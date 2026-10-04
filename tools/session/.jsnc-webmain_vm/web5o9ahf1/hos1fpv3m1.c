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
#include <dirent.h>
#include <stdio.h>
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct DirSnapshot_0_hos1fpv3m1 DirSnapshot_0_hos1fpv3m1;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
typedef struct DirSnapshot_0_hos1fpv3m1{
  seq_0_Ixdx2fh1_ast8ri79k names_0;
  seq_0_Ift2sne_chu5m1rja1 kinds_0;
  NI32 pos_0;
  NB8 live_0;}
DirSnapshot_0_hos1fpv3m1;
typedef struct seq_0_Ikorkmv_hos1fpv3m1{
  NI32 len_0;
  DirSnapshot_0_hos1fpv3m1* data_0;}
seq_0_Ikorkmv_hos1fpv3m1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS2_hos1fpv3m1{
  string_0_sysvq0asl a[2];}
X60Qt_0_IAarraySstring0sysvq0aslS2_hos1fpv3m1;
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
typedef struct Path_0_pat4k2dls{
  string_0_sysvq0asl data_0;}
Path_0_pat4k2dls;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l{
  ErrorCode_0_sysvq0asl fld_0;
  Path_0_pat4k2dls fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS1_hos1fpv3m1{
  string_0_sysvq0asl a[1];}
X60Qt_0_IAarraySstring0sysvq0aslS1_hos1fpv3m1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1{
  ErrorCode_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1{
  ErrorCode_0_sysvq0asl fld_0;
  NI64 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1;
typedef NU8 PathComponent_0_osc4bsu0d1;

#define pcFile_0_osc4bsu0d1 ((NU8)0)
#define pcLinkToFile_0_osc4bsu0d1 ((NU8)1)
#define pcDir_0_osc4bsu0d1 ((NU8)2)
#define pcLinkToDir_0_osc4bsu0d1 ((NU8)3)
typedef struct X60Qt_0_IAtupleSX50athX43omponent0osc4bsu0d1SX50ath0pat4k2dls_hos1fpv3m1{
  PathComponent_0_osc4bsu0d1 fld_0;
  Path_0_pat4k2dls fld_1;}
X60Qt_0_IAtupleSX50athX43omponent0osc4bsu0d1SX50ath0pat4k2dls_hos1fpv3m1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct Time_0_timsagyye1{
  NI64 seconds_0;
  NI32 nanosecond_0;}
Time_0_timsagyye1;
typedef struct MonoTime_0_mon82i3ln{
  NI64 ticks_0;}
MonoTime_0_mon82i3ln;
typedef struct DirWalker_0_dir38pj6l{
  DIR* pimpl_0;
  Path_0_pat4k2dls dir_0;
  ErrorCode_0_sysvq0asl status_0;}
DirWalker_0_dir38pj6l;
typedef struct DirEntry_0_dir38pj6l{
  PathComponent_0_osc4bsu0d1 kind_0;
  Path_0_pat4k2dls path_0;}
DirEntry_0_dir38pj6l;
typedef NU8 FileSeekPos_0_syn1lfpjv;

#define fspSet_0_syn1lfpjv ((NU8)0)
#define fspCur_0_syn1lfpjv ((NU8)1)
#define fspEnd_0_syn1lfpjv ((NU8)2)
typedef NU8 FileMode_0_syn1lfpjv;

#define fmRead_0_syn1lfpjv ((NU8)0)
#define fmWrite_0_syn1lfpjv ((NU8)1)
#define fmReadWrite_0_syn1lfpjv ((NU8)2)
#define fmReadWriteExisting_0_syn1lfpjv ((NU8)3)
#define fmAppend_0_syn1lfpjv ((NU8)4)
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
int getpid(void);
seq_0_Ixdx2fh1_ast8ri79k atQ_0_Ibamkxv1_hos1fpv3m1(X60Qt_0_IAarraySstring0sysvq0aslS2_hos1fpv3m1 a_6);
seq_0_Ixdx2fh1_ast8ri79k atQ_0_I508dwj_hos1fpv3m1(X60Qt_0_IAarraySstring0sysvq0aslS1_hos1fpv3m1 a_7);
static inline NI32 len_3_Iqiy1o3_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1 s_9);
static inline DirSnapshot_0_hos1fpv3m1* getQ_7_Irdozxf_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1 s_10, NI32 i_10);
static inline void putQ_7_Izkv0l3_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1* s_11, NI32 i_11, DirSnapshot_0_hos1fpv3m1 elem_4);
static inline void add_0_Iek2urt_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1* s_12, DirSnapshot_0_hos1fpv3m1 elem_5);
static inline NI32 memSizeInBytes_0_I08ylpd_hos1fpv3m1(NI32 size_9);
static inline NI32 capInBytes_0_Iuy29xh_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1 s_21);
NB8 resize_0_Iyfix491_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1* dest_3, NI32 addedElements_3);
void eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(DirSnapshot_0_hos1fpv3m1 dest_0);
void eQwasmovedQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(DirSnapshot_0_hos1fpv3m1* dest_0);
DirSnapshot_0_hos1fpv3m1 eQdupQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(DirSnapshot_0_hos1fpv3m1 src_0);
void eQdestroyQ_AtupleSX50athX43omponent0osc4bsu0d1SX50ath0pat4k2dls_0_hos1fpv3m1(X60Qt_0_IAtupleSX50athX43omponent0osc4bsu0d1SX50ath0pat4k2dls_hos1fpv3m1 dest_0);
extern NB8 capsDeniedOn_0_iop7yt73v(NI32 need_0, string_0_sysvq0asl path_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void recordViolation_0_iop7yt73v(string_0_sysvq0asl name_3, NI32 needed_2);
extern NB8 journalReplaying_0_jou8favxh1(void);
extern seq_0_Ixdx2fh1_ast8ri79k jServe_0_jou8favxh1(string_0_sysvq0asl kind_1, string_0_sysvq0asl key_1);
extern string_0_sysvq0asl jField_0_jou8favxh1(seq_0_Ixdx2fh1_ast8ri79k f_0, NI32 i_0);
extern NI32 jInt_0_jou8favxh1(string_0_sysvq0asl s_2);
extern void eQdestroy_1_Ivioh0a_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_46);
extern NB8 journalRecording_0_jou8favxh1(void);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern void jRecord_0_jou8favxh1(string_0_sysvq0asl kind_0, string_0_sysvq0asl key_0, seq_0_Ixdx2fh1_ast8ri79k fields_0);
extern string_0_sysvq0asl portPath_0_jou8favxh1(string_0_sysvq0asl p_1);
static inline Path_0_pat4k2dls path_0_pat4k2dls(string_0_sysvq0asl s_0);
extern ErrorCode_0_sysvq0asl tryCreateFinalDir_0_dir38pj6l(Path_0_pat4k2dls dir_0);
extern void eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(Path_0_pat4k2dls dest_0);
extern ErrorCode_0_sysvq0asl tryRemoveFinalDir_0_dir38pj6l(Path_0_pat4k2dls dir_2);
extern ErrorCode_0_sysvq0asl tryRemoveFile_0_dir38pj6l(Path_0_pat4k2dls file_0);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l getCurrentDir_0_dir38pj6l(void);
static inline string_0_sysvq0asl dollarQ_0_pat4k2dls(Path_0_pat4k2dls x_0);
extern ErrorCode_0_sysvq0asl setCurrentDir_0_dir38pj6l(Path_0_pat4k2dls dir_6);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1 execCmd_0_ospa68oph1(string_0_sysvq0asl command_1);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 getFilePos_0_syn1lfpjv(FILE* f_34);
extern ErrorCode_0_sysvq0asl setFilePos_0_syn1lfpjv(FILE* f_35, NI64 pos_0, FileSeekPos_0_syn1lfpjv relativeTo_0);
extern Time_0_timsagyye1 getTime_0_timsagyye1(void);
static inline NI64 seconds_0_timsagyye1(Time_0_timsagyye1 t_1);
static inline NI32 nanosecond_0_timsagyye1(Time_0_timsagyye1 t_2);
extern MonoTime_0_mon82i3ln getMonoTime_0_mon82i3ln(void);
extern NI64 ticks_0_mon82i3ln(MonoTime_0_mon82i3ln t_0);
extern NB8 open_0_syn1lfpjv(FILE** f_22, string_0_sysvq0asl filename_1, FileMode_0_syn1lfpjv mode_2, NI32 bufSize_0);
extern void close_0_syn1lfpjv(FILE* f_16);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline seq_0_Ixdx2fh1_ast8ri79k newSeqUninit_0_Im3cqd9_ast8ri79k(NI32 size_20);
static inline seq_0_Ift2sne_chu5m1rja1 newSeqUninit_0_Iggfvwp_chu5m1rja1(NI32 size_32);
static inline NI32 len_3_Ixq6taz_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_130);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5);
static inline void add_0_Ig6072n_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_20, string_0_sysvq0asl elem_3);
static inline void add_0_I8kd4i4_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_114, NI32 elem_27);
extern Path_0_pat4k2dls eQdupQ_SX50ath0pat4k2dls_0_pat4k2dls(Path_0_pat4k2dls src_0);
extern DirWalker_0_dir38pj6l tryOpenDir_0_dir38pj6l(Path_0_pat4k2dls dir_4);
extern void eQdestroyQ_SX44irX57alker0dir38pj6l_0_dir38pj6l(DirWalker_0_dir38pj6l dest_0);
extern NB8 tryNextDir_0_dir38pj6l(DirWalker_0_dir38pj6l* w_2, DirEntry_0_dir38pj6l* e_1);
extern void eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls(Path_0_pat4k2dls* dest_0);
static inline Path_0_pat4k2dls slashQ_0_pat4k2dls(Path_0_pat4k2dls head_0, Path_0_pat4k2dls tail_1);
extern void eQdestroyQ_SX44irX45ntry0dir38pj6l_0_dir38pj6l(DirEntry_0_dir38pj6l dest_0);
extern ErrorCode_0_sysvq0asl tryCloseDir_0_dir38pj6l(DirWalker_0_dir38pj6l* w_3);
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36);
extern void eQdestroy_1_Iv9ij5i1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_34);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_comaa5xpt1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
static inline void eQwasMoved_1_I5vdnla_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_47);
static inline void eQwasMoved_1_Ix88qzs1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1* s_35);
extern seq_0_Ixdx2fh1_ast8ri79k eQdup_1_Imq0s4c_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k a_10);
extern seq_0_Ift2sne_chu5m1rja1 eQdup_1_Iplow11_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 a_16);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_dir38pj6l(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_pat4k2dls(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_ospa68oph1(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_timsagyye1(void);
extern void X60Qini_0_mon82i3ln(void);
extern void X60Qini_0_iop7yt73v(void);
extern void X60Qini_0_jou8favxh1(void);
extern void X60Qini_0_osezuyu63(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NI32 memSizeInBytes_0_I7me00i_ast8ri79k(NI32 size_4);
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33);
static inline NI32 capInBytes_0_Ih2sbn01_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_28);
extern NB8 resize_0_I4buliy_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* dest_2, NI32 addedElements_2);
static inline NI32 capInBytes_0_Iet286n_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_72);
extern NB8 resize_0_I8l4tya_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* dest_22, NI32 addedElements_22);
extern string_0_sysvq0asl joinPath_0_ospaexnw61(string_0_sysvq0asl head_0, string_0_sysvq0asl tail_1);
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I7383674803287968507_hos1fpv3m1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " on \'"}
;
LongString_0_sysvq0asl const strlit_0_I11697234225982197076_hos1fpv3m1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mkdir"}
;
LongString_0_sysvq0asl const strlit_0_I4966622664534800651_hos1fpv3m1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mkdir(2)"}
;
LongString_0_sysvq0asl const strlit_0_I13735625106940001307_hos1fpv3m1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rmdir"}
;
LongString_0_sysvq0asl const strlit_0_I2765730614322406706_hos1fpv3m1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rmdir(2)"}
;
LongString_0_sysvq0asl const strlit_0_I2912131129587157308_hos1fpv3m1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unlink"}
;
LongString_0_sysvq0asl const strlit_0_I3700054611158304839_hos1fpv3m1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unlink(2)"}
;
LongString_0_sysvq0asl const strlit_0_I15418518599716865203_hos1fpv3m1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getcwd"}
;
LongString_0_sysvq0asl const strlit_0_I2723496349315214549_hos1fpv3m1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "chdir"}
;
LongString_0_sysvq0asl const strlit_0_I741435630578446865_hos1fpv3m1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "chdir(2)"}
;
LongString_0_sysvq0asl const strlit_0_I4050815769175754417_hos1fpv3m1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "system"}
;
LongString_0_sysvq0asl const strlit_0_I16745981998740488036_hos1fpv3m1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "system(3)"}
;
LongString_0_sysvq0asl const strlit_0_I15393414479670481275_hos1fpv3m1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "clock"}
;
LongString_0_sysvq0asl const strlit_0_I14102593084845164639_hos1fpv3m1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getpid"}
;
LongString_0_sysvq0asl const strlit_0_I4932132024348173802_hos1fpv3m1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fsize"}
;
LongString_0_sysvq0asl const strlit_0_I4718597432102153922_hos1fpv3m1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opendir"}
;
LongString_0_sysvq0asl const strlit_0_I14686529387667009019_hos1fpv3m1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opendir(3)"}
;
NI32 gErrno_0_hos1fpv3m1 = 0;
seq_0_Ikorkmv_hos1fpv3m1 gDirs_0_hos1fpv3m1;
NB8 X60QiniGuard_0_hos1fpv3m1;
NI32 hostErrno_0_hos1fpv3m1(void){
  NI32 result_0;
  result_0 = gErrno_0_hos1fpv3m1;
  return result_0;}
void setHostErrno_0_hos1fpv3m1(NI32 e_0){
  gErrno_0_hos1fpv3m1 = e_0;}
NB8 blockedByPolicy_0_hos1fpv3m1(string_0_sysvq0asl name_0, NI32 need_0, string_0_sysvq0asl path_0){
  NB8 result_1;
  NB8 X60Qx_9 = capsDeniedOn_0_iop7yt73v(need_0, path_0);
  if (X60Qx_9){
    string_0_sysvq0asl X60Qx_0;
    nimStrWasMoved((&X60Qx_0));
    NI32 X60Qx_10 = len_4_sysvq0asl(path_0);
    if (0 < X60Qx_10){
      NI32 X60Qx_11 = len_4_sysvq0asl(name_0);
      NI32 X60Qx_12 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I7383674803287968507_hos1fpv3m1)}
      );
      NI32 X60Qx_13 = len_4_sysvq0asl(path_0);
      NI32 X60Qx_14 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 9985u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_0 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_11 + X60Qx_12)) + X60Qx_13)) + X60Qx_14)));
      add_2_sysvq0asl((&X60Qdesugar_0), name_0);
      add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
        .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I7383674803287968507_hos1fpv3m1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_0), path_0);
      add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
        .bytes_0 = 9985u, .more_0 = NIM_NIL}
      );
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = X60Qdesugar_0;
      nimStrWasMoved((&X60Qdesugar_0));
      nimStrDestroy(X60Qdesugar_0);}
    else {
      nimStrDestroy(X60Qx_0);
      string_0_sysvq0asl X60Qx_15 = nimStrDup(name_0);
      X60Qx_0 = X60Qx_15;}
    recordViolation_0_iop7yt73v(X60Qx_0, need_0);
    gErrno_0_hos1fpv3m1 = ((NI32)1);
    result_1 = NIM_TRUE;
    nimStrDestroy(X60Qx_0);}
  else {
    result_1 = NIM_FALSE;}
  return result_1;}
NI32 errnoOf_0_hos1fpv3m1(ErrorCode_0_sysvq0asl ec_0){
  NI32 result_2;
  NI64 X60Qx_1;
  switch (ec_0){
    case 0:
    {
      X60Qx_1 = 0;}
    break;
    case 37:
    {
      X60Qx_1 = ((NI32)17);}
    break;
    case 38:
    {
      X60Qx_1 = ((NI32)2);}
    break;
    case 22:
    {
      X60Qx_1 = ((NI32)13);}
    break;
    case 32:
    {
      X60Qx_1 = ((NI32)39);}
    break;
    case 9:
    {
      X60Qx_1 = ((NI32)28);}
    break;
    case 11:
    {
      X60Qx_1 = ((NI32)5);}
    break;
    case 8:
    {
      X60Qx_1 = ((NI32)12);}
    break;
    case 23:
    {
      X60Qx_1 = ((NI32)11);}
    break;
    case 25:
    {
      X60Qx_1 = ((NI32)4);}
    break;
    default:
    {
      X60Qx_1 = ((NI32)22);}
    break;}
  result_2 = X60Qx_1;
  return result_2;}
NB8 jLeaf_0_hos1fpv3m1(string_0_sysvq0asl kind_0, string_0_sysvq0asl key_0, NI32* rc_0){
  NB8 result_3;
  NB8 X60Qx_16 = journalReplaying_0_jou8favxh1();
  if ((!X60Qx_16)){
    return NIM_FALSE;}
  seq_0_Ixdx2fh1_ast8ri79k a_0 = jServe_0_jou8favxh1(kind_0, key_0);
  string_0_sysvq0asl X60Qtmp_0 = jField_0_jou8favxh1(a_0, 0);
  NI32 X60Qx_17 = jInt_0_jou8favxh1(X60Qtmp_0);
  (*rc_0) = X60Qx_17;
  string_0_sysvq0asl X60Qtmp_1 = jField_0_jou8favxh1(a_0, 1);
  NI32 X60Qx_18 = jInt_0_jou8favxh1(X60Qtmp_1);
  setHostErrno_0_hos1fpv3m1(X60Qx_18);
  result_3 = NIM_TRUE;
  nimStrDestroy(X60Qtmp_1);
  nimStrDestroy(X60Qtmp_0);
  eQdestroy_1_Ivioh0a_ast8ri79k(a_0);
  return result_3;
  nimStrDestroy(X60Qtmp_1);
  nimStrDestroy(X60Qtmp_0);
  eQdestroy_1_Ivioh0a_ast8ri79k(a_0);
  return result_3;}
void jLeafDone_0_hos1fpv3m1(string_0_sysvq0asl kind_1, string_0_sysvq0asl key_1, NI32 rc_1){
  NB8 X60Qx_19 = journalRecording_0_jou8favxh1();
  if (X60Qx_19){
    string_0_sysvq0asl X60Qtmp_3 = dollarQ_2_sysvq0asl(rc_1);
    NI32 X60Qx_20 = hostErrno_0_hos1fpv3m1();
    string_0_sysvq0asl X60Qtmp_4 = dollarQ_2_sysvq0asl(X60Qx_20);
    seq_0_Ixdx2fh1_ast8ri79k X60Qtmp_2 = atQ_0_Ibamkxv1_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS2_hos1fpv3m1){
      .a = {
        X60Qtmp_3, X60Qtmp_4}}
    );
    jRecord_0_jou8favxh1(kind_1, key_1, X60Qtmp_2);
    eQdestroy_1_Ivioh0a_ast8ri79k(X60Qtmp_2);
    nimStrDestroy(X60Qtmp_4);
    nimStrDestroy(X60Qtmp_3);}}
NI32 hostMkdir_0_hos1fpv3m1(string_0_sysvq0asl p_0){
  NI32 result_4;
  NI32 jrc_0 = 0;
  string_0_sysvq0asl X60Qtmp_5 = portPath_0_jou8favxh1(p_0);
  NB8 X60Qx_21 = jLeaf_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1684762110u, .more_0 = (&strlit_0_I11697234225982197076_hos1fpv3m1)}
  , X60Qtmp_5, (&jrc_0));
  if (X60Qx_21){
    nimStrDestroy(X60Qtmp_5);
    return jrc_0;}
  NB8 X60Qx_22 = blockedByPolicy_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1684762110u, .more_0 = (&strlit_0_I4966622664534800651_hos1fpv3m1)}
  , ((NI32)2), p_0);
  if (X60Qx_22){
    nimStrDestroy(X60Qtmp_5);
    return -1;}
  Path_0_pat4k2dls X60Qtmp_6 = path_0_pat4k2dls(p_0);
  ErrorCode_0_sysvq0asl code_0 = tryCreateFinalDir_0_dir38pj6l(X60Qtmp_6);
  NI32 X60Qx_23 = errnoOf_0_hos1fpv3m1(code_0);
  setHostErrno_0_hos1fpv3m1(X60Qx_23);
  NI64 X60Qx_2;
  if (code_0 == 0){
    X60Qx_2 = 0;}
  else {
    X60Qx_2 = -1;}
  result_4 = X60Qx_2;
  string_0_sysvq0asl X60Qtmp_7 = portPath_0_jou8favxh1(p_0);
  jLeafDone_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1684762110u, .more_0 = (&strlit_0_I11697234225982197076_hos1fpv3m1)}
  , X60Qtmp_7, result_4);
  nimStrDestroy(X60Qtmp_7);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_6);
  nimStrDestroy(X60Qtmp_5);
  return result_4;
  nimStrDestroy(X60Qtmp_7);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_6);
  nimStrDestroy(X60Qtmp_5);
  return result_4;}
NI32 hostRmdir_0_hos1fpv3m1(string_0_sysvq0asl p_1){
  NI32 result_5;
  NI32 jrc_1 = 0;
  string_0_sysvq0asl X60Qtmp_8 = portPath_0_jou8favxh1(p_1);
  NB8 X60Qx_24 = jLeaf_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1684894462u, .more_0 = (&strlit_0_I13735625106940001307_hos1fpv3m1)}
  , X60Qtmp_8, (&jrc_1));
  if (X60Qx_24){
    nimStrDestroy(X60Qtmp_8);
    return jrc_1;}
  NB8 X60Qx_25 = blockedByPolicy_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1684894462u, .more_0 = (&strlit_0_I2765730614322406706_hos1fpv3m1)}
  , ((NI32)2), p_1);
  if (X60Qx_25){
    nimStrDestroy(X60Qtmp_8);
    return -1;}
  Path_0_pat4k2dls X60Qtmp_9 = path_0_pat4k2dls(p_1);
  ErrorCode_0_sysvq0asl code_1 = tryRemoveFinalDir_0_dir38pj6l(X60Qtmp_9);
  NI32 X60Qx_26 = errnoOf_0_hos1fpv3m1(code_1);
  setHostErrno_0_hos1fpv3m1(X60Qx_26);
  NI64 X60Qx_3;
  if (code_1 == 0){
    X60Qx_3 = 0;}
  else {
    X60Qx_3 = -1;}
  result_5 = X60Qx_3;
  string_0_sysvq0asl X60Qtmp_10 = portPath_0_jou8favxh1(p_1);
  jLeafDone_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1684894462u, .more_0 = (&strlit_0_I13735625106940001307_hos1fpv3m1)}
  , X60Qtmp_10, result_5);
  nimStrDestroy(X60Qtmp_10);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_9);
  nimStrDestroy(X60Qtmp_8);
  return result_5;
  nimStrDestroy(X60Qtmp_10);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_9);
  nimStrDestroy(X60Qtmp_8);
  return result_5;}
NI32 hostUnlink_0_hos1fpv3m1(string_0_sysvq0asl p_2){
  NI32 result_6;
  NI32 jrc_2 = 0;
  string_0_sysvq0asl X60Qtmp_11 = portPath_0_jou8favxh1(p_2);
  NB8 X60Qx_27 = jLeaf_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1819178494u, .more_0 = (&strlit_0_I2912131129587157308_hos1fpv3m1)}
  , X60Qtmp_11, (&jrc_2));
  if (X60Qx_27){
    nimStrDestroy(X60Qtmp_11);
    return jrc_2;}
  NB8 X60Qx_28 = blockedByPolicy_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1819178494u, .more_0 = (&strlit_0_I3700054611158304839_hos1fpv3m1)}
  , ((NI32)2), p_2);
  if (X60Qx_28){
    nimStrDestroy(X60Qtmp_11);
    return -1;}
  Path_0_pat4k2dls X60Qtmp_12 = path_0_pat4k2dls(p_2);
  ErrorCode_0_sysvq0asl code_2 = tryRemoveFile_0_dir38pj6l(X60Qtmp_12);
  NI32 X60Qx_29 = errnoOf_0_hos1fpv3m1(code_2);
  setHostErrno_0_hos1fpv3m1(X60Qx_29);
  NI64 X60Qx_4;
  if (code_2 == 0){
    X60Qx_4 = 0;}
  else {
    X60Qx_4 = -1;}
  result_6 = X60Qx_4;
  string_0_sysvq0asl X60Qtmp_13 = portPath_0_jou8favxh1(p_2);
  jLeafDone_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1819178494u, .more_0 = (&strlit_0_I2912131129587157308_hos1fpv3m1)}
  , X60Qtmp_13, result_6);
  nimStrDestroy(X60Qtmp_13);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_12);
  nimStrDestroy(X60Qtmp_11);
  return result_6;
  nimStrDestroy(X60Qtmp_13);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_12);
  nimStrDestroy(X60Qtmp_11);
  return result_6;}
string_0_sysvq0asl hostGetCwd_0_hos1fpv3m1(void){
  string_0_sysvq0asl result_7;
  nimStrWasMoved((&result_7));
  NB8 X60Qx_30 = journalReplaying_0_jou8favxh1();
  if (X60Qx_30){
    seq_0_Ixdx2fh1_ast8ri79k a_2 = jServe_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I15418518599716865203_hos1fpv3m1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    setHostErrno_0_hos1fpv3m1(0);
    string_0_sysvq0asl X60Qx_31 = jField_0_jou8favxh1(a_2, 0);
    result_7 = X60Qx_31;
    eQdestroy_1_Ivioh0a_ast8ri79k(a_2);
    return result_7;
    eQdestroy_1_Ivioh0a_ast8ri79k(a_2);}
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l X60QcanRaise_0 = getCurrentDir_0_dir38pj6l();
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_0;}
  nimStrDestroy(result_7);
  string_0_sysvq0asl X60Qx_32 = dollarQ_0_pat4k2dls(X60QcanRaise_0.fld_1);
  result_7 = X60Qx_32;
  setHostErrno_0_hos1fpv3m1(0);
  if (NIM_FALSE){
    X60Qexlab_0: ;
    setHostErrno_0_hos1fpv3m1(((NI32)13));
    nimStrDestroy(result_7);
    result_7 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NB8 X60Qx_33 = journalRecording_0_jou8favxh1();
  if (X60Qx_33){
    seq_0_Ixdx2fh1_ast8ri79k X60Qtmp_14 = atQ_0_I508dwj_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS1_hos1fpv3m1){
      .a = {
        result_7}}
    );
    jRecord_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I15418518599716865203_hos1fpv3m1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , X60Qtmp_14);
    eQdestroy_1_Ivioh0a_ast8ri79k(X60Qtmp_14);}
  return result_7;}
NI32 hostChdir_0_hos1fpv3m1(string_0_sysvq0asl p_3){
  NI32 result_8;
  NI32 jrc_3 = 0;
  string_0_sysvq0asl X60Qtmp_15 = portPath_0_jou8favxh1(p_3);
  NB8 X60Qx_34 = jLeaf_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1684562942u, .more_0 = (&strlit_0_I2723496349315214549_hos1fpv3m1)}
  , X60Qtmp_15, (&jrc_3));
  if (X60Qx_34){
    nimStrDestroy(X60Qtmp_15);
    return jrc_3;}
  NB8 X60Qx_35 = blockedByPolicy_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1684562942u, .more_0 = (&strlit_0_I741435630578446865_hos1fpv3m1)}
  , ((NI32)2), p_3);
  if (X60Qx_35){
    nimStrDestroy(X60Qtmp_15);
    return -1;}
  Path_0_pat4k2dls X60Qtmp_16 = path_0_pat4k2dls(p_3);
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = setCurrentDir_0_dir38pj6l(X60Qtmp_16);
  if (X60QcanRaise_0){
    eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_16);
    goto X60Qexlab_1;}
  setHostErrno_0_hos1fpv3m1(0);
  result_8 = 0;
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_16);
  if (NIM_FALSE){
    X60Qexlab_1: ;
    setHostErrno_0_hos1fpv3m1(((NI32)2));
    result_8 = -1;}
  string_0_sysvq0asl X60Qtmp_17 = portPath_0_jou8favxh1(p_3);
  jLeafDone_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1684562942u, .more_0 = (&strlit_0_I2723496349315214549_hos1fpv3m1)}
  , X60Qtmp_17, result_8);
  nimStrDestroy(X60Qtmp_17);
  nimStrDestroy(X60Qtmp_15);
  return result_8;
  nimStrDestroy(X60Qtmp_17);
  nimStrDestroy(X60Qtmp_15);
  return result_8;}
NI32 hostSystem_0_hos1fpv3m1(string_0_sysvq0asl cmd_0){
  NI32 result_9;
  NI32 jrc_4 = 0;
  NB8 X60Qx_36 = jLeaf_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I4050815769175754417_hos1fpv3m1)}
  , cmd_0, (&jrc_4));
  if (X60Qx_36){
    return jrc_4;}
  NB8 X60Qx_37 = blockedByPolicy_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I16745981998740488036_hos1fpv3m1)}
  , ((NI32)8), (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  if (X60Qx_37){
    return -1;}
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS32_hos1fpv3m1 X60QcanRaise_0 = execCmd_0_ospa68oph1(cmd_0);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_2;}
  result_9 = X60QcanRaise_0.fld_1;
  setHostErrno_0_hos1fpv3m1(0);
  if (NIM_FALSE){
    X60Qexlab_2: ;
    setHostErrno_0_hos1fpv3m1(((NI32)22));
    result_9 = -1;}
  jLeafDone_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I4050815769175754417_hos1fpv3m1)}
  , cmd_0, result_9);
  return result_9;}
NI32 hostFdSize_0_hos1fpv3m1(FILE* f_0){
  NI32 result_10;
  NI64 n_0 = ((NI64)0);
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 pos_0 = getFilePos_0_syn1lfpjv(f_0);
  if (pos_0.fld_0){
    goto X60Qexlab_3;}
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = setFilePos_0_syn1lfpjv(f_0, ((NI64)0), 2);
  if (X60QcanRaise_0){
    goto X60Qexlab_3;}
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 X60QcanRaise_1 = getFilePos_0_syn1lfpjv(f_0);
  if (X60QcanRaise_1.fld_0){
    goto X60Qexlab_3;}
  n_0 = X60QcanRaise_1.fld_1;
  ErrorCode_0_sysvq0asl X60QcanRaise_2 = setFilePos_0_syn1lfpjv(f_0, pos_0.fld_1, 0);
  if (X60QcanRaise_2){
    goto X60Qexlab_3;}
  if (NIM_FALSE){
    X60Qexlab_3: ;
    n_0 = ((NI64)-1);}
  result_10 = ((NI32)n_0);
  return result_10;}
void hostClockGettime_0_hos1fpv3m1(NI32 clockId_0, NI32* sec_0, NI32* nsec_0){
  NB8 X60Qx_38 = journalReplaying_0_jou8favxh1();
  if (X60Qx_38){
    string_0_sysvq0asl X60Qtmp_18 = dollarQ_2_sysvq0asl(clockId_0);
    seq_0_Ixdx2fh1_ast8ri79k a_4 = jServe_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I15393414479670481275_hos1fpv3m1)}
    , X60Qtmp_18);
    string_0_sysvq0asl X60Qtmp_19 = jField_0_jou8favxh1(a_4, 0);
    NI32 X60Qx_39 = jInt_0_jou8favxh1(X60Qtmp_19);
    (*sec_0) = X60Qx_39;
    string_0_sysvq0asl X60Qtmp_20 = jField_0_jou8favxh1(a_4, 1);
    NI32 X60Qx_40 = jInt_0_jou8favxh1(X60Qtmp_20);
    (*nsec_0) = X60Qx_40;
    nimStrDestroy(X60Qtmp_20);
    nimStrDestroy(X60Qtmp_19);
    eQdestroy_1_Ivioh0a_ast8ri79k(a_4);
    nimStrDestroy(X60Qtmp_18);
    return;
    nimStrDestroy(X60Qtmp_20);
    nimStrDestroy(X60Qtmp_19);
    eQdestroy_1_Ivioh0a_ast8ri79k(a_4);
    nimStrDestroy(X60Qtmp_18);}
  if (clockId_0 == 0){
    Time_0_timsagyye1 t_0 = getTime_0_timsagyye1();
    NI64 X60Qx_41 = seconds_0_timsagyye1(t_0);
    (*sec_0) = ((NI32)X60Qx_41);
    NI32 X60Qx_42 = nanosecond_0_timsagyye1(t_0);
    (*nsec_0) = ((NI32)X60Qx_42);}
  else {
    MonoTime_0_mon82i3ln X60Qx_43 = getMonoTime_0_mon82i3ln();
    NI64 ticks_0 = ticks_0_mon82i3ln(X60Qx_43);
    (*sec_0) = ((NI32)((NI64)(ticks_0 / ((NI64)1000000000))));
    (*nsec_0) = ((NI32)((NI64)(ticks_0 % ((NI64)1000000000))));}
  NB8 X60Qx_44 = journalRecording_0_jou8favxh1();
  if (X60Qx_44){
    string_0_sysvq0asl X60Qtmp_21 = dollarQ_2_sysvq0asl(clockId_0);
    string_0_sysvq0asl X60Qtmp_23 = dollarQ_2_sysvq0asl((*sec_0));
    string_0_sysvq0asl X60Qtmp_24 = dollarQ_2_sysvq0asl((*nsec_0));
    seq_0_Ixdx2fh1_ast8ri79k X60Qtmp_22 = atQ_0_Ibamkxv1_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS2_hos1fpv3m1){
      .a = {
        X60Qtmp_23, X60Qtmp_24}}
    );
    jRecord_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I15393414479670481275_hos1fpv3m1)}
    , X60Qtmp_21, X60Qtmp_22);
    eQdestroy_1_Ivioh0a_ast8ri79k(X60Qtmp_22);
    nimStrDestroy(X60Qtmp_24);
    nimStrDestroy(X60Qtmp_23);
    nimStrDestroy(X60Qtmp_21);}}
NI32 hostGetPid_0_hos1fpv3m1(void){
  NI32 result_11;
  NI32 jrc_5 = 0;
  NB8 X60Qx_45 = jLeaf_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I14102593084845164639_hos1fpv3m1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  , (&jrc_5));
  if (X60Qx_45){
    return jrc_5;}
  int X60Qx_46 = getpid();
  result_11 = ((NI32)X60Qx_46);
  setHostErrno_0_hos1fpv3m1(0);
  jLeafDone_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I14102593084845164639_hos1fpv3m1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  , result_11);
  return result_11;}
NI32 hostFileSize_0_hos1fpv3m1(string_0_sysvq0asl p_4){
  NI32 result_12;
  NI32 jrc_6 = 0;
  string_0_sysvq0asl X60Qtmp_25 = portPath_0_jou8favxh1(p_4);
  NB8 X60Qx_47 = jLeaf_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1769170686u, .more_0 = (&strlit_0_I4932132024348173802_hos1fpv3m1)}
  , X60Qtmp_25, (&jrc_6));
  if (X60Qx_47){
    nimStrDestroy(X60Qtmp_25);
    return jrc_6;}
  FILE* f_1;
  NB8 X60Qx_48 = open_0_syn1lfpjv((&f_1), p_4, 0, -1);
  if ((!X60Qx_48)){
    setHostErrno_0_hos1fpv3m1(((NI32)2));
    string_0_sysvq0asl X60Qtmp_26 = portPath_0_jou8favxh1(p_4);
    jLeafDone_0_hos1fpv3m1((string_0_sysvq0asl){
      .bytes_0 = 1769170686u, .more_0 = (&strlit_0_I4932132024348173802_hos1fpv3m1)}
    , X60Qtmp_26, -1);
    nimStrDestroy(X60Qtmp_26);
    nimStrDestroy(X60Qtmp_25);
    return -1;
    nimStrDestroy(X60Qtmp_26);}
  NI64 n_1 = ((NI64)0);
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = setFilePos_0_syn1lfpjv(f_1, ((NI64)0), 2);
  if (X60QcanRaise_0){
    goto X60Qexlab_4;}
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 X60QcanRaise_1 = getFilePos_0_syn1lfpjv(f_1);
  if (X60QcanRaise_1.fld_0){
    goto X60Qexlab_4;}
  n_1 = X60QcanRaise_1.fld_1;
  if (NIM_FALSE){
    X60Qexlab_4: ;
    n_1 = ((NI64)-1);}
  close_0_syn1lfpjv(f_1);
  setHostErrno_0_hos1fpv3m1(0);
  result_12 = ((NI32)n_1);
  string_0_sysvq0asl X60Qtmp_27 = portPath_0_jou8favxh1(p_4);
  jLeafDone_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1769170686u, .more_0 = (&strlit_0_I4932132024348173802_hos1fpv3m1)}
  , X60Qtmp_27, result_12);
  nimStrDestroy(X60Qtmp_27);
  nimStrDestroy(X60Qtmp_25);
  return result_12;
  nimStrDestroy(X60Qtmp_27);
  nimStrDestroy(X60Qtmp_25);
  return result_12;}
NI32 installSnapshot_0_hos1fpv3m1(DirSnapshot_0_hos1fpv3m1 snap_0){
  NI32 result_13;
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_49 = len_3_Iqiy1o3_hos1fpv3m1(gDirs_0_hos1fpv3m1);
      if (i_0 < X60Qx_49){
        DirSnapshot_0_hos1fpv3m1* X60Qx_50 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_0);
        if ((!(*X60Qx_50).live_0)){
          DirSnapshot_0_hos1fpv3m1 X60Qx_51 = eQdupQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(snap_0);
          putQ_7_Izkv0l3_hos1fpv3m1((&gDirs_0_hos1fpv3m1), i_0, X60Qx_51);
          result_13 = ((NI32)(i_0 + 1));
          return result_13;}
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  DirSnapshot_0_hos1fpv3m1 X60Qx_52 = eQdupQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(snap_0);
  add_0_Iek2urt_hos1fpv3m1((&gDirs_0_hos1fpv3m1), X60Qx_52);
  NI32 X60Qx_53 = len_3_Iqiy1o3_hos1fpv3m1(gDirs_0_hos1fpv3m1);
  result_13 = X60Qx_53;
  return result_13;}
NI32 hostOpenDir_0_hos1fpv3m1(string_0_sysvq0asl p_5){
  NI32 result_14;
  NB8 X60Qx_54 = journalReplaying_0_jou8favxh1();
  if (X60Qx_54){
    string_0_sysvq0asl X60Qtmp_28 = portPath_0_jou8favxh1(p_5);
    seq_0_Ixdx2fh1_ast8ri79k a_5 = jServe_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I4718597432102153922_hos1fpv3m1)}
    , X60Qtmp_28);
    string_0_sysvq0asl X60Qtmp_29 = jField_0_jou8favxh1(a_5, 0);
    NI32 X60Qx_55 = jInt_0_jou8favxh1(X60Qtmp_29);
    if (X60Qx_55 <= 0){
      setHostErrno_0_hos1fpv3m1(((NI32)2));
      nimStrDestroy(X60Qtmp_29);
      eQdestroy_1_Ivioh0a_ast8ri79k(a_5);
      nimStrDestroy(X60Qtmp_28);
      return 0;}
    seq_0_Ixdx2fh1_ast8ri79k X60Qx_56 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
    seq_0_Ift2sne_chu5m1rja1 X60Qx_57 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
    DirSnapshot_0_hos1fpv3m1 rsnap_0 = (DirSnapshot_0_hos1fpv3m1){
      .names_0 = X60Qx_56, .kinds_0 = X60Qx_57, .pos_0 = 0, .live_0 = NIM_TRUE}
    ;
    NI32 i_3 = 1;
    {
      while (NIM_TRUE){
        NI32 X60Qx_58 = len_3_Ixq6taz_comaa5xpt1(a_5);
        if (((NI32)(i_3 + 1)) < X60Qx_58){
          string_0_sysvq0asl* X60Qx_59 = getQ_7_Ir6d0tw_ast8ri79k(a_5, i_3);
          string_0_sysvq0asl X60Qx_60 = nimStrDup((*X60Qx_59));
          add_0_Ig6072n_ast8ri79k((&rsnap_0.names_0), X60Qx_60);
          string_0_sysvq0asl* X60Qx_61 = getQ_7_Ir6d0tw_ast8ri79k(a_5, ((NI32)(i_3 + 1)));
          NI32 X60Qx_62 = jInt_0_jou8favxh1((*X60Qx_61));
          add_0_I8kd4i4_comaa5xpt1((&rsnap_0.kinds_0), X60Qx_62);
          i_3 = ((NI32)(i_3 + 2));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    setHostErrno_0_hos1fpv3m1(0);
    NI32 X60Qx_63 = installSnapshot_0_hos1fpv3m1(rsnap_0);
    result_14 = X60Qx_63;
    eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(rsnap_0);
    nimStrDestroy(X60Qtmp_29);
    eQdestroy_1_Ivioh0a_ast8ri79k(a_5);
    nimStrDestroy(X60Qtmp_28);
    return result_14;
    eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(rsnap_0);
    nimStrDestroy(X60Qtmp_29);
    eQdestroy_1_Ivioh0a_ast8ri79k(a_5);
    nimStrDestroy(X60Qtmp_28);}
  NB8 X60Qx_64 = blockedByPolicy_0_hos1fpv3m1((string_0_sysvq0asl){
    .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I14686529387667009019_hos1fpv3m1)}
  , ((NI32)1), p_5);
  if (X60Qx_64){
    return 0;}
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_65 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_66 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  DirSnapshot_0_hos1fpv3m1 snap_1 = (DirSnapshot_0_hos1fpv3m1){
    .names_0 = X60Qx_65, .kinds_0 = X60Qx_66, .pos_0 = 0, .live_0 = NIM_TRUE}
  ;
  {
    Path_0_pat4k2dls X60Qlf_0 = path_0_pat4k2dls(p_5);
    NB8 X60Qlf_1 = NIM_TRUE;
    NB8 X60Qlf_2 = NIM_TRUE;
    Path_0_pat4k2dls X60Qx_67 = eQdupQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qlf_0);
    DirWalker_0_dir38pj6l X60Qlf_3 = tryOpenDir_0_dir38pj6l(X60Qx_67);
    NB8 X60Qx_68;
    if (X60Qlf_2){
      X60Qx_68 = (!(X60Qlf_3.status_0 == 0));}
    else {
      X60Qx_68 = NIM_FALSE;}
    if (X60Qx_68){
      eQdestroyQ_SX44irX57alker0dir38pj6l_0_dir38pj6l(X60Qlf_3);
      eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qlf_0);
      goto X60Qexlab_5;}
    DirEntry_0_dir38pj6l X60Qlf_4 = (DirEntry_0_dir38pj6l){
      .kind_0 = 0, .path_0 = (Path_0_pat4k2dls){
        .data_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}}}
    ;
    {
      while (X60Qlf_3.status_0 == 0){
        NB8 X60Qx_69 = tryNextDir_0_dir38pj6l((&X60Qlf_3), (&X60Qlf_4));
        if (X60Qx_69){
          Path_0_pat4k2dls X60Qx_5;
          eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&X60Qx_5));
          if (X60Qlf_1){
            eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qx_5);
            Path_0_pat4k2dls X60Qx_70 = eQdupQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qlf_4.path_0);
            X60Qx_5 = X60Qx_70;}
          else {
            eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qx_5);
            Path_0_pat4k2dls X60Qx_71 = slashQ_0_pat4k2dls(X60Qlf_0, X60Qlf_4.path_0);
            X60Qx_5 = X60Qx_71;}
          Path_0_pat4k2dls X60Qlf_5 = X60Qx_5;
          eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&X60Qx_5));
          {
            Path_0_pat4k2dls X60Qtmp_30 = X60Qlf_5;
            eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&X60Qlf_5));
            X60Qt_0_IAtupleSX50athX43omponent0osc4bsu0d1SX50ath0pat4k2dls_hos1fpv3m1 X60Qii_3 = (X60Qt_0_IAtupleSX50athX43omponent0osc4bsu0d1SX50ath0pat4k2dls_hos1fpv3m1){
              .fld_0 = X60Qlf_4.kind_0, .fld_1 = X60Qtmp_30}
            ;
            PathComponent_0_osc4bsu0d1 kind_3 = X60Qii_3.fld_0;
            Path_0_pat4k2dls entry_0 = X60Qii_3.fld_1;
            eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&X60Qii_3.fld_1));
            string_0_sysvq0asl X60Qx_72 = dollarQ_0_pat4k2dls(entry_0);
            add_0_Ig6072n_ast8ri79k((&snap_1.names_0), X60Qx_72);
            add_0_I8kd4i4_comaa5xpt1((&snap_1.kinds_0), ((NI32)kind_3));
            eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(entry_0);
            eQdestroyQ_AtupleSX50athX43omponent0osc4bsu0d1SX50ath0pat4k2dls_0_hos1fpv3m1(X60Qii_3);}
          eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qlf_5);
          eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qx_5);}
        else {
          goto whileStmtLabel_2;}}}
    whileStmtLabel_2: ;
    eQdestroyQ_SX44irX45ntry0dir38pj6l_0_dir38pj6l(X60Qlf_4);
    ErrorCode_0_sysvq0asl X60Qlf_6 = tryCloseDir_0_dir38pj6l((&X60Qlf_3));
    NB8 X60Qx_73;
    if (X60Qlf_2){
      X60Qx_73 = (!(X60Qlf_6 == 0));}
    else {
      X60Qx_73 = NIM_FALSE;}
    if (X60Qx_73){
      eQdestroyQ_SX44irX57alker0dir38pj6l_0_dir38pj6l(X60Qlf_3);
      eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qlf_0);
      goto X60Qexlab_5;}
    eQdestroyQ_SX44irX57alker0dir38pj6l_0_dir38pj6l(X60Qlf_3);
    eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qlf_0);}
  forStmtLabel_1: ;
  if (NIM_FALSE){
    X60Qexlab_5: ;
    setHostErrno_0_hos1fpv3m1(((NI32)2));
    NB8 X60Qx_74 = journalRecording_0_jou8favxh1();
    if (X60Qx_74){
      string_0_sysvq0asl X60Qtmp_31 = portPath_0_jou8favxh1(p_5);
      seq_0_Ixdx2fh1_ast8ri79k X60Qtmp_32 = atQ_0_I508dwj_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS1_hos1fpv3m1){
        .a = {
          (string_0_sysvq0asl){
            .bytes_0 = 12289u, .more_0 = NIM_NIL}}}
      );
      jRecord_0_jou8favxh1((string_0_sysvq0asl){
        .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I4718597432102153922_hos1fpv3m1)}
      , X60Qtmp_31, X60Qtmp_32);
      eQdestroy_1_Ivioh0a_ast8ri79k(X60Qtmp_32);
      nimStrDestroy(X60Qtmp_31);}
    eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(snap_1);
    return 0;}
  setHostErrno_0_hos1fpv3m1(0);
  seq_0_Ixdx2fh1_ast8ri79k fs_0 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  NB8 X60Qx_75 = journalRecording_0_jou8favxh1();
  if (X60Qx_75){
    NI32 k_0 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_76 = len_3_Ixq6taz_comaa5xpt1(snap_1.names_0);
        if (k_0 < X60Qx_76){
          string_0_sysvq0asl* X60Qx_77 = getQ_7_Ir6d0tw_ast8ri79k(snap_1.names_0, k_0);
          string_0_sysvq0asl X60Qx_78 = nimStrDup((*X60Qx_77));
          add_0_Ig6072n_ast8ri79k((&fs_0), X60Qx_78);
          NI32* X60Qx_79 = getQ_7_Ir8kccm_comaa5xpt1(snap_1.kinds_0, k_0);
          string_0_sysvq0asl X60Qx_80 = dollarQ_2_sysvq0asl((*X60Qx_79));
          add_0_Ig6072n_ast8ri79k((&fs_0), X60Qx_80);
          inc_1_I6wjjge_aow2h993l1((&k_0));}
        else {
          break;}}}
    whileStmtLabel_4: ;}
  NI32 X60Qx_81 = installSnapshot_0_hos1fpv3m1(snap_1);
  result_14 = X60Qx_81;
  NB8 X60Qx_82 = journalRecording_0_jou8favxh1();
  if (X60Qx_82){
    seq_0_Ixdx2fh1_ast8ri79k fs2_0 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
    string_0_sysvq0asl X60Qx_83 = dollarQ_2_sysvq0asl(result_14);
    add_0_Ig6072n_ast8ri79k((&fs2_0), X60Qx_83);
    NI32 k_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_84 = len_3_Ixq6taz_comaa5xpt1(fs_0);
        if (k_1 < X60Qx_84){
          string_0_sysvq0asl* X60Qx_85 = getQ_7_Ir6d0tw_ast8ri79k(fs_0, k_1);
          string_0_sysvq0asl X60Qx_86 = nimStrDup((*X60Qx_85));
          add_0_Ig6072n_ast8ri79k((&fs2_0), X60Qx_86);
          inc_1_I6wjjge_aow2h993l1((&k_1));}
        else {
          break;}}}
    whileStmtLabel_5: ;
    string_0_sysvq0asl X60Qtmp_33 = portPath_0_jou8favxh1(p_5);
    jRecord_0_jou8favxh1((string_0_sysvq0asl){
      .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I4718597432102153922_hos1fpv3m1)}
    , X60Qtmp_33, fs2_0);
    nimStrDestroy(X60Qtmp_33);
    eQdestroy_1_Ivioh0a_ast8ri79k(fs2_0);}
  eQdestroy_1_Ivioh0a_ast8ri79k(fs_0);
  eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(snap_1);
  return result_14;
  eQdestroy_1_Ivioh0a_ast8ri79k(fs_0);
  eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(snap_1);
  return result_14;}
NB8 hostNextDir_0_hos1fpv3m1(NI32 handle_0, string_0_sysvq0asl* name_1, NI32* kind_2){
  NB8 result_15;
  nimStrDestroy((*name_1));
  (*name_1) = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  (*kind_2) = 0;
  NI32 i_6 = ((NI32)(handle_0 - 1));
  NB8 X60Qx_87;
  NB8 X60Qx_88;
  if (i_6 < 0){
    X60Qx_88 = NIM_TRUE;}
  else {
    X60Qx_88 = (gDirs_0_hos1fpv3m1.len_0 <= i_6);}
  if (X60Qx_88){
    X60Qx_87 = NIM_TRUE;}
  else {
    DirSnapshot_0_hos1fpv3m1* X60Qx_89 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_6);
    X60Qx_87 = (!(*X60Qx_89).live_0);}
  if (X60Qx_87){
    return NIM_FALSE;}
  DirSnapshot_0_hos1fpv3m1* X60Qx_90 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_6);
  DirSnapshot_0_hos1fpv3m1* X60Qx_91 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_6);
  if ((*X60Qx_90).names_0.len_0 <= (*X60Qx_91).pos_0){
    setHostErrno_0_hos1fpv3m1(0);
    return NIM_FALSE;}
  string_0_sysvq0asl X60Qlhs_34 = (*name_1);
  DirSnapshot_0_hos1fpv3m1* X60Qx_92 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_6);
  DirSnapshot_0_hos1fpv3m1* X60Qx_93 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_6);
  string_0_sysvq0asl* X60Qx_94 = getQ_7_Ir6d0tw_ast8ri79k((*X60Qx_92).names_0, (*X60Qx_93).pos_0);
  string_0_sysvq0asl X60Qx_95 = nimStrDup((*X60Qx_94));
  (*name_1) = X60Qx_95;
  nimStrDestroy(X60Qlhs_34);
  DirSnapshot_0_hos1fpv3m1* X60Qx_96 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_6);
  DirSnapshot_0_hos1fpv3m1* X60Qx_97 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_6);
  NI32* X60Qx_98 = getQ_7_Ir8kccm_comaa5xpt1((*X60Qx_96).kinds_0, (*X60Qx_97).pos_0);
  (*kind_2) = (*X60Qx_98);
  DirSnapshot_0_hos1fpv3m1* X60Qx_99 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_6);
  inc_1_I6wjjge_aow2h993l1((&(*X60Qx_99).pos_0));
  result_15 = NIM_TRUE;
  return result_15;}
NI32 hostCloseDir_0_hos1fpv3m1(NI32 handle_1){
  NI32 result_16;
  NI32 i_7 = ((NI32)(handle_1 - 1));
  NB8 X60Qx_100;
  NB8 X60Qx_101;
  if (i_7 < 0){
    X60Qx_101 = NIM_TRUE;}
  else {
    X60Qx_101 = (gDirs_0_hos1fpv3m1.len_0 <= i_7);}
  if (X60Qx_101){
    X60Qx_100 = NIM_TRUE;}
  else {
    DirSnapshot_0_hos1fpv3m1* X60Qx_102 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_7);
    X60Qx_100 = (!(*X60Qx_102).live_0);}
  if (X60Qx_100){
    setHostErrno_0_hos1fpv3m1(((NI32)9));
    return -1;}
  DirSnapshot_0_hos1fpv3m1* X60Qx_103 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_7);
  seq_0_Ixdx2fh1_ast8ri79k* X60Qlhs_35 = (&(*X60Qx_103).names_0);
  seq_0_Ixdx2fh1_ast8ri79k X60Qlhs_36 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  eQdestroy_1_Ivioh0a_ast8ri79k((*X60Qlhs_35));
  (*X60Qlhs_35) = X60Qlhs_36;
  DirSnapshot_0_hos1fpv3m1* X60Qx_104 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_7);
  seq_0_Ift2sne_chu5m1rja1* X60Qlhs_37 = (&(*X60Qx_104).kinds_0);
  seq_0_Ift2sne_chu5m1rja1 X60Qlhs_38 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1((*X60Qlhs_37));
  (*X60Qlhs_37) = X60Qlhs_38;
  DirSnapshot_0_hos1fpv3m1* X60Qx_105 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_7);
  (*X60Qx_105).pos_0 = 0;
  DirSnapshot_0_hos1fpv3m1* X60Qx_106 = getQ_7_Irdozxf_hos1fpv3m1(gDirs_0_hos1fpv3m1, i_7);
  (*X60Qx_106).live_0 = NIM_FALSE;
  setHostErrno_0_hos1fpv3m1(0);
  result_16 = 0;
  return result_16;}
seq_0_Ixdx2fh1_ast8ri79k atQ_0_Ibamkxv1_hos1fpv3m1(X60Qt_0_IAarraySstring0sysvq0aslS2_hos1fpv3m1 a_6){
  seq_0_Ixdx2fh1_ast8ri79k result_17;
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_107 = newSeqUninit_0_Im3cqd9_ast8ri79k(((NI32)(((NI32)(((NI32)((NI32)1)) - ((NI32)((NI32)0)))) + 1)));
  result_17 = X60Qx_107;
  if ((!(result_17.data_0 == NIM_NIL))){
    NI32 i_8 = 0;
    {
      while (i_8 < result_17.len_0){
        NI32 X60Qx_108 = nimIcheckB(i_8, 1);
        string_0_sysvq0asl X60Qx_109 = nimStrDup(a_6.a[X60Qx_108]);
        result_17.data_0[i_8] = X60Qx_109;
        inc_1_I6wjjge_aow2h993l1((&i_8));}}
    whileStmtLabel_0: ;}
  return result_17;}
seq_0_Ixdx2fh1_ast8ri79k atQ_0_I508dwj_hos1fpv3m1(X60Qt_0_IAarraySstring0sysvq0aslS1_hos1fpv3m1 a_7){
  seq_0_Ixdx2fh1_ast8ri79k result_18;
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_110 = newSeqUninit_0_Im3cqd9_ast8ri79k(((NI32)(((NI32)(((NI32)((NI32)0)) - ((NI32)((NI32)0)))) + 1)));
  result_18 = X60Qx_110;
  if ((!(result_18.data_0 == NIM_NIL))){
    NI32 i_9 = 0;
    {
      while (i_9 < result_18.len_0){
        NI32 X60Qx_111 = nimIcheckB(i_9, 0);
        string_0_sysvq0asl X60Qx_112 = nimStrDup(a_7.a[X60Qx_111]);
        result_18.data_0[i_9] = X60Qx_112;
        inc_1_I6wjjge_aow2h993l1((&i_9));}}
    whileStmtLabel_0: ;}
  return result_18;}
static inline seq_0_Ikorkmv_hos1fpv3m1 newSeqUninit_0_Ifz9g0d1_hos1fpv3m1(NI32 size_3){
  seq_0_Ikorkmv_hos1fpv3m1 result_19;
  if (size_3 == 0){
    result_19 = (seq_0_Ikorkmv_hos1fpv3m1){
      .len_0 = size_3, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_I08ylpd_hos1fpv3m1(size_3);
    void* X60Qx_113 = alloc_1_sysvq0asl(memSize_0);
    result_19 = (seq_0_Ikorkmv_hos1fpv3m1){
      .len_0 = size_3, .data_0 = ((DirSnapshot_0_hos1fpv3m1*)X60Qx_113)}
    ;
    if ((!(result_19.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_114 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_19.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_19;}
static inline NI32 len_3_Iqiy1o3_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1 s_9){
  NI32 result_20;
  result_20 = s_9.len_0;
  return result_20;}
static inline DirSnapshot_0_hos1fpv3m1* getQ_7_Irdozxf_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1 s_10, NI32 i_10){
  NB8 X60Qx_115;
  if (i_10 < s_10.len_0){
    X60Qx_115 = (0 <= i_10);}
  else {
    X60Qx_115 = NIM_FALSE;}
  if ((!X60Qx_115)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  DirSnapshot_0_hos1fpv3m1* result_21;
  result_21 = (&s_10.data_0[i_10]);
  return result_21;}
static inline void putQ_7_Izkv0l3_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1* s_11, NI32 i_11, DirSnapshot_0_hos1fpv3m1 elem_4){
  NB8 X60Qx_116;
  if (i_11 < (*s_11).len_0){
    X60Qx_116 = (0 <= i_11);}
  else {
    X60Qx_116 = NIM_FALSE;}
  if ((!X60Qx_116)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  DirSnapshot_0_hos1fpv3m1* X60Qlhs_39 = (&(*s_11).data_0[i_11]);
  DirSnapshot_0_hos1fpv3m1 X60Qlhs_40 = elem_4;
  eQwasmovedQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1((&elem_4));
  eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1((*X60Qlhs_39));
  (*X60Qlhs_39) = X60Qlhs_40;
  eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(elem_4);}
static inline void add_0_Iek2urt_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1* s_12, DirSnapshot_0_hos1fpv3m1 elem_5){
  NI32 L_0 = (*s_12).len_0;
  NI32 X60Qx_117 = capInBytes_0_Iuy29xh_hos1fpv3m1((*s_12));
  if (X60Qx_117 < ((NI32)(((NI32)(L_0 * sizeof(DirSnapshot_0_hos1fpv3m1))) + sizeof(DirSnapshot_0_hos1fpv3m1)))){
    NB8 X60Qx_118 = resize_0_Iyfix491_hos1fpv3m1(s_12, 1);
    if ((!X60Qx_118)){
      eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(elem_5);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_12).len_0));
  (*s_12).data_0[L_0] = elem_5;}
static inline NI32 memSizeInBytes_0_I08ylpd_hos1fpv3m1(NI32 size_9){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_27;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_9, sizeof(DirSnapshot_0_hos1fpv3m1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_27 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_27 = ((NI32)2147483647);}
  return result_27;}
static inline NI32 capInBytes_0_Iuy29xh_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1 s_21){
  NI32 result_28;
  NI32 X60Qx_6;
  if ((!(s_21.data_0 == NIM_NIL))){
    NI32 X60Qx_129 = allocatedSize_0_sysvq0asl(((void*)((void*)s_21.data_0)));
    X60Qx_6 = X60Qx_129;}
  else {
    X60Qx_6 = 0;}
  result_28 = X60Qx_6;
  return result_28;}
NB8 resize_0_Iyfix491_hos1fpv3m1(seq_0_Ikorkmv_hos1fpv3m1* dest_3, NI32 addedElements_3){
  NB8 result_29;
  NI32 X60Qx_130 = capInBytes_0_Iuy29xh_hos1fpv3m1((*dest_3));
  NI32 oldCap_0 = ((NI32)(X60Qx_130 / sizeof(DirSnapshot_0_hos1fpv3m1)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_3);
  NI32 memSize_3 = memSizeInBytes_0_I08ylpd_hos1fpv3m1(newCap_0);
  void* X60Qx_131 = realloc_1_sysvq0asl(((void*)((void*)(*dest_3).data_0)), memSize_3);
  (*dest_3).data_0 = ((DirSnapshot_0_hos1fpv3m1*)X60Qx_131);
  if ((*dest_3).data_0 == NIM_NIL){
    (*dest_3).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_3);
    result_29 = NIM_FALSE;}
  else {
    result_29 = NIM_TRUE;}
  return result_29;}
void eQdestroyQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(DirSnapshot_0_hos1fpv3m1 dest_0){
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(dest_0.kinds_0);
  eQdestroy_1_Ivioh0a_ast8ri79k(dest_0.names_0);}
void eQwasmovedQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(DirSnapshot_0_hos1fpv3m1* dest_0){
  eQwasMoved_1_I5vdnla_ast8ri79k((&(*dest_0).names_0));
  eQwasMoved_1_Ix88qzs1_chu5m1rja1((&(*dest_0).kinds_0));}
DirSnapshot_0_hos1fpv3m1 eQdupQ_SX44irX53napshot0hos1fpv3m1_0_hos1fpv3m1(DirSnapshot_0_hos1fpv3m1 src_0){
  DirSnapshot_0_hos1fpv3m1 dest_0;
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_154 = eQdup_1_Imq0s4c_ast8ri79k(src_0.names_0);
  dest_0.names_0 = X60Qx_154;
  seq_0_Ift2sne_chu5m1rja1 X60Qx_155 = eQdup_1_Iplow11_chu5m1rja1(src_0.kinds_0);
  dest_0.kinds_0 = X60Qx_155;
  dest_0.pos_0 = src_0.pos_0;
  dest_0.live_0 = src_0.live_0;
  return dest_0;}
void eQdestroyQ_AtupleSX50athX43omponent0osc4bsu0d1SX50ath0pat4k2dls_0_hos1fpv3m1(X60Qt_0_IAtupleSX50athX43omponent0osc4bsu0d1SX50ath0pat4k2dls_hos1fpv3m1 dest_0){
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(dest_0.fld_1);}
void X60Qini_0_hos1fpv3m1(void){
  if (X60QiniGuard_0_hos1fpv3m1){
    return;}
  X60QiniGuard_0_hos1fpv3m1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_dir38pj6l();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_pat4k2dls();
  X60Qini_0_ossk30t39();
  X60Qini_0_ospa68oph1();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_timsagyye1();
  X60Qini_0_mon82i3ln();
  X60Qini_0_iop7yt73v();
  X60Qini_0_jou8favxh1();
  X60Qini_0_osezuyu63();
  gDirs_0_hos1fpv3m1 = newSeqUninit_0_Ifz9g0d1_hos1fpv3m1(0);}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline Path_0_pat4k2dls path_0_pat4k2dls(string_0_sysvq0asl s_0){
  Path_0_pat4k2dls result_0;
  eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&result_0));
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(result_0);
  string_0_sysvq0asl X60Qx_6 = nimStrDup(s_0);
  result_0 = (Path_0_pat4k2dls){
    .data_0 = X60Qx_6}
  ;
  return result_0;}
static inline string_0_sysvq0asl dollarQ_0_pat4k2dls(Path_0_pat4k2dls x_0){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  nimStrDestroy(result_1);
  string_0_sysvq0asl X60Qx_7 = nimStrDup(x_0.data_0);
  result_1 = X60Qx_7;
  return result_1;}
static inline NI64 seconds_0_timsagyye1(Time_0_timsagyye1 t_1){
  NI64 result_5;
  result_5 = t_1.seconds_0;
  return result_5;}
static inline NI32 nanosecond_0_timsagyye1(Time_0_timsagyye1 t_2){
  NI32 result_6;
  result_6 = t_2.nanosecond_0;
  return result_6;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline seq_0_Ixdx2fh1_ast8ri79k newSeqUninit_0_Im3cqd9_ast8ri79k(NI32 size_20){
  seq_0_Ixdx2fh1_ast8ri79k result_33;
  if (size_20 == 0){
    result_33 = (seq_0_Ixdx2fh1_ast8ri79k){
      .len_0 = size_20, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_11 = memSizeInBytes_0_I7me00i_ast8ri79k(size_20);
    void* X60Qx_113 = alloc_1_sysvq0asl(memSize_11);
    result_33 = (seq_0_Ixdx2fh1_ast8ri79k){
      .len_0 = size_20, .data_0 = ((string_0_sysvq0asl*)X60Qx_113)}
    ;
    if ((!(result_33.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_114 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_33.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_11);}}
  return result_33;}
static inline seq_0_Ift2sne_chu5m1rja1 newSeqUninit_0_Iggfvwp_chu5m1rja1(NI32 size_32){
  seq_0_Ift2sne_chu5m1rja1 result_21;
  if (size_32 == 0){
    result_21 = (seq_0_Ift2sne_chu5m1rja1){
      .len_0 = size_32, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_16 = memSizeInBytes_0_Inv7kg3_chu5m1rja1(size_32);
    void* X60Qx_88 = alloc_1_sysvq0asl(memSize_16);
    result_21 = (seq_0_Ift2sne_chu5m1rja1){
      .len_0 = size_32, .data_0 = ((NI32*)X60Qx_88)}
    ;
    if ((!(result_21.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_89 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_21.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_16);}}
  return result_21;}
static inline NI32 len_3_Ixq6taz_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_130){
  NI32 result_70;
  result_70 = s_130.len_0;
  return result_70;}
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5){
  NB8 X60Qx_52;
  if (i_5 < s_8.len_0){
    X60Qx_52 = (0 <= i_5);}
  else {
    X60Qx_52 = NIM_FALSE;}
  if ((!X60Qx_52)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  string_0_sysvq0asl* result_9;
  result_9 = (&s_8.data_0[i_5]);
  return result_9;}
static inline void add_0_Ig6072n_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_20, string_0_sysvq0asl elem_3){
  NI32 L_0 = (*s_20).len_0;
  NI32 X60Qx_66 = capInBytes_0_Ih2sbn01_ast8ri79k((*s_20));
  if (X60Qx_66 < ((NI32)(((NI32)(L_0 * sizeof(string_0_sysvq0asl))) + sizeof(string_0_sysvq0asl)))){
    NB8 X60Qx_67 = resize_0_I4buliy_ast8ri79k(s_20, 1);
    if ((!X60Qx_67)){
      nimStrDestroy(elem_3);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_20).len_0));
  (*s_20).data_0[L_0] = elem_3;}
static inline void add_0_I8kd4i4_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_114, NI32 elem_27){
  NI32 L_2 = (*s_114).len_0;
  NI32 X60Qx_1797 = capInBytes_0_Iet286n_chu5m1rja1((*s_114));
  if (X60Qx_1797 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1798 = resize_0_I8l4tya_comaa5xpt1(s_114, 1);
    if ((!X60Qx_1798)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_114).len_0));
  (*s_114).data_0[L_2] = elem_27;}
static inline Path_0_pat4k2dls slashQ_0_pat4k2dls(Path_0_pat4k2dls head_0, Path_0_pat4k2dls tail_1){
  Path_0_pat4k2dls result_4;
  eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&result_4));
  string_0_sysvq0asl joined_0 = joinPath_0_ospaexnw61(head_0.data_0, tail_1.data_0);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(result_4);
  Path_0_pat4k2dls X60Qx_18 = path_0_pat4k2dls(joined_0);
  result_4 = X60Qx_18;
  nimStrDestroy(joined_0);
  return result_4;
  nimStrDestroy(joined_0);
  return result_4;}
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36){
  NB8 X60Qx_1793;
  if (i_36 < s_110.len_0){
    X60Qx_1793 = (0 <= i_36);}
  else {
    X60Qx_1793 = NIM_FALSE;}
  if ((!X60Qx_1793)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NI32* result_62;
  result_62 = (&s_110.data_0[i_36]);
  return result_62;}
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
static inline void eQwasMoved_1_I5vdnla_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_47){
  (*s_47).len_0 = 0;
  (*s_47).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_Ix88qzs1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1* s_35){
  (*s_35).len_0 = 0;
  (*s_35).data_0 = NIM_NIL;}
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
static inline NI32 memSizeInBytes_0_I7me00i_ast8ri79k(NI32 size_4){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_23;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_4, sizeof(string_0_sysvq0asl), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_23 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_23 = ((NI32)2147483647);}
  return result_23;}
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_23;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_33, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_23 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_23 = ((NI32)2147483647);}
  return result_23;}
static inline NI32 capInBytes_0_Ih2sbn01_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_28){
  NI32 result_18;
  NI32 X60Qx_0;
  if ((!(s_28.data_0 == NIM_NIL))){
    NI32 X60Qx_72 = allocatedSize_0_sysvq0asl(((void*)((void*)s_28.data_0)));
    X60Qx_0 = X60Qx_72;}
  else {
    X60Qx_0 = 0;}
  result_18 = X60Qx_0;
  return result_18;}
static inline NI32 capInBytes_0_Iet286n_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_72){
  NI32 result_22;
  NI32 X60Qx_2;
  if ((!(s_72.data_0 == NIM_NIL))){
    NI32 X60Qx_90 = allocatedSize_0_sysvq0asl(((void*)((void*)s_72.data_0)));
    X60Qx_2 = X60Qx_90;}
  else {
    X60Qx_2 = 0;}
  result_22 = X60Qx_2;
  return result_22;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
