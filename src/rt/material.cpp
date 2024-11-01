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
double Dielectric::reflratio(double c,double ri){
  auto r0=(1-ri)/(1+ri);r0=r0*r0;
  return r0+(1-r0)*std::pow((1-c),5);
}
Dielectric::Dielectric(double refri):refri(refri){}
bool Dielectric::backward(const Ray &rin,const Hitment &hit,Col &att,Ray &rout)const{
  att=Col(1.,1.,1.);
  double etaiOo=hit.f?refri:1./refri;
  Vec3d od=rin.getDir().norm(),n=hit.n.norm(),nd;
  auto sgn=[&](double x){return x>0?1:-1;};
  double ci=-od*n;
  double si=sqrt(1.-ci*ci);
  double so=si/etaiOo;
  double rr=reflratio(std::fabs(ci),etaiOo);
  // std::cout << "<rr=" << rr << ">" << std::endl;
  if(so>1.||rr>randd()){
    nd=od.reflect(n).norm();
    rout=Ray(hit.p,nd);
    return true;
  }
  double co=sqrt(1.-so*so)*sgn(ci);
  Vec3d uPara=(od+ci*n).norm();
  nd=(uPara*so-n*co).norm();
  rout=Ray(hit.p,nd);
  return true;
}
