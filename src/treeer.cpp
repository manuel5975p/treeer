#include <numeric>
#include "treeer.hpp"
#include "combinatorics.hpp"

const tree_node* get_valid_starting_point(const tree_node& t, int nr_required_children){
    if (t.children.size() >= nr_required_children)
        return &t;

    for (auto const& c : t.children) {
        if (c->children.size() >= nr_required_children)
            return c.get();
    }

    return nullptr;
}

bool is_embeddable(const tree_node& smol,const tree_node& big){
    // ignore colour for now

    int nr_smol_children = smol.children.size();
    int nr_big_children = big.children.size();

    auto root = get_valid_starting_point(big, nr_smol_children);

    if (!root)
        return false;

    nr_big_children = root->children.size();

    std::vector<std::vector<bool>> embeddable(nr_big_children, std::vector<bool>(nr_smol_children));

    for (int i = 0; i < nr_big_children; ++i)
        for (int j = 0; j < nr_smol_children; ++j)
            embeddable[i][j] = is_embeddable(*smol.children[j], *root->children[i]);

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
