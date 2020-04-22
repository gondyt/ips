/**
 * @file Basis.h
 * @author Gondy Tania
 * @brief definition of class Basis
 * Computes the basis vectors and the basis functions
 * @version 0.1
 * @date 2019-11-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */


/// tag definition
#ifndef BASIS_H
#define BASIS_H

/// includes
#include <armadillo>
#include <math.h>
#include <iostream>

#include "Poly.h"
#include "Fact.h"

/**
 * @brief Basis class definition
 * 
 * computes quantum numbers with two parameters : an integer N and a double Q
 * computes basis functions with two parameters : two doubles br and bz
 */
class Basis
{
    public:

        /// defining b_r and b_z
        double b_r;
        double b_z;

        /// mMax limit for m
        int mMax;

        /// nMax limit for n
        arma::ivec nMax;

        /// n_zMax limit for n_z
        arma::imat n_zMax;



        /// constructors

        /**
         * @fn Basis
         * @brief construct a new Basis object
         * 
         */
        Basis();

        /**
         * @fn Basis
         * @brief construct a new Basis object and computes its truncation
         * based on the values of the quantum numbers
         * 
         * @param br (double)
         * @param bz (double)
         * @param N (integer)
         * @param Q (double)
         */
        Basis( double, double, int, double );

        /// the default destructor

        /**
         * @fn ~Basis
         * @brief Destroy the Basis object
         * 
         */
        ~Basis();        


        /// methods

        /**
         * @fn rPart
         * @brief computes the r-axis based function R(r, m, n)
         * 
         * @param r a position vector
         * @param m an integer (0 <= m)
         * @param n an integer (0 <= n)
         * @return a vector containing the results
         */
        arma::vec rPart( arma::vec, int, int );

        /**
         * @fn zPart
         * @brief computes the z-axis based function Z(z, n_z)
         * 
         * @param z a position vector
         * @param n_z an integer (0 <= n_z)
         * @return a vector containing the results
         */
        arma::vec zPart( arma::vec, int );


        /**
         * @fn basisFunc
         * @brief computes basis functions
         * 
         * @param m an integer (0 <= m)
         * @param n an integer (0 <= n)
         * @param n_z an integer (0 <= n_z)
         * @param zVals a position vector on z-axis
         * @param rVals a position vector on r-axis
         * @return a matrix containing the results under the following form :
         * for z = (z1, ..., zi) and r = (r1, ... rj) :
         * we get Z(z, n_z) = (Z1, ... Zi) and R(r, m, n) = (R1, ..., Rj)
         * and psy = [ [R1*Z1, R1*Z2, ..., R1*Zi],
         *             [R2*Z1, R2*Z2, ..., R2*Zi],
         * 
         *             [Rj*Z1, Rj*Z2, ..., Rj*Zi] ]
         */
        arma::mat basisFunc( int, int, int, arma::vec, arma::vec );

};


#endif