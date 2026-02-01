/********************************************************************************
 * Project: Tempo                                                               *
 *                                                                              *
 * Name: Algorithm C1                                                           *
 * Description: CT modular reduction,                                           *
 *              self-contained implementation using Barrett reduction           *
 ********************************************************************************/

#include "samplentt.h"
#include "params.h"
#include "fips202.h"

#define lt_1mask(x,y) (uint32_t)((((int32_t) x) - ((int32_t) y)) >> 31)  // 0xffffffffffffffff if x < y and 0 otherwise

// constants and pre-computations
const uint16_t m = 3329;
const uint32_t mu = 1290167;
const uint16_t pow2_mod_m[] = {
    1,    // 2^{i*32} = 2^0 mod 3329 (for x0)
    1353, // 2^{i*32} = 2^32 mod 3329 (for x1)
    2988, // 2^{i*32} = 2^64 mod 3329 (for x2)
    1358, // 2^{i*32} = 2^96 mod 3329 (for x3)
    3095, // 2^{i*32} = 2^128 mod 3329 (for x4)
    2982  // 2^{i*32} = 2^160 mod 3329 (for x5)
};

/*
Based on Barrett reduction described in HAC, Algorithm 14.42.

b = 2^16
k = 1
m = m0 \in [0,2^16) = KYBER_Q = 3329
x = (x1,x0) \in [0,2^32)
mu = floor(2^32/m) = 1290167
*/
uint16_t barrett_reduce32(uint32_t x) {
    uint64_t q3;
    uint32_t r;

    q3 = ((uint64_t)x * mu) >> 32;
    r = x - (uint32_t)(q3 * m);

    // while r >= m do r = r - m
    // at most 2 loops (HAC Fact 14.43) in general
    // at most 1 loop for m=3329
    uint32_t mask = ~lt_1mask(r,m); // mask is 0 if r < m, 0xffffffff otherwise
    r -= (mask & m);

    return (uint16_t)r;
}

/*
x = x5*2^160 + x4*2^128 + x3*2^92 + x2*2^64 + x1*2^32 + x0

r = x `mod` m
  = (x5*2^160 + x4*2^128 + x3*2^92 + x2*2^64 + x1*2^32 + x0) `mod` m
  = ((x5 `mod` m) * (2^160 `mod` m) + 
     (x4 `mod` m) * (2^128 `mod` m) + 
     (x3 `mod` m) * (2^92 `mod` m)  + 
     (x2 `mod` m) * (2^64 `mod` m)  + 
     (x1 `mod` m) * (2^32 `mod` m)  +
     (x0 `mod` m)) `mod` m
*/
uint16_t reduce192(uint32_t x[6]) {
    uint32_t temp = 0;

    for (int i = 5; i >= 0; i--)
        temp += (uint32_t)barrett_reduce32(x[i]) * (uint32_t)pow2_mod_m[i];
    
    return barrett_reduce32(temp);
}

void algorithmC1(int16_t a[KYBER_N], const uint8_t extseed[KYBER_SYMBYTES + 2]) {
    uint8_t C[24];
    uint32_t x[6];

    shake128incctx state;
    shake128_inc_init(&state);
    shake128_inc_absorb(&state, extseed, KYBER_SYMBYTES + 2);
    shake128_inc_finalize(&state);

    for (size_t j = 0; j < KYBER_N; j++) {
        shake128_inc_squeeze(C, sizeof(C), &state);
        
        for (int i = 0; i < 6; i++) {
            x[i] = ( uint32_t)C[i * 4 + 0]        |
                   ((uint32_t)C[i * 4 + 1] << 8)  |
                   ((uint32_t)C[i * 4 + 2] << 16) |
                   ((uint32_t)C[i * 4 + 3] << 24);
        }
        a[j] = reduce192(x);
    }

    shake128_inc_ctx_release(&state);
}
