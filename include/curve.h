#pragma once
#include <vector>

namespace curves
{

class Curve
{
public:
    virtual std::vector<double> point( double t ) const = 0;
    virtual std::vector<double> derivative( double t ) const = 0;
    virtual ~Curve(){}
};


}
