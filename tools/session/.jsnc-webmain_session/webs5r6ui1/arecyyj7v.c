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
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v;
typedef struct MatEntry_0_arecyyj7v MatEntry_0_arecyyj7v;
typedef struct BlockEntry_0_arecyyj7v BlockEntry_0_arecyyj7v;
typedef struct RegionHandout_0_arecyyj7v RegionHandout_0_arecyyj7v;
typedef struct FieldOff_0_fiepkwzpc FieldOff_0_fiepkwzpc;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct MatEntry_0_arecyyj7v{
  NU32 key_0;
  NU32 box_0;}
MatEntry_0_arecyyj7v;
typedef struct BlockEntry_0_arecyyj7v{
  NU32 key_0;
  NU32 data_0;
  NI32 stride_0;
  NI32 count_0;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sq_0;
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arr_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_0;}
BlockEntry_0_arecyyj7v;
typedef struct RegionHandout_0_arecyyj7v{
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_0;
  NU32 base_0;
  NI32 size_0;}
RegionHandout_0_arecyyj7v;
typedef struct seq_0_Isge9lx_arecyyj7v{
  NI32 len_0;
  MatEntry_0_arecyyj7v* data_0;}
seq_0_Isge9lx_arecyyj7v;
typedef struct seq_0_Idhq52f_arecyyj7v{
  NI32 len_0;
  BlockEntry_0_arecyyj7v* data_0;}
seq_0_Idhq52f_arecyyj7v;
typedef struct seq_0_Ijes23h1_arecyyj7v{
  NI32 len_0;
  RegionHandout_0_arecyyj7v* data_0;}
seq_0_Ijes23h1_arecyyj7v;
typedef struct ArenaMat_0_arecyyj7v{
  X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* a_0;
  seq_0_Isge9lx_arecyyj7v seen_0;
  seq_0_Idhq52f_arecyyj7v blocks_0;
  seq_0_Ijes23h1_arecyyj7v regions_0;}
ArenaMat_0_arecyyj7v;
typedef struct seq_0_Igsxz3n_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_Igsxz3n_arecyyj7v;
typedef struct seq_0_Iw8xl5b1_arecyyj7v{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_arecyyj7v;
typedef struct seq_0_Incv1wn_arecyyj7v{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_arecyyj7v;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct seq_0_Id0odh1_arecyyj7v{
  NI32 len_0;
  FieldOff_0_fiepkwzpc* data_0;}
seq_0_Id0odh1_arecyyj7v;
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
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
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
typedef struct seq_0_Iele5kv_arewp645e1{
  NI32 len_0;
  void** data_0;}
seq_0_Iele5kv_arewp645e1;
typedef struct Arena_Obj_0_arewp645e1{
  seq_0_Iele5kv_arewp645e1 chunks_0;
  seq_0_Ift2sne_aow7lb5cq1 sizes_0;
  NI32 chunkSize_0;
  NI32 cur_0;
  NI32 off_0;
  NI32 total_0;}
Arena_Obj_0_arewp645e1;
typedef struct X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v{
  NI r_00;
  Arena_Obj_0_arewp645e1 d_00;}
X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v;
typedef struct X60Qt_0_IAtupleApointerZAR6_arecyyj7v{
  void* fld_0;
  void* fld_1;}
X60Qt_0_IAtupleApointerZAR6_arecyyj7v;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_arecyyj7v names_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v{
  Value_0_valzr1t4f fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v;
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
typedef struct X60Qt_0_IAarrayAuS8ZS3_aow2h993l1{
  NU8 a[3];}
X60Qt_0_IAarrayAuS8ZS3_aow2h993l1;
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
typedef NU8 DeclineStage_0_croph25r5;

#define dsCensus_0_croph25r5 ((NU8)0)
#define dsMarshal_0_croph25r5 ((NU8)1)
#define dsCallee_0_croph25r5 ((NU8)2)
#define dsArena_0_croph25r5 ((NU8)3)
#define dsAnalysis_0_croph25r5 ((NU8)4)
#define dsJit_0_croph25r5 ((NU8)5)
#define dsBuild_0_croph25r5 ((NU8)6)
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
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
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
void placeField_1_arecyyj7v(ArenaMat_0_arecyyj7v* m_14, void* dst_5, NI32 off_4, Value_0_valzr1t4f* fv_1, NI32 fsize_2);
void placeObject_1_arecyyj7v(ArenaMat_0_arecyyj7v* m_15, void* dst_6, Value_0_valzr1t4f* v_7);
void* materializeRef_1_arecyyj7v(ArenaMat_0_arecyyj7v* m_16, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_1);
void syncObject_1_arecyyj7v(void* src_4, Value_0_valzr1t4f* v_9, seq_0_Igsxz3n_arecyyj7v* visited_3);
static inline seq_0_Isge9lx_arecyyj7v newSeqUninit_0_Iglb3hm1_arecyyj7v(NI32 size_4);
static inline seq_0_Idhq52f_arecyyj7v newSeqUninit_0_I7mggr11_arecyyj7v(NI32 size_6);
static inline seq_0_Ijes23h1_arecyyj7v newSeqUninit_0_I1oegnq1_arecyyj7v(NI32 size_8);
static inline NI32 len_3_Ifjbd231_arecyyj7v(seq_0_Isge9lx_arecyyj7v s_23);
static inline MatEntry_0_arecyyj7v* getQ_7_Ielxh6u1_arecyyj7v(seq_0_Isge9lx_arecyyj7v s_24, NI32 i_27);
static inline NI32 len_3_I83dzei_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_25);
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_26, NI32 i_28);
static inline NI32 len_3_I80y55d1_arecyyj7v(seq_0_Idhq52f_arecyyj7v s_27);
static inline BlockEntry_0_arecyyj7v* getQ_7_Iyxduse_arecyyj7v(seq_0_Idhq52f_arecyyj7v s_28, NI32 i_29);
static inline void add_0_I52sfn71_arecyyj7v(seq_0_Idhq52f_arecyyj7v* s_29, BlockEntry_0_arecyyj7v elem_4);
static inline NI32 len_3_Izoe8zv_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_31);
static inline NU8* getQ_7_Ig0r1051_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_32, NI32 i_30);
static inline NI32 len_3_Io8yozm_arecyyj7v(seq_0_Ijes23h1_arecyyj7v s_33);
static inline RegionHandout_0_arecyyj7v* getQ_7_Irzlyr2_arecyyj7v(seq_0_Ijes23h1_arecyyj7v s_34, NI32 i_31);
static inline void add_0_Ilvs1p91_arecyyj7v(seq_0_Ijes23h1_arecyyj7v* s_35, RegionHandout_0_arecyyj7v elem_5);
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37);
static inline NI32 len_3_If78p9o_arecyyj7v(seq_0_Id0odh1_arecyyj7v s_38);
static inline FieldOff_0_fiepkwzpc* getQ_7_Ivg8m7s_arecyyj7v(seq_0_Id0odh1_arecyyj7v s_39, NI32 i_32);
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33);
static inline void add_0_Iaos70d1_arecyyj7v(seq_0_Isge9lx_arecyyj7v* s_41, MatEntry_0_arecyyj7v elem_6);
static inline NI32 len_3_I3cga53_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_43);
static inline NU32* getQ_7_Ib5f77c1_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_44, NI32 i_34);
static inline void add_0_Iwsr3ai_arecyyj7v(seq_0_Igsxz3n_arecyyj7v* s_45, NU32 elem_7);
static inline seq_0_Igsxz3n_arecyyj7v newSeqUninit_0_I1kz5fl_arecyyj7v(NI32 size_10);
static inline NI32 memSizeInBytes_0_Isdq9ys1_arecyyj7v(NI32 size_12);
static inline NI32 memSizeInBytes_0_Iovtwg11_arecyyj7v(NI32 size_13);
static inline NI32 memSizeInBytes_0_If6e4np_arecyyj7v(NI32 size_14);
static inline NI32 capInBytes_0_I3r76wn_arecyyj7v(seq_0_Idhq52f_arecyyj7v s_47);
NB8 resize_0_Ii6jopd_arecyyj7v(seq_0_Idhq52f_arecyyj7v* dest_4, NI32 addedElements_4);
static inline NI32 capInBytes_0_In2lvry_arecyyj7v(seq_0_Ijes23h1_arecyyj7v s_48);
NB8 resize_0_Iwzs34z_arecyyj7v(seq_0_Ijes23h1_arecyyj7v* dest_5, NI32 addedElements_5);
static inline NI32 capInBytes_0_Iswy84i_arecyyj7v(seq_0_Isge9lx_arecyyj7v s_49);
NB8 resize_0_Ipftt5t1_arecyyj7v(seq_0_Isge9lx_arecyyj7v* dest_6, NI32 addedElements_6);
static inline NI32 capInBytes_0_Ia2b4aa_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_50);
NB8 resize_0_Ieull6y_arecyyj7v(seq_0_Igsxz3n_arecyyj7v* dest_7, NI32 addedElements_7);
static inline NI32 memSizeInBytes_0_Ioqvae11_arecyyj7v(NI32 size_15);
void eQdestroy_1_Ib6pp1_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_73);
void eQdestroy_1_Ijysww_arecyyj7v(seq_0_Id0odh1_arecyyj7v s_84);
static inline seq_0_Iw8xl5b1_arecyyj7v newSeqUninit_0_I1tbjnk1_arecyyj7v(NI32 size_24);
static inline NI32 memSizeInBytes_0_Ixcobep_arecyyj7v(NI32 size_25);
static inline seq_0_In6doa_arecyyj7v newSeqUninit_0_Ieodq4s1_arecyyj7v(NI32 size_28);
static inline NI32 memSizeInBytes_0_Ivqzo5x1_arecyyj7v(NI32 size_29);
static inline NI32 memSizeInBytes_0_Icryocg_arecyyj7v(NI32 size_31);
void eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v(BlockEntry_0_arecyyj7v* dest_0);
void eQwasmovedQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v(BlockEntry_0_arecyyj7v* dest_0);
BlockEntry_0_arecyyj7v eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v(BlockEntry_0_arecyyj7v* src_0);
void eQdestroyQ_SX52egionX48andout0arecyyj7v_0_arecyyj7v(RegionHandout_0_arecyyj7v dest_0);
RegionHandout_0_arecyyj7v eQdupQ_SX52egionX48andout0arecyyj7v_0_arecyyj7v(RegionHandout_0_arecyyj7v src_0);
void eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v(ArenaMat_0_arecyyj7v* dest_0);
void eQwasmovedQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v(ArenaMat_0_arecyyj7v* dest_0);
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0);
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_arecyyj7v(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* dest_0);
void eQwasmovedQ_ArefSX41renaX4fbj0arewp645e1_0_arecyyj7v(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v** dest_0);
X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* eQdupQ_ArefSX41renaX4fbj0arewp645e1_0_arecyyj7v(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* src_0);
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_arecyyj7v(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v* dest_0);
void eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_arecyyj7v(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v* dest_0);
void eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* dest_0);
extern void bump_0_croph25r5(NI32 c_0, NI32 by_0);
extern NI32 const cUnhandled_0_croph25r5;
extern void noteItem_0_croph25r5(NI32 c_2, string_0_sysvq0asl item_0);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern void declineNote_0_croph25r5(DeclineStage_0_croph25r5 stage_0, string_0_sysvq0asl reason_1);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
extern NI32 countOf_0_croph25r5(NI32 c_1);
extern NI32 const cSeqBlocks_0_croph25r5;
extern NI32 const cArrBlocks_0_croph25r5;
extern NI32 const cCellBlocks_0_croph25r5;
extern NI32 const cBytesDirect_0_croph25r5;
extern NI32 const cBytesOverlay_0_croph25r5;
extern NI32 const cPtrDeclines_0_croph25r5;
extern NI32 const cLyingSeqs_0_croph25r5;
extern NI32 const cPtrNoDeref_0_croph25r5;
extern NI32 const cWbPtrHome_0_croph25r5;
extern NI32 const cWbPtrLost_0_croph25r5;
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern string_0_sysvq0asl itemsOf_0_croph25r5(NI32 c_3);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern NI64 asInt_0_valzr1t4f(Value_0_valzr1t4f* v_17);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
static inline void pokeByte_0_arewp645e1(void* p_1, NI32 off_0, NU8 v_0);
extern void* arenaAlloc_0_arewp645e1(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* a_2, NI32 size_1, NI32 align_0);
extern void pokeU64_0_arewp645e1(void* p_3, NI32 off_2, NU64 v_1);
extern NI32 sizeOfSym_0_fiepkwzpc(NU32 typeSym_3);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
static inline NI16 elemBits_0_valzr1t4f(Value_0_valzr1t4f* v_9);
static inline TCode_0_valzr1t4f ecode_0_valzr1t4f(Value_0_valzr1t4f* v_10);
static inline NU32 etype_0_valzr1t4f(Value_0_valzr1t4f* v_11);
extern Value_0_valzr1t4f vPtrRegT_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* reg_0, NI32 fo_0, NI16 eb_0, TCode_0_valzr1t4f ec_0, NU32 et_0);
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern Value_0_valzr1t4f vPtrArr_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_2, X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* a_0, X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* s_1, NI32 b_1);
extern X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* ovMut_0_valzr1t4f(Value_0_valzr1t4f* v_12);
static inline X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0_valzr1t4f(Value_0_valzr1t4f* v_7);
static inline NI32 foff_0_valzr1t4f(Value_0_valzr1t4f* v_8);
static inline X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0_valzr1t4f(Value_0_valzr1t4f* v_5);
static inline X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0_valzr1t4f(Value_0_valzr1t4f* v_4);
static inline NI32 base_0_valzr1t4f(Value_0_valzr1t4f* v_6);
extern seq_0_Id0odh1_arecyyj7v fieldOffsetsOfType_0_fiepkwzpc(NU32 typeSym_1);
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
static inline NU8 peekByte_0_arewp645e1(void* p_2, NI32 off_1);
extern Value_0_valzr1t4f vInt_0_valzr1t4f(NI64 x_2, NI32 bits_0);
extern Value_0_valzr1t4f vUInt_0_valzr1t4f(NU64 x_4, NI32 bits_2);
extern Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
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
extern void eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f(Cell_Obj_0_valzr1t4f* dest_0);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(ArrBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(SeqBox_Obj_0_valzr1t4f dest_0);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(FlatRegion_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX41renaX4fbj0arewp645e1_0_arewp645e1(Arena_Obj_0_arewp645e1* dest_0);
extern void eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(ObjBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f(PtrOv_Obj_0_valzr1t4f* dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_arewp645e1(void);
extern void X60Qini_0_fiepkwzpc(void);
extern void X60Qini_0_heapjafyf1(void);
extern void X60Qini_0_croph25r5(void);
extern void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0);
extern void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
extern void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
LongString_0_sysvq0asl const strlit_0_I267683909564568044_arecyyj7v = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "no native byte form for leaf: "}
;
LongString_0_sysvq0asl const strlit_0_I2925818693908859700_arecyyj7v = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hybrid: arena blocks seq="}
;
LongString_0_sysvq0asl const strlit_0_I7220483300902828320_arecyyj7v = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " arr="}
;
LongString_0_sysvq0asl const strlit_0_I1405192176789893522_arecyyj7v = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " cell="}
;
LongString_0_sysvq0asl const strlit_0_I6658469085088257676_arecyyj7v = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " bytes="}
;
LongString_0_sysvq0asl const strlit_0_I2810153910757964428_arecyyj7v = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " bytesOverlay="}
;
LongString_0_sysvq0asl const strlit_0_I7178761246479705055_arecyyj7v = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " ptrNoDeref="}
;
LongString_0_sysvq0asl const strlit_0_I5391896935332235772_arecyyj7v = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " ptrDeclined="}
;
LongString_0_sysvq0asl const strlit_0_I9406485454641063824_arecyyj7v = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " wbPtrHome="}
;
LongString_0_sysvq0asl const strlit_0_I11318396273308722532_arecyyj7v = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " wbPtrLost="}
;
LongString_0_sysvq0asl const strlit_0_I4924544341798789442_arecyyj7v = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " unhandled="}
;
LongString_0_sysvq0asl const strlit_0_I5796312517412486244_arecyyj7v = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " lyingSeqs="}
;
LongString_0_sysvq0asl const strlit_0_I4032485569337694205_arecyyj7v = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "scalar-width "}
;
LongString_0_sysvq0asl const strlit_0_I8126988068395022829_arecyyj7v = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " vs value width "}
;
LongString_0_sysvq0asl const strlit_0_I2747239888017569374_arecyyj7v = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "string-elem"}
;
LongString_0_sysvq0asl const strlit_0_I17933319393316134329_arecyyj7v = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "elem-kind"}
;
LongString_0_sysvq0asl const strlit_0_I15497396085640490539_arecyyj7v = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "string-field"}
;
LongString_0_sysvq0asl const strlit_0_I6918956669890399711_arecyyj7v = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "field-kind"}
;
NB8 arenaMatFailed_0_arecyyj7v = NIM_FALSE;
NB8 X60QiniGuard_0_arecyyj7v;
void noteUnhandled_0_arecyyj7v(string_0_sysvq0asl name_0){
  bump_0_croph25r5(cUnhandled_0_croph25r5, 1);
  noteItem_0_croph25r5(cUnhandled_0_croph25r5, name_0);
  string_0_sysvq0asl X60Qtmp_0 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 544173822u, .more_0 = (&strlit_0_I267683909564568044_arecyyj7v)}
  , name_0);
  declineNote_0_croph25r5(3, X60Qtmp_0);
  arenaMatFailed_0_arecyyj7v = NIM_TRUE;
  nimStrDestroy(X60Qtmp_0);}
string_0_sysvq0asl arenaReport_0_arecyyj7v(void){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  NB8 X60Qx_25;
  NB8 X60Qx_26;
  NB8 X60Qx_27;
  NB8 X60Qx_28;
  NB8 X60Qx_29;
  NB8 X60Qx_30;
  NB8 X60Qx_31;
  NB8 X60Qx_32;
  NB8 X60Qx_33;
  NB8 X60Qx_34;
  NI32 X60Qx_35 = countOf_0_croph25r5(cSeqBlocks_0_croph25r5);
  if (X60Qx_35 == 0){
    NI32 X60Qx_36 = countOf_0_croph25r5(cArrBlocks_0_croph25r5);
    X60Qx_34 = (X60Qx_36 == 0);}
  else {
    X60Qx_34 = NIM_FALSE;}
  if (X60Qx_34){
    NI32 X60Qx_37 = countOf_0_croph25r5(cCellBlocks_0_croph25r5);
    X60Qx_33 = (X60Qx_37 == 0);}
  else {
    X60Qx_33 = NIM_FALSE;}
  if (X60Qx_33){
    NI32 X60Qx_38 = countOf_0_croph25r5(cBytesDirect_0_croph25r5);
    X60Qx_32 = (X60Qx_38 == 0);}
  else {
    X60Qx_32 = NIM_FALSE;}
  if (X60Qx_32){
    NI32 X60Qx_39 = countOf_0_croph25r5(cBytesOverlay_0_croph25r5);
    X60Qx_31 = (X60Qx_39 == 0);}
  else {
    X60Qx_31 = NIM_FALSE;}
  if (X60Qx_31){
    NI32 X60Qx_40 = countOf_0_croph25r5(cPtrDeclines_0_croph25r5);
    X60Qx_30 = (X60Qx_40 == 0);}
  else {
    X60Qx_30 = NIM_FALSE;}
  if (X60Qx_30){
    NI32 X60Qx_41 = countOf_0_croph25r5(cUnhandled_0_croph25r5);
    X60Qx_29 = (X60Qx_41 == 0);}
  else {
    X60Qx_29 = NIM_FALSE;}
  if (X60Qx_29){
    NI32 X60Qx_42 = countOf_0_croph25r5(cLyingSeqs_0_croph25r5);
    X60Qx_28 = (X60Qx_42 == 0);}
  else {
    X60Qx_28 = NIM_FALSE;}
  if (X60Qx_28){
    NI32 X60Qx_43 = countOf_0_croph25r5(cPtrNoDeref_0_croph25r5);
    X60Qx_27 = (X60Qx_43 == 0);}
  else {
    X60Qx_27 = NIM_FALSE;}
  if (X60Qx_27){
    NI32 X60Qx_44 = countOf_0_croph25r5(cWbPtrHome_0_croph25r5);
    X60Qx_26 = (X60Qx_44 == 0);}
  else {
    X60Qx_26 = NIM_FALSE;}
  if (X60Qx_26){
    NI32 X60Qx_45 = countOf_0_croph25r5(cWbPtrLost_0_croph25r5);
    X60Qx_25 = (X60Qx_45 == 0);}
  else {
    X60Qx_25 = NIM_FALSE;}
  if (X60Qx_25){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 X60Qx_46 = countOf_0_croph25r5(cSeqBlocks_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_0 = dollarQ_2_sysvq0asl(X60Qx_46);
  NI32 X60Qx_47 = countOf_0_croph25r5(cArrBlocks_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_1 = dollarQ_2_sysvq0asl(X60Qx_47);
  NI32 X60Qx_48 = countOf_0_croph25r5(cCellBlocks_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_2 = dollarQ_2_sysvq0asl(X60Qx_48);
  NI32 X60Qx_49 = countOf_0_croph25r5(cBytesDirect_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_3 = dollarQ_2_sysvq0asl(X60Qx_49);
  NI32 X60Qx_50 = countOf_0_croph25r5(cBytesOverlay_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_4 = dollarQ_2_sysvq0asl(X60Qx_50);
  NI32 X60Qx_51 = countOf_0_croph25r5(cPtrNoDeref_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_5 = dollarQ_2_sysvq0asl(X60Qx_51);
  NI32 X60Qx_52 = countOf_0_croph25r5(cPtrDeclines_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_6 = dollarQ_2_sysvq0asl(X60Qx_52);
  NI32 X60Qx_53 = countOf_0_croph25r5(cWbPtrHome_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_7 = dollarQ_2_sysvq0asl(X60Qx_53);
  NI32 X60Qx_54 = countOf_0_croph25r5(cWbPtrLost_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_8 = dollarQ_2_sysvq0asl(X60Qx_54);
  NI32 X60Qx_55 = countOf_0_croph25r5(cUnhandled_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_9 = dollarQ_2_sysvq0asl(X60Qx_55);
  string_0_sysvq0asl X60Qdesugar_10 = itemsOf_0_croph25r5(cUnhandled_0_croph25r5);
  NI32 X60Qx_56 = countOf_0_croph25r5(cLyingSeqs_0_croph25r5);
  string_0_sysvq0asl X60Qdesugar_11 = dollarQ_2_sysvq0asl(X60Qx_56);
  NI32 X60Qx_57 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I2925818693908859700_arecyyj7v)}
  );
  NI32 X60Qx_58 = len_4_sysvq0asl(X60Qdesugar_0);
  NI32 X60Qx_59 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I7220483300902828320_arecyyj7v)}
  );
  NI32 X60Qx_60 = len_4_sysvq0asl(X60Qdesugar_1);
  NI32 X60Qx_61 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1700995326u, .more_0 = (&strlit_0_I1405192176789893522_arecyyj7v)}
  );
  NI32 X60Qx_62 = len_4_sysvq0asl(X60Qdesugar_2);
  NI32 X60Qx_63 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I6658469085088257676_arecyyj7v)}
  );
  NI32 X60Qx_64 = len_4_sysvq0asl(X60Qdesugar_3);
  NI32 X60Qx_65 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I2810153910757964428_arecyyj7v)}
  );
  NI32 X60Qx_66 = len_4_sysvq0asl(X60Qdesugar_4);
  NI32 X60Qx_67 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1953505534u, .more_0 = (&strlit_0_I7178761246479705055_arecyyj7v)}
  );
  NI32 X60Qx_68 = len_4_sysvq0asl(X60Qdesugar_5);
  NI32 X60Qx_69 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1953505534u, .more_0 = (&strlit_0_I5391896935332235772_arecyyj7v)}
  );
  NI32 X60Qx_70 = len_4_sysvq0asl(X60Qdesugar_6);
  NI32 X60Qx_71 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1651974398u, .more_0 = (&strlit_0_I9406485454641063824_arecyyj7v)}
  );
  NI32 X60Qx_72 = len_4_sysvq0asl(X60Qdesugar_7);
  NI32 X60Qx_73 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1651974398u, .more_0 = (&strlit_0_I11318396273308722532_arecyyj7v)}
  );
  NI32 X60Qx_74 = len_4_sysvq0asl(X60Qdesugar_8);
  NI32 X60Qx_75 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I4924544341798789442_arecyyj7v)}
  );
  NI32 X60Qx_76 = len_4_sysvq0asl(X60Qdesugar_9);
  NI32 X60Qx_77 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 23297u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_78 = len_4_sysvq0asl(X60Qdesugar_10);
  NI32 X60Qx_79 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 23809u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_80 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2037129470u, .more_0 = (&strlit_0_I5796312517412486244_arecyyj7v)}
  );
  NI32 X60Qx_81 = len_4_sysvq0asl(X60Qdesugar_11);
  string_0_sysvq0asl X60Qdesugar_12 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_57 + X60Qx_58)) + X60Qx_59)) + X60Qx_60)) + X60Qx_61)) + X60Qx_62)) + X60Qx_63)) + X60Qx_64)) + X60Qx_65)) + X60Qx_66)) + X60Qx_67)) + X60Qx_68)) + X60Qx_69)) + X60Qx_70)) + X60Qx_71)) + X60Qx_72)) + X60Qx_73)) + X60Qx_74)) + X60Qx_75)) + X60Qx_76)) + X60Qx_77)) + X60Qx_78)) + X60Qx_79)) + X60Qx_80)) + X60Qx_81)));
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I2925818693908859700_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_0);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I7220483300902828320_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_1);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 1700995326u, .more_0 = (&strlit_0_I1405192176789893522_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_2);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I6658469085088257676_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_3);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I2810153910757964428_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_4);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 1953505534u, .more_0 = (&strlit_0_I7178761246479705055_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_5);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 1953505534u, .more_0 = (&strlit_0_I5391896935332235772_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_6);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 1651974398u, .more_0 = (&strlit_0_I9406485454641063824_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_7);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 1651974398u, .more_0 = (&strlit_0_I11318396273308722532_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_8);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I4924544341798789442_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_9);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 23297u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_10);
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 23809u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
    .bytes_0 = 2037129470u, .more_0 = (&strlit_0_I5796312517412486244_arecyyj7v)}
  );
  add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_11);
  nimStrDestroy(result_0);
  result_0 = X60Qdesugar_12;
  nimStrWasMoved((&X60Qdesugar_12));
  nimStrDestroy(X60Qdesugar_12);
  nimStrDestroy(X60Qdesugar_11);
  nimStrDestroy(X60Qdesugar_10);
  nimStrDestroy(X60Qdesugar_9);
  nimStrDestroy(X60Qdesugar_8);
  nimStrDestroy(X60Qdesugar_7);
  nimStrDestroy(X60Qdesugar_6);
  nimStrDestroy(X60Qdesugar_5);
  nimStrDestroy(X60Qdesugar_4);
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(X60Qdesugar_1);
  nimStrDestroy(X60Qdesugar_0);
  return result_0;
  nimStrDestroy(X60Qdesugar_12);
  nimStrDestroy(X60Qdesugar_11);
  nimStrDestroy(X60Qdesugar_10);
  nimStrDestroy(X60Qdesugar_9);
  nimStrDestroy(X60Qdesugar_8);
  nimStrDestroy(X60Qdesugar_7);
  nimStrDestroy(X60Qdesugar_6);
  nimStrDestroy(X60Qdesugar_5);
  nimStrDestroy(X60Qdesugar_4);
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(X60Qdesugar_1);
  nimStrDestroy(X60Qdesugar_0);
  return result_0;}
ArenaMat_0_arecyyj7v initArenaMat_0_arecyyj7v(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* a_0){
  ArenaMat_0_arecyyj7v result_1;
  eQwasmovedQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&result_1));
  arenaMatFailed_0_arecyyj7v = NIM_FALSE;
  eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&result_1));
  X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* X60Qx_82 = eQdupQ_ArefSX41renaX4fbj0arewp645e1_0_arecyyj7v(a_0);
  seq_0_Isge9lx_arecyyj7v X60Qx_83 = newSeqUninit_0_Iglb3hm1_arecyyj7v(0);
  seq_0_Idhq52f_arecyyj7v X60Qx_84 = newSeqUninit_0_I7mggr11_arecyyj7v(0);
  seq_0_Ijes23h1_arecyyj7v X60Qx_85 = newSeqUninit_0_I1oegnq1_arecyyj7v(0);
  result_1 = (ArenaMat_0_arecyyj7v){
    .a_0 = X60Qx_82, .seen_0 = X60Qx_83, .blocks_0 = X60Qx_84, .regions_0 = X60Qx_85}
  ;
  return result_1;}
NU32 seenGet_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_0, NU32 key_0){
  NU32 result_2;
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_86 = len_3_Ifjbd231_arecyyj7v((*m_0).seen_0);
      if (i_0 < X60Qx_86){
        MatEntry_0_arecyyj7v* X60Qx_87 = getQ_7_Ielxh6u1_arecyyj7v((*m_0).seen_0, i_0);
        if ((*X60Qx_87).key_0 == key_0){
          MatEntry_0_arecyyj7v* X60Qx_88 = getQ_7_Ielxh6u1_arecyyj7v((*m_0).seen_0, i_0);
          result_2 = (*X60Qx_88).box_0;
          return result_2;}
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_2 = 0u;
  return result_2;}
NI32 scalarSize_0_arecyyj7v(Value_0_valzr1t4f* v_0){
  NI32 result_3;
  NI64 X60Qx_0;
  switch ((*v_0).kind_0){
    case 1:
    case 2:
    {
      NI64 X60Qx_1;
      if ((*v_0).bits_0 <= 0){
        X60Qx_1 = 8;}
      else {
        X60Qx_1 = ((NI32)((*v_0).bits_0 / 8));}
      X60Qx_0 = X60Qx_1;}
    break;
    case 3:
    {
      NI64 X60Qx_2;
      if ((*v_0).fbits_0 == 32){
        X60Qx_2 = 4;}
      else {
        X60Qx_2 = 8;}
      X60Qx_0 = X60Qx_2;}
    break;
    case 4:
    {
      X60Qx_0 = 1;}
    break;
    case 5:
    {
      X60Qx_0 = 1;}
    break;
    case 7:
    {
      X60Qx_0 = 4;}
    break;
    default:
    {
      X60Qx_0 = 0;}
    break;}
  result_3 = X60Qx_0;
  return result_3;}
NU64 scalarToU64_0_arecyyj7v(Value_0_valzr1t4f* v_1){
  NU64 result_4;
  NU64 X60Qx_3;
  switch ((*v_1).kind_0){
    case 1:
    case 2:
    {
      NI64 X60Qx_89 = asInt_0_valzr1t4f((&(*v_1)));
      X60Qx_3 = ((NU64)X60Qx_89);}
    break;
    case 5:
    {
      X60Qx_3 = ((NU64)((NU8)(*v_1).cval_0));}
    break;
    case 4:
    {
      NU64 X60Qx_4;
      if ((*v_1).bval_0){
        X60Qx_4 = ((NU64)1u);}
      else {
        X60Qx_4 = ((NU64)0u);}
      X60Qx_3 = X60Qx_4;}
    break;
    case 7:
    {
      X60Qx_3 = ((NU64)((NU32)((NI32)(*v_1).eord_0)));}
    break;
    case 3:
    {
      NU64 X60Qx_5;
      if ((*v_1).fbits_0 == 32){
        NF32 X60Qx_90 = ((NF32)(*v_1).fval_0);
        NU32 X60Qx_91;
        copyMem_0_sysvq0asl((&X60Qx_91), (&X60Qx_90), sizeof(NU32));
        X60Qx_5 = ((NU64)X60Qx_91);}
      else {
        NF64 X60Qx_92 = (*v_1).fval_0;
        NU64 X60Qx_93;
        copyMem_0_sysvq0asl((&X60Qx_93), (&X60Qx_92), sizeof(NU64));
        X60Qx_5 = X60Qx_93;}
      X60Qx_3 = X60Qx_5;}
    break;
    default:
    {
      X60Qx_3 = ((NU64)0u);}
    break;}
  result_4 = X60Qx_3;
  return result_4;}
void writeScalar_0_arecyyj7v(void* dst_0, NI32 off_0, Value_0_valzr1t4f* v_2){
  NI32 n_1 = scalarSize_0_arecyyj7v((&(*v_2)));
  NU64 u_0 = scalarToU64_0_arecyyj7v((&(*v_2)));
  NI32 i_2 = 0;
  {
    while (i_2 < n_1){
      pokeByte_0_arewp645e1(dst_0, ((NI32)(off_0 + i_2)), ((NU8)((NU64)(((NU64)(u_0 >> ((NU32)(((NU32)i_2) * 8u)))) & ((NU64)255u)))));
      inc_1_I6wjjge_aow2h993l1((&i_2));}}
  whileStmtLabel_0: ;}
void writeScalarSized_0_arecyyj7v(void* dst_1, NI32 off_1, Value_0_valzr1t4f* v_3, NI32 fsize_0){
  NB8 X60Qx_94;
  if (fsize_0 <= 0){
    X60Qx_94 = NIM_TRUE;}
  else {
    NI32 X60Qx_95 = scalarSize_0_arecyyj7v((&(*v_3)));
    X60Qx_94 = (fsize_0 == X60Qx_95);}
  if (X60Qx_94){
    writeScalar_0_arecyyj7v(dst_1, off_1, (&(*v_3)));}
  else {
    NB8 X60Qx_96;
    NB8 X60Qx_97;
    NB8 X60Qx_98;
    if ((*v_3).kind_0 == 1){
      X60Qx_98 = NIM_TRUE;}
    else {
      X60Qx_98 = ((*v_3).kind_0 == 2);}
    if (X60Qx_98){
      X60Qx_97 = NIM_TRUE;}
    else {
      X60Qx_97 = ((*v_3).kind_0 == 4);}
    if (X60Qx_97){
      X60Qx_96 = NIM_TRUE;}
    else {
      X60Qx_96 = ((*v_3).kind_0 == 5);}
    if (X60Qx_96){
      NU64 u_1 = scalarToU64_0_arecyyj7v((&(*v_3)));
      NI32 i_3 = 0;
      {
        while (NIM_TRUE){
          NB8 X60Qx_99;
          if (i_3 < fsize_0){
            X60Qx_99 = (i_3 < 8);}
          else {
            X60Qx_99 = NIM_FALSE;}
          if (X60Qx_99){
            pokeByte_0_arewp645e1(dst_1, ((NI32)(off_1 + i_3)), ((NU8)((NU64)(((NU64)(u_1 >> ((NU32)(((NU32)i_3) * 8u)))) & ((NU64)255u)))));
            inc_1_I6wjjge_aow2h993l1((&i_3));}
          else {
            break;}}}
      whileStmtLabel_0: ;}
    else {
      string_0_sysvq0asl X60Qdesugar_13 = dollarQ_2_sysvq0asl(fsize_0);
      NI32 X60Qx_100 = scalarSize_0_arecyyj7v((&(*v_3)));
      string_0_sysvq0asl X60Qdesugar_14 = dollarQ_2_sysvq0asl(X60Qx_100);
      NI32 X60Qx_101 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1633907710u, .more_0 = (&strlit_0_I4032485569337694205_arecyyj7v)}
      );
      NI32 X60Qx_102 = len_4_sysvq0asl(X60Qdesugar_13);
      NI32 X60Qx_103 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1937121534u, .more_0 = (&strlit_0_I8126988068395022829_arecyyj7v)}
      );
      NI32 X60Qx_104 = len_4_sysvq0asl(X60Qdesugar_14);
      string_0_sysvq0asl X60Qdesugar_15 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_101 + X60Qx_102)) + X60Qx_103)) + X60Qx_104)));
      add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
        .bytes_0 = 1633907710u, .more_0 = (&strlit_0_I4032485569337694205_arecyyj7v)}
      );
      add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_13);
      add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
        .bytes_0 = 1937121534u, .more_0 = (&strlit_0_I8126988068395022829_arecyyj7v)}
      );
      add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_14);
      noteUnhandled_0_arecyyj7v(X60Qdesugar_15);
      nimStrDestroy(X60Qdesugar_15);
      nimStrDestroy(X60Qdesugar_14);
      nimStrDestroy(X60Qdesugar_13);}}}
X60Qt_0_IAtupleApointerZAR6_arecyyj7v refBox_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_1, NI32 payloadSize_0){
  X60Qt_0_IAtupleApointerZAR6_arecyyj7v result_5;
  NI32 total_0 = ((NI32)(((NI32)8) + payloadSize_0));
  void* box_0 = arenaAlloc_0_arewp645e1((*m_1).a_0, total_0, ((NI32)8));
  pokeU64_0_arewp645e1(box_0, ((NI32)0), ((NU64)1099511627776ull));
  void* payload_0 = ((void*)((NU32)(((NU32)box_0) + ((NU32)((NI32)8)))));
  result_5 = (X60Qt_0_IAtupleApointerZAR6_arecyyj7v){
    .fld_0 = box_0, .fld_1 = payload_0}
  ;
  return result_5;}
static inline NU32 cellKey_0_arecyyj7v(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_0){
  NU32 result_7;
  result_7 = ((NU32)c_0);
  return result_7;}
NI32 elemStride_0_arecyyj7v(Value_0_valzr1t4f* v_5){
  NI32 result_8;
  NI32 X60Qx_6;
  switch ((*v_5).kind_0){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    {
      NI32 X60Qx_107 = scalarSize_0_arecyyj7v((&(*v_5)));
      X60Qx_6 = X60Qx_107;}
    break;
    case 12:
    {
      X60Qx_6 = ((NI32)8);}
    break;
    case 8:
    {
      X60Qx_6 = ((NI32)16);}
    break;
    case 11:
    case 10:
    {
      NI32 X60Qx_7;
      if ((!((*v_5).obj_0 == NIM_NIL))){
        NI32 X60Qx_108 = sizeOfSym_0_fiepkwzpc((*(*v_5).obj_0).d_00.typeSym_0);
        X60Qx_7 = X60Qx_108;}
      else {
        X60Qx_7 = 0;}
      X60Qx_6 = X60Qx_7;}
    break;
    case 9:
    {
      NI32 X60Qx_8;
      NB8 X60Qx_109;
      NB8 X60Qx_110;
      if ((!((*v_5).arr_0 == NIM_NIL))){
        X60Qx_110 = (0 < (*(*v_5).arr_0).d_00.elems_0.len_0);}
      else {
        X60Qx_110 = NIM_FALSE;}
      if (X60Qx_110){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_111 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).arr_0).d_00.elems_0, 0);
        X60Qx_109 = (!((*X60Qx_111) == NIM_NIL));}
      else {
        X60Qx_109 = NIM_FALSE;}
      if (X60Qx_109){
        NI32 X60Qx_112 = len_3_I83dzei_arecyyj7v((*(*v_5).arr_0).d_00.elems_0);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_113 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).arr_0).d_00.elems_0, 0);
        NI32 X60Qx_114 = elemStride_0_arecyyj7v((&(*(*X60Qx_113)).d_00.v_0));
        X60Qx_8 = ((NI32)(X60Qx_112 * X60Qx_114));}
      else {
        X60Qx_8 = 0;}
      X60Qx_6 = X60Qx_8;}
    break;
    case 6:
    {
      noteUnhandled_0_arecyyj7v((string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I2747239888017569374_arecyyj7v)}
      );
      X60Qx_6 = 0;}
    break;
    default:
    {
      noteUnhandled_0_arecyyj7v((string_0_sysvq0asl){
        .bytes_0 = 1701602814u, .more_0 = (&strlit_0_I17933319393316134329_arecyyj7v)}
      );
      X60Qx_6 = 0;}
    break;}
  result_8 = X60Qx_6;
  return result_8;}
NI32 blockGet_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_6, NU32 key_1){
  NI32 result_9;
  NI32 i_5 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_115 = len_3_I80y55d1_arecyyj7v((*m_6).blocks_0);
      if (i_5 < X60Qx_115){
        BlockEntry_0_arecyyj7v* X60Qx_116 = getQ_7_Iyxduse_arecyyj7v((*m_6).blocks_0, i_5);
        if ((*X60Qx_116).key_0 == key_1){
          return i_5;}
        inc_1_I6wjjge_aow2h993l1((&i_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_9 = -1;
  return result_9;}
BlockEntry_0_arecyyj7v seqBlock_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_7, X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_0){
  BlockEntry_0_arecyyj7v result_10;
  eQwasmovedQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&result_10));
  NU32 key_2 = ((NU32)sb_0);
  NI32 hit_0 = blockGet_0_arecyyj7v((&(*m_7)), key_2);
  if (0 <= hit_0){
    BlockEntry_0_arecyyj7v* X60Qx_117 = getQ_7_Iyxduse_arecyyj7v((*m_7).blocks_0, hit_0);
    BlockEntry_0_arecyyj7v X60QconstRefTemp_0 = (*X60Qx_117);
    BlockEntry_0_arecyyj7v X60Qx_118 = eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&X60QconstRefTemp_0));
    result_10 = X60Qx_118;
    return result_10;}
  NI32 X60Qx_9;
  if ((!(sb_0 == NIM_NIL))){
    NI32 X60Qx_119 = len_3_I83dzei_arecyyj7v((*sb_0).d_00.elems_0);
    X60Qx_9 = X60Qx_119;}
  else {
    X60Qx_9 = 0;}
  NI32 n_2 = X60Qx_9;
  NI32 stride_0 = 0;
  NB8 X60Qx_120;
  if (0 < n_2){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_121 = getQ_7_Ii14ync1_arecyyj7v((*sb_0).d_00.elems_0, 0);
    X60Qx_120 = (!((*X60Qx_121) == NIM_NIL));}
  else {
    X60Qx_120 = NIM_FALSE;}
  if (X60Qx_120){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_122 = getQ_7_Ii14ync1_arecyyj7v((*sb_0).d_00.elems_0, 0);
    NI32 X60Qx_123 = elemStride_0_arecyyj7v((&(*(*X60Qx_122)).d_00.v_0));
    stride_0 = X60Qx_123;}
  void* data_1 = NIM_NIL;
  NB8 X60Qx_124;
  if (0 < n_2){
    X60Qx_124 = (0 < stride_0);}
  else {
    X60Qx_124 = NIM_FALSE;}
  if (X60Qx_124){
    void* X60Qx_125 = arenaAlloc_0_arewp645e1((*m_7).a_0, ((NI32)(n_2 * stride_0)), ((NI32)8));
    data_1 = X60Qx_125;}
  eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&result_10));
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_126 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(sb_0);
  result_10 = (BlockEntry_0_arecyyj7v){
    .key_0 = key_2, .data_0 = ((NU32)data_1), .stride_0 = stride_0, .count_0 = n_2, .sq_0 = X60Qx_126, .arr_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .cell_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}
  ;
  bump_0_croph25r5(cSeqBlocks_0_croph25r5, 1);
  BlockEntry_0_arecyyj7v X60Qx_127 = eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&result_10));
  add_0_I52sfn71_arecyyj7v((&(*m_7).blocks_0), X60Qx_127);
  if ((!(data_1 == NIM_NIL))){
    NI32 i_7 = 0;
    {
      while (i_7 < n_2){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_128 = getQ_7_Ii14ync1_arecyyj7v((*sb_0).d_00.elems_0, i_7);
        if ((!((*X60Qx_128) == NIM_NIL))){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_129 = getQ_7_Ii14ync1_arecyyj7v((*sb_0).d_00.elems_0, i_7);
          placeField_1_arecyyj7v(m_7, data_1, ((NI32)(i_7 * stride_0)), (&(*(*X60Qx_129)).d_00.v_0), 0);}
        inc_1_I6wjjge_aow2h993l1((&i_7));}}
    whileStmtLabel_0: ;}
  return result_10;}
BlockEntry_0_arecyyj7v arrBlock_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_8, X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* ab_0){
  BlockEntry_0_arecyyj7v result_11;
  eQwasmovedQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&result_11));
  NU32 key_3 = ((NU32)ab_0);
  NI32 hit_1 = blockGet_0_arecyyj7v((&(*m_8)), key_3);
  if (0 <= hit_1){
    BlockEntry_0_arecyyj7v* X60Qx_130 = getQ_7_Iyxduse_arecyyj7v((*m_8).blocks_0, hit_1);
    BlockEntry_0_arecyyj7v X60QconstRefTemp_0 = (*X60Qx_130);
    BlockEntry_0_arecyyj7v X60Qx_131 = eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&X60QconstRefTemp_0));
    result_11 = X60Qx_131;
    return result_11;}
  NI32 X60Qx_10;
  if ((!(ab_0 == NIM_NIL))){
    NI32 X60Qx_132 = len_3_I83dzei_arecyyj7v((*ab_0).d_00.elems_0);
    X60Qx_10 = X60Qx_132;}
  else {
    X60Qx_10 = 0;}
  NI32 n_3 = X60Qx_10;
  NI32 stride_1 = 0;
  NB8 X60Qx_133;
  if (0 < n_3){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_134 = getQ_7_Ii14ync1_arecyyj7v((*ab_0).d_00.elems_0, 0);
    X60Qx_133 = (!((*X60Qx_134) == NIM_NIL));}
  else {
    X60Qx_133 = NIM_FALSE;}
  if (X60Qx_133){
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_135 = getQ_7_Ii14ync1_arecyyj7v((*ab_0).d_00.elems_0, 0);
    NI32 X60Qx_136 = elemStride_0_arecyyj7v((&(*(*X60Qx_135)).d_00.v_0));
    stride_1 = X60Qx_136;}
  void* data_2 = NIM_NIL;
  NB8 X60Qx_137;
  if (0 < n_3){
    X60Qx_137 = (0 < stride_1);}
  else {
    X60Qx_137 = NIM_FALSE;}
  if (X60Qx_137){
    void* X60Qx_138 = arenaAlloc_0_arewp645e1((*m_8).a_0, ((NI32)(n_3 * stride_1)), ((NI32)8));
    data_2 = X60Qx_138;}
  eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&result_11));
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_139 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(ab_0);
  result_11 = (BlockEntry_0_arecyyj7v){
    .key_0 = key_3, .data_0 = ((NU32)data_2), .stride_0 = stride_1, .count_0 = n_3, .sq_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arr_0 = X60Qx_139, .cell_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}
  ;
  bump_0_croph25r5(cArrBlocks_0_croph25r5, 1);
  BlockEntry_0_arecyyj7v X60Qx_140 = eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&result_11));
  add_0_I52sfn71_arecyyj7v((&(*m_8).blocks_0), X60Qx_140);
  if ((!(data_2 == NIM_NIL))){
    NI32 i_8 = 0;
    {
      while (i_8 < n_3){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_141 = getQ_7_Ii14ync1_arecyyj7v((*ab_0).d_00.elems_0, i_8);
        if ((!((*X60Qx_141) == NIM_NIL))){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_142 = getQ_7_Ii14ync1_arecyyj7v((*ab_0).d_00.elems_0, i_8);
          placeField_1_arecyyj7v(m_8, data_2, ((NI32)(i_8 * stride_1)), (&(*(*X60Qx_142)).d_00.v_0), 0);}
        inc_1_I6wjjge_aow2h993l1((&i_8));}}
    whileStmtLabel_0: ;}
  return result_11;}
BlockEntry_0_arecyyj7v cellBlock_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_9, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1, NI32 wantSize_0){
  BlockEntry_0_arecyyj7v result_12;
  eQwasmovedQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&result_12));
  NU32 key_4 = ((NU32)c_1);
  NI32 hit_2 = blockGet_0_arecyyj7v((&(*m_9)), key_4);
  if (0 <= hit_2){
    BlockEntry_0_arecyyj7v* X60Qx_143 = getQ_7_Iyxduse_arecyyj7v((*m_9).blocks_0, hit_2);
    BlockEntry_0_arecyyj7v X60QconstRefTemp_0 = (*X60Qx_143);
    BlockEntry_0_arecyyj7v X60Qx_144 = eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&X60QconstRefTemp_0));
    result_12 = X60Qx_144;
    return result_12;}
  NI32 stride_2 = 0;
  if (0 < wantSize_0){
    stride_2 = wantSize_0;}
  else {
    if ((!(c_1 == NIM_NIL))){
      NI32 X60Qx_145 = elemStride_0_arecyyj7v((&(*c_1).d_00.v_0));
      stride_2 = X60Qx_145;}}
  void* data_3 = NIM_NIL;
  if (0 < stride_2){
    void* X60Qx_146 = arenaAlloc_0_arewp645e1((*m_9).a_0, stride_2, ((NI32)8));
    data_3 = X60Qx_146;}
  NI64 X60Qx_11;
  if ((!(data_3 == NIM_NIL))){
    X60Qx_11 = 1;}
  else {
    X60Qx_11 = 0;}
  eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&result_12));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_147 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v(c_1);
  result_12 = (BlockEntry_0_arecyyj7v){
    .key_0 = key_4, .data_0 = ((NU32)data_3), .stride_0 = stride_2, .count_0 = X60Qx_11, .sq_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arr_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .cell_0 = X60Qx_147}
  ;
  bump_0_croph25r5(cCellBlocks_0_croph25r5, 1);
  BlockEntry_0_arecyyj7v X60Qx_148 = eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&result_12));
  add_0_I52sfn71_arecyyj7v((&(*m_9).blocks_0), X60Qx_148);
  if ((!(data_3 == NIM_NIL))){
    placeField_1_arecyyj7v(m_9, data_3, 0, (&(*c_1).d_00.v_0), stride_2);}
  return result_12;}
NB8 bytesHoldWholeObject_0_arecyyj7v(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_0){
  NB8 result_13;
  if (r_0 == NIM_NIL){
    return NIM_FALSE;}
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* ov_0 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v((*r_0).d_00.objOverlay_0);
  if (ov_0 == NIM_NIL){
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(ov_0);
    return NIM_TRUE;}
  NI32 i_9 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_149 = len_3_I83dzei_arecyyj7v((*ov_0).d_00.cells_0);
      if (i_9 < X60Qx_149){
        NB8 X60Qx_150;
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_151 = getQ_7_Ii14ync1_arecyyj7v((*ov_0).d_00.cells_0, i_9);
        if ((!((*X60Qx_151) == NIM_NIL))){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_152 = getQ_7_Ii14ync1_arecyyj7v((*ov_0).d_00.cells_0, i_9);
          X60Qx_150 = (!((*(*X60Qx_152)).d_00.v_0.kind_0 == 0));}
        else {
          X60Qx_150 = NIM_FALSE;}
        if (X60Qx_150){
          eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(ov_0);
          return NIM_FALSE;}
        inc_1_I6wjjge_aow2h993l1((&i_9));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_13 = NIM_TRUE;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(ov_0);
  return result_13;
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(ov_0);
  return result_13;}
void noteRegionHandout_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_10, X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_1){
  NB8 X60Qx_153;
  if (r_1 == NIM_NIL){
    X60Qx_153 = NIM_TRUE;}
  else {
    NI32 X60Qx_154 = len_3_Izoe8zv_arecyyj7v((*r_1).d_00.bytes_0);
    X60Qx_153 = (X60Qx_154 <= 0);}
  if (X60Qx_153){
    return;}
  NU8* X60Qx_155 = getQ_7_Ig0r1051_arecyyj7v((*r_1).d_00.bytes_0, 0);
  NU32 b_0 = ((NU32)(&(*X60Qx_155)));
  NI32 i_11 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_156 = len_3_Io8yozm_arecyyj7v((*m_10).regions_0);
      if (i_11 < X60Qx_156){
        RegionHandout_0_arecyyj7v* X60Qx_157 = getQ_7_Irzlyr2_arecyyj7v((*m_10).regions_0, i_11);
        if ((*X60Qx_157).base_0 == b_0){
          return;}
        inc_1_I6wjjge_aow2h993l1((&i_11));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_158 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(r_1);
  NI32 X60Qx_159 = len_3_Izoe8zv_arecyyj7v((*r_1).d_00.bytes_0);
  add_0_Ilvs1p91_arecyyj7v((&(*m_10).regions_0), (RegionHandout_0_arecyyj7v){
    .r_0 = X60Qx_158, .base_0 = b_0, .size_0 = X60Qx_159}
  );}
X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v unmaterializePtr_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_11, NU32 a_1, Value_0_valzr1t4f* old_0){
  X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v result_14;
  eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_arecyyj7v((&result_14));
  eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_arecyyj7v((&result_14));
  Value_0_valzr1t4f X60Qx_160 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*old_0)));
  result_14 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v){
    .fld_0 = X60Qx_160, .fld_1 = NIM_FALSE}
  ;
  NI32 i_13 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_161 = len_3_Io8yozm_arecyyj7v((*m_11).regions_0);
      if (i_13 < X60Qx_161){
        RegionHandout_0_arecyyj7v* X60Qx_162 = getQ_7_Irzlyr2_arecyyj7v((*m_11).regions_0, i_13);
        RegionHandout_0_arecyyj7v h_0 = eQdupQ_SX52egionX48andout0arecyyj7v_0_arecyyj7v((*X60Qx_162));
        NB8 X60Qx_163;
        if (h_0.base_0 <= a_1){
          X60Qx_163 = (a_1 <= ((NU32)(h_0.base_0 + ((NU32)h_0.size_0))));}
        else {
          X60Qx_163 = NIM_FALSE;}
        if (X60Qx_163){
          NI16 X60Qx_164 = elemBits_0_valzr1t4f((&(*old_0)));
          TCode_0_valzr1t4f X60Qx_165 = ecode_0_valzr1t4f((&(*old_0)));
          NU32 X60Qx_166 = etype_0_valzr1t4f((&(*old_0)));
          Value_0_valzr1t4f nv_0 = vPtrRegT_0_valzr1t4f(h_0.r_0, ((NI32)((NU32)(a_1 - h_0.base_0))), X60Qx_164, X60Qx_165, X60Qx_166);
          bump_0_croph25r5(cWbPtrHome_0_croph25r5, 1);
          Value_0_valzr1t4f X60Qtmp_1 = nv_0;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
          result_14 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v){
            .fld_0 = X60Qtmp_1, .fld_1 = NIM_TRUE}
          ;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
          eQdestroyQ_SX52egionX48andout0arecyyj7v_0_arecyyj7v(h_0);
          return result_14;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));}
        inc_1_I6wjjge_aow2h993l1((&i_13));
        eQdestroyQ_SX52egionX48andout0arecyyj7v_0_arecyyj7v(h_0);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 k_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_167 = len_3_I80y55d1_arecyyj7v((*m_11).blocks_0);
      if (k_0 < X60Qx_167){
        BlockEntry_0_arecyyj7v* X60Qx_168 = getQ_7_Iyxduse_arecyyj7v((*m_11).blocks_0, k_0);
        BlockEntry_0_arecyyj7v X60QconstRefTemp_0 = (*X60Qx_168);
        BlockEntry_0_arecyyj7v b_1 = eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&X60QconstRefTemp_0));
        NB8 X60Qx_169;
        NB8 X60Qx_170;
        NB8 X60Qx_171;
        NB8 X60Qx_172;
        if ((!(b_1.data_0 == 0u))){
          X60Qx_172 = (0 < b_1.stride_0);}
        else {
          X60Qx_172 = NIM_FALSE;}
        if (X60Qx_172){
          X60Qx_171 = (0 < b_1.count_0);}
        else {
          X60Qx_171 = NIM_FALSE;}
        if (X60Qx_171){
          X60Qx_170 = (b_1.data_0 <= a_1);}
        else {
          X60Qx_170 = NIM_FALSE;}
        if (X60Qx_170){
          X60Qx_169 = (a_1 <= ((NU32)(b_1.data_0 + ((NU32)((NI32)(b_1.count_0 * b_1.stride_0))))));}
        else {
          X60Qx_169 = NIM_FALSE;}
        if (X60Qx_169){
          NU32 delta_0 = ((NU32)(a_1 - b_1.data_0));
          if ((!(((NI32)(((NI32)delta_0) % b_1.stride_0)) == 0))){
            bump_0_croph25r5(cWbPtrLost_0_croph25r5, 1);
            Value_0_valzr1t4f X60Qx_173 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*old_0)));
            result_14 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v){
              .fld_0 = X60Qx_173, .fld_1 = NIM_FALSE}
            ;
            eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_1));
            return result_14;}
          NB8 X60Qx_174;
          NB8 X60Qx_175;
          if (b_1.sq_0 == NIM_NIL){
            X60Qx_175 = (b_1.arr_0 == NIM_NIL);}
          else {
            X60Qx_175 = NIM_FALSE;}
          if (X60Qx_175){
            X60Qx_174 = (!(delta_0 == 0u));}
          else {
            X60Qx_174 = NIM_FALSE;}
          if (X60Qx_174){
            bump_0_croph25r5(cWbPtrLost_0_croph25r5, 1);
            Value_0_valzr1t4f X60Qx_176 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*old_0)));
            result_14 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v){
              .fld_0 = X60Qx_176, .fld_1 = NIM_FALSE}
            ;
            eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_1));
            return result_14;}
          Value_0_valzr1t4f nv_1 = vPtrArr_0_valzr1t4f(b_1.cell_0, b_1.arr_0, b_1.sq_0, ((NI32)(((NI32)delta_0) / b_1.stride_0)));
          X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* nov_0 = ovMut_0_valzr1t4f((&nv_1));
          NI16 X60Qx_177 = elemBits_0_valzr1t4f((&(*old_0)));
          (*nov_0).d_00.elemBits_0 = X60Qx_177;
          TCode_0_valzr1t4f X60Qx_178 = ecode_0_valzr1t4f((&(*old_0)));
          (*nov_0).d_00.ecode_0 = X60Qx_178;
          NU32 X60Qx_179 = etype_0_valzr1t4f((&(*old_0)));
          (*nov_0).d_00.etype_0 = X60Qx_179;
          bump_0_croph25r5(cWbPtrHome_0_croph25r5, 1);
          Value_0_valzr1t4f X60Qtmp_2 = nv_1;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_1));
          result_14 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v){
            .fld_0 = X60Qtmp_2, .fld_1 = NIM_TRUE}
          ;
          eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_arecyyj7v(nov_0);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_1));
          eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_1));
          return result_14;
          eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_arecyyj7v(nov_0);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_1));}
        inc_1_I6wjjge_aow2h993l1((&k_0));
        eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_1));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  bump_0_croph25r5(cWbPtrLost_0_croph25r5, 1);
  eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_arecyyj7v((&result_14));
  Value_0_valzr1t4f X60Qx_180 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*old_0)));
  result_14 = (X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v){
    .fld_0 = X60Qx_180, .fld_1 = NIM_FALSE}
  ;
  return result_14;}
void* materializePtr_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_12, Value_0_valzr1t4f* v_6, NB8 noDeref_0, NI32 wantSize_1){
  void* result_15;
  if ((!((*v_6).kind_0 == 13))){
    bump_0_croph25r5(cPtrDeclines_0_croph25r5, 1);
    return NIM_NIL;}
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_3 = region_0_valzr1t4f((&(*v_6)));
  if ((!(X60Qtmp_3 == NIM_NIL))){
    NB8 X60Qx_23;
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_4 = region_0_valzr1t4f((&(*v_6)));
    if ((!((*X60Qtmp_4).d_00.kind_0 == 0))){
      X60Qx_23 = NIM_TRUE;}
    else {
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_5 = region_0_valzr1t4f((&(*v_6)));
      X60Qx_23 = (*X60Qtmp_5).d_00.freed_0;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_5);}
    if (X60Qx_23){
      bump_0_croph25r5(cPtrDeclines_0_croph25r5, 1);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_4);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
      return NIM_NIL;}
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_6 = region_0_valzr1t4f((&(*v_6)));
    NI32 n_4 = len_3_Izoe8zv_arecyyj7v((*X60Qtmp_6).d_00.bytes_0);
    NI32 X60Qx_181 = foff_0_valzr1t4f((&(*v_6)));
    NI32 off_8 = ((NI32)X60Qx_181);
    NB8 X60Qx_182;
    NB8 X60Qx_183;
    if (n_4 <= 0){
      X60Qx_183 = NIM_TRUE;}
    else {
      X60Qx_183 = (off_8 < 0);}
    if (X60Qx_183){
      X60Qx_182 = NIM_TRUE;}
    else {
      X60Qx_182 = (n_4 <= off_8);}
    if (X60Qx_182){
      bump_0_croph25r5(cPtrDeclines_0_croph25r5, 1);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_6);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_4);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
      return NIM_NIL;}
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_7 = region_0_valzr1t4f((&(*v_6)));
    NB8 X60Qx_184 = bytesHoldWholeObject_0_arecyyj7v(X60Qtmp_7);
    if ((!X60Qx_184)){
      if ((!noDeref_0)){
        bump_0_croph25r5(cBytesOverlay_0_croph25r5, 1);
        bump_0_croph25r5(cPtrDeclines_0_croph25r5, 1);
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_7);
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_6);
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_4);
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
        return NIM_NIL;}
      bump_0_croph25r5(cPtrNoDeref_0_croph25r5, 1);
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_8 = region_0_valzr1t4f((&(*v_6)));
      noteRegionHandout_0_arecyyj7v(m_12, X60Qtmp_8);
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_9 = region_0_valzr1t4f((&(*v_6)));
      NU8* X60Qx_185 = getQ_7_Ig0r1051_arecyyj7v((*X60Qtmp_9).d_00.bytes_0, 0);
      result_15 = ((void*)((NU32)(((NU32)(&(*X60Qx_185))) + ((NU32)off_8))));
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_9);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_8);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_7);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_6);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_4);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
      return result_15;
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_9);
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_8);}
    bump_0_croph25r5(cBytesDirect_0_croph25r5, 1);
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_10 = region_0_valzr1t4f((&(*v_6)));
    noteRegionHandout_0_arecyyj7v(m_12, X60Qtmp_10);
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_11 = region_0_valzr1t4f((&(*v_6)));
    NU8* X60Qx_186 = getQ_7_Ig0r1051_arecyyj7v((*X60Qtmp_11).d_00.bytes_0, 0);
    result_15 = ((void*)((NU32)(((NU32)(&(*X60Qx_186))) + ((NU32)off_8))));
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_11);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_10);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_7);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_6);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_4);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
    return result_15;
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_11);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_10);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_7);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_6);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_4);}
  BlockEntry_0_arecyyj7v b_2 = (BlockEntry_0_arecyyj7v){
    .key_0 = ((NU32)0u), .data_0 = ((NU32)0u), .stride_0 = ((NI32)0), .count_0 = ((NI32)0), .sq_0 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .arr_0 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL), .cell_0 = ((X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}
  ;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_12 = seqOwn_0_valzr1t4f((&(*v_6)));
  if ((!(X60Qtmp_12 == NIM_NIL))){
    eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_2));
    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_13 = seqOwn_0_valzr1t4f((&(*v_6)));
    BlockEntry_0_arecyyj7v X60Qx_187 = seqBlock_0_arecyyj7v(m_12, X60Qtmp_13);
    b_2 = X60Qx_187;
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_13);}
  else {
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_14 = arrOwn_0_valzr1t4f((&(*v_6)));
    if ((!(X60Qtmp_14 == NIM_NIL))){
      eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_2));
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_15 = arrOwn_0_valzr1t4f((&(*v_6)));
      BlockEntry_0_arecyyj7v X60Qx_188 = arrBlock_0_arecyyj7v(m_12, X60Qtmp_15);
      b_2 = X60Qx_188;
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_15);}
    else {
      if ((!((*v_6).loc_0 == NIM_NIL))){
        eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_2));
        BlockEntry_0_arecyyj7v X60Qx_189 = cellBlock_0_arecyyj7v(m_12, (*v_6).loc_0, wantSize_1);
        b_2 = X60Qx_189;}
      else {
        bump_0_croph25r5(cPtrDeclines_0_croph25r5, 1);
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_14);
        eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_12);
        eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_2));
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
        return NIM_NIL;}}
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_14);}
  NB8 X60Qx_190;
  if (b_2.data_0 == 0u){
    X60Qx_190 = NIM_TRUE;}
  else {
    X60Qx_190 = (b_2.stride_0 <= 0);}
  if (X60Qx_190){
    bump_0_croph25r5(cPtrDeclines_0_croph25r5, 1);
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_12);
    eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_2));
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
    return NIM_NIL;}
  NI32 X60Qx_12;
  NB8 X60Qx_24;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_16 = seqOwn_0_valzr1t4f((&(*v_6)));
  if ((!(X60Qtmp_16 == NIM_NIL))){
    X60Qx_24 = NIM_TRUE;}
  else {
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_17 = arrOwn_0_valzr1t4f((&(*v_6)));
    X60Qx_24 = (!(X60Qtmp_17 == NIM_NIL));
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_17);}
  if (X60Qx_24){
    NI32 X60Qx_191 = base_0_valzr1t4f((&(*v_6)));
    X60Qx_12 = X60Qx_191;}
  else {
    X60Qx_12 = 0;}
  NI32 idx_0 = X60Qx_12;
  NB8 X60Qx_192;
  if (idx_0 < 0){
    X60Qx_192 = NIM_TRUE;}
  else {
    X60Qx_192 = (b_2.count_0 <= idx_0);}
  if (X60Qx_192){
    bump_0_croph25r5(cPtrDeclines_0_croph25r5, 1);
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_16);
    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_12);
    eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_2));
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
    return NIM_NIL;}
  result_15 = ((void*)((NU32)(b_2.data_0 + ((NU32)((NI32)(idx_0 * b_2.stride_0))))));
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_16);
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_12);
  eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_2));
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
  return result_15;
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_16);
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_12);
  eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_2));
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qtmp_3);
  return result_15;}
void placeSeqInline_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_13, void* dst_4, NI32 off_3, X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_1){
  BlockEntry_0_arecyyj7v b_3 = seqBlock_0_arecyyj7v(m_13, sb_1);
  NB8 X60Qx_193;
  if (0 < b_3.count_0){
    X60Qx_193 = (b_3.data_0 == 0u);}
  else {
    X60Qx_193 = NIM_FALSE;}
  if (X60Qx_193){
    bump_0_croph25r5(cLyingSeqs_0_croph25r5, 1);
    arenaMatFailed_0_arecyyj7v = NIM_TRUE;}
  pokeU64_0_arewp645e1(dst_4, ((NI32)(off_3 + ((NI32)0))), ((NU64)b_3.count_0));
  pokeU64_0_arewp645e1(dst_4, ((NI32)(off_3 + ((NI32)8))), ((NU64)b_3.data_0));
  eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_3));}
void placeField_1_arecyyj7v(ArenaMat_0_arecyyj7v* m_14, void* dst_5, NI32 off_4, Value_0_valzr1t4f* fv_1, NI32 fsize_2){
  switch ((*fv_1).kind_0){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    {
      writeScalarSized_0_arecyyj7v(dst_5, off_4, (&(*fv_1)), fsize_2);}
    break;
    case 11:
    case 10:
    {
      void* sub_0 = ((void*)((NU32)(((NU32)dst_5) + ((NU32)off_4))));
      placeObject_1_arecyyj7v(m_14, sub_0, (&(*fv_1)));}
    break;
    case 12:
    {
      void* p_0 = NIM_NIL;
      if ((!((*fv_1).rf_0 == NIM_NIL))){
        void* X60Qx_194 = materializeRef_1_arecyyj7v(m_14, (*fv_1).rf_0);
        p_0 = X60Qx_194;}
      pokeU64_0_arewp645e1(dst_5, off_4, ((NU64)((NU32)p_0)));}
    break;
    case 8:
    {
      placeSeqInline_0_arecyyj7v(m_14, dst_5, off_4, (*fv_1).sq_0);}
    break;
    case 13:
    {
      void* X60Qx_195 = materializePtr_0_arecyyj7v(m_14, (&(*fv_1)), NIM_FALSE, 0);
      pokeU64_0_arewp645e1(dst_5, off_4, ((NU64)((NU32)X60Qx_195)));}
    break;
    case 9:
    {
      NB8 X60Qx_196;
      NB8 X60Qx_197;
      if ((!((*fv_1).arr_0 == NIM_NIL))){
        X60Qx_197 = (0 < (*(*fv_1).arr_0).d_00.elems_0.len_0);}
      else {
        X60Qx_197 = NIM_FALSE;}
      if (X60Qx_197){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_198 = getQ_7_Ii14ync1_arecyyj7v((*(*fv_1).arr_0).d_00.elems_0, 0);
        X60Qx_196 = (!((*X60Qx_198) == NIM_NIL));}
      else {
        X60Qx_196 = NIM_FALSE;}
      if (X60Qx_196){
        NI32 st_0 = 0;
        NB8 X60Qx_199;
        if (0 < fsize_2){
          NI32 X60Qx_200 = len_3_I83dzei_arecyyj7v((*(*fv_1).arr_0).d_00.elems_0);
          X60Qx_199 = (((NI32)(fsize_2 % X60Qx_200)) == 0);}
        else {
          X60Qx_199 = NIM_FALSE;}
        if (X60Qx_199){
          NI32 X60Qx_201 = len_3_I83dzei_arecyyj7v((*(*fv_1).arr_0).d_00.elems_0);
          st_0 = ((NI32)(fsize_2 / X60Qx_201));}
        else {
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_202 = getQ_7_Ii14ync1_arecyyj7v((*(*fv_1).arr_0).d_00.elems_0, 0);
          NI32 X60Qx_203 = elemStride_0_arecyyj7v((&(*(*X60Qx_202)).d_00.v_0));
          st_0 = X60Qx_203;}
        if (0 < st_0){
          NI32 i_14 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_204 = len_3_I83dzei_arecyyj7v((*(*fv_1).arr_0).d_00.elems_0);
              if (i_14 < X60Qx_204){
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_205 = getQ_7_Ii14ync1_arecyyj7v((*(*fv_1).arr_0).d_00.elems_0, i_14);
                if ((!((*X60Qx_205) == NIM_NIL))){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_206 = getQ_7_Ii14ync1_arecyyj7v((*(*fv_1).arr_0).d_00.elems_0, i_14);
                  placeField_1_arecyyj7v(m_14, dst_5, ((NI32)(off_4 + ((NI32)(i_14 * st_0)))), (&(*(*X60Qx_206)).d_00.v_0), st_0);}
                inc_1_I6wjjge_aow2h993l1((&i_14));}
              else {
                break;}}}
          whileStmtLabel_0: ;}}}
    break;
    case 6:
    {
      noteUnhandled_0_arecyyj7v((string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I15497396085640490539_arecyyj7v)}
      );}
    break;
    default:
    {
      noteUnhandled_0_arecyyj7v((string_0_sysvq0asl){
        .bytes_0 = 1701406462u, .more_0 = (&strlit_0_I6918956669890399711_arecyyj7v)}
      );}
    break;}}
void placeObject_1_arecyyj7v(ArenaMat_0_arecyyj7v* m_15, void* dst_6, Value_0_valzr1t4f* v_7){
  if ((*v_7).obj_0 == NIM_NIL){
    return;}
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_1 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v((*v_7).obj_0);
  seq_0_Id0odh1_arecyyj7v fos_0 = fieldOffsetsOfType_0_fiepkwzpc((*box_1).d_00.typeSym_0);
  NI32 i_15 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_207;
      NI32 X60Qx_208 = len_3_I6y2imo_arecyyj7v((*box_1).d_00.names_0);
      if (i_15 < X60Qx_208){
        NI32 X60Qx_209 = len_3_I83dzei_arecyyj7v((*box_1).d_00.cells_0);
        X60Qx_207 = (i_15 < X60Qx_209);}
      else {
        X60Qx_207 = NIM_FALSE;}
      if (X60Qx_207){
        NI32 off_9 = -1;
        NI32 fsz_0 = 0;
        NI32 k_1 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_210 = len_3_If78p9o_arecyyj7v(fos_0);
            if (k_1 < X60Qx_210){
              FieldOff_0_fiepkwzpc* X60Qx_211 = getQ_7_Ivg8m7s_arecyyj7v(fos_0, k_1);
              NU32* X60Qx_212 = getQ_7_I2v00yv1_arecyyj7v((*box_1).d_00.names_0, i_15);
              NB8 X60Qx_213 = eqQ_0_nifh7u8pu1((*X60Qx_211).sym_0, (*X60Qx_212));
              if (X60Qx_213){
                FieldOff_0_fiepkwzpc* X60Qx_214 = getQ_7_Ivg8m7s_arecyyj7v(fos_0, k_1);
                off_9 = (*X60Qx_214).off_0;
                FieldOff_0_fiepkwzpc* X60Qx_215 = getQ_7_Ivg8m7s_arecyyj7v(fos_0, k_1);
                fsz_0 = (*X60Qx_215).size_0;
                goto whileStmtLabel_1;}
              inc_1_I6wjjge_aow2h993l1((&k_1));}
            else {
              break;}}}
        whileStmtLabel_1: ;
        NB8 X60Qx_216;
        if (0 <= off_9){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_217 = getQ_7_Ii14ync1_arecyyj7v((*box_1).d_00.cells_0, i_15);
          X60Qx_216 = (!((*X60Qx_217) == NIM_NIL));}
        else {
          X60Qx_216 = NIM_FALSE;}
        if (X60Qx_216){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_218 = getQ_7_Ii14ync1_arecyyj7v((*box_1).d_00.cells_0, i_15);
          placeField_1_arecyyj7v(m_15, dst_6, off_9, (&(*(*X60Qx_218)).d_00.v_0), fsz_0);}
        inc_1_I6wjjge_aow2h993l1((&i_15));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Ijysww_arecyyj7v(fos_0);
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(box_1);}
void* materializeRef_1_arecyyj7v(ArenaMat_0_arecyyj7v* m_16, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_1){
  void* result_16;
  NU32 key_5 = cellKey_0_arecyyj7v(cell_1);
  NU32 hit_3 = seenGet_0_arecyyj7v((&(*m_16)), key_5);
  if ((!(hit_3 == 0u))){
    return ((void*)hit_3);}
  Value_0_valzr1t4f payloadV_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cell_1).d_00.v_0));
  NI32 paySize_0 = 0;
  NB8 X60Qx_219;
  if (payloadV_0.kind_0 == 11){
    X60Qx_219 = NIM_TRUE;}
  else {
    X60Qx_219 = (payloadV_0.kind_0 == 10);}
  if (X60Qx_219){
    if ((!(payloadV_0.obj_0 == NIM_NIL))){
      NI32 s_16 = sizeOfSym_0_fiepkwzpc((*payloadV_0.obj_0).d_00.typeSym_0);
      if (0 < s_16){
        paySize_0 = s_16;}}}
  else {
    X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_16 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
      .a = {
        190u, 0u, 0u}}
    ;
    NU64 X60Qdesugar_17 = ((NU)payloadV_0.kind_0);
    if (((NU8)(X60Qdesugar_16.a[((NU)(X60Qdesugar_17 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_17 & 7u)))))) != 0u){
      NI32 X60Qx_220 = scalarSize_0_arecyyj7v((&payloadV_0));
      paySize_0 = X60Qx_220;}}
  X60Qt_0_IAtupleApointerZAR6_arecyyj7v X60Qtmptup_0 = refBox_0_arecyyj7v(m_16, paySize_0);
  void* box_2 = X60Qtmptup_0.fld_0;
  void* payload_1 = X60Qtmptup_0.fld_1;
  add_0_Iaos70d1_arecyyj7v((&(*m_16).seen_0), (MatEntry_0_arecyyj7v){
    .key_0 = key_5, .box_0 = ((NU32)box_2)}
  );
  NB8 X60Qx_221;
  if (payloadV_0.kind_0 == 11){
    X60Qx_221 = NIM_TRUE;}
  else {
    X60Qx_221 = (payloadV_0.kind_0 == 10);}
  if (X60Qx_221){
    placeObject_1_arecyyj7v(m_16, payload_1, (&payloadV_0));}
  else {
    X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_18 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
      .a = {
        190u, 0u, 0u}}
    ;
    NU64 X60Qdesugar_19 = ((NU)payloadV_0.kind_0);
    if (((NU8)(X60Qdesugar_18.a[((NU)(X60Qdesugar_19 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_19 & 7u)))))) != 0u){
      writeScalar_0_arecyyj7v(payload_1, 0, (&payloadV_0));}}
  result_16 = box_2;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&payloadV_0));
  return result_16;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&payloadV_0));
  return result_16;}
NU64 peekN_0_arecyyj7v(void* src_0, NI32 off_5, NI32 n_0){
  NU64 result_17;
  NU64 u_2 = ((NU64)0u);
  NI32 i_18 = 0;
  {
    while (i_18 < n_0){
      NU8 X60Qx_222 = peekByte_0_arewp645e1(src_0, ((NI32)(off_5 + i_18)));
      u_2 = ((NU64)(u_2 | ((NU64)(((NU64)X60Qx_222) << ((NU32)(((NU32)i_18) * 8u))))));
      inc_1_I6wjjge_aow2h993l1((&i_18));}}
  whileStmtLabel_0: ;
  result_17 = u_2;
  return result_17;}
Value_0_valzr1t4f readScalarBack_0_arecyyj7v(void* src_1, NI32 off_6, Value_0_valzr1t4f* old_1, NI32 fsize_3){
  Value_0_valzr1t4f result_18;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
  NI32 vn_0 = scalarSize_0_arecyyj7v((&(*old_1)));
  NI32 n_5 = vn_0;
  NB8 X60Qx_223;
  if (0 < fsize_3){
    X60Qx_223 = (!(fsize_3 == vn_0));}
  else {
    X60Qx_223 = NIM_FALSE;}
  if (X60Qx_223){
    NB8 X60Qx_224;
    NB8 X60Qx_225;
    NB8 X60Qx_226;
    if ((*old_1).kind_0 == 1){
      X60Qx_226 = NIM_TRUE;}
    else {
      X60Qx_226 = ((*old_1).kind_0 == 2);}
    if (X60Qx_226){
      X60Qx_225 = NIM_TRUE;}
    else {
      X60Qx_225 = ((*old_1).kind_0 == 4);}
    if (X60Qx_225){
      X60Qx_224 = NIM_TRUE;}
    else {
      X60Qx_224 = ((*old_1).kind_0 == 5);}
    if (X60Qx_224){
      n_5 = fsize_3;}
    else {
      Value_0_valzr1t4f X60Qx_227 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*old_1)));
      return X60Qx_227;}}
  NU64 u_3 = peekN_0_arecyyj7v(src_1, off_6, n_5);
  switch ((*old_1).kind_0){
    case 1:
    {
      NI64 s_18 = ((NI64)u_3);
      NB8 X60Qx_228;
      if (n_5 < 8){
        X60Qx_228 = (0 < n_5);}
      else {
        X60Qx_228 = NIM_FALSE;}
      if (X60Qx_228){
        NU32 shift_0 = ((NU32)((NI32)(64 - ((NI32)(n_5 * 8)))));
        s_18 = ((NI64)(((NI64)((NI64)((NU64)(u_3 << shift_0)))) >> ((NU64)shift_0)));}
      NI64 X60Qx_13;
      if ((*old_1).bits_0 <= 0){
        X60Qx_13 = 64;}
      else {
        X60Qx_13 = (*old_1).bits_0;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
      Value_0_valzr1t4f X60Qx_229 = vInt_0_valzr1t4f(s_18, X60Qx_13);
      result_18 = X60Qx_229;}
    break;
    case 2:
    {
      NI64 X60Qx_14;
      if ((*old_1).bits_0 <= 0){
        X60Qx_14 = 64;}
      else {
        X60Qx_14 = (*old_1).bits_0;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
      Value_0_valzr1t4f X60Qx_230 = vUInt_0_valzr1t4f(u_3, X60Qx_14);
      result_18 = X60Qx_230;}
    break;
    case 4:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
      Value_0_valzr1t4f X60Qx_231 = vBool_0_valzr1t4f((!(u_3 == ((NU64)0u))));
      result_18 = X60Qx_231;}
    break;
    case 5:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
      result_18 = (Value_0_valzr1t4f){
        .kind_0 = 5, .cval_0 = ((NC8)((NU8)((NU64)(u_3 & ((NU64)255u)))))}
      ;}
    break;
    case 7:
    {
      NI32 ord_0 = ((NI32)((NI32)((NU32)((NU64)(u_3 & ((NU64)4294967295u))))));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
      result_18 = (Value_0_valzr1t4f){
        .kind_0 = 7, .eord_0 = ord_0, .ekind_0 = (*old_1).ekind_0}
      ;}
    break;
    case 3:
    {
      if ((*old_1).fbits_0 == 32){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
        NU32 X60Qx_232 = ((NU32)((NU64)(u_3 & ((NU64)4294967295u))));
        NF32 X60Qx_233;
        copyMem_0_sysvq0asl((&X60Qx_233), (&X60Qx_232), sizeof(NF32));
        result_18 = (Value_0_valzr1t4f){
          .kind_0 = 3, .fval_0 = ((NF64)X60Qx_233), .fbits_0 = 32}
        ;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
        NF64 X60Qx_234;
        copyMem_0_sysvq0asl((&X60Qx_234), (&u_3), sizeof(NF64));
        result_18 = (Value_0_valzr1t4f){
          .kind_0 = 3, .fval_0 = X60Qx_234, .fbits_0 = 64}
        ;}}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
      Value_0_valzr1t4f X60Qx_235 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*old_1)));
      result_18 = X60Qx_235;}
    break;}
  return result_18;}
NB8 seen2_0_arecyyj7v(seq_0_Igsxz3n_arecyyj7v visited_0, NU32 a_2){
  NB8 result_19;
  NI32 i_19 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_236 = len_3_I3cga53_arecyyj7v(visited_0);
      if (i_19 < X60Qx_236){
        NU32* X60Qx_237 = getQ_7_Ib5f77c1_arecyyj7v(visited_0, i_19);
        if ((*X60Qx_237) == a_2){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_19));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_19 = NIM_FALSE;
  return result_19;}
void syncField_0_arecyyj7v(void* src_3, NI32 off_7, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_2, seq_0_Igsxz3n_arecyyj7v* visited_2, NI32 fsize_4){
  if (cell_2 == NIM_NIL){
    return;}
  Value_0_valzr1t4f fv_2 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*cell_2).d_00.v_0));
  switch (fv_2.kind_0){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    {
      Value_0_valzr1t4f* X60Qlhs_18 = (&(*cell_2).d_00.v_0);
      Value_0_valzr1t4f X60Qlhs_19 = readScalarBack_0_arecyyj7v(src_3, off_7, (&fv_2), fsize_4);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_18)));
      (*X60Qlhs_18) = X60Qlhs_19;}
    break;
    case 11:
    case 10:
    {
      void* sub_1 = ((void*)((NU32)(((NU32)src_3) + ((NU32)off_7))));
      syncObject_1_arecyyj7v(sub_1, (&fv_2), visited_2);}
    break;
    case 12:
    {
      if ((!(fv_2.rf_0 == NIM_NIL))){
        NU64 X60Qx_238 = peekN_0_arecyyj7v(src_3, off_7, ((NI32)8));
        NU32 box_3 = ((NU32)X60Qx_238);
        NB8 X60Qx_239;
        if ((!(box_3 == 0u))){
          NB8 X60Qx_240 = seen2_0_arecyyj7v((*visited_2), box_3);
          X60Qx_239 = (!X60Qx_240);}
        else {
          X60Qx_239 = NIM_FALSE;}
        if (X60Qx_239){
          add_0_Iwsr3ai_arecyyj7v(visited_2, box_3);
          void* payload_2 = ((void*)((NU32)(box_3 + ((NU32)((NI32)8)))));
          Value_0_valzr1t4f pv_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*fv_2.rf_0).d_00.v_0));
          X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_20 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
            .a = {
              0u, 12u, 0u}}
          ;
          NU64 X60Qdesugar_21 = ((NU)pv_0.kind_0);
          if (((NU8)(X60Qdesugar_20.a[((NU)(X60Qdesugar_21 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_21 & 7u)))))) != 0u){
            syncObject_1_arecyyj7v(payload_2, (&pv_0), visited_2);}
          else {
            X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_22 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
              .a = {
                190u, 0u, 0u}}
            ;
            NU64 X60Qdesugar_23 = ((NU)pv_0.kind_0);
            if (((NU8)(X60Qdesugar_22.a[((NU)(X60Qdesugar_23 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_23 & 7u)))))) != 0u){
              Value_0_valzr1t4f* X60Qlhs_20 = (&(*fv_2.rf_0).d_00.v_0);
              Value_0_valzr1t4f X60Qlhs_21 = readScalarBack_0_arecyyj7v(payload_2, 0, (&pv_0), 0);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_20)));
              (*X60Qlhs_20) = X60Qlhs_21;}}
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&pv_0));}}}
    break;
    case 8:
    {
      NB8 X60Qx_241;
      NB8 X60Qx_242;
      if ((!(fv_2.sq_0 == NIM_NIL))){
        X60Qx_242 = (0 < (*fv_2.sq_0).d_00.elems_0.len_0);}
      else {
        X60Qx_242 = NIM_FALSE;}
      if (X60Qx_242){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_243 = getQ_7_Ii14ync1_arecyyj7v((*fv_2.sq_0).d_00.elems_0, 0);
        X60Qx_241 = (!((*X60Qx_243) == NIM_NIL));}
      else {
        X60Qx_241 = NIM_FALSE;}
      if (X60Qx_241){
        NU64 X60Qx_244 = peekN_0_arecyyj7v(src_3, ((NI32)(off_7 + ((NI32)0))), ((NI32)8));
        NI32 n_6 = ((NI32)X60Qx_244);
        NU64 X60Qx_245 = peekN_0_arecyyj7v(src_3, ((NI32)(off_7 + ((NI32)8))), ((NI32)8));
        void* data_4 = ((void*)X60Qx_245);
        if ((!(data_4 == NIM_NIL))){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_246 = getQ_7_Ii14ync1_arecyyj7v((*fv_2.sq_0).d_00.elems_0, 0);
          NI32 stride_3 = elemStride_0_arecyyj7v((&(*(*X60Qx_246)).d_00.v_0));
          NI32 i_21 = 0;
          {
            while (NIM_TRUE){
              NB8 X60Qx_247;
              if (i_21 < n_6){
                NI32 X60Qx_248 = len_3_I83dzei_arecyyj7v((*fv_2.sq_0).d_00.elems_0);
                X60Qx_247 = (i_21 < X60Qx_248);}
              else {
                X60Qx_247 = NIM_FALSE;}
              if (X60Qx_247){
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_249 = getQ_7_Ii14ync1_arecyyj7v((*fv_2.sq_0).d_00.elems_0, i_21);
                if ((!((*X60Qx_249) == NIM_NIL))){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_250 = getQ_7_Ii14ync1_arecyyj7v((*fv_2.sq_0).d_00.elems_0, i_21);
                  syncField_0_arecyyj7v(data_4, ((NI32)(i_21 * stride_3)), (*X60Qx_250), visited_2, 0);}
                inc_1_I6wjjge_aow2h993l1((&i_21));}
              else {
                break;}}}
          whileStmtLabel_0: ;}}}
    break;
    case 9:
    {
      NB8 X60Qx_251;
      NB8 X60Qx_252;
      if ((!(fv_2.arr_0 == NIM_NIL))){
        X60Qx_252 = (0 < (*fv_2.arr_0).d_00.elems_0.len_0);}
      else {
        X60Qx_252 = NIM_FALSE;}
      if (X60Qx_252){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_253 = getQ_7_Ii14ync1_arecyyj7v((*fv_2.arr_0).d_00.elems_0, 0);
        X60Qx_251 = (!((*X60Qx_253) == NIM_NIL));}
      else {
        X60Qx_251 = NIM_FALSE;}
      if (X60Qx_251){
        NI32 st_1 = 0;
        NB8 X60Qx_254;
        if (0 < fsize_4){
          NI32 X60Qx_255 = len_3_I83dzei_arecyyj7v((*fv_2.arr_0).d_00.elems_0);
          X60Qx_254 = (((NI32)(fsize_4 % X60Qx_255)) == 0);}
        else {
          X60Qx_254 = NIM_FALSE;}
        if (X60Qx_254){
          NI32 X60Qx_256 = len_3_I83dzei_arecyyj7v((*fv_2.arr_0).d_00.elems_0);
          st_1 = ((NI32)(fsize_4 / X60Qx_256));}
        else {
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_257 = getQ_7_Ii14ync1_arecyyj7v((*fv_2.arr_0).d_00.elems_0, 0);
          NI32 X60Qx_258 = elemStride_0_arecyyj7v((&(*(*X60Qx_257)).d_00.v_0));
          st_1 = X60Qx_258;}
        if (0 < st_1){
          NI32 i_22 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_259 = len_3_I83dzei_arecyyj7v((*fv_2.arr_0).d_00.elems_0);
              if (i_22 < X60Qx_259){
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_260 = getQ_7_Ii14ync1_arecyyj7v((*fv_2.arr_0).d_00.elems_0, i_22);
                if ((!((*X60Qx_260) == NIM_NIL))){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_261 = getQ_7_Ii14ync1_arecyyj7v((*fv_2.arr_0).d_00.elems_0, i_22);
                  syncField_0_arecyyj7v(src_3, ((NI32)(off_7 + ((NI32)(i_22 * st_1)))), (*X60Qx_261), visited_2, st_1);}
                inc_1_I6wjjge_aow2h993l1((&i_22));}
              else {
                break;}}}
          whileStmtLabel_1: ;}}}
    break;
    default:
    {
      }
    break;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fv_2));}
void syncObject_1_arecyyj7v(void* src_4, Value_0_valzr1t4f* v_9, seq_0_Igsxz3n_arecyyj7v* visited_3){
  if ((*v_9).obj_0 == NIM_NIL){
    return;}
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_4 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v((*v_9).obj_0);
  seq_0_Id0odh1_arecyyj7v fos_1 = fieldOffsetsOfType_0_fiepkwzpc((*box_4).d_00.typeSym_0);
  NI32 i_23 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_262;
      NI32 X60Qx_263 = len_3_I6y2imo_arecyyj7v((*box_4).d_00.names_0);
      if (i_23 < X60Qx_263){
        NI32 X60Qx_264 = len_3_I83dzei_arecyyj7v((*box_4).d_00.cells_0);
        X60Qx_262 = (i_23 < X60Qx_264);}
      else {
        X60Qx_262 = NIM_FALSE;}
      if (X60Qx_262){
        NI32 off_10 = -1;
        NI32 fsz_1 = 0;
        NI32 k_2 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_265 = len_3_If78p9o_arecyyj7v(fos_1);
            if (k_2 < X60Qx_265){
              FieldOff_0_fiepkwzpc* X60Qx_266 = getQ_7_Ivg8m7s_arecyyj7v(fos_1, k_2);
              NU32* X60Qx_267 = getQ_7_I2v00yv1_arecyyj7v((*box_4).d_00.names_0, i_23);
              NB8 X60Qx_268 = eqQ_0_nifh7u8pu1((*X60Qx_266).sym_0, (*X60Qx_267));
              if (X60Qx_268){
                FieldOff_0_fiepkwzpc* X60Qx_269 = getQ_7_Ivg8m7s_arecyyj7v(fos_1, k_2);
                off_10 = (*X60Qx_269).off_0;
                FieldOff_0_fiepkwzpc* X60Qx_270 = getQ_7_Ivg8m7s_arecyyj7v(fos_1, k_2);
                fsz_1 = (*X60Qx_270).size_0;
                goto whileStmtLabel_1;}
              inc_1_I6wjjge_aow2h993l1((&k_2));}
            else {
              break;}}}
        whileStmtLabel_1: ;
        if (0 <= off_10){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_271 = getQ_7_Ii14ync1_arecyyj7v((*box_4).d_00.cells_0, i_23);
          syncField_0_arecyyj7v(src_4, off_10, (*X60Qx_271), visited_3, fsz_1);}
        inc_1_I6wjjge_aow2h993l1((&i_23));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Ijysww_arecyyj7v(fos_1);
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(box_4);}
void syncBack_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_17, Value_0_valzr1t4f* v_10, void* root_0){
  seq_0_Igsxz3n_arecyyj7v visited_4 = newSeqUninit_0_I1kz5fl_arecyyj7v(0);
  switch ((*v_10).kind_0){
    case 12:
    {
      NB8 X60Qx_272;
      if ((!((*v_10).rf_0 == NIM_NIL))){
        X60Qx_272 = (!(root_0 == NIM_NIL));}
      else {
        X60Qx_272 = NIM_FALSE;}
      if (X60Qx_272){
        NU32 box_5 = ((NU32)root_0);
        add_0_Iwsr3ai_arecyyj7v((&visited_4), box_5);
        void* payload_3 = ((void*)((NU32)(box_5 + ((NU32)((NI32)8)))));
        Value_0_valzr1t4f pv_1 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*v_10).rf_0).d_00.v_0));
        X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_24 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
          .a = {
            0u, 12u, 0u}}
        ;
        NU64 X60Qdesugar_25 = ((NU)pv_1.kind_0);
        if (((NU8)(X60Qdesugar_24.a[((NU)(X60Qdesugar_25 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_25 & 7u)))))) != 0u){
          syncObject_1_arecyyj7v(payload_3, (&pv_1), (&visited_4));}
        else {
          X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_26 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
            .a = {
              190u, 0u, 0u}}
          ;
          NU64 X60Qdesugar_27 = ((NU)pv_1.kind_0);
          if (((NU8)(X60Qdesugar_26.a[((NU)(X60Qdesugar_27 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_27 & 7u)))))) != 0u){
            Value_0_valzr1t4f* X60Qlhs_22 = (&(*(*v_10).rf_0).d_00.v_0);
            Value_0_valzr1t4f X60Qlhs_23 = readScalarBack_0_arecyyj7v(payload_3, 0, (&pv_1), 0);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_22)));
            (*X60Qlhs_22) = X60Qlhs_23;}}
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&pv_1));}}
    break;
    case 11:
    case 10:
    {
      syncObject_1_arecyyj7v(root_0, (&(*v_10)), (&visited_4));}
    break;
    case 8:
    {
      NB8 X60Qx_273;
      NB8 X60Qx_274;
      if ((!((*v_10).sq_0 == NIM_NIL))){
        X60Qx_274 = (0 < (*(*v_10).sq_0).d_00.elems_0.len_0);}
      else {
        X60Qx_274 = NIM_FALSE;}
      if (X60Qx_274){
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_275 = getQ_7_Ii14ync1_arecyyj7v((*(*v_10).sq_0).d_00.elems_0, 0);
        X60Qx_273 = (!((*X60Qx_275) == NIM_NIL));}
      else {
        X60Qx_273 = NIM_FALSE;}
      if (X60Qx_273){
        NU64 X60Qx_276 = peekN_0_arecyyj7v(root_0, ((NI32)0), ((NI32)8));
        NI32 n_7 = ((NI32)X60Qx_276);
        NU64 X60Qx_277 = peekN_0_arecyyj7v(root_0, ((NI32)8), ((NI32)8));
        void* data_5 = ((void*)X60Qx_277);
        if ((!(data_5 == NIM_NIL))){
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_278 = getQ_7_Ii14ync1_arecyyj7v((*(*v_10).sq_0).d_00.elems_0, 0);
          NI32 stride_4 = elemStride_0_arecyyj7v((&(*(*X60Qx_278)).d_00.v_0));
          NI32 i_24 = 0;
          {
            while (NIM_TRUE){
              NB8 X60Qx_279;
              if (i_24 < n_7){
                NI32 X60Qx_280 = len_3_I83dzei_arecyyj7v((*(*v_10).sq_0).d_00.elems_0);
                X60Qx_279 = (i_24 < X60Qx_280);}
              else {
                X60Qx_279 = NIM_FALSE;}
              if (X60Qx_279){
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_281 = getQ_7_Ii14ync1_arecyyj7v((*(*v_10).sq_0).d_00.elems_0, i_24);
                if ((!((*X60Qx_281) == NIM_NIL))){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_282 = getQ_7_Ii14ync1_arecyyj7v((*(*v_10).sq_0).d_00.elems_0, i_24);
                  syncField_0_arecyyj7v(data_5, ((NI32)(i_24 * stride_4)), (*X60Qx_282), (&visited_4), 0);}
                inc_1_I6wjjge_aow2h993l1((&i_24));}
              else {
                break;}}}
          whileStmtLabel_0: ;}}}
    break;
    default:
    {
      }
    break;}
  eQdestroy_1_Ib6pp1_arecyyj7v(visited_4);}
void syncBlocks_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_18){
  seq_0_Igsxz3n_arecyyj7v visited_5 = newSeqUninit_0_I1kz5fl_arecyyj7v(0);
  NI32 bi_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_283 = len_3_I80y55d1_arecyyj7v((*m_18).blocks_0);
      if (bi_0 < X60Qx_283){
        BlockEntry_0_arecyyj7v* X60Qx_284 = getQ_7_Iyxduse_arecyyj7v((*m_18).blocks_0, bi_0);
        BlockEntry_0_arecyyj7v X60QconstRefTemp_0 = (*X60Qx_284);
        BlockEntry_0_arecyyj7v b_4 = eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&X60QconstRefTemp_0));
        NB8 X60Qx_285;
        if ((!(b_4.data_0 == 0u))){
          X60Qx_285 = (0 < b_4.stride_0);}
        else {
          X60Qx_285 = NIM_FALSE;}
        if (X60Qx_285){
          void* data_6 = ((void*)b_4.data_0);
          if ((!(b_4.sq_0 == NIM_NIL))){
            NI32 i_25 = 0;
            {
              while (NIM_TRUE){
                NB8 X60Qx_286;
                if (i_25 < b_4.count_0){
                  NI32 X60Qx_287 = len_3_I83dzei_arecyyj7v((*b_4.sq_0).d_00.elems_0);
                  X60Qx_286 = (i_25 < X60Qx_287);}
                else {
                  X60Qx_286 = NIM_FALSE;}
                if (X60Qx_286){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_288 = getQ_7_Ii14ync1_arecyyj7v((*b_4.sq_0).d_00.elems_0, i_25);
                  if ((!((*X60Qx_288) == NIM_NIL))){
                    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_289 = getQ_7_Ii14ync1_arecyyj7v((*b_4.sq_0).d_00.elems_0, i_25);
                    syncField_0_arecyyj7v(data_6, ((NI32)(i_25 * b_4.stride_0)), (*X60Qx_289), (&visited_5), 0);}
                  inc_1_I6wjjge_aow2h993l1((&i_25));}
                else {
                  break;}}}
            whileStmtLabel_1: ;}
          else {
            if ((!(b_4.arr_0 == NIM_NIL))){
              NI32 i_26 = 0;
              {
                while (NIM_TRUE){
                  NB8 X60Qx_290;
                  if (i_26 < b_4.count_0){
                    NI32 X60Qx_291 = len_3_I83dzei_arecyyj7v((*b_4.arr_0).d_00.elems_0);
                    X60Qx_290 = (i_26 < X60Qx_291);}
                  else {
                    X60Qx_290 = NIM_FALSE;}
                  if (X60Qx_290){
                    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_292 = getQ_7_Ii14ync1_arecyyj7v((*b_4.arr_0).d_00.elems_0, i_26);
                    if ((!((*X60Qx_292) == NIM_NIL))){
                      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_293 = getQ_7_Ii14ync1_arecyyj7v((*b_4.arr_0).d_00.elems_0, i_26);
                      syncField_0_arecyyj7v(data_6, ((NI32)(i_26 * b_4.stride_0)), (*X60Qx_293), (&visited_5), 0);}
                    inc_1_I6wjjge_aow2h993l1((&i_26));}
                  else {
                    break;}}}
              whileStmtLabel_2: ;}
            else {
              if ((!(b_4.cell_0 == NIM_NIL))){
                syncField_0_arecyyj7v(data_6, 0, b_4.cell_0, (&visited_5), b_4.stride_0);}}}}
        inc_1_I6wjjge_aow2h993l1((&bi_0));
        eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_4));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Ib6pp1_arecyyj7v(visited_5);}
void* materialize_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_19, Value_0_valzr1t4f* v_11){
  void* result_20;
  switch ((*v_11).kind_0){
    case 12:
    {
      result_20 = NIM_NIL;
      if ((!((*v_11).rf_0 == NIM_NIL))){
        void* X60Qx_294 = materializeRef_1_arecyyj7v(m_19, (*v_11).rf_0);
        result_20 = X60Qx_294;}}
    break;
    case 11:
    case 10:
    {
      NI32 sz_0 = 0;
      if ((!((*v_11).obj_0 == NIM_NIL))){
        NI32 s_22 = sizeOfSym_0_fiepkwzpc((*(*v_11).obj_0).d_00.typeSym_0);
        if (0 < s_22){
          sz_0 = s_22;}}
      NI32 X60Qx_295 = max_2_sysvq0asl(sz_0, 1);
      void* dst_7 = arenaAlloc_0_arewp645e1((*m_19).a_0, X60Qx_295, ((NI32)8));
      placeObject_1_arecyyj7v(m_19, dst_7, (&(*v_11)));
      result_20 = dst_7;}
    break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    {
      NI32 X60Qx_296 = scalarSize_0_arecyyj7v((&(*v_11)));
      NI32 X60Qx_297 = max_2_sysvq0asl(X60Qx_296, 1);
      void* dst_8 = arenaAlloc_0_arewp645e1((*m_19).a_0, X60Qx_297, ((NI32)8));
      writeScalar_0_arecyyj7v(dst_8, 0, (&(*v_11)));
      result_20 = dst_8;}
    break;
    case 8:
    {
      void* dst_9 = arenaAlloc_0_arewp645e1((*m_19).a_0, ((NI32)16), ((NI32)8));
      placeSeqInline_0_arecyyj7v(m_19, dst_9, 0, (*v_11).sq_0);
      result_20 = dst_9;}
    break;
    default:
    {
      result_20 = NIM_NIL;}
    break;}
  return result_20;}
static inline seq_0_Isge9lx_arecyyj7v newSeqUninit_0_Iglb3hm1_arecyyj7v(NI32 size_4){
  seq_0_Isge9lx_arecyyj7v result_21;
  if (size_4 == 0){
    result_21 = (seq_0_Isge9lx_arecyyj7v){
      .len_0 = size_4, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_Isdq9ys1_arecyyj7v(size_4);
    void* X60Qx_298 = alloc_1_sysvq0asl(memSize_0);
    result_21 = (seq_0_Isge9lx_arecyyj7v){
      .len_0 = size_4, .data_0 = ((MatEntry_0_arecyyj7v*)X60Qx_298)}
    ;
    if ((!(result_21.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_299 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_21.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_21;}
static inline seq_0_Idhq52f_arecyyj7v newSeqUninit_0_I7mggr11_arecyyj7v(NI32 size_6){
  seq_0_Idhq52f_arecyyj7v result_22;
  if (size_6 == 0){
    result_22 = (seq_0_Idhq52f_arecyyj7v){
      .len_0 = size_6, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Iovtwg11_arecyyj7v(size_6);
    void* X60Qx_300 = alloc_1_sysvq0asl(memSize_1);
    result_22 = (seq_0_Idhq52f_arecyyj7v){
      .len_0 = size_6, .data_0 = ((BlockEntry_0_arecyyj7v*)X60Qx_300)}
    ;
    if ((!(result_22.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_301 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_22.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_22;}
static inline seq_0_Ijes23h1_arecyyj7v newSeqUninit_0_I1oegnq1_arecyyj7v(NI32 size_8){
  seq_0_Ijes23h1_arecyyj7v result_23;
  if (size_8 == 0){
    result_23 = (seq_0_Ijes23h1_arecyyj7v){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_If6e4np_arecyyj7v(size_8);
    void* X60Qx_302 = alloc_1_sysvq0asl(memSize_2);
    result_23 = (seq_0_Ijes23h1_arecyyj7v){
      .len_0 = size_8, .data_0 = ((RegionHandout_0_arecyyj7v*)X60Qx_302)}
    ;
    if ((!(result_23.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_303 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_23.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_23;}
static inline NI32 len_3_Ifjbd231_arecyyj7v(seq_0_Isge9lx_arecyyj7v s_23){
  NI32 result_24;
  result_24 = s_23.len_0;
  return result_24;}
static inline MatEntry_0_arecyyj7v* getQ_7_Ielxh6u1_arecyyj7v(seq_0_Isge9lx_arecyyj7v s_24, NI32 i_27){
  NB8 X60Qx_304;
  if (i_27 < s_24.len_0){
    X60Qx_304 = (0 <= i_27);}
  else {
    X60Qx_304 = NIM_FALSE;}
  if ((!X60Qx_304)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  MatEntry_0_arecyyj7v* result_25;
  result_25 = (&s_24.data_0[i_27]);
  return result_25;}
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
static inline NI32 len_3_I80y55d1_arecyyj7v(seq_0_Idhq52f_arecyyj7v s_27){
  NI32 result_28;
  result_28 = s_27.len_0;
  return result_28;}
static inline BlockEntry_0_arecyyj7v* getQ_7_Iyxduse_arecyyj7v(seq_0_Idhq52f_arecyyj7v s_28, NI32 i_29){
  NB8 X60Qx_306;
  if (i_29 < s_28.len_0){
    X60Qx_306 = (0 <= i_29);}
  else {
    X60Qx_306 = NIM_FALSE;}
  if ((!X60Qx_306)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  BlockEntry_0_arecyyj7v* result_29;
  result_29 = (&s_28.data_0[i_29]);
  return result_29;}
static inline void add_0_I52sfn71_arecyyj7v(seq_0_Idhq52f_arecyyj7v* s_29, BlockEntry_0_arecyyj7v elem_4){
  NI32 L_0 = (*s_29).len_0;
  NI32 X60Qx_307 = capInBytes_0_I3r76wn_arecyyj7v((*s_29));
  if (X60Qx_307 < ((NI32)(((NI32)(L_0 * sizeof(BlockEntry_0_arecyyj7v))) + sizeof(BlockEntry_0_arecyyj7v)))){
    NB8 X60Qx_308 = resize_0_Ii6jopd_arecyyj7v(s_29, 1);
    if ((!X60Qx_308)){
      eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&elem_4));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_29).len_0));
  (*s_29).data_0[L_0] = elem_4;}
static inline NI32 len_3_Izoe8zv_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_31){
  NI32 result_30;
  result_30 = s_31.len_0;
  return result_30;}
static inline NU8* getQ_7_Ig0r1051_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_32, NI32 i_30){
  NB8 X60Qx_309;
  if (i_30 < s_32.len_0){
    X60Qx_309 = (0 <= i_30);}
  else {
    X60Qx_309 = NIM_FALSE;}
  if ((!X60Qx_309)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU8* result_31;
  result_31 = (&s_32.data_0[i_30]);
  return result_31;}
static inline NI32 len_3_Io8yozm_arecyyj7v(seq_0_Ijes23h1_arecyyj7v s_33){
  NI32 result_32;
  result_32 = s_33.len_0;
  return result_32;}
static inline RegionHandout_0_arecyyj7v* getQ_7_Irzlyr2_arecyyj7v(seq_0_Ijes23h1_arecyyj7v s_34, NI32 i_31){
  NB8 X60Qx_310;
  if (i_31 < s_34.len_0){
    X60Qx_310 = (0 <= i_31);}
  else {
    X60Qx_310 = NIM_FALSE;}
  if ((!X60Qx_310)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  RegionHandout_0_arecyyj7v* result_33;
  result_33 = (&s_34.data_0[i_31]);
  return result_33;}
static inline void add_0_Ilvs1p91_arecyyj7v(seq_0_Ijes23h1_arecyyj7v* s_35, RegionHandout_0_arecyyj7v elem_5){
  NI32 L_1 = (*s_35).len_0;
  NI32 X60Qx_311 = capInBytes_0_In2lvry_arecyyj7v((*s_35));
  if (X60Qx_311 < ((NI32)(((NI32)(L_1 * sizeof(RegionHandout_0_arecyyj7v))) + sizeof(RegionHandout_0_arecyyj7v)))){
    NB8 X60Qx_312 = resize_0_Iwzs34z_arecyyj7v(s_35, 1);
    if ((!X60Qx_312)){
      eQdestroyQ_SX52egionX48andout0arecyyj7v_0_arecyyj7v(elem_5);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_35).len_0));
  (*s_35).data_0[L_1] = elem_5;}
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37){
  NI32 result_34;
  result_34 = s_37.len_0;
  return result_34;}
static inline NI32 len_3_If78p9o_arecyyj7v(seq_0_Id0odh1_arecyyj7v s_38){
  NI32 result_35;
  result_35 = s_38.len_0;
  return result_35;}
static inline FieldOff_0_fiepkwzpc* getQ_7_Ivg8m7s_arecyyj7v(seq_0_Id0odh1_arecyyj7v s_39, NI32 i_32){
  NB8 X60Qx_313;
  if (i_32 < s_39.len_0){
    X60Qx_313 = (0 <= i_32);}
  else {
    X60Qx_313 = NIM_FALSE;}
  if ((!X60Qx_313)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  FieldOff_0_fiepkwzpc* result_36;
  result_36 = (&s_39.data_0[i_32]);
  return result_36;}
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
static inline void add_0_Iaos70d1_arecyyj7v(seq_0_Isge9lx_arecyyj7v* s_41, MatEntry_0_arecyyj7v elem_6){
  NI32 L_2 = (*s_41).len_0;
  NI32 X60Qx_315 = capInBytes_0_Iswy84i_arecyyj7v((*s_41));
  if (X60Qx_315 < ((NI32)(((NI32)(L_2 * sizeof(MatEntry_0_arecyyj7v))) + sizeof(MatEntry_0_arecyyj7v)))){
    NB8 X60Qx_316 = resize_0_Ipftt5t1_arecyyj7v(s_41, 1);
    if ((!X60Qx_316)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_41).len_0));
  (*s_41).data_0[L_2] = elem_6;}
static inline NI32 len_3_I3cga53_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_43){
  NI32 result_38;
  result_38 = s_43.len_0;
  return result_38;}
static inline NU32* getQ_7_Ib5f77c1_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_44, NI32 i_34){
  NB8 X60Qx_317;
  if (i_34 < s_44.len_0){
    X60Qx_317 = (0 <= i_34);}
  else {
    X60Qx_317 = NIM_FALSE;}
  if ((!X60Qx_317)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_39;
  result_39 = (&s_44.data_0[i_34]);
  return result_39;}
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
static inline NI32 memSizeInBytes_0_Isdq9ys1_arecyyj7v(NI32 size_12){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_41;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_12, sizeof(MatEntry_0_arecyyj7v), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_41 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_41 = ((NI32)2147483647);}
  return result_41;}
static inline NI32 memSizeInBytes_0_Iovtwg11_arecyyj7v(NI32 size_13){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_42;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_13, sizeof(BlockEntry_0_arecyyj7v), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_42 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_42 = ((NI32)2147483647);}
  return result_42;}
static inline NI32 memSizeInBytes_0_If6e4np_arecyyj7v(NI32 size_14){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_43;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_14, sizeof(RegionHandout_0_arecyyj7v), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_43 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_43 = ((NI32)2147483647);}
  return result_43;}
static inline NI32 capInBytes_0_I3r76wn_arecyyj7v(seq_0_Idhq52f_arecyyj7v s_47){
  NI32 result_44;
  NI32 X60Qx_15;
  if ((!(s_47.data_0 == NIM_NIL))){
    NI32 X60Qx_322 = allocatedSize_0_sysvq0asl(((void*)((void*)s_47.data_0)));
    X60Qx_15 = X60Qx_322;}
  else {
    X60Qx_15 = 0;}
  result_44 = X60Qx_15;
  return result_44;}
NB8 resize_0_Ii6jopd_arecyyj7v(seq_0_Idhq52f_arecyyj7v* dest_4, NI32 addedElements_4){
  NB8 result_45;
  NI32 X60Qx_323 = capInBytes_0_I3r76wn_arecyyj7v((*dest_4));
  NI32 oldCap_0 = ((NI32)(X60Qx_323 / sizeof(BlockEntry_0_arecyyj7v)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_4);
  NI32 memSize_4 = memSizeInBytes_0_Iovtwg11_arecyyj7v(newCap_0);
  void* X60Qx_324 = realloc_1_sysvq0asl(((void*)((void*)(*dest_4).data_0)), memSize_4);
  (*dest_4).data_0 = ((BlockEntry_0_arecyyj7v*)X60Qx_324);
  if ((*dest_4).data_0 == NIM_NIL){
    (*dest_4).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_4);
    result_45 = NIM_FALSE;}
  else {
    result_45 = NIM_TRUE;}
  return result_45;}
static inline NI32 capInBytes_0_In2lvry_arecyyj7v(seq_0_Ijes23h1_arecyyj7v s_48){
  NI32 result_46;
  NI32 X60Qx_16;
  if ((!(s_48.data_0 == NIM_NIL))){
    NI32 X60Qx_325 = allocatedSize_0_sysvq0asl(((void*)((void*)s_48.data_0)));
    X60Qx_16 = X60Qx_325;}
  else {
    X60Qx_16 = 0;}
  result_46 = X60Qx_16;
  return result_46;}
NB8 resize_0_Iwzs34z_arecyyj7v(seq_0_Ijes23h1_arecyyj7v* dest_5, NI32 addedElements_5){
  NB8 result_47;
  NI32 X60Qx_326 = capInBytes_0_In2lvry_arecyyj7v((*dest_5));
  NI32 oldCap_1 = ((NI32)(X60Qx_326 / sizeof(RegionHandout_0_arecyyj7v)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_5);
  NI32 memSize_5 = memSizeInBytes_0_If6e4np_arecyyj7v(newCap_1);
  void* X60Qx_327 = realloc_1_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_5);
  (*dest_5).data_0 = ((RegionHandout_0_arecyyj7v*)X60Qx_327);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_5);
    result_47 = NIM_FALSE;}
  else {
    result_47 = NIM_TRUE;}
  return result_47;}
static inline NI32 capInBytes_0_Iswy84i_arecyyj7v(seq_0_Isge9lx_arecyyj7v s_49){
  NI32 result_48;
  NI32 X60Qx_17;
  if ((!(s_49.data_0 == NIM_NIL))){
    NI32 X60Qx_328 = allocatedSize_0_sysvq0asl(((void*)((void*)s_49.data_0)));
    X60Qx_17 = X60Qx_328;}
  else {
    X60Qx_17 = 0;}
  result_48 = X60Qx_17;
  return result_48;}
NB8 resize_0_Ipftt5t1_arecyyj7v(seq_0_Isge9lx_arecyyj7v* dest_6, NI32 addedElements_6){
  NB8 result_49;
  NI32 X60Qx_329 = capInBytes_0_Iswy84i_arecyyj7v((*dest_6));
  NI32 oldCap_2 = ((NI32)(X60Qx_329 / sizeof(MatEntry_0_arecyyj7v)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_6);
  NI32 memSize_6 = memSizeInBytes_0_Isdq9ys1_arecyyj7v(newCap_2);
  void* X60Qx_330 = realloc_1_sysvq0asl(((void*)((void*)(*dest_6).data_0)), memSize_6);
  (*dest_6).data_0 = ((MatEntry_0_arecyyj7v*)X60Qx_330);
  if ((*dest_6).data_0 == NIM_NIL){
    (*dest_6).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_6);
    result_49 = NIM_FALSE;}
  else {
    result_49 = NIM_TRUE;}
  return result_49;}
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
NB8 resize_0_Ieull6y_arecyyj7v(seq_0_Igsxz3n_arecyyj7v* dest_7, NI32 addedElements_7){
  NB8 result_51;
  NI32 X60Qx_332 = capInBytes_0_Ia2b4aa_arecyyj7v((*dest_7));
  NI32 oldCap_3 = ((NI32)(X60Qx_332 / sizeof(NU32)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_7);
  NI32 memSize_7 = memSizeInBytes_0_Ioqvae11_arecyyj7v(newCap_3);
  void* X60Qx_333 = realloc_1_sysvq0asl(((void*)((void*)(*dest_7).data_0)), memSize_7);
  (*dest_7).data_0 = ((NU32*)X60Qx_333);
  if ((*dest_7).data_0 == NIM_NIL){
    (*dest_7).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_7);
    result_51 = NIM_FALSE;}
  else {
    result_51 = NIM_TRUE;}
  return result_51;}
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
void eQdestroy_1_Ipblso_arecyyj7v(seq_0_Isge9lx_arecyyj7v s_67){
  if ((!(s_67.data_0 == NIM_NIL))){
    NI32 i_35 = 0;
    {
      while (i_35 < s_67.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_35));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_67.data_0)));}}
static inline void eQwasMoved_1_Is4d7xm_arecyyj7v(seq_0_Isge9lx_arecyyj7v* s_68){
  (*s_68).len_0 = 0;
  (*s_68).data_0 = NIM_NIL;}
void eQdestroy_1_Ibaacft1_arecyyj7v(seq_0_Idhq52f_arecyyj7v s_69){
  if ((!(s_69.data_0 == NIM_NIL))){
    NI32 i_39 = 0;
    {
      while (i_39 < s_69.len_0){
        eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&s_69.data_0[i_39]));
        inc_1_I6wjjge_aow2h993l1((&i_39));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_69.data_0)));}}
static inline void eQwasMoved_1_I749drk_arecyyj7v(seq_0_Idhq52f_arecyyj7v* s_70){
  (*s_70).len_0 = 0;
  (*s_70).data_0 = NIM_NIL;}
void eQdestroy_1_Iikae831_arecyyj7v(seq_0_Ijes23h1_arecyyj7v s_71){
  if ((!(s_71.data_0 == NIM_NIL))){
    NI32 i_43 = 0;
    {
      while (i_43 < s_71.len_0){
        eQdestroyQ_SX52egionX48andout0arecyyj7v_0_arecyyj7v(s_71.data_0[i_43]);
        inc_1_I6wjjge_aow2h993l1((&i_43));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_71.data_0)));}}
static inline void eQwasMoved_1_I3b6vpj1_arecyyj7v(seq_0_Ijes23h1_arecyyj7v* s_72){
  (*s_72).len_0 = 0;
  (*s_72).data_0 = NIM_NIL;}
void eQdestroy_1_Ib6pp1_arecyyj7v(seq_0_Igsxz3n_arecyyj7v s_73){
  if ((!(s_73.data_0 == NIM_NIL))){
    NI32 i_47 = 0;
    {
      while (i_47 < s_73.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_47));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_73.data_0)));}}
void eQdestroy_1_I8k3d0z1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_75){
  if ((!(s_75.data_0 == NIM_NIL))){
    NI32 i_51 = 0;
    {
      while (i_51 < s_75.len_0){
        eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v(s_75.data_0[i_51]);
        inc_1_I6wjjge_aow2h993l1((&i_51));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_75.data_0)));}}
static inline void eQwasMoved_1_I4kgdoh1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v* s_76){
  (*s_76).len_0 = 0;
  (*s_76).data_0 = NIM_NIL;}
seq_0_Iw8xl5b1_arecyyj7v eQdup_1_Io30l171_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v a_15){
  seq_0_Iw8xl5b1_arecyyj7v result_57;
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_354 = newSeqUninit_0_I1tbjnk1_arecyyj7v(a_15.len_0);
  result_57 = X60Qx_354;
  NI32 i_52 = 0;
  {
    while (i_52 < a_15.len_0){
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_355 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v(a_15.data_0[i_52]);
      result_57.data_0[i_52] = X60Qx_355;
      inc_1_I6wjjge_aow2h993l1((&i_52));}}
  whileStmtLabel_0: ;
  return result_57;}
void eQdestroy_1_Ijx6eoq_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_78){
  if ((!(s_78.data_0 == NIM_NIL))){
    NI32 i_55 = 0;
    {
      while (i_55 < s_78.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_55));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_78.data_0)));}}
static inline void eQwasMoved_1_I861g1c1_arecyyj7v(seq_0_Incv1wn_arecyyj7v* s_79){
  (*s_79).len_0 = 0;
  (*s_79).data_0 = NIM_NIL;}
void eQdestroy_1_Iscb4i31_arecyyj7v(seq_0_In6doa_arecyyj7v s_81){
  if ((!(s_81.data_0 == NIM_NIL))){
    NI32 i_59 = 0;
    {
      while (i_59 < s_81.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_59));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_81.data_0)));}}
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82){
  (*s_82).len_0 = 0;
  (*s_82).data_0 = NIM_NIL;}
seq_0_In6doa_arecyyj7v eQdup_1_Idg8rf9_arecyyj7v(seq_0_In6doa_arecyyj7v a_17){
  seq_0_In6doa_arecyyj7v result_59;
  seq_0_In6doa_arecyyj7v X60Qx_364 = newSeqUninit_0_Ieodq4s1_arecyyj7v(a_17.len_0);
  result_59 = X60Qx_364;
  NI32 i_60 = 0;
  {
    while (i_60 < a_17.len_0){
      result_59.data_0[i_60] = a_17.data_0[i_60];
      inc_1_I6wjjge_aow2h993l1((&i_60));}}
  whileStmtLabel_0: ;
  return result_59;}
void eQdestroy_1_Ijysww_arecyyj7v(seq_0_Id0odh1_arecyyj7v s_84){
  if ((!(s_84.data_0 == NIM_NIL))){
    NI32 i_63 = 0;
    {
      while (i_63 < s_84.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_63));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_84.data_0)));}}
static inline void eQwasMoved_1_Imwcp1s_arecyyj7v(seq_0_Id0odh1_arecyyj7v* s_85){
  (*s_85).len_0 = 0;
  (*s_85).data_0 = NIM_NIL;}
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
static inline NI32 capInBytes_0_Iffahgv_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_88){
  NI32 result_65;
  NI32 X60Qx_20;
  if ((!(s_88.data_0 == NIM_NIL))){
    NI32 X60Qx_377 = allocatedSize_0_sysvq0asl(((void*)((void*)s_88.data_0)));
    X60Qx_20 = X60Qx_377;}
  else {
    X60Qx_20 = 0;}
  result_65 = X60Qx_20;
  return result_65;}
static inline NI32 memSizeInBytes_0_Infw7m1_arecyyj7v(NI32 size_27){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_66;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_27, sizeof(NU8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_66 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_66 = ((NI32)2147483647);}
  return result_66;}
static inline seq_0_In6doa_arecyyj7v newSeqUninit_0_Ieodq4s1_arecyyj7v(NI32 size_28){
  seq_0_In6doa_arecyyj7v result_67;
  if (size_28 == 0){
    result_67 = (seq_0_In6doa_arecyyj7v){
      .len_0 = size_28, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_18 = memSizeInBytes_0_Ivqzo5x1_arecyyj7v(size_28);
    void* X60Qx_378 = alloc_1_sysvq0asl(memSize_18);
    result_67 = (seq_0_In6doa_arecyyj7v){
      .len_0 = size_28, .data_0 = ((NU32*)X60Qx_378)}
    ;
    if ((!(result_67.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_379 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_67.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_18);}}
  return result_67;}
static inline NI32 capInBytes_0_Iev6wua1_arecyyj7v(seq_0_In6doa_arecyyj7v s_89){
  NI32 result_68;
  NI32 X60Qx_21;
  if ((!(s_89.data_0 == NIM_NIL))){
    NI32 X60Qx_380 = allocatedSize_0_sysvq0asl(((void*)((void*)s_89.data_0)));
    X60Qx_21 = X60Qx_380;}
  else {
    X60Qx_21 = 0;}
  result_68 = X60Qx_21;
  return result_68;}
static inline NI32 memSizeInBytes_0_Ivqzo5x1_arecyyj7v(NI32 size_29){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_69;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_29, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_69 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_69 = ((NI32)2147483647);}
  return result_69;}
static inline seq_0_Id0odh1_arecyyj7v newSeqUninit_0_Ilswql7_arecyyj7v(NI32 size_30){
  seq_0_Id0odh1_arecyyj7v result_70;
  if (size_30 == 0){
    result_70 = (seq_0_Id0odh1_arecyyj7v){
      .len_0 = size_30, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_19 = memSizeInBytes_0_Icryocg_arecyyj7v(size_30);
    void* X60Qx_381 = alloc_1_sysvq0asl(memSize_19);
    result_70 = (seq_0_Id0odh1_arecyyj7v){
      .len_0 = size_30, .data_0 = ((FieldOff_0_fiepkwzpc*)X60Qx_381)}
    ;
    if ((!(result_70.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_382 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_70.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_19);}}
  return result_70;}
static inline NI32 capInBytes_0_I62hqc31_arecyyj7v(seq_0_Id0odh1_arecyyj7v s_90){
  NI32 result_71;
  NI32 X60Qx_22;
  if ((!(s_90.data_0 == NIM_NIL))){
    NI32 X60Qx_383 = allocatedSize_0_sysvq0asl(((void*)((void*)s_90.data_0)));
    X60Qx_22 = X60Qx_383;}
  else {
    X60Qx_22 = 0;}
  result_71 = X60Qx_22;
  return result_71;}
static inline NI32 memSizeInBytes_0_Icryocg_arecyyj7v(NI32 size_31){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_72;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_31, sizeof(FieldOff_0_fiepkwzpc), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_72 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_72 = ((NI32)2147483647);}
  return result_72;}
void eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v(BlockEntry_0_arecyyj7v* dest_0){
  eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v((*dest_0).cell_0);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v((*dest_0).arr_0);
  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v((*dest_0).sq_0);}
void eQwasmovedQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v(BlockEntry_0_arecyyj7v* dest_0){
  eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v((&(*dest_0).sq_0));
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v((&(*dest_0).arr_0));
  eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v((&(*dest_0).cell_0));}
BlockEntry_0_arecyyj7v eQdupQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v(BlockEntry_0_arecyyj7v* src_0){
  BlockEntry_0_arecyyj7v dest_0;
  dest_0.key_0 = (*src_0).key_0;
  dest_0.data_0 = (*src_0).data_0;
  dest_0.stride_0 = (*src_0).stride_0;
  dest_0.count_0 = (*src_0).count_0;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_384 = eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v((*src_0).sq_0);
  dest_0.sq_0 = X60Qx_384;
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_385 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v((*src_0).arr_0);
  dest_0.arr_0 = X60Qx_385;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_386 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v((*src_0).cell_0);
  dest_0.cell_0 = X60Qx_386;
  return dest_0;}
void eQdestroyQ_SX52egionX48andout0arecyyj7v_0_arecyyj7v(RegionHandout_0_arecyyj7v dest_0){
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(dest_0.r_0);}
RegionHandout_0_arecyyj7v eQdupQ_SX52egionX48andout0arecyyj7v_0_arecyyj7v(RegionHandout_0_arecyyj7v src_0){
  RegionHandout_0_arecyyj7v dest_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qx_387 = eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(src_0.r_0);
  dest_0.r_0 = X60Qx_387;
  dest_0.base_0 = src_0.base_0;
  dest_0.size_0 = src_0.size_0;
  return dest_0;}
void eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v(ArenaMat_0_arecyyj7v* dest_0){
  eQdestroy_1_Iikae831_arecyyj7v((*dest_0).regions_0);
  eQdestroy_1_Ibaacft1_arecyyj7v((*dest_0).blocks_0);
  eQdestroy_1_Ipblso_arecyyj7v((*dest_0).seen_0);
  eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_arecyyj7v((*dest_0).a_0);}
void eQwasmovedQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v(ArenaMat_0_arecyyj7v* dest_0){
  eQwasmovedQ_ArefSX41renaX4fbj0arewp645e1_0_arecyyj7v((&(*dest_0).a_0));
  eQwasMoved_1_Is4d7xm_arecyyj7v((&(*dest_0).seen_0));
  eQwasMoved_1_I749drk_arecyyj7v((&(*dest_0).blocks_0));
  eQwasMoved_1_I3b6vpj1_arecyyj7v((&(*dest_0).regions_0));}
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_392 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_392){
      eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_393 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_393){
      eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_394 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_394){
      eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_395 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_395){
      eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_arecyyj7v(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* dest_0){
  if (dest_0){
    NB8 X60Qx_396 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_396){
      eQdestroyQ_SX41renaX4fbj0arewp645e1_0_arewp645e1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX41renaX4fbj0arewp645e1_0_arecyyj7v(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* eQdupQ_ArefSX41renaX4fbj0arewp645e1_0_arecyyj7v(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* src_0){
  X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_397 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_397){
      eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQwasmovedQ_AtupleSX56alue0valzr1t4fAbool_0_arecyyj7v(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v* dest_0){
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_arecyyj7v(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_0));}
void eQdestroyQ_ArefSX50trX4fvX4fbj0valzr1t4f_0_arecyyj7v(X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v* dest_0){
  if (dest_0){
    NB8 X60Qx_398 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_398){
      eQdestroyQ_SX50trX4fvX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void X60Qini_0_arecyyj7v(void){
  if (X60QiniGuard_0_arecyyj7v){
    return;}
  X60QiniGuard_0_arecyyj7v = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_valzr1t4f();
  X60Qini_0_arewp645e1();
  X60Qini_0_fiepkwzpc();
  X60Qini_0_heapjafyf1();
  X60Qini_0_croph25r5();}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline void pokeByte_0_arewp645e1(void* p_1, NI32 off_0, NU8 v_0){
  (*((NU8*)((void*)((NU32)(((NU32)p_1) + ((NU32)off_0)))))) = v_0;}
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
static inline NI32 base_0_valzr1t4f(Value_0_valzr1t4f* v_6){
  NI32 result_24;
  NI64 X60Qx_5;
  if ((*v_6).ov_0 == NIM_NIL){
    X60Qx_5 = 0;}
  else {
    X60Qx_5 = (*(*v_6).ov_0).d_00.base_0;}
  result_24 = X60Qx_5;
  return result_24;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
static inline NU8 peekByte_0_arewp645e1(void* p_2, NI32 off_1){
  NU8 result_6;
  result_6 = (*((NU8*)((void*)((NU32)(((NU32)p_2) + ((NU32)off_1))))));
  return result_6;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
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
