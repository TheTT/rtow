#include<vector>
#include<fstream>
#include<iostream>
#include"color.hpp"
typedef Col Shader(int x,int y);
void render(int h,int w,Shader *shader,std::vector<Col> &buf){
  for(int j=0;j<h;j++){
    std::clog << "\rRendering progress: " << double(j)/h << "%        " << std::flush;
    for(int i=0;i<w;i++)
      buf.push_back(shader(i,j));
  }
  std::clog << "\rRendering progress: 100%        ";
  std::clog << "\nDone." << std::endl;
}
int main(){
  static const int w=256,h=256;
  std::ofstream ofs("../../image/demo.ppm");
  ofs << "P3\n" << w << ' ' << h << "\n255\n";
  std::vector<Col> buf;
  render(h,w,[](int i,int j){return Col(i/float(w),j/float(h),0.);},buf);
  for(auto &c:buf)ofs << c << '\n';
  return 0;
}
