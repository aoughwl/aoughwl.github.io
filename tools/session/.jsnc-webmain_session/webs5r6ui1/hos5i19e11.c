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
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct seq_0_I50urnw_croph25r5 seq_0_I50urnw_croph25r5;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct PathGrant_0_iop7yt73v PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v ReadRecord_0_iop7yt73v;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_Iygo52q1_hos5i19e11{
  NI32 len_0;
  FILE** data_0;}
seq_0_Iygo52q1_hos5i19e11;
typedef struct seq_0_I9xd2d01_hos5i19e11{
  NI32 len_0;
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** data_0;}
seq_0_I9xd2d01_hos5i19e11;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251)(void);
typedef N_NIMCALL_PTR(Value_0_valzr1t4f,  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251)(NI64, string_0_sysvq0asl, seq_0_I50urnw_croph25r5, NB8*);
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
  seq_0_Ixdx2fh1_aow7lb5cq1 argv_0;
  seq_0_Iygo52q1_hos5i19e11 fds_0;
  seq_0_I9xd2d01_hos5i19e11 pipeFds_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 envKeys_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 envVals_0;
  NB8 envSeeded_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 failedReads_0;
  NI32 failedReadCount_0;
  NI64 hostContext_0;
  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251 hostCall_0;
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* policy_0;}
OutSink_Obj_0_natd5co251;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5{
  NI r_00;
  OutSink_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
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
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01{
  string_0_sysvq0asl a[2];}
X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01;
typedef NU8 ErrorCode_0_sysvq0asl;

#define Success_0_sysvq0asl ((NU8)0)
#define OverflowError_0_sysvq0asl ((NU8)1)
#define Failure_0_sysvq0asl ((NU8)2)
#define BugError_0_sysvq0asl ((NU8)3)
#define IndexError_0_sysvq0asl ((NU8)4)
#define RangeError_0_sysvq0asl ((NU8)5)
#define OverlapError_0_sysvq0asl ((NU8)6)
#define SyntaxError_0_sysvq0asl ((NU8)7)
#define OutOfMemError_0_sysvq0asl ((NU8)8)
#define DiskFullError_0_sysvq0asl ((NU8)9)
#define StackOverflow_0_sysvq0asl ((NU8)10)
#define IOError_0_sysvq0asl ((NU8)11)
#define ValueError_0_sysvq0asl ((NU8)12)
#define KeyError_0_sysvq0asl ((NU8)13)
#define EndOfStreamError_0_sysvq0asl ((NU8)14)
#define SkipError_0_sysvq0asl ((NU8)15)
#define FullError_0_sysvq0asl ((NU8)16)
#define EmptyError_0_sysvq0asl ((NU8)17)
#define BusyError_0_sysvq0asl ((NU8)18)
#define DeadResource_0_sysvq0asl ((NU8)19)
#define ResourceExhaustedError_0_sysvq0asl ((NU8)20)
#define DescriptorExhaustedError_0_sysvq0asl ((NU8)21)
#define PermissionDenied_0_sysvq0asl ((NU8)22)
#define RetryError_0_sysvq0asl ((NU8)23)
#define TimeoutError_0_sysvq0asl ((NU8)24)
#define InterruptedError_0_sysvq0asl ((NU8)25)
#define DeadlockError_0_sysvq0asl ((NU8)26)
#define LockedError_0_sysvq0asl ((NU8)27)
#define FormatMismatch_0_sysvq0asl ((NU8)28)
#define AlreadyConnected_0_sysvq0asl ((NU8)29)
#define AddressNotAvailable_0_sysvq0asl ((NU8)30)
#define AddressFamilyUnsupported_0_sysvq0asl ((NU8)31)
#define BadOperation_0_sysvq0asl ((NU8)32)
#define AbortedOperation_0_sysvq0asl ((NU8)33)
#define UnimplementedOperation_0_sysvq0asl ((NU8)34)
#define AlreadyInProgress_0_sysvq0asl ((NU8)35)
#define NameTooLong_0_sysvq0asl ((NU8)36)
#define NameExists_0_sysvq0asl ((NU8)37)
#define NameNotFound_0_sysvq0asl ((NU8)38)
#define ContentTooLong_0_sysvq0asl ((NU8)39)
#define BadDescriptor_0_sysvq0asl ((NU8)40)
#define BadExecutable_0_sysvq0asl ((NU8)41)
#define BadLink_0_sysvq0asl ((NU8)42)
#define BadProtocol_0_sysvq0asl ((NU8)43)
#define ProtocolError_0_sysvq0asl ((NU8)44)
#define ReadonlyProtection_0_sysvq0asl ((NU8)45)
#define SegFault_0_sysvq0asl ((NU8)46)
#define DiskCorruption_0_sysvq0asl ((NU8)47)
#define Disconnected_0_sysvq0asl ((NU8)48)
#define RefusedConnection_0_sysvq0asl ((NU8)49)
#define UnreachableHost_0_sysvq0asl ((NU8)50)
#define UnrecoverableState_0_sysvq0asl ((NU8)51)
#define AuthenticationRequired_0_sysvq0asl ((NU8)52)
#define RedirectError_0_sysvq0asl ((NU8)53)
#define Reserved1_0_sysvq0asl ((NU8)54)
#define Reserved2_0_sysvq0asl ((NU8)55)
#define Reserved3_0_sysvq0asl ((NU8)56)
#define Reserved4_0_sysvq0asl ((NU8)57)
#define Reserved5_0_sysvq0asl ((NU8)58)
#define Reserved6_0_sysvq0asl ((NU8)59)
#define Reserved7_0_sysvq0asl ((NU8)60)
#define Reserved8_0_sysvq0asl ((NU8)61)
#define Reserved9_0_sysvq0asl ((NU8)62)
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1{
  ErrorCode_0_sysvq0asl fld_0;
  NI64 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1;
typedef struct X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11{
  NC8 a[65536];}
X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1{
  ErrorCode_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01{
  string_0_sysvq0asl a[1];}
X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef NU8 FileMode_0_syn1lfpjv;

#define fmRead_0_syn1lfpjv ((NU8)0)
#define fmWrite_0_syn1lfpjv ((NU8)1)
#define fmReadWrite_0_syn1lfpjv ((NU8)2)
#define fmReadWriteExisting_0_syn1lfpjv ((NU8)3)
#define fmAppend_0_syn1lfpjv ((NU8)4)
typedef NU8 FileSeekPos_0_syn1lfpjv;

#define fspSet_0_syn1lfpjv ((NU8)0)
#define fspCur_0_syn1lfpjv ((NU8)1)
#define fspEnd_0_syn1lfpjv ((NU8)2)
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct seq_0_I50urnw_croph25r5{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_croph25r5;
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
      NU32 ekind_0;}
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
      X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* ov_0;}
    ;
    struct {
      X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* st_0;}
    ;
    struct {
      X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* env_0;
      NU32 fn_0;
      NI32 pidxRaw_0;
      NI32 resumeRaw_0;}
    ;
    struct {
      NB8 toErr_0;}
    ;
    struct {
      X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* coro_0;}
    ;}
  ;}
Value_0_valzr1t4f;
typedef struct seq_0_Iq7pam4_iop7yt73v{
  NI32 len_0;
  PathGrant_0_iop7yt73v* data_0;}
seq_0_Iq7pam4_iop7yt73v;
typedef struct seq_0_Iero8tq_iop7yt73v{
  NI32 len_0;
  ReadRecord_0_iop7yt73v* data_0;}
seq_0_Iero8tq_iop7yt73v;
typedef struct IoPolicy_Obj_0_iop7yt73v{
  NB8 on_0;
  NI32 granted_0;
  seq_0_Iq7pam4_iop7yt73v grants_0;
  NB8 sealed_0;
  string_0_sysvq0asl owner_0;
  NB8 auditReads_0;
  seq_0_Iero8tq_iop7yt73v reads_0;
  NI32 violations_0;
  string_0_sysvq0asl violNative_0;
  NI32 violNeeded_0;}
IoPolicy_Obj_0_iop7yt73v;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax{
  NI r_00;
  IoPolicy_Obj_0_iop7yt73v d_00;}
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct seq_0_Iw8xl5b1_arecyyj7v{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_arecyyj7v;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_arecyyj7v names_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;}
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
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
typedef struct PtrOv_Obj_0_valzr1t4f{
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0;
  NI32 base_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0;
  NI32 foff_0;
  NI16 elemBits_0;
  TCode_0_valzr1t4f ecode_0;
  NU32 etype_0;}
PtrOv_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v{
  NI r_00;
  PtrOv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IAarrayAuS64ZS4_intzsnzax{
  NU64 a[4];}
X60Qt_0_IAarrayAuS64ZS4_intzsnzax;
typedef struct SetBox_Obj_0_valzr1t4f{
  X60Qt_0_IAarrayAuS64ZS4_intzsnzax words_0;}
SetBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  SetBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct ClosureEnv_Obj_0_valzr1t4f{
  seq_0_In6doa_arecyyj7v vars_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;
  X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* coro_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;}
ClosureEnv_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  ClosureEnv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct PathGrant_0_iop7yt73v{
  string_0_sysvq0asl prefix_0;
  NI32 caps_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 parts_0;}
PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v{
  string_0_sysvq0asl path_0;
  NU64 hash_0;
  NI32 size_0;
  NB8 hashed_0;}
ReadRecord_0_iop7yt73v;
typedef NU8 RegionKind_0_valzr1t4f;

#define rkBytes_0_valzr1t4f ((NU8)0)
#define rkSeq_0_valzr1t4f ((NU8)1)
#define rkArr_0_valzr1t4f ((NU8)2)
#define rkStr_0_valzr1t4f ((NU8)3)
#define rkCell_0_valzr1t4f ((NU8)4)
#define rkObj_0_valzr1t4f ((NU8)5)
#define rkForeign_0_valzr1t4f ((NU8)6)
typedef struct seq_0_Incv1wn_arecyyj7v{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_arecyyj7v;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct FlatRegion_Obj_0_valzr1t4f{
  RegionKind_0_valzr1t4f kind_0;
  union {
    struct {
      seq_0_Incv1wn_arecyyj7v bytes_0;
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
      seq_0_Ift2sne_aow7lb5cq1 offs_0;}
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
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
static inline NI32 len_3_Ijmnbol_hos5i19e11(seq_0_Iygo52q1_hos5i19e11 s_8);
static inline void add_0_Ifwhkoy_hos5i19e11(seq_0_Iygo52q1_hos5i19e11* s_9, FILE* elem_4);
static inline FILE** getQ_7_Ilvng2h1_hos5i19e11(seq_0_Iygo52q1_hos5i19e11 s_11, NI32 i_13);
static inline void putQ_7_Inawu4x1_hos5i19e11(seq_0_Iygo52q1_hos5i19e11* s_12, NI32 i_14, FILE* elem_5);
static inline NI32 len_3_I2hf64u1_hos5i19e11(seq_0_I9xd2d01_hos5i19e11 s_13);
static inline X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** getQ_7_Ihikmzc_hos5i19e11(seq_0_I9xd2d01_hos5i19e11 s_14, NI32 i_15);
static inline void add_0_Inzrvyi_hos5i19e11(seq_0_I9xd2d01_hos5i19e11* s_15, X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* elem_6);
static inline void putQ_7_I6xhgv5_hos5i19e11(seq_0_I9xd2d01_hos5i19e11* s_17, NI32 i_16, X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* elem_7);
static inline X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 default_23_Isnz07p_hos5i19e11(void);
static inline void minusQeQ_0_Ipe1u69_hos5i19e11(NI32* x_5, NI32 y_1);
static inline NI32 capInBytes_0_Ifagzit_hos5i19e11(seq_0_Iygo52q1_hos5i19e11 s_18);
NB8 resize_0_Isbw7m8_hos5i19e11(seq_0_Iygo52q1_hos5i19e11* dest_2, NI32 addedElements_2);
static inline NI32 capInBytes_0_Is2driv_hos5i19e11(seq_0_I9xd2d01_hos5i19e11 s_19);
NB8 resize_0_Iq5i634_hos5i19e11(seq_0_I9xd2d01_hos5i19e11* dest_3, NI32 addedElements_3);
static inline NI32 memSizeInBytes_0_Ifkbdqp_hos5i19e11(NI32 size_5);
static inline NI32 memSizeInBytes_0_Ie4yvp31_hos5i19e11(NI32 size_6);
void eQwasmovedQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** dest_0);
X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* eQdupQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* src_0);
void eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* dest_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
extern NB8 journalReplaying_0_jou8favxh1(void);
extern string_0_sysvq0asl portPath_0_jou8favxh1(string_0_sysvq0asl p_1);
extern seq_0_Ixdx2fh1_aow7lb5cq1 jServe_0_jou8favxh1(string_0_sysvq0asl kind_1, string_0_sysvq0asl key_1);
extern LongString_0_sysvq0asl const strlit_0_I9592449470941440445_croph25r5;
extern string_0_sysvq0asl jField_0_jou8favxh1(seq_0_Ixdx2fh1_aow7lb5cq1 f_0, NI32 i_0);
extern NI32 jInt_0_jou8favxh1(string_0_sysvq0asl s_2);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
extern NB8 capsDeniedOn_1_iop7yt73v(NI32 need_1, string_0_sysvq0asl path_1);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern void recordViolation_1_iop7yt73v(string_0_sysvq0asl name_4, NI32 needed_3);
extern NB8 open_0_syn1lfpjv(FILE** f_22, string_0_sysvq0asl filename_1, FileMode_0_syn1lfpjv mode_2, NI32 bufSize_0);
extern NB8 journalRecording_0_jou8favxh1(void);
extern seq_0_Ixdx2fh1_aow7lb5cq1 atQ_0_Ibamkxv1_hos1fpv3m1(X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01 a_6);
extern void jRecord_0_jou8favxh1(string_0_sysvq0asl kind_0, string_0_sysvq0asl key_0, seq_0_Ixdx2fh1_aow7lb5cq1 fields_0);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern string_0_sysvq0asl jSlurp_0_jou8favxh1(string_0_sysvq0asl p_2);
extern void close_0_syn1lfpjv(FILE* f_16);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 getFilePos_0_syn1lfpjv(FILE* f_34);
extern ErrorCode_0_sysvq0asl setFilePos_0_syn1lfpjv(FILE* f_35, NI64 pos_0, FileSeekPos_0_syn1lfpjv relativeTo_0);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
extern NI32 readBuffer_0_syn1lfpjv(FILE* f_18, void* buffer_1, NI32 size_3);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 getCurrentDir_0_ospaexnw61(void);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 absolutePath_0_ospaexnw61(string_0_sysvq0asl path_15, string_0_sysvq0asl root_0);
extern string_0_sysvq0asl normalizedPath_0_ospaexnw61(string_0_sysvq0asl path_19);
extern seq_0_Ixdx2fh1_aow7lb5cq1 atQ_0_I508dwj_hos1fpv3m1(X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01 a_7);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void dealloc_1_sysvq0asl(void* p_20);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void eQdestroyQ_SX50ipeX42ufX4fbj0natd5co251_0_natd5co251(PipeBuf_Obj_0_natd5co251 dest_0);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_natd5co251(void);
extern void X60Qini_0_iop7yt73v(void);
extern void X60Qini_0_jou8favxh1(void);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I112441122620953666_hos5i19e11 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "open(2) on \'"}
;
LongString_0_sysvq0asl const strlit_0_I12671210886245720931_hos5i19e11 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "expandpath"}
;
static NI32 const OQ_WRONLY_0 = ((NI32)1);
static NI32 const OQ_RDWR_0 = ((NI32)2);
static NI32 const OQ_CREAT_0 = ((NI32)64);
static NI32 const OQ_TRUNC_0 = ((NI32)512);
static NI32 const OQ_APPEND_0 = ((NI32)1024);
NB8 X60QiniGuard_0_hos5i19e11;
FileMode_0_syn1lfpjv modeFromPosixFlags_0_hos5i19e11(NI32 flags_0){
  FileMode_0_syn1lfpjv result_0;
  NI32 acc_0 = ((NI32)(flags_0 & 3));
  if ((!(((NI32)(flags_0 & ((NI32)1024))) == 0))){
    result_0 = 4;}
  else {
    if (acc_0 == ((NI32)2)){
      NB8 X60Qx_10;
      if ((!(((NI32)(flags_0 & ((NI32)64))) == 0))){
        X60Qx_10 = NIM_TRUE;}
      else {
        X60Qx_10 = (!(((NI32)(flags_0 & ((NI32)512))) == 0));}
      if (X60Qx_10){
        result_0 = 2;}
      else {
        result_0 = 3;}}
    else {
      if (acc_0 == ((NI32)1)){
        result_0 = 1;}
      else {
        result_0 = 0;}}}
  return result_0;}
FileMode_0_syn1lfpjv modeFromCString_0_hos5i19e11(string_0_sysvq0asl m_0){
  FileMode_0_syn1lfpjv result_1;
  NI32 X60Qx_11 = len_4_sysvq0asl(m_0);
  if (X60Qx_11 == 0){
    return 0;}
  NB8 X60Qx_12;
  NB8 X60Qx_13;
  NI32 X60Qx_14 = len_4_sysvq0asl(m_0);
  if (2 <= X60Qx_14){
    NC8 X60Qx_15 = getQ_9_sysvq0asl(m_0, 1);
    X60Qx_13 = (X60Qx_15 == (NC8)'+');}
  else {
    X60Qx_13 = NIM_FALSE;}
  if (X60Qx_13){
    X60Qx_12 = NIM_TRUE;}
  else {
    NB8 X60Qx_16;
    NI32 X60Qx_17 = len_4_sysvq0asl(m_0);
    if (3 <= X60Qx_17){
      NC8 X60Qx_18 = getQ_9_sysvq0asl(m_0, 2);
      X60Qx_16 = (X60Qx_18 == (NC8)'+');}
    else {
      X60Qx_16 = NIM_FALSE;}
    X60Qx_12 = X60Qx_16;}
  NB8 plus_0 = X60Qx_12;
  NC8 X60Qx_19 = getQ_9_sysvq0asl(m_0, 0);
  switch (X60Qx_19){
    case (NC8)'r':
    {
      FileMode_0_syn1lfpjv X60Qx_0;
      if (plus_0){
        X60Qx_0 = 3;}
      else {
        X60Qx_0 = 0;}
      result_1 = X60Qx_0;}
    break;
    case (NC8)'w':
    {
      FileMode_0_syn1lfpjv X60Qx_1;
      if (plus_0){
        X60Qx_1 = 2;}
      else {
        X60Qx_1 = 1;}
      result_1 = X60Qx_1;}
    break;
    case (NC8)'a':
    {
      result_1 = 4;}
    break;
    default:
    {
      result_1 = 0;}
    break;}
  return result_1;}
NI32 registerFd_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_0, FILE* f_0){
  NI32 result_2;
  {
    while (NIM_TRUE){
      NI32 X60Qx_20 = len_3_Ijmnbol_hos5i19e11((*sink_0).d_00.fds_0);
      if (X60Qx_20 < 3){
        add_0_Ifwhkoy_hos5i19e11((&(*sink_0).d_00.fds_0), NIM_NIL);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 i_0 = 3;
  {
    while (NIM_TRUE){
      NI32 X60Qx_21 = len_3_Ijmnbol_hos5i19e11((*sink_0).d_00.fds_0);
      if (i_0 < X60Qx_21){
        FILE** X60Qx_22 = getQ_7_Ilvng2h1_hos5i19e11((*sink_0).d_00.fds_0, i_0);
        if ((*X60Qx_22) == NIM_NIL){
          putQ_7_Inawu4x1_hos5i19e11((&(*sink_0).d_00.fds_0), i_0, f_0);
          return i_0;}
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  add_0_Ifwhkoy_hos5i19e11((&(*sink_0).d_00.fds_0), f_0);
  NI32 X60Qx_23 = len_3_Ijmnbol_hos5i19e11((*sink_0).d_00.fds_0);
  result_2 = ((NI32)(X60Qx_23 - 1));
  return result_2;}
X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pipeAt_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_1, NI32 fd_0){
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* result_3;
  eQwasmovedQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11((&result_3));
  NB8 X60Qx_24;
  if (3 <= fd_0){
    NI32 X60Qx_25 = len_3_I2hf64u1_hos5i19e11((*sink_1).d_00.pipeFds_0);
    X60Qx_24 = (fd_0 < X60Qx_25);}
  else {
    X60Qx_24 = NIM_FALSE;}
  if (X60Qx_24){
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** X60Qx_26 = getQ_7_Ihikmzc_hos5i19e11((*sink_1).d_00.pipeFds_0, fd_0);
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* X60Qx_27 = eQdupQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11((*X60Qx_26));
    result_3 = X60Qx_27;
    return result_3;}
  return NIM_NIL;
  return result_3;}
NI32 registerPipeEnd_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_2, X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_0){
  NI32 result_4;
  {
    while (NIM_TRUE){
      NI32 X60Qx_28 = len_3_Ijmnbol_hos5i19e11((*sink_2).d_00.fds_0);
      if (X60Qx_28 < 3){
        add_0_Ifwhkoy_hos5i19e11((&(*sink_2).d_00.fds_0), NIM_NIL);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  {
    while (NIM_TRUE){
      NI32 X60Qx_29 = len_3_I2hf64u1_hos5i19e11((*sink_2).d_00.pipeFds_0);
      NI32 X60Qx_30 = len_3_Ijmnbol_hos5i19e11((*sink_2).d_00.fds_0);
      if (X60Qx_29 < X60Qx_30){
        add_0_Inzrvyi_hos5i19e11((&(*sink_2).d_00.pipeFds_0), ((X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11*)NIM_NIL));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  NI32 i_4 = 3;
  {
    while (NIM_TRUE){
      NI32 X60Qx_31 = len_3_Ijmnbol_hos5i19e11((*sink_2).d_00.fds_0);
      if (i_4 < X60Qx_31){
        NB8 X60Qx_32;
        FILE** X60Qx_33 = getQ_7_Ilvng2h1_hos5i19e11((*sink_2).d_00.fds_0, i_4);
        if ((*X60Qx_33) == NIM_NIL){
          X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** X60Qx_34 = getQ_7_Ihikmzc_hos5i19e11((*sink_2).d_00.pipeFds_0, i_4);
          X60Qx_32 = ((*X60Qx_34) == NIM_NIL);}
        else {
          X60Qx_32 = NIM_FALSE;}
        if (X60Qx_32){
          X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* X60Qx_35 = eQdupQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_0);
          putQ_7_I6xhgv5_hos5i19e11((&(*sink_2).d_00.pipeFds_0), i_4, X60Qx_35);
          return i_4;}
        inc_1_I6wjjge_aow2h993l1((&i_4));}
      else {
        break;}}}
  whileStmtLabel_2: ;
  add_0_Ifwhkoy_hos5i19e11((&(*sink_2).d_00.fds_0), NIM_NIL);
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* X60Qx_36 = eQdupQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_0);
  add_0_Inzrvyi_hos5i19e11((&(*sink_2).d_00.pipeFds_0), X60Qx_36);
  NI32 X60Qx_37 = len_3_Ijmnbol_hos5i19e11((*sink_2).d_00.fds_0);
  result_4 = ((NI32)(X60Qx_37 - 1));
  return result_4;}
NB8 hostPipe_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_3, NI32* rfd_0, NI32* wfd_0){
  NB8 result_5;
  void* X60Qx_38 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11));
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* X60Qtmp_0 = ((X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11*)X60Qx_38);
  (*X60Qtmp_0) = (X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11){
    .r_00 = 0, .d_00 = (PipeBuf_Obj_0_natd5co251){
      .data_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .rpos_0 = 0, .writeFd_0 = 0, .writeClosed_0 = NIM_FALSE}}
  ;
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_1 = X60Qtmp_0;
  NI32 X60Qx_39 = registerPipeEnd_0_hos5i19e11(sink_3, pb_1);
  (*rfd_0) = X60Qx_39;
  NI32 X60Qx_40 = registerPipeEnd_0_hos5i19e11(sink_3, pb_1);
  (*wfd_0) = X60Qx_40;
  (*pb_1).d_00.writeFd_0 = (*wfd_0);
  result_5 = NIM_TRUE;
  eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_1);
  return result_5;
  eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_1);
  return result_5;}
NI32 hostOpen_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_4, string_0_sysvq0asl path_0, FileMode_0_syn1lfpjv mode_0){
  NI32 result_6;
  NB8 X60Qx_41 = journalReplaying_0_jou8favxh1();
  if (X60Qx_41){
    string_0_sysvq0asl X60Qtmp_1 = portPath_0_jou8favxh1(path_0);
    seq_0_Ixdx2fh1_aow7lb5cq1 a_0 = jServe_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
    , X60Qtmp_1);
    string_0_sysvq0asl X60Qtmp_2 = jField_0_jou8favxh1(a_0, 0);
    NI32 X60Qx_42 = jInt_0_jou8favxh1(X60Qtmp_2);
    if (X60Qx_42 < 0){
      nimStrDestroy(X60Qtmp_2);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(a_0);
      nimStrDestroy(X60Qtmp_1);
      return -1;}
    void* X60Qx_43 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11));
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* X60Qtmp_3 = ((X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11*)X60Qx_43);
    string_0_sysvq0asl X60Qx_44 = jField_0_jou8favxh1(a_0, 1);
    (*X60Qtmp_3) = (X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11){
      .r_00 = 0, .d_00 = (PipeBuf_Obj_0_natd5co251){
        .data_0 = X60Qx_44, .rpos_0 = 0, .writeFd_0 = -1, .writeClosed_0 = NIM_TRUE}}
    ;
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_2 = X60Qtmp_3;
    NI32 X60Qx_45 = registerPipeEnd_0_hos5i19e11(sink_4, pb_2);
    result_6 = X60Qx_45;
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_2);
    nimStrDestroy(X60Qtmp_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(a_0);
    nimStrDestroy(X60Qtmp_1);
    return result_6;
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_2);
    nimStrDestroy(X60Qtmp_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(a_0);
    nimStrDestroy(X60Qtmp_1);}
  NB8 X60Qx_46;
  NB8 X60Qx_47 = capsDeniedOn_1_iop7yt73v(((NI32)1), path_0);
  if (X60Qx_47){
    NB8 X60Qx_48 = capsDeniedOn_1_iop7yt73v(((NI32)2), path_0);
    X60Qx_46 = X60Qx_48;}
  else {
    X60Qx_46 = NIM_FALSE;}
  if (X60Qx_46){
    NI32 X60Qx_49 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I112441122620953666_hos5i19e11)}
    );
    NI32 X60Qx_50 = len_4_sysvq0asl(path_0);
    NI32 X60Qx_51 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_0 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_49 + X60Qx_50)) + X60Qx_51)));
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I112441122620953666_hos5i19e11)}
    );
    add_2_sysvq0asl((&X60Qdesugar_0), path_0);
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 9985u, .more_0 = NIM_NIL}
    );
    recordViolation_1_iop7yt73v(X60Qdesugar_0, ((NI32)(((NI32)1) | ((NI32)2))));
    nimStrDestroy(X60Qdesugar_0);
    return -1;
    nimStrDestroy(X60Qdesugar_0);}
  FILE* f_1;
  NB8 X60Qx_52 = open_0_syn1lfpjv((&f_1), path_0, mode_0, -1);
  if ((!X60Qx_52)){
    NB8 X60Qx_53 = journalRecording_0_jou8favxh1();
    if (X60Qx_53){
      string_0_sysvq0asl X60Qtmp_4 = portPath_0_jou8favxh1(path_0);
      seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_5 = atQ_0_Ibamkxv1_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
        .a = {
          (string_0_sysvq0asl){
            .bytes_0 = 3222786u, .more_0 = NIM_NIL}
          , (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}}}
      );
      jRecord_0_jou8favxh1((string_0_sysvq0asl){
        .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
      , X60Qtmp_4, X60Qtmp_5);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_5);
      nimStrDestroy(X60Qtmp_4);}
    return -1;}
  NI32 X60Qx_54 = registerFd_0_hos5i19e11(sink_4, f_1);
  result_6 = X60Qx_54;
  NB8 X60Qx_55 = journalRecording_0_jou8favxh1();
  if (X60Qx_55){
    string_0_sysvq0asl X60Qtmp_6 = portPath_0_jou8favxh1(path_0);
    string_0_sysvq0asl X60Qtmp_8 = dollarQ_2_sysvq0asl(result_6);
    string_0_sysvq0asl X60Qtmp_9 = jSlurp_0_jou8favxh1(path_0);
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_7 = atQ_0_Ibamkxv1_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS2_emi78vuj01){
      .a = {
        X60Qtmp_8, X60Qtmp_9}}
    );
    jRecord_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
    , X60Qtmp_6, X60Qtmp_7);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_7);
    nimStrDestroy(X60Qtmp_9);
    nimStrDestroy(X60Qtmp_8);
    nimStrDestroy(X60Qtmp_6);}
  return result_6;}
NI32 hostOpenPosix_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_5, string_0_sysvq0asl path_1, NI32 flags_1){
  NI32 result_7;
  FileMode_0_syn1lfpjv X60Qx_56 = modeFromPosixFlags_0_hos5i19e11(flags_1);
  NI32 X60Qx_57 = hostOpen_0_hos5i19e11(sink_5, path_1, X60Qx_56);
  result_7 = X60Qx_57;
  return result_7;}
NI32 hostOpenC_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_6, string_0_sysvq0asl path_2, string_0_sysvq0asl modeStr_0){
  NI32 result_8;
  FileMode_0_syn1lfpjv X60Qx_58 = modeFromCString_0_hos5i19e11(modeStr_0);
  NI32 X60Qx_59 = hostOpen_0_hos5i19e11(sink_6, path_2, X60Qx_58);
  result_8 = X60Qx_59;
  return result_8;}
NI32 hostClose_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_7, NI32 fd_1){
  NI32 result_9;
  NB8 X60Qx_60;
  if (0 <= fd_1){
    X60Qx_60 = (fd_1 <= 2);}
  else {
    X60Qx_60 = NIM_FALSE;}
  if (X60Qx_60){
    return 0;}
  {
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_3 = pipeAt_0_hos5i19e11(sink_7, fd_1);
    if ((!(pb_3 == NIM_NIL))){
      if (fd_1 == (*pb_3).d_00.writeFd_0){
        (*pb_3).d_00.writeClosed_0 = NIM_TRUE;}
      putQ_7_I6xhgv5_hos5i19e11((&(*sink_7).d_00.pipeFds_0), fd_1, ((X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11*)NIM_NIL));
      eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_3);
      return 0;}
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_3);}
  X60Qlab_0: ;
  NB8 X60Qx_61;
  if (3 <= fd_1){
    NI32 X60Qx_62 = len_3_Ijmnbol_hos5i19e11((*sink_7).d_00.fds_0);
    X60Qx_61 = (fd_1 < X60Qx_62);}
  else {
    X60Qx_61 = NIM_FALSE;}
  if (X60Qx_61){
    FILE** X60Qx_63 = getQ_7_Ilvng2h1_hos5i19e11((*sink_7).d_00.fds_0, fd_1);
    FILE* f_2 = (*X60Qx_63);
    if ((!(f_2 == NIM_NIL))){
      close_0_syn1lfpjv(f_2);
      putQ_7_Inawu4x1_hos5i19e11((&(*sink_7).d_00.fds_0), fd_1, NIM_NIL);
      return 0;}}
  result_9 = -1;
  return result_9;}
NB8 isHostFd_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_8, NI32 fd_2){
  NB8 result_10;
  NB8 X60Qx_64;
  NB8 X60Qx_65;
  if (3 <= fd_2){
    NI32 X60Qx_66 = len_3_I2hf64u1_hos5i19e11((*sink_8).d_00.pipeFds_0);
    X60Qx_65 = (fd_2 < X60Qx_66);}
  else {
    X60Qx_65 = NIM_FALSE;}
  if (X60Qx_65){
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** X60Qx_67 = getQ_7_Ihikmzc_hos5i19e11((*sink_8).d_00.pipeFds_0, fd_2);
    X60Qx_64 = (!((*X60Qx_67) == NIM_NIL));}
  else {
    X60Qx_64 = NIM_FALSE;}
  if (X60Qx_64){
    return NIM_TRUE;}
  NB8 X60Qx_68;
  NB8 X60Qx_69;
  if (3 <= fd_2){
    NI32 X60Qx_70 = len_3_Ijmnbol_hos5i19e11((*sink_8).d_00.fds_0);
    X60Qx_69 = (fd_2 < X60Qx_70);}
  else {
    X60Qx_69 = NIM_FALSE;}
  if (X60Qx_69){
    FILE** X60Qx_71 = getQ_7_Ilvng2h1_hos5i19e11((*sink_8).d_00.fds_0, fd_2);
    X60Qx_68 = (!((*X60Qx_71) == NIM_NIL));}
  else {
    X60Qx_68 = NIM_FALSE;}
  result_10 = X60Qx_68;
  return result_10;}
string_0_sysvq0asl hostPread_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_9, NI32 fd_3, NI32 off_0, NI32 n_0){
  string_0_sysvq0asl result_11;
  nimStrWasMoved((&result_11));
  nimStrDestroy(result_11);
  result_11 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_72;
  if (fd_3 < 3){
    X60Qx_72 = NIM_TRUE;}
  else {
    X60Qx_72 = ((*sink_9).d_00.fds_0.len_0 <= fd_3);}
  if (X60Qx_72){
    return result_11;}
  {
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_4 = pipeAt_0_hos5i19e11(sink_9, fd_3);
    if ((!(pb_4 == NIM_NIL))){
      NI32 i_6 = off_0;
      NI32 k_0 = 0;
      {
        while (NIM_TRUE){
          NB8 X60Qx_73;
          if (k_0 < n_0){
            NI32 X60Qx_74 = len_4_sysvq0asl((*pb_4).d_00.data_0);
            X60Qx_73 = (i_6 < X60Qx_74);}
          else {
            X60Qx_73 = NIM_FALSE;}
          if (X60Qx_73){
            NC8 X60Qx_75 = getQ_9_sysvq0asl((*pb_4).d_00.data_0, i_6);
            add_1_sysvq0asl((&result_11), X60Qx_75);
            inc_1_I6wjjge_aow2h993l1((&i_6));
            inc_1_I6wjjge_aow2h993l1((&k_0));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_4);
      return result_11;}
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_4);}
  X60Qlab_0: ;
  FILE** X60Qx_76 = getQ_7_Ilvng2h1_hos5i19e11((*sink_9).d_00.fds_0, fd_3);
  FILE* f_3 = (*X60Qx_76);
  if (f_3 == NIM_NIL){
    return result_11;}
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 pos_0 = getFilePos_0_syn1lfpjv(f_3);
  if (pos_0.fld_0){
    goto X60Qexlab_0;}
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = setFilePos_0_syn1lfpjv(f_3, ((NI64)off_0), 0);
  if (X60QcanRaise_0){
    goto X60Qexlab_0;}
  X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 buf_0 = default_23_Isnz07p_hos5i19e11();
  NI32 left_0 = n_0;
  {
    while (0 < left_0){
      NI32 X60Qx_2;
      if (left_0 < ((NI32)(((NI32)(((NI32)((NI32)65535)) - ((NI32)((NI32)0)))) + 1))){
        X60Qx_2 = left_0;}
      else {
        X60Qx_2 = ((NI32)(((NI32)(((NI32)((NI32)65535)) - ((NI32)((NI32)0)))) + 1));}
      NI32 want_0 = X60Qx_2;
      NI32 X60Qx_77 = nimIcheckB(0, 65535);
      NI32 got_0 = readBuffer_0_syn1lfpjv(f_3, ((void*)(&buf_0.a[X60Qx_77])), want_0);
      if (got_0 <= 0){
        goto whileStmtLabel_2;}
      NI32 i_7 = 0;
      {
        while (i_7 < got_0){
          NI32 X60Qx_78 = nimIcheckB(i_7, 65535);
          add_1_sysvq0asl((&result_11), buf_0.a[X60Qx_78]);
          inc_1_I6wjjge_aow2h993l1((&i_7));}}
      whileStmtLabel_3: ;
      left_0 = ((NI32)(left_0 - got_0));}}
  whileStmtLabel_2: ;
  ErrorCode_0_sysvq0asl X60QcanRaise_1 = setFilePos_0_syn1lfpjv(f_3, pos_0.fld_1, 0);
  if (X60QcanRaise_1){
    goto X60Qexlab_0;}
  if (NIM_FALSE){
    X60Qexlab_0: ;
    nimStrDestroy(result_11);
    result_11 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  return result_11;}
FILE* hostFileOfFd_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_10, NI32 fd_4){
  FILE* result_12;
  NB8 X60Qx_79;
  if (3 <= fd_4){
    NI32 X60Qx_80 = len_3_Ijmnbol_hos5i19e11((*sink_10).d_00.fds_0);
    X60Qx_79 = (fd_4 < X60Qx_80);}
  else {
    X60Qx_79 = NIM_FALSE;}
  if (X60Qx_79){
    FILE** X60Qx_81 = getQ_7_Ilvng2h1_hos5i19e11((*sink_10).d_00.fds_0, fd_4);
    result_12 = (*X60Qx_81);
    return result_12;}
  result_12 = NIM_NIL;
  return result_12;}
NI32 hostWrite_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_11, NI32 fd_5, string_0_sysvq0asl data_0, NI32 n_1){
  NI32 result_13;
  NI32 X60Qx_3;
  NI32 X60Qx_82 = len_4_sysvq0asl(data_0);
  if (n_1 < X60Qx_82){
    X60Qx_3 = n_1;}
  else {
    NI32 X60Qx_83 = len_4_sysvq0asl(data_0);
    X60Qx_3 = X60Qx_83;}
  NI32 cnt_0 = X60Qx_3;
  {
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_5 = pipeAt_0_hos5i19e11(sink_11, fd_5);
    if ((!(pb_5 == NIM_NIL))){
      NI32 i_8 = 0;
      {
        while (i_8 < cnt_0){
          NC8 X60Qx_84 = getQ_9_sysvq0asl(data_0, i_8);
          add_1_sysvq0asl((&(*pb_5).d_00.data_0), X60Qx_84);
          inc_1_I6wjjge_aow2h993l1((&i_8));}}
      whileStmtLabel_1: ;
      eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_5);
      return cnt_0;}
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_5);}
  X60Qlab_0: ;
  if (fd_5 == 1){
    if ((!(*sink_11).d_00.didQQuit_0)){
      NI32 i_9 = 0;
      {
        while (i_9 < cnt_0){
          NC8 X60Qx_85 = getQ_9_sysvq0asl(data_0, i_9);
          add_1_sysvq0asl((&(*sink_11).d_00.outBuf_0), X60Qx_85);
          inc_1_I6wjjge_aow2h993l1((&i_9));}}
      whileStmtLabel_2: ;}
    return cnt_0;}
  if (fd_5 == 2){
    NI32 i_10 = 0;
    {
      while (i_10 < cnt_0){
        NC8 X60Qx_86 = getQ_9_sysvq0asl(data_0, i_10);
        add_1_sysvq0asl((&(*sink_11).d_00.errBuf_0), X60Qx_86);
        inc_1_I6wjjge_aow2h993l1((&i_10));}}
    whileStmtLabel_3: ;
    return cnt_0;}
  if (fd_5 == 0){
    return -1;}
  NB8 X60Qx_87;
  if (3 <= fd_5){
    NI32 X60Qx_88 = len_3_Ijmnbol_hos5i19e11((*sink_11).d_00.fds_0);
    X60Qx_87 = (fd_5 < X60Qx_88);}
  else {
    X60Qx_87 = NIM_FALSE;}
  if (X60Qx_87){
    FILE** X60Qx_89 = getQ_7_Ilvng2h1_hos5i19e11((*sink_11).d_00.fds_0, fd_5);
    FILE* f_4 = (*X60Qx_89);
    if ((!(f_4 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_4;
      nimStrWasMoved((&X60Qx_4));
      NI32 X60Qx_90 = len_4_sysvq0asl(data_0);
      if (cnt_0 < X60Qx_90){
        nimStrDestroy(X60Qx_4);
        string_0_sysvq0asl X60Qx_91 = substr_0_sysvq0asl(data_0, 0, ((NI32)(cnt_0 - 1)));
        X60Qx_4 = X60Qx_91;}
      else {
        nimStrDestroy(X60Qx_4);
        string_0_sysvq0asl X60Qx_92 = nimStrDup(data_0);
        X60Qx_4 = X60Qx_92;}
      string_0_sysvq0asl chunk_0 = X60Qx_4;
      nimStrWasMoved((&X60Qx_4));
      write_0_syn1lfpjv(f_4, chunk_0);
      nimStrDestroy(chunk_0);
      nimStrDestroy(X60Qx_4);
      return cnt_0;
      nimStrDestroy(chunk_0);
      nimStrDestroy(X60Qx_4);}}
  result_13 = -1;
  return result_13;}
string_0_sysvq0asl hostRead_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_12, NI32 fd_6, NI32 n_2){
  string_0_sysvq0asl result_14;
  nimStrWasMoved((&result_14));
  nimStrDestroy(result_14);
  result_14 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (n_2 <= 0){
    return result_14;}
  {
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_6 = pipeAt_0_hos5i19e11(sink_12, fd_6);
    if ((!(pb_6 == NIM_NIL))){
      NI32 k_1 = 0;
      {
        while (NIM_TRUE){
          NB8 X60Qx_93;
          if (k_1 < n_2){
            NI32 X60Qx_94 = len_4_sysvq0asl((*pb_6).d_00.data_0);
            X60Qx_93 = ((*pb_6).d_00.rpos_0 < X60Qx_94);}
          else {
            X60Qx_93 = NIM_FALSE;}
          if (X60Qx_93){
            NC8 X60Qx_95 = getQ_9_sysvq0asl((*pb_6).d_00.data_0, (*pb_6).d_00.rpos_0);
            add_1_sysvq0asl((&result_14), X60Qx_95);
            inc_1_I6wjjge_aow2h993l1((&(*pb_6).d_00.rpos_0));
            inc_1_I6wjjge_aow2h993l1((&k_1));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_6);
      return result_14;}
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_6);}
  X60Qlab_0: ;
  if (fd_6 == 0){
    NI32 k_2 = 0;
    {
      while (NIM_TRUE){
        NB8 X60Qx_96;
        if (k_2 < n_2){
          NI32 X60Qx_97 = len_4_sysvq0asl((*sink_12).d_00.inBuf_0);
          X60Qx_96 = ((*sink_12).d_00.inPos_0 < X60Qx_97);}
        else {
          X60Qx_96 = NIM_FALSE;}
        if (X60Qx_96){
          NC8 X60Qx_98 = getQ_9_sysvq0asl((*sink_12).d_00.inBuf_0, (*sink_12).d_00.inPos_0);
          add_1_sysvq0asl((&result_14), X60Qx_98);
          inc_1_I6wjjge_aow2h993l1((&(*sink_12).d_00.inPos_0));
          inc_1_I6wjjge_aow2h993l1((&k_2));}
        else {
          break;}}}
    whileStmtLabel_2: ;
    return result_14;}
  NB8 X60Qx_99;
  if (3 <= fd_6){
    NI32 X60Qx_100 = len_3_Ijmnbol_hos5i19e11((*sink_12).d_00.fds_0);
    X60Qx_99 = (fd_6 < X60Qx_100);}
  else {
    X60Qx_99 = NIM_FALSE;}
  if (X60Qx_99){
    FILE** X60Qx_101 = getQ_7_Ilvng2h1_hos5i19e11((*sink_12).d_00.fds_0, fd_6);
    FILE* f_5 = (*X60Qx_101);
    if (f_5 == NIM_NIL){
      return result_14;}
    X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 buf_1 = default_23_Isnz07p_hos5i19e11();
    NI32 remaining_0 = n_2;
    {
      while (0 < remaining_0){
        NI32 X60Qx_5;
        if (remaining_0 < ((NI32)(((NI32)(((NI32)((NI32)65535)) - ((NI32)((NI32)0)))) + 1))){
          X60Qx_5 = remaining_0;}
        else {
          X60Qx_5 = ((NI32)(((NI32)(((NI32)((NI32)65535)) - ((NI32)((NI32)0)))) + 1));}
        NI32 take_0 = X60Qx_5;
        NI32 X60Qx_102 = nimIcheckB(0, 65535);
        NI32 got_1 = readBuffer_0_syn1lfpjv(f_5, ((void*)(&buf_1.a[X60Qx_102])), take_0);
        if (got_1 <= 0){
          goto whileStmtLabel_3;}
        NI32 i_11 = 0;
        {
          while (i_11 < got_1){
            NI32 X60Qx_103 = nimIcheckB(i_11, 65535);
            add_1_sysvq0asl((&result_14), buf_1.a[X60Qx_103]);
            inc_1_I6wjjge_aow2h993l1((&i_11));}}
        whileStmtLabel_4: ;
        minusQeQ_0_Ipe1u69_hos5i19e11((&remaining_0), got_1);
        if (got_1 < take_0){
          goto whileStmtLabel_3;}}}
    whileStmtLabel_3: ;}
  return result_14;}
string_0_sysvq0asl hostReadAll_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_13, NI32 fd_7){
  string_0_sysvq0asl result_15;
  nimStrWasMoved((&result_15));
  nimStrDestroy(result_15);
  result_15 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_7 = pipeAt_0_hos5i19e11(sink_13, fd_7);
    if ((!(pb_7 == NIM_NIL))){
      NI32 X60Qx_104 = len_4_sysvq0asl((*pb_7).d_00.data_0);
      if ((*pb_7).d_00.rpos_0 < X60Qx_104){
        nimStrDestroy(result_15);
        NI32 X60Qx_105 = len_4_sysvq0asl((*pb_7).d_00.data_0);
        string_0_sysvq0asl X60Qx_106 = substr_0_sysvq0asl((*pb_7).d_00.data_0, (*pb_7).d_00.rpos_0, ((NI32)(X60Qx_105 - 1)));
        result_15 = X60Qx_106;
        NI32 X60Qx_107 = len_4_sysvq0asl((*pb_7).d_00.data_0);
        (*pb_7).d_00.rpos_0 = X60Qx_107;}
      eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_7);
      return result_15;}
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_7);}
  X60Qlab_0: ;
  if (fd_7 == 0){
    NI32 X60Qx_108 = len_4_sysvq0asl((*sink_13).d_00.inBuf_0);
    if ((*sink_13).d_00.inPos_0 < X60Qx_108){
      nimStrDestroy(result_15);
      NI32 X60Qx_109 = len_4_sysvq0asl((*sink_13).d_00.inBuf_0);
      string_0_sysvq0asl X60Qx_110 = substr_0_sysvq0asl((*sink_13).d_00.inBuf_0, (*sink_13).d_00.inPos_0, ((NI32)(X60Qx_109 - 1)));
      result_15 = X60Qx_110;
      NI32 X60Qx_111 = len_4_sysvq0asl((*sink_13).d_00.inBuf_0);
      (*sink_13).d_00.inPos_0 = X60Qx_111;}
    return result_15;}
  NB8 X60Qx_112;
  if (3 <= fd_7){
    NI32 X60Qx_113 = len_3_Ijmnbol_hos5i19e11((*sink_13).d_00.fds_0);
    X60Qx_112 = (fd_7 < X60Qx_113);}
  else {
    X60Qx_112 = NIM_FALSE;}
  if (X60Qx_112){
    FILE** X60Qx_114 = getQ_7_Ilvng2h1_hos5i19e11((*sink_13).d_00.fds_0, fd_7);
    FILE* f_6 = (*X60Qx_114);
    if (f_6 == NIM_NIL){
      return result_15;}
    X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 buf_2 = default_23_Isnz07p_hos5i19e11();
    {
      while (NIM_TRUE){
        NI32 X60Qx_115 = nimIcheckB(0, 65535);
        NI32 got_2 = readBuffer_0_syn1lfpjv(f_6, ((void*)(&buf_2.a[X60Qx_115])), ((NI32)(((NI32)(((NI32)((NI32)65535)) - ((NI32)((NI32)0)))) + 1)));
        if (got_2 <= 0){
          goto whileStmtLabel_1;}
        NI32 i_12 = 0;
        {
          while (i_12 < got_2){
            NI32 X60Qx_116 = nimIcheckB(i_12, 65535);
            add_1_sysvq0asl((&result_15), buf_2.a[X60Qx_116]);
            inc_1_I6wjjge_aow2h993l1((&i_12));}}
        whileStmtLabel_2: ;
        if (got_2 < ((NI32)(((NI32)(((NI32)((NI32)65535)) - ((NI32)((NI32)0)))) + 1))){
          goto whileStmtLabel_1;}}}
    whileStmtLabel_1: ;}
  return result_15;}
NI64 hostLseek_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_14, NI32 fd_8, NI64 offset_0, NI32 whence_0){
  NI64 result_16;
  NB8 X60Qx_117;
  if (fd_8 < 3){
    X60Qx_117 = NIM_TRUE;}
  else {
    X60Qx_117 = ((*sink_14).d_00.fds_0.len_0 <= fd_8);}
  if (X60Qx_117){
    return ((NI64)-1);}
  {
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_8 = pipeAt_0_hos5i19e11(sink_14, fd_8);
    if ((!(pb_8 == NIM_NIL))){
      NI32 np_0 = 0;
      switch (whence_0){
        case 0:
        {
          np_0 = ((NI32)offset_0);}
        break;
        case 1:
        {
          np_0 = ((NI32)((*pb_8).d_00.rpos_0 + ((NI32)offset_0)));}
        break;
        case 2:
        {
          NI32 X60Qx_118 = len_4_sysvq0asl((*pb_8).d_00.data_0);
          np_0 = ((NI32)(X60Qx_118 + ((NI32)offset_0)));}
        break;
        default:
        {
          eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_8);
          return ((NI64)-1);}
        break;}
      if (np_0 < 0){
        eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_8);
        return ((NI64)-1);}
      (*pb_8).d_00.rpos_0 = np_0;
      eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_8);
      return ((NI64)np_0);}
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_8);}
  X60Qlab_0: ;
  FILE** X60Qx_119 = getQ_7_Ilvng2h1_hos5i19e11((*sink_14).d_00.fds_0, fd_8);
  FILE* f_7 = (*X60Qx_119);
  if (f_7 == NIM_NIL){
    return ((NI64)-1);}
  FileSeekPos_0_syn1lfpjv X60Qx_6;
  switch (whence_0){
    case 0:
    {
      X60Qx_6 = 0;}
    break;
    case 1:
    {
      X60Qx_6 = 1;}
    break;
    case 2:
    {
      X60Qx_6 = 2;}
    break;
    default:
    {
      return ((NI64)-1);}
    break;}
  FileSeekPos_0_syn1lfpjv rel_0 = X60Qx_6;
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = setFilePos_0_syn1lfpjv(f_7, offset_0, rel_0);
  if (X60QcanRaise_0){
    goto X60Qexlab_1;}
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 X60QcanRaise_1 = getFilePos_0_syn1lfpjv(f_7);
  if (X60QcanRaise_1.fld_0){
    goto X60Qexlab_1;}
  result_16 = X60QcanRaise_1.fld_1;
  if (NIM_FALSE){
    X60Qexlab_1: ;
    result_16 = ((NI64)-1);}
  return result_16;}
NI32 hostFdLen_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_15, NI32 fd_9){
  NI32 result_17;
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_9 = pipeAt_0_hos5i19e11(sink_15, fd_9);
  if ((!(pb_9 == NIM_NIL))){
    NI32 X60Qx_120 = len_4_sysvq0asl((*pb_9).d_00.data_0);
    result_17 = X60Qx_120;
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_9);
    return result_17;}
  result_17 = -1;
  eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_9);
  return result_17;
  eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_9);
  return result_17;}
NI64 hostTell_0_hos5i19e11(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_16, NI32 fd_10){
  NI64 result_18;
  NB8 X60Qx_121;
  if (fd_10 < 3){
    X60Qx_121 = NIM_TRUE;}
  else {
    X60Qx_121 = ((*sink_16).d_00.fds_0.len_0 <= fd_10);}
  if (X60Qx_121){
    return ((NI64)-1);}
  {
    X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* pb_10 = pipeAt_0_hos5i19e11(sink_16, fd_10);
    if ((!(pb_10 == NIM_NIL))){
      result_18 = ((NI64)(*pb_10).d_00.rpos_0);
      eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_10);
      return result_18;}
    eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(pb_10);}
  X60Qlab_0: ;
  FILE** X60Qx_122 = getQ_7_Ilvng2h1_hos5i19e11((*sink_16).d_00.fds_0, fd_10);
  FILE* f_8 = (*X60Qx_122);
  if (f_8 == NIM_NIL){
    return ((NI64)-1);}
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 X60QcanRaise_0 = getFilePos_0_syn1lfpjv(f_8);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_2;}
  result_18 = X60QcanRaise_0.fld_1;
  if (NIM_FALSE){
    X60Qexlab_2: ;
    result_18 = ((NI64)-1);}
  return result_18;}
string_0_sysvq0asl hostExpandFilename_0_hos5i19e11(string_0_sysvq0asl path_3){
  string_0_sysvq0asl result_19;
  nimStrWasMoved((&result_19));
  NB8 X60Qx_123 = journalReplaying_0_jou8favxh1();
  if (X60Qx_123){
    string_0_sysvq0asl X60Qtmp_11 = portPath_0_jou8favxh1(path_3);
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_10 = jServe_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I12671210886245720931_hos5i19e11)}
    , X60Qtmp_11);
    string_0_sysvq0asl X60Qx_124 = jField_0_jou8favxh1(X60Qtmp_10, 0);
    result_19 = X60Qx_124;
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_10);
    nimStrDestroy(X60Qtmp_11);
    return result_19;
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_10);
    nimStrDestroy(X60Qtmp_11);}
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_1 = getCurrentDir_0_ospaexnw61();
  if (X60QcanRaise_1.fld_0){
    goto X60Qexlab_3;}
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_0 = absolutePath_0_ospaexnw61(path_3, X60QcanRaise_1.fld_1);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_3;}
  nimStrDestroy(result_19);
  string_0_sysvq0asl X60Qx_125 = normalizedPath_0_ospaexnw61(X60QcanRaise_0.fld_1);
  result_19 = X60Qx_125;
  if (NIM_FALSE){
    X60Qexlab_3: ;
    nimStrDestroy(result_19);
    string_0_sysvq0asl X60Qx_126 = nimStrDup(path_3);
    result_19 = X60Qx_126;}
  NB8 X60Qx_127 = journalRecording_0_jou8favxh1();
  if (X60Qx_127){
    string_0_sysvq0asl X60Qtmp_12 = portPath_0_jou8favxh1(path_3);
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_13 = atQ_0_I508dwj_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01){
      .a = {
        result_19}}
    );
    jRecord_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I12671210886245720931_hos5i19e11)}
    , X60Qtmp_12, X60Qtmp_13);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_13);
    nimStrDestroy(X60Qtmp_12);}
  return result_19;}
static inline NI32 len_3_Ijmnbol_hos5i19e11(seq_0_Iygo52q1_hos5i19e11 s_8){
  NI32 result_20;
  result_20 = s_8.len_0;
  return result_20;}
static inline void add_0_Ifwhkoy_hos5i19e11(seq_0_Iygo52q1_hos5i19e11* s_9, FILE* elem_4){
  NI32 L_0 = (*s_9).len_0;
  NI32 X60Qx_128 = capInBytes_0_Ifagzit_hos5i19e11((*s_9));
  if (X60Qx_128 < ((NI32)(((NI32)(L_0 * sizeof(FILE*))) + sizeof(FILE*)))){
    NB8 X60Qx_129 = resize_0_Isbw7m8_hos5i19e11(s_9, 1);
    if ((!X60Qx_129)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_9).len_0));
  (*s_9).data_0[L_0] = elem_4;}
static inline FILE** getQ_7_Ilvng2h1_hos5i19e11(seq_0_Iygo52q1_hos5i19e11 s_11, NI32 i_13){
  NB8 X60Qx_130;
  if (i_13 < s_11.len_0){
    X60Qx_130 = (0 <= i_13);}
  else {
    X60Qx_130 = NIM_FALSE;}
  if ((!X60Qx_130)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  FILE** result_21;
  result_21 = (&s_11.data_0[i_13]);
  return result_21;}
static inline void putQ_7_Inawu4x1_hos5i19e11(seq_0_Iygo52q1_hos5i19e11* s_12, NI32 i_14, FILE* elem_5){
  NB8 X60Qx_131;
  if (i_14 < (*s_12).len_0){
    X60Qx_131 = (0 <= i_14);}
  else {
    X60Qx_131 = NIM_FALSE;}
  if ((!X60Qx_131)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_12).data_0[i_14] = elem_5;}
static inline NI32 len_3_I2hf64u1_hos5i19e11(seq_0_I9xd2d01_hos5i19e11 s_13){
  NI32 result_22;
  result_22 = s_13.len_0;
  return result_22;}
static inline X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** getQ_7_Ihikmzc_hos5i19e11(seq_0_I9xd2d01_hos5i19e11 s_14, NI32 i_15){
  NB8 X60Qx_132;
  if (i_15 < s_14.len_0){
    X60Qx_132 = (0 <= i_15);}
  else {
    X60Qx_132 = NIM_FALSE;}
  if ((!X60Qx_132)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** result_23;
  result_23 = (&s_14.data_0[i_15]);
  return result_23;}
static inline void add_0_Inzrvyi_hos5i19e11(seq_0_I9xd2d01_hos5i19e11* s_15, X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* elem_6){
  NI32 L_1 = (*s_15).len_0;
  NI32 X60Qx_133 = capInBytes_0_Is2driv_hos5i19e11((*s_15));
  if (X60Qx_133 < ((NI32)(((NI32)(L_1 * sizeof(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11*))) + sizeof(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11*)))){
    NB8 X60Qx_134 = resize_0_Iq5i634_hos5i19e11(s_15, 1);
    if ((!X60Qx_134)){
      eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(elem_6);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_15).len_0));
  (*s_15).data_0[L_1] = elem_6;}
static inline void putQ_7_I6xhgv5_hos5i19e11(seq_0_I9xd2d01_hos5i19e11* s_17, NI32 i_16, X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* elem_7){
  NB8 X60Qx_135;
  if (i_16 < (*s_17).len_0){
    X60Qx_135 = (0 <= i_16);}
  else {
    X60Qx_135 = NIM_FALSE;}
  if ((!X60Qx_135)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** X60Qlhs_14 = (&(*s_17).data_0[i_16]);
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* X60Qlhs_15 = elem_7;
  eQwasmovedQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11((&elem_7));
  eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11((*X60Qlhs_14));
  (*X60Qlhs_14) = X60Qlhs_15;
  eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(elem_7);}
static inline X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 default_23_Isnz07p_hos5i19e11(void){
  X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 result_25;
  {
    NI32 X60Qlf_0 = ((NI32)0);
    NI32 X60Qlf_1 = ((NI32)65535);
    NI32 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 <= X60Qlf_1){
        {
          NI32 X60Qx_139 = nimIcheckB(X60Qlf_2, 65535);
          result_25.a[X60Qx_139] = (NC8)'\000';}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_25;}
static inline void minusQeQ_0_Ipe1u69_hos5i19e11(NI32* x_5, NI32 y_1){
  (*x_5) = ((NI32)((*x_5) - y_1));}
static inline NI32 capInBytes_0_Ifagzit_hos5i19e11(seq_0_Iygo52q1_hos5i19e11 s_18){
  NI32 result_27;
  NI32 X60Qx_7;
  if ((!(s_18.data_0 == NIM_NIL))){
    NI32 X60Qx_143 = allocatedSize_0_sysvq0asl(((void*)((void*)s_18.data_0)));
    X60Qx_7 = X60Qx_143;}
  else {
    X60Qx_7 = 0;}
  result_27 = X60Qx_7;
  return result_27;}
NB8 resize_0_Isbw7m8_hos5i19e11(seq_0_Iygo52q1_hos5i19e11* dest_2, NI32 addedElements_2){
  NB8 result_28;
  NI32 X60Qx_144 = capInBytes_0_Ifagzit_hos5i19e11((*dest_2));
  NI32 oldCap_0 = ((NI32)(X60Qx_144 / sizeof(FILE*)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_2);
  NI32 memSize_0 = memSizeInBytes_0_Ifkbdqp_hos5i19e11(newCap_0);
  void* X60Qx_145 = realloc_1_sysvq0asl(((void*)((void*)(*dest_2).data_0)), memSize_0);
  (*dest_2).data_0 = ((FILE**)X60Qx_145);
  if ((*dest_2).data_0 == NIM_NIL){
    (*dest_2).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_0);
    result_28 = NIM_FALSE;}
  else {
    result_28 = NIM_TRUE;}
  return result_28;}
static inline NI32 capInBytes_0_Is2driv_hos5i19e11(seq_0_I9xd2d01_hos5i19e11 s_19){
  NI32 result_29;
  NI32 X60Qx_8;
  if ((!(s_19.data_0 == NIM_NIL))){
    NI32 X60Qx_146 = allocatedSize_0_sysvq0asl(((void*)((void*)s_19.data_0)));
    X60Qx_8 = X60Qx_146;}
  else {
    X60Qx_8 = 0;}
  result_29 = X60Qx_8;
  return result_29;}
NB8 resize_0_Iq5i634_hos5i19e11(seq_0_I9xd2d01_hos5i19e11* dest_3, NI32 addedElements_3){
  NB8 result_30;
  NI32 X60Qx_147 = capInBytes_0_Is2driv_hos5i19e11((*dest_3));
  NI32 oldCap_1 = ((NI32)(X60Qx_147 / sizeof(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11*)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_3);
  NI32 memSize_1 = memSizeInBytes_0_Ie4yvp31_hos5i19e11(newCap_1);
  void* X60Qx_148 = realloc_1_sysvq0asl(((void*)((void*)(*dest_3).data_0)), memSize_1);
  (*dest_3).data_0 = ((X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11**)X60Qx_148);
  if ((*dest_3).data_0 == NIM_NIL){
    (*dest_3).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_1);
    result_30 = NIM_FALSE;}
  else {
    result_30 = NIM_TRUE;}
  return result_30;}
static inline NI32 memSizeInBytes_0_Ifkbdqp_hos5i19e11(NI32 size_5){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_32;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_5, sizeof(FILE*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_32 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_32 = ((NI32)2147483647);}
  return result_32;}
static inline NI32 memSizeInBytes_0_Ie4yvp31_hos5i19e11(NI32 size_6){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_33;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_6, sizeof(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_33 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_33 = ((NI32)2147483647);}
  return result_33;}
void eQdestroy_1_I3k7gu91_hos5i19e11(seq_0_Iygo52q1_hos5i19e11 s_29){
  if ((!(s_29.data_0 == NIM_NIL))){
    NI32 i_25 = 0;
    {
      while (i_25 < s_29.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_25));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_29.data_0)));}}
void eQdestroy_1_Ibw1jxo1_hos5i19e11(seq_0_I9xd2d01_hos5i19e11 s_31){
  if ((!(s_31.data_0 == NIM_NIL))){
    NI32 i_29 = 0;
    {
      while (i_29 < s_31.len_0){
        eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(s_31.data_0[i_29]);
        inc_1_I6wjjge_aow2h993l1((&i_29));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_31.data_0)));}}
static inline seq_0_Iygo52q1_hos5i19e11 newSeqUninit_0_Iitdu24_hos5i19e11(NI32 size_10){
  seq_0_Iygo52q1_hos5i19e11 result_39;
  if (size_10 == 0){
    result_39 = (seq_0_Iygo52q1_hos5i19e11){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_6 = memSizeInBytes_0_Ifkbdqp_hos5i19e11(size_10);
    void* X60Qx_168 = alloc_1_sysvq0asl(memSize_6);
    result_39 = (seq_0_Iygo52q1_hos5i19e11){
      .len_0 = size_10, .data_0 = ((FILE**)X60Qx_168)}
    ;
    if ((!(result_39.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_169 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_39.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_6);}}
  return result_39;}
static inline seq_0_I9xd2d01_hos5i19e11 newSeqUninit_0_Ixqip6b1_hos5i19e11(NI32 size_11){
  seq_0_I9xd2d01_hos5i19e11 result_40;
  if (size_11 == 0){
    result_40 = (seq_0_I9xd2d01_hos5i19e11){
      .len_0 = size_11, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_7 = memSizeInBytes_0_Ie4yvp31_hos5i19e11(size_11);
    void* X60Qx_170 = alloc_1_sysvq0asl(memSize_7);
    result_40 = (seq_0_I9xd2d01_hos5i19e11){
      .len_0 = size_11, .data_0 = ((X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11**)X60Qx_170)}
    ;
    if ((!(result_40.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_171 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_40.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_7);}}
  return result_40;}
void eQwasmovedQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* eQdupQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* src_0){
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX50ipeX42ufX4fbj0natd5co251_0_hos5i19e11(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11* dest_0){
  if (dest_0){
    NB8 X60Qx_172 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_172){
      eQdestroyQ_SX50ipeX42ufX4fbj0natd5co251_0_natd5co251((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void X60Qini_0_hos5i19e11(void){
  if (X60QiniGuard_0_hos5i19e11){
    return;}
  X60QiniGuard_0_hos5i19e11 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_natd5co251();
  X60Qini_0_iop7yt73v();
  X60Qini_0_jou8favxh1();}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
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
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
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
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
