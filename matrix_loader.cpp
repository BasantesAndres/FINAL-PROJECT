#include "matrix_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Rating> load_ratings(const std::string& filename) {
    std::vector<Rating> ratings;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return ratings;
    }

    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string user, item, rate;
        std::getline(ss, user, ',');
        std::getline(ss, item, ',');
        std::getline(ss, rate, ',');
        ratings.push_back({std::stoi(user), std::stoi(item), std::stod(rate)});
    }
    return ratings;
}

int get_num_users(const std::vector<Rating>& ratings) {
    int max_id = 0;
    for (const auto& r : ratings)
        if (r.user_id > max_id) max_id = r.user_id;
    return max_id + 1;
}

int get_num_items(const std::vector<Rating>& ratings) {
    int max_id = 0;
    for (const auto& r : ratings)
        if (r.item_id > max_id) max_id = r.item_id;
    return max_id + 1;
}
