#include"vec3.h"
double sqrtRec(double x){
  union{long long i;double y;}u;
  double x2=(u.y=x)*0.5;
  static constexpr double threehalfs=1.5;
  u.i=0x5fe6eb50c7b537a9-(u.i>>1);
  u.y=u.y*(threehalfs-(x2*u.y*u.y));
  u.y=u.y*(threehalfs-(x2*u.y*u.y));
  u.y=u.y*(threehalfs-(x2*u.y*u.y));
  return u.y;
}
Vec3d::Vec3d():e{0,0,0}{}
Vec3d::Vec3d(double e0,double e1,double e2):e{e0,e1,e2}{}
double Vec3d::x()const{return e[0];}
double Vec3d::y()const{return e[1];}
double Vec3d::z()const{return e[2];}
double &Vec3d::x(){return e[0];}
double &Vec3d::y(){return e[1];}
double &Vec3d::z(){return e[2];}
Vec3d Vec3d::operator-()const{return Vec3d(-e[0],-e[1],-e[2]);}
double Vec3d::operator[](int i)const{return e[i];}
double& Vec3d::operator[](int i){return e[i];}
Vec3d Vec3d::operator+(const Vec3d& v)const{return Vec3d(e[0]+v.e[0],e[1]+v.e[1],e[2]+v.e[2]);}
Vec3d Vec3d::operator-(const Vec3d& v)const{return Vec3d(e[0]-v.e[0],e[1]-v.e[1],e[2]-v.e[2]);}
Vec3d Vec3d::operator*(const double t)const{return Vec3d(e[0]*t,e[1]*t,e[2]*t);}
Vec3d Vec3d::operator/(const double t)const{return *this*(1./t);}
double Vec3d::operator*(const Vec3d& v)const{return e[0]*v.e[0]+e[1]*v.e[1]+e[2]*v.e[2];}
Vec3d Vec3d::operator^(const Vec3d& v)const{return Vec3d(e[1]*v.e[2]-e[2]*v.e[1],e[2]*v.e[0]-e[0]*v.e[2],e[0]*v.e[1]-e[1]*v.e[0]);}
Vec3d Vec3d::operator%(const Vec3d& v)const{return Vec3d(e[0]*v.e[0],e[1]*v.e[1],e[2]*v.e[2]);}
Vec3d& Vec3d::operator+=(const Vec3d& v){e[0]+=v.e[0];e[1]+=v.e[1];e[2]+=v.e[2];return *this;}
Vec3d& Vec3d::operator-=(const Vec3d& v){e[0]-=v.e[0];e[1]-=v.e[1];e[2]-=v.e[2];return *this;}
Vec3d& Vec3d::operator*=(const double t){e[0]*=t;e[1]*=t;e[2]*=t;return *this;}
Vec3d& Vec3d::operator/=(const double t){return *this*=(1./t);}
double Vec3d::lenSqr()const{return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];}
double Vec3d::lenRec()const{return sqrtRec(lenSqr());}
double Vec3d::len()const{double x=lenSqr();return x*sqrtRec(x);}
Vec3d Vec3d::norm()const{return *this*lenRec();}
void Vec3d::makeUnit(){*this*=lenRec();}
Vec3d Vec3d::randOct1(){return Vec3d(randd(),randd(),randd());}
Vec3d Vec3d::randUnit(){
  double x,y,z,l2;
  do{
    x=2.*randd()-1.;
    y=2.*randd()-1.;
    z=2.*randd()-1.;
    l2=x*x+y*y+z*z;
  }while(1e-160>l2||l2>1.);
  return Vec3d(x,y,z).norm();
}
Vec3d Vec3d::randHemi(const Vec3d& n){
  Vec3d v=randUnit();
  return v*n>0?v:-v;
}
Vec3d operator*(const double t,const Vec3d& v){return v*t;}
