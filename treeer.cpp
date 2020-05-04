#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <algorithm>
#include <numeric>
#include <memory>
#include <vector>
#include <optional>
#include "combinatorics.hpp"
constexpr unsigned int N = 3;
struct tree_node{
    unsigned int color;
    std::vector<std::unique_ptr<tree_node>> children;
    // std::vector<std::reference_wrapper<std::unique_ptr<tree_node>>> flat;
};

template <typename T>
using opt_ref = std::optional<std::reference_wrapper<T>>;

opt_ref<const tree_node> get_valid_starting_point(const tree_node& t, int nr_required_children){
    if (t.children.size() >= nr_required_children)
        return t;

    for (auto const& c : t.children) {
        if (c->children.size() >= nr_required_children)
            return *c;
    }

    return std::nullopt;
}

bool is_embeddable(const tree_node& smol,const tree_node& big){
    // ignore colour for now

    int nr_smol_children = smol.children.size();
    int nr_big_children = big.children.size();

    auto root = get_valid_starting_point(big, nr_smol_children);

    if (!root) {
        for (auto const& c : big.children) {
            if (is_embeddable(smol, *c)) {
                return true;
            }
        }
        return false;
    }

    std::vector<std::vector<bool>> embeddable(nr_big_children, std::vector<bool>(nr_smol_children));

    for (int i = 0; i < nr_big_children; ++i)
        for (int j = 0; j < nr_smol_children; ++j)
            embeddable[i][j] = is_embeddable(*smol.children[j], *big.children[i]);

    std::vector<int> k_permutation(nr_smol_children);
    std::iota(k_permutation.begin(), k_permutation.end(), 0);

    do {
        bool ok = true;
        for (int i = 0; i < nr_smol_children; ++i) {
            if (!embeddable[k_permutation[i]][i]) {
                ok = false;
                break;
            }
        }
        if (ok)
            return true;
    } while(next_k_permutation(&k_permutation[0], nr_big_children, nr_smol_children));

    return false;
}
int main(){

}