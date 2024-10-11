#ifndef __HITTABLE_HPP__
#define __HITTABLE_HPP__
#include"base.hpp"
#include"interval.hpp"
struct Hitment;
class Hittable{
 public:
  ~Hittable()=default;
  virtual bool hit(const Ray &ray,Interval rg,Hitment &h)const=0;
};
struct Hitment{
  Point p;
  Vec3d n;
  Hittable *obj;
  double t;
  bool f;
  Hitment():p(),n(),obj(nullptr),t(inf),f(false){}
};
#endif
