#ifndef __VEC3_HPP__
#define __VEC3_HPP__
#include"common.hpp"
double sqrtRec(double x){
  union{long long i;double y;}u;
  double x2;
  static constexpr double threehalfs=1.5;
  u.y=x;
  x2=u.y*0.5;
  u.i=0x5fe6eb50c7b537a9-(u.i>>1);
  u.y=u.y*(threehalfs-(x2*u.y*u.y));
  u.y=u.y*(threehalfs-(x2*u.y*u.y));
  u.y=u.y*(threehalfs-(x2*u.y*u.y));
  return u.y;
}
class Vec3d{
 private:
  double e[3];
 public:
  // Constructors
  Vec3d():e{0,0,0}{}
  Vec3d(double e0,double e1,double e2):e{e0,e1,e2}{}
  // Entry getters
  double x()const{return e[0];}
  double y()const{return e[1];}
  double z()const{return e[2];}
  double &x(){return e[0];}
  double &y(){return e[1];}
  double &z(){return e[2];}
  // Monadic operators
  Vec3d operator-()const{return Vec3d(-e[0],-e[1],-e[2]);}
  double operator[](int i)const{return e[i];}
  double& operator[](int i){return e[i];}
  // Binomial operators
  Vec3d operator+(const Vec3d& v)const{return Vec3d(e[0]+v.e[0],e[1]+v.e[1],e[2]+v.e[2]);}
  Vec3d operator-(const Vec3d& v)const{return Vec3d(e[0]-v.e[0],e[1]-v.e[1],e[2]-v.e[2]);}
  Vec3d operator*(const double t)const{return Vec3d(e[0]*t,e[1]*t,e[2]*t);}
  friend Vec3d operator*(const double t,const Vec3d& v);
  Vec3d operator/(const double t)const{return *this*(1./t);}
  double operator*(const Vec3d& v)const{return e[0]*v.e[0]+e[1]*v.e[1]+e[2]*v.e[2];}
  Vec3d operator^(const Vec3d& v)const{return Vec3d(e[1]*v.e[2]-e[2]*v.e[1],e[2]*v.e[0]-e[0]*v.e[2],e[0]*v.e[1]-e[1]*v.e[0]);}
  Vec3d operator%(const Vec3d& v)const{return Vec3d(e[0]*v.e[0],e[1]*v.e[1],e[2]*v.e[2]);}
  // Assignment operators
  Vec3d& operator+=(const Vec3d& v){e[0]+=v.e[0];e[1]+=v.e[1];e[2]+=v.e[2];return *this;}
  Vec3d& operator-=(const Vec3d& v){e[0]-=v.e[0];e[1]-=v.e[1];e[2]-=v.e[2];return *this;}
  Vec3d& operator*=(const double t){e[0]*=t;e[1]*=t;e[2]*=t;return *this;}
  Vec3d& operator/=(const double t){return *this*=(1./t);}
  // Utility functions
  double lenSqr()const{return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];}
  double lenRec()const{return sqrtRec(lenSqr());}
  double len()const{double x=lenSqr();return x*sqrtRec(x);}
  Vec3d norm()const{return *this*lenRec();}
  void makeUnit(){*this*=lenRec();}
  // Static functions
  static Vec3d randOct1(){return Vec3d(randd(),randd(),randd());}
  static Vec3d randUnit(){
    double x,y,z,l2;
    do{
      x=2.*randd()-1.;
      y=2.*randd()-1.;
      z=2.*randd()-1.;
      l2=x*x+y*y+z*z;
    }while(1e-160>l2||l2>1.);
    return Vec3d(x,y,z).norm();
  }
  static Vec3d randHemi(const Vec3d& n){
    Vec3d v=randUnit();
    return v*n>0?v:-v;
  }
};
// Binomial operators
Vec3d operator*(const double t,const Vec3d& v){return v*t;}
using Point=Vec3d;
#endif
