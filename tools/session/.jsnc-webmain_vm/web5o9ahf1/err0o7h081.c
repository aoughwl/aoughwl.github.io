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
extern void X60Qini_0_sysvq0asl(void);
NB8 X60QiniGuard_0_err0o7h081;
ErrorCode_0_sysvq0asl posixToErrorCode_0_err0o7h081(NI32 err_0){
  ErrorCode_0_sysvq0asl result_0;
  ErrorCode_0_sysvq0asl X60Qx_0;
  if (err_0 == ((NI32)0)){
    X60Qx_0 = 0;}
  else {
    if (err_0 == EOVERFLOW){
      X60Qx_0 = 1;}
    else {
      NB8 X60Qx_2;
      if (err_0 == ERANGE){
        X60Qx_2 = NIM_TRUE;}
      else {
        X60Qx_2 = (err_0 == EDOM);}
      if (X60Qx_2){
        X60Qx_0 = 5;}
      else {
        if (err_0 == ENOMEM){
          X60Qx_0 = 8;}
        else {
          if (err_0 == ENOSPC){
            X60Qx_0 = 9;}
          else {
            if (err_0 == EIO){
              X60Qx_0 = 11;}
            else {
              NB8 X60Qx_3;
              NB8 X60Qx_4;
              NB8 X60Qx_5;
              NB8 X60Qx_6;
              if (err_0 == EINVAL){
                X60Qx_6 = NIM_TRUE;}
              else {
                X60Qx_6 = (err_0 == EBADMSG);}
              if (X60Qx_6){
                X60Qx_5 = NIM_TRUE;}
              else {
                X60Qx_5 = (err_0 == EILSEQ);}
              if (X60Qx_5){
                X60Qx_4 = NIM_TRUE;}
              else {
                X60Qx_4 = (err_0 == ENOMSG);}
              if (X60Qx_4){
                X60Qx_3 = NIM_TRUE;}
              else {
                X60Qx_3 = (err_0 == EDESTADDRREQ);}
              if (X60Qx_3){
                X60Qx_0 = 12;}
              else {
                NB8 X60Qx_7;
                if (err_0 == E2BIG){
                  X60Qx_7 = NIM_TRUE;}
                else {
                  X60Qx_7 = (err_0 == ENOBUFS);}
                if (X60Qx_7){
                  X60Qx_0 = 16;}
                else {
                  if (err_0 == ENODATA){
                    X60Qx_0 = 17;}
                  else {
                    NB8 X60Qx_8;
                    if (err_0 == EBUSY){
                      X60Qx_8 = NIM_TRUE;}
                    else {
                      X60Qx_8 = (err_0 == ETXTBSY);}
                    if (X60Qx_8){
                      X60Qx_0 = 18;}
                    else {
                      NB8 X60Qx_9;
                      if (err_0 == ECHILD){
                        X60Qx_9 = NIM_TRUE;}
                      else {
                        X60Qx_9 = (err_0 == EOWNERDEAD);}
                      if (X60Qx_9){
                        X60Qx_0 = 19;}
                      else {
                        if (err_0 == ENOLCK){
                          X60Qx_0 = 20;}
                        else {
                          if (err_0 == ENFILE){
                            X60Qx_0 = 21;}
                          else {
                            NB8 X60Qx_10;
                            if (err_0 == EACCES){
                              X60Qx_10 = NIM_TRUE;}
                            else {
                              X60Qx_10 = (err_0 == EPERM);}
                            if (X60Qx_10){
                              X60Qx_0 = 22;}
                            else {
                              NB8 X60Qx_11;
                              if (err_0 == EAGAIN){
                                X60Qx_11 = NIM_TRUE;}
                              else {
                                X60Qx_11 = (err_0 == EWOULDBLOCK);}
                              if (X60Qx_11){
                                X60Qx_0 = 23;}
                              else {
                                NB8 X60Qx_12;
                                if (err_0 == ETIMEDOUT){
                                  X60Qx_12 = NIM_TRUE;}
                                else {
                                  X60Qx_12 = (err_0 == ETIME);}
                                if (X60Qx_12){
                                  X60Qx_0 = 24;}
                                else {
                                  if (err_0 == EINTR){
                                    X60Qx_0 = 25;}
                                  else {
                                    if (err_0 == EDEADLK){
                                      X60Qx_0 = 26;}
                                    else {
                                      NB8 X60Qx_13;
                                      if (err_0 == EADDRINUSE){
                                        X60Qx_13 = NIM_TRUE;}
                                      else {
                                        X60Qx_13 = (err_0 == EISCONN);}
                                      if (X60Qx_13){
                                        X60Qx_0 = 29;}
                                      else {
                                        if (err_0 == EADDRNOTAVAIL){
                                          X60Qx_0 = 30;}
                                        else {
                                          if (err_0 == EAFNOSUPPORT){
                                            X60Qx_0 = 31;}
                                          else {
                                            NB8 X60Qx_14;
                                            NB8 X60Qx_15;
                                            NB8 X60Qx_16;
                                            NB8 X60Qx_17;
                                            NB8 X60Qx_18;
                                            NB8 X60Qx_19;
                                            NB8 X60Qx_20;
                                            if (err_0 == EOPNOTSUPP){
                                              X60Qx_20 = NIM_TRUE;}
                                            else {
                                              X60Qx_20 = (err_0 == ENOTSUP);}
                                            if (X60Qx_20){
                                              X60Qx_19 = NIM_TRUE;}
                                            else {
                                              X60Qx_19 = (err_0 == ENOSYS);}
                                            if (X60Qx_19){
                                              X60Qx_18 = NIM_TRUE;}
                                            else {
                                              X60Qx_18 = (err_0 == EPROTONOSUPPORT);}
                                            if (X60Qx_18){
                                              X60Qx_17 = NIM_TRUE;}
                                            else {
                                              X60Qx_17 = (err_0 == ENOTTY);}
                                            if (X60Qx_17){
                                              X60Qx_16 = NIM_TRUE;}
                                            else {
                                              X60Qx_16 = (err_0 == ESPIPE);}
                                            if (X60Qx_16){
                                              X60Qx_15 = NIM_TRUE;}
                                            else {
                                              X60Qx_15 = (err_0 == EISDIR);}
                                            if (X60Qx_15){
                                              X60Qx_14 = NIM_TRUE;}
                                            else {
                                              X60Qx_14 = (err_0 == ENOTEMPTY);}
                                            if (X60Qx_14){
                                              X60Qx_0 = 32;}
                                            else {
                                              NB8 X60Qx_21;
                                              NB8 X60Qx_22;
                                              if (err_0 == ECANCELED){
                                                X60Qx_22 = NIM_TRUE;}
                                              else {
                                                X60Qx_22 = (err_0 == ECONNABORTED);}
                                              if (X60Qx_22){
                                                X60Qx_21 = NIM_TRUE;}
                                              else {
                                                X60Qx_21 = (err_0 == ENETRESET);}
                                              if (X60Qx_21){
                                                X60Qx_0 = 33;}
                                              else {
                                                NB8 X60Qx_23;
                                                if (err_0 == EALREADY){
                                                  X60Qx_23 = NIM_TRUE;}
                                                else {
                                                  X60Qx_23 = (err_0 == EINPROGRESS);}
                                                if (X60Qx_23){
                                                  X60Qx_0 = 35;}
                                                else {
                                                  if (err_0 == ENAMETOOLONG){
                                                    X60Qx_0 = 36;}
                                                  else {
                                                    if (err_0 == EEXIST){
                                                      X60Qx_0 = 37;}
                                                    else {
                                                      NB8 X60Qx_24;
                                                      NB8 X60Qx_25;
                                                      NB8 X60Qx_26;
                                                      if (err_0 == ENOENT){
                                                        X60Qx_26 = NIM_TRUE;}
                                                      else {
                                                        X60Qx_26 = (err_0 == EIDRM);}
                                                      if (X60Qx_26){
                                                        X60Qx_25 = NIM_TRUE;}
                                                      else {
                                                        X60Qx_25 = (err_0 == ENODEV);}
                                                      if (X60Qx_25){
                                                        X60Qx_24 = NIM_TRUE;}
                                                      else {
                                                        X60Qx_24 = (err_0 == ENOTDIR);}
                                                      if (X60Qx_24){
                                                        X60Qx_0 = 38;}
                                                      else {
                                                        NB8 X60Qx_27;
                                                        if (err_0 == EFBIG){
                                                          X60Qx_27 = NIM_TRUE;}
                                                        else {
                                                          X60Qx_27 = (err_0 == EMSGSIZE);}
                                                        if (X60Qx_27){
                                                          X60Qx_0 = 39;}
                                                        else {
                                                          NB8 X60Qx_28;
                                                          NB8 X60Qx_29;
                                                          NB8 X60Qx_30;
                                                          NB8 X60Qx_31;
                                                          NB8 X60Qx_32;
                                                          NB8 X60Qx_33;
                                                          NB8 X60Qx_34;
                                                          if (err_0 == EPIPE){
                                                            X60Qx_34 = NIM_TRUE;}
                                                          else {
                                                            X60Qx_34 = (err_0 == EBADF);}
                                                          if (X60Qx_34){
                                                            X60Qx_33 = NIM_TRUE;}
                                                          else {
                                                            X60Qx_33 = (err_0 == EMFILE);}
                                                          if (X60Qx_33){
                                                            X60Qx_32 = NIM_TRUE;}
                                                          else {
                                                            X60Qx_32 = (err_0 == ENOSTR);}
                                                          if (X60Qx_32){
                                                            X60Qx_31 = NIM_TRUE;}
                                                          else {
                                                            X60Qx_31 = (err_0 == ENOTSOCK);}
                                                          if (X60Qx_31){
                                                            X60Qx_30 = NIM_TRUE;}
                                                          else {
                                                            X60Qx_30 = (err_0 == ENOSR);}
                                                          if (X60Qx_30){
                                                            X60Qx_29 = NIM_TRUE;}
                                                          else {
                                                            X60Qx_29 = (err_0 == ENXIO);}
                                                          if (X60Qx_29){
                                                            X60Qx_28 = NIM_TRUE;}
                                                          else {
                                                            X60Qx_28 = (err_0 == ESRCH);}
                                                          if (X60Qx_28){
                                                            X60Qx_0 = 40;}
                                                          else {
                                                            if (err_0 == ENOEXEC){
                                                              X60Qx_0 = 41;}
                                                            else {
                                                              NB8 X60Qx_35;
                                                              NB8 X60Qx_36;
                                                              if (err_0 == ELOOP){
                                                                X60Qx_36 = NIM_TRUE;}
                                                              else {
                                                                X60Qx_36 = (err_0 == EMLINK);}
                                                              if (X60Qx_36){
                                                                X60Qx_35 = NIM_TRUE;}
                                                              else {
                                                                X60Qx_35 = (err_0 == EXDEV);}
                                                              if (X60Qx_35){
                                                                X60Qx_0 = 42;}
                                                              else {
                                                                NB8 X60Qx_37;
                                                                if (err_0 == EPROTOTYPE){
                                                                  X60Qx_37 = NIM_TRUE;}
                                                                else {
                                                                  X60Qx_37 = (err_0 == ENOPROTOOPT);}
                                                                if (X60Qx_37){
                                                                  X60Qx_0 = 43;}
                                                                else {
                                                                  if (err_0 == EPROTO){
                                                                    X60Qx_0 = 44;}
                                                                  else {
                                                                    if (err_0 == EROFS){
                                                                      X60Qx_0 = 45;}
                                                                    else {
                                                                      if (err_0 == EFAULT){
                                                                        X60Qx_0 = 46;}
                                                                      else {
                                                                        NB8 X60Qx_38;
                                                                        NB8 X60Qx_39;
                                                                        NB8 X60Qx_40;
                                                                        if (err_0 == ENETDOWN){
                                                                          X60Qx_40 = NIM_TRUE;}
                                                                        else {
                                                                          X60Qx_40 = (err_0 == ENETUNREACH);}
                                                                        if (X60Qx_40){
                                                                          X60Qx_39 = NIM_TRUE;}
                                                                        else {
                                                                          X60Qx_39 = (err_0 == ECONNRESET);}
                                                                        if (X60Qx_39){
                                                                          X60Qx_38 = NIM_TRUE;}
                                                                        else {
                                                                          X60Qx_38 = (err_0 == ENOTCONN);}
                                                                        if (X60Qx_38){
                                                                          X60Qx_0 = 48;}
                                                                        else {
                                                                          if (err_0 == ECONNREFUSED){
                                                                            X60Qx_0 = 49;}
                                                                          else {
                                                                            if (err_0 == EHOSTUNREACH){
                                                                              X60Qx_0 = 50;}
                                                                            else {
                                                                              if (err_0 == ENOTRECOVERABLE){
                                                                                X60Qx_0 = 51;}
                                                                              else {
                                                                                X60Qx_0 = 2;}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
  result_0 = X60Qx_0;
  return result_0;}
void X60Qini_0_err0o7h081(void){
  if (X60QiniGuard_0_err0o7h081){
    return;}
  X60QiniGuard_0_err0o7h081 = NIM_TRUE;
  X60Qini_0_sysvq0asl();}
