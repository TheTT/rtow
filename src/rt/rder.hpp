#ifndef __RDER_HPP__
#define __RDER_HPP__
#include<vector>
#include"color.hpp"
#include"camera.hpp"
bool hit_sphere(const Vec3d& center,const double radius,const Ray& r,double &t){
  Vec3d oc=center-r.getOri();
  const Vec3d &rd=r.getDir();
  double a=rd.lenSqr();
  double h=rd*oc;
  double c=oc.lenSqr()-radius*radius;
  double delD4=h*h-a*c;
  if(delD4<0)return false;
  t=(h-sqrt(delD4))/a;
  return true;
}
class rder{
 private:
  Camera cam;
  Col trace(Ray r)const{
    double t=NAN;
    if(hit_sphere(Vec3d(0,0,-1),1,r,t)&&t>0){
      Vec3d N=(r.at(t)-Vec3d(0,0,-1)).norm();
      return Col(0.5*(N.x()+1),0.5*(N.y()+1),0.5*(N.z()+1));
    }
    Vec3d ud=r.getDir().norm();
    double d=0.5*(ud.y()+1.);
    return Col(1,1,1)*(1-d)+Col(0.5,0.7,1)*d;
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
