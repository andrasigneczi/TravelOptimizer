// TODO: 
//     : QSettings usage
//     : egy bekapcsolható funkció, ami klikkelésre az adott pozíciótól +- irányba fel-le automatikusan kigenerálja a kisképeket
//     : a trainingdatába.

#include "screencopy.h"
#include <QPainter>
#include <QMouseEvent>
#ifdef __LINUX__
#include <unistd.h>
#endif
#include <fmincg.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QtGui/QImage>
//#include <png2arma.h>
#include <QScreen>
#include <QApplication>
#include <QtCore/QSettings>
#include "logistic_regression.h"
#include "logistic_regression_v2.h"
#ifdef __LINUX__
#include "support_vector_machine.h"
#endif

const int small_image_width = 24;
const std::string training_sets_folder = "./training_sets/";
int copy_box_size = 80;
const int small_tile_size = 22;
double minimize_rate = (double)small_image_width/(double)copy_box_size;
const std::string training_set_prefix = "TH_plus_BG_small_tiles";
double training_set_y = 0.;
double lambda = 0.1;
int iteration = 1000;
int scanStepSize = 1;
arma::mat thetaSizes{(double)small_image_width*small_image_width, 10000, 2};

ScreenCopy::ScreenCopy(QWidget *parent) : QWidget(parent)
{
    move(66,93);
    resize(1544,875);
    setMouseTracking(true);
    mouseX = 0;
    mouseY = 0;
    mousePressed = false;
    mSelectionMode = false;
    mousePressedX = 0;
    mousePressedY = 0;
    mCanvasSize = QRect(0,0,0,0);
    mTrainingset.load(training_sets_folder + training_set_prefix + "_trainingset.bin");
    mResultset.load(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
    std::cout << "Training set size: " << mTrainingset.n_rows << " rows\n" << std::flush;
}

void ScreenCopy::capture() {
    QScreen* screen = qApp->primaryScreen();
    //QRect g = screen->geometry();
    if( mCanvasSize == QRect(0,0,0,0)) {
        //mScreenshot = screen->grabWindow(0,g.x(),g.y(),g.width(),g.height());
        mScreenshot = screen->grabWindow(0,66,93,1544,855);
    } else {
        mScreenshot = screen->grabWindow(0,mCanvasSize.x(),mCanvasSize.y(),mCanvasSize.width(),mCanvasSize.height());
    }
    mGrayMiniCopy = mScreenshot.toImage().scaledToWidth(mScreenshot.width()*minimize_rate,Qt::SmoothTransformation)
                    .convertToFormat(QImage::Format_RGB32, Qt::MonoOnly);
    mGrayMiniCopy.save("minicopy.png");
    mScreenshot.save("screenshot.png");
    prepareSmallTilesView();
    updateTrainingSetStat();
}

void ScreenCopy::paintEvent(QPaintEvent* pe) {

    QPainter p(this);
    //p.drawPixmap(0,0,mScreenshot);
    p.drawImage(0,0,mSmallTilesView);
    //p.setCompositionMode(QPainter::CompositionMode_SourceOver);
    p.fillRect(0,0,1500,100, QBrush(QColor("#444444")));
    p.setFont(QFont("times",18));
    p.setPen(QPen(QColor("#ff0000")));
    p.drawText(QRect(0,0,500,30), Qt::AlignLeft, (std::to_string(mouseX) + " " + std::to_string(mouseY)).c_str());

    int textpos = 0;
    for( auto it = mTrainingSetStat.begin(); it != mTrainingSetStat.end(); ++it ){
        if( it->first == training_set_y ){
            p.setFont(QFont("times",18,QFont::Bold));
            p.setPen(QPen(QColor("#ffff00")));
        } else {
            p.setFont(QFont("times",18, QFont::Normal));
            p.setPen(QPen(QColor("#ff0000")));
        }
        p.drawText(QRect(textpos,30,500,100), Qt::AlignLeft, y2String(it->first) +
                   "=>" + QString::number( it->second ));
        textpos += 250;
    }

    if( mTrainingSetStat.find(training_set_y) == mTrainingSetStat.end()){
        p.setFont(QFont("times",18,QFont::Bold));
        p.setPen(QPen(QColor("#ffff00")));
        p.drawText(QRect(textpos,30,500,100), Qt::AlignLeft, y2String( training_set_y ) +
                   "=>0");
        textpos += 250;
    }

    p.setPen(QPen(QColor("#ffffff"),1,Qt::SolidLine));
    for( size_t i = 0; i < mPredictions.size(); ++i ){
        if( mPredictions[i].y == training_set_y ){
            p.drawRect(mPredictions[i].rect);
            p.drawText(mPredictions[i].rect, Qt::AlignLeft, y2String( mPredictions[i].y ));
        }
    }

    if( !mSelectionMode ) {
        p.setPen(QPen(Qt::GlobalColor::white,2,Qt::DotLine));
        //p.drawRect(mouseX, mouseY, copy_box_size, copy_box_size);
        for( auto it = mSmallTiles.begin(); it != mSmallTiles.end(); ++it ) {
            if( it->contains( mouseX, mouseY )) {
                p.drawRect(it->x() - 1, it->y() - 1, it->width() + 2, it->height() + 2);
            }
        }
    } else {
        p.setPen(QPen(QColor("#ffff00"),2,Qt::DotLine));
        QRect r;
        if( selectionX > mouseX ) {
            r.setLeft( mouseX );
            r.setWidth( selectionX - mouseX );
        } else {
            r.setLeft( selectionX );
            r.setWidth( -selectionX + mouseX );
        }

        if( selectionY > mouseY ) {
            r.setTop( mouseY );
            r.setHeight( selectionY - mouseY );
        } else {
            r.setTop( selectionY );
            r.setHeight( -selectionY + mouseY );
        }

        p.drawRect(r);
    }
    QWidget::paintEvent(pe);
}

void ScreenCopy::mouseMoveEvent(QMouseEvent*me) {
    mouseX = me->x();
    mouseY = me->y();
    // globalX, globalY
    repaint();
    QWidget::mouseMoveEvent(me);
}

void ScreenCopy::mousePressEvent(QMouseEvent*me) {
    mousePressed = true;
    mousePressedX = me->x();
    mousePressedY = me->y();
    if( me->modifiers() == Qt::ShiftModifier){
        mSelectionMode = true;
        selectionX = mousePressedX;
        selectionY = mousePressedY;
    } else if( me->modifiers() == Qt::ControlModifier){
        deleteSelectedRect();
    } else {
        if( mSelectionMode ) {
            mSelectionMode = false;

            QRect r;
            if( selectionX > mouseX ) {
                r.setLeft( mouseX );
                r.setWidth( selectionX - mouseX );
            } else {
                r.setLeft( selectionX );
                r.setWidth( -selectionX + mouseX );
            }

            if( selectionY > mouseY ) {
                r.setTop( mouseY );
                r.setHeight( selectionY - mouseY );
            } else {
                r.setTop( selectionY );
                r.setHeight( -selectionY + mouseY );
            }

            for(auto it = mPredictions.begin(); it != mPredictions.end();){
                if( (*it).y == training_set_y && r.contains((*it).rect) ){
                    std::cout << "erase\n";
                    mPredictions.erase(it);
                } else {
                    ++it;
                }
            }
        } else {
            saveSelectedRect();
        }
    }
    repaint();
    QWidget::mousePressEvent(me);
    //sleep(1);

    // add rect connect to training set with the label
    // rerun the training

    //close();
}

void ScreenCopy::mouseReleaseEvent(QMouseEvent*me) {
    mousePressed = false;
    QWidget::mouseReleaseEvent(me);
}

void ScreenCopy::keyPressEvent(QKeyEvent*ke) {
    if( ke->key() == Qt::Key_Escape) {
        ke->accept();
        close();
        return;
    }
    else if( ke->key() >= Qt::Key_0 && ke->key() <= Qt::Key_9) {
        ke->accept();
        training_set_y = ke->key() - Qt::Key_0;
        if( ke->modifiers() == Qt::ControlModifier)
            training_set_y += 10;
        std::cout << "y=" << training_set_y << "\n" << std::flush;
        repaint();
        return;
    }
    else if( ke->key() == Qt::Key_Space) {
        ke->accept();
        mCanvasSize = geometry();
        std::cout << "Canvas size: " << mCanvasSize.x() << ";" << mCanvasSize.y() << ";" << mCanvasSize.width() << ";" << mCanvasSize.height()
                  << "\n" << std::flush;
        return;
    }
    else if( ke->key() == Qt::Key_Plus) {
        ++copy_box_size;
        minimize_rate = (double)small_image_width/(double)copy_box_size;
        std::cout << "New copy_box_size: " << copy_box_size << std::endl << std::flush;
        mGrayMiniCopy = mScreenshot.toImage().scaledToWidth(mScreenshot.width()*minimize_rate,Qt::SmoothTransformation)
                        .convertToFormat(QImage::Format_RGB32, Qt::MonoOnly);
        repaint();
        return;
    }
    else if( ke->key() == Qt::Key_Minus) {
        --copy_box_size;
        minimize_rate = (double)small_image_width/(double)copy_box_size;
        std::cout << "New copy_box_size: " << copy_box_size << std::endl << std::flush;
        mGrayMiniCopy = mScreenshot.toImage().scaledToWidth(mScreenshot.width()*minimize_rate,Qt::SmoothTransformation)
                        .convertToFormat(QImage::Format_RGB32, Qt::MonoOnly);
        repaint();
        return;
    }
    QWidget::keyPressEvent(ke);
}

void ScreenCopy::trainNeuralNetwork() {
    if( mTrainingset.n_cols == 0 )
        return;

    srand (time(NULL));

    NeuralNetwork nn(thetaSizes, mTrainingset, mResultset, lambda, mThYMapper);

    //std::cout << "dbg1\n";
    arma::mat initial_nn_params;
    srand (time(NULL));
    for( size_t i = 0; i <= thetaSizes.n_cols-2; ++i ) {
        // Randomly initialize the weights to small values
        arma::mat initial_Theta = nn.randInitializeWeights(thetaSizes(0,i), thetaSizes(0,i+1));

        // Unroll parameters
        //initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];
        if( i == 0 )
            initial_nn_params = arma::vectorise( initial_Theta );
        else
            initial_nn_params = join_cols( initial_nn_params, arma::vectorise( initial_Theta ));
    }
    fmincgRetVal frv = fmincg(nn, initial_nn_params, iteration);

    //std::cout << "Cost: " << frv.mCost;

    // Obtain Theta1 and Theta2 back from nn_params
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    arma::mat pred = nn.predict(mTrainingset,thetas);
    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == mResultset))*100. << "\n";

    thetaSizes.save( training_sets_folder + training_set_prefix + "_trained_theta_sizes.bin" );
    frv.m_NNPparams.save( training_sets_folder + training_set_prefix + "_trained_thetas.bin" );
}

void ScreenCopy::trainLogisticRegression() {
    if( mTrainingsetNewCollection.n_cols == 0 )
        return;

    const char* prefix = "th11";
    double lambda = 1e-3;
    LogisticRegression lr(mTrainingsetNewCollection, mResultsetNewCollection, lambda, true, 3 );
    std::vector<arma::mat> thetaAndFS = lr.loadThetaAndFeatureScaling(prefix);
    //lr.train(thetaAndFS[0], 1,true);
    lr.stochasticGradientDescent(thetaAndFS[0],1e-6,5000);

    lr.saveThetaAndFeatureScaling(prefix);
    mTrainingsetNewCollection.clear();
    mResultsetNewCollection.clear();
}

void ScreenCopy::scanScreenshot() {
    arma::mat thetaSizes;
    arma::mat theta;
    arma::mat X, y;

    thetaSizes.load( training_sets_folder + training_set_prefix + "_trained_theta_sizes.bin" );
    theta.load( training_sets_folder + training_set_prefix + "_trained_thetas.bin" );
    NeuralNetwork nn(thetaSizes, X, y, lambda, mThYMapper);
    std::vector<arma::mat> thetas {nn.extractThetas(theta)};

    mPredictions.clear();
    int bgcounter = 0;
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height(); yp += scanStepSize) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width(); xp += scanStepSize) {

            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            arma::mat pred = nn.predict(img,thetas);
            if( pred(0,0) == 1.0 ){
                //std::cout << "position: " << xp*bigImageScale/width << ";" << yp*bigImageScale/width << " TH" << pred(0,0) << "\n";
                mPredictions.push_back({1,QRect(xp/minimize_rate,yp/minimize_rate,copy_box_size,copy_box_size)});
            } else if( pred(0,0) == 0.0 ){
                ++bgcounter;
            } else {
                std::cout << "What is this? " << pred(0,0) << "\n" << std::endl;
            }
        }
    }
    std::cout << "bgcounter: " << bgcounter << "\n" << std::flush;
    std::cout << "Found TH count: " << mPredictions.size() << "\n" << std::flush;
    /*
    if( mPredictions.size() < 20 ) {
        for_each(mPredictions.begin(),mPredictions.end(),
          [&](const QRect& r) {std::cout << r.x() << ";" << r.y() << ";" << r.width() << ";" << r.height() << "\n" << std::flush; });
    }
    */
}

void ScreenCopy::scanScreenshot_lr() {
    arma::mat X, y;

    enum TH {
        TH11,
        TH8,
        TH9,
        TH7,
        TH10
    };

    std::vector<LogisticRegression> lr(5);
    //std::vector<double> thresholds{0.99999, 0.99, 0.95, 0.5, 0.95};
    std::vector<double> thresholds{0.999995, 0.99, 0.95, 0.5, 0.95};
    std::vector<double> mapping{1., 2., 3., 4., 5.};

    lr[TH11].setFeatureMappingDegree(3);
    lr[TH11].loadThetaAndFeatureScaling("lrv2_th11_minibatch");

    lr[TH8].setFeatureMappingDegree(3);
    lr[TH8].loadThetaAndFeatureScaling("th8");

    lr[TH9].setFeatureMappingDegree(3);
    lr[TH9].loadThetaAndFeatureScaling("th9");

    lr[TH7].setFeatureMappingDegree(3);
    lr[TH7].loadThetaAndFeatureScaling("th7");

    lr[TH10].setFeatureMappingDegree(3);
    lr[TH10].loadThetaAndFeatureScaling("th10");

    mPredictions.clear();
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    bool stop = false;
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height() && !stop; yp += scanStepSize) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width() && !stop; xp += scanStepSize) {

            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            for( int i = TH11; i <= TH11; ++i ) {
                arma::mat pred = lr[i].predict(img,thresholds[i]);
                if( pred(0,0) == 1. ) {
                    mPredictions.push_back({mapping[i],QRect(xp/minimize_rate,yp/minimize_rate,copy_box_size,copy_box_size)});
                    //stop = true;
                    std::cout << "Found: " << y2String(mapping[i]).toLocal8Bit().data() << std::endl;
                    break;
                }
            }
        }
    }
    //std::cout << "Found TH count: " << mPredictions.size() << "\n" << std::flush;
    /*
    if( mPredictions.size() < 20 ) {
        for_each(mPredictions.begin(),mPredictions.end(),
          [&](const QRect& r) {std::cout << r.x() << ";" << r.y() << ";" << r.width() << ";" << r.height() << "\n" << std::flush; });
    }
    */
}

void ScreenCopy::scanScreenshot_lr_onevsall() {
    arma::mat X, y;
    const char* prefix = "lrv2_minibatch_onevsall";
    LogisticRegressionV2 lr;
    lr.loadCurrentStatus(prefix);
    mPredictions.clear();
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    bool stop = false;
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height() && !stop; yp += scanStepSize) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width() && !stop; xp += scanStepSize) {

            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            arma::mat pred = lr.predictOneVsAll(img);
            if( pred(0,0) > 0. /* && pred(0,1) >= 0.5*/ ) {
                mPredictions.push_back({pred(0,0),QRect(xp/minimize_rate,yp/minimize_rate,copy_box_size,copy_box_size)});
                //stop = true;
                //break;
            }
        }
    }
    std::cout << "Found TH count: " << mPredictions.size() << "\n" << std::flush;
}

#ifdef __LINUX__
void ScreenCopy::scanScreenshot_svm() {
    arma::mat X, y;

    struct svm_model *model = svm_load_model("svm_model.bin");
    support_vector_machine svm;
    svm.loadFeatureScaling("coc_");
    
    mPredictions.clear();
    int bgcounter = 0;
    arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
    for( int yp = 0; yp  + small_image_width < mGrayMiniCopy.height(); yp += scanStepSize) {
        for( int xp = 0; xp  + small_image_width < mGrayMiniCopy.width(); xp += scanStepSize) {

            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            arma::mat pred = svm.predict(img,model);
            if( pred(0,0) == 0.0 ){
                ++bgcounter;
            } else  if(pred(0,1) > 0.5){
                //std::cout << "position: " << xp*bigImageScale/width << ";" << yp*bigImageScale/width << " TH" << pred(0,0) << "\n";
                mPredictions.push_back({pred(0,0),QRect(xp/minimize_rate,yp/minimize_rate,copy_box_size,copy_box_size)});
                std::cout << pred(0,1) << "\n" << std::flush;
            }
        }
    }
    std::cout << "bgcounter: " << bgcounter << "\n" << std::flush;
    std::cout << "Found TH count: " << mPredictions.size() << "\n" << std::flush;
}
#endif

void ScreenCopy::deleteSelectedRect() {
    for( auto it = mSmallTiles.begin(); it != mSmallTiles.end(); ++it ) {
        if( it->contains( mousePressedX, mousePressedY )) {
            QPainter p(&mSmallTilesView);
            p.fillRect(it->x() - 1, it->y() - 1, it->width() + 2, it->height() + 2,QBrush(Qt::GlobalColor::black));
            mSmallTiles.erase(it);
            break;
        }
    }
}

void ScreenCopy::saveSelectedRect() {
    for( auto it = mSmallTiles.begin(); it != mSmallTiles.end(); ++it ) {
        if( it->contains( mousePressedX, mousePressedY )) {
            //p.drawRect(it->x() - 1, it->y() - 1, it->width() + 2, it->height() + 2);
            arma::mat img = arma::zeros( 1, small_tile_size * small_tile_size );
            for( int i = 0; i < small_tile_size; ++i ) {
                for( int j = 0; j < small_tile_size; ++j ) {
                    QRgb rgb = mSmallTilesView.pixel( it->x() + j, it->y() + i );
                    img(0, i * small_tile_size + j ) = rgb;
                }
            }
            if( mTrainingsetNewCollection.n_cols == 0 )
                mTrainingsetNewCollection = img;
            else
                mTrainingsetNewCollection.insert_rows(mTrainingsetNewCollection.n_rows, img);
            mResultsetNewCollection.insert_rows(mResultsetNewCollection.n_rows, arma::mat{training_set_y}); // TODO: TH level

            QPainter p(&mSmallTilesView);
            p.fillRect(it->x() - 1, it->y() - 1, it->width() + 2, it->height() + 2,QBrush(Qt::GlobalColor::black));
            mSmallTiles.erase(it);
            break;
        }
    }
    std::cout << "Training set size: " << mTrainingset.n_rows + mTrainingsetNewCollection.n_rows << " rows\n" << std::flush;
    updateTrainingSetStat();
}

void ScreenCopy::saveSelectedRect_old() {

    int yp = mousePressedY *minimize_rate - scanStepSize;
    if( yp < 0 ) yp = 0;
    int xp = mousePressedX *minimize_rate - scanStepSize;
    if( xp < 0 ) xp = 0;

    for( int imgCountY = 0; imgCountY < 2* scanStepSize; ++imgCountY ) {
        for( int imgCountX = 0; imgCountX < 2* scanStepSize; ++imgCountX ) {
            arma::mat img = arma::zeros( 1, small_image_width*small_image_width );
            for( int i = 0; i < small_image_width; ++i ) {
                for( int j = 0; j < small_image_width; ++j ) {
                    QRgb rgb = mGrayMiniCopy.pixel( xp  + imgCountX + j, yp + imgCountY + i );
                    img(0, i * small_image_width + j ) = rgb;
                }
            }
            //mGrayMiniCopy.copy(mousePressedX *minimize_rate, mousePressedY *minimize_rate, small_image_width, small_image_width)
            //                  .save("selectedrect.png");
            if( mTrainingsetNewCollection.n_cols == 0 )
                mTrainingsetNewCollection = img;
            else
                mTrainingsetNewCollection.insert_rows(mTrainingsetNewCollection.n_rows, img);
            mResultsetNewCollection.insert_rows(mResultsetNewCollection.n_rows, arma::mat{training_set_y}); // TODO: TH level
        }
    }

    //mTrainingset.save(training_sets_folder + training_set_prefix + "_trainingset.bin");
    //mResultset.save(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
    std::cout << "Training set size: " << mTrainingset.n_rows + mTrainingsetNewCollection.n_rows << " rows\n" << std::flush;
    updateTrainingSetStat();
}

void ScreenCopy::saveTiles() {
    for( auto it = mSmallTiles.begin(); it != mSmallTiles.end(); ++it ) {
        arma::mat img = arma::zeros( 1, small_tile_size * small_tile_size );
        for( int i = 0; i < small_tile_size; ++i ) {
            for( int j = 0; j < small_tile_size; ++j ) {
                QRgb rgb = mSmallTilesView.pixel( it->x() + j, it->y() + i );
                img(0, i * small_tile_size + j ) = rgb;
            }
        }
        if( mTrainingsetNewCollection.n_cols == 0 )
            mTrainingsetNewCollection = img;
        else
            mTrainingsetNewCollection.insert_rows(mTrainingsetNewCollection.n_rows, img);
        mResultsetNewCollection.insert_rows(mResultsetNewCollection.n_rows, arma::mat{training_set_y});
    }
    mSmallTiles.clear();
    std::cout << "Training set size: " << mTrainingset.n_rows + mTrainingsetNewCollection.n_rows << " rows\n" << std::flush;
    updateTrainingSetStat();
}

void ScreenCopy::extractTrainingSet(double yFilter) {
    //std::cout <<  mTrainingset.n_rows << ";" << mTrainingset.n_cols << "\n" << std::flush;
    //QImage img(small_image_width,small_image_width, QImage::Format_RGB32);
    // 100 x 100 training picture will be stored on one big image
    const int imgPerRow = 100;
    int imgPosX = 0, imgPosY = 0;
    QImage img(small_image_width*imgPerRow, small_image_width*imgPerRow, QImage::Format_RGB32);
    img.fill(Qt::GlobalColor::white);
    char name[100];
    size_t nextImgToSave = 0;

    for( size_t i = 0; i < mTrainingset.n_rows; ++i ) {
        if( yFilter != -1 && mResultset(i,0) != yFilter )
            continue;
            
        imgPosX = (nextImgToSave%imgPerRow)*small_image_width;
        imgPosY = ((nextImgToSave/imgPerRow)%imgPerRow)*small_image_width;
        std::cout << "imgPosX: " << imgPosX << "  imgPosY: " << imgPosY << "\n";
        for( size_t j = 0; j < mTrainingset.n_cols; ++j ) {
            img.setPixel(imgPosX + (j%small_image_width), imgPosY + (j/small_image_width), mTrainingset(i, j));
        }
        
        if( imgPosY == small_image_width*(imgPerRow-1) && imgPosX == small_image_width*(imgPerRow-1)) {
            sprintf(name, "tmp/stamps_%d_%04lu.png", (int)yFilter, (unsigned long)i);
            img.save(name);
            //img.fill(Qt::GlobalColor::white);
            img = QImage(small_image_width*imgPerRow, small_image_width*imgPerRow, QImage::Format_RGB32);
            img.fill(Qt::GlobalColor::white);
        }
        ++nextImgToSave;
    }

    if( imgPosY != small_image_width*(imgPerRow-1) || imgPosX != small_image_width*(imgPerRow-1)) {
        sprintf(name, "tmp/stamps_%d_%04lu.png", (int)yFilter, (unsigned long)mTrainingset.n_rows);
        img.save(name);
    }
}

void ScreenCopy::updateTrainingSetStat(){
    mTrainingSetStat.clear();
    for( size_t i = 0; i < mResultset.n_rows; ++i ){
        auto it = mTrainingSetStat.find(mResultset(i,0));
        if( it != mTrainingSetStat.end()) {
            ++it->second;
        } else {
            mTrainingSetStat.emplace((int)mResultset(i,0),1);
        }
    }
    for( size_t i = 0; i < mResultsetNewCollection.n_rows; ++i ){
        auto it = mTrainingSetStat.find(mResultsetNewCollection(i,0));
        if( it != mTrainingSetStat.end()) {
            ++it->second;
        } else {
            mTrainingSetStat.emplace((int)mResultsetNewCollection(i,0),1);
        }
    }
    repaint();
}

void ScreenCopy::deleteTrainingSet() {
    mTrainingset.clear();
    mTrainingsetNewCollection.clear();
    mResultset.clear();
    mResultsetNewCollection.clear();
    //mTrainingset.save(training_sets_folder + training_set_prefix + "_trainingset.bin");
    //mResultset.save(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
    saveTrainingSet();
    std::cout << "Training set size: " << mTrainingset.n_rows << " rows\n" << std::flush;
    updateTrainingSetStat();
}

void ScreenCopy::saveTrainingSet() {
    mTrainingset.insert_rows(mTrainingset.n_rows, mTrainingsetNewCollection);
    mTrainingsetNewCollection.clear();
    mTrainingset.save(training_sets_folder + training_set_prefix + "_trainingset.bin");

    mResultset.insert_rows(mResultset.n_rows, mResultsetNewCollection);
    mResultsetNewCollection.clear();
    mResultset.save(training_sets_folder + training_set_prefix + "_trainingset_result.bin");
}

QString ScreenCopy::y2String(int y){
    switch(y){
    case 0:return "Background";
    case 1:return "Building";
    case 2:return "Troop";
    case 3:return "Button";
    default:return "????";
    }
    return "";
}

double ScreenCopy::getSelectedLabel() {
    return training_set_y;
}

void ScreenCopy::correctDataset() {
    /*
    size_t counter = 0;
    for( size_t i = mTrainingset.n_rows-1; i!= 0; --i ) {
        if( mResultset(i,0) == 3.) {
            mResultset(i,0) = 2;
            ++counter;
            if( counter == 5 ) {
                break;
            }
        }
    }
    */
    extractTrainingSet(0.);
    extractTrainingSet(1.);
    extractTrainingSet(2.);
    extractTrainingSet(3.);
    extractTrainingSet(4.);
    extractTrainingSet(5.);
}

void ScreenCopy::savePredictionsAs0() {
    arma::mat img = arma::zeros(1,small_image_width*small_image_width);
    for(auto it = mPredictions.begin(); it != mPredictions.end(); ++it){
        for( int i = 0; i < small_image_width; ++i ) {
            for( int j = 0; j < small_image_width; ++j ) {
                if((*it).y != training_set_y )
                    continue;
                size_t xp = (*it).rect.left() * minimize_rate;
                size_t yp = (*it).rect.top() * minimize_rate;
                QRgb rgb = mGrayMiniCopy.pixel( xp + j, yp + i );
                img(0, i * small_image_width + j ) = rgb;
            }
        }
        if( mTrainingsetNewCollection.n_cols == 0 )
            mTrainingsetNewCollection = img;
        else
            mTrainingsetNewCollection.insert_rows(mTrainingsetNewCollection.n_rows, img);
        mResultsetNewCollection.insert_rows(mResultsetNewCollection.n_rows, arma::mat{0});
    }
    std::cout << "Training set size: " << mTrainingset.n_rows + mTrainingsetNewCollection.n_rows << " rows\n" << std::flush;
    updateTrainingSetStat();
}

void ScreenCopy::prepareSmallTilesView() {
    const int space_size = 3;
    const int tile_count_h = mScreenshot.width() / small_tile_size;
    const int tile_count_v = mScreenshot.height() / small_tile_size;
    const int img_width = (small_tile_size + space_size) * tile_count_h - space_size;
    const int img_height = (small_tile_size + space_size) * tile_count_v - space_size;

    mSmallTiles.clear();
    mSmallTilesView = QImage(img_width, img_height, QImage::Format_RGB32);
    mSmallTilesView.fill(Qt::GlobalColor::black);
    QPainter p(&mSmallTilesView);

    int pos_x = 0;
    int pos_y = 0;
    for( int i = 0; i < mScreenshot.width(); i += small_tile_size ) {
        for( int j = 0; j < mScreenshot.height(); j += small_tile_size ) {
            if( i == 0 ) pos_x = 0;
            if( j == 0 ) pos_y = 0;
            QImage tile = mScreenshot.copy( i, j, small_tile_size, small_tile_size ).toImage();
            p.drawImage(pos_x, pos_y, tile);
            mSmallTiles.push_back(QRect(pos_x,pos_y,small_tile_size,small_tile_size));
            pos_y += small_tile_size + space_size;
        }
        pos_x += small_tile_size + space_size;
    }
}