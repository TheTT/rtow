#include<vector>
#include<fstream>
#include<iostream>
#include"rder.hpp"
// typedef Col Shader(int x,int y);
int main(){
  static const int w=256,h=256;
  std::ofstream ofs("../../image/demo.ppm");
  ofs << "P3\n" << w << ' ' << h << "\n255\n";
  std::vector<Col> buf;
  rder().setCam(Camera().setDire(Point(0,0,1),Point(0,0,0),Vec3d(0,1,0)).setRes(w,h).setFov(90)).work(buf);
  for(auto &c:buf)ofs << c << '\n';
  return 0;
}
