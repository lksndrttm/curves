#include "elipse.h"
#include "exceptions.h"

#include <cmath>

namespace curves
{

Elipse::Elipse(double h_radius, double v_radius): h_radius_(h_radius), v_radius_(v_radius)
{
    if(h_radius <= 0 || v_radius <= 0){
        throw ValueError("Elipse radiuses must be bigger than 0.");
    }
}

std::vector<double> Elipse::point(double t) const
{
    double x = h_radius_ * std::cos(t);
    double y = v_radius_ * std::sin(t);
    return std::vector<double>{{x,y,0}};
}

std::vector<double> Elipse::derivative(double t) const
{
    double x = -h_radius_ * std::sin(t);
    double y = v_radius_ * std::cos(t);
    return std::vector<double>{{x,y,0}};
}
}
