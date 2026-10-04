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
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef NU8 PathComponent_0_osc4bsu0d1;

#define pcFile_0_osc4bsu0d1 ((NU8)0)
#define pcLinkToFile_0_osc4bsu0d1 ((NU8)1)
#define pcDir_0_osc4bsu0d1 ((NU8)2)
#define pcLinkToDir_0_osc4bsu0d1 ((NU8)3)
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct Path_0_pat4k2dls{
  string_0_sysvq0asl data_0;}
Path_0_pat4k2dls;
typedef struct DirEntry_0_dir38pj6l{
  PathComponent_0_osc4bsu0d1 kind_0;
  Path_0_pat4k2dls path_0;}
DirEntry_0_dir38pj6l;
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
typedef struct DirWalker_0_dir38pj6l{
  DIR* pimpl_0;
  Path_0_pat4k2dls dir_0;
  ErrorCode_0_sysvq0asl status_0;}
DirWalker_0_dir38pj6l;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[32];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l{
  ErrorCode_0_sysvq0asl fld_0;
  Path_0_pat4k2dls fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct X60Qt_0_IAarrayAcS8ZS256_pososrh1q1{
  NC8 a[256];}
X60Qt_0_IAarrayAcS8ZS256_pososrh1q1;
void eQdestroyQ_SX44irX57alker0dir38pj6l_0_dir38pj6l(DirWalker_0_dir38pj6l dest_0);
void eQwasmovedQ_SX44irX57alker0dir38pj6l_0_dir38pj6l(DirWalker_0_dir38pj6l* dest_0);
static inline string_0_sysvq0asl dollarQ_0_pat4k2dls(Path_0_pat4k2dls x_0);
extern NC8* toCString_0_sysvq0asl(string_0_sysvq0asl* s_64);
extern ErrorCode_0_sysvq0asl posixToErrorCode_0_err0o7h081(NI32 err_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls(Path_0_pat4k2dls* dest_0);
extern void eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(Path_0_pat4k2dls dest_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
extern string_0_sysvq0asl fromCString_0_sysvq0asl(NC8* s_65);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline Path_0_pat4k2dls path_0_pat4k2dls(string_0_sysvq0asl s_0);
extern string_0_sysvq0asl newString_0_sysvq0asl(NI32 len_4);
extern NI32 osLastError_0_osezuyu63(void);
extern ErrorCode_0_sysvq0asl raiseOSError_0_osezuyu63(NI32 errorCode_0, string_0_sysvq0asl additionalInfo_0);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void shrink_1_sysvq0asl(string_0_sysvq0asl* s_52, NI32 newLen_12);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_osezuyu63(void);
extern void X60Qini_0_pat4k2dls(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_pososrh1q1(void);
extern void X60Qini_0_err0o7h081(void);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ignore runnable examples"}
;
LongString_0_sysvq0asl const strlit_0_I1116682708570381389_dir38pj6l = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "fine"}
;
LongString_0_sysvq0asl const strlit_0_I5892404049451637519_dir38pj6l = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "skip"}
;
static NI32 const bufSize_0 = ((NI32)1024);
NB8 X60QiniGuard_0_dir38pj6l;
ErrorCode_0_sysvq0asl tryCreateFinalDir_0_dir38pj6l(Path_0_pat4k2dls dir_0){
  ErrorCode_0_sysvq0asl result_0;
  string_0_sysvq0asl dirStr_0 = dollarQ_0_pat4k2dls(dir_0);
  NC8* X60Qx_2 = toCString_0_sysvq0asl((&dirStr_0));
  int X60Qx_3 = mkdir(X60Qx_2, ((mode_t)511));
  if (X60Qx_3 == ((NI32)0)){
    result_0 = 0;}
  else {
    ErrorCode_0_sysvq0asl X60Qx_4 = posixToErrorCode_0_err0o7h081(errno);
    result_0 = X60Qx_4;}
  nimStrDestroy(dirStr_0);
  return result_0;
  nimStrDestroy(dirStr_0);
  return result_0;}
ErrorCode_0_sysvq0asl tryRemoveFinalDir_0_dir38pj6l(Path_0_pat4k2dls dir_2){
  ErrorCode_0_sysvq0asl result_1;
  string_0_sysvq0asl dirStr_1 = dollarQ_0_pat4k2dls(dir_2);
  NC8* X60Qx_18 = toCString_0_sysvq0asl((&dirStr_1));
  int X60Qx_19 = rmdir(X60Qx_18);
  if (X60Qx_19 == ((NI32)0)){
    result_1 = 0;}
  else {
    ErrorCode_0_sysvq0asl X60Qx_20 = posixToErrorCode_0_err0o7h081(errno);
    result_1 = X60Qx_20;}
  nimStrDestroy(dirStr_1);
  return result_1;
  nimStrDestroy(dirStr_1);
  return result_1;}
ErrorCode_0_sysvq0asl tryRemoveFile_0_dir38pj6l(Path_0_pat4k2dls file_0){
  ErrorCode_0_sysvq0asl result_2;
  string_0_sysvq0asl fileStr_0 = dollarQ_0_pat4k2dls(file_0);
  NC8* X60Qx_23 = toCString_0_sysvq0asl((&fileStr_0));
  int X60Qx_24 = unlink(X60Qx_23);
  if (X60Qx_24 == ((NI32)0)){
    result_2 = 0;}
  else {
    ErrorCode_0_sysvq0asl X60Qx_25 = posixToErrorCode_0_err0o7h081(errno);
    result_2 = X60Qx_25;}
  nimStrDestroy(fileStr_0);
  return result_2;
  nimStrDestroy(fileStr_0);
  return result_2;}
ErrorCode_0_sysvq0asl removeFile_0_dir38pj6l(Path_0_pat4k2dls file_1){
  ErrorCode_0_sysvq0asl res_2 = tryRemoveFile_0_dir38pj6l(file_1);
  NB8 X60Qx_26;
  if (res_2 == 0){
    X60Qx_26 = NIM_TRUE;}
  else {
    X60Qx_26 = (res_2 == 38);}
  if (X60Qx_26){
    string_0_sysvq0asl X60Qx_27 = (string_0_sysvq0asl){
      .bytes_0 = 1852401406u, .more_0 = (&strlit_0_I1116682708570381389_dir38pj6l)}
    ;}
  else {
    return res_2;}
  return 0;}
DirWalker_0_dir38pj6l tryOpenDir_0_dir38pj6l(Path_0_pat4k2dls dir_4){
  DirWalker_0_dir38pj6l result_3;
  eQwasmovedQ_SX44irX57alker0dir38pj6l_0_dir38pj6l((&result_3));
  eQdestroyQ_SX44irX57alker0dir38pj6l_0_dir38pj6l(result_3);
  Path_0_pat4k2dls X60Qtmp_1 = dir_4;
  eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&dir_4));
  result_3 = (DirWalker_0_dir38pj6l){
    .pimpl_0 = ((DIR*)NIM_NIL), .dir_0 = X60Qtmp_1, .status_0 = 17}
  ;
  string_0_sysvq0asl dirStr_2 = dollarQ_0_pat4k2dls(result_3.dir_0);
  NC8* X60Qx_28 = toCString_0_sysvq0asl((&dirStr_2));
  DIR* X60Qx_29 = opendir(X60Qx_28);
  result_3.pimpl_0 = X60Qx_29;
  if (result_3.pimpl_0 == NIM_NIL){
    ErrorCode_0_sysvq0asl X60Qx_30 = posixToErrorCode_0_err0o7h081(errno);
    result_3.status_0 = X60Qx_30;}
  else {
    result_3.status_0 = 0;}
  nimStrDestroy(dirStr_2);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(dir_4);
  return result_3;
  nimStrDestroy(dirStr_2);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(dir_4);
  return result_3;}
PathComponent_0_osc4bsu0d1 pathComponentFromEntry_0_dir38pj6l(DirWalker_0_dir38pj6l* w_1, string_0_sysvq0asl name_0, NU8 dType_0){
  PathComponent_0_osc4bsu0d1 result_4;
  NB8 X60Qx_31;
  if (dType_0 == ((NU8)0u)){
    X60Qx_31 = NIM_TRUE;}
  else {
    X60Qx_31 = (dType_0 == ((NU8)10u));}
  if (X60Qx_31){
    string_0_sysvq0asl X60Qdesugar_4 = dollarQ_0_pat4k2dls((*w_1).dir_0);
    NI32 X60Qx_32 = len_4_sysvq0asl(X60Qdesugar_4);
    NI32 X60Qx_33 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 12033u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_34 = len_4_sysvq0asl(name_0);
    string_0_sysvq0asl X60Qdesugar_5 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_32 + X60Qx_33)) + X60Qx_34)));
    add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_4);
    add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
      .bytes_0 = 12033u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_5), name_0);
    string_0_sysvq0asl fullPath_0 = X60Qdesugar_5;
    nimStrWasMoved((&X60Qdesugar_5));
    struct stat s_0 = (struct stat){
      .st_dev = ((NU32)0u), .st_ino = ((NU32)0u), .st_size = ((NI64)0), .st_mode = ((NU32)0u), .st_mtime = ((NI64)0), .st_mtim = (struct timespec){
        .tv_sec = ((NI32)0), .tv_nsec = ((NI32)0)}}
    ;
    NC8* X60Qx_35 = toCString_0_sysvq0asl((&fullPath_0));
    int X60Qx_36 = lstat(X60Qx_35, (&s_0));
    if (X60Qx_36 == 0){
      NB8 X60Qx_37 = S_ISLNK(s_0.st_mode);
      if (X60Qx_37){
        struct stat targetStat_0 = (struct stat){
          .st_dev = ((NU32)0u), .st_ino = ((NU32)0u), .st_size = ((NI64)0), .st_mode = ((NU32)0u), .st_mtime = ((NI64)0), .st_mtim = (struct timespec){
            .tv_sec = ((NI32)0), .tv_nsec = ((NI32)0)}}
        ;
        NB8 X60Qx_38;
        NC8* X60Qx_39 = toCString_0_sysvq0asl((&fullPath_0));
        int X60Qx_40 = stat(X60Qx_39, (&targetStat_0));
        if (X60Qx_40 == 0){
          NB8 X60Qx_41 = S_ISDIR(targetStat_0.st_mode);
          X60Qx_38 = X60Qx_41;}
        else {
          X60Qx_38 = NIM_FALSE;}
        if (X60Qx_38){
          result_4 = 3;}
        else {
          result_4 = 1;}}
      else {
        NB8 X60Qx_42 = S_ISDIR(s_0.st_mode);
        if (X60Qx_42){
          result_4 = 2;}
        else {
          result_4 = 0;}}}
    else {
      result_4 = 0;}
    nimStrDestroy(fullPath_0);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qdesugar_4);}
  else {
    if (dType_0 == ((NU8)4u)){
      result_4 = 2;}
    else {
      result_4 = 0;}}
  return result_4;}
NB8 tryNextDir_0_dir38pj6l(DirWalker_0_dir38pj6l* w_2, DirEntry_0_dir38pj6l* e_1){
  NB8 result_5;
  result_5 = NIM_FALSE;
  {
    while ((*w_2).status_0 == 0){
      struct dirent* entry_0 = readdir((*w_2).pimpl_0);
      if (entry_0 == NIM_NIL){
        if ((*w_2).status_0 == 0){
          ErrorCode_0_sysvq0asl X60Qx_43 = posixToErrorCode_0_err0o7h081(errno);
          (*w_2).status_0 = X60Qx_43;}
        result_5 = NIM_FALSE;
        goto whileStmtLabel_0;}
      else {
        result_5 = NIM_TRUE;
        NI32 X60Qx_44 = nimIcheckB(0, 255);
        NC8* cstr_0 = ((NC8*)(&(*entry_0).d_name[X60Qx_44]));
        string_0_sysvq0asl name_1 = fromCString_0_sysvq0asl(cstr_0);
        NB8 X60Qx_45;
        NB8 X60Qx_46 = eqQ_20_sysvq0asl(name_1, (string_0_sysvq0asl){
          .bytes_0 = 11777u, .more_0 = NIM_NIL}
        );
        if (X60Qx_46){
          X60Qx_45 = NIM_TRUE;}
        else {
          NB8 X60Qx_47 = eqQ_20_sysvq0asl(name_1, (string_0_sysvq0asl){
            .bytes_0 = 3026434u, .more_0 = NIM_NIL}
          );
          X60Qx_45 = X60Qx_47;}
        if (X60Qx_45){
          string_0_sysvq0asl X60Qx_48 = (string_0_sysvq0asl){
            .bytes_0 = 1768649726u, .more_0 = (&strlit_0_I5892404049451637519_dir38pj6l)}
          ;}
        else {
          PathComponent_0_osc4bsu0d1 X60Qx_49 = pathComponentFromEntry_0_dir38pj6l(w_2, name_1, (*entry_0).d_type);
          (*e_1).kind_0 = X60Qx_49;
          Path_0_pat4k2dls* X60Qlhs_2 = (&(*e_1).path_0);
          eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls((*X60Qlhs_2));
          Path_0_pat4k2dls X60Qx_50 = path_0_pat4k2dls(name_1);
          (*X60Qlhs_2) = X60Qx_50;
          nimStrDestroy(name_1);
          goto whileStmtLabel_0;}
        nimStrDestroy(name_1);}}}
  whileStmtLabel_0: ;
  return result_5;}
ErrorCode_0_sysvq0asl tryCloseDir_0_dir38pj6l(DirWalker_0_dir38pj6l* w_3){
  ErrorCode_0_sysvq0asl result_6;
  int X60Qx_51 = closedir((*w_3).pimpl_0);
  if (X60Qx_51 == ((NI32)0)){
    result_6 = 0;}
  else {
    ErrorCode_0_sysvq0asl X60Qx_52 = posixToErrorCode_0_err0o7h081(errno);
    result_6 = X60Qx_52;}
  return result_6;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l getCurrentDir_0_dir38pj6l(void){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l result_7;
  result_7.fld_0 = 0;
  eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&result_7.fld_1));
  string_0_sysvq0asl buffer_0 = newString_0_sysvq0asl(((NI32)1024));
  NC8* X60Qx_53 = toCString_0_sysvq0asl((&buffer_0));
  NC8* X60Qx_54 = getcwd(X60Qx_53, ((NI32)1024));
  if (((void*)X60Qx_54) == NIM_NIL){
    NI32 X60Qx_55 = osLastError_0_osezuyu63();
    ErrorCode_0_sysvq0asl X60QcanRaise_0 = raiseOSError_0_osezuyu63(X60Qx_55, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    if (X60QcanRaise_0){
      nimStrDestroy(buffer_0);
      return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l){
        .fld_0 = X60QcanRaise_0, .fld_1 = result_7.fld_1}
      ;}}
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_56;
      NI32 X60Qx_57 = len_4_sysvq0asl(buffer_0);
      if (i_0 < X60Qx_57){
        NC8 X60Qx_58 = getQ_9_sysvq0asl(buffer_0, i_0);
        X60Qx_56 = (!(X60Qx_58 == (NC8)'\000'));}
      else {
        X60Qx_56 = NIM_FALSE;}
      if (X60Qx_56){
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  shrink_1_sysvq0asl((&buffer_0), i_0);
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(result_7.fld_1);
  Path_0_pat4k2dls X60Qx_59 = path_0_pat4k2dls(buffer_0);
  result_7 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l){
    .fld_0 = 0, .fld_1 = X60Qx_59}
  ;
  nimStrDestroy(buffer_0);
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX50ath0pat4k2dls_dir38pj6l){
    .fld_0 = 0, .fld_1 = result_7.fld_1}
  ;
  nimStrDestroy(buffer_0);
  return result_7;}
ErrorCode_0_sysvq0asl setCurrentDir_0_dir38pj6l(Path_0_pat4k2dls dir_6){
  string_0_sysvq0asl dirStr_3 = dollarQ_0_pat4k2dls(dir_6);
  NC8* X60Qx_60 = toCString_0_sysvq0asl((&dirStr_3));
  int X60Qx_61 = chdir(X60Qx_60);
  if ((!(X60Qx_61 == ((NI32)0)))){
    NI32 X60Qx_62 = osLastError_0_osezuyu63();
    ErrorCode_0_sysvq0asl X60QcanRaise_0 = raiseOSError_0_osezuyu63(X60Qx_62, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    if (X60QcanRaise_0){
      nimStrDestroy(dirStr_3);
      return X60QcanRaise_0;}}
  nimStrDestroy(dirStr_3);
  return 0;}
void eQdestroyQ_SX44irX45ntry0dir38pj6l_0_dir38pj6l(DirEntry_0_dir38pj6l dest_0){
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(dest_0.path_0);}
void eQdestroyQ_SX44irX57alker0dir38pj6l_0_dir38pj6l(DirWalker_0_dir38pj6l dest_0){
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(dest_0.dir_0);}
void eQwasmovedQ_SX44irX57alker0dir38pj6l_0_dir38pj6l(DirWalker_0_dir38pj6l* dest_0){
  eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&(*dest_0).dir_0));}
void X60Qini_0_dir38pj6l(void){
  if (X60QiniGuard_0_dir38pj6l){
    return;}
  X60QiniGuard_0_dir38pj6l = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_osezuyu63();
  X60Qini_0_pat4k2dls();
  X60Qini_0_ossk30t39();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_pososrh1q1();
  X60Qini_0_err0o7h081();}
static inline string_0_sysvq0asl dollarQ_0_pat4k2dls(Path_0_pat4k2dls x_0){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  nimStrDestroy(result_1);
  string_0_sysvq0asl X60Qx_7 = nimStrDup(x_0.data_0);
  result_1 = X60Qx_7;
  return result_1;}
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
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline Path_0_pat4k2dls path_0_pat4k2dls(string_0_sysvq0asl s_0){
  Path_0_pat4k2dls result_0;
  eQwasmovedQ_SX50ath0pat4k2dls_0_pat4k2dls((&result_0));
  eQdestroyQ_SX50ath0pat4k2dls_0_pat4k2dls(result_0);
  string_0_sysvq0asl X60Qx_6 = nimStrDup(s_0);
  result_0 = (Path_0_pat4k2dls){
    .data_0 = X60Qx_6}
  ;
  return result_0;}
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
