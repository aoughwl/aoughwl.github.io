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
#include <stdlib.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[32];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct X60Qt_0_IAarrayAfS64ZS23_party5a2l1{
  NF64 a[23];}
X60Qt_0_IAarrayAfS64ZS23_party5a2l1;
typedef struct X60Qt_0_IAarrayAcS8ZS500_party5a2l1{
  NC8 a[500];}
X60Qt_0_IAarrayAcS8ZS500_party5a2l1;
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
static inline void inc_0_Ineawm41_party5a2l1(NU64* x_8, NU64 y_2);
static inline NI32 abs_0_Iycnqz_party5a2l1(NI32 x_9);
static inline void inc_0_Iloplki_party5a2l1(NI32* x_10, NI32 y_3);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_29);
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l;
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_assy765wm(void);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
LongString_0_sysvq0asl const strlit_0_I16254714811886502893_party5a2l1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "e+000"}
;
static X60Qt_0_IAarrayAfS64ZS23_party5a2l1 const powtens_0 = {
  .a = {
    1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0, 100000000.0, 1000000000.0, 10000000000.0, 100000000000.0, 1000000000000.0, 10000000000000.0, 100000000000000.0, 1000000000000000.0, 10000000000000000.0, 1e+17, 1e+18, 1e+19, 1e+20, 1e+21, 1e+22}}
;
NB8 X60QiniGuard_0_party5a2l1;
NI32 rawParseInt_0_party5a2l1(openArray_0_Ijk0jkw1_aow7lb5cq1 s_2, NI64* b_0){
  NI32 result_2;
  NI64 sign_0 = ((NI64)-1);
  NI32 i_0 = 0;
  NI64 res_0 = ((NI64)0);
  NB8 overflow_0 = NIM_FALSE;
  NI32 X60Qx_20 = len_6_Iroq7kd1_aow7lb5cq1(s_2);
  if (i_0 < X60Qx_20){
    NC8* X60Qx_21 = getQ_10_I5nt6we_aow7lb5cq1(s_2, i_0);
    if ((*X60Qx_21) == (NC8)'+'){
      inc_1_I6wjjge_aow2h993l1((&i_0));}
    else {
      NC8* X60Qx_22 = getQ_10_I5nt6we_aow7lb5cq1(s_2, i_0);
      if ((*X60Qx_22) == (NC8)'-'){
        inc_1_I6wjjge_aow2h993l1((&i_0));
        sign_0 = ((NI64)1);}}}
  NB8 X60Qx_1;
  NI32 X60Qx_23 = len_6_Iroq7kd1_aow7lb5cq1(s_2);
  if (i_0 < X60Qx_23){
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_2 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
      .a = {
        0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
    ;
    NC8* X60Qx_24 = getQ_10_I5nt6we_aow7lb5cq1(s_2, i_0);
    NU64 X60Qdesugar_3 = ((NU)(*X60Qx_24));
    X60Qx_1 = (((NU8)(X60Qdesugar_2.a[((NU)(X60Qdesugar_3 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_3 & 7u)))))) != 0u);}
  else {
    X60Qx_1 = NIM_FALSE;}
  if (X60Qx_1){
    {
      while (NIM_TRUE){
        NB8 X60Qx_2;
        NI32 X60Qx_25 = len_6_Iroq7kd1_aow7lb5cq1(s_2);
        if (i_0 < X60Qx_25){
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_4 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
            .a = {
              0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
          ;
          NC8* X60Qx_26 = getQ_10_I5nt6we_aow7lb5cq1(s_2, i_0);
          NU64 X60Qdesugar_5 = ((NU)(*X60Qx_26));
          X60Qx_2 = (((NU8)(X60Qdesugar_4.a[((NU)(X60Qdesugar_5 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_5 & 7u)))))) != 0u);}
        else {
          X60Qx_2 = NIM_FALSE;}
        if (X60Qx_2){
          NC8* X60Qx_27 = getQ_10_I5nt6we_aow7lb5cq1(s_2, i_0);
          NI32 c_1 = ((NI32)(((NI32)(*X60Qx_27)) - ((NI32)(NC8)'0')));
          if ((!overflow_0)){
            if (((NI64)(((NI64)(((NI64)(IL64(-9223372036854775807) - IL64(1))) + ((NI64)c_1))) / ((NI64)10))) <= res_0){
              res_0 = ((NI64)(((NI64)(res_0 * ((NI64)10))) - ((NI64)c_1)));}
            else {
              overflow_0 = NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&i_0));
          {
            while (NIM_TRUE){
              NB8 X60Qx_28;
              NI32 X60Qx_29 = len_6_Iroq7kd1_aow7lb5cq1(s_2);
              if (i_0 < X60Qx_29){
                NC8* X60Qx_30 = getQ_10_I5nt6we_aow7lb5cq1(s_2, i_0);
                X60Qx_28 = ((*X60Qx_30) == (NC8)'_');}
              else {
                X60Qx_28 = NIM_FALSE;}
              if (X60Qx_28){
                inc_1_I6wjjge_aow2h993l1((&i_0));}
              else {
                break;}}}
          whileStmtLabel_1: ;}
        else {
          break;}}}
    whileStmtLabel_0: ;
    NB8 X60Qx_31;
    if (sign_0 == ((NI64)-1)){
      X60Qx_31 = (res_0 == ((NI64)(IL64(-9223372036854775807) - IL64(1))));}
    else {
      X60Qx_31 = NIM_FALSE;}
    if (X60Qx_31){
      overflow_0 = NIM_TRUE;}
    if (overflow_0){
      result_2 = ((NI32)-i_0);}
    else {
      (*b_0) = ((NI64)(res_0 * sign_0));
      result_2 = i_0;}}
  else {
    result_2 = 0;}
  return result_2;}
NI32 parseBiggestInt_0_party5a2l1(openArray_0_Ijk0jkw1_aow7lb5cq1 s_3, NI64* number_2){
  NI32 result_3;
  string_0_sysvq0asl X60Qx_32 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  NI64 res_1 = ((NI64)0);
  NI32 X60Qx_33 = rawParseInt_0_party5a2l1(s_3, (&res_1));
  result_3 = X60Qx_33;
  if (0 < result_3){
    (*number_2) = res_1;}
  return result_3;}
NI32 rawParseUInt_0_party5a2l1(openArray_0_Ijk0jkw1_aow7lb5cq1 s_4, NU64* b_1){
  NI32 result_4;
  NU64 res_2 = ((NU64)0);
  NI32 i_1 = 0;
  NB8 overflow_1 = NIM_FALSE;
  NB8 X60Qx_3;
  NB8 X60Qx_34;
  NI32 X60Qx_35 = len_6_Iroq7kd1_aow7lb5cq1(s_4);
  if (i_1 < ((NI32)(X60Qx_35 - 1))){
    NC8* X60Qx_36 = getQ_10_I5nt6we_aow7lb5cq1(s_4, i_1);
    X60Qx_34 = ((*X60Qx_36) == (NC8)'-');}
  else {
    X60Qx_34 = NIM_FALSE;}
  if (X60Qx_34){
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_6 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
      .a = {
        0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
    ;
    NC8* X60Qx_37 = getQ_10_I5nt6we_aow7lb5cq1(s_4, ((NI32)(i_1 + 1)));
    NU64 X60Qdesugar_7 = ((NU)(*X60Qx_37));
    X60Qx_3 = (((NU8)(X60Qdesugar_6.a[((NU)(X60Qdesugar_7 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_7 & 7u)))))) != 0u);}
  else {
    X60Qx_3 = NIM_FALSE;}
  if (X60Qx_3){
    overflow_1 = NIM_TRUE;
    inc_1_I6wjjge_aow2h993l1((&i_1));}
  NB8 X60Qx_38;
  NI32 X60Qx_39 = len_6_Iroq7kd1_aow7lb5cq1(s_4);
  if (i_1 < X60Qx_39){
    NC8* X60Qx_40 = getQ_10_I5nt6we_aow7lb5cq1(s_4, i_1);
    X60Qx_38 = ((*X60Qx_40) == (NC8)'+');}
  else {
    X60Qx_38 = NIM_FALSE;}
  if (X60Qx_38){
    inc_1_I6wjjge_aow2h993l1((&i_1));}
  NB8 X60Qx_4;
  NI32 X60Qx_41 = len_6_Iroq7kd1_aow7lb5cq1(s_4);
  if (i_1 < X60Qx_41){
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_8 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
      .a = {
        0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
    ;
    NC8* X60Qx_42 = getQ_10_I5nt6we_aow7lb5cq1(s_4, i_1);
    NU64 X60Qdesugar_9 = ((NU)(*X60Qx_42));
    X60Qx_4 = (((NU8)(X60Qdesugar_8.a[((NU)(X60Qdesugar_9 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_9 & 7u)))))) != 0u);}
  else {
    X60Qx_4 = NIM_FALSE;}
  if (X60Qx_4){
    {
      while (NIM_TRUE){
        NB8 X60Qx_5;
        NI32 X60Qx_43 = len_6_Iroq7kd1_aow7lb5cq1(s_4);
        if (i_1 < X60Qx_43){
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_10 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
            .a = {
              0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
          ;
          NC8* X60Qx_44 = getQ_10_I5nt6we_aow7lb5cq1(s_4, i_1);
          NU64 X60Qdesugar_11 = ((NU)(*X60Qx_44));
          X60Qx_5 = (((NU8)(X60Qdesugar_10.a[((NU)(X60Qdesugar_11 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_11 & 7u)))))) != 0u);}
        else {
          X60Qx_5 = NIM_FALSE;}
        if (X60Qx_5){
          if ((!overflow_1)){
            if (((NU64)(((NU64)18446744073709551615ull) / ((NU64)10))) < res_2){
              overflow_1 = NIM_TRUE;}
            else {
              res_2 = ((NU64)(res_2 * ((NU64)10)));
              NU64 prev_0 = res_2;
              NC8* X60Qx_45 = getQ_10_I5nt6we_aow7lb5cq1(s_4, i_1);
              inc_0_Ineawm41_party5a2l1((&res_2), ((NU64)((NI32)(((NI32)(*X60Qx_45)) - ((NI32)(NC8)'0')))));
              if (res_2 < prev_0){
                overflow_1 = NIM_TRUE;}}}
          inc_1_I6wjjge_aow2h993l1((&i_1));
          {
            while (NIM_TRUE){
              NB8 X60Qx_46;
              NI32 X60Qx_47 = len_6_Iroq7kd1_aow7lb5cq1(s_4);
              if (i_1 < X60Qx_47){
                NC8* X60Qx_48 = getQ_10_I5nt6we_aow7lb5cq1(s_4, i_1);
                X60Qx_46 = ((*X60Qx_48) == (NC8)'_');}
              else {
                X60Qx_46 = NIM_FALSE;}
              if (X60Qx_46){
                inc_1_I6wjjge_aow2h993l1((&i_1));}
              else {
                break;}}}
          whileStmtLabel_1: ;}
        else {
          break;}}}
    whileStmtLabel_0: ;
    if (overflow_1){
      result_4 = ((NI32)-i_1);}
    else {
      (*b_1) = res_2;
      result_4 = i_1;}}
  else {
    result_4 = 0;}
  return result_4;}
NI32 parseBiggestUInt_0_party5a2l1(openArray_0_Ijk0jkw1_aow7lb5cq1 s_5, NU64* number_3){
  NI32 result_5;
  string_0_sysvq0asl X60Qx_49 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  NU64 res_3 = ((NU64)0);
  NI32 X60Qx_50 = rawParseUInt_0_party5a2l1(s_5, (&res_3));
  result_5 = X60Qx_50;
  if (0 < result_5){
    (*number_3) = res_3;}
  return result_5;}
NI32 parseBiggestFloat_0_party5a2l1(openArray_0_Ijk0jkw1_aow7lb5cq1 s_6, NF64* number_4){
  NI32 result_6;
  X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 IdentChars_0 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
    .a = {
      0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 254u, 255u, 255u, 135u, 254u, 255u, 255u, 7u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
  ;
  NI32 i_2 = 0;
  NF64 sign_1 = 1.0;
  NI32 kdigits_0 = 0;
  NI32 fdigits_0 = 0;
  NI32 exponent_0 = 0;
  NU64 integer_0 = ((NU64)0);
  NI32 fracExponent_0 = 0;
  NI32 expSign_0 = 1;
  NI32 firstDigit_0 = -1;
  NB8 hasSign_0 = NIM_FALSE;
  NB8 X60Qx_51;
  NI32 X60Qx_52 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
  if (i_2 < X60Qx_52){
    NB8 X60Qx_53;
    NC8* X60Qx_54 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    if ((*X60Qx_54) == (NC8)'+'){
      X60Qx_53 = NIM_TRUE;}
    else {
      NC8* X60Qx_55 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
      X60Qx_53 = ((*X60Qx_55) == (NC8)'-');}
    X60Qx_51 = X60Qx_53;}
  else {
    X60Qx_51 = NIM_FALSE;}
  if (X60Qx_51){
    hasSign_0 = NIM_TRUE;
    NC8* X60Qx_56 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    if ((*X60Qx_56) == (NC8)'-'){
      sign_1 = -1.0;}
    inc_1_I6wjjge_aow2h993l1((&i_2));}
  NB8 X60Qx_57;
  NI32 X60Qx_58 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
  if (((NI32)(i_2 + 2)) < X60Qx_58){
    NB8 X60Qx_59;
    NC8* X60Qx_60 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    if ((*X60Qx_60) == (NC8)'N'){
      X60Qx_59 = NIM_TRUE;}
    else {
      NC8* X60Qx_61 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
      X60Qx_59 = ((*X60Qx_61) == (NC8)'n');}
    X60Qx_57 = X60Qx_59;}
  else {
    X60Qx_57 = NIM_FALSE;}
  if (X60Qx_57){
    NB8 X60Qx_62;
    NC8* X60Qx_63 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 1)));
    if ((*X60Qx_63) == (NC8)'A'){
      X60Qx_62 = NIM_TRUE;}
    else {
      NC8* X60Qx_64 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 1)));
      X60Qx_62 = ((*X60Qx_64) == (NC8)'a');}
    if (X60Qx_62){
      NB8 X60Qx_65;
      NC8* X60Qx_66 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 2)));
      if ((*X60Qx_66) == (NC8)'N'){
        X60Qx_65 = NIM_TRUE;}
      else {
        NC8* X60Qx_67 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 2)));
        X60Qx_65 = ((*X60Qx_67) == (NC8)'n');}
      if (X60Qx_65){
        NB8 X60Qx_6;
        if (s_6.len_0 <= ((NI32)(i_2 + 3))){
          X60Qx_6 = NIM_TRUE;}
        else {
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_12 = IdentChars_0;
          NC8* X60Qx_68 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 3)));
          NU64 X60Qdesugar_13 = ((NU)(*X60Qx_68));
          X60Qx_6 = (!(((NU8)(X60Qdesugar_12.a[((NU)(X60Qdesugar_13 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_13 & 7u)))))) != 0u));}
        if (X60Qx_6){
          (*number_4) = NAN;
          result_6 = ((NI32)(i_2 + 3));
          return result_6;}}}
    return 0;}
  NB8 X60Qx_69;
  NI32 X60Qx_70 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
  if (((NI32)(i_2 + 2)) < X60Qx_70){
    NB8 X60Qx_71;
    NC8* X60Qx_72 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    if ((*X60Qx_72) == (NC8)'I'){
      X60Qx_71 = NIM_TRUE;}
    else {
      NC8* X60Qx_73 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
      X60Qx_71 = ((*X60Qx_73) == (NC8)'i');}
    X60Qx_69 = X60Qx_71;}
  else {
    X60Qx_69 = NIM_FALSE;}
  if (X60Qx_69){
    NB8 X60Qx_74;
    NC8* X60Qx_75 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 1)));
    if ((*X60Qx_75) == (NC8)'N'){
      X60Qx_74 = NIM_TRUE;}
    else {
      NC8* X60Qx_76 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 1)));
      X60Qx_74 = ((*X60Qx_76) == (NC8)'n');}
    if (X60Qx_74){
      NB8 X60Qx_77;
      NC8* X60Qx_78 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 2)));
      if ((*X60Qx_78) == (NC8)'F'){
        X60Qx_77 = NIM_TRUE;}
      else {
        NC8* X60Qx_79 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 2)));
        X60Qx_77 = ((*X60Qx_79) == (NC8)'f');}
      if (X60Qx_77){
        NB8 X60Qx_7;
        if (s_6.len_0 <= ((NI32)(i_2 + 3))){
          X60Qx_7 = NIM_TRUE;}
        else {
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_14 = IdentChars_0;
          NC8* X60Qx_80 = getQ_10_I5nt6we_aow7lb5cq1(s_6, ((NI32)(i_2 + 3)));
          NU64 X60Qdesugar_15 = ((NU)(*X60Qx_80));
          X60Qx_7 = (!(((NU8)(X60Qdesugar_14.a[((NU)(X60Qdesugar_15 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_15 & 7u)))))) != 0u));}
        if (X60Qx_7){
          (*number_4) = ((NF64)(INF * sign_1));
          result_6 = ((NI32)(i_2 + 3));
          return result_6;}}}
    return 0;}
  NB8 X60Qx_8;
  NI32 X60Qx_81 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
  if (i_2 < X60Qx_81){
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_16 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
      .a = {
        0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
    ;
    NC8* X60Qx_82 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    NU64 X60Qdesugar_17 = ((NU)(*X60Qx_82));
    X60Qx_8 = (((NU8)(X60Qdesugar_16.a[((NU)(X60Qdesugar_17 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_17 & 7u)))))) != 0u);}
  else {
    X60Qx_8 = NIM_FALSE;}
  if (X60Qx_8){
    NC8* X60Qx_83 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    firstDigit_0 = ((NI32)(((NI32)(*X60Qx_83)) - ((NI32)(NC8)'0')));}
  {
    while (NIM_TRUE){
      NB8 X60Qx_9;
      NI32 X60Qx_84 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
      if (i_2 < X60Qx_84){
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_18 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
          .a = {
            0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
        ;
        NC8* X60Qx_85 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
        NU64 X60Qdesugar_19 = ((NU)(*X60Qx_85));
        X60Qx_9 = (((NU8)(X60Qdesugar_18.a[((NU)(X60Qdesugar_19 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_19 & 7u)))))) != 0u);}
      else {
        X60Qx_9 = NIM_FALSE;}
      if (X60Qx_9){
        inc_1_I6wjjge_aow2h993l1((&kdigits_0));
        NC8* X60Qx_86 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
        integer_0 = ((NU64)(((NU64)(integer_0 * ((NU64)10u))) + ((NU64)((NI32)(((NI32)(*X60Qx_86)) - ((NI32)(NC8)'0'))))));
        inc_1_I6wjjge_aow2h993l1((&i_2));
        {
          while (NIM_TRUE){
            NB8 X60Qx_87;
            NI32 X60Qx_88 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
            if (i_2 < X60Qx_88){
              NC8* X60Qx_89 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
              X60Qx_87 = ((*X60Qx_89) == (NC8)'_');}
            else {
              X60Qx_87 = NIM_FALSE;}
            if (X60Qx_87){
              inc_1_I6wjjge_aow2h993l1((&i_2));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_90;
  NI32 X60Qx_91 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
  if (i_2 < X60Qx_91){
    NC8* X60Qx_92 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    X60Qx_90 = ((*X60Qx_92) == (NC8)'.');}
  else {
    X60Qx_90 = NIM_FALSE;}
  if (X60Qx_90){
    inc_1_I6wjjge_aow2h993l1((&i_2));
    if (kdigits_0 <= 0){
      {
        while (NIM_TRUE){
          NB8 X60Qx_93;
          NI32 X60Qx_94 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
          if (i_2 < X60Qx_94){
            NC8* X60Qx_95 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
            X60Qx_93 = ((*X60Qx_95) == (NC8)'0');}
          else {
            X60Qx_93 = NIM_FALSE;}
          if (X60Qx_93){
            inc_1_I6wjjge_aow2h993l1((&fracExponent_0));
            inc_1_I6wjjge_aow2h993l1((&i_2));
            {
              while (NIM_TRUE){
                NB8 X60Qx_96;
                NI32 X60Qx_97 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
                if (i_2 < X60Qx_97){
                  NC8* X60Qx_98 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
                  X60Qx_96 = ((*X60Qx_98) == (NC8)'_');}
                else {
                  X60Qx_96 = NIM_FALSE;}
                if (X60Qx_96){
                  inc_1_I6wjjge_aow2h993l1((&i_2));}
                else {
                  break;}}}
            whileStmtLabel_3: ;}
          else {
            break;}}}
      whileStmtLabel_2: ;}
    NB8 X60Qx_10;
    NB8 X60Qx_99;
    if (firstDigit_0 == -1){
      NI32 X60Qx_100 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
      X60Qx_99 = (i_2 < X60Qx_100);}
    else {
      X60Qx_99 = NIM_FALSE;}
    if (X60Qx_99){
      X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_20 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
        .a = {
          0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
      ;
      NC8* X60Qx_101 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
      NU64 X60Qdesugar_21 = ((NU)(*X60Qx_101));
      X60Qx_10 = (((NU8)(X60Qdesugar_20.a[((NU)(X60Qdesugar_21 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_21 & 7u)))))) != 0u);}
    else {
      X60Qx_10 = NIM_FALSE;}
    if (X60Qx_10){
      NC8* X60Qx_102 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
      firstDigit_0 = ((NI32)(((NI32)(*X60Qx_102)) - ((NI32)(NC8)'0')));}
    {
      while (NIM_TRUE){
        NB8 X60Qx_11;
        NI32 X60Qx_103 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
        if (i_2 < X60Qx_103){
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_22 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
            .a = {
              0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
          ;
          NC8* X60Qx_104 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
          NU64 X60Qdesugar_23 = ((NU)(*X60Qx_104));
          X60Qx_11 = (((NU8)(X60Qdesugar_22.a[((NU)(X60Qdesugar_23 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_23 & 7u)))))) != 0u);}
        else {
          X60Qx_11 = NIM_FALSE;}
        if (X60Qx_11){
          inc_1_I6wjjge_aow2h993l1((&fdigits_0));
          inc_1_I6wjjge_aow2h993l1((&fracExponent_0));
          NC8* X60Qx_105 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
          integer_0 = ((NU64)(((NU64)(integer_0 * ((NU64)10u))) + ((NU64)((NI32)(((NI32)(*X60Qx_105)) - ((NI32)(NC8)'0'))))));
          inc_1_I6wjjge_aow2h993l1((&i_2));
          {
            while (NIM_TRUE){
              NB8 X60Qx_106;
              NI32 X60Qx_107 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
              if (i_2 < X60Qx_107){
                NC8* X60Qx_108 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
                X60Qx_106 = ((*X60Qx_108) == (NC8)'_');}
              else {
                X60Qx_106 = NIM_FALSE;}
              if (X60Qx_106){
                inc_1_I6wjjge_aow2h993l1((&i_2));}
              else {
                break;}}}
          whileStmtLabel_5: ;}
        else {
          break;}}}
    whileStmtLabel_4: ;}
  NB8 X60Qx_109;
  if (((NI32)(kdigits_0 + fdigits_0)) <= 0){
    NB8 X60Qx_110;
    if (i_2 == 0){
      X60Qx_110 = NIM_TRUE;}
    else {
      NB8 X60Qx_111;
      if (i_2 == 1){
        X60Qx_111 = hasSign_0;}
      else {
        X60Qx_111 = NIM_FALSE;}
      X60Qx_110 = X60Qx_111;}
    X60Qx_109 = X60Qx_110;}
  else {
    X60Qx_109 = NIM_FALSE;}
  if (X60Qx_109){
    return 0;}
  NB8 X60Qx_12;
  NI32 X60Qx_112 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
  if (((NI32)(i_2 + 1)) < X60Qx_112){
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_24 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
      .a = {
        0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 32u, 0u, 0u, 0u, 32u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
    ;
    NC8* X60Qx_113 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    NU64 X60Qdesugar_25 = ((NU)(*X60Qx_113));
    X60Qx_12 = (((NU8)(X60Qdesugar_24.a[((NU)(X60Qdesugar_25 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_25 & 7u)))))) != 0u);}
  else {
    X60Qx_12 = NIM_FALSE;}
  if (X60Qx_12){
    inc_1_I6wjjge_aow2h993l1((&i_2));
    NB8 X60Qx_114;
    NC8* X60Qx_115 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    if ((*X60Qx_115) == (NC8)'+'){
      X60Qx_114 = NIM_TRUE;}
    else {
      NC8* X60Qx_116 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
      X60Qx_114 = ((*X60Qx_116) == (NC8)'-');}
    if (X60Qx_114){
      NC8* X60Qx_117 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
      if ((*X60Qx_117) == (NC8)'-'){
        expSign_0 = -1;}
      inc_1_I6wjjge_aow2h993l1((&i_2));}
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_26 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
      .a = {
        0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
    ;
    NC8* X60Qx_118 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    NU64 X60Qdesugar_27 = ((NU)(*X60Qx_118));
    if ((!(((NU8)(X60Qdesugar_26.a[((NU)(X60Qdesugar_27 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_27 & 7u)))))) != 0u))){
      return 0;}
    {
      while (NIM_TRUE){
        NB8 X60Qx_13;
        NI32 X60Qx_119 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
        if (i_2 < X60Qx_119){
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_28 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
            .a = {
              0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
          ;
          NC8* X60Qx_120 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
          NU64 X60Qdesugar_29 = ((NU)(*X60Qx_120));
          X60Qx_13 = (((NU8)(X60Qdesugar_28.a[((NU)(X60Qdesugar_29 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_29 & 7u)))))) != 0u);}
        else {
          X60Qx_13 = NIM_FALSE;}
        if (X60Qx_13){
          NC8* X60Qx_121 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
          exponent_0 = ((NI32)(((NI32)(exponent_0 * 10)) + ((NI32)(((NI32)(*X60Qx_121)) - ((NI32)(NC8)'0')))));
          inc_1_I6wjjge_aow2h993l1((&i_2));
          {
            while (NIM_TRUE){
              NB8 X60Qx_122;
              NI32 X60Qx_123 = len_6_Iroq7kd1_aow7lb5cq1(s_6);
              if (i_2 < X60Qx_123){
                NC8* X60Qx_124 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
                X60Qx_122 = ((*X60Qx_124) == (NC8)'_');}
              else {
                X60Qx_122 = NIM_FALSE;}
              if (X60Qx_122){
                inc_1_I6wjjge_aow2h993l1((&i_2));}
              else {
                break;}}}
          whileStmtLabel_7: ;}
        else {
          break;}}}
    whileStmtLabel_6: ;}
  NI32 realExponent_0 = ((NI32)(((NI32)(expSign_0 * exponent_0)) - fracExponent_0));
  NB8 expNegative_0 = (realExponent_0 < 0);
  NI32 absExponent_0 = abs_0_Iycnqz_party5a2l1(realExponent_0);
  if (999 < absExponent_0){
    if (integer_0 == ((NU64)0)){
      (*number_4) = 0.0;}
    else {
      if (expNegative_0){
        (*number_4) = ((NF64)(0.0 * sign_1));}
      else {
        (*number_4) = ((NF64)(INF * sign_1));}}
    return i_2;}
  NI32 digits_0 = ((NI32)(kdigits_0 + fdigits_0));
  NB8 X60Qx_125;
  if (digits_0 <= 15){
    X60Qx_125 = NIM_TRUE;}
  else {
    NB8 X60Qx_126;
    if (digits_0 <= 16){
      X60Qx_126 = (firstDigit_0 <= 8);}
    else {
      X60Qx_126 = NIM_FALSE;}
    X60Qx_125 = X60Qx_126;}
  if (X60Qx_125){
    if (absExponent_0 <= 22){
      if (expNegative_0){
        NI32 X60Qx_127 = nimIcheckB(absExponent_0, 22);
        (*number_4) = ((NF64)(((NF64)(sign_1 * ((NF64)integer_0))) / powtens_0.a[X60Qx_127]));}
      else {
        NI32 X60Qx_128 = nimIcheckB(absExponent_0, 22);
        (*number_4) = ((NF64)(((NF64)(sign_1 * ((NF64)integer_0))) * powtens_0.a[X60Qx_128]));}
      return i_2;}
    NI32 slop_0 = ((NI32)(((NI32)(15 - kdigits_0)) - fdigits_0));
    NB8 X60Qx_129;
    if (absExponent_0 <= ((NI32)(22 + slop_0))){
      X60Qx_129 = (!expNegative_0);}
    else {
      X60Qx_129 = NIM_FALSE;}
    if (X60Qx_129){
      NI32 X60Qx_130 = nimIcheckB(slop_0, 22);
      NI32 X60Qx_131 = nimIcheckB(((NI32)(absExponent_0 - slop_0)), 22);
      (*number_4) = ((NF64)(((NF64)(((NF64)(sign_1 * ((NF64)integer_0))) * powtens_0.a[X60Qx_130])) * powtens_0.a[X60Qx_131]));
      return i_2;}}
  X60Qt_0_IAarrayAcS8ZS500_party5a2l1 t_0;
  NI32 ti_0 = 0;
  NI32 X60Qx_132 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 808150526u, .more_0 = (&strlit_0_I16254714811886502893_party5a2l1)}
  );
  NI32 maxlen_0 = ((NI32)(((NI32)(((NI32)(((NI32)(((NI32)((NI32)499)) - ((NI32)((NI32)0)))) + 1)) - 1)) - X60Qx_132));
  NI32 endPos_0 = i_2;
  result_6 = endPos_0;
  i_2 = 0;
  NB8 X60Qx_133;
  if (i_2 < endPos_0){
    NC8* X60Qx_134 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
    X60Qx_133 = ((*X60Qx_134) == (NC8)'.');}
  else {
    X60Qx_133 = NIM_FALSE;}
  if (X60Qx_133){
    inc_1_I6wjjge_aow2h993l1((&i_2));}
  {
    while (NIM_TRUE){
      NB8 X60Qx_14;
      if (i_2 < endPos_0){
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_30 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
          .a = {
            0u, 0u, 0u, 0u, 0u, 40u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
        ;
        NC8* X60Qx_135 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
        NU64 X60Qdesugar_31 = ((NU)(*X60Qx_135));
        X60Qx_14 = (((NU8)(X60Qdesugar_30.a[((NU)(X60Qdesugar_31 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_31 & 7u)))))) != 0u);}
      else {
        X60Qx_14 = NIM_FALSE;}
      if (X60Qx_14){
        if (ti_0 < maxlen_0){
          NI32 X60Qx_136 = nimIcheckB(ti_0, 499);
          NC8* X60Qx_137 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
          t_0.a[X60Qx_136] = (*X60Qx_137);
          inc_1_I6wjjge_aow2h993l1((&ti_0));}
        inc_1_I6wjjge_aow2h993l1((&i_2));
        {
          while (NIM_TRUE){
            NB8 X60Qx_15;
            if (i_2 < endPos_0){
              X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_32 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
                .a = {
                  0u, 0u, 0u, 0u, 0u, 64u, 0u, 0u, 0u, 0u, 0u, 128u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
              ;
              NC8* X60Qx_138 = getQ_10_I5nt6we_aow7lb5cq1(s_6, i_2);
              NU64 X60Qdesugar_33 = ((NU)(*X60Qx_138));
              X60Qx_15 = (((NU8)(X60Qdesugar_32.a[((NU)(X60Qdesugar_33 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_33 & 7u)))))) != 0u);}
            else {
              X60Qx_15 = NIM_FALSE;}
            if (X60Qx_15){
              inc_1_I6wjjge_aow2h993l1((&i_2));}
            else {
              break;}}}
        whileStmtLabel_9: ;}
      else {
        break;}}}
  whileStmtLabel_8: ;
  NI32 X60Qx_139 = nimIcheckB(ti_0, 499);
  t_0.a[X60Qx_139] = (NC8)'E';
  inc_1_I6wjjge_aow2h993l1((&ti_0));
  NC8 X60Qx_16;
  if (expNegative_0){
    X60Qx_16 = (NC8)'-';}
  else {
    X60Qx_16 = (NC8)'+';}
  NI32 X60Qx_140 = nimIcheckB(ti_0, 499);
  t_0.a[X60Qx_140] = X60Qx_16;
  inc_0_Iloplki_party5a2l1((&ti_0), 4);
  NI32 X60Qx_141 = nimIcheckB(((NI32)(ti_0 - 1)), 499);
  t_0.a[X60Qx_141] = ((NC8)((NI32)(((NI32)(NC8)'0') + ((NI32)(absExponent_0 % 10)))));
  absExponent_0 = ((NI32)(absExponent_0 / 10));
  NI32 X60Qx_142 = nimIcheckB(((NI32)(ti_0 - 2)), 499);
  t_0.a[X60Qx_142] = ((NC8)((NI32)(((NI32)(NC8)'0') + ((NI32)(absExponent_0 % 10)))));
  absExponent_0 = ((NI32)(absExponent_0 / 10));
  NI32 X60Qx_143 = nimIcheckB(((NI32)(ti_0 - 3)), 499);
  t_0.a[X60Qx_143] = ((NC8)((NI32)(((NI32)(NC8)'0') + ((NI32)(absExponent_0 % 10)))));
  NI32 X60Qx_144 = nimIcheckB(ti_0, 499);
  t_0.a[X60Qx_144] = (NC8)'\000';
  NF64 X60Qx_145 = strtod(((NC8*)(&t_0)), NIM_NIL);
  (*number_4) = X60Qx_145;
  return result_6;}
static inline void inc_0_Ineawm41_party5a2l1(NU64* x_8, NU64 y_2){
  (*x_8) = ((NU64)((*x_8) + y_2));}
static inline NI32 abs_0_Iycnqz_party5a2l1(NI32 x_9){
  NI32 result_14;
  NI32 X60Qx_18;
  if (x_9 < 0){
    X60Qx_18 = ((NI32)-x_9);}
  else {
    X60Qx_18 = x_9;}
  result_14 = X60Qx_18;
  return result_14;}
static inline void inc_0_Iloplki_party5a2l1(NI32* x_10, NI32 y_3){
  (*x_10) = ((NI32)((*x_10) + y_3));}
void X60Qini_0_party5a2l1(void){
  if (X60QiniGuard_0_party5a2l1){
    return;}
  X60QiniGuard_0_party5a2l1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_assy765wm();}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
