#ifndef API_H
#define API_H

#include "params.h"
#include "pake.h"

/*
 * Sizes must satisfy:
 *   CRYPTO_PUBLICKEYBYTES   == MSG1_LEN
 *   CRYPTO_CIPHERTEXTBYTES  == MSG2_LEN
 *   CRYPTO_BYTES            == KYBER_SYMBYTES   (shared secret size)
 *   CRYPTO_SECRETKEYBYTES   == KYBER_SECRETKEYBYTES + KYBER_PUBLICKEYBYTES + MSG1_LEN
 */
#define CRYPTO_SECRETKEYBYTES  KYBER_SECRETKEYBYTES + KYBER_PUBLICKEYBYTES + MSG1_LEN
#define CRYPTO_PUBLICKEYBYTES  MSG1_LEN
#define CRYPTO_CIPHERTEXTBYTES MSG2_LEN
#define CRYPTO_BYTES           KYBER_SSBYTES

#define CRYPTO_ALGNAME "NOIC-A1-MLKEM768"

int crypto_kem_keypair(unsigned char *pk, unsigned char *sk);
int crypto_kem_enc(unsigned char *ct, unsigned char *ss, const unsigned char *pk);
int crypto_kem_dec(unsigned char *ss, const unsigned char *ct, const unsigned char *sk);

#endif