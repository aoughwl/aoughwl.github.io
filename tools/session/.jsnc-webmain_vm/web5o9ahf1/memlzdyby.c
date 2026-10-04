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
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <time.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct MemFile_0_memlzdyby{
  void* mem_0;
  NI32 size_0;
  int handle_0;
  int flags_0;}
MemFile_0_memlzdyby;
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
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby{
  ErrorCode_0_sysvq0asl fld_0;
  MemFile_0_memlzdyby fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef NU8 FileMode_0_syn1lfpjv;

#define fmRead_0_syn1lfpjv ((NU8)0)
#define fmWrite_0_syn1lfpjv ((NU8)1)
#define fmReadWrite_0_syn1lfpjv ((NU8)2)
#define fmReadWriteExisting_0_syn1lfpjv ((NU8)3)
#define fmAppend_0_syn1lfpjv ((NU8)4)
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern NC8* toCString_0_sysvq0asl(string_0_sysvq0asl* s_64);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern ErrorCode_0_sysvq0asl raiseOSError_0_osezuyu63(NI32 errorCode_0, string_0_sysvq0asl additionalInfo_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_osezuyu63(void);
extern void X60Qini_0_pososrh1q1(void);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
LongString_0_sysvq0asl const strlit_0_I16389858666611951575_memlzdyby = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "error setting file size"}
;
LongString_0_sysvq0asl const strlit_0_I1292912936016310246_memlzdyby = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "error opening file"}
;
LongString_0_sysvq0asl const strlit_0_I1842668082708011872_memlzdyby = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "error getting file size"}
;
LongString_0_sysvq0asl const strlit_0_I164760095516170388_memlzdyby = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "file mapping failed"}
;
NB8 X60QiniGuard_0_memlzdyby;
NI32 setFileSize_0_memlzdyby(int fh_0, NI32 newFileSize_0, NI32 oldSize_0){
  NI32 result_0;
  result_0 = ((NI32)0);
  NB8 X60Qx_12;
  if (newFileSize_0 < 0){
    X60Qx_12 = NIM_TRUE;}
  else {
    X60Qx_12 = (newFileSize_0 == oldSize_0);}
  if (X60Qx_12){
    return result_0;}
  if (oldSize_0 < newFileSize_0){
    int e_0 = ((int)0);
    {
      while (NIM_TRUE){
        int X60Qx_13 = posix_fallocate(fh_0, ((off_t)0), ((off_t)newFileSize_0));
        e_0 = X60Qx_13;
        if (e_0 == ((NI32)4)){
          }
        else {
          break;}}}
    whileStmtLabel_0: ;
    NB8 X60Qx_14;
    if (e_0 == ((NI32)22)){
      X60Qx_14 = NIM_TRUE;}
    else {
      X60Qx_14 = (e_0 == ((NI32)95));}
    if (X60Qx_14){
      int X60Qx_15 = ftruncate(fh_0, ((off_t)newFileSize_0));
      long r_1 = ((long)X60Qx_15);
      long X60Qx_0;
      if (r_1 < 0){
        X60Qx_0 = ((long)((NI32)-errno));}
      else {
        X60Qx_0 = r_1;}
      long r_0 = X60Qx_0;
      if (r_0 < 0){
        result_0 = ((NI32)((NI32)((NI32)(0 - r_0))));}}
    else {
      if ((!(e_0 == 0))){
        result_0 = ((NI32)e_0);}}}
  else {
    int X60Qx_16 = ftruncate(((int)fh_0), ((off_t)newFileSize_0));
    long r_3 = ((long)X60Qx_16);
    long X60Qx_1;
    if (r_3 < 0){
      X60Qx_1 = ((long)((NI32)-errno));}
    else {
      X60Qx_1 = r_3;}
    long r_2 = X60Qx_1;
    if (r_2 < 0){
      result_0 = ((NI32)((NI32)((NI32)(0 - r_2))));}}
  return result_0;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby open_0_memlzdyby(string_0_sysvq0asl filename_0, FileMode_0_syn1lfpjv mode_0, NI32 mappedSize_0, NI32 offset_0, NI32 newFileSize_1, NB8 allowRemap_0, int mapFlags_0){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby result_1;
  result_1.fld_0 = 0;
  result_1 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby){
    .fld_0 = 0, .fld_1 = (MemFile_0_memlzdyby){
      .mem_0 = NIM_NIL, .size_0 = ((NI32)0), .handle_0 = ((NI32)0), .flags_0 = ((NI32)0)}}
  ;
  if (mode_0 == 4){
    return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby){
      .fld_0 = 32, .fld_1 = result_1.fld_1}
    ;}
  NB8 X60Qx_17;
  if (newFileSize_1 == -1){
    X60Qx_17 = NIM_TRUE;}
  else {
    X60Qx_17 = (!(mode_0 == 0));}
  if ((!X60Qx_17)){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NB8 readonly_0 = (mode_0 == 0);
  int X60Qx_2;
  if (readonly_0){
    X60Qx_2 = ((NI32)0);}
  else {
    X60Qx_2 = ((NI32)2);}
  NI32 flags_0 = ((NI32)(X60Qx_2 | ((NI32)524288)));
  if ((!(newFileSize_1 == -1))){
    flags_0 = ((NI32)(((NI32)(flags_0 | ((NI32)64))) | ((NI32)512)));
    mode_t permissionsMode_0 = ((mode_t)((NI32)(((NI32)256) | ((NI32)128))));
    string_0_sysvq0asl filename_1 = nimStrDup(filename_0);
    NC8* fc_0 = toCString_0_sysvq0asl((&filename_1));
    if (((void*)((void*)fc_0)) == NIM_NIL){
      nimStrDestroy(filename_1);
      return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby){
        .fld_0 = 8, .fld_1 = result_1.fld_1}
      ;}
    int X60Qx_18 = open(fc_0, flags_0, permissionsMode_0);
    long r_4 = ((long)X60Qx_18);
    long X60Qx_3;
    if (r_4 < 0){
      X60Qx_3 = ((long)((NI32)-errno));}
    else {
      X60Qx_3 = r_4;}
    result_1.fld_1.handle_0 = ((int)X60Qx_3);
    if (0 <= result_1.fld_1.handle_0){
      NI32 e_1 = setFileSize_0_memlzdyby(result_1.fld_1.handle_0, newFileSize_1, -1);
      if ((!(e_1 == ((NI32)0)))){
        result_1.fld_1.mem_0 = NIM_NIL;
        result_1.fld_1.size_0 = 0;
        if (0 <= result_1.fld_1.handle_0){
          int X60Qx_19 = close(result_1.fld_1.handle_0);}
        ErrorCode_0_sysvq0asl X60QcanRaise_0 = raiseOSError_0_osezuyu63(e_1, (string_0_sysvq0asl){
          .bytes_0 = 1920099838u, .more_0 = (&strlit_0_I16389858666611951575_memlzdyby)}
        );
        if (X60QcanRaise_0){
          nimStrDestroy(filename_1);
          return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby){
            .fld_0 = X60QcanRaise_0, .fld_1 = result_1.fld_1}
          ;}}}
    nimStrDestroy(filename_1);}
  else {
    string_0_sysvq0asl filename_2 = nimStrDup(filename_0);
    NC8* fc_1 = toCString_0_sysvq0asl((&filename_2));
    if (((void*)((void*)fc_1)) == NIM_NIL){
      nimStrDestroy(filename_2);
      return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby){
        .fld_0 = 8, .fld_1 = result_1.fld_1}
      ;}
    int X60Qx_20 = open(fc_1, flags_0);
    long r_5 = ((long)X60Qx_20);
    long X60Qx_4;
    if (r_5 < 0){
      X60Qx_4 = ((long)((NI32)-errno));}
    else {
      X60Qx_4 = r_5;}
    result_1.fld_1.handle_0 = ((int)X60Qx_4);
    nimStrDestroy(filename_2);}
  if (result_1.fld_1.handle_0 < 0){
    result_1.fld_1.mem_0 = NIM_NIL;
    result_1.fld_1.size_0 = 0;
    if (0 <= result_1.fld_1.handle_0){
      int X60Qx_21 = close(result_1.fld_1.handle_0);}
    ErrorCode_0_sysvq0asl X60QcanRaise_1 = raiseOSError_0_osezuyu63(((NI32)((NI32)((NI32)(0 - result_1.fld_1.handle_0)))), (string_0_sysvq0asl){
      .bytes_0 = 1920099838u, .more_0 = (&strlit_0_I1292912936016310246_memlzdyby)}
    );
    if (X60QcanRaise_1){
      return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby){
        .fld_0 = X60QcanRaise_1, .fld_1 = result_1.fld_1}
      ;}}
  if ((!(mappedSize_0 == -1))){
    result_1.fld_1.size_0 = mappedSize_0;}
  else {
    struct stat stat_0 = (struct stat){
      .st_dev = ((NU32)0u), .st_ino = ((NU32)0u), .st_size = ((NI64)0), .st_mode = ((NU32)0u), .st_mtime = ((NI64)0), .st_mtim = (struct timespec){
        .tv_sec = ((NI32)0), .tv_nsec = ((NI32)0)}}
    ;
    int X60Qx_22 = fstat(result_1.fld_1.handle_0, (&stat_0));
    long r_6 = ((long)X60Qx_22);
    long X60Qx_5;
    if (r_6 < 0){
      X60Qx_5 = ((long)((NI32)-errno));}
    else {
      X60Qx_5 = r_6;}
    long sr_0 = X60Qx_5;
    if (0 <= sr_0){
      result_1.fld_1.size_0 = ((NI32)stat_0.st_size);}
    else {
      result_1.fld_1.mem_0 = NIM_NIL;
      result_1.fld_1.size_0 = 0;
      if (0 <= result_1.fld_1.handle_0){
        int X60Qx_23 = close(result_1.fld_1.handle_0);}
      ErrorCode_0_sysvq0asl X60QcanRaise_2 = raiseOSError_0_osezuyu63(((NI32)((NI32)((NI32)(0 - sr_0)))), (string_0_sysvq0asl){
        .bytes_0 = 1920099838u, .more_0 = (&strlit_0_I1842668082708011872_memlzdyby)}
      );
      if (X60QcanRaise_2){
        return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby){
          .fld_0 = X60QcanRaise_2, .fld_1 = result_1.fld_1}
        ;}}}
  int X60Qx_6;
  if (mapFlags_0 == ((int)-1)){
    X60Qx_6 = ((NI32)1);}
  else {
    X60Qx_6 = mapFlags_0;}
  result_1.fld_1.flags_0 = X60Qx_6;
  if (((NI32)((NI32)(result_1.fld_1.flags_0 & ((NI32)2)))) == 0){
    result_1.fld_1.flags_0 = ((NI32)(result_1.fld_1.flags_0 | ((NI32)1)));}
  int X60Qx_7;
  if (readonly_0){
    X60Qx_7 = ((NI32)1);}
  else {
    X60Qx_7 = ((NI32)(((NI32)1) | ((NI32)2)));}
  int pr_0 = X60Qx_7;
  void* X60Qx_24 = mmap(NIM_NIL, result_1.fld_1.size_0, pr_0, result_1.fld_1.flags_0, result_1.fld_1.handle_0, ((off_t)offset_0));
  result_1.fld_1.mem_0 = X60Qx_24;
  NB8 X60Qx_25;
  if (-4095 <= ((NI32)result_1.fld_1.mem_0)){
    X60Qx_25 = (((NI32)result_1.fld_1.mem_0) <= -1);}
  else {
    X60Qx_25 = NIM_FALSE;}
  if (X60Qx_25){
    result_1.fld_1.mem_0 = NIM_NIL;
    result_1.fld_1.size_0 = 0;
    if (0 <= result_1.fld_1.handle_0){
      int X60Qx_26 = close(result_1.fld_1.handle_0);}
    ErrorCode_0_sysvq0asl X60QcanRaise_3 = raiseOSError_0_osezuyu63(((NI32)errno), (string_0_sysvq0asl){
      .bytes_0 = 1818846974u, .more_0 = (&strlit_0_I164760095516170388_memlzdyby)}
    );
    if (X60QcanRaise_3){
      return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby){
        .fld_0 = X60QcanRaise_3, .fld_1 = result_1.fld_1}
      ;}}
  NB8 X60Qx_27;
  if ((!allowRemap_0)){
    X60Qx_27 = (0 <= result_1.fld_1.handle_0);}
  else {
    X60Qx_27 = NIM_FALSE;}
  if (X60Qx_27){
    int X60Qx_28 = close(result_1.fld_1.handle_0);
    long r_8 = ((long)X60Qx_28);
    long X60Qx_8;
    if (r_8 < 0){
      X60Qx_8 = ((long)((NI32)-errno));}
    else {
      X60Qx_8 = r_8;}
    if (0 <= X60Qx_8){
      result_1.fld_1.handle_0 = -1;}}
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby){
    .fld_0 = 0, .fld_1 = result_1.fld_1}
  ;}
ErrorCode_0_sysvq0asl close_0_memlzdyby(MemFile_0_memlzdyby* f_0){
  NB8 error_0 = NIM_FALSE;
  NI32 lastErr_0;
  int X60Qx_29 = munmap((*f_0).mem_0, (*f_0).size_0);
  long r_9 = ((long)X60Qx_29);
  long X60Qx_9;
  if (r_9 < 0){
    X60Qx_9 = ((long)((NI32)-errno));}
  else {
    X60Qx_9 = r_9;}
  long mr_0 = X60Qx_9;
  error_0 = (mr_0 < 0);
  NI32 X60Qx_10;
  if (mr_0 < 0){
    X60Qx_10 = ((NI32)((NI32)((NI32)(0 - mr_0))));}
  else {
    X60Qx_10 = ((NI32)0);}
  lastErr_0 = X60Qx_10;
  if (0 <= (*f_0).handle_0){
    int X60Qx_30 = close((*f_0).handle_0);
    long r_10 = ((long)X60Qx_30);
    long X60Qx_11;
    if (r_10 < 0){
      X60Qx_11 = ((long)((NI32)-errno));}
    else {
      X60Qx_11 = r_10;}
    long cr_0 = X60Qx_11;
    if (cr_0 < 0){
      error_0 = NIM_TRUE;
      lastErr_0 = ((NI32)((NI32)((NI32)(0 - cr_0))));}}
  (*f_0).size_0 = 0;
  (*f_0).mem_0 = NIM_NIL;
  (*f_0).handle_0 = -1;
  if (error_0){
    ErrorCode_0_sysvq0asl X60QcanRaise_0 = raiseOSError_0_osezuyu63(lastErr_0, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    if (X60QcanRaise_0){
      return X60QcanRaise_0;}}
  return 0;}
void X60Qini_0_memlzdyby(void){
  if (X60QiniGuard_0_memlzdyby){
    return;}
  X60QiniGuard_0_memlzdyby = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_assy765wm();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_osezuyu63();
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
