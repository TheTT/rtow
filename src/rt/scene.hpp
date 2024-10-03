#ifndef __SCENE_HPP__
#define __SCENE_HPP__
#include<vector>
#include<memory>
#include"hittable.hpp"
class Scene{
 private:
  std::vector<std::shared_ptr<Hittable> > objs;
 public:
  Scene(){}
  inline Scene &add(std::shared_ptr<Hittable> obj){
    objs.push_back(obj);
    return *this;
  }
  // inline Scene &add(Hittable &&obj){
  //   objs.push_back(std::make_shared<Hittable>(std::move(obj)));
  //   return *this;
  // }
  // inline Scene &add(const Hittable &obj){
  //   objs.push_back(std::make_shared<Hittable>(obj));
  //   return *this;
  // }
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
