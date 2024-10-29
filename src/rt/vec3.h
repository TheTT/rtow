#ifndef __VEC3_H__
#define __VEC3_H__
#include"common.h"
double sqrtRec(double x);
class Vec3d{
 private:
  double e[3];
 public:
  Vec3d();
  Vec3d(double e0,double e1,double e2);
  double x()const;
  double y()const;
  double z()const;
  double &x();
  double &y();
  double &z();
  Vec3d operator-()const;
  double operator[](int i)const;
  double& operator[](int i);
  Vec3d operator+(const Vec3d& v)const;
  Vec3d operator-(const Vec3d& v)const;
  Vec3d operator*(const double t)const;
  friend Vec3d operator*(const double t,const Vec3d& v);
  Vec3d operator/(const double t)const;
  double operator*(const Vec3d& v)const;
  Vec3d operator^(const Vec3d& v)const;
  Vec3d operator%(const Vec3d& v)const;
  Vec3d& operator+=(const Vec3d& v);
  Vec3d& operator-=(const Vec3d& v);
  Vec3d& operator*=(const double t);
  Vec3d& operator/=(const double t);
  double lenSqr()const;
  double lenRec()const;
  double len()const;
  Vec3d norm()const;
  void makeUnit();
  bool nearZero()const;
  Vec3d reflect(const Vec3d& n)const;
  static Vec3d randOct1();
  static Vec3d randUnit();
  static Vec3d randHemi(const Vec3d& n);
};
Vec3d operator*(const double t,const Vec3d& v);
using Point=Vec3d;
#endif
