#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <vector>
#include <Eigen/Dense>

// Muestra las primeras filas de una matriz (lista de vectores)
void print_matrix_preview(const std::vector<Eigen::VectorXd>& mat, int rows = 5);

// Recomienda los N ítems con mayor puntuación estimada para un usuario
std::vector<int> recommend_top_n(const Eigen::VectorXd& user, const std::vector<Eigen::VectorXd>& items, int N);

#endif
