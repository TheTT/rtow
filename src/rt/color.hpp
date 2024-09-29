#ifndef __COLOR_HPP__
#define __COLOR_HPP__
#include"vec3.hpp"
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
  return out<<int(255.999*c.r())<<' '<<int(255.999*c.g())<<' '<<int(255.999*c.b());
}
#endif
