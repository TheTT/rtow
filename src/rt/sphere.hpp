#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__
#include<cmath>
#include"hittable.hpp"
class Sphere:public Hittable{
 private:
  Point center;
  double radius;
 public:
  Sphere(const Point &center,const double radius):center(center),radius(radius){}
  virtual bool hit(const Ray &ray,double tmin,double tmax,Hitment &h)const override{
    Vec3d oc=center-ray.getOri();
    const Vec3d &rd=ray.getDir();
    double a=rd.lenSqr();
    double hlf=rd*oc;
    double c=oc.lenSqr()-radius*radius;
    double delD4=hlf*hlf-a*c;
    if(delD4<0)return false;
    double root=(hlf-sqrt(delD4))/a;
    if(root<tmin||root>tmax){
      root=(hlf+sqrt(delD4))/a;
      if(root<tmin||root>tmax)
        return false;
    }
    h.t=root;
    h.p=ray.at(root);
    h.n=(h.p-center)/radius;
    return true;
  }
};
#endif
