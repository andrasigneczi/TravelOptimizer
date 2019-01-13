#include "activation_layer.h"

arma::mat4D Sigmoid::forward(arma::mat4D Z) {
    mCache = 1.0/(1.0+arma::exp(-Z));
    return mCache;
}

arma::mat4D Sigmoid::backward(arma::mat4D dA) {
    return dA % mCache % (1. - mCache);
}

arma::mat Sigmoid::forward(arma::mat Z) {
    mCache2 = 1.0/(1.0+arma::exp(-Z));
    return mCache2;
}

arma::mat Sigmoid::backward(arma::mat dA) {
    return dA % mCache2 % (1. - mCache2);
}

void Sigmoid::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Sigmoid::loadState(std::ifstream& input) {
    UNUSED(input);
}

void Sigmoid::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    UNUSED(learning_rate);
    UNUSED(beta);
    UNUSED(beta1);
    UNUSED(beta2);
    UNUSED(epsilon);
}

arma::mat4D Relu::forward(arma::mat4D Z) {
    mCache = Z;
    //Z.elem( arma::find(Z < 0.0) ).zeros();
    arma::Elem(Z, arma::find(Z < 0.0)).zeros();
    return Z;
}

arma::mat4D Relu::backward(arma::mat4D dA) {
    //gZ.elem( arma::find(gZ > 0.0) ).ones();
    //gZ.elem( arma::find(gZ <= 0.0) ).zeros();
    arma::Elem(mCache, arma::find(mCache > 0.0)).ones();
    arma::Elem(mCache, arma::find(mCache <= 0.0)).zeros();
    return dA % mCache;
}

arma::mat Relu::forward(arma::mat Z) {
    mCache2 = Z;
    Z.elem( arma::find(Z < 0.0) ).zeros();
    return Z;
}

arma::mat Relu::backward(arma::mat dA) {
    mCache2.elem( arma::find(mCache2 > 0.0) ).ones();
    mCache2.elem( arma::find(mCache2 <= 0.0) ).zeros();
    return dA % mCache2;
}

void Relu::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Relu::loadState(std::ifstream& input) {
    UNUSED(input);
}

void Relu::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    UNUSED(learning_rate);
    UNUSED(beta);
    UNUSED(beta1);
    UNUSED(beta2);
    UNUSED(epsilon);
}

arma::mat4D Tanh::forward(arma::mat4D Z) {
    const arma::mat4D pz = arma::exp(Z);
    const arma::mat4D nz = arma::exp(-Z);
    mCache = (pz - nz)/(pz + nz);
    return mCache;
}

arma::mat4D Tanh::backward(arma::mat4D dA) {
    return dA % (1. - arma::pow(mCache,2));
}

arma::mat Tanh::forward(arma::mat Z) {
    const arma::mat pz = arma::exp(Z);
    const arma::mat nz = arma::exp(-Z);
    mCache2 = (pz - nz)/(pz + nz);
    return mCache2;
}

arma::mat Tanh::backward(arma::mat dA) {
    return dA % (1. - arma::pow(mCache2,2));
}

void Tanh::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Tanh::loadState(std::ifstream& input) {
    UNUSED(input);
}

void Tanh::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    UNUSED(learning_rate);
    UNUSED(beta);
    UNUSED(beta1);
    UNUSED(beta2);
    UNUSED(epsilon);
}

arma::mat4D LeakyRelu::forward(arma::mat4D Z) {
    //Z.elem( arma::find(Z <= 0.0) ) *= 0.01;
    mCache = Z;
    arma::Elem(Z, arma::find(Z <= 0.0)) *= 0.01;
    return Z;
}

arma::mat4D LeakyRelu::backward(arma::mat4D dA) {
    //gZ.elem( arma::find(gZ > 0.0) ).fill(1.);
    //gZ.elem( arma::find(gZ < 0.0) ).fill(0.01);
    arma::Elem(dA, arma::find(mCache > 0.0)).fill(1.0);
    arma::Elem(dA, arma::find(mCache < 0.0)).fill(0.01);
    return dA%mCache;
}

arma::mat LeakyRelu::forward(arma::mat Z) {
    mCache2 = Z;
    Z.elem( arma::find(Z <= 0.0) ) *= 0.01;
    return Z;
}

arma::mat LeakyRelu::backward(arma::mat dA) {
    mCache2.elem( arma::find(mCache2 > 0.0) ).fill(1.);
    mCache2.elem( arma::find(mCache2 < 0.0) ).fill(0.01);
    return dA % mCache2;
}

void LeakyRelu::saveState(std::ofstream& output) {
    UNUSED(output);
}

void LeakyRelu::loadState(std::ifstream& input) {
    UNUSED(input);
}

void LeakyRelu::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    UNUSED(learning_rate);
    UNUSED(beta);
    UNUSED(beta1);
    UNUSED(beta2);
    UNUSED(epsilon);
}

arma::mat Softmax::forward(arma::mat Z) {
    // V1, stable softmax
    // exps = np.exp(Z - np.max(Z))
    // A = exps / np.sum(exps, axis=1, keepdims=True)

    // V2
    // dummy = np.exp(X)
    // self.Y = dummy/np.sum(dummy, axis=1, keepdims=True)
    // return self.Y, 0

    std::cerr << "Softmax::" << __FUNCTION__ << ": size(Z): " << size(Z) << "\n";

    arma::mat exps = arma::exp(Z - Z.max());
    mCache = Util::div(exps,arma::sum(exps, 0));
    return mCache;
}

// Actually we don't need this function
arma::mat Softmax::backward(arma::mat gZ) {
    // V1, stable softmax
    // gZ[Y.argmax(axis=0),range(m)] -= 1

    // V2
    // self.delta_X =  (self.Y - output) / self.Y.shape[0]
    // return self.delta_X


    std::cerr << "Softmax::" << __FUNCTION__ << ": size(gZ): " << size(gZ) << "\n";
    std::cerr << "Softmax::" << __FUNCTION__ << ": size(mCache): " << size(mCache) << "\n";
    std::cerr << "Softmax::" << __FUNCTION__ << ": end\n";
    return (mCache - gZ)/(double)mCache.n_rows;
}

void Softmax::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Softmax::loadState(std::ifstream& input) {
    UNUSED(input);
}

void Softmax::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    UNUSED(learning_rate);
    UNUSED(beta);
    UNUSED(beta1);
    UNUSED(beta2);
    UNUSED(epsilon);
}
