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
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01 X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct ToplevelEntry_0_prorcx25w1 ToplevelEntry_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21;
typedef NU8 NKind_0_emi78vuj01;

#define nkAtom_0_emi78vuj01 ((NU8)0)
#define nkStr_0_emi78vuj01 ((NU8)1)
#define nkChar_0_emi78vuj01 ((NU8)2)
#define nkList_0_emi78vuj01 ((NU8)3)
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct seq_0_Isutro81_emi78vuj01{
  NI32 len_0;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** data_0;}
seq_0_Isutro81_emi78vuj01;
typedef struct Node_Obj_0_emi78vuj01{
  NKind_0_emi78vuj01 kind_0;
  string_0_sysvq0asl tag_0;
  seq_0_Isutro81_emi78vuj01 kids_0;
  string_0_sysvq0asl atom_0;
  NB8 def_0;
  string_0_sysvq0asl strVal_0;
  NI32 chrVal_0;}
Node_Obj_0_emi78vuj01;
typedef struct ProcParts_0_emi78vuj01{
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* nameAtom_0;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* params_0;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* ret_0;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* body_0;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pragmas_0;
  seq_0_Isutro81_emi78vuj01 pnodes_0;}
ProcParts_0_emi78vuj01;
typedef struct GlobalInfo_0_emi78vuj01{
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl decl_0;
  string_0_sysvq0asl nameAtom_0;
  NB8 needsInit_0;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* value_0;}
GlobalInfo_0_emi78vuj01;
typedef struct Classified_0_emi78vuj01{
  seq_0_Isutro81_emi78vuj01 procs_0;
  seq_0_Isutro81_emi78vuj01 globals_0;
  seq_0_Isutro81_emi78vuj01 types_0;
  seq_0_Isutro81_emi78vuj01 topStmts_0;}
Classified_0_emi78vuj01;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct openArray_0_Ig73pnk_aow7lb5cq1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_aow7lb5cq1;
typedef struct HSlice_0_Inzqy8d_aow7lb5cq1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_aow7lb5cq1;
typedef struct openArray_0_Ip5n4zi1_emi78vuj01{
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** a_0;
  NI32 len_0;}
openArray_0_Ip5n4zi1_emi78vuj01;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
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
typedef struct X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01{
  NI r_00;
  Node_Obj_0_emi78vuj01 d_00;}
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01{
  string_0_sysvq0asl a[3];}
X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01{
  string_0_sysvq0asl a[2];}
X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01{
  string_0_sysvq0asl a[1];}
X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS9_emi78vuj01{
  string_0_sysvq0asl a[9];}
X60Qt_0_IAarraySstring0sysvq0aslS9_emi78vuj01;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01{
  string_0_sysvq0asl a[4];}
X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS7_emi78vuj01{
  string_0_sysvq0asl a[7];}
X60Qt_0_IAarraySstring0sysvq0aslS7_emi78vuj01;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS17_emi78vuj01{
  string_0_sysvq0asl a[17];}
X60Qt_0_IAarraySstring0sysvq0aslS17_emi78vuj01;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS6_emi78vuj01{
  string_0_sysvq0asl a[6];}
X60Qt_0_IAarraySstring0sysvq0aslS6_emi78vuj01;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
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
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
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
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1{
  string_0_sysvq0asl fld_0;
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef NU8 SemPhase_0_prorcx25w1;

#define SemcheckTopLevelSyms_0_prorcx25w1 ((NU8)0)
#define SemcheckSignaturesInProgress_0_prorcx25w1 ((NU8)1)
#define SemcheckSignatures_0_prorcx25w1 ((NU8)2)
#define SemcheckBodiesInProgress_0_prorcx25w1 ((NU8)3)
#define SemcheckBodies_0_prorcx25w1 ((NU8)4)
typedef struct ToplevelEntry_0_prorcx25w1{
  TokenBuf_0_nifb6mq6y1 buffer_0;
  SemPhase_0_prorcx25w1 phase_0;}
ToplevelEntry_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax{
  NU32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax;
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
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
string_0_sysvq0asl genType_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* t_6);
string_0_sysvq0asl genInit_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* e_6);
string_0_sysvq0asl genExpr_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* e_7);
string_0_sysvq0asl genStmt_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* s_15);
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* buildNode_1_emi78vuj01(Cursor_0_nifb6mq6y1* c_1);
static inline void plusQeQ_0_Iz7fdp7_emi78vuj01(NI32* x_18, NI32 y_1);
static inline seq_0_Isutro81_emi78vuj01 newSeqUninit_0_I3hisst_emi78vuj01(NI32 size_7);
static inline openArray_0_Ip5n4zi1_emi78vuj01 toOpenArray_1_I1gbnw21_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_39);
static inline NI32 len_3_Il6imzw1_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_41);
static inline X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** getQ_7_Iheb436_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_42, NI32 i_35);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_I3urt0l_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01* x_20);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Il5czcd1_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01* x_21);
static inline void add_0_Iv4n2t31_emi78vuj01(seq_0_Isutro81_emi78vuj01* s_43, X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* elem_5);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_If2frt3_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01* x_22);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Ia0unmf_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS9_emi78vuj01* x_23);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Ig1w4is1_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01* x_24);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Ih6urrr1_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS7_emi78vuj01* x_25);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Ima7t9w_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS17_emi78vuj01* x_26);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_I6nl44k1_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS6_emi78vuj01* x_27);
static inline NI32 memSizeInBytes_0_I9a2uc9_emi78vuj01(NI32 size_12);
static inline X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** rawData_0_Idp9xor1_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_53);
static inline NI32 len_6_I3x6mi_emi78vuj01(openArray_0_Ip5n4zi1_emi78vuj01 a_30);
static inline X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** getQ_10_Ipbnh891_emi78vuj01(openArray_0_Ip5n4zi1_emi78vuj01 x_30, NI32 idx_12);
static inline NI32 capInBytes_0_I6jrhdd1_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_54);
NB8 resize_0_Ihuqu5k1_emi78vuj01(seq_0_Isutro81_emi78vuj01* dest_4, NI32 addedElements_4);
void eQdestroy_1_Ia4wwhy1_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_80);
static inline void eQwasMoved_1_Iu9z3fg1_emi78vuj01(seq_0_Isutro81_emi78vuj01* s_81);
seq_0_Isutro81_emi78vuj01 eQdup_1_Iqcqrch1_emi78vuj01(seq_0_Isutro81_emi78vuj01 a_42);
void eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01(ProcParts_0_emi78vuj01* dest_0);
void eQwasmovedQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01(ProcParts_0_emi78vuj01* dest_0);
void eQdestroyQ_SX47lobalX49nfo0emi78vuj01_0_emi78vuj01(GlobalInfo_0_emi78vuj01* dest_0);
void eQwasmovedQ_SX47lobalX49nfo0emi78vuj01_0_emi78vuj01(GlobalInfo_0_emi78vuj01* dest_0);
void eQdestroyQ_SX43lassified0emi78vuj01_0_emi78vuj01(Classified_0_emi78vuj01* dest_0);
void eQwasmovedQ_SX43lassified0emi78vuj01_0_emi78vuj01(Classified_0_emi78vuj01* dest_0);
void eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* dest_0);
void eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** dest_0);
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* src_0);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_41);
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_28);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7);
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_27);
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline HSlice_0_Inzqy8d_aow7lb5cq1 ___1_Iclcqmw1_aow7lb5cq1(NI32 a_15, NI32 b_2);
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355);
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_dbgj4vyzj1(NI32 a_13, NI32 b_2);
static inline NC8 chr_0_sysvq0asl(NI32 u_0);
extern string_0_sysvq0asl dollarQ_1_sysvq0asl(NI64 x_225);
extern string_0_sysvq0asl dollarQ_0_sysvq0asl(NU64 x_224);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
static inline string_0_sysvq0asl ampQ_1_sysvq0asl(string_0_sysvq0asl x_316, NC8 y_199);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern Program_0_prorcx25w1 prog_0_prorcx25w1;
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
extern LongString_0_sysvq0asl const strlit_0_I5367917178860180580_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I11155032387348830029_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I11024699549390617459_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I1177603226064417776_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I1707222714195181991_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I12061648672903694946_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I8939511674443647382_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I4196580491060784277_der823rwr1;
extern LongString_0_sysvq0asl const strlit_0_I17846080716529448640_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I3789116743795128948_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I10462096440466995513_aow7lb5cq1;
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_36);
static inline void putQ_7_Ifvyck5_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_52, NI32 i_38, NI32 elem_15);
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13);
extern void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10);
extern LongString_0_sysvq0asl const strlit_0_I17410079638349000741_aow7lb5cq1;
extern NB8 fileExists_0_osc4bsu0d1(string_0_sysvq0asl filename_0);
extern TokenBuf_0_nifb6mq6y1 parseFromFile_0_nifb6mq6y1(string_0_sysvq0asl filename_1, NI32 sizeHint_1);
extern Cursor_0_nifb6mq6y1 beginRead_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_4);
static inline void endRead_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_5);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13);
static inline string_0_sysvq0asl* getQ_0_I93d71y_der823rwr1(BiTable_0_Icvz6lt_buiyylk1h1 t_5, NU32 litId_1);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
static inline void consumeParRi_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_19);
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
static inline NU32 litId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_7);
static inline string_0_sysvq0asl* getQ_0_Iplpzal1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k t_6, NU32 litId_5);
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10);
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6);
static inline NU32 uintId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_11);
static inline NU64* getQ_0_Iebom0i1_ast8ri79k(BiTable_0_Itxao711_ast8ri79k t_8, NU32 litId_7);
static inline NU32 floatId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_12);
static inline NF64 getQ_1_I4qx0py_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_9, NU32 litId_8);
extern string_0_sysvq0asl dollarQ_7_sysvq0asl(NF64 x_348);
static inline NC8 charLit_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_9);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_prorcx25w1(void);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
extern string_0_sysvq0asl charToString_0_sysvq0asl(NC8 c_16);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68);
extern NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8);
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern LongString_0_sysvq0asl const strlit_0_I17128882682348225350_nifb6mq6y1;
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline NU32 litId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_9);
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
static inline NU32 uintId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_13);
static inline NU64* getQ_7_Ifaxado1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_10, NI32 i_7);
static inline NU32 floatId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_14);
static inline NU64* getQ_0_I3qz68f_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_14, NU32 litId_13);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
static inline NC8 charLit_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_10);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
LongString_0_sysvq0asl const strlit_0_I1493431938208774112_emi78vuj01 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-9223372036854775808"}
;
LongString_0_sysvq0asl const strlit_0_I11180947211213179806_emi78vuj01 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(-9223372036854775807LL - 1LL)"}
;
LongString_0_sysvq0asl const strlit_0_I7901555537561129428_emi78vuj01 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "0123456789ABCDEF"}
;
LongString_0_sysvq0asl const strlit_0_I5839537462929284299_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "putQ"}
;
LongString_0_sysvq0asl const strlit_0_I3587198974648410474_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getQ"}
;
LongString_0_sysvq0asl const strlit_0_I6001479237466573771_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dollarQ"}
;
LongString_0_sysvq0asl const strlit_0_I9794172738743734741_emi78vuj01 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "percentQ"}
;
LongString_0_sysvq0asl const strlit_0_I4549956430263353259_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ampQ"}
;
LongString_0_sysvq0asl const strlit_0_I6324820878088668721_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "roofQ"}
;
LongString_0_sysvq0asl const strlit_0_I5022937532488303155_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "emarkQ"}
;
LongString_0_sysvq0asl const strlit_0_I3040189447710877908_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "qmarkQ"}
;
LongString_0_sysvq0asl const strlit_0_I17986771364525673239_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "starQ"}
;
LongString_0_sysvq0asl const strlit_0_I3209885551604274897_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "plusQ"}
;
LongString_0_sysvq0asl const strlit_0_I8120334580135717506_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "minusQ"}
;
LongString_0_sysvq0asl const strlit_0_I9829284319393728878_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "slashQ"}
;
LongString_0_sysvq0asl const strlit_0_I10077072016029657701_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bslashQ"}
;
LongString_0_sysvq0asl const strlit_0_I16101758279297810961_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tildeQ"}
;
LongString_0_sysvq0asl const strlit_0_I16015100509361966772_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "colonQ"}
;
LongString_0_sysvq0asl const strlit_0_I5416429193604338878_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "barQ"}
;
LongString_0_sysvq0asl const strlit_0_I7737667989527362245_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " << "}
;
LongString_0_sysvq0asl const strlit_0_I7519293862644853856_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " >> "}
;
LongString_0_sysvq0asl const strlit_0_I4333440046835585584_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ashr"}
;
LongString_0_sysvq0asl const strlit_0_I12320098920117258102_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bitand"}
;
LongString_0_sysvq0asl const strlit_0_I8344472873800577395_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bitor"}
;
LongString_0_sysvq0asl const strlit_0_I1868900624481666580_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bitxor"}
;
LongString_0_sysvq0asl const strlit_0_I12419389927391420973_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " == "}
;
LongString_0_sysvq0asl const strlit_0_I2558138246944699345_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " != "}
;
LongString_0_sysvq0asl const strlit_0_I8459464401138684096_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " <= "}
;
LongString_0_sysvq0asl const strlit_0_I10610139082009356491_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " >= "}
;
LongString_0_sysvq0asl const strlit_0_I9770694860431025064_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " && "}
;
LongString_0_sysvq0asl const strlit_0_I17052362747483005533_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " || "}
;
LongString_0_sysvq0asl const strlit_0_I6323980750145937682_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NI64"}
;
LongString_0_sysvq0asl const strlit_0_I12781920874167708466_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NI32"}
;
LongString_0_sysvq0asl const strlit_0_I13186846618376552100_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NI16"}
;
LongString_0_sysvq0asl const strlit_0_I18138163183994580077_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NU64"}
;
LongString_0_sysvq0asl const strlit_0_I9066213625147390190_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NU32"}
;
LongString_0_sysvq0asl const strlit_0_I13023609298664275323_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NU16"}
;
LongString_0_sysvq0asl const strlit_0_I11372099257973387468_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NF64"}
;
LongString_0_sysvq0asl const strlit_0_I10477416574274012141_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NF32"}
;
LongString_0_sysvq0asl const strlit_0_I7023501325319911082_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pragmas"}
;
LongString_0_sysvq0asl const strlit_0_I3957309170640276402_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "importc"}
;
LongString_0_sysvq0asl const strlit_0_I4862850237857511107_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "exportc"}
;
LongString_0_sysvq0asl const strlit_0_I6761535509221812916_emi78vuj01 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "importcpp"}
;
LongString_0_sysvq0asl const strlit_0_I9792473688321036479_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "param"}
;
LongString_0_sysvq0asl const strlit_0_I4957091821656791898_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(*)("}
;
LongString_0_sysvq0asl const strlit_0_I12782213824028315602_emi78vuj01 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowlc: bad type node"}
;
LongString_0_sysvq0asl const strlit_0_I6488225283415667707_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aptr"}
;
LongString_0_sysvq0asl const strlit_0_I13748185565082850274_emi78vuj01 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "flexarray"}
;
LongString_0_sysvq0asl const strlit_0_I1995551610468546737_emi78vuj01 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "proctype"}
;
LongString_0_sysvq0asl const strlit_0_I1645239835584249519_emi78vuj01 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowlc: unsupported type \'"}
;
LongString_0_sysvq0asl const strlit_0_I17573272885368898989_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aconstr"}
;
LongString_0_sysvq0asl const strlit_0_I10258041648709112440_emi78vuj01 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "{ .a = { "}
;
LongString_0_sysvq0asl const strlit_0_I3856878759998182809_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " } }"}
;
LongString_0_sysvq0asl const strlit_0_I7084116572891045059_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "oconstr"}
;
LongString_0_sysvq0asl const strlit_0_I8948425280810671385_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(NC8)"}
;
LongString_0_sysvq0asl const strlit_0_I8572766038233537570_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "true"}
;
LongString_0_sysvq0asl const strlit_0_I10397369818502852122_emi78vuj01 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NIM_TRUE"}
;
LongString_0_sysvq0asl const strlit_0_I3372626016653902757_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "false"}
;
LongString_0_sysvq0asl const strlit_0_I15144514746646140558_emi78vuj01 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NIM_FALSE"}
;
LongString_0_sysvq0asl const strlit_0_I14478742859183798749_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NIM_NIL"}
;
LongString_0_sysvq0asl const strlit_0_I186799702831424311_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "neginf"}
;
LongString_0_sysvq0asl const strlit_0_I173168012831799858_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-INF"}
;
LongString_0_sysvq0asl const strlit_0_I17332818319346761527_emi78vuj01 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowlc: bad expr node"}
;
LongString_0_sysvq0asl const strlit_0_I6041839086284145320_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bitnot"}
;
LongString_0_sysvq0asl const strlit_0_I13909093427330098489_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cast"}
;
LongString_0_sysvq0asl const strlit_0_I2501487269769466366_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "conv"}
;
LongString_0_sysvq0asl const strlit_0_I710932595938440230_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hconv"}
;
LongString_0_sysvq0asl const strlit_0_I4543393450896359795_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "baseobj"}
;
LongString_0_sysvq0asl const strlit_0_I5809186183819720447_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "onerr"}
;
LongString_0_sysvq0asl const strlit_0_I6487260469238205337_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "paren"}
;
LongString_0_sysvq0asl const strlit_0_I13798915436014509391_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "expr"}
;
LongString_0_sysvq0asl const strlit_0_I9557201018976274010_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "addr"}
;
LongString_0_sysvq0asl const strlit_0_I14042222260391466396_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sizeof"}
;
LongString_0_sysvq0asl const strlit_0_I14786653231029836613_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sizeof("}
;
LongString_0_sysvq0asl const strlit_0_I6690414846038512979_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "alignof"}
;
LongString_0_sysvq0asl const strlit_0_I8198489010515551214_emi78vuj01 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NIM_ALIGNOF("}
;
LongString_0_sysvq0asl const strlit_0_I10487743831055745770_emi78vuj01 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "LENGC_OVF_"}
;
LongString_0_sysvq0asl const strlit_0_I7763259150288237989_emi78vuj01 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowlc: unsupported expr \'"}
;
LongString_0_sysvq0asl const strlit_0_I17735862253056247523_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cursor"}
;
LongString_0_sysvq0asl const strlit_0_I2416437014800228590_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "result"}
;
LongString_0_sysvq0asl const strlit_0_I13752166055203769914_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "stmts"}
;
LongString_0_sysvq0asl const strlit_0_I110166545589372112_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "scope"}
;
LongString_0_sysvq0asl const strlit_0_I12999086881046019782_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "const"}
;
LongString_0_sysvq0asl const strlit_0_I880142495525408379_emi78vuj01 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static const "}
;
LongString_0_sysvq0asl const strlit_0_I2457206680275399171_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = {0}"}
;
LongString_0_sysvq0asl const strlit_0_I13424873862977158440_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "elif"}
;
LongString_0_sysvq0asl const strlit_0_I14854076524287435253_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "if ("}
;
LongString_0_sysvq0asl const strlit_0_I2222881345303884058_emi78vuj01 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " else if ("}
;
LongString_0_sysvq0asl const strlit_0_I4167480082662538754_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "else"}
;
LongString_0_sysvq0asl const strlit_0_I2561710370724821732_emi78vuj01 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " else {\012"}
;
LongString_0_sysvq0asl const strlit_0_I2767438444989370361_emi78vuj01 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "switch ("}
;
LongString_0_sysvq0asl const strlit_0_I10760563625686142994_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ranges"}
;
LongString_0_sysvq0asl const strlit_0_I16597999082088934835_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "range"}
;
LongString_0_sysvq0asl const strlit_0_I1967750273193337590_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "case "}
;
LongString_0_sysvq0asl const strlit_0_I11952777697407738927_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " ... "}
;
LongString_0_sysvq0asl const strlit_0_I1164491467687950421_emi78vuj01 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\012break;\012}\012"}
;
LongString_0_sysvq0asl const strlit_0_I5396197078431552478_emi78vuj01 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "default: {\012"}
;
LongString_0_sysvq0asl const strlit_0_I7451631847165411357_emi78vuj01 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__builtin_add_overflow"}
;
LongString_0_sysvq0asl const strlit_0_I10374958816402812404_emi78vuj01 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__builtin_sub_overflow"}
;
LongString_0_sysvq0asl const strlit_0_I12661504984193331701_emi78vuj01 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__builtin_mul_overflow"}
;
LongString_0_sysvq0asl const strlit_0_I16103378479668915775_emi78vuj01 = {
  .fullLen_0 = 31, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowlc: unsupported keepovf op \'"}
;
LongString_0_sysvq0asl const strlit_0_I11234898691155026843_emi78vuj01 = {
  .fullLen_0 = 43, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ")) { LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE; }"}
;
LongString_0_sysvq0asl const strlit_0_I1281801651151844468_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gvar"}
;
LongString_0_sysvq0asl const strlit_0_I5723805845286553140_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "glet"}
;
LongString_0_sysvq0asl const strlit_0_I13046452236886743244_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tvar"}
;
LongString_0_sysvq0asl const strlit_0_I2681092370707159476_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "asgn"}
;
LongString_0_sysvq0asl const strlit_0_I5487391404206283781_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "store"}
;
LongString_0_sysvq0asl const strlit_0_I4685521700204883275_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "return "}
;
LongString_0_sysvq0asl const strlit_0_I13276633450022896848_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "return;"}
;
LongString_0_sysvq0asl const strlit_0_I13200118161122656888_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "while"}
;
LongString_0_sysvq0asl const strlit_0_I10945407962990715491_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "while ("}
;
LongString_0_sysvq0asl const strlit_0_I5622496984824462814_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "loop"}
;
LongString_0_sysvq0asl const strlit_0_I539182870268293778_emi78vuj01 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "while (NIM_TRUE) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I13459072479819566868_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\012if (!("}
;
LongString_0_sysvq0asl const strlit_0_I159017457581697368_emi78vuj01 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ")) break;\012"}
;
LongString_0_sysvq0asl const strlit_0_I8380221545607033154_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "break"}
;
LongString_0_sysvq0asl const strlit_0_I13122058251689318351_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "break;"}
;
LongString_0_sysvq0asl const strlit_0_I2210116261907819816_emi78vuj01 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "continue"}
;
LongString_0_sysvq0asl const strlit_0_I9161030888050616993_emi78vuj01 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "continue;"}
;
LongString_0_sysvq0asl const strlit_0_I2956720964102846418_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "discard"}
;
LongString_0_sysvq0asl const strlit_0_I18295878950492138920_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(void)("}
;
LongString_0_sysvq0asl const strlit_0_I10005422671307457589_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "goto "}
;
LongString_0_sysvq0asl const strlit_0_I4956278306908871092_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "case"}
;
LongString_0_sysvq0asl const strlit_0_I6800807151669219983_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "keepovf"}
;
LongString_0_sysvq0asl const strlit_0_I6137881024046402116_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "raise"}
;
LongString_0_sysvq0asl const strlit_0_I5553614194453030385_emi78vuj01 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* raise */ (void)0;"}
;
LongString_0_sysvq0asl const strlit_0_I1572551130627868563_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "emit"}
;
LongString_0_sysvq0asl const strlit_0_I18257730313531980409_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "comment"}
;
LongString_0_sysvq0asl const strlit_0_I14941751896671455891_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "smry"}
;
LongString_0_sysvq0asl const strlit_0_I10785865655914555941_emi78vuj01 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowlc: unsupported stmt \'"}
;
LongString_0_sysvq0asl const strlit_0_I14150474136931533575_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "varargs"}
;
LongString_0_sysvq0asl const strlit_0_I11734088361827745870_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "inline"}
;
LongString_0_sysvq0asl const strlit_0_I13363476113935566349_emi78vuj01 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static inline "}
;
LongString_0_sysvq0asl const strlit_0_I10550632768111220399_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "const "}
;
LongString_0_sysvq0asl const strlit_0_I13598347493614872284_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " Q;\012"}
;
LongString_0_sysvq0asl const strlit_0_I3302612697625453930_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "union"}
;
LongString_0_sysvq0asl const strlit_0_I11734148202880076785_emi78vuj01 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "union {\012"}
;
LongString_0_sysvq0asl const strlit_0_I973692718279674627_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "object"}
;
LongString_0_sysvq0asl const strlit_0_I2377898382635629774_emi78vuj01 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "struct {\012"}
;
LongString_0_sysvq0asl const strlit_0_I10639822427173870573_emi78vuj01 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typedef union "}
;
LongString_0_sysvq0asl const strlit_0_I6078044050830967917_emi78vuj01 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " __attribute__((packed))"}
;
LongString_0_sysvq0asl const strlit_0_I3038304834379229130_emi78vuj01 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typedef "}
;
LongString_0_sysvq0asl const strlit_0_I2171368188661376471_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "efld"}
;
LongString_0_sysvq0asl const strlit_0_I11742995307374834148_emi78vuj01 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "#define "}
;
LongString_0_sysvq0asl const strlit_0_I9354196862430236195_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nodecl"}
;
LongString_0_sysvq0asl const strlit_0_I2341417231474813780_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "header"}
;
LongString_0_sysvq0asl const strlit_0_I17844812131497141662_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "packed"}
;
LongString_0_sysvq0asl const strlit_0_I5009490129652841634_emi78vuj01 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "]; } "}
;
LongString_0_sysvq0asl const strlit_0_I18345099547365871085_emi78vuj01 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mi_malloc"}
;
LongString_0_sysvq0asl const strlit_0_I1390764316392016455_emi78vuj01 = {
  .fullLen_0 = 58, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static void* mi_malloc(NU n) { return malloc((size_t)n); }"}
;
LongString_0_sysvq0asl const strlit_0_I12842777188212808440_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mi_free"}
;
LongString_0_sysvq0asl const strlit_0_I11654035052660406372_emi78vuj01 = {
  .fullLen_0 = 41, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static void mi_free(void* p) { free(p); }"}
;
LongString_0_sysvq0asl const strlit_0_I14462755268250863233_emi78vuj01 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mi_realloc"}
;
LongString_0_sysvq0asl const strlit_0_I4673220306063062360_emi78vuj01 = {
  .fullLen_0 = 72, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static void* mi_realloc(void* p, NU n) { return realloc(p, (size_t)n); }"}
;
LongString_0_sysvq0asl const strlit_0_I7117386163922528102_emi78vuj01 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mi_usable_size"}
;
LongString_0_sysvq0asl const strlit_0_I17194190520361290850_emi78vuj01 = {
  .fullLen_0 = 71, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static NU mi_usable_size(void* p) { return (NU)malloc_usable_size(p); }"}
;
LongString_0_sysvq0asl const strlit_0_I1974591037852052736_emi78vuj01 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<malloc.h>"}
;
LongString_0_sysvq0asl const strlit_0_I6581242055976388853_emi78vuj01 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<stdlib.h>"}
;
LongString_0_sysvq0asl const strlit_0_I14935256828133567672_emi78vuj01 = {
  .fullLen_0 = 59, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowlc: no top-level (stmts \342\200\246) found \342\200\224 is this a .c.nif\?"}
;
LongString_0_sysvq0asl const strlit_0_I5316556160589403975_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "proc"}
;
LongString_0_sysvq0asl const strlit_0_I9991102891510134496_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "func"}
;
LongString_0_sysvq0asl const strlit_0_I13413619771642637377_emi78vuj01 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "type"}
;
LongString_0_sysvq0asl const strlit_0_I2177770586444330071_emi78vuj01 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "union "}
;
LongString_0_sysvq0asl const strlit_0_I15036689029481705243_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "struct "}
;
LongString_0_sysvq0asl const strlit_0_I11931072057670428036_emi78vuj01 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "extern "}
;
LongString_0_sysvq0asl const strlit_0_I4048856184218363000_emi78vuj01 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "#include "}
;
LongString_0_sysvq0asl const strlit_0_I13990146375209994849_emi78vuj01 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "#include \""}
;
LongString_0_sysvq0asl const strlit_0_I8452133558184175204_emi78vuj01 = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- imported C headers --- */\012"}
;
LongString_0_sysvq0asl const strlit_0_I16941684571302003708_emi78vuj01 = {
  .fullLen_0 = 110, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- error/overflow flags --- */\012static _Thread_local NB8 LENGC_ERR_;\012static _Thread_local NB8 LENGC_OVF_;\012\012"}
;
LongString_0_sysvq0asl const strlit_0_I8169018483846267631_emi78vuj01 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- forward type declarations --- */\012"}
;
LongString_0_sysvq0asl const strlit_0_I4864334026181876568_emi78vuj01 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- types --- */\012"}
;
LongString_0_sysvq0asl const strlit_0_I3869532025073152017_emi78vuj01 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- prototypes --- */\012"}
;
LongString_0_sysvq0asl const strlit_0_I10565976826139702769_emi78vuj01 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- cross-module declarations --- */\012"}
;
LongString_0_sysvq0asl const strlit_0_I4664920264571878627_emi78vuj01 = {
  .fullLen_0 = 53, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- runtime provisions (no-header importc) --- */\012"}
;
LongString_0_sysvq0asl const strlit_0_I7195515648724051409_emi78vuj01 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- globals --- */\012"}
;
LongString_0_sysvq0asl const strlit_0_I18306971952939861040_emi78vuj01 = {
  .fullLen_0 = 46, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- cross-module inline definitions --- */\012"}
;
LongString_0_sysvq0asl const strlit_0_I7818278246678340207_emi78vuj01 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* --- procedures --- */\012"}
;
LongString_0_sysvq0asl const strlit_0_I1486236103788791016_emi78vuj01 = {
  .fullLen_0 = 60, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static void __attribute__((constructor)) aowlc_init(void) {\012"}
;
static string_0_sysvq0asl const HEX_0 = {
  .bytes_0 = 842084606u, .more_0 = (&strlit_0_I7901555537561129428_emi78vuj01)}
;
seq_0_Ixdx2fh1_aow7lb5cq1 externKeys_0_emi78vuj01;
seq_0_Ixdx2fh1_aow7lb5cq1 externVals_0_emi78vuj01;
seq_0_Ixdx2fh1_aow7lb5cq1 typeExternKeys_0_emi78vuj01;
seq_0_Ixdx2fh1_aow7lb5cq1 typeExternVals_0_emi78vuj01;
seq_0_Ixdx2fh1_aow7lb5cq1 noDeclTypes_0_emi78vuj01;
string_0_sysvq0asl ownMod_0_emi78vuj01 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
seq_0_Ixdx2fh1_aow7lb5cq1 loadedMods_0_emi78vuj01;
seq_0_Ixdx2fh1_aow7lb5cq1 siblingSuffixes_0_emi78vuj01;
NB8 siblingSuffixesLoaded_0_emi78vuj01 = NIM_FALSE;
seq_0_Ixdx2fh1_aow7lb5cq1 modProcKeys_0_emi78vuj01;
seq_0_Isutro81_emi78vuj01 modProcVals_0_emi78vuj01;
seq_0_Ixdx2fh1_aow7lb5cq1 modGlobalKeys_0_emi78vuj01;
seq_0_Isutro81_emi78vuj01 modGlobalVals_0_emi78vuj01;
seq_0_Ixdx2fh1_aow7lb5cq1 modTypeKeys_0_emi78vuj01;
seq_0_Isutro81_emi78vuj01 modTypeVals_0_emi78vuj01;
seq_0_Ixdx2fh1_aow7lb5cq1 checkedSuffixes_0_emi78vuj01;
string_0_sysvq0asl curResultVar_0_emi78vuj01 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
seq_0_Ixdx2fh1_aow7lb5cq1 otNames_0_emi78vuj01;
seq_0_Isutro81_emi78vuj01 otTypes_0_emi78vuj01;
seq_0_Isutro81_emi78vuj01 otOrder_0_emi78vuj01;
seq_0_Ixdx2fh1_aow7lb5cq1 otStateKeys_0_emi78vuj01;
seq_0_Ift2sne_aow7lb5cq1 otStateVals_0_emi78vuj01;
NB8 X60QiniGuard_0_emi78vuj01;
NB8 isList_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* n_0){
  NB8 result_1;
  NB8 X60Qx_50;
  if ((!(n_0 == NIM_NIL))){
    X60Qx_50 = ((*n_0).d_00.kind_0 == 3);}
  else {
    X60Qx_50 = NIM_FALSE;}
  result_1 = X60Qx_50;
  return result_1;}
NB8 isAtom_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* n_1){
  NB8 result_2;
  NB8 X60Qx_51;
  if ((!(n_1 == NIM_NIL))){
    X60Qx_51 = ((*n_1).d_00.kind_0 == 0);}
  else {
    X60Qx_51 = NIM_FALSE;}
  result_2 = X60Qx_51;
  return result_2;}
NB8 isDot_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* n_2){
  NB8 result_3;
  NB8 X60Qx_52;
  NB8 X60Qx_53 = isAtom_0_emi78vuj01(n_2);
  if (X60Qx_53){
    NB8 X60Qx_54 = eqQ_20_sysvq0asl((*n_2).d_00.atom_0, (string_0_sysvq0asl){
      .bytes_0 = 11777u, .more_0 = NIM_NIL}
    );
    X60Qx_52 = X60Qx_54;}
  else {
    X60Qx_52 = NIM_FALSE;}
  result_3 = X60Qx_52;
  return result_3;}
void fail_0_emi78vuj01(string_0_sysvq0asl msg_0){
  string_0_sysvq0asl X60Qtmp_0 = ampQ_0_sysvq0asl(msg_0, (string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  write_0_syn1lfpjv(stderr, X60Qtmp_0);
  quit_0_syn1lfpjv(1);
  nimStrDestroy(X60Qtmp_0);}
string_0_sysvq0asl myRepeat_0_emi78vuj01(string_0_sysvq0asl s_0, NI32 n_3){
  string_0_sysvq0asl result_4;
  nimStrWasMoved((&result_4));
  nimStrDestroy(result_4);
  result_4 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 i_0 = 0;
  {
    while (i_0 < n_3){
      add_2_sysvq0asl((&result_4), s_0);
      inc_1_I6wjjge_aow2h993l1((&i_0));}}
  whileStmtLabel_0: ;
  return result_4;}
string_0_sysvq0asl joinSeq_0_emi78vuj01(seq_0_Ixdx2fh1_aow7lb5cq1 xs_0, string_0_sysvq0asl sep_0){
  string_0_sysvq0asl result_5;
  nimStrWasMoved((&result_5));
  nimStrDestroy(result_5);
  result_5 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 first_0 = NIM_TRUE;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_0 = toOpenArray_1_I6b60gk1_aow7lb5cq1(xs_0);
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_55 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_55){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_0, X60Qlf_1);
            if ((!first_0)){
              add_2_sysvq0asl((&result_5), sep_0);}
            first_0 = NIM_FALSE;
            add_2_sysvq0asl((&result_5), (*X60Qii_2));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_5;}
seq_0_Ixdx2fh1_aow7lb5cq1 splitLinesNl_0_emi78vuj01(string_0_sysvq0asl s_1){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_6;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_6));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_6);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_56 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_6 = X60Qx_56;
  string_0_sysvq0asl cur_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_2 = toOpenArray_2_sysvq0asl((&s_1));
    NI32 X60Qlf_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_57 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_2);
        if (X60Qlf_3 < X60Qx_57){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_2, X60Qlf_3);
            if ((*X60Qii_2) == (NC8)'\012'){
              string_0_sysvq0asl X60Qtmp_1 = cur_0;
              nimStrWasMoved((&cur_0));
              add_0_Ig6072n_aow7lb5cq1((&result_6), X60Qtmp_1);
              nimStrDestroy(cur_0);
              cur_0 = (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              ;}
            else {
              add_1_sysvq0asl((&cur_0), (*X60Qii_2));}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qtmp_2 = cur_0;
  nimStrWasMoved((&cur_0));
  add_0_Ig6072n_aow7lb5cq1((&result_6), X60Qtmp_2);
  nimStrDestroy(cur_0);
  return result_6;
  nimStrDestroy(cur_0);
  return result_6;}
string_0_sysvq0asl stripBoth_0_emi78vuj01(string_0_sysvq0asl s_2){
  string_0_sysvq0asl result_7;
  nimStrWasMoved((&result_7));
  NI32 a_7 = 0;
  NI32 X60Qx_58 = len_4_sysvq0asl(s_2);
  NI32 b_0 = ((NI32)(X60Qx_58 - 1));
  {
    while (NIM_TRUE){
      NB8 X60Qx_59;
      if (a_7 <= b_0){
        NB8 X60Qx_60;
        NB8 X60Qx_61;
        NB8 X60Qx_62;
        NC8 X60Qx_63 = getQ_9_sysvq0asl(s_2, a_7);
        if (X60Qx_63 == (NC8)' '){
          X60Qx_62 = NIM_TRUE;}
        else {
          NC8 X60Qx_64 = getQ_9_sysvq0asl(s_2, a_7);
          X60Qx_62 = (X60Qx_64 == (NC8)'\011');}
        if (X60Qx_62){
          X60Qx_61 = NIM_TRUE;}
        else {
          NC8 X60Qx_65 = getQ_9_sysvq0asl(s_2, a_7);
          X60Qx_61 = (X60Qx_65 == (NC8)'\015');}
        if (X60Qx_61){
          X60Qx_60 = NIM_TRUE;}
        else {
          NC8 X60Qx_66 = getQ_9_sysvq0asl(s_2, a_7);
          X60Qx_60 = (X60Qx_66 == (NC8)'\012');}
        X60Qx_59 = X60Qx_60;}
      else {
        X60Qx_59 = NIM_FALSE;}
      if (X60Qx_59){
        inc_1_I6wjjge_aow2h993l1((&a_7));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  {
    while (NIM_TRUE){
      NB8 X60Qx_67;
      if (a_7 <= b_0){
        NB8 X60Qx_68;
        NB8 X60Qx_69;
        NB8 X60Qx_70;
        NC8 X60Qx_71 = getQ_9_sysvq0asl(s_2, b_0);
        if (X60Qx_71 == (NC8)' '){
          X60Qx_70 = NIM_TRUE;}
        else {
          NC8 X60Qx_72 = getQ_9_sysvq0asl(s_2, b_0);
          X60Qx_70 = (X60Qx_72 == (NC8)'\011');}
        if (X60Qx_70){
          X60Qx_69 = NIM_TRUE;}
        else {
          NC8 X60Qx_73 = getQ_9_sysvq0asl(s_2, b_0);
          X60Qx_69 = (X60Qx_73 == (NC8)'\015');}
        if (X60Qx_69){
          X60Qx_68 = NIM_TRUE;}
        else {
          NC8 X60Qx_74 = getQ_9_sysvq0asl(s_2, b_0);
          X60Qx_68 = (X60Qx_74 == (NC8)'\012');}
        X60Qx_67 = X60Qx_68;}
      else {
        X60Qx_67 = NIM_FALSE;}
      if (X60Qx_67){
        dec_1_I0nzoz91_aow7lb5cq1((&b_0));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  if (b_0 < a_7){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_75 = ___1_Iclcqmw1_aow7lb5cq1(a_7, b_0);
  string_0_sysvq0asl X60Qx_76 = getQ_14_sysvq0asl(s_2, X60Qx_75);
  result_7 = X60Qx_76;
  return result_7;
  return result_7;}
string_0_sysvq0asl beforeDot_0_emi78vuj01(string_0_sysvq0asl s_3){
  string_0_sysvq0asl result_8;
  nimStrWasMoved((&result_8));
  NI32 i_1 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_77;
      NI32 X60Qx_78 = len_4_sysvq0asl(s_3);
      if (i_1 < X60Qx_78){
        NC8 X60Qx_79 = getQ_9_sysvq0asl(s_3, i_1);
        X60Qx_77 = (!(X60Qx_79 == (NC8)'.'));}
      else {
        X60Qx_77 = NIM_FALSE;}
      if (X60Qx_77){
        inc_1_I6wjjge_aow2h993l1((&i_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_80 = __ltQ_1_Ij9jwi_dbgj4vyzj1(0, i_1);
  string_0_sysvq0asl X60Qx_81 = getQ_14_sysvq0asl(s_3, X60Qx_80);
  result_8 = X60Qx_81;
  return result_8;
  return result_8;}
NB8 oneOf_0_emi78vuj01(string_0_sysvq0asl s_4, openArray_0_Ig73pnk_aow7lb5cq1 xs_1){
  NB8 result_9;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_4 = xs_1;
    NI32 X60Qlf_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_82 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_4);
        if (X60Qlf_5 < X60Qx_82){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_4, X60Qlf_5);
            NB8 X60Qx_83 = eqQ_20_sysvq0asl((*X60Qii_2), s_4);
            if (X60Qx_83){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return NIM_FALSE;
  return result_9;}
string_0_sysvq0asl toOctal_0_emi78vuj01(NI32 n_4){
  string_0_sysvq0asl result_10;
  nimStrWasMoved((&result_10));
  if (n_4 == 0){
    return (string_0_sysvq0asl){
      .bytes_0 = 12289u, .more_0 = NIM_NIL}
    ;}
  NI32 v_2 = n_4;
  nimStrDestroy(result_10);
  result_10 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    while (0 < v_2){
      string_0_sysvq0asl d_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NC8 X60Qx_84 = chr_0_sysvq0asl(((NI32)(((NI32)(NC8)'0') + ((NI32)(v_2 % 8)))));
      add_1_sysvq0asl((&d_0), X60Qx_84);
      string_0_sysvq0asl X60Qlhs_3 = ampQ_0_sysvq0asl(d_0, result_10);
      nimStrDestroy(result_10);
      result_10 = X60Qlhs_3;
      v_2 = ((NI32)(v_2 / 8));
      nimStrDestroy(d_0);}}
  whileStmtLabel_0: ;
  return result_10;}
string_0_sysvq0asl toOctal3_0_emi78vuj01(NI32 n_5){
  string_0_sysvq0asl result_11;
  nimStrWasMoved((&result_11));
  string_0_sysvq0asl o_0 = toOctal_0_emi78vuj01(n_5);
  {
    while (NIM_TRUE){
      NI32 X60Qx_85 = len_4_sysvq0asl(o_0);
      if (X60Qx_85 < 3){
        string_0_sysvq0asl X60Qlhs_4 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 12289u, .more_0 = NIM_NIL}
        , o_0);
        nimStrDestroy(o_0);
        o_0 = X60Qlhs_4;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(result_11);
  result_11 = o_0;
  nimStrWasMoved((&o_0));
  nimStrDestroy(o_0);
  return result_11;
  nimStrDestroy(o_0);
  return result_11;}
NB8 isIntLit_0_emi78vuj01(string_0_sysvq0asl a_0){
  NB8 result_12;
  NI32 X60Qx_86 = len_4_sysvq0asl(a_0);
  if (X60Qx_86 == 0){
    return NIM_FALSE;}
  NI32 i_2 = 0;
  NC8 X60Qx_87 = getQ_9_sysvq0asl(a_0, 0);
  if (X60Qx_87 == (NC8)'-'){
    i_2 = 1;}
  NI32 X60Qx_88 = len_4_sysvq0asl(a_0);
  if (X60Qx_88 <= i_2){
    return NIM_FALSE;}
  {
    while (NIM_TRUE){
      NI32 X60Qx_89 = len_4_sysvq0asl(a_0);
      if (i_2 < X60Qx_89){
        NB8 X60Qx_90;
        NC8 X60Qx_91 = getQ_9_sysvq0asl(a_0, i_2);
        if (X60Qx_91 < (NC8)'0'){
          X60Qx_90 = NIM_TRUE;}
        else {
          NC8 X60Qx_92 = getQ_9_sysvq0asl(a_0, i_2);
          X60Qx_90 = ((NC8)'9' < X60Qx_92);}
        if (X60Qx_90){
          return NIM_FALSE;}
        inc_1_I6wjjge_aow2h993l1((&i_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return NIM_TRUE;
  return result_12;}
NB8 isUIntLit_0_emi78vuj01(string_0_sysvq0asl a_1){
  NB8 result_13;
  NI32 X60Qx_93 = len_4_sysvq0asl(a_1);
  if (X60Qx_93 == 0){
    return NIM_FALSE;}
  NI32 i_3 = 0;
  NB8 X60Qx_94;
  NC8 X60Qx_95 = getQ_9_sysvq0asl(a_1, i_3);
  if (X60Qx_95 < (NC8)'0'){
    X60Qx_94 = NIM_TRUE;}
  else {
    NC8 X60Qx_96 = getQ_9_sysvq0asl(a_1, i_3);
    X60Qx_94 = ((NC8)'9' < X60Qx_96);}
  if (X60Qx_94){
    return NIM_FALSE;}
  {
    while (NIM_TRUE){
      NB8 X60Qx_97;
      NB8 X60Qx_98;
      NI32 X60Qx_99 = len_4_sysvq0asl(a_1);
      if (i_3 < X60Qx_99){
        NC8 X60Qx_100 = getQ_9_sysvq0asl(a_1, i_3);
        X60Qx_98 = ((NC8)'0' <= X60Qx_100);}
      else {
        X60Qx_98 = NIM_FALSE;}
      if (X60Qx_98){
        NC8 X60Qx_101 = getQ_9_sysvq0asl(a_1, i_3);
        X60Qx_97 = (X60Qx_101 <= (NC8)'9');}
      else {
        X60Qx_97 = NIM_FALSE;}
      if (X60Qx_97){
        inc_1_I6wjjge_aow2h993l1((&i_3));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_102;
  NI32 X60Qx_103 = len_4_sysvq0asl(a_1);
  if (X60Qx_103 <= i_3){
    X60Qx_102 = NIM_TRUE;}
  else {
    NC8 X60Qx_104 = getQ_9_sysvq0asl(a_1, i_3);
    X60Qx_102 = (!(X60Qx_104 == (NC8)'u'));}
  if (X60Qx_102){
    return NIM_FALSE;}
  inc_1_I6wjjge_aow2h993l1((&i_3));
  NI32 X60Qx_105 = len_4_sysvq0asl(a_1);
  if (i_3 == X60Qx_105){
    return NIM_TRUE;}
  NC8 X60Qx_106 = getQ_9_sysvq0asl(a_1, i_3);
  if (X60Qx_106 == (NC8)'l'){
    inc_1_I6wjjge_aow2h993l1((&i_3));
    NI32 X60Qx_107 = len_4_sysvq0asl(a_1);
    if (i_3 == X60Qx_107){
      return NIM_TRUE;}
    NC8 X60Qx_108 = getQ_9_sysvq0asl(a_1, i_3);
    if (X60Qx_108 == (NC8)'l'){
      inc_1_I6wjjge_aow2h993l1((&i_3));
      NI32 X60Qx_109 = len_4_sysvq0asl(a_1);
      result_13 = (i_3 == X60Qx_109);
      return result_13;}
    return NIM_FALSE;}
  return NIM_FALSE;
  return result_13;}
NB8 isFloatLit_0_emi78vuj01(string_0_sysvq0asl a_2){
  NB8 result_14;
  NI32 X60Qx_110 = len_4_sysvq0asl(a_2);
  if (X60Qx_110 == 0){
    return NIM_FALSE;}
  NI32 i_4 = 0;
  NC8 X60Qx_111 = getQ_9_sysvq0asl(a_2, i_4);
  if (X60Qx_111 == (NC8)'-'){
    inc_1_I6wjjge_aow2h993l1((&i_4));}
  NB8 sawDigit_0 = NIM_FALSE;
  {
    while (NIM_TRUE){
      NB8 X60Qx_112;
      NB8 X60Qx_113;
      NI32 X60Qx_114 = len_4_sysvq0asl(a_2);
      if (i_4 < X60Qx_114){
        NC8 X60Qx_115 = getQ_9_sysvq0asl(a_2, i_4);
        X60Qx_113 = ((NC8)'0' <= X60Qx_115);}
      else {
        X60Qx_113 = NIM_FALSE;}
      if (X60Qx_113){
        NC8 X60Qx_116 = getQ_9_sysvq0asl(a_2, i_4);
        X60Qx_112 = (X60Qx_116 <= (NC8)'9');}
      else {
        X60Qx_112 = NIM_FALSE;}
      if (X60Qx_112){
        inc_1_I6wjjge_aow2h993l1((&i_4));
        sawDigit_0 = NIM_TRUE;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_117;
  NI32 X60Qx_118 = len_4_sysvq0asl(a_2);
  if (i_4 < X60Qx_118){
    NC8 X60Qx_119 = getQ_9_sysvq0asl(a_2, i_4);
    X60Qx_117 = (X60Qx_119 == (NC8)'.');}
  else {
    X60Qx_117 = NIM_FALSE;}
  if (X60Qx_117){
    inc_1_I6wjjge_aow2h993l1((&i_4));
    {
      while (NIM_TRUE){
        NB8 X60Qx_120;
        NB8 X60Qx_121;
        NI32 X60Qx_122 = len_4_sysvq0asl(a_2);
        if (i_4 < X60Qx_122){
          NC8 X60Qx_123 = getQ_9_sysvq0asl(a_2, i_4);
          X60Qx_121 = ((NC8)'0' <= X60Qx_123);}
        else {
          X60Qx_121 = NIM_FALSE;}
        if (X60Qx_121){
          NC8 X60Qx_124 = getQ_9_sysvq0asl(a_2, i_4);
          X60Qx_120 = (X60Qx_124 <= (NC8)'9');}
        else {
          X60Qx_120 = NIM_FALSE;}
        if (X60Qx_120){
          inc_1_I6wjjge_aow2h993l1((&i_4));
          sawDigit_0 = NIM_TRUE;}
        else {
          break;}}}
    whileStmtLabel_1: ;
    if ((!sawDigit_0)){
      return NIM_FALSE;}}
  else {
    if ((!sawDigit_0)){
      return NIM_FALSE;}}
  NB8 X60Qx_125;
  NI32 X60Qx_126 = len_4_sysvq0asl(a_2);
  if (i_4 < X60Qx_126){
    NB8 X60Qx_127;
    NC8 X60Qx_128 = getQ_9_sysvq0asl(a_2, i_4);
    if (X60Qx_128 == (NC8)'e'){
      X60Qx_127 = NIM_TRUE;}
    else {
      NC8 X60Qx_129 = getQ_9_sysvq0asl(a_2, i_4);
      X60Qx_127 = (X60Qx_129 == (NC8)'E');}
    X60Qx_125 = X60Qx_127;}
  else {
    X60Qx_125 = NIM_FALSE;}
  if (X60Qx_125){
    inc_1_I6wjjge_aow2h993l1((&i_4));
    NB8 X60Qx_130;
    NI32 X60Qx_131 = len_4_sysvq0asl(a_2);
    if (i_4 < X60Qx_131){
      NB8 X60Qx_132;
      NC8 X60Qx_133 = getQ_9_sysvq0asl(a_2, i_4);
      if (X60Qx_133 == (NC8)'+'){
        X60Qx_132 = NIM_TRUE;}
      else {
        NC8 X60Qx_134 = getQ_9_sysvq0asl(a_2, i_4);
        X60Qx_132 = (X60Qx_134 == (NC8)'-');}
      X60Qx_130 = X60Qx_132;}
    else {
      X60Qx_130 = NIM_FALSE;}
    if (X60Qx_130){
      inc_1_I6wjjge_aow2h993l1((&i_4));}
    NI32 X60Qx_135 = len_4_sysvq0asl(a_2);
    if (X60Qx_135 <= i_4){
      return NIM_FALSE;}
    NB8 esaw_0 = NIM_FALSE;
    {
      while (NIM_TRUE){
        NB8 X60Qx_136;
        NB8 X60Qx_137;
        NI32 X60Qx_138 = len_4_sysvq0asl(a_2);
        if (i_4 < X60Qx_138){
          NC8 X60Qx_139 = getQ_9_sysvq0asl(a_2, i_4);
          X60Qx_137 = ((NC8)'0' <= X60Qx_139);}
        else {
          X60Qx_137 = NIM_FALSE;}
        if (X60Qx_137){
          NC8 X60Qx_140 = getQ_9_sysvq0asl(a_2, i_4);
          X60Qx_136 = (X60Qx_140 <= (NC8)'9');}
        else {
          X60Qx_136 = NIM_FALSE;}
        if (X60Qx_136){
          inc_1_I6wjjge_aow2h993l1((&i_4));
          esaw_0 = NIM_TRUE;}
        else {
          break;}}}
    whileStmtLabel_2: ;
    if ((!esaw_0)){
      return NIM_FALSE;}}
  NI32 X60Qx_141 = len_4_sysvq0asl(a_2);
  if ((!(i_4 == X60Qx_141))){
    return NIM_FALSE;}
  {
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_6 = toOpenArray_2_sysvq0asl((&a_2));
    NI32 X60Qlf_7 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_142 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_6);
        if (X60Qlf_7 < X60Qx_142){
          {
            NC8* X60Qii_5 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_6, X60Qlf_7);
            NB8 X60Qx_143;
            NB8 X60Qx_144;
            if ((*X60Qii_5) == (NC8)'.'){
              X60Qx_144 = NIM_TRUE;}
            else {
              X60Qx_144 = ((*X60Qii_5) == (NC8)'e');}
            if (X60Qx_144){
              X60Qx_143 = NIM_TRUE;}
            else {
              X60Qx_143 = ((*X60Qii_5) == (NC8)'E');}
            if (X60Qx_143){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
        else {
          break;}}}
    whileStmtLabel_4: ;}
  forStmtLabel_3: ;
  return NIM_FALSE;
  return result_14;}
NI64 parseI64_0_emi78vuj01(string_0_sysvq0asl s_5){
  NI64 result_15;
  NI32 i_5 = 0;
  NB8 neg_0 = NIM_FALSE;
  NB8 X60Qx_145;
  NI32 X60Qx_146 = len_4_sysvq0asl(s_5);
  if (i_5 < X60Qx_146){
    NC8 X60Qx_147 = getQ_9_sysvq0asl(s_5, i_5);
    X60Qx_145 = (X60Qx_147 == (NC8)'-');}
  else {
    X60Qx_145 = NIM_FALSE;}
  if (X60Qx_145){
    neg_0 = NIM_TRUE;
    inc_1_I6wjjge_aow2h993l1((&i_5));}
  NI64 v_3 = ((NI64)0);
  {
    while (NIM_TRUE){
      NB8 X60Qx_148;
      NB8 X60Qx_149;
      NI32 X60Qx_150 = len_4_sysvq0asl(s_5);
      if (i_5 < X60Qx_150){
        NC8 X60Qx_151 = getQ_9_sysvq0asl(s_5, i_5);
        X60Qx_149 = ((NC8)'0' <= X60Qx_151);}
      else {
        X60Qx_149 = NIM_FALSE;}
      if (X60Qx_149){
        NC8 X60Qx_152 = getQ_9_sysvq0asl(s_5, i_5);
        X60Qx_148 = (X60Qx_152 <= (NC8)'9');}
      else {
        X60Qx_148 = NIM_FALSE;}
      if (X60Qx_148){
        NC8 X60Qx_153 = getQ_9_sysvq0asl(s_5, i_5);
        v_3 = ((NI64)(((NI64)(v_3 * ((NI64)10))) + ((NI64)((NI32)(((NI32)X60Qx_153) - ((NI32)(NC8)'0'))))));
        inc_1_I6wjjge_aow2h993l1((&i_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (neg_0){
    result_15 = ((NI64)-v_3);
    return result_15;}
  return v_3;
  return result_15;}
NU64 parseU64_0_emi78vuj01(string_0_sysvq0asl s_6){
  NU64 result_16;
  NI32 i_6 = 0;
  NU64 v_4 = ((NU64)0);
  {
    while (NIM_TRUE){
      NB8 X60Qx_154;
      NB8 X60Qx_155;
      NI32 X60Qx_156 = len_4_sysvq0asl(s_6);
      if (i_6 < X60Qx_156){
        NC8 X60Qx_157 = getQ_9_sysvq0asl(s_6, i_6);
        X60Qx_155 = ((NC8)'0' <= X60Qx_157);}
      else {
        X60Qx_155 = NIM_FALSE;}
      if (X60Qx_155){
        NC8 X60Qx_158 = getQ_9_sysvq0asl(s_6, i_6);
        X60Qx_154 = (X60Qx_158 <= (NC8)'9');}
      else {
        X60Qx_154 = NIM_FALSE;}
      if (X60Qx_154){
        NC8 X60Qx_159 = getQ_9_sysvq0asl(s_6, i_6);
        v_4 = ((NU64)(((NU64)(v_4 * ((NU64)10u))) + ((NU64)((NI32)(((NI32)X60Qx_159) - ((NI32)(NC8)'0'))))));
        inc_1_I6wjjge_aow2h993l1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return v_4;
  return result_16;}
string_0_sysvq0asl genIntLit_0_emi78vuj01(string_0_sysvq0asl a_3){
  string_0_sysvq0asl result_17;
  nimStrWasMoved((&result_17));
  NB8 X60Qx_160 = eqQ_20_sysvq0asl(a_3, (string_0_sysvq0asl){
    .bytes_0 = 842608126u, .more_0 = (&strlit_0_I1493431938208774112_emi78vuj01)}
  );
  if (X60Qx_160){
    return (string_0_sysvq0asl){
      .bytes_0 = 959260926u, .more_0 = (&strlit_0_I11180947211213179806_emi78vuj01)}
    ;}
  NI64 v_5 = parseI64_0_emi78vuj01(a_3);
  NB8 X60Qx_161;
  if (((NI64)(-2147483647 -1)) <= v_5){
    X60Qx_161 = (v_5 <= ((NI64)2147483647));}
  else {
    X60Qx_161 = NIM_FALSE;}
  if (X60Qx_161){
    string_0_sysvq0asl X60Qx_162 = dollarQ_1_sysvq0asl(v_5);
    result_17 = X60Qx_162;
    return result_17;}
  string_0_sysvq0asl X60Qtmp_5 = dollarQ_1_sysvq0asl(v_5);
  string_0_sysvq0asl X60Qx_163 = ampQ_0_sysvq0asl(X60Qtmp_5, (string_0_sysvq0asl){
    .bytes_0 = 5000194u, .more_0 = NIM_NIL}
  );
  result_17 = X60Qx_163;
  nimStrDestroy(X60Qtmp_5);
  return result_17;
  nimStrDestroy(X60Qtmp_5);
  return result_17;
  nimStrDestroy(X60Qtmp_5);
  return result_17;}
string_0_sysvq0asl genUIntLit_0_emi78vuj01(string_0_sysvq0asl a_4){
  string_0_sysvq0asl result_18;
  nimStrWasMoved((&result_18));
  NI32 n_11 = len_4_sysvq0asl(a_4);
  {
    while (NIM_TRUE){
      NB8 X60Qx_164;
      if (0 < n_11){
        NB8 X60Qx_165;
        NC8 X60Qx_166 = getQ_9_sysvq0asl(a_4, ((NI32)(n_11 - 1)));
        if (X60Qx_166 == (NC8)'l'){
          X60Qx_165 = NIM_TRUE;}
        else {
          NC8 X60Qx_167 = getQ_9_sysvq0asl(a_4, ((NI32)(n_11 - 1)));
          X60Qx_165 = (X60Qx_167 == (NC8)'L');}
        X60Qx_164 = X60Qx_165;}
      else {
        X60Qx_164 = NIM_FALSE;}
      if (X60Qx_164){
        dec_1_I0nzoz91_aow7lb5cq1((&n_11));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_168;
  if (0 < n_11){
    NB8 X60Qx_169;
    NC8 X60Qx_170 = getQ_9_sysvq0asl(a_4, ((NI32)(n_11 - 1)));
    if (X60Qx_170 == (NC8)'u'){
      X60Qx_169 = NIM_TRUE;}
    else {
      NC8 X60Qx_171 = getQ_9_sysvq0asl(a_4, ((NI32)(n_11 - 1)));
      X60Qx_169 = (X60Qx_171 == (NC8)'U');}
    X60Qx_168 = X60Qx_169;}
  else {
    X60Qx_168 = NIM_FALSE;}
  if (X60Qx_168){
    dec_1_I0nzoz91_aow7lb5cq1((&n_11));}
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_172 = __ltQ_1_Ij9jwi_dbgj4vyzj1(0, n_11);
  string_0_sysvq0asl digits_0 = getQ_14_sysvq0asl(a_4, X60Qx_172);
  NU64 v_6 = parseU64_0_emi78vuj01(digits_0);
  if (v_6 <= ((NU64)4294967295u)){
    string_0_sysvq0asl X60Qtmp_6 = dollarQ_0_sysvq0asl(v_6);
    string_0_sysvq0asl X60Qx_173 = ampQ_0_sysvq0asl(X60Qtmp_6, (string_0_sysvq0asl){
      .bytes_0 = 29953u, .more_0 = NIM_NIL}
    );
    result_18 = X60Qx_173;
    nimStrDestroy(X60Qtmp_6);
    nimStrDestroy(digits_0);
    return result_18;
    nimStrDestroy(X60Qtmp_6);}
  string_0_sysvq0asl X60Qtmp_7 = dollarQ_0_sysvq0asl(v_6);
  string_0_sysvq0asl X60Qx_174 = ampQ_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
    .bytes_0 = 1819047171u, .more_0 = NIM_NIL}
  );
  result_18 = X60Qx_174;
  nimStrDestroy(X60Qtmp_7);
  nimStrDestroy(digits_0);
  return result_18;
  nimStrDestroy(X60Qtmp_7);
  nimStrDestroy(digits_0);
  return result_18;
  nimStrDestroy(X60Qtmp_7);
  nimStrDestroy(digits_0);
  return result_18;}
string_0_sysvq0asl escapeChar_0_emi78vuj01(NC8 ch_0){
  string_0_sysvq0asl result_19;
  nimStrWasMoved((&result_19));
  NI32 nn_0 = ((NI32)ch_0);
  nimStrDestroy(result_19);
  result_19 = (string_0_sysvq0asl){
    .bytes_0 = 22529u, .more_0 = NIM_NIL}
  ;
  NC8 X60Qx_175 = getQ_9_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 842084606u, .more_0 = (&strlit_0_I7901555537561129428_emi78vuj01)}
  , ((NI32)(((NI32)(((NI32)nn_0) >> ((NU32)4))) & 15)));
  add_1_sysvq0asl((&result_19), X60Qx_175);
  NC8 X60Qx_176 = getQ_9_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 842084606u, .more_0 = (&strlit_0_I7901555537561129428_emi78vuj01)}
  , ((NI32)(nn_0 & 15)));
  add_1_sysvq0asl((&result_19), X60Qx_176);
  add_1_sysvq0asl((&result_19), (NC8)'Q');
  return result_19;}
string_0_sysvq0asl mangleToC_0_emi78vuj01(string_0_sysvq0asl s_7){
  string_0_sysvq0asl result_20;
  nimStrWasMoved((&result_20));
  nimStrDestroy(result_20);
  result_20 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 i_7 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_177 = len_4_sysvq0asl(s_7);
      if (i_7 < X60Qx_177){
        NC8 c_2 = getQ_9_sysvq0asl(s_7, i_7);
        NB8 X60Qx_178;
        NB8 X60Qx_179;
        NB8 X60Qx_180;
        NB8 X60Qx_181;
        if ((NC8)'A' <= c_2){
          X60Qx_181 = (c_2 <= (NC8)'P');}
        else {
          X60Qx_181 = NIM_FALSE;}
        if (X60Qx_181){
          X60Qx_180 = NIM_TRUE;}
        else {
          NB8 X60Qx_182;
          if ((NC8)'R' <= c_2){
            X60Qx_182 = (c_2 <= (NC8)'Z');}
          else {
            X60Qx_182 = NIM_FALSE;}
          X60Qx_180 = X60Qx_182;}
        if (X60Qx_180){
          X60Qx_179 = NIM_TRUE;}
        else {
          NB8 X60Qx_183;
          if ((NC8)'a' <= c_2){
            X60Qx_183 = (c_2 <= (NC8)'z');}
          else {
            X60Qx_183 = NIM_FALSE;}
          X60Qx_179 = X60Qx_183;}
        if (X60Qx_179){
          X60Qx_178 = NIM_TRUE;}
        else {
          NB8 X60Qx_184;
          if ((NC8)'0' <= c_2){
            X60Qx_184 = (c_2 <= (NC8)'9');}
          else {
            X60Qx_184 = NIM_FALSE;}
          X60Qx_178 = X60Qx_184;}
        if (X60Qx_178){
          add_1_sysvq0asl((&result_20), c_2);}
        else {
          if (c_2 == (NC8)'Q'){
            add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
              .bytes_0 = 5329154u, .more_0 = NIM_NIL}
            );}
          else {
            if (c_2 == (NC8)'_'){
              add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                .bytes_0 = 6246658u, .more_0 = NIM_NIL}
              );}
            else {
              if (c_2 == (NC8)'.'){
                add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                  .bytes_0 = 24321u, .more_0 = NIM_NIL}
                );}
              else {
                if (c_2 == (NC8)'['){
                  NB8 X60Qx_185;
                  NI32 X60Qx_186 = len_4_sysvq0asl(s_7);
                  if (((NI32)(i_7 + 1)) < X60Qx_186){
                    NC8 X60Qx_187 = getQ_9_sysvq0asl(s_7, ((NI32)(i_7 + 1)));
                    X60Qx_185 = (X60Qx_187 == (NC8)']');}
                  else {
                    X60Qx_185 = NIM_FALSE;}
                  if (X60Qx_185){
                    NB8 X60Qx_188;
                    NI32 X60Qx_189 = len_4_sysvq0asl(s_7);
                    if (((NI32)(i_7 + 2)) < X60Qx_189){
                      NC8 X60Qx_190 = getQ_9_sysvq0asl(s_7, ((NI32)(i_7 + 2)));
                      X60Qx_188 = (X60Qx_190 == (NC8)'=');}
                    else {
                      X60Qx_188 = NIM_FALSE;}
                    if (X60Qx_188){
                      add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                        .bytes_0 = 1953853694u, .more_0 = (&strlit_0_I5839537462929284299_emi78vuj01)}
                      );
                      plusQeQ_0_Iz7fdp7_emi78vuj01((&i_7), 2);}
                    else {
                      add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                        .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I3587198974648410474_emi78vuj01)}
                      );
                      plusQeQ_0_Iz7fdp7_emi78vuj01((&i_7), 1);}}
                  else {
                    string_0_sysvq0asl X60Qtmp_8 = escapeChar_0_emi78vuj01(c_2);
                    add_2_sysvq0asl((&result_20), X60Qtmp_8);
                    nimStrDestroy(X60Qtmp_8);}}
                else {
                  if (c_2 == (NC8)'='){
                    NB8 X60Qx_191;
                    NI32 X60Qx_192 = len_4_sysvq0asl(s_7);
                    if (((NI32)(i_7 + 1)) < X60Qx_192){
                      NC8 X60Qx_193 = getQ_9_sysvq0asl(s_7, ((NI32)(i_7 + 1)));
                      X60Qx_191 = (X60Qx_193 == (NC8)'=');}
                    else {
                      X60Qx_191 = NIM_FALSE;}
                    if (X60Qx_191){
                      add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                        .bytes_0 = 1366385923u, .more_0 = NIM_NIL}
                      );
                      inc_1_I6wjjge_aow2h993l1((&i_7));}
                    else {
                      add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                        .bytes_0 = 5334274u, .more_0 = NIM_NIL}
                      );}}
                  else {
                    if (c_2 == (NC8)'<'){
                      NB8 X60Qx_194;
                      NI32 X60Qx_195 = len_4_sysvq0asl(s_7);
                      if (((NI32)(i_7 + 1)) < X60Qx_195){
                        NC8 X60Qx_196 = getQ_9_sysvq0asl(s_7, ((NI32)(i_7 + 1)));
                        X60Qx_194 = (X60Qx_196 == (NC8)'=');}
                      else {
                        X60Qx_194 = NIM_FALSE;}
                      if (X60Qx_194){
                        add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                          .bytes_0 = 1365601283u, .more_0 = NIM_NIL}
                        );
                        inc_1_I6wjjge_aow2h993l1((&i_7));}
                      else {
                        add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                          .bytes_0 = 1366584323u, .more_0 = NIM_NIL}
                        );}}
                    else {
                      if (c_2 == (NC8)'>'){
                        NB8 X60Qx_197;
                        NI32 X60Qx_198 = len_4_sysvq0asl(s_7);
                        if (((NI32)(i_7 + 1)) < X60Qx_198){
                          NC8 X60Qx_199 = getQ_9_sysvq0asl(s_7, ((NI32)(i_7 + 1)));
                          X60Qx_197 = (X60Qx_199 == (NC8)'=');}
                        else {
                          X60Qx_197 = NIM_FALSE;}
                        if (X60Qx_197){
                          add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                            .bytes_0 = 1365600003u, .more_0 = NIM_NIL}
                          );
                          inc_1_I6wjjge_aow2h993l1((&i_7));}
                        else {
                          add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                            .bytes_0 = 1366583043u, .more_0 = NIM_NIL}
                          );}}
                      else {
                        if (c_2 == (NC8)'$'){
                          add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                            .bytes_0 = 1819239678u, .more_0 = (&strlit_0_I6001479237466573771_emi78vuj01)}
                          );}
                        else {
                          if (c_2 == (NC8)'%'){
                            add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                              .bytes_0 = 1919250686u, .more_0 = (&strlit_0_I9794172738743734741_emi78vuj01)}
                            );}
                          else {
                            if (c_2 == (NC8)'&'){
                              add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                .bytes_0 = 1886216702u, .more_0 = (&strlit_0_I4549956430263353259_emi78vuj01)}
                              );}
                            else {
                              if (c_2 == (NC8)'^'){
                                add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                  .bytes_0 = 1869574910u, .more_0 = (&strlit_0_I6324820878088668721_emi78vuj01)}
                                );}
                              else {
                                if (c_2 == (NC8)'!'){
                                  add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                    .bytes_0 = 1634559486u, .more_0 = (&strlit_0_I5022937532488303155_emi78vuj01)}
                                  );}
                                else {
                                  if (c_2 == (NC8)'\?'){
                                    add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                      .bytes_0 = 1634562558u, .more_0 = (&strlit_0_I3040189447710877908_emi78vuj01)}
                                    );}
                                  else {
                                    if (c_2 == (NC8)'*'){
                                      add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                        .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I17986771364525673239_emi78vuj01)}
                                      );}
                                    else {
                                      if (c_2 == (NC8)'+'){
                                        add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                          .bytes_0 = 1970041086u, .more_0 = (&strlit_0_I3209885551604274897_emi78vuj01)}
                                        );}
                                      else {
                                        if (c_2 == (NC8)'-'){
                                          add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                            .bytes_0 = 1852403198u, .more_0 = (&strlit_0_I8120334580135717506_emi78vuj01)}
                                          );}
                                        else {
                                          if (c_2 == (NC8)'/'){
                                            add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                              .bytes_0 = 1634497534u, .more_0 = (&strlit_0_I9829284319393728878_emi78vuj01)}
                                            );}
                                          else {
                                            if (c_2 == (NC8)'\\'){
                                              add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                                .bytes_0 = 1819501310u, .more_0 = (&strlit_0_I10077072016029657701_emi78vuj01)}
                                              );}
                                            else {
                                              if (c_2 == (NC8)'~'){
                                                add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                                  .bytes_0 = 1818850558u, .more_0 = (&strlit_0_I16101758279297810961_emi78vuj01)}
                                                );}
                                              else {
                                                if (c_2 == (NC8)':'){
                                                  add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                                    .bytes_0 = 1819239422u, .more_0 = (&strlit_0_I16015100509361966772_emi78vuj01)}
                                                  );}
                                                else {
                                                  if (c_2 == (NC8)'@'){
                                                    add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                                      .bytes_0 = 1366581507u, .more_0 = NIM_NIL}
                                                    );}
                                                  else {
                                                    if (c_2 == (NC8)'|'){
                                                      add_2_sysvq0asl((&result_20), (string_0_sysvq0asl){
                                                        .bytes_0 = 1918984958u, .more_0 = (&strlit_0_I5416429193604338878_emi78vuj01)}
                                                      );}
                                                    else {
                                                      string_0_sysvq0asl X60Qtmp_9 = escapeChar_0_emi78vuj01(c_2);
                                                      add_2_sysvq0asl((&result_20), X60Qtmp_9);
                                                      nimStrDestroy(X60Qtmp_9);}}}}}}}}}}}}}}}}}}}}}}}
        inc_1_I6wjjge_aow2h993l1((&i_7));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_20;}
string_0_sysvq0asl makeCString_0_emi78vuj01(string_0_sysvq0asl s_8){
  string_0_sysvq0asl result_21;
  nimStrWasMoved((&result_21));
  nimStrDestroy(result_21);
  result_21 = (string_0_sysvq0asl){
    .bytes_0 = 8705u, .more_0 = NIM_NIL}
  ;
  {
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_8 = toOpenArray_2_sysvq0asl((&s_8));
    NI32 X60Qlf_9 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_200 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_8);
        if (X60Qlf_9 < X60Qx_200){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_8, X60Qlf_9);
            NI32 X60Qii_3 = ((NI32)(*X60Qii_2));
            NB8 X60Qx_201;
            NB8 X60Qx_202;
            if (0 <= X60Qii_3){
              X60Qx_202 = (X60Qii_3 <= 31);}
            else {
              X60Qx_202 = NIM_FALSE;}
            if (X60Qx_202){
              X60Qx_201 = NIM_TRUE;}
            else {
              X60Qx_201 = (127 <= X60Qii_3);}
            if (X60Qx_201){
              add_2_sysvq0asl((&result_21), (string_0_sysvq0asl){
                .bytes_0 = 23553u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qtmp_10 = toOctal3_0_emi78vuj01(X60Qii_3);
              add_2_sysvq0asl((&result_21), X60Qtmp_10);
              nimStrDestroy(X60Qtmp_10);}
            else {
              NB8 X60Qx_203;
              NB8 X60Qx_204;
              NB8 X60Qx_205;
              if ((*X60Qii_2) == (NC8)'\''){
                X60Qx_205 = NIM_TRUE;}
              else {
                X60Qx_205 = ((*X60Qii_2) == (NC8)'\"');}
              if (X60Qx_205){
                X60Qx_204 = NIM_TRUE;}
              else {
                X60Qx_204 = ((*X60Qii_2) == (NC8)'\\');}
              if (X60Qx_204){
                X60Qx_203 = NIM_TRUE;}
              else {
                X60Qx_203 = ((*X60Qii_2) == (NC8)'\?');}
              if (X60Qx_203){
                add_2_sysvq0asl((&result_21), (string_0_sysvq0asl){
                  .bytes_0 = 23553u, .more_0 = NIM_NIL}
                );
                add_1_sysvq0asl((&result_21), (*X60Qii_2));}
              else {
                add_1_sysvq0asl((&result_21), (*X60Qii_2));}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  add_2_sysvq0asl((&result_21), (string_0_sysvq0asl){
    .bytes_0 = 8705u, .more_0 = NIM_NIL}
  );
  return result_21;}
string_0_sysvq0asl toCCharLit_0_emi78vuj01(NI32 code_0){
  string_0_sysvq0asl result_22;
  nimStrWasMoved((&result_22));
  NB8 X60Qx_206;
  NB8 X60Qx_207;
  if (0 <= code_0){
    X60Qx_207 = (code_0 <= 31);}
  else {
    X60Qx_207 = NIM_FALSE;}
  if (X60Qx_207){
    X60Qx_206 = NIM_TRUE;}
  else {
    X60Qx_206 = (127 <= code_0);}
  if (X60Qx_206){
    string_0_sysvq0asl X60Qdesugar_0 = toOctal_0_emi78vuj01(code_0);
    NI32 X60Qx_208 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 6039298u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_209 = len_4_sysvq0asl(X60Qdesugar_0);
    NI32 X60Qx_210 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_208 + X60Qx_209)) + X60Qx_210)));
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 6039298u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), X60Qdesugar_0);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_11 = X60Qdesugar_1;
    nimStrWasMoved((&X60Qdesugar_1));
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);
    return X60Qtmp_11;
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);}
  NC8 ch_4 = chr_0_sysvq0asl(code_0);
  NB8 X60Qx_211;
  NB8 X60Qx_212;
  NB8 X60Qx_213;
  if (ch_4 == (NC8)'\''){
    X60Qx_213 = NIM_TRUE;}
  else {
    X60Qx_213 = (ch_4 == (NC8)'\"');}
  if (X60Qx_213){
    X60Qx_212 = NIM_TRUE;}
  else {
    X60Qx_212 = (ch_4 == (NC8)'\\');}
  if (X60Qx_212){
    X60Qx_211 = NIM_TRUE;}
  else {
    X60Qx_211 = (ch_4 == (NC8)'\?');}
  if (X60Qx_211){
    string_0_sysvq0asl X60Qtmp_12 = ampQ_1_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 6039298u, .more_0 = NIM_NIL}
    , ch_4);
    string_0_sysvq0asl X60Qx_214 = ampQ_0_sysvq0asl(X60Qtmp_12, (string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    result_22 = X60Qx_214;
    nimStrDestroy(X60Qtmp_12);
    return result_22;
    nimStrDestroy(X60Qtmp_12);}
  string_0_sysvq0asl X60Qtmp_13 = ampQ_1_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 9985u, .more_0 = NIM_NIL}
  , ch_4);
  string_0_sysvq0asl X60Qx_215 = ampQ_0_sysvq0asl(X60Qtmp_13, (string_0_sysvq0asl){
    .bytes_0 = 9985u, .more_0 = NIM_NIL}
  );
  result_22 = X60Qx_215;
  nimStrDestroy(X60Qtmp_13);
  return result_22;
  nimStrDestroy(X60Qtmp_13);
  return result_22;
  nimStrDestroy(X60Qtmp_13);
  return result_22;}
string_0_sysvq0asl typedBinOp_0_emi78vuj01(string_0_sysvq0asl t_0){
  string_0_sysvq0asl result_23;
  nimStrWasMoved((&result_23));
  NB8 X60Qx_216 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
    .bytes_0 = 1684300035u, .more_0 = NIM_NIL}
  );
  if (X60Qx_216){
    return (string_0_sysvq0asl){
      .bytes_0 = 539697155u, .more_0 = NIM_NIL}
    ;}
  else {
    NB8 X60Qx_217 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
      .bytes_0 = 1651864323u, .more_0 = NIM_NIL}
    );
    if (X60Qx_217){
      return (string_0_sysvq0asl){
        .bytes_0 = 539828227u, .more_0 = NIM_NIL}
      ;}
    else {
      NB8 X60Qx_218 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
        .bytes_0 = 1819634947u, .more_0 = NIM_NIL}
      );
      if (X60Qx_218){
        return (string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        ;}
      else {
        NB8 X60Qx_219 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
          .bytes_0 = 1986618371u, .more_0 = NIM_NIL}
        );
        if (X60Qx_219){
          return (string_0_sysvq0asl){
            .bytes_0 = 539959299u, .more_0 = NIM_NIL}
          ;}
        else {
          NB8 X60Qx_220 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
            .bytes_0 = 1685024003u, .more_0 = NIM_NIL}
          );
          if (X60Qx_220){
            return (string_0_sysvq0asl){
              .bytes_0 = 539303939u, .more_0 = NIM_NIL}
            ;}
          else {
            NB8 X60Qx_221 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
              .bytes_0 = 1818784515u, .more_0 = NIM_NIL}
            );
            if (X60Qx_221){
              return (string_0_sysvq0asl){
                .bytes_0 = 1010573566u, .more_0 = (&strlit_0_I7737667989527362245_emi78vuj01)}
              ;}
            else {
              NB8 X60Qx_222 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
                .bytes_0 = 1919447811u, .more_0 = NIM_NIL}
              );
              if (X60Qx_222){
                return (string_0_sysvq0asl){
                  .bytes_0 = 1044259070u, .more_0 = (&strlit_0_I7519293862644853856_emi78vuj01)}
                ;}
              else {
                NB8 X60Qx_223 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
                  .bytes_0 = 1752392190u, .more_0 = (&strlit_0_I4333440046835585584_emi78vuj01)}
                );
                if (X60Qx_223){
                  return (string_0_sysvq0asl){
                    .bytes_0 = 1044259070u, .more_0 = (&strlit_0_I7519293862644853856_emi78vuj01)}
                  ;}
                else {
                  NB8 X60Qx_224 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
                    .bytes_0 = 1953063678u, .more_0 = (&strlit_0_I12320098920117258102_emi78vuj01)}
                  );
                  if (X60Qx_224){
                    return (string_0_sysvq0asl){
                      .bytes_0 = 539369475u, .more_0 = NIM_NIL}
                    ;}
                  else {
                    NB8 X60Qx_225 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
                      .bytes_0 = 1953063678u, .more_0 = (&strlit_0_I8344472873800577395_emi78vuj01)}
                    );
                    if (X60Qx_225){
                      return (string_0_sysvq0asl){
                        .bytes_0 = 545005571u, .more_0 = NIM_NIL}
                      ;}
                    else {
                      NB8 X60Qx_226 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
                        .bytes_0 = 1953063678u, .more_0 = (&strlit_0_I1868900624481666580_emi78vuj01)}
                      );
                      if (X60Qx_226){
                        return (string_0_sysvq0asl){
                          .bytes_0 = 543039491u, .more_0 = NIM_NIL}
                        ;}}}}}}}}}}}
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_23;}
string_0_sysvq0asl cmpBinOp_0_emi78vuj01(string_0_sysvq0asl t_1){
  string_0_sysvq0asl result_24;
  nimStrWasMoved((&result_24));
  NB8 X60Qx_227 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
    .bytes_0 = 7431426u, .more_0 = NIM_NIL}
  );
  if (X60Qx_227){
    return (string_0_sysvq0asl){
      .bytes_0 = 1027416318u, .more_0 = (&strlit_0_I12419389927391420973_emi78vuj01)}
    ;}
  else {
    NB8 X60Qx_228 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
      .bytes_0 = 1902472707u, .more_0 = NIM_NIL}
    );
    if (X60Qx_228){
      return (string_0_sysvq0asl){
        .bytes_0 = 1025581310u, .more_0 = (&strlit_0_I2558138246944699345_emi78vuj01)}
      ;}
    else {
      NB8 X60Qx_229 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
        .bytes_0 = 6646786u, .more_0 = NIM_NIL}
      );
      if (X60Qx_229){
        return (string_0_sysvq0asl){
          .bytes_0 = 1027350782u, .more_0 = (&strlit_0_I8459464401138684096_emi78vuj01)}
        ;}
      else {
        NB8 X60Qx_230 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
          .bytes_0 = 7629826u, .more_0 = NIM_NIL}
        );
        if (X60Qx_230){
          return (string_0_sysvq0asl){
            .bytes_0 = 540811267u, .more_0 = NIM_NIL}
          ;}
        else {
          NB8 X60Qx_231 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
            .bytes_0 = 6645506u, .more_0 = NIM_NIL}
          );
          if (X60Qx_231){
            return (string_0_sysvq0asl){
              .bytes_0 = 1027481854u, .more_0 = (&strlit_0_I10610139082009356491_emi78vuj01)}
            ;}
          else {
            NB8 X60Qx_232 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
              .bytes_0 = 7628546u, .more_0 = NIM_NIL}
            );
            if (X60Qx_232){
              return (string_0_sysvq0asl){
                .bytes_0 = 540942339u, .more_0 = NIM_NIL}
              ;}
            else {
              NB8 X60Qx_233 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
                .bytes_0 = 1684955395u, .more_0 = NIM_NIL}
              );
              if (X60Qx_233){
                return (string_0_sysvq0asl){
                  .bytes_0 = 640033022u, .more_0 = (&strlit_0_I9770694860431025064_emi78vuj01)}
                ;}
              else {
                NB8 X60Qx_234 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
                  .bytes_0 = 7499522u, .more_0 = NIM_NIL}
                );
                if (X60Qx_234){
                  return (string_0_sysvq0asl){
                    .bytes_0 = 2088509694u, .more_0 = (&strlit_0_I17052362747483005533_emi78vuj01)}
                  ;}}}}}}}}
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_24;}
string_0_sysvq0asl suffixType_0_emi78vuj01(string_0_sysvq0asl s_9){
  string_0_sysvq0asl result_25;
  nimStrWasMoved((&result_25));
  NB8 X60Qx_235 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
    .bytes_0 = 875981059u, .more_0 = NIM_NIL}
  );
  if (X60Qx_235){
    return (string_0_sysvq0asl){
      .bytes_0 = 910774014u, .more_0 = (&strlit_0_I6323980750145937682_emi78vuj01)}
    ;}
  else {
    NB8 X60Qx_236 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
      .bytes_0 = 842230019u, .more_0 = NIM_NIL}
    );
    if (X60Qx_236){
      return (string_0_sysvq0asl){
        .bytes_0 = 860442366u, .more_0 = (&strlit_0_I12781920874167708466_emi78vuj01)}
      ;}
    else {
      NB8 X60Qx_237 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
        .bytes_0 = 909207811u, .more_0 = NIM_NIL}
      );
      if (X60Qx_237){
        return (string_0_sysvq0asl){
          .bytes_0 = 826887934u, .more_0 = (&strlit_0_I13186846618376552100_emi78vuj01)}
        ;}
      else {
        NB8 X60Qx_238 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
          .bytes_0 = 3696898u, .more_0 = NIM_NIL}
        );
        if (X60Qx_238){
          return (string_0_sysvq0asl){
            .bytes_0 = 944328195u, .more_0 = NIM_NIL}
          ;}
        else {
          NB8 X60Qx_239 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
            .bytes_0 = 875984131u, .more_0 = NIM_NIL}
          );
          if (X60Qx_239){
            return (string_0_sysvq0asl){
              .bytes_0 = 911560446u, .more_0 = (&strlit_0_I18138163183994580077_emi78vuj01)}
            ;}
          else {
            NB8 X60Qx_240 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
              .bytes_0 = 842233091u, .more_0 = NIM_NIL}
            );
            if (X60Qx_240){
              return (string_0_sysvq0asl){
                .bytes_0 = 861228798u, .more_0 = (&strlit_0_I9066213625147390190_emi78vuj01)}
              ;}
            else {
              NB8 X60Qx_241 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
                .bytes_0 = 909210883u, .more_0 = NIM_NIL}
              );
              if (X60Qx_241){
                return (string_0_sysvq0asl){
                  .bytes_0 = 827674366u, .more_0 = (&strlit_0_I13023609298664275323_emi78vuj01)}
                ;}
              else {
                NB8 X60Qx_242 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
                  .bytes_0 = 3699970u, .more_0 = NIM_NIL}
                );
                if (X60Qx_242){
                  return (string_0_sysvq0asl){
                    .bytes_0 = 945114627u, .more_0 = NIM_NIL}
                  ;}
                else {
                  NB8 X60Qx_243 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
                    .bytes_0 = 875980291u, .more_0 = NIM_NIL}
                  );
                  if (X60Qx_243){
                    return (string_0_sysvq0asl){
                      .bytes_0 = 910577406u, .more_0 = (&strlit_0_I11372099257973387468_emi78vuj01)}
                    ;}
                  else {
                    NB8 X60Qx_244 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
                      .bytes_0 = 842229251u, .more_0 = NIM_NIL}
                    );
                    if (X60Qx_244){
                      return (string_0_sysvq0asl){
                        .bytes_0 = 860245758u, .more_0 = (&strlit_0_I10477416574274012141_emi78vuj01)}
                      ;}
                    else {
                      NB8 X60Qx_245 = eqQ_20_sysvq0asl(s_9, (string_0_sysvq0asl){
                        .bytes_0 = 26113u, .more_0 = NIM_NIL}
                      );
                      if (X60Qx_245){
                        return (string_0_sysvq0asl){
                          .bytes_0 = 910577406u, .more_0 = (&strlit_0_I11372099257973387468_emi78vuj01)}
                        ;}}}}}}}}}}}
  return (string_0_sysvq0asl){
    .bytes_0 = 910774014u, .more_0 = (&strlit_0_I6323980750145937682_emi78vuj01)}
  ;
  return result_25;}
void resetEmitter_0_emi78vuj01(void){
  eQdestroy_1_Ivioh0a_aow7lb5cq1(externKeys_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_246 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  externKeys_0_emi78vuj01 = X60Qx_246;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(externVals_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_247 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  externVals_0_emi78vuj01 = X60Qx_247;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(typeExternKeys_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_248 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  typeExternKeys_0_emi78vuj01 = X60Qx_248;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(typeExternVals_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_249 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  typeExternVals_0_emi78vuj01 = X60Qx_249;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(noDeclTypes_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_250 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  noDeclTypes_0_emi78vuj01 = X60Qx_250;
  nimStrDestroy(ownMod_0_emi78vuj01);
  string_0_sysvq0asl X60Qx_251 = nimStrDup(prog_0_prorcx25w1.main_0.name_0);
  ownMod_0_emi78vuj01 = X60Qx_251;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(loadedMods_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_252 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  loadedMods_0_emi78vuj01 = X60Qx_252;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(siblingSuffixes_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_253 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  siblingSuffixes_0_emi78vuj01 = X60Qx_253;
  siblingSuffixesLoaded_0_emi78vuj01 = NIM_FALSE;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(modProcKeys_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_254 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  modProcKeys_0_emi78vuj01 = X60Qx_254;
  eQdestroy_1_Ia4wwhy1_emi78vuj01(modProcVals_0_emi78vuj01);
  seq_0_Isutro81_emi78vuj01 X60Qx_255 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  modProcVals_0_emi78vuj01 = X60Qx_255;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(modGlobalKeys_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_256 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  modGlobalKeys_0_emi78vuj01 = X60Qx_256;
  eQdestroy_1_Ia4wwhy1_emi78vuj01(modGlobalVals_0_emi78vuj01);
  seq_0_Isutro81_emi78vuj01 X60Qx_257 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  modGlobalVals_0_emi78vuj01 = X60Qx_257;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(modTypeKeys_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_258 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  modTypeKeys_0_emi78vuj01 = X60Qx_258;
  eQdestroy_1_Ia4wwhy1_emi78vuj01(modTypeVals_0_emi78vuj01);
  seq_0_Isutro81_emi78vuj01 X60Qx_259 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  modTypeVals_0_emi78vuj01 = X60Qx_259;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(checkedSuffixes_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_260 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  checkedSuffixes_0_emi78vuj01 = X60Qx_260;}
NB8 mapHas_0_emi78vuj01(seq_0_Ixdx2fh1_aow7lb5cq1 keys_0, string_0_sysvq0asl k_0){
  NB8 result_26;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_10 = toOpenArray_1_I6b60gk1_aow7lb5cq1(keys_0);
    NI32 X60Qlf_11 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_261 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_10);
        if (X60Qlf_11 < X60Qx_261){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_10, X60Qlf_11);
            NB8 X60Qx_262 = eqQ_20_sysvq0asl((*X60Qii_2), k_0);
            if (X60Qx_262){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_11));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return NIM_FALSE;
  return result_26;}
string_0_sysvq0asl mapGet_0_emi78vuj01(seq_0_Ixdx2fh1_aow7lb5cq1 keys_1, seq_0_Ixdx2fh1_aow7lb5cq1 vals_0, string_0_sysvq0asl k_1){
  string_0_sysvq0asl result_27;
  nimStrWasMoved((&result_27));
  {
    NI32 X60Qlf_12 = 0;
    NI32 X60Qlf_13 = len_3_Ixq6taz_aow7lb5cq1(keys_1);
    NI32 X60Qlf_14 = X60Qlf_12;
    {
      while (X60Qlf_14 < X60Qlf_13){
        {
          string_0_sysvq0asl* X60Qx_263 = getQ_7_Ir6d0tw_aow7lb5cq1(keys_1, X60Qlf_14);
          NB8 X60Qx_264 = eqQ_20_sysvq0asl((*X60Qx_263), k_1);
          if (X60Qx_264){
            string_0_sysvq0asl* X60Qx_265 = getQ_7_Ir6d0tw_aow7lb5cq1(vals_0, X60Qlf_14);
            string_0_sysvq0asl X60Qx_266 = nimStrDup((*X60Qx_265));
            result_27 = X60Qx_266;
            return result_27;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_14));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_27;}
string_0_sysvq0asl symName_0_emi78vuj01(string_0_sysvq0asl name_0){
  string_0_sysvq0asl result_28;
  nimStrWasMoved((&result_28));
  NB8 X60Qx_267 = mapHas_0_emi78vuj01(externKeys_0_emi78vuj01, name_0);
  if (X60Qx_267){
    string_0_sysvq0asl X60Qx_268 = mapGet_0_emi78vuj01(externKeys_0_emi78vuj01, externVals_0_emi78vuj01, name_0);
    result_28 = X60Qx_268;
    return result_28;}
  string_0_sysvq0asl X60Qx_269 = mangleToC_0_emi78vuj01(name_0);
  result_28 = X60Qx_269;
  return result_28;
  return result_28;}
string_0_sysvq0asl typeName_0_emi78vuj01(string_0_sysvq0asl name_1){
  string_0_sysvq0asl result_29;
  nimStrWasMoved((&result_29));
  NB8 X60Qx_270 = mapHas_0_emi78vuj01(typeExternKeys_0_emi78vuj01, name_1);
  if (X60Qx_270){
    string_0_sysvq0asl X60Qx_271 = mapGet_0_emi78vuj01(typeExternKeys_0_emi78vuj01, typeExternVals_0_emi78vuj01, name_1);
    result_29 = X60Qx_271;
    return result_29;}
  string_0_sysvq0asl X60Qx_272 = mangleToC_0_emi78vuj01(name_1);
  result_29 = X60Qx_272;
  return result_29;
  return result_29;}
string_0_sysvq0asl externName_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pragmas_0){
  string_0_sysvq0asl result_30;
  nimStrWasMoved((&result_30));
  NB8 X60Qx_273;
  NB8 X60Qx_274 = isList_0_emi78vuj01(pragmas_0);
  if ((!X60Qx_274)){
    X60Qx_273 = NIM_TRUE;}
  else {
    NB8 X60Qx_275 = eqQ_20_sysvq0asl((*pragmas_0).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
    );
    X60Qx_273 = (!X60Qx_275);}
  if (X60Qx_273){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_15 = toOpenArray_1_I1gbnw21_emi78vuj01((*pragmas_0).d_00.kids_0);
    NI32 X60Qlf_16 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_276 = len_6_I3x6mi_emi78vuj01(X60Qlf_15);
        if (X60Qlf_16 < X60Qx_276){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_15, X60Qlf_16);
            NB8 X60Qx_277;
            NB8 X60Qx_278 = isList_0_emi78vuj01((*X60Qii_2));
            if (X60Qx_278){
              NB8 X60Qx_279;
              NB8 X60Qx_280;
              NB8 X60Qx_281 = eqQ_20_sysvq0asl((*(*X60Qii_2)).d_00.tag_0, (string_0_sysvq0asl){
                .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
              );
              if (X60Qx_281){
                X60Qx_280 = NIM_TRUE;}
              else {
                NB8 X60Qx_282 = eqQ_20_sysvq0asl((*(*X60Qii_2)).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I4862850237857511107_emi78vuj01)}
                );
                X60Qx_280 = X60Qx_282;}
              if (X60Qx_280){
                X60Qx_279 = NIM_TRUE;}
              else {
                NB8 X60Qx_283 = eqQ_20_sysvq0asl((*(*X60Qii_2)).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}
                );
                X60Qx_279 = X60Qx_283;}
              X60Qx_277 = X60Qx_279;}
            else {
              X60Qx_277 = NIM_FALSE;}
            if (X60Qx_277){
              if (0 < (*(*X60Qii_2)).d_00.kids_0.len_0){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_284 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_2)).d_00.kids_0, 0);
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_3 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_284));
                NB8 X60Qx_285;
                if ((!(X60Qii_3 == NIM_NIL))){
                  X60Qx_285 = ((*X60Qii_3).d_00.kind_0 == 1);}
                else {
                  X60Qx_285 = NIM_FALSE;}
                if (X60Qx_285){
                  string_0_sysvq0asl X60Qx_286 = nimStrDup((*X60Qii_3).d_00.strVal_0);
                  result_30 = X60Qx_286;
                  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_3);
                  return result_30;}
                NB8 X60Qx_287 = isAtom_0_emi78vuj01(X60Qii_3);
                if (X60Qx_287){
                  string_0_sysvq0asl X60Qx_288 = nimStrDup((*X60Qii_3).d_00.atom_0);
                  result_30 = X60Qx_288;
                  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_3);
                  return result_30;}
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_3);}
              return (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              ;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_16));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_30;}
NB8 hasPragma_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pragmas_1, openArray_0_Ig73pnk_aow7lb5cq1 names_0){
  NB8 result_31;
  NB8 X60Qx_289;
  NB8 X60Qx_290 = isList_0_emi78vuj01(pragmas_1);
  if ((!X60Qx_290)){
    X60Qx_289 = NIM_TRUE;}
  else {
    NB8 X60Qx_291 = eqQ_20_sysvq0asl((*pragmas_1).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
    );
    X60Qx_289 = (!X60Qx_291);}
  if (X60Qx_289){
    return NIM_FALSE;}
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_17 = toOpenArray_1_I1gbnw21_emi78vuj01((*pragmas_1).d_00.kids_0);
    NI32 X60Qlf_18 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_292 = len_6_I3x6mi_emi78vuj01(X60Qlf_17);
        if (X60Qlf_18 < X60Qx_292){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_17, X60Qlf_18);
            NB8 X60Qx_293;
            NB8 X60Qx_294 = isList_0_emi78vuj01((*X60Qii_2));
            if (X60Qx_294){
              NB8 X60Qx_295 = oneOf_0_emi78vuj01((*(*X60Qii_2)).d_00.tag_0, names_0);
              X60Qx_293 = X60Qx_295;}
            else {
              X60Qx_293 = NIM_FALSE;}
            if (X60Qx_293){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_18));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return NIM_FALSE;
  return result_31;}
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* findTag_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* n_6, string_0_sysvq0asl tag_0){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* result_32;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&result_32));
  NB8 X60Qx_296 = isList_0_emi78vuj01(n_6);
  if ((!X60Qx_296)){
    return NIM_NIL;}
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_19 = toOpenArray_1_I1gbnw21_emi78vuj01((*n_6).d_00.kids_0);
    NI32 X60Qlf_20 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_297 = len_6_I3x6mi_emi78vuj01(X60Qlf_19);
        if (X60Qlf_20 < X60Qx_297){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_19, X60Qlf_20);
            NB8 X60Qx_298;
            NB8 X60Qx_299 = isList_0_emi78vuj01((*X60Qii_2));
            if (X60Qx_299){
              NB8 X60Qx_300 = eqQ_20_sysvq0asl((*(*X60Qii_2)).d_00.tag_0, tag_0);
              X60Qx_298 = X60Qx_300;}
            else {
              X60Qx_298 = NIM_FALSE;}
            if (X60Qx_298){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_301 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_2));
              result_32 = X60Qx_301;
              return result_32;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_20));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return NIM_NIL;
  return result_32;}
NI32 indexOfKid_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* n_7, X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* target_0){
  NI32 result_33;
  {
    NI32 X60Qlf_21 = 0;
    NI32 X60Qlf_22 = len_3_Il6imzw1_emi78vuj01((*n_7).d_00.kids_0);
    NI32 X60Qlf_23 = X60Qlf_21;
    {
      while (X60Qlf_23 < X60Qlf_22){
        {
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_302 = getQ_7_Iheb436_emi78vuj01((*n_7).d_00.kids_0, X60Qlf_23);
          if ((*X60Qx_302) == target_0){
            return X60Qlf_23;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_23));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return -1;
  return result_33;}
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* paramType_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* paramNode_0){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* result_34;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&result_34));
  NI32 i_12 = 1;
  {
    while (NIM_TRUE){
      NI32 X60Qx_303 = len_3_Il6imzw1_emi78vuj01((*paramNode_0).d_00.kids_0);
      if (i_12 < X60Qx_303){
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_304 = getQ_7_Iheb436_emi78vuj01((*paramNode_0).d_00.kids_0, i_12);
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* k_3 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_304));
        NB8 X60Qx_305;
        NB8 X60Qx_306 = isList_0_emi78vuj01(k_3);
        if (X60Qx_306){
          X60Qx_305 = NIM_TRUE;}
        else {
          NB8 X60Qx_307;
          NB8 X60Qx_308;
          NB8 X60Qx_309 = isAtom_0_emi78vuj01(k_3);
          if (X60Qx_309){
            NB8 X60Qx_310 = eqQ_20_sysvq0asl((*k_3).d_00.atom_0, (string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            X60Qx_308 = (!X60Qx_310);}
          else {
            X60Qx_308 = NIM_FALSE;}
          if (X60Qx_308){
            X60Qx_307 = (!(*k_3).d_00.def_0);}
          else {
            X60Qx_307 = NIM_FALSE;}
          X60Qx_305 = X60Qx_307;}
        if (X60Qx_305){
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_14 = k_3;
          eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&k_3));
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(k_3);
          return X60Qtmp_14;}
        inc_1_I6wjjge_aow2h993l1((&i_12));
        eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(k_3);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_311 = getQ_7_Iheb436_emi78vuj01((*paramNode_0).d_00.kids_0, 2);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_312 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_311));
  result_34 = X60Qx_312;
  return result_34;
  return result_34;}
string_0_sysvq0asl bitsOf_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* t_4){
  string_0_sysvq0asl result_35;
  nimStrWasMoved((&result_35));
  NI32 X60Qx_313 = len_3_Il6imzw1_emi78vuj01((*t_4).d_00.kids_0);
  if (X60Qx_313 == 0){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 X60Qx_314 = len_3_Il6imzw1_emi78vuj01((*t_4).d_00.kids_0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_315 = getQ_7_Iheb436_emi78vuj01((*t_4).d_00.kids_0, ((NI32)(X60Qx_314 - 1)));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* last_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_315));
  NB8 X60Qx_316;
  NB8 X60Qx_317 = isAtom_0_emi78vuj01(last_0);
  if (X60Qx_317){
    NB8 X60Qx_318 = isIntLit_0_emi78vuj01((*last_0).d_00.atom_0);
    X60Qx_316 = X60Qx_318;}
  else {
    X60Qx_316 = NIM_FALSE;}
  if (X60Qx_316){
    NB8 X60Qx_319 = eqQ_20_sysvq0asl((*last_0).d_00.atom_0, (string_0_sysvq0asl){
      .bytes_0 = 3222786u, .more_0 = NIM_NIL}
    );
    if (X60Qx_319){
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(last_0);
      return (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl X60Qx_320 = nimStrDup((*last_0).d_00.atom_0);
    result_35 = X60Qx_320;
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(last_0);
    return result_35;}
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(last_0);
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(last_0);
  return result_35;
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(last_0);
  return result_35;}
string_0_sysvq0asl genProcTypePtr_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* t_5){
  string_0_sysvq0asl result_36;
  nimStrWasMoved((&result_36));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* params_0 = findTag_0_emi78vuj01(t_5, (string_0_sysvq0asl){
    .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_der823rwr1)}
  );
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* ret_0 = NIM_NIL;
  if ((!(params_0 == NIM_NIL))){
    NI32 idx_0 = indexOfKid_0_emi78vuj01(t_5, params_0);
    NB8 X60Qx_321;
    if (0 <= idx_0){
      NI32 X60Qx_322 = len_3_Il6imzw1_emi78vuj01((*t_5).d_00.kids_0);
      X60Qx_321 = (((NI32)(idx_0 + 1)) < X60Qx_322);}
    else {
      X60Qx_321 = NIM_FALSE;}
    if (X60Qx_321){
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ret_0);
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_323 = getQ_7_Iheb436_emi78vuj01((*t_5).d_00.kids_0, ((NI32)(idx_0 + 1)));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_324 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_323));
      ret_0 = X60Qx_324;}}
  else {
    if (0 < (*t_5).d_00.kids_0.len_0){
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ret_0);
      NI32 X60Qx_325 = len_3_Il6imzw1_emi78vuj01((*t_5).d_00.kids_0);
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_326 = getQ_7_Iheb436_emi78vuj01((*t_5).d_00.kids_0, ((NI32)(X60Qx_325 - 1)));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_327 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_326));
      ret_0 = X60Qx_327;}}
  seq_0_Ixdx2fh1_aow7lb5cq1 args_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  if ((!(params_0 == NIM_NIL))){
    {
      openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_24 = toOpenArray_1_I1gbnw21_emi78vuj01((*params_0).d_00.kids_0);
      NI32 X60Qlf_25 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_328 = len_6_I3x6mi_emi78vuj01(X60Qlf_24);
          if (X60Qlf_25 < X60Qx_328){
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_24, X60Qlf_25);
              NB8 X60Qx_329;
              NB8 X60Qx_330 = isList_0_emi78vuj01((*X60Qii_2));
              if (X60Qx_330){
                NB8 X60Qx_331 = eqQ_20_sysvq0asl((*(*X60Qii_2)).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I9792473688321036479_emi78vuj01)}
                );
                X60Qx_329 = X60Qx_331;}
              else {
                X60Qx_329 = NIM_FALSE;}
              if (X60Qx_329){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_15 = paramType_0_emi78vuj01((*X60Qii_2));
                string_0_sysvq0asl X60Qx_332 = genType_1_emi78vuj01(X60Qtmp_15);
                add_0_Ig6072n_aow7lb5cq1((&args_0), X60Qx_332);
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qtmp_15);}}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_25));}
          else {
            break;}}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  string_0_sysvq0asl X60Qx_0;
  nimStrWasMoved((&X60Qx_0));
  if (0 < args_0.len_0){
    nimStrDestroy(X60Qx_0);
    string_0_sysvq0asl X60Qx_333 = joinSeq_0_emi78vuj01(args_0, (string_0_sysvq0asl){
      .bytes_0 = 2108418u, .more_0 = NIM_NIL}
    );
    X60Qx_0 = X60Qx_333;}
  else {
    nimStrDestroy(X60Qx_0);
    X60Qx_0 = (string_0_sysvq0asl){
      .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
    ;}
  string_0_sysvq0asl argStr_0 = X60Qx_0;
  nimStrWasMoved((&X60Qx_0));
  string_0_sysvq0asl X60Qdesugar_2 = genType_1_emi78vuj01(ret_0);
  NI32 X60Qx_334 = len_4_sysvq0asl(X60Qdesugar_2);
  NI32 X60Qx_335 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 690628862u, .more_0 = (&strlit_0_I4957091821656791898_emi78vuj01)}
  );
  NI32 X60Qx_336 = len_4_sysvq0asl(argStr_0);
  NI32 X60Qx_337 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_3 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_334 + X60Qx_335)) + X60Qx_336)) + X60Qx_337)));
  add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_2);
  add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
    .bytes_0 = 690628862u, .more_0 = (&strlit_0_I4957091821656791898_emi78vuj01)}
  );
  add_2_sysvq0asl((&X60Qdesugar_3), argStr_0);
  add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qtmp_16 = X60Qdesugar_3;
  nimStrWasMoved((&X60Qdesugar_3));
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(argStr_0);
  nimStrDestroy(X60Qx_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(args_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ret_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(params_0);
  return X60Qtmp_16;
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(argStr_0);
  nimStrDestroy(X60Qx_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(args_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ret_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(params_0);
  return result_36;
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(argStr_0);
  nimStrDestroy(X60Qx_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(args_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ret_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(params_0);
  return result_36;}
string_0_sysvq0asl genType_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* t_6){
  string_0_sysvq0asl result_37;
  nimStrWasMoved((&result_37));
  NB8 X60Qx_338 = isDot_0_emi78vuj01(t_6);
  if (X60Qx_338){
    return (string_0_sysvq0asl){
      .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
    ;}
  NB8 X60Qx_339 = isAtom_0_emi78vuj01(t_6);
  if (X60Qx_339){
    NB8 X60Qx_340 = eqQ_20_sysvq0asl((*t_6).d_00.atom_0, (string_0_sysvq0asl){
      .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
    );
    if (X60Qx_340){
      return (string_0_sysvq0asl){
        .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
      ;}
    string_0_sysvq0asl X60Qx_341 = typeName_0_emi78vuj01((*t_6).d_00.atom_0);
    result_37 = X60Qx_341;
    return result_37;}
  NB8 X60Qx_342 = isList_0_emi78vuj01(t_6);
  if ((!X60Qx_342)){
    fail_0_emi78vuj01((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I12782213824028315602_emi78vuj01)}
    );
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl tg_0 = nimStrDup((*t_6).d_00.tag_0);
  NB8 X60Qx_343 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
    .bytes_0 = 26881u, .more_0 = NIM_NIL}
  );
  if (X60Qx_343){
    string_0_sysvq0asl X60Qtmp_17 = bitsOf_0_emi78vuj01(t_6);
    string_0_sysvq0asl X60Qx_344 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 4804098u, .more_0 = NIM_NIL}
    , X60Qtmp_17);
    result_37 = X60Qx_344;
    nimStrDestroy(X60Qtmp_17);
    nimStrDestroy(tg_0);
    return result_37;
    nimStrDestroy(X60Qtmp_17);}
  else {
    NB8 X60Qx_345 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
      .bytes_0 = 29953u, .more_0 = NIM_NIL}
    );
    if (X60Qx_345){
      string_0_sysvq0asl X60Qtmp_18 = bitsOf_0_emi78vuj01(t_6);
      string_0_sysvq0asl X60Qx_346 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 5590530u, .more_0 = NIM_NIL}
      , X60Qtmp_18);
      result_37 = X60Qx_346;
      nimStrDestroy(X60Qtmp_18);
      nimStrDestroy(tg_0);
      return result_37;
      nimStrDestroy(X60Qtmp_18);}
    else {
      NB8 X60Qx_347 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
        .bytes_0 = 26113u, .more_0 = NIM_NIL}
      );
      if (X60Qx_347){
        string_0_sysvq0asl X60Qtmp_19 = bitsOf_0_emi78vuj01(t_6);
        string_0_sysvq0asl X60Qx_348 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 4607490u, .more_0 = NIM_NIL}
        , X60Qtmp_19);
        result_37 = X60Qx_348;
        nimStrDestroy(X60Qtmp_19);
        nimStrDestroy(tg_0);
        return result_37;
        nimStrDestroy(X60Qtmp_19);}
      else {
        NB8 X60Qx_349 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
          .bytes_0 = 25345u, .more_0 = NIM_NIL}
        );
        if (X60Qx_349){
          string_0_sysvq0asl X60Qtmp_20 = bitsOf_0_emi78vuj01(t_6);
          string_0_sysvq0asl X60Qx_350 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 4410882u, .more_0 = NIM_NIL}
          , X60Qtmp_20);
          result_37 = X60Qx_350;
          nimStrDestroy(X60Qtmp_20);
          nimStrDestroy(tg_0);
          return result_37;
          nimStrDestroy(X60Qtmp_20);}
        else {
          NB8 X60Qx_351 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
            .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
          );
          if (X60Qx_351){
            nimStrDestroy(tg_0);
            return (string_0_sysvq0asl){
              .bytes_0 = 943869443u, .more_0 = NIM_NIL}
            ;}
          else {
            NB8 X60Qx_352 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
              .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
            );
            if (X60Qx_352){
              nimStrDestroy(tg_0);
              return (string_0_sysvq0asl){
                .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
              ;}
            else {
              NB8 X60Qx_353;
              NB8 X60Qx_354 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
              );
              if (X60Qx_354){
                X60Qx_353 = NIM_TRUE;}
              else {
                NB8 X60Qx_355 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                  .bytes_0 = 1953522174u, .more_0 = (&strlit_0_I6488225283415667707_emi78vuj01)}
                );
                X60Qx_353 = X60Qx_355;}
              if (X60Qx_353){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_356 = getQ_7_Iheb436_emi78vuj01((*t_6).d_00.kids_0, 0);
                string_0_sysvq0asl X60Qtmp_21 = genType_1_emi78vuj01((*X60Qx_356));
                string_0_sysvq0asl X60Qx_357 = ampQ_0_sysvq0asl(X60Qtmp_21, (string_0_sysvq0asl){
                  .bytes_0 = 10753u, .more_0 = NIM_NIL}
                );
                result_37 = X60Qx_357;
                nimStrDestroy(X60Qtmp_21);
                nimStrDestroy(tg_0);
                return result_37;
                nimStrDestroy(X60Qtmp_21);}
              else {
                NB8 X60Qx_358 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                  .bytes_0 = 1701603070u, .more_0 = (&strlit_0_I13748185565082850274_emi78vuj01)}
                );
                if (X60Qx_358){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_359 = getQ_7_Iheb436_emi78vuj01((*t_6).d_00.kids_0, 0);
                  string_0_sysvq0asl X60Qtmp_22 = genType_1_emi78vuj01((*X60Qx_359));
                  string_0_sysvq0asl X60Qx_360 = ampQ_0_sysvq0asl(X60Qtmp_22, (string_0_sysvq0asl){
                    .bytes_0 = 10753u, .more_0 = NIM_NIL}
                  );
                  result_37 = X60Qx_360;
                  nimStrDestroy(X60Qtmp_22);
                  nimStrDestroy(tg_0);
                  return result_37;
                  nimStrDestroy(X60Qtmp_22);}
                else {
                  NB8 X60Qx_361 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                    .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I1995551610468546737_emi78vuj01)}
                  );
                  if (X60Qx_361){
                    string_0_sysvq0asl X60Qx_362 = genProcTypePtr_0_emi78vuj01(t_6);
                    result_37 = X60Qx_362;
                    nimStrDestroy(tg_0);
                    return result_37;}
                  else {
                    NB8 X60Qx_363 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
                    );
                    if (X60Qx_363){
                      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_364 = getQ_7_Iheb436_emi78vuj01((*t_6).d_00.kids_0, 0);
                      string_0_sysvq0asl X60Qtmp_23 = genType_1_emi78vuj01((*X60Qx_364));
                      string_0_sysvq0asl X60Qx_365 = ampQ_0_sysvq0asl(X60Qtmp_23, (string_0_sysvq0asl){
                        .bytes_0 = 10753u, .more_0 = NIM_NIL}
                      );
                      result_37 = X60Qx_365;
                      nimStrDestroy(X60Qtmp_23);
                      nimStrDestroy(tg_0);
                      return result_37;
                      nimStrDestroy(X60Qtmp_23);}
                    else {
                      if (0 < (*t_6).d_00.kids_0.len_0){
                        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_366 = getQ_7_Iheb436_emi78vuj01((*t_6).d_00.kids_0, 0);
                        string_0_sysvq0asl X60Qx_367 = genType_1_emi78vuj01((*X60Qx_366));
                        result_37 = X60Qx_367;
                        nimStrDestroy(tg_0);
                        return result_37;}
                      NI32 X60Qx_368 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I1645239835584249519_emi78vuj01)}
                      );
                      NI32 X60Qx_369 = len_4_sysvq0asl(tg_0);
                      NI32 X60Qx_370 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 9985u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_4 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_368 + X60Qx_369)) + X60Qx_370)));
                      add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
                        .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I1645239835584249519_emi78vuj01)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_4), tg_0);
                      add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
                        .bytes_0 = 9985u, .more_0 = NIM_NIL}
                      );
                      fail_0_emi78vuj01(X60Qdesugar_4);
                      nimStrDestroy(X60Qdesugar_4);
                      nimStrDestroy(tg_0);
                      return (string_0_sysvq0asl){
                        .bytes_0 = 0u, .more_0 = NIM_NIL}
                      ;
                      nimStrDestroy(X60Qdesugar_4);}}}}}}}}}}
  nimStrDestroy(tg_0);
  return result_37;
  nimStrDestroy(tg_0);
  return result_37;}
string_0_sysvq0asl declare_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* t_7, string_0_sysvq0asl name_3){
  string_0_sysvq0asl result_38;
  nimStrWasMoved((&result_38));
  NB8 X60Qx_371;
  NB8 X60Qx_372 = isList_0_emi78vuj01(t_7);
  if (X60Qx_372){
    NB8 X60Qx_373 = eqQ_20_sysvq0asl((*t_7).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
    );
    X60Qx_371 = X60Qx_373;}
  else {
    X60Qx_371 = NIM_FALSE;}
  if (X60Qx_371){
    NI32 X60Qx_374 = len_3_Il6imzw1_emi78vuj01((*t_7).d_00.kids_0);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_375 = getQ_7_Iheb436_emi78vuj01((*t_7).d_00.kids_0, ((NI32)(X60Qx_374 - 1)));
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* size_2 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_375));
    string_0_sysvq0asl X60Qx_1;
    nimStrWasMoved((&X60Qx_1));
    NB8 X60Qx_376 = isAtom_0_emi78vuj01(size_2);
    if (X60Qx_376){
      nimStrDestroy(X60Qx_1);
      string_0_sysvq0asl X60Qx_377 = nimStrDup((*size_2).d_00.atom_0);
      X60Qx_1 = X60Qx_377;}
    else {
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 12289u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl len2_0 = X60Qx_1;
    nimStrWasMoved((&X60Qx_1));
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_378 = getQ_7_Iheb436_emi78vuj01((*t_7).d_00.kids_0, 0);
    string_0_sysvq0asl X60Qdesugar_5 = genType_1_emi78vuj01((*X60Qx_378));
    NI32 X60Qx_379 = len_4_sysvq0asl(X60Qdesugar_5);
    NI32 X60Qx_380 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_381 = len_4_sysvq0asl(name_3);
    NI32 X60Qx_382 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 23297u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_383 = len_4_sysvq0asl(len2_0);
    NI32 X60Qx_384 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 23809u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_6 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_379 + X60Qx_380)) + X60Qx_381)) + X60Qx_382)) + X60Qx_383)) + X60Qx_384)));
    add_2_sysvq0asl((&X60Qdesugar_6), X60Qdesugar_5);
    add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_6), name_3);
    add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
      .bytes_0 = 23297u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_6), len2_0);
    add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
      .bytes_0 = 23809u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_24 = X60Qdesugar_6;
    nimStrWasMoved((&X60Qdesugar_6));
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(len2_0);
    nimStrDestroy(X60Qx_1);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(size_2);
    return X60Qtmp_24;
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(len2_0);
    nimStrDestroy(X60Qx_1);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(size_2);}
  NB8 X60Qx_385;
  NB8 X60Qx_386 = isList_0_emi78vuj01(t_7);
  if (X60Qx_386){
    NB8 X60Qx_387 = eqQ_20_sysvq0asl((*t_7).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1701603070u, .more_0 = (&strlit_0_I13748185565082850274_emi78vuj01)}
    );
    X60Qx_385 = X60Qx_387;}
  else {
    X60Qx_385 = NIM_FALSE;}
  if (X60Qx_385){
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_388 = getQ_7_Iheb436_emi78vuj01((*t_7).d_00.kids_0, 0);
    string_0_sysvq0asl X60Qdesugar_7 = genType_1_emi78vuj01((*X60Qx_388));
    NI32 X60Qx_389 = len_4_sysvq0asl(X60Qdesugar_7);
    NI32 X60Qx_390 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_391 = len_4_sysvq0asl(name_3);
    NI32 X60Qx_392 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 6118146u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_8 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_389 + X60Qx_390)) + X60Qx_391)) + X60Qx_392)));
    add_2_sysvq0asl((&X60Qdesugar_8), X60Qdesugar_7);
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), name_3);
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 6118146u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_25 = X60Qdesugar_8;
    nimStrWasMoved((&X60Qdesugar_8));
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qdesugar_7);
    return X60Qtmp_25;
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qdesugar_7);}
  NB8 X60Qx_393;
  NB8 X60Qx_394 = isList_0_emi78vuj01(t_7);
  if (X60Qx_394){
    NB8 X60Qx_395 = eqQ_20_sysvq0asl((*t_7).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I1995551610468546737_emi78vuj01)}
    );
    X60Qx_393 = X60Qx_395;}
  else {
    X60Qx_393 = NIM_FALSE;}
  if (X60Qx_393){
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* params_1 = findTag_0_emi78vuj01(t_7, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_der823rwr1)}
    );
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* ret_1 = NIM_NIL;
    if ((!(params_1 == NIM_NIL))){
      NI32 idx_1 = indexOfKid_0_emi78vuj01(t_7, params_1);
      NB8 X60Qx_396;
      if (0 <= idx_1){
        NI32 X60Qx_397 = len_3_Il6imzw1_emi78vuj01((*t_7).d_00.kids_0);
        X60Qx_396 = (((NI32)(idx_1 + 1)) < X60Qx_397);}
      else {
        X60Qx_396 = NIM_FALSE;}
      if (X60Qx_396){
        eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ret_1);
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_398 = getQ_7_Iheb436_emi78vuj01((*t_7).d_00.kids_0, ((NI32)(idx_1 + 1)));
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_399 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_398));
        ret_1 = X60Qx_399;}}
    else {
      if (0 < (*t_7).d_00.kids_0.len_0){
        eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ret_1);
        NI32 X60Qx_400 = len_3_Il6imzw1_emi78vuj01((*t_7).d_00.kids_0);
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_401 = getQ_7_Iheb436_emi78vuj01((*t_7).d_00.kids_0, ((NI32)(X60Qx_400 - 1)));
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_402 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_401));
        ret_1 = X60Qx_402;}}
    seq_0_Ixdx2fh1_aow7lb5cq1 args_1 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    if ((!(params_1 == NIM_NIL))){
      {
        openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_26 = toOpenArray_1_I1gbnw21_emi78vuj01((*params_1).d_00.kids_0);
        NI32 X60Qlf_27 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_403 = len_6_I3x6mi_emi78vuj01(X60Qlf_26);
            if (X60Qlf_27 < X60Qx_403){
              {
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_26, X60Qlf_27);
                NB8 X60Qx_404;
                NB8 X60Qx_405 = isList_0_emi78vuj01((*X60Qii_2));
                if (X60Qx_405){
                  NB8 X60Qx_406 = eqQ_20_sysvq0asl((*(*X60Qii_2)).d_00.tag_0, (string_0_sysvq0asl){
                    .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I9792473688321036479_emi78vuj01)}
                  );
                  X60Qx_404 = X60Qx_406;}
                else {
                  X60Qx_404 = NIM_FALSE;}
                if (X60Qx_404){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_26 = paramType_0_emi78vuj01((*X60Qii_2));
                  string_0_sysvq0asl X60Qx_407 = genType_1_emi78vuj01(X60Qtmp_26);
                  add_0_Ig6072n_aow7lb5cq1((&args_1), X60Qx_407);
                  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qtmp_26);}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_27));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;}
    string_0_sysvq0asl X60Qx_2;
    nimStrWasMoved((&X60Qx_2));
    if (0 < args_1.len_0){
      nimStrDestroy(X60Qx_2);
      string_0_sysvq0asl X60Qx_408 = joinSeq_0_emi78vuj01(args_1, (string_0_sysvq0asl){
        .bytes_0 = 2108418u, .more_0 = NIM_NIL}
      );
      X60Qx_2 = X60Qx_408;}
    else {
      nimStrDestroy(X60Qx_2);
      X60Qx_2 = (string_0_sysvq0asl){
        .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
      ;}
    string_0_sysvq0asl argStr_1 = X60Qx_2;
    nimStrWasMoved((&X60Qx_2));
    string_0_sysvq0asl X60Qdesugar_9 = genType_1_emi78vuj01(ret_1);
    NI32 X60Qx_409 = len_4_sysvq0asl(X60Qdesugar_9);
    NI32 X60Qx_410 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 707272707u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_411 = len_4_sysvq0asl(name_3);
    NI32 X60Qx_412 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2631938u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_413 = len_4_sysvq0asl(argStr_1);
    NI32 X60Qx_414 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_10 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_409 + X60Qx_410)) + X60Qx_411)) + X60Qx_412)) + X60Qx_413)) + X60Qx_414)));
    add_2_sysvq0asl((&X60Qdesugar_10), X60Qdesugar_9);
    add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
      .bytes_0 = 707272707u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_10), name_3);
    add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
      .bytes_0 = 2631938u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_10), argStr_1);
    add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_27 = X60Qdesugar_10;
    nimStrWasMoved((&X60Qdesugar_10));
    nimStrDestroy(X60Qdesugar_10);
    nimStrDestroy(X60Qdesugar_9);
    nimStrDestroy(argStr_1);
    nimStrDestroy(X60Qx_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(args_1);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ret_1);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(params_1);
    return X60Qtmp_27;
    nimStrDestroy(X60Qdesugar_10);
    nimStrDestroy(X60Qdesugar_9);
    nimStrDestroy(argStr_1);
    nimStrDestroy(X60Qx_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(args_1);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ret_1);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(params_1);}
  string_0_sysvq0asl X60Qdesugar_11 = genType_1_emi78vuj01(t_7);
  NI32 X60Qx_415 = len_4_sysvq0asl(X60Qdesugar_11);
  NI32 X60Qx_416 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_417 = len_4_sysvq0asl(name_3);
  string_0_sysvq0asl X60Qdesugar_12 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_415 + X60Qx_416)) + X60Qx_417)));
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_11);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), name_3);
  string_0_sysvq0asl X60Qtmp_28 = X60Qdesugar_12;
  nimStrWasMoved((&X60Qdesugar_12));
  nimStrDestroy(X60Qdesugar_12);
  nimStrDestroy(X60Qdesugar_11);
  return X60Qtmp_28;
  nimStrDestroy(X60Qdesugar_12);
  nimStrDestroy(X60Qdesugar_11);
  return result_38;
  nimStrDestroy(X60Qdesugar_12);
  nimStrDestroy(X60Qdesugar_11);
  return result_38;}
string_0_sysvq0asl constrBody_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* e_4){
  string_0_sysvq0asl result_39;
  nimStrWasMoved((&result_39));
  NB8 X60Qx_418 = eqQ_20_sysvq0asl((*e_4).d_00.tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I17573272885368898989_emi78vuj01)}
  );
  if (X60Qx_418){
    seq_0_Ixdx2fh1_aow7lb5cq1 vals_1 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    NI32 i_13 = 1;
    {
      while (NIM_TRUE){
        NI32 X60Qx_419 = len_3_Il6imzw1_emi78vuj01((*e_4).d_00.kids_0);
        if (i_13 < X60Qx_419){
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_420 = getQ_7_Iheb436_emi78vuj01((*e_4).d_00.kids_0, i_13);
          string_0_sysvq0asl X60Qx_421 = genInit_1_emi78vuj01((*X60Qx_420));
          add_0_Ig6072n_aow7lb5cq1((&vals_1), X60Qx_421);
          inc_1_I6wjjge_aow2h993l1((&i_13));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_422 = getQ_7_Iheb436_emi78vuj01((*e_4).d_00.kids_0, 0);
    NB8 X60Qx_423 = isAtom_0_emi78vuj01((*X60Qx_422));
    if (X60Qx_423){
      string_0_sysvq0asl X60Qdesugar_13 = joinSeq_0_emi78vuj01(vals_1, (string_0_sysvq0asl){
        .bytes_0 = 2108418u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_424 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 773880830u, .more_0 = (&strlit_0_I10258041648709112440_emi78vuj01)}
      );
      NI32 X60Qx_425 = len_4_sysvq0asl(X60Qdesugar_13);
      NI32 X60Qx_426 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 545071358u, .more_0 = (&strlit_0_I3856878759998182809_emi78vuj01)}
      );
      string_0_sysvq0asl X60Qdesugar_14 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_424 + X60Qx_425)) + X60Qx_426)));
      add_2_sysvq0asl((&X60Qdesugar_14), (string_0_sysvq0asl){
        .bytes_0 = 773880830u, .more_0 = (&strlit_0_I10258041648709112440_emi78vuj01)}
      );
      add_2_sysvq0asl((&X60Qdesugar_14), X60Qdesugar_13);
      add_2_sysvq0asl((&X60Qdesugar_14), (string_0_sysvq0asl){
        .bytes_0 = 545071358u, .more_0 = (&strlit_0_I3856878759998182809_emi78vuj01)}
      );
      string_0_sysvq0asl X60Qtmp_29 = X60Qdesugar_14;
      nimStrWasMoved((&X60Qdesugar_14));
      nimStrDestroy(X60Qdesugar_14);
      nimStrDestroy(X60Qdesugar_13);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(vals_1);
      return X60Qtmp_29;
      nimStrDestroy(X60Qdesugar_14);
      nimStrDestroy(X60Qdesugar_13);}
    string_0_sysvq0asl X60Qdesugar_15 = joinSeq_0_emi78vuj01(vals_1, (string_0_sysvq0asl){
      .bytes_0 = 2108418u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_427 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2128642u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_428 = len_4_sysvq0asl(X60Qdesugar_15);
    NI32 X60Qx_429 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8200194u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_16 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_427 + X60Qx_428)) + X60Qx_429)));
    add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
      .bytes_0 = 2128642u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_16), X60Qdesugar_15);
    add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
      .bytes_0 = 8200194u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_30 = X60Qdesugar_16;
    nimStrWasMoved((&X60Qdesugar_16));
    nimStrDestroy(X60Qdesugar_16);
    nimStrDestroy(X60Qdesugar_15);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(vals_1);
    return X60Qtmp_30;
    nimStrDestroy(X60Qdesugar_16);
    nimStrDestroy(X60Qdesugar_15);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(vals_1);}
  seq_0_Ixdx2fh1_aow7lb5cq1 parts_1 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  NI32 i_14 = 1;
  {
    while (NIM_TRUE){
      NI32 X60Qx_430 = len_3_Il6imzw1_emi78vuj01((*e_4).d_00.kids_0);
      if (i_14 < X60Qx_430){
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_431 = getQ_7_Iheb436_emi78vuj01((*e_4).d_00.kids_0, i_14);
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* kv_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_431));
        NB8 X60Qx_432;
        NB8 X60Qx_433 = isList_0_emi78vuj01(kv_0);
        if (X60Qx_433){
          NB8 X60Qx_434 = eqQ_20_sysvq0asl((*kv_0).d_00.tag_0, (string_0_sysvq0asl){
            .bytes_0 = 7760642u, .more_0 = NIM_NIL}
          );
          X60Qx_432 = X60Qx_434;}
        else {
          X60Qx_432 = NIM_FALSE;}
        if (X60Qx_432){
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_435 = getQ_7_Iheb436_emi78vuj01((*kv_0).d_00.kids_0, 0);
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* fld_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_435));
          string_0_sysvq0asl X60Qx_3;
          nimStrWasMoved((&X60Qx_3));
          NB8 X60Qx_436 = isAtom_0_emi78vuj01(fld_0);
          if (X60Qx_436){
            nimStrDestroy(X60Qx_3);
            string_0_sysvq0asl X60Qx_437 = mangleToC_0_emi78vuj01((*fld_0).d_00.atom_0);
            X60Qx_3 = X60Qx_437;}
          else {
            nimStrDestroy(X60Qx_3);
            string_0_sysvq0asl X60Qx_438 = genExpr_1_emi78vuj01(fld_0);
            X60Qx_3 = X60Qx_438;}
          string_0_sysvq0asl fname_0 = X60Qx_3;
          nimStrWasMoved((&X60Qx_3));
          string_0_sysvq0asl inh_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          NB8 X60Qx_439;
          NB8 X60Qx_440;
          if (2 < (*kv_0).d_00.kids_0.len_0){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_441 = getQ_7_Iheb436_emi78vuj01((*kv_0).d_00.kids_0, 2);
            NB8 X60Qx_442 = isAtom_0_emi78vuj01((*X60Qx_441));
            X60Qx_440 = X60Qx_442;}
          else {
            X60Qx_440 = NIM_FALSE;}
          if (X60Qx_440){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_443 = getQ_7_Iheb436_emi78vuj01((*kv_0).d_00.kids_0, 2);
            NB8 X60Qx_444 = isIntLit_0_emi78vuj01((*(*X60Qx_443)).d_00.atom_0);
            X60Qx_439 = X60Qx_444;}
          else {
            X60Qx_439 = NIM_FALSE;}
          if (X60Qx_439){
            nimStrDestroy(inh_0);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_445 = getQ_7_Iheb436_emi78vuj01((*kv_0).d_00.kids_0, 2);
            NI64 X60Qx_446 = parseI64_0_emi78vuj01((*(*X60Qx_445)).d_00.atom_0);
            string_0_sysvq0asl X60Qx_447 = myRepeat_0_emi78vuj01((string_0_sysvq0asl){
              .bytes_0 = 5320194u, .more_0 = NIM_NIL}
            , ((NI32)X60Qx_446));
            inh_0 = X60Qx_447;}
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_448 = getQ_7_Iheb436_emi78vuj01((*kv_0).d_00.kids_0, 1);
          string_0_sysvq0asl X60Qdesugar_17 = genInit_1_emi78vuj01((*X60Qx_448));
          NI32 X60Qx_449 = len_4_sysvq0asl(inh_0);
          NI32 X60Qx_450 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 11777u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_451 = len_4_sysvq0asl(fname_0);
          NI32 X60Qx_452 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540876803u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_453 = len_4_sysvq0asl(X60Qdesugar_17);
          string_0_sysvq0asl X60Qdesugar_18 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_449 + X60Qx_450)) + X60Qx_451)) + X60Qx_452)) + X60Qx_453)));
          add_2_sysvq0asl((&X60Qdesugar_18), inh_0);
          add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
            .bytes_0 = 11777u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_18), fname_0);
          add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
            .bytes_0 = 540876803u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_18), X60Qdesugar_17);
          string_0_sysvq0asl X60Qtmp_31 = X60Qdesugar_18;
          nimStrWasMoved((&X60Qdesugar_18));
          add_0_Ig6072n_aow7lb5cq1((&parts_1), X60Qtmp_31);
          nimStrDestroy(X60Qdesugar_18);
          nimStrDestroy(X60Qdesugar_17);
          nimStrDestroy(inh_0);
          nimStrDestroy(fname_0);
          nimStrDestroy(X60Qx_3);
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(fld_0);}
        else {
          string_0_sysvq0asl X60Qx_454 = genInit_1_emi78vuj01(kv_0);
          add_0_Ig6072n_aow7lb5cq1((&parts_1), X60Qx_454);}
        inc_1_I6wjjge_aow2h993l1((&i_14));
        eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(kv_0);}
      else {
        break;}}}
  whileStmtLabel_1: ;
  string_0_sysvq0asl X60Qdesugar_19 = joinSeq_0_emi78vuj01(parts_1, (string_0_sysvq0asl){
    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_455 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2128642u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_456 = len_4_sysvq0asl(X60Qdesugar_19);
  NI32 X60Qx_457 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8200194u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_20 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_455 + X60Qx_456)) + X60Qx_457)));
  add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
    .bytes_0 = 2128642u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_20), X60Qdesugar_19);
  add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
    .bytes_0 = 8200194u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qtmp_32 = X60Qdesugar_20;
  nimStrWasMoved((&X60Qdesugar_20));
  nimStrDestroy(X60Qdesugar_20);
  nimStrDestroy(X60Qdesugar_19);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_1);
  return X60Qtmp_32;
  nimStrDestroy(X60Qdesugar_20);
  nimStrDestroy(X60Qdesugar_19);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_1);
  return result_39;
  nimStrDestroy(X60Qdesugar_20);
  nimStrDestroy(X60Qdesugar_19);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_1);
  return result_39;}
string_0_sysvq0asl genConstr_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* e_5){
  string_0_sysvq0asl result_40;
  nimStrWasMoved((&result_40));
  NB8 X60Qx_458;
  NB8 X60Qx_459 = eqQ_20_sysvq0asl((*e_5).d_00.tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I17573272885368898989_emi78vuj01)}
  );
  if (X60Qx_459){
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_460 = getQ_7_Iheb436_emi78vuj01((*e_5).d_00.kids_0, 0);
    NB8 X60Qx_461 = isAtom_0_emi78vuj01((*X60Qx_460));
    X60Qx_458 = (!X60Qx_461);}
  else {
    X60Qx_458 = NIM_FALSE;}
  if (X60Qx_458){
    string_0_sysvq0asl X60Qx_462 = constrBody_0_emi78vuj01(e_5);
    result_40 = X60Qx_462;
    return result_40;}
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_463 = getQ_7_Iheb436_emi78vuj01((*e_5).d_00.kids_0, 0);
  string_0_sysvq0asl X60Qdesugar_21 = genType_1_emi78vuj01((*X60Qx_463));
  string_0_sysvq0asl X60Qdesugar_22 = constrBody_0_emi78vuj01(e_5);
  NI32 X60Qx_464 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_465 = len_4_sysvq0asl(X60Qdesugar_21);
  NI32 X60Qx_466 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_467 = len_4_sysvq0asl(X60Qdesugar_22);
  string_0_sysvq0asl X60Qdesugar_23 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_464 + X60Qx_465)) + X60Qx_466)) + X60Qx_467)));
  add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_23), X60Qdesugar_21);
  add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_23), X60Qdesugar_22);
  string_0_sysvq0asl X60Qtmp_33 = X60Qdesugar_23;
  nimStrWasMoved((&X60Qdesugar_23));
  nimStrDestroy(X60Qdesugar_23);
  nimStrDestroy(X60Qdesugar_22);
  nimStrDestroy(X60Qdesugar_21);
  return X60Qtmp_33;
  nimStrDestroy(X60Qdesugar_23);
  nimStrDestroy(X60Qdesugar_22);
  nimStrDestroy(X60Qdesugar_21);
  return result_40;
  nimStrDestroy(X60Qdesugar_23);
  nimStrDestroy(X60Qdesugar_22);
  nimStrDestroy(X60Qdesugar_21);
  return result_40;}
string_0_sysvq0asl genInit_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* e_6){
  string_0_sysvq0asl result_41;
  nimStrWasMoved((&result_41));
  NB8 X60Qx_468;
  NB8 X60Qx_469;
  if ((!(e_6 == NIM_NIL))){
    NB8 X60Qx_470 = isList_0_emi78vuj01(e_6);
    X60Qx_469 = X60Qx_470;}
  else {
    X60Qx_469 = NIM_FALSE;}
  if (X60Qx_469){
    NB8 X60Qx_471;
    NB8 X60Qx_472 = eqQ_20_sysvq0asl((*e_6).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I17573272885368898989_emi78vuj01)}
    );
    if (X60Qx_472){
      X60Qx_471 = NIM_TRUE;}
    else {
      NB8 X60Qx_473 = eqQ_20_sysvq0asl((*e_6).d_00.tag_0, (string_0_sysvq0asl){
        .bytes_0 = 1868787710u, .more_0 = (&strlit_0_I7084116572891045059_emi78vuj01)}
      );
      X60Qx_471 = X60Qx_473;}
    X60Qx_468 = X60Qx_471;}
  else {
    X60Qx_468 = NIM_FALSE;}
  if (X60Qx_468){
    string_0_sysvq0asl X60Qx_474 = constrBody_0_emi78vuj01(e_6);
    result_41 = X60Qx_474;
    return result_41;}
  string_0_sysvq0asl X60Qx_475 = genExpr_1_emi78vuj01(e_6);
  result_41 = X60Qx_475;
  return result_41;
  return result_41;}
string_0_sysvq0asl genExpr_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* e_7){
  string_0_sysvq0asl result_42;
  nimStrWasMoved((&result_42));
  if (e_7 == NIM_NIL){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  if ((*e_7).d_00.kind_0 == 1){
    string_0_sysvq0asl X60Qx_476 = makeCString_0_emi78vuj01((*e_7).d_00.strVal_0);
    result_42 = X60Qx_476;
    return result_42;}
  if ((*e_7).d_00.kind_0 == 2){
    string_0_sysvq0asl X60Qtmp_34 = toCCharLit_0_emi78vuj01((*e_7).d_00.chrVal_0);
    string_0_sysvq0asl X60Qx_477 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1129195774u, .more_0 = (&strlit_0_I8948425280810671385_emi78vuj01)}
    , X60Qtmp_34);
    result_42 = X60Qx_477;
    nimStrDestroy(X60Qtmp_34);
    return result_42;
    nimStrDestroy(X60Qtmp_34);}
  NB8 X60Qx_478 = isAtom_0_emi78vuj01(e_7);
  if (X60Qx_478){
    string_0_sysvq0asl a_12 = nimStrDup((*e_7).d_00.atom_0);
    NB8 X60Qx_479 = eqQ_20_sysvq0asl(a_12, (string_0_sysvq0asl){
      .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I8572766038233537570_emi78vuj01)}
    );
    if (X60Qx_479){
      nimStrDestroy(a_12);
      return (string_0_sysvq0asl){
        .bytes_0 = 1296649982u, .more_0 = (&strlit_0_I10397369818502852122_emi78vuj01)}
      ;}
    NB8 X60Qx_480 = eqQ_20_sysvq0asl(a_12, (string_0_sysvq0asl){
      .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I3372626016653902757_emi78vuj01)}
    );
    if (X60Qx_480){
      nimStrDestroy(a_12);
      return (string_0_sysvq0asl){
        .bytes_0 = 1296649982u, .more_0 = (&strlit_0_I15144514746646140558_emi78vuj01)}
      ;}
    NB8 X60Qx_481 = eqQ_20_sysvq0asl(a_12, (string_0_sysvq0asl){
      .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
    );
    if (X60Qx_481){
      nimStrDestroy(a_12);
      return (string_0_sysvq0asl){
        .bytes_0 = 1296649982u, .more_0 = (&strlit_0_I14478742859183798749_emi78vuj01)}
      ;}
    NB8 X60Qx_482 = eqQ_20_sysvq0asl(a_12, (string_0_sysvq0asl){
      .bytes_0 = 1718511875u, .more_0 = NIM_NIL}
    );
    if (X60Qx_482){
      nimStrDestroy(a_12);
      return (string_0_sysvq0asl){
        .bytes_0 = 1179535619u, .more_0 = NIM_NIL}
      ;}
    NB8 X60Qx_483 = eqQ_20_sysvq0asl(a_12, (string_0_sysvq0asl){
      .bytes_0 = 1734700798u, .more_0 = (&strlit_0_I186799702831424311_emi78vuj01)}
    );
    if (X60Qx_483){
      nimStrDestroy(a_12);
      return (string_0_sysvq0asl){
        .bytes_0 = 1313418750u, .more_0 = (&strlit_0_I173168012831799858_emi78vuj01)}
      ;}
    NB8 X60Qx_484 = eqQ_20_sysvq0asl(a_12, (string_0_sysvq0asl){
      .bytes_0 = 1851878915u, .more_0 = NIM_NIL}
    );
    if (X60Qx_484){
      nimStrDestroy(a_12);
      return (string_0_sysvq0asl){
        .bytes_0 = 1312902659u, .more_0 = NIM_NIL}
      ;}
    NB8 X60Qx_485 = isUIntLit_0_emi78vuj01(a_12);
    if (X60Qx_485){
      string_0_sysvq0asl X60Qx_486 = genUIntLit_0_emi78vuj01(a_12);
      result_42 = X60Qx_486;
      nimStrDestroy(a_12);
      return result_42;}
    NB8 X60Qx_487 = isIntLit_0_emi78vuj01(a_12);
    if (X60Qx_487){
      string_0_sysvq0asl X60Qx_488 = genIntLit_0_emi78vuj01(a_12);
      result_42 = X60Qx_488;
      nimStrDestroy(a_12);
      return result_42;}
    NB8 X60Qx_489 = isFloatLit_0_emi78vuj01(a_12);
    if (X60Qx_489){
      string_0_sysvq0asl X60Qtmp_35 = a_12;
      nimStrWasMoved((&a_12));
      nimStrDestroy(a_12);
      return X60Qtmp_35;}
    string_0_sysvq0asl X60Qx_490 = symName_0_emi78vuj01(a_12);
    result_42 = X60Qx_490;
    nimStrDestroy(a_12);
    return result_42;
    nimStrDestroy(a_12);}
  NB8 X60Qx_491 = isList_0_emi78vuj01(e_7);
  if ((!X60Qx_491)){
    fail_0_emi78vuj01((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I17332818319346761527_emi78vuj01)}
    );
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl t_9 = nimStrDup((*e_7).d_00.tag_0);
  string_0_sysvq0asl tb_0 = typedBinOp_0_emi78vuj01(t_9);
  NI32 X60Qx_492 = len_4_sysvq0asl(tb_0);
  if (0 < X60Qx_492){
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_493 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
    string_0_sysvq0asl ty_0 = genType_1_emi78vuj01((*X60Qx_493));
    NI32 X60Qx_494 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_495 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_494 - 2)));
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* a_13 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_495));
    NI32 X60Qx_496 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_497 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_496 - 1)));
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* b_4 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_497));
    string_0_sysvq0asl X60Qdesugar_24 = genExpr_1_emi78vuj01(a_13);
    string_0_sysvq0asl X60Qdesugar_25 = genExpr_1_emi78vuj01(b_4);
    NI32 X60Qx_498 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2631682u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_499 = len_4_sysvq0asl(ty_0);
    NI32 X60Qx_500 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2631938u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_501 = len_4_sysvq0asl(X60Qdesugar_24);
    NI32 X60Qx_502 = len_4_sysvq0asl(tb_0);
    NI32 X60Qx_503 = len_4_sysvq0asl(X60Qdesugar_25);
    NI32 X60Qx_504 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2697474u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_26 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_498 + X60Qx_499)) + X60Qx_500)) + X60Qx_501)) + X60Qx_502)) + X60Qx_503)) + X60Qx_504)));
    add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
      .bytes_0 = 2631682u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_26), ty_0);
    add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
      .bytes_0 = 2631938u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_24);
    add_2_sysvq0asl((&X60Qdesugar_26), tb_0);
    add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_25);
    add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
      .bytes_0 = 2697474u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_36 = X60Qdesugar_26;
    nimStrWasMoved((&X60Qdesugar_26));
    nimStrDestroy(X60Qdesugar_26);
    nimStrDestroy(X60Qdesugar_25);
    nimStrDestroy(X60Qdesugar_24);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(b_4);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_13);
    nimStrDestroy(ty_0);
    nimStrDestroy(tb_0);
    nimStrDestroy(t_9);
    return X60Qtmp_36;
    nimStrDestroy(X60Qdesugar_26);
    nimStrDestroy(X60Qdesugar_25);
    nimStrDestroy(X60Qdesugar_24);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(b_4);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_13);
    nimStrDestroy(ty_0);}
  string_0_sysvq0asl cb_0 = cmpBinOp_0_emi78vuj01(t_9);
  NI32 X60Qx_505 = len_4_sysvq0asl(cb_0);
  if (0 < X60Qx_505){
    NI32 X60Qx_506 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_507 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_506 - 2)));
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* a_14 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_507));
    NI32 X60Qx_508 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_509 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_508 - 1)));
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* b_5 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_509));
    string_0_sysvq0asl X60Qdesugar_27 = genExpr_1_emi78vuj01(a_14);
    string_0_sysvq0asl X60Qdesugar_28 = genExpr_1_emi78vuj01(b_5);
    NI32 X60Qx_510 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 10241u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_511 = len_4_sysvq0asl(X60Qdesugar_27);
    NI32 X60Qx_512 = len_4_sysvq0asl(cb_0);
    NI32 X60Qx_513 = len_4_sysvq0asl(X60Qdesugar_28);
    NI32 X60Qx_514 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_29 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_510 + X60Qx_511)) + X60Qx_512)) + X60Qx_513)) + X60Qx_514)));
    add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
      .bytes_0 = 10241u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_29), X60Qdesugar_27);
    add_2_sysvq0asl((&X60Qdesugar_29), cb_0);
    add_2_sysvq0asl((&X60Qdesugar_29), X60Qdesugar_28);
    add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_37 = X60Qdesugar_29;
    nimStrWasMoved((&X60Qdesugar_29));
    nimStrDestroy(X60Qdesugar_29);
    nimStrDestroy(X60Qdesugar_28);
    nimStrDestroy(X60Qdesugar_27);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(b_5);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_14);
    nimStrDestroy(cb_0);
    nimStrDestroy(tb_0);
    nimStrDestroy(t_9);
    return X60Qtmp_37;
    nimStrDestroy(X60Qdesugar_29);
    nimStrDestroy(X60Qdesugar_28);
    nimStrDestroy(X60Qdesugar_27);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(b_5);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_14);}
  NB8 X60Qx_515 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
    .bytes_0 = 1734700547u, .more_0 = NIM_NIL}
  );
  if (X60Qx_515){
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_516 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
    string_0_sysvq0asl X60Qdesugar_30 = genType_1_emi78vuj01((*X60Qx_516));
    NI32 X60Qx_517 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_518 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_517 - 1)));
    string_0_sysvq0asl X60Qdesugar_31 = genExpr_1_emi78vuj01((*X60Qx_518));
    NI32 X60Qx_519 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2631682u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_520 = len_4_sysvq0asl(X60Qdesugar_30);
    NI32 X60Qx_521 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2959618u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_522 = len_4_sysvq0asl(X60Qdesugar_31);
    NI32 X60Qx_523 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_32 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_519 + X60Qx_520)) + X60Qx_521)) + X60Qx_522)) + X60Qx_523)));
    add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
      .bytes_0 = 2631682u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_32), X60Qdesugar_30);
    add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
      .bytes_0 = 2959618u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_32), X60Qdesugar_31);
    add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_38 = X60Qdesugar_32;
    nimStrWasMoved((&X60Qdesugar_32));
    nimStrDestroy(X60Qdesugar_32);
    nimStrDestroy(X60Qdesugar_31);
    nimStrDestroy(X60Qdesugar_30);
    nimStrDestroy(cb_0);
    nimStrDestroy(tb_0);
    nimStrDestroy(t_9);
    return X60Qtmp_38;
    nimStrDestroy(X60Qdesugar_32);
    nimStrDestroy(X60Qdesugar_31);
    nimStrDestroy(X60Qdesugar_30);}
  else {
    NB8 X60Qx_524 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
      .bytes_0 = 1953063678u, .more_0 = (&strlit_0_I6041839086284145320_emi78vuj01)}
    );
    if (X60Qx_524){
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_525 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
      string_0_sysvq0asl X60Qdesugar_33 = genType_1_emi78vuj01((*X60Qx_525));
      NI32 X60Qx_526 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_527 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_526 - 1)));
      string_0_sysvq0asl X60Qdesugar_34 = genExpr_1_emi78vuj01((*X60Qx_527));
      NI32 X60Qx_528 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2631682u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_529 = len_4_sysvq0asl(X60Qdesugar_33);
      NI32 X60Qx_530 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 8268034u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_531 = len_4_sysvq0asl(X60Qdesugar_34);
      NI32 X60Qx_532 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 10497u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_35 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_528 + X60Qx_529)) + X60Qx_530)) + X60Qx_531)) + X60Qx_532)));
      add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
        .bytes_0 = 2631682u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_35), X60Qdesugar_33);
      add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
        .bytes_0 = 8268034u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_35), X60Qdesugar_34);
      add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
        .bytes_0 = 10497u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qtmp_39 = X60Qdesugar_35;
      nimStrWasMoved((&X60Qdesugar_35));
      nimStrDestroy(X60Qdesugar_35);
      nimStrDestroy(X60Qdesugar_34);
      nimStrDestroy(X60Qdesugar_33);
      nimStrDestroy(cb_0);
      nimStrDestroy(tb_0);
      nimStrDestroy(t_9);
      return X60Qtmp_39;
      nimStrDestroy(X60Qdesugar_35);
      nimStrDestroy(X60Qdesugar_34);
      nimStrDestroy(X60Qdesugar_33);}
    else {
      NB8 X60Qx_533 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
        .bytes_0 = 1953459715u, .more_0 = NIM_NIL}
      );
      if (X60Qx_533){
        NI32 X60Qx_534 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_535 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_534 - 1)));
        string_0_sysvq0asl X60Qdesugar_36 = genExpr_1_emi78vuj01((*X60Qx_535));
        NI32 X60Qx_536 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2172930u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_537 = len_4_sysvq0asl(X60Qdesugar_36);
        NI32 X60Qx_538 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 10497u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_37 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_536 + X60Qx_537)) + X60Qx_538)));
        add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
          .bytes_0 = 2172930u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_37), X60Qdesugar_36);
        add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
          .bytes_0 = 10497u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qtmp_40 = X60Qdesugar_37;
        nimStrWasMoved((&X60Qdesugar_37));
        nimStrDestroy(X60Qdesugar_37);
        nimStrDestroy(X60Qdesugar_36);
        nimStrDestroy(cb_0);
        nimStrDestroy(tb_0);
        nimStrDestroy(t_9);
        return X60Qtmp_40;
        nimStrDestroy(X60Qdesugar_37);
        nimStrDestroy(X60Qdesugar_36);}
      else {
        NB8 X60Qx_539;
        NB8 X60Qx_540;
        NB8 X60Qx_541 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
          .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I13909093427330098489_emi78vuj01)}
        );
        if (X60Qx_541){
          X60Qx_540 = NIM_TRUE;}
        else {
          NB8 X60Qx_542 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
            .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2501487269769466366_emi78vuj01)}
          );
          X60Qx_540 = X60Qx_542;}
        if (X60Qx_540){
          X60Qx_539 = NIM_TRUE;}
        else {
          NB8 X60Qx_543 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
            .bytes_0 = 1868785918u, .more_0 = (&strlit_0_I710932595938440230_emi78vuj01)}
          );
          X60Qx_539 = X60Qx_543;}
        if (X60Qx_539){
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_544 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
          string_0_sysvq0asl target_1 = genType_1_emi78vuj01((*X60Qx_544));
          NI32 X60Qx_545 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_546 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_545 - 1)));
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* operand_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_546));
          NB8 X60Qx_45;
          NB8 X60Qx_547;
          NB8 X60Qx_548;
          NB8 X60Qx_549;
          NB8 X60Qx_550;
          NB8 X60Qx_551 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
            .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2501487269769466366_emi78vuj01)}
          );
          if (X60Qx_551){
            X60Qx_550 = NIM_TRUE;}
          else {
            NB8 X60Qx_552 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
              .bytes_0 = 1868785918u, .more_0 = (&strlit_0_I710932595938440230_emi78vuj01)}
            );
            X60Qx_550 = X60Qx_552;}
          if (X60Qx_550){
            NB8 X60Qx_553 = isList_0_emi78vuj01(operand_0);
            X60Qx_549 = X60Qx_553;}
          else {
            X60Qx_549 = NIM_FALSE;}
          if (X60Qx_549){
            NB8 X60Qx_554;
            NB8 X60Qx_555 = eqQ_20_sysvq0asl((*operand_0).d_00.tag_0, (string_0_sysvq0asl){
              .bytes_0 = 1868787710u, .more_0 = (&strlit_0_I7084116572891045059_emi78vuj01)}
            );
            if (X60Qx_555){
              X60Qx_554 = NIM_TRUE;}
            else {
              NB8 X60Qx_556 = eqQ_20_sysvq0asl((*operand_0).d_00.tag_0, (string_0_sysvq0asl){
                .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I17573272885368898989_emi78vuj01)}
              );
              X60Qx_554 = X60Qx_556;}
            X60Qx_548 = X60Qx_554;}
          else {
            X60Qx_548 = NIM_FALSE;}
          if (X60Qx_548){
            X60Qx_547 = (0 < (*operand_0).d_00.kids_0.len_0);}
          else {
            X60Qx_547 = NIM_FALSE;}
          if (X60Qx_547){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_557 = getQ_7_Iheb436_emi78vuj01((*operand_0).d_00.kids_0, 0);
            string_0_sysvq0asl X60Qtmp_41 = genType_1_emi78vuj01((*X60Qx_557));
            NB8 X60Qx_558 = eqQ_20_sysvq0asl(X60Qtmp_41, target_1);
            X60Qx_45 = X60Qx_558;
            nimStrDestroy(X60Qtmp_41);}
          else {
            X60Qx_45 = NIM_FALSE;}
          if (X60Qx_45){
            string_0_sysvq0asl X60Qx_559 = genExpr_1_emi78vuj01(operand_0);
            result_42 = X60Qx_559;
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(operand_0);
            nimStrDestroy(target_1);
            nimStrDestroy(cb_0);
            nimStrDestroy(tb_0);
            nimStrDestroy(t_9);
            return result_42;}
          string_0_sysvq0asl X60Qdesugar_38 = genExpr_1_emi78vuj01(operand_0);
          NI32 X60Qx_560 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2631682u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_561 = len_4_sysvq0asl(target_1);
          NI32 X60Qx_562 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 10497u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_563 = len_4_sysvq0asl(X60Qdesugar_38);
          NI32 X60Qx_564 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 10497u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_39 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_560 + X60Qx_561)) + X60Qx_562)) + X60Qx_563)) + X60Qx_564)));
          add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
            .bytes_0 = 2631682u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_39), target_1);
          add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
            .bytes_0 = 10497u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_39), X60Qdesugar_38);
          add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
            .bytes_0 = 10497u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qtmp_42 = X60Qdesugar_39;
          nimStrWasMoved((&X60Qdesugar_39));
          nimStrDestroy(X60Qdesugar_39);
          nimStrDestroy(X60Qdesugar_38);
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(operand_0);
          nimStrDestroy(target_1);
          nimStrDestroy(cb_0);
          nimStrDestroy(tb_0);
          nimStrDestroy(t_9);
          return X60Qtmp_42;
          nimStrDestroy(X60Qdesugar_39);
          nimStrDestroy(X60Qdesugar_38);
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(operand_0);
          nimStrDestroy(target_1);}
        else {
          NB8 X60Qx_565 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
            .bytes_0 = 1935762174u, .more_0 = (&strlit_0_I4543393450896359795_emi78vuj01)}
          );
          if (X60Qx_565){
            NI32 X60Qx_566 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_567 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_566 - 1)));
            string_0_sysvq0asl expr_0 = genExpr_1_emi78vuj01((*X60Qx_567));
            NI32 level_0 = 1;
            NB8 X60Qx_568;
            NB8 X60Qx_569;
            if (3 <= (*e_7).d_00.kids_0.len_0){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_570 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 1);
              NB8 X60Qx_571 = isAtom_0_emi78vuj01((*X60Qx_570));
              X60Qx_569 = X60Qx_571;}
            else {
              X60Qx_569 = NIM_FALSE;}
            if (X60Qx_569){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_572 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 1);
              NB8 X60Qx_573 = isIntLit_0_emi78vuj01((*(*X60Qx_572)).d_00.atom_0);
              X60Qx_568 = X60Qx_573;}
            else {
              X60Qx_568 = NIM_FALSE;}
            if (X60Qx_568){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_574 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 1);
              NI64 X60Qx_575 = parseI64_0_emi78vuj01((*(*X60Qx_574)).d_00.atom_0);
              level_0 = ((NI32)X60Qx_575);}
            string_0_sysvq0asl X60Qdesugar_40 = myRepeat_0_emi78vuj01((string_0_sysvq0asl){
              .bytes_0 = 5320194u, .more_0 = NIM_NIL}
            , level_0);
            NI32 X60Qx_576 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 10241u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_577 = len_4_sysvq0asl(expr_0);
            NI32 X60Qx_578 = len_4_sysvq0asl(X60Qdesugar_40);
            NI32 X60Qx_579 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 10497u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_41 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_576 + X60Qx_577)) + X60Qx_578)) + X60Qx_579)));
            add_2_sysvq0asl((&X60Qdesugar_41), (string_0_sysvq0asl){
              .bytes_0 = 10241u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_41), expr_0);
            add_2_sysvq0asl((&X60Qdesugar_41), X60Qdesugar_40);
            add_2_sysvq0asl((&X60Qdesugar_41), (string_0_sysvq0asl){
              .bytes_0 = 10497u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qtmp_43 = X60Qdesugar_41;
            nimStrWasMoved((&X60Qdesugar_41));
            nimStrDestroy(X60Qdesugar_41);
            nimStrDestroy(X60Qdesugar_40);
            nimStrDestroy(expr_0);
            nimStrDestroy(cb_0);
            nimStrDestroy(tb_0);
            nimStrDestroy(t_9);
            return X60Qtmp_43;
            nimStrDestroy(X60Qdesugar_41);
            nimStrDestroy(X60Qdesugar_40);
            nimStrDestroy(expr_0);}
          else {
            NB8 X60Qx_580;
            NB8 X60Qx_581;
            NB8 X60Qx_582 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
              .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_der823rwr1)}
            );
            if (X60Qx_582){
              X60Qx_581 = NIM_TRUE;}
            else {
              NB8 X60Qx_583 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_der823rwr1)}
              );
              X60Qx_581 = X60Qx_583;}
            if (X60Qx_581){
              X60Qx_580 = NIM_TRUE;}
            else {
              NB8 X60Qx_584 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                .bytes_0 = 1701736446u, .more_0 = (&strlit_0_I5809186183819720447_emi78vuj01)}
              );
              X60Qx_580 = X60Qx_584;}
            if (X60Qx_580){
              NI32 start_0 = 1;
              NB8 X60Qx_585 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                .bytes_0 = 1701736446u, .more_0 = (&strlit_0_I5809186183819720447_emi78vuj01)}
              );
              if (X60Qx_585){
                start_0 = 2;}
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_586 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(start_0 - 1)));
              string_0_sysvq0asl fn_0 = genExpr_1_emi78vuj01((*X60Qx_586));
              seq_0_Ixdx2fh1_aow7lb5cq1 args_2 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
              NI32 i_15 = start_0;
              {
                while (NIM_TRUE){
                  NI32 X60Qx_587 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
                  if (i_15 < X60Qx_587){
                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_588 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, i_15);
                    string_0_sysvq0asl X60Qx_589 = genExpr_1_emi78vuj01((*X60Qx_588));
                    add_0_Ig6072n_aow7lb5cq1((&args_2), X60Qx_589);
                    inc_1_I6wjjge_aow2h993l1((&i_15));}
                  else {
                    break;}}}
              whileStmtLabel_0: ;
              string_0_sysvq0asl X60Qdesugar_42 = joinSeq_0_emi78vuj01(args_2, (string_0_sysvq0asl){
                .bytes_0 = 2108418u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_590 = len_4_sysvq0asl(fn_0);
              NI32 X60Qx_591 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 10241u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_592 = len_4_sysvq0asl(X60Qdesugar_42);
              NI32 X60Qx_593 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 10497u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_43 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_590 + X60Qx_591)) + X60Qx_592)) + X60Qx_593)));
              add_2_sysvq0asl((&X60Qdesugar_43), fn_0);
              add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
                .bytes_0 = 10241u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_43), X60Qdesugar_42);
              add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
                .bytes_0 = 10497u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qtmp_44 = X60Qdesugar_43;
              nimStrWasMoved((&X60Qdesugar_43));
              nimStrDestroy(X60Qdesugar_43);
              nimStrDestroy(X60Qdesugar_42);
              eQdestroy_1_Ivioh0a_aow7lb5cq1(args_2);
              nimStrDestroy(fn_0);
              nimStrDestroy(cb_0);
              nimStrDestroy(tb_0);
              nimStrDestroy(t_9);
              return X60Qtmp_44;
              nimStrDestroy(X60Qdesugar_43);
              nimStrDestroy(X60Qdesugar_42);
              eQdestroy_1_Ivioh0a_aow7lb5cq1(args_2);
              nimStrDestroy(fn_0);}
            else {
              NB8 X60Qx_594 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                .bytes_0 = 1718973187u, .more_0 = NIM_NIL}
              );
              if (X60Qx_594){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_595 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* val_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_595));
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_596 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 1);
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* suf_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_596));
                NB8 X60Qx_597;
                if ((!(val_0 == NIM_NIL))){
                  X60Qx_597 = ((*val_0).d_00.kind_0 == 1);}
                else {
                  X60Qx_597 = NIM_FALSE;}
                if (X60Qx_597){
                  string_0_sysvq0asl X60Qx_598 = genExpr_1_emi78vuj01(val_0);
                  result_42 = X60Qx_598;
                  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(suf_0);
                  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(val_0);
                  nimStrDestroy(cb_0);
                  nimStrDestroy(tb_0);
                  nimStrDestroy(t_9);
                  return result_42;}
                string_0_sysvq0asl X60Qx_4;
                nimStrWasMoved((&X60Qx_4));
                NB8 X60Qx_599 = isAtom_0_emi78vuj01(suf_0);
                if (X60Qx_599){
                  nimStrDestroy(X60Qx_4);
                  string_0_sysvq0asl X60Qx_600 = nimStrDup((*suf_0).d_00.atom_0);
                  X60Qx_4 = X60Qx_600;}
                else {
                  NB8 X60Qx_601;
                  if ((!(suf_0 == NIM_NIL))){
                    X60Qx_601 = ((*suf_0).d_00.kind_0 == 1);}
                  else {
                    X60Qx_601 = NIM_FALSE;}
                  if (X60Qx_601){
                    nimStrDestroy(X60Qx_4);
                    string_0_sysvq0asl X60Qx_602 = nimStrDup((*suf_0).d_00.strVal_0);
                    X60Qx_4 = X60Qx_602;}
                  else {
                    nimStrDestroy(X60Qx_4);
                    X60Qx_4 = (string_0_sysvq0asl){
                      .bytes_0 = 0u, .more_0 = NIM_NIL}
                    ;}}
                string_0_sysvq0asl sname_0 = X60Qx_4;
                nimStrWasMoved((&X60Qx_4));
                string_0_sysvq0asl ty_1 = suffixType_0_emi78vuj01(sname_0);
                string_0_sysvq0asl X60Qdesugar_44 = genExpr_1_emi78vuj01(val_0);
                NI32 X60Qx_603 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 2631682u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_604 = len_4_sysvq0asl(ty_1);
                NI32 X60Qx_605 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 10497u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_606 = len_4_sysvq0asl(X60Qdesugar_44);
                NI32 X60Qx_607 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 10497u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_45 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_603 + X60Qx_604)) + X60Qx_605)) + X60Qx_606)) + X60Qx_607)));
                add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
                  .bytes_0 = 2631682u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_45), ty_1);
                add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
                  .bytes_0 = 10497u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_45), X60Qdesugar_44);
                add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
                  .bytes_0 = 10497u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qtmp_45 = X60Qdesugar_45;
                nimStrWasMoved((&X60Qdesugar_45));
                nimStrDestroy(X60Qdesugar_45);
                nimStrDestroy(X60Qdesugar_44);
                nimStrDestroy(ty_1);
                nimStrDestroy(sname_0);
                nimStrDestroy(X60Qx_4);
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(suf_0);
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(val_0);
                nimStrDestroy(cb_0);
                nimStrDestroy(tb_0);
                nimStrDestroy(t_9);
                return X60Qtmp_45;
                nimStrDestroy(X60Qdesugar_45);
                nimStrDestroy(X60Qdesugar_44);
                nimStrDestroy(ty_1);
                nimStrDestroy(sname_0);
                nimStrDestroy(X60Qx_4);
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(suf_0);
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(val_0);}
              else {
                NB8 X60Qx_608;
                NB8 X60Qx_609 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                  .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I6487260469238205337_emi78vuj01)}
                );
                if (X60Qx_609){
                  X60Qx_608 = NIM_TRUE;}
                else {
                  NB8 X60Qx_610 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                    .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I13798915436014509391_emi78vuj01)}
                  );
                  X60Qx_608 = X60Qx_610;}
                if (X60Qx_608){
                  NI32 X60Qx_611 = len_3_Il6imzw1_emi78vuj01((*e_7).d_00.kids_0);
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_612 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, ((NI32)(X60Qx_611 - 1)));
                  string_0_sysvq0asl X60Qdesugar_46 = genExpr_1_emi78vuj01((*X60Qx_612));
                  NI32 X60Qx_613 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 10241u, .more_0 = NIM_NIL}
                  );
                  NI32 X60Qx_614 = len_4_sysvq0asl(X60Qdesugar_46);
                  NI32 X60Qx_615 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 10497u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_47 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_613 + X60Qx_614)) + X60Qx_615)));
                  add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
                    .bytes_0 = 10241u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_47), X60Qdesugar_46);
                  add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
                    .bytes_0 = 10497u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qtmp_46 = X60Qdesugar_47;
                  nimStrWasMoved((&X60Qdesugar_47));
                  nimStrDestroy(X60Qdesugar_47);
                  nimStrDestroy(X60Qdesugar_46);
                  nimStrDestroy(cb_0);
                  nimStrDestroy(tb_0);
                  nimStrDestroy(t_9);
                  return X60Qtmp_46;
                  nimStrDestroy(X60Qdesugar_47);
                  nimStrDestroy(X60Qdesugar_46);}
                else {
                  NB8 X60Qx_616 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                    .bytes_0 = 1684300286u, .more_0 = (&strlit_0_I9557201018976274010_emi78vuj01)}
                  );
                  if (X60Qx_616){
                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_617 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
                    string_0_sysvq0asl X60Qdesugar_48 = genExpr_1_emi78vuj01((*X60Qx_617));
                    NI32 X60Qx_618 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 2500610u, .more_0 = NIM_NIL}
                    );
                    NI32 X60Qx_619 = len_4_sysvq0asl(X60Qdesugar_48);
                    NI32 X60Qx_620 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 10497u, .more_0 = NIM_NIL}
                    );
                    string_0_sysvq0asl X60Qdesugar_49 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_618 + X60Qx_619)) + X60Qx_620)));
                    add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
                      .bytes_0 = 2500610u, .more_0 = NIM_NIL}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_49), X60Qdesugar_48);
                    add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
                      .bytes_0 = 10497u, .more_0 = NIM_NIL}
                    );
                    string_0_sysvq0asl X60Qtmp_47 = X60Qdesugar_49;
                    nimStrWasMoved((&X60Qdesugar_49));
                    nimStrDestroy(X60Qdesugar_49);
                    nimStrDestroy(X60Qdesugar_48);
                    nimStrDestroy(cb_0);
                    nimStrDestroy(tb_0);
                    nimStrDestroy(t_9);
                    return X60Qtmp_47;
                    nimStrDestroy(X60Qdesugar_49);
                    nimStrDestroy(X60Qdesugar_48);}
                  else {
                    NB8 X60Qx_621;
                    NB8 X60Qx_622 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                      .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I8939511674443647382_der823rwr1)}
                    );
                    if (X60Qx_622){
                      X60Qx_621 = NIM_TRUE;}
                    else {
                      NB8 X60Qx_623 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                        .bytes_0 = 1701079294u, .more_0 = (&strlit_0_I4196580491060784277_der823rwr1)}
                      );
                      X60Qx_621 = X60Qx_623;}
                    if (X60Qx_621){
                      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_624 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
                      string_0_sysvq0asl X60Qdesugar_50 = genExpr_1_emi78vuj01((*X60Qx_624));
                      NI32 X60Qx_625 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2762754u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_626 = len_4_sysvq0asl(X60Qdesugar_50);
                      NI32 X60Qx_627 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 10497u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_51 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_625 + X60Qx_626)) + X60Qx_627)));
                      add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
                        .bytes_0 = 2762754u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_51), X60Qdesugar_50);
                      add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
                        .bytes_0 = 10497u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qtmp_48 = X60Qdesugar_51;
                      nimStrWasMoved((&X60Qdesugar_51));
                      nimStrDestroy(X60Qdesugar_51);
                      nimStrDestroy(X60Qdesugar_50);
                      nimStrDestroy(cb_0);
                      nimStrDestroy(tb_0);
                      nimStrDestroy(t_9);
                      return X60Qtmp_48;
                      nimStrDestroy(X60Qdesugar_51);
                      nimStrDestroy(X60Qdesugar_50);}
                    else {
                      NB8 X60Qx_628 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                        .bytes_0 = 7627010u, .more_0 = NIM_NIL}
                      );
                      if (X60Qx_628){
                        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_629 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
                        string_0_sysvq0asl X60Qdesugar_52 = genExpr_1_emi78vuj01((*X60Qx_629));
                        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_630 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 1);
                        string_0_sysvq0asl X60Qdesugar_53 = genExpr_1_emi78vuj01((*X60Qx_630));
                        NI32 X60Qx_631 = len_4_sysvq0asl(X60Qdesugar_52);
                        NI32 X60Qx_632 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1533095427u, .more_0 = NIM_NIL}
                        );
                        NI32 X60Qx_633 = len_4_sysvq0asl(X60Qdesugar_53);
                        NI32 X60Qx_634 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 23809u, .more_0 = NIM_NIL}
                        );
                        string_0_sysvq0asl X60Qdesugar_54 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_631 + X60Qx_632)) + X60Qx_633)) + X60Qx_634)));
                        add_2_sysvq0asl((&X60Qdesugar_54), X60Qdesugar_52);
                        add_2_sysvq0asl((&X60Qdesugar_54), (string_0_sysvq0asl){
                          .bytes_0 = 1533095427u, .more_0 = NIM_NIL}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_54), X60Qdesugar_53);
                        add_2_sysvq0asl((&X60Qdesugar_54), (string_0_sysvq0asl){
                          .bytes_0 = 23809u, .more_0 = NIM_NIL}
                        );
                        string_0_sysvq0asl X60Qtmp_49 = X60Qdesugar_54;
                        nimStrWasMoved((&X60Qdesugar_54));
                        nimStrDestroy(X60Qdesugar_54);
                        nimStrDestroy(X60Qdesugar_53);
                        nimStrDestroy(X60Qdesugar_52);
                        nimStrDestroy(cb_0);
                        nimStrDestroy(tb_0);
                        nimStrDestroy(t_9);
                        return X60Qtmp_49;
                        nimStrDestroy(X60Qdesugar_54);
                        nimStrDestroy(X60Qdesugar_53);
                        nimStrDestroy(X60Qdesugar_52);}
                      else {
                        NB8 X60Qx_635 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                          .bytes_0 = 1952542723u, .more_0 = NIM_NIL}
                        );
                        if (X60Qx_635){
                          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_636 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
                          string_0_sysvq0asl X60Qdesugar_55 = genExpr_1_emi78vuj01((*X60Qx_636));
                          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_637 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 1);
                          string_0_sysvq0asl X60Qdesugar_56 = genExpr_1_emi78vuj01((*X60Qx_637));
                          NI32 X60Qx_638 = len_4_sysvq0asl(X60Qdesugar_55);
                          NI32 X60Qx_639 = len_4_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 23297u, .more_0 = NIM_NIL}
                          );
                          NI32 X60Qx_640 = len_4_sysvq0asl(X60Qdesugar_56);
                          NI32 X60Qx_641 = len_4_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 23809u, .more_0 = NIM_NIL}
                          );
                          string_0_sysvq0asl X60Qdesugar_57 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_638 + X60Qx_639)) + X60Qx_640)) + X60Qx_641)));
                          add_2_sysvq0asl((&X60Qdesugar_57), X60Qdesugar_55);
                          add_2_sysvq0asl((&X60Qdesugar_57), (string_0_sysvq0asl){
                            .bytes_0 = 23297u, .more_0 = NIM_NIL}
                          );
                          add_2_sysvq0asl((&X60Qdesugar_57), X60Qdesugar_56);
                          add_2_sysvq0asl((&X60Qdesugar_57), (string_0_sysvq0asl){
                            .bytes_0 = 23809u, .more_0 = NIM_NIL}
                          );
                          string_0_sysvq0asl X60Qtmp_50 = X60Qdesugar_57;
                          nimStrWasMoved((&X60Qdesugar_57));
                          nimStrDestroy(X60Qdesugar_57);
                          nimStrDestroy(X60Qdesugar_56);
                          nimStrDestroy(X60Qdesugar_55);
                          nimStrDestroy(cb_0);
                          nimStrDestroy(tb_0);
                          nimStrDestroy(t_9);
                          return X60Qtmp_50;
                          nimStrDestroy(X60Qdesugar_57);
                          nimStrDestroy(X60Qdesugar_56);
                          nimStrDestroy(X60Qdesugar_55);}
                        else {
                          NB8 X60Qx_642 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                            .bytes_0 = 1953457155u, .more_0 = NIM_NIL}
                          );
                          if (X60Qx_642){
                            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_643 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
                            string_0_sysvq0asl obj_0 = genExpr_1_emi78vuj01((*X60Qx_643));
                            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_644 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 1);
                            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* fld_1 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_644));
                            string_0_sysvq0asl inh_1 = (string_0_sysvq0asl){
                              .bytes_0 = 0u, .more_0 = NIM_NIL}
                            ;
                            NB8 X60Qx_645;
                            NB8 X60Qx_646;
                            if (2 < (*e_7).d_00.kids_0.len_0){
                              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_647 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 2);
                              NB8 X60Qx_648 = isAtom_0_emi78vuj01((*X60Qx_647));
                              X60Qx_646 = X60Qx_648;}
                            else {
                              X60Qx_646 = NIM_FALSE;}
                            if (X60Qx_646){
                              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_649 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 2);
                              NB8 X60Qx_650 = isIntLit_0_emi78vuj01((*(*X60Qx_649)).d_00.atom_0);
                              X60Qx_645 = X60Qx_650;}
                            else {
                              X60Qx_645 = NIM_FALSE;}
                            if (X60Qx_645){
                              nimStrDestroy(inh_1);
                              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_651 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 2);
                              NI64 X60Qx_652 = parseI64_0_emi78vuj01((*(*X60Qx_651)).d_00.atom_0);
                              string_0_sysvq0asl X60Qx_653 = myRepeat_0_emi78vuj01((string_0_sysvq0asl){
                                .bytes_0 = 5320194u, .more_0 = NIM_NIL}
                              , ((NI32)X60Qx_652));
                              inh_1 = X60Qx_653;}
                            string_0_sysvq0asl X60Qx_5;
                            nimStrWasMoved((&X60Qx_5));
                            NB8 X60Qx_654 = isAtom_0_emi78vuj01(fld_1);
                            if (X60Qx_654){
                              nimStrDestroy(X60Qx_5);
                              string_0_sysvq0asl X60Qx_655 = mangleToC_0_emi78vuj01((*fld_1).d_00.atom_0);
                              X60Qx_5 = X60Qx_655;}
                            else {
                              nimStrDestroy(X60Qx_5);
                              string_0_sysvq0asl X60Qx_656 = genExpr_1_emi78vuj01(fld_1);
                              X60Qx_5 = X60Qx_656;}
                            string_0_sysvq0asl fname_1 = X60Qx_5;
                            nimStrWasMoved((&X60Qx_5));
                            NI32 X60Qx_657 = len_4_sysvq0asl(obj_0);
                            NI32 X60Qx_658 = len_4_sysvq0asl(inh_1);
                            NI32 X60Qx_659 = len_4_sysvq0asl((string_0_sysvq0asl){
                              .bytes_0 = 11777u, .more_0 = NIM_NIL}
                            );
                            NI32 X60Qx_660 = len_4_sysvq0asl(fname_1);
                            string_0_sysvq0asl X60Qdesugar_58 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_657 + X60Qx_658)) + X60Qx_659)) + X60Qx_660)));
                            add_2_sysvq0asl((&X60Qdesugar_58), obj_0);
                            add_2_sysvq0asl((&X60Qdesugar_58), inh_1);
                            add_2_sysvq0asl((&X60Qdesugar_58), (string_0_sysvq0asl){
                              .bytes_0 = 11777u, .more_0 = NIM_NIL}
                            );
                            add_2_sysvq0asl((&X60Qdesugar_58), fname_1);
                            string_0_sysvq0asl X60Qtmp_51 = X60Qdesugar_58;
                            nimStrWasMoved((&X60Qdesugar_58));
                            nimStrDestroy(X60Qdesugar_58);
                            nimStrDestroy(fname_1);
                            nimStrDestroy(X60Qx_5);
                            nimStrDestroy(inh_1);
                            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(fld_1);
                            nimStrDestroy(obj_0);
                            nimStrDestroy(cb_0);
                            nimStrDestroy(tb_0);
                            nimStrDestroy(t_9);
                            return X60Qtmp_51;
                            nimStrDestroy(X60Qdesugar_58);
                            nimStrDestroy(fname_1);
                            nimStrDestroy(X60Qx_5);
                            nimStrDestroy(inh_1);
                            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(fld_1);
                            nimStrDestroy(obj_0);}
                          else {
                            NB8 X60Qx_661 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                              .bytes_0 = 2053731326u, .more_0 = (&strlit_0_I14042222260391466396_emi78vuj01)}
                            );
                            if (X60Qx_661){
                              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_662 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
                              string_0_sysvq0asl X60Qdesugar_59 = genType_1_emi78vuj01((*X60Qx_662));
                              NI32 X60Qx_663 = len_4_sysvq0asl((string_0_sysvq0asl){
                                .bytes_0 = 2053731326u, .more_0 = (&strlit_0_I14786653231029836613_emi78vuj01)}
                              );
                              NI32 X60Qx_664 = len_4_sysvq0asl(X60Qdesugar_59);
                              NI32 X60Qx_665 = len_4_sysvq0asl((string_0_sysvq0asl){
                                .bytes_0 = 10497u, .more_0 = NIM_NIL}
                              );
                              string_0_sysvq0asl X60Qdesugar_60 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_663 + X60Qx_664)) + X60Qx_665)));
                              add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
                                .bytes_0 = 2053731326u, .more_0 = (&strlit_0_I14786653231029836613_emi78vuj01)}
                              );
                              add_2_sysvq0asl((&X60Qdesugar_60), X60Qdesugar_59);
                              add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
                                .bytes_0 = 10497u, .more_0 = NIM_NIL}
                              );
                              string_0_sysvq0asl X60Qtmp_52 = X60Qdesugar_60;
                              nimStrWasMoved((&X60Qdesugar_60));
                              nimStrDestroy(X60Qdesugar_60);
                              nimStrDestroy(X60Qdesugar_59);
                              nimStrDestroy(cb_0);
                              nimStrDestroy(tb_0);
                              nimStrDestroy(t_9);
                              return X60Qtmp_52;
                              nimStrDestroy(X60Qdesugar_60);
                              nimStrDestroy(X60Qdesugar_59);}
                            else {
                              NB8 X60Qx_666 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                .bytes_0 = 1768710654u, .more_0 = (&strlit_0_I6690414846038512979_emi78vuj01)}
                              );
                              if (X60Qx_666){
                                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_667 = getQ_7_Iheb436_emi78vuj01((*e_7).d_00.kids_0, 0);
                                string_0_sysvq0asl X60Qdesugar_61 = genType_1_emi78vuj01((*X60Qx_667));
                                NI32 X60Qx_668 = len_4_sysvq0asl((string_0_sysvq0asl){
                                  .bytes_0 = 1296649982u, .more_0 = (&strlit_0_I8198489010515551214_emi78vuj01)}
                                );
                                NI32 X60Qx_669 = len_4_sysvq0asl(X60Qdesugar_61);
                                NI32 X60Qx_670 = len_4_sysvq0asl((string_0_sysvq0asl){
                                  .bytes_0 = 10497u, .more_0 = NIM_NIL}
                                );
                                string_0_sysvq0asl X60Qdesugar_62 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_668 + X60Qx_669)) + X60Qx_670)));
                                add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
                                  .bytes_0 = 1296649982u, .more_0 = (&strlit_0_I8198489010515551214_emi78vuj01)}
                                );
                                add_2_sysvq0asl((&X60Qdesugar_62), X60Qdesugar_61);
                                add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
                                  .bytes_0 = 10497u, .more_0 = NIM_NIL}
                                );
                                string_0_sysvq0asl X60Qtmp_53 = X60Qdesugar_62;
                                nimStrWasMoved((&X60Qdesugar_62));
                                nimStrDestroy(X60Qdesugar_62);
                                nimStrDestroy(X60Qdesugar_61);
                                nimStrDestroy(cb_0);
                                nimStrDestroy(tb_0);
                                nimStrDestroy(t_9);
                                return X60Qtmp_53;
                                nimStrDestroy(X60Qdesugar_62);
                                nimStrDestroy(X60Qdesugar_61);}
                              else {
                                NB8 X60Qx_671 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                  .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I8572766038233537570_emi78vuj01)}
                                );
                                if (X60Qx_671){
                                  nimStrDestroy(cb_0);
                                  nimStrDestroy(tb_0);
                                  nimStrDestroy(t_9);
                                  return (string_0_sysvq0asl){
                                    .bytes_0 = 1296649982u, .more_0 = (&strlit_0_I10397369818502852122_emi78vuj01)}
                                  ;}
                                else {
                                  NB8 X60Qx_672 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                    .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I3372626016653902757_emi78vuj01)}
                                  );
                                  if (X60Qx_672){
                                    nimStrDestroy(cb_0);
                                    nimStrDestroy(tb_0);
                                    nimStrDestroy(t_9);
                                    return (string_0_sysvq0asl){
                                      .bytes_0 = 1296649982u, .more_0 = (&strlit_0_I15144514746646140558_emi78vuj01)}
                                    ;}
                                  else {
                                    NB8 X60Qx_673 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                      .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
                                    );
                                    if (X60Qx_673){
                                      nimStrDestroy(cb_0);
                                      nimStrDestroy(tb_0);
                                      nimStrDestroy(t_9);
                                      return (string_0_sysvq0asl){
                                        .bytes_0 = 1296649982u, .more_0 = (&strlit_0_I14478742859183798749_emi78vuj01)}
                                      ;}
                                    else {
                                      NB8 X60Qx_674 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                        .bytes_0 = 1718511875u, .more_0 = NIM_NIL}
                                      );
                                      if (X60Qx_674){
                                        nimStrDestroy(cb_0);
                                        nimStrDestroy(tb_0);
                                        nimStrDestroy(t_9);
                                        return (string_0_sysvq0asl){
                                          .bytes_0 = 1179535619u, .more_0 = NIM_NIL}
                                        ;}
                                      else {
                                        NB8 X60Qx_675 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                          .bytes_0 = 1734700798u, .more_0 = (&strlit_0_I186799702831424311_emi78vuj01)}
                                        );
                                        if (X60Qx_675){
                                          nimStrDestroy(cb_0);
                                          nimStrDestroy(tb_0);
                                          nimStrDestroy(t_9);
                                          return (string_0_sysvq0asl){
                                            .bytes_0 = 1313418750u, .more_0 = (&strlit_0_I173168012831799858_emi78vuj01)}
                                          ;}
                                        else {
                                          NB8 X60Qx_676 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                            .bytes_0 = 1851878915u, .more_0 = NIM_NIL}
                                          );
                                          if (X60Qx_676){
                                            nimStrDestroy(cb_0);
                                            nimStrDestroy(tb_0);
                                            nimStrDestroy(t_9);
                                            return (string_0_sysvq0asl){
                                              .bytes_0 = 1312902659u, .more_0 = NIM_NIL}
                                            ;}
                                          else {
                                            NB8 X60Qx_677;
                                            NB8 X60Qx_678 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                              .bytes_0 = 1868787710u, .more_0 = (&strlit_0_I7084116572891045059_emi78vuj01)}
                                            );
                                            if (X60Qx_678){
                                              X60Qx_677 = NIM_TRUE;}
                                            else {
                                              NB8 X60Qx_679 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                                .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I17573272885368898989_emi78vuj01)}
                                              );
                                              X60Qx_677 = X60Qx_679;}
                                            if (X60Qx_677){
                                              string_0_sysvq0asl X60Qx_680 = genConstr_1_emi78vuj01(e_7);
                                              result_42 = X60Qx_680;
                                              nimStrDestroy(cb_0);
                                              nimStrDestroy(tb_0);
                                              nimStrDestroy(t_9);
                                              return result_42;}
                                            else {
                                              NB8 X60Qx_681 = eqQ_20_sysvq0asl(t_9, (string_0_sysvq0asl){
                                                .bytes_0 = 1719037699u, .more_0 = NIM_NIL}
                                              );
                                              if (X60Qx_681){
                                                nimStrDestroy(cb_0);
                                                nimStrDestroy(tb_0);
                                                nimStrDestroy(t_9);
                                                return (string_0_sysvq0asl){
                                                  .bytes_0 = 1313164542u, .more_0 = (&strlit_0_I10487743831055745770_emi78vuj01)}
                                                ;}
                                              else {
                                                NI32 X60Qx_682 = len_4_sysvq0asl((string_0_sysvq0asl){
                                                  .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I7763259150288237989_emi78vuj01)}
                                                );
                                                NI32 X60Qx_683 = len_4_sysvq0asl(t_9);
                                                NI32 X60Qx_684 = len_4_sysvq0asl((string_0_sysvq0asl){
                                                  .bytes_0 = 9985u, .more_0 = NIM_NIL}
                                                );
                                                string_0_sysvq0asl X60Qdesugar_63 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_682 + X60Qx_683)) + X60Qx_684)));
                                                add_2_sysvq0asl((&X60Qdesugar_63), (string_0_sysvq0asl){
                                                  .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I7763259150288237989_emi78vuj01)}
                                                );
                                                add_2_sysvq0asl((&X60Qdesugar_63), t_9);
                                                add_2_sysvq0asl((&X60Qdesugar_63), (string_0_sysvq0asl){
                                                  .bytes_0 = 9985u, .more_0 = NIM_NIL}
                                                );
                                                fail_0_emi78vuj01(X60Qdesugar_63);
                                                nimStrDestroy(X60Qdesugar_63);
                                                nimStrDestroy(cb_0);
                                                nimStrDestroy(tb_0);
                                                nimStrDestroy(t_9);
                                                return (string_0_sysvq0asl){
                                                  .bytes_0 = 0u, .more_0 = NIM_NIL}
                                                ;
                                                nimStrDestroy(X60Qdesugar_63);}}}}}}}}}}}}}}}}}}}}}}}
  nimStrDestroy(cb_0);
  nimStrDestroy(tb_0);
  nimStrDestroy(t_9);
  return result_42;
  nimStrDestroy(cb_0);
  nimStrDestroy(tb_0);
  nimStrDestroy(t_9);
  return result_42;}
string_0_sysvq0asl genLvalue_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* n_8){
  string_0_sysvq0asl result_43;
  nimStrWasMoved((&result_43));
  NB8 X60Qx_685 = isAtom_0_emi78vuj01(n_8);
  if (X60Qx_685){
    string_0_sysvq0asl X60Qx_686 = symName_0_emi78vuj01((*n_8).d_00.atom_0);
    result_43 = X60Qx_686;
    return result_43;}
  string_0_sysvq0asl X60Qx_687 = genExpr_1_emi78vuj01(n_8);
  result_43 = X60Qx_687;
  return result_43;
  return result_43;}
string_0_sysvq0asl condExpr_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* n_9){
  string_0_sysvq0asl result_44;
  nimStrWasMoved((&result_44));
  NB8 X60Qx_46;
  NB8 X60Qx_688 = isList_0_emi78vuj01(n_9);
  if (X60Qx_688){
    string_0_sysvq0asl X60Qtmp_54 = cmpBinOp_0_emi78vuj01((*n_9).d_00.tag_0);
    NI32 X60Qx_689 = len_4_sysvq0asl(X60Qtmp_54);
    X60Qx_46 = (0 < X60Qx_689);
    nimStrDestroy(X60Qtmp_54);}
  else {
    X60Qx_46 = NIM_FALSE;}
  if (X60Qx_46){
    NI32 X60Qx_690 = len_3_Il6imzw1_emi78vuj01((*n_9).d_00.kids_0);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_691 = getQ_7_Iheb436_emi78vuj01((*n_9).d_00.kids_0, ((NI32)(X60Qx_690 - 2)));
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* a_15 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_691));
    NI32 X60Qx_692 = len_3_Il6imzw1_emi78vuj01((*n_9).d_00.kids_0);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_693 = getQ_7_Iheb436_emi78vuj01((*n_9).d_00.kids_0, ((NI32)(X60Qx_692 - 1)));
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* b_6 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_693));
    string_0_sysvq0asl X60Qdesugar_64 = genExpr_1_emi78vuj01(a_15);
    string_0_sysvq0asl X60Qdesugar_65 = cmpBinOp_0_emi78vuj01((*n_9).d_00.tag_0);
    string_0_sysvq0asl X60Qdesugar_66 = genExpr_1_emi78vuj01(b_6);
    NI32 X60Qx_694 = len_4_sysvq0asl(X60Qdesugar_64);
    NI32 X60Qx_695 = len_4_sysvq0asl(X60Qdesugar_65);
    NI32 X60Qx_696 = len_4_sysvq0asl(X60Qdesugar_66);
    string_0_sysvq0asl X60Qdesugar_67 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_694 + X60Qx_695)) + X60Qx_696)));
    add_2_sysvq0asl((&X60Qdesugar_67), X60Qdesugar_64);
    add_2_sysvq0asl((&X60Qdesugar_67), X60Qdesugar_65);
    add_2_sysvq0asl((&X60Qdesugar_67), X60Qdesugar_66);
    string_0_sysvq0asl X60Qtmp_55 = X60Qdesugar_67;
    nimStrWasMoved((&X60Qdesugar_67));
    nimStrDestroy(X60Qdesugar_67);
    nimStrDestroy(X60Qdesugar_66);
    nimStrDestroy(X60Qdesugar_65);
    nimStrDestroy(X60Qdesugar_64);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(b_6);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_15);
    return X60Qtmp_55;
    nimStrDestroy(X60Qdesugar_67);
    nimStrDestroy(X60Qdesugar_66);
    nimStrDestroy(X60Qdesugar_65);
    nimStrDestroy(X60Qdesugar_64);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(b_6);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_15);}
  string_0_sysvq0asl X60Qx_697 = genExpr_1_emi78vuj01(n_9);
  result_44 = X60Qx_697;
  return result_44;
  return result_44;}
string_0_sysvq0asl declName_0_emi78vuj01(string_0_sysvq0asl name_4, X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pragmas_2){
  string_0_sysvq0asl result_45;
  nimStrWasMoved((&result_45));
  string_0_sysvq0asl ext_0 = externName_0_emi78vuj01(pragmas_2);
  NI32 X60Qx_698 = len_4_sysvq0asl(ext_0);
  if (0 < X60Qx_698){
    string_0_sysvq0asl X60Qtmp_56 = ext_0;
    nimStrWasMoved((&ext_0));
    nimStrDestroy(ext_0);
    return X60Qtmp_56;}
  NB8 X60Qx_699;
  NB8 X60Qx_700 = isList_0_emi78vuj01(pragmas_2);
  if (X60Qx_700){
    X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01){
      .a = {
        (string_0_sysvq0asl){
          .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
        , (string_0_sysvq0asl){
          .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I4862850237857511107_emi78vuj01)}
        , (string_0_sysvq0asl){
          .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}}}
    ;
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_701 = toOpenArray_0_I3urt0l_emi78vuj01((&X60QconstRefTemp_0));
    NB8 X60Qx_702 = hasPragma_0_emi78vuj01(pragmas_2, X60Qx_701);
    X60Qx_699 = X60Qx_702;}
  else {
    X60Qx_699 = NIM_FALSE;}
  if (X60Qx_699){
    string_0_sysvq0asl X60Qx_703 = beforeDot_0_emi78vuj01(name_4);
    result_45 = X60Qx_703;
    nimStrDestroy(ext_0);
    return result_45;}
  string_0_sysvq0asl X60Qx_704 = mangleToC_0_emi78vuj01(name_4);
  result_45 = X60Qx_704;
  nimStrDestroy(ext_0);
  return result_45;
  nimStrDestroy(ext_0);
  return result_45;
  nimStrDestroy(ext_0);
  return result_45;}
string_0_sysvq0asl resultVarOf_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* body_0, NI32 depth_0){
  string_0_sysvq0asl result_46;
  nimStrWasMoved((&result_46));
  nimStrDestroy(result_46);
  result_46 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_705;
  if (body_0 == NIM_NIL){
    X60Qx_705 = NIM_TRUE;}
  else {
    X60Qx_705 = (3 < depth_0);}
  if (X60Qx_705){
    return result_46;}
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_28 = toOpenArray_1_I1gbnw21_emi78vuj01((*body_0).d_00.kids_0);
    NI32 X60Qlf_29 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_706 = len_6_I3x6mi_emi78vuj01(X60Qlf_28);
        if (X60Qlf_29 < X60Qx_706){
          {
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_3 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_28, X60Qlf_29);
              NB8 X60Qx_707 = isList_0_emi78vuj01((*X60Qii_3));
              if ((!X60Qx_707)){
                goto continueLabel_2;}
              NB8 X60Qx_708;
              NB8 X60Qx_709;
              X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I17735862253056247523_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_710 = toOpenArray_0_I3urt0l_emi78vuj01((&X60QconstRefTemp_0));
              NB8 X60Qx_711 = oneOf_0_emi78vuj01((*(*X60Qii_3)).d_00.tag_0, X60Qx_710);
              if (X60Qx_711){
                X60Qx_709 = (1 < (*(*X60Qii_3)).d_00.kids_0.len_0);}
              else {
                X60Qx_709 = NIM_FALSE;}
              if (X60Qx_709){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_712 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                NB8 X60Qx_713 = isAtom_0_emi78vuj01((*X60Qx_712));
                X60Qx_708 = X60Qx_713;}
              else {
                X60Qx_708 = NIM_FALSE;}
              if (X60Qx_708){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_714 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                string_0_sysvq0asl X60Qtmp_57 = beforeDot_0_emi78vuj01((*(*X60Qx_714)).d_00.atom_0);
                NB8 X60Qx_715 = eqQ_20_sysvq0asl(X60Qtmp_57, (string_0_sysvq0asl){
                  .bytes_0 = 1936028414u, .more_0 = (&strlit_0_I2416437014800228590_emi78vuj01)}
                );
                if (X60Qx_715){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_716 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_717 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 1);
                  string_0_sysvq0asl X60Qx_718 = declName_0_emi78vuj01((*(*X60Qx_716)).d_00.atom_0, (*X60Qx_717));
                  result_46 = X60Qx_718;
                  nimStrDestroy(X60Qtmp_57);
                  return result_46;}
                nimStrDestroy(X60Qtmp_57);}
              else {
                X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 X60QconstRefTemp_1 = (X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
                  .a = {
                    (string_0_sysvq0asl){
                      .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_emi78vuj01)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1868788734u, .more_0 = (&strlit_0_I110166545589372112_emi78vuj01)}}}
                ;
                openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_719 = toOpenArray_0_Il5czcd1_emi78vuj01((&X60QconstRefTemp_1));
                NB8 X60Qx_720 = oneOf_0_emi78vuj01((*(*X60Qii_3)).d_00.tag_0, X60Qx_719);
                if (X60Qx_720){
                  string_0_sysvq0asl X60Qii_4 = resultVarOf_0_emi78vuj01((*X60Qii_3), ((NI32)(depth_0 + 1)));
                  NI32 X60Qx_721 = len_4_sysvq0asl(X60Qii_4);
                  if (0 < X60Qx_721){
                    string_0_sysvq0asl X60Qtmp_58 = X60Qii_4;
                    nimStrWasMoved((&X60Qii_4));
                    nimStrDestroy(X60Qii_4);
                    return X60Qtmp_58;}
                  nimStrDestroy(X60Qii_4);}}}
            continueLabel_2: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_29));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_46;}
string_0_sysvq0asl genLocalVar_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* s_11){
  string_0_sysvq0asl result_47;
  nimStrWasMoved((&result_47));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_722 = getQ_7_Iheb436_emi78vuj01((*s_11).d_00.kids_0, 0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* nameAtom_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_722));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_723 = getQ_7_Iheb436_emi78vuj01((*s_11).d_00.kids_0, 1);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pragmas_4 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_723));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_724 = getQ_7_Iheb436_emi78vuj01((*s_11).d_00.kids_0, 2);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* typ_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_724));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_6;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&X60Qx_6));
  if (3 < (*s_11).d_00.kids_0.len_0){
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qx_6);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_725 = getQ_7_Iheb436_emi78vuj01((*s_11).d_00.kids_0, 3);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_726 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_725));
    X60Qx_6 = X60Qx_726;}
  else {
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qx_6);
    X60Qx_6 = NIM_NIL;}
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* value_0 = X60Qx_6;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&X60Qx_6));
  NB8 isConst_0 = eqQ_20_sysvq0asl((*s_11).d_00.tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I12999086881046019782_emi78vuj01)}
  );
  string_0_sysvq0asl X60Qx_7;
  nimStrWasMoved((&X60Qx_7));
  NB8 X60Qx_727 = isAtom_0_emi78vuj01(nameAtom_0);
  if (X60Qx_727){
    nimStrDestroy(X60Qx_7);
    string_0_sysvq0asl X60Qx_728 = declName_0_emi78vuj01((*nameAtom_0).d_00.atom_0, pragmas_4);
    X60Qx_7 = X60Qx_728;}
  else {
    nimStrDestroy(X60Qx_7);
    X60Qx_7 = (string_0_sysvq0asl){
      .bytes_0 = 30209u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl nm_5 = X60Qx_7;
  nimStrWasMoved((&X60Qx_7));
  NB8 X60Qx_729 = isDot_0_emi78vuj01(typ_0);
  if (X60Qx_729){
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(typ_0);
    typ_0 = NIM_NIL;}
  NB8 X60Qx_730;
  if ((!(value_0 == NIM_NIL))){
    NB8 X60Qx_731 = isDot_0_emi78vuj01(value_0);
    X60Qx_730 = (!X60Qx_731);}
  else {
    X60Qx_730 = NIM_FALSE;}
  NB8 hasInit_0 = X60Qx_730;
  string_0_sysvq0asl X60Qx_8;
  nimStrWasMoved((&X60Qx_8));
  if ((!(typ_0 == NIM_NIL))){
    nimStrDestroy(X60Qx_8);
    string_0_sysvq0asl X60Qx_732 = declare_1_emi78vuj01(typ_0, nm_5);
    X60Qx_8 = X60Qx_732;}
  else {
    nimStrDestroy(X60Qx_8);
    string_0_sysvq0asl X60Qx_733 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 541675011u, .more_0 = NIM_NIL}
    , nm_5);
    X60Qx_8 = X60Qx_733;}
  string_0_sysvq0asl decl_0 = X60Qx_8;
  nimStrWasMoved((&X60Qx_8));
  if (isConst_0){
    string_0_sysvq0asl X60Qlhs_59 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I880142495525408379_emi78vuj01)}
    , decl_0);
    nimStrDestroy(decl_0);
    decl_0 = X60Qlhs_59;}
  string_0_sysvq0asl X60Qx_9;
  nimStrWasMoved((&X60Qx_9));
  if (hasInit_0){
    nimStrDestroy(X60Qx_9);
    string_0_sysvq0asl X60Qtmp_60 = genInit_1_emi78vuj01(value_0);
    string_0_sysvq0asl X60Qx_734 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 540876803u, .more_0 = NIM_NIL}
    , X60Qtmp_60);
    X60Qx_9 = X60Qx_734;
    nimStrDestroy(X60Qtmp_60);}
  else {
    nimStrDestroy(X60Qx_9);
    X60Qx_9 = (string_0_sysvq0asl){
      .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2457206680275399171_emi78vuj01)}
    ;}
  string_0_sysvq0asl X60Qdesugar_68 = X60Qx_9;
  nimStrWasMoved((&X60Qx_9));
  NI32 X60Qx_735 = len_4_sysvq0asl(decl_0);
  NI32 X60Qx_736 = len_4_sysvq0asl(X60Qdesugar_68);
  NI32 X60Qx_737 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 15105u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_69 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_735 + X60Qx_736)) + X60Qx_737)));
  add_2_sysvq0asl((&X60Qdesugar_69), decl_0);
  add_2_sysvq0asl((&X60Qdesugar_69), X60Qdesugar_68);
  add_2_sysvq0asl((&X60Qdesugar_69), (string_0_sysvq0asl){
    .bytes_0 = 15105u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qtmp_61 = X60Qdesugar_69;
  nimStrWasMoved((&X60Qdesugar_69));
  nimStrDestroy(X60Qdesugar_69);
  nimStrDestroy(X60Qdesugar_68);
  nimStrDestroy(X60Qx_9);
  nimStrDestroy(decl_0);
  nimStrDestroy(X60Qx_8);
  nimStrDestroy(nm_5);
  nimStrDestroy(X60Qx_7);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(value_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qx_6);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(typ_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_4);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_0);
  return X60Qtmp_61;
  nimStrDestroy(X60Qdesugar_69);
  nimStrDestroy(X60Qdesugar_68);
  nimStrDestroy(X60Qx_9);
  nimStrDestroy(decl_0);
  nimStrDestroy(X60Qx_8);
  nimStrDestroy(nm_5);
  nimStrDestroy(X60Qx_7);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(value_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qx_6);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(typ_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_4);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_0);
  return result_47;
  nimStrDestroy(X60Qdesugar_69);
  nimStrDestroy(X60Qdesugar_68);
  nimStrDestroy(X60Qx_9);
  nimStrDestroy(decl_0);
  nimStrDestroy(X60Qx_8);
  nimStrDestroy(nm_5);
  nimStrDestroy(X60Qx_7);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(value_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qx_6);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(typ_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_4);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_0);
  return result_47;}
string_0_sysvq0asl genIf_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* s_12){
  string_0_sysvq0asl result_48;
  nimStrWasMoved((&result_48));
  string_0_sysvq0asl outp_3 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 firstElif_0 = NIM_TRUE;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_30 = toOpenArray_1_I1gbnw21_emi78vuj01((*s_12).d_00.kids_0);
    NI32 X60Qlf_31 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_738 = len_6_I3x6mi_emi78vuj01(X60Qlf_30);
        if (X60Qlf_31 < X60Qx_738){
          {
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_3 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_30, X60Qlf_31);
              NB8 X60Qx_739 = isList_0_emi78vuj01((*X60Qii_3));
              if ((!X60Qx_739)){
                goto continueLabel_2;}
              NB8 X60Qx_740 = eqQ_20_sysvq0asl((*(*X60Qii_3)).d_00.tag_0, (string_0_sysvq0asl){
                .bytes_0 = 1768711678u, .more_0 = (&strlit_0_I13424873862977158440_emi78vuj01)}
              );
              if (X60Qx_740){
                string_0_sysvq0asl X60Qx_10;
                nimStrWasMoved((&X60Qx_10));
                if (firstElif_0){
                  nimStrDestroy(X60Qx_10);
                  X60Qx_10 = (string_0_sysvq0asl){
                    .bytes_0 = 543582718u, .more_0 = (&strlit_0_I14854076524287435253_emi78vuj01)}
                  ;}
                else {
                  nimStrDestroy(X60Qx_10);
                  X60Qx_10 = (string_0_sysvq0asl){
                    .bytes_0 = 1818566910u, .more_0 = (&strlit_0_I2222881345303884058_emi78vuj01)}
                  ;}
                string_0_sysvq0asl X60Qdesugar_70 = X60Qx_10;
                nimStrWasMoved((&X60Qx_10));
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_741 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                string_0_sysvq0asl X60Qdesugar_71 = condExpr_0_emi78vuj01((*X60Qx_741));
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_742 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 1);
                string_0_sysvq0asl X60Qdesugar_72 = genStmt_1_emi78vuj01((*X60Qx_742));
                NI32 X60Qx_743 = len_4_sysvq0asl(X60Qdesugar_70);
                NI32 X60Qx_744 = len_4_sysvq0asl(X60Qdesugar_71);
                NI32 X60Qx_745 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
                );
                NI32 X60Qx_746 = len_4_sysvq0asl(X60Qdesugar_72);
                NI32 X60Qx_747 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 8194562u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_73 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_743 + X60Qx_744)) + X60Qx_745)) + X60Qx_746)) + X60Qx_747)));
                add_2_sysvq0asl((&X60Qdesugar_73), X60Qdesugar_70);
                add_2_sysvq0asl((&X60Qdesugar_73), X60Qdesugar_71);
                add_2_sysvq0asl((&X60Qdesugar_73), (string_0_sysvq0asl){
                  .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_73), X60Qdesugar_72);
                add_2_sysvq0asl((&X60Qdesugar_73), (string_0_sysvq0asl){
                  .bytes_0 = 8194562u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&outp_3), X60Qdesugar_73);
                firstElif_0 = NIM_FALSE;
                nimStrDestroy(X60Qdesugar_73);
                nimStrDestroy(X60Qdesugar_72);
                nimStrDestroy(X60Qdesugar_71);
                nimStrDestroy(X60Qdesugar_70);
                nimStrDestroy(X60Qx_10);}
              else {
                NB8 X60Qx_748 = eqQ_20_sysvq0asl((*(*X60Qii_3)).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_emi78vuj01)}
                );
                if (X60Qx_748){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_749 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                  string_0_sysvq0asl X60Qdesugar_74 = genStmt_1_emi78vuj01((*X60Qx_749));
                  NI32 X60Qx_750 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1818566910u, .more_0 = (&strlit_0_I2561710370724821732_emi78vuj01)}
                  );
                  NI32 X60Qx_751 = len_4_sysvq0asl(X60Qdesugar_74);
                  NI32 X60Qx_752 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 8194562u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_75 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_750 + X60Qx_751)) + X60Qx_752)));
                  add_2_sysvq0asl((&X60Qdesugar_75), (string_0_sysvq0asl){
                    .bytes_0 = 1818566910u, .more_0 = (&strlit_0_I2561710370724821732_emi78vuj01)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_75), X60Qdesugar_74);
                  add_2_sysvq0asl((&X60Qdesugar_75), (string_0_sysvq0asl){
                    .bytes_0 = 8194562u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&outp_3), X60Qdesugar_75);
                  nimStrDestroy(X60Qdesugar_75);
                  nimStrDestroy(X60Qdesugar_74);}}}
            continueLabel_2: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_31));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qtmp_62 = outp_3;
  nimStrWasMoved((&outp_3));
  nimStrDestroy(outp_3);
  return X60Qtmp_62;
  nimStrDestroy(outp_3);
  return result_48;
  nimStrDestroy(outp_3);
  return result_48;}
string_0_sysvq0asl genCase_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* s_13){
  string_0_sysvq0asl result_49;
  nimStrWasMoved((&result_49));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_753 = getQ_7_Iheb436_emi78vuj01((*s_13).d_00.kids_0, 0);
  string_0_sysvq0asl X60Qdesugar_76 = condExpr_0_emi78vuj01((*X60Qx_753));
  NI32 X60Qx_754 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1769436158u, .more_0 = (&strlit_0_I2767438444989370361_emi78vuj01)}
  );
  NI32 X60Qx_755 = len_4_sysvq0asl(X60Qdesugar_76);
  NI32 X60Qx_756 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_77 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_754 + X60Qx_755)) + X60Qx_756)));
  add_2_sysvq0asl((&X60Qdesugar_77), (string_0_sysvq0asl){
    .bytes_0 = 1769436158u, .more_0 = (&strlit_0_I2767438444989370361_emi78vuj01)}
  );
  add_2_sysvq0asl((&X60Qdesugar_77), X60Qdesugar_76);
  add_2_sysvq0asl((&X60Qdesugar_77), (string_0_sysvq0asl){
    .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
  );
  string_0_sysvq0asl outp_4 = X60Qdesugar_77;
  nimStrWasMoved((&X60Qdesugar_77));
  NI32 i_16 = 1;
  {
    while (NIM_TRUE){
      NI32 X60Qx_757 = len_3_Il6imzw1_emi78vuj01((*s_13).d_00.kids_0);
      if (i_16 < X60Qx_757){
        {
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_758 = getQ_7_Iheb436_emi78vuj01((*s_13).d_00.kids_0, i_16);
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* br_1 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_758));
          inc_1_I6wjjge_aow2h993l1((&i_16));
          NB8 X60Qx_759 = isList_0_emi78vuj01(br_1);
          if ((!X60Qx_759)){
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(br_1);
            goto continueLabel_1;}
          NB8 X60Qx_760 = eqQ_20_sysvq0asl((*br_1).d_00.tag_0, (string_0_sysvq0asl){
            .bytes_0 = 6713090u, .more_0 = NIM_NIL}
          );
          if (X60Qx_760){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_761 = getQ_7_Iheb436_emi78vuj01((*br_1).d_00.kids_0, 0);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* ranges_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_761));
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_762 = getQ_7_Iheb436_emi78vuj01((*br_1).d_00.kids_0, 1);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* body_4 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_762));
            seq_0_Ixdx2fh1_aow7lb5cq1 labels_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
            seq_0_Isutro81_emi78vuj01 vals_2 = newSeqUninit_0_I3hisst_emi78vuj01(0);
            NB8 X60Qx_763;
            NB8 X60Qx_764 = isList_0_emi78vuj01(ranges_0);
            if (X60Qx_764){
              NB8 X60Qx_765 = eqQ_20_sysvq0asl((*ranges_0).d_00.tag_0, (string_0_sysvq0asl){
                .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I10760563625686142994_emi78vuj01)}
              );
              X60Qx_763 = X60Qx_765;}
            else {
              X60Qx_763 = NIM_FALSE;}
            if (X60Qx_763){
              {
                openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_32 = toOpenArray_1_I1gbnw21_emi78vuj01((*ranges_0).d_00.kids_0);
                NI32 X60Qlf_33 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_766 = len_6_I3x6mi_emi78vuj01(X60Qlf_32);
                    if (X60Qlf_33 < X60Qx_766){
                      {
                        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_4 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_32, X60Qlf_33);
                        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_767 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_4));
                        add_0_Iv4n2t31_emi78vuj01((&vals_2), X60Qx_767);}
                      inc_1_I6wjjge_aow2h993l1((&X60Qlf_33));}
                    else {
                      break;}}}
                whileStmtLabel_3: ;}
              forStmtLabel_2: ;}
            else {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_63 = ranges_0;
              eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&ranges_0));
              add_0_Iv4n2t31_emi78vuj01((&vals_2), X60Qtmp_63);}
            {
              openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_34 = toOpenArray_1_I1gbnw21_emi78vuj01(vals_2);
              NI32 X60Qlf_35 = 0;
              {
                while (NIM_TRUE){
                  NI32 X60Qx_768 = len_6_I3x6mi_emi78vuj01(X60Qlf_34);
                  if (X60Qlf_35 < X60Qx_768){
                    {
                      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_7 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_34, X60Qlf_35);
                      NB8 X60Qx_769;
                      NB8 X60Qx_770 = isList_0_emi78vuj01((*X60Qii_7));
                      if (X60Qx_770){
                        NB8 X60Qx_771 = eqQ_20_sysvq0asl((*(*X60Qii_7)).d_00.tag_0, (string_0_sysvq0asl){
                          .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16597999082088934835_emi78vuj01)}
                        );
                        X60Qx_769 = X60Qx_771;}
                      else {
                        X60Qx_769 = NIM_FALSE;}
                      if (X60Qx_769){
                        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_772 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_7)).d_00.kids_0, 0);
                        string_0_sysvq0asl X60Qdesugar_78 = genExpr_1_emi78vuj01((*X60Qx_772));
                        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_773 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_7)).d_00.kids_0, 1);
                        string_0_sysvq0asl X60Qdesugar_79 = genExpr_1_emi78vuj01((*X60Qx_773));
                        NI32 X60Qx_774 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I1967750273193337590_emi78vuj01)}
                        );
                        NI32 X60Qx_775 = len_4_sysvq0asl(X60Qdesugar_78);
                        NI32 X60Qx_776 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 774775038u, .more_0 = (&strlit_0_I11952777697407738927_emi78vuj01)}
                        );
                        NI32 X60Qx_777 = len_4_sysvq0asl(X60Qdesugar_79);
                        NI32 X60Qx_778 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 14849u, .more_0 = NIM_NIL}
                        );
                        string_0_sysvq0asl X60Qdesugar_80 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_774 + X60Qx_775)) + X60Qx_776)) + X60Qx_777)) + X60Qx_778)));
                        add_2_sysvq0asl((&X60Qdesugar_80), (string_0_sysvq0asl){
                          .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I1967750273193337590_emi78vuj01)}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_80), X60Qdesugar_78);
                        add_2_sysvq0asl((&X60Qdesugar_80), (string_0_sysvq0asl){
                          .bytes_0 = 774775038u, .more_0 = (&strlit_0_I11952777697407738927_emi78vuj01)}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_80), X60Qdesugar_79);
                        add_2_sysvq0asl((&X60Qdesugar_80), (string_0_sysvq0asl){
                          .bytes_0 = 14849u, .more_0 = NIM_NIL}
                        );
                        string_0_sysvq0asl X60Qtmp_64 = X60Qdesugar_80;
                        nimStrWasMoved((&X60Qdesugar_80));
                        add_0_Ig6072n_aow7lb5cq1((&labels_0), X60Qtmp_64);
                        nimStrDestroy(X60Qdesugar_80);
                        nimStrDestroy(X60Qdesugar_79);
                        nimStrDestroy(X60Qdesugar_78);}
                      else {
                        string_0_sysvq0asl X60Qdesugar_81 = genExpr_1_emi78vuj01((*X60Qii_7));
                        NI32 X60Qx_779 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I1967750273193337590_emi78vuj01)}
                        );
                        NI32 X60Qx_780 = len_4_sysvq0asl(X60Qdesugar_81);
                        NI32 X60Qx_781 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 14849u, .more_0 = NIM_NIL}
                        );
                        string_0_sysvq0asl X60Qdesugar_82 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_779 + X60Qx_780)) + X60Qx_781)));
                        add_2_sysvq0asl((&X60Qdesugar_82), (string_0_sysvq0asl){
                          .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I1967750273193337590_emi78vuj01)}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_82), X60Qdesugar_81);
                        add_2_sysvq0asl((&X60Qdesugar_82), (string_0_sysvq0asl){
                          .bytes_0 = 14849u, .more_0 = NIM_NIL}
                        );
                        string_0_sysvq0asl X60Qtmp_65 = X60Qdesugar_82;
                        nimStrWasMoved((&X60Qdesugar_82));
                        add_0_Ig6072n_aow7lb5cq1((&labels_0), X60Qtmp_65);
                        nimStrDestroy(X60Qdesugar_82);
                        nimStrDestroy(X60Qdesugar_81);}}
                    inc_1_I6wjjge_aow2h993l1((&X60Qlf_35));}
                  else {
                    break;}}}
              whileStmtLabel_6: ;}
            forStmtLabel_5: ;
            string_0_sysvq0asl X60Qdesugar_83 = joinSeq_0_emi78vuj01(labels_0, (string_0_sysvq0asl){
              .bytes_0 = 2561u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_84 = genStmt_1_emi78vuj01(body_4);
            NI32 X60Qx_782 = len_4_sysvq0asl(X60Qdesugar_83);
            NI32 X60Qx_783 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 175841283u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_784 = len_4_sysvq0asl(X60Qdesugar_84);
            NI32 X60Qx_785 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1919027966u, .more_0 = (&strlit_0_I1164491467687950421_emi78vuj01)}
            );
            string_0_sysvq0asl X60Qdesugar_85 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_782 + X60Qx_783)) + X60Qx_784)) + X60Qx_785)));
            add_2_sysvq0asl((&X60Qdesugar_85), X60Qdesugar_83);
            add_2_sysvq0asl((&X60Qdesugar_85), (string_0_sysvq0asl){
              .bytes_0 = 175841283u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_85), X60Qdesugar_84);
            add_2_sysvq0asl((&X60Qdesugar_85), (string_0_sysvq0asl){
              .bytes_0 = 1919027966u, .more_0 = (&strlit_0_I1164491467687950421_emi78vuj01)}
            );
            add_2_sysvq0asl((&outp_4), X60Qdesugar_85);
            nimStrDestroy(X60Qdesugar_85);
            nimStrDestroy(X60Qdesugar_84);
            nimStrDestroy(X60Qdesugar_83);
            eQdestroy_1_Ia4wwhy1_emi78vuj01(vals_2);
            eQdestroy_1_Ivioh0a_aow7lb5cq1(labels_0);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_4);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ranges_0);}
          else {
            NB8 X60Qx_786 = eqQ_20_sysvq0asl((*br_1).d_00.tag_0, (string_0_sysvq0asl){
              .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_emi78vuj01)}
            );
            if (X60Qx_786){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_787 = getQ_7_Iheb436_emi78vuj01((*br_1).d_00.kids_0, 0);
              string_0_sysvq0asl X60Qdesugar_86 = genStmt_1_emi78vuj01((*X60Qx_787));
              NI32 X60Qx_788 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I5396197078431552478_emi78vuj01)}
              );
              NI32 X60Qx_789 = len_4_sysvq0asl(X60Qdesugar_86);
              NI32 X60Qx_790 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1919027966u, .more_0 = (&strlit_0_I1164491467687950421_emi78vuj01)}
              );
              string_0_sysvq0asl X60Qdesugar_87 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_788 + X60Qx_789)) + X60Qx_790)));
              add_2_sysvq0asl((&X60Qdesugar_87), (string_0_sysvq0asl){
                .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I5396197078431552478_emi78vuj01)}
              );
              add_2_sysvq0asl((&X60Qdesugar_87), X60Qdesugar_86);
              add_2_sysvq0asl((&X60Qdesugar_87), (string_0_sysvq0asl){
                .bytes_0 = 1919027966u, .more_0 = (&strlit_0_I1164491467687950421_emi78vuj01)}
              );
              add_2_sysvq0asl((&outp_4), X60Qdesugar_87);
              nimStrDestroy(X60Qdesugar_87);
              nimStrDestroy(X60Qdesugar_86);}}
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(br_1);}
        continueLabel_1: ;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl X60Qx_791 = ampQ_0_sysvq0asl(outp_4, (string_0_sysvq0asl){
    .bytes_0 = 32001u, .more_0 = NIM_NIL}
  );
  result_49 = X60Qx_791;
  nimStrDestroy(outp_4);
  nimStrDestroy(X60Qdesugar_77);
  nimStrDestroy(X60Qdesugar_76);
  return result_49;
  nimStrDestroy(outp_4);
  nimStrDestroy(X60Qdesugar_77);
  nimStrDestroy(X60Qdesugar_76);
  return result_49;
  nimStrDestroy(outp_4);
  nimStrDestroy(X60Qdesugar_77);
  nimStrDestroy(X60Qdesugar_76);
  return result_49;}
string_0_sysvq0asl genKeepOverflow_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* s_14){
  string_0_sysvq0asl result_50;
  nimStrWasMoved((&result_50));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_792 = getQ_7_Iheb436_emi78vuj01((*s_14).d_00.kids_0, 0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* op_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_792));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_793 = getQ_7_Iheb436_emi78vuj01((*s_14).d_00.kids_0, 1);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* lval_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_793));
  string_0_sysvq0asl builtin_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_794 = eqQ_20_sysvq0asl((*op_0).d_00.tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1684300035u, .more_0 = NIM_NIL}
  );
  if (X60Qx_794){
    nimStrDestroy(builtin_0);
    builtin_0 = (string_0_sysvq0asl){
      .bytes_0 = 1650417662u, .more_0 = (&strlit_0_I7451631847165411357_emi78vuj01)}
    ;}
  else {
    NB8 X60Qx_795 = eqQ_20_sysvq0asl((*op_0).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1651864323u, .more_0 = NIM_NIL}
    );
    if (X60Qx_795){
      nimStrDestroy(builtin_0);
      builtin_0 = (string_0_sysvq0asl){
        .bytes_0 = 1650417662u, .more_0 = (&strlit_0_I10374958816402812404_emi78vuj01)}
      ;}
    else {
      NB8 X60Qx_796 = eqQ_20_sysvq0asl((*op_0).d_00.tag_0, (string_0_sysvq0asl){
        .bytes_0 = 1819634947u, .more_0 = NIM_NIL}
      );
      if (X60Qx_796){
        nimStrDestroy(builtin_0);
        builtin_0 = (string_0_sysvq0asl){
          .bytes_0 = 1650417662u, .more_0 = (&strlit_0_I12661504984193331701_emi78vuj01)}
        ;}}}
  NI32 X60Qx_797 = len_4_sysvq0asl(builtin_0);
  if (X60Qx_797 == 0){
    string_0_sysvq0asl X60Qdesugar_88 = nimStrDup((*op_0).d_00.tag_0);
    NI32 X60Qx_798 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I16103378479668915775_emi78vuj01)}
    );
    NI32 X60Qx_799 = len_4_sysvq0asl(X60Qdesugar_88);
    NI32 X60Qx_800 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_89 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_798 + X60Qx_799)) + X60Qx_800)));
    add_2_sysvq0asl((&X60Qdesugar_89), (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I16103378479668915775_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_89), X60Qdesugar_88);
    add_2_sysvq0asl((&X60Qdesugar_89), (string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    fail_0_emi78vuj01(X60Qdesugar_89);
    nimStrDestroy(X60Qdesugar_89);
    nimStrDestroy(X60Qdesugar_88);
    nimStrDestroy(builtin_0);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(lval_0);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(op_0);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    nimStrDestroy(X60Qdesugar_89);
    nimStrDestroy(X60Qdesugar_88);}
  NI32 X60Qx_801 = len_3_Il6imzw1_emi78vuj01((*op_0).d_00.kids_0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_802 = getQ_7_Iheb436_emi78vuj01((*op_0).d_00.kids_0, ((NI32)(X60Qx_801 - 2)));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* a_16 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_802));
  NI32 X60Qx_803 = len_3_Il6imzw1_emi78vuj01((*op_0).d_00.kids_0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_804 = getQ_7_Iheb436_emi78vuj01((*op_0).d_00.kids_0, ((NI32)(X60Qx_803 - 1)));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* b_7 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_804));
  string_0_sysvq0asl X60Qdesugar_90 = genExpr_1_emi78vuj01(a_16);
  string_0_sysvq0asl X60Qdesugar_91 = genExpr_1_emi78vuj01(b_7);
  string_0_sysvq0asl X60Qdesugar_92 = genLvalue_0_emi78vuj01(lval_0);
  NI32 X60Qx_805 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 543582718u, .more_0 = (&strlit_0_I14854076524287435253_emi78vuj01)}
  );
  NI32 X60Qx_806 = len_4_sysvq0asl(builtin_0);
  NI32 X60Qx_807 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_808 = len_4_sysvq0asl(X60Qdesugar_90);
  NI32 X60Qx_809 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_810 = len_4_sysvq0asl(X60Qdesugar_91);
  NI32 X60Qx_811 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 639642627u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_812 = len_4_sysvq0asl(X60Qdesugar_92);
  NI32 X60Qx_813 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 539568638u, .more_0 = (&strlit_0_I11234898691155026843_emi78vuj01)}
  );
  string_0_sysvq0asl X60Qdesugar_93 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_805 + X60Qx_806)) + X60Qx_807)) + X60Qx_808)) + X60Qx_809)) + X60Qx_810)) + X60Qx_811)) + X60Qx_812)) + X60Qx_813)));
  add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
    .bytes_0 = 543582718u, .more_0 = (&strlit_0_I14854076524287435253_emi78vuj01)}
  );
  add_2_sysvq0asl((&X60Qdesugar_93), builtin_0);
  add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_93), X60Qdesugar_90);
  add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_93), X60Qdesugar_91);
  add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
    .bytes_0 = 639642627u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_93), X60Qdesugar_92);
  add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
    .bytes_0 = 539568638u, .more_0 = (&strlit_0_I11234898691155026843_emi78vuj01)}
  );
  string_0_sysvq0asl X60Qtmp_66 = X60Qdesugar_93;
  nimStrWasMoved((&X60Qdesugar_93));
  nimStrDestroy(X60Qdesugar_93);
  nimStrDestroy(X60Qdesugar_92);
  nimStrDestroy(X60Qdesugar_91);
  nimStrDestroy(X60Qdesugar_90);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(b_7);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_16);
  nimStrDestroy(builtin_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(lval_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(op_0);
  return X60Qtmp_66;
  nimStrDestroy(X60Qdesugar_93);
  nimStrDestroy(X60Qdesugar_92);
  nimStrDestroy(X60Qdesugar_91);
  nimStrDestroy(X60Qdesugar_90);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(b_7);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_16);
  nimStrDestroy(builtin_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(lval_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(op_0);
  return result_50;
  nimStrDestroy(X60Qdesugar_93);
  nimStrDestroy(X60Qdesugar_92);
  nimStrDestroy(X60Qdesugar_91);
  nimStrDestroy(X60Qdesugar_90);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(b_7);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_16);
  nimStrDestroy(builtin_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(lval_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(op_0);
  return result_50;}
string_0_sysvq0asl genStmt_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* s_15){
  string_0_sysvq0asl result_51;
  nimStrWasMoved((&result_51));
  NB8 X60Qx_814 = isDot_0_emi78vuj01(s_15);
  if (X60Qx_814){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NB8 X60Qx_815 = isList_0_emi78vuj01(s_15);
  if ((!X60Qx_815)){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl t_10 = nimStrDup((*s_15).d_00.tag_0);
  NB8 X60Qx_816 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
    .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_emi78vuj01)}
  );
  if (X60Qx_816){
    seq_0_Ixdx2fh1_aow7lb5cq1 parts_2 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    {
      openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_36 = toOpenArray_1_I1gbnw21_emi78vuj01((*s_15).d_00.kids_0);
      NI32 X60Qlf_37 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_817 = len_6_I3x6mi_emi78vuj01(X60Qlf_36);
          if (X60Qlf_37 < X60Qx_817){
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_36, X60Qlf_37);
              string_0_sysvq0asl X60Qii_3 = genStmt_1_emi78vuj01((*X60Qii_2));
              NI32 X60Qx_818 = len_4_sysvq0asl(X60Qii_3);
              if (0 < X60Qx_818){
                string_0_sysvq0asl X60Qtmp_67 = X60Qii_3;
                nimStrWasMoved((&X60Qii_3));
                add_0_Ig6072n_aow7lb5cq1((&parts_2), X60Qtmp_67);}
              nimStrDestroy(X60Qii_3);}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_37));}
          else {
            break;}}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;
    string_0_sysvq0asl X60Qx_819 = joinSeq_0_emi78vuj01(parts_2, (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    result_51 = X60Qx_819;
    eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_2);
    nimStrDestroy(t_10);
    return result_51;
    eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_2);}
  else {
    NB8 X60Qx_820 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
      .bytes_0 = 1868788734u, .more_0 = (&strlit_0_I110166545589372112_emi78vuj01)}
    );
    if (X60Qx_820){
      seq_0_Ixdx2fh1_aow7lb5cq1 parts_3 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
      {
        openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_38 = toOpenArray_1_I1gbnw21_emi78vuj01((*s_15).d_00.kids_0);
        NI32 X60Qlf_39 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_821 = len_6_I3x6mi_emi78vuj01(X60Qlf_38);
            if (X60Qlf_39 < X60Qx_821){
              {
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_6 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_38, X60Qlf_39);
                string_0_sysvq0asl X60Qii_7 = genStmt_1_emi78vuj01((*X60Qii_6));
                NI32 X60Qx_822 = len_4_sysvq0asl(X60Qii_7);
                if (0 < X60Qx_822){
                  string_0_sysvq0asl X60Qtmp_68 = X60Qii_7;
                  nimStrWasMoved((&X60Qii_7));
                  add_0_Ig6072n_aow7lb5cq1((&parts_3), X60Qtmp_68);}
                nimStrDestroy(X60Qii_7);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_39));}
            else {
              break;}}}
        whileStmtLabel_5: ;}
      forStmtLabel_4: ;
      string_0_sysvq0asl X60Qdesugar_94 = joinSeq_0_emi78vuj01(parts_3, (string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_823 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 686850u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_824 = len_4_sysvq0asl(X60Qdesugar_94);
      NI32 X60Qx_825 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 8194562u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_95 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_823 + X60Qx_824)) + X60Qx_825)));
      add_2_sysvq0asl((&X60Qdesugar_95), (string_0_sysvq0asl){
        .bytes_0 = 686850u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_95), X60Qdesugar_94);
      add_2_sysvq0asl((&X60Qdesugar_95), (string_0_sysvq0asl){
        .bytes_0 = 8194562u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qtmp_69 = X60Qdesugar_95;
      nimStrWasMoved((&X60Qdesugar_95));
      nimStrDestroy(X60Qdesugar_95);
      nimStrDestroy(X60Qdesugar_94);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_3);
      nimStrDestroy(t_10);
      return X60Qtmp_69;
      nimStrDestroy(X60Qdesugar_95);
      nimStrDestroy(X60Qdesugar_94);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(parts_3);}
    else {
      NB8 X60Qx_826;
      NB8 X60Qx_827;
      NB8 X60Qx_828;
      NB8 X60Qx_829;
      NB8 X60Qx_830;
      NB8 X60Qx_831;
      NB8 X60Qx_832 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
        .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
      );
      if (X60Qx_832){
        X60Qx_831 = NIM_TRUE;}
      else {
        NB8 X60Qx_833 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
          .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
        );
        X60Qx_831 = X60Qx_833;}
      if (X60Qx_831){
        X60Qx_830 = NIM_TRUE;}
      else {
        NB8 X60Qx_834 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
          .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I17735862253056247523_emi78vuj01)}
        );
        X60Qx_830 = X60Qx_834;}
      if (X60Qx_830){
        X60Qx_829 = NIM_TRUE;}
      else {
        NB8 X60Qx_835 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
          .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I12999086881046019782_emi78vuj01)}
        );
        X60Qx_829 = X60Qx_835;}
      if (X60Qx_829){
        X60Qx_828 = NIM_TRUE;}
      else {
        NB8 X60Qx_836 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
          .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_emi78vuj01)}
        );
        X60Qx_828 = X60Qx_836;}
      if (X60Qx_828){
        X60Qx_827 = NIM_TRUE;}
      else {
        NB8 X60Qx_837 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
          .bytes_0 = 1701603326u, .more_0 = (&strlit_0_I5723805845286553140_emi78vuj01)}
        );
        X60Qx_827 = X60Qx_837;}
      if (X60Qx_827){
        X60Qx_826 = NIM_TRUE;}
      else {
        NB8 X60Qx_838 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
          .bytes_0 = 1635153150u, .more_0 = (&strlit_0_I13046452236886743244_emi78vuj01)}
        );
        X60Qx_826 = X60Qx_838;}
      if (X60Qx_826){
        string_0_sysvq0asl X60Qx_839 = genLocalVar_0_emi78vuj01(s_15);
        result_51 = X60Qx_839;
        nimStrDestroy(t_10);
        return result_51;}
      else {
        NB8 X60Qx_840 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
          .bytes_0 = 1735614974u, .more_0 = (&strlit_0_I2681092370707159476_emi78vuj01)}
        );
        if (X60Qx_840){
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_841 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
          string_0_sysvq0asl X60Qdesugar_96 = genLvalue_0_emi78vuj01((*X60Qx_841));
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_842 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 1);
          string_0_sysvq0asl X60Qdesugar_97 = genExpr_1_emi78vuj01((*X60Qx_842));
          NI32 X60Qx_843 = len_4_sysvq0asl(X60Qdesugar_96);
          NI32 X60Qx_844 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540876803u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_845 = len_4_sysvq0asl(X60Qdesugar_97);
          NI32 X60Qx_846 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 15105u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_98 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_843 + X60Qx_844)) + X60Qx_845)) + X60Qx_846)));
          add_2_sysvq0asl((&X60Qdesugar_98), X60Qdesugar_96);
          add_2_sysvq0asl((&X60Qdesugar_98), (string_0_sysvq0asl){
            .bytes_0 = 540876803u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_98), X60Qdesugar_97);
          add_2_sysvq0asl((&X60Qdesugar_98), (string_0_sysvq0asl){
            .bytes_0 = 15105u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qtmp_70 = X60Qdesugar_98;
          nimStrWasMoved((&X60Qdesugar_98));
          nimStrDestroy(X60Qdesugar_98);
          nimStrDestroy(X60Qdesugar_97);
          nimStrDestroy(X60Qdesugar_96);
          nimStrDestroy(t_10);
          return X60Qtmp_70;
          nimStrDestroy(X60Qdesugar_98);
          nimStrDestroy(X60Qdesugar_97);
          nimStrDestroy(X60Qdesugar_96);}
        else {
          NB8 X60Qx_847 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
            .bytes_0 = 1869902846u, .more_0 = (&strlit_0_I5487391404206283781_emi78vuj01)}
          );
          if (X60Qx_847){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_848 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 1);
            string_0_sysvq0asl X60Qdesugar_99 = genLvalue_0_emi78vuj01((*X60Qx_848));
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_849 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
            string_0_sysvq0asl X60Qdesugar_100 = genExpr_1_emi78vuj01((*X60Qx_849));
            NI32 X60Qx_850 = len_4_sysvq0asl(X60Qdesugar_99);
            NI32 X60Qx_851 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540876803u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_852 = len_4_sysvq0asl(X60Qdesugar_100);
            NI32 X60Qx_853 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 15105u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_101 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_850 + X60Qx_851)) + X60Qx_852)) + X60Qx_853)));
            add_2_sysvq0asl((&X60Qdesugar_101), X60Qdesugar_99);
            add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
              .bytes_0 = 540876803u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_101), X60Qdesugar_100);
            add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
              .bytes_0 = 15105u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qtmp_71 = X60Qdesugar_101;
            nimStrWasMoved((&X60Qdesugar_101));
            nimStrDestroy(X60Qdesugar_101);
            nimStrDestroy(X60Qdesugar_100);
            nimStrDestroy(X60Qdesugar_99);
            nimStrDestroy(t_10);
            return X60Qtmp_71;
            nimStrDestroy(X60Qdesugar_101);
            nimStrDestroy(X60Qdesugar_100);
            nimStrDestroy(X60Qdesugar_99);}
          else {
            NB8 X60Qx_854 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
              .bytes_0 = 1952805379u, .more_0 = NIM_NIL}
            );
            if (X60Qx_854){
              NB8 X60Qx_855;
              NI32 X60Qx_856 = len_3_Il6imzw1_emi78vuj01((*s_15).d_00.kids_0);
              if (X60Qx_856 == 0){
                X60Qx_855 = NIM_TRUE;}
              else {
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_857 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
                NB8 X60Qx_858 = isDot_0_emi78vuj01((*X60Qx_857));
                X60Qx_855 = X60Qx_858;}
              if (X60Qx_855){
                NI32 X60Qx_859 = len_4_sysvq0asl(curResultVar_0_emi78vuj01);
                if (0 < X60Qx_859){
                  NI32 X60Qx_860 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I4685521700204883275_emi78vuj01)}
                  );
                  NI32 X60Qx_861 = len_4_sysvq0asl(curResultVar_0_emi78vuj01);
                  NI32 X60Qx_862 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 15105u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_102 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_860 + X60Qx_861)) + X60Qx_862)));
                  add_2_sysvq0asl((&X60Qdesugar_102), (string_0_sysvq0asl){
                    .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I4685521700204883275_emi78vuj01)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_102), curResultVar_0_emi78vuj01);
                  add_2_sysvq0asl((&X60Qdesugar_102), (string_0_sysvq0asl){
                    .bytes_0 = 15105u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qtmp_72 = X60Qdesugar_102;
                  nimStrWasMoved((&X60Qdesugar_102));
                  nimStrDestroy(X60Qdesugar_102);
                  nimStrDestroy(t_10);
                  return X60Qtmp_72;
                  nimStrDestroy(X60Qdesugar_102);}
                nimStrDestroy(t_10);
                return (string_0_sysvq0asl){
                  .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I13276633450022896848_emi78vuj01)}
                ;}
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_863 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
              string_0_sysvq0asl X60Qdesugar_103 = genExpr_1_emi78vuj01((*X60Qx_863));
              NI32 X60Qx_864 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I4685521700204883275_emi78vuj01)}
              );
              NI32 X60Qx_865 = len_4_sysvq0asl(X60Qdesugar_103);
              NI32 X60Qx_866 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 15105u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_104 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_864 + X60Qx_865)) + X60Qx_866)));
              add_2_sysvq0asl((&X60Qdesugar_104), (string_0_sysvq0asl){
                .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I4685521700204883275_emi78vuj01)}
              );
              add_2_sysvq0asl((&X60Qdesugar_104), X60Qdesugar_103);
              add_2_sysvq0asl((&X60Qdesugar_104), (string_0_sysvq0asl){
                .bytes_0 = 15105u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qtmp_73 = X60Qdesugar_104;
              nimStrWasMoved((&X60Qdesugar_104));
              nimStrDestroy(X60Qdesugar_104);
              nimStrDestroy(X60Qdesugar_103);
              nimStrDestroy(t_10);
              return X60Qtmp_73;
              nimStrDestroy(X60Qdesugar_104);
              nimStrDestroy(X60Qdesugar_103);}
            else {
              NB8 X60Qx_867 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                .bytes_0 = 6711554u, .more_0 = NIM_NIL}
              );
              if (X60Qx_867){
                string_0_sysvq0asl X60Qx_868 = genIf_0_emi78vuj01(s_15);
                result_51 = X60Qx_868;
                nimStrDestroy(t_10);
                return result_51;}
              else {
                NB8 X60Qx_869 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                  .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I13200118161122656888_emi78vuj01)}
                );
                if (X60Qx_869){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_870 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
                  string_0_sysvq0asl X60Qdesugar_105 = condExpr_0_emi78vuj01((*X60Qx_870));
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_871 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 1);
                  string_0_sysvq0asl X60Qdesugar_106 = genStmt_1_emi78vuj01((*X60Qx_871));
                  NI32 X60Qx_872 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I10945407962990715491_emi78vuj01)}
                  );
                  NI32 X60Qx_873 = len_4_sysvq0asl(X60Qdesugar_105);
                  NI32 X60Qx_874 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
                  );
                  NI32 X60Qx_875 = len_4_sysvq0asl(X60Qdesugar_106);
                  NI32 X60Qx_876 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 8194562u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_107 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_872 + X60Qx_873)) + X60Qx_874)) + X60Qx_875)) + X60Qx_876)));
                  add_2_sysvq0asl((&X60Qdesugar_107), (string_0_sysvq0asl){
                    .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I10945407962990715491_emi78vuj01)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_107), X60Qdesugar_105);
                  add_2_sysvq0asl((&X60Qdesugar_107), (string_0_sysvq0asl){
                    .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_107), X60Qdesugar_106);
                  add_2_sysvq0asl((&X60Qdesugar_107), (string_0_sysvq0asl){
                    .bytes_0 = 8194562u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qtmp_74 = X60Qdesugar_107;
                  nimStrWasMoved((&X60Qdesugar_107));
                  nimStrDestroy(X60Qdesugar_107);
                  nimStrDestroy(X60Qdesugar_106);
                  nimStrDestroy(X60Qdesugar_105);
                  nimStrDestroy(t_10);
                  return X60Qtmp_74;
                  nimStrDestroy(X60Qdesugar_107);
                  nimStrDestroy(X60Qdesugar_106);
                  nimStrDestroy(X60Qdesugar_105);}
                else {
                  NB8 X60Qx_877 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                    .bytes_0 = 1869573374u, .more_0 = (&strlit_0_I5622496984824462814_emi78vuj01)}
                  );
                  if (X60Qx_877){
                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_878 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
                    string_0_sysvq0asl pre_0 = genStmt_1_emi78vuj01((*X60Qx_878));
                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_879 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 1);
                    string_0_sysvq0asl cond_0 = genExpr_1_emi78vuj01((*X60Qx_879));
                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_880 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 2);
                    string_0_sysvq0asl body_5 = genStmt_1_emi78vuj01((*X60Qx_880));
                    NI32 X60Qx_881 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I539182870268293778_emi78vuj01)}
                    );
                    NI32 X60Qx_882 = len_4_sysvq0asl(pre_0);
                    NI32 X60Qx_883 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1718160126u, .more_0 = (&strlit_0_I13459072479819566868_emi78vuj01)}
                    );
                    NI32 X60Qx_884 = len_4_sysvq0asl(cond_0);
                    NI32 X60Qx_885 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 539568638u, .more_0 = (&strlit_0_I159017457581697368_emi78vuj01)}
                    );
                    NI32 X60Qx_886 = len_4_sysvq0asl(body_5);
                    NI32 X60Qx_887 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 8194562u, .more_0 = NIM_NIL}
                    );
                    string_0_sysvq0asl X60Qdesugar_108 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_881 + X60Qx_882)) + X60Qx_883)) + X60Qx_884)) + X60Qx_885)) + X60Qx_886)) + X60Qx_887)));
                    add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
                      .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I539182870268293778_emi78vuj01)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_108), pre_0);
                    add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
                      .bytes_0 = 1718160126u, .more_0 = (&strlit_0_I13459072479819566868_emi78vuj01)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_108), cond_0);
                    add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
                      .bytes_0 = 539568638u, .more_0 = (&strlit_0_I159017457581697368_emi78vuj01)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_108), body_5);
                    add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
                      .bytes_0 = 8194562u, .more_0 = NIM_NIL}
                    );
                    string_0_sysvq0asl X60Qtmp_75 = X60Qdesugar_108;
                    nimStrWasMoved((&X60Qdesugar_108));
                    nimStrDestroy(X60Qdesugar_108);
                    nimStrDestroy(body_5);
                    nimStrDestroy(cond_0);
                    nimStrDestroy(pre_0);
                    nimStrDestroy(t_10);
                    return X60Qtmp_75;
                    nimStrDestroy(X60Qdesugar_108);
                    nimStrDestroy(body_5);
                    nimStrDestroy(cond_0);
                    nimStrDestroy(pre_0);}
                  else {
                    NB8 X60Qx_888 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                      .bytes_0 = 1701995262u, .more_0 = (&strlit_0_I8380221545607033154_emi78vuj01)}
                    );
                    if (X60Qx_888){
                      nimStrDestroy(t_10);
                      return (string_0_sysvq0asl){
                        .bytes_0 = 1701995262u, .more_0 = (&strlit_0_I13122058251689318351_emi78vuj01)}
                      ;}
                    else {
                      NB8 X60Qx_889 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2210116261907819816_emi78vuj01)}
                      );
                      if (X60Qx_889){
                        nimStrDestroy(t_10);
                        return (string_0_sysvq0asl){
                          .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I9161030888050616993_emi78vuj01)}
                        ;}
                      else {
                        NB8 X60Qx_890;
                        NB8 X60Qx_891 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                          .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_der823rwr1)}
                        );
                        if (X60Qx_891){
                          X60Qx_890 = NIM_TRUE;}
                        else {
                          NB8 X60Qx_892 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                            .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_der823rwr1)}
                          );
                          X60Qx_890 = X60Qx_892;}
                        if (X60Qx_890){
                          string_0_sysvq0asl X60Qtmp_76 = genExpr_1_emi78vuj01(s_15);
                          string_0_sysvq0asl X60Qx_893 = ampQ_0_sysvq0asl(X60Qtmp_76, (string_0_sysvq0asl){
                            .bytes_0 = 15105u, .more_0 = NIM_NIL}
                          );
                          result_51 = X60Qx_893;
                          nimStrDestroy(X60Qtmp_76);
                          nimStrDestroy(t_10);
                          return result_51;
                          nimStrDestroy(X60Qtmp_76);}
                        else {
                          NB8 X60Qx_894 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                            .bytes_0 = 1701736446u, .more_0 = (&strlit_0_I5809186183819720447_emi78vuj01)}
                          );
                          if (X60Qx_894){
                            string_0_sysvq0asl X60Qtmp_77 = genExpr_1_emi78vuj01(s_15);
                            string_0_sysvq0asl X60Qx_895 = ampQ_0_sysvq0asl(X60Qtmp_77, (string_0_sysvq0asl){
                              .bytes_0 = 15105u, .more_0 = NIM_NIL}
                            );
                            result_51 = X60Qx_895;
                            nimStrDestroy(X60Qtmp_77);
                            nimStrDestroy(t_10);
                            return result_51;
                            nimStrDestroy(X60Qtmp_77);}
                          else {
                            NB8 X60Qx_896 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                              .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I2956720964102846418_emi78vuj01)}
                            );
                            if (X60Qx_896){
                              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_897 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
                              string_0_sysvq0asl X60Qdesugar_109 = genExpr_1_emi78vuj01((*X60Qx_897));
                              NI32 X60Qx_898 = len_4_sysvq0asl((string_0_sysvq0asl){
                                .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I18295878950492138920_emi78vuj01)}
                              );
                              NI32 X60Qx_899 = len_4_sysvq0asl(X60Qdesugar_109);
                              NI32 X60Qx_900 = len_4_sysvq0asl((string_0_sysvq0asl){
                                .bytes_0 = 3877122u, .more_0 = NIM_NIL}
                              );
                              string_0_sysvq0asl X60Qdesugar_110 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_898 + X60Qx_899)) + X60Qx_900)));
                              add_2_sysvq0asl((&X60Qdesugar_110), (string_0_sysvq0asl){
                                .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I18295878950492138920_emi78vuj01)}
                              );
                              add_2_sysvq0asl((&X60Qdesugar_110), X60Qdesugar_109);
                              add_2_sysvq0asl((&X60Qdesugar_110), (string_0_sysvq0asl){
                                .bytes_0 = 3877122u, .more_0 = NIM_NIL}
                              );
                              string_0_sysvq0asl X60Qtmp_78 = X60Qdesugar_110;
                              nimStrWasMoved((&X60Qdesugar_110));
                              nimStrDestroy(X60Qdesugar_110);
                              nimStrDestroy(X60Qdesugar_109);
                              nimStrDestroy(t_10);
                              return X60Qtmp_78;
                              nimStrDestroy(X60Qdesugar_110);
                              nimStrDestroy(X60Qdesugar_109);}
                            else {
                              NB8 X60Qx_901 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                                .bytes_0 = 1650551811u, .more_0 = NIM_NIL}
                              );
                              if (X60Qx_901){
                                string_0_sysvq0asl X60Qx_11;
                                nimStrWasMoved((&X60Qx_11));
                                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_902 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
                                NB8 X60Qx_903 = isAtom_0_emi78vuj01((*X60Qx_902));
                                if (X60Qx_903){
                                  nimStrDestroy(X60Qx_11);
                                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_904 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
                                  string_0_sysvq0asl X60Qx_905 = mangleToC_0_emi78vuj01((*(*X60Qx_904)).d_00.atom_0);
                                  X60Qx_11 = X60Qx_905;}
                                else {
                                  nimStrDestroy(X60Qx_11);
                                  X60Qx_11 = (string_0_sysvq0asl){
                                    .bytes_0 = 19457u, .more_0 = NIM_NIL}
                                  ;}
                                string_0_sysvq0asl nm_6 = X60Qx_11;
                                nimStrWasMoved((&X60Qx_11));
                                string_0_sysvq0asl X60Qx_906 = ampQ_0_sysvq0asl(nm_6, (string_0_sysvq0asl){
                                  .bytes_0 = 991967747u, .more_0 = NIM_NIL}
                                );
                                result_51 = X60Qx_906;
                                nimStrDestroy(nm_6);
                                nimStrDestroy(X60Qx_11);
                                nimStrDestroy(t_10);
                                return result_51;
                                nimStrDestroy(nm_6);
                                nimStrDestroy(X60Qx_11);}
                              else {
                                NB8 X60Qx_907 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                                  .bytes_0 = 1886218755u, .more_0 = NIM_NIL}
                                );
                                if (X60Qx_907){
                                  string_0_sysvq0asl X60Qx_12;
                                  nimStrWasMoved((&X60Qx_12));
                                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_908 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
                                  NB8 X60Qx_909 = isAtom_0_emi78vuj01((*X60Qx_908));
                                  if (X60Qx_909){
                                    nimStrDestroy(X60Qx_12);
                                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_910 = getQ_7_Iheb436_emi78vuj01((*s_15).d_00.kids_0, 0);
                                    string_0_sysvq0asl X60Qx_911 = mangleToC_0_emi78vuj01((*(*X60Qx_910)).d_00.atom_0);
                                    X60Qx_12 = X60Qx_911;}
                                  else {
                                    nimStrDestroy(X60Qx_12);
                                    X60Qx_12 = (string_0_sysvq0asl){
                                      .bytes_0 = 19457u, .more_0 = NIM_NIL}
                                    ;}
                                  string_0_sysvq0asl nm_7 = X60Qx_12;
                                  nimStrWasMoved((&X60Qx_12));
                                  NI32 X60Qx_912 = len_4_sysvq0asl((string_0_sysvq0asl){
                                    .bytes_0 = 1953458174u, .more_0 = (&strlit_0_I10005422671307457589_emi78vuj01)}
                                  );
                                  NI32 X60Qx_913 = len_4_sysvq0asl(nm_7);
                                  NI32 X60Qx_914 = len_4_sysvq0asl((string_0_sysvq0asl){
                                    .bytes_0 = 15105u, .more_0 = NIM_NIL}
                                  );
                                  string_0_sysvq0asl X60Qdesugar_111 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_912 + X60Qx_913)) + X60Qx_914)));
                                  add_2_sysvq0asl((&X60Qdesugar_111), (string_0_sysvq0asl){
                                    .bytes_0 = 1953458174u, .more_0 = (&strlit_0_I10005422671307457589_emi78vuj01)}
                                  );
                                  add_2_sysvq0asl((&X60Qdesugar_111), nm_7);
                                  add_2_sysvq0asl((&X60Qdesugar_111), (string_0_sysvq0asl){
                                    .bytes_0 = 15105u, .more_0 = NIM_NIL}
                                  );
                                  string_0_sysvq0asl X60Qtmp_79 = X60Qdesugar_111;
                                  nimStrWasMoved((&X60Qdesugar_111));
                                  nimStrDestroy(X60Qdesugar_111);
                                  nimStrDestroy(nm_7);
                                  nimStrDestroy(X60Qx_12);
                                  nimStrDestroy(t_10);
                                  return X60Qtmp_79;
                                  nimStrDestroy(X60Qdesugar_111);
                                  nimStrDestroy(nm_7);
                                  nimStrDestroy(X60Qx_12);}
                                else {
                                  NB8 X60Qx_915 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                                    .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_emi78vuj01)}
                                  );
                                  if (X60Qx_915){
                                    string_0_sysvq0asl X60Qx_916 = genCase_0_emi78vuj01(s_15);
                                    result_51 = X60Qx_916;
                                    nimStrDestroy(t_10);
                                    return result_51;}
                                  else {
                                    NB8 X60Qx_917 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                                      .bytes_0 = 1701145598u, .more_0 = (&strlit_0_I6800807151669219983_emi78vuj01)}
                                    );
                                    if (X60Qx_917){
                                      string_0_sysvq0asl X60Qx_918 = genKeepOverflow_0_emi78vuj01(s_15);
                                      result_51 = X60Qx_918;
                                      nimStrDestroy(t_10);
                                      return result_51;}
                                    else {
                                      NB8 X60Qx_919 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                                        .bytes_0 = 1767994110u, .more_0 = (&strlit_0_I6137881024046402116_emi78vuj01)}
                                      );
                                      if (X60Qx_919){
                                        nimStrDestroy(t_10);
                                        return (string_0_sysvq0asl){
                                          .bytes_0 = 539635710u, .more_0 = (&strlit_0_I5553614194453030385_emi78vuj01)}
                                        ;}
                                      else {
                                        NB8 X60Qx_920 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                                          .bytes_0 = 1768777214u, .more_0 = (&strlit_0_I1572551130627868563_emi78vuj01)}
                                        );
                                        if (X60Qx_920){
                                          string_0_sysvq0asl outp_5 = (string_0_sysvq0asl){
                                            .bytes_0 = 0u, .more_0 = NIM_NIL}
                                          ;
                                          {
                                            openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_40 = toOpenArray_1_I1gbnw21_emi78vuj01((*s_15).d_00.kids_0);
                                            NI32 X60Qlf_41 = 0;
                                            {
                                              while (NIM_TRUE){
                                                NI32 X60Qx_921 = len_6_I3x6mi_emi78vuj01(X60Qlf_40);
                                                if (X60Qlf_41 < X60Qx_921){
                                                  {
                                                    {
                                                      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_11 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_40, X60Qlf_41);
                                                      if ((*X60Qii_11) == NIM_NIL){
                                                        goto continueLabel_10;}
                                                      else {
                                                        if ((*(*X60Qii_11)).d_00.kind_0 == 1){
                                                          add_2_sysvq0asl((&outp_5), (*(*X60Qii_11)).d_00.strVal_0);}
                                                        else {
                                                          NB8 X60Qx_922 = isAtom_0_emi78vuj01((*X60Qii_11));
                                                          if (X60Qx_922){
                                                            string_0_sysvq0asl X60Qtmp_80 = mangleToC_0_emi78vuj01((*(*X60Qii_11)).d_00.atom_0);
                                                            add_2_sysvq0asl((&outp_5), X60Qtmp_80);
                                                            nimStrDestroy(X60Qtmp_80);}
                                                          else {
                                                            string_0_sysvq0asl X60Qtmp_81 = genExpr_1_emi78vuj01((*X60Qii_11));
                                                            add_2_sysvq0asl((&outp_5), X60Qtmp_81);
                                                            nimStrDestroy(X60Qtmp_81);}}}}
                                                    continueLabel_10: ;}
                                                  inc_1_I6wjjge_aow2h993l1((&X60Qlf_41));}
                                                else {
                                                  break;}}}
                                            whileStmtLabel_9: ;}
                                          forStmtLabel_8: ;
                                          NB8 X60Qx_923;
                                          NI32 X60Qx_924 = len_4_sysvq0asl(outp_5);
                                          if (0 < X60Qx_924){
                                            NI32 X60Qx_925 = len_4_sysvq0asl(outp_5);
                                            NC8 X60Qx_926 = getQ_9_sysvq0asl(outp_5, ((NI32)(X60Qx_925 - 1)));
                                            X60Qx_923 = (!(X60Qx_926 == (NC8)';'));}
                                          else {
                                            X60Qx_923 = NIM_FALSE;}
                                          if (X60Qx_923){
                                            add_2_sysvq0asl((&outp_5), (string_0_sysvq0asl){
                                              .bytes_0 = 15105u, .more_0 = NIM_NIL}
                                            );}
                                          string_0_sysvq0asl X60Qtmp_82 = outp_5;
                                          nimStrWasMoved((&outp_5));
                                          nimStrDestroy(outp_5);
                                          nimStrDestroy(t_10);
                                          return X60Qtmp_82;
                                          nimStrDestroy(outp_5);}
                                        else {
                                          NB8 X60Qx_927;
                                          NB8 X60Qx_928;
                                          NB8 X60Qx_929 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                                            .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
                                          );
                                          if (X60Qx_929){
                                            X60Qx_928 = NIM_TRUE;}
                                          else {
                                            NB8 X60Qx_930 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                                              .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I18257730313531980409_emi78vuj01)}
                                            );
                                            X60Qx_928 = X60Qx_930;}
                                          if (X60Qx_928){
                                            X60Qx_927 = NIM_TRUE;}
                                          else {
                                            NB8 X60Qx_931 = eqQ_20_sysvq0asl(t_10, (string_0_sysvq0asl){
                                              .bytes_0 = 1919775742u, .more_0 = (&strlit_0_I14941751896671455891_emi78vuj01)}
                                            );
                                            X60Qx_927 = X60Qx_931;}
                                          if (X60Qx_927){
                                            nimStrDestroy(t_10);
                                            return (string_0_sysvq0asl){
                                              .bytes_0 = 0u, .more_0 = NIM_NIL}
                                            ;}
                                          else {
                                            NI32 X60Qx_932 = len_4_sysvq0asl((string_0_sysvq0asl){
                                              .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I10785865655914555941_emi78vuj01)}
                                            );
                                            NI32 X60Qx_933 = len_4_sysvq0asl(t_10);
                                            NI32 X60Qx_934 = len_4_sysvq0asl((string_0_sysvq0asl){
                                              .bytes_0 = 9985u, .more_0 = NIM_NIL}
                                            );
                                            string_0_sysvq0asl X60Qdesugar_112 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_932 + X60Qx_933)) + X60Qx_934)));
                                            add_2_sysvq0asl((&X60Qdesugar_112), (string_0_sysvq0asl){
                                              .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I10785865655914555941_emi78vuj01)}
                                            );
                                            add_2_sysvq0asl((&X60Qdesugar_112), t_10);
                                            add_2_sysvq0asl((&X60Qdesugar_112), (string_0_sysvq0asl){
                                              .bytes_0 = 9985u, .more_0 = NIM_NIL}
                                            );
                                            fail_0_emi78vuj01(X60Qdesugar_112);
                                            nimStrDestroy(X60Qdesugar_112);
                                            nimStrDestroy(t_10);
                                            return (string_0_sysvq0asl){
                                              .bytes_0 = 0u, .more_0 = NIM_NIL}
                                            ;
                                            nimStrDestroy(X60Qdesugar_112);}}}}}}}}}}}}}}}}}}}}}
  nimStrDestroy(t_10);
  return result_51;
  nimStrDestroy(t_10);
  return result_51;}
ProcParts_0_emi78vuj01 procParts_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* p_1){
  ProcParts_0_emi78vuj01 result_52;
  eQwasmovedQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&result_52));
  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&result_52));
  seq_0_Isutro81_emi78vuj01 X60Qx_935 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  result_52 = (ProcParts_0_emi78vuj01){
    .nameAtom_0 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)NIM_NIL), .params_0 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)NIM_NIL), .ret_0 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)NIM_NIL), .body_0 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)NIM_NIL), .pragmas_0 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)NIM_NIL), .pnodes_0 = X60Qx_935}
  ;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qlhs_83 = (&result_52.nameAtom_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qlhs_83));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_936 = getQ_7_Iheb436_emi78vuj01((*p_1).d_00.kids_0, 0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_937 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_936));
  (*X60Qlhs_83) = X60Qx_937;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qlhs_84 = (&result_52.params_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qlhs_84));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_938 = findTag_0_emi78vuj01(p_1, (string_0_sysvq0asl){
    .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_der823rwr1)}
  );
  (*X60Qlhs_84) = X60Qx_938;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qlhs_85 = (&result_52.ret_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qlhs_85));
  (*X60Qlhs_85) = NIM_NIL;
  if ((!(result_52.params_0 == NIM_NIL))){
    NI32 pi_0 = indexOfKid_0_emi78vuj01(p_1, result_52.params_0);
    NI32 X60Qx_939 = len_3_Il6imzw1_emi78vuj01((*p_1).d_00.kids_0);
    if (((NI32)(pi_0 + 1)) < X60Qx_939){
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qlhs_86 = (&result_52.ret_0);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qlhs_86));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_940 = getQ_7_Iheb436_emi78vuj01((*p_1).d_00.kids_0, ((NI32)(pi_0 + 1)));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_941 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_940));
      (*X60Qlhs_86) = X60Qx_941;}}
  else {
    if (1 < (*p_1).d_00.kids_0.len_0){
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qlhs_87 = (&result_52.ret_0);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qlhs_87));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_942 = getQ_7_Iheb436_emi78vuj01((*p_1).d_00.kids_0, 1);
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_943 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_942));
      (*X60Qlhs_87) = X60Qx_943;}}
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qlhs_88 = (&result_52.body_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qlhs_88));
  (*X60Qlhs_88) = NIM_NIL;
  NI32 X60Qx_944 = len_3_Il6imzw1_emi78vuj01((*p_1).d_00.kids_0);
  NI32 j_0 = ((NI32)(X60Qx_944 - 1));
  {
    while (0 <= j_0){
      NB8 X60Qx_945;
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_946 = getQ_7_Iheb436_emi78vuj01((*p_1).d_00.kids_0, j_0);
      NB8 X60Qx_947 = isList_0_emi78vuj01((*X60Qx_946));
      if (X60Qx_947){
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_948 = getQ_7_Iheb436_emi78vuj01((*p_1).d_00.kids_0, j_0);
        NB8 X60Qx_949 = eqQ_20_sysvq0asl((*(*X60Qx_948)).d_00.tag_0, (string_0_sysvq0asl){
          .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_emi78vuj01)}
        );
        X60Qx_945 = X60Qx_949;}
      else {
        X60Qx_945 = NIM_FALSE;}
      if (X60Qx_945){
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qlhs_89 = (&result_52.body_0);
        eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qlhs_89));
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_950 = getQ_7_Iheb436_emi78vuj01((*p_1).d_00.kids_0, j_0);
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_951 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_950));
        (*X60Qlhs_89) = X60Qx_951;
        goto whileStmtLabel_0;}
      dec_1_I0nzoz91_aow7lb5cq1((&j_0));}}
  whileStmtLabel_0: ;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qlhs_90 = (&result_52.pragmas_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qlhs_90));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_952 = findTag_0_emi78vuj01(p_1, (string_0_sysvq0asl){
    .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
  );
  (*X60Qlhs_90) = X60Qx_952;
  seq_0_Isutro81_emi78vuj01* X60Qlhs_91 = (&result_52.pnodes_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*X60Qlhs_91));
  seq_0_Isutro81_emi78vuj01 X60Qx_953 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  (*X60Qlhs_91) = X60Qx_953;
  if ((!(result_52.params_0 == NIM_NIL))){
    {
      openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_42 = toOpenArray_1_I1gbnw21_emi78vuj01((*result_52.params_0).d_00.kids_0);
      NI32 X60Qlf_43 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_954 = len_6_I3x6mi_emi78vuj01(X60Qlf_42);
          if (X60Qlf_43 < X60Qx_954){
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_3 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_42, X60Qlf_43);
              NB8 X60Qx_955;
              NB8 X60Qx_956 = isList_0_emi78vuj01((*X60Qii_3));
              if (X60Qx_956){
                NB8 X60Qx_957 = eqQ_20_sysvq0asl((*(*X60Qii_3)).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I9792473688321036479_emi78vuj01)}
                );
                X60Qx_955 = X60Qx_957;}
              else {
                X60Qx_955 = NIM_FALSE;}
              if (X60Qx_955){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_958 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_3));
                add_0_Iv4n2t31_emi78vuj01((&result_52.pnodes_0), X60Qx_958);}}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_43));}
          else {
            break;}}}
      whileStmtLabel_2: ;}
    forStmtLabel_1: ;}
  return result_52;}
string_0_sysvq0asl procSignature_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* p_2){
  string_0_sysvq0asl result_53;
  nimStrWasMoved((&result_53));
  ProcParts_0_emi78vuj01 pp_0 = procParts_0_emi78vuj01(p_2);
  string_0_sysvq0asl name_8 = declName_0_emi78vuj01((*pp_0.nameAtom_0).d_00.atom_0, pp_0.pragmas_0);
  string_0_sysvq0asl X60Qx_13;
  nimStrWasMoved((&X60Qx_13));
  NB8 X60Qx_959;
  if (pp_0.ret_0 == NIM_NIL){
    X60Qx_959 = NIM_TRUE;}
  else {
    NB8 X60Qx_960 = isDot_0_emi78vuj01(pp_0.ret_0);
    X60Qx_959 = X60Qx_960;}
  if (X60Qx_959){
    nimStrDestroy(X60Qx_13);
    X60Qx_13 = (string_0_sysvq0asl){
      .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
    ;}
  else {
    nimStrDestroy(X60Qx_13);
    string_0_sysvq0asl X60Qx_961 = genType_1_emi78vuj01(pp_0.ret_0);
    X60Qx_13 = X60Qx_961;}
  string_0_sysvq0asl retC_0 = X60Qx_13;
  nimStrWasMoved((&X60Qx_13));
  seq_0_Ixdx2fh1_aow7lb5cq1 args_3 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_44 = toOpenArray_1_I1gbnw21_emi78vuj01(pp_0.pnodes_0);
    NI32 X60Qlf_45 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_962 = len_6_I3x6mi_emi78vuj01(X60Qlf_44);
        if (X60Qlf_45 < X60Qx_962){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_44, X60Qlf_45);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_963 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_2)).d_00.kids_0, 0);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_3 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_963));
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_4 = paramType_0_emi78vuj01((*X60Qii_2));
            NB8 X60Qx_964;
            NB8 X60Qx_965 = isList_0_emi78vuj01(X60Qii_4);
            if (X60Qx_965){
              NB8 X60Qx_966 = eqQ_20_sysvq0asl((*X60Qii_4).d_00.tag_0, (string_0_sysvq0asl){
                .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I14150474136931533575_emi78vuj01)}
              );
              X60Qx_964 = X60Qx_966;}
            else {
              X60Qx_964 = NIM_FALSE;}
            if (X60Qx_964){
              add_0_Ig6072n_aow7lb5cq1((&args_3), (string_0_sysvq0asl){
                .bytes_0 = 774778371u, .more_0 = NIM_NIL}
              );}
            else {
              string_0_sysvq0asl X60Qtmp_92 = mangleToC_0_emi78vuj01((*X60Qii_3).d_00.atom_0);
              string_0_sysvq0asl X60Qx_967 = declare_1_emi78vuj01(X60Qii_4, X60Qtmp_92);
              add_0_Ig6072n_aow7lb5cq1((&args_3), X60Qx_967);
              nimStrDestroy(X60Qtmp_92);}
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_4);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_3);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_45));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl prefix_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_968;
  if ((!(pp_0.pragmas_0 == NIM_NIL))){
    X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01){
      .a = {
        (string_0_sysvq0asl){
          .bytes_0 = 1819175422u, .more_0 = (&strlit_0_I11734088361827745870_emi78vuj01)}}}
    ;
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_969 = toOpenArray_0_If2frt3_emi78vuj01((&X60QconstRefTemp_0));
    NB8 X60Qx_970 = hasPragma_0_emi78vuj01(pp_0.pragmas_0, X60Qx_969);
    X60Qx_968 = X60Qx_970;}
  else {
    X60Qx_968 = NIM_FALSE;}
  if (X60Qx_968){
    nimStrDestroy(prefix_0);
    prefix_0 = (string_0_sysvq0asl){
      .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I13363476113935566349_emi78vuj01)}
    ;}
  string_0_sysvq0asl X60Qx_14;
  nimStrWasMoved((&X60Qx_14));
  if (0 < args_3.len_0){
    nimStrDestroy(X60Qx_14);
    string_0_sysvq0asl X60Qx_971 = joinSeq_0_emi78vuj01(args_3, (string_0_sysvq0asl){
      .bytes_0 = 2108418u, .more_0 = NIM_NIL}
    );
    X60Qx_14 = X60Qx_971;}
  else {
    nimStrDestroy(X60Qx_14);
    X60Qx_14 = (string_0_sysvq0asl){
      .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
    ;}
  string_0_sysvq0asl argStr_2 = X60Qx_14;
  nimStrWasMoved((&X60Qx_14));
  NI32 X60Qx_972 = len_4_sysvq0asl(prefix_0);
  NI32 X60Qx_973 = len_4_sysvq0asl(retC_0);
  NI32 X60Qx_974 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_975 = len_4_sysvq0asl(name_8);
  NI32 X60Qx_976 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_977 = len_4_sysvq0asl(argStr_2);
  NI32 X60Qx_978 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_113 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_972 + X60Qx_973)) + X60Qx_974)) + X60Qx_975)) + X60Qx_976)) + X60Qx_977)) + X60Qx_978)));
  add_2_sysvq0asl((&X60Qdesugar_113), prefix_0);
  add_2_sysvq0asl((&X60Qdesugar_113), retC_0);
  add_2_sysvq0asl((&X60Qdesugar_113), (string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_113), name_8);
  add_2_sysvq0asl((&X60Qdesugar_113), (string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_113), argStr_2);
  add_2_sysvq0asl((&X60Qdesugar_113), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qtmp_93 = X60Qdesugar_113;
  nimStrWasMoved((&X60Qdesugar_113));
  nimStrDestroy(X60Qdesugar_113);
  nimStrDestroy(argStr_2);
  nimStrDestroy(X60Qx_14);
  nimStrDestroy(prefix_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(args_3);
  nimStrDestroy(retC_0);
  nimStrDestroy(X60Qx_13);
  nimStrDestroy(name_8);
  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&pp_0));
  return X60Qtmp_93;
  nimStrDestroy(X60Qdesugar_113);
  nimStrDestroy(argStr_2);
  nimStrDestroy(X60Qx_14);
  nimStrDestroy(prefix_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(args_3);
  nimStrDestroy(retC_0);
  nimStrDestroy(X60Qx_13);
  nimStrDestroy(name_8);
  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&pp_0));
  return result_53;
  nimStrDestroy(X60Qdesugar_113);
  nimStrDestroy(argStr_2);
  nimStrDestroy(X60Qx_14);
  nimStrDestroy(prefix_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(args_3);
  nimStrDestroy(retC_0);
  nimStrDestroy(X60Qx_13);
  nimStrDestroy(name_8);
  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&pp_0));
  return result_53;}
string_0_sysvq0asl genProc_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* p_3){
  string_0_sysvq0asl result_54;
  nimStrWasMoved((&result_54));
  ProcParts_0_emi78vuj01 pp_1 = procParts_0_emi78vuj01(p_3);
  string_0_sysvq0asl sig_0 = procSignature_1_emi78vuj01(p_3);
  if (pp_1.body_0 == NIM_NIL){
    string_0_sysvq0asl X60Qx_979 = ampQ_0_sysvq0asl(sig_0, (string_0_sysvq0asl){
      .bytes_0 = 15105u, .more_0 = NIM_NIL}
    );
    result_54 = X60Qx_979;
    nimStrDestroy(sig_0);
    eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&pp_1));
    return result_54;}
  string_0_sysvq0asl saved_0 = nimStrDup(curResultVar_0_emi78vuj01);
  string_0_sysvq0asl X60Qx_15;
  nimStrWasMoved((&X60Qx_15));
  NB8 X60Qx_980;
  if (pp_1.ret_0 == NIM_NIL){
    X60Qx_980 = NIM_TRUE;}
  else {
    NB8 X60Qx_981 = isDot_0_emi78vuj01(pp_1.ret_0);
    X60Qx_980 = X60Qx_981;}
  if (X60Qx_980){
    nimStrDestroy(X60Qx_15);
    X60Qx_15 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  else {
    nimStrDestroy(X60Qx_15);
    string_0_sysvq0asl X60Qx_982 = resultVarOf_0_emi78vuj01(pp_1.body_0, 0);
    X60Qx_15 = X60Qx_982;}
  nimStrDestroy(curResultVar_0_emi78vuj01);
  curResultVar_0_emi78vuj01 = X60Qx_15;
  nimStrWasMoved((&X60Qx_15));
  string_0_sysvq0asl bodyC_0 = genStmt_1_emi78vuj01(pp_1.body_0);
  nimStrDestroy(curResultVar_0_emi78vuj01);
  curResultVar_0_emi78vuj01 = saved_0;
  nimStrWasMoved((&saved_0));
  NI32 X60Qx_983 = len_4_sysvq0asl(sig_0);
  NI32 X60Qx_984 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 175841283u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_985 = len_4_sysvq0asl(bodyC_0);
  NI32 X60Qx_986 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8194562u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_114 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_983 + X60Qx_984)) + X60Qx_985)) + X60Qx_986)));
  add_2_sysvq0asl((&X60Qdesugar_114), sig_0);
  add_2_sysvq0asl((&X60Qdesugar_114), (string_0_sysvq0asl){
    .bytes_0 = 175841283u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_114), bodyC_0);
  add_2_sysvq0asl((&X60Qdesugar_114), (string_0_sysvq0asl){
    .bytes_0 = 8194562u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qtmp_94 = X60Qdesugar_114;
  nimStrWasMoved((&X60Qdesugar_114));
  nimStrDestroy(X60Qdesugar_114);
  nimStrDestroy(bodyC_0);
  nimStrDestroy(X60Qx_15);
  nimStrDestroy(saved_0);
  nimStrDestroy(sig_0);
  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&pp_1));
  return X60Qtmp_94;
  nimStrDestroy(X60Qdesugar_114);
  nimStrDestroy(bodyC_0);
  nimStrDestroy(X60Qx_15);
  nimStrDestroy(saved_0);
  nimStrDestroy(sig_0);
  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&pp_1));
  return result_54;
  nimStrDestroy(X60Qdesugar_114);
  nimStrDestroy(bodyC_0);
  nimStrDestroy(X60Qx_15);
  nimStrDestroy(saved_0);
  nimStrDestroy(sig_0);
  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&pp_1));
  return result_54;}
NB8 isLiteralNode_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* v_0){
  NB8 result_55;
  if (v_0 == NIM_NIL){
    return NIM_FALSE;}
  NB8 X60Qx_987;
  if ((*v_0).d_00.kind_0 == 1){
    X60Qx_987 = NIM_TRUE;}
  else {
    X60Qx_987 = ((*v_0).d_00.kind_0 == 2);}
  if (X60Qx_987){
    return NIM_TRUE;}
  NB8 X60Qx_988 = isAtom_0_emi78vuj01(v_0);
  if (X60Qx_988){
    string_0_sysvq0asl a_17 = nimStrDup((*v_0).d_00.atom_0);
    NB8 X60Qx_989;
    NB8 X60Qx_990;
    NB8 X60Qx_991;
    NB8 X60Qx_992;
    NB8 X60Qx_993;
    NB8 X60Qx_994;
    NB8 X60Qx_995 = eqQ_20_sysvq0asl(a_17, (string_0_sysvq0asl){
      .bytes_0 = 11777u, .more_0 = NIM_NIL}
    );
    if (X60Qx_995){
      X60Qx_994 = NIM_TRUE;}
    else {
      NB8 X60Qx_996 = eqQ_20_sysvq0asl(a_17, (string_0_sysvq0asl){
        .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I8572766038233537570_emi78vuj01)}
      );
      X60Qx_994 = X60Qx_996;}
    if (X60Qx_994){
      X60Qx_993 = NIM_TRUE;}
    else {
      NB8 X60Qx_997 = eqQ_20_sysvq0asl(a_17, (string_0_sysvq0asl){
        .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I3372626016653902757_emi78vuj01)}
      );
      X60Qx_993 = X60Qx_997;}
    if (X60Qx_993){
      X60Qx_992 = NIM_TRUE;}
    else {
      NB8 X60Qx_998 = eqQ_20_sysvq0asl(a_17, (string_0_sysvq0asl){
        .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
      );
      X60Qx_992 = X60Qx_998;}
    if (X60Qx_992){
      X60Qx_991 = NIM_TRUE;}
    else {
      NB8 X60Qx_999 = isIntLit_0_emi78vuj01(a_17);
      X60Qx_991 = X60Qx_999;}
    if (X60Qx_991){
      X60Qx_990 = NIM_TRUE;}
    else {
      NB8 X60Qx_1000 = isUIntLit_0_emi78vuj01(a_17);
      X60Qx_990 = X60Qx_1000;}
    if (X60Qx_990){
      X60Qx_989 = NIM_TRUE;}
    else {
      NB8 X60Qx_1001 = isFloatLit_0_emi78vuj01(a_17);
      X60Qx_989 = X60Qx_1001;}
    result_55 = X60Qx_989;
    nimStrDestroy(a_17);
    return result_55;
    nimStrDestroy(a_17);}
  NB8 X60Qx_1002 = isList_0_emi78vuj01(v_0);
  if (X60Qx_1002){
    X60Qt_0_IAarraySstring0sysvq0aslS9_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS9_emi78vuj01){
      .a = {
        (string_0_sysvq0asl){
          .bytes_0 = 1718973187u, .more_0 = NIM_NIL}
        , (string_0_sysvq0asl){
          .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I8572766038233537570_emi78vuj01)}
        , (string_0_sysvq0asl){
          .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I3372626016653902757_emi78vuj01)}
        , (string_0_sysvq0asl){
          .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
        , (string_0_sysvq0asl){
          .bytes_0 = 1718511875u, .more_0 = NIM_NIL}
        , (string_0_sysvq0asl){
          .bytes_0 = 1734700798u, .more_0 = (&strlit_0_I186799702831424311_emi78vuj01)}
        , (string_0_sysvq0asl){
          .bytes_0 = 1851878915u, .more_0 = NIM_NIL}
        , (string_0_sysvq0asl){
          .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I13909093427330098489_emi78vuj01)}
        , (string_0_sysvq0asl){
          .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2501487269769466366_emi78vuj01)}}}
    ;
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1003 = toOpenArray_0_Ia0unmf_emi78vuj01((&X60QconstRefTemp_0));
    NB8 X60Qx_1004 = oneOf_0_emi78vuj01((*v_0).d_00.tag_0, X60Qx_1003);
    if (X60Qx_1004){
      return NIM_TRUE;}
    NB8 X60Qx_1005;
    NB8 X60Qx_1006 = eqQ_20_sysvq0asl((*v_0).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I17573272885368898989_emi78vuj01)}
    );
    if (X60Qx_1006){
      X60Qx_1005 = NIM_TRUE;}
    else {
      NB8 X60Qx_1007 = eqQ_20_sysvq0asl((*v_0).d_00.tag_0, (string_0_sysvq0asl){
        .bytes_0 = 1868787710u, .more_0 = (&strlit_0_I7084116572891045059_emi78vuj01)}
      );
      X60Qx_1005 = X60Qx_1007;}
    if (X60Qx_1005){
      NI32 i_17 = 1;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1008 = len_3_Il6imzw1_emi78vuj01((*v_0).d_00.kids_0);
          if (i_17 < X60Qx_1008){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1009 = getQ_7_Iheb436_emi78vuj01((*v_0).d_00.kids_0, i_17);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* k_12 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1009));
            NB8 X60Qx_1010;
            NB8 X60Qx_1011 = isList_0_emi78vuj01(k_12);
            if (X60Qx_1011){
              NB8 X60Qx_1012 = eqQ_20_sysvq0asl((*k_12).d_00.tag_0, (string_0_sysvq0asl){
                .bytes_0 = 7760642u, .more_0 = NIM_NIL}
              );
              X60Qx_1010 = X60Qx_1012;}
            else {
              X60Qx_1010 = NIM_FALSE;}
            if (X60Qx_1010){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1013 = getQ_7_Iheb436_emi78vuj01((*k_12).d_00.kids_0, 1);
              NB8 X60Qx_1014 = isLiteralNode_0_emi78vuj01((*X60Qx_1013));
              if ((!X60Qx_1014)){
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(k_12);
                return NIM_FALSE;}}
            else {
              NB8 X60Qx_1015 = isLiteralNode_0_emi78vuj01(k_12);
              if ((!X60Qx_1015)){
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(k_12);
                return NIM_FALSE;}}
            inc_1_I6wjjge_aow2h993l1((&i_17));
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(k_12);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      return NIM_TRUE;}}
  return NIM_FALSE;
  return result_55;}
GlobalInfo_0_emi78vuj01 genGlobal_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* g_0){
  GlobalInfo_0_emi78vuj01 result_56;
  eQwasmovedQ_SX47lobalX49nfo0emi78vuj01_0_emi78vuj01((&result_56));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1016 = getQ_7_Iheb436_emi78vuj01((*g_0).d_00.kids_0, 0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* nameAtom_1 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1016));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1017 = getQ_7_Iheb436_emi78vuj01((*g_0).d_00.kids_0, 1);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pragmas_5 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1017));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1018 = getQ_7_Iheb436_emi78vuj01((*g_0).d_00.kids_0, 2);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* typ_1 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1018));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_16;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&X60Qx_16));
  if (3 < (*g_0).d_00.kids_0.len_0){
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qx_16);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1019 = getQ_7_Iheb436_emi78vuj01((*g_0).d_00.kids_0, 3);
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1020 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1019));
    X60Qx_16 = X60Qx_1020;}
  else {
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qx_16);
    X60Qx_16 = NIM_NIL;}
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* value_1 = X60Qx_16;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&X60Qx_16));
  string_0_sysvq0asl nm_8 = declName_0_emi78vuj01((*nameAtom_1).d_00.atom_0, pragmas_5);
  NB8 isConst_1 = eqQ_20_sysvq0asl((*g_0).d_00.tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I12999086881046019782_emi78vuj01)}
  );
  string_0_sysvq0asl decl_1 = declare_1_emi78vuj01(typ_1, nm_8);
  if (isConst_1){
    string_0_sysvq0asl X60Qlhs_95 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I10550632768111220399_emi78vuj01)}
    , decl_1);
    nimStrDestroy(decl_1);
    decl_1 = X60Qlhs_95;}
  NB8 X60Qx_1021;
  NB8 X60Qx_1022;
  if ((!(value_1 == NIM_NIL))){
    NB8 X60Qx_1023 = isDot_0_emi78vuj01(value_1);
    X60Qx_1022 = (!X60Qx_1023);}
  else {
    X60Qx_1022 = NIM_FALSE;}
  if (X60Qx_1022){
    NB8 X60Qx_1024 = isLiteralNode_0_emi78vuj01(value_1);
    X60Qx_1021 = X60Qx_1024;}
  else {
    X60Qx_1021 = NIM_FALSE;}
  NB8 hasInit_1 = X60Qx_1021;
  eQdestroyQ_SX47lobalX49nfo0emi78vuj01_0_emi78vuj01((&result_56));
  result_56 = (GlobalInfo_0_emi78vuj01){
    .name_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .decl_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .nameAtom_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .needsInit_0 = NIM_FALSE, .value_0 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)NIM_NIL)}
  ;
  string_0_sysvq0asl* X60Qlhs_96 = (&result_56.name_0);
  nimStrDestroy((*X60Qlhs_96));
  (*X60Qlhs_96) = nm_8;
  nimStrWasMoved((&nm_8));
  string_0_sysvq0asl X60Qx_17;
  nimStrWasMoved((&X60Qx_17));
  if (hasInit_1){
    nimStrDestroy(X60Qx_17);
    string_0_sysvq0asl X60Qtmp_97 = genInit_1_emi78vuj01(value_1);
    string_0_sysvq0asl X60Qx_1025 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 540876803u, .more_0 = NIM_NIL}
    , X60Qtmp_97);
    X60Qx_17 = X60Qx_1025;
    nimStrDestroy(X60Qtmp_97);}
  else {
    nimStrDestroy(X60Qx_17);
    X60Qx_17 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl X60Qdesugar_115 = X60Qx_17;
  nimStrWasMoved((&X60Qx_17));
  NI32 X60Qx_1026 = len_4_sysvq0asl(decl_1);
  NI32 X60Qx_1027 = len_4_sysvq0asl(X60Qdesugar_115);
  NI32 X60Qx_1028 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 15105u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_116 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1026 + X60Qx_1027)) + X60Qx_1028)));
  add_2_sysvq0asl((&X60Qdesugar_116), decl_1);
  add_2_sysvq0asl((&X60Qdesugar_116), X60Qdesugar_115);
  add_2_sysvq0asl((&X60Qdesugar_116), (string_0_sysvq0asl){
    .bytes_0 = 15105u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl* X60Qlhs_98 = (&result_56.decl_0);
  nimStrDestroy((*X60Qlhs_98));
  (*X60Qlhs_98) = X60Qdesugar_116;
  nimStrWasMoved((&X60Qdesugar_116));
  string_0_sysvq0asl* X60Qlhs_99 = (&result_56.nameAtom_0);
  nimStrDestroy((*X60Qlhs_99));
  string_0_sysvq0asl X60Qx_1029 = nimStrDup((*nameAtom_1).d_00.atom_0);
  (*X60Qlhs_99) = X60Qx_1029;
  NB8 X60Qx_1030;
  NB8 X60Qx_1031;
  if ((!(value_1 == NIM_NIL))){
    NB8 X60Qx_1032 = isDot_0_emi78vuj01(value_1);
    X60Qx_1031 = (!X60Qx_1032);}
  else {
    X60Qx_1031 = NIM_FALSE;}
  if (X60Qx_1031){
    X60Qx_1030 = (!hasInit_1);}
  else {
    X60Qx_1030 = NIM_FALSE;}
  result_56.needsInit_0 = X60Qx_1030;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qlhs_100 = (&result_56.value_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qlhs_100));
  (*X60Qlhs_100) = value_1;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&value_1));
  nimStrDestroy(X60Qdesugar_116);
  nimStrDestroy(X60Qdesugar_115);
  nimStrDestroy(X60Qx_17);
  nimStrDestroy(decl_1);
  nimStrDestroy(nm_8);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(value_1);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qx_16);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(typ_1);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_5);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_1);
  return result_56;
  nimStrDestroy(X60Qdesugar_116);
  nimStrDestroy(X60Qdesugar_115);
  nimStrDestroy(X60Qx_17);
  nimStrDestroy(decl_1);
  nimStrDestroy(nm_8);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(value_1);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qx_16);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(typ_1);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_5);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_1);
  return result_56;}
string_0_sysvq0asl genObjectFields_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* body_1){
  string_0_sysvq0asl result_57;
  nimStrWasMoved((&result_57));
  string_0_sysvq0asl fields_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 start_1 = 0;
  NB8 X60Qx_1033;
  if (0 < (*body_1).d_00.kids_0.len_0){
    NB8 X60Qx_1034;
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1035 = getQ_7_Iheb436_emi78vuj01((*body_1).d_00.kids_0, 0);
    NB8 X60Qx_1036 = isDot_0_emi78vuj01((*X60Qx_1035));
    if (X60Qx_1036){
      X60Qx_1034 = NIM_TRUE;}
    else {
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1037 = getQ_7_Iheb436_emi78vuj01((*body_1).d_00.kids_0, 0);
      NB8 X60Qx_1038 = isAtom_0_emi78vuj01((*X60Qx_1037));
      X60Qx_1034 = X60Qx_1038;}
    X60Qx_1033 = X60Qx_1034;}
  else {
    X60Qx_1033 = NIM_FALSE;}
  if (X60Qx_1033){
    NB8 X60Qx_1039;
    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1040 = getQ_7_Iheb436_emi78vuj01((*body_1).d_00.kids_0, 0);
    NB8 X60Qx_1041 = isAtom_0_emi78vuj01((*X60Qx_1040));
    if (X60Qx_1041){
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1042 = getQ_7_Iheb436_emi78vuj01((*body_1).d_00.kids_0, 0);
      NB8 X60Qx_1043 = isDot_0_emi78vuj01((*X60Qx_1042));
      X60Qx_1039 = (!X60Qx_1043);}
    else {
      X60Qx_1039 = NIM_FALSE;}
    if (X60Qx_1039){
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1044 = getQ_7_Iheb436_emi78vuj01((*body_1).d_00.kids_0, 0);
      string_0_sysvq0asl X60Qtmp_102 = typeName_0_emi78vuj01((*(*X60Qx_1044)).d_00.atom_0);
      string_0_sysvq0asl X60Qtmp_101 = ampQ_0_sysvq0asl(X60Qtmp_102, (string_0_sysvq0asl){
        .bytes_0 = 995172606u, .more_0 = (&strlit_0_I13598347493614872284_emi78vuj01)}
      );
      add_2_sysvq0asl((&fields_0), X60Qtmp_101);
      nimStrDestroy(X60Qtmp_101);
      nimStrDestroy(X60Qtmp_102);}
    start_1 = 1;}
  NI32 i_18 = start_1;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1045 = len_3_Il6imzw1_emi78vuj01((*body_1).d_00.kids_0);
      if (i_18 < X60Qx_1045){
        {
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1046 = getQ_7_Iheb436_emi78vuj01((*body_1).d_00.kids_0, i_18);
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* f_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1046));
          inc_1_I6wjjge_aow2h993l1((&i_18));
          NB8 X60Qx_1047 = isList_0_emi78vuj01(f_0);
          if ((!X60Qx_1047)){
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(f_0);
            goto continueLabel_1;}
          NB8 X60Qx_1048 = eqQ_20_sysvq0asl((*f_0).d_00.tag_0, (string_0_sysvq0asl){
            .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
          );
          if (X60Qx_1048){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1049 = getQ_7_Iheb436_emi78vuj01((*f_0).d_00.kids_0, 0);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* fn_1 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1049));
            NI32 X60Qx_1050 = len_3_Il6imzw1_emi78vuj01((*f_0).d_00.kids_0);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1051 = getQ_7_Iheb436_emi78vuj01((*f_0).d_00.kids_0, ((NI32)(X60Qx_1050 - 1)));
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* ftype_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1051));
            string_0_sysvq0asl X60Qtmp_105 = mangleToC_0_emi78vuj01((*fn_1).d_00.atom_0);
            string_0_sysvq0asl X60Qtmp_104 = declare_1_emi78vuj01(ftype_0, X60Qtmp_105);
            string_0_sysvq0asl X60Qtmp_103 = ampQ_0_sysvq0asl(X60Qtmp_104, (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&fields_0), X60Qtmp_103);
            nimStrDestroy(X60Qtmp_103);
            nimStrDestroy(X60Qtmp_104);
            nimStrDestroy(X60Qtmp_105);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ftype_0);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(fn_1);}
          else {
            NB8 X60Qx_1052 = eqQ_20_sysvq0asl((*f_0).d_00.tag_0, (string_0_sysvq0asl){
              .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I3302612697625453930_emi78vuj01)}
            );
            if (X60Qx_1052){
              add_2_sysvq0asl((&fields_0), (string_0_sysvq0asl){
                .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I11734148202880076785_emi78vuj01)}
              );
              {
                openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_46 = toOpenArray_1_I1gbnw21_emi78vuj01((*f_0).d_00.kids_0);
                NI32 X60Qlf_47 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_1053 = len_6_I3x6mi_emi78vuj01(X60Qlf_46);
                    if (X60Qlf_47 < X60Qx_1053){
                      {
                        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_4 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_46, X60Qlf_47);
                        NB8 X60Qx_1054;
                        NB8 X60Qx_1055 = isList_0_emi78vuj01((*X60Qii_4));
                        if (X60Qx_1055){
                          NB8 X60Qx_1056 = eqQ_20_sysvq0asl((*(*X60Qii_4)).d_00.tag_0, (string_0_sysvq0asl){
                            .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
                          );
                          X60Qx_1054 = X60Qx_1056;}
                        else {
                          X60Qx_1054 = NIM_FALSE;}
                        if (X60Qx_1054){
                          string_0_sysvq0asl X60Qdesugar_117 = genObjectFields_0_emi78vuj01((*X60Qii_4));
                          NI32 X60Qx_1057 = len_4_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I2377898382635629774_emi78vuj01)}
                          );
                          NI32 X60Qx_1058 = len_4_sysvq0asl(X60Qdesugar_117);
                          NI32 X60Qx_1059 = len_4_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 171670787u, .more_0 = NIM_NIL}
                          );
                          string_0_sysvq0asl X60Qdesugar_118 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1057 + X60Qx_1058)) + X60Qx_1059)));
                          add_2_sysvq0asl((&X60Qdesugar_118), (string_0_sysvq0asl){
                            .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I2377898382635629774_emi78vuj01)}
                          );
                          add_2_sysvq0asl((&X60Qdesugar_118), X60Qdesugar_117);
                          add_2_sysvq0asl((&X60Qdesugar_118), (string_0_sysvq0asl){
                            .bytes_0 = 171670787u, .more_0 = NIM_NIL}
                          );
                          add_2_sysvq0asl((&fields_0), X60Qdesugar_118);
                          nimStrDestroy(X60Qdesugar_118);
                          nimStrDestroy(X60Qdesugar_117);}}
                      inc_1_I6wjjge_aow2h993l1((&X60Qlf_47));}
                    else {
                      break;}}}
                whileStmtLabel_3: ;}
              forStmtLabel_2: ;
              add_2_sysvq0asl((&fields_0), (string_0_sysvq0asl){
                .bytes_0 = 171670787u, .more_0 = NIM_NIL}
              );}}
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(f_0);}
        continueLabel_1: ;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl X60Qtmp_106 = fields_0;
  nimStrWasMoved((&fields_0));
  nimStrDestroy(fields_0);
  return X60Qtmp_106;
  nimStrDestroy(fields_0);
  return result_57;
  nimStrDestroy(fields_0);
  return result_57;}
string_0_sysvq0asl genObjectDecl_0_emi78vuj01(string_0_sysvq0asl nm_0, X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* body_2, NB8 isUnion_0, NB8 isPacked_0){
  string_0_sysvq0asl result_58;
  nimStrWasMoved((&result_58));
  string_0_sysvq0asl X60Qx_18;
  nimStrWasMoved((&X60Qx_18));
  if (isUnion_0){
    nimStrDestroy(X60Qx_18);
    X60Qx_18 = (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I10639822427173870573_emi78vuj01)}
    ;}
  else {
    nimStrDestroy(X60Qx_18);
    X60Qx_18 = (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
    ;}
  string_0_sysvq0asl kw_0 = X60Qx_18;
  nimStrWasMoved((&X60Qx_18));
  string_0_sysvq0asl X60Qx_19;
  nimStrWasMoved((&X60Qx_19));
  if (isPacked_0){
    nimStrDestroy(X60Qx_19);
    X60Qx_19 = (string_0_sysvq0asl){
      .bytes_0 = 1600069886u, .more_0 = (&strlit_0_I6078044050830967917_emi78vuj01)}
    ;}
  else {
    nimStrDestroy(X60Qx_19);
    X60Qx_19 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl attr_0 = X60Qx_19;
  nimStrWasMoved((&X60Qx_19));
  string_0_sysvq0asl X60Qdesugar_119 = genObjectFields_0_emi78vuj01(body_2);
  NI32 X60Qx_1060 = len_4_sysvq0asl(kw_0);
  NI32 X60Qx_1061 = len_4_sysvq0asl(nm_0);
  NI32 X60Qx_1062 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 175841283u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1063 = len_4_sysvq0asl(X60Qdesugar_119);
  NI32 X60Qx_1064 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 32001u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1065 = len_4_sysvq0asl(attr_0);
  NI32 X60Qx_1066 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1067 = len_4_sysvq0asl(nm_0);
  NI32 X60Qx_1068 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 15105u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_120 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1060 + X60Qx_1061)) + X60Qx_1062)) + X60Qx_1063)) + X60Qx_1064)) + X60Qx_1065)) + X60Qx_1066)) + X60Qx_1067)) + X60Qx_1068)));
  add_2_sysvq0asl((&X60Qdesugar_120), kw_0);
  add_2_sysvq0asl((&X60Qdesugar_120), nm_0);
  add_2_sysvq0asl((&X60Qdesugar_120), (string_0_sysvq0asl){
    .bytes_0 = 175841283u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_120), X60Qdesugar_119);
  add_2_sysvq0asl((&X60Qdesugar_120), (string_0_sysvq0asl){
    .bytes_0 = 32001u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_120), attr_0);
  add_2_sysvq0asl((&X60Qdesugar_120), (string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_120), nm_0);
  add_2_sysvq0asl((&X60Qdesugar_120), (string_0_sysvq0asl){
    .bytes_0 = 15105u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qtmp_107 = X60Qdesugar_120;
  nimStrWasMoved((&X60Qdesugar_120));
  nimStrDestroy(X60Qdesugar_120);
  nimStrDestroy(X60Qdesugar_119);
  nimStrDestroy(attr_0);
  nimStrDestroy(X60Qx_19);
  nimStrDestroy(kw_0);
  nimStrDestroy(X60Qx_18);
  return X60Qtmp_107;
  nimStrDestroy(X60Qdesugar_120);
  nimStrDestroy(X60Qdesugar_119);
  nimStrDestroy(attr_0);
  nimStrDestroy(X60Qx_19);
  nimStrDestroy(kw_0);
  nimStrDestroy(X60Qx_18);
  return result_58;
  nimStrDestroy(X60Qdesugar_120);
  nimStrDestroy(X60Qdesugar_119);
  nimStrDestroy(attr_0);
  nimStrDestroy(X60Qx_19);
  nimStrDestroy(kw_0);
  nimStrDestroy(X60Qx_18);
  return result_58;}
string_0_sysvq0asl genEnumDecl_0_emi78vuj01(string_0_sysvq0asl nm_1, X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* body_3){
  string_0_sysvq0asl result_59;
  nimStrWasMoved((&result_59));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1069 = getQ_7_Iheb436_emi78vuj01((*body_3).d_00.kids_0, 0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* base_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1069));
  string_0_sysvq0asl X60Qdesugar_121 = genType_1_emi78vuj01(base_0);
  NI32 X60Qx_1070 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
  );
  NI32 X60Qx_1071 = len_4_sysvq0asl(X60Qdesugar_121);
  NI32 X60Qx_1072 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1073 = len_4_sysvq0asl(nm_1);
  NI32 X60Qx_1074 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 670466u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_122 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1070 + X60Qx_1071)) + X60Qx_1072)) + X60Qx_1073)) + X60Qx_1074)));
  add_2_sysvq0asl((&X60Qdesugar_122), (string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
  );
  add_2_sysvq0asl((&X60Qdesugar_122), X60Qdesugar_121);
  add_2_sysvq0asl((&X60Qdesugar_122), (string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_122), nm_1);
  add_2_sysvq0asl((&X60Qdesugar_122), (string_0_sysvq0asl){
    .bytes_0 = 670466u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl outp_6 = X60Qdesugar_122;
  nimStrWasMoved((&X60Qdesugar_122));
  NI32 i_19 = 1;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1075 = len_3_Il6imzw1_emi78vuj01((*body_3).d_00.kids_0);
      if (i_19 < X60Qx_1075){
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1076 = getQ_7_Iheb436_emi78vuj01((*body_3).d_00.kids_0, i_19);
        X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* ef_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1076));
        inc_1_I6wjjge_aow2h993l1((&i_19));
        NB8 X60Qx_1077;
        NB8 X60Qx_1078 = isList_0_emi78vuj01(ef_0);
        if (X60Qx_1078){
          NB8 X60Qx_1079 = eqQ_20_sysvq0asl((*ef_0).d_00.tag_0, (string_0_sysvq0asl){
            .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_emi78vuj01)}
          );
          X60Qx_1077 = X60Qx_1079;}
        else {
          X60Qx_1077 = NIM_FALSE;}
        if (X60Qx_1077){
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1080 = getQ_7_Iheb436_emi78vuj01((*ef_0).d_00.kids_0, 0);
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* en_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1080));
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1081 = getQ_7_Iheb436_emi78vuj01((*ef_0).d_00.kids_0, 1);
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* ev_0 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1081));
          string_0_sysvq0asl X60Qdesugar_123 = mangleToC_0_emi78vuj01((*en_0).d_00.atom_0);
          string_0_sysvq0asl X60Qdesugar_124 = genType_1_emi78vuj01(base_0);
          string_0_sysvq0asl X60Qdesugar_125 = genExpr_1_emi78vuj01(ev_0);
          NI32 X60Qx_1082 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1701061630u, .more_0 = (&strlit_0_I11742995307374834148_emi78vuj01)}
          );
          NI32 X60Qx_1083 = len_4_sysvq0asl(X60Qdesugar_123);
          NI32 X60Qx_1084 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 673718275u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_1085 = len_4_sysvq0asl(X60Qdesugar_124);
          NI32 X60Qx_1086 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 10497u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_1087 = len_4_sysvq0asl(X60Qdesugar_125);
          NI32 X60Qx_1088 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 665858u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_126 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1082 + X60Qx_1083)) + X60Qx_1084)) + X60Qx_1085)) + X60Qx_1086)) + X60Qx_1087)) + X60Qx_1088)));
          add_2_sysvq0asl((&X60Qdesugar_126), (string_0_sysvq0asl){
            .bytes_0 = 1701061630u, .more_0 = (&strlit_0_I11742995307374834148_emi78vuj01)}
          );
          add_2_sysvq0asl((&X60Qdesugar_126), X60Qdesugar_123);
          add_2_sysvq0asl((&X60Qdesugar_126), (string_0_sysvq0asl){
            .bytes_0 = 673718275u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_126), X60Qdesugar_124);
          add_2_sysvq0asl((&X60Qdesugar_126), (string_0_sysvq0asl){
            .bytes_0 = 10497u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_126), X60Qdesugar_125);
          add_2_sysvq0asl((&X60Qdesugar_126), (string_0_sysvq0asl){
            .bytes_0 = 665858u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&outp_6), X60Qdesugar_126);
          nimStrDestroy(X60Qdesugar_126);
          nimStrDestroy(X60Qdesugar_125);
          nimStrDestroy(X60Qdesugar_124);
          nimStrDestroy(X60Qdesugar_123);
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ev_0);
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(en_0);}
        eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(ef_0);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl X60Qtmp_108 = outp_6;
  nimStrWasMoved((&outp_6));
  nimStrDestroy(outp_6);
  nimStrDestroy(X60Qdesugar_122);
  nimStrDestroy(X60Qdesugar_121);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(base_0);
  return X60Qtmp_108;
  nimStrDestroy(outp_6);
  nimStrDestroy(X60Qdesugar_122);
  nimStrDestroy(X60Qdesugar_121);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(base_0);
  return result_59;
  nimStrDestroy(outp_6);
  nimStrDestroy(X60Qdesugar_122);
  nimStrDestroy(X60Qdesugar_121);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(base_0);
  return result_59;}
string_0_sysvq0asl genTypeDecl_1_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* td_1){
  string_0_sysvq0asl result_60;
  nimStrWasMoved((&result_60));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1089 = getQ_7_Iheb436_emi78vuj01((*td_1).d_00.kids_0, 0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* nameAtom_2 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1089));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pragmas_6 = findTag_0_emi78vuj01(td_1, (string_0_sysvq0asl){
    .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
  );
  NI32 X60Qx_1090 = len_3_Il6imzw1_emi78vuj01((*td_1).d_00.kids_0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1091 = getQ_7_Iheb436_emi78vuj01((*td_1).d_00.kids_0, ((NI32)(X60Qx_1090 - 1)));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* body_6 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1091));
  X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01){
    .a = {
      (string_0_sysvq0asl){
        .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}}}
  ;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1092 = toOpenArray_0_Ig1w4is1_emi78vuj01((&X60QconstRefTemp_0));
  NB8 X60Qx_1093 = hasPragma_0_emi78vuj01(pragmas_6, X60Qx_1092);
  if (X60Qx_1093){
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl nm_9 = mangleToC_0_emi78vuj01((*nameAtom_2).d_00.atom_0);
  NB8 X60Qx_1094 = isList_0_emi78vuj01(body_6);
  if (X60Qx_1094){
    NB8 X60Qx_1095;
    NB8 X60Qx_1096 = eqQ_20_sysvq0asl((*body_6).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
    );
    if (X60Qx_1096){
      X60Qx_1095 = NIM_TRUE;}
    else {
      NB8 X60Qx_1097 = eqQ_20_sysvq0asl((*body_6).d_00.tag_0, (string_0_sysvq0asl){
        .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I3302612697625453930_emi78vuj01)}
      );
      X60Qx_1095 = X60Qx_1097;}
    if (X60Qx_1095){
      NB8 X60Qx_1098 = eqQ_20_sysvq0asl((*body_6).d_00.tag_0, (string_0_sysvq0asl){
        .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I3302612697625453930_emi78vuj01)}
      );
      X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01 X60QconstRefTemp_1 = (X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01){
        .a = {
          (string_0_sysvq0asl){
            .bytes_0 = 1667330302u, .more_0 = (&strlit_0_I17844812131497141662_emi78vuj01)}}}
      ;
      openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1099 = toOpenArray_0_If2frt3_emi78vuj01((&X60QconstRefTemp_1));
      NB8 X60Qx_1100 = hasPragma_0_emi78vuj01(pragmas_6, X60Qx_1099);
      string_0_sysvq0asl X60Qx_1101 = genObjectDecl_0_emi78vuj01(nm_9, body_6, X60Qx_1098, X60Qx_1100);
      result_60 = X60Qx_1101;
      nimStrDestroy(nm_9);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
      return result_60;}
    NB8 X60Qx_1102 = eqQ_20_sysvq0asl((*body_6).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
    );
    if (X60Qx_1102){
      string_0_sysvq0asl X60Qx_1103 = genEnumDecl_0_emi78vuj01(nm_9, body_6);
      result_60 = X60Qx_1103;
      nimStrDestroy(nm_9);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
      return result_60;}
    NB8 X60Qx_1104 = eqQ_20_sysvq0asl((*body_6).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
    );
    if (X60Qx_1104){
      NI32 X60Qx_1105 = len_3_Il6imzw1_emi78vuj01((*body_6).d_00.kids_0);
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1106 = getQ_7_Iheb436_emi78vuj01((*body_6).d_00.kids_0, ((NI32)(X60Qx_1105 - 1)));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* size_3 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1106));
      string_0_sysvq0asl X60Qx_20;
      nimStrWasMoved((&X60Qx_20));
      NB8 X60Qx_1107 = isAtom_0_emi78vuj01(size_3);
      if (X60Qx_1107){
        nimStrDestroy(X60Qx_20);
        string_0_sysvq0asl X60Qx_1108 = nimStrDup((*size_3).d_00.atom_0);
        X60Qx_20 = X60Qx_1108;}
      else {
        nimStrDestroy(X60Qx_20);
        X60Qx_20 = (string_0_sysvq0asl){
          .bytes_0 = 12289u, .more_0 = NIM_NIL}
        ;}
      string_0_sysvq0asl len2_1 = X60Qx_20;
      nimStrWasMoved((&X60Qx_20));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1109 = getQ_7_Iheb436_emi78vuj01((*body_6).d_00.kids_0, 0);
      string_0_sysvq0asl X60Qdesugar_127 = genType_1_emi78vuj01((*X60Qx_1109));
      NI32 X60Qx_1110 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
      );
      NI32 X60Qx_1111 = len_4_sysvq0asl(nm_9);
      NI32 X60Qx_1112 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 544940035u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_1113 = len_4_sysvq0asl(X60Qdesugar_127);
      NI32 X60Qx_1114 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1533091843u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_1115 = len_4_sysvq0asl(len2_1);
      NI32 X60Qx_1116 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540761598u, .more_0 = (&strlit_0_I5009490129652841634_emi78vuj01)}
      );
      NI32 X60Qx_1117 = len_4_sysvq0asl(nm_9);
      NI32 X60Qx_1118 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 15105u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_128 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1110 + X60Qx_1111)) + X60Qx_1112)) + X60Qx_1113)) + X60Qx_1114)) + X60Qx_1115)) + X60Qx_1116)) + X60Qx_1117)) + X60Qx_1118)));
      add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_128), nm_9);
      add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
        .bytes_0 = 544940035u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_128), X60Qdesugar_127);
      add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
        .bytes_0 = 1533091843u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_128), len2_1);
      add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
        .bytes_0 = 540761598u, .more_0 = (&strlit_0_I5009490129652841634_emi78vuj01)}
      );
      add_2_sysvq0asl((&X60Qdesugar_128), nm_9);
      add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
        .bytes_0 = 15105u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qtmp_109 = X60Qdesugar_128;
      nimStrWasMoved((&X60Qdesugar_128));
      nimStrDestroy(X60Qdesugar_128);
      nimStrDestroy(X60Qdesugar_127);
      nimStrDestroy(len2_1);
      nimStrDestroy(X60Qx_20);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(size_3);
      nimStrDestroy(nm_9);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
      return X60Qtmp_109;
      nimStrDestroy(X60Qdesugar_128);
      nimStrDestroy(X60Qdesugar_127);
      nimStrDestroy(len2_1);
      nimStrDestroy(X60Qx_20);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(size_3);}
    NB8 X60Qx_1119 = eqQ_20_sysvq0asl((*body_6).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I1995551610468546737_emi78vuj01)}
    );
    if (X60Qx_1119){
      string_0_sysvq0asl X60Qdesugar_129 = declare_1_emi78vuj01(body_6, nm_9);
      NI32 X60Qx_1120 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
      );
      NI32 X60Qx_1121 = len_4_sysvq0asl(X60Qdesugar_129);
      NI32 X60Qx_1122 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 15105u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_130 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1120 + X60Qx_1121)) + X60Qx_1122)));
      add_2_sysvq0asl((&X60Qdesugar_130), (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
      );
      add_2_sysvq0asl((&X60Qdesugar_130), X60Qdesugar_129);
      add_2_sysvq0asl((&X60Qdesugar_130), (string_0_sysvq0asl){
        .bytes_0 = 15105u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qtmp_110 = X60Qdesugar_130;
      nimStrWasMoved((&X60Qdesugar_130));
      nimStrDestroy(X60Qdesugar_130);
      nimStrDestroy(X60Qdesugar_129);
      nimStrDestroy(nm_9);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
      return X60Qtmp_110;
      nimStrDestroy(X60Qdesugar_130);
      nimStrDestroy(X60Qdesugar_129);}
    X60Qt_0_IAarraySstring0sysvq0aslS7_emi78vuj01 X60QconstRefTemp_2 = (X60Qt_0_IAarraySstring0sysvq0aslS7_emi78vuj01){
      .a = {
        (string_0_sysvq0asl){
          .bytes_0 = 26881u, .more_0 = NIM_NIL}
        , (string_0_sysvq0asl){
          .bytes_0 = 29953u, .more_0 = NIM_NIL}
        , (string_0_sysvq0asl){
          .bytes_0 = 26113u, .more_0 = NIM_NIL}
        , (string_0_sysvq0asl){
          .bytes_0 = 25345u, .more_0 = NIM_NIL}
        , (string_0_sysvq0asl){
          .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
        , (string_0_sysvq0asl){
          .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
        , (string_0_sysvq0asl){
          .bytes_0 = 1953522174u, .more_0 = (&strlit_0_I6488225283415667707_emi78vuj01)}}}
    ;
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1123 = toOpenArray_0_Ih6urrr1_emi78vuj01((&X60QconstRefTemp_2));
    NB8 X60Qx_1124 = oneOf_0_emi78vuj01((*body_6).d_00.tag_0, X60Qx_1123);
    if (X60Qx_1124){
      string_0_sysvq0asl X60Qdesugar_131 = declare_1_emi78vuj01(body_6, nm_9);
      NI32 X60Qx_1125 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
      );
      NI32 X60Qx_1126 = len_4_sysvq0asl(X60Qdesugar_131);
      NI32 X60Qx_1127 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 15105u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_132 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1125 + X60Qx_1126)) + X60Qx_1127)));
      add_2_sysvq0asl((&X60Qdesugar_132), (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
      );
      add_2_sysvq0asl((&X60Qdesugar_132), X60Qdesugar_131);
      add_2_sysvq0asl((&X60Qdesugar_132), (string_0_sysvq0asl){
        .bytes_0 = 15105u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qtmp_111 = X60Qdesugar_132;
      nimStrWasMoved((&X60Qdesugar_132));
      nimStrDestroy(X60Qdesugar_132);
      nimStrDestroy(X60Qdesugar_131);
      nimStrDestroy(nm_9);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
      return X60Qtmp_111;
      nimStrDestroy(X60Qdesugar_132);
      nimStrDestroy(X60Qdesugar_131);}}
  NB8 X60Qx_1128 = isAtom_0_emi78vuj01(body_6);
  if (X60Qx_1128){
    string_0_sysvq0asl X60Qdesugar_133 = typeName_0_emi78vuj01((*body_6).d_00.atom_0);
    NI32 X60Qx_1129 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
    );
    NI32 X60Qx_1130 = len_4_sysvq0asl(X60Qdesugar_133);
    NI32 X60Qx_1131 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1132 = len_4_sysvq0asl(nm_9);
    NI32 X60Qx_1133 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 15105u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_134 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1129 + X60Qx_1130)) + X60Qx_1131)) + X60Qx_1132)) + X60Qx_1133)));
    add_2_sysvq0asl((&X60Qdesugar_134), (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_134), X60Qdesugar_133);
    add_2_sysvq0asl((&X60Qdesugar_134), (string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_134), nm_9);
    add_2_sysvq0asl((&X60Qdesugar_134), (string_0_sysvq0asl){
      .bytes_0 = 15105u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_112 = X60Qdesugar_134;
    nimStrWasMoved((&X60Qdesugar_134));
    nimStrDestroy(X60Qdesugar_134);
    nimStrDestroy(X60Qdesugar_133);
    nimStrDestroy(nm_9);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
    return X60Qtmp_112;
    nimStrDestroy(X60Qdesugar_134);
    nimStrDestroy(X60Qdesugar_133);}
  nimStrDestroy(nm_9);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  nimStrDestroy(nm_9);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
  return result_60;
  nimStrDestroy(nm_9);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(body_6);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_6);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(nameAtom_2);
  return result_60;}
string_0_sysvq0asl provisionImpl_0_emi78vuj01(string_0_sysvq0asl name_5){
  string_0_sysvq0asl result_61;
  nimStrWasMoved((&result_61));
  NB8 X60Qx_1134 = eqQ_20_sysvq0asl(name_5, (string_0_sysvq0asl){
    .bytes_0 = 1600744958u, .more_0 = (&strlit_0_I18345099547365871085_emi78vuj01)}
  );
  if (X60Qx_1134){
    return (string_0_sysvq0asl){
      .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I1390764316392016455_emi78vuj01)}
    ;}
  else {
    NB8 X60Qx_1135 = eqQ_20_sysvq0asl(name_5, (string_0_sysvq0asl){
      .bytes_0 = 1600744958u, .more_0 = (&strlit_0_I12842777188212808440_emi78vuj01)}
    );
    if (X60Qx_1135){
      return (string_0_sysvq0asl){
        .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I11654035052660406372_emi78vuj01)}
      ;}
    else {
      NB8 X60Qx_1136 = eqQ_20_sysvq0asl(name_5, (string_0_sysvq0asl){
        .bytes_0 = 1600744958u, .more_0 = (&strlit_0_I14462755268250863233_emi78vuj01)}
      );
      if (X60Qx_1136){
        return (string_0_sysvq0asl){
          .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I4673220306063062360_emi78vuj01)}
        ;}
      else {
        NB8 X60Qx_1137 = eqQ_20_sysvq0asl(name_5, (string_0_sysvq0asl){
          .bytes_0 = 1600744958u, .more_0 = (&strlit_0_I7117386163922528102_emi78vuj01)}
        );
        if (X60Qx_1137){
          return (string_0_sysvq0asl){
            .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I17194190520361290850_emi78vuj01)}
          ;}}}}
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_61;}
string_0_sysvq0asl provisionNeeds_0_emi78vuj01(string_0_sysvq0asl name_6){
  string_0_sysvq0asl result_62;
  nimStrWasMoved((&result_62));
  NB8 X60Qx_1138 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
    .bytes_0 = 1600744958u, .more_0 = (&strlit_0_I7117386163922528102_emi78vuj01)}
  );
  if (X60Qx_1138){
    return (string_0_sysvq0asl){
      .bytes_0 = 1634548990u, .more_0 = (&strlit_0_I1974591037852052736_emi78vuj01)}
    ;}
  else {
    NB8 X60Qx_1139;
    NB8 X60Qx_1140;
    NB8 X60Qx_1141 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
      .bytes_0 = 1600744958u, .more_0 = (&strlit_0_I18345099547365871085_emi78vuj01)}
    );
    if (X60Qx_1141){
      X60Qx_1140 = NIM_TRUE;}
    else {
      NB8 X60Qx_1142 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
        .bytes_0 = 1600744958u, .more_0 = (&strlit_0_I12842777188212808440_emi78vuj01)}
      );
      X60Qx_1140 = X60Qx_1142;}
    if (X60Qx_1140){
      X60Qx_1139 = NIM_TRUE;}
    else {
      NB8 X60Qx_1143 = eqQ_20_sysvq0asl(name_6, (string_0_sysvq0asl){
        .bytes_0 = 1600744958u, .more_0 = (&strlit_0_I14462755268250863233_emi78vuj01)}
      );
      X60Qx_1139 = X60Qx_1143;}
    if (X60Qx_1139){
      return (string_0_sysvq0asl){
        .bytes_0 = 1953709310u, .more_0 = (&strlit_0_I6581242055976388853_emi78vuj01)}
      ;}}
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_62;}
NB8 isProvision_0_emi78vuj01(string_0_sysvq0asl name_7){
  NB8 result_63;
  string_0_sysvq0asl X60Qtmp_113 = provisionImpl_0_emi78vuj01(name_7);
  NI32 X60Qx_1144 = len_4_sysvq0asl(X60Qtmp_113);
  result_63 = (0 < X60Qx_1144);
  nimStrDestroy(X60Qtmp_113);
  return result_63;
  nimStrDestroy(X60Qtmp_113);
  return result_63;}
void addHeaders_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pragmas_3, seq_0_Ixdx2fh1_aow7lb5cq1* headers_0){
  NB8 X60Qx_1145 = isList_0_emi78vuj01(pragmas_3);
  if ((!X60Qx_1145)){
    return;}
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_48 = toOpenArray_1_I1gbnw21_emi78vuj01((*pragmas_3).d_00.kids_0);
    NI32 X60Qlf_49 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1146 = len_6_I3x6mi_emi78vuj01(X60Qlf_48);
        if (X60Qlf_49 < X60Qx_1146){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_48, X60Qlf_49);
            NB8 X60Qx_1147;
            NB8 X60Qx_1148;
            NB8 X60Qx_1149;
            NB8 X60Qx_1150;
            NB8 X60Qx_1151 = isList_0_emi78vuj01((*X60Qii_2));
            if (X60Qx_1151){
              NB8 X60Qx_1152 = eqQ_20_sysvq0asl((*(*X60Qii_2)).d_00.tag_0, (string_0_sysvq0asl){
                .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}
              );
              X60Qx_1150 = X60Qx_1152;}
            else {
              X60Qx_1150 = NIM_FALSE;}
            if (X60Qx_1150){
              X60Qx_1149 = (0 < (*(*X60Qii_2)).d_00.kids_0.len_0);}
            else {
              X60Qx_1149 = NIM_FALSE;}
            if (X60Qx_1149){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1153 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_2)).d_00.kids_0, 0);
              X60Qx_1148 = (!((*X60Qx_1153) == NIM_NIL));}
            else {
              X60Qx_1148 = NIM_FALSE;}
            if (X60Qx_1148){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1154 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_2)).d_00.kids_0, 0);
              X60Qx_1147 = ((*(*X60Qx_1154)).d_00.kind_0 == 1);}
            else {
              X60Qx_1147 = NIM_FALSE;}
            if (X60Qx_1147){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1155 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_2)).d_00.kids_0, 0);
              NB8 X60Qx_1156 = mapHas_0_emi78vuj01((*headers_0), (*(*X60Qx_1155)).d_00.strVal_0);
              if ((!X60Qx_1156)){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1157 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_2)).d_00.kids_0, 0);
                string_0_sysvq0asl X60Qx_1158 = nimStrDup((*(*X60Qx_1157)).d_00.strVal_0);
                add_0_Ig6072n_aow7lb5cq1(headers_0, X60Qx_1158);}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_49));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
NB8 isStmtTag_0_emi78vuj01(string_0_sysvq0asl t_8){
  NB8 result_64;
  X60Qt_0_IAarraySstring0sysvq0aslS17_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS17_emi78vuj01){
    .a = {
      (string_0_sysvq0asl){
        .bytes_0 = 1735614974u, .more_0 = (&strlit_0_I2681092370707159476_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1869902846u, .more_0 = (&strlit_0_I5487391404206283781_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_der823rwr1)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_der823rwr1)}
      , (string_0_sysvq0asl){
        .bytes_0 = 6711554u, .more_0 = NIM_NIL}
      , (string_0_sysvq0asl){
        .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I13200118161122656888_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1869573374u, .more_0 = (&strlit_0_I5622496984824462814_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1868788734u, .more_0 = (&strlit_0_I110166545589372112_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1650551811u, .more_0 = NIM_NIL}
      , (string_0_sysvq0asl){
        .bytes_0 = 1886218755u, .more_0 = NIM_NIL}
      , (string_0_sysvq0asl){
        .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I2956720964102846418_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1701736446u, .more_0 = (&strlit_0_I5809186183819720447_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1701145598u, .more_0 = (&strlit_0_I6800807151669219983_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1767994110u, .more_0 = (&strlit_0_I6137881024046402116_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1952805379u, .more_0 = NIM_NIL}
      , (string_0_sysvq0asl){
        .bytes_0 = 1701995262u, .more_0 = (&strlit_0_I8380221545607033154_emi78vuj01)}}}
  ;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1159 = toOpenArray_0_Ima7t9w_emi78vuj01((&X60QconstRefTemp_0));
  NB8 X60Qx_1160 = oneOf_0_emi78vuj01(t_8, X60Qx_1159);
  result_64 = X60Qx_1160;
  return result_64;}
Classified_0_emi78vuj01 classify_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* root_0){
  Classified_0_emi78vuj01 result_65;
  eQwasmovedQ_SX43lassified0emi78vuj01_0_emi78vuj01((&result_65));
  NB8 X60Qx_1161;
  NB8 X60Qx_1162 = isList_0_emi78vuj01(root_0);
  if (X60Qx_1162){
    NB8 X60Qx_1163 = eqQ_20_sysvq0asl((*root_0).d_00.tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_emi78vuj01)}
    );
    X60Qx_1161 = X60Qx_1163;}
  else {
    X60Qx_1161 = NIM_FALSE;}
  if ((!X60Qx_1161)){
    fail_0_emi78vuj01((string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I14935256828133567672_emi78vuj01)}
    );}
  eQdestroyQ_SX43lassified0emi78vuj01_0_emi78vuj01((&result_65));
  seq_0_Isutro81_emi78vuj01 X60Qx_1164 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  seq_0_Isutro81_emi78vuj01 X60Qx_1165 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  seq_0_Isutro81_emi78vuj01 X60Qx_1166 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  seq_0_Isutro81_emi78vuj01 X60Qx_1167 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  result_65 = (Classified_0_emi78vuj01){
    .procs_0 = X60Qx_1164, .globals_0 = X60Qx_1165, .types_0 = X60Qx_1166, .topStmts_0 = X60Qx_1167}
  ;
  seq_0_Isutro81_emi78vuj01* X60Qlhs_114 = (&result_65.procs_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*X60Qlhs_114));
  seq_0_Isutro81_emi78vuj01 X60Qx_1168 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  (*X60Qlhs_114) = X60Qx_1168;
  seq_0_Isutro81_emi78vuj01* X60Qlhs_115 = (&result_65.globals_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*X60Qlhs_115));
  seq_0_Isutro81_emi78vuj01 X60Qx_1169 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  (*X60Qlhs_115) = X60Qx_1169;
  seq_0_Isutro81_emi78vuj01* X60Qlhs_116 = (&result_65.types_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*X60Qlhs_116));
  seq_0_Isutro81_emi78vuj01 X60Qx_1170 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  (*X60Qlhs_116) = X60Qx_1170;
  seq_0_Isutro81_emi78vuj01* X60Qlhs_117 = (&result_65.topStmts_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*X60Qlhs_117));
  seq_0_Isutro81_emi78vuj01 X60Qx_1171 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  (*X60Qlhs_117) = X60Qx_1171;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_50 = toOpenArray_1_I1gbnw21_emi78vuj01((*root_0).d_00.kids_0);
    NI32 X60Qlf_51 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1172 = len_6_I3x6mi_emi78vuj01(X60Qlf_50);
        if (X60Qlf_51 < X60Qx_1172){
          {
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_3 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_50, X60Qlf_51);
              NB8 X60Qx_1173 = isList_0_emi78vuj01((*X60Qii_3));
              if ((!X60Qx_1173)){
                goto continueLabel_2;}
              NB8 X60Qx_1174;
              NB8 X60Qx_1175 = eqQ_20_sysvq0asl((*(*X60Qii_3)).d_00.tag_0, (string_0_sysvq0asl){
                .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I5316556160589403975_emi78vuj01)}
              );
              if (X60Qx_1175){
                X60Qx_1174 = NIM_TRUE;}
              else {
                NB8 X60Qx_1176 = eqQ_20_sysvq0asl((*(*X60Qii_3)).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1853187838u, .more_0 = (&strlit_0_I9991102891510134496_emi78vuj01)}
                );
                X60Qx_1174 = X60Qx_1176;}
              if (X60Qx_1174){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1177 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_3));
                add_0_Iv4n2t31_emi78vuj01((&result_65.procs_0), X60Qx_1177);}
              else {
                X60Qt_0_IAarraySstring0sysvq0aslS6_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS6_emi78vuj01){
                  .a = {
                    (string_0_sysvq0asl){
                      .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_emi78vuj01)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1635153150u, .more_0 = (&strlit_0_I13046452236886743244_emi78vuj01)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1701603326u, .more_0 = (&strlit_0_I5723805845286553140_emi78vuj01)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I12999086881046019782_emi78vuj01)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1952803843u, .more_0 = NIM_NIL}}}
                ;
                openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1178 = toOpenArray_0_I6nl44k1_emi78vuj01((&X60QconstRefTemp_0));
                NB8 X60Qx_1179 = oneOf_0_emi78vuj01((*(*X60Qii_3)).d_00.tag_0, X60Qx_1178);
                if (X60Qx_1179){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1180 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_3));
                  add_0_Iv4n2t31_emi78vuj01((&result_65.globals_0), X60Qx_1180);}
                else {
                  NB8 X60Qx_1181 = eqQ_20_sysvq0asl((*(*X60Qii_3)).d_00.tag_0, (string_0_sysvq0asl){
                    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
                  );
                  if (X60Qx_1181){
                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1182 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_3));
                    add_0_Iv4n2t31_emi78vuj01((&result_65.types_0), X60Qx_1182);}
                  else {
                    NB8 X60Qx_1183 = isStmtTag_0_emi78vuj01((*(*X60Qii_3)).d_00.tag_0);
                    if (X60Qx_1183){
                      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1184 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_3));
                      add_0_Iv4n2t31_emi78vuj01((&result_65.topStmts_0), X60Qx_1184);}}}}}
            continueLabel_2: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_51));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_65;}
void buildExternMaps_0_emi78vuj01(seq_0_Isutro81_emi78vuj01 procs_0, seq_0_Isutro81_emi78vuj01 globals_0, seq_0_Isutro81_emi78vuj01 types_0){
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_52 = toOpenArray_1_I1gbnw21_emi78vuj01(procs_0);
    NI32 X60Qlf_53 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1185 = len_6_I3x6mi_emi78vuj01(X60Qlf_52);
        if (X60Qlf_53 < X60Qx_1185){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_52, X60Qlf_53);
            ProcParts_0_emi78vuj01 X60Qii_3 = procParts_0_emi78vuj01((*X60Qii_2));
            string_0_sysvq0asl X60Qii_4 = externName_0_emi78vuj01(X60Qii_3.pragmas_0);
            NI32 X60Qx_1186 = len_4_sysvq0asl(X60Qii_4);
            if (0 < X60Qx_1186){
              string_0_sysvq0asl X60Qx_1187 = nimStrDup((*X60Qii_3.nameAtom_0).d_00.atom_0);
              add_0_Ig6072n_aow7lb5cq1((&externKeys_0_emi78vuj01), X60Qx_1187);
              string_0_sysvq0asl X60Qtmp_118 = X60Qii_4;
              nimStrWasMoved((&X60Qii_4));
              add_0_Ig6072n_aow7lb5cq1((&externVals_0_emi78vuj01), X60Qtmp_118);}
            else {
              X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I4862850237857511107_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1188 = toOpenArray_0_I3urt0l_emi78vuj01((&X60QconstRefTemp_0));
              NB8 X60Qx_1189 = hasPragma_0_emi78vuj01(X60Qii_3.pragmas_0, X60Qx_1188);
              if (X60Qx_1189){
                string_0_sysvq0asl X60Qx_1190 = nimStrDup((*X60Qii_3.nameAtom_0).d_00.atom_0);
                add_0_Ig6072n_aow7lb5cq1((&externKeys_0_emi78vuj01), X60Qx_1190);
                string_0_sysvq0asl X60Qx_1191 = beforeDot_0_emi78vuj01((*X60Qii_3.nameAtom_0).d_00.atom_0);
                add_0_Ig6072n_aow7lb5cq1((&externVals_0_emi78vuj01), X60Qx_1191);}}
            nimStrDestroy(X60Qii_4);
            eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_3));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_53));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_54 = toOpenArray_1_I1gbnw21_emi78vuj01(globals_0);
    NI32 X60Qlf_55 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1192 = len_6_I3x6mi_emi78vuj01(X60Qlf_54);
        if (X60Qlf_55 < X60Qx_1192){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_7 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_54, X60Qlf_55);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1193 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_7)).d_00.kids_0, 0);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_8 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1193));
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1194 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_7)).d_00.kids_0, 1);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_9 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1194));
            string_0_sysvq0asl X60Qii_10 = externName_0_emi78vuj01(X60Qii_9);
            NI32 X60Qx_1195 = len_4_sysvq0asl(X60Qii_10);
            if (0 < X60Qx_1195){
              string_0_sysvq0asl X60Qx_1196 = nimStrDup((*X60Qii_8).d_00.atom_0);
              add_0_Ig6072n_aow7lb5cq1((&externKeys_0_emi78vuj01), X60Qx_1196);
              string_0_sysvq0asl X60Qtmp_119 = X60Qii_10;
              nimStrWasMoved((&X60Qii_10));
              add_0_Ig6072n_aow7lb5cq1((&externVals_0_emi78vuj01), X60Qtmp_119);}
            nimStrDestroy(X60Qii_10);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_9);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_8);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_55));}
        else {
          break;}}}
    whileStmtLabel_6: ;}
  forStmtLabel_5: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_56 = toOpenArray_1_I1gbnw21_emi78vuj01(types_0);
    NI32 X60Qlf_57 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1197 = len_6_I3x6mi_emi78vuj01(X60Qlf_56);
        if (X60Qlf_57 < X60Qx_1197){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_13 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_56, X60Qlf_57);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1198 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_13)).d_00.kids_0, 0);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_14 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1198));
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_15 = findTag_0_emi78vuj01((*X60Qii_13), (string_0_sysvq0asl){
              .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
            );
            string_0_sysvq0asl X60Qii_16 = externName_0_emi78vuj01(X60Qii_15);
            NI32 X60Qx_1199 = len_4_sysvq0asl(X60Qii_16);
            if (0 < X60Qx_1199){
              string_0_sysvq0asl X60Qx_1200 = nimStrDup((*X60Qii_14).d_00.atom_0);
              add_0_Ig6072n_aow7lb5cq1((&typeExternKeys_0_emi78vuj01), X60Qx_1200);
              string_0_sysvq0asl X60Qtmp_120 = X60Qii_16;
              nimStrWasMoved((&X60Qii_16));
              add_0_Ig6072n_aow7lb5cq1((&typeExternVals_0_emi78vuj01), X60Qtmp_120);}
            X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01 X60QconstRefTemp_1 = (X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01){
              .a = {
                (string_0_sysvq0asl){
                  .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}
                , (string_0_sysvq0asl){
                  .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
                , (string_0_sysvq0asl){
                  .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}
                , (string_0_sysvq0asl){
                  .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}}}
            ;
            openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1201 = toOpenArray_0_Ig1w4is1_emi78vuj01((&X60QconstRefTemp_1));
            NB8 X60Qx_1202 = hasPragma_0_emi78vuj01(X60Qii_15, X60Qx_1201);
            if (X60Qx_1202){
              string_0_sysvq0asl X60Qx_1203 = nimStrDup((*X60Qii_14).d_00.atom_0);
              add_0_Ig6072n_aow7lb5cq1((&noDeclTypes_0_emi78vuj01), X60Qx_1203);}
            nimStrDestroy(X60Qii_16);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_15);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_14);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_57));}
        else {
          break;}}}
    whileStmtLabel_12: ;}
  forStmtLabel_11: ;}
void collectValueTypeAtoms_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* node_1, seq_0_Ixdx2fh1_aow7lb5cq1* outp_1){
  if (node_1 == NIM_NIL){
    return;}
  NB8 X60Qx_1226 = isAtom_0_emi78vuj01(node_1);
  if (X60Qx_1226){
    NB8 X60Qx_1227 = isDot_0_emi78vuj01(node_1);
    if ((!X60Qx_1227)){
      NB8 X60Qx_1228 = mapHas_0_emi78vuj01((*outp_1), (*node_1).d_00.atom_0);
      if ((!X60Qx_1228)){
        string_0_sysvq0asl X60Qx_1229 = nimStrDup((*node_1).d_00.atom_0);
        add_0_Ig6072n_aow7lb5cq1(outp_1, X60Qx_1229);}}
    return;}
  NB8 X60Qx_1230 = isList_0_emi78vuj01(node_1);
  if ((!X60Qx_1230)){
    return;}
  string_0_sysvq0asl tg_1 = nimStrDup((*node_1).d_00.tag_0);
  NB8 X60Qx_1231;
  NB8 X60Qx_1232;
  NB8 X60Qx_1233 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
    .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
  );
  if (X60Qx_1233){
    X60Qx_1232 = NIM_TRUE;}
  else {
    NB8 X60Qx_1234 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
      .bytes_0 = 1953522174u, .more_0 = (&strlit_0_I6488225283415667707_emi78vuj01)}
    );
    X60Qx_1232 = X60Qx_1234;}
  if (X60Qx_1232){
    X60Qx_1231 = NIM_TRUE;}
  else {
    NB8 X60Qx_1235 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
      .bytes_0 = 1701603070u, .more_0 = (&strlit_0_I13748185565082850274_emi78vuj01)}
    );
    X60Qx_1231 = X60Qx_1235;}
  if (X60Qx_1231){
    nimStrDestroy(tg_1);
    return;}
  else {
    NB8 X60Qx_1236 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
    );
    if (X60Qx_1236){
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1237 = getQ_7_Iheb436_emi78vuj01((*node_1).d_00.kids_0, 0);
      collectValueTypeAtoms_0_emi78vuj01((*X60Qx_1237), outp_1);
      nimStrDestroy(tg_1);
      return;}
    else {
      NB8 X60Qx_1238;
      NB8 X60Qx_1239 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
        .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
      );
      if (X60Qx_1239){
        X60Qx_1238 = NIM_TRUE;}
      else {
        NB8 X60Qx_1240 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
          .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I3302612697625453930_emi78vuj01)}
        );
        X60Qx_1238 = X60Qx_1240;}
      if (X60Qx_1238){
        NI32 start_2 = 0;
        NB8 X60Qx_1241;
        if (0 < (*node_1).d_00.kids_0.len_0){
          NB8 X60Qx_1242;
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1243 = getQ_7_Iheb436_emi78vuj01((*node_1).d_00.kids_0, 0);
          NB8 X60Qx_1244 = isDot_0_emi78vuj01((*X60Qx_1243));
          if (X60Qx_1244){
            X60Qx_1242 = NIM_TRUE;}
          else {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1245 = getQ_7_Iheb436_emi78vuj01((*node_1).d_00.kids_0, 0);
            NB8 X60Qx_1246 = isAtom_0_emi78vuj01((*X60Qx_1245));
            X60Qx_1242 = X60Qx_1246;}
          X60Qx_1241 = X60Qx_1242;}
        else {
          X60Qx_1241 = NIM_FALSE;}
        if (X60Qx_1241){
          NB8 X60Qx_1247;
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1248 = getQ_7_Iheb436_emi78vuj01((*node_1).d_00.kids_0, 0);
          NB8 X60Qx_1249 = isAtom_0_emi78vuj01((*X60Qx_1248));
          if (X60Qx_1249){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1250 = getQ_7_Iheb436_emi78vuj01((*node_1).d_00.kids_0, 0);
            NB8 X60Qx_1251 = isDot_0_emi78vuj01((*X60Qx_1250));
            X60Qx_1247 = (!X60Qx_1251);}
          else {
            X60Qx_1247 = NIM_FALSE;}
          if (X60Qx_1247){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1252 = getQ_7_Iheb436_emi78vuj01((*node_1).d_00.kids_0, 0);
            NB8 X60Qx_1253 = mapHas_0_emi78vuj01((*outp_1), (*(*X60Qx_1252)).d_00.atom_0);
            if ((!X60Qx_1253)){
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1254 = getQ_7_Iheb436_emi78vuj01((*node_1).d_00.kids_0, 0);
              string_0_sysvq0asl X60Qx_1255 = nimStrDup((*(*X60Qx_1254)).d_00.atom_0);
              add_0_Ig6072n_aow7lb5cq1(outp_1, X60Qx_1255);}}
          start_2 = 1;}
        NI32 i_20 = start_2;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1256 = len_3_Il6imzw1_emi78vuj01((*node_1).d_00.kids_0);
            if (i_20 < X60Qx_1256){
              {
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1257 = getQ_7_Iheb436_emi78vuj01((*node_1).d_00.kids_0, i_20);
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* f_1 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1257));
                inc_1_I6wjjge_aow2h993l1((&i_20));
                NB8 X60Qx_1258 = isList_0_emi78vuj01(f_1);
                if ((!X60Qx_1258)){
                  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(f_1);
                  goto continueLabel_1;}
                NB8 X60Qx_1259 = eqQ_20_sysvq0asl((*f_1).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
                );
                if (X60Qx_1259){
                  NI32 X60Qx_1260 = len_3_Il6imzw1_emi78vuj01((*f_1).d_00.kids_0);
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1261 = getQ_7_Iheb436_emi78vuj01((*f_1).d_00.kids_0, ((NI32)(X60Qx_1260 - 1)));
                  collectValueTypeAtoms_0_emi78vuj01((*X60Qx_1261), outp_1);}
                else {
                  NB8 X60Qx_1262;
                  NB8 X60Qx_1263 = eqQ_20_sysvq0asl((*f_1).d_00.tag_0, (string_0_sysvq0asl){
                    .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I3302612697625453930_emi78vuj01)}
                  );
                  if (X60Qx_1263){
                    X60Qx_1262 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_1264 = eqQ_20_sysvq0asl((*f_1).d_00.tag_0, (string_0_sysvq0asl){
                      .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
                    );
                    X60Qx_1262 = X60Qx_1264;}
                  if (X60Qx_1262){
                    collectValueTypeAtoms_0_emi78vuj01(f_1, outp_1);}}
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(f_1);}
              continueLabel_1: ;}
            else {
              break;}}}
        whileStmtLabel_0: ;
        nimStrDestroy(tg_1);
        return;}
      else {
        nimStrDestroy(tg_1);
        return;}}}
  nimStrDestroy(tg_1);}
NI32 otStateOf_0_emi78vuj01(string_0_sysvq0asl nm_2){
  NI32 result_66;
  {
    NI32 X60Qlf_60 = 0;
    NI32 X60Qlf_61 = len_3_Ixq6taz_aow7lb5cq1(otStateKeys_0_emi78vuj01);
    NI32 X60Qlf_62 = X60Qlf_60;
    {
      while (X60Qlf_62 < X60Qlf_61){
        {
          string_0_sysvq0asl* X60Qx_1265 = getQ_7_Ir6d0tw_aow7lb5cq1(otStateKeys_0_emi78vuj01, X60Qlf_62);
          NB8 X60Qx_1266 = eqQ_20_sysvq0asl((*X60Qx_1265), nm_2);
          if (X60Qx_1266){
            NI32* X60Qx_1267 = getQ_7_Ir8kccm_aow7lb5cq1(otStateVals_0_emi78vuj01, X60Qlf_62);
            result_66 = (*X60Qx_1267);
            return result_66;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_62));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return -1;
  return result_66;}
void otSetState_0_emi78vuj01(string_0_sysvq0asl nm_3, NI32 v_1){
  {
    NI32 X60Qlf_63 = 0;
    NI32 X60Qlf_64 = len_3_Ixq6taz_aow7lb5cq1(otStateKeys_0_emi78vuj01);
    NI32 X60Qlf_65 = X60Qlf_63;
    {
      while (X60Qlf_65 < X60Qlf_64){
        {
          string_0_sysvq0asl* X60Qx_1268 = getQ_7_Ir6d0tw_aow7lb5cq1(otStateKeys_0_emi78vuj01, X60Qlf_65);
          NB8 X60Qx_1269 = eqQ_20_sysvq0asl((*X60Qx_1268), nm_3);
          if (X60Qx_1269){
            putQ_7_Ifvyck5_aow7lb5cq1((&otStateVals_0_emi78vuj01), X60Qlf_65, v_1);
            return;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_65));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qx_1270 = nimStrDup(nm_3);
  add_0_Ig6072n_aow7lb5cq1((&otStateKeys_0_emi78vuj01), X60Qx_1270);
  add_0_I8kd4i4_aow7lb5cq1((&otStateVals_0_emi78vuj01), v_1);}
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* otByName_0_emi78vuj01(string_0_sysvq0asl nm_4){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* result_67;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&result_67));
  {
    NI32 X60Qlf_66 = 0;
    NI32 X60Qlf_67 = len_3_Il6imzw1_emi78vuj01(otTypes_0_emi78vuj01);
    NI32 X60Qlf_68 = X60Qlf_66;
    {
      while (X60Qlf_68 < X60Qlf_67){
        {
          string_0_sysvq0asl* X60Qx_1271 = getQ_7_Ir6d0tw_aow7lb5cq1(otNames_0_emi78vuj01, X60Qlf_68);
          NB8 X60Qx_1272 = eqQ_20_sysvq0asl((*X60Qx_1271), nm_4);
          if (X60Qx_1272){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1273 = getQ_7_Iheb436_emi78vuj01(otTypes_0_emi78vuj01, X60Qlf_68);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1274 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1273));
            result_67 = X60Qx_1274;
            return result_67;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_68));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return NIM_NIL;
  return result_67;}
seq_0_Ixdx2fh1_aow7lb5cq1 otValueDeps_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* td_2){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_68;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_68));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_68);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1275 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_68 = X60Qx_1275;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pragmas_9 = findTag_0_emi78vuj01(td_2, (string_0_sysvq0asl){
    .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
  );
  X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01){
    .a = {
      (string_0_sysvq0asl){
        .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}}}
  ;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1276 = toOpenArray_0_Ig1w4is1_emi78vuj01((&X60QconstRefTemp_0));
  NB8 X60Qx_1277 = hasPragma_0_emi78vuj01(pragmas_9, X60Qx_1276);
  if (X60Qx_1277){
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_9);
    return result_68;}
  seq_0_Ixdx2fh1_aow7lb5cq1 deps_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  NI32 X60Qx_1278 = len_3_Il6imzw1_emi78vuj01((*td_2).d_00.kids_0);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1279 = getQ_7_Iheb436_emi78vuj01((*td_2).d_00.kids_0, ((NI32)(X60Qx_1278 - 1)));
  collectValueTypeAtoms_0_emi78vuj01((*X60Qx_1279), (&deps_0));
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_69 = toOpenArray_1_I6b60gk1_aow7lb5cq1(deps_0);
    NI32 X60Qlf_70 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1280 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_69);
        if (X60Qlf_70 < X60Qx_1280){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_69, X60Qlf_70);
            NB8 X60Qx_1281;
            NB8 X60Qx_1282 = mapHas_0_emi78vuj01(otNames_0_emi78vuj01, (*X60Qii_2));
            if (X60Qx_1282){
              NB8 X60Qx_1283 = mapHas_0_emi78vuj01(result_68, (*X60Qii_2));
              X60Qx_1281 = (!X60Qx_1283);}
            else {
              X60Qx_1281 = NIM_FALSE;}
            if (X60Qx_1281){
              string_0_sysvq0asl X60Qx_1284 = nimStrDup((*X60Qii_2));
              add_0_Ig6072n_aow7lb5cq1((&result_68), X60Qx_1284);}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_70));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(deps_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_9);
  return result_68;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(deps_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pragmas_9);
  return result_68;}
void otVisit_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* td_3){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1285 = getQ_7_Iheb436_emi78vuj01((*td_3).d_00.kids_0, 0);
  string_0_sysvq0asl nm_10 = nimStrDup((*(*X60Qx_1285)).d_00.atom_0);
  NI32 X60Qx_1286 = otStateOf_0_emi78vuj01(nm_10);
  if (0 <= X60Qx_1286){
    nimStrDestroy(nm_10);
    return;}
  otSetState_0_emi78vuj01(nm_10, 0);
  {
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_121 = otValueDeps_0_emi78vuj01(td_3);
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_71 = toOpenArray_1_I6b60gk1_aow7lb5cq1(X60Qtmp_121);
    NI32 X60Qlf_72 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1287 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_71);
        if (X60Qlf_72 < X60Qx_1287){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_71, X60Qlf_72);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_3 = otByName_0_emi78vuj01((*X60Qii_2));
            NB8 X60Qx_1288;
            if ((!(X60Qii_3 == NIM_NIL))){
              X60Qx_1288 = (!(X60Qii_3 == td_3));}
            else {
              X60Qx_1288 = NIM_FALSE;}
            if (X60Qx_1288){
              otVisit_0_emi78vuj01(X60Qii_3);}
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_3);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_72));}
        else {
          break;}}}
    whileStmtLabel_1: ;
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_121);}
  forStmtLabel_0: ;
  otSetState_0_emi78vuj01(nm_10, 1);
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1289 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(td_3);
  add_0_Iv4n2t31_emi78vuj01((&otOrder_0_emi78vuj01), X60Qx_1289);
  nimStrDestroy(nm_10);}
seq_0_Isutro81_emi78vuj01 orderTypesByValueDeps_0_emi78vuj01(seq_0_Isutro81_emi78vuj01 types_1){
  seq_0_Isutro81_emi78vuj01 result_69;
  eQwasMoved_1_Iu9z3fg1_emi78vuj01((&result_69));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(otNames_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1290 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  otNames_0_emi78vuj01 = X60Qx_1290;
  eQdestroy_1_Ia4wwhy1_emi78vuj01(otTypes_0_emi78vuj01);
  seq_0_Isutro81_emi78vuj01 X60Qx_1291 = eQdup_1_Iqcqrch1_emi78vuj01(types_1);
  otTypes_0_emi78vuj01 = X60Qx_1291;
  eQdestroy_1_Ia4wwhy1_emi78vuj01(otOrder_0_emi78vuj01);
  seq_0_Isutro81_emi78vuj01 X60Qx_1292 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  otOrder_0_emi78vuj01 = X60Qx_1292;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(otStateKeys_0_emi78vuj01);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1293 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  otStateKeys_0_emi78vuj01 = X60Qx_1293;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(otStateVals_0_emi78vuj01);
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_1294 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  otStateVals_0_emi78vuj01 = X60Qx_1294;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_73 = toOpenArray_1_I1gbnw21_emi78vuj01(types_1);
    NI32 X60Qlf_74 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1295 = len_6_I3x6mi_emi78vuj01(X60Qlf_73);
        if (X60Qlf_74 < X60Qx_1295){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_73, X60Qlf_74);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1296 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_2)).d_00.kids_0, 0);
            string_0_sysvq0asl X60Qx_1297 = nimStrDup((*(*X60Qx_1296)).d_00.atom_0);
            add_0_Ig6072n_aow7lb5cq1((&otNames_0_emi78vuj01), X60Qx_1297);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_74));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_75 = toOpenArray_1_I1gbnw21_emi78vuj01(types_1);
    NI32 X60Qlf_76 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1298 = len_6_I3x6mi_emi78vuj01(X60Qlf_75);
        if (X60Qlf_76 < X60Qx_1298){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_5 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_75, X60Qlf_76);
            otVisit_0_emi78vuj01((*X60Qii_5));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_76));}
        else {
          break;}}}
    whileStmtLabel_4: ;}
  forStmtLabel_3: ;
  seq_0_Isutro81_emi78vuj01 X60Qx_1299 = eQdup_1_Iqcqrch1_emi78vuj01(otOrder_0_emi78vuj01);
  return X60Qx_1299;
  return result_69;}
string_0_sysvq0asl lastComponent_0_emi78vuj01(string_0_sysvq0asl s_16){
  string_0_sysvq0asl result_70;
  nimStrWasMoved((&result_70));
  NI32 X60Qx_1300 = len_4_sysvq0asl(s_16);
  NI32 i_26 = ((NI32)(X60Qx_1300 - 1));
  {
    while (NIM_TRUE){
      NB8 X60Qx_1301;
      if (0 <= i_26){
        NC8 X60Qx_1302 = getQ_9_sysvq0asl(s_16, i_26);
        X60Qx_1301 = (!(X60Qx_1302 == (NC8)'.'));}
      else {
        X60Qx_1301 = NIM_FALSE;}
      if (X60Qx_1301){
        dec_1_I0nzoz91_aow7lb5cq1((&i_26));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (i_26 < 0){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 X60Qx_1303 = len_4_sysvq0asl(s_16);
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1304 = __ltQ_1_Ij9jwi_dbgj4vyzj1(((NI32)(i_26 + 1)), X60Qx_1303);
  string_0_sysvq0asl X60Qx_1305 = getQ_14_sysvq0asl(s_16, X60Qx_1304);
  result_70 = X60Qx_1305;
  return result_70;
  return result_70;}
string_0_sysvq0asl foreignModuleOf_0_emi78vuj01(string_0_sysvq0asl atom_0){
  string_0_sysvq0asl result_71;
  nimStrWasMoved((&result_71));
  string_0_sysvq0asl lc_0 = lastComponent_0_emi78vuj01(atom_0);
  NI32 X60Qx_1306 = len_4_sysvq0asl(lc_0);
  if (X60Qx_1306 == 0){
    nimStrDestroy(lc_0);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NB8 X60Qx_1307 = eqQ_20_sysvq0asl(lc_0, ownMod_0_emi78vuj01);
  if (X60Qx_1307){
    nimStrDestroy(lc_0);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NB8 X60Qx_1308 = mapHas_0_emi78vuj01(siblingSuffixes_0_emi78vuj01, lc_0);
  if (X60Qx_1308){
    string_0_sysvq0asl X60Qtmp_122 = lc_0;
    nimStrWasMoved((&lc_0));
    nimStrDestroy(lc_0);
    return X60Qtmp_122;}
  NB8 X60Qx_1309 = mapHas_0_emi78vuj01(checkedSuffixes_0_emi78vuj01, lc_0);
  if (X60Qx_1309){
    nimStrDestroy(lc_0);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl X60Qx_1310 = nimStrDup(lc_0);
  add_0_Ig6072n_aow7lb5cq1((&checkedSuffixes_0_emi78vuj01), X60Qx_1310);
  string_0_sysvq0asl X60Qx_21;
  nimStrWasMoved((&X60Qx_21));
  NI32 X60Qx_1311 = len_4_sysvq0asl(prog_0_prorcx25w1.main_0.dir_0);
  if (0 < X60Qx_1311){
    nimStrDestroy(X60Qx_21);
    string_0_sysvq0asl X60Qx_1312 = nimStrDup(prog_0_prorcx25w1.main_0.dir_0);
    X60Qx_21 = X60Qx_1312;}
  else {
    nimStrDestroy(X60Qx_21);
    X60Qx_21 = (string_0_sysvq0asl){
      .bytes_0 = 11777u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl dir_0 = X60Qx_21;
  nimStrWasMoved((&X60Qx_21));
  NI32 X60Qx_1313 = len_4_sysvq0asl(dir_0);
  NI32 X60Qx_1314 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1315 = len_4_sysvq0asl(lc_0);
  NI32 X60Qx_1316 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17410079638349000741_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_135 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1313 + X60Qx_1314)) + X60Qx_1315)) + X60Qx_1316)));
  add_2_sysvq0asl((&X60Qdesugar_135), dir_0);
  add_2_sysvq0asl((&X60Qdesugar_135), (string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_135), lc_0);
  add_2_sysvq0asl((&X60Qdesugar_135), (string_0_sysvq0asl){
    .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17410079638349000741_aow7lb5cq1)}
  );
  NB8 X60Qx_1317 = fileExists_0_osc4bsu0d1(X60Qdesugar_135);
  if (X60Qx_1317){
    string_0_sysvq0asl X60Qx_1318 = nimStrDup(lc_0);
    add_0_Ig6072n_aow7lb5cq1((&siblingSuffixes_0_emi78vuj01), X60Qx_1318);
    string_0_sysvq0asl X60Qtmp_123 = lc_0;
    nimStrWasMoved((&lc_0));
    nimStrDestroy(X60Qdesugar_135);
    nimStrDestroy(dir_0);
    nimStrDestroy(X60Qx_21);
    nimStrDestroy(lc_0);
    return X60Qtmp_123;}
  nimStrDestroy(X60Qdesugar_135);
  nimStrDestroy(dir_0);
  nimStrDestroy(X60Qx_21);
  nimStrDestroy(lc_0);
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  nimStrDestroy(X60Qdesugar_135);
  nimStrDestroy(dir_0);
  nimStrDestroy(X60Qx_21);
  nimStrDestroy(lc_0);
  return result_71;
  nimStrDestroy(X60Qdesugar_135);
  nimStrDestroy(dir_0);
  nimStrDestroy(X60Qx_21);
  nimStrDestroy(lc_0);
  return result_71;}
void loadSiblingModule_0_emi78vuj01(string_0_sysvq0asl suffix_0){
  NB8 X60Qx_1319 = mapHas_0_emi78vuj01(loadedMods_0_emi78vuj01, suffix_0);
  if (X60Qx_1319){
    return;}
  string_0_sysvq0asl X60Qx_1320 = nimStrDup(suffix_0);
  add_0_Ig6072n_aow7lb5cq1((&loadedMods_0_emi78vuj01), X60Qx_1320);
  string_0_sysvq0asl X60Qx_22;
  nimStrWasMoved((&X60Qx_22));
  NI32 X60Qx_1321 = len_4_sysvq0asl(prog_0_prorcx25w1.main_0.dir_0);
  if (0 < X60Qx_1321){
    nimStrDestroy(X60Qx_22);
    string_0_sysvq0asl X60Qx_1322 = nimStrDup(prog_0_prorcx25w1.main_0.dir_0);
    X60Qx_22 = X60Qx_1322;}
  else {
    nimStrDestroy(X60Qx_22);
    X60Qx_22 = (string_0_sysvq0asl){
      .bytes_0 = 11777u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl dir_1 = X60Qx_22;
  nimStrWasMoved((&X60Qx_22));
  NI32 X60Qx_1323 = len_4_sysvq0asl(dir_1);
  NI32 X60Qx_1324 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1325 = len_4_sysvq0asl(suffix_0);
  NI32 X60Qx_1326 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17410079638349000741_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_136 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1323 + X60Qx_1324)) + X60Qx_1325)) + X60Qx_1326)));
  add_2_sysvq0asl((&X60Qdesugar_136), dir_1);
  add_2_sysvq0asl((&X60Qdesugar_136), (string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_136), suffix_0);
  add_2_sysvq0asl((&X60Qdesugar_136), (string_0_sysvq0asl){
    .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17410079638349000741_aow7lb5cq1)}
  );
  string_0_sysvq0asl path_0 = X60Qdesugar_136;
  nimStrWasMoved((&X60Qdesugar_136));
  NB8 X60Qx_1327 = fileExists_0_osc4bsu0d1(path_0);
  if ((!X60Qx_1327)){
    nimStrDestroy(path_0);
    nimStrDestroy(X60Qdesugar_136);
    nimStrDestroy(dir_1);
    nimStrDestroy(X60Qx_22);
    return;}
  TokenBuf_0_nifb6mq6y1 buf_0 = parseFromFile_0_nifb6mq6y1(path_0, 100);
  Cursor_0_nifb6mq6y1 cur_1 = beginRead_0_nifb6mq6y1((&buf_0));
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* tree_0 = buildNode_1_emi78vuj01((&cur_1));
  endRead_0_nifb6mq6y1((&buf_0));
  NB8 X60Qx_1328 = isList_0_emi78vuj01(tree_0);
  if ((!X60Qx_1328)){
    eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(tree_0);
    eQdestroy_0_nifb6mq6y1((&cur_1));
    eQdestroy_1_nifb6mq6y1((&buf_0));
    nimStrDestroy(path_0);
    nimStrDestroy(X60Qdesugar_136);
    nimStrDestroy(dir_1);
    nimStrDestroy(X60Qx_22);
    return;}
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_77 = toOpenArray_1_I1gbnw21_emi78vuj01((*tree_0).d_00.kids_0);
    NI32 X60Qlf_78 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1329 = len_6_I3x6mi_emi78vuj01(X60Qlf_77);
        if (X60Qlf_78 < X60Qx_1329){
          {
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_3 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_77, X60Qlf_78);
              NB8 X60Qx_1330 = isList_0_emi78vuj01((*X60Qii_3));
              if ((!X60Qx_1330)){
                goto continueLabel_2;}
              NB8 X60Qx_1331;
              NB8 X60Qx_1332 = eqQ_20_sysvq0asl((*(*X60Qii_3)).d_00.tag_0, (string_0_sysvq0asl){
                .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I5316556160589403975_emi78vuj01)}
              );
              if (X60Qx_1332){
                X60Qx_1331 = NIM_TRUE;}
              else {
                NB8 X60Qx_1333 = eqQ_20_sysvq0asl((*(*X60Qii_3)).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1853187838u, .more_0 = (&strlit_0_I9991102891510134496_emi78vuj01)}
                );
                X60Qx_1331 = X60Qx_1333;}
              if (X60Qx_1331){
                NB8 X60Qx_1334;
                if (0 < (*(*X60Qii_3)).d_00.kids_0.len_0){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1335 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                  NB8 X60Qx_1336 = isAtom_0_emi78vuj01((*X60Qx_1335));
                  X60Qx_1334 = X60Qx_1336;}
                else {
                  X60Qx_1334 = NIM_FALSE;}
                if (X60Qx_1334){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1337 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                  string_0_sysvq0asl X60Qx_1338 = nimStrDup((*(*X60Qx_1337)).d_00.atom_0);
                  add_0_Ig6072n_aow7lb5cq1((&modProcKeys_0_emi78vuj01), X60Qx_1338);
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1339 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_3));
                  add_0_Iv4n2t31_emi78vuj01((&modProcVals_0_emi78vuj01), X60Qx_1339);}}
              else {
                X60Qt_0_IAarraySstring0sysvq0aslS6_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS6_emi78vuj01){
                  .a = {
                    (string_0_sysvq0asl){
                      .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_emi78vuj01)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1635153150u, .more_0 = (&strlit_0_I13046452236886743244_emi78vuj01)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1701603326u, .more_0 = (&strlit_0_I5723805845286553140_emi78vuj01)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I12999086881046019782_emi78vuj01)}}}
                ;
                openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1340 = toOpenArray_0_I6nl44k1_emi78vuj01((&X60QconstRefTemp_0));
                NB8 X60Qx_1341 = oneOf_0_emi78vuj01((*(*X60Qii_3)).d_00.tag_0, X60Qx_1340);
                if (X60Qx_1341){
                  NB8 X60Qx_1342;
                  if (0 < (*(*X60Qii_3)).d_00.kids_0.len_0){
                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1343 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                    NB8 X60Qx_1344 = isAtom_0_emi78vuj01((*X60Qx_1343));
                    X60Qx_1342 = X60Qx_1344;}
                  else {
                    X60Qx_1342 = NIM_FALSE;}
                  if (X60Qx_1342){
                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1345 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                    string_0_sysvq0asl X60Qx_1346 = nimStrDup((*(*X60Qx_1345)).d_00.atom_0);
                    add_0_Ig6072n_aow7lb5cq1((&modGlobalKeys_0_emi78vuj01), X60Qx_1346);
                    X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1347 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_3));
                    add_0_Iv4n2t31_emi78vuj01((&modGlobalVals_0_emi78vuj01), X60Qx_1347);}}
                else {
                  NB8 X60Qx_1348 = eqQ_20_sysvq0asl((*(*X60Qii_3)).d_00.tag_0, (string_0_sysvq0asl){
                    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
                  );
                  if (X60Qx_1348){
                    NB8 X60Qx_1349;
                    if (0 < (*(*X60Qii_3)).d_00.kids_0.len_0){
                      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1350 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                      NB8 X60Qx_1351 = isAtom_0_emi78vuj01((*X60Qx_1350));
                      X60Qx_1349 = X60Qx_1351;}
                    else {
                      X60Qx_1349 = NIM_FALSE;}
                    if (X60Qx_1349){
                      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1352 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_3)).d_00.kids_0, 0);
                      string_0_sysvq0asl X60Qx_1353 = nimStrDup((*(*X60Qx_1352)).d_00.atom_0);
                      add_0_Ig6072n_aow7lb5cq1((&modTypeKeys_0_emi78vuj01), X60Qx_1353);
                      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1354 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_3));
                      add_0_Iv4n2t31_emi78vuj01((&modTypeVals_0_emi78vuj01), X60Qx_1354);}}}}}
            continueLabel_2: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_78));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(tree_0);
  eQdestroy_0_nifb6mq6y1((&cur_1));
  eQdestroy_1_nifb6mq6y1((&buf_0));
  nimStrDestroy(path_0);
  nimStrDestroy(X60Qdesugar_136);
  nimStrDestroy(dir_1);
  nimStrDestroy(X60Qx_22);}
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* modFindProc_0_emi78vuj01(string_0_sysvq0asl atom_1){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* result_72;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&result_72));
  {
    NI32 X60Qlf_79 = 0;
    NI32 X60Qlf_80 = len_3_Ixq6taz_aow7lb5cq1(modProcKeys_0_emi78vuj01);
    NI32 X60Qlf_81 = X60Qlf_79;
    {
      while (X60Qlf_81 < X60Qlf_80){
        {
          string_0_sysvq0asl* X60Qx_1355 = getQ_7_Ir6d0tw_aow7lb5cq1(modProcKeys_0_emi78vuj01, X60Qlf_81);
          NB8 X60Qx_1356 = eqQ_20_sysvq0asl((*X60Qx_1355), atom_1);
          if (X60Qx_1356){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1357 = getQ_7_Iheb436_emi78vuj01(modProcVals_0_emi78vuj01, X60Qlf_81);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1358 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1357));
            result_72 = X60Qx_1358;
            return result_72;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_81));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return NIM_NIL;
  return result_72;}
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* modFindGlobal_0_emi78vuj01(string_0_sysvq0asl atom_2){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* result_73;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&result_73));
  {
    NI32 X60Qlf_82 = 0;
    NI32 X60Qlf_83 = len_3_Ixq6taz_aow7lb5cq1(modGlobalKeys_0_emi78vuj01);
    NI32 X60Qlf_84 = X60Qlf_82;
    {
      while (X60Qlf_84 < X60Qlf_83){
        {
          string_0_sysvq0asl* X60Qx_1359 = getQ_7_Ir6d0tw_aow7lb5cq1(modGlobalKeys_0_emi78vuj01, X60Qlf_84);
          NB8 X60Qx_1360 = eqQ_20_sysvq0asl((*X60Qx_1359), atom_2);
          if (X60Qx_1360){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1361 = getQ_7_Iheb436_emi78vuj01(modGlobalVals_0_emi78vuj01, X60Qlf_84);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1362 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1361));
            result_73 = X60Qx_1362;
            return result_73;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_84));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return NIM_NIL;
  return result_73;}
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* modFindType_0_emi78vuj01(string_0_sysvq0asl atom_3){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* result_74;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&result_74));
  {
    NI32 X60Qlf_85 = 0;
    NI32 X60Qlf_86 = len_3_Ixq6taz_aow7lb5cq1(modTypeKeys_0_emi78vuj01);
    NI32 X60Qlf_87 = X60Qlf_85;
    {
      while (X60Qlf_87 < X60Qlf_86){
        {
          string_0_sysvq0asl* X60Qx_1363 = getQ_7_Ir6d0tw_aow7lb5cq1(modTypeKeys_0_emi78vuj01, X60Qlf_87);
          NB8 X60Qx_1364 = eqQ_20_sysvq0asl((*X60Qx_1363), atom_3);
          if (X60Qx_1364){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1365 = getQ_7_Iheb436_emi78vuj01(modTypeVals_0_emi78vuj01, X60Qlf_87);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1366 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1365));
            result_74 = X60Qx_1366;
            return result_74;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_87));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return NIM_NIL;
  return result_74;}
void collectForeignAtoms_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* n_10, seq_0_Ixdx2fh1_aow7lb5cq1* outp_2){
  if (n_10 == NIM_NIL){
    return;}
  NB8 X60Qx_1367 = isAtom_0_emi78vuj01(n_10);
  if (X60Qx_1367){
    NB8 X60Qx_47;
    string_0_sysvq0asl X60Qtmp_124 = foreignModuleOf_0_emi78vuj01((*n_10).d_00.atom_0);
    NI32 X60Qx_1368 = len_4_sysvq0asl(X60Qtmp_124);
    if (0 < X60Qx_1368){
      NB8 X60Qx_1369 = mapHas_0_emi78vuj01((*outp_2), (*n_10).d_00.atom_0);
      X60Qx_47 = (!X60Qx_1369);}
    else {
      X60Qx_47 = NIM_FALSE;}
    if (X60Qx_47){
      string_0_sysvq0asl X60Qx_1370 = nimStrDup((*n_10).d_00.atom_0);
      add_0_Ig6072n_aow7lb5cq1(outp_2, X60Qx_1370);}
    nimStrDestroy(X60Qtmp_124);
    return;
    nimStrDestroy(X60Qtmp_124);}
  NB8 X60Qx_1371 = isList_0_emi78vuj01(n_10);
  if (X60Qx_1371){
    {
      openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_88 = toOpenArray_1_I1gbnw21_emi78vuj01((*n_10).d_00.kids_0);
      NI32 X60Qlf_89 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1372 = len_6_I3x6mi_emi78vuj01(X60Qlf_88);
          if (X60Qlf_89 < X60Qx_1372){
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_2 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_88, X60Qlf_89);
              collectForeignAtoms_0_emi78vuj01((*X60Qii_2), outp_2);}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_89));}
          else {
            break;}}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}}
string_0_sysvq0asl indentC_0_emi78vuj01(string_0_sysvq0asl src_0){
  string_0_sysvq0asl result_75;
  nimStrWasMoved((&result_75));
  seq_0_Ixdx2fh1_aow7lb5cq1 lines_0 = splitLinesNl_0_emi78vuj01(src_0);
  NI32 depth_1 = 0;
  seq_0_Ixdx2fh1_aow7lb5cq1 outp_7 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_90 = toOpenArray_1_I6b60gk1_aow7lb5cq1(lines_0);
    NI32 X60Qlf_91 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1373 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_90);
        if (X60Qlf_91 < X60Qx_1373){
          {
            {
              string_0_sysvq0asl* X60Qii_3 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_90, X60Qlf_91);
              string_0_sysvq0asl X60Qii_4 = stripBoth_0_emi78vuj01((*X60Qii_3));
              NI32 X60Qx_1374 = len_4_sysvq0asl(X60Qii_4);
              if (X60Qx_1374 == 0){
                add_0_Ig6072n_aow7lb5cq1((&outp_7), (string_0_sysvq0asl){
                  .bytes_0 = 0u, .more_0 = NIM_NIL}
                );
                nimStrDestroy(X60Qii_4);
                goto continueLabel_2;}
              NC8 X60Qx_1375 = getQ_9_sysvq0asl(X60Qii_4, 0);
              if (X60Qx_1375 == (NC8)'#'){
                string_0_sysvq0asl X60Qtmp_125 = X60Qii_4;
                nimStrWasMoved((&X60Qii_4));
                add_0_Ig6072n_aow7lb5cq1((&outp_7), X60Qtmp_125);
                nimStrDestroy(X60Qii_4);
                goto continueLabel_2;}
              NI32 X60Qii_5 = depth_1;
              NC8 X60Qx_1376 = getQ_9_sysvq0asl(X60Qii_4, 0);
              if (X60Qx_1376 == (NC8)'}'){
                NI32 X60Qx_23;
                if (0 < ((NI32)(depth_1 - 1))){
                  X60Qx_23 = ((NI32)(depth_1 - 1));}
                else {
                  X60Qx_23 = 0;}
                X60Qii_5 = X60Qx_23;}
              string_0_sysvq0asl X60Qtmp_126 = myRepeat_0_emi78vuj01((string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              , X60Qii_5);
              string_0_sysvq0asl X60Qx_1377 = ampQ_0_sysvq0asl(X60Qtmp_126, X60Qii_4);
              add_0_Ig6072n_aow7lb5cq1((&outp_7), X60Qx_1377);
              {
                openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_92 = toOpenArray_2_sysvq0asl((&X60Qii_4));
                NI32 X60Qlf_93 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_1378 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_92);
                    if (X60Qlf_93 < X60Qx_1378){
                      {
                        NC8* X60Qii_8 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_92, X60Qlf_93);
                        if ((*X60Qii_8) == (NC8)'{'){
                          inc_1_I6wjjge_aow2h993l1((&depth_1));}
                        else {
                          if ((*X60Qii_8) == (NC8)'}'){
                            NI32 X60Qx_24;
                            if (0 < ((NI32)(depth_1 - 1))){
                              X60Qx_24 = ((NI32)(depth_1 - 1));}
                            else {
                              X60Qx_24 = 0;}
                            depth_1 = X60Qx_24;}}}
                      inc_1_I6wjjge_aow2h993l1((&X60Qlf_93));}
                    else {
                      break;}}}
                whileStmtLabel_7: ;}
              forStmtLabel_6: ;
              nimStrDestroy(X60Qtmp_126);
              nimStrDestroy(X60Qii_4);}
            continueLabel_2: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_91));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qx_1379 = joinSeq_0_emi78vuj01(outp_7, (string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  result_75 = X60Qx_1379;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(outp_7);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(lines_0);
  return result_75;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(outp_7);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(lines_0);
  return result_75;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(outp_7);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(lines_0);
  return result_75;}
string_0_sysvq0asl emitUnit_0_emi78vuj01(Classified_0_emi78vuj01* parts_0){
  string_0_sysvq0asl result_76;
  nimStrWasMoved((&result_76));
  seq_0_Isutro81_emi78vuj01 procs_1 = eQdup_1_Iqcqrch1_emi78vuj01((*parts_0).procs_0);
  seq_0_Isutro81_emi78vuj01 globals_1 = eQdup_1_Iqcqrch1_emi78vuj01((*parts_0).globals_0);
  seq_0_Isutro81_emi78vuj01 types_2 = eQdup_1_Iqcqrch1_emi78vuj01((*parts_0).types_0);
  seq_0_Isutro81_emi78vuj01 topStmts_0 = eQdup_1_Iqcqrch1_emi78vuj01((*parts_0).topStmts_0);
  buildExternMaps_0_emi78vuj01(procs_1, globals_1, types_2);
  {
    string_0_sysvq0asl found_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    {
      openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_94 = toOpenArray_1_I1gbnw21_emi78vuj01(procs_1);
      NI32 X60Qlf_95 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1380 = len_6_I3x6mi_emi78vuj01(X60Qlf_94);
          if (X60Qlf_95 < X60Qx_1380){
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_3 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_94, X60Qlf_95);
              ProcParts_0_emi78vuj01 X60Qtmp_127 = procParts_0_emi78vuj01((*X60Qii_3));
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_4 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qtmp_127.nameAtom_0);
              NB8 X60Qx_1381 = isAtom_0_emi78vuj01(X60Qii_4);
              if (X60Qx_1381){
                string_0_sysvq0asl X60Qii_5 = lastComponent_0_emi78vuj01((*X60Qii_4).d_00.atom_0);
                NI32 X60Qx_1382 = len_4_sysvq0asl(X60Qii_5);
                if (0 < X60Qx_1382){
                  nimStrDestroy(found_0);
                  found_0 = X60Qii_5;
                  nimStrWasMoved((&X60Qii_5));
                  nimStrDestroy(X60Qii_5);
                  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_4);
                  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qtmp_127));
                  goto forStmtLabel_1;}
                nimStrDestroy(X60Qii_5);}
              eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_4);
              eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qtmp_127));}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_95));}
          else {
            break;}}}
      whileStmtLabel_2: ;}
    forStmtLabel_1: ;
    NI32 X60Qx_1383 = len_4_sysvq0asl(found_0);
    if (X60Qx_1383 == 0){
      {
        openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_96 = toOpenArray_1_I1gbnw21_emi78vuj01(globals_1);
        NI32 X60Qlf_97 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1384 = len_6_I3x6mi_emi78vuj01(X60Qlf_96);
            if (X60Qlf_97 < X60Qx_1384){
              {
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_8 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_96, X60Qlf_97);
                NB8 X60Qx_1385;
                if (0 < (*(*X60Qii_8)).d_00.kids_0.len_0){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1386 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_8)).d_00.kids_0, 0);
                  NB8 X60Qx_1387 = isAtom_0_emi78vuj01((*X60Qx_1386));
                  X60Qx_1385 = X60Qx_1387;}
                else {
                  X60Qx_1385 = NIM_FALSE;}
                if (X60Qx_1385){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1388 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_8)).d_00.kids_0, 0);
                  string_0_sysvq0asl X60Qii_9 = lastComponent_0_emi78vuj01((*(*X60Qx_1388)).d_00.atom_0);
                  NI32 X60Qx_1389 = len_4_sysvq0asl(X60Qii_9);
                  if (0 < X60Qx_1389){
                    nimStrDestroy(found_0);
                    found_0 = X60Qii_9;
                    nimStrWasMoved((&X60Qii_9));
                    nimStrDestroy(X60Qii_9);
                    goto forStmtLabel_6;}
                  nimStrDestroy(X60Qii_9);}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_97));}
            else {
              break;}}}
        whileStmtLabel_7: ;}
      forStmtLabel_6: ;}
    NI32 X60Qx_1390 = len_4_sysvq0asl(found_0);
    if (X60Qx_1390 == 0){
      {
        openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_98 = toOpenArray_1_I1gbnw21_emi78vuj01(types_2);
        NI32 X60Qlf_99 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1391 = len_6_I3x6mi_emi78vuj01(X60Qlf_98);
            if (X60Qlf_99 < X60Qx_1391){
              {
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_12 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_98, X60Qlf_99);
                NB8 X60Qx_1392;
                if (0 < (*(*X60Qii_12)).d_00.kids_0.len_0){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1393 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_12)).d_00.kids_0, 0);
                  NB8 X60Qx_1394 = isAtom_0_emi78vuj01((*X60Qx_1393));
                  X60Qx_1392 = X60Qx_1394;}
                else {
                  X60Qx_1392 = NIM_FALSE;}
                if (X60Qx_1392){
                  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1395 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_12)).d_00.kids_0, 0);
                  string_0_sysvq0asl X60Qii_13 = lastComponent_0_emi78vuj01((*(*X60Qx_1395)).d_00.atom_0);
                  NI32 X60Qx_1396 = len_4_sysvq0asl(X60Qii_13);
                  if (0 < X60Qx_1396){
                    nimStrDestroy(found_0);
                    found_0 = X60Qii_13;
                    nimStrWasMoved((&X60Qii_13));
                    nimStrDestroy(X60Qii_13);
                    goto forStmtLabel_10;}
                  nimStrDestroy(X60Qii_13);}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_99));}
            else {
              break;}}}
        whileStmtLabel_11: ;}
      forStmtLabel_10: ;}
    NI32 X60Qx_1397 = len_4_sysvq0asl(found_0);
    if (0 < X60Qx_1397){
      nimStrDestroy(ownMod_0_emi78vuj01);
      ownMod_0_emi78vuj01 = found_0;
      nimStrWasMoved((&found_0));}
    nimStrDestroy(found_0);}
  X60Qlab_0: ;
  seq_0_Ixdx2fh1_aow7lb5cq1 definedSyms_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_100 = toOpenArray_1_I1gbnw21_emi78vuj01(procs_1);
    NI32 X60Qlf_101 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1398 = len_6_I3x6mi_emi78vuj01(X60Qlf_100);
        if (X60Qlf_101 < X60Qx_1398){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_16 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_100, X60Qlf_101);
            ProcParts_0_emi78vuj01 X60Qtmp_128 = procParts_0_emi78vuj01((*X60Qii_16));
            string_0_sysvq0asl X60Qii_17 = nimStrDup((*X60Qtmp_128.nameAtom_0).d_00.atom_0);
            NB8 X60Qx_1399 = mapHas_0_emi78vuj01(definedSyms_0, X60Qii_17);
            if ((!X60Qx_1399)){
              string_0_sysvq0asl X60Qtmp_129 = X60Qii_17;
              nimStrWasMoved((&X60Qii_17));
              add_0_Ig6072n_aow7lb5cq1((&definedSyms_0), X60Qtmp_129);}
            nimStrDestroy(X60Qii_17);
            eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qtmp_128));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_101));}
        else {
          break;}}}
    whileStmtLabel_15: ;}
  forStmtLabel_14: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_102 = toOpenArray_1_I1gbnw21_emi78vuj01(globals_1);
    NI32 X60Qlf_103 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1400 = len_6_I3x6mi_emi78vuj01(X60Qlf_102);
        if (X60Qlf_103 < X60Qx_1400){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_20 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_102, X60Qlf_103);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1401 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_20)).d_00.kids_0, 0);
            string_0_sysvq0asl X60Qii_21 = nimStrDup((*(*X60Qx_1401)).d_00.atom_0);
            NB8 X60Qx_1402 = mapHas_0_emi78vuj01(definedSyms_0, X60Qii_21);
            if ((!X60Qx_1402)){
              string_0_sysvq0asl X60Qtmp_130 = X60Qii_21;
              nimStrWasMoved((&X60Qii_21));
              add_0_Ig6072n_aow7lb5cq1((&definedSyms_0), X60Qtmp_130);}
            nimStrDestroy(X60Qii_21);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_103));}
        else {
          break;}}}
    whileStmtLabel_19: ;}
  forStmtLabel_18: ;
  seq_0_Isutro81_emi78vuj01 foreignProcs_0 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  seq_0_Isutro81_emi78vuj01 foreignGlobals_0 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  seq_0_Isutro81_emi78vuj01 foreignTypes_0 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 seenForeign_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 pending_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_104 = toOpenArray_1_I1gbnw21_emi78vuj01(procs_1);
    NI32 X60Qlf_105 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1403 = len_6_I3x6mi_emi78vuj01(X60Qlf_104);
        if (X60Qlf_105 < X60Qx_1403){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_24 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_104, X60Qlf_105);
            collectForeignAtoms_0_emi78vuj01((*X60Qii_24), (&pending_0));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_105));}
        else {
          break;}}}
    whileStmtLabel_23: ;}
  forStmtLabel_22: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_106 = toOpenArray_1_I1gbnw21_emi78vuj01(globals_1);
    NI32 X60Qlf_107 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1404 = len_6_I3x6mi_emi78vuj01(X60Qlf_106);
        if (X60Qlf_107 < X60Qx_1404){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_27 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_106, X60Qlf_107);
            collectForeignAtoms_0_emi78vuj01((*X60Qii_27), (&pending_0));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_107));}
        else {
          break;}}}
    whileStmtLabel_26: ;}
  forStmtLabel_25: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_108 = toOpenArray_1_I1gbnw21_emi78vuj01(types_2);
    NI32 X60Qlf_109 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1405 = len_6_I3x6mi_emi78vuj01(X60Qlf_108);
        if (X60Qlf_109 < X60Qx_1405){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_30 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_108, X60Qlf_109);
            collectForeignAtoms_0_emi78vuj01((*X60Qii_30), (&pending_0));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_109));}
        else {
          break;}}}
    whileStmtLabel_29: ;}
  forStmtLabel_28: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_110 = toOpenArray_1_I1gbnw21_emi78vuj01(topStmts_0);
    NI32 X60Qlf_111 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1406 = len_6_I3x6mi_emi78vuj01(X60Qlf_110);
        if (X60Qlf_111 < X60Qx_1406){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_33 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_110, X60Qlf_111);
            collectForeignAtoms_0_emi78vuj01((*X60Qii_33), (&pending_0));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_111));}
        else {
          break;}}}
    whileStmtLabel_32: ;}
  forStmtLabel_31: ;
  NI32 qi_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1407 = len_3_Ixq6taz_aow7lb5cq1(pending_0);
      if (qi_0 < X60Qx_1407){
        {
          string_0_sysvq0asl* X60Qx_1408 = getQ_7_Ir6d0tw_aow7lb5cq1(pending_0, qi_0);
          string_0_sysvq0asl atom_4 = nimStrDup((*X60Qx_1408));
          inc_1_I6wjjge_aow2h993l1((&qi_0));
          NB8 X60Qx_1409 = mapHas_0_emi78vuj01(seenForeign_0, atom_4);
          if (X60Qx_1409){
            nimStrDestroy(atom_4);
            goto continueLabel_35;}
          string_0_sysvq0asl X60Qx_1410 = nimStrDup(atom_4);
          add_0_Ig6072n_aow7lb5cq1((&seenForeign_0), X60Qx_1410);
          string_0_sysvq0asl m_0 = foreignModuleOf_0_emi78vuj01(atom_4);
          NI32 X60Qx_1411 = len_4_sysvq0asl(m_0);
          if (X60Qx_1411 == 0){
            nimStrDestroy(m_0);
            nimStrDestroy(atom_4);
            goto continueLabel_35;}
          loadSiblingModule_0_emi78vuj01(m_0);
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* pn_1 = modFindProc_0_emi78vuj01(atom_4);
          if ((!(pn_1 == NIM_NIL))){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1412 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pn_1);
            add_0_Iv4n2t31_emi78vuj01((&foreignProcs_0), X60Qx_1412);
            collectForeignAtoms_0_emi78vuj01(pn_1, (&pending_0));
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pn_1);
            nimStrDestroy(m_0);
            nimStrDestroy(atom_4);
            goto continueLabel_35;}
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* gn_0 = modFindGlobal_0_emi78vuj01(atom_4);
          if ((!(gn_0 == NIM_NIL))){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1413 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(gn_0);
            add_0_Iv4n2t31_emi78vuj01((&foreignGlobals_0), X60Qx_1413);
            collectForeignAtoms_0_emi78vuj01(gn_0, (&pending_0));
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(gn_0);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pn_1);
            nimStrDestroy(m_0);
            nimStrDestroy(atom_4);
            goto continueLabel_35;}
          X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* tn_0 = modFindType_0_emi78vuj01(atom_4);
          if ((!(tn_0 == NIM_NIL))){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1414 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(tn_0);
            add_0_Iv4n2t31_emi78vuj01((&foreignTypes_0), X60Qx_1414);
            collectForeignAtoms_0_emi78vuj01(tn_0, (&pending_0));
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(tn_0);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(gn_0);
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pn_1);
            nimStrDestroy(m_0);
            nimStrDestroy(atom_4);
            goto continueLabel_35;}
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(tn_0);
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(gn_0);
          eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(pn_1);
          nimStrDestroy(m_0);
          nimStrDestroy(atom_4);}
        continueLabel_35: ;}
      else {
        break;}}}
  whileStmtLabel_34: ;
  buildExternMaps_0_emi78vuj01(foreignProcs_0, foreignGlobals_0, foreignTypes_0);
  seq_0_Isutro81_emi78vuj01 allTypes_0 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_112 = toOpenArray_1_I1gbnw21_emi78vuj01(foreignTypes_0);
    NI32 X60Qlf_113 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1415 = len_6_I3x6mi_emi78vuj01(X60Qlf_112);
        if (X60Qlf_113 < X60Qx_1415){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_38 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_112, X60Qlf_113);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1416 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_38));
            add_0_Iv4n2t31_emi78vuj01((&allTypes_0), X60Qx_1416);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_113));}
        else {
          break;}}}
    whileStmtLabel_37: ;}
  forStmtLabel_36: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_114 = toOpenArray_1_I1gbnw21_emi78vuj01(types_2);
    NI32 X60Qlf_115 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1417 = len_6_I3x6mi_emi78vuj01(X60Qlf_114);
        if (X60Qlf_115 < X60Qx_1417){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_41 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_114, X60Qlf_115);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1418 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qii_41));
            add_0_Iv4n2t31_emi78vuj01((&allTypes_0), X60Qx_1418);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_115));}
        else {
          break;}}}
    whileStmtLabel_40: ;}
  forStmtLabel_39: ;
  seq_0_Ixdx2fh1_aow7lb5cq1 fwdDecls_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_116 = toOpenArray_1_I1gbnw21_emi78vuj01(allTypes_0);
    NI32 X60Qlf_117 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1419 = len_6_I3x6mi_emi78vuj01(X60Qlf_116);
        if (X60Qlf_117 < X60Qx_1419){
          {
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_45 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_116, X60Qlf_117);
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_46 = findTag_0_emi78vuj01((*X60Qii_45), (string_0_sysvq0asl){
                .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
              );
              X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01 X60QconstRefTemp_0 = (X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1420 = toOpenArray_0_Ig1w4is1_emi78vuj01((&X60QconstRefTemp_0));
              NB8 X60Qx_1421 = hasPragma_0_emi78vuj01(X60Qii_46, X60Qx_1420);
              if (X60Qx_1421){
                eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_46);
                goto continueLabel_44;}
              NI32 X60Qx_1422 = len_3_Il6imzw1_emi78vuj01((*(*X60Qii_45)).d_00.kids_0);
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1423 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_45)).d_00.kids_0, ((NI32)(X60Qx_1422 - 1)));
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qii_47 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*X60Qx_1423));
              NB8 X60Qx_1424;
              NB8 X60Qx_1425 = isList_0_emi78vuj01(X60Qii_47);
              if (X60Qx_1425){
                NB8 X60Qx_1426;
                NB8 X60Qx_1427 = eqQ_20_sysvq0asl((*X60Qii_47).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
                );
                if (X60Qx_1427){
                  X60Qx_1426 = NIM_TRUE;}
                else {
                  NB8 X60Qx_1428 = eqQ_20_sysvq0asl((*X60Qii_47).d_00.tag_0, (string_0_sysvq0asl){
                    .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I3302612697625453930_emi78vuj01)}
                  );
                  X60Qx_1426 = X60Qx_1428;}
                X60Qx_1424 = X60Qx_1426;}
              else {
                X60Qx_1424 = NIM_FALSE;}
              if (X60Qx_1424){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1429 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_45)).d_00.kids_0, 0);
                string_0_sysvq0asl X60Qii_48 = mangleToC_0_emi78vuj01((*(*X60Qx_1429)).d_00.atom_0);
                string_0_sysvq0asl X60Qx_25;
                nimStrWasMoved((&X60Qx_25));
                NB8 X60Qx_1430 = eqQ_20_sysvq0asl((*X60Qii_47).d_00.tag_0, (string_0_sysvq0asl){
                  .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I3302612697625453930_emi78vuj01)}
                );
                if (X60Qx_1430){
                  nimStrDestroy(X60Qx_25);
                  X60Qx_25 = (string_0_sysvq0asl){
                    .bytes_0 = 1768846846u, .more_0 = (&strlit_0_I2177770586444330071_emi78vuj01)}
                  ;}
                else {
                  nimStrDestroy(X60Qx_25);
                  X60Qx_25 = (string_0_sysvq0asl){
                    .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I15036689029481705243_emi78vuj01)}
                  ;}
                string_0_sysvq0asl X60Qii_49 = X60Qx_25;
                nimStrWasMoved((&X60Qx_25));
                NI32 X60Qx_1431 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
                );
                NI32 X60Qx_1432 = len_4_sysvq0asl(X60Qii_49);
                NI32 X60Qx_1433 = len_4_sysvq0asl(X60Qii_48);
                NI32 X60Qx_1434 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 8193u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_1435 = len_4_sysvq0asl(X60Qii_48);
                NI32 X60Qx_1436 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_137 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1431 + X60Qx_1432)) + X60Qx_1433)) + X60Qx_1434)) + X60Qx_1435)) + X60Qx_1436)));
                add_2_sysvq0asl((&X60Qdesugar_137), (string_0_sysvq0asl){
                  .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3038304834379229130_emi78vuj01)}
                );
                add_2_sysvq0asl((&X60Qdesugar_137), X60Qii_49);
                add_2_sysvq0asl((&X60Qdesugar_137), X60Qii_48);
                add_2_sysvq0asl((&X60Qdesugar_137), (string_0_sysvq0asl){
                  .bytes_0 = 8193u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_137), X60Qii_48);
                add_2_sysvq0asl((&X60Qdesugar_137), (string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qtmp_131 = X60Qdesugar_137;
                nimStrWasMoved((&X60Qdesugar_137));
                add_0_Ig6072n_aow7lb5cq1((&fwdDecls_0), X60Qtmp_131);
                nimStrDestroy(X60Qdesugar_137);
                nimStrDestroy(X60Qii_49);
                nimStrDestroy(X60Qx_25);
                nimStrDestroy(X60Qii_48);}
              eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_47);
              eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qii_46);}
            continueLabel_44: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_117));}
        else {
          break;}}}
    whileStmtLabel_43: ;}
  forStmtLabel_42: ;
  seq_0_Ixdx2fh1_aow7lb5cq1 typeDecls_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Isutro81_emi78vuj01 ordered_0 = orderTypesByValueDeps_0_emi78vuj01(allTypes_0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_118 = toOpenArray_1_I1gbnw21_emi78vuj01(ordered_0);
    NI32 X60Qlf_119 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1437 = len_6_I3x6mi_emi78vuj01(X60Qlf_118);
        if (X60Qlf_119 < X60Qx_1437){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_52 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_118, X60Qlf_119);
            string_0_sysvq0asl X60Qii_53 = genTypeDecl_1_emi78vuj01((*X60Qii_52));
            NI32 X60Qx_1438 = len_4_sysvq0asl(X60Qii_53);
            if (0 < X60Qx_1438){
              string_0_sysvq0asl X60Qtmp_132 = X60Qii_53;
              nimStrWasMoved((&X60Qii_53));
              add_0_Ig6072n_aow7lb5cq1((&typeDecls_0), X60Qtmp_132);}
            nimStrDestroy(X60Qii_53);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_119));}
        else {
          break;}}}
    whileStmtLabel_51: ;}
  forStmtLabel_50: ;
  seq_0_Ixdx2fh1_aow7lb5cq1 protos_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 defs_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 provisionsNeeded_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_120 = toOpenArray_1_I1gbnw21_emi78vuj01(procs_1);
    NI32 X60Qlf_121 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1439 = len_6_I3x6mi_emi78vuj01(X60Qlf_120);
        if (X60Qlf_121 < X60Qx_1439){
          {
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_57 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_120, X60Qlf_121);
              ProcParts_0_emi78vuj01 X60Qii_58 = procParts_0_emi78vuj01((*X60Qii_57));
              X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 X60QconstRefTemp_1 = (X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1440 = toOpenArray_0_Il5czcd1_emi78vuj01((&X60QconstRefTemp_1));
              NB8 X60Qx_1441 = hasPragma_0_emi78vuj01(X60Qii_58.pragmas_0, X60Qx_1440);
              if (X60Qx_1441){
                eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_58));
                goto continueLabel_56;}
              X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 X60QconstRefTemp_2 = (X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1442 = toOpenArray_0_Il5czcd1_emi78vuj01((&X60QconstRefTemp_2));
              NB8 X60Qx_1443 = hasPragma_0_emi78vuj01(X60Qii_58.pragmas_0, X60Qx_1442);
              if (X60Qx_1443){
                string_0_sysvq0asl X60Qii_59 = externName_0_emi78vuj01(X60Qii_58.pragmas_0);
                NI32 X60Qx_1444 = len_4_sysvq0asl(X60Qii_59);
                if (X60Qx_1444 == 0){
                  nimStrDestroy(X60Qii_59);
                  string_0_sysvq0asl X60Qx_1445 = beforeDot_0_emi78vuj01((*X60Qii_58.nameAtom_0).d_00.atom_0);
                  X60Qii_59 = X60Qx_1445;}
                NB8 X60Qx_1446;
                NB8 X60Qx_1447;
                NI32 X60Qx_1448 = len_4_sysvq0asl(X60Qii_59);
                if (2 <= X60Qx_1448){
                  NC8 X60Qx_1449 = getQ_9_sysvq0asl(X60Qii_59, 0);
                  X60Qx_1447 = (X60Qx_1449 == (NC8)'_');}
                else {
                  X60Qx_1447 = NIM_FALSE;}
                if (X60Qx_1447){
                  NC8 X60Qx_1450 = getQ_9_sysvq0asl(X60Qii_59, 1);
                  X60Qx_1446 = (X60Qx_1450 == (NC8)'_');}
                else {
                  X60Qx_1446 = NIM_FALSE;}
                if (X60Qx_1446){
                  nimStrDestroy(X60Qii_59);
                  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_58));
                  goto continueLabel_56;}
                NB8 X60Qx_1451 = isProvision_0_emi78vuj01(X60Qii_59);
                if (X60Qx_1451){
                  NB8 X60Qx_1452 = mapHas_0_emi78vuj01(provisionsNeeded_0, X60Qii_59);
                  if ((!X60Qx_1452)){
                    string_0_sysvq0asl X60Qtmp_133 = X60Qii_59;
                    nimStrWasMoved((&X60Qii_59));
                    add_0_Ig6072n_aow7lb5cq1((&provisionsNeeded_0), X60Qtmp_133);}
                  nimStrDestroy(X60Qii_59);
                  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_58));
                  goto continueLabel_56;}
                string_0_sysvq0asl X60Qtmp_134 = procSignature_1_emi78vuj01((*X60Qii_57));
                string_0_sysvq0asl X60Qx_1453 = ampQ_0_sysvq0asl(X60Qtmp_134, (string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                add_0_Ig6072n_aow7lb5cq1((&protos_0), X60Qx_1453);
                nimStrDestroy(X60Qtmp_134);
                nimStrDestroy(X60Qii_59);
                eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_58));
                goto continueLabel_56;
                nimStrDestroy(X60Qtmp_134);
                nimStrDestroy(X60Qii_59);}
              string_0_sysvq0asl X60Qii_60 = procSignature_1_emi78vuj01((*X60Qii_57));
              if (X60Qii_58.body_0 == NIM_NIL){
                string_0_sysvq0asl X60Qx_1454 = ampQ_0_sysvq0asl(X60Qii_60, (string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                add_0_Ig6072n_aow7lb5cq1((&protos_0), X60Qx_1454);
                nimStrDestroy(X60Qii_60);
                eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_58));
                goto continueLabel_56;}
              string_0_sysvq0asl X60Qx_1455 = ampQ_0_sysvq0asl(X60Qii_60, (string_0_sysvq0asl){
                .bytes_0 = 15105u, .more_0 = NIM_NIL}
              );
              add_0_Ig6072n_aow7lb5cq1((&protos_0), X60Qx_1455);
              string_0_sysvq0asl X60Qx_1456 = genProc_0_emi78vuj01((*X60Qii_57));
              add_0_Ig6072n_aow7lb5cq1((&defs_0), X60Qx_1456);
              nimStrDestroy(X60Qii_60);
              eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_58));}
            continueLabel_56: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_121));}
        else {
          break;}}}
    whileStmtLabel_55: ;}
  forStmtLabel_54: ;
  seq_0_Ixdx2fh1_aow7lb5cq1 stubs_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 foreignDefs_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_122 = toOpenArray_1_I1gbnw21_emi78vuj01(foreignProcs_0);
    NI32 X60Qlf_123 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1457 = len_6_I3x6mi_emi78vuj01(X60Qlf_122);
        if (X60Qlf_123 < X60Qx_1457){
          {
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_64 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_122, X60Qlf_123);
              ProcParts_0_emi78vuj01 X60Qii_65 = procParts_0_emi78vuj01((*X60Qii_64));
              X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 X60QconstRefTemp_3 = (X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1458 = toOpenArray_0_Il5czcd1_emi78vuj01((&X60QconstRefTemp_3));
              NB8 X60Qx_1459 = hasPragma_0_emi78vuj01(X60Qii_65.pragmas_0, X60Qx_1458);
              if (X60Qx_1459){
                eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_65));
                goto continueLabel_63;}
              X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 X60QconstRefTemp_4 = (X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1460 = toOpenArray_0_Il5czcd1_emi78vuj01((&X60QconstRefTemp_4));
              NB8 X60Qx_1461 = hasPragma_0_emi78vuj01(X60Qii_65.pragmas_0, X60Qx_1460);
              if (X60Qx_1461){
                string_0_sysvq0asl X60Qii_66 = externName_0_emi78vuj01(X60Qii_65.pragmas_0);
                NI32 X60Qx_1462 = len_4_sysvq0asl(X60Qii_66);
                if (X60Qx_1462 == 0){
                  nimStrDestroy(X60Qii_66);
                  string_0_sysvq0asl X60Qx_1463 = beforeDot_0_emi78vuj01((*X60Qii_65.nameAtom_0).d_00.atom_0);
                  X60Qii_66 = X60Qx_1463;}
                NB8 X60Qx_1464;
                NB8 X60Qx_1465;
                NI32 X60Qx_1466 = len_4_sysvq0asl(X60Qii_66);
                if (2 <= X60Qx_1466){
                  NC8 X60Qx_1467 = getQ_9_sysvq0asl(X60Qii_66, 0);
                  X60Qx_1465 = (X60Qx_1467 == (NC8)'_');}
                else {
                  X60Qx_1465 = NIM_FALSE;}
                if (X60Qx_1465){
                  NC8 X60Qx_1468 = getQ_9_sysvq0asl(X60Qii_66, 1);
                  X60Qx_1464 = (X60Qx_1468 == (NC8)'_');}
                else {
                  X60Qx_1464 = NIM_FALSE;}
                if (X60Qx_1464){
                  nimStrDestroy(X60Qii_66);
                  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_65));
                  goto continueLabel_63;}
                NB8 X60Qx_1469 = isProvision_0_emi78vuj01(X60Qii_66);
                if (X60Qx_1469){
                  NB8 X60Qx_1470 = mapHas_0_emi78vuj01(provisionsNeeded_0, X60Qii_66);
                  if ((!X60Qx_1470)){
                    string_0_sysvq0asl X60Qtmp_135 = X60Qii_66;
                    nimStrWasMoved((&X60Qii_66));
                    add_0_Ig6072n_aow7lb5cq1((&provisionsNeeded_0), X60Qtmp_135);}
                  nimStrDestroy(X60Qii_66);
                  eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_65));
                  goto continueLabel_63;}
                string_0_sysvq0asl X60Qtmp_136 = procSignature_1_emi78vuj01((*X60Qii_64));
                string_0_sysvq0asl X60Qx_1471 = ampQ_0_sysvq0asl(X60Qtmp_136, (string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                add_0_Ig6072n_aow7lb5cq1((&stubs_0), X60Qx_1471);
                nimStrDestroy(X60Qtmp_136);
                nimStrDestroy(X60Qii_66);
                eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_65));
                goto continueLabel_63;
                nimStrDestroy(X60Qtmp_136);
                nimStrDestroy(X60Qii_66);}
              NB8 X60Qx_1472;
              X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01 X60QconstRefTemp_5 = (X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1819175422u, .more_0 = (&strlit_0_I11734088361827745870_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1473 = toOpenArray_0_If2frt3_emi78vuj01((&X60QconstRefTemp_5));
              NB8 X60Qx_1474 = hasPragma_0_emi78vuj01(X60Qii_65.pragmas_0, X60Qx_1473);
              if (X60Qx_1474){
                X60Qx_1472 = (!(X60Qii_65.body_0 == NIM_NIL));}
              else {
                X60Qx_1472 = NIM_FALSE;}
              if (X60Qx_1472){
                string_0_sysvq0asl X60Qtmp_137 = procSignature_1_emi78vuj01((*X60Qii_64));
                string_0_sysvq0asl X60Qx_1475 = ampQ_0_sysvq0asl(X60Qtmp_137, (string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                add_0_Ig6072n_aow7lb5cq1((&stubs_0), X60Qx_1475);
                string_0_sysvq0asl X60Qx_1476 = genProc_0_emi78vuj01((*X60Qii_64));
                add_0_Ig6072n_aow7lb5cq1((&foreignDefs_0), X60Qx_1476);
                nimStrDestroy(X60Qtmp_137);
                eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_65));
                goto continueLabel_63;
                nimStrDestroy(X60Qtmp_137);}
              string_0_sysvq0asl X60Qdesugar_138 = procSignature_1_emi78vuj01((*X60Qii_64));
              NI32 X60Qx_1477 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I11931072057670428036_emi78vuj01)}
              );
              NI32 X60Qx_1478 = len_4_sysvq0asl(X60Qdesugar_138);
              NI32 X60Qx_1479 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 15105u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_139 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1477 + X60Qx_1478)) + X60Qx_1479)));
              add_2_sysvq0asl((&X60Qdesugar_139), (string_0_sysvq0asl){
                .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I11931072057670428036_emi78vuj01)}
              );
              add_2_sysvq0asl((&X60Qdesugar_139), X60Qdesugar_138);
              add_2_sysvq0asl((&X60Qdesugar_139), (string_0_sysvq0asl){
                .bytes_0 = 15105u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qtmp_138 = X60Qdesugar_139;
              nimStrWasMoved((&X60Qdesugar_139));
              add_0_Ig6072n_aow7lb5cq1((&stubs_0), X60Qtmp_138);
              nimStrDestroy(X60Qdesugar_139);
              nimStrDestroy(X60Qdesugar_138);
              eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qii_65));}
            continueLabel_63: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_123));}
        else {
          break;}}}
    whileStmtLabel_62: ;}
  forStmtLabel_61: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_124 = toOpenArray_1_I1gbnw21_emi78vuj01(foreignGlobals_0);
    NI32 X60Qlf_125 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1480 = len_6_I3x6mi_emi78vuj01(X60Qlf_124);
        if (X60Qlf_125 < X60Qx_1480){
          {
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_70 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_124, X60Qlf_125);
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1481 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_70)).d_00.kids_0, 1);
              X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 X60QconstRefTemp_6 = (X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1482 = toOpenArray_0_Il5czcd1_emi78vuj01((&X60QconstRefTemp_6));
              NB8 X60Qx_1483 = hasPragma_0_emi78vuj01((*X60Qx_1481), X60Qx_1482);
              if (X60Qx_1483){
                goto continueLabel_69;}
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1484 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_70)).d_00.kids_0, 1);
              X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 X60QconstRefTemp_7 = (X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1485 = toOpenArray_0_Il5czcd1_emi78vuj01((&X60QconstRefTemp_7));
              NB8 X60Qx_1486 = hasPragma_0_emi78vuj01((*X60Qx_1484), X60Qx_1485);
              if (X60Qx_1486){
                goto continueLabel_69;}
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1487 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_70)).d_00.kids_0, 0);
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1488 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_70)).d_00.kids_0, 1);
              string_0_sysvq0asl X60Qii_71 = declName_0_emi78vuj01((*(*X60Qx_1487)).d_00.atom_0, (*X60Qx_1488));
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1489 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_70)).d_00.kids_0, 2);
              string_0_sysvq0asl X60Qdesugar_140 = declare_1_emi78vuj01((*X60Qx_1489), X60Qii_71);
              NI32 X60Qx_1490 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I11931072057670428036_emi78vuj01)}
              );
              NI32 X60Qx_1491 = len_4_sysvq0asl(X60Qdesugar_140);
              NI32 X60Qx_1492 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 15105u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_141 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1490 + X60Qx_1491)) + X60Qx_1492)));
              add_2_sysvq0asl((&X60Qdesugar_141), (string_0_sysvq0asl){
                .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I11931072057670428036_emi78vuj01)}
              );
              add_2_sysvq0asl((&X60Qdesugar_141), X60Qdesugar_140);
              add_2_sysvq0asl((&X60Qdesugar_141), (string_0_sysvq0asl){
                .bytes_0 = 15105u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qtmp_139 = X60Qdesugar_141;
              nimStrWasMoved((&X60Qdesugar_141));
              add_0_Ig6072n_aow7lb5cq1((&stubs_0), X60Qtmp_139);
              nimStrDestroy(X60Qdesugar_141);
              nimStrDestroy(X60Qdesugar_140);
              nimStrDestroy(X60Qii_71);}
            continueLabel_69: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_125));}
        else {
          break;}}}
    whileStmtLabel_68: ;}
  forStmtLabel_67: ;
  seq_0_Ixdx2fh1_aow7lb5cq1 data_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 inits_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_126 = toOpenArray_1_I1gbnw21_emi78vuj01(globals_1);
    NI32 X60Qlf_127 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1493 = len_6_I3x6mi_emi78vuj01(X60Qlf_126);
        if (X60Qlf_127 < X60Qx_1493){
          {
            {
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_75 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_126, X60Qlf_127);
              NB8 X60Qx_1494;
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1495 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_75)).d_00.kids_0, 1);
              X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 X60QconstRefTemp_8 = (X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1496 = toOpenArray_0_Il5czcd1_emi78vuj01((&X60QconstRefTemp_8));
              NB8 X60Qx_1497 = hasPragma_0_emi78vuj01((*X60Qx_1495), X60Qx_1496);
              if (X60Qx_1497){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1498 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_75)).d_00.kids_0, 1);
                X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 X60QconstRefTemp_9 = (X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
                  .a = {
                    (string_0_sysvq0asl){
                      .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}}}
                ;
                openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1499 = toOpenArray_0_Il5czcd1_emi78vuj01((&X60QconstRefTemp_9));
                NB8 X60Qx_1500 = hasPragma_0_emi78vuj01((*X60Qx_1498), X60Qx_1499);
                X60Qx_1494 = (!X60Qx_1500);}
              else {
                X60Qx_1494 = NIM_FALSE;}
              if (X60Qx_1494){
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1501 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_75)).d_00.kids_0, 0);
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1502 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_75)).d_00.kids_0, 1);
                string_0_sysvq0asl X60Qtmp_140 = declName_0_emi78vuj01((*(*X60Qx_1501)).d_00.atom_0, (*X60Qx_1502));
                X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1503 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_75)).d_00.kids_0, 2);
                string_0_sysvq0asl X60Qdesugar_142 = declare_1_emi78vuj01((*X60Qx_1503), X60Qtmp_140);
                NI32 X60Qx_1504 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I11931072057670428036_emi78vuj01)}
                );
                NI32 X60Qx_1505 = len_4_sysvq0asl(X60Qdesugar_142);
                NI32 X60Qx_1506 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_143 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1504 + X60Qx_1505)) + X60Qx_1506)));
                add_2_sysvq0asl((&X60Qdesugar_143), (string_0_sysvq0asl){
                  .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I11931072057670428036_emi78vuj01)}
                );
                add_2_sysvq0asl((&X60Qdesugar_143), X60Qdesugar_142);
                add_2_sysvq0asl((&X60Qdesugar_143), (string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qtmp_141 = X60Qdesugar_143;
                nimStrWasMoved((&X60Qdesugar_143));
                add_0_Ig6072n_aow7lb5cq1((&stubs_0), X60Qtmp_141);
                nimStrDestroy(X60Qdesugar_143);
                nimStrDestroy(X60Qdesugar_142);
                nimStrDestroy(X60Qtmp_140);
                goto continueLabel_74;
                nimStrDestroy(X60Qdesugar_143);
                nimStrDestroy(X60Qdesugar_142);
                nimStrDestroy(X60Qtmp_140);}
              X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1507 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_75)).d_00.kids_0, 1);
              X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01 X60QconstRefTemp_10 = (X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01){
                .a = {
                  (string_0_sysvq0asl){
                    .bytes_0 = 1685024510u, .more_0 = (&strlit_0_I9354196862430236195_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I3957309170640276402_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I6761535509221812916_emi78vuj01)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 1634035966u, .more_0 = (&strlit_0_I2341417231474813780_emi78vuj01)}}}
              ;
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_1508 = toOpenArray_0_Ig1w4is1_emi78vuj01((&X60QconstRefTemp_10));
              NB8 X60Qx_1509 = hasPragma_0_emi78vuj01((*X60Qx_1507), X60Qx_1508);
              if (X60Qx_1509){
                goto continueLabel_74;}
              GlobalInfo_0_emi78vuj01 X60Qii_76 = genGlobal_0_emi78vuj01((*X60Qii_75));
              string_0_sysvq0asl X60Qtmp_142 = X60Qii_76.decl_0;
              nimStrWasMoved((&X60Qii_76.decl_0));
              add_0_Ig6072n_aow7lb5cq1((&data_0), X60Qtmp_142);
              if (X60Qii_76.needsInit_0){
                string_0_sysvq0asl X60Qdesugar_144 = symName_0_emi78vuj01(X60Qii_76.nameAtom_0);
                string_0_sysvq0asl X60Qdesugar_145 = genExpr_1_emi78vuj01(X60Qii_76.value_0);
                NI32 X60Qx_1510 = len_4_sysvq0asl(X60Qdesugar_144);
                NI32 X60Qx_1511 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 540876803u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_1512 = len_4_sysvq0asl(X60Qdesugar_145);
                NI32 X60Qx_1513 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_146 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1510 + X60Qx_1511)) + X60Qx_1512)) + X60Qx_1513)));
                add_2_sysvq0asl((&X60Qdesugar_146), X60Qdesugar_144);
                add_2_sysvq0asl((&X60Qdesugar_146), (string_0_sysvq0asl){
                  .bytes_0 = 540876803u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_146), X60Qdesugar_145);
                add_2_sysvq0asl((&X60Qdesugar_146), (string_0_sysvq0asl){
                  .bytes_0 = 15105u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qtmp_143 = X60Qdesugar_146;
                nimStrWasMoved((&X60Qdesugar_146));
                add_0_Ig6072n_aow7lb5cq1((&inits_0), X60Qtmp_143);
                nimStrDestroy(X60Qdesugar_146);
                nimStrDestroy(X60Qdesugar_145);
                nimStrDestroy(X60Qdesugar_144);}
              eQdestroyQ_SX47lobalX49nfo0emi78vuj01_0_emi78vuj01((&X60Qii_76));}
            continueLabel_74: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_127));}
        else {
          break;}}}
    whileStmtLabel_73: ;}
  forStmtLabel_72: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_128 = toOpenArray_1_I1gbnw21_emi78vuj01(topStmts_0);
    NI32 X60Qlf_129 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1514 = len_6_I3x6mi_emi78vuj01(X60Qlf_128);
        if (X60Qlf_129 < X60Qx_1514){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_79 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_128, X60Qlf_129);
            string_0_sysvq0asl X60Qii_80 = genStmt_1_emi78vuj01((*X60Qii_79));
            NI32 X60Qx_1515 = len_4_sysvq0asl(X60Qii_80);
            if (0 < X60Qx_1515){
              string_0_sysvq0asl X60Qtmp_144 = X60Qii_80;
              nimStrWasMoved((&X60Qii_80));
              add_0_Ig6072n_aow7lb5cq1((&inits_0), X60Qtmp_144);}
            nimStrDestroy(X60Qii_80);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_129));}
        else {
          break;}}}
    whileStmtLabel_78: ;}
  forStmtLabel_77: ;
  seq_0_Ixdx2fh1_aow7lb5cq1 headers_1 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_130 = toOpenArray_1_I1gbnw21_emi78vuj01(procs_1);
    NI32 X60Qlf_131 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1516 = len_6_I3x6mi_emi78vuj01(X60Qlf_130);
        if (X60Qlf_131 < X60Qx_1516){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_83 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_130, X60Qlf_131);
            ProcParts_0_emi78vuj01 X60Qtmp_145 = procParts_0_emi78vuj01((*X60Qii_83));
            addHeaders_0_emi78vuj01(X60Qtmp_145.pragmas_0, (&headers_1));
            eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qtmp_145));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_131));}
        else {
          break;}}}
    whileStmtLabel_82: ;}
  forStmtLabel_81: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_132 = toOpenArray_1_I1gbnw21_emi78vuj01(globals_1);
    NI32 X60Qlf_133 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1517 = len_6_I3x6mi_emi78vuj01(X60Qlf_132);
        if (X60Qlf_133 < X60Qx_1517){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_86 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_132, X60Qlf_133);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1518 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_86)).d_00.kids_0, 1);
            addHeaders_0_emi78vuj01((*X60Qx_1518), (&headers_1));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_133));}
        else {
          break;}}}
    whileStmtLabel_85: ;}
  forStmtLabel_84: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_134 = toOpenArray_1_I1gbnw21_emi78vuj01(types_2);
    NI32 X60Qlf_135 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1519 = len_6_I3x6mi_emi78vuj01(X60Qlf_134);
        if (X60Qlf_135 < X60Qx_1519){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_89 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_134, X60Qlf_135);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_146 = findTag_0_emi78vuj01((*X60Qii_89), (string_0_sysvq0asl){
              .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
            );
            addHeaders_0_emi78vuj01(X60Qtmp_146, (&headers_1));
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qtmp_146);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_135));}
        else {
          break;}}}
    whileStmtLabel_88: ;}
  forStmtLabel_87: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_136 = toOpenArray_1_I1gbnw21_emi78vuj01(foreignProcs_0);
    NI32 X60Qlf_137 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1520 = len_6_I3x6mi_emi78vuj01(X60Qlf_136);
        if (X60Qlf_137 < X60Qx_1520){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_92 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_136, X60Qlf_137);
            ProcParts_0_emi78vuj01 X60Qtmp_147 = procParts_0_emi78vuj01((*X60Qii_92));
            addHeaders_0_emi78vuj01(X60Qtmp_147.pragmas_0, (&headers_1));
            eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01((&X60Qtmp_147));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_137));}
        else {
          break;}}}
    whileStmtLabel_91: ;}
  forStmtLabel_90: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_138 = toOpenArray_1_I1gbnw21_emi78vuj01(foreignGlobals_0);
    NI32 X60Qlf_139 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1521 = len_6_I3x6mi_emi78vuj01(X60Qlf_138);
        if (X60Qlf_139 < X60Qx_1521){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_95 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_138, X60Qlf_139);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1522 = getQ_7_Iheb436_emi78vuj01((*(*X60Qii_95)).d_00.kids_0, 1);
            addHeaders_0_emi78vuj01((*X60Qx_1522), (&headers_1));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_139));}
        else {
          break;}}}
    whileStmtLabel_94: ;}
  forStmtLabel_93: ;
  {
    openArray_0_Ip5n4zi1_emi78vuj01 X60Qlf_140 = toOpenArray_1_I1gbnw21_emi78vuj01(foreignTypes_0);
    NI32 X60Qlf_141 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1523 = len_6_I3x6mi_emi78vuj01(X60Qlf_140);
        if (X60Qlf_141 < X60Qx_1523){
          {
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qii_98 = getQ_10_Ipbnh891_emi78vuj01(X60Qlf_140, X60Qlf_141);
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_148 = findTag_0_emi78vuj01((*X60Qii_98), (string_0_sysvq0asl){
              .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_emi78vuj01)}
            );
            addHeaders_0_emi78vuj01(X60Qtmp_148, (&headers_1));
            eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qtmp_148);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_141));}
        else {
          break;}}}
    whileStmtLabel_97: ;}
  forStmtLabel_96: ;
  seq_0_Ixdx2fh1_aow7lb5cq1 provisions_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_142 = toOpenArray_1_I6b60gk1_aow7lb5cq1(provisionsNeeded_0);
    NI32 X60Qlf_143 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1524 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_142);
        if (X60Qlf_143 < X60Qx_1524){
          {
            string_0_sysvq0asl* X60Qii_101 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_142, X60Qlf_143);
            string_0_sysvq0asl X60Qii_102 = provisionNeeds_0_emi78vuj01((*X60Qii_101));
            NB8 X60Qx_1525;
            NI32 X60Qx_1526 = len_4_sysvq0asl(X60Qii_102);
            if (0 < X60Qx_1526){
              NB8 X60Qx_1527 = mapHas_0_emi78vuj01(headers_1, X60Qii_102);
              X60Qx_1525 = (!X60Qx_1527);}
            else {
              X60Qx_1525 = NIM_FALSE;}
            if (X60Qx_1525){
              string_0_sysvq0asl X60Qtmp_149 = X60Qii_102;
              nimStrWasMoved((&X60Qii_102));
              add_0_Ig6072n_aow7lb5cq1((&headers_1), X60Qtmp_149);}
            string_0_sysvq0asl X60Qx_1528 = provisionImpl_0_emi78vuj01((*X60Qii_101));
            add_0_Ig6072n_aow7lb5cq1((&provisions_0), X60Qx_1528);
            nimStrDestroy(X60Qii_102);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_143));}
        else {
          break;}}}
    whileStmtLabel_100: ;}
  forStmtLabel_99: ;
  string_0_sysvq0asl outp_8 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (0 < headers_1.len_0){
    seq_0_Ixdx2fh1_aow7lb5cq1 hs_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    {
      openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_144 = toOpenArray_1_I6b60gk1_aow7lb5cq1(headers_1);
      NI32 X60Qlf_145 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1529 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_144);
          if (X60Qlf_145 < X60Qx_1529){
            {
              string_0_sysvq0asl* X60Qii_105 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_144, X60Qlf_145);
              NB8 X60Qx_1530;
              NI32 X60Qx_1531 = len_4_sysvq0asl((*X60Qii_105));
              if (0 < X60Qx_1531){
                NC8 X60Qx_1532 = getQ_9_sysvq0asl((*X60Qii_105), 0);
                X60Qx_1530 = (X60Qx_1532 == (NC8)'<');}
              else {
                X60Qx_1530 = NIM_FALSE;}
              if (X60Qx_1530){
                string_0_sysvq0asl X60Qx_1533 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1852384254u, .more_0 = (&strlit_0_I4048856184218363000_emi78vuj01)}
                , (*X60Qii_105));
                add_0_Ig6072n_aow7lb5cq1((&hs_0), X60Qx_1533);}
              else {
                string_0_sysvq0asl X60Qdesugar_147 = nimStrDup((*X60Qii_105));
                NI32 X60Qx_1534 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1852384254u, .more_0 = (&strlit_0_I13990146375209994849_emi78vuj01)}
                );
                NI32 X60Qx_1535 = len_4_sysvq0asl(X60Qdesugar_147);
                NI32 X60Qx_1536 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 8705u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_148 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1534 + X60Qx_1535)) + X60Qx_1536)));
                add_2_sysvq0asl((&X60Qdesugar_148), (string_0_sysvq0asl){
                  .bytes_0 = 1852384254u, .more_0 = (&strlit_0_I13990146375209994849_emi78vuj01)}
                );
                add_2_sysvq0asl((&X60Qdesugar_148), X60Qdesugar_147);
                add_2_sysvq0asl((&X60Qdesugar_148), (string_0_sysvq0asl){
                  .bytes_0 = 8705u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qtmp_150 = X60Qdesugar_148;
                nimStrWasMoved((&X60Qdesugar_148));
                add_0_Ig6072n_aow7lb5cq1((&hs_0), X60Qtmp_150);
                nimStrDestroy(X60Qdesugar_148);
                nimStrDestroy(X60Qdesugar_147);}}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_145));}
          else {
            break;}}}
      whileStmtLabel_104: ;}
    forStmtLabel_103: ;
    string_0_sysvq0asl X60Qdesugar_149 = joinSeq_0_emi78vuj01(hs_0, (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1537 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I8452133558184175204_emi78vuj01)}
    );
    NI32 X60Qx_1538 = len_4_sysvq0asl(X60Qdesugar_149);
    NI32 X60Qx_1539 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_150 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1537 + X60Qx_1538)) + X60Qx_1539)));
    add_2_sysvq0asl((&X60Qdesugar_150), (string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I8452133558184175204_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_150), X60Qdesugar_149);
    add_2_sysvq0asl((&X60Qdesugar_150), (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_150);
    nimStrDestroy(X60Qdesugar_150);
    nimStrDestroy(X60Qdesugar_149);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(hs_0);}
  add_2_sysvq0asl((&outp_8), (string_0_sysvq0asl){
    .bytes_0 = 539635710u, .more_0 = (&strlit_0_I16941684571302003708_emi78vuj01)}
  );
  if (0 < fwdDecls_0.len_0){
    string_0_sysvq0asl X60Qdesugar_151 = joinSeq_0_emi78vuj01(fwdDecls_0, (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1540 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I8169018483846267631_emi78vuj01)}
    );
    NI32 X60Qx_1541 = len_4_sysvq0asl(X60Qdesugar_151);
    NI32 X60Qx_1542 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_152 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1540 + X60Qx_1541)) + X60Qx_1542)));
    add_2_sysvq0asl((&X60Qdesugar_152), (string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I8169018483846267631_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_152), X60Qdesugar_151);
    add_2_sysvq0asl((&X60Qdesugar_152), (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_152);
    nimStrDestroy(X60Qdesugar_152);
    nimStrDestroy(X60Qdesugar_151);}
  if (0 < typeDecls_0.len_0){
    string_0_sysvq0asl X60Qdesugar_153 = joinSeq_0_emi78vuj01(typeDecls_0, (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1543 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I4864334026181876568_emi78vuj01)}
    );
    NI32 X60Qx_1544 = len_4_sysvq0asl(X60Qdesugar_153);
    NI32 X60Qx_1545 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_154 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1543 + X60Qx_1544)) + X60Qx_1545)));
    add_2_sysvq0asl((&X60Qdesugar_154), (string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I4864334026181876568_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_154), X60Qdesugar_153);
    add_2_sysvq0asl((&X60Qdesugar_154), (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_154);
    nimStrDestroy(X60Qdesugar_154);
    nimStrDestroy(X60Qdesugar_153);}
  if (0 < protos_0.len_0){
    string_0_sysvq0asl X60Qdesugar_155 = joinSeq_0_emi78vuj01(protos_0, (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1546 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I3869532025073152017_emi78vuj01)}
    );
    NI32 X60Qx_1547 = len_4_sysvq0asl(X60Qdesugar_155);
    NI32 X60Qx_1548 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_156 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1546 + X60Qx_1547)) + X60Qx_1548)));
    add_2_sysvq0asl((&X60Qdesugar_156), (string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I3869532025073152017_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_156), X60Qdesugar_155);
    add_2_sysvq0asl((&X60Qdesugar_156), (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_156);
    nimStrDestroy(X60Qdesugar_156);
    nimStrDestroy(X60Qdesugar_155);}
  if (0 < stubs_0.len_0){
    string_0_sysvq0asl X60Qdesugar_157 = joinSeq_0_emi78vuj01(stubs_0, (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1549 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I10565976826139702769_emi78vuj01)}
    );
    NI32 X60Qx_1550 = len_4_sysvq0asl(X60Qdesugar_157);
    NI32 X60Qx_1551 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_158 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1549 + X60Qx_1550)) + X60Qx_1551)));
    add_2_sysvq0asl((&X60Qdesugar_158), (string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I10565976826139702769_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_158), X60Qdesugar_157);
    add_2_sysvq0asl((&X60Qdesugar_158), (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_158);
    nimStrDestroy(X60Qdesugar_158);
    nimStrDestroy(X60Qdesugar_157);}
  if (0 < provisions_0.len_0){
    string_0_sysvq0asl X60Qdesugar_159 = joinSeq_0_emi78vuj01(provisions_0, (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1552 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I4664920264571878627_emi78vuj01)}
    );
    NI32 X60Qx_1553 = len_4_sysvq0asl(X60Qdesugar_159);
    NI32 X60Qx_1554 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_160 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1552 + X60Qx_1553)) + X60Qx_1554)));
    add_2_sysvq0asl((&X60Qdesugar_160), (string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I4664920264571878627_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_160), X60Qdesugar_159);
    add_2_sysvq0asl((&X60Qdesugar_160), (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_160);
    nimStrDestroy(X60Qdesugar_160);
    nimStrDestroy(X60Qdesugar_159);}
  if (0 < data_0.len_0){
    string_0_sysvq0asl X60Qdesugar_161 = joinSeq_0_emi78vuj01(data_0, (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1555 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I7195515648724051409_emi78vuj01)}
    );
    NI32 X60Qx_1556 = len_4_sysvq0asl(X60Qdesugar_161);
    NI32 X60Qx_1557 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_162 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1555 + X60Qx_1556)) + X60Qx_1557)));
    add_2_sysvq0asl((&X60Qdesugar_162), (string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I7195515648724051409_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_162), X60Qdesugar_161);
    add_2_sysvq0asl((&X60Qdesugar_162), (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_162);
    nimStrDestroy(X60Qdesugar_162);
    nimStrDestroy(X60Qdesugar_161);}
  if (0 < foreignDefs_0.len_0){
    string_0_sysvq0asl X60Qdesugar_163 = joinSeq_0_emi78vuj01(foreignDefs_0, (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1558 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I18306971952939861040_emi78vuj01)}
    );
    NI32 X60Qx_1559 = len_4_sysvq0asl(X60Qdesugar_163);
    NI32 X60Qx_1560 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_164 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1558 + X60Qx_1559)) + X60Qx_1560)));
    add_2_sysvq0asl((&X60Qdesugar_164), (string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I18306971952939861040_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_164), X60Qdesugar_163);
    add_2_sysvq0asl((&X60Qdesugar_164), (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_164);
    nimStrDestroy(X60Qdesugar_164);
    nimStrDestroy(X60Qdesugar_163);}
  if (0 < defs_0.len_0){
    string_0_sysvq0asl X60Qdesugar_165 = joinSeq_0_emi78vuj01(defs_0, (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1561 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I7818278246678340207_emi78vuj01)}
    );
    NI32 X60Qx_1562 = len_4_sysvq0asl(X60Qdesugar_165);
    NI32 X60Qx_1563 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_166 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1561 + X60Qx_1562)) + X60Qx_1563)));
    add_2_sysvq0asl((&X60Qdesugar_166), (string_0_sysvq0asl){
      .bytes_0 = 539635710u, .more_0 = (&strlit_0_I7818278246678340207_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_166), X60Qdesugar_165);
    add_2_sysvq0asl((&X60Qdesugar_166), (string_0_sysvq0asl){
      .bytes_0 = 657922u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_166);
    nimStrDestroy(X60Qdesugar_166);
    nimStrDestroy(X60Qdesugar_165);}
  if (0 < inits_0.len_0){
    string_0_sysvq0asl X60Qdesugar_167 = joinSeq_0_emi78vuj01(inits_0, (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1564 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I1486236103788791016_emi78vuj01)}
    );
    NI32 X60Qx_1565 = len_4_sysvq0asl(X60Qdesugar_167);
    NI32 X60Qx_1566 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 175966723u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_168 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1564 + X60Qx_1565)) + X60Qx_1566)));
    add_2_sysvq0asl((&X60Qdesugar_168), (string_0_sysvq0asl){
      .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I1486236103788791016_emi78vuj01)}
    );
    add_2_sysvq0asl((&X60Qdesugar_168), X60Qdesugar_167);
    add_2_sysvq0asl((&X60Qdesugar_168), (string_0_sysvq0asl){
      .bytes_0 = 175966723u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&outp_8), X60Qdesugar_168);
    nimStrDestroy(X60Qdesugar_168);
    nimStrDestroy(X60Qdesugar_167);}
  string_0_sysvq0asl X60Qx_1567 = indentC_0_emi78vuj01(outp_8);
  result_76 = X60Qx_1567;
  nimStrDestroy(outp_8);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(provisions_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(headers_1);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(inits_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(data_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(foreignDefs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(stubs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(provisionsNeeded_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(defs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(protos_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(ordered_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(typeDecls_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(fwdDecls_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(allTypes_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(pending_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(seenForeign_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(foreignTypes_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(foreignGlobals_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(foreignProcs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(definedSyms_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(topStmts_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(types_2);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(globals_1);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(procs_1);
  return result_76;
  nimStrDestroy(outp_8);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(provisions_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(headers_1);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(inits_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(data_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(foreignDefs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(stubs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(provisionsNeeded_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(defs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(protos_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(ordered_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(typeDecls_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(fwdDecls_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(allTypes_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(pending_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(seenForeign_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(foreignTypes_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(foreignGlobals_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(foreignProcs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(definedSyms_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(topStmts_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(types_2);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(globals_1);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(procs_1);
  return result_76;
  nimStrDestroy(outp_8);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(provisions_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(headers_1);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(inits_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(data_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(foreignDefs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(stubs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(provisionsNeeded_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(defs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(protos_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(ordered_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(typeDecls_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(fwdDecls_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(allTypes_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(pending_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(seenForeign_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(foreignTypes_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(foreignGlobals_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(foreignProcs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(definedSyms_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(topStmts_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(types_2);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(globals_1);
  eQdestroy_1_Ia4wwhy1_emi78vuj01(procs_1);
  return result_76;}
string_0_sysvq0asl stripModuleSuffix_0_emi78vuj01(string_0_sysvq0asl s_17){
  string_0_sysvq0asl result_77;
  nimStrWasMoved((&result_77));
  nimStrDestroy(result_77);
  string_0_sysvq0asl X60Qx_1568 = nimStrDup(s_17);
  result_77 = X60Qx_1568;
  return result_77;}
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* buildNode_1_emi78vuj01(Cursor_0_nifb6mq6y1* c_1){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* result_78;
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&result_78));
  NifKind_0_nif81dubp1 X60Qx_1569 = kind_0_nifb6mq6y1((*c_1));
  switch (X60Qx_1569){
    case 11:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1570 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_151 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1570);
      NU32 X60Qx_1571 = tagId_0_nifb6mq6y1((*c_1));
      string_0_sysvq0asl* X60Qx_1572 = getQ_0_I93d71y_der823rwr1(pool_0_nifh7u8pu1.tags_0, X60Qx_1571);
      string_0_sysvq0asl X60Qx_1573 = nimStrDup((*X60Qx_1572));
      seq_0_Isutro81_emi78vuj01 X60Qx_1574 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      (*X60Qtmp_151) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 3, .tag_0 = X60Qx_1573, .kids_0 = X60Qx_1574, .atom_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .def_0 = NIM_FALSE, .strVal_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .chrVal_0 = ((NI32)0)}}
      ;
      result_78 = X60Qtmp_151;
      inc_0_nifb6mq6y1(c_1);
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_1575 = kind_0_nifb6mq6y1((*c_1));
          if ((!(X60Qx_1575 == 12))){
            X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1576 = buildNode_1_emi78vuj01(c_1);
            add_0_Iv4n2t31_emi78vuj01((&(*result_78).d_00.kids_0), X60Qx_1576);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      consumeParRi_0_nifb6mq6y1(c_1);}
    break;
    case 12:
    {
      inc_0_nifb6mq6y1(c_1);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      result_78 = NIM_NIL;}
    break;
    case 2:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1577 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_152 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1577);
      seq_0_Isutro81_emi78vuj01 X60Qx_1578 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      (*X60Qtmp_152) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 0, .tag_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .kids_0 = X60Qx_1578, .atom_0 = (string_0_sysvq0asl){
            .bytes_0 = 11777u, .more_0 = NIM_NIL}
          , .def_0 = NIM_FALSE, .strVal_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .chrVal_0 = ((NI32)0)}}
      ;
      result_78 = X60Qtmp_152;
      inc_0_nifb6mq6y1(c_1);}
    break;
    case 4:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1579 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_153 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1579);
      seq_0_Isutro81_emi78vuj01 X60Qx_1580 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      NU32 X60Qx_1581 = symId_0_nifb6mq6y1((*c_1));
      string_0_sysvq0asl* X60Qx_1582 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, X60Qx_1581);
      string_0_sysvq0asl X60Qx_1583 = stripModuleSuffix_0_emi78vuj01((*X60Qx_1582));
      (*X60Qtmp_153) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 0, .tag_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .kids_0 = X60Qx_1580, .atom_0 = X60Qx_1583, .def_0 = NIM_FALSE, .strVal_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .chrVal_0 = ((NI32)0)}}
      ;
      result_78 = X60Qtmp_153;
      inc_0_nifb6mq6y1(c_1);}
    break;
    case 5:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1584 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_154 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1584);
      seq_0_Isutro81_emi78vuj01 X60Qx_1585 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      NU32 X60Qx_1586 = symId_0_nifb6mq6y1((*c_1));
      string_0_sysvq0asl* X60Qx_1587 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, X60Qx_1586);
      string_0_sysvq0asl X60Qx_1588 = stripModuleSuffix_0_emi78vuj01((*X60Qx_1587));
      (*X60Qtmp_154) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 0, .tag_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .kids_0 = X60Qx_1585, .atom_0 = X60Qx_1588, .def_0 = NIM_TRUE, .strVal_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .chrVal_0 = ((NI32)0)}}
      ;
      result_78 = X60Qtmp_154;
      inc_0_nifb6mq6y1(c_1);}
    break;
    case 3:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1589 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_155 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1589);
      seq_0_Isutro81_emi78vuj01 X60Qx_1590 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      NU32 X60Qx_1591 = litId_0_nifb6mq6y1((*c_1));
      string_0_sysvq0asl* X60Qx_1592 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_1591);
      string_0_sysvq0asl X60Qx_1593 = nimStrDup((*X60Qx_1592));
      (*X60Qtmp_155) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 0, .tag_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .kids_0 = X60Qx_1590, .atom_0 = X60Qx_1593, .def_0 = NIM_FALSE, .strVal_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .chrVal_0 = ((NI32)0)}}
      ;
      result_78 = X60Qtmp_155;
      inc_0_nifb6mq6y1(c_1);}
    break;
    case 8:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1594 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_156 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1594);
      seq_0_Isutro81_emi78vuj01 X60Qx_1595 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      NU32 X60Qx_1596 = intId_0_nifb6mq6y1((*c_1));
      NI64* X60Qx_1597 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_1596);
      string_0_sysvq0asl X60Qx_1598 = dollarQ_1_sysvq0asl((*X60Qx_1597));
      (*X60Qtmp_156) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 0, .tag_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .kids_0 = X60Qx_1595, .atom_0 = X60Qx_1598, .def_0 = NIM_FALSE, .strVal_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .chrVal_0 = ((NI32)0)}}
      ;
      result_78 = X60Qtmp_156;
      inc_0_nifb6mq6y1(c_1);}
    break;
    case 9:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1599 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_157 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1599);
      seq_0_Isutro81_emi78vuj01 X60Qx_48 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      NU32 X60Qx_1600 = uintId_0_nifb6mq6y1((*c_1));
      NU64* X60Qx_1601 = getQ_0_Iebom0i1_ast8ri79k(pool_0_nifh7u8pu1.uintegers_0, X60Qx_1600);
      string_0_sysvq0asl X60Qtmp_158 = dollarQ_0_sysvq0asl((*X60Qx_1601));
      string_0_sysvq0asl X60Qx_49 = ampQ_0_sysvq0asl(X60Qtmp_158, (string_0_sysvq0asl){
        .bytes_0 = 29953u, .more_0 = NIM_NIL}
      );
      (*X60Qtmp_157) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 0, .tag_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .kids_0 = X60Qx_48, .atom_0 = X60Qx_49, .def_0 = NIM_FALSE, .strVal_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .chrVal_0 = ((NI32)0)}}
      ;
      result_78 = X60Qtmp_157;
      inc_0_nifb6mq6y1(c_1);
      nimStrDestroy(X60Qtmp_158);}
    break;
    case 10:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1602 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_159 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1602);
      seq_0_Isutro81_emi78vuj01 X60Qx_1603 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      NU32 X60Qx_1604 = floatId_0_nifb6mq6y1((*c_1));
      NF64 X60Qx_1605 = getQ_1_I4qx0py_ast8ri79k(pool_0_nifh7u8pu1.floats_0, X60Qx_1604);
      string_0_sysvq0asl X60Qx_1606 = dollarQ_7_sysvq0asl(X60Qx_1605);
      (*X60Qtmp_159) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 0, .tag_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .kids_0 = X60Qx_1603, .atom_0 = X60Qx_1606, .def_0 = NIM_FALSE, .strVal_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .chrVal_0 = ((NI32)0)}}
      ;
      result_78 = X60Qtmp_159;
      inc_0_nifb6mq6y1(c_1);}
    break;
    case 6:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1607 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_160 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1607);
      seq_0_Isutro81_emi78vuj01 X60Qx_1608 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      NU32 X60Qx_1609 = litId_0_nifb6mq6y1((*c_1));
      string_0_sysvq0asl* X60Qx_1610 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_1609);
      string_0_sysvq0asl X60Qx_1611 = nimStrDup((*X60Qx_1610));
      (*X60Qtmp_160) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 1, .tag_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .kids_0 = X60Qx_1608, .atom_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .def_0 = NIM_FALSE, .strVal_0 = X60Qx_1611, .chrVal_0 = ((NI32)0)}}
      ;
      result_78 = X60Qtmp_160;
      inc_0_nifb6mq6y1(c_1);}
    break;
    case 7:
    {
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      void* X60Qx_1612 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01));
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qtmp_161 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)X60Qx_1612);
      seq_0_Isutro81_emi78vuj01 X60Qx_1613 = newSeqUninit_0_I3hisst_emi78vuj01(0);
      NC8 X60Qx_1614 = charLit_0_nifb6mq6y1((*c_1));
      (*X60Qtmp_161) = (X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01){
        .r_00 = 0, .d_00 = (Node_Obj_0_emi78vuj01){
          .kind_0 = 2, .tag_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .kids_0 = X60Qx_1613, .atom_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .def_0 = NIM_FALSE, .strVal_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .chrVal_0 = ((NI32)X60Qx_1614)}}
      ;
      result_78 = X60Qtmp_161;
      inc_0_nifb6mq6y1(c_1);}
    break;
    default:
    {
      inc_0_nifb6mq6y1(c_1);
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(result_78);
      result_78 = NIM_NIL;}
    break;}
  return result_78;}
string_0_sysvq0asl emitModuleBody_0_emi78vuj01(Cursor_0_nifb6mq6y1* root_1){
  string_0_sysvq0asl result_79;
  nimStrWasMoved((&result_79));
  resetEmitter_0_emi78vuj01();
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* tree_1 = buildNode_1_emi78vuj01(root_1);
  nimStrDestroy(result_79);
  Classified_0_emi78vuj01 X60Qtmp_162 = classify_0_emi78vuj01(tree_1);
  string_0_sysvq0asl X60Qx_1615 = emitUnit_0_emi78vuj01((&X60Qtmp_162));
  result_79 = X60Qx_1615;
  eQdestroyQ_SX43lassified0emi78vuj01_0_emi78vuj01((&X60Qtmp_162));
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(tree_1);
  return result_79;
  eQdestroyQ_SX43lassified0emi78vuj01_0_emi78vuj01((&X60Qtmp_162));
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(tree_1);
  return result_79;}
static inline void plusQeQ_0_Iz7fdp7_emi78vuj01(NI32* x_18, NI32 y_1){
  (*x_18) = ((NI32)((*x_18) + y_1));}
static inline seq_0_Isutro81_emi78vuj01 newSeqUninit_0_I3hisst_emi78vuj01(NI32 size_7){
  seq_0_Isutro81_emi78vuj01 result_84;
  if (size_7 == 0){
    result_84 = (seq_0_Isutro81_emi78vuj01){
      .len_0 = size_7, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_I9a2uc9_emi78vuj01(size_7);
    void* X60Qx_1621 = alloc_1_sysvq0asl(memSize_1);
    result_84 = (seq_0_Isutro81_emi78vuj01){
      .len_0 = size_7, .data_0 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01**)X60Qx_1621)}
    ;
    if ((!(result_84.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1622 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_84.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_84;}
static inline openArray_0_Ip5n4zi1_emi78vuj01 toOpenArray_1_I1gbnw21_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_39){
  openArray_0_Ip5n4zi1_emi78vuj01 result_87;
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** X60Qx_1624 = rawData_0_Idp9xor1_emi78vuj01(s_39);
  result_87 = (openArray_0_Ip5n4zi1_emi78vuj01){
    .a_0 = X60Qx_1624, .len_0 = s_39.len_0}
  ;
  return result_87;}
static inline NI32 len_3_Il6imzw1_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_41){
  NI32 result_88;
  result_88 = s_41.len_0;
  return result_88;}
static inline X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** getQ_7_Iheb436_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_42, NI32 i_35){
  NB8 X60Qx_1625;
  if (i_35 < s_42.len_0){
    X60Qx_1625 = (0 <= i_35);}
  else {
    X60Qx_1625 = NIM_FALSE;}
  if ((!X60Qx_1625)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** result_89;
  result_89 = (&s_42.data_0[i_35]);
  return result_89;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_I3urt0l_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01* x_20){
  openArray_0_Ig73pnk_aow7lb5cq1 result_90;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_26;
  if (((NI32)(((NI32)(((NI32)((NI32)2)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_26 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_26 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_20))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)2)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_90 = X60Qx_26;
  return result_90;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Il5czcd1_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01* x_21){
  openArray_0_Ig73pnk_aow7lb5cq1 result_91;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_27;
  if (((NI32)(((NI32)(((NI32)((NI32)1)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_27 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_27 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_21))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)1)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_91 = X60Qx_27;
  return result_91;}
static inline void add_0_Iv4n2t31_emi78vuj01(seq_0_Isutro81_emi78vuj01* s_43, X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* elem_5){
  NI32 L_1 = (*s_43).len_0;
  NI32 X60Qx_1626 = capInBytes_0_I6jrhdd1_emi78vuj01((*s_43));
  if (X60Qx_1626 < ((NI32)(((NI32)(L_1 * sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*))) + sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)))){
    NB8 X60Qx_1627 = resize_0_Ihuqu5k1_emi78vuj01(s_43, 1);
    if ((!X60Qx_1627)){
      eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(elem_5);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_43).len_0));
  (*s_43).data_0[L_1] = elem_5;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_If2frt3_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01* x_22){
  openArray_0_Ig73pnk_aow7lb5cq1 result_92;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_28;
  if (((NI32)(((NI32)(((NI32)((NI32)0)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_28 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_28 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_22))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)0)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_92 = X60Qx_28;
  return result_92;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Ia0unmf_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS9_emi78vuj01* x_23){
  openArray_0_Ig73pnk_aow7lb5cq1 result_93;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_29;
  if (((NI32)(((NI32)(((NI32)((NI32)8)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_29 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_29 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_23))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)8)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_93 = X60Qx_29;
  return result_93;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Ig1w4is1_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS4_emi78vuj01* x_24){
  openArray_0_Ig73pnk_aow7lb5cq1 result_94;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_30;
  if (((NI32)(((NI32)(((NI32)((NI32)3)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_30 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_30 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_24))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)3)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_94 = X60Qx_30;
  return result_94;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Ih6urrr1_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS7_emi78vuj01* x_25){
  openArray_0_Ig73pnk_aow7lb5cq1 result_95;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_31;
  if (((NI32)(((NI32)(((NI32)((NI32)6)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_31 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_31 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_25))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)6)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_95 = X60Qx_31;
  return result_95;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_Ima7t9w_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS17_emi78vuj01* x_26){
  openArray_0_Ig73pnk_aow7lb5cq1 result_96;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_32;
  if (((NI32)(((NI32)(((NI32)((NI32)16)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_32 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_32 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_26))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)16)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_96 = X60Qx_32;
  return result_96;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_0_I6nl44k1_emi78vuj01(X60Qt_0_IAarraySstring0sysvq0aslS6_emi78vuj01* x_27){
  openArray_0_Ig73pnk_aow7lb5cq1 result_97;
  openArray_0_Ig73pnk_aow7lb5cq1 X60Qx_33;
  if (((NI32)(((NI32)(((NI32)((NI32)5)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_33 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_33 = (openArray_0_Ig73pnk_aow7lb5cq1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_27))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)5)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_97 = X60Qx_33;
  return result_97;}
static inline NI32 memSizeInBytes_0_I9a2uc9_emi78vuj01(NI32 size_12){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_114;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_12, sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_114 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_114 = ((NI32)2147483647);}
  return result_114;}
static inline X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** rawData_0_Idp9xor1_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_53){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** result_115;
  result_115 = s_53.data_0;
  return result_115;}
static inline NI32 len_6_I3x6mi_emi78vuj01(openArray_0_Ip5n4zi1_emi78vuj01 a_30){
  NI32 result_116;
  result_116 = a_30.len_0;
  return result_116;}
static inline X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** getQ_10_Ipbnh891_emi78vuj01(openArray_0_Ip5n4zi1_emi78vuj01 x_30, NI32 idx_12){
  NB8 X60Qx_1647;
  if (0 <= idx_12){
    X60Qx_1647 = (idx_12 < x_30.len_0);}
  else {
    X60Qx_1647 = NIM_FALSE;}
  if ((!X60Qx_1647)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** result_117;
  result_117 = (&x_30.a_0[idx_12]);
  return result_117;}
static inline NI32 capInBytes_0_I6jrhdd1_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_54){
  NI32 result_118;
  NI32 X60Qx_35;
  if ((!(s_54.data_0 == NIM_NIL))){
    NI32 X60Qx_1648 = allocatedSize_0_sysvq0asl(((void*)((void*)s_54.data_0)));
    X60Qx_35 = X60Qx_1648;}
  else {
    X60Qx_35 = 0;}
  result_118 = X60Qx_35;
  return result_118;}
NB8 resize_0_Ihuqu5k1_emi78vuj01(seq_0_Isutro81_emi78vuj01* dest_4, NI32 addedElements_4){
  NB8 result_119;
  NI32 X60Qx_1649 = capInBytes_0_I6jrhdd1_emi78vuj01((*dest_4));
  NI32 oldCap_1 = ((NI32)(X60Qx_1649 / sizeof(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01*)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_4);
  NI32 memSize_4 = memSizeInBytes_0_I9a2uc9_emi78vuj01(newCap_1);
  void* X60Qx_1650 = realloc_1_sysvq0asl(((void*)((void*)(*dest_4).data_0)), memSize_4);
  (*dest_4).data_0 = ((X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01**)X60Qx_1650);
  if ((*dest_4).data_0 == NIM_NIL){
    (*dest_4).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_4);
    result_119 = NIM_FALSE;}
  else {
    result_119 = NIM_TRUE;}
  return result_119;}
void eQdestroy_1_Ia4wwhy1_emi78vuj01(seq_0_Isutro81_emi78vuj01 s_80){
  if ((!(s_80.data_0 == NIM_NIL))){
    NI32 i_42 = 0;
    {
      while (i_42 < s_80.len_0){
        eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(s_80.data_0[i_42]);
        inc_1_I6wjjge_aow2h993l1((&i_42));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_80.data_0)));}}
static inline void eQwasMoved_1_Iu9z3fg1_emi78vuj01(seq_0_Isutro81_emi78vuj01* s_81){
  (*s_81).len_0 = 0;
  (*s_81).data_0 = NIM_NIL;}
seq_0_Isutro81_emi78vuj01 eQdup_1_Iqcqrch1_emi78vuj01(seq_0_Isutro81_emi78vuj01 a_42){
  seq_0_Isutro81_emi78vuj01 result_126;
  seq_0_Isutro81_emi78vuj01 X60Qx_1657 = newSeqUninit_0_I3hisst_emi78vuj01(a_42.len_0);
  result_126 = X60Qx_1657;
  NI32 i_43 = 0;
  {
    while (i_43 < a_42.len_0){
      X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* X60Qx_1658 = eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(a_42.data_0[i_43]);
      result_126.data_0[i_43] = X60Qx_1658;
      inc_1_I6wjjge_aow2h993l1((&i_43));}}
  whileStmtLabel_0: ;
  return result_126;}
void eQdestroyQ_SX4eodeX4fbj0emi78vuj01_0_emi78vuj01(Node_Obj_0_emi78vuj01* dest_0){
  nimStrDestroy((*dest_0).strVal_0);
  nimStrDestroy((*dest_0).atom_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*dest_0).kids_0);
  nimStrDestroy((*dest_0).tag_0);}
void eQdestroyQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01(ProcParts_0_emi78vuj01* dest_0){
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*dest_0).pnodes_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*dest_0).pragmas_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*dest_0).body_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*dest_0).ret_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*dest_0).params_0);
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*dest_0).nameAtom_0);}
void eQwasmovedQ_SX50rocX50arts0emi78vuj01_0_emi78vuj01(ProcParts_0_emi78vuj01* dest_0){
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&(*dest_0).nameAtom_0));
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&(*dest_0).params_0));
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&(*dest_0).ret_0));
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&(*dest_0).body_0));
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&(*dest_0).pragmas_0));
  eQwasMoved_1_Iu9z3fg1_emi78vuj01((&(*dest_0).pnodes_0));}
void eQdestroyQ_SX47lobalX49nfo0emi78vuj01_0_emi78vuj01(GlobalInfo_0_emi78vuj01* dest_0){
  eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((*dest_0).value_0);
  nimStrDestroy((*dest_0).nameAtom_0);
  nimStrDestroy((*dest_0).decl_0);
  nimStrDestroy((*dest_0).name_0);}
void eQwasmovedQ_SX47lobalX49nfo0emi78vuj01_0_emi78vuj01(GlobalInfo_0_emi78vuj01* dest_0){
  nimStrWasMoved((&(*dest_0).name_0));
  nimStrWasMoved((&(*dest_0).decl_0));
  nimStrWasMoved((&(*dest_0).nameAtom_0));
  eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&(*dest_0).value_0));}
void eQdestroyQ_SX43lassified0emi78vuj01_0_emi78vuj01(Classified_0_emi78vuj01* dest_0){
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*dest_0).topStmts_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*dest_0).types_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*dest_0).globals_0);
  eQdestroy_1_Ia4wwhy1_emi78vuj01((*dest_0).procs_0);}
void eQwasmovedQ_SX43lassified0emi78vuj01_0_emi78vuj01(Classified_0_emi78vuj01* dest_0){
  eQwasMoved_1_Iu9z3fg1_emi78vuj01((&(*dest_0).procs_0));
  eQwasMoved_1_Iu9z3fg1_emi78vuj01((&(*dest_0).globals_0));
  eQwasMoved_1_Iu9z3fg1_emi78vuj01((&(*dest_0).types_0));
  eQwasMoved_1_Iu9z3fg1_emi78vuj01((&(*dest_0).topStmts_0));}
void eQdestroyQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* dest_0){
  if (dest_0){
    NB8 X60Qx_1761 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1761){
      eQdestroyQ_SX4eodeX4fbj0emi78vuj01_0_emi78vuj01((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* eQdupQ_ArefSX4eodeX4fbj0emi78vuj01_0_emi78vuj01(X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* src_0){
  X60Qt_0_IArefSX4eodeX4fbj0emi78vuj01_emi78vuj01* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void X60Qini_0_emi78vuj01(void){
  if (X60QiniGuard_0_emi78vuj01){
    return;}
  X60QiniGuard_0_emi78vuj01 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_prorcx25w1();
  externKeys_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  externVals_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  typeExternKeys_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  typeExternVals_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  noDeclTypes_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  loadedMods_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  siblingSuffixes_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  modProcKeys_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  modProcVals_0_emi78vuj01 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  modGlobalKeys_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  modGlobalVals_0_emi78vuj01 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  modTypeKeys_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  modTypeVals_0_emi78vuj01 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  checkedSuffixes_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  otNames_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  otTypes_0_emi78vuj01 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  otOrder_0_emi78vuj01 = newSeqUninit_0_I3hisst_emi78vuj01(0);
  otStateKeys_0_emi78vuj01 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  otStateVals_0_emi78vuj01 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67){
  openArray_0_Ijk0jkw1_aow7lb5cq1 result_146;
  NC8* X60Qx_316 = readRawData_0_sysvq0asl((&(*s_67)), 0);
  NI32 X60Qx_317 = len_4_sysvq0asl((*s_67));
  result_146 = (openArray_0_Ijk0jkw1_aow7lb5cq1){
    .a_0 = X60Qx_316, .len_0 = X60Qx_317}
  ;
  return result_146;}
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_27){
  NI32 result_83;
  result_83 = a_27.len_0;
  return result_83;}
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6){
  NB8 X60Qx_1466;
  if (0 <= idx_6){
    X60Qx_1466 = (idx_6 < x_12.len_0);}
  else {
    X60Qx_1466 = NIM_FALSE;}
  if ((!X60Qx_1466)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NC8* result_84;
  result_84 = (&x_12.a_0[idx_6]);
  return result_84;}
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
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline HSlice_0_Inzqy8d_aow7lb5cq1 ___1_Iclcqmw1_aow7lb5cq1(NI32 a_15, NI32 b_2){
  HSlice_0_Inzqy8d_aow7lb5cq1 result_57;
  result_57 = (HSlice_0_Inzqy8d_aow7lb5cq1){
    .a_0 = a_15, .b_0 = b_2}
  ;
  return result_57;}
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355){
  string_0_sysvq0asl result_224;
  nimStrWasMoved((&result_224));
  nimStrDestroy(result_224);
  string_0_sysvq0asl X60Qx_437 = substr_0_sysvq0asl(s_77, x_355.a_0, x_355.b_0);
  result_224 = X60Qx_437;
  return result_224;}
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_dbgj4vyzj1(NI32 a_13, NI32 b_2){
  HSlice_0_Inzqy8d_aow7lb5cq1 result_36;
  result_36 = (HSlice_0_Inzqy8d_aow7lb5cq1){
    .a_0 = a_13, .b_0 = ((NI32)(b_2 - ((NI32)1)))}
  ;
  return result_36;}
static inline NC8 chr_0_sysvq0asl(NI32 u_0){
  NC8 result_168;
  result_168 = ((NC8)((NI32)u_0));
  return result_168;}
static inline string_0_sysvq0asl ampQ_1_sysvq0asl(string_0_sysvq0asl x_316, NC8 y_199){
  string_0_sysvq0asl result_136;
  nimStrWasMoved((&result_136));
  nimStrDestroy(result_136);
  string_0_sysvq0asl X60Qtmp_4 = charToString_0_sysvq0asl(y_199);
  string_0_sysvq0asl X60Qx_307 = ampQ_0_sysvq0asl(x_316, X60Qtmp_4);
  result_136 = X60Qx_307;
  nimStrDestroy(X60Qtmp_4);
  return result_136;
  nimStrDestroy(X60Qtmp_4);
  return result_136;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
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
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_36){
  NB8 X60Qx_1442;
  if (i_36 < s_46.len_0){
    X60Qx_1442 = (0 <= i_36);}
  else {
    X60Qx_1442 = NIM_FALSE;}
  if ((!X60Qx_1442)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NI32* result_68;
  result_68 = (&s_46.data_0[i_36]);
  return result_68;}
static inline void putQ_7_Ifvyck5_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_52, NI32 i_38, NI32 elem_15){
  NB8 X60Qx_1452;
  if (i_38 < (*s_52).len_0){
    X60Qx_1452 = (0 <= i_38);}
  else {
    X60Qx_1452 = NIM_FALSE;}
  if ((!X60Qx_1452)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_52).data_0[i_38] = elem_15;}
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_1445 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_1445 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1446 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_1446)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10){
  seq_0_Ift2sne_aow7lb5cq1 result_69;
  if (size_10 == 0){
    result_69 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Inv7kg3_aow7lb5cq1(size_10);
    void* X60Qx_1443 = alloc_1_sysvq0asl(memSize_2);
    result_69 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = ((NI32*)X60Qx_1443)}
    ;
    if ((!(result_69.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1444 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_69.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_69;}
static inline void endRead_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_5){
  }
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
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
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
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
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8){
  NU32 result_11;
  PackedToken_0_nifh7u8pu1 X60Qx_26 = load_0_nifb6mq6y1(c_8);
  NU32 X60Qx_27 = symId_0_nifh7u8pu1(X60Qx_26);
  result_11 = X60Qx_27;
  return result_11;}
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
static inline NU32 uintId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_11){
  NU32 result_14;
  PackedToken_0_nifh7u8pu1 X60Qx_32 = load_0_nifb6mq6y1(c_11);
  NU32 X60Qx_33 = uintId_0_nifh7u8pu1(X60Qx_32);
  result_14 = X60Qx_33;
  return result_14;}
static inline NU64* getQ_0_Iebom0i1_ast8ri79k(BiTable_0_Itxao711_ast8ri79k t_8, NU32 litId_7){
  NU64* result_5;
  NI32 idx_2 = ((NI32)(((NI32)litId_7) - ((NI32)1)));
  if ((!(idx_2 < t_8.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NU64* X60Qx_33 = getQ_7_Ifaxado1_ast8ri79k(t_8.vals_0, idx_2);
  result_5 = X60Qx_33;
  return result_5;}
static inline NU32 floatId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_12){
  NU32 result_15;
  PackedToken_0_nifh7u8pu1 X60Qx_34 = load_0_nifb6mq6y1(c_12);
  NU32 X60Qx_35 = floatId_0_nifh7u8pu1(X60Qx_34);
  result_15 = X60Qx_35;
  return result_15;}
static inline NF64 getQ_1_I4qx0py_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_9, NU32 litId_8){
  NF64 result_6;
  NU64* X60Qx_34 = getQ_0_I3qz68f_ast8ri79k(t_9, litId_8);
  NU64 X60Qx_35 = (*X60Qx_34);
  NF64 X60Qx_36;
  copyMem_0_sysvq0asl((&X60Qx_36), (&X60Qx_35), sizeof(NF64));
  result_6 = X60Qx_36;
  return result_6;}
static inline NC8 charLit_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_9){
  NC8 result_12;
  PackedToken_0_nifh7u8pu1 X60Qx_28 = load_0_nifb6mq6y1(c_9);
  NC8 X60Qx_29 = charLit_0_nifh7u8pu1(X60Qx_28);
  result_12 = X60Qx_29;
  return result_12;}
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
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67){
  string_0_sysvq0asl* result_89;
  result_89 = s_67.data_0;
  return result_89;}
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
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0){
  NC8* result_103;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_39).bytes_0))))){
    result_103 = ((NC8*)((NU32)(((NU32)(&(*(*s_39).more_0).data_0[0])) + ((NU32)start_0))));}
  else {
    result_103 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_39).bytes_0)) + 1u)))) + ((NU32)start_0))));}
  return result_103;}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68){
  NI32 result_94;
  NI32 X60Qx_13;
  if ((!(s_68.data_0 == NIM_NIL))){
    NI32 X60Qx_1476 = allocatedSize_0_sysvq0asl(((void*)((void*)s_68.data_0)));
    X60Qx_13 = X60Qx_1476;}
  else {
    X60Qx_13 = 0;}
  result_94 = X60Qx_13;
  return result_94;}
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_93;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_20, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_93 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_93 = ((NI32)2147483647);}
  return result_93;}
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
static inline NU64* getQ_0_I3qz68f_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_14, NU32 litId_13){
  NU64* result_12;
  NI32 idx_4 = ((NI32)(((NI32)litId_13) - ((NI32)1)));
  if ((!(idx_4 < t_14.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NU64* X60Qx_55 = getQ_7_Ifaxado1_ast8ri79k(t_14.vals_0, idx_4);
  result_12 = X60Qx_55;
  return result_12;}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
