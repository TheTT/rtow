#ifndef __SCENE_H__
#define __SCENE_H__
#include<vector>
#include"base.h"
#include"hittable.h"
#include"interval.h"
class Scene{
 private:
  std::vector<std::shared_ptr<Hittable> > objs;
 public:
  Scene();
  Scene &add(std::shared_ptr<Hittable> obj);
  Scene &add(const Hittable &obj);
  bool hit(const Ray &ray,Interval rg,Hitment &h)const;
};
#endif
