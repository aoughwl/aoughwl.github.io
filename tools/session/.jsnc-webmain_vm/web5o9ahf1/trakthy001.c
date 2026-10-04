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
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689 X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1 X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct CallEvent_0_trakthy001 CallEvent_0_trakthy001;
typedef struct EvalEvent_0_trakthy001 EvalEvent_0_trakthy001;
typedef struct BranchEvent_0_trakthy001 BranchEvent_0_trakthy001;
typedef struct Step_0_trakthy001 Step_0_trakthy001;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef NU8 TraceMode_0_trakthy001;

#define tmOff_0_trakthy001 ((NU8)0)
#define tmCalls_0_trakthy001 ((NU8)1)
#define tmFull_0_trakthy001 ((NU8)2)
#define tmProfile_0_trakthy001 ((NU8)3)
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
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
typedef struct EvalEvent_0_trakthy001{
  string_0_sysvq0asl code_0;
  NI32 line_0;
  NI32 col_0;
  Value_0_valzr1t4f val_0;}
EvalEvent_0_trakthy001;
typedef struct BranchEvent_0_trakthy001{
  string_0_sysvq0asl form_0;
  string_0_sysvq0asl sel_0;
  string_0_sysvq0asl chose_0;
  string_0_sysvq0asl callee_0;
  NI32 line_0;
  NI32 depth_0;}
BranchEvent_0_trakthy001;
typedef NU8 StepKind_0_trakthy001;

#define skEnter_0_trakthy001 ((NU8)0)
#define skExit_0_trakthy001 ((NU8)1)
#define skBranch_0_trakthy001 ((NU8)2)
typedef struct Step_0_trakthy001{
  StepKind_0_trakthy001 kind_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl site_0;}
Step_0_trakthy001;
typedef struct seq_0_I50urnw_chu5m1rja1{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_chu5m1rja1;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct CallEvent_0_trakthy001{
  string_0_sysvq0asl callee_0;
  seq_0_I50urnw_chu5m1rja1 args_0;
  seq_0_Ixdx2fh1_ast8ri79k argsR_0;
  Value_0_valzr1t4f ret_0;
  string_0_sysvq0asl retR_0;
  NI32 depth_0;
  NI32 line_0;
  string_0_sysvq0asl file_0;}
CallEvent_0_trakthy001;
typedef struct seq_0_I00yatg_trakthy001{
  NI32 len_0;
  CallEvent_0_trakthy001* data_0;}
seq_0_I00yatg_trakthy001;
typedef struct seq_0_Ins76rj1_trakthy001{
  NI32 len_0;
  EvalEvent_0_trakthy001* data_0;}
seq_0_Ins76rj1_trakthy001;
typedef struct seq_0_Iuignwf1_trakthy001{
  NI32 len_0;
  BranchEvent_0_trakthy001* data_0;}
seq_0_Iuignwf1_trakthy001;
typedef struct seq_0_Is6l9yr_trakthy001{
  NI32 len_0;
  Step_0_trakthy001* data_0;}
seq_0_Is6l9yr_trakthy001;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
typedef struct seq_0_Ix7ee6h_sempjk6bn1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* data_0;}
seq_0_Ix7ee6h_sempjk6bn1;
typedef struct seq_0_Ikxuplm1_filqx2b6r1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_filqx2b6r1;
typedef struct Table_0_Idzlvr_sempjk6bn1{
  seq_0_Ix7ee6h_sempjk6bn1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Idzlvr_sempjk6bn1;
typedef struct seq_0_Iflf8jf1_fiepkwzpc{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_fiepkwzpc;
typedef struct Trace_Obj_0_trakthy001{
  TraceMode_0_trakthy001 mode_0;
  NI32 depth_0;
  string_0_sysvq0asl text_0;
  seq_0_I00yatg_trakthy001 calls_0;
  seq_0_Ins76rj1_trakthy001 evals_0;
  seq_0_Iuignwf1_trakthy001 branches_0;
  seq_0_Is6l9yr_trakthy001 steps_0;
  NI32 nCalls_0;
  NI32 maxDepth_0;
  NB8 truncated_0;
  NI32 lines_0;
  seq_0_Ift2sne_chu5m1rja1 frames_0;
  Table_0_Idzlvr_sempjk6bn1 prof_0;
  NI32 maxRecordDepth_0;
  seq_0_Iflf8jf1_fiepkwzpc recStack_0;}
Trace_Obj_0_trakthy001;
typedef struct HSlice_0_Inzqy8d_comaa5xpt1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_comaa5xpt1;
typedef struct openArray_0_Ig73pnk_comaa5xpt1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_comaa5xpt1;
typedef struct openArray_0_Ijk0jkw1_feaji4clb1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_feaji4clb1;
typedef struct X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001{
  NI r_00;
  Trace_Obj_0_trakthy001 d_00;}
X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
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
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
static inline seq_0_I00yatg_trakthy001 newSeqUninit_0_Igr8h2d_trakthy001(NI32 size_7);
static inline seq_0_Ins76rj1_trakthy001 newSeqUninit_0_I7r3cpg_trakthy001(NI32 size_9);
static inline seq_0_Iuignwf1_trakthy001 newSeqUninit_0_Ij364uq1_trakthy001(NI32 size_11);
static inline seq_0_Is6l9yr_trakthy001 newSeqUninit_0_Ig7buh21_trakthy001(NI32 size_13);
Table_0_Idzlvr_sempjk6bn1 initTable_0_Id6tqqy1_trakthy001(void);
NI32 getOrDefault_1_Iwgckf31_trakthy001(Table_0_Idzlvr_sempjk6bn1 t_15, string_0_sysvq0asl k_3, NI32 fallback_1);
void putQ_0_Ix03xxw_trakthy001(Table_0_Idzlvr_sempjk6bn1* t_17, string_0_sysvq0asl k_5, NI32 v_2);
static inline void add_0_Ibgb1rj1_trakthy001(seq_0_I00yatg_trakthy001* s_31, CallEvent_0_trakthy001 elem_10);
static inline void add_0_I9sf6zn_trakthy001(seq_0_Is6l9yr_trakthy001* s_33, Step_0_trakthy001 elem_11);
static inline NI32 len_3_Ipsu5z01_trakthy001(seq_0_I00yatg_trakthy001 s_35);
void setLen_0_I0277bu1_trakthy001(seq_0_Iflf8jf1_fiepkwzpc* s_40, NI32 newLen_2);
void setLen_0_Ik1cud6_trakthy001(seq_0_Ift2sne_chu5m1rja1* s_45, NI32 newLen_5);
static inline CallEvent_0_trakthy001* getQ_7_I6fsagi1_trakthy001(seq_0_I00yatg_trakthy001 s_48, NI32 i_16);
static inline void add_0_Iiokvvq_trakthy001(seq_0_Ins76rj1_trakthy001* s_49, EvalEvent_0_trakthy001 elem_13);
static inline NI32 memSizeInBytes_0_I219gvk_trakthy001(NI32 size_23);
static inline NI32 memSizeInBytes_0_Ivrxvb8_trakthy001(NI32 size_24);
static inline NI32 memSizeInBytes_0_Iyus9bq_trakthy001(NI32 size_25);
static inline NI32 memSizeInBytes_0_Ic2zc331_trakthy001(NI32 size_26);
NI32 rawGet_0_Ik917wh_trakthy001(Table_0_Idzlvr_sempjk6bn1 t_20, string_0_sysvq0asl k_7, NU32 kh_1);
static inline X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* getQ_7_Ioesyu2_trakthy001(seq_0_Ix7ee6h_sempjk6bn1 s_61, NI32 i_23);
void rawPut_0_Isxoisv_trakthy001(Table_0_Idzlvr_sempjk6bn1* t_21, string_0_sysvq0asl k_8, NI32 v_4, NU32 h_3);
static inline NI32 capInBytes_0_Iqgh8781_trakthy001(seq_0_I00yatg_trakthy001 s_67);
NB8 resize_0_Ixa06i01_trakthy001(seq_0_I00yatg_trakthy001* dest_9, NI32 addedElements_9);
static inline NI32 capInBytes_0_Ig7toyf1_trakthy001(seq_0_Is6l9yr_trakthy001 s_68);
NB8 resize_0_I8n8isu_trakthy001(seq_0_Is6l9yr_trakthy001* dest_10, NI32 addedElements_10);
void shrink_0_Iw0ki4f1_trakthy001(seq_0_Iflf8jf1_fiepkwzpc* s_70, NI32 newLen_8);
void growUnsafe_0_Ip180zg1_trakthy001(seq_0_Iflf8jf1_fiepkwzpc* s_71, NI32 newLen_9);
void shrink_0_Icjjln7_trakthy001(seq_0_Ift2sne_chu5m1rja1* s_72, NI32 newLen_10);
void growUnsafe_0_Ic4vyyd1_trakthy001(seq_0_Ift2sne_chu5m1rja1* s_73, NI32 newLen_11);
static inline NI32 capInBytes_0_I9kwvit_trakthy001(seq_0_Ins76rj1_trakthy001 s_74);
NB8 resize_0_Ipuaqvj_trakthy001(seq_0_Ins76rj1_trakthy001* dest_12, NI32 addedElements_12);
static inline NI32 len_3_Ixb1ads1_trakthy001(seq_0_Ix7ee6h_sempjk6bn1 s_76);
void fillHashPart_0_Ietaba01_trakthy001(Table_0_Idzlvr_sempjk6bn1* t_23);
static inline void add_0_I2s2mnd_trakthy001(seq_0_Ix7ee6h_sempjk6bn1* s_81, X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g elem_18);
NB8 resize_0_Itvz7wg_trakthy001(seq_0_Ix7ee6h_sempjk6bn1* dest_15, NI32 addedElements_15);
void eQdestroyQ_SX45valX45vent0trakthy001_0_trakthy001(EvalEvent_0_trakthy001* dest_0);
void eQdestroyQ_SX42ranchX45vent0trakthy001_0_trakthy001(BranchEvent_0_trakthy001* dest_0);
void eQdestroyQ_SX53tep0trakthy001_0_trakthy001(Step_0_trakthy001 dest_0);
void eQdestroyQ_SX43allX45vent0trakthy001_0_trakthy001(CallEvent_0_trakthy001* dest_0);
void eQdestroyQ_SX54able0X49dzlvr_0_trakthy001(Table_0_Idzlvr_sempjk6bn1 dest_0);
void eQwasmovedQ_SX54able0X49dzlvr_0_trakthy001(Table_0_Idzlvr_sempjk6bn1* dest_0);
void eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* dest_0);
void eQwasmovedQ_ArefSX54raceX4fbj0trakthy001_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001** dest_0);
void eQdestroyQ_AtupleSstring0sysvq0aslAiS32_0_trakthy001(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g dest_0);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_Ift2sne_chu5m1rja1 newSeqUninit_0_Iggfvwp_chu5m1rja1(NI32 size_32);
static inline seq_0_Iflf8jf1_fiepkwzpc newSeqUninit_0_I5mozxi1_fiepkwzpc(NI32 size_9);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern string_0_sysvq0asl dollarQ_0_valzr1t4f(Value_0_valzr1t4f* v_6);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline HSlice_0_Inzqy8d_comaa5xpt1 ___1_Iclcqmw1_comaa5xpt1(NI32 a_28, NI32 b_13);
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_comaa5xpt1 x_355);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
static inline openArray_0_Ijk0jkw1_feaji4clb1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67);
static inline NI32 len_6_Iroq7kd1_feaji4clb1(openArray_0_Ijk0jkw1_feaji4clb1 a_3);
static inline NC8* getQ_10_I5nt6we_feaji4clb1(openArray_0_Ijk0jkw1_feaji4clb1 x_2, NI32 idx_1);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline NI32 len_3_I4n9kvq_comaa5xpt1(seq_0_I50urnw_chu5m1rja1 s_121);
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_natd5co251(seq_0_I50urnw_chu5m1rja1 s_29, NI32 i_13);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline void add_0_Irnc3p1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* s_19, NB8 elem_7);
static inline seq_0_Ixdx2fh1_ast8ri79k newSeqUninit_0_Im3cqd9_ast8ri79k(NI32 size_20);
static inline void add_0_Ig6072n_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_20, string_0_sysvq0asl elem_3);
extern seq_0_I50urnw_chu5m1rja1 eQdup_1_I28mx5s1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 a_18);
static inline void eQwasMoved_1_I5vdnla_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_47);
extern Value_0_valzr1t4f vNil_0_valzr1t4f(void);
static inline void add_0_I8kd4i4_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_114, NI32 elem_27);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void eQdestroy_1_Ivioh0a_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_46);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
static inline NI32 len_3_I9hktyf_sigekpubi1(seq_0_Iflf8jf1_fiepkwzpc s_58);
static inline NB8* getQ_7_Iul1no9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_24, NI32 i_7);
static inline NI32 len_3_I0v1j8d_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_173);
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline seq_0_Ix7ee6h_sempjk6bn1 newSeqUninit_0_Ig5459y1_sempjk6bn1(NI32 size_82);
static inline seq_0_Ikxuplm1_filqx2b6r1 newSeqUninit_0_Iie69x21_filqx2b6r1(NI32 size_13);
extern NU32 hash_1_has9tn57v(string_0_sysvq0asl s_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NI32 high_3_Iyuup9h1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_17);
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_18, NU32 i_9);
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2);
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0);
static inline NI32 len_3_Iiefpcc1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_19);
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0);
extern void resize_0_tabcr240b1(seq_0_Ikxuplm1_filqx2b6r1* t_0);
static inline void putQ_8_Ipchg2a_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_22, NU32 i_11, HashEntry_0_tabcr240b1 elem_5);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
static inline NI32 capInBytes_0_In1m6ni_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_38);
extern NB8 resize_0_I2yw78g1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* dest_7, NI32 addedElements_7);
static inline NI32 capInBytes_0_Iet286n_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_72);
extern NB8 resize_0_I8l4tya_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* dest_22, NI32 addedElements_22);
extern void eQdestroy_1_I5skmro_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_34);
extern seq_0_Ikxuplm1_filqx2b6r1 newSeq_0_Iv3lu2h1_filqx2b6r1(NI32 size_5);
static inline NI32 capInBytes_0_Igxyzwi_sempjk6bn1(seq_0_Ix7ee6h_sempjk6bn1 s_173);
static inline NI32 memSizeInBytes_0_Ivx6m0g1_sempjk6bn1(NI32 size_83);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_Inxd7ue1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 s_40);
extern void eQdestroy_1_I7a20g9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_69);
extern void eQdestroy_1_Iv9ij5i1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_34);
extern void eQdestroy_1_Ime9ach1_sempjk6bn1(seq_0_Ix7ee6h_sempjk6bn1 s_107);
static inline void eQwasMoved_1_Iydurru1_sempjk6bn1(seq_0_Ix7ee6h_sempjk6bn1* s_108);
static inline void eQwasMoved_1_I8aeezd1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_35);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tabcr240b1(void);
extern void X60Qini_0_valzr1t4f(void);
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33);
static inline NI32 memSizeInBytes_0_Ih4q01h_fiepkwzpc(NI32 size_17);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_comaa5xpt1;
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NI32 memSizeInBytes_0_I7me00i_ast8ri79k(NI32 size_4);
static inline NI32 capInBytes_0_Ih2sbn01_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_28);
extern NB8 resize_0_I4buliy_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* dest_2, NI32 addedElements_2);
static inline NI32 memSizeInBytes_0_Ilp7p16_filqx2b6r1(NI32 size_8);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I12523847436600983983_trakthy001 = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  ... (trace truncated at "}
;
LongString_0_sysvq0asl const strlit_0_I15699532194603344317_trakthy001 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " lines)\012"}
;
LongString_0_sysvq0asl const strlit_0_I1052868480321005239_trakthy001 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\342\206\222 "}
;
LongString_0_sysvq0asl const strlit_0_I7269877443899615135_trakthy001 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\342\207\221 raised"}
;
LongString_0_sysvq0asl const strlit_0_I10302054660838544202_trakthy001 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\342\206\220 "}
;
NI32 argCap_0_trakthy001 = 48;
NB8 X60QiniGuard_0_trakthy001;
X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* newTrace_0_trakthy001(TraceMode_0_trakthy001 mode_0){
  X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* result_2;
  eQwasmovedQ_ArefSX54raceX4fbj0trakthy001_0_trakthy001((&result_2));
  eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_trakthy001(result_2);
  void* X60Qx_18 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001));
  X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* X60Qtmp_0 = ((X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001*)X60Qx_18);
  seq_0_I00yatg_trakthy001 X60Qx_19 = newSeqUninit_0_Igr8h2d_trakthy001(0);
  seq_0_Ins76rj1_trakthy001 X60Qx_20 = newSeqUninit_0_I7r3cpg_trakthy001(0);
  seq_0_Iuignwf1_trakthy001 X60Qx_21 = newSeqUninit_0_Ij364uq1_trakthy001(0);
  seq_0_Is6l9yr_trakthy001 X60Qx_22 = newSeqUninit_0_Ig7buh21_trakthy001(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_23 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  Table_0_Idzlvr_sempjk6bn1 X60Qx_24 = initTable_0_Id6tqqy1_trakthy001();
  seq_0_Iflf8jf1_fiepkwzpc X60Qx_25 = newSeqUninit_0_I5mozxi1_fiepkwzpc(0);
  (*X60Qtmp_0) = (X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001){
    .r_00 = 0, .d_00 = (Trace_Obj_0_trakthy001){
      .mode_0 = mode_0, .depth_0 = 0, .text_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .calls_0 = X60Qx_19, .evals_0 = X60Qx_20, .branches_0 = X60Qx_21, .steps_0 = X60Qx_22, .nCalls_0 = 0, .maxDepth_0 = 0, .truncated_0 = NIM_FALSE, .lines_0 = 0, .frames_0 = X60Qx_23, .prof_0 = X60Qx_24, .maxRecordDepth_0 = 0, .recStack_0 = X60Qx_25}}
  ;
  result_2 = X60Qtmp_0;
  return result_2;}
static inline NB8 recordHere_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_0){
  NB8 result_3;
  NB8 X60Qx_26;
  if ((*t_0).d_00.maxRecordDepth_0 <= 0){
    X60Qx_26 = NIM_TRUE;}
  else {
    X60Qx_26 = ((*t_0).d_00.depth_0 <= (*t_0).d_00.maxRecordDepth_0);}
  result_3 = X60Qx_26;
  return result_3;}
static inline NB8 enabled_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_1){
  NB8 result_4;
  result_4 = (!((*t_1).d_00.mode_0 == 0));
  return result_4;}
string_0_sysvq0asl indent_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_2){
  string_0_sysvq0asl result_5;
  nimStrWasMoved((&result_5));
  nimStrDestroy(result_5);
  result_5 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 i_0 = 0;
  {
    while (i_0 < (*t_2).d_00.depth_0){
      add_2_sysvq0asl((&result_5), (string_0_sysvq0asl){
        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
      );
      inc_1_I6wjjge_aow2h993l1((&i_0));}}
  whileStmtLabel_0: ;
  return result_5;}
string_0_sysvq0asl argText_0_trakthy001(Value_0_valzr1t4f* v_0){
  string_0_sysvq0asl result_6;
  nimStrWasMoved((&result_6));
  string_0_sysvq0asl s_1 = dollarQ_0_valzr1t4f((&(*v_0)));
  NB8 X60Qx_27;
  if (0 < argCap_0_trakthy001){
    NI32 X60Qx_28 = len_4_sysvq0asl(s_1);
    X60Qx_27 = (argCap_0_trakthy001 < X60Qx_28);}
  else {
    X60Qx_27 = NIM_FALSE;}
  if (X60Qx_27){
    HSlice_0_Inzqy8d_comaa5xpt1 X60Qx_29 = ___1_Iclcqmw1_comaa5xpt1(0, ((NI32)(argCap_0_trakthy001 - 4)));
    string_0_sysvq0asl X60Qtmp_2 = getQ_14_sysvq0asl(s_1, X60Qx_29);
    string_0_sysvq0asl X60Qlhs_1 = ampQ_0_sysvq0asl(X60Qtmp_2, (string_0_sysvq0asl){
      .bytes_0 = 774778371u, .more_0 = NIM_NIL}
    );
    nimStrDestroy(s_1);
    s_1 = X60Qlhs_1;
    nimStrDestroy(X60Qtmp_2);}
  string_0_sysvq0asl r_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    openArray_0_Ijk0jkw1_feaji4clb1 X60Qlf_0 = toOpenArray_2_sysvq0asl((&s_1));
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_30 = len_6_Iroq7kd1_feaji4clb1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_30){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_feaji4clb1(X60Qlf_0, X60Qlf_1);
            if ((*X60Qii_2) == (NC8)'\012'){
              add_2_sysvq0asl((&r_0), (string_0_sysvq0asl){
                .bytes_0 = 7232514u, .more_0 = NIM_NIL}
              );}
            else {
              if ((*X60Qii_2) == (NC8)'\011'){
                add_2_sysvq0asl((&r_0), (string_0_sysvq0asl){
                  .bytes_0 = 7625730u, .more_0 = NIM_NIL}
                );}
              else {
                add_1_sysvq0asl((&r_0), (*X60Qii_2));}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  nimStrDestroy(result_6);
  result_6 = r_0;
  nimStrWasMoved((&r_0));
  nimStrDestroy(r_0);
  nimStrDestroy(s_1);
  return result_6;
  nimStrDestroy(r_0);
  nimStrDestroy(s_1);
  return result_6;}
string_0_sysvq0asl joinArgs_0_trakthy001(seq_0_I50urnw_chu5m1rja1 args_0){
  string_0_sysvq0asl result_7;
  nimStrWasMoved((&result_7));
  nimStrDestroy(result_7);
  result_7 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 i_1 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_31 = len_3_I4n9kvq_comaa5xpt1(args_0);
      if (i_1 < X60Qx_31){
        if (0 < i_1){
          add_2_sysvq0asl((&result_7), (string_0_sysvq0asl){
            .bytes_0 = 2108418u, .more_0 = NIM_NIL}
          );}
        Value_0_valzr1t4f* X60Qx_32 = getQ_7_Ine8yq71_natd5co251(args_0, i_1);
        Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_32);
        string_0_sysvq0asl X60Qtmp_3 = argText_0_trakthy001((&X60QconstRefTemp_0));
        add_2_sysvq0asl((&result_7), X60Qtmp_3);
        inc_1_I6wjjge_aow2h993l1((&i_1));
        nimStrDestroy(X60Qtmp_3);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_7;}
void emitLine_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_3, string_0_sysvq0asl s_0){
  if ((*t_3).d_00.truncated_0){
    return;}
  if (((NI32)200000) <= (*t_3).d_00.lines_0){
    add_2_sysvq0asl((&(*t_3).d_00.text_0), (string_0_sysvq0asl){
      .bytes_0 = 773857534u, .more_0 = (&strlit_0_I12523847436600983983_trakthy001)}
    );
    string_0_sysvq0asl X60Qtmp_4 = dollarQ_2_sysvq0asl(((NI32)200000));
    add_2_sysvq0asl((&(*t_3).d_00.text_0), X60Qtmp_4);
    add_2_sysvq0asl((&(*t_3).d_00.text_0), (string_0_sysvq0asl){
      .bytes_0 = 1768694014u, .more_0 = (&strlit_0_I15699532194603344317_trakthy001)}
    );
    (*t_3).d_00.truncated_0 = NIM_TRUE;
    nimStrDestroy(X60Qtmp_4);
    return;
    nimStrDestroy(X60Qtmp_4);}
  add_2_sysvq0asl((&(*t_3).d_00.text_0), s_0);
  add_2_sysvq0asl((&(*t_3).d_00.text_0), (string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  inc_1_I6wjjge_aow2h993l1((&(*t_3).d_00.lines_0));}
void traceEnter_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_4, string_0_sysvq0asl callee_0, seq_0_I50urnw_chu5m1rja1 args_1, NI32 line_0, string_0_sysvq0asl file_0){
  if ((*t_4).d_00.mode_0 == 0){
    return;}
  inc_1_I6wjjge_aow2h993l1((&(*t_4).d_00.nCalls_0));
  if ((*t_4).d_00.mode_0 == 3){
    string_0_sysvq0asl X60Qx_33 = nimStrDup(callee_0);
    NI32 X60Qx_34 = getOrDefault_1_Iwgckf31_trakthy001((*t_4).d_00.prof_0, callee_0, 0);
    putQ_0_Ix03xxw_trakthy001((&(*t_4).d_00.prof_0), X60Qx_33, ((NI32)(X60Qx_34 + 1)));
    inc_1_I6wjjge_aow2h993l1((&(*t_4).d_00.depth_0));
    if ((*t_4).d_00.maxDepth_0 < (*t_4).d_00.depth_0){
      (*t_4).d_00.maxDepth_0 = (*t_4).d_00.depth_0;}
    return;}
  NB8 rec_0 = recordHere_0_trakthy001(t_4);
  add_0_Irnc3p1_fiepkwzpc((&(*t_4).d_00.recStack_0), rec_0);
  if (rec_0){
    seq_0_Ixdx2fh1_ast8ri79k ar_0 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
    NI32 ai_0 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_35 = len_3_I4n9kvq_comaa5xpt1(args_1);
        if (ai_0 < X60Qx_35){
          Value_0_valzr1t4f* X60Qx_36 = getQ_7_Ine8yq71_natd5co251(args_1, ai_0);
          Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_36);
          string_0_sysvq0asl X60Qx_37 = argText_0_trakthy001((&X60QconstRefTemp_0));
          add_0_Ig6072n_ast8ri79k((&ar_0), X60Qx_37);
          inc_1_I6wjjge_aow2h993l1((&ai_0));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    string_0_sysvq0asl X60Qx_13 = nimStrDup(callee_0);
    seq_0_I50urnw_chu5m1rja1 X60Qx_14 = eQdup_1_I28mx5s1_chu5m1rja1(args_1);
    seq_0_Ixdx2fh1_ast8ri79k X60Qtmp_5 = ar_0;
    eQwasMoved_1_I5vdnla_ast8ri79k((&ar_0));
    Value_0_valzr1t4f X60Qx_15 = vNil_0_valzr1t4f();
    string_0_sysvq0asl X60Qx_16 = nimStrDup(file_0);
    add_0_Ibgb1rj1_trakthy001((&(*t_4).d_00.calls_0), (CallEvent_0_trakthy001){
      .callee_0 = X60Qx_13, .args_0 = X60Qx_14, .argsR_0 = X60Qtmp_5, .ret_0 = X60Qx_15, .retR_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .depth_0 = (*t_4).d_00.depth_0, .line_0 = line_0, .file_0 = X60Qx_16}
    );
    string_0_sysvq0asl X60Qx_38 = nimStrDup(callee_0);
    add_0_I9sf6zn_trakthy001((&(*t_4).d_00.steps_0), (Step_0_trakthy001){
      .kind_0 = 0, .name_0 = X60Qx_38, .site_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}}
    );
    NI32 X60Qx_39 = len_3_Ipsu5z01_trakthy001((*t_4).d_00.calls_0);
    add_0_I8kd4i4_comaa5xpt1((&(*t_4).d_00.frames_0), ((NI32)(X60Qx_39 - 1)));
    string_0_sysvq0asl X60Qdesugar_0 = indent_0_trakthy001(t_4);
    string_0_sysvq0asl X60Qdesugar_1 = joinArgs_0_trakthy001(args_1);
    NI32 X60Qx_40 = len_4_sysvq0asl(X60Qdesugar_0);
    NI32 X60Qx_41 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2458313470u, .more_0 = (&strlit_0_I1052868480321005239_trakthy001)}
    );
    NI32 X60Qx_42 = len_4_sysvq0asl(callee_0);
    NI32 X60Qx_43 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 10241u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_44 = len_4_sysvq0asl(X60Qdesugar_1);
    NI32 X60Qx_45 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_40 + X60Qx_41)) + X60Qx_42)) + X60Qx_43)) + X60Qx_44)) + X60Qx_45)));
    add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_0);
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 2458313470u, .more_0 = (&strlit_0_I1052868480321005239_trakthy001)}
    );
    add_2_sysvq0asl((&X60Qdesugar_2), callee_0);
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 10241u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_1);
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl head_0 = X60Qdesugar_2;
    nimStrWasMoved((&X60Qdesugar_2));
    if (0 < line_0){
      add_2_sysvq0asl((&head_0), (string_0_sysvq0asl){
        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&head_0), file_0);
      add_2_sysvq0asl((&head_0), (string_0_sysvq0asl){
        .bytes_0 = 14849u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qtmp_6 = dollarQ_2_sysvq0asl(line_0);
      add_2_sysvq0asl((&head_0), X60Qtmp_6);
      nimStrDestroy(X60Qtmp_6);}
    emitLine_0_trakthy001(t_4, head_0);
    nimStrDestroy(head_0);
    nimStrDestroy(X60Qdesugar_2);
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);
    eQdestroy_1_Ivioh0a_ast8ri79k(ar_0);}
  inc_1_I6wjjge_aow2h993l1((&(*t_4).d_00.depth_0));
  if ((*t_4).d_00.maxDepth_0 < (*t_4).d_00.depth_0){
    (*t_4).d_00.maxDepth_0 = (*t_4).d_00.depth_0;}}
void traceExit_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_5, Value_0_valzr1t4f* ret_0, NB8 raised_0){
  if ((*t_5).d_00.mode_0 == 0){
    return;}
  if ((*t_5).d_00.mode_0 == 3){
    if (0 < (*t_5).d_00.depth_0){
      dec_1_I0nzoz91_ast8ri79k((&(*t_5).d_00.depth_0));}
    return;}
  NB8 rec_1 = NIM_TRUE;
  if (0 < (*t_5).d_00.recStack_0.len_0){
    NI32 X60Qx_46 = len_3_I9hktyf_sigekpubi1((*t_5).d_00.recStack_0);
    NB8* X60Qx_47 = getQ_7_Iul1no9_fiepkwzpc((*t_5).d_00.recStack_0, ((NI32)(X60Qx_46 - 1)));
    rec_1 = (*X60Qx_47);
    NI32 X60Qx_48 = len_3_I9hktyf_sigekpubi1((*t_5).d_00.recStack_0);
    setLen_0_I0277bu1_trakthy001((&(*t_5).d_00.recStack_0), ((NI32)(X60Qx_48 - 1)));}
  if (0 < (*t_5).d_00.depth_0){
    dec_1_I0nzoz91_ast8ri79k((&(*t_5).d_00.depth_0));}
  if ((!rec_1)){
    return;}
  add_0_I9sf6zn_trakthy001((&(*t_5).d_00.steps_0), (Step_0_trakthy001){
    .kind_0 = 1, .name_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .site_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}}
  );
  if (0 < (*t_5).d_00.frames_0.len_0){
    NI32 X60Qx_49 = len_3_I0v1j8d_comaa5xpt1((*t_5).d_00.frames_0);
    NI32* X60Qx_50 = getQ_7_Ir8kccm_comaa5xpt1((*t_5).d_00.frames_0, ((NI32)(X60Qx_49 - 1)));
    NI32 idx_0 = (*X60Qx_50);
    NI32 X60Qx_51 = len_3_I0v1j8d_comaa5xpt1((*t_5).d_00.frames_0);
    setLen_0_Ik1cud6_trakthy001((&(*t_5).d_00.frames_0), ((NI32)(X60Qx_51 - 1)));
    CallEvent_0_trakthy001* X60Qx_52 = getQ_7_I6fsagi1_trakthy001((*t_5).d_00.calls_0, idx_0);
    Value_0_valzr1t4f* X60Qlhs_7 = (&(*X60Qx_52).ret_0);
    CallEvent_0_trakthy001* X60Qx_53 = getQ_7_I6fsagi1_trakthy001((*t_5).d_00.calls_0, idx_0);
    Value_0_valzr1t4f X60Qlhs_8 = (*X60Qx_53).ret_0;
    Value_0_valzr1t4f X60Qx_54 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*ret_0)));
    (*X60Qlhs_7) = X60Qx_54;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_8));
    CallEvent_0_trakthy001* X60Qx_55 = getQ_7_I6fsagi1_trakthy001((*t_5).d_00.calls_0, idx_0);
    string_0_sysvq0asl* X60Qlhs_9 = (&(*X60Qx_55).retR_0);
    string_0_sysvq0asl X60Qlhs_10 = argText_0_trakthy001((&(*ret_0)));
    nimStrDestroy((*X60Qlhs_9));
    (*X60Qlhs_9) = X60Qlhs_10;}
  if (raised_0){
    string_0_sysvq0asl X60Qtmp_12 = indent_0_trakthy001(t_5);
    string_0_sysvq0asl X60Qtmp_11 = ampQ_0_sysvq0asl(X60Qtmp_12, (string_0_sysvq0asl){
      .bytes_0 = 2441601790u, .more_0 = (&strlit_0_I7269877443899615135_trakthy001)}
    );
    emitLine_0_trakthy001(t_5, X60Qtmp_11);
    nimStrDestroy(X60Qtmp_11);
    nimStrDestroy(X60Qtmp_12);}
  else {
    string_0_sysvq0asl X60Qdesugar_3 = indent_0_trakthy001(t_5);
    string_0_sysvq0asl X60Qdesugar_4 = argText_0_trakthy001((&(*ret_0)));
    NI32 X60Qx_56 = len_4_sysvq0asl(X60Qdesugar_3);
    NI32 X60Qx_57 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2424759038u, .more_0 = (&strlit_0_I10302054660838544202_trakthy001)}
    );
    NI32 X60Qx_58 = len_4_sysvq0asl(X60Qdesugar_4);
    string_0_sysvq0asl X60Qdesugar_5 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_56 + X60Qx_57)) + X60Qx_58)));
    add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_3);
    add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
      .bytes_0 = 2424759038u, .more_0 = (&strlit_0_I10302054660838544202_trakthy001)}
    );
    add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_4);
    emitLine_0_trakthy001(t_5, X60Qdesugar_5);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qdesugar_4);
    nimStrDestroy(X60Qdesugar_3);}}
void traceStep_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* t_6, string_0_sysvq0asl code_0, NI32 line_1, NI32 col_0){
  if ((!((*t_6).d_00.mode_0 == 2))){
    return;}
  NB8 X60Qx_59 = recordHere_0_trakthy001(t_6);
  if ((!X60Qx_59)){
    return;}
  string_0_sysvq0asl X60Qx_60 = nimStrDup(code_0);
  Value_0_valzr1t4f X60Qx_61 = vNil_0_valzr1t4f();
  add_0_Iiokvvq_trakthy001((&(*t_6).d_00.evals_0), (EvalEvent_0_trakthy001){
    .code_0 = X60Qx_60, .line_0 = line_1, .col_0 = col_0, .val_0 = X60Qx_61}
  );
  string_0_sysvq0asl X60Qdesugar_6 = indent_0_trakthy001(t_6);
  NI32 X60Qx_62 = len_4_sysvq0asl(X60Qdesugar_6);
  NI32 X60Qx_63 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 548913667u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_64 = len_4_sysvq0asl(code_0);
  string_0_sysvq0asl X60Qdesugar_7 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_62 + X60Qx_63)) + X60Qx_64)));
  add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_6);
  add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
    .bytes_0 = 548913667u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_7), code_0);
  string_0_sysvq0asl s_18 = X60Qdesugar_7;
  nimStrWasMoved((&X60Qdesugar_7));
  if (0 < line_1){
    add_2_sysvq0asl((&s_18), (string_0_sysvq0asl){
      .bytes_0 = 975183875u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_13 = dollarQ_2_sysvq0asl(line_1);
    add_2_sysvq0asl((&s_18), X60Qtmp_13);
    nimStrDestroy(X60Qtmp_13);}
  emitLine_0_trakthy001(t_6, s_18);
  nimStrDestroy(s_18);
  nimStrDestroy(X60Qdesugar_7);
  nimStrDestroy(X60Qdesugar_6);}
static inline seq_0_I00yatg_trakthy001 newSeqUninit_0_Igr8h2d_trakthy001(NI32 size_7){
  seq_0_I00yatg_trakthy001 result_10;
  if (size_7 == 0){
    result_10 = (seq_0_I00yatg_trakthy001){
      .len_0 = size_7, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_I219gvk_trakthy001(size_7);
    void* X60Qx_110 = alloc_1_sysvq0asl(memSize_0);
    result_10 = (seq_0_I00yatg_trakthy001){
      .len_0 = size_7, .data_0 = ((CallEvent_0_trakthy001*)X60Qx_110)}
    ;
    if ((!(result_10.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_111 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_10.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_10;}
static inline seq_0_Ins76rj1_trakthy001 newSeqUninit_0_I7r3cpg_trakthy001(NI32 size_9){
  seq_0_Ins76rj1_trakthy001 result_11;
  if (size_9 == 0){
    result_11 = (seq_0_Ins76rj1_trakthy001){
      .len_0 = size_9, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Ivrxvb8_trakthy001(size_9);
    void* X60Qx_112 = alloc_1_sysvq0asl(memSize_1);
    result_11 = (seq_0_Ins76rj1_trakthy001){
      .len_0 = size_9, .data_0 = ((EvalEvent_0_trakthy001*)X60Qx_112)}
    ;
    if ((!(result_11.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_113 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_11.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_11;}
static inline seq_0_Iuignwf1_trakthy001 newSeqUninit_0_Ij364uq1_trakthy001(NI32 size_11){
  seq_0_Iuignwf1_trakthy001 result_12;
  if (size_11 == 0){
    result_12 = (seq_0_Iuignwf1_trakthy001){
      .len_0 = size_11, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Iyus9bq_trakthy001(size_11);
    void* X60Qx_114 = alloc_1_sysvq0asl(memSize_2);
    result_12 = (seq_0_Iuignwf1_trakthy001){
      .len_0 = size_11, .data_0 = ((BranchEvent_0_trakthy001*)X60Qx_114)}
    ;
    if ((!(result_12.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_115 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_12.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_12;}
static inline seq_0_Is6l9yr_trakthy001 newSeqUninit_0_Ig7buh21_trakthy001(NI32 size_13){
  seq_0_Is6l9yr_trakthy001 result_13;
  if (size_13 == 0){
    result_13 = (seq_0_Is6l9yr_trakthy001){
      .len_0 = size_13, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_Ic2zc331_trakthy001(size_13);
    void* X60Qx_116 = alloc_1_sysvq0asl(memSize_3);
    result_13 = (seq_0_Is6l9yr_trakthy001){
      .len_0 = size_13, .data_0 = ((Step_0_trakthy001*)X60Qx_116)}
    ;
    if ((!(result_13.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_117 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_13.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_13;}
Table_0_Idzlvr_sempjk6bn1 initTable_0_Id6tqqy1_trakthy001(void){
  Table_0_Idzlvr_sempjk6bn1 result_15;
  eQwasmovedQ_SX54able0X49dzlvr_0_trakthy001((&result_15));
  eQdestroyQ_SX54able0X49dzlvr_0_trakthy001(result_15);
  seq_0_Ix7ee6h_sempjk6bn1 X60Qx_120 = newSeqUninit_0_Ig5459y1_sempjk6bn1(0);
  seq_0_Ikxuplm1_filqx2b6r1 X60Qx_121 = newSeqUninit_0_Iie69x21_filqx2b6r1(0);
  result_15 = (Table_0_Idzlvr_sempjk6bn1){
    .data_0 = X60Qx_120, .hashes_0 = X60Qx_121}
  ;
  return result_15;}
NI32 getOrDefault_1_Iwgckf31_trakthy001(Table_0_Idzlvr_sempjk6bn1 t_15, string_0_sysvq0asl k_3, NI32 fallback_1){
  NI32 result_20;
  NU32 X60Qx_125 = hash_1_has9tn57v(k_3);
  NI32 idx_2 = rawGet_0_Ik917wh_trakthy001(t_15, k_3, X60Qx_125);
  NI32 X60Qx_2;
  if (0 <= idx_2){
    X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* X60Qx_126 = getQ_7_Ioesyu2_trakthy001(t_15.data_0, idx_2);
    X60Qx_2 = (*X60Qx_126).fld_1;}
  else {
    X60Qx_2 = fallback_1;}
  result_20 = X60Qx_2;
  return result_20;}
void putQ_0_Ix03xxw_trakthy001(Table_0_Idzlvr_sempjk6bn1* t_17, string_0_sysvq0asl k_5, NI32 v_2){
  NU32 h_0 = hash_1_has9tn57v(k_5);
  NI32 idx_3 = rawGet_0_Ik917wh_trakthy001((*t_17), k_5, h_0);
  if (0 <= idx_3){
    X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* X60Qx_127 = getQ_7_Ioesyu2_trakthy001((*t_17).data_0, idx_3);
    (*X60Qx_127).fld_1 = v_2;}
  else {
    string_0_sysvq0asl X60Qtmp_18 = k_5;
    nimStrWasMoved((&k_5));
    rawPut_0_Isxoisv_trakthy001(t_17, X60Qtmp_18, v_2, h_0);}
  nimStrDestroy(k_5);}
static inline void add_0_Ibgb1rj1_trakthy001(seq_0_I00yatg_trakthy001* s_31, CallEvent_0_trakthy001 elem_10){
  NI32 L_2 = (*s_31).len_0;
  NI32 X60Qx_134 = capInBytes_0_Iqgh8781_trakthy001((*s_31));
  if (X60Qx_134 < ((NI32)(((NI32)(L_2 * sizeof(CallEvent_0_trakthy001))) + sizeof(CallEvent_0_trakthy001)))){
    NB8 X60Qx_135 = resize_0_Ixa06i01_trakthy001(s_31, 1);
    if ((!X60Qx_135)){
      eQdestroyQ_SX43allX45vent0trakthy001_0_trakthy001((&elem_10));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_31).len_0));
  (*s_31).data_0[L_2] = elem_10;}
static inline void add_0_I9sf6zn_trakthy001(seq_0_Is6l9yr_trakthy001* s_33, Step_0_trakthy001 elem_11){
  NI32 L_3 = (*s_33).len_0;
  NI32 X60Qx_136 = capInBytes_0_Ig7toyf1_trakthy001((*s_33));
  if (X60Qx_136 < ((NI32)(((NI32)(L_3 * sizeof(Step_0_trakthy001))) + sizeof(Step_0_trakthy001)))){
    NB8 X60Qx_137 = resize_0_I8n8isu_trakthy001(s_33, 1);
    if ((!X60Qx_137)){
      eQdestroyQ_SX53tep0trakthy001_0_trakthy001(elem_11);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_33).len_0));
  (*s_33).data_0[L_3] = elem_11;}
static inline NI32 len_3_Ipsu5z01_trakthy001(seq_0_I00yatg_trakthy001 s_35){
  NI32 result_22;
  result_22 = s_35.len_0;
  return result_22;}
void setLen_0_I0277bu1_trakthy001(seq_0_Iflf8jf1_fiepkwzpc* s_40, NI32 newLen_2){
  if (newLen_2 < (*s_40).len_0){
    shrink_0_Iw0ki4f1_trakthy001(s_40, newLen_2);}
  else {
    NI32 i_13 = (*s_40).len_0;
    growUnsafe_0_Ip180zg1_trakthy001(s_40, newLen_2);
    if ((*s_40).data_0 == NIM_NIL){
      return;}
    {
      while (i_13 < newLen_2){
        (*s_40).data_0[i_13] = NIM_FALSE;
        inc_1_I6wjjge_aow2h993l1((&i_13));}}
    whileStmtLabel_0: ;}}
void setLen_0_Ik1cud6_trakthy001(seq_0_Ift2sne_chu5m1rja1* s_45, NI32 newLen_5){
  if (newLen_5 < (*s_45).len_0){
    shrink_0_Icjjln7_trakthy001(s_45, newLen_5);}
  else {
    NI32 i_15 = (*s_45).len_0;
    growUnsafe_0_Ic4vyyd1_trakthy001(s_45, newLen_5);
    if ((*s_45).data_0 == NIM_NIL){
      return;}
    {
      while (i_15 < newLen_5){
        (*s_45).data_0[i_15] = ((NI32)0);
        inc_1_I6wjjge_aow2h993l1((&i_15));}}
    whileStmtLabel_0: ;}}
static inline CallEvent_0_trakthy001* getQ_7_I6fsagi1_trakthy001(seq_0_I00yatg_trakthy001 s_48, NI32 i_16){
  NB8 X60Qx_142;
  if (i_16 < s_48.len_0){
    X60Qx_142 = (0 <= i_16);}
  else {
    X60Qx_142 = NIM_FALSE;}
  if ((!X60Qx_142)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  CallEvent_0_trakthy001* result_27;
  result_27 = (&s_48.data_0[i_16]);
  return result_27;}
static inline void add_0_Iiokvvq_trakthy001(seq_0_Ins76rj1_trakthy001* s_49, EvalEvent_0_trakthy001 elem_13){
  NI32 L_5 = (*s_49).len_0;
  NI32 X60Qx_143 = capInBytes_0_I9kwvit_trakthy001((*s_49));
  if (X60Qx_143 < ((NI32)(((NI32)(L_5 * sizeof(EvalEvent_0_trakthy001))) + sizeof(EvalEvent_0_trakthy001)))){
    NB8 X60Qx_144 = resize_0_Ipuaqvj_trakthy001(s_49, 1);
    if ((!X60Qx_144)){
      eQdestroyQ_SX45valX45vent0trakthy001_0_trakthy001((&elem_13));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_49).len_0));
  (*s_49).data_0[L_5] = elem_13;}
static inline NI32 memSizeInBytes_0_I219gvk_trakthy001(NI32 size_23){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_31;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_23, sizeof(CallEvent_0_trakthy001), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_31 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_31 = ((NI32)2147483647);}
  return result_31;}
static inline NI32 memSizeInBytes_0_Ivrxvb8_trakthy001(NI32 size_24){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_32;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_24, sizeof(EvalEvent_0_trakthy001), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_32 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_32 = ((NI32)2147483647);}
  return result_32;}
static inline NI32 memSizeInBytes_0_Iyus9bq_trakthy001(NI32 size_25){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_33;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_25, sizeof(BranchEvent_0_trakthy001), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_33 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_33 = ((NI32)2147483647);}
  return result_33;}
static inline NI32 memSizeInBytes_0_Ic2zc331_trakthy001(NI32 size_26){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_34;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_26, sizeof(Step_0_trakthy001), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_34 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_34 = ((NI32)2147483647);}
  return result_34;}
NI32 rawGet_0_Ik917wh_trakthy001(Table_0_Idzlvr_sempjk6bn1 t_20, string_0_sysvq0asl k_7, NU32 kh_1){
  NI32 result_41;
  NI32 X60Qx_155 = len_3_Ixb1ads1_trakthy001(t_20.data_0);
  if (X60Qx_155 <= ((NI32)4)){
    {
      NI32 X60Qlf_9 = 0;
      NI32 X60Qlf_10 = len_3_Ixb1ads1_trakthy001(t_20.data_0);
      NI32 X60Qlf_11 = X60Qlf_9;
      {
        while (X60Qlf_11 < X60Qlf_10){
          {
            X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* X60Qx_156 = getQ_7_Ioesyu2_trakthy001(t_20.data_0, X60Qlf_11);
            NB8 X60Qx_157 = eqQ_20_sysvq0asl((*X60Qx_156).fld_0, k_7);
            if (X60Qx_157){
              return X60Qlf_11;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_11));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_158 = high_3_Iyuup9h1_filqx2b6r1(t_20.hashes_0);
    NU32 h_2 = ((NU32)(kh_1 & ((NU32)X60Qx_158)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_159 = getQ_8_Imt2zi01_filqx2b6r1(t_20.hashes_0, h_2);
        NB8 X60Qx_160 = isFilled_0_tabcr240b1((*X60Qx_159));
        if (X60Qx_160){
          HashEntry_0_tabcr240b1* X60Qx_161 = getQ_8_Imt2zi01_filqx2b6r1(t_20.hashes_0, h_2);
          HashEntry_0_tabcr240b1 d_0 = (*X60Qx_161);
          NB8 X60Qx_162;
          if (d_0.fullhash_0 == kh_1){
            X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* X60Qx_163 = getQ_7_Ioesyu2_trakthy001(t_20.data_0, ((NI32)(d_0.position_0 - 1)));
            NB8 X60Qx_164 = eqQ_20_sysvq0asl((*X60Qx_163).fld_0, k_7);
            X60Qx_162 = X60Qx_164;}
          else {
            X60Qx_162 = NIM_FALSE;}
          if (X60Qx_162){
            result_41 = ((NI32)(d_0.position_0 - 1));
            return result_41;}
          NI32 X60Qx_165 = high_3_Iyuup9h1_filqx2b6r1(t_20.hashes_0);
          NU32 X60Qx_166 = nextTry_0_has9tn57v(h_2, X60Qx_165);
          h_2 = X60Qx_166;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_41 = -1;
  return result_41;}
static inline X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* getQ_7_Ioesyu2_trakthy001(seq_0_Ix7ee6h_sempjk6bn1 s_61, NI32 i_23){
  NB8 X60Qx_167;
  if (i_23 < s_61.len_0){
    X60Qx_167 = (0 <= i_23);}
  else {
    X60Qx_167 = NIM_FALSE;}
  if ((!X60Qx_167)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* result_42;
  result_42 = (&s_61.data_0[i_23]);
  return result_42;}
void rawPut_0_Isxoisv_trakthy001(Table_0_Idzlvr_sempjk6bn1* t_21, string_0_sysvq0asl k_8, NI32 v_4, NU32 h_3){
  NI32 X60Qx_168 = len_3_Ixb1ads1_trakthy001((*t_21).data_0);
  if (X60Qx_168 == ((NI32)4)){
    fillHashPart_0_Ietaba01_trakthy001(t_21);}
  else {
    NI32 X60Qx_169 = len_3_Iiefpcc1_filqx2b6r1((*t_21).hashes_0);
    NI32 X60Qx_170 = len_3_Ixb1ads1_trakthy001((*t_21).data_0);
    NB8 X60Qx_171 = mustRehash_0_tabcr240b1(X60Qx_169, X60Qx_170);
    if (X60Qx_171){
      resize_0_tabcr240b1((&(*t_21).hashes_0));}}
  string_0_sysvq0asl X60Qtmp_21 = k_8;
  nimStrWasMoved((&k_8));
  add_0_I2s2mnd_trakthy001((&(*t_21).data_0), (X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g){
    .fld_0 = X60Qtmp_21, .fld_1 = v_4}
  );
  NI32 X60Qx_172 = high_3_Iyuup9h1_filqx2b6r1((*t_21).hashes_0);
  NU32 hi_0 = ((NU32)(h_3 & ((NU32)X60Qx_172)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_173 = getQ_8_Imt2zi01_filqx2b6r1((*t_21).hashes_0, hi_0);
      NB8 X60Qx_174 = isFilled_0_tabcr240b1((*X60Qx_173));
      if (X60Qx_174){
        NI32 X60Qx_175 = high_3_Iyuup9h1_filqx2b6r1((*t_21).hashes_0);
        NU32 X60Qx_176 = nextTry_0_has9tn57v(hi_0, X60Qx_175);
        hi_0 = X60Qx_176;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_177 = len_3_Ixb1ads1_trakthy001((*t_21).data_0);
  putQ_8_Ipchg2a_filqx2b6r1((&(*t_21).hashes_0), hi_0, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_3, .position_0 = X60Qx_177}
  );
  nimStrDestroy(k_8);}
static inline NI32 capInBytes_0_Iqgh8781_trakthy001(seq_0_I00yatg_trakthy001 s_67){
  NI32 result_48;
  NI32 X60Qx_5;
  if ((!(s_67.data_0 == NIM_NIL))){
    NI32 X60Qx_184 = allocatedSize_0_sysvq0asl(((void*)((void*)s_67.data_0)));
    X60Qx_5 = X60Qx_184;}
  else {
    X60Qx_5 = 0;}
  result_48 = X60Qx_5;
  return result_48;}
NB8 resize_0_Ixa06i01_trakthy001(seq_0_I00yatg_trakthy001* dest_9, NI32 addedElements_9){
  NB8 result_49;
  NI32 X60Qx_185 = capInBytes_0_Iqgh8781_trakthy001((*dest_9));
  NI32 oldCap_2 = ((NI32)(X60Qx_185 / sizeof(CallEvent_0_trakthy001)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_9);
  NI32 memSize_11 = memSizeInBytes_0_I219gvk_trakthy001(newCap_2);
  void* X60Qx_186 = realloc_1_sysvq0asl(((void*)((void*)(*dest_9).data_0)), memSize_11);
  (*dest_9).data_0 = ((CallEvent_0_trakthy001*)X60Qx_186);
  if ((*dest_9).data_0 == NIM_NIL){
    (*dest_9).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_11);
    result_49 = NIM_FALSE;}
  else {
    result_49 = NIM_TRUE;}
  return result_49;}
static inline NI32 capInBytes_0_Ig7toyf1_trakthy001(seq_0_Is6l9yr_trakthy001 s_68){
  NI32 result_50;
  NI32 X60Qx_6;
  if ((!(s_68.data_0 == NIM_NIL))){
    NI32 X60Qx_187 = allocatedSize_0_sysvq0asl(((void*)((void*)s_68.data_0)));
    X60Qx_6 = X60Qx_187;}
  else {
    X60Qx_6 = 0;}
  result_50 = X60Qx_6;
  return result_50;}
NB8 resize_0_I8n8isu_trakthy001(seq_0_Is6l9yr_trakthy001* dest_10, NI32 addedElements_10){
  NB8 result_51;
  NI32 X60Qx_188 = capInBytes_0_Ig7toyf1_trakthy001((*dest_10));
  NI32 oldCap_3 = ((NI32)(X60Qx_188 / sizeof(Step_0_trakthy001)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_10);
  NI32 memSize_12 = memSizeInBytes_0_Ic2zc331_trakthy001(newCap_3);
  void* X60Qx_189 = realloc_1_sysvq0asl(((void*)((void*)(*dest_10).data_0)), memSize_12);
  (*dest_10).data_0 = ((Step_0_trakthy001*)X60Qx_189);
  if ((*dest_10).data_0 == NIM_NIL){
    (*dest_10).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_12);
    result_51 = NIM_FALSE;}
  else {
    result_51 = NIM_TRUE;}
  return result_51;}
void shrink_0_Iw0ki4f1_trakthy001(seq_0_Iflf8jf1_fiepkwzpc* s_70, NI32 newLen_8){
  NI32 i_25 = ((NI32)((*s_70).len_0 - 1));
  {
    while (newLen_8 <= i_25){
      dec_1_I0nzoz91_ast8ri79k((&i_25));}}
  whileStmtLabel_0: ;
  (*s_70).len_0 = newLen_8;}
void growUnsafe_0_Ip180zg1_trakthy001(seq_0_Iflf8jf1_fiepkwzpc* s_71, NI32 newLen_9){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_9, sizeof(NB8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_0 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_193 = capInBytes_0_In1m6ni_fiepkwzpc((*s_71));
  if (X60Qx_193 < newSize_0){
    NB8 X60Qx_194 = resize_0_I2yw78g1_fiepkwzpc(s_71, ((NI32)(newLen_9 - (*s_71).len_0)));
    if ((!X60Qx_194)){
      return;}}
  (*s_71).len_0 = newLen_9;}
void shrink_0_Icjjln7_trakthy001(seq_0_Ift2sne_chu5m1rja1* s_72, NI32 newLen_10){
  NI32 i_26 = ((NI32)((*s_72).len_0 - 1));
  {
    while (newLen_10 <= i_26){
      dec_1_I0nzoz91_ast8ri79k((&i_26));}}
  whileStmtLabel_0: ;
  (*s_72).len_0 = newLen_10;}
void growUnsafe_0_Ic4vyyd1_trakthy001(seq_0_Ift2sne_chu5m1rja1* s_73, NI32 newLen_11){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_11, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_1 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_195 = capInBytes_0_Iet286n_chu5m1rja1((*s_73));
  if (X60Qx_195 < newSize_1){
    NB8 X60Qx_196 = resize_0_I8l4tya_comaa5xpt1(s_73, ((NI32)(newLen_11 - (*s_73).len_0)));
    if ((!X60Qx_196)){
      return;}}
  (*s_73).len_0 = newLen_11;}
static inline NI32 capInBytes_0_I9kwvit_trakthy001(seq_0_Ins76rj1_trakthy001 s_74){
  NI32 result_54;
  NI32 X60Qx_8;
  if ((!(s_74.data_0 == NIM_NIL))){
    NI32 X60Qx_197 = allocatedSize_0_sysvq0asl(((void*)((void*)s_74.data_0)));
    X60Qx_8 = X60Qx_197;}
  else {
    X60Qx_8 = 0;}
  result_54 = X60Qx_8;
  return result_54;}
NB8 resize_0_Ipuaqvj_trakthy001(seq_0_Ins76rj1_trakthy001* dest_12, NI32 addedElements_12){
  NB8 result_55;
  NI32 X60Qx_198 = capInBytes_0_I9kwvit_trakthy001((*dest_12));
  NI32 oldCap_5 = ((NI32)(X60Qx_198 / sizeof(EvalEvent_0_trakthy001)));
  NI32 newCap_5 = recalcCap_0_sysvq0asl(oldCap_5, addedElements_12);
  NI32 memSize_14 = memSizeInBytes_0_Ivrxvb8_trakthy001(newCap_5);
  void* X60Qx_199 = realloc_1_sysvq0asl(((void*)((void*)(*dest_12).data_0)), memSize_14);
  (*dest_12).data_0 = ((EvalEvent_0_trakthy001*)X60Qx_199);
  if ((*dest_12).data_0 == NIM_NIL){
    (*dest_12).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_14);
    result_55 = NIM_FALSE;}
  else {
    result_55 = NIM_TRUE;}
  return result_55;}
static inline NI32 len_3_Ixb1ads1_trakthy001(seq_0_Ix7ee6h_sempjk6bn1 s_76){
  NI32 result_58;
  result_58 = s_76.len_0;
  return result_58;}
void fillHashPart_0_Ietaba01_trakthy001(Table_0_Idzlvr_sempjk6bn1* t_23){
  seq_0_Ikxuplm1_filqx2b6r1* X60Qlhs_22 = (&(*t_23).hashes_0);
  eQdestroy_1_I5skmro_filqx2b6r1((*X60Qlhs_22));
  seq_0_Ikxuplm1_filqx2b6r1 X60Qx_204 = newSeq_0_Iv3lu2h1_filqx2b6r1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_22) = X60Qx_204;
  {
    NI32 X60Qlf_12 = 0;
    NI32 X60Qlf_13 = len_3_Ixb1ads1_trakthy001((*t_23).data_0);
    NI32 X60Qlf_14 = X60Qlf_12;
    {
      while (X60Qlf_14 < X60Qlf_13){
        {
          X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g* X60Qx_205 = getQ_7_Ioesyu2_trakthy001((*t_23).data_0, X60Qlf_14);
          NU32 X60Qii_2 = hash_1_has9tn57v((*X60Qx_205).fld_0);
          NI32 X60Qx_206 = high_3_Iyuup9h1_filqx2b6r1((*t_23).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_206)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_207 = getQ_8_Imt2zi01_filqx2b6r1((*t_23).hashes_0, X60Qii_3);
            NB8 X60Qx_208 = isFilled_0_tabcr240b1((*X60Qx_207));
            if (X60Qx_208){
              NI32 X60Qx_209 = high_3_Iyuup9h1_filqx2b6r1((*t_23).hashes_0);
              NU32 X60Qx_210 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_209);
              X60Qii_3 = X60Qx_210;}
            else {
              break;}}
          putQ_8_Ipchg2a_filqx2b6r1((&(*t_23).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_14 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_14));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_I2s2mnd_trakthy001(seq_0_Ix7ee6h_sempjk6bn1* s_81, X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g elem_18){
  NI32 L_7 = (*s_81).len_0;
  NI32 X60Qx_211 = capInBytes_0_Igxyzwi_sempjk6bn1((*s_81));
  if (X60Qx_211 < ((NI32)(((NI32)(L_7 * sizeof(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g))) + sizeof(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g)))){
    NB8 X60Qx_212 = resize_0_Itvz7wg_trakthy001(s_81, 1);
    if ((!X60Qx_212)){
      eQdestroyQ_AtupleSstring0sysvq0aslAiS32_0_trakthy001(elem_18);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_81).len_0));
  (*s_81).data_0[L_7] = elem_18;}
NB8 resize_0_Itvz7wg_trakthy001(seq_0_Ix7ee6h_sempjk6bn1* dest_15, NI32 addedElements_15){
  NB8 result_69;
  NI32 X60Qx_215 = capInBytes_0_Igxyzwi_sempjk6bn1((*dest_15));
  NI32 oldCap_7 = ((NI32)(X60Qx_215 / sizeof(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g)));
  NI32 newCap_7 = recalcCap_0_sysvq0asl(oldCap_7, addedElements_15);
  NI32 memSize_17 = memSizeInBytes_0_Ivx6m0g1_sempjk6bn1(newCap_7);
  void* X60Qx_216 = realloc_1_sysvq0asl(((void*)((void*)(*dest_15).data_0)), memSize_17);
  (*dest_15).data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g*)X60Qx_216);
  if ((*dest_15).data_0 == NIM_NIL){
    (*dest_15).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_17);
    result_69 = NIM_FALSE;}
  else {
    result_69 = NIM_TRUE;}
  return result_69;}
void eQdestroy_1_I5fvguk1_trakthy001(seq_0_I00yatg_trakthy001 s_110){
  if ((!(s_110.data_0 == NIM_NIL))){
    NI32 i_40 = 0;
    {
      while (i_40 < s_110.len_0){
        eQdestroyQ_SX43allX45vent0trakthy001_0_trakthy001((&s_110.data_0[i_40]));
        inc_1_I6wjjge_aow2h993l1((&i_40));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_110.data_0)));}}
void eQdestroy_1_I6bzens1_trakthy001(seq_0_Ins76rj1_trakthy001 s_112){
  if ((!(s_112.data_0 == NIM_NIL))){
    NI32 i_44 = 0;
    {
      while (i_44 < s_112.len_0){
        eQdestroyQ_SX45valX45vent0trakthy001_0_trakthy001((&s_112.data_0[i_44]));
        inc_1_I6wjjge_aow2h993l1((&i_44));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_112.data_0)));}}
void eQdestroy_1_Iyxavnp1_trakthy001(seq_0_Iuignwf1_trakthy001 s_114){
  if ((!(s_114.data_0 == NIM_NIL))){
    NI32 i_48 = 0;
    {
      while (i_48 < s_114.len_0){
        eQdestroyQ_SX42ranchX45vent0trakthy001_0_trakthy001((&s_114.data_0[i_48]));
        inc_1_I6wjjge_aow2h993l1((&i_48));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_114.data_0)));}}
void eQdestroy_1_I8tyh3p1_trakthy001(seq_0_Is6l9yr_trakthy001 s_116){
  if ((!(s_116.data_0 == NIM_NIL))){
    NI32 i_52 = 0;
    {
      while (i_52 < s_116.len_0){
        eQdestroyQ_SX53tep0trakthy001_0_trakthy001(s_116.data_0[i_52]);
        inc_1_I6wjjge_aow2h993l1((&i_52));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_116.data_0)));}}
void eQdestroyQ_SX45valX45vent0trakthy001_0_trakthy001(EvalEvent_0_trakthy001* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).val_0));
  nimStrDestroy((*dest_0).code_0);}
void eQdestroyQ_SX42ranchX45vent0trakthy001_0_trakthy001(BranchEvent_0_trakthy001* dest_0){
  nimStrDestroy((*dest_0).callee_0);
  nimStrDestroy((*dest_0).chose_0);
  nimStrDestroy((*dest_0).sel_0);
  nimStrDestroy((*dest_0).form_0);}
void eQdestroyQ_SX53tep0trakthy001_0_trakthy001(Step_0_trakthy001 dest_0){
  nimStrDestroy(dest_0.site_0);
  nimStrDestroy(dest_0.name_0);}
void eQdestroyQ_SX43allX45vent0trakthy001_0_trakthy001(CallEvent_0_trakthy001* dest_0){
  nimStrDestroy((*dest_0).file_0);
  nimStrDestroy((*dest_0).retR_0);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).ret_0));
  eQdestroy_1_Ivioh0a_ast8ri79k((*dest_0).argsR_0);
  eQdestroy_1_Inxd7ue1_chu5m1rja1((*dest_0).args_0);
  nimStrDestroy((*dest_0).callee_0);}
void eQdestroyQ_SX54raceX4fbj0trakthy001_0_trakthy001(Trace_Obj_0_trakthy001* dest_0){
  eQdestroy_1_I7a20g9_fiepkwzpc((*dest_0).recStack_0);
  eQdestroyQ_SX54able0X49dzlvr_0_trakthy001((*dest_0).prof_0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1((*dest_0).frames_0);
  eQdestroy_1_I8tyh3p1_trakthy001((*dest_0).steps_0);
  eQdestroy_1_Iyxavnp1_trakthy001((*dest_0).branches_0);
  eQdestroy_1_I6bzens1_trakthy001((*dest_0).evals_0);
  eQdestroy_1_I5fvguk1_trakthy001((*dest_0).calls_0);
  nimStrDestroy((*dest_0).text_0);}
void eQdestroyQ_SX54able0X49dzlvr_0_trakthy001(Table_0_Idzlvr_sempjk6bn1 dest_0){
  eQdestroy_1_I5skmro_filqx2b6r1(dest_0.hashes_0);
  eQdestroy_1_Ime9ach1_sempjk6bn1(dest_0.data_0);}
void eQwasmovedQ_SX54able0X49dzlvr_0_trakthy001(Table_0_Idzlvr_sempjk6bn1* dest_0){
  eQwasMoved_1_Iydurru1_sempjk6bn1((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_filqx2b6r1((&(*dest_0).hashes_0));}
void eQdestroyQ_ArefSX54raceX4fbj0trakthy001_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001* dest_0){
  if (dest_0){
    NB8 X60Qx_300 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_300){
      eQdestroyQ_SX54raceX4fbj0trakthy001_0_trakthy001((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX54raceX4fbj0trakthy001_0_trakthy001(X60Qt_0_IArefSX54raceX4fbj0trakthy001_trakthy001** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_AtupleSstring0sysvq0aslAiS32_0_trakthy001(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g dest_0){
  nimStrDestroy(dest_0.fld_0);}
void X60Qini_0_trakthy001(void){
  if (X60QiniGuard_0_trakthy001){
    return;}
  X60QiniGuard_0_trakthy001 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tabcr240b1();
  X60Qini_0_valzr1t4f();}
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
static inline seq_0_Iflf8jf1_fiepkwzpc newSeqUninit_0_I5mozxi1_fiepkwzpc(NI32 size_9){
  seq_0_Iflf8jf1_fiepkwzpc result_10;
  if (size_9 == 0){
    result_10 = (seq_0_Iflf8jf1_fiepkwzpc){
      .len_0 = size_9, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Ih4q01h_fiepkwzpc(size_9);
    void* X60Qx_138 = alloc_1_sysvq0asl(memSize_2);
    result_10 = (seq_0_Iflf8jf1_fiepkwzpc){
      .len_0 = size_9, .data_0 = ((NB8*)X60Qx_138)}
    ;
    if ((!(result_10.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_139 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_10.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_10;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline HSlice_0_Inzqy8d_comaa5xpt1 ___1_Iclcqmw1_comaa5xpt1(NI32 a_28, NI32 b_13){
  HSlice_0_Inzqy8d_comaa5xpt1 result_116;
  result_116 = (HSlice_0_Inzqy8d_comaa5xpt1){
    .a_0 = a_28, .b_0 = b_13}
  ;
  return result_116;}
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_comaa5xpt1 x_355){
  string_0_sysvq0asl result_224;
  nimStrWasMoved((&result_224));
  nimStrDestroy(result_224);
  string_0_sysvq0asl X60Qx_437 = substr_0_sysvq0asl(s_77, x_355.a_0, x_355.b_0);
  result_224 = X60Qx_437;
  return result_224;}
static inline openArray_0_Ijk0jkw1_feaji4clb1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67){
  openArray_0_Ijk0jkw1_feaji4clb1 result_146;
  NC8* X60Qx_316 = readRawData_0_sysvq0asl((&(*s_67)), 0);
  NI32 X60Qx_317 = len_4_sysvq0asl((*s_67));
  result_146 = (openArray_0_Ijk0jkw1_feaji4clb1){
    .a_0 = X60Qx_316, .len_0 = X60Qx_317}
  ;
  return result_146;}
static inline NI32 len_6_Iroq7kd1_feaji4clb1(openArray_0_Ijk0jkw1_feaji4clb1 a_3){
  NI32 result_3;
  result_3 = a_3.len_0;
  return result_3;}
static inline NC8* getQ_10_I5nt6we_feaji4clb1(openArray_0_Ijk0jkw1_feaji4clb1 x_2, NI32 idx_1){
  NB8 X60Qx_6;
  if (0 <= idx_1){
    X60Qx_6 = (idx_1 < x_2.len_0);}
  else {
    X60Qx_6 = NIM_FALSE;}
  if ((!X60Qx_6)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  NC8* result_4;
  result_4 = (&x_2.a_0[idx_1]);
  return result_4;}
static inline NI32 len_3_I4n9kvq_comaa5xpt1(seq_0_I50urnw_chu5m1rja1 s_121){
  NI32 result_67;
  result_67 = s_121.len_0;
  return result_67;}
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_natd5co251(seq_0_I50urnw_chu5m1rja1 s_29, NI32 i_13){
  NB8 X60Qx_108;
  if (i_13 < s_29.len_0){
    X60Qx_108 = (0 <= i_13);}
  else {
    X60Qx_108 = NIM_FALSE;}
  if ((!X60Qx_108)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  Value_0_valzr1t4f* result_19;
  result_19 = (&s_29.data_0[i_13]);
  return result_19;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline void add_0_Irnc3p1_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc* s_19, NB8 elem_7){
  NI32 L_2 = (*s_19).len_0;
  NI32 X60Qx_144 = capInBytes_0_In1m6ni_fiepkwzpc((*s_19));
  if (X60Qx_144 < ((NI32)(((NI32)(L_2 * sizeof(NB8))) + sizeof(NB8)))){
    NB8 X60Qx_145 = resize_0_I2yw78g1_fiepkwzpc(s_19, 1);
    if ((!X60Qx_145)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_19).len_0));
  (*s_19).data_0[L_2] = elem_7;}
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
static inline void add_0_I8kd4i4_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_114, NI32 elem_27){
  NI32 L_2 = (*s_114).len_0;
  NI32 X60Qx_1797 = capInBytes_0_Iet286n_chu5m1rja1((*s_114));
  if (X60Qx_1797 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1798 = resize_0_I8l4tya_comaa5xpt1(s_114, 1);
    if ((!X60Qx_1798)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_114).len_0));
  (*s_114).data_0[L_2] = elem_27;}
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
static inline NI32 len_3_I9hktyf_sigekpubi1(seq_0_Iflf8jf1_fiepkwzpc s_58){
  NI32 result_107;
  result_107 = s_58.len_0;
  return result_107;}
static inline NB8* getQ_7_Iul1no9_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_24, NI32 i_7){
  NB8 X60Qx_148;
  if (i_7 < s_24.len_0){
    X60Qx_148 = (0 <= i_7);}
  else {
    X60Qx_148 = NIM_FALSE;}
  if ((!X60Qx_148)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NB8* result_14;
  result_14 = (&s_24.data_0[i_7]);
  return result_14;}
static inline NI32 len_3_I0v1j8d_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_173){
  NI32 result_100;
  result_100 = s_173.len_0;
  return result_100;}
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36){
  NB8 X60Qx_1793;
  if (i_36 < s_110.len_0){
    X60Qx_1793 = (0 <= i_36);}
  else {
    X60Qx_1793 = NIM_FALSE;}
  if ((!X60Qx_1793)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NI32* result_62;
  result_62 = (&s_110.data_0[i_36]);
  return result_62;}
static inline seq_0_Ix7ee6h_sempjk6bn1 newSeqUninit_0_Ig5459y1_sempjk6bn1(NI32 size_82){
  seq_0_Ix7ee6h_sempjk6bn1 result_81;
  if (size_82 == 0){
    result_81 = (seq_0_Ix7ee6h_sempjk6bn1){
      .len_0 = size_82, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_41 = memSizeInBytes_0_Ivx6m0g1_sempjk6bn1(size_82);
    void* X60Qx_279 = alloc_1_sysvq0asl(memSize_41);
    result_81 = (seq_0_Ix7ee6h_sempjk6bn1){
      .len_0 = size_82, .data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g*)X60Qx_279)}
    ;
    if ((!(result_81.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_280 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_81.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_41);}}
  return result_81;}
static inline seq_0_Ikxuplm1_filqx2b6r1 newSeqUninit_0_Iie69x21_filqx2b6r1(NI32 size_13){
  seq_0_Ikxuplm1_filqx2b6r1 result_27;
  if (size_13 == 0){
    result_27 = (seq_0_Ikxuplm1_filqx2b6r1){
      .len_0 = size_13, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_8 = memSizeInBytes_0_Ilp7p16_filqx2b6r1(size_13);
    void* X60Qx_86 = alloc_1_sysvq0asl(memSize_8);
    result_27 = (seq_0_Ikxuplm1_filqx2b6r1){
      .len_0 = size_13, .data_0 = ((HashEntry_0_tabcr240b1*)X60Qx_86)}
    ;
    if ((!(result_27.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_87 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_27.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_8);}}
  return result_27;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline NI32 high_3_Iyuup9h1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_17){
  NI32 result_15;
  result_15 = ((NI32)(s_17.len_0 - 1));
  return result_15;}
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_18, NU32 i_9){
  if ((!(i_9 < ((NU32)s_18.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  HashEntry_0_tabcr240b1* result_16;
  result_16 = (&s_18.data_0[((NI32)i_9)]);
  return result_16;}
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2){
  NB8 result_1;
  result_1 = (0 < a_2.position_0);
  return result_1;}
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0){
  NU32 result_14;
  result_14 = ((NU32)(((NU32)(h_2 + 1u)) & ((NU32)maxHash_0)));
  return result_14;}
static inline NI32 len_3_Iiefpcc1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_19){
  NI32 result_17;
  result_17 = s_19.len_0;
  return result_17;}
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0){
  NB8 result_0;
  NB8 X60Qx_2;
  if (length_0 < ((NI32)(((NI32)(counter_0 / 2)) + counter_0))){
    X60Qx_2 = NIM_TRUE;}
  else {
    X60Qx_2 = (((NI32)(length_0 - counter_0)) < 4);}
  result_0 = X60Qx_2;
  return result_0;}
static inline void putQ_8_Ipchg2a_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_22, NU32 i_11, HashEntry_0_tabcr240b1 elem_5){
  if ((!(i_11 < ((NU32)(*s_22).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_22).data_0[((NI32)i_11)] = elem_5;}
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
static inline NI32 capInBytes_0_In1m6ni_fiepkwzpc(seq_0_Iflf8jf1_fiepkwzpc s_38){
  NI32 result_31;
  NI32 X60Qx_5;
  if ((!(s_38.data_0 == NIM_NIL))){
    NI32 X60Qx_168 = allocatedSize_0_sysvq0asl(((void*)((void*)s_38.data_0)));
    X60Qx_5 = X60Qx_168;}
  else {
    X60Qx_5 = 0;}
  result_31 = X60Qx_5;
  return result_31;}
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
static inline NI32 capInBytes_0_Igxyzwi_sempjk6bn1(seq_0_Ix7ee6h_sempjk6bn1 s_173){
  NI32 result_82;
  NI32 X60Qx_11;
  if ((!(s_173.data_0 == NIM_NIL))){
    NI32 X60Qx_281 = allocatedSize_0_sysvq0asl(((void*)((void*)s_173.data_0)));
    X60Qx_11 = X60Qx_281;}
  else {
    X60Qx_11 = 0;}
  result_82 = X60Qx_11;
  return result_82;}
static inline NI32 memSizeInBytes_0_Ivx6m0g1_sempjk6bn1(NI32 size_83){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_83;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_83, sizeof(X60Qt_0_IAtupleSstring0sysvq0aslAiS32_maglvku5g), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_83 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_83 = ((NI32)2147483647);}
  return result_83;}
static inline void eQwasMoved_1_Iydurru1_sempjk6bn1(seq_0_Ix7ee6h_sempjk6bn1* s_108){
  (*s_108).len_0 = 0;
  (*s_108).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I8aeezd1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_35){
  (*s_35).len_0 = 0;
  (*s_35).data_0 = NIM_NIL;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
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
static inline NI32 memSizeInBytes_0_Ih4q01h_fiepkwzpc(NI32 size_17){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_26;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_17, sizeof(NB8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_26 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_26 = ((NI32)2147483647);}
  return result_26;}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0){
  NC8* result_103;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_39).bytes_0))))){
    result_103 = ((NC8*)((NU32)(((NU32)(&(*(*s_39).more_0).data_0[0])) + ((NU32)start_0))));}
  else {
    result_103 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_39).bytes_0)) + 1u)))) + ((NU32)start_0))));}
  return result_103;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline NI32 memSizeInBytes_0_Ilp7p16_filqx2b6r1(NI32 size_8){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_21;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_8, sizeof(HashEntry_0_tabcr240b1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_21 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_21 = ((NI32)2147483647);}
  return result_21;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
