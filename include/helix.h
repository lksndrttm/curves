#pragma once

#include "curve.h"
#include <vector>

namespace curves {

class Helix : public Curve
{
private:
    double radius_;
    double step_;
public:
    Helix(double radius, double step);
    std::vector<double> point(double t) const override;
    std::vector<double> derivative(double t) const override;
};


}