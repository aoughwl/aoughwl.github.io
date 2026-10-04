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
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct openArray_0_Ijk0jkw1_feaji4clb1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_feaji4clb1;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[32];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21;
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
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1{
  NI32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAbool_osc4bsu0d1{
  ErrorCode_0_sysvq0asl fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAbool_osc4bsu0d1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6SR6_modjbswg91{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;
  string_0_sysvq0asl fld_2;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6SR6_modjbswg91;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
extern void setLen_1_sysvq0asl(string_0_sysvq0asl* s_53, NI32 newLen_13);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern string_0_sysvq0asl dollarQ_1_str7j0ifg(NC8 x_2);
static inline NI32 high_4_sysvq0asl(string_0_sysvq0asl s_35);
extern void addNormalizePath_0_patta6rli(string_0_sysvq0asl x_6, string_0_sysvq0asl* result_0, NI32* state_0, NC8 dirSep_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l;
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern string_0_sysvq0asl newString_0_sysvq0asl(NI32 len_4);
extern NC8* toCString_0_sysvq0asl(string_0_sysvq0asl* s_64);
static inline NI32 len_5_sysvq0asl(NC8* a_46);
extern NI32 osLastError_0_osezuyu63(void);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
extern ErrorCode_0_sysvq0asl raiseOSError_0_osezuyu63(NI32 errorCode_0, string_0_sysvq0asl additionalInfo_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern string_0_sysvq0asl normalizePath_0_patta6rli(string_0_sysvq0asl path_0, NC8 dirSep_1);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_str7j0ifg(void);
extern void X60Qini_0_osezuyu63(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_wid623gv(void);
extern void X60Qini_0_patta6rli(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_pososrh1q1(void);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
NB8 X60QiniGuard_0_ospaexnw61;
void normalizePathEnd_0_ospaexnw61(string_0_sysvq0asl* path_0, NB8 trailingSep_0){
  NI32 X60Qx_22 = len_4_sysvq0asl((*path_0));
  if (X60Qx_22 == 0){
    return;}
  NI32 i_0 = len_4_sysvq0asl((*path_0));
  {
    while (1 <= i_0){
      X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_0 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
        .a = {
          0u, 0u, 0u, 0u, 0u, 128u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
      ;
      NC8 X60Qx_23 = getQ_9_sysvq0asl((*path_0), ((NI32)(i_0 - 1)));
      NU64 X60Qdesugar_1 = ((NU)X60Qx_23);
      if (((NU8)(X60Qdesugar_0.a[((NU)(X60Qdesugar_1 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_1 & 7u)))))) != 0u){
        dec_1_I0nzoz91_ast8ri79k((&i_0));}
      else {
        NB8 X60Qx_0;
        NB8 X60Qx_24;
        NC8 X60Qx_25 = getQ_9_sysvq0asl((*path_0), ((NI32)(i_0 - 1)));
        if (X60Qx_25 == (NC8)'.'){
          X60Qx_24 = (2 <= i_0);}
        else {
          X60Qx_24 = NIM_FALSE;}
        if (X60Qx_24){
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_2 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
            .a = {
              0u, 0u, 0u, 0u, 0u, 128u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
          ;
          NC8 X60Qx_26 = getQ_9_sysvq0asl((*path_0), ((NI32)(i_0 - 2)));
          NU64 X60Qdesugar_3 = ((NU)X60Qx_26);
          X60Qx_0 = (((NU8)(X60Qdesugar_2.a[((NU)(X60Qdesugar_3 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_3 & 7u)))))) != 0u);}
        else {
          X60Qx_0 = NIM_FALSE;}
        if (X60Qx_0){
          dec_1_I0nzoz91_ast8ri79k((&i_0));}
        else {
          goto whileStmtLabel_0;}}}}
  whileStmtLabel_0: ;
  if (trailingSep_0){
    setLen_1_sysvq0asl(path_0, i_0);
    add_1_sysvq0asl(path_0, (NC8)'/');}
  else {
    if (0 < i_0){
      setLen_1_sysvq0asl(path_0, i_0);}
    else {
      nimStrDestroy((*path_0));
      string_0_sysvq0asl X60Qx_27 = dollarQ_1_str7j0ifg((NC8)'/');
      (*path_0) = X60Qx_27;}}}
void joinPathImpl_0_ospaexnw61(string_0_sysvq0asl* result_0, NI32* state_0, string_0_sysvq0asl tail_0){
  NB8 X60Qx_1;
  NB8 X60Qx_2;
  NI32 X60Qx_28 = len_4_sysvq0asl(tail_0);
  if (0 < X60Qx_28){
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_4 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
      .a = {
        0u, 0u, 0u, 0u, 0u, 128u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
    ;
    NI32 X60Qx_29 = high_4_sysvq0asl(tail_0);
    NC8 X60Qx_30 = getQ_9_sysvq0asl(tail_0, X60Qx_29);
    NU64 X60Qdesugar_5 = ((NU)X60Qx_30);
    X60Qx_2 = (((NU8)(X60Qdesugar_4.a[((NU)(X60Qdesugar_5 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_5 & 7u)))))) != 0u);}
  else {
    X60Qx_2 = NIM_FALSE;}
  if (X60Qx_2){
    X60Qx_1 = NIM_TRUE;}
  else {
    NB8 X60Qx_3;
    NI32 X60Qx_31 = len_4_sysvq0asl(tail_0);
    if (X60Qx_31 == 0){
      NB8 X60Qx_4;
      NI32 X60Qx_32 = len_4_sysvq0asl((*result_0));
      if (0 < X60Qx_32){
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_6 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
          .a = {
            0u, 0u, 0u, 0u, 0u, 128u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u}}
        ;
        NI32 X60Qx_33 = high_4_sysvq0asl((*result_0));
        NC8 X60Qx_34 = getQ_9_sysvq0asl((*result_0), X60Qx_33);
        NU64 X60Qdesugar_7 = ((NU)X60Qx_34);
        X60Qx_4 = (((NU8)(X60Qdesugar_6.a[((NU)(X60Qdesugar_7 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_7 & 7u)))))) != 0u);}
      else {
        X60Qx_4 = NIM_FALSE;}
      X60Qx_3 = X60Qx_4;}
    else {
      X60Qx_3 = NIM_FALSE;}
    X60Qx_1 = X60Qx_3;}
  NB8 trailingSep_1 = X60Qx_1;
  normalizePathEnd_0_ospaexnw61(result_0, NIM_FALSE);
  addNormalizePath_0_patta6rli(tail_0, result_0, state_0, (NC8)'/');
  normalizePathEnd_0_ospaexnw61(result_0, trailingSep_1);}
string_0_sysvq0asl joinPath_0_ospaexnw61(string_0_sysvq0asl head_0, string_0_sysvq0asl tail_1){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  string_0_sysvq0asl X60Qx_35 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  nimStrDestroy(result_1);
  NI32 X60Qx_36 = len_4_sysvq0asl(head_0);
  NI32 X60Qx_37 = len_4_sysvq0asl(tail_1);
  string_0_sysvq0asl X60Qx_38 = newStringOfCap_0_sysvq0asl(((NI32)(X60Qx_36 + X60Qx_37)));
  result_1 = X60Qx_38;
  NI32 state_1 = 0;
  joinPathImpl_0_ospaexnw61((&result_1), (&state_1), head_0);
  joinPathImpl_0_ospaexnw61((&result_1), (&state_1), tail_1);
  return result_1;}
static inline string_0_sysvq0asl slashQ_0_ospaexnw61(string_0_sysvq0asl head_1, string_0_sysvq0asl tail_2){
  string_0_sysvq0asl result_2;
  nimStrWasMoved((&result_2));
  string_0_sysvq0asl X60Qx_39 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  nimStrDestroy(result_2);
  string_0_sysvq0asl X60Qx_40 = joinPath_0_ospaexnw61(head_1, tail_2);
  result_2 = X60Qx_40;
  return result_2;}
NB8 isAbsolute_0_ospaexnw61(string_0_sysvq0asl path_2){
  NB8 result_4;
  string_0_sysvq0asl X60Qx_47 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  NI32 X60Qx_48 = len_4_sysvq0asl(path_2);
  if (X60Qx_48 == 0){
    return NIM_FALSE;}
  NC8 X60Qx_49 = getQ_9_sysvq0asl(path_2, 0);
  result_4 = (X60Qx_49 == (NC8)'/');
  return result_4;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1 getCurrentDir_0_ospaexnw61(void){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1 result_21;
  result_21.fld_0 = 0;
  NI32 bufsize_0 = 1024;
  string_0_sysvq0asl X60Qx_148 = newString_0_sysvq0asl(bufsize_0);
  result_21 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1){
    .fld_0 = 0, .fld_1 = X60Qx_148}
  ;
  {
    while (NIM_TRUE){
      NC8* X60Qx_149 = toCString_0_sysvq0asl((&result_21.fld_1));
      NC8* X60Qx_150 = getcwd(X60Qx_149, bufsize_0);
      if ((!(((void*)X60Qx_150) == NIM_NIL))){
        NC8* X60Qx_151 = toCString_0_sysvq0asl((&result_21.fld_1));
        NI32 X60Qx_152 = len_5_sysvq0asl(X60Qx_151);
        setLen_1_sysvq0asl((&result_21.fld_1), X60Qx_152);
        goto whileStmtLabel_0;}
      else {
        NI32 err_0 = osLastError_0_osezuyu63();
        if (((NI32)err_0) == ERANGE){
          bufsize_0 = ((NI32)(bufsize_0 << 1));
          if ((!(0 <= bufsize_0))){
            write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
              .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
            );
            write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            );
            write_7_syn1lfpjv(stdout, (NC8)'\012');
            quit_0_syn1lfpjv(1);}
          nimStrDestroy(result_21.fld_1);
          string_0_sysvq0asl X60Qx_153 = newString_0_sysvq0asl(bufsize_0);
          result_21 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1){
            .fld_0 = 0, .fld_1 = X60Qx_153}
          ;}
        else {
          NI32 X60Qx_154 = osLastError_0_osezuyu63();
          ErrorCode_0_sysvq0asl X60QcanRaise_0 = raiseOSError_0_osezuyu63(X60Qx_154, (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          );
          if (X60QcanRaise_0){
            return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1){
              .fld_0 = X60QcanRaise_0, .fld_1 = result_21.fld_1}
            ;}}}}}
  whileStmtLabel_0: ;
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1){
    .fld_0 = 0, .fld_1 = result_21.fld_1}
  ;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1 absolutePath_0_ospaexnw61(string_0_sysvq0asl path_15, string_0_sysvq0asl root_0){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1 result_22;
  result_22.fld_0 = 0;
  nimStrWasMoved((&result_22.fld_1));
  string_0_sysvq0asl X60Qx_155 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  string_0_sysvq0asl X60Qx_18;
  nimStrWasMoved((&X60Qx_18));
  NB8 X60Qx_156 = isAbsolute_0_ospaexnw61(path_15);
  if (X60Qx_156){
    nimStrDestroy(X60Qx_18);
    string_0_sysvq0asl X60Qx_157 = nimStrDup(path_15);
    X60Qx_18 = X60Qx_157;}
  else {
    NB8 X60Qx_158 = isAbsolute_0_ospaexnw61(root_0);
    if ((!X60Qx_158)){
      nimStrDestroy(X60Qx_18);
      return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1){
        .fld_0 = 12, .fld_1 = result_22.fld_1}
      ;}
    nimStrDestroy(X60Qx_18);
    string_0_sysvq0asl X60Qx_159 = joinPath_0_ospaexnw61(root_0, path_15);
    X60Qx_18 = X60Qx_159;}
  nimStrDestroy(result_22.fld_1);
  result_22 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1){
    .fld_0 = 0, .fld_1 = X60Qx_18}
  ;
  nimStrWasMoved((&X60Qx_18));
  nimStrDestroy(X60Qx_18);
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1){
    .fld_0 = 0, .fld_1 = result_22.fld_1}
  ;
  nimStrDestroy(X60Qx_18);
  return result_22;}
string_0_sysvq0asl normalizedPath_0_ospaexnw61(string_0_sysvq0asl path_19){
  string_0_sysvq0asl result_24;
  nimStrWasMoved((&result_24));
  string_0_sysvq0asl X60Qx_162 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  nimStrDestroy(result_24);
  string_0_sysvq0asl X60Qx_163 = normalizePath_0_patta6rli(path_19, (NC8)'/');
  result_24 = X60Qx_163;
  return result_24;}
void X60Qini_0_ospaexnw61(void){
  if (X60QiniGuard_0_ospaexnw61){
    return;}
  X60QiniGuard_0_ospaexnw61 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_str7j0ifg();
  X60Qini_0_osezuyu63();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_assy765wm();
  X60Qini_0_wid623gv();
  X60Qini_0_patta6rli();
  X60Qini_0_ossk30t39();
  X60Qini_0_pososrh1q1();}
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
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NI32 high_4_sysvq0asl(string_0_sysvq0asl s_35){
  NI32 result_99;
  NI32 X60Qx_220 = len_4_sysvq0asl(s_35);
  result_99 = ((NI32)(X60Qx_220 - 1));
  return result_99;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline NI32 len_5_sysvq0asl(NC8* a_46){
  NI32 result_105;
  NI64 X60Qx_19;
  if (((void*)a_46) == NIM_NIL){
    X60Qx_19 = 0;}
  else {
    size_t X60Qx_225 = strlen(a_46);
    X60Qx_19 = ((NI32)X60Qx_225);}
  result_105 = X60Qx_19;
  return result_105;}
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
