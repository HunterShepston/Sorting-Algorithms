#include "batcher.h"

void comparator(uint32_t *A, uint32_t x, uint32_t y, Stats *stats) {
    if (cmp(stats, A[x], A[y]) == 1) {
        swap(stats, &A[x], &A[y]);
    }
}

uint32_t bit_length(uint32_t n) {
    uint32_t count = 0;
    uint32_t subn = n;
    while (subn != 0) {
        subn = subn >> 1;
        count += 1;
    }
    return count;
}

void batcher_sort(Stats *stats, uint32_t *A, uint32_t n) {
    if (n == 0) {
        return;
    }
    uint32_t t = bit_length(n);
    uint32_t p = 1 << (t - 1);
    while (p > 0) {
        uint32_t q = 1 << (t - 1);
        uint32_t r = 0;
        uint32_t d = p;
        while (d > 0) {
            for (uint32_t i = 0; i < (n - d); i += 1) {
                if ((i & p) == r) {
                    comparator(A, i, i + d, stats);
                }
            }
            d = q - p;
            q = q >> 1;
            r = p;
        }
        p = p >> 1;
    }
}
