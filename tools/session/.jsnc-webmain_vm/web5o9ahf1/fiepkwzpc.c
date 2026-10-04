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
typedef struct FieldOff_0_fiepkwzpc FieldOff_0_fiepkwzpc;
typedef struct Cursor_0_nifb6mq6y1 Cursor_0_nifb6mq6y1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
typedef struct FieldOff_0_fiepkwzpc{
  NU32 sym_0;
  NI32 off_0;
  NI32 size_0;
  TCode_0_valzr1t4f code_0;
  NU32 tsym_0;
  NB8 variant_0;}
FieldOff_0_fiepkwzpc;
typedef struct seq_0_Id0odh1_fiepkwzpc{
  NI32 len_0;
  FieldOff_0_fiepkwzpc* data_0;}
seq_0_Id0odh1_fiepkwzpc;
typedef struct seq_0_Isyzizu1_comaa5xpt1{
  NI32 len_0;
  Cursor_0_nifb6mq6y1* data_0;}
seq_0_Isyzizu1_comaa5xpt1;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
typedef struct seq_0_Iflf8jf1_fiepkwzpc{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_fiepkwzpc;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct openArray_0_Ihovqtr1_fiepkwzpc{
  FieldOff_0_fiepkwzpc* a_0;
  NI32 len_0;}
openArray_0_Ihovqtr1_fiepkwzpc;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
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
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_Izov3yo_ast8ri79k keys_0;}
BiTable_0_Ipgo74p_ast8ri79k;
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
typedef struct seq_0_If70loa_nifh7u8pu1{
  NI32 len_0;
  NU32* data_0;}
seq_0_If70loa_nifh7u8pu1;
typedef struct BiTable_0_Ieutpr21_nifh7u8pu1{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_If70loa_nifh7u8pu1 keys_0;}
BiTable_0_Ieutpr21_nifh7u8pu1;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_In6doa_ast8ri79k keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
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
  BiTable_0_Ieutpr21_nifh7u8pu1 files_0;
  BiTable_0_I0ksat5_ast8ri79k syms_0;
  BiTable_0_Ipgo74p_ast8ri79k strings_0;
  BiTable_0_Itvq7bk_ast8ri79k integers_0;
  BiTable_0_Itxao711_ast8ri79k uintegers_0;
  BiTable_0_Iojfwmy1_ast8ri79k floats_0;}
Literals_0_nifh7u8pu1;
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
typedef NU8 LoadStatus_0_prorcx25w1;

#define LacksModuleName_0_prorcx25w1 ((NU8)0)
#define LacksOffset_0_prorcx25w1 ((NU8)1)
#define LacksPosition_0_prorcx25w1 ((NU8)2)
#define LacksNothing_0_prorcx25w1 ((NU8)3)
typedef struct LoadResult_0_prorcx25w1{
  LoadStatus_0_prorcx25w1 status_0;
  Cursor_0_nifb6mq6y1 decl_0;}
LoadResult_0_prorcx25w1;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct SizeAlign_0_siz2wt1it{
  NI32 size_0;
  NI32 align_0;}
SizeAlign_0_siz2wt1it;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
static inline seq_0_Iflf8jf1_fiepkwzpc newSeqUninit_0_I5mozxi1_fiepkwzpc(NI32 size_9);
static inline void add_0_Irnc3p1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* s_19, NB8 elem_7);
static inline NB8* getQ_7_Iul1no9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_24, NI32 i_7);
static inline void add_0_I9e6is9_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc* s_25, FieldOff_0_fiepkwzpc elem_8);
static inline seq_0_Id0odh1_fiepkwzpc newSeqUninit_0_Ilswql7_fiepkwzpc(NI32 size_11);
static inline NI32 len_3_If78p9o_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_31);
static inline openArray_0_Ihovqtr1_fiepkwzpc toOpenArray_1_Ilfv4hf_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_32);
static inline NI32 memSizeInBytes_0_Ih4q01h_fiepkwzpc(NI32 size_17);
static inline NI32 capInBytes_0_In1m6ni_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_38);
NB8 resize_0_I2yw78g1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* dest_7, NI32 addedElements_7);
static inline NI32 capInBytes_0_I62hqc31_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_39);
NB8 resize_0_Iupp4rl1_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc* dest_8, NI32 addedElements_8);
static inline NI32 memSizeInBytes_0_Icryocg_fiepkwzpc(NI32 size_18);
static inline FieldOff_0_fiepkwzpc* rawData_0_Ifr35xc1_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_41);
static inline NI32 len_6_Ikuawih_fiepkwzpc(openArray_0_Ihovqtr1_fiepkwzpc a_4);
static inline FieldOff_0_fiepkwzpc* getQ_10_Iu0e57f_fiepkwzpc(openArray_0_Ihovqtr1_fiepkwzpc x_3, NI32 idx_4);
void eQdestroy_1_Ijysww_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_63);
static inline void eQwasMoved_1_Imwcp1s_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc* s_64);
void eQdestroy_1_I7a20g9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_69);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13);
static inline string_0_sysvq0asl* getQ_0_I93d71y_comaa5xpt1(BiTable_0_Icvz6lt_buiyylk1h1 t_21, NU32 litId_6);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I11024699549390617459_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I10462096440466995513_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I3225181402180923291_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I973692718279674627_comaa5xpt1;
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
extern LoadResult_0_prorcx25w1 tryLoadSymSafe_0_modzy18mg1(NU32 s_0);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern LongString_0_sysvq0asl const strlit_0_I13413619771642637377_comaa5xpt1;
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
extern LongString_0_sysvq0asl const strlit_0_I6313045265747232047_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I7023501325319911082_comaa5xpt1;
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
extern LongString_0_sysvq0asl const strlit_0_I3021806080610957510_comaa5xpt1;
static inline seq_0_Isyzizu1_comaa5xpt1 newSeqUninit_0_Iikx2qh1_comaa5xpt1(NI32 size_32);
static inline seq_0_Ift2sne_chu5m1rja1 newSeqUninit_0_Iggfvwp_chu5m1rja1(NI32 size_32);
static inline void add_0_Insw6ce1_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1* s_144, Cursor_0_nifb6mq6y1 elem_37);
static inline void add_0_I8kd4i4_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_114, NI32 elem_27);
static inline NI32 len_3_Ilsmz1h_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_174);
static inline Cursor_0_nifb6mq6y1* getQ_7_Iyegbq3_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_155, NI32 i_44);
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36);
extern LongString_0_sysvq0asl const strlit_0_I4956278306908871092_comaa5xpt1;
extern void eQdestroy_1_Iv9ij5i1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_34);
extern void eQdestroy_1_Ir7cqbo_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_350);
extern SizeAlign_0_siz2wt1it sizeAlignOfType_0_siz2wt1it(Cursor_0_nifb6mq6y1 typ_0, NI32 depth_0);
extern LongString_0_sysvq0asl const strlit_0_I4167480082662538754_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13752166055203769914_comaa5xpt1;
static inline seq_0_In6doa_ast8ri79k newSeqUninit_0_Ieodq4s1_ast8ri79k(NI32 size_32);
static inline void add_0_I34il1q_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_112, NU32 elem_26);
static inline NI32 len_3_I6y2imo_buiyylk1h1(seq_0_In6doa_ast8ri79k s_56);
static inline NU32* getQ_7_I2v00yv1_buiyylk1h1(seq_0_In6doa_ast8ri79k s_58, NI32 i_28);
extern void eQdestroy_1_Iscb4i31_ast8ri79k(seq_0_In6doa_ast8ri79k s_65);
extern LongString_0_sysvq0asl const strlit_0_I2171368188661376471_comaa5xpt1;
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10);
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6);
static inline NU32 litId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_7);
static inline string_0_sysvq0asl* getQ_0_Iplpzal1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k t_6, NU32 litId_5);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_comaa5xpt1;
extern void dealloc_1_sysvq0asl(void* p_20);
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
extern void X60Qini_0_modzy18mg1(void);
extern void X60Qini_0_siz2wt1it(void);
extern void X60Qini_0_valzr1t4f(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline NI32 memSizeInBytes_0_I3r8cpo1_comaa5xpt1(NI32 size_66);
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33);
static inline NI32 capInBytes_0_I0ia6g61_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_231);
extern NB8 resize_0_I6nu0dd_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1* dest_31, NI32 addedElements_31);
static inline NI32 capInBytes_0_Iet286n_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_72);
extern NB8 resize_0_I8l4tya_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* dest_22, NI32 addedElements_22);
static inline NI32 memSizeInBytes_0_Ivqzo5x1_ast8ri79k(NI32 size_33);
static inline NI32 capInBytes_0_Iev6wua1_ast8ri79k(seq_0_In6doa_ast8ri79k s_73);
extern NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_ast8ri79k* dest_8, NI32 addedElements_8);
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
static inline NU32 litId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_9);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
LongString_0_sysvq0asl const strlit_0_I14656641239204103783_fiepkwzpc = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typevars"}
;
NB8 X60QiniGuard_0_fiepkwzpc;
string_0_sysvq0asl nodeTag_0_fiepkwzpc(Cursor_0_nifb6mq6y1 n_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  nimStrDestroy(result_0);
  NU32 X60Qx_30 = tagId_0_nifb6mq6y1(n_0);
  string_0_sysvq0asl* X60Qx_31 = getQ_0_I93d71y_comaa5xpt1(pool_0_nifh7u8pu1.tags_0, X60Qx_30);
  string_0_sysvq0asl X60Qx_32 = nimStrDup((*X60Qx_31));
  result_0 = X60Qx_32;
  return result_0;}
TCode_0_valzr1t4f scalarCodeOfType_0_fiepkwzpc(Cursor_0_nifb6mq6y1 typeCur_0, NU32* tsym_0){
  TCode_0_valzr1t4f result_1;
  (*tsym_0) = ((NU32)0u);
  Cursor_0_nifb6mq6y1 c_0 = eQdup_0_nifb6mq6y1(typeCur_0);
  NI32 guard_0 = 0;
  {
    while (guard_0 < 32){
      {
        inc_1_I6wjjge_aow2h993l1((&guard_0));
        NifKind_0_nif81dubp1 X60Qx_33 = kind_0_nifb6mq6y1(c_0);
        if (X60Qx_33 == 11){
          string_0_sysvq0asl X60Qtmp_0 = nodeTag_0_fiepkwzpc(c_0);
          NB8 X60Qtc_7 = nimStrAtLe_0_sysvq0asl(X60Qtmp_0, 0, (NC8)'f');
          if (X60Qtc_7){
            NB8 X60Qtc_8 = nimStrAtLe_0_sysvq0asl(X60Qtmp_0, 0, (NC8)'c');
            if (X60Qtc_8){
              if (equalStrings_0_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
                .bytes_0 = 25345u, .more_0 = NIM_NIL}
              )){
                goto X60Qsc_3;}
              else if (equalStrings_0_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
                .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_buiyylk1h1)}
              )){
                goto X60Qsc_4;}}
            else {
              if (equalStrings_0_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
                .bytes_0 = 26113u, .more_0 = NIM_NIL}
              )){
                goto X60Qsc_2;}
              else if (equalStrings_0_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
                .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_comaa5xpt1)}
              )){
                goto X60Qsc_5;}}}
          else {
            NB8 X60Qtc_9 = nimStrAtLe_0_sysvq0asl(X60Qtmp_0, 1, (NC8)'n');
            if (X60Qtc_9){
              if (equalStrings_0_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
                .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_comaa5xpt1)}
              )){
                goto X60Qsc_5;}
              else if (equalStrings_0_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
                .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
              )){
                goto X60Qsc_6;}}
            else {
              if (equalStrings_0_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
                .bytes_0 = 26881u, .more_0 = NIM_NIL}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
                .bytes_0 = 29953u, .more_0 = NIM_NIL}
              )){
                goto X60Qsc_1;}}}
          goto X60Qsc_11;
          X60Qsc_0: ;
          nimStrDestroy(X60Qtmp_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return 1;
          goto X60Qsc_10;
          X60Qsc_1: ;
          nimStrDestroy(X60Qtmp_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return 0;
          goto X60Qsc_10;
          X60Qsc_2: ;
          nimStrDestroy(X60Qtmp_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return 2;
          goto X60Qsc_10;
          X60Qsc_3: ;
          nimStrDestroy(X60Qtmp_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return 5;
          goto X60Qsc_10;
          X60Qsc_4: ;
          nimStrDestroy(X60Qtmp_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return 4;
          goto X60Qsc_10;
          X60Qsc_5: ;
          nimStrDestroy(X60Qtmp_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return 0;
          goto X60Qsc_10;
          X60Qsc_6: ;
          nimStrDestroy(X60Qtmp_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return 7;
          goto X60Qsc_10;
          X60Qsc_11: ;
          nimStrDestroy(X60Qtmp_0);
          eQdestroy_0_nifb6mq6y1((&c_0));
          return 6;
          X60Qsc_10: ;
          nimStrDestroy(X60Qtmp_0);}
        else {
          NifKind_0_nif81dubp1 X60Qx_34 = kind_0_nifb6mq6y1(c_0);
          if (X60Qx_34 == 4){
            NU32 s_0 = symId_0_nifb6mq6y1(c_0);
            LoadResult_0_prorcx25w1 res_0 = tryLoadSymSafe_0_modzy18mg1(s_0);
            NB8 X60Qx_13;
            NB8 X60Qx_35;
            if ((!(res_0.status_0 == 3))){
              X60Qx_35 = NIM_TRUE;}
            else {
              NifKind_0_nif81dubp1 X60Qx_36 = kind_0_nifb6mq6y1(res_0.decl_0);
              X60Qx_35 = (!(X60Qx_36 == 11));}
            if (X60Qx_35){
              X60Qx_13 = NIM_TRUE;}
            else {
              string_0_sysvq0asl X60Qtmp_1 = nodeTag_0_fiepkwzpc(res_0.decl_0);
              NB8 X60Qx_37 = eqQ_20_sysvq0asl(X60Qtmp_1, (string_0_sysvq0asl){
                .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
              );
              X60Qx_13 = (!X60Qx_37);
              nimStrDestroy(X60Qtmp_1);}
            if (X60Qx_13){
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
              eQdestroy_0_nifb6mq6y1((&c_0));
              return 6;}
            Cursor_0_nifb6mq6y1 d_0 = res_0.decl_0;
            eQwasMoved_0_nifb6mq6y1((&res_0.decl_0));
            inc_0_nifb6mq6y1((&d_0));
            Cursor_0_nifb6mq6y1 body_0 = (Cursor_0_nifb6mq6y1){
              .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
            ;
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_38 = kind_0_nifb6mq6y1(d_0);
                if ((!(X60Qx_38 == 12))){
                  NB8 X60Qx_39;
                  NifKind_0_nif81dubp1 X60Qx_40 = kind_0_nifb6mq6y1(d_0);
                  if (X60Qx_40 == 11){
                    X60Qx_39 = NIM_TRUE;}
                  else {
                    NifKind_0_nif81dubp1 X60Qx_41 = kind_0_nifb6mq6y1(d_0);
                    X60Qx_39 = (X60Qx_41 == 4);}
                  if (X60Qx_39){
                    string_0_sysvq0asl X60Qx_0;
                    nimStrWasMoved((&X60Qx_0));
                    NifKind_0_nif81dubp1 X60Qx_42 = kind_0_nifb6mq6y1(d_0);
                    if (X60Qx_42 == 11){
                      nimStrDestroy(X60Qx_0);
                      string_0_sysvq0asl X60Qx_43 = nodeTag_0_fiepkwzpc(d_0);
                      X60Qx_0 = X60Qx_43;}
                    else {
                      nimStrDestroy(X60Qx_0);
                      X60Qx_0 = (string_0_sysvq0asl){
                        .bytes_0 = 0u, .more_0 = NIM_NIL}
                      ;}
                    string_0_sysvq0asl t_1 = X60Qx_0;
                    nimStrWasMoved((&X60Qx_0));
                    NB8 X60Qx_44;
                    NB8 X60Qx_45;
                    NB8 X60Qx_46 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
                      .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I6313045265747232047_comaa5xpt1)}
                    );
                    if ((!X60Qx_46)){
                      NB8 X60Qx_47 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
                        .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_comaa5xpt1)}
                      );
                      X60Qx_45 = (!X60Qx_47);}
                    else {
                      X60Qx_45 = NIM_FALSE;}
                    if (X60Qx_45){
                      NB8 X60Qx_48 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
                        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I14656641239204103783_fiepkwzpc)}
                      );
                      X60Qx_44 = (!X60Qx_48);}
                    else {
                      X60Qx_44 = NIM_FALSE;}
                    if (X60Qx_44){
                      eQdestroy_0_nifb6mq6y1((&body_0));
                      Cursor_0_nifb6mq6y1 X60Qx_49 = eQdup_0_nifb6mq6y1(d_0);
                      body_0 = X60Qx_49;}
                    nimStrDestroy(t_1);
                    nimStrDestroy(X60Qx_0);}
                  skip_0_nifb6mq6y1((&d_0));}
                else {
                  break;}}}
            whileStmtLabel_2: ;
            NB8 X60Qx_14;
            NifKind_0_nif81dubp1 X60Qx_50 = kind_0_nifb6mq6y1(body_0);
            if (X60Qx_50 == 11){
              string_0_sysvq0asl X60Qtmp_2 = nodeTag_0_fiepkwzpc(body_0);
              NB8 X60Qx_51 = eqQ_20_sysvq0asl(X60Qtmp_2, (string_0_sysvq0asl){
                .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
              );
              X60Qx_14 = X60Qx_51;
              nimStrDestroy(X60Qtmp_2);}
            else {
              X60Qx_14 = NIM_FALSE;}
            if (X60Qx_14){
              (*tsym_0) = s_0;
              eQdestroy_0_nifb6mq6y1((&body_0));
              eQdestroy_0_nifb6mq6y1((&d_0));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
              eQdestroy_0_nifb6mq6y1((&c_0));
              return 7;}
            NB8 X60Qx_15;
            NifKind_0_nif81dubp1 X60Qx_52 = kind_0_nifb6mq6y1(body_0);
            if (X60Qx_52 == 11){
              string_0_sysvq0asl X60Qtmp_3 = nodeTag_0_fiepkwzpc(body_0);
              NB8 X60Qx_53 = eqQ_20_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_comaa5xpt1)}
              );
              X60Qx_15 = X60Qx_53;
              nimStrDestroy(X60Qtmp_3);}
            else {
              X60Qx_15 = NIM_FALSE;}
            if (X60Qx_15){
              Cursor_0_nifb6mq6y1 b_0 = body_0;
              eQwasMoved_0_nifb6mq6y1((&body_0));
              inc_0_nifb6mq6y1((&b_0));
              eQdestroy_0_nifb6mq6y1((&c_0));
              c_0 = b_0;
              eQwasMoved_0_nifb6mq6y1((&b_0));
              eQdestroy_0_nifb6mq6y1((&b_0));
              eQdestroy_0_nifb6mq6y1((&body_0));
              eQdestroy_0_nifb6mq6y1((&d_0));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
              goto continueLabel_1;
              eQdestroy_0_nifb6mq6y1((&b_0));}
            NB8 X60Qx_54;
            NifKind_0_nif81dubp1 X60Qx_55 = kind_0_nifb6mq6y1(body_0);
            if (X60Qx_55 == 11){
              X60Qx_54 = NIM_TRUE;}
            else {
              NifKind_0_nif81dubp1 X60Qx_56 = kind_0_nifb6mq6y1(body_0);
              X60Qx_54 = (X60Qx_56 == 4);}
            if (X60Qx_54){
              eQdestroy_0_nifb6mq6y1((&c_0));
              c_0 = body_0;
              eQwasMoved_0_nifb6mq6y1((&body_0));
              eQdestroy_0_nifb6mq6y1((&body_0));
              eQdestroy_0_nifb6mq6y1((&d_0));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
              goto continueLabel_1;}
            eQdestroy_0_nifb6mq6y1((&body_0));
            eQdestroy_0_nifb6mq6y1((&d_0));
            eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
            eQdestroy_0_nifb6mq6y1((&c_0));
            return 6;
            eQdestroy_0_nifb6mq6y1((&body_0));
            eQdestroy_0_nifb6mq6y1((&d_0));
            eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);}
          else {
            eQdestroy_0_nifb6mq6y1((&c_0));
            return 6;}}}
      continueLabel_1: ;}}
  whileStmtLabel_0: ;
  result_1 = 6;
  eQdestroy_0_nifb6mq6y1((&c_0));
  return result_1;
  eQdestroy_0_nifb6mq6y1((&c_0));
  return result_1;}
Cursor_0_nifb6mq6y1 objBodyOfSym_0_fiepkwzpc(NU32 typeSym_0){
  Cursor_0_nifb6mq6y1 result_2;
  eQwasMoved_0_nifb6mq6y1((&result_2));
  eQdestroy_0_nifb6mq6y1((&result_2));
  result_2 = (Cursor_0_nifb6mq6y1){
    .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
  ;
  if (((NU32)typeSym_0) == ((NU32)0u)){
    return result_2;}
  LoadResult_0_prorcx25w1 res_1 = tryLoadSymSafe_0_modzy18mg1(typeSym_0);
  NB8 X60Qx_16;
  NB8 X60Qx_57;
  if ((!(res_1.status_0 == 3))){
    X60Qx_57 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_58 = kind_0_nifb6mq6y1(res_1.decl_0);
    X60Qx_57 = (!(X60Qx_58 == 11));}
  if (X60Qx_57){
    X60Qx_16 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_4 = nodeTag_0_fiepkwzpc(res_1.decl_0);
    NB8 X60Qx_59 = eqQ_20_sysvq0asl(X60Qtmp_4, (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
    );
    X60Qx_16 = (!X60Qx_59);
    nimStrDestroy(X60Qtmp_4);}
  if (X60Qx_16){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
    return result_2;}
  Cursor_0_nifb6mq6y1 d_1 = res_1.decl_0;
  eQwasMoved_0_nifb6mq6y1((&res_1.decl_0));
  inc_0_nifb6mq6y1((&d_1));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_60 = kind_0_nifb6mq6y1(d_1);
      if ((!(X60Qx_60 == 12))){
        NB8 X60Qx_17;
        NifKind_0_nif81dubp1 X60Qx_61 = kind_0_nifb6mq6y1(d_1);
        if (X60Qx_61 == 11){
          string_0_sysvq0asl X60Qtmp_5 = nodeTag_0_fiepkwzpc(d_1);
          NB8 X60Qx_62 = eqQ_20_sysvq0asl(X60Qtmp_5, (string_0_sysvq0asl){
            .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
          );
          X60Qx_17 = X60Qx_62;
          nimStrDestroy(X60Qtmp_5);}
        else {
          X60Qx_17 = NIM_FALSE;}
        if (X60Qx_17){
          Cursor_0_nifb6mq6y1 X60Qtmp_6 = d_1;
          eQwasMoved_0_nifb6mq6y1((&d_1));
          eQdestroy_0_nifb6mq6y1((&d_1));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
          return X60Qtmp_6;}
        skip_0_nifb6mq6y1((&d_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&d_1));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
  return result_2;
  eQdestroy_0_nifb6mq6y1((&d_1));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
  return result_2;}
void collectOwnFields_0_fiepkwzpc(Cursor_0_nifb6mq6y1 objBody_0, NI32 startOff_0, seq_0_Id0odh1_fiepkwzpc* acc_0){
  seq_0_Isyzizu1_comaa5xpt1 lists_0 = newSeqUninit_0_Iikx2qh1_comaa5xpt1(0);
  seq_0_Ift2sne_chu5m1rja1 starts_0 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Iflf8jf1_fiepkwzpc inBranch_0 = newSeqUninit_0_I5mozxi1_fiepkwzpc(0);
  Cursor_0_nifb6mq6y1 c0_0 = eQdup_0_nifb6mq6y1(objBody_0);
  inc_0_nifb6mq6y1((&c0_0));
  skip_0_nifb6mq6y1((&c0_0));
  Cursor_0_nifb6mq6y1 X60Qtmp_7 = c0_0;
  eQwasMoved_0_nifb6mq6y1((&c0_0));
  add_0_Insw6ce1_comaa5xpt1((&lists_0), X60Qtmp_7);
  add_0_I8kd4i4_comaa5xpt1((&starts_0), startOff_0);
  add_0_Irnc3p1_fiepkwzpc((&inBranch_0), NIM_FALSE);
  NI32 li_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_63;
      NI32 X60Qx_64 = len_3_Ilsmz1h_comaa5xpt1(lists_0);
      if (li_0 < X60Qx_64){
        X60Qx_63 = (li_0 < 256);}
      else {
        X60Qx_63 = NIM_FALSE;}
      if (X60Qx_63){
        Cursor_0_nifb6mq6y1* X60Qx_65 = getQ_7_Iyegbq3_comaa5xpt1(lists_0, li_0);
        Cursor_0_nifb6mq6y1 c_1 = eQdup_0_nifb6mq6y1((*X60Qx_65));
        NI32* X60Qx_66 = getQ_7_Ir8kccm_comaa5xpt1(starts_0, li_0);
        NI32 offset_0 = (*X60Qx_66);
        NB8* X60Qx_67 = getQ_7_Iul1no9_fiepkwzpc(inBranch_0, li_0);
        NB8 branchHere_0 = (*X60Qx_67);
        inc_1_I6wjjge_aow2h993l1((&li_0));
        {
          while (NIM_TRUE){
            NifKind_0_nif81dubp1 X60Qx_68 = kind_0_nifb6mq6y1(c_1);
            if ((!(X60Qx_68 == 12))){
              NifKind_0_nif81dubp1 X60Qx_69 = kind_0_nifb6mq6y1(c_1);
              if (X60Qx_69 == 11){
                string_0_sysvq0asl tg_0 = nodeTag_0_fiepkwzpc(c_1);
                NB8 X60Qx_70;
                NB8 X60Qx_71 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                  .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
                );
                if (X60Qx_71){
                  X60Qx_70 = NIM_TRUE;}
                else {
                  NB8 X60Qx_72 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                    .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_comaa5xpt1)}
                  );
                  X60Qx_70 = X60Qx_72;}
                if (X60Qx_70){
                  Cursor_0_nifb6mq6y1 f_0 = eQdup_0_nifb6mq6y1(c_1);
                  NB8 X60Qx_73 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                    .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_comaa5xpt1)}
                  );
                  if (X60Qx_73){
                    inc_0_nifb6mq6y1((&f_0));
                    NB8 X60Qx_18;
                    NifKind_0_nif81dubp1 X60Qx_74 = kind_0_nifb6mq6y1(f_0);
                    if ((!(X60Qx_74 == 11))){
                      X60Qx_18 = NIM_TRUE;}
                    else {
                      string_0_sysvq0asl X60Qtmp_8 = nodeTag_0_fiepkwzpc(f_0);
                      NB8 X60Qx_75 = eqQ_20_sysvq0asl(X60Qtmp_8, (string_0_sysvq0asl){
                        .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
                      );
                      X60Qx_18 = (!X60Qx_75);
                      nimStrDestroy(X60Qtmp_8);}
                    if (X60Qx_18){
                      eQdestroy_0_nifb6mq6y1((&f_0));
                      nimStrDestroy(tg_0);
                      eQdestroy_0_nifb6mq6y1((&c_1));
                      eQdestroy_0_nifb6mq6y1((&c0_0));
                      eQdestroy_1_I7a20g9_fiepkwzpc(inBranch_0);
                      eQdestroy_1_Iv9ij5i1_chu5m1rja1(starts_0);
                      eQdestroy_1_Ir7cqbo_comaa5xpt1(lists_0);
                      return;}}
                  inc_0_nifb6mq6y1((&f_0));
                  NU32 fsym_0 = ((NU32)0u);
                  NB8 X60Qx_76;
                  NifKind_0_nif81dubp1 X60Qx_77 = kind_0_nifb6mq6y1(f_0);
                  if (X60Qx_77 == 4){
                    X60Qx_76 = NIM_TRUE;}
                  else {
                    NifKind_0_nif81dubp1 X60Qx_78 = kind_0_nifb6mq6y1(f_0);
                    X60Qx_76 = (X60Qx_78 == 5);}
                  if (X60Qx_76){
                    NU32 X60Qx_79 = symId_0_nifb6mq6y1(f_0);
                    fsym_0 = X60Qx_79;}
                  skip_0_nifb6mq6y1((&f_0));
                  skip_0_nifb6mq6y1((&f_0));
                  skip_0_nifb6mq6y1((&f_0));
                  SizeAlign_0_siz2wt1it fsa_0 = sizeAlignOfType_0_siz2wt1it(f_0, 0);
                  if (fsa_0.size_0 < 0){
                    eQdestroy_0_nifb6mq6y1((&f_0));
                    nimStrDestroy(tg_0);
                    eQdestroy_0_nifb6mq6y1((&c_1));
                    eQdestroy_0_nifb6mq6y1((&c0_0));
                    eQdestroy_1_I7a20g9_fiepkwzpc(inBranch_0);
                    eQdestroy_1_Iv9ij5i1_chu5m1rja1(starts_0);
                    eQdestroy_1_Ir7cqbo_comaa5xpt1(lists_0);
                    return;}
                  NI32 X60Qx_1;
                  if (0 < fsa_0.align_0){
                    X60Qx_1 = fsa_0.align_0;}
                  else {
                    X60Qx_1 = 1;}
                  NI32 a_0 = X60Qx_1;
                  if ((!(((NI32)(offset_0 % a_0)) == 0))){
                    offset_0 = ((NI32)(((NI32)(offset_0 + a_0)) - ((NI32)(offset_0 % a_0))));}
                  NU32 nested_0 = ((NU32)0u);
                  TCode_0_valzr1t4f code_0 = scalarCodeOfType_0_fiepkwzpc(f_0, (&nested_0));
                  add_0_I9e6is9_fiepkwzpc(acc_0, (FieldOff_0_fiepkwzpc){
                    .sym_0 = fsym_0, .off_0 = offset_0, .size_0 = fsa_0.size_0, .code_0 = code_0, .tsym_0 = nested_0, .variant_0 = branchHere_0}
                  );
                  offset_0 = ((NI32)(offset_0 + fsa_0.size_0));
                  eQdestroy_0_nifb6mq6y1((&f_0));}
                NB8 X60Qx_80 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                  .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_comaa5xpt1)}
                );
                if (X60Qx_80){
                  Cursor_0_nifb6mq6y1 k_0 = eQdup_0_nifb6mq6y1(c_1);
                  inc_0_nifb6mq6y1((&k_0));
                  skip_0_nifb6mq6y1((&k_0));
                  NI32 uSize_0 = 0;
                  NI32 uAlign_0 = 1;
                  Cursor_0_nifb6mq6y1 kk_0 = eQdup_0_nifb6mq6y1(k_0);
                  {
                    while (NIM_TRUE){
                      NifKind_0_nif81dubp1 X60Qx_81 = kind_0_nifb6mq6y1(kk_0);
                      if ((!(X60Qx_81 == 12))){
                        NB8 X60Qx_19;
                        NifKind_0_nif81dubp1 X60Qx_82 = kind_0_nifb6mq6y1(kk_0);
                        if (X60Qx_82 == 11){
                          NB8 X60Qx_20;
                          string_0_sysvq0asl X60Qtmp_9 = nodeTag_0_fiepkwzpc(kk_0);
                          NB8 X60Qx_83 = eqQ_20_sysvq0asl(X60Qtmp_9, (string_0_sysvq0asl){
                            .bytes_0 = 6713090u, .more_0 = NIM_NIL}
                          );
                          if (X60Qx_83){
                            X60Qx_20 = NIM_TRUE;}
                          else {
                            string_0_sysvq0asl X60Qtmp_10 = nodeTag_0_fiepkwzpc(kk_0);
                            NB8 X60Qx_84 = eqQ_20_sysvq0asl(X60Qtmp_10, (string_0_sysvq0asl){
                              .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_comaa5xpt1)}
                            );
                            X60Qx_20 = X60Qx_84;
                            nimStrDestroy(X60Qtmp_10);}
                          X60Qx_19 = X60Qx_20;
                          nimStrDestroy(X60Qtmp_9);}
                        else {
                          X60Qx_19 = NIM_FALSE;}
                        if (X60Qx_19){
                          Cursor_0_nifb6mq6y1 b_1 = eQdup_0_nifb6mq6y1(kk_0);
                          inc_0_nifb6mq6y1((&b_1));
                          string_0_sysvq0asl X60Qtmp_11 = nodeTag_0_fiepkwzpc(kk_0);
                          NB8 X60Qx_85 = eqQ_20_sysvq0asl(X60Qtmp_11, (string_0_sysvq0asl){
                            .bytes_0 = 6713090u, .more_0 = NIM_NIL}
                          );
                          if (X60Qx_85){
                            skip_0_nifb6mq6y1((&b_1));}
                          NB8 X60Qx_21;
                          NifKind_0_nif81dubp1 X60Qx_86 = kind_0_nifb6mq6y1(b_1);
                          if (X60Qx_86 == 11){
                            string_0_sysvq0asl X60Qtmp_12 = nodeTag_0_fiepkwzpc(b_1);
                            NB8 X60Qx_87 = eqQ_20_sysvq0asl(X60Qtmp_12, (string_0_sysvq0asl){
                              .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_comaa5xpt1)}
                            );
                            X60Qx_21 = X60Qx_87;
                            nimStrDestroy(X60Qtmp_12);}
                          else {
                            X60Qx_21 = NIM_FALSE;}
                          if (X60Qx_21){
                            SizeAlign_0_siz2wt1it bsa_0 = sizeAlignOfType_0_siz2wt1it(b_1, 0);
                            if (bsa_0.size_0 < 0){
                              nimStrDestroy(X60Qtmp_11);
                              eQdestroy_0_nifb6mq6y1((&b_1));
                              eQdestroy_0_nifb6mq6y1((&kk_0));
                              eQdestroy_0_nifb6mq6y1((&k_0));
                              nimStrDestroy(tg_0);
                              eQdestroy_0_nifb6mq6y1((&c_1));
                              eQdestroy_0_nifb6mq6y1((&c0_0));
                              eQdestroy_1_I7a20g9_fiepkwzpc(inBranch_0);
                              eQdestroy_1_Iv9ij5i1_chu5m1rja1(starts_0);
                              eQdestroy_1_Ir7cqbo_comaa5xpt1(lists_0);
                              return;}
                            if (uSize_0 < bsa_0.size_0){
                              uSize_0 = bsa_0.size_0;}
                            if (uAlign_0 < bsa_0.align_0){
                              uAlign_0 = bsa_0.align_0;}}
                          nimStrDestroy(X60Qtmp_11);
                          eQdestroy_0_nifb6mq6y1((&b_1));}
                        skip_0_nifb6mq6y1((&kk_0));}
                      else {
                        break;}}}
                  whileStmtLabel_2: ;
                  if (0 < uSize_0){
                    if ((!(((NI32)(offset_0 % uAlign_0)) == 0))){
                      offset_0 = ((NI32)(((NI32)(offset_0 + uAlign_0)) - ((NI32)(offset_0 % uAlign_0))));}
                    NI32 unionStart_0 = offset_0;
                    Cursor_0_nifb6mq6y1 kb_0 = k_0;
                    eQwasMoved_0_nifb6mq6y1((&k_0));
                    {
                      while (NIM_TRUE){
                        NifKind_0_nif81dubp1 X60Qx_88 = kind_0_nifb6mq6y1(kb_0);
                        if ((!(X60Qx_88 == 12))){
                          NB8 X60Qx_22;
                          NifKind_0_nif81dubp1 X60Qx_89 = kind_0_nifb6mq6y1(kb_0);
                          if (X60Qx_89 == 11){
                            NB8 X60Qx_23;
                            string_0_sysvq0asl X60Qtmp_13 = nodeTag_0_fiepkwzpc(kb_0);
                            NB8 X60Qx_90 = eqQ_20_sysvq0asl(X60Qtmp_13, (string_0_sysvq0asl){
                              .bytes_0 = 6713090u, .more_0 = NIM_NIL}
                            );
                            if (X60Qx_90){
                              X60Qx_23 = NIM_TRUE;}
                            else {
                              string_0_sysvq0asl X60Qtmp_14 = nodeTag_0_fiepkwzpc(kb_0);
                              NB8 X60Qx_91 = eqQ_20_sysvq0asl(X60Qtmp_14, (string_0_sysvq0asl){
                                .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_comaa5xpt1)}
                              );
                              X60Qx_23 = X60Qx_91;
                              nimStrDestroy(X60Qtmp_14);}
                            X60Qx_22 = X60Qx_23;
                            nimStrDestroy(X60Qtmp_13);}
                          else {
                            X60Qx_22 = NIM_FALSE;}
                          if (X60Qx_22){
                            Cursor_0_nifb6mq6y1 b_2 = eQdup_0_nifb6mq6y1(kb_0);
                            inc_0_nifb6mq6y1((&b_2));
                            string_0_sysvq0asl X60Qtmp_15 = nodeTag_0_fiepkwzpc(kb_0);
                            NB8 X60Qx_92 = eqQ_20_sysvq0asl(X60Qtmp_15, (string_0_sysvq0asl){
                              .bytes_0 = 6713090u, .more_0 = NIM_NIL}
                            );
                            if (X60Qx_92){
                              skip_0_nifb6mq6y1((&b_2));}
                            NB8 X60Qx_24;
                            NifKind_0_nif81dubp1 X60Qx_93 = kind_0_nifb6mq6y1(b_2);
                            if (X60Qx_93 == 11){
                              string_0_sysvq0asl X60Qtmp_16 = nodeTag_0_fiepkwzpc(b_2);
                              NB8 X60Qx_94 = eqQ_20_sysvq0asl(X60Qtmp_16, (string_0_sysvq0asl){
                                .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_comaa5xpt1)}
                              );
                              X60Qx_24 = X60Qx_94;
                              nimStrDestroy(X60Qtmp_16);}
                            else {
                              X60Qx_24 = NIM_FALSE;}
                            if (X60Qx_24){
                              Cursor_0_nifb6mq6y1 bs_0 = b_2;
                              eQwasMoved_0_nifb6mq6y1((&b_2));
                              inc_0_nifb6mq6y1((&bs_0));
                              Cursor_0_nifb6mq6y1 X60Qtmp_17 = bs_0;
                              eQwasMoved_0_nifb6mq6y1((&bs_0));
                              add_0_Insw6ce1_comaa5xpt1((&lists_0), X60Qtmp_17);
                              add_0_I8kd4i4_comaa5xpt1((&starts_0), unionStart_0);
                              add_0_Irnc3p1_fiepkwzpc((&inBranch_0), NIM_TRUE);
                              eQdestroy_0_nifb6mq6y1((&bs_0));}
                            nimStrDestroy(X60Qtmp_15);
                            eQdestroy_0_nifb6mq6y1((&b_2));}
                          skip_0_nifb6mq6y1((&kb_0));}
                        else {
                          break;}}}
                    whileStmtLabel_3: ;
                    offset_0 = ((NI32)(unionStart_0 + uSize_0));
                    eQdestroy_0_nifb6mq6y1((&kb_0));}
                  eQdestroy_0_nifb6mq6y1((&kk_0));
                  eQdestroy_0_nifb6mq6y1((&k_0));}
                nimStrDestroy(tg_0);}
              skip_0_nifb6mq6y1((&c_1));}
            else {
              break;}}}
        whileStmtLabel_1: ;
        eQdestroy_0_nifb6mq6y1((&c_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&c0_0));
  eQdestroy_1_I7a20g9_fiepkwzpc(inBranch_0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(starts_0);
  eQdestroy_1_Ir7cqbo_comaa5xpt1(lists_0);}
seq_0_Id0odh1_fiepkwzpc fieldOffsetsOfType_0_fiepkwzpc(NU32 typeSym_1){
  seq_0_Id0odh1_fiepkwzpc result_3;
  eQwasMoved_1_Imwcp1s_fiepkwzpc((&result_3));
  eQdestroy_1_Ijysww_fiepkwzpc(result_3);
  seq_0_Id0odh1_fiepkwzpc X60Qx_95 = newSeqUninit_0_Ilswql7_fiepkwzpc(0);
  result_3 = X60Qx_95;
  seq_0_In6doa_ast8ri79k chain_0 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  NU32 sym_0 = typeSym_1;
  NI32 guard_1 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_96;
      if ((!(((NU32)sym_0) == ((NU32)0u)))){
        X60Qx_96 = (guard_1 < 64);}
      else {
        X60Qx_96 = NIM_FALSE;}
      if (X60Qx_96){
        Cursor_0_nifb6mq6y1 body_1 = objBodyOfSym_0_fiepkwzpc(sym_0);
        NifKind_0_nif81dubp1 X60Qx_97 = kind_0_nifb6mq6y1(body_1);
        if ((!(X60Qx_97 == 11))){
          eQdestroy_0_nifb6mq6y1((&body_1));
          goto whileStmtLabel_0;}
        add_0_I34il1q_comaa5xpt1((&chain_0), sym_0);
        Cursor_0_nifb6mq6y1 c_2 = body_1;
        eQwasMoved_0_nifb6mq6y1((&body_1));
        inc_0_nifb6mq6y1((&c_2));
        NU32 X60Qx_2;
        NifKind_0_nif81dubp1 X60Qx_98 = kind_0_nifb6mq6y1(c_2);
        if (X60Qx_98 == 4){
          NU32 X60Qx_99 = symId_0_nifb6mq6y1(c_2);
          X60Qx_2 = X60Qx_99;}
        else {
          X60Qx_2 = ((NU32)0u);}
        sym_0 = X60Qx_2;
        inc_1_I6wjjge_aow2h993l1((&guard_1));
        eQdestroy_0_nifb6mq6y1((&c_2));
        eQdestroy_0_nifb6mq6y1((&body_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 k_1 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_100 = len_3_I6y2imo_buiyylk1h1(chain_0);
      if (k_1 < X60Qx_100){
        NU32* X60Qx_101 = getQ_7_I2v00yv1_buiyylk1h1(chain_0, k_1);
        Cursor_0_nifb6mq6y1 body_2 = objBodyOfSym_0_fiepkwzpc((*X60Qx_101));
        NifKind_0_nif81dubp1 X60Qx_102 = kind_0_nifb6mq6y1(body_2);
        if (X60Qx_102 == 11){
          Cursor_0_nifb6mq6y1 c_3 = eQdup_0_nifb6mq6y1(body_2);
          inc_0_nifb6mq6y1((&c_3));
          NI32 startOff_1 = 0;
          NifKind_0_nif81dubp1 X60Qx_103 = kind_0_nifb6mq6y1(c_3);
          if (X60Qx_103 == 4){
            SizeAlign_0_siz2wt1it bsa_1 = sizeAlignOfType_0_siz2wt1it(c_3, 0);
            if (0 <= bsa_1.size_0){
              startOff_1 = bsa_1.size_0;}}
          collectOwnFields_0_fiepkwzpc(body_2, startOff_1, (&result_3));
          eQdestroy_0_nifb6mq6y1((&c_3));}
        inc_1_I6wjjge_aow2h993l1((&k_1));
        eQdestroy_0_nifb6mq6y1((&body_2));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  eQdestroy_1_Iscb4i31_ast8ri79k(chain_0);
  return result_3;
  eQdestroy_1_Iscb4i31_ast8ri79k(chain_0);
  return result_3;}
NB8 isFlatPodType_0_fiepkwzpc(NU32 typeSym_2){
  NB8 result_4;
  seq_0_Id0odh1_fiepkwzpc top_0 = fieldOffsetsOfType_0_fiepkwzpc(typeSym_2);
  NI32 X60Qx_104 = len_3_If78p9o_fiepkwzpc(top_0);
  if (X60Qx_104 == 0){
    eQdestroy_1_Ijysww_fiepkwzpc(top_0);
    return NIM_FALSE;}
  seq_0_In6doa_ast8ri79k pending_0 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  NI32 head_0 = 0;
  seq_0_Id0odh1_fiepkwzpc fields_0 = top_0;
  eQwasMoved_1_Imwcp1s_fiepkwzpc((&top_0));
  NI32 guard_2 = 0;
  {
    while (guard_2 < 64){
      inc_1_I6wjjge_aow2h993l1((&guard_2));
      {
        openArray_0_Ihovqtr1_fiepkwzpc X60Qlf_0 = toOpenArray_1_Ilfv4hf_fiepkwzpc(fields_0);
        NI32 X60Qlf_1 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_105 = len_6_Ikuawih_fiepkwzpc(X60Qlf_0);
            if (X60Qlf_1 < X60Qx_105){
              {
                FieldOff_0_fiepkwzpc* X60Qii_3 = getQ_10_Iu0e57f_fiepkwzpc(X60Qlf_0, X60Qlf_1);
                if ((*X60Qii_3).code_0 == 6){
                  eQdestroy_1_Ijysww_fiepkwzpc(fields_0);
                  eQdestroy_1_Iscb4i31_ast8ri79k(pending_0);
                  eQdestroy_1_Ijysww_fiepkwzpc(top_0);
                  return NIM_FALSE;}
                if ((*X60Qii_3).code_0 == 7){
                  if (((NU32)(*X60Qii_3).tsym_0) == ((NU32)0u)){
                    eQdestroy_1_Ijysww_fiepkwzpc(fields_0);
                    eQdestroy_1_Iscb4i31_ast8ri79k(pending_0);
                    eQdestroy_1_Ijysww_fiepkwzpc(top_0);
                    return NIM_FALSE;}
                  add_0_I34il1q_comaa5xpt1((&pending_0), (*X60Qii_3).tsym_0);}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
            else {
              break;}}}
        whileStmtLabel_2: ;}
      forStmtLabel_1: ;
      if (pending_0.len_0 <= head_0){
        eQdestroy_1_Ijysww_fiepkwzpc(fields_0);
        eQdestroy_1_Iscb4i31_ast8ri79k(pending_0);
        eQdestroy_1_Ijysww_fiepkwzpc(top_0);
        return NIM_TRUE;}
      eQdestroy_1_Ijysww_fiepkwzpc(fields_0);
      NU32* X60Qx_106 = getQ_7_I2v00yv1_buiyylk1h1(pending_0, head_0);
      seq_0_Id0odh1_fiepkwzpc X60Qx_107 = fieldOffsetsOfType_0_fiepkwzpc((*X60Qx_106));
      fields_0 = X60Qx_107;
      inc_1_I6wjjge_aow2h993l1((&head_0));
      NI32 X60Qx_108 = len_3_If78p9o_fiepkwzpc(fields_0);
      if (X60Qx_108 == 0){
        eQdestroy_1_Ijysww_fiepkwzpc(fields_0);
        eQdestroy_1_Iscb4i31_ast8ri79k(pending_0);
        eQdestroy_1_Ijysww_fiepkwzpc(top_0);
        return NIM_FALSE;}}}
  whileStmtLabel_0: ;
  result_4 = NIM_FALSE;
  eQdestroy_1_Ijysww_fiepkwzpc(fields_0);
  eQdestroy_1_Iscb4i31_ast8ri79k(pending_0);
  eQdestroy_1_Ijysww_fiepkwzpc(top_0);
  return result_4;
  eQdestroy_1_Ijysww_fiepkwzpc(fields_0);
  eQdestroy_1_Iscb4i31_ast8ri79k(pending_0);
  eQdestroy_1_Ijysww_fiepkwzpc(top_0);
  return result_4;}
NI32 sizeOfSym_0_fiepkwzpc(NU32 typeSym_3){
  NI32 result_5;
  result_5 = -1;
  Cursor_0_nifb6mq6y1 body_3 = objBodyOfSym_0_fiepkwzpc(typeSym_3);
  NifKind_0_nif81dubp1 X60Qx_109 = kind_0_nifb6mq6y1(body_3);
  if ((!(X60Qx_109 == 11))){
    eQdestroy_0_nifb6mq6y1((&body_3));
    return result_5;}
  SizeAlign_0_siz2wt1it X60Qx_110 = sizeAlignOfType_0_siz2wt1it(body_3, 0);
  result_5 = X60Qx_110.size_0;
  eQdestroy_0_nifb6mq6y1((&body_3));
  return result_5;
  eQdestroy_0_nifb6mq6y1((&body_3));
  return result_5;}
string_0_sysvq0asl enumNameForOrdinal_0_fiepkwzpc(NU32 enumType_0, NI32 ord_0){
  string_0_sysvq0asl result_6;
  nimStrWasMoved((&result_6));
  nimStrDestroy(result_6);
  result_6 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (((NU32)enumType_0) == ((NU32)0u)){
    return result_6;}
  NU32 typeSym_4 = enumType_0;
  LoadResult_0_prorcx25w1 res0_0 = tryLoadSymSafe_0_modzy18mg1(enumType_0);
  NB8 X60Qx_25;
  NifKind_0_nif81dubp1 X60Qx_111 = kind_0_nifb6mq6y1(res0_0.decl_0);
  if (X60Qx_111 == 11){
    string_0_sysvq0asl X60Qtmp_18 = nodeTag_0_fiepkwzpc(res0_0.decl_0);
    NB8 X60Qx_112 = eqQ_20_sysvq0asl(X60Qtmp_18, (string_0_sysvq0asl){
      .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_comaa5xpt1)}
    );
    X60Qx_25 = X60Qx_112;
    nimStrDestroy(X60Qtmp_18);}
  else {
    X60Qx_25 = NIM_FALSE;}
  if (X60Qx_25){
    Cursor_0_nifb6mq6y1 d_2 = res0_0.decl_0;
    eQwasMoved_0_nifb6mq6y1((&res0_0.decl_0));
    inc_0_nifb6mq6y1((&d_2));
    skip_0_nifb6mq6y1((&d_2));
    skip_0_nifb6mq6y1((&d_2));
    skip_0_nifb6mq6y1((&d_2));
    NifKind_0_nif81dubp1 X60Qx_113 = kind_0_nifb6mq6y1(d_2);
    if (X60Qx_113 == 4){
      NU32 X60Qx_114 = symId_0_nifb6mq6y1(d_2);
      typeSym_4 = X60Qx_114;}
    eQdestroy_0_nifb6mq6y1((&d_2));}
  LoadResult_0_prorcx25w1 res_2 = tryLoadSymSafe_0_modzy18mg1(typeSym_4);
  NB8 X60Qx_26;
  NifKind_0_nif81dubp1 X60Qx_115 = kind_0_nifb6mq6y1(res_2.decl_0);
  if ((!(X60Qx_115 == 11))){
    X60Qx_26 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_19 = nodeTag_0_fiepkwzpc(res_2.decl_0);
    NB8 X60Qx_116 = eqQ_20_sysvq0asl(X60Qtmp_19, (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
    );
    X60Qx_26 = (!X60Qx_116);
    nimStrDestroy(X60Qtmp_19);}
  if (X60Qx_26){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res0_0);
    return result_6;}
  Cursor_0_nifb6mq6y1 c_4 = res_2.decl_0;
  eQwasMoved_0_nifb6mq6y1((&res_2.decl_0));
  inc_0_nifb6mq6y1((&c_4));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_117 = kind_0_nifb6mq6y1(c_4);
      if ((!(X60Qx_117 == 12))){
        NB8 X60Qx_27;
        NifKind_0_nif81dubp1 X60Qx_118 = kind_0_nifb6mq6y1(c_4);
        if (X60Qx_118 == 11){
          NB8 X60Qx_28;
          string_0_sysvq0asl X60Qtmp_20 = nodeTag_0_fiepkwzpc(c_4);
          NB8 X60Qx_119 = eqQ_20_sysvq0asl(X60Qtmp_20, (string_0_sysvq0asl){
            .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_comaa5xpt1)}
          );
          if (X60Qx_119){
            X60Qx_28 = NIM_TRUE;}
          else {
            string_0_sysvq0asl X60Qtmp_21 = nodeTag_0_fiepkwzpc(c_4);
            NB8 X60Qx_120 = eqQ_20_sysvq0asl(X60Qtmp_21, (string_0_sysvq0asl){
              .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_comaa5xpt1)}
            );
            X60Qx_28 = X60Qx_120;
            nimStrDestroy(X60Qtmp_21);}
          X60Qx_27 = X60Qx_28;
          nimStrDestroy(X60Qtmp_20);}
        else {
          X60Qx_27 = NIM_FALSE;}
        if (X60Qx_27){
          Cursor_0_nifb6mq6y1 e_0 = c_4;
          eQwasMoved_0_nifb6mq6y1((&c_4));
          inc_0_nifb6mq6y1((&e_0));
          {
            while (NIM_TRUE){
              NifKind_0_nif81dubp1 X60Qx_121 = kind_0_nifb6mq6y1(e_0);
              if ((!(X60Qx_121 == 12))){
                NB8 X60Qx_29;
                NifKind_0_nif81dubp1 X60Qx_122 = kind_0_nifb6mq6y1(e_0);
                if (X60Qx_122 == 11){
                  string_0_sysvq0asl X60Qtmp_22 = nodeTag_0_fiepkwzpc(e_0);
                  NB8 X60Qx_123 = eqQ_20_sysvq0asl(X60Qtmp_22, (string_0_sysvq0asl){
                    .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_comaa5xpt1)}
                  );
                  X60Qx_29 = X60Qx_123;
                  nimStrDestroy(X60Qtmp_22);}
                else {
                  X60Qx_29 = NIM_FALSE;}
                if (X60Qx_29){
                  Cursor_0_nifb6mq6y1 f_1 = eQdup_0_nifb6mq6y1(e_0);
                  inc_0_nifb6mq6y1((&f_1));
                  skip_0_nifb6mq6y1((&f_1));
                  skip_0_nifb6mq6y1((&f_1));
                  skip_0_nifb6mq6y1((&f_1));
                  skip_0_nifb6mq6y1((&f_1));
                  NifKind_0_nif81dubp1 X60Qx_124 = kind_0_nifb6mq6y1(f_1);
                  if (X60Qx_124 == 11){
                    Cursor_0_nifb6mq6y1 t_2 = f_1;
                    eQwasMoved_0_nifb6mq6y1((&f_1));
                    inc_0_nifb6mq6y1((&t_2));
                    NI32 o_0 = -1;
                    NifKind_0_nif81dubp1 X60Qx_125 = kind_0_nifb6mq6y1(t_2);
                    if (X60Qx_125 == 8){
                      NU32 X60Qx_126 = intId_0_nifb6mq6y1(t_2);
                      NI64* X60Qx_127 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_126);
                      o_0 = ((NI32)(*X60Qx_127));}
                    skip_0_nifb6mq6y1((&t_2));
                    NB8 X60Qx_128;
                    if (o_0 == ord_0){
                      NifKind_0_nif81dubp1 X60Qx_129 = kind_0_nifb6mq6y1(t_2);
                      X60Qx_128 = (X60Qx_129 == 6);}
                    else {
                      X60Qx_128 = NIM_FALSE;}
                    if (X60Qx_128){
                      NU32 X60Qx_130 = litId_0_nifb6mq6y1(t_2);
                      string_0_sysvq0asl* X60Qx_131 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_130);
                      string_0_sysvq0asl X60Qx_132 = nimStrDup((*X60Qx_131));
                      result_6 = X60Qx_132;
                      eQdestroy_0_nifb6mq6y1((&t_2));
                      eQdestroy_0_nifb6mq6y1((&f_1));
                      eQdestroy_0_nifb6mq6y1((&e_0));
                      eQdestroy_0_nifb6mq6y1((&c_4));
                      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
                      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res0_0);
                      return result_6;}
                    eQdestroy_0_nifb6mq6y1((&t_2));}
                  eQdestroy_0_nifb6mq6y1((&f_1));}
                skip_0_nifb6mq6y1((&e_0));}
              else {
                break;}}}
          whileStmtLabel_1: ;
          eQdestroy_0_nifb6mq6y1((&e_0));
          eQdestroy_0_nifb6mq6y1((&c_4));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res0_0);
          return result_6;
          eQdestroy_0_nifb6mq6y1((&e_0));}
        skip_0_nifb6mq6y1((&c_4));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&c_4));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res0_0);
  return result_6;
  eQdestroy_0_nifb6mq6y1((&c_4));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res0_0);
  return result_6;}
static inline seq_0_Iflf8jf1_fiepkwzpc newSeqUninit_0_I5mozxi1_fiepkwzpc(NI32 size_9){
  seq_0_Iflf8jf1_fiepkwzpc result_10;
  if (size_9 == 0){
    result_10 = (seq_0_Iflf8jf1_fiepkwzpc){
      .len_0 = size_9, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Ih4q01h_fiepkwzpc(size_9);
    void* X60Qx_138 = alloc_1_sysvq0asl(memSize_2);
    result_10 = (seq_0_Iflf8jf1_fiepkwzpc){
      .len_0 = size_9, .data_0 = ((NB8*)X60Qx_138)}
    ;
    if ((!(result_10.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_139 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_10.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_10;}
static inline void add_0_Irnc3p1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* s_19, NB8 elem_7){
  NI32 L_2 = (*s_19).len_0;
  NI32 X60Qx_144 = capInBytes_0_In1m6ni_fiepkwzpc((*s_19));
  if (X60Qx_144 < ((NI32)(((NI32)(L_2 * sizeof(NB8))) + sizeof(NB8)))){
    NB8 X60Qx_145 = resize_0_I2yw78g1_fiepkwzpc(s_19, 1);
    if ((!X60Qx_145)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_19).len_0));
  (*s_19).data_0[L_2] = elem_7;}
static inline NB8* getQ_7_Iul1no9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_24, NI32 i_7){
  NB8 X60Qx_148;
  if (i_7 < s_24.len_0){
    X60Qx_148 = (0 <= i_7);}
  else {
    X60Qx_148 = NIM_FALSE;}
  if ((!X60Qx_148)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NB8* result_14;
  result_14 = (&s_24.data_0[i_7]);
  return result_14;}
static inline void add_0_I9e6is9_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc* s_25, FieldOff_0_fiepkwzpc elem_8){
  NI32 L_3 = (*s_25).len_0;
  NI32 X60Qx_149 = capInBytes_0_I62hqc31_fiepkwzpc((*s_25));
  if (X60Qx_149 < ((NI32)(((NI32)(L_3 * sizeof(FieldOff_0_fiepkwzpc))) + sizeof(FieldOff_0_fiepkwzpc)))){
    NB8 X60Qx_150 = resize_0_Iupp4rl1_fiepkwzpc(s_25, 1);
    if ((!X60Qx_150)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_25).len_0));
  (*s_25).data_0[L_3] = elem_8;}
static inline seq_0_Id0odh1_fiepkwzpc newSeqUninit_0_Ilswql7_fiepkwzpc(NI32 size_11){
  seq_0_Id0odh1_fiepkwzpc result_15;
  if (size_11 == 0){
    result_15 = (seq_0_Id0odh1_fiepkwzpc){
      .len_0 = size_11, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_Icryocg_fiepkwzpc(size_11);
    void* X60Qx_151 = alloc_1_sysvq0asl(memSize_3);
    result_15 = (seq_0_Id0odh1_fiepkwzpc){
      .len_0 = size_11, .data_0 = ((FieldOff_0_fiepkwzpc*)X60Qx_151)}
    ;
    if ((!(result_15.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_152 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_15.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_15;}
static inline NI32 len_3_If78p9o_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_31){
  NI32 result_19;
  result_19 = s_31.len_0;
  return result_19;}
static inline openArray_0_Ihovqtr1_fiepkwzpc toOpenArray_1_Ilfv4hf_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_32){
  openArray_0_Ihovqtr1_fiepkwzpc result_20;
  FieldOff_0_fiepkwzpc* X60Qx_158 = rawData_0_Ifr35xc1_fiepkwzpc(s_32);
  result_20 = (openArray_0_Ihovqtr1_fiepkwzpc){
    .a_0 = X60Qx_158, .len_0 = s_32.len_0}
  ;
  return result_20;}
static inline NI32 memSizeInBytes_0_Ih4q01h_fiepkwzpc(NI32 size_17){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_26;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_17, sizeof(NB8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_26 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_26 = ((NI32)2147483647);}
  return result_26;}
static inline NI32 capInBytes_0_In1m6ni_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_38){
  NI32 result_31;
  NI32 X60Qx_5;
  if ((!(s_38.data_0 == NIM_NIL))){
    NI32 X60Qx_168 = allocatedSize_0_sysvq0asl(((void*)((void*)s_38.data_0)));
    X60Qx_5 = X60Qx_168;}
  else {
    X60Qx_5 = 0;}
  result_31 = X60Qx_5;
  return result_31;}
NB8 resize_0_I2yw78g1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* dest_7, NI32 addedElements_7){
  NB8 result_32;
  NI32 X60Qx_169 = capInBytes_0_In1m6ni_fiepkwzpc((*dest_7));
  NI32 oldCap_2 = ((NI32)(X60Qx_169 / sizeof(NB8)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_7);
  NI32 memSize_7 = memSizeInBytes_0_Ih4q01h_fiepkwzpc(newCap_2);
  void* X60Qx_170 = realloc_1_sysvq0asl(((void*)((void*)(*dest_7).data_0)), memSize_7);
  (*dest_7).data_0 = ((NB8*)X60Qx_170);
  if ((*dest_7).data_0 == NIM_NIL){
    (*dest_7).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_7);
    result_32 = NIM_FALSE;}
  else {
    result_32 = NIM_TRUE;}
  return result_32;}
static inline NI32 capInBytes_0_I62hqc31_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_39){
  NI32 result_33;
  NI32 X60Qx_6;
  if ((!(s_39.data_0 == NIM_NIL))){
    NI32 X60Qx_171 = allocatedSize_0_sysvq0asl(((void*)((void*)s_39.data_0)));
    X60Qx_6 = X60Qx_171;}
  else {
    X60Qx_6 = 0;}
  result_33 = X60Qx_6;
  return result_33;}
NB8 resize_0_Iupp4rl1_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc* dest_8, NI32 addedElements_8){
  NB8 result_34;
  NI32 X60Qx_172 = capInBytes_0_I62hqc31_fiepkwzpc((*dest_8));
  NI32 oldCap_3 = ((NI32)(X60Qx_172 / sizeof(FieldOff_0_fiepkwzpc)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_8);
  NI32 memSize_8 = memSizeInBytes_0_Icryocg_fiepkwzpc(newCap_3);
  void* X60Qx_173 = realloc_1_sysvq0asl(((void*)((void*)(*dest_8).data_0)), memSize_8);
  (*dest_8).data_0 = ((FieldOff_0_fiepkwzpc*)X60Qx_173);
  if ((*dest_8).data_0 == NIM_NIL){
    (*dest_8).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_8);
    result_34 = NIM_FALSE;}
  else {
    result_34 = NIM_TRUE;}
  return result_34;}
static inline NI32 memSizeInBytes_0_Icryocg_fiepkwzpc(NI32 size_18){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_35;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_18, sizeof(FieldOff_0_fiepkwzpc), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_35 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_35 = ((NI32)2147483647);}
  return result_35;}
static inline FieldOff_0_fiepkwzpc* rawData_0_Ifr35xc1_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_41){
  FieldOff_0_fiepkwzpc* result_39;
  result_39 = s_41.data_0;
  return result_39;}
static inline NI32 len_6_Ikuawih_fiepkwzpc(openArray_0_Ihovqtr1_fiepkwzpc a_4){
  NI32 result_40;
  result_40 = a_4.len_0;
  return result_40;}
static inline FieldOff_0_fiepkwzpc* getQ_10_Iu0e57f_fiepkwzpc(openArray_0_Ihovqtr1_fiepkwzpc x_3, NI32 idx_4){
  NB8 X60Qx_177;
  if (0 <= idx_4){
    X60Qx_177 = (idx_4 < x_3.len_0);}
  else {
    X60Qx_177 = NIM_FALSE;}
  if ((!X60Qx_177)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  FieldOff_0_fiepkwzpc* result_41;
  result_41 = (&x_3.a_0[idx_4]);
  return result_41;}
void eQdestroy_1_Ijysww_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_63){
  if ((!(s_63.data_0 == NIM_NIL))){
    NI32 i_13 = 0;
    {
      while (i_13 < s_63.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_13));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_63.data_0)));}}
static inline void eQwasMoved_1_Imwcp1s_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc* s_64){
  (*s_64).len_0 = 0;
  (*s_64).data_0 = NIM_NIL;}
void eQdestroy_1_I7a20g9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_69){
  if ((!(s_69.data_0 == NIM_NIL))){
    NI32 i_25 = 0;
    {
      while (i_25 < s_69.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_25));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_69.data_0)));}}
void X60Qini_0_fiepkwzpc(void){
  if (X60QiniGuard_0_fiepkwzpc){
    return;}
  X60QiniGuard_0_fiepkwzpc = NIM_TRUE;
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
  X60Qini_0_modzy18mg1();
  X60Qini_0_siz2wt1it();
  X60Qini_0_valzr1t4f();}
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
static inline string_0_sysvq0asl* getQ_0_I93d71y_comaa5xpt1(BiTable_0_Icvz6lt_buiyylk1h1 t_21, NU32 litId_6){
  string_0_sysvq0asl* result_63;
  NI32 idx_10 = ((NI32)(((NI32)litId_6) - ((NI32)1)));
  if ((!(idx_10 < t_21.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  string_0_sysvq0asl* X60Qx_1799 = getQ_7_Ir6d0tw_ast8ri79k(t_21.vals_0, idx_10);
  result_63 = X60Qx_1799;
  return result_63;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1){
  Cursor_0_nifb6mq6y1 result_4;
  result_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = src_1.owner_0, .p_0 = src_1.p_0, .rem_0 = src_1.rem_0}
  ;
  if ((!(result_4.owner_0 == NIM_NIL))){
    inc_1_I6wjjge_aow2h993l1((&(*result_4.owner_0).rc_0));}
  return result_4;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
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
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_ast8ri79k((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8){
  NU32 result_11;
  PackedToken_0_nifh7u8pu1 X60Qx_26 = load_0_nifb6mq6y1(c_8);
  NU32 X60Qx_27 = symId_0_nifh7u8pu1(X60Qx_26);
  result_11 = X60Qx_27;
  return result_11;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
  dec_1_I0nzoz91_ast8ri79k((&(*c_18).rem_0));}
static inline seq_0_Isyzizu1_comaa5xpt1 newSeqUninit_0_Iikx2qh1_comaa5xpt1(NI32 size_32){
  seq_0_Isyzizu1_comaa5xpt1 result_95;
  if (size_32 == 0){
    result_95 = (seq_0_Isyzizu1_comaa5xpt1){
      .len_0 = size_32, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_6 = memSizeInBytes_0_I3r8cpo1_comaa5xpt1(size_32);
    void* X60Qx_1853 = alloc_1_sysvq0asl(memSize_6);
    result_95 = (seq_0_Isyzizu1_comaa5xpt1){
      .len_0 = size_32, .data_0 = ((Cursor_0_nifb6mq6y1*)X60Qx_1853)}
    ;
    if ((!(result_95.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1854 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_95.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_6);}}
  return result_95;}
static inline seq_0_Ift2sne_chu5m1rja1 newSeqUninit_0_Iggfvwp_chu5m1rja1(NI32 size_32){
  seq_0_Ift2sne_chu5m1rja1 result_21;
  if (size_32 == 0){
    result_21 = (seq_0_Ift2sne_chu5m1rja1){
      .len_0 = size_32, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_16 = memSizeInBytes_0_Inv7kg3_chu5m1rja1(size_32);
    void* X60Qx_88 = alloc_1_sysvq0asl(memSize_16);
    result_21 = (seq_0_Ift2sne_chu5m1rja1){
      .len_0 = size_32, .data_0 = ((NI32*)X60Qx_88)}
    ;
    if ((!(result_21.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_89 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_21.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_16);}}
  return result_21;}
static inline void add_0_Insw6ce1_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1* s_144, Cursor_0_nifb6mq6y1 elem_37){
  NI32 L_11 = (*s_144).len_0;
  NI32 X60Qx_1822 = capInBytes_0_I0ia6g61_comaa5xpt1((*s_144));
  if (X60Qx_1822 < ((NI32)(((NI32)(L_11 * sizeof(Cursor_0_nifb6mq6y1))) + sizeof(Cursor_0_nifb6mq6y1)))){
    NB8 X60Qx_1823 = resize_0_I6nu0dd_comaa5xpt1(s_144, 1);
    if ((!X60Qx_1823)){
      eQdestroy_0_nifb6mq6y1((&elem_37));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_144).len_0));
  (*s_144).data_0[L_11] = elem_37;}
static inline void add_0_I8kd4i4_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_114, NI32 elem_27){
  NI32 L_2 = (*s_114).len_0;
  NI32 X60Qx_1797 = capInBytes_0_Iet286n_chu5m1rja1((*s_114));
  if (X60Qx_1797 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1798 = resize_0_I8l4tya_comaa5xpt1(s_114, 1);
    if ((!X60Qx_1798)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_114).len_0));
  (*s_114).data_0[L_2] = elem_27;}
static inline NI32 len_3_Ilsmz1h_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_174){
  NI32 result_101;
  result_101 = s_174.len_0;
  return result_101;}
static inline Cursor_0_nifb6mq6y1* getQ_7_Iyegbq3_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_155, NI32 i_44){
  NB8 X60Qx_1842;
  if (i_44 < s_155.len_0){
    X60Qx_1842 = (0 <= i_44);}
  else {
    X60Qx_1842 = NIM_FALSE;}
  if ((!X60Qx_1842)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  Cursor_0_nifb6mq6y1* result_88;
  result_88 = (&s_155.data_0[i_44]);
  return result_88;}
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36){
  NB8 X60Qx_1793;
  if (i_36 < s_110.len_0){
    X60Qx_1793 = (0 <= i_36);}
  else {
    X60Qx_1793 = NIM_FALSE;}
  if ((!X60Qx_1793)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NI32* result_62;
  result_62 = (&s_110.data_0[i_36]);
  return result_62;}
static inline seq_0_In6doa_ast8ri79k newSeqUninit_0_Ieodq4s1_ast8ri79k(NI32 size_32){
  seq_0_In6doa_ast8ri79k result_50;
  if (size_32 == 0){
    result_50 = (seq_0_In6doa_ast8ri79k){
      .len_0 = size_32, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_18 = memSizeInBytes_0_Ivqzo5x1_ast8ri79k(size_32);
    void* X60Qx_132 = alloc_1_sysvq0asl(memSize_18);
    result_50 = (seq_0_In6doa_ast8ri79k){
      .len_0 = size_32, .data_0 = ((NU32*)X60Qx_132)}
    ;
    if ((!(result_50.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_133 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_50.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_18);}}
  return result_50;}
static inline void add_0_I34il1q_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_112, NU32 elem_26){
  NI32 L_1 = (*s_112).len_0;
  NI32 X60Qx_1795 = capInBytes_0_Iev6wua1_ast8ri79k((*s_112));
  if (X60Qx_1795 < ((NI32)(((NI32)(L_1 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_1796 = resize_0_I6ho9ve_buiyylk1h1(s_112, 1);
    if ((!X60Qx_1796)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_112).len_0));
  (*s_112).data_0[L_1] = elem_26;}
static inline NI32 len_3_I6y2imo_buiyylk1h1(seq_0_In6doa_ast8ri79k s_56){
  NI32 result_20;
  result_20 = s_56.len_0;
  return result_20;}
static inline NU32* getQ_7_I2v00yv1_buiyylk1h1(seq_0_In6doa_ast8ri79k s_58, NI32 i_28){
  NB8 X60Qx_155;
  if (i_28 < s_58.len_0){
    X60Qx_155 = (0 <= i_28);}
  else {
    X60Qx_155 = NIM_FALSE;}
  if ((!X60Qx_155)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NU32* result_21;
  result_21 = (&s_58.data_0[i_28]);
  return result_21;}
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
static inline NU32 litId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_7){
  NU32 result_10;
  PackedToken_0_nifh7u8pu1 X60Qx_24 = load_0_nifb6mq6y1(c_7);
  NU32 X60Qx_25 = litId_0_nifh7u8pu1(X60Qx_24);
  result_10 = X60Qx_25;
  return result_10;}
static inline string_0_sysvq0asl* getQ_0_Iplpzal1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k t_6, NU32 litId_5){
  string_0_sysvq0asl* result_3;
  NI32 idx_0 = ((NI32)(((NI32)litId_5) - ((NI32)1)));
  if ((!(idx_0 < t_6.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  string_0_sysvq0asl* X60Qx_31 = getQ_7_Ir6d0tw_ast8ri79k(t_6.vals_0, idx_0);
  result_3 = X60Qx_31;
  return result_3;}
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
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5){
  NB8 X60Qx_52;
  if (i_5 < s_8.len_0){
    X60Qx_52 = (0 <= i_5);}
  else {
    X60Qx_52 = NIM_FALSE;}
  if ((!X60Qx_52)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  string_0_sysvq0asl* result_9;
  result_9 = (&s_8.data_0[i_5]);
  return result_9;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
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
static inline NI32 memSizeInBytes_0_I3r8cpo1_comaa5xpt1(NI32 size_66){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_177;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_66, sizeof(Cursor_0_nifb6mq6y1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_177 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_177 = ((NI32)2147483647);}
  return result_177;}
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_23;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_33, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_23 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_23 = ((NI32)2147483647);}
  return result_23;}
static inline NI32 capInBytes_0_I0ia6g61_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_231){
  NI32 result_156;
  NI32 X60Qx_32;
  if ((!(s_231.data_0 == NIM_NIL))){
    NI32 X60Qx_1944 = allocatedSize_0_sysvq0asl(((void*)((void*)s_231.data_0)));
    X60Qx_32 = X60Qx_1944;}
  else {
    X60Qx_32 = 0;}
  result_156 = X60Qx_32;
  return result_156;}
static inline NI32 capInBytes_0_Iet286n_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_72){
  NI32 result_22;
  NI32 X60Qx_2;
  if ((!(s_72.data_0 == NIM_NIL))){
    NI32 X60Qx_90 = allocatedSize_0_sysvq0asl(((void*)((void*)s_72.data_0)));
    X60Qx_2 = X60Qx_90;}
  else {
    X60Qx_2 = 0;}
  result_22 = X60Qx_2;
  return result_22;}
static inline NI32 memSizeInBytes_0_Ivqzo5x1_ast8ri79k(NI32 size_33){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_52;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_33, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_52 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_52 = ((NI32)2147483647);}
  return result_52;}
static inline NI32 capInBytes_0_Iev6wua1_ast8ri79k(seq_0_In6doa_ast8ri79k s_73){
  NI32 result_51;
  NI32 X60Qx_7;
  if ((!(s_73.data_0 == NIM_NIL))){
    NI32 X60Qx_134 = allocatedSize_0_sysvq0asl(((void*)((void*)s_73.data_0)));
    X60Qx_7 = X60Qx_134;}
  else {
    X60Qx_7 = 0;}
  result_51 = X60Qx_7;
  return result_51;}
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
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NI64* result_10;
  result_10 = (&s_9.data_0[i_6]);
  return result_10;}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
