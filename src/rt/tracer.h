#ifndef __TRACER_H__
#define __TRACER_H__
#include<chrono>
#include<vector>
#include"base.h"
#include"scene.h"
#include"camera.h"
#include"interval.h"
// #include"material.h"
class Tracer{
 private:
  Camera cam;
  Scene scn;
  int maxd;
  // Col trace(Ray r)const;
  Col trace(const Ray& r,double ctn=1)const;
 public:
  Tracer();
  Tracer& setCam(const Camera& cam,const int maxd=64);
  Tracer& setScn(const Scene& scn);
  void work(std::vector<Col> &buf)const;
  void debug(double x,double y)const;
};
#endif
