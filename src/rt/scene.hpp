#ifndef __SCENE_HPP__
#define __SCENE_HPP__
#include<vector>
#include"base.hpp"
#include"hittable.hpp"
#include"interval.hpp"
class Scene{
 private:
  std::vector<std::shared_ptr<Hittable> > objs;
 public:
  Scene(){}
  inline Scene &add(std::shared_ptr<Hittable> obj){
    objs.push_back(obj);
    return *this;
  }
  inline Scene &add(const Hittable &obj){
    objs.push_back(obj.clone());
    return *this;
  }
  bool hit(const Ray &ray,Interval rg,Hitment &h)const{
    Hitment tmp;
    bool hit=false;
    double maxt=rg.r;
    for(const auto &obj:objs)
      if(obj->hit(ray,Interval(rg.l,maxt),tmp))
        hit=true,maxt=tmp.t,h=tmp;
    return hit;
  }
};
#endif
