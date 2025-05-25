#ifndef MATRIX_LOADER_H
#define MATRIX_LOADER_H

#include <vector>
#include <string>

struct Rating {
    int user_id;
    int item_id;
    double rating;
};

std::vector<Rating> load_ratings(const std::string& filename);
int get_num_users(const std::vector<Rating>& ratings);
int get_num_items(const std::vector<Rating>& ratings);

#endif
