#include<vector>
#include<fstream>
#include"lib/gif.h"
#include"base.h"
#include"tracer.h"
#include"sphere.h"
int main(){
  static const int w=480,h=367,esr=64;
  // static const int w=1280,h=720,esr=256;
  std::shared_ptr<Material> m1=std::make_shared<Lambertian>(Col(.8,.3,.3));
  std::shared_ptr<Material> m3=std::make_shared<Metal>(Col(.8,.8,.0),0.2);
  std::vector<Col> buf;
  std::vector<uint8_t> image(w*h*4);
  Tracer trc=Tracer()
    .setCam(
      Camera()
        .setDire(Point(0,0,1),Point(0,0,0),Vec3d(0,1,0))
        .setRes(w,h,esr)
        .setFov(d2r(60))
    );
  std::shared_ptr<Material> m2;

  GifWriter gifWriter;
  GifBegin(&gifWriter,"../../image/animation.gif",w,h,8);
  for(int i=0;i<36;i++){
    m2=std::make_shared<Nuclear>(1./12.*i);
    trc.setScn(Scene()
      .add(Sphere(Vec3d(-0.4,0,-1),0.5).setMat(m1))
      .add(Sphere(Vec3d(0.4,0.2,-1.4),0.7).setMat(m2))
      .add(Sphere(Vec3d(-0.4,-100.5,-1),100).setMat(m3))
    ).work(buf);
    for(int j=0;j<w*h;++j){
      image[j*4]  =static_cast<uint8_t>(buf[j].r()*255.);
      image[j*4+1]=static_cast<uint8_t>(buf[j].g()*255.);
      image[j*4+2]=static_cast<uint8_t>(buf[j].b()*255.);
      image[j*4+3]=255;
    }
    GifWriteFrame(&gifWriter,image.data(),w,h,8);
  }
  GifEnd(&gifWriter);
  return 0;
}
/*
int main(){
  static const int w=480,h=367,esr=16;
  // static const int w=1280,h=720,esr=256;
  std::shared_ptr<Material> m1=std::make_shared<Lambertian>(Col(.8,.3,.3));
  std::shared_ptr<Material> m2=std::make_shared<Nuclear>(1.8);
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
*/
