/**
 * @file FactTest.h
 * @author Gondy Tania
 * @brief unit test for class Fact
 * @version 0.1
 * @date 2019-11-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../cxxtest-4.4/cxxtest/TestSuite.h"
#include "../headers/Fact.h"
#include <armadillo>

class FactTest : public CxxTest::TestSuite
{
    public:

        void testFact( void )
        {

        /// Unit test for Fact -- factorial of n (double)
        Fact f;

        arma::vec nVals, calcVals, targetVals;

        nVals = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        calcVals = arma::zeros(10);
        /// values taken from Wikipédia :
        targetVals = {1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0, 40320.0, 362880.0};

        /// filling calcVals with cumputed fact(nVals)
        // A TESTER calcVals = f.fact(nVals);
        for (unsigned int i = 0; i < nVals.n_rows; i++)
        {
            calcVals(i) = f.fact(nVals(i));
        }
        
        TS_ASSERT_DELTA(arma::norm((calcVals / targetVals) - 1.0), 0.0, 1e-08);
        }

};