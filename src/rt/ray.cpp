#include"ray.h"
Ray::Ray():o(),d(){}
Ray::Ray(const Point& o,const Vec3d& d):o(o),d(d){}
const Point &Ray::getOri()const{return o;}
const Vec3d &Ray::getDir()const{return d;}
Point Ray::at(double t)const{return o+d*t;}
