#ifndef __VEC3IO_HPP__
#define __VEC3IO_HPP__
#include<iostream>
#include"vec3.hpp"
std::istream& operator>>(std::istream& in,Vec3d& v){
  return in>>v.x()>>v.y()>>v.z();
}
std::ostream& operator<<(std::ostream& out,const Vec3d& v){
  return out<<v.x()<<' '<<v.y()<<' '<<v.z();
}
#endif
