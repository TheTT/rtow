#ifndef __RDER_HPP__
#define __RDER_HPP__
#include<vector>
#include"color.hpp"
#include"camera.hpp"
bool hit_sphere(const Vec3d& center,double radius,const Ray& r){
  Vec3d oc=center-r.getOri();
  auto a=r.getDir()*r.getDir();
  auto b=-2.*r.getDir()*oc;
  auto c=oc*oc-radius*radius;
  auto Del=b*b-4*a*c;
  return (Del>=0);
}
class rder{
 private:
  Camera cam;
  Col trace(Ray r)const{
    if(hit_sphere(Vec3d(0,0,-1),1,r))
      return Col(0,.5,0);
    Vec3d ud=r.getDir().norm();
    double t=0.5*(ud.y()+1.);
    return Col(1,1,1)*(1-t)+Col(0.5,0.7,1)*t;
  }
 public:
  rder(){}
  rder& setCam(const Camera& cam){
    this->cam=cam;
    return *this;
  }
  void work(std::vector<Col> &buf)const{
    buf.clear();
    if(!cam.ready()){
      std::cerr<<"Camera not ready!"<<std::endl;
      return;
    }
    for(int y=0;y<cam.getIh();y++)
      for(int x=0;x<cam.getIw();x++)
        buf.push_back(trace(cam.getRay(x,y)));
  }
};
#endif
