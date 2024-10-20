#ifndef __VEC3IO_H__
#define __VEC3IO_H__
#include<iostream>
#include"vec3.h"
std::istream& operator>>(std::istream& in,Vec3d& v);
std::ostream& operator<<(std::ostream& out,const Vec3d& v);
#endif
