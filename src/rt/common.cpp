#include"common.h"
double d2r(double degrees){
  static constexpr double r=pi/180.0;
  return degrees*r;
}
double l2g(double linear){
  return linear<=0?0:sqrt(linear);
}
double randd(){
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_real_distribution<double> dist(0.0,1.0);
  return dist(gen);
}
double randd(double min,double max){
  return min+randd()*(max-min);
}
