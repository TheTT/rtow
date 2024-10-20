#include"scene.h"
Scene::Scene(){}
Scene &Scene::add(std::shared_ptr<Hittable> obj){
  objs.push_back(obj);
  return *this;
}
Scene &Scene::add(const Hittable &obj){
  objs.push_back(obj.clone());
  return *this;
}
bool Scene::hit(const Ray &ray,Interval rg,Hitment &h)const{
  Hitment tmp;
  bool hit=false;
  double maxt=rg.r;
  for(const auto &obj:objs)
    if(obj->hit(ray,Interval(rg.l,maxt),tmp))
      hit=true,maxt=tmp.t,h=tmp;
  return hit;
}
