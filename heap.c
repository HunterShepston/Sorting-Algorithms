#include "heap.h"

#include <stdbool.h>

uint32_t max_child(uint32_t *A, uint32_t parenti, uint32_t n, Stats *stats) {
    uint32_t left = 2 * parenti;
    uint32_t right = left + 1;
    if (right <= n && cmp(stats, A[right - 1], A[left - 1]) == 1) {
        return right;
    }
    return left;
}

void fix_heap(uint32_t *A, uint32_t parenti, uint32_t n, Stats *stats) {
    bool found = false;
    uint32_t mother = parenti;
    uint32_t great = max_child(A, parenti, n, stats);
    while (mother <= (n >> 1) && found == 0) {
        if (cmp(stats, A[mother - 1], A[great - 1]) == -1) {
            swap(stats, &A[mother - 1], &A[great - 1]);
            mother = great;
            great = max_child(A, mother, n, stats);
        } else {
            found = true;
        }
    }
}

void build_heap(uint32_t *A, uint32_t parenti, uint32_t n, Stats *stats) {
    for (uint32_t father = n >> 1; father > parenti - 1; father -= 1) {
        fix_heap(A, father, n, stats);
    }
}

void heap_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t first = 1;
    build_heap(A, first, n, stats);
    for (uint32_t leaf = n; leaf > first; leaf -= 1) {
        swap(stats, &A[first - 1], &A[leaf - 1]);
        fix_heap(A, first, leaf - 1, stats);
    }
}
