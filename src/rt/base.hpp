#ifndef __BASE_HPP__
#define __BASE_HPP__
#include<cmath>
#include<limits>
#include<memory>
#include<iostream>
constexpr double inf=std::numeric_limits<double>::infinity();
constexpr double pi=3.1415926535897932385;
inline double d2r(double degrees) {
  static constexpr double r=pi/180.0;
  return degrees*r;
}
#include"ray.hpp"
#include"vec3.hpp"
#include"color.hpp"
#endif
