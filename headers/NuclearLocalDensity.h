/**
 * @file NuclearLocalDensity.h
 * @author Gondy Tania
 * @brief description of class NuclearLocalDensity
 * @version 0.1
 * @date 2019-11-15
 *
 * @copyright Copyright (c) 2019
 *
 */


#ifndef NUCLEAR_LOCAL_DENSITY_H
#define NUCLEAR_LOCAL_DENSITY_H


#include "Basis.h"
#include <armadillo>

class NuclearLocalDensity {
  private:

    /// access to quantum nomber basis and basis functions
    Basis basis;

  public:
    NuclearLocalDensity();
    ~NuclearLocalDensity();


    /// methods

    /**
     * @fn direct_algorithm
     * @brief computes nuclear local density with the direct algorithm
     *
     * @param rVals
     * @param zVals
     * @param basis
     * @return arma::mat
     */
    arma::mat direct_algorithm( arma::vec, arma::vec, Basis );

    /**
     * @fn opt_algorithm
     * @brief computes nuclear local density with sum optimizations
     *
     * @param rVals
     * @param zVals
     * @param basis
     * @return arma::mat
     */
    arma::mat opt_algorithm( arma::vec, arma::vec, Basis );

};


#endif