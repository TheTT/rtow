#ifndef __SCENE_HPP__
#define __SCENE_HPP__
#include<vector>
#include<memory>
#include"hittable.hpp"
class Scene{
 private:
  std::vector<std::shared_ptr<Hittable> > objs;
 public:
  inline void add(Hittable &&obj){
    objs.push_back(std::make_shared<Hittable>(std::move(obj)));
  }
  inline void add(const Hittable &obj){
    objs.push_back(std::make_shared<Hittable>(obj));
  }
  bool hit(const Ray &ray,double tmin,double tmax,Hitment &h)const{
    Hitment tmp;
    bool hit=false;
    double maxt=tmax;
    for(const auto &obj:objs)
      if(obj->hit(ray,tmin,maxt,tmp))
        hit=true,maxt=tmp.t,h=tmp;
    return hit;
  }
};
#endif
