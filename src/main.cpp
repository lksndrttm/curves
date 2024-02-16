#include "curves.h"

#include <iostream>
#include <cmath>
#include <numbers>
#include <memory>
#include <random>
#include <vector>
#include <algorithm>

#include <omp.h>

std::shared_ptr<curves::Curve> create_rand_circle()
{
    std::random_device dev;
    std::mt19937 gen{dev()};
    auto r_dis = std::uniform_real_distribution<double>(0.01, 100);
    return std::make_shared<curves::Circle>(r_dis(gen));
}

std::shared_ptr<curves::Curve> create_rand_elipse()
{
    std::random_device dev;
    std::mt19937 gen{dev()};
    auto r_dis = std::uniform_real_distribution<double>(0.01, 100);
    return std::make_shared<curves::Elipse>(r_dis(gen), r_dis(gen));
}

std::shared_ptr<curves::Curve> create_rand_helix()
{
    std::random_device dev;
    std::mt19937 gen{dev()};
    auto r_dis = std::uniform_real_distribution<double>(0.01, 100);
    return std::make_shared<curves::Helix>(r_dis(gen), r_dis(gen));
}

std::shared_ptr<curves::Curve> create_rand_curve()
{
    std::random_device dev;
    std::mt19937 gen{dev()};
    auto c_dis = std::uniform_int_distribution(0, 2);
    int curve_num = c_dis(gen);
    
    switch (curve_num)
    {
    case 0:
        return create_rand_circle();
    case 1:
        return create_rand_elipse();
    case 2:
        return create_rand_helix();
    }

    throw;
}

double rad_sum(const std::vector<std::shared_ptr<curves::Curve>>& circles)
{
    double sum = 0;
    
    #pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < circles.size(); i++)
    {
        sum += std::dynamic_pointer_cast<curves::Circle>(circles[i])->radius();
    }

    return sum;
    
}

int main ()
{
    std::vector<std::shared_ptr<curves::Curve>> rand_curves;
    std::vector<std::shared_ptr<curves::Curve>> circles;
    
    for (size_t i = 0; i < 100; i++)
    {
        rand_curves.push_back(create_rand_curve());
        
        auto point = rand_curves.back()->point(std::numbers::pi / 4);
        auto d = rand_curves.back()->derivative(std::numbers::pi / 4);
        
        std::cout << "Point: (" <<  point[0] << ", " << point[1] << ", " << point[2] << ")  ";
        std::cout << "Derivative: (" <<  d[0] << ", " << d[1] << ", " << d[2] << ")\n";
        
        if( typeid( *(rand_curves.back()) ) == typeid(curves::Circle) )
        {
            circles.push_back(rand_curves.back());
        }
    }

    std::sort(circles.begin(),circles.end(), [](const auto& a, const auto& b){
        return std::dynamic_pointer_cast<curves::Circle>(a)->radius() < std::dynamic_pointer_cast<curves::Circle>(b)->radius();
    });
    

    double r_sum = rad_sum(circles);

    return 0;
}