/**
 * @file NuclearLocalDensity.cpp
 * @brief implementation of NuclearLocalDensity.h
 * @version 0.1
 *
 */

#include "../headers/NuclearLocalDensity.h"

/**
 * @brief Construct a new Nuclear Local Density:: Nuclear Local Density object
 * 
 */
NuclearLocalDensity::NuclearLocalDensity()
{
}

/**
 * @brief Destroy the Nuclear Local Density:: Nuclear Local Density object
 * 
 */
NuclearLocalDensity::~NuclearLocalDensity()
{
}

/**
 * @brief compute 
 * 
 * @param rVals 
 * @param zVals 
 * @param basis 
 * @return arma::mat 
 */
arma::mat NuclearLocalDensity::direct_algorithm(arma::vec rVals, arma::vec zVals, Basis basis)
{
    /// loading rho matrix
    arma::mat rho;
    rho.load("src/data/rho.arma", arma::arma_ascii);

    /// defining nbR and nbZ
    unsigned int nbR = rVals.n_rows;
    unsigned int nbZ = zVals.n_rows;

    arma::mat result = arma::zeros(nbR, nbZ); /// number of points on r- and z- axes

    /// time records
    arma::wall_clock timer;
    timer.tic();

    int a = 0;
    for (int ma = 0; ma < basis.mMax; ma++)
    {
        for (int na = 0; na < basis.nMax(ma); na++)
        {
            for (int n_za = 0; n_za < basis.n_zMax(ma, na); n_za++)
            {
                int b = 0;
                for (int mb = 0; mb < basis.mMax; mb++)
                {
                    for (int nb = 0; nb < basis.nMax(mb); nb++)
                    {
                        for (int n_zb = 0; n_zb < basis.n_zMax(mb, nb); n_zb++)
                        {
                            arma::mat psyA = basis.basisFunc(ma, na, n_za, zVals, rVals);
                            arma::mat psyB = basis.basisFunc(mb, nb, n_zb, zVals, rVals);
                            result += psyA % psyB * rho(a, b);

                            b++;
                        }
                    }
                }
                a++;
            }
        }
    }

    /// ends time records
    double time = timer.toc();
    std::cout << "Time recorded for direct = " << time << ".\n"
              << std::endl;

    return result;
}

/**
 *  Calcule la densité nucléaire
 *  @param basis la base de calcul
 *  @param rvals le vecteur des coordonnées 'r' 
 *  @param zvals le vecteur des coordonnées 'z' 
 *  @return une tranche de la densité nucléaire (theta = 0)
 */
arma::mat NuclearLocalDensity::opt_algorithm(arma::vec rVals, arma::vec zVals, Basis basis)
{
    /// loading rho matrix
    arma::mat rho;
    rho.load("src/data/rho.arma", arma::arma_ascii);

    /// number of points on r- and z- axes
    arma::mat result = arma::zeros(rVals.size(), zVals.size()); 


    /// time records
    arma::wall_clock timer;
    timer.tic();

    int a = 0;
    int b_tmp = 0; /// delete mb loop because if ma != mb then phy(a,b) == 0
    for (int m = 0; m < basis.mMax; m++)
    {
        for (int na = 0; na < basis.nMax(m); na++)
        {
            for (int n_za = 0; n_za < basis.n_zMax(m, na); n_za++)
            {
                arma::mat psyA = basis.basisFunc(m, na, n_za, zVals, rVals); /// psyA computed only once out of B's loops

                int b = b_tmp;
                // double rho = rho(a, b);
                for (int nb = 0; nb < basis.nMax(m); nb++)
                {
                    for (int n_zb = 0; n_zb < basis.n_zMax(m, nb); n_zb++)
                    {
                        arma::mat psyB = basis.basisFunc(m, nb, n_zb, zVals, rVals);
                        result += psyA % psyB * rho(a, b);

                        b++;
                    }
                }

                a++;
            }
        }

        b_tmp = a;
    }

    /// ends time records
    double time = timer.toc();
    std::cout << "Time recorded for opt = " << time << ".\n"
              << std::endl;

    return result;
<<<<<<< HEAD

}
=======
}
>>>>>>> ad294f48b06f0372c032b492f391fff9bf16d546
