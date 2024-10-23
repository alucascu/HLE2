#include <Rcpp.h>
using namespace Rcpp;

//' Calculate the Hodges-Lehmann estimate of shift
//' 
//' @description
//' 'outer_HLE2()' returns a numeric estimate for the shift parameter of
//'    two datasets. To accomplish this, it employs an optimized c++ function
//'    and then finds the median of the indivdual differences. 
//' 
//' @details 
//' Hodges-Lehmann estimate of shift.
//' 
//' For two datasets: x and y, the Hodges-Lehmann Shift Estimate is defined as:
//' median(y_i-x_j) for all i and j within the set.
//' 
//' @param x A numeric vector. Should contain the dataset
//'   you want to compare.
//' @param y A numeric vector. Should contain the data from the
//'  sample you wish to find the shift for
//' @returns A numeric. The estimated shift parameter from
//'   dataset x, to dataset y
//' @seealso [outer_HLE2(x, y)] an implementation of HLE2 with the R base 'outer Function.
//' 
//' @references 
//' NMU DATA495 "Computing with Data" lectures and slides.
//' @export


// [[Rcpp::export]]
double cpp_HLE2(NumericVector x, NumericVector y){
  std::vector<double> estimatorVec;
  for(auto i = x.begin(); i < x.end(); ++i){
    for(auto j = y.begin(); j < y.end(); ++j){
      double estimate = *j - *i;  
      estimatorVec.push_back(estimate);
    }
  } 
  int medLocation = (estimatorVec.size() - 1) / 2;
  std::nth_element(estimatorVec.begin(), estimatorVec.begin() + medLocation, estimatorVec.end());
  return estimatorVec.at((estimatorVec.size() / 2));
}
