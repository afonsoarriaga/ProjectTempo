#include <stdint.h>
#include <string.h>

#include "params.h"  // defines KYBER_PUBLICKEYBYTES, KYBER_SECRETKEYBYTES, KYBER_SYMBYTES
#include "pake.h"    // defines initStart, resp, initEnd, MSG1_LEN, MSG2_LEN
#include "api.h"     // defines CRYPTO_PUBLICKEYBYTES, CRYPTO_SECRETKEYBYTES, CRYPTO_CIPHERTEXTBYTES, CRYPTO_BYTES for NoIC[MLKEM512]

/* wrapper:
 *   pk (public key)  = msg1
 *   sk (secret key)  = kem_sk || kem_pk || msg1
 *   ct (ciphertext)  = msg2
 *
 * sizes must satisfy:
 *   CRYPTO_PUBLICKEYBYTES   == MSG1_LEN
 *   CRYPTO_CIPHERTEXTBYTES  == MSG2_LEN
 *   CRYPTO_BYTES            == KYBER_SYMBYTES (shared secret size)
 *   CRYPTO_SECRETKEYBYTES   == KYBER_SECRETKEYBYTES + KYBER_PUBLICKEYBYTES + MSG1_LEN
 */

// global fixed password and session id (all-zero) for benchmarks purposes only
static const uint8_t pw_global[KYBER_SYMBYTES]  = {0};
static const uint8_t sid_global[KYBER_SYMBYTES] = {0};

int crypto_kem_keypair(unsigned char *pk, unsigned char *sk)
{
    uint8_t msg1[MSG1_LEN];
    uint8_t kem_pk[KYBER_PUBLICKEYBYTES];
    uint8_t kem_sk[KYBER_SECRETKEYBYTES];

    // run PAKE initiator first round: produces msg1, kem_pk, kem_sk.
    initStart(msg1,
              kem_pk,
              kem_sk,
              pw_global,
              sid_global);

    // pk = msg1
    memcpy(pk, msg1, MSG1_LEN);

    // sk = kem_sk || kem_pk || msg1
    uint8_t *p = sk;

    memcpy(p, kem_sk, KYBER_SECRETKEYBYTES);
    p += KYBER_SECRETKEYBYTES;

    memcpy(p, kem_pk, KYBER_PUBLICKEYBYTES);
    p += KYBER_PUBLICKEYBYTES;

    memcpy(p, msg1, MSG1_LEN);

    return 0;
}

int crypto_kem_enc(unsigned char *ct,
                   unsigned char *ss,
                   const unsigned char *pk)
{
    const uint8_t *msg1 = pk;  /* pk holds msg1 */

    uint8_t key[KYBER_SYMBYTES];
    uint8_t msg2[MSG2_LEN];

    /* run responder: msg1 -> (key, msg2). */
    resp(key,
         msg2,
         msg1,
         pw_global,
         sid_global);

    /* ss = key */
    memcpy(ss, key, KYBER_SYMBYTES);

    /* ct = msg2 */
    memcpy(ct, msg2, MSG2_LEN);

    return 0;
}

int crypto_kem_dec(unsigned char *ss,
                   const unsigned char *ct,
                   const unsigned char *sk)
{
    const uint8_t *p = sk;

    uint8_t kem_sk[KYBER_SECRETKEYBYTES];
    uint8_t kem_pk[KYBER_PUBLICKEYBYTES];
    uint8_t msg1[MSG1_LEN];
    const uint8_t *msg2 = ct;  /* ct holds msg2 */

    uint8_t key[KYBER_SYMBYTES];

    /* parse sk = kem_sk || kem_pk || msg1 */
    memcpy(kem_sk, p, KYBER_SECRETKEYBYTES);
    p += KYBER_SECRETKEYBYTES;

    memcpy(kem_pk, p, KYBER_PUBLICKEYBYTES);
    p += KYBER_PUBLICKEYBYTES;

    memcpy(msg1, p, MSG1_LEN);

    /* run initiator final step: (msg2, msg1, kem_pk, kem_sk) -> key. */
    initEnd(key,
            msg2,
            msg1,
            kem_pk,
            kem_sk,
            sid_global);

    /* ss = key */
    memcpy(ss, key, KYBER_SYMBYTES);

    return 0;
}
