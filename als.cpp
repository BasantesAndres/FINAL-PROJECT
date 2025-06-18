#include "als.h"
#include "metrics.h"
#include <fstream>
#include <chrono>
#include <random>


void train_als(const std::vector<Rating>& ratings,
               int num_users, int num_items, int k,
               double lambda, int iterations,
               std::vector<Eigen::VectorXd>& U,
               std::vector<Eigen::VectorXd>& V) {

    std::vector<double> rmse_history;
    std::vector<double> mae_history;


    std::default_random_engine engine;
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (auto& u : U) for (int i = 0; i < k; ++i) u[i] = dist(engine);
    for (auto& v : V) for (int i = 0; i < k; ++i) v[i] = dist(engine);

    auto start = std::chrono::high_resolution_clock::now();

    for (int iter = 0; iter < iterations; ++iter) {

        for (int u = 0; u < num_users; ++u) {
            Eigen::MatrixXd A = lambda * Eigen::MatrixXd::Identity(k, k);
            Eigen::VectorXd b = Eigen::VectorXd::Zero(k);
            for (const auto& r : ratings) {
                if (r.user_id == u) {
                    A += V[r.item_id] * V[r.item_id].transpose();
                    b += r.rating * V[r.item_id];
                }
            }
            U[u] = A.ldlt().solve(b);
        }

        for (int i = 0; i < num_items; ++i) {
            Eigen::MatrixXd A = lambda * Eigen::MatrixXd::Identity(k, k);
            Eigen::VectorXd b = Eigen::VectorXd::Zero(k);
            for (const auto& r : ratings) {
                if (r.item_id == i) {
                    A += U[r.user_id] * U[r.user_id].transpose();
                    b += r.rating * U[r.user_id];
                }
            }
            V[i] = A.ldlt().solve(b);
        }

        double rmse = compute_rmse(ratings, U, V);
        double mae = compute_mae(ratings, U, V);
        rmse_history.push_back(rmse);
        mae_history.push_back(mae);
    }

    auto end = std::chrono::high_resolution_clock::now();
    double total_sec = std::chrono::duration<double>(end - start).count();

    std::ofstream out("als_metrics.csv");
    out << "iteration,rmse,mae\n";
    for (int i = 0; i < rmse_history.size(); ++i)
        out << i + 1 << "," << rmse_history[i] << "," << mae_history[i] << "\n";
    out.close();

    std::ofstream t("als_time.txt");
    t << "ALS training time (s): " << total_sec << std::endl;
    t.close();
}
