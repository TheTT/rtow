#include"tracer.h"
/*
Col Tracer::trace(Ray r)const{
  Hitment hit;
  if(scn.hit(r,Interval(0,inf),hit))
    return Col(.5*(hit.n+Vec3d(1,1,1)));
  Vec3d ud=r.getDir().norm();
  double d=.5*(ud.y()+1.);
  return Col(1,1,1)*(1-d)+Col(.5,.7,1)*d;
}
*/
Col Tracer::trace(const Ray& r,double ctn)const{
  const double dpl=1./maxd+1e-6;
  Hitment hit;
  Col res;
  // std::cout << "\t->((" << r.getOri().x() << ',' << r.getOri().y() << ',' << r.getOri().z() << "), (" << r.getDir().x() << ',' << r.getDir().y() << ',' << r.getDir().z() << "))\n";
  if(scn.hit(r,Interval(1e-6,inf),hit)){
    if(randd()>ctn)return Col(0,0,0);
    Col att;Ray nxt;
    if(hit.m->backward(r,hit,att,nxt)){
      res=att%trace(nxt,ctn-dpl)/ctn;
      // std::cout << "\tcol\t(" << res.r() << ',' << res.g() << ',' << res.b() << ")\n";
      return res;
    }
  }
  Vec3d ud=r.getDir().norm();
  auto a=.5*(ud.y()+1.);
  res=(1.-a)*Col(1.,1.,1.)+a*Col(.5,.7,1.);
  // std::cout << "\tori\t(" << res.r() << ',' << res.g() << ',' << res.b() << ")\n";
  return res;
}
Tracer::Tracer(){}
Tracer& Tracer::setCam(const Camera& cam,const int maxd){
  this->cam=cam;
  this->maxd=maxd;
  return *this;
}
Tracer& Tracer::setScn(const Scene& scn){
  this->scn=scn;
  return *this;
}
void Tracer::work(std::vector<Col> &buf)const{
  buf.clear();
  if(!cam.ready()){
    std::cerr<<"Camera not ready!"<<std::endl;
    return;
  }
  auto start=std::chrono::high_resolution_clock::now();
  for(int y=0;y<cam.getIh();y++){
    std::clog << "\rRendering progress: " << 100.*y/cam.getIh() << "%        " << std::flush;
    for(int x=0;x<cam.getIw();x++)
      if(cam.getSpp()==1)
        buf.push_back(trace(cam.getRayij(x,y)));
      else{
        Col c;
        for(int i=0;i<cam.getSpp();i++)
          c+=trace(cam.getRayxy(x-.5+randd(),y-.5+randd()));
        buf.push_back(c/cam.getSpp());
      }
  }
  std::clog << "\rRendering progress: 100%        ";
  auto end=std::chrono::high_resolution_clock::now();
  std::clog << "\nDone in " << std::chrono::duration<double>(end-start).count() << "s" << std::endl;
}
void Tracer::debug(double x,double y)const{
  if(!cam.ready()){
    std::cerr<<"Camera not ready!"<<std::endl;
    return;
  }
  auto start=std::chrono::high_resolution_clock::now();
  Col c,sp;Ray r;
  for(int i=0;i<cam.getSpp();i++){
    r=cam.getRayxy(x-.5+randd(),y-.5+randd());
    c+=sp=trace(Ray(r.getOri(),r.getDir().norm()));
    // std::cout << i << ": " << sp.r() << ' ' << sp.g() << ' ' << sp.b() << std::endl;
  }
  c/=cam.getSpp();
  // std::cout << "Res: " << c.r() << ' ' << c.g() << ' ' << c.b() << std::endl;
  auto end=std::chrono::high_resolution_clock::now();
  std::clog << "\nDone in " << std::chrono::duration<double>(end-start).count() << "s" << std::endl;
}
