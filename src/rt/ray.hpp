#ifndef __RAY_HPP__
#define __RAY_HPP__
#include"vec3.hpp"
class ray{
 private:
  point o;
  vec3d d;
 public:
  ray():o(),d(){}
  ray(const point& o,const vec3d& d):o(o),d(d){}
  point orig()const{return o;}
  vec3d dire()const{return d;}
  point at(double t)const{return o+d*t;}
};
#endif
