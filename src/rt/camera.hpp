#ifndef __CAMERA_H__
#define __CAMERA_H__
#include"base.hpp"
class Camera{
 private:
  Point at,tar,up;
  Point fvec,right;
  int iw,ih;double fov;
  double asr,vph,vpw;
  char done;
 public:
  Camera():done(7){}
  inline const Point &getAt()const{return at;}
  inline const Point &getTar()const{return tar;}
  inline const Vec3d &getUp()const{return up;}
  inline const Point &getFvec()const{return fvec;}
  inline const Point &getRight()const{return right;}
  inline int getIw()const{return iw;}
  inline int getIh()const{return ih;}
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
  inline bool ready()const{return done==7;}
  inline Ray getRayuv(double u,double v)const{
    return Ray(at,(fvec+(right*(u-0.5)*vpw)+(up*(0.5-v)*vph)));
  }
  inline Ray getRayxy(double x,double y)const{
    return getRayuv(x/iw,y/ih);
  }
  inline Ray getRayij(int i,int j)const{
    return getRayuv((i+0.5)/iw,(j+0.5)/ih);
  }
};
#endif
