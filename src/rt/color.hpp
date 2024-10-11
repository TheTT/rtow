#ifndef __COLOR_HPP__
#define __COLOR_HPP__
#include"vec3.hpp"
#include"common.hpp"
#include"interval.hpp"
#include<iostream>
class Col:public Vec3d{
 public:
  Col():Vec3d(){}
  Col(const Vec3d &v):Vec3d(v){}
  Col(double r,double g,double b):Vec3d(r,g,b){}
  double r()const{return x();}
  double g()const{return y();}
  double b()const{return z();}
  double &r(){return x();}
  double &g(){return y();}
  double &b(){return z();}
};
std::ostream& operator<<(std::ostream& out,const Col& c){
  static const Interval r(0,0.999);
  return out<<int(256*r.clamp(l2g(c.r())))<<' '<<int(256*r.clamp(l2g(c.g())))<<' '<<int(256*r.clamp(l2g(c.b())));
}
#endif
