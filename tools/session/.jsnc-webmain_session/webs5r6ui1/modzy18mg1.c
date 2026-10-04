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
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct ToplevelEntry_0_prorcx25w1 ToplevelEntry_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
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
typedef NU8 LoadStatus_0_prorcx25w1;

#define LacksModuleName_0_prorcx25w1 ((NU8)0)
#define LacksOffset_0_prorcx25w1 ((NU8)1)
#define LacksPosition_0_prorcx25w1 ((NU8)2)
#define LacksNothing_0_prorcx25w1 ((NU8)3)
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct LoadResult_0_prorcx25w1{
  LoadStatus_0_prorcx25w1 status_0;
  Cursor_0_nifb6mq6y1 decl_0;}
LoadResult_0_prorcx25w1;
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
typedef struct seq_0_Ivkh6l1_linxafkvx1{
  NI32 len_0;
  LineInfoUnpacked_0_linxafkvx1* data_0;}
seq_0_Ivkh6l1_linxafkvx1;
typedef struct LineInfoManager_0_linxafkvx1{
  seq_0_Ivkh6l1_linxafkvx1 aside_0;}
LineInfoManager_0_linxafkvx1;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
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
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1{
  string_0_sysvq0asl fld_0;
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern string_0_sysvq0asl substr_1_sysvq0asl(string_0_sysvq0asl s_57, NI32 first_1);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline string_0_sysvq0asl suffixToNif_0_prorcx25w1(string_0_sysvq0asl suffix_1);
static inline NB8 vfsExists_0_vfsc9jn7(string_0_sysvq0asl path_3);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
extern void eQwasmovedQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1* dest_0);
static inline NB8 hasKey_0_prorcx25w1(ToplevelEntries_0_prorcx25w1 t_1, NU32 s_0);
extern Program_0_prorcx25w1 prog_0_prorcx25w1;
extern LoadResult_0_prorcx25w1 tryLoadSym_0_prorcx25w1(NU32 s_5);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
extern string_0_sysvq0asl extractModule_0_symkyk35i1(string_0_sysvq0asl s_2);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
extern string_0_sysvq0asl parentDir_0_ospaexnw61(string_0_sysvq0asl path_6);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline string_0_sysvq0asl slashQ_0_ospaexnw61(string_0_sysvq0asl head_1, string_0_sysvq0asl tail_2);
extern X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7 existsRelay_0_vfsc9jn7;
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
static inline NB8 hasKey_0_Ihimb3m1_intzsnzax(Table_0_Idzo7511_intzsnzax t_93, NU32 k_84);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l;
extern string_0_sysvq0asl joinPath_0_ospaexnw61(string_0_sysvq0asl head_0, string_0_sysvq0asl tail_1);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NB8 contains_0_Ix54wnr1_intzsnzax(Table_0_Idzo7511_intzsnzax t_129, NU32 k_107);
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0);
extern NI32 rawGet_0_I1waarx1_intzsnzax(Table_0_Idzo7511_intzsnzax t_96, NU32 k_86, NU32 kh_10);
static inline NU32 hash_2_has9tn57v(NU32 u_0);
LongString_0_sysvq0asl const strlit_0_I5065733472155119234_modzy18mg1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".s.nif"}
;
LongString_0_sysvq0asl const strlit_0_I11901799661097360525_modzy18mg1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".sc.nif"}
;
LongString_0_sysvq0asl const strlit_0_I16810923556642427947_modzy18mg1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".s.idx.nif"}
;
LongString_0_sysvq0asl const strlit_0_I4912791914873646233_modzy18mg1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".sc.idx.nif"}
;
LongString_0_sysvq0asl const strlit_0_I6285466887371389114_modzy18mg1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "module \'"}
;
LongString_0_sysvq0asl const strlit_0_I7031293180197693309_modzy18mg1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' has no artifacts at \'"}
;
LongString_0_sysvq0asl const strlit_0_I2260818525730174559_modzy18mg1 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' (needed to resolve \'"}
;
seq_0_Ixdx2fh1_aow7lb5cq1 gModArtifactsOk_0_modzy18mg1;
NB8 gMissingModule_0_modzy18mg1 = NIM_FALSE;
string_0_sysvq0asl gMissingModuleNote_0_modzy18mg1 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
static string_0_sysvq0asl const SExt_0 = {
  .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
;
static string_0_sysvq0asl const ScExt_0 = {
  .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
;
NI32 gRootGen_0_modzy18mg1 = 0;
NB8 X60QiniGuard_0_modzy18mg1;
string_0_sysvq0asl indexNameFor_0_modzy18mg1(string_0_sysvq0asl nifPath_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  nimStrDestroy(result_0);
  result_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_2;
  NI32 X60Qx_4 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
  );
  NI32 X60Qx_5 = len_4_sysvq0asl(nifPath_0);
  if (X60Qx_4 < X60Qx_5){
    NI32 X60Qx_6 = len_4_sysvq0asl(nifPath_0);
    NI32 X60Qx_7 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
    );
    string_0_sysvq0asl X60Qtmp_0 = substr_1_sysvq0asl(nifPath_0, ((NI32)(X60Qx_6 - X60Qx_7)));
    NB8 X60Qx_8 = eqQ_20_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
      .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
    );
    X60Qx_2 = X60Qx_8;
    nimStrDestroy(X60Qtmp_0);}
  else {
    X60Qx_2 = NIM_FALSE;}
  if (X60Qx_2){
    NI32 X60Qx_9 = len_4_sysvq0asl(nifPath_0);
    NI32 X60Qx_10 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_modzy18mg1)}
    );
    string_0_sysvq0asl X60Qtmp_1 = substr_0_sysvq0asl(nifPath_0, 0, ((NI32)(((NI32)(X60Qx_9 - X60Qx_10)) - 1)));
    string_0_sysvq0asl X60Qx_11 = ampQ_0_sysvq0asl(X60Qtmp_1, (string_0_sysvq0asl){
      .bytes_0 = 779300606u, .more_0 = (&strlit_0_I16810923556642427947_modzy18mg1)}
    );
    result_0 = X60Qx_11;
    nimStrDestroy(X60Qtmp_1);
    return result_0;
    nimStrDestroy(X60Qtmp_1);}
  NB8 X60Qx_3;
  NI32 X60Qx_12 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
  );
  NI32 X60Qx_13 = len_4_sysvq0asl(nifPath_0);
  if (X60Qx_12 < X60Qx_13){
    NI32 X60Qx_14 = len_4_sysvq0asl(nifPath_0);
    NI32 X60Qx_15 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
    );
    string_0_sysvq0asl X60Qtmp_2 = substr_1_sysvq0asl(nifPath_0, ((NI32)(X60Qx_14 - X60Qx_15)));
    NB8 X60Qx_16 = eqQ_20_sysvq0asl(X60Qtmp_2, (string_0_sysvq0asl){
      .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
    );
    X60Qx_3 = X60Qx_16;
    nimStrDestroy(X60Qtmp_2);}
  else {
    X60Qx_3 = NIM_FALSE;}
  if (X60Qx_3){
    NI32 X60Qx_17 = len_4_sysvq0asl(nifPath_0);
    NI32 X60Qx_18 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
    );
    string_0_sysvq0asl X60Qtmp_3 = substr_0_sysvq0asl(nifPath_0, 0, ((NI32)(((NI32)(X60Qx_17 - X60Qx_18)) - 1)));
    string_0_sysvq0asl X60Qx_19 = ampQ_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
      .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I4912791914873646233_modzy18mg1)}
    );
    result_0 = X60Qx_19;
    nimStrDestroy(X60Qtmp_3);
    return result_0;
    nimStrDestroy(X60Qtmp_3);}
  return result_0;}
NB8 moduleArtifactsPresent_0_modzy18mg1(string_0_sysvq0asl suffix_0){
  NB8 result_1;
  NI32 X60Qx_20 = len_4_sysvq0asl(suffix_0);
  if (X60Qx_20 == 0){
    return NIM_FALSE;}
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_21 = len_3_Ixq6taz_aow7lb5cq1(gModArtifactsOk_0_modzy18mg1);
      if (i_0 < X60Qx_21){
        string_0_sysvq0asl* X60Qx_22 = getQ_7_Ir6d0tw_aow7lb5cq1(gModArtifactsOk_0_modzy18mg1, i_0);
        NB8 X60Qx_23 = eqQ_20_sysvq0asl((*X60Qx_22), suffix_0);
        if (X60Qx_23){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl nif_0 = suffixToNif_0_prorcx25w1(suffix_0);
  NB8 X60Qx_24 = vfsExists_0_vfsc9jn7(nif_0);
  if ((!X60Qx_24)){
    nimStrDestroy(nif_0);
    return NIM_FALSE;}
  string_0_sysvq0asl idx_0 = indexNameFor_0_modzy18mg1(nif_0);
  NB8 X60Qx_25;
  NI32 X60Qx_26 = len_4_sysvq0asl(idx_0);
  if (0 < X60Qx_26){
    NB8 X60Qx_27 = vfsExists_0_vfsc9jn7(idx_0);
    X60Qx_25 = (!X60Qx_27);}
  else {
    X60Qx_25 = NIM_FALSE;}
  if (X60Qx_25){
    nimStrDestroy(idx_0);
    nimStrDestroy(nif_0);
    return NIM_FALSE;}
  string_0_sysvq0asl X60Qx_28 = nimStrDup(suffix_0);
  add_0_Ig6072n_aow7lb5cq1((&gModArtifactsOk_0_modzy18mg1), X60Qx_28);
  result_1 = NIM_TRUE;
  nimStrDestroy(idx_0);
  nimStrDestroy(nif_0);
  return result_1;
  nimStrDestroy(idx_0);
  nimStrDestroy(nif_0);
  return result_1;}
static inline NB8 moduleMissing_0_modzy18mg1(void){
  NB8 result_2;
  result_2 = gMissingModule_0_modzy18mg1;
  return result_2;}
string_0_sysvq0asl missingModuleNote_0_modzy18mg1(void){
  string_0_sysvq0asl result_3;
  nimStrWasMoved((&result_3));
  nimStrDestroy(result_3);
  string_0_sysvq0asl X60Qx_29 = nimStrDup(gMissingModuleNote_0_modzy18mg1);
  result_3 = X60Qx_29;
  return result_3;}
void clearMissingModule_0_modzy18mg1(void){
  gMissingModule_0_modzy18mg1 = NIM_FALSE;
  nimStrDestroy(gMissingModuleNote_0_modzy18mg1);
  gMissingModuleNote_0_modzy18mg1 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;}
LoadResult_0_prorcx25w1 tryLoadSymSafe_0_modzy18mg1(NU32 s_0){
  LoadResult_0_prorcx25w1 result_4;
  eQwasmovedQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1((&result_4));
  NB8 X60Qx_30 = hasKey_0_prorcx25w1(prog_0_prorcx25w1.mem_0, s_0);
  if (X60Qx_30){
    LoadResult_0_prorcx25w1 X60Qx_31 = tryLoadSym_0_prorcx25w1(s_0);
    result_4 = X60Qx_31;
    return result_4;}
  string_0_sysvq0asl* X60Qx_32 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_0);
  string_0_sysvq0asl nifName_0 = nimStrDup((*X60Qx_32));
  string_0_sysvq0asl modname_0 = extractModule_0_symkyk35i1(nifName_0);
  NB8 X60Qx_33;
  NI32 X60Qx_34 = len_4_sysvq0asl(modname_0);
  if (0 < X60Qx_34){
    NB8 X60Qx_35 = moduleArtifactsPresent_0_modzy18mg1(modname_0);
    X60Qx_33 = (!X60Qx_35);}
  else {
    X60Qx_33 = NIM_FALSE;}
  if (X60Qx_33){
    if ((!gMissingModule_0_modzy18mg1)){
      gMissingModule_0_modzy18mg1 = NIM_TRUE;
      string_0_sysvq0asl X60Qdesugar_0 = suffixToNif_0_prorcx25w1(modname_0);
      NI32 X60Qx_36 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I6285466887371389114_modzy18mg1)}
      );
      NI32 X60Qx_37 = len_4_sysvq0asl(modname_0);
      NI32 X60Qx_38 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1746937854u, .more_0 = (&strlit_0_I7031293180197693309_modzy18mg1)}
      );
      NI32 X60Qx_39 = len_4_sysvq0asl(X60Qdesugar_0);
      NI32 X60Qx_40 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 673196030u, .more_0 = (&strlit_0_I2260818525730174559_modzy18mg1)}
      );
      NI32 X60Qx_41 = len_4_sysvq0asl(nifName_0);
      NI32 X60Qx_42 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2696962u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_36 + X60Qx_37)) + X60Qx_38)) + X60Qx_39)) + X60Qx_40)) + X60Qx_41)) + X60Qx_42)));
      add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
        .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I6285466887371389114_modzy18mg1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_1), modname_0);
      add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
        .bytes_0 = 1746937854u, .more_0 = (&strlit_0_I7031293180197693309_modzy18mg1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_1), X60Qdesugar_0);
      add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
        .bytes_0 = 673196030u, .more_0 = (&strlit_0_I2260818525730174559_modzy18mg1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_1), nifName_0);
      add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
        .bytes_0 = 2696962u, .more_0 = NIM_NIL}
      );
      nimStrDestroy(gMissingModuleNote_0_modzy18mg1);
      gMissingModuleNote_0_modzy18mg1 = X60Qdesugar_1;
      nimStrWasMoved((&X60Qdesugar_1));
      nimStrDestroy(X60Qdesugar_1);
      nimStrDestroy(X60Qdesugar_0);}
    result_4 = (LoadResult_0_prorcx25w1){
      .status_0 = 0, .decl_0 = (Cursor_0_nifb6mq6y1){
        .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}}
    ;
    nimStrDestroy(modname_0);
    nimStrDestroy(nifName_0);
    return result_4;}
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(result_4);
  LoadResult_0_prorcx25w1 X60Qx_43 = tryLoadSym_0_prorcx25w1(s_0);
  result_4 = X60Qx_43;
  nimStrDestroy(modname_0);
  nimStrDestroy(nifName_0);
  return result_4;
  nimStrDestroy(modname_0);
  nimStrDestroy(nifName_0);
  return result_4;}
NB8 artifactReadable_0_modzy18mg1(string_0_sysvq0asl path_0){
  NB8 result_5;
  NB8 X60Qx_44;
  NI32 X60Qx_45 = len_4_sysvq0asl(path_0);
  if (0 < X60Qx_45){
    NB8 X60Qx_46 = vfsExists_0_vfsc9jn7(path_0);
    X60Qx_44 = X60Qx_46;}
  else {
    X60Qx_44 = NIM_FALSE;}
  result_5 = X60Qx_44;
  return result_5;}
string_0_sysvq0asl rootOfArtifact_0_modzy18mg1(string_0_sysvq0asl nifPath_1){
  string_0_sysvq0asl result_6;
  nimStrWasMoved((&result_6));
  nimStrDestroy(result_6);
  string_0_sysvq0asl X60Qx_47 = parentDir_0_ospaexnw61(nifPath_1);
  result_6 = X60Qx_47;
  return result_6;}
NI32 progRootGen_0_modzy18mg1(void){
  NI32 result_7;
  result_7 = gRootGen_0_modzy18mg1;
  return result_7;}
void setProgRoot_0_modzy18mg1(string_0_sysvq0asl dir_0){
  NB8 X60Qx_48;
  NI32 X60Qx_49 = len_4_sysvq0asl(dir_0);
  if (0 < X60Qx_49){
    NB8 X60Qx_50 = eqQ_20_sysvq0asl(prog_0_prorcx25w1.main_0.dir_0, dir_0);
    X60Qx_48 = (!X60Qx_50);}
  else {
    X60Qx_48 = NIM_FALSE;}
  if (X60Qx_48){
    string_0_sysvq0asl* X60Qlhs_4 = (&prog_0_prorcx25w1.main_0.dir_0);
    nimStrDestroy((*X60Qlhs_4));
    string_0_sysvq0asl X60Qx_51 = nimStrDup(dir_0);
    (*X60Qlhs_4) = X60Qx_51;
    eQdestroy_1_Ivioh0a_aow7lb5cq1(gModArtifactsOk_0_modzy18mg1);
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_52 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    gModArtifactsOk_0_modzy18mg1 = X60Qx_52;
    inc_1_I6wjjge_aow2h993l1((&gRootGen_0_modzy18mg1));}}
string_0_sysvq0asl progRoot_0_modzy18mg1(void){
  string_0_sysvq0asl result_8;
  nimStrWasMoved((&result_8));
  nimStrDestroy(result_8);
  string_0_sysvq0asl X60Qx_53 = nimStrDup(prog_0_prorcx25w1.main_0.dir_0);
  result_8 = X60Qx_53;
  return result_8;}
void X60Qini_0_modzy18mg1(void){
  if (X60QiniGuard_0_modzy18mg1){
    return;}
  X60QiniGuard_0_modzy18mg1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_prorcx25w1();
  X60Qini_0_symkyk35i1();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  gModArtifactsOk_0_modzy18mg1 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);}
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
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline NB8 vfsExists_0_vfsc9jn7(string_0_sysvq0asl path_3){
  NB8 result_15;
  NB8 X60Qx_17 = existsRelay_0_vfsc9jn7(path_3);
  result_15 = X60Qx_17;
  return result_15;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
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
static inline NB8 hasKey_0_prorcx25w1(ToplevelEntries_0_prorcx25w1 t_1, NU32 s_0){
  NB8 result_3;
  NB8 X60Qx_32 = hasKey_0_Ihimb3m1_intzsnzax(t_1.bySymId_0, s_0);
  result_3 = X60Qx_32;
  return result_3;}
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
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline NB8 hasKey_0_Ihimb3m1_intzsnzax(Table_0_Idzo7511_intzsnzax t_93, NU32 k_84){
  NB8 result_283;
  NB8 X60Qx_3947 = contains_0_Ix54wnr1_intzsnzax(t_93, k_84);
  result_283 = X60Qx_3947;
  return result_283;}
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
static inline NB8 contains_0_Ix54wnr1_intzsnzax(Table_0_Idzo7511_intzsnzax t_129, NU32 k_107){
  NB8 result_413;
  NU32 X60Qx_4283 = hash_0_nifh7u8pu1(k_107);
  NI32 X60Qx_4284 = rawGet_0_I1waarx1_intzsnzax(t_129, k_107, X60Qx_4283);
  result_413 = (0 <= X60Qx_4284);
  return result_413;}
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0){
  NU32 result_11;
  NU32 X60Qx_20 = hash_2_has9tn57v(x_0);
  result_11 = X60Qx_20;
  return result_11;}
static inline NU32 hash_2_has9tn57v(NU32 u_0){
  NU32 result_3;
  result_3 = u_0;
  return result_3;}
