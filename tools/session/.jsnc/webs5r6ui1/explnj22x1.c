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
#include <stdio.h>
#include <string.h>
typedef struct SemContext_0_sempjk6bn1 SemContext_0_sempjk6bn1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX53emX52outineX4fbj0sempjk6bn1_sempjk6bn1 X60Qt_0_IArefSX53emX52outineX4fbj0sempjk6bn1_sempjk6bn1;
typedef struct X60Qt_0_IArefSX53copeX4fbj0symiqlwtg1_sempjk6bn1 X60Qt_0_IArefSX53copeX4fbj0symiqlwtg1_sempjk6bn1;
typedef struct X60Qt_0_IArefSX50rogramX43ontextX4fbj0sempjk6bn1_sempjk6bn1 X60Qt_0_IArefSX50rogramX43ontextX4fbj0sempjk6bn1_sempjk6bn1;
typedef struct InstRequest_0_sempjk6bn1 InstRequest_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportedX4dodule0sempjk6bn1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportedX4dodule0sempjk6bn1_sempjk6bn1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX54okenX42uf0nifb6mq6y1_sempjk6bn1 X60Qt_0_IAtupleSstring0sysvq0aslSX54okenX42uf0nifb6mq6y1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi;
typedef struct X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1Sstring0sysvq0aslZSR9_sempjk6bn1 X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1Sstring0sysvq0aslZSR9_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX50ackedX4cineX49nfo0linxafkvx1Abool_repa2y0od1 X60Qt_0_IAtupleSX50ackedX4cineX49nfo0linxafkvx1Abool_repa2y0od1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX48ooksX50erX54ype0prorcx25w1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX48ooksX50erX54ype0prorcx25w1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43lassX45ntry0sempjk6bn1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43lassX45ntry0sempjk6bn1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportX46ilter0prorcx25w1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportX46ilter0prorcx25w1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX50luginX4fbj0sempjk6bn1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX50luginX4fbj0sempjk6bn1_sempjk6bn1;
typedef struct PluginObj_0_sempjk6bn1 PluginObj_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1SX53trX49d0R19ZSseq0X49n6doa_sempjk6bn1 X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1SX53trX49d0R19ZSseq0X49n6doa_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1;
typedef struct TokenBuf_0_nifb6mq6y1 TokenBuf_0_nifb6mq6y1;
typedef struct Cursor_0_nifb6mq6y1 Cursor_0_nifb6mq6y1;
typedef struct xint_0_xinat3x34 xint_0_xinat3x34;
typedef struct Table_0_I5rl962_sempjk6bn1 Table_0_I5rl962_sempjk6bn1;
typedef struct Item_0_sempjk6bn1 Item_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sstring0sysvq0asl_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sstring0sysvq0asl_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1;
typedef struct Table_0_I153b76_sigekpubi1 Table_0_I153b76_sigekpubi1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1;
typedef struct MethodIndexEntry_0_sempjk6bn1 MethodIndexEntry_0_sempjk6bn1;
typedef struct Sym_0_symiqlwtg1 Sym_0_symiqlwtg1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct EvalContext_0_explnj22x1{
  SemContext_0_sempjk6bn1* c_0;
  Cursor_0_nifb6mq6y1 trueValue_0;
  Cursor_0_nifb6mq6y1 falseValue_0;
  Cursor_0_nifb6mq6y1 expectedType_0;
  NB8 noExecute_0;}
EvalContext_0_explnj22x1;
typedef struct xint_0_xinat3x34{
  NB8 nan_0;
  NB8 neg_0;
  NU64 val_0;}
xint_0_xinat3x34;
typedef struct Bounds_0_explnj22x1{
  xint_0_xinat3x34 lo_0;
  xint_0_xinat3x34 hi_0;}
Bounds_0_explnj22x1;
typedef struct seq_0_Incv1wn_arecyyj7v{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_arecyyj7v;
typedef struct openArray_0_Is74e021_explnj22x1{
  NU8* a_0;
  NI32 len_0;}
openArray_0_Is74e021_explnj22x1;
typedef struct seq_0_Iotb7mc_ast8ri79k{
  NI32 len_0;
  NI64* data_0;}
seq_0_Iotb7mc_ast8ri79k;
typedef struct seq_0_Iwy7s2o_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iwy7s2o_ast8ri79k;
typedef struct BiTable_0_Itvq7bk_ast8ri79k{
  seq_0_Iotb7mc_ast8ri79k vals_0;
  seq_0_Iwy7s2o_ast8ri79k keys_0;}
BiTable_0_Itvq7bk_ast8ri79k;
typedef struct seq_0_Ijmiee61_ast8ri79k{
  NI32 len_0;
  NU64* data_0;}
seq_0_Ijmiee61_ast8ri79k;
typedef struct seq_0_Ipw48je1_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Ipw48je1_ast8ri79k;
typedef struct BiTable_0_Itxao711_ast8ri79k{
  seq_0_Ijmiee61_ast8ri79k vals_0;
  seq_0_Ipw48je1_ast8ri79k keys_0;}
BiTable_0_Itxao711_ast8ri79k;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Izov3yo_ast8ri79k keys_0;}
BiTable_0_Ipgo74p_ast8ri79k;
typedef struct seq_0_Isoawlw1_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Isoawlw1_ast8ri79k;
typedef struct BiTable_0_Iojfwmy1_ast8ri79k{
  seq_0_Ijmiee61_ast8ri79k vals_0;
  seq_0_Isoawlw1_ast8ri79k keys_0;}
BiTable_0_Iojfwmy1_ast8ri79k;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
typedef struct X60Qt_0_IAarrayAuS8ZS43_ast8ri79k{
  NU8 a[43];}
X60Qt_0_IAarrayAuS8ZS43_ast8ri79k;
typedef struct X60Qt_0_IAarrayAuS8ZS27_decqocs071{
  NU8 a[27];}
X60Qt_0_IAarrayAuS8ZS27_decqocs071;
typedef struct X60Qt_0_IAarrayAuS8ZS11_decqocs071{
  NU8 a[11];}
X60Qt_0_IAarrayAuS8ZS11_decqocs071;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct seq_0_Iafyozp_sempjk6bn1{
  NI32 len_0;
  InstRequest_0_sempjk6bn1* data_0;}
seq_0_Iafyozp_sempjk6bn1;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef struct seq_0_Ivtzsw31_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportedX4dodule0sempjk6bn1_sempjk6bn1* data_0;}
seq_0_Ivtzsw31_sempjk6bn1;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_I89hz581_sempjk6bn1{
  seq_0_Ivtzsw31_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_I89hz581_sempjk6bn1;
typedef struct seq_0_Io4pvgy1_nifb6mq6y1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Io4pvgy1_nifb6mq6y1;
typedef struct seq_0_Izphk88_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1* data_0;}
seq_0_Izphk88_prorcx25w1;
typedef struct Table_0_I4dbdda_prorcx25w1{
  seq_0_Izphk88_prorcx25w1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_I4dbdda_prorcx25w1;
typedef struct seq_0_Ix7ee6h_obs4v9ato1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* data_0;}
seq_0_Ix7ee6h_obs4v9ato1;
typedef struct Table_0_Idzlvr_obs4v9ato1{
  seq_0_Ix7ee6h_obs4v9ato1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Idzlvr_obs4v9ato1;
typedef struct BuiltinTypes_0_buiyylk1h1{
  TokenBuf_0_nifb6mq6y1 mem_0;
  Cursor_0_nifb6mq6y1 autoType_0;
  Cursor_0_nifb6mq6y1 stringType_0;
  Cursor_0_nifb6mq6y1 intType_0;
  Cursor_0_nifb6mq6y1 uintType_0;
  Cursor_0_nifb6mq6y1 floatType_0;
  Cursor_0_nifb6mq6y1 boolType_0;
  Cursor_0_nifb6mq6y1 charType_0;
  Cursor_0_nifb6mq6y1 voidType_0;
  Cursor_0_nifb6mq6y1 nilType_0;
  Cursor_0_nifb6mq6y1 int8Type_0;
  Cursor_0_nifb6mq6y1 int16Type_0;
  Cursor_0_nifb6mq6y1 int32Type_0;
  Cursor_0_nifb6mq6y1 int64Type_0;
  Cursor_0_nifb6mq6y1 uint8Type_0;
  Cursor_0_nifb6mq6y1 uint16Type_0;
  Cursor_0_nifb6mq6y1 uint32Type_0;
  Cursor_0_nifb6mq6y1 uint64Type_0;
  Cursor_0_nifb6mq6y1 float32Type_0;
  Cursor_0_nifb6mq6y1 float64Type_0;
  Cursor_0_nifb6mq6y1 emptyTupleType_0;
  Cursor_0_nifb6mq6y1 untypedType_0;
  Cursor_0_nifb6mq6y1 cstringType_0;
  Cursor_0_nifb6mq6y1 vtableType_0;
  Cursor_0_nifb6mq6y1 continuationType_0;}
BuiltinTypes_0_buiyylk1h1;
typedef struct seq_0_Irijhpk1_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX54okenX42uf0nifb6mq6y1_sempjk6bn1* data_0;}
seq_0_Irijhpk1_sempjk6bn1;
typedef struct Table_0_I1dz4p91_sempjk6bn1{
  seq_0_Irijhpk1_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_I1dz4p91_sempjk6bn1;
typedef struct seq_0_I7cgnoo1_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi* data_0;}
seq_0_I7cgnoo1_sempjk6bn1;
typedef struct Table_0_Id70lot_sempjk6bn1{
  seq_0_I7cgnoo1_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Id70lot_sempjk6bn1;
typedef struct seq_0_I8j02aj_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1Sstring0sysvq0aslZSR9_sempjk6bn1* data_0;}
seq_0_I8j02aj_sempjk6bn1;
typedef struct Table_0_Irghkpt1_sempjk6bn1{
  seq_0_I8j02aj_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Irghkpt1_sempjk6bn1;
typedef NU8 SemPhase_0_prorcx25w1;

#define SemcheckTopLevelSyms_0_prorcx25w1 ((NU8)0)
#define SemcheckSignaturesInProgress_0_prorcx25w1 ((NU8)1)
#define SemcheckSignatures_0_prorcx25w1 ((NU8)2)
#define SemcheckBodiesInProgress_0_prorcx25w1 ((NU8)3)
#define SemcheckBodies_0_prorcx25w1 ((NU8)4)
typedef struct seq_0_Izjcib2_repa2y0od1{
  NI32 len_0;
  X60Qt_0_IAtupleSX50ackedX4cineX49nfo0linxafkvx1Abool_repa2y0od1* data_0;}
seq_0_Izjcib2_repa2y0od1;
typedef struct Table_0_Ie7idqg_repa2y0od1{
  seq_0_Izjcib2_repa2y0od1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ie7idqg_repa2y0od1;
typedef struct HashSet_0_Iusf0fw1_repa2y0od1{
  Table_0_Ie7idqg_repa2y0od1 t_0;}
HashSet_0_Iusf0fw1_repa2y0od1;
typedef struct MetaInfo_0_sempjk6bn1{
  seq_0_Ixdx2fh1_aow7lb5cq1 includedFiles_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 importedFiles_0;}
MetaInfo_0_sempjk6bn1;
typedef struct seq_0_Im9jzzo_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX48ooksX50erX54ype0prorcx25w1_sempjk6bn1* data_0;}
seq_0_Im9jzzo_sempjk6bn1;
typedef struct Table_0_Iw0ekpv_sempjk6bn1{
  seq_0_Im9jzzo_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Iw0ekpv_sempjk6bn1;
typedef struct seq_0_Idyps081_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1* data_0;}
seq_0_Idyps081_prorcx25w1;
typedef struct Table_0_I2pi31q1_prorcx25w1{
  seq_0_Idyps081_prorcx25w1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_I2pi31q1_prorcx25w1;
typedef struct seq_0_Ig3ia49_nifa1znj21{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21* data_0;}
seq_0_Ig3ia49_nifa1znj21;
typedef struct seq_0_Iu6qog7_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43lassX45ntry0sempjk6bn1_sempjk6bn1* data_0;}
seq_0_Iu6qog7_sempjk6bn1;
typedef struct Table_0_Id6j12r1_sempjk6bn1{
  seq_0_Iu6qog7_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Id6j12r1_sempjk6bn1;
typedef struct seq_0_I4v4ahw1_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportX46ilter0prorcx25w1_sempjk6bn1* data_0;}
seq_0_I4v4ahw1_sempjk6bn1;
typedef struct Table_0_I51s2r71_sempjk6bn1{
  seq_0_I4v4ahw1_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_I51s2r71_sempjk6bn1;
typedef struct seq_0_Ic9cn7e1_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax* data_0;}
seq_0_Ic9cn7e1_intzsnzax;
typedef struct Table_0_Ibw7a2q1_intzsnzax{
  seq_0_Ic9cn7e1_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ibw7a2q1_intzsnzax;
typedef struct HashSet_0_Ilwf8c01_sempjk6bn1{
  Table_0_Ibw7a2q1_intzsnzax t_0;}
HashSet_0_Ilwf8c01_sempjk6bn1;
typedef struct seq_0_I0i3btg1_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1* data_0;}
seq_0_I0i3btg1_prorcx25w1;
typedef struct Table_0_Ik52dhu1_prorcx25w1{
  seq_0_I0i3btg1_prorcx25w1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ik52dhu1_prorcx25w1;
typedef struct HashSet_0_Ipcrj631_prorcx25w1{
  Table_0_Ik52dhu1_prorcx25w1 t_0;}
HashSet_0_Ipcrj631_prorcx25w1;
typedef struct seq_0_I2vifoq_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX50luginX4fbj0sempjk6bn1_sempjk6bn1* data_0;}
seq_0_I2vifoq_sempjk6bn1;
typedef struct Table_0_Ibvzn1b1_sempjk6bn1{
  seq_0_I2vifoq_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ibvzn1b1_sempjk6bn1;
typedef struct seq_0_Izpn8xg_sempjk6bn1{
  NI32 len_0;
  PluginObj_0_sempjk6bn1* data_0;}
seq_0_Izpn8xg_sempjk6bn1;
typedef struct seq_0_I2e4yxa_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1SX53trX49d0R19ZSseq0X49n6doa_sempjk6bn1* data_0;}
seq_0_I2e4yxa_sempjk6bn1;
typedef struct Table_0_Itbx1h51_sempjk6bn1{
  seq_0_I2e4yxa_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Itbx1h51_sempjk6bn1;
typedef struct seq_0_Ie256m71_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1* data_0;}
seq_0_Ie256m71_sempjk6bn1;
typedef struct Table_0_Iy0uuh6_sempjk6bn1{
  seq_0_Ie256m71_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Iy0uuh6_sempjk6bn1;
typedef struct seq_0_I86hhvd_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1* data_0;}
seq_0_I86hhvd_sempjk6bn1;
typedef struct Table_0_Igu3pp_sempjk6bn1{
  seq_0_I86hhvd_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Igu3pp_sempjk6bn1;
typedef struct seq_0_I8t027x1_sempjk6bn1{
  NI32 len_0;
  TokenBuf_0_nifb6mq6y1* data_0;}
seq_0_I8t027x1_sempjk6bn1;
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZSX43ursor0nifb6mq6y1SR31AR0SX54okenX42uf0R40ZSX50ackedX4cineX49nfo0linxafkvx1Sstring0sysvq0aslAnimcallZAfalseZAR134_sempjk6bn1)(SemContext_0_sempjk6bn1*, Cursor_0_nifb6mq6y1, Cursor_0_nifb6mq6y1, TokenBuf_0_nifb6mq6y1*, NU32);
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZSX43ursor0R47SEAnimcallZAfalseZAR83_sempjk6bn1)(SemContext_0_sempjk6bn1*, TokenBuf_0_nifb6mq6y1*, Cursor_0_nifb6mq6y1);
typedef N_NIMCALL_PTR(xint_0_xinat3x34,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZSX43ursor0nifb6mq6y1AboolZSxint0xinat3x34AnimcallZAfalseZAR81_sempjk6bn1)(SemContext_0_sempjk6bn1*, Cursor_0_nifb6mq6y1, NB8);
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZSEAnimcallZAfalseZAR70_sempjk6bn1)(SemContext_0_sempjk6bn1*, TokenBuf_0_nifb6mq6y1*);
typedef N_NIMCALL_PTR(Cursor_0_nifb6mq6y1,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZSX43ursor0nifb6mq6y1SX54able0X495rl962SR31AnimcallZAfalseZAR82_sempjk6bn1)(SemContext_0_sempjk6bn1*, Cursor_0_nifb6mq6y1, Table_0_I5rl962_sempjk6bn1);
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX49tem0R19ZAsetSX53emX46lag0R19ZSEAnimcallZAfalseZAR106_sempjk6bn1)(SemContext_0_sempjk6bn1*, TokenBuf_0_nifb6mq6y1*, Item_0_sempjk6bn1*, NU16);
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX43ursor0R47ZAboolZSEAnimcallZAfalseZAR93_sempjk6bn1)(SemContext_0_sempjk6bn1*, TokenBuf_0_nifb6mq6y1*, Cursor_0_nifb6mq6y1*, NB8);
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX49tem0R19ZAiS32ZSX43ursor0R47SEAnimcallZAfalseZAR104_sempjk6bn1)(SemContext_0_sempjk6bn1*, TokenBuf_0_nifb6mq6y1*, Item_0_sempjk6bn1*, NI32, Cursor_0_nifb6mq6y1);
typedef NU8 TypeDeclContext_0_sempjk6bn1;

#define InLocalDecl_0_sempjk6bn1 ((NU8)0)
#define InTypeSection_0_sempjk6bn1 ((NU8)1)
#define InReturnTypeDecl_0_sempjk6bn1 ((NU8)2)
#define AllowValues_0_sempjk6bn1 ((NU8)3)
#define InGenericConstraint_0_sempjk6bn1 ((NU8)4)
#define InInvokeHead_0_sempjk6bn1 ((NU8)5)
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX43ursor0R47ZSX54ypeX44eclX43ontext0R19AboolZSX53ymX49d0nifh7u8pu1SEAnimcallZAfalseZAR140_sempjk6bn1)(SemContext_0_sempjk6bn1*, TokenBuf_0_nifb6mq6y1*, Cursor_0_nifb6mq6y1*, TypeDeclContext_0_sempjk6bn1, NB8, NU32);
typedef N_NIMCALL_PTR(NU32,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZSX50ackedX4cineX49nfo0linxafkvx1SX53ymX49d0nifh7u8pu1AnimcallZAfalseZAR121_sempjk6bn1)(SemContext_0_sempjk6bn1*, TokenBuf_0_nifb6mq6y1*, NU32);
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX49tem0R19ZSEAnimcallZAfalseZAR85_sempjk6bn1)(SemContext_0_sempjk6bn1*, TokenBuf_0_nifb6mq6y1*, Item_0_sempjk6bn1*);
typedef struct seq_0_Ifl84r8_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sstring0sysvq0asl_sempjk6bn1* data_0;}
seq_0_Ifl84r8_sempjk6bn1;
typedef struct Table_0_Ikw23fw_sempjk6bn1{
  seq_0_Ifl84r8_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ikw23fw_sempjk6bn1;
typedef struct seq_0_I4xiucd_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1* data_0;}
seq_0_I4xiucd_sempjk6bn1;
typedef struct Table_0_Is51thb_sempjk6bn1{
  seq_0_I4xiucd_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Is51thb_sempjk6bn1;
typedef struct SemContext_0_sempjk6bn1{
  X60Qt_0_IArefSX53emX52outineX4fbj0sempjk6bn1_sempjk6bn1* routine_0;
  X60Qt_0_IArefSX53copeX4fbj0symiqlwtg1_sempjk6bn1* currentScope_0;
  X60Qt_0_IArefSX50rogramX43ontextX4fbj0sempjk6bn1_sempjk6bn1* g_0;
  seq_0_Iafyozp_sempjk6bn1 procRequests_0;
  seq_0_In6doa_arecyyj7v typeInstDecls_0;
  TokenBuf_0_nifb6mq6y1 pendingSumtypes_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 includeStack_0;
  Table_0_I89hz581_sempjk6bn1 importedModules_0;
  NU32 selfModuleSym_0;
  seq_0_Io4pvgy1_nifb6mq6y1 instantiatedFrom_0;
  Table_0_I4dbdda_prorcx25w1 importTab_0;
  Table_0_Idzlvr_obs4v9ato1 globals_0;
  Table_0_Idzlvr_obs4v9ato1 locals_0;
  Table_0_Idzlvr_obs4v9ato1 fieldCounts_0;
  BuiltinTypes_0_buiyylk1h1 types_0;
  Table_0_I1dz4p91_sempjk6bn1 typeMem_0;
  Table_0_Id70lot_sempjk6bn1 instantiatedTypes_0;
  Table_0_Irghkpt1_sempjk6bn1 instantiatedProcs_0;
  string_0_sysvq0asl thisModuleSuffix_0;
  NU8 moduleFlags_0;
  NU16 features_0;
  Table_0_Id70lot_sempjk6bn1 processedModules_0;
  NI32 usedTypevars_0;
  SemPhase_0_prorcx25w1 phase_0;
  NB8 canSelfExec_0;
  NB8 checkedForWriteNifModule_0;
  NI32 inWhen_0;
  NI32 inUncheckedAccess_0;
  HashSet_0_Iusf0fw1_repa2y0od1 warnedSources_0;
  NI32 inSpeculativeArg_0;
  NI32 templateInstCounter_0;
  string_0_sysvq0asl commandLineArgs_0;
  MetaInfo_0_sempjk6bn1 meta_0;
  Table_0_Iw0ekpv_sempjk6bn1 typeHooks_0;
  Table_0_I2pi31q1_prorcx25w1 converters_0;
  seq_0_Ig3ia49_nifa1znj21 converterIndexMap_0;
  Table_0_Id6j12r1_sempjk6bn1 classes_0;
  Table_0_I51s2r71_sempjk6bn1 exports_0;
  HashSet_0_Ilwf8c01_sempjk6bn1 freshSyms_0;
  TokenBuf_0_nifb6mq6y1 toBuild_0;
  TokenBuf_0_nifb6mq6y1 toBundle_0;
  HashSet_0_Ipcrj631_prorcx25w1 unoverloadableMagics_0;
  NB8 debugAllowErrors_0;
  TokenBuf_0_nifb6mq6y1 pending_0;
  Table_0_Ibvzn1b1_sempjk6bn1 pendingTypePlugins_0;
  seq_0_Izpn8xg_sempjk6bn1 pendingModulePlugins_0;
  HashSet_0_Ipcrj631_prorcx25w1 pluginBlacklist_0;
  Table_0_Itbx1h51_sempjk6bn1 cachedTypeboundOps_0;
  Table_0_Iy0uuh6_sempjk6bn1 userPragmas_0;
  HashSet_0_Ipcrj631_prorcx25w1 customPragmaTemplates_0;
  Table_0_Igu3pp_sempjk6bn1 usingStmtMap_0;
  seq_0_I8t027x1_sempjk6bn1 pragmaStack_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZSX43ursor0nifb6mq6y1SR31AR0SX54okenX42uf0R40ZSX50ackedX4cineX49nfo0linxafkvx1Sstring0sysvq0aslAnimcallZAfalseZAR134_sempjk6bn1 executeExpr_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZSX43ursor0R47SEAnimcallZAfalseZAR83_sempjk6bn1 semStmtCallback_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZSX43ursor0nifb6mq6y1AboolZSxint0xinat3x34AnimcallZAfalseZAR81_sempjk6bn1 semGetSize_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZSEAnimcallZAfalseZAR70_sempjk6bn1 forceInstantiate_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZSX43ursor0nifb6mq6y1SX54able0X495rl962SR31AnimcallZAfalseZAR82_sempjk6bn1 semInstantiateType_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX49tem0R19ZAsetSX53emX46lag0R19ZSEAnimcallZAfalseZAR106_sempjk6bn1 semExprCB_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX43ursor0R47ZAboolZSEAnimcallZAfalseZAR93_sempjk6bn1 semStmtCB_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX49tem0R19ZAiS32ZSX43ursor0R47SEAnimcallZAfalseZAR104_sempjk6bn1 commonTypeCB_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX43ursor0R47ZSX54ypeX44eclX43ontext0R19AboolZSX53ymX49d0nifh7u8pu1SEAnimcallZAfalseZAR140_sempjk6bn1 semLocalTypeImplCB_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZSX50ackedX4cineX49nfo0linxafkvx1SX53ymX49d0nifh7u8pu1AnimcallZAfalseZAR121_sempjk6bn1 declareResultCB_0;
  X60Qt_0_IAmutSX53emX43ontext0sempjk6bn1ZAR0SX54okenX42uf0nifb6mq6y1ZAR0SX49tem0R19ZSEAnimcallZAfalseZAR85_sempjk6bn1 semEmitCB_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 passL_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 passC_0;
  TokenBuf_0_nifb6mq6y1 importSnippets_0;
  HashSet_0_Ilwf8c01_sempjk6bn1 genericInnerProcs_0;
  TokenBuf_0_nifb6mq6y1 expanded_0;
  Table_0_I4dbdda_prorcx25w1 forwardDecls_0;
  Table_0_Ikw23fw_sempjk6bn1 compiledMacros_0;
  HashSet_0_Ilwf8c01_sempjk6bn1 matchedForwardDecls_0;
  seq_0_I7cgnoo1_sempjk6bn1 deferredCyclicImports_0;
  NI32 inTypeInst_0;
  Table_0_Igu3pp_sempjk6bn1 deferredLocals_0;
  Table_0_Is51thb_sempjk6bn1 onDemandResolved_0;}
SemContext_0_sempjk6bn1;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef NU8 NimonySym_0_nimry5ra91;

#define NoSym_0_nimry5ra91 ((NU8)0)
#define GvarY_0_nimry5ra91 ((NU8)54)
#define TvarY_0_nimry5ra91 ((NU8)55)
#define VarY_0_nimry5ra91 ((NU8)56)
#define ParamY_0_nimry5ra91 ((NU8)57)
#define ConstY_0_nimry5ra91 ((NU8)58)
#define ResultY_0_nimry5ra91 ((NU8)59)
#define GletY_0_nimry5ra91 ((NU8)60)
#define TletY_0_nimry5ra91 ((NU8)61)
#define LetY_0_nimry5ra91 ((NU8)62)
#define CursorY_0_nimry5ra91 ((NU8)63)
#define PatternvarY_0_nimry5ra91 ((NU8)64)
#define TypevarY_0_nimry5ra91 ((NU8)65)
#define StaticTypevarY_0_nimry5ra91 ((NU8)66)
#define EfldY_0_nimry5ra91 ((NU8)67)
#define FldY_0_nimry5ra91 ((NU8)68)
#define GfldY_0_nimry5ra91 ((NU8)69)
#define ProcY_0_nimry5ra91 ((NU8)70)
#define FuncY_0_nimry5ra91 ((NU8)71)
#define IteratorY_0_nimry5ra91 ((NU8)72)
#define ConverterY_0_nimry5ra91 ((NU8)73)
#define MethodY_0_nimry5ra91 ((NU8)74)
#define MacroY_0_nimry5ra91 ((NU8)75)
#define TemplateY_0_nimry5ra91 ((NU8)76)
#define TypeY_0_nimry5ra91 ((NU8)77)
#define BlockY_0_nimry5ra91 ((NU8)78)
#define ModuleY_0_nimry5ra91 ((NU8)79)
#define CchoiceY_0_nimry5ra91 ((NU8)80)
typedef struct SemRoutine_Obj_0_sempjk6bn1{
  NimonySym_0_nimry5ra91 kind_0;
  NB8 hasDefer_0;
  NI32 inGeneric_0;
  NI32 inLoop_0;
  NI32 inBlock_0;
  NI32 inInst_0;
  NI32 inExcept_0;
  Cursor_0_nifb6mq6y1 returnType_0;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k pragmas_0;
  Cursor_0_nifb6mq6y1 raisesType_0;
  NU32 resId_0;
  X60Qt_0_IArefSX53emX52outineX4fbj0sempjk6bn1_sempjk6bn1* parent_0;}
SemRoutine_Obj_0_sempjk6bn1;
typedef struct X60Qt_0_IArefSX53emX52outineX4fbj0sempjk6bn1_sempjk6bn1{
  NI r_00;
  SemRoutine_Obj_0_sempjk6bn1 d_00;}
X60Qt_0_IArefSX53emX52outineX4fbj0sempjk6bn1_sempjk6bn1;
typedef struct seq_0_I05y7aa1_sig6uoro1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1* data_0;}
seq_0_I05y7aa1_sig6uoro1;
typedef struct Table_0_Iv58xy8_sig6uoro1{
  seq_0_I05y7aa1_sig6uoro1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Iv58xy8_sig6uoro1;
typedef struct seq_0_Ihrtntb_symiqlwtg1{
  NI32 len_0;
  Table_0_I153b76_sigekpubi1* data_0;}
seq_0_Ihrtntb_symiqlwtg1;
typedef NU8 ScopeKind_0_symiqlwtg1;

#define NormalScope_0_symiqlwtg1 ((NU8)0)
#define ToplevelScope_0_symiqlwtg1 ((NU8)1)
#define ImportScope_0_symiqlwtg1 ((NU8)2)
typedef struct Scope_Obj_0_symiqlwtg1{
  Table_0_Iv58xy8_sig6uoro1 tab_0;
  seq_0_Ihrtntb_symiqlwtg1 undo_0;
  X60Qt_0_IArefSX53copeX4fbj0symiqlwtg1_sempjk6bn1* up_0;
  ScopeKind_0_symiqlwtg1 kind_0;}
Scope_Obj_0_symiqlwtg1;
typedef struct X60Qt_0_IArefSX53copeX4fbj0symiqlwtg1_sempjk6bn1{
  NI r_00;
  Scope_Obj_0_symiqlwtg1 d_00;}
X60Qt_0_IArefSX53copeX4fbj0symiqlwtg1_sempjk6bn1;
typedef NU8 TSystemCPU_0_plac8hrin1;

#define cpuNone_0_plac8hrin1 ((NU8)0)
#define cpuI386_0_plac8hrin1 ((NU8)1)
#define cpuM68k_0_plac8hrin1 ((NU8)2)
#define cpuAlpha_0_plac8hrin1 ((NU8)3)
#define cpuPowerpc_0_plac8hrin1 ((NU8)4)
#define cpuPowerpc64_0_plac8hrin1 ((NU8)5)
#define cpuPowerpc64el_0_plac8hrin1 ((NU8)6)
#define cpuSparc_0_plac8hrin1 ((NU8)7)
#define cpuVm_0_plac8hrin1 ((NU8)8)
#define cpuHppa_0_plac8hrin1 ((NU8)9)
#define cpuIa64_0_plac8hrin1 ((NU8)10)
#define cpuAmd64_0_plac8hrin1 ((NU8)11)
#define cpuMips_0_plac8hrin1 ((NU8)12)
#define cpuMipsel_0_plac8hrin1 ((NU8)13)
#define cpuArm_0_plac8hrin1 ((NU8)14)
#define cpuArm64_0_plac8hrin1 ((NU8)15)
#define cpuJS_0_plac8hrin1 ((NU8)16)
#define cpuNimVM_0_plac8hrin1 ((NU8)17)
#define cpuAVR_0_plac8hrin1 ((NU8)18)
#define cpuMSP430_0_plac8hrin1 ((NU8)19)
#define cpuSparc64_0_plac8hrin1 ((NU8)20)
#define cpuMips64_0_plac8hrin1 ((NU8)21)
#define cpuMips64el_0_plac8hrin1 ((NU8)22)
#define cpuRiscV32_0_plac8hrin1 ((NU8)23)
#define cpuRiscV64_0_plac8hrin1 ((NU8)24)
#define cpuEsp_0_plac8hrin1 ((NU8)25)
#define cpuWasm32_0_plac8hrin1 ((NU8)26)
#define cpuE2k_0_plac8hrin1 ((NU8)27)
#define cpuLoongArch64_0_plac8hrin1 ((NU8)28)
typedef NU8 TSystemOS_0_plac8hrin1;

#define osNone_0_plac8hrin1 ((NU8)0)
#define osDos_0_plac8hrin1 ((NU8)1)
#define osWindows_0_plac8hrin1 ((NU8)2)
#define osOs2_0_plac8hrin1 ((NU8)3)
#define osLinux_0_plac8hrin1 ((NU8)4)
#define osMorphos_0_plac8hrin1 ((NU8)5)
#define osSkyos_0_plac8hrin1 ((NU8)6)
#define osSolaris_0_plac8hrin1 ((NU8)7)
#define osIrix_0_plac8hrin1 ((NU8)8)
#define osNetbsd_0_plac8hrin1 ((NU8)9)
#define osFreebsd_0_plac8hrin1 ((NU8)10)
#define osOpenbsd_0_plac8hrin1 ((NU8)11)
#define osDragonfly_0_plac8hrin1 ((NU8)12)
#define osCrossos_0_plac8hrin1 ((NU8)13)
#define osAix_0_plac8hrin1 ((NU8)14)
#define osPalmos_0_plac8hrin1 ((NU8)15)
#define osQQnx_0_plac8hrin1 ((NU8)16)
#define osAmiga_0_plac8hrin1 ((NU8)17)
#define osAtari_0_plac8hrin1 ((NU8)18)
#define osNetware_0_plac8hrin1 ((NU8)19)
#define osMacos_0_plac8hrin1 ((NU8)20)
#define osMacosx_0_plac8hrin1 ((NU8)21)
#define osIos_0_plac8hrin1 ((NU8)22)
#define osHaiku_0_plac8hrin1 ((NU8)23)
#define osAndroid_0_plac8hrin1 ((NU8)24)
#define osVxWorks_0_plac8hrin1 ((NU8)25)
#define osGenode_0_plac8hrin1 ((NU8)26)
#define osJS_0_plac8hrin1 ((NU8)27)
#define osNimVM_0_plac8hrin1 ((NU8)28)
#define osStandalone_0_plac8hrin1 ((NU8)29)
#define osNintendoSwitch_0_plac8hrin1 ((NU8)30)
#define osFreeRTOS_0_plac8hrin1 ((NU8)31)
#define osZephyr_0_plac8hrin1 ((NU8)32)
#define osNuttX_0_plac8hrin1 ((NU8)33)
#define osAny_0_plac8hrin1 ((NU8)34)
typedef NU8 TrackMode_0_niflk7bc8;

#define TrackNone_0_niflk7bc8 ((NU8)0)
#define TrackUsages_0_niflk7bc8 ((NU8)1)
#define TrackDef_0_niflk7bc8 ((NU8)2)
typedef struct TrackPosition_0_niflk7bc8{
  TrackMode_0_niflk7bc8 mode_0;
  NI32 line_0;
  NI32 col_0;
  string_0_sysvq0asl filename_0;}
TrackPosition_0_niflk7bc8;
typedef NU8 AppType_0_niflk7bc8;

#define appConsole_0_niflk7bc8 ((NU8)0)
#define appGui_0_niflk7bc8 ((NU8)1)
#define appLib_0_niflk7bc8 ((NU8)2)
#define appStaticLib_0_niflk7bc8 ((NU8)3)
typedef NU8 Backend_0_niflk7bc8;

#define backendC_0_niflk7bc8 ((NU8)0)
#define backendLLVM_0_niflk7bc8 ((NU8)1)
#define backendNative_0_niflk7bc8 ((NU8)2)
typedef NU8 OptLevel_0_niflk7bc8;

#define optDebug_0_niflk7bc8 ((NU8)0)
#define optNone_0_niflk7bc8 ((NU8)1)
#define optSize_0_niflk7bc8 ((NU8)2)
#define optSpeed_0_niflk7bc8 ((NU8)3)
typedef struct NifConfig_0_niflk7bc8{
  seq_0_Ixdx2fh1_aow7lb5cq1 defines_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 paths_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 nimblePaths_0;
  string_0_sysvq0asl baseDir_0;
  string_0_sysvq0asl nifcachePath_0;
  NI32 bits_0;
  NB8 compat_0;
  TSystemCPU_0_plac8hrin1 targetCPU_0;
  TSystemOS_0_plac8hrin1 targetOS_0;
  TrackPosition_0_niflk7bc8 toTrack_0;
  string_0_sysvq0asl cc_0;
  string_0_sysvq0asl linker_0;
  string_0_sysvq0asl ccKey_0;
  AppType_0_niflk7bc8 appType_0;
  Backend_0_niflk7bc8 backend_0;
  OptLevel_0_niflk7bc8 optLevel_0;
  NB8 noValidate_0;
  NB8 verbose_0;
  string_0_sysvq0asl outFile_0;
  string_0_sysvq0asl outDir_0;
  string_0_sysvq0asl checkFlags_0;}
NifConfig_0_niflk7bc8;
typedef struct ProgramContext_Obj_0_sempjk6bn1{
  NifConfig_0_niflk7bc8 config_0;}
ProgramContext_Obj_0_sempjk6bn1;
typedef struct X60Qt_0_IArefSX50rogramX43ontextX4fbj0sempjk6bn1_sempjk6bn1{
  NI r_00;
  ProgramContext_Obj_0_sempjk6bn1 d_00;}
X60Qt_0_IArefSX50rogramX43ontextX4fbj0sempjk6bn1_sempjk6bn1;
typedef struct seq_0_Iqf5su2_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1* data_0;}
seq_0_Iqf5su2_sempjk6bn1;
typedef struct Table_0_I5rl962_sempjk6bn1{
  seq_0_Iqf5su2_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_I5rl962_sempjk6bn1;
typedef struct InstRequest_0_sempjk6bn1{
  NU32 origin_0;
  NU32 targetSym_0;
  Table_0_I5rl962_sempjk6bn1 inferred_0;
  seq_0_Io4pvgy1_nifb6mq6y1 requestFrom_0;}
InstRequest_0_sempjk6bn1;
typedef struct ImportedModule_0_sempjk6bn1{
  string_0_sysvq0asl path_0;
  string_0_sysvq0asl fromPlugin_0;
  Table_0_I4dbdda_prorcx25w1 iface_0;
  Table_0_I51s2r71_sempjk6bn1 exports_0;}
ImportedModule_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportedX4dodule0sempjk6bn1_sempjk6bn1{
  NU32 fld_0;
  ImportedModule_0_sempjk6bn1 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportedX4dodule0sempjk6bn1_sempjk6bn1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1{
  NU32 fld_0;
  seq_0_In6doa_arecyyj7v fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX54okenX42uf0nifb6mq6y1_sempjk6bn1{
  string_0_sysvq0asl fld_0;
  TokenBuf_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSX54okenX42uf0nifb6mq6y1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi{
  string_0_sysvq0asl fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sstring0sysvq0asl_sempjk6bn1{
  NU32 fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sstring0sysvq0asl_sempjk6bn1;
typedef struct X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1Sstring0sysvq0aslZSR9_sempjk6bn1{
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sstring0sysvq0asl_sempjk6bn1 fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1Sstring0sysvq0aslZSR9_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX50ackedX4cineX49nfo0linxafkvx1Abool_repa2y0od1{
  NU32 fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX50ackedX4cineX49nfo0linxafkvx1Abool_repa2y0od1;
typedef struct X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S6_prorcx25w1{
  NU32 a[6];}
X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S6_prorcx25w1;
typedef struct HooksPerType_0_prorcx25w1{
  X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S6_prorcx25w1 a_0;}
HooksPerType_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX48ooksX50erX54ype0prorcx25w1_sempjk6bn1{
  NU32 fld_0;
  HooksPerType_0_prorcx25w1 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX48ooksX50erX54ype0prorcx25w1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1{
  NU32 fld_0;
  seq_0_In6doa_arecyyj7v fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21{
  NU32 fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21;
typedef struct seq_0_Idl3iy1_intzsnzax{
  NI32 len_0;
  MethodIndexEntry_0_sempjk6bn1* data_0;}
seq_0_Idl3iy1_intzsnzax;
typedef struct ClassEntry_0_sempjk6bn1{
  seq_0_Idl3iy1_intzsnzax methods_0;}
ClassEntry_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43lassX45ntry0sempjk6bn1_sempjk6bn1{
  NU32 fld_0;
  ClassEntry_0_sempjk6bn1 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43lassX45ntry0sempjk6bn1_sempjk6bn1;
typedef NU8 ImportFilterKind_0_prorcx25w1;

#define ImportAll_0_prorcx25w1 ((NU8)0)
#define FromImport_0_prorcx25w1 ((NU8)1)
#define ImportExcept_0_prorcx25w1 ((NU8)2)
typedef struct ImportFilter_0_prorcx25w1{
  ImportFilterKind_0_prorcx25w1 kind_0;
  HashSet_0_Ipcrj631_prorcx25w1 list_0;}
ImportFilter_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportX46ilter0prorcx25w1_sempjk6bn1{
  NU32 fld_0;
  ImportFilter_0_prorcx25w1 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportX46ilter0prorcx25w1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax{
  NU32 fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1{
  NU32 fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1;
typedef struct PluginObj_0_sempjk6bn1{
  NU32 path_0;
  NU32 info_0;}
PluginObj_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX50luginX4fbj0sempjk6bn1_sempjk6bn1{
  NU32 fld_0;
  PluginObj_0_sempjk6bn1 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX50luginX4fbj0sempjk6bn1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX53trX49d0R16_sempjk6bn1{
  NU32 fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX53trX49d0R16_sempjk6bn1;
typedef struct X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1SX53trX49d0R19ZSseq0X49n6doa_sempjk6bn1{
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX53trX49d0R16_sempjk6bn1 fld_0;
  seq_0_In6doa_arecyyj7v fld_1;}
X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1SX53trX49d0R19ZSseq0X49n6doa_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1{
  NU32 fld_0;
  TokenBuf_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1{
  NU32 fld_0;
  Cursor_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1;
typedef struct Item_0_sempjk6bn1{
  Cursor_0_nifb6mq6y1 n_0;
  Cursor_0_nifb6mq6y1 typ_0;
  NimonySym_0_nimry5ra91 kind_0;}
Item_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1{
  NU32 fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1;
typedef struct seq_0_Ixpi5il1_sig6uoro1{
  NI32 len_0;
  Sym_0_symiqlwtg1* data_0;}
seq_0_Ixpi5il1_sig6uoro1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1{
  NU32 fld_0;
  seq_0_Ixpi5il1_sig6uoro1 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1;
typedef struct seq_0_Ikcwp3r1_sigekpubi1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1* data_0;}
seq_0_Ikcwp3r1_sigekpubi1;
typedef struct Table_0_I153b76_sigekpubi1{
  seq_0_Ikcwp3r1_sigekpubi1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_I153b76_sigekpubi1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1{
  NU32 fld_0;
  Cursor_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1;
typedef struct MethodIndexEntry_0_sempjk6bn1{
  NU32 fn_0;
  NU32 signature_0;}
MethodIndexEntry_0_sempjk6bn1;
typedef struct Sym_0_symiqlwtg1{
  NimonySym_0_nimry5ra91 kind_0;
  NU32 name_0;
  NI32 pos_0;}
Sym_0_symiqlwtg1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1{
  NU32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1;
static inline NI32 high_3_Iscz9v3_explnj22x1(seq_0_Ipw48je1_ast8ri79k s_55);
static inline NU32* getQ_8_Il3tzqv_explnj22x1(seq_0_Ipw48je1_ast8ri79k s_56, NU32 i_40);
void enlarge_0_Isqiwlk1_explnj22x1(BiTable_0_Itxao711_ast8ri79k* t_34);
void setLen_0_Ig8m65q_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_60, NI32 newLen_12);
static inline void putQ_8_Ivcm3wy_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_63, NU32 i_44, NU32 elem_14);
static inline void add_0_I388oob1_explnj22x1(seq_0_Ijmiee61_ast8ri79k* s_64, NU64 elem_15);
NU32 getOrIncl_0_Ivbdpqo_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_35, NU64 v_10);
static inline NU8* rawData_0_Ihjhfzs_explnj22x1(seq_0_Incv1wn_arecyyj7v s_70);
static inline NI32 len_3_Itda5g31_explnj22x1(seq_0_Ipw48je1_ast8ri79k s_85);
static inline void newSeq_1_I63l1ps_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_86, NI32 newLen_22);
static inline void swap_0_I6g32k11_explnj22x1(seq_0_Ipw48je1_ast8ri79k* x_38, seq_0_Ipw48je1_ast8ri79k* y_9);
static inline NU32* getQ_7_I19xg9l1_explnj22x1(seq_0_Ipw48je1_ast8ri79k s_87, NI32 i_51);
static inline NU32 move_0_I1bmgmc_explnj22x1(NU32* x_39);
void shrink_0_Io5vz0b_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_88, NI32 newLen_23);
void growUnsafe_0_Iyoxsj_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_89, NI32 newLen_24);
NB8 resize_0_Ixmbspe1_explnj22x1(seq_0_Ijmiee61_ast8ri79k* dest_14, NI32 addedElements_8);
static inline NI32 high_3_I8k93cc_explnj22x1(seq_0_Isoawlw1_ast8ri79k s_92);
static inline NU32* getQ_8_Iboidd8_explnj22x1(seq_0_Isoawlw1_ast8ri79k s_93, NU32 i_53);
void enlarge_0_Ib1jipm1_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_38);
void setLen_0_Ixczj431_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_97, NI32 newLen_26);
static inline void putQ_8_Idqx2k6_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_100, NU32 i_57, NU32 elem_17);
seq_0_Ipw48je1_ast8ri79k newSeq_0_I4s8fn41_explnj22x1(NI32 size_19);
NB8 resize_0_Indszvc_explnj22x1(seq_0_Ipw48je1_ast8ri79k* dest_17, NI32 addedElements_11);
static inline NI32 len_3_Irzg08a_explnj22x1(seq_0_Isoawlw1_ast8ri79k s_104);
static inline void newSeq_1_Idmlkik1_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_105, NI32 newLen_29);
static inline void swap_0_Iqoh72v_explnj22x1(seq_0_Isoawlw1_ast8ri79k* x_42, seq_0_Isoawlw1_ast8ri79k* y_11);
static inline NU32* getQ_7_Iqb93l2_explnj22x1(seq_0_Isoawlw1_ast8ri79k s_106, NI32 i_61);
static inline NU32 move_0_Ipo4xyv_explnj22x1(NU32* x_43);
void shrink_0_I74bzl8_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_107, NI32 newLen_30);
void growUnsafe_0_I4lson61_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_108, NI32 newLen_31);
seq_0_Isoawlw1_ast8ri79k newSeq_0_Ielwdyx_explnj22x1(NI32 size_26);
NB8 resize_0_Iw4ackb_explnj22x1(seq_0_Isoawlw1_ast8ri79k* dest_19, NI32 addedElements_13);
static inline NU32 hash_4_has9tn57v(NU64 x_1);
static inline NU64* getQ_7_Ifaxado1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_10, NI32 i_7);
static inline NU32 nextTry_0_bitekkhcx1(NU32 h_0, NU32 maxHash_0);
static inline NB8 mustRehash_0_bitekkhcx1(NI32 length_0, NI32 counter_0);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
static inline NI32 memSizeInBytes_0_Infw7m1_arecyyj7v(NI32 size_27);
extern void* alloc_1_sysvq0asl(NI32 size_24);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
static inline void eQwasMoved_1_I52bdqo1_ast8ri79k(seq_0_Ipw48je1_ast8ri79k* s_60);
extern void eQdestroy_1_I7og8li_ast8ri79k(seq_0_Ipw48je1_ast8ri79k s_59);
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
static inline NI32 capInBytes_0_Iifs4oa_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_70);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline NI32 capInBytes_0_I4tsb7_ast8ri79k(seq_0_Ipw48je1_ast8ri79k s_71);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
static inline NI32 memSizeInBytes_0_Iom723i1_ast8ri79k(NI32 size_27);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
static inline void eQwasMoved_1_I5y4iq9_ast8ri79k(seq_0_Isoawlw1_ast8ri79k* s_63);
extern void eQdestroy_1_Iz0k69p1_ast8ri79k(seq_0_Isoawlw1_ast8ri79k s_62);
static inline NI32 memSizeInBytes_0_Itq6t0c1_ast8ri79k(NI32 size_29);
static inline NI32 capInBytes_0_Iktr4pk_ast8ri79k(seq_0_Isoawlw1_ast8ri79k s_72);
static inline NI32 memSizeInBytes_0_Iidgqw2_ast8ri79k(NI32 size_31);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_bitekkhcx1(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_nifjp9lau1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_decqocs071(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_xinat3x34(void);
extern void X60Qini_0_sempjk6bn1(void);
extern void X60Qini_0_renqb5hy11(void);
extern void X60Qini_0_buiyylk1h1(void);
extern void X60Qini_0_typurxiqa1(void);
extern void X60Qini_0_lanhy12io1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I15608149751057510534_explnj22x1 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "into requires cursor at ParLe"}
;
LongString_0_sysvq0asl const strlit_0_I13237575353761119172_explnj22x1 = {
  .fullLen_0 = 36, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "into: body must consume all children"}
;
NB8 X60QiniGuard_0_explnj22x1;
NU32 getOrIncl_0_Icm7gb1_explnj22x1(BiTable_0_Itxao711_ast8ri79k* t_24, NU64 v_7){
  NU32 result_47;
  NU32 origH_2 = hash_4_has9tn57v(v_7);
  NI32 X60Qx_1394 = high_3_Iscz9v3_explnj22x1((*t_24).keys_0);
  NU32 h_2 = ((NU32)(origH_2 & ((NU32)X60Qx_1394)));
  if ((!((*t_24).keys_0.len_0 == 0))){
    {
      while (NIM_TRUE){
        NU32* X60Qx_1395 = getQ_8_Il3tzqv_explnj22x1((*t_24).keys_0, h_2);
        NU32 litId_11 = (*X60Qx_1395);
        if ((!(((NU32)0u) < ((NU32)litId_11)))){
          goto whileStmtLabel_0;}
        NU32* X60Qx_1396 = getQ_8_Il3tzqv_explnj22x1((*t_24).keys_0, h_2);
        NU64* X60Qx_1397 = getQ_7_Ifaxado1_ast8ri79k((*t_24).vals_0, ((NI32)(((NI32)(*X60Qx_1396)) - ((NI32)1))));
        if (v_7 == (*X60Qx_1397)){
          return litId_11;}
        NI32 X60Qx_1398 = high_3_Iscz9v3_explnj22x1((*t_24).keys_0);
        NU32 X60Qx_1399 = nextTry_0_bitekkhcx1(h_2, ((NU32)X60Qx_1398));
        h_2 = X60Qx_1399;}}
    whileStmtLabel_0: ;
    NB8 X60Qx_1400 = mustRehash_0_bitekkhcx1((*t_24).keys_0.len_0, (*t_24).vals_0.len_0);
    if (X60Qx_1400){
      enlarge_0_Isqiwlk1_explnj22x1(t_24);
      NI32 X60Qx_1401 = high_3_Iscz9v3_explnj22x1((*t_24).keys_0);
      h_2 = ((NU32)(origH_2 & ((NU32)X60Qx_1401)));
      {
        while (NIM_TRUE){
          NU32* X60Qx_1402 = getQ_8_Il3tzqv_explnj22x1((*t_24).keys_0, h_2);
          NU32 litId_12 = (*X60Qx_1402);
          if ((!(((NU32)0u) < ((NU32)litId_12)))){
            goto whileStmtLabel_1;}
          NI32 X60Qx_1403 = high_3_Iscz9v3_explnj22x1((*t_24).keys_0);
          NU32 X60Qx_1404 = nextTry_0_bitekkhcx1(h_2, ((NU32)X60Qx_1403));
          h_2 = X60Qx_1404;}}
      whileStmtLabel_1: ;}}
  else {
    setLen_0_Ig8m65q_explnj22x1((&(*t_24).keys_0), 16);
    NI32 X60Qx_1405 = high_3_Iscz9v3_explnj22x1((*t_24).keys_0);
    h_2 = ((NU32)(origH_2 & ((NU32)X60Qx_1405)));}
  result_47 = ((NU32)((NI32)((*t_24).vals_0.len_0 + ((NI32)1))));
  putQ_8_Ivcm3wy_explnj22x1((&(*t_24).keys_0), h_2, result_47);
  add_0_I388oob1_explnj22x1((&(*t_24).vals_0), v_7);
  return result_47;}
static inline NU32 getOrIncl_1_Ijmj1s_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_26, NF64 v_8){
  NU32 result_48;
  NU64 X60Qx_1406;
  copyMem_0_sysvq0asl((&X60Qx_1406), (&v_8), sizeof(NU64));
  NU32 X60Qx_1407 = getOrIncl_0_Ivbdpqo_explnj22x1(t_26, X60Qx_1406);
  result_48 = X60Qx_1407;
  return result_48;}
static inline openArray_0_Is74e021_explnj22x1 toOpenArray_1_Itrkyf61_explnj22x1(seq_0_Incv1wn_arecyyj7v s_27){
  openArray_0_Is74e021_explnj22x1 result_52;
  NU8* X60Qx_1412 = rawData_0_Ihjhfzs_explnj22x1(s_27);
  result_52 = (openArray_0_Is74e021_explnj22x1){
    .a_0 = X60Qx_1412, .len_0 = s_27.len_0}
  ;
  return result_52;}
seq_0_Incv1wn_arecyyj7v newSeq_0_Ivbxvoi1_explnj22x1(NI32 size_3){
  seq_0_Incv1wn_arecyyj7v result_53;
  if (size_3 == 0){
    result_53 = (seq_0_Incv1wn_arecyyj7v){
      .len_0 = size_3, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_Infw7m1_arecyyj7v(size_3);
    void* X60Qx_1413 = alloc_1_sysvq0asl(memSize_0);
    result_53 = (seq_0_Incv1wn_arecyyj7v){
      .len_0 = size_3, .data_0 = ((NU8*)X60Qx_1413)}
    ;
    if ((!(result_53.data_0 == NIM_NIL))){
      NI32 i_25 = 0;
      {
        while (i_25 < size_3){
          result_53.data_0[i_25] = ((NU8)0u);
          inc_1_I6wjjge_aow2h993l1((&i_25));}}
      whileStmtLabel_0: ;}
    else {
      result_53.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_53;}
static inline void putQ_7_Ipw0nqk1_explnj22x1(seq_0_Incv1wn_arecyyj7v* s_29, NI32 i_26, NU8 elem_9){
  NB8 X60Qx_1414;
  if (i_26 < (*s_29).len_0){
    X60Qx_1414 = (0 <= i_26);}
  else {
    X60Qx_1414 = NIM_FALSE;}
  if ((!X60Qx_1414)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_29).data_0[i_26] = elem_9;}
static inline NI32 high_3_Iscz9v3_explnj22x1(seq_0_Ipw48je1_ast8ri79k s_55){
  NI32 result_65;
  result_65 = ((NI32)(s_55.len_0 - 1));
  return result_65;}
static inline NU32* getQ_8_Il3tzqv_explnj22x1(seq_0_Ipw48je1_ast8ri79k s_56, NU32 i_40){
  if ((!(i_40 < ((NU32)s_56.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  NU32* result_66;
  result_66 = (&s_56.data_0[((NI32)i_40)]);
  return result_66;}
void enlarge_0_Isqiwlk1_explnj22x1(BiTable_0_Itxao711_ast8ri79k* t_34){
  seq_0_Ipw48je1_ast8ri79k n_41;
  eQwasMoved_1_I52bdqo1_ast8ri79k((&n_41));
  NI32 X60Qx_1449 = len_3_Itda5g31_explnj22x1((*t_34).keys_0);
  newSeq_1_I63l1ps_explnj22x1((&n_41), ((NI32)(X60Qx_1449 * 2)));
  swap_0_I6g32k11_explnj22x1((&(*t_34).keys_0), (&n_41));
  {
    NI32 X60Qlf_29 = 0;
    NI32 X60Qlf_30 = high_3_Iscz9v3_explnj22x1(n_41);
    NI32 X60Qlf_31 = X60Qlf_29;
    {
      while (X60Qlf_31 <= X60Qlf_30){
        {
          NU32* X60Qx_1450 = getQ_7_I19xg9l1_explnj22x1(n_41, X60Qlf_31);
          NU32 X60Qii_2 = (*X60Qx_1450);
          if (((NU32)0u) < ((NU32)X60Qii_2)){
            NU64* X60Qx_1451 = getQ_7_Ifaxado1_ast8ri79k((*t_34).vals_0, ((NI32)(((NI32)X60Qii_2) - ((NI32)1))));
            NU32 X60Qx_1452 = hash_4_has9tn57v((*X60Qx_1451));
            NI32 X60Qx_1453 = high_3_Iscz9v3_explnj22x1((*t_34).keys_0);
            NU32 X60Qii_3 = ((NU32)(X60Qx_1452 & ((NU32)X60Qx_1453)));
            while (NIM_TRUE){
              NU32* X60Qx_1454 = getQ_8_Il3tzqv_explnj22x1((*t_34).keys_0, X60Qii_3);
              if (((NU32)0u) < ((NU32)(*X60Qx_1454))){
                NI32 X60Qx_1455 = high_3_Iscz9v3_explnj22x1((*t_34).keys_0);
                NU32 X60Qx_1456 = nextTry_0_bitekkhcx1(X60Qii_3, ((NU32)X60Qx_1455));
                X60Qii_3 = X60Qx_1456;}
              else {
                break;}}
            NU32* X60Qx_1457 = getQ_7_I19xg9l1_explnj22x1(n_41, X60Qlf_31);
            NU32 X60Qx_1458 = move_0_I1bmgmc_explnj22x1(X60Qx_1457);
            putQ_8_Ivcm3wy_explnj22x1((&(*t_34).keys_0), X60Qii_3, X60Qx_1458);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_31));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroy_1_I7og8li_ast8ri79k(n_41);}
void setLen_0_Ig8m65q_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_60, NI32 newLen_12){
  if (newLen_12 < (*s_60).len_0){
    shrink_0_Io5vz0b_explnj22x1(s_60, newLen_12);}
  else {
    NI32 i_43 = (*s_60).len_0;
    growUnsafe_0_Iyoxsj_explnj22x1(s_60, newLen_12);
    if ((*s_60).data_0 == NIM_NIL){
      return;}
    {
      while (i_43 < newLen_12){
        (*s_60).data_0[i_43] = ((NU32)0u);
        inc_1_I6wjjge_aow2h993l1((&i_43));}}
    whileStmtLabel_0: ;}}
static inline void putQ_8_Ivcm3wy_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_63, NU32 i_44, NU32 elem_14){
  if ((!(i_44 < ((NU32)(*s_63).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_63).data_0[((NI32)i_44)] = elem_14;}
static inline void add_0_I388oob1_explnj22x1(seq_0_Ijmiee61_ast8ri79k* s_64, NU64 elem_15){
  NI32 L_2 = (*s_64).len_0;
  NI32 X60Qx_1459 = capInBytes_0_Iifs4oa_ast8ri79k((*s_64));
  if (X60Qx_1459 < ((NI32)(((NI32)(L_2 * sizeof(NU64))) + sizeof(NU64)))){
    NB8 X60Qx_1460 = resize_0_Ixmbspe1_explnj22x1(s_64, 1);
    if ((!X60Qx_1460)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_64).len_0));
  (*s_64).data_0[L_2] = elem_15;}
NU32 getOrIncl_0_Ivbdpqo_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_35, NU64 v_10){
  NU32 result_67;
  NU32 origH_3 = hash_4_has9tn57v(v_10);
  NI32 X60Qx_1461 = high_3_I8k93cc_explnj22x1((*t_35).keys_0);
  NU32 h_3 = ((NU32)(origH_3 & ((NU32)X60Qx_1461)));
  if ((!((*t_35).keys_0.len_0 == 0))){
    {
      while (NIM_TRUE){
        NU32* X60Qx_1462 = getQ_8_Iboidd8_explnj22x1((*t_35).keys_0, h_3);
        NU32 litId_17 = (*X60Qx_1462);
        if ((!(((NU32)0u) < ((NU32)litId_17)))){
          goto whileStmtLabel_0;}
        NU32* X60Qx_1463 = getQ_8_Iboidd8_explnj22x1((*t_35).keys_0, h_3);
        NU64* X60Qx_1464 = getQ_7_Ifaxado1_ast8ri79k((*t_35).vals_0, ((NI32)(((NI32)(*X60Qx_1463)) - ((NI32)1))));
        if (v_10 == (*X60Qx_1464)){
          return litId_17;}
        NI32 X60Qx_1465 = high_3_I8k93cc_explnj22x1((*t_35).keys_0);
        NU32 X60Qx_1466 = nextTry_0_bitekkhcx1(h_3, ((NU32)X60Qx_1465));
        h_3 = X60Qx_1466;}}
    whileStmtLabel_0: ;
    NB8 X60Qx_1467 = mustRehash_0_bitekkhcx1((*t_35).keys_0.len_0, (*t_35).vals_0.len_0);
    if (X60Qx_1467){
      enlarge_0_Ib1jipm1_explnj22x1(t_35);
      NI32 X60Qx_1468 = high_3_I8k93cc_explnj22x1((*t_35).keys_0);
      h_3 = ((NU32)(origH_3 & ((NU32)X60Qx_1468)));
      {
        while (NIM_TRUE){
          NU32* X60Qx_1469 = getQ_8_Iboidd8_explnj22x1((*t_35).keys_0, h_3);
          NU32 litId_18 = (*X60Qx_1469);
          if ((!(((NU32)0u) < ((NU32)litId_18)))){
            goto whileStmtLabel_1;}
          NI32 X60Qx_1470 = high_3_I8k93cc_explnj22x1((*t_35).keys_0);
          NU32 X60Qx_1471 = nextTry_0_bitekkhcx1(h_3, ((NU32)X60Qx_1470));
          h_3 = X60Qx_1471;}}
      whileStmtLabel_1: ;}}
  else {
    setLen_0_Ixczj431_explnj22x1((&(*t_35).keys_0), 16);
    NI32 X60Qx_1472 = high_3_I8k93cc_explnj22x1((*t_35).keys_0);
    h_3 = ((NU32)(origH_3 & ((NU32)X60Qx_1472)));}
  result_67 = ((NU32)((NI32)((*t_35).vals_0.len_0 + ((NI32)1))));
  putQ_8_Idqx2k6_explnj22x1((&(*t_35).keys_0), h_3, result_67);
  add_0_I388oob1_explnj22x1((&(*t_35).vals_0), v_10);
  return result_67;}
static inline NU8* rawData_0_Ihjhfzs_explnj22x1(seq_0_Incv1wn_arecyyj7v s_70){
  NU8* result_68;
  result_68 = s_70.data_0;
  return result_68;}
static inline NI32 len_6_Itc4yka_explnj22x1(openArray_0_Is74e021_explnj22x1 a_42){
  NI32 result_69;
  result_69 = a_42.len_0;
  return result_69;}
static inline NU8* getQ_10_Ikgj4ax_explnj22x1(openArray_0_Is74e021_explnj22x1 x_33, NI32 idx_5){
  NB8 X60Qx_1473;
  if (0 <= idx_5){
    X60Qx_1473 = (idx_5 < x_33.len_0);}
  else {
    X60Qx_1473 = NIM_FALSE;}
  if ((!X60Qx_1473)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NU8* result_70;
  result_70 = (&x_33.a_0[idx_5]);
  return result_70;}
static inline NI32 len_3_Itda5g31_explnj22x1(seq_0_Ipw48je1_ast8ri79k s_85){
  NI32 result_83;
  result_83 = s_85.len_0;
  return result_83;}
static inline void newSeq_1_I63l1ps_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_86, NI32 newLen_22){
  seq_0_Ipw48je1_ast8ri79k X60Qx_1489 = newSeq_0_I4s8fn41_explnj22x1(newLen_22);
  (*s_86) = X60Qx_1489;}
static inline void swap_0_I6g32k11_explnj22x1(seq_0_Ipw48je1_ast8ri79k* x_38, seq_0_Ipw48je1_ast8ri79k* y_9){
  seq_0_Ipw48je1_ast8ri79k tmp_2 = (*x_38);
  (*x_38) = (*y_9);
  (*y_9) = tmp_2;}
static inline NU32* getQ_7_I19xg9l1_explnj22x1(seq_0_Ipw48je1_ast8ri79k s_87, NI32 i_51){
  NB8 X60Qx_1490;
  if (i_51 < s_87.len_0){
    X60Qx_1490 = (0 <= i_51);}
  else {
    X60Qx_1490 = NIM_FALSE;}
  if ((!X60Qx_1490)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_84;
  result_84 = (&s_87.data_0[i_51]);
  return result_84;}
static inline NU32 move_0_I1bmgmc_explnj22x1(NU32* x_39){
  NU32 result_85;
  result_85 = (*x_39);
  return result_85;}
void shrink_0_Io5vz0b_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_88, NI32 newLen_23){
  NI32 i_52 = ((NI32)((*s_88).len_0 - 1));
  {
    while (newLen_23 <= i_52){
      dec_1_I0nzoz91_aow7lb5cq1((&i_52));}}
  whileStmtLabel_0: ;
  (*s_88).len_0 = newLen_23;}
void growUnsafe_0_Iyoxsj_explnj22x1(seq_0_Ipw48je1_ast8ri79k* s_89, NI32 newLen_24){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_24, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_2 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_1491 = capInBytes_0_I4tsb7_ast8ri79k((*s_89));
  if (X60Qx_1491 < newSize_2){
    NB8 X60Qx_1492 = resize_0_Indszvc_explnj22x1(s_89, ((NI32)(newLen_24 - (*s_89).len_0)));
    if ((!X60Qx_1492)){
      return;}}
  (*s_89).len_0 = newLen_24;}
NB8 resize_0_Ixmbspe1_explnj22x1(seq_0_Ijmiee61_ast8ri79k* dest_14, NI32 addedElements_8){
  NB8 result_87;
  NI32 X60Qx_1494 = capInBytes_0_Iifs4oa_ast8ri79k((*dest_14));
  NI32 oldCap_2 = ((NI32)(X60Qx_1494 / sizeof(NU64)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_8);
  NI32 memSize_4 = memSizeInBytes_0_Iom723i1_ast8ri79k(newCap_2);
  void* X60Qx_1495 = realloc_1_sysvq0asl(((void*)((void*)(*dest_14).data_0)), memSize_4);
  (*dest_14).data_0 = ((NU64*)X60Qx_1495);
  if ((*dest_14).data_0 == NIM_NIL){
    (*dest_14).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_4);
    result_87 = NIM_FALSE;}
  else {
    result_87 = NIM_TRUE;}
  return result_87;}
static inline NI32 high_3_I8k93cc_explnj22x1(seq_0_Isoawlw1_ast8ri79k s_92){
  NI32 result_88;
  result_88 = ((NI32)(s_92.len_0 - 1));
  return result_88;}
static inline NU32* getQ_8_Iboidd8_explnj22x1(seq_0_Isoawlw1_ast8ri79k s_93, NU32 i_53){
  if ((!(i_53 < ((NU32)s_93.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  NU32* result_89;
  result_89 = (&s_93.data_0[((NI32)i_53)]);
  return result_89;}
void enlarge_0_Ib1jipm1_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_38){
  seq_0_Isoawlw1_ast8ri79k n_42;
  eQwasMoved_1_I5y4iq9_ast8ri79k((&n_42));
  NI32 X60Qx_1496 = len_3_Irzg08a_explnj22x1((*t_38).keys_0);
  newSeq_1_Idmlkik1_explnj22x1((&n_42), ((NI32)(X60Qx_1496 * 2)));
  swap_0_Iqoh72v_explnj22x1((&(*t_38).keys_0), (&n_42));
  {
    NI32 X60Qlf_32 = 0;
    NI32 X60Qlf_33 = high_3_I8k93cc_explnj22x1(n_42);
    NI32 X60Qlf_34 = X60Qlf_32;
    {
      while (X60Qlf_34 <= X60Qlf_33){
        {
          NU32* X60Qx_1497 = getQ_7_Iqb93l2_explnj22x1(n_42, X60Qlf_34);
          NU32 X60Qii_2 = (*X60Qx_1497);
          if (((NU32)0u) < ((NU32)X60Qii_2)){
            NU64* X60Qx_1498 = getQ_7_Ifaxado1_ast8ri79k((*t_38).vals_0, ((NI32)(((NI32)X60Qii_2) - ((NI32)1))));
            NU32 X60Qx_1499 = hash_4_has9tn57v((*X60Qx_1498));
            NI32 X60Qx_1500 = high_3_I8k93cc_explnj22x1((*t_38).keys_0);
            NU32 X60Qii_3 = ((NU32)(X60Qx_1499 & ((NU32)X60Qx_1500)));
            while (NIM_TRUE){
              NU32* X60Qx_1501 = getQ_8_Iboidd8_explnj22x1((*t_38).keys_0, X60Qii_3);
              if (((NU32)0u) < ((NU32)(*X60Qx_1501))){
                NI32 X60Qx_1502 = high_3_I8k93cc_explnj22x1((*t_38).keys_0);
                NU32 X60Qx_1503 = nextTry_0_bitekkhcx1(X60Qii_3, ((NU32)X60Qx_1502));
                X60Qii_3 = X60Qx_1503;}
              else {
                break;}}
            NU32* X60Qx_1504 = getQ_7_Iqb93l2_explnj22x1(n_42, X60Qlf_34);
            NU32 X60Qx_1505 = move_0_Ipo4xyv_explnj22x1(X60Qx_1504);
            putQ_8_Idqx2k6_explnj22x1((&(*t_38).keys_0), X60Qii_3, X60Qx_1505);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_34));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroy_1_Iz0k69p1_ast8ri79k(n_42);}
void setLen_0_Ixczj431_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_97, NI32 newLen_26){
  if (newLen_26 < (*s_97).len_0){
    shrink_0_I74bzl8_explnj22x1(s_97, newLen_26);}
  else {
    NI32 i_56 = (*s_97).len_0;
    growUnsafe_0_I4lson61_explnj22x1(s_97, newLen_26);
    if ((*s_97).data_0 == NIM_NIL){
      return;}
    {
      while (i_56 < newLen_26){
        (*s_97).data_0[i_56] = ((NU32)0u);
        inc_1_I6wjjge_aow2h993l1((&i_56));}}
    whileStmtLabel_0: ;}}
static inline void putQ_8_Idqx2k6_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_100, NU32 i_57, NU32 elem_17){
  if ((!(i_57 < ((NU32)(*s_100).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_100).data_0[((NI32)i_57)] = elem_17;}
seq_0_Ipw48je1_ast8ri79k newSeq_0_I4s8fn41_explnj22x1(NI32 size_19){
  seq_0_Ipw48je1_ast8ri79k result_98;
  if (size_19 == 0){
    result_98 = (seq_0_Ipw48je1_ast8ri79k){
      .len_0 = size_19, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_9 = memSizeInBytes_0_Itq6t0c1_ast8ri79k(size_19);
    void* X60Qx_1514 = alloc_1_sysvq0asl(memSize_9);
    result_98 = (seq_0_Ipw48je1_ast8ri79k){
      .len_0 = size_19, .data_0 = ((NU32*)X60Qx_1514)}
    ;
    if ((!(result_98.data_0 == NIM_NIL))){
      NI32 i_60 = 0;
      {
        while (i_60 < size_19){
          result_98.data_0[i_60] = ((NU32)0u);
          inc_1_I6wjjge_aow2h993l1((&i_60));}}
      whileStmtLabel_0: ;}
    else {
      result_98.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_9);}}
  return result_98;}
NB8 resize_0_Indszvc_explnj22x1(seq_0_Ipw48je1_ast8ri79k* dest_17, NI32 addedElements_11){
  NB8 result_100;
  NI32 X60Qx_1516 = capInBytes_0_I4tsb7_ast8ri79k((*dest_17));
  NI32 oldCap_5 = ((NI32)(X60Qx_1516 / sizeof(NU32)));
  NI32 newCap_5 = recalcCap_0_sysvq0asl(oldCap_5, addedElements_11);
  NI32 memSize_10 = memSizeInBytes_0_Itq6t0c1_ast8ri79k(newCap_5);
  void* X60Qx_1517 = realloc_1_sysvq0asl(((void*)((void*)(*dest_17).data_0)), memSize_10);
  (*dest_17).data_0 = ((NU32*)X60Qx_1517);
  if ((*dest_17).data_0 == NIM_NIL){
    (*dest_17).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_10);
    result_100 = NIM_FALSE;}
  else {
    result_100 = NIM_TRUE;}
  return result_100;}
static inline NI32 len_3_Irzg08a_explnj22x1(seq_0_Isoawlw1_ast8ri79k s_104){
  NI32 result_102;
  result_102 = s_104.len_0;
  return result_102;}
static inline void newSeq_1_Idmlkik1_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_105, NI32 newLen_29){
  seq_0_Isoawlw1_ast8ri79k X60Qx_1518 = newSeq_0_Ielwdyx_explnj22x1(newLen_29);
  (*s_105) = X60Qx_1518;}
static inline void swap_0_Iqoh72v_explnj22x1(seq_0_Isoawlw1_ast8ri79k* x_42, seq_0_Isoawlw1_ast8ri79k* y_11){
  seq_0_Isoawlw1_ast8ri79k tmp_3 = (*x_42);
  (*x_42) = (*y_11);
  (*y_11) = tmp_3;}
static inline NU32* getQ_7_Iqb93l2_explnj22x1(seq_0_Isoawlw1_ast8ri79k s_106, NI32 i_61){
  NB8 X60Qx_1519;
  if (i_61 < s_106.len_0){
    X60Qx_1519 = (0 <= i_61);}
  else {
    X60Qx_1519 = NIM_FALSE;}
  if ((!X60Qx_1519)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_103;
  result_103 = (&s_106.data_0[i_61]);
  return result_103;}
static inline NU32 move_0_Ipo4xyv_explnj22x1(NU32* x_43){
  NU32 result_104;
  result_104 = (*x_43);
  return result_104;}
void shrink_0_I74bzl8_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_107, NI32 newLen_30){
  NI32 i_62 = ((NI32)((*s_107).len_0 - 1));
  {
    while (newLen_30 <= i_62){
      dec_1_I0nzoz91_aow7lb5cq1((&i_62));}}
  whileStmtLabel_0: ;
  (*s_107).len_0 = newLen_30;}
void growUnsafe_0_I4lson61_explnj22x1(seq_0_Isoawlw1_ast8ri79k* s_108, NI32 newLen_31){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_31, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_3 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_1520 = capInBytes_0_Iktr4pk_ast8ri79k((*s_108));
  if (X60Qx_1520 < newSize_3){
    NB8 X60Qx_1521 = resize_0_Iw4ackb_explnj22x1(s_108, ((NI32)(newLen_31 - (*s_108).len_0)));
    if ((!X60Qx_1521)){
      return;}}
  (*s_108).len_0 = newLen_31;}
seq_0_Isoawlw1_ast8ri79k newSeq_0_Ielwdyx_explnj22x1(NI32 size_26){
  seq_0_Isoawlw1_ast8ri79k result_108;
  if (size_26 == 0){
    result_108 = (seq_0_Isoawlw1_ast8ri79k){
      .len_0 = size_26, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_11 = memSizeInBytes_0_Iidgqw2_ast8ri79k(size_26);
    void* X60Qx_1522 = alloc_1_sysvq0asl(memSize_11);
    result_108 = (seq_0_Isoawlw1_ast8ri79k){
      .len_0 = size_26, .data_0 = ((NU32*)X60Qx_1522)}
    ;
    if ((!(result_108.data_0 == NIM_NIL))){
      NI32 i_63 = 0;
      {
        while (i_63 < size_26){
          result_108.data_0[i_63] = ((NU32)0u);
          inc_1_I6wjjge_aow2h993l1((&i_63));}}
      whileStmtLabel_0: ;}
    else {
      result_108.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_11);}}
  return result_108;}
NB8 resize_0_Iw4ackb_explnj22x1(seq_0_Isoawlw1_ast8ri79k* dest_19, NI32 addedElements_13){
  NB8 result_110;
  NI32 X60Qx_1524 = capInBytes_0_Iktr4pk_ast8ri79k((*dest_19));
  NI32 oldCap_6 = ((NI32)(X60Qx_1524 / sizeof(NU32)));
  NI32 newCap_6 = recalcCap_0_sysvq0asl(oldCap_6, addedElements_13);
  NI32 memSize_12 = memSizeInBytes_0_Iidgqw2_ast8ri79k(newCap_6);
  void* X60Qx_1525 = realloc_1_sysvq0asl(((void*)((void*)(*dest_19).data_0)), memSize_12);
  (*dest_19).data_0 = ((NU32*)X60Qx_1525);
  if ((*dest_19).data_0 == NIM_NIL){
    (*dest_19).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_12);
    result_110 = NIM_FALSE;}
  else {
    result_110 = NIM_TRUE;}
  return result_110;}
void X60Qini_0_explnj22x1(void){
  if (X60QiniGuard_0_explnj22x1){
    return;}
  X60QiniGuard_0_explnj22x1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_assy765wm();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_linxafkvx1();
  X60Qini_0_nifjp9lau1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_decqocs071();
  X60Qini_0_prorcx25w1();
  X60Qini_0_xinat3x34();
  X60Qini_0_sempjk6bn1();
  X60Qini_0_renqb5hy11();
  X60Qini_0_buiyylk1h1();
  X60Qini_0_typurxiqa1();
  X60Qini_0_lanhy12io1();
  X60Qini_0_symkyk35i1();}
static inline NU32 hash_4_has9tn57v(NU64 x_1){
  NU32 result_5;
  result_5 = ((NU32)x_1);
  return result_5;}
static inline NU64* getQ_7_Ifaxado1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_10, NI32 i_7){
  NB8 X60Qx_54;
  if (i_7 < s_10.len_0){
    X60Qx_54 = (0 <= i_7);}
  else {
    X60Qx_54 = NIM_FALSE;}
  if ((!X60Qx_54)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU64* result_11;
  result_11 = (&s_10.data_0[i_7]);
  return result_11;}
static inline NU32 nextTry_0_bitekkhcx1(NU32 h_0, NU32 maxHash_0){
  NU32 result_0;
  result_0 = ((NU32)(((NU32)(h_0 + ((NU32)1))) & maxHash_0));
  return result_0;}
static inline NB8 mustRehash_0_bitekkhcx1(NI32 length_0, NI32 counter_0){
  NB8 result_1;
  if ((!(counter_0 < length_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NB8 X60Qx_0;
  if (length_0 < ((NI32)(((NI32)(counter_0 / 2)) + counter_0))){
    X60Qx_0 = NIM_TRUE;}
  else {
    X60Qx_0 = (((NI32)(length_0 - counter_0)) < 4);}
  result_1 = X60Qx_0;
  return result_1;}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline NI32 memSizeInBytes_0_Infw7m1_arecyyj7v(NI32 size_27){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_66;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_27, sizeof(NU8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_66 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_66 = ((NI32)2147483647);}
  return result_66;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void eQwasMoved_1_I52bdqo1_ast8ri79k(seq_0_Ipw48je1_ast8ri79k* s_60){
  (*s_60).len_0 = 0;
  (*s_60).data_0 = NIM_NIL;}
static inline NI32 capInBytes_0_Iifs4oa_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_70){
  NI32 result_42;
  NI32 X60Qx_4;
  if ((!(s_70.data_0 == NIM_NIL))){
    NI32 X60Qx_125 = allocatedSize_0_sysvq0asl(((void*)((void*)s_70.data_0)));
    X60Qx_4 = X60Qx_125;}
  else {
    X60Qx_4 = 0;}
  result_42 = X60Qx_4;
  return result_42;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline NI32 capInBytes_0_I4tsb7_ast8ri79k(seq_0_Ipw48je1_ast8ri79k s_71){
  NI32 result_45;
  NI32 X60Qx_5;
  if ((!(s_71.data_0 == NIM_NIL))){
    NI32 X60Qx_128 = allocatedSize_0_sysvq0asl(((void*)((void*)s_71.data_0)));
    X60Qx_5 = X60Qx_128;}
  else {
    X60Qx_5 = 0;}
  result_45 = X60Qx_5;
  return result_45;}
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_85;
  NI32 X60QconstRefTemp_0;
  if (__builtin_sadd_overflow(oldCap_0, addedElements_0, &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 requiredLen_0 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_85 = ((NI32)2147483647);}
  else {
    NI32 X60QconstRefTemp_1;
    if (__builtin_sadd_overflow(oldCap_0, ((NI32)(((NI32)oldCap_0) >> ((NU32)1))), &X60QconstRefTemp_1)){
      LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
    result_85 = X60QconstRefTemp_1;
    if (LENGC_OVF_){
      result_85 = requiredLen_0;}
    else {
      NI32 X60Qx_219 = max_2_sysvq0asl(result_85, requiredLen_0);
      result_85 = X60Qx_219;}}
  return result_85;}
static inline NI32 memSizeInBytes_0_Iom723i1_ast8ri79k(NI32 size_27){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_43;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_27, sizeof(NU64), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_43 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_43 = ((NI32)2147483647);}
  return result_43;}
static inline void eQwasMoved_1_I5y4iq9_ast8ri79k(seq_0_Isoawlw1_ast8ri79k* s_63){
  (*s_63).len_0 = 0;
  (*s_63).data_0 = NIM_NIL;}
static inline NI32 memSizeInBytes_0_Itq6t0c1_ast8ri79k(NI32 size_29){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_46;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_29, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_46 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_46 = ((NI32)2147483647);}
  return result_46;}
static inline NI32 capInBytes_0_Iktr4pk_ast8ri79k(seq_0_Isoawlw1_ast8ri79k s_72){
  NI32 result_48;
  NI32 X60Qx_6;
  if ((!(s_72.data_0 == NIM_NIL))){
    NI32 X60Qx_131 = allocatedSize_0_sysvq0asl(((void*)((void*)s_72.data_0)));
    X60Qx_6 = X60Qx_131;}
  else {
    X60Qx_6 = 0;}
  result_48 = X60Qx_6;
  return result_48;}
static inline NI32 memSizeInBytes_0_Iidgqw2_ast8ri79k(NI32 size_31){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_49;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_31, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_49 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_49 = ((NI32)2147483647);}
  return result_49;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
