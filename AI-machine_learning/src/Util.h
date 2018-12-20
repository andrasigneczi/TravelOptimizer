#ifndef __UTIL_H__
#define __UTIL_H__

#include <string>
#include "qcustomplot.h"
#include <armadillo>
#include <QtCore/QtGlobal>
#include <set>
#include <unordered_map>

#define UNUSED(x) (void)(x)

namespace Util {
    typedef std::unordered_map<std::string,arma::mat> UStringMatMap;

    Q_DECL_EXPORT std::string trim(const std::string& str);
    Q_DECL_EXPORT void plotMatrix( QCustomPlot* customPlot, const arma::mat& matrix );
    Q_DECL_EXPORT void removeDuplication(arma::mat& dataset);
    Q_DECL_EXPORT void prepareTrainingAndValidationSet(const arma::mat& X, const arma::mat& y, arma::mat& Xtraining, arma::mat& Ytraining, arma::mat& Xval, arma::mat& Yval,
                                                       std::set<double> ignored_labels = std::set<double>(), size_t itemLimitPerLabel = 0,
                                                       const double percentage = 0.7);
    Q_DECL_EXPORT arma::mat mapFeature( const arma::mat& X1, const arma::mat& X2, int degree );
    Q_DECL_EXPORT int getLabelCount( const arma::mat& y );
    Q_DECL_EXPORT arma::mat broadcast_plus( arma::mat x, arma::mat y );
    Q_DECL_EXPORT arma::mat broadcast_minus( arma::mat x, arma::mat y );
    Q_DECL_EXPORT arma::mat broadcast_div( arma::mat x, arma::mat y );
    Q_DECL_EXPORT arma::mat broadcast_mul( arma::mat x, arma::mat y );
    
    Q_DECL_EXPORT bool saveMat(std::ofstream& output, const arma::mat& m);
    Q_DECL_EXPORT bool saveMat(std::ofstream& output, const arma::umat& m);
    Q_DECL_EXPORT bool saveStringUMap(std::ofstream& output, const UStringMatMap& m);
    Q_DECL_EXPORT bool saveVectorStringUMap(std::ofstream& output, const std::vector<UStringMatMap>& v);
    Q_DECL_EXPORT bool loadVectorStringUMap(std::ifstream& intput, std::vector<UStringMatMap>& v);
    Q_DECL_EXPORT arma::mat loadMat(std::ifstream& input);
    Q_DECL_EXPORT arma::umat loadUMat(std::ifstream& input);
    Q_DECL_EXPORT bool loadStringUMap(std::ifstream& output, UStringMatMap& m);

} // namespace Util

namespace arma {
#if ARMA_VERSION_MAJOR == 6
    arma::mat index_max(const arma::mat& A,int dim );
#endif // ARMA_VERSION_MAJOR == 6
} // namespace arma

#endif // __UTIL_H__
