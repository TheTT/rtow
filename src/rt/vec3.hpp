#ifndef __VEC3_HPP__
#define __VEC3_HPP__
double sqrtRec(double x){
  union{long long i;double y;}u;
  double x2;
  static const double threehalfs=1.5;
  u.y=x;
  x2=u.y*0.5;
  u.i=0x5fe6eb50c7b537a9-(u.i>>1);
  u.y=u.y*(threehalfs-(x2*u.y*u.y));
  u.y=u.y*(threehalfs-(x2*u.y*u.y));
  u.y=u.y*(threehalfs-(x2*u.y*u.y));
  return u.y;
}
class vec3d{
 private:
  double e[3];
 public:
  // Constructors
  vec3d():e{0,0,0}{}
  vec3d(double e0,double e1,double e2):e{e0,e1,e2}{}
  // Entry getters
  double x()const{return e[0];}
  double y()const{return e[1];}
  double z()const{return e[2];}
  double &x(){return e[0];}
  double &y(){return e[1];}
  double &z(){return e[2];}
  // Monadic operators
  vec3d operator-()const{return vec3d(-e[0],-e[1],-e[2]);}
  double operator[](int i)const{return e[i];}
  double& operator[](int i){return e[i];}
  // Binomial operators
  vec3d operator+(const vec3d& v)const{return vec3d(e[0]+v.e[0],e[1]+v.e[1],e[2]+v.e[2]);}
  vec3d operator-(const vec3d& v)const{return vec3d(e[0]-v.e[0],e[1]-v.e[1],e[2]-v.e[2]);}
  vec3d operator*(const double t)const{return vec3d(e[0]*t,e[1]*t,e[2]*t);}
  friend vec3d operator*(const double t,const vec3d& v);
  vec3d operator/(const double t)const{return *this*(1./t);}
  double operator*(const vec3d& v)const{return e[0]*v.e[0]+e[1]*v.e[1]+e[2]*v.e[2];}
  vec3d operator^(const vec3d& v)const{return vec3d(e[1]*v.e[2]-e[2]*v.e[1],e[2]*v.e[0]-e[0]*v.e[2],e[0]*v.e[1]-e[1]*v.e[0]);}
  vec3d operator%(const vec3d& v)const{return vec3d(e[0]*v.e[0],e[1]*v.e[1],e[2]*v.e[2]);}
  // Assignment operators
  vec3d& operator+=(const vec3d& v){e[0]+=v.e[0];e[1]+=v.e[1];e[2]+=v.e[2];return *this;}
  vec3d& operator-=(const vec3d& v){e[0]-=v.e[0];e[1]-=v.e[1];e[2]-=v.e[2];return *this;}
  vec3d& operator*=(const double t){e[0]*=t;e[1]*=t;e[2]*=t;return *this;}
  vec3d& operator/=(const double t){return *this*=(1./t);}
  // Utility functions
  double lenSqr()const{return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];}
  double lenRec()const{return sqrtRec(lenSqr());}
  double len()const{double x=lenSqr();return x*sqrtRec(x);}
  vec3d unit()const{return *this*lenRec();}
  void makeUnit(){*this*=lenRec();}
};
// Binomial operators
vec3d operator*(const double t,const vec3d& v){return v*t;}
using point3d=vec3d;
#endif
