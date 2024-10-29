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
Dielectric::Dielectric(double refri):refri(refri){}
bool Dielectric::backward(const Ray &rin,const Hitment &hit,Col &att,Ray &rout)const{
  att=Col(1.,1.,1.);
  double etaiOo=hit.f?refri:1./refri;
  // double etaiOo=refri;
  Vec3d od=rin.getDir().norm();
  auto sgn=[&](double x){return x>0?1:-1;};
  double ci=-od*hit.n;
  double si=sqrt(1.-ci*ci);
  double so=si/etaiOo;
  if(so>1.){
    Vec3d nd=od.reflect(hit.n);
    rout=Ray(hit.p,nd);
    return true;
  }
  double co=sqrt(1.-so*so)*sgn(ci);
  Vec3d uPara=od-ci*hit.n;
  Vec3d nd=uPara*so-hit.n*co;
  rout=Ray(hit.p,nd);
  // std::cerr << "<" << si << ',' << so << ">";
  return true;
}
