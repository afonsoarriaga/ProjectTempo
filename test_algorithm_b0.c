#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "algorithms.h"

// Prototype for oldAlgorithmB0 (must be present in algorithms.h or declared here)
void oldAlgorithmB0(int16_t a[KYBER_N], const uint8_t extseed[KYBER_SYMBYTES + 2]);

// Helper: fill buffer with random bytes (using /dev/urandom if available, else rand())
static void random_bytes(uint8_t *buf, size_t len) {
    FILE *urandom = fopen("/dev/urandom", "rb");
    if (urandom) {
        fread(buf, 1, len, urandom);
        fclose(urandom);
    } else {
        // fallback: not cryptographically secure, but fine for test
        for (size_t i = 0; i < len; ++i) {
            buf[i] = rand() & 0xFF;
        }
    }
}

int main(void) {
    int failures = 0;
    int16_t out_new[KYBER_N];
    int16_t out_old[KYBER_N];
    uint8_t seed[KYBER_SYMBYTES + 2];

    // Seed PRNG for fallback
    srand((unsigned)time(NULL));

    // Only 1 test for debugging
    for (int test = 0; test < 1; ++test) {
        random_bytes(seed, sizeof(seed));
        algorithmB0(out_new, seed);
        oldAlgorithmB0(out_old, seed);

        if (memcmp(out_new, out_old, sizeof(out_new)) != 0) {
            printf("Test %d FAILED!\n", test + 1);
            failures++;
            // Optionally print the differing outputs
            for (int i = 0; i < KYBER_N; ++i) {
                if (out_new[i] != out_old[i]) {
                    printf("  Coeff %d: new=%d, old=%d\n", i, out_new[i], out_old[i]);
                }
            }
        }
    }

    if (failures == 0) {
        printf("Test passed: algorithmB0 matches oldAlgorithmB0 (with reversal).\n");
        return 0;
    } else {
        printf("%d test(s) failed.\n", failures);
        return 1;
    }
}
