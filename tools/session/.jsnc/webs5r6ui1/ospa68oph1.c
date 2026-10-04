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
#include <stdio.h>
#include <sys/types.h>
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1 X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX50rocessX4fbj0ospa68oph1_ospa68oph1 X60Qt_0_IArefSX50rocessX4fbj0ospa68oph1_ospa68oph1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAbool_osc4bsu0d1 X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAbool_osc4bsu0d1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1 X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1;
typedef struct HSlice_0_Inzqy8d_aow7lb5cq1 HSlice_0_Inzqy8d_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6Abool_ospa68oph1 X60Qt_0_IAtupleSstring0sysvq0aslSR6Abool_ospa68oph1;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX46ileX53treamX4fbj0str7oj7yj1_ospa68oph1 X60Qt_0_IArefSX46ileX53treamX4fbj0str7oj7yj1_ospa68oph1;
typedef struct ProcessObj_0_ospa68oph1 ProcessObj_0_ospa68oph1;
typedef struct StringTableObj_0_str21a45d1 StringTableObj_0_str21a45d1;
typedef NU8 ProcessOption_0_ospa68oph1;

#define poEchoCmd_0_ospa68oph1 ((NU8)0)
#define poUsePath_0_ospa68oph1 ((NU8)1)
#define poEvalCommand_0_ospa68oph1 ((NU8)2)
#define poStdErrToStdOut_0_ospa68oph1 ((NU8)3)
#define poParentStreams_0_ospa68oph1 ((NU8)4)
#define poInteractive_0_ospa68oph1 ((NU8)5)
#define poDaemon_0_ospa68oph1 ((NU8)6)
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct ProcessObj_0_ospa68oph1{
  RootObj_0_sysvq0asl Q;
  int inHandle_0;
  int outHandle_0;
  int errHandle_0;
  pid_t id_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1* inStream_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1* outStream_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1* errStream_0;
  int exitStatus_0;
  NB8 exitFlag_0;
  NU8 options_0;}
ProcessObj_0_ospa68oph1;
typedef struct openArray_0_Ig73pnk_aow7lb5cq1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_aow7lb5cq1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_Ijvptge_ospa68oph1{
  NI32 len_0;
  X60Qt_0_IArefSX50rocessX4fbj0ospa68oph1_ospa68oph1** data_0;}
seq_0_Ijvptge_ospa68oph1;
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
typedef N_NIMCALL_PTR(ErrorCode_0_sysvq0asl,  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZSEAnimcallZAtrueZAfalse_str7oj7yj1)(X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1*);
typedef N_NIMCALL_PTR(X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAbool_osc4bsu0d1,  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAboolZAnimcallZAtrueZAfalse_str7oj7yj1)(X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1*);
typedef N_NIMCALL_PTR(ErrorCode_0_sysvq0asl,  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAiS32ZSEAnimcallZAtrueZAfalse_str7oj7yj1)(X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1*, NI32);
typedef N_NIMCALL_PTR(X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1,  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAiS32ZAnimcallZAtrueZAfalse_str7oj7yj1)(X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1*);
typedef N_NIMCALL_PTR(X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1,  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAmutSstring0sysvq0aslZSX48X53lice0X49nzqy8dAiS32ZAnimcallZAtrueZAfalse_str7oj7yj1)(X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1*, string_0_sysvq0asl*, HSlice_0_Inzqy8d_aow7lb5cq1);
typedef N_NIMCALL_PTR(X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAbool_osc4bsu0d1,  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAmutSstring0sysvq0aslZAboolZAnimcallZAtrueZAfalse_str7oj7yj1)(X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1*, string_0_sysvq0asl*);
typedef N_NIMCALL_PTR(X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1,  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZApointerZAiS32ZAiS32ZAnimcallZAtrueZAfalse_str7oj7yj1)(X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1*, void*, NI32);
typedef N_NIMCALL_PTR(ErrorCode_0_sysvq0asl,  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZApointerZAiS32ZSEAnimcallZAtrueZAfalse_str7oj7yj1)(X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1*, void*, NI32);
typedef struct StreamObj_0_str7oj7yj1{
  RootObj_0_sysvq0asl Q;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZSEAnimcallZAtrueZAfalse_str7oj7yj1 closeImpl_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAboolZAnimcallZAtrueZAfalse_str7oj7yj1 atEndImpl_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAiS32ZSEAnimcallZAtrueZAfalse_str7oj7yj1 setPositionImpl_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAiS32ZAnimcallZAtrueZAfalse_str7oj7yj1 getPositionImpl_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAmutSstring0sysvq0aslZSX48X53lice0X49nzqy8dAiS32ZAnimcallZAtrueZAfalse_str7oj7yj1 readDataStrImpl_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZAmutSstring0sysvq0aslZAboolZAnimcallZAtrueZAfalse_str7oj7yj1 readLineImpl_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZApointerZAiS32ZAiS32ZAnimcallZAtrueZAfalse_str7oj7yj1 readDataImpl_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZApointerZAiS32ZAiS32ZAnimcallZAtrueZAfalse_str7oj7yj1 peekDataImpl_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZApointerZAiS32ZSEAnimcallZAtrueZAfalse_str7oj7yj1 writeDataImpl_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1ZSEAnimcallZAtrueZAfalse_str7oj7yj1 flushImpl_0;}
StreamObj_0_str7oj7yj1;
typedef struct X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1{
  NI r_00;
  StreamObj_0_str7oj7yj1 d_00;}
X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1;
typedef struct X60Qt_0_IArefSX50rocessX4fbj0ospa68oph1_ospa68oph1{
  NI r_00;
  ProcessObj_0_ospa68oph1 d_00;}
X60Qt_0_IArefSX50rocessX4fbj0ospa68oph1_ospa68oph1;
typedef struct seq_0_Ij3n73f1_str21a45d1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSR6Abool_ospa68oph1* data_0;}
seq_0_Ij3n73f1_str21a45d1;
typedef NU8 StringTableMode_0_str21a45d1;

#define modeCaseSensitive_0_str21a45d1 ((NU8)0)
#define modeCaseInsensitive_0_str21a45d1 ((NU8)1)
#define modeStyleInsensitive_0_str21a45d1 ((NU8)2)
typedef struct StringTableObj_0_str21a45d1{
  RootObj_0_sysvq0asl Q;
  NI32 counter_0;
  seq_0_Ij3n73f1_str21a45d1 data_0;
  StringTableMode_0_str21a45d1 mode_0;}
StringTableObj_0_str21a45d1;
typedef struct X60Qt_0_IArefSX53tringX54ableX4fbj0str21a45d1_ospa68oph1{
  NI r_00;
  StringTableObj_0_str21a45d1 d_00;}
X60Qt_0_IArefSX53tringX54ableX4fbj0str21a45d1_ospa68oph1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6Abool_ospa68oph1{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;
  NB8 fld_2;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6Abool_ospa68oph1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslArefSX50rocessX4fbj0ospa68oph1_ospa68oph1{
  ErrorCode_0_sysvq0asl fld_0;
  X60Qt_0_IArefSX50rocessX4fbj0ospa68oph1_ospa68oph1* fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslArefSX50rocessX4fbj0ospa68oph1_ospa68oph1;
typedef struct X60Qt_0_IAarrayAiS32AimportcSUintUZZS2_intzsnzax{
  int a[2];}
X60Qt_0_IAarrayAiS32AimportcSUintUZZS2_intzsnzax;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01{
  string_0_sysvq0asl a[3];}
X60Qt_0_IAarraySstring0sysvq0aslS3_emi78vuj01;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01{
  string_0_sysvq0asl a[1];}
X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1{
  ErrorCode_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAbool_osc4bsu0d1{
  ErrorCode_0_sysvq0asl fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAbool_osc4bsu0d1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1{
  ErrorCode_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1;
typedef struct FileStreamObj_0_str7oj7yj1{
  StreamObj_0_str7oj7yj1 Q;
  FILE* f_0;}
FileStreamObj_0_str7oj7yj1;
typedef struct X60Qt_0_IArefSX46ileX53treamX4fbj0str7oj7yj1_ospa68oph1{
  NI r_00;
  FileStreamObj_0_str7oj7yj1 d_00;}
X60Qt_0_IArefSX46ileX53treamX4fbj0str7oj7yj1_ospa68oph1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslArefSX46ileX53treamX4fbj0str7oj7yj1_ospa68oph1{
  ErrorCode_0_sysvq0asl fld_0;
  X60Qt_0_IArefSX46ileX53treamX4fbj0str7oj7yj1_ospa68oph1* fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslArefSX46ileX53treamX4fbj0str7oj7yj1_ospa68oph1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslArefSX53treamX4fbj0str7oj7yj1_ospa68oph1{
  ErrorCode_0_sysvq0asl fld_0;
  X60Qt_0_IArefSX53treamX4fbj0str7oj7yj1_ospa68oph1* fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslArefSX53treamX4fbj0str7oj7yj1_ospa68oph1;
typedef struct X60Qt_0_IAtupleSseq0X49xdx2fh1AiS32_ospa68oph1{
  seq_0_Ixdx2fh1_aow7lb5cq1 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSseq0X49xdx2fh1AiS32_ospa68oph1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAR0Sseq0X49xdx2fh1AiS32_ospa68oph1{
  ErrorCode_0_sysvq0asl fld_0;
  X60Qt_0_IAtupleSseq0X49xdx2fh1AiS32_ospa68oph1 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAR0Sseq0X49xdx2fh1AiS32_ospa68oph1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAR0Sstring0R20AiS32_ospa68oph1{
  ErrorCode_0_sysvq0asl fld_0;
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAR0Sstring0R20AiS32_ospa68oph1;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS0_ospa68oph1{
  string_0_sysvq0asl a[0];}
X60Qt_0_IAarraySstring0sysvq0aslS0_ospa68oph1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISX50rocessX4fbj0ospa68oph1SEAnimcallZAfalseZAR37_ospa68oph1)(ProcessObj_0_ospa68oph1*);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISX53tringX54ableX4fbj0str21a45d1SEAnimcallZAfalseZAR43_ospa68oph1)(StringTableObj_0_str21a45d1*);
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
typedef struct HSlice_0_Inzqy8d_aow7lb5cq1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_aow7lb5cq1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern NC8* toCString_0_sysvq0asl(string_0_sysvq0asl* s_64);
extern int exitStatusLikeShell_0_oswd7dmm(int status_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_str7j0ifg(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_str21a45d1(void);
extern void X60Qini_0_str7oj7yj1(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_cpuf8djhu(void);
extern void X60Qini_0_osezuyu63(void);
extern void X60Qini_0_envto7w6l1(void);
extern void X60Qini_0_mon82i3ln(void);
extern void X60Qini_0_timsagyye1(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_pososrh1q1(void);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
NB8 X60QiniGuard_0_ospa68oph1;
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1 execCmd_0_ospa68oph1(string_0_sysvq0asl command_1){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1 result_20;
  result_20.fld_0 = 0;
  string_0_sysvq0asl cmd_1 = nimStrDup(command_1);
  NC8* X60Qx_160 = toCString_0_sysvq0asl((&cmd_1));
  int tmp_0 = system(X60Qx_160);
  int X60Qx_2;
  if (tmp_0 == -1){
    X60Qx_2 = tmp_0;}
  else {
    int X60Qx_161 = exitStatusLikeShell_0_oswd7dmm(tmp_0);
    X60Qx_2 = X60Qx_161;}
  result_20 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1){
    .fld_0 = 0, .fld_1 = X60Qx_2}
  ;
  nimStrDestroy(cmd_1);
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1){
    .fld_0 = 0, .fld_1 = result_20.fld_1}
  ;
  nimStrDestroy(cmd_1);
  return result_20;}
void X60Qini_0_ospa68oph1(void){
  if (X60QiniGuard_0_ospa68oph1){
    return;}
  X60QiniGuard_0_ospa68oph1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_str7j0ifg();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_str21a45d1();
  X60Qini_0_str7oj7yj1();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_cpuf8djhu();
  X60Qini_0_osezuyu63();
  X60Qini_0_envto7w6l1();
  X60Qini_0_mon82i3ln();
  X60Qini_0_timsagyye1();
  X60Qini_0_assy765wm();
  X60Qini_0_pososrh1q1();}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
