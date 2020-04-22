/**
 * @file Poly.cpp
 * @author Gondy Tania
 * @brief implementation of the class Poly described in Poly.h
 * @version 0.1
 * @date 2019-11-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */

/// includes
#include "../headers/Poly.h"



Poly::Poly()
{
    
}

Poly::~Poly()
{

}


void Poly::calcHermite (int n, arma::vec z )
{
    /// solution matrix initialisation
    arma::mat S = arma::mat(z.n_rows, n);

    /// initializes the first two columns
    S.col(0).fill(1.0);
    S.col(1) = 2.0 * z;

    /// filling with the formula
    int i;
    for (i = 2 ; i < n ; i++)
    {
        double id = i;
        S.col(i) = 2.0*z%S.col(i-1) - 2.0*(id-1.0)*S.col(i-2);
    }

    /// store the result in HS
    HS = S;

}

arma::vec Poly::hermite( int n )
{
    /// gets wanted values
    arma::vec S = HS.col(n);

    /// returns those values
    return S;
}

void Poly::calcLaguerre( int m, int n, arma::vec z )
{
    /// variable declaration
    int i, j;

    /// solution cube initialisation
    /// m settled as slice index to separate data in a practical way
    /// besides the computation don't depends on a call of Laguerre with a (de)cremental m index
    arma::cube S = arma::cube(z.n_rows, n, m);

    /// initializes two first columns
    for ( j = 0; j < m; j++)
    {
        double jd = j;
        S.slice(j).col(0).fill(1.0);
        S.slice(j).col(1) = 1.0 + jd - z;
    }

    /// filling
    /// for each slice m = j
    for (j = 0 ; j < m ; j++)
    {
        double jd = j;
        /// for each column n = i
        for (i = 2; i < n; i++)
        {
            double id = i;
            arma::vec tmp = S.slice(j).col(i-1);
            S.slice(j).col(i) = (2.0 + ((jd-1.0)/id))*tmp - (1.0/id)*z%tmp - (1.0 + ((jd-1.0)/id))*S.slice(j).col(i-2);
        }
    }

    /// stores the results in LS
    LS = S;
}

arma::vec Poly::laguerre(int m, int n)
{
    /// gets wanted values
    arma::vec S = LS.slice(m).col(n);

    /// returns those values
    return S;
}