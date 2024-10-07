#ifndef __HITTABLE_HPP__
#define __HITTABLE_HPP__
#include"base.hpp"
#include"interval.hpp"
struct Hitment{
  Point p;
  Vec3d n;
  double t;
  bool f;
};
class Hittable{
 public:
  ~Hittable()=default;
  virtual bool hit(const Ray &ray,Interval rg,Hitment &h)const=0;
};
#endif
