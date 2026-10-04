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
typedef struct ParamFacts_0_der823rwr1 ParamFacts_0_der823rwr1;
typedef struct X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1 X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef NU8 AnGiveUp_0_der823rwr1;

#define agNone_0_der823rwr1 ((NU8)0)
#define agNoBody_0_der823rwr1 ((NU8)1)
#define agMethod_0_der823rwr1 ((NU8)2)
#define agRecursion_0_der823rwr1 ((NU8)3)
#define agDepth_0_der823rwr1 ((NU8)4)
#define agShape_0_der823rwr1 ((NU8)5)
#define agCalleeUnknown_0_der823rwr1 ((NU8)6)
#define agNoParam_0_der823rwr1 ((NU8)7)
#define agNoField_0_der823rwr1 ((NU8)8)
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct ParamFacts_0_der823rwr1{
  NB8 unknown_0;
  AnGiveUp_0_der823rwr1 why_0;
  string_0_sysvq0asl at_0;
  seq_0_In6doa_arecyyj7v touched_0;}
ParamFacts_0_der823rwr1;
typedef struct seq_0_Ipj3tye_der823rwr1{
  NI32 len_0;
  ParamFacts_0_der823rwr1* data_0;}
seq_0_Ipj3tye_der823rwr1;
typedef struct RoutineFacts_Obj_0_der823rwr1{
  NB8 ok_0;
  AnGiveUp_0_der823rwr1 why_0;
  seq_0_Ipj3tye_der823rwr1 params_0;}
RoutineFacts_Obj_0_der823rwr1;
typedef struct Scan_0_der823rwr1{
  seq_0_In6doa_arecyyj7v params_0;
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* facts_0;
  NI32 depth_0;}
Scan_0_der823rwr1;
typedef NU8 AnVerdict_0_der823rwr1;

#define avNeverTouched_0_der823rwr1 ((NU8)0)
#define avTouched_0_der823rwr1 ((NU8)1)
#define avUnknown_0_der823rwr1 ((NU8)2)
typedef struct seq_0_Ispzxr4_der823rwr1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* data_0;}
seq_0_Ispzxr4_der823rwr1;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_Iyoauy01_der823rwr1{
  seq_0_Ispzxr4_der823rwr1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Iyoauy01_der823rwr1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
typedef struct X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1{
  NI r_00;
  RoutineFacts_Obj_0_der823rwr1 d_00;}
X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1;
typedef struct X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1{
  AnVerdict_0_der823rwr1 fld_0;
  AnGiveUp_0_der823rwr1 fld_1;
  string_0_sysvq0asl fld_2;}
X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1{
  NU32 fld_0;
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1;
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
typedef struct Local_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 typ_0;
  Cursor_0_nifb6mq6y1 val_0;}
Local_0_decqocs071;
typedef NU8 LoadStatus_0_prorcx25w1;

#define LacksModuleName_0_prorcx25w1 ((NU8)0)
#define LacksOffset_0_prorcx25w1 ((NU8)1)
#define LacksPosition_0_prorcx25w1 ((NU8)2)
#define LacksNothing_0_prorcx25w1 ((NU8)3)
typedef struct LoadResult_0_prorcx25w1{
  LoadStatus_0_prorcx25w1 status_0;
  Cursor_0_nifb6mq6y1 decl_0;}
LoadResult_0_prorcx25w1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
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
typedef NU8 DeclineStage_0_croph25r5;

#define dsCensus_0_croph25r5 ((NU8)0)
#define dsMarshal_0_croph25r5 ((NU8)1)
#define dsCallee_0_croph25r5 ((NU8)2)
#define dsArena_0_croph25r5 ((NU8)3)
#define dsAnalysis_0_croph25r5 ((NU8)4)
#define dsJit_0_croph25r5 ((NU8)5)
#define dsBuild_0_croph25r5 ((NU8)6)
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* analyzeRoutine_1_der823rwr1(NU32 sym_1, NI32 depth_1);
static inline string_0_sysvq0asl* getQ_0_I93d71y_der823rwr1(BiTable_0_Icvz6lt_buiyylk1h1 t_5, NU32 litId_1);
static inline ParamFacts_0_der823rwr1* getQ_7_Idvq35j1_der823rwr1(seq_0_Ipj3tye_der823rwr1 s_11, NI32 i_9);
static inline void add_0_I34il1q_der823rwr1(seq_0_In6doa_arecyyj7v* s_12, NU32 elem_2);
X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* getOrDefault_1_Ixytwrx1_der823rwr1(Table_0_Iyoauy01_der823rwr1 t_6, NU32 k_4, X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* fallback_1);
static inline seq_0_Ipj3tye_der823rwr1 newSeqUninit_0_Ijxkk69_der823rwr1(NI32 size_6);
static inline void add_0_Iq49bdb1_der823rwr1(seq_0_Ipj3tye_der823rwr1* s_15, ParamFacts_0_der823rwr1 elem_3);
void putQ_0_Itnkvom_der823rwr1(Table_0_Iyoauy01_der823rwr1* t_8, NU32 k_6, X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* v_2);
static inline seq_0_Ispzxr4_der823rwr1 newSeqUninit_0_Is5zvug1_der823rwr1(NI32 size_8);
static inline seq_0_Ikxuplm1_der823rwr1 newSeqUninit_0_Iie69x21_der823rwr1(NI32 size_10);
NI32 rawGet_0_Il0rzk71_der823rwr1(Table_0_Iyoauy01_der823rwr1 t_10, NU32 k_8, NU32 kh_1);
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* getQ_7_I14ceb_der823rwr1(seq_0_Ispzxr4_der823rwr1 s_22, NI32 i_14);
static inline NI32 memSizeInBytes_0_Iewu4mv1_der823rwr1(NI32 size_13);
static inline NI32 capInBytes_0_Ijpz55p1_der823rwr1(seq_0_Ipj3tye_der823rwr1 s_23);
NB8 resize_0_Ikria3j1_der823rwr1(seq_0_Ipj3tye_der823rwr1* dest_3, NI32 addedElements_3);
void rawPut_0_Isr2exp_der823rwr1(Table_0_Iyoauy01_der823rwr1* t_11, NU32 k_9, X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* v_4, NU32 h_3);
static inline NI32 memSizeInBytes_0_Ifd0mjk1_der823rwr1(NI32 size_14);
static inline NI32 memSizeInBytes_0_Ilp7p16_der823rwr1(NI32 size_15);
static inline NI32 len_3_Iuzfbwg1_der823rwr1(seq_0_Ispzxr4_der823rwr1 s_27);
static inline NI32 high_3_Iyuup9h1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_28);
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_29, NU32 i_17);
void fillHashPart_0_I4xxq0t1_der823rwr1(Table_0_Iyoauy01_der823rwr1* t_13);
static inline NI32 len_3_Iiefpcc1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_30);
static inline void add_0_I3ne3x81_der823rwr1(seq_0_Ispzxr4_der823rwr1* s_31, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1 elem_6);
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7);
seq_0_Ikxuplm1_der823rwr1 newSeq_0_Iv3lu2h1_der823rwr1(NI32 size_17);
static inline NI32 capInBytes_0_I09m9nj1_der823rwr1(seq_0_Ispzxr4_der823rwr1 s_34);
NB8 resize_0_Igv01r6_der823rwr1(seq_0_Ispzxr4_der823rwr1* dest_5, NI32 addedElements_5);
void eQdestroy_1_I5skmro_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_53);
void eQdestroyQ_SX50aramX46acts0der823rwr1_0_der823rwr1(ParamFacts_0_der823rwr1 dest_0);
void eQdestroyQ_SX53can0der823rwr1_0_der823rwr1(Scan_0_der823rwr1 dest_0);
void eQdestroyQ_SX54able0X49yoauy01_0_der823rwr1(Table_0_Iyoauy01_der823rwr1 dest_0);
void eQwasmovedQ_SX54able0X49yoauy01_0_der823rwr1(Table_0_Iyoauy01_der823rwr1* dest_0);
void eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* dest_0);
void eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1** dest_0);
X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* eQdupQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* src_0);
void eQwasmovedQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_der823rwr1(X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1* dest_0);
void eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_der823rwr1(X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 dest_0);
void eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1 dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern LongString_0_sysvq0asl const strlit_0_I8446236512461598146_croph25r5;
extern void bump_0_croph25r5(NI32 c_0, NI32 by_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern void noteItem_0_croph25r5(NI32 c_2, string_0_sysvq0asl item_0);
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37);
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33);
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82);
extern void eQdestroy_1_Iscb4i31_arecyyj7v(seq_0_In6doa_arecyyj7v s_81);
static inline seq_0_In6doa_arecyyj7v newSeqUninit_0_Ieodq4s1_arecyyj7v(NI32 size_28);
extern Local_0_decqocs071 takeLocal_0_decqocs071(Cursor_0_nifb6mq6y1* c_4, SkipMode_0_decqocs071 mode_0);
extern void eQdestroyQ_SX4cocal0decqocs071_0_decqocs071(Local_0_decqocs071* dest_0);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
extern LoadResult_0_prorcx25w1 tryLoadSymSafe_0_modzy18mg1(NU32 s_0);
static inline NimonySym_0_nimry5ra91 symKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_11);
static inline NB8 isRoutine_0_decqocs071(NimonySym_0_nimry5ra91 t_0);
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
extern Routine_0_decqocs071 asRoutine_0_decqocs071(Cursor_0_nifb6mq6y1 c_8, SkipMode_0_decqocs071 mode_3);
extern void eQdestroyQ_SX52outine0decqocs071_0_decqocs071(Routine_0_decqocs071* dest_0);
extern void declineNote_0_croph25r5(DeclineStage_0_croph25r5 stage_0, string_0_sysvq0asl reason_1);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline NI32 capInBytes_0_Iev6wua1_arecyyj7v(seq_0_In6doa_arecyyj7v s_89);
extern NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_arecyyj7v* dest_8, NI32 addedElements_8);
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2);
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0);
extern void resize_0_tabcr240b1(seq_0_Ikxuplm1_der823rwr1* t_0);
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
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
extern void X60Qini_0_tabcr240b1(void);
extern void X60Qini_0_croph25r5(void);
extern NI32 newRouteCounter_0_croph25r5(string_0_sysvq0asl name_0);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline NI32 memSizeInBytes_0_Ivqzo5x1_arecyyj7v(NI32 size_29);
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14);
static inline NB8 rawTagIsNimonySym_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_5);
static inline NU32 hash_2_has9tn57v(NU32 u_0);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16);
extern NU32 const ErrT_0_nifh7u8pu1;
LongString_0_sysvq0asl const strlit_0_I7700577950856589536_der823rwr1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "no-body"}
;
LongString_0_sysvq0asl const strlit_0_I6517805684605582485_der823rwr1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "method"}
;
LongString_0_sysvq0asl const strlit_0_I12821824867635071619_der823rwr1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "recursion"}
;
LongString_0_sysvq0asl const strlit_0_I11687695069464501825_der823rwr1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "depth"}
;
LongString_0_sysvq0asl const strlit_0_I11844399600601855873_der823rwr1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unmodelled-shape"}
;
LongString_0_sysvq0asl const strlit_0_I13965770315477080000_der823rwr1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "callee-unknown"}
;
LongString_0_sysvq0asl const strlit_0_I12426617750300075358_der823rwr1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "no-such-param"}
;
LongString_0_sysvq0asl const strlit_0_I12033249648675409453_der823rwr1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "no-field-name"}
;
LongString_0_sysvq0asl const strlit_0_I11574592732441186701_der823rwr1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.granted"}
;
LongString_0_sysvq0asl const strlit_0_I5028085522355536342_der823rwr1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.touched"}
;
LongString_0_sysvq0asl const strlit_0_I2383610246520674964_der823rwr1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.unknown"}
;
LongString_0_sysvq0asl const strlit_0_I6139412745867667785_der823rwr1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.noBody"}
;
LongString_0_sysvq0asl const strlit_0_I11741953360225786868_der823rwr1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.method"}
;
LongString_0_sysvq0asl const strlit_0_I12337066681093166662_der823rwr1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.recursion"}
;
LongString_0_sysvq0asl const strlit_0_I7642361806055897670_der823rwr1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.depth"}
;
LongString_0_sysvq0asl const strlit_0_I7024631262500088190_der823rwr1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.shape"}
;
LongString_0_sysvq0asl const strlit_0_I2839949493752707786_der823rwr1 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.calleeUnknown"}
;
LongString_0_sysvq0asl const strlit_0_I13963232378993663656_der823rwr1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.noParam"}
;
LongString_0_sysvq0asl const strlit_0_I4806146699330252585_der823rwr1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.noField"}
;
LongString_0_sysvq0asl const strlit_0_I14871862945109281425_der823rwr1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.honoured"}
;
LongString_0_sysvq0asl const strlit_0_I3166641380190870650_der823rwr1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan.revoked"}
;
LongString_0_sysvq0asl const strlit_0_I1707222714195181991_der823rwr1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "call"}
;
LongString_0_sysvq0asl const strlit_0_I9217337746930322866_der823rwr1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "callstrlit"}
;
LongString_0_sysvq0asl const strlit_0_I12061648672903694946_der823rwr1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hcall"}
;
LongString_0_sysvq0asl const strlit_0_I8390060478375454995_der823rwr1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "infix"}
;
LongString_0_sysvq0asl const strlit_0_I8954722698363393223_der823rwr1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "prefix"}
;
LongString_0_sysvq0asl const strlit_0_I4196580491060784277_der823rwr1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hderef"}
;
LongString_0_sysvq0asl const strlit_0_I8939511674443647382_der823rwr1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "deref"}
;
LongString_0_sysvq0asl const strlit_0_I14457488926480995039_der823rwr1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ddot"}
;
LongString_0_sysvq0asl const strlit_0_I6196012693010658506_der823rwr1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-unnamed-field"}
;
LongString_0_sysvq0asl const strlit_0_I9966780157259260886_der823rwr1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-obj"}
;
LongString_0_sysvq0asl const strlit_0_I15812448433220312006_der823rwr1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-rest"}
;
LongString_0_sysvq0asl const strlit_0_I12455351349982063882_der823rwr1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-indirect-callee"}
;
LongString_0_sysvq0asl const strlit_0_I15579204254611461655_der823rwr1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-arg"}
;
LongString_0_sysvq0asl const strlit_0_I5367917178860180580_der823rwr1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "params"}
;
LongString_0_sysvq0asl const strlit_0_I11863286937721830209_der823rwr1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "body"}
;
LongString_0_sysvq0asl const strlit_0_I8567886285254816433_der823rwr1 = {
  .fullLen_0 = 49, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "callee names the field (a property of the CALLEE)"}
;
LongString_0_sysvq0asl const strlit_0_I9045620134790905442_der823rwr1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "derefan cannot see: "}
;
LongString_0_sysvq0asl const strlit_0_I12933864966599503538_der823rwr1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " at "}
;
LongString_0_sysvq0asl const strlit_0_I10118323441081413360_der823rwr1 = {
  .fullLen_0 = 48, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " (a property of the ANALYSIS, not of the callee)"}
;
NI32 cAnGranted_0_der823rwr1;
NI32 cAnTouched_0_der823rwr1;
NI32 cAnUnknown_0_der823rwr1;
NI32 cAnNoBody_0_der823rwr1;
NI32 cAnMethod_0_der823rwr1;
NI32 cAnRecursion_0_der823rwr1;
NI32 cAnDepth_0_der823rwr1;
NI32 cAnShape_0_der823rwr1;
NI32 cAnCalleeUnknown_0_der823rwr1;
NI32 cAnNoParam_0_der823rwr1;
NI32 cAnNoField_0_der823rwr1;
NI32 cAnHonoured_0_der823rwr1;
NI32 cAnRevoked_0_der823rwr1;
Table_0_Iyoauy01_der823rwr1 factsCache_0_der823rwr1;
NB8 X60QiniGuard_0_der823rwr1;
string_0_sysvq0asl giveUpName_0_der823rwr1(AnGiveUp_0_der823rwr1 g_0){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  string_0_sysvq0asl X60Qx_0;
  nimStrWasMoved((&X60Qx_0));
  switch (g_0){
    case 0:
    {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 1852796670u, .more_0 = (&strlit_0_I8446236512461598146_croph25r5)}
      ;}
    break;
    case 1:
    {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 762277630u, .more_0 = (&strlit_0_I7700577950856589536_der823rwr1)}
      ;}
    break;
    case 2:
    {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_der823rwr1)}
      ;}
    break;
    case 3:
    {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 1667592958u, .more_0 = (&strlit_0_I12821824867635071619_der823rwr1)}
      ;}
    break;
    case 4:
    {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 1885693182u, .more_0 = (&strlit_0_I11687695069464501825_der823rwr1)}
      ;}
    break;
    case 5:
    {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 1835955710u, .more_0 = (&strlit_0_I11844399600601855873_der823rwr1)}
      ;}
    break;
    case 6:
    {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I13965770315477080000_der823rwr1)}
      ;}
    break;
    case 7:
    {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 762277630u, .more_0 = (&strlit_0_I12426617750300075358_der823rwr1)}
      ;}
    break;
    case 8:
    {
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 762277630u, .more_0 = (&strlit_0_I12033249648675409453_der823rwr1)}
      ;}
    break;}
  nimStrDestroy(result_1);
  result_1 = X60Qx_0;
  nimStrWasMoved((&X60Qx_0));
  nimStrDestroy(X60Qx_0);
  return result_1;
  nimStrDestroy(X60Qx_0);
  return result_1;}
void bumpGiveUp_0_der823rwr1(AnGiveUp_0_der823rwr1 g_1, string_0_sysvq0asl at_0){
  bump_0_croph25r5(cAnUnknown_0_der823rwr1, 1);
  switch (g_1){
    case 0:
    {
      }
    break;
    case 1:
    {
      bump_0_croph25r5(cAnNoBody_0_der823rwr1, 1);}
    break;
    case 2:
    {
      bump_0_croph25r5(cAnMethod_0_der823rwr1, 1);}
    break;
    case 3:
    {
      bump_0_croph25r5(cAnRecursion_0_der823rwr1, 1);}
    break;
    case 4:
    {
      bump_0_croph25r5(cAnDepth_0_der823rwr1, 1);}
    break;
    case 5:
    {
      bump_0_croph25r5(cAnShape_0_der823rwr1, 1);
      NI32 X60Qx_9 = len_4_sysvq0asl(at_0);
      if (0 < X60Qx_9){
        noteItem_0_croph25r5(cAnShape_0_der823rwr1, at_0);}}
    break;
    case 6:
    {
      bump_0_croph25r5(cAnCalleeUnknown_0_der823rwr1, 1);
      NI32 X60Qx_10 = len_4_sysvq0asl(at_0);
      if (0 < X60Qx_10){
        noteItem_0_croph25r5(cAnCalleeUnknown_0_der823rwr1, at_0);}}
    break;
    case 7:
    {
      bump_0_croph25r5(cAnNoParam_0_der823rwr1, 1);}
    break;
    case 8:
    {
      bump_0_croph25r5(cAnNoField_0_der823rwr1, 1);}
    break;}}
string_0_sysvq0asl nodeTag_0_der823rwr1(Cursor_0_nifb6mq6y1 n_0){
  string_0_sysvq0asl result_3;
  nimStrWasMoved((&result_3));
  nimStrDestroy(result_3);
  NU32 X60Qx_65 = tagId_0_nifb6mq6y1(n_0);
  string_0_sysvq0asl* X60Qx_66 = getQ_0_I93d71y_der823rwr1(pool_0_nifh7u8pu1.tags_0, X60Qx_65);
  string_0_sysvq0asl X60Qx_67 = nimStrDup((*X60Qx_66));
  result_3 = X60Qx_67;
  return result_3;}
NB8 isCallTag_0_der823rwr1(string_0_sysvq0asl t_0){
  NB8 result_4;
  NB8 X60Qx_68;
  NB8 X60Qx_69;
  NB8 X60Qx_70;
  NB8 X60Qx_71;
  NB8 X60Qx_72;
  NB8 X60Qx_73 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
    .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_der823rwr1)}
  );
  if (X60Qx_73){
    X60Qx_72 = NIM_TRUE;}
  else {
    NB8 X60Qx_74 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
      .bytes_0 = 1684890371u, .more_0 = NIM_NIL}
    );
    X60Qx_72 = X60Qx_74;}
  if (X60Qx_72){
    X60Qx_71 = NIM_TRUE;}
  else {
    NB8 X60Qx_75 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
      .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I9217337746930322866_der823rwr1)}
    );
    X60Qx_71 = X60Qx_75;}
  if (X60Qx_71){
    X60Qx_70 = NIM_TRUE;}
  else {
    NB8 X60Qx_76 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
      .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_der823rwr1)}
    );
    X60Qx_70 = X60Qx_76;}
  if (X60Qx_70){
    X60Qx_69 = NIM_TRUE;}
  else {
    NB8 X60Qx_77 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
      .bytes_0 = 1718512126u, .more_0 = (&strlit_0_I8390060478375454995_der823rwr1)}
    );
    X60Qx_69 = X60Qx_77;}
  if (X60Qx_69){
    X60Qx_68 = NIM_TRUE;}
  else {
    NB8 X60Qx_78 = eqQ_20_sysvq0asl(t_0, (string_0_sysvq0asl){
      .bytes_0 = 1701998846u, .more_0 = (&strlit_0_I8954722698363393223_der823rwr1)}
    );
    X60Qx_68 = X60Qx_78;}
  result_4 = X60Qx_68;
  return result_4;}
NI32 paramIndex_0_der823rwr1(Scan_0_der823rwr1 st_0, NU32 s_0){
  NI32 result_5;
  result_5 = -1;
  NI32 i_2 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_79 = len_3_I6y2imo_arecyyj7v(st_0.params_0);
      if (i_2 < X60Qx_79){
        NU32* X60Qx_80 = getQ_7_I2v00yv1_arecyyj7v(st_0.params_0, i_2);
        NB8 X60Qx_81 = eqQ_0_nifh7u8pu1((*X60Qx_80), s_0);
        if (X60Qx_81){
          return i_2;}
        inc_1_I6wjjge_aow2h993l1((&i_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_5;}
void markUnknown_0_der823rwr1(Scan_0_der823rwr1* st_1, NI32 i_0, AnGiveUp_0_der823rwr1 why_0, string_0_sysvq0asl at_1){
  NB8 X60Qx_82;
  if (i_0 < 0){
    X60Qx_82 = NIM_TRUE;}
  else {
    X60Qx_82 = ((*(*st_1).facts_0).d_00.params_0.len_0 <= i_0);}
  if (X60Qx_82){
    return;}
  ParamFacts_0_der823rwr1* X60Qx_83 = getQ_7_Idvq35j1_der823rwr1((*(*st_1).facts_0).d_00.params_0, i_0);
  if ((*X60Qx_83).unknown_0){
    return;}
  ParamFacts_0_der823rwr1* X60Qx_84 = getQ_7_Idvq35j1_der823rwr1((*(*st_1).facts_0).d_00.params_0, i_0);
  (*X60Qx_84).unknown_0 = NIM_TRUE;
  ParamFacts_0_der823rwr1* X60Qx_85 = getQ_7_Idvq35j1_der823rwr1((*(*st_1).facts_0).d_00.params_0, i_0);
  (*X60Qx_85).why_0 = why_0;
  ParamFacts_0_der823rwr1* X60Qx_86 = getQ_7_Idvq35j1_der823rwr1((*(*st_1).facts_0).d_00.params_0, i_0);
  string_0_sysvq0asl* X60Qlhs_0 = (&(*X60Qx_86).at_0);
  ParamFacts_0_der823rwr1* X60Qx_87 = getQ_7_Idvq35j1_der823rwr1((*(*st_1).facts_0).d_00.params_0, i_0);
  string_0_sysvq0asl X60Qlhs_1 = (*X60Qx_87).at_0;
  string_0_sysvq0asl X60Qx_88 = nimStrDup(at_1);
  (*X60Qlhs_0) = X60Qx_88;
  nimStrDestroy(X60Qlhs_1);}
void addTouched_0_der823rwr1(Scan_0_der823rwr1* st_2, NI32 i_1, NU32 f_0){
  NB8 X60Qx_89;
  if (i_1 < 0){
    X60Qx_89 = NIM_TRUE;}
  else {
    X60Qx_89 = ((*(*st_2).facts_0).d_00.params_0.len_0 <= i_1);}
  if (X60Qx_89){
    return;}
  NI32 k_0 = 0;
  {
    while (NIM_TRUE){
      ParamFacts_0_der823rwr1* X60Qx_90 = getQ_7_Idvq35j1_der823rwr1((*(*st_2).facts_0).d_00.params_0, i_1);
      NI32 X60Qx_91 = len_3_I6y2imo_arecyyj7v((*X60Qx_90).touched_0);
      if (k_0 < X60Qx_91){
        ParamFacts_0_der823rwr1* X60Qx_92 = getQ_7_Idvq35j1_der823rwr1((*(*st_2).facts_0).d_00.params_0, i_1);
        NU32* X60Qx_93 = getQ_7_I2v00yv1_arecyyj7v((*X60Qx_92).touched_0, k_0);
        NB8 X60Qx_94 = eqQ_0_nifh7u8pu1((*X60Qx_93), f_0);
        if (X60Qx_94){
          return;}
        inc_1_I6wjjge_aow2h993l1((&k_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  ParamFacts_0_der823rwr1* X60Qx_95 = getQ_7_Idvq35j1_der823rwr1((*(*st_2).facts_0).d_00.params_0, i_1);
  add_0_I34il1q_der823rwr1((&(*X60Qx_95).touched_0), f_0);}
void mergeCallee_0_der823rwr1(Scan_0_der823rwr1* st_3, NU32 fn_0, NI32 argIdx_0, NI32 myParam_0){
  if (((NI32)8) < ((NI32)((*st_3).depth_0 + 1))){
    markUnknown_0_der823rwr1(st_3, myParam_0, 4, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    return;}
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* sub_0 = analyzeRoutine_1_der823rwr1(fn_0, ((NI32)((*st_3).depth_0 + 1)));
  if (sub_0 == NIM_NIL){
    markUnknown_0_der823rwr1(st_3, myParam_0, 1, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(sub_0);
    return;}
  if ((!(*sub_0).d_00.ok_0)){
    markUnknown_0_der823rwr1(st_3, myParam_0, (*sub_0).d_00.why_0, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(sub_0);
    return;}
  if ((*sub_0).d_00.params_0.len_0 <= argIdx_0){
    markUnknown_0_der823rwr1(st_3, myParam_0, 7, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(sub_0);
    return;}
  ParamFacts_0_der823rwr1* X60Qx_96 = getQ_7_Idvq35j1_der823rwr1((*sub_0).d_00.params_0, argIdx_0);
  if ((*X60Qx_96).unknown_0){
    ParamFacts_0_der823rwr1* X60Qx_97 = getQ_7_Idvq35j1_der823rwr1((*sub_0).d_00.params_0, argIdx_0);
    string_0_sysvq0asl X60Qdesugar_16 = giveUpName_0_der823rwr1((*X60Qx_97).why_0);
    ParamFacts_0_der823rwr1* X60Qx_98 = getQ_7_Idvq35j1_der823rwr1((*sub_0).d_00.params_0, argIdx_0);
    string_0_sysvq0asl X60Qdesugar_17 = nimStrDup((*X60Qx_98).at_0);
    NI32 X60Qx_99 = len_4_sysvq0asl(X60Qdesugar_16);
    NI32 X60Qx_100 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 16385u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_101 = len_4_sysvq0asl(X60Qdesugar_17);
    string_0_sysvq0asl X60Qdesugar_18 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_99 + X60Qx_100)) + X60Qx_101)));
    add_2_sysvq0asl((&X60Qdesugar_18), X60Qdesugar_16);
    add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
      .bytes_0 = 16385u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_18), X60Qdesugar_17);
    markUnknown_0_der823rwr1(st_3, myParam_0, 6, X60Qdesugar_18);
    nimStrDestroy(X60Qdesugar_18);
    nimStrDestroy(X60Qdesugar_17);
    nimStrDestroy(X60Qdesugar_16);
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(sub_0);
    return;
    nimStrDestroy(X60Qdesugar_18);
    nimStrDestroy(X60Qdesugar_17);
    nimStrDestroy(X60Qdesugar_16);}
  NI32 k_1 = 0;
  {
    while (NIM_TRUE){
      ParamFacts_0_der823rwr1* X60Qx_102 = getQ_7_Idvq35j1_der823rwr1((*sub_0).d_00.params_0, argIdx_0);
      NI32 X60Qx_103 = len_3_I6y2imo_arecyyj7v((*X60Qx_102).touched_0);
      if (k_1 < X60Qx_103){
        ParamFacts_0_der823rwr1* X60Qx_104 = getQ_7_Idvq35j1_der823rwr1((*sub_0).d_00.params_0, argIdx_0);
        NU32* X60Qx_105 = getQ_7_I2v00yv1_arecyyj7v((*X60Qx_104).touched_0, k_1);
        addTouched_0_der823rwr1(st_3, myParam_0, (*X60Qx_105));
        inc_1_I6wjjge_aow2h993l1((&k_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(sub_0);}
Cursor_0_nifb6mq6y1 unwrapParamDeref_0_der823rwr1(Scan_0_der823rwr1 st_4, Cursor_0_nifb6mq6y1 n_1){
  Cursor_0_nifb6mq6y1 result_6;
  eQwasMoved_0_nifb6mq6y1((&result_6));
  eQdestroy_0_nifb6mq6y1((&result_6));
  Cursor_0_nifb6mq6y1 X60Qx_106 = eQdup_0_nifb6mq6y1(n_1);
  result_6 = X60Qx_106;
  NifKind_0_nif81dubp1 X60Qx_107 = kind_0_nifb6mq6y1(n_1);
  if ((!(X60Qx_107 == 11))){
    return result_6;}
  string_0_sysvq0asl t_2 = nodeTag_0_der823rwr1(n_1);
  NB8 X60Qx_108;
  NB8 X60Qx_109 = eqQ_20_sysvq0asl(t_2, (string_0_sysvq0asl){
    .bytes_0 = 1701079294u, .more_0 = (&strlit_0_I4196580491060784277_der823rwr1)}
  );
  if ((!X60Qx_109)){
    NB8 X60Qx_110 = eqQ_20_sysvq0asl(t_2, (string_0_sysvq0asl){
      .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I8939511674443647382_der823rwr1)}
    );
    X60Qx_108 = (!X60Qx_110);}
  else {
    X60Qx_108 = NIM_FALSE;}
  if (X60Qx_108){
    nimStrDestroy(t_2);
    return result_6;}
  Cursor_0_nifb6mq6y1 inner_0 = eQdup_0_nifb6mq6y1(n_1);
  inc_0_nifb6mq6y1((&inner_0));
  NifKind_0_nif81dubp1 X60Qx_111 = kind_0_nifb6mq6y1(inner_0);
  if ((!(X60Qx_111 == 4))){
    eQdestroy_0_nifb6mq6y1((&inner_0));
    nimStrDestroy(t_2);
    return result_6;}
  NU32 X60Qx_112 = symId_0_nifb6mq6y1(inner_0);
  NI32 X60Qx_113 = paramIndex_0_der823rwr1(st_4, X60Qx_112);
  if (X60Qx_113 < 0){
    eQdestroy_0_nifb6mq6y1((&inner_0));
    nimStrDestroy(t_2);
    return result_6;}
  Cursor_0_nifb6mq6y1 after_0 = eQdup_0_nifb6mq6y1(inner_0);
  skip_0_nifb6mq6y1((&after_0));
  NifKind_0_nif81dubp1 X60Qx_114 = kind_0_nifb6mq6y1(after_0);
  if ((!(X60Qx_114 == 12))){
    eQdestroy_0_nifb6mq6y1((&after_0));
    eQdestroy_0_nifb6mq6y1((&inner_0));
    nimStrDestroy(t_2);
    return result_6;}
  eQdestroy_0_nifb6mq6y1((&result_6));
  result_6 = inner_0;
  eQwasMoved_0_nifb6mq6y1((&inner_0));
  eQdestroy_0_nifb6mq6y1((&after_0));
  eQdestroy_0_nifb6mq6y1((&inner_0));
  nimStrDestroy(t_2);
  return result_6;
  eQdestroy_0_nifb6mq6y1((&after_0));
  eQdestroy_0_nifb6mq6y1((&inner_0));
  nimStrDestroy(t_2);
  return result_6;}
void walkTree_0_der823rwr1(Cursor_0_nifb6mq6y1 root_0, Scan_0_der823rwr1* st_5, string_0_sysvq0asl ctx_0){
  Cursor_0_nifb6mq6y1 c_0 = eQdup_0_nifb6mq6y1(root_0);
  NifKind_0_nif81dubp1 X60Qx_115 = kind_0_nifb6mq6y1(c_0);
  if (X60Qx_115 == 4){
    NU32 X60Qx_116 = symId_0_nifb6mq6y1(c_0);
    NI32 pi_0 = paramIndex_0_der823rwr1((*st_5), X60Qx_116);
    if (0 <= pi_0){
      markUnknown_0_der823rwr1(st_5, pi_0, 5, ctx_0);}
    eQdestroy_0_nifb6mq6y1((&c_0));
    return;}
  NifKind_0_nif81dubp1 X60Qx_117 = kind_0_nifb6mq6y1(c_0);
  if ((!(X60Qx_117 == 11))){
    eQdestroy_0_nifb6mq6y1((&c_0));
    return;}
  string_0_sysvq0asl tag_0 = nodeTag_0_der823rwr1(c_0);
  NB8 X60Qx_118;
  NB8 X60Qx_119 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1953457155u, .more_0 = NIM_NIL}
  );
  if (X60Qx_119){
    X60Qx_118 = NIM_TRUE;}
  else {
    NB8 X60Qx_120 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1868850430u, .more_0 = (&strlit_0_I14457488926480995039_der823rwr1)}
    );
    X60Qx_118 = X60Qx_120;}
  if (X60Qx_118){
    Cursor_0_nifb6mq6y1 f_1 = c_0;
    eQwasMoved_0_nifb6mq6y1((&c_0));
    inc_0_nifb6mq6y1((&f_1));
    Cursor_0_nifb6mq6y1 objn_0 = unwrapParamDeref_0_der823rwr1((*st_5), f_1);
    NifKind_0_nif81dubp1 X60Qx_121 = kind_0_nifb6mq6y1(objn_0);
    if (X60Qx_121 == 4){
      NU32 X60Qx_122 = symId_0_nifb6mq6y1(objn_0);
      NI32 pi_1 = paramIndex_0_der823rwr1((*st_5), X60Qx_122);
      if (0 <= pi_1){
        Cursor_0_nifb6mq6y1 g_2 = f_1;
        eQwasMoved_0_nifb6mq6y1((&f_1));
        skip_0_nifb6mq6y1((&g_2));
        NifKind_0_nif81dubp1 X60Qx_123 = kind_0_nifb6mq6y1(g_2);
        if (X60Qx_123 == 4){
          NU32 X60Qx_124 = symId_0_nifb6mq6y1(g_2);
          addTouched_0_der823rwr1(st_5, pi_1, X60Qx_124);}
        else {
          string_0_sysvq0asl X60Qtmp_2 = ampQ_0_sysvq0asl(tag_0, (string_0_sysvq0asl){
            .bytes_0 = 1853173246u, .more_0 = (&strlit_0_I6196012693010658506_der823rwr1)}
          );
          markUnknown_0_der823rwr1(st_5, pi_1, 5, X60Qtmp_2);
          nimStrDestroy(X60Qtmp_2);}
        eQdestroy_0_nifb6mq6y1((&g_2));
        eQdestroy_0_nifb6mq6y1((&objn_0));
        eQdestroy_0_nifb6mq6y1((&f_1));
        nimStrDestroy(tag_0);
        eQdestroy_0_nifb6mq6y1((&c_0));
        return;
        eQdestroy_0_nifb6mq6y1((&g_2));}}
    string_0_sysvq0asl X60Qtmp_3 = ampQ_0_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1651453438u, .more_0 = (&strlit_0_I9966780157259260886_der823rwr1)}
    );
    walkTree_0_der823rwr1(f_1, st_5, X60Qtmp_3);
    skip_0_nifb6mq6y1((&f_1));
    skip_0_nifb6mq6y1((&f_1));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_125 = kind_0_nifb6mq6y1(f_1);
        if ((!(X60Qx_125 == 12))){
          string_0_sysvq0asl X60Qtmp_4 = ampQ_0_sysvq0asl(tag_0, (string_0_sysvq0asl){
            .bytes_0 = 1701981694u, .more_0 = (&strlit_0_I15812448433220312006_der823rwr1)}
          );
          walkTree_0_der823rwr1(f_1, st_5, X60Qtmp_4);
          skip_0_nifb6mq6y1((&f_1));
          nimStrDestroy(X60Qtmp_4);}
        else {
          break;}}}
    whileStmtLabel_0: ;
    nimStrDestroy(X60Qtmp_3);
    eQdestroy_0_nifb6mq6y1((&objn_0));
    eQdestroy_0_nifb6mq6y1((&f_1));
    nimStrDestroy(tag_0);
    eQdestroy_0_nifb6mq6y1((&c_0));
    return;
    nimStrDestroy(X60Qtmp_3);
    eQdestroy_0_nifb6mq6y1((&objn_0));
    eQdestroy_0_nifb6mq6y1((&f_1));}
  NB8 X60Qx_126 = isCallTag_0_der823rwr1(tag_0);
  if (X60Qx_126){
    Cursor_0_nifb6mq6y1 f_2 = c_0;
    eQwasMoved_0_nifb6mq6y1((&c_0));
    inc_0_nifb6mq6y1((&f_2));
    NU32 fnSym_0 = ((NU32)0u);
    NB8 haveFn_0 = NIM_FALSE;
    NifKind_0_nif81dubp1 X60Qx_127 = kind_0_nifb6mq6y1(f_2);
    if (X60Qx_127 == 4){
      NU32 X60Qx_128 = symId_0_nifb6mq6y1(f_2);
      fnSym_0 = X60Qx_128;
      haveFn_0 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_5 = ampQ_0_sysvq0asl(tag_0, (string_0_sysvq0asl){
        .bytes_0 = 1852189955u, .more_0 = NIM_NIL}
      );
      walkTree_0_der823rwr1(f_2, st_5, X60Qtmp_5);
      nimStrDestroy(X60Qtmp_5);}
    skip_0_nifb6mq6y1((&f_2));
    NI32 argi_0 = 0;
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_129 = kind_0_nifb6mq6y1(f_2);
        if ((!(X60Qx_129 == 12))){
          Cursor_0_nifb6mq6y1 an_0 = unwrapParamDeref_0_der823rwr1((*st_5), f_2);
          NB8 X60Qx_130;
          NifKind_0_nif81dubp1 X60Qx_131 = kind_0_nifb6mq6y1(an_0);
          if (X60Qx_131 == 4){
            NU32 X60Qx_132 = symId_0_nifb6mq6y1(an_0);
            NI32 X60Qx_133 = paramIndex_0_der823rwr1((*st_5), X60Qx_132);
            X60Qx_130 = (0 <= X60Qx_133);}
          else {
            X60Qx_130 = NIM_FALSE;}
          if (X60Qx_130){
            NU32 X60Qx_134 = symId_0_nifb6mq6y1(an_0);
            NI32 pi_2 = paramIndex_0_der823rwr1((*st_5), X60Qx_134);
            if (haveFn_0){
              mergeCallee_0_der823rwr1(st_5, fnSym_0, argi_0, pi_2);}
            else {
              string_0_sysvq0asl X60Qtmp_6 = ampQ_0_sysvq0asl(tag_0, (string_0_sysvq0asl){
                .bytes_0 = 1852386814u, .more_0 = (&strlit_0_I12455351349982063882_der823rwr1)}
              );
              markUnknown_0_der823rwr1(st_5, pi_2, 5, X60Qtmp_6);
              nimStrDestroy(X60Qtmp_6);}}
          else {
            string_0_sysvq0asl X60Qtmp_7 = ampQ_0_sysvq0asl(tag_0, (string_0_sysvq0asl){
              .bytes_0 = 1918971390u, .more_0 = (&strlit_0_I15579204254611461655_der823rwr1)}
            );
            walkTree_0_der823rwr1(f_2, st_5, X60Qtmp_7);
            nimStrDestroy(X60Qtmp_7);}
          skip_0_nifb6mq6y1((&f_2));
          inc_1_I6wjjge_aow2h993l1((&argi_0));
          eQdestroy_0_nifb6mq6y1((&an_0));}
        else {
          break;}}}
    whileStmtLabel_1: ;
    eQdestroy_0_nifb6mq6y1((&f_2));
    nimStrDestroy(tag_0);
    eQdestroy_0_nifb6mq6y1((&c_0));
    return;
    eQdestroy_0_nifb6mq6y1((&f_2));}
  Cursor_0_nifb6mq6y1 f_3 = c_0;
  eQwasMoved_0_nifb6mq6y1((&c_0));
  inc_0_nifb6mq6y1((&f_3));
  NI32 ai_0 = 0;
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_135 = kind_0_nifb6mq6y1(f_3);
      if ((!(X60Qx_135 == 12))){
        string_0_sysvq0asl X60Qdesugar_19 = dollarQ_2_sysvq0asl(ai_0);
        NI32 X60Qx_136 = len_4_sysvq0asl(tag_0);
        NI32 X60Qx_137 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 23297u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_138 = len_4_sysvq0asl(X60Qdesugar_19);
        NI32 X60Qx_139 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 23809u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_20 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_136 + X60Qx_137)) + X60Qx_138)) + X60Qx_139)));
        add_2_sysvq0asl((&X60Qdesugar_20), tag_0);
        add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
          .bytes_0 = 23297u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_20), X60Qdesugar_19);
        add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
          .bytes_0 = 23809u, .more_0 = NIM_NIL}
        );
        walkTree_0_der823rwr1(f_3, st_5, X60Qdesugar_20);
        skip_0_nifb6mq6y1((&f_3));
        inc_1_I6wjjge_aow2h993l1((&ai_0));
        nimStrDestroy(X60Qdesugar_20);
        nimStrDestroy(X60Qdesugar_19);}
      else {
        break;}}}
  whileStmtLabel_2: ;
  eQdestroy_0_nifb6mq6y1((&f_3));
  nimStrDestroy(tag_0);
  eQdestroy_0_nifb6mq6y1((&c_0));}
seq_0_In6doa_arecyyj7v collectParams_0_der823rwr1(Routine_0_decqocs071* r_0){
  seq_0_In6doa_arecyyj7v result_7;
  eQwasMoved_1_I2k4kel_arecyyj7v((&result_7));
  eQdestroy_1_Iscb4i31_arecyyj7v(result_7);
  seq_0_In6doa_arecyyj7v X60Qx_140 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
  result_7 = X60Qx_140;
  Cursor_0_nifb6mq6y1 pc_0 = eQdup_0_nifb6mq6y1((*r_0).params_0);
  NB8 X60Qx_8;
  NifKind_0_nif81dubp1 X60Qx_141 = kind_0_nifb6mq6y1(pc_0);
  if (X60Qx_141 == 11){
    string_0_sysvq0asl X60Qtmp_8 = nodeTag_0_der823rwr1(pc_0);
    NB8 X60Qx_142 = eqQ_20_sysvq0asl(X60Qtmp_8, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_der823rwr1)}
    );
    X60Qx_8 = X60Qx_142;
    nimStrDestroy(X60Qtmp_8);}
  else {
    X60Qx_8 = NIM_FALSE;}
  if (X60Qx_8){
    inc_0_nifb6mq6y1((&pc_0));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_143 = kind_0_nifb6mq6y1(pc_0);
        if ((!(X60Qx_143 == 12))){
          NifKind_0_nif81dubp1 X60Qx_144 = kind_0_nifb6mq6y1(pc_0);
          if (X60Qx_144 == 11){
            Local_0_decqocs071 loc_0 = takeLocal_0_decqocs071((&pc_0), 2);
            NU32 nm_0 = ((NU32)0u);
            NB8 X60Qx_145;
            NifKind_0_nif81dubp1 X60Qx_146 = kind_0_nifb6mq6y1(loc_0.name_0);
            if (X60Qx_146 == 4){
              X60Qx_145 = NIM_TRUE;}
            else {
              NifKind_0_nif81dubp1 X60Qx_147 = kind_0_nifb6mq6y1(loc_0.name_0);
              X60Qx_145 = (X60Qx_147 == 5);}
            if (X60Qx_145){
              NU32 X60Qx_148 = symId_0_nifb6mq6y1(loc_0.name_0);
              nm_0 = X60Qx_148;}
            add_0_I34il1q_der823rwr1((&result_7), nm_0);
            eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_0));}
          else {
            skip_0_nifb6mq6y1((&pc_0));}}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  eQdestroy_0_nifb6mq6y1((&pc_0));
  return result_7;
  eQdestroy_0_nifb6mq6y1((&pc_0));
  return result_7;}
X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* analyzeRoutine_1_der823rwr1(NU32 sym_1, NI32 depth_1){
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* result_8;
  eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((&result_8));
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(result_8);
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_149 = getOrDefault_1_Ixytwrx1_der823rwr1(factsCache_0_der823rwr1, sym_1, NIM_NIL);
  result_8 = X60Qx_149;
  if ((!(result_8 == NIM_NIL))){
    return result_8;}
  if (((NI32)8) < depth_1){
    void* X60Qx_150 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1));
    X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qtmp_9 = ((X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1*)X60Qx_150);
    seq_0_Ipj3tye_der823rwr1 X60Qx_151 = newSeqUninit_0_Ijxkk69_der823rwr1(0);
    (*X60Qtmp_9) = (X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1){
      .r_00 = 0, .d_00 = (RoutineFacts_Obj_0_der823rwr1){
        .ok_0 = NIM_FALSE, .why_0 = 4, .params_0 = X60Qx_151}}
    ;
    result_8 = X60Qtmp_9;
    return result_8;}
  LoadResult_0_prorcx25w1 res_0 = tryLoadSymSafe_0_modzy18mg1(sym_1);
  NB8 X60Qx_152;
  NB8 X60Qx_153;
  if ((!(res_0.status_0 == 3))){
    X60Qx_153 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_154 = kind_0_nifb6mq6y1(res_0.decl_0);
    X60Qx_153 = (!(X60Qx_154 == 11));}
  if (X60Qx_153){
    X60Qx_152 = NIM_TRUE;}
  else {
    NimonySym_0_nimry5ra91 X60Qx_155 = symKind_0_nim30udrv(res_0.decl_0);
    NB8 X60Qx_156 = isRoutine_0_decqocs071(X60Qx_155);
    X60Qx_152 = (!X60Qx_156);}
  if (X60Qx_152){
    void* X60Qx_157 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1));
    X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qtmp_10 = ((X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1*)X60Qx_157);
    seq_0_Ipj3tye_der823rwr1 X60Qx_158 = newSeqUninit_0_Ijxkk69_der823rwr1(0);
    (*X60Qtmp_10) = (X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1){
      .r_00 = 0, .d_00 = (RoutineFacts_Obj_0_der823rwr1){
        .ok_0 = NIM_FALSE, .why_0 = 1, .params_0 = X60Qx_158}}
    ;
    result_8 = X60Qtmp_10;
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    return result_8;}
  string_0_sysvq0asl X60Qtmp_11 = nodeTag_0_der823rwr1(res_0.decl_0);
  NB8 X60Qx_159 = eqQ_20_sysvq0asl(X60Qtmp_11, (string_0_sysvq0asl){
    .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_der823rwr1)}
  );
  if (X60Qx_159){
    void* X60Qx_160 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1));
    X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qtmp_12 = ((X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1*)X60Qx_160);
    seq_0_Ipj3tye_der823rwr1 X60Qx_161 = newSeqUninit_0_Ijxkk69_der823rwr1(0);
    (*X60Qtmp_12) = (X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1){
      .r_00 = 0, .d_00 = (RoutineFacts_Obj_0_der823rwr1){
        .ok_0 = NIM_FALSE, .why_0 = 2, .params_0 = X60Qx_161}}
    ;
    result_8 = X60Qtmp_12;
    nimStrDestroy(X60Qtmp_11);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    return result_8;}
  Routine_0_decqocs071 r_1 = asRoutine_0_decqocs071(res_0.decl_0, 1);
  NifKind_0_nif81dubp1 X60Qx_162 = kind_0_nifb6mq6y1(r_1.body_0);
  if ((!(X60Qx_162 == 11))){
    void* X60Qx_163 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1));
    X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qtmp_13 = ((X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1*)X60Qx_163);
    seq_0_Ipj3tye_der823rwr1 X60Qx_164 = newSeqUninit_0_Ijxkk69_der823rwr1(0);
    (*X60Qtmp_13) = (X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1){
      .r_00 = 0, .d_00 = (RoutineFacts_Obj_0_der823rwr1){
        .ok_0 = NIM_FALSE, .why_0 = 1, .params_0 = X60Qx_164}}
    ;
    result_8 = X60Qtmp_13;
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
    nimStrDestroy(X60Qtmp_11);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    return result_8;}
  seq_0_In6doa_arecyyj7v X60Qx_165 = collectParams_0_der823rwr1((&r_1));
  Scan_0_der823rwr1 st_6 = (Scan_0_der823rwr1){
    .params_0 = X60Qx_165, .facts_0 = NIM_NIL, .depth_0 = depth_1}
  ;
  void* X60Qx_166 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1));
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qtmp_14 = ((X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1*)X60Qx_166);
  seq_0_Ipj3tye_der823rwr1 X60Qx_167 = newSeqUninit_0_Ijxkk69_der823rwr1(0);
  (*X60Qtmp_14) = (X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1){
    .r_00 = 0, .d_00 = (RoutineFacts_Obj_0_der823rwr1){
      .ok_0 = NIM_TRUE, .why_0 = 0, .params_0 = X60Qx_167}}
  ;
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* f_4 = X60Qtmp_14;
  NI32 i_5 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_168 = len_3_I6y2imo_arecyyj7v(st_6.params_0);
      if (i_5 < X60Qx_168){
        seq_0_In6doa_arecyyj7v X60Qx_169 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
        add_0_Iq49bdb1_der823rwr1((&(*f_4).d_00.params_0), (ParamFacts_0_der823rwr1){
          .unknown_0 = NIM_FALSE, .why_0 = 0, .at_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .touched_0 = X60Qx_169}
        );
        inc_1_I6wjjge_aow2h993l1((&i_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1** X60Qlhs_15 = (&st_6.facts_0);
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((*X60Qlhs_15));
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_170 = eQdupQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_4);
  (*X60Qlhs_15) = X60Qx_170;
  void* X60Qx_171 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1));
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qtmp_16 = ((X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1*)X60Qx_171);
  seq_0_Ipj3tye_der823rwr1 X60Qx_172 = newSeqUninit_0_Ijxkk69_der823rwr1(0);
  (*X60Qtmp_16) = (X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1){
    .r_00 = 0, .d_00 = (RoutineFacts_Obj_0_der823rwr1){
      .ok_0 = NIM_FALSE, .why_0 = 3, .params_0 = X60Qx_172}}
  ;
  putQ_0_Itnkvom_der823rwr1((&factsCache_0_der823rwr1), sym_1, X60Qtmp_16);
  walkTree_0_der823rwr1(r_1.body_0, (&st_6), (string_0_sysvq0asl){
    .bytes_0 = 1685021438u, .more_0 = (&strlit_0_I11863286937721830209_der823rwr1)}
  );
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_173 = eQdupQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_4);
  putQ_0_Itnkvom_der823rwr1((&factsCache_0_der823rwr1), sym_1, X60Qx_173);
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(result_8);
  result_8 = f_4;
  eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((&f_4));
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_4);
  eQdestroyQ_SX53can0der823rwr1_0_der823rwr1(st_6);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
  nimStrDestroy(X60Qtmp_11);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_8;
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_4);
  eQdestroyQ_SX53can0der823rwr1_0_der823rwr1(st_6);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
  nimStrDestroy(X60Qtmp_11);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_8;}
X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 fieldVerdict_0_der823rwr1(NU32 calleeSym_0, NI32 paramIdx_0, NU32 fieldSym_0){
  X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 result_10;
  eQwasmovedQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_der823rwr1((&result_10));
  if (((NU32)fieldSym_0) == ((NU32)0u)){
    result_10 = (X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1){
      .fld_0 = 2, .fld_1 = 8, .fld_2 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}}
    ;
    return result_10;}
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* f_5 = analyzeRoutine_1_der823rwr1(calleeSym_0, 0);
  if (f_5 == NIM_NIL){
    result_10 = (X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1){
      .fld_0 = 2, .fld_1 = 1, .fld_2 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}}
    ;
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_5);
    return result_10;}
  if ((!(*f_5).d_00.ok_0)){
    result_10 = (X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1){
      .fld_0 = 2, .fld_1 = (*f_5).d_00.why_0, .fld_2 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}}
    ;
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_5);
    return result_10;}
  NB8 X60Qx_174;
  if (paramIdx_0 < 0){
    X60Qx_174 = NIM_TRUE;}
  else {
    X60Qx_174 = ((*f_5).d_00.params_0.len_0 <= paramIdx_0);}
  if (X60Qx_174){
    result_10 = (X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1){
      .fld_0 = 2, .fld_1 = 7, .fld_2 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}}
    ;
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_5);
    return result_10;}
  ParamFacts_0_der823rwr1* X60Qx_175 = getQ_7_Idvq35j1_der823rwr1((*f_5).d_00.params_0, paramIdx_0);
  if ((*X60Qx_175).unknown_0){
    ParamFacts_0_der823rwr1* X60Qx_176 = getQ_7_Idvq35j1_der823rwr1((*f_5).d_00.params_0, paramIdx_0);
    ParamFacts_0_der823rwr1* X60Qx_177 = getQ_7_Idvq35j1_der823rwr1((*f_5).d_00.params_0, paramIdx_0);
    string_0_sysvq0asl X60Qx_178 = nimStrDup((*X60Qx_177).at_0);
    result_10 = (X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1){
      .fld_0 = 2, .fld_1 = (*X60Qx_176).why_0, .fld_2 = X60Qx_178}
    ;
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_5);
    return result_10;}
  NI32 i_6 = 0;
  {
    while (NIM_TRUE){
      ParamFacts_0_der823rwr1* X60Qx_179 = getQ_7_Idvq35j1_der823rwr1((*f_5).d_00.params_0, paramIdx_0);
      NI32 X60Qx_180 = len_3_I6y2imo_arecyyj7v((*X60Qx_179).touched_0);
      if (i_6 < X60Qx_180){
        ParamFacts_0_der823rwr1* X60Qx_181 = getQ_7_Idvq35j1_der823rwr1((*f_5).d_00.params_0, paramIdx_0);
        NU32* X60Qx_182 = getQ_7_I2v00yv1_arecyyj7v((*X60Qx_181).touched_0, i_6);
        NB8 X60Qx_183 = eqQ_0_nifh7u8pu1((*X60Qx_182), fieldSym_0);
        if (X60Qx_183){
          result_10 = (X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1){
            .fld_0 = 1, .fld_1 = 0, .fld_2 = (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}}
          ;
          eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_5);
          return result_10;}
        inc_1_I6wjjge_aow2h993l1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_der823rwr1(result_10);
  result_10 = (X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1){
    .fld_0 = 0, .fld_1 = 0, .fld_2 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}}
  ;
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_5);
  return result_10;
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(f_5);
  return result_10;}
NB8 fieldNeverTouched_0_der823rwr1(NU32 calleeSym_1, NI32 paramIdx_1, NU32 fieldSym_1){
  NB8 result_11;
  X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 X60Qtmptup_0 = fieldVerdict_0_der823rwr1(calleeSym_1, paramIdx_1, fieldSym_1);
  AnVerdict_0_der823rwr1 v_1 = X60Qtmptup_0.fld_0;
  AnGiveUp_0_der823rwr1 why_1 = X60Qtmptup_0.fld_1;
  string_0_sysvq0asl at_2 = X60Qtmptup_0.fld_2;
  nimStrWasMoved((&X60Qtmptup_0.fld_2));
  switch (v_1){
    case 0:
    {
      bump_0_croph25r5(cAnGranted_0_der823rwr1, 1);
      result_11 = NIM_TRUE;}
    break;
    case 1:
    {
      bump_0_croph25r5(cAnTouched_0_der823rwr1, 1);
      declineNote_0_croph25r5(4, (string_0_sysvq0asl){
        .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I8567886285254816433_der823rwr1)}
      );
      result_11 = NIM_FALSE;}
    break;
    case 2:
    {
      bumpGiveUp_0_der823rwr1(why_1, at_2);
      string_0_sysvq0asl X60Qtmp_17 = giveUpName_0_der823rwr1(why_1);
      string_0_sysvq0asl msg_0 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I9045620134790905442_der823rwr1)}
      , X60Qtmp_17);
      NI32 X60Qx_184 = len_4_sysvq0asl(at_2);
      if (0 < X60Qx_184){
        string_0_sysvq0asl X60Qtmp_18 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1952522494u, .more_0 = (&strlit_0_I12933864966599503538_der823rwr1)}
        , at_2);
        add_2_sysvq0asl((&msg_0), X60Qtmp_18);
        nimStrDestroy(X60Qtmp_18);}
      add_2_sysvq0asl((&msg_0), (string_0_sysvq0asl){
        .bytes_0 = 1630019838u, .more_0 = (&strlit_0_I10118323441081413360_der823rwr1)}
      );
      declineNote_0_croph25r5(4, msg_0);
      result_11 = NIM_FALSE;
      nimStrDestroy(msg_0);
      nimStrDestroy(X60Qtmp_17);}
    break;}
  nimStrDestroy(at_2);
  eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_der823rwr1(X60Qtmptup_0);
  return result_11;
  nimStrDestroy(at_2);
  eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_der823rwr1(X60Qtmptup_0);
  return result_11;}
Table_0_Iyoauy01_der823rwr1 initTable_0_I5rhh7r1_der823rwr1(void){
  Table_0_Iyoauy01_der823rwr1 result_12;
  eQwasmovedQ_SX54able0X49yoauy01_0_der823rwr1((&result_12));
  eQdestroyQ_SX54able0X49yoauy01_0_der823rwr1(result_12);
  seq_0_Ispzxr4_der823rwr1 X60Qx_185 = newSeqUninit_0_Is5zvug1_der823rwr1(0);
  seq_0_Ikxuplm1_der823rwr1 X60Qx_186 = newSeqUninit_0_Iie69x21_der823rwr1(0);
  result_12 = (Table_0_Iyoauy01_der823rwr1){
    .data_0 = X60Qx_185, .hashes_0 = X60Qx_186}
  ;
  return result_12;}
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
static inline ParamFacts_0_der823rwr1* getQ_7_Idvq35j1_der823rwr1(seq_0_Ipj3tye_der823rwr1 s_11, NI32 i_9){
  NB8 X60Qx_189;
  if (i_9 < s_11.len_0){
    X60Qx_189 = (0 <= i_9);}
  else {
    X60Qx_189 = NIM_FALSE;}
  if ((!X60Qx_189)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  ParamFacts_0_der823rwr1* result_17;
  result_17 = (&s_11.data_0[i_9]);
  return result_17;}
static inline void add_0_I34il1q_der823rwr1(seq_0_In6doa_arecyyj7v* s_12, NU32 elem_2){
  NI32 L_0 = (*s_12).len_0;
  NI32 X60Qx_190 = capInBytes_0_Iev6wua1_arecyyj7v((*s_12));
  if (X60Qx_190 < ((NI32)(((NI32)(L_0 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_191 = resize_0_I6ho9ve_buiyylk1h1(s_12, 1);
    if ((!X60Qx_191)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_12).len_0));
  (*s_12).data_0[L_0] = elem_2;}
X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* getOrDefault_1_Ixytwrx1_der823rwr1(Table_0_Iyoauy01_der823rwr1 t_6, NU32 k_4, X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* fallback_1){
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* result_19;
  eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((&result_19));
  NU32 X60Qx_194 = hash_0_nifh7u8pu1(k_4);
  NI32 idx_1 = rawGet_0_Il0rzk71_der823rwr1(t_6, k_4, X60Qx_194);
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_1;
  eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((&X60Qx_1));
  if (0 <= idx_1){
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qx_1);
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_195 = getQ_7_I14ceb_der823rwr1(t_6.data_0, idx_1);
    X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_196 = eQdupQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((*X60Qx_195).fld_1);
    X60Qx_1 = X60Qx_196;}
  else {
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qx_1);
    X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_197 = eQdupQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(fallback_1);
    X60Qx_1 = X60Qx_197;}
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(result_19);
  result_19 = X60Qx_1;
  eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((&X60Qx_1));
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qx_1);
  return result_19;
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qx_1);
  return result_19;}
static inline seq_0_Ipj3tye_der823rwr1 newSeqUninit_0_Ijxkk69_der823rwr1(NI32 size_6){
  seq_0_Ipj3tye_der823rwr1 result_20;
  if (size_6 == 0){
    result_20 = (seq_0_Ipj3tye_der823rwr1){
      .len_0 = size_6, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Iewu4mv1_der823rwr1(size_6);
    void* X60Qx_198 = alloc_1_sysvq0asl(memSize_1);
    result_20 = (seq_0_Ipj3tye_der823rwr1){
      .len_0 = size_6, .data_0 = ((ParamFacts_0_der823rwr1*)X60Qx_198)}
    ;
    if ((!(result_20.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_199 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_20.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_20;}
static inline void add_0_Iq49bdb1_der823rwr1(seq_0_Ipj3tye_der823rwr1* s_15, ParamFacts_0_der823rwr1 elem_3){
  NI32 L_1 = (*s_15).len_0;
  NI32 X60Qx_200 = capInBytes_0_Ijpz55p1_der823rwr1((*s_15));
  if (X60Qx_200 < ((NI32)(((NI32)(L_1 * sizeof(ParamFacts_0_der823rwr1))) + sizeof(ParamFacts_0_der823rwr1)))){
    NB8 X60Qx_201 = resize_0_Ikria3j1_der823rwr1(s_15, 1);
    if ((!X60Qx_201)){
      eQdestroyQ_SX50aramX46acts0der823rwr1_0_der823rwr1(elem_3);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_15).len_0));
  (*s_15).data_0[L_1] = elem_3;}
void putQ_0_Itnkvom_der823rwr1(Table_0_Iyoauy01_der823rwr1* t_8, NU32 k_6, X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* v_2){
  NU32 h_0 = hash_0_nifh7u8pu1(k_6);
  NI32 idx_2 = rawGet_0_Il0rzk71_der823rwr1((*t_8), k_6, h_0);
  if (0 <= idx_2){
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_202 = getQ_7_I14ceb_der823rwr1((*t_8).data_0, idx_2);
    X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1** X60Qlhs_19 = (&(*X60Qx_202).fld_1);
    X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qlhs_20 = v_2;
    eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((&v_2));
    eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((*X60Qlhs_19));
    (*X60Qlhs_19) = X60Qlhs_20;}
  else {
    X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qtmp_21 = v_2;
    eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((&v_2));
    rawPut_0_Isr2exp_der823rwr1(t_8, k_6, X60Qtmp_21, h_0);}
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(v_2);}
static inline seq_0_Ispzxr4_der823rwr1 newSeqUninit_0_Is5zvug1_der823rwr1(NI32 size_8){
  seq_0_Ispzxr4_der823rwr1 result_21;
  if (size_8 == 0){
    result_21 = (seq_0_Ispzxr4_der823rwr1){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Ifd0mjk1_der823rwr1(size_8);
    void* X60Qx_203 = alloc_1_sysvq0asl(memSize_2);
    result_21 = (seq_0_Ispzxr4_der823rwr1){
      .len_0 = size_8, .data_0 = ((X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1*)X60Qx_203)}
    ;
    if ((!(result_21.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_204 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_21.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_21;}
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
NI32 rawGet_0_Il0rzk71_der823rwr1(Table_0_Iyoauy01_der823rwr1 t_10, NU32 k_8, NU32 kh_1){
  NI32 result_27;
  NI32 X60Qx_211 = len_3_Iuzfbwg1_der823rwr1(t_10.data_0);
  if (X60Qx_211 <= ((NI32)4)){
    {
      NI32 X60Qlf_0 = 0;
      NI32 X60Qlf_1 = len_3_Iuzfbwg1_der823rwr1(t_10.data_0);
      NI32 X60Qlf_2 = X60Qlf_0;
      {
        while (X60Qlf_2 < X60Qlf_1){
          {
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_212 = getQ_7_I14ceb_der823rwr1(t_10.data_0, X60Qlf_2);
            NB8 X60Qx_213 = eqQ_0_nifh7u8pu1((*X60Qx_212).fld_0, k_8);
            if (X60Qx_213){
              return X60Qlf_2;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_214 = high_3_Iyuup9h1_der823rwr1(t_10.hashes_0);
    NU32 h_2 = ((NU32)(kh_1 & ((NU32)X60Qx_214)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_215 = getQ_8_Imt2zi01_der823rwr1(t_10.hashes_0, h_2);
        NB8 X60Qx_216 = isFilled_0_tabcr240b1((*X60Qx_215));
        if (X60Qx_216){
          HashEntry_0_tabcr240b1* X60Qx_217 = getQ_8_Imt2zi01_der823rwr1(t_10.hashes_0, h_2);
          HashEntry_0_tabcr240b1 d_0 = (*X60Qx_217);
          NB8 X60Qx_218;
          if (d_0.fullhash_0 == kh_1){
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_219 = getQ_7_I14ceb_der823rwr1(t_10.data_0, ((NI32)(d_0.position_0 - 1)));
            NB8 X60Qx_220 = eqQ_0_nifh7u8pu1((*X60Qx_219).fld_0, k_8);
            X60Qx_218 = X60Qx_220;}
          else {
            X60Qx_218 = NIM_FALSE;}
          if (X60Qx_218){
            result_27 = ((NI32)(d_0.position_0 - 1));
            return result_27;}
          NI32 X60Qx_221 = high_3_Iyuup9h1_der823rwr1(t_10.hashes_0);
          NU32 X60Qx_222 = nextTry_0_has9tn57v(h_2, X60Qx_221);
          h_2 = X60Qx_222;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_27 = -1;
  return result_27;}
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* getQ_7_I14ceb_der823rwr1(seq_0_Ispzxr4_der823rwr1 s_22, NI32 i_14){
  NB8 X60Qx_223;
  if (i_14 < s_22.len_0){
    X60Qx_223 = (0 <= i_14);}
  else {
    X60Qx_223 = NIM_FALSE;}
  if ((!X60Qx_223)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* result_28;
  result_28 = (&s_22.data_0[i_14]);
  return result_28;}
static inline NI32 memSizeInBytes_0_Iewu4mv1_der823rwr1(NI32 size_13){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_29;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_13, sizeof(ParamFacts_0_der823rwr1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_29 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_29 = ((NI32)2147483647);}
  return result_29;}
static inline NI32 capInBytes_0_Ijpz55p1_der823rwr1(seq_0_Ipj3tye_der823rwr1 s_23){
  NI32 result_30;
  NI32 X60Qx_3;
  if ((!(s_23.data_0 == NIM_NIL))){
    NI32 X60Qx_224 = allocatedSize_0_sysvq0asl(((void*)((void*)s_23.data_0)));
    X60Qx_3 = X60Qx_224;}
  else {
    X60Qx_3 = 0;}
  result_30 = X60Qx_3;
  return result_30;}
NB8 resize_0_Ikria3j1_der823rwr1(seq_0_Ipj3tye_der823rwr1* dest_3, NI32 addedElements_3){
  NB8 result_31;
  NI32 X60Qx_225 = capInBytes_0_Ijpz55p1_der823rwr1((*dest_3));
  NI32 oldCap_1 = ((NI32)(X60Qx_225 / sizeof(ParamFacts_0_der823rwr1)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_3);
  NI32 memSize_5 = memSizeInBytes_0_Iewu4mv1_der823rwr1(newCap_1);
  void* X60Qx_226 = realloc_1_sysvq0asl(((void*)((void*)(*dest_3).data_0)), memSize_5);
  (*dest_3).data_0 = ((ParamFacts_0_der823rwr1*)X60Qx_226);
  if ((*dest_3).data_0 == NIM_NIL){
    (*dest_3).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_5);
    result_31 = NIM_FALSE;}
  else {
    result_31 = NIM_TRUE;}
  return result_31;}
void rawPut_0_Isr2exp_der823rwr1(Table_0_Iyoauy01_der823rwr1* t_11, NU32 k_9, X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* v_4, NU32 h_3){
  NI32 X60Qx_227 = len_3_Iuzfbwg1_der823rwr1((*t_11).data_0);
  if (X60Qx_227 == ((NI32)4)){
    fillHashPart_0_I4xxq0t1_der823rwr1(t_11);}
  else {
    NI32 X60Qx_228 = len_3_Iiefpcc1_der823rwr1((*t_11).hashes_0);
    NI32 X60Qx_229 = len_3_Iuzfbwg1_der823rwr1((*t_11).data_0);
    NB8 X60Qx_230 = mustRehash_0_tabcr240b1(X60Qx_228, X60Qx_229);
    if (X60Qx_230){
      resize_0_tabcr240b1((&(*t_11).hashes_0));}}
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qtmp_22 = v_4;
  eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((&v_4));
  add_0_I3ne3x81_der823rwr1((&(*t_11).data_0), (X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1){
    .fld_0 = k_9, .fld_1 = X60Qtmp_22}
  );
  NI32 X60Qx_231 = high_3_Iyuup9h1_der823rwr1((*t_11).hashes_0);
  NU32 hi_0 = ((NU32)(h_3 & ((NU32)X60Qx_231)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_232 = getQ_8_Imt2zi01_der823rwr1((*t_11).hashes_0, hi_0);
      NB8 X60Qx_233 = isFilled_0_tabcr240b1((*X60Qx_232));
      if (X60Qx_233){
        NI32 X60Qx_234 = high_3_Iyuup9h1_der823rwr1((*t_11).hashes_0);
        NU32 X60Qx_235 = nextTry_0_has9tn57v(hi_0, X60Qx_234);
        hi_0 = X60Qx_235;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_236 = len_3_Iuzfbwg1_der823rwr1((*t_11).data_0);
  putQ_8_Ipchg2a_der823rwr1((&(*t_11).hashes_0), hi_0, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_3, .position_0 = X60Qx_236}
  );
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(v_4);}
static inline NI32 memSizeInBytes_0_Ifd0mjk1_der823rwr1(NI32 size_14){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_32;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_14, sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_32 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_32 = ((NI32)2147483647);}
  return result_32;}
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
static inline NI32 len_3_Iuzfbwg1_der823rwr1(seq_0_Ispzxr4_der823rwr1 s_27){
  NI32 result_34;
  result_34 = s_27.len_0;
  return result_34;}
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
void fillHashPart_0_I4xxq0t1_der823rwr1(Table_0_Iyoauy01_der823rwr1* t_13){
  seq_0_Ikxuplm1_der823rwr1* X60Qlhs_23 = (&(*t_13).hashes_0);
  eQdestroy_1_I5skmro_der823rwr1((*X60Qlhs_23));
  seq_0_Ikxuplm1_der823rwr1 X60Qx_237 = newSeq_0_Iv3lu2h1_der823rwr1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_23) = X60Qx_237;
  {
    NI32 X60Qlf_3 = 0;
    NI32 X60Qlf_4 = len_3_Iuzfbwg1_der823rwr1((*t_13).data_0);
    NI32 X60Qlf_5 = X60Qlf_3;
    {
      while (X60Qlf_5 < X60Qlf_4){
        {
          X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* X60Qx_238 = getQ_7_I14ceb_der823rwr1((*t_13).data_0, X60Qlf_5);
          NU32 X60Qii_2 = hash_0_nifh7u8pu1((*X60Qx_238).fld_0);
          NI32 X60Qx_239 = high_3_Iyuup9h1_der823rwr1((*t_13).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_239)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_240 = getQ_8_Imt2zi01_der823rwr1((*t_13).hashes_0, X60Qii_3);
            NB8 X60Qx_241 = isFilled_0_tabcr240b1((*X60Qx_240));
            if (X60Qx_241){
              NI32 X60Qx_242 = high_3_Iyuup9h1_der823rwr1((*t_13).hashes_0);
              NU32 X60Qx_243 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_242);
              X60Qii_3 = X60Qx_243;}
            else {
              break;}}
          putQ_8_Ipchg2a_der823rwr1((&(*t_13).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_5 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline NI32 len_3_Iiefpcc1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_30){
  NI32 result_37;
  result_37 = s_30.len_0;
  return result_37;}
static inline void add_0_I3ne3x81_der823rwr1(seq_0_Ispzxr4_der823rwr1* s_31, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1 elem_6){
  NI32 L_2 = (*s_31).len_0;
  NI32 X60Qx_244 = capInBytes_0_I09m9nj1_der823rwr1((*s_31));
  if (X60Qx_244 < ((NI32)(((NI32)(L_2 * sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1))) + sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1)))){
    NB8 X60Qx_245 = resize_0_Igv01r6_der823rwr1(s_31, 1);
    if ((!X60Qx_245)){
      eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(elem_6);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_31).len_0));
  (*s_31).data_0[L_2] = elem_6;}
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7){
  if ((!(i_19 < ((NU32)(*s_33).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_33).data_0[((NI32)i_19)] = elem_7;}
seq_0_Ikxuplm1_der823rwr1 newSeq_0_Iv3lu2h1_der823rwr1(NI32 size_17){
  seq_0_Ikxuplm1_der823rwr1 result_38;
  if (size_17 == 0){
    result_38 = (seq_0_Ikxuplm1_der823rwr1){
      .len_0 = size_17, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_6 = memSizeInBytes_0_Ilp7p16_der823rwr1(size_17);
    void* X60Qx_246 = alloc_1_sysvq0asl(memSize_6);
    result_38 = (seq_0_Ikxuplm1_der823rwr1){
      .len_0 = size_17, .data_0 = ((HashEntry_0_tabcr240b1*)X60Qx_246)}
    ;
    if ((!(result_38.data_0 == NIM_NIL))){
      NI32 i_20 = 0;
      {
        while (i_20 < size_17){
          result_38.data_0[i_20] = (HashEntry_0_tabcr240b1){
            .fullhash_0 = ((NU32)0u), .position_0 = ((NI32)0)}
          ;
          inc_1_I6wjjge_aow2h993l1((&i_20));}}
      whileStmtLabel_0: ;}
    else {
      result_38.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_6);}}
  return result_38;}
static inline NI32 capInBytes_0_I09m9nj1_der823rwr1(seq_0_Ispzxr4_der823rwr1 s_34){
  NI32 result_39;
  NI32 X60Qx_4;
  if ((!(s_34.data_0 == NIM_NIL))){
    NI32 X60Qx_247 = allocatedSize_0_sysvq0asl(((void*)((void*)s_34.data_0)));
    X60Qx_4 = X60Qx_247;}
  else {
    X60Qx_4 = 0;}
  result_39 = X60Qx_4;
  return result_39;}
NB8 resize_0_Igv01r6_der823rwr1(seq_0_Ispzxr4_der823rwr1* dest_5, NI32 addedElements_5){
  NB8 result_40;
  NI32 X60Qx_248 = capInBytes_0_I09m9nj1_der823rwr1((*dest_5));
  NI32 oldCap_2 = ((NI32)(X60Qx_248 / sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_5);
  NI32 memSize_7 = memSizeInBytes_0_Ifd0mjk1_der823rwr1(newCap_2);
  void* X60Qx_249 = realloc_1_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_7);
  (*dest_5).data_0 = ((X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1*)X60Qx_249);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_7);
    result_40 = NIM_FALSE;}
  else {
    result_40 = NIM_TRUE;}
  return result_40;}
void eQdestroy_1_Id27w511_der823rwr1(seq_0_Ipj3tye_der823rwr1 s_49){
  if ((!(s_49.data_0 == NIM_NIL))){
    NI32 i_25 = 0;
    {
      while (i_25 < s_49.len_0){
        eQdestroyQ_SX50aramX46acts0der823rwr1_0_der823rwr1(s_49.data_0[i_25]);
        inc_1_I6wjjge_aow2h993l1((&i_25));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_49.data_0)));}}
void eQdestroy_1_I6jqpn5_der823rwr1(seq_0_Ispzxr4_der823rwr1 s_51){
  if ((!(s_51.data_0 == NIM_NIL))){
    NI32 i_29 = 0;
    {
      while (i_29 < s_51.len_0){
        eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(s_51.data_0[i_29]);
        inc_1_I6wjjge_aow2h993l1((&i_29));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_51.data_0)));}}
static inline void eQwasMoved_1_Iyzx95e1_der823rwr1(seq_0_Ispzxr4_der823rwr1* s_52){
  (*s_52).len_0 = 0;
  (*s_52).data_0 = NIM_NIL;}
void eQdestroy_1_I5skmro_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_53){
  if ((!(s_53.data_0 == NIM_NIL))){
    NI32 i_33 = 0;
    {
      while (i_33 < s_53.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_33));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_53.data_0)));}}
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
void eQdestroyQ_SX50aramX46acts0der823rwr1_0_der823rwr1(ParamFacts_0_der823rwr1 dest_0){
  eQdestroy_1_Iscb4i31_arecyyj7v(dest_0.touched_0);
  nimStrDestroy(dest_0.at_0);}
void eQdestroyQ_SX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(RoutineFacts_Obj_0_der823rwr1 dest_0){
  eQdestroy_1_Id27w511_der823rwr1(dest_0.params_0);}
void eQdestroyQ_SX53can0der823rwr1_0_der823rwr1(Scan_0_der823rwr1 dest_0){
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(dest_0.facts_0);
  eQdestroy_1_Iscb4i31_arecyyj7v(dest_0.params_0);}
void eQdestroyQ_SX54able0X49yoauy01_0_der823rwr1(Table_0_Iyoauy01_der823rwr1 dest_0){
  eQdestroy_1_I5skmro_der823rwr1(dest_0.hashes_0);
  eQdestroy_1_I6jqpn5_der823rwr1(dest_0.data_0);}
void eQwasmovedQ_SX54able0X49yoauy01_0_der823rwr1(Table_0_Iyoauy01_der823rwr1* dest_0){
  eQwasMoved_1_Iyzx95e1_der823rwr1((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_der823rwr1((&(*dest_0).hashes_0));}
void eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* dest_0){
  if (dest_0){
    NB8 X60Qx_297 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_297){
      eQdestroyQ_SX52outineX46actsX4fbj0der823rwr1_0_der823rwr1((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* eQdupQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* src_0){
  X60Qt_0_IArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQwasmovedQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_der823rwr1(X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1* dest_0){
  nimStrWasMoved((&(*dest_0).fld_2));}
void eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_der823rwr1(X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 dest_0){
  nimStrDestroy(dest_0.fld_2);}
void eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX52outineX46actsX4fbj0der823rwr1_der823rwr1 dest_0){
  eQdestroyQ_ArefSX52outineX46actsX4fbj0der823rwr1_0_der823rwr1(dest_0.fld_1);}
void X60Qini_0_der823rwr1(void){
  if (X60QiniGuard_0_der823rwr1){
    return;}
  X60QiniGuard_0_der823rwr1 = NIM_TRUE;
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
  X60Qini_0_tabcr240b1();
  X60Qini_0_croph25r5();
  cAnGranted_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I11574592732441186701_der823rwr1)}
  );
  cAnTouched_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I5028085522355536342_der823rwr1)}
  );
  cAnUnknown_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I2383610246520674964_der823rwr1)}
  );
  cAnNoBody_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I6139412745867667785_der823rwr1)}
  );
  cAnMethod_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I11741953360225786868_der823rwr1)}
  );
  cAnRecursion_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I12337066681093166662_der823rwr1)}
  );
  cAnDepth_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I7642361806055897670_der823rwr1)}
  );
  cAnShape_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I7024631262500088190_der823rwr1)}
  );
  cAnCalleeUnknown_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I2839949493752707786_der823rwr1)}
  );
  cAnNoParam_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I13963232378993663656_der823rwr1)}
  );
  cAnNoField_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I4806146699330252585_der823rwr1)}
  );
  cAnHonoured_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I14871862945109281425_der823rwr1)}
  );
  cAnRevoked_0_der823rwr1 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I3166641380190870650_der823rwr1)}
  );
  factsCache_0_der823rwr1 = initTable_0_I5rhh7r1_der823rwr1();}
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
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13){
  NU32 result_16;
  PackedToken_0_nifh7u8pu1 X60Qx_36 = load_0_nifb6mq6y1(c_13);
  NU32 X60Qx_37 = tagId_0_nifh7u8pu1(X60Qx_36);
  result_16 = X60Qx_37;
  return result_16;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37){
  NI32 result_34;
  result_34 = s_37.len_0;
  return result_34;}
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
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
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
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
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
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82){
  (*s_82).len_0 = 0;
  (*s_82).data_0 = NIM_NIL;}
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
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0){
  NU32 result_11;
  NU32 X60Qx_20 = hash_2_has9tn57v(x_0);
  result_11 = X60Qx_20;
  return result_11;}
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2){
  NB8 result_1;
  result_1 = (0 < a_2.position_0);
  return result_1;}
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0){
  NU32 result_14;
  result_14 = ((NU32)(((NU32)(h_2 + 1u)) & ((NU32)maxHash_0)));
  return result_14;}
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
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0){
  NB8 result_0;
  NB8 X60Qx_2;
  if (length_0 < ((NI32)(((NI32)(counter_0 / 2)) + counter_0))){
    X60Qx_2 = NIM_TRUE;}
  else {
    X60Qx_2 = (((NI32)(length_0 - counter_0)) < 4);}
  result_0 = X60Qx_2;
  return result_0;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
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
