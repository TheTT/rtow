#include"vec3io.h"
std::istream& operator>>(std::istream& in,Vec3d& v){
  return in>>v.x()>>v.y()>>v.z();
}
std::ostream& operator<<(std::ostream& out,const Vec3d& v){
  return out<<v.x()<<' '<<v.y()<<' '<<v.z();
}
