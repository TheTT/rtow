#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__
class Material{
 public:
  virtual ~Material()=default;
  virtual bool backward(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const{return false;}
};
class Lambertian:public Material{
 private:
  Col albedo;
 public:
  Lambertian(const Col& albedo):albedo(albedo){}
  virtual bool backward(const Ray& rin,const Hitment& hit,Col& att,Ray& rout)const override{
    Vec3d nd=hit.n+Vec3d::randUnit();
    att=albedo;
    rout=Ray(hit.p,nd);
    return true;
  }
};
#endif
