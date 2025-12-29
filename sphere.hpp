#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hpp"
#include "rtweekend.hpp"


class sphere : public hittable{
    public:
        sphere(const point3& center, double radius, shared_ptr<material> mat) : center(center), radius(std::fmax(0,radius)), mat(mat){
            
        }


        bool hit(const ray& r, interval ray_t, hit_record& rec) const override{
            vec3 oc  = center - r.origin(); // C - P
            auto a = r.direction().length_squared();
            auto h = dot(r.direction(),oc);
            auto c =  oc.length_squared() - radius*radius;
            auto discriminant = h*h -a*c;

            if(discriminant < 0){
                return false;
            }
            auto sqrd = std::sqrt(discriminant);

            //Find the nearest root in min < t < max 
            auto root =  (h - sqrd) / a;
            if(!ray_t.surrounds(root)){
                root  =  (h + sqrd) / a;
                if(!ray_t.surrounds(root)){
                    return false;
                }
            }

            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center ) / radius; //Divided for the uniot lenght
            rec.set_face_normal(r, outward_normal);
            rec.mat = mat;

            return true;

        }

    private:
    point3 center;
    double radius;
    shared_ptr<material> mat;
};


#endif