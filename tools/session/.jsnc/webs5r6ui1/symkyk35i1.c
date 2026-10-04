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
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct SplittedSymName_0_symkyk35i1{
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl module_0;}
SplittedSymName_0_symkyk35i1;
typedef struct SplittedModulePath_0_symkyk35i1{
  string_0_sysvq0asl dir_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl ext_0;}
SplittedModulePath_0_symkyk35i1;
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[32];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
void eQdestroyQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1(SplittedModulePath_0_symkyk35i1 dest_0);
void eQwasmovedQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1(SplittedModulePath_0_symkyk35i1* dest_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern void setLen_1_sysvq0asl(string_0_sysvq0asl* s_53, NI32 newLen_13);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern string_0_sysvq0asl substr_1_sysvq0asl(string_0_sysvq0asl s_57, NI32 first_1);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void X60Qini_0_sysvq0asl(void);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
NB8 X60QiniGuard_0_symkyk35i1;
void extractBasename_1_symkyk35i1(string_0_sysvq0asl* s_1){
  NI32 X60Qx_7 = len_4_sysvq0asl((*s_1));
  NI32 i_1 = ((NI32)(X60Qx_7 - 2));
  {
    while (0 < i_1){
      NC8 X60Qx_8 = getQ_9_sysvq0asl((*s_1), i_1);
      if (X60Qx_8 == (NC8)'.'){
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_2 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
          .a = {
            0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
        ;
        NC8 X60Qx_9 = getQ_9_sysvq0asl((*s_1), ((NI32)(i_1 + 1)));
        NU64 X60Qdesugar_3 = ((NU)X60Qx_9);
        if (((NU8)(X60Qdesugar_2.a[((NU)(X60Qdesugar_3 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_3 & 7u)))))) != 0u){
          setLen_1_sysvq0asl(s_1, i_1);
          return;}}
      dec_1_I0nzoz91_aow7lb5cq1((&i_1));}}
  whileStmtLabel_0: ;}
string_0_sysvq0asl extractModule_0_symkyk35i1(string_0_sysvq0asl s_2){
  string_0_sysvq0asl result_2;
  nimStrWasMoved((&result_2));
  NI32 X60Qx_14 = len_4_sysvq0asl(s_2);
  NI32 i_2 = ((NI32)(X60Qx_14 - 2));
  {
    while (0 < i_2){
      NC8 X60Qx_15 = getQ_9_sysvq0asl(s_2, i_2);
      if (X60Qx_15 == (NC8)'.'){
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_5 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
          .a = {
            0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
        ;
        NC8 X60Qx_16 = getQ_9_sysvq0asl(s_2, ((NI32)(i_2 + 1)));
        NU64 X60Qdesugar_6 = ((NU)X60Qx_16);
        if (((NU8)(X60Qdesugar_5.a[((NU)(X60Qdesugar_6 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_6 & 7u)))))) != 0u){
          return (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;}
        else {
          string_0_sysvq0asl X60Qx_17 = substr_1_sysvq0asl(s_2, ((NI32)(i_2 + 1)));
          result_2 = X60Qx_17;
          return result_2;}}
      dec_1_I0nzoz91_aow7lb5cq1((&i_2));}}
  whileStmtLabel_0: ;
  return (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_2;}
NB8 isInstantiation_0_symkyk35i1(string_0_sysvq0asl s_6){
  NB8 result_6;
  NI32 X60Qx_36 = len_4_sysvq0asl(s_6);
  NI32 i_5 = ((NI32)(X60Qx_36 - 2));
  NI32 dots_0 = 3;
  {
    while (0 < i_5){
      NC8 X60Qx_37 = getQ_9_sysvq0asl(s_6, i_5);
      if (X60Qx_37 == (NC8)'.'){
        dec_1_I0nzoz91_aow7lb5cq1((&dots_0));
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_14 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
          .a = {
            0u, 0u, 0u, 0u, 0u, 0u, 255u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
        ;
        NC8 X60Qx_38 = getQ_9_sysvq0asl(s_6, ((NI32)(i_5 + 1)));
        NU64 X60Qdesugar_15 = ((NU)X60Qx_38);
        if (((NU8)(X60Qdesugar_14.a[((NU)(X60Qdesugar_15 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_15 & 7u)))))) != 0u){
          result_6 = (dots_0 == 0);
          return result_6;}
        else {
          NB8 X60Qx_39;
          if (dots_0 == 1){
            NC8 X60Qx_40 = getQ_9_sysvq0asl(s_6, ((NI32)(i_5 + 1)));
            X60Qx_39 = (!(X60Qx_40 == (NC8)'I'));}
          else {
            X60Qx_39 = NIM_FALSE;}
          if (X60Qx_39){
            return NIM_FALSE;}}}
      dec_1_I0nzoz91_aow7lb5cq1((&i_5));}}
  whileStmtLabel_0: ;
  result_6 = NIM_FALSE;
  return result_6;}
SplittedModulePath_0_symkyk35i1 splitModulePath_0_symkyk35i1(string_0_sysvq0asl s_10){
  SplittedModulePath_0_symkyk35i1 result_10;
  eQwasmovedQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1((&result_10));
  NI32 X60Qx_57 = len_4_sysvq0asl(s_10);
  NI32 i_9 = ((NI32)(X60Qx_57 - 2));
  {
    while (NIM_TRUE){
      NB8 X60Qx_2;
      if (0 <= i_9){
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_20 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
          .a = {
            0u, 0u, 0u, 0u, 0u, 128u, 0u, 0u, 0u, 0u, 0u, 16u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
        ;
        NC8 X60Qx_58 = getQ_9_sysvq0asl(s_10, i_9);
        NU64 X60Qdesugar_21 = ((NU)X60Qx_58);
        X60Qx_2 = (!(((NU8)(X60Qdesugar_20.a[((NU)(X60Qdesugar_21 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_21 & 7u)))))) != 0u));}
      else {
        X60Qx_2 = NIM_FALSE;}
      if (X60Qx_2){
        dec_1_I0nzoz91_aow7lb5cq1((&i_9));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 d_0 = ((NI32)(i_9 + 1));
  {
    while (NIM_TRUE){
      NB8 X60Qx_59;
      NI32 X60Qx_60 = len_4_sysvq0asl(s_10);
      if (d_0 < X60Qx_60){
        NC8 X60Qx_61 = getQ_9_sysvq0asl(s_10, d_0);
        X60Qx_59 = (!(X60Qx_61 == (NC8)'.'));}
      else {
        X60Qx_59 = NIM_FALSE;}
      if (X60Qx_59){
        inc_1_I6wjjge_aow2h993l1((&d_0));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  eQdestroyQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1(result_10);
  string_0_sysvq0asl X60Qx_62 = substr_0_sysvq0asl(s_10, 0, ((NI32)(i_9 - 1)));
  string_0_sysvq0asl X60Qx_63 = substr_0_sysvq0asl(s_10, ((NI32)(i_9 + 1)), ((NI32)(d_0 - 1)));
  string_0_sysvq0asl X60Qx_64 = substr_1_sysvq0asl(s_10, d_0);
  result_10 = (SplittedModulePath_0_symkyk35i1){
    .dir_0 = X60Qx_62, .name_0 = X60Qx_63, .ext_0 = X60Qx_64}
  ;
  return result_10;}
string_0_sysvq0asl changeModuleExt_0_symkyk35i1(string_0_sysvq0asl s_11, string_0_sysvq0asl ext_0){
  string_0_sysvq0asl result_11;
  nimStrWasMoved((&result_11));
  SplittedModulePath_0_symkyk35i1 mp_0 = splitModulePath_0_symkyk35i1(s_11);
  nimStrDestroy(result_11);
  result_11 = mp_0.dir_0;
  nimStrWasMoved((&mp_0.dir_0));
  NI32 X60Qx_65 = len_4_sysvq0asl(result_11);
  if (0 < X60Qx_65){
    add_2_sysvq0asl((&result_11), (string_0_sysvq0asl){
      .bytes_0 = 12033u, .more_0 = NIM_NIL}
    );}
  add_2_sysvq0asl((&result_11), mp_0.name_0);
  NB8 X60Qx_66;
  NI32 X60Qx_67 = len_4_sysvq0asl(ext_0);
  if (0 < X60Qx_67){
    NC8 X60Qx_68 = getQ_9_sysvq0asl(ext_0, 0);
    X60Qx_66 = (!(X60Qx_68 == (NC8)'.'));}
  else {
    X60Qx_66 = NIM_FALSE;}
  if (X60Qx_66){
    string_0_sysvq0asl X60Qtmp_0 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 11777u, .more_0 = NIM_NIL}
    , ext_0);
    add_2_sysvq0asl((&result_11), X60Qtmp_0);
    nimStrDestroy(X60Qtmp_0);}
  else {
    add_2_sysvq0asl((&result_11), ext_0);}
  eQdestroyQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1(mp_0);
  return result_11;
  eQdestroyQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1(mp_0);
  return result_11;}
void eQdestroyQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1(SplittedModulePath_0_symkyk35i1 dest_0){
  nimStrDestroy(dest_0.ext_0);
  nimStrDestroy(dest_0.name_0);
  nimStrDestroy(dest_0.dir_0);}
void eQwasmovedQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1(SplittedModulePath_0_symkyk35i1* dest_0){
  nimStrWasMoved((&(*dest_0).dir_0));
  nimStrWasMoved((&(*dest_0).name_0));
  nimStrWasMoved((&(*dest_0).ext_0));}
void X60Qini_0_symkyk35i1(void){
  if (X60QiniGuard_0_symkyk35i1){
    return;}
  X60QiniGuard_0_symkyk35i1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();}
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
