#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int e[25];  // exponents for primes <= 100 (25 primes)
} term;

int prime_list[] =
    {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
     53,59,61,67,71,73,79,83,89,97};

int prime_count = 25;

int equal(term *a, term *b) {
    return memcmp(a->e, b->e, sizeof(a->e)) == 0;
}

int exists(term *list, int n, term *t) {
    for (int i = 0; i < n; i++)
        if (equal(&list[i], t))
            return 1;
    return 0;
}

int main() {
    clock_t start = clock();

    term results[10000];
    int count = 0;

    for (int a = 2; a <= 100; a++) {

        int base = a;
        int factor_exp[25] = {0};

        for (int p = 0; p < prime_count; p++) {
            while (base % prime_list[p] == 0) {
                base /= prime_list[p];
                factor_exp[p]++;
            }
        }

        for (int b = 2; b <= 100; b++) {

            term t = {0};
            for (int i = 0; i < prime_count; i++)
                t.e[i] = factor_exp[i] * b;

            if (!exists(results, count, &t)) {
                results[count++] = t;
            }
        }
    }

    clock_t end = clock();

    printf("Distinct terms: %d\n", count);
    printf("Time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
