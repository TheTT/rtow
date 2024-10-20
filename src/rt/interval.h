#ifndef __INTERVAL_H__
#define __INTERVAL_H__
#include"base.h"
class Interval{
 public:
  double l,r;
  Interval();
  Interval(double l,double r);
  double size()const;
  bool empty()const;
  bool contains(double x)const;
  bool contains(const Interval &i)const;
  bool surround(double x)const;
  double clamp(double x)const;
};
#endif
