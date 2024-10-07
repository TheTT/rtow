#ifndef __INTERVAL_HPP__
#define __INTERVAL_HPP__
#include"base.hpp"
class Interval{
 public:
  double l,r;
  Interval():l(inf),r(-inf){}
  Interval(double l,double r):l(l),r(r){}
  double size()const{return r-l;}
  bool empty()const{return r<l;}
  bool contains(double x)const{return l<=x&&x<=r;}
  bool contains(const Interval &i)const{return i.empty()||(l<=i.l&&i.r<=r);}
  bool surround(double x)const{return l<x&&x<r;}
};
#endif
