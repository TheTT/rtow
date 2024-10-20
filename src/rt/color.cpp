#include"color.h"
Col::Col():Vec3d(){}
Col::Col(const Vec3d &v):Vec3d(v){}
Col::Col(double r,double g,double b):Vec3d(r,g,b){}
double Col::r()const{return x();}
double Col::g()const{return y();}
double Col::b()const{return z();}
double &Col::r(){return x();}
double &Col::g(){return y();}
double &Col::b(){return z();}
std::ostream& operator<<(std::ostream& out,const Col& c){
  static const Interval r(0,0.999);
  return out<<int(256*r.clamp(l2g(c.r())))<<' '<<int(256*r.clamp(l2g(c.g())))<<' '<<int(256*r.clamp(l2g(c.b())));
}
