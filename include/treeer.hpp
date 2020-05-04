#ifndef TREEER_HPP
#define TREEER_HPP

#include <vector>
#include <memory>
#include <optional>

constexpr unsigned int N = 3;

struct tree_node{
    std::vector<std::unique_ptr<tree_node>> children {};
    unsigned int color {0};
};

const tree_node* get_valid_starting_point(const tree_node& t, int nr_required_children);

bool is_embeddable(const tree_node& smol,const tree_node& big);

#endif // TREEER_HPP
