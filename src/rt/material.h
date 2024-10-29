#ifndef __MATERIAL_H__
#define __MATERIAL_H__
class Material;
class Lambertian;
class Nuclear;
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
class Metal:public Material{
 private:
  Col albedo;
  double fuzz;
 public:
  Metal(const Col& albedo,double fuzz=0.);
  virtual bool backward(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const override;
};
class Nuclear:public Material{
 private:
  double density;
 public:
  Nuclear(double density=1.);
  virtual bool backward(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const override;
};
class Dielectric:public Material{
 private:
  double refri;
 public:
  Dielectric(double refri=1.);
  virtual bool backward(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const override;
};
#endif
