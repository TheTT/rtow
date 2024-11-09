#ifndef __CAMERA_H__
#define __CAMERA_H__
#include"base.h"
class Camera{
 private:
  Point at,tar,up;
  Point fvec,right;
  int iw,ih,spp;double flen,fov;
  double asr,vph,vpw;
  char done;
  void upd_vphw();
 public:
  Camera();
  const Point &getAt()const;
  const Point &getTar()const;
  const Vec3d &getUp()const;
  const Point &getFvec()const;
  const Point &getRight()const;
  int getIw()const;
  int getIh()const;
  int getSpp()const;
  Camera& setDire(const Point& at,const Point& tar,const Vec3d& up);
  Camera& setRes(int iw,int ih,int spp=1);
  Camera& setFov(double fov);
  bool ready()const;
  Ray getRayuv(double u,double v)const;
  Ray getRayxy(double x,double y)const;
  Ray getRayij(int i,int j)const;
};
#endif
