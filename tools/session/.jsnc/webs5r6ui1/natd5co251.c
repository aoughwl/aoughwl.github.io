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
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct seq_0_I50urnw_croph25r5 seq_0_I50urnw_croph25r5;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct PathGrant_0_iop7yt73v PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v ReadRecord_0_iop7yt73v;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct PipeBuf_Obj_0_natd5co251{
  string_0_sysvq0asl data_0;
  NI32 rpos_0;
  NI32 writeFd_0;
  NB8 writeClosed_0;}
PipeBuf_Obj_0_natd5co251;
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251)(void);
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_Iygo52q1_hos5i19e11{
  NI32 len_0;
  FILE** data_0;}
seq_0_Iygo52q1_hos5i19e11;
typedef struct seq_0_I9xd2d01_hos5i19e11{
  NI32 len_0;
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** data_0;}
seq_0_I9xd2d01_hos5i19e11;
typedef N_NIMCALL_PTR(Value_0_valzr1t4f,  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251)(NI64, string_0_sysvq0asl, seq_0_I50urnw_croph25r5, NB8*);
typedef struct OutSink_Obj_0_natd5co251{
  string_0_sysvq0asl outBuf_0;
  string_0_sysvq0asl errBuf_0;
  NI32 exitCode_0;
  NB8 didQQuit_0;
  string_0_sysvq0asl inBuf_0;
  NI32 inPos_0;
  NB8 inLoaded_0;
  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251 inLoad_0;
  string_0_sysvq0asl progName_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 argv_0;
  seq_0_Iygo52q1_hos5i19e11 fds_0;
  seq_0_I9xd2d01_hos5i19e11 pipeFds_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 envKeys_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 envVals_0;
  NB8 envSeeded_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 failedReads_0;
  NI32 failedReadCount_0;
  NI64 hostContext_0;
  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251 hostCall_0;
  X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* policy_0;}
OutSink_Obj_0_natd5co251;
typedef struct seq_0_I50urnw_croph25r5{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_croph25r5;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11{
  NI r_00;
  PipeBuf_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5{
  NI r_00;
  OutSink_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct seq_0_Iq7pam4_iop7yt73v{
  NI32 len_0;
  PathGrant_0_iop7yt73v* data_0;}
seq_0_Iq7pam4_iop7yt73v;
typedef struct seq_0_Iero8tq_iop7yt73v{
  NI32 len_0;
  ReadRecord_0_iop7yt73v* data_0;}
seq_0_Iero8tq_iop7yt73v;
typedef struct IoPolicy_Obj_0_iop7yt73v{
  NB8 on_0;
  NI32 granted_0;
  seq_0_Iq7pam4_iop7yt73v grants_0;
  NB8 sealed_0;
  string_0_sysvq0asl owner_0;
  NB8 auditReads_0;
  seq_0_Iero8tq_iop7yt73v reads_0;
  NI32 violations_0;
  string_0_sysvq0asl violNative_0;
  NI32 violNeeded_0;}
IoPolicy_Obj_0_iop7yt73v;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax{
  NI r_00;
  IoPolicy_Obj_0_iop7yt73v d_00;}
X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21{
  string_0_sysvq0asl fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef NU8 ValueKind_0_valzr1t4f;

#define vkNil_0_valzr1t4f ((NU8)0)
#define vkInt_0_valzr1t4f ((NU8)1)
#define vkUInt_0_valzr1t4f ((NU8)2)
#define vkFloat_0_valzr1t4f ((NU8)3)
#define vkBool_0_valzr1t4f ((NU8)4)
#define vkChar_0_valzr1t4f ((NU8)5)
#define vkString_0_valzr1t4f ((NU8)6)
#define vkEnum_0_valzr1t4f ((NU8)7)
#define vkSeq_0_valzr1t4f ((NU8)8)
#define vkArray_0_valzr1t4f ((NU8)9)
#define vkTuple_0_valzr1t4f ((NU8)10)
#define vkObject_0_valzr1t4f ((NU8)11)
#define vkRef_0_valzr1t4f ((NU8)12)
#define vkPtr_0_valzr1t4f ((NU8)13)
#define vkSet_0_valzr1t4f ((NU8)14)
#define vkProc_0_valzr1t4f ((NU8)15)
#define vkStream_0_valzr1t4f ((NU8)16)
#define vkCont_0_valzr1t4f ((NU8)17)
typedef struct xint_0_xinat3x34{
  NB8 nan_0;
  NB8 neg_0;
  NU64 val_0;}
xint_0_xinat3x34;
typedef struct Value_0_valzr1t4f{
  ValueKind_0_valzr1t4f kind_0;
  union {
    struct {
      }
    ;
    struct {
      xint_0_xinat3x34 ival_0;
      NI32 bits_0;}
    ;
    struct {
      NF64 fval_0;
      NI32 fbits_0;}
    ;
    struct {
      NB8 bval_0;}
    ;
    struct {
      NC8 cval_0;}
    ;
    struct {
      string_0_sysvq0asl sval_0;}
    ;
    struct {
      NI32 eord_0;
      NU32 ekind_0;}
    ;
    struct {
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sq_0;}
    ;
    struct {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arr_0;}
    ;
    struct {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* obj_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* rf_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* loc_0;
      X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* ov_0;}
    ;
    struct {
      X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* st_0;}
    ;
    struct {
      X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* env_0;
      NU32 fn_0;
      NI32 pidxRaw_0;
      NI32 resumeRaw_0;}
    ;
    struct {
      NB8 toErr_0;}
    ;
    struct {
      X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* coro_0;}
    ;}
  ;}
Value_0_valzr1t4f;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct PathGrant_0_iop7yt73v{
  string_0_sysvq0asl prefix_0;
  NI32 caps_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 parts_0;}
PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v{
  string_0_sysvq0asl path_0;
  NU64 hash_0;
  NI32 size_0;
  NB8 hashed_0;}
ReadRecord_0_iop7yt73v;
typedef struct seq_0_Iw8xl5b1_arecyyj7v{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_arecyyj7v;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_arecyyj7v names_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct Cell_Obj_0_valzr1t4f{
  Value_0_valzr1t4f v_0;}
Cell_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  Cell_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
typedef struct PtrOv_Obj_0_valzr1t4f{
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0;
  NI32 base_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0;
  NI32 foff_0;
  NI16 elemBits_0;
  TCode_0_valzr1t4f ecode_0;
  NU32 etype_0;}
PtrOv_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v{
  NI r_00;
  PtrOv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IAarrayAuS64ZS4_intzsnzax{
  NU64 a[4];}
X60Qt_0_IAarrayAuS64ZS4_intzsnzax;
typedef struct SetBox_Obj_0_valzr1t4f{
  X60Qt_0_IAarrayAuS64ZS4_intzsnzax words_0;}
SetBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  SetBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct ClosureEnv_Obj_0_valzr1t4f{
  seq_0_In6doa_arecyyj7v vars_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;
  X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* coro_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;}
ClosureEnv_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  ClosureEnv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef NU8 RegionKind_0_valzr1t4f;

#define rkBytes_0_valzr1t4f ((NU8)0)
#define rkSeq_0_valzr1t4f ((NU8)1)
#define rkArr_0_valzr1t4f ((NU8)2)
#define rkStr_0_valzr1t4f ((NU8)3)
#define rkCell_0_valzr1t4f ((NU8)4)
#define rkObj_0_valzr1t4f ((NU8)5)
#define rkForeign_0_valzr1t4f ((NU8)6)
typedef struct seq_0_Incv1wn_arecyyj7v{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_arecyyj7v;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct FlatRegion_Obj_0_valzr1t4f{
  RegionKind_0_valzr1t4f kind_0;
  union {
    struct {
      seq_0_Incv1wn_arecyyj7v bytes_0;
      NB8 freed_0;
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* objOverlay_0;}
    ;
    struct {
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sbox_0;
      NI32 sEbits_0;
      TCode_0_valzr1t4f sEcode_0;}
    ;
    struct {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* abox_0;
      NI32 aEbits_0;
      TCode_0_valzr1t4f aEcode_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* scell_0;}
    ;
    struct {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* ccell_0;}
    ;
    struct {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* obox_0;
      seq_0_Ift2sne_aow7lb5cq1 offs_0;}
    ;
    struct {
      NU64 haddr_0;
      NI32 hlen_0;}
    ;}
  ;}
FlatRegion_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  FlatRegion_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
void delete_0_I6cfmey1_natd5co251(seq_0_Ixdx2fh1_aow7lb5cq1* s_29, NI32 idx_1);
void eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* dest_0);
void eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_natd5co251(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* dest_0);
void eQwasmovedQ_ArefSX4futX53inkX4fbj0natd5co251_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5** dest_0);
void eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_natd5co251(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21* dest_0);
void eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_natd5co251(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 dest_0);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline seq_0_Iygo52q1_hos5i19e11 newSeqUninit_0_Iitdu24_hos5i19e11(NI32 size_10);
static inline seq_0_I9xd2d01_hos5i19e11 newSeqUninit_0_Ixqip6b1_hos5i19e11(NI32 size_11);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline void putQ_7_Ild9iim_croph25r5(seq_0_Ixdx2fh1_aow7lb5cq1* s_23, NI32 i_11, string_0_sysvq0asl elem_9);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
extern seq_0_Ixdx2fh1_aow7lb5cq1 eQdup_1_Imq0s4c_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 a_41);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern string_0_sysvq0asl dollarQ_0_valzr1t4f(Value_0_valzr1t4f* v_19);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern NI64 asInt_0_valzr1t4f(Value_0_valzr1t4f* v_17);
extern string_0_sysvq0asl utoa_0_valzr1t4f(NU64 x_1);
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_139);
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_140, NI32 i_94);
extern string_0_sysvq0asl itoa_0_valzr1t4f(NI64 x_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
extern void eQdestroy_1_Ibw1jxo1_hos5i19e11(seq_0_I9xd2d01_hos5i19e11 s_31);
extern void eQdestroy_1_I3k7gu91_hos5i19e11(seq_0_Iygo52q1_hos5i19e11 s_29);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void eQdestroyQ_SX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v(IoPolicy_Obj_0_iop7yt73v* dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_iop7yt73v(void);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 memSizeInBytes_0_Ifkbdqp_hos5i19e11(NI32 size_5);
static inline NI32 memSizeInBytes_0_Ie4yvp31_hos5i19e11(NI32 size_6);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
extern void dealloc_1_sysvq0asl(void* p_20);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
LongString_0_sysvq0asl const strlit_0_I18439285131696709482_natd5co251 = {
  .fullLen_0 = 117, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/seqimpl.nim(262, 42): 0 <= idx and idx < s.len [AssertionDefect]\012"}
;
string_0_sysvq0asl progBaseDir_0_natd5co251 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
NB8 X60QiniGuard_0_natd5co251;
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* newOutSink_0_natd5co251(void){
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* result_0;
  eQwasmovedQ_ArefSX4futX53inkX4fbj0natd5co251_0_natd5co251((&result_0));
  eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_natd5co251(result_0);
  void* X60Qx_5 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5));
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* X60Qtmp_0 = ((X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5*)X60Qx_5);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_6 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Iygo52q1_hos5i19e11 X60Qx_7 = newSeqUninit_0_Iitdu24_hos5i19e11(0);
  seq_0_I9xd2d01_hos5i19e11 X60Qx_8 = newSeqUninit_0_Ixqip6b1_hos5i19e11(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_9 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_10 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_11 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  (*X60Qtmp_0) = (X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5){
    .r_00 = 0, .d_00 = (OutSink_Obj_0_natd5co251){
      .outBuf_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .errBuf_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .exitCode_0 = 0, .didQQuit_0 = NIM_FALSE, .inBuf_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .inPos_0 = 0, .inLoaded_0 = NIM_FALSE, .inLoad_0 = NIM_NIL, .progName_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .argv_0 = X60Qx_6, .fds_0 = X60Qx_7, .pipeFds_0 = X60Qx_8, .envKeys_0 = X60Qx_9, .envVals_0 = X60Qx_10, .envSeeded_0 = NIM_FALSE, .failedReads_0 = X60Qx_11, .failedReadCount_0 = 0, .hostContext_0 = ((NI64)0), .hostCall_0 = NIM_NIL, .policy_0 = ((X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax*)NIM_NIL)}}
  ;
  result_0 = X60Qtmp_0;
  return result_0;}
void noteFailedRead_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_2, string_0_sysvq0asl path_0){
  inc_1_I6wjjge_aow2h993l1((&(*s_2).d_00.failedReadCount_0));
  NI32 X60Qx_14 = len_3_Ixq6taz_aow7lb5cq1((*s_2).d_00.failedReads_0);
  if (X60Qx_14 < 6){
    string_0_sysvq0asl X60Qx_15 = nimStrDup(path_0);
    add_0_Ig6072n_aow7lb5cq1((&(*s_2).d_00.failedReads_0), X60Qx_15);}}
void ensureStdin_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_4){
  if ((*s_4).d_00.inLoaded_0){
    return;}
  (*s_4).d_00.inLoaded_0 = NIM_TRUE;
  if ((!(((void*)(*s_4).d_00.inLoad_0) == NIM_NIL))){
    string_0_sysvq0asl* X60Qlhs_3 = (&(*s_4).d_00.inBuf_0);
    string_0_sysvq0asl X60Qlhs_4 = (*s_4).d_00.inLoad_0();
    nimStrDestroy((*X60Qlhs_3));
    (*X60Qlhs_3) = X60Qlhs_4;
    (*s_4).d_00.inPos_0 = 0;}}
string_0_sysvq0asl envGet_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_5, string_0_sysvq0asl key_0, NB8* found_0){
  string_0_sysvq0asl result_3;
  nimStrWasMoved((&result_3));
  NI32 i_3 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_33 = len_3_Ixq6taz_aow7lb5cq1((*s_5).d_00.envKeys_0);
      if (i_3 < X60Qx_33){
        string_0_sysvq0asl* X60Qx_34 = getQ_7_Ir6d0tw_aow7lb5cq1((*s_5).d_00.envKeys_0, i_3);
        NB8 X60Qx_35 = eqQ_20_sysvq0asl((*X60Qx_34), key_0);
        if (X60Qx_35){
          (*found_0) = NIM_TRUE;
          string_0_sysvq0asl* X60Qx_36 = getQ_7_Ir6d0tw_aow7lb5cq1((*s_5).d_00.envVals_0, i_3);
          string_0_sysvq0asl X60Qx_37 = nimStrDup((*X60Qx_36));
          result_3 = X60Qx_37;
          return result_3;}
        inc_1_I6wjjge_aow2h993l1((&i_3));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  (*found_0) = NIM_FALSE;
  nimStrDestroy(result_3);
  result_3 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_3;}
void envPut_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_6, string_0_sysvq0asl key_1, string_0_sysvq0asl val_0){
  NI32 i_4 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_38 = len_3_Ixq6taz_aow7lb5cq1((*s_6).d_00.envKeys_0);
      if (i_4 < X60Qx_38){
        string_0_sysvq0asl* X60Qx_39 = getQ_7_Ir6d0tw_aow7lb5cq1((*s_6).d_00.envKeys_0, i_4);
        NB8 X60Qx_40 = eqQ_20_sysvq0asl((*X60Qx_39), key_1);
        if (X60Qx_40){
          string_0_sysvq0asl X60Qx_41 = nimStrDup(val_0);
          putQ_7_Ild9iim_croph25r5((&(*s_6).d_00.envVals_0), i_4, X60Qx_41);
          return;}
        inc_1_I6wjjge_aow2h993l1((&i_4));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl X60Qx_42 = nimStrDup(key_1);
  add_0_Ig6072n_aow7lb5cq1((&(*s_6).d_00.envKeys_0), X60Qx_42);
  string_0_sysvq0asl X60Qx_43 = nimStrDup(val_0);
  add_0_Ig6072n_aow7lb5cq1((&(*s_6).d_00.envVals_0), X60Qx_43);}
void envDel_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_7, string_0_sysvq0asl key_2){
  NI32 i_6 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_44 = len_3_Ixq6taz_aow7lb5cq1((*s_7).d_00.envKeys_0);
      if (i_6 < X60Qx_44){
        string_0_sysvq0asl* X60Qx_45 = getQ_7_Ir6d0tw_aow7lb5cq1((*s_7).d_00.envKeys_0, i_6);
        NB8 X60Qx_46 = eqQ_20_sysvq0asl((*X60Qx_45), key_2);
        if (X60Qx_46){
          delete_0_I6cfmey1_natd5co251((&(*s_7).d_00.envKeys_0), i_6);
          delete_0_I6cfmey1_natd5co251((&(*s_7).d_00.envVals_0), i_6);
          return;}
        inc_1_I6wjjge_aow2h993l1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;}
X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 readLineFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_8){
  X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 result_4;
  eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_natd5co251((&result_4));
  ensureStdin_0_natd5co251(s_8);
  NI32 X60Qx_47 = len_4_sysvq0asl((*s_8).d_00.inBuf_0);
  if (X60Qx_47 <= (*s_8).d_00.inPos_0){
    result_4 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
      .fld_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .fld_1 = NIM_FALSE}
    ;
    return result_4;}
  NI32 e_0 = (*s_8).d_00.inPos_0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_48;
      NI32 X60Qx_49 = len_4_sysvq0asl((*s_8).d_00.inBuf_0);
      if (e_0 < X60Qx_49){
        NC8 X60Qx_50 = getQ_9_sysvq0asl((*s_8).d_00.inBuf_0, e_0);
        X60Qx_48 = (!(X60Qx_50 == (NC8)'\012'));}
      else {
        X60Qx_48 = NIM_FALSE;}
      if (X60Qx_48){
        inc_1_I6wjjge_aow2h993l1((&e_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl line_0 = substr_0_sysvq0asl((*s_8).d_00.inBuf_0, (*s_8).d_00.inPos_0, ((NI32)(e_0 - 1)));
  NI32 X60Qx_0;
  NI32 X60Qx_51 = len_4_sysvq0asl((*s_8).d_00.inBuf_0);
  if (e_0 < X60Qx_51){
    X60Qx_0 = ((NI32)(e_0 + 1));}
  else {
    X60Qx_0 = e_0;}
  (*s_8).d_00.inPos_0 = X60Qx_0;
  eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_natd5co251(result_4);
  string_0_sysvq0asl X60Qtmp_5 = line_0;
  nimStrWasMoved((&line_0));
  result_4 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
    .fld_0 = X60Qtmp_5, .fld_1 = NIM_TRUE}
  ;
  nimStrDestroy(line_0);
  return result_4;
  nimStrDestroy(line_0);
  return result_4;}
string_0_sysvq0asl readAllFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_9){
  string_0_sysvq0asl result_5;
  nimStrWasMoved((&result_5));
  ensureStdin_0_natd5co251(s_9);
  NI32 X60Qx_52 = len_4_sysvq0asl((*s_9).d_00.inBuf_0);
  if (X60Qx_52 <= (*s_9).d_00.inPos_0){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_5);
  NI32 X60Qx_53 = len_4_sysvq0asl((*s_9).d_00.inBuf_0);
  string_0_sysvq0asl X60Qx_54 = substr_0_sysvq0asl((*s_9).d_00.inBuf_0, (*s_9).d_00.inPos_0, ((NI32)(X60Qx_53 - 1)));
  result_5 = X60Qx_54;
  NI32 X60Qx_55 = len_4_sysvq0asl((*s_9).d_00.inBuf_0);
  (*s_9).d_00.inPos_0 = X60Qx_55;
  return result_5;}
NI32 readCharFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_10){
  NI32 result_6;
  ensureStdin_0_natd5co251(s_10);
  NI32 X60Qx_56 = len_4_sysvq0asl((*s_10).d_00.inBuf_0);
  if (X60Qx_56 <= (*s_10).d_00.inPos_0){
    return -1;}
  NC8 X60Qx_57 = getQ_9_sysvq0asl((*s_10).d_00.inBuf_0, (*s_10).d_00.inPos_0);
  result_6 = ((NI32)X60Qx_57);
  inc_1_I6wjjge_aow2h993l1((&(*s_10).d_00.inPos_0));
  return result_6;}
seq_0_Ixdx2fh1_aow7lb5cq1 commandLineParamsFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_11){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_7;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_7));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_7);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_58 = eQdup_1_Imq0s4c_aow7lb5cq1((*s_11).d_00.argv_0);
  result_7 = X60Qx_58;
  return result_7;}
NI32 paramCountFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_12){
  NI32 result_8;
  NI32 X60Qx_59 = len_3_Ixq6taz_aow7lb5cq1((*s_12).d_00.argv_0);
  result_8 = X60Qx_59;
  return result_8;}
string_0_sysvq0asl paramStrFrom_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_13, NI32 i_0){
  string_0_sysvq0asl result_9;
  nimStrWasMoved((&result_9));
  if (i_0 == 0){
    nimStrDestroy(result_9);
    string_0_sysvq0asl X60Qx_60 = nimStrDup((*s_13).d_00.progName_0);
    result_9 = X60Qx_60;}
  else {
    NB8 X60Qx_61;
    if (1 <= i_0){
      NI32 X60Qx_62 = len_3_Ixq6taz_aow7lb5cq1((*s_13).d_00.argv_0);
      X60Qx_61 = (i_0 <= X60Qx_62);}
    else {
      X60Qx_61 = NIM_FALSE;}
    if (X60Qx_61){
      nimStrDestroy(result_9);
      string_0_sysvq0asl* X60Qx_63 = getQ_7_Ir6d0tw_aow7lb5cq1((*s_13).d_00.argv_0, ((NI32)(i_0 - 1)));
      string_0_sysvq0asl X60Qx_64 = nimStrDup((*X60Qx_63));
      result_9 = X60Qx_64;}
    else {
      nimStrDestroy(result_9);
      result_9 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}}
  return result_9;}
void writeStr_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_14, NB8 toErr_0, string_0_sysvq0asl text_0){
  if (toErr_0){
    add_2_sysvq0asl((&(*s_14).d_00.errBuf_0), text_0);}
  else {
    if ((!(*s_14).d_00.didQQuit_0)){
      add_2_sysvq0asl((&(*s_14).d_00.outBuf_0), text_0);}}}
void writeVal_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_15, NB8 toErr_1, Value_0_valzr1t4f* v_0){
  if (toErr_1){
    string_0_sysvq0asl X60Qtmp_6 = dollarQ_0_valzr1t4f((&(*v_0)));
    add_2_sysvq0asl((&(*s_15).d_00.errBuf_0), X60Qtmp_6);
    nimStrDestroy(X60Qtmp_6);}
  else {
    if ((!(*s_15).d_00.didQQuit_0)){
      string_0_sysvq0asl X60Qtmp_7 = dollarQ_0_valzr1t4f((&(*v_0)));
      add_2_sysvq0asl((&(*s_15).d_00.outBuf_0), X60Qtmp_7);
      nimStrDestroy(X60Qtmp_7);}}}
string_0_sysvq0asl resolvedReadPath_0_natd5co251(string_0_sysvq0asl path_1){
  string_0_sysvq0asl result_10;
  nimStrWasMoved((&result_10));
  NB8 X60Qx_66;
  NI32 X60Qx_67 = len_4_sysvq0asl(progBaseDir_0_natd5co251);
  if (X60Qx_67 == 0){
    X60Qx_66 = NIM_TRUE;}
  else {
    NI32 X60Qx_68 = len_4_sysvq0asl(path_1);
    X60Qx_66 = (X60Qx_68 == 0);}
  if (X60Qx_66){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NC8 X60Qx_69 = getQ_9_sysvq0asl(path_1, 0);
  if (X60Qx_69 == (NC8)'/'){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl d_1 = nimStrDup(progBaseDir_0_natd5co251);
  NI32 X60Qx_70 = len_4_sysvq0asl(d_1);
  NC8 X60Qx_71 = getQ_9_sysvq0asl(d_1, ((NI32)(X60Qx_70 - 1)));
  if ((!(X60Qx_71 == (NC8)'/'))){
    add_1_sysvq0asl((&d_1), (NC8)'/');}
  nimStrDestroy(result_10);
  string_0_sysvq0asl X60Qx_72 = ampQ_0_sysvq0asl(d_1, path_1);
  result_10 = X60Qx_72;
  nimStrDestroy(d_1);
  return result_10;
  nimStrDestroy(d_1);
  return result_10;}
void doQQuit_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* s_16, NI32 code_0){
  if ((!(*s_16).d_00.didQQuit_0)){
    (*s_16).d_00.exitCode_0 = code_0;
    (*s_16).d_00.didQQuit_0 = NIM_TRUE;}}
string_0_sysvq0asl uText_0_natd5co251(Value_0_valzr1t4f* v_1){
  string_0_sysvq0asl result_11;
  nimStrWasMoved((&result_11));
  nimStrDestroy(result_11);
  result_11 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((*v_1).kind_0 == 2){
    nimStrDestroy(result_11);
    string_0_sysvq0asl X60Qx_73 = dollarQ_0_valzr1t4f((&(*v_1)));
    result_11 = X60Qx_73;}
  else {
    NI64 i_7 = asInt_0_valzr1t4f((&(*v_1)));
    if (((NI64)0) <= i_7){
      nimStrDestroy(result_11);
      string_0_sysvq0asl X60Qx_74 = utoa_0_valzr1t4f(((NU64)i_7));
      result_11 = X60Qx_74;}
    else {
      nimStrDestroy(result_11);
      string_0_sysvq0asl X60Qx_75 = utoa_0_valzr1t4f(((NU64)i_7));
      result_11 = X60Qx_75;}}
  return result_11;}
string_0_sysvq0asl charText_0_natd5co251(Value_0_valzr1t4f* v_2){
  string_0_sysvq0asl result_12;
  nimStrWasMoved((&result_12));
  nimStrDestroy(result_12);
  result_12 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((*v_2).kind_0 == 5){
    add_1_sysvq0asl((&result_12), (*v_2).cval_0);}
  else {
    NI64 X60Qx_76 = asInt_0_valzr1t4f((&(*v_2)));
    add_1_sysvq0asl((&result_12), ((NC8)((NI64)(X60Qx_76 & ((NI64)255)))));}
  return result_12;}
string_0_sysvq0asl cformat_0_natd5co251(string_0_sysvq0asl fmt_0, seq_0_I50urnw_croph25r5 args_1){
  string_0_sysvq0asl result_13;
  nimStrWasMoved((&result_13));
  nimStrDestroy(result_13);
  result_13 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 i_8 = 0;
  NI32 ai_0 = 0;
  NI32 n_0 = len_4_sysvq0asl(fmt_0);
  {
    while (i_8 < n_0){
      {
        NC8 c_0 = getQ_9_sysvq0asl(fmt_0, i_8);
        if ((!(c_0 == (NC8)'%'))){
          add_1_sysvq0asl((&result_13), c_0);
          inc_1_I6wjjge_aow2h993l1((&i_8));
          goto continueLabel_1;}
        inc_1_I6wjjge_aow2h993l1((&i_8));
        if (n_0 <= i_8){
          add_1_sysvq0asl((&result_13), (NC8)'%');
          goto whileStmtLabel_0;}
        NI32 lmod_0 = 0;
        {
          while (NIM_TRUE){
            NB8 X60Qx_77;
            if (i_8 < n_0){
              NC8 X60Qx_78 = getQ_9_sysvq0asl(fmt_0, i_8);
              X60Qx_77 = (X60Qx_78 == (NC8)'l');}
            else {
              X60Qx_77 = NIM_FALSE;}
            if (X60Qx_77){
              inc_1_I6wjjge_aow2h993l1((&lmod_0));
              inc_1_I6wjjge_aow2h993l1((&i_8));}
            else {
              break;}}}
        whileStmtLabel_2: ;
        if (n_0 <= i_8){
          add_1_sysvq0asl((&result_13), (NC8)'%');
          NI32 k_0 = 0;
          {
            while (k_0 < lmod_0){
              add_1_sysvq0asl((&result_13), (NC8)'l');
              inc_1_I6wjjge_aow2h993l1((&k_0));}}
          whileStmtLabel_3: ;
          goto whileStmtLabel_0;}
        NC8 spec_0 = getQ_9_sysvq0asl(fmt_0, i_8);
        inc_1_I6wjjge_aow2h993l1((&i_8));
        NB8 X60Qx_79;
        if (spec_0 == (NC8)'%'){
          X60Qx_79 = (lmod_0 == 0);}
        else {
          X60Qx_79 = NIM_FALSE;}
        if (X60Qx_79){
          add_1_sysvq0asl((&result_13), (NC8)'%');}
        else {
          NB8 X60Qx_80;
          if (spec_0 == (NC8)'s'){
            X60Qx_80 = (lmod_0 == 0);}
          else {
            X60Qx_80 = NIM_FALSE;}
          if (X60Qx_80){
            NI32 X60Qx_81 = len_3_I4n9kvq_intzsnzax(args_1);
            if (ai_0 < X60Qx_81){
              Value_0_valzr1t4f* X60Qx_82 = getQ_7_Ine8yq71_intzsnzax(args_1, ai_0);
              Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_82);
              string_0_sysvq0asl X60Qtmp_8 = dollarQ_0_valzr1t4f((&X60QconstRefTemp_0));
              add_2_sysvq0asl((&result_13), X60Qtmp_8);
              inc_1_I6wjjge_aow2h993l1((&ai_0));
              nimStrDestroy(X60Qtmp_8);}}
          else {
            NB8 X60Qx_83;
            if (spec_0 == (NC8)'d'){
              X60Qx_83 = NIM_TRUE;}
            else {
              X60Qx_83 = (spec_0 == (NC8)'i');}
            if (X60Qx_83){
              NI32 X60Qx_84 = len_3_I4n9kvq_intzsnzax(args_1);
              if (ai_0 < X60Qx_84){
                Value_0_valzr1t4f* X60Qx_85 = getQ_7_Ine8yq71_intzsnzax(args_1, ai_0);
                Value_0_valzr1t4f X60QconstRefTemp_1 = (*X60Qx_85);
                NI64 X60Qx_86 = asInt_0_valzr1t4f((&X60QconstRefTemp_1));
                string_0_sysvq0asl X60Qtmp_9 = itoa_0_valzr1t4f(X60Qx_86);
                add_2_sysvq0asl((&result_13), X60Qtmp_9);
                inc_1_I6wjjge_aow2h993l1((&ai_0));
                nimStrDestroy(X60Qtmp_9);}}
            else {
              if (spec_0 == (NC8)'u'){
                NI32 X60Qx_87 = len_3_I4n9kvq_intzsnzax(args_1);
                if (ai_0 < X60Qx_87){
                  Value_0_valzr1t4f* X60Qx_88 = getQ_7_Ine8yq71_intzsnzax(args_1, ai_0);
                  Value_0_valzr1t4f X60QconstRefTemp_2 = (*X60Qx_88);
                  string_0_sysvq0asl X60Qtmp_10 = uText_0_natd5co251((&X60QconstRefTemp_2));
                  add_2_sysvq0asl((&result_13), X60Qtmp_10);
                  inc_1_I6wjjge_aow2h993l1((&ai_0));
                  nimStrDestroy(X60Qtmp_10);}}
              else {
                NB8 X60Qx_89;
                if (spec_0 == (NC8)'c'){
                  X60Qx_89 = (lmod_0 == 0);}
                else {
                  X60Qx_89 = NIM_FALSE;}
                if (X60Qx_89){
                  NI32 X60Qx_90 = len_3_I4n9kvq_intzsnzax(args_1);
                  if (ai_0 < X60Qx_90){
                    Value_0_valzr1t4f* X60Qx_91 = getQ_7_Ine8yq71_intzsnzax(args_1, ai_0);
                    Value_0_valzr1t4f X60QconstRefTemp_3 = (*X60Qx_91);
                    string_0_sysvq0asl X60Qtmp_11 = charText_0_natd5co251((&X60QconstRefTemp_3));
                    add_2_sysvq0asl((&result_13), X60Qtmp_11);
                    inc_1_I6wjjge_aow2h993l1((&ai_0));
                    nimStrDestroy(X60Qtmp_11);}}
                else {
                  NB8 X60Qx_92;
                  NB8 X60Qx_93;
                  NB8 X60Qx_94;
                  NB8 X60Qx_95;
                  NB8 X60Qx_96;
                  if (spec_0 == (NC8)'f'){
                    X60Qx_96 = NIM_TRUE;}
                  else {
                    X60Qx_96 = (spec_0 == (NC8)'g');}
                  if (X60Qx_96){
                    X60Qx_95 = NIM_TRUE;}
                  else {
                    X60Qx_95 = (spec_0 == (NC8)'e');}
                  if (X60Qx_95){
                    X60Qx_94 = NIM_TRUE;}
                  else {
                    X60Qx_94 = (spec_0 == (NC8)'F');}
                  if (X60Qx_94){
                    X60Qx_93 = NIM_TRUE;}
                  else {
                    X60Qx_93 = (spec_0 == (NC8)'G');}
                  if (X60Qx_93){
                    X60Qx_92 = NIM_TRUE;}
                  else {
                    X60Qx_92 = (spec_0 == (NC8)'E');}
                  if (X60Qx_92){
                    NI32 X60Qx_97 = len_3_I4n9kvq_intzsnzax(args_1);
                    if (ai_0 < X60Qx_97){
                      Value_0_valzr1t4f* X60Qx_98 = getQ_7_Ine8yq71_intzsnzax(args_1, ai_0);
                      Value_0_valzr1t4f X60QconstRefTemp_4 = (*X60Qx_98);
                      string_0_sysvq0asl X60Qtmp_12 = dollarQ_0_valzr1t4f((&X60QconstRefTemp_4));
                      add_2_sysvq0asl((&result_13), X60Qtmp_12);
                      inc_1_I6wjjge_aow2h993l1((&ai_0));
                      nimStrDestroy(X60Qtmp_12);}}
                  else {
                    add_1_sysvq0asl((&result_13), (NC8)'%');
                    NI32 k_1 = 0;
                    {
                      while (k_1 < lmod_0){
                        add_1_sysvq0asl((&result_13), (NC8)'l');
                        inc_1_I6wjjge_aow2h993l1((&k_1));}}
                    whileStmtLabel_4: ;
                    add_1_sysvq0asl((&result_13), spec_0);}}}}}}}
      continueLabel_1: ;}}
  whileStmtLabel_0: ;
  return result_13;}
void delete_0_I6cfmey1_natd5co251(seq_0_Ixdx2fh1_aow7lb5cq1* s_29, NI32 idx_1){
  NB8 X60Qx_109;
  if (0 <= idx_1){
    X60Qx_109 = (idx_1 < (*s_29).len_0);}
  else {
    X60Qx_109 = NIM_FALSE;}
  if ((!X60Qx_109)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I18439285131696709482_natd5co251)}
    );}
  NI32 L_1 = (*s_29).len_0;
  nimStrDestroy((*s_29).data_0[idx_1]);
  NI32 i_12 = idx_1;
  {
    while (i_12 < ((NI32)(L_1 - 1))){
      (*s_29).data_0[i_12] = (*s_29).data_0[((NI32)(i_12 + 1))];
      inc_1_I6wjjge_aow2h993l1((&i_12));}}
  whileStmtLabel_0: ;
  dec_1_I0nzoz91_aow7lb5cq1((&(*s_29).len_0));}
void eQdestroyQ_SX50ipeX42ufX4fbj0natd5co251_0_natd5co251(PipeBuf_Obj_0_natd5co251 dest_0){
  nimStrDestroy(dest_0.data_0);}
void eQdestroyQ_SX4futX53inkX4fbj0natd5co251_0_natd5co251(OutSink_Obj_0_natd5co251* dest_0){
  eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_natd5co251((*dest_0).policy_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*dest_0).failedReads_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*dest_0).envVals_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*dest_0).envKeys_0);
  eQdestroy_1_Ibw1jxo1_hos5i19e11((*dest_0).pipeFds_0);
  eQdestroy_1_I3k7gu91_hos5i19e11((*dest_0).fds_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*dest_0).argv_0);
  nimStrDestroy((*dest_0).progName_0);
  nimStrDestroy((*dest_0).inBuf_0);
  nimStrDestroy((*dest_0).errBuf_0);
  nimStrDestroy((*dest_0).outBuf_0);}
void eQdestroyQ_ArefSX4futX53inkX4fbj0natd5co251_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* dest_0){
  if (dest_0){
    NB8 X60Qx_156 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_156){
      eQdestroyQ_SX4futX53inkX4fbj0natd5co251_0_natd5co251((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX49oX50olicyX4fbj0iop7yt73v_0_natd5co251(X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_157 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_157){
      eQdestroyQ_SX49oX50olicyX4fbj0iop7yt73v_0_iop7yt73v((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX4futX53inkX4fbj0natd5co251_0_natd5co251(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_natd5co251(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21* dest_0){
  nimStrWasMoved((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_natd5co251(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 dest_0){
  nimStrDestroy(dest_0.fld_0);}
void X60Qini_0_natd5co251(void){
  if (X60QiniGuard_0_natd5co251){
    return;}
  X60QiniGuard_0_natd5co251 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_valzr1t4f();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_iop7yt73v();}
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_59;
  if (size_8 == 0){
    result_59 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_I7me00i_aow7lb5cq1(size_8);
    void* X60Qx_1432 = alloc_1_sysvq0asl(memSize_1);
    result_59 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = ((string_0_sysvq0asl*)X60Qx_1432)}
    ;
    if ((!(result_59.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1433 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_59.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_59;}
static inline seq_0_Iygo52q1_hos5i19e11 newSeqUninit_0_Iitdu24_hos5i19e11(NI32 size_10){
  seq_0_Iygo52q1_hos5i19e11 result_39;
  if (size_10 == 0){
    result_39 = (seq_0_Iygo52q1_hos5i19e11){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_6 = memSizeInBytes_0_Ifkbdqp_hos5i19e11(size_10);
    void* X60Qx_168 = alloc_1_sysvq0asl(memSize_6);
    result_39 = (seq_0_Iygo52q1_hos5i19e11){
      .len_0 = size_10, .data_0 = ((FILE**)X60Qx_168)}
    ;
    if ((!(result_39.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_169 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_39.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_6);}}
  return result_39;}
static inline seq_0_I9xd2d01_hos5i19e11 newSeqUninit_0_Ixqip6b1_hos5i19e11(NI32 size_11){
  seq_0_I9xd2d01_hos5i19e11 result_40;
  if (size_11 == 0){
    result_40 = (seq_0_I9xd2d01_hos5i19e11){
      .len_0 = size_11, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_7 = memSizeInBytes_0_Ie4yvp31_hos5i19e11(size_11);
    void* X60Qx_170 = alloc_1_sysvq0asl(memSize_7);
    result_40 = (seq_0_I9xd2d01_hos5i19e11){
      .len_0 = size_11, .data_0 = ((X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11**)X60Qx_170)}
    ;
    if ((!(result_40.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_171 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_40.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_7);}}
  return result_40;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37){
  NI32 result_60;
  result_60 = s_37.len_0;
  return result_60;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9){
  NI32 L_0 = (*s_35).len_0;
  NI32 X60Qx_1434 = capInBytes_0_Ih2sbn01_aow7lb5cq1((*s_35));
  if (X60Qx_1434 < ((NI32)(((NI32)(L_0 * sizeof(string_0_sysvq0asl))) + sizeof(string_0_sysvq0asl)))){
    NB8 X60Qx_1435 = resize_0_I4buliy_aow7lb5cq1(s_35, 1);
    if ((!X60Qx_1435)){
      nimStrDestroy(elem_9);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_35).len_0));
  (*s_35).data_0[L_0] = elem_9;}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33){
  NB8 X60Qx_1436;
  if (i_33 < s_38.len_0){
    X60Qx_1436 = (0 <= i_33);}
  else {
    X60Qx_1436 = NIM_FALSE;}
  if ((!X60Qx_1436)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* result_61;
  result_61 = (&s_38.data_0[i_33]);
  return result_61;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline void putQ_7_Ild9iim_croph25r5(seq_0_Ixdx2fh1_aow7lb5cq1* s_23, NI32 i_11, string_0_sysvq0asl elem_9){
  NB8 X60Qx_122;
  if (i_11 < (*s_23).len_0){
    X60Qx_122 = (0 <= i_11);}
  else {
    X60Qx_122 = NIM_FALSE;}
  if ((!X60Qx_122)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* X60Qlhs_5 = (&(*s_23).data_0[i_11]);
  string_0_sysvq0asl X60Qlhs_6 = elem_9;
  nimStrWasMoved((&elem_9));
  nimStrDestroy((*X60Qlhs_5));
  (*X60Qlhs_5) = X60Qlhs_6;
  nimStrDestroy(elem_9);}
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
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93){
  (*s_93).len_0 = 0;
  (*s_93).data_0 = NIM_NIL;}
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_139){
  NI32 result_189;
  result_189 = s_139.len_0;
  return result_189;}
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_140, NI32 i_94){
  NB8 X60Qx_3644;
  if (i_94 < s_140.len_0){
    X60Qx_3644 = (0 <= i_94);}
  else {
    X60Qx_3644 = NIM_FALSE;}
  if ((!X60Qx_3644)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  Value_0_valzr1t4f* result_190;
  result_190 = (&s_140.data_0[i_94]);
  return result_190;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_82;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_19, sizeof(string_0_sysvq0asl), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_82 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_82 = ((NI32)2147483647);}
  return result_82;}
static inline NI32 memSizeInBytes_0_Ifkbdqp_hos5i19e11(NI32 size_5){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_32;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_5, sizeof(FILE*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_32 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_32 = ((NI32)2147483647);}
  return result_32;}
static inline NI32 memSizeInBytes_0_Ie4yvp31_hos5i19e11(NI32 size_6){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_33;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_6, sizeof(X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_33 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_33 = ((NI32)2147483647);}
  return result_33;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65){
  NI32 result_85;
  NI32 X60Qx_11;
  if ((!(s_65.data_0 == NIM_NIL))){
    NI32 X60Qx_1467 = allocatedSize_0_sysvq0asl(((void*)((void*)s_65.data_0)));
    X60Qx_11 = X60Qx_1467;}
  else {
    X60Qx_11 = 0;}
  result_85 = X60Qx_11;
  return result_85;}
