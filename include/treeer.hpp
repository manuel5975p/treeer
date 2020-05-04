#ifndef TREEER_HPP
#define TREEER_HPP

#include <functional>
#include <vector>
#include <memory>
#include <optional>

constexpr unsigned int N = 3;

struct tree_node{
    unsigned int color;
    std::vector<std::unique_ptr<tree_node>> children;
    // std::vector<std::reference_wrapper<std::unique_ptr<tree_node>>> flat;
};

template <typename T>
using opt_ref = std::optional<std::reference_wrapper<T>>;

opt_ref<const tree_node> get_valid_starting_point(const tree_node& t, int nr_required_children);

bool is_embeddable(const tree_node& smol,const tree_node& big);

#endif // TREEER_HPP
