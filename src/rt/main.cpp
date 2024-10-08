#include<vector>
#include<fstream>
#include"base.hpp"
#include"tracer.hpp"
#include"sphere.hpp"
// typedef Col Shader(int x,int y);
int main(){
  static const int w=256,h=256;
  std::ofstream ofs("../../image/demo.ppm");
  ofs << "P3\n" << w << ' ' << h << "\n255\n";
  std::vector<Col> buf;
  Tracer()
  .setCam(
    Camera()
    .setDire(Point(0,0,1),Point(0,0,0),Vec3d(0,1,0))
    .setRes(w,h)
    .setFov(90)
  )
  .setScn(
    Scene()
    .add(Sphere(Vec3d(0,0,-1),1))
    .add(Sphere(Vec3d(0,-100.5,-1),100))
  )
  .work(buf);
  for(auto &c:buf)ofs << c << '\n';
  return 0;
}
