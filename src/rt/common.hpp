#ifndef __COMMON_HPP__
#define __COMMON_HPP__
#include<cmath>
#include<limits>
#include<memory>
#include<random>
#include<iostream>
constexpr double inf=std::numeric_limits<double>::infinity();
constexpr double pi=3.1415926535897932385;
inline double d2r(double degrees){
  static constexpr double r=pi/180.0;
  return degrees*r;
}
inline double randd(){
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_real_distribution<double> dist(0.0,1.0);
  return dist(gen);
}
inline double randd(double min,double max){
  return min+randd()*(max-min);
}
#endif
