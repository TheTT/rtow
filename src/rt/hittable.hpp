#ifndef __HITTABLE_HPP__
#define __HITTABLE_HPP__
#include"ray.hpp"
struct Hitment{
  Point p;
  Vec3d n;
  double t;
};
class Hittable{
 public:
  ~Hittable()=default;
  virtual bool hit(const Ray &ray,double tmin,double tmax,Hitment &h)const=0;
};
#endif
