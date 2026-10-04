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
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct GlobalUse_0_jitqj5lia1{
  NB8 unsafe_0;
  string_0_sysvq0asl what_0;}
GlobalUse_0_jitqj5lia1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_Ic9cn7e1_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax* data_0;}
seq_0_Ic9cn7e1_intzsnzax;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_Ibw7a2q1_intzsnzax{
  seq_0_Ic9cn7e1_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ibw7a2q1_intzsnzax;
typedef struct HSlice_0_Inzqy8d_aow7lb5cq1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_aow7lb5cq1;
typedef struct seq_0_Izrqpny1_jitqj5lia1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1* data_0;}
seq_0_Izrqpny1_jitqj5lia1;
typedef struct Table_0_Ifnkmam_jitqj5lia1{
  seq_0_Izrqpny1_jitqj5lia1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ifnkmam_jitqj5lia1;
typedef struct openArray_0_Ig73pnk_aow7lb5cq1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_aow7lb5cq1;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax{
  NU32 fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Abool_intzsnzax;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1{
  NU32 fld_0;
  GlobalUse_0_jitqj5lia1 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1;
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
typedef struct Local_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 typ_0;
  Cursor_0_nifb6mq6y1 val_0;}
Local_0_decqocs071;
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
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef NU8 SkipMode_0_decqocs071;

#define SkipExclBody_0_decqocs071 ((NU8)0)
#define SkipInclBody_0_decqocs071 ((NU8)1)
#define SkipFinalParRi_0_decqocs071 ((NU8)2)
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
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
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
GlobalUse_0_jitqj5lia1 routineGlobalUse_1_jitqj5lia1(NU32 sym_1, NI32 depth_2);
void collectGlobals_1_jitqj5lia1(NU32 sym_3, NI32 depth_5, seq_0_Ixdx2fh1_aow7lb5cq1* acc_3, Table_0_Ibw7a2q1_intzsnzax* seen_2);
Table_0_Ifnkmam_jitqj5lia1 initTable_0_Iqi8tx7_jitqj5lia1(void);
static inline NB8 hasKey_0_Icj0dc5_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 t_12, NU32 k_7);
GlobalUse_0_jitqj5lia1 getOrDefault_1_Ih7x0bp_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 t_14, NU32 k_9, GlobalUse_0_jitqj5lia1 fallback_3);
void putQ_0_Imryept1_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1* t_18, NU32 k_13, GlobalUse_0_jitqj5lia1 v_4);
static inline seq_0_Izrqpny1_jitqj5lia1 newSeqUninit_0_Ib8dmg91_jitqj5lia1(NI32 size_6);
static inline NB8 contains_0_Izy14iy_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 t_21, NU32 k_16);
NI32 rawGet_0_Iohu0oo_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 t_22, NU32 k_17, NU32 kh_3);
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1* getQ_7_Iz902rn_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1 s_18, NI32 i_11);
void rawPut_0_Icjctv1_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1* t_25, NU32 k_19, GlobalUse_0_jitqj5lia1 v_7, NU32 h_7);
static inline NI32 memSizeInBytes_0_Ilymosl1_jitqj5lia1(NI32 size_13);
static inline NI32 len_3_Iyo0r2i1_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1 s_28);
void fillHashPart_0_Ibyako91_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1* t_28);
static inline void add_0_I7i8eld1_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1* s_33, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1 elem_7);
static inline NI32 capInBytes_0_Ixqw5o81_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1 s_36);
NB8 resize_0_Iq9n92b1_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1* dest_5, NI32 addedElements_5);
void eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(GlobalUse_0_jitqj5lia1 dest_0);
void eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(GlobalUse_0_jitqj5lia1* dest_0);
GlobalUse_0_jitqj5lia1 eQdupQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(GlobalUse_0_jitqj5lia1 src_0);
void eQdestroyQ_SX54able0X49bw7a2q1_0_jitqj5lia1(Table_0_Ibw7a2q1_intzsnzax dest_0);
void eQdestroyQ_SX54able0X49fnkmam_0_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 dest_0);
void eQwasmovedQ_SX54able0X49fnkmam_0_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1* dest_0);
void eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1 dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13);
static inline string_0_sysvq0asl* getQ_0_I93d71y_der823rwr1(BiTable_0_Icvz6lt_buiyylk1h1 t_5, NU32 litId_1);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_dbgj4vyzj1(NI32 a_13, NI32 b_2);
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355);
extern LoadResult_0_prorcx25w1 tryLoadSymSafe_0_modzy18mg1(NU32 s_0);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern LongString_0_sysvq0asl const strlit_0_I1281801651151844468_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I13046452236886743244_emi78vuj01;
extern Local_0_decqocs071 asLocal_0_decqocs071(Cursor_0_nifb6mq6y1 c_5, SkipMode_0_decqocs071 mode_1);
extern string_0_sysvq0asl importcName_0_hlc70y78v(Cursor_0_nifb6mq6y1 pragmasCur_4);
extern void eQdestroyQ_SX4cocal0decqocs071_0_decqocs071(Local_0_decqocs071* dest_0);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
extern LongString_0_sysvq0asl const strlit_0_I14457488926480995039_der823rwr1;
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
extern LongString_0_sysvq0asl const strlit_0_I1707222714195181991_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I9217337746930322866_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I12061648672903694946_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I8390060478375454995_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I8954722698363393223_der823rwr1;
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern NB8 getOrDefault_1_I3qjwxq1_intzsnzax(Table_0_Ibw7a2q1_intzsnzax t_60, NU32 k_54, NB8 fallback_13);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
static inline NimonySym_0_nimry5ra91 symKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_11);
static inline NB8 isRoutine_0_decqocs071(NimonySym_0_nimry5ra91 t_0);
extern LongString_0_sysvq0asl const strlit_0_I6517805684605582485_der823rwr1;
extern Routine_0_decqocs071 asRoutine_0_decqocs071(Cursor_0_nifb6mq6y1 c_8, SkipMode_0_decqocs071 mode_3);
extern void eQdestroyQ_SX52outine0decqocs071_0_decqocs071(Routine_0_decqocs071* dest_0);
extern void putQ_0_Iievosd1_intzsnzax(Table_0_Ibw7a2q1_intzsnzax* t_64, NU32 k_58, NB8 v_37);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_41);
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_28);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
extern Table_0_Ibw7a2q1_intzsnzax initTable_0_I6qaiy6_intzsnzax(void);
static inline seq_0_Ikxuplm1_der823rwr1 newSeqUninit_0_Iie69x21_der823rwr1(NI32 size_10);
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
static inline NI32 high_3_Iyuup9h1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_28);
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_29, NU32 i_17);
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2);
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline NI32 len_3_Iiefpcc1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_30);
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0);
extern void resize_0_tabcr240b1(seq_0_Ikxuplm1_der823rwr1* t_0);
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7);
extern void eQdestroy_1_I5skmro_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_53);
extern seq_0_Ikxuplm1_der823rwr1 newSeq_0_Iv3lu2h1_der823rwr1(NI32 size_17);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_Iv5j0db_intzsnzax(seq_0_Ic9cn7e1_intzsnzax s_518);
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_decqocs071(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_modzy18mg1(void);
extern void X60Qini_0_hlc70y78v(void);
extern void X60Qini_0_tabcr240b1(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14);
static inline NB8 rawTagIsNimonySym_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_5);
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NI32 memSizeInBytes_0_Ilp7p16_der823rwr1(NI32 size_15);
static inline NU32 hash_2_has9tn57v(NU32 u_0);
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16);
extern NU32 const ErrT_0_nifh7u8pu1;
LongString_0_sysvq0asl const strlit_0_I3485566669610392440_jitqj5lia1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "proccall"}
;
LongString_0_sysvq0asl const strlit_0_I299064572124707266_jitqj5lia1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "call depth > "}
;
LongString_0_sysvq0asl const strlit_0_I10145095296556069584_jitqj5lia1 = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 the analysis stopped looking"}
;
LongString_0_sysvq0asl const strlit_0_I121364913559080128_jitqj5lia1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " (via "}
;
LongString_0_sysvq0asl const strlit_0_I17997871512989884151_jitqj5lia1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "depth > "}
;
LongString_0_sysvq0asl const strlit_0_I12210089496471385066_jitqj5lia1 = {
  .fullLen_0 = 48, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "reads or writes the mutable module-level global "}
;
LongString_0_sysvq0asl const strlit_0_I6440375529625813319_jitqj5lia1 = {
  .fullLen_0 = 67, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 the JIT\'s shared library gets its OWN copy of it, so a native "}
;
LongString_0_sysvq0asl const strlit_0_I2146333674375736140_jitqj5lia1 = {
  .fullLen_0 = 65, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "call would answer from storage the interpreter never wrote (same "}
;
LongString_0_sysvq0asl const strlit_0_I12417213472165961137_jitqj5lia1 = {
  .fullLen_0 = 53, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "two-storages reason importcglob.nim halts on a write)"}
;
Table_0_Ifnkmam_jitqj5lia1 useCache_0_jitqj5lia1;
Table_0_Ibw7a2q1_intzsnzax inFlight_0_jitqj5lia1;
NB8 X60QiniGuard_0_jitqj5lia1;
string_0_sysvq0asl nodeTag_0_jitqj5lia1(Cursor_0_nifb6mq6y1 n_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  nimStrDestroy(result_0);
  NU32 X60Qx_9 = tagId_0_nifb6mq6y1(n_0);
  string_0_sysvq0asl* X60Qx_10 = getQ_0_I93d71y_der823rwr1(pool_0_nifh7u8pu1.tags_0, X60Qx_9);
  string_0_sysvq0asl X60Qx_11 = nimStrDup((*X60Qx_10));
  result_0 = X60Qx_11;
  return result_0;}
string_0_sysvq0asl baseOf_0_jitqj5lia1(NU32 s_0){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  string_0_sysvq0asl* X60Qx_12 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_0);
  string_0_sysvq0asl full_0 = nimStrDup((*X60Qx_12));
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_13;
      NI32 X60Qx_14 = len_4_sysvq0asl(full_0);
      if (i_0 < X60Qx_14){
        NC8 X60Qx_15 = getQ_9_sysvq0asl(full_0, i_0);
        X60Qx_13 = (!(X60Qx_15 == (NC8)'.'));}
      else {
        X60Qx_13 = NIM_FALSE;}
      if (X60Qx_13){
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(result_1);
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_16 = __ltQ_1_Ij9jwi_dbgj4vyzj1(0, i_0);
  string_0_sysvq0asl X60Qx_17 = getQ_14_sysvq0asl(full_0, X60Qx_16);
  result_1 = X60Qx_17;
  nimStrDestroy(full_0);
  return result_1;
  nimStrDestroy(full_0);
  return result_1;}
NB8 isTopLevelSym_0_jitqj5lia1(NU32 s_1){
  NB8 result_2;
  string_0_sysvq0asl* X60Qx_18 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_1);
  string_0_sysvq0asl full_1 = nimStrDup((*X60Qx_18));
  NI32 dots_0 = 0;
  NI32 i_1 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_19 = len_4_sysvq0asl(full_1);
      if (i_1 < X60Qx_19){
        NC8 X60Qx_20 = getQ_9_sysvq0asl(full_1, i_1);
        if (X60Qx_20 == (NC8)'.'){
          inc_1_I6wjjge_aow2h993l1((&dots_0));}
        inc_1_I6wjjge_aow2h993l1((&i_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_2 = (2 <= dots_0);
  nimStrDestroy(full_1);
  return result_2;
  nimStrDestroy(full_1);
  return result_2;}
GlobalUse_0_jitqj5lia1 classifyGlobal_0_jitqj5lia1(NU32 s_2){
  GlobalUse_0_jitqj5lia1 result_3;
  eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&result_3));
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(result_3);
  result_3 = (GlobalUse_0_jitqj5lia1){
    .unsafe_0 = NIM_FALSE, .what_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}}
  ;
  NB8 X60Qx_21 = isTopLevelSym_0_jitqj5lia1(s_2);
  if ((!X60Qx_21)){
    return result_3;}
  LoadResult_0_prorcx25w1 res_0 = tryLoadSymSafe_0_modzy18mg1(s_2);
  NB8 X60Qx_22;
  if ((!(res_0.status_0 == 3))){
    X60Qx_22 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_23 = kind_0_nifb6mq6y1(res_0.decl_0);
    X60Qx_22 = (!(X60Qx_23 == 11));}
  if (X60Qx_22){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    return result_3;}
  string_0_sysvq0asl t_2 = nodeTag_0_jitqj5lia1(res_0.decl_0);
  NB8 X60Qx_24;
  NB8 X60Qx_25 = eqQ_20_sysvq0asl(t_2, (string_0_sysvq0asl){
    .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_emi78vuj01)}
  );
  if ((!X60Qx_25)){
    NB8 X60Qx_26 = eqQ_20_sysvq0asl(t_2, (string_0_sysvq0asl){
      .bytes_0 = 1635153150u, .more_0 = (&strlit_0_I13046452236886743244_emi78vuj01)}
    );
    X60Qx_24 = (!X60Qx_26);}
  else {
    X60Qx_24 = NIM_FALSE;}
  if (X60Qx_24){
    nimStrDestroy(t_2);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    return result_3;}
  Local_0_decqocs071 loc_0 = asLocal_0_decqocs071(res_0.decl_0, 1);
  string_0_sysvq0asl X60Qtmp_0 = importcName_0_hlc70y78v(loc_0.pragmas_0);
  NI32 X60Qx_27 = len_4_sysvq0asl(X60Qtmp_0);
  if (0 < X60Qx_27){
    nimStrDestroy(X60Qtmp_0);
    eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_0));
    nimStrDestroy(t_2);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    return result_3;}
  string_0_sysvq0asl X60Qdesugar_0 = baseOf_0_jitqj5lia1(s_2);
  NI32 X60Qx_28 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 24577u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_29 = len_4_sysvq0asl(X60Qdesugar_0);
  NI32 X60Qx_30 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 24577u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_28 + X60Qx_29)) + X60Qx_30)));
  add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
    .bytes_0 = 24577u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_1), X60Qdesugar_0);
  add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
    .bytes_0 = 24577u, .more_0 = NIM_NIL}
  );
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(result_3);
  string_0_sysvq0asl X60Qtmp_1 = X60Qdesugar_1;
  nimStrWasMoved((&X60Qdesugar_1));
  result_3 = (GlobalUse_0_jitqj5lia1){
    .unsafe_0 = NIM_TRUE, .what_0 = X60Qtmp_1}
  ;
  nimStrDestroy(X60Qdesugar_1);
  nimStrDestroy(X60Qdesugar_0);
  nimStrDestroy(X60Qtmp_0);
  eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_0));
  nimStrDestroy(t_2);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_3;
  nimStrDestroy(X60Qdesugar_1);
  nimStrDestroy(X60Qdesugar_0);
  nimStrDestroy(X60Qtmp_0);
  eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_0));
  nimStrDestroy(t_2);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_3;}
void walkTree_0_jitqj5lia1(Cursor_0_nifb6mq6y1 root_0, NI32 depth_1, GlobalUse_0_jitqj5lia1* acc_0, NB8* tainted_0){
  if ((*acc_0).unsafe_0){
    return;}
  Cursor_0_nifb6mq6y1 c_0 = eQdup_0_nifb6mq6y1(root_0);
  NifKind_0_nif81dubp1 X60Qx_31 = kind_0_nifb6mq6y1(c_0);
  if (X60Qx_31 == 4){
    NU32 X60Qx_32 = symId_0_nifb6mq6y1(c_0);
    GlobalUse_0_jitqj5lia1 g_0 = classifyGlobal_0_jitqj5lia1(X60Qx_32);
    if (g_0.unsafe_0){
      eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((*acc_0));
      (*acc_0) = g_0;
      eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&g_0));}
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(g_0);
    eQdestroy_0_nifb6mq6y1((&c_0));
    return;
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(g_0);}
  NifKind_0_nif81dubp1 X60Qx_33 = kind_0_nifb6mq6y1(c_0);
  if ((!(X60Qx_33 == 11))){
    eQdestroy_0_nifb6mq6y1((&c_0));
    return;}
  string_0_sysvq0asl tag_0 = nodeTag_0_jitqj5lia1(c_0);
  NB8 X60Qx_34;
  NB8 X60Qx_35 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1953457155u, .more_0 = NIM_NIL}
  );
  if (X60Qx_35){
    X60Qx_34 = NIM_TRUE;}
  else {
    NB8 X60Qx_36 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1868850430u, .more_0 = (&strlit_0_I14457488926480995039_der823rwr1)}
    );
    X60Qx_34 = X60Qx_36;}
  if (X60Qx_34){
    Cursor_0_nifb6mq6y1 f_0 = c_0;
    eQwasMoved_0_nifb6mq6y1((&c_0));
    inc_0_nifb6mq6y1((&f_0));
    walkTree_0_jitqj5lia1(f_0, depth_1, acc_0, tainted_0);
    skip_0_nifb6mq6y1((&f_0));
    skip_0_nifb6mq6y1((&f_0));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_37 = kind_0_nifb6mq6y1(f_0);
        if ((!(X60Qx_37 == 12))){
          walkTree_0_jitqj5lia1(f_0, depth_1, acc_0, tainted_0);
          skip_0_nifb6mq6y1((&f_0));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    eQdestroy_0_nifb6mq6y1((&f_0));
    nimStrDestroy(tag_0);
    eQdestroy_0_nifb6mq6y1((&c_0));
    return;
    eQdestroy_0_nifb6mq6y1((&f_0));}
  NB8 X60Qx_38;
  NB8 X60Qx_39;
  NB8 X60Qx_40;
  NB8 X60Qx_41;
  NB8 X60Qx_42;
  NB8 X60Qx_43;
  NB8 X60Qx_44 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_der823rwr1)}
  );
  if (X60Qx_44){
    X60Qx_43 = NIM_TRUE;}
  else {
    NB8 X60Qx_45 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1684890371u, .more_0 = NIM_NIL}
    );
    X60Qx_43 = X60Qx_45;}
  if (X60Qx_43){
    X60Qx_42 = NIM_TRUE;}
  else {
    NB8 X60Qx_46 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I9217337746930322866_der823rwr1)}
    );
    X60Qx_42 = X60Qx_46;}
  if (X60Qx_42){
    X60Qx_41 = NIM_TRUE;}
  else {
    NB8 X60Qx_47 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_der823rwr1)}
    );
    X60Qx_41 = X60Qx_47;}
  if (X60Qx_41){
    X60Qx_40 = NIM_TRUE;}
  else {
    NB8 X60Qx_48 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1718512126u, .more_0 = (&strlit_0_I8390060478375454995_der823rwr1)}
    );
    X60Qx_40 = X60Qx_48;}
  if (X60Qx_40){
    X60Qx_39 = NIM_TRUE;}
  else {
    NB8 X60Qx_49 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1701998846u, .more_0 = (&strlit_0_I8954722698363393223_der823rwr1)}
    );
    X60Qx_39 = X60Qx_49;}
  if (X60Qx_39){
    X60Qx_38 = NIM_TRUE;}
  else {
    NB8 X60Qx_50 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I3485566669610392440_jitqj5lia1)}
    );
    X60Qx_38 = X60Qx_50;}
  if (X60Qx_38){
    Cursor_0_nifb6mq6y1 f_1 = c_0;
    eQwasMoved_0_nifb6mq6y1((&c_0));
    inc_0_nifb6mq6y1((&f_1));
    NifKind_0_nif81dubp1 X60Qx_51 = kind_0_nifb6mq6y1(f_1);
    if (X60Qx_51 == 4){
      if (((NI32)8) < ((NI32)(depth_1 + 1))){
        string_0_sysvq0asl X60Qdesugar_2 = dollarQ_2_sysvq0asl(((NI32)8));
        NI32 X60Qx_52 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I299064572124707266_jitqj5lia1)}
        );
        NI32 X60Qx_53 = len_4_sysvq0asl(X60Qdesugar_2);
        NI32 X60Qx_54 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I10145095296556069584_jitqj5lia1)}
        );
        string_0_sysvq0asl X60Qdesugar_3 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_52 + X60Qx_53)) + X60Qx_54)));
        add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
          .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I299064572124707266_jitqj5lia1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_2);
        add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
          .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I10145095296556069584_jitqj5lia1)}
        );
        eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((*acc_0));
        string_0_sysvq0asl X60Qtmp_2 = X60Qdesugar_3;
        nimStrWasMoved((&X60Qdesugar_3));
        (*acc_0) = (GlobalUse_0_jitqj5lia1){
          .unsafe_0 = NIM_TRUE, .what_0 = X60Qtmp_2}
        ;
        nimStrDestroy(X60Qdesugar_3);
        nimStrDestroy(X60Qdesugar_2);
        eQdestroy_0_nifb6mq6y1((&f_1));
        nimStrDestroy(tag_0);
        eQdestroy_0_nifb6mq6y1((&c_0));
        return;
        nimStrDestroy(X60Qdesugar_3);
        nimStrDestroy(X60Qdesugar_2);}
      NU32 X60Qx_55 = symId_0_nifb6mq6y1(f_1);
      NB8 X60Qx_56 = getOrDefault_1_I3qjwxq1_intzsnzax(inFlight_0_jitqj5lia1, X60Qx_55, NIM_FALSE);
      if (X60Qx_56){
        (*tainted_0) = NIM_TRUE;}
      else {
        NU32 X60Qx_57 = symId_0_nifb6mq6y1(f_1);
        GlobalUse_0_jitqj5lia1 sub_0 = routineGlobalUse_1_jitqj5lia1(X60Qx_57, ((NI32)(depth_1 + 1)));
        if (sub_0.unsafe_0){
          NU32 X60Qx_58 = symId_0_nifb6mq6y1(f_1);
          string_0_sysvq0asl X60Qdesugar_4 = baseOf_0_jitqj5lia1(X60Qx_58);
          NI32 X60Qx_59 = len_4_sysvq0asl(sub_0.what_0);
          NI32 X60Qx_60 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1982341374u, .more_0 = (&strlit_0_I121364913559080128_jitqj5lia1)}
          );
          NI32 X60Qx_61 = len_4_sysvq0asl(X60Qdesugar_4);
          NI32 X60Qx_62 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 10497u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_5 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_59 + X60Qx_60)) + X60Qx_61)) + X60Qx_62)));
          add_2_sysvq0asl((&X60Qdesugar_5), sub_0.what_0);
          add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
            .bytes_0 = 1982341374u, .more_0 = (&strlit_0_I121364913559080128_jitqj5lia1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_4);
          add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
            .bytes_0 = 10497u, .more_0 = NIM_NIL}
          );
          eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((*acc_0));
          string_0_sysvq0asl X60Qtmp_3 = X60Qdesugar_5;
          nimStrWasMoved((&X60Qdesugar_5));
          (*acc_0) = (GlobalUse_0_jitqj5lia1){
            .unsafe_0 = NIM_TRUE, .what_0 = X60Qtmp_3}
          ;
          nimStrDestroy(X60Qdesugar_5);
          nimStrDestroy(X60Qdesugar_4);
          eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(sub_0);
          eQdestroy_0_nifb6mq6y1((&f_1));
          nimStrDestroy(tag_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return;
          nimStrDestroy(X60Qdesugar_5);
          nimStrDestroy(X60Qdesugar_4);}
        eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(sub_0);}}
    else {
      walkTree_0_jitqj5lia1(f_1, depth_1, acc_0, tainted_0);}
    skip_0_nifb6mq6y1((&f_1));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_63 = kind_0_nifb6mq6y1(f_1);
        if ((!(X60Qx_63 == 12))){
          walkTree_0_jitqj5lia1(f_1, depth_1, acc_0, tainted_0);
          skip_0_nifb6mq6y1((&f_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;
    eQdestroy_0_nifb6mq6y1((&f_1));
    nimStrDestroy(tag_0);
    eQdestroy_0_nifb6mq6y1((&c_0));
    return;
    eQdestroy_0_nifb6mq6y1((&f_1));}
  Cursor_0_nifb6mq6y1 f_2 = c_0;
  eQwasMoved_0_nifb6mq6y1((&c_0));
  inc_0_nifb6mq6y1((&f_2));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_64 = kind_0_nifb6mq6y1(f_2);
      if ((!(X60Qx_64 == 12))){
        walkTree_0_jitqj5lia1(f_2, depth_1, acc_0, tainted_0);
        if ((*acc_0).unsafe_0){
          eQdestroy_0_nifb6mq6y1((&f_2));
          nimStrDestroy(tag_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return;}
        skip_0_nifb6mq6y1((&f_2));}
      else {
        break;}}}
  whileStmtLabel_2: ;
  eQdestroy_0_nifb6mq6y1((&f_2));
  nimStrDestroy(tag_0);
  eQdestroy_0_nifb6mq6y1((&c_0));}
GlobalUse_0_jitqj5lia1 routineGlobalUse_1_jitqj5lia1(NU32 sym_1, NI32 depth_2){
  GlobalUse_0_jitqj5lia1 result_4;
  eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&result_4));
  NB8 X60Qx_65 = hasKey_0_Icj0dc5_jitqj5lia1(useCache_0_jitqj5lia1, sym_1);
  if (X60Qx_65){
    GlobalUse_0_jitqj5lia1 X60Qtmp_4 = (GlobalUse_0_jitqj5lia1){
      .unsafe_0 = NIM_FALSE, .what_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}}
    ;
    GlobalUse_0_jitqj5lia1 X60Qx_66 = getOrDefault_1_Ih7x0bp_jitqj5lia1(useCache_0_jitqj5lia1, sym_1, X60Qtmp_4);
    result_4 = X60Qx_66;
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(X60Qtmp_4);
    return result_4;
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(X60Qtmp_4);}
  if (((NI32)8) < depth_2){
    string_0_sysvq0asl X60Qtmp_5 = dollarQ_2_sysvq0asl(((NI32)8));
    string_0_sysvq0asl X60Qx_8 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1885693182u, .more_0 = (&strlit_0_I17997871512989884151_jitqj5lia1)}
    , X60Qtmp_5);
    result_4 = (GlobalUse_0_jitqj5lia1){
      .unsafe_0 = NIM_TRUE, .what_0 = X60Qx_8}
    ;
    nimStrDestroy(X60Qtmp_5);
    return result_4;
    nimStrDestroy(X60Qtmp_5);}
  LoadResult_0_prorcx25w1 res_1 = tryLoadSymSafe_0_modzy18mg1(sym_1);
  NB8 X60Qx_67;
  NB8 X60Qx_68;
  if ((!(res_1.status_0 == 3))){
    X60Qx_68 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_69 = kind_0_nifb6mq6y1(res_1.decl_0);
    X60Qx_68 = (!(X60Qx_69 == 11));}
  if (X60Qx_68){
    X60Qx_67 = NIM_TRUE;}
  else {
    NimonySym_0_nimry5ra91 X60Qx_70 = symKind_0_nim30udrv(res_1.decl_0);
    NB8 X60Qx_71 = isRoutine_0_decqocs071(X60Qx_70);
    X60Qx_67 = (!X60Qx_71);}
  if (X60Qx_67){
    result_4 = (GlobalUse_0_jitqj5lia1){
      .unsafe_0 = NIM_FALSE, .what_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}}
    ;
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
    return result_4;}
  string_0_sysvq0asl X60Qtmp_6 = nodeTag_0_jitqj5lia1(res_1.decl_0);
  NB8 X60Qx_72 = eqQ_20_sysvq0asl(X60Qtmp_6, (string_0_sysvq0asl){
    .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_der823rwr1)}
  );
  if (X60Qx_72){
    result_4 = (GlobalUse_0_jitqj5lia1){
      .unsafe_0 = NIM_FALSE, .what_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}}
    ;
    nimStrDestroy(X60Qtmp_6);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
    return result_4;}
  Routine_0_decqocs071 r_0 = asRoutine_0_decqocs071(res_1.decl_0, 1);
  NifKind_0_nif81dubp1 X60Qx_73 = kind_0_nifb6mq6y1(r_0.body_0);
  if ((!(X60Qx_73 == 11))){
    result_4 = (GlobalUse_0_jitqj5lia1){
      .unsafe_0 = NIM_FALSE, .what_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}}
    ;
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_0));
    nimStrDestroy(X60Qtmp_6);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
    return result_4;}
  GlobalUse_0_jitqj5lia1 acc_4 = (GlobalUse_0_jitqj5lia1){
    .unsafe_0 = NIM_FALSE, .what_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}}
  ;
  NB8 tainted_1 = NIM_FALSE;
  putQ_0_Iievosd1_intzsnzax((&inFlight_0_jitqj5lia1), sym_1, NIM_TRUE);
  walkTree_0_jitqj5lia1(r_0.body_0, depth_2, (&acc_4), (&tainted_1));
  putQ_0_Iievosd1_intzsnzax((&inFlight_0_jitqj5lia1), sym_1, NIM_FALSE);
  if ((!tainted_1)){
    GlobalUse_0_jitqj5lia1 X60Qx_74 = eQdupQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(acc_4);
    putQ_0_Imryept1_jitqj5lia1((&useCache_0_jitqj5lia1), sym_1, X60Qx_74);}
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(result_4);
  result_4 = acc_4;
  eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&acc_4));
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(acc_4);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_0));
  nimStrDestroy(X60Qtmp_6);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
  return result_4;
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(acc_4);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_0));
  nimStrDestroy(X60Qtmp_6);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
  return result_4;}
void walkAll_0_jitqj5lia1(Cursor_0_nifb6mq6y1 root_1, NI32 depth_4, seq_0_Ixdx2fh1_aow7lb5cq1* acc_2, Table_0_Ibw7a2q1_intzsnzax* seen_1){
  Cursor_0_nifb6mq6y1 c_1 = eQdup_0_nifb6mq6y1(root_1);
  NifKind_0_nif81dubp1 X60Qx_75 = kind_0_nifb6mq6y1(c_1);
  if (X60Qx_75 == 4){
    NU32 X60Qx_76 = symId_0_nifb6mq6y1(c_1);
    GlobalUse_0_jitqj5lia1 g_1 = classifyGlobal_0_jitqj5lia1(X60Qx_76);
    if (g_1.unsafe_0){
      NB8 dup_0 = NIM_FALSE;
      {
        openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_0 = toOpenArray_1_I6b60gk1_aow7lb5cq1((*acc_2));
        NI32 X60Qlf_1 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_77 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_0);
            if (X60Qlf_1 < X60Qx_77){
              {
                string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_0, X60Qlf_1);
                NB8 X60Qx_78 = eqQ_20_sysvq0asl((*X60Qii_2), g_1.what_0);
                if (X60Qx_78){
                  dup_0 = NIM_TRUE;
                  goto forStmtLabel_0;}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;
      if ((!dup_0)){
        string_0_sysvq0asl X60Qtmp_7 = g_1.what_0;
        nimStrWasMoved((&g_1.what_0));
        add_0_Ig6072n_aow7lb5cq1(acc_2, X60Qtmp_7);}}
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(g_1);
    eQdestroy_0_nifb6mq6y1((&c_1));
    return;
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(g_1);}
  NifKind_0_nif81dubp1 X60Qx_79 = kind_0_nifb6mq6y1(c_1);
  if ((!(X60Qx_79 == 11))){
    eQdestroy_0_nifb6mq6y1((&c_1));
    return;}
  string_0_sysvq0asl tag_1 = nodeTag_0_jitqj5lia1(c_1);
  NB8 X60Qx_80;
  NB8 X60Qx_81 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
    .bytes_0 = 1953457155u, .more_0 = NIM_NIL}
  );
  if (X60Qx_81){
    X60Qx_80 = NIM_TRUE;}
  else {
    NB8 X60Qx_82 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
      .bytes_0 = 1868850430u, .more_0 = (&strlit_0_I14457488926480995039_der823rwr1)}
    );
    X60Qx_80 = X60Qx_82;}
  if (X60Qx_80){
    Cursor_0_nifb6mq6y1 f_3 = c_1;
    eQwasMoved_0_nifb6mq6y1((&c_1));
    inc_0_nifb6mq6y1((&f_3));
    walkAll_0_jitqj5lia1(f_3, depth_4, acc_2, seen_1);
    skip_0_nifb6mq6y1((&f_3));
    skip_0_nifb6mq6y1((&f_3));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_83 = kind_0_nifb6mq6y1(f_3);
        if ((!(X60Qx_83 == 12))){
          walkAll_0_jitqj5lia1(f_3, depth_4, acc_2, seen_1);
          skip_0_nifb6mq6y1((&f_3));}
        else {
          break;}}}
    whileStmtLabel_3: ;
    eQdestroy_0_nifb6mq6y1((&f_3));
    nimStrDestroy(tag_1);
    eQdestroy_0_nifb6mq6y1((&c_1));
    return;
    eQdestroy_0_nifb6mq6y1((&f_3));}
  NB8 X60Qx_84;
  NB8 X60Qx_85;
  NB8 X60Qx_86;
  NB8 X60Qx_87;
  NB8 X60Qx_88;
  NB8 X60Qx_89;
  NB8 X60Qx_90 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
    .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_der823rwr1)}
  );
  if (X60Qx_90){
    X60Qx_89 = NIM_TRUE;}
  else {
    NB8 X60Qx_91 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
      .bytes_0 = 1684890371u, .more_0 = NIM_NIL}
    );
    X60Qx_89 = X60Qx_91;}
  if (X60Qx_89){
    X60Qx_88 = NIM_TRUE;}
  else {
    NB8 X60Qx_92 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
      .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I9217337746930322866_der823rwr1)}
    );
    X60Qx_88 = X60Qx_92;}
  if (X60Qx_88){
    X60Qx_87 = NIM_TRUE;}
  else {
    NB8 X60Qx_93 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
      .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_der823rwr1)}
    );
    X60Qx_87 = X60Qx_93;}
  if (X60Qx_87){
    X60Qx_86 = NIM_TRUE;}
  else {
    NB8 X60Qx_94 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
      .bytes_0 = 1718512126u, .more_0 = (&strlit_0_I8390060478375454995_der823rwr1)}
    );
    X60Qx_86 = X60Qx_94;}
  if (X60Qx_86){
    X60Qx_85 = NIM_TRUE;}
  else {
    NB8 X60Qx_95 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
      .bytes_0 = 1701998846u, .more_0 = (&strlit_0_I8954722698363393223_der823rwr1)}
    );
    X60Qx_85 = X60Qx_95;}
  if (X60Qx_85){
    X60Qx_84 = NIM_TRUE;}
  else {
    NB8 X60Qx_96 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I3485566669610392440_jitqj5lia1)}
    );
    X60Qx_84 = X60Qx_96;}
  if (X60Qx_84){
    Cursor_0_nifb6mq6y1 f_4 = c_1;
    eQwasMoved_0_nifb6mq6y1((&c_1));
    inc_0_nifb6mq6y1((&f_4));
    NifKind_0_nif81dubp1 X60Qx_97 = kind_0_nifb6mq6y1(f_4);
    if (X60Qx_97 == 4){
      NB8 X60Qx_98;
      if (((NI32)(depth_4 + 1)) <= ((NI32)8)){
        NU32 X60Qx_99 = symId_0_nifb6mq6y1(f_4);
        NB8 X60Qx_100 = getOrDefault_1_I3qjwxq1_intzsnzax((*seen_1), X60Qx_99, NIM_FALSE);
        X60Qx_98 = (!X60Qx_100);}
      else {
        X60Qx_98 = NIM_FALSE;}
      if (X60Qx_98){
        NU32 X60Qx_101 = symId_0_nifb6mq6y1(f_4);
        collectGlobals_1_jitqj5lia1(X60Qx_101, ((NI32)(depth_4 + 1)), acc_2, seen_1);}}
    else {
      walkAll_0_jitqj5lia1(f_4, depth_4, acc_2, seen_1);}
    skip_0_nifb6mq6y1((&f_4));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_102 = kind_0_nifb6mq6y1(f_4);
        if ((!(X60Qx_102 == 12))){
          walkAll_0_jitqj5lia1(f_4, depth_4, acc_2, seen_1);
          skip_0_nifb6mq6y1((&f_4));}
        else {
          break;}}}
    whileStmtLabel_4: ;
    eQdestroy_0_nifb6mq6y1((&f_4));
    nimStrDestroy(tag_1);
    eQdestroy_0_nifb6mq6y1((&c_1));
    return;
    eQdestroy_0_nifb6mq6y1((&f_4));}
  Cursor_0_nifb6mq6y1 f_5 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&f_5));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_103 = kind_0_nifb6mq6y1(f_5);
      if ((!(X60Qx_103 == 12))){
        walkAll_0_jitqj5lia1(f_5, depth_4, acc_2, seen_1);
        skip_0_nifb6mq6y1((&f_5));}
      else {
        break;}}}
  whileStmtLabel_5: ;
  eQdestroy_0_nifb6mq6y1((&f_5));
  nimStrDestroy(tag_1);
  eQdestroy_0_nifb6mq6y1((&c_1));}
void collectGlobals_1_jitqj5lia1(NU32 sym_3, NI32 depth_5, seq_0_Ixdx2fh1_aow7lb5cq1* acc_3, Table_0_Ibw7a2q1_intzsnzax* seen_2){
  NB8 X60Qx_104 = getOrDefault_1_I3qjwxq1_intzsnzax((*seen_2), sym_3, NIM_FALSE);
  if (X60Qx_104){
    return;}
  putQ_0_Iievosd1_intzsnzax(seen_2, sym_3, NIM_TRUE);
  if (((NI32)8) < depth_5){
    return;}
  LoadResult_0_prorcx25w1 res_2 = tryLoadSymSafe_0_modzy18mg1(sym_3);
  NB8 X60Qx_105;
  NB8 X60Qx_106;
  if ((!(res_2.status_0 == 3))){
    X60Qx_106 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_107 = kind_0_nifb6mq6y1(res_2.decl_0);
    X60Qx_106 = (!(X60Qx_107 == 11));}
  if (X60Qx_106){
    X60Qx_105 = NIM_TRUE;}
  else {
    NimonySym_0_nimry5ra91 X60Qx_108 = symKind_0_nim30udrv(res_2.decl_0);
    NB8 X60Qx_109 = isRoutine_0_decqocs071(X60Qx_108);
    X60Qx_105 = (!X60Qx_109);}
  if (X60Qx_105){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
    return;}
  string_0_sysvq0asl X60Qtmp_8 = nodeTag_0_jitqj5lia1(res_2.decl_0);
  NB8 X60Qx_110 = eqQ_20_sysvq0asl(X60Qtmp_8, (string_0_sysvq0asl){
    .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_der823rwr1)}
  );
  if (X60Qx_110){
    nimStrDestroy(X60Qtmp_8);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
    return;}
  Routine_0_decqocs071 r_1 = asRoutine_0_decqocs071(res_2.decl_0, 1);
  NifKind_0_nif81dubp1 X60Qx_111 = kind_0_nifb6mq6y1(r_1.body_0);
  if ((!(X60Qx_111 == 11))){
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
    nimStrDestroy(X60Qtmp_8);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
    return;}
  walkAll_0_jitqj5lia1(r_1.body_0, depth_5, acc_3, seen_2);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
  nimStrDestroy(X60Qtmp_8);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);}
seq_0_Ixdx2fh1_aow7lb5cq1 jitGlobalsTouched_0_jitqj5lia1(NU32 sym_4){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_5;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_5));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_5);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_112 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_5 = X60Qx_112;
  Table_0_Ibw7a2q1_intzsnzax seen_3 = initTable_0_I6qaiy6_intzsnzax();
  collectGlobals_1_jitqj5lia1(sym_4, 0, (&result_5), (&seen_3));
  eQdestroyQ_SX54able0X49bw7a2q1_0_jitqj5lia1(seen_3);
  return result_5;
  eQdestroyQ_SX54able0X49bw7a2q1_0_jitqj5lia1(seen_3);
  return result_5;}
string_0_sysvq0asl jitGlobalDeclineReason_0_jitqj5lia1(NU32 sym_5){
  string_0_sysvq0asl result_6;
  nimStrWasMoved((&result_6));
  GlobalUse_0_jitqj5lia1 g_2 = routineGlobalUse_1_jitqj5lia1(sym_5, 0);
  if ((!g_2.unsafe_0)){
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(g_2);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 X60Qx_113 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I12210089496471385066_jitqj5lia1)}
  );
  NI32 X60Qx_114 = len_4_sysvq0asl(g_2.what_0);
  NI32 X60Qx_115 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I6440375529625813319_jitqj5lia1)}
  );
  NI32 X60Qx_116 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I2146333674375736140_jitqj5lia1)}
  );
  NI32 X60Qx_117 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1870099710u, .more_0 = (&strlit_0_I12417213472165961137_jitqj5lia1)}
  );
  string_0_sysvq0asl X60Qdesugar_6 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_113 + X60Qx_114)) + X60Qx_115)) + X60Qx_116)) + X60Qx_117)));
  add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
    .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I12210089496471385066_jitqj5lia1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_6), g_2.what_0);
  add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
    .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I6440375529625813319_jitqj5lia1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
    .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I2146333674375736140_jitqj5lia1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
    .bytes_0 = 1870099710u, .more_0 = (&strlit_0_I12417213472165961137_jitqj5lia1)}
  );
  nimStrDestroy(result_6);
  result_6 = X60Qdesugar_6;
  nimStrWasMoved((&X60Qdesugar_6));
  nimStrDestroy(X60Qdesugar_6);
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(g_2);
  return result_6;
  nimStrDestroy(X60Qdesugar_6);
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(g_2);
  return result_6;}
void resetJitGlobalCache_0_jitqj5lia1(void){
  eQdestroyQ_SX54able0X49fnkmam_0_jitqj5lia1(useCache_0_jitqj5lia1);
  Table_0_Ifnkmam_jitqj5lia1 X60Qx_118 = initTable_0_Iqi8tx7_jitqj5lia1();
  useCache_0_jitqj5lia1 = X60Qx_118;
  eQdestroyQ_SX54able0X49bw7a2q1_0_jitqj5lia1(inFlight_0_jitqj5lia1);
  Table_0_Ibw7a2q1_intzsnzax X60Qx_119 = initTable_0_I6qaiy6_intzsnzax();
  inFlight_0_jitqj5lia1 = X60Qx_119;}
Table_0_Ifnkmam_jitqj5lia1 initTable_0_Iqi8tx7_jitqj5lia1(void){
  Table_0_Ifnkmam_jitqj5lia1 result_10;
  eQwasmovedQ_SX54able0X49fnkmam_0_jitqj5lia1((&result_10));
  eQdestroyQ_SX54able0X49fnkmam_0_jitqj5lia1(result_10);
  seq_0_Izrqpny1_jitqj5lia1 X60Qx_122 = newSeqUninit_0_Ib8dmg91_jitqj5lia1(0);
  seq_0_Ikxuplm1_der823rwr1 X60Qx_123 = newSeqUninit_0_Iie69x21_der823rwr1(0);
  result_10 = (Table_0_Ifnkmam_jitqj5lia1){
    .data_0 = X60Qx_122, .hashes_0 = X60Qx_123}
  ;
  return result_10;}
static inline NB8 hasKey_0_Icj0dc5_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 t_12, NU32 k_7){
  NB8 result_13;
  NB8 X60Qx_128 = contains_0_Izy14iy_jitqj5lia1(t_12, k_7);
  result_13 = X60Qx_128;
  return result_13;}
GlobalUse_0_jitqj5lia1 getOrDefault_1_Ih7x0bp_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 t_14, NU32 k_9, GlobalUse_0_jitqj5lia1 fallback_3){
  GlobalUse_0_jitqj5lia1 result_14;
  eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&result_14));
  NU32 X60Qx_129 = hash_0_nifh7u8pu1(k_9);
  NI32 idx_3 = rawGet_0_Iohu0oo_jitqj5lia1(t_14, k_9, X60Qx_129);
  GlobalUse_0_jitqj5lia1 X60Qx_1;
  eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&X60Qx_1));
  if (0 <= idx_3){
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(X60Qx_1);
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1* X60Qx_130 = getQ_7_Iz902rn_jitqj5lia1(t_14.data_0, idx_3);
    GlobalUse_0_jitqj5lia1 X60Qx_131 = eQdupQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((*X60Qx_130).fld_1);
    X60Qx_1 = X60Qx_131;}
  else {
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(X60Qx_1);
    GlobalUse_0_jitqj5lia1 X60Qx_132 = eQdupQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(fallback_3);
    X60Qx_1 = X60Qx_132;}
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(result_14);
  result_14 = X60Qx_1;
  eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&X60Qx_1));
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(X60Qx_1);
  return result_14;
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(X60Qx_1);
  return result_14;}
void putQ_0_Imryept1_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1* t_18, NU32 k_13, GlobalUse_0_jitqj5lia1 v_4){
  NU32 h_2 = hash_0_nifh7u8pu1(k_13);
  NI32 idx_5 = rawGet_0_Iohu0oo_jitqj5lia1((*t_18), k_13, h_2);
  if (0 <= idx_5){
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1* X60Qx_134 = getQ_7_Iz902rn_jitqj5lia1((*t_18).data_0, idx_5);
    GlobalUse_0_jitqj5lia1* X60Qlhs_9 = (&(*X60Qx_134).fld_1);
    GlobalUse_0_jitqj5lia1 X60Qlhs_10 = v_4;
    eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&v_4));
    eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((*X60Qlhs_9));
    (*X60Qlhs_9) = X60Qlhs_10;}
  else {
    GlobalUse_0_jitqj5lia1 X60Qtmp_11 = v_4;
    eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&v_4));
    rawPut_0_Icjctv1_jitqj5lia1(t_18, k_13, X60Qtmp_11, h_2);}
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(v_4);}
static inline seq_0_Izrqpny1_jitqj5lia1 newSeqUninit_0_Ib8dmg91_jitqj5lia1(NI32 size_6){
  seq_0_Izrqpny1_jitqj5lia1 result_18;
  if (size_6 == 0){
    result_18 = (seq_0_Izrqpny1_jitqj5lia1){
      .len_0 = size_6, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Ilymosl1_jitqj5lia1(size_6);
    void* X60Qx_141 = alloc_1_sysvq0asl(memSize_1);
    result_18 = (seq_0_Izrqpny1_jitqj5lia1){
      .len_0 = size_6, .data_0 = ((X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1*)X60Qx_141)}
    ;
    if ((!(result_18.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_142 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_18.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_18;}
static inline NB8 contains_0_Izy14iy_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 t_21, NU32 k_16){
  NB8 result_23;
  NU32 X60Qx_160 = hash_0_nifh7u8pu1(k_16);
  NI32 X60Qx_161 = rawGet_0_Iohu0oo_jitqj5lia1(t_21, k_16, X60Qx_160);
  result_23 = (0 <= X60Qx_161);
  return result_23;}
NI32 rawGet_0_Iohu0oo_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 t_22, NU32 k_17, NU32 kh_3){
  NI32 result_24;
  NI32 X60Qx_162 = len_3_Iyo0r2i1_jitqj5lia1(t_22.data_0);
  if (X60Qx_162 <= ((NI32)4)){
    {
      NI32 X60Qlf_5 = 0;
      NI32 X60Qlf_6 = len_3_Iyo0r2i1_jitqj5lia1(t_22.data_0);
      NI32 X60Qlf_7 = X60Qlf_5;
      {
        while (X60Qlf_7 < X60Qlf_6){
          {
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1* X60Qx_163 = getQ_7_Iz902rn_jitqj5lia1(t_22.data_0, X60Qlf_7);
            NB8 X60Qx_164 = eqQ_0_nifh7u8pu1((*X60Qx_163).fld_0, k_17);
            if (X60Qx_164){
              return X60Qlf_7;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_165 = high_3_Iyuup9h1_der823rwr1(t_22.hashes_0);
    NU32 h_5 = ((NU32)(kh_3 & ((NU32)X60Qx_165)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_166 = getQ_8_Imt2zi01_der823rwr1(t_22.hashes_0, h_5);
        NB8 X60Qx_167 = isFilled_0_tabcr240b1((*X60Qx_166));
        if (X60Qx_167){
          HashEntry_0_tabcr240b1* X60Qx_168 = getQ_8_Imt2zi01_der823rwr1(t_22.hashes_0, h_5);
          HashEntry_0_tabcr240b1 d_1 = (*X60Qx_168);
          NB8 X60Qx_169;
          if (d_1.fullhash_0 == kh_3){
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1* X60Qx_170 = getQ_7_Iz902rn_jitqj5lia1(t_22.data_0, ((NI32)(d_1.position_0 - 1)));
            NB8 X60Qx_171 = eqQ_0_nifh7u8pu1((*X60Qx_170).fld_0, k_17);
            X60Qx_169 = X60Qx_171;}
          else {
            X60Qx_169 = NIM_FALSE;}
          if (X60Qx_169){
            result_24 = ((NI32)(d_1.position_0 - 1));
            return result_24;}
          NI32 X60Qx_172 = high_3_Iyuup9h1_der823rwr1(t_22.hashes_0);
          NU32 X60Qx_173 = nextTry_0_has9tn57v(h_5, X60Qx_172);
          h_5 = X60Qx_173;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_24 = -1;
  return result_24;}
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1* getQ_7_Iz902rn_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1 s_18, NI32 i_11){
  NB8 X60Qx_174;
  if (i_11 < s_18.len_0){
    X60Qx_174 = (0 <= i_11);}
  else {
    X60Qx_174 = NIM_FALSE;}
  if ((!X60Qx_174)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1* result_25;
  result_25 = (&s_18.data_0[i_11]);
  return result_25;}
void rawPut_0_Icjctv1_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1* t_25, NU32 k_19, GlobalUse_0_jitqj5lia1 v_7, NU32 h_7){
  NI32 X60Qx_185 = len_3_Iyo0r2i1_jitqj5lia1((*t_25).data_0);
  if (X60Qx_185 == ((NI32)4)){
    fillHashPart_0_Ibyako91_jitqj5lia1(t_25);}
  else {
    NI32 X60Qx_186 = len_3_Iiefpcc1_der823rwr1((*t_25).hashes_0);
    NI32 X60Qx_187 = len_3_Iyo0r2i1_jitqj5lia1((*t_25).data_0);
    NB8 X60Qx_188 = mustRehash_0_tabcr240b1(X60Qx_186, X60Qx_187);
    if (X60Qx_188){
      resize_0_tabcr240b1((&(*t_25).hashes_0));}}
  GlobalUse_0_jitqj5lia1 X60Qtmp_12 = v_7;
  eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1((&v_7));
  add_0_I7i8eld1_jitqj5lia1((&(*t_25).data_0), (X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1){
    .fld_0 = k_19, .fld_1 = X60Qtmp_12}
  );
  NI32 X60Qx_189 = high_3_Iyuup9h1_der823rwr1((*t_25).hashes_0);
  NU32 hi_1 = ((NU32)(h_7 & ((NU32)X60Qx_189)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_190 = getQ_8_Imt2zi01_der823rwr1((*t_25).hashes_0, hi_1);
      NB8 X60Qx_191 = isFilled_0_tabcr240b1((*X60Qx_190));
      if (X60Qx_191){
        NI32 X60Qx_192 = high_3_Iyuup9h1_der823rwr1((*t_25).hashes_0);
        NU32 X60Qx_193 = nextTry_0_has9tn57v(hi_1, X60Qx_192);
        hi_1 = X60Qx_193;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_194 = len_3_Iyo0r2i1_jitqj5lia1((*t_25).data_0);
  putQ_8_Ipchg2a_der823rwr1((&(*t_25).hashes_0), hi_1, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_7, .position_0 = X60Qx_194}
  );
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(v_7);}
static inline NI32 memSizeInBytes_0_Ilymosl1_jitqj5lia1(NI32 size_13){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_32;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_13, sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_32 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_32 = ((NI32)2147483647);}
  return result_32;}
static inline NI32 len_3_Iyo0r2i1_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1 s_28){
  NI32 result_38;
  result_38 = s_28.len_0;
  return result_38;}
void fillHashPart_0_Ibyako91_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1* t_28){
  seq_0_Ikxuplm1_der823rwr1* X60Qlhs_14 = (&(*t_28).hashes_0);
  eQdestroy_1_I5skmro_der823rwr1((*X60Qlhs_14));
  seq_0_Ikxuplm1_der823rwr1 X60Qx_208 = newSeq_0_Iv3lu2h1_der823rwr1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_14) = X60Qx_208;
  {
    NI32 X60Qlf_11 = 0;
    NI32 X60Qlf_12 = len_3_Iyo0r2i1_jitqj5lia1((*t_28).data_0);
    NI32 X60Qlf_13 = X60Qlf_11;
    {
      while (X60Qlf_13 < X60Qlf_12){
        {
          X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1* X60Qx_209 = getQ_7_Iz902rn_jitqj5lia1((*t_28).data_0, X60Qlf_13);
          NU32 X60Qii_2 = hash_0_nifh7u8pu1((*X60Qx_209).fld_0);
          NI32 X60Qx_210 = high_3_Iyuup9h1_der823rwr1((*t_28).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_210)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_211 = getQ_8_Imt2zi01_der823rwr1((*t_28).hashes_0, X60Qii_3);
            NB8 X60Qx_212 = isFilled_0_tabcr240b1((*X60Qx_211));
            if (X60Qx_212){
              NI32 X60Qx_213 = high_3_Iyuup9h1_der823rwr1((*t_28).hashes_0);
              NU32 X60Qx_214 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_213);
              X60Qii_3 = X60Qx_214;}
            else {
              break;}}
          putQ_8_Ipchg2a_der823rwr1((&(*t_28).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_13 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_13));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_I7i8eld1_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1* s_33, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1 elem_7){
  NI32 L_2 = (*s_33).len_0;
  NI32 X60Qx_215 = capInBytes_0_Ixqw5o81_jitqj5lia1((*s_33));
  if (X60Qx_215 < ((NI32)(((NI32)(L_2 * sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1))) + sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1)))){
    NB8 X60Qx_216 = resize_0_Iq9n92b1_jitqj5lia1(s_33, 1);
    if ((!X60Qx_216)){
      eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(elem_7);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_33).len_0));
  (*s_33).data_0[L_2] = elem_7;}
static inline NI32 capInBytes_0_Ixqw5o81_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1 s_36){
  NI32 result_43;
  NI32 X60Qx_4;
  if ((!(s_36.data_0 == NIM_NIL))){
    NI32 X60Qx_221 = allocatedSize_0_sysvq0asl(((void*)((void*)s_36.data_0)));
    X60Qx_4 = X60Qx_221;}
  else {
    X60Qx_4 = 0;}
  result_43 = X60Qx_4;
  return result_43;}
NB8 resize_0_Iq9n92b1_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1* dest_5, NI32 addedElements_5){
  NB8 result_44;
  NI32 X60Qx_222 = capInBytes_0_Ixqw5o81_jitqj5lia1((*dest_5));
  NI32 oldCap_2 = ((NI32)(X60Qx_222 / sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_5);
  NI32 memSize_7 = memSizeInBytes_0_Ilymosl1_jitqj5lia1(newCap_2);
  void* X60Qx_223 = realloc_1_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_7);
  (*dest_5).data_0 = ((X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1*)X60Qx_223);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_7);
    result_44 = NIM_FALSE;}
  else {
    result_44 = NIM_TRUE;}
  return result_44;}
void eQdestroy_1_Ijdmc3k1_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1 s_53){
  if ((!(s_53.data_0 == NIM_NIL))){
    NI32 i_27 = 0;
    {
      while (i_27 < s_53.len_0){
        eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(s_53.data_0[i_27]);
        inc_1_I6wjjge_aow2h993l1((&i_27));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_53.data_0)));}}
static inline void eQwasMoved_1_Iucrzxm1_jitqj5lia1(seq_0_Izrqpny1_jitqj5lia1* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
void eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(GlobalUse_0_jitqj5lia1 dest_0){
  nimStrDestroy(dest_0.what_0);}
void eQwasmovedQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(GlobalUse_0_jitqj5lia1* dest_0){
  nimStrWasMoved((&(*dest_0).what_0));}
GlobalUse_0_jitqj5lia1 eQdupQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(GlobalUse_0_jitqj5lia1 src_0){
  GlobalUse_0_jitqj5lia1 dest_0;
  dest_0.unsafe_0 = src_0.unsafe_0;
  string_0_sysvq0asl X60Qx_259 = nimStrDup(src_0.what_0);
  dest_0.what_0 = X60Qx_259;
  return dest_0;}
void eQdestroyQ_SX54able0X49bw7a2q1_0_jitqj5lia1(Table_0_Ibw7a2q1_intzsnzax dest_0){
  eQdestroy_1_I5skmro_der823rwr1(dest_0.hashes_0);
  eQdestroy_1_Iv5j0db_intzsnzax(dest_0.data_0);}
void eQdestroyQ_SX54able0X49fnkmam_0_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1 dest_0){
  eQdestroy_1_I5skmro_der823rwr1(dest_0.hashes_0);
  eQdestroy_1_Ijdmc3k1_jitqj5lia1(dest_0.data_0);}
void eQwasmovedQ_SX54able0X49fnkmam_0_jitqj5lia1(Table_0_Ifnkmam_jitqj5lia1* dest_0){
  eQwasMoved_1_Iucrzxm1_jitqj5lia1((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_der823rwr1((&(*dest_0).hashes_0));}
void eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SX47lobalX55se0jitqj5lia1_jitqj5lia1 dest_0){
  eQdestroyQ_SX47lobalX55se0jitqj5lia1_0_jitqj5lia1(dest_0.fld_1);}
void X60Qini_0_jitqj5lia1(void){
  if (X60QiniGuard_0_jitqj5lia1){
    return;}
  X60QiniGuard_0_jitqj5lia1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_decqocs071();
  X60Qini_0_prorcx25w1();
  X60Qini_0_modzy18mg1();
  X60Qini_0_hlc70y78v();
  X60Qini_0_tabcr240b1();
  useCache_0_jitqj5lia1 = initTable_0_Iqi8tx7_jitqj5lia1();
  inFlight_0_jitqj5lia1 = initTable_0_I6qaiy6_intzsnzax();}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
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
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_dbgj4vyzj1(NI32 a_13, NI32 b_2){
  HSlice_0_Inzqy8d_aow7lb5cq1 result_36;
  result_36 = (HSlice_0_Inzqy8d_aow7lb5cq1){
    .a_0 = a_13, .b_0 = ((NI32)(b_2 - ((NI32)1)))}
  ;
  return result_36;}
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355){
  string_0_sysvq0asl result_224;
  nimStrWasMoved((&result_224));
  nimStrDestroy(result_224);
  string_0_sysvq0asl X60Qx_437 = substr_0_sysvq0asl(s_77, x_355.a_0, x_355.b_0);
  result_224 = X60Qx_437;
  return result_224;}
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1){
  Cursor_0_nifb6mq6y1 result_4;
  result_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = src_1.owner_0, .p_0 = src_1.p_0, .rem_0 = src_1.rem_0}
  ;
  if ((!(result_4.owner_0 == NIM_NIL))){
    inc_1_I6wjjge_aow2h993l1((&(*result_4.owner_0).rc_0));}
  return result_4;}
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
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_41){
  openArray_0_Ig73pnk_aow7lb5cq1 result_62;
  string_0_sysvq0asl* X60Qx_1439 = rawData_0_I65w5sr_aow7lb5cq1(s_41);
  result_62 = (openArray_0_Ig73pnk_aow7lb5cq1){
    .a_0 = X60Qx_1439, .len_0 = s_41.len_0}
  ;
  return result_62;}
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_28){
  NI32 result_90;
  result_90 = a_28.len_0;
  return result_90;}
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7){
  NB8 X60Qx_1473;
  if (0 <= idx_7){
    X60Qx_1473 = (idx_7 < x_13.len_0);}
  else {
    X60Qx_1473 = NIM_FALSE;}
  if ((!X60Qx_1473)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* result_91;
  result_91 = (&x_13.a_0[idx_7]);
  return result_91;}
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9){
  NI32 L_0 = (*s_35).len_0;
  NI32 X60Qx_1434 = capInBytes_0_Ih2sbn01_aow7lb5cq1((*s_35));
  if (X60Qx_1434 < ((NI32)(((NI32)(L_0 * sizeof(string_0_sysvq0asl))) + sizeof(string_0_sysvq0asl)))){
    NB8 X60Qx_1435 = resize_0_I4buliy_aow7lb5cq1(s_35, 1);
    if ((!X60Qx_1435)){
      nimStrDestroy(elem_9);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_35).len_0));
  (*s_35).data_0[L_0] = elem_9;}
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93){
  (*s_93).len_0 = 0;
  (*s_93).data_0 = NIM_NIL;}
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_59;
  if (size_8 == 0){
    result_59 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_I7me00i_aow7lb5cq1(size_8);
    void* X60Qx_1432 = alloc_1_sysvq0asl(memSize_1);
    result_59 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = ((string_0_sysvq0asl*)X60Qx_1432)}
    ;
    if ((!(result_59.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1433 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_59.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_59;}
static inline seq_0_Ikxuplm1_der823rwr1 newSeqUninit_0_Iie69x21_der823rwr1(NI32 size_10){
  seq_0_Ikxuplm1_der823rwr1 result_22;
  if (size_10 == 0){
    result_22 = (seq_0_Ikxuplm1_der823rwr1){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_Ilp7p16_der823rwr1(size_10);
    void* X60Qx_205 = alloc_1_sysvq0asl(memSize_3);
    result_22 = (seq_0_Ikxuplm1_der823rwr1){
      .len_0 = size_10, .data_0 = ((HashEntry_0_tabcr240b1*)X60Qx_205)}
    ;
    if ((!(result_22.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_206 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_22.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_22;}
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0){
  NU32 result_11;
  NU32 X60Qx_20 = hash_2_has9tn57v(x_0);
  result_11 = X60Qx_20;
  return result_11;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
static inline NI32 high_3_Iyuup9h1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_28){
  NI32 result_35;
  result_35 = ((NI32)(s_28.len_0 - 1));
  return result_35;}
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_29, NU32 i_17){
  if ((!(i_17 < ((NU32)s_29.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  HashEntry_0_tabcr240b1* result_36;
  result_36 = (&s_29.data_0[((NI32)i_17)]);
  return result_36;}
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2){
  NB8 result_1;
  result_1 = (0 < a_2.position_0);
  return result_1;}
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0){
  NU32 result_14;
  result_14 = ((NU32)(((NU32)(h_2 + 1u)) & ((NU32)maxHash_0)));
  return result_14;}
static inline NI32 len_3_Iiefpcc1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_30){
  NI32 result_37;
  result_37 = s_30.len_0;
  return result_37;}
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0){
  NB8 result_0;
  NB8 X60Qx_2;
  if (length_0 < ((NI32)(((NI32)(counter_0 / 2)) + counter_0))){
    X60Qx_2 = NIM_TRUE;}
  else {
    X60Qx_2 = (((NI32)(length_0 - counter_0)) < 4);}
  result_0 = X60Qx_2;
  return result_0;}
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7){
  if ((!(i_19 < ((NU32)(*s_33).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_33).data_0[((NI32)i_19)] = elem_7;}
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
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
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
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67){
  string_0_sysvq0asl* result_89;
  result_89 = s_67.data_0;
  return result_89;}
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65){
  NI32 result_85;
  NI32 X60Qx_11;
  if ((!(s_65.data_0 == NIM_NIL))){
    NI32 X60Qx_1467 = allocatedSize_0_sysvq0asl(((void*)((void*)s_65.data_0)));
    X60Qx_11 = X60Qx_1467;}
  else {
    X60Qx_11 = 0;}
  result_85 = X60Qx_11;
  return result_85;}
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_82;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_19, sizeof(string_0_sysvq0asl), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_82 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_82 = ((NI32)2147483647);}
  return result_82;}
static inline NI32 memSizeInBytes_0_Ilp7p16_der823rwr1(NI32 size_15){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_33;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_15, sizeof(HashEntry_0_tabcr240b1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_33 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_33 = ((NI32)2147483647);}
  return result_33;}
static inline NU32 hash_2_has9tn57v(NU32 u_0){
  NU32 result_3;
  result_3 = u_0;
  return result_3;}
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
