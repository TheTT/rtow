#ifndef __TRACER_HPP__
#define __TRACER_HPP__
#include<vector>
#include"base.hpp"
#include"scene.hpp"
#include"camera.hpp"
#include"interval.hpp"
class Tracer{
 private:
  Camera cam;
  Scene scn;
  Col trace(Ray r)const{
    Hitment hit;
    if(scn.hit(r,Interval(0,inf),hit))
      return Col(0.5*(hit.n+Vec3d(1,1,1)));
    Vec3d ud=r.getDir().norm();
    double d=0.5*(ud.y()+1.);
    return Col(1,1,1)*(1-d)+Col(0.5,0.7,1)*d;
  }
 public:
  Tracer(){}
  Tracer& setCam(const Camera& cam){
    this->cam=cam;
    return *this;
  }
  Tracer& setScn(const Scene& scn){
    this->scn=scn;
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
        if(cam.getSpp()==1)
          buf.push_back(trace(cam.getRayij(x,y)));
        else{
          Col c;
          for(int i=0;i<cam.getSpp();i++)
            c+=trace(cam.getRayxy(x-.5+randd(),y-.5+randd()));
          buf.push_back(c/cam.getSpp());
        }
  }
};
#endif
