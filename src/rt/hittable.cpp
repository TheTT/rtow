#include"hittable.h"
Hitment::Hitment():p(),n(),m(),t(inf),f(false){}
Hittable::Hittable():m(){}
Hittable &Hittable::setMat(const std::shared_ptr<Material> &m){this->m=m;return *this;}
