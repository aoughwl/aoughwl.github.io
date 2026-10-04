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
typedef struct Breakpoint_0_dbgj4vyzj1 Breakpoint_0_dbgj4vyzj1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct VarSnap_0_dbgj4vyzj1 VarSnap_0_dbgj4vyzj1;
typedef struct seq_0_Iflf8jf1_aow7lb5cq1 seq_0_Iflf8jf1_aow7lb5cq1;
typedef NU8 DebugMode_0_dbgj4vyzj1;

#define dmRun_0_dbgj4vyzj1 ((NU8)0)
#define dmBreak_0_dbgj4vyzj1 ((NU8)1)
#define dmStep_0_dbgj4vyzj1 ((NU8)2)
typedef NU8 StepMode_0_dbgj4vyzj1;

#define ssContinue_0_dbgj4vyzj1 ((NU8)0)
#define ssInto_0_dbgj4vyzj1 ((NU8)1)
#define ssOver_0_dbgj4vyzj1 ((NU8)2)
#define ssOut_0_dbgj4vyzj1 ((NU8)3)
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct DbgSnapshot_0_dbgj4vyzj1{
  string_0_sysvq0asl name_0;
  NI32 pid_0;
  NI32 wake_0;}
DbgSnapshot_0_dbgj4vyzj1;
typedef NU8 BreakKind_0_dbgj4vyzj1;

#define bkLine_0_dbgj4vyzj1 ((NU8)0)
#define bkFunc_0_dbgj4vyzj1 ((NU8)1)
#define bkLineInFunc_0_dbgj4vyzj1 ((NU8)2)
typedef struct Breakpoint_0_dbgj4vyzj1{
  BreakKind_0_dbgj4vyzj1 kind_0;
  NI32 line_0;
  string_0_sysvq0asl funcName_0;
  string_0_sysvq0asl file_0;
  NB8 enabled_0;}
Breakpoint_0_dbgj4vyzj1;
typedef struct seq_0_Ik20wl91_dbgj4vyzj1{
  NI32 len_0;
  Breakpoint_0_dbgj4vyzj1* data_0;}
seq_0_Ik20wl91_dbgj4vyzj1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct DebugConfig_0_dbgj4vyzj1{
  DebugMode_0_dbgj4vyzj1 mode_0;
  NB8 session_0;
  seq_0_Ik20wl91_dbgj4vyzj1 breakpoints_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 expand_0;}
DebugConfig_0_dbgj4vyzj1;
typedef struct VarSnap_0_dbgj4vyzj1{
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl value_0;
  NB8 isExpand_0;}
VarSnap_0_dbgj4vyzj1;
typedef struct seq_0_Ipg6zum_dbgj4vyzj1{
  NI32 len_0;
  VarSnap_0_dbgj4vyzj1* data_0;}
seq_0_Ipg6zum_dbgj4vyzj1;
typedef struct BreakHit_0_dbgj4vyzj1{
  NI32 line_0;
  string_0_sysvq0asl file_0;
  string_0_sysvq0asl funcName_0;
  seq_0_Ipg6zum_dbgj4vyzj1 vars_0;
  NI32 depth_0;
  NI32 outLen_0;}
BreakHit_0_dbgj4vyzj1;
typedef struct seq_0_Iflf8jf1_aow7lb5cq1{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_aow7lb5cq1;
typedef struct seq_0_Ibhsdeb1_dbgj4vyzj1{
  NI32 len_0;
  seq_0_Iflf8jf1_aow7lb5cq1* data_0;}
seq_0_Ibhsdeb1_dbgj4vyzj1;
typedef struct openArray_0_Idekh1f1_dbgj4vyzj1{
  Breakpoint_0_dbgj4vyzj1* a_0;
  NI32 len_0;}
openArray_0_Idekh1f1_dbgj4vyzj1;
typedef struct openArray_0_In3wn691_dbgj4vyzj1{
  VarSnap_0_dbgj4vyzj1* a_0;
  NI32 len_0;}
openArray_0_In3wn691_dbgj4vyzj1;
typedef struct openArray_0_Ig73pnk_aow7lb5cq1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_aow7lb5cq1;
typedef struct openArray_0_I5qk0ls_dbgj4vyzj1{
  seq_0_Iflf8jf1_aow7lb5cq1* a_0;
  NI32 len_0;}
openArray_0_I5qk0ls_dbgj4vyzj1;
typedef struct HSlice_0_Inzqy8d_aow7lb5cq1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_aow7lb5cq1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline seq_0_Ik20wl91_dbgj4vyzj1 newSeqUninit_0_Is73s0j1_dbgj4vyzj1(NI32 size_2);
static inline openArray_0_Idekh1f1_dbgj4vyzj1 toOpenArray_1_Iwukdtc_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1 s_19);
static inline NI32 memSizeInBytes_0_Iknnb5t_dbgj4vyzj1(NI32 size_6);
static inline NI32 capInBytes_0_Itavz6j_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1 s_36);
NB8 resize_0_I1yekrh1_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1* dest_2, NI32 addedElements_2);
static inline Breakpoint_0_dbgj4vyzj1* rawData_0_Itdv7wu1_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1 s_37);
static inline NI32 len_6_I6maimy1_dbgj4vyzj1(openArray_0_Idekh1f1_dbgj4vyzj1 a_14);
static inline Breakpoint_0_dbgj4vyzj1* getQ_10_I4jvq0e_dbgj4vyzj1(openArray_0_Idekh1f1_dbgj4vyzj1 x_7, NI32 idx_4);
static inline NI32 memSizeInBytes_0_Iku9z7f_dbgj4vyzj1(NI32 size_15);
static inline NI32 memSizeInBytes_0_Icjtp7x_dbgj4vyzj1(NI32 size_19);
void eQdestroyQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1(Breakpoint_0_dbgj4vyzj1* dest_0);
void eQwasmovedQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1(Breakpoint_0_dbgj4vyzj1* dest_0);
void eQdestroyQ_SX44ebugX43onfig0dbgj4vyzj1_0_dbgj4vyzj1(DebugConfig_0_dbgj4vyzj1 dest_0);
void eQwasmovedQ_SX44ebugX43onfig0dbgj4vyzj1_0_dbgj4vyzj1(DebugConfig_0_dbgj4vyzj1* dest_0);
void eQdestroyQ_SX56arX53nap0dbgj4vyzj1_0_dbgj4vyzj1(VarSnap_0_dbgj4vyzj1 dest_0);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_I7a20g9_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_100);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
extern void X60Qini_0_sysvq0asl(void);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
LongString_0_sysvq0asl const strlit_0_I10817201013825926720_dbgj4vyzj1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", \342\200\246(+"}
;
LongString_0_sysvq0asl const strlit_0_I734781229358173569_dbgj4vyzj1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " more)"}
;
NB8 X60QiniGuard_0_dbgj4vyzj1;
DebugConfig_0_dbgj4vyzj1 newDebugConfig_0_dbgj4vyzj1(DebugMode_0_dbgj4vyzj1 mode_0){
  DebugConfig_0_dbgj4vyzj1 result_3;
  eQwasmovedQ_SX44ebugX43onfig0dbgj4vyzj1_0_dbgj4vyzj1((&result_3));
  eQdestroyQ_SX44ebugX43onfig0dbgj4vyzj1_0_dbgj4vyzj1(result_3);
  seq_0_Ik20wl91_dbgj4vyzj1 X60Qx_12 = newSeqUninit_0_Is73s0j1_dbgj4vyzj1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_13 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_3 = (DebugConfig_0_dbgj4vyzj1){
    .mode_0 = mode_0, .session_0 = NIM_FALSE, .breakpoints_0 = X60Qx_12, .expand_0 = X60Qx_13}
  ;
  return result_3;}
Breakpoint_0_dbgj4vyzj1 lineBreak_0_dbgj4vyzj1(NI32 line_0, string_0_sysvq0asl file_0, NB8 enabled_0){
  Breakpoint_0_dbgj4vyzj1 result_4;
  eQwasmovedQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1((&result_4));
  eQdestroyQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1((&result_4));
  string_0_sysvq0asl X60Qx_14 = nimStrDup(file_0);
  result_4 = (Breakpoint_0_dbgj4vyzj1){
    .kind_0 = 0, .line_0 = line_0, .funcName_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .file_0 = X60Qx_14, .enabled_0 = enabled_0}
  ;
  return result_4;}
Breakpoint_0_dbgj4vyzj1 funcBreak_0_dbgj4vyzj1(string_0_sysvq0asl name_0, NB8 enabled_1){
  Breakpoint_0_dbgj4vyzj1 result_5;
  eQwasmovedQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1((&result_5));
  eQdestroyQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1((&result_5));
  string_0_sysvq0asl X60Qx_15 = nimStrDup(name_0);
  result_5 = (Breakpoint_0_dbgj4vyzj1){
    .kind_0 = 1, .line_0 = 0, .funcName_0 = X60Qx_15, .file_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .enabled_0 = enabled_1}
  ;
  return result_5;}
NB8 matches_0_dbgj4vyzj1(Breakpoint_0_dbgj4vyzj1* bp_1, string_0_sysvq0asl file_1, NI32 line_2, string_0_sysvq0asl funcName_0){
  NB8 result_7;
  result_7 = NIM_FALSE;
  if ((!(*bp_1).enabled_0)){
    return result_7;}
  NB8 X60Qx_19;
  NI32 X60Qx_20 = len_4_sysvq0asl((*bp_1).file_0);
  if (X60Qx_20 == 0){
    X60Qx_19 = NIM_TRUE;}
  else {
    NB8 X60Qx_21 = eqQ_20_sysvq0asl((*bp_1).file_0, file_1);
    X60Qx_19 = X60Qx_21;}
  NB8 fileOk_0 = X60Qx_19;
  switch ((*bp_1).kind_0){
    case 0:
    {
      NB8 X60Qx_22;
      NB8 X60Qx_23;
      if (fileOk_0){
        X60Qx_23 = (!((*bp_1).line_0 == 0));}
      else {
        X60Qx_23 = NIM_FALSE;}
      if (X60Qx_23){
        X60Qx_22 = ((*bp_1).line_0 == line_2);}
      else {
        X60Qx_22 = NIM_FALSE;}
      result_7 = X60Qx_22;}
    break;
    case 1:
    {
      NB8 X60Qx_24;
      NI32 X60Qx_25 = len_4_sysvq0asl((*bp_1).funcName_0);
      if ((!(X60Qx_25 == 0))){
        NB8 X60Qx_26 = eqQ_20_sysvq0asl((*bp_1).funcName_0, funcName_0);
        X60Qx_24 = X60Qx_26;}
      else {
        X60Qx_24 = NIM_FALSE;}
      result_7 = X60Qx_24;}
    break;
    case 2:
    {
      NB8 X60Qx_27;
      NB8 X60Qx_28;
      NB8 X60Qx_29;
      NB8 X60Qx_30;
      if (fileOk_0){
        X60Qx_30 = (!((*bp_1).line_0 == 0));}
      else {
        X60Qx_30 = NIM_FALSE;}
      if (X60Qx_30){
        NI32 X60Qx_31 = len_4_sysvq0asl((*bp_1).funcName_0);
        X60Qx_29 = (!(X60Qx_31 == 0));}
      else {
        X60Qx_29 = NIM_FALSE;}
      if (X60Qx_29){
        X60Qx_28 = ((*bp_1).line_0 == line_2);}
      else {
        X60Qx_28 = NIM_FALSE;}
      if (X60Qx_28){
        NB8 X60Qx_32 = eqQ_20_sysvq0asl((*bp_1).funcName_0, funcName_0);
        X60Qx_27 = X60Qx_32;}
      else {
        X60Qx_27 = NIM_FALSE;}
      result_7 = X60Qx_27;}
    break;}
  return result_7;}
NB8 funcEntryOnlyMatch_0_dbgj4vyzj1(DebugConfig_0_dbgj4vyzj1 cfg_2, string_0_sysvq0asl file_2, NI32 line_3, string_0_sysvq0asl funcName_1){
  NB8 result_8;
  result_8 = NIM_FALSE;
  NB8 sawFunc_0 = NIM_FALSE;
  {
    openArray_0_Idekh1f1_dbgj4vyzj1 X60Qlf_0 = toOpenArray_1_Iwukdtc_dbgj4vyzj1(cfg_2.breakpoints_0);
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_33 = len_6_I6maimy1_dbgj4vyzj1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_33){
          {
            {
              Breakpoint_0_dbgj4vyzj1* X60Qii_3 = getQ_10_I4jvq0e_dbgj4vyzj1(X60Qlf_0, X60Qlf_1);
              if ((!(*X60Qii_3).enabled_0)){
                goto continueLabel_2;}
              NB8 X60Qx_34 = matches_0_dbgj4vyzj1((&(*X60Qii_3)), file_2, line_3, funcName_1);
              if ((!X60Qx_34)){
                goto continueLabel_2;}
              if ((*X60Qii_3).kind_0 == 1){
                sawFunc_0 = NIM_TRUE;}
              else {
                return NIM_FALSE;}}
            continueLabel_2: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  result_8 = sawFunc_0;
  return result_8;}
NB8 shouldBreak_0_dbgj4vyzj1(DebugConfig_0_dbgj4vyzj1 cfg_3, string_0_sysvq0asl file_3, NI32 line_4, string_0_sysvq0asl funcName_2){
  NB8 result_9;
  result_9 = NIM_FALSE;
  switch (cfg_3.mode_0){
    case 0:
    {
      result_9 = NIM_FALSE;}
    break;
    case 2:
    {
      result_9 = NIM_TRUE;}
    break;
    case 1:
    {
      {
        openArray_0_Idekh1f1_dbgj4vyzj1 X60Qlf_2 = toOpenArray_1_Iwukdtc_dbgj4vyzj1(cfg_3.breakpoints_0);
        NI32 X60Qlf_3 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_35 = len_6_I6maimy1_dbgj4vyzj1(X60Qlf_2);
            if (X60Qlf_3 < X60Qx_35){
              {
                Breakpoint_0_dbgj4vyzj1* X60Qii_2 = getQ_10_I4jvq0e_dbgj4vyzj1(X60Qlf_2, X60Qlf_3);
                NB8 X60Qx_36 = matches_0_dbgj4vyzj1((&(*X60Qii_2)), file_3, line_4, funcName_2);
                if (X60Qx_36){
                  result_9 = NIM_TRUE;
                  return result_9;}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;}
    break;}
  return result_9;}
NB8 lineBreakAt_0_dbgj4vyzj1(DebugConfig_0_dbgj4vyzj1 cfg_4, string_0_sysvq0asl file_4, NI32 line_5, string_0_sysvq0asl funcName_3){
  NB8 result_10;
  result_10 = NIM_FALSE;
  if ((!(cfg_4.mode_0 == 1))){
    return result_10;}
  {
    openArray_0_Idekh1f1_dbgj4vyzj1 X60Qlf_4 = toOpenArray_1_Iwukdtc_dbgj4vyzj1(cfg_4.breakpoints_0);
    NI32 X60Qlf_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_37 = len_6_I6maimy1_dbgj4vyzj1(X60Qlf_4);
        if (X60Qlf_5 < X60Qx_37){
          {
            {
              Breakpoint_0_dbgj4vyzj1* X60Qii_3 = getQ_10_I4jvq0e_dbgj4vyzj1(X60Qlf_4, X60Qlf_5);
              if ((*X60Qii_3).kind_0 == 1){
                goto continueLabel_2;}
              NB8 X60Qx_38 = matches_0_dbgj4vyzj1((&(*X60Qii_3)), file_4, line_5, funcName_3);
              if (X60Qx_38){
                result_10 = NIM_TRUE;
                return result_10;}}
            continueLabel_2: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_10;}
NI32 firstEq_0_dbgj4vyzj1(string_0_sysvq0asl s_0){
  NI32 result_13;
  result_13 = -1;
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_41 = len_4_sysvq0asl(s_0);
      if (i_0 < X60Qx_41){
        NC8 X60Qx_42 = getQ_9_sysvq0asl(s_0, i_0);
        if (X60Qx_42 == (NC8)'='){
          result_13 = i_0;
          return result_13;}
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_13;}
static inline seq_0_Ik20wl91_dbgj4vyzj1 newSeqUninit_0_Is73s0j1_dbgj4vyzj1(NI32 size_2){
  seq_0_Ik20wl91_dbgj4vyzj1 result_24;
  if (size_2 == 0){
    result_24 = (seq_0_Ik20wl91_dbgj4vyzj1){
      .len_0 = size_2, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_Iknnb5t_dbgj4vyzj1(size_2);
    void* X60Qx_256 = alloc_1_sysvq0asl(memSize_0);
    result_24 = (seq_0_Ik20wl91_dbgj4vyzj1){
      .len_0 = size_2, .data_0 = ((Breakpoint_0_dbgj4vyzj1*)X60Qx_256)}
    ;
    if ((!(result_24.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_257 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_24.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_24;}
static inline void add_0_Iwoqy9x1_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1* s_17, Breakpoint_0_dbgj4vyzj1 elem_2){
  NI32 L_0 = (*s_17).len_0;
  NI32 X60Qx_260 = capInBytes_0_Itavz6j_dbgj4vyzj1((*s_17));
  if (X60Qx_260 < ((NI32)(((NI32)(L_0 * sizeof(Breakpoint_0_dbgj4vyzj1))) + sizeof(Breakpoint_0_dbgj4vyzj1)))){
    NB8 X60Qx_261 = resize_0_I1yekrh1_dbgj4vyzj1(s_17, 1);
    if ((!X60Qx_261)){
      eQdestroyQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1((&elem_2));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_17).len_0));
  (*s_17).data_0[L_0] = elem_2;}
static inline openArray_0_Idekh1f1_dbgj4vyzj1 toOpenArray_1_Iwukdtc_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1 s_19){
  openArray_0_Idekh1f1_dbgj4vyzj1 result_26;
  Breakpoint_0_dbgj4vyzj1* X60Qx_262 = rawData_0_Itdv7wu1_dbgj4vyzj1(s_19);
  result_26 = (openArray_0_Idekh1f1_dbgj4vyzj1){
    .a_0 = X60Qx_262, .len_0 = s_19.len_0}
  ;
  return result_26;}
static inline NI32 len_3_I9hktyf_dbgj4vyzj1(seq_0_Iflf8jf1_aow7lb5cq1 s_27){
  NI32 result_30;
  result_30 = s_27.len_0;
  return result_30;}
static inline seq_0_Iflf8jf1_aow7lb5cq1* getQ_7_I689z2e1_dbgj4vyzj1(seq_0_Ibhsdeb1_dbgj4vyzj1 s_31, NI32 i_12){
  NB8 X60Qx_267;
  if (i_12 < s_31.len_0){
    X60Qx_267 = (0 <= i_12);}
  else {
    X60Qx_267 = NIM_FALSE;}
  if ((!X60Qx_267)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  seq_0_Iflf8jf1_aow7lb5cq1* result_34;
  result_34 = (&s_31.data_0[i_12]);
  return result_34;}
static inline NI32 memSizeInBytes_0_Iknnb5t_dbgj4vyzj1(NI32 size_6){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_38;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_6, sizeof(Breakpoint_0_dbgj4vyzj1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_38 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_38 = ((NI32)2147483647);}
  return result_38;}
static inline NI32 capInBytes_0_Itavz6j_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1 s_36){
  NI32 result_40;
  NI32 X60Qx_4;
  if ((!(s_36.data_0 == NIM_NIL))){
    NI32 X60Qx_271 = allocatedSize_0_sysvq0asl(((void*)((void*)s_36.data_0)));
    X60Qx_4 = X60Qx_271;}
  else {
    X60Qx_4 = 0;}
  result_40 = X60Qx_4;
  return result_40;}
NB8 resize_0_I1yekrh1_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1* dest_2, NI32 addedElements_2){
  NB8 result_41;
  NI32 X60Qx_272 = capInBytes_0_Itavz6j_dbgj4vyzj1((*dest_2));
  NI32 oldCap_0 = ((NI32)(X60Qx_272 / sizeof(Breakpoint_0_dbgj4vyzj1)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_2);
  NI32 memSize_2 = memSizeInBytes_0_Iknnb5t_dbgj4vyzj1(newCap_0);
  void* X60Qx_273 = realloc_1_sysvq0asl(((void*)((void*)(*dest_2).data_0)), memSize_2);
  (*dest_2).data_0 = ((Breakpoint_0_dbgj4vyzj1*)X60Qx_273);
  if ((*dest_2).data_0 == NIM_NIL){
    (*dest_2).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_2);
    result_41 = NIM_FALSE;}
  else {
    result_41 = NIM_TRUE;}
  return result_41;}
static inline Breakpoint_0_dbgj4vyzj1* rawData_0_Itdv7wu1_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1 s_37){
  Breakpoint_0_dbgj4vyzj1* result_42;
  result_42 = s_37.data_0;
  return result_42;}
static inline NI32 len_6_I6maimy1_dbgj4vyzj1(openArray_0_Idekh1f1_dbgj4vyzj1 a_14){
  NI32 result_43;
  result_43 = a_14.len_0;
  return result_43;}
static inline Breakpoint_0_dbgj4vyzj1* getQ_10_I4jvq0e_dbgj4vyzj1(openArray_0_Idekh1f1_dbgj4vyzj1 x_7, NI32 idx_4){
  NB8 X60Qx_274;
  if (0 <= idx_4){
    X60Qx_274 = (idx_4 < x_7.len_0);}
  else {
    X60Qx_274 = NIM_FALSE;}
  if ((!X60Qx_274)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  Breakpoint_0_dbgj4vyzj1* result_44;
  result_44 = (&x_7.a_0[idx_4]);
  return result_44;}
void eQdestroy_1_I1pplm51_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1 s_52){
  if ((!(s_52.data_0 == NIM_NIL))){
    NI32 i_14 = 0;
    {
      while (i_14 < s_52.len_0){
        eQdestroyQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1((&s_52.data_0[i_14]));
        inc_1_I6wjjge_aow2h993l1((&i_14));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_52.data_0)));}}
static inline void eQwasMoved_1_Isgtw04_dbgj4vyzj1(seq_0_Ik20wl91_dbgj4vyzj1* s_53){
  (*s_53).len_0 = 0;
  (*s_53).data_0 = NIM_NIL;}
void eQdestroy_1_If2c8og1_dbgj4vyzj1(seq_0_Ipg6zum_dbgj4vyzj1 s_56){
  if ((!(s_56.data_0 == NIM_NIL))){
    NI32 i_22 = 0;
    {
      while (i_22 < s_56.len_0){
        eQdestroyQ_SX56arX53nap0dbgj4vyzj1_0_dbgj4vyzj1(s_56.data_0[i_22]);
        inc_1_I6wjjge_aow2h993l1((&i_22));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_56.data_0)));}}
static inline void eQwasMoved_1_I507go6_dbgj4vyzj1(seq_0_Ipg6zum_dbgj4vyzj1* s_57){
  (*s_57).len_0 = 0;
  (*s_57).data_0 = NIM_NIL;}
void eQdestroy_1_Iis45aw1_dbgj4vyzj1(seq_0_Ibhsdeb1_dbgj4vyzj1 s_62){
  if ((!(s_62.data_0 == NIM_NIL))){
    NI32 i_30 = 0;
    {
      while (i_30 < s_62.len_0){
        eQdestroy_1_I7a20g9_aow7lb5cq1(s_62.data_0[i_30]);
        inc_1_I6wjjge_aow2h993l1((&i_30));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_62.data_0)));}}
static inline seq_0_Ipg6zum_dbgj4vyzj1 newSeqUninit_0_Izhurmm1_dbgj4vyzj1(NI32 size_14){
  seq_0_Ipg6zum_dbgj4vyzj1 result_61;
  if (size_14 == 0){
    result_61 = (seq_0_Ipg6zum_dbgj4vyzj1){
      .len_0 = size_14, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_9 = memSizeInBytes_0_Iku9z7f_dbgj4vyzj1(size_14);
    void* X60Qx_309 = alloc_1_sysvq0asl(memSize_9);
    result_61 = (seq_0_Ipg6zum_dbgj4vyzj1){
      .len_0 = size_14, .data_0 = ((VarSnap_0_dbgj4vyzj1*)X60Qx_309)}
    ;
    if ((!(result_61.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_310 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_61.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_9);}}
  return result_61;}
static inline NI32 capInBytes_0_Iuah4u2_dbgj4vyzj1(seq_0_Ipg6zum_dbgj4vyzj1 s_65){
  NI32 result_62;
  NI32 X60Qx_6;
  if ((!(s_65.data_0 == NIM_NIL))){
    NI32 X60Qx_311 = allocatedSize_0_sysvq0asl(((void*)((void*)s_65.data_0)));
    X60Qx_6 = X60Qx_311;}
  else {
    X60Qx_6 = 0;}
  result_62 = X60Qx_6;
  return result_62;}
static inline NI32 memSizeInBytes_0_Iku9z7f_dbgj4vyzj1(NI32 size_15){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_63;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_15, sizeof(VarSnap_0_dbgj4vyzj1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_63 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_63 = ((NI32)2147483647);}
  return result_63;}
static inline seq_0_Ibhsdeb1_dbgj4vyzj1 newSeqUninit_0_Ibdxcd1_dbgj4vyzj1(NI32 size_18){
  seq_0_Ibhsdeb1_dbgj4vyzj1 result_67;
  if (size_18 == 0){
    result_67 = (seq_0_Ibhsdeb1_dbgj4vyzj1){
      .len_0 = size_18, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_11 = memSizeInBytes_0_Icjtp7x_dbgj4vyzj1(size_18);
    void* X60Qx_315 = alloc_1_sysvq0asl(memSize_11);
    result_67 = (seq_0_Ibhsdeb1_dbgj4vyzj1){
      .len_0 = size_18, .data_0 = ((seq_0_Iflf8jf1_aow7lb5cq1*)X60Qx_315)}
    ;
    if ((!(result_67.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_316 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_67.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_11);}}
  return result_67;}
static inline NI32 capInBytes_0_Id1upe_dbgj4vyzj1(seq_0_Ibhsdeb1_dbgj4vyzj1 s_67){
  NI32 result_68;
  NI32 X60Qx_8;
  if ((!(s_67.data_0 == NIM_NIL))){
    NI32 X60Qx_317 = allocatedSize_0_sysvq0asl(((void*)((void*)s_67.data_0)));
    X60Qx_8 = X60Qx_317;}
  else {
    X60Qx_8 = 0;}
  result_68 = X60Qx_8;
  return result_68;}
static inline NI32 memSizeInBytes_0_Icjtp7x_dbgj4vyzj1(NI32 size_19){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_69;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_19, sizeof(seq_0_Iflf8jf1_aow7lb5cq1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_69 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_69 = ((NI32)2147483647);}
  return result_69;}
void eQdestroyQ_SX44bgX53napshot0dbgj4vyzj1_0_dbgj4vyzj1(DbgSnapshot_0_dbgj4vyzj1 dest_0){
  nimStrDestroy(dest_0.name_0);}
DbgSnapshot_0_dbgj4vyzj1 eQdupQ_SX44bgX53napshot0dbgj4vyzj1_0_dbgj4vyzj1(DbgSnapshot_0_dbgj4vyzj1 src_0){
  DbgSnapshot_0_dbgj4vyzj1 dest_0;
  string_0_sysvq0asl X60Qx_318 = nimStrDup(src_0.name_0);
  dest_0.name_0 = X60Qx_318;
  dest_0.pid_0 = src_0.pid_0;
  dest_0.wake_0 = src_0.wake_0;
  return dest_0;}
void eQdestroyQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1(Breakpoint_0_dbgj4vyzj1* dest_0){
  nimStrDestroy((*dest_0).file_0);
  nimStrDestroy((*dest_0).funcName_0);}
void eQwasmovedQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1(Breakpoint_0_dbgj4vyzj1* dest_0){
  nimStrWasMoved((&(*dest_0).funcName_0));
  nimStrWasMoved((&(*dest_0).file_0));}
Breakpoint_0_dbgj4vyzj1 eQdupQ_SX42reakpoint0dbgj4vyzj1_0_dbgj4vyzj1(Breakpoint_0_dbgj4vyzj1* src_0){
  Breakpoint_0_dbgj4vyzj1 dest_0;
  dest_0.kind_0 = (*src_0).kind_0;
  dest_0.line_0 = (*src_0).line_0;
  string_0_sysvq0asl X60Qx_319 = nimStrDup((*src_0).funcName_0);
  dest_0.funcName_0 = X60Qx_319;
  string_0_sysvq0asl X60Qx_320 = nimStrDup((*src_0).file_0);
  dest_0.file_0 = X60Qx_320;
  dest_0.enabled_0 = (*src_0).enabled_0;
  return dest_0;}
void eQdestroyQ_SX44ebugX43onfig0dbgj4vyzj1_0_dbgj4vyzj1(DebugConfig_0_dbgj4vyzj1 dest_0){
  eQdestroy_1_Ivioh0a_aow7lb5cq1(dest_0.expand_0);
  eQdestroy_1_I1pplm51_dbgj4vyzj1(dest_0.breakpoints_0);}
void eQwasmovedQ_SX44ebugX43onfig0dbgj4vyzj1_0_dbgj4vyzj1(DebugConfig_0_dbgj4vyzj1* dest_0){
  eQwasMoved_1_Isgtw04_dbgj4vyzj1((&(*dest_0).breakpoints_0));
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&(*dest_0).expand_0));}
void eQdestroyQ_SX56arX53nap0dbgj4vyzj1_0_dbgj4vyzj1(VarSnap_0_dbgj4vyzj1 dest_0){
  nimStrDestroy(dest_0.value_0);
  nimStrDestroy(dest_0.name_0);}
void eQdestroyQ_SX42reakX48it0dbgj4vyzj1_0_dbgj4vyzj1(BreakHit_0_dbgj4vyzj1* dest_0){
  eQdestroy_1_If2c8og1_dbgj4vyzj1((*dest_0).vars_0);
  nimStrDestroy((*dest_0).funcName_0);
  nimStrDestroy((*dest_0).file_0);}
void eQwasmovedQ_SX42reakX48it0dbgj4vyzj1_0_dbgj4vyzj1(BreakHit_0_dbgj4vyzj1* dest_0){
  nimStrWasMoved((&(*dest_0).file_0));
  nimStrWasMoved((&(*dest_0).funcName_0));
  eQwasMoved_1_I507go6_dbgj4vyzj1((&(*dest_0).vars_0));}
void X60Qini_0_dbgj4vyzj1(void){
  if (X60QiniGuard_0_dbgj4vyzj1){
    return;}
  X60QiniGuard_0_dbgj4vyzj1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();}
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
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
