#ifndef __POINT_HPP__
#define __POINT_HPP__
#include"vec3.hpp"
class point:public vec3d{
 public:
  point():vec3d(){}
  point(double x,double y,double z):vec3d(x,y,z){}
};
#endif
