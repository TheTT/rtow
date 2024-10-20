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
