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
#include <string.h>
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct FieldOff_0_fiepkwzpc FieldOff_0_fiepkwzpc;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689 X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1 X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct openArray_0_Ig73pnk_comaa5xpt1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_comaa5xpt1;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct seq_0_Iw8xl5b1_flaksyopx1{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_flaksyopx1;
typedef struct openArray_0_Ihovqtr1_fiepkwzpc{
  FieldOff_0_fiepkwzpc* a_0;
  NI32 len_0;}
openArray_0_Ihovqtr1_fiepkwzpc;
typedef struct seq_0_Il6bofj1_flaksyopx1{
  NI32 len_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Il6bofj1_flaksyopx1;
typedef struct seq_0_Incv1wn_explnj22x1{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_explnj22x1;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
typedef struct openArray_0_Inqs7yx_comaa5xpt1{
  NI32* a_0;
  NI32 len_0;}
openArray_0_Inqs7yx_comaa5xpt1;
typedef struct seq_0_Id0odh1_fiepkwzpc{
  NI32 len_0;
  FieldOff_0_fiepkwzpc* data_0;}
seq_0_Id0odh1_fiepkwzpc;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS8_flaksyopx1{
  string_0_sysvq0asl a[8];}
X60Qt_0_IAarraySstring0sysvq0aslS8_flaksyopx1;
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
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_ast8ri79k names_0;
  seq_0_Iw8xl5b1_flaksyopx1 cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IAtupleAboolZAiS32ZAiS32ZSX54X43ode0valzr1t4fSX53ymX49d0nifh7u8pu1_flaksyopx1{
  NB8 fld_0;
  NI32 fld_1;
  NI32 fld_2;
  TCode_0_valzr1t4f fld_3;
  NU32 fld_4;}
X60Qt_0_IAtupleAboolZAiS32ZAiS32ZSX54X43ode0valzr1t4fSX53ymX49d0nifh7u8pu1_flaksyopx1;
typedef struct X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1{
  NB8 fld_0;
  Value_0_valzr1t4f fld_1;}
X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1;
typedef struct X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1{
  NI32 fld_0;
  TCode_0_valzr1t4f fld_1;}
X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1;
typedef struct X60Qt_0_IAtupleAboolZArefSX46latX52egionX4fbj0valzr1t4fZAiS32ZAiS32ZSX54X43ode0R36_flaksyopx1{
  NB8 fld_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* fld_1;
  NI32 fld_2;
  NI32 fld_3;
  TCode_0_valzr1t4f fld_4;}
X60Qt_0_IAtupleAboolZArefSX46latX52egionX4fbj0valzr1t4fZAiS32ZAiS32ZSX54X43ode0R36_flaksyopx1;
typedef struct X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1{
  Value_0_valzr1t4f fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1;
typedef struct X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1{
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct FieldOff_0_fiepkwzpc{
  NU32 sym_0;
  NI32 off_0;
  NI32 size_0;
  TCode_0_valzr1t4f code_0;
  NU32 tsym_0;
  NB8 variant_0;}
FieldOff_0_fiepkwzpc;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
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
Value_0_valzr1t4f flLoadObj_1_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_11, NI32 off_8, NU32 tsym_1, NI32 depth_3);
static inline openArray_0_Ig73pnk_comaa5xpt1 toOpenArray_0_I1pr4a81_flaksyopx1(X60Qt_0_IAarraySstring0sysvq0aslS8_flaksyopx1* x_2);
static inline NI32 len_3_I83dzei_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_23);
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_24, NI32 i_31);
static inline seq_0_Iw8xl5b1_flaksyopx1 newSeqUninit_0_I1tbjnk1_flaksyopx1(NI32 size_7);
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8);
static inline NI32 len_3_Iau77c6_flaksyopx1(seq_0_Il6bofj1_flaksyopx1 s_37);
static inline X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** getQ_7_I1p0jos_flaksyopx1(seq_0_Il6bofj1_flaksyopx1 s_38, NI32 i_37);
static inline void add_0_I0t6c8o_flaksyopx1(seq_0_Il6bofj1_flaksyopx1* s_39, X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* elem_9);
void setLen_0_I9zf5sf1_flaksyopx1(seq_0_Incv1wn_explnj22x1* s_41, NI32 newLen_1);
seq_0_Ift2sne_chu5m1rja1 newSeq_0_I7328u4_flaksyopx1(NI32 size_13);
static inline void putQ_7_Iv6u0oa1_flaksyopx1(seq_0_Il6bofj1_flaksyopx1* s_47, NI32 i_43, X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* elem_11);
static inline NI32 memSizeInBytes_0_Ixcobep_flaksyopx1(NI32 size_16);
static inline NI32 capInBytes_0_Iih34tr1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_49);
NB8 resize_0_If3pogj_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* dest_4, NI32 addedElements_4);
static inline NI32 memSizeInBytes_0_I6mjfpb1_flaksyopx1(NI32 size_17);
static inline NI32 capInBytes_0_Ixu29jk_flaksyopx1(seq_0_Il6bofj1_flaksyopx1 s_51);
NB8 resize_0_Is4jxz_flaksyopx1(seq_0_Il6bofj1_flaksyopx1* dest_5, NI32 addedElements_5);
void shrink_0_I7bszm81_flaksyopx1(seq_0_Incv1wn_explnj22x1* s_52, NI32 newLen_4);
void growUnsafe_0_I4f7zfx1_flaksyopx1(seq_0_Incv1wn_explnj22x1* s_53, NI32 newLen_5);
NB8 resize_0_Iuiuhg71_flaksyopx1(seq_0_Incv1wn_explnj22x1* dest_7, NI32 addedElements_7);
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_AtupleAboolZSX56alue0valzr1t4f_0_flaksyopx1(X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1* dest_0);
void eQdestroyQ_AtupleAboolZSX56alue0valzr1t4f_0_flaksyopx1(X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1* dest_0);
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_flaksyopx1(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1* dest_0);
void eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_flaksyopx1(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1* dest_0);
void eQwasmovedQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1* dest_0);
void eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 dest_0);
static inline NI32 len_6_Igv2wyu1_comaa5xpt1(openArray_0_Ig73pnk_comaa5xpt1 a_40);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_comaa5xpt1(openArray_0_Ig73pnk_comaa5xpt1 x_29, NI32 idx_30);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern Value_0_valzr1t4f vInt_0_valzr1t4f(NI64 x_2, NI32 bits_0);
extern Value_0_valzr1t4f vUInt_0_valzr1t4f(NU64 x_4, NI32 bits_2);
extern NI64 asInt_0_valzr1t4f(Value_0_valzr1t4f* v_4);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
extern Value_0_valzr1t4f vChar_0_valzr1t4f(NC8 c_0);
extern Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0);
extern string_0_sysvq0asl enumNameForOrdinal_0_fiepkwzpc(NU32 enumType_0, NI32 ord_0);
extern Value_0_valzr1t4f vEnum_0_valzr1t4f(NI32 ord_0, NU32 ekind_0, string_0_sysvq0asl name_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern Value_0_valzr1t4f vFloat_0_valzr1t4f(NF64 f_0, NI32 bits_4);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
static inline NI32 len_3_Izoe8zv_explnj22x1(seq_0_Incv1wn_explnj22x1 s_25);
static inline NU8* getQ_7_Ig0r1051_explnj22x1(seq_0_Incv1wn_explnj22x1 s_26, NI32 i_23);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline NI32 len_3_I0v1j8d_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_173);
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36);
static inline void putQ_7_Ipw0nqk1_explnj22x1(seq_0_Incv1wn_explnj22x1* s_29, NI32 i_26, NU8 elem_9);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15);
extern Value_0_valzr1t4f vStr_0_valzr1t4f(string_0_sysvq0asl s_0);
extern Value_0_valzr1t4f vNil_0_valzr1t4f(void);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_In6doa_ast8ri79k newSeqUninit_0_Ieodq4s1_ast8ri79k(NI32 size_32);
static inline NI32 len_3_I6y2imo_buiyylk1h1(seq_0_In6doa_ast8ri79k s_56);
static inline NU32* getQ_7_I2v00yv1_buiyylk1h1(seq_0_In6doa_ast8ri79k s_58, NI32 i_28);
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
extern X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* newCell_0_valzr1t4f(Value_0_valzr1t4f* v_0);
static inline void add_0_I34il1q_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_112, NU32 elem_26);
extern seq_0_Id0odh1_fiepkwzpc fieldOffsetsOfType_0_fiepkwzpc(NU32 typeSym_1);
static inline NI32 len_3_If78p9o_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_31);
extern void eQdestroy_1_Ijysww_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_63);
static inline openArray_0_Ihovqtr1_fiepkwzpc toOpenArray_1_Ilfv4hf_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_32);
static inline NI32 len_6_Ikuawih_fiepkwzpc(openArray_0_Ihovqtr1_fiepkwzpc a_4);
static inline FieldOff_0_fiepkwzpc* getQ_10_Iu0e57f_fiepkwzpc(openArray_0_Ihovqtr1_fiepkwzpc x_3, NI32 idx_4);
extern seq_0_Incv1wn_explnj22x1 newSeq_0_Ivbxvoi1_explnj22x1(NI32 size_3);
static inline void eQwasMoved_1_I861g1c1_explnj22x1(seq_0_Incv1wn_explnj22x1* s_130);
extern void eQdestroy_1_Ijx6eoq_explnj22x1(seq_0_Incv1wn_explnj22x1 s_129);
static inline void putQ_7_Ifvyck5_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_111, NI32 i_37, NI32 elem_25);
static inline void eQwasMoved_1_Ix88qzs1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1* s_35);
extern void eQdestroy_1_Iv9ij5i1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_34);
static inline openArray_0_Inqs7yx_comaa5xpt1 toOpenArray_1_Ibqb4ob_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_160);
static inline NI32 len_6_I9632ti1_comaa5xpt1(openArray_0_Inqs7yx_comaa5xpt1 a_32);
static inline NI32* getQ_10_I053icq_comaa5xpt1(openArray_0_Inqs7yx_comaa5xpt1 x_21, NI32 idx_24);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern string_0_sysvq0asl itoa_0_valzr1t4f(NI64 x_0);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_comaa5xpt1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
static inline NI32 capInBytes_0_Iffahgv_explnj22x1(seq_0_Incv1wn_explnj22x1 s_149);
static inline NI32 memSizeInBytes_0_Infw7m1_explnj22x1(NI32 size_6);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f(Cell_Obj_0_valzr1t4f* dest_0);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(ObjBox_Obj_0_valzr1t4f dest_0);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(FlatRegion_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(ArrBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(SeqBox_Obj_0_valzr1t4f dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_fiepkwzpc(void);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_comaa5xpt1;
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
extern LongString_0_sysvq0asl const strlit_0_I11201514831099767300_sysvq0asl;
extern void prepareMutation_0_sysvq0asl(string_0_sysvq0asl* s_46);
static inline NI32 memSizeInBytes_0_Ivqzo5x1_ast8ri79k(NI32 size_33);
static inline NI32 capInBytes_0_Iev6wua1_ast8ri79k(seq_0_In6doa_ast8ri79k s_73);
extern NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_ast8ri79k* dest_8, NI32 addedElements_8);
static inline FieldOff_0_fiepkwzpc* rawData_0_Ifr35xc1_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_41);
static inline NI32* rawData_0_Ic25u3r_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_236);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I16513080964259093980_flaksyopx1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "copyMem"}
;
LongString_0_sysvq0asl const strlit_0_I15154933186756103481_flaksyopx1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "moveMem"}
;
LongString_0_sysvq0asl const strlit_0_I14137437451056432656_flaksyopx1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "zeroMem"}
;
LongString_0_sysvq0asl const strlit_0_I14385440250011608213_flaksyopx1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "equalMem"}
;
LongString_0_sysvq0asl const strlit_0_I10175009822598077709_flaksyopx1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "alloc"}
;
LongString_0_sysvq0asl const strlit_0_I6624701989437400523_flaksyopx1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "alloc0"}
;
LongString_0_sysvq0asl const strlit_0_I13706781941607385374_flaksyopx1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dealloc"}
;
LongString_0_sysvq0asl const strlit_0_I8010039202931761952_flaksyopx1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "realloc"}
;
LongString_0_sysvq0asl const strlit_0_I7981118950328739133_flaksyopx1 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "not-a-cell-address"}
;
LongString_0_sysvq0asl const strlit_0_I4206788977324198015_flaksyopx1 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unminted-cell-slot"}
;
LongString_0_sysvq0asl const strlit_0_I15879331316645165_flaksyopx1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "no-lens-for-cell"}
;
LongString_0_sysvq0asl const strlit_0_I5967086138208162463_flaksyopx1 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cell-offset-past-end:"}
;
X60Qt_0_IAarraySstring0sysvq0aslS8_flaksyopx1 const MemMagics_0_flaksyopx1 = {
  .a = {
    {
      .bytes_0 = 1886348286u, .more_0 = (&strlit_0_I16513080964259093980_flaksyopx1)}
    , {
      .bytes_0 = 1987014142u, .more_0 = (&strlit_0_I15154933186756103481_flaksyopx1)}
    , {
      .bytes_0 = 1919253246u, .more_0 = (&strlit_0_I14137437451056432656_flaksyopx1)}
    , {
      .bytes_0 = 1970365950u, .more_0 = (&strlit_0_I14385440250011608213_flaksyopx1)}
    , {
      .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I10175009822598077709_flaksyopx1)}
    , {
      .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I6624701989437400523_flaksyopx1)}
    , {
      .bytes_0 = 1634034942u, .more_0 = (&strlit_0_I13706781941607385374_flaksyopx1)}
    , {
      .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I8010039202931761952_flaksyopx1)}}}
;
static NI32 const ForeignScanMax_0 = ((NI32)1048576);
seq_0_Il6bofj1_flaksyopx1 regionTable_0_flaksyopx1;
seq_0_Iw8xl5b1_flaksyopx1 cellTable_0_flaksyopx1;
seq_0_Il6bofj1_flaksyopx1 cellLensTable_0_flaksyopx1;
NB8 X60QiniGuard_0_flaksyopx1;
NB8 isMemMagic_0_flaksyopx1(string_0_sysvq0asl base_0){
  NB8 result_0;
  {
    openArray_0_Ig73pnk_comaa5xpt1 X60Qlf_0 = toOpenArray_0_I1pr4a81_flaksyopx1((&MemMagics_0_flaksyopx1));
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_37 = len_6_Igv2wyu1_comaa5xpt1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_37){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_comaa5xpt1(X60Qlf_0, X60Qlf_1);
            NB8 X60Qx_38 = eqQ_20_sysvq0asl((*X60Qii_2), base_0);
            if (X60Qx_38){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  result_0 = NIM_FALSE;
  return result_0;}
Value_0_valzr1t4f reinterpToInt_0_flaksyopx1(NU64 raw_0, NI32 tbits_0, NB8 tsigned_0){
  Value_0_valzr1t4f result_1;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_1));
  NU64 X60Qx_0;
  if (64 <= tbits_0){
    X60Qx_0 = raw_0;}
  else {
    X60Qx_0 = ((NU64)(raw_0 & ((NU64)(((NU64)(((NU64)1u) << ((NU32)tbits_0))) - ((NU64)1u)))));}
  NU64 mval_0 = X60Qx_0;
  if (tsigned_0){
    NI64 sv_0 = ((NI64)mval_0);
    NB8 X60Qx_39;
    if (tbits_0 < 64){
      X60Qx_39 = (!(((NU64)(mval_0 & ((NU64)(((NU64)1u) << ((NU32)((NI32)(tbits_0 - 1))))))) == ((NU64)0u)));}
    else {
      X60Qx_39 = NIM_FALSE;}
    if (X60Qx_39){
      sv_0 = ((NI64)((NU64)(mval_0 | ((NU64) ~ ((NU64)(((NU64)(((NU64)1u) << ((NU32)tbits_0))) - ((NU64)1u)))))));}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_1));
    Value_0_valzr1t4f X60Qx_40 = vInt_0_valzr1t4f(sv_0, tbits_0);
    result_1 = X60Qx_40;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_1));
    Value_0_valzr1t4f X60Qx_41 = vUInt_0_valzr1t4f(mval_0, tbits_0);
    result_1 = X60Qx_41;}
  return result_1;}
NI32 bitsOf_0_flaksyopx1(Value_0_valzr1t4f* v_0){
  NI32 result_2;
  NI32 X60Qx_1;
  switch ((*v_0).kind_0){
    case 1:
    case 2:
    {
      NI32 X60Qx_2;
      if (0 < (*v_0).bits_0){
        X60Qx_2 = (*v_0).bits_0;}
      else {
        X60Qx_2 = 64;}
      X60Qx_1 = X60Qx_2;}
    break;
    case 3:
    {
      NI32 X60Qx_3;
      if (0 < (*v_0).fbits_0){
        X60Qx_3 = (*v_0).fbits_0;}
      else {
        X60Qx_3 = 64;}
      X60Qx_1 = X60Qx_3;}
    break;
    case 5:
    {
      X60Qx_1 = 8;}
    break;
    case 4:
    {
      X60Qx_1 = 8;}
    break;
    default:
    {
      X60Qx_1 = 64;}
    break;}
  result_2 = X60Qx_1;
  return result_2;}
NU64 scalarToU64_0_flaksyopx1(Value_0_valzr1t4f* v_1){
  NU64 result_3;
  switch ((*v_1).kind_0){
    case 2:
    case 1:
    {
      NI32 w_0 = bitsOf_0_flaksyopx1((&(*v_1)));
      NI64 X60Qx_42 = asInt_0_valzr1t4f((&(*v_1)));
      result_3 = ((NU64)X60Qx_42);
      if (w_0 < 64){
        result_3 = ((NU64)(result_3 & ((NU64)(((NU64)(((NU64)1u) << ((NU32)w_0))) - ((NU64)1u)))));}}
    break;
    case 5:
    {
      result_3 = ((NU64)((NU8)(*v_1).cval_0));}
    break;
    case 4:
    {
      NU64 X60Qx_4;
      if ((*v_1).bval_0){
        X60Qx_4 = ((NU64)1u);}
      else {
        X60Qx_4 = ((NU64)0u);}
      result_3 = X60Qx_4;}
    break;
    case 7:
    {
      result_3 = ((NU64)((NU64)(*v_1).eord_0));}
    break;
    case 3:
    {
      if ((*v_1).fbits_0 == 32){
        NF32 X60Qx_43 = ((NF32)(*v_1).fval_0);
        NU32 X60Qx_44;
        copyMem_0_sysvq0asl((&X60Qx_44), (&X60Qx_43), sizeof(NU32));
        result_3 = ((NU64)X60Qx_44);}
      else {
        NF64 X60Qx_45 = (*v_1).fval_0;
        NU64 X60Qx_46;
        copyMem_0_sysvq0asl((&X60Qx_46), (&X60Qx_45), sizeof(NU64));
        result_3 = X60Qx_46;}}
    break;
    default:
    {
      result_3 = ((NU64)0u);}
    break;}
  return result_3;}
Value_0_valzr1t4f rebuildScalar_0_flaksyopx1(Value_0_valzr1t4f* old_0, NU64 u_0){
  Value_0_valzr1t4f result_4;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
  switch ((*old_0).kind_0){
    case 2:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
      NI32 X60Qx_47 = bitsOf_0_flaksyopx1((&(*old_0)));
      Value_0_valzr1t4f X60Qx_48 = vUInt_0_valzr1t4f(u_0, X60Qx_47);
      result_4 = X60Qx_48;}
    break;
    case 1:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
      NI32 X60Qx_49 = bitsOf_0_flaksyopx1((&(*old_0)));
      Value_0_valzr1t4f X60Qx_50 = reinterpToInt_0_flaksyopx1(u_0, X60Qx_49, NIM_TRUE);
      result_4 = X60Qx_50;}
    break;
    case 5:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
      Value_0_valzr1t4f X60Qx_51 = vChar_0_valzr1t4f(((NC8)((NU8)((NU64)(u_0 & ((NU64)255u))))));
      result_4 = X60Qx_51;}
    break;
    case 4:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
      Value_0_valzr1t4f X60Qx_52 = vBool_0_valzr1t4f((!(((NU64)(u_0 & ((NU64)1u))) == ((NU64)0u))));
      result_4 = X60Qx_52;}
    break;
    case 7:
    {
      NI32 ord_0 = ((NI32)u_0);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
      string_0_sysvq0asl X60Qtmp_0 = enumNameForOrdinal_0_fiepkwzpc((*old_0).ekind_0, ord_0);
      Value_0_valzr1t4f X60Qx_53 = vEnum_0_valzr1t4f(ord_0, (*old_0).ekind_0, X60Qtmp_0);
      result_4 = X60Qx_53;
      nimStrDestroy(X60Qtmp_0);}
    break;
    case 3:
    {
      if ((*old_0).fbits_0 == 32){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
        NU32 X60Qx_54 = ((NU32)((NU64)(u_0 & ((NU64)4294967295u))));
        NF32 X60Qx_55;
        copyMem_0_sysvq0asl((&X60Qx_55), (&X60Qx_54), sizeof(NF32));
        Value_0_valzr1t4f X60Qx_56 = vFloat_0_valzr1t4f(((NF64)X60Qx_55), 32);
        result_4 = X60Qx_56;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
        NF64 X60Qx_57;
        copyMem_0_sysvq0asl((&X60Qx_57), (&u_0), sizeof(NF64));
        Value_0_valzr1t4f X60Qx_58 = vFloat_0_valzr1t4f(X60Qx_57, 64);
        result_4 = X60Qx_58;}}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_4));
      Value_0_valzr1t4f X60Qx_59 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*old_0)));
      result_4 = X60Qx_59;}
    break;}
  return result_4;}
NI32 elemBytes_0_flaksyopx1(NI32 bits_0){
  NI32 result_5;
  NI64 X60Qx_5;
  if (bits_0 <= 0){
    X60Qx_5 = 1;}
  else {
    X60Qx_5 = ((NI32)(bits_0 / 8));}
  result_5 = X60Qx_5;
  return result_5;}
NU8 cellByte_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_0, NI32 bi_0){
  NU8 result_6;
  NB8 X60Qx_60;
  NB8 X60Qx_61;
  if (c_0 == NIM_NIL){
    X60Qx_61 = NIM_TRUE;}
  else {
    X60Qx_61 = (bi_0 < 0);}
  if (X60Qx_61){
    X60Qx_60 = NIM_TRUE;}
  else {
    X60Qx_60 = (8 <= bi_0);}
  if (X60Qx_60){
    return ((NU8)0);}
  NU64 u_3 = scalarToU64_0_flaksyopx1((&(*c_0).d_00.v_0));
  result_6 = ((NU8)((NU64)(((NU64)(u_3 >> ((NU32)(((NU32)bi_0) * 8u)))) & ((NU64)255u))));
  return result_6;}
void setCellByte_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1, NI32 bi_1, NU8 b_0){
  NB8 X60Qx_62;
  NB8 X60Qx_63;
  if (c_1 == NIM_NIL){
    X60Qx_63 = NIM_TRUE;}
  else {
    X60Qx_63 = (bi_1 < 0);}
  if (X60Qx_63){
    X60Qx_62 = NIM_TRUE;}
  else {
    X60Qx_62 = (8 <= bi_1);}
  if (X60Qx_62){
    return;}
  NU64 u_4 = scalarToU64_0_flaksyopx1((&(*c_1).d_00.v_0));
  u_4 = ((NU64)(u_4 & ((NU64) ~ ((NU64)(((NU64)255u) << ((NU32)(((NU32)bi_1) * 8u)))))));
  u_4 = ((NU64)(u_4 | ((NU64)(((NU64)b_0) << ((NU32)(((NU32)bi_1) * 8u))))));
  Value_0_valzr1t4f* X60Qlhs_1 = (&(*c_1).d_00.v_0);
  Value_0_valzr1t4f X60Qlhs_2 = rebuildScalar_0_flaksyopx1((&(*c_1).d_00.v_0), u_4);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_1)));
  (*X60Qlhs_1) = X60Qlhs_2;}
NU8 foreignByte_0_flaksyopx1(NU64 haddr_0, NI32 off_0){
  NU8 result_9;
  if (haddr_0 == ((NU64)0u)){
    return ((NU8)0);}
  result_9 = (*((NU8*)((NU32)(((NU32)haddr_0) + ((NU32)off_0)))));
  return result_9;}
NU8 byteAt_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_1, NI32 off_1){
  NU8 result_10;
  NB8 X60Qx_65;
  if (r_1 == NIM_NIL){
    X60Qx_65 = NIM_TRUE;}
  else {
    X60Qx_65 = (off_1 < 0);}
  if (X60Qx_65){
    return ((NU8)0);}
  switch ((*r_1).d_00.kind_0){
    case 0:
    {
      NI32 X60Qx_66 = len_3_Izoe8zv_explnj22x1((*r_1).d_00.bytes_0);
      if (off_1 < X60Qx_66){
        NU8* X60Qx_67 = getQ_7_Ig0r1051_explnj22x1((*r_1).d_00.bytes_0, off_1);
        result_10 = (*X60Qx_67);}
      else {
        result_10 = ((NU8)0);}}
    break;
    case 6:
    {
      NB8 X60Qx_68;
      if (0 <= (*r_1).d_00.hlen_0){
        X60Qx_68 = ((*r_1).d_00.hlen_0 <= off_1);}
      else {
        X60Qx_68 = NIM_FALSE;}
      if (X60Qx_68){
        result_10 = ((NU8)0);}
      else {
        NU8 X60Qx_69 = foreignByte_0_flaksyopx1((*r_1).d_00.haddr_0, off_1);
        result_10 = X60Qx_69;}}
    break;
    case 2:
    {
      NI32 eb_0 = elemBytes_0_flaksyopx1((*r_1).d_00.aEbits_0);
      NI32 ei_0 = ((NI32)(off_1 / eb_0));
      NI32 bi_2 = ((NI32)(off_1 % eb_0));
      NB8 X60Qx_70;
      NB8 X60Qx_71;
      if ((!((*r_1).d_00.abox_0 == NIM_NIL))){
        X60Qx_71 = (0 <= ei_0);}
      else {
        X60Qx_71 = NIM_FALSE;}
      if (X60Qx_71){
        NI32 X60Qx_72 = len_3_I83dzei_flaksyopx1((*(*r_1).d_00.abox_0).d_00.elems_0);
        X60Qx_70 = (ei_0 < X60Qx_72);}
      else {
        X60Qx_70 = NIM_FALSE;}
      if (X60Qx_70){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_73 = getQ_7_Ii14ync1_flaksyopx1((*(*r_1).d_00.abox_0).d_00.elems_0, ei_0);
        NU8 X60Qx_74 = cellByte_0_flaksyopx1((*X60Qx_73), bi_2);
        result_10 = X60Qx_74;}
      else {
        result_10 = ((NU8)0);}}
    break;
    case 1:
    {
      NI32 eb_1 = elemBytes_0_flaksyopx1((*r_1).d_00.sEbits_0);
      NI32 ei_1 = ((NI32)(off_1 / eb_1));
      NI32 bi_3 = ((NI32)(off_1 % eb_1));
      NB8 X60Qx_75;
      NB8 X60Qx_76;
      if ((!((*r_1).d_00.sbox_0 == NIM_NIL))){
        X60Qx_76 = (0 <= ei_1);}
      else {
        X60Qx_76 = NIM_FALSE;}
      if (X60Qx_76){
        NI32 X60Qx_77 = len_3_I83dzei_flaksyopx1((*(*r_1).d_00.sbox_0).d_00.elems_0);
        X60Qx_75 = (ei_1 < X60Qx_77);}
      else {
        X60Qx_75 = NIM_FALSE;}
      if (X60Qx_75){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_78 = getQ_7_Ii14ync1_flaksyopx1((*(*r_1).d_00.sbox_0).d_00.elems_0, ei_1);
        NU8 X60Qx_79 = cellByte_0_flaksyopx1((*X60Qx_78), bi_3);
        result_10 = X60Qx_79;}
      else {
        result_10 = ((NU8)0);}}
    break;
    case 3:
    {
      NB8 X60Qx_80;
      NB8 X60Qx_81;
      if ((!((*r_1).d_00.scell_0 == NIM_NIL))){
        X60Qx_81 = ((*(*r_1).d_00.scell_0).d_00.v_0.kind_0 == 6);}
      else {
        X60Qx_81 = NIM_FALSE;}
      if (X60Qx_81){
        NI32 X60Qx_82 = len_4_sysvq0asl((*(*r_1).d_00.scell_0).d_00.v_0.sval_0);
        X60Qx_80 = (off_1 < X60Qx_82);}
      else {
        X60Qx_80 = NIM_FALSE;}
      if (X60Qx_80){
        NC8 X60Qx_83 = getQ_9_sysvq0asl((*(*r_1).d_00.scell_0).d_00.v_0.sval_0, off_1);
        result_10 = ((NU8)((NU8)X60Qx_83));}
      else {
        result_10 = ((NU8)0);}}
    break;
    case 4:
    {
      NU8 X60Qx_84 = cellByte_0_flaksyopx1((*r_1).d_00.ccell_0, off_1);
      result_10 = X60Qx_84;}
    break;
    case 5:
    {
      if ((*r_1).d_00.obox_0 == NIM_NIL){
        return ((NU8)0);}
      NI32 best_0 = -1;
      NI32 bestOff_0 = -1;
      NI32 i_7 = 0;
      {
        while (NIM_TRUE){
          NB8 X60Qx_85;
          NI32 X60Qx_86 = len_3_I0v1j8d_comaa5xpt1((*r_1).d_00.offs_0);
          if (i_7 < X60Qx_86){
            NI32 X60Qx_87 = len_3_I83dzei_flaksyopx1((*(*r_1).d_00.obox_0).d_00.cells_0);
            X60Qx_85 = (i_7 < X60Qx_87);}
          else {
            X60Qx_85 = NIM_FALSE;}
          if (X60Qx_85){
            NB8 X60Qx_88;
            NI32* X60Qx_89 = getQ_7_Ir8kccm_comaa5xpt1((*r_1).d_00.offs_0, i_7);
            if ((*X60Qx_89) <= off_1){
              NI32* X60Qx_90 = getQ_7_Ir8kccm_comaa5xpt1((*r_1).d_00.offs_0, i_7);
              X60Qx_88 = (bestOff_0 < (*X60Qx_90));}
            else {
              X60Qx_88 = NIM_FALSE;}
            if (X60Qx_88){
              NI32* X60Qx_91 = getQ_7_Ir8kccm_comaa5xpt1((*r_1).d_00.offs_0, i_7);
              bestOff_0 = (*X60Qx_91);
              best_0 = i_7;}
            inc_1_I6wjjge_aow2h993l1((&i_7));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      if (0 <= best_0){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_92 = getQ_7_Ii14ync1_flaksyopx1((*(*r_1).d_00.obox_0).d_00.cells_0, best_0);
        NU8 X60Qx_93 = cellByte_0_flaksyopx1((*X60Qx_92), ((NI32)(off_1 - bestOff_0)));
        result_10 = X60Qx_93;}
      else {
        result_10 = ((NU8)0);}}
    break;}
  return result_10;}
NI32 foreignLen_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_3){
  NI32 result_12;
  NB8 X60Qx_104;
  NB8 X60Qx_105;
  if (r_3 == NIM_NIL){
    X60Qx_105 = NIM_TRUE;}
  else {
    X60Qx_105 = (!((*r_3).d_00.kind_0 == 6));}
  if (X60Qx_105){
    X60Qx_104 = NIM_TRUE;}
  else {
    X60Qx_104 = ((*r_3).d_00.haddr_0 == ((NU64)0u));}
  if (X60Qx_104){
    return 0;}
  if (0 <= (*r_3).d_00.hlen_0){
    result_12 = (*r_3).d_00.hlen_0;
    return result_12;}
  NI32 i_10 = 0;
  {
    while (i_10 < ((NI32)1048576)){
      NU8 X60Qx_106 = foreignByte_0_flaksyopx1((*r_3).d_00.haddr_0, i_10);
      if (X60Qx_106 == ((NU8)0u)){
        return i_10;}
      inc_1_I6wjjge_aow2h993l1((&i_10));}}
  whileStmtLabel_0: ;
  result_12 = ((NI32)1048576);
  return result_12;}
void setByteAt_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_4, NI32 off_2, NU8 b_1){
  NB8 X60Qx_107;
  if (r_4 == NIM_NIL){
    X60Qx_107 = NIM_TRUE;}
  else {
    X60Qx_107 = (off_2 < 0);}
  if (X60Qx_107){
    return;}
  switch ((*r_4).d_00.kind_0){
    case 0:
    {
      NI32 X60Qx_108 = len_3_Izoe8zv_explnj22x1((*r_4).d_00.bytes_0);
      if (off_2 < X60Qx_108){
        putQ_7_Ipw0nqk1_explnj22x1((&(*r_4).d_00.bytes_0), off_2, b_1);}}
    break;
    case 6:
    {
      }
    break;
    case 2:
    {
      NI32 eb_2 = elemBytes_0_flaksyopx1((*r_4).d_00.aEbits_0);
      NI32 ei_2 = ((NI32)(off_2 / eb_2));
      NI32 bi_4 = ((NI32)(off_2 % eb_2));
      NB8 X60Qx_109;
      NB8 X60Qx_110;
      if ((!((*r_4).d_00.abox_0 == NIM_NIL))){
        X60Qx_110 = (0 <= ei_2);}
      else {
        X60Qx_110 = NIM_FALSE;}
      if (X60Qx_110){
        NI32 X60Qx_111 = len_3_I83dzei_flaksyopx1((*(*r_4).d_00.abox_0).d_00.elems_0);
        X60Qx_109 = (ei_2 < X60Qx_111);}
      else {
        X60Qx_109 = NIM_FALSE;}
      if (X60Qx_109){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_112 = getQ_7_Ii14ync1_flaksyopx1((*(*r_4).d_00.abox_0).d_00.elems_0, ei_2);
        setCellByte_0_flaksyopx1((*X60Qx_112), bi_4, b_1);}}
    break;
    case 1:
    {
      NI32 eb_3 = elemBytes_0_flaksyopx1((*r_4).d_00.sEbits_0);
      NI32 ei_3 = ((NI32)(off_2 / eb_3));
      NI32 bi_5 = ((NI32)(off_2 % eb_3));
      NB8 X60Qx_113;
      NB8 X60Qx_114;
      if ((!((*r_4).d_00.sbox_0 == NIM_NIL))){
        X60Qx_114 = (0 <= ei_3);}
      else {
        X60Qx_114 = NIM_FALSE;}
      if (X60Qx_114){
        NI32 X60Qx_115 = len_3_I83dzei_flaksyopx1((*(*r_4).d_00.sbox_0).d_00.elems_0);
        X60Qx_113 = (ei_3 < X60Qx_115);}
      else {
        X60Qx_113 = NIM_FALSE;}
      if (X60Qx_113){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_116 = getQ_7_Ii14ync1_flaksyopx1((*(*r_4).d_00.sbox_0).d_00.elems_0, ei_3);
        setCellByte_0_flaksyopx1((*X60Qx_116), bi_5, b_1);}}
    break;
    case 3:
    {
      NB8 X60Qx_117;
      NB8 X60Qx_118;
      if ((!((*r_4).d_00.scell_0 == NIM_NIL))){
        X60Qx_118 = ((*(*r_4).d_00.scell_0).d_00.v_0.kind_0 == 6);}
      else {
        X60Qx_118 = NIM_FALSE;}
      if (X60Qx_118){
        NI32 X60Qx_119 = len_4_sysvq0asl((*(*r_4).d_00.scell_0).d_00.v_0.sval_0);
        X60Qx_117 = (off_2 < X60Qx_119);}
      else {
        X60Qx_117 = NIM_FALSE;}
      if (X60Qx_117){
        string_0_sysvq0asl s_7 = nimStrDup((*(*r_4).d_00.scell_0).d_00.v_0.sval_0);
        putQ_9_sysvq0asl((&s_7), off_2, ((NC8)b_1));
        Value_0_valzr1t4f* X60Qlhs_3 = (&(*(*r_4).d_00.scell_0).d_00.v_0);
        Value_0_valzr1t4f X60Qlhs_4 = vStr_0_valzr1t4f(s_7);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_3)));
        (*X60Qlhs_3) = X60Qlhs_4;
        nimStrDestroy(s_7);}}
    break;
    case 4:
    {
      setCellByte_0_flaksyopx1((*r_4).d_00.ccell_0, off_2, b_1);}
    break;
    case 5:
    {
      if ((*r_4).d_00.obox_0 == NIM_NIL){
        return;}
      NI32 best_1 = -1;
      NI32 bestOff_1 = -1;
      NI32 i_12 = 0;
      {
        while (NIM_TRUE){
          NB8 X60Qx_120;
          NI32 X60Qx_121 = len_3_I0v1j8d_comaa5xpt1((*r_4).d_00.offs_0);
          if (i_12 < X60Qx_121){
            NI32 X60Qx_122 = len_3_I83dzei_flaksyopx1((*(*r_4).d_00.obox_0).d_00.cells_0);
            X60Qx_120 = (i_12 < X60Qx_122);}
          else {
            X60Qx_120 = NIM_FALSE;}
          if (X60Qx_120){
            NB8 X60Qx_123;
            NI32* X60Qx_124 = getQ_7_Ir8kccm_comaa5xpt1((*r_4).d_00.offs_0, i_12);
            if ((*X60Qx_124) <= off_2){
              NI32* X60Qx_125 = getQ_7_Ir8kccm_comaa5xpt1((*r_4).d_00.offs_0, i_12);
              X60Qx_123 = (bestOff_1 < (*X60Qx_125));}
            else {
              X60Qx_123 = NIM_FALSE;}
            if (X60Qx_123){
              NI32* X60Qx_126 = getQ_7_Ir8kccm_comaa5xpt1((*r_4).d_00.offs_0, i_12);
              bestOff_1 = (*X60Qx_126);
              best_1 = i_12;}
            inc_1_I6wjjge_aow2h993l1((&i_12));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      if (0 <= best_1){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_127 = getQ_7_Ii14ync1_flaksyopx1((*(*r_4).d_00.obox_0).d_00.cells_0, best_1);
        setCellByte_0_flaksyopx1((*X60Qx_127), ((NI32)(off_2 - bestOff_1)), b_1);}}
    break;}}
NU64 flLoadRaw_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_5, NI32 off_3, NI32 bits_1){
  NU64 result_13;
  NI32 nb_0 = elemBytes_0_flaksyopx1(bits_1);
  NU64 u_5 = ((NU64)0u);
  NI32 i_13 = 0;
  {
    while (i_13 < nb_0){
      NU8 X60Qx_128 = byteAt_0_flaksyopx1(r_5, ((NI32)(off_3 + i_13)));
      u_5 = ((NU64)(u_5 | ((NU64)(((NU64)X60Qx_128) << ((NU32)(((NU32)i_13) * 8u))))));
      inc_1_I6wjjge_aow2h993l1((&i_13));}}
  whileStmtLabel_0: ;
  result_13 = u_5;
  return result_13;}
Value_0_valzr1t4f flValueFromRaw_0_flaksyopx1(NU64 u_1, NI32 bits_2, TCode_0_valzr1t4f code_0){
  Value_0_valzr1t4f result_14;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
  Value_0_valzr1t4f X60Qx_129 = vNil_0_valzr1t4f();
  result_14 = X60Qx_129;
  switch (code_0){
    case 2:
    {
      if (bits_2 == 32){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
        NU32 X60Qx_130 = ((NU32)((NU64)(u_1 & ((NU64)4294967295u))));
        NF32 X60Qx_131;
        copyMem_0_sysvq0asl((&X60Qx_131), (&X60Qx_130), sizeof(NF32));
        Value_0_valzr1t4f X60Qx_132 = vFloat_0_valzr1t4f(((NF64)X60Qx_131), 32);
        result_14 = X60Qx_132;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
        NF64 X60Qx_133;
        copyMem_0_sysvq0asl((&X60Qx_133), (&u_1), sizeof(NF64));
        Value_0_valzr1t4f X60Qx_134 = vFloat_0_valzr1t4f(X60Qx_133, 64);
        result_14 = X60Qx_134;}}
    break;
    case 1:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
      Value_0_valzr1t4f X60Qx_135 = reinterpToInt_0_flaksyopx1(u_1, bits_2, NIM_TRUE);
      result_14 = X60Qx_135;}
    break;
    case 4:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
      Value_0_valzr1t4f X60Qx_136 = vBool_0_valzr1t4f((!(((NU64)(u_1 & ((NU64)255u))) == ((NU64)0u))));
      result_14 = X60Qx_136;}
    break;
    case 5:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
      Value_0_valzr1t4f X60Qx_137 = vChar_0_valzr1t4f(((NC8)((NU8)((NU64)(u_1 & ((NU64)255u))))));
      result_14 = X60Qx_137;}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
      Value_0_valzr1t4f X60Qx_138 = reinterpToInt_0_flaksyopx1(u_1, bits_2, NIM_FALSE);
      result_14 = X60Qx_138;}
    break;}
  return result_14;}
void flStoreRaw_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_6, NI32 off_4, NI32 bits_3, NU64 u_2){
  NI32 nb_1 = elemBytes_0_flaksyopx1(bits_3);
  NI32 i_14 = 0;
  {
    while (i_14 < nb_1){
      setByteAt_0_flaksyopx1(r_6, ((NI32)(off_4 + i_14)), ((NU8)((NU64)(((NU64)(u_2 >> ((NU32)(((NU32)i_14) * 8u)))) & ((NU64)255u)))));
      inc_1_I6wjjge_aow2h993l1((&i_14));}}
  whileStmtLabel_0: ;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* regionOverlayCell_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_9, NU32 fsym_0, NB8 create_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_15;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((&result_15));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(result_15);
  result_15 = NIM_NIL;
  if (r_9 == NIM_NIL){
    return result_15;}
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_3 = NIM_NIL;
  switch ((*r_9).d_00.kind_0){
    case 5:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_3);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_139 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((*r_9).d_00.obox_0);
      box_3 = X60Qx_139;}
    break;
    case 0:
    {
      if ((*r_9).d_00.objOverlay_0 == NIM_NIL){
        if ((!create_0)){
          eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_3);
          return result_15;}
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_5 = (&(*r_9).d_00.objOverlay_0);
        void* X60Qx_140 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_7 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_140);
        seq_0_In6doa_ast8ri79k X60Qx_141 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
        seq_0_Iw8xl5b1_flaksyopx1 X60Qx_142 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
        (*X60Qtmp_7) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
            .typeSym_0 = ((NU32)0u), .names_0 = X60Qx_141, .cells_0 = X60Qx_142}}
        ;
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_6 = X60Qtmp_7;
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_5));
        (*X60Qlhs_5) = X60Qlhs_6;}
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_3);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_143 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((*r_9).d_00.objOverlay_0);
      box_3 = X60Qx_143;}
    break;
    default:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_3);
      return result_15;}
    break;}
  if (box_3 == NIM_NIL){
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_3);
    return result_15;}
  NI32 i_15 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_144;
      NI32 X60Qx_145 = len_3_I6y2imo_buiyylk1h1((*box_3).d_00.names_0);
      if (i_15 < X60Qx_145){
        NI32 X60Qx_146 = len_3_I83dzei_flaksyopx1((*box_3).d_00.cells_0);
        X60Qx_144 = (i_15 < X60Qx_146);}
      else {
        X60Qx_144 = NIM_FALSE;}
      if (X60Qx_144){
        NU32* X60Qx_147 = getQ_7_I2v00yv1_buiyylk1h1((*box_3).d_00.names_0, i_15);
        NB8 X60Qx_148 = eqQ_0_nifh7u8pu1((*X60Qx_147), fsym_0);
        if (X60Qx_148){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_149 = getQ_7_Ii14ync1_flaksyopx1((*box_3).d_00.cells_0, i_15);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_150 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*X60Qx_149));
          result_15 = X60Qx_150;
          eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_3);
          return result_15;}
        inc_1_I6wjjge_aow2h993l1((&i_15));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if ((!create_0)){
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_3);
    return result_15;}
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(result_15);
  Value_0_valzr1t4f X60Qtmp_8 = vNil_0_valzr1t4f();
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_151 = newCell_0_valzr1t4f((&X60Qtmp_8));
  result_15 = X60Qx_151;
  add_0_I34il1q_comaa5xpt1((&(*box_3).d_00.names_0), fsym_0);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_152 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(result_15);
  add_0_Ijpw0mu_flaksyopx1((&(*box_3).d_00.cells_0), X60Qx_152);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_8));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_3);
  return result_15;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_8));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_3);
  return result_15;}
Value_0_valzr1t4f flLoadFieldAt_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_10, NI32 off_7, FieldOff_0_fiepkwzpc fo_0, NI32 depth_2){
  Value_0_valzr1t4f result_16;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
  if (fo_0.code_0 == 6){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_4 = regionOverlayCell_0_flaksyopx1(r_10, fo_0.sym_0, NIM_FALSE);
    Value_0_valzr1t4f X60Qx_10;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_10));
    if ((!(c_4 == NIM_NIL))){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_10));
      Value_0_valzr1t4f X60Qx_153 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_4).d_00.v_0));
      X60Qx_10 = X60Qx_153;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_10));
      Value_0_valzr1t4f X60Qx_154 = vNil_0_valzr1t4f();
      X60Qx_10 = X60Qx_154;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
    result_16 = X60Qx_10;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_10));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_10));
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_4);}
  else {
    if (fo_0.code_0 == 7){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      Value_0_valzr1t4f X60Qx_155 = flLoadObj_1_flaksyopx1(r_10, off_7, fo_0.tsym_0, ((NI32)(depth_2 + 1)));
      result_16 = X60Qx_155;}
    else {
      if (fo_0.code_0 == 4){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
        NU64 X60Qx_156 = flLoadRaw_0_flaksyopx1(r_10, off_7, 8);
        Value_0_valzr1t4f X60Qx_157 = vBool_0_valzr1t4f((!(X60Qx_156 == ((NU64)0u))));
        result_16 = X60Qx_157;}
      else {
        if (fo_0.code_0 == 5){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
          NU64 X60Qx_158 = flLoadRaw_0_flaksyopx1(r_10, off_7, 8);
          Value_0_valzr1t4f X60Qx_159 = vChar_0_valzr1t4f(((NC8)((NU8)((NU64)(X60Qx_158 & ((NU64)255u))))));
          result_16 = X60Qx_159;}
        else {
          NI32 X60Qx_11;
          if (0 < fo_0.size_0){
            X60Qx_11 = ((NI32)(fo_0.size_0 * 8));}
          else {
            X60Qx_11 = 8;}
          NI32 bits_7 = X60Qx_11;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
          NU64 X60Qx_160 = flLoadRaw_0_flaksyopx1(r_10, off_7, bits_7);
          Value_0_valzr1t4f X60Qx_161 = flValueFromRaw_0_flaksyopx1(X60Qx_160, bits_7, fo_0.code_0);
          result_16 = X60Qx_161;}}}}
  return result_16;}
Value_0_valzr1t4f flLoadObj_1_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_11, NI32 off_8, NU32 tsym_1, NI32 depth_3){
  Value_0_valzr1t4f result_17;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
  Value_0_valzr1t4f X60Qx_162 = vNil_0_valzr1t4f();
  result_17 = X60Qx_162;
  NB8 X60Qx_163;
  if (r_11 == NIM_NIL){
    X60Qx_163 = NIM_TRUE;}
  else {
    X60Qx_163 = (8 < depth_3);}
  if (X60Qx_163){
    return result_17;}
  seq_0_Id0odh1_fiepkwzpc fos_0 = fieldOffsetsOfType_0_fiepkwzpc(tsym_1);
  NI32 X60Qx_164 = len_3_If78p9o_fiepkwzpc(fos_0);
  if (X60Qx_164 == 0){
    eQdestroy_1_Ijysww_fiepkwzpc(fos_0);
    return result_17;}
  void* X60Qx_165 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_9 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_165);
  seq_0_In6doa_ast8ri79k X60Qx_166 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Iw8xl5b1_flaksyopx1 X60Qx_167 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
  (*X60Qtmp_9) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
      .typeSym_0 = tsym_1, .names_0 = X60Qx_166, .cells_0 = X60Qx_167}}
  ;
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_4 = X60Qtmp_9;
  {
    openArray_0_Ihovqtr1_fiepkwzpc X60Qlf_2 = toOpenArray_1_Ilfv4hf_fiepkwzpc(fos_0);
    NI32 X60Qlf_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_168 = len_6_Ikuawih_fiepkwzpc(X60Qlf_2);
        if (X60Qlf_3 < X60Qx_168){
          {
            FieldOff_0_fiepkwzpc* X60Qii_2 = getQ_10_Iu0e57f_fiepkwzpc(X60Qlf_2, X60Qlf_3);
            add_0_I34il1q_comaa5xpt1((&(*box_4).d_00.names_0), (*X60Qii_2).sym_0);
            Value_0_valzr1t4f X60Qtmp_10 = flLoadFieldAt_0_flaksyopx1(r_11, ((NI32)(off_8 + (*X60Qii_2).off_0)), (*X60Qii_2), depth_3);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_169 = newCell_0_valzr1t4f((&X60Qtmp_10));
            add_0_Ijpw0mu_flaksyopx1((&(*box_4).d_00.cells_0), X60Qx_169);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_10));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_11 = box_4;
  eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((&box_4));
  result_17 = (Value_0_valzr1t4f){
    .kind_0 = 11, .obj_0 = X60Qtmp_11}
  ;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_4);
  eQdestroy_1_Ijysww_fiepkwzpc(fos_0);
  return result_17;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_4);
  eQdestroy_1_Ijysww_fiepkwzpc(fos_0);
  return result_17;}
void flScatterObj_1_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_12, NI32 off_9, Value_0_valzr1t4f* v_3, NI32 depth_4){
  NB8 X60Qx_170;
  if (r_12 == NIM_NIL){
    X60Qx_170 = NIM_TRUE;}
  else {
    X60Qx_170 = (8 < depth_4);}
  if (X60Qx_170){
    return;}
  NB8 X60Qx_171;
  if ((!((*v_3).kind_0 == 11))){
    X60Qx_171 = (!((*v_3).kind_0 == 10));}
  else {
    X60Qx_171 = NIM_FALSE;}
  if (X60Qx_171){
    return;}
  if ((*v_3).obj_0 == NIM_NIL){
    return;}
  seq_0_Id0odh1_fiepkwzpc fos_1 = fieldOffsetsOfType_0_fiepkwzpc((*(*v_3).obj_0).d_00.typeSym_0);
  NI32 X60Qx_172 = len_3_If78p9o_fiepkwzpc(fos_1);
  if (X60Qx_172 == 0){
    eQdestroy_1_Ijysww_fiepkwzpc(fos_1);
    return;}
  NI32 i_17 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_173;
      NI32 X60Qx_174 = len_3_I6y2imo_buiyylk1h1((*(*v_3).obj_0).d_00.names_0);
      if (i_17 < X60Qx_174){
        NI32 X60Qx_175 = len_3_I83dzei_flaksyopx1((*(*v_3).obj_0).d_00.cells_0);
        X60Qx_173 = (i_17 < X60Qx_175);}
      else {
        X60Qx_173 = NIM_FALSE;}
      if (X60Qx_173){
        {
          openArray_0_Ihovqtr1_fiepkwzpc X60Qlf_4 = toOpenArray_1_Ilfv4hf_fiepkwzpc(fos_1);
          NI32 X60Qlf_5 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_176 = len_6_Ikuawih_fiepkwzpc(X60Qlf_4);
              if (X60Qlf_5 < X60Qx_176){
                {
                  FieldOff_0_fiepkwzpc* X60Qii_3 = getQ_10_Iu0e57f_fiepkwzpc(X60Qlf_4, X60Qlf_5);
                  NU32* X60Qx_177 = getQ_7_I2v00yv1_buiyylk1h1((*(*v_3).obj_0).d_00.names_0, i_17);
                  NB8 X60Qx_178 = eqQ_0_nifh7u8pu1((*X60Qii_3).sym_0, (*X60Qx_177));
                  if (X60Qx_178){
                    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_179 = getQ_7_Ii14ync1_flaksyopx1((*(*v_3).obj_0).d_00.cells_0, i_17);
                    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qii_4 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*X60Qx_179));
                    if ((!(X60Qii_4 == NIM_NIL))){
                      if ((*X60Qii_3).code_0 == 6){
                        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qii_5 = regionOverlayCell_0_flaksyopx1(r_12, (*X60Qii_3).sym_0, NIM_TRUE);
                        if ((!(X60Qii_5 == NIM_NIL))){
                          Value_0_valzr1t4f* X60Qlhs_12 = (&(*X60Qii_5).d_00.v_0);
                          Value_0_valzr1t4f X60Qlhs_13 = (*X60Qii_5).d_00.v_0;
                          Value_0_valzr1t4f X60Qx_180 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qii_4).d_00.v_0));
                          (*X60Qlhs_12) = X60Qx_180;
                          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_13));}
                        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qii_5);}
                      else {
                        if ((*X60Qii_3).code_0 == 7){
                          flScatterObj_1_flaksyopx1(r_12, ((NI32)(off_9 + (*X60Qii_3).off_0)), (&(*X60Qii_4).d_00.v_0), ((NI32)(depth_4 + 1)));}
                        else {
                          NI32 X60Qx_12;
                          if (0 < (*X60Qii_3).size_0){
                            X60Qx_12 = ((NI32)((*X60Qii_3).size_0 * 8));}
                          else {
                            X60Qx_12 = 8;}
                          NU64 X60Qx_181 = scalarToU64_0_flaksyopx1((&(*X60Qii_4).d_00.v_0));
                          flStoreRaw_0_flaksyopx1(r_12, ((NI32)(off_9 + (*X60Qii_3).off_0)), X60Qx_12, X60Qx_181);}}}
                    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qii_4);
                    goto forStmtLabel_1;
                    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qii_4);}}
                inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
              else {
                break;}}}
          whileStmtLabel_2: ;}
        forStmtLabel_1: ;
        inc_1_I6wjjge_aow2h993l1((&i_17));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Ijysww_fiepkwzpc(fos_1);}
NB8 flStoreOverlayObj_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_13, Value_0_valzr1t4f* v_4){
  NB8 result_18;
  result_18 = NIM_FALSE;
  if (r_13 == NIM_NIL){
    return result_18;}
  NB8 X60Qx_182;
  if ((!((*v_4).kind_0 == 11))){
    X60Qx_182 = (!((*v_4).kind_0 == 10));}
  else {
    X60Qx_182 = NIM_FALSE;}
  if (X60Qx_182){
    return result_18;}
  if ((*v_4).obj_0 == NIM_NIL){
    return result_18;}
  NB8 X60Qx_183;
  if ((!((*r_13).d_00.kind_0 == 0))){
    X60Qx_183 = (!((*r_13).d_00.kind_0 == 5));}
  else {
    X60Qx_183 = NIM_FALSE;}
  if (X60Qx_183){
    return result_18;}
  NI32 i_18 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_184;
      NI32 X60Qx_185 = len_3_I6y2imo_buiyylk1h1((*(*v_4).obj_0).d_00.names_0);
      if (i_18 < X60Qx_185){
        NI32 X60Qx_186 = len_3_I83dzei_flaksyopx1((*(*v_4).obj_0).d_00.cells_0);
        X60Qx_184 = (i_18 < X60Qx_186);}
      else {
        X60Qx_184 = NIM_FALSE;}
      if (X60Qx_184){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_187 = getQ_7_Ii14ync1_flaksyopx1((*(*v_4).obj_0).d_00.cells_0, i_18);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_6 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*X60Qx_187));
        if ((!(c_6 == NIM_NIL))){
          NU32* X60Qx_188 = getQ_7_I2v00yv1_buiyylk1h1((*(*v_4).obj_0).d_00.names_0, i_18);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* oc_1 = regionOverlayCell_0_flaksyopx1(r_13, (*X60Qx_188), NIM_TRUE);
          if ((!(oc_1 == NIM_NIL))){
            Value_0_valzr1t4f* X60Qlhs_14 = (&(*oc_1).d_00.v_0);
            Value_0_valzr1t4f X60Qlhs_15 = (*oc_1).d_00.v_0;
            Value_0_valzr1t4f X60Qx_189 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_6).d_00.v_0));
            (*X60Qlhs_14) = X60Qx_189;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_15));}
          eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(oc_1);}
        inc_1_I6wjjge_aow2h993l1((&i_18));
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_6);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_190;
  NB8 X60Qx_191;
  if ((*r_13).d_00.kind_0 == 0){
    X60Qx_191 = (!((*r_13).d_00.objOverlay_0 == NIM_NIL));}
  else {
    X60Qx_191 = NIM_FALSE;}
  if (X60Qx_191){
    NB8 X60Qx_192 = eqQ_0_nifh7u8pu1((*(*v_4).obj_0).d_00.typeSym_0, ((NU32)0u));
    X60Qx_190 = (!X60Qx_192);}
  else {
    X60Qx_190 = NIM_FALSE;}
  if (X60Qx_190){
    (*(*r_13).d_00.objOverlay_0).d_00.typeSym_0 = (*(*v_4).obj_0).d_00.typeSym_0;}
  result_18 = NIM_TRUE;
  return result_18;}
Value_0_valzr1t4f flOverlayValue_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_14){
  Value_0_valzr1t4f result_19;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_19));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_19));
  Value_0_valzr1t4f X60Qx_193 = vNil_0_valzr1t4f();
  result_19 = X60Qx_193;
  if (r_14 == NIM_NIL){
    return result_19;}
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_5 = NIM_NIL;
  switch ((*r_14).d_00.kind_0){
    case 5:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_5);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_194 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((*r_14).d_00.obox_0);
      box_5 = X60Qx_194;}
    break;
    case 0:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_5);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_195 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((*r_14).d_00.objOverlay_0);
      box_5 = X60Qx_195;}
    break;
    default:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_5);
      return result_19;}
    break;}
  NB8 X60Qx_196;
  if (box_5 == NIM_NIL){
    X60Qx_196 = NIM_TRUE;}
  else {
    NI32 X60Qx_197 = len_3_I83dzei_flaksyopx1((*box_5).d_00.cells_0);
    X60Qx_196 = (X60Qx_197 == 0);}
  if (X60Qx_196){
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_5);
    return result_19;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_19));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_16 = box_5;
  eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((&box_5));
  result_19 = (Value_0_valzr1t4f){
    .kind_0 = 11, .obj_0 = X60Qtmp_16}
  ;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_5);
  return result_19;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_5);
  return result_19;}
X60Qt_0_IAtupleAboolZAiS32ZAiS32ZSX54X43ode0valzr1t4fSX53ymX49d0nifh7u8pu1_flaksyopx1 flFieldSlot_0_flaksyopx1(Value_0_valzr1t4f* v_5, NU32 fsym_1){
  X60Qt_0_IAtupleAboolZAiS32ZAiS32ZSX54X43ode0valzr1t4fSX53ymX49d0nifh7u8pu1_flaksyopx1 result_20;
  result_20 = (X60Qt_0_IAtupleAboolZAiS32ZAiS32ZSX54X43ode0valzr1t4fSX53ymX49d0nifh7u8pu1_flaksyopx1){
    .fld_0 = NIM_FALSE, .fld_1 = 0, .fld_2 = 0, .fld_3 = 0, .fld_4 = ((NU32)0u)}
  ;
  NB8 X60Qx_198;
  NB8 X60Qx_199;
  if ((!((*v_5).kind_0 == 13))){
    X60Qx_199 = NIM_TRUE;}
  else {
    X60Qx_199 = ((*v_5).region_0 == NIM_NIL);}
  if (X60Qx_199){
    X60Qx_198 = NIM_TRUE;}
  else {
    X60Qx_198 = (!((*v_5).ecode_0 == 7));}
  if (X60Qx_198){
    return result_20;}
  {
    seq_0_Id0odh1_fiepkwzpc X60Qtmp_17 = fieldOffsetsOfType_0_fiepkwzpc((*v_5).etype_0);
    openArray_0_Ihovqtr1_fiepkwzpc X60Qlf_6 = toOpenArray_1_Ilfv4hf_fiepkwzpc(X60Qtmp_17);
    NI32 X60Qlf_7 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_200 = len_6_Ikuawih_fiepkwzpc(X60Qlf_6);
        if (X60Qlf_7 < X60Qx_200){
          {
            FieldOff_0_fiepkwzpc* X60Qii_2 = getQ_10_Iu0e57f_fiepkwzpc(X60Qlf_6, X60Qlf_7);
            NB8 X60Qx_201 = eqQ_0_nifh7u8pu1((*X60Qii_2).sym_0, fsym_1);
            if (X60Qx_201){
              if ((*X60Qii_2).code_0 == 6){
                eQdestroy_1_Ijysww_fiepkwzpc(X60Qtmp_17);
                return result_20;}
              NI32 X60Qx_13;
              if (0 < (*X60Qii_2).size_0){
                X60Qx_13 = ((NI32)((*X60Qii_2).size_0 * 8));}
              else {
                X60Qx_13 = 8;}
              result_20 = (X60Qt_0_IAtupleAboolZAiS32ZAiS32ZSX54X43ode0valzr1t4fSX53ymX49d0nifh7u8pu1_flaksyopx1){
                .fld_0 = NIM_TRUE, .fld_1 = ((NI32)(((NI32)(*v_5).foff_0) + (*X60Qii_2).off_0)), .fld_2 = X60Qx_13, .fld_3 = (*X60Qii_2).code_0, .fld_4 = (*X60Qii_2).tsym_0}
              ;
              eQdestroy_1_Ijysww_fiepkwzpc(X60Qtmp_17);
              return result_20;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
        else {
          break;}}}
    whileStmtLabel_1: ;
    eQdestroy_1_Ijysww_fiepkwzpc(X60Qtmp_17);}
  forStmtLabel_0: ;
  return result_20;}
X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1 flFieldPtr_0_flaksyopx1(Value_0_valzr1t4f* v_6, NU32 fsym_2){
  X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1 result_21;
  eQwasmovedQ_AtupleAboolZSX56alue0valzr1t4f_0_flaksyopx1((&result_21));
  X60Qt_0_IAtupleAboolZAiS32ZAiS32ZSX54X43ode0valzr1t4fSX53ymX49d0nifh7u8pu1_flaksyopx1 X60Qtmptup_0 = flFieldSlot_0_flaksyopx1((&(*v_6)), fsym_2);
  NB8 ok_0 = X60Qtmptup_0.fld_0;
  NI32 off_11 = X60Qtmptup_0.fld_1;
  NI32 bits_8 = X60Qtmptup_0.fld_2;
  TCode_0_valzr1t4f code_3 = X60Qtmptup_0.fld_3;
  NU32 tsym_3 = X60Qtmptup_0.fld_4;
  if ((!ok_0)){
    Value_0_valzr1t4f X60Qx_202 = vNil_0_valzr1t4f();
    result_21 = (X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1){
      .fld_0 = NIM_FALSE, .fld_1 = X60Qx_202}
    ;
    return result_21;}
  eQdestroyQ_AtupleAboolZSX56alue0valzr1t4f_0_flaksyopx1((&result_21));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_203 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*v_6).region_0);
  result_21 = (X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1){
    .fld_0 = NIM_TRUE, .fld_1 = (Value_0_valzr1t4f){
      .kind_0 = 13, .loc_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = X60Qx_203, .foff_0 = ((NI32)off_11), .elemBits_0 = ((NI16)bits_8), .ecode_0 = code_3, .etype_0 = tsym_3}}
  ;
  return result_21;}
void flScatter_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_15, NI32 off_10, NI32 bits_4, Value_0_valzr1t4f* v_7){
  NB8 X60Qx_206;
  if ((*v_7).kind_0 == 11){
    X60Qx_206 = NIM_TRUE;}
  else {
    X60Qx_206 = ((*v_7).kind_0 == 10);}
  if (X60Qx_206){
    flScatterObj_1_flaksyopx1(r_15, off_10, (&(*v_7)), 0);}
  else {
    NU64 X60Qx_207 = scalarToU64_0_flaksyopx1((&(*v_7)));
    flStoreRaw_0_flaksyopx1(r_15, off_10, bits_4, X60Qx_207);}}
Value_0_valzr1t4f flLoadAt_0_flaksyopx1(Value_0_valzr1t4f* v_8, NI32 i_0){
  Value_0_valzr1t4f result_23;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_23));
  NI32 eb_4 = elemBytes_0_flaksyopx1(((NI32)(*v_8).elemBits_0));
  if ((*v_8).ecode_0 == 7){
    Value_0_valzr1t4f X60Qx_208 = flLoadObj_1_flaksyopx1((*v_8).region_0, ((NI32)(((NI32)(*v_8).foff_0) + ((NI32)(i_0 * eb_4)))), (*v_8).etype_0, 0);
    result_23 = X60Qx_208;
    return result_23;}
  if (i_0 == 0){
    Value_0_valzr1t4f ov_0 = flOverlayValue_0_flaksyopx1((*v_8).region_0);
    if (ov_0.kind_0 == 11){
      Value_0_valzr1t4f X60Qtmp_19 = ov_0;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&ov_0));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ov_0));
      return X60Qtmp_19;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ov_0));}
  NU64 raw_1 = flLoadRaw_0_flaksyopx1((*v_8).region_0, ((NI32)(((NI32)(*v_8).foff_0) + ((NI32)(i_0 * eb_4)))), ((NI32)(*v_8).elemBits_0));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_23));
  Value_0_valzr1t4f X60Qx_209 = flValueFromRaw_0_flaksyopx1(raw_1, ((NI32)(*v_8).elemBits_0), (*v_8).ecode_0);
  result_23 = X60Qx_209;
  return result_23;}
Value_0_valzr1t4f flDeref_0_flaksyopx1(Value_0_valzr1t4f* v_9){
  Value_0_valzr1t4f result_24;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_24));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_24));
  Value_0_valzr1t4f X60Qx_210 = flLoadAt_0_flaksyopx1((&(*v_9)), 0);
  result_24 = X60Qx_210;
  return result_24;}
Value_0_valzr1t4f flIndexGet_0_flaksyopx1(Value_0_valzr1t4f* v_10, NI32 i_1){
  Value_0_valzr1t4f result_25;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_25));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_25));
  Value_0_valzr1t4f X60Qx_211 = flLoadAt_0_flaksyopx1((&(*v_10)), i_1);
  result_25 = X60Qx_211;
  return result_25;}
void flStoreAt_0_flaksyopx1(Value_0_valzr1t4f* v_11, NI32 i_2, Value_0_valzr1t4f* val_0){
  NI32 eb_5 = elemBytes_0_flaksyopx1(((NI32)(*v_11).elemBits_0));
  NB8 X60Qx_212;
  NB8 X60Qx_213;
  if (i_2 == 0){
    X60Qx_213 = (!((*v_11).ecode_0 == 7));}
  else {
    X60Qx_213 = NIM_FALSE;}
  if (X60Qx_213){
    NB8 X60Qx_214;
    if ((*val_0).kind_0 == 11){
      X60Qx_214 = NIM_TRUE;}
    else {
      X60Qx_214 = ((*val_0).kind_0 == 10);}
    X60Qx_212 = X60Qx_214;}
  else {
    X60Qx_212 = NIM_FALSE;}
  if (X60Qx_212){
    NB8 X60Qx_215 = flStoreOverlayObj_0_flaksyopx1((*v_11).region_0, (&(*val_0)));
    if (X60Qx_215){
      return;}}
  flScatter_0_flaksyopx1((*v_11).region_0, ((NI32)(((NI32)(*v_11).foff_0) + ((NI32)(i_2 * eb_5)))), ((NI32)(*v_11).elemBits_0), (&(*val_0)));}
void flStoreDeref_0_flaksyopx1(Value_0_valzr1t4f* v_12, Value_0_valzr1t4f* val_1){
  flStoreAt_0_flaksyopx1((&(*v_12)), 0, (&(*val_1)));}
NB8 needsView_0_flaksyopx1(NI32 boxBits_0, NI32 tbits_1, TCode_0_valzr1t4f boxCode_1, TCode_0_valzr1t4f tcode_1){
  NB8 result_27;
  NB8 X60Qx_218;
  if (tcode_1 == 7){
    X60Qx_218 = NIM_TRUE;}
  else {
    X60Qx_218 = (boxCode_1 == 7);}
  if (X60Qx_218){
    return NIM_TRUE;}
  if ((!(boxBits_0 == tbits_1))){
    return NIM_TRUE;}
  NB8 X60Qx_219;
  if (tcode_1 == 2){
    X60Qx_219 = NIM_TRUE;}
  else {
    X60Qx_219 = (boxCode_1 == 2);}
  if (X60Qx_219){
    result_27 = (!(tcode_1 == boxCode_1));
    return result_27;}
  NB8 X60Qx_220;
  if (tcode_1 == 1){
    X60Qx_220 = (!(boxCode_1 == 1));}
  else {
    X60Qx_220 = NIM_FALSE;}
  if (X60Qx_220){
    return NIM_TRUE;}
  result_27 = NIM_FALSE;
  return result_27;}
X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 arrElemInfo_0_flaksyopx1(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* box_0){
  X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 result_28;
  NB8 X60Qx_221;
  if ((!(box_0 == NIM_NIL))){
    X60Qx_221 = (0 < (*box_0).d_00.elems_0.len_0);}
  else {
    X60Qx_221 = NIM_FALSE;}
  if (X60Qx_221){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_222 = getQ_7_Ii14ync1_flaksyopx1((*box_0).d_00.elems_0, 0);
    Value_0_valzr1t4f v_22 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_222)).d_00.v_0));
    switch (v_22.kind_0){
      case 2:
      {
        NI32 X60Qx_223 = bitsOf_0_flaksyopx1((&v_22));
        result_28 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = X60Qx_223, .fld_1 = 0}
        ;}
      break;
      case 1:
      {
        NI32 X60Qx_224 = bitsOf_0_flaksyopx1((&v_22));
        result_28 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = X60Qx_224, .fld_1 = 1}
        ;}
      break;
      case 3:
      {
        NI32 X60Qx_225 = bitsOf_0_flaksyopx1((&v_22));
        result_28 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = X60Qx_225, .fld_1 = 2}
        ;}
      break;
      case 5:
      {
        result_28 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = 8, .fld_1 = 3}
        ;}
      break;
      case 4:
      {
        result_28 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = 8, .fld_1 = 3}
        ;}
      break;
      default:
      {
        result_28 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = 0, .fld_1 = 3}
        ;}
      break;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_22));}
  else {
    result_28 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
      .fld_0 = 0, .fld_1 = 3}
    ;}
  return result_28;}
X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 seqElemInfo_0_flaksyopx1(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* box_1){
  X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 result_29;
  NB8 X60Qx_226;
  if ((!(box_1 == NIM_NIL))){
    X60Qx_226 = (0 < (*box_1).d_00.elems_0.len_0);}
  else {
    X60Qx_226 = NIM_FALSE;}
  if (X60Qx_226){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_227 = getQ_7_Ii14ync1_flaksyopx1((*box_1).d_00.elems_0, 0);
    Value_0_valzr1t4f v_23 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_227)).d_00.v_0));
    switch (v_23.kind_0){
      case 2:
      {
        NI32 X60Qx_228 = bitsOf_0_flaksyopx1((&v_23));
        result_29 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = X60Qx_228, .fld_1 = 0}
        ;}
      break;
      case 1:
      {
        NI32 X60Qx_229 = bitsOf_0_flaksyopx1((&v_23));
        result_29 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = X60Qx_229, .fld_1 = 1}
        ;}
      break;
      case 3:
      {
        NI32 X60Qx_230 = bitsOf_0_flaksyopx1((&v_23));
        result_29 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = X60Qx_230, .fld_1 = 2}
        ;}
      break;
      case 5:
      {
        result_29 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = 8, .fld_1 = 3}
        ;}
      break;
      case 4:
      {
        result_29 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = 8, .fld_1 = 3}
        ;}
      break;
      default:
      {
        result_29 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = 0, .fld_1 = 3}
        ;}
      break;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_23));}
  else {
    result_29 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
      .fld_0 = 0, .fld_1 = 3}
    ;}
  return result_29;}
X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 cellElemInfo_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_3){
  X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 result_30;
  if ((!(c_3 == NIM_NIL))){
    Value_0_valzr1t4f v_24 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*c_3).d_00.v_0));
    switch (v_24.kind_0){
      case 2:
      {
        NI32 X60Qx_231 = bitsOf_0_flaksyopx1((&v_24));
        result_30 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = X60Qx_231, .fld_1 = 0}
        ;}
      break;
      case 1:
      {
        NI32 X60Qx_232 = bitsOf_0_flaksyopx1((&v_24));
        result_30 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = X60Qx_232, .fld_1 = 1}
        ;}
      break;
      case 3:
      {
        NI32 X60Qx_233 = bitsOf_0_flaksyopx1((&v_24));
        result_30 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = X60Qx_233, .fld_1 = 2}
        ;}
      break;
      case 5:
      {
        result_30 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = 8, .fld_1 = 3}
        ;}
      break;
      case 4:
      {
        result_30 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = 8, .fld_1 = 3}
        ;}
      break;
      default:
      {
        result_30 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
          .fld_0 = 0, .fld_1 = 3}
        ;}
      break;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_24));}
  else {
    result_30 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1){
      .fld_0 = 0, .fld_1 = 3}
    ;}
  return result_30;}
Value_0_valzr1t4f flCastPtr_0_flaksyopx1(Value_0_valzr1t4f* v_13, NI32 tbits_2, TCode_0_valzr1t4f tcode_2, NU32 etype_0){
  Value_0_valzr1t4f result_31;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_31));
  if ((!((*v_13).kind_0 == 13))){
    Value_0_valzr1t4f X60Qx_234 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_13)));
    return X60Qx_234;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_31));
  Value_0_valzr1t4f X60Qx_235 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_13)));
  result_31 = X60Qx_235;
  if ((!((*v_13).region_0 == NIM_NIL))){
    result_31.elemBits_0 = ((NI16)tbits_2);
    result_31.ecode_0 = tcode_2;
    NU32 X60Qx_15;
    if (tcode_2 == 7){
      X60Qx_15 = etype_0;}
    else {
      X60Qx_15 = ((NU32)0u);}
    result_31.etype_0 = X60Qx_15;
    return result_31;}
  if ((!((*v_13).arrOwn_0 == NIM_NIL))){
    X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 X60Qtmptup_1 = arrElemInfo_0_flaksyopx1((*v_13).arrOwn_0);
    NI32 boxBits_1 = X60Qtmptup_1.fld_0;
    TCode_0_valzr1t4f boxCode_2 = X60Qtmptup_1.fld_1;
    NB8 X60Qx_236;
    if (boxBits_1 == 0){
      X60Qx_236 = NIM_TRUE;}
    else {
      NB8 X60Qx_237 = needsView_0_flaksyopx1(boxBits_1, tbits_2, boxCode_2, tcode_2);
      X60Qx_236 = (!X60Qx_237);}
    if (X60Qx_236){
      return result_31;}
    if ((*(*v_13).arrOwn_0).d_00.flat_0 == NIM_NIL){
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_20 = (&(*(*v_13).arrOwn_0).d_00.flat_0);
      void* X60Qx_238 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_22 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_238);
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_239 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1((*v_13).arrOwn_0);
      (*X60Qtmp_22) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
          .kind_0 = 2, .abox_0 = X60Qx_239, .aEbits_0 = boxBits_1, .aEcode_0 = boxCode_2}}
      ;
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_21 = X60Qtmp_22;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_20));
      (*X60Qlhs_20) = X60Qlhs_21;}
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_23 = (&result_31.region_0);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_23));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_240 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*(*v_13).arrOwn_0).d_00.flat_0);
    (*X60Qlhs_23) = X60Qx_240;
    NI32 X60Qx_241 = elemBytes_0_flaksyopx1(boxBits_1);
    result_31.foff_0 = ((NI32)((NI32)((*v_13).base_0 * X60Qx_241)));
    result_31.elemBits_0 = ((NI16)tbits_2);
    result_31.ecode_0 = tcode_2;
    NU32 X60Qx_16;
    if (tcode_2 == 7){
      X60Qx_16 = etype_0;}
    else {
      X60Qx_16 = ((NU32)0u);}
    result_31.etype_0 = X60Qx_16;
    return result_31;}
  if ((!((*v_13).seqOwn_0 == NIM_NIL))){
    X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 X60Qtmptup_2 = seqElemInfo_0_flaksyopx1((*v_13).seqOwn_0);
    NI32 boxBits_2 = X60Qtmptup_2.fld_0;
    TCode_0_valzr1t4f boxCode_3 = X60Qtmptup_2.fld_1;
    NB8 X60Qx_242;
    if (boxBits_2 == 0){
      X60Qx_242 = NIM_TRUE;}
    else {
      NB8 X60Qx_243 = needsView_0_flaksyopx1(boxBits_2, tbits_2, boxCode_3, tcode_2);
      X60Qx_242 = (!X60Qx_243);}
    if (X60Qx_242){
      return result_31;}
    if ((*(*v_13).seqOwn_0).d_00.flat_0 == NIM_NIL){
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_24 = (&(*(*v_13).seqOwn_0).d_00.flat_0);
      void* X60Qx_244 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_26 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_244);
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_245 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1((*v_13).seqOwn_0);
      (*X60Qtmp_26) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
          .kind_0 = 1, .sbox_0 = X60Qx_245, .sEbits_0 = boxBits_2, .sEcode_0 = boxCode_3}}
      ;
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_25 = X60Qtmp_26;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_24));
      (*X60Qlhs_24) = X60Qlhs_25;}
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_27 = (&result_31.region_0);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_27));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_246 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*(*v_13).seqOwn_0).d_00.flat_0);
    (*X60Qlhs_27) = X60Qx_246;
    NI32 X60Qx_247 = elemBytes_0_flaksyopx1(boxBits_2);
    result_31.foff_0 = ((NI32)((NI32)((*v_13).base_0 * X60Qx_247)));
    result_31.elemBits_0 = ((NI16)tbits_2);
    result_31.ecode_0 = tcode_2;
    NU32 X60Qx_17;
    if (tcode_2 == 7){
      X60Qx_17 = etype_0;}
    else {
      X60Qx_17 = ((NU32)0u);}
    result_31.etype_0 = X60Qx_17;
    return result_31;}
  if ((!((*v_13).loc_0 == NIM_NIL))){
    X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 X60Qtmptup_3 = cellElemInfo_0_flaksyopx1((*v_13).loc_0);
    NI32 boxBits_3 = X60Qtmptup_3.fld_0;
    TCode_0_valzr1t4f boxCode_4 = X60Qtmptup_3.fld_1;
    NB8 X60Qx_248;
    if (boxBits_3 == 0){
      X60Qx_248 = NIM_TRUE;}
    else {
      NB8 X60Qx_249 = needsView_0_flaksyopx1(boxBits_3, tbits_2, boxCode_4, tcode_2);
      X60Qx_248 = (!X60Qx_249);}
    if (X60Qx_248){
      return result_31;}
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_28 = (&result_31.region_0);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_28));
    void* X60Qx_250 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_29 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_250);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_251 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*v_13).loc_0);
    (*X60Qtmp_29) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
      .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
        .kind_0 = 4, .ccell_0 = X60Qx_251}}
    ;
    (*X60Qlhs_28) = X60Qtmp_29;
    result_31.foff_0 = 0;
    result_31.elemBits_0 = ((NI16)tbits_2);
    result_31.ecode_0 = tcode_2;
    NU32 X60Qx_18;
    if (tcode_2 == 7){
      X60Qx_18 = etype_0;}
    else {
      X60Qx_18 = ((NU32)0u);}
    result_31.etype_0 = X60Qx_18;
    return result_31;}
  return result_31;}
Value_0_valzr1t4f flAddrOfIndex_0_flaksyopx1(Value_0_valzr1t4f* recv_0, NI32 i_3){
  Value_0_valzr1t4f result_32;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_32));
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0 = NIM_NIL;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0 = NIM_NIL;
  NI32 base_2 = 0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_7 = NIM_NIL;
  Value_0_valzr1t4f rv_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*recv_0)));
  NB8 X60Qx_252;
  if (rv_0.kind_0 == 13){
    X60Qx_252 = (!(rv_0.loc_0 == NIM_NIL));}
  else {
    X60Qx_252 = NIM_FALSE;}
  if (X60Qx_252){
    Value_0_valzr1t4f X60Qlhs_30 = rv_0;
    Value_0_valzr1t4f X60Qx_253 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*rv_0.loc_0).d_00.v_0));
    rv_0 = X60Qx_253;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_30));}
  else {
    NB8 X60Qx_254;
    if (rv_0.kind_0 == 12){
      X60Qx_254 = (!(rv_0.rf_0 == NIM_NIL));}
    else {
      X60Qx_254 = NIM_FALSE;}
    if (X60Qx_254){
      Value_0_valzr1t4f X60Qlhs_31 = rv_0;
      Value_0_valzr1t4f X60Qx_255 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*rv_0.rf_0).d_00.v_0));
      rv_0 = X60Qx_255;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_31));}}
  switch (rv_0.kind_0){
    case 9:
    {
      if ((!(rv_0.arr_0 == NIM_NIL))){
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(arrOwn_0);
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_256 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(rv_0.arr_0);
        arrOwn_0 = X60Qx_256;
        base_2 = ((NI32)(i_3 - (*rv_0.arr_0).d_00.lo_0));
        NB8 X60Qx_257;
        if (0 <= base_2){
          NI32 X60Qx_258 = len_3_I83dzei_flaksyopx1((*arrOwn_0).d_00.elems_0);
          X60Qx_257 = (base_2 < X60Qx_258);}
        else {
          X60Qx_257 = NIM_FALSE;}
        if (X60Qx_257){
          eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_7);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_259 = getQ_7_Ii14ync1_flaksyopx1((*arrOwn_0).d_00.elems_0, base_2);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_260 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*X60Qx_259));
          c_7 = X60Qx_260;}}}
    break;
    case 8:
    {
      if ((!(rv_0.sq_0 == NIM_NIL))){
        eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1(seqOwn_0);
        seqOwn_0 = rv_0.sq_0;
        eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1((&rv_0.sq_0));
        base_2 = i_3;
        NB8 X60Qx_261;
        if (0 <= base_2){
          NI32 X60Qx_262 = len_3_I83dzei_flaksyopx1((*seqOwn_0).d_00.elems_0);
          X60Qx_261 = (base_2 < X60Qx_262);}
        else {
          X60Qx_261 = NIM_FALSE;}
        if (X60Qx_261){
          eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_7);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_263 = getQ_7_Ii14ync1_flaksyopx1((*seqOwn_0).d_00.elems_0, base_2);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_264 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*X60Qx_263));
          c_7 = X60Qx_264;}}}
    break;
    default:
    {
      }
    break;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_32));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_32 = c_7;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((&c_7));
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_33 = arrOwn_0;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1((&arrOwn_0));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_34 = seqOwn_0;
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1((&seqOwn_0));
  result_32 = (Value_0_valzr1t4f){
    .kind_0 = 13, .loc_0 = X60Qtmp_32, .arrOwn_0 = X60Qtmp_33, .seqOwn_0 = X60Qtmp_34, .base_0 = base_2, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
  ;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_0));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_7);
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1(seqOwn_0);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(arrOwn_0);
  return result_32;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&rv_0));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_7);
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1(seqOwn_0);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(arrOwn_0);
  return result_32;}
NU64 regionSlotAddr_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_16){
  NU64 result_34;
  if (r_16 == NIM_NIL){
    return ((NU64)0u);}
  NI32 idx_1 = -1;
  {
    NI32 X60Qlf_10 = 0;
    NI32 X60Qlf_11 = len_3_Iau77c6_flaksyopx1(regionTable_0_flaksyopx1);
    NI32 X60Qlf_12 = X60Qlf_10;
    {
      while (X60Qlf_12 < X60Qlf_11){
        {
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qx_267 = getQ_7_I1p0jos_flaksyopx1(regionTable_0_flaksyopx1, X60Qlf_12);
          if ((*X60Qx_267) == r_16){
            idx_1 = X60Qlf_12;
            goto forStmtLabel_0;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_12));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  if (idx_1 < 0){
    NI32 X60Qx_268 = len_3_Iau77c6_flaksyopx1(regionTable_0_flaksyopx1);
    idx_1 = X60Qx_268;
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_269 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_16);
    add_0_I0t6c8o_flaksyopx1((&regionTable_0_flaksyopx1), X60Qx_269);}
  result_34 = ((NU64)(((NU64)(((NU64)idx_1) + ((NU64)1u))) * ((NU64)17179869184ull)));
  return result_34;}
NU64 regionAddr_0_flaksyopx1(Value_0_valzr1t4f* v_14){
  NU64 result_35;
  NB8 X60Qx_270;
  if ((!((*v_14).kind_0 == 13))){
    X60Qx_270 = NIM_TRUE;}
  else {
    X60Qx_270 = ((*v_14).region_0 == NIM_NIL);}
  if (X60Qx_270){
    return ((NU64)0u);}
  NU64 X60Qx_271 = regionSlotAddr_0_flaksyopx1((*v_14).region_0);
  result_35 = ((NU64)(X60Qx_271 + ((NU64)((NU32)(*v_14).foff_0))));
  return result_35;}
Value_0_valzr1t4f addrToRegionPtr_0_flaksyopx1(NU64 a_0, NI32 bits_5, TCode_0_valzr1t4f code_1, NU32 etype_1){
  Value_0_valzr1t4f result_36;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_36));
  NU64 slot_0 = ((NU64)(a_0 / ((NU64)17179869184ull)));
  NB8 X60Qx_272;
  if (slot_0 == ((NU64)0u)){
    X60Qx_272 = NIM_TRUE;}
  else {
    X60Qx_272 = (((NU64)regionTable_0_flaksyopx1.len_0) < slot_0);}
  if (X60Qx_272){
    result_36 = (Value_0_valzr1t4f){
      .kind_0 = 13, .loc_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
    ;
    return result_36;}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qx_273 = getQ_7_I1p0jos_flaksyopx1(regionTable_0_flaksyopx1, ((NI32)((NU64)(slot_0 - ((NU64)1u)))));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qx_273));
  NI32 off_12 = ((NI32)((NU64)(a_0 % ((NU64)17179869184ull))));
  NI32 X60Qx_19;
  if (0 < bits_5){
    X60Qx_19 = bits_5;}
  else {
    X60Qx_19 = 8;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_36));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_35 = region_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&region_0));
  result_36 = (Value_0_valzr1t4f){
    .kind_0 = 13, .loc_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = X60Qtmp_35, .foff_0 = ((NI32)off_12), .elemBits_0 = ((NI16)X60Qx_19), .ecode_0 = code_1, .etype_0 = etype_1}
  ;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(region_0);
  return result_36;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(region_0);
  return result_36;}
NI32 regionElemBytes_0_flaksyopx1(Value_0_valzr1t4f* v_15){
  NI32 result_37;
  NI64 X60Qx_20;
  if (((NI32)(*v_15).elemBits_0) <= 0){
    X60Qx_20 = 1;}
  else {
    X60Qx_20 = ((NI32)(((NI32)(*v_15).elemBits_0) / 8));}
  result_37 = X60Qx_20;
  return result_37;}
NU64 cellAddr_0_flaksyopx1(Value_0_valzr1t4f* v_16){
  NU64 result_38;
  NB8 X60Qx_274;
  if ((!((*v_16).kind_0 == 13))){
    X60Qx_274 = NIM_TRUE;}
  else {
    X60Qx_274 = ((*v_16).loc_0 == NIM_NIL);}
  if (X60Qx_274){
    return ((NU64)0u);}
  NI32 idx_2 = -1;
  {
    NI32 X60Qlf_13 = 0;
    NI32 X60Qlf_14 = len_3_I83dzei_flaksyopx1(cellTable_0_flaksyopx1);
    NI32 X60Qlf_15 = X60Qlf_13;
    {
      while (X60Qlf_15 < X60Qlf_14){
        {
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_275 = getQ_7_Ii14ync1_flaksyopx1(cellTable_0_flaksyopx1, X60Qlf_15);
          if ((*X60Qx_275) == (*v_16).loc_0){
            idx_2 = X60Qlf_15;
            goto forStmtLabel_0;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_15));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  if (idx_2 < 0){
    NI32 X60Qx_276 = len_3_I83dzei_flaksyopx1(cellTable_0_flaksyopx1);
    idx_2 = X60Qx_276;
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_277 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*v_16).loc_0);
    add_0_Ijpw0mu_flaksyopx1((&cellTable_0_flaksyopx1), X60Qx_277);}
  result_38 = ((NU64)(((NU64)1152921504606846976ull) + ((NU64)(((NU64)(((NU64)idx_2) + ((NU64)1u))) * ((NU64)1048576u)))));
  return result_38;}
static inline NB8 isCellAddr_0_flaksyopx1(NU64 a_1){
  NB8 result_39;
  result_39 = (((NU64)(((NU64)1152921504606846976ull) + ((NU64)1048576u))) <= a_1);
  return result_39;}
Value_0_valzr1t4f flAllocRegion_0_flaksyopx1(NI32 nbytes_0, NB8 zeroed_0){
  Value_0_valzr1t4f result_41;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_41));
  NI32 X60Qx_21;
  if (0 < nbytes_0){
    X60Qx_21 = nbytes_0;}
  else {
    X60Qx_21 = 0;}
  seq_0_Incv1wn_explnj22x1 bs_0 = newSeq_0_Ivbxvoi1_explnj22x1(X60Qx_21);
  void* X60Qx_282 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_36 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_282);
  seq_0_Incv1wn_explnj22x1 X60Qtmp_37 = bs_0;
  eQwasMoved_1_I861g1c1_explnj22x1((&bs_0));
  (*X60Qtmp_36) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
      .kind_0 = 0, .bytes_0 = X60Qtmp_37, .freed_0 = NIM_FALSE, .objOverlay_0 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
  ;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_18 = X60Qtmp_36;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_41));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_38 = r_18;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&r_18));
  result_41 = (Value_0_valzr1t4f){
    .kind_0 = 13, .loc_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = X60Qtmp_38, .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)8), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
  ;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_18);
  eQdestroy_1_Ijx6eoq_explnj22x1(bs_0);
  return result_41;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_18);
  eQdestroy_1_Ijx6eoq_explnj22x1(bs_0);
  return result_41;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* flOverlayBox_0_flaksyopx1(Value_0_valzr1t4f* v_17){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* result_42;
  eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((&result_42));
  NB8 X60Qx_283;
  if ((!((*v_17).kind_0 == 13))){
    X60Qx_283 = NIM_TRUE;}
  else {
    X60Qx_283 = ((*v_17).region_0 == NIM_NIL);}
  if (X60Qx_283){
    return NIM_NIL;}
  switch ((*(*v_17).region_0).d_00.kind_0){
    case 5:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(result_42);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_284 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((*(*v_17).region_0).d_00.obox_0);
      result_42 = X60Qx_284;}
    break;
    case 0:
    {
      if ((*(*v_17).region_0).d_00.objOverlay_0 == NIM_NIL){
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_39 = (&(*(*v_17).region_0).d_00.objOverlay_0);
        void* X60Qx_285 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_41 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_285);
        seq_0_In6doa_ast8ri79k X60Qx_286 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
        seq_0_Iw8xl5b1_flaksyopx1 X60Qx_287 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
        (*X60Qtmp_41) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
            .typeSym_0 = ((NU32)0u), .names_0 = X60Qx_286, .cells_0 = X60Qx_287}}
        ;
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_40 = X60Qtmp_41;
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_39));
        (*X60Qlhs_39) = X60Qlhs_40;}
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(result_42);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_288 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1((*(*v_17).region_0).d_00.objOverlay_0);
      result_42 = X60Qx_288;}
    break;
    default:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(result_42);
      result_42 = NIM_NIL;}
    break;}
  return result_42;}
void flFree_0_flaksyopx1(Value_0_valzr1t4f* v_18){
  NB8 X60Qx_289;
  NB8 X60Qx_290;
  if ((*v_18).kind_0 == 13){
    X60Qx_290 = (!((*v_18).region_0 == NIM_NIL));}
  else {
    X60Qx_290 = NIM_FALSE;}
  if (X60Qx_290){
    X60Qx_289 = ((*(*v_18).region_0).d_00.kind_0 == 0);}
  else {
    X60Qx_289 = NIM_FALSE;}
  if (X60Qx_289){
    (*(*v_18).region_0).d_00.freed_0 = NIM_TRUE;}}
Value_0_valzr1t4f flRealloc_0_flaksyopx1(Value_0_valzr1t4f* v_19, NI32 newBytes_0){
  Value_0_valzr1t4f result_43;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_43));
  NB8 X60Qx_291;
  NB8 X60Qx_292;
  if ((*v_19).kind_0 == 13){
    X60Qx_292 = (!((*v_19).region_0 == NIM_NIL));}
  else {
    X60Qx_292 = NIM_FALSE;}
  if (X60Qx_292){
    X60Qx_291 = ((*(*v_19).region_0).d_00.kind_0 == 0);}
  else {
    X60Qx_291 = NIM_FALSE;}
  if (X60Qx_291){
    NI32 X60Qx_22;
    if (0 < newBytes_0){
      X60Qx_22 = newBytes_0;}
    else {
      X60Qx_22 = 0;}
    NI32 n_4 = X60Qx_22;
    setLen_0_I9zf5sf1_flaksyopx1((&(*(*v_19).region_0).d_00.bytes_0), n_4);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_43));
    Value_0_valzr1t4f X60Qx_293 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_19)));
    result_43 = X60Qx_293;
    result_43.elemBits_0 = ((NI16)8);
    result_43.ecode_0 = 3;
    result_43.foff_0 = 0;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_43));
    Value_0_valzr1t4f X60Qx_294 = flAllocRegion_0_flaksyopx1(newBytes_0, NIM_TRUE);
    result_43 = X60Qx_294;}
  return result_43;}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flObjRegion_0_flaksyopx1(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_2){
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* result_44;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&result_44));
  if (box_2 == NIM_NIL){
    return NIM_NIL;}
  seq_0_Id0odh1_fiepkwzpc fos_2 = fieldOffsetsOfType_0_fiepkwzpc((*box_2).d_00.typeSym_0);
  NI32 X60Qx_295 = len_3_If78p9o_fiepkwzpc(fos_2);
  if (X60Qx_295 == 0){
    eQdestroy_1_Ijysww_fiepkwzpc(fos_2);
    return NIM_NIL;}
  NI32 X60Qx_296 = len_3_I83dzei_flaksyopx1((*box_2).d_00.cells_0);
  seq_0_Ift2sne_chu5m1rja1 offs_0 = newSeq_0_I7328u4_flaksyopx1(X60Qx_296);
  NI32 i_22 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_297;
      NI32 X60Qx_298 = len_3_I6y2imo_buiyylk1h1((*box_2).d_00.names_0);
      if (i_22 < X60Qx_298){
        NI32 X60Qx_299 = len_3_I83dzei_flaksyopx1((*box_2).d_00.cells_0);
        X60Qx_297 = (i_22 < X60Qx_299);}
      else {
        X60Qx_297 = NIM_FALSE;}
      if (X60Qx_297){
        NB8 found_0 = NIM_FALSE;
        {
          openArray_0_Ihovqtr1_fiepkwzpc X60Qlf_16 = toOpenArray_1_Ilfv4hf_fiepkwzpc(fos_2);
          NI32 X60Qlf_17 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_300 = len_6_Ikuawih_fiepkwzpc(X60Qlf_16);
              if (X60Qlf_17 < X60Qx_300){
                {
                  FieldOff_0_fiepkwzpc* X60Qii_3 = getQ_10_Iu0e57f_fiepkwzpc(X60Qlf_16, X60Qlf_17);
                  NU32* X60Qx_301 = getQ_7_I2v00yv1_buiyylk1h1((*box_2).d_00.names_0, i_22);
                  NB8 X60Qx_302 = eqQ_0_nifh7u8pu1((*X60Qii_3).sym_0, (*X60Qx_301));
                  if (X60Qx_302){
                    putQ_7_Ifvyck5_comaa5xpt1((&offs_0), i_22, (*X60Qii_3).off_0);
                    found_0 = NIM_TRUE;
                    goto forStmtLabel_1;}}
                inc_1_I6wjjge_aow2h993l1((&X60Qlf_17));}
              else {
                break;}}}
          whileStmtLabel_2: ;}
        forStmtLabel_1: ;
        if ((!found_0)){
          putQ_7_Ifvyck5_comaa5xpt1((&offs_0), i_22, -1);}
        inc_1_I6wjjge_aow2h993l1((&i_22));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(result_44);
  void* X60Qx_303 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_42 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_303);
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_36 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(box_2);
  seq_0_Ift2sne_chu5m1rja1 X60Qtmp_43 = offs_0;
  eQwasMoved_1_Ix88qzs1_chu5m1rja1((&offs_0));
  (*X60Qtmp_42) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
      .kind_0 = 5, .obox_0 = X60Qx_36, .offs_0 = X60Qtmp_43}}
  ;
  result_44 = X60Qtmp_42;
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(offs_0);
  eQdestroy_1_Ijysww_fiepkwzpc(fos_2);
  return result_44;
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(offs_0);
  eQdestroy_1_Ijysww_fiepkwzpc(fos_2);
  return result_44;}
NI32 lensByteSize_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_17){
  NI32 result_45;
  if (r_17 == NIM_NIL){
    return 0;}
  switch ((*r_17).d_00.kind_0){
    case 0:
    {
      NI32 X60Qx_304 = len_3_Izoe8zv_explnj22x1((*r_17).d_00.bytes_0);
      result_45 = X60Qx_304;}
    break;
    case 3:
    {
      NI32 X60Qx_23;
      NB8 X60Qx_305;
      if ((!((*r_17).d_00.scell_0 == NIM_NIL))){
        X60Qx_305 = ((*(*r_17).d_00.scell_0).d_00.v_0.kind_0 == 6);}
      else {
        X60Qx_305 = NIM_FALSE;}
      if (X60Qx_305){
        NI32 X60Qx_306 = len_4_sysvq0asl((*(*r_17).d_00.scell_0).d_00.v_0.sval_0);
        X60Qx_23 = X60Qx_306;}
      else {
        X60Qx_23 = 0;}
      result_45 = X60Qx_23;}
    break;
    case 4:
    {
      NI32 X60Qx_24;
      if ((!((*r_17).d_00.ccell_0 == NIM_NIL))){
        NI32 X60Qx_307 = bitsOf_0_flaksyopx1((&(*(*r_17).d_00.ccell_0).d_00.v_0));
        X60Qx_24 = ((NI32)(X60Qx_307 / 8));}
      else {
        X60Qx_24 = 0;}
      result_45 = X60Qx_24;}
    break;
    case 5:
    {
      NI32 m_1 = 0;
      {
        openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_18 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*r_17).d_00.offs_0);
        NI32 X60Qlf_19 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_308 = len_6_I9632ti1_comaa5xpt1(X60Qlf_18);
            if (X60Qlf_19 < X60Qx_308){
              {
                NI32* X60Qii_2 = getQ_10_I053icq_comaa5xpt1(X60Qlf_18, X60Qlf_19);
                NB8 X60Qx_309;
                if (0 <= (*X60Qii_2)){
                  X60Qx_309 = (m_1 < ((NI32)((*X60Qii_2) + 8)));}
                else {
                  X60Qx_309 = NIM_FALSE;}
                if (X60Qx_309){
                  m_1 = ((NI32)((*X60Qii_2) + 8));}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_19));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;
      result_45 = m_1;}
    break;
    case 2:
    {
      NI32 X60Qx_25;
      if ((!((*r_17).d_00.abox_0 == NIM_NIL))){
        NI32 X60Qx_310 = len_3_I83dzei_flaksyopx1((*(*r_17).d_00.abox_0).d_00.elems_0);
        NI32 X60Qx_311 = elemBytes_0_flaksyopx1((*r_17).d_00.aEbits_0);
        X60Qx_25 = ((NI32)(X60Qx_310 * X60Qx_311));}
      else {
        X60Qx_25 = 0;}
      result_45 = X60Qx_25;}
    break;
    case 1:
    {
      NI32 X60Qx_26;
      if ((!((*r_17).d_00.sbox_0 == NIM_NIL))){
        NI32 X60Qx_312 = len_3_I83dzei_flaksyopx1((*(*r_17).d_00.sbox_0).d_00.elems_0);
        NI32 X60Qx_313 = elemBytes_0_flaksyopx1((*r_17).d_00.sEbits_0);
        X60Qx_26 = ((NI32)(X60Qx_312 * X60Qx_313));}
      else {
        X60Qx_26 = 0;}
      result_45 = X60Qx_26;}
    break;
    case 6:
    {
      NI32 X60Qx_314 = foreignLen_0_flaksyopx1(r_17);
      result_45 = X60Qx_314;}
    break;}
  return result_45;}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* cellLensFor_0_flaksyopx1(NI32 idx_0){
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* result_46;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&result_46));
  NB8 X60Qx_315;
  if (idx_0 < 0){
    X60Qx_315 = NIM_TRUE;}
  else {
    X60Qx_315 = (cellTable_0_flaksyopx1.len_0 <= idx_0);}
  if (X60Qx_315){
    return NIM_NIL;}
  {
    while (NIM_TRUE){
      NI32 X60Qx_316 = len_3_Iau77c6_flaksyopx1(cellLensTable_0_flaksyopx1);
      NI32 X60Qx_317 = len_3_I83dzei_flaksyopx1(cellTable_0_flaksyopx1);
      if (X60Qx_316 < X60Qx_317){
        add_0_I0t6c8o_flaksyopx1((&cellLensTable_0_flaksyopx1), NIM_NIL);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_318 = getQ_7_Ii14ync1_flaksyopx1(cellTable_0_flaksyopx1, idx_0);
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_8 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*X60Qx_318));
  if (c_8 == NIM_NIL){
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_8);
    return NIM_NIL;}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qx_319 = getQ_7_I1p0jos_flaksyopx1(cellLensTable_0_flaksyopx1, idx_0);
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* cached_0 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qx_319));
  NB8 ok_1 = NIM_FALSE;
  if ((!(cached_0 == NIM_NIL))){
    switch ((*cached_0).d_00.kind_0){
      case 3:
      {
        NB8 X60Qx_320;
        if ((*c_8).d_00.v_0.kind_0 == 6){
          X60Qx_320 = ((*cached_0).d_00.scell_0 == c_8);}
        else {
          X60Qx_320 = NIM_FALSE;}
        ok_1 = X60Qx_320;}
      break;
      case 5:
      {
        NB8 X60Qx_321;
        NB8 X60Qx_322;
        if ((*c_8).d_00.v_0.kind_0 == 11){
          X60Qx_322 = NIM_TRUE;}
        else {
          X60Qx_322 = ((*c_8).d_00.v_0.kind_0 == 10);}
        if (X60Qx_322){
          X60Qx_321 = ((*cached_0).d_00.obox_0 == (*c_8).d_00.v_0.obj_0);}
        else {
          X60Qx_321 = NIM_FALSE;}
        ok_1 = X60Qx_321;}
      break;
      case 4:
      {
        NB8 X60Qx_323;
        NB8 X60Qx_324;
        if ((!((*c_8).d_00.v_0.kind_0 == 6))){
          X60Qx_324 = (!((*c_8).d_00.v_0.kind_0 == 11));}
        else {
          X60Qx_324 = NIM_FALSE;}
        if (X60Qx_324){
          X60Qx_323 = (!((*c_8).d_00.v_0.kind_0 == 10));}
        else {
          X60Qx_323 = NIM_FALSE;}
        ok_1 = X60Qx_323;}
      break;
      default:
      {
        ok_1 = NIM_FALSE;}
      break;}}
  if (ok_1){
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_44 = cached_0;
    eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&cached_0));
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(cached_0);
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_8);
    return X60Qtmp_44;}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_19 = NIM_NIL;
  if ((*c_8).d_00.v_0.kind_0 == 6){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_19);
    void* X60Qx_325 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_45 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_325);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_326 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_8);
    (*X60Qtmp_45) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
      .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
        .kind_0 = 3, .scell_0 = X60Qx_326}}
    ;
    r_19 = X60Qtmp_45;}
  else {
    NB8 X60Qx_327;
    NB8 X60Qx_328;
    if ((*c_8).d_00.v_0.kind_0 == 11){
      X60Qx_328 = NIM_TRUE;}
    else {
      X60Qx_328 = ((*c_8).d_00.v_0.kind_0 == 10);}
    if (X60Qx_328){
      X60Qx_327 = (!((*c_8).d_00.v_0.obj_0 == NIM_NIL));}
    else {
      X60Qx_327 = NIM_FALSE;}
    if (X60Qx_327){
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_19);
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_329 = flObjRegion_0_flaksyopx1((*c_8).d_00.v_0.obj_0);
      r_19 = X60Qx_329;}}
  if (r_19 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_19);
    void* X60Qx_330 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_46 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_330);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_47 = c_8;
    eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((&c_8));
    (*X60Qtmp_46) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
      .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
        .kind_0 = 4, .ccell_0 = X60Qtmp_47}}
    ;
    r_19 = X60Qtmp_46;}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_331 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_19);
  putQ_7_Iv6u0oa1_flaksyopx1((&cellLensTable_0_flaksyopx1), idx_0, X60Qx_331);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(result_46);
  result_46 = r_19;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&r_19));
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_19);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(cached_0);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_8);
  return result_46;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_19);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(cached_0);
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(c_8);
  return result_46;}
X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 addrToCellPtrAt_0_flaksyopx1(NU64 a_3, NI32 bits_6, TCode_0_valzr1t4f code_2, NU32 etype_2){
  X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1 result_47;
  eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_flaksyopx1((&result_47));
  NB8 X60Qx_332 = isCellAddr_0_flaksyopx1(a_3);
  if ((!X60Qx_332)){
    result_47 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
      .fld_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}
      , .fld_1 = NIM_FALSE}
    ;
    return result_47;}
  NU64 rel_1 = ((NU64)(a_3 - ((NU64)1152921504606846976ull)));
  NI32 idx_4 = ((NI32)(((NI32)((NU64)(rel_1 / ((NU64)1048576u)))) - 1));
  NI32 off_13 = ((NI32)((NU64)(rel_1 % ((NU64)1048576u))));
  NB8 X60Qx_333;
  if (idx_4 < 0){
    X60Qx_333 = NIM_TRUE;}
  else {
    X60Qx_333 = (cellTable_0_flaksyopx1.len_0 <= idx_4);}
  if (X60Qx_333){
    result_47 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
      .fld_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}
      , .fld_1 = NIM_FALSE}
    ;
    return result_47;}
  NB8 X60Qx_334;
  if (off_13 == 0){
    NB8 X60Qx_335;
    NB8 X60Qx_336;
    if (bits_6 <= 0){
      X60Qx_336 = NIM_TRUE;}
    else {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_337 = getQ_7_Ii14ync1_flaksyopx1(cellTable_0_flaksyopx1, idx_4);
      X60Qx_336 = ((*X60Qx_337) == NIM_NIL);}
    if (X60Qx_336){
      X60Qx_335 = NIM_TRUE;}
    else {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_338 = getQ_7_Ii14ync1_flaksyopx1(cellTable_0_flaksyopx1, idx_4);
      NI32 X60Qx_339 = bitsOf_0_flaksyopx1((&(*(*X60Qx_338)).d_00.v_0));
      X60Qx_335 = (bits_6 == X60Qx_339);}
    X60Qx_334 = X60Qx_335;}
  else {
    X60Qx_334 = NIM_FALSE;}
  if (X60Qx_334){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_340 = getQ_7_Ii14ync1_flaksyopx1(cellTable_0_flaksyopx1, idx_4);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_341 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*X60Qx_340));
    result_47 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
      .fld_0 = (Value_0_valzr1t4f){
        .kind_0 = 13, .loc_0 = X60Qx_341, .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}
      , .fld_1 = NIM_TRUE}
    ;
    return result_47;}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_20 = cellLensFor_0_flaksyopx1(idx_4);
  if (r_20 == NIM_NIL){
    result_47 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
      .fld_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}
      , .fld_1 = NIM_FALSE}
    ;
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_20);
    return result_47;}
  NI32 X60Qx_342 = lensByteSize_0_flaksyopx1(r_20);
  if (X60Qx_342 <= off_13){
    result_47 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
      .fld_0 = (Value_0_valzr1t4f){
        .kind_0 = 0}
      , .fld_1 = NIM_FALSE}
    ;
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_20);
    return result_47;}
  NI32 X60Qx_27;
  if (0 < bits_6){
    X60Qx_27 = bits_6;}
  else {
    X60Qx_27 = 8;}
  eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_flaksyopx1((&result_47));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_48 = r_20;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&r_20));
  result_47 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1){
    .fld_0 = (Value_0_valzr1t4f){
      .kind_0 = 13, .loc_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = X60Qtmp_48, .foff_0 = ((NI32)off_13), .elemBits_0 = ((NI16)X60Qx_27), .ecode_0 = code_2, .etype_0 = etype_2}
    , .fld_1 = NIM_TRUE}
  ;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_20);
  return result_47;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_20);
  return result_47;}
NB8 isMintedCellAddr_0_flaksyopx1(NU64 a_4){
  NB8 result_48;
  NB8 X60Qx_343 = isCellAddr_0_flaksyopx1(a_4);
  if ((!X60Qx_343)){
    return NIM_FALSE;}
  NI32 idx_5 = ((NI32)(((NI32)((NU64)(((NU64)(a_4 - ((NU64)1152921504606846976ull))) / ((NU64)1048576u)))) - 1));
  NB8 X60Qx_344;
  if (0 <= idx_5){
    NI32 X60Qx_345 = len_3_I83dzei_flaksyopx1(cellTable_0_flaksyopx1);
    X60Qx_344 = (idx_5 < X60Qx_345);}
  else {
    X60Qx_344 = NIM_FALSE;}
  result_48 = X60Qx_344;
  return result_48;}
string_0_sysvq0asl cellAddrProblem_0_flaksyopx1(NU64 a_5){
  string_0_sysvq0asl result_49;
  nimStrWasMoved((&result_49));
  NB8 X60Qx_346 = isCellAddr_0_flaksyopx1(a_5);
  if ((!X60Qx_346)){
    return (string_0_sysvq0asl){
      .bytes_0 = 1953459966u, .more_0 = (&strlit_0_I7981118950328739133_flaksyopx1)}
    ;}
  NU64 rel_2 = ((NU64)(a_5 - ((NU64)1152921504606846976ull)));
  NI32 idx_6 = ((NI32)(((NI32)((NU64)(rel_2 / ((NU64)1048576u)))) - 1));
  NI32 off_14 = ((NI32)((NU64)(rel_2 % ((NU64)1048576u))));
  NB8 X60Qx_347;
  if (idx_6 < 0){
    X60Qx_347 = NIM_TRUE;}
  else {
    X60Qx_347 = (cellTable_0_flaksyopx1.len_0 <= idx_6);}
  if (X60Qx_347){
    return (string_0_sysvq0asl){
      .bytes_0 = 1835955710u, .more_0 = (&strlit_0_I4206788977324198015_flaksyopx1)}
    ;}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_21 = cellLensFor_0_flaksyopx1(idx_6);
  if (r_21 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_21);
    return (string_0_sysvq0asl){
      .bytes_0 = 762277630u, .more_0 = (&strlit_0_I15879331316645165_flaksyopx1)}
    ;}
  string_0_sysvq0asl X60Qdesugar_0 = itoa_0_valzr1t4f(((NI64)off_14));
  NI32 X60Qx_348 = lensByteSize_0_flaksyopx1(r_21);
  string_0_sysvq0asl X60Qdesugar_1 = itoa_0_valzr1t4f(((NI64)X60Qx_348));
  NI32 X60Qx_349 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1818584062u, .more_0 = (&strlit_0_I5967086138208162463_flaksyopx1)}
  );
  NI32 X60Qx_350 = len_4_sysvq0asl(X60Qdesugar_0);
  NI32 X60Qx_351 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_352 = len_4_sysvq0asl(X60Qdesugar_1);
  string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_349 + X60Qx_350)) + X60Qx_351)) + X60Qx_352)));
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 1818584062u, .more_0 = (&strlit_0_I5967086138208162463_flaksyopx1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_0);
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 12033u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_1);
  nimStrDestroy(result_49);
  result_49 = X60Qdesugar_2;
  nimStrWasMoved((&X60Qdesugar_2));
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(X60Qdesugar_1);
  nimStrDestroy(X60Qdesugar_0);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_21);
  return result_49;
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(X60Qdesugar_1);
  nimStrDestroy(X60Qdesugar_0);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_21);
  return result_49;}
NU64 ptrToAddr_0_flaksyopx1(Value_0_valzr1t4f* v_20){
  NU64 result_50;
  if ((!((*v_20).kind_0 == 13))){
    return ((NU64)0u);}
  if ((!((*v_20).region_0 == NIM_NIL))){
    NU64 X60Qx_353 = regionAddr_0_flaksyopx1((&(*v_20)));
    result_50 = X60Qx_353;
    return result_50;}
  if ((!((*v_20).arrOwn_0 == NIM_NIL))){
    X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 X60Qtmptup_4 = arrElemInfo_0_flaksyopx1((*v_20).arrOwn_0);
    NI32 bb_0 = X60Qtmptup_4.fld_0;
    TCode_0_valzr1t4f bc_0 = X60Qtmptup_4.fld_1;
    if (0 < bb_0){
      if ((*(*v_20).arrOwn_0).d_00.flat_0 == NIM_NIL){
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_49 = (&(*(*v_20).arrOwn_0).d_00.flat_0);
        void* X60Qx_354 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_51 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_354);
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_355 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1((*v_20).arrOwn_0);
        (*X60Qtmp_51) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
            .kind_0 = 2, .abox_0 = X60Qx_355, .aEbits_0 = bb_0, .aEcode_0 = bc_0}}
        ;
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_50 = X60Qtmp_51;
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_49));
        (*X60Qlhs_49) = X60Qlhs_50;}
      NU64 X60Qx_356 = regionSlotAddr_0_flaksyopx1((*(*v_20).arrOwn_0).d_00.flat_0);
      NI32 X60Qx_357 = elemBytes_0_flaksyopx1(bb_0);
      result_50 = ((NU64)(X60Qx_356 + ((NU64)((NI32)((*v_20).base_0 * X60Qx_357)))));
      return result_50;}}
  if ((!((*v_20).seqOwn_0 == NIM_NIL))){
    X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 X60Qtmptup_5 = seqElemInfo_0_flaksyopx1((*v_20).seqOwn_0);
    NI32 bb_1 = X60Qtmptup_5.fld_0;
    TCode_0_valzr1t4f bc_1 = X60Qtmptup_5.fld_1;
    if (0 < bb_1){
      if ((*(*v_20).seqOwn_0).d_00.flat_0 == NIM_NIL){
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_52 = (&(*(*v_20).seqOwn_0).d_00.flat_0);
        void* X60Qx_358 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_54 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_358);
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_359 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1((*v_20).seqOwn_0);
        (*X60Qtmp_54) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
            .kind_0 = 1, .sbox_0 = X60Qx_359, .sEbits_0 = bb_1, .sEcode_0 = bc_1}}
        ;
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_53 = X60Qtmp_54;
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_52));
        (*X60Qlhs_52) = X60Qlhs_53;}
      NU64 X60Qx_360 = regionSlotAddr_0_flaksyopx1((*(*v_20).seqOwn_0).d_00.flat_0);
      NI32 X60Qx_361 = elemBytes_0_flaksyopx1(bb_1);
      result_50 = ((NU64)(X60Qx_360 + ((NU64)((NI32)((*v_20).base_0 * X60Qx_361)))));
      return result_50;}}
  NU64 X60Qx_362 = cellAddr_0_flaksyopx1((&(*v_20)));
  result_50 = X60Qx_362;
  return result_50;}
X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 lensOf_0_flaksyopx1(Value_0_valzr1t4f* v_21){
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 result_51;
  eQwasmovedQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1((&result_51));
  if ((!((*v_21).kind_0 == 13))){
    result_51 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
      .fld_0 = NIM_NIL, .fld_1 = 0}
    ;
    return result_51;}
  if ((!((*v_21).region_0 == NIM_NIL))){
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_363 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*v_21).region_0);
    result_51 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
      .fld_0 = X60Qx_363, .fld_1 = ((NI32)(*v_21).foff_0)}
    ;
    return result_51;}
  if ((!((*v_21).arrOwn_0 == NIM_NIL))){
    X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 X60Qtmptup_6 = arrElemInfo_0_flaksyopx1((*v_21).arrOwn_0);
    NI32 bb_2 = X60Qtmptup_6.fld_0;
    TCode_0_valzr1t4f bc_2 = X60Qtmptup_6.fld_1;
    if (0 < bb_2){
      if ((*(*v_21).arrOwn_0).d_00.flat_0 == NIM_NIL){
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_55 = (&(*(*v_21).arrOwn_0).d_00.flat_0);
        void* X60Qx_364 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_57 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_364);
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_365 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1((*v_21).arrOwn_0);
        (*X60Qtmp_57) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
            .kind_0 = 2, .abox_0 = X60Qx_365, .aEbits_0 = bb_2, .aEcode_0 = bc_2}}
        ;
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_56 = X60Qtmp_57;
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_55));
        (*X60Qlhs_55) = X60Qlhs_56;}
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_366 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*(*v_21).arrOwn_0).d_00.flat_0);
      NI32 X60Qx_367 = elemBytes_0_flaksyopx1(bb_2);
      result_51 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
        .fld_0 = X60Qx_366, .fld_1 = ((NI32)((*v_21).base_0 * X60Qx_367))}
      ;
      return result_51;}}
  if ((!((*v_21).seqOwn_0 == NIM_NIL))){
    X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4f_flaksyopx1 X60Qtmptup_7 = seqElemInfo_0_flaksyopx1((*v_21).seqOwn_0);
    NI32 bb_3 = X60Qtmptup_7.fld_0;
    TCode_0_valzr1t4f bc_3 = X60Qtmptup_7.fld_1;
    if (0 < bb_3){
      if ((*(*v_21).seqOwn_0).d_00.flat_0 == NIM_NIL){
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_58 = (&(*(*v_21).seqOwn_0).d_00.flat_0);
        void* X60Qx_368 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_60 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_368);
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_369 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1((*v_21).seqOwn_0);
        (*X60Qtmp_60) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
          .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
            .kind_0 = 1, .sbox_0 = X60Qx_369, .sEbits_0 = bb_3, .sEcode_0 = bc_3}}
        ;
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_59 = X60Qtmp_60;
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_58));
        (*X60Qlhs_58) = X60Qlhs_59;}
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_370 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*(*v_21).seqOwn_0).d_00.flat_0);
      NI32 X60Qx_371 = elemBytes_0_flaksyopx1(bb_3);
      result_51 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
        .fld_0 = X60Qx_370, .fld_1 = ((NI32)((*v_21).base_0 * X60Qx_371))}
      ;
      return result_51;}}
  if ((!((*v_21).loc_0 == NIM_NIL))){
    if ((*(*v_21).loc_0).d_00.v_0.kind_0 == 6){
      void* X60Qx_372 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_61 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_372);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_373 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*v_21).loc_0);
      (*X60Qtmp_61) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
          .kind_0 = 3, .scell_0 = X60Qx_373}}
      ;
      result_51 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
        .fld_0 = X60Qtmp_61, .fld_1 = 0}
      ;
      return result_51;}
    NB8 X60Qx_374;
    NB8 X60Qx_375;
    if ((*(*v_21).loc_0).d_00.v_0.kind_0 == 11){
      X60Qx_375 = NIM_TRUE;}
    else {
      X60Qx_375 = ((*(*v_21).loc_0).d_00.v_0.kind_0 == 10);}
    if (X60Qx_375){
      X60Qx_374 = (!((*(*v_21).loc_0).d_00.v_0.obj_0 == NIM_NIL));}
    else {
      X60Qx_374 = NIM_FALSE;}
    if (X60Qx_374){
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_22 = flObjRegion_0_flaksyopx1((*(*v_21).loc_0).d_00.v_0.obj_0);
      if ((!(r_22 == NIM_NIL))){
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_62 = r_22;
        eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&r_22));
        result_51 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
          .fld_0 = X60Qtmp_62, .fld_1 = 0}
        ;
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_22);
        return result_51;}
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(r_22);}
    void* X60Qx_376 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_63 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_376);
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_377 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1((*v_21).loc_0);
    (*X60Qtmp_63) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
      .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
        .kind_0 = 4, .ccell_0 = X60Qx_377}}
    ;
    result_51 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
      .fld_0 = X60Qtmp_63, .fld_1 = 0}
    ;
    return result_51;}
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(result_51);
  result_51 = (X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1){
    .fld_0 = NIM_NIL, .fld_1 = 0}
  ;
  return result_51;}
void flCopy_0_flaksyopx1(Value_0_valzr1t4f* dst_0, Value_0_valzr1t4f* src_0, NI32 n_0){
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_8 = lensOf_0_flaksyopx1((&(*dst_0)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dr_0 = X60Qtmptup_8.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&X60Qtmptup_8.fld_0));
  NI32 doff_0 = X60Qtmptup_8.fld_1;
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_9 = lensOf_0_flaksyopx1((&(*src_0)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* sr_0 = X60Qtmptup_9.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&X60Qtmptup_9.fld_0));
  NI32 soff_0 = X60Qtmptup_9.fld_1;
  NB8 X60Qx_378;
  if (dr_0 == NIM_NIL){
    X60Qx_378 = NIM_TRUE;}
  else {
    X60Qx_378 = (sr_0 == NIM_NIL);}
  if (X60Qx_378){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(sr_0);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_9);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(dr_0);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_8);
    return;}
  NI32 i_25 = 0;
  {
    while (i_25 < n_0){
      NU8 X60Qx_379 = byteAt_0_flaksyopx1(sr_0, ((NI32)(soff_0 + i_25)));
      setByteAt_0_flaksyopx1(dr_0, ((NI32)(doff_0 + i_25)), X60Qx_379);
      inc_1_I6wjjge_aow2h993l1((&i_25));}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(sr_0);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_9);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(dr_0);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_8);}
void flMove_0_flaksyopx1(Value_0_valzr1t4f* dst_1, Value_0_valzr1t4f* src_1, NI32 n_1){
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_10 = lensOf_0_flaksyopx1((&(*dst_1)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dr_1 = X60Qtmptup_10.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&X60Qtmptup_10.fld_0));
  NI32 doff_1 = X60Qtmptup_10.fld_1;
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_11 = lensOf_0_flaksyopx1((&(*src_1)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* sr_1 = X60Qtmptup_11.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&X60Qtmptup_11.fld_0));
  NI32 soff_1 = X60Qtmptup_11.fld_1;
  NB8 X60Qx_380;
  if (dr_1 == NIM_NIL){
    X60Qx_380 = NIM_TRUE;}
  else {
    X60Qx_380 = (sr_1 == NIM_NIL);}
  if (X60Qx_380){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(sr_1);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_11);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(dr_1);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_10);
    return;}
  NI32 X60Qx_28;
  if (0 < n_1){
    X60Qx_28 = n_1;}
  else {
    X60Qx_28 = 0;}
  seq_0_Incv1wn_explnj22x1 tmp_0 = newSeq_0_Ivbxvoi1_explnj22x1(X60Qx_28);
  NI32 i_26 = 0;
  {
    while (i_26 < n_1){
      NU8 X60Qx_381 = byteAt_0_flaksyopx1(sr_1, ((NI32)(soff_1 + i_26)));
      putQ_7_Ipw0nqk1_explnj22x1((&tmp_0), i_26, X60Qx_381);
      inc_1_I6wjjge_aow2h993l1((&i_26));}}
  whileStmtLabel_0: ;
  i_26 = 0;
  {
    while (i_26 < n_1){
      NU8* X60Qx_382 = getQ_7_Ig0r1051_explnj22x1(tmp_0, i_26);
      setByteAt_0_flaksyopx1(dr_1, ((NI32)(doff_1 + i_26)), (*X60Qx_382));
      inc_1_I6wjjge_aow2h993l1((&i_26));}}
  whileStmtLabel_1: ;
  eQdestroy_1_Ijx6eoq_explnj22x1(tmp_0);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(sr_1);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_11);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(dr_1);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_10);}
void flZero_0_flaksyopx1(Value_0_valzr1t4f* dst_2, NI32 n_2){
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_12 = lensOf_0_flaksyopx1((&(*dst_2)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dr_2 = X60Qtmptup_12.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&X60Qtmptup_12.fld_0));
  NI32 doff_2 = X60Qtmptup_12.fld_1;
  if (dr_2 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(dr_2);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_12);
    return;}
  NI32 i_27 = 0;
  {
    while (i_27 < n_2){
      setByteAt_0_flaksyopx1(dr_2, ((NI32)(doff_2 + i_27)), ((NU8)0u));
      inc_1_I6wjjge_aow2h993l1((&i_27));}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(dr_2);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_12);}
NB8 flEqual_0_flaksyopx1(Value_0_valzr1t4f* a_6, Value_0_valzr1t4f* b_2, NI32 n_3){
  NB8 result_52;
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_13 = lensOf_0_flaksyopx1((&(*a_6)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* ar_0 = X60Qtmptup_13.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&X60Qtmptup_13.fld_0));
  NI32 aoff_0 = X60Qtmptup_13.fld_1;
  X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 X60Qtmptup_14 = lensOf_0_flaksyopx1((&(*b_2)));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* br_0 = X60Qtmptup_14.fld_0;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&X60Qtmptup_14.fld_0));
  NI32 boff_0 = X60Qtmptup_14.fld_1;
  NB8 X60Qx_383;
  if (ar_0 == NIM_NIL){
    X60Qx_383 = NIM_TRUE;}
  else {
    X60Qx_383 = (br_0 == NIM_NIL);}
  if (X60Qx_383){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(br_0);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_14);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(ar_0);
    eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_13);
    return NIM_FALSE;}
  NI32 i_28 = 0;
  {
    while (i_28 < n_3){
      NU8 X60Qx_384 = byteAt_0_flaksyopx1(ar_0, ((NI32)(aoff_0 + i_28)));
      NU8 X60Qx_385 = byteAt_0_flaksyopx1(br_0, ((NI32)(boff_0 + i_28)));
      if ((!(X60Qx_384 == X60Qx_385))){
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(br_0);
        eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_14);
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(ar_0);
        eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_13);
        return NIM_FALSE;}
      inc_1_I6wjjge_aow2h993l1((&i_28));}}
  whileStmtLabel_0: ;
  result_52 = NIM_TRUE;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(br_0);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_14);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(ar_0);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_13);
  return result_52;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(br_0);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_14);
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(ar_0);
  eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qtmptup_13);
  return result_52;}
static inline openArray_0_Ig73pnk_comaa5xpt1 toOpenArray_0_I1pr4a81_flaksyopx1(X60Qt_0_IAarraySstring0sysvq0aslS8_flaksyopx1* x_2){
  openArray_0_Ig73pnk_comaa5xpt1 result_53;
  openArray_0_Ig73pnk_comaa5xpt1 X60Qx_29;
  if (((NI32)(((NI32)(((NI32)((NI32)7)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_29 = (openArray_0_Ig73pnk_comaa5xpt1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_29 = (openArray_0_Ig73pnk_comaa5xpt1){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_2))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)7)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_53 = X60Qx_29;
  return result_53;}
static inline NI32 len_3_I83dzei_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_23){
  NI32 result_56;
  result_56 = s_23.len_0;
  return result_56;}
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_24, NI32 i_31){
  NB8 X60Qx_387;
  if (i_31 < s_24.len_0){
    X60Qx_387 = (0 <= i_31);}
  else {
    X60Qx_387 = NIM_FALSE;}
  if ((!X60Qx_387)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** result_57;
  result_57 = (&s_24.data_0[i_31]);
  return result_57;}
static inline seq_0_Iw8xl5b1_flaksyopx1 newSeqUninit_0_I1tbjnk1_flaksyopx1(NI32 size_7){
  seq_0_Iw8xl5b1_flaksyopx1 result_61;
  if (size_7 == 0){
    result_61 = (seq_0_Iw8xl5b1_flaksyopx1){
      .len_0 = size_7, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Ixcobep_flaksyopx1(size_7);
    void* X60Qx_392 = alloc_1_sysvq0asl(memSize_1);
    result_61 = (seq_0_Iw8xl5b1_flaksyopx1){
      .len_0 = size_7, .data_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1**)X60Qx_392)}
    ;
    if ((!(result_61.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_393 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_61.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_61;}
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8){
  NI32 L_1 = (*s_32).len_0;
  NI32 X60Qx_397 = capInBytes_0_Iih34tr1_flaksyopx1((*s_32));
  if (X60Qx_397 < ((NI32)(((NI32)(L_1 * sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*))) + sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)))){
    NB8 X60Qx_398 = resize_0_If3pogj_flaksyopx1(s_32, 1);
    if ((!X60Qx_398)){
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(elem_8);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_32).len_0));
  (*s_32).data_0[L_1] = elem_8;}
static inline seq_0_Il6bofj1_flaksyopx1 newSeqUninit_0_In1z2du1_flaksyopx1(NI32 size_9){
  seq_0_Il6bofj1_flaksyopx1 result_66;
  if (size_9 == 0){
    result_66 = (seq_0_Il6bofj1_flaksyopx1){
      .len_0 = size_9, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_I6mjfpb1_flaksyopx1(size_9);
    void* X60Qx_400 = alloc_1_sysvq0asl(memSize_2);
    result_66 = (seq_0_Il6bofj1_flaksyopx1){
      .len_0 = size_9, .data_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1**)X60Qx_400)}
    ;
    if ((!(result_66.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_401 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_66.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_66;}
static inline NI32 len_3_Iau77c6_flaksyopx1(seq_0_Il6bofj1_flaksyopx1 s_37){
  NI32 result_67;
  result_67 = s_37.len_0;
  return result_67;}
static inline X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** getQ_7_I1p0jos_flaksyopx1(seq_0_Il6bofj1_flaksyopx1 s_38, NI32 i_37){
  NB8 X60Qx_402;
  if (i_37 < s_38.len_0){
    X60Qx_402 = (0 <= i_37);}
  else {
    X60Qx_402 = NIM_FALSE;}
  if ((!X60Qx_402)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** result_68;
  result_68 = (&s_38.data_0[i_37]);
  return result_68;}
static inline void add_0_I0t6c8o_flaksyopx1(seq_0_Il6bofj1_flaksyopx1* s_39, X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* elem_9){
  NI32 L_2 = (*s_39).len_0;
  NI32 X60Qx_403 = capInBytes_0_Ixu29jk_flaksyopx1((*s_39));
  if (X60Qx_403 < ((NI32)(((NI32)(L_2 * sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*))) + sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)))){
    NB8 X60Qx_404 = resize_0_Is4jxz_flaksyopx1(s_39, 1);
    if ((!X60Qx_404)){
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(elem_9);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_39).len_0));
  (*s_39).data_0[L_2] = elem_9;}
void setLen_0_I9zf5sf1_flaksyopx1(seq_0_Incv1wn_explnj22x1* s_41, NI32 newLen_1){
  if (newLen_1 < (*s_41).len_0){
    shrink_0_I7bszm81_flaksyopx1(s_41, newLen_1);}
  else {
    NI32 i_39 = (*s_41).len_0;
    growUnsafe_0_I4f7zfx1_flaksyopx1(s_41, newLen_1);
    if ((*s_41).data_0 == NIM_NIL){
      return;}
    {
      while (i_39 < newLen_1){
        (*s_41).data_0[i_39] = ((NU8)0u);
        inc_1_I6wjjge_aow2h993l1((&i_39));}}
    whileStmtLabel_0: ;}}
seq_0_Ift2sne_chu5m1rja1 newSeq_0_I7328u4_flaksyopx1(NI32 size_13){
  seq_0_Ift2sne_chu5m1rja1 result_70;
  if (size_13 == 0){
    result_70 = (seq_0_Ift2sne_chu5m1rja1){
      .len_0 = size_13, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_4 = memSizeInBytes_0_Inv7kg3_chu5m1rja1(size_13);
    void* X60Qx_406 = alloc_1_sysvq0asl(memSize_4);
    result_70 = (seq_0_Ift2sne_chu5m1rja1){
      .len_0 = size_13, .data_0 = ((NI32*)X60Qx_406)}
    ;
    if ((!(result_70.data_0 == NIM_NIL))){
      NI32 i_40 = 0;
      {
        while (i_40 < size_13){
          result_70.data_0[i_40] = ((NI32)0);
          inc_1_I6wjjge_aow2h993l1((&i_40));}}
      whileStmtLabel_0: ;}
    else {
      result_70.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_4);}}
  return result_70;}
static inline void putQ_7_Iv6u0oa1_flaksyopx1(seq_0_Il6bofj1_flaksyopx1* s_47, NI32 i_43, X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* elem_11){
  NB8 X60Qx_409;
  if (i_43 < (*s_47).len_0){
    X60Qx_409 = (0 <= i_43);}
  else {
    X60Qx_409 = NIM_FALSE;}
  if ((!X60Qx_409)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** X60Qlhs_64 = (&(*s_47).data_0[i_43]);
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qlhs_65 = elem_11;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&elem_11));
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((*X60Qlhs_64));
  (*X60Qlhs_64) = X60Qlhs_65;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(elem_11);}
static inline NI32 memSizeInBytes_0_Ixcobep_flaksyopx1(NI32 size_16){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_75;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_16, sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_75 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_75 = ((NI32)2147483647);}
  return result_75;}
static inline NI32 capInBytes_0_Iih34tr1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_49){
  NI32 result_78;
  NI32 X60Qx_31;
  if ((!(s_49.data_0 == NIM_NIL))){
    NI32 X60Qx_414 = allocatedSize_0_sysvq0asl(((void*)((void*)s_49.data_0)));
    X60Qx_31 = X60Qx_414;}
  else {
    X60Qx_31 = 0;}
  result_78 = X60Qx_31;
  return result_78;}
NB8 resize_0_If3pogj_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* dest_4, NI32 addedElements_4){
  NB8 result_79;
  NI32 X60Qx_415 = capInBytes_0_Iih34tr1_flaksyopx1((*dest_4));
  NI32 oldCap_1 = ((NI32)(X60Qx_415 / sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_4);
  NI32 memSize_6 = memSizeInBytes_0_Ixcobep_flaksyopx1(newCap_1);
  void* X60Qx_416 = realloc_1_sysvq0asl(((void*)((void*)(*dest_4).data_0)), memSize_6);
  (*dest_4).data_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1**)X60Qx_416);
  if ((*dest_4).data_0 == NIM_NIL){
    (*dest_4).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_6);
    result_79 = NIM_FALSE;}
  else {
    result_79 = NIM_TRUE;}
  return result_79;}
static inline NI32 memSizeInBytes_0_I6mjfpb1_flaksyopx1(NI32 size_17){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_83;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_17, sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_83 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_83 = ((NI32)2147483647);}
  return result_83;}
static inline NI32 capInBytes_0_Ixu29jk_flaksyopx1(seq_0_Il6bofj1_flaksyopx1 s_51){
  NI32 result_84;
  NI32 X60Qx_32;
  if ((!(s_51.data_0 == NIM_NIL))){
    NI32 X60Qx_418 = allocatedSize_0_sysvq0asl(((void*)((void*)s_51.data_0)));
    X60Qx_32 = X60Qx_418;}
  else {
    X60Qx_32 = 0;}
  result_84 = X60Qx_32;
  return result_84;}
NB8 resize_0_Is4jxz_flaksyopx1(seq_0_Il6bofj1_flaksyopx1* dest_5, NI32 addedElements_5){
  NB8 result_85;
  NI32 X60Qx_419 = capInBytes_0_Ixu29jk_flaksyopx1((*dest_5));
  NI32 oldCap_2 = ((NI32)(X60Qx_419 / sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_5);
  NI32 memSize_7 = memSizeInBytes_0_I6mjfpb1_flaksyopx1(newCap_2);
  void* X60Qx_420 = realloc_1_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_7);
  (*dest_5).data_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1**)X60Qx_420);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_7);
    result_85 = NIM_FALSE;}
  else {
    result_85 = NIM_TRUE;}
  return result_85;}
void shrink_0_I7bszm81_flaksyopx1(seq_0_Incv1wn_explnj22x1* s_52, NI32 newLen_4){
  NI32 i_44 = ((NI32)((*s_52).len_0 - 1));
  {
    while (newLen_4 <= i_44){
      dec_1_I0nzoz91_ast8ri79k((&i_44));}}
  whileStmtLabel_0: ;
  (*s_52).len_0 = newLen_4;}
void growUnsafe_0_I4f7zfx1_flaksyopx1(seq_0_Incv1wn_explnj22x1* s_53, NI32 newLen_5){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_5, sizeof(NU8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_0 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_421 = capInBytes_0_Iffahgv_explnj22x1((*s_53));
  if (X60Qx_421 < newSize_0){
    NB8 X60Qx_422 = resize_0_Iuiuhg71_flaksyopx1(s_53, ((NI32)(newLen_5 - (*s_53).len_0)));
    if ((!X60Qx_422)){
      return;}}
  (*s_53).len_0 = newLen_5;}
NB8 resize_0_Iuiuhg71_flaksyopx1(seq_0_Incv1wn_explnj22x1* dest_7, NI32 addedElements_7){
  NB8 result_92;
  NI32 X60Qx_425 = capInBytes_0_Iffahgv_explnj22x1((*dest_7));
  NI32 oldCap_3 = ((NI32)(X60Qx_425 / sizeof(NU8)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_7);
  NI32 memSize_8 = memSizeInBytes_0_Infw7m1_explnj22x1(newCap_3);
  void* X60Qx_426 = realloc_1_sysvq0asl(((void*)((void*)(*dest_7).data_0)), memSize_8);
  (*dest_7).data_0 = ((NU8*)X60Qx_426);
  if ((*dest_7).data_0 == NIM_NIL){
    (*dest_7).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_8);
    result_92 = NIM_FALSE;}
  else {
    result_92 = NIM_TRUE;}
  return result_92;}
void eQdestroy_1_I8k3d0z1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 s_71){
  if ((!(s_71.data_0 == NIM_NIL))){
    NI32 i_49 = 0;
    {
      while (i_49 < s_71.len_0){
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(s_71.data_0[i_49]);
        inc_1_I6wjjge_aow2h993l1((&i_49));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_71.data_0)));}}
static inline void eQwasMoved_1_I4kgdoh1_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1* s_72){
  (*s_72).len_0 = 0;
  (*s_72).data_0 = NIM_NIL;}
seq_0_Iw8xl5b1_flaksyopx1 eQdup_1_Io30l171_flaksyopx1(seq_0_Iw8xl5b1_flaksyopx1 a_28){
  seq_0_Iw8xl5b1_flaksyopx1 result_94;
  seq_0_Iw8xl5b1_flaksyopx1 X60Qx_431 = newSeqUninit_0_I1tbjnk1_flaksyopx1(a_28.len_0);
  result_94 = X60Qx_431;
  NI32 i_50 = 0;
  {
    while (i_50 < a_28.len_0){
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_432 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(a_28.data_0[i_50]);
      result_94.data_0[i_50] = X60Qx_432;
      inc_1_I6wjjge_aow2h993l1((&i_50));}}
  whileStmtLabel_0: ;
  return result_94;}
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_463 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_463){
      eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_464 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_464){
      eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_AtupleAboolZSX56alue0valzr1t4f_0_flaksyopx1(X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1* dest_0){
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_1));}
void eQdestroyQ_AtupleAboolZSX56alue0valzr1t4f_0_flaksyopx1(X60Qt_0_IAtupleAboolZSX56alue0valzr1t4f_flaksyopx1* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_1));}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_465 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_465){
      eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_466 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_466){
      eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_467 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_467){
      eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_flaksyopx1(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1* dest_0){
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_flaksyopx1(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_flaksyopx1* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_0));}
void eQwasmovedQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1* dest_0){
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_0_flaksyopx1(X60Qt_0_IAtupleArefSX46latX52egionX4fbj0valzr1t4fZAiS32_flaksyopx1 dest_0){
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_flaksyopx1(dest_0.fld_0);}
void X60Qini_0_flaksyopx1(void){
  if (X60QiniGuard_0_flaksyopx1){
    return;}
  X60QiniGuard_0_flaksyopx1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_valzr1t4f();
  X60Qini_0_fiepkwzpc();
  regionTable_0_flaksyopx1 = newSeqUninit_0_In1z2du1_flaksyopx1(0);
  cellTable_0_flaksyopx1 = newSeqUninit_0_I1tbjnk1_flaksyopx1(0);
  cellLensTable_0_flaksyopx1 = newSeqUninit_0_In1z2du1_flaksyopx1(0);}
static inline NI32 len_6_Igv2wyu1_comaa5xpt1(openArray_0_Ig73pnk_comaa5xpt1 a_40){
  NI32 result_207;
  result_207 = a_40.len_0;
  return result_207;}
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_comaa5xpt1(openArray_0_Ig73pnk_comaa5xpt1 x_29, NI32 idx_30){
  NB8 X60Qx_1997;
  if (0 <= idx_30){
    X60Qx_1997 = (idx_30 < x_29.len_0);}
  else {
    X60Qx_1997 = NIM_FALSE;}
  if ((!X60Qx_1997)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  string_0_sysvq0asl* result_208;
  result_208 = (&x_29.a_0[idx_30]);
  return result_208;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NI32 len_3_Izoe8zv_explnj22x1(seq_0_Incv1wn_explnj22x1 s_25){
  NI32 result_50;
  result_50 = s_25.len_0;
  return result_50;}
static inline NU8* getQ_7_Ig0r1051_explnj22x1(seq_0_Incv1wn_explnj22x1 s_26, NI32 i_23){
  NB8 X60Qx_1410;
  if (i_23 < s_26.len_0){
    X60Qx_1410 = (0 <= i_23);}
  else {
    X60Qx_1410 = NIM_FALSE;}
  if ((!X60Qx_1410)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NU8* result_51;
  result_51 = (&s_26.data_0[i_23]);
  return result_51;}
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
static inline void putQ_7_Ipw0nqk1_explnj22x1(seq_0_Incv1wn_explnj22x1* s_29, NI32 i_26, NU8 elem_9){
  NB8 X60Qx_1414;
  if (i_26 < (*s_29).len_0){
    X60Qx_1414 = (0 <= i_26);}
  else {
    X60Qx_1414 = NIM_FALSE;}
  if ((!X60Qx_1414)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  (*s_29).data_0[i_26] = elem_9;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15){
  NB8 X60Qx_259;
  NI32 X60Qx_260 = len_4_sysvq0asl((*s_55));
  if (i_15 < X60Qx_260){
    X60Qx_259 = (0 <= i_15);}
  else {
    X60Qx_259 = NIM_FALSE;}
  if ((!X60Qx_259)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I11201514831099767300_sysvq0asl)}
    );}
  prepareMutation_0_sysvq0asl(s_55);
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_55).bytes_0))))){
    (*(*s_55).more_0).data_0[i_15] = c_15;
    if (i_15 < ((NI32)3)){
      ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
  else {
    ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
static inline seq_0_In6doa_ast8ri79k newSeqUninit_0_Ieodq4s1_ast8ri79k(NI32 size_32){
  seq_0_In6doa_ast8ri79k result_50;
  if (size_32 == 0){
    result_50 = (seq_0_In6doa_ast8ri79k){
      .len_0 = size_32, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_18 = memSizeInBytes_0_Ivqzo5x1_ast8ri79k(size_32);
    void* X60Qx_132 = alloc_1_sysvq0asl(memSize_18);
    result_50 = (seq_0_In6doa_ast8ri79k){
      .len_0 = size_32, .data_0 = ((NU32*)X60Qx_132)}
    ;
    if ((!(result_50.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_133 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_50.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_18);}}
  return result_50;}
static inline NI32 len_3_I6y2imo_buiyylk1h1(seq_0_In6doa_ast8ri79k s_56){
  NI32 result_20;
  result_20 = s_56.len_0;
  return result_20;}
static inline NU32* getQ_7_I2v00yv1_buiyylk1h1(seq_0_In6doa_ast8ri79k s_58, NI32 i_28){
  NB8 X60Qx_155;
  if (i_28 < s_58.len_0){
    X60Qx_155 = (0 <= i_28);}
  else {
    X60Qx_155 = NIM_FALSE;}
  if ((!X60Qx_155)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NU32* result_21;
  result_21 = (&s_58.data_0[i_28]);
  return result_21;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
static inline void add_0_I34il1q_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_112, NU32 elem_26){
  NI32 L_1 = (*s_112).len_0;
  NI32 X60Qx_1795 = capInBytes_0_Iev6wua1_ast8ri79k((*s_112));
  if (X60Qx_1795 < ((NI32)(((NI32)(L_1 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_1796 = resize_0_I6ho9ve_buiyylk1h1(s_112, 1);
    if ((!X60Qx_1796)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_112).len_0));
  (*s_112).data_0[L_1] = elem_26;}
static inline NI32 len_3_If78p9o_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_31){
  NI32 result_19;
  result_19 = s_31.len_0;
  return result_19;}
static inline openArray_0_Ihovqtr1_fiepkwzpc toOpenArray_1_Ilfv4hf_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_32){
  openArray_0_Ihovqtr1_fiepkwzpc result_20;
  FieldOff_0_fiepkwzpc* X60Qx_158 = rawData_0_Ifr35xc1_fiepkwzpc(s_32);
  result_20 = (openArray_0_Ihovqtr1_fiepkwzpc){
    .a_0 = X60Qx_158, .len_0 = s_32.len_0}
  ;
  return result_20;}
static inline NI32 len_6_Ikuawih_fiepkwzpc(openArray_0_Ihovqtr1_fiepkwzpc a_4){
  NI32 result_40;
  result_40 = a_4.len_0;
  return result_40;}
static inline FieldOff_0_fiepkwzpc* getQ_10_Iu0e57f_fiepkwzpc(openArray_0_Ihovqtr1_fiepkwzpc x_3, NI32 idx_4){
  NB8 X60Qx_177;
  if (0 <= idx_4){
    X60Qx_177 = (idx_4 < x_3.len_0);}
  else {
    X60Qx_177 = NIM_FALSE;}
  if ((!X60Qx_177)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  FieldOff_0_fiepkwzpc* result_41;
  result_41 = (&x_3.a_0[idx_4]);
  return result_41;}
static inline void eQwasMoved_1_I861g1c1_explnj22x1(seq_0_Incv1wn_explnj22x1* s_130){
  (*s_130).len_0 = 0;
  (*s_130).data_0 = NIM_NIL;}
static inline void putQ_7_Ifvyck5_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_111, NI32 i_37, NI32 elem_25){
  NB8 X60Qx_1794;
  if (i_37 < (*s_111).len_0){
    X60Qx_1794 = (0 <= i_37);}
  else {
    X60Qx_1794 = NIM_FALSE;}
  if ((!X60Qx_1794)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  (*s_111).data_0[i_37] = elem_25;}
static inline void eQwasMoved_1_Ix88qzs1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1* s_35){
  (*s_35).len_0 = 0;
  (*s_35).data_0 = NIM_NIL;}
static inline openArray_0_Inqs7yx_comaa5xpt1 toOpenArray_1_Ibqb4ob_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_160){
  openArray_0_Inqs7yx_comaa5xpt1 result_92;
  NI32* X60Qx_1850 = rawData_0_Ic25u3r_comaa5xpt1(s_160);
  result_92 = (openArray_0_Inqs7yx_comaa5xpt1){
    .a_0 = X60Qx_1850, .len_0 = s_160.len_0}
  ;
  return result_92;}
static inline NI32 len_6_I9632ti1_comaa5xpt1(openArray_0_Inqs7yx_comaa5xpt1 a_32){
  NI32 result_173;
  result_173 = a_32.len_0;
  return result_173;}
static inline NI32* getQ_10_I053icq_comaa5xpt1(openArray_0_Inqs7yx_comaa5xpt1 x_21, NI32 idx_24){
  NB8 X60Qx_1958;
  if (0 <= idx_24){
    X60Qx_1958 = (idx_24 < x_21.len_0);}
  else {
    X60Qx_1958 = NIM_FALSE;}
  if ((!X60Qx_1958)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  NI32* result_174;
  result_174 = (&x_21.a_0[idx_24]);
  return result_174;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
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
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
static inline NI32 capInBytes_0_Iffahgv_explnj22x1(seq_0_Incv1wn_explnj22x1 s_149){
  NI32 result_121;
  NI32 X60Qx_70;
  if ((!(s_149.data_0 == NIM_NIL))){
    NI32 X60Qx_1564 = allocatedSize_0_sysvq0asl(((void*)((void*)s_149.data_0)));
    X60Qx_70 = X60Qx_1564;}
  else {
    X60Qx_70 = 0;}
  result_121 = X60Qx_70;
  return result_121;}
static inline NI32 memSizeInBytes_0_Infw7m1_explnj22x1(NI32 size_6){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_71;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_6, sizeof(NU8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_71 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_71 = ((NI32)2147483647);}
  return result_71;}
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
static inline NI32 memSizeInBytes_0_Ivqzo5x1_ast8ri79k(NI32 size_33){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_52;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_33, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_52 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_52 = ((NI32)2147483647);}
  return result_52;}
static inline NI32 capInBytes_0_Iev6wua1_ast8ri79k(seq_0_In6doa_ast8ri79k s_73){
  NI32 result_51;
  NI32 X60Qx_7;
  if ((!(s_73.data_0 == NIM_NIL))){
    NI32 X60Qx_134 = allocatedSize_0_sysvq0asl(((void*)((void*)s_73.data_0)));
    X60Qx_7 = X60Qx_134;}
  else {
    X60Qx_7 = 0;}
  result_51 = X60Qx_7;
  return result_51;}
static inline FieldOff_0_fiepkwzpc* rawData_0_Ifr35xc1_fiepkwzpc(seq_0_Id0odh1_fiepkwzpc s_41){
  FieldOff_0_fiepkwzpc* result_39;
  result_39 = s_41.data_0;
  return result_39;}
static inline NI32* rawData_0_Ic25u3r_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_236){
  NI32* result_172;
  result_172 = s_236.data_0;
  return result_172;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
