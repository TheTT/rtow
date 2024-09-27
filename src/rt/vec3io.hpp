#ifndef __VEC3IO_HPP__
#define __VEC3IO_HPP__
#include<iostream>
#include"vec3.hpp"
std::istream& operator>>(std::istream& in,vec3d& v){
  return in>>v.x()>>v.y()>>v.z();
}
std::ostream& operator<<(std::ostream& out,const vec3d& v){
  return out<<v.x()<<' '<<v.y()<<' '<<v.z();
}
#endif
