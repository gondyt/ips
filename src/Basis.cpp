/**
 * @file Basis.cpp
 * @author Gondy Tania
 * @brief implementation of class described in Basis.h
 * @version 0.1
 * @date 2019-11-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../headers/Basis.h"

Basis::Basis()
{

}

Basis::Basis( double br, double bz, int N, double Q )
{
    /// defining b_r and b_z
    b_r = br;
    b_z = bz;


    /**
     * @brief mMax, nMax and n_zMax computation
     * 
     */
    
    /**
     * @brief computation of m_Max
     * 
     */

    /// index declaration and const declaration
    int i = 1;

    double Nd = (double) N;
    double K = (Nd + 2.0)*pow(Q, 2.0/3.0) + (1.0/2.0);

    /// while n_max_z_i < 1 add 1 to i and re-compute n_max_z_i
    int n_max_z_i = floor( K - i*Q );

    while ( n_max_z_i >= 1.0 )
    {
        i++;
        n_max_z_i = floor( K - i*Q );
    }

    mMax = i-1;
    int m_max = i-1;


    /**
     * @brief computation of nMax
     * 
     */

    /// variable definition
    arma::ivec n_max = arma::ivec(m_max);

    for (int i = 0; i < m_max; i++)
    {
        double id = (double) i;
        double md = (double) m_max;
        n_max(i) = (1.0/2.0) * (md - id - 1.0) + 1.0;
    }

    nMax = n_max;

    /**
     * @brief computation of n_zMax
     * 
     */

    /// variable definition
    arma::imat n_z_max = arma::imat(m_max, n_max.n_rows);

    for (int i = 0; i < m_max; i++)
    {
        double id = (double) i;

        for (unsigned int j = 0; j < n_max.n_rows; j++)
        {
            double jd = (double) j;

            int tmp = floor( K - (id + 2.0*jd + 1.0)*Q );
            if (tmp < 0)
            {
                tmp = 0;
            }
            n_z_max(i,j) = tmp;
        }
    }

    /// re-sizing matrix
    int index = 0;
    while ( n_z_max(0, index) != 0 )
    {
        index++;
    }

    n_z_max.resize(m_max, index);
    n_zMax = n_z_max;

}


Basis::~Basis()
{

}


arma::vec Basis::rPart( arma::vec r, int m, int n )
{
    /// we take the absolute value of m
    double m_abs = fabs(m);
    /// conversion from int to double for n
    double nd = (double) n;
    /// laguerre parameter cumputation
    arma::vec lag_par = (pow(r, 2)) / (pow(b_r, 2));

    /// we get laguerre polynomials solutions corresponding to
    /// our parameters
    Poly poly;
    poly.calcLaguerre(m+1, n+2, lag_par);
    arma::vec L = poly.laguerre(m, n);

    /// multiplication by ( r / b_r )^(|m|)
    L = pow( (r / b_r), m_abs ) % L;

    /// multiplication by exp( -r² / 2*b_r² )
    L = exp( (-pow( r, 2 ))/(2.0 * pow( b_r, 2)) ) % L;

    /// multiplication by sqrt( fact(n)/fact(n+|m|) )
    Fact f_n;
    Fact f_n_m;
    L = sqrt( (f_n.fact(nd)) / (f_n_m.fact( nd + m_abs )) ) * L;

    /// multiplication by 1 / b_r*sqrt(PI)
    L = ( 1.0 / (b_r*sqrt(M_PI)) ) * L;

    return L;
}

arma::vec Basis::zPart( arma::vec z, int n_z )
{
    /// conversion from int to double for n_z
    double n_zd = (double) n_z;
    /// hermite parameter computation
    arma::vec her_par = z / b_z;

    /// we get hermite polynomials solutions corresponding to
    /// our parameters
    Poly poly;
    poly.calcHermite(n_z+2, her_par);
    arma::vec H = poly.hermite(n_z);

    /// multiplication by exp( (-z²)/(2.0*b_z²) )
    H = exp( (-pow(z,2.0))/(2.0*pow(b_z,2.0)) ) % H;

    /// multiplication by 1 / sqrt( 2^n_z * sqrt(PI) * fact(n_z) )
    Fact f_nz;
    H = (1.0 / (sqrt( pow(2, n_zd) * sqrt(M_PI) * f_nz.fact(n_zd) )) ) * H;

    /// multiplication by 1 / sqrt(b_z)
    H = (1.0 / (sqrt( b_z ))) * H;

    return H;
}


arma::mat Basis::basisFunc( int m, int n, int n_z, arma::vec zVals, arma::vec rVals )
{
    /// computing Z(z, n_z)
    arma::vec zPartVals = zPart(zVals, n_z);
    /// computing R(r, m, n)
    arma::vec rPartVals = rPart(rVals, m, n);

    unsigned int nbR = rPartVals.n_rows;
    unsigned int nbZ = zPartVals.n_rows;
    /// solution returned
    arma::mat psy = arma::zeros(nbR, nbZ);

    /// filling psy
    for (unsigned int i = 0; i < nbZ; i++)
    {
        psy.col(i) = rPartVals * zPartVals(i);
    }

    return psy;
}