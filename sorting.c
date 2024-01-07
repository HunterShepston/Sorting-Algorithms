#include "batcher.h"
#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum { INSERT = 0, BATCHER = 1, HEAP = 2, QUICK = 3 } algs;

//void prnt()

int main(int argc, char **argv) {
    Set s = empty_set();
    Stats stats;
    reset(&stats);
    int opt = 0;
    unsigned int seed = 13371453;
    int n = 100;
    int p = 100;
    uint32_t mask = 1073741823;
    int cnt = 0;
    
    int i;
    uint32_t *unsorted_array;

    while ((opt = getopt(argc, argv, "ahbiqr:n:p:Hm")) != -1) {
        switch (opt) {
        case 'a':
            s = insert_set(HEAP, s);
            s = insert_set(BATCHER, s);
            s = insert_set(INSERT, s);
            s = insert_set(QUICK, s);
            break;
        case 'h': s = insert_set(HEAP, s); break;
        case 'b': s = insert_set(BATCHER, s); break;
        case 'i': s = insert_set(INSERT, s); break;
        case 'q': s = insert_set(QUICK, s); break;
        case 'r': seed = strtoul(optarg, NULL, 10); break;
        case 'n': n = strtol(optarg, NULL, 10); break;
        case 'p': p = strtol(optarg, NULL, 10); break;
        case 'H':
            printf("SYNOPSIS\n"
                   "    Generates an array of pseudorandom numbers\n"
                   "    and sorts them using different algoritms.\n"
                   "\nUSAGE\n"
                   "    ./sorting [-ahbiqr:n:p:H] [-r seed] [-n length] [-p print]\n"
                   "\nOPTIONS\n"
                   "    -a          enables all sorting algorithms.\n"
                   "    -h          enables heap sort.\n"
                   "    -b          enables Batcher's odd even merge sort.\n"
                   "    -i          enables insertion sort.\n"
                   "    -q          enables quick sort.\n"
                   "    -r seed     sets seed for random numbers.\n"
                   "    -n length   sets length of random array.\n"
                   "    -p print    sets the amount of items to print from the final sorted arrays.\n"
                   "	-H			prints usage for program");
            break;
        default: fprintf(stderr, "Error, please specify a sorting algorithm\n"); return 1;
        }
    }



    for (algs r = INSERT; r <= QUICK; r += 1) {
        if (member_set(r, s)) {
            switch (r) {
            case INSERT:
                srandom(seed);
                unsorted_array = (uint32_t *)malloc(n * 32);
                for (i = 0; i < n; i += 1) {
                    unsorted_array[i] = (random() & mask);
                }
                insertion_sort(&stats, unsorted_array, n);
                printf("Insertion Sort, %d elements ", n);
                printf("%" PRIu64 " moves, ", stats.moves);
                printf("%" PRIu64 " compares\n", stats.compares);
                reset(&stats);
                cnt = 0;
                for (i = 0; i < p && i < n; i += 1) {
                    cnt += 1;
                    printf("%13" PRIu32, unsorted_array[i]);
                    if (cnt % 5 == 0) {
                        printf("\n");
                    }
                }
                if(cnt%5 != 0){printf("\n");}
                free(unsorted_array);
                break;
            case BATCHER:
                srandom(seed);
                unsorted_array = (uint32_t *)malloc(n * 32);
                for (i = 0; i < n; i += 1) {
                    unsorted_array[i] = (random() & mask);
                }
                batcher_sort(&stats, unsorted_array, n);
                printf("Batcher Sort, %d elements ", n);
                printf("%" PRIu64 " moves, ", stats.moves);
                printf("%" PRIu64 " compares\n", stats.compares);
                reset(&stats);
                cnt = 0;
                for (i = 0; i < p && i < n; i += 1) {
                    cnt += 1;
                    printf("%13" PRIu32, unsorted_array[i]);
                    if (cnt % 5 == 0) {
                        printf("\n");
                    }
                }
                if(cnt%5 != 0){printf("\n");}
                free(unsorted_array);
                break;
            case HEAP:
                srandom(seed);
                unsorted_array = (uint32_t *)malloc(n * 32);
                for (i = 0; i < n; i += 1) {
                    unsorted_array[i] = (random() & mask);
                }
                heap_sort(&stats, unsorted_array, n);
                printf("Heap Sort, %d elements ", n);
                printf("%" PRIu64 " moves, ", stats.moves);
                printf("%" PRIu64 " compares\n", stats.compares);
                reset(&stats);
                cnt = 0;
                for (i = 0; i < p && i < n; i += 1) {
                    cnt += 1;
                    printf("%13" PRIu32, unsorted_array[i]);
                    if (cnt % 5 == 0) {
                        printf("\n");
                    }
                }
                if(cnt%5 != 0){printf("\n");}
                free(unsorted_array);
                break;
            case QUICK:
                srandom(seed);
                unsorted_array = (uint32_t *)malloc(n * 32);
                for (i = 0; i < n; i += 1) {
                    unsorted_array[i] = (random() & mask);
                }
                quick_sort(&stats, unsorted_array, n);
                printf("Quick Sort, %d elements ", n);
                printf("%" PRIu64 " moves, ", stats.moves);
                printf("%" PRIu64 " compares\n", stats.compares);
                reset(&stats);
                cnt = 0;
                for (i = 0; i < p && i < n; i += 1) {
                    cnt += 1;
                    printf("%13" PRIu32, unsorted_array[i]);
                    if (cnt % 5 == 0) {
                        printf("\n");
                    }
                }
                if(cnt%5 != 0){printf("\n");}
                free(unsorted_array);
                break;
            }
        }
    }
}
