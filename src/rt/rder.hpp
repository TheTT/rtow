#ifndef __RDER_HPP__
#define __RDER_HPP__
#include<vector>
#include"color.hpp"
#include"camera.hpp"
class rder{
 private:
  Camera cam;
  Col trace(Ray r)const{
    return Col();
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
