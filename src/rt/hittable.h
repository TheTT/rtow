#ifndef __HITTABLE_H__
#define __HITTABLE_H__
struct Hitment;
class Hittable;
#include"base.h"
#include"interval.h"
#include"material.h"
struct Hitment{
  Point p;
  Vec3d n;
  std::shared_ptr<Material> m;
  double t;
  bool f;
  Hitment();
};
class Hittable{
 protected:
  std::shared_ptr<Material> m;
 public:
  Hittable();
  virtual bool hit(const Ray &ray,Interval rg,Hitment &h)const=0;
  Hittable &setMat(const std::shared_ptr<Material> &m);
  virtual std::shared_ptr<Hittable> clone()const=0;
};
template<typename _Tp>
concept DerivedFromHittable=std::is_base_of_v<Hittable,_Tp>;
#endif
