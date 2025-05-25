#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include "matrix_loader.h"
#include "sgd.h"
#include "als.h"
#include "metrics.h"
#include "extensions.h"

int main() {
    std::vector<Rating> ratings = load_ratings("data/ratings.csv");
    int num_users = get_num_users(ratings);
    int num_items = get_num_items(ratings);
    int k = 10;
    double lambda = 0.1;
    double learning_rate = 0.01;
    int iterations = 30;

    std::vector<Eigen::VectorXd> U_sgd(num_users, Eigen::VectorXd::Zero(k));
    std::vector<Eigen::VectorXd> V_sgd(num_items, Eigen::VectorXd::Zero(k));
    std::vector<Eigen::VectorXd> U_als(num_users, Eigen::VectorXd::Zero(k));
    std::vector<Eigen::VectorXd> V_als(num_items, Eigen::VectorXd::Zero(k));

    std::cout << "\nTraining with SGD...\n";
    train_sgd(ratings, num_users, num_items, k, lambda, learning_rate, iterations, U_sgd, V_sgd);
    std::cout << "SGD RMSE: " << compute_rmse(ratings, U_sgd, V_sgd) << std::endl;
    std::cout << "SGD MAE:  " << compute_mae(ratings, U_sgd, V_sgd) << std::endl;

    std::cout << "\nTraining with ALS...\n";
    train_als(ratings, num_users, num_items, k, lambda, iterations, U_als, V_als);
    std::cout << "ALS RMSE: " << compute_rmse(ratings, U_als, V_als) << std::endl;
    std::cout << "ALS MAE:  " << compute_mae(ratings, U_als, V_als) << std::endl;

    print_matrix_preview(U_als, 5);
    print_matrix_preview(V_als, 5);

    int example_user = 0;
    auto recommendations = recommend_top_n(U_als[example_user], V_als, 5);
    std::cout << "Top 5 recommendations for user " << example_user << ": ";
    for (int id : recommendations) std::cout << id << " ";
    std::cout << std::endl;

    return 0;
}
