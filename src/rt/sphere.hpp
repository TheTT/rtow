#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__
#include"base.hpp"
#include"hittable.hpp"
class Sphere:public Hittable{
 private:
  Point center;
  double radius;
 public:
  Sphere(const Point &center,const double radius):center(center),radius(fmax(0.,radius)){}
  virtual bool hit(const Ray &ray,Interval rg,Hitment &h)const override{
    Vec3d oc=center-ray.getOri();
    const Vec3d &rd=ray.getDir();
    double a=rd.lenSqr();
    double hlf=rd*oc;
    double c=oc.lenSqr()-radius*radius;
    double delD4=hlf*hlf-a*c;
    if(delD4<0)return false;
    double &root=h.t=(hlf-sqrt(delD4))/a;
    if(!rg.surround(root)){
      root=(hlf+sqrt(delD4))/a;
      if(!rg.surround(root))
        return false;
    }
    h.p=ray.at(root);
    h.n=(h.p-center)/radius;
    h.f=(h.n*rd<0);
    return true;
  }
};
#endif
