#include <iostream>
#define _USE_MATH_DEFINES 
#include <cmath>



class Sphere
{
    public:
        double radius;
    public:
        Sphere(double r)
        {
            this->radius = r;
        }

        double get_surface_area()
        {
            return 4 * M_PI * pow(this->radius, 2);
        }

        double get_volume()
        {
            return ((4 * M_PI * pow(this->radius, 3))/3);
        }
};

int main()
{
    Sphere s(5);
    std::cout << s.get_surface_area() << std::endl;
    std::cout << s.get_volume() << std::endl;
    return 0;
}