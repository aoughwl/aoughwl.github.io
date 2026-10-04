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
#include <string.h>
#include <stdio.h>
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21;
typedef struct X60Qt_0_IAtupleAsetAcS8ZZAcS8_str7j0ifg X60Qt_0_IAtupleAsetAcS8ZZAcS8_str7j0ifg;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef NU8 FloatFormatMode_0_str7j0ifg;

#define ffDefault_0_str7j0ifg ((NU8)0)
#define ffDecimal_0_str7j0ifg ((NU8)1)
#define ffScientific_0_str7j0ifg ((NU8)2)
typedef NU8 BinaryPrefixMode_0_str7j0ifg;

#define bpIEC_0_str7j0ifg ((NU8)0)
#define bpColloquial_0_str7j0ifg ((NU8)1)
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct HSlice_0_Inzqy8d_comaa5xpt1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_comaa5xpt1;
typedef struct openArray_0_Ihfaw761_prorcx25w1{
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21* a_0;
  NI32 len_0;}
openArray_0_Ihfaw761_prorcx25w1;
typedef struct openArray_0_Ijk0jkw1_feaji4clb1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_feaji4clb1;
typedef struct openArray_0_I8ohqne_str7j0ifg{
  X60Qt_0_IAtupleAsetAcS8ZZAcS8_str7j0ifg* a_0;
  NI32 len_0;}
openArray_0_I8ohqne_str7j0ifg;
typedef struct openArray_0_Ig73pnk_comaa5xpt1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_comaa5xpt1;
typedef struct openArray_0_Inqs7yx_comaa5xpt1{
  NI32* a_0;
  NI32 len_0;}
openArray_0_Inqs7yx_comaa5xpt1;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[32];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct X60Qt_0_IAarrayAiS32ZS256_str7j0ifg{
  NI32 a[256];}
X60Qt_0_IAarrayAiS32ZS256_str7j0ifg;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21;
typedef struct X60Qt_0_IAtupleAsetAcS8ZZAcS8_str7j0ifg{
  X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 fld_0;
  NC8 fld_1;}
X60Qt_0_IAtupleAsetAcS8ZZAcS8_str7j0ifg;
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
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1{
  ErrorCode_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1;
typedef struct X60Qt_0_IAarrayAcS8ZS3_str7j0ifg{
  NC8 a[3];}
X60Qt_0_IAarrayAcS8ZS3_str7j0ifg;
typedef struct X60Qt_0_IAarrayAcS8ZS6_str7j0ifg{
  NC8 a[6];}
X60Qt_0_IAarrayAcS8ZS6_str7j0ifg;
typedef struct X60Qt_0_IAarrayAcS8ZS2501_str7j0ifg{
  NC8 a[2501];}
X60Qt_0_IAarrayAcS8ZS2501_str7j0ifg;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS7_str7j0ifg{
  string_0_sysvq0asl a[7];}
X60Qt_0_IAarraySstring0sysvq0aslS7_str7j0ifg;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1{
  ErrorCode_0_sysvq0asl fld_0;
  NI64 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1{
  ErrorCode_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1;
typedef struct X60Qt_0_IAarrayAtupleAsetAcS8ZZAcS8ZZS4_str7j0ifg{
  X60Qt_0_IAtupleAsetAcS8ZZAcS8_str7j0ifg a[4];}
X60Qt_0_IAarrayAtupleAsetAcS8ZZAcS8ZZS4_str7j0ifg;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern string_0_sysvq0asl newString_0_sysvq0asl(NI32 len_4);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l;
extern NB8 startsWithImpl_0_sysvq0asl(string_0_sysvq0asl s_59, string_0_sysvq0asl prefix_0);
static inline NI32 high_4_sysvq0asl(string_0_sysvq0asl s_35);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_party5a2l1(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I11201514831099767300_sysvq0asl;
extern void prepareMutation_0_sysvq0asl(string_0_sysvq0asl* s_46);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
LongString_0_sysvq0asl const strlit_0_I8062030498282895634_str7j0ifg = {
  .fullLen_0 = 115, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/openarrays.nim(12, 59): 0 <= i and i < x.len [AssertionDefect]\012"}
;
static X60Qt_0_IAarrayAcS8ZS3_str7j0ifg const floatFormatToChar_0 = {
  .a = {
    (NC8)'g', (NC8)'f', (NC8)'e'}}
;
NB8 X60QiniGuard_0_str7j0ifg;
string_0_sysvq0asl dollarQ_0_str7j0ifg(NC8* x_1){
  string_0_sysvq0asl result_12;
  nimStrWasMoved((&result_12));
  if (((void*)x_1) == NIM_NIL){
    nimStrDestroy(result_12);
    result_12 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  else {
    NI32 X60Qx_51 = strlen(x_1);
    NI32 L_0 = ((NI32)X60Qx_51);
    nimStrDestroy(result_12);
    string_0_sysvq0asl X60Qx_52 = newString_0_sysvq0asl(L_0);
    result_12 = X60Qx_52;
    {
      NI32 X60Qlf_11 = 0;
      NI32 X60Qlf_12 = len_4_sysvq0asl(result_12);
      NI32 X60Qlf_13 = X60Qlf_11;
      {
        while (X60Qlf_13 < X60Qlf_12){
          {
            putQ_9_sysvq0asl((&result_12), X60Qlf_13, x_1[X60Qlf_13]);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_13));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  return result_12;}
string_0_sysvq0asl dollarQ_1_str7j0ifg(NC8 x_2){
  string_0_sysvq0asl result_13;
  nimStrWasMoved((&result_13));
  nimStrDestroy(result_13);
  string_0_sysvq0asl X60Qx_53 = newString_0_sysvq0asl(1);
  result_13 = X60Qx_53;
  putQ_9_sysvq0asl((&result_13), 0, x_2);
  return result_13;}
NB8 startsWith_0_str7j0ifg(string_0_sysvq0asl s_21, string_0_sysvq0asl prefix_1){
  NB8 result_21;
  string_0_sysvq0asl X60Qx_106 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  NB8 X60Qx_107 = startsWithImpl_0_sysvq0asl(s_21, prefix_1);
  result_21 = X60Qx_107;
  return result_21;}
NI32 find_0_str7j0ifg(string_0_sysvq0asl s_27, NC8 sub_0, NI32 start_1, NI32 last_0){
  NI32 result_31;
  result_31 = -1;
  NI32 X60Qx_10;
  if (last_0 < 0){
    NI32 X60Qx_154 = high_4_sysvq0asl(s_27);
    X60Qx_10 = X60Qx_154;}
  else {
    X60Qx_10 = last_0;}
  NI32 last_10 = X60Qx_10;
  {
    NI32 X60Qlf_58 = ((NI32)start_1);
    NI32 X60Qlf_59 = last_10;
    NI32 X60Qlf_60 = X60Qlf_58;
    {
      while (X60Qlf_60 <= X60Qlf_59){
        {
          NC8 X60Qx_155 = getQ_9_sysvq0asl(s_27, X60Qlf_60);
          if (X60Qx_155 == sub_0){
            return X60Qlf_60;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_60));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_31;}
string_0_sysvq0asl formatBiggestFloat_0_str7j0ifg(NF64 f_0, FloatFormatMode_0_str7j0ifg format_0, NI32 precision_0, NC8 decimalSep_0){
  string_0_sysvq0asl result_44;
  nimStrWasMoved((&result_44));
  string_0_sysvq0asl X60Qx_223 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  X60Qt_0_IAarrayAcS8ZS6_str7j0ifg frmtstr_0;
  X60Qt_0_IAarrayAcS8ZS2501_str7j0ifg buf_1;
  int L_1;
  NI32 X60Qx_224 = nimIcheckB(0, 5);
  frmtstr_0.a[X60Qx_224] = (NC8)'%';
  if (0 <= ((NI32)precision_0)){
    NI32 X60Qx_225 = nimIcheckB(1, 5);
    frmtstr_0.a[X60Qx_225] = (NC8)'#';
    NI32 X60Qx_226 = nimIcheckB(2, 5);
    frmtstr_0.a[X60Qx_226] = (NC8)'.';
    NI32 X60Qx_227 = nimIcheckB(3, 5);
    frmtstr_0.a[X60Qx_227] = (NC8)'*';
    NI32 X60Qx_228 = nimIcheckB(4, 5);
    NI32 X60Qx_229 = nimIcheckB(format_0, 2);
    frmtstr_0.a[X60Qx_228] = floatFormatToChar_0.a[X60Qx_229];
    NI32 X60Qx_230 = nimIcheckB(5, 5);
    frmtstr_0.a[X60Qx_230] = (NC8)'\000';
    int X60Qx_231 = snprintf(((NC8*)(&buf_1)), ((size_t)2501), ((NC8*)(&frmtstr_0)), precision_0, f_0);
    L_1 = X60Qx_231;}
  else {
    NI32 X60Qx_232 = nimIcheckB(1, 5);
    NI32 X60Qx_233 = nimIcheckB(format_0, 2);
    frmtstr_0.a[X60Qx_232] = floatFormatToChar_0.a[X60Qx_233];
    NI32 X60Qx_234 = nimIcheckB(2, 5);
    frmtstr_0.a[X60Qx_234] = (NC8)'\000';
    int X60Qx_235 = snprintf(((NC8*)(&buf_1)), ((size_t)2501), ((NC8*)(&frmtstr_0)), f_0);
    L_1 = X60Qx_235;}
  nimStrDestroy(result_44);
  string_0_sysvq0asl X60Qx_236 = newString_0_sysvq0asl(L_1);
  result_44 = X60Qx_236;
  {
    NI32 X60Qlf_81 = 0;
    NI32 X60Qlf_82 = L_1;
    NI32 X60Qlf_83 = X60Qlf_81;
    {
      while (X60Qlf_83 < X60Qlf_82){
        {
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_38 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
            .a = {
              0u, 0u, 0u, 0u, 0u, 80u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
          ;
          NI32 X60Qx_237 = nimIcheckB(X60Qlf_83, 2500);
          NU64 X60Qdesugar_39 = ((NU)buf_1.a[X60Qx_237]);
          if (((NU8)(X60Qdesugar_38.a[((NU)(X60Qdesugar_39 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_39 & 7u)))))) != 0u){
            putQ_9_sysvq0asl((&result_44), X60Qlf_83, decimalSep_0);}
          else {
            NI32 X60Qx_238 = nimIcheckB(X60Qlf_83, 2500);
            putQ_9_sysvq0asl((&result_44), X60Qlf_83, buf_1.a[X60Qx_238]);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_83));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_44;}
void X60Qini_0_str7j0ifg(void){
  if (X60QiniGuard_0_str7j0ifg){
    return;}
  X60QiniGuard_0_str7j0ifg = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_assy765wm();
  X60Qini_0_party5a2l1();}
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
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15){
  NB8 X60Qx_259;
  NI32 X60Qx_260 = len_4_sysvq0asl((*s_55));
  if (i_15 < X60Qx_260){
    X60Qx_259 = (0 <= i_15);}
  else {
    X60Qx_259 = NIM_FALSE;}
  if ((!X60Qx_259)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I11201514831099767300_sysvq0asl)}
    );}
  prepareMutation_0_sysvq0asl(s_55);
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_55).bytes_0))))){
    (*(*s_55).more_0).data_0[i_15] = c_15;
    if (i_15 < ((NI32)3)){
      ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
  else {
    ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NI32 high_4_sysvq0asl(string_0_sysvq0asl s_35){
  NI32 result_99;
  NI32 X60Qx_220 = len_4_sysvq0asl(s_35);
  result_99 = ((NI32)(X60Qx_220 - 1));
  return result_99;}
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
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
