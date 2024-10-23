#' Calculate the Hodges-Lehmann estimate of shift
#' 
#' @description
#' 'outer_HLE2()' returns a numeric estimate for the shift parameter of
#'    two datasets. To accomplish this, it employs the R-base "outer" function
#'    and then finds the median of the indivdual differences. 
#' 
#' @details 
#' Hodges-Lehmann estimate of shift.
#' 
#' For two datasets: x and y, the Hodges-Lehmann Shift Estimate is defined as:
#' median(y_i-x_j) for all i and j within the set.
#' 
#' @param x A numeric vector. Should contain the dataset
#'   you want to compare.
#' @param y A numeric vector. Should contain the data from the
#'  sample you wish to find the shift for
#' @returns A numeric. The estimated shift parameter from
#'   dataset x, to dataset y
#' @seealso [cpp_HLE2(x, y)] a faster, c++ implementation of this calaculation.
#' @examples
#' # Generating random datasets
#' loc_estimate_1 <- rnorm(100)
#' loc_estimate_2 <- rnorm(100) + 5 
#' # The calculated shift for this data
#' #should be ~5
#' 
#' outer_HLE2(loc_estimate_1, loc_estimate_2)
#' 
#' @references 
#' NMU DATA495 "Computing with Data" lectures and slides.
#' @importFrom stats median
#' @export
outer_HLE2 <-function(x, y) {
  mat <- outer(y, x, "-")
  return(median(mat))
}
