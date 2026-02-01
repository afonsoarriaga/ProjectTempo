#ifndef SAMPLENTT_H
#define SAMPLENTT_H

#include <stdint.h>
#include "params.h"

// FIPS 203, appendix B
#define MAX_ITER 280

void algorithmA0(int16_t a[KYBER_N], const uint8_t seed[34]);

#endif