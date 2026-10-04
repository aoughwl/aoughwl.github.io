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
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef NU8 SkipIntent_0_nifb6mq6y1;

#define SkipTag_0_nifb6mq6y1 ((NU8)0)
#define SkipParRi_0_nifb6mq6y1 ((NU8)1)
#define SkipName_0_nifb6mq6y1 ((NU8)2)
#define SkipExport_0_nifb6mq6y1 ((NU8)3)
#define SkipPragmas_0_nifb6mq6y1 ((NU8)4)
#define SkipType_0_nifb6mq6y1 ((NU8)5)
#define SkipExpr_0_nifb6mq6y1 ((NU8)6)
#define SkipStmt_0_nifb6mq6y1 ((NU8)7)
#define SkipValue_0_nifb6mq6y1 ((NU8)8)
#define SkipGenParams_0_nifb6mq6y1 ((NU8)9)
#define SkipCond_0_nifb6mq6y1 ((NU8)10)
#define SkipBody_0_nifb6mq6y1 ((NU8)11)
#define SkipEffects_0_nifb6mq6y1 ((NU8)12)
#define SkipResult_0_nifb6mq6y1 ((NU8)13)
#define SkipFull_0_nifb6mq6y1 ((NU8)14)
typedef NU8 TagClass_0_nifb6mq6y1;

#define Anything_0_nifb6mq6y1 ((NU8)0)
#define AnyExpr_0_nifb6mq6y1 ((NU8)1)
#define AnyStmt_0_nifb6mq6y1 ((NU8)2)
#define AnyType_0_nifb6mq6y1 ((NU8)3)
typedef struct openArray_0_I0m47e11_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* a_0;
  NI32 len_0;}
openArray_0_I0m47e11_nifb6mq6y1;
typedef struct seq_0_Iajrb23_nifb6mq6y1{
  NI32 len_0;
  PackedToken_0_nifh7u8pu1* data_0;}
seq_0_Iajrb23_nifb6mq6y1;
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
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
typedef struct seq_0_Io4pvgy1_nifb6mq6y1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Io4pvgy1_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S2_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1 a[2];}
X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S2_nifb6mq6y1;
typedef struct X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S1_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1 a[1];}
X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S1_nifb6mq6y1;
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
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
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
typedef struct Stream_0_nifh7u8pu1{
  Reader_0_nif81dubp1 r_0;
  seq_0_Io4pvgy1_nifb6mq6y1 parents_0;}
Stream_0_nifh7u8pu1;
typedef NU8 DirectivesResult_0_nif81dubp1;

#define WrongHeader_0_nif81dubp1 ((NU8)0)
#define WrongMeta_0_nif81dubp1 ((NU8)1)
#define Success_0_nif81dubp1 ((NU8)2)
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
openArray_0_I0m47e11_nifb6mq6y1 toOpenArray_3_Il7lkuv_nifb6mq6y1(PackedToken_0_nifh7u8pu1* x_9, NI32 first_2, NI32 last_2);
static inline void putQ_7_Ieeb9u61_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1* s_32, NI32 i_25, NU32 elem_10);
static inline openArray_0_I0m47e11_nifb6mq6y1 toOpenArray_0_Iq1nlhi1_nifb6mq6y1(X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S1_nifb6mq6y1* x_11);
static inline NI32 memSizeInBytes_0_Isupifd_nifb6mq6y1(NI32 size_49);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline NU32 litId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_9);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline NC8 charLit_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_10);
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12);
static inline NU32 uintId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_13);
static inline NU32 floatId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_14);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
extern void* alloc_1_sysvq0asl(NI32 size_24);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
extern void* alloc0_1_sysvq0asl(NI32 size_25);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
static inline PackedToken_0_nifh7u8pu1 parLeToken_0_nifh7u8pu1(NU32 t_0, NU32 info_9);
static inline PackedToken_0_nifh7u8pu1 parRiToken_0_nifh7u8pu1(NU32 info_2);
extern NU32 const NoLineInfo_0_linxafkvx1;
static inline PackedToken_0_nifh7u8pu1 dotToken_0_nifh7u8pu1(NU32 info_7);
extern NU32 getOrIncl_0_Ix6biej1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k* t_11, string_0_sysvq0asl v_1);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline PackedToken_0_nifh7u8pu1 strToken_0_nifh7u8pu1(NU32 id_5, NU32 info_15);
extern NU32 getOrIncl_0_I4rntkc_buiyylk1h1(BiTable_0_Itvq7bk_ast8ri79k* t_7, NI64 v_5);
static inline PackedToken_0_nifh7u8pu1 intToken_0_nifh7u8pu1(NU32 id_2, NU32 info_11);
extern NU32 getOrIncl_0_Icm7gb1_explnj22x1(BiTable_0_Itxao711_ast8ri79k* t_24, NU64 v_7);
static inline PackedToken_0_nifh7u8pu1 uintToken_0_nifh7u8pu1(NU32 id_3, NU32 info_12);
static inline PackedToken_0_nifh7u8pu1 identToken_0_nifh7u8pu1(NU32 s_0, NU32 info_5);
static inline NU32 getOrIncl_1_Ijmj1s_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_26, NF64 v_8);
static inline PackedToken_0_nifh7u8pu1 floatToken_0_nifh7u8pu1(NU32 id_4, NU32 info_13);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern string_0_sysvq0asl toString_0_nifh7u8pu1(openArray_0_I0m47e11_nifb6mq6y1 tree_1, NB8 produceLineInfo_0);
extern NU32 getOrIncl_0_Is83dq9_buiyylk1h1(BiTable_0_Icvz6lt_buiyylk1h1* t_3, string_0_sysvq0asl v_3);
extern PackedToken_0_nifh7u8pu1 next_0_nifh7u8pu1(Stream_0_nifh7u8pu1* s_5);
extern Stream_0_nifh7u8pu1 open_0_nifh7u8pu1(string_0_sysvq0asl filename_0);
extern DirectivesResult_0_nif81dubp1 processDirectives_0_nif81dubp1(Reader_0_nif81dubp1* r_11);
extern void eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1(Stream_0_nifh7u8pu1* dest_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_bitekkhcx1(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern NU32 const ErrT_0_nifh7u8pu1;
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iz0lv7d1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_12, NU32 id_16, NU32 info_31);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ie5j2hb_nifh7u8pu1(NifKind_0_nif81dubp1 kind_11, NU32 id_15, NU32 info_30);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ika21pk_nifh7u8pu1(NifKind_0_nif81dubp1 kind_9, NU32 id_13, NU32 info_28);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Is7quwk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_13, NU32 id_17, NU32 info_32);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ikm2gt2_nifh7u8pu1(NifKind_0_nif81dubp1 kind_14, NU32 id_18, NU32 info_33);
extern NU32 getOrIncl_0_Ivbdpqo_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_35, NU64 v_10);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ifgbqjw1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_15, NU32 id_19, NU32 info_34);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
LongString_0_sysvq0asl const strlit_0_I17128882682348225350_nifb6mq6y1 = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "consumeParRi: cursor not at ParRi"}
;
LongString_0_sysvq0asl const strlit_0_I3807893400126689806_nifb6mq6y1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cursor at end\?"}
;
LongString_0_sysvq0asl const strlit_0_I6597381209844855110_nifb6mq6y1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "parsing "}
;
LongString_0_sysvq0asl const strlit_0_I5667823097063552622_nifb6mq6y1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "Anything"}
;
LongString_0_sysvq0asl const strlit_0_I9993243300318027214_nifb6mq6y1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AnyExpr"}
;
LongString_0_sysvq0asl const strlit_0_I14573359324850232186_nifb6mq6y1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AnyStmt"}
;
LongString_0_sysvq0asl const strlit_0_I3796628542686513035_nifb6mq6y1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AnyType"}
;
X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S2_nifb6mq6y1 ErrToken_0_nifb6mq6y1;
NB8 X60QiniGuard_0_nifb6mq6y1;
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1){
  Cursor_0_nifb6mq6y1 result_4;
  result_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = src_1.owner_0, .p_0 = src_1.p_0, .rem_0 = src_1.rem_0}
  ;
  if ((!(result_4.owner_0 == NIM_NIL))){
    inc_1_I6wjjge_aow2h993l1((&(*result_4.owner_0).rc_0));}
  return result_4;}
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
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
static inline NU32 info_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_5){
  NU32 result_9;
  PackedToken_0_nifh7u8pu1 X60Qx_23 = load_0_nifb6mq6y1(c_5);
  result_9 = X60Qx_23.info_0;
  return result_9;}
static inline NU32 litId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_7){
  NU32 result_10;
  PackedToken_0_nifh7u8pu1 X60Qx_24 = load_0_nifb6mq6y1(c_7);
  NU32 X60Qx_25 = litId_0_nifh7u8pu1(X60Qx_24);
  result_10 = X60Qx_25;
  return result_10;}
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8){
  NU32 result_11;
  PackedToken_0_nifh7u8pu1 X60Qx_26 = load_0_nifb6mq6y1(c_8);
  NU32 X60Qx_27 = symId_0_nifh7u8pu1(X60Qx_26);
  result_11 = X60Qx_27;
  return result_11;}
static inline NC8 charLit_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_9){
  NC8 result_12;
  PackedToken_0_nifh7u8pu1 X60Qx_28 = load_0_nifb6mq6y1(c_9);
  NC8 X60Qx_29 = charLit_0_nifh7u8pu1(X60Qx_28);
  result_12 = X60Qx_29;
  return result_12;}
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10){
  NU32 result_13;
  PackedToken_0_nifh7u8pu1 X60Qx_30 = load_0_nifb6mq6y1(c_10);
  NU32 X60Qx_31 = intId_0_nifh7u8pu1(X60Qx_30);
  result_13 = X60Qx_31;
  return result_13;}
static inline NU32 uintId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_11){
  NU32 result_14;
  PackedToken_0_nifh7u8pu1 X60Qx_32 = load_0_nifb6mq6y1(c_11);
  NU32 X60Qx_33 = uintId_0_nifh7u8pu1(X60Qx_32);
  result_14 = X60Qx_33;
  return result_14;}
static inline NU32 floatId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_12){
  NU32 result_15;
  PackedToken_0_nifh7u8pu1 X60Qx_34 = load_0_nifb6mq6y1(c_12);
  NU32 X60Qx_35 = floatId_0_nifh7u8pu1(X60Qx_34);
  result_15 = X60Qx_35;
  return result_15;}
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13){
  NU32 result_16;
  PackedToken_0_nifh7u8pu1 X60Qx_36 = load_0_nifb6mq6y1(c_13);
  NU32 X60Qx_37 = tagId_0_nifh7u8pu1(X60Qx_36);
  result_16 = X60Qx_37;
  return result_16;}
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14){
  NU32 result_17;
  PackedToken_0_nifh7u8pu1 X60Qx_38 = load_0_nifb6mq6y1(c_14);
  NU32 X60Qx_39 = tag_0_nifh7u8pu1(X60Qx_38);
  result_17 = X60Qx_39;
  return result_17;}
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
static inline void consumeParRi_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_19){
  NifKind_0_nif81dubp1 X60Qx_44 = kind_0_nifb6mq6y1((*c_19));
  if ((!(X60Qx_44 == 12))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I17128882682348225350_nifb6mq6y1)}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  inc_0_nifb6mq6y1(c_19);}
void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24){
  NifKind_0_nif81dubp1 X60Qx_46 = kind_0_nifb6mq6y1((*c_24));
  if (X60Qx_46 == 11){
    NI32 nested_0 = 0;
    {
      while (NIM_TRUE){
        inc_0_nifb6mq6y1(c_24);
        NifKind_0_nif81dubp1 X60Qx_47 = kind_0_nifb6mq6y1((*c_24));
        if (X60Qx_47 == 12){
          if (nested_0 == 0){
            goto whileStmtLabel_0;}
          dec_1_I0nzoz91_aow7lb5cq1((&nested_0));}
        else {
          NifKind_0_nif81dubp1 X60Qx_48 = kind_0_nifb6mq6y1((*c_24));
          if (X60Qx_48 == 11){
            inc_1_I6wjjge_aow2h993l1((&nested_0));}}}}
    whileStmtLabel_0: ;}
  inc_0_nifb6mq6y1(c_24);}
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
TokenBuf_0_nifb6mq6y1 createTokenBuf_0_nifb6mq6y1(NI32 cap_1){
  TokenBuf_0_nifb6mq6y1 result_25;
  eQwasMoved_1_nifb6mq6y1((&result_25));
  eQdestroy_1_nifb6mq6y1((&result_25));
  NI32 X60Qx_59 = max_2_sysvq0asl(cap_1, 8);
  void* X60Qx_60 = alloc_1_sysvq0asl(((NI32)(sizeof(PackedToken_0_nifh7u8pu1) * X60Qx_59)));
  result_25 = (TokenBuf_0_nifb6mq6y1){
    .data_0 = ((PackedToken_0_nifh7u8pu1*)X60Qx_60), .len_0 = 0, .cap_0 = cap_1, .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL)}
  ;
  return result_25;}
static inline void prepareMutation_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_0){
  if ((!((*b_0).owner_0 == NIM_NIL))){
    if ((*(*b_0).owner_0).rc_0 == 1){
      dealloc_1_sysvq0asl(((void*)(*b_0).owner_0));
      (*b_0).owner_0 = NIM_NIL;}
    else {
      NI32 X60Qx_61 = max_2_sysvq0asl((*b_0).cap_0, 8);
      void* X60Qx_62 = alloc_1_sysvq0asl(((NI32)(sizeof(PackedToken_0_nifh7u8pu1) * X60Qx_61)));
      PackedToken_0_nifh7u8pu1* newData_0 = ((PackedToken_0_nifh7u8pu1*)X60Qx_62);
      copyMem_0_sysvq0asl(((void*)newData_0), ((void*)(*b_0).data_0), ((NI32)(sizeof(PackedToken_0_nifh7u8pu1) * (*b_0).len_0)));
      dec_1_I0nzoz91_aow7lb5cq1((&(*(*b_0).owner_0).rc_0));
      if ((*(*b_0).owner_0).rc_0 == 0){
        if ((!((*(*b_0).owner_0).data_0 == NIM_NIL))){
          dealloc_1_sysvq0asl(((void*)((void*)(*(*b_0).owner_0).data_0)));}
        dealloc_1_sysvq0asl(((void*)((void*)(*b_0).owner_0)));}
      (*b_0).owner_0 = NIM_NIL;
      (*b_0).data_0 = newData_0;}}}
Cursor_0_nifb6mq6y1 beginRead_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_4){
  Cursor_0_nifb6mq6y1 result_26;
  eQwasMoved_0_nifb6mq6y1((&result_26));
  if ((*b_4).owner_0 == NIM_NIL){
    void* X60Qx_63 = alloc0_1_sysvq0asl(sizeof(CursorOwnerObj_0_nifb6mq6y1));
    (*b_4).owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)X60Qx_63);
    (*(*b_4).owner_0).data_0 = (*b_4).data_0;
    (*(*b_4).owner_0).rc_0 = 1;}
  inc_1_I6wjjge_aow2h993l1((&(*(*b_4).owner_0).rc_0));
  eQdestroy_0_nifb6mq6y1((&result_26));
  result_26 = (Cursor_0_nifb6mq6y1){
    .owner_0 = (*b_4).owner_0, .p_0 = (&(*b_4).data_0[0]), .rem_0 = (*b_4).len_0}
  ;
  return result_26;}
static inline void endRead_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_5){
  }
static inline void add_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_7, PackedToken_0_nifh7u8pu1 item_1){
  if ((!((*b_7).owner_0 == NIM_NIL))){
    prepareMutation_0_nifb6mq6y1(b_7);}
  if ((*b_7).cap_0 <= (*b_7).len_0){
    NI32 X60Qx_66 = max_2_sysvq0asl(((NI32)(((NI32)((*b_7).cap_0 / 2)) + (*b_7).cap_0)), 8);
    (*b_7).cap_0 = X60Qx_66;
    void* X60Qx_67 = realloc_1_sysvq0asl(((void*)(*b_7).data_0), ((NI32)(sizeof(PackedToken_0_nifh7u8pu1) * (*b_7).cap_0)));
    (*b_7).data_0 = ((PackedToken_0_nifh7u8pu1*)X60Qx_67);}
  (*b_7).data_0[(*b_7).len_0] = item_1;
  inc_1_I6wjjge_aow2h993l1((&(*b_7).len_0));}
static inline Cursor_0_nifb6mq6y1 cursorAt_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_11, NI32 i_2){
  Cursor_0_nifb6mq6y1 result_29;
  eQwasMoved_0_nifb6mq6y1((&result_29));
  NB8 X60Qx_70;
  if (0 <= i_2){
    X60Qx_70 = (i_2 < (*b_11).len_0);}
  else {
    X60Qx_70 = NIM_FALSE;}
  if ((!X60Qx_70)){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  if ((*b_11).owner_0 == NIM_NIL){
    void* X60Qx_71 = alloc0_1_sysvq0asl(sizeof(CursorOwnerObj_0_nifb6mq6y1));
    (*b_11).owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)X60Qx_71);
    (*(*b_11).owner_0).data_0 = (*b_11).data_0;
    (*(*b_11).owner_0).rc_0 = 1;}
  inc_1_I6wjjge_aow2h993l1((&(*(*b_11).owner_0).rc_0));
  eQdestroy_0_nifb6mq6y1((&result_29));
  result_29 = (Cursor_0_nifb6mq6y1){
    .owner_0 = (*b_11).owner_0, .p_0 = (&(*b_11).data_0[i_2]), .rem_0 = ((NI32)((*b_11).len_0 - i_2))}
  ;
  return result_29;}
static inline NI32 cursorToPosition_1_nifb6mq6y1(Cursor_0_nifb6mq6y1 base_0, Cursor_0_nifb6mq6y1 c_30){
  NI32 result_33;
  NI32 c_46 = ((NI32)c_30.p_0);
  NI32 base_1 = ((NI32)base_0.p_0);
  if ((!(base_1 <= c_46))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_33 = ((NI32)(((NI32)(c_46 - base_1)) / sizeof(PackedToken_0_nifh7u8pu1)));
  if ((!(result_33 < 1000000))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  return result_33;}
static inline NI32 toUniqueId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_31){
  NI32 result_34;
  result_34 = ((NI32)c_31.p_0);
  return result_34;}
void addSubtree_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* result_1, Cursor_0_nifb6mq6y1 c_34){
  NifKind_0_nif81dubp1 X60Qx_78 = kind_0_nifb6mq6y1(c_34);
  if ((!(!(X60Qx_78 == 12)))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I3807893400126689806_nifb6mq6y1)}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NifKind_0_nif81dubp1 X60Qx_79 = kind_0_nifb6mq6y1(c_34);
  if ((!(X60Qx_79 == 11))){
    PackedToken_0_nifh7u8pu1 X60Qx_80 = load_0_nifb6mq6y1(c_34);
    add_0_nifb6mq6y1(result_1, X60Qx_80);}
  else {
    Cursor_0_nifb6mq6y1 c_47 = eQdup_0_nifb6mq6y1(c_34);
    NI32 nested_3 = 0;
    {
      while (NIM_TRUE){
        PackedToken_0_nifh7u8pu1 item_2 = load_0_nifb6mq6y1(c_47);
        add_0_nifb6mq6y1(result_1, item_2);
        if (((NifKind_0_nif81dubp1)((NU32)(item_2.x_0 & ((NU32)15u)))) == 12){
          dec_1_I0nzoz91_aow7lb5cq1((&nested_3));
          if (nested_3 == 0){
            goto whileStmtLabel_0;}}
        else {
          if (((NifKind_0_nif81dubp1)((NU32)(item_2.x_0 & ((NU32)15u)))) == 11){
            inc_1_I6wjjge_aow2h993l1((&nested_3));}}
        inc_0_nifb6mq6y1((&c_47));}}
    whileStmtLabel_0: ;
    inc_0_nifb6mq6y1((&c_47));
    eQdestroy_0_nifb6mq6y1((&c_47));}}
void addParLe_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_10, NU32 tag_1, NU32 info_4){
  PackedToken_0_nifh7u8pu1 X60Qx_87 = parLeToken_0_nifh7u8pu1(tag_1, info_4);
  add_0_nifb6mq6y1(dest_10, X60Qx_87);}
void addParRi_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_11){
  PackedToken_0_nifh7u8pu1 X60Qx_88 = parRiToken_0_nifh7u8pu1(NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1(dest_11, X60Qx_88);}
void addDotToken_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_14){
  PackedToken_0_nifh7u8pu1 X60Qx_91 = dotToken_0_nifh7u8pu1(NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1(dest_14, X60Qx_91);}
void addStrLit_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_15, string_0_sysvq0asl s_4, NU32 info_7){
  NU32 X60Qx_92 = getOrIncl_0_Ix6biej1_ast8ri79k((&pool_0_nifh7u8pu1.strings_0), s_4);
  PackedToken_0_nifh7u8pu1 X60Qx_93 = strToken_0_nifh7u8pu1(X60Qx_92, info_7);
  add_0_nifb6mq6y1(dest_15, X60Qx_93);}
void addIntLit_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_16, NI64 i_4, NU32 info_8){
  NU32 X60Qx_94 = getOrIncl_0_I4rntkc_buiyylk1h1((&pool_0_nifh7u8pu1.integers_0), i_4);
  PackedToken_0_nifh7u8pu1 X60Qx_95 = intToken_0_nifh7u8pu1(X60Qx_94, info_8);
  add_0_nifb6mq6y1(dest_16, X60Qx_95);}
void addUIntLit_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_17, NU64 i_5, NU32 info_9){
  NU32 X60Qx_96 = getOrIncl_0_Icm7gb1_explnj22x1((&pool_0_nifh7u8pu1.uintegers_0), i_5);
  PackedToken_0_nifh7u8pu1 X60Qx_97 = uintToken_0_nifh7u8pu1(X60Qx_96, info_9);
  add_0_nifb6mq6y1(dest_17, X60Qx_97);}
void addIdent_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_18, string_0_sysvq0asl s_5, NU32 info_10){
  NU32 X60Qx_98 = getOrIncl_0_Ix6biej1_ast8ri79k((&pool_0_nifh7u8pu1.strings_0), s_5);
  PackedToken_0_nifh7u8pu1 X60Qx_99 = identToken_0_nifh7u8pu1(X60Qx_98, info_10);
  add_0_nifb6mq6y1(dest_18, X60Qx_99);}
void addFloatLit_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_20, NF64 f_0, NU32 info_12){
  NU32 X60Qx_101 = getOrIncl_1_Ijmj1s_explnj22x1((&pool_0_nifh7u8pu1.floats_0), f_0);
  PackedToken_0_nifh7u8pu1 X60Qx_102 = floatToken_0_nifh7u8pu1(X60Qx_101, info_12);
  add_0_nifb6mq6y1(dest_20, X60Qx_102);}
NI32 span_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_38){
  NI32 result_37;
  result_37 = 0;
  Cursor_0_nifb6mq6y1 c_50 = eQdup_0_nifb6mq6y1(c_38);
  NifKind_0_nif81dubp1 X60Qx_103 = kind_0_nifb6mq6y1(c_50);
  if (X60Qx_103 == 11){
    NI32 nested_5 = 0;
    {
      while (NIM_TRUE){
        inc_0_nifb6mq6y1((&c_50));
        inc_1_I6wjjge_aow2h993l1((&result_37));
        NifKind_0_nif81dubp1 X60Qx_104 = kind_0_nifb6mq6y1(c_50);
        if (X60Qx_104 == 12){
          if (nested_5 == 0){
            goto whileStmtLabel_0;}
          dec_1_I0nzoz91_aow7lb5cq1((&nested_5));}
        else {
          NifKind_0_nif81dubp1 X60Qx_105 = kind_0_nifb6mq6y1(c_50);
          if (X60Qx_105 == 11){
            inc_1_I6wjjge_aow2h993l1((&nested_5));}}}}
    whileStmtLabel_0: ;}
  if (0 < c_50.rem_0){
    inc_0_nifb6mq6y1((&c_50));
    inc_1_I6wjjge_aow2h993l1((&result_37));}
  eQdestroy_0_nifb6mq6y1((&c_50));
  return result_37;
  eQdestroy_0_nifb6mq6y1((&c_50));
  return result_37;}
string_0_sysvq0asl toString_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1 b_18, NB8 produceLineInfo_0){
  string_0_sysvq0asl result_38;
  nimStrWasMoved((&result_38));
  nimStrDestroy(result_38);
  openArray_0_I0m47e11_nifb6mq6y1 X60Qx_116 = toOpenArray_3_Il7lkuv_nifb6mq6y1(b_18.data_0, 0, ((NI32)(b_18.len_0 - 1)));
  string_0_sysvq0asl X60Qx_117 = toString_0_nifh7u8pu1(X60Qx_116, produceLineInfo_0);
  result_38 = X60Qx_117;
  return result_38;}
static inline PackedToken_0_nifh7u8pu1 parLeTokenUnchecked_0_nifb6mq6y1(string_0_sysvq0asl tag_3, NU32 info_14){
  PackedToken_0_nifh7u8pu1 result_43;
  NU32 X60Qx_130 = getOrIncl_0_Is83dq9_buiyylk1h1((&pool_0_nifh7u8pu1.tags_0), tag_3);
  PackedToken_0_nifh7u8pu1 X60Qx_131 = parLeToken_0_nifh7u8pu1(X60Qx_130, info_14);
  result_43 = X60Qx_131;
  return result_43;}
void parse_0_nifb6mq6y1(Stream_0_nifh7u8pu1* r_0, TokenBuf_0_nifb6mq6y1* dest_27, NU32 parentInfo_0, NB8 debug_0){
  putQ_7_Ieeb9u61_nifb6mq6y1((&(*r_0).parents_0), 0, parentInfo_0);
  NI32 nested_7 = 0;
  {
    while (NIM_TRUE){
      PackedToken_0_nifh7u8pu1 tok_0 = next_0_nifh7u8pu1(r_0);
      add_0_nifb6mq6y1(dest_27, tok_0);
      if (debug_0){
        write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
          .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I6597381209844855110_nifb6mq6y1)}
        );
        X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S1_nifb6mq6y1 X60QconstRefTemp_0 = (X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S1_nifb6mq6y1){
          .a = {
            tok_0}}
        ;
        openArray_0_I0m47e11_nifb6mq6y1 X60Qx_132 = toOpenArray_0_Iq1nlhi1_nifb6mq6y1((&X60QconstRefTemp_0));
        string_0_sysvq0asl X60Qtmp_3 = toString_0_nifh7u8pu1(X60Qx_132, NIM_FALSE);
        write_0_syn1lfpjv(stdout, X60Qtmp_3);
        write_7_syn1lfpjv(stdout, (NC8)'\012');
        if (((NifKind_0_nif81dubp1)((NU32)(tok_0.x_0 & ((NU32)15u)))) == 0){
          nimStrDestroy(X60Qtmp_3);
          goto whileStmtLabel_0;}
        nimStrDestroy(X60Qtmp_3);}
      if (((NifKind_0_nif81dubp1)((NU32)(tok_0.x_0 & ((NU32)15u)))) == 1){
        goto whileStmtLabel_0;}
      else {
        if (((NifKind_0_nif81dubp1)((NU32)(tok_0.x_0 & ((NU32)15u)))) == 11){
          inc_1_I6wjjge_aow2h993l1((&nested_7));}
        else {
          if (((NifKind_0_nif81dubp1)((NU32)(tok_0.x_0 & ((NU32)15u)))) == 12){
            dec_1_I0nzoz91_aow7lb5cq1((&nested_7));
            if (nested_7 == 0){
              goto whileStmtLabel_0;}}}}}}
  whileStmtLabel_0: ;}
TokenBuf_0_nifb6mq6y1 parseFromFile_0_nifb6mq6y1(string_0_sysvq0asl filename_1, NI32 sizeHint_1){
  TokenBuf_0_nifb6mq6y1 result_45;
  eQwasMoved_1_nifb6mq6y1((&result_45));
  Stream_0_nifh7u8pu1 r_2 = open_0_nifh7u8pu1(filename_1);
  DirectivesResult_0_nif81dubp1 X60Qx_135 = processDirectives_0_nif81dubp1((&r_2.r_0));
  eQdestroy_1_nifb6mq6y1((&result_45));
  TokenBuf_0_nifb6mq6y1 X60Qx_136 = createTokenBuf_0_nifb6mq6y1(sizeHint_1);
  result_45 = X60Qx_136;
  parse_0_nifb6mq6y1((&r_2), (&result_45), NoLineInfo_0_linxafkvx1, NIM_FALSE);
  eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1((&r_2));
  return result_45;
  eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1((&r_2));
  return result_45;}
string_0_sysvq0asl dollarX60Q_TagClass_0_nifb6mq6y1(TagClass_0_nifb6mq6y1 e_1){
  string_0_sysvq0asl result_50;
  nimStrWasMoved((&result_50));
  switch (e_1){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2037268990u, .more_0 = (&strlit_0_I5667823097063552622_nifb6mq6y1)}
      ;}
    break;
    case 1:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2037268990u, .more_0 = (&strlit_0_I9993243300318027214_nifb6mq6y1)}
      ;}
    break;
    case 2:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2037268990u, .more_0 = (&strlit_0_I14573359324850232186_nifb6mq6y1)}
      ;}
    break;
    case 3:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 2037268990u, .more_0 = (&strlit_0_I3796628542686513035_nifb6mq6y1)}
      ;}
    break;}
  return result_50;}
static inline NB8 tagClassMatches_0_nifb6mq6y1(NifKind_0_nif81dubp1 k_1, TagClass_0_nifb6mq6y1 expected_0){
  NB8 result_51;
  NB8 X60Qx_3;
  switch (expected_0){
    case 0:
    {
      X60Qx_3 = (!(k_1 == 1));}
    break;
    case 1:
    {
      NU16 X60Qdesugar_24 = 4098u;
      NU64 X60Qdesugar_25 = ((NU)k_1);
      X60Qx_3 = (!(((NU16)(X60Qdesugar_24 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_25 & 15u)))))) != 0u));}
    break;
    case 2:
    {
      NU16 X60Qdesugar_26 = 2052u;
      NU64 X60Qdesugar_27 = ((NU)k_1);
      X60Qx_3 = (((NU16)(X60Qdesugar_26 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_27 & 15u)))))) != 0u);}
    break;
    case 3:
    {
      NU16 X60Qdesugar_28 = 2076u;
      NU64 X60Qdesugar_29 = ((NU)k_1);
      X60Qx_3 = (((NU16)(X60Qdesugar_28 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_29 & 15u)))))) != 0u);}
    break;}
  result_51 = X60Qx_3;
  return result_51;}
static inline PackedToken_0_nifh7u8pu1* getQ_10_Iids335_nifb6mq6y1(openArray_0_I0m47e11_nifb6mq6y1 x_8, NI32 idx_1){
  NB8 X60Qx_141;
  if (0 <= idx_1){
    X60Qx_141 = (idx_1 < x_8.len_0);}
  else {
    X60Qx_141 = NIM_FALSE;}
  if ((!X60Qx_141)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  PackedToken_0_nifh7u8pu1* result_52;
  result_52 = (&x_8.a_0[idx_1]);
  return result_52;}
static inline NI32 len_6_I4emj7h_nifb6mq6y1(openArray_0_I0m47e11_nifb6mq6y1 a_4){
  NI32 result_53;
  result_53 = a_4.len_0;
  return result_53;}
openArray_0_I0m47e11_nifb6mq6y1 toOpenArray_3_Il7lkuv_nifb6mq6y1(PackedToken_0_nifh7u8pu1* x_9, NI32 first_2, NI32 last_2){
  openArray_0_I0m47e11_nifb6mq6y1 result_58;
  result_58 = (openArray_0_I0m47e11_nifb6mq6y1){
    .a_0 = ((PackedToken_0_nifh7u8pu1*)((NU32)(((NU32)x_9) + ((NU32)((NI32)(first_2 * sizeof(PackedToken_0_nifh7u8pu1))))))), .len_0 = ((NI32)(((NI32)(last_2 - first_2)) + 1))}
  ;
  return result_58;}
static inline void putQ_7_Ieeb9u61_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1* s_32, NI32 i_25, NU32 elem_10){
  NB8 X60Qx_198;
  if (i_25 < (*s_32).len_0){
    X60Qx_198 = (0 <= i_25);}
  else {
    X60Qx_198 = NIM_FALSE;}
  if ((!X60Qx_198)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_32).data_0[i_25] = elem_10;}
static inline openArray_0_I0m47e11_nifb6mq6y1 toOpenArray_0_Iq1nlhi1_nifb6mq6y1(X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S1_nifb6mq6y1* x_11){
  openArray_0_I0m47e11_nifb6mq6y1 result_60;
  openArray_0_I0m47e11_nifb6mq6y1 X60Qx_4;
  if (((NI32)(((NI32)(((NI32)((NI32)0)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_4 = (openArray_0_I0m47e11_nifb6mq6y1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_4 = (openArray_0_I0m47e11_nifb6mq6y1){
      .a_0 = ((PackedToken_0_nifh7u8pu1*)(&(*x_11))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)0)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_60 = X60Qx_4;
  return result_60;}
static inline void dec_0_Ig5i8xp_nifb6mq6y1(NI32* x_18, NI32 y_4){
  (*x_18) = ((NI32)((*x_18) - y_4));}
void eQdestroy_1_I35tn0j_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1 s_168){
  if ((!(s_168.data_0 == NIM_NIL))){
    NI32 i_108 = 0;
    {
      while (i_108 < s_168.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_108));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_168.data_0)));}}
static inline void eQwasMoved_1_Igz5mgz_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1* s_169){
  (*s_169).len_0 = 0;
  (*s_169).data_0 = NIM_NIL;}
static inline seq_0_Io4pvgy1_nifb6mq6y1 newSeqUninit_0_Ijkckzz_nifb6mq6y1(NI32 size_48){
  seq_0_Io4pvgy1_nifb6mq6y1 result_141;
  if (size_48 == 0){
    result_141 = (seq_0_Io4pvgy1_nifb6mq6y1){
      .len_0 = size_48, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_33 = memSizeInBytes_0_Isupifd_nifb6mq6y1(size_48);
    void* X60Qx_382 = alloc_1_sysvq0asl(memSize_33);
    result_141 = (seq_0_Io4pvgy1_nifb6mq6y1){
      .len_0 = size_48, .data_0 = ((NU32*)X60Qx_382)}
    ;
    if ((!(result_141.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_383 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_141.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_33);}}
  return result_141;}
static inline NI32 capInBytes_0_Id76iiw1_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1 s_171){
  NI32 result_142;
  NI32 X60Qx_14;
  if ((!(s_171.data_0 == NIM_NIL))){
    NI32 X60Qx_384 = allocatedSize_0_sysvq0asl(((void*)((void*)s_171.data_0)));
    X60Qx_14 = X60Qx_384;}
  else {
    X60Qx_14 = 0;}
  result_142 = X60Qx_14;
  return result_142;}
static inline NI32 memSizeInBytes_0_Isupifd_nifb6mq6y1(NI32 size_49){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_143;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_49, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_143 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_143 = ((NI32)2147483647);}
  return result_143;}
void X60Qini_0_nifb6mq6y1(void){
  if (X60QiniGuard_0_nifb6mq6y1){
    return;}
  X60QiniGuard_0_nifb6mq6y1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_assy765wm();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_linxafkvx1();
  X60Qini_0_vfsc9jn7();
  PackedToken_0_nifh7u8pu1 X60Qx_16 = parLeToken_0_nifh7u8pu1(ErrT_0_nifh7u8pu1, NoLineInfo_0_linxafkvx1);
  PackedToken_0_nifh7u8pu1 X60Qx_17 = parRiToken_0_nifh7u8pu1(NoLineInfo_0_linxafkvx1);
  ErrToken_0_nifb6mq6y1 = (X60Qt_0_IAarraySX50ackedX54oken0nifh7u8pu1S2_nifb6mq6y1){
    .a = {
      X60Qx_16, X60Qx_17}}
  ;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NU32 litId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_9){
  NU32 result_36;
  NU16 X60Qdesugar_0 = 72u;
  NU64 X60Qdesugar_1 = ((NU)((NifKind_0_nif81dubp1)((NU32)(n_9.x_0 & ((NU32)15u)))));
  if ((!(((NU16)(X60Qdesugar_0 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_1 & 15u)))))) != 0u))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_36 = ((NU32)((NU32)(n_9.x_0 >> ((NU32)4u))));
  return result_36;}
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
static inline NC8 charLit_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_10){
  NC8 result_37;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_10.x_0 & ((NU32)15u)))) == 7))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_37 = ((NC8)((NU32)(n_10.x_0 >> ((NU32)4u))));
  return result_37;}
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
static inline NU32 uintId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_13){
  NU32 result_40;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_13.x_0 & ((NU32)15u)))) == 9))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_40 = ((NU32)((NU32)(n_13.x_0 >> ((NU32)4u))));
  return result_40;}
static inline NU32 floatId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_14){
  NU32 result_41;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_14.x_0 & ((NU32)15u)))) == 10))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_41 = ((NU32)((NU32)(n_14.x_0 >> ((NU32)4u))));
  return result_41;}
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
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16){
  NU32 result_43;
  if (((NifKind_0_nif81dubp1)((NU32)(n_16.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_88 = tagId_0_nifh7u8pu1(n_16);
    result_43 = X60Qx_88;}
  else {
    result_43 = ErrT_0_nifh7u8pu1;}
  return result_43;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline PackedToken_0_nifh7u8pu1 parLeToken_0_nifh7u8pu1(NU32 t_0, NU32 info_9){
  PackedToken_0_nifh7u8pu1 result_22;
  PackedToken_0_nifh7u8pu1 X60Qx_48 = toToken_0_Iz0lv7d1_nifh7u8pu1(11, t_0, info_9);
  result_22 = X60Qx_48;
  return result_22;}
static inline PackedToken_0_nifh7u8pu1 parRiToken_0_nifh7u8pu1(NU32 info_2){
  PackedToken_0_nifh7u8pu1 result_3;
  result_3 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)12) | ((NU32)(((NU32)0u) << ((NU32)4u))))), .info_0 = info_2}
  ;
  return result_3;}
static inline PackedToken_0_nifh7u8pu1 dotToken_0_nifh7u8pu1(NU32 info_7){
  PackedToken_0_nifh7u8pu1 result_20;
  PackedToken_0_nifh7u8pu1 X60Qx_46 = toToken_0_Ie5j2hb_nifh7u8pu1(2, ((NU32)0u), info_7);
  result_20 = X60Qx_46;
  return result_20;}
static inline PackedToken_0_nifh7u8pu1 strToken_0_nifh7u8pu1(NU32 id_5, NU32 info_15){
  PackedToken_0_nifh7u8pu1 result_29;
  PackedToken_0_nifh7u8pu1 X60Qx_55 = toToken_0_Ika21pk_nifh7u8pu1(6, id_5, info_15);
  result_29 = X60Qx_55;
  return result_29;}
static inline PackedToken_0_nifh7u8pu1 intToken_0_nifh7u8pu1(NU32 id_2, NU32 info_11){
  PackedToken_0_nifh7u8pu1 result_25;
  PackedToken_0_nifh7u8pu1 X60Qx_51 = toToken_0_Is7quwk1_nifh7u8pu1(8, id_2, info_11);
  result_25 = X60Qx_51;
  return result_25;}
static inline PackedToken_0_nifh7u8pu1 uintToken_0_nifh7u8pu1(NU32 id_3, NU32 info_12){
  PackedToken_0_nifh7u8pu1 result_26;
  PackedToken_0_nifh7u8pu1 X60Qx_52 = toToken_0_Ikm2gt2_nifh7u8pu1(9, id_3, info_12);
  result_26 = X60Qx_52;
  return result_26;}
static inline PackedToken_0_nifh7u8pu1 identToken_0_nifh7u8pu1(NU32 s_0, NU32 info_5){
  PackedToken_0_nifh7u8pu1 result_18;
  PackedToken_0_nifh7u8pu1 X60Qx_44 = toToken_0_Ika21pk_nifh7u8pu1(3, s_0, info_5);
  result_18 = X60Qx_44;
  return result_18;}
static inline NU32 getOrIncl_1_Ijmj1s_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_26, NF64 v_8){
  NU32 result_48;
  NU64 X60Qx_1406;
  copyMem_0_sysvq0asl((&X60Qx_1406), (&v_8), sizeof(NU64));
  NU32 X60Qx_1407 = getOrIncl_0_Ivbdpqo_explnj22x1(t_26, X60Qx_1406);
  result_48 = X60Qx_1407;
  return result_48;}
static inline PackedToken_0_nifh7u8pu1 floatToken_0_nifh7u8pu1(NU32 id_4, NU32 info_13){
  PackedToken_0_nifh7u8pu1 result_27;
  PackedToken_0_nifh7u8pu1 X60Qx_53 = toToken_0_Ifgbqjw1_nifh7u8pu1(10, id_4, info_13);
  result_27 = X60Qx_53;
  return result_27;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iz0lv7d1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_12, NU32 id_16, NU32 info_31){
  PackedToken_0_nifh7u8pu1 result_65;
  result_65 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_12) | ((NU32)(((NU32)id_16) << ((NU32)4u))))), .info_0 = info_31}
  ;
  return result_65;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ie5j2hb_nifh7u8pu1(NifKind_0_nif81dubp1 kind_11, NU32 id_15, NU32 info_30){
  PackedToken_0_nifh7u8pu1 result_64;
  result_64 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_11) | ((NU32)(((NU32)id_15) << ((NU32)4u))))), .info_0 = info_30}
  ;
  return result_64;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ika21pk_nifh7u8pu1(NifKind_0_nif81dubp1 kind_9, NU32 id_13, NU32 info_28){
  PackedToken_0_nifh7u8pu1 result_62;
  result_62 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_9) | ((NU32)(((NU32)id_13) << ((NU32)4u))))), .info_0 = info_28}
  ;
  return result_62;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Is7quwk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_13, NU32 id_17, NU32 info_32){
  PackedToken_0_nifh7u8pu1 result_66;
  result_66 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_13) | ((NU32)(((NU32)id_17) << ((NU32)4u))))), .info_0 = info_32}
  ;
  return result_66;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ikm2gt2_nifh7u8pu1(NifKind_0_nif81dubp1 kind_14, NU32 id_18, NU32 info_33){
  PackedToken_0_nifh7u8pu1 result_67;
  result_67 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_14) | ((NU32)(((NU32)id_18) << ((NU32)4u))))), .info_0 = info_33}
  ;
  return result_67;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ifgbqjw1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_15, NU32 id_19, NU32 info_34){
  PackedToken_0_nifh7u8pu1 result_68;
  result_68 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_15) | ((NU32)(((NU32)id_19) << ((NU32)4u))))), .info_0 = info_34}
  ;
  return result_68;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
