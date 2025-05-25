#ifndef SGD_H
#define SGD_H

#include <vector>
#include <Eigen/Dense>
#include "matrix_loader.h"

void train_sgd(const std::vector<Rating>& ratings,
               int num_users, int num_items, int k,
               double lambda, double learning_rate, int iterations,
               std::vector<Eigen::VectorXd>& U,
               std::vector<Eigen::VectorXd>& V);

#endif
