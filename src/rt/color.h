#ifndef __COLOR_H__
#define __COLOR_H__
#include"vec3.h"
#include"common.h"
#include"interval.h"
#include<iostream>
class Col:public Vec3d{
 public:
  Col();
  Col(const Vec3d &v);
  Col(double r,double g,double b);
  double r()const;
  double g()const;
  double b()const;
  double &r();
  double &g();
  double &b();
};
std::ostream& operator<<(std::ostream& out,const Col& c);
#endif
