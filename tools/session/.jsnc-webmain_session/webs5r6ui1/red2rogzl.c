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
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct RedeclSet_0_red2rogzl{
  seq_0_Ixdx2fh1_aow7lb5cq1 typeDecls_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 procDecls_0;
  seq_0_In6doa_arecyyj7v seenTypes_0;
  seq_0_In6doa_arecyyj7v activeTypes_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 usedNames_0;
  NB8 sawImportc_0;}
RedeclSet_0_red2rogzl;
typedef struct openArray_0_Ir53qdx_intzsnzax{
  NU32* a_0;
  NI32 len_0;}
openArray_0_Ir53qdx_intzsnzax;
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
typedef struct TypeDecl_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 typevars_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 body_0;}
TypeDecl_0_decqocs071;
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
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef NU8 SkipMode_0_decqocs071;

#define SkipExclBody_0_decqocs071 ((NU8)0)
#define SkipInclBody_0_decqocs071 ((NU8)1)
#define SkipFinalParRi_0_decqocs071 ((NU8)2)
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
NB8 addTypeRedecl_1_red2rogzl(NU32 sym_1, RedeclSet_0_red2rogzl* rs_2, NI32 depth_2);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13);
static inline string_0_sysvq0asl* getQ_0_I93d71y_der823rwr1(BiTable_0_Icvz6lt_buiyylk1h1 t_5, NU32 litId_1);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern void extractBasename_1_symkyk35i1(string_0_sysvq0asl* s_1);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I11643015150811461308_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I11024699549390617459_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I3703322799828345117_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I18357185398770638485_aow7lb5cq1;
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10);
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern LongString_0_sysvq0asl const strlit_0_I7023501325319911082_emi78vuj01;
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
extern LongString_0_sysvq0asl const strlit_0_I2341417231474813780_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I4859700805551129371_nimry5ra91;
extern LongString_0_sysvq0asl const strlit_0_I3557287941175077387_nimry5ra91;
extern LongString_0_sysvq0asl const strlit_0_I17844812131497141662_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I3957309170640276402_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I17285089853291426062_nimry5ra91;
extern LongString_0_sysvq0asl const strlit_0_I9354196862430236195_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I3302612697625453930_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I14150474136931533575_emi78vuj01;
static inline NU32 litId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_7);
static inline string_0_sysvq0asl* getQ_0_Iplpzal1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k t_6, NU32 litId_5);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
extern LongString_0_sysvq0asl const strlit_0_I1177603226064417776_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I14727864736786204059_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I16393544569146403439_intzsnzax;
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
static inline openArray_0_Ir53qdx_intzsnzax toOpenArray_1_I02c2wz_intzsnzax(seq_0_In6doa_arecyyj7v s_164);
static inline NI32 len_6_Ijqv54i_intzsnzax(openArray_0_Ir53qdx_intzsnzax a_72);
static inline NU32* getQ_10_Ibernwj1_intzsnzax(openArray_0_Ir53qdx_intzsnzax x_28, NI32 idx_48);
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_43);
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_30);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7);
extern LoadResult_0_prorcx25w1 tryLoadSymSafe_0_modzy18mg1(NU32 s_0);
extern LongString_0_sysvq0asl const strlit_0_I13413619771642637377_emi78vuj01;
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
extern TypeDecl_0_decqocs071 asTypeDecl_0_decqocs071(Cursor_0_nifb6mq6y1 c_10);
extern void eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071(TypeDecl_0_decqocs071* dest_0);
static inline void add_0_I34il1q_der823rwr1(seq_0_In6doa_arecyyj7v* s_12, NU32 elem_2);
extern LongString_0_sysvq0asl const strlit_0_I973692718279674627_emi78vuj01;
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37);
extern void setLen_0_Ihfm18w_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_33, NI32 newLen_8);
extern Routine_0_decqocs071 asRoutine_0_decqocs071(Cursor_0_nifb6mq6y1 c_8, SkipMode_0_decqocs071 mode_3);
extern void eQdestroyQ_SX52outine0decqocs071_0_decqocs071(Routine_0_decqocs071* dest_0);
extern LongString_0_sysvq0asl const strlit_0_I5367917178860180580_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I9792473688321036479_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I5595596763809202512_nim30udrv;
extern void eQdestroy_1_Iscb4i31_arecyyj7v(seq_0_In6doa_arecyyj7v s_81);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_modzy18mg1(void);
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
extern void X60Qini_0_tagygirdh1(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline NU32 litId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_9);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline NU32* rawData_0_I9ky6gs1_intzsnzax(seq_0_In6doa_arecyyj7v s_290);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67);
static inline NI32 capInBytes_0_Iev6wua1_arecyyj7v(seq_0_In6doa_arecyyj7v s_89);
extern NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_arecyyj7v* dest_8, NI32 addedElements_8);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
LongString_0_sysvq0asl const strlit_0_I589554620119875380_red2rogzl = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "float32"}
;
LongString_0_sysvq0asl const strlit_0_I15741960979639035523_red2rogzl = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "float64"}
;
LongString_0_sysvq0asl const strlit_0_I17145195551207940444_red2rogzl = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "byte"}
;
LongString_0_sysvq0asl const strlit_0_I17450945768583924279_red2rogzl = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "int16"}
;
LongString_0_sysvq0asl const strlit_0_I6136553206224205495_red2rogzl = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "int32"}
;
LongString_0_sysvq0asl const strlit_0_I17873677997389965638_red2rogzl = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "int8"}
;
LongString_0_sysvq0asl const strlit_0_I12353965517161629078_red2rogzl = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "int64"}
;
LongString_0_sysvq0asl const strlit_0_I1184649450617298588_red2rogzl = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "uint16"}
;
LongString_0_sysvq0asl const strlit_0_I13604536769712135534_red2rogzl = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "uint32"}
;
LongString_0_sysvq0asl const strlit_0_I7032352044772062024_red2rogzl = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "uint8"}
;
LongString_0_sysvq0asl const strlit_0_I18004982030542443876_red2rogzl = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "uint64"}
;
LongString_0_sysvq0asl const strlit_0_I3375509943470633651_red2rogzl = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "incompletestruct"}
;
LongString_0_sysvq0asl const strlit_0_I17240049634294106551_red2rogzl = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "importc: \""}
;
LongString_0_sysvq0asl const strlit_0_I4197161763800528367_red2rogzl = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "header: \""}
;
LongString_0_sysvq0asl const strlit_0_I8143666813629710679_red2rogzl = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ptr "}
;
LongString_0_sysvq0asl const strlit_0_I16157109470490228308_red2rogzl = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "array["}
;
LongString_0_sysvq0asl const strlit_0_I16837745836829406171_red2rogzl = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " .. "}
;
LongString_0_sysvq0asl const strlit_0_I3342234748333824056_red2rogzl = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "type "}
;
LongString_0_sysvq0asl const strlit_0_I11348611436872997213_red2rogzl = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = object\012"}
;
LongString_0_sysvq0asl const strlit_0_I15249506995356931180_red2rogzl = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "proc "}
;
NB8 X60QiniGuard_0_red2rogzl;
string_0_sysvq0asl nodeTag_0_red2rogzl(Cursor_0_nifb6mq6y1 n_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  nimStrDestroy(result_0);
  NU32 X60Qx_22 = tagId_0_nifb6mq6y1(n_0);
  string_0_sysvq0asl* X60Qx_23 = getQ_0_I93d71y_der823rwr1(pool_0_nifh7u8pu1.tags_0, X60Qx_22);
  string_0_sysvq0asl X60Qx_24 = nimStrDup((*X60Qx_23));
  result_0 = X60Qx_24;
  return result_0;}
string_0_sysvq0asl baseNameOf_0_red2rogzl(NU32 s_0){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  nimStrDestroy(result_1);
  string_0_sysvq0asl* X60Qx_25 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_0);
  string_0_sysvq0asl X60Qx_26 = nimStrDup((*X60Qx_25));
  result_1 = X60Qx_26;
  extractBasename_1_symkyk35i1((&result_1));
  return result_1;}
NB8 isBuiltinScalarName_0_red2rogzl(string_0_sysvq0asl n_1){
  NB8 result_2;
  NB8 X60Qx_0;
  NB8 X60Qtc_1 = nimStrAtLe_0_sysvq0asl(n_1, 3, (NC8)'e');
  if (X60Qtc_1){
    NB8 X60Qtc_2 = nimStrAtLe_0_sysvq0asl(n_1, 0, (NC8)'f');
    if (X60Qtc_2){
      NB8 X60Qtc_3 = nimStrAtLe_0_sysvq0asl(n_1, 5, (NC8)'6');
      if (X60Qtc_3){
        if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I589554620119875380_red2rogzl)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I15741960979639035523_red2rogzl)}
        )){
          goto X60Qsc_0;}}
      else {
        if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I11643015150811461308_aow7lb5cq1)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1954112254u, .more_0 = (&strlit_0_I17145195551207940444_red2rogzl)}
        )){
          goto X60Qsc_0;}}}
    else {
      NB8 X60Qtc_4 = nimStrAtLe_0_sysvq0asl(n_1, 3, (NC8)'3');
      if (X60Qtc_4){
        if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I17450945768583924279_red2rogzl)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I6136553206224205495_red2rogzl)}
        )){
          goto X60Qsc_0;}}
      else {
        if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I17873677997389965638_red2rogzl)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I12353965517161629078_red2rogzl)}
        )){
          goto X60Qsc_0;}}}}
  else {
    NB8 X60Qtc_5 = nimStrAtLe_0_sysvq0asl(n_1, 4, (NC8)'8');
    if (X60Qtc_5){
      NB8 X60Qtc_6 = nimStrAtLe_0_sysvq0asl(n_1, 4, (NC8)'3');
      if (X60Qtc_6){
        if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I1184649450617298588_red2rogzl)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I13604536769712135534_red2rogzl)}
        )){
          goto X60Qsc_0;}}
      else {
        if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I7032352044772062024_red2rogzl)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I18004982030542443876_red2rogzl)}
        )){
          goto X60Qsc_0;}}}
    else {
      NB8 X60Qtc_7 = nimStrAtLe_0_sysvq0asl(n_1, 0, (NC8)'c');
      if (X60Qtc_7){
        if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1634231294u, .more_0 = (&strlit_0_I3703322799828345117_aow7lb5cq1)}
        )){
          goto X60Qsc_0;}}
      else {
        if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1953392899u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(n_1, (string_0_sysvq0asl){
          .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I18357185398770638485_aow7lb5cq1)}
        )){
          goto X60Qsc_0;}}}}
  goto X60Qsc_9;
  X60Qsc_0: ;
  X60Qx_0 = NIM_TRUE;
  goto X60Qsc_8;
  X60Qsc_9: ;
  X60Qx_0 = NIM_FALSE;
  X60Qsc_8: ;
  result_2 = X60Qx_0;
  return result_2;}
NI32 litInt_0_red2rogzl(Cursor_0_nifb6mq6y1 c_0){
  NI32 result_3;
  NI32 X60Qx_1;
  NifKind_0_nif81dubp1 X60Qx_27 = kind_0_nifb6mq6y1(c_0);
  if (X60Qx_27 == 8){
    NU32 X60Qx_28 = intId_0_nifb6mq6y1(c_0);
    NI64* X60Qx_29 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_28);
    X60Qx_1 = ((NI32)(*X60Qx_29));}
  else {
    X60Qx_1 = 0;}
  result_3 = X60Qx_1;
  return result_3;}
string_0_sysvq0asl intWidthName_0_red2rogzl(string_0_sysvq0asl tg_0, NI32 bits_0){
  string_0_sysvq0asl result_4;
  nimStrWasMoved((&result_4));
  string_0_sysvq0asl X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  NB8 X60Qtc_13 = nimStrAtLe_0_sysvq0asl(tg_0, 0, (NC8)'i');
  if (X60Qtc_13){
    if (equalStrings_0_sysvq0asl(tg_0, (string_0_sysvq0asl){
      .bytes_0 = 26881u, .more_0 = NIM_NIL}
    )){
      goto X60Qsc_10;}
    else if (equalStrings_0_sysvq0asl(tg_0, (string_0_sysvq0asl){
      .bytes_0 = 26113u, .more_0 = NIM_NIL}
    )){
      goto X60Qsc_12;}}
  else {
    if (equalStrings_0_sysvq0asl(tg_0, (string_0_sysvq0asl){
      .bytes_0 = 29953u, .more_0 = NIM_NIL}
    )){
      goto X60Qsc_11;}}
  goto X60Qsc_15;
  X60Qsc_10: ;
  string_0_sysvq0asl X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  if (bits_0 <= 0){
    nimStrDestroy(X60Qx_3);
    X60Qx_3 = (string_0_sysvq0asl){
      .bytes_0 = 1953392899u, .more_0 = NIM_NIL}
    ;}
  else {
    nimStrDestroy(X60Qx_3);
    string_0_sysvq0asl X60Qtmp_0 = dollarQ_2_sysvq0asl(bits_0);
    string_0_sysvq0asl X60Qx_30 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953392899u, .more_0 = NIM_NIL}
    , X60Qtmp_0);
    X60Qx_3 = X60Qx_30;
    nimStrDestroy(X60Qtmp_0);}
  nimStrDestroy(X60Qx_2);
  X60Qx_2 = X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  nimStrDestroy(X60Qx_3);
  goto X60Qsc_14;
  X60Qsc_11: ;
  string_0_sysvq0asl X60Qx_4;
  nimStrWasMoved((&X60Qx_4));
  if (bits_0 <= 0){
    nimStrDestroy(X60Qx_4);
    X60Qx_4 = (string_0_sysvq0asl){
      .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I18357185398770638485_aow7lb5cq1)}
    ;}
  else {
    nimStrDestroy(X60Qx_4);
    string_0_sysvq0asl X60Qtmp_1 = dollarQ_2_sysvq0asl(bits_0);
    string_0_sysvq0asl X60Qx_31 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I18357185398770638485_aow7lb5cq1)}
    , X60Qtmp_1);
    X60Qx_4 = X60Qx_31;
    nimStrDestroy(X60Qtmp_1);}
  nimStrDestroy(X60Qx_2);
  X60Qx_2 = X60Qx_4;
  nimStrWasMoved((&X60Qx_4));
  nimStrDestroy(X60Qx_4);
  goto X60Qsc_14;
  X60Qsc_12: ;
  string_0_sysvq0asl X60Qx_5;
  nimStrWasMoved((&X60Qx_5));
  if (bits_0 <= 0){
    nimStrDestroy(X60Qx_5);
    X60Qx_5 = (string_0_sysvq0asl){
      .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I11643015150811461308_aow7lb5cq1)}
    ;}
  else {
    nimStrDestroy(X60Qx_5);
    string_0_sysvq0asl X60Qtmp_2 = dollarQ_2_sysvq0asl(bits_0);
    string_0_sysvq0asl X60Qx_32 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I11643015150811461308_aow7lb5cq1)}
    , X60Qtmp_2);
    X60Qx_5 = X60Qx_32;
    nimStrDestroy(X60Qtmp_2);}
  nimStrDestroy(X60Qx_2);
  X60Qx_2 = X60Qx_5;
  nimStrWasMoved((&X60Qx_5));
  nimStrDestroy(X60Qx_5);
  goto X60Qsc_14;
  X60Qsc_15: ;
  nimStrDestroy(X60Qx_2);
  X60Qx_2 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  X60Qsc_14: ;
  nimStrDestroy(result_4);
  result_4 = X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  nimStrDestroy(X60Qx_2);
  return result_4;
  nimStrDestroy(X60Qx_2);
  return result_4;}
string_0_sysvq0asl spellPragmas_0_red2rogzl(Cursor_0_nifb6mq6y1 pragmas_0, NB8* ok_0, NB8* sawImportc_0){
  string_0_sysvq0asl result_5;
  nimStrWasMoved((&result_5));
  nimStrDestroy(result_5);
  result_5 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NifKind_0_nif81dubp1 X60Qx_33 = kind_0_nifb6mq6y1(pragmas_0);
  if (X60Qx_33 == 2){
    return result_5;}
  NB8 X60Qx_15;
  NifKind_0_nif81dubp1 X60Qx_34 = kind_0_nifb6mq6y1(pragmas_0);
  if ((!(X60Qx_34 == 11))){
    X60Qx_15 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_3 = nodeTag_0_red2rogzl(pragmas_0);
    NB8 X60Qx_35 = eqQ_20_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
      .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
    );
    X60Qx_15 = (!X60Qx_35);
    nimStrDestroy(X60Qtmp_3);}
  if (X60Qx_15){
    (*ok_0) = NIM_FALSE;
    return result_5;}
  seq_0_Ixdx2fh1_aow7lb5cq1 parts_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  Cursor_0_nifb6mq6y1 c_2 = eQdup_0_nifb6mq6y1(pragmas_0);
  inc_0_nifb6mq6y1((&c_2));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_36 = kind_0_nifb6mq6y1(c_2);
      if ((!(X60Qx_36 == 12))){
        NifKind_0_nif81dubp1 X60Qx_37 = kind_0_nifb6mq6y1(c_2);
        if (X60Qx_37 == 11){
          string_0_sysvq0asl tg_1 = nodeTag_0_red2rogzl(c_2);
          Cursor_0_nifb6mq6y1 arg_0 = eQdup_0_nifb6mq6y1(c_2);
          inc_0_nifb6mq6y1((&arg_0));
          NB8 X60Qtc_25 = nimStrAtLe_0_sysvq0asl(tg_1, 2, (NC8)'c');
          if (X60Qtc_25){
            NB8 X60Qtc_26 = nimStrAtLe_0_sysvq0asl(tg_1, 0, (NC8)'h');
            if (X60Qtc_26){
              if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}
              )){
                goto X60Qsc_17;}
              else if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                .bytes_0 = 1668899582u, .more_0 = (&strlit_0_I4859700805551129371_nimry5ra91)}
              )){
                goto X60Qsc_21;}}
            else {
              NB8 X60Qtc_27 = nimStrAtLe_0_sysvq0asl(tg_1, 0, (NC8)'i');
              if (X60Qtc_27){
                if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                  .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I3375509943470633651_red2rogzl)}
                )){
                  goto X60Qsc_23;}
                else if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                  .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I3557287941175077387_nimry5ra91)}
                )){
                  goto X60Qsc_23;}}
              else {
                if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                  .bytes_0 = 1667330302u, .more_0 = (&strlit_0_I17844812131497141662_emi78vuj01)}
                )){
                  goto X60Qsc_19;}}}}
          else {
            NB8 X60Qtc_28 = nimStrAtLe_0_sysvq0asl(tg_1, 0, (NC8)'i');
            if (X60Qtc_28){
              if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
              )){
                goto X60Qsc_16;}
              else if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                .bytes_0 = 1920557822u, .more_0 = (&strlit_0_I17285089853291426062_nimry5ra91)}
              )){
                goto X60Qsc_22;}}
            else {
              NB8 X60Qtc_29 = nimStrAtLe_0_sysvq0asl(tg_1, 0, (NC8)'n');
              if (X60Qtc_29){
                if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                  .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}
                )){
                  goto X60Qsc_18;}}
              else {
                if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                  .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I3302612697625453930_emi78vuj01)}
                )){
                  goto X60Qsc_20;}
                else if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
                  .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I14150474136931533575_emi78vuj01)}
                )){
                  goto X60Qsc_24;}}}}
          goto X60Qsc_31;
          X60Qsc_16: ;
          (*sawImportc_0) = NIM_TRUE;
          NifKind_0_nif81dubp1 X60Qx_38 = kind_0_nifb6mq6y1(arg_0);
          if (X60Qx_38 == 6){
            NU32 X60Qx_39 = litId_0_nifb6mq6y1(arg_0);
            string_0_sysvq0asl* X60Qx_40 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_39);
            string_0_sysvq0asl X60Qdesugar_0 = nimStrDup((*X60Qx_40));
            NI32 X60Qx_41 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I17240049634294106551_red2rogzl)}
            );
            NI32 X60Qx_42 = len_4_sysvq0asl(X60Qdesugar_0);
            NI32 X60Qx_43 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8705u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_41 + X60Qx_42)) + X60Qx_43)));
            add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
              .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I17240049634294106551_red2rogzl)}
            );
            add_2_sysvq0asl((&X60Qdesugar_1), X60Qdesugar_0);
            add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
              .bytes_0 = 8705u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qtmp_4 = X60Qdesugar_1;
            nimStrWasMoved((&X60Qdesugar_1));
            add_0_Ig6072n_aow7lb5cq1((&parts_0), X60Qtmp_4);
            nimStrDestroy(X60Qdesugar_1);
            nimStrDestroy(X60Qdesugar_0);}
          else {
            add_0_Ig6072n_aow7lb5cq1((&parts_0), (string_0_sysvq0asl){
              .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
            );}
          goto X60Qsc_30;
          X60Qsc_17: ;
          NifKind_0_nif81dubp1 X60Qx_44 = kind_0_nifb6mq6y1(arg_0);
          if (X60Qx_44 == 6){
            NU32 X60Qx_45 = litId_0_nifb6mq6y1(arg_0);
            string_0_sysvq0asl* X60Qx_46 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_45);
            string_0_sysvq0asl X60Qdesugar_2 = nimStrDup((*X60Qx_46));
            NI32 X60Qx_47 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I4197161763800528367_red2rogzl)}
            );
            NI32 X60Qx_48 = len_4_sysvq0asl(X60Qdesugar_2);
            NI32 X60Qx_49 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8705u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_3 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_47 + X60Qx_48)) + X60Qx_49)));
            add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
              .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I4197161763800528367_red2rogzl)}
            );
            add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_2);
            add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
              .bytes_0 = 8705u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qtmp_5 = X60Qdesugar_3;
            nimStrWasMoved((&X60Qdesugar_3));
            add_0_Ig6072n_aow7lb5cq1((&parts_0), X60Qtmp_5);
            nimStrDestroy(X60Qdesugar_3);
            nimStrDestroy(X60Qdesugar_2);}
          else {
            (*ok_0) = NIM_FALSE;}
          goto X60Qsc_30;
          X60Qsc_18: ;
          add_0_Ig6072n_aow7lb5cq1((&parts_0), (string_0_sysvq0asl){
            .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}
          );
          goto X60Qsc_30;
          X60Qsc_19: ;
          add_0_Ig6072n_aow7lb5cq1((&parts_0), (string_0_sysvq0asl){
            .bytes_0 = 1667330302u, .more_0 = (&strlit_0_I17844812131497141662_emi78vuj01)}
          );
          goto X60Qsc_30;
          X60Qsc_20: ;
          add_0_Ig6072n_aow7lb5cq1((&parts_0), (string_0_sysvq0asl){
            .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I3302612697625453930_emi78vuj01)}
          );
          goto X60Qsc_30;
          X60Qsc_21: ;
          add_0_Ig6072n_aow7lb5cq1((&parts_0), (string_0_sysvq0asl){
            .bytes_0 = 1668899582u, .more_0 = (&strlit_0_I4859700805551129371_nimry5ra91)}
          );
          goto X60Qsc_30;
          X60Qsc_22: ;
          add_0_Ig6072n_aow7lb5cq1((&parts_0), (string_0_sysvq0asl){
            .bytes_0 = 1920557822u, .more_0 = (&strlit_0_I17285089853291426062_nimry5ra91)}
          );
          goto X60Qsc_30;
          X60Qsc_23: ;
          add_0_Ig6072n_aow7lb5cq1((&parts_0), (string_0_sysvq0asl){
            .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I3557287941175077387_nimry5ra91)}
          );
          goto X60Qsc_30;
          X60Qsc_24: ;
          (*ok_0) = NIM_FALSE;
          goto X60Qsc_30;
          X60Qsc_31: ;
          (*ok_0) = NIM_FALSE;
          X60Qsc_30: ;
          eQdestroy_0_nifb6mq6y1((&arg_0));
          nimStrDestroy(tg_1);}
        else {
          NifKind_0_nif81dubp1 X60Qx_50 = kind_0_nifb6mq6y1(c_2);
          if (X60Qx_50 == 3){
            (*ok_0) = NIM_FALSE;}}
        skip_0_nifb6mq6y1((&c_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_51 = len_3_Ixq6taz_aow7lb5cq1(parts_0);
  if (X60Qx_51 == 0){
    eQdestroy_0_nifb6mq6y1((&c_2));
    eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_0);
    return result_5;}
  nimStrDestroy(result_5);
  result_5 = (string_0_sysvq0asl){
    .bytes_0 = 779821059u, .more_0 = NIM_NIL}
  ;
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_52 = len_3_Ixq6taz_aow7lb5cq1(parts_0);
      if (i_0 < X60Qx_52){
        if (0 < i_0){
          add_2_sysvq0asl((&result_5), (string_0_sysvq0asl){
            .bytes_0 = 2108418u, .more_0 = NIM_NIL}
          );}
        string_0_sysvq0asl* X60Qx_53 = getQ_7_Ir6d0tw_aow7lb5cq1(parts_0, i_0);
        add_2_sysvq0asl((&result_5), (*X60Qx_53));
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  add_2_sysvq0asl((&result_5), (string_0_sysvq0asl){
    .bytes_0 = 8203778u, .more_0 = NIM_NIL}
  );
  eQdestroy_0_nifb6mq6y1((&c_2));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_0);
  return result_5;
  eQdestroy_0_nifb6mq6y1((&c_2));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_0);
  return result_5;}
string_0_sysvq0asl spellTypeExpr_0_red2rogzl(Cursor_0_nifb6mq6y1 c_1, RedeclSet_0_red2rogzl* rs_1, NI32 depth_1){
  string_0_sysvq0asl result_6;
  nimStrWasMoved((&result_6));
  if (24 < depth_1){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NifKind_0_nif81dubp1 X60Qx_54 = kind_0_nifb6mq6y1(c_1);
  if (X60Qx_54 == 4){
    NU32 X60Qx_55 = symId_0_nifb6mq6y1(c_1);
    string_0_sysvq0asl bn_0 = baseNameOf_0_red2rogzl(X60Qx_55);
    NB8 X60Qx_56 = isBuiltinScalarName_0_red2rogzl(bn_0);
    if (X60Qx_56){
      string_0_sysvq0asl X60Qtmp_6 = bn_0;
      nimStrWasMoved((&bn_0));
      nimStrDestroy(bn_0);
      return X60Qtmp_6;}
    NU32 X60Qx_57 = symId_0_nifb6mq6y1(c_1);
    NB8 X60Qx_58 = addTypeRedecl_1_red2rogzl(X60Qx_57, rs_1, ((NI32)(depth_1 + 1)));
    if ((!X60Qx_58)){
      nimStrDestroy(bn_0);
      return (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qtmp_7 = bn_0;
    nimStrWasMoved((&bn_0));
    nimStrDestroy(bn_0);
    return X60Qtmp_7;
    nimStrDestroy(bn_0);}
  NifKind_0_nif81dubp1 X60Qx_59 = kind_0_nifb6mq6y1(c_1);
  if ((!(X60Qx_59 == 11))){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl tg_2 = nodeTag_0_red2rogzl(c_1);
  NB8 X60Qtc_38 = nimStrAtLe_0_sysvq0asl(tg_2, 0, (NC8)'c');
  if (X60Qtc_38){
    NB8 X60Qtc_39 = nimStrAtLe_0_sysvq0asl(tg_2, 0, (NC8)'b');
    if (X60Qtc_39){
      if (equalStrings_0_sysvq0asl(tg_2, (string_0_sysvq0asl){
        .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
      )){
        goto X60Qsc_33;}
      else if (equalStrings_0_sysvq0asl(tg_2, (string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
      )){
        goto X60Qsc_37;}}
    else {
      if (equalStrings_0_sysvq0asl(tg_2, (string_0_sysvq0asl){
        .bytes_0 = 25345u, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_34;}
      else if (equalStrings_0_sysvq0asl(tg_2, (string_0_sysvq0asl){
        .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
      )){
        goto X60Qsc_35;}}}
  else {
    NB8 X60Qtc_40 = nimStrAtLe_0_sysvq0asl(tg_2, 0, (NC8)'i');
    if (X60Qtc_40){
      if (equalStrings_0_sysvq0asl(tg_2, (string_0_sysvq0asl){
        .bytes_0 = 26881u, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_32;}
      else if (equalStrings_0_sysvq0asl(tg_2, (string_0_sysvq0asl){
        .bytes_0 = 26113u, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_32;}}
    else {
      if (equalStrings_0_sysvq0asl(tg_2, (string_0_sysvq0asl){
        .bytes_0 = 29953u, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_32;}
      else if (equalStrings_0_sysvq0asl(tg_2, (string_0_sysvq0asl){
        .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_36;}}}
  goto X60Qsc_42;
  X60Qsc_32: ;
  Cursor_0_nifb6mq6y1 w_0 = eQdup_0_nifb6mq6y1(c_1);
  inc_0_nifb6mq6y1((&w_0));
  NI32 X60Qx_6;
  NifKind_0_nif81dubp1 X60Qx_60 = kind_0_nifb6mq6y1(w_0);
  if (X60Qx_60 == 8){
    NI32 X60Qx_61 = litInt_0_red2rogzl(w_0);
    X60Qx_6 = X60Qx_61;}
  else {
    X60Qx_6 = -1;}
  string_0_sysvq0asl X60Qx_62 = intWidthName_0_red2rogzl(tg_2, X60Qx_6);
  result_6 = X60Qx_62;
  eQdestroy_0_nifb6mq6y1((&w_0));
  nimStrDestroy(tg_2);
  return result_6;
  eQdestroy_0_nifb6mq6y1((&w_0));
  goto X60Qsc_41;
  X60Qsc_33: ;
  nimStrDestroy(tg_2);
  return (string_0_sysvq0asl){
    .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
  ;
  goto X60Qsc_41;
  X60Qsc_34: ;
  Cursor_0_nifb6mq6y1 w_1 = eQdup_0_nifb6mq6y1(c_1);
  inc_0_nifb6mq6y1((&w_1));
  NI32 X60Qx_7;
  NifKind_0_nif81dubp1 X60Qx_63 = kind_0_nifb6mq6y1(w_1);
  if (X60Qx_63 == 8){
    NI32 X60Qx_64 = litInt_0_red2rogzl(w_1);
    X60Qx_7 = X60Qx_64;}
  else {
    X60Qx_7 = 8;}
  NI32 bits_1 = X60Qx_7;
  string_0_sysvq0asl X60Qx_8;
  nimStrWasMoved((&X60Qx_8));
  if (bits_1 <= 8){
    nimStrDestroy(X60Qx_8);
    X60Qx_8 = (string_0_sysvq0asl){
      .bytes_0 = 1634231294u, .more_0 = (&strlit_0_I3703322799828345117_aow7lb5cq1)}
    ;}
  else {
    nimStrDestroy(X60Qx_8);
    X60Qx_8 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl X60Qtmp_8 = X60Qx_8;
  nimStrWasMoved((&X60Qx_8));
  nimStrDestroy(X60Qx_8);
  eQdestroy_0_nifb6mq6y1((&w_1));
  nimStrDestroy(tg_2);
  return X60Qtmp_8;
  nimStrDestroy(X60Qx_8);
  eQdestroy_0_nifb6mq6y1((&w_1));
  goto X60Qsc_41;
  X60Qsc_35: ;
  nimStrDestroy(tg_2);
  return (string_0_sysvq0asl){
    .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
  ;
  goto X60Qsc_41;
  X60Qsc_36: ;
  Cursor_0_nifb6mq6y1 e_0 = eQdup_0_nifb6mq6y1(c_1);
  inc_0_nifb6mq6y1((&e_0));
  string_0_sysvq0asl inner_0 = spellTypeExpr_0_red2rogzl(e_0, rs_1, ((NI32)(depth_1 + 1)));
  NI32 X60Qx_65 = len_4_sysvq0asl(inner_0);
  if (X60Qx_65 == 0){
    nimStrDestroy(inner_0);
    eQdestroy_0_nifb6mq6y1((&e_0));
    nimStrDestroy(tg_2);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl X60Qx_66 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1920233726u, .more_0 = (&strlit_0_I8143666813629710679_red2rogzl)}
  , inner_0);
  result_6 = X60Qx_66;
  nimStrDestroy(inner_0);
  eQdestroy_0_nifb6mq6y1((&e_0));
  nimStrDestroy(tg_2);
  return result_6;
  nimStrDestroy(inner_0);
  eQdestroy_0_nifb6mq6y1((&e_0));
  goto X60Qsc_41;
  X60Qsc_37: ;
  Cursor_0_nifb6mq6y1 e_1 = eQdup_0_nifb6mq6y1(c_1);
  inc_0_nifb6mq6y1((&e_1));
  string_0_sysvq0asl elem_1 = spellTypeExpr_0_red2rogzl(e_1, rs_1, ((NI32)(depth_1 + 1)));
  NI32 X60Qx_67 = len_4_sysvq0asl(elem_1);
  if (X60Qx_67 == 0){
    nimStrDestroy(elem_1);
    eQdestroy_0_nifb6mq6y1((&e_1));
    nimStrDestroy(tg_2);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  skip_0_nifb6mq6y1((&e_1));
  NB8 X60Qx_16;
  NifKind_0_nif81dubp1 X60Qx_68 = kind_0_nifb6mq6y1(e_1);
  if ((!(X60Qx_68 == 11))){
    X60Qx_16 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_9 = nodeTag_0_red2rogzl(e_1);
    NB8 X60Qx_69 = eqQ_20_sysvq0asl(X60Qtmp_9, (string_0_sysvq0asl){
      .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16393544569146403439_intzsnzax)}
    );
    X60Qx_16 = (!X60Qx_69);
    nimStrDestroy(X60Qtmp_9);}
  if (X60Qx_16){
    nimStrDestroy(elem_1);
    eQdestroy_0_nifb6mq6y1((&e_1));
    nimStrDestroy(tg_2);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  Cursor_0_nifb6mq6y1 r_0 = e_1;
  eQwasMoved_0_nifb6mq6y1((&e_1));
  inc_0_nifb6mq6y1((&r_0));
  skip_0_nifb6mq6y1((&r_0));
  NifKind_0_nif81dubp1 X60Qx_70 = kind_0_nifb6mq6y1(r_0);
  if ((!(X60Qx_70 == 8))){
    eQdestroy_0_nifb6mq6y1((&r_0));
    nimStrDestroy(elem_1);
    eQdestroy_0_nifb6mq6y1((&e_1));
    nimStrDestroy(tg_2);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 lo_0 = litInt_0_red2rogzl(r_0);
  skip_0_nifb6mq6y1((&r_0));
  NifKind_0_nif81dubp1 X60Qx_71 = kind_0_nifb6mq6y1(r_0);
  if ((!(X60Qx_71 == 8))){
    eQdestroy_0_nifb6mq6y1((&r_0));
    nimStrDestroy(elem_1);
    eQdestroy_0_nifb6mq6y1((&e_1));
    nimStrDestroy(tg_2);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 hi_0 = litInt_0_red2rogzl(r_0);
  if (hi_0 < lo_0){
    eQdestroy_0_nifb6mq6y1((&r_0));
    nimStrDestroy(elem_1);
    eQdestroy_0_nifb6mq6y1((&e_1));
    nimStrDestroy(tg_2);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl X60Qdesugar_4 = dollarQ_2_sysvq0asl(lo_0);
  string_0_sysvq0asl X60Qdesugar_5 = dollarQ_2_sysvq0asl(hi_0);
  NI32 X60Qx_72 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I16157109470490228308_red2rogzl)}
  );
  NI32 X60Qx_73 = len_4_sysvq0asl(X60Qdesugar_4);
  NI32 X60Qx_74 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 774775038u, .more_0 = (&strlit_0_I16837745836829406171_red2rogzl)}
  );
  NI32 X60Qx_75 = len_4_sysvq0asl(X60Qdesugar_5);
  NI32 X60Qx_76 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_77 = len_4_sysvq0asl(elem_1);
  NI32 X60Qx_78 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 23809u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_6 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_72 + X60Qx_73)) + X60Qx_74)) + X60Qx_75)) + X60Qx_76)) + X60Qx_77)) + X60Qx_78)));
  add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
    .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I16157109470490228308_red2rogzl)}
  );
  add_2_sysvq0asl((&X60Qdesugar_6), X60Qdesugar_4);
  add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
    .bytes_0 = 774775038u, .more_0 = (&strlit_0_I16837745836829406171_red2rogzl)}
  );
  add_2_sysvq0asl((&X60Qdesugar_6), X60Qdesugar_5);
  add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_6), elem_1);
  add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
    .bytes_0 = 23809u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qtmp_10 = X60Qdesugar_6;
  nimStrWasMoved((&X60Qdesugar_6));
  nimStrDestroy(X60Qdesugar_6);
  nimStrDestroy(X60Qdesugar_5);
  nimStrDestroy(X60Qdesugar_4);
  eQdestroy_0_nifb6mq6y1((&r_0));
  nimStrDestroy(elem_1);
  eQdestroy_0_nifb6mq6y1((&e_1));
  nimStrDestroy(tg_2);
  return X60Qtmp_10;
  nimStrDestroy(X60Qdesugar_6);
  nimStrDestroy(X60Qdesugar_5);
  nimStrDestroy(X60Qdesugar_4);
  eQdestroy_0_nifb6mq6y1((&r_0));
  nimStrDestroy(elem_1);
  eQdestroy_0_nifb6mq6y1((&e_1));
  goto X60Qsc_41;
  X60Qsc_42: ;
  nimStrDestroy(tg_2);
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  X60Qsc_41: ;
  nimStrDestroy(tg_2);
  return result_6;
  nimStrDestroy(tg_2);
  return result_6;}
NB8 addTypeRedecl_1_red2rogzl(NU32 sym_1, RedeclSet_0_red2rogzl* rs_2, NI32 depth_2){
  NB8 result_7;
  if (((NU32)sym_1) == ((NU32)0u)){
    return NIM_FALSE;}
  {
    openArray_0_Ir53qdx_intzsnzax X60Qlf_0 = toOpenArray_1_I02c2wz_intzsnzax((*rs_2).seenTypes_0);
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_79 = len_6_Ijqv54i_intzsnzax(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_79){
          {
            NU32* X60Qii_2 = getQ_10_Ibernwj1_intzsnzax(X60Qlf_0, X60Qlf_1);
            NB8 X60Qx_80 = eqQ_0_nifh7u8pu1((*X60Qii_2), sym_1);
            if (X60Qx_80){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  {
    openArray_0_Ir53qdx_intzsnzax X60Qlf_2 = toOpenArray_1_I02c2wz_intzsnzax((*rs_2).activeTypes_0);
    NI32 X60Qlf_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_81 = len_6_Ijqv54i_intzsnzax(X60Qlf_2);
        if (X60Qlf_3 < X60Qx_81){
          {
            NU32* X60Qii_5 = getQ_10_Ibernwj1_intzsnzax(X60Qlf_2, X60Qlf_3);
            NB8 X60Qx_82 = eqQ_0_nifh7u8pu1((*X60Qii_5), sym_1);
            if (X60Qx_82){
              return NIM_FALSE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
        else {
          break;}}}
    whileStmtLabel_4: ;}
  forStmtLabel_3: ;
  if (24 < depth_2){
    return NIM_FALSE;}
  string_0_sysvq0asl name_0 = baseNameOf_0_red2rogzl(sym_1);
  NI32 X60Qx_83 = len_4_sysvq0asl(name_0);
  if (X60Qx_83 == 0){
    nimStrDestroy(name_0);
    return NIM_FALSE;}
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_4 = toOpenArray_1_I6b60gk1_aow7lb5cq1((*rs_2).usedNames_0);
    NI32 X60Qlf_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_84 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_4);
        if (X60Qlf_5 < X60Qx_84){
          {
            string_0_sysvq0asl* X60Qii_8 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_4, X60Qlf_5);
            NB8 X60Qx_85 = eqQ_20_sysvq0asl((*X60Qii_8), name_0);
            if (X60Qx_85){
              nimStrDestroy(name_0);
              return NIM_FALSE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
        else {
          break;}}}
    whileStmtLabel_7: ;}
  forStmtLabel_6: ;
  LoadResult_0_prorcx25w1 res_0 = tryLoadSymSafe_0_modzy18mg1(sym_1);
  NB8 X60Qx_17;
  NB8 X60Qx_86;
  if ((!(res_0.status_0 == 3))){
    X60Qx_86 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_87 = kind_0_nifb6mq6y1(res_0.decl_0);
    X60Qx_86 = (!(X60Qx_87 == 11));}
  if (X60Qx_86){
    X60Qx_17 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_11 = nodeTag_0_red2rogzl(res_0.decl_0);
    NB8 X60Qx_88 = eqQ_20_sysvq0asl(X60Qtmp_11, (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
    );
    X60Qx_17 = (!X60Qx_88);
    nimStrDestroy(X60Qtmp_11);}
  if (X60Qx_17){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    nimStrDestroy(name_0);
    return NIM_FALSE;}
  TypeDecl_0_decqocs071 td_0 = asTypeDecl_0_decqocs071(res_0.decl_0);
  NifKind_0_nif81dubp1 X60Qx_89 = kind_0_nifb6mq6y1(td_0.typevars_0);
  if ((!(X60Qx_89 == 2))){
    eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_0));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    nimStrDestroy(name_0);
    return NIM_FALSE;}
  NB8 pok_0 = NIM_TRUE;
  NB8 pimp_0 = NIM_FALSE;
  string_0_sysvq0asl prag_0 = spellPragmas_0_red2rogzl(td_0.pragmas_0, (&pok_0), (&pimp_0));
  if ((!pok_0)){
    nimStrDestroy(prag_0);
    eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_0));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    nimStrDestroy(name_0);
    return NIM_FALSE;}
  add_0_I34il1q_der823rwr1((&(*rs_2).activeTypes_0), sym_1);
  string_0_sysvq0asl text_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_18;
  NifKind_0_nif81dubp1 X60Qx_90 = kind_0_nifb6mq6y1(td_0.body_0);
  if (X60Qx_90 == 11){
    string_0_sysvq0asl X60Qtmp_12 = nodeTag_0_red2rogzl(td_0.body_0);
    NB8 X60Qx_91 = eqQ_20_sysvq0asl(X60Qtmp_12, (string_0_sysvq0asl){
      .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
    );
    X60Qx_18 = X60Qx_91;
    nimStrDestroy(X60Qtmp_12);}
  else {
    X60Qx_18 = NIM_FALSE;}
  if (X60Qx_18){
    Cursor_0_nifb6mq6y1 b_0 = td_0.body_0;
    eQwasMoved_0_nifb6mq6y1((&td_0.body_0));
    inc_0_nifb6mq6y1((&b_0));
    NifKind_0_nif81dubp1 X60Qx_92 = kind_0_nifb6mq6y1(b_0);
    if ((!(X60Qx_92 == 2))){
      NI32 X60Qx_93 = len_3_I6y2imo_arecyyj7v((*rs_2).activeTypes_0);
      setLen_0_Ihfm18w_buiyylk1h1((&(*rs_2).activeTypes_0), ((NI32)(X60Qx_93 - 1)));
      eQdestroy_0_nifb6mq6y1((&b_0));
      nimStrDestroy(text_0);
      nimStrDestroy(prag_0);
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_0));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
      nimStrDestroy(name_0);
      return NIM_FALSE;}
    skip_0_nifb6mq6y1((&b_0));
    string_0_sysvq0asl fields_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    NB8 fok_0 = NIM_TRUE;
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_94 = kind_0_nifb6mq6y1(b_0);
        if ((!(X60Qx_94 == 12))){
          NB8 X60Qx_19;
          NifKind_0_nif81dubp1 X60Qx_95 = kind_0_nifb6mq6y1(b_0);
          if ((!(X60Qx_95 == 11))){
            X60Qx_19 = NIM_TRUE;}
          else {
            string_0_sysvq0asl X60Qtmp_13 = nodeTag_0_red2rogzl(b_0);
            NB8 X60Qx_96 = eqQ_20_sysvq0asl(X60Qtmp_13, (string_0_sysvq0asl){
              .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
            );
            X60Qx_19 = (!X60Qx_96);
            nimStrDestroy(X60Qtmp_13);}
          if (X60Qx_19){
            fok_0 = NIM_FALSE;
            goto whileStmtLabel_9;}
          Cursor_0_nifb6mq6y1 f_0 = eQdup_0_nifb6mq6y1(b_0);
          inc_0_nifb6mq6y1((&f_0));
          NifKind_0_nif81dubp1 X60Qx_97 = kind_0_nifb6mq6y1(f_0);
          if ((!(X60Qx_97 == 5))){
            fok_0 = NIM_FALSE;
            eQdestroy_0_nifb6mq6y1((&f_0));
            goto whileStmtLabel_9;}
          NU32 X60Qx_98 = symId_0_nifb6mq6y1(f_0);
          string_0_sysvq0asl fname_0 = baseNameOf_0_red2rogzl(X60Qx_98);
          skip_0_nifb6mq6y1((&f_0));
          skip_0_nifb6mq6y1((&f_0));
          NB8 fpok_0 = NIM_TRUE;
          NB8 fimp_0 = NIM_FALSE;
          string_0_sysvq0asl fprag_0 = spellPragmas_0_red2rogzl(f_0, (&fpok_0), (&fimp_0));
          if ((!fpok_0)){
            fok_0 = NIM_FALSE;
            nimStrDestroy(fprag_0);
            nimStrDestroy(fname_0);
            eQdestroy_0_nifb6mq6y1((&f_0));
            goto whileStmtLabel_9;}
          skip_0_nifb6mq6y1((&f_0));
          string_0_sysvq0asl ftyp_0 = spellTypeExpr_0_red2rogzl(f_0, rs_2, ((NI32)(depth_2 + 1)));
          NI32 X60Qx_99 = len_4_sysvq0asl(ftyp_0);
          if (X60Qx_99 == 0){
            fok_0 = NIM_FALSE;
            nimStrDestroy(ftyp_0);
            nimStrDestroy(fprag_0);
            nimStrDestroy(fname_0);
            eQdestroy_0_nifb6mq6y1((&f_0));
            goto whileStmtLabel_9;}
          NI32 X60Qx_100 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2105346u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_101 = len_4_sysvq0asl(fname_0);
          NI32 X60Qx_102 = len_4_sysvq0asl(fprag_0);
          NI32 X60Qx_103 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2112002u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_104 = len_4_sysvq0asl(ftyp_0);
          NI32 X60Qx_105 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2561u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_7 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_100 + X60Qx_101)) + X60Qx_102)) + X60Qx_103)) + X60Qx_104)) + X60Qx_105)));
          add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
            .bytes_0 = 2105346u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_7), fname_0);
          add_2_sysvq0asl((&X60Qdesugar_7), fprag_0);
          add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
            .bytes_0 = 2112002u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_7), ftyp_0);
          add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
            .bytes_0 = 2561u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&fields_0), X60Qdesugar_7);
          skip_0_nifb6mq6y1((&b_0));
          nimStrDestroy(X60Qdesugar_7);
          nimStrDestroy(ftyp_0);
          nimStrDestroy(fprag_0);
          nimStrDestroy(fname_0);
          eQdestroy_0_nifb6mq6y1((&f_0));}
        else {
          break;}}}
    whileStmtLabel_9: ;
    NB8 X60Qx_106;
    if ((!fok_0)){
      X60Qx_106 = NIM_TRUE;}
    else {
      NI32 X60Qx_107 = len_4_sysvq0asl(fields_0);
      X60Qx_106 = (X60Qx_107 == 0);}
    if (X60Qx_106){
      NI32 X60Qx_108 = len_3_I6y2imo_arecyyj7v((*rs_2).activeTypes_0);
      setLen_0_Ihfm18w_buiyylk1h1((&(*rs_2).activeTypes_0), ((NI32)(X60Qx_108 - 1)));
      nimStrDestroy(fields_0);
      eQdestroy_0_nifb6mq6y1((&b_0));
      nimStrDestroy(text_0);
      nimStrDestroy(prag_0);
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_0));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
      nimStrDestroy(name_0);
      return NIM_FALSE;}
    NI32 X60Qx_109 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3342234748333824056_red2rogzl)}
    );
    NI32 X60Qx_110 = len_4_sysvq0asl(name_0);
    NI32 X60Qx_111 = len_4_sysvq0asl(prag_0);
    NI32 X60Qx_112 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 540877054u, .more_0 = (&strlit_0_I11348611436872997213_red2rogzl)}
    );
    NI32 X60Qx_113 = len_4_sysvq0asl(fields_0);
    string_0_sysvq0asl X60Qdesugar_8 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_109 + X60Qx_110)) + X60Qx_111)) + X60Qx_112)) + X60Qx_113)));
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3342234748333824056_red2rogzl)}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), name_0);
    add_2_sysvq0asl((&X60Qdesugar_8), prag_0);
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 540877054u, .more_0 = (&strlit_0_I11348611436872997213_red2rogzl)}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), fields_0);
    nimStrDestroy(text_0);
    text_0 = X60Qdesugar_8;
    nimStrWasMoved((&X60Qdesugar_8));
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(fields_0);
    eQdestroy_0_nifb6mq6y1((&b_0));}
  else {
    string_0_sysvq0asl bodyStr_0 = spellTypeExpr_0_red2rogzl(td_0.body_0, rs_2, ((NI32)(depth_2 + 1)));
    NI32 X60Qx_114 = len_4_sysvq0asl(bodyStr_0);
    if (X60Qx_114 == 0){
      NI32 X60Qx_115 = len_3_I6y2imo_arecyyj7v((*rs_2).activeTypes_0);
      setLen_0_Ihfm18w_buiyylk1h1((&(*rs_2).activeTypes_0), ((NI32)(X60Qx_115 - 1)));
      nimStrDestroy(bodyStr_0);
      nimStrDestroy(text_0);
      nimStrDestroy(prag_0);
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_0));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
      nimStrDestroy(name_0);
      return NIM_FALSE;}
    NI32 X60Qx_116 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3342234748333824056_red2rogzl)}
    );
    NI32 X60Qx_117 = len_4_sysvq0asl(name_0);
    NI32 X60Qx_118 = len_4_sysvq0asl(prag_0);
    NI32 X60Qx_119 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 540876803u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_120 = len_4_sysvq0asl(bodyStr_0);
    NI32 X60Qx_121 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_116 + X60Qx_117)) + X60Qx_118)) + X60Qx_119)) + X60Qx_120)) + X60Qx_121)));
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3342234748333824056_red2rogzl)}
    );
    add_2_sysvq0asl((&X60Qdesugar_9), name_0);
    add_2_sysvq0asl((&X60Qdesugar_9), prag_0);
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 540876803u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_9), bodyStr_0);
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(text_0);
    text_0 = X60Qdesugar_9;
    nimStrWasMoved((&X60Qdesugar_9));
    nimStrDestroy(X60Qdesugar_9);
    nimStrDestroy(bodyStr_0);}
  NI32 X60Qx_122 = len_3_I6y2imo_arecyyj7v((*rs_2).activeTypes_0);
  setLen_0_Ihfm18w_buiyylk1h1((&(*rs_2).activeTypes_0), ((NI32)(X60Qx_122 - 1)));
  add_0_I34il1q_der823rwr1((&(*rs_2).seenTypes_0), sym_1);
  string_0_sysvq0asl X60Qtmp_14 = name_0;
  nimStrWasMoved((&name_0));
  add_0_Ig6072n_aow7lb5cq1((&(*rs_2).usedNames_0), X60Qtmp_14);
  string_0_sysvq0asl X60Qtmp_15 = text_0;
  nimStrWasMoved((&text_0));
  add_0_Ig6072n_aow7lb5cq1((&(*rs_2).typeDecls_0), X60Qtmp_15);
  result_7 = NIM_TRUE;
  nimStrDestroy(text_0);
  nimStrDestroy(prag_0);
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_0));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  nimStrDestroy(name_0);
  return result_7;
  nimStrDestroy(text_0);
  nimStrDestroy(prag_0);
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_0));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  nimStrDestroy(name_0);
  return result_7;}
NB8 addProcRedecl_0_red2rogzl(NU32 sym_2, Cursor_0_nifb6mq6y1 decl_0, RedeclSet_0_red2rogzl* rs_3){
  NB8 result_8;
  NifKind_0_nif81dubp1 X60Qx_123 = kind_0_nifb6mq6y1(decl_0);
  if ((!(X60Qx_123 == 11))){
    return NIM_FALSE;}
  Routine_0_decqocs071 rt_0 = asRoutine_0_decqocs071(decl_0, 1);
  NifKind_0_nif81dubp1 X60Qx_124 = kind_0_nifb6mq6y1(rt_0.typevars_0);
  if ((!(X60Qx_124 == 2))){
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
    return NIM_FALSE;}
  string_0_sysvq0asl name_1 = baseNameOf_0_red2rogzl(sym_2);
  NI32 X60Qx_125 = len_4_sysvq0asl(name_1);
  if (X60Qx_125 == 0){
    nimStrDestroy(name_1);
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
    return NIM_FALSE;}
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_6 = toOpenArray_1_I6b60gk1_aow7lb5cq1((*rs_3).usedNames_0);
    NI32 X60Qlf_7 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_126 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_6);
        if (X60Qlf_7 < X60Qx_126){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_6, X60Qlf_7);
            NB8 X60Qx_127 = eqQ_20_sysvq0asl((*X60Qii_2), name_1);
            if (X60Qx_127){
              nimStrDestroy(name_1);
              eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
              return NIM_FALSE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NB8 pok_1 = NIM_TRUE;
  NB8 pimp_1 = NIM_FALSE;
  string_0_sysvq0asl prag_1 = spellPragmas_0_red2rogzl(rt_0.pragmas_0, (&pok_1), (&pimp_1));
  if ((!pok_1)){
    nimStrDestroy(prag_1);
    nimStrDestroy(name_1);
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
    return NIM_FALSE;}
  if ((!pimp_1)){
    nimStrDestroy(prag_1);
    nimStrDestroy(name_1);
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
    return NIM_FALSE;}
  string_0_sysvq0asl params_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 n_4 = 0;
  NB8 X60Qx_20;
  NifKind_0_nif81dubp1 X60Qx_128 = kind_0_nifb6mq6y1(rt_0.params_0);
  if (X60Qx_128 == 11){
    string_0_sysvq0asl X60Qtmp_16 = nodeTag_0_red2rogzl(rt_0.params_0);
    NB8 X60Qx_129 = eqQ_20_sysvq0asl(X60Qtmp_16, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_der823rwr1)}
    );
    X60Qx_20 = X60Qx_129;
    nimStrDestroy(X60Qtmp_16);}
  else {
    X60Qx_20 = NIM_FALSE;}
  if (X60Qx_20){
    Cursor_0_nifb6mq6y1 p_0 = rt_0.params_0;
    eQwasMoved_0_nifb6mq6y1((&rt_0.params_0));
    inc_0_nifb6mq6y1((&p_0));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_130 = kind_0_nifb6mq6y1(p_0);
        if ((!(X60Qx_130 == 12))){
          NB8 X60Qx_21;
          NifKind_0_nif81dubp1 X60Qx_131 = kind_0_nifb6mq6y1(p_0);
          if ((!(X60Qx_131 == 11))){
            X60Qx_21 = NIM_TRUE;}
          else {
            string_0_sysvq0asl X60Qtmp_17 = nodeTag_0_red2rogzl(p_0);
            NB8 X60Qx_132 = eqQ_20_sysvq0asl(X60Qtmp_17, (string_0_sysvq0asl){
              .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I9792473688321036479_emi78vuj01)}
            );
            X60Qx_21 = (!X60Qx_132);
            nimStrDestroy(X60Qtmp_17);}
          if (X60Qx_21){
            eQdestroy_0_nifb6mq6y1((&p_0));
            nimStrDestroy(params_0);
            nimStrDestroy(prag_1);
            nimStrDestroy(name_1);
            eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
            return NIM_FALSE;}
          Cursor_0_nifb6mq6y1 q_0 = eQdup_0_nifb6mq6y1(p_0);
          inc_0_nifb6mq6y1((&q_0));
          skip_0_nifb6mq6y1((&q_0));
          skip_0_nifb6mq6y1((&q_0));
          skip_0_nifb6mq6y1((&q_0));
          string_0_sysvq0asl pfx_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          Cursor_0_nifb6mq6y1 tc_0 = q_0;
          eQwasMoved_0_nifb6mq6y1((&q_0));
          NifKind_0_nif81dubp1 X60Qx_133 = kind_0_nifb6mq6y1(tc_0);
          if (X60Qx_133 == 11){
            string_0_sysvq0asl ttg_0 = nodeTag_0_red2rogzl(tc_0);
            NB8 X60Qx_134;
            NB8 X60Qx_135;
            NB8 X60Qx_136 = eqQ_20_sysvq0asl(ttg_0, (string_0_sysvq0asl){
              .bytes_0 = 1953853187u, .more_0 = NIM_NIL}
            );
            if (X60Qx_136){
              X60Qx_135 = NIM_TRUE;}
            else {
              NB8 X60Qx_137 = eqQ_20_sysvq0asl(ttg_0, (string_0_sysvq0asl){
                .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
              );
              X60Qx_135 = X60Qx_137;}
            if (X60Qx_135){
              X60Qx_134 = NIM_TRUE;}
            else {
              NB8 X60Qx_138 = eqQ_20_sysvq0asl(ttg_0, (string_0_sysvq0asl){
                .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I5595596763809202512_nim30udrv)}
              );
              X60Qx_134 = X60Qx_138;}
            if (X60Qx_134){
              nimStrDestroy(pfx_0);
              string_0_sysvq0asl X60Qx_139 = ampQ_0_sysvq0asl(ttg_0, (string_0_sysvq0asl){
                .bytes_0 = 8193u, .more_0 = NIM_NIL}
              );
              pfx_0 = X60Qx_139;
              inc_0_nifb6mq6y1((&tc_0));}
            nimStrDestroy(ttg_0);}
          string_0_sysvq0asl ts_0 = spellTypeExpr_0_red2rogzl(tc_0, rs_3, 0);
          NI32 X60Qx_140 = len_4_sysvq0asl(ts_0);
          if (X60Qx_140 == 0){
            nimStrDestroy(ts_0);
            eQdestroy_0_nifb6mq6y1((&tc_0));
            nimStrDestroy(pfx_0);
            eQdestroy_0_nifb6mq6y1((&q_0));
            eQdestroy_0_nifb6mq6y1((&p_0));
            nimStrDestroy(params_0);
            nimStrDestroy(prag_1);
            nimStrDestroy(name_1);
            eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
            return NIM_FALSE;}
          if (0 < n_4){
            add_2_sysvq0asl((&params_0), (string_0_sysvq0asl){
              .bytes_0 = 2112258u, .more_0 = NIM_NIL}
            );}
          string_0_sysvq0asl X60Qdesugar_10 = dollarQ_2_sysvq0asl(n_4);
          NI32 X60Qx_141 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 24833u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_142 = len_4_sysvq0asl(X60Qdesugar_10);
          NI32 X60Qx_143 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2112002u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_144 = len_4_sysvq0asl(pfx_0);
          NI32 X60Qx_145 = len_4_sysvq0asl(ts_0);
          string_0_sysvq0asl X60Qdesugar_11 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_141 + X60Qx_142)) + X60Qx_143)) + X60Qx_144)) + X60Qx_145)));
          add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
            .bytes_0 = 24833u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_11), X60Qdesugar_10);
          add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
            .bytes_0 = 2112002u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_11), pfx_0);
          add_2_sysvq0asl((&X60Qdesugar_11), ts_0);
          add_2_sysvq0asl((&params_0), X60Qdesugar_11);
          inc_1_I6wjjge_aow2h993l1((&n_4));
          skip_0_nifb6mq6y1((&p_0));
          nimStrDestroy(X60Qdesugar_11);
          nimStrDestroy(X60Qdesugar_10);
          nimStrDestroy(ts_0);
          eQdestroy_0_nifb6mq6y1((&tc_0));
          nimStrDestroy(pfx_0);
          eQdestroy_0_nifb6mq6y1((&q_0));}
        else {
          break;}}}
    whileStmtLabel_3: ;
    eQdestroy_0_nifb6mq6y1((&p_0));}
  string_0_sysvq0asl ret_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NifKind_0_nif81dubp1 X60Qx_146 = kind_0_nifb6mq6y1(rt_0.retType_0);
  if ((!(X60Qx_146 == 2))){
    string_0_sysvq0asl rs2_0 = spellTypeExpr_0_red2rogzl(rt_0.retType_0, rs_3, 0);
    NI32 X60Qx_147 = len_4_sysvq0asl(rs2_0);
    if (X60Qx_147 == 0){
      nimStrDestroy(rs2_0);
      nimStrDestroy(ret_0);
      nimStrDestroy(params_0);
      nimStrDestroy(prag_1);
      nimStrDestroy(name_1);
      eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
      return NIM_FALSE;}
    nimStrDestroy(ret_0);
    string_0_sysvq0asl X60Qx_148 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2112002u, .more_0 = NIM_NIL}
    , rs2_0);
    ret_0 = X60Qx_148;
    nimStrDestroy(rs2_0);}
  string_0_sysvq0asl X60Qx_149 = nimStrDup(name_1);
  add_0_Ig6072n_aow7lb5cq1((&(*rs_3).usedNames_0), X60Qx_149);
  NI32 X60Qx_150 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I15249506995356931180_red2rogzl)}
  );
  NI32 X60Qx_151 = len_4_sysvq0asl(name_1);
  NI32 X60Qx_152 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_153 = len_4_sysvq0asl(params_0);
  NI32 X60Qx_154 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_155 = len_4_sysvq0asl(ret_0);
  NI32 X60Qx_156 = len_4_sysvq0asl(prag_1);
  NI32 X60Qx_157 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_12 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_150 + X60Qx_151)) + X60Qx_152)) + X60Qx_153)) + X60Qx_154)) + X60Qx_155)) + X60Qx_156)) + X60Qx_157)));
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I15249506995356931180_red2rogzl)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), name_1);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), params_0);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), ret_0);
  add_2_sysvq0asl((&X60Qdesugar_12), prag_1);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qtmp_18 = X60Qdesugar_12;
  nimStrWasMoved((&X60Qdesugar_12));
  add_0_Ig6072n_aow7lb5cq1((&(*rs_3).procDecls_0), X60Qtmp_18);
  result_8 = NIM_TRUE;
  nimStrDestroy(X60Qdesugar_12);
  nimStrDestroy(ret_0);
  nimStrDestroy(params_0);
  nimStrDestroy(prag_1);
  nimStrDestroy(name_1);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
  return result_8;
  nimStrDestroy(X60Qdesugar_12);
  nimStrDestroy(ret_0);
  nimStrDestroy(params_0);
  nimStrDestroy(prag_1);
  nimStrDestroy(name_1);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rt_0));
  return result_8;}
string_0_sysvq0asl renderProcRedecls_0_red2rogzl(RedeclSet_0_red2rogzl* rs_4){
  string_0_sysvq0asl result_9;
  nimStrWasMoved((&result_9));
  nimStrDestroy(result_9);
  result_9 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_8 = toOpenArray_1_I6b60gk1_aow7lb5cq1((*rs_4).procDecls_0);
    NI32 X60Qlf_9 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_158 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_8);
        if (X60Qlf_9 < X60Qx_158){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_8, X60Qlf_9);
            add_2_sysvq0asl((&result_9), (*X60Qii_2));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_9;}
void eQdestroyQ_SX52edeclX53et0red2rogzl_0_red2rogzl(RedeclSet_0_red2rogzl* dest_0){
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*dest_0).usedNames_0);
  eQdestroy_1_Iscb4i31_arecyyj7v((*dest_0).activeTypes_0);
  eQdestroy_1_Iscb4i31_arecyyj7v((*dest_0).seenTypes_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*dest_0).procDecls_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*dest_0).typeDecls_0);}
void X60Qini_0_red2rogzl(void){
  if (X60QiniGuard_0_red2rogzl){
    return;}
  X60QiniGuard_0_red2rogzl = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_modzy18mg1();
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
  X60Qini_0_tagygirdh1();}
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
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
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
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1){
  Cursor_0_nifb6mq6y1 result_4;
  result_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = src_1.owner_0, .p_0 = src_1.p_0, .rem_0 = src_1.rem_0}
  ;
  if ((!(result_4.owner_0 == NIM_NIL))){
    inc_1_I6wjjge_aow2h993l1((&(*result_4.owner_0).rc_0));}
  return result_4;}
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
  string_0_sysvq0asl* X60Qx_31 = getQ_7_Ir6d0tw_aow7lb5cq1(t_6.vals_0, idx_0);
  result_3 = X60Qx_31;
  return result_3;}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
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
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8){
  NU32 result_11;
  PackedToken_0_nifh7u8pu1 X60Qx_26 = load_0_nifb6mq6y1(c_8);
  NU32 X60Qx_27 = symId_0_nifh7u8pu1(X60Qx_26);
  result_11 = X60Qx_27;
  return result_11;}
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
static inline openArray_0_Ir53qdx_intzsnzax toOpenArray_1_I02c2wz_intzsnzax(seq_0_In6doa_arecyyj7v s_164){
  openArray_0_Ir53qdx_intzsnzax result_211;
  NU32* X60Qx_3781 = rawData_0_I9ky6gs1_intzsnzax(s_164);
  result_211 = (openArray_0_Ir53qdx_intzsnzax){
    .a_0 = X60Qx_3781, .len_0 = s_164.len_0}
  ;
  return result_211;}
static inline NI32 len_6_Ijqv54i_intzsnzax(openArray_0_Ir53qdx_intzsnzax a_72){
  NI32 result_328;
  result_328 = a_72.len_0;
  return result_328;}
static inline NU32* getQ_10_Ibernwj1_intzsnzax(openArray_0_Ir53qdx_intzsnzax x_28, NI32 idx_48){
  NB8 X60Qx_4077;
  if (0 <= idx_48){
    X60Qx_4077 = (idx_48 < x_28.len_0);}
  else {
    X60Qx_4077 = NIM_FALSE;}
  if ((!X60Qx_4077)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NU32* result_329;
  result_329 = (&x_28.a_0[idx_48]);
  return result_329;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_43){
  openArray_0_Ig73pnk_aow7lb5cq1 result_80;
  string_0_sysvq0asl* X60Qx_2287 = rawData_0_I65w5sr_aow7lb5cq1(s_43);
  result_80 = (openArray_0_Ig73pnk_aow7lb5cq1){
    .a_0 = X60Qx_2287, .len_0 = s_43.len_0}
  ;
  return result_80;}
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
static inline void add_0_I34il1q_der823rwr1(seq_0_In6doa_arecyyj7v* s_12, NU32 elem_2){
  NI32 L_0 = (*s_12).len_0;
  NI32 X60Qx_190 = capInBytes_0_Iev6wua1_arecyyj7v((*s_12));
  if (X60Qx_190 < ((NI32)(((NI32)(L_0 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_191 = resize_0_I6ho9ve_buiyylk1h1(s_12, 1);
    if ((!X60Qx_191)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_12).len_0));
  (*s_12).data_0[L_0] = elem_2;}
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37){
  NI32 result_34;
  result_34 = s_37.len_0;
  return result_34;}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
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
static inline NU32* rawData_0_I9ky6gs1_intzsnzax(seq_0_In6doa_arecyyj7v s_290){
  NU32* result_327;
  result_327 = s_290.data_0;
  return result_327;}
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67){
  string_0_sysvq0asl* result_106;
  result_106 = s_67.data_0;
  return result_106;}
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
