#include "helix.h"
#include "exceptions.h"

#include <cmath>
#include <numbers>

namespace curves
{

Helix::Helix(double radius, double step) : radius_(radius), step_(step)
{
    if(radius <= 0){
        throw ValueError("Helix radius must be bigger than 0.");
    }
    if(step <= 0){
        throw ValueError("Helix step must be bigger than 0.");
    }
}

std::vector<double> Helix::point(double t) const
{
    double x = radius_ * std::cos(t);
    double y = radius_ * std::sin(t);
    double z = t/(2 * std::numbers::pi) * step_;
    return std::vector<double>{{x,y,z}};
}

std::vector<double> Helix::derivative(double t) const
{
    double x = -radius_ * std::sin(t);
    double y = radius_ * std::cos(t);
    double z = 1/(2 * std::numbers::pi) * step_;
    return std::vector<double>{{x,y,z}};
}

}
