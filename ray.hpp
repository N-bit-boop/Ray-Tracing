#ifndef RAY_H
#define RAY_H


#include "vec.hpp"

class ray{
    public:
        ray(){}

       ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction){}
    
       const point3 origin() const{return orig;} //Only chose a position
       const vec3 direction() const{return dir;} // A vector (direction as well )
       
       //line 
       point3 at(double t) const{
        return orig +t *dir;
       }

    private:
        point3 orig;
        vec3 dir;
};


#endif