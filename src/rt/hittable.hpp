#ifndef __HITTABLE_HPP__
#define __HITTABLE_HPP__
#include"base.hpp"
#include"interval.hpp"
class Material;
struct Hitment{
  Point p;
  Vec3d n;
  std::shared_ptr<Material> m;
  double t;
  bool f;
  Hitment():p(),n(),m(),t(inf),f(false){}
};
#include"material.hpp"
class Hittable{
 protected:
  std::shared_ptr<Material> m;
 public:
  Hittable():m(){}
  ~Hittable()=default;
  virtual bool hit(const Ray &ray,Interval rg,Hitment &h)const=0;
  Hittable &setMat(const std::shared_ptr<Material> &m){this->m=m;return *this;}
  virtual std::shared_ptr<Hittable> clone()const=0;
};
template<typename _Tp>
concept DerivedFromHittable=std::is_base_of_v<Hittable,_Tp>;
#endif
