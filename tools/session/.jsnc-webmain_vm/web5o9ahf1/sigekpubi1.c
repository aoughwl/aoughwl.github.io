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
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_sempjk6bn1;
typedef struct SemContext_0_sempjk6bn1 SemContext_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1;
typedef struct Cursor_0_nifb6mq6y1 Cursor_0_nifb6mq6y1;
typedef struct CallArg_0_sigekpubi1 CallArg_0_sigekpubi1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportX46ilter0prorcx25w1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportX46ilter0prorcx25w1_sempjk6bn1;
typedef struct ImportedModule_0_sempjk6bn1 ImportedModule_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1;
typedef struct Table_0_I153b76_sigekpubi1 Table_0_I153b76_sigekpubi1;
typedef struct X60Qt_0_IArefSX53copeX4fbj0symiqlwtg1_sempjk6bn1 X60Qt_0_IArefSX53copeX4fbj0symiqlwtg1_sempjk6bn1;
typedef struct X60Qt_0_IArefSX53emX52outineX4fbj0sempjk6bn1_sempjk6bn1 X60Qt_0_IArefSX53emX52outineX4fbj0sempjk6bn1_sempjk6bn1;
typedef struct X60Qt_0_IArefSX50rogramX43ontextX4fbj0sempjk6bn1_sempjk6bn1 X60Qt_0_IArefSX50rogramX43ontextX4fbj0sempjk6bn1_sempjk6bn1;
typedef struct InstRequest_0_sempjk6bn1 InstRequest_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportedX4dodule0sempjk6bn1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportedX4dodule0sempjk6bn1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX54okenX42uf0nifb6mq6y1_sempjk6bn1 X60Qt_0_IAtupleSstring0sysvq0aslSX54okenX42uf0nifb6mq6y1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_sempjk6bn1 X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1Sstring0sysvq0aslZSR9_sempjk6bn1 X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1Sstring0sysvq0aslZSR9_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX50ackedX4cineX49nfo0linxafkvx1Abool_repa2y0od1 X60Qt_0_IAtupleSX50ackedX4cineX49nfo0linxafkvx1Abool_repa2y0od1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX48ooksX50erX54ype0prorcx25w1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX48ooksX50erX54ype0prorcx25w1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43lassX45ntry0sempjk6bn1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43lassX45ntry0sempjk6bn1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX50luginX4fbj0sempjk6bn1_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX50luginX4fbj0sempjk6bn1_sempjk6bn1;
typedef struct PluginObj_0_sempjk6bn1 PluginObj_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1SX53trX49d0R19ZSseq0X49n6doa_sempjk6bn1 X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1SX53trX49d0R19ZSseq0X49n6doa_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1;
typedef struct TokenBuf_0_nifb6mq6y1 TokenBuf_0_nifb6mq6y1;
typedef struct xint_0_xinat3x34 xint_0_xinat3x34;
typedef struct Table_0_I5rl962_sempjk6bn1 Table_0_I5rl962_sempjk6bn1;
typedef struct Item_0_sempjk6bn1 Item_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sstring0sysvq0asl_sempjk6bn1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sstring0sysvq0asl_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1;
typedef struct Sym_0_symiqlwtg1 Sym_0_symiqlwtg1;
typedef struct MethodIndexEntry_0_sempjk6bn1 MethodIndexEntry_0_sempjk6bn1;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct CallArg_0_sigekpubi1{
  Cursor_0_nifb6mq6y1 n_0;
  Cursor_0_nifb6mq6y1 typ_0;
  Cursor_0_nifb6mq6y1 orig_0;}
CallArg_0_sigekpubi1;
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
typedef struct FnCandidate_0_sigekpubi1{
  NimonySym_0_nimry5ra91 kind_0;
  NU32 sym_0;
  Cursor_0_nifb6mq6y1 typ_0;
  NB8 fromConcept_0;}
FnCandidate_0_sigekpubi1;
typedef NU8 MatchErrorKind_0_sigekpubi1;

#define InvalidMatch_0_sigekpubi1 ((NU8)0)
#define InvalidRematch_0_sigekpubi1 ((NU8)1)
#define ConstraintMismatch_0_sigekpubi1 ((NU8)2)
#define FormalTypeNotAtEndBug_0_sigekpubi1 ((NU8)3)
#define FormalParamsMismatch_0_sigekpubi1 ((NU8)4)
#define CallConvMismatch_0_sigekpubi1 ((NU8)5)
#define RaisesMismatch_0_sigekpubi1 ((NU8)6)
#define ClosureMismatch_0_sigekpubi1 ((NU8)7)
#define PassiveMismatch_0_sigekpubi1 ((NU8)8)
#define UnavailableSubtypeRelation_0_sigekpubi1 ((NU8)9)
#define ImplicitConversionNotMutable_0_sigekpubi1 ((NU8)10)
#define VarNeeded_0_sigekpubi1 ((NU8)11)
#define UnhandledTypeBug_0_sigekpubi1 ((NU8)12)
#define MismatchBug_0_sigekpubi1 ((NU8)13)
#define MissingExplicitGenericParameter_0_sigekpubi1 ((NU8)14)
#define ExtraGenericParameter_0_sigekpubi1 ((NU8)15)
#define RoutineIsNotGeneric_0_sigekpubi1 ((NU8)16)
#define CouldNotInferTypeVar_0_sigekpubi1 ((NU8)17)
#define TooManyArguments_0_sigekpubi1 ((NU8)18)
#define TooFewArguments_0_sigekpubi1 ((NU8)19)
#define NameNotFound_0_sigekpubi1 ((NU8)20)
#define ParamAlreadyGiven_0_sigekpubi1 ((NU8)21)
typedef struct MatchError_0_sigekpubi1{
  NU32 info_0;
  MatchErrorKind_0_sigekpubi1 kind_0;
  NU32 typeVar_0;
  Cursor_0_nifb6mq6y1 expected_0;
  Cursor_0_nifb6mq6y1 got_0;
  NI32 pos_0;}
MatchError_0_sigekpubi1;
typedef struct seq_0_Iqf5su2_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1* data_0;}
seq_0_Iqf5su2_sempjk6bn1;
typedef struct seq_0_Ikxuplm1_filqx2b6r1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_filqx2b6r1;
typedef struct Table_0_I5rl962_sempjk6bn1{
  seq_0_Iqf5su2_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_I5rl962_sempjk6bn1;
typedef struct seq_0_Ic9cn7e1_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_sempjk6bn1* data_0;}
seq_0_Ic9cn7e1_sempjk6bn1;
typedef struct Table_0_Ibw7a2q1_sempjk6bn1{
  seq_0_Ic9cn7e1_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Ibw7a2q1_sempjk6bn1;
typedef struct HashSet_0_Ilwf8c01_sempjk6bn1{
  Table_0_Ibw7a2q1_sempjk6bn1 t_0;}
HashSet_0_Ilwf8c01_sempjk6bn1;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef NU8 NimonyType_0_nimry5ra91;

#define NoType_0_nimry5ra91 ((NU8)0)
#define ErrT_0_nimry5ra91 ((NU8)1)
#define AtT_0_nimry5ra91 ((NU8)3)
#define AndT_0_nimry5ra91 ((NU8)17)
#define OrT_0_nimry5ra91 ((NU8)18)
#define NotT_0_nimry5ra91 ((NU8)20)
#define ProcT_0_nimry5ra91 ((NU8)70)
#define FuncT_0_nimry5ra91 ((NU8)71)
#define IteratorT_0_nimry5ra91 ((NU8)72)
#define ConverterT_0_nimry5ra91 ((NU8)73)
#define MethodT_0_nimry5ra91 ((NU8)74)
#define MacroT_0_nimry5ra91 ((NU8)75)
#define TemplateT_0_nimry5ra91 ((NU8)76)
#define ObjectT_0_nimry5ra91 ((NU8)106)
#define EnumT_0_nimry5ra91 ((NU8)107)
#define ProctypeT_0_nimry5ra91 ((NU8)108)
#define IT_0_nimry5ra91 ((NU8)113)
#define UT_0_nimry5ra91 ((NU8)114)
#define FT_0_nimry5ra91 ((NU8)115)
#define CT_0_nimry5ra91 ((NU8)116)
#define BoolT_0_nimry5ra91 ((NU8)117)
#define VoidT_0_nimry5ra91 ((NU8)118)
#define PtrT_0_nimry5ra91 ((NU8)119)
#define ArrayT_0_nimry5ra91 ((NU8)120)
#define VarargsT_0_nimry5ra91 ((NU8)137)
#define StaticT_0_nimry5ra91 ((NU8)163)
#define TupleT_0_nimry5ra91 ((NU8)185)
#define OnumT_0_nimry5ra91 ((NU8)186)
#define AnumT_0_nimry5ra91 ((NU8)187)
#define RefT_0_nimry5ra91 ((NU8)188)
#define MutT_0_nimry5ra91 ((NU8)189)
#define OutT_0_nimry5ra91 ((NU8)190)
#define LentT_0_nimry5ra91 ((NU8)191)
#define SinkT_0_nimry5ra91 ((NU8)192)
#define NiltT_0_nimry5ra91 ((NU8)193)
#define ConceptT_0_nimry5ra91 ((NU8)194)
#define DistinctT_0_nimry5ra91 ((NU8)195)
#define ItertypeT_0_nimry5ra91 ((NU8)196)
#define RangetypeT_0_nimry5ra91 ((NU8)197)
#define UarrayT_0_nimry5ra91 ((NU8)198)
#define SetT_0_nimry5ra91 ((NU8)199)
#define AutoT_0_nimry5ra91 ((NU8)200)
#define SymkindT_0_nimry5ra91 ((NU8)201)
#define TypekindT_0_nimry5ra91 ((NU8)202)
#define TypedescT_0_nimry5ra91 ((NU8)203)
#define UntypedT_0_nimry5ra91 ((NU8)204)
#define TypedT_0_nimry5ra91 ((NU8)205)
#define CstringT_0_nimry5ra91 ((NU8)206)
#define PointerT_0_nimry5ra91 ((NU8)207)
#define OrdinalT_0_nimry5ra91 ((NU8)208)
typedef struct Match_0_sigekpubi1{
  Table_0_I5rl962_sempjk6bn1 inferred_0;
  HashSet_0_Ilwf8c01_sempjk6bn1 tvars_0;
  FnCandidate_0_sigekpubi1 fn_0;
  TokenBuf_0_nifb6mq6y1 args_0;
  TokenBuf_0_nifb6mq6y1 typeArgs_0;
  NB8 err_0;
  NB8 flipped_0;
  NB8 concreteMatch_0;
  NB8 ignoreConstraints_0;
  NB8 hasError_0;
  NimonyType_0_nimry5ra91 skippedMod_0;
  NU32 argInfo_0;
  NI32 pos_0;
  NI32 opened_0;
  NI32 inheritanceCosts_0;
  NI32 intLitCosts_0;
  NI32 intConvCosts_0;
  NI32 convCosts_0;
  Cursor_0_nifb6mq6y1 returnType_0;
  SemContext_0_sempjk6bn1* context_0;
  MatchError_0_sigekpubi1 error_0;
  NI32 firstVarargPosition_0;
  NI32 varargsEndPosition_0;
  NB8 genericConverter_0;
  NB8 refineArgType_0;
  NB8 insertedParam_0;
  NB8 namedArgsReordered_0;
  NU32 namedArgsReorderInfo_0;}
Match_0_sigekpubi1;
typedef NU8 LinearMatchFlag_0_sigekpubi1;

#define ExactBits_0_sigekpubi1 ((NU8)0)
#define InferActualTypevar_0_sigekpubi1 ((NU8)1)
typedef NU8 CallConv_0_cal1yym9t1;

#define NoCallConv_0_cal1yym9t1 ((NU8)0)
#define Cdecl_0_cal1yym9t1 ((NU8)123)
#define Stdcall_0_cal1yym9t1 ((NU8)124)
#define Safecall_0_cal1yym9t1 ((NU8)125)
#define Syscall_0_cal1yym9t1 ((NU8)126)
#define Fastcall_0_cal1yym9t1 ((NU8)127)
#define Thiscall_0_cal1yym9t1 ((NU8)128)
#define Noconv_0_cal1yym9t1 ((NU8)129)
#define Member_0_cal1yym9t1 ((NU8)130)
#define Nimcall_0_cal1yym9t1 ((NU8)131)
typedef struct ProcProperties_0_sigekpubi1{
  CallConv_0_cal1yym9t1 cc_0;
  NB8 usesRaises_0;
  Cursor_0_nifb6mq6y1 raisesType_0;
  NB8 usesClosure_0;
  NB8 usesPassive_0;}
ProcProperties_0_sigekpubi1;
typedef NU8 TypeRelation_0_sigekpubi1;

#define NoMatch_0_sigekpubi1 ((NU8)0)
#define IntLitMatch_0_sigekpubi1 ((NU8)1)
#define IntConvMatch_0_sigekpubi1 ((NU8)2)
#define ConvertibleMatch_0_sigekpubi1 ((NU8)3)
#define SubtypeMatch_0_sigekpubi1 ((NU8)4)
#define GenericMatch_0_sigekpubi1 ((NU8)5)
#define EqualMatch_0_sigekpubi1 ((NU8)6)
typedef NU8 DisambiguationResult_0_sigekpubi1;

#define NobodyWins_0_sigekpubi1 ((NU8)0)
#define FirstWins_0_sigekpubi1 ((NU8)1)
#define SecondWins_0_sigekpubi1 ((NU8)2)
typedef struct seq_0_Ikcwp3r1_sigekpubi1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1* data_0;}
seq_0_Ikcwp3r1_sigekpubi1;
typedef struct Table_0_I153b76_sigekpubi1{
  seq_0_Ikcwp3r1_sigekpubi1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_I153b76_sigekpubi1;
typedef struct seq_0_Iflf8jf1_fiepkwzpc{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_fiepkwzpc;
typedef struct ParamsInfo_0_sigekpubi1{
  NI32 len_0;
  Table_0_I153b76_sigekpubi1 names_0;
  seq_0_Iflf8jf1_fiepkwzpc isVarargs_0;}
ParamsInfo_0_sigekpubi1;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct openArray_0_Idn7dja1_sigekpubi1{
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1* a_0;
  NI32 len_0;}
openArray_0_Idn7dja1_sigekpubi1;
typedef struct seq_0_Isyzizu1_comaa5xpt1{
  NI32 len_0;
  Cursor_0_nifb6mq6y1* data_0;}
seq_0_Isyzizu1_comaa5xpt1;
typedef struct openArray_0_Il0925p1_sigekpubi1{
  CallArg_0_sigekpubi1* a_0;
  NI32 len_0;}
openArray_0_Il0925p1_sigekpubi1;
typedef struct seq_0_I8i5w711_sigekpubi1{
  NI32 len_0;
  CallArg_0_sigekpubi1* data_0;}
seq_0_I8i5w711_sigekpubi1;
typedef struct openArray_0_Ir53qdx_comaa5xpt1{
  NU32* a_0;
  NI32 len_0;}
openArray_0_Ir53qdx_comaa5xpt1;
typedef struct openArray_0_Imqex5f1_comaa5xpt1{
  Cursor_0_nifb6mq6y1* a_0;
  NI32 len_0;}
openArray_0_Imqex5f1_comaa5xpt1;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_In6doa_ast8ri79k keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
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
typedef struct seq_0_Isoawlw1_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Isoawlw1_ast8ri79k;
typedef struct BiTable_0_Iojfwmy1_ast8ri79k{
  seq_0_Ijmiee61_ast8ri79k vals_0;
  seq_0_Isoawlw1_ast8ri79k keys_0;}
BiTable_0_Iojfwmy1_ast8ri79k;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[32];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct X60Qt_0_IAarrayAuS8ZS27_decqocs071{
  NU8 a[27];}
X60Qt_0_IAarrayAuS8ZS27_decqocs071;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1{
  NU32 fld_0;
  Cursor_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1;
typedef struct X60Qt_0_IAarrayAuS8ZS11_decqocs071{
  NU8 a[11];}
X60Qt_0_IAarrayAuS8ZS11_decqocs071;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct seq_0_Izphk88_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1* data_0;}
seq_0_Izphk88_prorcx25w1;
typedef struct Table_0_I4dbdda_prorcx25w1{
  seq_0_Izphk88_prorcx25w1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_I4dbdda_prorcx25w1;
typedef struct seq_0_I4v4ahw1_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportX46ilter0prorcx25w1_sempjk6bn1* data_0;}
seq_0_I4v4ahw1_sempjk6bn1;
typedef struct Table_0_I51s2r71_sempjk6bn1{
  seq_0_I4v4ahw1_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_I51s2r71_sempjk6bn1;
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
typedef struct X60Qt_0_IAtupleAlentSX53ymX49d0nifh7u8pu1ZAR6SX49mportedX4dodule0sempjk6bn1_sigekpubi1{
  NU32* fld_0;
  ImportedModule_0_sempjk6bn1* fld_1;}
X60Qt_0_IAtupleAlentSX53ymX49d0nifh7u8pu1ZAR6SX49mportedX4dodule0sempjk6bn1_sigekpubi1;
typedef struct seq_0_I05y7aa1_sig6uoro1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1* data_0;}
seq_0_I05y7aa1_sig6uoro1;
typedef struct Table_0_Iv58xy8_sig6uoro1{
  seq_0_I05y7aa1_sig6uoro1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
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
typedef struct X60Qt_0_IAtupleSX43ursor0nifb6mq6y1SR6_sig6uoro1{
  Cursor_0_nifb6mq6y1 fld_0;
  Cursor_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleSX43ursor0nifb6mq6y1SR6_sig6uoro1;
typedef struct X60Qt_0_IAtupleAiS32ZAmutSX43ursor0nifb6mq6y1_sigekpubi1{
  NI32 fld_0;
  Cursor_0_nifb6mq6y1* fld_1;}
X60Qt_0_IAtupleAiS32ZAmutSX43ursor0nifb6mq6y1_sigekpubi1;
typedef struct X60Qt_0_IAarrayAuS8ZS43_ast8ri79k{
  NU8 a[43];}
X60Qt_0_IAarrayAuS8ZS43_ast8ri79k;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_sempjk6bn1{
  NU32 fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_sempjk6bn1;
typedef struct X60Qt_0_IAtupleAlentSX53ymX49d0nifh7u8pu1ZAR6Abool_sigekpubi1{
  NU32* fld_0;
  NB8* fld_1;}
X60Qt_0_IAtupleAlentSX53ymX49d0nifh7u8pu1ZAR6Abool_sigekpubi1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1{
  NU32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1AiS32_sigekpubi1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef struct seq_0_Iafyozp_sempjk6bn1{
  NI32 len_0;
  InstRequest_0_sempjk6bn1* data_0;}
seq_0_Iafyozp_sempjk6bn1;
typedef struct seq_0_Ivtzsw31_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX49mportedX4dodule0sempjk6bn1_sempjk6bn1* data_0;}
seq_0_Ivtzsw31_sempjk6bn1;
typedef struct Table_0_I89hz581_sempjk6bn1{
  seq_0_Ivtzsw31_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_I89hz581_sempjk6bn1;
typedef struct seq_0_Io4pvgy1_nifb6mq6y1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Io4pvgy1_nifb6mq6y1;
typedef struct seq_0_Ix7ee6h_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* data_0;}
seq_0_Ix7ee6h_sempjk6bn1;
typedef struct Table_0_Idzlvr_sempjk6bn1{
  seq_0_Ix7ee6h_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Idzlvr_sempjk6bn1;
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
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_I1dz4p91_sempjk6bn1;
typedef struct seq_0_I7cgnoo1_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_sempjk6bn1* data_0;}
seq_0_I7cgnoo1_sempjk6bn1;
typedef struct Table_0_Id70lot_sempjk6bn1{
  seq_0_I7cgnoo1_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Id70lot_sempjk6bn1;
typedef struct seq_0_I8j02aj_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1Sstring0sysvq0aslZSR9_sempjk6bn1* data_0;}
seq_0_I8j02aj_sempjk6bn1;
typedef struct Table_0_Irghkpt1_sempjk6bn1{
  seq_0_I8j02aj_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
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
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Ie7idqg_repa2y0od1;
typedef struct HashSet_0_Iusf0fw1_repa2y0od1{
  Table_0_Ie7idqg_repa2y0od1 t_0;}
HashSet_0_Iusf0fw1_repa2y0od1;
typedef struct MetaInfo_0_sempjk6bn1{
  seq_0_Ixdx2fh1_ast8ri79k includedFiles_0;
  seq_0_Ixdx2fh1_ast8ri79k importedFiles_0;}
MetaInfo_0_sempjk6bn1;
typedef struct seq_0_Im9jzzo_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX48ooksX50erX54ype0prorcx25w1_sempjk6bn1* data_0;}
seq_0_Im9jzzo_sempjk6bn1;
typedef struct Table_0_Iw0ekpv_sempjk6bn1{
  seq_0_Im9jzzo_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Iw0ekpv_sempjk6bn1;
typedef struct seq_0_Idyps081_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1* data_0;}
seq_0_Idyps081_prorcx25w1;
typedef struct Table_0_I2pi31q1_prorcx25w1{
  seq_0_Idyps081_prorcx25w1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
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
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Id6j12r1_sempjk6bn1;
typedef struct seq_0_I0i3btg1_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1* data_0;}
seq_0_I0i3btg1_prorcx25w1;
typedef struct Table_0_Ik52dhu1_prorcx25w1{
  seq_0_I0i3btg1_prorcx25w1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
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
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
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
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Itbx1h51_sempjk6bn1;
typedef struct seq_0_Ie256m71_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1* data_0;}
seq_0_Ie256m71_sempjk6bn1;
typedef struct Table_0_Iy0uuh6_sempjk6bn1{
  seq_0_Ie256m71_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Iy0uuh6_sempjk6bn1;
typedef struct seq_0_I86hhvd_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1* data_0;}
seq_0_I86hhvd_sempjk6bn1;
typedef struct Table_0_Igu3pp_sempjk6bn1{
  seq_0_I86hhvd_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Igu3pp_sempjk6bn1;
typedef struct seq_0_I8t027x1_comaa5xpt1{
  NI32 len_0;
  TokenBuf_0_nifb6mq6y1* data_0;}
seq_0_I8t027x1_comaa5xpt1;
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
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Ikw23fw_sempjk6bn1;
typedef struct seq_0_I4xiucd_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1* data_0;}
seq_0_I4xiucd_sempjk6bn1;
typedef struct Table_0_Is51thb_sempjk6bn1{
  seq_0_I4xiucd_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Is51thb_sempjk6bn1;
typedef struct SemContext_0_sempjk6bn1{
  X60Qt_0_IArefSX53emX52outineX4fbj0sempjk6bn1_sempjk6bn1* routine_0;
  X60Qt_0_IArefSX53copeX4fbj0symiqlwtg1_sempjk6bn1* currentScope_0;
  X60Qt_0_IArefSX50rogramX43ontextX4fbj0sempjk6bn1_sempjk6bn1* g_0;
  seq_0_Iafyozp_sempjk6bn1 procRequests_0;
  seq_0_In6doa_ast8ri79k typeInstDecls_0;
  TokenBuf_0_nifb6mq6y1 pendingSumtypes_0;
  seq_0_Ixdx2fh1_ast8ri79k includeStack_0;
  Table_0_I89hz581_sempjk6bn1 importedModules_0;
  NU32 selfModuleSym_0;
  seq_0_Io4pvgy1_nifb6mq6y1 instantiatedFrom_0;
  Table_0_I4dbdda_prorcx25w1 importTab_0;
  Table_0_Idzlvr_sempjk6bn1 globals_0;
  Table_0_Idzlvr_sempjk6bn1 locals_0;
  Table_0_Idzlvr_sempjk6bn1 fieldCounts_0;
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
  seq_0_I8t027x1_comaa5xpt1 pragmaStack_0;
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
  seq_0_Ixdx2fh1_ast8ri79k passL_0;
  seq_0_Ixdx2fh1_ast8ri79k passC_0;
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
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1{
  NU32 fld_0;
  seq_0_In6doa_ast8ri79k fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
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
typedef struct seq_0_Ixpi5il1_sig6uoro1{
  NI32 len_0;
  Sym_0_symiqlwtg1* data_0;}
seq_0_Ixpi5il1_sig6uoro1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1{
  NU32 fld_0;
  seq_0_Ixpi5il1_sig6uoro1 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49xpi5il1_sig6uoro1;
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
  seq_0_Ixdx2fh1_ast8ri79k defines_0;
  seq_0_Ixdx2fh1_ast8ri79k paths_0;
  seq_0_Ixdx2fh1_ast8ri79k nimblePaths_0;
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
typedef struct InstRequest_0_sempjk6bn1{
  NU32 origin_0;
  NU32 targetSym_0;
  Table_0_I5rl962_sempjk6bn1 inferred_0;
  seq_0_Io4pvgy1_nifb6mq6y1 requestFrom_0;}
InstRequest_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX54okenX42uf0nifb6mq6y1_sempjk6bn1{
  string_0_sysvq0asl fld_0;
  TokenBuf_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSX54okenX42uf0nifb6mq6y1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_sempjk6bn1{
  string_0_sysvq0asl fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_sempjk6bn1;
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
  seq_0_In6doa_ast8ri79k fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21{
  NU32 fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21;
typedef struct seq_0_Idl3iy1_comaa5xpt1{
  NI32 len_0;
  MethodIndexEntry_0_sempjk6bn1* data_0;}
seq_0_Idl3iy1_comaa5xpt1;
typedef struct ClassEntry_0_sempjk6bn1{
  seq_0_Idl3iy1_comaa5xpt1 methods_0;}
ClassEntry_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43lassX45ntry0sempjk6bn1_sempjk6bn1{
  NU32 fld_0;
  ClassEntry_0_sempjk6bn1 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX43lassX45ntry0sempjk6bn1_sempjk6bn1;
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
  seq_0_In6doa_ast8ri79k fld_1;}
X60Qt_0_IAtupleAR0SX53ymX49d0nifh7u8pu1SX53trX49d0R19ZSseq0X49n6doa_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1{
  NU32 fld_0;
  TokenBuf_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX54okenX42uf0nifb6mq6y1_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1{
  NU32 fld_0;
  Cursor_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX43ursor0nifb6mq6y1_sempjk6bn1;
typedef struct xint_0_xinat3x34{
  NB8 nan_0;
  NB8 neg_0;
  NU64 val_0;}
xint_0_xinat3x34;
typedef struct Item_0_sempjk6bn1{
  Cursor_0_nifb6mq6y1 n_0;
  Cursor_0_nifb6mq6y1 typ_0;
  NimonySym_0_nimry5ra91 kind_0;}
Item_0_sempjk6bn1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1{
  NU32 fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1SX53ymX49d0R16_sempjk6bn1;
typedef struct Sym_0_symiqlwtg1{
  NimonySym_0_nimry5ra91 kind_0;
  NU32 name_0;
  NI32 pos_0;}
Sym_0_symiqlwtg1;
typedef struct MethodIndexEntry_0_sempjk6bn1{
  NU32 fn_0;
  NU32 signature_0;}
MethodIndexEntry_0_sempjk6bn1;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_comaa5xpt1;
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_set37vj3r(void);
extern void X60Qini_0_tabcr240b1(void);
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
extern void X60Qini_0_sempjk6bn1(void);
extern void X60Qini_0_typurxiqa1(void);
extern void X60Qini_0_xinat3x34(void);
extern void X60Qini_0_buiyylk1h1(void);
extern void X60Qini_0_renqb5hy11(void);
extern void X60Qini_0_ast8ri79k(void);
extern void X60Qini_0_feaji4clb1(void);
extern void X60Qini_0_symiqlwtg1(void);
extern void X60Qini_0_sig6uoro1(void);
extern void X60Qini_0_explnj22x1(void);
extern void X60Qini_0_sta2iipes(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_tagygirdh1(void);
NB8 X60QiniGuard_0_sigekpubi1;
static inline NI32 len_3_I9hktyf_sigekpubi1(seq_0_Iflf8jf1_fiepkwzpc s_58){
  NI32 result_107;
  result_107 = s_58.len_0;
  return result_107;}
static inline void putQ_7_Iiblebk_sigekpubi1(seq_0_Iflf8jf1_fiepkwzpc* s_59, NI32 i_30, NB8 elem_14){
  NB8 X60Qx_1214;
  if (i_30 < (*s_59).len_0){
    X60Qx_1214 = (0 <= i_30);}
  else {
    X60Qx_1214 = NIM_FALSE;}
  if ((!X60Qx_1214)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  (*s_59).data_0[i_30] = elem_14;}
void X60Qini_0_sigekpubi1(void){
  if (X60QiniGuard_0_sigekpubi1){
    return;}
  X60QiniGuard_0_sigekpubi1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_set37vj3r();
  X60Qini_0_tabcr240b1();
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
  X60Qini_0_sempjk6bn1();
  X60Qini_0_typurxiqa1();
  X60Qini_0_xinat3x34();
  X60Qini_0_buiyylk1h1();
  X60Qini_0_renqb5hy11();
  X60Qini_0_ast8ri79k();
  X60Qini_0_feaji4clb1();
  X60Qini_0_symiqlwtg1();
  X60Qini_0_sig6uoro1();
  X60Qini_0_explnj22x1();
  X60Qini_0_sta2iipes();
  X60Qini_0_symkyk35i1();
  X60Qini_0_tagygirdh1();}
