#include <algorithm>

// http://www.martinbroadhurst.com/combinations.html
template <typename T>
bool next_combination(T *ar, std::size_t n, T k)
{
    bool finished = false;
    bool changed = false;
    unsigned int i;

    if (k > 0) {
        for (unsigned int i = k - 1; !finished && !changed; i--) {
            if (ar[i] < (n - 1) - (k - 1) + i) {
                /* Increment this element */
                ar[i]++;
                if (i < k - 1) {
                    /* Turn the elements after it into a linear sequence */
                    unsigned int j;
                    for (j = i + 1; j < k; j++) {
                        ar[j] = ar[j - 1] + 1;
                    }
                }
                changed = true;
            }
            finished = i == 0;
        }
        if (!changed) {
            /* Reset to first combination */
            for (unsigned int i = 0; i < k; i++) {
                ar[i] = i;
            }
        }
    }
    return changed;
}

// http://www.martinbroadhurst.com/k-permutations.html
template <typename T>
unsigned int next_k_permutation(T *ar, std::size_t n, T k)
{
    bool result = std::next_permutation(ar, ar + k);
    if (!result)
        result = next_combination(ar, n, k);
    return result;
}
