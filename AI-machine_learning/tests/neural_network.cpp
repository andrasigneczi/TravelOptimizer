#include <armadillo>
#include "neural_network.h"
#include <neural_network.h>
#include <fmincg.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QtGui/QImage>

namespace NeuralNetwork_ns {
    
void test1();
void test2();
void test3();
void test4();
void coc_prediction_test();

void runTests() {
    //test1(); // neural network prediction
    //test2(); // neural network complex training
    //test3(); // neural network simple training
    // test4(); // coc training test
    coc_prediction_test();
}


class TestYMappper : public CostAndGradient::YMappperIF {
public:
    arma::mat fromYtoYY(double y, size_t num_labels ) override {
        arma::mat yy = arma::zeros(1,num_labels);
        if( y == 0 ) {
            yy(0,9) = 1;
        } else {
            yy(0,y-1) = 1;
        }
        return yy;
    }
    
    double fromYYtoY( size_t index ) override {
        return index + 1; // the Octave used 1 based indexes
    }
};

void test1() {
    // neural network prediction
    arma::mat X, y, Theta1, Theta2;
    
    Theta1.load("ex3weights_Theta1.bin");
    Theta2.load("ex3weights_Theta2.bin");
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");
    
    TestYMappper yMapper;
    const arma::mat thetaSizes;
    NeuralNetwork nn(thetaSizes, X, y, 0, yMapper);
    arma::mat pred = nn.predict(X, {Theta1, Theta2});
    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
}

void test2() {
    // neural network training
    
    arma::mat X, y, Theta1, Theta2;
    
    Theta1.load("ex3weights_Theta1.bin");
    Theta2.load("ex3weights_Theta2.bin");
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");

    //nn_params = [Theta1(:) ; Theta2(:)];
    arma::mat nn_params = join_cols( arma::vectorise( Theta1 ), arma::vectorise( Theta2 ));
    double lambda = 0;
    
    std::cout << "Feedforward Using Neural Network ...\n";
    arma::mat thetaSizes;
    int input_layer_size  = 400;
    int hidden_layer_size = 25;
    int num_labels        = 10;
    
    thetaSizes << input_layer_size << hidden_layer_size << num_labels; // input, hidden, output
    TestYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);
    //J = nnCostFunction(nn_params, input_layer_size, hidden_layer_size, ...
    //                   num_labels, X, y, lambda);
    CostAndGradient::RetVal& rv = nn.calc(nn_params);
    
    std::cout << "Cost at parameters (loaded from ex4weights): " << rv.cost << " (this value should be about 0.287629)\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
    
    
    std::cout << "\nChecking Cost Function (w/ Regularization) ... \n";
    
    lambda = 1;
    nn.setLambda(lambda);
    rv = nn.calc(nn_params);

    std::cout << "Cost at parameters (loaded from ex4weights): " << rv.cost << " (this value should be about 0.383770)\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
    
    
    std::cout << "\nEvaluating sigmoid gradient...\n";
    
    arma::mat testV = {-1, -0.5, 0, 0.5, 1 };
    arma::mat g = nn.sigmoidGradient( testV );
    std::cout << "Sigmoid gradient evaluated at [-1 -0.5 0 0.5 1]:\n";
    std::cout << g << "\n";
    
    
    // Randomly initialize the weights to small values
    arma::mat initial_Theta1 = nn.randInitializeWeights(input_layer_size, hidden_layer_size);
    arma::mat initial_Theta2 = nn.randInitializeWeights(hidden_layer_size, num_labels);
    
    // Unroll parameters
    //initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];
    arma::mat initial_nn_params = join_cols( arma::vectorise( initial_Theta1 ), arma::vectorise( initial_Theta2 ));

    std::cout << "\nChecking Backpropagation... \n";
    //  Check gradients by running checkNNGradients
    nn.checkNNGradients();
    std::cout << "Press enter to continue\n";
    std::cin.get();
    
    
    std::cout << "\nChecking Backpropagation (w/ Regularization) ... \n";
    
    //  Check gradients by running checkNNGradients
    lambda = 3;
    nn.setLambda(lambda);
    nn.checkNNGradients(lambda);
    
    // Also output the costFunction debugging values
    //debug_J  = nnCostFunction(nn_params, input_layer_size, ...
    //                          hidden_layer_size, num_labels, X, y, lambda);

    //J = nnCostFunction(nn_params, input_layer_size, hidden_layer_size, ...
    //                   num_labels, X, y, lambda);
    rv = nn.calc(nn_params);
    
    std::cout << "\nCost at (fixed) debugging parameters (w/ lambda = " << lambda << "): " << rv.cost <<
             "\n(for lambda = 3, this value should be about 0.576051)\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
    


    std::cout << "\nTraining Neural Network... \n";
    
    //  After you have completed the assignment, change the MaxIter to a larger
    //  value to see how more training helps.
    //options = optimset('MaxIter', 50);
    
    //  You should also try different values of lambda
    lambda = 1;
    nn.setLambda(lambda);
    // Create "short hand" for the cost function to be minimized
    //costFunction = @(p) nnCostFunction(p, ...
    //                                   input_layer_size, ...
    //                                   hidden_layer_size, ...
    //                                   num_labels, X, y, lambda);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    // Now, costFunction is a function that takes in only one argument (the
    // neural network parameters)
    //[nn_params, cost] = fmincg(costFunction, initial_nn_params, options);
    fmincgRetVal frv = fmincg(nn, initial_nn_params, 200);
    
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;
    
    // Obtain Theta1 and Theta2 back from nn_params
    /*
    Theta1 = arma::reshape(frv.m_NNPparams.rows(0,hidden_layer_size * (input_layer_size + 1)-1),
                     hidden_layer_size, (input_layer_size + 1));
    
    Theta2 = arma::reshape(frv.m_NNPparams.rows((hidden_layer_size * (input_layer_size + 1)),frv.m_NNPparams.n_rows-1),
                     num_labels, (hidden_layer_size + 1));
    */
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    arma::mat pred = nn.predict(X,thetas);
    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
}

void test3() {
    arma::mat X, y;
    
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");

    arma::mat thetaSizes;
    int input_layer_size  = 400;
    int hidden_layer_size1 = 20;
    int num_labels         = 10;
    double lambda = 1;
    int iteration = 50;
    
    thetaSizes << input_layer_size << hidden_layer_size1 << num_labels; // input, hidden, output
    TestYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);

    // Randomly initialize the weights to small values
    arma::mat initial_Theta1 = nn.randInitializeWeights(input_layer_size, hidden_layer_size1);
    arma::mat initial_Theta2 = nn.randInitializeWeights(hidden_layer_size1, num_labels);
    
    // Unroll parameters
    //initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];
    arma::mat initial_nn_params = join_cols( arma::vectorise( initial_Theta1 ), arma::vectorise( initial_Theta2 ));

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    fmincgRetVal frv = fmincg(nn, initial_nn_params, iteration);

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;

    // Obtain Theta1 and Theta2 back from nn_params
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    arma::mat pred = nn.predict(X,thetas);

    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();

}

class COCYMappper : public CostAndGradient::YMappperIF {
public:
    arma::mat fromYtoYY(double y, size_t num_labels ) override {
        arma::mat yy = arma::zeros(1,num_labels);
        yy(0,y-1) = 1;
        return yy;
    }
    
    double fromYYtoY( size_t index ) override {
        return index + 1; // the smallest TH number is 2
    }
};

double coc( const arma::mat& X, const arma::mat& y, const arma::mat& Xt, const arma::mat& yt, double layerSize, double lambda );
void test4() {
    arma::mat X, y, Xt, yt;
    
    X.load("coc_trainingset.bin");
    y.load("coc_trainingset_result.bin");
    Xt.load("coc_testset.bin");
    yt.load("coc_testset_result.bin");

    // multiply the training set: totally useless!!!!
  /*  
    for( int i = 0; i < 3; ++i ) {
        X = join_cols( X, X );
        y = join_cols( y, y );
    }
    std::cout << "New size: " << size(X) << size(y);
*/
    coc( X, y, Xt, yt, 8000, 3.0e-2 );
    if( 0 ) {
     double lastAccuracy = 0;
        int accuracyIndex = 0;
        for( int i = 700; i < 1300; i += 100 ) {
            std::cout << "layer size: " << i << "\n";
            double accuracy = coc( X, y, Xt, yt, (double)i, 3.0e-2 );  
            if( accuracy > lastAccuracy ) {
                lastAccuracy = accuracy;
                accuracyIndex = i;
            }
        }
        std::cout << "Best accuracy: " << lastAccuracy << "; layer size: " << accuracyIndex << "\n";
    }
    
    
}

double coc( const arma::mat& X, const arma::mat& y, const arma::mat& Xt, const arma::mat& yt, double layerSize, double lambda ) {
    
    // input, hidden1, ..., hddenN, output
    arma::mat thetaSizes{(double)X.n_cols, layerSize,11 };
    //double lambda = 1e-1;
    int iteration = 100;
    
    //thetaSizes << input_layer_size << hidden_layer_size1 << num_labels; // input, hidden, output
    COCYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);

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
    //std::cout << "dbg2\n";
    
/*    
    std::cout << "\nChecking Backpropagation (w/ Regularization) ... \n";
    
    //  Check gradients by running checkNNGradients
    nn.setLambda(3);
    nn.checkNNGradients(3);
    std::cout << "Press enter to continue\n";
    std::cin.get();
    nn.setLambda( lambda );
*/    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    //std::cout << "dbg3\n";

    fmincgRetVal frv = fmincg(nn, initial_nn_params, iteration);

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;

    thetaSizes.save( "coc_trained_theta_sizes.bin" );
    frv.m_NNPparams.save( "coc_trained_thetas.bin" );
    
    // Obtain Theta1 and Theta2 back from nn_params
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    
    arma::mat pred = nn.predict(X,thetas);
    arma::mat pred2 = nn.predict(Xt,thetas);

    double accuracy = arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100;
    double accuracy2 = arma::mean(arma::conv_to<arma::colvec>::from(pred2 == yt))*100;
    //std::cout << "Training y:\n";
    //std::cout << join_rows(y, pred) << std::endl;
    /*
    for( size_t i = 0; i < y.n_rows; ++i )
        if( y(i,0) != pred(i,0))
            std::cout << y(i,0) << " " << pred(i,0) << std::endl;
    */        
    //std::cout << "Test y:\n";
    //std::cout << join_rows(yt, pred2) << std::endl;
    /*
    for( size_t i = 0; i < yt.n_rows; ++i )
        if( yt(i,0) != pred2(i,0))
            std::cout << i + 1 << ". " << yt(i,0) << " " << pred2(i,0) << std::endl;
    */
    std::cout << "Training Set Accuracy: " << accuracy << "%\n";
    std::cout << "Test Set Accuracy: " << accuracy2 << "%\n";
    std::cout << "thetaSizes: " << thetaSizes << "\nlambda: " << lambda << "\n";
    
    
    NeuralNetwork nn2(thetaSizes, Xt, yt, lambda, yMapper);
    CostAndGradient::RetVal& rv = nn.calc(frv.m_NNPparams);
    
    std::cout << "Cost with training data: " << frv.mCost << "\niteration: " << frv.mI <<"\n";
    std::cout << "\nCost with test data: " << rv.cost <<"\n";

    return accuracy;
}

void coc_prediction_test() {
    arma::mat thetaSizes;
    arma::mat theta;
    arma::mat X, y;
    double lambda = 0;
    
    std::cout << "dbg1\n";
    
    thetaSizes.load( "./theta_n8000_l03/coc_trained_theta_sizes.bin" );
    theta.load( "./theta_n8000_l03/coc_trained_thetas.bin" );
    
    std::cout << "dbg2\n";
    
    COCYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);
    
    std::cout << "dbg3\n";
    
    std::vector<arma::mat> thetas {nn.extractThetas(theta)};
    
    std::cout << "dbg4\n";
    
    QImage testmap;
    
    std::cout << "dbg5\n";
    
    if( testmap.load( "../COC/Processed/BlueStacks_ScreenShot1.jpg")) {
        std::cout << "BlueStacks_ScreenShot1.jpg size: " << testmap.width() << " x " << testmap.height() << "\n";
    }
    
    int width = 100;
    for( size_t yp = 0; yp  + width < testmap.height(); yp += 4) {
        std::cout << "yp: " << yp << "\n";
        for( size_t xp = 0; xp  + width < testmap.width(); xp += 4) {
            QImage tmp = testmap.copy( xp, yp, width, width ).scaled(24,24);
            arma::mat retVal = arma::zeros( 1, 24*24 );
            for( size_t i = 0; i < 24; ++i ) {
                for( size_t j = 0; j < 24; ++j ) {
                    QRgb rgb = tmp.pixel( j, i );
                    retVal(0, i * 24 + j ) = 0.2126*qRed(rgb)+0.7152*qGreen(rgb)+0.0722*qBlue(rgb);
                }
            }
            std::cout << nn.predict(retVal,thetas);
        }
    }
    std::cout << "dbg5\n";
    
    //std::cout << "dbg6\n";
}

} // NeuralNetwork_ns