#include "extensions.h"
#include <iostream>
#include <algorithm>

// Vista previa de vectores latentes (para inspección)
void print_matrix_preview(const std::vector<Eigen::VectorXd>& mat, int rows) {
    std::cout << "\nMatrix Preview (first " << rows << " vectors):" << std::endl;
    for (int i = 0; i < std::min(rows, (int)mat.size()); ++i) {
        std::cout << i << ": ";
        for (int j = 0; j < mat[i].size(); ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Retorna los N mejores ítems para un usuario según la predicción
std::vector<int> recommend_top_n(const Eigen::VectorXd& user, const std::vector<Eigen::VectorXd>& items, int N) {
    std::vector<std::pair<double, int>> scores;
    for (int i = 0; i < items.size(); ++i) {
        scores.emplace_back(user.dot(items[i]), i);
    }

    std::sort(scores.rbegin(), scores.rend()); // de mayor a menor

    std::vector<int> top_n;
    for (int i = 0; i < N && i < scores.size(); ++i)
        top_n.push_back(scores[i].second);

    return top_n;
}
