#ifndef __RDER_HPP__
#define __RDER_HPP__
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
  void work()const{}
};
#endif
