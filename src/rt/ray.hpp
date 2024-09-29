#ifndef __RAY_HPP__
#define __RAY_HPP__
#include"vec3.hpp"
class Ray{
 private:
  Point o;
  Vec3d d;
 public:
  Ray():o(),d(){}
  Ray(const Point& o,const Vec3d& d):o(o),d(d){}
  const Point &orig()const{return o;}
  const Vec3d &dire()const{return d;}
  Point at(double t)const{return o+d*t;}
};
#endif
