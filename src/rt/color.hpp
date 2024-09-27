#ifndef __COLOR_HPP__
#define __COLOR_HPP__
#include"vec3.hpp"
#include<iostream>
class color:public vec3d{
 public:
  color():vec3d(){}
  color(double r,double g,double b):vec3d(r,g,b){}
  double r()const{return x();}
  double g()const{return y();}
  double b()const{return z();}
  void writePPM(std::ostream& out){
    out<<static_cast<int>(255.999*r())<<' '<<static_cast<int>(255.999*g())<<' '<<static_cast<int>(255.999*b())<<'\n';
  }
};
#endif
