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
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline NI32 high_3_Ivq2uke1_envto7w6l1(seq_0_Ixdx2fh1_aow7lb5cq1 s_6);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
extern string_0_sysvq0asl dollarQ_0_str7j0ifg(NC8* x_1);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39);
extern NB8 startsWith_0_str7j0ifg(string_0_sysvq0asl s_21, string_0_sysvq0asl prefix_1);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l;
extern NI32 find_0_str7j0ifg(string_0_sysvq0asl s_27, NC8 sub_0, NI32 start_1, NI32 last_0);
extern string_0_sysvq0asl substr_1_sysvq0asl(string_0_sysvq0asl s_57, NI32 first_1);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern NC8* toCString_0_sysvq0asl(string_0_sysvq0asl* s_64);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_str7j0ifg(void);
extern void X60Qini_0_osezuyu63(void);
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
__thread NB8 envComputed_0_envto7w6l1;
__thread seq_0_Ixdx2fh1_aow7lb5cq1 environment_0_envto7w6l1;
extern NC8** environ;
NB8 X60QiniGuard_0_envto7w6l1;
void getEnvVarsC_0_envto7w6l1(void){
  if ((!envComputed_0_envto7w6l1)){
    eQdestroy_1_Ivioh0a_aow7lb5cq1(environment_0_envto7w6l1);
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    environment_0_envto7w6l1 = X60Qx_1;
    NI32 i_1 = 0;
    {
      while ((!(((void*)environ[i_1]) == NIM_NIL))){
        string_0_sysvq0asl X60Qx_2 = dollarQ_0_str7j0ifg(environ[i_1]);
        add_0_Ig6072n_aow7lb5cq1((&environment_0_envto7w6l1), X60Qx_2);
        inc_1_I6wjjge_aow2h993l1((&i_1));}}
    whileStmtLabel_0: ;
    envComputed_0_envto7w6l1 = NIM_TRUE;}}
NI32 findEnvVar_0_envto7w6l1(string_0_sysvq0asl key_0){
  NI32 result_0;
  getEnvVarsC_0_envto7w6l1();
  string_0_sysvq0asl temp_0 = ampQ_0_sysvq0asl(key_0, (string_0_sysvq0asl){
    .bytes_0 = 15617u, .more_0 = NIM_NIL}
  );
  {
    NI32 X60Qlf_0 = 0;
    NI32 X60Qlf_1 = high_3_Ivq2uke1_envto7w6l1(environment_0_envto7w6l1);
    NI32 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 <= X60Qlf_1){
        {
          string_0_sysvq0asl* X60Qx_3 = getQ_7_Ir6d0tw_aow7lb5cq1(environment_0_envto7w6l1, X60Qlf_2);
          NB8 X60Qx_4 = startsWith_0_str7j0ifg((*X60Qx_3), temp_0);
          if (X60Qx_4){
            nimStrDestroy(temp_0);
            return X60Qlf_2;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  nimStrDestroy(temp_0);
  return -1;
  nimStrDestroy(temp_0);
  return result_0;
  nimStrDestroy(temp_0);
  return result_0;}
string_0_sysvq0asl getEnv_0_envto7w6l1(string_0_sysvq0asl key_1, string_0_sysvq0asl default_0){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  string_0_sysvq0asl X60Qx_5 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  NI32 i_4 = findEnvVar_0_envto7w6l1(key_1);
  if (0 <= i_4){
    nimStrDestroy(result_1);
    string_0_sysvq0asl* X60Qx_6 = getQ_7_Ir6d0tw_aow7lb5cq1(environment_0_envto7w6l1, i_4);
    string_0_sysvq0asl* X60Qx_7 = getQ_7_Ir6d0tw_aow7lb5cq1(environment_0_envto7w6l1, i_4);
    NI32 X60Qx_8 = find_0_str7j0ifg((*X60Qx_7), (NC8)'=', 0, -1);
    string_0_sysvq0asl X60Qx_9 = substr_1_sysvq0asl((*X60Qx_6), ((NI32)(X60Qx_8 + 1)));
    result_1 = X60Qx_9;}
  else {
    string_0_sysvq0asl key_5 = nimStrDup(key_1);
    NC8* kc_0 = toCString_0_sysvq0asl((&key_5));
    if (((void*)((void*)kc_0)) == NIM_NIL){
      nimStrDestroy(result_1);
      string_0_sysvq0asl X60Qx_10 = nimStrDup(default_0);
      result_1 = X60Qx_10;}
    else {
      NC8* env_2 = getenv(kc_0);
      if (((void*)env_2) == NIM_NIL){
        nimStrDestroy(result_1);
        string_0_sysvq0asl X60Qx_11 = nimStrDup(default_0);
        result_1 = X60Qx_11;}
      else {
        nimStrDestroy(result_1);
        string_0_sysvq0asl X60Qx_12 = dollarQ_0_str7j0ifg(env_2);
        result_1 = X60Qx_12;}}
    nimStrDestroy(key_5);}
  return result_1;}
static inline NI32 high_3_Ivq2uke1_envto7w6l1(seq_0_Ixdx2fh1_aow7lb5cq1 s_6){
  NI32 result_4;
  result_4 = ((NI32)(s_6.len_0 - 1));
  return result_4;}
static inline void putQ_7_Ild9iim_envto7w6l1(seq_0_Ixdx2fh1_aow7lb5cq1* s_8, NI32 i_10, string_0_sysvq0asl elem_3){
  NB8 X60Qx_28;
  if (i_10 < (*s_8).len_0){
    X60Qx_28 = (0 <= i_10);}
  else {
    X60Qx_28 = NIM_FALSE;}
  if ((!X60Qx_28)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* X60Qlhs_2 = (&(*s_8).data_0[i_10]);
  string_0_sysvq0asl X60Qlhs_3 = elem_3;
  nimStrWasMoved((&elem_3));
  nimStrDestroy((*X60Qlhs_2));
  (*X60Qlhs_2) = X60Qlhs_3;
  nimStrDestroy(elem_3);}
void shrink_0_Iiotmvc_envto7w6l1(seq_0_Ixdx2fh1_aow7lb5cq1* s_13, NI32 newLen_1){
  NI32 i_12 = ((NI32)((*s_13).len_0 - 1));
  {
    while (newLen_1 <= i_12){
      nimStrDestroy((*s_13).data_0[i_12]);
      dec_1_I0nzoz91_aow7lb5cq1((&i_12));}}
  whileStmtLabel_0: ;
  (*s_13).len_0 = newLen_1;}
void X60Qini_0_envto7w6l1(void){
  if (X60QiniGuard_0_envto7w6l1){
    return;}
  X60QiniGuard_0_envto7w6l1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_str7j0ifg();
  X60Qini_0_osezuyu63();
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&environment_0_envto7w6l1));}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93){
  (*s_93).len_0 = 0;
  (*s_93).data_0 = NIM_NIL;}
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
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
