#include <random>
#include <ceres/ceres.h>
#include "simpleLinearRegression.h"

SimpleLinearRegression::SimpleLinearRegression(const std::vector<std::pair<double, double> >& data)
    :_data(data)
{

}

SimpleLinearRegression::~SimpleLinearRegression()
{

}

void SimpleLinearRegression::solve()
{
    double B0, B1;
    ceres::Problem problem;
    for (auto m : _data) {
        problem.AddResidualBlock(
            new ceres::AutoDiffCostFunction<SimpleLinearRegressionCost, 1, 1, 1>(
                new SimpleLinearRegressionCost(m.first, m.second)
                ),
            nullptr,
            &B0, &B1
        );
    }

    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_SCHUR;
    options.minimizer_progress_to_stdout = true;

    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.BriefReport() << std::endl;
    std::cout << "estimated a, b = " << B0 << "," << B1 << std::endl;
}



int main(int argc, char* argv[]) {
    std::vector<std::pair<double, double> > data;
    data.emplace_back(1,1);
    data.emplace_back(2,3);
    data.emplace_back(4,3);
    data.emplace_back(3,2);
    data.emplace_back(5,5);
    SimpleLinearRegression simpleLinearRegression(data);
    simpleLinearRegression.solve();
	return 0;
}
