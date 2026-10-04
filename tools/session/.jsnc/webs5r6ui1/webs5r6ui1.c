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
NIM_THREADVAR NB8 LENGC_ERR_;
#include <stdio.h>
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct seq_0_I50urnw_croph25r5 seq_0_I50urnw_croph25r5;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct Cursor_0_nifb6mq6y1 Cursor_0_nifb6mq6y1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAiS32ZArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax X60Qt_0_IAtupleAiS32ZArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAiS32ZArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax X60Qt_0_IAtupleAiS32ZArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAiS32ZArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax X60Qt_0_IAtupleAiS32ZArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAiS32ZArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax X60Qt_0_IAtupleAiS32ZArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax;
typedef struct X60Qt_0_IArefSX46rameX4fbj0intzsnzax_intzsnzax X60Qt_0_IArefSX46rameX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IArefSX46orX53inkX4fbj0intzsnzax_intzsnzax X60Qt_0_IArefSX46orX53inkX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5 X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax;
typedef struct X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43oroX4fbj0intzsnzax_intzsnzax X60Qt_0_IArefSX43oroX4fbj0intzsnzax_intzsnzax;
typedef struct TimerEntry_0_intzsnzax TimerEntry_0_intzsnzax;
typedef struct Breakpoint_0_dbgj4vyzj1 Breakpoint_0_dbgj4vyzj1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct DbgSnapshot_0_dbgj4vyzj1 DbgSnapshot_0_dbgj4vyzj1;
typedef struct seq_0_Iflf8jf1_aow7lb5cq1 seq_0_Iflf8jf1_aow7lb5cq1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct BreakHit_0_dbgj4vyzj1 BreakHit_0_dbgj4vyzj1;
typedef struct X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax;
typedef struct X60Qt_0_IArefSX53amplerX4fbj0obs4v9ato1_intzsnzax X60Qt_0_IArefSX53amplerX4fbj0obs4v9ato1_intzsnzax;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax;
typedef struct X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21;
typedef struct CallEvent_0_trakthy001 CallEvent_0_trakthy001;
typedef struct EvalEvent_0_trakthy001 EvalEvent_0_trakthy001;
typedef struct BranchEvent_0_trakthy001 BranchEvent_0_trakthy001;
typedef struct Step_0_trakthy001 Step_0_trakthy001;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax;
typedef struct JsValue_0_jsfc0lwq21 JsValue_0_jsfc0lwq21;
typedef struct PathGrant_0_iop7yt73v PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v ReadRecord_0_iop7yt73v;
typedef struct X60Qt_0_IArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax X60Qt_0_IArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax X60Qt_0_IArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax X60Qt_0_IArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax X60Qt_0_IArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax X60Qt_0_IArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax X60Qt_0_IArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1 X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct VarSnap_0_dbgj4vyzj1 VarSnap_0_dbgj4vyzj1;
typedef struct X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1 X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1;
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1 X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1;
typedef struct X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax;
typedef struct Branch_0_hlweqpif51 Branch_0_hlweqpif51;
typedef struct CaseBranch_0_hlweqpif51 CaseBranch_0_hlweqpif51;
typedef struct seq_0_I50urnw_croph25r5{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_croph25r5;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251)(void);
typedef struct seq_0_Iygo52q1_hos5i19e11{
  NI32 len_0;
  FILE** data_0;}
seq_0_Iygo52q1_hos5i19e11;
typedef struct seq_0_I9xd2d01_hos5i19e11{
  NI32 len_0;
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** data_0;}
seq_0_I9xd2d01_hos5i19e11;
typedef N_NIMCALL_PTR(Value_0_valzr1t4f,  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251)(NI64, string_0_sysvq0asl, seq_0_I50urnw_croph25r5, NB8*);
typedef struct OutSink_Obj_0_natd5co251{
  string_0_sysvq0asl outBuf_0;
  string_0_sysvq0asl errBuf_0;
  NI32 exitCode_0;
  NB8 didQQuit_0;
  string_0_sysvq0asl inBuf_0;
  NI32 inPos_0;
  NB8 inLoaded_0;
  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251 inLoad_0;
  string_0_sysvq0asl progName_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 argv_0;
  seq_0_Iygo52q1_hos5i19e11 fds_0;
  seq_0_I9xd2d01_hos5i19e11 pipeFds_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 envKeys_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 envVals_0;
  NB8 envSeeded_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 failedReads_0;
  NI32 failedReadCount_0;
  NI64 hostContext_0;
  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251 hostCall_0;
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* policy_0;}
OutSink_Obj_0_natd5co251;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5{
  NI r_00;
  OutSink_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct seq_0_Isyzizu1_fiepkwzpc{
  NI32 len_0;
  Cursor_0_nifb6mq6y1* data_0;}
seq_0_Isyzizu1_fiepkwzpc;
typedef struct seq_0_I6tbqwu_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax* data_0;}
seq_0_I6tbqwu_intzsnzax;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_Iwtkpzp1_intzsnzax{
  seq_0_I6tbqwu_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Iwtkpzp1_intzsnzax;
typedef struct seq_0_I9khh3u1_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax* data_0;}
seq_0_I9khh3u1_intzsnzax;
typedef struct Table_0_Izxqu3l_intzsnzax{
  seq_0_I9khh3u1_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Izxqu3l_intzsnzax;
typedef struct seq_0_Innu9ec1_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleAiS32ZArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax* data_0;}
seq_0_Innu9ec1_intzsnzax;
typedef struct Table_0_Iq4i0sb1_intzsnzax{
  seq_0_Innu9ec1_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Iq4i0sb1_intzsnzax;
typedef struct seq_0_I2r8ooz_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleAiS32ZArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax* data_0;}
seq_0_I2r8ooz_intzsnzax;
typedef struct Table_0_I67qc3g_intzsnzax{
  seq_0_I2r8ooz_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_I67qc3g_intzsnzax;
typedef struct seq_0_Ibfbbbw1_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleAiS32ZArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax* data_0;}
seq_0_Ibfbbbw1_intzsnzax;
typedef struct Table_0_Inj0mfw_intzsnzax{
  seq_0_Ibfbbbw1_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Inj0mfw_intzsnzax;
typedef struct seq_0_Ifzb5nt_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleAiS32ZArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax* data_0;}
seq_0_Ifzb5nt_intzsnzax;
typedef struct Table_0_I7bup84_intzsnzax{
  seq_0_Ifzb5nt_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_I7bup84_intzsnzax;
typedef struct seq_0_I8hny96_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax* data_0;}
seq_0_I8hny96_intzsnzax;
typedef struct Table_0_Idzo7511_intzsnzax{
  seq_0_I8hny96_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Idzo7511_intzsnzax;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct seq_0_I55hg7a_intzsnzax{
  NI32 len_0;
  X60Qt_0_IArefSX46rameX4fbj0intzsnzax_intzsnzax** data_0;}
seq_0_I55hg7a_intzsnzax;
typedef struct seq_0_Ic9gdzm1_intzsnzax{
  NI32 len_0;
  seq_0_I50urnw_croph25r5* data_0;}
seq_0_Ic9gdzm1_intzsnzax;
typedef struct seq_0_Iwbgwyg_intzsnzax{
  NI32 len_0;
  X60Qt_0_IArefSX46orX53inkX4fbj0intzsnzax_intzsnzax** data_0;}
seq_0_Iwbgwyg_intzsnzax;
typedef NU8 ValueKind_0_valzr1t4f;

#define vkNil_0_valzr1t4f ((NU8)0)
#define vkInt_0_valzr1t4f ((NU8)1)
#define vkUInt_0_valzr1t4f ((NU8)2)
#define vkFloat_0_valzr1t4f ((NU8)3)
#define vkBool_0_valzr1t4f ((NU8)4)
#define vkChar_0_valzr1t4f ((NU8)5)
#define vkString_0_valzr1t4f ((NU8)6)
#define vkEnum_0_valzr1t4f ((NU8)7)
#define vkSeq_0_valzr1t4f ((NU8)8)
#define vkArray_0_valzr1t4f ((NU8)9)
#define vkTuple_0_valzr1t4f ((NU8)10)
#define vkObject_0_valzr1t4f ((NU8)11)
#define vkRef_0_valzr1t4f ((NU8)12)
#define vkPtr_0_valzr1t4f ((NU8)13)
#define vkSet_0_valzr1t4f ((NU8)14)
#define vkProc_0_valzr1t4f ((NU8)15)
#define vkStream_0_valzr1t4f ((NU8)16)
#define vkCont_0_valzr1t4f ((NU8)17)
typedef struct xint_0_xinat3x34{
  NB8 nan_0;
  NB8 neg_0;
  NU64 val_0;}
xint_0_xinat3x34;
typedef struct Value_0_valzr1t4f{
  ValueKind_0_valzr1t4f kind_0;
  union {
    struct {
      }
    ;
    struct {
      xint_0_xinat3x34 ival_0;
      NI32 bits_0;}
    ;
    struct {
      NF64 fval_0;
      NI32 fbits_0;}
    ;
    struct {
      NB8 bval_0;}
    ;
    struct {
      NC8 cval_0;}
    ;
    struct {
      string_0_sysvq0asl sval_0;}
    ;
    struct {
      NI32 eord_0;
      NU32 ekind_0;}
    ;
    struct {
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sq_0;}
    ;
    struct {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arr_0;}
    ;
    struct {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* obj_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* rf_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* loc_0;
      X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* ov_0;}
    ;
    struct {
      X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* st_0;}
    ;
    struct {
      X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* env_0;
      NU32 fn_0;
      NI32 pidxRaw_0;
      NI32 resumeRaw_0;}
    ;
    struct {
      NB8 toErr_0;}
    ;
    struct {
      X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* coro_0;}
    ;}
  ;}
Value_0_valzr1t4f;
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
typedef struct seq_0_I1q3n2c_intzsnzax{
  NI32 len_0;
  TimerEntry_0_intzsnzax* data_0;}
seq_0_I1q3n2c_intzsnzax;
typedef struct seq_0_Ih5xjlg1_intzsnzax{
  NI32 len_0;
  X60Qt_0_IArefSX43oroX4fbj0intzsnzax_intzsnzax** data_0;}
seq_0_Ih5xjlg1_intzsnzax;
typedef NU8 DebugMode_0_dbgj4vyzj1;

#define dmRun_0_dbgj4vyzj1 ((NU8)0)
#define dmBreak_0_dbgj4vyzj1 ((NU8)1)
#define dmStep_0_dbgj4vyzj1 ((NU8)2)
typedef struct seq_0_Ik20wl91_dbgj4vyzj1{
  NI32 len_0;
  Breakpoint_0_dbgj4vyzj1* data_0;}
seq_0_Ik20wl91_dbgj4vyzj1;
typedef struct DebugConfig_0_dbgj4vyzj1{
  DebugMode_0_dbgj4vyzj1 mode_0;
  NB8 session_0;
  seq_0_Ik20wl91_dbgj4vyzj1 breakpoints_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 expand_0;}
DebugConfig_0_dbgj4vyzj1;
typedef NU8 StepMode_0_dbgj4vyzj1;

#define ssContinue_0_dbgj4vyzj1 ((NU8)0)
#define ssInto_0_dbgj4vyzj1 ((NU8)1)
#define ssOver_0_dbgj4vyzj1 ((NU8)2)
#define ssOut_0_dbgj4vyzj1 ((NU8)3)
typedef struct seq_0_Ilvi9zw_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* data_0;}
seq_0_Ilvi9zw_intzsnzax;
typedef struct Table_0_Isfp6gt1_intzsnzax{
  seq_0_Ilvi9zw_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Isfp6gt1_intzsnzax;
typedef struct seq_0_I15ujth_intzsnzax{
  NI32 len_0;
  DbgSnapshot_0_dbgj4vyzj1* data_0;}
seq_0_I15ujth_intzsnzax;
typedef struct seq_0_Ibhsdeb1_dbgj4vyzj1{
  NI32 len_0;
  seq_0_Iflf8jf1_aow7lb5cq1* data_0;}
seq_0_Ibhsdeb1_dbgj4vyzj1;
typedef struct seq_0_Iflf8jf1_aow7lb5cq1{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_aow7lb5cq1;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct seq_0_Iktj6bv_intzsnzax{
  NI32 len_0;
  BreakHit_0_dbgj4vyzj1* data_0;}
seq_0_Iktj6bv_intzsnzax;
typedef struct seq_0_Ic9cn7e1_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax* data_0;}
seq_0_Ic9cn7e1_intzsnzax;
typedef struct Table_0_Ibw7a2q1_intzsnzax{
  seq_0_Ic9cn7e1_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ibw7a2q1_intzsnzax;
typedef struct seq_0_Isiz2tl_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21* data_0;}
seq_0_Isiz2tl_intzsnzax;
typedef struct Table_0_Ish679o_intzsnzax{
  seq_0_Isiz2tl_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ish679o_intzsnzax;
typedef struct Interp_Obj_0_intzsnzax{
  seq_0_In6doa_arecyyj7v procs_0;
  seq_0_Isyzizu1_fiepkwzpc procBodies_0;
  Table_0_Iwtkpzp1_intzsnzax callCache_0;
  Table_0_Izxqu3l_intzsnzax localSeedCache_0;
  seq_0_In6doa_arecyyj7v hotDriftSyms_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 hotDriftInfo_0;
  NB8 driftArmed_0;
  NB8 driftTypeCheck_0;
  NB8 loadCheck_0;
  Table_0_Iq4i0sb1_intzsnzax forCache_0;
  Table_0_I67qc3g_intzsnzax ifCache_0;
  Table_0_Inj0mfw_intzsnzax caseCache_0;
  Table_0_I7bup84_intzsnzax headCache_0;
  Table_0_Idzo7511_intzsnzax globalIndex_0;
  seq_0_In6doa_arecyyj7v enumSyms_0;
  seq_0_Ift2sne_aow7lb5cq1 enumOrds_0;
  seq_0_I55hg7a_intzsnzax frames_0;
  seq_0_I55hg7a_intzsnzax framePool_0;
  seq_0_Ic9gdzm1_intzsnzax argPool_0;
  seq_0_Iwbgwyg_intzsnzax sinks_0;
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_0;
  X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax* trace_0;
  X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* run_0;
  NB8 raised_0;
  Value_0_valzr1t4f excVal_0;
  NB8 failPending_0;
  NU32 failSym_0;
  NI32 keepOvf_0;
  NB8 overflowFlag_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* flatScratch_0;
  NB8 flatStore_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flatRegion_0;
  NI32 flatOff_0;
  NI32 flatBits_0;
  TCode_0_valzr1t4f flatCode_0;
  NU32 flatEtype_0;
  X60Qt_0_IArefSX43oroX4fbj0intzsnzax_intzsnzax* curCoro_0;
  X60Qt_0_IArefSX43oroX4fbj0intzsnzax_intzsnzax* pendingChild_0;
  Value_0_valzr1t4f scheduler_0;
  seq_0_I1q3n2c_intzsnzax timerHeap_0;
  NI32 virtualNow_0;
  NI32 timerSeq_0;
  seq_0_Ih5xjlg1_intzsnzax readyQQ_0;
  NI32 readyHead_0;
  NB8 poolStoppedFlag_0;
  NU32 breakLabel_0;
  DebugConfig_0_dbgj4vyzj1 dbg_0;
  NB8 dbgOn_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 routineStack_0;
  NB8 dbgNeedsRoutine_0;
  seq_0_Ift2sne_aow7lb5cq1 dbgLineSet_0;
  StepMode_0_dbgj4vyzj1 dbgStepMode_0;
  NI32 dbgStepDepth_0;
  NI32 dbgStepRepeat_0;
  NB8 dbgQQuiet_0;
  NB8 dbgDiffOnly_0;
  Table_0_Isfp6gt1_intzsnzax dbgPrevLocals_0;
  seq_0_I15ujth_intzsnzax dbgSnapshots_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 dbgWatches_0;
  Table_0_Isfp6gt1_intzsnzax dbgWatchVals_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 dbgWhenNames_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 dbgWhenVals_0;
  NI32 dbgNthWanted_0;
  NI32 dbgNthSeen_0;
  NB8 dbgSession_0;
  NB8 dbgSessionCut_0;
  NI32 dbgPauseCount_0;
  NB8 dbgCapFull_0;
  seq_0_Ibhsdeb1_dbgj4vyzj1 dbgSeenLines_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 dbgSeenFiles_0;
  string_0_sysvq0asl dbgLastFile_0;
  NI32 dbgLastFileIdx_0;
  seq_0_Iflf8jf1_aow7lb5cq1 dbgExpandOk_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 dbgSeenFuncs_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 dbgKnownFiles_0;
  seq_0_Ibhsdeb1_dbgj4vyzj1 dbgKnownLines_0;
  seq_0_Ift2sne_aow7lb5cq1 dbgLocFileIds_0;
  seq_0_Ift2sne_aow7lb5cq1 dbgLocLines_0;
  NB8 curStmtValid_0;
  NI32 curFileId_0;
  NI32 curLine_0;
  seq_0_Ift2sne_aow7lb5cq1 xferFileIds_0;
  seq_0_Ift2sne_aow7lb5cq1 xferLines_0;
  NI32 xferHead_0;
  seq_0_Ift2sne_aow7lb5cq1 routineFiles_0;
  seq_0_Ift2sne_aow7lb5cq1 routineLines_0;
  seq_0_Ift2sne_aow7lb5cq1 dbgCallFiles_0;
  seq_0_Ift2sne_aow7lb5cq1 dbgCallLines_0;
  NU32 pendCallInfo_0;
  NB8 pendCallValid_0;
  string_0_sysvq0asl dbgFinishFile_0;
  NI32 dbgFinishLine_0;
  NB8 dbgAtEpilogue_0;
  Cursor_0_nifb6mq6y1 curStmt_0;
  seq_0_Iktj6bv_intzsnzax captures_0;
  NU32 curInfo_0;
  NB8 abortCaptured_0;
  NU32 abortInfo_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 abortStack_0;
  string_0_sysvq0asl abortSite_0;
  NB8 abortTrack_0;
  NB8 observeOn_0;
  X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax* cov_0;
  X60Qt_0_IArefSX53amplerX4fbj0obs4v9ato1_intzsnzax* smp_0;
  NB8 jitOn_0;
  NB8 jitTried_0;
  NI32 jitThreshold_0;
  NI32 jitCompiled_0;
  NB8 jitHybridOnly_0;
  string_0_sysvq0asl jitCnifDir_0;
  string_0_sysvq0asl jitBuildDir_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 jitScope_0;
  Table_0_Idzo7511_intzsnzax jitCounts_0;
  Table_0_Ibw7a2q1_intzsnzax jitSyms_0;
  Table_0_Ibw7a2q1_intzsnzax redeclSyms_0;
  Cursor_0_nifb6mq6y1 progRoot_0;
  NB8 progRootValid_0;
  NB8 hybridOn_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 interpretMods_0;
  X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* hybridReg_0;
  NI32 wallGen_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 wallMods_0;
  seq_0_Ift2sne_aow7lb5cq1 wallProcs_0;
  seq_0_Ift2sne_aow7lb5cq1 wallIn_0;
  seq_0_Ift2sne_aow7lb5cq1 wallNat_0;
  Table_0_Ish679o_intzsnzax wallShimmed_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 wallNameMods_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 wallNameSrcs_0;
  NB8 wallNamesLoaded_0;
  string_0_sysvq0asl wallCnifDir_0;
  string_0_sysvq0asl wallBuildDir_0;
  NB8 wallArmed_0;
  string_0_sysvq0asl wallLastNote_0;}
Interp_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  Interp_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef struct HotModule_Obj_0_intzsnzax{
  string_0_sysvq0asl path_0;
  string_0_sysvq0asl root_0;
  TokenBuf_0_nifb6mq6y1 buf_0;
  TokenBuf_0_nifb6mq6y1 owning_0;
  NB8 reading_0;
  seq_0_In6doa_arecyyj7v syms_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 bases_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 sigs_0;
  NI32 generation_0;
  NI32 newGlobals_0;
  seq_0_In6doa_arecyyj7v driftSyms_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 drift_0;}
HotModule_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  HotModule_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax;
typedef NU8 TraceMode_0_trakthy001;

#define tmOff_0_trakthy001 ((NU8)0)
#define tmCalls_0_trakthy001 ((NU8)1)
#define tmFull_0_trakthy001 ((NU8)2)
#define tmProfile_0_trakthy001 ((NU8)3)
typedef struct seq_0_I00yatg_trakthy001{
  NI32 len_0;
  CallEvent_0_trakthy001* data_0;}
seq_0_I00yatg_trakthy001;
typedef struct seq_0_Ins76rj1_trakthy001{
  NI32 len_0;
  EvalEvent_0_trakthy001* data_0;}
seq_0_Ins76rj1_trakthy001;
typedef struct seq_0_Iuignwf1_trakthy001{
  NI32 len_0;
  BranchEvent_0_trakthy001* data_0;}
seq_0_Iuignwf1_trakthy001;
typedef struct seq_0_Is6l9yr_trakthy001{
  NI32 len_0;
  Step_0_trakthy001* data_0;}
seq_0_Is6l9yr_trakthy001;
typedef struct seq_0_Ix7ee6h_obs4v9ato1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* data_0;}
seq_0_Ix7ee6h_obs4v9ato1;
typedef struct Table_0_Idzlvr_obs4v9ato1{
  seq_0_Ix7ee6h_obs4v9ato1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Idzlvr_obs4v9ato1;
typedef struct Trace_Obj_0_trakthy001{
  TraceMode_0_trakthy001 mode_0;
  NI32 depth_0;
  string_0_sysvq0asl text_0;
  seq_0_I00yatg_trakthy001 calls_0;
  seq_0_Ins76rj1_trakthy001 evals_0;
  seq_0_Iuignwf1_trakthy001 branches_0;
  seq_0_Is6l9yr_trakthy001 steps_0;
  NI32 nCalls_0;
  NI32 maxDepth_0;
  NB8 truncated_0;
  NI32 lines_0;
  seq_0_Ift2sne_aow7lb5cq1 frames_0;
  Table_0_Idzlvr_obs4v9ato1 prof_0;
  NI32 maxRecordDepth_0;
  seq_0_Iflf8jf1_aow7lb5cq1 recStack_0;}
Trace_Obj_0_trakthy001;
typedef struct X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax{
  NI r_00;
  Trace_Obj_0_trakthy001 d_00;}
X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax;
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21)(void);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISX4asX56alue0jsfc0lwq21SEAnimcallZAfalseZAR34_jsfc0lwq21)(JsValue_0_jsfc0lwq21);
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct JsValue_0_jsfc0lwq21{
  NI32 h_0;}
JsValue_0_jsfc0lwq21;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct PipeBuf_Obj_0_natd5co251{
  string_0_sysvq0asl data_0;
  NI32 rpos_0;
  NI32 writeFd_0;
  NB8 writeClosed_0;}
PipeBuf_Obj_0_natd5co251;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11{
  NI r_00;
  PipeBuf_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct seq_0_Iq7pam4_iop7yt73v{
  NI32 len_0;
  PathGrant_0_iop7yt73v* data_0;}
seq_0_Iq7pam4_iop7yt73v;
typedef struct seq_0_Iero8tq_iop7yt73v{
  NI32 len_0;
  ReadRecord_0_iop7yt73v* data_0;}
seq_0_Iero8tq_iop7yt73v;
typedef struct IoPolicy_Obj_0_iop7yt73v{
  NB8 on_0;
  NI32 granted_0;
  seq_0_Iq7pam4_iop7yt73v grants_0;
  NB8 sealed_0;
  string_0_sysvq0asl owner_0;
  NB8 auditReads_0;
  seq_0_Iero8tq_iop7yt73v reads_0;
  NI32 violations_0;
  string_0_sysvq0asl violNative_0;
  NI32 violNeeded_0;}
IoPolicy_Obj_0_iop7yt73v;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax{
  NI r_00;
  IoPolicy_Obj_0_iop7yt73v d_00;}
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax{
  NU32 fld_0;
  X60Qt_0_IArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax* fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax{
  NU32 fld_0;
  X60Qt_0_IArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax* fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAiS32ZArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax{
  NI32 fld_0;
  X60Qt_0_IArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax* fld_1;}
X60Qt_0_IAtupleAiS32ZArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAiS32ZArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax{
  NI32 fld_0;
  X60Qt_0_IArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax* fld_1;}
X60Qt_0_IAtupleAiS32ZArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAiS32ZArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax{
  NI32 fld_0;
  X60Qt_0_IArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax* fld_1;}
X60Qt_0_IAtupleAiS32ZArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAiS32ZArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax{
  NI32 fld_0;
  X60Qt_0_IArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax* fld_1;}
X60Qt_0_IAtupleAiS32ZArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax{
  NU32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax;
typedef struct seq_0_Iw8xl5b1_arecyyj7v{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_arecyyj7v;
typedef struct Frame_Obj_0_intzsnzax{
  seq_0_In6doa_arecyyj7v vars_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;
  NU64 varMask_0;
  NI32 maskLen_0;
  seq_0_In6doa_arecyyj7v envVars_0;
  seq_0_Iw8xl5b1_arecyyj7v envCells_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* resultCell_0;
  NB8 returned_0;
  Value_0_valzr1t4f retVal_0;
  NB8 isGlobal_0;
  NB8 inPassive_0;
  NB8 fnBpFired_0;}
Frame_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX46rameX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  Frame_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX46rameX4fbj0intzsnzax_intzsnzax;
typedef NU8 Flow_0_intzsnzax;

#define flNormal_0_intzsnzax ((NU8)0)
#define flBreak_0_intzsnzax ((NU8)1)
#define flContinue_0_intzsnzax ((NU8)2)
#define flReturn_0_intzsnzax ((NU8)3)
#define flRaise_0_intzsnzax ((NU8)4)
typedef struct ForSink_Obj_0_intzsnzax{
  seq_0_Iw8xl5b1_arecyyj7v loopCells_0;
  seq_0_In6doa_arecyyj7v loopVarSyms_0;
  Cursor_0_nifb6mq6y1 binder_0;
  Cursor_0_nifb6mq6y1 body_0;
  X60Qt_0_IArefSX46rameX4fbj0intzsnzax_intzsnzax* callerFrame_0;
  Flow_0_intzsnzax flow_0;
  NI32 resumeSkip_0;
  NI32 consumed_0;}
ForSink_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX46orX53inkX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  ForSink_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX46orX53inkX4fbj0intzsnzax_intzsnzax;
typedef struct seq_0_Ixktxxh1_runx5db6s1{
  NI32 len_0;
  X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* data_0;}
seq_0_Ixktxxh1_runx5db6s1;
typedef struct Table_0_If84ub3_runx5db6s1{
  seq_0_Ixktxxh1_runx5db6s1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_If84ub3_runx5db6s1;
typedef struct RunEmitter_Obj_0_runx5db6s1{
  NB8 enabled_0;
  NB8 ops_0;
  TokenBuf_0_nifb6mq6y1 buf_0;
  Cursor_0_nifb6mq6y1 base_0;
  Table_0_If84ub3_runx5db6s1 cellId_0;
  NI32 nextId_0;
  seq_0_Ift2sne_aow7lb5cq1 iterStack_0;
  NU32 tRunmod_0;
  NU32 tRunstmts_0;
  NU32 tRunlet_0;
  NU32 tAt_0;
  NU32 tRunloop_0;
  NU32 tRuniter_0;
  NU32 tBinds_0;
  NU32 tBind_0;
  NU32 tRunop_0;
  NU32 tRuncall_0;
  NU32 tVnil_0;
  NU32 tVint_0;
  NU32 tVuint_0;
  NU32 tVfloat_0;
  NU32 tVbool_0;
  NU32 tVchar_0;
  NU32 tVstr_0;
  NU32 tVenum_0;
  NU32 tVseq_0;
  NU32 tVarr_0;
  NU32 tVtup_0;
  NU32 tVobj_0;
  NU32 tFld_0;
  NU32 tVref_0;
  NU32 tVptr_0;
  NU32 tVrefback_0;
  NU32 tVset_0;
  NU32 tVproc_0;
  NU32 tVstream_0;}
RunEmitter_Obj_0_runx5db6s1;
typedef struct X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax{
  NI r_00;
  RunEmitter_Obj_0_runx5db6s1 d_00;}
X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_arecyyj7v names_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct Cell_Obj_0_valzr1t4f{
  Value_0_valzr1t4f v_0;}
Cell_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  Cell_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct PtrOv_Obj_0_valzr1t4f{
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0;
  NI32 base_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0;
  NI32 foff_0;
  NI16 elemBits_0;
  TCode_0_valzr1t4f ecode_0;
  NU32 etype_0;}
PtrOv_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v{
  NI r_00;
  PtrOv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IAarrayAuS64ZS4_intzsnzax{
  NU64 a[4];}
X60Qt_0_IAarrayAuS64ZS4_intzsnzax;
typedef struct SetBox_Obj_0_valzr1t4f{
  X60Qt_0_IAarrayAuS64ZS4_intzsnzax words_0;}
SetBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  SetBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct ClosureEnv_Obj_0_valzr1t4f{
  seq_0_In6doa_arecyyj7v vars_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;
  X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* coro_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;}
ClosureEnv_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  ClosureEnv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef NU8 RegionKind_0_valzr1t4f;

#define rkBytes_0_valzr1t4f ((NU8)0)
#define rkSeq_0_valzr1t4f ((NU8)1)
#define rkArr_0_valzr1t4f ((NU8)2)
#define rkStr_0_valzr1t4f ((NU8)3)
#define rkCell_0_valzr1t4f ((NU8)4)
#define rkObj_0_valzr1t4f ((NU8)5)
#define rkForeign_0_valzr1t4f ((NU8)6)
typedef struct seq_0_Incv1wn_arecyyj7v{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_arecyyj7v;
typedef struct FlatRegion_Obj_0_valzr1t4f{
  RegionKind_0_valzr1t4f kind_0;
  union {
    struct {
      seq_0_Incv1wn_arecyyj7v bytes_0;
      NB8 freed_0;
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* objOverlay_0;}
    ;
    struct {
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sbox_0;
      NI32 sEbits_0;
      TCode_0_valzr1t4f sEcode_0;}
    ;
    struct {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* abox_0;
      NI32 aEbits_0;
      TCode_0_valzr1t4f aEcode_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* scell_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* ccell_0;}
    ;
    struct {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* obox_0;
      seq_0_Ift2sne_aow7lb5cq1 offs_0;}
    ;
    struct {
      NU64 haddr_0;
      NI32 hlen_0;}
    ;}
  ;}
FlatRegion_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  FlatRegion_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct Coro_Obj_0_intzsnzax{
  CoroRef_Obj_0_valzr1t4f Q;
  X60Qt_0_IArefSX46rameX4fbj0intzsnzax_intzsnzax* frame_0;
  Cursor_0_nifb6mq6y1 resumeAt_0;
  X60Qt_0_IArefSX43oroX4fbj0intzsnzax_intzsnzax* caller_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* retCell_0;
  NB8 started_0;
  NB8 parked_0;
  NB8 finished_0;
  NB8 awaitingPark_0;
  NB8 pullMode_0;
  Value_0_valzr1t4f yieldVal_0;}
Coro_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  Coro_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX43oroX4fbj0intzsnzax_intzsnzax;
typedef struct TimerEntry_0_intzsnzax{
  NI32 due_0;
  NI32 seqno_0;
  X60Qt_0_IArefSX43oroX4fbj0intzsnzax_intzsnzax* coro_0;}
TimerEntry_0_intzsnzax;
typedef NU8 BreakKind_0_dbgj4vyzj1;

#define bkLine_0_dbgj4vyzj1 ((NU8)0)
#define bkFunc_0_dbgj4vyzj1 ((NU8)1)
#define bkLineInFunc_0_dbgj4vyzj1 ((NU8)2)
typedef struct Breakpoint_0_dbgj4vyzj1{
  BreakKind_0_dbgj4vyzj1 kind_0;
  NI32 line_0;
  string_0_sysvq0asl funcName_0;
  string_0_sysvq0asl file_0;
  NB8 enabled_0;}
Breakpoint_0_dbgj4vyzj1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct DbgSnapshot_0_dbgj4vyzj1{
  string_0_sysvq0asl name_0;
  NI32 pid_0;
  NI32 wake_0;}
DbgSnapshot_0_dbgj4vyzj1;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct seq_0_Ipg6zum_dbgj4vyzj1{
  NI32 len_0;
  VarSnap_0_dbgj4vyzj1* data_0;}
seq_0_Ipg6zum_dbgj4vyzj1;
typedef struct BreakHit_0_dbgj4vyzj1{
  NI32 line_0;
  string_0_sysvq0asl file_0;
  string_0_sysvq0asl funcName_0;
  seq_0_Ipg6zum_dbgj4vyzj1 vars_0;
  NI32 depth_0;
  NI32 outLen_0;}
BreakHit_0_dbgj4vyzj1;
typedef struct seq_0_Icfzt52_obs4v9ato1{
  NI32 len_0;
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1** data_0;}
seq_0_Icfzt52_obs4v9ato1;
typedef struct seq_0_Iivvdd91_obs4v9ato1{
  NI32 len_0;
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* data_0;}
seq_0_Iivvdd91_obs4v9ato1;
typedef struct Table_0_Ir2mg111_obs4v9ato1{
  seq_0_Iivvdd91_obs4v9ato1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ir2mg111_obs4v9ato1;
typedef struct seq_0_Ivhjttw1_obs4v9ato1{
  NI32 len_0;
  X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1** data_0;}
seq_0_Ivhjttw1_obs4v9ato1;
typedef struct Coverage_Obj_0_obs4v9ato1{
  seq_0_Icfzt52_obs4v9ato1 files_0;
  string_0_sysvq0asl lastName_0;
  NI32 lastIdx_0;
  Table_0_Ir2mg111_obs4v9ato1 siteIdx_0;
  seq_0_Ivhjttw1_obs4v9ato1 sites_0;}
Coverage_Obj_0_obs4v9ato1;
typedef struct X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax{
  NI r_00;
  Coverage_Obj_0_obs4v9ato1 d_00;}
X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax;
typedef struct Sampler_Obj_0_obs4v9ato1{
  NI32 interval_0;
  NI32 counter_0;
  NI32 steps_0;
  NI32 samples_0;
  Table_0_Idzlvr_obs4v9ato1 stacks_0;
  Table_0_Idzlvr_obs4v9ato1 selfC_0;
  Table_0_Idzlvr_obs4v9ato1 totalC_0;}
Sampler_Obj_0_obs4v9ato1;
typedef struct X60Qt_0_IArefSX53amplerX4fbj0obs4v9ato1_intzsnzax{
  NI r_00;
  Sampler_Obj_0_obs4v9ato1 d_00;}
X60Qt_0_IArefSX53amplerX4fbj0obs4v9ato1_intzsnzax;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax{
  NU32 fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax;
typedef struct seq_0_Ixkko8n_run8hsnpi{
  NI32 len_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** data_0;}
seq_0_Ixkko8n_run8hsnpi;
typedef struct HybridRegistry_Obj_0_run8hsnpi{
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* provider_0;
  seq_0_Ixkko8n_run8hsnpi extra_0;}
HybridRegistry_Obj_0_run8hsnpi;
typedef struct X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax{
  NI r_00;
  HybridRegistry_Obj_0_run8hsnpi d_00;}
X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21{
  string_0_sysvq0asl fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21;
typedef struct CallEvent_0_trakthy001{
  string_0_sysvq0asl callee_0;
  seq_0_I50urnw_croph25r5 args_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 argsR_0;
  Value_0_valzr1t4f ret_0;
  string_0_sysvq0asl retR_0;
  NI32 depth_0;
  NI32 line_0;
  string_0_sysvq0asl file_0;}
CallEvent_0_trakthy001;
typedef struct EvalEvent_0_trakthy001{
  string_0_sysvq0asl code_0;
  NI32 line_0;
  NI32 col_0;
  Value_0_valzr1t4f val_0;}
EvalEvent_0_trakthy001;
typedef struct BranchEvent_0_trakthy001{
  string_0_sysvq0asl form_0;
  string_0_sysvq0asl sel_0;
  string_0_sysvq0asl chose_0;
  string_0_sysvq0asl callee_0;
  NI32 line_0;
  NI32 depth_0;}
BranchEvent_0_trakthy001;
typedef NU8 StepKind_0_trakthy001;

#define skEnter_0_trakthy001 ((NU8)0)
#define skExit_0_trakthy001 ((NU8)1)
#define skBranch_0_trakthy001 ((NU8)2)
typedef struct Step_0_trakthy001{
  StepKind_0_trakthy001 kind_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl site_0;}
Step_0_trakthy001;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax;
typedef struct PathGrant_0_iop7yt73v{
  string_0_sysvq0asl prefix_0;
  NI32 caps_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 parts_0;}
PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v{
  string_0_sysvq0asl path_0;
  NU64 hash_0;
  NI32 size_0;
  NB8 hashed_0;}
ReadRecord_0_iop7yt73v;
typedef NU8 SpecialNative_0_intzsnzax;

#define snNone_0_intzsnzax ((NU8)0)
#define snVfsOpenMmap_0_intzsnzax ((NU8)1)
#define snExpandFilename_0_intzsnzax ((NU8)2)
#define snArc_0_intzsnzax ((NU8)3)
#define snDestroyTrace_0_intzsnzax ((NU8)4)
#define snDup_0_intzsnzax ((NU8)5)
#define snWasMoved_0_intzsnzax ((NU8)6)
#define snCopy_0_intzsnzax ((NU8)7)
#define snSink_0_intzsnzax ((NU8)8)
#define snOpen_0_intzsnzax ((NU8)9)
#define snAllocFixed_0_intzsnzax ((NU8)10)
#define snDollar_0_intzsnzax ((NU8)11)
#define snIndex_0_intzsnzax ((NU8)12)
#define snSetScheduler_0_intzsnzax ((NU8)13)
#define snComplete_0_intzsnzax ((NU8)14)
#define snArmTimer_0_intzsnzax ((NU8)15)
#define snCallSoon_0_intzsnzax ((NU8)16)
#define snDrainReady_0_intzsnzax ((NU8)17)
#define snRunForever_0_intzsnzax ((NU8)18)
#define snInitPool_0_intzsnzax ((NU8)19)
#define snSubmit_0_intzsnzax ((NU8)20)
#define snShutdownPool_0_intzsnzax ((NU8)21)
#define snPoolStopped_0_intzsnzax ((NU8)22)
#define snPoolHelp_0_intzsnzax ((NU8)23)
#define snAwait_0_intzsnzax ((NU8)24)
#define snNewSeq_0_intzsnzax ((NU8)25)
#define snPthreadCreate_0_intzsnzax ((NU8)26)
#define snPthreadJoin_0_intzsnzax ((NU8)27)
#define snReadRawData_0_intzsnzax ((NU8)28)
#define snDirs_0_intzsnzax ((NU8)29)
typedef struct CallInfo_Obj_0_intzsnzax{
  string_0_sysvq0asl base_0;
  NU32 sym_0;
  NB8 isNat_0;
  NB8 ownModule_0;
  NB8 natProvides_0;
  NB8 gated_0;
  SpecialNative_0_intzsnzax special_0;
  NB8 streamGatable_0;
  NB8 resolved_0;
  NB8 isMethod_0;
  NB8 isPassive_0;
  NB8 bodyExists_0;
  NB8 nested_0;
  NB8 foreign_0;
  string_0_sysvq0asl foreignName_0;
  string_0_sysvq0asl dynlib_0;
  seq_0_Ift2sne_aow7lb5cq1 dynArgs_0;
  NI32 dynRet_0;
  string_0_sysvq0asl dynWhy_0;
  Cursor_0_nifb6mq6y1 body_0;
  NI32 hybridGen_0;
  NB8 hybridNative_0;
  NI32 wallIdx1_0;}
CallInfo_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  CallInfo_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX43allX49nfoX4fbj0intzsnzax_intzsnzax;
typedef struct LocalSeed_Obj_0_intzsnzax{
  NB8 plain_0;
  string_0_sysvq0asl bn_0;
  string_0_sysvq0asl importcSym_0;
  NB8 isErrno_0;
  NB8 isEnvironment_0;}
LocalSeed_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  LocalSeed_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX4cocalX53eedX4fbj0intzsnzax_intzsnzax;
typedef struct ForLayout_Obj_0_intzsnzax{
  Cursor_0_nifb6mq6y1 iterCur_0;
  Cursor_0_nifb6mq6y1 binderCur_0;
  Cursor_0_nifb6mq6y1 bodyCur_0;
  Cursor_0_nifb6mq6y1 afterCur_0;}
ForLayout_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  ForLayout_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX46orX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct seq_0_I5xzhce1_hlweqpif51{
  NI32 len_0;
  Branch_0_hlweqpif51* data_0;}
seq_0_I5xzhce1_hlweqpif51;
typedef struct IfLayout_Obj_0_intzsnzax{
  seq_0_I5xzhce1_hlweqpif51 branches_0;
  Cursor_0_nifb6mq6y1 afterCur_0;}
IfLayout_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  IfLayout_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX49fX4cayoutX4fbj0intzsnzax_intzsnzax;
typedef struct seq_0_Inh5osa1_hlweqpif51{
  NI32 len_0;
  CaseBranch_0_hlweqpif51* data_0;}
seq_0_Inh5osa1_hlweqpif51;
typedef struct CaseLayout_Obj_0_intzsnzax{
  seq_0_Inh5osa1_hlweqpif51 branches_0;
  Cursor_0_nifb6mq6y1 selCur_0;
  Cursor_0_nifb6mq6y1 afterCur_0;}
CaseLayout_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  CaseLayout_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX43aseX4cayoutX4fbj0intzsnzax_intzsnzax;
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
typedef struct Routine_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 pattern_0;
  Cursor_0_nifb6mq6y1 typevars_0;
  Cursor_0_nifb6mq6y1 params_0;
  Cursor_0_nifb6mq6y1 retType_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 effects_0;
  Cursor_0_nifb6mq6y1 body_0;}
Routine_0_decqocs071;
typedef struct RoutineHead_Obj_0_intzsnzax{
  Routine_0_decqocs071 r_0;
  NB8 inPassive_0;}
RoutineHead_Obj_0_intzsnzax;
typedef struct X60Qt_0_IArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax{
  NI r_00;
  RoutineHead_Obj_0_intzsnzax d_00;}
X60Qt_0_IArefSX52outineX48eadX4fbj0intzsnzax_intzsnzax;
typedef struct X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1{
  NU32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1;
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
typedef struct VarSnap_0_dbgj4vyzj1{
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl value_0;
  NB8 isExpand_0;}
VarSnap_0_dbgj4vyzj1;
typedef struct FileCov_Obj_0_obs4v9ato1{
  string_0_sysvq0asl name_0;
  seq_0_Ift2sne_aow7lb5cq1 hits_0;
  seq_0_Iflf8jf1_aow7lb5cq1 known_0;}
FileCov_Obj_0_obs4v9ato1;
typedef struct X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1{
  NI r_00;
  FileCov_Obj_0_obs4v9ato1 d_00;}
X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1;
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1{
  NI32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1;
typedef struct BranchSite_Obj_0_obs4v9ato1{
  string_0_sysvq0asl file_0;
  NI32 line_0;
  string_0_sysvq0asl form_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 labels_0;
  seq_0_Ift2sne_aow7lb5cq1 counts_0;}
BranchSite_Obj_0_obs4v9ato1;
typedef struct X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1{
  NI r_00;
  BranchSite_Obj_0_obs4v9ato1 d_00;}
X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1;
typedef NU8 ProviderKind_0_run8hsnpi;

#define pkInterpret_0_run8hsnpi ((NU8)0)
#define pkHostNative_0_run8hsnpi ((NU8)1)
#define pkSyscall_0_run8hsnpi ((NU8)2)
#define pkHybridNative_0_run8hsnpi ((NU8)3)
typedef NU8 Codec_0_run8hsnpi;

#define codecIdentity_0_run8hsnpi ((NU8)0)
#define codecFlatCAbi_0_run8hsnpi ((NU8)1)
#define codecJsValue_0_run8hsnpi ((NU8)2)
typedef NU8 Policy_0_run8hsnpi;

#define polFailLoud_0_run8hsnpi ((NU8)0)
#define polFallbackInterpret_0_run8hsnpi ((NU8)1)
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSstring0sysvq0aslAboolZAnimcallZAfalseZAR71_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSseq0X4950urnwAboolZAnimcallZAfalseZAR68_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, seq_0_I50urnw_croph25r5);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX56alue0valzr1t4fAmutSR39ZAboolZAnimcallZAfalseZAR81_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, Value_0_valzr1t4f*, Value_0_valzr1t4f*);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX53ymX49d0nifh7u8pu1AboolZAnimcallZAfalseZAR75_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, NU32);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX53ymX49d0nifh7u8pu1Sstring0sysvq0aslSseq0X4950urnwAmutSX56alue0valzr1t4fZAboolZAnimcallZAfalseZAR129_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, NU32, string_0_sysvq0asl, seq_0_I50urnw_croph25r5, Value_0_valzr1t4f*);
typedef struct HybridProvider_Obj_0_run8hsnpi{
  RootObj_0_sysvq0asl Q;
  ProviderKind_0_run8hsnpi kind_0;
  Codec_0_run8hsnpi codec_0;
  Policy_0_run8hsnpi policy_0;
  string_0_sysvq0asl name_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSstring0sysvq0aslAboolZAnimcallZAfalseZAR71_run8hsnpi resolveFastImpl_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSseq0X4950urnwAboolZAnimcallZAfalseZAR68_run8hsnpi marshalArgs_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX56alue0valzr1t4fAmutSR39ZAboolZAnimcallZAfalseZAR81_run8hsnpi marshalReturn_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX53ymX49d0nifh7u8pu1AboolZAnimcallZAfalseZAR75_run8hsnpi ownsImpl_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX53ymX49d0nifh7u8pu1Sstring0sysvq0aslSseq0X4950urnwAmutSX56alue0valzr1t4fZAboolZAnimcallZAfalseZAR129_run8hsnpi invoke_0;}
HybridProvider_Obj_0_run8hsnpi;
typedef struct X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax{
  NI r_00;
  HybridProvider_Obj_0_run8hsnpi d_00;}
X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax;
typedef struct Branch_0_hlweqpif51{
  NB8 isElse_0;
  Cursor_0_nifb6mq6y1 cond_0;
  Cursor_0_nifb6mq6y1 body_0;}
Branch_0_hlweqpif51;
typedef struct CaseBranch_0_hlweqpif51{
  NB8 isElse_0;
  Cursor_0_nifb6mq6y1 ranges_0;
  Cursor_0_nifb6mq6y1 body_0;}
CaseBranch_0_hlweqpif51;
void eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_webs5r6ui1(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* dest_0);
void eQdestroyQ_ArefSX49nterpX4fbj0intzsnzax_0_webs5r6ui1(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* dest_0);
void eQdestroyQ_ArefSX48otX4doduleX4fbj0intzsnzax_0_webs5r6ui1(X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax* dest_0);
void eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_webs5r6ui1(X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax* dest_0);
extern JsValue_0_jsfc0lwq21 global_0_jsfc0lwq21(string_0_sysvq0asl name_8);
extern void set_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 obj_9, string_0_sysvq0asl name_10, JsValue_0_jsfc0lwq21 val_3);
extern void eQdestroy_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 x_2);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern string_0_sysvq0asl toStr_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_7);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern JsValue_0_jsfc0lwq21 toJs_3_jsfc0lwq21(string_0_sysvq0asl s_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline JsValue_0_jsfc0lwq21 toJs_2_jsfc0lwq21(NB8 b_5);
extern NB8 hotRaised_0_intzsnzax(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* ip_184);
extern void hotClearRaise_0_intzsnzax(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* ip_187);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern Value_0_valzr1t4f vNil_0_valzr1t4f(void);
static inline NB8 isNil_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_3);
static inline JsValue_0_jsfc0lwq21 newJsArray_0_jsfc0lwq21(void);
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_139);
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_140, NI32 i_94);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
extern NI64 asInt_0_valzr1t4f(Value_0_valzr1t4f* v_17);
static inline JsValue_0_jsfc0lwq21 toJs_0_jsfc0lwq21(NI32 x_4);
static inline void add_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 arr_1, JsValue_0_jsfc0lwq21 val_1);
static inline JsValue_0_jsfc0lwq21 toJs_1_jsfc0lwq21(NF64 x_5);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern JsValue_0_jsfc0lwq21 call_2_jsfc0lwq21(JsValue_0_jsfc0lwq21 obj_12, string_0_sysvq0asl name_13, JsValue_0_jsfc0lwq21 a_7, JsValue_0_jsfc0lwq21 b_6);
extern string_0_sysvq0asl jsTypeof_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_9);
extern JsValue_0_jsfc0lwq21 get_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 obj_8, string_0_sysvq0asl name_9);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NI32 toInt_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_4);
extern Value_0_valzr1t4f vInt_0_valzr1t4f(NI64 x_2, NI32 bits_0);
static inline NF64 toFloat_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_5);
extern Value_0_valzr1t4f vFloat_0_valzr1t4f(NF64 f_0, NI32 bits_4);
static inline NB8 toBool_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_6);
extern Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0);
extern Value_0_valzr1t4f vStr_0_valzr1t4f(string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I16952481534133288743_web91l7of;
extern LongString_0_sysvq0asl const strlit_0_I5065733472155119234_modzy18mg1;
extern void webPut_0_web91l7of(string_0_sysvq0asl path_0, string_0_sysvq0asl content_0);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
extern void installWebVfs_0_web91l7of(void);
extern void loadWebModules_0_web91l7of(string_0_sysvq0asl framed_0);
extern void publishMainModule_0_web91l7of(string_0_sysvq0asl src_0);
extern void setupProgramForTesting_0_prorcx25w1(string_0_sysvq0asl dir_0, string_0_sysvq0asl file_0, string_0_sysvq0asl ext_0);
extern X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* newOutSink_0_natd5co251(void);
extern X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax* newTrace_0_trakthy001(TraceMode_0_trakthy001 mode_0);
extern X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* newInterp_0_intzsnzax(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_0, X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax* tr_0);
extern void enableAbortTrack_0_intzsnzax(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* ip_171);
extern X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax* loadHot_0_intzsnzax(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* ip_177, string_0_sysvq0asl path_2, NB8 runInit_0);
extern NB8 hasHot_0_intzsnzax(X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax* hm_7, string_0_sysvq0asl base_5);
static inline JsValue_0_jsfc0lwq21 newJsObject_0_jsfc0lwq21(void);
static inline seq_0_I50urnw_croph25r5 newSeqUninit_0_I8oufjc_croph25r5(NI32 size_14);
extern Value_0_valzr1t4f callHot_0_intzsnzax(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* ip_189, X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax* hm_10, string_0_sysvq0asl base_9, seq_0_I50urnw_croph25r5 args_19);
extern void eQdestroy_1_Inxd7ue1_croph25r5(seq_0_I50urnw_croph25r5 s_35);
extern NB8 hotSafe_0_intzsnzax(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* ip_175);
extern NB8 swapHot_0_intzsnzax(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* ip_180, X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax* hm_4, NB8 runInit_1);
extern NB8 swapHotAppend_0_intzsnzax(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* ip_181, X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax* hm_5, NI32 alreadyRun_0, NI32* ranTo_0);
static inline JsValue_0_jsfc0lwq21 toJs_4_jsfc0lwq21(X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21 p_3);
static inline JsValue_0_jsfc0lwq21 toJs_5_jsfc0lwq21(X60Qt_0_ISX4asX56alue0jsfc0lwq21SEAnimcallZAfalseZAR34_jsfc0lwq21 p_4);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void eQdestroyQ_SX4futX53inkX4fbj0natd5co251_0_natd5co251(OutSink_Obj_0_natd5co251* dest_0);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void eQdestroyQ_SX49nterpX4fbj0intzsnzax_0_intzsnzax(Interp_Obj_0_intzsnzax* dest_0);
extern void eQdestroyQ_SX48otX4doduleX4fbj0intzsnzax_0_intzsnzax(HotModule_Obj_0_intzsnzax* dest_0);
extern void eQdestroyQ_SX54raceX4fbj0trakthy001_0_trakthy001(Trace_Obj_0_trakthy001* dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_natd5co251(void);
extern void X60Qini_0_trakthy001(void);
extern void X60Qini_0_intzsnzax(void);
extern void X60Qini_0_web91l7of(void);
extern void X60Qini_0_jsfc0lwq21(void);
extern void nimFlushStdStreams(void);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern NI32 _boolToJs(NB8 b_1);
extern NI32 _jsNewArray(void);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NI32 _numToJs(NI32 x_0);
extern void _jsArrPush(NI32 h_8, NI32 v_0);
extern NI32 _numToJs(NF64 x_1);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern NI32 _jsToNum(NI32 h_4);
extern NF64 _jsToNum(NI32 h_5);
extern NB8 _jsToBool(NI32 h_6);
extern NI32 _jsNewObject(void);
static inline NI32 memSizeInBytes_0_Itmy7ww1_croph25r5(NI32 size_15);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern NI32 _fnToJs0(X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21 p_1);
extern NI32 _fnToJs1(X60Qt_0_ISX4asX56alue0jsfc0lwq21SEAnimcallZAfalseZAR34_jsfc0lwq21 p_2);
LongString_0_sysvq0asl const strlit_0_I16664880105326712979_webs5r6ui1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "globalThis"}
;
LongString_0_sysvq0asl const strlit_0_I14368754465758110339_webs5r6ui1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_out"}
;
LongString_0_sysvq0asl const strlit_0_I5134639445603132408_webs5r6ui1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_stderr"}
;
LongString_0_sysvq0asl const strlit_0_I1787529681825097394_webs5r6ui1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_ok"}
;
LongString_0_sysvq0asl const strlit_0_I6856008627648404401_webs5r6ui1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_err"}
;
LongString_0_sysvq0asl const strlit_0_I14330892142168120120_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_host"}
;
LongString_0_sysvq0asl const strlit_0_I7783416736724960873_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_null"}
;
LongString_0_sysvq0asl const strlit_0_I12387915600341333245_webs5r6ui1 = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unsupported value passed to host API \'"}
;
LongString_0_sysvq0asl const strlit_0_I6673594784355463836_webs5r6ui1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "undefined"}
;
LongString_0_sysvq0asl const strlit_0_I5855350227254373858_webs5r6ui1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "host API \'"}
;
LongString_0_sysvq0asl const strlit_0_I16523460683690378575_webs5r6ui1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' failed"}
;
LongString_0_sysvq0asl const strlit_0_I4105200327509957739_webs5r6ui1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_gen"}
;
LongString_0_sysvq0asl const strlit_0_I14182430854109474760_webs5r6ui1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_newglobals"}
;
LongString_0_sysvq0asl const strlit_0_I13473439033966344835_webs5r6ui1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_bases"}
;
LongString_0_sysvq0asl const strlit_0_I9432706845178526121_webs5r6ui1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_drift"}
;
LongString_0_sysvq0asl const strlit_0_I14006682085828796090_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_mods"}
;
LongString_0_sysvq0asl const strlit_0_I2892469019530033308_webs5r6ui1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_src"}
;
LongString_0_sysvq0asl const strlit_0_I3140825920218649134_webs5r6ui1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_in"}
;
LongString_0_sysvq0asl const strlit_0_I16982784616617010069_webs5r6ui1 = {
  .fullLen_0 = 34, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "the program raised while loading: "}
;
LongString_0_sysvq0asl const strlit_0_I6699796638540018275_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_live"}
;
LongString_0_sysvq0asl const strlit_0_I2880903839811411786_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_bool"}
;
LongString_0_sysvq0asl const strlit_0_I9944353754377813301_webs5r6ui1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_ret"}
;
LongString_0_sysvq0asl const strlit_0_I658753421934677541_webs5r6ui1 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "no session is running"}
;
LongString_0_sysvq0asl const strlit_0_I12209841552747336970_webs5r6ui1 = {
  .fullLen_0 = 63, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "inside a call \342\200\224 the swap will land at the next frame boundary"}
;
LongString_0_sysvq0asl const strlit_0_I11523583819895159517_webs5r6ui1 = {
  .fullLen_0 = 50, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "the swap was refused: the program is inside a call"}
;
LongString_0_sysvq0asl const strlit_0_I2508100949235602327_webs5r6ui1 = {
  .fullLen_0 = 50, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "inside a call \342\200\224 retry at the next frame boundary"}
;
LongString_0_sysvq0asl const strlit_0_I16618460296835865401_webs5r6ui1 = {
  .fullLen_0 = 52, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "the append was refused: the program is inside a call"}
;
LongString_0_sysvq0asl const strlit_0_I4815655542236682105_webs5r6ui1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_ranto"}
;
LongString_0_sysvq0asl const strlit_0_I8065116423232770122_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_boot"}
;
LongString_0_sysvq0asl const strlit_0_I6015155935723769989_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_load"}
;
LongString_0_sysvq0asl const strlit_0_I17800444574936960851_webs5r6ui1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_has"}
;
LongString_0_sysvq0asl const strlit_0_I8453464220281351022_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_call"}
;
LongString_0_sysvq0asl const strlit_0_I7914060555962730862_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_swap"}
;
LongString_0_sysvq0asl const strlit_0_I4731531427299153800_webs5r6ui1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_append"}
;
LongString_0_sysvq0asl const strlit_0_I3856498981043743497_webs5r6ui1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_stop"}
;
LongString_0_sysvq0asl const strlit_0_I14037528535367499582_webs5r6ui1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__sess_ready"}
;
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_0_webs5r6ui1 = NIM_NIL;
X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* machine_0_webs5r6ui1 = NIM_NIL;
X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax* hot_0_webs5r6ui1;
NB8 live_0_webs5r6ui1 = NIM_FALSE;
NB8 hostFailed_0_webs5r6ui1 = NIM_FALSE;
NI32 ranTo_0_webs5r6ui1 = 0;
string_0_sysvq0asl lastErr_0_webs5r6ui1 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
NB8 X60QiniGuard_0_webs5r6ui1;
NI32 cmdCount;
NC8** cmdLine;
NC8** nimEnviron;
void park_0_webs5r6ui1(string_0_sysvq0asl name_0, JsValue_0_jsfc0lwq21 v_0){
  JsValue_0_jsfc0lwq21 g_0 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1869375486u, .more_0 = (&strlit_0_I16664880105326712979_webs5r6ui1)}
  );
  set_0_jsfc0lwq21(g_0, name_0, v_0);
  eQdestroy_0_jsfc0lwq21(g_0);}
string_0_sysvq0asl jsText_0_webs5r6ui1(JsValue_0_jsfc0lwq21 v_1){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  nimStrDestroy(result_0);
  result_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl s_0 = toStr_0_jsfc0lwq21(v_1);
  {
    NI32 X60Qlf_0 = 0;
    NI32 X60Qlf_1 = len_4_sysvq0asl(s_0);
    NI32 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 < X60Qlf_1){
        {
          NC8 X60Qx_3 = getQ_9_sysvq0asl(s_0, X60Qlf_2);
          add_1_sysvq0asl((&result_0), X60Qx_3);}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  nimStrDestroy(s_0);
  return result_0;
  nimStrDestroy(s_0);
  return result_0;}
NB8 sameText_0_webs5r6ui1(string_0_sysvq0asl a_0, string_0_sysvq0asl b_0){
  NB8 result_1;
  NI32 X60Qx_4 = len_4_sysvq0asl(a_0);
  NI32 X60Qx_5 = len_4_sysvq0asl(b_0);
  if ((!(X60Qx_4 == X60Qx_5))){
    return NIM_FALSE;}
  {
    NI32 X60Qlf_3 = 0;
    NI32 X60Qlf_4 = len_4_sysvq0asl(a_0);
    NI32 X60Qlf_5 = X60Qlf_3;
    {
      while (X60Qlf_5 < X60Qlf_4){
        {
          NC8 X60Qx_6 = getQ_9_sysvq0asl(a_0, X60Qlf_5);
          NC8 X60Qx_7 = getQ_9_sysvq0asl(b_0, X60Qlf_5);
          if ((!(X60Qx_6 == X60Qx_7))){
            return NIM_FALSE;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  result_1 = NIM_TRUE;
  return result_1;}
void drain_0_webs5r6ui1(void){
  if (sink_0_webs5r6ui1 == NIM_NIL){
    JsValue_0_jsfc0lwq21 X60Qtmp_0 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    park_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I14368754465758110339_webs5r6ui1)}
    , X60Qtmp_0);
    JsValue_0_jsfc0lwq21 X60Qtmp_1 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    park_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I5134639445603132408_webs5r6ui1)}
    , X60Qtmp_1);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_1);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_0);
    return;
    eQdestroy_0_jsfc0lwq21(X60Qtmp_1);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_0);}
  JsValue_0_jsfc0lwq21 X60Qtmp_2 = toJs_3_jsfc0lwq21((*sink_0_webs5r6ui1).d_00.outBuf_0);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I14368754465758110339_webs5r6ui1)}
  , X60Qtmp_2);
  string_0_sysvq0asl* X60Qlhs_3 = (&(*sink_0_webs5r6ui1).d_00.outBuf_0);
  string_0_sysvq0asl X60Qlhs_4 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  nimStrDestroy((*X60Qlhs_3));
  (*X60Qlhs_3) = X60Qlhs_4;
  nimStrDestroy(lastErr_0_webs5r6ui1);
  string_0_sysvq0asl X60Qx_8 = nimStrDup((*sink_0_webs5r6ui1).d_00.errBuf_0);
  lastErr_0_webs5r6ui1 = X60Qx_8;
  string_0_sysvq0asl* X60Qlhs_5 = (&(*sink_0_webs5r6ui1).d_00.errBuf_0);
  string_0_sysvq0asl X60Qlhs_6 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  nimStrDestroy((*X60Qlhs_5));
  (*X60Qlhs_5) = X60Qlhs_6;
  JsValue_0_jsfc0lwq21 X60Qtmp_7 = toJs_3_jsfc0lwq21(lastErr_0_webs5r6ui1);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I5134639445603132408_webs5r6ui1)}
  , X60Qtmp_7);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_7);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_2);}
void failWith_0_webs5r6ui1(string_0_sysvq0asl msg_0){
  JsValue_0_jsfc0lwq21 X60Qtmp_8 = toJs_2_jsfc0lwq21(NIM_FALSE);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I1787529681825097394_webs5r6ui1)}
  , X60Qtmp_8);
  JsValue_0_jsfc0lwq21 X60Qtmp_9 = toJs_3_jsfc0lwq21(msg_0);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I6856008627648404401_webs5r6ui1)}
  , X60Qtmp_9);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_9);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_8);}
void succeed_0_webs5r6ui1(void){
  JsValue_0_jsfc0lwq21 X60Qtmp_10 = toJs_2_jsfc0lwq21(NIM_TRUE);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I1787529681825097394_webs5r6ui1)}
  , X60Qtmp_10);
  JsValue_0_jsfc0lwq21 X60Qtmp_11 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I6856008627648404401_webs5r6ui1)}
  , X60Qtmp_11);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_11);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_10);}
NB8 raised_0_webs5r6ui1(void){
  NB8 result_2;
  if (machine_0_webs5r6ui1 == NIM_NIL){
    return NIM_FALSE;}
  NB8 X60Qx_9 = hotRaised_0_intzsnzax(machine_0_webs5r6ui1);
  if (X60Qx_9){
    hotClearRaise_0_intzsnzax(machine_0_webs5r6ui1);
    string_0_sysvq0asl msg_1 = nimStrDup(lastErr_0_webs5r6ui1);
    NB8 X60Qx_10;
    if ((!(sink_0_webs5r6ui1 == NIM_NIL))){
      NI32 X60Qx_11 = len_4_sysvq0asl((*sink_0_webs5r6ui1).d_00.errBuf_0);
      X60Qx_10 = (0 < X60Qx_11);}
    else {
      X60Qx_10 = NIM_FALSE;}
    if (X60Qx_10){
      string_0_sysvq0asl X60Qlhs_12 = ampQ_0_sysvq0asl(msg_1, (*sink_0_webs5r6ui1).d_00.errBuf_0);
      nimStrDestroy(msg_1);
      msg_1 = X60Qlhs_12;
      string_0_sysvq0asl* X60Qlhs_13 = (&(*sink_0_webs5r6ui1).d_00.errBuf_0);
      string_0_sysvq0asl X60Qlhs_14 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      nimStrDestroy((*X60Qlhs_13));
      (*X60Qlhs_13) = X60Qlhs_14;}
    failWith_0_webs5r6ui1(msg_1);
    nimStrDestroy(msg_1);
    return NIM_TRUE;
    nimStrDestroy(msg_1);}
  result_2 = NIM_FALSE;
  return result_2;}
N_NIMCALL(Value_0_valzr1t4f, jsHostCall_0_webs5r6ui1)(NI64 context_0, string_0_sysvq0asl name_1, seq_0_I50urnw_croph25r5 args_0, NB8* handled_0){
  Value_0_valzr1t4f result_3;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
  Value_0_valzr1t4f X60Qx_12 = vNil_0_valzr1t4f();
  result_3 = X60Qx_12;
  JsValue_0_jsfc0lwq21 hostFn_0 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I14330892142168120120_webs5r6ui1)}
  );
  NB8 X60Qx_13 = isNil_0_jsfc0lwq21(hostFn_0);
  if (X60Qx_13){
    eQdestroy_0_jsfc0lwq21(hostFn_0);
    return result_3;}
  JsValue_0_jsfc0lwq21 arr_0 = newJsArray_0_jsfc0lwq21();
  {
    NI32 X60Qlf_6 = 0;
    NI32 X60Qlf_7 = len_3_I4n9kvq_intzsnzax(args_0);
    NI32 X60Qlf_8 = X60Qlf_6;
    {
      while (X60Qlf_8 < X60Qlf_7){
        {
          Value_0_valzr1t4f* X60Qx_14 = getQ_7_Ine8yq71_intzsnzax(args_0, X60Qlf_8);
          Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_14);
          Value_0_valzr1t4f X60Qii_2 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
          switch (X60Qii_2.kind_0){
            case 1:
            case 2:
            case 5:
            case 7:
            {
              NI64 X60Qx_15 = asInt_0_valzr1t4f((&X60Qii_2));
              JsValue_0_jsfc0lwq21 X60Qtmp_15 = toJs_0_jsfc0lwq21(((NI32)X60Qx_15));
              add_0_jsfc0lwq21(arr_0, X60Qtmp_15);
              eQdestroy_0_jsfc0lwq21(X60Qtmp_15);}
            break;
            case 3:
            {
              JsValue_0_jsfc0lwq21 X60Qtmp_16 = toJs_1_jsfc0lwq21(X60Qii_2.fval_0);
              add_0_jsfc0lwq21(arr_0, X60Qtmp_16);
              eQdestroy_0_jsfc0lwq21(X60Qtmp_16);}
            break;
            case 4:
            {
              JsValue_0_jsfc0lwq21 X60Qtmp_17 = toJs_2_jsfc0lwq21(X60Qii_2.bval_0);
              add_0_jsfc0lwq21(arr_0, X60Qtmp_17);
              eQdestroy_0_jsfc0lwq21(X60Qtmp_17);}
            break;
            case 6:
            {
              JsValue_0_jsfc0lwq21 X60Qtmp_18 = toJs_3_jsfc0lwq21(X60Qii_2.sval_0);
              add_0_jsfc0lwq21(arr_0, X60Qtmp_18);
              eQdestroy_0_jsfc0lwq21(X60Qtmp_18);}
            break;
            case 0:
            {
              JsValue_0_jsfc0lwq21 X60Qtmp_19 = global_0_jsfc0lwq21((string_0_sysvq0asl){
                .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I7783416736724960873_webs5r6ui1)}
              );
              add_0_jsfc0lwq21(arr_0, X60Qtmp_19);
              eQdestroy_0_jsfc0lwq21(X60Qtmp_19);}
            break;
            default:
            {
              hostFailed_0_webs5r6ui1 = NIM_TRUE;
              NI32 X60Qx_16 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1936619006u, .more_0 = (&strlit_0_I12387915600341333245_webs5r6ui1)}
              );
              NI32 X60Qx_17 = len_4_sysvq0asl(name_1);
              NI32 X60Qx_18 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 9985u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_0 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_16 + X60Qx_17)) + X60Qx_18)));
              add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
                .bytes_0 = 1936619006u, .more_0 = (&strlit_0_I12387915600341333245_webs5r6ui1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_0), name_1);
              add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
                .bytes_0 = 9985u, .more_0 = NIM_NIL}
              );
              failWith_0_webs5r6ui1(X60Qdesugar_0);
              (*handled_0) = NIM_TRUE;
              nimStrDestroy(X60Qdesugar_0);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qii_2));
              eQdestroy_0_jsfc0lwq21(arr_0);
              eQdestroy_0_jsfc0lwq21(hostFn_0);
              return result_3;
              nimStrDestroy(X60Qdesugar_0);}
            break;}
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qii_2));}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_8));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  JsValue_0_jsfc0lwq21 X60Qtmp_20 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1869375486u, .more_0 = (&strlit_0_I16664880105326712979_webs5r6ui1)}
  );
  JsValue_0_jsfc0lwq21 X60Qtmp_21 = toJs_3_jsfc0lwq21(name_1);
  JsValue_0_jsfc0lwq21 ret_0 = call_2_jsfc0lwq21(X60Qtmp_20, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I14330892142168120120_webs5r6ui1)}
  , X60Qtmp_21, arr_0);
  NB8 X60Qx_2;
  NB8 X60Qx_19 = isNil_0_jsfc0lwq21(ret_0);
  if (X60Qx_19){
    X60Qx_2 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_22 = jsTypeof_0_jsfc0lwq21(ret_0);
    NB8 X60Qx_20 = sameText_0_webs5r6ui1(X60Qtmp_22, (string_0_sysvq0asl){
      .bytes_0 = 1684960766u, .more_0 = (&strlit_0_I6673594784355463836_webs5r6ui1)}
    );
    X60Qx_2 = X60Qx_20;
    nimStrDestroy(X60Qtmp_22);}
  if (X60Qx_2){
    eQdestroy_0_jsfc0lwq21(ret_0);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_21);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_20);
    eQdestroy_0_jsfc0lwq21(arr_0);
    eQdestroy_0_jsfc0lwq21(hostFn_0);
    return result_3;}
  (*handled_0) = NIM_TRUE;
  JsValue_0_jsfc0lwq21 X60Qtmp_23 = get_0_jsfc0lwq21(ret_0, (string_0_sysvq0asl){
    .bytes_0 = 27393u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl kind_0 = jsText_0_webs5r6ui1(X60Qtmp_23);
  NB8 X60Qx_21 = eqQ_20_sysvq0asl(kind_0, (string_0_sysvq0asl){
    .bytes_0 = 26881u, .more_0 = NIM_NIL}
  );
  if (X60Qx_21){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
    JsValue_0_jsfc0lwq21 X60Qtmp_24 = get_0_jsfc0lwq21(ret_0, (string_0_sysvq0asl){
      .bytes_0 = 30209u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_22 = toInt_0_jsfc0lwq21(X60Qtmp_24);
    Value_0_valzr1t4f X60Qx_23 = vInt_0_valzr1t4f(((NI64)X60Qx_22), 64);
    result_3 = X60Qx_23;
    eQdestroy_0_jsfc0lwq21(X60Qtmp_24);}
  else {
    NB8 X60Qx_24 = eqQ_20_sysvq0asl(kind_0, (string_0_sysvq0asl){
      .bytes_0 = 26113u, .more_0 = NIM_NIL}
    );
    if (X60Qx_24){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
      JsValue_0_jsfc0lwq21 X60Qtmp_25 = get_0_jsfc0lwq21(ret_0, (string_0_sysvq0asl){
        .bytes_0 = 30209u, .more_0 = NIM_NIL}
      );
      NF64 X60Qx_25 = toFloat_0_jsfc0lwq21(X60Qtmp_25);
      Value_0_valzr1t4f X60Qx_26 = vFloat_0_valzr1t4f(X60Qx_25, 64);
      result_3 = X60Qx_26;
      eQdestroy_0_jsfc0lwq21(X60Qtmp_25);}
    else {
      NB8 X60Qx_27 = eqQ_20_sysvq0asl(kind_0, (string_0_sysvq0asl){
        .bytes_0 = 25089u, .more_0 = NIM_NIL}
      );
      if (X60Qx_27){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
        JsValue_0_jsfc0lwq21 X60Qtmp_26 = get_0_jsfc0lwq21(ret_0, (string_0_sysvq0asl){
          .bytes_0 = 30209u, .more_0 = NIM_NIL}
        );
        NB8 X60Qx_28 = toBool_0_jsfc0lwq21(X60Qtmp_26);
        Value_0_valzr1t4f X60Qx_29 = vBool_0_valzr1t4f(X60Qx_28);
        result_3 = X60Qx_29;
        eQdestroy_0_jsfc0lwq21(X60Qtmp_26);}
      else {
        NB8 X60Qx_30 = eqQ_20_sysvq0asl(kind_0, (string_0_sysvq0asl){
          .bytes_0 = 29441u, .more_0 = NIM_NIL}
        );
        if (X60Qx_30){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
          JsValue_0_jsfc0lwq21 X60Qtmp_28 = get_0_jsfc0lwq21(ret_0, (string_0_sysvq0asl){
            .bytes_0 = 30209u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qtmp_27 = jsText_0_webs5r6ui1(X60Qtmp_28);
          Value_0_valzr1t4f X60Qx_31 = vStr_0_valzr1t4f(X60Qtmp_27);
          result_3 = X60Qx_31;
          nimStrDestroy(X60Qtmp_27);
          eQdestroy_0_jsfc0lwq21(X60Qtmp_28);}
        else {
          NB8 X60Qx_32 = eqQ_20_sysvq0asl(kind_0, (string_0_sysvq0asl){
            .bytes_0 = 30721u, .more_0 = NIM_NIL}
          );
          if (X60Qx_32){
            hostFailed_0_webs5r6ui1 = NIM_TRUE;
            NI32 X60Qx_33 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1936681214u, .more_0 = (&strlit_0_I5855350227254373858_webs5r6ui1)}
            );
            NI32 X60Qx_34 = len_4_sysvq0asl(name_1);
            NI32 X60Qx_35 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1713383422u, .more_0 = (&strlit_0_I16523460683690378575_webs5r6ui1)}
            );
            string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_33 + X60Qx_34)) + X60Qx_35)));
            add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
              .bytes_0 = 1936681214u, .more_0 = (&strlit_0_I5855350227254373858_webs5r6ui1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_1), name_1);
            add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
              .bytes_0 = 1713383422u, .more_0 = (&strlit_0_I16523460683690378575_webs5r6ui1)}
            );
            failWith_0_webs5r6ui1(X60Qdesugar_1);
            nimStrDestroy(X60Qdesugar_1);}
          else {
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_3));
            Value_0_valzr1t4f X60Qx_36 = vNil_0_valzr1t4f();
            result_3 = X60Qx_36;}}}}}
  nimStrDestroy(kind_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_23);
  eQdestroy_0_jsfc0lwq21(ret_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_21);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_20);
  eQdestroy_0_jsfc0lwq21(arr_0);
  eQdestroy_0_jsfc0lwq21(hostFn_0);
  return result_3;
  nimStrDestroy(kind_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_23);
  eQdestroy_0_jsfc0lwq21(ret_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_21);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_20);
  eQdestroy_0_jsfc0lwq21(arr_0);
  eQdestroy_0_jsfc0lwq21(hostFn_0);
  return result_3;}
string_0_sysvq0asl modulePath_0_webs5r6ui1(void){
  string_0_sysvq0asl result_4;
  nimStrWasMoved((&result_4));
  NI32 X60Qx_37 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 7810818u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_38 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_39 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1650817022u, .more_0 = (&strlit_0_I16952481534133288743_web91l7of)}
  );
  NI32 X60Qx_40 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
  );
  string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_37 + X60Qx_38)) + X60Qx_39)) + X60Qx_40)));
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 7810818u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 1650817022u, .more_0 = (&strlit_0_I16952481534133288743_web91l7of)}
  );
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
  );
  nimStrDestroy(result_4);
  result_4 = X60Qdesugar_2;
  nimStrWasMoved((&X60Qdesugar_2));
  nimStrDestroy(X60Qdesugar_2);
  return result_4;
  nimStrDestroy(X60Qdesugar_2);
  return result_4;}
void republish_0_webs5r6ui1(string_0_sysvq0asl src_0){
  string_0_sysvq0asl X60Qtmp_29 = modulePath_0_webs5r6ui1();
  webPut_0_web91l7of(X60Qtmp_29, src_0);
  nimStrDestroy(X60Qtmp_29);}
void parkModuleFacts_0_webs5r6ui1(void){
  JsValue_0_jsfc0lwq21 X60Qtmp_30 = toJs_0_jsfc0lwq21((*hot_0_webs5r6ui1).d_00.generation_0);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I4105200327509957739_webs5r6ui1)}
  , X60Qtmp_30);
  JsValue_0_jsfc0lwq21 X60Qtmp_31 = toJs_0_jsfc0lwq21((*hot_0_webs5r6ui1).d_00.newGlobals_0);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I14182430854109474760_webs5r6ui1)}
  , X60Qtmp_31);
  string_0_sysvq0asl names_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    NI32 X60Qlf_9 = 0;
    NI32 X60Qlf_10 = len_3_Ixq6taz_aow7lb5cq1((*hot_0_webs5r6ui1).d_00.bases_0);
    NI32 X60Qlf_11 = X60Qlf_9;
    {
      while (X60Qlf_11 < X60Qlf_10){
        {
          if (0 < X60Qlf_11){
            add_2_sysvq0asl((&names_0), (string_0_sysvq0asl){
              .bytes_0 = 11265u, .more_0 = NIM_NIL}
            );}
          string_0_sysvq0asl* X60Qx_41 = getQ_7_Ir6d0tw_aow7lb5cq1((*hot_0_webs5r6ui1).d_00.bases_0, X60Qlf_11);
          add_2_sysvq0asl((&names_0), (*X60Qx_41));}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_11));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  JsValue_0_jsfc0lwq21 X60Qtmp_32 = toJs_3_jsfc0lwq21(names_0);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I13473439033966344835_webs5r6ui1)}
  , X60Qtmp_32);
  string_0_sysvq0asl d_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    NI32 X60Qlf_12 = 0;
    NI32 X60Qlf_13 = len_3_Ixq6taz_aow7lb5cq1((*hot_0_webs5r6ui1).d_00.drift_0);
    NI32 X60Qlf_14 = X60Qlf_12;
    {
      while (X60Qlf_14 < X60Qlf_13){
        {
          if (0 < X60Qlf_14){
            add_2_sysvq0asl((&d_0), (string_0_sysvq0asl){
              .bytes_0 = 2561u, .more_0 = NIM_NIL}
            );}
          string_0_sysvq0asl* X60Qx_42 = getQ_7_Ir6d0tw_aow7lb5cq1((*hot_0_webs5r6ui1).d_00.drift_0, X60Qlf_14);
          add_2_sysvq0asl((&d_0), (*X60Qx_42));}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_14));}}
    whileStmtLabel_3: ;}
  forStmtLabel_2: ;
  JsValue_0_jsfc0lwq21 X60Qtmp_33 = toJs_3_jsfc0lwq21(d_0);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I9432706845178526121_webs5r6ui1)}
  , X60Qtmp_33);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_33);
  nimStrDestroy(d_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_32);
  nimStrDestroy(names_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_31);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_30);}
void startSession_0_webs5r6ui1(NB8 runInit_0){
  installWebVfs_0_web91l7of();
  JsValue_0_jsfc0lwq21 X60Qtmp_35 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I14006682085828796090_webs5r6ui1)}
  );
  string_0_sysvq0asl X60Qtmp_34 = toStr_0_jsfc0lwq21(X60Qtmp_35);
  loadWebModules_0_web91l7of(X60Qtmp_34);
  JsValue_0_jsfc0lwq21 X60Qtmp_36 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I2892469019530033308_webs5r6ui1)}
  );
  string_0_sysvq0asl src_1 = toStr_0_jsfc0lwq21(X60Qtmp_36);
  publishMainModule_0_web91l7of(src_1);
  republish_0_webs5r6ui1(src_1);
  setupProgramForTesting_0_prorcx25w1((string_0_sysvq0asl){
    .bytes_0 = 7810818u, .more_0 = NIM_NIL}
  , (string_0_sysvq0asl){
    .bytes_0 = 1650817022u, .more_0 = (&strlit_0_I16952481534133288743_web91l7of)}
  , (string_0_sysvq0asl){
    .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
  );
  eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_webs5r6ui1(sink_0_webs5r6ui1);
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* X60Qx_43 = newOutSink_0_natd5co251();
  sink_0_webs5r6ui1 = X60Qx_43;
  (*sink_0_webs5r6ui1).d_00.hostContext_0 = ((NI64)0);
  (*sink_0_webs5r6ui1).d_00.hostCall_0 = jsHostCall_0_webs5r6ui1;
  string_0_sysvq0asl* X60Qlhs_37 = (&(*sink_0_webs5r6ui1).d_00.inBuf_0);
  JsValue_0_jsfc0lwq21 X60Qtmp_39 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I3140825920218649134_webs5r6ui1)}
  );
  string_0_sysvq0asl X60Qlhs_38 = toStr_0_jsfc0lwq21(X60Qtmp_39);
  nimStrDestroy((*X60Qlhs_37));
  (*X60Qlhs_37) = X60Qlhs_38;
  (*sink_0_webs5r6ui1).d_00.inPos_0 = 0;
  (*sink_0_webs5r6ui1).d_00.inLoaded_0 = NIM_TRUE;
  eQdestroyQ_ArefSX49nterpX4fbj0intzsnzax_0_webs5r6ui1(machine_0_webs5r6ui1);
  X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax* X60Qtmp_40 = newTrace_0_trakthy001(0);
  X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* X60Qx_44 = newInterp_0_intzsnzax(sink_0_webs5r6ui1, X60Qtmp_40);
  machine_0_webs5r6ui1 = X60Qx_44;
  enableAbortTrack_0_intzsnzax(machine_0_webs5r6ui1);
  hostFailed_0_webs5r6ui1 = NIM_FALSE;
  live_0_webs5r6ui1 = NIM_FALSE;
  ranTo_0_webs5r6ui1 = 0;
  nimStrDestroy(lastErr_0_webs5r6ui1);
  lastErr_0_webs5r6ui1 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  eQdestroyQ_ArefSX48otX4doduleX4fbj0intzsnzax_0_webs5r6ui1(hot_0_webs5r6ui1);
  string_0_sysvq0asl X60Qtmp_41 = modulePath_0_webs5r6ui1();
  X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax* X60Qx_45 = loadHot_0_intzsnzax(machine_0_webs5r6ui1, X60Qtmp_41, runInit_0);
  hot_0_webs5r6ui1 = X60Qx_45;
  drain_0_webs5r6ui1();
  if (hostFailed_0_webs5r6ui1){
    nimStrDestroy(X60Qtmp_41);
    eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_webs5r6ui1(X60Qtmp_40);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_39);
    nimStrDestroy(src_1);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_36);
    nimStrDestroy(X60Qtmp_34);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_35);
    return;}
  NB8 X60Qx_46 = hotRaised_0_intzsnzax(machine_0_webs5r6ui1);
  if (X60Qx_46){
    hotClearRaise_0_intzsnzax(machine_0_webs5r6ui1);
    string_0_sysvq0asl msg_2 = nimStrDup(lastErr_0_webs5r6ui1);
    NB8 X60Qx_47;
    if ((!(sink_0_webs5r6ui1 == NIM_NIL))){
      NI32 X60Qx_48 = len_4_sysvq0asl((*sink_0_webs5r6ui1).d_00.errBuf_0);
      X60Qx_47 = (0 < X60Qx_48);}
    else {
      X60Qx_47 = NIM_FALSE;}
    if (X60Qx_47){
      string_0_sysvq0asl X60Qlhs_42 = ampQ_0_sysvq0asl(msg_2, (*sink_0_webs5r6ui1).d_00.errBuf_0);
      nimStrDestroy(msg_2);
      msg_2 = X60Qlhs_42;
      string_0_sysvq0asl* X60Qlhs_43 = (&(*sink_0_webs5r6ui1).d_00.errBuf_0);
      string_0_sysvq0asl X60Qlhs_44 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      nimStrDestroy((*X60Qlhs_43));
      (*X60Qlhs_43) = X60Qlhs_44;}
    string_0_sysvq0asl X60Qtmp_45 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I16982784616617010069_webs5r6ui1)}
    , msg_2);
    failWith_0_webs5r6ui1(X60Qtmp_45);
    JsValue_0_jsfc0lwq21 X60Qtmp_46 = toJs_2_jsfc0lwq21(NIM_FALSE);
    park_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I6699796638540018275_webs5r6ui1)}
    , X60Qtmp_46);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_46);
    nimStrDestroy(X60Qtmp_45);
    nimStrDestroy(msg_2);
    nimStrDestroy(X60Qtmp_41);
    eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_webs5r6ui1(X60Qtmp_40);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_39);
    nimStrDestroy(src_1);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_36);
    nimStrDestroy(X60Qtmp_34);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_35);
    return;
    eQdestroy_0_jsfc0lwq21(X60Qtmp_46);
    nimStrDestroy(X60Qtmp_45);
    nimStrDestroy(msg_2);}
  live_0_webs5r6ui1 = NIM_TRUE;
  JsValue_0_jsfc0lwq21 X60Qtmp_47 = toJs_2_jsfc0lwq21(NIM_TRUE);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I6699796638540018275_webs5r6ui1)}
  , X60Qtmp_47);
  parkModuleFacts_0_webs5r6ui1();
  succeed_0_webs5r6ui1();
  eQdestroy_0_jsfc0lwq21(X60Qtmp_47);
  nimStrDestroy(X60Qtmp_41);
  eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_webs5r6ui1(X60Qtmp_40);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_39);
  nimStrDestroy(src_1);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_36);
  nimStrDestroy(X60Qtmp_34);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_35);}
N_NIMCALL(void, bootImpl_0_webs5r6ui1)(void){
  startSession_0_webs5r6ui1(NIM_TRUE);}
N_NIMCALL(void, loadImpl_0_webs5r6ui1)(void){
  startSession_0_webs5r6ui1(NIM_FALSE);}
N_NIMCALL(void, hasImpl_0_webs5r6ui1)(JsValue_0_jsfc0lwq21 name_2){
  if ((!live_0_webs5r6ui1)){
    JsValue_0_jsfc0lwq21 X60Qtmp_48 = toJs_2_jsfc0lwq21(NIM_FALSE);
    park_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I2880903839811411786_webs5r6ui1)}
    , X60Qtmp_48);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_48);}
  else {
    string_0_sysvq0asl X60Qtmp_50 = jsText_0_webs5r6ui1(name_2);
    NB8 X60Qx_49 = hasHot_0_intzsnzax(hot_0_webs5r6ui1, X60Qtmp_50);
    JsValue_0_jsfc0lwq21 X60Qtmp_49 = toJs_2_jsfc0lwq21(X60Qx_49);
    park_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I2880903839811411786_webs5r6ui1)}
    , X60Qtmp_49);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_49);
    nimStrDestroy(X60Qtmp_50);}}
void parkReturn_0_webs5r6ui1(Value_0_valzr1t4f* v_2){
  JsValue_0_jsfc0lwq21 obj_0 = newJsObject_0_jsfc0lwq21();
  switch ((*v_2).kind_0){
    case 1:
    case 2:
    case 5:
    case 7:
    {
      JsValue_0_jsfc0lwq21 X60Qtmp_51 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
        .bytes_0 = 26881u, .more_0 = NIM_NIL}
      );
      set_0_jsfc0lwq21(obj_0, (string_0_sysvq0asl){
        .bytes_0 = 27393u, .more_0 = NIM_NIL}
      , X60Qtmp_51);
      NI64 X60Qx_50 = asInt_0_valzr1t4f((&(*v_2)));
      JsValue_0_jsfc0lwq21 X60Qtmp_52 = toJs_0_jsfc0lwq21(((NI32)X60Qx_50));
      set_0_jsfc0lwq21(obj_0, (string_0_sysvq0asl){
        .bytes_0 = 30209u, .more_0 = NIM_NIL}
      , X60Qtmp_52);
      eQdestroy_0_jsfc0lwq21(X60Qtmp_52);
      eQdestroy_0_jsfc0lwq21(X60Qtmp_51);}
    break;
    case 3:
    {
      JsValue_0_jsfc0lwq21 X60Qtmp_53 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
        .bytes_0 = 26113u, .more_0 = NIM_NIL}
      );
      set_0_jsfc0lwq21(obj_0, (string_0_sysvq0asl){
        .bytes_0 = 27393u, .more_0 = NIM_NIL}
      , X60Qtmp_53);
      JsValue_0_jsfc0lwq21 X60Qtmp_54 = toJs_1_jsfc0lwq21((*v_2).fval_0);
      set_0_jsfc0lwq21(obj_0, (string_0_sysvq0asl){
        .bytes_0 = 30209u, .more_0 = NIM_NIL}
      , X60Qtmp_54);
      eQdestroy_0_jsfc0lwq21(X60Qtmp_54);
      eQdestroy_0_jsfc0lwq21(X60Qtmp_53);}
    break;
    case 4:
    {
      JsValue_0_jsfc0lwq21 X60Qtmp_55 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
        .bytes_0 = 25089u, .more_0 = NIM_NIL}
      );
      set_0_jsfc0lwq21(obj_0, (string_0_sysvq0asl){
        .bytes_0 = 27393u, .more_0 = NIM_NIL}
      , X60Qtmp_55);
      JsValue_0_jsfc0lwq21 X60Qtmp_56 = toJs_2_jsfc0lwq21((*v_2).bval_0);
      set_0_jsfc0lwq21(obj_0, (string_0_sysvq0asl){
        .bytes_0 = 30209u, .more_0 = NIM_NIL}
      , X60Qtmp_56);
      eQdestroy_0_jsfc0lwq21(X60Qtmp_56);
      eQdestroy_0_jsfc0lwq21(X60Qtmp_55);}
    break;
    case 6:
    {
      JsValue_0_jsfc0lwq21 X60Qtmp_57 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
        .bytes_0 = 29441u, .more_0 = NIM_NIL}
      );
      set_0_jsfc0lwq21(obj_0, (string_0_sysvq0asl){
        .bytes_0 = 27393u, .more_0 = NIM_NIL}
      , X60Qtmp_57);
      JsValue_0_jsfc0lwq21 X60Qtmp_58 = toJs_3_jsfc0lwq21((*v_2).sval_0);
      set_0_jsfc0lwq21(obj_0, (string_0_sysvq0asl){
        .bytes_0 = 30209u, .more_0 = NIM_NIL}
      , X60Qtmp_58);
      eQdestroy_0_jsfc0lwq21(X60Qtmp_58);
      eQdestroy_0_jsfc0lwq21(X60Qtmp_57);}
    break;
    default:
    {
      JsValue_0_jsfc0lwq21 X60Qtmp_59 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
        .bytes_0 = 28161u, .more_0 = NIM_NIL}
      );
      set_0_jsfc0lwq21(obj_0, (string_0_sysvq0asl){
        .bytes_0 = 27393u, .more_0 = NIM_NIL}
      , X60Qtmp_59);
      eQdestroy_0_jsfc0lwq21(X60Qtmp_59);}
    break;}
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I9944353754377813301_webs5r6ui1)}
  , obj_0);
  eQdestroy_0_jsfc0lwq21(obj_0);}
void clearReturn_0_webs5r6ui1(void){
  JsValue_0_jsfc0lwq21 obj_1 = newJsObject_0_jsfc0lwq21();
  JsValue_0_jsfc0lwq21 X60Qtmp_60 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 28161u, .more_0 = NIM_NIL}
  );
  set_0_jsfc0lwq21(obj_1, (string_0_sysvq0asl){
    .bytes_0 = 27393u, .more_0 = NIM_NIL}
  , X60Qtmp_60);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I9944353754377813301_webs5r6ui1)}
  , obj_1);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_60);
  eQdestroy_0_jsfc0lwq21(obj_1);}
N_NIMCALL(void, callImpl_0_webs5r6ui1)(JsValue_0_jsfc0lwq21 name_3){
  clearReturn_0_webs5r6ui1();
  if ((!live_0_webs5r6ui1)){
    failWith_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 544173822u, .more_0 = (&strlit_0_I658753421934677541_webs5r6ui1)}
    );
    return;}
  succeed_0_webs5r6ui1();
  hostFailed_0_webs5r6ui1 = NIM_FALSE;
  seq_0_I50urnw_croph25r5 args_1 = newSeqUninit_0_I8oufjc_croph25r5(0);
  string_0_sysvq0asl X60Qtmp_61 = jsText_0_webs5r6ui1(name_3);
  Value_0_valzr1t4f v_3 = callHot_0_intzsnzax(machine_0_webs5r6ui1, hot_0_webs5r6ui1, X60Qtmp_61, args_1);
  drain_0_webs5r6ui1();
  if (hostFailed_0_webs5r6ui1){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
    nimStrDestroy(X60Qtmp_61);
    eQdestroy_1_Inxd7ue1_croph25r5(args_1);
    return;}
  NB8 X60Qx_51 = raised_0_webs5r6ui1();
  if (X60Qx_51){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
    nimStrDestroy(X60Qtmp_61);
    eQdestroy_1_Inxd7ue1_croph25r5(args_1);
    return;}
  parkReturn_0_webs5r6ui1((&v_3));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
  nimStrDestroy(X60Qtmp_61);
  eQdestroy_1_Inxd7ue1_croph25r5(args_1);}
N_NIMCALL(void, swapImpl_0_webs5r6ui1)(void){
  if ((!live_0_webs5r6ui1)){
    failWith_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 544173822u, .more_0 = (&strlit_0_I658753421934677541_webs5r6ui1)}
    );
    return;}
  NB8 X60Qx_52 = hotSafe_0_intzsnzax(machine_0_webs5r6ui1);
  if ((!X60Qx_52)){
    failWith_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I12209841552747336970_webs5r6ui1)}
    );
    return;}
  JsValue_0_jsfc0lwq21 X60Qtmp_63 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I2892469019530033308_webs5r6ui1)}
  );
  string_0_sysvq0asl X60Qtmp_62 = toStr_0_jsfc0lwq21(X60Qtmp_63);
  republish_0_webs5r6ui1(X60Qtmp_62);
  hostFailed_0_webs5r6ui1 = NIM_FALSE;
  NB8 X60Qx_53 = swapHot_0_intzsnzax(machine_0_webs5r6ui1, hot_0_webs5r6ui1, NIM_FALSE);
  if ((!X60Qx_53)){
    failWith_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I11523583819895159517_webs5r6ui1)}
    );
    nimStrDestroy(X60Qtmp_62);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_63);
    return;}
  drain_0_webs5r6ui1();
  if (hostFailed_0_webs5r6ui1){
    nimStrDestroy(X60Qtmp_62);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_63);
    return;}
  NB8 X60Qx_54 = raised_0_webs5r6ui1();
  if (X60Qx_54){
    nimStrDestroy(X60Qtmp_62);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_63);
    return;}
  parkModuleFacts_0_webs5r6ui1();
  succeed_0_webs5r6ui1();
  nimStrDestroy(X60Qtmp_62);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_63);}
N_NIMCALL(void, appendImpl_0_webs5r6ui1)(JsValue_0_jsfc0lwq21 fromStmt_0){
  if ((!live_0_webs5r6ui1)){
    failWith_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 544173822u, .more_0 = (&strlit_0_I658753421934677541_webs5r6ui1)}
    );
    return;}
  NB8 X60Qx_55 = hotSafe_0_intzsnzax(machine_0_webs5r6ui1);
  if ((!X60Qx_55)){
    failWith_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I2508100949235602327_webs5r6ui1)}
    );
    return;}
  JsValue_0_jsfc0lwq21 X60Qtmp_65 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I2892469019530033308_webs5r6ui1)}
  );
  string_0_sysvq0asl X60Qtmp_64 = toStr_0_jsfc0lwq21(X60Qtmp_65);
  republish_0_webs5r6ui1(X60Qtmp_64);
  hostFailed_0_webs5r6ui1 = NIM_FALSE;
  NI32 upto_0 = ranTo_0_webs5r6ui1;
  NI32 X60Qx_56 = toInt_0_jsfc0lwq21(fromStmt_0);
  NI32 already_0 = ((NI32)X60Qx_56);
  if (0 <= already_0){
    upto_0 = already_0;}
  NI32 newTotal_0 = upto_0;
  NB8 X60Qx_57 = swapHotAppend_0_intzsnzax(machine_0_webs5r6ui1, hot_0_webs5r6ui1, upto_0, (&newTotal_0));
  if ((!X60Qx_57)){
    failWith_0_webs5r6ui1((string_0_sysvq0asl){
      .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I16618460296835865401_webs5r6ui1)}
    );
    nimStrDestroy(X60Qtmp_64);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_65);
    return;}
  ranTo_0_webs5r6ui1 = newTotal_0;
  JsValue_0_jsfc0lwq21 X60Qtmp_66 = toJs_0_jsfc0lwq21(ranTo_0_webs5r6ui1);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I4815655542236682105_webs5r6ui1)}
  , X60Qtmp_66);
  drain_0_webs5r6ui1();
  if (hostFailed_0_webs5r6ui1){
    eQdestroy_0_jsfc0lwq21(X60Qtmp_66);
    nimStrDestroy(X60Qtmp_64);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_65);
    return;}
  NB8 X60Qx_58 = raised_0_webs5r6ui1();
  if (X60Qx_58){
    eQdestroy_0_jsfc0lwq21(X60Qtmp_66);
    nimStrDestroy(X60Qtmp_64);
    eQdestroy_0_jsfc0lwq21(X60Qtmp_65);
    return;}
  parkModuleFacts_0_webs5r6ui1();
  succeed_0_webs5r6ui1();
  eQdestroy_0_jsfc0lwq21(X60Qtmp_66);
  nimStrDestroy(X60Qtmp_64);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_65);}
N_NIMCALL(void, stopImpl_0_webs5r6ui1)(void){
  live_0_webs5r6ui1 = NIM_FALSE;
  eQdestroyQ_ArefSX49nterpX4fbj0intzsnzax_0_webs5r6ui1(machine_0_webs5r6ui1);
  machine_0_webs5r6ui1 = NIM_NIL;
  eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_webs5r6ui1(sink_0_webs5r6ui1);
  sink_0_webs5r6ui1 = NIM_NIL;
  ranTo_0_webs5r6ui1 = 0;
  JsValue_0_jsfc0lwq21 X60Qtmp_67 = toJs_2_jsfc0lwq21(NIM_FALSE);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I6699796638540018275_webs5r6ui1)}
  , X60Qtmp_67);
  JsValue_0_jsfc0lwq21 X60Qtmp_68 = toJs_0_jsfc0lwq21(0);
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I4105200327509957739_webs5r6ui1)}
  , X60Qtmp_68);
  JsValue_0_jsfc0lwq21 X60Qtmp_69 = toJs_3_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  park_0_webs5r6ui1((string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I14368754465758110339_webs5r6ui1)}
  , X60Qtmp_69);
  succeed_0_webs5r6ui1();
  eQdestroy_0_jsfc0lwq21(X60Qtmp_69);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_68);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_67);}
void register_0_webs5r6ui1(void){
  JsValue_0_jsfc0lwq21 g_1 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1869375486u, .more_0 = (&strlit_0_I16664880105326712979_webs5r6ui1)}
  );
  X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21 b_2 = bootImpl_0_webs5r6ui1;
  X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21 l_0 = loadImpl_0_webs5r6ui1;
  X60Qt_0_ISX4asX56alue0jsfc0lwq21SEAnimcallZAfalseZAR34_jsfc0lwq21 h_0 = hasImpl_0_webs5r6ui1;
  X60Qt_0_ISX4asX56alue0jsfc0lwq21SEAnimcallZAfalseZAR34_jsfc0lwq21 c_0 = callImpl_0_webs5r6ui1;
  X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21 s_5 = swapImpl_0_webs5r6ui1;
  X60Qt_0_ISX4asX56alue0jsfc0lwq21SEAnimcallZAfalseZAR34_jsfc0lwq21 a_2 = appendImpl_0_webs5r6ui1;
  X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21 x_0 = stopImpl_0_webs5r6ui1;
  JsValue_0_jsfc0lwq21 X60Qtmp_70 = toJs_4_jsfc0lwq21(b_2);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I8065116423232770122_webs5r6ui1)}
  , X60Qtmp_70);
  JsValue_0_jsfc0lwq21 X60Qtmp_71 = toJs_4_jsfc0lwq21(l_0);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I6015155935723769989_webs5r6ui1)}
  , X60Qtmp_71);
  JsValue_0_jsfc0lwq21 X60Qtmp_72 = toJs_5_jsfc0lwq21(h_0);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I17800444574936960851_webs5r6ui1)}
  , X60Qtmp_72);
  JsValue_0_jsfc0lwq21 X60Qtmp_73 = toJs_5_jsfc0lwq21(c_0);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I8453464220281351022_webs5r6ui1)}
  , X60Qtmp_73);
  JsValue_0_jsfc0lwq21 X60Qtmp_74 = toJs_4_jsfc0lwq21(s_5);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I7914060555962730862_webs5r6ui1)}
  , X60Qtmp_74);
  JsValue_0_jsfc0lwq21 X60Qtmp_75 = toJs_5_jsfc0lwq21(a_2);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I4731531427299153800_webs5r6ui1)}
  , X60Qtmp_75);
  JsValue_0_jsfc0lwq21 X60Qtmp_76 = toJs_4_jsfc0lwq21(x_0);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I3856498981043743497_webs5r6ui1)}
  , X60Qtmp_76);
  JsValue_0_jsfc0lwq21 X60Qtmp_77 = toJs_2_jsfc0lwq21(NIM_FALSE);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I6699796638540018275_webs5r6ui1)}
  , X60Qtmp_77);
  JsValue_0_jsfc0lwq21 X60Qtmp_78 = toJs_0_jsfc0lwq21(0);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I4105200327509957739_webs5r6ui1)}
  , X60Qtmp_78);
  JsValue_0_jsfc0lwq21 X60Qtmp_79 = toJs_2_jsfc0lwq21(NIM_TRUE);
  set_0_jsfc0lwq21(g_1, (string_0_sysvq0asl){
    .bytes_0 = 1935630334u, .more_0 = (&strlit_0_I14037528535367499582_webs5r6ui1)}
  , X60Qtmp_79);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_79);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_78);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_77);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_76);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_75);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_74);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_73);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_72);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_71);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_70);
  eQdestroy_0_jsfc0lwq21(g_1);}
void eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_webs5r6ui1(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* dest_0){
  if (dest_0){
    NB8 X60Qx_79 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_79){
      eQdestroyQ_SX4futX53inkX4fbj0natd5co251_0_natd5co251((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX49nterpX4fbj0intzsnzax_0_webs5r6ui1(X60Qt_0_IArefSX49nterpX4fbj0intzsnzax_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_80 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_80){
      eQdestroyQ_SX49nterpX4fbj0intzsnzax_0_intzsnzax((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX48otX4doduleX4fbj0intzsnzax_0_webs5r6ui1(X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX48otX4doduleX4fbj0intzsnzax_0_webs5r6ui1(X60Qt_0_IArefSX48otX4doduleX4fbj0intzsnzax_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_81 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_81){
      eQdestroyQ_SX48otX4doduleX4fbj0intzsnzax_0_intzsnzax((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_webs5r6ui1(X60Qt_0_IArefSX54raceX4fbj0trakthy001_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_82 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_82){
      eQdestroyQ_SX54raceX4fbj0trakthy001_0_trakthy001((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void X60Qini_0_webs5r6ui1(void){
  if (X60QiniGuard_0_webs5r6ui1){
    return;}
  X60QiniGuard_0_webs5r6ui1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_prorcx25w1();
  X60Qini_0_valzr1t4f();
  X60Qini_0_natd5co251();
  X60Qini_0_trakthy001();
  X60Qini_0_intzsnzax();
  X60Qini_0_web91l7of();
  X60Qini_0_jsfc0lwq21();
  eQwasmovedQ_ArefSX48otX4doduleX4fbj0intzsnzax_0_webs5r6ui1((&hot_0_webs5r6ui1));
  register_0_webs5r6ui1();}
NI32 main(NI32 X60Qargc_0_webs5r6ui1, char** X60Qargv_0_webs5r6ui1, char** X60Qenvp_0_webs5r6ui1){
  cmdCount = X60Qargc_0_webs5r6ui1;
  cmdLine = ((NC8**)X60Qargv_0_webs5r6ui1);
  nimEnviron = ((NC8**)X60Qenvp_0_webs5r6ui1);
  X60Qini_0_webs5r6ui1();
  nimFlushStdStreams();
  return 0;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14){
  NB8 X60Qx_257;
  NI32 X60Qx_258 = len_4_sysvq0asl(s_54);
  if (i_14 < X60Qx_258){
    X60Qx_257 = (0 <= i_14);}
  else {
    X60Qx_257 = NIM_FALSE;}
  if ((!X60Qx_257)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5239124994330926419_sysvq0asl)}
    );}
  NC8 result_112;
  NC8 X60Qx_26;
  if (((NI32)6) < ((NI32)(*((NU8*)(&s_54.bytes_0))))){
    X60Qx_26 = (*s_54.more_0).data_0[i_14];}
  else {
    X60Qx_26 = ((NC8*)((NU32)(((NU32)(&s_54.bytes_0)) + 1u)))[i_14];}
  result_112 = X60Qx_26;
  return result_112;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline JsValue_0_jsfc0lwq21 toJs_2_jsfc0lwq21(NB8 b_5){
  JsValue_0_jsfc0lwq21 result_8;
  eQdestroy_0_jsfc0lwq21(result_8);
  NI32 X60Qx_8 = _boolToJs(b_5);
  result_8 = (JsValue_0_jsfc0lwq21){
    .h_0 = X60Qx_8}
  ;
  return result_8;}
static inline NB8 isNil_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_3){
  NB8 result_2;
  result_2 = (v_3.h_0 == 0);
  return result_2;}
static inline JsValue_0_jsfc0lwq21 newJsArray_0_jsfc0lwq21(void){
  JsValue_0_jsfc0lwq21 result_14;
  eQdestroy_0_jsfc0lwq21(result_14);
  NI32 X60Qx_17 = _jsNewArray();
  result_14 = (JsValue_0_jsfc0lwq21){
    .h_0 = X60Qx_17}
  ;
  return result_14;}
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_139){
  NI32 result_189;
  result_189 = s_139.len_0;
  return result_189;}
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_140, NI32 i_94){
  NB8 X60Qx_3644;
  if (i_94 < s_140.len_0){
    X60Qx_3644 = (0 <= i_94);}
  else {
    X60Qx_3644 = NIM_FALSE;}
  if ((!X60Qx_3644)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  Value_0_valzr1t4f* result_190;
  result_190 = (&s_140.data_0[i_94]);
  return result_190;}
static inline JsValue_0_jsfc0lwq21 toJs_0_jsfc0lwq21(NI32 x_4){
  JsValue_0_jsfc0lwq21 result_4;
  eQdestroy_0_jsfc0lwq21(result_4);
  NI32 X60Qx_4 = _numToJs(x_4);
  result_4 = (JsValue_0_jsfc0lwq21){
    .h_0 = X60Qx_4}
  ;
  return result_4;}
static inline void add_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 arr_1, JsValue_0_jsfc0lwq21 val_1){
  _jsArrPush(arr_1.h_0, val_1.h_0);}
static inline JsValue_0_jsfc0lwq21 toJs_1_jsfc0lwq21(NF64 x_5){
  JsValue_0_jsfc0lwq21 result_6;
  eQdestroy_0_jsfc0lwq21(result_6);
  NI32 X60Qx_6 = _numToJs(x_5);
  result_6 = (JsValue_0_jsfc0lwq21){
    .h_0 = X60Qx_6}
  ;
  return result_6;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline NI32 toInt_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_4){
  NI32 result_5;
  NI32 X60Qx_5 = _jsToNum(v_4.h_0);
  result_5 = X60Qx_5;
  return result_5;}
static inline NF64 toFloat_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_5){
  NF64 result_7;
  NF64 X60Qx_7 = _jsToNum(v_5.h_0);
  result_7 = X60Qx_7;
  return result_7;}
static inline NB8 toBool_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_6){
  NB8 result_9;
  NB8 X60Qx_9 = _jsToBool(v_6.h_0);
  result_9 = X60Qx_9;
  return result_9;}
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37){
  NI32 result_60;
  result_60 = s_37.len_0;
  return result_60;}
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33){
  NB8 X60Qx_1436;
  if (i_33 < s_38.len_0){
    X60Qx_1436 = (0 <= i_33);}
  else {
    X60Qx_1436 = NIM_FALSE;}
  if ((!X60Qx_1436)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* result_61;
  result_61 = (&s_38.data_0[i_33]);
  return result_61;}
static inline JsValue_0_jsfc0lwq21 newJsObject_0_jsfc0lwq21(void){
  JsValue_0_jsfc0lwq21 result_13;
  eQdestroy_0_jsfc0lwq21(result_13);
  NI32 X60Qx_16 = _jsNewObject();
  result_13 = (JsValue_0_jsfc0lwq21){
    .h_0 = X60Qx_16}
  ;
  return result_13;}
static inline seq_0_I50urnw_croph25r5 newSeqUninit_0_I8oufjc_croph25r5(NI32 size_14){
  seq_0_I50urnw_croph25r5 result_49;
  if (size_14 == 0){
    result_49 = (seq_0_I50urnw_croph25r5){
      .len_0 = size_14, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_10 = memSizeInBytes_0_Itmy7ww1_croph25r5(size_14);
    void* X60Qx_152 = alloc_1_sysvq0asl(memSize_10);
    result_49 = (seq_0_I50urnw_croph25r5){
      .len_0 = size_14, .data_0 = ((Value_0_valzr1t4f*)X60Qx_152)}
    ;
    if ((!(result_49.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_153 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_49.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_10);}}
  return result_49;}
static inline JsValue_0_jsfc0lwq21 toJs_4_jsfc0lwq21(X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21 p_3){
  JsValue_0_jsfc0lwq21 result_17;
  eQdestroy_0_jsfc0lwq21(result_17);
  NI32 X60Qx_20 = _fnToJs0(p_3);
  result_17 = (JsValue_0_jsfc0lwq21){
    .h_0 = X60Qx_20}
  ;
  return result_17;}
static inline JsValue_0_jsfc0lwq21 toJs_5_jsfc0lwq21(X60Qt_0_ISX4asX56alue0jsfc0lwq21SEAnimcallZAfalseZAR34_jsfc0lwq21 p_4){
  JsValue_0_jsfc0lwq21 result_18;
  eQdestroy_0_jsfc0lwq21(result_18);
  NI32 X60Qx_21 = _fnToJs1(p_4);
  result_18 = (JsValue_0_jsfc0lwq21){
    .h_0 = X60Qx_21}
  ;
  return result_18;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NI32 memSizeInBytes_0_Itmy7ww1_croph25r5(NI32 size_15){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_51;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_15, sizeof(Value_0_valzr1t4f), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_51 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_51 = ((NI32)2147483647);}
  return result_51;}
