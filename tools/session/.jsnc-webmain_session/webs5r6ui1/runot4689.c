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
#include <math.h>
#include <string.h>
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct BwEntry_0_runot4689 BwEntry_0_runot4689;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct seq_0_I50urnw_croph25r5 seq_0_I50urnw_croph25r5;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct PathGrant_0_iop7yt73v PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v ReadRecord_0_iop7yt73v;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct ToplevelEntry_0_prorcx25w1 ToplevelEntry_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21;
typedef struct BwEntry_0_runot4689{
  NU32 sym_0;
  NB8 isBw_0;}
BwEntry_0_runot4689;
typedef struct openArray_0_I2902h9_intzsnzax{
  Value_0_valzr1t4f* a_0;
  NI32 len_0;}
openArray_0_I2902h9_intzsnzax;
typedef struct seq_0_I50urnw_croph25r5{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_croph25r5;
typedef struct seq_0_Iw8xl5b1_arecyyj7v{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_arecyyj7v;
typedef struct openArray_0_Ig73pnk_aow7lb5cq1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_aow7lb5cq1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_Iflf8jf1_aow7lb5cq1{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_aow7lb5cq1;
typedef struct seq_0_Ixbbxx5_runot4689{
  NI32 len_0;
  BwEntry_0_runot4689* data_0;}
seq_0_Ixbbxx5_runot4689;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct openArray_0_Iu2js7k_intzsnzax{
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** a_0;
  NI32 len_0;}
openArray_0_Iu2js7k_intzsnzax;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct HSlice_0_Inzqy8d_aow7lb5cq1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_aow7lb5cq1;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
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
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Izov3yo_ast8ri79k keys_0;}
BiTable_0_Ipgo74p_ast8ri79k;
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
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
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
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
typedef struct Cell_Obj_0_valzr1t4f{
  Value_0_valzr1t4f v_0;}
Cell_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  Cell_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS11_runot4689{
  string_0_sysvq0asl a[11];}
X60Qt_0_IAarraySstring0sysvq0aslS11_runot4689;
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
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21{
  string_0_sysvq0asl fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
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
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
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
typedef struct X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1{
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1;
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
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01{
  string_0_sysvq0asl a[2];}
X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01;
typedef struct X60Qt_0_IAarrayAiS32ZS1_filqx2b6r1{
  NI32 a[1];}
X60Qt_0_IAarrayAiS32ZS1_filqx2b6r1;
typedef struct X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11{
  NC8 a[65536];}
X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11;
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
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct seq_0_Ivkh6l1_linxafkvx1{
  NI32 len_0;
  LineInfoUnpacked_0_linxafkvx1* data_0;}
seq_0_Ivkh6l1_linxafkvx1;
typedef struct LineInfoManager_0_linxafkvx1{
  seq_0_Ivkh6l1_linxafkvx1 aside_0;}
LineInfoManager_0_linxafkvx1;
typedef struct seq_0_If70loa_intzsnzax{
  NI32 len_0;
  NU32* data_0;}
seq_0_If70loa_intzsnzax;
typedef struct BiTable_0_Ieutpr21_intzsnzax{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_If70loa_intzsnzax keys_0;}
BiTable_0_Ieutpr21_intzsnzax;
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
typedef struct Literals_0_nifh7u8pu1{
  LineInfoManager_0_linxafkvx1 man_0;
  BiTable_0_Icvz6lt_buiyylk1h1 tags_0;
  BiTable_0_Ieutpr21_intzsnzax files_0;
  BiTable_0_I0ksat5_ast8ri79k syms_0;
  BiTable_0_Ipgo74p_ast8ri79k strings_0;
  BiTable_0_Itvq7bk_ast8ri79k integers_0;
  BiTable_0_Itxao711_ast8ri79k uintegers_0;
  BiTable_0_Iojfwmy1_ast8ri79k floats_0;}
Literals_0_nifh7u8pu1;
typedef NU8 LoadStatus_0_prorcx25w1;

#define LacksModuleName_0_prorcx25w1 ((NU8)0)
#define LacksOffset_0_prorcx25w1 ((NU8)1)
#define LacksPosition_0_prorcx25w1 ((NU8)2)
#define LacksNothing_0_prorcx25w1 ((NU8)3)
typedef struct LoadResult_0_prorcx25w1{
  LoadStatus_0_prorcx25w1 status_0;
  Cursor_0_nifb6mq6y1 decl_0;}
LoadResult_0_prorcx25w1;
typedef NU8 NifKind_0_nif81dubp1;

#define UnknownToken_0_nif81dubp1 ((NU8)0)
#define EofToken_0_nif81dubp1 ((NU8)1)
#define DotToken_0_nif81dubp1 ((NU8)2)
#define Ident_0_nif81dubp1 ((NU8)3)
#define Symbol_0_nif81dubp1 ((NU8)4)
#define SymbolDef_0_nif81dubp1 ((NU8)5)
#define StringLit_0_nif81dubp1 ((NU8)6)
#define CharLit_0_nif81dubp1 ((NU8)7)
#define IntLit_0_nif81dubp1 ((NU8)8)
#define UIntLit_0_nif81dubp1 ((NU8)9)
#define FloatLit_0_nif81dubp1 ((NU8)10)
#define ParLe_0_nif81dubp1 ((NU8)11)
#define ParRi_0_nif81dubp1 ((NU8)12)
typedef struct seq_0_I7dew2c_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* data_0;}
seq_0_I7dew2c_prorcx25w1;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_Ij858uv_prorcx25w1{
  seq_0_I7dew2c_prorcx25w1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ij858uv_prorcx25w1;
typedef struct SplittedModulePath_0_symkyk35i1{
  string_0_sysvq0asl dir_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl ext_0;}
SplittedModulePath_0_symkyk35i1;
typedef struct seq_0_Ikxamj_prorcx25w1{
  NI32 len_0;
  ToplevelEntry_0_prorcx25w1* data_0;}
seq_0_Ikxamj_prorcx25w1;
typedef struct seq_0_I8hny96_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax* data_0;}
seq_0_I8hny96_intzsnzax;
typedef struct Table_0_Idzo7511_intzsnzax{
  seq_0_I8hny96_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Idzo7511_intzsnzax;
typedef struct ToplevelEntries_0_prorcx25w1{
  seq_0_Ikxamj_prorcx25w1 entries_0;
  Table_0_Idzo7511_intzsnzax bySymId_0;}
ToplevelEntries_0_prorcx25w1;
typedef struct Program_0_prorcx25w1{
  Table_0_Ij858uv_prorcx25w1 mods_0;
  SplittedModulePath_0_symkyk35i1 main_0;
  ToplevelEntries_0_prorcx25w1 mem_0;}
Program_0_prorcx25w1;
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
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
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
typedef NU16 TagEnum_0_tagygirdh1;

#define InvalidTagId_0_tagygirdh1 ((NU16)0)
#define ErrTagId_0_tagygirdh1 ((NU16)1)
#define SufTagId_0_tagygirdh1 ((NU16)2)
#define AtTagId_0_tagygirdh1 ((NU16)3)
#define DerefTagId_0_tagygirdh1 ((NU16)4)
#define DotTagId_0_tagygirdh1 ((NU16)5)
#define PatTagId_0_tagygirdh1 ((NU16)6)
#define ParTagId_0_tagygirdh1 ((NU16)7)
#define AddrTagId_0_tagygirdh1 ((NU16)8)
#define NilTagId_0_tagygirdh1 ((NU16)9)
#define NotnilTagId_0_tagygirdh1 ((NU16)10)
#define UncheckedTagId_0_tagygirdh1 ((NU16)11)
#define InfTagId_0_tagygirdh1 ((NU16)12)
#define NeginfTagId_0_tagygirdh1 ((NU16)13)
#define NanTagId_0_tagygirdh1 ((NU16)14)
#define FalseTagId_0_tagygirdh1 ((NU16)15)
#define TrueTagId_0_tagygirdh1 ((NU16)16)
#define AndTagId_0_tagygirdh1 ((NU16)17)
#define OrTagId_0_tagygirdh1 ((NU16)18)
#define XorTagId_0_tagygirdh1 ((NU16)19)
#define NotTagId_0_tagygirdh1 ((NU16)20)
#define NegTagId_0_tagygirdh1 ((NU16)21)
#define SizeofTagId_0_tagygirdh1 ((NU16)22)
#define AlignofTagId_0_tagygirdh1 ((NU16)23)
#define OffsetofTagId_0_tagygirdh1 ((NU16)24)
#define OconstrTagId_0_tagygirdh1 ((NU16)25)
#define AconstrTagId_0_tagygirdh1 ((NU16)26)
#define BracketTagId_0_tagygirdh1 ((NU16)27)
#define CurlyTagId_0_tagygirdh1 ((NU16)28)
#define CurlyatTagId_0_tagygirdh1 ((NU16)29)
#define KvTagId_0_tagygirdh1 ((NU16)30)
#define VvTagId_0_tagygirdh1 ((NU16)31)
#define OvfTagId_0_tagygirdh1 ((NU16)32)
#define AddTagId_0_tagygirdh1 ((NU16)33)
#define SubTagId_0_tagygirdh1 ((NU16)34)
#define MulTagId_0_tagygirdh1 ((NU16)35)
#define DivTagId_0_tagygirdh1 ((NU16)36)
#define ModTagId_0_tagygirdh1 ((NU16)37)
#define ShrTagId_0_tagygirdh1 ((NU16)38)
#define ShlTagId_0_tagygirdh1 ((NU16)39)
#define BitandTagId_0_tagygirdh1 ((NU16)40)
#define BitorTagId_0_tagygirdh1 ((NU16)41)
#define BitxorTagId_0_tagygirdh1 ((NU16)42)
#define BitnotTagId_0_tagygirdh1 ((NU16)43)
#define EqTagId_0_tagygirdh1 ((NU16)44)
#define NeqTagId_0_tagygirdh1 ((NU16)45)
#define LeTagId_0_tagygirdh1 ((NU16)46)
#define LtTagId_0_tagygirdh1 ((NU16)47)
#define CastTagId_0_tagygirdh1 ((NU16)48)
#define ConvTagId_0_tagygirdh1 ((NU16)49)
#define CallTagId_0_tagygirdh1 ((NU16)50)
#define CmdTagId_0_tagygirdh1 ((NU16)51)
#define RangeTagId_0_tagygirdh1 ((NU16)52)
#define RangesTagId_0_tagygirdh1 ((NU16)53)
#define GvarTagId_0_tagygirdh1 ((NU16)54)
#define TvarTagId_0_tagygirdh1 ((NU16)55)
#define VarTagId_0_tagygirdh1 ((NU16)56)
#define ParamTagId_0_tagygirdh1 ((NU16)57)
#define ConstTagId_0_tagygirdh1 ((NU16)58)
#define ResultTagId_0_tagygirdh1 ((NU16)59)
#define GletTagId_0_tagygirdh1 ((NU16)60)
#define TletTagId_0_tagygirdh1 ((NU16)61)
#define LetTagId_0_tagygirdh1 ((NU16)62)
#define CursorTagId_0_tagygirdh1 ((NU16)63)
#define PatternvarTagId_0_tagygirdh1 ((NU16)64)
#define TypevarTagId_0_tagygirdh1 ((NU16)65)
#define StaticTypevarTagId_0_tagygirdh1 ((NU16)66)
#define EfldTagId_0_tagygirdh1 ((NU16)67)
#define FldTagId_0_tagygirdh1 ((NU16)68)
#define GfldTagId_0_tagygirdh1 ((NU16)69)
#define ProcTagId_0_tagygirdh1 ((NU16)70)
#define FuncTagId_0_tagygirdh1 ((NU16)71)
#define IteratorTagId_0_tagygirdh1 ((NU16)72)
#define ConverterTagId_0_tagygirdh1 ((NU16)73)
#define MethodTagId_0_tagygirdh1 ((NU16)74)
#define MacroTagId_0_tagygirdh1 ((NU16)75)
#define TemplateTagId_0_tagygirdh1 ((NU16)76)
#define TypeTagId_0_tagygirdh1 ((NU16)77)
#define BlockTagId_0_tagygirdh1 ((NU16)78)
#define ModuleTagId_0_tagygirdh1 ((NU16)79)
#define CchoiceTagId_0_tagygirdh1 ((NU16)80)
#define OchoiceTagId_0_tagygirdh1 ((NU16)81)
#define EmitTagId_0_tagygirdh1 ((NU16)82)
#define AsgnTagId_0_tagygirdh1 ((NU16)83)
#define StoreTagId_0_tagygirdh1 ((NU16)84)
#define KeepovfTagId_0_tagygirdh1 ((NU16)85)
#define ScopeTagId_0_tagygirdh1 ((NU16)86)
#define IfTagId_0_tagygirdh1 ((NU16)87)
#define WhenTagId_0_tagygirdh1 ((NU16)88)
#define ElifTagId_0_tagygirdh1 ((NU16)89)
#define ElseTagId_0_tagygirdh1 ((NU16)90)
#define TypevarsTagId_0_tagygirdh1 ((NU16)91)
#define BreakTagId_0_tagygirdh1 ((NU16)92)
#define ContinueTagId_0_tagygirdh1 ((NU16)93)
#define ForTagId_0_tagygirdh1 ((NU16)94)
#define WhileTagId_0_tagygirdh1 ((NU16)95)
#define CoroforTagId_0_tagygirdh1 ((NU16)96)
#define CaseTagId_0_tagygirdh1 ((NU16)97)
#define OfTagId_0_tagygirdh1 ((NU16)98)
#define LabTagId_0_tagygirdh1 ((NU16)99)
#define JmpTagId_0_tagygirdh1 ((NU16)100)
#define RetTagId_0_tagygirdh1 ((NU16)101)
#define YldTagId_0_tagygirdh1 ((NU16)102)
#define StmtsTagId_0_tagygirdh1 ((NU16)103)
#define ParamsTagId_0_tagygirdh1 ((NU16)104)
#define UnionTagId_0_tagygirdh1 ((NU16)105)
#define ObjectTagId_0_tagygirdh1 ((NU16)106)
#define EnumTagId_0_tagygirdh1 ((NU16)107)
#define ProctypeTagId_0_tagygirdh1 ((NU16)108)
#define AtomicTagId_0_tagygirdh1 ((NU16)109)
#define RoTagId_0_tagygirdh1 ((NU16)110)
#define RestrictTagId_0_tagygirdh1 ((NU16)111)
#define CpprefTagId_0_tagygirdh1 ((NU16)112)
#define ITagId_0_tagygirdh1 ((NU16)113)
#define UTagId_0_tagygirdh1 ((NU16)114)
#define FTagId_0_tagygirdh1 ((NU16)115)
#define CTagId_0_tagygirdh1 ((NU16)116)
#define BoolTagId_0_tagygirdh1 ((NU16)117)
#define VoidTagId_0_tagygirdh1 ((NU16)118)
#define PtrTagId_0_tagygirdh1 ((NU16)119)
#define ArrayTagId_0_tagygirdh1 ((NU16)120)
#define FlexarrayTagId_0_tagygirdh1 ((NU16)121)
#define AptrTagId_0_tagygirdh1 ((NU16)122)
#define CdeclTagId_0_tagygirdh1 ((NU16)123)
#define StdcallTagId_0_tagygirdh1 ((NU16)124)
#define SafecallTagId_0_tagygirdh1 ((NU16)125)
#define SyscallTagId_0_tagygirdh1 ((NU16)126)
#define FastcallTagId_0_tagygirdh1 ((NU16)127)
#define ThiscallTagId_0_tagygirdh1 ((NU16)128)
#define NoconvTagId_0_tagygirdh1 ((NU16)129)
#define MemberTagId_0_tagygirdh1 ((NU16)130)
#define NimcallTagId_0_tagygirdh1 ((NU16)131)
#define InlineTagId_0_tagygirdh1 ((NU16)132)
#define NoinlineTagId_0_tagygirdh1 ((NU16)133)
#define ClosureTagId_0_tagygirdh1 ((NU16)134)
#define AttrTagId_0_tagygirdh1 ((NU16)135)
#define SmryTagId_0_tagygirdh1 ((NU16)136)
#define VarargsTagId_0_tagygirdh1 ((NU16)137)
#define WasTagId_0_tagygirdh1 ((NU16)138)
#define SelectanyTagId_0_tagygirdh1 ((NU16)139)
#define PragmasTagId_0_tagygirdh1 ((NU16)140)
#define PragmaxTagId_0_tagygirdh1 ((NU16)141)
#define AlignTagId_0_tagygirdh1 ((NU16)142)
#define BitsTagId_0_tagygirdh1 ((NU16)143)
#define VectorTagId_0_tagygirdh1 ((NU16)144)
#define NodeclTagId_0_tagygirdh1 ((NU16)145)
#define InclTagId_0_tagygirdh1 ((NU16)146)
#define ExclTagId_0_tagygirdh1 ((NU16)147)
#define IncludeTagId_0_tagygirdh1 ((NU16)148)
#define ImportTagId_0_tagygirdh1 ((NU16)149)
#define ImportasTagId_0_tagygirdh1 ((NU16)150)
#define FromimportTagId_0_tagygirdh1 ((NU16)151)
#define ImportexceptTagId_0_tagygirdh1 ((NU16)152)
#define ExportTagId_0_tagygirdh1 ((NU16)153)
#define FromexportTagId_0_tagygirdh1 ((NU16)154)
#define ExportexceptTagId_0_tagygirdh1 ((NU16)155)
#define CommentTagId_0_tagygirdh1 ((NU16)156)
#define DiscardTagId_0_tagygirdh1 ((NU16)157)
#define TryTagId_0_tagygirdh1 ((NU16)158)
#define RaiseTagId_0_tagygirdh1 ((NU16)159)
#define OnerrTagId_0_tagygirdh1 ((NU16)160)
#define RaisesTagId_0_tagygirdh1 ((NU16)161)
#define ErrsTagId_0_tagygirdh1 ((NU16)162)
#define StaticTagId_0_tagygirdh1 ((NU16)163)
#define IteTagId_0_tagygirdh1 ((NU16)164)
#define ItecTagId_0_tagygirdh1 ((NU16)165)
#define LoopTagId_0_tagygirdh1 ((NU16)166)
#define VTagId_0_tagygirdh1 ((NU16)167)
#define EtupatTagId_0_tagygirdh1 ((NU16)168)
#define UnknownTagId_0_tagygirdh1 ((NU16)169)
#define JtrueTagId_0_tagygirdh1 ((NU16)170)
#define MflagTagId_0_tagygirdh1 ((NU16)171)
#define VflagTagId_0_tagygirdh1 ((NU16)172)
#define EitherTagId_0_tagygirdh1 ((NU16)173)
#define JoinTagId_0_tagygirdh1 ((NU16)174)
#define GraphTagId_0_tagygirdh1 ((NU16)175)
#define ForbindTagId_0_tagygirdh1 ((NU16)176)
#define KillTagId_0_tagygirdh1 ((NU16)177)
#define UnpackflatTagId_0_tagygirdh1 ((NU16)178)
#define UnpacktupTagId_0_tagygirdh1 ((NU16)179)
#define CallargsTagId_0_tagygirdh1 ((NU16)180)
#define ForcallTagId_0_tagygirdh1 ((NU16)181)
#define UnpackdeclTagId_0_tagygirdh1 ((NU16)182)
#define ExceptTagId_0_tagygirdh1 ((NU16)183)
#define FinTagId_0_tagygirdh1 ((NU16)184)
#define TupleTagId_0_tagygirdh1 ((NU16)185)
#define OnumTagId_0_tagygirdh1 ((NU16)186)
#define AnumTagId_0_tagygirdh1 ((NU16)187)
#define RefTagId_0_tagygirdh1 ((NU16)188)
#define MutTagId_0_tagygirdh1 ((NU16)189)
#define OutTagId_0_tagygirdh1 ((NU16)190)
#define LentTagId_0_tagygirdh1 ((NU16)191)
#define SinkTagId_0_tagygirdh1 ((NU16)192)
#define NiltTagId_0_tagygirdh1 ((NU16)193)
#define ConceptTagId_0_tagygirdh1 ((NU16)194)
#define DistinctTagId_0_tagygirdh1 ((NU16)195)
#define ItertypeTagId_0_tagygirdh1 ((NU16)196)
#define RangetypeTagId_0_tagygirdh1 ((NU16)197)
#define UarrayTagId_0_tagygirdh1 ((NU16)198)
#define SetTagId_0_tagygirdh1 ((NU16)199)
#define AutoTagId_0_tagygirdh1 ((NU16)200)
#define SymkindTagId_0_tagygirdh1 ((NU16)201)
#define TypekindTagId_0_tagygirdh1 ((NU16)202)
#define TypedescTagId_0_tagygirdh1 ((NU16)203)
#define UntypedTagId_0_tagygirdh1 ((NU16)204)
#define TypedTagId_0_tagygirdh1 ((NU16)205)
#define CstringTagId_0_tagygirdh1 ((NU16)206)
#define PointerTagId_0_tagygirdh1 ((NU16)207)
#define OrdinalTagId_0_tagygirdh1 ((NU16)208)
#define MagicTagId_0_tagygirdh1 ((NU16)209)
#define ImportcTagId_0_tagygirdh1 ((NU16)210)
#define ImportcppTagId_0_tagygirdh1 ((NU16)211)
#define DynlibTagId_0_tagygirdh1 ((NU16)212)
#define ExportcTagId_0_tagygirdh1 ((NU16)213)
#define HeaderTagId_0_tagygirdh1 ((NU16)214)
#define ThreadvarTagId_0_tagygirdh1 ((NU16)215)
#define GlobalTagId_0_tagygirdh1 ((NU16)216)
#define DiscardableTagId_0_tagygirdh1 ((NU16)217)
#define NoreturnTagId_0_tagygirdh1 ((NU16)218)
#define BorrowTagId_0_tagygirdh1 ((NU16)219)
#define NoSideEffectTagId_0_tagygirdh1 ((NU16)220)
#define NodestroyTagId_0_tagygirdh1 ((NU16)221)
#define PluginTagId_0_tagygirdh1 ((NU16)222)
#define BycopyTagId_0_tagygirdh1 ((NU16)223)
#define ByrefTagId_0_tagygirdh1 ((NU16)224)
#define NoinitTagId_0_tagygirdh1 ((NU16)225)
#define RequiresTagId_0_tagygirdh1 ((NU16)226)
#define EnsuresTagId_0_tagygirdh1 ((NU16)227)
#define AssumeTagId_0_tagygirdh1 ((NU16)228)
#define AssertTagId_0_tagygirdh1 ((NU16)229)
#define BuildTagId_0_tagygirdh1 ((NU16)230)
#define FeatureTagId_0_tagygirdh1 ((NU16)231)
#define StringTagId_0_tagygirdh1 ((NU16)232)
#define ViewTagId_0_tagygirdh1 ((NU16)233)
#define IncompleteStructTagId_0_tagygirdh1 ((NU16)234)
#define QQuotedTagId_0_tagygirdh1 ((NU16)235)
#define HderefTagId_0_tagygirdh1 ((NU16)236)
#define DdotTagId_0_tagygirdh1 ((NU16)237)
#define HaddrTagId_0_tagygirdh1 ((NU16)238)
#define NewrefTagId_0_tagygirdh1 ((NU16)239)
#define NewobjTagId_0_tagygirdh1 ((NU16)240)
#define TupTagId_0_tagygirdh1 ((NU16)241)
#define TupconstrTagId_0_tagygirdh1 ((NU16)242)
#define SetconstrTagId_0_tagygirdh1 ((NU16)243)
#define TabconstrTagId_0_tagygirdh1 ((NU16)244)
#define AshrTagId_0_tagygirdh1 ((NU16)245)
#define BaseobjTagId_0_tagygirdh1 ((NU16)246)
#define HconvTagId_0_tagygirdh1 ((NU16)247)
#define DconvTagId_0_tagygirdh1 ((NU16)248)
#define CallstrlitTagId_0_tagygirdh1 ((NU16)249)
#define InfixTagId_0_tagygirdh1 ((NU16)250)
#define PrefixTagId_0_tagygirdh1 ((NU16)251)
#define HcallTagId_0_tagygirdh1 ((NU16)252)
#define CompilesTagId_0_tagygirdh1 ((NU16)253)
#define DeclaredTagId_0_tagygirdh1 ((NU16)254)
#define DefinedTagId_0_tagygirdh1 ((NU16)255)
#define AstToStrTagId_0_tagygirdh1 ((NU16)256)
#define BindSymTagId_0_tagygirdh1 ((NU16)257)
#define BindSymNameTagId_0_tagygirdh1 ((NU16)258)
#define InstanceofTagId_0_tagygirdh1 ((NU16)259)
#define ProccallTagId_0_tagygirdh1 ((NU16)260)
#define HighTagId_0_tagygirdh1 ((NU16)261)
#define LowTagId_0_tagygirdh1 ((NU16)262)
#define TypeofTagId_0_tagygirdh1 ((NU16)263)
#define UnpackTagId_0_tagygirdh1 ((NU16)264)
#define FieldsTagId_0_tagygirdh1 ((NU16)265)
#define FieldpairsTagId_0_tagygirdh1 ((NU16)266)
#define EnumtostrTagId_0_tagygirdh1 ((NU16)267)
#define IsmainmoduleTagId_0_tagygirdh1 ((NU16)268)
#define DefaultobjTagId_0_tagygirdh1 ((NU16)269)
#define DefaulttupTagId_0_tagygirdh1 ((NU16)270)
#define DefaultdistinctTagId_0_tagygirdh1 ((NU16)271)
#define DelayTagId_0_tagygirdh1 ((NU16)272)
#define Delay0TagId_0_tagygirdh1 ((NU16)273)
#define SuspendTagId_0_tagygirdh1 ((NU16)274)
#define ExprTagId_0_tagygirdh1 ((NU16)275)
#define DoTagId_0_tagygirdh1 ((NU16)276)
#define ArratTagId_0_tagygirdh1 ((NU16)277)
#define TupatTagId_0_tagygirdh1 ((NU16)278)
#define PlussetTagId_0_tagygirdh1 ((NU16)279)
#define MinussetTagId_0_tagygirdh1 ((NU16)280)
#define MulsetTagId_0_tagygirdh1 ((NU16)281)
#define XorsetTagId_0_tagygirdh1 ((NU16)282)
#define EqsetTagId_0_tagygirdh1 ((NU16)283)
#define LesetTagId_0_tagygirdh1 ((NU16)284)
#define LtsetTagId_0_tagygirdh1 ((NU16)285)
#define InsetTagId_0_tagygirdh1 ((NU16)286)
#define CardTagId_0_tagygirdh1 ((NU16)287)
#define EmoveTagId_0_tagygirdh1 ((NU16)288)
#define DestroyTagId_0_tagygirdh1 ((NU16)289)
#define DupTagId_0_tagygirdh1 ((NU16)290)
#define CopyTagId_0_tagygirdh1 ((NU16)291)
#define WasmovedTagId_0_tagygirdh1 ((NU16)292)
#define SinkhTagId_0_tagygirdh1 ((NU16)293)
#define TraceTagId_0_tagygirdh1 ((NU16)294)
#define ErrvTagId_0_tagygirdh1 ((NU16)295)
#define StaticstmtTagId_0_tagygirdh1 ((NU16)296)
#define BindTagId_0_tagygirdh1 ((NU16)297)
#define MixinTagId_0_tagygirdh1 ((NU16)298)
#define UsingTagId_0_tagygirdh1 ((NU16)299)
#define AsmTagId_0_tagygirdh1 ((NU16)300)
#define DeferTagId_0_tagygirdh1 ((NU16)301)
#define IndexTagId_0_tagygirdh1 ((NU16)302)
#define InjectTagId_0_tagygirdh1 ((NU16)303)
#define GensymTagId_0_tagygirdh1 ((NU16)304)
#define DirtyTagId_0_tagygirdh1 ((NU16)305)
#define ErrorTagId_0_tagygirdh1 ((NU16)306)
#define ReportTagId_0_tagygirdh1 ((NU16)307)
#define TagsTagId_0_tagygirdh1 ((NU16)308)
#define DeprecatedTagId_0_tagygirdh1 ((NU16)309)
#define SideEffectTagId_0_tagygirdh1 ((NU16)310)
#define KeepOverflowFlagTagId_0_tagygirdh1 ((NU16)311)
#define SemanticsTagId_0_tagygirdh1 ((NU16)312)
#define InheritableTagId_0_tagygirdh1 ((NU16)313)
#define BaseTagId_0_tagygirdh1 ((NU16)314)
#define PureTagId_0_tagygirdh1 ((NU16)315)
#define FinalTagId_0_tagygirdh1 ((NU16)316)
#define AcyclicTagId_0_tagygirdh1 ((NU16)317)
#define PragmaTagId_0_tagygirdh1 ((NU16)318)
#define InternalTypeNameTagId_0_tagygirdh1 ((NU16)319)
#define InternalFieldPairsTagId_0_tagygirdh1 ((NU16)320)
#define FailedTagId_0_tagygirdh1 ((NU16)321)
#define IsTagId_0_tagygirdh1 ((NU16)322)
#define EnvpTagId_0_tagygirdh1 ((NU16)323)
#define PackedTagId_0_tagygirdh1 ((NU16)324)
#define PassiveTagId_0_tagygirdh1 ((NU16)325)
#define PushTagId_0_tagygirdh1 ((NU16)326)
#define CallConvTagId_0_tagygirdh1 ((NU16)327)
#define PopTagId_0_tagygirdh1 ((NU16)328)
#define PassLTagId_0_tagygirdh1 ((NU16)329)
#define PassCTagId_0_tagygirdh1 ((NU16)330)
#define MethodsTagId_0_tagygirdh1 ((NU16)331)
#define SizeTagId_0_tagygirdh1 ((NU16)332)
#define UncheckedAccessTagId_0_tagygirdh1 ((NU16)333)
#define UncheckedAssignTagId_0_tagygirdh1 ((NU16)334)
#define ProfilerTagId_0_tagygirdh1 ((NU16)335)
#define StacktraceTagId_0_tagygirdh1 ((NU16)336)
#define GcsafeTagId_0_tagygirdh1 ((NU16)337)
#define UsedTagId_0_tagygirdh1 ((NU16)338)
#define CompileTagId_0_tagygirdh1 ((NU16)339)
#define BundleTagId_0_tagygirdh1 ((NU16)340)
#define ToClosureTagId_0_tagygirdh1 ((NU16)341)
typedef struct X60Qt_0_IAarrayAuS8ZS11_decqocs071{
  NU8 a[11];}
X60Qt_0_IAarrayAuS8ZS11_decqocs071;
typedef NU8 SkipMode_0_decqocs071;

#define SkipExclBody_0_decqocs071 ((NU8)0)
#define SkipInclBody_0_decqocs071 ((NU8)1)
#define SkipFinalParRi_0_decqocs071 ((NU8)2)
typedef NU8 NimonyOther_0_nimry5ra91;

#define NoSub_0_nimry5ra91 ((NU8)0)
#define NilU_0_nimry5ra91 ((NU8)9)
#define NotnilU_0_nimry5ra91 ((NU8)10)
#define UncheckedU_0_nimry5ra91 ((NU8)11)
#define KvU_0_nimry5ra91 ((NU8)30)
#define VvU_0_nimry5ra91 ((NU8)31)
#define RangeU_0_nimry5ra91 ((NU8)52)
#define RangesU_0_nimry5ra91 ((NU8)53)
#define ParamU_0_nimry5ra91 ((NU8)57)
#define TypevarU_0_nimry5ra91 ((NU8)65)
#define StaticTypevarU_0_nimry5ra91 ((NU8)66)
#define EfldU_0_nimry5ra91 ((NU8)67)
#define FldU_0_nimry5ra91 ((NU8)68)
#define GfldU_0_nimry5ra91 ((NU8)69)
#define WhenU_0_nimry5ra91 ((NU8)88)
#define ElifU_0_nimry5ra91 ((NU8)89)
#define ElseU_0_nimry5ra91 ((NU8)90)
#define TypevarsU_0_nimry5ra91 ((NU8)91)
#define CaseU_0_nimry5ra91 ((NU8)97)
#define OfU_0_nimry5ra91 ((NU8)98)
#define StmtsU_0_nimry5ra91 ((NU8)103)
#define ParamsU_0_nimry5ra91 ((NU8)104)
#define PragmasU_0_nimry5ra91 ((NU8)140)
#define EitherU_0_nimry5ra91 ((NU8)173)
#define JoinU_0_nimry5ra91 ((NU8)174)
#define UnpackflatU_0_nimry5ra91 ((NU8)178)
#define UnpacktupU_0_nimry5ra91 ((NU8)179)
#define CallargsU_0_nimry5ra91 ((NU8)180)
#define ForcallU_0_nimry5ra91 ((NU8)181)
#define ExceptU_0_nimry5ra91 ((NU8)183)
#define FinU_0_nimry5ra91 ((NU8)184)
typedef NU8 SemPhase_0_prorcx25w1;

#define SemcheckTopLevelSyms_0_prorcx25w1 ((NU8)0)
#define SemcheckSignaturesInProgress_0_prorcx25w1 ((NU8)1)
#define SemcheckSignatures_0_prorcx25w1 ((NU8)2)
#define SemcheckBodiesInProgress_0_prorcx25w1 ((NU8)3)
#define SemcheckBodies_0_prorcx25w1 ((NU8)4)
typedef NU8 FileMode_0_syn1lfpjv;

#define fmRead_0_syn1lfpjv ((NU8)0)
#define fmWrite_0_syn1lfpjv ((NU8)1)
#define fmReadWrite_0_syn1lfpjv ((NU8)2)
#define fmReadWriteExisting_0_syn1lfpjv ((NU8)3)
#define fmAppend_0_syn1lfpjv ((NU8)4)
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7)(string_0_sysvq0asl);
typedef struct X60Qt_0_IAarrayAuS8ZS43_ast8ri79k{
  NU8 a[43];}
X60Qt_0_IAarrayAuS8ZS43_ast8ri79k;
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
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1{
  string_0_sysvq0asl fld_0;
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef struct ToplevelEntry_0_prorcx25w1{
  TokenBuf_0_nifb6mq6y1 buffer_0;
  SemPhase_0_prorcx25w1 phase_0;}
ToplevelEntry_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax{
  NU32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax;
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
typedef struct MemFile_0_memlzdyby{
  void* mem_0;
  NI32 size_0;
  int handle_0;
  int flags_0;}
MemFile_0_memlzdyby;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1)(VfsBlob_0_vfsc9jn7*);
typedef struct VfsBlob_0_vfsc9jn7{
  void* data_0;
  NI32 size_0;
  MemFile_0_memlzdyby mf_0;
  void* cookie_0;
  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1 cleanup_0;}
VfsBlob_0_vfsc9jn7;
typedef struct StringView_0_strdllfw2{
  NC8* p_0;
  NI32 len_0;}
StringView_0_strdllfw2;
typedef struct FilePos_0_nif81dubp1{
  NI32 col_0;
  NI32 line_0;}
FilePos_0_nif81dubp1;
typedef struct ExpandedToken_0_nif81dubp1{
  NifKind_0_nif81dubp1 tk_0;
  NU8 flags_0;
  NU16 kind_0;
  StringView_0_strdllfw2 data_0;
  FilePos_0_nif81dubp1 pos_0;
  StringView_0_strdllfw2 filename_0;
  StringView_0_strdllfw2 comment_0;}
ExpandedToken_0_nif81dubp1;
typedef struct Reader_0_nif81dubp1{
  NC8* p_0;
  void* eof_0;
  VfsBlob_0_vfsc9jn7 f_0;
  string_0_sysvq0asl buf_0;
  string_0_sysvq0asl thisModule_0;
  NI32 line_0;
  NI32 indexAt_0;
  ExpandedToken_0_nif81dubp1 unusedNameHint_0;}
Reader_0_nif81dubp1;
typedef struct seq_0_Io4pvgy1_nifb6mq6y1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Io4pvgy1_nifb6mq6y1;
typedef struct Stream_0_nifh7u8pu1{
  Reader_0_nif81dubp1 r_0;
  seq_0_Io4pvgy1_nifb6mq6y1 parents_0;}
Stream_0_nifh7u8pu1;
typedef struct seq_0_Ilvi9zw_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* data_0;}
seq_0_Ilvi9zw_intzsnzax;
typedef struct seq_0_Imzz798_nifa1znj21{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21* data_0;}
seq_0_Imzz798_nifa1znj21;
typedef struct NifIndex_0_nifa1znj21{
  seq_0_Ilvi9zw_intzsnzax converters_0;
  seq_0_Imzz798_nifa1znj21 exports_0;}
NifIndex_0_nifa1znj21;
typedef struct seq_0_Irkj95k_nifa1znj21{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* data_0;}
seq_0_Irkj95k_nifa1znj21;
typedef struct Table_0_Iyfwn301_nifa1znj21{
  seq_0_Irkj95k_nifa1znj21 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Iyfwn301_nifa1znj21;
typedef struct NifModule_Obj_0_prorcx25w1{
  Stream_0_nifh7u8pu1 stream_0;
  NifIndex_0_nifa1znj21 index_0;
  Table_0_Iyfwn301_nifa1znj21 public_0;
  Table_0_Iyfwn301_nifa1znj21 private_0;}
NifModule_Obj_0_prorcx25w1;
typedef struct X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1{
  NI r_00;
  NifModule_Obj_0_prorcx25w1 d_00;}
X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef NU16 NifIndexKind_0_nif12fhfr1;

#define NoIndexTag_0_nif12fhfr1 ((NU16)0)
#define KvIdx_0_nif12fhfr1 ((NU16)30)
#define VvIdx_0_nif12fhfr1 ((NU16)31)
#define GvarIdx_0_nif12fhfr1 ((NU16)54)
#define TvarIdx_0_nif12fhfr1 ((NU16)55)
#define VarIdx_0_nif12fhfr1 ((NU16)56)
#define ConstIdx_0_nif12fhfr1 ((NU16)58)
#define GletIdx_0_nif12fhfr1 ((NU16)60)
#define TletIdx_0_nif12fhfr1 ((NU16)61)
#define LetIdx_0_nif12fhfr1 ((NU16)62)
#define CursorIdx_0_nif12fhfr1 ((NU16)63)
#define ProcIdx_0_nif12fhfr1 ((NU16)70)
#define FuncIdx_0_nif12fhfr1 ((NU16)71)
#define IteratorIdx_0_nif12fhfr1 ((NU16)72)
#define ConverterIdx_0_nif12fhfr1 ((NU16)73)
#define MethodIdx_0_nif12fhfr1 ((NU16)74)
#define MacroIdx_0_nif12fhfr1 ((NU16)75)
#define TemplateIdx_0_nif12fhfr1 ((NU16)76)
#define TypeIdx_0_nif12fhfr1 ((NU16)77)
#define InlineIdx_0_nif12fhfr1 ((NU16)132)
#define ExportIdx_0_nif12fhfr1 ((NU16)153)
#define FromexportIdx_0_nif12fhfr1 ((NU16)154)
#define ExportexceptIdx_0_nif12fhfr1 ((NU16)155)
#define BuildIdx_0_nif12fhfr1 ((NU16)230)
#define IndexIdx_0_nif12fhfr1 ((NU16)302)
#define BundleIdx_0_nif12fhfr1 ((NU16)340)
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21{
  string_0_sysvq0asl fld_0;
  NifIndexKind_0_nif12fhfr1 fld_1;
  seq_0_Izov3yo_ast8ri79k fld_2;}
X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21;
typedef NU8 IndexVisibility_0_nifa1znj21;

#define Hidden_0_nifa1znj21 ((NU8)0)
#define Exported_0_nifa1znj21 ((NU8)1)
typedef struct NifIndexEntry_0_nifa1znj21{
  NI32 offset_0;
  NU32 info_0;
  IndexVisibility_0_nifa1znj21 vis_0;}
NifIndexEntry_0_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21{
  string_0_sysvq0asl fld_0;
  NifIndexEntry_0_nifa1znj21 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21;
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* ptrCell_0_runot4689(Value_0_valzr1t4f* v_3);
Value_0_valzr1t4f defaultForType_1_runot4689(Cursor_0_nifb6mq6y1 typ_2);
Value_0_valzr1t4f libcConstVal_0_runot4689(string_0_sysvq0asl b_2, NB8* found_4);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_In7zd9y_runot4689(X60Qt_0_IAarraySstring0sysvq0aslS11_runot4689* x_30);
static inline NI32 len_3_Iktsa441_runot4689(seq_0_Ixbbxx5_runot4689 s_61);
static inline BwEntry_0_runot4689* getQ_7_I1zo4u41_runot4689(seq_0_Ixbbxx5_runot4689 s_62, NI32 i_66);
static inline void add_0_Ifyely51_runot4689(seq_0_Ixbbxx5_runot4689* s_63, BwEntry_0_runot4689 elem_11);
static inline X60Qt_0_IAarrayAuS64ZS4_intzsnzax default_23_I3gf93w_runot4689(void);
static inline NI32 memSizeInBytes_0_I56aaae_runot4689(NI32 size_26);
static inline NI32 capInBytes_0_Ibnuxic1_runot4689(seq_0_Ixbbxx5_runot4689 s_88);
NB8 resize_0_I0hj5uk1_runot4689(seq_0_Ixbbxx5_runot4689* dest_9, NI32 addedElements_9);
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_runot4689(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21* dest_0);
void eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_runot4689(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 dest_0);
void eQwasmovedQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1* dest_0);
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 dest_0);
void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_runot4689(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* dest_0);
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_arecyyj7v* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8);
static inline NI32 len_3_I83dzei_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_25);
extern NI32 hostErrno_0_hos1fpv3m1(void);
extern Value_0_valzr1t4f vInt_0_valzr1t4f(NI64 x_2, NI32 bits_0);
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_26, NI32 i_28);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* newCell_0_valzr1t4f(Value_0_valzr1t4f* v_0);
extern NI32 hostSockErrno_0_hos9jnsbq1(void);
extern LongString_0_sysvq0asl const strlit_0_I10157464168546919252_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I7262382801534885590_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I7117386163922528102_emi78vuj01;
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_30);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void doQQuit_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_16, NI32 code_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern LongString_0_sysvq0asl const strlit_0_I6395244567427789796_croph25r5;
static inline NI32 len_6_Iy5lph11_intzsnzax(openArray_0_I2902h9_intzsnzax a_75);
static inline Value_0_valzr1t4f* getQ_10_Igi7i95_intzsnzax(openArray_0_I2902h9_intzsnzax x_31, NI32 idx_51);
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern Value_0_valzr1t4f vStr_0_valzr1t4f(string_0_sysvq0asl s_0);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
extern LongString_0_sysvq0asl const strlit_0_I18357185398770638485_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I11643015150811461308_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I11024699549390617459_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I3703322799828345117_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I4511345809429878981_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I10462096440466995513_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I1177603226064417776_aow7lb5cq1;
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_142);
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_143, NI32 i_95);
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13);
static inline string_0_sysvq0asl* getQ_0_I93d71y_der823rwr1(BiTable_0_Icvz6lt_buiyylk1h1 t_5, NU32 litId_1);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_Iw8xl5b1_arecyyj7v newSeqUninit_0_I1tbjnk1_arecyyj7v(NI32 size_24);
extern LoadResult_0_prorcx25w1 tryLoadSymSafe_0_modzy18mg1(NU32 s_0);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
extern LongString_0_sysvq0asl const strlit_0_I2171368188661376471_emi78vuj01;
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
extern LongString_0_sysvq0asl const strlit_0_I13413619771642637377_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I3225181402180923291_fiepkwzpc;
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
extern LongString_0_sysvq0asl const strlit_0_I16393544569146403439_intzsnzax;
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10);
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6);
extern NI64 asInt_0_valzr1t4f(Value_0_valzr1t4f* v_17);
static inline X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0_valzr1t4f(Value_0_valzr1t4f* v_7);
static inline NI32 foff_0_valzr1t4f(Value_0_valzr1t4f* v_8);
extern NU8 byteAt_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_1, NI32 off_1);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
static inline X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0_valzr1t4f(Value_0_valzr1t4f* v_4);
static inline NI32 base_0_valzr1t4f(Value_0_valzr1t4f* v_6);
static inline X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0_valzr1t4f(Value_0_valzr1t4f* v_5);
extern NI32 regionLen_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_2);
extern NB8 regionIsByteFaithful_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_0);
extern void setByteAt_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_4, NI32 off_2, NU8 b_1);
extern NB8 isMemMagic_0_flaksyopx1(string_0_sysvq0asl base_0);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I11216437567223755660_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I4303973984874128508_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I4300154733488353634_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I3006705858755300605_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I8566804573867139999_nimry5ra91;
extern LongString_0_sysvq0asl const strlit_0_I4978164850318270062_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I3411051090140283573_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I2027400509069786846_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I12542130669033277445_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I7514604024534592575_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I7466143617196742693_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I3225684998187034911_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I11042971208590088895_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I900530018976380608_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I7616721286816756_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I17971560687400798064_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I17563301282676592437_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I885514587362827984_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I9592449470941440445_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I17106851413817154788_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I14251590839437571501_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I16529604172406501048_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I10217866098611558294_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I6178772090241098573_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I13565819874765507459_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I12440307187701028700_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I3703669261441550327_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I11445521212967021334_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I4266325610518786829_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I10138590777481088495_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I11697234225982197076_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I4718597432102153922_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I13735625106940001307_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I4050815769175754417_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I2912131129587157308_hos1fpv3m1;
extern NF64 toFloat64_0_xinat3x34(xint_0_xinat3x34 x_7);
static inline void eQwasMoved_1_I4kgdoh1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v* s_76);
extern void eQdestroy_1_I8k3d0z1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_75);
extern seq_0_Iw8xl5b1_arecyyj7v eQdup_1_Io30l171_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v a_15);
extern NU64 regionAddr_0_flaksyopx1(Value_0_valzr1t4f* v_14);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern Program_0_prorcx25w1 prog_0_prorcx25w1;
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern string_0_sysvq0asl extractModule_0_symkyk35i1(string_0_sysvq0asl s_2);
extern string_0_sysvq0asl substr_1_sysvq0asl(string_0_sysvq0asl s_57, NI32 first_1);
extern LongString_0_sysvq0asl const strlit_0_I4160594580551937874_intzsnzax;
extern string_0_sysvq0asl uhashBase36_0_modjbswg91(string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I355568250392628060_hos14g919;
static inline string_0_sysvq0asl suffixToNif_0_prorcx25w1(string_0_sysvq0asl suffix_1);
static inline string_0_sysvq0asl vfsRead_0_vfsc9jn7(string_0_sysvq0asl path_1);
extern LongString_0_sysvq0asl const strlit_0_I12313941242067973473_aow7lb5cq1;
extern NI32 progRootGen_0_modzy18mg1(void);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
extern void eQdestroy_1_I7a20g9_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_100);
static inline seq_0_Iflf8jf1_aow7lb5cq1 newSeqUninit_0_I5mozxi1_aow7lb5cq1(NI32 size_14);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39);
static inline NB8* getQ_7_Iul1no9_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_55, NI32 i_45);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline void add_0_Irnc3p1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_53, NB8 elem_16);
static inline NimonySym_0_nimry5ra91 symKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_11);
static inline NB8 isRoutine_0_decqocs071(NimonySym_0_nimry5ra91 t_0);
extern Routine_0_decqocs071 asRoutine_0_decqocs071(Cursor_0_nifb6mq6y1 c_8, SkipMode_0_decqocs071 mode_3);
extern void eQdestroyQ_SX52outine0decqocs071_0_decqocs071(Routine_0_decqocs071* dest_0);
extern NB8 isInstantiation_0_symkyk35i1(string_0_sysvq0asl s_6);
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
extern LongString_0_sysvq0asl const strlit_0_I973692718279674627_emi78vuj01;
extern void extractBasename_1_symkyk35i1(string_0_sysvq0asl* s_1);
static inline NB8 isGeneric_0_decqocs071(Routine_0_decqocs071* r_0);
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33);
static inline seq_0_In6doa_arecyyj7v newSeqUninit_0_Ieodq4s1_arecyyj7v(NI32 size_28);
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37);
static inline void add_0_I34il1q_der823rwr1(seq_0_In6doa_arecyyj7v* s_12, NU32 elem_2);
extern LongString_0_sysvq0asl const strlit_0_I3021806080610957510_fiepkwzpc;
extern LongString_0_sysvq0asl const strlit_0_I6300154543333844069_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I14727864736786204059_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I18086024188298164462_buiyylk1h1;
extern Value_0_valzr1t4f vEnum_0_valzr1t4f(NI32 ord_0, NU32 ekind_0);
extern Value_0_valzr1t4f vNil_0_valzr1t4f(void);
extern LongString_0_sysvq0asl const strlit_0_I14845240230376595005_buiyylk1h1;
extern Value_0_valzr1t4f vUInt_0_valzr1t4f(NU64 x_4, NI32 bits_2);
extern Value_0_valzr1t4f vFloat_0_valzr1t4f(NF64 f_0, NI32 bits_4);
extern Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0);
extern Value_0_valzr1t4f vChar_0_valzr1t4f(NC8 c_0);
extern LongString_0_sysvq0asl const strlit_0_I6313045265747232047_fiepkwzpc;
extern LongString_0_sysvq0asl const strlit_0_I7023501325319911082_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I14656641239204103783_fiepkwzpc;
extern LongString_0_sysvq0asl const strlit_0_I17496857845421750549_nimry5ra91;
extern NI32 span_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_38);
extern TokenBuf_0_nifb6mq6y1 createTokenBuf_0_nifb6mq6y1(NI32 cap_1);
extern void addSubtree_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* result_1, Cursor_0_nifb6mq6y1 c_34);
static inline void eQwasMoved_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_2);
extern void publish_0_prorcx25w1(NU32 s_8, TokenBuf_0_nifb6mq6y1 buf_0, SemPhase_0_prorcx25w1 phase_0);
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3);
static inline NB8 ltQ_17_sysvq0asl(string_0_sysvq0asl a_53, string_0_sysvq0asl b_16);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
static inline openArray_0_Iu2js7k_intzsnzax toOpenArray_1_Ij5ojb01_intzsnzax(seq_0_Iw8xl5b1_arecyyj7v s_227);
static inline NI32 len_6_Ip8y5v7_intzsnzax(openArray_0_Iu2js7k_intzsnzax a_79);
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_10_Ik17lqr_intzsnzax(openArray_0_Iu2js7k_intzsnzax x_36, NI32 idx_54);
extern NB8 journalReplaying_0_jou8favxh1(void);
extern string_0_sysvq0asl portPath_0_jou8favxh1(string_0_sysvq0asl p_1);
extern seq_0_Ixdx2fh1_aow7lb5cq1 jServe_0_jou8favxh1(string_0_sysvq0asl kind_1, string_0_sysvq0asl key_1);
extern string_0_sysvq0asl jField_0_jou8favxh1(seq_0_Ixdx2fh1_aow7lb5cq1 f_0, NI32 i_0);
extern NI32 jInt_0_jou8favxh1(string_0_sysvq0asl s_2);
extern NB8 symlinkExists_0_osc4bsu0d1(string_0_sysvq0asl link_0);
extern NB8 fileExists_0_osc4bsu0d1(string_0_sysvq0asl filename_0);
extern NB8 dirExists_0_osc4bsu0d1(string_0_sysvq0asl dir_0);
extern NB8 journalRecording_0_jou8favxh1(void);
extern seq_0_Ixdx2fh1_aow7lb5cq1 atQ_0_Ibamkxv1_hos1fpv3m1(X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 a_6);
extern void jRecord_0_jou8favxh1(string_0_sysvq0asl kind_0, string_0_sysvq0asl key_0, seq_0_Ixdx2fh1_aow7lb5cq1 fields_0);
extern LongString_0_sysvq0asl const strlit_0_I14094691204709860525_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I7133596773365113623_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I10065104808643963232_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I14998953601798186169_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I274569611119625799_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I13880079574436425354_intzsnzax;
extern seq_0_In6doa_arecyyj7v eQdup_1_Idg8rf9_arecyyj7v(seq_0_In6doa_arecyyj7v a_17);
extern NB8 policyOn_0_iop7yt73v(void);
extern NI32 capsNeeded_0_iop7yt73v(string_0_sysvq0asl name_0);
extern NB8 policyDeniesPath_0_iop7yt73v(string_0_sysvq0asl name_2, string_0_sysvq0asl path_2, NI32* needed_1);
extern void recordViolation_1_iop7yt73v(string_0_sysvq0asl name_4, NI32 needed_3);
extern string_0_sysvq0asl policyMessage_1_iop7yt73v(string_0_sysvq0asl name_6, NI32 needed_5, string_0_sysvq0asl path_6);
extern NB8 readAuditOn_0_iop7yt73v(void);
extern LongString_0_sysvq0asl const strlit_0_I754749039837241777_iop7yt73v;
extern void recordOpen_0_iop7yt73v(string_0_sysvq0asl path_4);
extern LongString_0_sysvq0asl const strlit_0_I4398256179715674167_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I18337270522941735704_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I13706781941607385374_flaksyopx1;
extern LongString_0_sysvq0asl const strlit_0_I8010039202931761952_flaksyopx1;
extern LongString_0_sysvq0asl const strlit_0_I13696262612503621358_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I14137437451056432656_flaksyopx1;
extern LongString_0_sysvq0asl const strlit_0_I14102593084845164639_hos1fpv3m1;
extern LongString_0_sysvq0asl const strlit_0_I5348593791521339691_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I13537887754319196487_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I10175009822598077709_flaksyopx1;
extern LongString_0_sysvq0asl const strlit_0_I6624701989437400523_flaksyopx1;
extern LongString_0_sysvq0asl const strlit_0_I15031238125720431605_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I399834492833889323_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I8779604385735337050_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I4547290982746310667_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I9620132962526484305_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I16513080964259093980_flaksyopx1;
extern LongString_0_sysvq0asl const strlit_0_I15154933186756103481_flaksyopx1;
extern LongString_0_sysvq0asl const strlit_0_I100145031017624899_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I15415642409673360391_iop7yt73v;
extern LongString_0_sysvq0asl const strlit_0_I930249616028346462_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I14385440250011608213_flaksyopx1;
extern LongString_0_sysvq0asl const strlit_0_I2856626897374252538_intzsnzax;
extern NI32 hostMkdir_0_hos1fpv3m1(string_0_sysvq0asl p_0);
extern NI32 hostRmdir_0_hos1fpv3m1(string_0_sysvq0asl p_1);
extern NI32 hostUnlink_0_hos1fpv3m1(string_0_sysvq0asl p_2);
extern NI32 hostSocket_0_hos9jnsbq1(NI32 domain_1, NI32 typ_1, NI32 protocol_1);
extern NI32 hostBind_0_hos9jnsbq1(NI32 h_3, string_0_sysvq0asl sa_5);
extern NI32 hostConnect_0_hos9jnsbq1(NI32 h_4, string_0_sysvq0asl sa_6);
extern NI32 hostListen_0_hos9jnsbq1(NI32 h_5, NI32 backlog_1);
extern NI32 hostAccept_0_hos9jnsbq1(NI32 h_6, string_0_sysvq0asl* peer_0);
extern NI32 hostGetsockname_0_hos9jnsbq1(NI32 h_7, string_0_sysvq0asl* sa_8);
extern NI32 hostGetpeername_0_hos9jnsbq1(NI32 h_8, string_0_sysvq0asl* sa_9);
extern NI32 hostSetsockopt_0_hos9jnsbq1(NI32 h_9, NI32 level_2, NI32 opt_2, string_0_sysvq0asl val_2);
extern NI32 hostGetsockopt_0_hos9jnsbq1(NI32 h_10, NI32 level_3, NI32 opt_3, NI32 want_0, string_0_sysvq0asl* val_3);
extern NI32 hostSend_0_hos9jnsbq1(NI32 h_11, string_0_sysvq0asl data_0, NI32 flags_2);
extern NI32 hostRecv_0_hos9jnsbq1(NI32 h_12, NI32 want_1, NI32 flags_3, string_0_sysvq0asl* data_1);
extern NI32 hostShutdown_0_hos9jnsbq1(NI32 h_13, NI32 how_1);
extern NB8 isSockHandle_0_hos9jnsbq1(NI32 h_0);
extern NI32 hostSockFcntl_0_hos9jnsbq1(NI32 h_14, NI32 cmd_2, NI32 arg_1, NB8 hasArg_0);
extern seq_0_Ift2sne_aow7lb5cq1 atQ_0_Iy7v4si1_filqx2b6r1(X60Qt_0_IAarrayAiS32ZS1_filqx2b6r1 a_1);
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10);
extern NI32 hostPoll_0_hos9jnsbq1(seq_0_Ift2sne_aow7lb5cq1 handles_0, seq_0_Ift2sne_aow7lb5cq1 events_0, seq_0_Ift2sne_aow7lb5cq1* revents_0, NI32 timeout_1);
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_42);
extern void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
static inline Value_0_valzr1t4f vPtrLoc_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1);
extern NI32 hostHtons_0_hos9jnsbq1(NI32 x_4);
extern NI32 hostHtonl_0_hos9jnsbq1(NI32 x_5);
extern NI32 hostNtohs_0_hos9jnsbq1(NI32 x_6);
extern NI32 hostNtohl_0_hos9jnsbq1(NI32 x_7);
extern void hostClockGettime_0_hos1fpv3m1(NI32 clockId_0, NI32* sec_0, NI32* nsec_0);
extern NI32 hostGetPid_0_hos1fpv3m1(void);
extern NI32 hostSystem_0_hos1fpv3m1(string_0_sysvq0asl cmd_0);
extern string_0_sysvq0asl hostGetCwd_0_hos1fpv3m1(void);
extern NI32 hostChdir_0_hos1fpv3m1(string_0_sysvq0asl p_3);
extern string_0_sysvq0asl hostExpandFilename_0_hos5i19e11(string_0_sysvq0asl path_3);
extern NI32 hostOpenDir_0_hos1fpv3m1(string_0_sysvq0asl p_5);
extern NI32 hostCloseDir_0_hos1fpv3m1(NI32 handle_1);
extern NB8 hostNextDir_0_hos1fpv3m1(NI32 handle_0, string_0_sysvq0asl* name_1, NI32* kind_2);
extern NI32 hostFileSize_0_hos1fpv3m1(string_0_sysvq0asl p_4);
extern string_0_sysvq0asl hostPread_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_9, NI32 fd_3, NI32 off_0, NI32 n_0);
extern Value_0_valzr1t4f flAllocRegion_0_flaksyopx1(NI32 nbytes_0, NB8 zeroed_0);
extern FILE* hostFileOfFd_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_10, NI32 fd_4);
extern NI32 hostFdSize_0_hos1fpv3m1(FILE* f_0);
extern NI32 hostFdLen_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_15, NI32 fd_9);
extern void setLen_1_sysvq0asl(string_0_sysvq0asl* s_53, NI32 newLen_13);
extern void writeStr_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_14, NB8 toErr_0, string_0_sysvq0asl text_0);
extern NI32 hostWrite_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_11, NI32 fd_5, string_0_sysvq0asl data_0, NI32 n_1);
extern void writeVal_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_15, NB8 toErr_1, Value_0_valzr1t4f* v_0);
extern NB8 isHostFd_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_8, NI32 fd_2);
extern string_0_sysvq0asl dollarQ_0_valzr1t4f(Value_0_valzr1t4f* v_19);
extern string_0_sysvq0asl hostRead_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_12, NI32 fd_6, NI32 n_2);
extern X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 readLineFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_8);
static inline void plusQeQ_0_Iz7fdp7_emi78vuj01(NI32* x_18, NI32 y_1);
extern Value_0_valzr1t4f vPtrReg_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* reg_1, NI32 fo_1, NI16 eb_1, TCode_0_valzr1t4f ec_1);
extern NI32 hostOpenC_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_6, string_0_sysvq0asl path_2, string_0_sysvq0asl modeStr_0);
extern NI32 hostOpenPosix_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_5, string_0_sysvq0asl path_1, NI32 flags_1);
extern NB8 hostPipe_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_3, NI32* rfd_0, NI32* wfd_0);
extern NI32 hostSockClose_0_hos9jnsbq1(NI32 h_2);
extern NI32 hostClose_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_7, NI32 fd_1);
extern NI64 hostLseek_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_14, NI32 fd_8, NI64 offset_0, NI32 whence_0);
extern NI64 hostTell_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_16, NI32 fd_10);
extern string_0_sysvq0asl envGet_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_5, string_0_sysvq0asl key_0, NB8* found_0);
extern void envPut_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_6, string_0_sysvq0asl key_1, string_0_sysvq0asl val_0);
extern void envDel_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_7, string_0_sysvq0asl key_2);
extern void noteFailedRead_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_2, string_0_sysvq0asl path_0);
extern NB8 open_0_syn1lfpjv(FILE** f_22, string_0_sysvq0asl filename_1, FileMode_0_syn1lfpjv mode_2, NI32 bufSize_0);
extern string_0_sysvq0asl resolvedReadPath_0_natd5co251(string_0_sysvq0asl path_1);
static inline X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 default_23_Isnz07p_hos5i19e11(void);
extern NI32 readBuffer_0_syn1lfpjv(FILE* f_18, void* buffer_1, NI32 size_3);
extern void close_0_syn1lfpjv(FILE* f_16);
extern void recordRead_0_iop7yt73v(string_0_sysvq0asl path_3, string_0_sysvq0asl content_0);
extern string_0_sysvq0asl hostReadAll_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_13, NI32 fd_7);
extern string_0_sysvq0asl readAllFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_9);
extern NI32 readCharFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_10);
extern seq_0_Ixdx2fh1_aow7lb5cq1 commandLineParamsFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_11);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_43);
extern NI32 paramCountFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_12);
extern string_0_sysvq0asl paramStrFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_13, NI32 i_0);
static inline openArray_0_I2902h9_intzsnzax toOpenArray_1_Ik4sb7f_intzsnzax(seq_0_I50urnw_croph25r5 s_173);
extern Value_0_valzr1t4f copyOnAssign_0_valzr1t4f(Value_0_valzr1t4f* v_2);
extern Value_0_valzr1t4f vPtrArr_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_2, X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* a_0, X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* s_1, NI32 b_1);
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15);
extern void setLen_0_I9io9dh1_intzsnzax(seq_0_Iw8xl5b1_arecyyj7v* s_196, NI32 newLen_21);
static inline void putQ_7_I41w2p9_intzsnzax(seq_0_Iw8xl5b1_arecyyj7v* s_131, NI32 i_91, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_28);
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_aow7lb5cq1(NI32 a_27, NI32 b_4);
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355);
static inline seq_0_I50urnw_croph25r5 newSeqUninit_0_I8oufjc_croph25r5(NI32 size_10);
static inline void add_0_Itre92n_intzsnzax(seq_0_I50urnw_croph25r5* s_140, Value_0_valzr1t4f elem_31);
extern string_0_sysvq0asl cformat_0_natd5co251(string_0_sysvq0asl fmt_0, seq_0_I50urnw_croph25r5 args_1);
extern void eQdestroy_1_Inxd7ue1_croph25r5(seq_0_I50urnw_croph25r5 s_23);
extern string_0_sysvq0asl fmtBigFloat_0_flowmlewz(NF64 f_0, NI32 modeSel_0, NI32 prec_0, NC8 sep_0);
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_29);
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6);
extern NF64 parseBigFloat_0_flowmlewz(string_0_sysvq0asl s_0);
extern void flCopy_0_flaksyopx1(Value_0_valzr1t4f* dst_0, Value_0_valzr1t4f* src_0, NI32 n_0);
extern void flMove_0_flaksyopx1(Value_0_valzr1t4f* dst_1, Value_0_valzr1t4f* src_1, NI32 n_1);
extern void flZero_0_flaksyopx1(Value_0_valzr1t4f* dst_2, NI32 n_2);
extern NB8 flEqual_0_flaksyopx1(Value_0_valzr1t4f* a_6, Value_0_valzr1t4f* b_2, NI32 n_3);
extern void flFree_0_flaksyopx1(Value_0_valzr1t4f* v_18);
extern Value_0_valzr1t4f flRealloc_0_flaksyopx1(Value_0_valzr1t4f* v_19, NI32 newBytes_0);
extern NB8 perInterpPolicies_0_iop7yt73v(void);
extern X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* useIoPolicy_0_iop7yt73v(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* p_0);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f(Cell_Obj_0_valzr1t4f* dest_0);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(FlatRegion_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(ObjBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(ArrBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(SeqBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(IoPolicy_Obj_0_iop7yt73v* dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_decqocs071(void);
extern void X60Qini_0_modzy18mg1(void);
extern void X60Qini_0_buiyylk1h1(void);
extern void X60Qini_0_modjbswg91(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_natd5co251(void);
extern void X60Qini_0_flowmlewz(void);
extern void X60Qini_0_flaksyopx1(void);
extern void X60Qini_0_hos5i19e11(void);
extern void X60Qini_0_hos1fpv3m1(void);
extern void X60Qini_0_hos9jnsbq1(void);
extern void X60Qini_0_iop7yt73v(void);
extern void X60Qini_0_jou8favxh1(void);
extern void X60Qini_0_mat7cnfv21(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_envto7w6l1(void);
extern string_0_sysvq0asl getEnv_0_envto7w6l1(string_0_sysvq0asl key_1, string_0_sysvq0asl default_0);
static inline NI32 capInBytes_0_Iih34tr1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_87);
extern NB8 resize_0_If3pogj_flaksyopx1(seq_0_Iw8xl5b1_arecyyj7v* dest_4, NI32 addedElements_4);
extern void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern void dealloc_1_sysvq0asl(void* p_20);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline NI32 memSizeInBytes_0_Ixcobep_arecyyj7v(NI32 size_25);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
extern void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0);
extern void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
extern void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
extern LongString_0_sysvq0asl const strlit_0_I11901799661097360525_modzy18mg1;
extern LongString_0_sysvq0asl const strlit_0_I5065733472155119234_modzy18mg1;
static inline string_0_sysvq0asl slashQ_0_ospaexnw61(string_0_sysvq0asl head_1, string_0_sysvq0asl tail_2);
extern X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7 readBytesRelay_0_vfsc9jn7;
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NI32 memSizeInBytes_0_Ih4q01h_aow7lb5cq1(NI32 size_22);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
static inline NI32 capInBytes_0_In1m6ni_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_70);
extern NB8 resize_0_I2yw78g1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* dest_10, NI32 addedElements_10);
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14);
static inline NB8 rawTagIsNimonySym_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_5);
static inline NimonyOther_0_nimry5ra91 substructureKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_6);
static inline NI32 memSizeInBytes_0_Ivqzo5x1_arecyyj7v(NI32 size_29);
static inline NI32 capInBytes_0_Iev6wua1_arecyyj7v(seq_0_In6doa_arecyyj7v s_89);
extern NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_arecyyj7v* dest_8, NI32 addedElements_8);
extern NI32 cmp_1_sysvq0asl(string_0_sysvq0asl a_51, string_0_sysvq0asl b_14);
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** rawData_0_Iqcdbhc_intzsnzax(seq_0_Iw8xl5b1_arecyyj7v s_333);
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20);
extern X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0);
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67);
static inline Value_0_valzr1t4f* rawData_0_Ih1dm1f1_intzsnzax(seq_0_I50urnw_croph25r5 s_296);
extern LongString_0_sysvq0asl const strlit_0_I11201514831099767300_sysvq0asl;
extern void prepareMutation_0_sysvq0asl(string_0_sysvq0asl* s_46);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
extern void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_intzsnzax(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_intzsnzax(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
static inline NI32 memSizeInBytes_0_Itmy7ww1_croph25r5(NI32 size_11);
static inline NI32 capInBytes_0_Ihvsegh1_croph25r5(seq_0_I50urnw_croph25r5 s_30);
extern NB8 resize_0_Iz8tg361_intzsnzax(seq_0_I50urnw_croph25r5* dest_23, NI32 addedElements_23);
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
extern LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l;
extern string_0_sysvq0asl joinPath_0_ospaexnw61(string_0_sysvq0asl head_0, string_0_sysvq0asl tail_1);
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16);
static inline NimonyOther_0_nimry5ra91 substructureKind_0_nim30udrv(PackedToken_0_nifh7u8pu1 c_5);
extern NU32 const ErrT_0_nifh7u8pu1;
static inline NB8 rawTagIsNimonyOther_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_3);
LongString_0_sysvq0asl const strlit_0_I10545009242662524993_runot4689 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_TRACE_UNPORTED"}
;
LongString_0_sysvq0asl const strlit_0_I3658334576718801857_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fflush"}
;
LongString_0_sysvq0asl const strlit_0_I83481134452578751_runot4689 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_cond_signal"}
;
LongString_0_sysvq0asl const strlit_0_I10552516363120284090_runot4689 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_cond_broadcast"}
;
LongString_0_sysvq0asl const strlit_0_I8474686393983226071_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "iconv_open"}
;
LongString_0_sysvq0asl const strlit_0_I4162784111547495237_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "iconv_close"}
;
LongString_0_sysvq0asl const strlit_0_I4192063856828764885_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sysconf"}
;
LongString_0_sysvq0asl const strlit_0_I11161314014774899755_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "myFunc"}
;
LongString_0_sysvq0asl const strlit_0_I14218070088974767232_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "myFunc2"}
;
LongString_0_sysvq0asl const strlit_0_I10647032785286562467_runot4689 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_UNPORTED\011"}
;
LongString_0_sysvq0asl const strlit_0_I17855937645147449103_runot4689 = {
  .fullLen_0 = 52, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: cannot store into an element of a nil value ("}
;
LongString_0_sysvq0asl const strlit_0_I680476680836312648_runot4689 = {
  .fullLen_0 = 76, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") \342\200\224 the container does not exist, so the write would be silently dropped. "}
;
LongString_0_sysvq0asl const strlit_0_I13892765374060201417_runot4689 = {
  .fullLen_0 = 73, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "If this is a field of a raw `alloc`\'d block, the field\'s type is one the "}
;
LongString_0_sysvq0asl const strlit_0_I8909888703136744024_runot4689 = {
  .fullLen_0 = 54, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "field seed does not materialise (seq/string/ptr/ref).\012"}
;
LongString_0_sysvq0asl const strlit_0_I13575662182318269178_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "toOpenArray"}
;
LongString_0_sysvq0asl const strlit_0_I8091224095641214909_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "modify"}
;
LongString_0_sysvq0asl const strlit_0_I3482038733795591457_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: \'"}
;
LongString_0_sysvq0asl const strlit_0_I13430512253800851145_runot4689 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' on a nil container (runtime:"}
;
LongString_0_sysvq0asl const strlit_0_I11551122325864634146_runot4689 = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") \342\200\224 there is nothing to "}
;
LongString_0_sysvq0asl const strlit_0_I12900702437801693322_runot4689 = {
  .fullLen_0 = 68, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", and answering anyway is a wrong result that presents as a working "}
;
LongString_0_sysvq0asl const strlit_0_I17333570120953067106_runot4689 = {
  .fullLen_0 = 71, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "program. If this is a field of a raw `alloc`\'d block, the field\'s type "}
;
LongString_0_sysvq0asl const strlit_0_I4361863382066363811_runot4689 = {
  .fullLen_0 = 65, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "is one the field seed does not materialise (seq/string/ptr/ref).\012"}
;
LongString_0_sysvq0asl const strlit_0_I7772827330262704879_runot4689 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' with a nil memory operand (runtime:"}
;
LongString_0_sysvq0asl const strlit_0_I18182598141676208927_runot4689 = {
  .fullLen_0 = 65, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") \342\200\224 there is no region to read or write, so the bytes would go "}
;
LongString_0_sysvq0asl const strlit_0_I8202177012730565345_runot4689 = {
  .fullLen_0 = 69, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nowhere and the program would continue as if they had landed. Native "}
;
LongString_0_sysvq0asl const strlit_0_I3391095418943119447_runot4689 = {
  .fullLen_0 = 34, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dereferences a null pointer here.\012"}
;
LongString_0_sysvq0asl const strlit_0_I14948233031946914775_runot4689 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nativeCall:arg-shape"}
;
LongString_0_sysvq0asl const strlit_0_I696346342095441754_runot4689 = {
  .fullLen_0 = 41, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: unported argument shape reached: \'"}
;
LongString_0_sysvq0asl const strlit_0_I16229626376861876445_runot4689 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ")\' \342\200\224 the native for \'"}
;
LongString_0_sysvq0asl const strlit_0_I16330257589235283131_runot4689 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' has no branch for "}
;
LongString_0_sysvq0asl const strlit_0_I6564517153549527586_runot4689 = {
  .fullLen_0 = 66, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "these operand kinds and would have silently returned nil. Add the "}
;
LongString_0_sysvq0asl const strlit_0_I9873199351554270220_runot4689 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "branch, or drop \'"}
;
LongString_0_sysvq0asl const strlit_0_I7647809558014641970_runot4689 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' from isNativeBase so the library body "}
;
LongString_0_sysvq0asl const strlit_0_I193201366648006738_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "runs.\012"}
;
LongString_0_sysvq0asl const strlit_0_I1169319743787033125_runot4689 = {
  .fullLen_0 = 36, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: unported primitive reached: \'"}
;
LongString_0_sysvq0asl const strlit_0_I15763493685976154898_runot4689 = {
  .fullLen_0 = 52, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") \342\200\224 no native implementation; would have silently "}
;
LongString_0_sysvq0asl const strlit_0_I8002392516255080284_runot4689 = {
  .fullLen_0 = 70, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "returned nil. Add a native, or list it in UnportedNoops if its result "}
;
LongString_0_sysvq0asl const strlit_0_I11178650102999243047_runot4689 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "is genuinely discarded.\012"}
;
LongString_0_sysvq0asl const strlit_0_I16052506731142050930_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "S_ISDIR"}
;
LongString_0_sysvq0asl const strlit_0_I17683665254279387272_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "S_ISREG"}
;
LongString_0_sysvq0asl const strlit_0_I7311313444739886319_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "S_ISLNK"}
;
LongString_0_sysvq0asl const strlit_0_I17823405900913585998_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "beginStore"}
;
LongString_0_sysvq0asl const strlit_0_I7523013755933230041_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "delete"}
;
LongString_0_sysvq0asl const strlit_0_I12032775272325669946_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "echoBinSafe"}
;
LongString_0_sysvq0asl const strlit_0_I4165263228779136726_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "firstSetBit"}
;
LongString_0_sysvq0asl const strlit_0_I17711552707752383867_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hash"}
;
LongString_0_sysvq0asl const strlit_0_I13171408700689225719_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readByte"}
;
LongString_0_sysvq0asl const strlit_0_I8996502465535440862_runot4689 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "leadingZeroBits"}
;
LongString_0_sysvq0asl const strlit_0_I17462820957681339184_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "newSeqOfCap"}
;
LongString_0_sysvq0asl const strlit_0_I16799243069367891670_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "newString"}
;
LongString_0_sysvq0asl const strlit_0_I11206267958496974357_runot4689 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "newStringOfCap"}
;
LongString_0_sysvq0asl const strlit_0_I12927204854279428474_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "shrink"}
;
LongString_0_sysvq0asl const strlit_0_I2442484592079803371_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "parityBits"}
;
LongString_0_sysvq0asl const strlit_0_I590530705459077169_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "setLen"}
;
LongString_0_sysvq0asl const strlit_0_I12973856256439326227_runot4689 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "borrowCStringUnsafe"}
;
LongString_0_sysvq0asl const strlit_0_I4889788401779984975_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "countSetBits"}
;
LongString_0_sysvq0asl const strlit_0_I8891710430887467064_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "endStore"}
;
LongString_0_sysvq0asl const strlit_0_I16314744827495621298_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "endsWith"}
;
LongString_0_sysvq0asl const strlit_0_I15089905067781246666_runot4689 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "formatBiggestFloat"}
;
LongString_0_sysvq0asl const strlit_0_I130460565633405389_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "formatFloat"}
;
LongString_0_sysvq0asl const strlit_0_I6872392552133396222_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "insert"}
;
LongString_0_sysvq0asl const strlit_0_I4459857122359951064_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fromCString"}
;
LongString_0_sysvq0asl const strlit_0_I5078203883954553591_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "popcount"}
;
LongString_0_sysvq0asl const strlit_0_I3590215048999296526_runot4689 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rotateLeftBits"}
;
LongString_0_sysvq0asl const strlit_0_I12537729981146465730_runot4689 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rotateRightBits"}
;
LongString_0_sysvq0asl const strlit_0_I11323202368322527013_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "toCString"}
;
LongString_0_sysvq0asl const strlit_0_I12206775736441983472_runot4689 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "trailingZeroBits"}
;
LongString_0_sysvq0asl const strlit_0_I518833209856422221_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "startsWith"}
;
LongString_0_sysvq0asl const strlit_0_I10580268758365513846_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "substr"}
;
LongString_0_sysvq0asl const strlit_0_I18218698628038865650_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "peekData"}
;
LongString_0_sysvq0asl const strlit_0_I17725400170363418176_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readData"}
;
LongString_0_sysvq0asl const strlit_0_I14889114411614909829_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "writeData"}
;
LongString_0_sysvq0asl const strlit_0_I17978188014264979010_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fpclassify"}
;
LongString_0_sysvq0asl const strlit_0_I6629672319202990767_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_frexp"}
;
LongString_0_sysvq0asl const strlit_0_I17733383591063213526_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_getenv"}
;
LongString_0_sysvq0asl const strlit_0_I16869611209385436378_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_isnan"}
;
LongString_0_sysvq0asl const strlit_0_I2756518269131387936_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_ldexp"}
;
LongString_0_sysvq0asl const strlit_0_I9007462764285996300_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ceil"}
;
LongString_0_sysvq0asl const strlit_0_I11575531321635900188_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gamma"}
;
LongString_0_sysvq0asl const strlit_0_I5077193025928916746_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_printf"}
;
LongString_0_sysvq0asl const strlit_0_I14098594833283830517_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_putenv"}
;
LongString_0_sysvq0asl const strlit_0_I8970872227344634284_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cbrt"}
;
LongString_0_sysvq0asl const strlit_0_I3004431710427040048_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_signbit"}
;
LongString_0_sysvq0asl const strlit_0_I12271947912804281422_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_setenv"}
;
LongString_0_sysvq0asl const strlit_0_I10744707227501835447_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getenv"}
;
LongString_0_sysvq0asl const strlit_0_I261076703518422676_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_unsetenv"}
;
LongString_0_sysvq0asl const strlit_0_I13770135642222982414_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "floor"}
;
LongString_0_sysvq0asl const strlit_0_I15469864145960116068_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "clock_gettime"}
;
LongString_0_sysvq0asl const strlit_0_I9772346370466888830_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "copySign"}
;
LongString_0_sysvq0asl const strlit_0_I2902005617748064841_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fmod"}
;
LongString_0_sysvq0asl const strlit_0_I1951864687996922622_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cosh"}
;
LongString_0_sysvq0asl const strlit_0_I5698419940050250200_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arcsin"}
;
LongString_0_sysvq0asl const strlit_0_I1702282805285054051_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arccos"}
;
LongString_0_sysvq0asl const strlit_0_I1534576491481833817_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arctan"}
;
LongString_0_sysvq0asl const strlit_0_I891118288292861849_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arctan2"}
;
LongString_0_sysvq0asl const strlit_0_I2254028527881297604_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hypot"}
;
LongString_0_sysvq0asl const strlit_0_I6858632851445378176_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fprintf"}
;
LongString_0_sysvq0asl const strlit_0_I17537008619994765435_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "lgamma"}
;
LongString_0_sysvq0asl const strlit_0_I1291718626454456793_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mmap"}
;
LongString_0_sysvq0asl const strlit_0_I4457427298056883912_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "lseek"}
;
LongString_0_sysvq0asl const strlit_0_I10762679581578789876_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "log10"}
;
LongString_0_sysvq0asl const strlit_0_I16777186388511288065_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "log2"}
;
LongString_0_sysvq0asl const strlit_0_I11647825660565427273_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "munmap"}
;
LongString_0_sysvq0asl const strlit_0_I2227768086840020110_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pipe"}
;
LongString_0_sysvq0asl const strlit_0_I11258486380889900750_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "printf"}
;
LongString_0_sysvq0asl const strlit_0_I10681429218388745297_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "putenv"}
;
LongString_0_sysvq0asl const strlit_0_I11492332034473653383_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "setenv"}
;
LongString_0_sysvq0asl const strlit_0_I3069983570459151989_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tanh"}
;
LongString_0_sysvq0asl const strlit_0_I11806394720139207185_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sinh"}
;
LongString_0_sysvq0asl const strlit_0_I2622871807570587851_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sqrt"}
;
LongString_0_sysvq0asl const strlit_0_I16919077516905105311_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "round"}
;
LongString_0_sysvq0asl const strlit_0_I10988075821851534954_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "strlen"}
;
LongString_0_sysvq0asl const strlit_0_I15639938243715246193_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unsetenv"}
;
LongString_0_sysvq0asl const strlit_0_I10246663023455874512_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "trunc"}
;
LongString_0_sysvq0asl const strlit_0_I17809097366158705854_runot4689 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "BackwardsIndex"}
;
LongString_0_sysvq0asl const strlit_0_I10672061222185195832_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gEnv"}
;
LongString_0_sysvq0asl const strlit_0_I5200583122280938215_runot4689 = {
  .fullLen_0 = 50, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: write to a natively-bound importc global: \'"}
;
LongString_0_sysvq0asl const strlit_0_I9043385391952070731_runot4689 = {
  .fullLen_0 = 67, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' \342\200\224 its value was read once out of the generated accessor shim\'s "}
;
LongString_0_sysvq0asl const strlit_0_I7864832558404820058_runot4689 = {
  .fullLen_0 = 72, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "translation unit, so assigning here would leave the interpreter and the "}
;
LongString_0_sysvq0asl const strlit_0_I7045456837871243884_runot4689 = {
  .fullLen_0 = 68, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "C object disagreeing about one C symbol. The importc-global rung is "}
;
LongString_0_sysvq0asl const strlit_0_I11592933535804058560_runot4689 = {
  .fullLen_0 = 72, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "READ-ONLY (src/aowli/importcglob.nim); a write-back route would have to "}
;
LongString_0_sysvq0asl const strlit_0_I11068299943761976496_runot4689 = {
  .fullLen_0 = 42, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "publish through the same accessor module.\012"}
;
LongString_0_sysvq0asl const strlit_0_I8044815621933303456_runot4689 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_IMPORTC_LAX"}
;
LongString_0_sysvq0asl const strlit_0_I8126255002988789275_runot4689 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: unbound importc global reached: \'"}
;
LongString_0_sysvq0asl const strlit_0_I15900777102133637650_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' (nim name \'"}
;
LongString_0_sysvq0asl const strlit_0_I13719311418082057446_runot4689 = {
  .fullLen_0 = 70, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\') \342\200\224 no C symbol is linked into the interpreter, so this read would "}
;
LongString_0_sysvq0asl const strlit_0_I14654729971600803534_runot4689 = {
  .fullLen_0 = 65, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "have silently yielded zero. Seed it (runtime.importcGlobalSeed / "}
;
LongString_0_sysvq0asl const strlit_0_I10797867291169351481_runot4689 = {
  .fullLen_0 = 75, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "libcConstVal), cross it natively, or list it in isAllowedUnboundImportc if "}
;
LongString_0_sysvq0asl const strlit_0_I15831543276806770207_runot4689 = {
  .fullLen_0 = 39, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "its value is genuinely never observed.\012"}
;
LongString_0_sysvq0asl const strlit_0_I6086898244938667450_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sin_family"}
;
LongString_0_sysvq0asl const strlit_0_I1630993779792733486_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sin_port"}
;
LongString_0_sysvq0asl const strlit_0_I9145615580426605709_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sin_addr"}
;
LongString_0_sysvq0asl const strlit_0_I4274381415279064279_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "s_addr"}
;
LongString_0_sysvq0asl const strlit_0_I13270768669503881230_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sin6_family"}
;
LongString_0_sysvq0asl const strlit_0_I6128741239358766604_runot4689 = {
  .fullLen_0 = 36, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: IPv6 socket address reached \'"}
;
LongString_0_sysvq0asl const strlit_0_I5854685259221891605_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' \342\200\224 the "}
;
LongString_0_sysvq0asl const strlit_0_I4584856981448071874_runot4689 = {
  .fullLen_0 = 74, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "interpreted `struct sockaddr_in6` record declares only its scalar fields, "}
;
LongString_0_sysvq0asl const strlit_0_I18228840873349803156_runot4689 = {
  .fullLen_0 = 71, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "so the 16 address bytes at offset 8 are not visible at this seam and a "}
;
LongString_0_sysvq0asl const strlit_0_I14411341024074226062_runot4689 = {
  .fullLen_0 = 73, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "reconstruction would silently use the wildcard address (\'::\') instead of "}
;
LongString_0_sysvq0asl const strlit_0_I7782505738835258833_runot4689 = {
  .fullLen_0 = 72, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "the one asked for. IPv4 is supported; v6 needs the sockaddr to cross as "}
;
LongString_0_sysvq0asl const strlit_0_I8261414620968001461_runot4689 = {
  .fullLen_0 = 70, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "RAW BYTES (as accept/getsockname already do) or the getaddrinfo rung.\012"}
;
LongString_0_sysvq0asl const strlit_0_I16850029409187227929_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "_fseeki64"}
;
LongString_0_sysvq0asl const strlit_0_I15896652137124894441_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "_ftelli64"}
;
LongString_0_sysvq0asl const strlit_0_I12734185539917726554_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fgetc"}
;
LongString_0_sysvq0asl const strlit_0_I13338309813228285486_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ceilf"}
;
LongString_0_sysvq0asl const strlit_0_I3331562609906234561_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "deallocFixed"}
;
LongString_0_sysvq0asl const strlit_0_I13165182437724203393_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "lgammaf"}
;
LongString_0_sysvq0asl const strlit_0_I13332988580619513941_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "llabs"}
;
LongString_0_sysvq0asl const strlit_0_I4315280164913964871_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fmodf"}
;
LongString_0_sysvq0asl const strlit_0_I13587882791461032424_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tgamma"}
;
LongString_0_sysvq0asl const strlit_0_I528020226223869869_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tgammaf"}
;
LongString_0_sysvq0asl const strlit_0_I2460192712881505125_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "paramCount"}
;
LongString_0_sysvq0asl const strlit_0_I6254854690921100046_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "paramStr"}
;
LongString_0_sysvq0asl const strlit_0_I17762169876133351355_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "signbit"}
;
LongString_0_sysvq0asl const strlit_0_I4037024720053716733_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sinf"}
;
LongString_0_sysvq0asl const strlit_0_I2842093187128652953_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tanf"}
;
LongString_0_sysvq0asl const strlit_0_I3542826059153545742_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sinhf"}
;
LongString_0_sysvq0asl const strlit_0_I13572268722964477183_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tanhf"}
;
LongString_0_sysvq0asl const strlit_0_I6360057863985801792_runot4689 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_add_fetch"}
;
LongString_0_sysvq0asl const strlit_0_I7416523361519930235_runot4689 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_clear"}
;
LongString_0_sysvq0asl const strlit_0_I8017305591929431070_runot4689 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_exchange_n"}
;
LongString_0_sysvq0asl const strlit_0_I6911048140413447969_runot4689 = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_compare_exchange_n"}
;
LongString_0_sysvq0asl const strlit_0_I14794290808105000385_runot4689 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_fetch_add"}
;
LongString_0_sysvq0asl const strlit_0_I2721612651281431750_runot4689 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_fetch_sub"}
;
LongString_0_sysvq0asl const strlit_0_I15330224518915338745_runot4689 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_load_n"}
;
LongString_0_sysvq0asl const strlit_0_I6562023223248407785_runot4689 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_store_n"}
;
LongString_0_sysvq0asl const strlit_0_I6014013695438108326_runot4689 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_signal_fence"}
;
LongString_0_sysvq0asl const strlit_0_I13618388896102550277_runot4689 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_sub_fetch"}
;
LongString_0_sysvq0asl const strlit_0_I9961550407930830585_runot4689 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_test_and_set"}
;
LongString_0_sysvq0asl const strlit_0_I4918636105606565444_runot4689 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__atomic_thread_fence"}
;
LongString_0_sysvq0asl const strlit_0_I5557876643816385366_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fread"}
;
LongString_0_sysvq0asl const strlit_0_I1425867270648381196_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fputc"}
;
LongString_0_sysvq0asl const strlit_0_I267265874032566585_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fseek"}
;
LongString_0_sysvq0asl const strlit_0_I9020750254248281358_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_ftell"}
;
LongString_0_sysvq0asl const strlit_0_I15442353845339373309_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fabs"}
;
LongString_0_sysvq0asl const strlit_0_I11888325900615031473_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fabsf"}
;
LongString_0_sysvq0asl const strlit_0_I1015435270754762846_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "labs"}
;
LongString_0_sysvq0asl const strlit_0_I10587700194469857770_runot4689 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__errno_location"}
;
LongString_0_sysvq0asl const strlit_0_I2935065715245494111_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__error"}
;
LongString_0_sysvq0asl const strlit_0_I829494218257581341_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fwrite"}
;
LongString_0_sysvq0asl const strlit_0_I17773428354037550576_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_putenv_s"}
;
LongString_0_sysvq0asl const strlit_0_I11458864696903921954_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_strtod"}
;
LongString_0_sysvq0asl const strlit_0_I18389659094084831927_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cbrtf"}
;
LongString_0_sysvq0asl const strlit_0_I10412889024785430365_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "acosf"}
;
LongString_0_sysvq0asl const strlit_0_I5124821916304759024_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "acosh"}
;
LongString_0_sysvq0asl const strlit_0_I8283530786494002228_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "acoshf"}
;
LongString_0_sysvq0asl const strlit_0_I916283243853797056_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fcntl"}
;
LongString_0_sysvq0asl const strlit_0_I15988237883286942751_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getpeername"}
;
LongString_0_sysvq0asl const strlit_0_I3797353385083767601_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fgetc"}
;
LongString_0_sysvq0asl const strlit_0_I7911372692567978064_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "shutdown"}
;
LongString_0_sysvq0asl const strlit_0_I2255282174144548766_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "acos"}
;
LongString_0_sysvq0asl const strlit_0_I3644943614415463836_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fclose"}
;
LongString_0_sysvq0asl const strlit_0_I4103505614328324962_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "floorf"}
;
LongString_0_sysvq0asl const strlit_0_I15485922392778096779_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getsockname"}
;
LongString_0_sysvq0asl const strlit_0_I10535682057815138895_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getsockopt"}
;
LongString_0_sysvq0asl const strlit_0_I5781888230858571977_runot4689 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "commandLineParams"}
;
LongString_0_sysvq0asl const strlit_0_I16778293019659317075_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "coshf"}
;
LongString_0_sysvq0asl const strlit_0_I14583999013692158065_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "atan2"}
;
LongString_0_sysvq0asl const strlit_0_I7452096862806559312_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "atan2f"}
;
LongString_0_sysvq0asl const strlit_0_I18319326863888772702_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "asinf"}
;
LongString_0_sysvq0asl const strlit_0_I5382018615177490518_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "atanf"}
;
LongString_0_sysvq0asl const strlit_0_I15785994502496746995_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "asinh"}
;
LongString_0_sysvq0asl const strlit_0_I17120658844982687581_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "asinhf"}
;
LongString_0_sysvq0asl const strlit_0_I16113657126360930300_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "atanh"}
;
LongString_0_sysvq0asl const strlit_0_I11603069084661078003_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "atanhf"}
;
LongString_0_sysvq0asl const strlit_0_I12956148032481319733_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fpclassify"}
;
LongString_0_sysvq0asl const strlit_0_I11259678733945033750_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fread"}
;
LongString_0_sysvq0asl const strlit_0_I1809801196744581258_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "erfcf"}
;
LongString_0_sysvq0asl const strlit_0_I13358815423116982192_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fseek"}
;
LongString_0_sysvq0asl const strlit_0_I16765359973108783593_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fseeko"}
;
LongString_0_sysvq0asl const strlit_0_I17605982152144906666_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fputc"}
;
LongString_0_sysvq0asl const strlit_0_I14090416911907227580_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "log10f"}
;
LongString_0_sysvq0asl const strlit_0_I3257461749309365855_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "log2f"}
;
LongString_0_sysvq0asl const strlit_0_I17586706449769989679_runot4689 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_attr_init"}
;
LongString_0_sysvq0asl const strlit_0_I12455491439291898808_runot4689 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_attr_destroy"}
;
LongString_0_sysvq0asl const strlit_0_I7879418900251688251_runot4689 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_attr_setstacksize"}
;
LongString_0_sysvq0asl const strlit_0_I13575103462706389231_runot4689 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_cond_init"}
;
LongString_0_sysvq0asl const strlit_0_I15101805001566300991_runot4689 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_cond_destroy"}
;
LongString_0_sysvq0asl const strlit_0_I16307165221440279626_runot4689 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_mutex_init"}
;
LongString_0_sysvq0asl const strlit_0_I7563958664671285564_runot4689 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_mutex_destroy"}
;
LongString_0_sysvq0asl const strlit_0_I5520204047587305294_runot4689 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_mutex_lock"}
;
LongString_0_sysvq0asl const strlit_0_I2704167984537518126_runot4689 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_mutex_trylock"}
;
LongString_0_sysvq0asl const strlit_0_I12090117985479266910_runot4689 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_mutex_unlock"}
;
LongString_0_sysvq0asl const strlit_0_I7144656948613361609_runot4689 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_mutexattr_init"}
;
LongString_0_sysvq0asl const strlit_0_I15900191554327605035_runot4689 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_mutexattr_destroy"}
;
LongString_0_sysvq0asl const strlit_0_I15453311318628242112_runot4689 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_mutexattr_settype"}
;
LongString_0_sysvq0asl const strlit_0_I5251620621223879244_runot4689 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_rwlock_init"}
;
LongString_0_sysvq0asl const strlit_0_I10103062530166186202_runot4689 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_rwlock_destroy"}
;
LongString_0_sysvq0asl const strlit_0_I8777584587013623138_runot4689 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_rwlock_rdlock"}
;
LongString_0_sysvq0asl const strlit_0_I9358368861162995182_runot4689 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_rwlock_tryrdlock"}
;
LongString_0_sysvq0asl const strlit_0_I3165618862315308536_runot4689 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_rwlock_trywrlock"}
;
LongString_0_sysvq0asl const strlit_0_I3058267948028936567_runot4689 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_rwlock_wrlock"}
;
LongString_0_sysvq0asl const strlit_0_I2713340543544631928_runot4689 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pthread_rwlock_unlock"}
;
LongString_0_sysvq0asl const strlit_0_I11472341555409824841_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "roundf"}
;
LongString_0_sysvq0asl const strlit_0_I16230913145226539634_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sqrtf"}
;
LongString_0_sysvq0asl const strlit_0_I17395397086815796959_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "truncf"}
;
LongString_0_sysvq0asl const strlit_0_I4513720326185655066_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "copysign"}
;
LongString_0_sysvq0asl const strlit_0_I12200441697993125318_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "copysignf"}
;
LongString_0_sysvq0asl const strlit_0_I6681190863369851530_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cosf"}
;
LongString_0_sysvq0asl const strlit_0_I17767840746738081133_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "erfc"}
;
LongString_0_sysvq0asl const strlit_0_I10901154011981123785_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "erff"}
;
LongString_0_sysvq0asl const strlit_0_I10698485606268199303_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "asin"}
;
LongString_0_sysvq0asl const strlit_0_I11456619178692440789_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "atan"}
;
LongString_0_sysvq0asl const strlit_0_I10712772139775900001_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "expf"}
;
LongString_0_sysvq0asl const strlit_0_I10389925338050183997_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ftell"}
;
LongString_0_sysvq0asl const strlit_0_I13386057973257435165_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ftello"}
;
LongString_0_sysvq0asl const strlit_0_I14144589816323362037_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "htons"}
;
LongString_0_sysvq0asl const strlit_0_I14650401024631548577_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "htonl"}
;
LongString_0_sysvq0asl const strlit_0_I8125595602251731014_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hypotf"}
;
LongString_0_sysvq0asl const strlit_0_I5383957453197838038_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "logf"}
;
LongString_0_sysvq0asl const strlit_0_I8961661824765813682_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "poll"}
;
LongString_0_sysvq0asl const strlit_0_I3083679647149312804_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "powf"}
;
LongString_0_sysvq0asl const strlit_0_I18238894324927972679_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "isnan"}
;
LongString_0_sysvq0asl const strlit_0_I17395640001380130172_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ntohs"}
;
LongString_0_sysvq0asl const strlit_0_I10214058258048950411_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ntohl"}
;
LongString_0_sysvq0asl const strlit_0_I11298461363290321067_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "strtod"}
;
LongString_0_sysvq0asl const strlit_0_I15643014340064390533_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "events"}
;
LongString_0_sysvq0asl const strlit_0_I8105615898909808576_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "revents"}
;
LongString_0_sysvq0asl const strlit_0_I8094440439369104877_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "poll(nfds="}
;
LongString_0_sysvq0asl const strlit_0_I3550780962399020617_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nativeCall"}
;
LongString_0_sysvq0asl const strlit_0_I1549329809582954555_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tv_sec"}
;
LongString_0_sysvq0asl const strlit_0_I7192365939506907704_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tv_nsec"}
;
LongString_0_sysvq0asl const strlit_0_I16579930605568015458_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pimpl"}
;
LongString_0_sysvq0asl const strlit_0_I18311672068392283896_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "kind"}
;
LongString_0_sysvq0asl const strlit_0_I2500417439306294520_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "path"}
;
LongString_0_sysvq0asl const strlit_0_I6805333918920290403_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "st_mode"}
;
LongString_0_sysvq0asl const strlit_0_I11133855009892133944_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "st_size"}
;
LongString_0_sysvq0asl const strlit_0_I15923132267043663999_runot4689 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli writeFile: cannot open \'"}
;
LongString_0_sysvq0asl const strlit_0_I13890055370861586915_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readfile"}
;
LongString_0_sysvq0asl const strlit_0_I1043492540097414730_runot4689 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli readFile: cannot open \'"}
;
LongString_0_sysvq0asl const strlit_0_I16141550644421620305_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "runtime:[]="}
;
LongString_0_sysvq0asl const strlit_0_I8660272623971252417_runot4689 = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nativeCall:allowlisted-noop"}
;
LongString_0_sysvq0asl const strlit_0_I13521228324183726981_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EADDRNOTAVAIL"}
;
LongString_0_sysvq0asl const strlit_0_I13213607251399513994_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ECANCELED"}
;
LongString_0_sysvq0asl const strlit_0_I10078620631909322514_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ECONNRESET"}
;
LongString_0_sysvq0asl const strlit_0_I10443767956889305667_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AF_UNSPEC"}
;
LongString_0_sysvq0asl const strlit_0_I4380987711265286239_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "FD_CLOEXEC"}
;
LongString_0_sysvq0asl const strlit_0_I7771350034674712515_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAI_BADFLAGS"}
;
LongString_0_sysvq0asl const strlit_0_I12050149256530257920_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAI_AGAIN"}
;
LongString_0_sysvq0asl const strlit_0_I12873808100213791010_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAI_FAMILY"}
;
LongString_0_sysvq0asl const strlit_0_I1202898303368581925_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAI_NONAME"}
;
LongString_0_sysvq0asl const strlit_0_I16862582215469788300_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAI_SERVICE"}
;
LongString_0_sysvq0asl const strlit_0_I1773389152722915160_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAI_SYSTEM"}
;
LongString_0_sysvq0asl const strlit_0_I15484450220121022056_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AI_CANONNAME"}
;
LongString_0_sysvq0asl const strlit_0_I17160939106385923572_runot4689 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AI_NUMERICHOST"}
;
LongString_0_sysvq0asl const strlit_0_I9655121365460891732_runot4689 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AI_NUMERICSERV"}
;
LongString_0_sysvq0asl const strlit_0_I10749741470294450029_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EINPROGRESS"}
;
LongString_0_sysvq0asl const strlit_0_I204748838534382851_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EHOSTUNREACH"}
;
LongString_0_sysvq0asl const strlit_0_I626075554773012147_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENAMETOOLONG"}
;
LongString_0_sysvq0asl const strlit_0_I3590701547663877830_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENETUNREACH"}
;
LongString_0_sysvq0asl const strlit_0_I7364463776597098673_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EOWNERDEAD"}
;
LongString_0_sysvq0asl const strlit_0_I7912715734078800859_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLL_CTL_ADD"}
;
LongString_0_sysvq0asl const strlit_0_I4198327292561152411_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLL_CTL_DEL"}
;
LongString_0_sysvq0asl const strlit_0_I1327145675017360827_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLL_CTL_MOD"}
;
LongString_0_sysvq0asl const strlit_0_I3700114206701234657_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAFNOSUPPORT"}
;
LongString_0_sysvq0asl const strlit_0_I13198638834565665639_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EADDRINUSE"}
;
LongString_0_sysvq0asl const strlit_0_I11261879291153827405_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AI_ADDRCONFIG"}
;
LongString_0_sysvq0asl const strlit_0_I15346413526716859885_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ECONNABORTED"}
;
LongString_0_sysvq0asl const strlit_0_I9347374490907984536_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ECONNREFUSED"}
;
LongString_0_sysvq0asl const strlit_0_I15677921475206071770_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EOVERFLOW"}
;
LongString_0_sysvq0asl const strlit_0_I11457930569918428624_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ETIMEDOUT"}
;
LongString_0_sysvq0asl const strlit_0_I16616648354288951258_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLLONESHOT"}
;
LongString_0_sysvq0asl const strlit_0_I9893293526153346610_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EOPNOTSUPP"}
;
LongString_0_sysvq0asl const strlit_0_I17556606778065541191_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLLRDHUP"}
;
LongString_0_sysvq0asl const strlit_0_I13209058275940028340_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLL_CLOEXEC"}
;
LongString_0_sysvq0asl const strlit_0_I2227035140242129764_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AI_PASSIVE"}
;
LongString_0_sysvq0asl const strlit_0_I11776152313751980820_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EDESTADDRREQ"}
;
LongString_0_sysvq0asl const strlit_0_I15806131157789360951_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOPROTOOPT"}
;
LongString_0_sysvq0asl const strlit_0_I8761593122721247282_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPROTOTYPE"}
;
LongString_0_sysvq0asl const strlit_0_I11678056797885678089_runot4689 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPROTONOSUPPORT"}
;
LongString_0_sysvq0asl const strlit_0_I16829864831926568729_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAI_SOCKTYPE"}
;
LongString_0_sysvq0asl const strlit_0_I9182775675243303253_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAI_MEMORY"}
;
LongString_0_sysvq0asl const strlit_0_I7746302189920450481_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENETRESET"}
;
LongString_0_sysvq0asl const strlit_0_I13043036667978839918_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOTEMPTY"}
;
LongString_0_sysvq0asl const strlit_0_I16403450858519639669_runot4689 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOTRECOVERABLE"}
;
LongString_0_sysvq0asl const strlit_0_I4798278778889723231_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EWOULDBLOCK"}
;
LongString_0_sysvq0asl const strlit_0_I6913423194599751370_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "TCP_KEEPCNT"}
;
LongString_0_sysvq0asl const strlit_0_I8182183537059069841_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "TCP_KEEPIDLE"}
;
LongString_0_sysvq0asl const strlit_0_I9626116225094488163_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "TCP_KEEPINTVL"}
;
LongString_0_sysvq0asl const strlit_0_I17583787354024638215_runot4689 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "INET6_ADDRSTRLEN"}
;
LongString_0_sysvq0asl const strlit_0_I7249319940781528932_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "TCP_NODELAY"}
;
LongString_0_sysvq0asl const strlit_0_I5787969039729970751_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NI_MAXHOST"}
;
LongString_0_sysvq0asl const strlit_0_I18167337230236686779_runot4689 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "PTHREAD_MUTEX_RECURSIVE"}
;
LongString_0_sysvq0asl const strlit_0_I17889022518531510231_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "O_NONBLOCK"}
;
LongString_0_sysvq0asl const strlit_0_I4344074165183380173_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_RCVBUF"}
;
LongString_0_sysvq0asl const strlit_0_I1000757519110562595_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_LINGER"}
;
LongString_0_sysvq0asl const strlit_0_I1870891164029464854_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_SNDBUF"}
;
LongString_0_sysvq0asl const strlit_0_I11009998552320449210_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "IPV6_V6ONLY"}
;
LongString_0_sysvq0asl const strlit_0_I5553058630802048398_runot4689 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "INET_ADDRSTRLEN"}
;
LongString_0_sysvq0asl const strlit_0_I11734112185704578351_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "MSG_WAITALL"}
;
LongString_0_sysvq0asl const strlit_0_I16174996664107135480_runot4689 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NI_NUMERICHOST"}
;
LongString_0_sysvq0asl const strlit_0_I7037597850929843469_runot4689 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NI_NUMERICSERV"}
;
LongString_0_sysvq0asl const strlit_0_I10809207772613252416_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "POLLRDHUP"}
;
LongString_0_sysvq0asl const strlit_0_I15800523363237382565_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SOCK_DGRAM"}
;
LongString_0_sysvq0asl const strlit_0_I9240057488478669814_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SOCK_CLOEXEC"}
;
LongString_0_sysvq0asl const strlit_0_I12664588953822526387_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SOL_SOCKET"}
;
LongString_0_sysvq0asl const strlit_0_I4226514502516112276_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_BROADCAST"}
;
LongString_0_sysvq0asl const strlit_0_I13632876346895515917_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SHUT_RDWR"}
;
LongString_0_sysvq0asl const strlit_0_I17737170811934970191_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "INADDR_ANY"}
;
LongString_0_sysvq0asl const strlit_0_I7090624206164100572_runot4689 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "INADDR_LOOPBACK"}
;
LongString_0_sysvq0asl const strlit_0_I6359826815753912034_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "MSG_DONTWAIT"}
;
LongString_0_sysvq0asl const strlit_0_I8788901631926167309_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "MSG_NOSIGNAL"}
;
LongString_0_sysvq0asl const strlit_0_I9559849193963664254_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "O_CLOEXEC"}
;
LongString_0_sysvq0asl const strlit_0_I9389307232129446377_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SOCK_NONBLOCK"}
;
LongString_0_sysvq0asl const strlit_0_I2049951798581219970_runot4689 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SOMAXCONN"}
;
LongString_0_sysvq0asl const strlit_0_I18164877413073487427_runot4689 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "_SC_NPROCESSORS_ONLN"}
;
LongString_0_sysvq0asl const strlit_0_I15905776585326246364_runot4689 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SC_NPROCESSORS_ONLN"}
;
LongString_0_sysvq0asl const strlit_0_I2671533804468217520_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_KEEPALIVE"}
;
LongString_0_sysvq0asl const strlit_0_I10532456418562285465_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_SNDTIMEO"}
;
LongString_0_sysvq0asl const strlit_0_I12281703296401441837_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "IPPROTO_IP"}
;
LongString_0_sysvq0asl const strlit_0_I1962864414267436350_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "IPPROTO_IPV6"}
;
LongString_0_sysvq0asl const strlit_0_I4171139148755867550_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "IPPROTO_TCP"}
;
LongString_0_sysvq0asl const strlit_0_I16984630673936295851_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "IPPROTO_UDP"}
;
LongString_0_sysvq0asl const strlit_0_I15095837033020071043_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NI_MAXSERV"}
;
LongString_0_sysvq0asl const strlit_0_I6673179633149433259_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_RCVTIMEO"}
;
LongString_0_sysvq0asl const strlit_0_I6789973116114424194_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_REUSEADDR"}
;
LongString_0_sysvq0asl const strlit_0_I17128670092080497032_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_REUSEPORT"}
;
LongString_0_sysvq0asl const strlit_0_I3857493931253010879_runot4689 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SOCK_STREAM"}
;
LongString_0_sysvq0asl const strlit_0_I3149784073278903579_runot4689 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fpInfinite"}
;
LongString_0_sysvq0asl const strlit_0_I6033114792105624477_runot4689 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fpNormal"}
;
LongString_0_sysvq0asl const strlit_0_I5158232484248566749_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EDEADLK"}
;
LongString_0_sysvq0asl const strlit_0_I17457601873643567287_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EBADMSG"}
;
LongString_0_sysvq0asl const strlit_0_I1809179661248541393_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENODATA"}
;
LongString_0_sysvq0asl const strlit_0_I5139042553195443001_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "POLLERR"}
;
LongString_0_sysvq0asl const strlit_0_I17013449421715367364_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "POLLHUP"}
;
LongString_0_sysvq0asl const strlit_0_I17358945580507176610_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLLERR"}
;
LongString_0_sysvq0asl const strlit_0_I5248620504356590772_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLLET"}
;
LongString_0_sysvq0asl const strlit_0_I12271380861566684602_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLLHUP"}
;
LongString_0_sysvq0asl const strlit_0_I10839707354694829060_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLLIN"}
;
LongString_0_sysvq0asl const strlit_0_I3937690270225078500_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLLPRI"}
;
LongString_0_sysvq0asl const strlit_0_I8946932245986333730_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPOLLOUT"}
;
LongString_0_sysvq0asl const strlit_0_I11594876617722388375_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "DBL_MIN"}
;
LongString_0_sysvq0asl const strlit_0_I10144059179297749967_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "DBL_MAX"}
;
LongString_0_sysvq0asl const strlit_0_I4255749366583942339_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EALREADY"}
;
LongString_0_sysvq0asl const strlit_0_I4781299124954187715_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAI_FAIL"}
;
LongString_0_sysvq0asl const strlit_0_I13634279464104443691_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SIGPIPE"}
;
LongString_0_sysvq0asl const strlit_0_I14468723604863520882_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENETDOWN"}
;
LongString_0_sysvq0asl const strlit_0_I16330101864687675799_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOTDIR"}
;
LongString_0_sysvq0asl const strlit_0_I18194623753014474103_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOTCONN"}
;
LongString_0_sysvq0asl const strlit_0_I1563878196577720926_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ETXTBSY"}
;
LongString_0_sysvq0asl const strlit_0_I15612622545109941423_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "FLT_MIN"}
;
LongString_0_sysvq0asl const strlit_0_I1732960802234142746_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "FLT_MAX"}
;
LongString_0_sysvq0asl const strlit_0_I13407841004723990027_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "E2BIG"}
;
LongString_0_sysvq0asl const strlit_0_I7696489594431534503_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EAGAIN"}
;
LongString_0_sysvq0asl const strlit_0_I16505938179313545570_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EACCES"}
;
LongString_0_sysvq0asl const strlit_0_I7885205764400162211_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EBADF"}
;
LongString_0_sysvq0asl const strlit_0_I11951888307548616935_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ECHILD"}
;
LongString_0_sysvq0asl const strlit_0_I13961222692725009152_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EFAULT"}
;
LongString_0_sysvq0asl const strlit_0_I14165813638295880333_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EFBIG"}
;
LongString_0_sysvq0asl const strlit_0_I18045396037127461917_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EIDRM"}
;
LongString_0_sysvq0asl const strlit_0_I16087019284446782908_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EINVAL"}
;
LongString_0_sysvq0asl const strlit_0_I4417284260189626978_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EILSEQ"}
;
LongString_0_sysvq0asl const strlit_0_I4422294296788528856_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EISDIR"}
;
LongString_0_sysvq0asl const strlit_0_I6018957557667376486_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENFILE"}
;
LongString_0_sysvq0asl const strlit_0_I14335387131779148269_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EMFILE"}
;
LongString_0_sysvq0asl const strlit_0_I9895666589443991481_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENODEV"}
;
LongString_0_sysvq0asl const strlit_0_I10766781976852166750_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOMEM"}
;
LongString_0_sysvq0asl const strlit_0_I11180353872235103934_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOLCK"}
;
LongString_0_sysvq0asl const strlit_0_I7918050307321854610_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPERM"}
;
LongString_0_sysvq0asl const strlit_0_I7589268120598100160_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPIPE"}
;
LongString_0_sysvq0asl const strlit_0_I2663494012684851386_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "POLLIN"}
;
LongString_0_sysvq0asl const strlit_0_I11925018427503121466_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ESRCH"}
;
LongString_0_sysvq0asl const strlit_0_I2180196358490588742_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ERANGE"}
;
LongString_0_sysvq0asl const strlit_0_I3480874712708093906_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ETIME"}
;
LongString_0_sysvq0asl const strlit_0_I15078264392612778793_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AF_INET"}
;
LongString_0_sysvq0asl const strlit_0_I1821346782087953896_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AF_INET6"}
;
LongString_0_sysvq0asl const strlit_0_I1692641011015349778_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AF_LOCAL"}
;
LongString_0_sysvq0asl const strlit_0_I8661079974994151876_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EEXIST"}
;
LongString_0_sysvq0asl const strlit_0_I16815888584729336766_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EISCONN"}
;
LongString_0_sysvq0asl const strlit_0_I6781072607786902955_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOBUFS"}
;
LongString_0_sysvq0asl const strlit_0_I17054469839633439730_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOENT"}
;
LongString_0_sysvq0asl const strlit_0_I10282372825264079254_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOEXEC"}
;
LongString_0_sysvq0asl const strlit_0_I15601062527192052937_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EMLINK"}
;
LongString_0_sysvq0asl const strlit_0_I4967662571765976842_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EMSGSIZE"}
;
LongString_0_sysvq0asl const strlit_0_I240744520471951397_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENXIO"}
;
LongString_0_sysvq0asl const strlit_0_I8724774692756819601_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "POLLOUT"}
;
LongString_0_sysvq0asl const strlit_0_I4941450663983007662_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "POLLNVAL"}
;
LongString_0_sysvq0asl const strlit_0_I8372180987632331225_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "POLLPRI"}
;
LongString_0_sysvq0asl const strlit_0_I4080054270751335887_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ESPIPE"}
;
LongString_0_sysvq0asl const strlit_0_I13498639423973040135_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EROFS"}
;
LongString_0_sysvq0asl const strlit_0_I11277392945061468617_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SO_ERROR"}
;
LongString_0_sysvq0asl const strlit_0_I362468072453043806_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EXDEV"}
;
LongString_0_sysvq0asl const strlit_0_I14570504673037786676_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "F_GETFD"}
;
LongString_0_sysvq0asl const strlit_0_I533934364364588600_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "F_GETFL"}
;
LongString_0_sysvq0asl const strlit_0_I16261150504049361679_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "F_SETFD"}
;
LongString_0_sysvq0asl const strlit_0_I8531867494946046462_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "F_SETFL"}
;
LongString_0_sysvq0asl const strlit_0_I2944771336232298774_runot4689 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SysLockType_Reentrant"}
;
LongString_0_sysvq0asl const strlit_0_I17561303392051597154_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOMSG"}
;
LongString_0_sysvq0asl const strlit_0_I18256310088179281350_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EPROTO"}
;
LongString_0_sysvq0asl const strlit_0_I278101307767034630_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOSPC"}
;
LongString_0_sysvq0asl const strlit_0_I7858844098996301644_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOSYS"}
;
LongString_0_sysvq0asl const strlit_0_I14438518319534345255_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOSTR"}
;
LongString_0_sysvq0asl const strlit_0_I9045984924491784844_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AF_UNIX"}
;
LongString_0_sysvq0asl const strlit_0_I17887482345509938807_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOTSOCK"}
;
LongString_0_sysvq0asl const strlit_0_I13423043380691448333_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOTSUP"}
;
LongString_0_sysvq0asl const strlit_0_I9851796506809248932_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "MSG_OOB"}
;
LongString_0_sysvq0asl const strlit_0_I10243074878288110481_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "MSG_PEEK"}
;
LongString_0_sysvq0asl const strlit_0_I5657775279585733169_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SHUT_RD"}
;
LongString_0_sysvq0asl const strlit_0_I2847344692231790002_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EBUSY"}
;
LongString_0_sysvq0asl const strlit_0_I12820801794451713283_runot4689 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EDOM"}
;
LongString_0_sysvq0asl const strlit_0_I17143673008816423290_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "EINTR"}
;
LongString_0_sysvq0asl const strlit_0_I14681790201059529979_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "SHUT_WR"}
;
LongString_0_sysvq0asl const strlit_0_I13308434310029317997_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ELOOP"}
;
LongString_0_sysvq0asl const strlit_0_I15946152287025759498_runot4689 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOTTY"}
;
LongString_0_sysvq0asl const strlit_0_I15039168409343197742_runot4689 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ENOSR"}
;
LongString_0_sysvq0asl const strlit_0_I13183969988249572472_runot4689 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fpNan"}
;
LongString_0_sysvq0asl const strlit_0_I17447564145226279959_runot4689 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fpZero"}
;
LongString_0_sysvq0asl const strlit_0_I2884488504956493598_runot4689 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "c_fpSubnormal"}
;
seq_0_Iw8xl5b1_arecyyj7v gErrnoCells_0_runot4689;
seq_0_Iw8xl5b1_arecyyj7v gEnvironmentCells_0_runot4689;
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* gSockErrnoCell_0_runot4689 = NIM_NIL;
NB8 traceUnported_0_runot4689;
X60Qt_0_IAarraySstring0sysvq0aslS11_runot4689 const UnportedNoops_0_runot4689 = {
  .a = {
    {
      .bytes_0 = 1701068286u, .more_0 = (&strlit_0_I10157464168546919252_intzsnzax)}
    , {
      .bytes_0 = 1920220670u, .more_0 = (&strlit_0_I7262382801534885590_intzsnzax)}
    , {
      .bytes_0 = 1600744958u, .more_0 = (&strlit_0_I7117386163922528102_emi78vuj01)}
    , {
      .bytes_0 = 1818650366u, .more_0 = (&strlit_0_I3658334576718801857_runot4689)}
    , {
      .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I83481134452578751_runot4689)}
    , {
      .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I10552516363120284090_runot4689)}
    , {
      .bytes_0 = 1868786174u, .more_0 = (&strlit_0_I8474686393983226071_runot4689)}
    , {
      .bytes_0 = 1868786174u, .more_0 = (&strlit_0_I4162784111547495237_runot4689)}
    , {
      .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I4192063856828764885_runot4689)}
    , {
      .bytes_0 = 1182363134u, .more_0 = (&strlit_0_I11161314014774899755_runot4689)}
    , {
      .bytes_0 = 1182363134u, .more_0 = (&strlit_0_I14218070088974767232_runot4689)}}}
;
NI32 noopHits_0_runot4689 = 0;
string_0_sysvq0asl noopNames_0_runot4689 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
static string_0_sysvq0asl const Marker_0 = {
  .bytes_0 = 1953704190u, .more_0 = (&strlit_0_I355568250392628060_hos14g919)}
;
seq_0_Ixdx2fh1_aow7lb5cq1 gModSuffixSeen_0_runot4689;
seq_0_Iflf8jf1_aow7lb5cq1 gModSuffixStd_0_runot4689;
NI32 gModSuffixGen_0_runot4689 = -1;
seq_0_Ixbbxx5_runot4689 gBackwardsHiCache_0_runot4689;
seq_0_Ixdx2fh1_aow7lb5cq1 gImportcNames_0_runot4689;
seq_0_Iw8xl5b1_arecyyj7v gImportcCells_0_runot4689;
seq_0_Ixdx2fh1_aow7lb5cq1 gImportcNativeNames_0_runot4689;
seq_0_I50urnw_croph25r5 gImportcNativeVals_0_runot4689;
seq_0_Iw8xl5b1_arecyyj7v gImportcNativeCells_0_runot4689;
seq_0_Ixdx2fh1_aow7lb5cq1 gImportcNativeCellNames_0_runot4689;
NB8 importcLax_0_runot4689;
NB8 X60QiniGuard_0_runot4689;
void registerEnvironmentCell_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_0){
  if ((!(c_0 == NIM_NIL))){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_137 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_0);
    add_0_Ijpw0mu_flaksyopx1((&gEnvironmentCells_0_runot4689), X60Qx_137);}}
void registerErrnoCell_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1){
  if ((!(c_1 == NIM_NIL))){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_138 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_1);
    add_0_Ijpw0mu_flaksyopx1((&gErrnoCells_0_runot4689), X60Qx_138);}}
void publishErrno_0_runot4689(void){
  NI32 X60Qx_139 = len_3_I83dzei_arecyyj7v(gErrnoCells_0_runot4689);
  if (X60Qx_139 == 0){
    return;}
  NI32 X60Qx_140 = hostErrno_0_hos1fpv3m1();
  Value_0_valzr1t4f v_30 = vInt_0_valzr1t4f(((NI64)X60Qx_140), 64);
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_141 = len_3_I83dzei_arecyyj7v(gErrnoCells_0_runot4689);
      if (i_0 < X60Qx_141){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_142 = getQ_7_Ii14ync1_arecyyj7v(gErrnoCells_0_runot4689, i_0);
        Value_0_valzr1t4f* X60Qlhs_0 = (&(*(*X60Qx_142)).d_00.v_0);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_143 = getQ_7_Ii14ync1_arecyyj7v(gErrnoCells_0_runot4689, i_0);
        Value_0_valzr1t4f X60Qlhs_1 = (*(*X60Qx_143)).d_00.v_0;
        Value_0_valzr1t4f X60Qx_144 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_30));
        (*X60Qlhs_0) = X60Qx_144;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_1));
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_30));}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* sockErrnoCell_0_runot4689(void){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_0;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&result_0));
  if (gSockErrnoCell_0_runot4689 == NIM_NIL){
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(gSockErrnoCell_0_runot4689);
    Value_0_valzr1t4f X60Qtmp_2 = vInt_0_valzr1t4f(((NI64)0), 32);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_145 = newCell_0_valzr1t4f((&X60Qtmp_2));
    gSockErrnoCell_0_runot4689 = X60Qx_145;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_2));}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(result_0);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_146 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(gSockErrnoCell_0_runot4689);
  result_0 = X60Qx_146;
  return result_0;}
void setHostSockErrno_0_runot4689(NI32 e_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_3 = sockErrnoCell_0_runot4689();
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_147 = X60Qtmp_3;
  Value_0_valzr1t4f* X60Qlhs_4 = (&(*gSockErrnoCell_0_runot4689).d_00.v_0);
  Value_0_valzr1t4f X60Qlhs_5 = vInt_0_valzr1t4f(((NI64)e_0), 32);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_4)));
  (*X60Qlhs_4) = X60Qlhs_5;
  NI32 X60Qx_148 = len_3_I83dzei_arecyyj7v(gErrnoCells_0_runot4689);
  if (X60Qx_148 == 0){
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qtmp_3);
    return;}
  Value_0_valzr1t4f v_31 = vInt_0_valzr1t4f(((NI64)e_0), 64);
  NI32 i_2 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_149 = len_3_I83dzei_arecyyj7v(gErrnoCells_0_runot4689);
      if (i_2 < X60Qx_149){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_150 = getQ_7_Ii14ync1_arecyyj7v(gErrnoCells_0_runot4689, i_2);
        Value_0_valzr1t4f* X60Qlhs_6 = (&(*(*X60Qx_150)).d_00.v_0);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_151 = getQ_7_Ii14ync1_arecyyj7v(gErrnoCells_0_runot4689, i_2);
        Value_0_valzr1t4f X60Qlhs_7 = (*(*X60Qx_151)).d_00.v_0;
        Value_0_valzr1t4f X60Qx_152 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_31));
        (*X60Qlhs_6) = X60Qx_152;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_7));
        inc_1_I6wjjge_aow2h993l1((&i_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_31));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qtmp_3);}
void publishSockErrno_0_runot4689(void){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_8 = sockErrnoCell_0_runot4689();
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_153 = X60Qtmp_8;
  NI32 e_1 = hostSockErrno_0_hos9jnsbq1();
  Value_0_valzr1t4f* X60Qlhs_9 = (&(*gSockErrnoCell_0_runot4689).d_00.v_0);
  Value_0_valzr1t4f X60Qlhs_10 = vInt_0_valzr1t4f(((NI64)e_1), 32);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_9)));
  (*X60Qlhs_9) = X60Qlhs_10;
  NI32 X60Qx_154 = len_3_I83dzei_arecyyj7v(gErrnoCells_0_runot4689);
  if (X60Qx_154 == 0){
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qtmp_8);
    return;}
  Value_0_valzr1t4f v_32 = vInt_0_valzr1t4f(((NI64)e_1), 64);
  NI32 i_3 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_155 = len_3_I83dzei_arecyyj7v(gErrnoCells_0_runot4689);
      if (i_3 < X60Qx_155){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_156 = getQ_7_Ii14ync1_arecyyj7v(gErrnoCells_0_runot4689, i_3);
        Value_0_valzr1t4f* X60Qlhs_11 = (&(*(*X60Qx_156)).d_00.v_0);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_157 = getQ_7_Ii14ync1_arecyyj7v(gErrnoCells_0_runot4689, i_3);
        Value_0_valzr1t4f X60Qlhs_12 = (*(*X60Qx_157)).d_00.v_0;
        Value_0_valzr1t4f X60Qx_158 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_32));
        (*X60Qlhs_11) = X60Qx_158;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_12));
        inc_1_I6wjjge_aow2h993l1((&i_3));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_32));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qtmp_8);}
NB8 isAllowedNoop_0_runot4689(string_0_sysvq0asl name_0){
  NB8 result_1;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_0 = toOpenArray_0_In7zd9y_runot4689((&UnportedNoops_0_runot4689));
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_159 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_159){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_0, X60Qlf_1);
            NB8 X60Qx_160 = eqQ_20_sysvq0asl((*X60Qii_2), name_0);
            if (X60Qx_160){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  result_1 = NIM_FALSE;
  return result_1;}
void noteNoop_0_runot4689(string_0_sysvq0asl name_1){
  inc_1_I6wjjge_aow2h993l1((&noopHits_0_runot4689));
  NB8 seen_0 = NIM_FALSE;
  NI32 i_4 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_161 = len_4_sysvq0asl(name_1);
      NI32 X60Qx_162 = len_4_sysvq0asl(noopNames_0_runot4689);
      if (((NI32)(i_4 + X60Qx_161)) <= X60Qx_162){
        NI32 k_0 = 0;
        {
          while (NIM_TRUE){
            NB8 X60Qx_163;
            NI32 X60Qx_164 = len_4_sysvq0asl(name_1);
            if (k_0 < X60Qx_164){
              NC8 X60Qx_165 = getQ_9_sysvq0asl(noopNames_0_runot4689, ((NI32)(i_4 + k_0)));
              NC8 X60Qx_166 = getQ_9_sysvq0asl(name_1, k_0);
              X60Qx_163 = (X60Qx_165 == X60Qx_166);}
            else {
              X60Qx_163 = NIM_FALSE;}
            if (X60Qx_163){
              inc_1_I6wjjge_aow2h993l1((&k_0));}
            else {
              break;}}}
        whileStmtLabel_1: ;
        NI32 X60Qx_167 = len_4_sysvq0asl(name_1);
        if (k_0 == X60Qx_167){
          seen_0 = NIM_TRUE;
          goto whileStmtLabel_0;}
        inc_1_I6wjjge_aow2h993l1((&i_4));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_168;
  if ((!seen_0)){
    NI32 X60Qx_169 = len_4_sysvq0asl(noopNames_0_runot4689);
    X60Qx_168 = (X60Qx_169 < 200);}
  else {
    X60Qx_168 = NIM_FALSE;}
  if (X60Qx_168){
    NI32 X60Qx_170 = len_4_sysvq0asl(noopNames_0_runot4689);
    if (0 < X60Qx_170){
      add_2_sysvq0asl((&noopNames_0_runot4689), (string_0_sysvq0asl){
        .bytes_0 = 11265u, .more_0 = NIM_NIL}
      );}
    add_2_sysvq0asl((&noopNames_0_runot4689), name_1);}}
void reportUnported_0_runot4689(string_0_sysvq0asl name_2, string_0_sysvq0asl ctx_0){
  if (traceUnported_0_runot4689){
    NI32 X60Qx_171 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I10647032785286562467_runot4689)}
    );
    NI32 X60Qx_172 = len_4_sysvq0asl(name_2);
    NI32 X60Qx_173 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2305u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_174 = len_4_sysvq0asl(ctx_0);
    NI32 X60Qx_175 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_0 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_171 + X60Qx_172)) + X60Qx_173)) + X60Qx_174)) + X60Qx_175)));
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I10647032785286562467_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_0), name_2);
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 2305u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_0), ctx_0);
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_0);
    nimStrDestroy(X60Qdesugar_0);}}
void failNilIndex_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_0, string_0_sysvq0asl ctx_1){
  if ((!(*sink_0).d_00.didQQuit_0)){
    NI32 X60Qx_176 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I17855937645147449103_runot4689)}
    );
    NI32 X60Qx_177 = len_4_sysvq0asl(ctx_1);
    NI32 X60Qx_178 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I680476680836312648_runot4689)}
    );
    NI32 X60Qx_179 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 543574526u, .more_0 = (&strlit_0_I13892765374060201417_runot4689)}
    );
    NI32 X60Qx_180 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1701406462u, .more_0 = (&strlit_0_I8909888703136744024_runot4689)}
    );
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_176 + X60Qx_177)) + X60Qx_178)) + X60Qx_179)) + X60Qx_180)));
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I17855937645147449103_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), ctx_1);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I680476680836312648_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 543574526u, .more_0 = (&strlit_0_I13892765374060201417_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 1701406462u, .more_0 = (&strlit_0_I8909888703136744024_runot4689)}
    );
    add_2_sysvq0asl((&(*sink_0).d_00.errBuf_0), X60Qdesugar_1);
    doQQuit_0_natd5co251(sink_0, 1);
    nimStrDestroy(X60Qdesugar_1);}}
void failNilContainerOp_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_1, string_0_sysvq0asl op_0){
  if ((!(*sink_1).d_00.didQQuit_0)){
    string_0_sysvq0asl X60Qx_0;
    nimStrWasMoved((&X60Qx_0));
    NB8 X60Qx_181;
    NB8 X60Qx_182;
    NB8 X60Qx_183 = eqQ_20_sysvq0asl(op_0, (string_0_sysvq0asl){
      .bytes_0 = 6118146u, .more_0 = NIM_NIL}
    );
    if (X60Qx_183){
      X60Qx_182 = NIM_TRUE;}
    else {
      NB8 X60Qx_184 = eqQ_20_sysvq0asl(op_0, (string_0_sysvq0asl){
        .bytes_0 = 1886351363u, .more_0 = NIM_NIL}
      );
      X60Qx_182 = X60Qx_184;}
    if (X60Qx_182){
      X60Qx_181 = NIM_TRUE;}
    else {
      NB8 X60Qx_185 = eqQ_20_sysvq0asl(op_0, (string_0_sysvq0asl){
        .bytes_0 = 1332704510u, .more_0 = (&strlit_0_I13575662182318269178_runot4689)}
      );
      X60Qx_181 = X60Qx_185;}
    if (X60Qx_181){
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I6395244567427789796_croph25r5)}
      ;}
    else {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I8091224095641214909_runot4689)}
      ;}
    string_0_sysvq0asl X60Qdesugar_2 = X60Qx_0;
    nimStrWasMoved((&X60Qx_0));
    NI32 X60Qx_186 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3482038733795591457_runot4689)}
    );
    NI32 X60Qx_187 = len_4_sysvq0asl(op_0);
    NI32 X60Qx_188 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1864378366u, .more_0 = (&strlit_0_I13430512253800851145_runot4689)}
    );
    NI32 X60Qx_189 = len_4_sysvq0asl(op_0);
    NI32 X60Qx_190 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I11551122325864634146_runot4689)}
    );
    NI32 X60Qx_191 = len_4_sysvq0asl(X60Qdesugar_2);
    NI32 X60Qx_192 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I12900702437801693322_runot4689)}
    );
    NI32 X60Qx_193 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I17333570120953067106_runot4689)}
    );
    NI32 X60Qx_194 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 544434686u, .more_0 = (&strlit_0_I4361863382066363811_runot4689)}
    );
    string_0_sysvq0asl X60Qdesugar_3 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_186 + X60Qx_187)) + X60Qx_188)) + X60Qx_189)) + X60Qx_190)) + X60Qx_191)) + X60Qx_192)) + X60Qx_193)) + X60Qx_194)));
    add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3482038733795591457_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_3), op_0);
    add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
      .bytes_0 = 1864378366u, .more_0 = (&strlit_0_I13430512253800851145_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_3), op_0);
    add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
      .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I11551122325864634146_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_2);
    add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
      .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I12900702437801693322_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I17333570120953067106_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
      .bytes_0 = 544434686u, .more_0 = (&strlit_0_I4361863382066363811_runot4689)}
    );
    add_2_sysvq0asl((&(*sink_1).d_00.errBuf_0), X60Qdesugar_3);
    doQQuit_0_natd5co251(sink_1, 1);
    nimStrDestroy(X60Qdesugar_3);
    nimStrDestroy(X60Qdesugar_2);
    nimStrDestroy(X60Qx_0);}}
void failNilMem_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_2, string_0_sysvq0asl op_1){
  if ((!(*sink_2).d_00.didQQuit_0)){
    NI32 X60Qx_195 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3482038733795591457_runot4689)}
    );
    NI32 X60Qx_196 = len_4_sysvq0asl(op_1);
    NI32 X60Qx_197 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1998596094u, .more_0 = (&strlit_0_I7772827330262704879_runot4689)}
    );
    NI32 X60Qx_198 = len_4_sysvq0asl(op_1);
    NI32 X60Qx_199 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I18182598141676208927_runot4689)}
    );
    NI32 X60Qx_200 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003791614u, .more_0 = (&strlit_0_I8202177012730565345_runot4689)}
    );
    NI32 X60Qx_201 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I3391095418943119447_runot4689)}
    );
    string_0_sysvq0asl X60Qdesugar_4 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_195 + X60Qx_196)) + X60Qx_197)) + X60Qx_198)) + X60Qx_199)) + X60Qx_200)) + X60Qx_201)));
    add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3482038733795591457_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_4), op_1);
    add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
      .bytes_0 = 1998596094u, .more_0 = (&strlit_0_I7772827330262704879_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_4), op_1);
    add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
      .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I18182598141676208927_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
      .bytes_0 = 2003791614u, .more_0 = (&strlit_0_I8202177012730565345_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
      .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I3391095418943119447_runot4689)}
    );
    add_2_sysvq0asl((&(*sink_2).d_00.errBuf_0), X60Qdesugar_4);
    doQQuit_0_natd5co251(sink_2, 1);
    nimStrDestroy(X60Qdesugar_4);}}
NB8 nilMemOperand_0_runot4689(openArray_0_I2902h9_intzsnzax args_0, NI32 upto_0){
  NB8 result_2;
  NI32 i_5 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_202;
      if (i_5 < upto_0){
        NI32 X60Qx_203 = len_6_Iy5lph11_intzsnzax(args_0);
        X60Qx_202 = (i_5 < X60Qx_203);}
      else {
        X60Qx_202 = NIM_FALSE;}
      if (X60Qx_202){
        Value_0_valzr1t4f* X60Qx_204 = getQ_10_Igi7i95_intzsnzax(args_0, i_5);
        if ((*X60Qx_204).kind_0 == 0){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_2 = NIM_FALSE;
  return result_2;}
NB8 nilContainerRecv_0_runot4689(openArray_0_I2902h9_intzsnzax args_1){
  NB8 result_3;
  NI32 X60Qx_205 = len_6_Iy5lph11_intzsnzax(args_1);
  if (X60Qx_205 < 1){
    return NIM_FALSE;}
  Value_0_valzr1t4f* X60Qx_206 = getQ_10_Igi7i95_intzsnzax(args_1, 0);
  Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_206);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_0 = ptrCell_0_runot4689((&X60QconstRefTemp_0));
  ValueKind_0_valzr1t4f X60Qx_1;
  if ((!(cell_0 == NIM_NIL))){
    X60Qx_1 = (*cell_0).d_00.v_0.kind_0;}
  else {
    Value_0_valzr1t4f* X60Qx_207 = getQ_10_Igi7i95_intzsnzax(args_1, 0);
    X60Qx_1 = (*X60Qx_207).kind_0;}
  result_3 = (X60Qx_1 == 0);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_0);
  return result_3;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_0);
  return result_3;}
Value_0_valzr1t4f strArg_0_runot4689(Value_0_valzr1t4f* v_0){
  Value_0_valzr1t4f result_4;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
  Value_0_valzr1t4f X60Qx_2;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
  if ((*v_0).kind_0 == 0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
    Value_0_valzr1t4f X60Qx_208 = vStr_0_valzr1t4f((string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    X60Qx_2 = X60Qx_208;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
    Value_0_valzr1t4f X60Qx_209 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_0)));
    X60Qx_2 = X60Qx_209;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
  result_4 = X60Qx_2;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
  return result_4;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
  return result_4;}
X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 concatText_0_runot4689(Value_0_valzr1t4f* v_1){
  X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 result_5;
  eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_runot4689((&result_5));
  Value_0_valzr1t4f a_4 = strArg_0_runot4689((&(*v_1)));
  switch (a_4.kind_0){
    case 6:
    {
      eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_runot4689(result_5);
      string_0_sysvq0asl X60Qtmp_14 = a_4.sval_0;
      nimStrWasMoved((&a_4.sval_0));
      result_5 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = X60Qtmp_14, .fld_1 = NIM_TRUE}
      ;}
    break;
    case 5:
    {
      string_0_sysvq0asl one_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      add_1_sysvq0asl((&one_0), a_4.cval_0);
      eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_runot4689(result_5);
      string_0_sysvq0asl X60Qtmp_15 = one_0;
      nimStrWasMoved((&one_0));
      result_5 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = X60Qtmp_15, .fld_1 = NIM_TRUE}
      ;
      nimStrDestroy(one_0);}
    break;
    default:
    {
      eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_runot4689(result_5);
      result_5 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .fld_1 = NIM_FALSE}
      ;}
    break;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_4));
  return result_5;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_4));
  return result_5;}
string_0_sysvq0asl valueKindName_0_runot4689(Value_0_valzr1t4f* v_2){
  string_0_sysvq0asl result_6;
  nimStrWasMoved((&result_6));
  string_0_sysvq0asl X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  switch ((*v_2).kind_0){
    case 0:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
      ;}
    break;
    case 1:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1953392899u, .more_0 = NIM_NIL}
      ;}
    break;
    case 2:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I18357185398770638485_aow7lb5cq1)}
      ;}
    break;
    case 3:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I11643015150811461308_aow7lb5cq1)}
      ;}
    break;
    case 4:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
      ;}
    break;
    case 5:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1634231294u, .more_0 = (&strlit_0_I3703322799828345117_aow7lb5cq1)}
      ;}
    break;
    case 6:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
      ;}
    break;
    case 7:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
      ;}
    break;
    case 8:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
      ;}
    break;
    case 9:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
      ;}
    break;
    default:
    {
      string_0_sysvq0asl X60Qdesugar_5 = dollarQ_2_sysvq0asl(((NI32)(*v_2).kind_0));
      NI32 X60Qx_210 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 15361u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_211 = len_4_sysvq0asl(X60Qdesugar_5);
      NI32 X60Qx_212 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 15873u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_6 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_210 + X60Qx_211)) + X60Qx_212)));
      add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
        .bytes_0 = 15361u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_6), X60Qdesugar_5);
      add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
        .bytes_0 = 15873u, .more_0 = NIM_NIL}
      );
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = X60Qdesugar_6;
      nimStrWasMoved((&X60Qdesugar_6));
      nimStrDestroy(X60Qdesugar_6);
      nimStrDestroy(X60Qdesugar_5);}
    break;}
  nimStrDestroy(result_6);
  result_6 = X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  nimStrDestroy(X60Qx_3);
  return result_6;
  nimStrDestroy(X60Qx_3);
  return result_6;}
void failShape_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_3, string_0_sysvq0asl name_3, seq_0_I50urnw_croph25r5 args_2){
  string_0_sysvq0asl shape_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 i_6 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_213 = len_3_I4n9kvq_intzsnzax(args_2);
      if (i_6 < X60Qx_213){
        if (0 < i_6){
          add_2_sysvq0asl((&shape_0), (string_0_sysvq0asl){
            .bytes_0 = 2108418u, .more_0 = NIM_NIL}
          );}
        Value_0_valzr1t4f* X60Qx_214 = getQ_7_Ine8yq71_intzsnzax(args_2, i_6);
        Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_214);
        string_0_sysvq0asl X60Qtmp_16 = valueKindName_0_runot4689((&X60QconstRefTemp_0));
        add_2_sysvq0asl((&shape_0), X60Qtmp_16);
        inc_1_I6wjjge_aow2h993l1((&i_6));
        nimStrDestroy(X60Qtmp_16);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_215 = len_4_sysvq0asl(name_3);
  NI32 X60Qx_216 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_217 = len_4_sysvq0asl(shape_0);
  NI32 X60Qx_218 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_7 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_215 + X60Qx_216)) + X60Qx_217)) + X60Qx_218)));
  add_2_sysvq0asl((&X60Qdesugar_7), name_3);
  add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_7), shape_0);
  add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  reportUnported_0_runot4689(X60Qdesugar_7, (string_0_sysvq0asl){
    .bytes_0 = 1952542462u, .more_0 = (&strlit_0_I14948233031946914775_runot4689)}
  );
  if ((!(*sink_3).d_00.didQQuit_0)){
    NI32 X60Qx_219 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I696346342095441754_runot4689)}
    );
    NI32 X60Qx_220 = len_4_sysvq0asl(name_3);
    NI32 X60Qx_221 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 10241u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_222 = len_4_sysvq0asl(shape_0);
    NI32 X60Qx_223 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539437566u, .more_0 = (&strlit_0_I16229626376861876445_runot4689)}
    );
    NI32 X60Qx_224 = len_4_sysvq0asl(name_3);
    NI32 X60Qx_225 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1746937854u, .more_0 = (&strlit_0_I16330257589235283131_runot4689)}
    );
    NI32 X60Qx_226 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I6564517153549527586_runot4689)}
    );
    NI32 X60Qx_227 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1634886398u, .more_0 = (&strlit_0_I9873199351554270220_runot4689)}
    );
    NI32 X60Qx_228 = len_4_sysvq0asl(name_3);
    NI32 X60Qx_229 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1713383422u, .more_0 = (&strlit_0_I7647809558014641970_runot4689)}
    );
    NI32 X60Qx_230 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I193201366648006738_runot4689)}
    );
    string_0_sysvq0asl X60Qdesugar_8 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_219 + X60Qx_220)) + X60Qx_221)) + X60Qx_222)) + X60Qx_223)) + X60Qx_224)) + X60Qx_225)) + X60Qx_226)) + X60Qx_227)) + X60Qx_228)) + X60Qx_229)) + X60Qx_230)));
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I696346342095441754_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), name_3);
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 10241u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), shape_0);
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 539437566u, .more_0 = (&strlit_0_I16229626376861876445_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), name_3);
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 1746937854u, .more_0 = (&strlit_0_I16330257589235283131_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I6564517153549527586_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 1634886398u, .more_0 = (&strlit_0_I9873199351554270220_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), name_3);
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 1713383422u, .more_0 = (&strlit_0_I7647809558014641970_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I193201366648006738_runot4689)}
    );
    add_2_sysvq0asl((&(*sink_3).d_00.errBuf_0), X60Qdesugar_8);
    doQQuit_0_natd5co251(sink_3, 1);
    nimStrDestroy(X60Qdesugar_8);}
  nimStrDestroy(X60Qdesugar_7);
  nimStrDestroy(shape_0);}
void failUnported_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_4, string_0_sysvq0asl name_4, string_0_sysvq0asl ctx_2){
  reportUnported_0_runot4689(name_4, ctx_2);
  if ((!(*sink_4).d_00.didQQuit_0)){
    NI32 X60Qx_231 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I1169319743787033125_runot4689)}
    );
    NI32 X60Qx_232 = len_4_sysvq0asl(name_4);
    NI32 X60Qx_233 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 673195779u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_234 = len_4_sysvq0asl(ctx_2);
    NI32 X60Qx_235 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I15763493685976154898_runot4689)}
    );
    NI32 X60Qx_236 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I8002392516255080284_runot4689)}
    );
    NI32 X60Qx_237 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 544434686u, .more_0 = (&strlit_0_I11178650102999243047_runot4689)}
    );
    string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_231 + X60Qx_232)) + X60Qx_233)) + X60Qx_234)) + X60Qx_235)) + X60Qx_236)) + X60Qx_237)));
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I1169319743787033125_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_9), name_4);
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 673195779u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_9), ctx_2);
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 3793758718u, .more_0 = (&strlit_0_I15763493685976154898_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I8002392516255080284_runot4689)}
    );
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 544434686u, .more_0 = (&strlit_0_I11178650102999243047_runot4689)}
    );
    add_2_sysvq0asl((&(*sink_4).d_00.errBuf_0), X60Qdesugar_9);
    doQQuit_0_natd5co251(sink_4, 1);
    nimStrDestroy(X60Qdesugar_9);}}
string_0_sysvq0asl nodeTag_0_runot4689(Cursor_0_nifb6mq6y1 n_0){
  string_0_sysvq0asl result_7;
  nimStrWasMoved((&result_7));
  nimStrDestroy(result_7);
  NU32 X60Qx_238 = tagId_0_nifb6mq6y1(n_0);
  string_0_sysvq0asl* X60Qx_239 = getQ_0_I93d71y_der823rwr1(pool_0_nifh7u8pu1.tags_0, X60Qx_238);
  string_0_sysvq0asl X60Qx_240 = nimStrDup((*X60Qx_239));
  result_7 = X60Qx_240;
  return result_7;}
Value_0_valzr1t4f emptySeqVal_0_runot4689(void){
  Value_0_valzr1t4f result_8;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_8));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_8));
  void* X60Qx_241 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_17 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_241);
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_242 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  (*X60Qtmp_17) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
      .elems_0 = X60Qx_242, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
  ;
  result_8 = (Value_0_valzr1t4f){
    .kind_0 = 8, .sq_0 = X60Qtmp_17}
  ;
  return result_8;}
NU32 enumTypeOfField_0_runot4689(NU32 fieldSym_0){
  NU32 result_10;
  result_10 = ((NU32)0u);
  if (((NU32)fieldSym_0) == ((NU32)0u)){
    return result_10;}
  LoadResult_0_prorcx25w1 res_0 = tryLoadSymSafe_0_modzy18mg1(fieldSym_0);
  NB8 X60Qx_96;
  NB8 X60Qx_251;
  if (res_0.status_0 == 3){
    NifKind_0_nif81dubp1 X60Qx_252 = kind_0_nifb6mq6y1(res_0.decl_0);
    X60Qx_251 = (X60Qx_252 == 11);}
  else {
    X60Qx_251 = NIM_FALSE;}
  if (X60Qx_251){
    string_0_sysvq0asl X60Qtmp_18 = nodeTag_0_runot4689(res_0.decl_0);
    NB8 X60Qx_253 = eqQ_20_sysvq0asl(X60Qtmp_18, (string_0_sysvq0asl){
      .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_emi78vuj01)}
    );
    X60Qx_96 = X60Qx_253;
    nimStrDestroy(X60Qtmp_18);}
  else {
    X60Qx_96 = NIM_FALSE;}
  if (X60Qx_96){
    Cursor_0_nifb6mq6y1 c_5 = res_0.decl_0;
    eQwasMoved_0_nifb6mq6y1((&res_0.decl_0));
    inc_0_nifb6mq6y1((&c_5));
    skip_0_nifb6mq6y1((&c_5));
    skip_0_nifb6mq6y1((&c_5));
    skip_0_nifb6mq6y1((&c_5));
    NifKind_0_nif81dubp1 X60Qx_254 = kind_0_nifb6mq6y1(c_5);
    if (X60Qx_254 == 4){
      NU32 X60Qx_255 = symId_0_nifb6mq6y1(c_5);
      result_10 = X60Qx_255;}
    eQdestroy_0_nifb6mq6y1((&c_5));}
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_10;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_10;}
NB8 isEnumType_0_runot4689(NU32 sym_0){
  NB8 result_11;
  result_11 = NIM_FALSE;
  if (((NU32)sym_0) == ((NU32)0u)){
    return result_11;}
  LoadResult_0_prorcx25w1 res_1 = tryLoadSymSafe_0_modzy18mg1(sym_0);
  NB8 X60Qx_256;
  if ((!(res_1.status_0 == 3))){
    X60Qx_256 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_257 = kind_0_nifb6mq6y1(res_1.decl_0);
    X60Qx_256 = (!(X60Qx_257 == 11));}
  if (X60Qx_256){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
    return result_11;}
  string_0_sysvq0asl X60Qtmp_19 = nodeTag_0_runot4689(res_1.decl_0);
  NB8 X60Qx_258 = eqQ_20_sysvq0asl(X60Qtmp_19, (string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
  );
  if ((!X60Qx_258)){
    nimStrDestroy(X60Qtmp_19);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
    return result_11;}
  Cursor_0_nifb6mq6y1 c_6 = res_1.decl_0;
  eQwasMoved_0_nifb6mq6y1((&res_1.decl_0));
  inc_0_nifb6mq6y1((&c_6));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_259 = kind_0_nifb6mq6y1(c_6);
      if ((!(X60Qx_259 == 12))){
        NB8 X60Qx_97;
        NifKind_0_nif81dubp1 X60Qx_260 = kind_0_nifb6mq6y1(c_6);
        if (X60Qx_260 == 11){
          NB8 X60Qx_98;
          string_0_sysvq0asl X60Qtmp_20 = nodeTag_0_runot4689(c_6);
          NB8 X60Qx_261 = eqQ_20_sysvq0asl(X60Qtmp_20, (string_0_sysvq0asl){
            .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
          );
          if (X60Qx_261){
            X60Qx_98 = NIM_TRUE;}
          else {
            string_0_sysvq0asl X60Qtmp_21 = nodeTag_0_runot4689(c_6);
            NB8 X60Qx_262 = eqQ_20_sysvq0asl(X60Qtmp_21, (string_0_sysvq0asl){
              .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_fiepkwzpc)}
            );
            X60Qx_98 = X60Qx_262;
            nimStrDestroy(X60Qtmp_21);}
          X60Qx_97 = X60Qx_98;
          nimStrDestroy(X60Qtmp_20);}
        else {
          X60Qx_97 = NIM_FALSE;}
        if (X60Qx_97){
          eQdestroy_0_nifb6mq6y1((&c_6));
          nimStrDestroy(X60Qtmp_19);
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
          return NIM_TRUE;}
        skip_0_nifb6mq6y1((&c_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&c_6));
  nimStrDestroy(X60Qtmp_19);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
  return result_11;
  eQdestroy_0_nifb6mq6y1((&c_6));
  nimStrDestroy(X60Qtmp_19);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
  return result_11;}
NI32 arrayLowFromType_0_runot4689(Cursor_0_nifb6mq6y1 typeCur_0){
  NI32 result_13;
  result_13 = 0;
  NB8 X60Qx_102;
  NifKind_0_nif81dubp1 X60Qx_281 = kind_0_nifb6mq6y1(typeCur_0);
  if ((!(X60Qx_281 == 11))){
    X60Qx_102 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_25 = nodeTag_0_runot4689(typeCur_0);
    NB8 X60Qx_282 = eqQ_20_sysvq0asl(X60Qtmp_25, (string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
    );
    X60Qx_102 = (!X60Qx_282);
    nimStrDestroy(X60Qtmp_25);}
  if (X60Qx_102){
    return result_13;}
  Cursor_0_nifb6mq6y1 c_8 = eQdup_0_nifb6mq6y1(typeCur_0);
  inc_0_nifb6mq6y1((&c_8));
  skip_0_nifb6mq6y1((&c_8));
  NB8 X60Qx_103;
  NifKind_0_nif81dubp1 X60Qx_283 = kind_0_nifb6mq6y1(c_8);
  if (X60Qx_283 == 11){
    string_0_sysvq0asl X60Qtmp_26 = nodeTag_0_runot4689(c_8);
    NB8 X60Qx_284 = eqQ_20_sysvq0asl(X60Qtmp_26, (string_0_sysvq0asl){
      .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16393544569146403439_intzsnzax)}
    );
    X60Qx_103 = X60Qx_284;
    nimStrDestroy(X60Qtmp_26);}
  else {
    X60Qx_103 = NIM_FALSE;}
  if (X60Qx_103){
    Cursor_0_nifb6mq6y1 r_0 = c_8;
    eQwasMoved_0_nifb6mq6y1((&c_8));
    inc_0_nifb6mq6y1((&r_0));
    skip_0_nifb6mq6y1((&r_0));
    NifKind_0_nif81dubp1 X60Qx_285 = kind_0_nifb6mq6y1(r_0);
    if (X60Qx_285 == 8){
      NU32 X60Qx_286 = intId_0_nifb6mq6y1(r_0);
      NI64* X60Qx_287 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_286);
      result_13 = ((NI32)(*X60Qx_287));}
    eQdestroy_0_nifb6mq6y1((&r_0));}
  eQdestroy_0_nifb6mq6y1((&c_8));
  return result_13;
  eQdestroy_0_nifb6mq6y1((&c_8));
  return result_13;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* ptrCell_0_runot4689(Value_0_valzr1t4f* v_3){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_14;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&result_14));
  if ((*v_3).kind_0 == 13){
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(result_14);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_288 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*v_3).loc_0);
    result_14 = X60Qx_288;}
  else {
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(result_14);
    result_14 = NIM_NIL;}
  return result_14;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* intSlotCell_0_runot4689(Value_0_valzr1t4f* v_4){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_15;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&result_15));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_9 = ptrCell_0_runot4689((&(*v_4)));
  {
    while (NIM_TRUE){
      NB8 X60Qx_289;
      NB8 X60Qx_290;
      if ((!(c_9 == NIM_NIL))){
        X60Qx_290 = ((*c_9).d_00.v_0.kind_0 == 13);}
      else {
        X60Qx_290 = NIM_FALSE;}
      if (X60Qx_290){
        X60Qx_289 = (!((*c_9).d_00.v_0.loc_0 == NIM_NIL));}
      else {
        X60Qx_289 = NIM_FALSE;}
      if (X60Qx_289){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_27 = c_9;
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_291 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*c_9).d_00.v_0.loc_0);
        c_9 = X60Qx_291;
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qlhs_27);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(result_15);
  result_15 = c_9;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&c_9));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_9);
  return result_15;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_9);
  return result_15;}
NI32 fdOfValue_0_runot4689(Value_0_valzr1t4f* v_5){
  NI32 result_16;
  switch ((*v_5).kind_0){
    case 1:
    case 2:
    {
      NI64 X60Qx_292 = asInt_0_valzr1t4f((&(*v_5)));
      result_16 = ((NI32)X60Qx_292);}
    break;
    default:
    {
      result_16 = -1;}
    break;}
  return result_16;}
string_0_sysvq0asl ptrToString_0_runot4689(Value_0_valzr1t4f* v_6){
  string_0_sysvq0asl result_17;
  nimStrWasMoved((&result_17));
  nimStrDestroy(result_17);
  result_17 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  Value_0_valzr1t4f x_9 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_6)));
  if (x_9.kind_0 == 13){
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_28 = region_0_valzr1t4f((&x_9));
    if ((!(X60Qtmp_28 == NIM_NIL))){
      NI32 i_8 = 0;
      {
        while (i_8 < 65536){
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_29 = region_0_valzr1t4f((&x_9));
          NI32 X60Qx_293 = foff_0_valzr1t4f((&x_9));
          NU8 b_3 = byteAt_0_flaksyopx1(X60Qtmp_29, ((NI32)(((NI32)X60Qx_293) + i_8)));
          if (b_3 == ((NU8)0u)){
            eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_29);
            goto whileStmtLabel_0;}
          add_1_sysvq0asl((&result_17), ((NC8)b_3));
          inc_1_I6wjjge_aow2h993l1((&i_8));
          eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_29);}}
      whileStmtLabel_0: ;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_28);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&x_9));
      return result_17;}
    if ((!(x_9.loc_0 == NIM_NIL))){
      Value_0_valzr1t4f X60Qlhs_30 = x_9;
      Value_0_valzr1t4f X60Qx_294 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*x_9.loc_0).d_00.v_0));
      x_9 = X60Qx_294;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_30));}
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_28);}
  if (x_9.kind_0 == 6){
    nimStrDestroy(result_17);
    result_17 = x_9.sval_0;
    nimStrWasMoved((&x_9.sval_0));
    NI32 n_4 = len_4_sysvq0asl(result_17);
    {
      while (NIM_TRUE){
        NB8 X60Qx_295;
        if (0 < n_4){
          NC8 X60Qx_296 = getQ_9_sysvq0asl(result_17, ((NI32)(n_4 - 1)));
          X60Qx_295 = (X60Qx_296 == (NC8)'\000');}
        else {
          X60Qx_295 = NIM_FALSE;}
        if (X60Qx_295){
          dec_1_I0nzoz91_aow7lb5cq1((&n_4));}
        else {
          break;}}}
    whileStmtLabel_1: ;
    NI32 X60Qx_297 = len_4_sysvq0asl(result_17);
    if (n_4 < X60Qx_297){
      string_0_sysvq0asl X60Qlhs_31 = substr_0_sysvq0asl(result_17, 0, ((NI32)(n_4 - 1)));
      nimStrDestroy(result_17);
      result_17 = X60Qlhs_31;}}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&x_9));
  return result_17;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&x_9));
  return result_17;}
X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 ptrRegionOf_0_runot4689(Value_0_valzr1t4f* v_7){
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 result_18;
  eQwasmovedQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689((&result_18));
  if ((!((*v_7).kind_0 == 13))){
    result_18 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
      .fld_0 = NIM_NIL, .fld_1 = 0}
    ;
    return result_18;}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_32 = region_0_valzr1t4f((&(*v_7)));
  if ((!(X60Qtmp_32 == NIM_NIL))){
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_298 = region_0_valzr1t4f((&(*v_7)));
    NI32 X60Qx_299 = foff_0_valzr1t4f((&(*v_7)));
    result_18 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
      .fld_0 = X60Qx_298, .fld_1 = ((NI32)X60Qx_299)}
    ;
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_32);
    return result_18;}
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_33 = arrOwn_0_valzr1t4f((&(*v_7)));
  if ((!(X60Qtmp_33 == NIM_NIL))){
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_34 = arrOwn_0_valzr1t4f((&(*v_7)));
    if ((*X60Qtmp_34).d_00.flat_0 == NIM_NIL){
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_36 = arrOwn_0_valzr1t4f((&(*v_7)));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_35 = (&(*X60Qtmp_36).d_00.flat_0);
      void* X60Qx_300 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_38 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_300);
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_301 = arrOwn_0_valzr1t4f((&(*v_7)));
      (*X60Qtmp_38) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
          .kind_0 = 2, .abox_0 = X60Qx_301, .aEbits_0 = 8, .aEcode_0 = 3}}
      ;
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_37 = X60Qtmp_38;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((*X60Qlhs_35));
      (*X60Qlhs_35) = X60Qlhs_37;
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_36);}
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_39 = arrOwn_0_valzr1t4f((&(*v_7)));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_104 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((*X60Qtmp_39).d_00.flat_0);
    NI32 X60Qx_105 = base_0_valzr1t4f((&(*v_7)));
    result_18 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
      .fld_0 = X60Qx_104, .fld_1 = X60Qx_105}
    ;
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_39);
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_34);
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_33);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_32);
    return result_18;
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_39);
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_34);}
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_40 = seqOwn_0_valzr1t4f((&(*v_7)));
  if ((!(X60Qtmp_40 == NIM_NIL))){
    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_41 = seqOwn_0_valzr1t4f((&(*v_7)));
    if ((*X60Qtmp_41).d_00.flat_0 == NIM_NIL){
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_43 = seqOwn_0_valzr1t4f((&(*v_7)));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_42 = (&(*X60Qtmp_43).d_00.flat_0);
      void* X60Qx_302 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_45 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_302);
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_303 = seqOwn_0_valzr1t4f((&(*v_7)));
      (*X60Qtmp_45) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
          .kind_0 = 1, .sbox_0 = X60Qx_303, .sEbits_0 = 8, .sEcode_0 = 3}}
      ;
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_44 = X60Qtmp_45;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((*X60Qlhs_42));
      (*X60Qlhs_42) = X60Qlhs_44;
      eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_43);}
    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_46 = seqOwn_0_valzr1t4f((&(*v_7)));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_106 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((*X60Qtmp_46).d_00.flat_0);
    NI32 X60Qx_107 = base_0_valzr1t4f((&(*v_7)));
    result_18 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
      .fld_0 = X60Qx_106, .fld_1 = X60Qx_107}
    ;
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_46);
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_41);
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_40);
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_33);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_32);
    return result_18;
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_46);
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_41);}
  if ((!((*v_7).loc_0 == NIM_NIL))){
    if ((*(*v_7).loc_0).d_00.v_0.kind_0 == 6){
      void* X60Qx_304 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_47 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_304);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_305 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*v_7).loc_0);
      (*X60Qtmp_47) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
          .kind_0 = 3, .scell_0 = X60Qx_305}}
      ;
      result_18 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
        .fld_0 = X60Qtmp_47, .fld_1 = 0}
      ;
      eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_40);
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_33);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_32);
      return result_18;}
    void* X60Qx_306 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_48 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_306);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_307 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*v_7).loc_0);
    (*X60Qtmp_48) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
      .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
        .kind_0 = 4, .ccell_0 = X60Qx_307}}
    ;
    result_18 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
      .fld_0 = X60Qtmp_48, .fld_1 = 0}
    ;
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_40);
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_33);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_32);
    return result_18;}
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(result_18);
  result_18 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
    .fld_0 = NIM_NIL, .fld_1 = 0}
  ;
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_40);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_33);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_32);
  return result_18;
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_40);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_33);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_32);
  return result_18;}
string_0_sysvq0asl ptrReadBytes_0_runot4689(Value_0_valzr1t4f* v_8, NI32 n_1){
  string_0_sysvq0asl result_19;
  nimStrWasMoved((&result_19));
  nimStrDestroy(result_19);
  result_19 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_0 = ptrRegionOf_0_runot4689((&(*v_8)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_1 = X60Qtmptup_0.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((&X60Qtmptup_0.fld_0));
  NI32 off_1 = X60Qtmptup_0.fld_1;
  if (r_1 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_1);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_0);
    return result_19;}
  NI32 i_9 = 0;
  {
    while (i_9 < n_1){
      NU8 X60Qx_308 = byteAt_0_flaksyopx1(r_1, ((NI32)(off_1 + i_9)));
      add_1_sysvq0asl((&result_19), ((NC8)X60Qx_308));
      inc_1_I6wjjge_aow2h993l1((&i_9));}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_1);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_0);
  return result_19;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_1);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_0);
  return result_19;}
NI32 ptrExtent_0_runot4689(Value_0_valzr1t4f* v_9){
  NI32 result_20;
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_1 = ptrRegionOf_0_runot4689((&(*v_9)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_2 = X60Qtmptup_1.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((&X60Qtmptup_1.fld_0));
  NI32 off_2 = X60Qtmptup_1.fld_1;
  if (r_2 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_2);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_1);
    return -1;}
  NI32 n_5 = regionLen_0_flaksyopx1(r_2);
  if (n_5 < 0){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_2);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_1);
    return -1;}
  NI32 X60Qx_4;
  if (off_2 < n_5){
    X60Qx_4 = ((NI32)(n_5 - off_2));}
  else {
    X60Qx_4 = 0;}
  result_20 = X60Qx_4;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_2);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_1);
  return result_20;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_2);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_1);
  return result_20;}
Value_0_valzr1t4f derefForText_0_runot4689(Value_0_valzr1t4f* v_10){
  Value_0_valzr1t4f result_21;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_21));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_21));
  Value_0_valzr1t4f X60Qx_309 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_10)));
  result_21 = X60Qx_309;
  if ((*v_10).kind_0 == 13){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_10 = ptrCell_0_runot4689((&(*v_10)));
    NB8 X60Qx_310;
    if ((!(c_10 == NIM_NIL))){
      NB8 X60Qx_311;
      if ((*c_10).d_00.v_0.kind_0 == 6){
        X60Qx_311 = NIM_TRUE;}
      else {
        X60Qx_311 = ((*c_10).d_00.v_0.kind_0 == 5);}
      X60Qx_310 = X60Qx_311;}
    else {
      X60Qx_310 = NIM_FALSE;}
    if (X60Qx_310){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_21));
      Value_0_valzr1t4f X60Qx_312 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_10).d_00.v_0));
      result_21 = X60Qx_312;}
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_10);}
  return result_21;}
NB8 ptrIsByteFaithful_0_runot4689(Value_0_valzr1t4f* v_11){
  NB8 result_22;
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_2 = ptrRegionOf_0_runot4689((&(*v_11)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_3 = X60Qtmptup_2.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((&X60Qtmptup_2.fld_0));
  NI32 Q__0 = X60Qtmptup_2.fld_1;
  if (r_3 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_3);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_2);
    return NIM_FALSE;}
  NB8 X60Qx_313 = regionIsByteFaithful_0_flaksyopx1(r_3);
  result_22 = X60Qx_313;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_3);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_2);
  return result_22;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_3);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_2);
  return result_22;}
void ptrWriteBytes_0_runot4689(Value_0_valzr1t4f* v_12, string_0_sysvq0asl data_0){
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_3 = ptrRegionOf_0_runot4689((&(*v_12)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_4 = X60Qtmptup_3.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((&X60Qtmptup_3.fld_0));
  NI32 off_3 = X60Qtmptup_3.fld_1;
  if (r_4 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_4);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_3);
    return;}
  NI32 i_10 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_314 = len_4_sysvq0asl(data_0);
      if (i_10 < X60Qx_314){
        NC8 X60Qx_315 = getQ_9_sysvq0asl(data_0, i_10);
        setByteAt_0_flaksyopx1(r_4, ((NI32)(off_3 + i_10)), ((NU8)((NU8)X60Qx_315)));
        inc_1_I6wjjge_aow2h993l1((&i_10));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_4);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_3);}
NB8 isNativeBase_0_runot4689(string_0_sysvq0asl base_0){
  NB8 result_23;
  NB8 X60Qx_316 = isMemMagic_0_flaksyopx1(base_0);
  if (X60Qx_316){
    return NIM_TRUE;}
  NB8 X60Qtc_1 = nimStrAtLe_0_sysvq0asl(base_0, 1, (NC8)'i');
  if (X60Qtc_1){
    NB8 X60Qtc_2 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'h');
    if (X60Qtc_2){
      NB8 X60Qtc_3 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'b');
      if (X60Qtc_3){
        NB8 X60Qtc_4 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'S');
        if (X60Qtc_4){
          NB8 X60Qtc_5 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'=');
          if (X60Qtc_5){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 4013314u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 4013058u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}}
          else {
            NB8 X60Qtc_6 = nimStrAtLe_0_sysvq0asl(base_0, 4, (NC8)'D');
            if (X60Qtc_6){
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1230984190u, .more_0 = (&strlit_0_I16052506731142050930_runot4689)}
              )){
                goto X60Qsc_0;}}
            else {
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1230984190u, .more_0 = (&strlit_0_I17683665254279387272_runot4689)}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1230984190u, .more_0 = (&strlit_0_I7311313444739886319_runot4689)}
              )){
                goto X60Qsc_0;}}}}
        else {
          NB8 X60Qtc_7 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'[');
          if (X60Qtc_7){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 6118146u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1029528323u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1684300035u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1734697726u, .more_0 = (&strlit_0_I17823405900913585998_runot4689)}
            )){
              goto X60Qsc_0;}}}}
      else {
        NB8 X60Qtc_8 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'f');
        if (X60Qtc_8){
          NB8 X60Qtc_9 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'d');
          if (X60Qtc_9){
            NB8 X60Qtc_10 = nimStrAtLe_0_sysvq0asl(base_0, 3, (NC8)'E');
            if (X60Qtc_10){
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I11216437567223755660_iop7yt73v)}
              )){
                goto X60Qsc_0;}}
            else {
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1818584067u, .more_0 = NIM_NIL}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I7523013755933230041_runot4689)}
              )){
                goto X60Qsc_0;}}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1751344638u, .more_0 = (&strlit_0_I12032775272325669946_runot4689)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1919510270u, .more_0 = (&strlit_0_I4165263228779136726_runot4689)}
            )){
              goto X60Qsc_0;}}}
        else {
          NB8 X60Qtc_11 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'g');
          if (X60Qtc_11){
            NB8 X60Qtc_12 = nimStrAtLe_0_sysvq0asl(base_0, 3, (NC8)'C');
            if (X60Qtc_12){
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I4303973984874128508_intzsnzax)}
              )){
                goto X60Qsc_0;}}
            else {
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I4300154733488353634_iop7yt73v)}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I3006705858755300605_iop7yt73v)}
              )){
                goto X60Qsc_0;}}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1734961406u, .more_0 = (&strlit_0_I8566804573867139999_nimry5ra91)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1935763710u, .more_0 = (&strlit_0_I17711552707752383867_runot4689)}
            )){
              goto X60Qsc_0;}}}}}
    else {
      NB8 X60Qtc_13 = nimStrAtLe_0_sysvq0asl(base_0, 2, (NC8)'n');
      if (X60Qtc_13){
        NB8 X60Qtc_14 = nimStrAtLe_0_sysvq0asl(base_0, 4, (NC8)'L');
        if (X60Qtc_14){
          NB8 X60Qtc_15 = nimStrAtLe_0_sysvq0asl(base_0, 4, (NC8)'B');
          if (X60Qtc_15){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I4978164850318270062_croph25r5)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I13171408700689225719_runot4689)}
            )){
              goto X60Qsc_0;}}
          else {
            NB8 X60Qtc_16 = nimStrAtLe_0_sysvq0asl(base_0, 4, (NC8)'C');
            if (X60Qtc_16){
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I3411051090140283573_croph25r5)}
              )){
                goto X60Qsc_0;}}
            else {
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I2027400509069786846_croph25r5)}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I12542130669033277445_croph25r5)}
              )){
                goto X60Qsc_0;}}}}
        else {
          NB8 X60Qtc_17 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'l');
          if (X60Qtc_17){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1852140547u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I8996502465535440862_runot4689)}
            )){
              goto X60Qsc_0;}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I7514604024534592575_intzsnzax)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I7466143617196742693_intzsnzax)}
            )){
              goto X60Qsc_0;}}}}
      else {
        NB8 X60Qtc_18 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'n');
        if (X60Qtc_18){
          NB8 X60Qtc_19 = nimStrAtLe_0_sysvq0asl(base_0, 4, (NC8)'e');
          if (X60Qtc_19){
            NB8 X60Qtc_20 = nimStrAtLe_0_sysvq0asl(base_0, 6, (NC8)'O');
            if (X60Qtc_20){
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I17462820957681339184_runot4689)}
              )){
                goto X60Qsc_0;}}
            else {
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I3225684998187034911_intzsnzax)}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I11042971208590088895_intzsnzax)}
              )){
                goto X60Qsc_0;}}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I16799243069367891670_runot4689)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I11206267958496974357_runot4689)}
            )){
              goto X60Qsc_0;}}}
        else {
          NB8 X60Qtc_21 = nimStrAtLe_0_sysvq0asl(base_0, 2, (NC8)'r');
          if (X60Qtc_21){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1919448062u, .more_0 = (&strlit_0_I12927204854279428474_runot4689)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I2442484592079803371_runot4689)}
            )){
              goto X60Qsc_0;}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I900530018976380608_intzsnzax)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I590530705459077169_runot4689)}
            )){
              goto X60Qsc_0;}}}}}}
  else {
    NB8 X60Qtc_22 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'l');
    if (X60Qtc_22){
      NB8 X60Qtc_23 = nimStrAtLe_0_sysvq0asl(base_0, 1, (NC8)'o');
      if (X60Qtc_23){
        NB8 X60Qtc_24 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'e');
        if (X60Qtc_24){
          NB8 X60Qtc_25 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'c');
          if (X60Qtc_25){
            NB8 X60Qtc_26 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'b');
            if (X60Qtc_26){
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1919902462u, .more_0 = (&strlit_0_I12973856256439326227_runot4689)}
              )){
                goto X60Qsc_0;}}
            else {
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1886216963u, .more_0 = NIM_NIL}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1970234366u, .more_0 = (&strlit_0_I4889788401779984975_runot4689)}
              )){
                goto X60Qsc_0;}}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1684956670u, .more_0 = (&strlit_0_I8891710430887467064_runot4689)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1684956670u, .more_0 = (&strlit_0_I16314744827495621298_runot4689)}
            )){
              goto X60Qsc_0;}}}
        else {
          NB8 X60Qtc_27 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'f');
          if (X60Qtc_27){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I15089905067781246666_runot4689)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I130460565633405389_runot4689)}
            )){
              goto X60Qsc_0;}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 2003790851u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I6872392552133396222_runot4689)}
            )){
              goto X60Qsc_0;}}}}
      else {
        NB8 X60Qtc_28 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'@');
        if (X60Qtc_28){
          NB8 X60Qtc_29 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'&');
          if (X60Qtc_29){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 9729u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 9217u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 16385u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 15361u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}}}
        else {
          NB8 X60Qtc_30 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'e');
          if (X60Qtc_30){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1769498110u, .more_0 = (&strlit_0_I7616721286816756_iop7yt73v)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I17971560687400798064_intzsnzax)}
            )){
              goto X60Qsc_0;}}
          else {
            NB8 X60Qtc_31 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'f');
            if (X60Qtc_31){
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1869768446u, .more_0 = (&strlit_0_I4459857122359951064_runot4689)}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1953720062u, .more_0 = (&strlit_0_I17563301282676592437_iop7yt73v)}
              )){
                goto X60Qsc_0;}}
            else {
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1953721598u, .more_0 = (&strlit_0_I885514587362827984_iop7yt73v)}
              )){
                goto X60Qsc_0;}}}}}}
    else {
      NB8 X60Qtc_32 = nimStrAtLe_0_sysvq0asl(base_0, 3, (NC8)'p');
      if (X60Qtc_32){
        NB8 X60Qtc_33 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'r');
        if (X60Qtc_33){
          NB8 X60Qtc_34 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'p');
          if (X60Qtc_34){
            NB8 X60Qtc_35 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'o');
            if (X60Qtc_35){
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
              )){
                goto X60Qsc_0;}}
            else {
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1953853694u, .more_0 = (&strlit_0_I17106851413817154788_iop7yt73v)}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1886351614u, .more_0 = (&strlit_0_I5078203883954553591_runot4689)}
              )){
                goto X60Qsc_0;}}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1953460990u, .more_0 = (&strlit_0_I3590215048999296526_runot4689)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1953460990u, .more_0 = (&strlit_0_I12537729981146465730_runot4689)}
            )){
              goto X60Qsc_0;}}}
        else {
          NB8 X60Qtc_36 = nimStrAtLe_0_sysvq0asl(base_0, 1, (NC8)'o');
          if (X60Qtc_36){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1332704510u, .more_0 = (&strlit_0_I13575662182318269178_runot4689)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1131377918u, .more_0 = (&strlit_0_I11323202368322527013_runot4689)}
            )){
              goto X60Qsc_0;}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 2037544190u, .more_0 = (&strlit_0_I14251590839437571501_intzsnzax)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1634891006u, .more_0 = (&strlit_0_I12206775736441983472_runot4689)}
            )){
              goto X60Qsc_0;}}}}
      else {
        NB8 X60Qtc_37 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'s');
        if (X60Qtc_37){
          NB8 X60Qtc_38 = nimStrAtLe_0_sysvq0asl(base_0, 0, (NC8)'q');
          if (X60Qtc_38){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1769304574u, .more_0 = (&strlit_0_I16529604172406501048_intzsnzax)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1886351363u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}}
          else {
            NB8 X60Qtc_39 = nimStrAtLe_0_sysvq0asl(base_0, 1, (NC8)'t');
            if (X60Qtc_39){
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I518833209856422221_runot4689)}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I10217866098611558294_iop7yt73v)}
              )){
                goto X60Qsc_0;}}
            else {
              if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
                .bytes_0 = 1651864574u, .more_0 = (&strlit_0_I10580268758365513846_runot4689)}
              )){
                goto X60Qsc_0;}}}}
        else {
          NB8 X60Qtc_40 = nimStrAtLe_0_sysvq0asl(base_0, 5, (NC8)'F');
          if (X60Qtc_40){
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I6178772090241098573_croph25r5)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I13565819874765507459_croph25r5)}
            )){
              goto X60Qsc_0;}}
          else {
            if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I12440307187701028700_croph25r5)}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(base_0, (string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I3703669261441550327_croph25r5)}
            )){
              goto X60Qsc_0;}}}}}}
  goto X60Qsc_42;
  X60Qsc_0: ;
  result_23 = NIM_TRUE;
  goto X60Qsc_41;
  X60Qsc_42: ;
  result_23 = NIM_FALSE;
  X60Qsc_41: ;
  return result_23;}
NB8 isGatedNative_0_runot4689(string_0_sysvq0asl base_1){
  NB8 result_24;
  NB8 X60Qtc_44 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'d');
  if (X60Qtc_44){
    NB8 X60Qtc_45 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'[');
    if (X60Qtc_45){
      NB8 X60Qtc_46 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'<');
      if (X60Qtc_46){
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 15361u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_43;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 4013058u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_43;}}
      else {
        NB8 X60Qtc_47 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'=');
        if (X60Qtc_47){
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 4013314u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_43;}}
        else {
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 6118146u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_43;}
          else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1029528323u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_43;}}}}
    else {
      NB8 X60Qtc_48 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'c');
      if (X60Qtc_48){
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1684300035u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_43;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1886216963u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_43;}}
      else {
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1818584067u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_43;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I7523013755933230041_runot4689)}
        )){
          goto X60Qsc_43;}}}}
  else {
    NB8 X60Qtc_49 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'i');
    if (X60Qtc_49){
      NB8 X60Qtc_50 = nimStrAtLe_0_sysvq0asl(base_1, 1, (NC8)'i');
      if (X60Qtc_50){
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1734961406u, .more_0 = (&strlit_0_I8566804573867139999_nimry5ra91)}
        )){
          goto X60Qsc_43;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1935763710u, .more_0 = (&strlit_0_I17711552707752383867_runot4689)}
        )){
          goto X60Qsc_43;}}
      else {
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I6872392552133396222_runot4689)}
        )){
          goto X60Qsc_43;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1684956670u, .more_0 = (&strlit_0_I16314744827495621298_runot4689)}
        )){
          goto X60Qsc_43;}}}
    else {
      NB8 X60Qtc_51 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'p');
      if (X60Qtc_51){
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1886351363u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_43;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1852140547u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_43;}}
      else {
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I590530705459077169_runot4689)}
        )){
          goto X60Qsc_43;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I518833209856422221_runot4689)}
        )){
          goto X60Qsc_43;}}}}
  goto X60Qsc_53;
  X60Qsc_43: ;
  result_24 = NIM_TRUE;
  goto X60Qsc_52;
  X60Qsc_53: ;
  result_24 = NIM_FALSE;
  X60Qsc_52: ;
  return result_24;}
NB8 isStreamGatableIO_0_runot4689(string_0_sysvq0asl base_2){
  NB8 result_25;
  NB8 X60Qtc_55 = nimStrAtLe_0_sysvq0asl(base_2, 1, (NC8)'e');
  if (X60Qtc_55){
    NB8 X60Qtc_56 = nimStrAtLe_0_sysvq0asl(base_2, 4, (NC8)'C');
    if (X60Qtc_56){
      NB8 X60Qtc_57 = nimStrAtLe_0_sysvq0asl(base_2, 5, (NC8)'l');
      if (X60Qtc_57){
        if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I3411051090140283573_croph25r5)}
        )){
          goto X60Qsc_54;}
        else if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I4978164850318270062_croph25r5)}
        )){
          goto X60Qsc_54;}}
      else {
        if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I13171408700689225719_runot4689)}
        )){
          goto X60Qsc_54;}
        else if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I11445521212967021334_croph25r5)}
        )){
          goto X60Qsc_54;}}}
    else {
      NB8 X60Qtc_58 = nimStrAtLe_0_sysvq0asl(base_2, 0, (NC8)'p');
      if (X60Qtc_58){
        if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1701146878u, .more_0 = (&strlit_0_I18218698628038865650_runot4689)}
        )){
          goto X60Qsc_54;}}
      else {
        if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I2027400509069786846_croph25r5)}
        )){
          goto X60Qsc_54;}
        else if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I17725400170363418176_runot4689)}
        )){
          goto X60Qsc_54;}}}}
  else {
    NB8 X60Qtc_59 = nimStrAtLe_0_sysvq0asl(base_2, 5, (NC8)'L');
    if (X60Qtc_59){
      NB8 X60Qtc_60 = nimStrAtLe_0_sysvq0asl(base_2, 5, (NC8)'B');
      if (X60Qtc_60){
        if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I6178772090241098573_croph25r5)}
        )){
          goto X60Qsc_54;}}
      else {
        if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I3703669261441550327_croph25r5)}
        )){
          goto X60Qsc_54;}
        else if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I14889114411614909829_runot4689)}
        )){
          goto X60Qsc_54;}}}
    else {
      NB8 X60Qtc_61 = nimStrAtLe_0_sysvq0asl(base_2, 0, (NC8)'o');
      if (X60Qtc_61){
        if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
        )){
          goto X60Qsc_54;}
        else if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I4266325610518786829_croph25r5)}
        )){
          goto X60Qsc_54;}}
      else {
        if (equalStrings_0_sysvq0asl(base_2, (string_0_sysvq0asl){
          .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I12440307187701028700_croph25r5)}
        )){
          goto X60Qsc_54;}}}}
  goto X60Qsc_63;
  X60Qsc_54: ;
  result_25 = NIM_TRUE;
  goto X60Qsc_62;
  X60Qsc_63: ;
  result_25 = NIM_FALSE;
  X60Qsc_62: ;
  return result_25;}
NB8 argIsStream_0_runot4689(Value_0_valzr1t4f* v_13){
  NB8 result_26;
  Value_0_valzr1t4f x_11 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_13)));
  NB8 X60Qx_317;
  if (x_11.kind_0 == 13){
    X60Qx_317 = (!(x_11.loc_0 == NIM_NIL));}
  else {
    X60Qx_317 = NIM_FALSE;}
  if (X60Qx_317){
    Value_0_valzr1t4f X60Qlhs_49 = x_11;
    Value_0_valzr1t4f X60Qx_318 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*x_11.loc_0).d_00.v_0));
    x_11 = X60Qx_318;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_49));}
  NB8 X60Qx_319;
  if (x_11.kind_0 == 12){
    X60Qx_319 = NIM_TRUE;}
  else {
    X60Qx_319 = (x_11.kind_0 == 11);}
  result_26 = X60Qx_319;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&x_11));
  return result_26;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&x_11));
  return result_26;}
NB8 nativeReceiver_0_runot4689(Value_0_valzr1t4f* v_14){
  NB8 result_27;
  ValueKind_0_valzr1t4f k_1 = (*v_14).kind_0;
  NB8 X60Qx_320;
  if (k_1 == 13){
    X60Qx_320 = (!((*v_14).loc_0 == NIM_NIL));}
  else {
    X60Qx_320 = NIM_FALSE;}
  if (X60Qx_320){
    k_1 = (*(*v_14).loc_0).d_00.v_0.kind_0;}
  else {
    NB8 X60Qx_321;
    if (k_1 == 12){
      X60Qx_321 = (!((*v_14).rf_0 == NIM_NIL));}
    else {
      X60Qx_321 = NIM_FALSE;}
    if (X60Qx_321){
      k_1 = (*(*v_14).rf_0).d_00.v_0.kind_0;}}
  switch (k_1){
    case 8:
    case 6:
    case 9:
    case 14:
    {
      result_27 = NIM_TRUE;}
    break;
    default:
    {
      result_27 = NIM_FALSE;}
    break;}
  return result_27;}
NB8 gateAllowsNative_0_runot4689(string_0_sysvq0asl base_3, Value_0_valzr1t4f* v_15){
  NB8 result_28;
  NB8 X60Qx_322 = eqQ_20_sysvq0asl(base_3, (string_0_sysvq0asl){
    .bytes_0 = 1935763710u, .more_0 = (&strlit_0_I17711552707752383867_runot4689)}
  );
  if (X60Qx_322){
    ValueKind_0_valzr1t4f k_2 = (*v_15).kind_0;
    NB8 X60Qx_323;
    if (k_2 == 13){
      X60Qx_323 = (!((*v_15).loc_0 == NIM_NIL));}
    else {
      X60Qx_323 = NIM_FALSE;}
    if (X60Qx_323){
      k_2 = (*(*v_15).loc_0).d_00.v_0.kind_0;}
    else {
      NB8 X60Qx_324;
      if (k_2 == 12){
        X60Qx_324 = (!((*v_15).rf_0 == NIM_NIL));}
      else {
        X60Qx_324 = NIM_FALSE;}
      if (X60Qx_324){
        k_2 = (*(*v_15).rf_0).d_00.v_0.kind_0;}}
    result_28 = (k_2 == 6);}
  else {
    ValueKind_0_valzr1t4f k_3 = (*v_15).kind_0;
    NB8 X60Qx_325;
    if (k_3 == 13){
      X60Qx_325 = (!((*v_15).loc_0 == NIM_NIL));}
    else {
      X60Qx_325 = NIM_FALSE;}
    if (X60Qx_325){
      k_3 = (*(*v_15).loc_0).d_00.v_0.kind_0;}
    NB8 X60Qx_326;
    NB8 X60Qx_327 = nativeReceiver_0_runot4689((&(*v_15)));
    if (X60Qx_327){
      X60Qx_326 = NIM_TRUE;}
    else {
      X60Qx_326 = (k_3 == 0);}
    result_28 = X60Qx_326;}
  return result_28;}
NB8 isInterceptedForeign_0_runot4689(string_0_sysvq0asl base_4){
  NB8 result_29;
  NB8 X60Qx_328 = isMemMagic_0_flaksyopx1(base_4);
  if (X60Qx_328){
    return NIM_TRUE;}
  NB8 X60Qtc_65 = nimStrAtLe_0_sysvq0asl(base_4, 0, (NC8)'h');
  if (X60Qtc_65){
    NB8 X60Qtc_66 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'e');
    if (X60Qtc_66){
      NB8 X60Qtc_67 = nimStrAtLe_0_sysvq0asl(base_4, 2, (NC8)'m');
      if (X60Qtc_67){
        NB8 X60Qtc_68 = nimStrAtLe_0_sysvq0asl(base_4, 2, (NC8)'g');
        if (X60Qtc_68){
          NB8 X60Qtc_69 = nimStrAtLe_0_sysvq0asl(base_4, 2, (NC8)'f');
          if (X60Qtc_69){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I17978188014264979010_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I6629672319202990767_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1734304766u, .more_0 = (&strlit_0_I17733383591063213526_runot4689)}
            )){
              goto X60Qsc_64;}}}
        else {
          NB8 X60Qtc_70 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'_');
          if (X60Qtc_70){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1767859198u, .more_0 = (&strlit_0_I16869611209385436378_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1818190846u, .more_0 = (&strlit_0_I2756518269131387936_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1768252414u, .more_0 = (&strlit_0_I9007462764285996300_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1835100158u, .more_0 = (&strlit_0_I11575531321635900188_runot4689)}
            )){
              goto X60Qsc_64;}}}}
      else {
        NB8 X60Qtc_71 = nimStrAtLe_0_sysvq0asl(base_4, 2, (NC8)'r');
        if (X60Qtc_71){
          NB8 X60Qtc_72 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'_');
          if (X60Qtc_72){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1885299710u, .more_0 = (&strlit_0_I5077193025928916746_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1885299710u, .more_0 = (&strlit_0_I14098594833283830517_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1919050750u, .more_0 = (&strlit_0_I8970872227344634284_runot4689)}
            )){
              goto X60Qsc_64;}}}
        else {
          NB8 X60Qtc_73 = nimStrAtLe_0_sysvq0asl(base_4, 2, (NC8)'s');
          if (X60Qtc_73){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1935631358u, .more_0 = (&strlit_0_I3004431710427040048_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1935631358u, .more_0 = (&strlit_0_I12271947912804281422_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I10744707227501835447_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1969185790u, .more_0 = (&strlit_0_I261076703518422676_runot4689)}
            )){
              goto X60Qsc_64;}}}}}
    else {
      NB8 X60Qtc_74 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'o');
      if (X60Qtc_74){
        NB8 X60Qtc_75 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'l');
        if (X60Qtc_75){
          NB8 X60Qtc_76 = nimStrAtLe_0_sysvq0asl(base_4, 3, (NC8)'o');
          if (X60Qtc_76){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I13770135642222982414_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I15469864145960116068_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I4266325610518786829_croph25r5)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I10138590777481088495_iop7yt73v)}
            )){
              goto X60Qsc_64;}}}
        else {
          NB8 X60Qtc_77 = nimStrAtLe_0_sysvq0asl(base_4, 2, (NC8)'p');
          if (X60Qtc_77){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I9772346370466888830_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1869440766u, .more_0 = (&strlit_0_I2902005617748064841_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1936679683u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1936679934u, .more_0 = (&strlit_0_I1951864687996922622_runot4689)}
            )){
              goto X60Qsc_64;}}}}
      else {
        NB8 X60Qtc_78 = nimStrAtLe_0_sysvq0asl(base_4, 0, (NC8)'a');
        if (X60Qtc_78){
          NB8 X60Qtc_79 = nimStrAtLe_0_sysvq0asl(base_4, 3, (NC8)'s');
          if (X60Qtc_79){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I5698419940050250200_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I1702282805285054051_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I1534576491481833817_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I891118288292861849_runot4689)}
            )){
              goto X60Qsc_64;}}}
        else {
          NB8 X60Qtc_80 = nimStrAtLe_0_sysvq0asl(base_4, 0, (NC8)'e');
          if (X60Qtc_80){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1886938371u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1887004926u, .more_0 = (&strlit_0_I2254028527881297604_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1919969022u, .more_0 = (&strlit_0_I6858632851445378176_runot4689)}
            )){
              goto X60Qsc_64;}}}}}}
  else {
    NB8 X60Qtc_81 = nimStrAtLe_0_sysvq0asl(base_4, 0, (NC8)'p');
    if (X60Qtc_81){
      NB8 X60Qtc_82 = nimStrAtLe_0_sysvq0asl(base_4, 2, (NC8)'e');
      if (X60Qtc_82){
        NB8 X60Qtc_83 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'o');
        if (X60Qtc_83){
          NB8 X60Qtc_84 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'k');
          if (X60Qtc_84){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1634168062u, .more_0 = (&strlit_0_I17537008619994765435_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1684762110u, .more_0 = (&strlit_0_I11697234225982197076_hos1fpv3m1)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1685024003u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1634561534u, .more_0 = (&strlit_0_I1291718626454456793_runot4689)}
            )){
              goto X60Qsc_64;}}}
        else {
          NB8 X60Qtc_85 = nimStrAtLe_0_sysvq0asl(base_4, 0, (NC8)'l');
          if (X60Qtc_85){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1702063358u, .more_0 = (&strlit_0_I4457427298056883912_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I4718597432102153922_hos1fpv3m1)}
            )){
              goto X60Qsc_64;}}}}
      else {
        NB8 X60Qtc_86 = nimStrAtLe_0_sysvq0asl(base_4, 0, (NC8)'m');
        if (X60Qtc_86){
          NB8 X60Qtc_87 = nimStrAtLe_0_sysvq0asl(base_4, 2, (NC8)'g');
          if (X60Qtc_87){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1735355646u, .more_0 = (&strlit_0_I10762679581578789876_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1735355646u, .more_0 = (&strlit_0_I16777186388511288065_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 7236610u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1853189630u, .more_0 = (&strlit_0_I11647825660565427273_runot4689)}
            )){
              goto X60Qsc_64;}}}
        else {
          NB8 X60Qtc_88 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'o');
          if (X60Qtc_88){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 2003791875u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1885958398u, .more_0 = (&strlit_0_I2227768086840020110_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1769107710u, .more_0 = (&strlit_0_I11258486380889900750_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1953853694u, .more_0 = (&strlit_0_I10681429218388745297_runot4689)}
            )){
              goto X60Qsc_64;}}}}}
    else {
      NB8 X60Qtc_89 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'m');
      if (X60Qtc_89){
        NB8 X60Qtc_90 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'e');
        if (X60Qtc_90){
          NB8 X60Qtc_91 = nimStrAtLe_0_sysvq0asl(base_4, 0, (NC8)'s');
          if (X60Qtc_91){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I6395244567427789796_croph25r5)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I11492332034473653383_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1851880451u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1851880702u, .more_0 = (&strlit_0_I3069983570459151989_runot4689)}
            )){
              goto X60Qsc_64;}}}
        else {
          NB8 X60Qtc_92 = nimStrAtLe_0_sysvq0asl(base_4, 0, (NC8)'r');
          if (X60Qtc_92){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1684894462u, .more_0 = (&strlit_0_I13735625106940001307_hos1fpv3m1)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1852404483u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I11806394720139207185_runot4689)}
            )){
              goto X60Qsc_64;}}}}
      else {
        NB8 X60Qtc_93 = nimStrAtLe_0_sysvq0asl(base_4, 0, (NC8)'s');
        if (X60Qtc_93){
          NB8 X60Qtc_94 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'q');
          if (X60Qtc_94){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1920037886u, .more_0 = (&strlit_0_I2622871807570587851_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1970238206u, .more_0 = (&strlit_0_I16919077516905105311_runot4689)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I10988075821851534954_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I4050815769175754417_hos1fpv3m1)}
            )){
              goto X60Qsc_64;}}}
        else {
          NB8 X60Qtc_95 = nimStrAtLe_0_sysvq0asl(base_4, 1, (NC8)'n');
          if (X60Qtc_95){
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1936619006u, .more_0 = (&strlit_0_I15639938243715246193_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1819178494u, .more_0 = (&strlit_0_I2912131129587157308_hos1fpv3m1)}
            )){
              goto X60Qsc_64;}}
          else {
            if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I10246663023455874512_runot4689)}
            )){
              goto X60Qsc_64;}
            else if (equalStrings_0_sysvq0asl(base_4, (string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I12440307187701028700_croph25r5)}
            )){
              goto X60Qsc_64;}}}}}}
  goto X60Qsc_97;
  X60Qsc_64: ;
  result_29 = NIM_TRUE;
  goto X60Qsc_96;
  X60Qsc_97: ;
  result_29 = NIM_FALSE;
  X60Qsc_96: ;
  return result_29;}
NF64 toFloatVal_0_runot4689(Value_0_valzr1t4f* v_16){
  NF64 result_30;
  switch ((*v_16).kind_0){
    case 3:
    {
      result_30 = (*v_16).fval_0;}
    break;
    case 1:
    case 2:
    {
      NF64 X60Qx_329 = toFloat64_0_xinat3x34((*v_16).ival_0);
      result_30 = X60Qx_329;}
    break;
    default:
    {
      result_30 = 0.0;}
    break;}
  return result_30;}
seq_0_Iw8xl5b1_arecyyj7v elemCells_0_runot4689(Value_0_valzr1t4f* v_17){
  seq_0_Iw8xl5b1_arecyyj7v result_31;
  eQwasMoved_1_I4kgdoh1_arecyyj7v((&result_31));
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_5;
  eQwasMoved_1_I4kgdoh1_arecyyj7v((&X60Qx_5));
  switch ((*v_17).kind_0){
    case 8:
    {
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_6;
      eQwasMoved_1_I4kgdoh1_arecyyj7v((&X60Qx_6));
      if ((!((*v_17).sq_0 == NIM_NIL))){
        eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_6);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_330 = eQdup_1_Io30l171_arecyyj7v((*(*v_17).sq_0).d_00.elems_0);
        X60Qx_6 = X60Qx_330;}
      else {
        eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_6);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_331 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        X60Qx_6 = X60Qx_331;}
      eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_5);
      X60Qx_5 = X60Qx_6;
      eQwasMoved_1_I4kgdoh1_arecyyj7v((&X60Qx_6));
      eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_6);}
    break;
    case 9:
    {
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_7;
      eQwasMoved_1_I4kgdoh1_arecyyj7v((&X60Qx_7));
      if ((!((*v_17).arr_0 == NIM_NIL))){
        eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_7);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_332 = eQdup_1_Io30l171_arecyyj7v((*(*v_17).arr_0).d_00.elems_0);
        X60Qx_7 = X60Qx_332;}
      else {
        eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_7);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_333 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        X60Qx_7 = X60Qx_333;}
      eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_5);
      X60Qx_5 = X60Qx_7;
      eQwasMoved_1_I4kgdoh1_arecyyj7v((&X60Qx_7));
      eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_7);}
    break;
    default:
    {
      eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_5);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_334 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      X60Qx_5 = X60Qx_334;}
    break;}
  eQdestroy_1_I8k3d0z1_arecyyj7v(result_31);
  result_31 = X60Qx_5;
  eQwasMoved_1_I4kgdoh1_arecyyj7v((&X60Qx_5));
  eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_5);
  return result_31;
  eQdestroy_1_I8k3d0z1_arecyyj7v(X60Qx_5);
  return result_31;}
NB8 valueEquals_0_runot4689(Value_0_valzr1t4f* a_0, Value_0_valzr1t4f* b_0){
  NB8 result_32;
  if ((!(((*a_0).kind_0 == 6) == ((*b_0).kind_0 == 6)))){
    NB8 X60Qx_108;
    NB8 X60Qx_109;
    if ((*a_0).kind_0 == 13){
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_50 = region_0_valzr1t4f((&(*a_0)));
      X60Qx_109 = (!(X60Qtmp_50 == NIM_NIL));
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_50);}
    else {
      X60Qx_109 = NIM_FALSE;}
    if (X60Qx_109){
      X60Qx_108 = ((*b_0).kind_0 == 6);}
    else {
      X60Qx_108 = NIM_FALSE;}
    if (X60Qx_108){
      string_0_sysvq0asl X60Qtmp_51 = ptrToString_0_runot4689((&(*a_0)));
      NB8 X60Qx_335 = eqQ_20_sysvq0asl(X60Qtmp_51, (*b_0).sval_0);
      result_32 = X60Qx_335;
      nimStrDestroy(X60Qtmp_51);
      return result_32;
      nimStrDestroy(X60Qtmp_51);}
    NB8 X60Qx_110;
    NB8 X60Qx_111;
    if ((*b_0).kind_0 == 13){
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_52 = region_0_valzr1t4f((&(*b_0)));
      X60Qx_111 = (!(X60Qtmp_52 == NIM_NIL));
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_52);}
    else {
      X60Qx_111 = NIM_FALSE;}
    if (X60Qx_111){
      X60Qx_110 = ((*a_0).kind_0 == 6);}
    else {
      X60Qx_110 = NIM_FALSE;}
    if (X60Qx_110){
      string_0_sysvq0asl X60Qtmp_53 = ptrToString_0_runot4689((&(*b_0)));
      NB8 X60Qx_336 = eqQ_20_sysvq0asl(X60Qtmp_53, (*a_0).sval_0);
      result_32 = X60Qx_336;
      nimStrDestroy(X60Qtmp_53);
      return result_32;
      nimStrDestroy(X60Qtmp_53);}
    return NIM_FALSE;}
  switch ((*a_0).kind_0){
    case 1:
    case 2:
    {
      NI64 X60Qx_337 = asInt_0_valzr1t4f((&(*a_0)));
      NI64 X60Qx_338 = asInt_0_valzr1t4f((&(*b_0)));
      result_32 = (X60Qx_337 == X60Qx_338);}
    break;
    case 5:
    {
      if ((*b_0).kind_0 == 5){
        result_32 = ((*a_0).cval_0 == (*b_0).cval_0);}
      else {
        NI64 X60Qx_339 = asInt_0_valzr1t4f((&(*a_0)));
        NI64 X60Qx_340 = asInt_0_valzr1t4f((&(*b_0)));
        result_32 = (X60Qx_339 == X60Qx_340);}}
    break;
    case 6:
    {
      NB8 X60Qx_341;
      if ((*b_0).kind_0 == 6){
        NB8 X60Qx_342 = eqQ_20_sysvq0asl((*a_0).sval_0, (*b_0).sval_0);
        X60Qx_341 = X60Qx_342;}
      else {
        X60Qx_341 = NIM_FALSE;}
      result_32 = X60Qx_341;}
    break;
    case 4:
    {
      NB8 X60Qx_343;
      if ((*b_0).kind_0 == 4){
        X60Qx_343 = ((*a_0).bval_0 == (*b_0).bval_0);}
      else {
        X60Qx_343 = NIM_FALSE;}
      result_32 = X60Qx_343;}
    break;
    case 7:
    {
      if ((*b_0).kind_0 == 7){
        result_32 = ((*a_0).eord_0 == (*b_0).eord_0);}
      else {
        NI64 X60Qx_344 = asInt_0_valzr1t4f((&(*a_0)));
        NI64 X60Qx_345 = asInt_0_valzr1t4f((&(*b_0)));
        result_32 = (X60Qx_344 == X60Qx_345);}}
    break;
    case 8:
    case 9:
    {
      NB8 X60Qx_346;
      if ((!((*b_0).kind_0 == 8))){
        X60Qx_346 = (!((*b_0).kind_0 == 9));}
      else {
        X60Qx_346 = NIM_FALSE;}
      if (X60Qx_346){
        return NIM_FALSE;}
      seq_0_Iw8xl5b1_arecyyj7v ae_0 = elemCells_0_runot4689((&(*a_0)));
      seq_0_Iw8xl5b1_arecyyj7v be_0 = elemCells_0_runot4689((&(*b_0)));
      if ((!(ae_0.len_0 == be_0.len_0))){
        eQdestroy_1_I8k3d0z1_arecyyj7v(be_0);
        eQdestroy_1_I8k3d0z1_arecyyj7v(ae_0);
        return NIM_FALSE;}
      NI32 i_11 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_347 = len_3_I83dzei_arecyyj7v(ae_0);
          if (i_11 < X60Qx_347){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_348 = getQ_7_Ii14ync1_arecyyj7v(ae_0, i_11);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_349 = getQ_7_Ii14ync1_arecyyj7v(be_0, i_11);
            NB8 X60Qx_350 = valueEquals_0_runot4689((&(*(*X60Qx_348)).d_00.v_0), (&(*(*X60Qx_349)).d_00.v_0));
            if ((!X60Qx_350)){
              eQdestroy_1_I8k3d0z1_arecyyj7v(be_0);
              eQdestroy_1_I8k3d0z1_arecyyj7v(ae_0);
              return NIM_FALSE;}
            inc_1_I6wjjge_aow2h993l1((&i_11));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      result_32 = NIM_TRUE;
      eQdestroy_1_I8k3d0z1_arecyyj7v(be_0);
      eQdestroy_1_I8k3d0z1_arecyyj7v(ae_0);}
    break;
    case 10:
    case 11:
    {
      if ((!((*b_0).kind_0 == (*a_0).kind_0))){
        return NIM_FALSE;}
      NB8 X60Qx_351;
      if ((*a_0).obj_0 == NIM_NIL){
        X60Qx_351 = NIM_TRUE;}
      else {
        X60Qx_351 = ((*b_0).obj_0 == NIM_NIL);}
      if (X60Qx_351){
        result_32 = ((*a_0).obj_0 == (*b_0).obj_0);
        return result_32;}
      if ((!((*(*a_0).obj_0).d_00.cells_0.len_0 == (*(*b_0).obj_0).d_00.cells_0.len_0))){
        return NIM_FALSE;}
      NI32 i_12 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_352 = len_3_I83dzei_arecyyj7v((*(*a_0).obj_0).d_00.cells_0);
          if (i_12 < X60Qx_352){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_353 = getQ_7_Ii14ync1_arecyyj7v((*(*a_0).obj_0).d_00.cells_0, i_12);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_354 = getQ_7_Ii14ync1_arecyyj7v((*(*b_0).obj_0).d_00.cells_0, i_12);
            NB8 X60Qx_355 = valueEquals_0_runot4689((&(*(*X60Qx_353)).d_00.v_0), (&(*(*X60Qx_354)).d_00.v_0));
            if ((!X60Qx_355)){
              return NIM_FALSE;}
            inc_1_I6wjjge_aow2h993l1((&i_12));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      result_32 = NIM_TRUE;}
    break;
    case 13:
    {
      if ((!((*b_0).kind_0 == 13))){
        NI64 X60Qx_356 = asInt_0_valzr1t4f((&(*a_0)));
        NI64 X60Qx_357 = asInt_0_valzr1t4f((&(*b_0)));
        result_32 = (X60Qx_356 == X60Qx_357);}
      else {
        NB8 X60Qx_112;
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_54 = region_0_valzr1t4f((&(*a_0)));
        if ((!(X60Qtmp_54 == NIM_NIL))){
          X60Qx_112 = NIM_TRUE;}
        else {
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_55 = region_0_valzr1t4f((&(*b_0)));
          X60Qx_112 = (!(X60Qtmp_55 == NIM_NIL));
          eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_55);}
        if (X60Qx_112){
          NB8 X60Qx_113;
          NB8 X60Qx_114;
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_56 = region_0_valzr1t4f((&(*a_0)));
          if ((!(X60Qtmp_56 == NIM_NIL))){
            X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_57 = region_0_valzr1t4f((&(*b_0)));
            X60Qx_114 = (!(X60Qtmp_57 == NIM_NIL));
            eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_57);}
          else {
            X60Qx_114 = NIM_FALSE;}
          if (X60Qx_114){
            NU64 X60Qx_358 = regionAddr_0_flaksyopx1((&(*a_0)));
            NU64 X60Qx_359 = regionAddr_0_flaksyopx1((&(*b_0)));
            X60Qx_113 = (X60Qx_358 == X60Qx_359);}
          else {
            X60Qx_113 = NIM_FALSE;}
          result_32 = X60Qx_113;
          eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_56);}
        else {
          NB8 X60Qx_115;
          X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_58 = arrOwn_0_valzr1t4f((&(*a_0)));
          if ((!(X60Qtmp_58 == NIM_NIL))){
            X60Qx_115 = NIM_TRUE;}
          else {
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_59 = arrOwn_0_valzr1t4f((&(*b_0)));
            X60Qx_115 = (!(X60Qtmp_59 == NIM_NIL));
            eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_59);}
          if (X60Qx_115){
            NB8 X60Qx_116;
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_60 = arrOwn_0_valzr1t4f((&(*a_0)));
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_61 = arrOwn_0_valzr1t4f((&(*b_0)));
            if (X60Qtmp_60 == X60Qtmp_61){
              NI32 X60Qx_360 = base_0_valzr1t4f((&(*a_0)));
              NI32 X60Qx_361 = base_0_valzr1t4f((&(*b_0)));
              X60Qx_116 = (X60Qx_360 == X60Qx_361);}
            else {
              X60Qx_116 = NIM_FALSE;}
            result_32 = X60Qx_116;
            eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_61);
            eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_60);}
          else {
            NB8 X60Qx_117;
            X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_62 = seqOwn_0_valzr1t4f((&(*a_0)));
            if ((!(X60Qtmp_62 == NIM_NIL))){
              X60Qx_117 = NIM_TRUE;}
            else {
              X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_63 = seqOwn_0_valzr1t4f((&(*b_0)));
              X60Qx_117 = (!(X60Qtmp_63 == NIM_NIL));
              eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_63);}
            if (X60Qx_117){
              NB8 X60Qx_118;
              X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_64 = seqOwn_0_valzr1t4f((&(*a_0)));
              X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_65 = seqOwn_0_valzr1t4f((&(*b_0)));
              if (X60Qtmp_64 == X60Qtmp_65){
                NI32 X60Qx_362 = base_0_valzr1t4f((&(*a_0)));
                NI32 X60Qx_363 = base_0_valzr1t4f((&(*b_0)));
                X60Qx_118 = (X60Qx_362 == X60Qx_363);}
              else {
                X60Qx_118 = NIM_FALSE;}
              result_32 = X60Qx_118;
              eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_65);
              eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_64);}
            else {
              result_32 = ((*a_0).loc_0 == (*b_0).loc_0);}
            eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_62);}
          eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qtmp_58);}
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_54);}}
    break;
    case 12:
    {
      if ((!((*b_0).kind_0 == 12))){
        NI64 X60Qx_364 = asInt_0_valzr1t4f((&(*a_0)));
        NI64 X60Qx_365 = asInt_0_valzr1t4f((&(*b_0)));
        result_32 = (X60Qx_364 == X60Qx_365);}
      else {
        result_32 = ((*a_0).rf_0 == (*b_0).rf_0);}}
    break;
    default:
    {
      NI64 X60Qx_366 = asInt_0_valzr1t4f((&(*a_0)));
      NI64 X60Qx_367 = asInt_0_valzr1t4f((&(*b_0)));
      result_32 = (X60Qx_366 == X60Qx_367);}
    break;}
  return result_32;}
void setBit_0_runot4689(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* sb_0, NI64 x_0){
  NB8 X60Qx_368;
  if (((NI64)0) <= x_0){
    X60Qx_368 = (x_0 < ((NI64)256));}
  else {
    X60Qx_368 = NIM_FALSE;}
  if (X60Qx_368){
    NI32 X60Qx_369 = nimIcheckB(((NI32)((NI64)(x_0 / ((NI64)64)))), 3);
    NI32 X60Qx_370 = nimIcheckB(((NI32)((NI64)(x_0 / ((NI64)64)))), 3);
    (*sb_0).d_00.words_0.a[X60Qx_369] = ((NU64)((*sb_0).d_00.words_0.a[X60Qx_370] | ((NU64)(((NU64)1u) << ((NU32)((NI64)(x_0 % ((NI64)64))))))));}}
void clearBit_0_runot4689(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* sb_1, NI64 x_1){
  NB8 X60Qx_371;
  if (((NI64)0) <= x_1){
    X60Qx_371 = (x_1 < ((NI64)256));}
  else {
    X60Qx_371 = NIM_FALSE;}
  if (X60Qx_371){
    NI32 X60Qx_372 = nimIcheckB(((NI32)((NI64)(x_1 / ((NI64)64)))), 3);
    NI32 X60Qx_373 = nimIcheckB(((NI32)((NI64)(x_1 / ((NI64)64)))), 3);
    (*sb_1).d_00.words_0.a[X60Qx_372] = ((NU64)((*sb_1).d_00.words_0.a[X60Qx_373] & ((NU64) ~ ((NU64)(((NU64)1u) << ((NU32)((NI64)(x_1 % ((NI64)64)))))))));}}
NB8 hasBit_0_runot4689(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* sb_2, NI64 x_2){
  NB8 result_33;
  result_33 = NIM_FALSE;
  NB8 X60Qx_374;
  if (((NI64)0) <= x_2){
    X60Qx_374 = (x_2 < ((NI64)256));}
  else {
    X60Qx_374 = NIM_FALSE;}
  if (X60Qx_374){
    NI32 X60Qx_375 = nimIcheckB(((NI32)((NI64)(x_2 / ((NI64)64)))), 3);
    result_33 = (!(((NU64)((*sb_2).d_00.words_0.a[X60Qx_375] & ((NU64)(((NU64)1u) << ((NU32)((NI64)(x_2 % ((NI64)64)))))))) == ((NU64)0u)));}
  return result_33;}
NI32 popcnt64_0_runot4689(NU64 x_3){
  NI32 result_34;
  NU64 v_33 = x_3;
  result_34 = 0;
  {
    while ((!(v_33 == ((NU64)0u)))){
      inc_1_I6wjjge_aow2h993l1((&result_34));
      v_33 = ((NU64)(v_33 & ((NU64)(v_33 - ((NU64)1u)))));}}
  whileStmtLabel_0: ;
  return result_34;}
NI32 setCard_0_runot4689(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* sb_3){
  NI32 result_35;
  NI32 X60Qx_376 = nimIcheckB(0, 3);
  NI32 X60Qx_377 = popcnt64_0_runot4689((*sb_3).d_00.words_0.a[X60Qx_376]);
  NI32 X60Qx_378 = nimIcheckB(1, 3);
  NI32 X60Qx_379 = popcnt64_0_runot4689((*sb_3).d_00.words_0.a[X60Qx_378]);
  NI32 X60Qx_380 = nimIcheckB(2, 3);
  NI32 X60Qx_381 = popcnt64_0_runot4689((*sb_3).d_00.words_0.a[X60Qx_380]);
  NI32 X60Qx_382 = nimIcheckB(3, 3);
  NI32 X60Qx_383 = popcnt64_0_runot4689((*sb_3).d_00.words_0.a[X60Qx_382]);
  result_35 = ((NI32)(((NI32)(((NI32)(X60Qx_377 + X60Qx_379)) + X60Qx_381)) + X60Qx_383));
  return result_35;}
NB8 endsWithStr_0_runot4689(string_0_sysvq0asl s_0, string_0_sysvq0asl suffix_0){
  NB8 result_36;
  NI32 X60Qx_384 = len_4_sysvq0asl(s_0);
  NI32 X60Qx_385 = len_4_sysvq0asl(suffix_0);
  if (X60Qx_384 < X60Qx_385){
    return NIM_FALSE;}
  NI32 i_13 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_386 = len_4_sysvq0asl(suffix_0);
      if (i_13 < X60Qx_386){
        NI32 X60Qx_387 = len_4_sysvq0asl(s_0);
        NI32 X60Qx_388 = len_4_sysvq0asl(suffix_0);
        NC8 X60Qx_389 = getQ_9_sysvq0asl(s_0, ((NI32)(((NI32)(X60Qx_387 - X60Qx_388)) + i_13)));
        NC8 X60Qx_390 = getQ_9_sysvq0asl(suffix_0, i_13);
        if ((!(X60Qx_389 == X60Qx_390))){
          return NIM_FALSE;}
        inc_1_I6wjjge_aow2h993l1((&i_13));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_36 = NIM_TRUE;
  return result_36;}
string_0_sysvq0asl trueModuleOf_0_runot4689(NU32 sym_1){
  string_0_sysvq0asl result_37;
  nimStrWasMoved((&result_37));
  string_0_sysvq0asl* X60Qx_391 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_1);
  string_0_sysvq0asl s_11 = nimStrDup((*X60Qx_391));
  string_0_sysvq0asl main_0 = nimStrDup(prog_0_prorcx25w1.main_0.name_0);
  NB8 X60Qx_119;
  NI32 X60Qx_392 = len_4_sysvq0asl(main_0);
  if (0 < X60Qx_392){
    string_0_sysvq0asl X60Qtmp_66 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 11777u, .more_0 = NIM_NIL}
    , main_0);
    NB8 X60Qx_393 = endsWithStr_0_runot4689(s_11, X60Qtmp_66);
    X60Qx_119 = X60Qx_393;
    nimStrDestroy(X60Qtmp_66);}
  else {
    X60Qx_119 = NIM_FALSE;}
  if (X60Qx_119){
    NI32 X60Qx_394 = len_4_sysvq0asl(s_11);
    NI32 X60Qx_395 = len_4_sysvq0asl(main_0);
    string_0_sysvq0asl X60Qlhs_67 = substr_0_sysvq0asl(s_11, 0, ((NI32)(((NI32)(X60Qx_394 - X60Qx_395)) - 2)));
    nimStrDestroy(s_11);
    s_11 = X60Qlhs_67;}
  nimStrDestroy(result_37);
  string_0_sysvq0asl X60Qx_396 = extractModule_0_symkyk35i1(s_11);
  result_37 = X60Qx_396;
  nimStrDestroy(main_0);
  nimStrDestroy(s_11);
  return result_37;
  nimStrDestroy(main_0);
  nimStrDestroy(s_11);
  return result_37;}
string_0_sysvq0asl stdlibSuffixOf_0_runot4689(string_0_sysvq0asl relPath_0){
  string_0_sysvq0asl result_38;
  nimStrWasMoved((&result_38));
  NI32 slash_0 = -1;
  NI32 i_14 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_397 = len_4_sysvq0asl(relPath_0);
      if (i_14 < X60Qx_397){
        NC8 X60Qx_398 = getQ_9_sysvq0asl(relPath_0, i_14);
        if (X60Qx_398 == (NC8)'/'){
          slash_0 = i_14;}
        inc_1_I6wjjge_aow2h993l1((&i_14));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl name_8 = substr_1_sysvq0asl(relPath_0, ((NI32)(slash_0 + 1)));
  NB8 X60Qx_120;
  NI32 X60Qx_399 = len_4_sysvq0asl(name_8);
  if (4 < X60Qx_399){
    NI32 X60Qx_400 = len_4_sysvq0asl(name_8);
    string_0_sysvq0asl X60Qtmp_68 = substr_1_sysvq0asl(name_8, ((NI32)(X60Qx_400 - 4)));
    NB8 X60Qx_401 = eqQ_20_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
      .bytes_0 = 1768828670u, .more_0 = (&strlit_0_I4160594580551937874_intzsnzax)}
    );
    X60Qx_120 = X60Qx_401;
    nimStrDestroy(X60Qtmp_68);}
  else {
    X60Qx_120 = NIM_FALSE;}
  if (X60Qx_120){
    NI32 X60Qx_402 = len_4_sysvq0asl(name_8);
    string_0_sysvq0asl X60Qlhs_69 = substr_0_sysvq0asl(name_8, 0, ((NI32)(X60Qx_402 - 5)));
    nimStrDestroy(name_8);
    name_8 = X60Qlhs_69;}
  nimStrDestroy(result_38);
  result_38 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  i_14 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_403;
      NI32 X60Qx_404 = len_4_sysvq0asl(name_8);
      if (i_14 < X60Qx_404){
        X60Qx_403 = (i_14 < 3);}
      else {
        X60Qx_403 = NIM_FALSE;}
      if (X60Qx_403){
        NC8 X60Qx_405 = getQ_9_sysvq0asl(name_8, i_14);
        add_1_sysvq0asl((&result_38), X60Qx_405);
        inc_1_I6wjjge_aow2h993l1((&i_14));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  string_0_sysvq0asl X60Qtmp_70 = uhashBase36_0_modjbswg91(relPath_0);
  add_2_sysvq0asl((&result_38), X60Qtmp_70);
  nimStrDestroy(X60Qtmp_70);
  nimStrDestroy(name_8);
  return result_38;
  nimStrDestroy(X60Qtmp_70);
  nimStrDestroy(name_8);
  return result_38;}
string_0_sysvq0asl nifStmtsSource_0_runot4689(string_0_sysvq0asl line_0){
  string_0_sysvq0asl result_39;
  nimStrWasMoved((&result_39));
  nimStrDestroy(result_39);
  result_39 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 X60Qx_406 = len_4_sysvq0asl(line_0);
  NI32 X60Qx_407 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1953704190u, .more_0 = (&strlit_0_I355568250392628060_hos14g919)}
  );
  if (X60Qx_406 <= X60Qx_407){
    return result_39;}
  NI32 X60Qx_408 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1953704190u, .more_0 = (&strlit_0_I355568250392628060_hos14g919)}
  );
  string_0_sysvq0asl X60Qtmp_71 = substr_0_sysvq0asl(line_0, 0, ((NI32)(X60Qx_408 - 1)));
  NB8 X60Qx_409 = eqQ_20_sysvq0asl(X60Qtmp_71, (string_0_sysvq0asl){
    .bytes_0 = 1953704190u, .more_0 = (&strlit_0_I355568250392628060_hos14g919)}
  );
  if ((!X60Qx_409)){
    nimStrDestroy(X60Qtmp_71);
    return result_39;}
  NI32 i_15 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1953704190u, .more_0 = (&strlit_0_I355568250392628060_hos14g919)}
  );
  NI32 commas_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_410;
      NI32 X60Qx_411 = len_4_sysvq0asl(line_0);
      if (i_15 < X60Qx_411){
        X60Qx_410 = (commas_0 < 2);}
      else {
        X60Qx_410 = NIM_FALSE;}
      if (X60Qx_410){
        NC8 X60Qx_412 = getQ_9_sysvq0asl(line_0, i_15);
        if (X60Qx_412 == (NC8)','){
          inc_1_I6wjjge_aow2h993l1((&commas_0));}
        inc_1_I6wjjge_aow2h993l1((&i_15));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (commas_0 < 2){
    nimStrDestroy(X60Qtmp_71);
    return result_39;}
  NB8 X60Qx_413;
  NI32 X60Qx_414 = len_4_sysvq0asl(line_0);
  if (i_15 < X60Qx_414){
    NC8 X60Qx_415 = getQ_9_sysvq0asl(line_0, i_15);
    X60Qx_413 = (X60Qx_415 == (NC8)'\"');}
  else {
    X60Qx_413 = NIM_FALSE;}
  if (X60Qx_413){
    inc_1_I6wjjge_aow2h993l1((&i_15));}
  {
    while (NIM_TRUE){
      NB8 X60Qx_416;
      NB8 X60Qx_417;
      NB8 X60Qx_418;
      NI32 X60Qx_419 = len_4_sysvq0asl(line_0);
      if (i_15 < X60Qx_419){
        NC8 X60Qx_420 = getQ_9_sysvq0asl(line_0, i_15);
        X60Qx_418 = (!(X60Qx_420 == (NC8)'\"'));}
      else {
        X60Qx_418 = NIM_FALSE;}
      if (X60Qx_418){
        NC8 X60Qx_421 = getQ_9_sysvq0asl(line_0, i_15);
        X60Qx_417 = (!(X60Qx_421 == (NC8)' '));}
      else {
        X60Qx_417 = NIM_FALSE;}
      if (X60Qx_417){
        NC8 X60Qx_422 = getQ_9_sysvq0asl(line_0, i_15);
        X60Qx_416 = (!(X60Qx_422 == (NC8)')'));}
      else {
        X60Qx_416 = NIM_FALSE;}
      if (X60Qx_416){
        NC8 X60Qx_423 = getQ_9_sysvq0asl(line_0, i_15);
        add_1_sysvq0asl((&result_39), X60Qx_423);
        inc_1_I6wjjge_aow2h993l1((&i_15));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  nimStrDestroy(X60Qtmp_71);
  return result_39;
  nimStrDestroy(X60Qtmp_71);
  return result_39;}
string_0_sysvq0asl moduleSourcePath_0_runot4689(string_0_sysvq0asl suffix_1){
  string_0_sysvq0asl result_40;
  nimStrWasMoved((&result_40));
  nimStrDestroy(result_40);
  result_40 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl X60Qtmp_72 = suffixToNif_0_prorcx25w1(suffix_1);
  string_0_sysvq0asl text_0 = vfsRead_0_vfsc9jn7(X60Qtmp_72);
  NI32 X60Qx_424 = len_4_sysvq0asl(text_0);
  if (X60Qx_424 == 0){
    nimStrDestroy(text_0);
    nimStrDestroy(X60Qtmp_72);
    return result_40;}
  NI32 i_16 = 0;
  NI32 n_6 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_425;
      if (n_6 < 8){
        NI32 X60Qx_426 = len_4_sysvq0asl(text_0);
        X60Qx_425 = (i_16 < X60Qx_426);}
      else {
        X60Qx_425 = NIM_FALSE;}
      if (X60Qx_425){
        NI32 e_3 = i_16;
        {
          while (NIM_TRUE){
            NB8 X60Qx_427;
            NI32 X60Qx_428 = len_4_sysvq0asl(text_0);
            if (e_3 < X60Qx_428){
              NC8 X60Qx_429 = getQ_9_sysvq0asl(text_0, e_3);
              X60Qx_427 = (!(((NI32)X60Qx_429) == 10));}
            else {
              X60Qx_427 = NIM_FALSE;}
            if (X60Qx_427){
              inc_1_I6wjjge_aow2h993l1((&e_3));}
            else {
              break;}}}
        whileStmtLabel_1: ;
        NI32 last_0 = e_3;
        NB8 X60Qx_430;
        if (i_16 < last_0){
          NC8 X60Qx_431 = getQ_9_sysvq0asl(text_0, ((NI32)(last_0 - 1)));
          X60Qx_430 = (((NI32)X60Qx_431) == 13);}
        else {
          X60Qx_430 = NIM_FALSE;}
        if (X60Qx_430){
          dec_1_I0nzoz91_aow7lb5cq1((&last_0));}
        inc_1_I6wjjge_aow2h993l1((&n_6));
        NB8 X60Qx_121;
        if (7 < ((NI32)(last_0 - i_16))){
          string_0_sysvq0asl X60Qtmp_73 = substr_0_sysvq0asl(text_0, i_16, ((NI32)(i_16 + 6)));
          NB8 X60Qx_432 = eqQ_20_sysvq0asl(X60Qtmp_73, (string_0_sysvq0asl){
            .bytes_0 = 1953704190u, .more_0 = (&strlit_0_I355568250392628060_hos14g919)}
          );
          X60Qx_121 = X60Qx_432;
          nimStrDestroy(X60Qtmp_73);}
        else {
          X60Qx_121 = NIM_FALSE;}
        if (X60Qx_121){
          nimStrDestroy(result_40);
          string_0_sysvq0asl X60Qtmp_74 = substr_0_sysvq0asl(text_0, i_16, ((NI32)(last_0 - 1)));
          string_0_sysvq0asl X60Qx_433 = nifStmtsSource_0_runot4689(X60Qtmp_74);
          result_40 = X60Qx_433;
          nimStrDestroy(X60Qtmp_74);
          goto whileStmtLabel_0;
          nimStrDestroy(X60Qtmp_74);}
        i_16 = ((NI32)(e_3 + 1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(text_0);
  nimStrDestroy(X60Qtmp_72);
  return result_40;
  nimStrDestroy(text_0);
  nimStrDestroy(X60Qtmp_72);
  return result_40;}
NB8 moduleIsStdlib_0_runot4689(string_0_sysvq0asl suffix_2){
  NB8 result_41;
  NI32 X60Qx_434 = len_4_sysvq0asl(suffix_2);
  if (X60Qx_434 == 0){
    return NIM_FALSE;}
  NB8 X60Qx_435 = eqQ_20_sysvq0asl(suffix_2, (string_0_sysvq0asl){
    .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I12313941242067973473_aow7lb5cq1)}
  );
  if (X60Qx_435){
    return NIM_TRUE;}
  NI32 X60Qx_436 = progRootGen_0_modzy18mg1();
  if ((!(gModSuffixGen_0_runot4689 == X60Qx_436))){
    NI32 X60Qx_437 = progRootGen_0_modzy18mg1();
    gModSuffixGen_0_runot4689 = X60Qx_437;
    eQdestroy_1_Ivioh0a_aow7lb5cq1(gModSuffixSeen_0_runot4689);
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_438 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    gModSuffixSeen_0_runot4689 = X60Qx_438;
    eQdestroy_1_I7a20g9_aow7lb5cq1(gModSuffixStd_0_runot4689);
    seq_0_Iflf8jf1_aow7lb5cq1 X60Qx_439 = newSeqUninit_0_I5mozxi1_aow7lb5cq1(0);
    gModSuffixStd_0_runot4689 = X60Qx_439;}
  NI32 i_17 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_440 = len_3_Ixq6taz_aow7lb5cq1(gModSuffixSeen_0_runot4689);
      if (i_17 < X60Qx_440){
        string_0_sysvq0asl* X60Qx_441 = getQ_7_Ir6d0tw_aow7lb5cq1(gModSuffixSeen_0_runot4689, i_17);
        NB8 X60Qx_442 = eqQ_20_sysvq0asl((*X60Qx_441), suffix_2);
        if (X60Qx_442){
          NB8* X60Qx_443 = getQ_7_Iul1no9_aow7lb5cq1(gModSuffixStd_0_runot4689, i_17);
          result_41 = (*X60Qx_443);
          return result_41;}
        inc_1_I6wjjge_aow2h993l1((&i_17));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 answer_0 = NIM_FALSE;
  string_0_sysvq0asl path_1 = moduleSourcePath_0_runot4689(suffix_2);
  NI32 X60Qx_444 = len_4_sysvq0asl(path_1);
  if (0 < X60Qx_444){
    NI32 lastStd_0 = -1;
    NI32 j_0 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_445 = len_4_sysvq0asl(path_1);
        if (((NI32)(j_0 + 4)) <= X60Qx_445){
          NB8 X60Qx_446;
          NB8 X60Qx_447;
          NB8 X60Qx_448;
          NB8 X60Qx_449;
          NC8 X60Qx_450 = getQ_9_sysvq0asl(path_1, j_0);
          if (X60Qx_450 == (NC8)'s'){
            NC8 X60Qx_451 = getQ_9_sysvq0asl(path_1, ((NI32)(j_0 + 1)));
            X60Qx_449 = (X60Qx_451 == (NC8)'t');}
          else {
            X60Qx_449 = NIM_FALSE;}
          if (X60Qx_449){
            NC8 X60Qx_452 = getQ_9_sysvq0asl(path_1, ((NI32)(j_0 + 2)));
            X60Qx_448 = (X60Qx_452 == (NC8)'d');}
          else {
            X60Qx_448 = NIM_FALSE;}
          if (X60Qx_448){
            NB8 X60Qx_453;
            NC8 X60Qx_454 = getQ_9_sysvq0asl(path_1, ((NI32)(j_0 + 3)));
            if (X60Qx_454 == (NC8)'/'){
              X60Qx_453 = NIM_TRUE;}
            else {
              NC8 X60Qx_455 = getQ_9_sysvq0asl(path_1, ((NI32)(j_0 + 3)));
              X60Qx_453 = (X60Qx_455 == (NC8)'\\');}
            X60Qx_447 = X60Qx_453;}
          else {
            X60Qx_447 = NIM_FALSE;}
          if (X60Qx_447){
            NB8 X60Qx_456;
            NB8 X60Qx_457;
            if (j_0 == 0){
              X60Qx_457 = NIM_TRUE;}
            else {
              NC8 X60Qx_458 = getQ_9_sysvq0asl(path_1, ((NI32)(j_0 - 1)));
              X60Qx_457 = (X60Qx_458 == (NC8)'/');}
            if (X60Qx_457){
              X60Qx_456 = NIM_TRUE;}
            else {
              NC8 X60Qx_459 = getQ_9_sysvq0asl(path_1, ((NI32)(j_0 - 1)));
              X60Qx_456 = (X60Qx_459 == (NC8)'\\');}
            X60Qx_446 = X60Qx_456;}
          else {
            X60Qx_446 = NIM_FALSE;}
          if (X60Qx_446){
            lastStd_0 = j_0;}
          inc_1_I6wjjge_aow2h993l1((&j_0));}
        else {
          break;}}}
    whileStmtLabel_1: ;
    if (0 <= lastStd_0){
      string_0_sysvq0asl rel_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      j_0 = lastStd_0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_460 = len_4_sysvq0asl(path_1);
          if (j_0 < X60Qx_460){
            NC8 X60Qx_461 = getQ_9_sysvq0asl(path_1, j_0);
            if (X60Qx_461 == (NC8)'\\'){
              add_1_sysvq0asl((&rel_0), (NC8)'/');}
            else {
              NC8 X60Qx_462 = getQ_9_sysvq0asl(path_1, j_0);
              add_1_sysvq0asl((&rel_0), X60Qx_462);}
            inc_1_I6wjjge_aow2h993l1((&j_0));}
          else {
            break;}}}
      whileStmtLabel_2: ;
      string_0_sysvq0asl X60Qtmp_75 = stdlibSuffixOf_0_runot4689(rel_0);
      NB8 X60Qx_463 = eqQ_20_sysvq0asl(X60Qtmp_75, suffix_2);
      answer_0 = X60Qx_463;
      nimStrDestroy(X60Qtmp_75);
      nimStrDestroy(rel_0);}}
  string_0_sysvq0asl X60Qx_464 = nimStrDup(suffix_2);
  add_0_Ig6072n_aow7lb5cq1((&gModSuffixSeen_0_runot4689), X60Qx_464);
  add_0_Irnc3p1_aow7lb5cq1((&gModSuffixStd_0_runot4689), answer_0);
  result_41 = answer_0;
  nimStrDestroy(path_1);
  return result_41;
  nimStrDestroy(path_1);
  return result_41;}
NU32 instantiationOrigin_0_runot4689(NU32 sym_2){
  NU32 result_42;
  result_42 = ((NU32)0u);
  LoadResult_0_prorcx25w1 res_3 = tryLoadSymSafe_0_modzy18mg1(sym_2);
  NB8 X60Qx_465;
  if ((!(res_3.status_0 == 3))){
    X60Qx_465 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_466 = kind_0_nifb6mq6y1(res_3.decl_0);
    X60Qx_465 = (!(X60Qx_466 == 11));}
  if (X60Qx_465){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_3);
    return result_42;}
  NimonySym_0_nimry5ra91 X60Qx_467 = symKind_0_nim30udrv(res_3.decl_0);
  NB8 X60Qx_468 = isRoutine_0_decqocs071(X60Qx_467);
  if ((!X60Qx_468)){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_3);
    return result_42;}
  Routine_0_decqocs071 X60Qtmp_76 = asRoutine_0_decqocs071(res_3.decl_0, 1);
  Cursor_0_nifb6mq6y1 tv_0 = eQdup_0_nifb6mq6y1(X60Qtmp_76.typevars_0);
  NifKind_0_nif81dubp1 X60Qx_469 = kind_0_nifb6mq6y1(tv_0);
  if ((!(X60Qx_469 == 11))){
    eQdestroy_0_nifb6mq6y1((&tv_0));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&X60Qtmp_76));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_3);
    return result_42;}
  inc_0_nifb6mq6y1((&tv_0));
  NifKind_0_nif81dubp1 X60Qx_470 = kind_0_nifb6mq6y1(tv_0);
  if (X60Qx_470 == 4){
    NU32 X60Qx_471 = symId_0_nifb6mq6y1(tv_0);
    result_42 = X60Qx_471;}
  eQdestroy_0_nifb6mq6y1((&tv_0));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&X60Qtmp_76));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_3);
  return result_42;
  eQdestroy_0_nifb6mq6y1((&tv_0));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&X60Qtmp_76));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_3);
  return result_42;}
NB8 nativeProvidesSym_0_runot4689(NU32 sym_3){
  NB8 result_43;
  NU32 s_17 = sym_3;
  NI32 hops_0 = 0;
  {
    while (hops_0 < 8){
      inc_1_I6wjjge_aow2h993l1((&hops_0));
      string_0_sysvq0asl* X60Qx_472 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_17);
      NB8 X60Qx_473 = isInstantiation_0_symkyk35i1((*X60Qx_472));
      if (X60Qx_473){
        NU32 origin_0 = instantiationOrigin_0_runot4689(s_17);
        NB8 X60Qx_474;
        NB8 X60Qx_475 = eqQ_0_nifh7u8pu1(origin_0, ((NU32)0u));
        if (X60Qx_475){
          X60Qx_474 = NIM_TRUE;}
        else {
          NB8 X60Qx_476 = eqQ_0_nifh7u8pu1(origin_0, s_17);
          X60Qx_474 = X60Qx_476;}
        if (X60Qx_474){
          return NIM_TRUE;}
        s_17 = origin_0;}
      else {
        string_0_sysvq0asl X60Qtmp_77 = trueModuleOf_0_runot4689(s_17);
        NB8 X60Qx_477 = moduleIsStdlib_0_runot4689(X60Qtmp_77);
        result_43 = X60Qx_477;
        nimStrDestroy(X60Qtmp_77);
        return result_43;
        nimStrDestroy(X60Qtmp_77);}}}
  whileStmtLabel_0: ;
  result_43 = NIM_TRUE;
  return result_43;}
NU32 objBaseSym_0_runot4689(NU32 typeSym_0){
  NU32 result_44;
  result_44 = ((NU32)0u);
  LoadResult_0_prorcx25w1 res_4 = tryLoadSymSafe_0_modzy18mg1(typeSym_0);
  if ((!(res_4.status_0 == 3))){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
    return result_44;}
  Cursor_0_nifb6mq6y1 d_0 = res_4.decl_0;
  eQwasMoved_0_nifb6mq6y1((&res_4.decl_0));
  NifKind_0_nif81dubp1 X60Qx_478 = kind_0_nifb6mq6y1(d_0);
  if ((!(X60Qx_478 == 11))){
    eQdestroy_0_nifb6mq6y1((&d_0));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
    return result_44;}
  inc_0_nifb6mq6y1((&d_0));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_479 = kind_0_nifb6mq6y1(d_0);
      if ((!(X60Qx_479 == 12))){
        NB8 X60Qx_122;
        NifKind_0_nif81dubp1 X60Qx_480 = kind_0_nifb6mq6y1(d_0);
        if (X60Qx_480 == 11){
          string_0_sysvq0asl X60Qtmp_78 = nodeTag_0_runot4689(d_0);
          NB8 X60Qx_481 = eqQ_20_sysvq0asl(X60Qtmp_78, (string_0_sysvq0asl){
            .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
          );
          X60Qx_122 = X60Qx_481;
          nimStrDestroy(X60Qtmp_78);}
        else {
          X60Qx_122 = NIM_FALSE;}
        if (X60Qx_122){
          inc_0_nifb6mq6y1((&d_0));
          NifKind_0_nif81dubp1 X60Qx_482 = kind_0_nifb6mq6y1(d_0);
          if (X60Qx_482 == 4){
            NU32 X60Qx_483 = symId_0_nifb6mq6y1(d_0);
            result_44 = X60Qx_483;}
          else {
            NB8 X60Qx_123;
            NifKind_0_nif81dubp1 X60Qx_484 = kind_0_nifb6mq6y1(d_0);
            if (X60Qx_484 == 11){
              NB8 X60Qx_124;
              string_0_sysvq0asl X60Qtmp_79 = nodeTag_0_runot4689(d_0);
              NB8 X60Qx_485 = eqQ_20_sysvq0asl(X60Qtmp_79, (string_0_sysvq0asl){
                .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
              );
              if (X60Qx_485){
                X60Qx_124 = NIM_TRUE;}
              else {
                string_0_sysvq0asl X60Qtmp_80 = nodeTag_0_runot4689(d_0);
                NB8 X60Qx_486 = eqQ_20_sysvq0asl(X60Qtmp_80, (string_0_sysvq0asl){
                  .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
                );
                X60Qx_124 = X60Qx_486;
                nimStrDestroy(X60Qtmp_80);}
              X60Qx_123 = X60Qx_124;
              nimStrDestroy(X60Qtmp_79);}
            else {
              X60Qx_123 = NIM_FALSE;}
            if (X60Qx_123){
              inc_0_nifb6mq6y1((&d_0));
              NifKind_0_nif81dubp1 X60Qx_487 = kind_0_nifb6mq6y1(d_0);
              if (X60Qx_487 == 4){
                NU32 X60Qx_488 = symId_0_nifb6mq6y1(d_0);
                result_44 = X60Qx_488;}}}
          eQdestroy_0_nifb6mq6y1((&d_0));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
          return result_44;}
        else {
          NB8 X60Qx_125;
          NifKind_0_nif81dubp1 X60Qx_489 = kind_0_nifb6mq6y1(d_0);
          if (X60Qx_489 == 11){
            string_0_sysvq0asl X60Qtmp_81 = nodeTag_0_runot4689(d_0);
            NB8 X60Qx_490 = eqQ_20_sysvq0asl(X60Qtmp_81, (string_0_sysvq0asl){
              .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
            );
            X60Qx_125 = X60Qx_490;
            nimStrDestroy(X60Qtmp_81);}
          else {
            X60Qx_125 = NIM_FALSE;}
          if (X60Qx_125){
            Cursor_0_nifb6mq6y1 cc_0 = d_0;
            eQwasMoved_0_nifb6mq6y1((&d_0));
            inc_0_nifb6mq6y1((&cc_0));
            NifKind_0_nif81dubp1 X60Qx_491 = kind_0_nifb6mq6y1(cc_0);
            if (X60Qx_491 == 4){
              NU32 X60Qx_492 = symId_0_nifb6mq6y1(cc_0);
              result_44 = X60Qx_492;}
            eQdestroy_0_nifb6mq6y1((&cc_0));
            eQdestroy_0_nifb6mq6y1((&d_0));
            eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
            return result_44;
            eQdestroy_0_nifb6mq6y1((&cc_0));}
          else {
            NifKind_0_nif81dubp1 X60Qx_493 = kind_0_nifb6mq6y1(d_0);
            if (X60Qx_493 == 11){
              skip_0_nifb6mq6y1((&d_0));}
            else {
              inc_0_nifb6mq6y1((&d_0));}}}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&d_0));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
  return result_44;
  eQdestroy_0_nifb6mq6y1((&d_0));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
  return result_44;}
NB8 sliceHiIsBackwards_0_runot4689(NU32 typeSym_1){
  NB8 result_45;
  if (((NU32)typeSym_1) == ((NU32)0u)){
    return NIM_FALSE;}
  NI32 i_20 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_494 = len_3_Iktsa441_runot4689(gBackwardsHiCache_0_runot4689);
      if (i_20 < X60Qx_494){
        BwEntry_0_runot4689* X60Qx_495 = getQ_7_I1zo4u41_runot4689(gBackwardsHiCache_0_runot4689, i_20);
        NB8 X60Qx_496 = eqQ_0_nifh7u8pu1((*X60Qx_495).sym_0, typeSym_1);
        if (X60Qx_496){
          BwEntry_0_runot4689* X60Qx_497 = getQ_7_I1zo4u41_runot4689(gBackwardsHiCache_0_runot4689, i_20);
          result_45 = (*X60Qx_497).isBw_0;
          return result_45;}
        inc_1_I6wjjge_aow2h993l1((&i_20));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 found_5 = NIM_FALSE;
  LoadResult_0_prorcx25w1 res_5 = tryLoadSymSafe_0_modzy18mg1(typeSym_1);
  if (res_5.status_0 == 3){
    Cursor_0_nifb6mq6y1 d_1 = res_5.decl_0;
    eQwasMoved_0_nifb6mq6y1((&res_5.decl_0));
    NI32 nested_0 = 0;
    NI32 budget_0 = 0;
    {
      while (budget_0 < 4096){
        NifKind_0_nif81dubp1 X60Qx_498 = kind_0_nifb6mq6y1(d_1);
        if (X60Qx_498 == 11){
          inc_1_I6wjjge_aow2h993l1((&nested_0));}
        else {
          NifKind_0_nif81dubp1 X60Qx_499 = kind_0_nifb6mq6y1(d_1);
          if (X60Qx_499 == 12){
            dec_1_I0nzoz91_aow7lb5cq1((&nested_0));
            if (nested_0 <= 0){
              goto whileStmtLabel_1;}}
          else {
            NifKind_0_nif81dubp1 X60Qx_500 = kind_0_nifb6mq6y1(d_1);
            if (X60Qx_500 == 4){
              NU32 X60Qx_501 = symId_0_nifb6mq6y1(d_1);
              string_0_sysvq0asl* X60Qx_502 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, X60Qx_501);
              string_0_sysvq0asl nm_0 = nimStrDup((*X60Qx_502));
              extractBasename_1_symkyk35i1((&nm_0));
              NB8 X60Qx_503 = eqQ_20_sysvq0asl(nm_0, (string_0_sysvq0asl){
                .bytes_0 = 1667318526u, .more_0 = (&strlit_0_I17809097366158705854_runot4689)}
              );
              if (X60Qx_503){
                found_5 = NIM_TRUE;
                nimStrDestroy(nm_0);
                goto whileStmtLabel_1;}
              nimStrDestroy(nm_0);}}}
        inc_0_nifb6mq6y1((&d_1));
        inc_1_I6wjjge_aow2h993l1((&budget_0));}}
    whileStmtLabel_1: ;
    eQdestroy_0_nifb6mq6y1((&d_1));}
  add_0_Ifyely51_runot4689((&gBackwardsHiCache_0_runot4689), (BwEntry_0_runot4689){
    .sym_0 = typeSym_1, .isBw_0 = found_5}
  );
  result_45 = found_5;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_5);
  return result_45;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_5);
  return result_45;}
NB8 isGenericRoutine_0_runot4689(NU32 fn_0){
  NB8 result_46;
  LoadResult_0_prorcx25w1 res_6 = tryLoadSymSafe_0_modzy18mg1(fn_0);
  if ((!(res_6.status_0 == 3))){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
    return NIM_FALSE;}
  Routine_0_decqocs071 r_5 = asRoutine_0_decqocs071(res_6.decl_0, 0);
  NB8 X60Qx_504 = isGeneric_0_decqocs071((&r_5));
  result_46 = X60Qx_504;
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_5));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
  return result_46;
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_5));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
  return result_46;}
NB8 isSubtype_0_runot4689(NU32 concrete_0, NU32 target_0){
  NB8 result_47;
  NU32 cur_0 = concrete_0;
  NI32 depth_0 = 0;
  {
    while (depth_0 < 64){
      NB8 X60Qx_505 = eqQ_0_nifh7u8pu1(cur_0, target_0);
      if (X60Qx_505){
        return NIM_TRUE;}
      NU32 b_4 = objBaseSym_0_runot4689(cur_0);
      NB8 X60Qx_506;
      NB8 X60Qx_507 = eqQ_0_nifh7u8pu1(b_4, ((NU32)0u));
      if (X60Qx_507){
        X60Qx_506 = NIM_TRUE;}
      else {
        NB8 X60Qx_508 = eqQ_0_nifh7u8pu1(b_4, cur_0);
        X60Qx_506 = X60Qx_508;}
      if (X60Qx_506){
        return NIM_FALSE;}
      cur_0 = b_4;
      inc_1_I6wjjge_aow2h993l1((&depth_0));}}
  whileStmtLabel_0: ;
  result_47 = NIM_FALSE;
  return result_47;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* arcBlockPayload_0_runot4689(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_0){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* result_48;
  eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689((&result_48));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(result_48);
  result_48 = NIM_NIL;
  NB8 X60Qx_509;
  NB8 X60Qx_510;
  if (box_0 == NIM_NIL){
    X60Qx_510 = NIM_TRUE;}
  else {
    X60Qx_510 = (!((*box_0).d_00.names_0.len_0 == 2));}
  if (X60Qx_510){
    X60Qx_509 = NIM_TRUE;}
  else {
    X60Qx_509 = (!((*box_0).d_00.cells_0.len_0 == 2));}
  if (X60Qx_509){
    return result_48;}
  string_0_sysvq0asl* X60Qx_511 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*box_0).d_00.typeSym_0);
  string_0_sysvq0asl tn_0 = nimStrDup((*X60Qx_511));
  extractBasename_1_symkyk35i1((&tn_0));
  NB8 X60Qx_512;
  NI32 X60Qx_513 = len_4_sysvq0asl(tn_0);
  if (X60Qx_513 == 0){
    X60Qx_512 = NIM_TRUE;}
  else {
    NC8 X60Qx_514 = getQ_9_sysvq0asl(tn_0, 0);
    X60Qx_512 = (!(X60Qx_514 == (NC8)'`'));}
  if (X60Qx_512){
    nimStrDestroy(tn_0);
    return result_48;}
  NU32* X60Qx_515 = getQ_7_I2v00yv1_arecyyj7v((*box_0).d_00.names_0, 0);
  string_0_sysvq0asl* X60Qx_516 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*X60Qx_515));
  string_0_sysvq0asl n0_0 = nimStrDup((*X60Qx_516));
  extractBasename_1_symkyk35i1((&n0_0));
  NB8 X60Qx_517 = eqQ_20_sysvq0asl(n0_0, (string_0_sysvq0asl){
    .bytes_0 = 29185u, .more_0 = NIM_NIL}
  );
  if ((!X60Qx_517)){
    nimStrDestroy(n0_0);
    nimStrDestroy(tn_0);
    return result_48;}
  NU32* X60Qx_518 = getQ_7_I2v00yv1_arecyyj7v((*box_0).d_00.names_0, 1);
  string_0_sysvq0asl* X60Qx_519 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*X60Qx_518));
  string_0_sysvq0asl n1_0 = nimStrDup((*X60Qx_519));
  extractBasename_1_symkyk35i1((&n1_0));
  NB8 X60Qx_520 = eqQ_20_sysvq0asl(n1_0, (string_0_sysvq0asl){
    .bytes_0 = 25601u, .more_0 = NIM_NIL}
  );
  if ((!X60Qx_520)){
    nimStrDestroy(n1_0);
    nimStrDestroy(n0_0);
    nimStrDestroy(tn_0);
    return result_48;}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_521 = getQ_7_Ii14ync1_arecyyj7v((*box_0).d_00.cells_0, 1);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* payload_0 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_521));
  if (payload_0 == NIM_NIL){
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(payload_0);
    nimStrDestroy(n1_0);
    nimStrDestroy(n0_0);
    nimStrDestroy(tn_0);
    return result_48;}
  NB8 X60Qx_522;
  if ((*payload_0).d_00.v_0.kind_0 == 11){
    X60Qx_522 = NIM_TRUE;}
  else {
    X60Qx_522 = ((*payload_0).d_00.v_0.kind_0 == 10);}
  if (X60Qx_522){
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(result_48);
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_523 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689((*payload_0).d_00.v_0.obj_0);
    result_48 = X60Qx_523;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(payload_0);
  nimStrDestroy(n1_0);
  nimStrDestroy(n0_0);
  nimStrDestroy(tn_0);
  return result_48;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(payload_0);
  nimStrDestroy(n1_0);
  nimStrDestroy(n0_0);
  nimStrDestroy(tn_0);
  return result_48;}
NU32 objTypeOf_0_runot4689(Value_0_valzr1t4f* v_18){
  NU32 result_49;
  switch ((*v_18).kind_0){
    case 11:
    case 10:
    {
      if ((!((*v_18).obj_0 == NIM_NIL))){
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* inner_0 = arcBlockPayload_0_runot4689((*v_18).obj_0);
        NU32 X60Qx_8;
        if ((!(inner_0 == NIM_NIL))){
          X60Qx_8 = (*inner_0).d_00.typeSym_0;}
        else {
          X60Qx_8 = (*(*v_18).obj_0).d_00.typeSym_0;}
        result_49 = X60Qx_8;
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(inner_0);}
      else {
        result_49 = ((NU32)0u);}}
    break;
    case 12:
    {
      NB8 X60Qx_524;
      NB8 X60Qx_525;
      if ((!((*v_18).rf_0 == NIM_NIL))){
        NB8 X60Qx_526;
        if ((*(*v_18).rf_0).d_00.v_0.kind_0 == 11){
          X60Qx_526 = NIM_TRUE;}
        else {
          X60Qx_526 = ((*(*v_18).rf_0).d_00.v_0.kind_0 == 10);}
        X60Qx_525 = X60Qx_526;}
      else {
        X60Qx_525 = NIM_FALSE;}
      if (X60Qx_525){
        X60Qx_524 = (!((*(*v_18).rf_0).d_00.v_0.obj_0 == NIM_NIL));}
      else {
        X60Qx_524 = NIM_FALSE;}
      if (X60Qx_524){
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* inner_1 = arcBlockPayload_0_runot4689((*(*v_18).rf_0).d_00.v_0.obj_0);
        NU32 X60Qx_9;
        if ((!(inner_1 == NIM_NIL))){
          X60Qx_9 = (*inner_1).d_00.typeSym_0;}
        else {
          X60Qx_9 = (*(*(*v_18).rf_0).d_00.v_0.obj_0).d_00.typeSym_0;}
        result_49 = X60Qx_9;
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(inner_1);}
      else {
        result_49 = ((NU32)0u);}}
    break;
    case 13:
    {
      if ((!((*v_18).loc_0 == NIM_NIL))){
        NU32 X60Qx_527 = objTypeOf_0_runot4689((&(*(*v_18).loc_0).d_00.v_0));
        result_49 = X60Qx_527;}
      else {
        result_49 = ((NU32)0u);}}
    break;
    default:
    {
      result_49 = ((NU32)0u);}
    break;}
  return result_49;}
Value_0_valzr1t4f zeroObject_0_runot4689(Cursor_0_nifb6mq6y1 objNode_0, NU32 typeSym_2){
  Value_0_valzr1t4f result_50;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
  void* X60Qx_528 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_82 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_528);
  seq_0_In6doa_arecyyj7v X60Qx_529 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_530 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  (*X60Qtmp_82) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
      .typeSym_0 = typeSym_2, .names_0 = X60Qx_529, .cells_0 = X60Qx_530}}
  ;
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* ob_0 = X60Qtmp_82;
  Cursor_0_nifb6mq6y1 c_11 = eQdup_0_nifb6mq6y1(objNode_0);
  inc_0_nifb6mq6y1((&c_11));
  NifKind_0_nif81dubp1 X60Qx_531 = kind_0_nifb6mq6y1(c_11);
  if (X60Qx_531 == 4){
    Value_0_valzr1t4f baseVal_0 = defaultForType_1_runot4689(c_11);
    NB8 X60Qx_532;
    NB8 X60Qx_533;
    if (baseVal_0.kind_0 == 11){
      X60Qx_533 = NIM_TRUE;}
    else {
      X60Qx_533 = (baseVal_0.kind_0 == 10);}
    if (X60Qx_533){
      X60Qx_532 = (!(baseVal_0.obj_0 == NIM_NIL));}
    else {
      X60Qx_532 = NIM_FALSE;}
    if (X60Qx_532){
      NI32 i_23 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_534 = len_3_I6y2imo_arecyyj7v((*baseVal_0.obj_0).d_00.names_0);
          if (i_23 < X60Qx_534){
            NU32* X60Qx_535 = getQ_7_I2v00yv1_arecyyj7v((*baseVal_0.obj_0).d_00.names_0, i_23);
            add_0_I34il1q_der823rwr1((&(*ob_0).d_00.names_0), (*X60Qx_535));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_536 = getQ_7_Ii14ync1_arecyyj7v((*baseVal_0.obj_0).d_00.cells_0, i_23);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_537 = newCell_0_valzr1t4f((&(*(*X60Qx_536)).d_00.v_0));
            add_0_Ijpw0mu_flaksyopx1((&(*ob_0).d_00.cells_0), X60Qx_537);
            inc_1_I6wjjge_aow2h993l1((&i_23));}
          else {
            break;}}}
      whileStmtLabel_0: ;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&baseVal_0));}
  skip_0_nifb6mq6y1((&c_11));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_538 = kind_0_nifb6mq6y1(c_11);
      if ((!(X60Qx_538 == 12))){
        NB8 X60Qx_126;
        NifKind_0_nif81dubp1 X60Qx_539 = kind_0_nifb6mq6y1(c_11);
        if (X60Qx_539 == 11){
          string_0_sysvq0asl X60Qtmp_83 = nodeTag_0_runot4689(c_11);
          NB8 X60Qx_540 = eqQ_20_sysvq0asl(X60Qtmp_83, (string_0_sysvq0asl){
            .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
          );
          X60Qx_126 = X60Qx_540;
          nimStrDestroy(X60Qtmp_83);}
        else {
          X60Qx_126 = NIM_FALSE;}
        if (X60Qx_126){
          Cursor_0_nifb6mq6y1 f_1 = eQdup_0_nifb6mq6y1(c_11);
          inc_0_nifb6mq6y1((&f_1));
          NU32 nameSym_0 = ((NU32)0u);
          NB8 X60Qx_541;
          NifKind_0_nif81dubp1 X60Qx_542 = kind_0_nifb6mq6y1(f_1);
          if (X60Qx_542 == 4){
            X60Qx_541 = NIM_TRUE;}
          else {
            NifKind_0_nif81dubp1 X60Qx_543 = kind_0_nifb6mq6y1(f_1);
            X60Qx_541 = (X60Qx_543 == 5);}
          if (X60Qx_541){
            NU32 X60Qx_544 = symId_0_nifb6mq6y1(f_1);
            nameSym_0 = X60Qx_544;}
          skip_0_nifb6mq6y1((&f_1));
          skip_0_nifb6mq6y1((&f_1));
          skip_0_nifb6mq6y1((&f_1));
          add_0_I34il1q_der823rwr1((&(*ob_0).d_00.names_0), nameSym_0);
          Value_0_valzr1t4f X60Qtmp_84 = defaultForType_1_runot4689(f_1);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_545 = newCell_0_valzr1t4f((&X60Qtmp_84));
          add_0_Ijpw0mu_flaksyopx1((&(*ob_0).d_00.cells_0), X60Qx_545);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_84));
          eQdestroy_0_nifb6mq6y1((&f_1));}
        skip_0_nifb6mq6y1((&c_11));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_85 = ob_0;
  eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689((&ob_0));
  result_50 = (Value_0_valzr1t4f){
    .kind_0 = 11, .obj_0 = X60Qtmp_85}
  ;
  eQdestroy_0_nifb6mq6y1((&c_11));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(ob_0);
  return result_50;
  eQdestroy_0_nifb6mq6y1((&c_11));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(ob_0);
  return result_50;}
Value_0_valzr1t4f defaultForType_1_runot4689(Cursor_0_nifb6mq6y1 typ_2){
  Value_0_valzr1t4f result_51;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_51));
  Cursor_0_nifb6mq6y1 t_6 = eQdup_0_nifb6mq6y1(typ_2);
  NifKind_0_nif81dubp1 X60Qx_546 = kind_0_nifb6mq6y1(t_6);
  if (X60Qx_546 == 4){
    NU32 sym_4 = symId_0_nifb6mq6y1(t_6);
    {
      string_0_sysvq0asl* X60Qx_547 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_4);
      string_0_sysvq0asl bn_2 = nimStrDup((*X60Qx_547));
      extractBasename_1_symkyk35i1((&bn_2));
      NB8 X60Qx_548 = eqQ_20_sysvq0asl(bn_2, (string_0_sysvq0asl){
        .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
      );
      if (X60Qx_548){
        Value_0_valzr1t4f X60Qx_549 = emptySeqVal_0_runot4689();
        result_51 = X60Qx_549;
        nimStrDestroy(bn_2);
        eQdestroy_0_nifb6mq6y1((&t_6));
        return result_51;}
      else {
        NB8 X60Qx_550 = eqQ_20_sysvq0asl(bn_2, (string_0_sysvq0asl){
          .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
        );
        if (X60Qx_550){
          Value_0_valzr1t4f X60Qx_551 = vStr_0_valzr1t4f((string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          );
          result_51 = X60Qx_551;
          nimStrDestroy(bn_2);
          eQdestroy_0_nifb6mq6y1((&t_6));
          return result_51;}}
      nimStrDestroy(bn_2);}
    X60Qlab_0: ;
    LoadResult_0_prorcx25w1 res_7 = tryLoadSymSafe_0_modzy18mg1(sym_4);
    NB8 X60Qx_127;
    NB8 X60Qx_552;
    if (res_7.status_0 == 3){
      NifKind_0_nif81dubp1 X60Qx_553 = kind_0_nifb6mq6y1(res_7.decl_0);
      X60Qx_552 = (X60Qx_553 == 11);}
    else {
      X60Qx_552 = NIM_FALSE;}
    if (X60Qx_552){
      string_0_sysvq0asl X60Qtmp_86 = nodeTag_0_runot4689(res_7.decl_0);
      NB8 X60Qx_554 = eqQ_20_sysvq0asl(X60Qtmp_86, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
      );
      X60Qx_127 = X60Qx_554;
      nimStrDestroy(X60Qtmp_86);}
    else {
      X60Qx_127 = NIM_FALSE;}
    if (X60Qx_127){
      Cursor_0_nifb6mq6y1 d_2 = res_7.decl_0;
      eQwasMoved_0_nifb6mq6y1((&res_7.decl_0));
      inc_0_nifb6mq6y1((&d_2));
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_555 = kind_0_nifb6mq6y1(d_2);
          if ((!(X60Qx_555 == 12))){
            NifKind_0_nif81dubp1 X60Qx_556 = kind_0_nifb6mq6y1(d_2);
            if (X60Qx_556 == 11){
              string_0_sysvq0asl X60Qtmp_87 = nodeTag_0_runot4689(d_2);
              NB8 X60Qtc_102 = nimStrAtLe_0_sysvq0asl(X60Qtmp_87, 1, (NC8)'o');
              if (X60Qtc_102){
                NB8 X60Qtc_103 = nimStrAtLe_0_sysvq0asl(X60Qtmp_87, 0, (NC8)'o');
                if (X60Qtc_103){
                  NB8 X60Qtc_104 = nimStrAtLe_0_sysvq0asl(X60Qtmp_87, 0, (NC8)'e');
                  if (X60Qtc_104){
                    NB8 X60Qtc_105 = nimStrAtLe_0_sysvq0asl(X60Qtmp_87, 0, (NC8)'d');
                    if (X60Qtc_105){
                      if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                        .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_fiepkwzpc)}
                      )){
                        goto X60Qsc_100;}
                      else if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                        .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
                      )){
                        goto X60Qsc_101;}}
                    else {
                      if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                        .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
                      )){
                        goto X60Qsc_99;}}}
                  else {
                    if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
                    )){
                      goto X60Qsc_98;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_fiepkwzpc)}
                    )){
                      goto X60Qsc_99;}}}
                else {
                  NB8 X60Qtc_106 = nimStrAtLe_0_sysvq0asl(X60Qtmp_87, 0, (NC8)'r');
                  if (X60Qtc_106){
                    if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I6300154543333844069_intzsnzax)}
                    )){
                      goto X60Qsc_101;}}
                  else {
                    if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 1952805635u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}}}}
              else {
                NB8 X60Qtc_107 = nimStrAtLe_0_sysvq0asl(X60Qtmp_87, 0, (NC8)'i');
                if (X60Qtc_107){
                  NB8 X60Qtc_108 = nimStrAtLe_0_sysvq0asl(X60Qtmp_87, 0, (NC8)'c');
                  if (X60Qtc_108){
                    NB8 X60Qtc_109 = nimStrAtLe_0_sysvq0asl(X60Qtmp_87, 0, (NC8)'a');
                    if (X60Qtc_109){
                      if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
                      )){
                        goto X60Qsc_101;}}
                    else {
                      if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                        .bytes_0 = 25345u, .more_0 = NIM_NIL}
                      )){
                        goto X60Qsc_101;}
                      else if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                        .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
                      )){
                        goto X60Qsc_101;}}}
                  else {
                    if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 26881u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 26113u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}}}
                else {
                  NB8 X60Qtc_110 = nimStrAtLe_0_sysvq0asl(X60Qtmp_87, 0, (NC8)'s');
                  if (X60Qtc_110){
                    if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}}
                  else {
                    if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 29953u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
                    )){
                      goto X60Qsc_101;}}}}
              goto X60Qsc_112;
              X60Qsc_98: ;
              Value_0_valzr1t4f X60Qx_557 = zeroObject_0_runot4689(d_2, sym_4);
              result_51 = X60Qx_557;
              nimStrDestroy(X60Qtmp_87);
              eQdestroy_0_nifb6mq6y1((&d_2));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
              eQdestroy_0_nifb6mq6y1((&t_6));
              return result_51;
              goto X60Qsc_111;
              X60Qsc_99: ;
              Value_0_valzr1t4f X60Qx_558 = vEnum_0_valzr1t4f(0, sym_4);
              result_51 = X60Qx_558;
              nimStrDestroy(X60Qtmp_87);
              eQdestroy_0_nifb6mq6y1((&d_2));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
              eQdestroy_0_nifb6mq6y1((&t_6));
              return result_51;
              goto X60Qsc_111;
              X60Qsc_100: ;
              Cursor_0_nifb6mq6y1 b_5 = d_2;
              eQwasMoved_0_nifb6mq6y1((&d_2));
              inc_0_nifb6mq6y1((&b_5));
              Value_0_valzr1t4f X60Qx_559 = defaultForType_1_runot4689(b_5);
              result_51 = X60Qx_559;
              eQdestroy_0_nifb6mq6y1((&b_5));
              nimStrDestroy(X60Qtmp_87);
              eQdestroy_0_nifb6mq6y1((&d_2));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
              eQdestroy_0_nifb6mq6y1((&t_6));
              return result_51;
              eQdestroy_0_nifb6mq6y1((&b_5));
              goto X60Qsc_111;
              X60Qsc_101: ;
              Value_0_valzr1t4f X60Qx_560 = defaultForType_1_runot4689(d_2);
              result_51 = X60Qx_560;
              nimStrDestroy(X60Qtmp_87);
              eQdestroy_0_nifb6mq6y1((&d_2));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
              eQdestroy_0_nifb6mq6y1((&t_6));
              return result_51;
              goto X60Qsc_111;
              X60Qsc_112: ;
              X60Qsc_111: ;
              nimStrDestroy(X60Qtmp_87);}
            skip_0_nifb6mq6y1((&d_2));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      Value_0_valzr1t4f X60Qx_561 = vNil_0_valzr1t4f();
      result_51 = X60Qx_561;
      eQdestroy_0_nifb6mq6y1((&d_2));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      eQdestroy_0_nifb6mq6y1((&d_2));}
    else {
      string_0_sysvq0asl* X60Qx_562 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_4);
      string_0_sysvq0asl s_24 = nimStrDup((*X60Qx_562));
      extractBasename_1_symkyk35i1((&s_24));
      NB8 X60Qx_563 = eqQ_20_sysvq0asl(s_24, (string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
      );
      if (X60Qx_563){
        Value_0_valzr1t4f X60Qx_564 = vStr_0_valzr1t4f((string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        );
        result_51 = X60Qx_564;
        nimStrDestroy(s_24);
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
        eQdestroy_0_nifb6mq6y1((&t_6));
        return result_51;}
      else {
        NB8 X60Qx_565 = eqQ_20_sysvq0asl(s_24, (string_0_sysvq0asl){
          .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
        );
        if (X60Qx_565){
          Value_0_valzr1t4f X60Qx_566 = emptySeqVal_0_runot4689();
          result_51 = X60Qx_566;
          nimStrDestroy(s_24);
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
          eQdestroy_0_nifb6mq6y1((&t_6));
          return result_51;}}
      Value_0_valzr1t4f X60Qx_567 = vNil_0_valzr1t4f();
      result_51 = X60Qx_567;
      nimStrDestroy(s_24);
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      nimStrDestroy(s_24);}
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);}
  else {
    NifKind_0_nif81dubp1 X60Qx_568 = kind_0_nifb6mq6y1(t_6);
    if (X60Qx_568 == 11){
      string_0_sysvq0asl X60Qtmp_88 = nodeTag_0_runot4689(t_6);
      NB8 X60Qtc_124 = nimStrAtLe_0_sysvq0asl(X60Qtmp_88, 0, (NC8)'n');
      if (X60Qtc_124){
        NB8 X60Qtc_125 = nimStrAtLe_0_sysvq0asl(X60Qtmp_88, 0, (NC8)'c');
        if (X60Qtc_125){
          NB8 X60Qtc_126 = nimStrAtLe_0_sysvq0asl(X60Qtmp_88, 0, (NC8)'b');
          if (X60Qtc_126){
            if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
            )){
              goto X60Qsc_116;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
            )){
              goto X60Qsc_122;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 25345u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_117;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
            )){
              goto X60Qsc_118;}}}
        else {
          NB8 X60Qtc_127 = nimStrAtLe_0_sysvq0asl(X60Qtmp_88, 0, (NC8)'i');
          if (X60Qtc_127){
            if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 26881u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_113;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 26113u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_115;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1818849022u, .more_0 = (&strlit_0_I14845240230376595005_buiyylk1h1)}
            )){
              goto X60Qsc_121;}}}}
      else {
        NB8 X60Qtc_128 = nimStrAtLe_0_sysvq0asl(X60Qtmp_88, 1, (NC8)'o');
        if (X60Qtc_128){
          NB8 X60Qtc_129 = nimStrAtLe_0_sysvq0asl(X60Qtmp_88, 0, (NC8)'r');
          if (X60Qtc_129){
            if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_121;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I6300154543333844069_intzsnzax)}
            )){
              goto X60Qsc_121;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_119;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1952805635u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_120;}}}
        else {
          NB8 X60Qtc_130 = nimStrAtLe_0_sysvq0asl(X60Qtmp_88, 0, (NC8)'s');
          if (X60Qtc_130){
            if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
            )){
              goto X60Qsc_118;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_121;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 29953u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_114;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
            )){
              goto X60Qsc_123;}}}}
      goto X60Qsc_132;
      X60Qsc_113: ;
      Value_0_valzr1t4f X60Qx_569 = vInt_0_valzr1t4f(((NI64)0), 64);
      result_51 = X60Qx_569;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      goto X60Qsc_131;
      X60Qsc_114: ;
      Value_0_valzr1t4f X60Qx_570 = vUInt_0_valzr1t4f(((NU64)0), 64);
      result_51 = X60Qx_570;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      goto X60Qsc_131;
      X60Qsc_115: ;
      Value_0_valzr1t4f X60Qx_571 = vFloat_0_valzr1t4f(0.0, 64);
      result_51 = X60Qx_571;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      goto X60Qsc_131;
      X60Qsc_116: ;
      Value_0_valzr1t4f X60Qx_572 = vBool_0_valzr1t4f(NIM_FALSE);
      result_51 = X60Qx_572;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      goto X60Qsc_131;
      X60Qsc_117: ;
      Value_0_valzr1t4f X60Qx_573 = vChar_0_valzr1t4f((NC8)'\000');
      result_51 = X60Qx_573;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      goto X60Qsc_131;
      X60Qsc_118: ;
      Value_0_valzr1t4f X60Qx_574 = vStr_0_valzr1t4f((string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      );
      result_51 = X60Qx_574;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      goto X60Qsc_131;
      X60Qsc_119: ;
      Value_0_valzr1t4f X60Qx_575 = emptySeqVal_0_runot4689();
      result_51 = X60Qx_575;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      goto X60Qsc_131;
      X60Qsc_120: ;
      void* X60Qx_576 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax));
      X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* X60Qtmp_89 = ((X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax*)X60Qx_576);
      X60Qt_0_IAarrayAuS64ZS4_intzsnzax X60Qx_577 = default_23_I3gf93w_runot4689();
      (*X60Qtmp_89) = (X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax){
        .r_00 = 0, .d_00 = (SetBox_Obj_0_valzr1t4f){
          .words_0 = X60Qx_577}}
      ;
      result_51 = (Value_0_valzr1t4f){
        .kind_0 = 14, .st_0 = X60Qtmp_89}
      ;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      goto X60Qsc_131;
      X60Qsc_121: ;
      Value_0_valzr1t4f X60Qx_578 = vNil_0_valzr1t4f();
      result_51 = X60Qx_578;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      goto X60Qsc_131;
      X60Qsc_122: ;
      Cursor_0_nifb6mq6y1 c_12 = t_6;
      eQwasMoved_0_nifb6mq6y1((&t_6));
      inc_0_nifb6mq6y1((&c_12));
      Cursor_0_nifb6mq6y1 elemCur_0 = eQdup_0_nifb6mq6y1(c_12);
      skip_0_nifb6mq6y1((&c_12));
      NI32 lo_0 = 0;
      NI32 hi_0 = -1;
      NB8 X60Qx_128;
      NifKind_0_nif81dubp1 X60Qx_579 = kind_0_nifb6mq6y1(c_12);
      if (X60Qx_579 == 11){
        string_0_sysvq0asl X60Qtmp_90 = nodeTag_0_runot4689(c_12);
        NB8 X60Qx_580 = eqQ_20_sysvq0asl(X60Qtmp_90, (string_0_sysvq0asl){
          .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16393544569146403439_intzsnzax)}
        );
        X60Qx_128 = X60Qx_580;
        nimStrDestroy(X60Qtmp_90);}
      else {
        X60Qx_128 = NIM_FALSE;}
      if (X60Qx_128){
        Cursor_0_nifb6mq6y1 r_6 = c_12;
        eQwasMoved_0_nifb6mq6y1((&c_12));
        inc_0_nifb6mq6y1((&r_6));
        skip_0_nifb6mq6y1((&r_6));
        NifKind_0_nif81dubp1 X60Qx_581 = kind_0_nifb6mq6y1(r_6);
        if (X60Qx_581 == 8){
          NU32 X60Qx_582 = intId_0_nifb6mq6y1(r_6);
          NI64* X60Qx_583 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_582);
          lo_0 = ((NI32)(*X60Qx_583));}
        skip_0_nifb6mq6y1((&r_6));
        NifKind_0_nif81dubp1 X60Qx_584 = kind_0_nifb6mq6y1(r_6);
        if (X60Qx_584 == 8){
          NU32 X60Qx_585 = intId_0_nifb6mq6y1(r_6);
          NI64* X60Qx_586 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_585);
          hi_0 = ((NI32)(*X60Qx_586));}
        eQdestroy_0_nifb6mq6y1((&r_6));}
      void* X60Qx_587 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_91 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_587);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_588 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_91) = (X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (ArrBox_Obj_0_valzr1t4f){
          .elems_0 = X60Qx_588, .lo_0 = lo_0, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
      ;
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* ab_0 = X60Qtmp_91;
      NI32 i_24 = lo_0;
      {
        while (i_24 <= hi_0){
          Value_0_valzr1t4f X60Qtmp_92 = defaultForType_1_runot4689(elemCur_0);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_589 = newCell_0_valzr1t4f((&X60Qtmp_92));
          add_0_Ijpw0mu_flaksyopx1((&(*ab_0).d_00.elems_0), X60Qx_589);
          inc_1_I6wjjge_aow2h993l1((&i_24));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_92));}}
      whileStmtLabel_2: ;
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_93 = ab_0;
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689((&ab_0));
      result_51 = (Value_0_valzr1t4f){
        .kind_0 = 9, .arr_0 = X60Qtmp_93}
      ;
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(ab_0);
      eQdestroy_0_nifb6mq6y1((&elemCur_0));
      eQdestroy_0_nifb6mq6y1((&c_12));
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(ab_0);
      eQdestroy_0_nifb6mq6y1((&elemCur_0));
      eQdestroy_0_nifb6mq6y1((&c_12));
      goto X60Qsc_131;
      X60Qsc_123: ;
      Cursor_0_nifb6mq6y1 c_13 = t_6;
      eQwasMoved_0_nifb6mq6y1((&t_6));
      inc_0_nifb6mq6y1((&c_13));
      void* X60Qx_590 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_94 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_590);
      seq_0_In6doa_arecyyj7v X60Qx_591 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_592 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_94) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
          .typeSym_0 = ((NU32)0u), .names_0 = X60Qx_591, .cells_0 = X60Qx_592}}
      ;
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* ob_1 = X60Qtmp_94;
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_593 = kind_0_nifb6mq6y1(c_13);
          if ((!(X60Qx_593 == 12))){
            NB8 X60Qx_129;
            NifKind_0_nif81dubp1 X60Qx_594 = kind_0_nifb6mq6y1(c_13);
            if (X60Qx_594 == 11){
              string_0_sysvq0asl X60Qtmp_95 = nodeTag_0_runot4689(c_13);
              NB8 X60Qx_595 = eqQ_20_sysvq0asl(X60Qtmp_95, (string_0_sysvq0asl){
                .bytes_0 = 7760642u, .more_0 = NIM_NIL}
              );
              X60Qx_129 = X60Qx_595;
              nimStrDestroy(X60Qtmp_95);}
            else {
              X60Qx_129 = NIM_FALSE;}
            if (X60Qx_129){
              Cursor_0_nifb6mq6y1 k_4 = eQdup_0_nifb6mq6y1(c_13);
              inc_0_nifb6mq6y1((&k_4));
              NU32 nameSym_1 = ((NU32)0u);
              NB8 X60Qx_596;
              NifKind_0_nif81dubp1 X60Qx_597 = kind_0_nifb6mq6y1(k_4);
              if (X60Qx_597 == 4){
                X60Qx_596 = NIM_TRUE;}
              else {
                NifKind_0_nif81dubp1 X60Qx_598 = kind_0_nifb6mq6y1(k_4);
                X60Qx_596 = (X60Qx_598 == 5);}
              if (X60Qx_596){
                NU32 X60Qx_599 = symId_0_nifb6mq6y1(k_4);
                nameSym_1 = X60Qx_599;}
              skip_0_nifb6mq6y1((&k_4));
              add_0_I34il1q_der823rwr1((&(*ob_1).d_00.names_0), nameSym_1);
              Value_0_valzr1t4f X60Qtmp_96 = defaultForType_1_runot4689(k_4);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_600 = newCell_0_valzr1t4f((&X60Qtmp_96));
              add_0_Ijpw0mu_flaksyopx1((&(*ob_1).d_00.cells_0), X60Qx_600);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_96));
              eQdestroy_0_nifb6mq6y1((&k_4));}
            skip_0_nifb6mq6y1((&c_13));}
          else {
            break;}}}
      whileStmtLabel_3: ;
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_97 = ob_1;
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689((&ob_1));
      result_51 = (Value_0_valzr1t4f){
        .kind_0 = 10, .obj_0 = X60Qtmp_97}
      ;
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(ob_1);
      eQdestroy_0_nifb6mq6y1((&c_13));
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(ob_1);
      eQdestroy_0_nifb6mq6y1((&c_13));
      goto X60Qsc_131;
      X60Qsc_132: ;
      Value_0_valzr1t4f X60Qx_601 = vNil_0_valzr1t4f();
      result_51 = X60Qx_601;
      nimStrDestroy(X60Qtmp_88);
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;
      X60Qsc_131: ;
      nimStrDestroy(X60Qtmp_88);}
    else {
      Value_0_valzr1t4f X60Qx_602 = vNil_0_valzr1t4f();
      result_51 = X60Qx_602;
      eQdestroy_0_nifb6mq6y1((&t_6));
      return result_51;}}
  eQdestroy_0_nifb6mq6y1((&t_6));
  return result_51;
  eQdestroy_0_nifb6mq6y1((&t_6));
  return result_51;}
NB8 isAggregateFieldType_0_runot4689(Cursor_0_nifb6mq6y1 typ_3){
  NB8 result_52;
  Cursor_0_nifb6mq6y1 c_14 = eQdup_0_nifb6mq6y1(typ_3);
  NI32 guard_0 = 0;
  {
    while (guard_0 < 32){
      inc_1_I6wjjge_aow2h993l1((&guard_0));
      NifKind_0_nif81dubp1 X60Qx_603 = kind_0_nifb6mq6y1(c_14);
      if (X60Qx_603 == 11){
        string_0_sysvq0asl X60Qtmp_98 = nodeTag_0_runot4689(c_14);
        NB8 X60Qtc_134 = nimStrAtLe_0_sysvq0asl(X60Qtmp_98, 0, (NC8)'a');
        if (X60Qtc_134){
          if (equalStrings_0_sysvq0asl(X60Qtmp_98, (string_0_sysvq0asl){
            .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
          )){
            goto X60Qsc_133;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtmp_98, (string_0_sysvq0asl){
            .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
          )){
            goto X60Qsc_133;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_98, (string_0_sysvq0asl){
            .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
          )){
            goto X60Qsc_133;}}
        goto X60Qsc_136;
        X60Qsc_133: ;
        nimStrDestroy(X60Qtmp_98);
        eQdestroy_0_nifb6mq6y1((&c_14));
        return NIM_TRUE;
        goto X60Qsc_135;
        X60Qsc_136: ;
        nimStrDestroy(X60Qtmp_98);
        eQdestroy_0_nifb6mq6y1((&c_14));
        return NIM_FALSE;
        X60Qsc_135: ;
        nimStrDestroy(X60Qtmp_98);}
      else {
        NifKind_0_nif81dubp1 X60Qx_604 = kind_0_nifb6mq6y1(c_14);
        if (X60Qx_604 == 4){
          NU32 X60Qx_605 = symId_0_nifb6mq6y1(c_14);
          string_0_sysvq0asl* X60Qx_606 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, X60Qx_605);
          string_0_sysvq0asl bn_3 = nimStrDup((*X60Qx_606));
          extractBasename_1_symkyk35i1((&bn_3));
          NB8 X60Qx_607;
          NB8 X60Qx_608 = eqQ_20_sysvq0asl(bn_3, (string_0_sysvq0asl){
            .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
          );
          if (X60Qx_608){
            X60Qx_607 = NIM_TRUE;}
          else {
            NB8 X60Qx_609 = eqQ_20_sysvq0asl(bn_3, (string_0_sysvq0asl){
              .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
            );
            X60Qx_607 = X60Qx_609;}
          if (X60Qx_607){
            nimStrDestroy(bn_3);
            eQdestroy_0_nifb6mq6y1((&c_14));
            return NIM_FALSE;}
          NU32 X60Qx_610 = symId_0_nifb6mq6y1(c_14);
          LoadResult_0_prorcx25w1 res_8 = tryLoadSymSafe_0_modzy18mg1(X60Qx_610);
          NB8 X60Qx_130;
          NB8 X60Qx_611;
          if ((!(res_8.status_0 == 3))){
            X60Qx_611 = NIM_TRUE;}
          else {
            NifKind_0_nif81dubp1 X60Qx_612 = kind_0_nifb6mq6y1(res_8.decl_0);
            X60Qx_611 = (!(X60Qx_612 == 11));}
          if (X60Qx_611){
            X60Qx_130 = NIM_TRUE;}
          else {
            string_0_sysvq0asl X60Qtmp_99 = nodeTag_0_runot4689(res_8.decl_0);
            NB8 X60Qx_613 = eqQ_20_sysvq0asl(X60Qtmp_99, (string_0_sysvq0asl){
              .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
            );
            X60Qx_130 = (!X60Qx_613);
            nimStrDestroy(X60Qtmp_99);}
          if (X60Qx_130){
            eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
            nimStrDestroy(bn_3);
            eQdestroy_0_nifb6mq6y1((&c_14));
            return NIM_FALSE;}
          Cursor_0_nifb6mq6y1 d_3 = res_8.decl_0;
          eQwasMoved_0_nifb6mq6y1((&res_8.decl_0));
          inc_0_nifb6mq6y1((&d_3));
          Cursor_0_nifb6mq6y1 body_0 = (Cursor_0_nifb6mq6y1){
            .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
          ;
          {
            while (NIM_TRUE){
              NifKind_0_nif81dubp1 X60Qx_614 = kind_0_nifb6mq6y1(d_3);
              if ((!(X60Qx_614 == 12))){
                NB8 X60Qx_615;
                NifKind_0_nif81dubp1 X60Qx_616 = kind_0_nifb6mq6y1(d_3);
                if (X60Qx_616 == 11){
                  X60Qx_615 = NIM_TRUE;}
                else {
                  NifKind_0_nif81dubp1 X60Qx_617 = kind_0_nifb6mq6y1(d_3);
                  X60Qx_615 = (X60Qx_617 == 4);}
                if (X60Qx_615){
                  string_0_sysvq0asl X60Qx_10;
                  nimStrWasMoved((&X60Qx_10));
                  NifKind_0_nif81dubp1 X60Qx_618 = kind_0_nifb6mq6y1(d_3);
                  if (X60Qx_618 == 11){
                    nimStrDestroy(X60Qx_10);
                    string_0_sysvq0asl X60Qx_619 = nodeTag_0_runot4689(d_3);
                    X60Qx_10 = X60Qx_619;}
                  else {
                    nimStrDestroy(X60Qx_10);
                    X60Qx_10 = (string_0_sysvq0asl){
                      .bytes_0 = 0u, .more_0 = NIM_NIL}
                    ;}
                  string_0_sysvq0asl t_7 = X60Qx_10;
                  nimStrWasMoved((&X60Qx_10));
                  NB8 X60Qx_620;
                  NB8 X60Qx_621;
                  NB8 X60Qx_622 = eqQ_20_sysvq0asl(t_7, (string_0_sysvq0asl){
                    .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I6313045265747232047_fiepkwzpc)}
                  );
                  if ((!X60Qx_622)){
                    NB8 X60Qx_623 = eqQ_20_sysvq0asl(t_7, (string_0_sysvq0asl){
                      .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
                    );
                    X60Qx_621 = (!X60Qx_623);}
                  else {
                    X60Qx_621 = NIM_FALSE;}
                  if (X60Qx_621){
                    NB8 X60Qx_624 = eqQ_20_sysvq0asl(t_7, (string_0_sysvq0asl){
                      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I14656641239204103783_fiepkwzpc)}
                    );
                    X60Qx_620 = (!X60Qx_624);}
                  else {
                    X60Qx_620 = NIM_FALSE;}
                  if (X60Qx_620){
                    eQdestroy_0_nifb6mq6y1((&body_0));
                    Cursor_0_nifb6mq6y1 X60Qx_625 = eQdup_0_nifb6mq6y1(d_3);
                    body_0 = X60Qx_625;}
                  nimStrDestroy(t_7);
                  nimStrDestroy(X60Qx_10);}
                skip_0_nifb6mq6y1((&d_3));}
              else {
                break;}}}
          whileStmtLabel_1: ;
          NifKind_0_nif81dubp1 X60Qx_626 = kind_0_nifb6mq6y1(body_0);
          if ((!(X60Qx_626 == 11))){
            eQdestroy_0_nifb6mq6y1((&body_0));
            eQdestroy_0_nifb6mq6y1((&d_3));
            eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
            nimStrDestroy(bn_3);
            eQdestroy_0_nifb6mq6y1((&c_14));
            return NIM_FALSE;}
          string_0_sysvq0asl X60Qtmp_100 = nodeTag_0_runot4689(body_0);
          NB8 X60Qtc_139 = nimStrAtLe_0_sysvq0asl(X60Qtmp_100, 0, (NC8)'d');
          if (X60Qtc_139){
            if (equalStrings_0_sysvq0asl(X60Qtmp_100, (string_0_sysvq0asl){
              .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
            )){
              goto X60Qsc_137;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_100, (string_0_sysvq0asl){
              .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_fiepkwzpc)}
            )){
              goto X60Qsc_138;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtmp_100, (string_0_sysvq0asl){
              .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
            )){
              goto X60Qsc_137;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_100, (string_0_sysvq0asl){
              .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
            )){
              goto X60Qsc_137;}}
          goto X60Qsc_141;
          X60Qsc_137: ;
          nimStrDestroy(X60Qtmp_100);
          eQdestroy_0_nifb6mq6y1((&body_0));
          eQdestroy_0_nifb6mq6y1((&d_3));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
          nimStrDestroy(bn_3);
          eQdestroy_0_nifb6mq6y1((&c_14));
          return NIM_TRUE;
          goto X60Qsc_140;
          X60Qsc_138: ;
          Cursor_0_nifb6mq6y1 b_6 = body_0;
          eQwasMoved_0_nifb6mq6y1((&body_0));
          inc_0_nifb6mq6y1((&b_6));
          eQdestroy_0_nifb6mq6y1((&c_14));
          c_14 = b_6;
          eQwasMoved_0_nifb6mq6y1((&b_6));
          eQdestroy_0_nifb6mq6y1((&b_6));
          goto X60Qsc_140;
          X60Qsc_141: ;
          nimStrDestroy(X60Qtmp_100);
          eQdestroy_0_nifb6mq6y1((&body_0));
          eQdestroy_0_nifb6mq6y1((&d_3));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
          nimStrDestroy(bn_3);
          eQdestroy_0_nifb6mq6y1((&c_14));
          return NIM_FALSE;
          X60Qsc_140: ;
          nimStrDestroy(X60Qtmp_100);
          eQdestroy_0_nifb6mq6y1((&body_0));
          eQdestroy_0_nifb6mq6y1((&d_3));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
          nimStrDestroy(bn_3);}
        else {
          eQdestroy_0_nifb6mq6y1((&c_14));
          return NIM_FALSE;}}}}
  whileStmtLabel_0: ;
  result_52 = NIM_FALSE;
  eQdestroy_0_nifb6mq6y1((&c_14));
  return result_52;
  eQdestroy_0_nifb6mq6y1((&c_14));
  return result_52;}
void publishFieldDecls_0_runot4689(Cursor_0_nifb6mq6y1 n_2){
  Cursor_0_nifb6mq6y1 c_15 = eQdup_0_nifb6mq6y1(n_2);
  NI32 depth_1 = 0;
  NI32 guard_1 = 0;
  {
    while (guard_1 < 1000000){
      inc_1_I6wjjge_aow2h993l1((&guard_1));
      NifKind_0_nif81dubp1 X60Qx_627 = kind_0_nifb6mq6y1(c_15);
      switch (X60Qx_627){
        case 11:
        {
          string_0_sysvq0asl tg_0 = nodeTag_0_runot4689(c_15);
          NB8 X60Qx_628;
          NB8 X60Qx_629;
          NB8 X60Qx_630 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
            .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
          );
          if (X60Qx_630){
            X60Qx_629 = NIM_TRUE;}
          else {
            NB8 X60Qx_631 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
              .bytes_0 = 1818650622u, .more_0 = (&strlit_0_I17496857845421750549_nimry5ra91)}
            );
            X60Qx_629 = X60Qx_631;}
          if (X60Qx_629){
            X60Qx_628 = NIM_TRUE;}
          else {
            NB8 X60Qx_632 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
              .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_emi78vuj01)}
            );
            X60Qx_628 = X60Qx_632;}
          if (X60Qx_628){
            Cursor_0_nifb6mq6y1 f_2 = eQdup_0_nifb6mq6y1(c_15);
            inc_0_nifb6mq6y1((&f_2));
            NifKind_0_nif81dubp1 X60Qx_633 = kind_0_nifb6mq6y1(f_2);
            if (X60Qx_633 == 5){
              NI32 X60Qx_634 = span_0_nifb6mq6y1(c_15);
              TokenBuf_0_nifb6mq6y1 b_7 = createTokenBuf_0_nifb6mq6y1(X60Qx_634);
              addSubtree_0_nifb6mq6y1((&b_7), c_15);
              TokenBuf_0_nifb6mq6y1 X60Qtmp_101 = b_7;
              eQwasMoved_1_nifb6mq6y1((&b_7));
              NU32 X60Qx_635 = symId_0_nifb6mq6y1(f_2);
              publish_0_prorcx25w1(X60Qx_635, X60Qtmp_101, 4);
              eQdestroy_1_nifb6mq6y1((&b_7));}
            eQdestroy_0_nifb6mq6y1((&f_2));}
          inc_1_I6wjjge_aow2h993l1((&depth_1));
          inc_0_nifb6mq6y1((&c_15));
          nimStrDestroy(tg_0);}
        break;
        case 12:
        {
          dec_1_I0nzoz91_aow7lb5cq1((&depth_1));
          inc_0_nifb6mq6y1((&c_15));
          if (depth_1 <= 0){
            goto whileStmtLabel_0;}}
        break;
        case 1:
        {
          goto whileStmtLabel_0;}
        break;
        default:
        {
          inc_0_nifb6mq6y1((&c_15));}
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&c_15));}
Value_0_valzr1t4f fieldSeedValue_0_runot4689(NU32 fsym_0){
  Value_0_valzr1t4f result_53;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
  Value_0_valzr1t4f X60Qx_636 = vNil_0_valzr1t4f();
  result_53 = X60Qx_636;
  if (((NU32)fsym_0) == ((NU32)0u)){
    return result_53;}
  LoadResult_0_prorcx25w1 res_9 = tryLoadSymSafe_0_modzy18mg1(fsym_0);
  NB8 X60Qx_637;
  if ((!(res_9.status_0 == 3))){
    X60Qx_637 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_638 = kind_0_nifb6mq6y1(res_9.decl_0);
    X60Qx_637 = (!(X60Qx_638 == 11));}
  if (X60Qx_637){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
    return result_53;}
  string_0_sysvq0asl tg_1 = nodeTag_0_runot4689(res_9.decl_0);
  NB8 X60Qx_639;
  NB8 X60Qx_640 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
    .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
  );
  if ((!X60Qx_640)){
    NB8 X60Qx_641 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
      .bytes_0 = 1818650622u, .more_0 = (&strlit_0_I17496857845421750549_nimry5ra91)}
    );
    X60Qx_639 = (!X60Qx_641);}
  else {
    X60Qx_639 = NIM_FALSE;}
  if (X60Qx_639){
    nimStrDestroy(tg_1);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
    return result_53;}
  Cursor_0_nifb6mq6y1 f_3 = res_9.decl_0;
  eQwasMoved_0_nifb6mq6y1((&res_9.decl_0));
  inc_0_nifb6mq6y1((&f_3));
  skip_0_nifb6mq6y1((&f_3));
  skip_0_nifb6mq6y1((&f_3));
  skip_0_nifb6mq6y1((&f_3));
  NB8 X60Qx_642 = isAggregateFieldType_0_runot4689(f_3);
  if (X60Qx_642){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
    Value_0_valzr1t4f X60Qx_643 = defaultForType_1_runot4689(f_3);
    result_53 = X60Qx_643;}
  eQdestroy_0_nifb6mq6y1((&f_3));
  nimStrDestroy(tg_1);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
  return result_53;
  eQdestroy_0_nifb6mq6y1((&f_3));
  nimStrDestroy(tg_1);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
  return result_53;}
NF64 floatOf_0_runot4689(Value_0_valzr1t4f* v_19){
  NF64 result_54;
  NF64 X60Qx_11;
  if ((*v_19).kind_0 == 3){
    X60Qx_11 = (*v_19).fval_0;}
  else {
    NI64 X60Qx_644 = asInt_0_valzr1t4f((&(*v_19)));
    X60Qx_11 = ((NF64)X60Qx_644);}
  result_54 = X60Qx_11;
  return result_54;}
NI32 bitWidthOf_0_runot4689(Value_0_valzr1t4f* v_20){
  NI32 result_55;
  NB8 X60Qx_645;
  if ((*v_20).kind_0 == 1){
    X60Qx_645 = NIM_TRUE;}
  else {
    X60Qx_645 = ((*v_20).kind_0 == 2);}
  if (X60Qx_645){
    NI32 X60Qx_12;
    if (0 < (*v_20).bits_0){
      X60Qx_12 = (*v_20).bits_0;}
    else {
      X60Qx_12 = 64;}
    result_55 = X60Qx_12;}
  else {
    result_55 = 64;}
  return result_55;}
NU64 uMasked_0_runot4689(Value_0_valzr1t4f* v_21){
  NU64 result_56;
  NI32 w_0 = bitWidthOf_0_runot4689((&(*v_21)));
  NI64 X60Qx_646 = asInt_0_valzr1t4f((&(*v_21)));
  result_56 = ((NU64)X60Qx_646);
  if (w_0 < 64){
    result_56 = ((NU64)(result_56 & ((NU64)(((NU64)(((NU64)1u) << ((NU32)w_0))) - ((NU64)1u)))));}
  return result_56;}
NI32 cmpValues_0_runot4689(Value_0_valzr1t4f* a_1, Value_0_valzr1t4f* b_1){
  NI32 result_57;
  Value_0_valzr1t4f a_5 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*a_1)));
  Value_0_valzr1t4f b_8 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*b_1)));
  NB8 X60Qx_647;
  if (a_5.kind_0 == 0){
    X60Qx_647 = (b_8.kind_0 == 6);}
  else {
    X60Qx_647 = NIM_FALSE;}
  if (X60Qx_647){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_5));
    Value_0_valzr1t4f X60Qx_648 = vStr_0_valzr1t4f((string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    a_5 = X60Qx_648;}
  else {
    NB8 X60Qx_649;
    if (b_8.kind_0 == 0){
      X60Qx_649 = (a_5.kind_0 == 6);}
    else {
      X60Qx_649 = NIM_FALSE;}
    if (X60Qx_649){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&b_8));
      Value_0_valzr1t4f X60Qx_650 = vStr_0_valzr1t4f((string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      );
      b_8 = X60Qx_650;}}
  switch (a_5.kind_0){
    case 6:
    {
      if (b_8.kind_0 == 6){
        NB8 X60Qx_651 = ltQ_17_sysvq0asl(a_5.sval_0, b_8.sval_0);
        if (X60Qx_651){
          result_57 = -1;}
        else {
          NB8 X60Qx_652 = ltQ_17_sysvq0asl(b_8.sval_0, a_5.sval_0);
          if (X60Qx_652){
            result_57 = 1;}
          else {
            result_57 = 0;}}}
      else {
        result_57 = 0;}}
    break;
    case 3:
    {
      NF64 x_13 = a_5.fval_0;
      NF64 y_0 = floatOf_0_runot4689((&b_8));
      if (x_13 < y_0){
        result_57 = -1;}
      else {
        if (y_0 < x_13){
          result_57 = 1;}
        else {
          result_57 = 0;}}}
    break;
    default:
    {
      NI64 x_14 = asInt_0_valzr1t4f((&a_5));
      NI64 y_1 = asInt_0_valzr1t4f((&b_8));
      if (x_14 < y_1){
        result_57 = -1;}
      else {
        if (y_1 < x_14){
          result_57 = 1;}
        else {
          result_57 = 0;}}}
    break;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&b_8));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_5));
  return result_57;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&b_8));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_5));
  return result_57;}
void addRuneUtf8_0_runot4689(string_0_sysvq0asl* s_1, NI64 cp_0){
  NI64 c_16 = cp_0;
  NB8 X60Qx_653;
  if (c_16 < ((NI64)0)){
    X60Qx_653 = NIM_TRUE;}
  else {
    X60Qx_653 = (((NI64)1114111) < c_16);}
  if (X60Qx_653){
    c_16 = ((NI64)65533);}
  if (c_16 <= ((NI64)127)){
    add_1_sysvq0asl(s_1, ((NC8)c_16));}
  else {
    if (c_16 <= ((NI64)2047)){
      add_1_sysvq0asl(s_1, ((NC8)((NI64)(((NI64)192) | ((NI64)(((NI64)c_16) >> ((NU64)6)))))));
      add_1_sysvq0asl(s_1, ((NC8)((NI64)(((NI64)128) | ((NI64)(c_16 & ((NI64)63)))))));}
    else {
      if (c_16 <= ((NI64)65535)){
        add_1_sysvq0asl(s_1, ((NC8)((NI64)(((NI64)224) | ((NI64)(((NI64)c_16) >> ((NU64)12)))))));
        add_1_sysvq0asl(s_1, ((NC8)((NI64)(((NI64)128) | ((NI64)(((NI64)(((NI64)c_16) >> ((NU64)6))) & ((NI64)63)))))));
        add_1_sysvq0asl(s_1, ((NC8)((NI64)(((NI64)128) | ((NI64)(c_16 & ((NI64)63)))))));}
      else {
        add_1_sysvq0asl(s_1, ((NC8)((NI64)(((NI64)240) | ((NI64)(((NI64)c_16) >> ((NU64)18)))))));
        add_1_sysvq0asl(s_1, ((NC8)((NI64)(((NI64)128) | ((NI64)(((NI64)(((NI64)c_16) >> ((NU64)12))) & ((NI64)63)))))));
        add_1_sysvq0asl(s_1, ((NC8)((NI64)(((NI64)128) | ((NI64)(((NI64)(((NI64)c_16) >> ((NU64)6))) & ((NI64)63)))))));
        add_1_sysvq0asl(s_1, ((NC8)((NI64)(((NI64)128) | ((NI64)(c_16 & ((NI64)63)))))));}}}}
void appendValueBytes_0_runot4689(string_0_sysvq0asl* buf_0, Value_0_valzr1t4f* v_22){
  switch ((*v_22).kind_0){
    case 5:
    {
      add_1_sysvq0asl(buf_0, (*v_22).cval_0);}
    break;
    case 4:
    {
      NC8 X60Qx_13;
      if ((*v_22).bval_0){
        X60Qx_13 = (NC8)'\001';}
      else {
        X60Qx_13 = (NC8)'\000';}
      add_1_sysvq0asl(buf_0, X60Qx_13);}
    break;
    case 1:
    case 2:
    {
      NI32 X60Qx_14;
      if (0 < (*v_22).bits_0){
        X60Qx_14 = (*v_22).bits_0;}
      else {
        X60Qx_14 = 64;}
      NI32 w_1 = X60Qx_14;
      NI32 nbytes_2 = ((NI32)(w_1 / 8));
      NU64 x_15 = uMasked_0_runot4689((&(*v_22)));
      NI32 i_25 = 0;
      {
        while (i_25 < nbytes_2){
          add_1_sysvq0asl(buf_0, ((NC8)((NU8)((NU64)(x_15 & ((NU64)255u))))));
          x_15 = ((NU64)(x_15 >> 8));
          inc_1_I6wjjge_aow2h993l1((&i_25));}}
      whileStmtLabel_0: ;}
    break;
    case 3:
    {
      NI32 X60Qx_15;
      if (0 < (*v_22).fbits_0){
        X60Qx_15 = (*v_22).fbits_0;}
      else {
        X60Qx_15 = 64;}
      NI32 bits_0 = X60Qx_15;
      if (bits_0 == 32){
        NF32 X60Qx_654 = ((NF32)(*v_22).fval_0);
        NU32 X60Qx_655;
        copyMem_0_sysvq0asl((&X60Qx_655), (&X60Qx_654), sizeof(NU32));
        NU32 x_16 = X60Qx_655;
        NI32 i_26 = 0;
        {
          while (i_26 < 4){
            add_1_sysvq0asl(buf_0, ((NC8)((NU8)((NU32)(x_16 & ((NU32)255u))))));
            x_16 = ((NU32)(x_16 >> ((NU32)8u)));
            inc_1_I6wjjge_aow2h993l1((&i_26));}}
        whileStmtLabel_1: ;}
      else {
        NF64 X60Qx_656 = (*v_22).fval_0;
        NU64 X60Qx_657;
        copyMem_0_sysvq0asl((&X60Qx_657), (&X60Qx_656), sizeof(NU64));
        NU64 x_17 = X60Qx_657;
        NI32 i_27 = 0;
        {
          while (i_27 < 8){
            add_1_sysvq0asl(buf_0, ((NC8)((NU8)((NU64)(x_17 & ((NU64)255u))))));
            x_17 = ((NU64)(x_17 >> ((NU64)8u)));
            inc_1_I6wjjge_aow2h993l1((&i_27));}}
        whileStmtLabel_2: ;}}
    break;
    case 11:
    case 10:
    {
      if ((!((*v_22).obj_0 == NIM_NIL))){
        {
          openArray_0_Iu2js7k_intzsnzax X60Qlf_2 = toOpenArray_1_Ij5ojb01_intzsnzax((*(*v_22).obj_0).d_00.cells_0);
          NI32 X60Qlf_3 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_658 = len_6_Ip8y5v7_intzsnzax(X60Qlf_2);
              if (X60Qlf_3 < X60Qx_658){
                {
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qii_5 = getQ_10_Ik17lqr_intzsnzax(X60Qlf_2, X60Qlf_3);
                  appendValueBytes_0_runot4689(buf_0, (&(*(*X60Qii_5)).d_00.v_0));}
                inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
              else {
                break;}}}
          whileStmtLabel_4: ;}
        forStmtLabel_3: ;}}
    break;
    case 9:
    {
      if ((!((*v_22).arr_0 == NIM_NIL))){
        {
          openArray_0_Iu2js7k_intzsnzax X60Qlf_4 = toOpenArray_1_Ij5ojb01_intzsnzax((*(*v_22).arr_0).d_00.elems_0);
          NI32 X60Qlf_5 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_659 = len_6_Ip8y5v7_intzsnzax(X60Qlf_4);
              if (X60Qlf_5 < X60Qx_659){
                {
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qii_8 = getQ_10_Ik17lqr_intzsnzax(X60Qlf_4, X60Qlf_5);
                  appendValueBytes_0_runot4689(buf_0, (&(*(*X60Qii_8)).d_00.v_0));}
                inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
              else {
                break;}}}
          whileStmtLabel_7: ;}
        forStmtLabel_6: ;}}
    break;
    default:
    {
      }
    break;}}
NI32 statModeForPath_0_runot4689(string_0_sysvq0asl path_0, NB8 followSymlink_0, NB8* found_0){
  NI32 result_58;
  (*found_0) = NIM_FALSE;
  NB8 X60Qx_660 = journalReplaying_0_jou8favxh1();
  if (X60Qx_660){
    string_0_sysvq0asl X60Qx_16;
    nimStrWasMoved((&X60Qx_16));
    if (followSymlink_0){
      nimStrDestroy(X60Qx_16);
      X60Qx_16 = (string_0_sysvq0asl){
        .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I10217866098611558294_iop7yt73v)}
      ;}
    else {
      nimStrDestroy(X60Qx_16);
      X60Qx_16 = (string_0_sysvq0asl){
        .bytes_0 = 1953721598u, .more_0 = (&strlit_0_I885514587362827984_iop7yt73v)}
      ;}
    string_0_sysvq0asl X60Qtmp_102 = portPath_0_jou8favxh1(path_0);
    seq_0_Ixdx2fh1_aow7lb5cq1 a_7 = jServe_0_jou8favxh1(X60Qx_16, X60Qtmp_102);
    string_0_sysvq0asl X60Qtmp_103 = jField_0_jou8favxh1(a_7, 0);
    NB8 X60Qx_661 = eqQ_20_sysvq0asl(X60Qtmp_103, (string_0_sysvq0asl){
      .bytes_0 = 12545u, .more_0 = NIM_NIL}
    );
    (*found_0) = X60Qx_661;
    string_0_sysvq0asl X60Qtmp_104 = jField_0_jou8favxh1(a_7, 1);
    NI32 X60Qx_662 = jInt_0_jou8favxh1(X60Qtmp_104);
    result_58 = X60Qx_662;
    nimStrDestroy(X60Qtmp_104);
    nimStrDestroy(X60Qtmp_103);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(a_7);
    nimStrDestroy(X60Qtmp_102);
    nimStrDestroy(X60Qx_16);
    return result_58;
    nimStrDestroy(X60Qtmp_104);
    nimStrDestroy(X60Qtmp_103);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(a_7);
    nimStrDestroy(X60Qtmp_102);
    nimStrDestroy(X60Qx_16);}
  NB8 X60Qx_663;
  if ((!followSymlink_0)){
    NB8 X60Qx_664 = symlinkExists_0_osc4bsu0d1(path_0);
    X60Qx_663 = X60Qx_664;}
  else {
    X60Qx_663 = NIM_FALSE;}
  if (X60Qx_663){
    (*found_0) = NIM_TRUE;
    result_58 = 40960;}
  else {
    NB8 X60Qx_665 = fileExists_0_osc4bsu0d1(path_0);
    if (X60Qx_665){
      (*found_0) = NIM_TRUE;
      result_58 = 32768;}
    else {
      NB8 X60Qx_666 = dirExists_0_osc4bsu0d1(path_0);
      if (X60Qx_666){
        (*found_0) = NIM_TRUE;
        result_58 = 16384;}
      else {
        result_58 = 0;}}}
  NB8 X60Qx_667 = journalRecording_0_jou8favxh1();
  if (X60Qx_667){
    string_0_sysvq0asl X60Qx_17;
    nimStrWasMoved((&X60Qx_17));
    if (followSymlink_0){
      nimStrDestroy(X60Qx_17);
      X60Qx_17 = (string_0_sysvq0asl){
        .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I10217866098611558294_iop7yt73v)}
      ;}
    else {
      nimStrDestroy(X60Qx_17);
      X60Qx_17 = (string_0_sysvq0asl){
        .bytes_0 = 1953721598u, .more_0 = (&strlit_0_I885514587362827984_iop7yt73v)}
      ;}
    string_0_sysvq0asl X60Qx_18;
    nimStrWasMoved((&X60Qx_18));
    if ((*found_0)){
      nimStrDestroy(X60Qx_18);
      X60Qx_18 = (string_0_sysvq0asl){
        .bytes_0 = 12545u, .more_0 = NIM_NIL}
      ;}
    else {
      nimStrDestroy(X60Qx_18);
      X60Qx_18 = (string_0_sysvq0asl){
        .bytes_0 = 12289u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qx_19 = dollarQ_2_sysvq0asl(result_58);
    string_0_sysvq0asl X60Qtmp_105 = portPath_0_jou8favxh1(path_0);
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_106 = atQ_0_Ibamkxv1_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
      .a = {
        X60Qx_18, X60Qx_19}}
    );
    jRecord_0_jou8favxh1(X60Qx_17, X60Qtmp_105, X60Qtmp_106);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_106);
    nimStrDestroy(X60Qtmp_105);
    nimStrDestroy(X60Qx_18);
    nimStrDestroy(X60Qx_17);}
  return result_58;}
void writeStatField_0_runot4689(Value_0_valzr1t4f* v_23, string_0_sysvq0asl field_0, NI32 x_4){
  Value_0_valzr1t4f target_1 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_23)));
  NB8 X60Qx_668;
  if (target_1.kind_0 == 13){
    X60Qx_668 = (!(target_1.loc_0 == NIM_NIL));}
  else {
    X60Qx_668 = NIM_FALSE;}
  if (X60Qx_668){
    Value_0_valzr1t4f X60Qlhs_107 = target_1;
    Value_0_valzr1t4f X60Qx_669 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*target_1.loc_0).d_00.v_0));
    target_1 = X60Qx_669;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_107));}
  else {
    NB8 X60Qx_670;
    if (target_1.kind_0 == 12){
      X60Qx_670 = (!(target_1.rf_0 == NIM_NIL));}
    else {
      X60Qx_670 = NIM_FALSE;}
    if (X60Qx_670){
      Value_0_valzr1t4f X60Qlhs_108 = target_1;
      Value_0_valzr1t4f X60Qx_671 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*target_1.rf_0).d_00.v_0));
      target_1 = X60Qx_671;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_108));}}
  NB8 X60Qx_672;
  if ((!(target_1.kind_0 == 11))){
    X60Qx_672 = NIM_TRUE;}
  else {
    X60Qx_672 = (target_1.obj_0 == NIM_NIL);}
  if (X60Qx_672){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_1));
    return;}
  NI32 i_28 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_673 = len_3_I6y2imo_arecyyj7v((*target_1.obj_0).d_00.names_0);
      if (i_28 < X60Qx_673){
        NU32* X60Qx_674 = getQ_7_I2v00yv1_arecyyj7v((*target_1.obj_0).d_00.names_0, i_28);
        string_0_sysvq0asl* X60Qx_675 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*X60Qx_674));
        string_0_sysvq0asl nm_1 = nimStrDup((*X60Qx_675));
        extractBasename_1_symkyk35i1((&nm_1));
        NB8 X60Qx_676 = eqQ_20_sysvq0asl(nm_1, field_0);
        if (X60Qx_676){
          NB8 X60Qx_677;
          NI32 X60Qx_678 = len_3_I83dzei_arecyyj7v((*target_1.obj_0).d_00.cells_0);
          if (i_28 < X60Qx_678){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_679 = getQ_7_Ii14ync1_arecyyj7v((*target_1.obj_0).d_00.cells_0, i_28);
            X60Qx_677 = (!((*X60Qx_679) == NIM_NIL));}
          else {
            X60Qx_677 = NIM_FALSE;}
          if (X60Qx_677){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_680 = getQ_7_Ii14ync1_arecyyj7v((*target_1.obj_0).d_00.cells_0, i_28);
            Value_0_valzr1t4f* X60Qlhs_109 = (&(*(*X60Qx_680)).d_00.v_0);
            Value_0_valzr1t4f X60Qlhs_110 = vInt_0_valzr1t4f(((NI64)x_4), 64);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_109)));
            (*X60Qlhs_109) = X60Qlhs_110;}
          nimStrDestroy(nm_1);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_1));
          return;}
        inc_1_I6wjjge_aow2h993l1((&i_28));
        nimStrDestroy(nm_1);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_1));}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* fieldCellByBase_0_runot4689(Value_0_valzr1t4f* v_24, string_0_sysvq0asl base_5){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_59;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&result_59));
  Value_0_valzr1t4f target_2 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_24)));
  NB8 X60Qx_681;
  if (target_2.kind_0 == 13){
    X60Qx_681 = (!(target_2.loc_0 == NIM_NIL));}
  else {
    X60Qx_681 = NIM_FALSE;}
  if (X60Qx_681){
    Value_0_valzr1t4f X60Qlhs_111 = target_2;
    Value_0_valzr1t4f X60Qx_682 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*target_2.loc_0).d_00.v_0));
    target_2 = X60Qx_682;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_111));}
  else {
    NB8 X60Qx_683;
    if (target_2.kind_0 == 12){
      X60Qx_683 = (!(target_2.rf_0 == NIM_NIL));}
    else {
      X60Qx_683 = NIM_FALSE;}
    if (X60Qx_683){
      Value_0_valzr1t4f X60Qlhs_112 = target_2;
      Value_0_valzr1t4f X60Qx_684 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*target_2.rf_0).d_00.v_0));
      target_2 = X60Qx_684;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_112));}}
  NB8 X60Qx_685;
  NB8 X60Qx_686;
  if ((!(target_2.kind_0 == 11))){
    X60Qx_686 = (!(target_2.kind_0 == 10));}
  else {
    X60Qx_686 = NIM_FALSE;}
  if (X60Qx_686){
    X60Qx_685 = NIM_TRUE;}
  else {
    X60Qx_685 = (target_2.obj_0 == NIM_NIL);}
  if (X60Qx_685){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_2));
    return NIM_NIL;}
  NI32 i_29 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_687 = len_3_I6y2imo_arecyyj7v((*target_2.obj_0).d_00.names_0);
      if (i_29 < X60Qx_687){
        NU32* X60Qx_688 = getQ_7_I2v00yv1_arecyyj7v((*target_2.obj_0).d_00.names_0, i_29);
        string_0_sysvq0asl* X60Qx_689 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*X60Qx_688));
        string_0_sysvq0asl nm_2 = nimStrDup((*X60Qx_689));
        extractBasename_1_symkyk35i1((&nm_2));
        NB8 X60Qx_690 = eqQ_20_sysvq0asl(nm_2, base_5);
        if (X60Qx_690){
          NI32 X60Qx_691 = len_3_I83dzei_arecyyj7v((*target_2.obj_0).d_00.cells_0);
          if (i_29 < X60Qx_691){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_692 = getQ_7_Ii14ync1_arecyyj7v((*target_2.obj_0).d_00.cells_0, i_29);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_693 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_692));
            result_59 = X60Qx_693;
            nimStrDestroy(nm_2);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_2));
            return result_59;}
          nimStrDestroy(nm_2);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_2));
          return NIM_NIL;}
        inc_1_I6wjjge_aow2h993l1((&i_29));
        nimStrDestroy(nm_2);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(result_59);
  result_59 = NIM_NIL;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_2));
  return result_59;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_2));
  return result_59;}
Value_0_valzr1t4f environArrayValue_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_5){
  Value_0_valzr1t4f result_60;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_60));
  void* X60Qx_694 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_113 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_694);
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_695 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  (*X60Qtmp_113) = (X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (ArrBox_Obj_0_valzr1t4f){
      .elems_0 = X60Qx_695, .lo_0 = 0, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
  ;
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* ab_1 = X60Qtmp_113;
  NI32 i_30 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_696 = len_3_Ixq6taz_aow7lb5cq1((*sink_5).d_00.envKeys_0);
      if (i_30 < X60Qx_696){
        string_0_sysvq0asl* X60Qx_697 = getQ_7_Ir6d0tw_aow7lb5cq1((*sink_5).d_00.envKeys_0, i_30);
        string_0_sysvq0asl X60Qdesugar_10 = nimStrDup((*X60Qx_697));
        string_0_sysvq0asl* X60Qx_698 = getQ_7_Ir6d0tw_aow7lb5cq1((*sink_5).d_00.envVals_0, i_30);
        string_0_sysvq0asl X60Qdesugar_11 = nimStrDup((*X60Qx_698));
        NI32 X60Qx_699 = len_4_sysvq0asl(X60Qdesugar_10);
        NI32 X60Qx_700 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 15617u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_701 = len_4_sysvq0asl(X60Qdesugar_11);
        string_0_sysvq0asl X60Qdesugar_12 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_699 + X60Qx_700)) + X60Qx_701)));
        add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_10);
        add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
          .bytes_0 = 15617u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_11);
        Value_0_valzr1t4f X60Qtmp_114 = vStr_0_valzr1t4f(X60Qdesugar_12);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_702 = newCell_0_valzr1t4f((&X60Qtmp_114));
        add_0_Ijpw0mu_flaksyopx1((&(*ab_1).d_00.elems_0), X60Qx_702);
        inc_1_I6wjjge_aow2h993l1((&i_30));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_114));
        nimStrDestroy(X60Qdesugar_12);
        nimStrDestroy(X60Qdesugar_11);
        nimStrDestroy(X60Qdesugar_10);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  Value_0_valzr1t4f X60Qtmp_115 = vNil_0_valzr1t4f();
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_703 = newCell_0_valzr1t4f((&X60Qtmp_115));
  add_0_Ijpw0mu_flaksyopx1((&(*ab_1).d_00.elems_0), X60Qx_703);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_60));
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_116 = ab_1;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689((&ab_1));
  result_60 = (Value_0_valzr1t4f){
    .kind_0 = 9, .arr_0 = X60Qtmp_116}
  ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_115));
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(ab_1);
  return result_60;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_115));
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(ab_1);
  return result_60;}
Value_0_valzr1t4f environmentSeqValue_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_6){
  Value_0_valzr1t4f result_61;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_61));
  void* X60Qx_704 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_117 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_704);
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_705 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  (*X60Qtmp_117) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
      .elems_0 = X60Qx_705, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
  ;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_4 = X60Qtmp_117;
  NI32 i_31 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_706 = len_3_Ixq6taz_aow7lb5cq1((*sink_6).d_00.envKeys_0);
      if (i_31 < X60Qx_706){
        string_0_sysvq0asl* X60Qx_707 = getQ_7_Ir6d0tw_aow7lb5cq1((*sink_6).d_00.envKeys_0, i_31);
        string_0_sysvq0asl X60Qdesugar_13 = nimStrDup((*X60Qx_707));
        string_0_sysvq0asl* X60Qx_708 = getQ_7_Ir6d0tw_aow7lb5cq1((*sink_6).d_00.envVals_0, i_31);
        string_0_sysvq0asl X60Qdesugar_14 = nimStrDup((*X60Qx_708));
        NI32 X60Qx_709 = len_4_sysvq0asl(X60Qdesugar_13);
        NI32 X60Qx_710 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 15617u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_711 = len_4_sysvq0asl(X60Qdesugar_14);
        string_0_sysvq0asl X60Qdesugar_15 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_709 + X60Qx_710)) + X60Qx_711)));
        add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_13);
        add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
          .bytes_0 = 15617u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_14);
        Value_0_valzr1t4f X60Qtmp_118 = vStr_0_valzr1t4f(X60Qdesugar_15);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_712 = newCell_0_valzr1t4f((&X60Qtmp_118));
        add_0_Ijpw0mu_flaksyopx1((&(*sb_4).d_00.elems_0), X60Qx_712);
        inc_1_I6wjjge_aow2h993l1((&i_31));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_118));
        nimStrDestroy(X60Qdesugar_15);
        nimStrDestroy(X60Qdesugar_14);
        nimStrDestroy(X60Qdesugar_13);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_61));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_119 = sb_4;
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689((&sb_4));
  result_61 = (Value_0_valzr1t4f){
    .kind_0 = 8, .sq_0 = X60Qtmp_119}
  ;
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb_4);
  return result_61;
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb_4);
  return result_61;}
NB8 isEnvironGlobal_0_runot4689(string_0_sysvq0asl base_6){
  NB8 result_62;
  NB8 X60Qx_713;
  NB8 X60Qx_714;
  NB8 X60Qx_715 = eqQ_20_sysvq0asl(base_6, (string_0_sysvq0asl){
    .bytes_0 = 1850042366u, .more_0 = (&strlit_0_I10672061222185195832_runot4689)}
  );
  if (X60Qx_715){
    X60Qx_714 = NIM_TRUE;}
  else {
    NB8 X60Qx_716 = eqQ_20_sysvq0asl(base_6, (string_0_sysvq0asl){
      .bytes_0 = 1986946558u, .more_0 = (&strlit_0_I14094691204709860525_intzsnzax)}
    );
    X60Qx_714 = X60Qx_716;}
  if (X60Qx_714){
    X60Qx_713 = NIM_TRUE;}
  else {
    NB8 X60Qx_717 = eqQ_20_sysvq0asl(base_6, (string_0_sysvq0asl){
      .bytes_0 = 1835626238u, .more_0 = (&strlit_0_I7133596773365113623_intzsnzax)}
    );
    X60Qx_713 = X60Qx_717;}
  result_62 = X60Qx_713;
  return result_62;}
Value_0_valzr1t4f argvArrayValue_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_7){
  Value_0_valzr1t4f result_63;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_63));
  void* X60Qx_718 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_120 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_718);
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_719 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  (*X60Qtmp_120) = (X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (ArrBox_Obj_0_valzr1t4f){
      .elems_0 = X60Qx_719, .lo_0 = 0, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
  ;
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* ab_2 = X60Qtmp_120;
  Value_0_valzr1t4f X60Qtmp_121 = vStr_0_valzr1t4f((*sink_7).d_00.progName_0);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_720 = newCell_0_valzr1t4f((&X60Qtmp_121));
  add_0_Ijpw0mu_flaksyopx1((&(*ab_2).d_00.elems_0), X60Qx_720);
  NI32 i_32 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_721 = len_3_Ixq6taz_aow7lb5cq1((*sink_7).d_00.argv_0);
      if (i_32 < X60Qx_721){
        string_0_sysvq0asl* X60Qx_722 = getQ_7_Ir6d0tw_aow7lb5cq1((*sink_7).d_00.argv_0, i_32);
        Value_0_valzr1t4f X60Qtmp_122 = vStr_0_valzr1t4f((*X60Qx_722));
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_723 = newCell_0_valzr1t4f((&X60Qtmp_122));
        add_0_Ijpw0mu_flaksyopx1((&(*ab_2).d_00.elems_0), X60Qx_723);
        inc_1_I6wjjge_aow2h993l1((&i_32));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_122));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  Value_0_valzr1t4f X60Qtmp_123 = vNil_0_valzr1t4f();
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_724 = newCell_0_valzr1t4f((&X60Qtmp_123));
  add_0_Ijpw0mu_flaksyopx1((&(*ab_2).d_00.elems_0), X60Qx_724);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_63));
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_124 = ab_2;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689((&ab_2));
  result_63 = (Value_0_valzr1t4f){
    .kind_0 = 9, .arr_0 = X60Qtmp_124}
  ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_123));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_121));
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(ab_2);
  return result_63;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_123));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_121));
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(ab_2);
  return result_63;}
Value_0_valzr1t4f argvCountValue_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_8){
  Value_0_valzr1t4f result_64;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_64));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_64));
  NI32 X60Qx_725 = len_3_Ixq6taz_aow7lb5cq1((*sink_8).d_00.argv_0);
  Value_0_valzr1t4f X60Qx_726 = vInt_0_valzr1t4f(((NI64)((NI32)(X60Qx_725 + 1))), 32);
  result_64 = X60Qx_726;
  return result_64;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* sharedImportcCell_0_runot4689(string_0_sysvq0asl cname_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_65;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&result_65));
  NI32 i_33 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_727 = len_3_Ixq6taz_aow7lb5cq1(gImportcNames_0_runot4689);
      if (i_33 < X60Qx_727){
        string_0_sysvq0asl* X60Qx_728 = getQ_7_Ir6d0tw_aow7lb5cq1(gImportcNames_0_runot4689, i_33);
        NB8 X60Qx_729 = eqQ_20_sysvq0asl((*X60Qx_728), cname_0);
        if (X60Qx_729){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_730 = getQ_7_Ii14ync1_arecyyj7v(gImportcCells_0_runot4689, i_33);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_731 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_730));
          result_65 = X60Qx_731;
          return result_65;}
        inc_1_I6wjjge_aow2h993l1((&i_33));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(result_65);
  result_65 = NIM_NIL;
  return result_65;}
void registerImportcCell_0_runot4689(string_0_sysvq0asl cname_1, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_2){
  NB8 X60Qx_732;
  NI32 X60Qx_733 = len_4_sysvq0asl(cname_1);
  if (0 < X60Qx_733){
    X60Qx_732 = (!(c_2 == NIM_NIL));}
  else {
    X60Qx_732 = NIM_FALSE;}
  if (X60Qx_732){
    string_0_sysvq0asl X60Qx_734 = nimStrDup(cname_1);
    add_0_Ig6072n_aow7lb5cq1((&gImportcNames_0_runot4689), X60Qx_734);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_735 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_2);
    add_0_Ijpw0mu_flaksyopx1((&gImportcCells_0_runot4689), X60Qx_735);}}
Value_0_valzr1t4f importcNativeValue_0_runot4689(string_0_sysvq0asl cname_2, NB8* found_1){
  Value_0_valzr1t4f result_66;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_66));
  (*found_1) = NIM_FALSE;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_66));
  Value_0_valzr1t4f X60Qx_736 = vNil_0_valzr1t4f();
  result_66 = X60Qx_736;
  NB8 X60Qx_737;
  NI32 X60Qx_738 = len_4_sysvq0asl(cname_2);
  if (X60Qx_738 == 0){
    X60Qx_737 = NIM_TRUE;}
  else {
    NI32 X60Qx_739 = len_3_Ixq6taz_aow7lb5cq1(gImportcNativeNames_0_runot4689);
    X60Qx_737 = (X60Qx_739 == 0);}
  if (X60Qx_737){
    return result_66;}
  NI32 i_34 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_740 = len_3_Ixq6taz_aow7lb5cq1(gImportcNativeNames_0_runot4689);
      if (i_34 < X60Qx_740){
        string_0_sysvq0asl* X60Qx_741 = getQ_7_Ir6d0tw_aow7lb5cq1(gImportcNativeNames_0_runot4689, i_34);
        NB8 X60Qx_742 = eqQ_20_sysvq0asl((*X60Qx_741), cname_2);
        if (X60Qx_742){
          (*found_1) = NIM_TRUE;
          Value_0_valzr1t4f* X60Qx_743 = getQ_7_Ine8yq71_intzsnzax(gImportcNativeVals_0_runot4689, i_34);
          Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_743);
          Value_0_valzr1t4f X60Qx_744 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
          result_66 = X60Qx_744;
          return result_66;}
        inc_1_I6wjjge_aow2h993l1((&i_34));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_66;}
void markNativeImportcCell_0_runot4689(string_0_sysvq0asl cname_4, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_3){
  NB8 X60Qx_752;
  NI32 X60Qx_753 = len_4_sysvq0asl(cname_4);
  if (X60Qx_753 == 0){
    X60Qx_752 = NIM_TRUE;}
  else {
    X60Qx_752 = (c_3 == NIM_NIL);}
  if (X60Qx_752){
    return;}
  NB8 f_4 = NIM_FALSE;
  Value_0_valzr1t4f X60Qtmp_125 = importcNativeValue_0_runot4689(cname_4, (&f_4));
  Value_0_valzr1t4f X60Qx_754 = X60Qtmp_125;
  if ((!f_4)){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_125));
    return;}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_755 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_3);
  add_0_Ijpw0mu_flaksyopx1((&gImportcNativeCells_0_runot4689), X60Qx_755);
  string_0_sysvq0asl X60Qx_756 = nimStrDup(cname_4);
  add_0_Ig6072n_aow7lb5cq1((&gImportcNativeCellNames_0_runot4689), X60Qx_756);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_125));}
static inline string_0_sysvq0asl nativeImportcCellName_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_4){
  string_0_sysvq0asl result_67;
  nimStrWasMoved((&result_67));
  nimStrDestroy(result_67);
  result_67 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_757;
  NI32 X60Qx_758 = len_3_I83dzei_arecyyj7v(gImportcNativeCells_0_runot4689);
  if (X60Qx_758 == 0){
    X60Qx_757 = NIM_TRUE;}
  else {
    X60Qx_757 = (c_4 == NIM_NIL);}
  if (X60Qx_757){
    return result_67;}
  NI32 i_37 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_759 = len_3_I83dzei_arecyyj7v(gImportcNativeCells_0_runot4689);
      if (i_37 < X60Qx_759){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_760 = getQ_7_Ii14ync1_arecyyj7v(gImportcNativeCells_0_runot4689, i_37);
        if ((*X60Qx_760) == c_4){
          string_0_sysvq0asl* X60Qx_761 = getQ_7_Ir6d0tw_aow7lb5cq1(gImportcNativeCellNames_0_runot4689, i_37);
          string_0_sysvq0asl X60Qx_762 = nimStrDup((*X60Qx_761));
          result_67 = X60Qx_762;
          return result_67;}
        inc_1_I6wjjge_aow2h993l1((&i_37));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_67;}
void failNativeImportcWrite_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_9, string_0_sysvq0asl cname_5){
  NI32 X60Qx_763 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I5200583122280938215_runot4689)}
  );
  NI32 X60Qx_764 = len_4_sysvq0asl(cname_5);
  NI32 X60Qx_765 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3793758206u, .more_0 = (&strlit_0_I9043385391952070731_runot4689)}
  );
  NI32 X60Qx_766 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1634891006u, .more_0 = (&strlit_0_I7864832558404820058_runot4689)}
  );
  NI32 X60Qx_767 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1864385534u, .more_0 = (&strlit_0_I7045456837871243884_runot4689)}
  );
  NI32 X60Qx_768 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1095062270u, .more_0 = (&strlit_0_I11592933535804058560_runot4689)}
  );
  NI32 X60Qx_769 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1651863806u, .more_0 = (&strlit_0_I11068299943761976496_runot4689)}
  );
  string_0_sysvq0asl X60Qdesugar_16 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_763 + X60Qx_764)) + X60Qx_765)) + X60Qx_766)) + X60Qx_767)) + X60Qx_768)) + X60Qx_769)));
  add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I5200583122280938215_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_16), cname_5);
  add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
    .bytes_0 = 3793758206u, .more_0 = (&strlit_0_I9043385391952070731_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
    .bytes_0 = 1634891006u, .more_0 = (&strlit_0_I7864832558404820058_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
    .bytes_0 = 1864385534u, .more_0 = (&strlit_0_I7045456837871243884_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
    .bytes_0 = 1095062270u, .more_0 = (&strlit_0_I11592933535804058560_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
    .bytes_0 = 1651863806u, .more_0 = (&strlit_0_I11068299943761976496_runot4689)}
  );
  string_0_sysvq0asl msg_0 = X60Qdesugar_16;
  nimStrWasMoved((&X60Qdesugar_16));
  if ((!(*sink_9).d_00.didQQuit_0)){
    add_2_sysvq0asl((&(*sink_9).d_00.errBuf_0), msg_0);
    doQQuit_0_natd5co251(sink_9, 1);}
  nimStrDestroy(msg_0);
  nimStrDestroy(X60Qdesugar_16);}
NB8 isAllowedUnboundImportc_0_runot4689(string_0_sysvq0asl cname_6){
  NB8 result_68;
  if (equalStrings_0_sysvq0asl(cname_6, (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  )){
    goto X60Qsc_142;}
  goto X60Qsc_144;
  X60Qsc_142: ;
  result_68 = NIM_FALSE;
  goto X60Qsc_143;
  X60Qsc_144: ;
  result_68 = NIM_FALSE;
  X60Qsc_143: ;
  return result_68;}
void failUnboundImportcGlobal_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_10, string_0_sysvq0asl cname_7, string_0_sysvq0asl bn_0){
  NI32 X60Qx_770 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I8126255002988789275_runot4689)}
  );
  NI32 X60Qx_771 = len_4_sysvq0asl(cname_7);
  NI32 X60Qx_772 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 673196030u, .more_0 = (&strlit_0_I15900777102133637650_runot4689)}
  );
  NI32 X60Qx_773 = len_4_sysvq0asl(bn_0);
  NI32 X60Qx_774 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 539568126u, .more_0 = (&strlit_0_I13719311418082057446_runot4689)}
  );
  NI32 X60Qx_775 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1986095358u, .more_0 = (&strlit_0_I14654729971600803534_runot4689)}
  );
  NI32 X60Qx_776 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1651076350u, .more_0 = (&strlit_0_I10797867291169351481_runot4689)}
  );
  NI32 X60Qx_777 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1937009150u, .more_0 = (&strlit_0_I15831543276806770207_runot4689)}
  );
  string_0_sysvq0asl X60Qdesugar_17 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_770 + X60Qx_771)) + X60Qx_772)) + X60Qx_773)) + X60Qx_774)) + X60Qx_775)) + X60Qx_776)) + X60Qx_777)));
  add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I8126255002988789275_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_17), cname_7);
  add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
    .bytes_0 = 673196030u, .more_0 = (&strlit_0_I15900777102133637650_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_17), bn_0);
  add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
    .bytes_0 = 539568126u, .more_0 = (&strlit_0_I13719311418082057446_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
    .bytes_0 = 1986095358u, .more_0 = (&strlit_0_I14654729971600803534_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
    .bytes_0 = 1651076350u, .more_0 = (&strlit_0_I10797867291169351481_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
    .bytes_0 = 1937009150u, .more_0 = (&strlit_0_I15831543276806770207_runot4689)}
  );
  string_0_sysvq0asl msg_1 = X60Qdesugar_17;
  nimStrWasMoved((&X60Qdesugar_17));
  if (importcLax_0_runot4689){
    write_0_syn1lfpjv(stderr, msg_1);
    nimStrDestroy(msg_1);
    nimStrDestroy(X60Qdesugar_17);
    return;}
  if ((!(*sink_10).d_00.didQQuit_0)){
    add_2_sysvq0asl((&(*sink_10).d_00.errBuf_0), msg_1);
    doQQuit_0_natd5co251(sink_10, 1);}
  nimStrDestroy(msg_1);
  nimStrDestroy(X60Qdesugar_17);}
Value_0_valzr1t4f importcGlobalSeed_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_11, string_0_sysvq0asl cname_8, string_0_sysvq0asl bn_1, NB8* found_2, NB8 quiet_0){
  Value_0_valzr1t4f result_69;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_69));
  (*found_2) = NIM_TRUE;
  string_0_sysvq0asl X60Qx_20;
  nimStrWasMoved((&X60Qx_20));
  NI32 X60Qx_778 = len_4_sysvq0asl(cname_8);
  if (0 < X60Qx_778){
    nimStrDestroy(X60Qx_20);
    string_0_sysvq0asl X60Qx_779 = nimStrDup(cname_8);
    X60Qx_20 = X60Qx_779;}
  else {
    nimStrDestroy(X60Qx_20);
    string_0_sysvq0asl X60Qx_780 = nimStrDup(bn_1);
    X60Qx_20 = X60Qx_780;}
  string_0_sysvq0asl key_0 = X60Qx_20;
  nimStrWasMoved((&X60Qx_20));
  NB8 X60Qtc_148 = nimStrAtLe_0_sysvq0asl(key_0, 0, (NC8)'c');
  if (X60Qtc_148){
    if (equalStrings_0_sysvq0asl(key_0, (string_0_sysvq0asl){
      .bytes_0 = 1684890622u, .more_0 = (&strlit_0_I10065104808643963232_intzsnzax)}
    )){
      goto X60Qsc_145;}
    else if (equalStrings_0_sysvq0asl(key_0, (string_0_sysvq0asl){
      .bytes_0 = 1684890622u, .more_0 = (&strlit_0_I14998953601798186169_intzsnzax)}
    )){
      goto X60Qsc_146;}}
  else {
    if (equalStrings_0_sysvq0asl(key_0, (string_0_sysvq0asl){
      .bytes_0 = 1986946558u, .more_0 = (&strlit_0_I14094691204709860525_intzsnzax)}
    )){
      goto X60Qsc_147;}
    else if (equalStrings_0_sysvq0asl(key_0, (string_0_sysvq0asl){
      .bytes_0 = 1835626238u, .more_0 = (&strlit_0_I7133596773365113623_intzsnzax)}
    )){
      goto X60Qsc_147;}}
  goto X60Qsc_150;
  X60Qsc_145: ;
  Value_0_valzr1t4f X60Qx_781 = argvCountValue_0_runot4689(sink_11);
  result_69 = X60Qx_781;
  nimStrDestroy(key_0);
  nimStrDestroy(X60Qx_20);
  return result_69;
  goto X60Qsc_149;
  X60Qsc_146: ;
  Value_0_valzr1t4f X60Qx_782 = argvArrayValue_0_runot4689(sink_11);
  result_69 = X60Qx_782;
  nimStrDestroy(key_0);
  nimStrDestroy(X60Qx_20);
  return result_69;
  goto X60Qsc_149;
  X60Qsc_147: ;
  Value_0_valzr1t4f X60Qx_783 = environArrayValue_0_runot4689(sink_11);
  result_69 = X60Qx_783;
  nimStrDestroy(key_0);
  nimStrDestroy(X60Qx_20);
  return result_69;
  goto X60Qsc_149;
  X60Qsc_150: ;
  X60Qsc_149: ;
  NB8 X60Qx_784 = isEnvironGlobal_0_runot4689(bn_1);
  if (X60Qx_784){
    Value_0_valzr1t4f X60Qx_785 = environArrayValue_0_runot4689(sink_11);
    result_69 = X60Qx_785;
    nimStrDestroy(key_0);
    nimStrDestroy(X60Qx_20);
    return result_69;}
  NB8 X60Qx_786 = eqQ_20_sysvq0asl(bn_1, (string_0_sysvq0asl){
    .bytes_0 = 1986946558u, .more_0 = (&strlit_0_I274569611119625799_intzsnzax)}
  );
  if (X60Qx_786){
    Value_0_valzr1t4f X60Qx_787 = environmentSeqValue_0_runot4689(sink_11);
    result_69 = X60Qx_787;
    nimStrDestroy(key_0);
    nimStrDestroy(X60Qx_20);
    return result_69;}
  NB8 X60Qx_788;
  NB8 X60Qx_789 = eqQ_20_sysvq0asl(cname_8, (string_0_sysvq0asl){
    .bytes_0 = 1920099838u, .more_0 = (&strlit_0_I13880079574436425354_intzsnzax)}
  );
  if (X60Qx_789){
    X60Qx_788 = NIM_TRUE;}
  else {
    NB8 X60Qx_790 = eqQ_20_sysvq0asl(bn_1, (string_0_sysvq0asl){
      .bytes_0 = 1920099838u, .more_0 = (&strlit_0_I13880079574436425354_intzsnzax)}
    );
    X60Qx_788 = X60Qx_790;}
  if (X60Qx_788){
    Value_0_valzr1t4f X60Qx_791 = vInt_0_valzr1t4f(((NI64)0), 32);
    result_69 = X60Qx_791;
    nimStrDestroy(key_0);
    nimStrDestroy(X60Qx_20);
    return result_69;}
  NB8 nvFound_0 = NIM_FALSE;
  Value_0_valzr1t4f nv_0 = importcNativeValue_0_runot4689(cname_8, (&nvFound_0));
  if (nvFound_0){
    Value_0_valzr1t4f X60Qtmp_127 = nv_0;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
    nimStrDestroy(key_0);
    nimStrDestroy(X60Qx_20);
    return X60Qtmp_127;}
  NB8 lcFound_0 = NIM_FALSE;
  Value_0_valzr1t4f lc_0 = libcConstVal_0_runot4689(bn_1, (&lcFound_0));
  if (lcFound_0){
    Value_0_valzr1t4f X60Qtmp_128 = lc_0;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_0));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_0));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
    nimStrDestroy(key_0);
    nimStrDestroy(X60Qx_20);
    return X60Qtmp_128;}
  (*found_2) = NIM_FALSE;
  NB8 X60Qx_792;
  NB8 X60Qx_793;
  NI32 X60Qx_794 = len_4_sysvq0asl(cname_8);
  if (0 < X60Qx_794){
    NB8 X60Qx_795 = isAllowedUnboundImportc_0_runot4689(cname_8);
    X60Qx_793 = (!X60Qx_795);}
  else {
    X60Qx_793 = NIM_FALSE;}
  if (X60Qx_793){
    X60Qx_792 = (!quiet_0);}
  else {
    X60Qx_792 = NIM_FALSE;}
  if (X60Qx_792){
    failUnboundImportcGlobal_0_runot4689(sink_11, cname_8, bn_1);}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_69));
  Value_0_valzr1t4f X60Qx_796 = vNil_0_valzr1t4f();
  result_69 = X60Qx_796;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_0));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
  nimStrDestroy(key_0);
  nimStrDestroy(X60Qx_20);
  return result_69;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_0));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
  nimStrDestroy(key_0);
  nimStrDestroy(X60Qx_20);
  return result_69;}
Value_0_valzr1t4f likeStringValue_0_runot4689(Value_0_valzr1t4f* model_0, string_0_sysvq0asl s_2){
  Value_0_valzr1t4f result_70;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_70));
  NB8 X60Qx_797;
  NB8 X60Qx_798;
  if ((*model_0).kind_0 == 11){
    X60Qx_798 = (!((*model_0).obj_0 == NIM_NIL));}
  else {
    X60Qx_798 = NIM_FALSE;}
  if (X60Qx_798){
    NI32 X60Qx_799 = len_3_I83dzei_arecyyj7v((*(*model_0).obj_0).d_00.cells_0);
    X60Qx_797 = (X60Qx_799 == 1);}
  else {
    X60Qx_797 = NIM_FALSE;}
  if (X60Qx_797){
    void* X60Qx_800 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_129 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_800);
    seq_0_In6doa_arecyyj7v X60Qx_801 = eQdup_1_Idg8rf9_arecyyj7v((*(*model_0).obj_0).d_00.names_0);
    seq_0_Iw8xl5b1_arecyyj7v X60Qx_802 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
    (*X60Qtmp_129) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
      .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
        .typeSym_0 = (*(*model_0).obj_0).d_00.typeSym_0, .names_0 = X60Qx_801, .cells_0 = X60Qx_802}}
    ;
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* ob_2 = X60Qtmp_129;
    Value_0_valzr1t4f X60Qtmp_130 = vStr_0_valzr1t4f(s_2);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_803 = newCell_0_valzr1t4f((&X60Qtmp_130));
    add_0_Ijpw0mu_flaksyopx1((&(*ob_2).d_00.cells_0), X60Qx_803);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_70));
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_131 = ob_2;
    eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689((&ob_2));
    result_70 = (Value_0_valzr1t4f){
      .kind_0 = 11, .obj_0 = X60Qtmp_131}
    ;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_130));
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(ob_2);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_70));
    Value_0_valzr1t4f X60Qx_804 = vStr_0_valzr1t4f(s_2);
    result_70 = X60Qx_804;}
  return result_70;}
string_0_sysvq0asl policyPathOf_0_runot4689(string_0_sysvq0asl name_5, seq_0_I50urnw_croph25r5 args_3){
  string_0_sysvq0asl result_71;
  nimStrWasMoved((&result_71));
  NI32 X60Qx_805 = len_3_I4n9kvq_intzsnzax(args_3);
  if (X60Qx_805 == 0){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NB8 X60Qx_806 = eqQ_20_sysvq0asl(name_5, (string_0_sysvq0asl){
    .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
  );
  if (X60Qx_806){
    NB8 X60Qx_807;
    if (2 <= args_3.len_0){
      Value_0_valzr1t4f* X60Qx_808 = getQ_7_Ine8yq71_intzsnzax(args_3, 0);
      X60Qx_807 = ((*X60Qx_808).kind_0 == 6);}
    else {
      X60Qx_807 = NIM_FALSE;}
    if (X60Qx_807){
      Value_0_valzr1t4f* X60Qx_809 = getQ_7_Ine8yq71_intzsnzax(args_3, 0);
      string_0_sysvq0asl X60Qx_810 = nimStrDup((*X60Qx_809).sval_0);
      result_71 = X60Qx_810;
      return result_71;}
    NB8 X60Qx_811;
    if (3 <= args_3.len_0){
      Value_0_valzr1t4f* X60Qx_812 = getQ_7_Ine8yq71_intzsnzax(args_3, 1);
      X60Qx_811 = ((*X60Qx_812).kind_0 == 6);}
    else {
      X60Qx_811 = NIM_FALSE;}
    if (X60Qx_811){
      Value_0_valzr1t4f* X60Qx_813 = getQ_7_Ine8yq71_intzsnzax(args_3, 1);
      string_0_sysvq0asl X60Qx_814 = nimStrDup((*X60Qx_813).sval_0);
      result_71 = X60Qx_814;
      return result_71;}}
  string_0_sysvq0asl X60Qx_21;
  nimStrWasMoved((&X60Qx_21));
  Value_0_valzr1t4f* X60Qx_815 = getQ_7_Ine8yq71_intzsnzax(args_3, 0);
  if ((*X60Qx_815).kind_0 == 6){
    nimStrDestroy(X60Qx_21);
    Value_0_valzr1t4f* X60Qx_816 = getQ_7_Ine8yq71_intzsnzax(args_3, 0);
    string_0_sysvq0asl X60Qx_817 = nimStrDup((*X60Qx_816).sval_0);
    X60Qx_21 = X60Qx_817;}
  else {
    nimStrDestroy(X60Qx_21);
    Value_0_valzr1t4f* X60Qx_818 = getQ_7_Ine8yq71_intzsnzax(args_3, 0);
    Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_818);
    string_0_sysvq0asl X60Qx_819 = ptrToString_0_runot4689((&X60QconstRefTemp_0));
    X60Qx_21 = X60Qx_819;}
  nimStrDestroy(result_71);
  result_71 = X60Qx_21;
  nimStrWasMoved((&X60Qx_21));
  nimStrDestroy(X60Qx_21);
  return result_71;
  nimStrDestroy(X60Qx_21);
  return result_71;}
void leAppend_0_runot4689(string_0_sysvq0asl* s_3, NI32 x_5, NI32 nbytes_0){
  NU64 v_34 = ((NU64)((NU64)x_5));
  NI32 i_38 = 0;
  {
    while (i_38 < nbytes_0){
      add_1_sysvq0asl(s_3, ((NC8)((NU8)((NU64)(v_34 & ((NU64)255u))))));
      v_34 = ((NU64)(v_34 >> ((NU64)8u)));
      inc_1_I6wjjge_aow2h993l1((&i_38));}}
  whileStmtLabel_0: ;}
NI32 leAt_0_runot4689(string_0_sysvq0asl s_4, NI32 off_0, NI32 nbytes_1){
  NI32 result_72;
  NU64 v_35 = ((NU64)0u);
  NI32 i_39 = ((NI32)(nbytes_1 - 1));
  {
    while (0 <= i_39){
      NU64 X60Qx_22;
      NI32 X60Qx_820 = len_4_sysvq0asl(s_4);
      if (((NI32)(off_0 + i_39)) < X60Qx_820){
        NC8 X60Qx_821 = getQ_9_sysvq0asl(s_4, ((NI32)(off_0 + i_39)));
        X60Qx_22 = ((NU64)((NU8)X60Qx_821));}
      else {
        X60Qx_22 = ((NU64)0u);}
      NU64 b_9 = X60Qx_22;
      v_35 = ((NU64)(((NU64)(v_35 << ((NU64)8u))) | b_9));
      dec_1_I0nzoz91_aow7lb5cq1((&i_39));}}
  whileStmtLabel_0: ;
  result_72 = ((NI32)v_35);
  return result_72;}
NI32 sockIntField_0_runot4689(Value_0_valzr1t4f* v_26, string_0_sysvq0asl base_7, NB8* found_3){
  NI32 result_73;
  (*found_3) = NIM_FALSE;
  result_73 = 0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_19 = fieldCellByBase_0_runot4689((&(*v_26)), base_7);
  if (c_19 == NIM_NIL){
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_19);
    return result_73;}
  (*found_3) = NIM_TRUE;
  NI64 X60Qx_822 = asInt_0_valzr1t4f((&(*c_19).d_00.v_0));
  result_73 = ((NI32)X60Qx_822);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_19);
  return result_73;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_19);
  return result_73;}
string_0_sysvq0asl sockAddrImage_0_runot4689(Value_0_valzr1t4f* v_27, string_0_sysvq0asl* kind_0){
  string_0_sysvq0asl result_74;
  nimStrWasMoved((&result_74));
  nimStrDestroy(result_74);
  result_74 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  nimStrDestroy((*kind_0));
  (*kind_0) = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 has_0 = NIM_FALSE;
  NI32 fam4_0 = sockIntField_0_runot4689((&(*v_27)), (string_0_sysvq0asl){
    .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I6086898244938667450_runot4689)}
  , (&has_0));
  if (has_0){
    nimStrDestroy((*kind_0));
    (*kind_0) = (string_0_sysvq0asl){
      .bytes_0 = 3438082u, .more_0 = NIM_NIL}
    ;
    NI32 port_0 = 0;
    NI32 a_9 = 0;
    NB8 f2_0 = NIM_FALSE;
    NI32 X60Qx_823 = sockIntField_0_runot4689((&(*v_27)), (string_0_sysvq0asl){
      .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I1630993779792733486_runot4689)}
    , (&f2_0));
    port_0 = X60Qx_823;
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* ac_0 = fieldCellByBase_0_runot4689((&(*v_27)), (string_0_sysvq0asl){
      .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I9145615580426605709_runot4689)}
    );
    if ((!(ac_0 == NIM_NIL))){
      NB8 f3_0 = NIM_FALSE;
      NI32 X60Qx_824 = sockIntField_0_runot4689((&(*ac_0).d_00.v_0), (string_0_sysvq0asl){
        .bytes_0 = 1633645566u, .more_0 = (&strlit_0_I4274381415279064279_runot4689)}
      , (&f3_0));
      a_9 = X60Qx_824;}
    leAppend_0_runot4689((&result_74), fam4_0, 2);
    leAppend_0_runot4689((&result_74), port_0, 2);
    leAppend_0_runot4689((&result_74), a_9, 4);
    leAppend_0_runot4689((&result_74), 0, 4);
    leAppend_0_runot4689((&result_74), 0, 4);
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(ac_0);
    return result_74;
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(ac_0);}
  NI32 fam6_0 = sockIntField_0_runot4689((&(*v_27)), (string_0_sysvq0asl){
    .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I13270768669503881230_runot4689)}
  , (&has_0));
  if (has_0){
    nimStrDestroy((*kind_0));
    (*kind_0) = (string_0_sysvq0asl){
      .bytes_0 = 3569154u, .more_0 = NIM_NIL}
    ;
    NI32 X60Qx_825 = fam6_0;
    return result_74;}
  return result_74;}
void failSockV6_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_12, string_0_sysvq0asl nativeName_0){
  NI32 X60Qx_826 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I6128741239358766604_runot4689)}
  );
  NI32 X60Qx_827 = len_4_sysvq0asl(nativeName_0);
  NI32 X60Qx_828 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3793758206u, .more_0 = (&strlit_0_I5854685259221891605_runot4689)}
  );
  NI32 X60Qx_829 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I4584856981448071874_runot4689)}
  );
  NI32 X60Qx_830 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 544175102u, .more_0 = (&strlit_0_I18228840873349803156_runot4689)}
  );
  NI32 X60Qx_831 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1667592958u, .more_0 = (&strlit_0_I14411341024074226062_runot4689)}
  );
  NI32 X60Qx_832 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I7782505738835258833_runot4689)}
  );
  NI32 X60Qx_833 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1463898878u, .more_0 = (&strlit_0_I8261414620968001461_runot4689)}
  );
  string_0_sysvq0asl X60Qdesugar_18 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_826 + X60Qx_827)) + X60Qx_828)) + X60Qx_829)) + X60Qx_830)) + X60Qx_831)) + X60Qx_832)) + X60Qx_833)));
  add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I6128741239358766604_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_18), nativeName_0);
  add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
    .bytes_0 = 3793758206u, .more_0 = (&strlit_0_I5854685259221891605_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
    .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I4584856981448071874_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
    .bytes_0 = 544175102u, .more_0 = (&strlit_0_I18228840873349803156_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
    .bytes_0 = 1667592958u, .more_0 = (&strlit_0_I14411341024074226062_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
    .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I7782505738835258833_runot4689)}
  );
  add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
    .bytes_0 = 1463898878u, .more_0 = (&strlit_0_I8261414620968001461_runot4689)}
  );
  string_0_sysvq0asl msg_2 = X60Qdesugar_18;
  nimStrWasMoved((&X60Qdesugar_18));
  if ((!(*sink_12).d_00.didQQuit_0)){
    add_2_sysvq0asl((&(*sink_12).d_00.errBuf_0), msg_2);
    doQQuit_0_natd5co251(sink_12, 1);}
  nimStrDestroy(msg_2);
  nimStrDestroy(X60Qdesugar_18);}
void writeSockAddrBack_0_runot4689(Value_0_valzr1t4f* v_28, string_0_sysvq0asl sa_0){
  ptrWriteBytes_0_runot4689((&(*v_28)), sa_0);}
string_0_sysvq0asl sockOptBytes_0_runot4689(Value_0_valzr1t4f* v_29, NI32 n_3){
  string_0_sysvq0asl result_75;
  nimStrWasMoved((&result_75));
  nimStrDestroy(result_75);
  string_0_sysvq0asl X60Qx_834 = ptrReadBytes_0_runot4689((&(*v_29)), n_3);
  result_75 = X60Qx_834;
  NI32 X60Qx_835 = len_4_sysvq0asl(result_75);
  if (X60Qx_835 < n_3){
    NI32 i_40 = len_4_sysvq0asl(result_75);
    {
      while (i_40 < n_3){
        add_1_sysvq0asl((&result_75), (NC8)'\000');
        inc_1_I6wjjge_aow2h993l1((&i_40));}}
    whileStmtLabel_0: ;}
  return result_75;}
Value_0_valzr1t4f nativeArm_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_13, string_0_sysvq0asl name_6, seq_0_I50urnw_croph25r5 args_4){
  Value_0_valzr1t4f result_76;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_836 = vNil_0_valzr1t4f();
  result_76 = X60Qx_836;
  NB8 X60Qx_837 = policyOn_0_iop7yt73v();
  if (X60Qx_837){
    NI32 needed_0 = capsNeeded_0_iop7yt73v(name_6);
    if ((!(needed_0 == 0))){
      string_0_sysvq0asl X60Qx_23;
      nimStrWasMoved((&X60Qx_23));
      if ((!(((NI32)(needed_0 & ((NI32)(((NI32)(((NI32)1) | ((NI32)2))) | ((NI32)4))))) == 0))){
        nimStrDestroy(X60Qx_23);
        string_0_sysvq0asl X60Qx_838 = policyPathOf_0_runot4689(name_6, args_4);
        X60Qx_23 = X60Qx_838;}
      else {
        nimStrDestroy(X60Qx_23);
        X60Qx_23 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;}
      string_0_sysvq0asl p_0 = X60Qx_23;
      nimStrWasMoved((&X60Qx_23));
      NB8 X60Qx_839 = policyDeniesPath_0_iop7yt73v(name_6, p_0, (&needed_0));
      if (X60Qx_839){
        recordViolation_1_iop7yt73v(name_6, needed_0);
        if ((!(*sink_13).d_00.didQQuit_0)){
          string_0_sysvq0asl X60Qtmp_132 = policyMessage_1_iop7yt73v(name_6, needed_0, p_0);
          add_2_sysvq0asl((&(*sink_13).d_00.errBuf_0), X60Qtmp_132);
          doQQuit_0_natd5co251(sink_13, ((NI32)77));
          nimStrDestroy(X60Qtmp_132);}
        Value_0_valzr1t4f X60Qx_840 = vNil_0_valzr1t4f();
        result_76 = X60Qx_840;
        nimStrDestroy(p_0);
        nimStrDestroy(X60Qx_23);
        return result_76;}
      NB8 X60Qx_841;
      NB8 X60Qx_842;
      NB8 X60Qx_843 = readAuditOn_0_iop7yt73v();
      if (X60Qx_843){
        NI32 X60Qx_844 = len_4_sysvq0asl(p_0);
        X60Qx_842 = (0 < X60Qx_844);}
      else {
        X60Qx_842 = NIM_FALSE;}
      if (X60Qx_842){
        NB8 X60Qx_845;
        NB8 X60Qx_846 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
          .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
        );
        if (X60Qx_846){
          X60Qx_845 = NIM_TRUE;}
        else {
          NB8 X60Qx_847 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
            .bytes_0 = 1886349054u, .more_0 = (&strlit_0_I754749039837241777_iop7yt73v)}
          );
          X60Qx_845 = X60Qx_847;}
        X60Qx_841 = X60Qx_845;}
      else {
        X60Qx_841 = NIM_FALSE;}
      if (X60Qx_841){
        recordOpen_0_iop7yt73v(p_0);}
      nimStrDestroy(p_0);
      nimStrDestroy(X60Qx_23);}}
  NB8 X60Qtc_296 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'m');
  if (X60Qtc_296){
    NB8 X60Qtc_297 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'n');
    if (X60Qtc_297){
      NB8 X60Qtc_298 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'l');
      if (X60Qtc_298){
        NB8 X60Qtc_299 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'c');
        if (X60Qtc_299){
          NB8 X60Qtc_300 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'b');
          if (X60Qtc_300){
            NB8 X60Qtc_301 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'c');
            if (X60Qtc_301){
              NB8 X60Qtc_302 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'L');
              if (X60Qtc_302){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1230984190u, .more_0 = (&strlit_0_I16052506731142050930_runot4689)}
                )){
                  goto X60Qsc_184;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1230984190u, .more_0 = (&strlit_0_I7311313444739886319_runot4689)}
                )){
                  goto X60Qsc_185;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1667457534u, .more_0 = (&strlit_0_I4398256179715674167_iop7yt73v)}
                )){
                  goto X60Qsc_155;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1230984190u, .more_0 = (&strlit_0_I17683665254279387272_runot4689)}
                )){
                  goto X60Qsc_183;}}}
            else {
              NB8 X60Qtc_303 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'_');
              if (X60Qtc_303){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1936089086u, .more_0 = (&strlit_0_I16850029409187227929_runot4689)}
                )){
                  goto X60Qsc_216;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952866302u, .more_0 = (&strlit_0_I15896652137124894441_runot4689)}
                )){
                  goto X60Qsc_217;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1852400382u, .more_0 = (&strlit_0_I18337270522941735704_iop7yt73v)}
                )){
                  goto X60Qsc_153;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1734697726u, .more_0 = (&strlit_0_I17823405900913585998_runot4689)}
                )){
                  goto X60Qsc_206;}}}}
          else {
            NB8 X60Qtc_304 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'i');
            if (X60Qtc_304){
              NB8 X60Qtc_305 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'_');
              if (X60Qtc_305){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I12734185539917726554_runot4689)}
                )){
                  goto X60Qsc_222;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1734304766u, .more_0 = (&strlit_0_I17733383591063213526_runot4689)}
                )){
                  goto X60Qsc_223;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1768252414u, .more_0 = (&strlit_0_I9007462764285996300_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1768252414u, .more_0 = (&strlit_0_I13338309813228285486_runot4689)}
                )){
                  goto X60Qsc_263;}}}
            else {
              NB8 X60Qtc_306 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'o');
              if (X60Qtc_306){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I15469864145960116068_runot4689)}
                )){
                  goto X60Qsc_169;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1818190846u, .more_0 = (&strlit_0_I2756518269131387936_runot4689)}
                )){
                  goto X60Qsc_267;}}
              else {
                NB8 X60Qtc_307 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'s');
                if (X60Qtc_307){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1935631358u, .more_0 = (&strlit_0_I12271947912804281422_runot4689)}
                  )){
                    goto X60Qsc_229;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1935631358u, .more_0 = (&strlit_0_I3004431710427040048_runot4689)}
                  )){
                    goto X60Qsc_269;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1969185790u, .more_0 = (&strlit_0_I261076703518422676_runot4689)}
                  )){
                    goto X60Qsc_232;}}}}}}
        else {
          NB8 X60Qtc_308 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'l');
          if (X60Qtc_308){
            NB8 X60Qtc_309 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'d');
            if (X60Qtc_309){
              NB8 X60Qtc_310 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'a');
              if (X60Qtc_310){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634034942u, .more_0 = (&strlit_0_I13706781941607385374_flaksyopx1)}
                )){
                  goto X60Qsc_279;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634034942u, .more_0 = (&strlit_0_I3331562609906234561_runot4689)}
                )){
                  goto X60Qsc_295;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I11216437567223755660_iop7yt73v)}
                )){
                  goto X60Qsc_227;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I7523013755933230041_runot4689)}
                )){
                  goto X60Qsc_259;}}}
            else {
              NB8 X60Qtc_311 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'g');
              if (X60Qtc_311){
                NB8 X60Qtc_312 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'e');
                if (X60Qtc_312){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I8996502465535440862_runot4689)}
                  )){
                    goto X60Qsc_198;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1634168062u, .more_0 = (&strlit_0_I17537008619994765435_runot4689)}
                  )){
                    goto X60Qsc_263;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1634168062u, .more_0 = (&strlit_0_I13165182437724203393_runot4689)}
                  )){
                    goto X60Qsc_263;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634495742u, .more_0 = (&strlit_0_I13332988580619513941_runot4689)}
                )){
                  goto X60Qsc_202;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1734961406u, .more_0 = (&strlit_0_I8566804573867139999_nimry5ra91)}
                )){
                  goto X60Qsc_241;}}}}
          else {
            NB8 X60Qtc_313 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'s');
            if (X60Qtc_313){
              NB8 X60Qtc_314 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'f');
              if (X60Qtc_314){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869440766u, .more_0 = (&strlit_0_I2902005617748064841_runot4689)}
                )){
                  goto X60Qsc_264;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869440766u, .more_0 = (&strlit_0_I4315280164913964871_runot4689)}
                )){
                  goto X60Qsc_264;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1935763710u, .more_0 = (&strlit_0_I17711552707752383867_runot4689)}
                )){
                  goto X60Qsc_191;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1835100158u, .more_0 = (&strlit_0_I11575531321635900188_runot4689)}
                )){
                  goto X60Qsc_263;}}}
            else {
              NB8 X60Qtc_315 = nimStrAtLe_0_sysvq0asl(name_6, 6, (NC8)'r');
              if (X60Qtc_315){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I3006705858755300605_iop7yt73v)}
                )){
                  goto X60Qsc_171;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I4303973984874128508_intzsnzax)}
                )){
                  goto X60Qsc_173;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I10744707227501835447_runot4689)}
                )){
                  goto X60Qsc_223;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I4300154733488353634_iop7yt73v)}
                )){
                  goto X60Qsc_224;}}}}}}
      else {
        NB8 X60Qtc_316 = nimStrAtLe_0_sysvq0asl(name_6, 5, (NC8)'q');
        if (X60Qtc_316){
          NB8 X60Qtc_317 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'a');
          if (X60Qtc_317){
            NB8 X60Qtc_318 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'L');
            if (X60Qtc_318){
              NB8 X60Qtc_319 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'C');
              if (X60Qtc_319){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I4978164850318270062_croph25r5)}
                )){
                  goto X60Qsc_234;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I3411051090140283573_croph25r5)}
                )){
                  goto X60Qsc_236;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I2027400509069786846_croph25r5)}
                )){
                  goto X60Qsc_190;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I12542130669033277445_croph25r5)}
                )){
                  goto X60Qsc_233;}}}
            else {
              NB8 X60Qtc_320 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'r');
              if (X60Qtc_320){
                NB8 X60Qtc_321 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'d');
                if (X60Qtc_321){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I7514604024534592575_intzsnzax)}
                  )){
                    goto X60Qsc_205;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I7466143617196742693_intzsnzax)}
                  )){
                    goto X60Qsc_205;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I8010039202931761952_flaksyopx1)}
                  )){
                    goto X60Qsc_280;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634170110u, .more_0 = (&strlit_0_I13587882791461032424_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634170110u, .more_0 = (&strlit_0_I528020226223869869_runot4689)}
                )){
                  goto X60Qsc_263;}}}}
          else {
            NB8 X60Qtc_322 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'r');
            if (X60Qtc_322){
              NB8 X60Qtc_323 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'p');
              if (X60Qtc_323){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I2460192712881505125_runot4689)}
                )){
                  goto X60Qsc_238;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I6254854690921100046_runot4689)}
                )){
                  goto X60Qsc_239;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1919448062u, .more_0 = (&strlit_0_I12927204854279428474_runot4689)}
                )){
                  goto X60Qsc_256;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1734964222u, .more_0 = (&strlit_0_I17762169876133351355_runot4689)}
                )){
                  goto X60Qsc_269;}}}
            else {
              NB8 X60Qtc_324 = nimStrAtLe_0_sysvq0asl(name_6, 6, (NC8)'U');
              if (X60Qtc_324){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I17462820957681339184_runot4689)}
                )){
                  goto X60Qsc_253;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I11042971208590088895_intzsnzax)}
                )){
                  goto X60Qsc_253;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I3225684998187034911_intzsnzax)}
                )){
                  goto X60Qsc_253;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I590530705459077169_runot4689)}
                )){
                  goto X60Qsc_255;}}}}}
        else {
          NB8 X60Qtc_325 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'r');
          if (X60Qtc_325){
            NB8 X60Qtc_326 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'d');
            if (X60Qtc_326){
              NB8 X60Qtc_327 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'e');
              if (X60Qtc_327){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I6395244567427789796_croph25r5)}
                )){
                  goto X60Qsc_218;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I13171408700689225719_runot4689)}
                )){
                  goto X60Qsc_235;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1684762110u, .more_0 = (&strlit_0_I11697234225982197076_hos1fpv3m1)}
                )){
                  goto X60Qsc_151;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1684894462u, .more_0 = (&strlit_0_I13735625106940001307_hos1fpv3m1)}
                )){
                  goto X60Qsc_151;}}}
            else {
              NB8 X60Qtc_328 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'n');
              if (X60Qtc_328){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I16799243069367891670_runot4689)}
                )){
                  goto X60Qsc_254;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I11206267958496974357_runot4689)}
                )){
                  goto X60Qsc_254;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I2442484592079803371_runot4689)}
                )){
                  goto X60Qsc_195;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1885958398u, .more_0 = (&strlit_0_I2227768086840020110_runot4689)}
                )){
                  goto X60Qsc_212;}}}}
          else {
            NB8 X60Qtc_329 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'f');
            if (X60Qtc_329){
              NB8 X60Qtc_330 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'n');
              if (X60Qtc_330){
                NB8 X60Qtc_331 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'s');
                if (X60Qtc_331){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1852142590u, .more_0 = (&strlit_0_I13696262612503621358_iop7yt73v)}
                  )){
                    goto X60Qsc_159;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I4037024720053716733_runot4689)}
                  )){
                    goto X60Qsc_263;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1851880702u, .more_0 = (&strlit_0_I2842093187128652953_runot4689)}
                  )){
                    goto X60Qsc_263;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I900530018976380608_intzsnzax)}
                )){
                  goto X60Qsc_174;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I11492332034473653383_runot4689)}
                )){
                  goto X60Qsc_229;}}}
            else {
              NB8 X60Qtc_332 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'s');
              if (X60Qtc_332){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I11806394720139207185_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I3542826059153545742_runot4689)}
                )){
                  goto X60Qsc_263;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1851880702u, .more_0 = (&strlit_0_I3069983570459151989_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1851880702u, .more_0 = (&strlit_0_I13572268722964477183_runot4689)}
                )){
                  goto X60Qsc_263;}}}}}}}
    else {
      NB8 X60Qtc_333 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'a');
      if (X60Qtc_333){
        NB8 X60Qtc_334 = nimStrAtLe_0_sysvq0asl(name_6, 6, (NC8)'l');
        if (X60Qtc_334){
          NB8 X60Qtc_335 = nimStrAtLe_0_sysvq0asl(name_6, 9, (NC8)'l');
          if (X60Qtc_335){
            NB8 X60Qtc_336 = nimStrAtLe_0_sysvq0asl(name_6, 9, (NC8)'e');
            if (X60Qtc_336){
              NB8 X60Qtc_337 = nimStrAtLe_0_sysvq0asl(name_6, 10, (NC8)'l');
              if (X60Qtc_337){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I6360057863985801792_runot4689)}
                )){
                  goto X60Qsc_284;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I7416523361519930235_runot4689)}
                )){
                  goto X60Qsc_293;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I8017305591929431070_runot4689)}
                )){
                  goto X60Qsc_290;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I6911048140413447969_runot4689)}
                )){
                  goto X60Qsc_291;}}}
            else {
              NB8 X60Qtc_338 = nimStrAtLe_0_sysvq0asl(name_6, 9, (NC8)'f');
              if (X60Qtc_338){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I14794290808105000385_runot4689)}
                )){
                  goto X60Qsc_288;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I2721612651281431750_runot4689)}
                )){
                  goto X60Qsc_289;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I17978188014264979010_runot4689)}
                )){
                  goto X60Qsc_268;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I15330224518915338745_runot4689)}
                )){
                  goto X60Qsc_286;}}}}
          else {
            NB8 X60Qtc_339 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'_');
            if (X60Qtc_339){
              NB8 X60Qtc_340 = nimStrAtLe_0_sysvq0asl(name_6, 9, (NC8)'s');
              if (X60Qtc_340){
                NB8 X60Qtc_341 = nimStrAtLe_0_sysvq0asl(name_6, 10, (NC8)'t');
                if (X60Qtc_341){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I6562023223248407785_runot4689)}
                  )){
                    goto X60Qsc_287;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I6014013695438108326_runot4689)}
                  )){
                    goto X60Qsc_294;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I13618388896102550277_runot4689)}
                  )){
                    goto X60Qsc_285;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I9961550407930830585_runot4689)}
                )){
                  goto X60Qsc_292;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I4918636105606565444_runot4689)}
                )){
                  goto X60Qsc_294;}}}
            else {
              NB8 X60Qtc_342 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'r');
              if (X60Qtc_342){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I5557876643816385366_runot4689)}
                )){
                  goto X60Qsc_219;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I1425867270648381196_runot4689)}
                )){
                  goto X60Qsc_221;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I267265874032566585_runot4689)}
                )){
                  goto X60Qsc_216;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I9020750254248281358_runot4689)}
                )){
                  goto X60Qsc_217;}}}}}
        else {
          NB8 X60Qtc_343 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'f');
          if (X60Qtc_343){
            NB8 X60Qtc_344 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'b');
            if (X60Qtc_344){
              NB8 X60Qtc_345 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'f');
              if (X60Qtc_345){
                NB8 X60Qtc_346 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'[');
                if (X60Qtc_346){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1029528323u, .more_0 = NIM_NIL}
                  )){
                    goto X60Qsc_245;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1650550526u, .more_0 = (&strlit_0_I15442353845339373309_runot4689)}
                  )){
                    goto X60Qsc_203;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1650550526u, .more_0 = (&strlit_0_I11888325900615031473_runot4689)}
                  )){
                    goto X60Qsc_203;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1650552062u, .more_0 = (&strlit_0_I1015435270754762846_runot4689)}
                )){
                  goto X60Qsc_202;}}}
            else {
              NB8 X60Qtc_347 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'_');
              if (X60Qtc_347){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1700749310u, .more_0 = (&strlit_0_I10587700194469857770_runot4689)}
                )){
                  goto X60Qsc_164;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1700749310u, .more_0 = (&strlit_0_I2935065715245494111_runot4689)}
                )){
                  goto X60Qsc_164;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I829494218257581341_runot4689)}
                )){
                  goto X60Qsc_220;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I6629672319202990767_runot4689)}
                )){
                  goto X60Qsc_266;}}}}
          else {
            NB8 X60Qtc_348 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'p');
            if (X60Qtc_348){
              NB8 X60Qtc_349 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'n');
              if (X60Qtc_349){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1851880451u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1767859198u, .more_0 = (&strlit_0_I16869611209385436378_runot4689)}
                )){
                  goto X60Qsc_270;}}
              else {
                NB8 X60Qtc_350 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'r');
                if (X60Qtc_350){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1885299710u, .more_0 = (&strlit_0_I5077193025928916746_runot4689)}
                  )){
                    goto X60Qsc_265;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1885299710u, .more_0 = (&strlit_0_I14098594833283830517_runot4689)}
                  )){
                    goto X60Qsc_230;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1885299710u, .more_0 = (&strlit_0_I17773428354037550576_runot4689)}
                  )){
                    goto X60Qsc_231;}}}}
            else {
              NB8 X60Qtc_351 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'=');
              if (X60Qtc_351){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 4013314u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_248;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 4013058u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_251;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 6118146u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_244;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1935631358u, .more_0 = (&strlit_0_I11458864696903921954_runot4689)}
                )){
                  goto X60Qsc_272;}}}}}}
      else {
        NB8 X60Qtc_352 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'l');
        if (X60Qtc_352){
          NB8 X60Qtc_353 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'e');
          if (X60Qtc_353){
            NB8 X60Qtc_354 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'c');
            if (X60Qtc_354){
              NB8 X60Qtc_355 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'f');
              if (X60Qtc_355){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1919050750u, .more_0 = (&strlit_0_I18389659094084831927_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I10412889024785430365_runot4689)}
                )){
                  goto X60Qsc_263;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I5124821916304759024_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I8283530786494002228_runot4689)}
                )){
                  goto X60Qsc_263;}}}
            else {
              NB8 X60Qtc_356 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'r');
              if (X60Qtc_356){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1852008190u, .more_0 = (&strlit_0_I916283243853797056_runot4689)}
                )){
                  goto X60Qsc_162;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1919253246u, .more_0 = (&strlit_0_I14137437451056432656_flaksyopx1)}
                )){
                  goto X60Qsc_275;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I15988237883286942751_runot4689)}
                )){
                  goto X60Qsc_156;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I14102593084845164639_hos1fpv3m1)}
                )){
                  goto X60Qsc_170;}}}}
          else {
            NB8 X60Qtc_357 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'a');
            if (X60Qtc_357){
              NB8 X60Qtc_358 = nimStrAtLe_0_sysvq0asl(name_6, 6, (NC8)'i');
              if (X60Qtc_358){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I5348593791521339691_intzsnzax)}
                )){
                  goto X60Qsc_278;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I13537887754319196487_intzsnzax)}
                )){
                  goto X60Qsc_278;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I10175009822598077709_flaksyopx1)}
                )){
                  goto X60Qsc_277;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I6624701989437400523_flaksyopx1)}
                )){
                  goto X60Qsc_277;}}}
            else {
              NB8 X60Qtc_359 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'c');
              if (X60Qtc_359){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I10138590777481088495_iop7yt73v)}
                )){
                  goto X60Qsc_177;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I4266325610518786829_croph25r5)}
                )){
                  goto X60Qsc_213;}}
              else {
                NB8 X60Qtc_360 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'l');
                if (X60Qtc_360){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1936289022u, .more_0 = (&strlit_0_I15031238125720431605_iop7yt73v)}
                  )){
                    goto X60Qsc_154;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1701275390u, .more_0 = (&strlit_0_I3797353385083767601_runot4689)}
                  )){
                    goto X60Qsc_222;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1969779710u, .more_0 = (&strlit_0_I7911372692567978064_runot4689)}
                  )){
                    goto X60Qsc_161;}}}}}}
        else {
          NB8 X60Qtc_361 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'s');
          if (X60Qtc_361){
            NB8 X60Qtc_362 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'f');
            if (X60Qtc_362){
              NB8 X60Qtc_363 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'i');
              if (X60Qtc_363){
                NB8 X60Qtc_364 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'a');
                if (X60Qtc_364){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I2255282174144548766_runot4689)}
                  )){
                    goto X60Qsc_263;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1919510270u, .more_0 = (&strlit_0_I4165263228779136726_runot4689)}
                  )){
                    goto X60Qsc_196;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1818453758u, .more_0 = (&strlit_0_I3644943614415463836_runot4689)}
                  )){
                    goto X60Qsc_214;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I13770135642222982414_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I4103505614328324962_runot4689)}
                )){
                  goto X60Qsc_263;}}}
            else {
              NB8 X60Qtc_365 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'g');
              if (X60Qtc_365){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I15485922392778096779_runot4689)}
                )){
                  goto X60Qsc_156;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I10535682057815138895_runot4689)}
                )){
                  goto X60Qsc_158;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I399834492833889323_iop7yt73v)}
                )){
                  goto X60Qsc_157;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634561534u, .more_0 = (&strlit_0_I1291718626454456793_runot4689)}
                )){
                  goto X60Qsc_180;}}}}
          else {
            NB8 X60Qtc_366 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'c');
            if (X60Qtc_366){
              NB8 X60Qtc_367 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'a');
              if (X60Qtc_367){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1935827203u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_202;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1684300035u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_243;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1886216963u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_249;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1919050750u, .more_0 = (&strlit_0_I8970872227344634284_runot4689)}
                )){
                  goto X60Qsc_263;}}}
            else {
              NB8 X60Qtc_368 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'l');
              if (X60Qtc_368){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1852140547u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_240;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1818584067u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_258;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1667592958u, .more_0 = (&strlit_0_I8779604385735337050_iop7yt73v)}
                )){
                  goto X60Qsc_160;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1852404483u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_263;}}}}}}}}
  else {
    NB8 X60Qtc_369 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'k');
    if (X60Qtc_369){
      NB8 X60Qtc_370 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'o');
      if (X60Qtc_370){
        NB8 X60Qtc_371 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'c');
        if (X60Qtc_371){
          NB8 X60Qtc_372 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'r');
          if (X60Qtc_372){
            NB8 X60Qtc_373 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'a');
            if (X60Qtc_373){
              NB8 X60Qtc_374 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'s');
              if (X60Qtc_374){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I5698419940050250200_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I4547290982746310667_intzsnzax)}
                )){
                  goto X60Qsc_282;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I1534576491481833817_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I891118288292861849_runot4689)}
                )){
                  goto X60Qsc_264;}}}
            else {
              NB8 X60Qtc_375 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'n');
              if (X60Qtc_375){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I9620132962526484305_iop7yt73v)}
                )){
                  goto X60Qsc_153;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I5781888230858571977_runot4689)}
                )){
                  goto X60Qsc_237;}}
              else {
                NB8 X60Qtc_376 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'p');
                if (X60Qtc_376){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I9772346370466888830_runot4689)}
                  )){
                    goto X60Qsc_264;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I16513080964259093980_flaksyopx1)}
                  )){
                    goto X60Qsc_273;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1936679934u, .more_0 = (&strlit_0_I16778293019659317075_runot4689)}
                  )){
                    goto X60Qsc_263;}}}}}
          else {
            NB8 X60Qtc_377 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'f');
            if (X60Qtc_377){
              NB8 X60Qtc_378 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'2');
              if (X60Qtc_378){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1635017214u, .more_0 = (&strlit_0_I14583999013692158065_runot4689)}
                )){
                  goto X60Qsc_264;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1635017214u, .more_0 = (&strlit_0_I7452096862806559312_runot4689)}
                )){
                  goto X60Qsc_264;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769169406u, .more_0 = (&strlit_0_I18319326863888772702_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1635017214u, .more_0 = (&strlit_0_I5382018615177490518_runot4689)}
                )){
                  goto X60Qsc_263;}}}
            else {
              NB8 X60Qtc_379 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'s');
              if (X60Qtc_379){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769169406u, .more_0 = (&strlit_0_I15785994502496746995_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769169406u, .more_0 = (&strlit_0_I17120658844982687581_runot4689)}
                )){
                  goto X60Qsc_263;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1635017214u, .more_0 = (&strlit_0_I16113657126360930300_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1635017214u, .more_0 = (&strlit_0_I11603069084661078003_runot4689)}
                )){
                  goto X60Qsc_263;}}}}}
        else {
          NB8 X60Qtc_380 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'f');
          if (X60Qtc_380){
            NB8 X60Qtc_381 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'d');
            if (X60Qtc_381){
              NB8 X60Qtc_382 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'d');
              if (X60Qtc_382){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1684956670u, .more_0 = (&strlit_0_I16314744827495621298_runot4689)}
                )){
                  goto X60Qsc_193;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1668310782u, .more_0 = (&strlit_0_I12956148032481319733_runot4689)}
                )){
                  goto X60Qsc_268;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I4718597432102153922_hos1fpv3m1)}
                )){
                  goto X60Qsc_176;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1701996286u, .more_0 = (&strlit_0_I11259678733945033750_runot4689)}
                )){
                  goto X60Qsc_219;}}}
            else {
              NB8 X60Qtc_383 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'f');
              if (X60Qtc_383){
                NB8 X60Qtc_384 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'e');
                if (X60Qtc_384){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1718773246u, .more_0 = (&strlit_0_I1809801196744581258_runot4689)}
                  )){
                    goto X60Qsc_263;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1702061822u, .more_0 = (&strlit_0_I13358815423116982192_runot4689)}
                  )){
                    goto X60Qsc_216;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1702061822u, .more_0 = (&strlit_0_I16765359973108783593_runot4689)}
                  )){
                    goto X60Qsc_216;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1702063358u, .more_0 = (&strlit_0_I4457427298056883912_runot4689)}
                )){
                  goto X60Qsc_215;}}}}
          else {
            NB8 X60Qtc_385 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'f');
            if (X60Qtc_385){
              NB8 X60Qtc_386 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'o');
              if (X60Qtc_386){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I15089905067781246666_runot4689)}
                )){
                  goto X60Qsc_271;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I130460565633405389_runot4689)}
                )){
                  goto X60Qsc_271;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869768446u, .more_0 = (&strlit_0_I4459857122359951064_runot4689)}
                )){
                  goto X60Qsc_207;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1970300670u, .more_0 = (&strlit_0_I17605982152144906666_runot4689)}
                )){
                  goto X60Qsc_221;}}}
            else {
              NB8 X60Qtc_387 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'l');
              if (X60Qtc_387){
                NB8 X60Qtc_388 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'1');
                if (X60Qtc_388){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1735355646u, .more_0 = (&strlit_0_I10762679581578789876_runot4689)}
                  )){
                    goto X60Qsc_263;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1735355646u, .more_0 = (&strlit_0_I14090416911907227580_runot4689)}
                  )){
                    goto X60Qsc_263;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1735355646u, .more_0 = (&strlit_0_I3257461749309365855_runot4689)}
                  )){
                    goto X60Qsc_263;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1853189630u, .more_0 = (&strlit_0_I11647825660565427273_runot4689)}
                )){
                  goto X60Qsc_181;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1987014142u, .more_0 = (&strlit_0_I15154933186756103481_flaksyopx1)}
                )){
                  goto X60Qsc_274;}}}}}}
      else {
        NB8 X60Qtc_389 = nimStrAtLe_0_sysvq0asl(name_6, 8, (NC8)'m');
        if (X60Qtc_389){
          NB8 X60Qtc_390 = nimStrAtLe_0_sysvq0asl(name_6, 8, (NC8)'f');
          if (X60Qtc_390){
            NB8 X60Qtc_391 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'p');
            if (X60Qtc_391){
              NB8 X60Qtc_392 = nimStrAtLe_0_sysvq0asl(name_6, 8, (NC8)'a');
              if (X60Qtc_392){
                NB8 X60Qtc_393 = nimStrAtLe_0_sysvq0asl(name_6, 13, (NC8)'i');
                if (X60Qtc_393){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I17586706449769989679_runot4689)}
                  )){
                    goto X60Qsc_201;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I12455491439291898808_runot4689)}
                  )){
                    goto X60Qsc_201;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I7879418900251688251_runot4689)}
                  )){
                    goto X60Qsc_201;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I13575103462706389231_runot4689)}
                )){
                  goto X60Qsc_201;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I15101805001566300991_runot4689)}
                )){
                  goto X60Qsc_201;}}}
            else {
              NB8 X60Qtc_394 = nimStrAtLe_0_sysvq0asl(name_6, 5, (NC8)'B');
              if (X60Qtc_394){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I6178772090241098573_croph25r5)}
                )){
                  goto X60Qsc_186;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I100145031017624899_croph25r5)}
                )){
                  goto X60Qsc_186;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I3703669261441550327_croph25r5)}
                )){
                  goto X60Qsc_188;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I13565819874765507459_croph25r5)}
                )){
                  goto X60Qsc_228;}}}}
          else {
            NB8 X60Qtc_395 = nimStrAtLe_0_sysvq0asl(name_6, 13, (NC8)'_');
            if (X60Qtc_395){
              NB8 X60Qtc_396 = nimStrAtLe_0_sysvq0asl(name_6, 14, (NC8)'l');
              if (X60Qtc_396){
                NB8 X60Qtc_397 = nimStrAtLe_0_sysvq0asl(name_6, 14, (NC8)'i');
                if (X60Qtc_397){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I16307165221440279626_runot4689)}
                  )){
                    goto X60Qsc_201;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I7563958664671285564_runot4689)}
                  )){
                    goto X60Qsc_201;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I5520204047587305294_runot4689)}
                  )){
                    goto X60Qsc_201;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I2704167984537518126_runot4689)}
                )){
                  goto X60Qsc_201;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I12090117985479266910_runot4689)}
                )){
                  goto X60Qsc_201;}}}
            else {
              NB8 X60Qtc_398 = nimStrAtLe_0_sysvq0asl(name_6, 18, (NC8)'i');
              if (X60Qtc_398){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I7144656948613361609_runot4689)}
                )){
                  goto X60Qsc_201;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I15900191554327605035_runot4689)}
                )){
                  goto X60Qsc_201;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 2037544190u, .more_0 = (&strlit_0_I14251590839437571501_intzsnzax)}
                )){
                  goto X60Qsc_178;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I15453311318628242112_runot4689)}
                )){
                  goto X60Qsc_201;}}}}}
        else {
          NB8 X60Qtc_399 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'r');
          if (X60Qtc_399){
            NB8 X60Qtc_400 = nimStrAtLe_0_sysvq0asl(name_6, 15, (NC8)'t');
            if (X60Qtc_400){
              NB8 X60Qtc_401 = nimStrAtLe_0_sysvq0asl(name_6, 15, (NC8)'i');
              if (X60Qtc_401){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I5251620621223879244_runot4689)}
                )){
                  goto X60Qsc_201;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I10103062530166186202_runot4689)}
                )){
                  goto X60Qsc_201;}}
              else {
                NB8 X60Qtc_402 = nimStrAtLe_0_sysvq0asl(name_6, 15, (NC8)'r');
                if (X60Qtc_402){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I8777584587013623138_runot4689)}
                  )){
                    goto X60Qsc_201;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I9358368861162995182_runot4689)}
                  )){
                    goto X60Qsc_201;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I3165618862315308536_runot4689)}
                  )){
                    goto X60Qsc_201;}}}}
            else {
              NB8 X60Qtc_403 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'p');
              if (X60Qtc_403){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I3058267948028936567_runot4689)}
                )){
                  goto X60Qsc_201;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1752461566u, .more_0 = (&strlit_0_I2713340543544631928_runot4689)}
                )){
                  goto X60Qsc_201;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1970238206u, .more_0 = (&strlit_0_I16919077516905105311_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1970238206u, .more_0 = (&strlit_0_I11472341555409824841_runot4689)}
                )){
                  goto X60Qsc_263;}}}}
          else {
            NB8 X60Qtc_404 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'s');
            if (X60Qtc_404){
              NB8 X60Qtc_405 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'q');
              if (X60Qtc_405){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1668248574u, .more_0 = (&strlit_0_I15415642409673360391_iop7yt73v)}
                )){
                  goto X60Qsc_152;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1920037886u, .more_0 = (&strlit_0_I16230913145226539634_runot4689)}
                )){
                  goto X60Qsc_263;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I4050815769175754417_hos1fpv3m1)}
                )){
                  goto X60Qsc_172;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I10988075821851534954_runot4689)}
                )){
                  goto X60Qsc_204;}}}
            else {
              NB8 X60Qtc_406 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'i');
              if (X60Qtc_406){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I12440307187701028700_croph25r5)}
                )){
                  goto X60Qsc_187;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1332704510u, .more_0 = (&strlit_0_I13575662182318269178_runot4689)}
                )){
                  goto X60Qsc_261;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I10246663023455874512_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I17395397086815796959_runot4689)}
                )){
                  goto X60Qsc_263;}}}}}}}
    else {
      NB8 X60Qtc_407 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'h');
      if (X60Qtc_407){
        NB8 X60Qtc_408 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'r');
        if (X60Qtc_408){
          NB8 X60Qtc_409 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'o');
          if (X60Qtc_409){
            NB8 X60Qtc_410 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'r');
            if (X60Qtc_410){
              NB8 X60Qtc_411 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'c');
              if (X60Qtc_411){
                NB8 X60Qtc_412 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'b');
                if (X60Qtc_412){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1919902462u, .more_0 = (&strlit_0_I12973856256439326227_runot4689)}
                  )){
                    goto X60Qsc_207;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I4513720326185655066_runot4689)}
                  )){
                    goto X60Qsc_264;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I12200441697993125318_runot4689)}
                  )){
                    goto X60Qsc_264;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1684956670u, .more_0 = (&strlit_0_I8891710430887467064_runot4689)}
                )){
                  goto X60Qsc_208;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1886349054u, .more_0 = (&strlit_0_I754749039837241777_iop7yt73v)}
                )){
                  goto X60Qsc_211;}}}
            else {
              NB8 X60Qtc_413 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'h');
              if (X60Qtc_413){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1936679934u, .more_0 = (&strlit_0_I6681190863369851530_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1936679934u, .more_0 = (&strlit_0_I1951864687996922622_runot4689)}
                )){
                  goto X60Qsc_263;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1970234366u, .more_0 = (&strlit_0_I4889788401779984975_runot4689)}
                )){
                  goto X60Qsc_194;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1936679683u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_263;}}}}
          else {
            NB8 X60Qtc_414 = nimStrAtLe_0_sysvq0asl(name_6, 4, (NC8)'o');
            if (X60Qtc_414){
              NB8 X60Qtc_415 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'a');
              if (X60Qtc_415){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I1702282805285054051_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I930249616028346462_intzsnzax)}
                )){
                  goto X60Qsc_281;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1919969022u, .more_0 = (&strlit_0_I6858632851445378176_runot4689)}
                )){
                  goto X60Qsc_265;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1970365950u, .more_0 = (&strlit_0_I14385440250011608213_flaksyopx1)}
                )){
                  goto X60Qsc_276;}}}
            else {
              NB8 X60Qtc_416 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'c');
              if (X60Qtc_416){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1718773246u, .more_0 = (&strlit_0_I17767840746738081133_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I2856626897374252538_intzsnzax)}
                )){
                  goto X60Qsc_283;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1718772995u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1718773246u, .more_0 = (&strlit_0_I10901154011981123785_runot4689)}
                )){
                  goto X60Qsc_263;}}}}}
        else {
          NB8 X60Qtc_417 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'n');
          if (X60Qtc_417){
            NB8 X60Qtc_418 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'e');
            if (X60Qtc_418){
              NB8 X60Qtc_419 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'a');
              if (X60Qtc_419){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769169406u, .more_0 = (&strlit_0_I10698485606268199303_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1635017214u, .more_0 = (&strlit_0_I11456619178692440789_runot4689)}
                )){
                  goto X60Qsc_263;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I17971560687400798064_intzsnzax)}
                )){
                  goto X60Qsc_175;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I10712772139775900001_runot4689)}
                )){
                  goto X60Qsc_263;}}}
            else {
              NB8 X60Qtc_420 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'f');
              if (X60Qtc_420){
                NB8 X60Qtc_421 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'s');
                if (X60Qtc_421){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1953720062u, .more_0 = (&strlit_0_I17563301282676592437_iop7yt73v)}
                  )){
                    goto X60Qsc_182;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1702127358u, .more_0 = (&strlit_0_I10389925338050183997_runot4689)}
                  )){
                    goto X60Qsc_217;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1702127358u, .more_0 = (&strlit_0_I13386057973257435165_runot4689)}
                  )){
                    goto X60Qsc_217;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869900030u, .more_0 = (&strlit_0_I14144589816323362037_runot4689)}
                )){
                  goto X60Qsc_165;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869900030u, .more_0 = (&strlit_0_I14650401024631548577_runot4689)}
                )){
                  goto X60Qsc_166;}}}}
          else {
            NB8 X60Qtc_422 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'@');
            if (X60Qtc_422){
              NB8 X60Qtc_423 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'&');
              if (X60Qtc_423){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 9729u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_246;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 9217u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_247;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 15361u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_250;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 16385u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_252;}}}
            else {
              NB8 X60Qtc_424 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'e');
              if (X60Qtc_424){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769498110u, .more_0 = (&strlit_0_I7616721286816756_iop7yt73v)}
                )){
                  goto X60Qsc_225;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1886938371u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_263;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1887004926u, .more_0 = (&strlit_0_I2254028527881297604_runot4689)}
                )){
                  goto X60Qsc_264;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1887004926u, .more_0 = (&strlit_0_I8125595602251731014_runot4689)}
                )){
                  goto X60Qsc_264;}}}}}}
      else {
        NB8 X60Qtc_425 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'o');
        if (X60Qtc_425){
          NB8 X60Qtc_426 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'p');
          if (X60Qtc_426){
            NB8 X60Qtc_427 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'m');
            if (X60Qtc_427){
              NB8 X60Qtc_428 = nimStrAtLe_0_sysvq0asl(name_6, 3, (NC8)'f');
              if (X60Qtc_428){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1735355646u, .more_0 = (&strlit_0_I5383957453197838038_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1735355646u, .more_0 = (&strlit_0_I16777186388511288065_runot4689)}
                )){
                  goto X60Qsc_263;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1735355395u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1685024003u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_264;}}}
            else {
              NB8 X60Qtc_429 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'p');
              if (X60Qtc_429){
                NB8 X60Qtc_430 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'l');
                if (X60Qtc_430){
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1819242750u, .more_0 = (&strlit_0_I8961661824765813682_runot4689)}
                  )){
                    goto X60Qsc_163;}}
                else {
                  if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1886351614u, .more_0 = (&strlit_0_I5078203883954553591_runot4689)}
                  )){
                    goto X60Qsc_194;}
                  else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                    .bytes_0 = 1886351363u, .more_0 = NIM_NIL}
                  )){
                    goto X60Qsc_257;}}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1819178494u, .more_0 = (&strlit_0_I2912131129587157308_hos1fpv3m1)}
                )){
                  goto X60Qsc_151;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1131377918u, .more_0 = (&strlit_0_I11323202368322527013_runot4689)}
                )){
                  goto X60Qsc_209;}}}}
          else {
            NB8 X60Qtc_431 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'t');
            if (X60Qtc_431){
              NB8 X60Qtc_432 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'n');
              if (X60Qtc_432){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1936619006u, .more_0 = (&strlit_0_I15639938243715246193_runot4689)}
                )){
                  goto X60Qsc_232;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I6872392552133396222_runot4689)}
                )){
                  goto X60Qsc_260;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1953460990u, .more_0 = (&strlit_0_I3590215048999296526_runot4689)}
                )){
                  goto X60Qsc_199;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1953460990u, .more_0 = (&strlit_0_I12537729981146465730_runot4689)}
                )){
                  goto X60Qsc_200;}}}
            else {
              NB8 X60Qtc_433 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'l');
              if (X60Qtc_433){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 2003790851u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_242;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 7236610u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_263;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 2003791875u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_264;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 2003792126u, .more_0 = (&strlit_0_I3083679647149312804_runot4689)}
                )){
                  goto X60Qsc_264;}}}}}
        else {
          NB8 X60Qtc_434 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'p');
          if (X60Qtc_434){
            NB8 X60Qtc_435 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'n');
            if (X60Qtc_435){
              NB8 X60Qtc_436 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'l');
              if (X60Qtc_436){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1953721598u, .more_0 = (&strlit_0_I885514587362827984_iop7yt73v)}
                )){
                  goto X60Qsc_179;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1853057534u, .more_0 = (&strlit_0_I18238894324927972679_runot4689)}
                )){
                  goto X60Qsc_270;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869901566u, .more_0 = (&strlit_0_I17395640001380130172_runot4689)}
                )){
                  goto X60Qsc_167;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1869901566u, .more_0 = (&strlit_0_I10214058258048950411_runot4689)}
                )){
                  goto X60Qsc_168;}}}
            else {
              NB8 X60Qtc_437 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'r');
              if (X60Qtc_437){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
                )){
                  goto X60Qsc_210;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769107710u, .more_0 = (&strlit_0_I11258486380889900750_runot4689)}
                )){
                  goto X60Qsc_265;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1953853694u, .more_0 = (&strlit_0_I17106851413817154788_iop7yt73v)}
                )){
                  goto X60Qsc_226;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1953853694u, .more_0 = (&strlit_0_I10681429218388745297_runot4689)}
                )){
                  goto X60Qsc_230;}}}}
          else {
            NB8 X60Qtc_438 = nimStrAtLe_0_sysvq0asl(name_6, 2, (NC8)'a');
            if (X60Qtc_438){
              NB8 X60Qtc_439 = nimStrAtLe_0_sysvq0asl(name_6, 0, (NC8)'s');
              if (X60Qtc_439){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I10217866098611558294_iop7yt73v)}
                )){
                  goto X60Qsc_179;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I518833209856422221_runot4689)}
                )){
                  goto X60Qsc_192;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1634891006u, .more_0 = (&strlit_0_I12206775736441983472_runot4689)}
                )){
                  goto X60Qsc_197;}}}
            else {
              NB8 X60Qtc_440 = nimStrAtLe_0_sysvq0asl(name_6, 1, (NC8)'t');
              if (X60Qtc_440){
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1920037886u, .more_0 = (&strlit_0_I2622871807570587851_runot4689)}
                )){
                  goto X60Qsc_263;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I11298461363290321067_runot4689)}
                )){
                  goto X60Qsc_272;}}
              else {
                if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1769304574u, .more_0 = (&strlit_0_I16529604172406501048_intzsnzax)}
                )){
                  goto X60Qsc_189;}
                else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
                  .bytes_0 = 1651864574u, .more_0 = (&strlit_0_I10580268758365513846_runot4689)}
                )){
                  goto X60Qsc_262;}}}}}}}}
  goto X60Qsc_442;
  X60Qsc_151: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_848 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_848);
    string_0_sysvq0asl p_1 = ptrToString_0_runot4689((&X60QconstRefTemp_0));
    NI32 rc_0 = -1;
    if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
      .bytes_0 = 1684762110u, .more_0 = (&strlit_0_I11697234225982197076_hos1fpv3m1)}
    )){
      goto X60Qsc_443;}
    else if (equalStrings_0_sysvq0asl(name_6, (string_0_sysvq0asl){
      .bytes_0 = 1684894462u, .more_0 = (&strlit_0_I13735625106940001307_hos1fpv3m1)}
    )){
      goto X60Qsc_444;}
    goto X60Qsc_446;
    X60Qsc_443: ;
    NI32 X60Qx_849 = hostMkdir_0_hos1fpv3m1(p_1);
    rc_0 = X60Qx_849;
    goto X60Qsc_445;
    X60Qsc_444: ;
    NI32 X60Qx_850 = hostRmdir_0_hos1fpv3m1(p_1);
    rc_0 = X60Qx_850;
    goto X60Qsc_445;
    X60Qsc_446: ;
    NI32 X60Qx_851 = hostUnlink_0_hos1fpv3m1(p_1);
    rc_0 = X60Qx_851;
    X60Qsc_445: ;
    publishErrno_0_runot4689();
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_852 = vInt_0_valzr1t4f(((NI64)rc_0), 64);
    result_76 = X60Qx_852;
    nimStrDestroy(p_1);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_853 = vInt_0_valzr1t4f(((NI64)-1), 64);
    result_76 = X60Qx_853;}
  goto X60Qsc_441;
  X60Qsc_152: ;
  if (3 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_854 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_1 = (*X60Qx_854);
    NI64 X60Qx_855 = asInt_0_valzr1t4f((&X60QconstRefTemp_1));
    Value_0_valzr1t4f* X60Qx_856 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_2 = (*X60Qx_856);
    NI64 X60Qx_857 = asInt_0_valzr1t4f((&X60QconstRefTemp_2));
    Value_0_valzr1t4f* X60Qx_858 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_3 = (*X60Qx_858);
    NI64 X60Qx_859 = asInt_0_valzr1t4f((&X60QconstRefTemp_3));
    NI32 X60Qx_860 = hostSocket_0_hos9jnsbq1(((NI32)X60Qx_855), ((NI32)X60Qx_857), ((NI32)X60Qx_859));
    Value_0_valzr1t4f X60Qx_861 = vInt_0_valzr1t4f(((NI64)X60Qx_860), 32);
    result_76 = X60Qx_861;
    publishSockErrno_0_runot4689();}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_862 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_862;}
  goto X60Qsc_441;
  X60Qsc_153: ;
  if (2 <= args_4.len_0){
    string_0_sysvq0asl kind_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    Value_0_valzr1t4f* X60Qx_863 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_4 = (*X60Qx_863);
    string_0_sysvq0asl img_0 = sockAddrImage_0_runot4689((&X60QconstRefTemp_4), (&kind_1));
    NB8 X60Qx_864 = eqQ_20_sysvq0asl(kind_1, (string_0_sysvq0asl){
      .bytes_0 = 3569154u, .more_0 = NIM_NIL}
    );
    if (X60Qx_864){
      failSockV6_0_runot4689(sink_13, name_6);
      Value_0_valzr1t4f X60Qx_865 = vInt_0_valzr1t4f(((NI64)-1), 32);
      result_76 = X60Qx_865;
      nimStrDestroy(img_0);
      nimStrDestroy(kind_1);
      return result_76;}
    NI32 X60Qx_866 = len_4_sysvq0asl(kind_1);
    if (X60Qx_866 == 0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_867 = vInt_0_valzr1t4f(((NI64)-1), 32);
      result_76 = X60Qx_867;}
    else {
      Value_0_valzr1t4f* X60Qx_868 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_5 = (*X60Qx_868);
      NI64 X60Qx_869 = asInt_0_valzr1t4f((&X60QconstRefTemp_5));
      NI32 h_0 = ((NI32)X60Qx_869);
      NI32 X60Qx_24;
      NB8 X60Qx_870 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
        .bytes_0 = 1852400382u, .more_0 = (&strlit_0_I18337270522941735704_iop7yt73v)}
      );
      if (X60Qx_870){
        NI32 X60Qx_871 = hostBind_0_hos9jnsbq1(h_0, img_0);
        X60Qx_24 = X60Qx_871;}
      else {
        NI32 X60Qx_872 = hostConnect_0_hos9jnsbq1(h_0, img_0);
        X60Qx_24 = X60Qx_872;}
      NI32 rc_1 = X60Qx_24;
      publishSockErrno_0_runot4689();
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_873 = vInt_0_valzr1t4f(((NI64)rc_1), 32);
      result_76 = X60Qx_873;}
    nimStrDestroy(img_0);
    nimStrDestroy(kind_1);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_874 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_874;}
  goto X60Qsc_441;
  X60Qsc_154: ;
  if (2 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_875 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_6 = (*X60Qx_875);
    NI64 X60Qx_876 = asInt_0_valzr1t4f((&X60QconstRefTemp_6));
    Value_0_valzr1t4f* X60Qx_877 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_7 = (*X60Qx_877);
    NI64 X60Qx_878 = asInt_0_valzr1t4f((&X60QconstRefTemp_7));
    NI32 X60Qx_879 = hostListen_0_hos9jnsbq1(((NI32)X60Qx_876), ((NI32)X60Qx_878));
    Value_0_valzr1t4f X60Qx_880 = vInt_0_valzr1t4f(((NI64)X60Qx_879), 32);
    result_76 = X60Qx_880;
    publishSockErrno_0_runot4689();}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_881 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_881;}
  goto X60Qsc_441;
  X60Qsc_155: ;
  if (1 <= args_4.len_0){
    string_0_sysvq0asl peer_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    Value_0_valzr1t4f* X60Qx_882 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_8 = (*X60Qx_882);
    NI64 X60Qx_883 = asInt_0_valzr1t4f((&X60QconstRefTemp_8));
    NI32 h_1 = hostAccept_0_hos9jnsbq1(((NI32)X60Qx_883), (&peer_0));
    publishSockErrno_0_runot4689();
    NB8 X60Qx_884;
    NB8 X60Qx_885;
    if (0 <= h_1){
      X60Qx_885 = (3 <= args_4.len_0);}
    else {
      X60Qx_885 = NIM_FALSE;}
    if (X60Qx_885){
      NI32 X60Qx_886 = len_4_sysvq0asl(peer_0);
      X60Qx_884 = (0 < X60Qx_886);}
    else {
      X60Qx_884 = NIM_FALSE;}
    if (X60Qx_884){
      Value_0_valzr1t4f* X60Qx_887 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_9 = (*X60Qx_887);
      writeSockAddrBack_0_runot4689((&X60QconstRefTemp_9), peer_0);
      Value_0_valzr1t4f* X60Qx_888 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
      Value_0_valzr1t4f X60QconstRefTemp_10 = (*X60Qx_888);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* lc_1 = intSlotCell_0_runot4689((&X60QconstRefTemp_10));
      if ((!(lc_1 == NIM_NIL))){
        Value_0_valzr1t4f* X60Qlhs_133 = (&(*lc_1).d_00.v_0);
        NI32 X60Qx_889 = len_4_sysvq0asl(peer_0);
        Value_0_valzr1t4f X60Qlhs_134 = vInt_0_valzr1t4f(((NI64)X60Qx_889), 32);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_133)));
        (*X60Qlhs_133) = X60Qlhs_134;}
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(lc_1);}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_890 = vInt_0_valzr1t4f(((NI64)h_1), 32);
    result_76 = X60Qx_890;
    nimStrDestroy(peer_0);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_891 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_891;}
  goto X60Qsc_441;
  X60Qsc_156: ;
  if (2 <= args_4.len_0){
    string_0_sysvq0asl sa_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    Value_0_valzr1t4f* X60Qx_892 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_11 = (*X60Qx_892);
    NI64 X60Qx_893 = asInt_0_valzr1t4f((&X60QconstRefTemp_11));
    NI32 h_2 = ((NI32)X60Qx_893);
    NI32 X60Qx_25;
    NB8 X60Qx_894 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
      .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I15485922392778096779_runot4689)}
    );
    if (X60Qx_894){
      NI32 X60Qx_895 = hostGetsockname_0_hos9jnsbq1(h_2, (&sa_1));
      X60Qx_25 = X60Qx_895;}
    else {
      NI32 X60Qx_896 = hostGetpeername_0_hos9jnsbq1(h_2, (&sa_1));
      X60Qx_25 = X60Qx_896;}
    NI32 rc_2 = X60Qx_25;
    publishSockErrno_0_runot4689();
    NB8 X60Qx_897;
    if (rc_2 == 0){
      NI32 X60Qx_898 = len_4_sysvq0asl(sa_1);
      X60Qx_897 = (0 < X60Qx_898);}
    else {
      X60Qx_897 = NIM_FALSE;}
    if (X60Qx_897){
      Value_0_valzr1t4f* X60Qx_899 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_12 = (*X60Qx_899);
      writeSockAddrBack_0_runot4689((&X60QconstRefTemp_12), sa_1);
      if (3 <= args_4.len_0){
        Value_0_valzr1t4f* X60Qx_900 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
        Value_0_valzr1t4f X60QconstRefTemp_13 = (*X60Qx_900);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* lc_2 = intSlotCell_0_runot4689((&X60QconstRefTemp_13));
        if ((!(lc_2 == NIM_NIL))){
          Value_0_valzr1t4f* X60Qlhs_135 = (&(*lc_2).d_00.v_0);
          NI32 X60Qx_901 = len_4_sysvq0asl(sa_1);
          Value_0_valzr1t4f X60Qlhs_136 = vInt_0_valzr1t4f(((NI64)X60Qx_901), 32);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_135)));
          (*X60Qlhs_135) = X60Qlhs_136;}
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(lc_2);}}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_902 = vInt_0_valzr1t4f(((NI64)rc_2), 32);
    result_76 = X60Qx_902;
    nimStrDestroy(sa_1);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_903 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_903;}
  goto X60Qsc_441;
  X60Qsc_157: ;
  if (5 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_904 = getQ_7_Ine8yq71_intzsnzax(args_4, 4);
    Value_0_valzr1t4f X60QconstRefTemp_14 = (*X60Qx_904);
    NI64 X60Qx_905 = asInt_0_valzr1t4f((&X60QconstRefTemp_14));
    NI32 n_7 = ((NI32)X60Qx_905);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_906 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
    Value_0_valzr1t4f X60QconstRefTemp_15 = (*X60Qx_906);
    string_0_sysvq0asl X60Qtmp_137 = sockOptBytes_0_runot4689((&X60QconstRefTemp_15), n_7);
    Value_0_valzr1t4f* X60Qx_907 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_16 = (*X60Qx_907);
    NI64 X60Qx_908 = asInt_0_valzr1t4f((&X60QconstRefTemp_16));
    Value_0_valzr1t4f* X60Qx_909 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_17 = (*X60Qx_909);
    NI64 X60Qx_910 = asInt_0_valzr1t4f((&X60QconstRefTemp_17));
    Value_0_valzr1t4f* X60Qx_911 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_18 = (*X60Qx_911);
    NI64 X60Qx_912 = asInt_0_valzr1t4f((&X60QconstRefTemp_18));
    NI32 X60Qx_913 = hostSetsockopt_0_hos9jnsbq1(((NI32)X60Qx_908), ((NI32)X60Qx_910), ((NI32)X60Qx_912), X60Qtmp_137);
    Value_0_valzr1t4f X60Qx_914 = vInt_0_valzr1t4f(((NI64)X60Qx_913), 32);
    result_76 = X60Qx_914;
    publishSockErrno_0_runot4689();
    nimStrDestroy(X60Qtmp_137);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_915 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_915;}
  goto X60Qsc_441;
  X60Qsc_158: ;
  if (5 <= args_4.len_0){
    NI32 want_0 = 4;
    Value_0_valzr1t4f* X60Qx_916 = getQ_7_Ine8yq71_intzsnzax(args_4, 4);
    Value_0_valzr1t4f X60QconstRefTemp_19 = (*X60Qx_916);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* lc_3 = intSlotCell_0_runot4689((&X60QconstRefTemp_19));
    if ((!(lc_3 == NIM_NIL))){
      NI64 X60Qx_917 = asInt_0_valzr1t4f((&(*lc_3).d_00.v_0));
      want_0 = ((NI32)X60Qx_917);}
    NB8 X60Qx_918;
    if (want_0 <= 0){
      X60Qx_918 = NIM_TRUE;}
    else {
      X60Qx_918 = (128 < want_0);}
    if (X60Qx_918){
      want_0 = 4;}
    string_0_sysvq0asl val_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    Value_0_valzr1t4f* X60Qx_919 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_20 = (*X60Qx_919);
    NI64 X60Qx_920 = asInt_0_valzr1t4f((&X60QconstRefTemp_20));
    Value_0_valzr1t4f* X60Qx_921 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_21 = (*X60Qx_921);
    NI64 X60Qx_922 = asInt_0_valzr1t4f((&X60QconstRefTemp_21));
    Value_0_valzr1t4f* X60Qx_923 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_22 = (*X60Qx_923);
    NI64 X60Qx_924 = asInt_0_valzr1t4f((&X60QconstRefTemp_22));
    NI32 rc_3 = hostGetsockopt_0_hos9jnsbq1(((NI32)X60Qx_920), ((NI32)X60Qx_922), ((NI32)X60Qx_924), want_0, (&val_0));
    publishSockErrno_0_runot4689();
    NB8 X60Qx_925;
    if (rc_3 == 0){
      NI32 X60Qx_926 = len_4_sysvq0asl(val_0);
      X60Qx_925 = (0 < X60Qx_926);}
    else {
      X60Qx_925 = NIM_FALSE;}
    if (X60Qx_925){
      Value_0_valzr1t4f* X60Qx_927 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
      Value_0_valzr1t4f X60QconstRefTemp_23 = (*X60Qx_927);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* vc_0 = intSlotCell_0_runot4689((&X60QconstRefTemp_23));
      NB8 X60Qx_928;
      if ((!(vc_0 == NIM_NIL))){
        NI32 X60Qx_929 = len_4_sysvq0asl(val_0);
        X60Qx_928 = (X60Qx_929 <= 8);}
      else {
        X60Qx_928 = NIM_FALSE;}
      if (X60Qx_928){
        Value_0_valzr1t4f* X60Qlhs_138 = (&(*vc_0).d_00.v_0);
        NI32 X60Qx_930 = len_4_sysvq0asl(val_0);
        NI32 X60Qx_931 = leAt_0_runot4689(val_0, 0, X60Qx_930);
        Value_0_valzr1t4f X60Qlhs_139 = vInt_0_valzr1t4f(((NI64)X60Qx_931), 32);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_138)));
        (*X60Qlhs_138) = X60Qlhs_139;}
      else {
        Value_0_valzr1t4f* X60Qx_932 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
        Value_0_valzr1t4f X60QconstRefTemp_24 = (*X60Qx_932);
        ptrWriteBytes_0_runot4689((&X60QconstRefTemp_24), val_0);}
      if ((!(lc_3 == NIM_NIL))){
        Value_0_valzr1t4f* X60Qlhs_140 = (&(*lc_3).d_00.v_0);
        NI32 X60Qx_933 = len_4_sysvq0asl(val_0);
        Value_0_valzr1t4f X60Qlhs_141 = vInt_0_valzr1t4f(((NI64)X60Qx_933), 32);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_140)));
        (*X60Qlhs_140) = X60Qlhs_141;}
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(vc_0);}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_934 = vInt_0_valzr1t4f(((NI64)rc_3), 32);
    result_76 = X60Qx_934;
    nimStrDestroy(val_0);
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(lc_3);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_935 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_935;}
  goto X60Qsc_441;
  X60Qsc_159: ;
  if (4 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_936 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_25 = (*X60Qx_936);
    NI64 X60Qx_937 = asInt_0_valzr1t4f((&X60QconstRefTemp_25));
    NI32 n_8 = ((NI32)X60Qx_937);
    Value_0_valzr1t4f* X60Qx_938 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_26 = (*X60Qx_938);
    string_0_sysvq0asl data_1 = ptrReadBytes_0_runot4689((&X60QconstRefTemp_26), n_8);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_939 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_27 = (*X60Qx_939);
    NI64 X60Qx_940 = asInt_0_valzr1t4f((&X60QconstRefTemp_27));
    Value_0_valzr1t4f* X60Qx_941 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
    Value_0_valzr1t4f X60QconstRefTemp_28 = (*X60Qx_941);
    NI64 X60Qx_942 = asInt_0_valzr1t4f((&X60QconstRefTemp_28));
    NI32 X60Qx_943 = hostSend_0_hos9jnsbq1(((NI32)X60Qx_940), data_1, ((NI32)X60Qx_942));
    Value_0_valzr1t4f X60Qx_944 = vInt_0_valzr1t4f(((NI64)X60Qx_943), 64);
    result_76 = X60Qx_944;
    publishSockErrno_0_runot4689();
    nimStrDestroy(data_1);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_945 = vInt_0_valzr1t4f(((NI64)-1), 64);
    result_76 = X60Qx_945;}
  goto X60Qsc_441;
  X60Qsc_160: ;
  if (4 <= args_4.len_0){
    string_0_sysvq0asl data_2 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    Value_0_valzr1t4f* X60Qx_946 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_29 = (*X60Qx_946);
    NI64 X60Qx_947 = asInt_0_valzr1t4f((&X60QconstRefTemp_29));
    Value_0_valzr1t4f* X60Qx_948 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_30 = (*X60Qx_948);
    NI64 X60Qx_949 = asInt_0_valzr1t4f((&X60QconstRefTemp_30));
    Value_0_valzr1t4f* X60Qx_950 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
    Value_0_valzr1t4f X60QconstRefTemp_31 = (*X60Qx_950);
    NI64 X60Qx_951 = asInt_0_valzr1t4f((&X60QconstRefTemp_31));
    NI32 rc_4 = hostRecv_0_hos9jnsbq1(((NI32)X60Qx_947), ((NI32)X60Qx_949), ((NI32)X60Qx_951), (&data_2));
    publishSockErrno_0_runot4689();
    if (0 < rc_4){
      Value_0_valzr1t4f* X60Qx_952 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_32 = (*X60Qx_952);
      ptrWriteBytes_0_runot4689((&X60QconstRefTemp_32), data_2);}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_953 = vInt_0_valzr1t4f(((NI64)rc_4), 64);
    result_76 = X60Qx_953;
    nimStrDestroy(data_2);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_954 = vInt_0_valzr1t4f(((NI64)-1), 64);
    result_76 = X60Qx_954;}
  goto X60Qsc_441;
  X60Qsc_161: ;
  if (2 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_955 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_33 = (*X60Qx_955);
    NI64 X60Qx_956 = asInt_0_valzr1t4f((&X60QconstRefTemp_33));
    Value_0_valzr1t4f* X60Qx_957 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_34 = (*X60Qx_957);
    NI64 X60Qx_958 = asInt_0_valzr1t4f((&X60QconstRefTemp_34));
    NI32 X60Qx_959 = hostShutdown_0_hos9jnsbq1(((NI32)X60Qx_956), ((NI32)X60Qx_958));
    Value_0_valzr1t4f X60Qx_960 = vInt_0_valzr1t4f(((NI64)X60Qx_959), 32);
    result_76 = X60Qx_960;
    publishSockErrno_0_runot4689();}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_961 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_961;}
  goto X60Qsc_441;
  X60Qsc_162: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_962 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_35 = (*X60Qx_962);
    NI64 X60Qx_963 = asInt_0_valzr1t4f((&X60QconstRefTemp_35));
    NI32 h_3 = ((NI32)X60Qx_963);
    NB8 X60Qx_964 = isSockHandle_0_hos9jnsbq1(h_3);
    if (X60Qx_964){
      NB8 hasArg_0 = (3 <= args_4.len_0);
      NI32 X60Qx_26;
      if (hasArg_0){
        Value_0_valzr1t4f* X60Qx_965 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
        Value_0_valzr1t4f X60QconstRefTemp_36 = (*X60Qx_965);
        NI64 X60Qx_966 = asInt_0_valzr1t4f((&X60QconstRefTemp_36));
        X60Qx_26 = ((NI32)X60Qx_966);}
      else {
        X60Qx_26 = 0;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f* X60Qx_967 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_37 = (*X60Qx_967);
      NI64 X60Qx_968 = asInt_0_valzr1t4f((&X60QconstRefTemp_37));
      NI32 X60Qx_969 = hostSockFcntl_0_hos9jnsbq1(h_3, ((NI32)X60Qx_968), X60Qx_26, hasArg_0);
      Value_0_valzr1t4f X60Qx_970 = vInt_0_valzr1t4f(((NI64)X60Qx_969), 32);
      result_76 = X60Qx_970;
      publishSockErrno_0_runot4689();}
    else {
      setHostSockErrno_0_runot4689(9);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_971 = vInt_0_valzr1t4f(((NI64)-1), 32);
      result_76 = X60Qx_971;}}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_972 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_972;}
  goto X60Qsc_441;
  X60Qsc_163: ;
  if (3 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_973 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_38 = (*X60Qx_973);
    NI64 X60Qx_974 = asInt_0_valzr1t4f((&X60QconstRefTemp_38));
    NI32 nfds_0 = ((NI32)X60Qx_974);
    Value_0_valzr1t4f* X60Qx_975 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_39 = (*X60Qx_975);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* fdc_0 = fieldCellByBase_0_runot4689((&X60QconstRefTemp_39), (string_0_sysvq0asl){
      .bytes_0 = 6579714u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_976;
    if (nfds_0 == 1){
      X60Qx_976 = (!(fdc_0 == NIM_NIL));}
    else {
      X60Qx_976 = NIM_FALSE;}
    if (X60Qx_976){
      Value_0_valzr1t4f* X60Qx_977 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_40 = (*X60Qx_977);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* evc_0 = fieldCellByBase_0_runot4689((&X60QconstRefTemp_40), (string_0_sysvq0asl){
        .bytes_0 = 1702258174u, .more_0 = (&strlit_0_I15643014340064390533_runot4689)}
      );
      Value_0_valzr1t4f* X60Qx_978 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_41 = (*X60Qx_978);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* rvc_0 = fieldCellByBase_0_runot4689((&X60QconstRefTemp_41), (string_0_sysvq0asl){
        .bytes_0 = 1986360062u, .more_0 = (&strlit_0_I8105615898909808576_runot4689)}
      );
      NI64 X60Qx_979 = asInt_0_valzr1t4f((&(*fdc_0).d_00.v_0));
      seq_0_Ift2sne_aow7lb5cq1 hs_0 = atQ_0_Iy7v4si1_filqx2b6r1((X60Qt_0_IAarrayAiS32ZS1_filqx2b6r1){
        .a = {
          ((NI32)X60Qx_979)}}
      );
      NI32 X60Qx_27;
      if ((!(evc_0 == NIM_NIL))){
        NI64 X60Qx_980 = asInt_0_valzr1t4f((&(*evc_0).d_00.v_0));
        X60Qx_27 = ((NI32)X60Qx_980);}
      else {
        X60Qx_27 = 0;}
      seq_0_Ift2sne_aow7lb5cq1 evs_0 = atQ_0_Iy7v4si1_filqx2b6r1((X60Qt_0_IAarrayAiS32ZS1_filqx2b6r1){
        .a = {
          X60Qx_27}}
      );
      seq_0_Ift2sne_aow7lb5cq1 rvs_0 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
      Value_0_valzr1t4f* X60Qx_981 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
      Value_0_valzr1t4f X60QconstRefTemp_42 = (*X60Qx_981);
      NI64 X60Qx_982 = asInt_0_valzr1t4f((&X60QconstRefTemp_42));
      NI32 rc_5 = hostPoll_0_hos9jnsbq1(hs_0, evs_0, (&rvs_0), ((NI32)X60Qx_982));
      publishSockErrno_0_runot4689();
      NB8 X60Qx_983;
      if ((!(rvc_0 == NIM_NIL))){
        X60Qx_983 = (0 < rvs_0.len_0);}
      else {
        X60Qx_983 = NIM_FALSE;}
      if (X60Qx_983){
        Value_0_valzr1t4f* X60Qlhs_142 = (&(*rvc_0).d_00.v_0);
        NI32* X60Qx_984 = getQ_7_Ir8kccm_aow7lb5cq1(rvs_0, 0);
        Value_0_valzr1t4f X60Qlhs_143 = vInt_0_valzr1t4f(((NI64)(*X60Qx_984)), 16);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_142)));
        (*X60Qlhs_142) = X60Qlhs_143;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_985 = vInt_0_valzr1t4f(((NI64)rc_5), 32);
      result_76 = X60Qx_985;
      eQdestroy_1_Iv9ij5i1_aow7lb5cq1(rvs_0);
      eQdestroy_1_Iv9ij5i1_aow7lb5cq1(evs_0);
      eQdestroy_1_Iv9ij5i1_aow7lb5cq1(hs_0);
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(rvc_0);
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(evc_0);}
    else {
      string_0_sysvq0asl X60Qdesugar_19 = dollarQ_2_sysvq0asl(nfds_0);
      NI32 X60Qx_986 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1819242750u, .more_0 = (&strlit_0_I8094440439369104877_runot4689)}
      );
      NI32 X60Qx_987 = len_4_sysvq0asl(X60Qdesugar_19);
      NI32 X60Qx_988 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 10497u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_20 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_986 + X60Qx_987)) + X60Qx_988)));
      add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
        .bytes_0 = 1819242750u, .more_0 = (&strlit_0_I8094440439369104877_runot4689)}
      );
      add_2_sysvq0asl((&X60Qdesugar_20), X60Qdesugar_19);
      add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
        .bytes_0 = 10497u, .more_0 = NIM_NIL}
      );
      failUnported_0_runot4689(sink_13, X60Qdesugar_20, (string_0_sysvq0asl){
        .bytes_0 = 1952542462u, .more_0 = (&strlit_0_I3550780962399020617_runot4689)}
      );
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_989 = vInt_0_valzr1t4f(((NI64)-1), 32);
      result_76 = X60Qx_989;
      nimStrDestroy(X60Qdesugar_20);
      nimStrDestroy(X60Qdesugar_19);}
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(fdc_0);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_990 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_990;}
  goto X60Qsc_441;
  X60Qsc_164: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_144 = sockErrnoCell_0_runot4689();
  Value_0_valzr1t4f X60Qx_991 = vPtrLoc_0_valzr1t4f(X60Qtmp_144);
  result_76 = X60Qx_991;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qtmp_144);
  goto X60Qsc_441;
  X60Qsc_165: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f* X60Qx_992 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_43 = (*X60Qx_992);
  NI64 X60Qx_993 = asInt_0_valzr1t4f((&X60QconstRefTemp_43));
  NI32 X60Qx_994 = hostHtons_0_hos9jnsbq1(((NI32)X60Qx_993));
  Value_0_valzr1t4f X60Qx_995 = vInt_0_valzr1t4f(((NI64)X60Qx_994), 16);
  result_76 = X60Qx_995;
  goto X60Qsc_441;
  X60Qsc_166: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f* X60Qx_996 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_44 = (*X60Qx_996);
  NI64 X60Qx_997 = asInt_0_valzr1t4f((&X60QconstRefTemp_44));
  NI32 X60Qx_998 = hostHtonl_0_hos9jnsbq1(((NI32)X60Qx_997));
  Value_0_valzr1t4f X60Qx_999 = vInt_0_valzr1t4f(((NI64)X60Qx_998), 32);
  result_76 = X60Qx_999;
  goto X60Qsc_441;
  X60Qsc_167: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f* X60Qx_1000 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_45 = (*X60Qx_1000);
  NI64 X60Qx_1001 = asInt_0_valzr1t4f((&X60QconstRefTemp_45));
  NI32 X60Qx_1002 = hostNtohs_0_hos9jnsbq1(((NI32)X60Qx_1001));
  Value_0_valzr1t4f X60Qx_1003 = vInt_0_valzr1t4f(((NI64)X60Qx_1002), 16);
  result_76 = X60Qx_1003;
  goto X60Qsc_441;
  X60Qsc_168: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f* X60Qx_1004 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_46 = (*X60Qx_1004);
  NI64 X60Qx_1005 = asInt_0_valzr1t4f((&X60QconstRefTemp_46));
  NI32 X60Qx_1006 = hostNtohl_0_hos9jnsbq1(((NI32)X60Qx_1005));
  Value_0_valzr1t4f X60Qx_1007 = vInt_0_valzr1t4f(((NI64)X60Qx_1006), 32);
  result_76 = X60Qx_1007;
  goto X60Qsc_441;
  X60Qsc_169: ;
  if (2 <= args_4.len_0){
    NI32 sec_0 = 0;
    NI32 nsec_0 = 0;
    Value_0_valzr1t4f* X60Qx_1008 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_47 = (*X60Qx_1008);
    NI64 X60Qx_1009 = asInt_0_valzr1t4f((&X60QconstRefTemp_47));
    hostClockGettime_0_hos1fpv3m1(((NI32)X60Qx_1009), (&sec_0), (&nsec_0));
    Value_0_valzr1t4f* X60Qx_1010 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_48 = (*X60Qx_1010);
    writeStatField_0_runot4689((&X60QconstRefTemp_48), (string_0_sysvq0asl){
      .bytes_0 = 1601598718u, .more_0 = (&strlit_0_I1549329809582954555_runot4689)}
    , sec_0);
    Value_0_valzr1t4f* X60Qx_1011 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_49 = (*X60Qx_1011);
    writeStatField_0_runot4689((&X60QconstRefTemp_49), (string_0_sysvq0asl){
      .bytes_0 = 1601598718u, .more_0 = (&strlit_0_I7192365939506907704_runot4689)}
    , nsec_0);}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1012 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_76 = X60Qx_1012;
  goto X60Qsc_441;
  X60Qsc_170: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  NI32 X60Qx_1013 = hostGetPid_0_hos1fpv3m1();
  Value_0_valzr1t4f X60Qx_1014 = vInt_0_valzr1t4f(((NI64)X60Qx_1013), 32);
  result_76 = X60Qx_1014;
  goto X60Qsc_441;
  X60Qsc_171: ;
  NI32 i_42 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1015 = len_3_I83dzei_arecyyj7v(gEnvironmentCells_0_runot4689);
      if (i_42 < X60Qx_1015){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1016 = getQ_7_Ii14ync1_arecyyj7v(gEnvironmentCells_0_runot4689, i_42);
        Value_0_valzr1t4f* X60Qlhs_145 = (&(*(*X60Qx_1016)).d_00.v_0);
        Value_0_valzr1t4f X60Qlhs_146 = environmentSeqValue_0_runot4689(sink_13);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_145)));
        (*X60Qlhs_145) = X60Qlhs_146;
        inc_1_I6wjjge_aow2h993l1((&i_42));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1017 = vNil_0_valzr1t4f();
  result_76 = X60Qx_1017;
  goto X60Qsc_441;
  X60Qsc_172: ;
  if (1 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1018 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_50 = (*X60Qx_1018);
    string_0_sysvq0asl X60Qtmp_147 = ptrToString_0_runot4689((&X60QconstRefTemp_50));
    NI32 X60Qx_1019 = hostSystem_0_hos1fpv3m1(X60Qtmp_147);
    Value_0_valzr1t4f X60Qx_1020 = vInt_0_valzr1t4f(((NI64)X60Qx_1019), 64);
    result_76 = X60Qx_1020;
    publishErrno_0_runot4689();
    nimStrDestroy(X60Qtmp_147);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1021 = vInt_0_valzr1t4f(((NI64)-1), 64);
    result_76 = X60Qx_1021;}
  goto X60Qsc_441;
  X60Qsc_173: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  string_0_sysvq0asl X60Qtmp_148 = hostGetCwd_0_hos1fpv3m1();
  Value_0_valzr1t4f X60Qx_1022 = vStr_0_valzr1t4f(X60Qtmp_148);
  result_76 = X60Qx_1022;
  publishErrno_0_runot4689();
  nimStrDestroy(X60Qtmp_148);
  goto X60Qsc_441;
  X60Qsc_174: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1023 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_51 = (*X60Qx_1023);
    string_0_sysvq0asl X60Qtmp_149 = ptrToString_0_runot4689((&X60QconstRefTemp_51));
    NI32 X60Qx_1024 = hostChdir_0_hos1fpv3m1(X60Qtmp_149);
    publishErrno_0_runot4689();
    nimStrDestroy(X60Qtmp_149);}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1025 = vNil_0_valzr1t4f();
  result_76 = X60Qx_1025;
  goto X60Qsc_441;
  X60Qsc_175: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1026 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_52 = (*X60Qx_1026);
    Value_0_valzr1t4f s0_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_52));
    NB8 X60Qx_1027;
    if (s0_0.kind_0 == 13){
      X60Qx_1027 = (!(s0_0.loc_0 == NIM_NIL));}
    else {
      X60Qx_1027 = NIM_FALSE;}
    if (X60Qx_1027){
      Value_0_valzr1t4f X60Qlhs_150 = s0_0;
      Value_0_valzr1t4f X60Qx_1028 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*s0_0.loc_0).d_00.v_0));
      s0_0 = X60Qx_1028;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_150));}
    string_0_sysvq0asl X60Qx_28;
    nimStrWasMoved((&X60Qx_28));
    if (s0_0.kind_0 == 6){
      nimStrDestroy(X60Qx_28);
      X60Qx_28 = s0_0.sval_0;
      nimStrWasMoved((&s0_0.sval_0));}
    else {
      nimStrDestroy(X60Qx_28);
      Value_0_valzr1t4f* X60Qx_1029 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_53 = (*X60Qx_1029);
      string_0_sysvq0asl X60Qx_1030 = ptrToString_0_runot4689((&X60QconstRefTemp_53));
      X60Qx_28 = X60Qx_1030;}
    string_0_sysvq0asl inPath_0 = X60Qx_28;
    nimStrWasMoved((&X60Qx_28));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    string_0_sysvq0asl X60Qtmp_151 = hostExpandFilename_0_hos5i19e11(inPath_0);
    Value_0_valzr1t4f X60Qx_1031 = vStr_0_valzr1t4f(X60Qtmp_151);
    result_76 = X60Qx_1031;
    nimStrDestroy(X60Qtmp_151);
    nimStrDestroy(inPath_0);
    nimStrDestroy(X60Qx_28);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s0_0));}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1032 = vStr_0_valzr1t4f((string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    result_76 = X60Qx_1032;}
  goto X60Qsc_441;
  X60Qsc_176: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1033 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_54 = (*X60Qx_1033);
    string_0_sysvq0asl X60Qtmp_152 = ptrToString_0_runot4689((&X60QconstRefTemp_54));
    NI32 h_4 = hostOpenDir_0_hos1fpv3m1(X60Qtmp_152);
    publishErrno_0_runot4689();
    Value_0_valzr1t4f X60Qx_29;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_29));
    if (h_4 <= 0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_29));
      Value_0_valzr1t4f X60Qx_1034 = vNil_0_valzr1t4f();
      X60Qx_29 = X60Qx_1034;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_29));
      Value_0_valzr1t4f X60Qx_1035 = vInt_0_valzr1t4f(((NI64)h_4), 64);
      X60Qx_29 = X60Qx_1035;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    result_76 = X60Qx_29;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_29));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_29));
    nimStrDestroy(X60Qtmp_152);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1036 = vNil_0_valzr1t4f();
    result_76 = X60Qx_1036;}
  goto X60Qsc_441;
  X60Qsc_177: ;
  NB8 X60Qx_1037;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1038 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1037 = (!((*X60Qx_1038).kind_0 == 0));}
  else {
    X60Qx_1037 = NIM_FALSE;}
  if (X60Qx_1037){
    Value_0_valzr1t4f* X60Qx_1039 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_55 = (*X60Qx_1039);
    NI64 X60Qx_1040 = asInt_0_valzr1t4f((&X60QconstRefTemp_55));
    NI32 X60Qx_1041 = hostCloseDir_0_hos1fpv3m1(((NI32)X60Qx_1040));
    publishErrno_0_runot4689();}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1042 = vInt_0_valzr1t4f(((NI64)0), 64);
  result_76 = X60Qx_1042;
  goto X60Qsc_441;
  X60Qsc_178: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1043 = vBool_0_valzr1t4f(NIM_FALSE);
  result_76 = X60Qx_1043;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1044 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_56 = (*X60Qx_1044);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* hc_0 = fieldCellByBase_0_runot4689((&X60QconstRefTemp_56), (string_0_sysvq0asl){
      .bytes_0 = 1835626750u, .more_0 = (&strlit_0_I16579930605568015458_runot4689)}
    );
    NB8 X60Qx_1045;
    if ((!(hc_0 == NIM_NIL))){
      X60Qx_1045 = (!((*hc_0).d_00.v_0.kind_0 == 0));}
    else {
      X60Qx_1045 = NIM_FALSE;}
    if (X60Qx_1045){
      string_0_sysvq0asl nm_3 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NI32 kd_0 = 0;
      NI64 X60Qx_1046 = asInt_0_valzr1t4f((&(*hc_0).d_00.v_0));
      NB8 X60Qx_1047 = hostNextDir_0_hos1fpv3m1(((NI32)X60Qx_1046), (&nm_3), (&kd_0));
      if (X60Qx_1047){
        Value_0_valzr1t4f* X60Qx_1048 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_57 = (*X60Qx_1048);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* kc_0 = fieldCellByBase_0_runot4689((&X60QconstRefTemp_57), (string_0_sysvq0asl){
          .bytes_0 = 1852402686u, .more_0 = (&strlit_0_I18311672068392283896_runot4689)}
        );
        if ((!(kc_0 == NIM_NIL))){
          NU32 X60Qx_30;
          if ((*kc_0).d_00.v_0.kind_0 == 7){
            X60Qx_30 = (*kc_0).d_00.v_0.ekind_0;}
          else {
            X60Qx_30 = ((NU32)0u);}
          NU32 ek_0 = X60Qx_30;
          Value_0_valzr1t4f* X60Qlhs_153 = (&(*kc_0).d_00.v_0);
          Value_0_valzr1t4f X60Qlhs_154 = vEnum_0_valzr1t4f(kd_0, ek_0);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_153)));
          (*X60Qlhs_153) = X60Qlhs_154;}
        Value_0_valzr1t4f* X60Qx_1049 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_58 = (*X60Qx_1049);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* pc_0 = fieldCellByBase_0_runot4689((&X60QconstRefTemp_58), (string_0_sysvq0asl){
          .bytes_0 = 1952542974u, .more_0 = (&strlit_0_I2500417439306294520_runot4689)}
        );
        if ((!(pc_0 == NIM_NIL))){
          Value_0_valzr1t4f* X60Qx_1050 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
          Value_0_valzr1t4f X60QconstRefTemp_59 = (*X60Qx_1050);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dc_0 = fieldCellByBase_0_runot4689((&X60QconstRefTemp_59), (string_0_sysvq0asl){
            .bytes_0 = 1919509507u, .more_0 = NIM_NIL}
          );
          Value_0_valzr1t4f X60Qx_31;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_31));
          if ((!(dc_0 == NIM_NIL))){
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_31));
            Value_0_valzr1t4f X60Qx_1051 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dc_0).d_00.v_0));
            X60Qx_31 = X60Qx_1051;}
          else {
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_31));
            Value_0_valzr1t4f X60Qx_1052 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*pc_0).d_00.v_0));
            X60Qx_31 = X60Qx_1052;}
          Value_0_valzr1t4f* X60Qlhs_155 = (&(*pc_0).d_00.v_0);
          Value_0_valzr1t4f X60Qlhs_156 = likeStringValue_0_runot4689((&X60Qx_31), nm_3);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_155)));
          (*X60Qlhs_155) = X60Qlhs_156;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_31));
          eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(dc_0);}
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1053 = vBool_0_valzr1t4f(NIM_TRUE);
        result_76 = X60Qx_1053;
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(pc_0);
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(kc_0);}
      nimStrDestroy(nm_3);}
    publishErrno_0_runot4689();
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(hc_0);}
  goto X60Qsc_441;
  X60Qsc_179: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1054 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_60 = (*X60Qx_1054);
    string_0_sysvq0asl path_2 = ptrToString_0_runot4689((&X60QconstRefTemp_60));
    NB8 found_6 = NIM_FALSE;
    NB8 X60Qx_1055 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
      .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I10217866098611558294_iop7yt73v)}
    );
    NI32 mode_0 = statModeForPath_0_runot4689(path_2, X60Qx_1055, (&found_6));
    if (found_6){
      Value_0_valzr1t4f* X60Qx_1056 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_61 = (*X60Qx_1056);
      writeStatField_0_runot4689((&X60QconstRefTemp_61), (string_0_sysvq0asl){
        .bytes_0 = 1601467390u, .more_0 = (&strlit_0_I6805333918920290403_runot4689)}
      , mode_0);
      if (((NI32)(mode_0 & 61440)) == 32768){
        Value_0_valzr1t4f* X60Qx_1057 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_62 = (*X60Qx_1057);
        NI32 X60Qx_1058 = hostFileSize_0_hos1fpv3m1(path_2);
        writeStatField_0_runot4689((&X60QconstRefTemp_62), (string_0_sysvq0asl){
          .bytes_0 = 1601467390u, .more_0 = (&strlit_0_I11133855009892133944_runot4689)}
        , X60Qx_1058);}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1059 = vInt_0_valzr1t4f(((NI64)0), 64);
      result_76 = X60Qx_1059;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1060 = vInt_0_valzr1t4f(((NI64)-1), 64);
      result_76 = X60Qx_1060;}
    nimStrDestroy(path_2);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1061 = vInt_0_valzr1t4f(((NI64)-1), 64);
    result_76 = X60Qx_1061;}
  goto X60Qsc_441;
  X60Qsc_180: ;
  if (6 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1062 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_63 = (*X60Qx_1062);
    NI64 X60Qx_1063 = asInt_0_valzr1t4f((&X60QconstRefTemp_63));
    NI32 n_9 = ((NI32)X60Qx_1063);
    Value_0_valzr1t4f* X60Qx_1064 = getQ_7_Ine8yq71_intzsnzax(args_4, 4);
    Value_0_valzr1t4f X60QconstRefTemp_64 = (*X60Qx_1064);
    NI64 X60Qx_1065 = asInt_0_valzr1t4f((&X60QconstRefTemp_64));
    NI32 fd_0 = ((NI32)X60Qx_1065);
    Value_0_valzr1t4f* X60Qx_1066 = getQ_7_Ine8yq71_intzsnzax(args_4, 5);
    Value_0_valzr1t4f X60QconstRefTemp_65 = (*X60Qx_1066);
    NI64 X60Qx_1067 = asInt_0_valzr1t4f((&X60QconstRefTemp_65));
    NI32 off_4 = ((NI32)X60Qx_1067);
    string_0_sysvq0asl bytes_0 = hostPread_0_hos5i19e11(sink_13, fd_0, off_4, n_9);
    Value_0_valzr1t4f reg_0 = flAllocRegion_0_flaksyopx1(n_9, NIM_FALSE);
    NI32 bi_0 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1068 = len_4_sysvq0asl(bytes_0);
        if (bi_0 < X60Qx_1068){
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_157 = region_0_valzr1t4f((&reg_0));
          NC8 X60Qx_1069 = getQ_9_sysvq0asl(bytes_0, bi_0);
          setByteAt_0_flaksyopx1(X60Qtmp_157, bi_0, ((NU8)X60Qx_1069));
          inc_1_I6wjjge_aow2h993l1((&bi_0));
          eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_157);}
        else {
          break;}}}
    whileStmtLabel_1: ;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    result_76 = reg_0;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&reg_0));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&reg_0));
    nimStrDestroy(bytes_0);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1070 = vNil_0_valzr1t4f();
    result_76 = X60Qx_1070;}
  goto X60Qsc_441;
  X60Qsc_181: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1071 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_76 = X60Qx_1071;
  goto X60Qsc_441;
  X60Qsc_182: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1072 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_66 = (*X60Qx_1072);
    NI64 X60Qx_1073 = asInt_0_valzr1t4f((&X60QconstRefTemp_66));
    NI32 fd_1 = ((NI32)X60Qx_1073);
    FILE* f_5 = hostFileOfFd_0_hos5i19e11(sink_13, fd_1);
    if ((!(f_5 == NIM_NIL))){
      Value_0_valzr1t4f* X60Qx_1074 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_67 = (*X60Qx_1074);
      writeStatField_0_runot4689((&X60QconstRefTemp_67), (string_0_sysvq0asl){
        .bytes_0 = 1601467390u, .more_0 = (&strlit_0_I6805333918920290403_runot4689)}
      , 32768);
      Value_0_valzr1t4f* X60Qx_1075 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_68 = (*X60Qx_1075);
      NI32 X60Qx_1076 = hostFdSize_0_hos1fpv3m1(f_5);
      writeStatField_0_runot4689((&X60QconstRefTemp_68), (string_0_sysvq0asl){
        .bytes_0 = 1601467390u, .more_0 = (&strlit_0_I11133855009892133944_runot4689)}
      , X60Qx_1076);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1077 = vInt_0_valzr1t4f(((NI64)0), 32);
      result_76 = X60Qx_1077;}
    else {
      NI32 X60Qx_1078 = hostFdLen_0_hos5i19e11(sink_13, fd_1);
      if (0 <= X60Qx_1078){
        Value_0_valzr1t4f* X60Qx_1079 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_69 = (*X60Qx_1079);
        writeStatField_0_runot4689((&X60QconstRefTemp_69), (string_0_sysvq0asl){
          .bytes_0 = 1601467390u, .more_0 = (&strlit_0_I6805333918920290403_runot4689)}
        , 32768);
        Value_0_valzr1t4f* X60Qx_1080 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_70 = (*X60Qx_1080);
        NI32 X60Qx_1081 = hostFdLen_0_hos5i19e11(sink_13, fd_1);
        writeStatField_0_runot4689((&X60QconstRefTemp_70), (string_0_sysvq0asl){
          .bytes_0 = 1601467390u, .more_0 = (&strlit_0_I11133855009892133944_runot4689)}
        , X60Qx_1081);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1082 = vInt_0_valzr1t4f(((NI64)0), 32);
        result_76 = X60Qx_1082;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1083 = vInt_0_valzr1t4f(((NI64)-1), 32);
        result_76 = X60Qx_1083;}}}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1084 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_1084;}
  goto X60Qsc_441;
  X60Qsc_183: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f* X60Qx_1085 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_71 = (*X60Qx_1085);
  NI64 X60Qx_1086 = asInt_0_valzr1t4f((&X60QconstRefTemp_71));
  Value_0_valzr1t4f X60Qx_1087 = vBool_0_valzr1t4f((((NI32)(((NI32)X60Qx_1086) & 61440)) == 32768));
  result_76 = X60Qx_1087;
  goto X60Qsc_441;
  X60Qsc_184: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f* X60Qx_1088 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_72 = (*X60Qx_1088);
  NI64 X60Qx_1089 = asInt_0_valzr1t4f((&X60QconstRefTemp_72));
  Value_0_valzr1t4f X60Qx_1090 = vBool_0_valzr1t4f((((NI32)(((NI32)X60Qx_1089) & 61440)) == 16384));
  result_76 = X60Qx_1090;
  goto X60Qsc_441;
  X60Qsc_185: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f* X60Qx_1091 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_73 = (*X60Qx_1091);
  NI64 X60Qx_1092 = asInt_0_valzr1t4f((&X60QconstRefTemp_73));
  Value_0_valzr1t4f X60Qx_1093 = vBool_0_valzr1t4f((((NI32)(((NI32)X60Qx_1092) & 61440)) == 40960));
  result_76 = X60Qx_1093;
  goto X60Qsc_441;
  X60Qsc_186: ;
  if (3 <= args_4.len_0){
    NB8 toErr_0 = NIM_FALSE;
    Value_0_valzr1t4f* X60Qx_1094 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    if ((*X60Qx_1094).kind_0 == 16){
      Value_0_valzr1t4f* X60Qx_1095 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      toErr_0 = (*X60Qx_1095).toErr_0;}
    Value_0_valzr1t4f* X60Qx_1096 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_74 = (*X60Qx_1096);
    NI64 X60Qx_1097 = asInt_0_valzr1t4f((&X60QconstRefTemp_74));
    NI32 count_0 = ((NI32)X60Qx_1097);
    string_0_sysvq0asl buf_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    Value_0_valzr1t4f* X60Qx_1098 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_75 = (*X60Qx_1098);
    Value_0_valzr1t4f v_36 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_75));
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_20 = ptrCell_0_runot4689((&v_36));
    if ((!(c_20 == NIM_NIL))){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_36));
      Value_0_valzr1t4f X60Qx_1099 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_20).d_00.v_0));
      v_36 = X60Qx_1099;}
    appendValueBytes_0_runot4689((&buf_1), (&v_36));
    NI32 X60Qx_1100 = len_4_sysvq0asl(buf_1);
    if (X60Qx_1100 < count_0){
      NI32 X60Qx_1101 = len_4_sysvq0asl(buf_1);
      NI32 pad_0 = ((NI32)(count_0 - X60Qx_1101));
      {
        while (0 < pad_0){
          add_1_sysvq0asl((&buf_1), (NC8)'\000');
          dec_1_I0nzoz91_aow7lb5cq1((&pad_0));}}
      whileStmtLabel_2: ;}
    else {
      NI32 X60Qx_1102 = len_4_sysvq0asl(buf_1);
      if (count_0 < X60Qx_1102){
        setLen_1_sysvq0asl((&buf_1), count_0);}}
    writeStr_0_natd5co251(sink_13, toErr_0, buf_1);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1103 = vInt_0_valzr1t4f(((NI64)count_0), 64);
    result_76 = X60Qx_1103;
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_20);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_36));
    nimStrDestroy(buf_1);}
  goto X60Qsc_441;
  X60Qsc_187: ;
  NB8 X60Qx_1104;
  NB8 X60Qx_1105;
  NI32 X60Qx_1106 = len_3_I4n9kvq_intzsnzax(args_4);
  if (X60Qx_1106 == 3){
    NB8 X60Qx_1107;
    Value_0_valzr1t4f* X60Qx_1108 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    if ((*X60Qx_1108).kind_0 == 1){
      X60Qx_1107 = NIM_TRUE;}
    else {
      Value_0_valzr1t4f* X60Qx_1109 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      X60Qx_1107 = ((*X60Qx_1109).kind_0 == 2);}
    X60Qx_1105 = X60Qx_1107;}
  else {
    X60Qx_1105 = NIM_FALSE;}
  if (X60Qx_1105){
    Value_0_valzr1t4f* X60Qx_1110 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    X60Qx_1104 = ((*X60Qx_1110).kind_0 == 13);}
  else {
    X60Qx_1104 = NIM_FALSE;}
  if (X60Qx_1104){
    Value_0_valzr1t4f* X60Qx_1111 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_76 = (*X60Qx_1111);
    NI32 fd_2 = fdOfValue_0_runot4689((&X60QconstRefTemp_76));
    Value_0_valzr1t4f* X60Qx_1112 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_77 = (*X60Qx_1112);
    NI64 X60Qx_1113 = asInt_0_valzr1t4f((&X60QconstRefTemp_77));
    NI32 n_10 = ((NI32)X60Qx_1113);
    Value_0_valzr1t4f* X60Qx_1114 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_78 = (*X60Qx_1114);
    string_0_sysvq0asl data_3 = ptrReadBytes_0_runot4689((&X60QconstRefTemp_78), n_10);
    NI32 X60Qx_1115 = len_4_sysvq0asl(data_3);
    NI32 wrote_0 = hostWrite_0_hos5i19e11(sink_13, fd_2, data_3, X60Qx_1115);
    NI64 X60Qx_32;
    if (wrote_0 < 0){
      X60Qx_32 = -1;}
    else {
      NI32 X60Qx_1116 = len_4_sysvq0asl(data_3);
      X60Qx_32 = X60Qx_1116;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1117 = vInt_0_valzr1t4f(((NI64)X60Qx_32), 64);
    result_76 = X60Qx_1117;
    nimStrDestroy(data_3);}
  else {
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1118 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      if ((*X60Qx_1118).kind_0 == 16){
        Value_0_valzr1t4f* X60Qx_1119 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        Value_0_valzr1t4f* X60Qx_1120 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_79 = (*X60Qx_1120);
        writeVal_0_natd5co251(sink_13, (*X60Qx_1119).toErr_0, (&X60QconstRefTemp_79));}
      else {
        Value_0_valzr1t4f* X60Qx_1121 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        Value_0_valzr1t4f X60QconstRefTemp_80 = (*X60Qx_1121);
        NI32 X60Qx_1122 = fdOfValue_0_runot4689((&X60QconstRefTemp_80));
        NB8 X60Qx_1123 = isHostFd_0_hos5i19e11(sink_13, X60Qx_1122);
        if (X60Qx_1123){
          Value_0_valzr1t4f* X60Qx_1124 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          Value_0_valzr1t4f X60QconstRefTemp_81 = (*X60Qx_1124);
          string_0_sysvq0asl s_30 = dollarQ_0_valzr1t4f((&X60QconstRefTemp_81));
          Value_0_valzr1t4f* X60Qx_1125 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
          Value_0_valzr1t4f X60QconstRefTemp_82 = (*X60Qx_1125);
          NI32 X60Qx_1126 = fdOfValue_0_runot4689((&X60QconstRefTemp_82));
          NI32 X60Qx_1127 = len_4_sysvq0asl(s_30);
          NI32 X60Qx_1128 = hostWrite_0_hos5i19e11(sink_13, X60Qx_1126, s_30, X60Qx_1127);
          nimStrDestroy(s_30);}
        else {
          Value_0_valzr1t4f* X60Qx_1129 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          Value_0_valzr1t4f X60QconstRefTemp_83 = (*X60Qx_1129);
          writeVal_0_natd5co251(sink_13, NIM_FALSE, (&X60QconstRefTemp_83));}}}}
  goto X60Qsc_441;
  X60Qsc_188: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1130 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    if ((*X60Qx_1130).kind_0 == 16){
      Value_0_valzr1t4f* X60Qx_1131 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f* X60Qx_1132 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_84 = (*X60Qx_1132);
      writeVal_0_natd5co251(sink_13, (*X60Qx_1131).toErr_0, (&X60QconstRefTemp_84));
      Value_0_valzr1t4f* X60Qx_1133 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      writeStr_0_natd5co251(sink_13, (*X60Qx_1133).toErr_0, (string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );}
    else {
      Value_0_valzr1t4f* X60Qx_1134 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_85 = (*X60Qx_1134);
      NI32 X60Qx_1135 = fdOfValue_0_runot4689((&X60QconstRefTemp_85));
      NB8 X60Qx_1136 = isHostFd_0_hos5i19e11(sink_13, X60Qx_1135);
      if (X60Qx_1136){
        Value_0_valzr1t4f* X60Qx_1137 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_86 = (*X60Qx_1137);
        string_0_sysvq0asl X60Qtmp_158 = dollarQ_0_valzr1t4f((&X60QconstRefTemp_86));
        string_0_sysvq0asl s_31 = ampQ_0_sysvq0asl(X60Qtmp_158, (string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );
        Value_0_valzr1t4f* X60Qx_1138 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        Value_0_valzr1t4f X60QconstRefTemp_87 = (*X60Qx_1138);
        NI32 X60Qx_1139 = fdOfValue_0_runot4689((&X60QconstRefTemp_87));
        NI32 X60Qx_1140 = len_4_sysvq0asl(s_31);
        NI32 X60Qx_1141 = hostWrite_0_hos5i19e11(sink_13, X60Qx_1139, s_31, X60Qx_1140);
        nimStrDestroy(s_31);
        nimStrDestroy(X60Qtmp_158);}
      else {
        Value_0_valzr1t4f* X60Qx_1142 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_88 = (*X60Qx_1142);
        writeVal_0_natd5co251(sink_13, NIM_FALSE, (&X60QconstRefTemp_88));
        writeStr_0_natd5co251(sink_13, NIM_FALSE, (string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );}}}
  goto X60Qsc_441;
  X60Qsc_189: ;
  NI32 code_0 = 0;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1143 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_89 = (*X60Qx_1143);
    NI64 X60Qx_1144 = asInt_0_valzr1t4f((&X60QconstRefTemp_89));
    code_0 = ((NI32)X60Qx_1144);}
  doQQuit_0_natd5co251(sink_13, code_0);
  goto X60Qsc_441;
  X60Qsc_190: ;
  NB8 ok_0 = NIM_FALSE;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1145 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_90 = (*X60Qx_1145);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_1 = ptrCell_0_runot4689((&X60QconstRefTemp_90));
    Value_0_valzr1t4f* X60Qx_1146 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_91 = (*X60Qx_1146);
    NI32 fd_3 = fdOfValue_0_runot4689((&X60QconstRefTemp_91));
    NB8 X60Qx_1147 = isHostFd_0_hos5i19e11(sink_13, fd_3);
    if (X60Qx_1147){
      string_0_sysvq0asl line_1 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NB8 got_0 = NIM_FALSE;
      {
        while (NIM_TRUE){
          string_0_sysvq0asl b_10 = hostRead_0_hos5i19e11(sink_13, fd_3, 1);
          NI32 X60Qx_1148 = len_4_sysvq0asl(b_10);
          if (X60Qx_1148 == 0){
            nimStrDestroy(b_10);
            goto whileStmtLabel_3;}
          got_0 = NIM_TRUE;
          NC8 X60Qx_1149 = getQ_9_sysvq0asl(b_10, 0);
          if (X60Qx_1149 == (NC8)'\012'){
            nimStrDestroy(b_10);
            goto whileStmtLabel_3;}
          NC8 X60Qx_1150 = getQ_9_sysvq0asl(b_10, 0);
          add_1_sysvq0asl((&line_1), X60Qx_1150);
          nimStrDestroy(b_10);}}
      whileStmtLabel_3: ;
      if ((!(cell_1 == NIM_NIL))){
        Value_0_valzr1t4f* X60Qlhs_159 = (&(*cell_1).d_00.v_0);
        Value_0_valzr1t4f X60Qlhs_160 = vStr_0_valzr1t4f(line_1);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_159)));
        (*X60Qlhs_159) = X60Qlhs_160;}
      ok_0 = got_0;
      nimStrDestroy(line_1);}
    else {
      X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 X60Qtmptup_4 = readLineFrom_0_natd5co251(sink_13);
      string_0_sysvq0asl line_2 = X60Qtmptup_4.fld_0;
      nimStrWasMoved((&X60Qtmptup_4.fld_0));
      NB8 hadData_0 = X60Qtmptup_4.fld_1;
      if ((!(cell_1 == NIM_NIL))){
        Value_0_valzr1t4f* X60Qlhs_161 = (&(*cell_1).d_00.v_0);
        Value_0_valzr1t4f X60Qlhs_162 = vStr_0_valzr1t4f(line_2);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_161)));
        (*X60Qlhs_161) = X60Qlhs_162;}
      ok_0 = hadData_0;
      nimStrDestroy(line_2);
      eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_runot4689(X60Qtmptup_4);}
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_1);}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1151 = vBool_0_valzr1t4f(ok_0);
  result_76 = X60Qx_1151;
  goto X60Qsc_441;
  X60Qsc_191: ;
  NB8 X60Qx_1152;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1153 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1152 = ((*X60Qx_1153).kind_0 == 6);}
  else {
    X60Qx_1152 = NIM_FALSE;}
  if (X60Qx_1152){
    Value_0_valzr1t4f* X60Qx_1154 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    string_0_sysvq0asl s_32 = nimStrDup((*X60Qx_1154).sval_0);
    NU64 h_5 = ((NU64)0u);
    NI32 i_43 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1155 = len_4_sysvq0asl(s_32);
        if (i_43 < X60Qx_1155){
          NC8 X60Qx_1156 = getQ_9_sysvq0asl(s_32, i_43);
          h_5 = ((NU64)(h_5 + ((NU64)((NU8)X60Qx_1156))));
          h_5 = ((NU64)(h_5 + ((NU64)(h_5 << ((NU64)10u)))));
          h_5 = ((NU64)(h_5 ^ ((NU64)(h_5 >> ((NU64)6u)))));
          inc_1_I6wjjge_aow2h993l1((&i_43));}
        else {
          break;}}}
    whileStmtLabel_4: ;
    h_5 = ((NU64)(h_5 + ((NU64)(h_5 << ((NU64)3u)))));
    h_5 = ((NU64)(h_5 ^ ((NU64)(h_5 >> ((NU64)11u)))));
    h_5 = ((NU64)(h_5 + ((NU64)(h_5 << ((NU64)15u)))));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1157 = vUInt_0_valzr1t4f(h_5, 64);
    result_76 = X60Qx_1157;
    nimStrDestroy(s_32);}
  goto X60Qsc_441;
  X60Qsc_192: ;
  NB8 X60Qx_131;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1158 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_92 = (*X60Qx_1158);
    Value_0_valzr1t4f X60Qtmp_163 = strArg_0_runot4689((&X60QconstRefTemp_92));
    X60Qx_131 = (X60Qtmp_163.kind_0 == 6);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_163));}
  else {
    X60Qx_131 = NIM_FALSE;}
  if (X60Qx_131){
    Value_0_valzr1t4f* X60Qx_1159 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_93 = (*X60Qx_1159);
    Value_0_valzr1t4f X60Qtmp_164 = strArg_0_runot4689((&X60QconstRefTemp_93));
    string_0_sysvq0asl s_33 = nimStrDup(X60Qtmp_164.sval_0);
    Value_0_valzr1t4f* X60Qx_1160 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_94 = (*X60Qx_1160);
    Value_0_valzr1t4f X60Qtmp_165 = strArg_0_runot4689((&X60QconstRefTemp_94));
    if (X60Qtmp_165.kind_0 == 6){
      Value_0_valzr1t4f* X60Qx_1161 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_95 = (*X60Qx_1161);
      Value_0_valzr1t4f X60Qtmp_166 = strArg_0_runot4689((&X60QconstRefTemp_95));
      string_0_sysvq0asl p_2 = nimStrDup(X60Qtmp_166.sval_0);
      NI32 X60Qx_1162 = len_4_sysvq0asl(p_2);
      NI32 X60Qx_1163 = len_4_sysvq0asl(s_33);
      NB8 ok_1 = (X60Qx_1162 <= X60Qx_1163);
      NI32 i_44 = 0;
      {
        while (NIM_TRUE){
          NB8 X60Qx_1164;
          if (ok_1){
            NI32 X60Qx_1165 = len_4_sysvq0asl(p_2);
            X60Qx_1164 = (i_44 < X60Qx_1165);}
          else {
            X60Qx_1164 = NIM_FALSE;}
          if (X60Qx_1164){
            NC8 X60Qx_1166 = getQ_9_sysvq0asl(s_33, i_44);
            NC8 X60Qx_1167 = getQ_9_sysvq0asl(p_2, i_44);
            if ((!(X60Qx_1166 == X60Qx_1167))){
              ok_1 = NIM_FALSE;}
            inc_1_I6wjjge_aow2h993l1((&i_44));}
          else {
            break;}}}
      whileStmtLabel_5: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1168 = vBool_0_valzr1t4f(ok_1);
      result_76 = X60Qx_1168;
      nimStrDestroy(p_2);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_166));}
    else {
      Value_0_valzr1t4f* X60Qx_1169 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      if ((*X60Qx_1169).kind_0 == 5){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        NB8 X60Qx_1170;
        NI32 X60Qx_1171 = len_4_sysvq0asl(s_33);
        if (0 < X60Qx_1171){
          NC8 X60Qx_1172 = getQ_9_sysvq0asl(s_33, 0);
          Value_0_valzr1t4f* X60Qx_1173 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          X60Qx_1170 = (X60Qx_1172 == (*X60Qx_1173).cval_0);}
        else {
          X60Qx_1170 = NIM_FALSE;}
        Value_0_valzr1t4f X60Qx_1174 = vBool_0_valzr1t4f(X60Qx_1170);
        result_76 = X60Qx_1174;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1175 = vBool_0_valzr1t4f(NIM_FALSE);
        result_76 = X60Qx_1175;}}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_165));
    nimStrDestroy(s_33);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_164));}
  goto X60Qsc_441;
  X60Qsc_193: ;
  NB8 X60Qx_132;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1176 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_96 = (*X60Qx_1176);
    Value_0_valzr1t4f X60Qtmp_167 = strArg_0_runot4689((&X60QconstRefTemp_96));
    X60Qx_132 = (X60Qtmp_167.kind_0 == 6);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_167));}
  else {
    X60Qx_132 = NIM_FALSE;}
  if (X60Qx_132){
    Value_0_valzr1t4f* X60Qx_1177 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_97 = (*X60Qx_1177);
    Value_0_valzr1t4f X60Qtmp_168 = strArg_0_runot4689((&X60QconstRefTemp_97));
    string_0_sysvq0asl s_34 = nimStrDup(X60Qtmp_168.sval_0);
    Value_0_valzr1t4f* X60Qx_1178 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_98 = (*X60Qx_1178);
    Value_0_valzr1t4f X60Qtmp_169 = strArg_0_runot4689((&X60QconstRefTemp_98));
    if (X60Qtmp_169.kind_0 == 6){
      Value_0_valzr1t4f* X60Qx_1179 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_99 = (*X60Qx_1179);
      Value_0_valzr1t4f X60Qtmp_170 = strArg_0_runot4689((&X60QconstRefTemp_99));
      string_0_sysvq0asl p_3 = nimStrDup(X60Qtmp_170.sval_0);
      NI32 X60Qx_1180 = len_4_sysvq0asl(p_3);
      NI32 X60Qx_1181 = len_4_sysvq0asl(s_34);
      NB8 ok_2 = (X60Qx_1180 <= X60Qx_1181);
      NI32 i_45 = 0;
      {
        while (NIM_TRUE){
          NB8 X60Qx_1182;
          if (ok_2){
            NI32 X60Qx_1183 = len_4_sysvq0asl(p_3);
            X60Qx_1182 = (i_45 < X60Qx_1183);}
          else {
            X60Qx_1182 = NIM_FALSE;}
          if (X60Qx_1182){
            NI32 X60Qx_1184 = len_4_sysvq0asl(s_34);
            NI32 X60Qx_1185 = len_4_sysvq0asl(p_3);
            NC8 X60Qx_1186 = getQ_9_sysvq0asl(s_34, ((NI32)(((NI32)(X60Qx_1184 - X60Qx_1185)) + i_45)));
            NC8 X60Qx_1187 = getQ_9_sysvq0asl(p_3, i_45);
            if ((!(X60Qx_1186 == X60Qx_1187))){
              ok_2 = NIM_FALSE;}
            inc_1_I6wjjge_aow2h993l1((&i_45));}
          else {
            break;}}}
      whileStmtLabel_6: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1188 = vBool_0_valzr1t4f(ok_2);
      result_76 = X60Qx_1188;
      nimStrDestroy(p_3);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_170));}
    else {
      Value_0_valzr1t4f* X60Qx_1189 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      if ((*X60Qx_1189).kind_0 == 5){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        NB8 X60Qx_1190;
        NI32 X60Qx_1191 = len_4_sysvq0asl(s_34);
        if (0 < X60Qx_1191){
          NI32 X60Qx_1192 = len_4_sysvq0asl(s_34);
          NC8 X60Qx_1193 = getQ_9_sysvq0asl(s_34, ((NI32)(X60Qx_1192 - 1)));
          Value_0_valzr1t4f* X60Qx_1194 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          X60Qx_1190 = (X60Qx_1193 == (*X60Qx_1194).cval_0);}
        else {
          X60Qx_1190 = NIM_FALSE;}
        Value_0_valzr1t4f X60Qx_1195 = vBool_0_valzr1t4f(X60Qx_1190);
        result_76 = X60Qx_1195;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1196 = vBool_0_valzr1t4f(NIM_FALSE);
        result_76 = X60Qx_1196;}}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_169));
    nimStrDestroy(s_34);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_168));}
  goto X60Qsc_441;
  X60Qsc_194: ;
  if (1 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1197 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_100 = (*X60Qx_1197);
    NU64 X60Qx_1198 = uMasked_0_runot4689((&X60QconstRefTemp_100));
    NI32 X60Qx_1199 = popcnt64_0_runot4689(X60Qx_1198);
    Value_0_valzr1t4f X60Qx_1200 = vInt_0_valzr1t4f(((NI64)X60Qx_1199), 64);
    result_76 = X60Qx_1200;}
  goto X60Qsc_441;
  X60Qsc_195: ;
  if (1 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1201 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_101 = (*X60Qx_1201);
    NU64 X60Qx_1202 = uMasked_0_runot4689((&X60QconstRefTemp_101));
    NI32 X60Qx_1203 = popcnt64_0_runot4689(X60Qx_1202);
    Value_0_valzr1t4f X60Qx_1204 = vInt_0_valzr1t4f(((NI64)((NI32)(X60Qx_1203 & 1))), 64);
    result_76 = X60Qx_1204;}
  goto X60Qsc_441;
  X60Qsc_196: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1205 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_102 = (*X60Qx_1205);
    NU64 x_18 = uMasked_0_runot4689((&X60QconstRefTemp_102));
    if (x_18 == ((NU64)0u)){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1206 = vInt_0_valzr1t4f(((NI64)0), 64);
      result_76 = X60Qx_1206;}
    else {
      NI32 c_21 = 1;
      {
        while (((NU64)(x_18 & ((NU64)1u))) == ((NU64)0u)){
          inc_1_I6wjjge_aow2h993l1((&c_21));
          x_18 = ((NU64)(x_18 >> 1));}}
      whileStmtLabel_7: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1207 = vInt_0_valzr1t4f(((NI64)c_21), 64);
      result_76 = X60Qx_1207;}}
  goto X60Qsc_441;
  X60Qsc_197: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1208 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_103 = (*X60Qx_1208);
    NI32 w_2 = bitWidthOf_0_runot4689((&X60QconstRefTemp_103));
    Value_0_valzr1t4f* X60Qx_1209 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_104 = (*X60Qx_1209);
    NU64 x_19 = uMasked_0_runot4689((&X60QconstRefTemp_104));
    if (x_19 == ((NU64)0u)){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1210 = vInt_0_valzr1t4f(((NI64)w_2), 64);
      result_76 = X60Qx_1210;}
    else {
      NI32 c_22 = 0;
      {
        while (((NU64)(x_19 & ((NU64)1u))) == ((NU64)0u)){
          inc_1_I6wjjge_aow2h993l1((&c_22));
          x_19 = ((NU64)(x_19 >> 1));}}
      whileStmtLabel_8: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1211 = vInt_0_valzr1t4f(((NI64)c_22), 64);
      result_76 = X60Qx_1211;}}
  goto X60Qsc_441;
  X60Qsc_198: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1212 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_105 = (*X60Qx_1212);
    NI32 w_3 = bitWidthOf_0_runot4689((&X60QconstRefTemp_105));
    Value_0_valzr1t4f* X60Qx_1213 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_106 = (*X60Qx_1213);
    NU64 x_20 = uMasked_0_runot4689((&X60QconstRefTemp_106));
    if (x_20 == ((NU64)0u)){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1214 = vInt_0_valzr1t4f(((NI64)w_3), 64);
      result_76 = X60Qx_1214;}
    else {
      NI32 c_23 = 0;
      NI32 bit_0 = ((NI32)(w_3 - 1));
      {
        while (NIM_TRUE){
          NB8 X60Qx_1215;
          if (0 <= bit_0){
            X60Qx_1215 = (((NU64)(x_20 & ((NU64)(((NU64)1u) << ((NU32)bit_0))))) == ((NU64)0u));}
          else {
            X60Qx_1215 = NIM_FALSE;}
          if (X60Qx_1215){
            inc_1_I6wjjge_aow2h993l1((&c_23));
            dec_1_I0nzoz91_aow7lb5cq1((&bit_0));}
          else {
            break;}}}
      whileStmtLabel_9: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1216 = vInt_0_valzr1t4f(((NI64)c_23), 64);
      result_76 = X60Qx_1216;}}
  goto X60Qsc_441;
  X60Qsc_199: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1217 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_107 = (*X60Qx_1217);
    NI32 w_4 = bitWidthOf_0_runot4689((&X60QconstRefTemp_107));
    Value_0_valzr1t4f* X60Qx_1218 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_108 = (*X60Qx_1218);
    NU64 x_21 = uMasked_0_runot4689((&X60QconstRefTemp_108));
    Value_0_valzr1t4f* X60Qx_1219 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_109 = (*X60Qx_1219);
    NI64 X60Qx_1220 = asInt_0_valzr1t4f((&X60QconstRefTemp_109));
    NI32 k_5 = ((NI32)(((NI32)X60Qx_1220) % w_4));
    if (k_5 < 0){
      plusQeQ_0_Iz7fdp7_emi78vuj01((&k_5), w_4);}
    NU64 X60Qx_33;
    if (k_5 == 0){
      X60Qx_33 = x_21;}
    else {
      X60Qx_33 = ((NU64)(((NU64)(x_21 << ((NU32)k_5))) | ((NU64)(x_21 >> ((NU32)((NI32)(w_4 - k_5)))))));}
    NU64 r_7 = X60Qx_33;
    if (w_4 < 64){
      r_7 = ((NU64)(r_7 & ((NU64)(((NU64)(((NU64)1u) << ((NU32)w_4))) - ((NU64)1u)))));}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1221 = vUInt_0_valzr1t4f(r_7, w_4);
    result_76 = X60Qx_1221;}
  goto X60Qsc_441;
  X60Qsc_200: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1222 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_110 = (*X60Qx_1222);
    NI32 w_5 = bitWidthOf_0_runot4689((&X60QconstRefTemp_110));
    Value_0_valzr1t4f* X60Qx_1223 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_111 = (*X60Qx_1223);
    NU64 x_23 = uMasked_0_runot4689((&X60QconstRefTemp_111));
    Value_0_valzr1t4f* X60Qx_1224 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_112 = (*X60Qx_1224);
    NI64 X60Qx_1225 = asInt_0_valzr1t4f((&X60QconstRefTemp_112));
    NI32 k_6 = ((NI32)(((NI32)X60Qx_1225) % w_5));
    if (k_6 < 0){
      plusQeQ_0_Iz7fdp7_emi78vuj01((&k_6), w_5);}
    NU64 X60Qx_34;
    if (k_6 == 0){
      X60Qx_34 = x_23;}
    else {
      X60Qx_34 = ((NU64)(((NU64)(x_23 >> ((NU32)k_6))) | ((NU64)(x_23 << ((NU32)((NI32)(w_5 - k_6)))))));}
    NU64 r_8 = X60Qx_34;
    if (w_5 < 64){
      r_8 = ((NU64)(r_8 & ((NU64)(((NU64)(((NU64)1u) << ((NU32)w_5))) - ((NU64)1u)))));}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1226 = vUInt_0_valzr1t4f(r_8, w_5);
    result_76 = X60Qx_1226;}
  goto X60Qsc_441;
  X60Qsc_201: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1227 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_76 = X60Qx_1227;
  goto X60Qsc_441;
  X60Qsc_202: ;
  NB8 X60Qx_1228;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1229 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1228 = ((*X60Qx_1229).kind_0 == 1);}
  else {
    X60Qx_1228 = NIM_FALSE;}
  if (X60Qx_1228){
    Value_0_valzr1t4f* X60Qx_1230 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_113 = (*X60Qx_1230);
    NI64 v_37 = asInt_0_valzr1t4f((&X60QconstRefTemp_113));
    NI64 X60Qx_35;
    if (v_37 < ((NI64)0)){
      X60Qx_35 = ((NI64)-v_37);}
    else {
      X60Qx_35 = v_37;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1231 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60Qx_1232 = vInt_0_valzr1t4f(X60Qx_35, (*X60Qx_1231).bits_0);
    result_76 = X60Qx_1232;}
  else {
    if (1 <= args_4.len_0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f* X60Qx_1233 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_114 = (*X60Qx_1233);
      Value_0_valzr1t4f X60Qx_1234 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_114));
      result_76 = X60Qx_1234;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1235 = vInt_0_valzr1t4f(((NI64)0), 64);
      result_76 = X60Qx_1235;}}
  goto X60Qsc_441;
  X60Qsc_203: ;
  NB8 X60Qx_1236;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1237 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1236 = ((*X60Qx_1237).kind_0 == 3);}
  else {
    X60Qx_1236 = NIM_FALSE;}
  if (X60Qx_1236){
    Value_0_valzr1t4f* X60Qx_1238 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    NF64 f_6 = (*X60Qx_1238).fval_0;
    NF64 X60Qx_36;
    if (f_6 < 0.0){
      X60Qx_36 = ((NF64)-f_6);}
    else {
      X60Qx_36 = f_6;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1239 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60Qx_1240 = vFloat_0_valzr1t4f(X60Qx_36, (*X60Qx_1239).fbits_0);
    result_76 = X60Qx_1240;}
  else {
    if (1 <= args_4.len_0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f* X60Qx_1241 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_115 = (*X60Qx_1241);
      Value_0_valzr1t4f X60Qx_1242 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_115));
      result_76 = X60Qx_1242;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1243 = vFloat_0_valzr1t4f(0.0, 64);
      result_76 = X60Qx_1243;}}
  goto X60Qsc_441;
  X60Qsc_204: ;
  NB8 X60Qx_1244;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1245 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1244 = ((*X60Qx_1245).kind_0 == 6);}
  else {
    X60Qx_1244 = NIM_FALSE;}
  if (X60Qx_1244){
    Value_0_valzr1t4f* X60Qx_1246 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    string_0_sysvq0asl s_35 = nimStrDup((*X60Qx_1246).sval_0);
    NI32 n_11 = 0;
    {
      while (NIM_TRUE){
        NB8 X60Qx_1247;
        NI32 X60Qx_1248 = len_4_sysvq0asl(s_35);
        if (n_11 < X60Qx_1248){
          NC8 X60Qx_1249 = getQ_9_sysvq0asl(s_35, n_11);
          X60Qx_1247 = (!(X60Qx_1249 == (NC8)'\000'));}
        else {
          X60Qx_1247 = NIM_FALSE;}
        if (X60Qx_1247){
          inc_1_I6wjjge_aow2h993l1((&n_11));}
        else {
          break;}}}
    whileStmtLabel_10: ;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1250 = vInt_0_valzr1t4f(((NI64)n_11), 64);
    result_76 = X60Qx_1250;
    nimStrDestroy(s_35);}
  else {
    NB8 X60Qx_1251;
    if (1 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1252 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      X60Qx_1251 = ((*X60Qx_1252).kind_0 == 13);}
    else {
      X60Qx_1251 = NIM_FALSE;}
    if (X60Qx_1251){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f* X60Qx_1253 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_116 = (*X60Qx_1253);
      string_0_sysvq0asl X60Qtmp_171 = ptrToString_0_runot4689((&X60QconstRefTemp_116));
      NI32 X60Qx_1254 = len_4_sysvq0asl(X60Qtmp_171);
      Value_0_valzr1t4f X60Qx_1255 = vInt_0_valzr1t4f(((NI64)X60Qx_1254), 64);
      result_76 = X60Qx_1255;
      nimStrDestroy(X60Qtmp_171);}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1256 = vInt_0_valzr1t4f(((NI64)0), 64);
      result_76 = X60Qx_1256;}}
  goto X60Qsc_441;
  X60Qsc_205: ;
  if (1 <= args_4.len_0){
    NI32 X60Qx_37;
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1257 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_117 = (*X60Qx_1257);
      NI64 X60Qx_1258 = asInt_0_valzr1t4f((&X60QconstRefTemp_117));
      X60Qx_37 = ((NI32)X60Qx_1258);}
    else {
      X60Qx_37 = 0;}
    NI32 start_0 = X60Qx_37;
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_2 = NIM_NIL;
    Value_0_valzr1t4f* X60Qx_1259 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_118 = (*X60Qx_1259);
    Value_0_valzr1t4f v_38 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_118));
    NB8 X60Qx_1260;
    NB8 X60Qx_1261;
    if (v_38.kind_0 == 13){
      X60Qx_1261 = (!(v_38.loc_0 == NIM_NIL));}
    else {
      X60Qx_1261 = NIM_FALSE;}
    if (X60Qx_1261){
      X60Qx_1260 = ((*v_38.loc_0).d_00.v_0.kind_0 == 6);}
    else {
      X60Qx_1260 = NIM_FALSE;}
    if (X60Qx_1260){
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_2);
      cell_2 = v_38.loc_0;
      eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&v_38.loc_0));}
    else {
      if (v_38.kind_0 == 6){
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_2);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1262 = newCell_0_valzr1t4f((&v_38));
        cell_2 = X60Qx_1262;}}
    if ((!(cell_2 == NIM_NIL))){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      void* X60Qx_1263 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_172 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1263);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_173 = cell_2;
      eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&cell_2));
      (*X60Qtmp_172) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
          .kind_0 = 3, .scell_0 = X60Qtmp_173}}
      ;
      Value_0_valzr1t4f X60Qx_1264 = vPtrReg_0_valzr1t4f(X60Qtmp_172, ((NI32)start_0), ((NI16)8), 5);
      result_76 = X60Qx_1264;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_172);}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1265 = vPtrLoc_0_valzr1t4f(((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL));
      result_76 = X60Qx_1265;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_38));
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_2);}
  goto X60Qsc_441;
  X60Qsc_206: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1266 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_119 = (*X60Qx_1266);
    NI64 X60Qx_1267 = asInt_0_valzr1t4f((&X60QconstRefTemp_119));
    NI32 newLen_0 = ((NI32)X60Qx_1267);
    NI32 X60Qx_38;
    if (3 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1268 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
      Value_0_valzr1t4f X60QconstRefTemp_120 = (*X60Qx_1268);
      NI64 X60Qx_1269 = asInt_0_valzr1t4f((&X60QconstRefTemp_120));
      X60Qx_38 = ((NI32)X60Qx_1269);}
    else {
      X60Qx_38 = 0;}
    NI32 start_1 = X60Qx_38;
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_3 = NIM_NIL;
    Value_0_valzr1t4f* X60Qx_1270 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_121 = (*X60Qx_1270);
    Value_0_valzr1t4f v_39 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_121));
    NB8 X60Qx_1271;
    NB8 X60Qx_1272;
    if (v_39.kind_0 == 13){
      X60Qx_1272 = (!(v_39.loc_0 == NIM_NIL));}
    else {
      X60Qx_1272 = NIM_FALSE;}
    if (X60Qx_1272){
      X60Qx_1271 = ((*v_39.loc_0).d_00.v_0.kind_0 == 6);}
    else {
      X60Qx_1271 = NIM_FALSE;}
    if (X60Qx_1271){
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_3);
      cell_3 = v_39.loc_0;
      eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&v_39.loc_0));}
    if ((!(cell_3 == NIM_NIL))){
      string_0_sysvq0asl s_36 = nimStrDup((*cell_3).d_00.v_0.sval_0);
      NI32 X60Qx_1273 = len_4_sysvq0asl(s_36);
      if (X60Qx_1273 < newLen_0){
        {
          while (NIM_TRUE){
            NI32 X60Qx_1274 = len_4_sysvq0asl(s_36);
            if (X60Qx_1274 < newLen_0){
              add_1_sysvq0asl((&s_36), (NC8)'\000');}
            else {
              break;}}}
        whileStmtLabel_11: ;}
      else {
        NB8 X60Qx_1275;
        if (0 <= newLen_0){
          NI32 X60Qx_1276 = len_4_sysvq0asl(s_36);
          X60Qx_1275 = (newLen_0 < X60Qx_1276);}
        else {
          X60Qx_1275 = NIM_FALSE;}
        if (X60Qx_1275){
          string_0_sysvq0asl X60Qx_39;
          nimStrWasMoved((&X60Qx_39));
          if (newLen_0 == 0){
            nimStrDestroy(X60Qx_39);
            X60Qx_39 = (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            ;}
          else {
            nimStrDestroy(X60Qx_39);
            string_0_sysvq0asl X60Qx_1277 = substr_0_sysvq0asl(s_36, 0, ((NI32)(newLen_0 - 1)));
            X60Qx_39 = X60Qx_1277;}
          nimStrDestroy(s_36);
          s_36 = X60Qx_39;
          nimStrWasMoved((&X60Qx_39));
          nimStrDestroy(X60Qx_39);}}
      Value_0_valzr1t4f* X60Qlhs_174 = (&(*cell_3).d_00.v_0);
      Value_0_valzr1t4f X60Qlhs_175 = vStr_0_valzr1t4f(s_36);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_174)));
      (*X60Qlhs_174) = X60Qlhs_175;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      void* X60Qx_1278 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_176 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1278);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_177 = cell_3;
      eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&cell_3));
      (*X60Qtmp_176) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
          .kind_0 = 3, .scell_0 = X60Qtmp_177}}
      ;
      Value_0_valzr1t4f X60Qx_1279 = vPtrReg_0_valzr1t4f(X60Qtmp_176, ((NI32)start_1), ((NI16)8), 5);
      result_76 = X60Qx_1279;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_176);
      nimStrDestroy(s_36);}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1280 = vPtrLoc_0_valzr1t4f(((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL));
      result_76 = X60Qx_1280;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_39));
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_3);}
  goto X60Qsc_441;
  X60Qsc_207: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1281 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_122 = (*X60Qx_1281);
    Value_0_valzr1t4f v_40 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_122));
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_24 = ptrCell_0_runot4689((&v_40));
    NB8 X60Qx_1282;
    if ((!(c_24 == NIM_NIL))){
      X60Qx_1282 = (!((*c_24).d_00.v_0.kind_0 == 13));}
    else {
      X60Qx_1282 = NIM_FALSE;}
    if (X60Qx_1282){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_40));
      Value_0_valzr1t4f X60Qx_1283 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_24).d_00.v_0));
      v_40 = X60Qx_1283;}
    string_0_sysvq0asl s_37 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1284 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_123 = (*X60Qx_1284);
      NI64 X60Qx_1285 = asInt_0_valzr1t4f((&X60QconstRefTemp_123));
      NI32 n_12 = ((NI32)X60Qx_1285);
      if (0 < n_12){
        if (v_40.kind_0 == 6){
          string_0_sysvq0asl X60Qx_40;
          nimStrWasMoved((&X60Qx_40));
          NI32 X60Qx_1286 = len_4_sysvq0asl(v_40.sval_0);
          if (n_12 <= X60Qx_1286){
            nimStrDestroy(X60Qx_40);
            string_0_sysvq0asl X60Qx_1287 = substr_0_sysvq0asl(v_40.sval_0, 0, ((NI32)(n_12 - 1)));
            X60Qx_40 = X60Qx_1287;}
          else {
            nimStrDestroy(X60Qx_40);
            X60Qx_40 = v_40.sval_0;
            nimStrWasMoved((&v_40.sval_0));}
          nimStrDestroy(s_37);
          s_37 = X60Qx_40;
          nimStrWasMoved((&X60Qx_40));
          nimStrDestroy(X60Qx_40);}
        else {
          NB8 X60Qx_133;
          if (v_40.kind_0 == 13){
            X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_178 = region_0_valzr1t4f((&v_40));
            X60Qx_133 = (!(X60Qtmp_178 == NIM_NIL));
            eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_178);}
          else {
            X60Qx_133 = NIM_FALSE;}
          if (X60Qx_133){
            NI32 i_46 = 0;
            {
              while (i_46 < n_12){
                X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_179 = region_0_valzr1t4f((&v_40));
                NI32 X60Qx_1288 = foff_0_valzr1t4f((&v_40));
                NU8 X60Qx_1289 = byteAt_0_flaksyopx1(X60Qtmp_179, ((NI32)(((NI32)X60Qx_1288) + i_46)));
                add_1_sysvq0asl((&s_37), ((NC8)X60Qx_1289));
                inc_1_I6wjjge_aow2h993l1((&i_46));
                eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_179);}}
            whileStmtLabel_12: ;}}}}
    else {
      if (v_40.kind_0 == 6){
        nimStrDestroy(s_37);
        s_37 = v_40.sval_0;
        nimStrWasMoved((&v_40.sval_0));}
      else {
        NB8 X60Qx_134;
        if (v_40.kind_0 == 13){
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_180 = region_0_valzr1t4f((&v_40));
          X60Qx_134 = (!(X60Qtmp_180 == NIM_NIL));
          eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_180);}
        else {
          X60Qx_134 = NIM_FALSE;}
        if (X60Qx_134){
          NI32 i_47 = 0;
          {
            while (NIM_TRUE){
              X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_181 = region_0_valzr1t4f((&v_40));
              NI32 X60Qx_1290 = foff_0_valzr1t4f((&v_40));
              NU8 b_11 = byteAt_0_flaksyopx1(X60Qtmp_181, ((NI32)(((NI32)X60Qx_1290) + i_47)));
              if (b_11 == ((NU8)0u)){
                eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_181);
                goto whileStmtLabel_13;}
              add_1_sysvq0asl((&s_37), ((NC8)b_11));
              inc_1_I6wjjge_aow2h993l1((&i_47));
              eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_181);}}
          whileStmtLabel_13: ;}}}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1291 = vStr_0_valzr1t4f(s_37);
    result_76 = X60Qx_1291;
    nimStrDestroy(s_37);
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_24);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_40));}
  goto X60Qsc_441;
  X60Qsc_208: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1292 = vNil_0_valzr1t4f();
  result_76 = X60Qx_1292;
  goto X60Qsc_441;
  X60Qsc_209: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1293 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_124 = (*X60Qx_1293);
    Value_0_valzr1t4f v_41 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_124));
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_25 = ptrCell_0_runot4689((&v_41));
    NB8 X60Qx_1294;
    if ((!(c_25 == NIM_NIL))){
      X60Qx_1294 = ((*c_25).d_00.v_0.kind_0 == 6);}
    else {
      X60Qx_1294 = NIM_FALSE;}
    if (X60Qx_1294){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      void* X60Qx_1295 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_182 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1295);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_183 = c_25;
      eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&c_25));
      (*X60Qtmp_182) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
          .kind_0 = 3, .scell_0 = X60Qtmp_183}}
      ;
      Value_0_valzr1t4f X60Qx_1296 = vPtrReg_0_valzr1t4f(X60Qtmp_182, ((NI32)0), ((NI16)8), 5);
      result_76 = X60Qx_1296;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_182);}
    else {
      if ((!(c_25 == NIM_NIL))){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1297 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_25).d_00.v_0));
        result_76 = X60Qx_1297;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1298 = strArg_0_runot4689((&v_41));
        result_76 = X60Qx_1298;}}
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_25);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_41));}
  goto X60Qsc_441;
  X60Qsc_210: ;
  NB8 X60Qx_1299;
  NB8 X60Qx_1300;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1301 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1300 = ((*X60Qx_1301).kind_0 == 6);}
  else {
    X60Qx_1300 = NIM_FALSE;}
  if (X60Qx_1300){
    Value_0_valzr1t4f* X60Qx_1302 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    X60Qx_1299 = ((*X60Qx_1302).kind_0 == 7);}
  else {
    X60Qx_1299 = NIM_FALSE;}
  if (X60Qx_1299){
    string_0_sysvq0asl X60Qx_41;
    nimStrWasMoved((&X60Qx_41));
    Value_0_valzr1t4f* X60Qx_1303 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    switch ((*X60Qx_1303).eord_0){
      case 1:
      {
        nimStrDestroy(X60Qx_41);
        X60Qx_41 = (string_0_sysvq0asl){
          .bytes_0 = 6452994u, .more_0 = NIM_NIL}
        ;}
      break;
      case 2:
      {
        nimStrDestroy(X60Qx_41);
        X60Qx_41 = (string_0_sysvq0asl){
          .bytes_0 = 1647015683u, .more_0 = NIM_NIL}
        ;}
      break;
      case 3:
      {
        nimStrDestroy(X60Qx_41);
        X60Qx_41 = (string_0_sysvq0asl){
          .bytes_0 = 1647014403u, .more_0 = NIM_NIL}
        ;}
      break;
      case 4:
      {
        nimStrDestroy(X60Qx_41);
        X60Qx_41 = (string_0_sysvq0asl){
          .bytes_0 = 6447362u, .more_0 = NIM_NIL}
        ;}
      break;
      default:
      {
        nimStrDestroy(X60Qx_41);
        X60Qx_41 = (string_0_sysvq0asl){
          .bytes_0 = 6451714u, .more_0 = NIM_NIL}
        ;}
      break;}
    string_0_sysvq0asl modeStr_0 = X60Qx_41;
    nimStrWasMoved((&X60Qx_41));
    Value_0_valzr1t4f* X60Qx_1304 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    NI32 fd_4 = hostOpenC_0_hos5i19e11(sink_13, (*X60Qx_1304).sval_0, modeStr_0);
    Value_0_valzr1t4f X60Qx_42;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
    if (fd_4 < 0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
      Value_0_valzr1t4f X60Qx_1305 = vNil_0_valzr1t4f();
      X60Qx_42 = X60Qx_1305;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
      Value_0_valzr1t4f X60Qx_1306 = vInt_0_valzr1t4f(((NI64)fd_4), 64);
      X60Qx_42 = X60Qx_1306;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    result_76 = X60Qx_42;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
    nimStrDestroy(modeStr_0);
    nimStrDestroy(X60Qx_41);}
  else {
    NB8 X60Qx_1307;
    NB8 X60Qx_1308;
    if (3 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1309 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      X60Qx_1308 = ((*X60Qx_1309).kind_0 == 6);}
    else {
      X60Qx_1308 = NIM_FALSE;}
    if (X60Qx_1308){
      Value_0_valzr1t4f* X60Qx_1310 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
      X60Qx_1307 = ((*X60Qx_1310).kind_0 == 7);}
    else {
      X60Qx_1307 = NIM_FALSE;}
    if (X60Qx_1307){
      string_0_sysvq0asl X60Qx_43;
      nimStrWasMoved((&X60Qx_43));
      Value_0_valzr1t4f* X60Qx_1311 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
      switch ((*X60Qx_1311).eord_0){
        case 1:
        {
          nimStrDestroy(X60Qx_43);
          X60Qx_43 = (string_0_sysvq0asl){
            .bytes_0 = 6452994u, .more_0 = NIM_NIL}
          ;}
        break;
        case 2:
        {
          nimStrDestroy(X60Qx_43);
          X60Qx_43 = (string_0_sysvq0asl){
            .bytes_0 = 1647015683u, .more_0 = NIM_NIL}
          ;}
        break;
        case 3:
        {
          nimStrDestroy(X60Qx_43);
          X60Qx_43 = (string_0_sysvq0asl){
            .bytes_0 = 1647014403u, .more_0 = NIM_NIL}
          ;}
        break;
        case 4:
        {
          nimStrDestroy(X60Qx_43);
          X60Qx_43 = (string_0_sysvq0asl){
            .bytes_0 = 6447362u, .more_0 = NIM_NIL}
          ;}
        break;
        default:
        {
          nimStrDestroy(X60Qx_43);
          X60Qx_43 = (string_0_sysvq0asl){
            .bytes_0 = 6451714u, .more_0 = NIM_NIL}
          ;}
        break;}
      string_0_sysvq0asl modeStr_1 = X60Qx_43;
      nimStrWasMoved((&X60Qx_43));
      Value_0_valzr1t4f* X60Qx_1312 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      NI32 fd_5 = hostOpenC_0_hos5i19e11(sink_13, (*X60Qx_1312).sval_0, modeStr_1);
      Value_0_valzr1t4f* X60Qx_1313 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_125 = (*X60Qx_1313);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_4 = ptrCell_0_runot4689((&X60QconstRefTemp_125));
      if ((!(cell_4 == NIM_NIL))){
        Value_0_valzr1t4f X60Qx_44;
        eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));
        if (fd_5 < 0){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));
          Value_0_valzr1t4f X60Qx_1314 = vNil_0_valzr1t4f();
          X60Qx_44 = X60Qx_1314;}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));
          Value_0_valzr1t4f X60Qx_1315 = vInt_0_valzr1t4f(((NI64)fd_5), 64);
          X60Qx_44 = X60Qx_1315;}
        Value_0_valzr1t4f* X60Qlhs_184 = (&(*cell_4).d_00.v_0);
        Value_0_valzr1t4f X60Qlhs_185 = X60Qx_44;
        eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_184)));
        (*X60Qlhs_184) = X60Qlhs_185;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1316 = vBool_0_valzr1t4f((0 <= fd_5));
      result_76 = X60Qx_1316;
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_4);
      nimStrDestroy(modeStr_1);
      nimStrDestroy(X60Qx_43);}
    else {
      if (2 <= args_4.len_0){
        Value_0_valzr1t4f* X60Qx_1317 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        Value_0_valzr1t4f X60QconstRefTemp_126 = (*X60Qx_1317);
        string_0_sysvq0asl X60Qtmp_186 = ptrToString_0_runot4689((&X60QconstRefTemp_126));
        Value_0_valzr1t4f* X60Qx_1318 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_127 = (*X60Qx_1318);
        NI64 X60Qx_1319 = asInt_0_valzr1t4f((&X60QconstRefTemp_127));
        NI32 fd_6 = hostOpenPosix_0_hos5i19e11(sink_13, X60Qtmp_186, ((NI32)X60Qx_1319));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1320 = vInt_0_valzr1t4f(((NI64)fd_6), 32);
        result_76 = X60Qx_1320;
        nimStrDestroy(X60Qtmp_186);}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1321 = vInt_0_valzr1t4f(((NI64)-1), 32);
        result_76 = X60Qx_1321;}}}
  goto X60Qsc_441;
  X60Qsc_211: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1322 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_128 = (*X60Qx_1322);
    string_0_sysvq0asl X60Qtmp_187 = ptrToString_0_runot4689((&X60QconstRefTemp_128));
    Value_0_valzr1t4f* X60Qx_1323 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_129 = (*X60Qx_1323);
    string_0_sysvq0asl X60Qtmp_188 = ptrToString_0_runot4689((&X60QconstRefTemp_129));
    NI32 fd_7 = hostOpenC_0_hos5i19e11(sink_13, X60Qtmp_187, X60Qtmp_188);
    Value_0_valzr1t4f X60Qx_45;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));
    if (fd_7 < 0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));
      Value_0_valzr1t4f X60Qx_1324 = vNil_0_valzr1t4f();
      X60Qx_45 = X60Qx_1324;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));
      Value_0_valzr1t4f X60Qx_1325 = vInt_0_valzr1t4f(((NI64)fd_7), 64);
      X60Qx_45 = X60Qx_1325;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    result_76 = X60Qx_45;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));
    nimStrDestroy(X60Qtmp_188);
    nimStrDestroy(X60Qtmp_187);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1326 = vNil_0_valzr1t4f();
    result_76 = X60Qx_1326;}
  goto X60Qsc_441;
  X60Qsc_212: ;
  if (1 <= args_4.len_0){
    NI32 rfd_0 = 0;
    NI32 wfd_0 = 0;
    NB8 X60Qx_1327 = hostPipe_0_hos5i19e11(sink_13, (&rfd_0), (&wfd_0));
    if (X60Qx_1327){
      Value_0_valzr1t4f* X60Qx_1328 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_130 = (*X60Qx_1328);
      Value_0_valzr1t4f target_3 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_130));
      NB8 X60Qx_1329;
      if (target_3.kind_0 == 13){
        X60Qx_1329 = (!(target_3.loc_0 == NIM_NIL));}
      else {
        X60Qx_1329 = NIM_FALSE;}
      if (X60Qx_1329){
        Value_0_valzr1t4f X60Qlhs_189 = target_3;
        Value_0_valzr1t4f X60Qx_1330 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*target_3.loc_0).d_00.v_0));
        target_3 = X60Qx_1330;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_189));}
      else {
        NB8 X60Qx_1331;
        if (target_3.kind_0 == 12){
          X60Qx_1331 = (!(target_3.rf_0 == NIM_NIL));}
        else {
          X60Qx_1331 = NIM_FALSE;}
        if (X60Qx_1331){
          Value_0_valzr1t4f X60Qlhs_190 = target_3;
          Value_0_valzr1t4f X60Qx_1332 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*target_3.rf_0).d_00.v_0));
          target_3 = X60Qx_1332;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_190));}}
      NB8 X60Qx_1333;
      NB8 X60Qx_1334;
      if (target_3.kind_0 == 9){
        X60Qx_1334 = (!(target_3.arr_0 == NIM_NIL));}
      else {
        X60Qx_1334 = NIM_FALSE;}
      if (X60Qx_1334){
        X60Qx_1333 = (2 <= (*target_3.arr_0).d_00.elems_0.len_0);}
      else {
        X60Qx_1333 = NIM_FALSE;}
      if (X60Qx_1333){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1335 = getQ_7_Ii14ync1_arecyyj7v((*target_3.arr_0).d_00.elems_0, 0);
        Value_0_valzr1t4f* X60Qlhs_191 = (&(*(*X60Qx_1335)).d_00.v_0);
        Value_0_valzr1t4f X60Qlhs_192 = vInt_0_valzr1t4f(((NI64)rfd_0), 32);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_191)));
        (*X60Qlhs_191) = X60Qlhs_192;
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1336 = getQ_7_Ii14ync1_arecyyj7v((*target_3.arr_0).d_00.elems_0, 1);
        Value_0_valzr1t4f* X60Qlhs_193 = (&(*(*X60Qx_1336)).d_00.v_0);
        Value_0_valzr1t4f X60Qlhs_194 = vInt_0_valzr1t4f(((NI64)wfd_0), 32);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_193)));
        (*X60Qlhs_193) = X60Qlhs_194;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1337 = vInt_0_valzr1t4f(((NI64)0), 32);
      result_76 = X60Qx_1337;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_3));}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1338 = vInt_0_valzr1t4f(((NI64)-1), 32);
      result_76 = X60Qx_1338;}}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1339 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_1339;}
  goto X60Qsc_441;
  X60Qsc_213: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1340 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_131 = (*X60Qx_1340);
    NI32 fd_8 = fdOfValue_0_runot4689((&X60QconstRefTemp_131));
    NB8 X60Qx_1341 = isSockHandle_0_hos9jnsbq1(fd_8);
    if (X60Qx_1341){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      NI32 X60Qx_1342 = hostSockClose_0_hos9jnsbq1(fd_8);
      Value_0_valzr1t4f X60Qx_1343 = vInt_0_valzr1t4f(((NI64)X60Qx_1342), 32);
      result_76 = X60Qx_1343;
      publishSockErrno_0_runot4689();}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      NI32 X60Qx_1344 = hostClose_0_hos5i19e11(sink_13, fd_8);
      Value_0_valzr1t4f X60Qx_1345 = vInt_0_valzr1t4f(((NI64)X60Qx_1344), 32);
      result_76 = X60Qx_1345;}}
  goto X60Qsc_441;
  X60Qsc_214: ;
  if (1 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1346 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_132 = (*X60Qx_1346);
    NI32 X60Qx_1347 = fdOfValue_0_runot4689((&X60QconstRefTemp_132));
    NI32 X60Qx_1348 = hostClose_0_hos5i19e11(sink_13, X60Qx_1347);
    Value_0_valzr1t4f X60Qx_1349 = vInt_0_valzr1t4f(((NI64)X60Qx_1348), 32);
    result_76 = X60Qx_1349;}
  goto X60Qsc_441;
  X60Qsc_215: ;
  if (3 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1350 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_133 = (*X60Qx_1350);
    NI32 X60Qx_1351 = fdOfValue_0_runot4689((&X60QconstRefTemp_133));
    Value_0_valzr1t4f* X60Qx_1352 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_134 = (*X60Qx_1352);
    NI64 X60Qx_1353 = asInt_0_valzr1t4f((&X60QconstRefTemp_134));
    Value_0_valzr1t4f* X60Qx_1354 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_135 = (*X60Qx_1354);
    NI64 X60Qx_1355 = asInt_0_valzr1t4f((&X60QconstRefTemp_135));
    NI64 X60Qx_1356 = hostLseek_0_hos5i19e11(sink_13, X60Qx_1351, X60Qx_1353, ((NI32)X60Qx_1355));
    Value_0_valzr1t4f X60Qx_1357 = vInt_0_valzr1t4f(X60Qx_1356, 64);
    result_76 = X60Qx_1357;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1358 = vInt_0_valzr1t4f(((NI64)-1), 64);
    result_76 = X60Qx_1358;}
  goto X60Qsc_441;
  X60Qsc_216: ;
  if (3 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1359 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_136 = (*X60Qx_1359);
    NI32 X60Qx_1360 = fdOfValue_0_runot4689((&X60QconstRefTemp_136));
    Value_0_valzr1t4f* X60Qx_1361 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_137 = (*X60Qx_1361);
    NI64 X60Qx_1362 = asInt_0_valzr1t4f((&X60QconstRefTemp_137));
    Value_0_valzr1t4f* X60Qx_1363 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_138 = (*X60Qx_1363);
    NI64 X60Qx_1364 = asInt_0_valzr1t4f((&X60QconstRefTemp_138));
    NI64 r_9 = hostLseek_0_hos5i19e11(sink_13, X60Qx_1360, X60Qx_1362, ((NI32)X60Qx_1364));
    NI64 X60Qx_46;
    if (r_9 < ((NI64)0)){
      X60Qx_46 = ((NI64)-1);}
    else {
      X60Qx_46 = ((NI64)0);}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1365 = vInt_0_valzr1t4f(X60Qx_46, 32);
    result_76 = X60Qx_1365;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1366 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_1366;}
  goto X60Qsc_441;
  X60Qsc_217: ;
  if (1 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1367 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_139 = (*X60Qx_1367);
    NI32 X60Qx_1368 = fdOfValue_0_runot4689((&X60QconstRefTemp_139));
    NI64 X60Qx_1369 = hostTell_0_hos5i19e11(sink_13, X60Qx_1368);
    Value_0_valzr1t4f X60Qx_1370 = vInt_0_valzr1t4f(X60Qx_1369, 64);
    result_76 = X60Qx_1370;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1371 = vInt_0_valzr1t4f(((NI64)-1), 64);
    result_76 = X60Qx_1371;}
  goto X60Qsc_441;
  X60Qsc_218: ;
  if (3 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1372 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_140 = (*X60Qx_1372);
    NI32 fd_9 = fdOfValue_0_runot4689((&X60QconstRefTemp_140));
    Value_0_valzr1t4f* X60Qx_1373 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_141 = (*X60Qx_1373);
    NI64 X60Qx_1374 = asInt_0_valzr1t4f((&X60QconstRefTemp_141));
    NI32 n_13 = ((NI32)X60Qx_1374);
    string_0_sysvq0asl data_4 = hostRead_0_hos5i19e11(sink_13, fd_9, n_13);
    Value_0_valzr1t4f* X60Qx_1375 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_142 = (*X60Qx_1375);
    ptrWriteBytes_0_runot4689((&X60QconstRefTemp_142), data_4);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    NI32 X60Qx_1376 = len_4_sysvq0asl(data_4);
    Value_0_valzr1t4f X60Qx_1377 = vInt_0_valzr1t4f(((NI64)X60Qx_1376), 64);
    result_76 = X60Qx_1377;
    nimStrDestroy(data_4);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1378 = vInt_0_valzr1t4f(((NI64)-1), 64);
    result_76 = X60Qx_1378;}
  goto X60Qsc_441;
  X60Qsc_219: ;
  if (4 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1379 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_143 = (*X60Qx_1379);
    NI64 X60Qx_1380 = asInt_0_valzr1t4f((&X60QconstRefTemp_143));
    NI32 size_7 = ((NI32)X60Qx_1380);
    Value_0_valzr1t4f* X60Qx_1381 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_144 = (*X60Qx_1381);
    NI64 X60Qx_1382 = asInt_0_valzr1t4f((&X60QconstRefTemp_144));
    NI32 cnt_0 = ((NI32)X60Qx_1382);
    Value_0_valzr1t4f* X60Qx_1383 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
    Value_0_valzr1t4f X60QconstRefTemp_145 = (*X60Qx_1383);
    NI32 fd_10 = fdOfValue_0_runot4689((&X60QconstRefTemp_145));
    NI32 want_1 = ((NI32)(size_7 * cnt_0));
    string_0_sysvq0asl data_5 = hostRead_0_hos5i19e11(sink_13, fd_10, want_1);
    Value_0_valzr1t4f* X60Qx_1384 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_146 = (*X60Qx_1384);
    ptrWriteBytes_0_runot4689((&X60QconstRefTemp_146), data_5);
    NI32 X60Qx_47;
    if (0 < size_7){
      NI32 X60Qx_1385 = len_4_sysvq0asl(data_5);
      X60Qx_47 = ((NI32)(X60Qx_1385 / size_7));}
    else {
      X60Qx_47 = 0;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1386 = vUInt_0_valzr1t4f(((NU64)X60Qx_47), 64);
    result_76 = X60Qx_1386;
    nimStrDestroy(data_5);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1387 = vUInt_0_valzr1t4f(((NU64)0u), 64);
    result_76 = X60Qx_1387;}
  goto X60Qsc_441;
  X60Qsc_220: ;
  if (4 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1388 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_147 = (*X60Qx_1388);
    NI64 X60Qx_1389 = asInt_0_valzr1t4f((&X60QconstRefTemp_147));
    NI32 size_8 = ((NI32)X60Qx_1389);
    Value_0_valzr1t4f* X60Qx_1390 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_148 = (*X60Qx_1390);
    NI64 X60Qx_1391 = asInt_0_valzr1t4f((&X60QconstRefTemp_148));
    NI32 cnt_1 = ((NI32)X60Qx_1391);
    NI32 total_0 = ((NI32)(size_8 * cnt_1));
    Value_0_valzr1t4f* X60Qx_1392 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_149 = (*X60Qx_1392);
    string_0_sysvq0asl data_6 = ptrReadBytes_0_runot4689((&X60QconstRefTemp_149), total_0);
    Value_0_valzr1t4f* X60Qx_1393 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
    if ((*X60Qx_1393).kind_0 == 16){
      Value_0_valzr1t4f* X60Qx_1394 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
      writeStr_0_natd5co251(sink_13, (*X60Qx_1394).toErr_0, data_6);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1395 = vUInt_0_valzr1t4f(((NU64)cnt_1), 64);
      result_76 = X60Qx_1395;}
    else {
      Value_0_valzr1t4f* X60Qx_1396 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
      Value_0_valzr1t4f X60QconstRefTemp_150 = (*X60Qx_1396);
      NI32 X60Qx_1397 = fdOfValue_0_runot4689((&X60QconstRefTemp_150));
      NI32 X60Qx_1398 = len_4_sysvq0asl(data_6);
      NI32 wrote_1 = hostWrite_0_hos5i19e11(sink_13, X60Qx_1397, data_6, X60Qx_1398);
      NU64 X60Qx_48;
      if (wrote_1 < 0){
        X60Qx_48 = ((NU64)0u);}
      else {
        NI32 X60Qx_49;
        if (0 < size_8){
          X60Qx_49 = ((NI32)(wrote_1 / size_8));}
        else {
          X60Qx_49 = 0;}
        X60Qx_48 = ((NU64)X60Qx_49);}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1399 = vUInt_0_valzr1t4f(X60Qx_48, 64);
      result_76 = X60Qx_1399;}
    nimStrDestroy(data_6);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1400 = vUInt_0_valzr1t4f(((NU64)0u), 64);
    result_76 = X60Qx_1400;}
  goto X60Qsc_441;
  X60Qsc_221: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1401 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_151 = (*X60Qx_1401);
    NI64 X60Qx_1402 = asInt_0_valzr1t4f((&X60QconstRefTemp_151));
    NC8 ch_0 = ((NC8)((NU8)((NI64)(X60Qx_1402 & ((NI64)255)))));
    string_0_sysvq0asl s_38 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    add_1_sysvq0asl((&s_38), ch_0);
    Value_0_valzr1t4f* X60Qx_1403 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    if ((*X60Qx_1403).kind_0 == 16){
      Value_0_valzr1t4f* X60Qx_1404 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      writeStr_0_natd5co251(sink_13, (*X60Qx_1404).toErr_0, s_38);}
    else {
      Value_0_valzr1t4f* X60Qx_1405 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_152 = (*X60Qx_1405);
      NI32 X60Qx_1406 = fdOfValue_0_runot4689((&X60QconstRefTemp_152));
      NI32 X60Qx_1407 = hostWrite_0_hos5i19e11(sink_13, X60Qx_1406, s_38, 1);}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1408 = vInt_0_valzr1t4f(((NI64)((NU8)ch_0)), 32);
    result_76 = X60Qx_1408;
    nimStrDestroy(s_38);}
  goto X60Qsc_441;
  X60Qsc_222: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1409 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_153 = (*X60Qx_1409);
    NI32 X60Qx_1410 = fdOfValue_0_runot4689((&X60QconstRefTemp_153));
    string_0_sysvq0asl b_12 = hostRead_0_hos5i19e11(sink_13, X60Qx_1410, 1);
    NI64 X60Qx_50;
    NI32 X60Qx_1411 = len_4_sysvq0asl(b_12);
    if (X60Qx_1411 == 0){
      X60Qx_50 = ((NI64)-1);}
    else {
      NC8 X60Qx_1412 = getQ_9_sysvq0asl(b_12, 0);
      X60Qx_50 = ((NI64)((NU8)X60Qx_1412));}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1413 = vInt_0_valzr1t4f(X60Qx_50, 32);
    result_76 = X60Qx_1413;
    nimStrDestroy(b_12);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1414 = vInt_0_valzr1t4f(((NI64)-1), 32);
    result_76 = X60Qx_1414;}
  goto X60Qsc_441;
  X60Qsc_223: ;
  if (1 <= args_4.len_0){
    NB8 found_7 = NIM_FALSE;
    Value_0_valzr1t4f* X60Qx_1415 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_154 = (*X60Qx_1415);
    string_0_sysvq0asl X60Qtmp_195 = ptrToString_0_runot4689((&X60QconstRefTemp_154));
    string_0_sysvq0asl v_42 = envGet_0_natd5co251(sink_13, X60Qtmp_195, (&found_7));
    Value_0_valzr1t4f X60Qx_51;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_51));
    if (found_7){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_51));
      Value_0_valzr1t4f X60Qx_1416 = vStr_0_valzr1t4f(v_42);
      X60Qx_51 = X60Qx_1416;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_51));
      Value_0_valzr1t4f X60Qx_1417 = vNil_0_valzr1t4f();
      X60Qx_51 = X60Qx_1417;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    result_76 = X60Qx_51;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_51));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_51));
    nimStrDestroy(v_42);
    nimStrDestroy(X60Qtmp_195);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1418 = vNil_0_valzr1t4f();
    result_76 = X60Qx_1418;}
  goto X60Qsc_441;
  X60Qsc_224: ;
  if (1 <= args_4.len_0){
    NB8 found_8 = NIM_FALSE;
    Value_0_valzr1t4f* X60Qx_1419 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_155 = (*X60Qx_1419);
    string_0_sysvq0asl X60Qtmp_196 = ptrToString_0_runot4689((&X60QconstRefTemp_155));
    string_0_sysvq0asl v_43 = envGet_0_natd5co251(sink_13, X60Qtmp_196, (&found_8));
    if (found_8){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1420 = vStr_0_valzr1t4f(v_43);
      result_76 = X60Qx_1420;}
    else {
      NB8 X60Qx_1421;
      if (2 <= args_4.len_0){
        Value_0_valzr1t4f* X60Qx_1422 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        X60Qx_1421 = ((*X60Qx_1422).kind_0 == 6);}
      else {
        X60Qx_1421 = NIM_FALSE;}
      if (X60Qx_1421){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f* X60Qx_1423 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60Qx_1424 = vStr_0_valzr1t4f((*X60Qx_1423).sval_0);
        result_76 = X60Qx_1424;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1425 = vStr_0_valzr1t4f((string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        );
        result_76 = X60Qx_1425;}}
    nimStrDestroy(v_43);
    nimStrDestroy(X60Qtmp_196);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1426 = vStr_0_valzr1t4f((string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    result_76 = X60Qx_1426;}
  goto X60Qsc_441;
  X60Qsc_225: ;
  if (1 <= args_4.len_0){
    NB8 found_9 = NIM_FALSE;
    Value_0_valzr1t4f* X60Qx_1427 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_156 = (*X60Qx_1427);
    string_0_sysvq0asl X60Qtmp_198 = ptrToString_0_runot4689((&X60QconstRefTemp_156));
    string_0_sysvq0asl X60Qtmp_197 = envGet_0_natd5co251(sink_13, X60Qtmp_198, (&found_9));
    string_0_sysvq0asl X60Qx_1428 = X60Qtmp_197;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1429 = vBool_0_valzr1t4f(found_9);
    result_76 = X60Qx_1429;
    nimStrDestroy(X60Qtmp_197);
    nimStrDestroy(X60Qtmp_198);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1430 = vBool_0_valzr1t4f(NIM_FALSE);
    result_76 = X60Qx_1430;}
  goto X60Qsc_441;
  X60Qsc_226: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1431 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_157 = (*X60Qx_1431);
    string_0_sysvq0asl X60Qtmp_199 = ptrToString_0_runot4689((&X60QconstRefTemp_157));
    Value_0_valzr1t4f* X60Qx_1432 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_158 = (*X60Qx_1432);
    string_0_sysvq0asl X60Qtmp_200 = ptrToString_0_runot4689((&X60QconstRefTemp_158));
    envPut_0_natd5co251(sink_13, X60Qtmp_199, X60Qtmp_200);
    nimStrDestroy(X60Qtmp_200);
    nimStrDestroy(X60Qtmp_199);}
  goto X60Qsc_441;
  X60Qsc_227: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1433 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_159 = (*X60Qx_1433);
    string_0_sysvq0asl X60Qtmp_201 = ptrToString_0_runot4689((&X60QconstRefTemp_159));
    envDel_0_natd5co251(sink_13, X60Qtmp_201);
    nimStrDestroy(X60Qtmp_201);}
  goto X60Qsc_441;
  X60Qsc_228: ;
  NB8 X60Qx_1434;
  NB8 X60Qx_1435;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1436 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1435 = ((*X60Qx_1436).kind_0 == 6);}
  else {
    X60Qx_1435 = NIM_FALSE;}
  if (X60Qx_1435){
    Value_0_valzr1t4f* X60Qx_1437 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    X60Qx_1434 = ((*X60Qx_1437).kind_0 == 6);}
  else {
    X60Qx_1434 = NIM_FALSE;}
  if (X60Qx_1434){
    Value_0_valzr1t4f* X60Qx_1438 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    NI32 fd_11 = hostOpenC_0_hos5i19e11(sink_13, (*X60Qx_1438).sval_0, (string_0_sysvq0asl){
      .bytes_0 = 6452994u, .more_0 = NIM_NIL}
    );
    if (0 <= fd_11){
      Value_0_valzr1t4f* X60Qx_1439 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f* X60Qx_1440 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      NI32 X60Qx_1441 = len_4_sysvq0asl((*X60Qx_1440).sval_0);
      NI32 X60Qx_1442 = hostWrite_0_hos5i19e11(sink_13, fd_11, (*X60Qx_1439).sval_0, X60Qx_1441);
      NI32 X60Qx_1443 = hostClose_0_hos5i19e11(sink_13, fd_11);}
    else {
      writeStr_0_natd5co251(sink_13, NIM_TRUE, (string_0_sysvq0asl){
        .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I15923132267043663999_runot4689)}
      );
      Value_0_valzr1t4f* X60Qx_1444 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      writeStr_0_natd5co251(sink_13, NIM_TRUE, (*X60Qx_1444).sval_0);
      writeStr_0_natd5co251(sink_13, NIM_TRUE, (string_0_sysvq0asl){
        .bytes_0 = 665346u, .more_0 = NIM_NIL}
      );}}
  goto X60Qsc_441;
  X60Qsc_229: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1445 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_160 = (*X60Qx_1445);
    string_0_sysvq0asl X60Qtmp_202 = ptrToString_0_runot4689((&X60QconstRefTemp_160));
    Value_0_valzr1t4f* X60Qx_1446 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_161 = (*X60Qx_1446);
    string_0_sysvq0asl X60Qtmp_203 = ptrToString_0_runot4689((&X60QconstRefTemp_161));
    envPut_0_natd5co251(sink_13, X60Qtmp_202, X60Qtmp_203);
    nimStrDestroy(X60Qtmp_203);
    nimStrDestroy(X60Qtmp_202);}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1447 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_76 = X60Qx_1447;
  goto X60Qsc_441;
  X60Qsc_230: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1448 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_162 = (*X60Qx_1448);
    string_0_sysvq0asl kv_0 = ptrToString_0_runot4689((&X60QconstRefTemp_162));
    NI32 eq_0 = -1;
    NI32 i_48 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1449 = len_4_sysvq0asl(kv_0);
        if (i_48 < X60Qx_1449){
          NC8 X60Qx_1450 = getQ_9_sysvq0asl(kv_0, i_48);
          if (X60Qx_1450 == (NC8)'='){
            eq_0 = i_48;
            goto whileStmtLabel_14;}
          inc_1_I6wjjge_aow2h993l1((&i_48));}
        else {
          break;}}}
    whileStmtLabel_14: ;
    if (0 <= eq_0){
      string_0_sysvq0asl X60Qtmp_204 = substr_0_sysvq0asl(kv_0, 0, ((NI32)(eq_0 - 1)));
      NI32 X60Qx_1451 = len_4_sysvq0asl(kv_0);
      string_0_sysvq0asl X60Qtmp_205 = substr_0_sysvq0asl(kv_0, ((NI32)(eq_0 + 1)), ((NI32)(X60Qx_1451 - 1)));
      envPut_0_natd5co251(sink_13, X60Qtmp_204, X60Qtmp_205);
      nimStrDestroy(X60Qtmp_205);
      nimStrDestroy(X60Qtmp_204);}
    nimStrDestroy(kv_0);}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1452 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_76 = X60Qx_1452;
  goto X60Qsc_441;
  X60Qsc_231: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1453 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_163 = (*X60Qx_1453);
    string_0_sysvq0asl X60Qtmp_206 = ptrToString_0_runot4689((&X60QconstRefTemp_163));
    Value_0_valzr1t4f* X60Qx_1454 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_164 = (*X60Qx_1454);
    string_0_sysvq0asl X60Qtmp_207 = ptrToString_0_runot4689((&X60QconstRefTemp_164));
    envPut_0_natd5co251(sink_13, X60Qtmp_206, X60Qtmp_207);
    nimStrDestroy(X60Qtmp_207);
    nimStrDestroy(X60Qtmp_206);}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1455 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_76 = X60Qx_1455;
  goto X60Qsc_441;
  X60Qsc_232: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1456 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_165 = (*X60Qx_1456);
    string_0_sysvq0asl X60Qtmp_208 = ptrToString_0_runot4689((&X60QconstRefTemp_165));
    envDel_0_natd5co251(sink_13, X60Qtmp_208);
    nimStrDestroy(X60Qtmp_208);}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1457 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_76 = X60Qx_1457;
  goto X60Qsc_441;
  X60Qsc_233: ;
  NB8 X60Qx_1458 = journalReplaying_0_jou8favxh1();
  if (X60Qx_1458){
    string_0_sysvq0asl X60Qx_52;
    nimStrWasMoved((&X60Qx_52));
    NB8 X60Qx_1459;
    if (1 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1460 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      X60Qx_1459 = ((*X60Qx_1460).kind_0 == 6);}
    else {
      X60Qx_1459 = NIM_FALSE;}
    if (X60Qx_1459){
      nimStrDestroy(X60Qx_52);
      Value_0_valzr1t4f* X60Qx_1461 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      string_0_sysvq0asl X60Qx_1462 = nimStrDup((*X60Qx_1461).sval_0);
      X60Qx_52 = X60Qx_1462;}
    else {
      nimStrDestroy(X60Qx_52);
      X60Qx_52 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl p_4 = X60Qx_52;
    nimStrWasMoved((&X60Qx_52));
    string_0_sysvq0asl X60Qtmp_209 = portPath_0_jou8favxh1(p_4);
    seq_0_Ixdx2fh1_aow7lb5cq1 a_11 = jServe_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I13890055370861586915_runot4689)}
    , X60Qtmp_209);
    string_0_sysvq0asl X60Qtmp_210 = jField_0_jou8favxh1(a_11, 0);
    NB8 X60Qx_1463 = eqQ_20_sysvq0asl(X60Qtmp_210, (string_0_sysvq0asl){
      .bytes_0 = 12545u, .more_0 = NIM_NIL}
    );
    if (X60Qx_1463){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      string_0_sysvq0asl X60Qtmp_211 = jField_0_jou8favxh1(a_11, 1);
      Value_0_valzr1t4f X60Qx_1464 = vStr_0_valzr1t4f(X60Qtmp_211);
      result_76 = X60Qx_1464;
      nimStrDestroy(X60Qtmp_211);}
    else {
      writeStr_0_natd5co251(sink_13, NIM_TRUE, (string_0_sysvq0asl){
        .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I1043492540097414730_runot4689)}
      );
      writeStr_0_natd5co251(sink_13, NIM_TRUE, p_4);
      writeStr_0_natd5co251(sink_13, NIM_TRUE, (string_0_sysvq0asl){
        .bytes_0 = 665346u, .more_0 = NIM_NIL}
      );
      noteFailedRead_0_natd5co251(sink_13, p_4);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1465 = vStr_0_valzr1t4f((string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      );
      result_76 = X60Qx_1465;}
    nimStrDestroy(X60Qtmp_210);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(a_11);
    nimStrDestroy(X60Qtmp_209);
    nimStrDestroy(p_4);
    nimStrDestroy(X60Qx_52);}
  else {
    NB8 X60Qx_1466;
    if (1 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1467 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      X60Qx_1466 = ((*X60Qx_1467).kind_0 == 6);}
    else {
      X60Qx_1466 = NIM_FALSE;}
    if (X60Qx_1466){
      FILE* f_7;
      Value_0_valzr1t4f* X60Qx_1468 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      NB8 opened_0 = open_0_syn1lfpjv((&f_7), (*X60Qx_1468).sval_0, 0, -1);
      if ((!opened_0)){
        Value_0_valzr1t4f* X60Qx_1469 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        string_0_sysvq0asl alt_0 = resolvedReadPath_0_natd5co251((*X60Qx_1469).sval_0);
        NI32 X60Qx_1470 = len_4_sysvq0asl(alt_0);
        if (0 < X60Qx_1470){
          NB8 X60Qx_1471 = open_0_syn1lfpjv((&f_7), alt_0, 0, -1);
          opened_0 = X60Qx_1471;}
        nimStrDestroy(alt_0);}
      if (opened_0){
        string_0_sysvq0asl acc_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;
        X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 buf_2 = default_23_Isnz07p_hos5i19e11();
        {
          while (NIM_TRUE){
            NI32 X60Qx_1472 = nimIcheckB(0, 65535);
            NI32 n_14 = readBuffer_0_syn1lfpjv(f_7, ((void*)(&buf_2.a[X60Qx_1472])), ((NI32)(((NI32)(((NI32)((NI32)65535)) - ((NI32)((NI32)0)))) + 1)));
            if (n_14 <= 0){
              goto whileStmtLabel_15;}
            NI32 i_49 = 0;
            {
              while (i_49 < n_14){
                NI32 X60Qx_1473 = nimIcheckB(i_49, 65535);
                add_1_sysvq0asl((&acc_0), buf_2.a[X60Qx_1473]);
                inc_1_I6wjjge_aow2h993l1((&i_49));}}
            whileStmtLabel_16: ;}}
        whileStmtLabel_15: ;
        close_0_syn1lfpjv(f_7);
        NB8 X60Qx_1474 = readAuditOn_0_iop7yt73v();
        if (X60Qx_1474){
          Value_0_valzr1t4f* X60Qx_1475 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
          recordRead_0_iop7yt73v((*X60Qx_1475).sval_0, acc_0);}
        NB8 X60Qx_1476 = journalRecording_0_jou8favxh1();
        if (X60Qx_1476){
          Value_0_valzr1t4f* X60Qx_1477 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
          string_0_sysvq0asl X60Qtmp_212 = portPath_0_jou8favxh1((*X60Qx_1477).sval_0);
          seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_213 = atQ_0_Ibamkxv1_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
            .a = {
              (string_0_sysvq0asl){
                .bytes_0 = 12545u, .more_0 = NIM_NIL}
              , acc_0}}
          );
          jRecord_0_jou8favxh1((string_0_sysvq0asl){
            .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I13890055370861586915_runot4689)}
          , X60Qtmp_212, X60Qtmp_213);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_213);
          nimStrDestroy(X60Qtmp_212);}
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1478 = vStr_0_valzr1t4f(acc_0);
        result_76 = X60Qx_1478;
        nimStrDestroy(acc_0);}
      else {
        writeStr_0_natd5co251(sink_13, NIM_TRUE, (string_0_sysvq0asl){
          .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I1043492540097414730_runot4689)}
        );
        Value_0_valzr1t4f* X60Qx_1479 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        writeStr_0_natd5co251(sink_13, NIM_TRUE, (*X60Qx_1479).sval_0);
        writeStr_0_natd5co251(sink_13, NIM_TRUE, (string_0_sysvq0asl){
          .bytes_0 = 665346u, .more_0 = NIM_NIL}
        );
        Value_0_valzr1t4f* X60Qx_1480 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        noteFailedRead_0_natd5co251(sink_13, (*X60Qx_1480).sval_0);
        NB8 X60Qx_1481 = journalRecording_0_jou8favxh1();
        if (X60Qx_1481){
          Value_0_valzr1t4f* X60Qx_1482 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
          string_0_sysvq0asl X60Qtmp_214 = portPath_0_jou8favxh1((*X60Qx_1482).sval_0);
          seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_215 = atQ_0_Ibamkxv1_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
            .a = {
              (string_0_sysvq0asl){
                .bytes_0 = 12289u, .more_0 = NIM_NIL}
              , (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}}}
          );
          jRecord_0_jou8favxh1((string_0_sysvq0asl){
            .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I13890055370861586915_runot4689)}
          , X60Qtmp_214, X60Qtmp_215);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_215);
          nimStrDestroy(X60Qtmp_214);}
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1483 = vStr_0_valzr1t4f((string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        );
        result_76 = X60Qx_1483;}}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1484 = vStr_0_valzr1t4f((string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      );
      result_76 = X60Qx_1484;}}
  goto X60Qsc_441;
  X60Qsc_234: ;
  NB8 X60Qx_1485;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1486 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_166 = (*X60Qx_1486);
    NI32 X60Qx_1487 = fdOfValue_0_runot4689((&X60QconstRefTemp_166));
    NB8 X60Qx_1488 = isHostFd_0_hos5i19e11(sink_13, X60Qx_1487);
    X60Qx_1485 = X60Qx_1488;}
  else {
    X60Qx_1485 = NIM_FALSE;}
  if (X60Qx_1485){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1489 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_167 = (*X60Qx_1489);
    NI32 X60Qx_1490 = fdOfValue_0_runot4689((&X60QconstRefTemp_167));
    string_0_sysvq0asl X60Qtmp_216 = hostReadAll_0_hos5i19e11(sink_13, X60Qx_1490);
    Value_0_valzr1t4f X60Qx_1491 = vStr_0_valzr1t4f(X60Qtmp_216);
    result_76 = X60Qx_1491;
    nimStrDestroy(X60Qtmp_216);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    string_0_sysvq0asl X60Qtmp_217 = readAllFrom_0_natd5co251(sink_13);
    Value_0_valzr1t4f X60Qx_1492 = vStr_0_valzr1t4f(X60Qtmp_217);
    result_76 = X60Qx_1492;
    nimStrDestroy(X60Qtmp_217);}
  goto X60Qsc_441;
  X60Qsc_235: ;
  NB8 X60Qx_1493;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1494 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_168 = (*X60Qx_1494);
    NI32 X60Qx_1495 = fdOfValue_0_runot4689((&X60QconstRefTemp_168));
    NB8 X60Qx_1496 = isHostFd_0_hos5i19e11(sink_13, X60Qx_1495);
    X60Qx_1493 = X60Qx_1496;}
  else {
    X60Qx_1493 = NIM_FALSE;}
  if (X60Qx_1493){
    Value_0_valzr1t4f* X60Qx_1497 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_169 = (*X60Qx_1497);
    NI32 X60Qx_1498 = fdOfValue_0_runot4689((&X60QconstRefTemp_169));
    string_0_sysvq0asl b_13 = hostRead_0_hos5i19e11(sink_13, X60Qx_1498, 1);
    NI64 X60Qx_53;
    NI32 X60Qx_1499 = len_4_sysvq0asl(b_13);
    if (X60Qx_1499 == 0){
      X60Qx_53 = ((NI64)-1);}
    else {
      NC8 X60Qx_1500 = getQ_9_sysvq0asl(b_13, 0);
      X60Qx_53 = ((NI64)((NU8)X60Qx_1500));}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1501 = vInt_0_valzr1t4f(X60Qx_53, 64);
    result_76 = X60Qx_1501;
    nimStrDestroy(b_13);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    NI32 X60Qx_1502 = readCharFrom_0_natd5co251(sink_13);
    Value_0_valzr1t4f X60Qx_1503 = vInt_0_valzr1t4f(((NI64)X60Qx_1502), 64);
    result_76 = X60Qx_1503;}
  goto X60Qsc_441;
  X60Qsc_236: ;
  NB8 X60Qx_1504;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1505 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_170 = (*X60Qx_1505);
    NI32 X60Qx_1506 = fdOfValue_0_runot4689((&X60QconstRefTemp_170));
    NB8 X60Qx_1507 = isHostFd_0_hos5i19e11(sink_13, X60Qx_1506);
    X60Qx_1504 = X60Qx_1507;}
  else {
    X60Qx_1504 = NIM_FALSE;}
  if (X60Qx_1504){
    Value_0_valzr1t4f* X60Qx_1508 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_171 = (*X60Qx_1508);
    NI32 X60Qx_1509 = fdOfValue_0_runot4689((&X60QconstRefTemp_171));
    string_0_sysvq0asl b_14 = hostRead_0_hos5i19e11(sink_13, X60Qx_1509, 1);
    NC8 X60Qx_54;
    NI32 X60Qx_1510 = len_4_sysvq0asl(b_14);
    if (X60Qx_1510 == 0){
      X60Qx_54 = (NC8)'\000';}
    else {
      NC8 X60Qx_1511 = getQ_9_sysvq0asl(b_14, 0);
      X60Qx_54 = X60Qx_1511;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1512 = vChar_0_valzr1t4f(X60Qx_54);
    result_76 = X60Qx_1512;
    nimStrDestroy(b_14);}
  else {
    NI32 c_26 = readCharFrom_0_natd5co251(sink_13);
    NC8 X60Qx_55;
    if (c_26 < 0){
      X60Qx_55 = (NC8)'\000';}
    else {
      X60Qx_55 = ((NC8)c_26);}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1513 = vChar_0_valzr1t4f(X60Qx_55);
    result_76 = X60Qx_1513;}
  goto X60Qsc_441;
  X60Qsc_237: ;
  seq_0_Iw8xl5b1_arecyyj7v elems_0 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  {
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_218 = commandLineParamsFrom_0_natd5co251(sink_13);
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_6 = toOpenArray_1_I6b60gk1_aow7lb5cq1(X60Qtmp_218);
    NI32 X60Qlf_7 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1514 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_6);
        if (X60Qlf_7 < X60Qx_1514){
          {
            string_0_sysvq0asl* X60Qii_19 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_6, X60Qlf_7);
            Value_0_valzr1t4f X60Qtmp_219 = vStr_0_valzr1t4f((*X60Qii_19));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1515 = newCell_0_valzr1t4f((&X60Qtmp_219));
            add_0_Ijpw0mu_flaksyopx1((&elems_0), X60Qx_1515);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_219));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
        else {
          break;}}}
    whileStmtLabel_18: ;
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_218);}
  forStmtLabel_17: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  void* X60Qx_1516 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_220 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1516);
  seq_0_Iw8xl5b1_arecyyj7v X60Qtmp_221 = elems_0;
  eQwasMoved_1_I4kgdoh1_arecyyj7v((&elems_0));
  (*X60Qtmp_220) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
      .elems_0 = X60Qtmp_221, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
  ;
  result_76 = (Value_0_valzr1t4f){
    .kind_0 = 8, .sq_0 = X60Qtmp_220}
  ;
  eQdestroy_1_I8k3d0z1_arecyyj7v(elems_0);
  goto X60Qsc_441;
  X60Qsc_238: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  NI32 X60Qx_1517 = paramCountFrom_0_natd5co251(sink_13);
  Value_0_valzr1t4f X60Qx_1518 = vInt_0_valzr1t4f(((NI64)X60Qx_1517), 64);
  result_76 = X60Qx_1518;
  goto X60Qsc_441;
  X60Qsc_239: ;
  if (1 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1519 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_172 = (*X60Qx_1519);
    NI64 X60Qx_1520 = asInt_0_valzr1t4f((&X60QconstRefTemp_172));
    string_0_sysvq0asl X60Qtmp_222 = paramStrFrom_0_natd5co251(sink_13, ((NI32)X60Qx_1520));
    Value_0_valzr1t4f X60Qx_1521 = vStr_0_valzr1t4f(X60Qtmp_222);
    result_76 = X60Qx_1521;
    nimStrDestroy(X60Qtmp_222);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1522 = vStr_0_valzr1t4f((string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    result_76 = X60Qx_1522;}
  goto X60Qsc_441;
  X60Qsc_240: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1523 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    switch ((*X60Qx_1523).kind_0){
      case 6:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f* X60Qx_1524 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        NI32 X60Qx_1525 = len_4_sysvq0asl((*X60Qx_1524).sval_0);
        Value_0_valzr1t4f X60Qx_1526 = vInt_0_valzr1t4f(((NI64)X60Qx_1525), 64);
        result_76 = X60Qx_1526;}
      break;
      case 8:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f* X60Qx_1527 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        NI32 X60Qx_1528 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1527).sq_0).d_00.elems_0);
        Value_0_valzr1t4f X60Qx_1529 = vInt_0_valzr1t4f(((NI64)X60Qx_1528), 64);
        result_76 = X60Qx_1529;}
      break;
      case 9:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f* X60Qx_1530 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        NI32 X60Qx_1531 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1530).arr_0).d_00.elems_0);
        Value_0_valzr1t4f X60Qx_1532 = vInt_0_valzr1t4f(((NI64)X60Qx_1531), 64);
        result_76 = X60Qx_1532;}
      break;
      case 13:
      {
        Value_0_valzr1t4f* X60Qx_1533 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        Value_0_valzr1t4f X60QconstRefTemp_173 = (*X60Qx_1533);
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_223 = region_0_valzr1t4f((&X60QconstRefTemp_173));
        if ((!(X60Qtmp_223 == NIM_NIL))){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
          Value_0_valzr1t4f* X60Qx_1534 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
          Value_0_valzr1t4f X60QconstRefTemp_174 = (*X60Qx_1534);
          string_0_sysvq0asl X60Qtmp_224 = ptrToString_0_runot4689((&X60QconstRefTemp_174));
          NI32 X60Qx_1535 = len_4_sysvq0asl(X60Qtmp_224);
          Value_0_valzr1t4f X60Qx_1536 = vInt_0_valzr1t4f(((NI64)X60Qx_1535), 64);
          result_76 = X60Qx_1536;
          nimStrDestroy(X60Qtmp_224);}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
          Value_0_valzr1t4f X60Qx_1537 = vInt_0_valzr1t4f(((NI64)0), 64);
          result_76 = X60Qx_1537;}
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qtmp_223);}
      break;
      default:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1538 = vInt_0_valzr1t4f(((NI64)0), 64);
        result_76 = X60Qx_1538;}
      break;}}
  goto X60Qsc_441;
  X60Qsc_241: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1539 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    switch ((*X60Qx_1539).kind_0){
      case 6:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f* X60Qx_1540 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        NI32 X60Qx_1541 = len_4_sysvq0asl((*X60Qx_1540).sval_0);
        Value_0_valzr1t4f X60Qx_1542 = vInt_0_valzr1t4f(((NI64)(((NI64)X60Qx_1541) - ((NI64)1))), 64);
        result_76 = X60Qx_1542;}
      break;
      case 8:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f* X60Qx_1543 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        NI32 X60Qx_1544 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1543).sq_0).d_00.elems_0);
        Value_0_valzr1t4f X60Qx_1545 = vInt_0_valzr1t4f(((NI64)(((NI64)X60Qx_1544) - ((NI64)1))), 64);
        result_76 = X60Qx_1545;}
      break;
      case 9:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f* X60Qx_1546 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        NI32 X60Qx_1547 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1546).arr_0).d_00.elems_0);
        Value_0_valzr1t4f X60Qx_1548 = vInt_0_valzr1t4f(((NI64)(((NI64)X60Qx_1547) - ((NI64)1))), 64);
        result_76 = X60Qx_1548;}
      break;
      default:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1549 = vInt_0_valzr1t4f(((NI64)-1), 64);
        result_76 = X60Qx_1549;}
      break;}}
  goto X60Qsc_441;
  X60Qsc_242: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1550 = vInt_0_valzr1t4f(((NI64)0), 64);
  result_76 = X60Qx_1550;
  goto X60Qsc_441;
  X60Qsc_243: ;
  NB8 X60Qx_1551;
  if (2 <= args_4.len_0){
    openArray_0_I2902h9_intzsnzax X60Qx_1552 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
    NB8 X60Qx_1553 = nilContainerRecv_0_runot4689(X60Qx_1552);
    X60Qx_1551 = X60Qx_1553;}
  else {
    X60Qx_1551 = NIM_FALSE;}
  if (X60Qx_1551){
    failNilContainerOp_0_runot4689(sink_13, (string_0_sysvq0asl){
      .bytes_0 = 1684300035u, .more_0 = NIM_NIL}
    );}
  else {
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1554 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_175 = (*X60Qx_1554);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_5 = ptrCell_0_runot4689((&X60QconstRefTemp_175));
      if ((!(cell_5 == NIM_NIL))){
        if ((*cell_5).d_00.v_0.kind_0 == 8){
          Value_0_valzr1t4f* X60Qx_1555 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          Value_0_valzr1t4f X60QconstRefTemp_176 = (*X60Qx_1555);
          Value_0_valzr1t4f X60Qtmp_225 = copyOnAssign_0_valzr1t4f((&X60QconstRefTemp_176));
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1556 = newCell_0_valzr1t4f((&X60Qtmp_225));
          add_0_Ijpw0mu_flaksyopx1((&(*(*cell_5).d_00.v_0.sq_0).d_00.elems_0), X60Qx_1556);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_225));}
        else {
          if ((*cell_5).d_00.v_0.kind_0 == 6){
            Value_0_valzr1t4f* X60Qx_1557 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
            if ((*X60Qx_1557).kind_0 == 5){
              Value_0_valzr1t4f* X60Qx_1558 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
              add_1_sysvq0asl((&(*cell_5).d_00.v_0.sval_0), (*X60Qx_1558).cval_0);}
            else {
              Value_0_valzr1t4f* X60Qx_1559 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
              if ((*X60Qx_1559).kind_0 == 6){
                Value_0_valzr1t4f* X60Qx_1560 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
                add_2_sysvq0asl((&(*cell_5).d_00.v_0.sval_0), (*X60Qx_1560).sval_0);}
              else {
                NB8 X60Qx_1561;
                Value_0_valzr1t4f* X60Qx_1562 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
                if ((*X60Qx_1562).kind_0 == 1){
                  X60Qx_1561 = NIM_TRUE;}
                else {
                  Value_0_valzr1t4f* X60Qx_1563 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
                  X60Qx_1561 = ((*X60Qx_1563).kind_0 == 2);}
                if (X60Qx_1561){
                  Value_0_valzr1t4f* X60Qx_1564 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
                  Value_0_valzr1t4f X60QconstRefTemp_177 = (*X60Qx_1564);
                  NI64 X60Qx_1565 = asInt_0_valzr1t4f((&X60QconstRefTemp_177));
                  addRuneUtf8_0_runot4689((&(*cell_5).d_00.v_0.sval_0), X60Qx_1565);}}}}}}
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_5);}}
  goto X60Qsc_441;
  X60Qsc_244: ;
  NB8 X60Qx_1566;
  if (2 <= args_4.len_0){
    openArray_0_I2902h9_intzsnzax X60Qx_1567 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
    NB8 X60Qx_1568 = nilContainerRecv_0_runot4689(X60Qx_1567);
    X60Qx_1566 = X60Qx_1568;}
  else {
    X60Qx_1566 = NIM_FALSE;}
  if (X60Qx_1566){
    failNilContainerOp_0_runot4689(sink_13, (string_0_sysvq0asl){
      .bytes_0 = 6118146u, .more_0 = NIM_NIL}
    );}
  else {
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1569 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_178 = (*X60Qx_1569);
      Value_0_valzr1t4f recv_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_178));
      NB8 X60Qx_1570;
      NB8 X60Qx_1571;
      NB8 X60Qx_1572;
      Value_0_valzr1t4f* X60Qx_1573 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      if ((*X60Qx_1573).kind_0 == 11){
        X60Qx_1572 = NIM_TRUE;}
      else {
        Value_0_valzr1t4f* X60Qx_1574 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        X60Qx_1572 = ((*X60Qx_1574).kind_0 == 10);}
      if (X60Qx_1572){
        Value_0_valzr1t4f* X60Qx_1575 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        X60Qx_1571 = (!((*X60Qx_1575).obj_0 == NIM_NIL));}
      else {
        X60Qx_1571 = NIM_FALSE;}
      if (X60Qx_1571){
        Value_0_valzr1t4f* X60Qx_1576 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        X60Qx_1570 = (2 <= (*(*X60Qx_1576).obj_0).d_00.cells_0.len_0);}
      else {
        X60Qx_1570 = NIM_FALSE;}
      if (X60Qx_1570){
        Value_0_valzr1t4f* X60Qx_1577 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1578 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1577).obj_0).d_00.cells_0, 0);
        NI64 X60Qx_1579 = asInt_0_valzr1t4f((&(*(*X60Qx_1578)).d_00.v_0));
        NI32 lo_1 = ((NI32)X60Qx_1579);
        Value_0_valzr1t4f* X60Qx_1580 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1581 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1580).obj_0).d_00.cells_0, 1);
        NI64 X60Qx_1582 = asInt_0_valzr1t4f((&(*(*X60Qx_1581)).d_00.v_0));
        NI32 hi_1 = ((NI32)X60Qx_1582);
        Value_0_valzr1t4f* X60Qx_1583 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        NB8 X60Qx_1584 = sliceHiIsBackwards_0_runot4689((*(*X60Qx_1583).obj_0).d_00.typeSym_0);
        if (X60Qx_1584){
          NI32 n_15 = 0;
          if (recv_0.kind_0 == 6){
            NI32 X60Qx_1585 = len_4_sysvq0asl(recv_0.sval_0);
            n_15 = X60Qx_1585;}
          else {
            NB8 X60Qx_1586;
            if (recv_0.kind_0 == 8){
              X60Qx_1586 = (!(recv_0.sq_0 == NIM_NIL));}
            else {
              X60Qx_1586 = NIM_FALSE;}
            if (X60Qx_1586){
              NI32 X60Qx_1587 = len_3_I83dzei_arecyyj7v((*recv_0.sq_0).d_00.elems_0);
              n_15 = X60Qx_1587;}
            else {
              NB8 X60Qx_1588;
              if (recv_0.kind_0 == 9){
                X60Qx_1588 = (!(recv_0.arr_0 == NIM_NIL));}
              else {
                X60Qx_1588 = NIM_FALSE;}
              if (X60Qx_1588){
                NI32 X60Qx_1589 = len_3_I83dzei_arecyyj7v((*recv_0.arr_0).d_00.elems_0);
                n_15 = X60Qx_1589;}}}
          hi_1 = ((NI32)(n_15 - hi_1));
          NB8 X60Qx_1590;
          if (recv_0.kind_0 == 9){
            X60Qx_1590 = (!(recv_0.arr_0 == NIM_NIL));}
          else {
            X60Qx_1590 = NIM_FALSE;}
          if (X60Qx_1590){
            hi_1 = ((NI32)(hi_1 + (*recv_0.arr_0).d_00.lo_0));}}
        switch (recv_0.kind_0){
          case 6:
          {
            NI32 m_1 = len_4_sysvq0asl(recv_0.sval_0);
            if (lo_1 < 0){
              lo_1 = 0;}
            if (m_1 <= hi_1){
              hi_1 = ((NI32)(m_1 - 1));}
            Value_0_valzr1t4f X60Qx_56;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_56));
            if (lo_1 <= hi_1){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_56));
              string_0_sysvq0asl X60Qtmp_226 = substr_0_sysvq0asl(recv_0.sval_0, lo_1, hi_1);
              Value_0_valzr1t4f X60Qx_1591 = vStr_0_valzr1t4f(X60Qtmp_226);
              X60Qx_56 = X60Qx_1591;
              nimStrDestroy(X60Qtmp_226);}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_56));
              Value_0_valzr1t4f X60Qx_1592 = vStr_0_valzr1t4f((string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              );
              X60Qx_56 = X60Qx_1592;}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
            result_76 = X60Qx_56;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_56));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_56));}
          break;
          case 8:
          {
            void* X60Qx_1593 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
            X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_227 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1593);
            seq_0_Iw8xl5b1_arecyyj7v X60Qx_1594 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
            (*X60Qtmp_227) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
              .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
                .elems_0 = X60Qx_1594, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
            ;
            X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_5 = X60Qtmp_227;
            if ((!(recv_0.sq_0 == NIM_NIL))){
              NI32 m_2 = len_3_I83dzei_arecyyj7v((*recv_0.sq_0).d_00.elems_0);
              if (lo_1 < 0){
                lo_1 = 0;}
              if (m_2 <= hi_1){
                hi_1 = ((NI32)(m_2 - 1));}
              NI32 k_7 = lo_1;
              {
                while (k_7 <= hi_1){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1595 = getQ_7_Ii14ync1_arecyyj7v((*recv_0.sq_0).d_00.elems_0, k_7);
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1596 = newCell_0_valzr1t4f((&(*(*X60Qx_1595)).d_00.v_0));
                  add_0_Ijpw0mu_flaksyopx1((&(*sb_5).d_00.elems_0), X60Qx_1596);
                  inc_1_I6wjjge_aow2h993l1((&k_7));}}
              whileStmtLabel_20: ;}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
            X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_228 = sb_5;
            eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689((&sb_5));
            result_76 = (Value_0_valzr1t4f){
              .kind_0 = 8, .sq_0 = X60Qtmp_228}
            ;
            eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb_5);}
          break;
          case 9:
          {
            void* X60Qx_1597 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
            X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_229 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1597);
            seq_0_Iw8xl5b1_arecyyj7v X60Qx_1598 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
            (*X60Qtmp_229) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
              .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
                .elems_0 = X60Qx_1598, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
            ;
            X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_6 = X60Qtmp_229;
            if ((!(recv_0.arr_0 == NIM_NIL))){
              NI32 m_3 = len_3_I83dzei_arecyyj7v((*recv_0.arr_0).d_00.elems_0);
              NI32 a2_0 = ((NI32)(lo_1 - (*recv_0.arr_0).d_00.lo_0));
              NI32 b2_0 = ((NI32)(hi_1 - (*recv_0.arr_0).d_00.lo_0));
              if (a2_0 < 0){
                a2_0 = 0;}
              if (m_3 <= b2_0){
                b2_0 = ((NI32)(m_3 - 1));}
              NI32 k_8 = a2_0;
              {
                while (k_8 <= b2_0){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1599 = getQ_7_Ii14ync1_arecyyj7v((*recv_0.arr_0).d_00.elems_0, k_8);
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1600 = newCell_0_valzr1t4f((&(*(*X60Qx_1599)).d_00.v_0));
                  add_0_Ijpw0mu_flaksyopx1((&(*sb_6).d_00.elems_0), X60Qx_1600);
                  inc_1_I6wjjge_aow2h993l1((&k_8));}}
              whileStmtLabel_21: ;}
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
            X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_230 = sb_6;
            eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689((&sb_6));
            result_76 = (Value_0_valzr1t4f){
              .kind_0 = 8, .sq_0 = X60Qtmp_230}
            ;
            eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb_6);}
          break;
          default:
          {
            }
          break;}}
      else {
        Value_0_valzr1t4f* X60Qx_1601 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_179 = (*X60Qx_1601);
        NI64 X60Qx_1602 = asInt_0_valzr1t4f((&X60QconstRefTemp_179));
        NI32 i_50 = ((NI32)X60Qx_1602);
        switch (recv_0.kind_0){
          case 8:
          {
            NB8 X60Qx_1603;
            if (0 <= i_50){
              NI32 X60Qx_1604 = len_3_I83dzei_arecyyj7v((*recv_0.sq_0).d_00.elems_0);
              X60Qx_1603 = (i_50 < X60Qx_1604);}
            else {
              X60Qx_1603 = NIM_FALSE;}
            if (X60Qx_1603){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1605 = getQ_7_Ii14ync1_arecyyj7v((*recv_0.sq_0).d_00.elems_0, i_50);
              Value_0_valzr1t4f X60Qx_1606 = vPtrArr_0_valzr1t4f((*X60Qx_1605), ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), recv_0.sq_0, i_50);
              result_76 = X60Qx_1606;}}
          break;
          case 6:
          {
            NB8 X60Qx_1607;
            if (0 <= i_50){
              NI32 X60Qx_1608 = len_4_sysvq0asl(recv_0.sval_0);
              X60Qx_1607 = (i_50 < X60Qx_1608);}
            else {
              X60Qx_1607 = NIM_FALSE;}
            if (X60Qx_1607){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
              NC8 X60Qx_1609 = getQ_9_sysvq0asl(recv_0.sval_0, i_50);
              Value_0_valzr1t4f X60Qx_1610 = vChar_0_valzr1t4f(X60Qx_1609);
              result_76 = X60Qx_1610;}}
          break;
          case 9:
          {
            NB8 X60Qx_1611;
            if (0 <= i_50){
              NI32 X60Qx_1612 = len_3_I83dzei_arecyyj7v((*recv_0.arr_0).d_00.elems_0);
              X60Qx_1611 = (i_50 < X60Qx_1612);}
            else {
              X60Qx_1611 = NIM_FALSE;}
            if (X60Qx_1611){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1613 = getQ_7_Ii14ync1_arecyyj7v((*recv_0.arr_0).d_00.elems_0, i_50);
              Value_0_valzr1t4f X60Qx_1614 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_1613)).d_00.v_0));
              result_76 = X60Qx_1614;}}
          break;
          default:
          {
            }
          break;}}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&recv_0));}}
  goto X60Qsc_441;
  X60Qsc_245: ;
  if (3 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1615 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_180 = (*X60Qx_1615);
    NI64 X60Qx_1616 = asInt_0_valzr1t4f((&X60QconstRefTemp_180));
    NI32 i_51 = ((NI32)X60Qx_1616);
    Value_0_valzr1t4f* X60Qx_1617 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_181 = (*X60Qx_1617);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_6 = ptrCell_0_runot4689((&X60QconstRefTemp_181));
    Value_0_valzr1t4f X60Qx_57;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_57));
    if ((!(cell_6 == NIM_NIL))){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_57));
      Value_0_valzr1t4f X60Qx_1618 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cell_6).d_00.v_0));
      X60Qx_57 = X60Qx_1618;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_57));
      Value_0_valzr1t4f* X60Qx_1619 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_182 = (*X60Qx_1619);
      Value_0_valzr1t4f X60Qx_1620 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_182));
      X60Qx_57 = X60Qx_1620;}
    Value_0_valzr1t4f target_4 = X60Qx_57;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_57));
    switch (target_4.kind_0){
      case 8:
      {
        NB8 X60Qx_1621;
        NB8 X60Qx_1622;
        if ((!(target_4.sq_0 == NIM_NIL))){
          X60Qx_1622 = (0 <= i_51);}
        else {
          X60Qx_1622 = NIM_FALSE;}
        if (X60Qx_1622){
          NI32 X60Qx_1623 = len_3_I83dzei_arecyyj7v((*target_4.sq_0).d_00.elems_0);
          X60Qx_1621 = (i_51 < X60Qx_1623);}
        else {
          X60Qx_1621 = NIM_FALSE;}
        if (X60Qx_1621){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1624 = getQ_7_Ii14ync1_arecyyj7v((*target_4.sq_0).d_00.elems_0, i_51);
          Value_0_valzr1t4f* X60Qlhs_231 = (&(*(*X60Qx_1624)).d_00.v_0);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1625 = getQ_7_Ii14ync1_arecyyj7v((*target_4.sq_0).d_00.elems_0, i_51);
          Value_0_valzr1t4f X60Qlhs_232 = (*(*X60Qx_1625)).d_00.v_0;
          Value_0_valzr1t4f* X60Qx_1626 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
          Value_0_valzr1t4f X60QconstRefTemp_183 = (*X60Qx_1626);
          Value_0_valzr1t4f X60Qx_1627 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_183));
          (*X60Qlhs_231) = X60Qx_1627;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_232));}}
      break;
      case 9:
      {
        if ((!(target_4.arr_0 == NIM_NIL))){
          NI32 ai_0 = ((NI32)(i_51 - (*target_4.arr_0).d_00.lo_0));
          NB8 X60Qx_1628;
          if (0 <= ai_0){
            NI32 X60Qx_1629 = len_3_I83dzei_arecyyj7v((*target_4.arr_0).d_00.elems_0);
            X60Qx_1628 = (ai_0 < X60Qx_1629);}
          else {
            X60Qx_1628 = NIM_FALSE;}
          if (X60Qx_1628){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1630 = getQ_7_Ii14ync1_arecyyj7v((*target_4.arr_0).d_00.elems_0, ai_0);
            Value_0_valzr1t4f* X60Qlhs_233 = (&(*(*X60Qx_1630)).d_00.v_0);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1631 = getQ_7_Ii14ync1_arecyyj7v((*target_4.arr_0).d_00.elems_0, ai_0);
            Value_0_valzr1t4f X60Qlhs_234 = (*(*X60Qx_1631)).d_00.v_0;
            Value_0_valzr1t4f* X60Qx_1632 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
            Value_0_valzr1t4f X60QconstRefTemp_184 = (*X60Qx_1632);
            Value_0_valzr1t4f X60Qx_1633 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_184));
            (*X60Qlhs_233) = X60Qx_1633;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_234));}}}
      break;
      case 14:
      {
        NB8 X60Qx_1634;
        if ((!(target_4.st_0 == NIM_NIL))){
          Value_0_valzr1t4f* X60Qx_1635 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
          X60Qx_1634 = ((*X60Qx_1635).kind_0 == 4);}
        else {
          X60Qx_1634 = NIM_FALSE;}
        if (X60Qx_1634){
          Value_0_valzr1t4f* X60Qx_1636 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
          if ((*X60Qx_1636).bval_0){
            Value_0_valzr1t4f* X60Qx_1637 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
            Value_0_valzr1t4f X60QconstRefTemp_185 = (*X60Qx_1637);
            NI64 X60Qx_1638 = asInt_0_valzr1t4f((&X60QconstRefTemp_185));
            setBit_0_runot4689(target_4.st_0, X60Qx_1638);}
          else {
            Value_0_valzr1t4f* X60Qx_1639 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
            Value_0_valzr1t4f X60QconstRefTemp_186 = (*X60Qx_1639);
            NI64 X60Qx_1640 = asInt_0_valzr1t4f((&X60QconstRefTemp_186));
            clearBit_0_runot4689(target_4.st_0, X60Qx_1640);}}}
      break;
      case 6:
      {
        NB8 X60Qx_1641;
        NB8 X60Qx_1642;
        NB8 X60Qx_1643;
        if ((!(cell_6 == NIM_NIL))){
          Value_0_valzr1t4f* X60Qx_1644 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
          X60Qx_1643 = ((*X60Qx_1644).kind_0 == 5);}
        else {
          X60Qx_1643 = NIM_FALSE;}
        if (X60Qx_1643){
          X60Qx_1642 = (0 <= i_51);}
        else {
          X60Qx_1642 = NIM_FALSE;}
        if (X60Qx_1642){
          NI32 X60Qx_1645 = len_4_sysvq0asl((*cell_6).d_00.v_0.sval_0);
          X60Qx_1641 = (i_51 < X60Qx_1645);}
        else {
          X60Qx_1641 = NIM_FALSE;}
        if (X60Qx_1641){
          Value_0_valzr1t4f* X60Qx_1646 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
          putQ_9_sysvq0asl((&(*cell_6).d_00.v_0.sval_0), i_51, (*X60Qx_1646).cval_0);}}
      break;
      case 0:
      {
        failNilIndex_0_runot4689(sink_13, (string_0_sysvq0asl){
          .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I16141550644421620305_runot4689)}
        );}
      break;
      default:
      {
        }
      break;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&target_4));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_57));
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_6);}
  goto X60Qsc_441;
  X60Qsc_246: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1647 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_187 = (*X60Qx_1647);
    Value_0_valzr1t4f X60Qtmp_235 = derefForText_0_runot4689((&X60QconstRefTemp_187));
    X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 a_13 = concatText_0_runot4689((&X60Qtmp_235));
    Value_0_valzr1t4f* X60Qx_1648 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_188 = (*X60Qx_1648);
    Value_0_valzr1t4f X60Qtmp_236 = derefForText_0_runot4689((&X60QconstRefTemp_188));
    X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 b_15 = concatText_0_runot4689((&X60Qtmp_236));
    NB8 X60Qx_1649;
    if (a_13.fld_1){
      X60Qx_1649 = b_15.fld_1;}
    else {
      X60Qx_1649 = NIM_FALSE;}
    if (X60Qx_1649){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      string_0_sysvq0asl X60Qtmp_237 = ampQ_0_sysvq0asl(a_13.fld_0, b_15.fld_0);
      Value_0_valzr1t4f X60Qx_1650 = vStr_0_valzr1t4f(X60Qtmp_237);
      result_76 = X60Qx_1650;
      nimStrDestroy(X60Qtmp_237);}
    else {
      failShape_0_runot4689(sink_13, (string_0_sysvq0asl){
        .bytes_0 = 9729u, .more_0 = NIM_NIL}
      , args_4);}
    eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_runot4689(b_15);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_236));
    eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_runot4689(a_13);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_235));}
  goto X60Qsc_441;
  X60Qsc_247: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1651 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    if ((*X60Qx_1651).kind_0 == 0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_1652 = vStr_0_valzr1t4f((string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      );
      result_76 = X60Qx_1652;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f* X60Qx_1653 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_189 = (*X60Qx_1653);
      string_0_sysvq0asl X60Qtmp_238 = dollarQ_0_valzr1t4f((&X60QconstRefTemp_189));
      Value_0_valzr1t4f X60Qx_1654 = vStr_0_valzr1t4f(X60Qtmp_238);
      result_76 = X60Qx_1654;
      nimStrDestroy(X60Qtmp_238);}}
  goto X60Qsc_441;
  X60Qsc_248: ;
  if (2 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1655 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_190 = (*X60Qx_1655);
    Value_0_valzr1t4f* X60Qx_1656 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_191 = (*X60Qx_1656);
    NB8 X60Qx_1657 = valueEquals_0_runot4689((&X60QconstRefTemp_190), (&X60QconstRefTemp_191));
    Value_0_valzr1t4f X60Qx_1658 = vBool_0_valzr1t4f(X60Qx_1657);
    result_76 = X60Qx_1658;}
  goto X60Qsc_441;
  X60Qsc_249: ;
  if (2 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1659 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_192 = (*X60Qx_1659);
    Value_0_valzr1t4f* X60Qx_1660 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_193 = (*X60Qx_1660);
    NI32 X60Qx_1661 = cmpValues_0_runot4689((&X60QconstRefTemp_192), (&X60QconstRefTemp_193));
    Value_0_valzr1t4f X60Qx_1662 = vInt_0_valzr1t4f(((NI64)X60Qx_1661), 64);
    result_76 = X60Qx_1662;}
  goto X60Qsc_441;
  X60Qsc_250: ;
  if (2 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1663 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_194 = (*X60Qx_1663);
    Value_0_valzr1t4f* X60Qx_1664 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_195 = (*X60Qx_1664);
    NI32 X60Qx_1665 = cmpValues_0_runot4689((&X60QconstRefTemp_194), (&X60QconstRefTemp_195));
    Value_0_valzr1t4f X60Qx_1666 = vBool_0_valzr1t4f((X60Qx_1665 < 0));
    result_76 = X60Qx_1666;}
  goto X60Qsc_441;
  X60Qsc_251: ;
  if (2 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1667 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_196 = (*X60Qx_1667);
    Value_0_valzr1t4f* X60Qx_1668 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_197 = (*X60Qx_1668);
    NI32 X60Qx_1669 = cmpValues_0_runot4689((&X60QconstRefTemp_196), (&X60QconstRefTemp_197));
    Value_0_valzr1t4f X60Qx_1670 = vBool_0_valzr1t4f((X60Qx_1669 <= 0));
    result_76 = X60Qx_1670;}
  goto X60Qsc_441;
  X60Qsc_252: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1671 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    switch ((*X60Qx_1671).kind_0){
      case 0:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        void* X60Qx_1672 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_239 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1672);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_1673 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        (*X60Qtmp_239) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
            .elems_0 = X60Qx_1673, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
        ;
        result_76 = (Value_0_valzr1t4f){
          .kind_0 = 8, .sq_0 = X60Qtmp_239}
        ;}
      break;
      case 9:
      {
        void* X60Qx_1674 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_240 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1674);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_1675 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        (*X60Qtmp_240) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
            .elems_0 = X60Qx_1675, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
        ;
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_7 = X60Qtmp_240;
        NI32 i_52 = 0;
        {
          while (NIM_TRUE){
            Value_0_valzr1t4f* X60Qx_1676 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
            NI32 X60Qx_1677 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1676).arr_0).d_00.elems_0);
            if (i_52 < X60Qx_1677){
              Value_0_valzr1t4f* X60Qx_1678 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1679 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1678).arr_0).d_00.elems_0, i_52);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1680 = newCell_0_valzr1t4f((&(*(*X60Qx_1679)).d_00.v_0));
              add_0_Ijpw0mu_flaksyopx1((&(*sb_7).d_00.elems_0), X60Qx_1680);
              inc_1_I6wjjge_aow2h993l1((&i_52));}
            else {
              break;}}}
        whileStmtLabel_22: ;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_241 = sb_7;
        eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689((&sb_7));
        result_76 = (Value_0_valzr1t4f){
          .kind_0 = 8, .sq_0 = X60Qtmp_241}
        ;
        eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb_7);}
      break;
      case 8:
      {
        void* X60Qx_1681 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_242 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1681);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_1682 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        (*X60Qtmp_242) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
            .elems_0 = X60Qx_1682, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
        ;
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_8 = X60Qtmp_242;
        Value_0_valzr1t4f* X60Qx_1683 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        if ((!((*X60Qx_1683).sq_0 == NIM_NIL))){
          NI32 i_53 = 0;
          {
            while (NIM_TRUE){
              Value_0_valzr1t4f* X60Qx_1684 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
              NI32 X60Qx_1685 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1684).sq_0).d_00.elems_0);
              if (i_53 < X60Qx_1685){
                Value_0_valzr1t4f* X60Qx_1686 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1687 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1686).sq_0).d_00.elems_0, i_53);
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1688 = newCell_0_valzr1t4f((&(*(*X60Qx_1687)).d_00.v_0));
                add_0_Ijpw0mu_flaksyopx1((&(*sb_8).d_00.elems_0), X60Qx_1688);
                inc_1_I6wjjge_aow2h993l1((&i_53));}
              else {
                break;}}}
          whileStmtLabel_23: ;}
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_243 = sb_8;
        eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689((&sb_8));
        result_76 = (Value_0_valzr1t4f){
          .kind_0 = 8, .sq_0 = X60Qtmp_243}
        ;
        eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb_8);}
      break;
      case 6:
      {
        void* X60Qx_1689 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_244 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1689);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_1690 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        (*X60Qtmp_244) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
            .elems_0 = X60Qx_1690, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
        ;
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_9 = X60Qtmp_244;
        NI32 i_54 = 0;
        {
          while (NIM_TRUE){
            Value_0_valzr1t4f* X60Qx_1691 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
            NI32 X60Qx_1692 = len_4_sysvq0asl((*X60Qx_1691).sval_0);
            if (i_54 < X60Qx_1692){
              Value_0_valzr1t4f* X60Qx_1693 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
              NC8 X60Qx_1694 = getQ_9_sysvq0asl((*X60Qx_1693).sval_0, i_54);
              Value_0_valzr1t4f X60Qtmp_245 = vChar_0_valzr1t4f(X60Qx_1694);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1695 = newCell_0_valzr1t4f((&X60Qtmp_245));
              add_0_Ijpw0mu_flaksyopx1((&(*sb_9).d_00.elems_0), X60Qx_1695);
              inc_1_I6wjjge_aow2h993l1((&i_54));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_245));}
            else {
              break;}}}
        whileStmtLabel_24: ;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_246 = sb_9;
        eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689((&sb_9));
        result_76 = (Value_0_valzr1t4f){
          .kind_0 = 8, .sq_0 = X60Qtmp_246}
        ;
        eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb_9);}
      break;
      default:
      {
        failShape_0_runot4689(sink_13, (string_0_sysvq0asl){
          .bytes_0 = 16385u, .more_0 = NIM_NIL}
        , args_4);}
      break;}}
  goto X60Qsc_441;
  X60Qsc_253: ;
  NB8 X60Qx_1696;
  NB8 X60Qx_1697 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
    .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I3225684998187034911_intzsnzax)}
  );
  if (X60Qx_1697){
    X60Qx_1696 = (2 <= args_4.len_0);}
  else {
    X60Qx_1696 = NIM_FALSE;}
  if (X60Qx_1696){
    Value_0_valzr1t4f* X60Qx_1698 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_198 = (*X60Qx_1698);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_7 = ptrCell_0_runot4689((&X60QconstRefTemp_198));
    Value_0_valzr1t4f* X60Qx_1699 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_199 = (*X60Qx_1699);
    NI64 X60Qx_1700 = asInt_0_valzr1t4f((&X60QconstRefTemp_199));
    NI32 m_4 = ((NI32)X60Qx_1700);
    if ((!(cell_7 == NIM_NIL))){
      void* X60Qx_1701 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_247 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1701);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_1702 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_247) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
          .elems_0 = X60Qx_1702, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
      ;
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb2_0 = X60Qtmp_247;
      NI32 k_9 = 0;
      {
        while (k_9 < m_4){
          Value_0_valzr1t4f X60Qtmp_248 = vInt_0_valzr1t4f(((NI64)0), 64);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1703 = newCell_0_valzr1t4f((&X60Qtmp_248));
          add_0_Ijpw0mu_flaksyopx1((&(*sb2_0).d_00.elems_0), X60Qx_1703);
          inc_1_I6wjjge_aow2h993l1((&k_9));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_248));}}
      whileStmtLabel_25: ;
      Value_0_valzr1t4f* X60Qlhs_249 = (&(*cell_7).d_00.v_0);
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_251 = sb2_0;
      eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689((&sb2_0));
      Value_0_valzr1t4f X60Qlhs_250 = (Value_0_valzr1t4f){
        .kind_0 = 8, .sq_0 = X60Qtmp_251}
      ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_249)));
      (*X60Qlhs_249) = X60Qlhs_250;
      eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb2_0);}
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_7);
    return result_76;
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_7);}
  NI32 n_16 = 0;
  NB8 X60Qx_1704;
  NB8 X60Qx_1705 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
    .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I17462820957681339184_runot4689)}
  );
  if ((!X60Qx_1705)){
    X60Qx_1704 = (1 <= args_4.len_0);}
  else {
    X60Qx_1704 = NIM_FALSE;}
  if (X60Qx_1704){
    Value_0_valzr1t4f* X60Qx_1706 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_200 = (*X60Qx_1706);
    NI64 X60Qx_1707 = asInt_0_valzr1t4f((&X60QconstRefTemp_200));
    n_16 = ((NI32)X60Qx_1707);}
  void* X60Qx_1708 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_252 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1708);
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_1709 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  (*X60Qtmp_252) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
      .elems_0 = X60Qx_1709, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
  ;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_10 = X60Qtmp_252;
  NI32 i_55 = 0;
  {
    while (i_55 < n_16){
      Value_0_valzr1t4f X60Qtmp_253 = vInt_0_valzr1t4f(((NI64)0), 64);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1710 = newCell_0_valzr1t4f((&X60Qtmp_253));
      add_0_Ijpw0mu_flaksyopx1((&(*sb_10).d_00.elems_0), X60Qx_1710);
      inc_1_I6wjjge_aow2h993l1((&i_55));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_253));}}
  whileStmtLabel_26: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_254 = sb_10;
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689((&sb_10));
  result_76 = (Value_0_valzr1t4f){
    .kind_0 = 8, .sq_0 = X60Qtmp_254}
  ;
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb_10);
  goto X60Qsc_441;
  X60Qsc_254: ;
  NI32 n_17 = 0;
  NB8 X60Qx_1711;
  NB8 X60Qx_1712 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
    .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I11206267958496974357_runot4689)}
  );
  if ((!X60Qx_1712)){
    X60Qx_1711 = (1 <= args_4.len_0);}
  else {
    X60Qx_1711 = NIM_FALSE;}
  if (X60Qx_1711){
    Value_0_valzr1t4f* X60Qx_1713 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_201 = (*X60Qx_1713);
    NI64 X60Qx_1714 = asInt_0_valzr1t4f((&X60QconstRefTemp_201));
    n_17 = ((NI32)X60Qx_1714);}
  string_0_sysvq0asl s_41 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 i_56 = 0;
  {
    while (i_56 < n_17){
      add_1_sysvq0asl((&s_41), (NC8)'\000');
      inc_1_I6wjjge_aow2h993l1((&i_56));}}
  whileStmtLabel_27: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qx_1715 = vStr_0_valzr1t4f(s_41);
  result_76 = X60Qx_1715;
  nimStrDestroy(s_41);
  goto X60Qsc_441;
  X60Qsc_255: ;
  NB8 X60Qx_1716;
  if (2 <= args_4.len_0){
    openArray_0_I2902h9_intzsnzax X60Qx_1717 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
    NB8 X60Qx_1718 = nilContainerRecv_0_runot4689(X60Qx_1717);
    X60Qx_1716 = X60Qx_1718;}
  else {
    X60Qx_1716 = NIM_FALSE;}
  if (X60Qx_1716){
    failNilContainerOp_0_runot4689(sink_13, (string_0_sysvq0asl){
      .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I590530705459077169_runot4689)}
    );}
  else {
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1719 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_202 = (*X60Qx_1719);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_8 = ptrCell_0_runot4689((&X60QconstRefTemp_202));
      Value_0_valzr1t4f* X60Qx_1720 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_203 = (*X60Qx_1720);
      NI64 X60Qx_1721 = asInt_0_valzr1t4f((&X60QconstRefTemp_203));
      NI32 n_18 = ((NI32)X60Qx_1721);
      NB8 X60Qx_1722;
      if ((!(cell_8 == NIM_NIL))){
        X60Qx_1722 = ((*cell_8).d_00.v_0.kind_0 == 8);}
      else {
        X60Qx_1722 = NIM_FALSE;}
      if (X60Qx_1722){
        {
          while (NIM_TRUE){
            NI32 X60Qx_1723 = len_3_I83dzei_arecyyj7v((*(*cell_8).d_00.v_0.sq_0).d_00.elems_0);
            if (X60Qx_1723 < n_18){
              Value_0_valzr1t4f X60Qtmp_255 = vInt_0_valzr1t4f(((NI64)0), 64);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1724 = newCell_0_valzr1t4f((&X60Qtmp_255));
              add_0_Ijpw0mu_flaksyopx1((&(*(*cell_8).d_00.v_0.sq_0).d_00.elems_0), X60Qx_1724);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_255));}
            else {
              break;}}}
        whileStmtLabel_28: ;
        if (n_18 < (*(*cell_8).d_00.v_0.sq_0).d_00.elems_0.len_0){
          setLen_0_I9io9dh1_intzsnzax((&(*(*cell_8).d_00.v_0.sq_0).d_00.elems_0), n_18);}}
      else {
        NB8 X60Qx_1725;
        if ((!(cell_8 == NIM_NIL))){
          X60Qx_1725 = ((*cell_8).d_00.v_0.kind_0 == 6);}
        else {
          X60Qx_1725 = NIM_FALSE;}
        if (X60Qx_1725){
          {
            while (NIM_TRUE){
              NI32 X60Qx_1726 = len_4_sysvq0asl((*cell_8).d_00.v_0.sval_0);
              if (X60Qx_1726 < n_18){
                add_1_sysvq0asl((&(*cell_8).d_00.v_0.sval_0), (NC8)'\000');}
              else {
                break;}}}
          whileStmtLabel_29: ;
          NI32 X60Qx_1727 = len_4_sysvq0asl((*cell_8).d_00.v_0.sval_0);
          if (n_18 < X60Qx_1727){
            setLen_1_sysvq0asl((&(*cell_8).d_00.v_0.sval_0), n_18);}}}
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_8);}}
  goto X60Qsc_441;
  X60Qsc_256: ;
  NB8 X60Qx_1728;
  if (2 <= args_4.len_0){
    openArray_0_I2902h9_intzsnzax X60Qx_1729 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
    NB8 X60Qx_1730 = nilContainerRecv_0_runot4689(X60Qx_1729);
    X60Qx_1728 = X60Qx_1730;}
  else {
    X60Qx_1728 = NIM_FALSE;}
  if (X60Qx_1728){
    failNilContainerOp_0_runot4689(sink_13, (string_0_sysvq0asl){
      .bytes_0 = 1919448062u, .more_0 = (&strlit_0_I12927204854279428474_runot4689)}
    );}
  else {
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1731 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_204 = (*X60Qx_1731);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_9 = ptrCell_0_runot4689((&X60QconstRefTemp_204));
      Value_0_valzr1t4f* X60Qx_1732 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_205 = (*X60Qx_1732);
      NI64 X60Qx_1733 = asInt_0_valzr1t4f((&X60QconstRefTemp_205));
      NI32 n_19 = ((NI32)X60Qx_1733);
      NB8 X60Qx_1734;
      if ((!(cell_9 == NIM_NIL))){
        X60Qx_1734 = ((*cell_9).d_00.v_0.kind_0 == 6);}
      else {
        X60Qx_1734 = NIM_FALSE;}
      if (X60Qx_1734){
        NB8 X60Qx_1735;
        if (0 <= n_19){
          NI32 X60Qx_1736 = len_4_sysvq0asl((*cell_9).d_00.v_0.sval_0);
          X60Qx_1735 = (n_19 < X60Qx_1736);}
        else {
          X60Qx_1735 = NIM_FALSE;}
        if (X60Qx_1735){
          setLen_1_sysvq0asl((&(*cell_9).d_00.v_0.sval_0), n_19);}}
      else {
        NB8 X60Qx_1737;
        NB8 X60Qx_1738;
        if ((!(cell_9 == NIM_NIL))){
          X60Qx_1738 = ((*cell_9).d_00.v_0.kind_0 == 8);}
        else {
          X60Qx_1738 = NIM_FALSE;}
        if (X60Qx_1738){
          X60Qx_1737 = (!((*cell_9).d_00.v_0.sq_0 == NIM_NIL));}
        else {
          X60Qx_1737 = NIM_FALSE;}
        if (X60Qx_1737){
          NB8 X60Qx_1739;
          if (0 <= n_19){
            NI32 X60Qx_1740 = len_3_I83dzei_arecyyj7v((*(*cell_9).d_00.v_0.sq_0).d_00.elems_0);
            X60Qx_1739 = (n_19 < X60Qx_1740);}
          else {
            X60Qx_1739 = NIM_FALSE;}
          if (X60Qx_1739){
            setLen_0_I9io9dh1_intzsnzax((&(*(*cell_9).d_00.v_0.sq_0).d_00.elems_0), n_19);}}}
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_9);}}
  goto X60Qsc_441;
  X60Qsc_257: ;
  NB8 X60Qx_1741;
  if (1 <= args_4.len_0){
    openArray_0_I2902h9_intzsnzax X60Qx_1742 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
    NB8 X60Qx_1743 = nilContainerRecv_0_runot4689(X60Qx_1742);
    X60Qx_1741 = X60Qx_1743;}
  else {
    X60Qx_1741 = NIM_FALSE;}
  if (X60Qx_1741){
    failNilContainerOp_0_runot4689(sink_13, (string_0_sysvq0asl){
      .bytes_0 = 1886351363u, .more_0 = NIM_NIL}
    );}
  else {
    if (1 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1744 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_206 = (*X60Qx_1744);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_10 = ptrCell_0_runot4689((&X60QconstRefTemp_206));
      NB8 X60Qx_1745;
      NB8 X60Qx_1746;
      if ((!(cell_10 == NIM_NIL))){
        X60Qx_1746 = ((*cell_10).d_00.v_0.kind_0 == 8);}
      else {
        X60Qx_1746 = NIM_FALSE;}
      if (X60Qx_1746){
        X60Qx_1745 = (0 < (*(*cell_10).d_00.v_0.sq_0).d_00.elems_0.len_0);}
      else {
        X60Qx_1745 = NIM_FALSE;}
      if (X60Qx_1745){
        NI32 X60Qx_1747 = len_3_I83dzei_arecyyj7v((*(*cell_10).d_00.v_0.sq_0).d_00.elems_0);
        NI32 last_1 = ((NI32)(X60Qx_1747 - 1));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1748 = getQ_7_Ii14ync1_arecyyj7v((*(*cell_10).d_00.v_0.sq_0).d_00.elems_0, last_1);
        Value_0_valzr1t4f X60Qx_1749 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_1748)).d_00.v_0));
        result_76 = X60Qx_1749;
        setLen_0_I9io9dh1_intzsnzax((&(*(*cell_10).d_00.v_0.sq_0).d_00.elems_0), last_1);}
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_10);}}
  goto X60Qsc_441;
  X60Qsc_258: ;
  NB8 X60Qx_1750;
  if (2 <= args_4.len_0){
    openArray_0_I2902h9_intzsnzax X60Qx_1751 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
    NB8 X60Qx_1752 = nilContainerRecv_0_runot4689(X60Qx_1751);
    X60Qx_1750 = X60Qx_1752;}
  else {
    X60Qx_1750 = NIM_FALSE;}
  if (X60Qx_1750){
    failNilContainerOp_0_runot4689(sink_13, (string_0_sysvq0asl){
      .bytes_0 = 1818584067u, .more_0 = NIM_NIL}
    );}
  else {
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1753 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_207 = (*X60Qx_1753);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_11 = ptrCell_0_runot4689((&X60QconstRefTemp_207));
      Value_0_valzr1t4f* X60Qx_1754 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_208 = (*X60Qx_1754);
      NI64 X60Qx_1755 = asInt_0_valzr1t4f((&X60QconstRefTemp_208));
      NI32 i_57 = ((NI32)X60Qx_1755);
      NB8 X60Qx_1756;
      if ((!(cell_11 == NIM_NIL))){
        X60Qx_1756 = ((*cell_11).d_00.v_0.kind_0 == 8);}
      else {
        X60Qx_1756 = NIM_FALSE;}
      if (X60Qx_1756){
        NI32 m_5 = len_3_I83dzei_arecyyj7v((*(*cell_11).d_00.v_0.sq_0).d_00.elems_0);
        NB8 X60Qx_1757;
        if (0 <= i_57){
          X60Qx_1757 = (i_57 < m_5);}
        else {
          X60Qx_1757 = NIM_FALSE;}
        if (X60Qx_1757){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1758 = getQ_7_Ii14ync1_arecyyj7v((*(*cell_11).d_00.v_0.sq_0).d_00.elems_0, ((NI32)(m_5 - 1)));
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* moved_0 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_1758));
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_256 = moved_0;
          eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&moved_0));
          putQ_7_I41w2p9_intzsnzax((&(*(*cell_11).d_00.v_0.sq_0).d_00.elems_0), i_57, X60Qtmp_256);
          setLen_0_I9io9dh1_intzsnzax((&(*(*cell_11).d_00.v_0.sq_0).d_00.elems_0), ((NI32)(m_5 - 1)));
          eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(moved_0);}}
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_11);}}
  goto X60Qsc_441;
  X60Qsc_259: ;
  NB8 X60Qx_1759;
  if (2 <= args_4.len_0){
    openArray_0_I2902h9_intzsnzax X60Qx_1760 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
    NB8 X60Qx_1761 = nilContainerRecv_0_runot4689(X60Qx_1760);
    X60Qx_1759 = X60Qx_1761;}
  else {
    X60Qx_1759 = NIM_FALSE;}
  if (X60Qx_1759){
    failNilContainerOp_0_runot4689(sink_13, (string_0_sysvq0asl){
      .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I7523013755933230041_runot4689)}
    );}
  else {
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1762 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_209 = (*X60Qx_1762);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_12 = ptrCell_0_runot4689((&X60QconstRefTemp_209));
      NI32 first_0;
      NI32 last_2;
      if (3 <= args_4.len_0){
        Value_0_valzr1t4f* X60Qx_1763 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_210 = (*X60Qx_1763);
        NI64 X60Qx_1764 = asInt_0_valzr1t4f((&X60QconstRefTemp_210));
        first_0 = ((NI32)X60Qx_1764);
        Value_0_valzr1t4f* X60Qx_1765 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
        Value_0_valzr1t4f X60QconstRefTemp_211 = (*X60Qx_1765);
        NI64 X60Qx_1766 = asInt_0_valzr1t4f((&X60QconstRefTemp_211));
        last_2 = ((NI32)X60Qx_1766);}
      else {
        NB8 X60Qx_1767;
        NB8 X60Qx_1768;
        NB8 X60Qx_1769;
        Value_0_valzr1t4f* X60Qx_1770 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        if ((*X60Qx_1770).kind_0 == 11){
          X60Qx_1769 = NIM_TRUE;}
        else {
          Value_0_valzr1t4f* X60Qx_1771 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          X60Qx_1769 = ((*X60Qx_1771).kind_0 == 10);}
        if (X60Qx_1769){
          Value_0_valzr1t4f* X60Qx_1772 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          X60Qx_1768 = (!((*X60Qx_1772).obj_0 == NIM_NIL));}
        else {
          X60Qx_1768 = NIM_FALSE;}
        if (X60Qx_1768){
          Value_0_valzr1t4f* X60Qx_1773 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          X60Qx_1767 = (2 <= (*(*X60Qx_1773).obj_0).d_00.cells_0.len_0);}
        else {
          X60Qx_1767 = NIM_FALSE;}
        if (X60Qx_1767){
          Value_0_valzr1t4f* X60Qx_1774 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1775 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1774).obj_0).d_00.cells_0, 0);
          NI64 X60Qx_1776 = asInt_0_valzr1t4f((&(*(*X60Qx_1775)).d_00.v_0));
          first_0 = ((NI32)X60Qx_1776);
          Value_0_valzr1t4f* X60Qx_1777 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1778 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1777).obj_0).d_00.cells_0, 1);
          NI64 X60Qx_1779 = asInt_0_valzr1t4f((&(*(*X60Qx_1778)).d_00.v_0));
          last_2 = ((NI32)X60Qx_1779);}
        else {
          Value_0_valzr1t4f* X60Qx_1780 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          Value_0_valzr1t4f X60QconstRefTemp_212 = (*X60Qx_1780);
          NI64 X60Qx_1781 = asInt_0_valzr1t4f((&X60QconstRefTemp_212));
          first_0 = ((NI32)X60Qx_1781);
          last_2 = first_0;}}
      NB8 X60Qx_1782;
      if ((!(cell_12 == NIM_NIL))){
        X60Qx_1782 = ((*cell_12).d_00.v_0.kind_0 == 8);}
      else {
        X60Qx_1782 = NIM_FALSE;}
      if (X60Qx_1782){
        NI32 m_6 = len_3_I83dzei_arecyyj7v((*(*cell_12).d_00.v_0.sq_0).d_00.elems_0);
        if (first_0 < 0){
          first_0 = 0;}
        if (m_6 <= last_2){
          last_2 = ((NI32)(m_6 - 1));}
        NB8 X60Qx_1783;
        if (first_0 <= last_2){
          X60Qx_1783 = (first_0 < m_6);}
        else {
          X60Qx_1783 = NIM_FALSE;}
        if (X60Qx_1783){
          NI32 cnt_2 = ((NI32)(((NI32)(last_2 - first_0)) + 1));
          NI32 k_10 = first_0;
          {
            while (((NI32)(k_10 + cnt_2)) < m_6){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1784 = getQ_7_Ii14ync1_arecyyj7v((*(*cell_12).d_00.v_0.sq_0).d_00.elems_0, ((NI32)(k_10 + cnt_2)));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* moved_1 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_1784));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_257 = moved_1;
              eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&moved_1));
              putQ_7_I41w2p9_intzsnzax((&(*(*cell_12).d_00.v_0.sq_0).d_00.elems_0), k_10, X60Qtmp_257);
              inc_1_I6wjjge_aow2h993l1((&k_10));
              eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(moved_1);}}
          whileStmtLabel_30: ;
          setLen_0_I9io9dh1_intzsnzax((&(*(*cell_12).d_00.v_0.sq_0).d_00.elems_0), ((NI32)(m_6 - cnt_2)));}}
      else {
        NB8 X60Qx_1785;
        if ((!(cell_12 == NIM_NIL))){
          X60Qx_1785 = ((*cell_12).d_00.v_0.kind_0 == 6);}
        else {
          X60Qx_1785 = NIM_FALSE;}
        if (X60Qx_1785){
          NI32 m_7 = len_4_sysvq0asl((*cell_12).d_00.v_0.sval_0);
          if (first_0 < 0){
            first_0 = 0;}
          if (m_7 <= last_2){
            last_2 = ((NI32)(m_7 - 1));}
          NB8 X60Qx_1786;
          if (first_0 <= last_2){
            X60Qx_1786 = (first_0 < m_7);}
          else {
            X60Qx_1786 = NIM_FALSE;}
          if (X60Qx_1786){
            NI32 cnt_3 = ((NI32)(((NI32)(last_2 - first_0)) + 1));
            NI32 k_11 = first_0;
            {
              while (((NI32)(k_11 + cnt_3)) < m_7){
                NC8 movedCh_0 = getQ_9_sysvq0asl((*cell_12).d_00.v_0.sval_0, ((NI32)(k_11 + cnt_3)));
                putQ_9_sysvq0asl((&(*cell_12).d_00.v_0.sval_0), k_11, movedCh_0);
                inc_1_I6wjjge_aow2h993l1((&k_11));}}
            whileStmtLabel_31: ;
            setLen_1_sysvq0asl((&(*cell_12).d_00.v_0.sval_0), ((NI32)(m_7 - cnt_3)));}}}
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_12);}}
  goto X60Qsc_441;
  X60Qsc_260: ;
  NB8 X60Qx_1787;
  if (2 <= args_4.len_0){
    openArray_0_I2902h9_intzsnzax X60Qx_1788 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
    NB8 X60Qx_1789 = nilContainerRecv_0_runot4689(X60Qx_1788);
    X60Qx_1787 = X60Qx_1789;}
  else {
    X60Qx_1787 = NIM_FALSE;}
  if (X60Qx_1787){
    failNilContainerOp_0_runot4689(sink_13, (string_0_sysvq0asl){
      .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I6872392552133396222_runot4689)}
    );}
  else {
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1790 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_213 = (*X60Qx_1790);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_13 = ptrCell_0_runot4689((&X60QconstRefTemp_213));
      NB8 X60Qx_1791;
      if ((!(cell_13 == NIM_NIL))){
        X60Qx_1791 = ((*cell_13).d_00.v_0.kind_0 == 8);}
      else {
        X60Qx_1791 = NIM_FALSE;}
      if (X60Qx_1791){
        NI32 X60Qx_58;
        if (3 <= args_4.len_0){
          Value_0_valzr1t4f* X60Qx_1792 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
          Value_0_valzr1t4f X60QconstRefTemp_214 = (*X60Qx_1792);
          NI64 X60Qx_1793 = asInt_0_valzr1t4f((&X60QconstRefTemp_214));
          X60Qx_58 = ((NI32)X60Qx_1793);}
        else {
          X60Qx_58 = 0;}
        NI32 p_5 = X60Qx_58;
        if (p_5 < 0){
          p_5 = 0;}
        if ((*(*cell_13).d_00.v_0.sq_0).d_00.elems_0.len_0 < p_5){
          NI32 X60Qx_1794 = len_3_I83dzei_arecyyj7v((*(*cell_13).d_00.v_0.sq_0).d_00.elems_0);
          p_5 = X60Qx_1794;}
        seq_0_Iw8xl5b1_arecyyj7v ins_0 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        NB8 X60Qx_1795;
        Value_0_valzr1t4f* X60Qx_1796 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        if ((*X60Qx_1796).kind_0 == 8){
          Value_0_valzr1t4f* X60Qx_1797 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          X60Qx_1795 = (!((*X60Qx_1797).sq_0 == NIM_NIL));}
        else {
          X60Qx_1795 = NIM_FALSE;}
        if (X60Qx_1795){
          NI32 j_1 = 0;
          {
            while (NIM_TRUE){
              Value_0_valzr1t4f* X60Qx_1798 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
              NI32 X60Qx_1799 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1798).sq_0).d_00.elems_0);
              if (j_1 < X60Qx_1799){
                Value_0_valzr1t4f* X60Qx_1800 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1801 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1800).sq_0).d_00.elems_0, j_1);
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1802 = newCell_0_valzr1t4f((&(*(*X60Qx_1801)).d_00.v_0));
                add_0_Ijpw0mu_flaksyopx1((&ins_0), X60Qx_1802);
                inc_1_I6wjjge_aow2h993l1((&j_1));}
              else {
                break;}}}
          whileStmtLabel_32: ;}
        else {
          NB8 X60Qx_1803;
          Value_0_valzr1t4f* X60Qx_1804 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          if ((*X60Qx_1804).kind_0 == 9){
            Value_0_valzr1t4f* X60Qx_1805 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
            X60Qx_1803 = (!((*X60Qx_1805).arr_0 == NIM_NIL));}
          else {
            X60Qx_1803 = NIM_FALSE;}
          if (X60Qx_1803){
            NI32 j_2 = 0;
            {
              while (NIM_TRUE){
                Value_0_valzr1t4f* X60Qx_1806 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
                NI32 X60Qx_1807 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1806).arr_0).d_00.elems_0);
                if (j_2 < X60Qx_1807){
                  Value_0_valzr1t4f* X60Qx_1808 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1809 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1808).arr_0).d_00.elems_0, j_2);
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1810 = newCell_0_valzr1t4f((&(*(*X60Qx_1809)).d_00.v_0));
                  add_0_Ijpw0mu_flaksyopx1((&ins_0), X60Qx_1810);
                  inc_1_I6wjjge_aow2h993l1((&j_2));}
                else {
                  break;}}}
            whileStmtLabel_33: ;}
          else {
            Value_0_valzr1t4f* X60Qx_1811 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
            if ((*X60Qx_1811).kind_0 == 6){
              NI32 j_3 = 0;
              {
                while (NIM_TRUE){
                  Value_0_valzr1t4f* X60Qx_1812 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
                  NI32 X60Qx_1813 = len_4_sysvq0asl((*X60Qx_1812).sval_0);
                  if (j_3 < X60Qx_1813){
                    Value_0_valzr1t4f* X60Qx_1814 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
                    NC8 X60Qx_1815 = getQ_9_sysvq0asl((*X60Qx_1814).sval_0, j_3);
                    Value_0_valzr1t4f X60Qtmp_258 = vChar_0_valzr1t4f(X60Qx_1815);
                    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1816 = newCell_0_valzr1t4f((&X60Qtmp_258));
                    add_0_Ijpw0mu_flaksyopx1((&ins_0), X60Qx_1816);
                    inc_1_I6wjjge_aow2h993l1((&j_3));
                    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_258));}
                  else {
                    break;}}}
              whileStmtLabel_34: ;}
            else {
              Value_0_valzr1t4f* X60Qx_1817 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
              Value_0_valzr1t4f X60QconstRefTemp_215 = (*X60Qx_1817);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1818 = newCell_0_valzr1t4f((&X60QconstRefTemp_215));
              add_0_Ijpw0mu_flaksyopx1((&ins_0), X60Qx_1818);}}}
        seq_0_Iw8xl5b1_arecyyj7v ne_0 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        NI32 k_12 = 0;
        {
          while (k_12 < p_5){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1819 = getQ_7_Ii14ync1_arecyyj7v((*(*cell_13).d_00.v_0.sq_0).d_00.elems_0, k_12);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1820 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_1819));
            add_0_Ijpw0mu_flaksyopx1((&ne_0), X60Qx_1820);
            inc_1_I6wjjge_aow2h993l1((&k_12));}}
        whileStmtLabel_35: ;
        NI32 t_8 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1821 = len_3_I83dzei_arecyyj7v(ins_0);
            if (t_8 < X60Qx_1821){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1822 = getQ_7_Ii14ync1_arecyyj7v(ins_0, t_8);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1823 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_1822));
              add_0_Ijpw0mu_flaksyopx1((&ne_0), X60Qx_1823);
              inc_1_I6wjjge_aow2h993l1((&t_8));}
            else {
              break;}}}
        whileStmtLabel_36: ;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1824 = len_3_I83dzei_arecyyj7v((*(*cell_13).d_00.v_0.sq_0).d_00.elems_0);
            if (k_12 < X60Qx_1824){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1825 = getQ_7_Ii14ync1_arecyyj7v((*(*cell_13).d_00.v_0.sq_0).d_00.elems_0, k_12);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1826 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_1825));
              add_0_Ijpw0mu_flaksyopx1((&ne_0), X60Qx_1826);
              inc_1_I6wjjge_aow2h993l1((&k_12));}
            else {
              break;}}}
        whileStmtLabel_37: ;
        seq_0_Iw8xl5b1_arecyyj7v* X60Qlhs_259 = (&(*(*cell_13).d_00.v_0.sq_0).d_00.elems_0);
        seq_0_Iw8xl5b1_arecyyj7v X60Qlhs_260 = ne_0;
        eQwasMoved_1_I4kgdoh1_arecyyj7v((&ne_0));
        eQdestroy_1_I8k3d0z1_arecyyj7v((*X60Qlhs_259));
        (*X60Qlhs_259) = X60Qlhs_260;
        eQdestroy_1_I8k3d0z1_arecyyj7v(ne_0);
        eQdestroy_1_I8k3d0z1_arecyyj7v(ins_0);}
      else {
        NB8 X60Qx_1827;
        if ((!(cell_13 == NIM_NIL))){
          X60Qx_1827 = ((*cell_13).d_00.v_0.kind_0 == 6);}
        else {
          X60Qx_1827 = NIM_FALSE;}
        if (X60Qx_1827){
          NI32 X60Qx_59;
          if (3 <= args_4.len_0){
            Value_0_valzr1t4f* X60Qx_1828 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
            Value_0_valzr1t4f X60QconstRefTemp_216 = (*X60Qx_1828);
            NI64 X60Qx_1829 = asInt_0_valzr1t4f((&X60QconstRefTemp_216));
            X60Qx_59 = ((NI32)X60Qx_1829);}
          else {
            X60Qx_59 = 0;}
          NI32 p_6 = X60Qx_59;
          if (p_6 < 0){
            p_6 = 0;}
          NI32 X60Qx_1830 = len_4_sysvq0asl((*cell_13).d_00.v_0.sval_0);
          if (X60Qx_1830 < p_6){
            NI32 X60Qx_1831 = len_4_sysvq0asl((*cell_13).d_00.v_0.sval_0);
            p_6 = X60Qx_1831;}
          string_0_sysvq0asl piece_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          Value_0_valzr1t4f* X60Qx_1832 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
          if ((*X60Qx_1832).kind_0 == 6){
            nimStrDestroy(piece_0);
            Value_0_valzr1t4f* X60Qx_1833 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
            string_0_sysvq0asl X60Qx_1834 = nimStrDup((*X60Qx_1833).sval_0);
            piece_0 = X60Qx_1834;}
          else {
            Value_0_valzr1t4f* X60Qx_1835 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
            if ((*X60Qx_1835).kind_0 == 5){
              Value_0_valzr1t4f* X60Qx_1836 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
              add_1_sysvq0asl((&piece_0), (*X60Qx_1836).cval_0);}}
          string_0_sysvq0asl ns_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          NI32 k_13 = 0;
          {
            while (k_13 < p_6){
              NC8 X60Qx_1837 = getQ_9_sysvq0asl((*cell_13).d_00.v_0.sval_0, k_13);
              add_1_sysvq0asl((&ns_0), X60Qx_1837);
              inc_1_I6wjjge_aow2h993l1((&k_13));}}
          whileStmtLabel_38: ;
          add_2_sysvq0asl((&ns_0), piece_0);
          {
            while (NIM_TRUE){
              NI32 X60Qx_1838 = len_4_sysvq0asl((*cell_13).d_00.v_0.sval_0);
              if (k_13 < X60Qx_1838){
                NC8 X60Qx_1839 = getQ_9_sysvq0asl((*cell_13).d_00.v_0.sval_0, k_13);
                add_1_sysvq0asl((&ns_0), X60Qx_1839);
                inc_1_I6wjjge_aow2h993l1((&k_13));}
              else {
                break;}}}
          whileStmtLabel_39: ;
          string_0_sysvq0asl* X60Qlhs_261 = (&(*cell_13).d_00.v_0.sval_0);
          string_0_sysvq0asl X60Qlhs_262 = ns_0;
          nimStrWasMoved((&ns_0));
          nimStrDestroy((*X60Qlhs_261));
          (*X60Qlhs_261) = X60Qlhs_262;
          nimStrDestroy(ns_0);
          nimStrDestroy(piece_0);}}
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_13);}}
  goto X60Qsc_441;
  X60Qsc_261: ;
  if (3 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1840 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_217 = (*X60Qx_1840);
    NI64 X60Qx_1841 = asInt_0_valzr1t4f((&X60QconstRefTemp_217));
    NI32 lo_2 = ((NI32)X60Qx_1841);
    Value_0_valzr1t4f* X60Qx_1842 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_218 = (*X60Qx_1842);
    NI64 X60Qx_1843 = asInt_0_valzr1t4f((&X60QconstRefTemp_218));
    NI32 hi_2 = ((NI32)X60Qx_1843);
    Value_0_valzr1t4f* X60Qx_1844 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    switch ((*X60Qx_1844).kind_0){
      case 0:
      {
        if (hi_2 < lo_2){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
          Value_0_valzr1t4f X60Qx_1845 = vStr_0_valzr1t4f((string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          );
          result_76 = X60Qx_1845;}
        else {
          failNilContainerOp_0_runot4689(sink_13, (string_0_sysvq0asl){
            .bytes_0 = 1332704510u, .more_0 = (&strlit_0_I13575662182318269178_runot4689)}
          );}}
      break;
      case 6:
      {
        string_0_sysvq0asl r_10 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;
        NI64 X60Qx_60;
        if (lo_2 < 0){
          X60Qx_60 = 0;}
        else {
          X60Qx_60 = lo_2;}
        NI32 k_14 = X60Qx_60;
        {
          while (NIM_TRUE){
            NB8 X60Qx_1846;
            if (k_14 <= hi_2){
              Value_0_valzr1t4f* X60Qx_1847 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
              NI32 X60Qx_1848 = len_4_sysvq0asl((*X60Qx_1847).sval_0);
              X60Qx_1846 = (k_14 < X60Qx_1848);}
            else {
              X60Qx_1846 = NIM_FALSE;}
            if (X60Qx_1846){
              Value_0_valzr1t4f* X60Qx_1849 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
              NC8 X60Qx_1850 = getQ_9_sysvq0asl((*X60Qx_1849).sval_0, k_14);
              add_1_sysvq0asl((&r_10), X60Qx_1850);
              inc_1_I6wjjge_aow2h993l1((&k_14));}
            else {
              break;}}}
        whileStmtLabel_40: ;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1851 = vStr_0_valzr1t4f(r_10);
        result_76 = X60Qx_1851;
        nimStrDestroy(r_10);}
      break;
      case 8:
      {
        void* X60Qx_1852 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_263 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1852);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_1853 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        (*X60Qtmp_263) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
            .elems_0 = X60Qx_1853, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
        ;
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_11 = X60Qtmp_263;
        NI64 X60Qx_61;
        if (lo_2 < 0){
          X60Qx_61 = 0;}
        else {
          X60Qx_61 = lo_2;}
        NI32 k_15 = X60Qx_61;
        {
          while (NIM_TRUE){
            NB8 X60Qx_1854;
            if (k_15 <= hi_2){
              Value_0_valzr1t4f* X60Qx_1855 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
              NI32 X60Qx_1856 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1855).sq_0).d_00.elems_0);
              X60Qx_1854 = (k_15 < X60Qx_1856);}
            else {
              X60Qx_1854 = NIM_FALSE;}
            if (X60Qx_1854){
              Value_0_valzr1t4f* X60Qx_1857 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1858 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1857).sq_0).d_00.elems_0, k_15);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1859 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_1858));
              add_0_Ijpw0mu_flaksyopx1((&(*sb_11).d_00.elems_0), X60Qx_1859);
              inc_1_I6wjjge_aow2h993l1((&k_15));}
            else {
              break;}}}
        whileStmtLabel_41: ;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_264 = sb_11;
        eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689((&sb_11));
        result_76 = (Value_0_valzr1t4f){
          .kind_0 = 8, .sq_0 = X60Qtmp_264}
        ;
        eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(sb_11);}
      break;
      case 9:
      {
        void* X60Qx_1860 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_265 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_1860);
        seq_0_Iw8xl5b1_arecyyj7v X60Qx_1861 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
        (*X60Qtmp_265) = (X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (ArrBox_Obj_0_valzr1t4f){
            .elems_0 = X60Qx_1861, .lo_0 = 0, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
        ;
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* ab_3 = X60Qtmp_265;
        NI64 X60Qx_62;
        if (lo_2 < 0){
          X60Qx_62 = 0;}
        else {
          X60Qx_62 = lo_2;}
        NI32 k_16 = X60Qx_62;
        {
          while (NIM_TRUE){
            NB8 X60Qx_1862;
            if (k_16 <= hi_2){
              Value_0_valzr1t4f* X60Qx_1863 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
              NI32 X60Qx_1864 = len_3_I83dzei_arecyyj7v((*(*X60Qx_1863).arr_0).d_00.elems_0);
              X60Qx_1862 = (k_16 < X60Qx_1864);}
            else {
              X60Qx_1862 = NIM_FALSE;}
            if (X60Qx_1862){
              Value_0_valzr1t4f* X60Qx_1865 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_1866 = getQ_7_Ii14ync1_arecyyj7v((*(*X60Qx_1865).arr_0).d_00.elems_0, k_16);
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_1867 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((*X60Qx_1866));
              add_0_Ijpw0mu_flaksyopx1((&(*ab_3).d_00.elems_0), X60Qx_1867);
              inc_1_I6wjjge_aow2h993l1((&k_16));}
            else {
              break;}}}
        whileStmtLabel_42: ;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_266 = ab_3;
        eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689((&ab_3));
        result_76 = (Value_0_valzr1t4f){
          .kind_0 = 9, .arr_0 = X60Qtmp_266}
        ;
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(ab_3);}
      break;
      case 13:
      {
        Value_0_valzr1t4f* X60Qx_1868 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        Value_0_valzr1t4f X60QconstRefTemp_219 = (*X60Qx_1868);
        X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_5 = ptrRegionOf_0_runot4689((&X60QconstRefTemp_219));
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_11 = X60Qtmptup_5.fld_0;
        eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((&X60Qtmptup_5.fld_0));
        NI32 base_9 = X60Qtmptup_5.fld_1;
        if ((!(r_11 == NIM_NIL))){
          string_0_sysvq0asl s_44 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          NI64 X60Qx_63;
          if (lo_2 < 0){
            X60Qx_63 = 0;}
          else {
            X60Qx_63 = lo_2;}
          NI32 k_17 = X60Qx_63;
          {
            while (k_17 <= hi_2){
              NU8 X60Qx_1869 = byteAt_0_flaksyopx1(r_11, ((NI32)(base_9 + k_17)));
              add_1_sysvq0asl((&s_44), ((NC8)X60Qx_1869));
              inc_1_I6wjjge_aow2h993l1((&k_17));}}
          whileStmtLabel_43: ;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
          Value_0_valzr1t4f X60Qx_1870 = vStr_0_valzr1t4f(s_44);
          result_76 = X60Qx_1870;
          nimStrDestroy(s_44);}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
          Value_0_valzr1t4f* X60Qx_1871 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
          Value_0_valzr1t4f X60QconstRefTemp_220 = (*X60Qx_1871);
          Value_0_valzr1t4f X60Qx_1872 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_220));
          result_76 = X60Qx_1872;}
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(r_11);
        eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qtmptup_5);}
      break;
      default:
      {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f* X60Qx_1873 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        Value_0_valzr1t4f X60QconstRefTemp_221 = (*X60Qx_1873);
        Value_0_valzr1t4f X60Qx_1874 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_221));
        result_76 = X60Qx_1874;}
      break;}}
  else {
    if (1 <= args_4.len_0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f* X60Qx_1875 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_222 = (*X60Qx_1875);
      Value_0_valzr1t4f X60Qx_1876 = strArg_0_runot4689((&X60QconstRefTemp_222));
      result_76 = X60Qx_1876;}}
  goto X60Qsc_441;
  X60Qsc_262: ;
  NB8 X60Qx_135;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1877 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_223 = (*X60Qx_1877);
    Value_0_valzr1t4f X60Qtmp_267 = strArg_0_runot4689((&X60QconstRefTemp_223));
    X60Qx_135 = (X60Qtmp_267.kind_0 == 6);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_267));}
  else {
    X60Qx_135 = NIM_FALSE;}
  if (X60Qx_135){
    Value_0_valzr1t4f* X60Qx_1878 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_224 = (*X60Qx_1878);
    Value_0_valzr1t4f X60Qtmp_268 = strArg_0_runot4689((&X60QconstRefTemp_224));
    string_0_sysvq0asl s_45 = nimStrDup(X60Qtmp_268.sval_0);
    NI32 X60Qx_64;
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1879 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_225 = (*X60Qx_1879);
      NI64 X60Qx_1880 = asInt_0_valzr1t4f((&X60QconstRefTemp_225));
      X60Qx_64 = ((NI32)X60Qx_1880);}
    else {
      X60Qx_64 = 0;}
    NI32 a_14 = X60Qx_64;
    NI32 X60Qx_65;
    if (3 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_1881 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
      Value_0_valzr1t4f X60QconstRefTemp_226 = (*X60Qx_1881);
      NI64 X60Qx_1882 = asInt_0_valzr1t4f((&X60QconstRefTemp_226));
      X60Qx_65 = ((NI32)X60Qx_1882);}
    else {
      NI32 X60Qx_1883 = len_4_sysvq0asl(s_45);
      X60Qx_65 = ((NI32)(X60Qx_1883 - 1));}
    NI32 b_16 = X60Qx_65;
    if (a_14 < 0){
      a_14 = 0;}
    NI32 X60Qx_1884 = len_4_sysvq0asl(s_45);
    if (X60Qx_1884 <= b_16){
      NI32 X60Qx_1885 = len_4_sysvq0asl(s_45);
      b_16 = ((NI32)(X60Qx_1885 - 1));}
    string_0_sysvq0asl r_12 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    NI32 k_18 = a_14;
    {
      while (k_18 <= b_16){
        NC8 X60Qx_1886 = getQ_9_sysvq0asl(s_45, k_18);
        add_1_sysvq0asl((&r_12), X60Qx_1886);
        inc_1_I6wjjge_aow2h993l1((&k_18));}}
    whileStmtLabel_44: ;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1887 = vStr_0_valzr1t4f(r_12);
    result_76 = X60Qx_1887;
    nimStrDestroy(r_12);
    nimStrDestroy(s_45);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_268));}
  goto X60Qsc_441;
  X60Qsc_263: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1888 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_227 = (*X60Qx_1888);
    NF64 x_25 = floatOf_0_runot4689((&X60QconstRefTemp_227));
    string_0_sysvq0asl nm_4 = nimStrDup(name_6);
    NB8 X60Qx_1889;
    NB8 X60Qx_1890;
    NI32 X60Qx_1891 = len_4_sysvq0asl(nm_4);
    if (1 < X60Qx_1891){
      NI32 X60Qx_1892 = len_4_sysvq0asl(nm_4);
      NC8 X60Qx_1893 = getQ_9_sysvq0asl(nm_4, ((NI32)(X60Qx_1892 - 1)));
      X60Qx_1890 = (X60Qx_1893 == (NC8)'f');}
    else {
      X60Qx_1890 = NIM_FALSE;}
    if (X60Qx_1890){
      NB8 X60Qx_1894 = eqQ_20_sysvq0asl(nm_4, (string_0_sysvq0asl){
        .bytes_0 = 1718772995u, .more_0 = NIM_NIL}
      );
      X60Qx_1889 = (!X60Qx_1894);}
    else {
      X60Qx_1889 = NIM_FALSE;}
    if (X60Qx_1889){
      NI32 X60Qx_1895 = len_4_sysvq0asl(nm_4);
      HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1896 = __ltQ_1_Ij9jwi_aow7lb5cq1(0, ((NI32)(X60Qx_1895 - 1)));
      string_0_sysvq0asl X60Qlhs_269 = getQ_14_sysvq0asl(nm_4, X60Qx_1896);
      nimStrDestroy(nm_4);
      nm_4 = X60Qlhs_269;}
    NF64 r_13 = 0.0;
    NB8 X60Qtc_473 = nimStrAtLe_0_sysvq0asl(nm_4, 0, (NC8)'e');
    if (X60Qtc_473){
      NB8 X60Qtc_474 = nimStrAtLe_0_sysvq0asl(nm_4, 3, (NC8)'n');
      if (X60Qtc_474){
        NB8 X60Qtc_475 = nimStrAtLe_0_sysvq0asl(nm_4, 1, (NC8)'r');
        if (X60Qtc_475){
          NB8 X60Qtc_476 = nimStrAtLe_0_sysvq0asl(nm_4, 1, (NC8)'o');
          if (X60Qtc_476){
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1936679934u, .more_0 = (&strlit_0_I1951864687996922622_runot4689)}
            )){
              goto X60Qsc_456;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1768252414u, .more_0 = (&strlit_0_I9007462764285996300_runot4689)}
            )){
              goto X60Qsc_470;}}
          else {
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I1702282805285054051_runot4689)}
            )){
              goto X60Qsc_453;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1718773246u, .more_0 = (&strlit_0_I17767840746738081133_runot4689)}
            )){
              goto X60Qsc_462;}}}
        else {
          NB8 X60Qtc_477 = nimStrAtLe_0_sysvq0asl(nm_4, 1, (NC8)'s');
          if (X60Qtc_477){
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1769169406u, .more_0 = (&strlit_0_I10698485606268199303_runot4689)}
            )){
              goto X60Qsc_452;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1769169406u, .more_0 = (&strlit_0_I15785994502496746995_runot4689)}
            )){
              goto X60Qsc_458;}}
          else {
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1635017214u, .more_0 = (&strlit_0_I11456619178692440789_runot4689)}
            )){
              goto X60Qsc_454;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1635017214u, .more_0 = (&strlit_0_I16113657126360930300_runot4689)}
            )){
              goto X60Qsc_460;}}}}
      else {
        NB8 X60Qtc_478 = nimStrAtLe_0_sysvq0asl(nm_4, 0, (NC8)'a');
        if (X60Qtc_478){
          NB8 X60Qtc_479 = nimStrAtLe_0_sysvq0asl(nm_4, 1, (NC8)'c');
          if (X60Qtc_479){
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I2255282174144548766_runot4689)}
            )){
              goto X60Qsc_453;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I5124821916304759024_runot4689)}
            )){
              goto X60Qsc_459;}}
          else {
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I5698419940050250200_runot4689)}
            )){
              goto X60Qsc_452;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I1534576491481833817_runot4689)}
            )){
              goto X60Qsc_454;}}}
        else {
          NB8 X60Qtc_480 = nimStrAtLe_0_sysvq0asl(nm_4, 0, (NC8)'c');
          if (X60Qtc_480){
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1919050750u, .more_0 = (&strlit_0_I8970872227344634284_runot4689)}
            )){
              goto X60Qsc_448;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1936679683u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_450;}}
          else {
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1718772995u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_461;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1886938371u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_465;}}}}}
    else {
      NB8 X60Qtc_481 = nimStrAtLe_0_sysvq0asl(nm_4, 0, (NC8)'l');
      if (X60Qtc_481){
        NB8 X60Qtc_482 = nimStrAtLe_0_sysvq0asl(nm_4, 1, (NC8)'n');
        if (X60Qtc_482){
          NB8 X60Qtc_483 = nimStrAtLe_0_sysvq0asl(nm_4, 0, (NC8)'g');
          if (X60Qtc_483){
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1835100158u, .more_0 = (&strlit_0_I11575531321635900188_runot4689)}
            )){
              goto X60Qsc_463;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I13770135642222982414_runot4689)}
            )){
              goto X60Qsc_469;}}
          else {
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1634168062u, .more_0 = (&strlit_0_I17537008619994765435_runot4689)}
            )){
              goto X60Qsc_464;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 7236610u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_466;}}}
        else {
          NB8 X60Qtc_484 = nimStrAtLe_0_sysvq0asl(nm_4, 3, (NC8)'1');
          if (X60Qtc_484){
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1735355646u, .more_0 = (&strlit_0_I10762679581578789876_runot4689)}
            )){
              goto X60Qsc_467;}}
          else {
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1735355395u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_466;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1735355646u, .more_0 = (&strlit_0_I16777186388511288065_runot4689)}
            )){
              goto X60Qsc_468;}}}}
      else {
        NB8 X60Qtc_485 = nimStrAtLe_0_sysvq0asl(nm_4, 0, (NC8)'s');
        if (X60Qtc_485){
          NB8 X60Qtc_486 = nimStrAtLe_0_sysvq0asl(nm_4, 1, (NC8)'i');
          if (X60Qtc_486){
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1852404483u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_449;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I11806394720139207185_runot4689)}
            )){
              goto X60Qsc_455;}}
          else {
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1920037886u, .more_0 = (&strlit_0_I2622871807570587851_runot4689)}
            )){
              goto X60Qsc_447;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1970238206u, .more_0 = (&strlit_0_I16919077516905105311_runot4689)}
            )){
              goto X60Qsc_472;}}}
        else {
          NB8 X60Qtc_487 = nimStrAtLe_0_sysvq0asl(nm_4, 1, (NC8)'a');
          if (X60Qtc_487){
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1851880451u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_451;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1851880702u, .more_0 = (&strlit_0_I3069983570459151989_runot4689)}
            )){
              goto X60Qsc_457;}}
          else {
            if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1634170110u, .more_0 = (&strlit_0_I13587882791461032424_runot4689)}
            )){
              goto X60Qsc_463;}
            else if (equalStrings_0_sysvq0asl(nm_4, (string_0_sysvq0asl){
              .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I10246663023455874512_runot4689)}
            )){
              goto X60Qsc_471;}}}}}
    goto X60Qsc_489;
    X60Qsc_447: ;
    NF64 X60Qx_1897 = sqrt(x_25);
    r_13 = X60Qx_1897;
    goto X60Qsc_488;
    X60Qsc_448: ;
    NF64 X60Qx_1898 = cbrt(x_25);
    r_13 = X60Qx_1898;
    goto X60Qsc_488;
    X60Qsc_449: ;
    NF64 X60Qx_1899 = sin(x_25);
    r_13 = X60Qx_1899;
    goto X60Qsc_488;
    X60Qsc_450: ;
    NF64 X60Qx_1900 = cos(x_25);
    r_13 = X60Qx_1900;
    goto X60Qsc_488;
    X60Qsc_451: ;
    NF64 X60Qx_1901 = tan(x_25);
    r_13 = X60Qx_1901;
    goto X60Qsc_488;
    X60Qsc_452: ;
    NF64 X60Qx_1902 = asin(x_25);
    r_13 = X60Qx_1902;
    goto X60Qsc_488;
    X60Qsc_453: ;
    NF64 X60Qx_1903 = acos(x_25);
    r_13 = X60Qx_1903;
    goto X60Qsc_488;
    X60Qsc_454: ;
    NF64 X60Qx_1904 = atan(x_25);
    r_13 = X60Qx_1904;
    goto X60Qsc_488;
    X60Qsc_455: ;
    NF64 X60Qx_1905 = sinh(x_25);
    r_13 = X60Qx_1905;
    goto X60Qsc_488;
    X60Qsc_456: ;
    NF64 X60Qx_1906 = cosh(x_25);
    r_13 = X60Qx_1906;
    goto X60Qsc_488;
    X60Qsc_457: ;
    NF64 X60Qx_1907 = tanh(x_25);
    r_13 = X60Qx_1907;
    goto X60Qsc_488;
    X60Qsc_458: ;
    NF64 X60Qx_1908 = asinh(x_25);
    r_13 = X60Qx_1908;
    goto X60Qsc_488;
    X60Qsc_459: ;
    NF64 X60Qx_1909 = acosh(x_25);
    r_13 = X60Qx_1909;
    goto X60Qsc_488;
    X60Qsc_460: ;
    NF64 X60Qx_1910 = atanh(x_25);
    r_13 = X60Qx_1910;
    goto X60Qsc_488;
    X60Qsc_461: ;
    NF64 X60Qx_1911 = erf(x_25);
    r_13 = X60Qx_1911;
    goto X60Qsc_488;
    X60Qsc_462: ;
    NF64 X60Qx_1912 = erfc(x_25);
    r_13 = X60Qx_1912;
    goto X60Qsc_488;
    X60Qsc_463: ;
    NF64 X60Qx_1913 = tgamma(x_25);
    r_13 = X60Qx_1913;
    goto X60Qsc_488;
    X60Qsc_464: ;
    NF64 X60Qx_1914 = lgamma(x_25);
    r_13 = X60Qx_1914;
    goto X60Qsc_488;
    X60Qsc_465: ;
    NF64 X60Qx_1915 = exp(x_25);
    r_13 = X60Qx_1915;
    goto X60Qsc_488;
    X60Qsc_466: ;
    NF64 X60Qx_1916 = log(x_25);
    r_13 = X60Qx_1916;
    goto X60Qsc_488;
    X60Qsc_467: ;
    NF64 X60Qx_1917 = log10(x_25);
    r_13 = X60Qx_1917;
    goto X60Qsc_488;
    X60Qsc_468: ;
    NF64 X60Qx_1918 = log2(x_25);
    r_13 = X60Qx_1918;
    goto X60Qsc_488;
    X60Qsc_469: ;
    NF64 X60Qx_1919 = floor(x_25);
    r_13 = X60Qx_1919;
    goto X60Qsc_488;
    X60Qsc_470: ;
    NF64 X60Qx_1920 = ceil(x_25);
    r_13 = X60Qx_1920;
    goto X60Qsc_488;
    X60Qsc_471: ;
    NF64 X60Qx_1921 = trunc(x_25);
    r_13 = X60Qx_1921;
    goto X60Qsc_488;
    X60Qsc_472: ;
    NF64 X60Qx_1922 = round(x_25);
    r_13 = X60Qx_1922;
    goto X60Qsc_488;
    X60Qsc_489: ;
    X60Qsc_488: ;
    NI32 X60Qx_66;
    Value_0_valzr1t4f* X60Qx_1923 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    if ((*X60Qx_1923).kind_0 == 3){
      Value_0_valzr1t4f* X60Qx_1924 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      X60Qx_66 = (*X60Qx_1924).fbits_0;}
    else {
      X60Qx_66 = 64;}
    NI32 fb_0 = X60Qx_66;
    if (fb_0 == 32){
      r_13 = ((NF64)((NF32)r_13));}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1925 = vFloat_0_valzr1t4f(r_13, fb_0);
    result_76 = X60Qx_1925;
    nimStrDestroy(nm_4);}
  goto X60Qsc_441;
  X60Qsc_264: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1926 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_228 = (*X60Qx_1926);
    NF64 x_26 = floatOf_0_runot4689((&X60QconstRefTemp_228));
    Value_0_valzr1t4f* X60Qx_1927 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_229 = (*X60Qx_1927);
    NF64 y_3 = floatOf_0_runot4689((&X60QconstRefTemp_229));
    string_0_sysvq0asl nm_5 = nimStrDup(name_6);
    NB8 X60Qx_1928;
    NB8 X60Qx_1929;
    NI32 X60Qx_1930 = len_4_sysvq0asl(nm_5);
    if (1 < X60Qx_1930){
      NI32 X60Qx_1931 = len_4_sysvq0asl(nm_5);
      NC8 X60Qx_1932 = getQ_9_sysvq0asl(nm_5, ((NI32)(X60Qx_1931 - 1)));
      X60Qx_1929 = (X60Qx_1932 == (NC8)'f');}
    else {
      X60Qx_1929 = NIM_FALSE;}
    if (X60Qx_1929){
      NB8 X60Qx_1933 = eqQ_20_sysvq0asl(nm_5, (string_0_sysvq0asl){
        .bytes_0 = 1685024003u, .more_0 = NIM_NIL}
      );
      X60Qx_1928 = (!X60Qx_1933);}
    else {
      X60Qx_1928 = NIM_FALSE;}
    if (X60Qx_1928){
      NI32 X60Qx_1934 = len_4_sysvq0asl(nm_5);
      HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1935 = __ltQ_1_Ij9jwi_aow7lb5cq1(0, ((NI32)(X60Qx_1934 - 1)));
      string_0_sysvq0asl X60Qlhs_270 = getQ_14_sysvq0asl(nm_5, X60Qx_1935);
      nimStrDestroy(nm_5);
      nm_5 = X60Qlhs_270;}
    NF64 r_14 = 0.0;
    NB8 X60Qtc_495 = nimStrAtLe_0_sysvq0asl(nm_5, 0, (NC8)'c');
    if (X60Qtc_495){
      NB8 X60Qtc_496 = nimStrAtLe_0_sysvq0asl(nm_5, 0, (NC8)'a');
      if (X60Qtc_496){
        if (equalStrings_0_sysvq0asl(nm_5, (string_0_sysvq0asl){
          .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I891118288292861849_runot4689)}
        )){
          goto X60Qsc_492;}
        else if (equalStrings_0_sysvq0asl(nm_5, (string_0_sysvq0asl){
          .bytes_0 = 1635017214u, .more_0 = (&strlit_0_I14583999013692158065_runot4689)}
        )){
          goto X60Qsc_492;}}
      else {
        if (equalStrings_0_sysvq0asl(nm_5, (string_0_sysvq0asl){
          .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I9772346370466888830_runot4689)}
        )){
          goto X60Qsc_493;}
        else if (equalStrings_0_sysvq0asl(nm_5, (string_0_sysvq0asl){
          .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I4513720326185655066_runot4689)}
        )){
          goto X60Qsc_493;}}}
    else {
      NB8 X60Qtc_497 = nimStrAtLe_0_sysvq0asl(nm_5, 0, (NC8)'h');
      if (X60Qtc_497){
        if (equalStrings_0_sysvq0asl(nm_5, (string_0_sysvq0asl){
          .bytes_0 = 1887004926u, .more_0 = (&strlit_0_I2254028527881297604_runot4689)}
        )){
          goto X60Qsc_491;}
        else if (equalStrings_0_sysvq0asl(nm_5, (string_0_sysvq0asl){
          .bytes_0 = 1869440766u, .more_0 = (&strlit_0_I2902005617748064841_runot4689)}
        )){
          goto X60Qsc_494;}}
      else {
        if (equalStrings_0_sysvq0asl(nm_5, (string_0_sysvq0asl){
          .bytes_0 = 2003791875u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_490;}
        else if (equalStrings_0_sysvq0asl(nm_5, (string_0_sysvq0asl){
          .bytes_0 = 1685024003u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_494;}}}
    goto X60Qsc_499;
    X60Qsc_490: ;
    NF64 X60Qx_1936 = pow(x_26, y_3);
    r_14 = X60Qx_1936;
    goto X60Qsc_498;
    X60Qsc_491: ;
    NF64 X60Qx_1937 = hypot(x_26, y_3);
    r_14 = X60Qx_1937;
    goto X60Qsc_498;
    X60Qsc_492: ;
    NF64 X60Qx_1938 = atan2(x_26, y_3);
    r_14 = X60Qx_1938;
    goto X60Qsc_498;
    X60Qsc_493: ;
    NF64 X60Qx_1939 = copysign(x_26, y_3);
    r_14 = X60Qx_1939;
    goto X60Qsc_498;
    X60Qsc_494: ;
    NF64 X60Qx_1940 = trunc(((NF64)(x_26 / y_3)));
    r_14 = ((NF64)(x_26 - ((NF64)(X60Qx_1940 * y_3))));
    goto X60Qsc_498;
    X60Qsc_499: ;
    X60Qsc_498: ;
    NI32 X60Qx_67;
    Value_0_valzr1t4f* X60Qx_1941 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    if ((*X60Qx_1941).kind_0 == 3){
      Value_0_valzr1t4f* X60Qx_1942 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      X60Qx_67 = (*X60Qx_1942).fbits_0;}
    else {
      X60Qx_67 = 64;}
    NI32 fb_1 = X60Qx_67;
    if (fb_1 == 32){
      r_14 = ((NF64)((NF32)r_14));}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1943 = vFloat_0_valzr1t4f(r_14, fb_1);
    result_76 = X60Qx_1943;
    nimStrDestroy(nm_5);}
  goto X60Qsc_441;
  X60Qsc_265: ;
  NI32 fi_0 = 0;
  NB8 toErr_1 = NIM_FALSE;
  NB8 X60Qx_1944;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1945 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1944 = ((*X60Qx_1945).kind_0 == 16);}
  else {
    X60Qx_1944 = NIM_FALSE;}
  if (X60Qx_1944){
    Value_0_valzr1t4f* X60Qx_1946 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    toErr_1 = (*X60Qx_1946).toErr_0;
    fi_0 = 1;}
  Value_0_valzr1t4f X60Qx_68;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_68));
  NI32 X60Qx_1947 = len_3_I4n9kvq_intzsnzax(args_4);
  if (fi_0 < X60Qx_1947){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_68));
    Value_0_valzr1t4f* X60Qx_1948 = getQ_7_Ine8yq71_intzsnzax(args_4, fi_0);
    Value_0_valzr1t4f X60QconstRefTemp_230 = (*X60Qx_1948);
    Value_0_valzr1t4f X60Qx_1949 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_230));
    X60Qx_68 = X60Qx_1949;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_68));
    Value_0_valzr1t4f X60Qx_1950 = vNil_0_valzr1t4f();
    X60Qx_68 = X60Qx_1950;}
  Value_0_valzr1t4f fmtv_0 = X60Qx_68;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_68));
  if (fmtv_0.kind_0 == 13){
    string_0_sysvq0asl X60Qtmp_272 = ptrToString_0_runot4689((&fmtv_0));
    Value_0_valzr1t4f X60Qlhs_271 = vStr_0_valzr1t4f(X60Qtmp_272);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fmtv_0));
    fmtv_0 = X60Qlhs_271;
    nimStrDestroy(X60Qtmp_272);}
  NB8 X60Qx_1951;
  NI32 X60Qx_1952 = len_3_I4n9kvq_intzsnzax(args_4);
  if (fi_0 < X60Qx_1952){
    X60Qx_1951 = (fmtv_0.kind_0 == 6);}
  else {
    X60Qx_1951 = NIM_FALSE;}
  if (X60Qx_1951){
    seq_0_I50urnw_croph25r5 rest_0 = newSeqUninit_0_I8oufjc_croph25r5(0);
    NI32 i_59 = ((NI32)(fi_0 + 1));
    {
      while (NIM_TRUE){
        NI32 X60Qx_1953 = len_3_I4n9kvq_intzsnzax(args_4);
        if (i_59 < X60Qx_1953){
          Value_0_valzr1t4f* X60Qx_1954 = getQ_7_Ine8yq71_intzsnzax(args_4, i_59);
          if ((*X60Qx_1954).kind_0 == 13){
            Value_0_valzr1t4f* X60Qx_1955 = getQ_7_Ine8yq71_intzsnzax(args_4, i_59);
            Value_0_valzr1t4f X60QconstRefTemp_231 = (*X60Qx_1955);
            string_0_sysvq0asl X60Qtmp_273 = ptrToString_0_runot4689((&X60QconstRefTemp_231));
            Value_0_valzr1t4f X60Qx_1956 = vStr_0_valzr1t4f(X60Qtmp_273);
            add_0_Itre92n_intzsnzax((&rest_0), X60Qx_1956);
            nimStrDestroy(X60Qtmp_273);}
          else {
            Value_0_valzr1t4f* X60Qx_1957 = getQ_7_Ine8yq71_intzsnzax(args_4, i_59);
            Value_0_valzr1t4f X60QconstRefTemp_232 = (*X60Qx_1957);
            Value_0_valzr1t4f X60Qx_1958 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_232));
            add_0_Itre92n_intzsnzax((&rest_0), X60Qx_1958);}
          inc_1_I6wjjge_aow2h993l1((&i_59));}
        else {
          break;}}}
    whileStmtLabel_45: ;
    string_0_sysvq0asl s_46 = cformat_0_natd5co251(fmtv_0.sval_0, rest_0);
    writeStr_0_natd5co251(sink_13, toErr_1, s_46);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    NI32 X60Qx_1959 = len_4_sysvq0asl(s_46);
    Value_0_valzr1t4f X60Qx_1960 = vInt_0_valzr1t4f(((NI64)X60Qx_1959), 64);
    result_76 = X60Qx_1960;
    nimStrDestroy(s_46);
    eQdestroy_1_Inxd7ue1_croph25r5(rest_0);}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fmtv_0));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_68));
  goto X60Qsc_441;
  X60Qsc_266: ;
  NB8 X60Qx_1961;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1962 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1961 = ((*X60Qx_1962).kind_0 == 3);}
  else {
    X60Qx_1961 = NIM_FALSE;}
  if (X60Qx_1961){
    Value_0_valzr1t4f* X60Qx_1963 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    NF64 x_27 = (*X60Qx_1963).fval_0;
    NI32 e_4 = 0;
    NF64 frac_0 = x_27;
    NB8 X60Qx_1964;
    NB8 X60Qx_1965;
    if ((!(x_27 == 0.0))){
      X60Qx_1965 = (x_27 == x_27);}
    else {
      X60Qx_1965 = NIM_FALSE;}
    if (X60Qx_1965){
      X60Qx_1964 = (((NF64)(x_27 - x_27)) == 0.0);}
    else {
      X60Qx_1964 = NIM_FALSE;}
    if (X60Qx_1964){
      NF64 X60Qx_69;
      if (x_27 < 0.0){
        X60Qx_69 = ((NF64)-x_27);}
      else {
        X60Qx_69 = x_27;}
      NF64 ax_0 = X60Qx_69;
      {
        while (1.0 <= ax_0){
          ax_0 = ((NF64)(ax_0 / 2.0));
          inc_1_I6wjjge_aow2h993l1((&e_4));}}
      whileStmtLabel_46: ;
      {
        while (ax_0 < 0.5){
          ax_0 = ((NF64)(ax_0 * 2.0));
          dec_1_I0nzoz91_aow7lb5cq1((&e_4));}}
      whileStmtLabel_47: ;
      NF64 X60Qx_70;
      if (x_27 < 0.0){
        X60Qx_70 = ((NF64)-ax_0);}
      else {
        X60Qx_70 = ax_0;}
      frac_0 = X60Qx_70;}
    Value_0_valzr1t4f* X60Qx_1966 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_233 = (*X60Qx_1966);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_14 = ptrCell_0_runot4689((&X60QconstRefTemp_233));
    if ((!(cell_14 == NIM_NIL))){
      Value_0_valzr1t4f* X60Qlhs_274 = (&(*cell_14).d_00.v_0);
      Value_0_valzr1t4f X60Qlhs_275 = vInt_0_valzr1t4f(((NI64)e_4), 64);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_274)));
      (*X60Qlhs_274) = X60Qlhs_275;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1967 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60Qx_1968 = vFloat_0_valzr1t4f(frac_0, (*X60Qx_1967).fbits_0);
    result_76 = X60Qx_1968;
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(cell_14);}
  goto X60Qsc_441;
  X60Qsc_267: ;
  NB8 X60Qx_1969;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1970 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1969 = ((*X60Qx_1970).kind_0 == 3);}
  else {
    X60Qx_1969 = NIM_FALSE;}
  if (X60Qx_1969){
    Value_0_valzr1t4f* X60Qx_1971 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    NF64 r_15 = (*X60Qx_1971).fval_0;
    Value_0_valzr1t4f* X60Qx_1972 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_234 = (*X60Qx_1972);
    NI64 X60Qx_1973 = asInt_0_valzr1t4f((&X60QconstRefTemp_234));
    NI32 e_5 = ((NI32)X60Qx_1973);
    {
      while (0 < e_5){
        r_15 = ((NF64)(r_15 * 2.0));
        dec_1_I0nzoz91_aow7lb5cq1((&e_5));}}
    whileStmtLabel_48: ;
    {
      while (e_5 < 0){
        r_15 = ((NF64)(r_15 / 2.0));
        inc_1_I6wjjge_aow2h993l1((&e_5));}}
    whileStmtLabel_49: ;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_1974 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60Qx_1975 = vFloat_0_valzr1t4f(r_15, (*X60Qx_1974).fbits_0);
    result_76 = X60Qx_1975;}
  goto X60Qsc_441;
  X60Qsc_268: ;
  NB8 X60Qx_1976;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1977 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1976 = ((*X60Qx_1977).kind_0 == 3);}
  else {
    X60Qx_1976 = NIM_FALSE;}
  if (X60Qx_1976){
    Value_0_valzr1t4f* X60Qx_1978 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    if ((*X60Qx_1978).fbits_0 == 32){
      Value_0_valzr1t4f* X60Qx_1979 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      NF32 X60Qx_1980 = ((NF32)(*X60Qx_1979).fval_0);
      NU32 X60Qx_1981;
      copyMem_0_sysvq0asl((&X60Qx_1981), (&X60Qx_1980), sizeof(NU32));
      NU32 bits_1 = X60Qx_1981;
      NU32 exp_0 = ((NU32)(((NU32)(bits_1 >> ((NU32)23u))) & ((NU32)255u)));
      NU32 mant_0 = ((NU32)(bits_1 & ((NU32)8388607u)));
      if (exp_0 == ((NU32)255u)){
        NI64 X60Qx_71;
        if ((!(mant_0 == ((NU32)0u)))){
          X60Qx_71 = 0;}
        else {
          X60Qx_71 = 1;}
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1982 = vInt_0_valzr1t4f(((NI64)X60Qx_71), 64);
        result_76 = X60Qx_1982;}
      else {
        if (exp_0 == ((NU32)0u)){
          NI64 X60Qx_72;
          if (mant_0 == ((NU32)0u)){
            X60Qx_72 = 2;}
          else {
            X60Qx_72 = 3;}
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
          Value_0_valzr1t4f X60Qx_1983 = vInt_0_valzr1t4f(((NI64)X60Qx_72), 64);
          result_76 = X60Qx_1983;}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
          Value_0_valzr1t4f X60Qx_1984 = vInt_0_valzr1t4f(((NI64)4), 64);
          result_76 = X60Qx_1984;}}}
    else {
      Value_0_valzr1t4f* X60Qx_1985 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      NF64 X60Qx_1986 = (*X60Qx_1985).fval_0;
      NU64 X60Qx_1987;
      copyMem_0_sysvq0asl((&X60Qx_1987), (&X60Qx_1986), sizeof(NU64));
      NU64 bits_2 = X60Qx_1987;
      NU64 exp_1 = ((NU64)(((NU64)(bits_2 >> 52)) & ((NU64)2047u)));
      NU64 mant_1 = ((NU64)(bits_2 & ((NU64)4503599627370495ull)));
      if (exp_1 == ((NU64)2047u)){
        NI64 X60Qx_73;
        if ((!(mant_1 == ((NU64)0u)))){
          X60Qx_73 = 0;}
        else {
          X60Qx_73 = 1;}
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f X60Qx_1988 = vInt_0_valzr1t4f(((NI64)X60Qx_73), 64);
        result_76 = X60Qx_1988;}
      else {
        if (exp_1 == ((NU64)0u)){
          NI64 X60Qx_74;
          if (mant_1 == ((NU64)0u)){
            X60Qx_74 = 2;}
          else {
            X60Qx_74 = 3;}
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
          Value_0_valzr1t4f X60Qx_1989 = vInt_0_valzr1t4f(((NI64)X60Qx_74), 64);
          result_76 = X60Qx_1989;}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
          Value_0_valzr1t4f X60Qx_1990 = vInt_0_valzr1t4f(((NI64)4), 64);
          result_76 = X60Qx_1990;}}}}
  goto X60Qsc_441;
  X60Qsc_269: ;
  NB8 X60Qx_1991;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1992 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1991 = ((*X60Qx_1992).kind_0 == 3);}
  else {
    X60Qx_1991 = NIM_FALSE;}
  if (X60Qx_1991){
    Value_0_valzr1t4f* X60Qx_1993 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    NF64 X60Qx_1994 = (*X60Qx_1993).fval_0;
    NU64 X60Qx_1995;
    copyMem_0_sysvq0asl((&X60Qx_1995), (&X60Qx_1994), sizeof(NU64));
    NU64 bits_3 = X60Qx_1995;
    NI64 X60Qx_75;
    if ((!(((NU64)(bits_3 >> 63)) == ((NU64)0u)))){
      X60Qx_75 = 1;}
    else {
      X60Qx_75 = 0;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_1996 = vInt_0_valzr1t4f(((NI64)X60Qx_75), 64);
    result_76 = X60Qx_1996;}
  goto X60Qsc_441;
  X60Qsc_270: ;
  NB8 X60Qx_1997;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_1998 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    X60Qx_1997 = ((*X60Qx_1998).kind_0 == 3);}
  else {
    X60Qx_1997 = NIM_FALSE;}
  if (X60Qx_1997){
    Value_0_valzr1t4f* X60Qx_1999 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    NF64 x_28 = (*X60Qx_1999).fval_0;
    NI64 X60Qx_76;
    if ((!(x_28 == x_28))){
      X60Qx_76 = 1;}
    else {
      X60Qx_76 = 0;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2000 = vInt_0_valzr1t4f(((NI64)X60Qx_76), 64);
    result_76 = X60Qx_2000;}
  goto X60Qsc_441;
  X60Qsc_271: ;
  NB8 X60Qx_2001;
  if (1 <= args_4.len_0){
    NB8 X60Qx_2002;
    Value_0_valzr1t4f* X60Qx_2003 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    if ((*X60Qx_2003).kind_0 == 3){
      X60Qx_2002 = NIM_TRUE;}
    else {
      Value_0_valzr1t4f* X60Qx_2004 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      X60Qx_2002 = ((*X60Qx_2004).kind_0 == 0);}
    X60Qx_2001 = X60Qx_2002;}
  else {
    X60Qx_2001 = NIM_FALSE;}
  if (X60Qx_2001){
    NF64 X60Qx_77;
    Value_0_valzr1t4f* X60Qx_2005 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    if ((*X60Qx_2005).kind_0 == 3){
      Value_0_valzr1t4f* X60Qx_2006 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      X60Qx_77 = (*X60Qx_2006).fval_0;}
    else {
      X60Qx_77 = 0.0;}
    NF64 f_8 = X60Qx_77;
    NI32 modeSel_0 = 0;
    NB8 X60Qx_2007;
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_2008 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      X60Qx_2007 = ((*X60Qx_2008).kind_0 == 7);}
    else {
      X60Qx_2007 = NIM_FALSE;}
    if (X60Qx_2007){
      Value_0_valzr1t4f* X60Qx_2009 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      modeSel_0 = (*X60Qx_2009).eord_0;}
    NI32 prec_0 = 16;
    if (3 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_2010 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
      Value_0_valzr1t4f X60QconstRefTemp_235 = (*X60Qx_2010);
      NI64 X60Qx_2011 = asInt_0_valzr1t4f((&X60QconstRefTemp_235));
      prec_0 = ((NI32)X60Qx_2011);}
    if (prec_0 < -1){
      prec_0 = -1;}
    else {
      if (32 < prec_0){
        prec_0 = 32;}}
    NC8 sep_0 = (NC8)'.';
    NB8 X60Qx_2012;
    if (4 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_2013 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
      X60Qx_2012 = ((*X60Qx_2013).kind_0 == 5);}
    else {
      X60Qx_2012 = NIM_FALSE;}
    if (X60Qx_2012){
      Value_0_valzr1t4f* X60Qx_2014 = getQ_7_Ine8yq71_intzsnzax(args_4, 3);
      sep_0 = (*X60Qx_2014).cval_0;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    string_0_sysvq0asl X60Qtmp_276 = fmtBigFloat_0_flowmlewz(f_8, modeSel_0, prec_0, sep_0);
    Value_0_valzr1t4f X60Qx_2015 = vStr_0_valzr1t4f(X60Qtmp_276);
    result_76 = X60Qx_2015;
    nimStrDestroy(X60Qtmp_276);}
  goto X60Qsc_441;
  X60Qsc_272: ;
  if (1 <= args_4.len_0){
    string_0_sysvq0asl buf_3 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    Value_0_valzr1t4f* X60Qx_2016 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_236 = (*X60Qx_2016);
    Value_0_valzr1t4f v_44 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_236));
    NB8 X60Qx_2017;
    if (v_44.kind_0 == 13){
      X60Qx_2017 = (!(v_44.loc_0 == NIM_NIL));}
    else {
      X60Qx_2017 = NIM_FALSE;}
    if (X60Qx_2017){
      Value_0_valzr1t4f X60Qlhs_277 = v_44;
      Value_0_valzr1t4f X60Qx_2018 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_44.loc_0).d_00.v_0));
      v_44 = X60Qx_2018;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_277));}
    switch (v_44.kind_0){
      case 6:
      {
        {
          openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_8 = toOpenArray_2_sysvq0asl((&v_44.sval_0));
          NI32 X60Qlf_9 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_2019 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_8);
              if (X60Qlf_9 < X60Qx_2019){
                {
                  NC8* X60Qii_52 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_8, X60Qlf_9);
                  if ((*X60Qii_52) == (NC8)'\000'){
                    goto forStmtLabel_50;}
                  add_1_sysvq0asl((&buf_3), (*X60Qii_52));}
                inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}
              else {
                break;}}}
          whileStmtLabel_51: ;}
        forStmtLabel_50: ;}
      break;
      case 9:
      {
        if ((!(v_44.arr_0 == NIM_NIL))){
          {
            openArray_0_Iu2js7k_intzsnzax X60Qlf_10 = toOpenArray_1_Ij5ojb01_intzsnzax((*v_44.arr_0).d_00.elems_0);
            NI32 X60Qlf_11 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_2020 = len_6_Ip8y5v7_intzsnzax(X60Qlf_10);
                if (X60Qlf_11 < X60Qx_2020){
                  {
                    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qii_55 = getQ_10_Ik17lqr_intzsnzax(X60Qlf_10, X60Qlf_11);
                    NB8 X60Qx_2021;
                    if ((!((*(*X60Qii_55)).d_00.v_0.kind_0 == 5))){
                      X60Qx_2021 = NIM_TRUE;}
                    else {
                      X60Qx_2021 = ((*(*X60Qii_55)).d_00.v_0.cval_0 == (NC8)'\000');}
                    if (X60Qx_2021){
                      goto forStmtLabel_53;}
                    add_1_sysvq0asl((&buf_3), (*(*X60Qii_55)).d_00.v_0.cval_0);}
                  inc_1_I6wjjge_aow2h993l1((&X60Qlf_11));}
                else {
                  break;}}}
            whileStmtLabel_54: ;}
          forStmtLabel_53: ;}}
      break;
      default:
      {
        }
      break;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    NF64 X60Qx_2022 = parseBigFloat_0_flowmlewz(buf_3);
    Value_0_valzr1t4f X60Qx_2023 = vFloat_0_valzr1t4f(X60Qx_2022, 64);
    result_76 = X60Qx_2023;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_44));
    nimStrDestroy(buf_3);}
  goto X60Qsc_441;
  X60Qsc_273: ;
  if (3 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_2024 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_237 = (*X60Qx_2024);
    NI64 X60Qx_2025 = asInt_0_valzr1t4f((&X60QconstRefTemp_237));
    NI32 n_20 = ((NI32)X60Qx_2025);
    NB8 X60Qx_2026;
    if (0 < n_20){
      openArray_0_I2902h9_intzsnzax X60Qx_2027 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
      NB8 X60Qx_2028 = nilMemOperand_0_runot4689(X60Qx_2027, 2);
      X60Qx_2026 = X60Qx_2028;}
    else {
      X60Qx_2026 = NIM_FALSE;}
    if (X60Qx_2026){
      failNilMem_0_runot4689(sink_13, (string_0_sysvq0asl){
        .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I16513080964259093980_flaksyopx1)}
      );}
    else {
      Value_0_valzr1t4f* X60Qx_2029 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_238 = (*X60Qx_2029);
      Value_0_valzr1t4f* X60Qx_2030 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_239 = (*X60Qx_2030);
      flCopy_0_flaksyopx1((&X60QconstRefTemp_238), (&X60QconstRefTemp_239), n_20);}}
  goto X60Qsc_441;
  X60Qsc_274: ;
  if (3 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_2031 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_240 = (*X60Qx_2031);
    NI64 X60Qx_2032 = asInt_0_valzr1t4f((&X60QconstRefTemp_240));
    NI32 n_21 = ((NI32)X60Qx_2032);
    NB8 X60Qx_2033;
    if (0 < n_21){
      openArray_0_I2902h9_intzsnzax X60Qx_2034 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
      NB8 X60Qx_2035 = nilMemOperand_0_runot4689(X60Qx_2034, 2);
      X60Qx_2033 = X60Qx_2035;}
    else {
      X60Qx_2033 = NIM_FALSE;}
    if (X60Qx_2033){
      failNilMem_0_runot4689(sink_13, (string_0_sysvq0asl){
        .bytes_0 = 1987014142u, .more_0 = (&strlit_0_I15154933186756103481_flaksyopx1)}
      );}
    else {
      Value_0_valzr1t4f* X60Qx_2036 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_241 = (*X60Qx_2036);
      Value_0_valzr1t4f* X60Qx_2037 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_242 = (*X60Qx_2037);
      flMove_0_flaksyopx1((&X60QconstRefTemp_241), (&X60QconstRefTemp_242), n_21);}}
  goto X60Qsc_441;
  X60Qsc_275: ;
  if (2 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_2038 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_243 = (*X60Qx_2038);
    NI64 X60Qx_2039 = asInt_0_valzr1t4f((&X60QconstRefTemp_243));
    NI32 n_22 = ((NI32)X60Qx_2039);
    NB8 X60Qx_2040;
    if (0 < n_22){
      openArray_0_I2902h9_intzsnzax X60Qx_2041 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
      NB8 X60Qx_2042 = nilMemOperand_0_runot4689(X60Qx_2041, 1);
      X60Qx_2040 = X60Qx_2042;}
    else {
      X60Qx_2040 = NIM_FALSE;}
    if (X60Qx_2040){
      failNilMem_0_runot4689(sink_13, (string_0_sysvq0asl){
        .bytes_0 = 1919253246u, .more_0 = (&strlit_0_I14137437451056432656_flaksyopx1)}
      );}
    else {
      Value_0_valzr1t4f* X60Qx_2043 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
      Value_0_valzr1t4f X60QconstRefTemp_244 = (*X60Qx_2043);
      flZero_0_flaksyopx1((&X60QconstRefTemp_244), n_22);}}
  goto X60Qsc_441;
  X60Qsc_276: ;
  if (3 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_2044 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
    Value_0_valzr1t4f X60QconstRefTemp_245 = (*X60Qx_2044);
    NI64 X60Qx_2045 = asInt_0_valzr1t4f((&X60QconstRefTemp_245));
    NI32 n_23 = ((NI32)X60Qx_2045);
    if (n_23 <= 0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_2046 = vBool_0_valzr1t4f(NIM_TRUE);
      result_76 = X60Qx_2046;}
    else {
      openArray_0_I2902h9_intzsnzax X60Qx_2047 = toOpenArray_1_Ik4sb7f_intzsnzax(args_4);
      NB8 X60Qx_2048 = nilMemOperand_0_runot4689(X60Qx_2047, 2);
      if (X60Qx_2048){
        failNilMem_0_runot4689(sink_13, (string_0_sysvq0asl){
          .bytes_0 = 1970365950u, .more_0 = (&strlit_0_I14385440250011608213_flaksyopx1)}
        );}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
        Value_0_valzr1t4f* X60Qx_2049 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
        Value_0_valzr1t4f X60QconstRefTemp_246 = (*X60Qx_2049);
        Value_0_valzr1t4f* X60Qx_2050 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
        Value_0_valzr1t4f X60QconstRefTemp_247 = (*X60Qx_2050);
        NB8 X60Qx_2051 = flEqual_0_flaksyopx1((&X60QconstRefTemp_246), (&X60QconstRefTemp_247), n_23);
        Value_0_valzr1t4f X60Qx_2052 = vBool_0_valzr1t4f(X60Qx_2051);
        result_76 = X60Qx_2052;}}}
  goto X60Qsc_441;
  X60Qsc_277: ;
  if (1 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_2053 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_248 = (*X60Qx_2053);
    NI64 X60Qx_2054 = asInt_0_valzr1t4f((&X60QconstRefTemp_248));
    Value_0_valzr1t4f X60Qx_2055 = flAllocRegion_0_flaksyopx1(((NI32)X60Qx_2054), NIM_TRUE);
    result_76 = X60Qx_2055;}
  goto X60Qsc_441;
  X60Qsc_278: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  Value_0_valzr1t4f X60Qtmp_278 = vNil_0_valzr1t4f();
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_136 = newCell_0_valzr1t4f((&X60Qtmp_278));
  result_76 = (Value_0_valzr1t4f){
    .kind_0 = 12, .rf_0 = X60Qx_136}
  ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_278));
  goto X60Qsc_441;
  X60Qsc_279: ;
  if (1 <= args_4.len_0){
    Value_0_valzr1t4f* X60Qx_2056 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_249 = (*X60Qx_2056);
    flFree_0_flaksyopx1((&X60QconstRefTemp_249));}
  goto X60Qsc_441;
  X60Qsc_280: ;
  if (2 <= args_4.len_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f* X60Qx_2057 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
    Value_0_valzr1t4f X60QconstRefTemp_250 = (*X60Qx_2057);
    Value_0_valzr1t4f* X60Qx_2058 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_251 = (*X60Qx_2058);
    NI64 X60Qx_2059 = asInt_0_valzr1t4f((&X60QconstRefTemp_251));
    Value_0_valzr1t4f X60Qx_2060 = flRealloc_0_flaksyopx1((&X60QconstRefTemp_250), ((NI32)X60Qx_2059));
    result_76 = X60Qx_2060;}
  goto X60Qsc_441;
  X60Qsc_281: ;
  Value_0_valzr1t4f* X60Qx_2061 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_252 = (*X60Qx_2061);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_27 = intSlotCell_0_runot4689((&X60QconstRefTemp_252));
  if ((!(c_27 == NIM_NIL))){
    Value_0_valzr1t4f* X60Qlhs_279 = (&(*c_27).d_00.v_0);
    NI64 X60Qx_2062 = asInt_0_valzr1t4f((&(*c_27).d_00.v_0));
    Value_0_valzr1t4f X60Qlhs_280 = vInt_0_valzr1t4f(((NI64)(((NI64)X60Qx_2062) + ((NI64)1))), 64);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_279)));
    (*X60Qlhs_279) = X60Qlhs_280;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_27);
  goto X60Qsc_441;
  X60Qsc_282: ;
  Value_0_valzr1t4f* X60Qx_2063 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_253 = (*X60Qx_2063);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_28 = intSlotCell_0_runot4689((&X60QconstRefTemp_253));
  if ((!(c_28 == NIM_NIL))){
    NI64 X60Qx_2064 = asInt_0_valzr1t4f((&(*c_28).d_00.v_0));
    NI64 n_24 = ((NI64)(((NI64)X60Qx_2064) - ((NI64)1)));
    Value_0_valzr1t4f* X60Qlhs_281 = (&(*c_28).d_00.v_0);
    Value_0_valzr1t4f X60Qlhs_282 = vInt_0_valzr1t4f(n_24, 64);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_281)));
    (*X60Qlhs_281) = X60Qlhs_282;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2065 = vBool_0_valzr1t4f((n_24 < ((NI64)0)));
    result_76 = X60Qx_2065;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2066 = vBool_0_valzr1t4f(NIM_FALSE);
    result_76 = X60Qx_2066;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_28);
  goto X60Qsc_441;
  X60Qsc_283: ;
  Value_0_valzr1t4f* X60Qx_2067 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_254 = (*X60Qx_2067);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_29 = intSlotCell_0_runot4689((&X60QconstRefTemp_254));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
  NB8 X60Qx_2068;
  if ((!(c_29 == NIM_NIL))){
    NI64 X60Qx_2069 = asInt_0_valzr1t4f((&(*c_29).d_00.v_0));
    X60Qx_2068 = (((NI64)X60Qx_2069) == ((NI64)0));}
  else {
    X60Qx_2068 = NIM_FALSE;}
  Value_0_valzr1t4f X60Qx_2070 = vBool_0_valzr1t4f(X60Qx_2068);
  result_76 = X60Qx_2070;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_29);
  goto X60Qsc_441;
  X60Qsc_284: ;
  Value_0_valzr1t4f* X60Qx_2071 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_255 = (*X60Qx_2071);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_30 = intSlotCell_0_runot4689((&X60QconstRefTemp_255));
  if ((!(c_30 == NIM_NIL))){
    NI64 X60Qx_78;
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_2072 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_256 = (*X60Qx_2072);
      NI64 X60Qx_2073 = asInt_0_valzr1t4f((&X60QconstRefTemp_256));
      X60Qx_78 = ((NI64)X60Qx_2073);}
    else {
      X60Qx_78 = ((NI64)0);}
    Value_0_valzr1t4f* X60Qlhs_283 = (&(*c_30).d_00.v_0);
    NI64 X60Qx_2074 = asInt_0_valzr1t4f((&(*c_30).d_00.v_0));
    Value_0_valzr1t4f X60Qlhs_284 = vInt_0_valzr1t4f(((NI64)(((NI64)X60Qx_2074) + X60Qx_78)), 64);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_283)));
    (*X60Qlhs_283) = X60Qlhs_284;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2075 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_30).d_00.v_0));
    result_76 = X60Qx_2075;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_30);
  goto X60Qsc_441;
  X60Qsc_285: ;
  Value_0_valzr1t4f* X60Qx_2076 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_257 = (*X60Qx_2076);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_31 = intSlotCell_0_runot4689((&X60QconstRefTemp_257));
  if ((!(c_31 == NIM_NIL))){
    NI64 X60Qx_79;
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_2077 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_258 = (*X60Qx_2077);
      NI64 X60Qx_2078 = asInt_0_valzr1t4f((&X60QconstRefTemp_258));
      X60Qx_79 = ((NI64)X60Qx_2078);}
    else {
      X60Qx_79 = ((NI64)0);}
    Value_0_valzr1t4f* X60Qlhs_285 = (&(*c_31).d_00.v_0);
    NI64 X60Qx_2079 = asInt_0_valzr1t4f((&(*c_31).d_00.v_0));
    Value_0_valzr1t4f X60Qlhs_286 = vInt_0_valzr1t4f(((NI64)(((NI64)X60Qx_2079) - X60Qx_79)), 64);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_285)));
    (*X60Qlhs_285) = X60Qlhs_286;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2080 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_31).d_00.v_0));
    result_76 = X60Qx_2080;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_31);
  goto X60Qsc_441;
  X60Qsc_286: ;
  Value_0_valzr1t4f* X60Qx_2081 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_259 = (*X60Qx_2081);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_32 = intSlotCell_0_runot4689((&X60QconstRefTemp_259));
  if ((!(c_32 == NIM_NIL))){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2082 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_32).d_00.v_0));
    result_76 = X60Qx_2082;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2083 = vInt_0_valzr1t4f(((NI64)0), 64);
    result_76 = X60Qx_2083;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_32);
  goto X60Qsc_441;
  X60Qsc_287: ;
  Value_0_valzr1t4f* X60Qx_2084 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_260 = (*X60Qx_2084);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_33 = intSlotCell_0_runot4689((&X60QconstRefTemp_260));
  NB8 X60Qx_2085;
  if ((!(c_33 == NIM_NIL))){
    X60Qx_2085 = (2 <= args_4.len_0);}
  else {
    X60Qx_2085 = NIM_FALSE;}
  if (X60Qx_2085){
    Value_0_valzr1t4f* X60Qlhs_287 = (&(*c_33).d_00.v_0);
    Value_0_valzr1t4f* X60Qx_2086 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_261 = (*X60Qx_2086);
    NI64 X60Qx_2087 = asInt_0_valzr1t4f((&X60QconstRefTemp_261));
    Value_0_valzr1t4f X60Qlhs_288 = vInt_0_valzr1t4f(((NI64)X60Qx_2087), 64);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_287)));
    (*X60Qlhs_287) = X60Qlhs_288;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_33);
  goto X60Qsc_441;
  X60Qsc_288: ;
  Value_0_valzr1t4f* X60Qx_2088 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_262 = (*X60Qx_2088);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_34 = intSlotCell_0_runot4689((&X60QconstRefTemp_262));
  if ((!(c_34 == NIM_NIL))){
    NI64 X60Qx_2089 = asInt_0_valzr1t4f((&(*c_34).d_00.v_0));
    NI64 old_0 = ((NI64)X60Qx_2089);
    NI64 X60Qx_80;
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_2090 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_263 = (*X60Qx_2090);
      NI64 X60Qx_2091 = asInt_0_valzr1t4f((&X60QconstRefTemp_263));
      X60Qx_80 = ((NI64)X60Qx_2091);}
    else {
      X60Qx_80 = ((NI64)0);}
    Value_0_valzr1t4f* X60Qlhs_289 = (&(*c_34).d_00.v_0);
    Value_0_valzr1t4f X60Qlhs_290 = vInt_0_valzr1t4f(((NI64)(old_0 + X60Qx_80)), 64);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_289)));
    (*X60Qlhs_289) = X60Qlhs_290;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2092 = vInt_0_valzr1t4f(old_0, 64);
    result_76 = X60Qx_2092;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2093 = vInt_0_valzr1t4f(((NI64)0), 64);
    result_76 = X60Qx_2093;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_34);
  goto X60Qsc_441;
  X60Qsc_289: ;
  Value_0_valzr1t4f* X60Qx_2094 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_264 = (*X60Qx_2094);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_35 = intSlotCell_0_runot4689((&X60QconstRefTemp_264));
  if ((!(c_35 == NIM_NIL))){
    NI64 X60Qx_2095 = asInt_0_valzr1t4f((&(*c_35).d_00.v_0));
    NI64 old_1 = ((NI64)X60Qx_2095);
    NI64 X60Qx_81;
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qx_2096 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_265 = (*X60Qx_2096);
      NI64 X60Qx_2097 = asInt_0_valzr1t4f((&X60QconstRefTemp_265));
      X60Qx_81 = ((NI64)X60Qx_2097);}
    else {
      X60Qx_81 = ((NI64)0);}
    Value_0_valzr1t4f* X60Qlhs_291 = (&(*c_35).d_00.v_0);
    Value_0_valzr1t4f X60Qlhs_292 = vInt_0_valzr1t4f(((NI64)(old_1 - X60Qx_81)), 64);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_291)));
    (*X60Qlhs_291) = X60Qlhs_292;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2098 = vInt_0_valzr1t4f(old_1, 64);
    result_76 = X60Qx_2098;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2099 = vInt_0_valzr1t4f(((NI64)0), 64);
    result_76 = X60Qx_2099;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_35);
  goto X60Qsc_441;
  X60Qsc_290: ;
  Value_0_valzr1t4f* X60Qx_2100 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_266 = (*X60Qx_2100);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_36 = intSlotCell_0_runot4689((&X60QconstRefTemp_266));
  if ((!(c_36 == NIM_NIL))){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2101 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_36).d_00.v_0));
    result_76 = X60Qx_2101;
    if (2 <= args_4.len_0){
      Value_0_valzr1t4f* X60Qlhs_293 = (&(*c_36).d_00.v_0);
      Value_0_valzr1t4f* X60Qx_2102 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
      Value_0_valzr1t4f X60QconstRefTemp_267 = (*X60Qx_2102);
      NI64 X60Qx_2103 = asInt_0_valzr1t4f((&X60QconstRefTemp_267));
      Value_0_valzr1t4f X60Qlhs_294 = vInt_0_valzr1t4f(((NI64)X60Qx_2103), 64);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_293)));
      (*X60Qlhs_293) = X60Qlhs_294;}}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2104 = vInt_0_valzr1t4f(((NI64)0), 64);
    result_76 = X60Qx_2104;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_36);
  goto X60Qsc_441;
  X60Qsc_291: ;
  Value_0_valzr1t4f* X60Qx_2105 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_268 = (*X60Qx_2105);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_37 = intSlotCell_0_runot4689((&X60QconstRefTemp_268));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_82;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&X60Qx_82));
  if (2 <= args_4.len_0){
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qx_82);
    Value_0_valzr1t4f* X60Qx_2106 = getQ_7_Ine8yq71_intzsnzax(args_4, 1);
    Value_0_valzr1t4f X60QconstRefTemp_269 = (*X60Qx_2106);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_2107 = intSlotCell_0_runot4689((&X60QconstRefTemp_269));
    X60Qx_82 = X60Qx_2107;}
  else {
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qx_82);
    X60Qx_82 = NIM_NIL;}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* e_6 = X60Qx_82;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689((&X60Qx_82));
  NB8 X60Qx_2108;
  if ((!(c_37 == NIM_NIL))){
    X60Qx_2108 = (!(e_6 == NIM_NIL));}
  else {
    X60Qx_2108 = NIM_FALSE;}
  if (X60Qx_2108){
    NI64 X60Qx_2109 = asInt_0_valzr1t4f((&(*c_37).d_00.v_0));
    NI64 cur_1 = ((NI64)X60Qx_2109);
    NI64 X60Qx_2110 = asInt_0_valzr1t4f((&(*e_6).d_00.v_0));
    NI64 exp_2 = ((NI64)X60Qx_2110);
    if (cur_1 == exp_2){
      NI64 X60Qx_83;
      if (3 <= args_4.len_0){
        Value_0_valzr1t4f* X60Qx_2111 = getQ_7_Ine8yq71_intzsnzax(args_4, 2);
        Value_0_valzr1t4f X60QconstRefTemp_270 = (*X60Qx_2111);
        NI64 X60Qx_2112 = asInt_0_valzr1t4f((&X60QconstRefTemp_270));
        X60Qx_83 = ((NI64)X60Qx_2112);}
      else {
        X60Qx_83 = ((NI64)0);}
      Value_0_valzr1t4f* X60Qlhs_295 = (&(*c_37).d_00.v_0);
      Value_0_valzr1t4f X60Qlhs_296 = vInt_0_valzr1t4f(X60Qx_83, 64);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_295)));
      (*X60Qlhs_295) = X60Qlhs_296;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_2113 = vBool_0_valzr1t4f(NIM_TRUE);
      result_76 = X60Qx_2113;}
    else {
      Value_0_valzr1t4f* X60Qlhs_297 = (&(*e_6).d_00.v_0);
      Value_0_valzr1t4f X60Qlhs_298 = vInt_0_valzr1t4f(cur_1, 64);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_297)));
      (*X60Qlhs_297) = X60Qlhs_298;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
      Value_0_valzr1t4f X60Qx_2114 = vBool_0_valzr1t4f(NIM_FALSE);
      result_76 = X60Qx_2114;}}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2115 = vBool_0_valzr1t4f(NIM_FALSE);
    result_76 = X60Qx_2115;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(e_6);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qx_82);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_37);
  goto X60Qsc_441;
  X60Qsc_292: ;
  Value_0_valzr1t4f* X60Qx_2116 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_271 = (*X60Qx_2116);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_38 = intSlotCell_0_runot4689((&X60QconstRefTemp_271));
  if ((!(c_38 == NIM_NIL))){
    NI64 X60Qx_2117 = asInt_0_valzr1t4f((&(*c_38).d_00.v_0));
    NI64 old_2 = ((NI64)X60Qx_2117);
    Value_0_valzr1t4f* X60Qlhs_299 = (&(*c_38).d_00.v_0);
    Value_0_valzr1t4f X60Qlhs_300 = vInt_0_valzr1t4f(((NI64)1), 64);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_299)));
    (*X60Qlhs_299) = X60Qlhs_300;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2118 = vBool_0_valzr1t4f((!(old_2 == ((NI64)0))));
    result_76 = X60Qx_2118;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2119 = vBool_0_valzr1t4f(NIM_FALSE);
    result_76 = X60Qx_2119;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_38);
  goto X60Qsc_441;
  X60Qsc_293: ;
  Value_0_valzr1t4f* X60Qx_2120 = getQ_7_Ine8yq71_intzsnzax(args_4, 0);
  Value_0_valzr1t4f X60QconstRefTemp_272 = (*X60Qx_2120);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_39 = intSlotCell_0_runot4689((&X60QconstRefTemp_272));
  if ((!(c_39 == NIM_NIL))){
    Value_0_valzr1t4f* X60Qlhs_301 = (&(*c_39).d_00.v_0);
    Value_0_valzr1t4f X60Qlhs_302 = vInt_0_valzr1t4f(((NI64)0), 64);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_301)));
    (*X60Qlhs_301) = X60Qlhs_302;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(c_39);
  goto X60Qsc_441;
  X60Qsc_294: ;
  goto X60Qsc_441;
  X60Qsc_295: ;
  goto X60Qsc_441;
  X60Qsc_442: ;
  NB8 handled_0 = NIM_FALSE;
  if ((!(((void*)(*sink_13).d_00.hostCall_0) == NIM_NIL))){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_76));
    Value_0_valzr1t4f X60Qx_2121 = (*sink_13).d_00.hostCall_0((*sink_13).d_00.hostContext_0, name_6, args_4, (&handled_0));
    result_76 = X60Qx_2121;}
  if (handled_0){
    }
  else {
    NB8 X60Qx_2122 = isAllowedNoop_0_runot4689(name_6);
    if (X60Qx_2122){
      noteNoop_0_runot4689(name_6);
      reportUnported_0_runot4689(name_6, (string_0_sysvq0asl){
        .bytes_0 = 1952542462u, .more_0 = (&strlit_0_I8660272623971252417_runot4689)}
      );}
    else {
      failUnported_0_runot4689(sink_13, name_6, (string_0_sysvq0asl){
        .bytes_0 = 1952542462u, .more_0 = (&strlit_0_I3550780962399020617_runot4689)}
      );}}
  X60Qsc_441: ;
  return result_76;}
NB8 resultIsNeverNil_0_runot4689(string_0_sysvq0asl base_8){
  NB8 result_77;
  NB8 X60Qtc_501 = nimStrAtLe_0_sysvq0asl(base_8, 0, (NC8)'h');
  if (X60Qtc_501){
    NB8 X60Qtc_502 = nimStrAtLe_0_sysvq0asl(base_8, 0, (NC8)'@');
    if (X60Qtc_502){
      NB8 X60Qtc_503 = nimStrAtLe_0_sysvq0asl(base_8, 0, (NC8)'&');
      if (X60Qtc_503){
        if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
          .bytes_0 = 9729u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_500;}
        else if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
          .bytes_0 = 9217u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_500;}}
      else {
        NB8 X60Qtc_504 = nimStrAtLe_0_sysvq0asl(base_8, 0, (NC8)'<');
        if (X60Qtc_504){
          if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 15361u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_500;}
          else if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 4013058u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_500;}}
        else {
          if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 16385u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_500;}
          else if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 4013314u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_500;}}}}
    else {
      NB8 X60Qtc_505 = nimStrAtLe_0_sysvq0asl(base_8, 0, (NC8)'e');
      if (X60Qtc_505){
        if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
          .bytes_0 = 1684956670u, .more_0 = (&strlit_0_I16314744827495621298_runot4689)}
        )){
          goto X60Qsc_500;}
        else if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
          .bytes_0 = 1886216963u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_500;}}
      else {
        NB8 X60Qtc_506 = nimStrAtLe_0_sysvq0asl(base_8, 0, (NC8)'f');
        if (X60Qtc_506){
          if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I130460565633405389_runot4689)}
          )){
            goto X60Qsc_500;}
          else if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I15089905067781246666_runot4689)}
          )){
            goto X60Qsc_500;}}
        else {
          if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 1734961406u, .more_0 = (&strlit_0_I8566804573867139999_nimry5ra91)}
          )){
            goto X60Qsc_500;}}}}}
  else {
    NB8 X60Qtc_507 = nimStrAtLe_0_sysvq0asl(base_8, 3, (NC8)'S');
    if (X60Qtc_507){
      NB8 X60Qtc_508 = nimStrAtLe_0_sysvq0asl(base_8, 4, (NC8)'e');
      if (X60Qtc_508){
        NB8 X60Qtc_509 = nimStrAtLe_0_sysvq0asl(base_8, 6, (NC8)'O');
        if (X60Qtc_509){
          if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I17462820957681339184_runot4689)}
          )){
            goto X60Qsc_500;}}
        else {
          if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I3225684998187034911_intzsnzax)}
          )){
            goto X60Qsc_500;}
          else if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I11042971208590088895_intzsnzax)}
          )){
            goto X60Qsc_500;}}}
      else {
        if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
          .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I16799243069367891670_runot4689)}
        )){
          goto X60Qsc_500;}
        else if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
          .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I11206267958496974357_runot4689)}
        )){
          goto X60Qsc_500;}}}
    else {
      NB8 X60Qtc_510 = nimStrAtLe_0_sysvq0asl(base_8, 0, (NC8)'l');
      if (X60Qtc_510){
        if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
          .bytes_0 = 1852140547u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_500;}
        else if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
          .bytes_0 = 2003790851u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_500;}}
      else {
        NB8 X60Qtc_511 = nimStrAtLe_0_sysvq0asl(base_8, 0, (NC8)'s');
        if (X60Qtc_511){
          if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 1651864574u, .more_0 = (&strlit_0_I10580268758365513846_runot4689)}
          )){
            goto X60Qsc_500;}
          else if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I518833209856422221_runot4689)}
          )){
            goto X60Qsc_500;}}
        else {
          if (equalStrings_0_sysvq0asl(base_8, (string_0_sysvq0asl){
            .bytes_0 = 1332704510u, .more_0 = (&strlit_0_I13575662182318269178_runot4689)}
          )){
            goto X60Qsc_500;}}}}}
  goto X60Qsc_513;
  X60Qsc_500: ;
  result_77 = NIM_TRUE;
  goto X60Qsc_512;
  X60Qsc_513: ;
  result_77 = NIM_FALSE;
  X60Qsc_512: ;
  return result_77;}
Value_0_valzr1t4f nativeCall_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_14, string_0_sysvq0asl name_7, seq_0_I50urnw_croph25r5 args_5){
  Value_0_valzr1t4f result_78;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_78));
  NB8 X60Qx_2123 = perInterpPolicies_0_iop7yt73v();
  if (X60Qx_2123){
    X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* prev_0 = useIoPolicy_0_iop7yt73v((*sink_14).d_00.policy_0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_78));
    Value_0_valzr1t4f X60Qx_2124 = nativeArm_0_runot4689(sink_14, name_7, args_5);
    result_78 = X60Qx_2124;
    NB8 X60Qx_2125;
    NB8 X60Qx_2126;
    if (result_78.kind_0 == 0){
      X60Qx_2126 = (!(*sink_14).d_00.didQQuit_0);}
    else {
      X60Qx_2126 = NIM_FALSE;}
    if (X60Qx_2126){
      NB8 X60Qx_2127 = resultIsNeverNil_0_runot4689(name_7);
      X60Qx_2125 = X60Qx_2127;}
    else {
      X60Qx_2125 = NIM_FALSE;}
    if (X60Qx_2125){
      failShape_0_runot4689(sink_14, name_7, args_5);}
    X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* X60Qtmp_303 = useIoPolicy_0_iop7yt73v(prev_0);
    X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* X60Qx_2128 = X60Qtmp_303;
    eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_runot4689(X60Qtmp_303);
    eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_runot4689(prev_0);}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_78));
    Value_0_valzr1t4f X60Qx_2129 = nativeArm_0_runot4689(sink_14, name_7, args_5);
    result_78 = X60Qx_2129;
    NB8 X60Qx_2130;
    NB8 X60Qx_2131;
    if (result_78.kind_0 == 0){
      X60Qx_2131 = (!(*sink_14).d_00.didQQuit_0);}
    else {
      X60Qx_2131 = NIM_FALSE;}
    if (X60Qx_2131){
      NB8 X60Qx_2132 = resultIsNeverNil_0_runot4689(name_7);
      X60Qx_2130 = X60Qx_2132;}
    else {
      X60Qx_2130 = NIM_FALSE;}
    if (X60Qx_2130){
      failShape_0_runot4689(sink_14, name_7, args_5);}}
  return result_78;}
Value_0_valzr1t4f libcConstVal_0_runot4689(string_0_sysvq0asl b_2, NB8* found_4){
  Value_0_valzr1t4f result_79;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  (*found_4) = NIM_TRUE;
  NB8 X60Qtc_686 = nimStrAtLe_0_sysvq0asl(b_2, 8, (NC8)'n');
  if (X60Qtc_686){
    NB8 X60Qtc_687 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'F');
    if (X60Qtc_687){
      NB8 X60Qtc_688 = nimStrAtLe_0_sysvq0asl(b_2, 8, (NC8)'N');
      if (X60Qtc_688){
        NB8 X60Qtc_689 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'F');
        if (X60Qtc_689){
          NB8 X60Qtc_690 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'U');
          if (X60Qtc_690){
            NB8 X60Qtc_691 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'C');
            if (X60Qtc_691){
              NB8 X60Qtc_692 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'A');
              if (X60Qtc_692){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1145128446u, .more_0 = (&strlit_0_I13521228324183726981_runot4689)}
                )){
                  goto X60Qsc_584;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1094927870u, .more_0 = (&strlit_0_I13213607251399513994_runot4689)}
                )){
                  goto X60Qsc_550;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1329808894u, .more_0 = (&strlit_0_I10078620631909322514_runot4689)}
                )){
                  goto X60Qsc_587;}}}
            else {
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1598439934u, .more_0 = (&strlit_0_I10443767956889305667_runot4689)}
              )){
                goto X60Qsc_612;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1598310142u, .more_0 = (&strlit_0_I4380987711265286239_runot4689)}
              )){
                goto X60Qsc_641;}}}
          else {
            NB8 X60Qtc_693 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'F');
            if (X60Qtc_693){
              NB8 X60Qtc_694 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'B');
              if (X60Qtc_694){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229014526u, .more_0 = (&strlit_0_I7771350034674712515_runot4689)}
                )){
                  goto X60Qsc_672;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229014526u, .more_0 = (&strlit_0_I12050149256530257920_runot4689)}
                )){
                  goto X60Qsc_674;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229014526u, .more_0 = (&strlit_0_I12873808100213791010_runot4689)}
                )){
                  goto X60Qsc_676;}}}
            else {
              NB8 X60Qtc_695 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'N');
              if (X60Qtc_695){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229014526u, .more_0 = (&strlit_0_I1202898303368581925_runot4689)}
                )){
                  goto X60Qsc_673;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229014526u, .more_0 = (&strlit_0_I16862582215469788300_runot4689)}
                )){
                  goto X60Qsc_678;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229014526u, .more_0 = (&strlit_0_I1773389152722915160_runot4689)}
                )){
                  goto X60Qsc_680;}}}}}
        else {
          NB8 X60Qtc_696 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'I');
          if (X60Qtc_696){
            NB8 X60Qtc_697 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'A');
            if (X60Qtc_697){
              NB8 X60Qtc_698 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'C');
              if (X60Qtc_698){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598636542u, .more_0 = (&strlit_0_I15484450220121022056_runot4689)}
                )){
                  goto X60Qsc_664;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598636542u, .more_0 = (&strlit_0_I17160939106385923572_runot4689)}
                )){
                  goto X60Qsc_665;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598636542u, .more_0 = (&strlit_0_I9655121365460891732_runot4689)}
                )){
                  goto X60Qsc_667;}}}
            else {
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1313424894u, .more_0 = (&strlit_0_I10749741470294450029_runot4689)}
              )){
                goto X60Qsc_552;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1330136574u, .more_0 = (&strlit_0_I204748838534382851_runot4689)}
              )){
                goto X60Qsc_593;}}}
          else {
            NB8 X60Qtc_699 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'O');
            if (X60Qtc_699){
              NB8 X60Qtc_700 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'N');
              if (X60Qtc_700){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1095648766u, .more_0 = (&strlit_0_I626075554773012147_runot4689)}
                )){
                  goto X60Qsc_561;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1162757630u, .more_0 = (&strlit_0_I3590701547663877830_runot4689)}
                )){
                  goto X60Qsc_586;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1464813054u, .more_0 = (&strlit_0_I7364463776597098673_runot4689)}
                )){
                  goto X60Qsc_594;}}}
            else {
              NB8 X60Qtc_701 = nimStrAtLe_0_sysvq0asl(b_2, 10, (NC8)'A');
              if (X60Qtc_701){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I7912715734078800859_runot4689)}
                )){
                  goto X60Qsc_659;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I4198327292561152411_runot4689)}
                )){
                  goto X60Qsc_660;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I1327145675017360827_runot4689)}
                )){
                  goto X60Qsc_661;}}}}}}
      else {
        NB8 X60Qtc_702 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'N');
        if (X60Qtc_702){
          NB8 X60Qtc_703 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'I');
          if (X60Qtc_703){
            NB8 X60Qtc_704 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'A');
            if (X60Qtc_704){
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1178682878u, .more_0 = (&strlit_0_I3700114206701234657_runot4689)}
              )){
                goto X60Qsc_582;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1145128446u, .more_0 = (&strlit_0_I13198638834565665639_runot4689)}
              )){
                goto X60Qsc_583;}}
            else {
              NB8 X60Qtc_705 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'A');
              if (X60Qtc_705){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598636542u, .more_0 = (&strlit_0_I11261879291153827405_runot4689)}
                )){
                  goto X60Qsc_666;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1329808894u, .more_0 = (&strlit_0_I15346413526716859885_runot4689)}
                )){
                  goto X60Qsc_551;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1329808894u, .more_0 = (&strlit_0_I9347374490907984536_runot4689)}
                )){
                  goto X60Qsc_592;}}}}
          else {
            NB8 X60Qtc_706 = nimStrAtLe_0_sysvq0asl(b_2, 5, (NC8)'O');
            if (X60Qtc_706){
              NB8 X60Qtc_707 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'O');
              if (X60Qtc_707){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1448035838u, .more_0 = (&strlit_0_I15677921475206071770_runot4689)}
                )){
                  goto X60Qsc_574;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1230259710u, .more_0 = (&strlit_0_I11457930569918428624_runot4689)}
                )){
                  goto X60Qsc_591;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I16616648354288951258_runot4689)}
                )){
                  goto X60Qsc_657;}}}
            else {
              NB8 X60Qtc_708 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'O');
              if (X60Qtc_708){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1347372542u, .more_0 = (&strlit_0_I9893293526153346610_runot4689)}
                )){
                  goto X60Qsc_581;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I17556606778065541191_runot4689)}
                )){
                  goto X60Qsc_656;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I13209058275940028340_runot4689)}
                )){
                  goto X60Qsc_662;}}}}}
        else {
          NB8 X60Qtc_709 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'S');
          if (X60Qtc_709){
            NB8 X60Qtc_710 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'N');
            if (X60Qtc_710){
              NB8 X60Qtc_711 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'A');
              if (X60Qtc_711){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598636542u, .more_0 = (&strlit_0_I2227035140242129764_runot4689)}
                )){
                  goto X60Qsc_663;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1162102270u, .more_0 = (&strlit_0_I11776152313751980820_runot4689)}
                )){
                  goto X60Qsc_577;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I15806131157789360951_runot4689)}
                )){
                  goto X60Qsc_579;}}}
            else {
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1380992510u, .more_0 = (&strlit_0_I8761593122721247282_runot4689)}
              )){
                goto X60Qsc_578;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1380992510u, .more_0 = (&strlit_0_I11678056797885678089_runot4689)}
              )){
                goto X60Qsc_580;}}}
          else {
            NB8 X60Qtc_712 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'I');
            if (X60Qtc_712){
              NB8 X60Qtc_713 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'A');
              if (X60Qtc_713){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229014526u, .more_0 = (&strlit_0_I16829864831926568729_runot4689)}
                )){
                  goto X60Qsc_677;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229014526u, .more_0 = (&strlit_0_I9182775675243303253_runot4689)}
                )){
                  goto X60Qsc_679;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1162757630u, .more_0 = (&strlit_0_I7746302189920450481_runot4689)}
                )){
                  goto X60Qsc_555;}}}
            else {
              NB8 X60Qtc_714 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'N');
              if (X60Qtc_714){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I13043036667978839918_runot4689)}
                )){
                  goto X60Qsc_564;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I16403450858519639669_runot4689)}
                )){
                  goto X60Qsc_595;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1331119614u, .more_0 = (&strlit_0_I4798278778889723231_runot4689)}
                )){
                  goto X60Qsc_529;}}}}}}}
    else {
      NB8 X60Qtc_715 = nimStrAtLe_0_sysvq0asl(b_2, 6, (NC8)'L');
      if (X60Qtc_715){
        NB8 X60Qtc_716 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'N');
        if (X60Qtc_716){
          NB8 X60Qtc_717 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'N');
          if (X60Qtc_717){
            NB8 X60Qtc_718 = nimStrAtLe_0_sysvq0asl(b_2, 5, (NC8)'E');
            if (X60Qtc_718){
              NB8 X60Qtc_719 = nimStrAtLe_0_sysvq0asl(b_2, 8, (NC8)'C');
              if (X60Qtc_719){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1346589950u, .more_0 = (&strlit_0_I6913423194599751370_runot4689)}
                )){
                  goto X60Qsc_628;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1346589950u, .more_0 = (&strlit_0_I8182183537059069841_runot4689)}
                )){
                  goto X60Qsc_626;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1346589950u, .more_0 = (&strlit_0_I9626116225094488163_runot4689)}
                )){
                  goto X60Qsc_627;}}}
            else {
              NB8 X60Qtc_720 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'I');
              if (X60Qtc_720){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1162758654u, .more_0 = (&strlit_0_I17583787354024638215_runot4689)}
                )){
                  goto X60Qsc_636;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1346589950u, .more_0 = (&strlit_0_I7249319940781528932_runot4689)}
                )){
                  goto X60Qsc_625;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598639870u, .more_0 = (&strlit_0_I5787969039729970751_runot4689)}
                )){
                  goto X60Qsc_670;}}}}
          else {
            NB8 X60Qtc_721 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'P');
            if (X60Qtc_721){
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1213485310u, .more_0 = (&strlit_0_I18167337230236686779_runot4689)}
              )){
                goto X60Qsc_557;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1314869246u, .more_0 = (&strlit_0_I17889022518531510231_runot4689)}
              )){
                goto X60Qsc_642;}}
            else {
              NB8 X60Qtc_722 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'R');
              if (X60Qtc_722){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I4344074165183380173_runot4689)}
                )){
                  goto X60Qsc_601;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I1000757519110562595_runot4689)}
                )){
                  goto X60Qsc_603;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I1870891164029464854_runot4689)}
                )){
                  goto X60Qsc_600;}}}}}
        else {
          NB8 X60Qtc_723 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'P');
          if (X60Qtc_723){
            NB8 X60Qtc_724 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'M');
            if (X60Qtc_724){
              NB8 X60Qtc_725 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'I');
              if (X60Qtc_725){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1448102398u, .more_0 = (&strlit_0_I11009998552320449210_runot4689)}
                )){
                  goto X60Qsc_624;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1162758654u, .more_0 = (&strlit_0_I5553058630802048398_runot4689)}
                )){
                  goto X60Qsc_635;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1196641790u, .more_0 = (&strlit_0_I11734112185704578351_runot4689)}
                )){
                  goto X60Qsc_610;}}}
            else {
              NB8 X60Qtc_726 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'N');
              if (X60Qtc_726){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598639870u, .more_0 = (&strlit_0_I16174996664107135480_runot4689)}
                )){
                  goto X60Qsc_668;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598639870u, .more_0 = (&strlit_0_I7037597850929843469_runot4689)}
                )){
                  goto X60Qsc_669;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1280266494u, .more_0 = (&strlit_0_I10809207772613252416_runot4689)}
                )){
                  goto X60Qsc_650;}}}}
          else {
            NB8 X60Qtc_727 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'L');
            if (X60Qtc_727){
              NB8 X60Qtc_728 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'C');
              if (X60Qtc_728){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1129272318u, .more_0 = (&strlit_0_I15800523363237382565_runot4689)}
                )){
                  goto X60Qsc_617;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1129272318u, .more_0 = (&strlit_0_I9240057488478669814_runot4689)}
                )){
                  goto X60Qsc_619;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1280267262u, .more_0 = (&strlit_0_I12664588953822526387_runot4689)}
                )){
                  goto X60Qsc_596;}}}
            else {
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I4226514502516112276_runot4689)}
              )){
                goto X60Qsc_599;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1430803454u, .more_0 = (&strlit_0_I13632876346895515917_runot4689)}
              )){
                goto X60Qsc_631;}}}}}
      else {
        NB8 X60Qtc_729 = nimStrAtLe_0_sysvq0asl(b_2, 5, (NC8)'R');
        if (X60Qtc_729){
          NB8 X60Qtc_730 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'O');
          if (X60Qtc_730){
            NB8 X60Qtc_731 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'I');
            if (X60Qtc_731){
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1095649790u, .more_0 = (&strlit_0_I17737170811934970191_runot4689)}
              )){
                goto X60Qsc_633;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1095649790u, .more_0 = (&strlit_0_I7090624206164100572_runot4689)}
              )){
                goto X60Qsc_634;}}
            else {
              NB8 X60Qtc_732 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'M');
              if (X60Qtc_732){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1196641790u, .more_0 = (&strlit_0_I6359826815753912034_runot4689)}
                )){
                  goto X60Qsc_609;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1196641790u, .more_0 = (&strlit_0_I8788901631926167309_runot4689)}
                )){
                  goto X60Qsc_611;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1130319870u, .more_0 = (&strlit_0_I9559849193963664254_runot4689)}
                )){
                  goto X60Qsc_643;}}}}
          else {
            NB8 X60Qtc_733 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'M');
            if (X60Qtc_733){
              NB8 X60Qtc_734 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'S');
              if (X60Qtc_734){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1129272318u, .more_0 = (&strlit_0_I9389307232129446377_runot4689)}
                )){
                  goto X60Qsc_618;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1297044478u, .more_0 = (&strlit_0_I2049951798581219970_runot4689)}
                )){
                  goto X60Qsc_632;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1129537534u, .more_0 = (&strlit_0_I18164877413073487427_runot4689)}
                )){
                  goto X60Qsc_556;}}}
            else {
              NB8 X60Qtc_735 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'C');
              if (X60Qtc_735){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598247934u, .more_0 = (&strlit_0_I15905776585326246364_runot4689)}
                )){
                  goto X60Qsc_556;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I2671533804468217520_runot4689)}
                )){
                  goto X60Qsc_602;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I10532456418562285465_runot4689)}
                )){
                  goto X60Qsc_606;}}}}}
        else {
          NB8 X60Qtc_736 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'N');
          if (X60Qtc_736){
            NB8 X60Qtc_737 = nimStrAtLe_0_sysvq0asl(b_2, 8, (NC8)'I');
            if (X60Qtc_737){
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1347439102u, .more_0 = (&strlit_0_I12281703296401441837_runot4689)}
              )){
                goto X60Qsc_620;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1347439102u, .more_0 = (&strlit_0_I1962864414267436350_runot4689)}
              )){
                goto X60Qsc_623;}}
            else {
              NB8 X60Qtc_738 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'I');
              if (X60Qtc_738){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1347439102u, .more_0 = (&strlit_0_I4171139148755867550_runot4689)}
                )){
                  goto X60Qsc_621;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1347439102u, .more_0 = (&strlit_0_I16984630673936295851_runot4689)}
                )){
                  goto X60Qsc_622;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598639870u, .more_0 = (&strlit_0_I15095837033020071043_runot4689)}
                )){
                  goto X60Qsc_671;}}}}
          else {
            NB8 X60Qtc_739 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'E');
            if (X60Qtc_739){
              NB8 X60Qtc_740 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'C');
              if (X60Qtc_740){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I6673179633149433259_runot4689)}
                )){
                  goto X60Qsc_605;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I6789973116114424194_runot4689)}
                )){
                  goto X60Qsc_597;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I17128670092080497032_runot4689)}
                )){
                  goto X60Qsc_604;}}}
            else {
              NB8 X60Qtc_741 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'S');
              if (X60Qtc_741){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1129272318u, .more_0 = (&strlit_0_I3857493931253010879_runot4689)}
                )){
                  goto X60Qsc_616;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I3149784073278903579_runot4689)}
                )){
                  goto X60Qsc_515;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I6033114792105624477_runot4689)}
                )){
                  goto X60Qsc_518;}}}}}}}}
  else {
    NB8 X60Qtc_742 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'M');
    if (X60Qtc_742){
      NB8 X60Qtc_743 = nimStrAtLe_0_sysvq0asl(b_2, 6, (NC8)'Y');
      if (X60Qtc_743){
        NB8 X60Qtc_744 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'L');
        if (X60Qtc_744){
          NB8 X60Qtc_745 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'O');
          if (X60Qtc_745){
            NB8 X60Qtc_746 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'E');
            if (X60Qtc_746){
              NB8 X60Qtc_747 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'D');
              if (X60Qtc_747){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1162102270u, .more_0 = (&strlit_0_I5158232484248566749_runot4689)}
                )){
                  goto X60Qsc_560;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1094862334u, .more_0 = (&strlit_0_I17457601873643567287_runot4689)}
                )){
                  goto X60Qsc_573;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I1809179661248541393_runot4689)}
                )){
                  goto X60Qsc_569;}}}
            else {
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1280266494u, .more_0 = (&strlit_0_I5139042553195443001_runot4689)}
              )){
                goto X60Qsc_647;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1280266494u, .more_0 = (&strlit_0_I17013449421715367364_runot4689)}
              )){
                goto X60Qsc_648;}}}
          else {
            NB8 X60Qtc_748 = nimStrAtLe_0_sysvq0asl(b_2, 5, (NC8)'H');
            if (X60Qtc_748){
              NB8 X60Qtc_749 = nimStrAtLe_0_sysvq0asl(b_2, 5, (NC8)'E');
              if (X60Qtc_749){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I17358945580507176610_runot4689)}
                )){
                  goto X60Qsc_654;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I5248620504356590772_runot4689)}
                )){
                  goto X60Qsc_658;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I12271380861566684602_runot4689)}
                )){
                  goto X60Qsc_655;}}}
            else {
              NB8 X60Qtc_750 = nimStrAtLe_0_sysvq0asl(b_2, 5, (NC8)'I');
              if (X60Qtc_750){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I10839707354694829060_runot4689)}
                )){
                  goto X60Qsc_651;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I3937690270225078500_runot4689)}
                )){
                  goto X60Qsc_652;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330660862u, .more_0 = (&strlit_0_I8946932245986333730_runot4689)}
                )){
                  goto X60Qsc_653;}}}}}
        else {
          NB8 X60Qtc_751 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'I');
          if (X60Qtc_751){
            NB8 X60Qtc_752 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'D');
            if (X60Qtc_752){
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1279411454u, .more_0 = (&strlit_0_I11594876617722388375_runot4689)}
              )){
                goto X60Qsc_682;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1279411454u, .more_0 = (&strlit_0_I10144059179297749967_runot4689)}
              )){
                goto X60Qsc_684;}}
            else {
              NB8 X60Qtc_753 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'E');
              if (X60Qtc_753){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1279346174u, .more_0 = (&strlit_0_I4255749366583942339_runot4689)}
                )){
                  goto X60Qsc_553;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229014526u, .more_0 = (&strlit_0_I4781299124954187715_runot4689)}
                )){
                  goto X60Qsc_675;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1195987966u, .more_0 = (&strlit_0_I13634279464104443691_runot4689)}
                )){
                  goto X60Qsc_681;}}}}
          else {
            NB8 X60Qtc_754 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'O');
            if (X60Qtc_754){
              NB8 X60Qtc_755 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'E');
              if (X60Qtc_755){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1162757630u, .more_0 = (&strlit_0_I14468723604863520882_runot4689)}
                )){
                  goto X60Qsc_585;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I16330101864687675799_runot4689)}
                )){
                  goto X60Qsc_537;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I18194623753014474103_runot4689)}
                )){
                  goto X60Qsc_590;}}}
            else {
              NB8 X60Qtc_756 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'E');
              if (X60Qtc_756){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1481917950u, .more_0 = (&strlit_0_I1563878196577720926_runot4689)}
                )){
                  goto X60Qsc_543;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1414285054u, .more_0 = (&strlit_0_I15612622545109941423_runot4689)}
                )){
                  goto X60Qsc_683;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1414285054u, .more_0 = (&strlit_0_I1732960802234142746_runot4689)}
                )){
                  goto X60Qsc_685;}}}}}}
      else {
        NB8 X60Qtc_757 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'I');
        if (X60Qtc_757){
          NB8 X60Qtc_758 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'C');
          if (X60Qtc_758){
            NB8 X60Qtc_759 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'A');
            if (X60Qtc_759){
              NB8 X60Qtc_760 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'2');
              if (X60Qtc_760){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1110590974u, .more_0 = (&strlit_0_I13407841004723990027_runot4689)}
                )){
                  goto X60Qsc_525;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1195460094u, .more_0 = (&strlit_0_I7696489594431534503_runot4689)}
                )){
                  goto X60Qsc_529;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1128351230u, .more_0 = (&strlit_0_I16505938179313545570_runot4689)}
                )){
                  goto X60Qsc_531;}}}
            else {
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1094862334u, .more_0 = (&strlit_0_I7885205764400162211_runot4689)}
              )){
                goto X60Qsc_527;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1212368382u, .more_0 = (&strlit_0_I11951888307548616935_runot4689)}
              )){
                goto X60Qsc_528;}}}
          else {
            NB8 X60Qtc_761 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'D');
            if (X60Qtc_761){
              NB8 X60Qtc_762 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'F');
              if (X60Qtc_762){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1095124478u, .more_0 = (&strlit_0_I13961222692725009152_runot4689)}
                )){
                  goto X60Qsc_532;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1111901694u, .more_0 = (&strlit_0_I14165813638295880333_runot4689)}
                )){
                  goto X60Qsc_544;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1145652734u, .more_0 = (&strlit_0_I18045396037127461917_runot4689)}
                )){
                  goto X60Qsc_567;}}}
            else {
              NB8 X60Qtc_763 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'N');
              if (X60Qtc_763){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1313424894u, .more_0 = (&strlit_0_I16087019284446782908_runot4689)}
                )){
                  goto X60Qsc_539;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1279870462u, .more_0 = (&strlit_0_I4417284260189626978_runot4689)}
                )){
                  goto X60Qsc_575;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1397310974u, .more_0 = (&strlit_0_I4422294296788528856_runot4689)}
                )){
                  goto X60Qsc_538;}}}}}
        else {
          NB8 X60Qtc_764 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'N');
          if (X60Qtc_764){
            NB8 X60Qtc_765 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'F');
            if (X60Qtc_765){
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1179534846u, .more_0 = (&strlit_0_I6018957557667376486_runot4689)}
              )){
                goto X60Qsc_540;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1179469310u, .more_0 = (&strlit_0_I14335387131779148269_runot4689)}
              )){
                goto X60Qsc_541;}}
            else {
              NB8 X60Qtc_766 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'D');
              if (X60Qtc_766){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I9895666589443991481_runot4689)}
                )){
                  goto X60Qsc_536;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I10766781976852166750_runot4689)}
                )){
                  goto X60Qsc_530;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I11180353872235103934_runot4689)}
                )){
                  goto X60Qsc_562;}}}}
          else {
            NB8 X60Qtc_767 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'P');
            if (X60Qtc_767){
              NB8 X60Qtc_768 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'E');
              if (X60Qtc_768){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1162888702u, .more_0 = (&strlit_0_I7918050307321854610_runot4689)}
                )){
                  goto X60Qsc_519;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1229997566u, .more_0 = (&strlit_0_I7589268120598100160_runot4689)}
                )){
                  goto X60Qsc_549;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1280266494u, .more_0 = (&strlit_0_I2663494012684851386_runot4689)}
                )){
                  goto X60Qsc_644;}}}
            else {
              NB8 X60Qtc_769 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'S');
              if (X60Qtc_769){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1381189118u, .more_0 = (&strlit_0_I11925018427503121466_runot4689)}
                )){
                  goto X60Qsc_521;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1095910910u, .more_0 = (&strlit_0_I2180196358490588742_runot4689)}
                )){
                  goto X60Qsc_559;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1230259710u, .more_0 = (&strlit_0_I3480874712708093906_runot4689)}
                )){
                  goto X60Qsc_570;}}}}}}}
    else {
      NB8 X60Qtc_770 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'L');
      if (X60Qtc_770){
        NB8 X60Qtc_771 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'N');
        if (X60Qtc_771){
          NB8 X60Qtc_772 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'I');
          if (X60Qtc_772){
            NB8 X60Qtc_773 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'A');
            if (X60Qtc_773){
              NB8 X60Qtc_774 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'I');
              if (X60Qtc_774){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598439934u, .more_0 = (&strlit_0_I15078264392612778793_runot4689)}
                )){
                  goto X60Qsc_614;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598439934u, .more_0 = (&strlit_0_I1821346782087953896_runot4689)}
                )){
                  goto X60Qsc_615;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598439934u, .more_0 = (&strlit_0_I1692641011015349778_runot4689)}
                )){
                  goto X60Qsc_613;}}}
            else {
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1480934910u, .more_0 = (&strlit_0_I8661079974994151876_runot4689)}
              )){
                goto X60Qsc_534;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1397310974u, .more_0 = (&strlit_0_I16815888584729336766_runot4689)}
              )){
                goto X60Qsc_589;}}}
          else {
            NB8 X60Qtc_775 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'E');
            if (X60Qtc_775){
              NB8 X60Qtc_776 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'B');
              if (X60Qtc_776){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I6781072607786902955_runot4689)}
                )){
                  goto X60Qsc_588;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I17054469839633439730_runot4689)}
                )){
                  goto X60Qsc_520;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I10282372825264079254_runot4689)}
                )){
                  goto X60Qsc_526;}}}
            else {
              NB8 X60Qtc_777 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'M');
              if (X60Qtc_777){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1280132606u, .more_0 = (&strlit_0_I15601062527192052937_runot4689)}
                )){
                  goto X60Qsc_548;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1397573118u, .more_0 = (&strlit_0_I4967662571765976842_runot4689)}
                )){
                  goto X60Qsc_554;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1481524734u, .more_0 = (&strlit_0_I240744520471951397_runot4689)}
                )){
                  goto X60Qsc_524;}}}}}
        else {
          NB8 X60Qtc_778 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'S');
          if (X60Qtc_778){
            NB8 X60Qtc_779 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'L');
            if (X60Qtc_779){
              NB8 X60Qtc_780 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'O');
              if (X60Qtc_780){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1280266494u, .more_0 = (&strlit_0_I8724774692756819601_runot4689)}
                )){
                  goto X60Qsc_646;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1280266494u, .more_0 = (&strlit_0_I4941450663983007662_runot4689)}
                )){
                  goto X60Qsc_649;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1280266494u, .more_0 = (&strlit_0_I8372180987632331225_runot4689)}
                )){
                  goto X60Qsc_645;}}}
            else {
              NB8 X60Qtc_781 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'E');
              if (X60Qtc_781){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1347634686u, .more_0 = (&strlit_0_I4080054270751335887_runot4689)}
                )){
                  goto X60Qsc_546;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330791934u, .more_0 = (&strlit_0_I13498639423973040135_runot4689)}
                )){
                  goto X60Qsc_547;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1599034366u, .more_0 = (&strlit_0_I11277392945061468617_runot4689)}
                )){
                  goto X60Qsc_598;}}}}
          else {
            NB8 X60Qtc_782 = nimStrAtLe_0_sysvq0asl(b_2, 2, (NC8)'G');
            if (X60Qtc_782){
              NB8 X60Qtc_783 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'E');
              if (X60Qtc_783){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1146635774u, .more_0 = (&strlit_0_I362468072453043806_runot4689)}
                )){
                  goto X60Qsc_535;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1197426430u, .more_0 = (&strlit_0_I14570504673037786676_runot4689)}
                )){
                  goto X60Qsc_637;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1197426430u, .more_0 = (&strlit_0_I533934364364588600_runot4689)}
                )){
                  goto X60Qsc_639;}}}
            else {
              NB8 X60Qtc_784 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'F');
              if (X60Qtc_784){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1398753022u, .more_0 = (&strlit_0_I16261150504049361679_runot4689)}
                )){
                  goto X60Qsc_638;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1398753022u, .more_0 = (&strlit_0_I8531867494946046462_runot4689)}
                )){
                  goto X60Qsc_640;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1937331198u, .more_0 = (&strlit_0_I2944771336232298774_runot4689)}
                )){
                  goto X60Qsc_557;}}}}}}
      else {
        NB8 X60Qtc_785 = nimStrAtLe_0_sysvq0asl(b_2, 5, (NC8)'U');
        if (X60Qtc_785){
          NB8 X60Qtc_786 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'S');
          if (X60Qtc_786){
            NB8 X60Qtc_787 = nimStrAtLe_0_sysvq0asl(b_2, 3, (NC8)'O');
            if (X60Qtc_787){
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I17561303392051597154_runot4689)}
              )){
                goto X60Qsc_566;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1380992510u, .more_0 = (&strlit_0_I18256310088179281350_runot4689)}
              )){
                goto X60Qsc_572;}}
            else {
              NB8 X60Qtc_788 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'P');
              if (X60Qtc_788){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I278101307767034630_runot4689)}
                )){
                  goto X60Qsc_545;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I7858844098996301644_runot4689)}
                )){
                  goto X60Qsc_563;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I14438518319534345255_runot4689)}
                )){
                  goto X60Qsc_568;}}}}
          else {
            NB8 X60Qtc_789 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'E');
            if (X60Qtc_789){
              NB8 X60Qtc_790 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'A');
              if (X60Qtc_790){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1598439934u, .more_0 = (&strlit_0_I9045984924491784844_runot4689)}
                )){
                  goto X60Qsc_613;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I17887482345509938807_runot4689)}
                )){
                  goto X60Qsc_576;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I13423043380691448333_runot4689)}
                )){
                  goto X60Qsc_581;}}}
            else {
              NB8 X60Qtc_791 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'M');
              if (X60Qtc_791){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1196641790u, .more_0 = (&strlit_0_I9851796506809248932_runot4689)}
                )){
                  goto X60Qsc_607;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1196641790u, .more_0 = (&strlit_0_I10243074878288110481_runot4689)}
                )){
                  goto X60Qsc_608;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1430803454u, .more_0 = (&strlit_0_I5657775279585733169_runot4689)}
                )){
                  goto X60Qsc_629;}}}}}
        else {
          NB8 X60Qtc_792 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'I');
          if (X60Qtc_792){
            NB8 X60Qtc_793 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'D');
            if (X60Qtc_793){
              if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1430406654u, .more_0 = (&strlit_0_I2847344692231790002_runot4689)}
              )){
                goto X60Qsc_533;}
              else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                .bytes_0 = 1329874430u, .more_0 = (&strlit_0_I12820801794451713283_runot4689)}
              )){
                goto X60Qsc_558;}}
            else {
              NB8 X60Qtc_794 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'E');
              if (X60Qtc_794){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1313424894u, .more_0 = (&strlit_0_I17143673008816423290_runot4689)}
                )){
                  goto X60Qsc_522;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330201859u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_523;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1430803454u, .more_0 = (&strlit_0_I14681790201059529979_runot4689)}
                )){
                  goto X60Qsc_630;}}}}
          else {
            NB8 X60Qtc_795 = nimStrAtLe_0_sysvq0asl(b_2, 0, (NC8)'E');
            if (X60Qtc_795){
              NB8 X60Qtc_796 = nimStrAtLe_0_sysvq0asl(b_2, 1, (NC8)'L');
              if (X60Qtc_796){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330398718u, .more_0 = (&strlit_0_I13308434310029317997_runot4689)}
                )){
                  goto X60Qsc_565;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I15946152287025759498_runot4689)}
                )){
                  goto X60Qsc_542;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1330529790u, .more_0 = (&strlit_0_I15039168409343197742_runot4689)}
                )){
                  goto X60Qsc_571;}}}
            else {
              NB8 X60Qtc_797 = nimStrAtLe_0_sysvq0asl(b_2, 4, (NC8)'N');
              if (X60Qtc_797){
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I13183969988249572472_runot4689)}
                )){
                  goto X60Qsc_514;}}
              else {
                if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I17447564145226279959_runot4689)}
                )){
                  goto X60Qsc_516;}
                else if (equalStrings_0_sysvq0asl(b_2, (string_0_sysvq0asl){
                  .bytes_0 = 1717527550u, .more_0 = (&strlit_0_I2884488504956493598_runot4689)}
                )){
                  goto X60Qsc_517;}}}}}}}}
  goto X60Qsc_799;
  X60Qsc_514: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2133 = vInt_0_valzr1t4f(((NI64)0), 64);
  result_79 = X60Qx_2133;
  goto X60Qsc_798;
  X60Qsc_515: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2134 = vInt_0_valzr1t4f(((NI64)1), 64);
  result_79 = X60Qx_2134;
  goto X60Qsc_798;
  X60Qsc_516: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2135 = vInt_0_valzr1t4f(((NI64)2), 64);
  result_79 = X60Qx_2135;
  goto X60Qsc_798;
  X60Qsc_517: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2136 = vInt_0_valzr1t4f(((NI64)3), 64);
  result_79 = X60Qx_2136;
  goto X60Qsc_798;
  X60Qsc_518: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2137 = vInt_0_valzr1t4f(((NI64)4), 64);
  result_79 = X60Qx_2137;
  goto X60Qsc_798;
  X60Qsc_519: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2138 = vInt_0_valzr1t4f(((NI64)1), 64);
  result_79 = X60Qx_2138;
  goto X60Qsc_798;
  X60Qsc_520: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2139 = vInt_0_valzr1t4f(((NI64)2), 64);
  result_79 = X60Qx_2139;
  goto X60Qsc_798;
  X60Qsc_521: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2140 = vInt_0_valzr1t4f(((NI64)3), 64);
  result_79 = X60Qx_2140;
  goto X60Qsc_798;
  X60Qsc_522: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2141 = vInt_0_valzr1t4f(((NI64)4), 64);
  result_79 = X60Qx_2141;
  goto X60Qsc_798;
  X60Qsc_523: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2142 = vInt_0_valzr1t4f(((NI64)5), 64);
  result_79 = X60Qx_2142;
  goto X60Qsc_798;
  X60Qsc_524: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2143 = vInt_0_valzr1t4f(((NI64)6), 64);
  result_79 = X60Qx_2143;
  goto X60Qsc_798;
  X60Qsc_525: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2144 = vInt_0_valzr1t4f(((NI64)7), 64);
  result_79 = X60Qx_2144;
  goto X60Qsc_798;
  X60Qsc_526: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2145 = vInt_0_valzr1t4f(((NI64)8), 64);
  result_79 = X60Qx_2145;
  goto X60Qsc_798;
  X60Qsc_527: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2146 = vInt_0_valzr1t4f(((NI64)9), 64);
  result_79 = X60Qx_2146;
  goto X60Qsc_798;
  X60Qsc_528: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2147 = vInt_0_valzr1t4f(((NI64)10), 64);
  result_79 = X60Qx_2147;
  goto X60Qsc_798;
  X60Qsc_529: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2148 = vInt_0_valzr1t4f(((NI64)11), 64);
  result_79 = X60Qx_2148;
  goto X60Qsc_798;
  X60Qsc_530: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2149 = vInt_0_valzr1t4f(((NI64)12), 64);
  result_79 = X60Qx_2149;
  goto X60Qsc_798;
  X60Qsc_531: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2150 = vInt_0_valzr1t4f(((NI64)13), 64);
  result_79 = X60Qx_2150;
  goto X60Qsc_798;
  X60Qsc_532: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2151 = vInt_0_valzr1t4f(((NI64)14), 64);
  result_79 = X60Qx_2151;
  goto X60Qsc_798;
  X60Qsc_533: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2152 = vInt_0_valzr1t4f(((NI64)16), 64);
  result_79 = X60Qx_2152;
  goto X60Qsc_798;
  X60Qsc_534: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2153 = vInt_0_valzr1t4f(((NI64)17), 64);
  result_79 = X60Qx_2153;
  goto X60Qsc_798;
  X60Qsc_535: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2154 = vInt_0_valzr1t4f(((NI64)18), 64);
  result_79 = X60Qx_2154;
  goto X60Qsc_798;
  X60Qsc_536: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2155 = vInt_0_valzr1t4f(((NI64)19), 64);
  result_79 = X60Qx_2155;
  goto X60Qsc_798;
  X60Qsc_537: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2156 = vInt_0_valzr1t4f(((NI64)20), 64);
  result_79 = X60Qx_2156;
  goto X60Qsc_798;
  X60Qsc_538: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2157 = vInt_0_valzr1t4f(((NI64)21), 64);
  result_79 = X60Qx_2157;
  goto X60Qsc_798;
  X60Qsc_539: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2158 = vInt_0_valzr1t4f(((NI64)22), 64);
  result_79 = X60Qx_2158;
  goto X60Qsc_798;
  X60Qsc_540: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2159 = vInt_0_valzr1t4f(((NI64)23), 64);
  result_79 = X60Qx_2159;
  goto X60Qsc_798;
  X60Qsc_541: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2160 = vInt_0_valzr1t4f(((NI64)24), 64);
  result_79 = X60Qx_2160;
  goto X60Qsc_798;
  X60Qsc_542: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2161 = vInt_0_valzr1t4f(((NI64)25), 64);
  result_79 = X60Qx_2161;
  goto X60Qsc_798;
  X60Qsc_543: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2162 = vInt_0_valzr1t4f(((NI64)26), 64);
  result_79 = X60Qx_2162;
  goto X60Qsc_798;
  X60Qsc_544: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2163 = vInt_0_valzr1t4f(((NI64)27), 64);
  result_79 = X60Qx_2163;
  goto X60Qsc_798;
  X60Qsc_545: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2164 = vInt_0_valzr1t4f(((NI64)28), 64);
  result_79 = X60Qx_2164;
  goto X60Qsc_798;
  X60Qsc_546: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2165 = vInt_0_valzr1t4f(((NI64)29), 64);
  result_79 = X60Qx_2165;
  goto X60Qsc_798;
  X60Qsc_547: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2166 = vInt_0_valzr1t4f(((NI64)30), 64);
  result_79 = X60Qx_2166;
  goto X60Qsc_798;
  X60Qsc_548: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2167 = vInt_0_valzr1t4f(((NI64)31), 64);
  result_79 = X60Qx_2167;
  goto X60Qsc_798;
  X60Qsc_549: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2168 = vInt_0_valzr1t4f(((NI64)32), 64);
  result_79 = X60Qx_2168;
  goto X60Qsc_798;
  X60Qsc_550: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2169 = vInt_0_valzr1t4f(((NI64)125), 64);
  result_79 = X60Qx_2169;
  goto X60Qsc_798;
  X60Qsc_551: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2170 = vInt_0_valzr1t4f(((NI64)103), 64);
  result_79 = X60Qx_2170;
  goto X60Qsc_798;
  X60Qsc_552: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2171 = vInt_0_valzr1t4f(((NI64)115), 64);
  result_79 = X60Qx_2171;
  goto X60Qsc_798;
  X60Qsc_553: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2172 = vInt_0_valzr1t4f(((NI64)114), 64);
  result_79 = X60Qx_2172;
  goto X60Qsc_798;
  X60Qsc_554: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2173 = vInt_0_valzr1t4f(((NI64)90), 64);
  result_79 = X60Qx_2173;
  goto X60Qsc_798;
  X60Qsc_555: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2174 = vInt_0_valzr1t4f(((NI64)102), 64);
  result_79 = X60Qx_2174;
  goto X60Qsc_798;
  X60Qsc_556: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2175 = vInt_0_valzr1t4f(((NI64)84), 64);
  result_79 = X60Qx_2175;
  goto X60Qsc_798;
  X60Qsc_557: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2176 = vInt_0_valzr1t4f(((NI64)1), 64);
  result_79 = X60Qx_2176;
  goto X60Qsc_798;
  X60Qsc_558: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2177 = vInt_0_valzr1t4f(((NI64)33), 64);
  result_79 = X60Qx_2177;
  goto X60Qsc_798;
  X60Qsc_559: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2178 = vInt_0_valzr1t4f(((NI64)34), 64);
  result_79 = X60Qx_2178;
  goto X60Qsc_798;
  X60Qsc_560: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2179 = vInt_0_valzr1t4f(((NI64)35), 64);
  result_79 = X60Qx_2179;
  goto X60Qsc_798;
  X60Qsc_561: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2180 = vInt_0_valzr1t4f(((NI64)36), 64);
  result_79 = X60Qx_2180;
  goto X60Qsc_798;
  X60Qsc_562: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2181 = vInt_0_valzr1t4f(((NI64)37), 64);
  result_79 = X60Qx_2181;
  goto X60Qsc_798;
  X60Qsc_563: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2182 = vInt_0_valzr1t4f(((NI64)38), 64);
  result_79 = X60Qx_2182;
  goto X60Qsc_798;
  X60Qsc_564: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2183 = vInt_0_valzr1t4f(((NI64)39), 64);
  result_79 = X60Qx_2183;
  goto X60Qsc_798;
  X60Qsc_565: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2184 = vInt_0_valzr1t4f(((NI64)40), 64);
  result_79 = X60Qx_2184;
  goto X60Qsc_798;
  X60Qsc_566: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2185 = vInt_0_valzr1t4f(((NI64)42), 64);
  result_79 = X60Qx_2185;
  goto X60Qsc_798;
  X60Qsc_567: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2186 = vInt_0_valzr1t4f(((NI64)43), 64);
  result_79 = X60Qx_2186;
  goto X60Qsc_798;
  X60Qsc_568: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2187 = vInt_0_valzr1t4f(((NI64)60), 64);
  result_79 = X60Qx_2187;
  goto X60Qsc_798;
  X60Qsc_569: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2188 = vInt_0_valzr1t4f(((NI64)61), 64);
  result_79 = X60Qx_2188;
  goto X60Qsc_798;
  X60Qsc_570: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2189 = vInt_0_valzr1t4f(((NI64)62), 64);
  result_79 = X60Qx_2189;
  goto X60Qsc_798;
  X60Qsc_571: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2190 = vInt_0_valzr1t4f(((NI64)63), 64);
  result_79 = X60Qx_2190;
  goto X60Qsc_798;
  X60Qsc_572: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2191 = vInt_0_valzr1t4f(((NI64)71), 64);
  result_79 = X60Qx_2191;
  goto X60Qsc_798;
  X60Qsc_573: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2192 = vInt_0_valzr1t4f(((NI64)74), 64);
  result_79 = X60Qx_2192;
  goto X60Qsc_798;
  X60Qsc_574: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2193 = vInt_0_valzr1t4f(((NI64)75), 64);
  result_79 = X60Qx_2193;
  goto X60Qsc_798;
  X60Qsc_575: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2194 = vInt_0_valzr1t4f(((NI64)84), 64);
  result_79 = X60Qx_2194;
  goto X60Qsc_798;
  X60Qsc_576: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2195 = vInt_0_valzr1t4f(((NI64)88), 64);
  result_79 = X60Qx_2195;
  goto X60Qsc_798;
  X60Qsc_577: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2196 = vInt_0_valzr1t4f(((NI64)89), 64);
  result_79 = X60Qx_2196;
  goto X60Qsc_798;
  X60Qsc_578: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2197 = vInt_0_valzr1t4f(((NI64)91), 64);
  result_79 = X60Qx_2197;
  goto X60Qsc_798;
  X60Qsc_579: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2198 = vInt_0_valzr1t4f(((NI64)92), 64);
  result_79 = X60Qx_2198;
  goto X60Qsc_798;
  X60Qsc_580: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2199 = vInt_0_valzr1t4f(((NI64)93), 64);
  result_79 = X60Qx_2199;
  goto X60Qsc_798;
  X60Qsc_581: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2200 = vInt_0_valzr1t4f(((NI64)95), 64);
  result_79 = X60Qx_2200;
  goto X60Qsc_798;
  X60Qsc_582: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2201 = vInt_0_valzr1t4f(((NI64)97), 64);
  result_79 = X60Qx_2201;
  goto X60Qsc_798;
  X60Qsc_583: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2202 = vInt_0_valzr1t4f(((NI64)98), 64);
  result_79 = X60Qx_2202;
  goto X60Qsc_798;
  X60Qsc_584: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2203 = vInt_0_valzr1t4f(((NI64)99), 64);
  result_79 = X60Qx_2203;
  goto X60Qsc_798;
  X60Qsc_585: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2204 = vInt_0_valzr1t4f(((NI64)100), 64);
  result_79 = X60Qx_2204;
  goto X60Qsc_798;
  X60Qsc_586: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2205 = vInt_0_valzr1t4f(((NI64)101), 64);
  result_79 = X60Qx_2205;
  goto X60Qsc_798;
  X60Qsc_587: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2206 = vInt_0_valzr1t4f(((NI64)104), 64);
  result_79 = X60Qx_2206;
  goto X60Qsc_798;
  X60Qsc_588: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2207 = vInt_0_valzr1t4f(((NI64)105), 64);
  result_79 = X60Qx_2207;
  goto X60Qsc_798;
  X60Qsc_589: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2208 = vInt_0_valzr1t4f(((NI64)106), 64);
  result_79 = X60Qx_2208;
  goto X60Qsc_798;
  X60Qsc_590: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2209 = vInt_0_valzr1t4f(((NI64)107), 64);
  result_79 = X60Qx_2209;
  goto X60Qsc_798;
  X60Qsc_591: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2210 = vInt_0_valzr1t4f(((NI64)110), 64);
  result_79 = X60Qx_2210;
  goto X60Qsc_798;
  X60Qsc_592: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2211 = vInt_0_valzr1t4f(((NI64)111), 64);
  result_79 = X60Qx_2211;
  goto X60Qsc_798;
  X60Qsc_593: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2212 = vInt_0_valzr1t4f(((NI64)113), 64);
  result_79 = X60Qx_2212;
  goto X60Qsc_798;
  X60Qsc_594: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2213 = vInt_0_valzr1t4f(((NI64)130), 64);
  result_79 = X60Qx_2213;
  goto X60Qsc_798;
  X60Qsc_595: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2214 = vInt_0_valzr1t4f(((NI64)131), 64);
  result_79 = X60Qx_2214;
  goto X60Qsc_798;
  X60Qsc_596: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2215 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2215;
  goto X60Qsc_798;
  X60Qsc_597: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2216 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2216;
  goto X60Qsc_798;
  X60Qsc_598: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2217 = vInt_0_valzr1t4f(((NI64)4), 32);
  result_79 = X60Qx_2217;
  goto X60Qsc_798;
  X60Qsc_599: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2218 = vInt_0_valzr1t4f(((NI64)6), 32);
  result_79 = X60Qx_2218;
  goto X60Qsc_798;
  X60Qsc_600: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2219 = vInt_0_valzr1t4f(((NI64)7), 32);
  result_79 = X60Qx_2219;
  goto X60Qsc_798;
  X60Qsc_601: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2220 = vInt_0_valzr1t4f(((NI64)8), 32);
  result_79 = X60Qx_2220;
  goto X60Qsc_798;
  X60Qsc_602: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2221 = vInt_0_valzr1t4f(((NI64)9), 32);
  result_79 = X60Qx_2221;
  goto X60Qsc_798;
  X60Qsc_603: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2222 = vInt_0_valzr1t4f(((NI64)13), 32);
  result_79 = X60Qx_2222;
  goto X60Qsc_798;
  X60Qsc_604: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2223 = vInt_0_valzr1t4f(((NI64)15), 32);
  result_79 = X60Qx_2223;
  goto X60Qsc_798;
  X60Qsc_605: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2224 = vInt_0_valzr1t4f(((NI64)20), 32);
  result_79 = X60Qx_2224;
  goto X60Qsc_798;
  X60Qsc_606: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2225 = vInt_0_valzr1t4f(((NI64)21), 32);
  result_79 = X60Qx_2225;
  goto X60Qsc_798;
  X60Qsc_607: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2226 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2226;
  goto X60Qsc_798;
  X60Qsc_608: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2227 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2227;
  goto X60Qsc_798;
  X60Qsc_609: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2228 = vInt_0_valzr1t4f(((NI64)64), 32);
  result_79 = X60Qx_2228;
  goto X60Qsc_798;
  X60Qsc_610: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2229 = vInt_0_valzr1t4f(((NI64)256), 32);
  result_79 = X60Qx_2229;
  goto X60Qsc_798;
  X60Qsc_611: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2230 = vInt_0_valzr1t4f(((NI64)16384), 32);
  result_79 = X60Qx_2230;
  goto X60Qsc_798;
  X60Qsc_612: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2231 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_79 = X60Qx_2231;
  goto X60Qsc_798;
  X60Qsc_613: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2232 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2232;
  goto X60Qsc_798;
  X60Qsc_614: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2233 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2233;
  goto X60Qsc_798;
  X60Qsc_615: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2234 = vInt_0_valzr1t4f(((NI64)10), 32);
  result_79 = X60Qx_2234;
  goto X60Qsc_798;
  X60Qsc_616: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2235 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2235;
  goto X60Qsc_798;
  X60Qsc_617: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2236 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2236;
  goto X60Qsc_798;
  X60Qsc_618: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2237 = vInt_0_valzr1t4f(((NI64)2048), 32);
  result_79 = X60Qx_2237;
  goto X60Qsc_798;
  X60Qsc_619: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2238 = vInt_0_valzr1t4f(((NI64)524288), 32);
  result_79 = X60Qx_2238;
  goto X60Qsc_798;
  X60Qsc_620: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2239 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_79 = X60Qx_2239;
  goto X60Qsc_798;
  X60Qsc_621: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2240 = vInt_0_valzr1t4f(((NI64)6), 32);
  result_79 = X60Qx_2240;
  goto X60Qsc_798;
  X60Qsc_622: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2241 = vInt_0_valzr1t4f(((NI64)17), 32);
  result_79 = X60Qx_2241;
  goto X60Qsc_798;
  X60Qsc_623: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2242 = vInt_0_valzr1t4f(((NI64)41), 32);
  result_79 = X60Qx_2242;
  goto X60Qsc_798;
  X60Qsc_624: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2243 = vInt_0_valzr1t4f(((NI64)26), 32);
  result_79 = X60Qx_2243;
  goto X60Qsc_798;
  X60Qsc_625: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2244 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2244;
  goto X60Qsc_798;
  X60Qsc_626: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2245 = vInt_0_valzr1t4f(((NI64)4), 32);
  result_79 = X60Qx_2245;
  goto X60Qsc_798;
  X60Qsc_627: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2246 = vInt_0_valzr1t4f(((NI64)5), 32);
  result_79 = X60Qx_2246;
  goto X60Qsc_798;
  X60Qsc_628: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2247 = vInt_0_valzr1t4f(((NI64)6), 32);
  result_79 = X60Qx_2247;
  goto X60Qsc_798;
  X60Qsc_629: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2248 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_79 = X60Qx_2248;
  goto X60Qsc_798;
  X60Qsc_630: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2249 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2249;
  goto X60Qsc_798;
  X60Qsc_631: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2250 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2250;
  goto X60Qsc_798;
  X60Qsc_632: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2251 = vInt_0_valzr1t4f(((NI64)4096), 32);
  result_79 = X60Qx_2251;
  goto X60Qsc_798;
  X60Qsc_633: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2252 = vInt_0_valzr1t4f(((NI64)0), 32);
  result_79 = X60Qx_2252;
  goto X60Qsc_798;
  X60Qsc_634: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2253 = vInt_0_valzr1t4f(((NI64)2130706433), 32);
  result_79 = X60Qx_2253;
  goto X60Qsc_798;
  X60Qsc_635: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2254 = vInt_0_valzr1t4f(((NI64)16), 32);
  result_79 = X60Qx_2254;
  goto X60Qsc_798;
  X60Qsc_636: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2255 = vInt_0_valzr1t4f(((NI64)46), 32);
  result_79 = X60Qx_2255;
  goto X60Qsc_798;
  X60Qsc_637: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2256 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2256;
  goto X60Qsc_798;
  X60Qsc_638: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2257 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2257;
  goto X60Qsc_798;
  X60Qsc_639: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2258 = vInt_0_valzr1t4f(((NI64)3), 32);
  result_79 = X60Qx_2258;
  goto X60Qsc_798;
  X60Qsc_640: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2259 = vInt_0_valzr1t4f(((NI64)4), 32);
  result_79 = X60Qx_2259;
  goto X60Qsc_798;
  X60Qsc_641: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2260 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2260;
  goto X60Qsc_798;
  X60Qsc_642: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2261 = vInt_0_valzr1t4f(((NI64)2048), 32);
  result_79 = X60Qx_2261;
  goto X60Qsc_798;
  X60Qsc_643: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2262 = vInt_0_valzr1t4f(((NI64)524288), 32);
  result_79 = X60Qx_2262;
  goto X60Qsc_798;
  X60Qsc_644: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2263 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2263;
  goto X60Qsc_798;
  X60Qsc_645: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2264 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2264;
  goto X60Qsc_798;
  X60Qsc_646: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2265 = vInt_0_valzr1t4f(((NI64)4), 32);
  result_79 = X60Qx_2265;
  goto X60Qsc_798;
  X60Qsc_647: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2266 = vInt_0_valzr1t4f(((NI64)8), 32);
  result_79 = X60Qx_2266;
  goto X60Qsc_798;
  X60Qsc_648: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2267 = vInt_0_valzr1t4f(((NI64)16), 32);
  result_79 = X60Qx_2267;
  goto X60Qsc_798;
  X60Qsc_649: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2268 = vInt_0_valzr1t4f(((NI64)32), 32);
  result_79 = X60Qx_2268;
  goto X60Qsc_798;
  X60Qsc_650: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2269 = vInt_0_valzr1t4f(((NI64)8192), 32);
  result_79 = X60Qx_2269;
  goto X60Qsc_798;
  X60Qsc_651: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2270 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2270;
  goto X60Qsc_798;
  X60Qsc_652: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2271 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2271;
  goto X60Qsc_798;
  X60Qsc_653: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2272 = vInt_0_valzr1t4f(((NI64)4), 32);
  result_79 = X60Qx_2272;
  goto X60Qsc_798;
  X60Qsc_654: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2273 = vInt_0_valzr1t4f(((NI64)8), 32);
  result_79 = X60Qx_2273;
  goto X60Qsc_798;
  X60Qsc_655: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2274 = vInt_0_valzr1t4f(((NI64)16), 32);
  result_79 = X60Qx_2274;
  goto X60Qsc_798;
  X60Qsc_656: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2275 = vInt_0_valzr1t4f(((NI64)8192), 32);
  result_79 = X60Qx_2275;
  goto X60Qsc_798;
  X60Qsc_657: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2276 = vInt_0_valzr1t4f(((NI64)1073741824), 32);
  result_79 = X60Qx_2276;
  goto X60Qsc_798;
  X60Qsc_658: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2277 = vInt_0_valzr1t4f(((NI64)(-2147483647 -1)), 32);
  result_79 = X60Qx_2277;
  goto X60Qsc_798;
  X60Qsc_659: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2278 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2278;
  goto X60Qsc_798;
  X60Qsc_660: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2279 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2279;
  goto X60Qsc_798;
  X60Qsc_661: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2280 = vInt_0_valzr1t4f(((NI64)3), 32);
  result_79 = X60Qx_2280;
  goto X60Qsc_798;
  X60Qsc_662: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2281 = vInt_0_valzr1t4f(((NI64)524288), 32);
  result_79 = X60Qx_2281;
  goto X60Qsc_798;
  X60Qsc_663: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2282 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2282;
  goto X60Qsc_798;
  X60Qsc_664: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2283 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2283;
  goto X60Qsc_798;
  X60Qsc_665: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2284 = vInt_0_valzr1t4f(((NI64)4), 32);
  result_79 = X60Qx_2284;
  goto X60Qsc_798;
  X60Qsc_666: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2285 = vInt_0_valzr1t4f(((NI64)32), 32);
  result_79 = X60Qx_2285;
  goto X60Qsc_798;
  X60Qsc_667: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2286 = vInt_0_valzr1t4f(((NI64)1024), 32);
  result_79 = X60Qx_2286;
  goto X60Qsc_798;
  X60Qsc_668: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2287 = vInt_0_valzr1t4f(((NI64)1), 32);
  result_79 = X60Qx_2287;
  goto X60Qsc_798;
  X60Qsc_669: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2288 = vInt_0_valzr1t4f(((NI64)2), 32);
  result_79 = X60Qx_2288;
  goto X60Qsc_798;
  X60Qsc_670: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2289 = vInt_0_valzr1t4f(((NI64)1025), 32);
  result_79 = X60Qx_2289;
  goto X60Qsc_798;
  X60Qsc_671: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2290 = vInt_0_valzr1t4f(((NI64)32), 32);
  result_79 = X60Qx_2290;
  goto X60Qsc_798;
  X60Qsc_672: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2291 = vInt_0_valzr1t4f(((NI64)-1), 32);
  result_79 = X60Qx_2291;
  goto X60Qsc_798;
  X60Qsc_673: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2292 = vInt_0_valzr1t4f(((NI64)-2), 32);
  result_79 = X60Qx_2292;
  goto X60Qsc_798;
  X60Qsc_674: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2293 = vInt_0_valzr1t4f(((NI64)-3), 32);
  result_79 = X60Qx_2293;
  goto X60Qsc_798;
  X60Qsc_675: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2294 = vInt_0_valzr1t4f(((NI64)-4), 32);
  result_79 = X60Qx_2294;
  goto X60Qsc_798;
  X60Qsc_676: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2295 = vInt_0_valzr1t4f(((NI64)-6), 32);
  result_79 = X60Qx_2295;
  goto X60Qsc_798;
  X60Qsc_677: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2296 = vInt_0_valzr1t4f(((NI64)-7), 32);
  result_79 = X60Qx_2296;
  goto X60Qsc_798;
  X60Qsc_678: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2297 = vInt_0_valzr1t4f(((NI64)-8), 32);
  result_79 = X60Qx_2297;
  goto X60Qsc_798;
  X60Qsc_679: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2298 = vInt_0_valzr1t4f(((NI64)-10), 32);
  result_79 = X60Qx_2298;
  goto X60Qsc_798;
  X60Qsc_680: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2299 = vInt_0_valzr1t4f(((NI64)-11), 32);
  result_79 = X60Qx_2299;
  goto X60Qsc_798;
  X60Qsc_681: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2300 = vInt_0_valzr1t4f(((NI64)13), 32);
  result_79 = X60Qx_2300;
  goto X60Qsc_798;
  X60Qsc_682: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  NU64 X60Qx_2301 = ((NU64)4503599627370496ull);
  NF64 X60Qx_2302;
  copyMem_0_sysvq0asl((&X60Qx_2302), (&X60Qx_2301), sizeof(NF64));
  Value_0_valzr1t4f X60Qx_2303 = vFloat_0_valzr1t4f(X60Qx_2302, 64);
  result_79 = X60Qx_2303;
  goto X60Qsc_798;
  X60Qsc_683: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2304 = vFloat_0_valzr1t4f(1.1754943508222875e-38, 32);
  result_79 = X60Qx_2304;
  goto X60Qsc_798;
  X60Qsc_684: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  NU64 X60Qx_2305 = ((NU64)9218868437227405311ull);
  NF64 X60Qx_2306;
  copyMem_0_sysvq0asl((&X60Qx_2306), (&X60Qx_2305), sizeof(NF64));
  Value_0_valzr1t4f X60Qx_2307 = vFloat_0_valzr1t4f(X60Qx_2306, 64);
  result_79 = X60Qx_2307;
  goto X60Qsc_798;
  X60Qsc_685: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2308 = vFloat_0_valzr1t4f(3.4028234663852886e+38, 32);
  result_79 = X60Qx_2308;
  goto X60Qsc_798;
  X60Qsc_799: ;
  (*found_4) = NIM_FALSE;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_79));
  Value_0_valzr1t4f X60Qx_2309 = vNil_0_valzr1t4f();
  result_79 = X60Qx_2309;
  X60Qsc_798: ;
  return result_79;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_In7zd9y_runot4689(X60Qt_0_IAarraySstring0sysvq0aslS11_runot4689* x_30){
  openArray_0_Ig73pnk_aow7lb5cq1 result_83;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_84;
  if (((NI32)(((NI32)(((NI32)((NI32)10)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_84 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_84 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_30))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)10)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_83 = X60Qx_84;
  return result_83;}
static inline seq_0_Ixbbxx5_runot4689 newSeqUninit_0_Ianh1rs1_runot4689(NI32 size_15){
  seq_0_Ixbbxx5_runot4689 result_97;
  if (size_15 == 0){
    result_97 = (seq_0_Ixbbxx5_runot4689){
      .len_0 = size_15, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_I56aaae_runot4689(size_15);
    void* X60Qx_2331 = alloc_1_sysvq0asl(memSize_3);
    result_97 = (seq_0_Ixbbxx5_runot4689){
      .len_0 = size_15, .data_0 = ((BwEntry_0_runot4689*)X60Qx_2331)}
    ;
    if ((!(result_97.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2332 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_97.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_97;}
static inline NI32 len_3_Iktsa441_runot4689(seq_0_Ixbbxx5_runot4689 s_61){
  NI32 result_98;
  result_98 = s_61.len_0;
  return result_98;}
static inline BwEntry_0_runot4689* getQ_7_I1zo4u41_runot4689(seq_0_Ixbbxx5_runot4689 s_62, NI32 i_66){
  NB8 X60Qx_2333;
  if (i_66 < s_62.len_0){
    X60Qx_2333 = (0 <= i_66);}
  else {
    X60Qx_2333 = NIM_FALSE;}
  if ((!X60Qx_2333)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  BwEntry_0_runot4689* result_99;
  result_99 = (&s_62.data_0[i_66]);
  return result_99;}
static inline void add_0_Ifyely51_runot4689(seq_0_Ixbbxx5_runot4689* s_63, BwEntry_0_runot4689 elem_11){
  NI32 L_3 = (*s_63).len_0;
  NI32 X60Qx_2334 = capInBytes_0_Ibnuxic1_runot4689((*s_63));
  if (X60Qx_2334 < ((NI32)(((NI32)(L_3 * sizeof(BwEntry_0_runot4689))) + sizeof(BwEntry_0_runot4689)))){
    NB8 X60Qx_2335 = resize_0_I0hj5uk1_runot4689(s_63, 1);
    if ((!X60Qx_2335)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_63).len_0));
  (*s_63).data_0[L_3] = elem_11;}
static inline X60Qt_0_IAarrayAuS64ZS4_intzsnzax default_23_I3gf93w_runot4689(void){
  X60Qt_0_IAarrayAuS64ZS4_intzsnzax result_103;
  {
    NI32 X60Qlf_12 = ((NI32)0);
    NI32 X60Qlf_13 = ((NI32)3);
    NI32 X60Qlf_14 = X60Qlf_12;
    {
      while (X60Qlf_14 <= X60Qlf_13){
        {
          NI32 X60Qx_2341 = nimIcheckB(X60Qlf_14, 3);
          result_103.a[X60Qx_2341] = ((NU64)0u);}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_14));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_103;}
static inline NI32 memSizeInBytes_0_I56aaae_runot4689(NI32 size_26){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_127;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_26, sizeof(BwEntry_0_runot4689), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_127 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_127 = ((NI32)2147483647);}
  return result_127;}
static inline NI32 capInBytes_0_Ibnuxic1_runot4689(seq_0_Ixbbxx5_runot4689 s_88){
  NI32 result_128;
  NI32 X60Qx_88;
  if ((!(s_88.data_0 == NIM_NIL))){
    NI32 X60Qx_2371 = allocatedSize_0_sysvq0asl(((void*)((void*)s_88.data_0)));
    X60Qx_88 = X60Qx_2371;}
  else {
    X60Qx_88 = 0;}
  result_128 = X60Qx_88;
  return result_128;}
NB8 resize_0_I0hj5uk1_runot4689(seq_0_Ixbbxx5_runot4689* dest_9, NI32 addedElements_9){
  NB8 result_129;
  NI32 X60Qx_2372 = capInBytes_0_Ibnuxic1_runot4689((*dest_9));
  NI32 oldCap_3 = ((NI32)(X60Qx_2372 / sizeof(BwEntry_0_runot4689)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_9);
  NI32 memSize_10 = memSizeInBytes_0_I56aaae_runot4689(newCap_3);
  void* X60Qx_2373 = realloc_1_sysvq0asl(((void*)((void*)(*dest_9).data_0)), memSize_10);
  (*dest_9).data_0 = ((BwEntry_0_runot4689*)X60Qx_2373);
  if ((*dest_9).data_0 == NIM_NIL){
    (*dest_9).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_10);
    result_129 = NIM_FALSE;}
  else {
    result_129 = NIM_TRUE;}
  return result_129;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_2455 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2455){
      eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_runot4689(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21* dest_0){
  nimStrWasMoved((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_runot4689(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 dest_0){
  nimStrDestroy(dest_0.fld_0);}
void eQwasmovedQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1* dest_0){
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689((&(*dest_0).fld_0));}
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_2456 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2456){
      eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_runot4689(X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 dest_0){
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(dest_0.fld_0);}
void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_2457 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2457){
      eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_2458 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2458){
      eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_2459 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2459){
      eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_runot4689(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_runot4689(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_2460 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2460){
      eQdestroyQ_SX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void X60Qini_0_runot4689(void){
  if (X60QiniGuard_0_runot4689){
    return;}
  X60QiniGuard_0_runot4689 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_prorcx25w1();
  X60Qini_0_symkyk35i1();
  X60Qini_0_decqocs071();
  X60Qini_0_modzy18mg1();
  X60Qini_0_buiyylk1h1();
  X60Qini_0_modjbswg91();
  X60Qini_0_valzr1t4f();
  X60Qini_0_natd5co251();
  X60Qini_0_flowmlewz();
  X60Qini_0_flaksyopx1();
  X60Qini_0_hos5i19e11();
  X60Qini_0_hos1fpv3m1();
  X60Qini_0_hos9jnsbq1();
  X60Qini_0_iop7yt73v();
  X60Qini_0_jou8favxh1();
  X60Qini_0_mat7cnfv21();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_envto7w6l1();
  gErrnoCells_0_runot4689 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  gEnvironmentCells_0_runot4689 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  string_0_sysvq0asl X60Qtmp_13 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I10545009242662524993_runot4689)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  traceUnported_0_runot4689 = eqQ_20_sysvq0asl(X60Qtmp_13, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  gModSuffixSeen_0_runot4689 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  gModSuffixStd_0_runot4689 = newSeqUninit_0_I5mozxi1_aow7lb5cq1(0);
  gBackwardsHiCache_0_runot4689 = newSeqUninit_0_Ianh1rs1_runot4689(0);
  gImportcNames_0_runot4689 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  gImportcCells_0_runot4689 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  gImportcNativeNames_0_runot4689 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  gImportcNativeVals_0_runot4689 = newSeqUninit_0_I8oufjc_croph25r5(0);
  gImportcNativeCells_0_runot4689 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  gImportcNativeCellNames_0_runot4689 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  string_0_sysvq0asl X60Qtmp_126 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I8044815621933303456_runot4689)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  importcLax_0_runot4689 = eqQ_20_sysvq0asl(X60Qtmp_126, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(X60Qtmp_126);
  nimStrDestroy(X60Qtmp_13);}
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_arecyyj7v* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8){
  NI32 L_1 = (*s_32).len_0;
  NI32 X60Qx_432 = capInBytes_0_Iih34tr1_arecyyj7v((*s_32));
  if (X60Qx_432 < ((NI32)(((NI32)(L_1 * sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*))) + sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)))){
    NB8 X60Qx_433 = resize_0_If3pogj_flaksyopx1(s_32, 1);
    if ((!X60Qx_433)){
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(elem_8);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_32).len_0));
  (*s_32).data_0[L_1] = elem_8;}
static inline NI32 len_3_I83dzei_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_25){
  NI32 result_26;
  result_26 = s_25.len_0;
  return result_26;}
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_26, NI32 i_28){
  NB8 X60Qx_305;
  if (i_28 < s_26.len_0){
    X60Qx_305 = (0 <= i_28);}
  else {
    X60Qx_305 = NIM_FALSE;}
  if ((!X60Qx_305)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** result_27;
  result_27 = (&s_26.data_0[i_28]);
  return result_27;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_30){
  NI32 result_107;
  result_107 = a_30.len_0;
  return result_107;}
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7){
  NB8 X60Qx_2320;
  if (0 <= idx_7){
    X60Qx_2320 = (idx_7 < x_13.len_0);}
  else {
    X60Qx_2320 = NIM_FALSE;}
  if ((!X60Qx_2320)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* result_108;
  result_108 = (&x_13.a_0[idx_7]);
  return result_108;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline NI32 len_6_Iy5lph11_intzsnzax(openArray_0_I2902h9_intzsnzax a_75){
  NI32 result_342;
  result_342 = a_75.len_0;
  return result_342;}
static inline Value_0_valzr1t4f* getQ_10_Igi7i95_intzsnzax(openArray_0_I2902h9_intzsnzax x_31, NI32 idx_51){
  NB8 X60Qx_4108;
  if (0 <= idx_51){
    X60Qx_4108 = (idx_51 < x_31.len_0);}
  else {
    X60Qx_4108 = NIM_FALSE;}
  if ((!X60Qx_4108)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  Value_0_valzr1t4f* result_343;
  result_343 = (&x_31.a_0[idx_51]);
  return result_343;}
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_142){
  NI32 result_191;
  result_191 = s_142.len_0;
  return result_191;}
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_143, NI32 i_95){
  NB8 X60Qx_3740;
  if (i_95 < s_143.len_0){
    X60Qx_3740 = (0 <= i_95);}
  else {
    X60Qx_3740 = NIM_FALSE;}
  if ((!X60Qx_3740)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  Value_0_valzr1t4f* result_192;
  result_192 = (&s_143.data_0[i_95]);
  return result_192;}
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13){
  NU32 result_16;
  PackedToken_0_nifh7u8pu1 X60Qx_36 = load_0_nifb6mq6y1(c_13);
  NU32 X60Qx_37 = tagId_0_nifh7u8pu1(X60Qx_36);
  result_16 = X60Qx_37;
  return result_16;}
static inline string_0_sysvq0asl* getQ_0_I93d71y_der823rwr1(BiTable_0_Icvz6lt_buiyylk1h1 t_5, NU32 litId_1){
  string_0_sysvq0asl* result_13;
  NI32 idx_0 = ((NI32)(((NI32)litId_1) - ((NI32)1)));
  if ((!(idx_0 < t_5.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  string_0_sysvq0asl* X60Qx_187 = getQ_7_Ir6d0tw_aow7lb5cq1(t_5.vals_0, idx_0);
  result_13 = X60Qx_187;
  return result_13;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline seq_0_Iw8xl5b1_arecyyj7v newSeqUninit_0_I1tbjnk1_arecyyj7v(NI32 size_24){
  seq_0_Iw8xl5b1_arecyyj7v result_61;
  if (size_24 == 0){
    result_61 = (seq_0_Iw8xl5b1_arecyyj7v){
      .len_0 = size_24, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_16 = memSizeInBytes_0_Ixcobep_arecyyj7v(size_24);
    void* X60Qx_372 = alloc_1_sysvq0asl(memSize_16);
    result_61 = (seq_0_Iw8xl5b1_arecyyj7v){
      .len_0 = size_24, .data_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1**)X60Qx_372)}
    ;
    if ((!(result_61.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_373 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_61.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_16);}}
  return result_61;}
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18){
  if ((!(0 < (*c_18).rem_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  (*c_18).p_0 = ((PackedToken_0_nifh7u8pu1*)((NU32)(((NU32)(*c_18).p_0) + ((NU32)sizeof(PackedToken_0_nifh7u8pu1)))));
  dec_1_I0nzoz91_aow7lb5cq1((&(*c_18).rem_0));}
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8){
  NU32 result_11;
  PackedToken_0_nifh7u8pu1 X60Qx_26 = load_0_nifb6mq6y1(c_8);
  NU32 X60Qx_27 = symId_0_nifh7u8pu1(X60Qx_26);
  result_11 = X60Qx_27;
  return result_11;}
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1){
  Cursor_0_nifb6mq6y1 result_4;
  result_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = src_1.owner_0, .p_0 = src_1.p_0, .rem_0 = src_1.rem_0}
  ;
  if ((!(result_4.owner_0 == NIM_NIL))){
    inc_1_I6wjjge_aow2h993l1((&(*result_4.owner_0).rc_0));}
  return result_4;}
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10){
  NU32 result_13;
  PackedToken_0_nifh7u8pu1 X60Qx_30 = load_0_nifb6mq6y1(c_10);
  NU32 X60Qx_31 = intId_0_nifh7u8pu1(X60Qx_30);
  result_13 = X60Qx_31;
  return result_13;}
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6){
  NI64* result_4;
  NI32 idx_1 = ((NI32)(((NI32)litId_6) - ((NI32)1)));
  if ((!(idx_1 < t_7.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NI64* X60Qx_32 = getQ_7_Ite3z0o_ast8ri79k(t_7.vals_0, idx_1);
  result_4 = X60Qx_32;
  return result_4;}
static inline X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0_valzr1t4f(Value_0_valzr1t4f* v_7){
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* result_25;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((&result_25));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_6;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_6));
  if ((*v_7).ov_0 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_6);
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_80 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL));
    X60Qx_6 = X60Qx_80;}
  else {
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_6);
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_81 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*(*v_7).ov_0).d_00.region_0);
    X60Qx_6 = X60Qx_81;}
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(result_25);
  result_25 = X60Qx_6;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_6));
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_6);
  return result_25;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_6);
  return result_25;}
static inline NI32 foff_0_valzr1t4f(Value_0_valzr1t4f* v_8){
  NI32 result_26;
  NI32 X60Qx_7;
  if ((*v_8).ov_0 == NIM_NIL){
    X60Qx_7 = ((NI32)0);}
  else {
    X60Qx_7 = (*(*v_8).ov_0).d_00.foff_0;}
  result_26 = X60Qx_7;
  return result_26;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0_valzr1t4f(Value_0_valzr1t4f* v_4){
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* result_22;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((&result_22));
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_3;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_3));
  if ((*v_4).ov_0 == NIM_NIL){
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_3);
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_76 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL));
    X60Qx_3 = X60Qx_76;}
  else {
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_3);
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_77 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*(*v_4).ov_0).d_00.arrOwn_0);
    X60Qx_3 = X60Qx_77;}
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(result_22);
  result_22 = X60Qx_3;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_3));
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_3);
  return result_22;
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_3);
  return result_22;}
static inline NI32 base_0_valzr1t4f(Value_0_valzr1t4f* v_6){
  NI32 result_24;
  NI64 X60Qx_5;
  if ((*v_6).ov_0 == NIM_NIL){
    X60Qx_5 = 0;}
  else {
    X60Qx_5 = (*(*v_6).ov_0).d_00.base_0;}
  result_24 = X60Qx_5;
  return result_24;}
static inline X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0_valzr1t4f(Value_0_valzr1t4f* v_5){
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* result_23;
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((&result_23));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_4;
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_4));
  if ((*v_5).ov_0 == NIM_NIL){
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_4);
    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_78 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL));
    X60Qx_4 = X60Qx_78;}
  else {
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_4);
    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_79 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*(*v_5).ov_0).d_00.seqOwn_0);
    X60Qx_4 = X60Qx_79;}
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(result_23);
  result_23 = X60Qx_4;
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_4));
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_4);
  return result_23;
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_4);
  return result_23;}
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0){
  NB8 result_127;
  NB8 X60Qx_284;
  NI32 X60Qx_285 = len_4_sysvq0asl(s_58);
  if (idx_2 < X60Qx_285){
    NC8 X60Qx_286 = getQ_9_sysvq0asl(s_58, idx_2);
    X60Qx_284 = (X60Qx_286 <= ch_0);}
  else {
    X60Qx_284 = NIM_FALSE;}
  result_127 = X60Qx_284;
  return result_127;}
static inline void eQwasMoved_1_I4kgdoh1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v* s_76){
  (*s_76).len_0 = 0;
  (*s_76).data_0 = NIM_NIL;}
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22){
  NI32 result_159;
  NB8 X60Qx_327;
  if (0 <= i_19){
    X60Qx_327 = (i_19 <= b_22);}
  else {
    X60Qx_327 = NIM_FALSE;}
  if (X60Qx_327){
    result_159 = i_19;}
  else {
    result_159 = 0;
    raiseIndexError3_0_I113jpc1_sysvq0asl(i_19, 0, b_22);}
  return result_159;}
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12){
  string_0_sysvq0asl* result_8;
  NI32 idx_3 = ((NI32)(((NI32)litId_12) - ((NI32)1)));
  if ((!(idx_3 < t_13.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  string_0_sysvq0asl* X60Qx_51 = getQ_7_Ir6d0tw_aow7lb5cq1(t_13.vals_0, idx_3);
  result_8 = X60Qx_51;
  return result_8;}
static inline string_0_sysvq0asl suffixToNif_0_prorcx25w1(string_0_sysvq0asl suffix_1){
  string_0_sysvq0asl result_11;
  nimStrWasMoved((&result_11));
  string_0_sysvq0asl X60Qx_1;
  nimStrWasMoved((&X60Qx_1));
  NB8 X60Qx_58 = eqQ_20_sysvq0asl(prog_0_prorcx25w1.main_0.ext_0, (string_0_sysvq0asl){
    .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
  );
  if (X60Qx_58){
    nimStrDestroy(X60Qx_1);
    X60Qx_1 = (string_0_sysvq0asl){
      .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
    ;}
  else {
    nimStrDestroy(X60Qx_1);
    X60Qx_1 = (string_0_sysvq0asl){
      .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
    ;}
  string_0_sysvq0asl ext_1 = X60Qx_1;
  nimStrWasMoved((&X60Qx_1));
  nimStrDestroy(result_11);
  string_0_sysvq0asl X60Qtmp_9 = slashQ_0_ospaexnw61(prog_0_prorcx25w1.main_0.dir_0, suffix_1);
  string_0_sysvq0asl X60Qx_59 = ampQ_0_sysvq0asl(X60Qtmp_9, ext_1);
  result_11 = X60Qx_59;
  nimStrDestroy(X60Qtmp_9);
  nimStrDestroy(ext_1);
  nimStrDestroy(X60Qx_1);
  return result_11;
  nimStrDestroy(X60Qtmp_9);
  nimStrDestroy(ext_1);
  nimStrDestroy(X60Qx_1);
  return result_11;}
static inline string_0_sysvq0asl vfsRead_0_vfsc9jn7(string_0_sysvq0asl path_1){
  string_0_sysvq0asl result_14;
  nimStrWasMoved((&result_14));
  nimStrDestroy(result_14);
  string_0_sysvq0asl X60Qx_16 = readBytesRelay_0_vfsc9jn7(path_1);
  result_14 = X60Qx_16;
  return result_14;}
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_75;
  if (size_8 == 0){
    result_75 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_I7me00i_aow7lb5cq1(size_8);
    void* X60Qx_2279 = alloc_1_sysvq0asl(memSize_1);
    result_75 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = ((string_0_sysvq0asl*)X60Qx_2279)}
    ;
    if ((!(result_75.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2280 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_75.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_75;}
static inline seq_0_Iflf8jf1_aow7lb5cq1 newSeqUninit_0_I5mozxi1_aow7lb5cq1(NI32 size_14){
  seq_0_Iflf8jf1_aow7lb5cq1 result_88;
  if (size_14 == 0){
    result_88 = (seq_0_Iflf8jf1_aow7lb5cq1){
      .len_0 = size_14, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_4 = memSizeInBytes_0_Ih4q01h_aow7lb5cq1(size_14);
    void* X60Qx_2300 = alloc_1_sysvq0asl(memSize_4);
    result_88 = (seq_0_Iflf8jf1_aow7lb5cq1){
      .len_0 = size_14, .data_0 = ((NB8*)X60Qx_2300)}
    ;
    if ((!(result_88.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2301 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_88.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_4);}}
  return result_88;}
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37){
  NI32 result_76;
  result_76 = s_37.len_0;
  return result_76;}
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39){
  NB8 X60Qx_2283;
  if (i_39 < s_38.len_0){
    X60Qx_2283 = (0 <= i_39);}
  else {
    X60Qx_2283 = NIM_FALSE;}
  if ((!X60Qx_2283)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* result_77;
  result_77 = (&s_38.data_0[i_39]);
  return result_77;}
static inline NB8* getQ_7_Iul1no9_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_55, NI32 i_45){
  NB8 X60Qx_2304;
  if (i_45 < s_55.len_0){
    X60Qx_2304 = (0 <= i_45);}
  else {
    X60Qx_2304 = NIM_FALSE;}
  if ((!X60Qx_2304)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NB8* result_89;
  result_89 = (&s_55.data_0[i_45]);
  return result_89;}
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9){
  NI32 L_0 = (*s_35).len_0;
  NI32 X60Qx_2281 = capInBytes_0_Ih2sbn01_aow7lb5cq1((*s_35));
  if (X60Qx_2281 < ((NI32)(((NI32)(L_0 * sizeof(string_0_sysvq0asl))) + sizeof(string_0_sysvq0asl)))){
    NB8 X60Qx_2282 = resize_0_I4buliy_aow7lb5cq1(s_35, 1);
    if ((!X60Qx_2282)){
      nimStrDestroy(elem_9);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_35).len_0));
  (*s_35).data_0[L_0] = elem_9;}
static inline void add_0_Irnc3p1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_53, NB8 elem_16){
  NI32 L_4 = (*s_53).len_0;
  NI32 X60Qx_2302 = capInBytes_0_In1m6ni_aow7lb5cq1((*s_53));
  if (X60Qx_2302 < ((NI32)(((NI32)(L_4 * sizeof(NB8))) + sizeof(NB8)))){
    NB8 X60Qx_2303 = resize_0_I2yw78g1_aow7lb5cq1(s_53, 1);
    if ((!X60Qx_2303)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_53).len_0));
  (*s_53).data_0[L_4] = elem_16;}
static inline NimonySym_0_nimry5ra91 symKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_11){
  NimonySym_0_nimry5ra91 result_9;
  NifKind_0_nif81dubp1 X60Qx_48 = kind_0_nifb6mq6y1(c_11);
  if (X60Qx_48 == 11){
    NU32 X60Qx_49 = tag_0_nifb6mq6y1(c_11);
    NB8 X60Qx_50 = rawTagIsNimonySym_0_nimry5ra91(((TagEnum_0_tagygirdh1)X60Qx_49));
    if (X60Qx_50){
      NU32 X60Qx_51 = tag_0_nifb6mq6y1(c_11);
      result_9 = ((NimonySym_0_nimry5ra91)((TagEnum_0_tagygirdh1)X60Qx_51));}
    else {
      result_9 = 0;}}
  else {
    result_9 = 0;}
  return result_9;}
static inline NB8 isRoutine_0_decqocs071(NimonySym_0_nimry5ra91 t_0){
  NB8 result_0;
  X60Qt_0_IAarrayAuS8ZS11_decqocs071 X60Qdesugar_0 = (X60Qt_0_IAarrayAuS8ZS11_decqocs071){
    .a = {
      0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 192u, 31u, 0u}}
  ;
  NU64 X60Qdesugar_1 = ((NU)t_0);
  result_0 = (((NU8)(X60Qdesugar_0.a[((NU)(X60Qdesugar_1 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_1 & 7u)))))) != 0u);
  return result_0;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
static inline NB8 isGeneric_0_decqocs071(Routine_0_decqocs071* r_0){
  NB8 result_9;
  NimonyOther_0_nimry5ra91 X60Qx_18 = substructureKind_1_nim30udrv((*r_0).typevars_0);
  result_9 = (X60Qx_18 == 91);
  return result_9;}
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33){
  NB8 X60Qx_314;
  if (i_33 < s_40.len_0){
    X60Qx_314 = (0 <= i_33);}
  else {
    X60Qx_314 = NIM_FALSE;}
  if ((!X60Qx_314)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_37;
  result_37 = (&s_40.data_0[i_33]);
  return result_37;}
static inline seq_0_In6doa_arecyyj7v newSeqUninit_0_Ieodq4s1_arecyyj7v(NI32 size_28){
  seq_0_In6doa_arecyyj7v result_67;
  if (size_28 == 0){
    result_67 = (seq_0_In6doa_arecyyj7v){
      .len_0 = size_28, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_18 = memSizeInBytes_0_Ivqzo5x1_arecyyj7v(size_28);
    void* X60Qx_378 = alloc_1_sysvq0asl(memSize_18);
    result_67 = (seq_0_In6doa_arecyyj7v){
      .len_0 = size_28, .data_0 = ((NU32*)X60Qx_378)}
    ;
    if ((!(result_67.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_379 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_67.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_18);}}
  return result_67;}
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37){
  NI32 result_34;
  result_34 = s_37.len_0;
  return result_34;}
static inline void add_0_I34il1q_der823rwr1(seq_0_In6doa_arecyyj7v* s_12, NU32 elem_2){
  NI32 L_0 = (*s_12).len_0;
  NI32 X60Qx_190 = capInBytes_0_Iev6wua1_arecyyj7v((*s_12));
  if (X60Qx_190 < ((NI32)(((NI32)(L_0 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_191 = resize_0_I6ho9ve_buiyylk1h1(s_12, 1);
    if ((!X60Qx_191)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_12).len_0));
  (*s_12).data_0[L_0] = elem_2;}
static inline void eQwasMoved_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_2){
  (*dest_2).data_0 = NIM_NIL;
  (*dest_2).len_0 = 0;
  (*dest_2).cap_0 = 0;
  (*dest_2).owner_0 = NIM_NIL;}
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3){
  if ((!((*dest_3).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*dest_3).owner_0).rc_0));
    if ((*(*dest_3).owner_0).rc_0 == 0){
      if ((!((*(*dest_3).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*dest_3).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*dest_3).owner_0)));}}
  else {
    if ((!((*dest_3).data_0 == NIM_NIL))){
      dealloc_1_sysvq0asl(((void*)(*dest_3).data_0));}}}
static inline NB8 ltQ_17_sysvq0asl(string_0_sysvq0asl a_53, string_0_sysvq0asl b_16){
  NB8 result_130;
  NI32 X60Qx_291 = cmp_1_sysvq0asl(a_53, b_16);
  result_130 = (X60Qx_291 < 0);
  return result_130;}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline openArray_0_Iu2js7k_intzsnzax toOpenArray_1_Ij5ojb01_intzsnzax(seq_0_Iw8xl5b1_arecyyj7v s_227){
  openArray_0_Iu2js7k_intzsnzax result_242;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_3859 = rawData_0_Iqcdbhc_intzsnzax(s_227);
  result_242 = (openArray_0_Iu2js7k_intzsnzax){
    .a_0 = X60Qx_3859, .len_0 = s_227.len_0}
  ;
  return result_242;}
static inline NI32 len_6_Ip8y5v7_intzsnzax(openArray_0_Iu2js7k_intzsnzax a_79){
  NI32 result_370;
  result_370 = a_79.len_0;
  return result_370;}
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_10_Ik17lqr_intzsnzax(openArray_0_Iu2js7k_intzsnzax x_36, NI32 idx_54){
  NB8 X60Qx_4212;
  if (0 <= idx_54){
    X60Qx_4212 = (idx_54 < x_36.len_0);}
  else {
    X60Qx_4212 = NIM_FALSE;}
  if ((!X60Qx_4212)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** result_371;
  result_371 = (&x_36.a_0[idx_54]);
  return result_371;}
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10){
  seq_0_Ift2sne_aow7lb5cq1 result_85;
  if (size_10 == 0){
    result_85 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Inv7kg3_aow7lb5cq1(size_10);
    void* X60Qx_2290 = alloc_1_sysvq0asl(memSize_2);
    result_85 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = ((NI32*)X60Qx_2290)}
    ;
    if ((!(result_85.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2291 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_85.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_85;}
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_42){
  NB8 X60Qx_2289;
  if (i_42 < s_46.len_0){
    X60Qx_2289 = (0 <= i_42);}
  else {
    X60Qx_2289 = NIM_FALSE;}
  if ((!X60Qx_2289)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NI32* result_84;
  result_84 = (&s_46.data_0[i_42]);
  return result_84;}
static inline Value_0_valzr1t4f vPtrLoc_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1){
  Value_0_valzr1t4f result_18;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_69 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(c_1);
  result_18 = (Value_0_valzr1t4f){
    .kind_0 = 13, .loc_0 = X60Qx_69, .ov_0 = ((X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v*)NIM_NIL)}
  ;
  return result_18;}
static inline void plusQeQ_0_Iz7fdp7_emi78vuj01(NI32* x_18, NI32 y_1){
  (*x_18) = ((NI32)((*x_18) + y_1));}
static inline X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 default_23_Isnz07p_hos5i19e11(void){
  X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 result_25;
  {
    NI32 X60Qlf_0 = ((NI32)0);
    NI32 X60Qlf_1 = ((NI32)65535);
    NI32 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 <= X60Qlf_1){
        {
          NI32 X60Qx_139 = nimIcheckB(X60Qlf_2, 65535);
          result_25.a[X60Qx_139] = (NC8)'\000';}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_25;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_43){
  openArray_0_Ig73pnk_aow7lb5cq1 result_80;
  string_0_sysvq0asl* X60Qx_2287 = rawData_0_I65w5sr_aow7lb5cq1(s_43);
  result_80 = (openArray_0_Ig73pnk_aow7lb5cq1){
    .a_0 = X60Qx_2287, .len_0 = s_43.len_0}
  ;
  return result_80;}
static inline openArray_0_I2902h9_intzsnzax toOpenArray_1_Ik4sb7f_intzsnzax(seq_0_I50urnw_croph25r5 s_173){
  openArray_0_I2902h9_intzsnzax result_219;
  Value_0_valzr1t4f* X60Qx_3796 = rawData_0_Ih1dm1f1_intzsnzax(s_173);
  result_219 = (openArray_0_I2902h9_intzsnzax){
    .a_0 = X60Qx_3796, .len_0 = s_173.len_0}
  ;
  return result_219;}
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15){
  NB8 X60Qx_259;
  NI32 X60Qx_260 = len_4_sysvq0asl((*s_55));
  if (i_15 < X60Qx_260){
    X60Qx_259 = (0 <= i_15);}
  else {
    X60Qx_259 = NIM_FALSE;}
  if ((!X60Qx_259)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I11201514831099767300_sysvq0asl)}
    );}
  prepareMutation_0_sysvq0asl(s_55);
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_55).bytes_0))))){
    (*(*s_55).more_0).data_0[i_15] = c_15;
    if (i_15 < ((NI32)3)){
      ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
  else {
    ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
static inline void putQ_7_I41w2p9_intzsnzax(seq_0_Iw8xl5b1_arecyyj7v* s_131, NI32 i_91, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_28){
  NB8 X60Qx_3719;
  if (i_91 < (*s_131).len_0){
    X60Qx_3719 = (0 <= i_91);}
  else {
    X60Qx_3719 = NIM_FALSE;}
  if ((!X60Qx_3719)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_719 = (&(*s_131).data_0[i_91]);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_720 = elem_28;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_intzsnzax((&elem_28));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_intzsnzax((*X60Qlhs_719));
  (*X60Qlhs_719) = X60Qlhs_720;
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_intzsnzax(elem_28);}
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_aow7lb5cq1(NI32 a_27, NI32 b_4){
  HSlice_0_Inzqy8d_aow7lb5cq1 result_94;
  result_94 = (HSlice_0_Inzqy8d_aow7lb5cq1){
    .a_0 = a_27, .b_0 = ((NI32)(b_4 - ((NI32)1)))}
  ;
  return result_94;}
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355){
  string_0_sysvq0asl result_224;
  nimStrWasMoved((&result_224));
  nimStrDestroy(result_224);
  string_0_sysvq0asl X60Qx_437 = substr_0_sysvq0asl(s_77, x_355.a_0, x_355.b_0);
  result_224 = X60Qx_437;
  return result_224;}
static inline seq_0_I50urnw_croph25r5 newSeqUninit_0_I8oufjc_croph25r5(NI32 size_10){
  seq_0_I50urnw_croph25r5 result_43;
  if (size_10 == 0){
    result_43 = (seq_0_I50urnw_croph25r5){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_7 = memSizeInBytes_0_Itmy7ww1_croph25r5(size_10);
    void* X60Qx_137 = alloc_1_sysvq0asl(memSize_7);
    result_43 = (seq_0_I50urnw_croph25r5){
      .len_0 = size_10, .data_0 = ((Value_0_valzr1t4f*)X60Qx_137)}
    ;
    if ((!(result_43.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_138 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_43.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_7);}}
  return result_43;}
static inline void add_0_Itre92n_intzsnzax(seq_0_I50urnw_croph25r5* s_140, Value_0_valzr1t4f elem_31){
  NI32 L_2 = (*s_140).len_0;
  NI32 X60Qx_3738 = capInBytes_0_Ihvsegh1_croph25r5((*s_140));
  if (X60Qx_3738 < ((NI32)(((NI32)(L_2 * sizeof(Value_0_valzr1t4f))) + sizeof(Value_0_valzr1t4f)))){
    NB8 X60Qx_3739 = resize_0_Iz8tg361_intzsnzax(s_140, 1);
    if ((!X60Qx_3739)){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&elem_31));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_140).len_0));
  (*s_140).data_0[L_2] = elem_31;}
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67){
  openArray_0_Ijk0jkw1_aow7lb5cq1 result_146;
  NC8* X60Qx_316 = readRawData_0_sysvq0asl((&(*s_67)), 0);
  NI32 X60Qx_317 = len_4_sysvq0asl((*s_67));
  result_146 = (openArray_0_Ijk0jkw1_aow7lb5cq1){
    .a_0 = X60Qx_316, .len_0 = X60Qx_317}
  ;
  return result_146;}
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_29){
  NI32 result_100;
  result_100 = a_29.len_0;
  return result_100;}
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6){
  NB8 X60Qx_2313;
  if (0 <= idx_6){
    X60Qx_2313 = (idx_6 < x_12.len_0);}
  else {
    X60Qx_2313 = NIM_FALSE;}
  if ((!X60Qx_2313)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NC8* result_101;
  result_101 = (&x_12.a_0[idx_6]);
  return result_101;}
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
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline NI32 capInBytes_0_Iih34tr1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_87){
  NI32 result_62;
  NI32 X60Qx_19;
  if ((!(s_87.data_0 == NIM_NIL))){
    NI32 X60Qx_374 = allocatedSize_0_sysvq0asl(((void*)((void*)s_87.data_0)));
    X60Qx_19 = X60Qx_374;}
  else {
    X60Qx_19 = 0;}
  result_62 = X60Qx_19;
  return result_62;}
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3){
  PackedToken_0_nifh7u8pu1 result_7;
  NB8 X60Qx_21;
  if ((!(c_3.p_0 == NIM_NIL))){
    X60Qx_21 = (0 < c_3.rem_0);}
  else {
    X60Qx_21 = NIM_FALSE;}
  if ((!X60Qx_21)){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_7 = (*c_3.p_0);
  return result_7;}
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15){
  NU32 result_42;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_15.x_0 & ((NU32)15u)))) == 11))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    string_0_sysvq0asl X60Qtmp_9 = dollarX60Q_NifKind_0_nif81dubp1(((NifKind_0_nif81dubp1)((NU32)(n_15.x_0 & ((NU32)15u)))));
    write_0_syn1lfpjv(stdout, X60Qtmp_9);
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);
    nimStrDestroy(X60Qtmp_9);}
  result_42 = ((NU32)((NU32)(n_15.x_0 >> ((NU32)4u))));
  return result_42;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline NI32 memSizeInBytes_0_Ixcobep_arecyyj7v(NI32 size_25){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_63;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_25, sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_63 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_63 = ((NI32)2147483647);}
  return result_63;}
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11){
  NU32 result_38;
  NU16 X60Qdesugar_2 = 48u;
  NU64 X60Qdesugar_3 = ((NU)((NifKind_0_nif81dubp1)((NU32)(n_11.x_0 & ((NU32)15u)))));
  if ((!(((NU16)(X60Qdesugar_2 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_3 & 15u)))))) != 0u))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_38 = ((NU32)((NU32)(n_11.x_0 >> ((NU32)4u))));
  return result_38;}
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12){
  NU32 result_39;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_12.x_0 & ((NU32)15u)))) == 8))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_39 = ((NU32)((NU32)(n_12.x_0 >> ((NU32)4u))));
  return result_39;}
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6){
  NB8 X60Qx_53;
  if (i_6 < s_9.len_0){
    X60Qx_53 = (0 <= i_6);}
  else {
    X60Qx_53 = NIM_FALSE;}
  if ((!X60Qx_53)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NI64* result_10;
  result_10 = (&s_9.data_0[i_6]);
  return result_10;}
static inline string_0_sysvq0asl slashQ_0_ospaexnw61(string_0_sysvq0asl head_1, string_0_sysvq0asl tail_2){
  string_0_sysvq0asl result_2;
  nimStrWasMoved((&result_2));
  string_0_sysvq0asl X60Qx_39 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  nimStrDestroy(result_2);
  string_0_sysvq0asl X60Qx_40 = joinPath_0_ospaexnw61(head_1, tail_2);
  result_2 = X60Qx_40;
  return result_2;}
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_99;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_19, sizeof(string_0_sysvq0asl), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_99 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_99 = ((NI32)2147483647);}
  return result_99;}
static inline NI32 memSizeInBytes_0_Ih4q01h_aow7lb5cq1(NI32 size_22){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_116;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_22, sizeof(NB8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_116 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_116 = ((NI32)2147483647);}
  return result_116;}
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65){
  NI32 result_102;
  NI32 X60Qx_18;
  if ((!(s_65.data_0 == NIM_NIL))){
    NI32 X60Qx_2314 = allocatedSize_0_sysvq0asl(((void*)((void*)s_65.data_0)));
    X60Qx_18 = X60Qx_2314;}
  else {
    X60Qx_18 = 0;}
  result_102 = X60Qx_18;
  return result_102;}
static inline NI32 capInBytes_0_In1m6ni_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_70){
  NI32 result_117;
  NI32 X60Qx_22;
  if ((!(s_70.data_0 == NIM_NIL))){
    NI32 X60Qx_2329 = allocatedSize_0_sysvq0asl(((void*)((void*)s_70.data_0)));
    X60Qx_22 = X60Qx_2329;}
  else {
    X60Qx_22 = 0;}
  result_117 = X60Qx_22;
  return result_117;}
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14){
  NU32 result_17;
  PackedToken_0_nifh7u8pu1 X60Qx_38 = load_0_nifb6mq6y1(c_14);
  NU32 X60Qx_39 = tag_0_nifh7u8pu1(X60Qx_38);
  result_17 = X60Qx_39;
  return result_17;}
static inline NB8 rawTagIsNimonySym_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_5){
  NB8 result_11;
  NB8 X60Qx_0;
  if (54 <= raw_5){
    X60Qx_0 = (raw_5 <= 80);}
  else {
    X60Qx_0 = NIM_FALSE;}
  result_11 = X60Qx_0;
  return result_11;}
static inline NimonyOther_0_nimry5ra91 substructureKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_6){
  NimonyOther_0_nimry5ra91 result_4;
  PackedToken_0_nifh7u8pu1 X60Qx_28 = load_0_nifb6mq6y1(c_6);
  NimonyOther_0_nimry5ra91 X60Qx_29 = substructureKind_0_nim30udrv(X60Qx_28);
  result_4 = X60Qx_29;
  return result_4;}
static inline NI32 memSizeInBytes_0_Ivqzo5x1_arecyyj7v(NI32 size_29){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_69;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_29, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_69 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_69 = ((NI32)2147483647);}
  return result_69;}
static inline NI32 capInBytes_0_Iev6wua1_arecyyj7v(seq_0_In6doa_arecyyj7v s_89){
  NI32 result_68;
  NI32 X60Qx_21;
  if ((!(s_89.data_0 == NIM_NIL))){
    NI32 X60Qx_380 = allocatedSize_0_sysvq0asl(((void*)((void*)s_89.data_0)));
    X60Qx_21 = X60Qx_380;}
  else {
    X60Qx_21 = 0;}
  result_68 = X60Qx_21;
  return result_68;}
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** rawData_0_Iqcdbhc_intzsnzax(seq_0_Iw8xl5b1_arecyyj7v s_333){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** result_369;
  result_369 = s_333.data_0;
  return result_369;}
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_110;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_20, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_110 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_110 = ((NI32)2147483647);}
  return result_110;}
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67){
  string_0_sysvq0asl* result_106;
  result_106 = s_67.data_0;
  return result_106;}
static inline Value_0_valzr1t4f* rawData_0_Ih1dm1f1_intzsnzax(seq_0_I50urnw_croph25r5 s_296){
  Value_0_valzr1t4f* result_341;
  result_341 = s_296.data_0;
  return result_341;}
static inline NI32 memSizeInBytes_0_Itmy7ww1_croph25r5(NI32 size_11){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_45;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_11, sizeof(Value_0_valzr1t4f), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_45 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_45 = ((NI32)2147483647);}
  return result_45;}
static inline NI32 capInBytes_0_Ihvsegh1_croph25r5(seq_0_I50urnw_croph25r5 s_30){
  NI32 result_44;
  NI32 X60Qx_6;
  if ((!(s_30.data_0 == NIM_NIL))){
    NI32 X60Qx_139 = allocatedSize_0_sysvq0asl(((void*)((void*)s_30.data_0)));
    X60Qx_6 = X60Qx_139;}
  else {
    X60Qx_6 = 0;}
  result_44 = X60Qx_6;
  return result_44;}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0){
  NC8* result_103;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_39).bytes_0))))){
    result_103 = ((NC8*)((NU32)(((NU32)(&(*(*s_39).more_0).data_0[0])) + ((NU32)start_0))));}
  else {
    result_103 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_39).bytes_0)) + 1u)))) + ((NU32)start_0))));}
  return result_103;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16){
  NU32 result_43;
  if (((NifKind_0_nif81dubp1)((NU32)(n_16.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_88 = tagId_0_nifh7u8pu1(n_16);
    result_43 = X60Qx_88;}
  else {
    result_43 = ErrT_0_nifh7u8pu1;}
  return result_43;}
static inline NimonyOther_0_nimry5ra91 substructureKind_0_nim30udrv(PackedToken_0_nifh7u8pu1 c_5){
  NimonyOther_0_nimry5ra91 result_3;
  NB8 X60Qx_24;
  if (((NifKind_0_nif81dubp1)((NU32)(c_5.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_25 = tag_0_nifh7u8pu1(c_5);
    NB8 X60Qx_26 = rawTagIsNimonyOther_0_nimry5ra91(((TagEnum_0_tagygirdh1)X60Qx_25));
    X60Qx_24 = X60Qx_26;}
  else {
    X60Qx_24 = NIM_FALSE;}
  if (X60Qx_24){
    NU32 X60Qx_27 = tag_0_nifh7u8pu1(c_5);
    result_3 = ((NimonyOther_0_nimry5ra91)X60Qx_27);}
  else {
    result_3 = 0;}
  return result_3;}
static inline NB8 rawTagIsNimonyOther_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_3){
  NB8 result_7;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_6 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      0u, 14u, 0u, 192u, 0u, 0u, 48u, 2u, 62u, 0u, 0u, 15u, 134u, 1u, 0u, 0u, 0u, 16u, 0u, 0u, 0u, 96u, 188u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
  ;
  NU64 X60Qdesugar_7 = ((NU)raw_3);
  result_7 = (((NU8)(X60Qdesugar_6.a[((NU)(X60Qdesugar_7 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_7 & 7u)))))) != 0u);
  return result_7;}
