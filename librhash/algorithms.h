/* algorithms.h - rhash library algorithms */
#ifndef RHASH_ALGORITHMS_H
#define RHASH_ALGORITHMS_H

#include <stddef.h> /* for ptrdiff_t */
#include "rhash.h"
#include "byte_order.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RHASH_API
/* modifier for RHash library functions */
# define RHASH_API
#endif

typedef void (*pinit_t)(void*);
typedef void (*pupdate_t)(void *ctx, const void* msg, size_t size);
typedef void (*pfinal_t)(void*, unsigned char*);
typedef void (*pcleanup_t)(void*);

typedef struct rhash_hash_info
{
	rhash_info *info;
	size_t context_size;
	ptrdiff_t  digest_diff;
	pinit_t    init;
	pupdate_t  update;
	pfinal_t   final;
	pcleanup_t cleanup;
} rhash_hash_info;

extern rhash_hash_info rhash_hash_info_default[RHASH_HASH_COUNT];
extern rhash_hash_info* rhash_info_table;
extern int rhash_info_size;
extern unsigned rhash_uninitialized_algorithms;

extern rhash_info info_crc32;
extern rhash_info info_md4;
extern rhash_info info_md5;
extern rhash_info info_sha1;
extern rhash_info info_tiger;
extern rhash_info info_tth ;
extern rhash_info info_btih;
extern rhash_info info_ed2k;
extern rhash_info info_aich;
extern rhash_info info_whirlpool;
extern rhash_info info_rmd160;
extern rhash_info info_gost;
extern rhash_info info_gostpro;
extern rhash_info info_has160;
extern rhash_info info_snf128;
extern rhash_info info_snf256;
extern rhash_info info_sha224;
extern rhash_info info_sha256;
extern rhash_info info_sha384;
extern rhash_info info_sha512;
extern rhash_info info_edr256;
extern rhash_info info_edr512;

/* rhash_info flags */
#define F_BS32 1   /* default output in base32 */
#define F_SWAP32 2 /* Big endian flag */
#define F_SWAP64 4

/* define endianness flags */
#ifndef CPU_BIG_ENDIAN
#define F_LE32 0
#define F_LE64 0
#define F_BE32 F_SWAP32
#define F_BE64 F_SWAP64
#else
#define F_LE32 F_SWAP32
#define F_LE64 F_SWAP64
#define F_BE32 0
#define F_BE64 0
#endif

void rhash_init_algorithms(unsigned mask);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RHASH_ALGORITHMS_H */
