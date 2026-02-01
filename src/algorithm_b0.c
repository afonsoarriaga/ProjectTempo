/********************************************************************************
 * Project: Tempo                                                               *
 *                                                                              *
 * Name: Algorithm B0                                                           *
 * Description: CT integer division with remainder,                             *
 *              over 3200-bit integers using OpenSSL                            *
 *              (assuming all calls to OpenSSL execute in CT)                   *
 ********************************************************************************/

#include <openssl/bn.h>

#include "algorithms.h"
#include "config.h"
#include "fips202.h"

void algorithmB0(int16_t a[KYBER_N], const uint8_t extseed[KYBER_SYMBYTES + 2]) {
    uint8_t C[400]; // 400 bytes = 3200 bits

    shake128incctx state;
    shake128_inc_init(&state);
    shake128_inc_absorb(&state, extseed, KYBER_SYMBYTES + 2);
    shake128_inc_finalize(&state);
    shake128_inc_squeeze(C, sizeof(C), &state);
    shake128_inc_ctx_release(&state);
    
    // create OpenSSL BN context and numbers
    BN_CTX *bn_ctx = BN_CTX_new();
    BIGNUM *x_bn = BN_new();
    BIGNUM *m_bn = BN_new();
    BIGNUM *quotient = BN_new();
    BIGNUM *remainder = BN_new();

    // set m = KYBER_Q
    BN_set_word(m_bn, KYBER_Q);
    
    // set x_bn from the 400-byte buffer C 
    // (load little-endian, as other algorithms in this library)
    BN_lebin2bn(C, sizeof(C), x_bn);

    for (uint16_t j = 0; j < KYBER_N; j++) {
        // quotient = x_bn / m_bn
        // remainder = x_bn % m_bn
        BN_div(quotient, remainder, x_bn, m_bn, bn_ctx);

        // remainer fits in 16 bits
        a[j] = (uint16_t)BN_get_word(remainder);

        // x_bn = quotient for next iteration
        BN_copy(x_bn, quotient);
    }

    BN_free(x_bn);
    BN_free(m_bn);
    BN_free(quotient);
    BN_free(remainder);
    BN_CTX_free(bn_ctx);
}
