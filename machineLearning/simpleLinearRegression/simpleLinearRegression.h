#pragma once

#include <iostream>
#include <vector>

class SimpleLinearRegression
{
public:
    SimpleLinearRegression(const std::vector<std::pair<double, double> >& data);
    ~SimpleLinearRegression();
    void solve();

private:
    std::vector<std::pair<double, double> > _data;
};

struct SimpleLinearRegressionCost
{
    const double _x, _y;

    SimpleLinearRegressionCost(double x, double y) :_x(x), _y(y) {

    }

    template<typename T>
    bool operator()(const T* const B0, const T* const B1, T* residual) const {
        residual[0] = T(_y) - (B0[0] + B1[0] * T(_x));
        return true;
    }
};
