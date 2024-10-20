#include"interval.h"
Interval::Interval():l(inf),r(-inf){}
Interval::Interval(double l,double r):l(l),r(r){}
double Interval::size()const{return r-l;}
bool Interval::empty()const{return r<l;}
bool Interval::contains(double x)const{return l<=x&&x<=r;}
bool Interval::contains(const Interval &i)const{return i.empty()||(l<=i.l&&i.r<=r);}
bool Interval::surround(double x)const{return l<x&&x<r;}
double Interval::clamp(double x)const{return std::max(l,std::min(r,x));}
