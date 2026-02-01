/********************************************************************************
 * Project: Tempo                                                               *
 *                                                                              *
 * Name: Algorithm C0                                                           *
 * Description: CT modular reduction, using OpenSSL                             *
 ********************************************************************************/

#include <openssl/bn.h>

#include "algorithms.h"
#include "config.h"
#include "fips202.h"

void algorithmC0(int16_t a[KYBER_N], const uint8_t extseed[KYBER_SYMBYTES + 2]) {
    uint8_t C[24];

    shake128incctx state;
    shake128_inc_init(&state);
    shake128_inc_absorb(&state, extseed, KYBER_SYMBYTES + 2);
    shake128_inc_finalize(&state);

    // create OpenSSL BN context and numbers
    BN_CTX *bn_ctx = BN_CTX_new();
    BIGNUM *x_bn = BN_new();        // 192-bit integer
    BIGNUM *m_bn = BN_new();        // modulus
    BIGNUM *r_bn = BN_new();        // remainder

    // set m = KYBER_Q
    BN_set_word(m_bn, KYBER_Q);

    for (int i = 0; i < KYBER_N; i++) {
        shake128_inc_squeeze(C, sizeof(C), &state);

        // set x_bn from the 24-byte buffer C 
        // (load little-endian, as Algorithm C1, to cross-check calculations)
        BN_lebin2bn(C, 24, x_bn);

        // compute remainder: r_bn = x_bn `mod` m_bn
        BN_mod(r_bn, x_bn, m_bn, bn_ctx);

        // get the remainder as a 16-bit integer
        a[i] = (uint16_t)BN_get_word(r_bn);
    }

    BN_free(x_bn);
    BN_free(m_bn);
    BN_free(r_bn);
    BN_CTX_free(bn_ctx);

    shake128_inc_ctx_release(&state);
}
