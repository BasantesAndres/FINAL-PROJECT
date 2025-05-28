#ifndef METRICS_H
#define METRICS_H

#include <vector>
#include <Eigen/Dense>
#include "matrix_loader.h"

double compute_rmse(const std::vector<Rating>& ratings,
                    const std::vector<Eigen::VectorXd>& U,
                    const std::vector<Eigen::VectorXd>& V);

double compute_mae(const std::vector<Rating>& ratings,
                   const std::vector<Eigen::VectorXd>& U,
                   const std::vector<Eigen::VectorXd>& V);

#endif
