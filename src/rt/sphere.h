#ifndef __SPHERE_H__
#define __SPHERE_H__
#include"base.h"
#include"hittable.h"
class Sphere:public Hittable{
 private:
  Point center;
  double radius;
 public:
  Sphere(const Point &center,const double radius);
  virtual bool hit(const Ray &ray,Interval rg,Hitment &h)const override;
  virtual std::shared_ptr<Hittable> clone()const override;
};
#endif
