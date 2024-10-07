#ifndef __SCENE_HPP__
#define __SCENE_HPP__
#include<vector>
#include"base.hpp"
#include"hittable.hpp"
#include"interval.hpp"
template<typename _Tp>
concept DerivedFromHittable=std::is_base_of_v<Hittable,_Tp>;
class Scene{
 private:
  std::vector<std::shared_ptr<Hittable> > objs;
 public:
  Scene(){}
  inline Scene &add(std::shared_ptr<Hittable> obj){
    objs.push_back(obj);
    return *this;
  }
  template<DerivedFromHittable _Tp>
  inline Scene &add(_Tp &&obj){
    objs.push_back(std::make_shared<_Tp>(std::move(obj)));
    return *this;
  }
  template<DerivedFromHittable _Tp>
  inline Scene &add(const _Tp &obj){
    objs.push_back(std::make_shared<_Tp>(obj));
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
