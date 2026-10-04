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
NIM_THREADVAR NB8 LENGC_ERR_;
#include <stdio.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct seq_0_I50urnw_chu5m1rja1 seq_0_I50urnw_chu5m1rja1;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct CallEvent_0_trakthy001 CallEvent_0_trakthy001;
typedef struct EvalEvent_0_trakthy001 EvalEvent_0_trakthy001;
typedef struct BranchEvent_0_trakthy001 BranchEvent_0_trakthy001;
typedef struct Step_0_trakthy001 Step_0_trakthy001;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct Cursor_0_nifb6mq6y1 Cursor_0_nifb6mq6y1;
typedef struct Proc_0_chu5m1rja1 Proc_0_chu5m1rja1;
typedef struct MagicSpec_0_chu5m1rja1 MagicSpec_0_chu5m1rja1;
typedef struct ConvSpec_0_chu5m1rja1 ConvSpec_0_chu5m1rja1;
typedef struct GatedCall_0_chu5m1rja1 GatedCall_0_chu5m1rja1;
typedef struct ObjInfo_0_chu5m1rja1 ObjInfo_0_chu5m1rja1;
typedef struct ObjSpec_0_chu5m1rja1 ObjSpec_0_chu5m1rja1;
typedef struct MethodSite_0_chu5m1rja1 MethodSite_0_chu5m1rja1;
typedef struct MethodEntry_0_chu5m1rja1 MethodEntry_0_chu5m1rja1;
typedef struct Instr_0_chu5m1rja1 Instr_0_chu5m1rja1;
typedef struct GlobalSeed_0_chu5m1rja1 GlobalSeed_0_chu5m1rja1;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689 X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1 X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251)(void);
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct seq_0_Iygo52q1_hos5i19e11{
  NI32 len_0;
  FILE** data_0;}
seq_0_Iygo52q1_hos5i19e11;
typedef struct seq_0_I9xd2d01_hos5i19e11{
  NI32 len_0;
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** data_0;}
seq_0_I9xd2d01_hos5i19e11;
typedef N_NIMCALL_PTR(Value_0_valzr1t4f,  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251)(NI64, string_0_sysvq0asl, seq_0_I50urnw_chu5m1rja1, NB8*);
typedef struct OutSink_Obj_0_natd5co251{
  string_0_sysvq0asl outBuf_0;
  string_0_sysvq0asl errBuf_0;
  NI32 exitCode_0;
  NB8 didQQuit_0;
  string_0_sysvq0asl inBuf_0;
  NI32 inPos_0;
  NB8 inLoaded_0;
  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251 inLoad_0;
  string_0_sysvq0asl progName_0;
  seq_0_Ixdx2fh1_ast8ri79k argv_0;
  seq_0_Iygo52q1_hos5i19e11 fds_0;
  seq_0_I9xd2d01_hos5i19e11 pipeFds_0;
  seq_0_Ixdx2fh1_ast8ri79k envKeys_0;
  seq_0_Ixdx2fh1_ast8ri79k envVals_0;
  NB8 envSeeded_0;
  seq_0_Ixdx2fh1_ast8ri79k failedReads_0;
  NI32 failedReadCount_0;
  NI64 hostContext_0;
  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251 hostCall_0;}
OutSink_Obj_0_natd5co251;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5{
  NI r_00;
  OutSink_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef NU8 TraceMode_0_trakthy001;

#define tmOff_0_trakthy001 ((NU8)0)
#define tmCalls_0_trakthy001 ((NU8)1)
#define tmFull_0_trakthy001 ((NU8)2)
#define tmProfile_0_trakthy001 ((NU8)3)
typedef struct seq_0_I00yatg_trakthy001{
  NI32 len_0;
  CallEvent_0_trakthy001* data_0;}
seq_0_I00yatg_trakthy001;
typedef struct seq_0_Ins76rj1_trakthy001{
  NI32 len_0;
  EvalEvent_0_trakthy001* data_0;}
seq_0_Ins76rj1_trakthy001;
typedef struct seq_0_Iuignwf1_trakthy001{
  NI32 len_0;
  BranchEvent_0_trakthy001* data_0;}
seq_0_Iuignwf1_trakthy001;
typedef struct seq_0_Is6l9yr_trakthy001{
  NI32 len_0;
  Step_0_trakthy001* data_0;}
seq_0_Is6l9yr_trakthy001;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
typedef struct seq_0_Ix7ee6h_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* data_0;}
seq_0_Ix7ee6h_sempjk6bn1;
typedef struct seq_0_Ikxuplm1_filqx2b6r1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_filqx2b6r1;
typedef struct Table_0_Idzlvr_sempjk6bn1{
  seq_0_Ix7ee6h_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Idzlvr_sempjk6bn1;
typedef struct seq_0_Iflf8jf1_fiepkwzpc{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_fiepkwzpc;
typedef struct Trace_Obj_0_trakthy001{
  TraceMode_0_trakthy001 mode_0;
  NI32 depth_0;
  string_0_sysvq0asl text_0;
  seq_0_I00yatg_trakthy001 calls_0;
  seq_0_Ins76rj1_trakthy001 evals_0;
  seq_0_Iuignwf1_trakthy001 branches_0;
  seq_0_Is6l9yr_trakthy001 steps_0;
  NI32 nCalls_0;
  NI32 maxDepth_0;
  NB8 truncated_0;
  NI32 lines_0;
  seq_0_Ift2sne_chu5m1rja1 frames_0;
  Table_0_Idzlvr_sempjk6bn1 prof_0;
  NI32 maxRecordDepth_0;
  seq_0_Iflf8jf1_fiepkwzpc recStack_0;}
Trace_Obj_0_trakthy001;
typedef struct X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001{
  NI r_00;
  Trace_Obj_0_trakthy001 d_00;}
X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct X60Qt_0_IAarraySX43ursor0nifb6mq6y1S0_comaa5xpt1{
  Cursor_0_nifb6mq6y1 a[0];}
X60Qt_0_IAarraySX43ursor0nifb6mq6y1S0_comaa5xpt1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct JsValue_0_jsfc0lwq21{
  NI32 h_0;}
JsValue_0_jsfc0lwq21;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef struct openArray_0_Imqex5f1_comaa5xpt1{
  Cursor_0_nifb6mq6y1* a_0;
  NI32 len_0;}
openArray_0_Imqex5f1_comaa5xpt1;
typedef struct seq_0_Inaua171_chu5m1rja1{
  NI32 len_0;
  Proc_0_chu5m1rja1* data_0;}
seq_0_Inaua171_chu5m1rja1;
typedef struct seq_0_I50urnw_chu5m1rja1{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_chu5m1rja1;
typedef struct seq_0_Ie9rikd_chu5m1rja1{
  NI32 len_0;
  MagicSpec_0_chu5m1rja1* data_0;}
seq_0_Ie9rikd_chu5m1rja1;
typedef struct seq_0_Iknt7a3_chu5m1rja1{
  NI32 len_0;
  ConvSpec_0_chu5m1rja1* data_0;}
seq_0_Iknt7a3_chu5m1rja1;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct seq_0_Id5h4uf_chu5m1rja1{
  NI32 len_0;
  GatedCall_0_chu5m1rja1* data_0;}
seq_0_Id5h4uf_chu5m1rja1;
typedef struct seq_0_I2neof81_chu5m1rja1{
  NI32 len_0;
  ObjInfo_0_chu5m1rja1* data_0;}
seq_0_I2neof81_chu5m1rja1;
typedef struct seq_0_Isww99s_chu5m1rja1{
  NI32 len_0;
  ObjSpec_0_chu5m1rja1* data_0;}
seq_0_Isww99s_chu5m1rja1;
typedef struct seq_0_Ir067xu1_chu5m1rja1{
  NI32 len_0;
  MethodSite_0_chu5m1rja1* data_0;}
seq_0_Ir067xu1_chu5m1rja1;
typedef struct seq_0_I88k8j01_chu5m1rja1{
  NI32 len_0;
  MethodEntry_0_chu5m1rja1* data_0;}
seq_0_I88k8j01_chu5m1rja1;
typedef struct seq_0_Izok7jt1_chu5m1rja1{
  NI32 len_0;
  Instr_0_chu5m1rja1* data_0;}
seq_0_Izok7jt1_chu5m1rja1;
typedef struct Proc_0_chu5m1rja1{
  seq_0_Izok7jt1_chu5m1rja1 code_0;
  seq_0_Ift2sne_chu5m1rja1 lines_0;
  NI32 numParams_0;
  NI32 numLocals_0;
  NI32 resultSlot_0;
  string_0_sysvq0asl name_0;
  NB8 isPassive_0;
  seq_0_In6doa_ast8ri79k slotSyms_0;}
Proc_0_chu5m1rja1;
typedef struct seq_0_Iioxqbu_chu5m1rja1{
  NI32 len_0;
  GlobalSeed_0_chu5m1rja1* data_0;}
seq_0_Iioxqbu_chu5m1rja1;
typedef struct VmProgram_0_chu5m1rja1{
  seq_0_Inaua171_chu5m1rja1 procs_0;
  seq_0_I50urnw_chu5m1rja1 consts_0;
  seq_0_Ie9rikd_chu5m1rja1 magics_0;
  seq_0_Iknt7a3_chu5m1rja1 convs_0;
  seq_0_Ixdx2fh1_ast8ri79k natives_0;
  seq_0_In6doa_ast8ri79k enumWraps_0;
  seq_0_Id5h4uf_chu5m1rja1 gatedCalls_0;
  seq_0_I2neof81_chu5m1rja1 objInfos_0;
  seq_0_In6doa_ast8ri79k fieldSyms_0;
  seq_0_Isww99s_chu5m1rja1 objSpecs_0;
  seq_0_In6doa_ast8ri79k typeSyms_0;
  seq_0_In6doa_ast8ri79k envSyms_0;
  seq_0_Ir067xu1_chu5m1rja1 methodSites_0;
  seq_0_I88k8j01_chu5m1rja1 methodTable_0;
  Proc_0_chu5m1rja1 top_0;
  seq_0_Inaua171_chu5m1rja1 inits_0;
  NI32 numGlobals_0;
  seq_0_Iioxqbu_chu5m1rja1 globalSeeds_0;}
VmProgram_0_chu5m1rja1;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PipeBuf_Obj_0_natd5co251{
  string_0_sysvq0asl data_0;
  NI32 rpos_0;
  NI32 writeFd_0;
  NB8 writeClosed_0;}
PipeBuf_Obj_0_natd5co251;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11{
  NI r_00;
  PipeBuf_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef NU8 ValueKind_0_valzr1t4f;

#define vkNil_0_valzr1t4f ((NU8)0)
#define vkInt_0_valzr1t4f ((NU8)1)
#define vkUInt_0_valzr1t4f ((NU8)2)
#define vkFloat_0_valzr1t4f ((NU8)3)
#define vkBool_0_valzr1t4f ((NU8)4)
#define vkChar_0_valzr1t4f ((NU8)5)
#define vkString_0_valzr1t4f ((NU8)6)
#define vkEnum_0_valzr1t4f ((NU8)7)
#define vkSeq_0_valzr1t4f ((NU8)8)
#define vkArray_0_valzr1t4f ((NU8)9)
#define vkTuple_0_valzr1t4f ((NU8)10)
#define vkObject_0_valzr1t4f ((NU8)11)
#define vkRef_0_valzr1t4f ((NU8)12)
#define vkPtr_0_valzr1t4f ((NU8)13)
#define vkSet_0_valzr1t4f ((NU8)14)
#define vkProc_0_valzr1t4f ((NU8)15)
#define vkStream_0_valzr1t4f ((NU8)16)
#define vkCont_0_valzr1t4f ((NU8)17)
typedef struct xint_0_xinat3x34{
  NB8 nan_0;
  NB8 neg_0;
  NU64 val_0;}
xint_0_xinat3x34;
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
typedef struct Value_0_valzr1t4f{
  ValueKind_0_valzr1t4f kind_0;
  union {
    struct {
      }
    ;
    struct {
      xint_0_xinat3x34 ival_0;
      NI32 bits_0;}
    ;
    struct {
      NF64 fval_0;
      NI32 fbits_0;}
    ;
    struct {
      NB8 bval_0;}
    ;
    struct {
      NC8 cval_0;}
    ;
    struct {
      string_0_sysvq0asl sval_0;}
    ;
    struct {
      NI32 eord_0;
      NU32 ekind_0;
      string_0_sysvq0asl ename_0;}
    ;
    struct {
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sq_0;}
    ;
    struct {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arr_0;}
    ;
    struct {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* obj_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* rf_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* loc_0;
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0;
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0;
      NI32 base_0;
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0;
      NI32 foff_0;
      NI16 elemBits_0;
      TCode_0_valzr1t4f ecode_0;
      NU32 etype_0;}
    ;
    struct {
      X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* st_0;}
    ;
    struct {
      NU32 fn_0;
      NI32 pidx_0;
      X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_0;
      NI32 resume_0;}
    ;
    struct {
      NB8 toErr_0;}
    ;
    struct {
      X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* coro_0;}
    ;}
  ;}
Value_0_valzr1t4f;
typedef struct CallEvent_0_trakthy001{
  string_0_sysvq0asl callee_0;
  seq_0_I50urnw_chu5m1rja1 args_0;
  seq_0_Ixdx2fh1_ast8ri79k argsR_0;
  Value_0_valzr1t4f ret_0;
  string_0_sysvq0asl retR_0;
  NI32 depth_0;
  NI32 line_0;
  string_0_sysvq0asl file_0;}
CallEvent_0_trakthy001;
typedef struct EvalEvent_0_trakthy001{
  string_0_sysvq0asl code_0;
  NI32 line_0;
  NI32 col_0;
  Value_0_valzr1t4f val_0;}
EvalEvent_0_trakthy001;
typedef struct BranchEvent_0_trakthy001{
  string_0_sysvq0asl form_0;
  string_0_sysvq0asl sel_0;
  string_0_sysvq0asl chose_0;
  string_0_sysvq0asl callee_0;
  NI32 line_0;
  NI32 depth_0;}
BranchEvent_0_trakthy001;
typedef NU8 StepKind_0_trakthy001;

#define skEnter_0_trakthy001 ((NU8)0)
#define skExit_0_trakthy001 ((NU8)1)
#define skBranch_0_trakthy001 ((NU8)2)
typedef struct Step_0_trakthy001{
  StepKind_0_trakthy001 kind_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl site_0;}
Step_0_trakthy001;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef NU16 NimonyExpr_0_nimry5ra91;

#define NoExpr_0_nimry5ra91 ((NU16)0)
#define ErrX_0_nimry5ra91 ((NU16)1)
#define SufX_0_nimry5ra91 ((NU16)2)
#define AtX_0_nimry5ra91 ((NU16)3)
#define DerefX_0_nimry5ra91 ((NU16)4)
#define DotX_0_nimry5ra91 ((NU16)5)
#define PatX_0_nimry5ra91 ((NU16)6)
#define ParX_0_nimry5ra91 ((NU16)7)
#define AddrX_0_nimry5ra91 ((NU16)8)
#define NilX_0_nimry5ra91 ((NU16)9)
#define InfX_0_nimry5ra91 ((NU16)12)
#define NeginfX_0_nimry5ra91 ((NU16)13)
#define NanX_0_nimry5ra91 ((NU16)14)
#define FalseX_0_nimry5ra91 ((NU16)15)
#define TrueX_0_nimry5ra91 ((NU16)16)
#define AndX_0_nimry5ra91 ((NU16)17)
#define OrX_0_nimry5ra91 ((NU16)18)
#define XorX_0_nimry5ra91 ((NU16)19)
#define NotX_0_nimry5ra91 ((NU16)20)
#define NegX_0_nimry5ra91 ((NU16)21)
#define SizeofX_0_nimry5ra91 ((NU16)22)
#define AlignofX_0_nimry5ra91 ((NU16)23)
#define OffsetofX_0_nimry5ra91 ((NU16)24)
#define OconstrX_0_nimry5ra91 ((NU16)25)
#define AconstrX_0_nimry5ra91 ((NU16)26)
#define BracketX_0_nimry5ra91 ((NU16)27)
#define CurlyX_0_nimry5ra91 ((NU16)28)
#define CurlyatX_0_nimry5ra91 ((NU16)29)
#define KvX_0_nimry5ra91 ((NU16)30)
#define OvfX_0_nimry5ra91 ((NU16)32)
#define AddX_0_nimry5ra91 ((NU16)33)
#define SubX_0_nimry5ra91 ((NU16)34)
#define MulX_0_nimry5ra91 ((NU16)35)
#define DivX_0_nimry5ra91 ((NU16)36)
#define ModX_0_nimry5ra91 ((NU16)37)
#define ShrX_0_nimry5ra91 ((NU16)38)
#define ShlX_0_nimry5ra91 ((NU16)39)
#define BitandX_0_nimry5ra91 ((NU16)40)
#define BitorX_0_nimry5ra91 ((NU16)41)
#define BitxorX_0_nimry5ra91 ((NU16)42)
#define BitnotX_0_nimry5ra91 ((NU16)43)
#define EqX_0_nimry5ra91 ((NU16)44)
#define NeqX_0_nimry5ra91 ((NU16)45)
#define LeX_0_nimry5ra91 ((NU16)46)
#define LtX_0_nimry5ra91 ((NU16)47)
#define CastX_0_nimry5ra91 ((NU16)48)
#define ConvX_0_nimry5ra91 ((NU16)49)
#define CallX_0_nimry5ra91 ((NU16)50)
#define CmdX_0_nimry5ra91 ((NU16)51)
#define CchoiceX_0_nimry5ra91 ((NU16)80)
#define OchoiceX_0_nimry5ra91 ((NU16)81)
#define PragmaxX_0_nimry5ra91 ((NU16)141)
#define QQuotedX_0_nimry5ra91 ((NU16)235)
#define HderefX_0_nimry5ra91 ((NU16)236)
#define DdotX_0_nimry5ra91 ((NU16)237)
#define HaddrX_0_nimry5ra91 ((NU16)238)
#define NewrefX_0_nimry5ra91 ((NU16)239)
#define NewobjX_0_nimry5ra91 ((NU16)240)
#define TupX_0_nimry5ra91 ((NU16)241)
#define TupconstrX_0_nimry5ra91 ((NU16)242)
#define SetconstrX_0_nimry5ra91 ((NU16)243)
#define TabconstrX_0_nimry5ra91 ((NU16)244)
#define AshrX_0_nimry5ra91 ((NU16)245)
#define BaseobjX_0_nimry5ra91 ((NU16)246)
#define HconvX_0_nimry5ra91 ((NU16)247)
#define DconvX_0_nimry5ra91 ((NU16)248)
#define CallstrlitX_0_nimry5ra91 ((NU16)249)
#define InfixX_0_nimry5ra91 ((NU16)250)
#define PrefixX_0_nimry5ra91 ((NU16)251)
#define HcallX_0_nimry5ra91 ((NU16)252)
#define CompilesX_0_nimry5ra91 ((NU16)253)
#define DeclaredX_0_nimry5ra91 ((NU16)254)
#define DefinedX_0_nimry5ra91 ((NU16)255)
#define AstToStrX_0_nimry5ra91 ((NU16)256)
#define BindSymX_0_nimry5ra91 ((NU16)257)
#define BindSymNameX_0_nimry5ra91 ((NU16)258)
#define InstanceofX_0_nimry5ra91 ((NU16)259)
#define ProccallX_0_nimry5ra91 ((NU16)260)
#define HighX_0_nimry5ra91 ((NU16)261)
#define LowX_0_nimry5ra91 ((NU16)262)
#define TypeofX_0_nimry5ra91 ((NU16)263)
#define UnpackX_0_nimry5ra91 ((NU16)264)
#define FieldsX_0_nimry5ra91 ((NU16)265)
#define FieldpairsX_0_nimry5ra91 ((NU16)266)
#define EnumtostrX_0_nimry5ra91 ((NU16)267)
#define IsmainmoduleX_0_nimry5ra91 ((NU16)268)
#define DefaultobjX_0_nimry5ra91 ((NU16)269)
#define DefaulttupX_0_nimry5ra91 ((NU16)270)
#define DefaultdistinctX_0_nimry5ra91 ((NU16)271)
#define DelayX_0_nimry5ra91 ((NU16)272)
#define Delay0X_0_nimry5ra91 ((NU16)273)
#define SuspendX_0_nimry5ra91 ((NU16)274)
#define ExprX_0_nimry5ra91 ((NU16)275)
#define DoX_0_nimry5ra91 ((NU16)276)
#define ArratX_0_nimry5ra91 ((NU16)277)
#define TupatX_0_nimry5ra91 ((NU16)278)
#define PlussetX_0_nimry5ra91 ((NU16)279)
#define MinussetX_0_nimry5ra91 ((NU16)280)
#define MulsetX_0_nimry5ra91 ((NU16)281)
#define XorsetX_0_nimry5ra91 ((NU16)282)
#define EqsetX_0_nimry5ra91 ((NU16)283)
#define LesetX_0_nimry5ra91 ((NU16)284)
#define LtsetX_0_nimry5ra91 ((NU16)285)
#define InsetX_0_nimry5ra91 ((NU16)286)
#define CardX_0_nimry5ra91 ((NU16)287)
#define EmoveX_0_nimry5ra91 ((NU16)288)
#define DestroyX_0_nimry5ra91 ((NU16)289)
#define DupX_0_nimry5ra91 ((NU16)290)
#define CopyX_0_nimry5ra91 ((NU16)291)
#define WasmovedX_0_nimry5ra91 ((NU16)292)
#define SinkhX_0_nimry5ra91 ((NU16)293)
#define TraceX_0_nimry5ra91 ((NU16)294)
#define InternalTypeNameX_0_nimry5ra91 ((NU16)319)
#define InternalFieldPairsX_0_nimry5ra91 ((NU16)320)
#define FailedX_0_nimry5ra91 ((NU16)321)
#define IsX_0_nimry5ra91 ((NU16)322)
#define EnvpX_0_nimry5ra91 ((NU16)323)
#define ToClosureX_0_nimry5ra91 ((NU16)341)
typedef struct MagicSpec_0_chu5m1rja1{
  NimonyExpr_0_nimry5ra91 op_0;
  NI32 bits_0;
  NB8 signed_0;
  NB8 caseEq_0;}
MagicSpec_0_chu5m1rja1;
typedef struct ConvSpec_0_chu5m1rja1{
  NI32 mode_0;
  NI32 bits_0;
  NB8 signed_0;
  TCode_0_valzr1t4f code_0;
  NU32 etype_0;}
ConvSpec_0_chu5m1rja1;
typedef struct GatedCall_0_chu5m1rja1{
  NI32 nat_0;
  NI32 fallback_0;
  NB8 dollarScalar_0;}
GatedCall_0_chu5m1rja1;
typedef struct ObjInfo_0_chu5m1rja1{
  NU32 typeSym_0;
  seq_0_In6doa_ast8ri79k fieldSyms_0;}
ObjInfo_0_chu5m1rja1;
typedef struct ObjSpec_0_chu5m1rja1{
  NU32 typeSym_0;
  NB8 isRef_0;
  seq_0_In6doa_ast8ri79k fields_0;}
ObjSpec_0_chu5m1rja1;
typedef struct MethodSite_0_chu5m1rja1{
  NU32 staticFn_0;
  NI32 fallbackIdx_0;}
MethodSite_0_chu5m1rja1;
typedef struct MethodEntry_0_chu5m1rja1{
  NU32 sym_0;
  NI32 idx_0;}
MethodEntry_0_chu5m1rja1;
typedef NU8 OpCode_0_chu5m1rja1;

#define opPushConst_0_chu5m1rja1 ((NU8)0)
#define opPushNil_0_chu5m1rja1 ((NU8)1)
#define opPushEmptySeq_0_chu5m1rja1 ((NU8)2)
#define opPushEmptyStr_0_chu5m1rja1 ((NU8)3)
#define opPop_0_chu5m1rja1 ((NU8)4)
#define opLoadLocal_0_chu5m1rja1 ((NU8)5)
#define opStoreLocal_0_chu5m1rja1 ((NU8)6)
#define opLoadLocalAddr_0_chu5m1rja1 ((NU8)7)
#define opLoadGlobal_0_chu5m1rja1 ((NU8)8)
#define opStoreGlobal_0_chu5m1rja1 ((NU8)9)
#define opLoadGlobalAddr_0_chu5m1rja1 ((NU8)10)
#define opLoadGlobalInit_0_chu5m1rja1 ((NU8)11)
#define opLoadGlobalAddrInit_0_chu5m1rja1 ((NU8)12)
#define opDeref_0_chu5m1rja1 ((NU8)13)
#define opStoreDeref_0_chu5m1rja1 ((NU8)14)
#define opWasMoved_0_chu5m1rja1 ((NU8)15)
#define opKeepOvfBegin_0_chu5m1rja1 ((NU8)16)
#define opKeepOvfEnd_0_chu5m1rja1 ((NU8)17)
#define opOverflowFlag_0_chu5m1rja1 ((NU8)18)
#define opBinMagic_0_chu5m1rja1 ((NU8)19)
#define opUnMagic_0_chu5m1rja1 ((NU8)20)
#define opConv_0_chu5m1rja1 ((NU8)21)
#define opRewidth_0_chu5m1rja1 ((NU8)22)
#define opEnumWrap_0_chu5m1rja1 ((NU8)23)
#define opJump_0_chu5m1rja1 ((NU8)24)
#define opJumpIfFalse_0_chu5m1rja1 ((NU8)25)
#define opCall_0_chu5m1rja1 ((NU8)26)
#define opCallIndirect_0_chu5m1rja1 ((NU8)27)
#define opCallMethod_0_chu5m1rja1 ((NU8)28)
#define opCallNested_0_chu5m1rja1 ((NU8)29)
#define opLoadEnv_0_chu5m1rja1 ((NU8)30)
#define opStoreEnv_0_chu5m1rja1 ((NU8)31)
#define opLoadEnvAddr_0_chu5m1rja1 ((NU8)32)
#define opCaptureEnv_0_chu5m1rja1 ((NU8)33)
#define opCallNative_0_chu5m1rja1 ((NU8)34)
#define opCallNativeGated_0_chu5m1rja1 ((NU8)35)
#define opRet_0_chu5m1rja1 ((NU8)36)
#define opMakeObj_0_chu5m1rja1 ((NU8)37)
#define opMakeRef_0_chu5m1rja1 ((NU8)38)
#define opNewRefInit_0_chu5m1rja1 ((NU8)39)
#define opMakeTuple_0_chu5m1rja1 ((NU8)40)
#define opLoadField_0_chu5m1rja1 ((NU8)41)
#define opLoadFieldAddr_0_chu5m1rja1 ((NU8)42)
#define opTupIndex_0_chu5m1rja1 ((NU8)43)
#define opTupIndexAddr_0_chu5m1rja1 ((NU8)44)
#define opMakeArray_0_chu5m1rja1 ((NU8)45)
#define opMakeSeq_0_chu5m1rja1 ((NU8)46)
#define opFillSeqDefaults_0_chu5m1rja1 ((NU8)47)
#define opIndexGet_0_chu5m1rja1 ((NU8)48)
#define opIndexAddr_0_chu5m1rja1 ((NU8)49)
#define opIndexSet_0_chu5m1rja1 ((NU8)50)
#define opCopyAssign_0_chu5m1rja1 ((NU8)51)
#define opNewSet_0_chu5m1rja1 ((NU8)52)
#define opSetInclTos_0_chu5m1rja1 ((NU8)53)
#define opSetInclRangeTos_0_chu5m1rja1 ((NU8)54)
#define opSetIncl_0_chu5m1rja1 ((NU8)55)
#define opSetExcl_0_chu5m1rja1 ((NU8)56)
#define opInSet_0_chu5m1rja1 ((NU8)57)
#define opCard_0_chu5m1rja1 ((NU8)58)
#define opSetCombine_0_chu5m1rja1 ((NU8)59)
#define opSetCmp_0_chu5m1rja1 ((NU8)60)
#define opNewObj_0_chu5m1rja1 ((NU8)61)
#define opGetField_0_chu5m1rja1 ((NU8)62)
#define opInstanceOf_0_chu5m1rja1 ((NU8)63)
#define opSetupTry_0_chu5m1rja1 ((NU8)64)
#define opPopTry_0_chu5m1rja1 ((NU8)65)
#define opRaise_0_chu5m1rja1 ((NU8)66)
#define opReRaise_0_chu5m1rja1 ((NU8)67)
#define opEndFinally_0_chu5m1rja1 ((NU8)68)
#define opLoadExc_0_chu5m1rja1 ((NU8)69)
#define opFinMark_0_chu5m1rja1 ((NU8)70)
#define opFinSkip_0_chu5m1rja1 ((NU8)71)
#define opYield_0_chu5m1rja1 ((NU8)72)
#define opCoroInit_0_chu5m1rja1 ((NU8)73)
#define opCoroResume_0_chu5m1rja1 ((NU8)74)
#define opSetScheduler_0_chu5m1rja1 ((NU8)75)
#define opDelay0_0_chu5m1rja1 ((NU8)76)
#define opDelay_0_chu5m1rja1 ((NU8)77)
#define opSuspend_0_chu5m1rja1 ((NU8)78)
#define opPassiveCall_0_chu5m1rja1 ((NU8)79)
#define opDrivePassive_0_chu5m1rja1 ((NU8)80)
#define opPassiveMethodCall_0_chu5m1rja1 ((NU8)81)
#define opDrivePassiveMethod_0_chu5m1rja1 ((NU8)82)
typedef struct Instr_0_chu5m1rja1{
  OpCode_0_chu5m1rja1 op_0;
  NI32 a_0;
  NI32 b_0;}
Instr_0_chu5m1rja1;
typedef struct GlobalSeed_0_chu5m1rja1{
  NI32 slot_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl cname_0;
  Value_0_valzr1t4f v_0;}
GlobalSeed_0_chu5m1rja1;
typedef struct seq_0_Iw8xl5b1_flaksyopx1{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_flaksyopx1;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_ast8ri79k names_0;
  seq_0_Iw8xl5b1_flaksyopx1 cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct Cell_Obj_0_valzr1t4f{
  Value_0_valzr1t4f v_0;}
Cell_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  Cell_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef NU8 RegionKind_0_valzr1t4f;

#define rkBytes_0_valzr1t4f ((NU8)0)
#define rkSeq_0_valzr1t4f ((NU8)1)
#define rkArr_0_valzr1t4f ((NU8)2)
#define rkStr_0_valzr1t4f ((NU8)3)
#define rkCell_0_valzr1t4f ((NU8)4)
#define rkObj_0_valzr1t4f ((NU8)5)
#define rkForeign_0_valzr1t4f ((NU8)6)
typedef struct seq_0_Incv1wn_explnj22x1{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_explnj22x1;
typedef struct FlatRegion_Obj_0_valzr1t4f{
  RegionKind_0_valzr1t4f kind_0;
  union {
    struct {
      seq_0_Incv1wn_explnj22x1 bytes_0;
      NB8 freed_0;
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* objOverlay_0;}
    ;
    struct {
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sbox_0;
      NI32 sEbits_0;
      TCode_0_valzr1t4f sEcode_0;}
    ;
    struct {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* abox_0;
      NI32 aEbits_0;
      TCode_0_valzr1t4f aEcode_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* scell_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* ccell_0;}
    ;
    struct {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* obox_0;
      seq_0_Ift2sne_chu5m1rja1 offs_0;}
    ;
    struct {
      NU64 haddr_0;
      NI32 hlen_0;}
    ;}
  ;}
FlatRegion_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  FlatRegion_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IAarrayAuS64ZS4_runot4689{
  NU64 a[4];}
X60Qt_0_IAarrayAuS64ZS4_runot4689;
typedef struct SetBox_Obj_0_valzr1t4f{
  X60Qt_0_IAarrayAuS64ZS4_runot4689 words_0;}
SetBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689{
  NI r_00;
  SetBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct ClosureEnv_Obj_0_valzr1t4f{
  seq_0_In6doa_ast8ri79k vars_0;
  seq_0_Iw8xl5b1_flaksyopx1 cells_0;
  X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* coro_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;}
ClosureEnv_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1{
  NI r_00;
  ClosureEnv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
void eQwasmovedQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5** dest_0);
void eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* dest_0);
void eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_web5o9ahf1(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* dest_0);
extern void installWebVfs_0_web91l7of(void);
extern JsValue_0_jsfc0lwq21 global_0_jsfc0lwq21(string_0_sysvq0asl name_8);
extern string_0_sysvq0asl toStr_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 v_7);
extern void loadWebModules_0_web91l7of(string_0_sysvq0asl framed_0);
extern void publishMainModule_0_web91l7of(string_0_sysvq0asl src_0);
extern void setupProgramForTesting_0_prorcx25w1(string_0_sysvq0asl dir_0, string_0_sysvq0asl file_0, string_0_sysvq0asl ext_0);
extern LongString_0_sysvq0asl const strlit_0_I5065733472155119234_comaa5xpt1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern TokenBuf_0_nifb6mq6y1 parseFromBuffer_0_nifb6mq6y1(string_0_sysvq0asl input_0, string_0_sysvq0asl thisModule_0, NI32 sizeHint_0);
extern Cursor_0_nifb6mq6y1 beginRead_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_4);
extern X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* newOutSink_0_natd5co251(void);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* newTrace_0_trakthy001(TraceMode_0_trakthy001 mode_0);
static inline openArray_0_Imqex5f1_comaa5xpt1 toOpenArray_0_Imravs1_comaa5xpt1(X60Qt_0_IAarraySX43ursor0nifb6mq6y1S0_comaa5xpt1* x_19);
extern VmProgram_0_chu5m1rja1 compileModule_0_comaa5xpt1(Cursor_0_nifb6mq6y1 root_2, openArray_0_Imqex5f1_comaa5xpt1 importRoots_0);
extern void runProgram_0_vmtuaxp6(VmProgram_0_chu5m1rja1* prog_0, X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_1, X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* tr_0);
extern void eQdestroyQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1(VmProgram_0_chu5m1rja1* dest_0);
extern void eQdestroy_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 x_2);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3);
extern JsValue_0_jsfc0lwq21 toJs_3_jsfc0lwq21(string_0_sysvq0asl s_0);
extern void set_0_jsfc0lwq21(JsValue_0_jsfc0lwq21 obj_9, string_0_sysvq0asl name_10, JsValue_0_jsfc0lwq21 val_3);
static inline JsValue_0_jsfc0lwq21 toJs_0_jsfc0lwq21(NI32 x_4);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void eQdestroyQ_SX4futX53inkX4fbj0natd5co251_0_natd5co251(OutSink_Obj_0_natd5co251* dest_0);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void eQdestroyQ_SX54raceX4fbj0trakthy001_0_trakthy001(Trace_Obj_0_trakthy001* dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_natd5co251(void);
extern void X60Qini_0_trakthy001(void);
extern void X60Qini_0_chu5m1rja1(void);
extern void X60Qini_0_comaa5xpt1(void);
extern void X60Qini_0_vmtuaxp6(void);
extern void X60Qini_0_web91l7of(void);
extern void X60Qini_0_jsfc0lwq21(void);
extern void nimFlushStdStreams(void);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
extern NI32 _numToJs(NI32 x_0);
LongString_0_sysvq0asl const strlit_0_I8652765962980441160_web5o9ahf1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__aowli_mods"}
;
LongString_0_sysvq0asl const strlit_0_I16952481534133288743_web5o9ahf1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "webmod"}
;
LongString_0_sysvq0asl const strlit_0_I13015410432117533387_web5o9ahf1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__aowli_in"}
;
LongString_0_sysvq0asl const strlit_0_I9568650182260370108_web5o9ahf1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__aowli_src"}
;
LongString_0_sysvq0asl const strlit_0_I16664880105326712979_web5o9ahf1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "globalThis"}
;
LongString_0_sysvq0asl const strlit_0_I11811999825154579109_web5o9ahf1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__aowli_out"}
;
LongString_0_sysvq0asl const strlit_0_I14831203836371878571_web5o9ahf1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__aowli_err"}
;
LongString_0_sysvq0asl const strlit_0_I15127672453272209563_web5o9ahf1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "__aowli_exit"}
;
NB8 X60QiniGuard_0_web5o9ahf1;
NI32 cmdCount;
NC8** cmdLine;
NC8** nimEnviron;
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* runNif_0_web5o9ahf1(string_0_sysvq0asl src_0){
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* result_0;
  eQwasmovedQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1((&result_0));
  installWebVfs_0_web91l7of();
  JsValue_0_jsfc0lwq21 X60Qtmp_1 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I8652765962980441160_web5o9ahf1)}
  );
  string_0_sysvq0asl X60Qtmp_0 = toStr_0_jsfc0lwq21(X60Qtmp_1);
  loadWebModules_0_web91l7of(X60Qtmp_0);
  publishMainModule_0_web91l7of(src_0);
  setupProgramForTesting_0_prorcx25w1((string_0_sysvq0asl){
    .bytes_0 = 7810818u, .more_0 = NIM_NIL}
  , (string_0_sysvq0asl){
    .bytes_0 = 1650817022u, .more_0 = (&strlit_0_I16952481534133288743_web5o9ahf1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_comaa5xpt1)}
  );
  string_0_sysvq0asl X60Qx_0 = nimStrDup((string_0_sysvq0asl){
    .bytes_0 = 1650817022u, .more_0 = (&strlit_0_I16952481534133288743_web5o9ahf1)}
  );
  TokenBuf_0_nifb6mq6y1 buf_0 = parseFromBuffer_0_nifb6mq6y1(src_0, X60Qx_0, 100);
  Cursor_0_nifb6mq6y1 root_0 = beginRead_0_nifb6mq6y1((&buf_0));
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_0 = newOutSink_0_natd5co251();
  string_0_sysvq0asl* X60Qlhs_2 = (&(*sink_0).d_00.inBuf_0);
  JsValue_0_jsfc0lwq21 X60Qtmp_4 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I13015410432117533387_web5o9ahf1)}
  );
  string_0_sysvq0asl X60Qlhs_3 = toStr_0_jsfc0lwq21(X60Qtmp_4);
  nimStrDestroy((*X60Qlhs_2));
  (*X60Qlhs_2) = X60Qlhs_3;
  (*sink_0).d_00.inPos_0 = 0;
  X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* tr_0 = newTrace_0_trakthy001(0);
  X60Qt_0_IAarraySX43ursor0nifb6mq6y1S0_comaa5xpt1 X60QconstRefTemp_0 = (X60Qt_0_IAarraySX43ursor0nifb6mq6y1S0_comaa5xpt1){
    .a = {
      }}
  ;
  openArray_0_Imqex5f1_comaa5xpt1 X60Qx_1 = toOpenArray_0_Imravs1_comaa5xpt1((&X60QconstRefTemp_0));
  VmProgram_0_chu5m1rja1 prog_0 = compileModule_0_comaa5xpt1(root_0, X60Qx_1);
  runProgram_0_vmtuaxp6((&prog_0), sink_0, tr_0);
  eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1(result_0);
  result_0 = sink_0;
  eQwasmovedQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1((&sink_0));
  eQdestroyQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1((&prog_0));
  eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_web5o9ahf1(tr_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_4);
  eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1(sink_0);
  eQdestroy_0_nifb6mq6y1((&root_0));
  eQdestroy_1_nifb6mq6y1((&buf_0));
  nimStrDestroy(X60Qtmp_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_1);
  return result_0;
  eQdestroyQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1((&prog_0));
  eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_web5o9ahf1(tr_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_4);
  eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1(sink_0);
  eQdestroy_0_nifb6mq6y1((&root_0));
  eQdestroy_1_nifb6mq6y1((&buf_0));
  nimStrDestroy(X60Qtmp_0);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_1);
  return result_0;}
void aowliRun_0_web5o9ahf1(void){
  JsValue_0_jsfc0lwq21 X60Qtmp_5 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I9568650182260370108_web5o9ahf1)}
  );
  string_0_sysvq0asl src_1 = toStr_0_jsfc0lwq21(X60Qtmp_5);
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_1 = runNif_0_web5o9ahf1(src_1);
  JsValue_0_jsfc0lwq21 g_0 = global_0_jsfc0lwq21((string_0_sysvq0asl){
    .bytes_0 = 1869375486u, .more_0 = (&strlit_0_I16664880105326712979_web5o9ahf1)}
  );
  JsValue_0_jsfc0lwq21 X60Qtmp_6 = toJs_3_jsfc0lwq21((*sink_1).d_00.outBuf_0);
  set_0_jsfc0lwq21(g_0, (string_0_sysvq0asl){
    .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I11811999825154579109_web5o9ahf1)}
  , X60Qtmp_6);
  JsValue_0_jsfc0lwq21 X60Qtmp_7 = toJs_3_jsfc0lwq21((*sink_1).d_00.errBuf_0);
  set_0_jsfc0lwq21(g_0, (string_0_sysvq0asl){
    .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I14831203836371878571_web5o9ahf1)}
  , X60Qtmp_7);
  JsValue_0_jsfc0lwq21 X60Qtmp_8 = toJs_0_jsfc0lwq21((*sink_1).d_00.exitCode_0);
  set_0_jsfc0lwq21(g_0, (string_0_sysvq0asl){
    .bytes_0 = 1633640446u, .more_0 = (&strlit_0_I15127672453272209563_web5o9ahf1)}
  , X60Qtmp_8);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_8);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_7);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_6);
  eQdestroy_0_jsfc0lwq21(g_0);
  eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1(sink_1);
  nimStrDestroy(src_1);
  eQdestroy_0_jsfc0lwq21(X60Qtmp_5);}
void eQwasmovedQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_web5o9ahf1(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* dest_0){
  if (dest_0){
    NB8 X60Qx_2 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2){
      eQdestroyQ_SX4futX53inkX4fbj0natd5co251_0_natd5co251((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_web5o9ahf1(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* dest_0){
  if (dest_0){
    NB8 X60Qx_3 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_3){
      eQdestroyQ_SX54raceX4fbj0trakthy001_0_trakthy001((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void X60Qini_0_web5o9ahf1(void){
  if (X60QiniGuard_0_web5o9ahf1){
    return;}
  X60QiniGuard_0_web5o9ahf1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_prorcx25w1();
  X60Qini_0_natd5co251();
  X60Qini_0_trakthy001();
  X60Qini_0_chu5m1rja1();
  X60Qini_0_comaa5xpt1();
  X60Qini_0_vmtuaxp6();
  X60Qini_0_web91l7of();
  X60Qini_0_jsfc0lwq21();
  aowliRun_0_web5o9ahf1();}
NI32 main(NI32 X60Qargc_0_web5o9ahf1, char** X60Qargv_0_web5o9ahf1, char** X60Qenvp_0_web5o9ahf1){
  cmdCount = X60Qargc_0_web5o9ahf1;
  cmdLine = ((NC8**)X60Qargv_0_web5o9ahf1);
  nimEnviron = ((NC8**)X60Qenvp_0_web5o9ahf1);
  X60Qini_0_web5o9ahf1();
  nimFlushStdStreams();
  return 0;}
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
static inline openArray_0_Imqex5f1_comaa5xpt1 toOpenArray_0_Imravs1_comaa5xpt1(X60Qt_0_IAarraySX43ursor0nifb6mq6y1S0_comaa5xpt1* x_19){
  openArray_0_Imqex5f1_comaa5xpt1 result_120;
  openArray_0_Imqex5f1_comaa5xpt1 X60Qx_21;
  if (((NI32)(((NI32)(((NI32)((NI32)-1)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_21 = (openArray_0_Imqex5f1_comaa5xpt1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_21 = (openArray_0_Imqex5f1_comaa5xpt1){
      .a_0 = ((Cursor_0_nifb6mq6y1*)(&(*x_19))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)-1)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_120 = X60Qx_21;
  return result_120;}
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_ast8ri79k((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3){
  if ((!((*dest_3).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_ast8ri79k((&(*(*dest_3).owner_0).rc_0));
    if ((*(*dest_3).owner_0).rc_0 == 0){
      if ((!((*(*dest_3).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*dest_3).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*dest_3).owner_0)));}}
  else {
    if ((!((*dest_3).data_0 == NIM_NIL))){
      dealloc_1_sysvq0asl(((void*)(*dest_3).data_0));}}}
static inline JsValue_0_jsfc0lwq21 toJs_0_jsfc0lwq21(NI32 x_4){
  JsValue_0_jsfc0lwq21 result_4;
  eQdestroy_0_jsfc0lwq21(result_4);
  NI32 X60Qx_4 = _numToJs(x_4);
  result_4 = (JsValue_0_jsfc0lwq21){
    .h_0 = X60Qx_4}
  ;
  return result_4;}
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
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
