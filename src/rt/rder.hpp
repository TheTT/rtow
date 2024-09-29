#ifndef __RDER_HPP__
#define __RDER_HPP__
#include"color.hpp"
#include"camera.hpp"
class rder{
 private:
  Camera cam;
  Col trace(Ray r)const{
    return Col();
  }
 public:
  rder(){}
  Col trace(Camera cam,double vpu,double vpv)const{
    Point o=cam.getAt();
    Vec3d d=cam.getFvec()+cam.getRight()*vpu-cam.getUp()*vpv;
    return trace(Ray(o,d));
  }
  void work()const{}
};
#endif
