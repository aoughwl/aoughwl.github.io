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
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct JEvent_0_jou8favxh1 JEvent_0_jou8favxh1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct JEvent_0_jou8favxh1{
  string_0_sysvq0asl kind_0;
  string_0_sysvq0asl key_0;
  seq_0_Ixdx2fh1_ast8ri79k fields_0;}
JEvent_0_jou8favxh1;
typedef struct seq_0_I467rk41_jou8favxh1{
  NI32 len_0;
  JEvent_0_jou8favxh1* data_0;}
seq_0_I467rk41_jou8favxh1;
typedef struct X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11{
  NC8 a[65536];}
X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11;
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
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline void add_0_Ixpq8s01_jou8favxh1(seq_0_I467rk41_jou8favxh1* s_14, JEvent_0_jou8favxh1 elem_3);
static inline NI32 len_3_Ijmyd9p1_jou8favxh1(seq_0_I467rk41_jou8favxh1 s_16);
static inline JEvent_0_jou8favxh1* getQ_7_Ilovtk3_jou8favxh1(seq_0_I467rk41_jou8favxh1 s_17, NI32 i_18);
static inline NI32 memSizeInBytes_0_I6i476p1_jou8favxh1(NI32 size_6);
static inline NI32 capInBytes_0_I8iriqw_jou8favxh1(seq_0_I467rk41_jou8favxh1 s_19);
NB8 resize_0_Ikutmw21_jou8favxh1(seq_0_I467rk41_jou8favxh1* dest_3, NI32 addedElements_3);
void eQdestroyQ_SX4aX45vent0jou8favxh1_0_jou8favxh1(JEvent_0_jou8favxh1 dest_0);
void eQwasmovedQ_SX4aX45vent0jou8favxh1_0_jou8favxh1(JEvent_0_jou8favxh1* dest_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline seq_0_Ixdx2fh1_ast8ri79k newSeqUninit_0_Im3cqd9_ast8ri79k(NI32 size_20);
static inline NI32 len_3_Ixq6taz_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_130);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5);
static inline void add_0_Ig6072n_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_20, string_0_sysvq0asl elem_3);
static inline void eQwasMoved_1_I5vdnla_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_47);
extern void eQdestroy_1_Ivioh0a_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_46);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern NB8 open_0_syn1lfpjv(FILE** f_22, string_0_sysvq0asl filename_1, FileMode_0_syn1lfpjv mode_2, NI32 bufSize_0);
static inline X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 default_23_Isnz07p_hos5i19e11(void);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
extern NI32 readBuffer_0_syn1lfpjv(FILE* f_18, void* buffer_1, NI32 size_3);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
extern void close_0_syn1lfpjv(FILE* f_16);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_envto7w6l1(void);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NI32 memSizeInBytes_0_I7me00i_ast8ri79k(NI32 size_4);
static inline NI32 capInBytes_0_Ih2sbn01_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_28);
extern NB8 resize_0_I4buliy_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* dest_2, NI32 addedElements_2);
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I12481102836346023039_jou8favxh1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<cwd>"}
;
LongString_0_sysvq0asl const strlit_0_I5108244652392725038_jou8favxh1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<cwd>/"}
;
LongString_0_sysvq0asl const strlit_0_I15594291411169668529_jou8favxh1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<home>"}
;
LongString_0_sysvq0asl const strlit_0_I259198575133589317_jou8favxh1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<home>/"}
;
LongString_0_sysvq0asl const strlit_0_I6215679874670304319_jou8favxh1 = {
  .fullLen_0 = 70, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli: REPLAY DIVERGENCE \342\200\224 the run asked the host for something the\012"}
;
LongString_0_sysvq0asl const strlit_0_I18059250407093429845_jou8favxh1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "       journal \'"}
;
LongString_0_sysvq0asl const strlit_0_I2366269965781815703_jou8favxh1 = {
  .fullLen_0 = 42, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' cannot answer. Refusing to fall through\012"}
;
LongString_0_sysvq0asl const strlit_0_I4156614902080285430_jou8favxh1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "       to the real OS.\012"}
;
LongString_0_sysvq0asl const strlit_0_I2378533904818905159_jou8favxh1 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  journal EXHAUSTED: all "}
;
LongString_0_sysvq0asl const strlit_0_I11713221633288736133_jou8favxh1 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " recorded event(s) consumed.\012"}
;
LongString_0_sysvq0asl const strlit_0_I10986452433485484482_jou8favxh1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  asked for : "}
;
LongString_0_sysvq0asl const strlit_0_I15929356284961791821_jou8favxh1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  at event #"}
;
LongString_0_sysvq0asl const strlit_0_I8474398651341962338_jou8favxh1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " of "}
;
LongString_0_sysvq0asl const strlit_0_I11780180728635778377_jou8favxh1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  journal has: "}
;
LongString_0_sysvq0asl const strlit_0_I10049178917842299699_jou8favxh1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  asked for  : "}
;
LongString_0_sysvq0asl const strlit_0_I2341417231474813780_jou8favxh1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "header"}
;
NI32 gMode_0_jou8favxh1 = 0;
seq_0_I467rk41_jou8favxh1 gEvents_0_jou8favxh1;
NI32 gPos_0_jou8favxh1 = 0;
string_0_sysvq0asl gPath_0_jou8favxh1 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
string_0_sysvq0asl gCwd_0_jou8favxh1 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
string_0_sysvq0asl gHome_0_jou8favxh1 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
seq_0_Ixdx2fh1_ast8ri79k gArgv_0_jou8favxh1;
NB8 X60QiniGuard_0_jou8favxh1;
NB8 journalRecording_0_jou8favxh1(void){
  NB8 result_1;
  result_1 = (gMode_0_jou8favxh1 == 1);
  return result_1;}
NB8 journalReplaying_0_jou8favxh1(void){
  NB8 result_2;
  result_2 = (gMode_0_jou8favxh1 == 2);
  return result_2;}
NI32 jInt_0_jou8favxh1(string_0_sysvq0asl s_2){
  NI32 result_6;
  result_6 = 0;
  NI32 i_3 = 0;
  NB8 neg_0 = NIM_FALSE;
  NB8 X60Qx_33;
  NI32 X60Qx_34 = len_4_sysvq0asl(s_2);
  if (i_3 < X60Qx_34){
    NC8 X60Qx_35 = getQ_9_sysvq0asl(s_2, i_3);
    X60Qx_33 = (X60Qx_35 == (NC8)'-');}
  else {
    X60Qx_33 = NIM_FALSE;}
  if (X60Qx_33){
    neg_0 = NIM_TRUE;
    inc_1_I6wjjge_aow2h993l1((&i_3));}
  {
    while (NIM_TRUE){
      NB8 X60Qx_36;
      NB8 X60Qx_37;
      NI32 X60Qx_38 = len_4_sysvq0asl(s_2);
      if (i_3 < X60Qx_38){
        NC8 X60Qx_39 = getQ_9_sysvq0asl(s_2, i_3);
        X60Qx_37 = ((NC8)'0' <= X60Qx_39);}
      else {
        X60Qx_37 = NIM_FALSE;}
      if (X60Qx_37){
        NC8 X60Qx_40 = getQ_9_sysvq0asl(s_2, i_3);
        X60Qx_36 = (X60Qx_40 <= (NC8)'9');}
      else {
        X60Qx_36 = NIM_FALSE;}
      if (X60Qx_36){
        NC8 X60Qx_41 = getQ_9_sysvq0asl(s_2, i_3);
        result_6 = ((NI32)(((NI32)(result_6 * 10)) + ((NI32)(((NI32)X60Qx_41) - ((NI32)(NC8)'0')))));
        inc_1_I6wjjge_aow2h993l1((&i_3));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (neg_0){
    result_6 = ((NI32)-result_6);}
  return result_6;}
NB8 startsWithStr_0_jou8favxh1(string_0_sysvq0asl s_3, string_0_sysvq0asl p_0){
  NB8 result_7;
  NB8 X60Qx_42;
  NI32 X60Qx_43 = len_4_sysvq0asl(p_0);
  if (X60Qx_43 == 0){
    X60Qx_42 = NIM_TRUE;}
  else {
    NI32 X60Qx_44 = len_4_sysvq0asl(s_3);
    NI32 X60Qx_45 = len_4_sysvq0asl(p_0);
    X60Qx_42 = (X60Qx_44 < X60Qx_45);}
  if (X60Qx_42){
    return NIM_FALSE;}
  NI32 i_4 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_46 = len_4_sysvq0asl(p_0);
      if (i_4 < X60Qx_46){
        NC8 X60Qx_47 = getQ_9_sysvq0asl(s_3, i_4);
        NC8 X60Qx_48 = getQ_9_sysvq0asl(p_0, i_4);
        if ((!(X60Qx_47 == X60Qx_48))){
          return NIM_FALSE;}
        inc_1_I6wjjge_aow2h993l1((&i_4));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_7 = NIM_TRUE;
  return result_7;}
string_0_sysvq0asl portPath_0_jou8favxh1(string_0_sysvq0asl p_1){
  string_0_sysvq0asl result_8;
  nimStrWasMoved((&result_8));
  NI32 X60Qx_49 = len_4_sysvq0asl(p_1);
  if (X60Qx_49 == 0){
    string_0_sysvq0asl X60Qx_50 = nimStrDup(p_1);
    return X60Qx_50;}
  NI32 X60Qx_51 = len_4_sysvq0asl(gCwd_0_jou8favxh1);
  if (0 < X60Qx_51){
    NB8 X60Qx_52 = eqQ_20_sysvq0asl(p_1, gCwd_0_jou8favxh1);
    if (X60Qx_52){
      return (string_0_sysvq0asl){
        .bytes_0 = 2002992382u, .more_0 = (&strlit_0_I12481102836346023039_jou8favxh1)}
      ;}
    string_0_sysvq0asl X60Qtmp_0 = ampQ_0_sysvq0asl(gCwd_0_jou8favxh1, (string_0_sysvq0asl){
      .bytes_0 = 12033u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_53 = startsWithStr_0_jou8favxh1(p_1, X60Qtmp_0);
    if (X60Qx_53){
      NI32 X60Qx_54 = len_4_sysvq0asl(gCwd_0_jou8favxh1);
      NI32 X60Qx_55 = len_4_sysvq0asl(p_1);
      string_0_sysvq0asl X60Qtmp_1 = substr_0_sysvq0asl(p_1, ((NI32)(X60Qx_54 + 1)), ((NI32)(X60Qx_55 - 1)));
      string_0_sysvq0asl X60Qx_56 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2002992382u, .more_0 = (&strlit_0_I5108244652392725038_jou8favxh1)}
      , X60Qtmp_1);
      result_8 = X60Qx_56;
      nimStrDestroy(X60Qtmp_1);
      nimStrDestroy(X60Qtmp_0);
      return result_8;
      nimStrDestroy(X60Qtmp_1);}
    nimStrDestroy(X60Qtmp_0);}
  NI32 X60Qx_57 = len_4_sysvq0asl(gHome_0_jou8favxh1);
  if (0 < X60Qx_57){
    NB8 X60Qx_58 = eqQ_20_sysvq0asl(p_1, gHome_0_jou8favxh1);
    if (X60Qx_58){
      return (string_0_sysvq0asl){
        .bytes_0 = 1869102334u, .more_0 = (&strlit_0_I15594291411169668529_jou8favxh1)}
      ;}
    string_0_sysvq0asl X60Qtmp_2 = ampQ_0_sysvq0asl(gHome_0_jou8favxh1, (string_0_sysvq0asl){
      .bytes_0 = 12033u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_59 = startsWithStr_0_jou8favxh1(p_1, X60Qtmp_2);
    if (X60Qx_59){
      NI32 X60Qx_60 = len_4_sysvq0asl(gHome_0_jou8favxh1);
      NI32 X60Qx_61 = len_4_sysvq0asl(p_1);
      string_0_sysvq0asl X60Qtmp_3 = substr_0_sysvq0asl(p_1, ((NI32)(X60Qx_60 + 1)), ((NI32)(X60Qx_61 - 1)));
      string_0_sysvq0asl X60Qx_62 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1869102334u, .more_0 = (&strlit_0_I259198575133589317_jou8favxh1)}
      , X60Qtmp_3);
      result_8 = X60Qx_62;
      nimStrDestroy(X60Qtmp_3);
      nimStrDestroy(X60Qtmp_2);
      return result_8;
      nimStrDestroy(X60Qtmp_3);}
    nimStrDestroy(X60Qtmp_2);}
  nimStrDestroy(result_8);
  string_0_sysvq0asl X60Qx_63 = nimStrDup(p_1);
  result_8 = X60Qx_63;
  return result_8;}
void journalFail_0_jou8favxh1(string_0_sysvq0asl msg_0){
  write_0_syn1lfpjv(stderr, (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I6215679874670304319_jou8favxh1)}
  );
  NI32 X60Qx_64 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18059250407093429845_jou8favxh1)}
  );
  NI32 X60Qx_65 = len_4_sysvq0asl(gPath_0_jou8favxh1);
  NI32 X60Qx_66 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1663051774u, .more_0 = (&strlit_0_I2366269965781815703_jou8favxh1)}
  );
  string_0_sysvq0asl X60Qdesugar_0 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_64 + X60Qx_65)) + X60Qx_66)));
  add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18059250407093429845_jou8favxh1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_0), gPath_0_jou8favxh1);
  add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
    .bytes_0 = 1663051774u, .more_0 = (&strlit_0_I2366269965781815703_jou8favxh1)}
  );
  write_0_syn1lfpjv(stderr, X60Qdesugar_0);
  write_0_syn1lfpjv(stderr, (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4156614902080285430_jou8favxh1)}
  );
  write_0_syn1lfpjv(stderr, msg_0);
  quit_0_syn1lfpjv(((NI32)78));
  nimStrDestroy(X60Qdesugar_0);}
void jRecord_0_jou8favxh1(string_0_sysvq0asl kind_0, string_0_sysvq0asl key_0, seq_0_Ixdx2fh1_ast8ri79k fields_0){
  string_0_sysvq0asl X60Qx_67 = nimStrDup(kind_0);
  string_0_sysvq0asl X60Qx_68 = nimStrDup(key_0);
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_69 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  JEvent_0_jou8favxh1 e_0 = (JEvent_0_jou8favxh1){
    .kind_0 = X60Qx_67, .key_0 = X60Qx_68, .fields_0 = X60Qx_69}
  ;
  NI32 i_5 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_70 = len_3_Ixq6taz_comaa5xpt1(fields_0);
      if (i_5 < X60Qx_70){
        string_0_sysvq0asl* X60Qx_71 = getQ_7_Ir6d0tw_ast8ri79k(fields_0, i_5);
        string_0_sysvq0asl X60Qx_72 = nimStrDup((*X60Qx_71));
        add_0_Ig6072n_ast8ri79k((&e_0.fields_0), X60Qx_72);
        inc_1_I6wjjge_aow2h993l1((&i_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  JEvent_0_jou8favxh1 X60Qtmp_4 = e_0;
  eQwasmovedQ_SX4aX45vent0jou8favxh1_0_jou8favxh1((&e_0));
  add_0_Ixpq8s01_jou8favxh1((&gEvents_0_jou8favxh1), X60Qtmp_4);
  eQdestroyQ_SX4aX45vent0jou8favxh1_0_jou8favxh1(e_0);}
seq_0_Ixdx2fh1_ast8ri79k jServe_0_jou8favxh1(string_0_sysvq0asl kind_1, string_0_sysvq0asl key_1){
  seq_0_Ixdx2fh1_ast8ri79k result_9;
  eQwasMoved_1_I5vdnla_ast8ri79k((&result_9));
  eQdestroy_1_Ivioh0a_ast8ri79k(result_9);
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_73 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  result_9 = X60Qx_73;
  if (gEvents_0_jou8favxh1.len_0 <= gPos_0_jou8favxh1){
    NI32 X60Qx_74 = len_3_Ijmyd9p1_jou8favxh1(gEvents_0_jou8favxh1);
    string_0_sysvq0asl X60Qdesugar_1 = dollarQ_2_sysvq0asl(X60Qx_74);
    NI32 X60Qx_75 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1780490494u, .more_0 = (&strlit_0_I2378533904818905159_jou8favxh1)}
    );
    NI32 X60Qx_76 = len_4_sysvq0asl(X60Qdesugar_1);
    NI32 X60Qx_77 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1701978366u, .more_0 = (&strlit_0_I11713221633288736133_jou8favxh1)}
    );
    NI32 X60Qx_78 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I10986452433485484482_jou8favxh1)}
    );
    NI32 X60Qx_79 = len_4_sysvq0asl(kind_1);
    NI32 X60Qx_80 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_81 = len_4_sysvq0asl(key_1);
    NI32 X60Qx_82 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_75 + X60Qx_76)) + X60Qx_77)) + X60Qx_78)) + X60Qx_79)) + X60Qx_80)) + X60Qx_81)) + X60Qx_82)));
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 1780490494u, .more_0 = (&strlit_0_I2378533904818905159_jou8favxh1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_1);
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 1701978366u, .more_0 = (&strlit_0_I11713221633288736133_jou8favxh1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I10986452433485484482_jou8favxh1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_2), kind_1);
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_2), key_1);
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    journalFail_0_jou8favxh1(X60Qdesugar_2);
    nimStrDestroy(X60Qdesugar_2);
    nimStrDestroy(X60Qdesugar_1);
    return result_9;
    nimStrDestroy(X60Qdesugar_2);
    nimStrDestroy(X60Qdesugar_1);}
  NB8 X60Qx_83;
  JEvent_0_jou8favxh1* X60Qx_84 = getQ_7_Ilovtk3_jou8favxh1(gEvents_0_jou8favxh1, gPos_0_jou8favxh1);
  NB8 X60Qx_85 = eqQ_20_sysvq0asl((*X60Qx_84).kind_0, kind_1);
  if ((!X60Qx_85)){
    X60Qx_83 = NIM_TRUE;}
  else {
    JEvent_0_jou8favxh1* X60Qx_86 = getQ_7_Ilovtk3_jou8favxh1(gEvents_0_jou8favxh1, gPos_0_jou8favxh1);
    NB8 X60Qx_87 = eqQ_20_sysvq0asl((*X60Qx_86).key_0, key_1);
    X60Qx_83 = (!X60Qx_87);}
  if (X60Qx_83){
    string_0_sysvq0asl X60Qdesugar_3 = dollarQ_2_sysvq0asl(((NI32)(gPos_0_jou8favxh1 + 1)));
    NI32 X60Qx_88 = len_3_Ijmyd9p1_jou8favxh1(gEvents_0_jou8favxh1);
    string_0_sysvq0asl X60Qdesugar_4 = dollarQ_2_sysvq0asl(X60Qx_88);
    JEvent_0_jou8favxh1* X60Qx_89 = getQ_7_Ilovtk3_jou8favxh1(gEvents_0_jou8favxh1, gPos_0_jou8favxh1);
    string_0_sysvq0asl X60Qdesugar_5 = nimStrDup((*X60Qx_89).kind_0);
    JEvent_0_jou8favxh1* X60Qx_90 = getQ_7_Ilovtk3_jou8favxh1(gEvents_0_jou8favxh1, gPos_0_jou8favxh1);
    string_0_sysvq0asl X60Qdesugar_6 = nimStrDup((*X60Qx_90).key_0);
    NI32 X60Qx_91 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I15929356284961791821_jou8favxh1)}
    );
    NI32 X60Qx_92 = len_4_sysvq0asl(X60Qdesugar_3);
    NI32 X60Qx_93 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1718558974u, .more_0 = (&strlit_0_I8474398651341962338_jou8favxh1)}
    );
    NI32 X60Qx_94 = len_4_sysvq0asl(X60Qdesugar_4);
    NI32 X60Qx_95 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_96 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1780490494u, .more_0 = (&strlit_0_I11780180728635778377_jou8favxh1)}
    );
    NI32 X60Qx_97 = len_4_sysvq0asl(X60Qdesugar_5);
    NI32 X60Qx_98 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_99 = len_4_sysvq0asl(X60Qdesugar_6);
    NI32 X60Qx_100 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_101 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I10049178917842299699_jou8favxh1)}
    );
    NI32 X60Qx_102 = len_4_sysvq0asl(kind_1);
    NI32 X60Qx_103 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_104 = len_4_sysvq0asl(key_1);
    NI32 X60Qx_105 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_7 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_91 + X60Qx_92)) + X60Qx_93)) + X60Qx_94)) + X60Qx_95)) + X60Qx_96)) + X60Qx_97)) + X60Qx_98)) + X60Qx_99)) + X60Qx_100)) + X60Qx_101)) + X60Qx_102)) + X60Qx_103)) + X60Qx_104)) + X60Qx_105)));
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I15929356284961791821_jou8favxh1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_3);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 1718558974u, .more_0 = (&strlit_0_I8474398651341962338_jou8favxh1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_4);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 1780490494u, .more_0 = (&strlit_0_I11780180728635778377_jou8favxh1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_5);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_6);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I10049178917842299699_jou8favxh1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), kind_1);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), key_1);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    journalFail_0_jou8favxh1(X60Qdesugar_7);
    nimStrDestroy(X60Qdesugar_7);
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qdesugar_4);
    nimStrDestroy(X60Qdesugar_3);
    return result_9;
    nimStrDestroy(X60Qdesugar_7);
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qdesugar_4);
    nimStrDestroy(X60Qdesugar_3);}
  NI32 i_8 = 0;
  {
    while (NIM_TRUE){
      JEvent_0_jou8favxh1* X60Qx_106 = getQ_7_Ilovtk3_jou8favxh1(gEvents_0_jou8favxh1, gPos_0_jou8favxh1);
      NI32 X60Qx_107 = len_3_Ixq6taz_comaa5xpt1((*X60Qx_106).fields_0);
      if (i_8 < X60Qx_107){
        JEvent_0_jou8favxh1* X60Qx_108 = getQ_7_Ilovtk3_jou8favxh1(gEvents_0_jou8favxh1, gPos_0_jou8favxh1);
        string_0_sysvq0asl* X60Qx_109 = getQ_7_Ir6d0tw_ast8ri79k((*X60Qx_108).fields_0, i_8);
        string_0_sysvq0asl X60Qx_110 = nimStrDup((*X60Qx_109));
        add_0_Ig6072n_ast8ri79k((&result_9), X60Qx_110);
        inc_1_I6wjjge_aow2h993l1((&i_8));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  inc_1_I6wjjge_aow2h993l1((&gPos_0_jou8favxh1));
  return result_9;}
string_0_sysvq0asl jField_0_jou8favxh1(seq_0_Ixdx2fh1_ast8ri79k f_0, NI32 i_0){
  string_0_sysvq0asl result_10;
  nimStrWasMoved((&result_10));
  string_0_sysvq0asl X60Qx_1;
  nimStrWasMoved((&X60Qx_1));
  NI32 X60Qx_111 = len_3_Ixq6taz_comaa5xpt1(f_0);
  if (i_0 < X60Qx_111){
    nimStrDestroy(X60Qx_1);
    string_0_sysvq0asl* X60Qx_112 = getQ_7_Ir6d0tw_ast8ri79k(f_0, i_0);
    string_0_sysvq0asl X60Qx_113 = nimStrDup((*X60Qx_112));
    X60Qx_1 = X60Qx_113;}
  else {
    nimStrDestroy(X60Qx_1);
    X60Qx_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_10);
  result_10 = X60Qx_1;
  nimStrWasMoved((&X60Qx_1));
  nimStrDestroy(X60Qx_1);
  return result_10;
  nimStrDestroy(X60Qx_1);
  return result_10;}
string_0_sysvq0asl jSlurp_0_jou8favxh1(string_0_sysvq0asl p_2){
  string_0_sysvq0asl result_11;
  nimStrWasMoved((&result_11));
  nimStrDestroy(result_11);
  result_11 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  FILE* f_1;
  NB8 X60Qx_114 = open_0_syn1lfpjv((&f_1), p_2, 0, -1);
  if ((!X60Qx_114)){
    return result_11;}
  X60Qt_0_IAarrayAcS8ZS65536_hos5i19e11 buf_0 = default_23_Isnz07p_hos5i19e11();
  {
    while (NIM_TRUE){
      NI32 X60Qx_115 = nimIcheckB(0, 65535);
      NI32 n_0 = readBuffer_0_syn1lfpjv(f_1, ((void*)(&buf_0.a[X60Qx_115])), ((NI32)(((NI32)(((NI32)((NI32)65535)) - ((NI32)((NI32)0)))) + 1)));
      if (n_0 <= 0){
        goto whileStmtLabel_0;}
      NI32 i_9 = 0;
      {
        while (i_9 < n_0){
          NI32 X60Qx_116 = nimIcheckB(i_9, 65535);
          add_1_sysvq0asl((&result_11), buf_0.a[X60Qx_116]);
          inc_1_I6wjjge_aow2h993l1((&i_9));}}
      whileStmtLabel_1: ;}}
  whileStmtLabel_0: ;
  close_0_syn1lfpjv(f_1);
  return result_11;}
static inline seq_0_I467rk41_jou8favxh1 newSeqUninit_0_Iuueuci_jou8favxh1(NI32 size_2){
  seq_0_I467rk41_jou8favxh1 result_16;
  if (size_2 == 0){
    result_16 = (seq_0_I467rk41_jou8favxh1){
      .len_0 = size_2, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_I6i476p1_jou8favxh1(size_2);
    void* X60Qx_261 = alloc_1_sysvq0asl(memSize_0);
    result_16 = (seq_0_I467rk41_jou8favxh1){
      .len_0 = size_2, .data_0 = ((JEvent_0_jou8favxh1*)X60Qx_261)}
    ;
    if ((!(result_16.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_262 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_16.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_16;}
static inline void add_0_Ixpq8s01_jou8favxh1(seq_0_I467rk41_jou8favxh1* s_14, JEvent_0_jou8favxh1 elem_3){
  NI32 L_1 = (*s_14).len_0;
  NI32 X60Qx_268 = capInBytes_0_I8iriqw_jou8favxh1((*s_14));
  if (X60Qx_268 < ((NI32)(((NI32)(L_1 * sizeof(JEvent_0_jou8favxh1))) + sizeof(JEvent_0_jou8favxh1)))){
    NB8 X60Qx_269 = resize_0_Ikutmw21_jou8favxh1(s_14, 1);
    if ((!X60Qx_269)){
      eQdestroyQ_SX4aX45vent0jou8favxh1_0_jou8favxh1(elem_3);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_14).len_0));
  (*s_14).data_0[L_1] = elem_3;}
static inline NI32 len_3_Ijmyd9p1_jou8favxh1(seq_0_I467rk41_jou8favxh1 s_16){
  NI32 result_20;
  result_20 = s_16.len_0;
  return result_20;}
static inline JEvent_0_jou8favxh1* getQ_7_Ilovtk3_jou8favxh1(seq_0_I467rk41_jou8favxh1 s_17, NI32 i_18){
  NB8 X60Qx_270;
  if (i_18 < s_17.len_0){
    X60Qx_270 = (0 <= i_18);}
  else {
    X60Qx_270 = NIM_FALSE;}
  if ((!X60Qx_270)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  JEvent_0_jou8favxh1* result_21;
  result_21 = (&s_17.data_0[i_18]);
  return result_21;}
static inline NI32 memSizeInBytes_0_I6i476p1_jou8favxh1(NI32 size_6){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_23;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_6, sizeof(JEvent_0_jou8favxh1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_23 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_23 = ((NI32)2147483647);}
  return result_23;}
static inline NI32 capInBytes_0_I8iriqw_jou8favxh1(seq_0_I467rk41_jou8favxh1 s_19){
  NI32 result_27;
  NI32 X60Qx_4;
  if ((!(s_19.data_0 == NIM_NIL))){
    NI32 X60Qx_275 = allocatedSize_0_sysvq0asl(((void*)((void*)s_19.data_0)));
    X60Qx_4 = X60Qx_275;}
  else {
    X60Qx_4 = 0;}
  result_27 = X60Qx_4;
  return result_27;}
NB8 resize_0_Ikutmw21_jou8favxh1(seq_0_I467rk41_jou8favxh1* dest_3, NI32 addedElements_3){
  NB8 result_28;
  NI32 X60Qx_276 = capInBytes_0_I8iriqw_jou8favxh1((*dest_3));
  NI32 oldCap_1 = ((NI32)(X60Qx_276 / sizeof(JEvent_0_jou8favxh1)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_3);
  NI32 memSize_3 = memSizeInBytes_0_I6i476p1_jou8favxh1(newCap_1);
  void* X60Qx_277 = realloc_1_sysvq0asl(((void*)((void*)(*dest_3).data_0)), memSize_3);
  (*dest_3).data_0 = ((JEvent_0_jou8favxh1*)X60Qx_277);
  if ((*dest_3).data_0 == NIM_NIL){
    (*dest_3).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_3);
    result_28 = NIM_FALSE;}
  else {
    result_28 = NIM_TRUE;}
  return result_28;}
void eQdestroyQ_SX4aX45vent0jou8favxh1_0_jou8favxh1(JEvent_0_jou8favxh1 dest_0){
  eQdestroy_1_Ivioh0a_ast8ri79k(dest_0.fields_0);
  nimStrDestroy(dest_0.key_0);
  nimStrDestroy(dest_0.kind_0);}
void eQwasmovedQ_SX4aX45vent0jou8favxh1_0_jou8favxh1(JEvent_0_jou8favxh1* dest_0){
  nimStrWasMoved((&(*dest_0).kind_0));
  nimStrWasMoved((&(*dest_0).key_0));
  eQwasMoved_1_I5vdnla_ast8ri79k((&(*dest_0).fields_0));}
void X60Qini_0_jou8favxh1(void){
  if (X60QiniGuard_0_jou8favxh1){
    return;}
  X60QiniGuard_0_jou8favxh1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_envto7w6l1();
  gEvents_0_jou8favxh1 = newSeqUninit_0_Iuueuci_jou8favxh1(0);
  gArgv_0_jou8favxh1 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);}
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
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
static inline void eQwasMoved_1_I5vdnla_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_47){
  (*s_47).len_0 = 0;
  (*s_47).data_0 = NIM_NIL;}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
