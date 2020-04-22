/**
 * @file Fact.h
 * @author Gondy Tania
 * @brief definition of class Fact
 * Computes fact(n) using double
 * @version 0.1
 * @date 2019-11-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

/// tag definition
#ifndef FACT_H
#define FACT_H



class Fact
{
    public:

        /// constructors

        /**
         * @fn Fact
         * @brief Construct a new Fact object
         * 
         */
        Fact();


        /// destructor

        /**
         * @fn ~Fact
         * @brief Destroy the Fact object
         * 
         */
        ~Fact();


        /// method

        /**
         * @fn fact
         * @brief computes the factorial of n
         * 
         * @param n a double
         * @return returns fact(n) as a double
         */
        double fact( double );

};



#endif