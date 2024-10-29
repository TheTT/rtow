#include"../vec3.h"
#include"../vec3io.h"
bool refract(const Vec3d &od,const Vec3d &n,double etaiOo,Vec3d &nd){
  auto sgn=[&](double x){return x>0?1:-1;};
  double ci=-od*n;
  double si=sqrt(1.-ci*ci);
  double so=si/etaiOo;
  if(so>1.){
    nd=od.reflect(n).norm();
    return false;
  }
  double co=sqrt(1.-so*so)*sgn(ci);
  Vec3d uPara=(od+ci*n).norm();
  std::cout << uPara*n << "==0" << std::endl;
  nd=(uPara*so-n*co).norm();
  std::cout << "<" << si << ',' << so << ">" << std::endl;
  return true;
}
int main(){
  Vec3d od,n=Vec3d(1,1,1).norm(),nd;
  double etaiOo=1.;
  for(int i=0;i<12;i++){
    od=Vec3d(cos(i/6.5*pi),sin(i/6.5*pi),0).norm();
    if(refract(od,n,etaiOo,nd))
      std::cout << od << " -> Refract: " << nd << std::endl;
    else std::cout << od << " -> TotRefl: " << od << std::endl;
    double ci=od*n,si=sqrt(1.-ci*ci);
    double co=nd*n,so=sqrt(1.-co*co);
    std::cout << si << " -> " << so << std::endl;
    std::cout << "---------------------------" << std::endl;
  }
  return 0;
}
