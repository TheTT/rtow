#ifndef __CAMERA_H__
#define __CAMERA_H__
#include<cmath>
#include"ray.hpp"
class camera{
 private:
  point at,tar,up;
  point fvec,right;
  int iw,ih;double fov;
  double asr,vph,vpw;
  char done;
 public:
  camera():done(7){}
  const point &getAt()const{return at;}
  const point &getTar()const{return tar;}
  const vec3d &getUp()const{return up;}
  const point &getFvec()const{return fvec;}
  const point &getRight()const{return right;}
  camera& setDire(const point& at,const point& tar,const vec3d& up){
    this->at=at;
    this->tar=tar;
    this->up=up.norm();
    fvec=tar-at;
    right=(up^fvec).norm();
    done|=1;
    return *this;
  }
  camera& setRes(int iw,int ih){
    this->iw=iw;
    this->ih=ih;
    asr=double(iw)/ih;
    done|=2;
    if(done&4){
      vph=2*tan(fov/2);
      vpw=vph*asr;
    }
    return *this;
  }
  camera& setFov(double fov){
    this->fov=fov;
    done|=4;
    if(done&2){
      vph=2*tan(fov/2);
      vpw=vph*asr;
    }
    return *this;
  }
  bool ready()const{return done==7;}
};
#endif
