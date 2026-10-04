#define NIM_INTBITS 32
/* GENERATED CODE. DO NOT EDIT. */

#ifdef __cplusplus
#  if __cplusplus >= 201103L
#    /* nullptr is more type safe (less implicit conversions than 0) */
#    define NIM_NIL nullptr
#  else
#    // both `((void*)0)` and `NULL` would cause codegen to emit
#    // error: assigning to 'Foo *' from incompatible type 'void *'
#    // but codegen could be fixed if need. See also potential caveat regarding
#    // NULL.
#    // However, `0` causes other issues, see #13798
#    define NIM_NIL 0
#  endif
#else
#  include <stdbool.h>
#  define NIM_NIL NULL
#endif

#ifdef __cplusplus
#define NB8 bool
#elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901)
// see #13798: to avoid conflicts for code emitting `#include <stdbool.h>`
#define NB8 _Bool
#else
typedef unsigned char NB8; // best effort
#endif

typedef unsigned char NC8;

typedef float NF32;
typedef double NF64;
#if defined(__BORLANDC__) || defined(_MSC_VER)
typedef signed char NI8;
typedef signed short int NI16;
typedef signed int NI32;
typedef __int64 NI64;
/* XXX: Float128? */
typedef unsigned char NU8;
typedef unsigned short int NU16;
typedef unsigned int NU32;
typedef unsigned __int64 NU64;
#elif defined(HAVE_STDINT_H)
#ifndef USE_NIM_NAMESPACE
#  include <stdint.h>
#endif
typedef int8_t NI8;
typedef int16_t NI16;
typedef int32_t NI32;
typedef int64_t NI64;
typedef uint8_t NU8;
typedef uint16_t NU16;
typedef uint32_t NU32;
typedef uint64_t NU64;
#elif defined(HAVE_CSTDINT)
#ifndef USE_NIM_NAMESPACE
#  include <cstdint>
#endif
typedef std::int8_t NI8;
typedef std::int16_t NI16;
typedef std::int32_t NI32;
typedef std::int64_t NI64;
typedef std::uint8_t NU8;
typedef std::uint16_t NU16;
typedef std::uint32_t NU32;
typedef std::uint64_t NU64;
#else
/* Unknown compiler/version, do our best */
#ifdef __INT8_TYPE__
typedef __INT8_TYPE__ NI8;
#else
typedef signed char NI8;
#endif
#ifdef __INT16_TYPE__
typedef __INT16_TYPE__ NI16;
#else
typedef signed short int NI16;
#endif
#ifdef __INT32_TYPE__
typedef __INT32_TYPE__ NI32;
#else
typedef signed int NI32;
#endif
#ifdef __INT64_TYPE__
typedef __INT64_TYPE__ NI64;
#else
typedef long long int NI64;
#endif
/* XXX: Float128? */
#ifdef __UINT8_TYPE__
typedef __UINT8_TYPE__ NU8;
#else
typedef unsigned char NU8;
#endif
#ifdef __UINT16_TYPE__
typedef __UINT16_TYPE__ NU16;
#else
typedef unsigned short int NU16;
#endif
#ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ NU32;
#else
typedef unsigned int NU32;
#endif
#ifdef __UINT64_TYPE__
typedef __UINT64_TYPE__ NU64;
#else
typedef unsigned long long int NU64;
#endif
#endif

#ifdef NIM_INTBITS
#  if NIM_INTBITS == 64
typedef NI64 NI;
typedef NU64 NU;
#  elif NIM_INTBITS == 32
typedef NI32 NI;
typedef NU32 NU;
#  elif NIM_INTBITS == 16
typedef NI16 NI;
typedef NU16 NU;
#  elif NIM_INTBITS == 8
typedef NI8 NI;
typedef NU8 NU;
#  else
#    error "invalid bit width for int"
#  endif
#endif

#define NIM_TRUE true
#define NIM_FALSE false

#define _GNU_SOURCE

// Include math.h to use `NAN` that should be defined in C compilers supports C99.
#include <math.h>

// Define NAN in case math.h doesn't define it.
// NAN definition copied from math.h included in the Windows SDK version 10.0.14393.0
#ifndef NAN
#  ifndef _HUGE_ENUF
#    define _HUGE_ENUF  1e+300  // _HUGE_ENUF*_HUGE_ENUF must overflow
#  endif
#  define NAN_INFINITY ((float)(_HUGE_ENUF * _HUGE_ENUF))
#  define NAN ((float)(NAN_INFINITY * 0.0F))
#endif

#ifndef INF
#  ifdef INFINITY
#    define INF INFINITY
#  elif defined(HUGE_VAL)
#    define INF  HUGE_VAL
#  elif defined(_MSC_VER)
#    include <float.h>
#    define INF (DBL_MAX+DBL_MAX)
#  else
#    define INF (1.0 / 0.0)
#  endif
#endif

#if defined(__GNUC__) || defined(_MSC_VER)
#  define IL64(x) x##LL
#else /* works only without LL */
#  define IL64(x) ((NI64)x)
#endif


/* ------------ ignore typical warnings in Nim-generated files ------------- */
#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic ignored "-Wswitch-bool"
#  pragma GCC diagnostic ignored "-Wformat"
#  pragma GCC diagnostic ignored "-Wpointer-sign"
#  if defined(__clang__)
#    pragma GCC diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"
#  else
#    pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
#  endif
#endif



/* ------------------------------------------------------------------- */
#ifdef  __cplusplus
#  define NIM_EXTERNC extern "C"
#else
#  define NIM_EXTERNC
#endif

#if defined(WIN32) || defined(_WIN32) /* only Windows has this mess... */
#  define N_LIB_PRIVATE
#  define N_CDECL(rettype, name) rettype __cdecl name
#  define N_STDCALL(rettype, name) rettype __stdcall name
#  define N_SYSCALL(rettype, name) rettype __syscall name
#  define N_FASTCALL(rettype, name) rettype __fastcall name
#  define N_THISCALL(rettype, name) rettype __thiscall name
#  define N_SAFECALL(rettype, name) rettype __stdcall name
/* function pointers with calling convention: */
#  define N_CDECL_PTR(rettype, name) rettype (__cdecl *name)
#  define N_STDCALL_PTR(rettype, name) rettype (__stdcall *name)
#  define N_SYSCALL_PTR(rettype, name) rettype (__syscall *name)
#  define N_FASTCALL_PTR(rettype, name) rettype (__fastcall *name)
#  define N_THISCALL_PTR(rettype, name) rettype (__thiscall *name)
#  define N_SAFECALL_PTR(rettype, name) rettype (__stdcall *name)

#  ifdef __EMSCRIPTEN__
#    define N_LIB_EXPORT  NIM_EXTERNC __declspec(dllexport) __attribute__((used))
#    define N_LIB_EXPORT_VAR  __declspec(dllexport) __attribute__((used))
#  else
#    define N_LIB_EXPORT  NIM_EXTERNC __declspec(dllexport)
#    define N_LIB_EXPORT_VAR  __declspec(dllexport)
#  endif
#  define N_LIB_IMPORT  extern __declspec(dllimport)
#else
#  define N_LIB_PRIVATE __attribute__((visibility("hidden")))
#  if defined(__GNUC__)
#    define N_CDECL(rettype, name) rettype name
#    define N_STDCALL(rettype, name) rettype name
#    define N_SYSCALL(rettype, name) rettype name
#    define N_FASTCALL(rettype, name) __attribute__((fastcall)) rettype name
#    define N_SAFECALL(rettype, name) rettype name
/*   function pointers with calling convention: */
#    define N_CDECL_PTR(rettype, name) rettype (*name)
#    define N_STDCALL_PTR(rettype, name) rettype (*name)
#    define N_SYSCALL_PTR(rettype, name) rettype (*name)
#    define N_FASTCALL_PTR(rettype, name) __attribute__((fastcall)) rettype (*name)
#    define N_SAFECALL_PTR(rettype, name) rettype (*name)
#  else
#    define N_CDECL(rettype, name) rettype name
#    define N_STDCALL(rettype, name) rettype name
#    define N_SYSCALL(rettype, name) rettype name
#    define N_FASTCALL(rettype, name) rettype name
#    define N_SAFECALL(rettype, name) rettype name
/*   function pointers with calling convention: */
#    define N_CDECL_PTR(rettype, name) rettype (*name)
#    define N_STDCALL_PTR(rettype, name) rettype (*name)
#    define N_SYSCALL_PTR(rettype, name) rettype (*name)
#    define N_FASTCALL_PTR(rettype, name) rettype (*name)
#    define N_SAFECALL_PTR(rettype, name) rettype (*name)
#  endif
#  ifdef __EMSCRIPTEN__
#    define N_LIB_EXPORT NIM_EXTERNC __attribute__((visibility("default"), used))
#    define N_LIB_EXPORT_VAR  __attribute__((visibility("default"), used))
#  else
#    define N_LIB_EXPORT NIM_EXTERNC __attribute__((visibility("default")))
#    define N_LIB_EXPORT_VAR  __attribute__((visibility("default")))
#  endif
#  define N_LIB_IMPORT  extern
#endif

#if defined(__BORLANDC__) || defined(_MSC_VER) || defined(WIN32) || defined(_WIN32)
/* these compilers have a fastcall so use it: */
#  define N_NIMCALL(rettype, name) rettype __fastcall name
#  define N_NIMCALL_PTR(rettype, name) rettype (__fastcall *name)
#else
#  define N_NIMCALL(rettype, name) rettype name /* no modifier */
#  define N_NIMCALL_PTR(rettype, name) rettype (*name)
#endif

#define N_NOCONV(rettype, name) rettype name
/* specify no calling convention */
#define N_NOCONV_PTR(rettype, name) rettype (*name)

/* calling convention mess ----------------------------------------------- */
#if defined(__GNUC__) || defined(__TINYC__)
  /* these should support C99's inline */
#  define N_INLINE(rettype, name) inline rettype name
#elif defined(__BORLANDC__) || defined(_MSC_VER)
/* Borland's compiler is really STRANGE here; note that the __fastcall
   keyword cannot be before the return type, but __inline cannot be after
   the return type, so we do not handle this mess in the code generator
   but rather here. */
#  define N_INLINE(rettype, name) __inline rettype name
#else /* others are less picky: */
#  define N_INLINE(rettype, name) rettype __inline name
#endif

#define N_INLINE_PTR(rettype, name) rettype (*name)

#if defined(__GNUC__) || defined(__ICC__)
#  define N_NOINLINE __attribute__((__noinline__))
#elif defined(_MSC_VER)
#  define N_NOINLINE __declspec(noinline)
#else
#  define N_NOINLINE
#endif

#define N_NOINLINE_PTR(rettype, name) rettype (*name)

#if defined(_MSC_VER)
#  define NIM_ALIGN(x)  __declspec(align(x))
#  define NIM_ALIGNOF(x) __alignof(x)
#else
#  define NIM_ALIGN(x)  __attribute__((aligned(x)))
#  define NIM_ALIGNOF(x) __alignof__(x)
#endif

#include <stddef.h>


/*
  NIM_THREADVAR declaration based on
  https://stackoverflow.com/questions/18298280/how-to-declare-a-variable-as-thread-local-portably
*/
#if defined _WIN32
#  if defined _MSC_VER || defined __BORLANDC__
#    define NIM_THREADVAR __declspec(thread)
#  else
#    define NIM_THREADVAR __thread
#  endif
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112 && !defined __STDC_NO_THREADS__
#  define NIM_THREADVAR _Thread_local
#elif defined _WIN32 && ( \
       defined _MSC_VER || \
       defined __ICL || \
       defined __BORLANDC__ )
#  define NIM_THREADVAR __declspec(thread)
#elif defined(__TINYC__) || defined(__GENODE__)
#  define NIM_THREADVAR
/* note that ICC (linux) and Clang are covered by __GNUC__ */
#elif defined __GNUC__ || \
       defined __SUNPRO_C || \
       defined __xlC__
#  define NIM_THREADVAR __thread
#else
#  error "Cannot define NIM_THREADVAR"
#endif

/* define NIM_STATIC_ASSERT */
#if defined(__cplusplus)
#define NIM_STATIC_ASSERT(x, msg) static_assert((x), msg)
#else
#define NIM_STATIC_ASSERT(x, msg) _Static_assert((x), msg)
#endif

// Test to see if Nim and the C compiler agree on the size of a pointer.
NIM_STATIC_ASSERT(sizeof(NI) == sizeof(void*) && NIM_INTBITS == sizeof(NI)*8, "Pointer size mismatch between Nim and C/C++ backend. You probably need to setup the backend compiler for target CPU.");

N_INLINE(NB8, _Qlengc_div_sll_overflow)(long long int a, long long int b, long long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  if (a == (long long int)(((unsigned long long int)1) << (sizeof(long long int) * 8 - 1)) && b == -1) {
    *res = a;
    return NIM_TRUE;
  }
  *res = a / b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_div_sl_overflow)(long int a, long int b, long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  if (a == (long int)(((unsigned long int)1) << (sizeof(long int) * 8 - 1)) && b == -1) {
    *res = a;
    return NIM_TRUE;
  }
  *res = a / b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_div_ull_overflow)(unsigned long long int a, unsigned long long int b, unsigned long long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE; /* Overflow: division by zero */
  }
  *res = a / b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_div_ul_overflow)(unsigned long int a, unsigned long int b, unsigned long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a / b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_mod_sll_overflow)(long long int a, long long int b, long long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  if (a == (long long int)(((unsigned long long int)1) << (sizeof(long long int) * 8 - 1)) && b == -1) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a % b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_mod_sl_overflow)(long int a, long int b, long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  if (a == (long int)(((unsigned long int)1) << (sizeof(long int) * 8 - 1)) && b == -1) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a % b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_mod_ull_overflow)(unsigned long long int a, unsigned long long int b, unsigned long long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a % b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_mod_ul_overflow)(unsigned long int a, unsigned long int b, unsigned long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a % b;
  return NIM_FALSE;
}
typedef struct xint_0_xinat3x34{
  NB8 nan_0;
  NB8 neg_0;
  NU64 val_0;}
xint_0_xinat3x34;
extern void X60Qini_0_sysvq0asl(void);
NB8 X60QiniGuard_0_xinat3x34;
xint_0_xinat3x34 zero_0_xinat3x34(void){
  xint_0_xinat3x34 result_0;
  result_0 = (xint_0_xinat3x34){
    .nan_0 = NIM_FALSE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)0)}
  ;
  return result_0;}
NI64 asSigned_0_xinat3x34(xint_0_xinat3x34 x_2, NB8* err_0){
  NI64 result_4;
  result_4 = ((NI64)0);
  if (x_2.nan_0){
    (*err_0) = NIM_TRUE;}
  else {
    if (x_2.neg_0){
      if (((NU64)(((NU64)((NI64)IL64(9223372036854775807))) + ((NU64)1))) < x_2.val_0){
        (*err_0) = NIM_TRUE;}
      else {
        result_4 = ((NI64)-((NI64)x_2.val_0));}}
    else {
      if (((NU64)((NI64)IL64(9223372036854775807))) < x_2.val_0){
        (*err_0) = NIM_TRUE;}
      else {
        result_4 = ((NI64)x_2.val_0);}}}
  return result_4;}
NU64 asUnsigned_0_xinat3x34(xint_0_xinat3x34 x_3, NB8* err_1){
  NU64 result_5;
  result_5 = ((NU64)0u);
  if (x_3.nan_0){
    (*err_1) = NIM_TRUE;}
  else {
    NB8 X60Qx_7;
    if (x_3.neg_0){
      X60Qx_7 = (!(x_3.val_0 == ((NU64)0u)));}
    else {
      X60Qx_7 = NIM_FALSE;}
    if (X60Qx_7){
      (*err_1) = NIM_TRUE;}
    else {
      result_5 = x_3.val_0;}}
  return result_5;}
xint_0_xinat3x34 minusQ_0_xinat3x34(xint_0_xinat3x34 a_0){
  xint_0_xinat3x34 result_6;
  result_6 = (xint_0_xinat3x34){
    .nan_0 = a_0.nan_0, .neg_0 = (!a_0.neg_0), .val_0 = a_0.val_0}
  ;
  return result_6;}
xint_0_xinat3x34 div_0_xinat3x34(xint_0_xinat3x34 a_5, xint_0_xinat3x34 b_3){
  xint_0_xinat3x34 result_10;
  NB8 X60Qx_14;
  NB8 X60Qx_15;
  if (a_5.nan_0){
    X60Qx_15 = NIM_TRUE;}
  else {
    X60Qx_15 = b_3.nan_0;}
  if (X60Qx_15){
    X60Qx_14 = NIM_TRUE;}
  else {
    X60Qx_14 = (b_3.val_0 == ((NU64)0));}
  if (X60Qx_14){
    result_10 = (xint_0_xinat3x34){
      .nan_0 = NIM_TRUE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)0u)}
    ;
    return result_10;}
  result_10 = (xint_0_xinat3x34){
    .nan_0 = NIM_FALSE, .neg_0 = (!(a_5.neg_0 == b_3.neg_0)), .val_0 = ((NU64)(a_5.val_0 / b_3.val_0))}
  ;
  return result_10;}
xint_0_xinat3x34 createXint_0_xinat3x34(NI64 x_4){
  xint_0_xinat3x34 result_12;
  xint_0_xinat3x34 X60Qx_1;
  if (x_4 == ((NI64)(IL64(-9223372036854775807) - IL64(1)))){
    X60Qx_1 = (xint_0_xinat3x34){
      .nan_0 = NIM_FALSE, .neg_0 = NIM_TRUE, .val_0 = ((NU64)(((NU64)((NI64)IL64(9223372036854775807))) + ((NU64)1u)))}
    ;}
  else {
    if (x_4 < ((NI64)0)){
      X60Qx_1 = (xint_0_xinat3x34){
        .nan_0 = NIM_FALSE, .neg_0 = NIM_TRUE, .val_0 = ((NU64)((NI64)-x_4))}
      ;}
    else {
      X60Qx_1 = (xint_0_xinat3x34){
        .nan_0 = NIM_FALSE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)x_4)}
      ;}}
  result_12 = X60Qx_1;
  return result_12;}
xint_0_xinat3x34 shr_0_xinat3x34(xint_0_xinat3x34 a_8, NI32 b_5){
  xint_0_xinat3x34 result_14;
  NB8 X60Qx_20;
  if (a_8.nan_0){
    X60Qx_20 = NIM_TRUE;}
  else {
    X60Qx_20 = (b_5 < 0);}
  if (X60Qx_20){
    result_14 = (xint_0_xinat3x34){
      .nan_0 = NIM_TRUE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)0u)}
    ;
    return result_14;}
  result_14 = (xint_0_xinat3x34){
    .nan_0 = NIM_FALSE, .neg_0 = a_8.neg_0, .val_0 = ((NU64)(a_8.val_0 >> b_5))}
  ;
  return result_14;}
xint_0_xinat3x34 not_0_xinat3x34(xint_0_xinat3x34 a_12){
  xint_0_xinat3x34 result_18;
  result_18 = (xint_0_xinat3x34){
    .nan_0 = a_12.nan_0, .neg_0 = a_12.neg_0, .val_0 = ((NU64) ~ a_12.val_0)}
  ;
  return result_18;}
xint_0_xinat3x34 mod_0_xinat3x34(xint_0_xinat3x34 a_13, xint_0_xinat3x34 b_9){
  xint_0_xinat3x34 result_19;
  NB8 X60Qx_26;
  NB8 X60Qx_27;
  if (a_13.nan_0){
    X60Qx_27 = NIM_TRUE;}
  else {
    X60Qx_27 = b_9.nan_0;}
  if (X60Qx_27){
    X60Qx_26 = NIM_TRUE;}
  else {
    X60Qx_26 = (b_9.val_0 == ((NU64)0));}
  if (X60Qx_26){
    result_19 = (xint_0_xinat3x34){
      .nan_0 = NIM_TRUE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)0u)}
    ;
    return result_19;}
  result_19 = (xint_0_xinat3x34){
    .nan_0 = NIM_FALSE, .neg_0 = a_13.neg_0, .val_0 = ((NU64)(a_13.val_0 % b_9.val_0))}
  ;
  return result_19;}
xint_0_xinat3x34 mask_0_xinat3x34(xint_0_xinat3x34 a_14, NI32 bits_0, NB8 signed_0){
  xint_0_xinat3x34 result_20;
  NB8 X60Qx_28;
  NB8 X60Qx_29;
  if (a_14.nan_0){
    X60Qx_29 = NIM_TRUE;}
  else {
    X60Qx_29 = (bits_0 < 0);}
  if (X60Qx_29){
    X60Qx_28 = NIM_TRUE;}
  else {
    X60Qx_28 = (64 < bits_0);}
  if (X60Qx_28){
    result_20 = (xint_0_xinat3x34){
      .nan_0 = NIM_TRUE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)0u)}
    ;
    return result_20;}
  NU64 X60Qx_2;
  if (bits_0 == 64){
    X60Qx_2 = ((NU64)18446744073709551615ull);}
  else {
    X60Qx_2 = ((NU64)(((NU64)(((NU64)1u) << bits_0)) - ((NU64)1)));}
  NU64 mask_0 = X60Qx_2;
  result_20 = (xint_0_xinat3x34){
    .nan_0 = NIM_FALSE, .neg_0 = a_14.neg_0, .val_0 = ((NU64)(a_14.val_0 & mask_0))}
  ;
  NB8 X60Qx_30;
  if (signed_0){
    X60Qx_30 = (!(((NU64)(result_20.val_0 >> ((NI32)(bits_0 - 1)))) == ((NU64)0)));}
  else {
    X60Qx_30 = NIM_FALSE;}
  if (X60Qx_30){
    result_20.val_0 = ((NU64)(((NU64)(((NU64) ~ result_20.val_0) & mask_0)) + ((NU64)1)));
    result_20.neg_0 = (!result_20.neg_0);}
  return result_20;}
NB8 eqQ_0_xinat3x34(xint_0_xinat3x34 a_18, xint_0_xinat3x34 b_10){
  NB8 result_24;
  if (a_18.nan_0){
    result_24 = b_10.nan_0;
    return result_24;}
  else {
    if (b_10.nan_0){
      return NIM_FALSE;}}
  NB8 X60Qx_37;
  if (a_18.neg_0 == b_10.neg_0){
    X60Qx_37 = (a_18.val_0 == b_10.val_0);}
  else {
    X60Qx_37 = NIM_FALSE;}
  result_24 = X60Qx_37;
  return result_24;}
NB8 ltQ_0_xinat3x34(xint_0_xinat3x34 a_19, xint_0_xinat3x34 b_11){
  NB8 result_25;
  NB8 X60Qx_38;
  if (a_19.nan_0){
    X60Qx_38 = NIM_TRUE;}
  else {
    X60Qx_38 = b_11.nan_0;}
  if (X60Qx_38){
    return NIM_FALSE;}
  NB8 X60Qx_39;
  if (a_19.neg_0){
    X60Qx_39 = (!b_11.neg_0);}
  else {
    X60Qx_39 = NIM_FALSE;}
  if (X60Qx_39){
    return NIM_TRUE;}
  NB8 X60Qx_40;
  if ((!a_19.neg_0)){
    X60Qx_40 = b_11.neg_0;}
  else {
    X60Qx_40 = NIM_FALSE;}
  if (X60Qx_40){
    return NIM_FALSE;}
  NB8 X60Qx_3;
  if (a_19.neg_0){
    X60Qx_3 = (b_11.val_0 < a_19.val_0);}
  else {
    X60Qx_3 = (a_19.val_0 < b_11.val_0);}
  result_25 = X60Qx_3;
  return result_25;}
NB8 leQ_0_xinat3x34(xint_0_xinat3x34 a_20, xint_0_xinat3x34 b_12){
  NB8 result_26;
  NB8 X60Qx_41;
  NB8 X60Qx_42 = ltQ_0_xinat3x34(a_20, b_12);
  if (X60Qx_42){
    X60Qx_41 = NIM_TRUE;}
  else {
    NB8 X60Qx_43 = eqQ_0_xinat3x34(a_20, b_12);
    X60Qx_41 = X60Qx_43;}
  result_26 = X60Qx_41;
  return result_26;}
NF64 toFloat64_0_xinat3x34(xint_0_xinat3x34 x_7){
  NF64 result_32;
  NF64 X60Qx_6;
  if (x_7.nan_0){
    X60Qx_6 = NAN;}
  else {
    if (x_7.neg_0){
      X60Qx_6 = ((NF64)-((NF64)x_7.val_0));}
    else {
      X60Qx_6 = ((NF64)x_7.val_0);}}
  result_32 = X60Qx_6;
  return result_32;}
void X60Qini_0_xinat3x34(void){
  if (X60QiniGuard_0_xinat3x34){
    return;}
  X60QiniGuard_0_xinat3x34 = NIM_TRUE;
  X60Qini_0_sysvq0asl();}
