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
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1 X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1;
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1 X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct seq_0_Iflf8jf1_aow7lb5cq1{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_aow7lb5cq1;
typedef struct FileCov_Obj_0_obs4v9ato1{
  string_0_sysvq0asl name_0;
  seq_0_Ift2sne_aow7lb5cq1 hits_0;
  seq_0_Iflf8jf1_aow7lb5cq1 known_0;}
FileCov_Obj_0_obs4v9ato1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct BranchSite_Obj_0_obs4v9ato1{
  string_0_sysvq0asl file_0;
  NI32 line_0;
  string_0_sysvq0asl form_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 labels_0;
  seq_0_Ift2sne_aow7lb5cq1 counts_0;}
BranchSite_Obj_0_obs4v9ato1;
typedef struct seq_0_Icfzt52_obs4v9ato1{
  NI32 len_0;
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1** data_0;}
seq_0_Icfzt52_obs4v9ato1;
typedef struct seq_0_Iivvdd91_obs4v9ato1{
  NI32 len_0;
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* data_0;}
seq_0_Iivvdd91_obs4v9ato1;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
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
typedef struct seq_0_Ix7ee6h_obs4v9ato1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* data_0;}
seq_0_Ix7ee6h_obs4v9ato1;
typedef struct Table_0_Idzlvr_obs4v9ato1{
  seq_0_Ix7ee6h_obs4v9ato1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Idzlvr_obs4v9ato1;
typedef struct Sampler_Obj_0_obs4v9ato1{
  NI32 interval_0;
  NI32 counter_0;
  NI32 steps_0;
  NI32 samples_0;
  Table_0_Idzlvr_obs4v9ato1 stacks_0;
  Table_0_Idzlvr_obs4v9ato1 selfC_0;
  Table_0_Idzlvr_obs4v9ato1 totalC_0;}
Sampler_Obj_0_obs4v9ato1;
typedef struct openArray_0_I6d7wnv1_obs4v9ato1{
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1** a_0;
  NI32 len_0;}
openArray_0_I6d7wnv1_obs4v9ato1;
typedef struct openArray_0_Ijlsgol1_obs4v9ato1{
  X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1** a_0;
  NI32 len_0;}
openArray_0_Ijlsgol1_obs4v9ato1;
typedef struct openArray_0_Ig73pnk_aow7lb5cq1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_aow7lb5cq1;
typedef struct openArray_0_Inqs7yx_aow7lb5cq1{
  NI32* a_0;
  NI32 len_0;}
openArray_0_Inqs7yx_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1{
  NI r_00;
  FileCov_Obj_0_obs4v9ato1 d_00;}
X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1;
typedef struct X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1{
  NI r_00;
  BranchSite_Obj_0_obs4v9ato1 d_00;}
X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1;
typedef struct X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax{
  NI r_00;
  Coverage_Obj_0_obs4v9ato1 d_00;}
X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax;
typedef struct X60Qt_0_IArefSX53amplerX4fbj0obs4v9ato1_intzsnzax{
  NI r_00;
  Sampler_Obj_0_obs4v9ato1 d_00;}
X60Qt_0_IArefSX53amplerX4fbj0obs4v9ato1_intzsnzax;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax;
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1{
  NI32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline NI32 len_3_I040hpi1_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1 s_29);
static inline X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1** getQ_7_Ip11xd9_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1 s_30, NI32 i_13);
static inline void add_0_Ilbvamp1_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1* s_31, X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* elem_8);
NI32 getOrDefault_1_I03027c1_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1 t_5, NI32 k_7, NI32 fallback_2);
static inline void add_0_Ic6dly71_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1* s_43, X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* elem_13);
static inline NI32 len_3_Inbysyn_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1 s_45);
void putQ_0_Icmdioe1_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1* t_7, NI32 k_9, NI32 v_2);
static inline X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1** getQ_7_I7my8px1_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1 s_46, NI32 i_18);
NI32 getOrDefault_1_Iwgckf31_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1 t_9, string_0_sysvq0asl k_11, NI32 fallback_3);
void putQ_0_Ix03xxw_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1* t_11, string_0_sysvq0asl k_13, NI32 v_4);
static inline NI32 capInBytes_0_Ik3d83k1_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1 s_63);
NB8 resize_0_I3k0qzd_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1* dest_5, NI32 addedElements_5);
NI32 rawGet_0_Ixeuwkk_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1 t_14, NI32 k_15, NU32 kh_2);
static inline X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* getQ_7_Ime3143_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1 s_69, NI32 i_30);
static inline NI32 capInBytes_0_Isiozph_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1 s_70);
NB8 resize_0_Inz4czs_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1* dest_8, NI32 addedElements_8);
void rawPut_0_Ir4gd8s1_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1* t_15, NI32 k_16, NI32 v_6, NU32 h_5);
static inline seq_0_Ix7ee6h_obs4v9ato1 newSeqUninit_0_Ig5459y1_obs4v9ato1(NI32 size_27);
NI32 rawGet_0_Ik917wh_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1 t_17, string_0_sysvq0asl k_17, NU32 kh_3);
static inline X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* getQ_7_Ioesyu2_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1 s_79, NI32 i_33);
void rawPut_0_Isxoisv_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1* t_18, string_0_sysvq0asl k_18, NI32 v_7, NU32 h_7);
static inline NI32 len_3_Ixb1ads1_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1 s_81);
static inline NI32 len_3_Iqf4r13_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1 s_82);
void fillHashPart_0_Ii9f097_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1* t_20);
static inline void add_0_Imd0elh_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1* s_86, X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 elem_19);
static inline NI32 memSizeInBytes_0_Ivx6m0g1_obs4v9ato1(NI32 size_32);
void fillHashPart_0_Ietaba01_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1* t_21);
static inline void add_0_I2s2mnd_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1* s_89, X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax elem_21);
static inline NI32 capInBytes_0_Ikzjb2e1_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1 s_91);
NB8 resize_0_Ikxsgd91_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1* dest_12, NI32 addedElements_12);
static inline NI32 capInBytes_0_Igxyzwi_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1 s_92);
NB8 resize_0_Itvz7wg_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1* dest_13, NI32 addedElements_13);
void eQdestroyQ_SX54able0X49r2mg111_0_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1 dest_0);
void eQdestroyQ_SX54able0X49dzlvr_0_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1 dest_0);
void eQwasmovedQ_SX54able0X49dzlvr_0_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1* dest_0);
void eQdestroyQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1(X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* dest_0);
void eQdestroyQ_ArefSX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1(X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* dest_0);
X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* eQdupQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1(X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* src_0);
X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* eQdupQ_ArefSX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1(X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* src_0);
void eQdestroyQ_AtupleSstring0sysvq0aslAiS32_0_obs4v9ato1(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax dest_0);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10);
static inline seq_0_Iflf8jf1_aow7lb5cq1 newSeqUninit_0_I5mozxi1_aow7lb5cq1(NI32 size_14);
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45);
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13);
static inline void add_0_Irnc3p1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_53, NB8 elem_16);
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_36);
static inline void putQ_7_Ifvyck5_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_52, NI32 i_38, NI32 elem_15);
static inline void putQ_7_Iiblebk_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_56, NI32 i_40, NB8 elem_17);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
extern seq_0_Ixdx2fh1_aow7lb5cq1 eQdup_1_Imq0s4c_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 a_41);
static inline void eQwasMoved_1_Ix88qzs1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_95);
extern void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_41);
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_28);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline NU32 hash_5_has9tn57v(NI32 x_2);
static inline seq_0_Ikxuplm1_der823rwr1 newSeqUninit_0_Iie69x21_der823rwr1(NI32 size_10);
extern NU32 hash_1_has9tn57v(string_0_sysvq0asl s_0);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 high_3_Iyuup9h1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_28);
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_29, NU32 i_17);
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2);
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0);
static inline NI32 len_3_Iiefpcc1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_30);
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0);
extern void resize_0_tabcr240b1(seq_0_Ikxuplm1_der823rwr1* t_0);
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern void eQdestroy_1_I5skmro_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_53);
extern seq_0_Ikxuplm1_der823rwr1 newSeq_0_Iv3lu2h1_der823rwr1(NI32 size_17);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_I7a20g9_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_100);
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tabcr240b1(void);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20);
static inline NI32 memSizeInBytes_0_Ih4q01h_aow7lb5cq1(NI32 size_22);
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68);
extern NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8);
static inline NI32 capInBytes_0_In1m6ni_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_70);
extern NB8 resize_0_I2yw78g1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* dest_10, NI32 addedElements_10);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
static inline NI32 memSizeInBytes_0_Ilp7p16_der823rwr1(NI32 size_15);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
LongString_0_sysvq0asl const strlit_0_I4092267118630528849_obs4v9ato1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(top level)"}
;
LongString_0_sysvq0asl const strlit_0_I409803864855967452_obs4v9ato1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<anon>"}
;
NB8 X60QiniGuard_0_obs4v9ato1;
NI32 fileIdx_0_obs4v9ato1(X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax* c_0, string_0_sysvq0asl name_0){
  NI32 result_1;
  NB8 X60Qx_22;
  NB8 X60Qx_23 = eqQ_20_sysvq0asl(name_0, (*c_0).d_00.lastName_0);
  if (X60Qx_23){
    X60Qx_22 = (0 <= (*c_0).d_00.lastIdx_0);}
  else {
    X60Qx_22 = NIM_FALSE;}
  if (X60Qx_22){
    result_1 = (*c_0).d_00.lastIdx_0;
    return result_1;}
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_24 = len_3_I040hpi1_obs4v9ato1((*c_0).d_00.files_0);
      if (i_0 < X60Qx_24){
        X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1** X60Qx_25 = getQ_7_Ip11xd9_obs4v9ato1((*c_0).d_00.files_0, i_0);
        NB8 X60Qx_26 = eqQ_20_sysvq0asl((*(*X60Qx_25)).d_00.name_0, name_0);
        if (X60Qx_26){
          string_0_sysvq0asl* X60Qlhs_1 = (&(*c_0).d_00.lastName_0);
          string_0_sysvq0asl X60Qlhs_2 = (*c_0).d_00.lastName_0;
          string_0_sysvq0asl X60Qx_27 = nimStrDup(name_0);
          (*X60Qlhs_1) = X60Qx_27;
          nimStrDestroy(X60Qlhs_2);
          (*c_0).d_00.lastIdx_0 = i_0;
          return i_0;}
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  void* X60Qx_28 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1));
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* X60Qtmp_3 = ((X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1*)X60Qx_28);
  string_0_sysvq0asl X60Qx_29 = nimStrDup(name_0);
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_30 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  seq_0_Iflf8jf1_aow7lb5cq1 X60Qx_31 = newSeqUninit_0_I5mozxi1_aow7lb5cq1(0);
  (*X60Qtmp_3) = (X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1){
    .r_00 = 0, .d_00 = (FileCov_Obj_0_obs4v9ato1){
      .name_0 = X60Qx_29, .hits_0 = X60Qx_30, .known_0 = X60Qx_31}}
  ;
  add_0_Ilbvamp1_obs4v9ato1((&(*c_0).d_00.files_0), X60Qtmp_3);
  string_0_sysvq0asl* X60Qlhs_4 = (&(*c_0).d_00.lastName_0);
  string_0_sysvq0asl X60Qlhs_5 = (*c_0).d_00.lastName_0;
  string_0_sysvq0asl X60Qx_32 = nimStrDup(name_0);
  (*X60Qlhs_4) = X60Qx_32;
  nimStrDestroy(X60Qlhs_5);
  NI32 X60Qx_33 = len_3_I040hpi1_obs4v9ato1((*c_0).d_00.files_0);
  (*c_0).d_00.lastIdx_0 = ((NI32)(X60Qx_33 - 1));
  result_1 = (*c_0).d_00.lastIdx_0;
  return result_1;}
void covHit_0_obs4v9ato1(X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax* c_1, string_0_sysvq0asl file_0, NI32 line_0){
  if (line_0 <= 0){
    return;}
  NI32 X60Qx_34 = fileIdx_0_obs4v9ato1(c_1, file_0);
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1** X60Qx_35 = getQ_7_Ip11xd9_obs4v9ato1((*c_1).d_00.files_0, X60Qx_34);
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* f_0 = eQdupQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1((*X60Qx_35));
  {
    while (NIM_TRUE){
      NI32 X60Qx_36 = len_3_I0v1j8d_aow7lb5cq1((*f_0).d_00.hits_0);
      if (X60Qx_36 <= line_0){
        add_0_I8kd4i4_aow7lb5cq1((&(*f_0).d_00.hits_0), 0);
        add_0_Irnc3p1_aow7lb5cq1((&(*f_0).d_00.known_0), NIM_FALSE);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32* X60Qx_37 = getQ_7_Ir8kccm_aow7lb5cq1((*f_0).d_00.hits_0, line_0);
  putQ_7_Ifvyck5_aow7lb5cq1((&(*f_0).d_00.hits_0), line_0, ((NI32)((*X60Qx_37) + 1)));
  putQ_7_Iiblebk_aow7lb5cq1((&(*f_0).d_00.known_0), line_0, NIM_TRUE);
  eQdestroyQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1(f_0);}
void covKnown_0_obs4v9ato1(X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax* c_2, string_0_sysvq0asl file_1, NI32 line_1){
  if (line_1 <= 0){
    return;}
  NI32 X60Qx_38 = fileIdx_0_obs4v9ato1(c_2, file_1);
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1** X60Qx_39 = getQ_7_Ip11xd9_obs4v9ato1((*c_2).d_00.files_0, X60Qx_38);
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* f_1 = eQdupQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1((*X60Qx_39));
  {
    while (NIM_TRUE){
      NI32 X60Qx_40 = len_3_I0v1j8d_aow7lb5cq1((*f_1).d_00.hits_0);
      if (X60Qx_40 <= line_1){
        add_0_I8kd4i4_aow7lb5cq1((&(*f_1).d_00.hits_0), 0);
        add_0_Irnc3p1_aow7lb5cq1((&(*f_1).d_00.known_0), NIM_FALSE);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  putQ_7_Iiblebk_aow7lb5cq1((&(*f_1).d_00.known_0), line_1, NIM_TRUE);
  eQdestroyQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1(f_1);}
NI32 covSite_0_obs4v9ato1(X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax* c_3, NI32 site_0, string_0_sysvq0asl file_2, NI32 line_2, string_0_sysvq0asl form_0, seq_0_Ixdx2fh1_aow7lb5cq1 labels_0){
  NI32 result_2;
  NI32 existing_0 = getOrDefault_1_I03027c1_obs4v9ato1((*c_3).d_00.siteIdx_0, site_0, -1);
  if (0 <= existing_0){
    return existing_0;}
  seq_0_Ift2sne_aow7lb5cq1 counts_0 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  NI32 i_5 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_41 = len_3_Ixq6taz_aow7lb5cq1(labels_0);
      if (i_5 < X60Qx_41){
        add_0_I8kd4i4_aow7lb5cq1((&counts_0), 0);
        inc_1_I6wjjge_aow2h993l1((&i_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  void* X60Qx_42 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1));
  X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* X60Qtmp_6 = ((X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1*)X60Qx_42);
  string_0_sysvq0asl X60Qx_15 = nimStrDup(file_2);
  string_0_sysvq0asl X60Qx_16 = nimStrDup(form_0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_17 = eQdup_1_Imq0s4c_aow7lb5cq1(labels_0);
  seq_0_Ift2sne_aow7lb5cq1 X60Qtmp_7 = counts_0;
  eQwasMoved_1_Ix88qzs1_aow7lb5cq1((&counts_0));
  (*X60Qtmp_6) = (X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1){
    .r_00 = 0, .d_00 = (BranchSite_Obj_0_obs4v9ato1){
      .file_0 = X60Qx_15, .line_0 = line_2, .form_0 = X60Qx_16, .labels_0 = X60Qx_17, .counts_0 = X60Qtmp_7}}
  ;
  add_0_Ic6dly71_obs4v9ato1((&(*c_3).d_00.sites_0), X60Qtmp_6);
  NI32 X60Qx_43 = len_3_Inbysyn_obs4v9ato1((*c_3).d_00.sites_0);
  NI32 idx_0 = ((NI32)(X60Qx_43 - 1));
  putQ_0_Icmdioe1_obs4v9ato1((&(*c_3).d_00.siteIdx_0), site_0, idx_0);
  result_2 = idx_0;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(counts_0);
  return result_2;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(counts_0);
  return result_2;}
void covArm_0_obs4v9ato1(X60Qt_0_IArefSX43overageX4fbj0obs4v9ato1_intzsnzax* c_4, NI32 siteIndex_0, NI32 arm_0){
  NB8 X60Qx_44;
  if (siteIndex_0 < 0){
    X60Qx_44 = NIM_TRUE;}
  else {
    X60Qx_44 = ((*c_4).d_00.sites_0.len_0 <= siteIndex_0);}
  if (X60Qx_44){
    return;}
  X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1** X60Qx_45 = getQ_7_I7my8px1_obs4v9ato1((*c_4).d_00.sites_0, siteIndex_0);
  X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* s_16 = eQdupQ_ArefSX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1((*X60Qx_45));
  NB8 X60Qx_46;
  if (arm_0 < 0){
    X60Qx_46 = NIM_TRUE;}
  else {
    X60Qx_46 = ((*s_16).d_00.counts_0.len_0 <= arm_0);}
  if (X60Qx_46){
    eQdestroyQ_ArefSX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1(s_16);
    return;}
  NI32* X60Qx_47 = getQ_7_Ir8kccm_aow7lb5cq1((*s_16).d_00.counts_0, arm_0);
  putQ_7_Ifvyck5_aow7lb5cq1((&(*s_16).d_00.counts_0), arm_0, ((NI32)((*X60Qx_47) + 1)));
  eQdestroyQ_ArefSX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1(s_16);}
NB8 tick_0_obs4v9ato1(X60Qt_0_IArefSX53amplerX4fbj0obs4v9ato1_intzsnzax* s_0){
  NB8 result_7;
  (*s_0).d_00.steps_0 = ((NI32)((*s_0).d_00.steps_0 + 1));
  (*s_0).d_00.counter_0 = ((NI32)((*s_0).d_00.counter_0 + 1));
  if ((*s_0).d_00.interval_0 <= (*s_0).d_00.counter_0){
    (*s_0).d_00.counter_0 = 0;
    result_7 = NIM_TRUE;}
  else {
    result_7 = NIM_FALSE;}
  return result_7;}
void addSample_0_obs4v9ato1(X60Qt_0_IArefSX53amplerX4fbj0obs4v9ato1_intzsnzax* s_1, seq_0_Ixdx2fh1_aow7lb5cq1 stack_0){
  (*s_1).d_00.samples_0 = ((NI32)((*s_1).d_00.samples_0 + 1));
  string_0_sysvq0asl key_0 = nimStrDup((string_0_sysvq0asl){
    .bytes_0 = 1869883646u, .more_0 = (&strlit_0_I4092267118630528849_obs4v9ato1)}
  );
  NI32 i_10 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_147 = len_3_Ixq6taz_aow7lb5cq1(stack_0);
      if (i_10 < X60Qx_147){
        string_0_sysvq0asl X60Qx_1;
        nimStrWasMoved((&X60Qx_1));
        string_0_sysvq0asl* X60Qx_148 = getQ_7_Ir6d0tw_aow7lb5cq1(stack_0, i_10);
        NI32 X60Qx_149 = len_4_sysvq0asl((*X60Qx_148));
        if (0 < X60Qx_149){
          nimStrDestroy(X60Qx_1);
          string_0_sysvq0asl* X60Qx_150 = getQ_7_Ir6d0tw_aow7lb5cq1(stack_0, i_10);
          string_0_sysvq0asl X60Qx_151 = nimStrDup((*X60Qx_150));
          X60Qx_1 = X60Qx_151;}
        else {
          nimStrDestroy(X60Qx_1);
          X60Qx_1 = (string_0_sysvq0asl){
            .bytes_0 = 1851866366u, .more_0 = (&strlit_0_I409803864855967452_obs4v9ato1)}
          ;}
        string_0_sysvq0asl nm_0 = X60Qx_1;
        nimStrWasMoved((&X60Qx_1));
        add_2_sysvq0asl((&key_0), (string_0_sysvq0asl){
          .bytes_0 = 15105u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&key_0), nm_0);
        inc_1_I6wjjge_aow2h993l1((&i_10));
        nimStrDestroy(nm_0);
        nimStrDestroy(X60Qx_1);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl X60Qx_152 = nimStrDup(key_0);
  NI32 X60Qx_153 = getOrDefault_1_Iwgckf31_obs4v9ato1((*s_1).d_00.stacks_0, key_0, 0);
  putQ_0_Ix03xxw_obs4v9ato1((&(*s_1).d_00.stacks_0), X60Qx_152, ((NI32)(X60Qx_153 + 1)));
  string_0_sysvq0asl X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  if (0 < stack_0.len_0){
    string_0_sysvq0asl X60Qx_3;
    nimStrWasMoved((&X60Qx_3));
    string_0_sysvq0asl* X60Qx_154 = getQ_7_Ir6d0tw_aow7lb5cq1(stack_0, ((NI32)(stack_0.len_0 - 1)));
    NI32 X60Qx_155 = len_4_sysvq0asl((*X60Qx_154));
    if (0 < X60Qx_155){
      nimStrDestroy(X60Qx_3);
      NI32 X60Qx_156 = len_3_Ixq6taz_aow7lb5cq1(stack_0);
      string_0_sysvq0asl* X60Qx_157 = getQ_7_Ir6d0tw_aow7lb5cq1(stack_0, ((NI32)(X60Qx_156 - 1)));
      string_0_sysvq0asl X60Qx_158 = nimStrDup((*X60Qx_157));
      X60Qx_3 = X60Qx_158;}
    else {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1851866366u, .more_0 = (&strlit_0_I409803864855967452_obs4v9ato1)}
      ;}
    nimStrDestroy(X60Qx_2);
    X60Qx_2 = X60Qx_3;
    nimStrWasMoved((&X60Qx_3));
    nimStrDestroy(X60Qx_3);}
  else {
    nimStrDestroy(X60Qx_2);
    string_0_sysvq0asl X60Qx_159 = nimStrDup((string_0_sysvq0asl){
      .bytes_0 = 1869883646u, .more_0 = (&strlit_0_I4092267118630528849_obs4v9ato1)}
    );
    X60Qx_2 = X60Qx_159;}
  string_0_sysvq0asl leaf_0 = X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  string_0_sysvq0asl X60Qx_160 = nimStrDup(leaf_0);
  NI32 X60Qx_161 = getOrDefault_1_Iwgckf31_obs4v9ato1((*s_1).d_00.selfC_0, leaf_0, 0);
  putQ_0_Ix03xxw_obs4v9ato1((&(*s_1).d_00.selfC_0), X60Qx_160, ((NI32)(X60Qx_161 + 1)));
  seq_0_Ixdx2fh1_aow7lb5cq1 seen_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  string_0_sysvq0asl X60Qx_162 = nimStrDup((string_0_sysvq0asl){
    .bytes_0 = 1869883646u, .more_0 = (&strlit_0_I4092267118630528849_obs4v9ato1)}
  );
  add_0_Ig6072n_aow7lb5cq1((&seen_0), X60Qx_162);
  i_10 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_163 = len_3_Ixq6taz_aow7lb5cq1(stack_0);
      if (i_10 < X60Qx_163){
        string_0_sysvq0asl X60Qx_4;
        nimStrWasMoved((&X60Qx_4));
        string_0_sysvq0asl* X60Qx_164 = getQ_7_Ir6d0tw_aow7lb5cq1(stack_0, i_10);
        NI32 X60Qx_165 = len_4_sysvq0asl((*X60Qx_164));
        if (0 < X60Qx_165){
          nimStrDestroy(X60Qx_4);
          string_0_sysvq0asl* X60Qx_166 = getQ_7_Ir6d0tw_aow7lb5cq1(stack_0, i_10);
          string_0_sysvq0asl X60Qx_167 = nimStrDup((*X60Qx_166));
          X60Qx_4 = X60Qx_167;}
        else {
          nimStrDestroy(X60Qx_4);
          X60Qx_4 = (string_0_sysvq0asl){
            .bytes_0 = 1851866366u, .more_0 = (&strlit_0_I409803864855967452_obs4v9ato1)}
          ;}
        string_0_sysvq0asl nm_1 = X60Qx_4;
        nimStrWasMoved((&X60Qx_4));
        NB8 dup_0 = NIM_FALSE;
        {
          openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_10 = toOpenArray_1_I6b60gk1_aow7lb5cq1(seen_0);
          NI32 X60Qlf_11 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_168 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_10);
              if (X60Qlf_11 < X60Qx_168){
                {
                  string_0_sysvq0asl* X60Qii_4 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_10, X60Qlf_11);
                  NB8 X60Qx_169 = eqQ_20_sysvq0asl((*X60Qii_4), nm_1);
                  if (X60Qx_169){
                    dup_0 = NIM_TRUE;}}
                inc_1_I6wjjge_aow2h993l1((&X60Qlf_11));}
              else {
                break;}}}
          whileStmtLabel_3: ;}
        forStmtLabel_2: ;
        if ((!dup_0)){
          string_0_sysvq0asl X60Qtmp_13 = nm_1;
          nimStrWasMoved((&nm_1));
          add_0_Ig6072n_aow7lb5cq1((&seen_0), X60Qtmp_13);}
        inc_1_I6wjjge_aow2h993l1((&i_10));
        nimStrDestroy(nm_1);
        nimStrDestroy(X60Qx_4);}
      else {
        break;}}}
  whileStmtLabel_1: ;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_12 = toOpenArray_1_I6b60gk1_aow7lb5cq1(seen_0);
    NI32 X60Qlf_13 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_170 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_12);
        if (X60Qlf_13 < X60Qx_170){
          {
            string_0_sysvq0asl* X60Qii_7 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_12, X60Qlf_13);
            string_0_sysvq0asl X60Qx_171 = nimStrDup((*X60Qii_7));
            NI32 X60Qx_172 = getOrDefault_1_Iwgckf31_obs4v9ato1((*s_1).d_00.totalC_0, (*X60Qii_7), 0);
            putQ_0_Ix03xxw_obs4v9ato1((&(*s_1).d_00.totalC_0), X60Qx_171, ((NI32)(X60Qx_172 + 1)));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_13));}
        else {
          break;}}}
    whileStmtLabel_6: ;}
  forStmtLabel_5: ;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(seen_0);
  nimStrDestroy(leaf_0);
  nimStrDestroy(X60Qx_2);
  nimStrDestroy(key_0);}
static inline NI32 len_3_I040hpi1_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1 s_29){
  NI32 result_13;
  result_13 = s_29.len_0;
  return result_13;}
static inline X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1** getQ_7_Ip11xd9_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1 s_30, NI32 i_13){
  NB8 X60Qx_220;
  if (i_13 < s_30.len_0){
    X60Qx_220 = (0 <= i_13);}
  else {
    X60Qx_220 = NIM_FALSE;}
  if ((!X60Qx_220)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1** result_14;
  result_14 = (&s_30.data_0[i_13]);
  return result_14;}
static inline void add_0_Ilbvamp1_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1* s_31, X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* elem_8){
  NI32 L_0 = (*s_31).len_0;
  NI32 X60Qx_225 = capInBytes_0_Ik3d83k1_obs4v9ato1((*s_31));
  if (X60Qx_225 < ((NI32)(((NI32)(L_0 * sizeof(X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1*))) + sizeof(X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1*)))){
    NB8 X60Qx_226 = resize_0_I3k0qzd_obs4v9ato1(s_31, 1);
    if ((!X60Qx_226)){
      eQdestroyQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1(elem_8);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_31).len_0));
  (*s_31).data_0[L_0] = elem_8;}
NI32 getOrDefault_1_I03027c1_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1 t_5, NI32 k_7, NI32 fallback_2){
  NI32 result_19;
  NU32 X60Qx_234 = hash_5_has9tn57v(k_7);
  NI32 idx_1 = rawGet_0_Ixeuwkk_obs4v9ato1(t_5, k_7, X60Qx_234);
  NI32 X60Qx_5;
  if (0 <= idx_1){
    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* X60Qx_235 = getQ_7_Ime3143_obs4v9ato1(t_5.data_0, idx_1);
    X60Qx_5 = (*X60Qx_235).fld_1;}
  else {
    X60Qx_5 = fallback_2;}
  result_19 = X60Qx_5;
  return result_19;}
static inline void add_0_Ic6dly71_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1* s_43, X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* elem_13){
  NI32 L_3 = (*s_43).len_0;
  NI32 X60Qx_236 = capInBytes_0_Isiozph_obs4v9ato1((*s_43));
  if (X60Qx_236 < ((NI32)(((NI32)(L_3 * sizeof(X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1*))) + sizeof(X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1*)))){
    NB8 X60Qx_237 = resize_0_Inz4czs_obs4v9ato1(s_43, 1);
    if ((!X60Qx_237)){
      eQdestroyQ_ArefSX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1(elem_13);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_43).len_0));
  (*s_43).data_0[L_3] = elem_13;}
static inline NI32 len_3_Inbysyn_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1 s_45){
  NI32 result_21;
  result_21 = s_45.len_0;
  return result_21;}
void putQ_0_Icmdioe1_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1* t_7, NI32 k_9, NI32 v_2){
  NU32 h_0 = hash_5_has9tn57v(k_9);
  NI32 idx_2 = rawGet_0_Ixeuwkk_obs4v9ato1((*t_7), k_9, h_0);
  if (0 <= idx_2){
    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* X60Qx_238 = getQ_7_Ime3143_obs4v9ato1((*t_7).data_0, idx_2);
    (*X60Qx_238).fld_1 = v_2;}
  else {
    rawPut_0_Ir4gd8s1_obs4v9ato1(t_7, k_9, v_2, h_0);}}
static inline X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1** getQ_7_I7my8px1_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1 s_46, NI32 i_18){
  NB8 X60Qx_239;
  if (i_18 < s_46.len_0){
    X60Qx_239 = (0 <= i_18);}
  else {
    X60Qx_239 = NIM_FALSE;}
  if ((!X60Qx_239)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1** result_22;
  result_22 = (&s_46.data_0[i_18]);
  return result_22;}
Table_0_Idzlvr_obs4v9ato1 initTable_0_Id6tqqy1_obs4v9ato1(void){
  Table_0_Idzlvr_obs4v9ato1 result_31;
  eQwasmovedQ_SX54able0X49dzlvr_0_obs4v9ato1((&result_31));
  eQdestroyQ_SX54able0X49dzlvr_0_obs4v9ato1(result_31);
  seq_0_Ix7ee6h_obs4v9ato1 X60Qx_250 = newSeqUninit_0_Ig5459y1_obs4v9ato1(0);
  seq_0_Ikxuplm1_der823rwr1 X60Qx_251 = newSeqUninit_0_Iie69x21_der823rwr1(0);
  result_31 = (Table_0_Idzlvr_obs4v9ato1){
    .data_0 = X60Qx_250, .hashes_0 = X60Qx_251}
  ;
  return result_31;}
NI32 getOrDefault_1_Iwgckf31_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1 t_9, string_0_sysvq0asl k_11, NI32 fallback_3){
  NI32 result_32;
  NU32 X60Qx_252 = hash_1_has9tn57v(k_11);
  NI32 idx_7 = rawGet_0_Ik917wh_obs4v9ato1(t_9, k_11, X60Qx_252);
  NI32 X60Qx_6;
  if (0 <= idx_7){
    X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* X60Qx_253 = getQ_7_Ioesyu2_obs4v9ato1(t_9.data_0, idx_7);
    X60Qx_6 = (*X60Qx_253).fld_1;}
  else {
    X60Qx_6 = fallback_3;}
  result_32 = X60Qx_6;
  return result_32;}
void putQ_0_Ix03xxw_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1* t_11, string_0_sysvq0asl k_13, NI32 v_4){
  NU32 h_2 = hash_1_has9tn57v(k_13);
  NI32 idx_8 = rawGet_0_Ik917wh_obs4v9ato1((*t_11), k_13, h_2);
  if (0 <= idx_8){
    X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* X60Qx_254 = getQ_7_Ioesyu2_obs4v9ato1((*t_11).data_0, idx_8);
    (*X60Qx_254).fld_1 = v_4;}
  else {
    string_0_sysvq0asl X60Qtmp_16 = k_13;
    nimStrWasMoved((&k_13));
    rawPut_0_Isxoisv_obs4v9ato1(t_11, X60Qtmp_16, v_4, h_2);}
  nimStrDestroy(k_13);}
static inline NI32 memSizeInBytes_0_Iwm7rxe1_obs4v9ato1(NI32 size_18){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_33;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_18, sizeof(X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_33 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_33 = ((NI32)2147483647);}
  return result_33;}
static inline NI32 memSizeInBytes_0_I8qofpy1_obs4v9ato1(NI32 size_23){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_36;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_23, sizeof(X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_36 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_36 = ((NI32)2147483647);}
  return result_36;}
static inline NI32 capInBytes_0_Ik3d83k1_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1 s_63){
  NI32 result_39;
  NI32 X60Qx_7;
  if ((!(s_63.data_0 == NIM_NIL))){
    NI32 X60Qx_260 = allocatedSize_0_sysvq0asl(((void*)((void*)s_63.data_0)));
    X60Qx_7 = X60Qx_260;}
  else {
    X60Qx_7 = 0;}
  result_39 = X60Qx_7;
  return result_39;}
NB8 resize_0_I3k0qzd_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1* dest_5, NI32 addedElements_5){
  NB8 result_40;
  NI32 X60Qx_261 = capInBytes_0_Ik3d83k1_obs4v9ato1((*dest_5));
  NI32 oldCap_0 = ((NI32)(X60Qx_261 / sizeof(X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1*)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_5);
  NI32 memSize_7 = memSizeInBytes_0_Iwm7rxe1_obs4v9ato1(newCap_0);
  void* X60Qx_262 = realloc_1_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_7);
  (*dest_5).data_0 = ((X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1**)X60Qx_262);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_7);
    result_40 = NIM_FALSE;}
  else {
    result_40 = NIM_TRUE;}
  return result_40;}
NI32 rawGet_0_Ixeuwkk_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1 t_14, NI32 k_15, NU32 kh_2){
  NI32 result_45;
  NI32 X60Qx_269 = len_3_Iqf4r13_obs4v9ato1(t_14.data_0);
  if (X60Qx_269 <= ((NI32)4)){
    {
      NI32 X60Qlf_28 = 0;
      NI32 X60Qlf_29 = len_3_Iqf4r13_obs4v9ato1(t_14.data_0);
      NI32 X60Qlf_30 = X60Qlf_28;
      {
        while (X60Qlf_30 < X60Qlf_29){
          {
            X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* X60Qx_270 = getQ_7_Ime3143_obs4v9ato1(t_14.data_0, X60Qlf_30);
            if ((*X60Qx_270).fld_0 == k_15){
              return X60Qlf_30;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_30));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_271 = high_3_Iyuup9h1_der823rwr1(t_14.hashes_0);
    NU32 h_4 = ((NU32)(kh_2 & ((NU32)X60Qx_271)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_272 = getQ_8_Imt2zi01_der823rwr1(t_14.hashes_0, h_4);
        NB8 X60Qx_273 = isFilled_0_tabcr240b1((*X60Qx_272));
        if (X60Qx_273){
          HashEntry_0_tabcr240b1* X60Qx_274 = getQ_8_Imt2zi01_der823rwr1(t_14.hashes_0, h_4);
          HashEntry_0_tabcr240b1 d_0 = (*X60Qx_274);
          NB8 X60Qx_275;
          if (d_0.fullhash_0 == kh_2){
            X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* X60Qx_276 = getQ_7_Ime3143_obs4v9ato1(t_14.data_0, ((NI32)(d_0.position_0 - 1)));
            X60Qx_275 = ((*X60Qx_276).fld_0 == k_15);}
          else {
            X60Qx_275 = NIM_FALSE;}
          if (X60Qx_275){
            result_45 = ((NI32)(d_0.position_0 - 1));
            return result_45;}
          NI32 X60Qx_277 = high_3_Iyuup9h1_der823rwr1(t_14.hashes_0);
          NU32 X60Qx_278 = nextTry_0_has9tn57v(h_4, X60Qx_277);
          h_4 = X60Qx_278;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_45 = -1;
  return result_45;}
static inline X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* getQ_7_Ime3143_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1 s_69, NI32 i_30){
  NB8 X60Qx_279;
  if (i_30 < s_69.len_0){
    X60Qx_279 = (0 <= i_30);}
  else {
    X60Qx_279 = NIM_FALSE;}
  if ((!X60Qx_279)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* result_46;
  result_46 = (&s_69.data_0[i_30]);
  return result_46;}
static inline NI32 capInBytes_0_Isiozph_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1 s_70){
  NI32 result_47;
  NI32 X60Qx_10;
  if ((!(s_70.data_0 == NIM_NIL))){
    NI32 X60Qx_280 = allocatedSize_0_sysvq0asl(((void*)((void*)s_70.data_0)));
    X60Qx_10 = X60Qx_280;}
  else {
    X60Qx_10 = 0;}
  result_47 = X60Qx_10;
  return result_47;}
NB8 resize_0_Inz4czs_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1* dest_8, NI32 addedElements_8){
  NB8 result_48;
  NI32 X60Qx_281 = capInBytes_0_Isiozph_obs4v9ato1((*dest_8));
  NI32 oldCap_3 = ((NI32)(X60Qx_281 / sizeof(X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1*)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_8);
  NI32 memSize_10 = memSizeInBytes_0_I8qofpy1_obs4v9ato1(newCap_3);
  void* X60Qx_282 = realloc_1_sysvq0asl(((void*)((void*)(*dest_8).data_0)), memSize_10);
  (*dest_8).data_0 = ((X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1**)X60Qx_282);
  if ((*dest_8).data_0 == NIM_NIL){
    (*dest_8).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_10);
    result_48 = NIM_FALSE;}
  else {
    result_48 = NIM_TRUE;}
  return result_48;}
void rawPut_0_Ir4gd8s1_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1* t_15, NI32 k_16, NI32 v_6, NU32 h_5){
  NI32 X60Qx_283 = len_3_Iqf4r13_obs4v9ato1((*t_15).data_0);
  if (X60Qx_283 == ((NI32)4)){
    fillHashPart_0_Ii9f097_obs4v9ato1(t_15);}
  else {
    NI32 X60Qx_284 = len_3_Iiefpcc1_der823rwr1((*t_15).hashes_0);
    NI32 X60Qx_285 = len_3_Iqf4r13_obs4v9ato1((*t_15).data_0);
    NB8 X60Qx_286 = mustRehash_0_tabcr240b1(X60Qx_284, X60Qx_285);
    if (X60Qx_286){
      resize_0_tabcr240b1((&(*t_15).hashes_0));}}
  add_0_Imd0elh_obs4v9ato1((&(*t_15).data_0), (X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1){
    .fld_0 = k_16, .fld_1 = v_6}
  );
  NI32 X60Qx_287 = high_3_Iyuup9h1_der823rwr1((*t_15).hashes_0);
  NU32 hi_0 = ((NU32)(h_5 & ((NU32)X60Qx_287)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_288 = getQ_8_Imt2zi01_der823rwr1((*t_15).hashes_0, hi_0);
      NB8 X60Qx_289 = isFilled_0_tabcr240b1((*X60Qx_288));
      if (X60Qx_289){
        NI32 X60Qx_290 = high_3_Iyuup9h1_der823rwr1((*t_15).hashes_0);
        NU32 X60Qx_291 = nextTry_0_has9tn57v(hi_0, X60Qx_290);
        hi_0 = X60Qx_291;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_292 = len_3_Iqf4r13_obs4v9ato1((*t_15).data_0);
  putQ_8_Ipchg2a_der823rwr1((&(*t_15).hashes_0), hi_0, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_5, .position_0 = X60Qx_292}
  );}
static inline seq_0_Ix7ee6h_obs4v9ato1 newSeqUninit_0_Ig5459y1_obs4v9ato1(NI32 size_27){
  seq_0_Ix7ee6h_obs4v9ato1 result_64;
  if (size_27 == 0){
    result_64 = (seq_0_Ix7ee6h_obs4v9ato1){
      .len_0 = size_27, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_12 = memSizeInBytes_0_Ivx6m0g1_obs4v9ato1(size_27);
    void* X60Qx_300 = alloc_1_sysvq0asl(memSize_12);
    result_64 = (seq_0_Ix7ee6h_obs4v9ato1){
      .len_0 = size_27, .data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax*)X60Qx_300)}
    ;
    if ((!(result_64.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_301 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_64.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_12);}}
  return result_64;}
NI32 rawGet_0_Ik917wh_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1 t_17, string_0_sysvq0asl k_17, NU32 kh_3){
  NI32 result_65;
  NI32 X60Qx_302 = len_3_Ixb1ads1_obs4v9ato1(t_17.data_0);
  if (X60Qx_302 <= ((NI32)4)){
    {
      NI32 X60Qlf_31 = 0;
      NI32 X60Qlf_32 = len_3_Ixb1ads1_obs4v9ato1(t_17.data_0);
      NI32 X60Qlf_33 = X60Qlf_31;
      {
        while (X60Qlf_33 < X60Qlf_32){
          {
            X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* X60Qx_303 = getQ_7_Ioesyu2_obs4v9ato1(t_17.data_0, X60Qlf_33);
            NB8 X60Qx_304 = eqQ_20_sysvq0asl((*X60Qx_303).fld_0, k_17);
            if (X60Qx_304){
              return X60Qlf_33;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_33));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_305 = high_3_Iyuup9h1_der823rwr1(t_17.hashes_0);
    NU32 h_6 = ((NU32)(kh_3 & ((NU32)X60Qx_305)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_306 = getQ_8_Imt2zi01_der823rwr1(t_17.hashes_0, h_6);
        NB8 X60Qx_307 = isFilled_0_tabcr240b1((*X60Qx_306));
        if (X60Qx_307){
          HashEntry_0_tabcr240b1* X60Qx_308 = getQ_8_Imt2zi01_der823rwr1(t_17.hashes_0, h_6);
          HashEntry_0_tabcr240b1 d_1 = (*X60Qx_308);
          NB8 X60Qx_309;
          if (d_1.fullhash_0 == kh_3){
            X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* X60Qx_310 = getQ_7_Ioesyu2_obs4v9ato1(t_17.data_0, ((NI32)(d_1.position_0 - 1)));
            NB8 X60Qx_311 = eqQ_20_sysvq0asl((*X60Qx_310).fld_0, k_17);
            X60Qx_309 = X60Qx_311;}
          else {
            X60Qx_309 = NIM_FALSE;}
          if (X60Qx_309){
            result_65 = ((NI32)(d_1.position_0 - 1));
            return result_65;}
          NI32 X60Qx_312 = high_3_Iyuup9h1_der823rwr1(t_17.hashes_0);
          NU32 X60Qx_313 = nextTry_0_has9tn57v(h_6, X60Qx_312);
          h_6 = X60Qx_313;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_65 = -1;
  return result_65;}
static inline X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* getQ_7_Ioesyu2_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1 s_79, NI32 i_33){
  NB8 X60Qx_314;
  if (i_33 < s_79.len_0){
    X60Qx_314 = (0 <= i_33);}
  else {
    X60Qx_314 = NIM_FALSE;}
  if ((!X60Qx_314)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* result_66;
  result_66 = (&s_79.data_0[i_33]);
  return result_66;}
void rawPut_0_Isxoisv_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1* t_18, string_0_sysvq0asl k_18, NI32 v_7, NU32 h_7){
  NI32 X60Qx_315 = len_3_Ixb1ads1_obs4v9ato1((*t_18).data_0);
  if (X60Qx_315 == ((NI32)4)){
    fillHashPart_0_Ietaba01_obs4v9ato1(t_18);}
  else {
    NI32 X60Qx_316 = len_3_Iiefpcc1_der823rwr1((*t_18).hashes_0);
    NI32 X60Qx_317 = len_3_Ixb1ads1_obs4v9ato1((*t_18).data_0);
    NB8 X60Qx_318 = mustRehash_0_tabcr240b1(X60Qx_316, X60Qx_317);
    if (X60Qx_318){
      resize_0_tabcr240b1((&(*t_18).hashes_0));}}
  string_0_sysvq0asl X60Qtmp_19 = k_18;
  nimStrWasMoved((&k_18));
  add_0_I2s2mnd_obs4v9ato1((&(*t_18).data_0), (X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax){
    .fld_0 = X60Qtmp_19, .fld_1 = v_7}
  );
  NI32 X60Qx_319 = high_3_Iyuup9h1_der823rwr1((*t_18).hashes_0);
  NU32 hi_1 = ((NU32)(h_7 & ((NU32)X60Qx_319)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_320 = getQ_8_Imt2zi01_der823rwr1((*t_18).hashes_0, hi_1);
      NB8 X60Qx_321 = isFilled_0_tabcr240b1((*X60Qx_320));
      if (X60Qx_321){
        NI32 X60Qx_322 = high_3_Iyuup9h1_der823rwr1((*t_18).hashes_0);
        NU32 X60Qx_323 = nextTry_0_has9tn57v(hi_1, X60Qx_322);
        hi_1 = X60Qx_323;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_324 = len_3_Ixb1ads1_obs4v9ato1((*t_18).data_0);
  putQ_8_Ipchg2a_der823rwr1((&(*t_18).hashes_0), hi_1, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_7, .position_0 = X60Qx_324}
  );
  nimStrDestroy(k_18);}
static inline NI32 len_3_Ixb1ads1_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1 s_81){
  NI32 result_67;
  result_67 = s_81.len_0;
  return result_67;}
static inline NI32 memSizeInBytes_0_Isevqrk_obs4v9ato1(NI32 size_29){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_68;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_29, sizeof(X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_68 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_68 = ((NI32)2147483647);}
  return result_68;}
static inline NI32 len_3_Iqf4r13_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1 s_82){
  NI32 result_70;
  result_70 = s_82.len_0;
  return result_70;}
void fillHashPart_0_Ii9f097_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1* t_20){
  seq_0_Ikxuplm1_der823rwr1* X60Qlhs_20 = (&(*t_20).hashes_0);
  eQdestroy_1_I5skmro_der823rwr1((*X60Qlhs_20));
  seq_0_Ikxuplm1_der823rwr1 X60Qx_325 = newSeq_0_Iv3lu2h1_der823rwr1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_20) = X60Qx_325;
  {
    NI32 X60Qlf_34 = 0;
    NI32 X60Qlf_35 = len_3_Iqf4r13_obs4v9ato1((*t_20).data_0);
    NI32 X60Qlf_36 = X60Qlf_34;
    {
      while (X60Qlf_36 < X60Qlf_35){
        {
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1* X60Qx_326 = getQ_7_Ime3143_obs4v9ato1((*t_20).data_0, X60Qlf_36);
          NU32 X60Qii_2 = hash_5_has9tn57v((*X60Qx_326).fld_0);
          NI32 X60Qx_327 = high_3_Iyuup9h1_der823rwr1((*t_20).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_327)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_328 = getQ_8_Imt2zi01_der823rwr1((*t_20).hashes_0, X60Qii_3);
            NB8 X60Qx_329 = isFilled_0_tabcr240b1((*X60Qx_328));
            if (X60Qx_329){
              NI32 X60Qx_330 = high_3_Iyuup9h1_der823rwr1((*t_20).hashes_0);
              NU32 X60Qx_331 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_330);
              X60Qii_3 = X60Qx_331;}
            else {
              break;}}
          putQ_8_Ipchg2a_der823rwr1((&(*t_20).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_36 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_36));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_Imd0elh_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1* s_86, X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 elem_19){
  NI32 L_5 = (*s_86).len_0;
  NI32 X60Qx_332 = capInBytes_0_Ikzjb2e1_obs4v9ato1((*s_86));
  if (X60Qx_332 < ((NI32)(((NI32)(L_5 * sizeof(X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1))) + sizeof(X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1)))){
    NB8 X60Qx_333 = resize_0_Ikxsgd91_obs4v9ato1(s_86, 1);
    if ((!X60Qx_333)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_86).len_0));
  (*s_86).data_0[L_5] = elem_19;}
static inline NI32 memSizeInBytes_0_Ivx6m0g1_obs4v9ato1(NI32 size_32){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_74;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_32, sizeof(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_74 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_74 = ((NI32)2147483647);}
  return result_74;}
void fillHashPart_0_Ietaba01_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1* t_21){
  seq_0_Ikxuplm1_der823rwr1* X60Qlhs_21 = (&(*t_21).hashes_0);
  eQdestroy_1_I5skmro_der823rwr1((*X60Qlhs_21));
  seq_0_Ikxuplm1_der823rwr1 X60Qx_334 = newSeq_0_Iv3lu2h1_der823rwr1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_21) = X60Qx_334;
  {
    NI32 X60Qlf_37 = 0;
    NI32 X60Qlf_38 = len_3_Ixb1ads1_obs4v9ato1((*t_21).data_0);
    NI32 X60Qlf_39 = X60Qlf_37;
    {
      while (X60Qlf_39 < X60Qlf_38){
        {
          X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* X60Qx_335 = getQ_7_Ioesyu2_obs4v9ato1((*t_21).data_0, X60Qlf_39);
          NU32 X60Qii_2 = hash_1_has9tn57v((*X60Qx_335).fld_0);
          NI32 X60Qx_336 = high_3_Iyuup9h1_der823rwr1((*t_21).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_336)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_337 = getQ_8_Imt2zi01_der823rwr1((*t_21).hashes_0, X60Qii_3);
            NB8 X60Qx_338 = isFilled_0_tabcr240b1((*X60Qx_337));
            if (X60Qx_338){
              NI32 X60Qx_339 = high_3_Iyuup9h1_der823rwr1((*t_21).hashes_0);
              NU32 X60Qx_340 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_339);
              X60Qii_3 = X60Qx_340;}
            else {
              break;}}
          putQ_8_Ipchg2a_der823rwr1((&(*t_21).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_39 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_39));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_I2s2mnd_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1* s_89, X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax elem_21){
  NI32 L_6 = (*s_89).len_0;
  NI32 X60Qx_341 = capInBytes_0_Igxyzwi_obs4v9ato1((*s_89));
  if (X60Qx_341 < ((NI32)(((NI32)(L_6 * sizeof(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax))) + sizeof(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax)))){
    NB8 X60Qx_342 = resize_0_Itvz7wg_obs4v9ato1(s_89, 1);
    if ((!X60Qx_342)){
      eQdestroyQ_AtupleSstring0sysvq0aslAiS32_0_obs4v9ato1(elem_21);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_89).len_0));
  (*s_89).data_0[L_6] = elem_21;}
static inline NI32 capInBytes_0_Ikzjb2e1_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1 s_91){
  NI32 result_76;
  NI32 X60Qx_12;
  if ((!(s_91.data_0 == NIM_NIL))){
    NI32 X60Qx_344 = allocatedSize_0_sysvq0asl(((void*)((void*)s_91.data_0)));
    X60Qx_12 = X60Qx_344;}
  else {
    X60Qx_12 = 0;}
  result_76 = X60Qx_12;
  return result_76;}
NB8 resize_0_Ikxsgd91_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1* dest_12, NI32 addedElements_12){
  NB8 result_77;
  NI32 X60Qx_345 = capInBytes_0_Ikzjb2e1_obs4v9ato1((*dest_12));
  NI32 oldCap_5 = ((NI32)(X60Qx_345 / sizeof(X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1)));
  NI32 newCap_5 = recalcCap_0_sysvq0asl(oldCap_5, addedElements_12);
  NI32 memSize_14 = memSizeInBytes_0_Isevqrk_obs4v9ato1(newCap_5);
  void* X60Qx_346 = realloc_1_sysvq0asl(((void*)((void*)(*dest_12).data_0)), memSize_14);
  (*dest_12).data_0 = ((X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1*)X60Qx_346);
  if ((*dest_12).data_0 == NIM_NIL){
    (*dest_12).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_14);
    result_77 = NIM_FALSE;}
  else {
    result_77 = NIM_TRUE;}
  return result_77;}
static inline NI32 capInBytes_0_Igxyzwi_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1 s_92){
  NI32 result_78;
  NI32 X60Qx_13;
  if ((!(s_92.data_0 == NIM_NIL))){
    NI32 X60Qx_347 = allocatedSize_0_sysvq0asl(((void*)((void*)s_92.data_0)));
    X60Qx_13 = X60Qx_347;}
  else {
    X60Qx_13 = 0;}
  result_78 = X60Qx_13;
  return result_78;}
NB8 resize_0_Itvz7wg_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1* dest_13, NI32 addedElements_13){
  NB8 result_79;
  NI32 X60Qx_348 = capInBytes_0_Igxyzwi_obs4v9ato1((*dest_13));
  NI32 oldCap_6 = ((NI32)(X60Qx_348 / sizeof(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax)));
  NI32 newCap_6 = recalcCap_0_sysvq0asl(oldCap_6, addedElements_13);
  NI32 memSize_15 = memSizeInBytes_0_Ivx6m0g1_obs4v9ato1(newCap_6);
  void* X60Qx_349 = realloc_1_sysvq0asl(((void*)((void*)(*dest_13).data_0)), memSize_15);
  (*dest_13).data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax*)X60Qx_349);
  if ((*dest_13).data_0 == NIM_NIL){
    (*dest_13).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_15);
    result_79 = NIM_FALSE;}
  else {
    result_79 = NIM_TRUE;}
  return result_79;}
void eQdestroy_1_Iglm0fw_obs4v9ato1(seq_0_Icfzt52_obs4v9ato1 s_115){
  if ((!(s_115.data_0 == NIM_NIL))){
    NI32 i_52 = 0;
    {
      while (i_52 < s_115.len_0){
        eQdestroyQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1(s_115.data_0[i_52]);
        inc_1_I6wjjge_aow2h993l1((&i_52));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_115.data_0)));}}
void eQdestroy_1_Ip35lo21_obs4v9ato1(seq_0_Iivvdd91_obs4v9ato1 s_117){
  if ((!(s_117.data_0 == NIM_NIL))){
    NI32 i_56 = 0;
    {
      while (i_56 < s_117.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_56));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_117.data_0)));}}
void eQdestroy_1_Ikfl66d1_obs4v9ato1(seq_0_Ivhjttw1_obs4v9ato1 s_119){
  if ((!(s_119.data_0 == NIM_NIL))){
    NI32 i_60 = 0;
    {
      while (i_60 < s_119.len_0){
        eQdestroyQ_ArefSX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1(s_119.data_0[i_60]);
        inc_1_I6wjjge_aow2h993l1((&i_60));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_119.data_0)));}}
void eQdestroy_1_Ime9ach1_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1 s_121){
  if ((!(s_121.data_0 == NIM_NIL))){
    NI32 i_64 = 0;
    {
      while (i_64 < s_121.len_0){
        eQdestroyQ_AtupleSstring0sysvq0aslAiS32_0_obs4v9ato1(s_121.data_0[i_64]);
        inc_1_I6wjjge_aow2h993l1((&i_64));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_121.data_0)));}}
static inline void eQwasMoved_1_Iydurru1_obs4v9ato1(seq_0_Ix7ee6h_obs4v9ato1* s_122){
  (*s_122).len_0 = 0;
  (*s_122).data_0 = NIM_NIL;}
void eQdestroyQ_SX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1(FileCov_Obj_0_obs4v9ato1 dest_0){
  eQdestroy_1_I7a20g9_aow7lb5cq1(dest_0.known_0);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(dest_0.hits_0);
  nimStrDestroy(dest_0.name_0);}
void eQdestroyQ_SX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1(BranchSite_Obj_0_obs4v9ato1* dest_0){
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1((*dest_0).counts_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*dest_0).labels_0);
  nimStrDestroy((*dest_0).form_0);
  nimStrDestroy((*dest_0).file_0);}
void eQdestroyQ_SX43overageX4fbj0obs4v9ato1_0_obs4v9ato1(Coverage_Obj_0_obs4v9ato1* dest_0){
  eQdestroy_1_Ikfl66d1_obs4v9ato1((*dest_0).sites_0);
  eQdestroyQ_SX54able0X49r2mg111_0_obs4v9ato1((*dest_0).siteIdx_0);
  nimStrDestroy((*dest_0).lastName_0);
  eQdestroy_1_Iglm0fw_obs4v9ato1((*dest_0).files_0);}
void eQdestroyQ_SX53amplerX4fbj0obs4v9ato1_0_obs4v9ato1(Sampler_Obj_0_obs4v9ato1* dest_0){
  eQdestroyQ_SX54able0X49dzlvr_0_obs4v9ato1((*dest_0).totalC_0);
  eQdestroyQ_SX54able0X49dzlvr_0_obs4v9ato1((*dest_0).selfC_0);
  eQdestroyQ_SX54able0X49dzlvr_0_obs4v9ato1((*dest_0).stacks_0);}
void eQdestroyQ_SX54able0X49r2mg111_0_obs4v9ato1(Table_0_Ir2mg111_obs4v9ato1 dest_0){
  eQdestroy_1_I5skmro_der823rwr1(dest_0.hashes_0);
  eQdestroy_1_Ip35lo21_obs4v9ato1(dest_0.data_0);}
void eQdestroyQ_SX54able0X49dzlvr_0_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1 dest_0){
  eQdestroy_1_I5skmro_der823rwr1(dest_0.hashes_0);
  eQdestroy_1_Ime9ach1_obs4v9ato1(dest_0.data_0);}
void eQwasmovedQ_SX54able0X49dzlvr_0_obs4v9ato1(Table_0_Idzlvr_obs4v9ato1* dest_0){
  eQwasMoved_1_Iydurru1_obs4v9ato1((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_der823rwr1((&(*dest_0).hashes_0));}
void eQdestroyQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1(X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* dest_0){
  if (dest_0){
    NB8 X60Qx_413 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_413){
      eQdestroyQ_SX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1(X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* dest_0){
  if (dest_0){
    NB8 X60Qx_414 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_414){
      eQdestroyQ_SX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* eQdupQ_ArefSX46ileX43ovX4fbj0obs4v9ato1_0_obs4v9ato1(X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* src_0){
  X60Qt_0_IArefSX46ileX43ovX4fbj0obs4v9ato1_obs4v9ato1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* eQdupQ_ArefSX42ranchX53iteX4fbj0obs4v9ato1_0_obs4v9ato1(X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* src_0){
  X60Qt_0_IArefSX42ranchX53iteX4fbj0obs4v9ato1_obs4v9ato1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_AtupleSstring0sysvq0aslAiS32_0_obs4v9ato1(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax dest_0){
  nimStrDestroy(dest_0.fld_0);}
void X60Qini_0_obs4v9ato1(void){
  if (X60QiniGuard_0_obs4v9ato1){
    return;}
  X60QiniGuard_0_obs4v9ato1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tabcr240b1();}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline seq_0_Iflf8jf1_aow7lb5cq1 newSeqUninit_0_I5mozxi1_aow7lb5cq1(NI32 size_14){
  seq_0_Iflf8jf1_aow7lb5cq1 result_72;
  if (size_14 == 0){
    result_72 = (seq_0_Iflf8jf1_aow7lb5cq1){
      .len_0 = size_14, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_4 = memSizeInBytes_0_Ih4q01h_aow7lb5cq1(size_14);
    void* X60Qx_1453 = alloc_1_sysvq0asl(memSize_4);
    result_72 = (seq_0_Iflf8jf1_aow7lb5cq1){
      .len_0 = size_14, .data_0 = ((NB8*)X60Qx_1453)}
    ;
    if ((!(result_72.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1454 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_72.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_4);}}
  return result_72;}
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45){
  NI32 result_67;
  result_67 = s_45.len_0;
  return result_67;}
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_1445 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_1445 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1446 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_1446)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
static inline void add_0_Irnc3p1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_53, NB8 elem_16){
  NI32 L_4 = (*s_53).len_0;
  NI32 X60Qx_1455 = capInBytes_0_In1m6ni_aow7lb5cq1((*s_53));
  if (X60Qx_1455 < ((NI32)(((NI32)(L_4 * sizeof(NB8))) + sizeof(NB8)))){
    NB8 X60Qx_1456 = resize_0_I2yw78g1_aow7lb5cq1(s_53, 1);
    if ((!X60Qx_1456)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_53).len_0));
  (*s_53).data_0[L_4] = elem_16;}
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
static inline void putQ_7_Iiblebk_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_56, NI32 i_40, NB8 elem_17){
  NB8 X60Qx_1458;
  if (i_40 < (*s_56).len_0){
    X60Qx_1458 = (0 <= i_40);}
  else {
    X60Qx_1458 = NIM_FALSE;}
  if ((!X60Qx_1458)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_56).data_0[i_40] = elem_17;}
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37){
  NI32 result_60;
  result_60 = s_37.len_0;
  return result_60;}
static inline void eQwasMoved_1_Ix88qzs1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_95){
  (*s_95).len_0 = 0;
  (*s_95).data_0 = NIM_NIL;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
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
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
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
static inline NU32 hash_5_has9tn57v(NI32 x_2){
  NU32 result_6;
  result_6 = ((NU32)((NI32)x_2));
  return result_6;}
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
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
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
static inline NI32 memSizeInBytes_0_Ih4q01h_aow7lb5cq1(NI32 size_22){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_99;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_22, sizeof(NB8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_99 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_99 = ((NI32)2147483647);}
  return result_99;}
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
static inline NI32 capInBytes_0_In1m6ni_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_70){
  NI32 result_100;
  NI32 X60Qx_15;
  if ((!(s_70.data_0 == NIM_NIL))){
    NI32 X60Qx_1482 = allocatedSize_0_sysvq0asl(((void*)((void*)s_70.data_0)));
    X60Qx_15 = X60Qx_1482;}
  else {
    X60Qx_15 = 0;}
  result_100 = X60Qx_15;
  return result_100;}
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
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67){
  string_0_sysvq0asl* result_89;
  result_89 = s_67.data_0;
  return result_89;}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
