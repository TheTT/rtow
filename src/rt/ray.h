#ifndef __RAY_H__
#define __RAY_H__
#include"vec3.h"
class Ray{
 private:
  Point o;
  Vec3d d;
 public:
  Ray();
  Ray(const Point& o,const Vec3d& d);
  const Point &getOri()const;
  const Vec3d &getDir()const;
  Point at(double t)const;
};
#endif
