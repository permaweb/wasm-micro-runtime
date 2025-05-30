#ifndef _NAN_CANONICALIZATION_H
#define _NAN_CANONICALIZATION_H

#ifdef __cplusplus
extern "C" {
#endif

// Canonical NaNs in WASM have their most significant bit set to 1
#define _CANONICAL_NAN_POSITIVE_F32 (0x7FC00000)
#define _CANONICAL_NAN_POSITIVE_F64 (0x7FF8000000000000ULL)
#define _CANONICAL_NAN_NEGATIVE_F32 (0xFFC00000)
#define _CANONICAL_NAN_NEGATIVE_F64 (0xFFF8000000000000ULL)

static const unsigned long long CANONICAL_NAN_POSITIVE_F32 = _CANONICAL_NAN_POSITIVE_F32;
static const unsigned long long CANONICAL_NAN_POSITIVE_F64 = _CANONICAL_NAN_POSITIVE_F64;
static const unsigned long long CANONICAL_NAN_NEGATIVE_F32 = _CANONICAL_NAN_NEGATIVE_F32;
static const unsigned long long CANONICAL_NAN_NEGATIVE_F64 = _CANONICAL_NAN_NEGATIVE_F64;

// Conditionally set the canonical NaN based on the build flag
#if WASM_NAN_CANONICALIZATION_SIGN_BIT == 1
#define _CANONICAL_NAN_F32 _CANONICAL_NAN_NEGATIVE_F32
#define _CANONICAL_NAN_F64 _CANONICAL_NAN_NEGATIVE_F64
#else
#define _CANONICAL_NAN_F32 _CANONICAL_NAN_POSITIVE_F32
#define _CANONICAL_NAN_F64 _CANONICAL_NAN_POSITIVE_F64
#endif

static const unsigned long long CANONICAL_NAN_F32 = _CANONICAL_NAN_F32;
static const unsigned long long CANONICAL_NAN_F64 = _CANONICAL_NAN_F64;

#ifdef __cplusplus
}
#endif

#endif