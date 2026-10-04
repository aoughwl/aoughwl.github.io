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
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
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
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
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
typedef struct Cell_Obj_0_valzr1t4f{
  Value_0_valzr1t4f v_0;}
Cell_Obj_0_valzr1t4f;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct seq_0_Iw8xl5b1_arecyyj7v{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_arecyyj7v;
typedef struct ClosureEnv_Obj_0_valzr1t4f{
  seq_0_In6doa_arecyyj7v vars_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;
  X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* coro_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;}
ClosureEnv_Obj_0_valzr1t4f;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_arecyyj7v names_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
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
typedef struct X60Qt_0_IAarrayAuS64ZS4_intzsnzax{
  NU64 a[4];}
X60Qt_0_IAarrayAuS64ZS4_intzsnzax;
typedef struct SetBox_Obj_0_valzr1t4f{
  X60Qt_0_IAarrayAuS64ZS4_intzsnzax words_0;}
SetBox_Obj_0_valzr1t4f;
typedef struct seq_0_Igsxz3n_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_Igsxz3n_arecyyj7v;
typedef struct openArray_0_Ig73pnk_aow7lb5cq1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_aow7lb5cq1;
typedef struct seq_0_I7epg22_valzr1t4f{
  NI32 len_0;
  NC8* data_0;}
seq_0_I7epg22_valzr1t4f;
typedef struct openArray_0_Iptmq8f_valzr1t4f{
  NU32* a_0;
  NI32 len_0;}
openArray_0_Iptmq8f_valzr1t4f;
typedef struct HSlice_0_Inzqy8d_aow7lb5cq1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_aow7lb5cq1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  Cell_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  ClosureEnv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  FlatRegion_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v{
  NI r_00;
  PtrOv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  SetBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISX53ymX49d0nifh7u8pu1AiS32ZSstring0sysvq0aslAnimcallZAfalseZAR53_valzr1t4f)(NU32, NI32);
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct seq_0_Ivkh6l1_linxafkvx1{
  NI32 len_0;
  LineInfoUnpacked_0_linxafkvx1* data_0;}
seq_0_Ivkh6l1_linxafkvx1;
typedef struct LineInfoManager_0_linxafkvx1{
  seq_0_Ivkh6l1_linxafkvx1 aside_0;}
LineInfoManager_0_linxafkvx1;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
typedef struct seq_0_If70loa_intzsnzax{
  NI32 len_0;
  NU32* data_0;}
seq_0_If70loa_intzsnzax;
typedef struct BiTable_0_Ieutpr21_intzsnzax{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_If70loa_intzsnzax keys_0;}
BiTable_0_Ieutpr21_intzsnzax;
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Izov3yo_ast8ri79k keys_0;}
BiTable_0_Ipgo74p_ast8ri79k;
typedef struct seq_0_Iotb7mc_ast8ri79k{
  NI32 len_0;
  NI64* data_0;}
seq_0_Iotb7mc_ast8ri79k;
typedef struct seq_0_Iwy7s2o_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iwy7s2o_ast8ri79k;
typedef struct BiTable_0_Itvq7bk_ast8ri79k{
  seq_0_Iotb7mc_ast8ri79k vals_0;
  seq_0_Iwy7s2o_ast8ri79k keys_0;}
BiTable_0_Itvq7bk_ast8ri79k;
typedef struct seq_0_Ijmiee61_ast8ri79k{
  NI32 len_0;
  NU64* data_0;}
seq_0_Ijmiee61_ast8ri79k;
typedef struct seq_0_Ipw48je1_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Ipw48je1_ast8ri79k;
typedef struct BiTable_0_Itxao711_ast8ri79k{
  seq_0_Ijmiee61_ast8ri79k vals_0;
  seq_0_Ipw48je1_ast8ri79k keys_0;}
BiTable_0_Itxao711_ast8ri79k;
typedef struct seq_0_Isoawlw1_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Isoawlw1_ast8ri79k;
typedef struct BiTable_0_Iojfwmy1_ast8ri79k{
  seq_0_Ijmiee61_ast8ri79k vals_0;
  seq_0_Isoawlw1_ast8ri79k keys_0;}
BiTable_0_Iojfwmy1_ast8ri79k;
typedef struct Literals_0_nifh7u8pu1{
  LineInfoManager_0_linxafkvx1 man_0;
  BiTable_0_Icvz6lt_buiyylk1h1 tags_0;
  BiTable_0_Ieutpr21_intzsnzax files_0;
  BiTable_0_I0ksat5_ast8ri79k syms_0;
  BiTable_0_Ipgo74p_ast8ri79k strings_0;
  BiTable_0_Itvq7bk_ast8ri79k integers_0;
  BiTable_0_Itxao711_ast8ri79k uintegers_0;
  BiTable_0_Iojfwmy1_ast8ri79k floats_0;}
Literals_0_nifh7u8pu1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
Value_0_valzr1t4f vNil_0_valzr1t4f(void);
Value_0_valzr1t4f vStr_0_valzr1t4f(string_0_sysvq0asl s_0);
string_0_sysvq0asl renderReadable_1_valzr1t4f(Value_0_valzr1t4f* v_21, NI32 depth_2, seq_0_Igsxz3n_arecyyj7v* seen_4, NI32* budget_2);
static inline seq_0_I7epg22_valzr1t4f newSeqUninit_0_I5ncg7j_valzr1t4f(NI32 size_3);
static inline void add_0_Id5x3o5_valzr1t4f(seq_0_I7epg22_valzr1t4f* s_17, NC8 elem_3);
static inline NI32 len_3_Irwqcn4_valzr1t4f(seq_0_I7epg22_valzr1t4f s_19);
static inline NC8* getQ_7_Iqupddu1_valzr1t4f(seq_0_I7epg22_valzr1t4f s_20, NI32 i_15);
static inline openArray_0_Iptmq8f_valzr1t4f toOpenArray_1_Iy9e09m1_valzr1t4f(seq_0_Igsxz3n_arecyyj7v s_26);
void setLen_0_Iqjrd6x1_valzr1t4f(seq_0_Igsxz3n_arecyyj7v* s_29, NI32 newLen_1);
static inline NI32 memSizeInBytes_0_Iigtmlk1_valzr1t4f(NI32 size_9);
static inline NI32 capInBytes_0_Isccluk1_valzr1t4f(seq_0_I7epg22_valzr1t4f s_36);
NB8 resize_0_Irimnxi1_valzr1t4f(seq_0_I7epg22_valzr1t4f* dest_3, NI32 addedElements_3);
static inline NU32* rawData_0_I2ocua8_valzr1t4f(seq_0_Igsxz3n_arecyyj7v s_39);
static inline NI32 len_6_Iql6z121_valzr1t4f(openArray_0_Iptmq8f_valzr1t4f a_11);
static inline NU32* getQ_10_Isxag051_valzr1t4f(openArray_0_Iptmq8f_valzr1t4f x_16, NI32 idx_8);
void shrink_0_I8pb57y1_valzr1t4f(seq_0_Igsxz3n_arecyyj7v* s_40, NI32 newLen_4);
void growUnsafe_0_Ivs2bxy1_valzr1t4f(seq_0_Igsxz3n_arecyyj7v* s_41, NI32 newLen_5);
void eQdestroy_1_I9czx0f1_valzr1t4f(seq_0_I7epg22_valzr1t4f s_70);
void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
void eQdestroyQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* dest_0);
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* dest_0);
void eQwasmovedQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax** dest_0);
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0);
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* eQdupQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* src_0);
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQtraceQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax** dest_0, void* src_0);
void eQtraceQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0);
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0);
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQtraceQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0);
void eQtraceQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0);
void eQtraceQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0);
void eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* dest_0);
void eQdestroyQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* dest_0);
void eQwasmovedQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v** dest_0);
void eQwasmovedQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax** dest_0);
void eQwasmovedQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax** dest_0);
X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* eQdupQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* src_0);
X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* eQdupQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* src_0);
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* eQdupQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* src_0);
void eQtraceQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v** dest_0, void* src_0);
void eQtraceQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax** dest_0, void* src_0);
void eQtraceQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax** dest_0, void* src_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern LongString_0_sysvq0asl const strlit_0_I6105018409752412263_dbg4n0xd21;
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_Iw8xl5b1_arecyyj7v newSeqUninit_0_I1tbjnk1_arecyyj7v(NI32 size_24);
static inline NI32 len_3_I83dzei_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_25);
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_26, NI32 i_28);
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_arecyyj7v* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern seq_0_In6doa_arecyyj7v eQdup_1_Idg8rf9_arecyyj7v(seq_0_In6doa_arecyyj7v a_17);
extern xint_0_xinat3x34 createXint_0_xinat3x34(NI64 x_4);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
extern void extractBasename_1_symkyk35i1(string_0_sysvq0asl* s_1);
extern NI64 asSigned_0_xinat3x34(xint_0_xinat3x34 x_2, NB8* err_0);
extern NU64 asUnsigned_0_xinat3x34(xint_0_xinat3x34 x_3, NB8* err_1);
extern xint_0_xinat3x34 zero_0_xinat3x34(void);
extern NB8 eqQ_0_xinat3x34(xint_0_xinat3x34 a_18, xint_0_xinat3x34 b_10);
extern string_0_sysvq0asl dollarQ_7_sysvq0asl(NF64 x_348);
extern LongString_0_sysvq0asl const strlit_0_I8572766038233537570_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I3372626016653902757_emi78vuj01;
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern LongString_0_sysvq0asl const strlit_0_I5316556160589403975_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I9873340078075426535_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I1990248930136438291_intzsnzax;
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
static inline NI32 len_3_I3cga53_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_43);
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_dbgj4vyzj1(NI32 a_13, NI32 b_2);
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
static inline void dec_0_Ig5i8xp_nifb6mq6y1(NI32* x_18, NI32 y_4);
extern LongString_0_sysvq0asl const strlit_0_I10817201013825926720_dbgj4vyzj1;
extern LongString_0_sysvq0asl const strlit_0_I734781229358173569_dbgj4vyzj1;
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37);
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33);
static inline void add_0_Iwsr3ai_arecyyj7v(seq_0_Igsxz3n_arecyyj7v* s_45, NU32 elem_7);
static inline seq_0_Igsxz3n_arecyyj7v newSeqUninit_0_I1kz5fl_arecyyj7v(NI32 size_10);
extern void eQdestroy_1_Ib6pp1_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_73);
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_27);
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6);
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_28);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
static inline NI32 capInBytes_0_Ia2b4aa_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_50);
extern NB8 resize_0_Ieull6y_arecyyj7v(seq_0_Igsxz3n_arecyyj7v* dest_7, NI32 addedElements_7);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_I8k3d0z1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_75);
extern void eQdestroy_1_Iscb4i31_arecyyj7v(seq_0_In6doa_arecyyj7v s_81);
extern void eQdestroy_1_Ijx6eoq_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_78);
extern void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_xinat3x34(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_symkyk35i1(void);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 memSizeInBytes_0_Ixcobep_arecyyj7v(NI32 size_25);
static inline NI32 capInBytes_0_Iih34tr1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_87);
extern NB8 resize_0_If3pogj_flaksyopx1(seq_0_Iw8xl5b1_arecyyj7v* dest_4, NI32 addedElements_4);
extern void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
static inline NI32 memSizeInBytes_0_Ioqvae11_arecyyj7v(NI32 size_15);
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I13021287048749917422_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkNil"}
;
LongString_0_sysvq0asl const strlit_0_I660019497787745985_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkInt"}
;
LongString_0_sysvq0asl const strlit_0_I17031991666208428624_valzr1t4f = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkUInt"}
;
LongString_0_sysvq0asl const strlit_0_I12522418509369288814_valzr1t4f = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkFloat"}
;
LongString_0_sysvq0asl const strlit_0_I13713944732189728992_valzr1t4f = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkBool"}
;
LongString_0_sysvq0asl const strlit_0_I52251037002071843_valzr1t4f = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkChar"}
;
LongString_0_sysvq0asl const strlit_0_I14431728484787280804_valzr1t4f = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkString"}
;
LongString_0_sysvq0asl const strlit_0_I5181047062616341298_valzr1t4f = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkEnum"}
;
LongString_0_sysvq0asl const strlit_0_I10226434242242547095_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkSeq"}
;
LongString_0_sysvq0asl const strlit_0_I10740187594655811902_valzr1t4f = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkArray"}
;
LongString_0_sysvq0asl const strlit_0_I18161105815053747832_valzr1t4f = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkTuple"}
;
LongString_0_sysvq0asl const strlit_0_I2816361684503279331_valzr1t4f = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkObject"}
;
LongString_0_sysvq0asl const strlit_0_I14071318187021295975_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkRef"}
;
LongString_0_sysvq0asl const strlit_0_I10068244995211906959_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkPtr"}
;
LongString_0_sysvq0asl const strlit_0_I4576800331711514745_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkSet"}
;
LongString_0_sysvq0asl const strlit_0_I12004295674729814082_valzr1t4f = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkProc"}
;
LongString_0_sysvq0asl const strlit_0_I435962976610090392_valzr1t4f = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkStream"}
;
LongString_0_sysvq0asl const strlit_0_I2405585310759867956_valzr1t4f = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vkCont"}
;
LongString_0_sysvq0asl const strlit_0_I13068369644666833682_valzr1t4f = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rkBytes"}
;
LongString_0_sysvq0asl const strlit_0_I15255950865718029157_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rkSeq"}
;
LongString_0_sysvq0asl const strlit_0_I8944398165928514150_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rkArr"}
;
LongString_0_sysvq0asl const strlit_0_I8446304413138944875_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rkStr"}
;
LongString_0_sysvq0asl const strlit_0_I3412482732172750780_valzr1t4f = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rkCell"}
;
LongString_0_sysvq0asl const strlit_0_I8127409244350026501_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rkObj"}
;
LongString_0_sysvq0asl const strlit_0_I1672035738740780362_valzr1t4f = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rkForeign"}
;
LongString_0_sysvq0asl const strlit_0_I8350635790867353280_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "enum:"}
;
LongString_0_sysvq0asl const strlit_0_I13499555360605886803_valzr1t4f = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(object)"}
;
LongString_0_sysvq0asl const strlit_0_I1708568703999513659_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "{set}"}
;
LongString_0_sysvq0asl const strlit_0_I17682010759162773284_valzr1t4f = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "continuation"}
;
LongString_0_sysvq0asl const strlit_0_I17892332096354785130_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\246("}
;
LongString_0_sysvq0asl const strlit_0_I15811569221951826670_valzr1t4f = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " chars)\342\200\246 "}
;
LongString_0_sysvq0asl const strlit_0_I7590662755332226574_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\342\200\246(+"}
;
LongString_0_sysvq0asl const strlit_0_I16360096150727577611_valzr1t4f = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " fields){budget}"}
;
LongString_0_sysvq0asl const strlit_0_I8898202128342635644_valzr1t4f = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "@[\342\200\246]"}
;
LongString_0_sysvq0asl const strlit_0_I15433588765009474833_valzr1t4f = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "){budget}"}
;
LongString_0_sysvq0asl const strlit_0_I7681136583982100770_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "[\342\200\246]"}
;
LongString_0_sysvq0asl const strlit_0_I8973501876771101138_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(\342\200\246)"}
;
LongString_0_sysvq0asl const strlit_0_I14068598100739118063_valzr1t4f = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<cycle>"}
;
LongString_0_sysvq0asl const strlit_0_I11598900929015759369_valzr1t4f = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ref \342\200\246"}
;
LongString_0_sysvq0asl const strlit_0_I934609865401688195_valzr1t4f = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<foreign 0x"}
;
LongString_0_sysvq0asl const strlit_0_I11501170429003019622_valzr1t4f = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<view "}
;
LongString_0_sysvq0asl const strlit_0_I1095046037665756977_valzr1t4f = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ptr \342\200\246"}
;
LongString_0_sysvq0asl const strlit_0_I6638091695445642996_valzr1t4f = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<no field \'"}
;
LongString_0_sysvq0asl const strlit_0_I13247028810395804432_valzr1t4f = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' on "}
;
static string_0_sysvq0asl const Digits_0 = {
  .bytes_0 = 842084606u, .more_0 = (&strlit_0_I6105018409752412263_dbg4n0xd21)}
;
X60Qt_0_ISX53ymX49d0nifh7u8pu1AiS32ZSstring0sysvq0aslAnimcallZAfalseZAR53_valzr1t4f enumNamerHook_0_valzr1t4f = NIM_NIL;
NI32 dbgRenderDepth_0_valzr1t4f = 5;
NB8 X60QiniGuard_0_valzr1t4f;
string_0_sysvq0asl dollarX60Q_ValueKind_0_valzr1t4f(ValueKind_0_valzr1t4f e_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  switch (e_0){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1315665662u, .more_0 = (&strlit_0_I13021287048749917422_valzr1t4f)}
      ;}
    break;
    case 1:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1231779582u, .more_0 = (&strlit_0_I660019497787745985_valzr1t4f)}
      ;}
    break;
    case 2:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1433106174u, .more_0 = (&strlit_0_I17031991666208428624_valzr1t4f)}
      ;}
    break;
    case 3:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1181447934u, .more_0 = (&strlit_0_I12522418509369288814_valzr1t4f)}
      ;}
    break;
    case 4:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1114339070u, .more_0 = (&strlit_0_I13713944732189728992_valzr1t4f)}
      ;}
    break;
    case 5:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1131116286u, .more_0 = (&strlit_0_I52251037002071843_valzr1t4f)}
      ;}
    break;
    case 6:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399551742u, .more_0 = (&strlit_0_I14431728484787280804_valzr1t4f)}
      ;}
    break;
    case 7:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1164670718u, .more_0 = (&strlit_0_I5181047062616341298_valzr1t4f)}
      ;}
    break;
    case 8:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399551742u, .more_0 = (&strlit_0_I10226434242242547095_valzr1t4f)}
      ;}
    break;
    case 9:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1097561854u, .more_0 = (&strlit_0_I10740187594655811902_valzr1t4f)}
      ;}
    break;
    case 10:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1416328958u, .more_0 = (&strlit_0_I18161105815053747832_valzr1t4f)}
      ;}
    break;
    case 11:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1332442878u, .more_0 = (&strlit_0_I2816361684503279331_valzr1t4f)}
      ;}
    break;
    case 12:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1382774526u, .more_0 = (&strlit_0_I14071318187021295975_valzr1t4f)}
      ;}
    break;
    case 13:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1349220094u, .more_0 = (&strlit_0_I10068244995211906959_valzr1t4f)}
      ;}
    break;
    case 14:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399551742u, .more_0 = (&strlit_0_I4576800331711514745_valzr1t4f)}
      ;}
    break;
    case 15:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1349220094u, .more_0 = (&strlit_0_I12004295674729814082_valzr1t4f)}
      ;}
    break;
    case 16:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399551742u, .more_0 = (&strlit_0_I435962976610090392_valzr1t4f)}
      ;}
    break;
    case 17:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1131116286u, .more_0 = (&strlit_0_I2405585310759867956_valzr1t4f)}
      ;}
    break;}
  return result_0;}
string_0_sysvq0asl dollarX60Q_RegionKind_0_valzr1t4f(RegionKind_0_valzr1t4f e_2){
  string_0_sysvq0asl result_2;
  nimStrWasMoved((&result_2));
  switch (e_2){
    case 0:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1114338046u, .more_0 = (&strlit_0_I13068369644666833682_valzr1t4f)}
      ;}
    break;
    case 1:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399550718u, .more_0 = (&strlit_0_I15255950865718029157_valzr1t4f)}
      ;}
    break;
    case 2:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1097560830u, .more_0 = (&strlit_0_I8944398165928514150_valzr1t4f)}
      ;}
    break;
    case 3:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1399550718u, .more_0 = (&strlit_0_I8446304413138944875_valzr1t4f)}
      ;}
    break;
    case 4:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1131115262u, .more_0 = (&strlit_0_I3412482732172750780_valzr1t4f)}
      ;}
    break;
    case 5:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1332441854u, .more_0 = (&strlit_0_I8127409244350026501_valzr1t4f)}
      ;}
    break;
    case 6:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 1181446910u, .more_0 = (&strlit_0_I1672035738740780362_valzr1t4f)}
      ;}
    break;}
  return result_2;}
string_0_sysvq0asl hexu_0_valzr1t4f(NU64 u_0){
  string_0_sysvq0asl result_3;
  nimStrWasMoved((&result_3));
  if (u_0 == ((NU64)0u)){
    return (string_0_sysvq0asl){
      .bytes_0 = 12289u, .more_0 = NIM_NIL}
    ;}
  seq_0_I7epg22_valzr1t4f buf_0 = newSeqUninit_0_I5ncg7j_valzr1t4f(0);
  NU64 n_1 = u_0;
  {
    while ((!(n_1 == ((NU64)0u)))){
      NC8 X60Qx_24 = getQ_9_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 842084606u, .more_0 = (&strlit_0_I6105018409752412263_dbg4n0xd21)}
      , ((NI32)((NU64)(n_1 & ((NU64)15u)))));
      add_0_Id5x3o5_valzr1t4f((&buf_0), X60Qx_24);
      n_1 = ((NU64)(n_1 >> 4));}}
  whileStmtLabel_0: ;
  nimStrDestroy(result_3);
  result_3 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 X60Qx_25 = len_3_Irwqcn4_valzr1t4f(buf_0);
  NI32 i_0 = ((NI32)(X60Qx_25 - 1));
  {
    while (0 <= i_0){
      NC8* X60Qx_26 = getQ_7_Iqupddu1_valzr1t4f(buf_0, i_0);
      add_1_sysvq0asl((&result_3), (*X60Qx_26));
      dec_1_I0nzoz91_aow7lb5cq1((&i_0));}}
  whileStmtLabel_1: ;
  eQdestroy_1_I9czx0f1_valzr1t4f(buf_0);
  return result_3;
  eQdestroy_1_I9czx0f1_valzr1t4f(buf_0);
  return result_3;}
string_0_sysvq0asl itoa_0_valzr1t4f(NI64 x_0){
  string_0_sysvq0asl result_4;
  nimStrWasMoved((&result_4));
  nimStrDestroy(result_4);
  result_4 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (x_0 == ((NI64)0)){
    nimStrDestroy(result_4);
    result_4 = (string_0_sysvq0asl){
      .bytes_0 = 12289u, .more_0 = NIM_NIL}
    ;
    return result_4;}
  NI64 n_2 = x_0;
  NB8 neg_0 = NIM_FALSE;
  if (n_2 < ((NI64)0)){
    neg_0 = NIM_TRUE;}
  seq_0_I7epg22_valzr1t4f digits_0 = newSeqUninit_0_I5ncg7j_valzr1t4f(0);
  if ((!neg_0)){
    n_2 = ((NI64)-n_2);}
  {
    while ((!(n_2 == ((NI64)0)))){
      NI32 d_0 = ((NI32)((NI64)-((NI64)(n_2 % ((NI64)10)))));
      add_0_Id5x3o5_valzr1t4f((&digits_0), ((NC8)((NI32)(((NI32)(NC8)'0') + d_0))));
      n_2 = ((NI64)(n_2 / ((NI64)10)));}}
  whileStmtLabel_0: ;
  if (neg_0){
    add_1_sysvq0asl((&result_4), (NC8)'-');}
  NI32 X60Qx_27 = len_3_Irwqcn4_valzr1t4f(digits_0);
  NI32 i_2 = ((NI32)(X60Qx_27 - 1));
  {
    while (0 <= i_2){
      NC8* X60Qx_28 = getQ_7_Iqupddu1_valzr1t4f(digits_0, i_2);
      add_1_sysvq0asl((&result_4), (*X60Qx_28));
      dec_1_I0nzoz91_aow7lb5cq1((&i_2));}}
  whileStmtLabel_1: ;
  eQdestroy_1_I9czx0f1_valzr1t4f(digits_0);
  return result_4;
  eQdestroy_1_I9czx0f1_valzr1t4f(digits_0);
  return result_4;}
string_0_sysvq0asl utoa_0_valzr1t4f(NU64 x_1){
  string_0_sysvq0asl result_5;
  nimStrWasMoved((&result_5));
  nimStrDestroy(result_5);
  result_5 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (x_1 == ((NU64)0u)){
    nimStrDestroy(result_5);
    result_5 = (string_0_sysvq0asl){
      .bytes_0 = 12289u, .more_0 = NIM_NIL}
    ;
    return result_5;}
  NU64 n_3 = x_1;
  seq_0_I7epg22_valzr1t4f digits_1 = newSeqUninit_0_I5ncg7j_valzr1t4f(0);
  {
    while ((!(n_3 == ((NU64)0u)))){
      NI32 d_1 = ((NI32)((NU64)(n_3 % ((NU64)10u))));
      add_0_Id5x3o5_valzr1t4f((&digits_1), ((NC8)((NI32)(((NI32)(NC8)'0') + d_1))));
      n_3 = ((NU64)(n_3 / ((NU64)10u)));}}
  whileStmtLabel_0: ;
  NI32 X60Qx_29 = len_3_Irwqcn4_valzr1t4f(digits_1);
  NI32 i_3 = ((NI32)(X60Qx_29 - 1));
  {
    while (0 <= i_3){
      NC8* X60Qx_30 = getQ_7_Iqupddu1_valzr1t4f(digits_1, i_3);
      add_1_sysvq0asl((&result_5), (*X60Qx_30));
      dec_1_I0nzoz91_aow7lb5cq1((&i_3));}}
  whileStmtLabel_1: ;
  eQdestroy_1_I9czx0f1_valzr1t4f(digits_1);
  return result_5;
  eQdestroy_1_I9czx0f1_valzr1t4f(digits_1);
  return result_5;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* newCell_0_valzr1t4f(Value_0_valzr1t4f* v_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* result_6;
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((&result_6));
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(result_6);
  void* X60Qx_31 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)X60Qx_31);
  Value_0_valzr1t4f X60Qx_32 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_0)));
  (*X60Qtmp_0) = (X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (Cell_Obj_0_valzr1t4f){
      .v_0 = X60Qx_32}}
  ;
  result_6 = X60Qtmp_0;
  return result_6;}
Value_0_valzr1t4f deepCopyValue_0_valzr1t4f(Value_0_valzr1t4f* v_1){
  Value_0_valzr1t4f result_7;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_7));
  switch ((*v_1).kind_0){
    case 8:
    {
      if ((*v_1).sq_0 == NIM_NIL){
        Value_0_valzr1t4f X60Qx_33 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
        return X60Qx_33;}
      void* X60Qx_34 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_1 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_34);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_35 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_1) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
          .elems_0 = X60Qx_35, .flat_0 = NIM_NIL}}
      ;
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* nb_0 = X60Qtmp_1;
      NI32 i_4 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_36 = len_3_I83dzei_arecyyj7v((*(*v_1).sq_0).d_00.elems_0);
          if (i_4 < X60Qx_36){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_37 = getQ_7_Ii14ync1_arecyyj7v((*(*v_1).sq_0).d_00.elems_0, i_4);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_3 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((*X60Qx_37));
            Value_0_valzr1t4f X60Qx_0;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
            if ((!(c_3 == NIM_NIL))){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
              Value_0_valzr1t4f X60Qx_38 = deepCopyValue_0_valzr1t4f((&(*c_3).d_00.v_0));
              X60Qx_0 = X60Qx_38;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
              Value_0_valzr1t4f X60Qx_39 = vNil_0_valzr1t4f();
              X60Qx_0 = X60Qx_39;}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_40 = newCell_0_valzr1t4f((&X60Qx_0));
            add_0_Ijpw0mu_flaksyopx1((&(*nb_0).d_00.elems_0), X60Qx_40);
            inc_1_I6wjjge_aow2h993l1((&i_4));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
            eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(c_3);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_7));
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_2 = nb_0;
      eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((&nb_0));
      result_7 = (Value_0_valzr1t4f){
        .kind_0 = 8, .sq_0 = X60Qtmp_2}
      ;
      eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(nb_0);}
    break;
    case 9:
    {
      if ((*v_1).arr_0 == NIM_NIL){
        Value_0_valzr1t4f X60Qx_41 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
        return X60Qx_41;}
      void* X60Qx_42 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_3 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_42);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_43 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_3) = (X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (ArrBox_Obj_0_valzr1t4f){
          .elems_0 = X60Qx_43, .lo_0 = (*(*v_1).arr_0).d_00.lo_0, .flat_0 = NIM_NIL}}
      ;
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* nb_1 = X60Qtmp_3;
      NI32 i_6 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_44 = len_3_I83dzei_arecyyj7v((*(*v_1).arr_0).d_00.elems_0);
          if (i_6 < X60Qx_44){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_45 = getQ_7_Ii14ync1_arecyyj7v((*(*v_1).arr_0).d_00.elems_0, i_6);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_4 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((*X60Qx_45));
            Value_0_valzr1t4f X60Qx_1;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_1));
            if ((!(c_4 == NIM_NIL))){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_1));
              Value_0_valzr1t4f X60Qx_46 = deepCopyValue_0_valzr1t4f((&(*c_4).d_00.v_0));
              X60Qx_1 = X60Qx_46;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_1));
              Value_0_valzr1t4f X60Qx_47 = vNil_0_valzr1t4f();
              X60Qx_1 = X60Qx_47;}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_48 = newCell_0_valzr1t4f((&X60Qx_1));
            add_0_Ijpw0mu_flaksyopx1((&(*nb_1).d_00.elems_0), X60Qx_48);
            inc_1_I6wjjge_aow2h993l1((&i_6));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_1));
            eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(c_4);}
          else {
            break;}}}
      whileStmtLabel_1: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_7));
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_4 = nb_1;
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((&nb_1));
      result_7 = (Value_0_valzr1t4f){
        .kind_0 = 9, .arr_0 = X60Qtmp_4}
      ;
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(nb_1);}
    break;
    case 10:
    case 11:
    {
      if ((*v_1).obj_0 == NIM_NIL){
        Value_0_valzr1t4f X60Qx_49 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
        return X60Qx_49;}
      void* X60Qx_50 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_5 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_50);
      seq_0_In6doa_arecyyj7v X60Qx_51 = eQdup_1_Idg8rf9_arecyyj7v((*(*v_1).obj_0).d_00.names_0);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_52 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_5) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
          .typeSym_0 = (*(*v_1).obj_0).d_00.typeSym_0, .names_0 = X60Qx_51, .cells_0 = X60Qx_52}}
      ;
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* nb_2 = X60Qtmp_5;
      NI32 i_7 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_53 = len_3_I83dzei_arecyyj7v((*(*v_1).obj_0).d_00.cells_0);
          if (i_7 < X60Qx_53){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_54 = getQ_7_Ii14ync1_arecyyj7v((*(*v_1).obj_0).d_00.cells_0, i_7);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_5 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((*X60Qx_54));
            Value_0_valzr1t4f X60Qx_2;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
            if ((!(c_5 == NIM_NIL))){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
              Value_0_valzr1t4f X60Qx_55 = deepCopyValue_0_valzr1t4f((&(*c_5).d_00.v_0));
              X60Qx_2 = X60Qx_55;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
              Value_0_valzr1t4f X60Qx_56 = vNil_0_valzr1t4f();
              X60Qx_2 = X60Qx_56;}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_57 = newCell_0_valzr1t4f((&X60Qx_2));
            add_0_Ijpw0mu_flaksyopx1((&(*nb_2).d_00.cells_0), X60Qx_57);
            inc_1_I6wjjge_aow2h993l1((&i_7));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_2));
            eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(c_5);}
          else {
            break;}}}
      whileStmtLabel_2: ;
      if ((*v_1).kind_0 == 10){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_7));
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_6 = nb_2;
        eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((&nb_2));
        result_7 = (Value_0_valzr1t4f){
          .kind_0 = 10, .obj_0 = X60Qtmp_6}
        ;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_7));
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_7 = nb_2;
        eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((&nb_2));
        result_7 = (Value_0_valzr1t4f){
          .kind_0 = 11, .obj_0 = X60Qtmp_7}
        ;}
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(nb_2);}
    break;
    case 14:
    {
      if ((*v_1).st_0 == NIM_NIL){
        Value_0_valzr1t4f X60Qx_58 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
        return X60Qx_58;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_7));
      void* X60Qx_59 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax));
      X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* X60Qtmp_8 = ((X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax*)X60Qx_59);
      (*X60Qtmp_8) = (X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax){
        .r_00 = 0, .d_00 = (SetBox_Obj_0_valzr1t4f){
          .words_0 = (*(*v_1).st_0).d_00.words_0}}
      ;
      result_7 = (Value_0_valzr1t4f){
        .kind_0 = 14, .st_0 = X60Qtmp_8}
      ;}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_7));
      Value_0_valzr1t4f X60Qx_60 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
      result_7 = X60Qx_60;}
    break;}
  return result_7;}
Value_0_valzr1t4f copyOnAssign_0_valzr1t4f(Value_0_valzr1t4f* v_2){
  Value_0_valzr1t4f result_8;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_8));
  switch ((*v_2).kind_0){
    case 11:
    case 10:
    case 9:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_8));
      Value_0_valzr1t4f X60Qx_61 = deepCopyValue_0_valzr1t4f((&(*v_2)));
      result_8 = X60Qx_61;}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_8));
      Value_0_valzr1t4f X60Qx_62 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_2)));
      result_8 = X60Qx_62;}
    break;}
  return result_8;}
Value_0_valzr1t4f detachedDefault_0_valzr1t4f(Value_0_valzr1t4f* v_3){
  Value_0_valzr1t4f result_9;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_9));
  switch ((*v_3).kind_0){
    case 8:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_9));
      void* X60Qx_63 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_9 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_63);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_64 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_9) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
          .elems_0 = X60Qx_64, .flat_0 = NIM_NIL}}
      ;
      result_9 = (Value_0_valzr1t4f){
        .kind_0 = 8, .sq_0 = X60Qtmp_9}
      ;}
    break;
    case 6:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_9));
      Value_0_valzr1t4f X60Qx_65 = vStr_0_valzr1t4f((string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      );
      result_9 = X60Qx_65;}
    break;
    case 12:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_9));
      result_9 = (Value_0_valzr1t4f){
        .kind_0 = 12, .rf_0 = NIM_NIL}
      ;}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_9));
      Value_0_valzr1t4f X60Qx_66 = vNil_0_valzr1t4f();
      result_9 = X60Qx_66;}
    break;}
  return result_9;}
Value_0_valzr1t4f vNil_0_valzr1t4f(void){
  Value_0_valzr1t4f result_10;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_10));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_10));
  result_10 = (Value_0_valzr1t4f){
    .kind_0 = 0}
  ;
  return result_10;}
Value_0_valzr1t4f vInt_0_valzr1t4f(NI64 x_2, NI32 bits_0){
  Value_0_valzr1t4f result_11;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_11));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_11));
  xint_0_xinat3x34 X60Qx_67 = createXint_0_xinat3x34(x_2);
  result_11 = (Value_0_valzr1t4f){
    .kind_0 = 1, .ival_0 = X60Qx_67, .bits_0 = bits_0}
  ;
  return result_11;}
Value_0_valzr1t4f vIntX_0_valzr1t4f(xint_0_xinat3x34 x_3, NI32 bits_1){
  Value_0_valzr1t4f result_12;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_12));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_12));
  result_12 = (Value_0_valzr1t4f){
    .kind_0 = 1, .ival_0 = x_3, .bits_0 = bits_1}
  ;
  return result_12;}
Value_0_valzr1t4f vUInt_0_valzr1t4f(NU64 x_4, NI32 bits_2){
  Value_0_valzr1t4f result_13;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_13));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_13));
  result_13 = (Value_0_valzr1t4f){
    .kind_0 = 2, .ival_0 = (xint_0_xinat3x34){
      .nan_0 = NIM_FALSE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)x_4)}
    , .bits_0 = bits_2}
  ;
  return result_13;}
Value_0_valzr1t4f vUIntX_0_valzr1t4f(xint_0_xinat3x34 x_5, NI32 bits_3){
  Value_0_valzr1t4f result_14;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_14));
  result_14 = (Value_0_valzr1t4f){
    .kind_0 = 2, .ival_0 = x_5, .bits_0 = bits_3}
  ;
  return result_14;}
Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0){
  Value_0_valzr1t4f result_15;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_15));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_15));
  result_15 = (Value_0_valzr1t4f){
    .kind_0 = 4, .bval_0 = b_0}
  ;
  return result_15;}
Value_0_valzr1t4f vChar_0_valzr1t4f(NC8 c_0){
  Value_0_valzr1t4f result_16;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
  result_16 = (Value_0_valzr1t4f){
    .kind_0 = 5, .cval_0 = c_0}
  ;
  return result_16;}
Value_0_valzr1t4f vStr_0_valzr1t4f(string_0_sysvq0asl s_0){
  Value_0_valzr1t4f result_17;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
  string_0_sysvq0asl X60Qx_68 = nimStrDup(s_0);
  result_17 = (Value_0_valzr1t4f){
    .kind_0 = 6, .sval_0 = X60Qx_68}
  ;
  return result_17;}
static inline Value_0_valzr1t4f vPtrLoc_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1){
  Value_0_valzr1t4f result_18;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_69 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(c_1);
  result_18 = (Value_0_valzr1t4f){
    .kind_0 = 13, .loc_0 = X60Qx_69, .ov_0 = ((X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v*)NIM_NIL)}
  ;
  return result_18;}
Value_0_valzr1t4f vPtrArr_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_2, X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* a_0, X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* s_1, NI32 b_1){
  Value_0_valzr1t4f result_19;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_19));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_19));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_23 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(c_2);
  void* X60Qx_70 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v));
  X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* X60Qtmp_10 = ((X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v*)X60Qx_70);
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_71 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(a_0);
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_72 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(s_1);
  (*X60Qtmp_10) = (X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v){
    .r_00 = 0, .d_00 = (PtrOv_Obj_0_valzr1t4f){
      .arrOwn_0 = X60Qx_71, .seqOwn_0 = X60Qx_72, .base_0 = b_1, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}}
  ;
  result_19 = (Value_0_valzr1t4f){
    .kind_0 = 13, .loc_0 = X60Qx_23, .ov_0 = X60Qtmp_10}
  ;
  return result_19;}
Value_0_valzr1t4f vPtrRegT_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* reg_0, NI32 fo_0, NI16 eb_0, TCode_0_valzr1t4f ec_0, NU32 et_0){
  Value_0_valzr1t4f result_20;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_20));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_20));
  void* X60Qx_73 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v));
  X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* X60Qtmp_11 = ((X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v*)X60Qx_73);
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_74 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(reg_0);
  (*X60Qtmp_11) = (X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v){
    .r_00 = 0, .d_00 = (PtrOv_Obj_0_valzr1t4f){
      .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = X60Qx_74, .foff_0 = fo_0, .elemBits_0 = eb_0, .ecode_0 = ec_0, .etype_0 = et_0}}
  ;
  result_20 = (Value_0_valzr1t4f){
    .kind_0 = 13, .loc_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .ov_0 = X60Qtmp_11}
  ;
  return result_20;}
Value_0_valzr1t4f vPtrReg_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* reg_1, NI32 fo_1, NI16 eb_1, TCode_0_valzr1t4f ec_1){
  Value_0_valzr1t4f result_21;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_21));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_21));
  Value_0_valzr1t4f X60Qx_75 = vPtrRegT_0_valzr1t4f(reg_1, fo_1, eb_1, ec_1, ((NU32)0u));
  result_21 = X60Qx_75;
  return result_21;}
static inline X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0_valzr1t4f(Value_0_valzr1t4f* v_4){
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* result_22;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((&result_22));
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_3;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_3));
  if ((*v_4).ov_0 == NIM_NIL){
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_3);
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_76 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL));
    X60Qx_3 = X60Qx_76;}
  else {
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_3);
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_77 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*(*v_4).ov_0).d_00.arrOwn_0);
    X60Qx_3 = X60Qx_77;}
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(result_22);
  result_22 = X60Qx_3;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_3));
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_3);
  return result_22;
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_3);
  return result_22;}
static inline X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0_valzr1t4f(Value_0_valzr1t4f* v_5){
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* result_23;
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((&result_23));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_4;
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_4));
  if ((*v_5).ov_0 == NIM_NIL){
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_4);
    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_78 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL));
    X60Qx_4 = X60Qx_78;}
  else {
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_4);
    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_79 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*(*v_5).ov_0).d_00.seqOwn_0);
    X60Qx_4 = X60Qx_79;}
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(result_23);
  result_23 = X60Qx_4;
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_4));
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_4);
  return result_23;
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_4);
  return result_23;}
static inline NI32 base_0_valzr1t4f(Value_0_valzr1t4f* v_6){
  NI32 result_24;
  NI64 X60Qx_5;
  if ((*v_6).ov_0 == NIM_NIL){
    X60Qx_5 = 0;}
  else {
    X60Qx_5 = (*(*v_6).ov_0).d_00.base_0;}
  result_24 = X60Qx_5;
  return result_24;}
static inline X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0_valzr1t4f(Value_0_valzr1t4f* v_7){
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* result_25;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((&result_25));
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_6;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_6));
  if ((*v_7).ov_0 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_6);
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_80 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL));
    X60Qx_6 = X60Qx_80;}
  else {
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_6);
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_81 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*(*v_7).ov_0).d_00.region_0);
    X60Qx_6 = X60Qx_81;}
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(result_25);
  result_25 = X60Qx_6;
  eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((&X60Qx_6));
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_6);
  return result_25;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qx_6);
  return result_25;}
static inline NI32 foff_0_valzr1t4f(Value_0_valzr1t4f* v_8){
  NI32 result_26;
  NI32 X60Qx_7;
  if ((*v_8).ov_0 == NIM_NIL){
    X60Qx_7 = ((NI32)0);}
  else {
    X60Qx_7 = (*(*v_8).ov_0).d_00.foff_0;}
  result_26 = X60Qx_7;
  return result_26;}
static inline NI16 elemBits_0_valzr1t4f(Value_0_valzr1t4f* v_9){
  NI16 result_27;
  NI16 X60Qx_8;
  if ((*v_9).ov_0 == NIM_NIL){
    X60Qx_8 = ((NI16)0);}
  else {
    X60Qx_8 = (*(*v_9).ov_0).d_00.elemBits_0;}
  result_27 = X60Qx_8;
  return result_27;}
static inline TCode_0_valzr1t4f ecode_0_valzr1t4f(Value_0_valzr1t4f* v_10){
  TCode_0_valzr1t4f result_28;
  TCode_0_valzr1t4f X60Qx_9;
  if ((*v_10).ov_0 == NIM_NIL){
    X60Qx_9 = 3;}
  else {
    X60Qx_9 = (*(*v_10).ov_0).d_00.ecode_0;}
  result_28 = X60Qx_9;
  return result_28;}
static inline NU32 etype_0_valzr1t4f(Value_0_valzr1t4f* v_11){
  NU32 result_29;
  NU32 X60Qx_10;
  if ((*v_11).ov_0 == NIM_NIL){
    X60Qx_10 = ((NU32)0u);}
  else {
    X60Qx_10 = (*(*v_11).ov_0).d_00.etype_0;}
  result_29 = X60Qx_10;
  return result_29;}
X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* ovMut_0_valzr1t4f(Value_0_valzr1t4f* v_12){
  X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* result_30;
  eQwasmovedQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((&result_30));
  if ((*v_12).ov_0 == NIM_NIL){
    X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v** X60Qlhs_12 = (&(*v_12).ov_0);
    eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((*X60Qlhs_12));
    void* X60Qx_82 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v));
    X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* X60Qtmp_13 = ((X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v*)X60Qx_82);
    (*X60Qtmp_13) = (X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v){
      .r_00 = 0, .d_00 = (PtrOv_Obj_0_valzr1t4f){
        .arrOwn_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .seqOwn_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .base_0 = 0, .region_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .foff_0 = ((NI32)0), .elemBits_0 = ((NI16)0), .ecode_0 = 3, .etype_0 = ((NU32)0u)}}
    ;
    (*X60Qlhs_12) = X60Qtmp_13;}
  else {
    X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v** X60Qlhs_14 = (&(*v_12).ov_0);
    void* X60Qx_83 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v));
    X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* X60Qtmp_16 = ((X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v*)X60Qx_83);
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_84 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*(*v_12).ov_0).d_00.arrOwn_0);
    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_85 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*(*v_12).ov_0).d_00.seqOwn_0);
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_86 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*(*v_12).ov_0).d_00.region_0);
    (*X60Qtmp_16) = (X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v){
      .r_00 = 0, .d_00 = (PtrOv_Obj_0_valzr1t4f){
        .arrOwn_0 = X60Qx_84, .seqOwn_0 = X60Qx_85, .base_0 = (*(*v_12).ov_0).d_00.base_0, .region_0 = X60Qx_86, .foff_0 = (*(*v_12).ov_0).d_00.foff_0, .elemBits_0 = (*(*v_12).ov_0).d_00.elemBits_0, .ecode_0 = (*(*v_12).ov_0).d_00.ecode_0, .etype_0 = (*(*v_12).ov_0).d_00.etype_0}}
    ;
    X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* X60Qlhs_15 = X60Qtmp_16;
    eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((*X60Qlhs_14));
    (*X60Qlhs_14) = X60Qlhs_15;}
  eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(result_30);
  X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* X60Qx_87 = eQdupQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((*v_12).ov_0);
  result_30 = X60Qx_87;
  return result_30;}
static inline NI32 resume_0_valzr1t4f(Value_0_valzr1t4f* v_14){
  NI32 result_32;
  result_32 = ((NI32)(*v_14).resumeRaw_0);
  return result_32;}
static inline void setResume_0_valzr1t4f(Value_0_valzr1t4f* v_15, NI32 n_0){
  (*v_15).resumeRaw_0 = ((NI32)n_0);}
static inline Value_0_valzr1t4f vProc_0_valzr1t4f(NU32 fn_0, NI32 pidx_0, X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* env_0, NI32 resume_0){
  Value_0_valzr1t4f result_33;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_33));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_33));
  X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* X60Qx_88 = eQdupQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(env_0);
  result_33 = (Value_0_valzr1t4f){
    .kind_0 = 15, .env_0 = X60Qx_88, .fn_0 = fn_0, .pidxRaw_0 = ((NI32)pidx_0), .resumeRaw_0 = ((NI32)resume_0)}
  ;
  return result_33;}
Value_0_valzr1t4f vFloat_0_valzr1t4f(NF64 f_0, NI32 bits_4){
  Value_0_valzr1t4f result_34;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_34));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_34));
  result_34 = (Value_0_valzr1t4f){
    .kind_0 = 3, .fval_0 = f_0, .fbits_0 = bits_4}
  ;
  return result_34;}
Value_0_valzr1t4f vEnum_0_valzr1t4f(NI32 ord_0, NU32 ekind_0){
  Value_0_valzr1t4f result_35;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_35));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_35));
  result_35 = (Value_0_valzr1t4f){
    .kind_0 = 7, .eord_0 = ord_0, .ekind_0 = ekind_0}
  ;
  return result_35;}
string_0_sysvq0asl enumDisplay_0_valzr1t4f(Value_0_valzr1t4f* v_16){
  string_0_sysvq0asl result_36;
  nimStrWasMoved((&result_36));
  nimStrDestroy(result_36);
  result_36 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((!((*v_16).kind_0 == 7))){
    return result_36;}
  if (((NU32)(*v_16).ekind_0) == ((NU32)0u)){
    return result_36;}
  if ((!(((void*)enumNamerHook_0_valzr1t4f) == NIM_NIL))){
    nimStrDestroy(result_36);
    string_0_sysvq0asl X60Qx_89 = enumNamerHook_0_valzr1t4f((*v_16).ekind_0, (*v_16).eord_0);
    result_36 = X60Qx_89;}
  NI32 X60Qx_90 = len_4_sysvq0asl(result_36);
  if (X60Qx_90 == 0){
    nimStrDestroy(result_36);
    string_0_sysvq0asl* X60Qx_91 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*v_16).ekind_0);
    string_0_sysvq0asl X60Qx_92 = nimStrDup((*X60Qx_91));
    result_36 = X60Qx_92;
    extractBasename_1_symkyk35i1((&result_36));}
  return result_36;}
NI64 asInt_0_valzr1t4f(Value_0_valzr1t4f* v_17){
  NI64 result_37;
  switch ((*v_17).kind_0){
    case 1:
    {
      NB8 err_0 = NIM_FALSE;
      NI64 X60Qx_93 = asSigned_0_xinat3x34((*v_17).ival_0, (&err_0));
      result_37 = X60Qx_93;}
    break;
    case 2:
    {
      NB8 err_1 = NIM_FALSE;
      NU64 X60Qx_94 = asUnsigned_0_xinat3x34((*v_17).ival_0, (&err_1));
      result_37 = ((NI64)X60Qx_94);}
    break;
    case 5:
    {
      result_37 = ((NI64)((NI32)(*v_17).cval_0));}
    break;
    case 4:
    {
      NI64 X60Qx_11;
      if ((*v_17).bval_0){
        X60Qx_11 = ((NI64)1);}
      else {
        X60Qx_11 = ((NI64)0);}
      result_37 = X60Qx_11;}
    break;
    case 7:
    {
      result_37 = ((NI64)(*v_17).eord_0);}
    break;
    default:
    {
      result_37 = ((NI64)0);}
    break;}
  return result_37;}
NB8 truthy_0_valzr1t4f(Value_0_valzr1t4f* v_18){
  NB8 result_38;
  NB8 X60Qx_12;
  switch ((*v_18).kind_0){
    case 4:
    {
      X60Qx_12 = (*v_18).bval_0;}
    break;
    case 1:
    case 2:
    {
      xint_0_xinat3x34 X60Qx_95 = zero_0_xinat3x34();
      NB8 X60Qx_96 = eqQ_0_xinat3x34((*v_18).ival_0, X60Qx_95);
      X60Qx_12 = (!X60Qx_96);}
    break;
    case 0:
    {
      X60Qx_12 = NIM_FALSE;}
    break;
    default:
    {
      X60Qx_12 = NIM_TRUE;}
    break;}
  result_38 = X60Qx_12;
  return result_38;}
string_0_sysvq0asl dollarQ_0_valzr1t4f(Value_0_valzr1t4f* v_19){
  string_0_sysvq0asl result_39;
  nimStrWasMoved((&result_39));
  switch ((*v_19).kind_0){
    case 0:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
      ;}
    break;
    case 1:
    {
      NB8 err_2 = NIM_FALSE;
      nimStrDestroy(result_39);
      NI64 X60Qx_97 = asSigned_0_xinat3x34((*v_19).ival_0, (&err_2));
      string_0_sysvq0asl X60Qx_98 = itoa_0_valzr1t4f(X60Qx_97);
      result_39 = X60Qx_98;}
    break;
    case 2:
    {
      NB8 err_3 = NIM_FALSE;
      nimStrDestroy(result_39);
      NU64 X60Qx_99 = asUnsigned_0_xinat3x34((*v_19).ival_0, (&err_3));
      string_0_sysvq0asl X60Qx_100 = utoa_0_valzr1t4f(X60Qx_99);
      result_39 = X60Qx_100;}
    break;
    case 3:
    {
      nimStrDestroy(result_39);
      string_0_sysvq0asl X60Qx_101 = dollarQ_7_sysvq0asl((*v_19).fval_0);
      result_39 = X60Qx_101;}
    break;
    case 4:
    {
      string_0_sysvq0asl X60Qx_13;
      nimStrWasMoved((&X60Qx_13));
      if ((*v_19).bval_0){
        nimStrDestroy(X60Qx_13);
        X60Qx_13 = (string_0_sysvq0asl){
          .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I8572766038233537570_emi78vuj01)}
        ;}
      else {
        nimStrDestroy(X60Qx_13);
        X60Qx_13 = (string_0_sysvq0asl){
          .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I3372626016653902757_emi78vuj01)}
        ;}
      nimStrDestroy(result_39);
      result_39 = X60Qx_13;
      nimStrWasMoved((&X60Qx_13));
      nimStrDestroy(X60Qx_13);}
    break;
    case 5:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      add_1_sysvq0asl((&result_39), (*v_19).cval_0);}
    break;
    case 6:
    {
      nimStrDestroy(result_39);
      string_0_sysvq0asl X60Qx_102 = nimStrDup((*v_19).sval_0);
      result_39 = X60Qx_102;}
    break;
    case 7:
    {
      string_0_sysvq0asl nm_0 = enumDisplay_0_valzr1t4f((&(*v_19)));
      NI32 X60Qx_103 = len_4_sysvq0asl(nm_0);
      if (0 < X60Qx_103){
        nimStrDestroy(result_39);
        result_39 = nm_0;
        nimStrWasMoved((&nm_0));}
      else {
        nimStrDestroy(result_39);
        string_0_sysvq0asl X60Qtmp_17 = itoa_0_valzr1t4f(((NI64)(*v_19).eord_0));
        string_0_sysvq0asl X60Qx_104 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I8350635790867353280_valzr1t4f)}
        , X60Qtmp_17);
        result_39 = X60Qx_104;
        nimStrDestroy(X60Qtmp_17);}
      nimStrDestroy(nm_0);}
    break;
    case 8:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 5980162u, .more_0 = NIM_NIL}
      ;
      NI32 i_8 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_105 = len_3_I83dzei_arecyyj7v((*(*v_19).sq_0).d_00.elems_0);
          if (i_8 < X60Qx_105){
            if (0 < i_8){
              add_2_sysvq0asl((&result_39), (string_0_sysvq0asl){
                .bytes_0 = 2108418u, .more_0 = NIM_NIL}
              );}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_106 = getQ_7_Ii14ync1_arecyyj7v((*(*v_19).sq_0).d_00.elems_0, i_8);
            string_0_sysvq0asl X60Qtmp_18 = dollarQ_0_valzr1t4f((&(*(*X60Qx_106)).d_00.v_0));
            add_2_sysvq0asl((&result_39), X60Qtmp_18);
            inc_1_I6wjjge_aow2h993l1((&i_8));
            nimStrDestroy(X60Qtmp_18);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      add_2_sysvq0asl((&result_39), (string_0_sysvq0asl){
        .bytes_0 = 23809u, .more_0 = NIM_NIL}
      );}
    break;
    case 9:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 23297u, .more_0 = NIM_NIL}
      ;
      NI32 i_9 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_107 = len_3_I83dzei_arecyyj7v((*(*v_19).arr_0).d_00.elems_0);
          if (i_9 < X60Qx_107){
            if (0 < i_9){
              add_2_sysvq0asl((&result_39), (string_0_sysvq0asl){
                .bytes_0 = 2108418u, .more_0 = NIM_NIL}
              );}
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_108 = getQ_7_Ii14ync1_arecyyj7v((*(*v_19).arr_0).d_00.elems_0, i_9);
            string_0_sysvq0asl X60Qtmp_19 = dollarQ_0_valzr1t4f((&(*(*X60Qx_108)).d_00.v_0));
            add_2_sysvq0asl((&result_39), X60Qtmp_19);
            inc_1_I6wjjge_aow2h993l1((&i_9));
            nimStrDestroy(X60Qtmp_19);}
          else {
            break;}}}
      whileStmtLabel_1: ;
      add_2_sysvq0asl((&result_39), (string_0_sysvq0asl){
        .bytes_0 = 23809u, .more_0 = NIM_NIL}
      );}
    break;
    case 10:
    case 11:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 1651452158u, .more_0 = (&strlit_0_I13499555360605886803_valzr1t4f)}
      ;}
    break;
    case 12:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
      ;}
    break;
    case 13:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
      ;}
    break;
    case 14:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 1702067198u, .more_0 = (&strlit_0_I1708568703999513659_valzr1t4f)}
      ;}
    break;
    case 15:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I5316556160589403975_emi78vuj01)}
      ;}
    break;
    case 17:
    {
      nimStrDestroy(result_39);
      result_39 = (string_0_sysvq0asl){
        .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I17682010759162773284_valzr1t4f)}
      ;}
    break;
    case 16:
    {
      string_0_sysvq0asl X60Qx_14;
      nimStrWasMoved((&X60Qx_14));
      if ((*v_19).toErr_0){
        nimStrDestroy(X60Qx_14);
        X60Qx_14 = (string_0_sysvq0asl){
          .bytes_0 = 1685353470u, .more_0 = (&strlit_0_I9873340078075426535_intzsnzax)}
        ;}
      else {
        nimStrDestroy(X60Qx_14);
        X60Qx_14 = (string_0_sysvq0asl){
          .bytes_0 = 1685353470u, .more_0 = (&strlit_0_I1990248930136438291_intzsnzax)}
        ;}
      nimStrDestroy(result_39);
      result_39 = X60Qx_14;
      nimStrWasMoved((&X60Qx_14));
      nimStrDestroy(X60Qx_14);}
    break;}
  return result_39;}
string_0_sysvq0asl fieldBasename_0_valzr1t4f(NU32 s_2){
  string_0_sysvq0asl result_40;
  nimStrWasMoved((&result_40));
  NB8 X60Qx_109 = eqQ_0_nifh7u8pu1(s_2, ((NU32)0u));
  if (X60Qx_109){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_40);
  string_0_sysvq0asl* X60Qx_110 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_2);
  string_0_sysvq0asl X60Qx_111 = nimStrDup((*X60Qx_110));
  result_40 = X60Qx_111;
  extractBasename_1_symkyk35i1((&result_40));
  return result_40;}
NB8 seenHas_0_valzr1t4f(seq_0_Igsxz3n_arecyyj7v seen_0, NU32 key_0){
  NB8 result_41;
  {
    openArray_0_Iptmq8f_valzr1t4f X60Qlf_0 = toOpenArray_1_Iy9e09m1_valzr1t4f(seen_0);
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_112 = len_6_Iql6z121_valzr1t4f(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_112){
          {
            NU32* X60Qii_2 = getQ_10_Isxag051_valzr1t4f(X60Qlf_0, X60Qlf_1);
            if ((*X60Qii_2) == key_0){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  result_41 = NIM_FALSE;
  return result_41;}
void popSeen_0_valzr1t4f(seq_0_Igsxz3n_arecyyj7v* seen_1){
  if (0 < (*seen_1).len_0){
    NI32 X60Qx_113 = len_3_I3cga53_arecyyj7v((*seen_1));
    setLen_0_Iqjrd6x1_valzr1t4f(seen_1, ((NI32)(X60Qx_113 - 1)));}}
string_0_sysvq0asl capString_0_valzr1t4f(string_0_sysvq0asl s_3){
  string_0_sysvq0asl result_42;
  nimStrWasMoved((&result_42));
  NI32 X60Qx_114 = len_4_sysvq0asl(s_3);
  if (X60Qx_114 <= ((NI32)120)){
    string_0_sysvq0asl X60Qx_115 = nimStrDup(s_3);
    return X60Qx_115;}
  NI32 keep_0 = ((NI32)(((NI32)120) / 2));
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_116 = __ltQ_1_Ij9jwi_dbgj4vyzj1(0, keep_0);
  string_0_sysvq0asl X60Qdesugar_0 = getQ_14_sysvq0asl(s_3, X60Qx_116);
  NI32 X60Qx_117 = len_4_sysvq0asl(s_3);
  string_0_sysvq0asl X60Qdesugar_1 = itoa_0_valzr1t4f(((NI64)X60Qx_117));
  NI32 X60Qx_118 = len_4_sysvq0asl(s_3);
  NI32 X60Qx_119 = len_4_sysvq0asl(s_3);
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_120 = __ltQ_1_Ij9jwi_dbgj4vyzj1(((NI32)(X60Qx_118 - keep_0)), X60Qx_119);
  string_0_sysvq0asl X60Qdesugar_2 = getQ_14_sysvq0asl(s_3, X60Qx_120);
  NI32 X60Qx_121 = len_4_sysvq0asl(X60Qdesugar_0);
  NI32 X60Qx_122 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I17892332096354785130_valzr1t4f)}
  );
  NI32 X60Qx_123 = len_4_sysvq0asl(X60Qdesugar_1);
  NI32 X60Qx_124 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1751326974u, .more_0 = (&strlit_0_I15811569221951826670_valzr1t4f)}
  );
  NI32 X60Qx_125 = len_4_sysvq0asl(X60Qdesugar_2);
  string_0_sysvq0asl X60Qdesugar_3 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_121 + X60Qx_122)) + X60Qx_123)) + X60Qx_124)) + X60Qx_125)));
  add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_0);
  add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
    .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I17892332096354785130_valzr1t4f)}
  );
  add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_1);
  add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
    .bytes_0 = 1751326974u, .more_0 = (&strlit_0_I15811569221951826670_valzr1t4f)}
  );
  add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_2);
  nimStrDestroy(result_42);
  result_42 = X60Qdesugar_3;
  nimStrWasMoved((&X60Qdesugar_3));
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(X60Qdesugar_1);
  nimStrDestroy(X60Qdesugar_0);
  return result_42;
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(X60Qdesugar_1);
  nimStrDestroy(X60Qdesugar_0);
  return result_42;}
string_0_sysvq0asl renderObjReadable_0_valzr1t4f(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* obj_0, NI32 depth_1, seq_0_Igsxz3n_arecyyj7v* seen_3, NI32* budget_1){
  string_0_sysvq0asl result_43;
  nimStrWasMoved((&result_43));
  if (obj_0 == NIM_NIL){
    return (string_0_sysvq0asl){
      .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl head_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_126 = eqQ_0_nifh7u8pu1((*obj_0).d_00.typeSym_0, ((NU32)0u));
  if ((!X60Qx_126)){
    nimStrDestroy(head_0);
    string_0_sysvq0asl X60Qx_127 = fieldBasename_0_valzr1t4f((*obj_0).d_00.typeSym_0);
    head_0 = X60Qx_127;}
  nimStrDestroy(result_43);
  string_0_sysvq0asl X60Qx_128 = ampQ_0_sysvq0asl(head_0, (string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  result_43 = X60Qx_128;
  NI32 X60Qx_129 = len_4_sysvq0asl(result_43);
  dec_0_Ig5i8xp_nifb6mq6y1(budget_1, X60Qx_129);
  NI32 i_10 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_130 = len_3_I83dzei_arecyyj7v((*obj_0).d_00.cells_0);
      if (i_10 < X60Qx_130){
        if ((*budget_1) <= 0){
          NI32 X60Qx_131 = len_3_I83dzei_arecyyj7v((*obj_0).d_00.cells_0);
          string_0_sysvq0asl X60Qdesugar_4 = itoa_0_valzr1t4f(((NI64)((NI32)(X60Qx_131 - i_10))));
          NI32 X60Qx_132 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2793464574u, .more_0 = (&strlit_0_I7590662755332226574_valzr1t4f)}
          );
          NI32 X60Qx_133 = len_4_sysvq0asl(X60Qdesugar_4);
          NI32 X60Qx_134 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1768300798u, .more_0 = (&strlit_0_I16360096150727577611_valzr1t4f)}
          );
          string_0_sysvq0asl X60Qdesugar_5 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_132 + X60Qx_133)) + X60Qx_134)));
          add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
            .bytes_0 = 2793464574u, .more_0 = (&strlit_0_I7590662755332226574_valzr1t4f)}
          );
          add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_4);
          add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
            .bytes_0 = 1768300798u, .more_0 = (&strlit_0_I16360096150727577611_valzr1t4f)}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_5);
          nimStrDestroy(X60Qdesugar_5);
          nimStrDestroy(X60Qdesugar_4);
          goto whileStmtLabel_0;
          nimStrDestroy(X60Qdesugar_5);
          nimStrDestroy(X60Qdesugar_4);}
        if (((NI32)24) <= i_10){
          NI32 X60Qx_135 = len_3_I83dzei_arecyyj7v((*obj_0).d_00.cells_0);
          string_0_sysvq0asl X60Qdesugar_6 = itoa_0_valzr1t4f(((NI64)((NI32)(X60Qx_135 - i_10))));
          NI32 X60Qx_136 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 3793759486u, .more_0 = (&strlit_0_I10817201013825926720_dbgj4vyzj1)}
          );
          NI32 X60Qx_137 = len_4_sysvq0asl(X60Qdesugar_6);
          NI32 X60Qx_138 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I734781229358173569_dbgj4vyzj1)}
          );
          string_0_sysvq0asl X60Qdesugar_7 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_136 + X60Qx_137)) + X60Qx_138)));
          add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
            .bytes_0 = 3793759486u, .more_0 = (&strlit_0_I10817201013825926720_dbgj4vyzj1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_6);
          add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
            .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I734781229358173569_dbgj4vyzj1)}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_7);
          nimStrDestroy(X60Qdesugar_7);
          nimStrDestroy(X60Qdesugar_6);
          goto whileStmtLabel_0;
          nimStrDestroy(X60Qdesugar_7);
          nimStrDestroy(X60Qdesugar_6);}
        if (0 < i_10){
          add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
            .bytes_0 = 2108418u, .more_0 = NIM_NIL}
          );
          dec_0_Ig5i8xp_nifb6mq6y1(budget_1, 2);}
        NI32 X60Qx_139 = len_3_I6y2imo_arecyyj7v((*obj_0).d_00.names_0);
        if (i_10 < X60Qx_139){
          NU32* X60Qx_140 = getQ_7_I2v00yv1_arecyyj7v((*obj_0).d_00.names_0, i_10);
          string_0_sysvq0asl fname_0 = fieldBasename_0_valzr1t4f((*X60Qx_140));
          NI32 X60Qx_141 = len_4_sysvq0asl(fname_0);
          if (0 < X60Qx_141){
            add_2_sysvq0asl((&result_43), fname_0);
            add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
              .bytes_0 = 2112002u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_142 = len_4_sysvq0asl(fname_0);
            dec_0_Ig5i8xp_nifb6mq6y1(budget_1, ((NI32)(X60Qx_142 + 2)));}
          nimStrDestroy(fname_0);}
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_143 = getQ_7_Ii14ync1_arecyyj7v((*obj_0).d_00.cells_0, i_10);
        if ((!((*X60Qx_143) == NIM_NIL))){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_144 = getQ_7_Ii14ync1_arecyyj7v((*obj_0).d_00.cells_0, i_10);
          string_0_sysvq0asl X60Qtmp_20 = renderReadable_1_valzr1t4f((&(*(*X60Qx_144)).d_00.v_0), ((NI32)(depth_1 - 1)), seen_3, budget_1);
          add_2_sysvq0asl((&result_43), X60Qtmp_20);
          nimStrDestroy(X60Qtmp_20);}
        else {
          add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
            .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
          );}
        inc_1_I6wjjge_aow2h993l1((&i_10));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(head_0);
  return result_43;
  nimStrDestroy(head_0);
  return result_43;}
string_0_sysvq0asl renderReadable_1_valzr1t4f(Value_0_valzr1t4f* v_21, NI32 depth_2, seq_0_Igsxz3n_arecyyj7v* seen_4, NI32* budget_2){
  string_0_sysvq0asl result_44;
  nimStrWasMoved((&result_44));
  switch ((*v_21).kind_0){
    case 6:
    {
      nimStrDestroy(result_44);
      string_0_sysvq0asl X60Qx_145 = capString_0_valzr1t4f((*v_21).sval_0);
      result_44 = X60Qx_145;
      NI32 X60Qx_146 = len_4_sysvq0asl(result_44);
      dec_0_Ig5i8xp_nifb6mq6y1(budget_2, X60Qx_146);}
    break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 14:
    case 15:
    case 17:
    case 16:
    {
      nimStrDestroy(result_44);
      string_0_sysvq0asl X60Qx_147 = dollarQ_0_valzr1t4f((&(*v_21)));
      result_44 = X60Qx_147;
      NI32 X60Qx_148 = len_4_sysvq0asl(result_44);
      dec_0_Ig5i8xp_nifb6mq6y1(budget_2, X60Qx_148);}
    break;
    case 8:
    {
      NB8 X60Qx_149;
      if (depth_2 <= 0){
        X60Qx_149 = NIM_TRUE;}
      else {
        X60Qx_149 = ((*v_21).sq_0 == NIM_NIL);}
      if (X60Qx_149){
        nimStrDestroy(result_44);
        result_44 = (string_0_sysvq0asl){
          .bytes_0 = 3797631230u, .more_0 = (&strlit_0_I8898202128342635644_valzr1t4f)}
        ;}
      else {
        nimStrDestroy(result_44);
        result_44 = (string_0_sysvq0asl){
          .bytes_0 = 5980162u, .more_0 = NIM_NIL}
        ;
        dec_0_Ig5i8xp_nifb6mq6y1(budget_2, 2);
        NI32 i_12 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_150 = len_3_I83dzei_arecyyj7v((*(*v_21).sq_0).d_00.elems_0);
            if (i_12 < X60Qx_150){
              if ((*budget_2) <= 0){
                NI32 X60Qx_151 = len_3_I83dzei_arecyyj7v((*(*v_21).sq_0).d_00.elems_0);
                string_0_sysvq0asl X60Qdesugar_8 = itoa_0_valzr1t4f(((NI64)((NI32)(X60Qx_151 - i_12))));
                NI32 X60Qx_152 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 2793464574u, .more_0 = (&strlit_0_I7590662755332226574_valzr1t4f)}
                );
                NI32 X60Qx_153 = len_4_sysvq0asl(X60Qdesugar_8);
                NI32 X60Qx_154 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1652238846u, .more_0 = (&strlit_0_I15433588765009474833_valzr1t4f)}
                );
                string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_152 + X60Qx_153)) + X60Qx_154)));
                add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
                  .bytes_0 = 2793464574u, .more_0 = (&strlit_0_I7590662755332226574_valzr1t4f)}
                );
                add_2_sysvq0asl((&X60Qdesugar_9), X60Qdesugar_8);
                add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
                  .bytes_0 = 1652238846u, .more_0 = (&strlit_0_I15433588765009474833_valzr1t4f)}
                );
                add_2_sysvq0asl((&result_44), X60Qdesugar_9);
                nimStrDestroy(X60Qdesugar_9);
                nimStrDestroy(X60Qdesugar_8);
                goto whileStmtLabel_0;
                nimStrDestroy(X60Qdesugar_9);
                nimStrDestroy(X60Qdesugar_8);}
              if (((NI32)24) <= i_12){
                NI32 X60Qx_155 = len_3_I83dzei_arecyyj7v((*(*v_21).sq_0).d_00.elems_0);
                string_0_sysvq0asl X60Qdesugar_10 = itoa_0_valzr1t4f(((NI64)((NI32)(X60Qx_155 - i_12))));
                NI32 X60Qx_156 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 3793759486u, .more_0 = (&strlit_0_I10817201013825926720_dbgj4vyzj1)}
                );
                NI32 X60Qx_157 = len_4_sysvq0asl(X60Qdesugar_10);
                NI32 X60Qx_158 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I734781229358173569_dbgj4vyzj1)}
                );
                string_0_sysvq0asl X60Qdesugar_11 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_156 + X60Qx_157)) + X60Qx_158)));
                add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
                  .bytes_0 = 3793759486u, .more_0 = (&strlit_0_I10817201013825926720_dbgj4vyzj1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_11), X60Qdesugar_10);
                add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
                  .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I734781229358173569_dbgj4vyzj1)}
                );
                add_2_sysvq0asl((&result_44), X60Qdesugar_11);
                nimStrDestroy(X60Qdesugar_11);
                nimStrDestroy(X60Qdesugar_10);
                goto whileStmtLabel_0;
                nimStrDestroy(X60Qdesugar_11);
                nimStrDestroy(X60Qdesugar_10);}
              if (0 < i_12){
                add_2_sysvq0asl((&result_44), (string_0_sysvq0asl){
                  .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                );
                dec_0_Ig5i8xp_nifb6mq6y1(budget_2, 2);}
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_159 = getQ_7_Ii14ync1_arecyyj7v((*(*v_21).sq_0).d_00.elems_0, i_12);
              string_0_sysvq0asl X60Qtmp_21 = renderReadable_1_valzr1t4f((&(*(*X60Qx_159)).d_00.v_0), ((NI32)(depth_2 - 1)), seen_4, budget_2);
              add_2_sysvq0asl((&result_44), X60Qtmp_21);
              inc_1_I6wjjge_aow2h993l1((&i_12));
              nimStrDestroy(X60Qtmp_21);}
            else {
              break;}}}
        whileStmtLabel_0: ;
        add_2_sysvq0asl((&result_44), (string_0_sysvq0asl){
          .bytes_0 = 23809u, .more_0 = NIM_NIL}
        );}}
    break;
    case 9:
    {
      NB8 X60Qx_160;
      if (depth_2 <= 0){
        X60Qx_160 = NIM_TRUE;}
      else {
        X60Qx_160 = ((*v_21).arr_0 == NIM_NIL);}
      if (X60Qx_160){
        nimStrDestroy(result_44);
        result_44 = (string_0_sysvq0asl){
          .bytes_0 = 2162318334u, .more_0 = (&strlit_0_I7681136583982100770_valzr1t4f)}
        ;}
      else {
        nimStrDestroy(result_44);
        result_44 = (string_0_sysvq0asl){
          .bytes_0 = 23297u, .more_0 = NIM_NIL}
        ;
        dec_0_Ig5i8xp_nifb6mq6y1(budget_2, 1);
        NI32 i_13 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_161 = len_3_I83dzei_arecyyj7v((*(*v_21).arr_0).d_00.elems_0);
            if (i_13 < X60Qx_161){
              if ((*budget_2) <= 0){
                NI32 X60Qx_162 = len_3_I83dzei_arecyyj7v((*(*v_21).arr_0).d_00.elems_0);
                string_0_sysvq0asl X60Qdesugar_12 = itoa_0_valzr1t4f(((NI64)((NI32)(X60Qx_162 - i_13))));
                NI32 X60Qx_163 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 2793464574u, .more_0 = (&strlit_0_I7590662755332226574_valzr1t4f)}
                );
                NI32 X60Qx_164 = len_4_sysvq0asl(X60Qdesugar_12);
                NI32 X60Qx_165 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1652238846u, .more_0 = (&strlit_0_I15433588765009474833_valzr1t4f)}
                );
                string_0_sysvq0asl X60Qdesugar_13 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_163 + X60Qx_164)) + X60Qx_165)));
                add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
                  .bytes_0 = 2793464574u, .more_0 = (&strlit_0_I7590662755332226574_valzr1t4f)}
                );
                add_2_sysvq0asl((&X60Qdesugar_13), X60Qdesugar_12);
                add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
                  .bytes_0 = 1652238846u, .more_0 = (&strlit_0_I15433588765009474833_valzr1t4f)}
                );
                add_2_sysvq0asl((&result_44), X60Qdesugar_13);
                nimStrDestroy(X60Qdesugar_13);
                nimStrDestroy(X60Qdesugar_12);
                goto whileStmtLabel_1;
                nimStrDestroy(X60Qdesugar_13);
                nimStrDestroy(X60Qdesugar_12);}
              if (((NI32)24) <= i_13){
                NI32 X60Qx_166 = len_3_I83dzei_arecyyj7v((*(*v_21).arr_0).d_00.elems_0);
                string_0_sysvq0asl X60Qdesugar_14 = itoa_0_valzr1t4f(((NI64)((NI32)(X60Qx_166 - i_13))));
                NI32 X60Qx_167 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 3793759486u, .more_0 = (&strlit_0_I10817201013825926720_dbgj4vyzj1)}
                );
                NI32 X60Qx_168 = len_4_sysvq0asl(X60Qdesugar_14);
                NI32 X60Qx_169 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I734781229358173569_dbgj4vyzj1)}
                );
                string_0_sysvq0asl X60Qdesugar_15 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_167 + X60Qx_168)) + X60Qx_169)));
                add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
                  .bytes_0 = 3793759486u, .more_0 = (&strlit_0_I10817201013825926720_dbgj4vyzj1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_14);
                add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
                  .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I734781229358173569_dbgj4vyzj1)}
                );
                add_2_sysvq0asl((&result_44), X60Qdesugar_15);
                nimStrDestroy(X60Qdesugar_15);
                nimStrDestroy(X60Qdesugar_14);
                goto whileStmtLabel_1;
                nimStrDestroy(X60Qdesugar_15);
                nimStrDestroy(X60Qdesugar_14);}
              if (0 < i_13){
                add_2_sysvq0asl((&result_44), (string_0_sysvq0asl){
                  .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                );
                dec_0_Ig5i8xp_nifb6mq6y1(budget_2, 2);}
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_170 = getQ_7_Ii14ync1_arecyyj7v((*(*v_21).arr_0).d_00.elems_0, i_13);
              string_0_sysvq0asl X60Qtmp_22 = renderReadable_1_valzr1t4f((&(*(*X60Qx_170)).d_00.v_0), ((NI32)(depth_2 - 1)), seen_4, budget_2);
              add_2_sysvq0asl((&result_44), X60Qtmp_22);
              inc_1_I6wjjge_aow2h993l1((&i_13));
              nimStrDestroy(X60Qtmp_22);}
            else {
              break;}}}
        whileStmtLabel_1: ;
        add_2_sysvq0asl((&result_44), (string_0_sysvq0asl){
          .bytes_0 = 23809u, .more_0 = NIM_NIL}
        );}}
    break;
    case 10:
    case 11:
    {
      if (depth_2 <= 0){
        nimStrDestroy(result_44);
        result_44 = (string_0_sysvq0asl){
          .bytes_0 = 2162305278u, .more_0 = (&strlit_0_I8973501876771101138_valzr1t4f)}
        ;}
      else {
        nimStrDestroy(result_44);
        string_0_sysvq0asl X60Qx_171 = renderObjReadable_0_valzr1t4f((*v_21).obj_0, depth_2, seen_4, budget_2);
        result_44 = X60Qx_171;}}
    break;
    case 12:
    {
      if ((*v_21).rf_0 == NIM_NIL){
        nimStrDestroy(result_44);
        result_44 = (string_0_sysvq0asl){
          .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
        ;}
      else {
        NU32 key_1 = ((NU32)((void*)(*v_21).rf_0));
        NB8 X60Qx_172 = seenHas_0_valzr1t4f((*seen_4), key_1);
        if (X60Qx_172){
          nimStrDestroy(result_44);
          result_44 = (string_0_sysvq0asl){
            .bytes_0 = 2036546814u, .more_0 = (&strlit_0_I14068598100739118063_valzr1t4f)}
          ;}
        else {
          if (depth_2 <= 0){
            nimStrDestroy(result_44);
            result_44 = (string_0_sysvq0asl){
              .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I11598900929015759369_valzr1t4f)}
            ;}
          else {
            add_0_Iwsr3ai_arecyyj7v(seen_4, key_1);
            nimStrDestroy(result_44);
            string_0_sysvq0asl X60Qx_173 = renderReadable_1_valzr1t4f((&(*(*v_21).rf_0).d_00.v_0), ((NI32)(depth_2 - 1)), seen_4, budget_2);
            result_44 = X60Qx_173;
            popSeen_0_valzr1t4f(seen_4);}}}}
    break;
    case 13:
    {
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_23 = region_0_valzr1t4f((&(*v_21)));
      if ((!(X60Qtmp_23 == NIM_NIL))){
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_24 = region_0_valzr1t4f((&(*v_21)));
        switch ((*X60Qtmp_24).d_00.kind_0){
          case 6:
          {
            X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_25 = region_0_valzr1t4f((&(*v_21)));
            if ((*X60Qtmp_25).d_00.haddr_0 == ((NU64)0u)){
              nimStrDestroy(result_44);
              result_44 = (string_0_sysvq0asl){
                .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
              ;}
            else {
              X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_26 = region_0_valzr1t4f((&(*v_21)));
              string_0_sysvq0asl X60Qdesugar_16 = hexu_0_valzr1t4f((*X60Qtmp_26).d_00.haddr_0);
              NI32 X60Qx_174 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1868971262u, .more_0 = (&strlit_0_I934609865401688195_valzr1t4f)}
              );
              NI32 X60Qx_175 = len_4_sysvq0asl(X60Qdesugar_16);
              NI32 X60Qx_176 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 15873u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_17 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_174 + X60Qx_175)) + X60Qx_176)));
              add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
                .bytes_0 = 1868971262u, .more_0 = (&strlit_0_I934609865401688195_valzr1t4f)}
              );
              add_2_sysvq0asl((&X60Qdesugar_17), X60Qdesugar_16);
              add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
                .bytes_0 = 15873u, .more_0 = NIM_NIL}
              );
              nimStrDestroy(result_44);
              result_44 = X60Qdesugar_17;
              nimStrWasMoved((&X60Qdesugar_17));
              nimStrDestroy(X60Qdesugar_17);
              nimStrDestroy(X60Qdesugar_16);
              eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qtmp_26);}
            eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qtmp_25);}
          break;
          default:
          {
            X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_27 = region_0_valzr1t4f((&(*v_21)));
            string_0_sysvq0asl X60Qdesugar_18 = dollarX60Q_RegionKind_0_valzr1t4f((*X60Qtmp_27).d_00.kind_0);
            NI32 X60Qx_177 = foff_0_valzr1t4f((&(*v_21)));
            string_0_sysvq0asl X60Qdesugar_19 = itoa_0_valzr1t4f(((NI64)X60Qx_177));
            NI32 X60Qx_178 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1769356542u, .more_0 = (&strlit_0_I11501170429003019622_valzr1t4f)}
            );
            NI32 X60Qx_179 = len_4_sysvq0asl(X60Qdesugar_18);
            NI32 X60Qx_180 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 11009u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_181 = len_4_sysvq0asl(X60Qdesugar_19);
            NI32 X60Qx_182 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 15873u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_20 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_178 + X60Qx_179)) + X60Qx_180)) + X60Qx_181)) + X60Qx_182)));
            add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
              .bytes_0 = 1769356542u, .more_0 = (&strlit_0_I11501170429003019622_valzr1t4f)}
            );
            add_2_sysvq0asl((&X60Qdesugar_20), X60Qdesugar_18);
            add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
              .bytes_0 = 11009u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_20), X60Qdesugar_19);
            add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
              .bytes_0 = 15873u, .more_0 = NIM_NIL}
            );
            nimStrDestroy(result_44);
            result_44 = X60Qdesugar_20;
            nimStrWasMoved((&X60Qdesugar_20));
            nimStrDestroy(X60Qdesugar_20);
            nimStrDestroy(X60Qdesugar_19);
            nimStrDestroy(X60Qdesugar_18);
            eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qtmp_27);}
          break;}
        NI32 X60Qx_183 = len_4_sysvq0asl(result_44);
        dec_0_Ig5i8xp_nifb6mq6y1(budget_2, X60Qx_183);
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qtmp_24);}
      else {
        if ((*v_21).loc_0 == NIM_NIL){
          nimStrDestroy(result_44);
          result_44 = (string_0_sysvq0asl){
            .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
          ;}
        else {
          NU32 key_2 = ((NU32)((void*)(*v_21).loc_0));
          NB8 X60Qx_184 = seenHas_0_valzr1t4f((*seen_4), key_2);
          if (X60Qx_184){
            nimStrDestroy(result_44);
            result_44 = (string_0_sysvq0asl){
              .bytes_0 = 2036546814u, .more_0 = (&strlit_0_I14068598100739118063_valzr1t4f)}
            ;}
          else {
            if (depth_2 <= 0){
              nimStrDestroy(result_44);
              result_44 = (string_0_sysvq0asl){
                .bytes_0 = 1920233726u, .more_0 = (&strlit_0_I1095046037665756977_valzr1t4f)}
              ;}
            else {
              add_0_Iwsr3ai_arecyyj7v(seen_4, key_2);
              nimStrDestroy(result_44);
              string_0_sysvq0asl X60Qx_185 = renderReadable_1_valzr1t4f((&(*(*v_21).loc_0).d_00.v_0), ((NI32)(depth_2 - 1)), seen_4, budget_2);
              result_44 = X60Qx_185;
              popSeen_0_valzr1t4f(seen_4);}}}}
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qtmp_23);}
    break;}
  return result_44;}
string_0_sysvq0asl renderValueReadable_0_valzr1t4f(Value_0_valzr1t4f* v_22, NI32 budget_3){
  string_0_sysvq0asl result_45;
  nimStrWasMoved((&result_45));
  seq_0_Igsxz3n_arecyyj7v seen_5 = newSeqUninit_0_I1kz5fl_arecyyj7v(0);
  NI32 b_3 = budget_3;
  nimStrDestroy(result_45);
  string_0_sysvq0asl X60Qx_186 = renderReadable_1_valzr1t4f((&(*v_22)), dbgRenderDepth_0_valzr1t4f, (&seen_5), (&b_3));
  result_45 = X60Qx_186;
  eQdestroy_1_Ib6pp1_arecyyj7v(seen_5);
  return result_45;
  eQdestroy_1_Ib6pp1_arecyyj7v(seen_5);
  return result_45;}
NI32 parseIndexSeg_0_valzr1t4f(string_0_sysvq0asl s_4){
  NI32 result_46;
  NI32 X60Qx_187 = len_4_sysvq0asl(s_4);
  if (X60Qx_187 == 0){
    return -1;}
  result_46 = 0;
  {
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_2 = toOpenArray_2_sysvq0asl((&s_4));
    NI32 X60Qlf_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_188 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_2);
        if (X60Qlf_3 < X60Qx_188){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_2, X60Qlf_3);
            NB8 X60Qx_189;
            if ((NC8)'0' <= (*X60Qii_2)){
              X60Qx_189 = ((*X60Qii_2) <= (NC8)'9');}
            else {
              X60Qx_189 = NIM_FALSE;}
            if (X60Qx_189){
              result_46 = ((NI32)(((NI32)(result_46 * 10)) + ((NI32)(((NI32)(*X60Qii_2)) - ((NI32)(NC8)'0')))));}
            else {
              return -1;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_46;}
string_0_sysvq0asl renderValueAtPath_0_valzr1t4f(Value_0_valzr1t4f* startV_0, openArray_0_Ig73pnk_aow7lb5cq1 segs_0){
  string_0_sysvq0asl result_47;
  nimStrWasMoved((&result_47));
  Value_0_valzr1t4f cur_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*startV_0)));
  NI32 i_14 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_190 = len_6_Igv2wyu1_aow7lb5cq1(segs_0);
      if (i_14 < X60Qx_190){
        NI32 guard_0 = 0;
        {
          while (guard_0 < 64){
            NB8 X60Qx_191;
            if (cur_0.kind_0 == 12){
              X60Qx_191 = (!(cur_0.rf_0 == NIM_NIL));}
            else {
              X60Qx_191 = NIM_FALSE;}
            if (X60Qx_191){
              Value_0_valzr1t4f X60Qlhs_28 = cur_0;
              Value_0_valzr1t4f X60Qx_192 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cur_0.rf_0).d_00.v_0));
              cur_0 = X60Qx_192;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_28));}
            else {
              NB8 X60Qx_193;
              if (cur_0.kind_0 == 13){
                X60Qx_193 = (!(cur_0.loc_0 == NIM_NIL));}
              else {
                X60Qx_193 = NIM_FALSE;}
              if (X60Qx_193){
                Value_0_valzr1t4f X60Qlhs_29 = cur_0;
                Value_0_valzr1t4f X60Qx_194 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cur_0.loc_0).d_00.v_0));
                cur_0 = X60Qx_194;
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_29));}
              else {
                goto whileStmtLabel_1;}}
            inc_1_I6wjjge_aow2h993l1((&guard_0));}}
        whileStmtLabel_1: ;
        string_0_sysvq0asl* X60Qx_195 = getQ_10_Ik9hgkq1_aow7lb5cq1(segs_0, i_14);
        string_0_sysvq0asl seg_0 = nimStrDup((*X60Qx_195));
        NB8 moved_0 = NIM_FALSE;
        switch (cur_0.kind_0){
          case 11:
          case 10:
          {
            if ((!(cur_0.obj_0 == NIM_NIL))){
              NI32 k_1 = 0;
              {
                while (NIM_TRUE){
                  NI32 X60Qx_196 = len_3_I83dzei_arecyyj7v((*cur_0.obj_0).d_00.cells_0);
                  if (k_1 < X60Qx_196){
                    string_0_sysvq0asl X60Qx_15;
                    nimStrWasMoved((&X60Qx_15));
                    NI32 X60Qx_197 = len_3_I6y2imo_arecyyj7v((*cur_0.obj_0).d_00.names_0);
                    if (k_1 < X60Qx_197){
                      nimStrDestroy(X60Qx_15);
                      NU32* X60Qx_198 = getQ_7_I2v00yv1_arecyyj7v((*cur_0.obj_0).d_00.names_0, k_1);
                      string_0_sysvq0asl X60Qx_199 = fieldBasename_0_valzr1t4f((*X60Qx_198));
                      X60Qx_15 = X60Qx_199;}
                    else {
                      nimStrDestroy(X60Qx_15);
                      X60Qx_15 = (string_0_sysvq0asl){
                        .bytes_0 = 0u, .more_0 = NIM_NIL}
                      ;}
                    string_0_sysvq0asl nm_1 = X60Qx_15;
                    nimStrWasMoved((&X60Qx_15));
                    NB8 X60Qx_200;
                    NB8 X60Qx_201 = eqQ_20_sysvq0asl(nm_1, seg_0);
                    if (X60Qx_201){
                      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_202 = getQ_7_Ii14ync1_arecyyj7v((*cur_0.obj_0).d_00.cells_0, k_1);
                      X60Qx_200 = (!((*X60Qx_202) == NIM_NIL));}
                    else {
                      X60Qx_200 = NIM_FALSE;}
                    if (X60Qx_200){
                      Value_0_valzr1t4f X60Qlhs_30 = cur_0;
                      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_203 = getQ_7_Ii14ync1_arecyyj7v((*cur_0.obj_0).d_00.cells_0, k_1);
                      Value_0_valzr1t4f X60Qx_204 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_203)).d_00.v_0));
                      cur_0 = X60Qx_204;
                      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_30));
                      moved_0 = NIM_TRUE;
                      nimStrDestroy(nm_1);
                      nimStrDestroy(X60Qx_15);
                      goto whileStmtLabel_2;}
                    inc_1_I6wjjge_aow2h993l1((&k_1));
                    nimStrDestroy(nm_1);
                    nimStrDestroy(X60Qx_15);}
                  else {
                    break;}}}
              whileStmtLabel_2: ;
              if ((!moved_0)){
                NI32 idx_1 = parseIndexSeg_0_valzr1t4f(seg_0);
                NB8 X60Qx_205;
                NB8 X60Qx_206;
                if (0 <= idx_1){
                  NI32 X60Qx_207 = len_3_I83dzei_arecyyj7v((*cur_0.obj_0).d_00.cells_0);
                  X60Qx_206 = (idx_1 < X60Qx_207);}
                else {
                  X60Qx_206 = NIM_FALSE;}
                if (X60Qx_206){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_208 = getQ_7_Ii14ync1_arecyyj7v((*cur_0.obj_0).d_00.cells_0, idx_1);
                  X60Qx_205 = (!((*X60Qx_208) == NIM_NIL));}
                else {
                  X60Qx_205 = NIM_FALSE;}
                if (X60Qx_205){
                  Value_0_valzr1t4f X60Qlhs_31 = cur_0;
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_209 = getQ_7_Ii14ync1_arecyyj7v((*cur_0.obj_0).d_00.cells_0, idx_1);
                  Value_0_valzr1t4f X60Qx_210 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_209)).d_00.v_0));
                  cur_0 = X60Qx_210;
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_31));
                  moved_0 = NIM_TRUE;}}}}
          break;
          case 8:
          {
            NI32 idx_2 = parseIndexSeg_0_valzr1t4f(seg_0);
            NB8 X60Qx_211;
            NB8 X60Qx_212;
            NB8 X60Qx_213;
            if ((!(cur_0.sq_0 == NIM_NIL))){
              X60Qx_213 = (0 <= idx_2);}
            else {
              X60Qx_213 = NIM_FALSE;}
            if (X60Qx_213){
              NI32 X60Qx_214 = len_3_I83dzei_arecyyj7v((*cur_0.sq_0).d_00.elems_0);
              X60Qx_212 = (idx_2 < X60Qx_214);}
            else {
              X60Qx_212 = NIM_FALSE;}
            if (X60Qx_212){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_215 = getQ_7_Ii14ync1_arecyyj7v((*cur_0.sq_0).d_00.elems_0, idx_2);
              X60Qx_211 = (!((*X60Qx_215) == NIM_NIL));}
            else {
              X60Qx_211 = NIM_FALSE;}
            if (X60Qx_211){
              Value_0_valzr1t4f X60Qlhs_32 = cur_0;
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_216 = getQ_7_Ii14ync1_arecyyj7v((*cur_0.sq_0).d_00.elems_0, idx_2);
              Value_0_valzr1t4f X60Qx_217 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_216)).d_00.v_0));
              cur_0 = X60Qx_217;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_32));
              moved_0 = NIM_TRUE;}}
          break;
          case 9:
          {
            NI32 idx_3 = parseIndexSeg_0_valzr1t4f(seg_0);
            NB8 X60Qx_218;
            NB8 X60Qx_219;
            NB8 X60Qx_220;
            if ((!(cur_0.arr_0 == NIM_NIL))){
              X60Qx_220 = (0 <= idx_3);}
            else {
              X60Qx_220 = NIM_FALSE;}
            if (X60Qx_220){
              NI32 X60Qx_221 = len_3_I83dzei_arecyyj7v((*cur_0.arr_0).d_00.elems_0);
              X60Qx_219 = (idx_3 < X60Qx_221);}
            else {
              X60Qx_219 = NIM_FALSE;}
            if (X60Qx_219){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_222 = getQ_7_Ii14ync1_arecyyj7v((*cur_0.arr_0).d_00.elems_0, idx_3);
              X60Qx_218 = (!((*X60Qx_222) == NIM_NIL));}
            else {
              X60Qx_218 = NIM_FALSE;}
            if (X60Qx_218){
              Value_0_valzr1t4f X60Qlhs_33 = cur_0;
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_223 = getQ_7_Ii14ync1_arecyyj7v((*cur_0.arr_0).d_00.elems_0, idx_3);
              Value_0_valzr1t4f X60Qx_224 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_223)).d_00.v_0));
              cur_0 = X60Qx_224;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_33));
              moved_0 = NIM_TRUE;}}
          break;
          default:
          {
            }
          break;}
        if ((!moved_0)){
          string_0_sysvq0asl X60Qdesugar_21 = dollarX60Q_ValueKind_0_valzr1t4f(cur_0.kind_0);
          NI32 X60Qx_225 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1869495550u, .more_0 = (&strlit_0_I6638091695445642996_valzr1t4f)}
          );
          NI32 X60Qx_226 = len_4_sysvq0asl(seg_0);
          NI32 X60Qx_227 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1864378366u, .more_0 = (&strlit_0_I13247028810395804432_valzr1t4f)}
          );
          NI32 X60Qx_228 = len_4_sysvq0asl(X60Qdesugar_21);
          NI32 X60Qx_229 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 15873u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_22 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_225 + X60Qx_226)) + X60Qx_227)) + X60Qx_228)) + X60Qx_229)));
          add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
            .bytes_0 = 1869495550u, .more_0 = (&strlit_0_I6638091695445642996_valzr1t4f)}
          );
          add_2_sysvq0asl((&X60Qdesugar_22), seg_0);
          add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
            .bytes_0 = 1864378366u, .more_0 = (&strlit_0_I13247028810395804432_valzr1t4f)}
          );
          add_2_sysvq0asl((&X60Qdesugar_22), X60Qdesugar_21);
          add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
            .bytes_0 = 15873u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qtmp_34 = X60Qdesugar_22;
          nimStrWasMoved((&X60Qdesugar_22));
          nimStrDestroy(X60Qdesugar_22);
          nimStrDestroy(X60Qdesugar_21);
          nimStrDestroy(seg_0);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cur_0));
          return X60Qtmp_34;
          nimStrDestroy(X60Qdesugar_22);
          nimStrDestroy(X60Qdesugar_21);}
        inc_1_I6wjjge_aow2h993l1((&i_14));
        nimStrDestroy(seg_0);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(result_47);
  string_0_sysvq0asl X60Qx_230 = renderValueReadable_0_valzr1t4f((&cur_0), ((NI32)8000));
  result_47 = X60Qx_230;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cur_0));
  return result_47;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cur_0));
  return result_47;}
static inline seq_0_I7epg22_valzr1t4f newSeqUninit_0_I5ncg7j_valzr1t4f(NI32 size_3){
  seq_0_I7epg22_valzr1t4f result_48;
  if (size_3 == 0){
    result_48 = (seq_0_I7epg22_valzr1t4f){
      .len_0 = size_3, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_Iigtmlk1_valzr1t4f(size_3);
    void* X60Qx_231 = alloc_1_sysvq0asl(memSize_0);
    result_48 = (seq_0_I7epg22_valzr1t4f){
      .len_0 = size_3, .data_0 = ((NC8*)X60Qx_231)}
    ;
    if ((!(result_48.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_232 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_48.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_48;}
static inline void add_0_Id5x3o5_valzr1t4f(seq_0_I7epg22_valzr1t4f* s_17, NC8 elem_3){
  NI32 L_0 = (*s_17).len_0;
  NI32 X60Qx_233 = capInBytes_0_Isccluk1_valzr1t4f((*s_17));
  if (X60Qx_233 < ((NI32)(((NI32)(L_0 * sizeof(NC8))) + sizeof(NC8)))){
    NB8 X60Qx_234 = resize_0_Irimnxi1_valzr1t4f(s_17, 1);
    if ((!X60Qx_234)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_17).len_0));
  (*s_17).data_0[L_0] = elem_3;}
static inline NI32 len_3_Irwqcn4_valzr1t4f(seq_0_I7epg22_valzr1t4f s_19){
  NI32 result_49;
  result_49 = s_19.len_0;
  return result_49;}
static inline NC8* getQ_7_Iqupddu1_valzr1t4f(seq_0_I7epg22_valzr1t4f s_20, NI32 i_15){
  NB8 X60Qx_235;
  if (i_15 < s_20.len_0){
    X60Qx_235 = (0 <= i_15);}
  else {
    X60Qx_235 = NIM_FALSE;}
  if ((!X60Qx_235)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NC8* result_50;
  result_50 = (&s_20.data_0[i_15]);
  return result_50;}
static inline openArray_0_Iptmq8f_valzr1t4f toOpenArray_1_Iy9e09m1_valzr1t4f(seq_0_Igsxz3n_arecyyj7v s_26){
  openArray_0_Iptmq8f_valzr1t4f result_55;
  NU32* X60Qx_242 = rawData_0_I2ocua8_valzr1t4f(s_26);
  result_55 = (openArray_0_Iptmq8f_valzr1t4f){
    .a_0 = X60Qx_242, .len_0 = s_26.len_0}
  ;
  return result_55;}
void setLen_0_Iqjrd6x1_valzr1t4f(seq_0_Igsxz3n_arecyyj7v* s_29, NI32 newLen_1){
  if (newLen_1 < (*s_29).len_0){
    shrink_0_I8pb57y1_valzr1t4f(s_29, newLen_1);}
  else {
    NI32 i_19 = (*s_29).len_0;
    growUnsafe_0_Ivs2bxy1_valzr1t4f(s_29, newLen_1);
    if ((*s_29).data_0 == NIM_NIL){
      return;}
    {
      while (i_19 < newLen_1){
        (*s_29).data_0[i_19] = ((NU32)0u);
        inc_1_I6wjjge_aow2h993l1((&i_19));}}
    whileStmtLabel_0: ;}}
static inline NI32 memSizeInBytes_0_Iigtmlk1_valzr1t4f(NI32 size_9){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_63;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_9, sizeof(NC8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_63 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_63 = ((NI32)2147483647);}
  return result_63;}
static inline NI32 capInBytes_0_Isccluk1_valzr1t4f(seq_0_I7epg22_valzr1t4f s_36){
  NI32 result_64;
  NI32 X60Qx_16;
  if ((!(s_36.data_0 == NIM_NIL))){
    NI32 X60Qx_249 = allocatedSize_0_sysvq0asl(((void*)((void*)s_36.data_0)));
    X60Qx_16 = X60Qx_249;}
  else {
    X60Qx_16 = 0;}
  result_64 = X60Qx_16;
  return result_64;}
NB8 resize_0_Irimnxi1_valzr1t4f(seq_0_I7epg22_valzr1t4f* dest_3, NI32 addedElements_3){
  NB8 result_65;
  NI32 X60Qx_250 = capInBytes_0_Isccluk1_valzr1t4f((*dest_3));
  NI32 oldCap_0 = ((NI32)(X60Qx_250 / sizeof(NC8)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_3);
  NI32 memSize_3 = memSizeInBytes_0_Iigtmlk1_valzr1t4f(newCap_0);
  void* X60Qx_251 = realloc_1_sysvq0asl(((void*)((void*)(*dest_3).data_0)), memSize_3);
  (*dest_3).data_0 = ((NC8*)X60Qx_251);
  if ((*dest_3).data_0 == NIM_NIL){
    (*dest_3).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_3);
    result_65 = NIM_FALSE;}
  else {
    result_65 = NIM_TRUE;}
  return result_65;}
static inline NU32* rawData_0_I2ocua8_valzr1t4f(seq_0_Igsxz3n_arecyyj7v s_39){
  NU32* result_70;
  result_70 = s_39.data_0;
  return result_70;}
static inline NI32 len_6_Iql6z121_valzr1t4f(openArray_0_Iptmq8f_valzr1t4f a_11){
  NI32 result_71;
  result_71 = a_11.len_0;
  return result_71;}
static inline NU32* getQ_10_Isxag051_valzr1t4f(openArray_0_Iptmq8f_valzr1t4f x_16, NI32 idx_8){
  NB8 X60Qx_256;
  if (0 <= idx_8){
    X60Qx_256 = (idx_8 < x_16.len_0);}
  else {
    X60Qx_256 = NIM_FALSE;}
  if ((!X60Qx_256)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NU32* result_72;
  result_72 = (&x_16.a_0[idx_8]);
  return result_72;}
void shrink_0_I8pb57y1_valzr1t4f(seq_0_Igsxz3n_arecyyj7v* s_40, NI32 newLen_4){
  NI32 i_23 = ((NI32)((*s_40).len_0 - 1));
  {
    while (newLen_4 <= i_23){
      dec_1_I0nzoz91_aow7lb5cq1((&i_23));}}
  whileStmtLabel_0: ;
  (*s_40).len_0 = newLen_4;}
void growUnsafe_0_Ivs2bxy1_valzr1t4f(seq_0_Igsxz3n_arecyyj7v* s_41, NI32 newLen_5){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_5, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_0 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_257 = capInBytes_0_Ia2b4aa_arecyyj7v((*s_41));
  if (X60Qx_257 < newSize_0){
    NB8 X60Qx_258 = resize_0_Ieull6y_arecyyj7v(s_41, ((NI32)(newLen_5 - (*s_41).len_0)));
    if ((!X60Qx_258)){
      return;}}
  (*s_41).len_0 = newLen_5;}
void eQdestroy_1_I9czx0f1_valzr1t4f(seq_0_I7epg22_valzr1t4f s_70){
  if ((!(s_70.data_0 == NIM_NIL))){
    NI32 i_44 = 0;
    {
      while (i_44 < s_70.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_44));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_70.data_0)));}}
void eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f(Cell_Obj_0_valzr1t4f* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).v_0));}
void eQdestroyQ_SX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(ClosureEnv_Obj_0_valzr1t4f dest_0){
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(dest_0.dest_0);
  eQdestroyQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f(dest_0.coro_0);
  eQdestroy_1_I8k3d0z1_arecyyj7v(dest_0.cells_0);
  eQdestroy_1_Iscb4i31_arecyyj7v(dest_0.vars_0);}
void eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(SeqBox_Obj_0_valzr1t4f dest_0){
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(dest_0.flat_0);
  eQdestroy_1_I8k3d0z1_arecyyj7v(dest_0.elems_0);}
void eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(ArrBox_Obj_0_valzr1t4f dest_0){
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(dest_0.flat_0);
  eQdestroy_1_I8k3d0z1_arecyyj7v(dest_0.elems_0);}
void eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(ObjBox_Obj_0_valzr1t4f dest_0){
  eQdestroy_1_I8k3d0z1_arecyyj7v(dest_0.cells_0);
  eQdestroy_1_Iscb4i31_arecyyj7v(dest_0.names_0);}
void eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(FlatRegion_Obj_0_valzr1t4f dest_0){
  switch (dest_0.kind_0){
    case 0:
    {
      eQdestroy_1_Ijx6eoq_arecyyj7v(dest_0.bytes_0);
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(dest_0.objOverlay_0);}
    break;
    case 1:
    {
      eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(dest_0.sbox_0);}
    break;
    case 2:
    {
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(dest_0.abox_0);}
    break;
    case 3:
    {
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(dest_0.scell_0);}
    break;
    case 4:
    {
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(dest_0.ccell_0);}
    break;
    case 5:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(dest_0.obox_0);
      eQdestroy_1_Iv9ij5i1_aow7lb5cq1(dest_0.offs_0);}
    break;
    case 6:
    {
      }
    break;}}
void eQdestroyQ_SX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(PtrOv_Obj_0_valzr1t4f* dest_0){
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).region_0);
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).seqOwn_0);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).arrOwn_0);}
void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0){
  switch ((*dest_0).kind_0){
    case 0:
    {
      }
    break;
    case 1:
    case 2:
    {
      }
    break;
    case 3:
    {
      }
    break;
    case 4:
    {
      }
    break;
    case 5:
    {
      }
    break;
    case 6:
    {
      nimStrDestroy((*dest_0).sval_0);}
    break;
    case 7:
    {
      }
    break;
    case 8:
    {
      eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).sq_0);}
    break;
    case 9:
    {
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).arr_0);}
    break;
    case 10:
    case 11:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).obj_0);}
    break;
    case 12:
    {
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).rf_0);}
    break;
    case 13:
    {
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).loc_0);
      eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).ov_0);}
    break;
    case 14:
    {
      eQdestroyQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).st_0);}
    break;
    case 15:
    {
      eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).env_0);}
    break;
    case 16:
    {
      }
    break;
    case 17:
    {
      eQdestroyQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).coro_0);}
    break;}}
void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0){
  switch ((*dest_0).kind_0){
    case 0:
    {
      }
    break;
    case 1:
    case 2:
    {
      }
    break;
    case 3:
    {
      }
    break;
    case 4:
    {
      }
    break;
    case 5:
    {
      }
    break;
    case 6:
    {
      nimStrWasMoved((&(*dest_0).sval_0));}
    break;
    case 7:
    {
      }
    break;
    case 8:
    {
      eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).sq_0));}
    break;
    case 9:
    {
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).arr_0));}
    break;
    case 10:
    case 11:
    {
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).obj_0));}
    break;
    case 12:
    {
      eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).rf_0));}
    break;
    case 13:
    {
      eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).loc_0));
      eQwasmovedQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).ov_0));}
    break;
    case 14:
    {
      eQwasmovedQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).st_0));}
    break;
    case 15:
    {
      eQwasmovedQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).env_0));}
    break;
    case 16:
    {
      }
    break;
    case 17:
    {
      eQwasmovedQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).coro_0));}
    break;}}
Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0){
  Value_0_valzr1t4f dest_0;
  dest_0.kind_0 = (*src_0).kind_0;
  switch (dest_0.kind_0){
    case 0:
    {
      }
    break;
    case 1:
    case 2:
    {
      dest_0.ival_0 = (*src_0).ival_0;
      dest_0.bits_0 = (*src_0).bits_0;}
    break;
    case 3:
    {
      dest_0.fval_0 = (*src_0).fval_0;
      dest_0.fbits_0 = (*src_0).fbits_0;}
    break;
    case 4:
    {
      dest_0.bval_0 = (*src_0).bval_0;}
    break;
    case 5:
    {
      dest_0.cval_0 = (*src_0).cval_0;}
    break;
    case 6:
    {
      string_0_sysvq0asl X60Qx_338 = nimStrDup((*src_0).sval_0);
      dest_0.sval_0 = X60Qx_338;}
    break;
    case 7:
    {
      dest_0.eord_0 = (*src_0).eord_0;
      dest_0.ekind_0 = (*src_0).ekind_0;}
    break;
    case 8:
    {
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_339 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*src_0).sq_0);
      dest_0.sq_0 = X60Qx_339;}
    break;
    case 9:
    {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_340 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*src_0).arr_0);
      dest_0.arr_0 = X60Qx_340;}
    break;
    case 10:
    case 11:
    {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_341 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((*src_0).obj_0);
      dest_0.obj_0 = X60Qx_341;}
    break;
    case 12:
    {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_342 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((*src_0).rf_0);
      dest_0.rf_0 = X60Qx_342;}
    break;
    case 13:
    {
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_343 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((*src_0).loc_0);
      dest_0.loc_0 = X60Qx_343;
      X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* X60Qx_344 = eQdupQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((*src_0).ov_0);
      dest_0.ov_0 = X60Qx_344;}
    break;
    case 14:
    {
      X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* X60Qx_345 = eQdupQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f((*src_0).st_0);
      dest_0.st_0 = X60Qx_345;}
    break;
    case 15:
    {
      X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* X60Qx_346 = eQdupQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f((*src_0).env_0);
      dest_0.env_0 = X60Qx_346;
      dest_0.fn_0 = (*src_0).fn_0;
      dest_0.pidxRaw_0 = (*src_0).pidxRaw_0;
      dest_0.resumeRaw_0 = (*src_0).resumeRaw_0;}
    break;
    case 16:
    {
      dest_0.toErr_0 = (*src_0).toErr_0;}
    break;
    case 17:
    {
      X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* X60Qx_347 = eQdupQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f((*src_0).coro_0);
      dest_0.coro_0 = X60Qx_347;}
    break;}
  return dest_0;}
void eQtraceQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0, void* src_0){
  switch ((*dest_0).kind_0){
    case 0:
    {
      }
    break;
    case 1:
    case 2:
    {
      }
    break;
    case 3:
    {
      }
    break;
    case 4:
    {
      }
    break;
    case 5:
    {
      }
    break;
    case 6:
    {
      }
    break;
    case 7:
    {
      }
    break;
    case 8:
    {
      eQtraceQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).sq_0), src_0);}
    break;
    case 9:
    {
      eQtraceQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).arr_0), src_0);}
    break;
    case 10:
    case 11:
    {
      eQtraceQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).obj_0), src_0);}
    break;
    case 12:
    {
      eQtraceQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).rf_0), src_0);}
    break;
    case 13:
    {
      eQtraceQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).loc_0), src_0);
      eQtraceQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).ov_0), src_0);}
    break;
    case 14:
    {
      eQtraceQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).st_0), src_0);}
    break;
    case 15:
    {
      eQtraceQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).env_0), src_0);}
    break;
    case 16:
    {
      }
    break;
    case 17:
    {
      eQtraceQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).coro_0), src_0);}
    break;}}
void eQdestroyQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_350 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_350){
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_351 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_351){
      eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_352 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_352){
      eQdestroyQ_SX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* eQdupQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* src_0){
  X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQtraceQ_ArefSX43oroX52efX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax** dest_0, void* src_0){
  }
void eQtraceQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0){
  }
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_353 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_353){
      eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_354 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_354){
      eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_355 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_355){
      eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_356 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_356){
      eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQtraceQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0){
  }
void eQtraceQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0){
  }
void eQtraceQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0, void* src_0){
  }
void eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* dest_0){
  if (dest_0){
    NB8 X60Qx_357 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_357){
      eQdestroyQ_SX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_358 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_358){
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* eQdupQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* src_0){
  X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* eQdupQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* src_0){
  X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* eQdupQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* src_0){
  X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQtraceQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v** dest_0, void* src_0){
  }
void eQtraceQ_ArefSX53etX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax** dest_0, void* src_0){
  }
void eQtraceQ_ArefSX43losureX45nvX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax** dest_0, void* src_0){
  }
void X60Qini_0_valzr1t4f(void){
  if (X60QiniGuard_0_valzr1t4f){
    return;}
  X60QiniGuard_0_valzr1t4f = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_xinat3x34();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_symkyk35i1();}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
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
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline seq_0_Iw8xl5b1_arecyyj7v newSeqUninit_0_I1tbjnk1_arecyyj7v(NI32 size_24){
  seq_0_Iw8xl5b1_arecyyj7v result_61;
  if (size_24 == 0){
    result_61 = (seq_0_Iw8xl5b1_arecyyj7v){
      .len_0 = size_24, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_16 = memSizeInBytes_0_Ixcobep_arecyyj7v(size_24);
    void* X60Qx_372 = alloc_1_sysvq0asl(memSize_16);
    result_61 = (seq_0_Iw8xl5b1_arecyyj7v){
      .len_0 = size_24, .data_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1**)X60Qx_372)}
    ;
    if ((!(result_61.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_373 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_61.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_16);}}
  return result_61;}
static inline NI32 len_3_I83dzei_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_25){
  NI32 result_26;
  result_26 = s_25.len_0;
  return result_26;}
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_26, NI32 i_28){
  NB8 X60Qx_305;
  if (i_28 < s_26.len_0){
    X60Qx_305 = (0 <= i_28);}
  else {
    X60Qx_305 = NIM_FALSE;}
  if ((!X60Qx_305)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** result_27;
  result_27 = (&s_26.data_0[i_28]);
  return result_27;}
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_arecyyj7v* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8){
  NI32 L_1 = (*s_32).len_0;
  NI32 X60Qx_432 = capInBytes_0_Iih34tr1_arecyyj7v((*s_32));
  if (X60Qx_432 < ((NI32)(((NI32)(L_1 * sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*))) + sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)))){
    NB8 X60Qx_433 = resize_0_If3pogj_flaksyopx1(s_32, 1);
    if ((!X60Qx_433)){
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(elem_8);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_32).len_0));
  (*s_32).data_0[L_1] = elem_8;}
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
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12){
  string_0_sysvq0asl* result_8;
  NI32 idx_3 = ((NI32)(((NI32)litId_12) - ((NI32)1)));
  if ((!(idx_3 < t_13.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  string_0_sysvq0asl* X60Qx_51 = getQ_7_Ir6d0tw_aow7lb5cq1(t_13.vals_0, idx_3);
  result_8 = X60Qx_51;
  return result_8;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
static inline NI32 len_3_I3cga53_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_43){
  NI32 result_38;
  result_38 = s_43.len_0;
  return result_38;}
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_dbgj4vyzj1(NI32 a_13, NI32 b_2){
  HSlice_0_Inzqy8d_aow7lb5cq1 result_36;
  result_36 = (HSlice_0_Inzqy8d_aow7lb5cq1){
    .a_0 = a_13, .b_0 = ((NI32)(b_2 - ((NI32)1)))}
  ;
  return result_36;}
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355){
  string_0_sysvq0asl result_224;
  nimStrWasMoved((&result_224));
  nimStrDestroy(result_224);
  string_0_sysvq0asl X60Qx_437 = substr_0_sysvq0asl(s_77, x_355.a_0, x_355.b_0);
  result_224 = X60Qx_437;
  return result_224;}
static inline void dec_0_Ig5i8xp_nifb6mq6y1(NI32* x_18, NI32 y_4){
  (*x_18) = ((NI32)((*x_18) - y_4));}
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37){
  NI32 result_34;
  result_34 = s_37.len_0;
  return result_34;}
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33){
  NB8 X60Qx_314;
  if (i_33 < s_40.len_0){
    X60Qx_314 = (0 <= i_33);}
  else {
    X60Qx_314 = NIM_FALSE;}
  if ((!X60Qx_314)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_37;
  result_37 = (&s_40.data_0[i_33]);
  return result_37;}
static inline void add_0_Iwsr3ai_arecyyj7v(seq_0_Igsxz3n_arecyyj7v* s_45, NU32 elem_7){
  NI32 L_3 = (*s_45).len_0;
  NI32 X60Qx_318 = capInBytes_0_Ia2b4aa_arecyyj7v((*s_45));
  if (X60Qx_318 < ((NI32)(((NI32)(L_3 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_319 = resize_0_Ieull6y_arecyyj7v(s_45, 1);
    if ((!X60Qx_319)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_45).len_0));
  (*s_45).data_0[L_3] = elem_7;}
static inline seq_0_Igsxz3n_arecyyj7v newSeqUninit_0_I1kz5fl_arecyyj7v(NI32 size_10){
  seq_0_Igsxz3n_arecyyj7v result_40;
  if (size_10 == 0){
    result_40 = (seq_0_Igsxz3n_arecyyj7v){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_Ioqvae11_arecyyj7v(size_10);
    void* X60Qx_320 = alloc_1_sysvq0asl(memSize_3);
    result_40 = (seq_0_Igsxz3n_arecyyj7v){
      .len_0 = size_10, .data_0 = ((NU32*)X60Qx_320)}
    ;
    if ((!(result_40.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_321 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_40.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_40;}
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67){
  openArray_0_Ijk0jkw1_aow7lb5cq1 result_146;
  NC8* X60Qx_316 = readRawData_0_sysvq0asl((&(*s_67)), 0);
  NI32 X60Qx_317 = len_4_sysvq0asl((*s_67));
  result_146 = (openArray_0_Ijk0jkw1_aow7lb5cq1){
    .a_0 = X60Qx_316, .len_0 = X60Qx_317}
  ;
  return result_146;}
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_27){
  NI32 result_83;
  result_83 = a_27.len_0;
  return result_83;}
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6){
  NB8 X60Qx_1466;
  if (0 <= idx_6){
    X60Qx_1466 = (idx_6 < x_12.len_0);}
  else {
    X60Qx_1466 = NIM_FALSE;}
  if ((!X60Qx_1466)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NC8* result_84;
  result_84 = (&x_12.a_0[idx_6]);
  return result_84;}
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_28){
  NI32 result_90;
  result_90 = a_28.len_0;
  return result_90;}
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7){
  NB8 X60Qx_1473;
  if (0 <= idx_7){
    X60Qx_1473 = (idx_7 < x_13.len_0);}
  else {
    X60Qx_1473 = NIM_FALSE;}
  if ((!X60Qx_1473)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* result_91;
  result_91 = (&x_13.a_0[idx_7]);
  return result_91;}
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
static inline NI32 capInBytes_0_Ia2b4aa_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_50){
  NI32 result_50;
  NI32 X60Qx_18;
  if ((!(s_50.data_0 == NIM_NIL))){
    NI32 X60Qx_331 = allocatedSize_0_sysvq0asl(((void*)((void*)s_50.data_0)));
    X60Qx_18 = X60Qx_331;}
  else {
    X60Qx_18 = 0;}
  result_50 = X60Qx_18;
  return result_50;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NI32 memSizeInBytes_0_Ixcobep_arecyyj7v(NI32 size_25){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_63;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_25, sizeof(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_63 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_63 = ((NI32)2147483647);}
  return result_63;}
static inline NI32 capInBytes_0_Iih34tr1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_87){
  NI32 result_62;
  NI32 X60Qx_19;
  if ((!(s_87.data_0 == NIM_NIL))){
    NI32 X60Qx_374 = allocatedSize_0_sysvq0asl(((void*)((void*)s_87.data_0)));
    X60Qx_19 = X60Qx_374;}
  else {
    X60Qx_19 = 0;}
  result_62 = X60Qx_19;
  return result_62;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
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
static inline NI32 memSizeInBytes_0_Ioqvae11_arecyyj7v(NI32 size_15){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_52;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_15, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_52 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_52 = ((NI32)2147483647);}
  return result_52;}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0){
  NC8* result_103;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_39).bytes_0))))){
    result_103 = ((NC8*)((NU32)(((NU32)(&(*(*s_39).more_0).data_0[0])) + ((NU32)start_0))));}
  else {
    result_103 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_39).bytes_0)) + 1u)))) + ((NU32)start_0))));}
  return result_103;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
