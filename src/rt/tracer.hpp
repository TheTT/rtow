#ifndef __TRACER_HPP__
#define __TRACER_HPP__
#include<chrono>
#include<vector>
#include"base.hpp"
#include"scene.hpp"
#include"camera.hpp"
#include"interval.hpp"
class Tracer{
 private:
  Camera cam;
  Scene scn;
  int maxd;
  /*
  Col trace(Ray r)const{
    Hitment hit;
    if(scn.hit(r,Interval(0,inf),hit))
      return Col(.5*(hit.n+Vec3d(1,1,1)));
    Vec3d ud=r.getDir().norm();
    double d=.5*(ud.y()+1.);
    return Col(1,1,1)*(1-d)+Col(.5,.7,1)*d;
  }
  */
  Col trace(const Ray& r,double drn=0)const{
    const double dpl=1./maxd;
    Hitment hit;
    if(scn.hit(r,Interval(1e-6,inf),hit)){
      if(randd()<drn)return Col(0,0,0);
      Vec3d nd=hit.n+Vec3d::randUnit();
      return .5*trace(Ray(hit.p,nd),drn+dpl)/(1-drn);
    }
    Vec3d ud=r.getDir().norm();
    auto a=.5*(ud.y()+1.);
    return (1.-a)*Col(1.,1.,1.)+a*Col(.5,.7,1.);
  }
 public:
  Tracer(){}
  Tracer& setCam(const Camera& cam,const int maxd=16){
    this->cam=cam;
    this->maxd=maxd;
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
    auto start=std::chrono::high_resolution_clock::now();
    for(int y=0;y<cam.getIh();y++){
      std::clog << "\rRendering progress: " << 100.*y/cam.getIh() << "%        " << std::flush;
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
    std::clog << "\rRendering progress: 100%        ";
    auto end=std::chrono::high_resolution_clock::now();
    std::clog << "\nDone in " << std::chrono::duration<double>(end-start).count() << "s" << std::endl;
  }
};
#endif
