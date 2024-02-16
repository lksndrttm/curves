#pragma once

#include "curve.h"

#include <vector>

namespace curves {

class Elipse : public Curve
{
private:
    double h_radius_;
    double v_radius_;
public:
    Elipse(double h_radius, double v_radius);
    std::vector<double> point(double t) const override;
    std::vector<double> derivative(double t) const override;
};


}