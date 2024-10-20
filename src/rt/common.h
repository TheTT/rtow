#ifndef __COMMON_H__
#define __COMMON_H__
#include<cmath>
#include<limits>
#include<memory>
#include<random>
#include<iostream>
static constexpr double inf=std::numeric_limits<double>::infinity();
static constexpr double pi=3.1415926535897932385;
double d2r(double degrees);
double l2g(double linear);
double randd();
double randd(double min,double max);
#endif
