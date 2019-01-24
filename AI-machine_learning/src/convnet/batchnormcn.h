#ifndef __BATCHNORM_H__
#define __BATCHNORM_H__

#include "forward_backward_if.h"
#include "layerobserver.h"
#include <stack>

class BatchNormCN : public ForwardBackwardIF, public LayerSubject {
    friend class BatchNormTest;
public:
    // for conv layer
    BatchNormCN(int f_H, int f_W, int n_C_prev, int n_C);
    
    // for fully connected layer
    BatchNormCN(int weightRows);
    
    arma::mat4D forward(arma::mat4D A_prev) override;
    arma::mat4D backward(arma::mat4D dZ) override;

    arma::mat forward(arma::mat Z) override;
    arma::mat backward(arma::mat dX) override;
    
    bool is4D() { return false; }
    void updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon, int batch_size) override;

    void accept(Visitor& visitor) override { visitor.visit(this); }

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

    void initializeByBatch(size_t batchIndex);
    
    void setTrainOff() { mBatchIndex = -1; }
    bool isTrainOff() const { return mBatchIndex == -1; }
    
private:

    enum Param {
        GAMMA,
        BETA,
        RUNNING_MEAN,
        RUNNING_VAR,
        DGAMMA,
        DBETA
    };
    arma::mat avgBatchParam(BatchNormCN::Param param);
    
    struct Item {
        arma::mat mGamma;
        arma::mat mBeta;
        arma::mat mRunningMean;
        arma::mat mRunningVar;
        arma::mat mdGamma;
        arma::mat mdBeta;
    };
    std::vector<Item> mBatches;
    int mWeightRows;
    int mBatchIndex;
    std::stack<arma::mat> mCache;
};

class BatchNormVisitor : public Visitor {
public:
    BatchNormVisitor(int batchIndex) : mBatchIndex(batchIndex){}
    void visit(BatchNormCN* b) {
        b->initializeByBatch(mBatchIndex);
    }

private:
    int mBatchIndex;
};

#endif // __BATCHNORM_H__