#include "quick.h"

uint32_t partition(uint32_t *A, uint32_t lo, uint32_t hi, Stats *stats) {
    uint32_t i = lo - 1;
    for (uint32_t j = lo; j < hi; j += 1) {
        if (cmp(stats, A[j - 1], A[hi - 1]) == -1) {
            i += 1;
            swap(stats, &A[i - 1], &A[j - 1]);
        }
    }
    swap(stats, &A[i], &A[hi - 1]);
    return i + 1;
}

void quick_sorter(uint32_t *A, uint32_t lo, uint32_t hi, Stats *stats) {
    if (lo < hi) {
        uint32_t p = partition(A, lo, hi, stats);
        quick_sorter(A, lo, p - 1, stats);
        quick_sorter(A, p + 1, hi, stats);
    }
}

void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {
    quick_sorter(A, 1, n, stats);
}
