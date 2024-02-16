#pragma once

#include "curve.h"
#include <vector>

namespace curves {

class Circle : public Curve
{
private:
    double radius_;
public:
    Circle(double radius);
    std::vector<double> point(double t) const override;
    std::vector<double> derivative(double t) const override;
    double radius() const {return radius_;}
};


}