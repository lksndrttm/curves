#include "circle.h"
#include "exceptions.h"

#include <cmath>


namespace curves
{
    
Circle::Circle(double radius) : radius_(radius)
{
    if(radius <= 0){
        throw ValueError("Circle radius must be bigger than 0.");
    }
}

std::vector<double> Circle::point(double t) const
{
    double x = radius_ * std::cos(t);
    double y = radius_ * std::sin(t);
    return std::vector<double>{{x,y,0}};
}

std::vector<double> Circle::derivative(double t) const
{
    double x = -radius_ * std::sin(t);
    double y = radius_ * std::cos(t);
    return std::vector<double>{{x,y,0}};
}

}
