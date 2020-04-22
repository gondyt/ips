/**
 * @file Fact.cpp
 * @author Gondy Tania
 * @brief implementation of class Fact described in Fact.h
 * @version 0.1
 * @date 2019-11-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */


/// includes
#include "../headers/Fact.h"


Fact::Fact()
{

}

Fact::~Fact()
{

}


/// method

double Fact::fact( double n )
{
    /// if n = 0.0 or n = 1.0 it returns 1.0
    if ( n == 0.0 || n == 1.0 )
    {
        return 1.0;
    }
    /// else it computes fact(n) recursively, then returns the result
    else
    {
        return n*fact(n - 1.0);
    }
    
}