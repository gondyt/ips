/**
 * @file Poly.h
 * @author Gondy Tania
 * @brief definition of class Poly
 * Defines everything that concerns polynomials, especially Hermite and Laguerre ones
 * @version 0.1
 * @date 2019-11-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */

/// tag definition 
#ifndef POLY_H
#define POLY_H

/// includes
#include <armadillo>


/**
 * @brief class Poly
 * 
 * Computes values of Hermite and Laguerre polynomials
 */
class Poly
{
    private :

        /// matrix to stock values computed by calchermite(n, z)
        arma::mat HS;

        /// cube to stock values computed by calclaguerre(m, n, z)
        arma::cube LS;


    public :

        /// the default construtor

        /**
         * @fn Poly
         * @brief Construct a new Poly object
         * 
         */
        Poly();

        /// the default destructor
        
        /**
         * @fn ~Poly
         * @brief Destroy the Poly object
         * 
         */
        ~Poly();


        /// methods

        /**
         * @fn calcHermite
         * @brief computes hermite polynomials values for n = {0, ..., n-1} and one
         * position vector z
         * 
         * @param n an integer ( 2 <= n )
         * because the first two columns are computed out of the loop
         * @param z a position vector
         */
        void calcHermite( int, arma::vec );

        /**
         * @fn hermite
         * @brief select a data vector in the matrix containing the solutions of Hermite polynomials
         * 
         * @param n an integer (0 <= n and n < HS.ncol )
         * @return (arma::vec) vector containing the nth columns of HS, which
         * contains a matrix of the solutions of hermite polynomials for n = {0, ... , n-1}
         * and z a position vector
         */
        arma::vec hermite( int );

        /**
         * @fn calcLaguerre
         * @brief computes laguerre polynomials values for m = {0, ..., m-1} and 
         * n = {0, ..., n-1} and one position vector z
         * 
         * @param m an integer ( 1 <= m )
         * @param n an integer ( 2 <= n )
         * again, the first two columns are computed out of the loop
         * @param z position vector
         */
        void calcLaguerre(int, int, arma::vec );

        /**
         * @fn laguerre
         * @brief select a data vector in the matrix containing the solutions of Laguerre polynomials
         * 
         * @param m an integer ( 0 <= m and m < LS.nslice )
         * @param n an integer ( 0 <= n and n < LS.ncol )
         * @return (arma::vec) vector containing the mth slice, the nth column of LS,
         * which contains a cube of solutions of laguerre polynomials for m = {0, ..., m-1},
         * n = {0, ..., n-1} and z a position vector
         */
        arma::vec laguerre( int, int );

};

#endif