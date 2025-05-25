#include "als.h"
#include "metrics.h"
#include <fstream>
#include <chrono>
#include <random>

void train_sgd(const std::vector<Rating>& ratings,
               int num_users, int num_items, int k,
               double lambda, double learning_rate, int iterations,
               std::vector<Eigen::VectorXd>& U,
               std::vector<Eigen::VectorXd>& V) {

    std::vector<double> rmse_history;
    std::vector<double> mae_history;

    // Inicializar U y V
    std::default_random_engine engine;
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (auto& u : U) for (int i = 0; i < k; ++i) u[i] = dist(engine);
    for (auto& v : V) for (int i = 0; i < k; ++i) v[i] = dist(engine);

    auto start = std::chrono::high_resolution_clock::now();

    for (int iter = 0; iter < iterations; ++iter) {
        for (const auto& r : ratings) {
            int u = r.user_id;
            int i = r.item_id;
            double error = r.rating - U[u].dot(V[i]);

            U[u] += learning_rate * (error * V[i] - lambda * U[u]);
            V[i] += learning_rate * (error * U[u] - lambda * V[i]);
        }

        // Guardar métricas por iteración
        double rmse = compute_rmse(ratings, U, V);
        double mae = compute_mae(ratings, U, V);
        rmse_history.push_back(rmse);
        mae_history.push_back(mae);
    }

    auto end = std::chrono::high_resolution_clock::now();
    double total_sec = std::chrono::duration<double>(end - start).count();

    // Guardar CSV
    std::ofstream out("sgd_metrics.csv");
    out << "iteration,rmse,mae\n";
    for (int i = 0; i < rmse_history.size(); ++i)
        out << i + 1 << "," << rmse_history[i] << "," << mae_history[i] << "\n";
    out.close();

    std::ofstream t("sgd_time.txt");
    t << "SGD training time (s): " << total_sec << std::endl;
    t.close();
}
