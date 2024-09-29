#ifndef __RDER_HPP__
#define __RDER_HPP__
#include"color.hpp"
#include"camera.hpp"
class rder{
 private:
  camera cam;
  Col trace(ray r)const{
    return Col();
  }
 public:
  rder(){}
  Col trace(camera cam,double vpu,double vpv)const{
    point o=cam.getAt();
    vec3d d=cam.getFvec()+cam.getRight()*vpu-cam.getUp()*vpv;
    return trace(ray(o,d));
  }
  void work()const{}
};
#endif
