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
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689 X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1 X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5 X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct seq_0_I50urnw_chu5m1rja1 seq_0_I50urnw_chu5m1rja1;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5 X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
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
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
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
      NU32 ekind_0;
      string_0_sysvq0asl ename_0;}
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
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0;
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0;
      NI32 base_0;
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0;
      NI32 foff_0;
      NI16 elemBits_0;
      TCode_0_valzr1t4f ecode_0;
      NU32 etype_0;}
    ;
    struct {
      X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* st_0;}
    ;
    struct {
      NU32 fn_0;
      NI32 pidx_0;
      X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_0;
      NI32 resume_0;}
    ;
    struct {
      NB8 toErr_0;}
    ;
    struct {
      X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* coro_0;}
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
typedef N_NIMCALL_PTR(Value_0_valzr1t4f,  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251ZSstring0sysvq0aslSseq0X4950urnwSX56alue0valzr1t4fAnimcallZAfalseZAR91_croph25r5)(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5*, string_0_sysvq0asl, seq_0_I50urnw_chu5m1rja1);
typedef N_NIMCALL_PTR(CrossRoute_0_croph25r5,  X60Qt_0_ISstring0sysvq0aslSX43rossX52oute0croph25r5AnimcallZAfalseZAR51_croph25r5)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5)(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5*);
typedef struct XProvider_Obj_0_croph25r5{
  string_0_sysvq0asl name_0;
  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251ZSstring0sysvq0aslSseq0X4950urnwSX56alue0valzr1t4fAnimcallZAfalseZAR91_croph25r5 run_0;
  X60Qt_0_ISstring0sysvq0aslSX43rossX52oute0croph25r5AnimcallZAfalseZAR51_croph25r5 route_0;
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_0;
  string_0_sysvq0asl artifact_0;
  NB8 attested_0;
  NB8 attestRun_0;}
XProvider_Obj_0_croph25r5;
typedef struct seq_0_I50urnw_chu5m1rja1{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_chu5m1rja1;
typedef struct seq_0_Iwlfuke_croph25r5{
  NI32 len_0;
  DeclineStage_0_croph25r5* data_0;}
seq_0_Iwlfuke_croph25r5;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslAnimcallZAfalseZAR26_natd5co251)(void);
typedef struct seq_0_Iygo52q1_hos5i19e11{
  NI32 len_0;
  FILE** data_0;}
seq_0_Iygo52q1_hos5i19e11;
typedef struct seq_0_I9xd2d01_hos5i19e11{
  NI32 len_0;
  X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11** data_0;}
seq_0_I9xd2d01_hos5i19e11;
typedef N_NIMCALL_PTR(Value_0_valzr1t4f,  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251)(NI64, string_0_sysvq0asl, seq_0_I50urnw_chu5m1rja1, NB8*);
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
  seq_0_Ixdx2fh1_ast8ri79k argv_0;
  seq_0_Iygo52q1_hos5i19e11 fds_0;
  seq_0_I9xd2d01_hos5i19e11 pipeFds_0;
  seq_0_Ixdx2fh1_ast8ri79k envKeys_0;
  seq_0_Ixdx2fh1_ast8ri79k envVals_0;
  NB8 envSeeded_0;
  seq_0_Ixdx2fh1_ast8ri79k failedReads_0;
  NI32 failedReadCount_0;
  NI64 hostContext_0;
  X60Qt_0_IAiS64ZSstring0sysvq0aslSseq0X4950urnwAmutAboolZZSX56alue0valzr1t4fAnimcallZAfalseZAR75_natd5co251 hostCall_0;}
OutSink_Obj_0_natd5co251;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5{
  NI r_00;
  OutSink_Obj_0_natd5co251 d_00;}
X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5{
  NI r_00;
  XProvider_Obj_0_croph25r5 d_00;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct seq_0_Iw8xl5b1_flaksyopx1{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_flaksyopx1;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_ast8ri79k names_0;
  seq_0_Iw8xl5b1_flaksyopx1 cells_0;}
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
typedef NU8 RegionKind_0_valzr1t4f;

#define rkBytes_0_valzr1t4f ((NU8)0)
#define rkSeq_0_valzr1t4f ((NU8)1)
#define rkArr_0_valzr1t4f ((NU8)2)
#define rkStr_0_valzr1t4f ((NU8)3)
#define rkCell_0_valzr1t4f ((NU8)4)
#define rkObj_0_valzr1t4f ((NU8)5)
#define rkForeign_0_valzr1t4f ((NU8)6)
typedef struct seq_0_Incv1wn_explnj22x1{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_explnj22x1;
typedef struct FlatRegion_Obj_0_valzr1t4f{
  RegionKind_0_valzr1t4f kind_0;
  union {
    struct {
      seq_0_Incv1wn_explnj22x1 bytes_0;
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
      seq_0_Ift2sne_chu5m1rja1 offs_0;}
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
typedef struct X60Qt_0_IAarrayAuS64ZS4_runot4689{
  NU64 a[4];}
X60Qt_0_IAarrayAuS64ZS4_runot4689;
typedef struct SetBox_Obj_0_valzr1t4f{
  X60Qt_0_IAarrayAuS64ZS4_runot4689 words_0;}
SetBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689{
  NI r_00;
  SetBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct ClosureEnv_Obj_0_valzr1t4f{
  seq_0_In6doa_ast8ri79k vars_0;
  seq_0_Iw8xl5b1_flaksyopx1 cells_0;
  X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* coro_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;}
ClosureEnv_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1{
  NI r_00;
  ClosureEnv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
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
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
static inline NI32 memSizeInBytes_0_I45nzb5_croph25r5(NI32 size_9);
void eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* dest_0);
void eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5** dest_0);
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* eQdupQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* src_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline void add_0_Ig6072n_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_20, string_0_sysvq0asl elem_3);
static inline void add_0_I8kd4i4_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_114, NI32 elem_27);
static inline NI32 len_3_Ixq6taz_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_130);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I9592449470941440445_comaa5xpt1;
extern Value_0_valzr1t4f nativeCall_0_runot4689(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_14, string_0_sysvq0asl name_7, seq_0_I50urnw_chu5m1rja1 args_5);
extern LongString_0_sysvq0asl const strlit_0_I2072093345082808027_cal1yym9t1;
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern NI32 noopHits_0_runot4689;
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern Value_0_valzr1t4f vNil_0_valzr1t4f(void);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_comaa5xpt1;
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_envto7w6l1(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_natd5co251(void);
extern void X60Qini_0_runot4689(void);
static inline seq_0_Ixdx2fh1_ast8ri79k newSeqUninit_0_Im3cqd9_ast8ri79k(NI32 size_20);
static inline seq_0_Ift2sne_chu5m1rja1 newSeqUninit_0_Iggfvwp_chu5m1rja1(NI32 size_32);
extern string_0_sysvq0asl getEnv_0_envto7w6l1(string_0_sysvq0asl key_1, string_0_sysvq0asl default_0);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline NI32 capInBytes_0_Ih2sbn01_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_28);
extern NB8 resize_0_I4buliy_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* dest_2, NI32 addedElements_2);
static inline NI32 capInBytes_0_Iet286n_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_72);
extern NB8 resize_0_I8l4tya_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* dest_22, NI32 addedElements_22);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NI32 memSizeInBytes_0_I7me00i_ast8ri79k(NI32 size_4);
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
LongString_0_sysvq0asl const strlit_0_I8446236512461598146_croph25r5 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "none"}
;
LongString_0_sysvq0asl const strlit_0_I3769781912767351299_croph25r5 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "host-native"}
;
LongString_0_sysvq0asl const strlit_0_I10833596585003541936_croph25r5 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "build"}
;
LongString_0_sysvq0asl const strlit_0_I5296348581242699135_croph25r5 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "attest.revoked"}
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
seq_0_Iwlfuke_croph25r5 gChainStages_0_croph25r5;
seq_0_Ixdx2fh1_ast8ri79k gChainReasons_0_croph25r5;
seq_0_Ixdx2fh1_ast8ri79k gCountNames_0_croph25r5;
seq_0_Ift2sne_chu5m1rja1 gCounts_0_croph25r5;
seq_0_Ixdx2fh1_ast8ri79k gItems_0_croph25r5;
NI32 cGrantsRevoked_0_croph25r5;
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* gHostNative_0_croph25r5 = NIM_NIL;
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* gSyscall_0_croph25r5 = NIM_NIL;
NI32 xHostCalls_0_croph25r5 = 0;
NI32 xSyscallCalls_0_croph25r5 = 0;
NI32 xNoopDeclines_0_croph25r5 = 0;
NB8 routeLog_0_croph25r5;
NB8 X60QiniGuard_0_croph25r5;
NI32 newRouteCounter_0_croph25r5(string_0_sysvq0asl name_0){
  NI32 result_14;
  string_0_sysvq0asl X60Qx_45 = nimStrDup(name_0);
  add_0_Ig6072n_ast8ri79k((&gCountNames_0_croph25r5), X60Qx_45);
  add_0_I8kd4i4_comaa5xpt1((&gCounts_0_croph25r5), 0);
  add_0_Ig6072n_ast8ri79k((&gItems_0_croph25r5), (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_46 = len_3_Ixq6taz_comaa5xpt1(gCountNames_0_croph25r5);
  result_14 = ((NI32)((NI32)(X60Qx_46 - 1)));
  return result_14;}
NB8 xNoArtifact_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* p_1){
  NB8 result_17;
  result_17 = NIM_TRUE;
  return result_17;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* newXProvider_0_croph25r5(string_0_sysvq0asl name_2, X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251ZSstring0sysvq0aslSseq0X4950urnwSX56alue0valzr1t4fAnimcallZAfalseZAR91_croph25r5 run_0, X60Qt_0_ISstring0sysvq0aslSX43rossX52oute0croph25r5AnimcallZAfalseZAR51_croph25r5 route_2, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_0, string_0_sysvq0asl artifact_0){
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* result_18;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&result_18));
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(result_18);
  void* X60Qx_62 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5));
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* X60Qtmp_1 = ((X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5*)X60Qx_62);
  string_0_sysvq0asl X60Qx_63 = nimStrDup(name_2);
  string_0_sysvq0asl X60Qx_64 = nimStrDup(artifact_0);
  (*X60Qtmp_1) = (X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5){
    .r_00 = 0, .d_00 = (XProvider_Obj_0_croph25r5){
      .name_0 = X60Qx_63, .run_0 = run_0, .route_0 = route_2, .attest_0 = attest_0, .artifact_0 = X60Qx_64, .attested_0 = NIM_FALSE, .attestRun_0 = NIM_FALSE}}
  ;
  result_18 = X60Qtmp_1;
  return result_18;}
NB8 isSyscallBase_0_croph25r5(string_0_sysvq0asl base_1){
  NB8 result_20;
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
          .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_comaa5xpt1)}
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
  result_20 = NIM_TRUE;
  goto X60Qsc_13;
  X60Qsc_14: ;
  result_20 = NIM_FALSE;
  X60Qsc_13: ;
  return result_20;}
CrossRoute_0_croph25r5 nativeRoute_0_croph25r5(string_0_sysvq0asl base_2){
  CrossRoute_0_croph25r5 result_21;
  CrossRoute_0_croph25r5 X60Qx_2;
  NB8 X60Qx_67 = isSyscallBase_0_croph25r5(base_2);
  if (X60Qx_67){
    X60Qx_2 = 2;}
  else {
    X60Qx_2 = 1;}
  result_21 = X60Qx_2;
  return result_21;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* nativeSpine_0_croph25r5(void){
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* result_22;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&result_22));
  if (gHostNative_0_croph25r5 == NIM_NIL){
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(gHostNative_0_croph25r5);
    X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* X60Qx_68 = newXProvider_0_croph25r5((string_0_sysvq0asl){
      .bytes_0 = 1936681214u, .more_0 = (&strlit_0_I3769781912767351299_croph25r5)}
    , nativeCall_0_runot4689, nativeRoute_0_croph25r5, xNoArtifact_0_croph25r5, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    gHostNative_0_croph25r5 = X60Qx_68;}
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(result_22);
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* X60Qx_69 = eQdupQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(gHostNative_0_croph25r5);
  result_22 = X60Qx_69;
  return result_22;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* syscallSpine_0_croph25r5(void){
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* result_23;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&result_23));
  if (gSyscall_0_croph25r5 == NIM_NIL){
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(gSyscall_0_croph25r5);
    X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* X60Qx_70 = newXProvider_0_croph25r5((string_0_sysvq0asl){
      .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I2072093345082808027_cal1yym9t1)}
    , nativeCall_0_runot4689, nativeRoute_0_croph25r5, xNoArtifact_0_croph25r5, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    gSyscall_0_croph25r5 = X60Qx_70;}
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(result_23);
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* X60Qx_71 = eQdupQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(gSyscall_0_croph25r5);
  result_23 = X60Qx_71;
  return result_23;}
Value_0_valzr1t4f runNativeSpine_0_croph25r5(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_1, string_0_sysvq0asl base_3, seq_0_I50urnw_chu5m1rja1 args_1, CrossRoute_0_croph25r5* route_3, NB8* noopDeclined_0){
  Value_0_valzr1t4f result_24;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_24));
  CrossRoute_0_croph25r5 X60Qx_72 = nativeRoute_0_croph25r5(base_3);
  (*route_3) = X60Qx_72;
  (*noopDeclined_0) = NIM_FALSE;
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* X60Qx_3;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&X60Qx_3));
  if ((*route_3) == 2){
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
    X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* X60Qx_73 = syscallSpine_0_croph25r5();
    X60Qx_3 = X60Qx_73;}
  else {
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
    X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* X60Qx_74 = nativeSpine_0_croph25r5();
    X60Qx_3 = X60Qx_74;}
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* p_3 = X60Qx_3;
  eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5((&X60Qx_3));
  NI32 before_0 = noopHits_0_runot4689;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_24));
  Value_0_valzr1t4f X60Qx_75 = (*p_3).d_00.run_0(sink_1, base_3, args_1);
  result_24 = X60Qx_75;
  if (before_0 < noopHits_0_runot4689){
    inc_1_I6wjjge_aow2h993l1((&xNoopDeclines_0_croph25r5));
    (*noopDeclined_0) = NIM_TRUE;
    Value_0_valzr1t4f X60Qx_76 = vNil_0_valzr1t4f();
    result_24 = X60Qx_76;
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(p_3);
    eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
    return result_24;}
  if ((*route_3) == 2){
    inc_1_I6wjjge_aow2h993l1((&xSyscallCalls_0_croph25r5));}
  else {
    inc_1_I6wjjge_aow2h993l1((&xHostCalls_0_croph25r5));}
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(p_3);
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
  return result_24;
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(p_3);
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qx_3);
  return result_24;}
Value_0_valzr1t4f crossNativeValue_0_croph25r5(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5* sink_3, string_0_sysvq0asl base_5, seq_0_I50urnw_chu5m1rja1 args_3){
  Value_0_valzr1t4f result_26;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_26));
  CrossRoute_0_croph25r5 r_2 = 0;
  NB8 noopDeclined_2 = NIM_FALSE;
  Value_0_valzr1t4f v_3 = runNativeSpine_0_croph25r5(sink_3, base_5, args_3, (&r_2), (&noopDeclined_2));
  if (noopDeclined_2){
    Value_0_valzr1t4f X60Qx_79 = vNil_0_valzr1t4f();
    result_26 = X60Qx_79;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
    return result_26;}
  NI32 X60Qx_80 = len_4_sysvq0asl(base_5);
  if (X60Qx_80 == 0){
    inc_1_I6wjjge_aow2h993l1((&xUnnamedDeclines_0_croph25r5));
    inc_1_I6wjjge_aow2h993l1((&xUnnamedRoute_0_croph25r5));
    Value_0_valzr1t4f X60Qx_81 = vNil_0_valzr1t4f();
    result_26 = X60Qx_81;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
    return result_26;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_26));
  result_26 = v_3;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
  return result_26;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_3));
  return result_26;}
static inline seq_0_Iwlfuke_croph25r5 newSeqUninit_0_Injrsqx1_croph25r5(NI32 size_3){
  seq_0_Iwlfuke_croph25r5 result_28;
  if (size_3 == 0){
    result_28 = (seq_0_Iwlfuke_croph25r5){
      .len_0 = size_3, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_I45nzb5_croph25r5(size_3);
    void* X60Qx_106 = alloc_1_sysvq0asl(memSize_0);
    result_28 = (seq_0_Iwlfuke_croph25r5){
      .len_0 = size_3, .data_0 = ((DeclineStage_0_croph25r5*)X60Qx_106)}
    ;
    if ((!(result_28.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_107 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_28.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_28;}
static inline void putQ_7_Ild9iim_croph25r5(seq_0_Ixdx2fh1_ast8ri79k* s_23, NI32 i_11, string_0_sysvq0asl elem_9){
  NB8 X60Qx_122;
  if (i_11 < (*s_23).len_0){
    X60Qx_122 = (0 <= i_11);}
  else {
    X60Qx_122 = NIM_FALSE;}
  if ((!X60Qx_122)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  string_0_sysvq0asl* X60Qlhs_5 = (&(*s_23).data_0[i_11]);
  string_0_sysvq0asl X60Qlhs_6 = elem_9;
  nimStrWasMoved((&elem_9));
  nimStrDestroy((*X60Qlhs_5));
  (*X60Qlhs_5) = X60Qlhs_6;
  nimStrDestroy(elem_9);}
static inline NI32 memSizeInBytes_0_I45nzb5_croph25r5(NI32 size_9){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_36;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_9, sizeof(DeclineStage_0_croph25r5), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_36 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_36 = ((NI32)2147483647);}
  return result_36;}
void eQdestroyQ_SX58X50roviderX4fbj0croph25r5_0_croph25r5(XProvider_Obj_0_croph25r5* dest_0){
  nimStrDestroy((*dest_0).artifact_0);
  nimStrDestroy((*dest_0).name_0);}
void eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* dest_0){
  if (dest_0){
    NB8 X60Qx_160 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_160){
      eQdestroyQ_SX58X50roviderX4fbj0croph25r5_0_croph25r5((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* eQdupQ_ArefSX58X50roviderX4fbj0croph25r5_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* src_0){
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_croph25r5* dest_0;
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
  gChainReasons_0_croph25r5 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  gCountNames_0_croph25r5 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  gCounts_0_croph25r5 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  gItems_0_croph25r5 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  cGrantsRevoked_0_croph25r5 = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1953784318u, .more_0 = (&strlit_0_I5296348581242699135_croph25r5)}
  );
  NB8 X60Qx_8;
  string_0_sysvq0asl X60Qtmp_3 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I1312293394728271086_croph25r5)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_82 = eqQ_20_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  if (X60Qx_82){
    X60Qx_8 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_4 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I819492781050547440_croph25r5)}
    , (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_83 = eqQ_20_sysvq0asl(X60Qtmp_4, (string_0_sysvq0asl){
      .bytes_0 = 12545u, .more_0 = NIM_NIL}
    );
    X60Qx_8 = X60Qx_83;
    nimStrDestroy(X60Qtmp_4);}
  routeLog_0_croph25r5 = X60Qx_8;
  nimStrDestroy(X60Qtmp_3);}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
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
static inline NI32 len_3_Ixq6taz_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_130){
  NI32 result_70;
  result_70 = s_130.len_0;
  return result_70;}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
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
