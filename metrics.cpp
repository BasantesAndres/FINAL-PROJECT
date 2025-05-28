#include "metrics.h"
#include <cmath>

double compute_rmse(const std::vector<Rating>& ratings,
                    const std::vector<Eigen::VectorXd>& U,
                    const std::vector<Eigen::VectorXd>& V) {
    double sum = 0.0;
    for (const auto& r : ratings) {
        double pred = U[r.user_id].dot(V[r.item_id]);
        sum += std::pow(r.rating - pred, 2);
    }
    return std::sqrt(sum / ratings.size());
}

double compute_mae(const std::vector<Rating>& ratings,
                   const std::vector<Eigen::VectorXd>& U,
                   const std::vector<Eigen::VectorXd>& V) {
    double sum = 0.0;
    for (const auto& r : ratings) {
        double pred = U[r.user_id].dot(V[r.item_id]);
        sum += std::abs(r.rating - pred);
    }
    return sum / ratings.size();
}
