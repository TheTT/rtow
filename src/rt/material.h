#ifndef __MATERIAL_H__
#define __MATERIAL_H__
class Material;
class Lambertian;
#include"hittable.h"
class Material{
 public:
  virtual ~Material();
  virtual bool backward(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const;
};
class Lambertian:public Material{
 private:
  Col albedo;
 public:
  Lambertian(const Col& albedo);
  virtual bool backward(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const override;
};
#endif
