#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__
#include"base.hpp"
#include"hittable.hpp"
class Material{
 public:
  virtual ~Material()=default;
  virtual bool scatter(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const=0;
};
#endif
