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
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5 X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct seq_0_I50urnw_croph25r5 seq_0_I50urnw_croph25r5;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1 X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct PathGrant_0_iop7yt73v PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v ReadRecord_0_iop7yt73v;
typedef NU8 CrossRoute_0_croph25r5;

#define crNone_0_croph25r5 ((NU8)0)
#define crHostNative_0_croph25r5 ((NU8)1)
#define crSyscall_0_croph25r5 ((NU8)2)
#define crHybridNative_0_croph25r5 ((NU8)3)
#define crInterpret_0_croph25r5 ((NU8)4)
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
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
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
typedef struct CrossOutcome_0_croph25r5{
  NB8 handled_0;
  Value_0_valzr1t4f v_0;
  CrossRoute_0_croph25r5 route_0;
  string_0_sysvq0asl detail_0;}
CrossOutcome_0_croph25r5;
typedef NU8 DeclineStage_0_croph25r5;

#define dsCensus_0_croph25r5 ((NU8)0)
#define dsMarshal_0_croph25r5 ((NU8)1)
#define dsCallee_0_croph25r5 ((NU8)2)
#define dsArena_0_croph25r5 ((NU8)3)
#define dsAnalysis_0_croph25r5 ((NU8)4)
#define dsJit_0_croph25r5 ((NU8)5)
#define dsBuild_0_croph25r5 ((NU8)6)
typedef N_NIMCALL_PTR(Value_0_valzr1t4f,  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251ZSstring0sysvq0aslSseq0X4950urnwSX56alue0valzr1t4fAnimcallZAfalseZAR91_croph25r5)(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5*, string_0_sysvq0asl, seq_0_I50urnw_croph25r5);
typedef N_NIMCALL_PTR(CrossRoute_0_croph25r5,  X60Qt_0_ISstring0sysvq0aslSX43rossX52oute0croph25r5AnimcallZAfalseZAR51_croph25r5)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5)(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1*);
typedef struct XProvider_Obj_0_croph25r5{
  string_0_sysvq0asl name_0;
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251ZSstring0sysvq0aslSseq0X4950urnwSX56alue0valzr1t4fAnimcallZAfalseZAR91_croph25r5 run_0;
  X60Qt_0_ISstring0sysvq0aslSX43rossX52oute0croph25r5AnimcallZAfalseZAR51_croph25r5 route_0;
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_0;
  string_0_sysvq0asl artifact_0;
  NB8 attested_0;
  NB8 attestRun_0;}
XProvider_Obj_0_croph25r5;
typedef struct seq_0_I50urnw_croph25r5{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_croph25r5;
typedef struct seq_0_Iwlfuke_croph25r5{
  NI32 len_0;
  DeclineStage_0_croph25r5* data_0;}
seq_0_Iwlfuke_croph25r5;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct X60Qt_0_IAarrayAiS32ZS27_croph25r5{
  NI32 a[27];}
X60Qt_0_IAarrayAiS32ZS27_croph25r5;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS27_croph25r5{
  string_0_sysvq0asl a[27];}
X60Qt_0_IAarraySstring0sysvq0aslS27_croph25r5;
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251)(void);
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
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5{
  NI r_00;
  OutSink_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1{
  NI r_00;
  XProvider_Obj_0_croph25r5 d_00;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
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
typedef struct PipeBuf_Obj_0_natd5co251{
  string_0_sysvq0asl data_0;
  NI32 rpos_0;
  NI32 writeFd_0;
  NB8 writeClosed_0;}
PipeBuf_Obj_0_natd5co251;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11{
  NI r_00;
  PipeBuf_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
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
static inline seq_0_Iwlfuke_croph25r5 newSeqUninit_0_Injrsqx1_croph25r5(NI32 size_2);
static inline void add_0_Ih7x8oe1_croph25r5(seq_0_Iwlfuke_croph25r5* s_7, DeclineStage_0_croph25r5 elem_2);
static inline NI32 len_3_If0ji891_croph25r5(seq_0_Iwlfuke_croph25r5 s_11);
static inline DeclineStage_0_croph25r5* getQ_7_Idt9yvi_croph25r5(seq_0_Iwlfuke_croph25r5 s_14, NI32 i_5);
static inline NI32 memSizeInBytes_0_I45nzb5_croph25r5(NI32 size_6);
static inline NI32 capInBytes_0_I41twvj1_croph25r5(seq_0_Iwlfuke_croph25r5 s_15);
NB8 resize_0_Ig39hrf_croph25r5(seq_0_Iwlfuke_croph25r5* dest_2, NI32 addedElements_2);
void eQdestroy_1_I8f0yiq_croph25r5(seq_0_Iwlfuke_croph25r5 s_26);
static inline seq_0_I50urnw_croph25r5 newSeqUninit_0_I8oufjc_croph25r5(NI32 size_10);
static inline NI32 memSizeInBytes_0_Itmy7ww1_croph25r5(NI32 size_11);
void eQdestroyQ_SX43rossX4futcome0croph25r5_0_croph25r5(CrossOutcome_0_croph25r5* dest_0);
void eQwasmovedQ_SX43rossX4futcome0croph25r5_0_croph25r5(CrossOutcome_0_croph25r5* dest_0);
void eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* dest_0);
void eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1** dest_0);
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* eQdupQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* src_0);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern Value_0_valzr1t4f vNil_0_valzr1t4f(void);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern Value_0_valzr1t4f nativeCall_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_14, string_0_sysvq0asl name_7, seq_0_I50urnw_croph25r5 args_5);
extern LongString_0_sysvq0asl const strlit_0_I2072093345082808027_cal1yym9t1;
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern NI32 noopHits_0_runot4689;
extern string_0_sysvq0asl getEnv_0_envto7w6l1(string_0_sysvq0asl key_1, string_0_sysvq0asl default_0);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_envto7w6l1(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_natd5co251(void);
extern void X60Qini_0_runot4689(void);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I8446236512461598146_croph25r5 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "none"}
;
LongString_0_sysvq0asl const strlit_0_I3769781912767351299_croph25r5 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "host-native"}
;
LongString_0_sysvq0asl const strlit_0_I4912385847247956930_croph25r5 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "interpret"}
;
LongString_0_sysvq0asl const strlit_0_I622427702386968398_croph25r5 = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "provider produced no route"}
;
LongString_0_sysvq0asl const strlit_0_I3892905952809112992_croph25r5 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<unnamed decline>"}
;
LongString_0_sysvq0asl const strlit_0_I18371599458681458362_croph25r5 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "census"}
;
LongString_0_sysvq0asl const strlit_0_I11097756920309624244_croph25r5 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "marshal"}
;
LongString_0_sysvq0asl const strlit_0_I17555607389722195064_croph25r5 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "callee"}
;
LongString_0_sysvq0asl const strlit_0_I9923954385269310427_croph25r5 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arena"}
;
LongString_0_sysvq0asl const strlit_0_I14983304549480785616_croph25r5 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "analysis"}
;
LongString_0_sysvq0asl const strlit_0_I10833596585003541936_croph25r5 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "build"}
;
LongString_0_sysvq0asl const strlit_0_I11689404509053140833_croph25r5 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " -> "}
;
LongString_0_sysvq0asl const strlit_0_I4241637849034259752_croph25r5 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "   <== BLOCKER ("}
;
LongString_0_sysvq0asl const strlit_0_I13219317321365981656_croph25r5 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "flushFile"}
;
LongString_0_sysvq0asl const strlit_0_I5792391256252241729_croph25r5 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "endOfFile"}
;
LongString_0_sysvq0asl const strlit_0_I2053446828331389519_croph25r5 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getFilePos"}
;
LongString_0_sysvq0asl const strlit_0_I15913671615442312297_croph25r5 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getFileHandle"}
;
LongString_0_sysvq0asl const strlit_0_I11626809062896146847_croph25r5 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "getFileSize"}
;
LongString_0_sysvq0asl const strlit_0_I3411051090140283573_croph25r5 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readChar"}
;
LongString_0_sysvq0asl const strlit_0_I11445521212967021334_croph25r5 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readBuffer"}
;
LongString_0_sysvq0asl const strlit_0_I15258214261968625836_croph25r5 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "setFilePos"}
;
LongString_0_sysvq0asl const strlit_0_I13565819874765507459_croph25r5 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "writeFile"}
;
LongString_0_sysvq0asl const strlit_0_I3703669261441550327_croph25r5 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "writeLine"}
;
LongString_0_sysvq0asl const strlit_0_I4978164850318270062_croph25r5 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readAll"}
;
LongString_0_sysvq0asl const strlit_0_I12542130669033277445_croph25r5 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readFile"}
;
LongString_0_sysvq0asl const strlit_0_I2707782551556965371_croph25r5 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readBytes"}
;
LongString_0_sysvq0asl const strlit_0_I6395244567427789796_croph25r5 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "read"}
;
LongString_0_sysvq0asl const strlit_0_I2027400509069786846_croph25r5 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readLine"}
;
LongString_0_sysvq0asl const strlit_0_I3858632921624769948_croph25r5 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "reopen"}
;
LongString_0_sysvq0asl const strlit_0_I9592449470941440445_croph25r5 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "open"}
;
LongString_0_sysvq0asl const strlit_0_I4266325610518786829_croph25r5 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "close"}
;
LongString_0_sysvq0asl const strlit_0_I6178772090241098573_croph25r5 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "writeBuffer"}
;
LongString_0_sysvq0asl const strlit_0_I100145031017624899_croph25r5 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "writeBytes"}
;
LongString_0_sysvq0asl const strlit_0_I12440307187701028700_croph25r5 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "write"}
;
LongString_0_sysvq0asl const strlit_0_I1312293394728271086_croph25r5 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_ROUTE"}
;
LongString_0_sysvq0asl const strlit_0_I819492781050547440_croph25r5 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_HYBRID_LOG"}
;
NI32 xUnnamedDeclines_0_croph25r5 = 0;
NI32 xUnnamedRoute_0_croph25r5 = 0;
NI32 xUnnamedCross_0_croph25r5 = 0;
NI32 xUnnamedCensus_0_croph25r5 = 0;
string_0_sysvq0asl gChainCallee_0_croph25r5 = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
seq_0_Iwlfuke_croph25r5 gChainStages_0_croph25r5;
seq_0_Ixdx2fh1_aow7lb5cq1 gChainReasons_0_croph25r5;
NI32 const cSeqBlocks_0_croph25r5 = ((NI32)0);
NI32 const cArrBlocks_0_croph25r5 = ((NI32)1);
NI32 const cCellBlocks_0_croph25r5 = ((NI32)2);
NI32 const cBytesDirect_0_croph25r5 = ((NI32)3);
NI32 const cBytesOverlay_0_croph25r5 = ((NI32)4);
NI32 const cPtrNoDeref_0_croph25r5 = ((NI32)5);
NI32 const cPtrDeclines_0_croph25r5 = ((NI32)6);
NI32 const cWbPtrHome_0_croph25r5 = ((NI32)7);
NI32 const cWbPtrLost_0_croph25r5 = ((NI32)8);
NI32 const cUnhandled_0_croph25r5 = ((NI32)9);
NI32 const cLyingSeqs_0_croph25r5 = ((NI32)10);
NI32 const cGrantsRevoked_0_croph25r5 = ((NI32)11);
NI32 const cAnGranted_0_croph25r5 = ((NI32)12);
NI32 const cAnTouched_0_croph25r5 = ((NI32)13);
NI32 const cAnUnknown_0_croph25r5 = ((NI32)14);
NI32 const cAnNoBody_0_croph25r5 = ((NI32)15);
NI32 const cAnMethod_0_croph25r5 = ((NI32)16);
NI32 const cAnRecursion_0_croph25r5 = ((NI32)17);
NI32 const cAnDepth_0_croph25r5 = ((NI32)18);
NI32 const cAnShape_0_croph25r5 = ((NI32)19);
NI32 const cAnCalleeUnknown_0_croph25r5 = ((NI32)20);
NI32 const cAnNoParam_0_croph25r5 = ((NI32)21);
NI32 const cAnNoField_0_croph25r5 = ((NI32)22);
NI32 const cAnHonoured_0_croph25r5 = ((NI32)23);
NI32 const cAnRevoked_0_croph25r5 = ((NI32)24);
NI32 const cHybridCalls_0_croph25r5 = ((NI32)25);
NI32 const cArenaDeclines_0_croph25r5 = ((NI32)26);
X60Qt_0_IAarrayAiS32ZS27_croph25r5 gCounts_0_croph25r5;
X60Qt_0_IAarraySstring0sysvq0aslS27_croph25r5 gItems_0_croph25r5;
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* gHostNative_0_croph25r5 = NIM_NIL;
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* gSyscall_0_croph25r5 = NIM_NIL;
NI32 xHostCalls_0_croph25r5 = 0;
NI32 xSyscallCalls_0_croph25r5 = 0;
NI32 xNoopDeclines_0_croph25r5 = 0;
NB8 X60QiniGuard_0_croph25r5;
CrossOutcome_0_croph25r5 crossOk_0_croph25r5(Value_0_valzr1t4f* v_0, CrossRoute_0_croph25r5 route_0, string_0_sysvq0asl detail_0){
  CrossOutcome_0_croph25r5 result_2;
  eQwasmovedQ_SX43rossX4futcome0croph25r5_0_croph25r5((&result_2));
  NB8 X60Qx_8;
  if (route_0 == 0){
    X60Qx_8 = NIM_TRUE;}
  else {
    NI32 X60Qx_9 = len_4_sysvq0asl(detail_0);
    X60Qx_8 = (X60Qx_9 == 0);}
  if (X60Qx_8){
    inc_1_I6wjjge_aow2h993l1((&xUnnamedDeclines_0_croph25r5));
    inc_1_I6wjjge_aow2h993l1((&xUnnamedRoute_0_croph25r5));
    Value_0_valzr1t4f X60Qx_10 = vNil_0_valzr1t4f();
    result_2 = (CrossOutcome_0_croph25r5){
      .handled_0 = NIM_FALSE, .v_0 = X60Qx_10, .route_0 = 0, .detail_0 = (string_0_sysvq0asl){
        .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I622427702386968398_croph25r5)}}
    ;
    return result_2;}
  eQdestroyQ_SX43rossX4futcome0croph25r5_0_croph25r5((&result_2));
  Value_0_valzr1t4f X60Qx_11 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_0)));
  string_0_sysvq0asl X60Qx_12 = nimStrDup(detail_0);
  result_2 = (CrossOutcome_0_croph25r5){
    .handled_0 = NIM_TRUE, .v_0 = X60Qx_11, .route_0 = route_0, .detail_0 = X60Qx_12}
  ;
  return result_2;}
CrossOutcome_0_croph25r5 crossDecline_0_croph25r5(CrossRoute_0_croph25r5 route_1, string_0_sysvq0asl reason_0){
  CrossOutcome_0_croph25r5 result_3;
  eQwasmovedQ_SX43rossX4futcome0croph25r5_0_croph25r5((&result_3));
  NI32 X60Qx_13 = len_4_sysvq0asl(reason_0);
  if (X60Qx_13 == 0){
    inc_1_I6wjjge_aow2h993l1((&xUnnamedDeclines_0_croph25r5));
    inc_1_I6wjjge_aow2h993l1((&xUnnamedCross_0_croph25r5));
    Value_0_valzr1t4f X60Qx_14 = vNil_0_valzr1t4f();
    result_3 = (CrossOutcome_0_croph25r5){
      .handled_0 = NIM_FALSE, .v_0 = X60Qx_14, .route_0 = route_1, .detail_0 = (string_0_sysvq0asl){
        .bytes_0 = 1853177086u, .more_0 = (&strlit_0_I3892905952809112992_croph25r5)}}
    ;
    return result_3;}
  eQdestroyQ_SX43rossX4futcome0croph25r5_0_croph25r5((&result_3));
  Value_0_valzr1t4f X60Qx_15 = vNil_0_valzr1t4f();
  string_0_sysvq0asl X60Qx_16 = nimStrDup(reason_0);
  result_3 = (CrossOutcome_0_croph25r5){
    .handled_0 = NIM_FALSE, .v_0 = X60Qx_15, .route_0 = route_1, .detail_0 = X60Qx_16}
  ;
  return result_3;}
NB8 take_0_croph25r5(CrossOutcome_0_croph25r5* o_0, Value_0_valzr1t4f* v_1){
  NB8 result_4;
  if ((*o_0).handled_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
    Value_0_valzr1t4f X60Qx_17 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*o_0).v_0));
    (*v_1) = X60Qx_17;
    return NIM_TRUE;}
  result_4 = NIM_FALSE;
  return result_4;}
string_0_sysvq0asl stageName_0_croph25r5(DeclineStage_0_croph25r5 s_0){
  string_0_sysvq0asl result_9;
  nimStrWasMoved((&result_9));
  string_0_sysvq0asl X60Qx_1;
  nimStrWasMoved((&X60Qx_1));
  switch (s_0){
    case 0:
    {
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 1852138494u, .more_0 = (&strlit_0_I18371599458681458362_croph25r5)}
      ;}
    break;
    case 1:
    {
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 1918987774u, .more_0 = (&strlit_0_I11097756920309624244_croph25r5)}
      ;}
    break;
    case 2:
    {
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I17555607389722195064_croph25r5)}
      ;}
    break;
    case 3:
    {
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I9923954385269310427_croph25r5)}
      ;}
    break;
    case 4:
    {
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 1634623998u, .more_0 = (&strlit_0_I14983304549480785616_croph25r5)}
      ;}
    break;
    case 5:
    {
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 1953065475u, .more_0 = NIM_NIL}
      ;}
    break;
    case 6:
    {
      nimStrDestroy(X60Qx_1);
      X60Qx_1 = (string_0_sysvq0asl){
        .bytes_0 = 1769300734u, .more_0 = (&strlit_0_I10833596585003541936_croph25r5)}
      ;}
    break;}
  nimStrDestroy(result_9);
  result_9 = X60Qx_1;
  nimStrWasMoved((&X60Qx_1));
  nimStrDestroy(X60Qx_1);
  return result_9;
  nimStrDestroy(X60Qx_1);
  return result_9;}
void declineBegin_0_croph25r5(string_0_sysvq0asl callee_0){
  nimStrDestroy(gChainCallee_0_croph25r5);
  string_0_sysvq0asl X60Qx_19 = nimStrDup(callee_0);
  gChainCallee_0_croph25r5 = X60Qx_19;
  eQdestroy_1_I8f0yiq_croph25r5(gChainStages_0_croph25r5);
  seq_0_Iwlfuke_croph25r5 X60Qx_20 = newSeqUninit_0_Injrsqx1_croph25r5(0);
  gChainStages_0_croph25r5 = X60Qx_20;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(gChainReasons_0_croph25r5);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_21 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  gChainReasons_0_croph25r5 = X60Qx_21;}
void declineNote_0_croph25r5(DeclineStage_0_croph25r5 stage_0, string_0_sysvq0asl reason_1){
  NI32 X60Qx_22 = len_4_sysvq0asl(reason_1);
  if (X60Qx_22 == 0){
    inc_1_I6wjjge_aow2h993l1((&xUnnamedDeclines_0_croph25r5));
    inc_1_I6wjjge_aow2h993l1((&xUnnamedCensus_0_croph25r5));
    add_0_Ih7x8oe1_croph25r5((&gChainStages_0_croph25r5), stage_0);
    add_0_Ig6072n_aow7lb5cq1((&gChainReasons_0_croph25r5), (string_0_sysvq0asl){
      .bytes_0 = 1853177086u, .more_0 = (&strlit_0_I3892905952809112992_croph25r5)}
    );
    return;}
  add_0_Ih7x8oe1_croph25r5((&gChainStages_0_croph25r5), stage_0);
  string_0_sysvq0asl X60Qx_23 = nimStrDup(reason_1);
  add_0_Ig6072n_aow7lb5cq1((&gChainReasons_0_croph25r5), X60Qx_23);}
NI32 declineDepth_0_croph25r5(void){
  NI32 result_10;
  NI32 X60Qx_24 = len_3_If0ji891_croph25r5(gChainStages_0_croph25r5);
  result_10 = X60Qx_24;
  return result_10;}
string_0_sysvq0asl blockerReason_0_croph25r5(void){
  string_0_sysvq0asl result_11;
  nimStrWasMoved((&result_11));
  NI32 X60Qx_25 = len_3_Ixq6taz_aow7lb5cq1(gChainReasons_0_croph25r5);
  if (X60Qx_25 == 0){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_11);
  NI32 X60Qx_26 = len_3_Ixq6taz_aow7lb5cq1(gChainReasons_0_croph25r5);
  string_0_sysvq0asl* X60Qx_27 = getQ_7_Ir6d0tw_aow7lb5cq1(gChainReasons_0_croph25r5, ((NI32)(X60Qx_26 - 1)));
  string_0_sysvq0asl X60Qx_28 = nimStrDup((*X60Qx_27));
  result_11 = X60Qx_28;
  return result_11;}
DeclineStage_0_croph25r5 blockerStage_0_croph25r5(void){
  DeclineStage_0_croph25r5 result_12;
  NI32 X60Qx_29 = len_3_If0ji891_croph25r5(gChainStages_0_croph25r5);
  if (X60Qx_29 == 0){
    return 0;}
  NI32 X60Qx_30 = len_3_If0ji891_croph25r5(gChainStages_0_croph25r5);
  DeclineStage_0_croph25r5* X60Qx_31 = getQ_7_Idt9yvi_croph25r5(gChainStages_0_croph25r5, ((NI32)(X60Qx_30 - 1)));
  result_12 = (*X60Qx_31);
  return result_12;}
string_0_sysvq0asl declineChain_0_croph25r5(void){
  string_0_sysvq0asl result_13;
  nimStrWasMoved((&result_13));
  NI32 X60Qx_32 = len_3_Ixq6taz_aow7lb5cq1(gChainReasons_0_croph25r5);
  if (X60Qx_32 == 0){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_13);
  string_0_sysvq0asl X60Qx_33 = ampQ_0_sysvq0asl(gChainCallee_0_croph25r5, (string_0_sysvq0asl){
    .bytes_0 = 2112002u, .more_0 = NIM_NIL}
  );
  result_13 = X60Qx_33;
  NI32 i_2 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_34 = len_3_Ixq6taz_aow7lb5cq1(gChainReasons_0_croph25r5);
      if (i_2 < X60Qx_34){
        if (0 < i_2){
          add_2_sysvq0asl((&result_13), (string_0_sysvq0asl){
            .bytes_0 = 1043144958u, .more_0 = (&strlit_0_I11689404509053140833_croph25r5)}
          );}
        DeclineStage_0_croph25r5* X60Qx_35 = getQ_7_Idt9yvi_croph25r5(gChainStages_0_croph25r5, i_2);
        string_0_sysvq0asl X60Qdesugar_0 = stageName_0_croph25r5((*X60Qx_35));
        string_0_sysvq0asl* X60Qx_36 = getQ_7_Ir6d0tw_aow7lb5cq1(gChainReasons_0_croph25r5, i_2);
        string_0_sysvq0asl X60Qdesugar_1 = nimStrDup((*X60Qx_36));
        NI32 X60Qx_37 = len_4_sysvq0asl(X60Qdesugar_0);
        NI32 X60Qx_38 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 14849u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_39 = len_4_sysvq0asl(X60Qdesugar_1);
        string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_37 + X60Qx_38)) + X60Qx_39)));
        add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_0);
        add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
          .bytes_0 = 14849u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_1);
        add_2_sysvq0asl((&result_13), X60Qdesugar_2);
        inc_1_I6wjjge_aow2h993l1((&i_2));
        nimStrDestroy(X60Qdesugar_2);
        nimStrDestroy(X60Qdesugar_1);
        nimStrDestroy(X60Qdesugar_0);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  DeclineStage_0_croph25r5 X60Qx_40 = blockerStage_0_croph25r5();
  string_0_sysvq0asl X60Qdesugar_3 = stageName_0_croph25r5(X60Qx_40);
  NI32 X60Qx_41 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4241637849034259752_croph25r5)}
  );
  NI32 X60Qx_42 = len_4_sysvq0asl(X60Qdesugar_3);
  NI32 X60Qx_43 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_4 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_41 + X60Qx_42)) + X60Qx_43)));
  add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4241637849034259752_croph25r5)}
  );
  add_2_sysvq0asl((&X60Qdesugar_4), X60Qdesugar_3);
  add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&result_13), X60Qdesugar_4);
  nimStrDestroy(X60Qdesugar_4);
  nimStrDestroy(X60Qdesugar_3);
  return result_13;
  nimStrDestroy(X60Qdesugar_4);
  nimStrDestroy(X60Qdesugar_3);
  return result_13;}
void bump_0_croph25r5(NI32 c_0, NI32 by_0){
  NI32 X60Qx_44 = nimIcheckB(((NI32)c_0), 26);
  NI32 X60Qx_45 = nimIcheckB(((NI32)c_0), 26);
  gCounts_0_croph25r5.a[X60Qx_44] = ((NI32)(gCounts_0_croph25r5.a[X60Qx_45] + by_0));}
NI32 countOf_0_croph25r5(NI32 c_1){
  NI32 result_14;
  NI32 X60Qx_46 = nimIcheckB(((NI32)c_1), 26);
  result_14 = gCounts_0_croph25r5.a[X60Qx_46];
  return result_14;}
void noteItem_0_croph25r5(NI32 c_2, string_0_sysvq0asl item_0){
  NI32 X60Qx_47 = nimIcheckB(((NI32)c_2), 26);
  string_0_sysvq0asl cur_0 = nimStrDup(gItems_0_croph25r5.a[X60Qx_47]);
  NB8 seen_0 = NIM_FALSE;
  NI32 i_3 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_48 = len_4_sysvq0asl(item_0);
      NI32 X60Qx_49 = len_4_sysvq0asl(cur_0);
      if (((NI32)(i_3 + X60Qx_48)) <= X60Qx_49){
        NI32 k_0 = 0;
        {
          while (NIM_TRUE){
            NB8 X60Qx_50;
            NI32 X60Qx_51 = len_4_sysvq0asl(item_0);
            if (k_0 < X60Qx_51){
              NC8 X60Qx_52 = getQ_9_sysvq0asl(cur_0, ((NI32)(i_3 + k_0)));
              NC8 X60Qx_53 = getQ_9_sysvq0asl(item_0, k_0);
              X60Qx_50 = (X60Qx_52 == X60Qx_53);}
            else {
              X60Qx_50 = NIM_FALSE;}
            if (X60Qx_50){
              inc_1_I6wjjge_aow2h993l1((&k_0));}
            else {
              break;}}}
        whileStmtLabel_1: ;
        NI32 X60Qx_54 = len_4_sysvq0asl(item_0);
        if (k_0 == X60Qx_54){
          seen_0 = NIM_TRUE;
          goto whileStmtLabel_0;}
        inc_1_I6wjjge_aow2h993l1((&i_3));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_55;
  if ((!seen_0)){
    NI32 X60Qx_56 = len_4_sysvq0asl(cur_0);
    X60Qx_55 = (X60Qx_56 < 200);}
  else {
    X60Qx_55 = NIM_FALSE;}
  if (X60Qx_55){
    NI32 X60Qx_57 = len_4_sysvq0asl(cur_0);
    if (0 < X60Qx_57){
      add_2_sysvq0asl((&cur_0), (string_0_sysvq0asl){
        .bytes_0 = 11265u, .more_0 = NIM_NIL}
      );}
    add_2_sysvq0asl((&cur_0), item_0);
    NI32 X60Qx_58 = nimIcheckB(((NI32)c_2), 26);
    string_0_sysvq0asl* X60Qlhs_0 = (&gItems_0_croph25r5.a[X60Qx_58]);
    nimStrDestroy((*X60Qlhs_0));
    (*X60Qlhs_0) = cur_0;
    nimStrWasMoved((&cur_0));}
  nimStrDestroy(cur_0);}
string_0_sysvq0asl itemsOf_0_croph25r5(NI32 c_3){
  string_0_sysvq0asl result_15;
  nimStrWasMoved((&result_15));
  nimStrDestroy(result_15);
  NI32 X60Qx_59 = nimIcheckB(((NI32)c_3), 26);
  string_0_sysvq0asl X60Qx_60 = nimStrDup(gItems_0_croph25r5.a[X60Qx_59]);
  result_15 = X60Qx_60;
  return result_15;}
NB8 xNoArtifact_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* p_1){
  NB8 result_16;
  result_16 = NIM_TRUE;
  return result_16;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* newXProvider_0_croph25r5(string_0_sysvq0asl name_1, X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251ZSstring0sysvq0aslSseq0X4950urnwSX56alue0valzr1t4fAnimcallZAfalseZAR91_croph25r5 run_0, X60Qt_0_ISstring0sysvq0aslSX43rossX52oute0croph25r5AnimcallZAfalseZAR51_croph25r5 route_2, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_0, string_0_sysvq0asl artifact_0){
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* result_17;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&result_17));
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(result_17);
  void* X60Qx_61 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1));
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qtmp_1 = ((X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1*)X60Qx_61);
  string_0_sysvq0asl X60Qx_62 = nimStrDup(name_1);
  string_0_sysvq0asl X60Qx_63 = nimStrDup(artifact_0);
  (*X60Qtmp_1) = (X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1){
    .r_00 = 0, .d_00 = (XProvider_Obj_0_croph25r5){
      .name_0 = X60Qx_62, .run_0 = run_0, .route_0 = route_2, .attest_0 = attest_0, .artifact_0 = X60Qx_63, .attested_0 = NIM_FALSE, .attestRun_0 = NIM_FALSE}}
  ;
  result_17 = X60Qtmp_1;
  return result_17;}
NB8 grantsHonoured_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* p_2){
  NB8 result_18;
  NB8 X60Qx_64;
  if (p_2 == NIM_NIL){
    X60Qx_64 = NIM_TRUE;}
  else {
    X60Qx_64 = (((void*)(*p_2).d_00.attest_0) == NIM_NIL);}
  if (X60Qx_64){
    return NIM_FALSE;}
  if ((!(*p_2).d_00.attestRun_0)){
    (*p_2).d_00.attestRun_0 = NIM_TRUE;
    NB8 X60Qx_65 = (*p_2).d_00.attest_0(p_2);
    (*p_2).d_00.attested_0 = X60Qx_65;
    if ((!(*p_2).d_00.attested_0)){
      bump_0_croph25r5(cGrantsRevoked_0_croph25r5, 1);}}
  result_18 = (*p_2).d_00.attested_0;
  return result_18;}
NB8 isSyscallBase_0_croph25r5(string_0_sysvq0asl base_1){
  NB8 result_19;
  NB8 X60Qtc_1 = nimStrAtLe_0_sysvq0asl(base_1, 6, (NC8)'i');
  if (X60Qtc_1){
    NB8 X60Qtc_2 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'g');
    if (X60Qtc_2){
      NB8 X60Qtc_3 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'f');
      if (X60Qtc_3){
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1970038526u, .more_0 = (&strlit_0_I13219317321365981656_croph25r5)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1684956670u, .more_0 = (&strlit_0_I5792391256252241729_croph25r5)}
        )){
          goto X60Qsc_0;}}
      else {
        NB8 X60Qtc_4 = nimStrAtLe_0_sysvq0asl(base_1, 7, (NC8)'P');
        if (X60Qtc_4){
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I2053446828331389519_croph25r5)}
          )){
            goto X60Qsc_0;}
          else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I15913671615442312297_croph25r5)}
          )){
            goto X60Qsc_0;}}
        else {
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1952802814u, .more_0 = (&strlit_0_I11626809062896146847_croph25r5)}
          )){
            goto X60Qsc_0;}}}}
    else {
      NB8 X60Qtc_5 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'r');
      if (X60Qtc_5){
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I3411051090140283573_croph25r5)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I11445521212967021334_croph25r5)}
        )){
          goto X60Qsc_0;}}
      else {
        NB8 X60Qtc_6 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'s');
        if (X60Qtc_6){
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I15258214261968625836_croph25r5)}
          )){
            goto X60Qsc_0;}}
        else {
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I13565819874765507459_croph25r5)}
          )){
            goto X60Qsc_0;}
          else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I3703669261441550327_croph25r5)}
          )){
            goto X60Qsc_0;}}}}}
  else {
    NB8 X60Qtc_7 = nimStrAtLe_0_sysvq0asl(base_1, 1, (NC8)'e');
    if (X60Qtc_7){
      NB8 X60Qtc_8 = nimStrAtLe_0_sysvq0asl(base_1, 4, (NC8)'F');
      if (X60Qtc_8){
        NB8 X60Qtc_9 = nimStrAtLe_0_sysvq0asl(base_1, 4, (NC8)'A');
        if (X60Qtc_9){
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I4978164850318270062_croph25r5)}
          )){
            goto X60Qsc_0;}}
        else {
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I12542130669033277445_croph25r5)}
          )){
            goto X60Qsc_0;}
          else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I2707782551556965371_croph25r5)}
          )){
            goto X60Qsc_0;}}}
      else {
        NB8 X60Qtc_10 = nimStrAtLe_0_sysvq0asl(base_1, 2, (NC8)'a');
        if (X60Qtc_10){
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I6395244567427789796_croph25r5)}
          )){
            goto X60Qsc_0;}
          else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I2027400509069786846_croph25r5)}
          )){
            goto X60Qsc_0;}}
        else {
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1868919550u, .more_0 = (&strlit_0_I3858632921624769948_croph25r5)}
          )){
            goto X60Qsc_0;}}}}
    else {
      NB8 X60Qtc_11 = nimStrAtLe_0_sysvq0asl(base_1, 0, (NC8)'o');
      if (X60Qtc_11){
        if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_croph25r5)}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I4266325610518786829_croph25r5)}
        )){
          goto X60Qsc_0;}}
      else {
        NB8 X60Qtc_12 = nimStrAtLe_0_sysvq0asl(base_1, 5, (NC8)'B');
        if (X60Qtc_12){
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I6178772090241098573_croph25r5)}
          )){
            goto X60Qsc_0;}
          else if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I100145031017624899_croph25r5)}
          )){
            goto X60Qsc_0;}}
        else {
          if (equalStrings_0_sysvq0asl(base_1, (string_0_sysvq0asl){
            .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I12440307187701028700_croph25r5)}
          )){
            goto X60Qsc_0;}}}}}
  goto X60Qsc_14;
  X60Qsc_0: ;
  result_19 = NIM_TRUE;
  goto X60Qsc_13;
  X60Qsc_14: ;
  result_19 = NIM_FALSE;
  X60Qsc_13: ;
  return result_19;}
CrossRoute_0_croph25r5 nativeRoute_0_croph25r5(string_0_sysvq0asl base_2){
  CrossRoute_0_croph25r5 result_20;
  CrossRoute_0_croph25r5 X60Qx_2;
  NB8 X60Qx_66 = isSyscallBase_0_croph25r5(base_2);
  if (X60Qx_66){
    X60Qx_2 = 2;}
  else {
    X60Qx_2 = 1;}
  result_20 = X60Qx_2;
  return result_20;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* nativeSpine_0_croph25r5(void){
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* result_21;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&result_21));
  if (gHostNative_0_croph25r5 == NIM_NIL){
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(gHostNative_0_croph25r5);
    X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qx_67 = newXProvider_0_croph25r5((string_0_sysvq0asl){
      .bytes_0 = 1936681214u, .more_0 = (&strlit_0_I3769781912767351299_croph25r5)}
    , nativeCall_0_runot4689, nativeRoute_0_croph25r5, xNoArtifact_0_croph25r5, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    gHostNative_0_croph25r5 = X60Qx_67;}
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(result_21);
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qx_68 = eQdupQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(gHostNative_0_croph25r5);
  result_21 = X60Qx_68;
  return result_21;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* syscallSpine_0_croph25r5(void){
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* result_22;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&result_22));
  if (gSyscall_0_croph25r5 == NIM_NIL){
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(gSyscall_0_croph25r5);
    X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qx_69 = newXProvider_0_croph25r5((string_0_sysvq0asl){
      .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I2072093345082808027_cal1yym9t1)}
    , nativeCall_0_runot4689, nativeRoute_0_croph25r5, xNoArtifact_0_croph25r5, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    gSyscall_0_croph25r5 = X60Qx_69;}
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(result_22);
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qx_70 = eQdupQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(gSyscall_0_croph25r5);
  result_22 = X60Qx_70;
  return result_22;}
Value_0_valzr1t4f runNativeSpine_0_croph25r5(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_1, string_0_sysvq0asl base_3, seq_0_I50urnw_croph25r5 args_1, CrossRoute_0_croph25r5* route_3, NB8* noopDeclined_0){
  Value_0_valzr1t4f result_23;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_23));
  CrossRoute_0_croph25r5 X60Qx_71 = nativeRoute_0_croph25r5(base_3);
  (*route_3) = X60Qx_71;
  (*noopDeclined_0) = NIM_FALSE;
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qx_3;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&X60Qx_3));
  if ((*route_3) == 2){
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
    X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qx_72 = syscallSpine_0_croph25r5();
    X60Qx_3 = X60Qx_72;}
  else {
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
    X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qx_73 = nativeSpine_0_croph25r5();
    X60Qx_3 = X60Qx_73;}
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* p_3 = X60Qx_3;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&X60Qx_3));
  NI32 before_0 = noopHits_0_runot4689;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_23));
  Value_0_valzr1t4f X60Qx_74 = (*p_3).d_00.run_0(sink_1, base_3, args_1);
  result_23 = X60Qx_74;
  if (before_0 < noopHits_0_runot4689){
    inc_1_I6wjjge_aow2h993l1((&xNoopDeclines_0_croph25r5));
    (*noopDeclined_0) = NIM_TRUE;
    Value_0_valzr1t4f X60Qx_75 = vNil_0_valzr1t4f();
    result_23 = X60Qx_75;
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(p_3);
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
    return result_23;}
  if ((*route_3) == 2){
    inc_1_I6wjjge_aow2h993l1((&xSyscallCalls_0_croph25r5));}
  else {
    inc_1_I6wjjge_aow2h993l1((&xHostCalls_0_croph25r5));}
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(p_3);
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
  return result_23;
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(p_3);
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
  return result_23;}
Value_0_valzr1t4f crossNativeValue_0_croph25r5(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_3, string_0_sysvq0asl base_5, seq_0_I50urnw_croph25r5 args_3){
  Value_0_valzr1t4f result_25;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_25));
  CrossRoute_0_croph25r5 r_2 = 0;
  NB8 noopDeclined_2 = NIM_FALSE;
  Value_0_valzr1t4f v_3 = runNativeSpine_0_croph25r5(sink_3, base_5, args_3, (&r_2), (&noopDeclined_2));
  if (noopDeclined_2){
    Value_0_valzr1t4f X60Qx_78 = vNil_0_valzr1t4f();
    result_25 = X60Qx_78;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
    return result_25;}
  NI32 X60Qx_79 = len_4_sysvq0asl(base_5);
  if (X60Qx_79 == 0){
    inc_1_I6wjjge_aow2h993l1((&xUnnamedDeclines_0_croph25r5));
    inc_1_I6wjjge_aow2h993l1((&xUnnamedRoute_0_croph25r5));
    Value_0_valzr1t4f X60Qx_80 = vNil_0_valzr1t4f();
    result_25 = X60Qx_80;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
    return result_25;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_25));
  result_25 = v_3;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
  return result_25;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
  return result_25;}
NB8 routeLog_0_croph25r5(void){
  NB8 result_26;
  NB8 X60Qx_7;
  string_0_sysvq0asl X60Qtmp_3 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I1312293394728271086_croph25r5)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_81 = eqQ_20_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  if (X60Qx_81){
    X60Qx_7 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_4 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I819492781050547440_croph25r5)}
    , (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_82 = eqQ_20_sysvq0asl(X60Qtmp_4, (string_0_sysvq0asl){
      .bytes_0 = 12545u, .more_0 = NIM_NIL}
    );
    X60Qx_7 = X60Qx_82;
    nimStrDestroy(X60Qtmp_4);}
  result_26 = X60Qx_7;
  nimStrDestroy(X60Qtmp_3);
  return result_26;
  nimStrDestroy(X60Qtmp_3);
  return result_26;}
static inline seq_0_Iwlfuke_croph25r5 newSeqUninit_0_Injrsqx1_croph25r5(NI32 size_2){
  seq_0_Iwlfuke_croph25r5 result_28;
  if (size_2 == 0){
    result_28 = (seq_0_Iwlfuke_croph25r5){
      .len_0 = size_2, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_I45nzb5_croph25r5(size_2);
    void* X60Qx_105 = alloc_1_sysvq0asl(memSize_0);
    result_28 = (seq_0_Iwlfuke_croph25r5){
      .len_0 = size_2, .data_0 = ((DeclineStage_0_croph25r5*)X60Qx_105)}
    ;
    if ((!(result_28.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_106 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_28.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_28;}
static inline void add_0_Ih7x8oe1_croph25r5(seq_0_Iwlfuke_croph25r5* s_7, DeclineStage_0_croph25r5 elem_2){
  NI32 L_0 = (*s_7).len_0;
  NI32 X60Qx_109 = capInBytes_0_I41twvj1_croph25r5((*s_7));
  if (X60Qx_109 < ((NI32)(((NI32)(L_0 * sizeof(DeclineStage_0_croph25r5))) + sizeof(DeclineStage_0_croph25r5)))){
    NB8 X60Qx_110 = resize_0_Ig39hrf_croph25r5(s_7, 1);
    if ((!X60Qx_110)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_7).len_0));
  (*s_7).data_0[L_0] = elem_2;}
static inline NI32 len_3_If0ji891_croph25r5(seq_0_Iwlfuke_croph25r5 s_11){
  NI32 result_30;
  result_30 = s_11.len_0;
  return result_30;}
static inline DeclineStage_0_croph25r5* getQ_7_Idt9yvi_croph25r5(seq_0_Iwlfuke_croph25r5 s_14, NI32 i_5){
  NB8 X60Qx_114;
  if (i_5 < s_14.len_0){
    X60Qx_114 = (0 <= i_5);}
  else {
    X60Qx_114 = NIM_FALSE;}
  if ((!X60Qx_114)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  DeclineStage_0_croph25r5* result_33;
  result_33 = (&s_14.data_0[i_5]);
  return result_33;}
static inline NI32 memSizeInBytes_0_I45nzb5_croph25r5(NI32 size_6){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_34;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_6, sizeof(DeclineStage_0_croph25r5), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_34 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_34 = ((NI32)2147483647);}
  return result_34;}
static inline NI32 capInBytes_0_I41twvj1_croph25r5(seq_0_Iwlfuke_croph25r5 s_15){
  NI32 result_36;
  NI32 X60Qx_4;
  if ((!(s_15.data_0 == NIM_NIL))){
    NI32 X60Qx_115 = allocatedSize_0_sysvq0asl(((void*)((void*)s_15.data_0)));
    X60Qx_4 = X60Qx_115;}
  else {
    X60Qx_4 = 0;}
  result_36 = X60Qx_4;
  return result_36;}
NB8 resize_0_Ig39hrf_croph25r5(seq_0_Iwlfuke_croph25r5* dest_2, NI32 addedElements_2){
  NB8 result_37;
  NI32 X60Qx_116 = capInBytes_0_I41twvj1_croph25r5((*dest_2));
  NI32 oldCap_0 = ((NI32)(X60Qx_116 / sizeof(DeclineStage_0_croph25r5)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_2);
  NI32 memSize_2 = memSizeInBytes_0_I45nzb5_croph25r5(newCap_0);
  void* X60Qx_117 = realloc_1_sysvq0asl(((void*)((void*)(*dest_2).data_0)), memSize_2);
  (*dest_2).data_0 = ((DeclineStage_0_croph25r5*)X60Qx_117);
  if ((*dest_2).data_0 == NIM_NIL){
    (*dest_2).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_2);
    result_37 = NIM_FALSE;}
  else {
    result_37 = NIM_TRUE;}
  return result_37;}
void eQdestroy_1_Inxd7ue1_croph25r5(seq_0_I50urnw_croph25r5 s_23){
  if ((!(s_23.data_0 == NIM_NIL))){
    NI32 i_6 = 0;
    {
      while (i_6 < s_23.len_0){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&s_23.data_0[i_6]));
        inc_1_I6wjjge_aow2h993l1((&i_6));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_23.data_0)));}}
static inline void eQwasMoved_1_Ivxly0t1_croph25r5(seq_0_I50urnw_croph25r5* s_24){
  (*s_24).len_0 = 0;
  (*s_24).data_0 = NIM_NIL;}
seq_0_I50urnw_croph25r5 eQdup_1_I28mx5s1_croph25r5(seq_0_I50urnw_croph25r5 a_3){
  seq_0_I50urnw_croph25r5 result_40;
  seq_0_I50urnw_croph25r5 X60Qx_121 = newSeqUninit_0_I8oufjc_croph25r5(a_3.len_0);
  result_40 = X60Qx_121;
  NI32 i_7 = 0;
  {
    while (i_7 < a_3.len_0){
      Value_0_valzr1t4f X60Qx_122 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&a_3.data_0[i_7]));
      result_40.data_0[i_7] = X60Qx_122;
      inc_1_I6wjjge_aow2h993l1((&i_7));}}
  whileStmtLabel_0: ;
  return result_40;}
void eQdestroy_1_I8f0yiq_croph25r5(seq_0_Iwlfuke_croph25r5 s_26){
  if ((!(s_26.data_0 == NIM_NIL))){
    NI32 i_10 = 0;
    {
      while (i_10 < s_26.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_10));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_26.data_0)));}}
static inline seq_0_I50urnw_croph25r5 newSeqUninit_0_I8oufjc_croph25r5(NI32 size_10){
  seq_0_I50urnw_croph25r5 result_43;
  if (size_10 == 0){
    result_43 = (seq_0_I50urnw_croph25r5){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_7 = memSizeInBytes_0_Itmy7ww1_croph25r5(size_10);
    void* X60Qx_137 = alloc_1_sysvq0asl(memSize_7);
    result_43 = (seq_0_I50urnw_croph25r5){
      .len_0 = size_10, .data_0 = ((Value_0_valzr1t4f*)X60Qx_137)}
    ;
    if ((!(result_43.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_138 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_43.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_7);}}
  return result_43;}
static inline NI32 capInBytes_0_Ihvsegh1_croph25r5(seq_0_I50urnw_croph25r5 s_30){
  NI32 result_44;
  NI32 X60Qx_6;
  if ((!(s_30.data_0 == NIM_NIL))){
    NI32 X60Qx_139 = allocatedSize_0_sysvq0asl(((void*)((void*)s_30.data_0)));
    X60Qx_6 = X60Qx_139;}
  else {
    X60Qx_6 = 0;}
  result_44 = X60Qx_6;
  return result_44;}
static inline NI32 memSizeInBytes_0_Itmy7ww1_croph25r5(NI32 size_11){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_45;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_11, sizeof(Value_0_valzr1t4f), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_45 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_45 = ((NI32)2147483647);}
  return result_45;}
void eQdestroyQ_SX43rossX4futcome0croph25r5_0_croph25r5(CrossOutcome_0_croph25r5* dest_0){
  nimStrDestroy((*dest_0).detail_0);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).v_0));}
void eQwasmovedQ_SX43rossX4futcome0croph25r5_0_croph25r5(CrossOutcome_0_croph25r5* dest_0){
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).v_0));
  nimStrWasMoved((&(*dest_0).detail_0));}
void eQdestroyQ_SX58X50roviderX4fbj0croph25r5_0_croph25r5(XProvider_Obj_0_croph25r5* dest_0){
  nimStrDestroy((*dest_0).artifact_0);
  nimStrDestroy((*dest_0).name_0);}
void eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_145 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_145){
      eQdestroyQ_SX58X50roviderX4fbj0croph25r5_0_croph25r5((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_AarraySstring0sysvq0aslS27_0_croph25r5(X60Qt_0_IAarraySstring0sysvq0aslS27_croph25r5* dest_0){
  NI idx_0 = 0;
  while (idx_0 < 27){
    nimStrWasMoved((&(*dest_0).a[idx_0]));
    idx_0 = ((NI)(idx_0 + 1));}}
void eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* eQdupQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* src_0){
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void X60Qini_0_croph25r5(void){
  if (X60QiniGuard_0_croph25r5){
    return;}
  X60QiniGuard_0_croph25r5 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_envto7w6l1();
  X60Qini_0_valzr1t4f();
  X60Qini_0_natd5co251();
  X60Qini_0_runot4689();
  gChainStages_0_croph25r5 = newSeqUninit_0_Injrsqx1_croph25r5(0);
  gChainReasons_0_croph25r5 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  eQwasmovedQ_AarraySstring0sysvq0aslS27_0_croph25r5((&gItems_0_croph25r5));}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_75;
  if (size_8 == 0){
    result_75 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_I7me00i_aow7lb5cq1(size_8);
    void* X60Qx_2279 = alloc_1_sysvq0asl(memSize_1);
    result_75 = (seq_0_Ixdx2fh1_aow7lb5cq1){
      .len_0 = size_8, .data_0 = ((string_0_sysvq0asl*)X60Qx_2279)}
    ;
    if ((!(result_75.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2280 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_75.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_75;}
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9){
  NI32 L_0 = (*s_35).len_0;
  NI32 X60Qx_2281 = capInBytes_0_Ih2sbn01_aow7lb5cq1((*s_35));
  if (X60Qx_2281 < ((NI32)(((NI32)(L_0 * sizeof(string_0_sysvq0asl))) + sizeof(string_0_sysvq0asl)))){
    NB8 X60Qx_2282 = resize_0_I4buliy_aow7lb5cq1(s_35, 1);
    if ((!X60Qx_2282)){
      nimStrDestroy(elem_9);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_35).len_0));
  (*s_35).data_0[L_0] = elem_9;}
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37){
  NI32 result_76;
  result_76 = s_37.len_0;
  return result_76;}
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39){
  NB8 X60Qx_2283;
  if (i_39 < s_38.len_0){
    X60Qx_2283 = (0 <= i_39);}
  else {
    X60Qx_2283 = NIM_FALSE;}
  if ((!X60Qx_2283)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* result_77;
  result_77 = (&s_38.data_0[i_39]);
  return result_77;}
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
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0){
  NB8 result_127;
  NB8 X60Qx_284;
  NI32 X60Qx_285 = len_4_sysvq0asl(s_58);
  if (idx_2 < X60Qx_285){
    NC8 X60Qx_286 = getQ_9_sysvq0asl(s_58, idx_2);
    X60Qx_284 = (X60Qx_286 <= ch_0);}
  else {
    X60Qx_284 = NIM_FALSE;}
  result_127 = X60Qx_284;
  return result_127;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_99;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_19, sizeof(string_0_sysvq0asl), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_99 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_99 = ((NI32)2147483647);}
  return result_99;}
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65){
  NI32 result_102;
  NI32 X60Qx_18;
  if ((!(s_65.data_0 == NIM_NIL))){
    NI32 X60Qx_2314 = allocatedSize_0_sysvq0asl(((void*)((void*)s_65.data_0)));
    X60Qx_18 = X60Qx_2314;}
  else {
    X60Qx_18 = 0;}
  result_102 = X60Qx_18;
  return result_102;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
