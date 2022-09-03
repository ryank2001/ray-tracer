#include "color.h"
#include "vec3.h"
#include "ray.h"
#include <iostream>

color raycolor(const ray& r){
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main(){
    double image_ratio = 16.0 /9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / image_ratio);

    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * image_ratio;
    auto focal_length = 1.0;

    point3 origin = point3(0,0,0);
    auto horizontal = point3(viewport_width,0,0);
    auto vertical = point3(0,viewport_height,0);
    point3 lower_left_corner = origin - horizontal/2 - vertical/2 - point3(0,0,focal_length);




    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = image_height; j >= 0 ; --j){
    std::cerr << "\nlines remaining: " << j << " " << std::flush; 
        for (int i = 0; i < image_width; i++)
        {
            auto v = double(j) / (image_height-1);
            auto h = double(i) / (image_width -1);

            ray r(origin, lower_left_corner + h*horizontal + v*vertical - origin);
            color pixel_color = raycolor(r);
            write_color(std::cout, pixel_color);
        }
        
    }
    std::cerr << "\nfininshed printing!!\n";
    
}
