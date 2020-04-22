/**
 * @file main.cpp
 * @author Gondy Tania & Bailleul Géraldine & Rémi Huguet
 * @brief presentation of the results
 * @version 0.1
 * @date 2019-09-18
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <armadillo>
#include <iostream>
#include <fstream>
#include <math.h>
#include <unistd.h>

#include "../headers/Poly.h"
#include "../headers/Basis.h"
#include "../headers/NuclearLocalDensity.h"

/**
 * @brief main function of this project
 *
 * @param argc
 * @param argv
 * @return int
 */
int main()
{

    /// r and z test vectors
<<<<<<< HEAD
    arma::vec r = {0.0, 1.0}; //arma::linspace<arma::vec>(-10, 10, 30);
    arma::vec z = {0.0, 1.0}; //arma::linspace<arma::vec>(-10, 10, 30);
=======
    arma::vec r = arma::linspace<arma::vec>(-10, 10, 30);
    arma::vec z = arma::linspace<arma::vec>(-10, 10, 30);
>>>>>>> ad294f48b06f0372c032b492f391fff9bf16d546

    /// basis values
    double br = 1.935801664793151;
    double bz = 2.829683956491218;
    int N = 14;
    double Q = 1.3;
    /// defining basis
    Basis basis(br, bz, N, Q);

    /// defining NuclearLocalDensity
    NuclearLocalDensity nld;
    arma::mat S1 = nld.direct_algorithm(r, z, basis);
    S1.print();
    arma::mat S2 = nld.opt_algorithm(r, z, basis);
    S2.print();

<<<<<<< HEAD
    /// tests
    arma::mat test1 = arma::zeros(2, 2);
    //arma::mat test_cal = test1*test1;
    //test_cal.print();
=======
    S2.save("obj/out.arma", arma::arma_ascii);
>>>>>>> ad294f48b06f0372c032b492f391fff9bf16d546

    return 0;
}