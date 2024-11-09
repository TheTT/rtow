#include"camera.h"
void Camera::upd_vphw(){
  vph=2*flen*tan(fov/2);
  vpw=vph*asr;
}
Camera::Camera():done(7){}
const Point &Camera::getAt()const{return at;}
const Point &Camera::getTar()const{return tar;}
const Vec3d &Camera::getUp()const{return up;}
const Point &Camera::getFvec()const{return fvec;}
const Point &Camera::getRight()const{return right;}
int Camera::getIw()const{return iw;}
int Camera::getIh()const{return ih;}
int Camera::getSpp()const{return spp;}
Camera& Camera::setDire(const Point& at,const Point& tar,const Vec3d& up){
  this->at=at;
  this->tar=tar;
  fvec=tar-at;
  flen=fvec.len();
  right=(fvec^up).norm();
  this->up=(right^fvec).norm();
  done|=1;
  return *this;
}
Camera& Camera::setRes(int iw,int ih,int spp){
  this->iw=iw;
  this->ih=ih;
  this->spp=spp;
  asr=double(iw)/ih;
  done|=2;
  if(done&4)upd_vphw();
  return *this;
}
Camera& Camera::setFov(double fov){
  this->fov=fov;
  done|=4;
  if(done&2)upd_vphw();
  return *this;
}
bool Camera::ready()const{return done==7;}
Ray Camera::getRayuv(double u,double v)const{
  auto pix=at-right*(u-0.5)*vpw-up*(0.5-v)*vph;
  return Ray(tar,tar-pix);
}
Ray Camera::getRayxy(double x,double y)const{
  return getRayuv(x/iw,y/ih);
}
Ray Camera::getRayij(int i,int j)const{
  return getRayuv((i+0.5)/iw,(j+0.5)/ih);
}
