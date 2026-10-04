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
#include <string.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
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
typedef NU8 FilePermission_0_syn1lfpjv;

#define fpUserExec_0_syn1lfpjv ((NU8)0)
#define fpUserWrite_0_syn1lfpjv ((NU8)1)
#define fpUserRead_0_syn1lfpjv ((NU8)2)
#define fpGroupExec_0_syn1lfpjv ((NU8)3)
#define fpGroupWrite_0_syn1lfpjv ((NU8)4)
#define fpGroupRead_0_syn1lfpjv ((NU8)5)
#define fpOthersExec_0_syn1lfpjv ((NU8)6)
#define fpOthersWrite_0_syn1lfpjv ((NU8)7)
#define fpOthersRead_0_syn1lfpjv ((NU8)8)
typedef struct X60Qt_0_IAarrayAcS8ZS80_syn1lfpjv{
  NC8 a[80];}
X60Qt_0_IAarrayAcS8ZS80_syn1lfpjv;
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
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1{
  ErrorCode_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1{
  ErrorCode_0_sysvq0asl fld_0;
  NI64 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline string_0_sysvq0asl terminatingZero_0_sysvq0asl(string_0_sysvq0asl s_60);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void shrink_1_sysvq0asl(string_0_sysvq0asl* s_52, NI32 newLen_12);
extern void cExit_0_sysvq0asl(NI32 code_1);
extern string_0_sysvq0asl newString_0_sysvq0asl(NI32 len_4);
extern NC8* beginStore_0_sysvq0asl(string_0_sysvq0asl* s_47, NI32 newLen_7, NI32 start_2);
static inline void endStore_0_sysvq0asl(string_0_sysvq0asl* s_48);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern void setLen_1_sysvq0asl(string_0_sysvq0asl* s_53, NI32 newLen_13);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_for2ybv4p1(void);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
NB8 X60QiniGuard_0_syn1lfpjv;
void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0){
  NC8* X60Qx_2 = readRawData_0_sysvq0asl((&s_0), 0);
  NI32 X60Qx_3 = len_4_sysvq0asl(s_0);
  NU32 X60Qx_4 = fwrite(((void*)X60Qx_2), 1u, ((NU32)X60Qx_3), f_6);}
void write_7_syn1lfpjv(FILE* f_13, NC8 c_1){
  NI32 X60Qx_5 = fputc(((NI32)c_1), f_13);}
void close_0_syn1lfpjv(FILE* f_16){
  NI32 X60Qx_6 = fclose(f_16);}
NI32 readBuffer_0_syn1lfpjv(FILE* f_18, void* buffer_1, NI32 size_3){
  NI32 result_5;
  NU32 X60Qx_8 = fread(buffer_1, 1u, ((NU32)size_3), f_18);
  result_5 = ((NI32)X60Qx_8);
  return result_5;}
static inline NB8 failed_0_syn1lfpjv(FILE* f_20){
  NB8 result_6;
  NI32 X60Qx_9 = ferror(f_20);
  result_6 = (!(X60Qx_9 == 0));
  return result_6;}
NB8 open_0_syn1lfpjv(FILE** f_22, string_0_sysvq0asl filename_1, FileMode_0_syn1lfpjv mode_2, NI32 bufSize_0){
  NB8 result_7;
  NC8* X60Qx_0;
  switch (mode_2){
    case 0:
    {
      X60Qx_0 = (NC8*)"rb";}
    break;
    case 1:
    {
      X60Qx_0 = (NC8*)"wb";}
    break;
    case 2:
    {
      X60Qx_0 = (NC8*)"w+b";}
    break;
    case 3:
    {
      X60Qx_0 = (NC8*)"r+b";}
    break;
    case 4:
    {
      X60Qx_0 = (NC8*)"ab";}
    break;}
  NC8* m_0 = X60Qx_0;
  string_0_sysvq0asl tmpFilename_0 = terminatingZero_0_sysvq0asl(filename_1);
  NC8* X60Qx_10 = readRawData_0_sysvq0asl((&tmpFilename_0), 0);
  NC8* rawFilename_0 = ((NC8*)X60Qx_10);
  FILE* X60Qx_11 = fopen(rawFilename_0, m_0);
  (*f_22) = X60Qx_11;
  if ((!((*f_22) == NIM_NIL))){
    result_7 = NIM_TRUE;
    if (0 <= bufSize_0){
      NI32 X60Qx_12 = setvbuf((*f_22), NIM_NIL, ((NI32)0), ((NU32)bufSize_0));}}
  else {
    result_7 = NIM_FALSE;}
  nimStrDestroy(tmpFilename_0);
  return result_7;
  nimStrDestroy(tmpFilename_0);
  return result_7;}
void writeLine_0_syn1lfpjv(FILE* f_23, string_0_sysvq0asl s_1){
  write_0_syn1lfpjv(f_23, s_1);
  write_7_syn1lfpjv(f_23, (NC8)'\012');}
NB8 addReadLine_0_syn1lfpjv(FILE* f_25, string_0_sysvq0asl* s_2){
  NB8 result_9;
  result_9 = NIM_FALSE;
  X60Qt_0_IAarrayAcS8ZS80_syn1lfpjv buf_2;
  {
    while (NIM_TRUE){
      NC8* X60Qx_14 = fgets((&buf_2.a[0]), ((NI32)((NI32)80)), f_25);
      if ((!(((void*)X60Qx_14) == NIM_NIL))){
        result_9 = NIM_TRUE;
        NB8 done_0 = NIM_FALSE;
        {
          NI32 X60Qlf_0 = 0;
          NI32 X60Qlf_1 = ((NI32)80);
          NI32 X60Qlf_2 = X60Qlf_0;
          {
            while (X60Qlf_2 < X60Qlf_1){
              {
                NI32 X60Qx_15 = nimIcheckB(X60Qlf_2, 79);
                if (buf_2.a[X60Qx_15] == (NC8)'\000'){
                  goto forStmtLabel_1;}
                NI32 X60Qx_16 = nimIcheckB(X60Qlf_2, 79);
                if (buf_2.a[X60Qx_16] == (NC8)'\012'){
                  done_0 = NIM_TRUE;
                  goto forStmtLabel_1;}
                NI32 X60Qx_17 = nimIcheckB(X60Qlf_2, 79);
                add_1_sysvq0asl(s_2, buf_2.a[X60Qx_17]);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
          whileStmtLabel_2: ;}
        forStmtLabel_1: ;
        if (done_0){
          goto whileStmtLabel_0;}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_9;}
NB8 readLine_0_syn1lfpjv(FILE* f_26, string_0_sysvq0asl* s_3){
  NB8 result_10;
  shrink_1_sysvq0asl(s_3, 0);
  NB8 X60Qx_18 = addReadLine_0_syn1lfpjv(f_26, s_3);
  result_10 = X60Qx_18;
  return result_10;}
void quit_0_syn1lfpjv(NI32 value_0){
  cExit_0_sysvq0asl(value_0);}
void quit_1_syn1lfpjv(string_0_sysvq0asl msg_0){
  write_0_syn1lfpjv(stdout, msg_0);
  write_7_syn1lfpjv(stdout, (NC8)'\012');
  quit_0_syn1lfpjv(((NI32)1));}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 readAll_0_syn1lfpjv(FILE* f_28){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 result_11;
  result_11.fld_0 = 0;
  result_11 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1){
    .fld_0 = 0, .fld_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}}
  ;
  string_0_sysvq0asl buffer_3 = newString_0_sysvq0asl(((NI32)4000));
  {
    while (NIM_TRUE){
      NC8* X60Qx_19 = beginStore_0_sysvq0asl((&buffer_3), ((NI32)4000), 0);
      NI32 bytesRead_0 = readBuffer_0_syn1lfpjv(f_28, ((void*)X60Qx_19), ((NI32)4000));
      endStore_0_sysvq0asl((&buffer_3));
      if (bytesRead_0 == ((NI32)4000)){
        add_2_sysvq0asl((&result_11.fld_1), buffer_3);}
      else {
        setLen_1_sysvq0asl((&buffer_3), bytesRead_0);
        add_2_sysvq0asl((&result_11.fld_1), buffer_3);
        goto whileStmtLabel_0;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_20 = failed_0_syn1lfpjv(f_28);
  if (X60Qx_20){
    nimStrDestroy(buffer_3);
    return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1){
      .fld_0 = 11, .fld_1 = result_11.fld_1}
    ;}
  nimStrDestroy(buffer_3);
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1){
    .fld_0 = 0, .fld_1 = result_11.fld_1}
  ;
  nimStrDestroy(buffer_3);
  return result_11;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 readFile_0_syn1lfpjv(string_0_sysvq0asl filename_4){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 result_12;
  result_12.fld_0 = 0;
  result_12 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1){
    .fld_0 = 0, .fld_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}}
  ;
  FILE* f_37;
  NB8 X60Qx_21 = open_0_syn1lfpjv((&f_37), filename_4, 0, -1);
  if (X60Qx_21){
    X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_0 = readAll_0_syn1lfpjv(f_37);
    if (X60QcanRaise_0.fld_0){
      close_0_syn1lfpjv(f_37);
      return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1){
        .fld_0 = X60QcanRaise_0.fld_0, .fld_1 = result_12.fld_1}
      ;}
    nimStrDestroy(result_12.fld_1);
    string_0_sysvq0asl X60Qx_22 = nimStrDup(X60QcanRaise_0.fld_1);
    result_12 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1){
      .fld_0 = 0, .fld_1 = X60Qx_22}
    ;
    close_0_syn1lfpjv(f_37);}
  else {
    return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1){
      .fld_0 = 11, .fld_1 = result_12.fld_1}
    ;}
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1){
    .fld_0 = 0, .fld_1 = result_12.fld_1}
  ;}
ErrorCode_0_sysvq0asl writeFile_0_syn1lfpjv(string_0_sysvq0asl filename_5, string_0_sysvq0asl content_0){
  FILE* f_38;
  NB8 X60Qx_23 = open_0_syn1lfpjv((&f_38), filename_5, 1, -1);
  if (X60Qx_23){
    write_0_syn1lfpjv(f_38, content_0);
    close_0_syn1lfpjv(f_38);}
  else {
    return 11;}
  return 0;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 getFilePos_0_syn1lfpjv(FILE* f_34){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1 result_15;
  result_15.fld_0 = 0;
  NI64 X60Qx_28 = ftello(f_34);
  result_15 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1){
    .fld_0 = 0, .fld_1 = X60Qx_28}
  ;
  if (result_15.fld_1 < ((NI64)0)){
    return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1){
      .fld_0 = 11, .fld_1 = result_15.fld_1}
    ;}
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1){
    .fld_0 = 0, .fld_1 = result_15.fld_1}
  ;}
ErrorCode_0_sysvq0asl setFilePos_0_syn1lfpjv(FILE* f_35, NI64 pos_0, FileSeekPos_0_syn1lfpjv relativeTo_0){
  NI32 X60Qx_29 = fseeko(f_35, pos_0, ((NI32)relativeTo_0));
  if ((!(X60Qx_29 == ((NI32)0)))){
    return 11;}
  return 0;}
void X60Qini_0_syn1lfpjv(void){
  if (X60QiniGuard_0_syn1lfpjv){
    return;}
  X60QiniGuard_0_syn1lfpjv = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_for2ybv4p1();}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0){
  NC8* result_103;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_39).bytes_0))))){
    result_103 = ((NC8*)((NU32)(((NU32)(&(*(*s_39).more_0).data_0[0])) + ((NU32)start_0))));}
  else {
    result_103 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_39).bytes_0)) + 1u)))) + ((NU32)start_0))));}
  return result_103;}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline string_0_sysvq0asl terminatingZero_0_sysvq0asl(string_0_sysvq0asl s_60){
  string_0_sysvq0asl result_138;
  nimStrWasMoved((&result_138));
  nimStrDestroy(result_138);
  string_0_sysvq0asl X60Qx_309 = ampQ_0_sysvq0asl(s_60, (string_0_sysvq0asl){
    .bytes_0 = 1u, .more_0 = NIM_NIL}
  );
  result_138 = X60Qx_309;
  NI32 X60Qx_310 = len_4_sysvq0asl(s_60);
  shrink_1_sysvq0asl((&result_138), X60Qx_310);
  return result_138;}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void endStore_0_sysvq0asl(string_0_sysvq0asl* s_48){
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_48).bytes_0))))){
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_48).bytes_0)) + 1u)))), ((void*)(&(*(*s_48).more_0).data_0[0])), ((NI32)3));}}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
