#ifndef ALS_H
#define ALS_H

#include <vector>
#include <Eigen/Dense>
#include "matrix_loader.h"

void train_als(const std::vector<Rating>& ratings,
               int num_users, int num_items, int k,
               double lambda, int iterations,
               std::vector<Eigen::VectorXd>& U,
               std::vector<Eigen::VectorXd>& V);

#endif
