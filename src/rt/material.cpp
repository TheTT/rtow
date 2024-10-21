#include"material.h"
Material::~Material()=default;
bool Material::backward(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const{return false;}
Lambertian::Lambertian(const Col& albedo):albedo(albedo){}
bool Lambertian::backward(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const{
  Vec3d nd=hit.n+Vec3d::randUnit();
  att=albedo;
  if(nd.nearZero())nd=hit.n;
  rout=Ray(hit.p,nd);
  return true;
}

Metal::Metal(const Col &albedo,double fuzz):albedo(albedo),fuzz(fuzz){}
bool Metal::backward(const Ray &rin,const Hitment &hit,Col &att,Ray &rout)const{
  Vec3d nd=rin.getDir().reflect(hit.n);
  if(fabs(fuzz)>1e-6)nd+=fuzz*Vec3d::randUnit();
  bool flag=nd*hit.n>0;att=albedo;
  if(flag)rout=Ray(hit.p,nd);
  return flag;
}
