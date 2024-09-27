#include<vector>
#include<fstream>
#include<iostream>
struct Colf{
  Colf():r(0),g(0),b(0){}
  Colf(float r,float g,float b):r(r),g(g),b(b){}
  float r,g,b;
};
std::ostream &operator<<(std::ostream &os,const Colf &c){
  return os << static_cast<int>(255.999*c.r) << ' ' << static_cast<int>(255.999*c.g) << ' ' << static_cast<int>(255.999*c.b);
}
typedef Colf Shader(int x,int y);
void render(int h,int w,Shader *shader,std::vector<Colf> &buf){
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
  std::vector<Colf> buf;
  render(h,w,[](int i,int j){return Colf(i/float(w),j/float(h),0.);},buf);
  for(auto &c:buf)ofs << c << '\n';
  return 0;
}
