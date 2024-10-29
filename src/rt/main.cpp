#include<vector>
#include<fstream>
// #include"lib/gif.h"
#include"base.h"
#include"tracer.h"
#include"sphere.h"
int main(){
  static const int w=480,h=367,esr=16;
  // static const int w=1280,h=720,esr=256;
  std::shared_ptr<Material> m1=std::make_shared<Lambertian>(Col(.8,.3,.3));
  std::shared_ptr<Material> m2=std::make_shared<Dielectric>(1.2);
  // std::shared_ptr<Material> m2=std::make_shared<Nuclear>(1.8);
  std::shared_ptr<Material> m3=std::make_shared<Metal>(Col(.8,.8,.0),0.2);
  std::ofstream ofs("../../image/demo.ppm");
  ofs << "P3\n" << w << ' ' << h << "\n255\n";
  std::vector<Col> buf;
  Tracer()
  .setCam(
    Camera()
    .setDire(Point(0,0,1),Point(0,0,0),Vec3d(0,1,0))
    .setRes(w,h,esr)
    .setFov(d2r(60))
  )
  .setScn(
    Scene()
    .add(Sphere(Vec3d(-0.4,0,-1),0.5).setMat(m1))
    .add(Sphere(Vec3d(0.4,0.2,-1.4),0.7).setMat(m2))
    .add(Sphere(Vec3d(-0.4,-100.5,-1),100).setMat(m3))
  )
  .work(buf);
  for(auto &c:buf)ofs << c << '\n';
  return 0;
}
