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
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef NU8 FileWriteMode_0_vfsc9jn7;

#define AlwaysWrite_0_vfsc9jn7 ((NU8)0)
#define OnlyIfChanged_0_vfsc9jn7 ((NU8)1)
typedef struct MemFile_0_memlzdyby{
  void* mem_0;
  NI32 size_0;
  int handle_0;
  int flags_0;}
MemFile_0_memlzdyby;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1)(VfsBlob_0_vfsc9jn7*);
typedef struct VfsBlob_0_vfsc9jn7{
  void* data_0;
  NI32 size_0;
  MemFile_0_memlzdyby mf_0;
  void* cookie_0;
  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1 cleanup_0;}
VfsBlob_0_vfsc9jn7;
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
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1{
  ErrorCode_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby{
  ErrorCode_0_sysvq0asl fld_0;
  MemFile_0_memlzdyby fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby;
typedef N_NIMCALL_PTR(VfsBlob_0_vfsc9jn7,  X60Qt_0_ISstring0sysvq0aslSX56fsX42lob0vfsc9jn7AnimcallZAfalseZAR47_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISstring0sysvq0aslSR0SEAnimcallZAfalseZAR31_vfsc9jn7)(string_0_sysvq0asl, string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NI64,  X60Qt_0_ISstring0sysvq0aslAiS64ZAnimcallZAfalseZAR32_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NI64,  X60Qt_0_IAiS64ZAnimcallZAfalseZAR15_vfsc9jn7)(void);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISstring0sysvq0aslSEAnimcallZAfalseZAR28_vfsc9jn7)(string_0_sysvq0asl);
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
typedef struct Path_0_pat4k2dls{
  string_0_sysvq0asl data_0;}
Path_0_pat4k2dls;
typedef NU8 FileMode_0_syn1lfpjv;

#define fmRead_0_syn1lfpjv ((NU8)0)
#define fmWrite_0_syn1lfpjv ((NU8)1)
#define fmReadWrite_0_syn1lfpjv ((NU8)2)
#define fmReadWriteExisting_0_syn1lfpjv ((NU8)3)
#define fmAppend_0_syn1lfpjv ((NU8)4)
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 getLastModificationTime_0_oswd7dmm(string_0_sysvq0asl file_0);
extern Time_0_timsagyye1 getTime_0_timsagyye1(void);
extern NI64 toUnix_0_timsagyye1(Time_0_timsagyye1 t_0);
static inline NI32 nanosecond_0_timsagyye1(Time_0_timsagyye1 t_2);
static inline Path_0_pat4k2dls path_0_pat4k2dls(string_0_sysvq0asl s_0);
extern ErrorCode_0_sysvq0asl removeFile_0_dir38pj6l(Path_0_pat4k2dls file_1);
extern void eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(Path_0_pat4k2dls dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1 readFile_0_syn1lfpjv(string_0_sysvq0asl filename_4);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern ErrorCode_0_sysvq0asl writeFile_0_syn1lfpjv(string_0_sysvq0asl filename_5, string_0_sysvq0asl content_0);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void quit_1_syn1lfpjv(string_0_sysvq0asl msg_0);
extern NB8 fileExists_0_osc4bsu0d1(string_0_sysvq0asl filename_0);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby open_0_memlzdyby(string_0_sysvq0asl filename_0, FileMode_0_syn1lfpjv mode_0, NI32 mappedSize_0, NI32 offset_0, NI32 newFileSize_1, NB8 allowRemap_0, int mapFlags_0);
extern ErrorCode_0_sysvq0asl close_0_memlzdyby(MemFile_0_memlzdyby* f_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_memlzdyby(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_timsagyye1(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_dir38pj6l(void);
extern void X60Qini_0_pat4k2dls(void);
extern void eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls(Path_0_pat4k2dls* dest_0);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
LongString_0_sysvq0asl const strlit_0_I12909424938976562878_vfsc9jn7 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vfs: write failed: "}
;
LongString_0_sysvq0asl const strlit_0_I3169694335637950427_vfsc9jn7 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vfs: open failed: "}
;
X60Qt_0_ISstring0sysvq0aslSX56fsX42lob0vfsc9jn7AnimcallZAfalseZAR47_vfsc9jn7 openMmapRelay_0_vfsc9jn7;
X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7 readBytesRelay_0_vfsc9jn7;
X60Qt_0_ISstring0sysvq0aslSR0SEAnimcallZAfalseZAR31_vfsc9jn7 writeBytesRelay_0_vfsc9jn7;
X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7 existsRelay_0_vfsc9jn7;
X60Qt_0_ISstring0sysvq0aslAiS64ZAnimcallZAfalseZAR32_vfsc9jn7 mtimeRelay_0_vfsc9jn7;
X60Qt_0_IAiS64ZAnimcallZAfalseZAR15_vfsc9jn7 nowRelay_0_vfsc9jn7;
X60Qt_0_ISstring0sysvq0aslSEAnimcallZAfalseZAR28_vfsc9jn7 removeRelay_0_vfsc9jn7;
NB8 X60QiniGuard_0_vfsc9jn7;
NI64 unixModTime_0_vfsc9jn7(string_0_sysvq0asl p_0){
  NI64 result_1;
  NI64 X60Qx_0;
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 X60QcanRaise_0 = getLastModificationTime_0_oswd7dmm(p_0);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_0;}
  X60Qx_0 = X60QcanRaise_0.fld_1;
  if (NIM_FALSE){
    X60Qexlab_0: ;
    X60Qx_0 = ((NI64)0);}
  result_1 = X60Qx_0;
  return result_1;}
NI64 unixNow_0_vfsc9jn7(void){
  NI64 result_2;
  NI64 X60Qx_1;
  Time_0_timsagyye1 t_0 = getTime_0_timsagyye1();
  NI64 X60Qx_5 = toUnix_0_timsagyye1(t_0);
  NI32 X60Qx_6 = nanosecond_0_timsagyye1(t_0);
  X60Qx_1 = ((NI64)(((NI64)(X60Qx_5 * ((NI64)1000000000))) + ((NI64)X60Qx_6)));
  if (NIM_FALSE){
    X60Qexlab_1: ;
    X60Qx_1 = ((NI64)0);}
  result_2 = X60Qx_1;
  return result_2;}
void rmPath_0_vfsc9jn7(string_0_sysvq0asl p_1){
  Path_0_pat4k2dls X60Qtmp_0 = path_0_pat4k2dls(p_1);
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = removeFile_0_dir38pj6l(X60Qtmp_0);
  if (X60QcanRaise_0){
    eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_0);
    goto X60Qexlab_2;}
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(X60Qtmp_0);
  if (NIM_FALSE){
    X60Qexlab_2: ;}}
string_0_sysvq0asl readBytes_0_vfsc9jn7(string_0_sysvq0asl p_2){
  string_0_sysvq0asl result_3;
  nimStrWasMoved((&result_3));
  string_0_sysvq0asl X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1 X60QcanRaise_0 = readFile_0_syn1lfpjv(p_2);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_3;}
  nimStrDestroy(X60Qx_2);
  string_0_sysvq0asl X60Qx_7 = nimStrDup(X60QcanRaise_0.fld_1);
  X60Qx_2 = X60Qx_7;
  if (NIM_FALSE){
    X60Qexlab_3: ;
    nimStrDestroy(X60Qx_2);
    X60Qx_2 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_3);
  result_3 = X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  nimStrDestroy(X60Qx_2);
  return result_3;
  nimStrDestroy(X60Qx_2);
  return result_3;}
void writeBytes_0_vfsc9jn7(string_0_sysvq0asl p_3, string_0_sysvq0asl c_0){
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = writeFile_0_syn1lfpjv(p_3, c_0);
  if (X60QcanRaise_0){
    goto X60Qexlab_4;}
  if (NIM_FALSE){
    X60Qexlab_4: ;
    string_0_sysvq0asl X60Qtmp_1 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1936094974u, .more_0 = (&strlit_0_I12909424938976562878_vfsc9jn7)}
    , p_3);
    quit_1_syn1lfpjv(X60Qtmp_1);
    nimStrDestroy(X60Qtmp_1);}}
NB8 fileMaybeExists_0_vfsc9jn7(string_0_sysvq0asl p_4){
  NB8 result_4;
  NB8 X60Qx_3;
  NB8 X60Qx_8 = fileExists_0_osc4bsu0d1(p_4);
  X60Qx_3 = X60Qx_8;
  if (NIM_FALSE){
    X60Qexlab_5: ;
    X60Qx_3 = NIM_FALSE;}
  result_4 = X60Qx_3;
  return result_4;}
MemFile_0_memlzdyby openMmapImpl_0_vfsc9jn7(string_0_sysvq0asl p_5){
  MemFile_0_memlzdyby result_5;
  MemFile_0_memlzdyby X60Qx_4;
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby X60QcanRaise_0 = open_0_memlzdyby(p_5, 0, -1, 0, -1, NIM_FALSE, ((int)-1));
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_6;}
  X60Qx_4 = X60QcanRaise_0.fld_1;
  if (NIM_FALSE){
    X60Qexlab_6: ;
    string_0_sysvq0asl X60Qtmp_2 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1936094974u, .more_0 = (&strlit_0_I3169694335637950427_vfsc9jn7)}
    , p_5);
    quit_1_syn1lfpjv(X60Qtmp_2);
    nimStrDestroy(X60Qtmp_2);}
  result_5 = X60Qx_4;
  return result_5;}
VfsBlob_0_vfsc9jn7 initBlob_0_vfsc9jn7(void* data_0, NI32 size_0, void* cookie_0, X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1 cleanup_0){
  VfsBlob_0_vfsc9jn7 result_6;
  result_6 = (VfsBlob_0_vfsc9jn7){
    .data_0 = data_0, .size_0 = size_0, .mf_0 = (MemFile_0_memlzdyby){
      .mem_0 = NIM_NIL, .size_0 = ((NI32)0), .handle_0 = ((NI32)0), .flags_0 = ((NI32)0)}
    , .cookie_0 = cookie_0, .cleanup_0 = cleanup_0}
  ;
  return result_6;}
N_NIMCALL(void, closeMemFileBlob_0_vfsc9jn7)(VfsBlob_0_vfsc9jn7* b_3){
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = close_0_memlzdyby((&(*b_3).mf_0));
  if (X60QcanRaise_0){
    goto X60Qexlab_7;}
  if (NIM_FALSE){
    X60Qexlab_7: ;}}
VfsBlob_0_vfsc9jn7 fromMemFile_0_vfsc9jn7(MemFile_0_memlzdyby mf_0){
  VfsBlob_0_vfsc9jn7 result_7;
  result_7 = (VfsBlob_0_vfsc9jn7){
    .data_0 = mf_0.mem_0, .size_0 = mf_0.size_0, .mf_0 = mf_0, .cookie_0 = NIM_NIL, .cleanup_0 = closeMemFileBlob_0_vfsc9jn7}
  ;
  return result_7;}
VfsBlob_0_vfsc9jn7 X60Qanonproc_0_vfsc9jn7(string_0_sysvq0asl path_7){
  VfsBlob_0_vfsc9jn7 result_8;
  MemFile_0_memlzdyby X60Qx_9 = openMmapImpl_0_vfsc9jn7(path_7);
  VfsBlob_0_vfsc9jn7 X60Qx_10 = fromMemFile_0_vfsc9jn7(X60Qx_9);
  result_8 = X60Qx_10;
  return result_8;}
string_0_sysvq0asl X60Qanonproc_1_vfsc9jn7(string_0_sysvq0asl path_9){
  string_0_sysvq0asl result_9;
  nimStrWasMoved((&result_9));
  nimStrDestroy(result_9);
  string_0_sysvq0asl X60Qx_11 = readBytes_0_vfsc9jn7(path_9);
  result_9 = X60Qx_11;
  return result_9;}
void X60Qanonproc_2_vfsc9jn7(string_0_sysvq0asl path_11, string_0_sysvq0asl content_2){
  writeBytes_0_vfsc9jn7(path_11, content_2);}
NB8 X60Qanonproc_3_vfsc9jn7(string_0_sysvq0asl path_13){
  NB8 result_10;
  NB8 X60Qx_12 = fileMaybeExists_0_vfsc9jn7(path_13);
  result_10 = X60Qx_12;
  return result_10;}
NI64 X60Qanonproc_4_vfsc9jn7(string_0_sysvq0asl path_15){
  NI64 result_11;
  NI64 X60Qx_13 = unixModTime_0_vfsc9jn7(path_15);
  result_11 = X60Qx_13;
  return result_11;}
NI64 X60Qanonproc_5_vfsc9jn7(void){
  NI64 result_12;
  NI64 X60Qx_14 = unixNow_0_vfsc9jn7();
  result_12 = X60Qx_14;
  return result_12;}
void X60Qanonproc_6_vfsc9jn7(string_0_sysvq0asl path_17){
  rmPath_0_vfsc9jn7(path_17);}
static inline VfsBlob_0_vfsc9jn7 vfsOpenMmap_0_vfsc9jn7(string_0_sysvq0asl path_0){
  VfsBlob_0_vfsc9jn7 result_13;
  VfsBlob_0_vfsc9jn7 X60Qx_15 = openMmapRelay_0_vfsc9jn7(path_0);
  result_13 = X60Qx_15;
  return result_13;}
static inline string_0_sysvq0asl vfsRead_0_vfsc9jn7(string_0_sysvq0asl path_1){
  string_0_sysvq0asl result_14;
  nimStrWasMoved((&result_14));
  nimStrDestroy(result_14);
  string_0_sysvq0asl X60Qx_16 = readBytesRelay_0_vfsc9jn7(path_1);
  result_14 = X60Qx_16;
  return result_14;}
static inline NB8 vfsExists_0_vfsc9jn7(string_0_sysvq0asl path_3){
  NB8 result_15;
  NB8 X60Qx_17 = existsRelay_0_vfsc9jn7(path_3);
  result_15 = X60Qx_17;
  return result_15;}
void X60Qini_0_vfsc9jn7(void){
  if (X60QiniGuard_0_vfsc9jn7){
    return;}
  X60QiniGuard_0_vfsc9jn7 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_memlzdyby();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_timsagyye1();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_dir38pj6l();
  X60Qini_0_pat4k2dls();}
static inline NI32 nanosecond_0_timsagyye1(Time_0_timsagyye1 t_2){
  NI32 result_6;
  result_6 = t_2.nanosecond_0;
  return result_6;}
static inline Path_0_pat4k2dls path_0_pat4k2dls(string_0_sysvq0asl s_0){
  Path_0_pat4k2dls result_0;
  eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&result_0));
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(result_0);
  string_0_sysvq0asl X60Qx_6 = nimStrDup(s_0);
  result_0 = (Path_0_pat4k2dls){
    .data_0 = X60Qx_6}
  ;
  return result_0;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
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
static void __attribute__((constructor)) init(void) {openMmapRelay_0_vfsc9jn7 = X60Qanonproc_0_vfsc9jn7;
readBytesRelay_0_vfsc9jn7 = X60Qanonproc_1_vfsc9jn7;
writeBytesRelay_0_vfsc9jn7 = X60Qanonproc_2_vfsc9jn7;
existsRelay_0_vfsc9jn7 = X60Qanonproc_3_vfsc9jn7;
mtimeRelay_0_vfsc9jn7 = X60Qanonproc_4_vfsc9jn7;
nowRelay_0_vfsc9jn7 = X60Qanonproc_5_vfsc9jn7;
removeRelay_0_vfsc9jn7 = X60Qanonproc_6_vfsc9jn7;
}

