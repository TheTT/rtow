#ifndef __VEC3IO_HPP__
#define __VEC3IO_HPP__
#include<iostream>
#include"vec3.hpp"
std::istream& operator>>(std::istream& in,vec3d& v){
  return in>>v.e[0]>>v.e[1]>>v.e[2];
}
std::ostream& operator<<(std::ostream& out,const vec3d& v){
  return out<<v.e[0]<<' '<<v.e[1]<<' '<<v.e[2];
}
#endif