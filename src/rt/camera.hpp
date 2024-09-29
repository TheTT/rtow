#ifndef __CAMERA_H__
#define __CAMERA_H__
#include<cmath>
#include"ray.hpp"
class Camera{
 private:
  Point at,tar,up;
  Point fvec,right;
  int iw,ih;double fov;
  double asr,vph,vpw;
  char done;
 public:
  Camera():done(7){}
  const Point &getAt()const{return at;}
  const Point &getTar()const{return tar;}
  const Vec3d &getUp()const{return up;}
  const Point &getFvec()const{return fvec;}
  const Point &getRight()const{return right;}
  Camera& setDire(const Point& at,const Point& tar,const Vec3d& up){
    this->at=at;
    this->tar=tar;
    this->up=up.norm();
    fvec=tar-at;
    right=(up^fvec).norm();
    done|=1;
    return *this;
  }
  Camera& setRes(int iw,int ih){
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
  Camera& setFov(double fov){
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
