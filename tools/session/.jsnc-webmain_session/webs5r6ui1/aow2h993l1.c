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
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
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
typedef struct X60Qt_0_IAarrayAuS8ZS3_aow2h993l1{
  NU8 a[3];}
X60Qt_0_IAarrayAuS8ZS3_aow2h993l1;
typedef NU16 NimonyExpr_0_nimry5ra91;

#define NoExpr_0_nimry5ra91 ((NU16)0)
#define ErrX_0_nimry5ra91 ((NU16)1)
#define SufX_0_nimry5ra91 ((NU16)2)
#define AtX_0_nimry5ra91 ((NU16)3)
#define DerefX_0_nimry5ra91 ((NU16)4)
#define DotX_0_nimry5ra91 ((NU16)5)
#define PatX_0_nimry5ra91 ((NU16)6)
#define ParX_0_nimry5ra91 ((NU16)7)
#define AddrX_0_nimry5ra91 ((NU16)8)
#define NilX_0_nimry5ra91 ((NU16)9)
#define InfX_0_nimry5ra91 ((NU16)12)
#define NeginfX_0_nimry5ra91 ((NU16)13)
#define NanX_0_nimry5ra91 ((NU16)14)
#define FalseX_0_nimry5ra91 ((NU16)15)
#define TrueX_0_nimry5ra91 ((NU16)16)
#define AndX_0_nimry5ra91 ((NU16)17)
#define OrX_0_nimry5ra91 ((NU16)18)
#define XorX_0_nimry5ra91 ((NU16)19)
#define NotX_0_nimry5ra91 ((NU16)20)
#define NegX_0_nimry5ra91 ((NU16)21)
#define SizeofX_0_nimry5ra91 ((NU16)22)
#define AlignofX_0_nimry5ra91 ((NU16)23)
#define OffsetofX_0_nimry5ra91 ((NU16)24)
#define OconstrX_0_nimry5ra91 ((NU16)25)
#define AconstrX_0_nimry5ra91 ((NU16)26)
#define BracketX_0_nimry5ra91 ((NU16)27)
#define CurlyX_0_nimry5ra91 ((NU16)28)
#define CurlyatX_0_nimry5ra91 ((NU16)29)
#define KvX_0_nimry5ra91 ((NU16)30)
#define OvfX_0_nimry5ra91 ((NU16)32)
#define AddX_0_nimry5ra91 ((NU16)33)
#define SubX_0_nimry5ra91 ((NU16)34)
#define MulX_0_nimry5ra91 ((NU16)35)
#define DivX_0_nimry5ra91 ((NU16)36)
#define ModX_0_nimry5ra91 ((NU16)37)
#define ShrX_0_nimry5ra91 ((NU16)38)
#define ShlX_0_nimry5ra91 ((NU16)39)
#define BitandX_0_nimry5ra91 ((NU16)40)
#define BitorX_0_nimry5ra91 ((NU16)41)
#define BitxorX_0_nimry5ra91 ((NU16)42)
#define BitnotX_0_nimry5ra91 ((NU16)43)
#define EqX_0_nimry5ra91 ((NU16)44)
#define NeqX_0_nimry5ra91 ((NU16)45)
#define LeX_0_nimry5ra91 ((NU16)46)
#define LtX_0_nimry5ra91 ((NU16)47)
#define CastX_0_nimry5ra91 ((NU16)48)
#define ConvX_0_nimry5ra91 ((NU16)49)
#define CallX_0_nimry5ra91 ((NU16)50)
#define CmdX_0_nimry5ra91 ((NU16)51)
#define CchoiceX_0_nimry5ra91 ((NU16)80)
#define OchoiceX_0_nimry5ra91 ((NU16)81)
#define PragmaxX_0_nimry5ra91 ((NU16)141)
#define QQuotedX_0_nimry5ra91 ((NU16)235)
#define HderefX_0_nimry5ra91 ((NU16)236)
#define DdotX_0_nimry5ra91 ((NU16)237)
#define HaddrX_0_nimry5ra91 ((NU16)238)
#define NewrefX_0_nimry5ra91 ((NU16)239)
#define NewobjX_0_nimry5ra91 ((NU16)240)
#define TupX_0_nimry5ra91 ((NU16)241)
#define TupconstrX_0_nimry5ra91 ((NU16)242)
#define SetconstrX_0_nimry5ra91 ((NU16)243)
#define TabconstrX_0_nimry5ra91 ((NU16)244)
#define AshrX_0_nimry5ra91 ((NU16)245)
#define BaseobjX_0_nimry5ra91 ((NU16)246)
#define HconvX_0_nimry5ra91 ((NU16)247)
#define DconvX_0_nimry5ra91 ((NU16)248)
#define CallstrlitX_0_nimry5ra91 ((NU16)249)
#define InfixX_0_nimry5ra91 ((NU16)250)
#define PrefixX_0_nimry5ra91 ((NU16)251)
#define HcallX_0_nimry5ra91 ((NU16)252)
#define CompilesX_0_nimry5ra91 ((NU16)253)
#define DeclaredX_0_nimry5ra91 ((NU16)254)
#define DefinedX_0_nimry5ra91 ((NU16)255)
#define AstToStrX_0_nimry5ra91 ((NU16)256)
#define BindSymX_0_nimry5ra91 ((NU16)257)
#define BindSymNameX_0_nimry5ra91 ((NU16)258)
#define InstanceofX_0_nimry5ra91 ((NU16)259)
#define ProccallX_0_nimry5ra91 ((NU16)260)
#define HighX_0_nimry5ra91 ((NU16)261)
#define LowX_0_nimry5ra91 ((NU16)262)
#define TypeofX_0_nimry5ra91 ((NU16)263)
#define UnpackX_0_nimry5ra91 ((NU16)264)
#define FieldsX_0_nimry5ra91 ((NU16)265)
#define FieldpairsX_0_nimry5ra91 ((NU16)266)
#define EnumtostrX_0_nimry5ra91 ((NU16)267)
#define IsmainmoduleX_0_nimry5ra91 ((NU16)268)
#define DefaultobjX_0_nimry5ra91 ((NU16)269)
#define DefaulttupX_0_nimry5ra91 ((NU16)270)
#define DefaultdistinctX_0_nimry5ra91 ((NU16)271)
#define DelayX_0_nimry5ra91 ((NU16)272)
#define Delay0X_0_nimry5ra91 ((NU16)273)
#define SuspendX_0_nimry5ra91 ((NU16)274)
#define ExprX_0_nimry5ra91 ((NU16)275)
#define DoX_0_nimry5ra91 ((NU16)276)
#define ArratX_0_nimry5ra91 ((NU16)277)
#define TupatX_0_nimry5ra91 ((NU16)278)
#define PlussetX_0_nimry5ra91 ((NU16)279)
#define MinussetX_0_nimry5ra91 ((NU16)280)
#define MulsetX_0_nimry5ra91 ((NU16)281)
#define XorsetX_0_nimry5ra91 ((NU16)282)
#define EqsetX_0_nimry5ra91 ((NU16)283)
#define LesetX_0_nimry5ra91 ((NU16)284)
#define LtsetX_0_nimry5ra91 ((NU16)285)
#define InsetX_0_nimry5ra91 ((NU16)286)
#define CardX_0_nimry5ra91 ((NU16)287)
#define EmoveX_0_nimry5ra91 ((NU16)288)
#define DestroyX_0_nimry5ra91 ((NU16)289)
#define DupX_0_nimry5ra91 ((NU16)290)
#define CopyX_0_nimry5ra91 ((NU16)291)
#define WasmovedX_0_nimry5ra91 ((NU16)292)
#define SinkhX_0_nimry5ra91 ((NU16)293)
#define TraceX_0_nimry5ra91 ((NU16)294)
#define InternalTypeNameX_0_nimry5ra91 ((NU16)319)
#define InternalFieldPairsX_0_nimry5ra91 ((NU16)320)
#define FailedX_0_nimry5ra91 ((NU16)321)
#define IsX_0_nimry5ra91 ((NU16)322)
#define EnvpX_0_nimry5ra91 ((NU16)323)
#define ToClosureX_0_nimry5ra91 ((NU16)341)
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
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
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline void dec_1_I2mwrey1_aow2h993l1(NI64* x_8);
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern NI64 asInt_0_valzr1t4f(Value_0_valzr1t4f* v_17);
extern xint_0_xinat3x34 createXint_0_xinat3x34(NI64 x_4);
extern NU64 asUnsigned_0_xinat3x34(xint_0_xinat3x34 x_3, NB8* err_1);
extern NI64 asSigned_0_xinat3x34(xint_0_xinat3x34 x_2, NB8* err_0);
extern NF64 toFloat64_0_xinat3x34(xint_0_xinat3x34 x_7);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0_valzr1t4f(Value_0_valzr1t4f* v_7);
static inline NI32 foff_0_valzr1t4f(Value_0_valzr1t4f* v_8);
static inline X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0_valzr1t4f(Value_0_valzr1t4f* v_4);
static inline NI32 base_0_valzr1t4f(Value_0_valzr1t4f* v_6);
static inline X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0_valzr1t4f(Value_0_valzr1t4f* v_5);
extern NB8 eqQ_0_xinat3x34(xint_0_xinat3x34 a_18, xint_0_xinat3x34 b_10);
extern NB8 ltQ_0_xinat3x34(xint_0_xinat3x34 a_19, xint_0_xinat3x34 b_11);
extern NB8 leQ_0_xinat3x34(xint_0_xinat3x34 a_20, xint_0_xinat3x34 b_12);
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern Value_0_valzr1t4f vFloat_0_valzr1t4f(NF64 f_0, NI32 bits_4);
extern xint_0_xinat3x34 zero_0_xinat3x34(void);
extern xint_0_xinat3x34 div_0_xinat3x34(xint_0_xinat3x34 a_5, xint_0_xinat3x34 b_3);
extern xint_0_xinat3x34 mod_0_xinat3x34(xint_0_xinat3x34 a_13, xint_0_xinat3x34 b_9);
extern xint_0_xinat3x34 mask_0_xinat3x34(xint_0_xinat3x34 a_14, NI32 bits_0, NB8 signed_0);
extern Value_0_valzr1t4f vIntX_0_valzr1t4f(xint_0_xinat3x34 x_3, NI32 bits_1);
extern Value_0_valzr1t4f vUIntX_0_valzr1t4f(xint_0_xinat3x34 x_5, NI32 bits_3);
extern Value_0_valzr1t4f vInt_0_valzr1t4f(NI64 x_2, NI32 bits_0);
extern Value_0_valzr1t4f vUInt_0_valzr1t4f(NU64 x_4, NI32 bits_2);
extern xint_0_xinat3x34 shr_0_xinat3x34(xint_0_xinat3x34 a_8, NI32 b_5);
extern Value_0_valzr1t4f vNil_0_valzr1t4f(void);
extern Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0);
extern NB8 truthy_0_valzr1t4f(Value_0_valzr1t4f* v_18);
extern xint_0_xinat3x34 minusQ_0_xinat3x34(xint_0_xinat3x34 a_0);
extern xint_0_xinat3x34 not_0_xinat3x34(xint_0_xinat3x34 a_12);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(FlatRegion_Obj_0_valzr1t4f dest_0);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(ArrBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(SeqBox_Obj_0_valzr1t4f dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_xinat3x34(void);
extern void X60Qini_0_nimry5ra91(void);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
extern void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0);
extern void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
extern void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
NB8 X60QiniGuard_0_aow2h993l1;
xint_0_xinat3x34 toXint_0_aow2h993l1(Value_0_valzr1t4f* v_0){
  xint_0_xinat3x34 result_0;
  switch ((*v_0).kind_0){
    case 1:
    case 2:
    {
      result_0 = (*v_0).ival_0;}
    break;
    default:
    {
      NI64 X60Qx_16 = asInt_0_valzr1t4f((&(*v_0)));
      xint_0_xinat3x34 X60Qx_17 = createXint_0_xinat3x34(X60Qx_16);
      result_0 = X60Qx_17;}
    break;}
  return result_0;}
NU64 u64bits_0_aow2h993l1(Value_0_valzr1t4f* v_1){
  NU64 result_1;
  xint_0_xinat3x34 x_1 = toXint_0_aow2h993l1((&(*v_1)));
  NB8 err_0 = NIM_FALSE;
  NU64 X60Qx_18 = asUnsigned_0_xinat3x34(x_1, (&err_0));
  result_1 = X60Qx_18;
  if (err_0){
    err_0 = NIM_FALSE;
    NI64 X60Qx_19 = asSigned_0_xinat3x34(x_1, (&err_0));
    result_1 = ((NU64)X60Qx_19);}
  return result_1;}
NF64 toFloat_0_aow2h993l1(Value_0_valzr1t4f* v_2){
  NF64 result_2;
  switch ((*v_2).kind_0){
    case 3:
    {
      result_2 = (*v_2).fval_0;}
    break;
    case 1:
    case 2:
    {
      NF64 X60Qx_20 = toFloat64_0_xinat3x34((*v_2).ival_0);
      result_2 = X60Qx_20;}
    break;
    default:
    {
      NI64 X60Qx_21 = asInt_0_valzr1t4f((&(*v_2)));
      result_2 = ((NF64)X60Qx_21);}
    break;}
  return result_2;}
NB8 strEq_0_aow2h993l1(string_0_sysvq0asl a_0, string_0_sysvq0asl b_0){
  NB8 result_3;
  NI32 X60Qx_22 = len_4_sysvq0asl(a_0);
  NI32 X60Qx_23 = len_4_sysvq0asl(b_0);
  if ((!(X60Qx_22 == X60Qx_23))){
    result_3 = NIM_FALSE;}
  else {
    NI32 i_0 = 0;
    result_3 = NIM_TRUE;
    {
      while (NIM_TRUE){
        NI32 X60Qx_24 = len_4_sysvq0asl(a_0);
        if (i_0 < X60Qx_24){
          NC8 X60Qx_25 = getQ_9_sysvq0asl(a_0, i_0);
          NC8 X60Qx_26 = getQ_9_sysvq0asl(b_0, i_0);
          if ((!(X60Qx_25 == X60Qx_26))){
            result_3 = NIM_FALSE;
            goto whileStmtLabel_0;}
          inc_1_I6wjjge_aow2h993l1((&i_0));}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  return result_3;}
NB8 strLt_0_aow2h993l1(string_0_sysvq0asl a_1, string_0_sysvq0asl b_1){
  NB8 result_4;
  NI32 n_0 = len_4_sysvq0asl(a_1);
  NI32 X60Qx_27 = len_4_sysvq0asl(b_1);
  if (X60Qx_27 < n_0){
    NI32 X60Qx_28 = len_4_sysvq0asl(b_1);
    n_0 = X60Qx_28;}
  NI32 i_1 = 0;
  result_4 = NIM_FALSE;
  NB8 decided_0 = NIM_FALSE;
  {
    while (i_1 < n_0){
      NC8 X60Qx_29 = getQ_9_sysvq0asl(a_1, i_1);
      NC8 X60Qx_30 = getQ_9_sysvq0asl(b_1, i_1);
      if ((!(X60Qx_29 == X60Qx_30))){
        NC8 X60Qx_31 = getQ_9_sysvq0asl(a_1, i_1);
        NC8 X60Qx_32 = getQ_9_sysvq0asl(b_1, i_1);
        result_4 = (X60Qx_31 < X60Qx_32);
        decided_0 = NIM_TRUE;
        goto whileStmtLabel_0;}
      inc_1_I6wjjge_aow2h993l1((&i_1));}}
  whileStmtLabel_0: ;
  if ((!decided_0)){
    NI32 X60Qx_33 = len_4_sysvq0asl(a_1);
    NI32 X60Qx_34 = len_4_sysvq0asl(b_1);
    result_4 = (X60Qx_33 < X60Qx_34);}
  return result_4;}
NB8 sameRegionTarget_0_aow2h993l1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* x_0, X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* y_0){
  NB8 result_5;
  if (x_0 == y_0){
    return NIM_TRUE;}
  NB8 X60Qx_35;
  if (x_0 == NIM_NIL){
    X60Qx_35 = NIM_TRUE;}
  else {
    X60Qx_35 = (y_0 == NIM_NIL);}
  if (X60Qx_35){
    return NIM_FALSE;}
  if ((!((*x_0).d_00.kind_0 == (*y_0).d_00.kind_0))){
    return NIM_FALSE;}
  switch ((*x_0).d_00.kind_0){
    case 0:
    {
      result_5 = NIM_FALSE;}
    break;
    case 6:
    {
      result_5 = ((*x_0).d_00.haddr_0 == (*y_0).d_00.haddr_0);}
    break;
    case 1:
    {
      result_5 = ((*x_0).d_00.sbox_0 == (*y_0).d_00.sbox_0);}
    break;
    case 2:
    {
      result_5 = ((*x_0).d_00.abox_0 == (*y_0).d_00.abox_0);}
    break;
    case 3:
    {
      result_5 = ((*x_0).d_00.scell_0 == (*y_0).d_00.scell_0);}
    break;
    case 4:
    {
      result_5 = ((*x_0).d_00.ccell_0 == (*y_0).d_00.ccell_0);}
    break;
    case 5:
    {
      result_5 = ((*x_0).d_00.obox_0 == (*y_0).d_00.obox_0);}
    break;}
  return result_5;}
NB8 cstringAddrVsValue_0_aow2h993l1(Value_0_valzr1t4f* a_2, Value_0_valzr1t4f* b_2){
  NB8 result_6;
  result_6 = NIM_FALSE;
  return result_6;}
NB8 cmpEq_0_aow2h993l1(Value_0_valzr1t4f* a_3, Value_0_valzr1t4f* b_3){
  NB8 result_7;
  NB8 X60Qx_36;
  NB8 X60Qx_37;
  if ((*a_3).kind_0 == 13){
    X60Qx_37 = ((*b_3).kind_0 == 6);}
  else {
    X60Qx_37 = NIM_FALSE;}
  if (X60Qx_37){
    X60Qx_36 = NIM_TRUE;}
  else {
    NB8 X60Qx_38;
    if ((*a_3).kind_0 == 6){
      X60Qx_38 = ((*b_3).kind_0 == 13);}
    else {
      X60Qx_38 = NIM_FALSE;}
    X60Qx_36 = X60Qx_38;}
  if (X60Qx_36){
    NB8 X60Qx_39 = cstringAddrVsValue_0_aow2h993l1((&(*a_3)), (&(*b_3)));
    result_7 = X60Qx_39;}
  else {
    NB8 X60Qx_40;
    if ((*a_3).kind_0 == 6){
      X60Qx_40 = ((*b_3).kind_0 == 6);}
    else {
      X60Qx_40 = NIM_FALSE;}
    if (X60Qx_40){
      NB8 X60Qx_41 = strEq_0_aow2h993l1((*a_3).sval_0, (*b_3).sval_0);
      result_7 = X60Qx_41;}
    else {
      NB8 X60Qx_42;
      if ((*a_3).kind_0 == 3){
        X60Qx_42 = NIM_TRUE;}
      else {
        X60Qx_42 = ((*b_3).kind_0 == 3);}
      if (X60Qx_42){
        NF64 X60Qx_43 = toFloat_0_aow2h993l1((&(*a_3)));
        NF64 X60Qx_44 = toFloat_0_aow2h993l1((&(*b_3)));
        result_7 = (X60Qx_43 == X60Qx_44);}
      else {
        NB8 X60Qx_45;
        if ((*a_3).kind_0 == 0){
          X60Qx_45 = NIM_TRUE;}
        else {
          X60Qx_45 = ((*b_3).kind_0 == 0);}
        if (X60Qx_45){
          NB8 X60Qx_46;
          if ((*a_3).kind_0 == 0){
            X60Qx_46 = ((*b_3).kind_0 == 0);}
          else {
            X60Qx_46 = NIM_FALSE;}
          result_7 = X60Qx_46;}
        else {
          NB8 X60Qx_47;
          NB8 X60Qx_48;
          if ((*a_3).kind_0 == 1){
            X60Qx_48 = NIM_TRUE;}
          else {
            X60Qx_48 = ((*a_3).kind_0 == 2);}
          if (X60Qx_48){
            NB8 X60Qx_49;
            if ((*b_3).kind_0 == 1){
              X60Qx_49 = NIM_TRUE;}
            else {
              X60Qx_49 = ((*b_3).kind_0 == 2);}
            X60Qx_47 = X60Qx_49;}
          else {
            X60Qx_47 = NIM_FALSE;}
          if (X60Qx_47){
            NU64 X60Qx_50 = u64bits_0_aow2h993l1((&(*a_3)));
            NU64 X60Qx_51 = u64bits_0_aow2h993l1((&(*b_3)));
            result_7 = (X60Qx_50 == X60Qx_51);}
          else {
            NB8 X60Qx_52;
            if ((*a_3).kind_0 == 13){
              X60Qx_52 = ((*b_3).kind_0 == 13);}
            else {
              X60Qx_52 = NIM_FALSE;}
            if (X60Qx_52){
              NB8 X60Qx_4;
              X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_0 = region_0_valzr1t4f((&(*a_3)));
              if ((!(X60Qtmp_0 == NIM_NIL))){
                X60Qx_4 = NIM_TRUE;}
              else {
                X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_1 = region_0_valzr1t4f((&(*b_3)));
                X60Qx_4 = (!(X60Qtmp_1 == NIM_NIL));
                eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_1);}
              if (X60Qx_4){
                NB8 X60Qx_5;
                X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_2 = region_0_valzr1t4f((&(*a_3)));
                X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_3 = region_0_valzr1t4f((&(*b_3)));
                NB8 X60Qx_53 = sameRegionTarget_0_aow2h993l1(X60Qtmp_2, X60Qtmp_3);
                if (X60Qx_53){
                  NI32 X60Qx_54 = foff_0_valzr1t4f((&(*a_3)));
                  NI32 X60Qx_55 = foff_0_valzr1t4f((&(*b_3)));
                  X60Qx_5 = (X60Qx_54 == X60Qx_55);}
                else {
                  X60Qx_5 = NIM_FALSE;}
                result_7 = X60Qx_5;
                eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_3);
                eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_2);}
              else {
                NB8 X60Qx_6;
                X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_4 = arrOwn_0_valzr1t4f((&(*a_3)));
                if ((!(X60Qtmp_4 == NIM_NIL))){
                  X60Qx_6 = NIM_TRUE;}
                else {
                  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_5 = arrOwn_0_valzr1t4f((&(*b_3)));
                  X60Qx_6 = (!(X60Qtmp_5 == NIM_NIL));
                  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_5);}
                if (X60Qx_6){
                  NB8 X60Qx_7;
                  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_6 = arrOwn_0_valzr1t4f((&(*a_3)));
                  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_7 = arrOwn_0_valzr1t4f((&(*b_3)));
                  if (X60Qtmp_6 == X60Qtmp_7){
                    NI32 X60Qx_56 = base_0_valzr1t4f((&(*a_3)));
                    NI32 X60Qx_57 = base_0_valzr1t4f((&(*b_3)));
                    X60Qx_7 = (X60Qx_56 == X60Qx_57);}
                  else {
                    X60Qx_7 = NIM_FALSE;}
                  result_7 = X60Qx_7;
                  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_7);
                  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_6);}
                else {
                  NB8 X60Qx_8;
                  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_8 = seqOwn_0_valzr1t4f((&(*a_3)));
                  if ((!(X60Qtmp_8 == NIM_NIL))){
                    X60Qx_8 = NIM_TRUE;}
                  else {
                    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_9 = seqOwn_0_valzr1t4f((&(*b_3)));
                    X60Qx_8 = (!(X60Qtmp_9 == NIM_NIL));
                    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_9);}
                  if (X60Qx_8){
                    NB8 X60Qx_9;
                    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_10 = seqOwn_0_valzr1t4f((&(*a_3)));
                    X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_11 = seqOwn_0_valzr1t4f((&(*b_3)));
                    if (X60Qtmp_10 == X60Qtmp_11){
                      NI32 X60Qx_58 = base_0_valzr1t4f((&(*a_3)));
                      NI32 X60Qx_59 = base_0_valzr1t4f((&(*b_3)));
                      X60Qx_9 = (X60Qx_58 == X60Qx_59);}
                    else {
                      X60Qx_9 = NIM_FALSE;}
                    result_7 = X60Qx_9;
                    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_11);
                    eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_10);}
                  else {
                    result_7 = ((*a_3).loc_0 == (*b_3).loc_0);}
                  eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_8);}
                eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_4);}
              eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_0);}
            else {
              NB8 X60Qx_60;
              if ((*a_3).kind_0 == 12){
                X60Qx_60 = ((*b_3).kind_0 == 12);}
              else {
                X60Qx_60 = NIM_FALSE;}
              if (X60Qx_60){
                result_7 = ((*a_3).rf_0 == (*b_3).rf_0);}
              else {
                xint_0_xinat3x34 X60Qx_61 = toXint_0_aow2h993l1((&(*a_3)));
                xint_0_xinat3x34 X60Qx_62 = toXint_0_aow2h993l1((&(*b_3)));
                NB8 X60Qx_63 = eqQ_0_xinat3x34(X60Qx_61, X60Qx_62);
                result_7 = X60Qx_63;}}}}}}}
  return result_7;}
NB8 ptrOrdLt_0_aow2h993l1(Value_0_valzr1t4f* a_4, Value_0_valzr1t4f* b_4){
  NB8 result_8;
  NB8 X60Qx_10;
  NB8 X60Qx_11;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_12 = region_0_valzr1t4f((&(*a_4)));
  if ((!(X60Qtmp_12 == NIM_NIL))){
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_13 = region_0_valzr1t4f((&(*b_4)));
    X60Qx_11 = (!(X60Qtmp_13 == NIM_NIL));
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_13);}
  else {
    X60Qx_11 = NIM_FALSE;}
  if (X60Qx_11){
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_14 = region_0_valzr1t4f((&(*a_4)));
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_15 = region_0_valzr1t4f((&(*b_4)));
    X60Qx_10 = (X60Qtmp_14 == X60Qtmp_15);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_15);
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_14);}
  else {
    X60Qx_10 = NIM_FALSE;}
  if (X60Qx_10){
    NI32 X60Qx_64 = foff_0_valzr1t4f((&(*a_4)));
    NI32 X60Qx_65 = foff_0_valzr1t4f((&(*b_4)));
    result_8 = (((NI32)X60Qx_64) < ((NI32)X60Qx_65));}
  else {
    NB8 X60Qx_12;
    NB8 X60Qx_13;
    X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_16 = arrOwn_0_valzr1t4f((&(*a_4)));
    if ((!(X60Qtmp_16 == NIM_NIL))){
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_17 = arrOwn_0_valzr1t4f((&(*b_4)));
      X60Qx_13 = (!(X60Qtmp_17 == NIM_NIL));
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_17);}
    else {
      X60Qx_13 = NIM_FALSE;}
    if (X60Qx_13){
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_18 = arrOwn_0_valzr1t4f((&(*a_4)));
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_19 = arrOwn_0_valzr1t4f((&(*b_4)));
      X60Qx_12 = (X60Qtmp_18 == X60Qtmp_19);
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_19);
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_18);}
    else {
      X60Qx_12 = NIM_FALSE;}
    if (X60Qx_12){
      NI32 X60Qx_66 = base_0_valzr1t4f((&(*a_4)));
      NI32 X60Qx_67 = base_0_valzr1t4f((&(*b_4)));
      result_8 = (X60Qx_66 < X60Qx_67);}
    else {
      NB8 X60Qx_14;
      NB8 X60Qx_15;
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_20 = seqOwn_0_valzr1t4f((&(*a_4)));
      if ((!(X60Qtmp_20 == NIM_NIL))){
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_21 = seqOwn_0_valzr1t4f((&(*b_4)));
        X60Qx_15 = (!(X60Qtmp_21 == NIM_NIL));
        eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_21);}
      else {
        X60Qx_15 = NIM_FALSE;}
      if (X60Qx_15){
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_22 = seqOwn_0_valzr1t4f((&(*a_4)));
        X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_23 = seqOwn_0_valzr1t4f((&(*b_4)));
        X60Qx_14 = (X60Qtmp_22 == X60Qtmp_23);
        eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_23);
        eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_22);}
      else {
        X60Qx_14 = NIM_FALSE;}
      if (X60Qx_14){
        NI32 X60Qx_68 = base_0_valzr1t4f((&(*a_4)));
        NI32 X60Qx_69 = base_0_valzr1t4f((&(*b_4)));
        result_8 = (X60Qx_68 < X60Qx_69);}
      else {
        xint_0_xinat3x34 X60Qx_70 = toXint_0_aow2h993l1((&(*a_4)));
        xint_0_xinat3x34 X60Qx_71 = toXint_0_aow2h993l1((&(*b_4)));
        NB8 X60Qx_72 = ltQ_0_xinat3x34(X60Qx_70, X60Qx_71);
        result_8 = X60Qx_72;}
      eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_20);}
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_16);}
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_12);
  return result_8;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qtmp_12);
  return result_8;}
NB8 cmpLt_0_aow2h993l1(Value_0_valzr1t4f* a_5, Value_0_valzr1t4f* b_5){
  NB8 result_9;
  NB8 X60Qx_73;
  if ((*a_5).kind_0 == 6){
    X60Qx_73 = ((*b_5).kind_0 == 6);}
  else {
    X60Qx_73 = NIM_FALSE;}
  if (X60Qx_73){
    NB8 X60Qx_74 = strLt_0_aow2h993l1((*a_5).sval_0, (*b_5).sval_0);
    result_9 = X60Qx_74;}
  else {
    NB8 X60Qx_75;
    if ((*a_5).kind_0 == 3){
      X60Qx_75 = NIM_TRUE;}
    else {
      X60Qx_75 = ((*b_5).kind_0 == 3);}
    if (X60Qx_75){
      NF64 X60Qx_76 = toFloat_0_aow2h993l1((&(*a_5)));
      NF64 X60Qx_77 = toFloat_0_aow2h993l1((&(*b_5)));
      result_9 = (X60Qx_76 < X60Qx_77);}
    else {
      NB8 X60Qx_78;
      if ((*a_5).kind_0 == 13){
        X60Qx_78 = ((*b_5).kind_0 == 13);}
      else {
        X60Qx_78 = NIM_FALSE;}
      if (X60Qx_78){
        NB8 X60Qx_79 = ptrOrdLt_0_aow2h993l1((&(*a_5)), (&(*b_5)));
        result_9 = X60Qx_79;}
      else {
        xint_0_xinat3x34 X60Qx_80 = toXint_0_aow2h993l1((&(*a_5)));
        xint_0_xinat3x34 X60Qx_81 = toXint_0_aow2h993l1((&(*b_5)));
        NB8 X60Qx_82 = ltQ_0_xinat3x34(X60Qx_80, X60Qx_81);
        result_9 = X60Qx_82;}}}
  return result_9;}
NB8 cmpLe_0_aow2h993l1(Value_0_valzr1t4f* a_6, Value_0_valzr1t4f* b_6){
  NB8 result_10;
  NB8 X60Qx_83;
  if ((*a_6).kind_0 == 6){
    X60Qx_83 = ((*b_6).kind_0 == 6);}
  else {
    X60Qx_83 = NIM_FALSE;}
  if (X60Qx_83){
    NB8 X60Qx_84;
    NB8 X60Qx_85 = strLt_0_aow2h993l1((*a_6).sval_0, (*b_6).sval_0);
    if (X60Qx_85){
      X60Qx_84 = NIM_TRUE;}
    else {
      NB8 X60Qx_86 = strEq_0_aow2h993l1((*a_6).sval_0, (*b_6).sval_0);
      X60Qx_84 = X60Qx_86;}
    result_10 = X60Qx_84;}
  else {
    NB8 X60Qx_87;
    if ((*a_6).kind_0 == 3){
      X60Qx_87 = NIM_TRUE;}
    else {
      X60Qx_87 = ((*b_6).kind_0 == 3);}
    if (X60Qx_87){
      NF64 X60Qx_88 = toFloat_0_aow2h993l1((&(*a_6)));
      NF64 X60Qx_89 = toFloat_0_aow2h993l1((&(*b_6)));
      result_10 = (X60Qx_88 <= X60Qx_89);}
    else {
      NB8 X60Qx_90;
      if ((*a_6).kind_0 == 13){
        X60Qx_90 = ((*b_6).kind_0 == 13);}
      else {
        X60Qx_90 = NIM_FALSE;}
      if (X60Qx_90){
        NB8 X60Qx_91;
        NB8 X60Qx_92 = ptrOrdLt_0_aow2h993l1((&(*a_6)), (&(*b_6)));
        if (X60Qx_92){
          X60Qx_91 = NIM_TRUE;}
        else {
          NB8 X60Qx_93 = cmpEq_0_aow2h993l1((&(*a_6)), (&(*b_6)));
          X60Qx_91 = X60Qx_93;}
        result_10 = X60Qx_91;}
      else {
        xint_0_xinat3x34 X60Qx_94 = toXint_0_aow2h993l1((&(*a_6)));
        xint_0_xinat3x34 X60Qx_95 = toXint_0_aow2h993l1((&(*b_6)));
        NB8 X60Qx_96 = leQ_0_xinat3x34(X60Qx_94, X60Qx_95);
        result_10 = X60Qx_96;}}}
  return result_10;}
Value_0_valzr1t4f floatArith_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_0, Value_0_valzr1t4f* a_7, Value_0_valzr1t4f* b_7){
  Value_0_valzr1t4f result_11;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_11));
  NF64 x_3 = toFloat_0_aow2h993l1((&(*a_7)));
  NF64 y_1 = toFloat_0_aow2h993l1((&(*b_7)));
  NF64 r_0 = 0.0;
  switch (op_0){
    case 33:
    {
      r_0 = ((NF64)(x_3 + y_1));}
    break;
    case 34:
    {
      r_0 = ((NF64)(x_3 - y_1));}
    break;
    case 35:
    {
      r_0 = ((NF64)(x_3 * y_1));}
    break;
    case 36:
    {
      r_0 = ((NF64)(x_3 / y_1));}
    break;
    case 37:
    {
      NF64 q_0 = ((NF64)(x_3 / y_1));
      NF64 t_0 = ((NF64)((NI64)q_0));
      r_0 = ((NF64)(x_3 - ((NF64)(t_0 * y_1))));}
    break;
    default:
    {
      r_0 = 0.0;}
    break;}
  NI32 fb_0 = 64;
  if ((*a_7).kind_0 == 3){
    fb_0 = (*a_7).fbits_0;}
  else {
    if ((*b_7).kind_0 == 3){
      fb_0 = (*b_7).fbits_0;}}
  if (fb_0 == 32){
    r_0 = ((NF64)((NF32)r_0));}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_11));
  Value_0_valzr1t4f X60Qx_97 = vFloat_0_valzr1t4f(r_0, fb_0);
  result_11 = X60Qx_97;
  return result_11;}
Value_0_valzr1t4f intArith_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_1, Value_0_valzr1t4f* a_8, Value_0_valzr1t4f* b_8, NI32 bits_0, NB8 signed_0){
  Value_0_valzr1t4f result_12;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_12));
  xint_0_xinat3x34 r_1 = zero_0_xinat3x34();
  switch (op_1){
    case 33:
    case 34:
    case 35:
    {
      NU64 ua_0 = u64bits_0_aow2h993l1((&(*a_8)));
      NU64 ub_0 = u64bits_0_aow2h993l1((&(*b_8)));
      NU64 w_0 = ((NU64)0);
      switch (op_1){
        case 33:
        {
          w_0 = ((NU64)(ua_0 + ub_0));}
        break;
        case 34:
        {
          w_0 = ((NU64)(ua_0 - ub_0));}
        break;
        default:
        {
          w_0 = ((NU64)(ua_0 * ub_0));}
        break;}
      r_1 = (xint_0_xinat3x34){
        .nan_0 = NIM_FALSE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)w_0)}
      ;}
    break;
    case 36:
    {
      xint_0_xinat3x34 X60Qx_98 = toXint_0_aow2h993l1((&(*a_8)));
      xint_0_xinat3x34 X60Qx_99 = toXint_0_aow2h993l1((&(*b_8)));
      xint_0_xinat3x34 X60Qx_100 = div_0_xinat3x34(X60Qx_98, X60Qx_99);
      r_1 = X60Qx_100;}
    break;
    case 37:
    {
      xint_0_xinat3x34 X60Qx_101 = toXint_0_aow2h993l1((&(*a_8)));
      xint_0_xinat3x34 X60Qx_102 = toXint_0_aow2h993l1((&(*b_8)));
      xint_0_xinat3x34 X60Qx_103 = mod_0_xinat3x34(X60Qx_101, X60Qx_102);
      r_1 = X60Qx_103;}
    break;
    default:
    {
      xint_0_xinat3x34 X60Qx_104 = zero_0_xinat3x34();
      r_1 = X60Qx_104;}
    break;}
  xint_0_xinat3x34 m_0 = mask_0_xinat3x34(r_1, bits_0, signed_0);
  if (signed_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_12));
    Value_0_valzr1t4f X60Qx_105 = vIntX_0_valzr1t4f(m_0, bits_0);
    result_12 = X60Qx_105;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_12));
    Value_0_valzr1t4f X60Qx_106 = vUIntX_0_valzr1t4f(m_0, bits_0);
    result_12 = X60Qx_106;}
  NU64 X60Qx_107 = u64bits_0_aow2h993l1((&result_12));
  if (X60Qx_107 == ((NU64)0u)){
    Value_0_valzr1t4f X60Qx_0;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
    if (signed_0){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
      Value_0_valzr1t4f X60Qx_108 = vInt_0_valzr1t4f(((NI64)0), bits_0);
      X60Qx_0 = X60Qx_108;}
    else {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
      Value_0_valzr1t4f X60Qx_109 = vUInt_0_valzr1t4f(((NU64)0), bits_0);
      X60Qx_0 = X60Qx_109;}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_12));
    result_12 = X60Qx_0;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));}
  return result_12;}
Value_0_valzr1t4f bitOp_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_2, Value_0_valzr1t4f* a_9, Value_0_valzr1t4f* b_9, NI32 bits_1, NB8 signed_1){
  Value_0_valzr1t4f result_13;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_13));
  xint_0_xinat3x34 x_4 = toXint_0_aow2h993l1((&(*a_9)));
  xint_0_xinat3x34 r_2 = zero_0_xinat3x34();
  switch (op_2){
    case 40:
    {
      NU64 X60Qx_110 = u64bits_0_aow2h993l1((&(*a_9)));
      NU64 X60Qx_111 = u64bits_0_aow2h993l1((&(*b_9)));
      r_2 = (xint_0_xinat3x34){
        .nan_0 = NIM_FALSE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)((NU64)(X60Qx_110 & X60Qx_111)))}
      ;}
    break;
    case 41:
    {
      NU64 X60Qx_112 = u64bits_0_aow2h993l1((&(*a_9)));
      NU64 X60Qx_113 = u64bits_0_aow2h993l1((&(*b_9)));
      r_2 = (xint_0_xinat3x34){
        .nan_0 = NIM_FALSE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)((NU64)(X60Qx_112 | X60Qx_113)))}
      ;}
    break;
    case 42:
    {
      NU64 X60Qx_114 = u64bits_0_aow2h993l1((&(*a_9)));
      NU64 X60Qx_115 = u64bits_0_aow2h993l1((&(*b_9)));
      r_2 = (xint_0_xinat3x34){
        .nan_0 = NIM_FALSE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)((NU64)(X60Qx_114 ^ X60Qx_115)))}
      ;}
    break;
    case 39:
    {
      NI64 X60Qx_116 = asInt_0_valzr1t4f((&(*b_9)));
      NI32 sh_0 = ((NI32)X60Qx_116);
      NB8 X60Qx_117;
      if (64 <= sh_0){
        X60Qx_117 = NIM_TRUE;}
      else {
        X60Qx_117 = (sh_0 < 0);}
      if (X60Qx_117){
        xint_0_xinat3x34 X60Qx_118 = zero_0_xinat3x34();
        r_2 = X60Qx_118;}
      else {
        NU64 X60Qx_119 = u64bits_0_aow2h993l1((&(*a_9)));
        r_2 = (xint_0_xinat3x34){
          .nan_0 = NIM_FALSE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)((NU64)(X60Qx_119 << sh_0)))}
        ;}}
    break;
    case 38:
    {
      NI64 X60Qx_120 = asInt_0_valzr1t4f((&(*b_9)));
      xint_0_xinat3x34 X60Qx_121 = shr_0_xinat3x34(x_4, ((NI32)X60Qx_120));
      r_2 = X60Qx_121;}
    break;
    case 245:
    {
      NI64 X60Qx_122 = asInt_0_valzr1t4f((&(*b_9)));
      NI32 sh_1 = ((NI32)X60Qx_122);
      if (sh_1 <= 0){
        r_2 = x_4;}
      else {
        if (64 <= sh_1){
          xint_0_xinat3x34 X60Qx_1;
          NI64 X60Qx_123 = asInt_0_valzr1t4f((&(*a_9)));
          if (X60Qx_123 < ((NI64)0)){
            xint_0_xinat3x34 X60Qx_124 = createXint_0_xinat3x34(((NI64)-1));
            X60Qx_1 = X60Qx_124;}
          else {
            xint_0_xinat3x34 X60Qx_125 = zero_0_xinat3x34();
            X60Qx_1 = X60Qx_125;}
          r_2 = X60Qx_1;}
        else {
          NI64 av_0 = asInt_0_valzr1t4f((&(*a_9)));
          NI64 p_0 = ((NI64)(((NI64)1) << sh_1));
          NI64 q_1 = ((NI64)(av_0 / p_0));
          NB8 X60Qx_126;
          if (av_0 < ((NI64)0)){
            X60Qx_126 = (!(((NI64)(q_1 * p_0)) == av_0));}
          else {
            X60Qx_126 = NIM_FALSE;}
          if (X60Qx_126){
            dec_1_I2mwrey1_aow2h993l1((&q_1));}
          xint_0_xinat3x34 X60Qx_127 = createXint_0_xinat3x34(q_1);
          r_2 = X60Qx_127;}}}
    break;
    default:
    {
      xint_0_xinat3x34 X60Qx_128 = zero_0_xinat3x34();
      r_2 = X60Qx_128;}
    break;}
  xint_0_xinat3x34 m_1 = mask_0_xinat3x34(r_2, bits_1, signed_1);
  if (signed_1){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_13));
    Value_0_valzr1t4f X60Qx_129 = vIntX_0_valzr1t4f(m_1, bits_1);
    result_13 = X60Qx_129;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_13));
    Value_0_valzr1t4f X60Qx_130 = vUIntX_0_valzr1t4f(m_1, bits_1);
    result_13 = X60Qx_130;}
  return result_13;}
NB8 isBinMagicOp_0_aow2h993l1(NimonyExpr_0_nimry5ra91 ek_0){
  NB8 result_14;
  switch (ek_0){
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 40:
    case 41:
    case 42:
    case 39:
    case 38:
    case 245:
    case 44:
    case 45:
    case 47:
    case 46:
    case 17:
    case 18:
    case 19:
    {
      result_14 = NIM_TRUE;}
    break;
    default:
    {
      result_14 = NIM_FALSE;}
    break;}
  return result_14;}
NB8 isDivByZero_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_3, Value_0_valzr1t4f* a_10, Value_0_valzr1t4f* b_10){
  NB8 result_15;
  NB8 X60Qx_131;
  if ((!(op_3 == 36))){
    X60Qx_131 = (!(op_3 == 37));}
  else {
    X60Qx_131 = NIM_FALSE;}
  if (X60Qx_131){
    return NIM_FALSE;}
  NB8 X60Qx_132;
  if ((*a_10).kind_0 == 3){
    X60Qx_132 = NIM_TRUE;}
  else {
    X60Qx_132 = ((*b_10).kind_0 == 3);}
  if (X60Qx_132){
    return NIM_FALSE;}
  NB8 X60Qx_133;
  if ((!((*b_10).kind_0 == 1))){
    X60Qx_133 = (!((*b_10).kind_0 == 2));}
  else {
    X60Qx_133 = NIM_FALSE;}
  if (X60Qx_133){
    return NIM_FALSE;}
  NU64 X60Qx_134 = u64bits_0_aow2h993l1((&(*b_10)));
  result_15 = (X60Qx_134 == ((NU64)0u));
  return result_15;}
Value_0_valzr1t4f binMagic_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_4, Value_0_valzr1t4f* a_11, Value_0_valzr1t4f* b_11, NI32 bits_2, NB8 signed_2){
  Value_0_valzr1t4f result_16;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
  Value_0_valzr1t4f X60Qx_135 = vNil_0_valzr1t4f();
  result_16 = X60Qx_135;
  switch (op_4){
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    {
      NB8 X60Qx_136;
      if ((*a_11).kind_0 == 3){
        X60Qx_136 = NIM_TRUE;}
      else {
        X60Qx_136 = ((*b_11).kind_0 == 3);}
      if (X60Qx_136){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
        Value_0_valzr1t4f X60Qx_137 = floatArith_0_aow2h993l1(op_4, (&(*a_11)), (&(*b_11)));
        result_16 = X60Qx_137;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
        Value_0_valzr1t4f X60Qx_138 = intArith_0_aow2h993l1(op_4, (&(*a_11)), (&(*b_11)), bits_2, signed_2);
        result_16 = X60Qx_138;}}
    break;
    case 40:
    case 41:
    case 42:
    case 39:
    case 38:
    case 245:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      Value_0_valzr1t4f X60Qx_139 = bitOp_0_aow2h993l1(op_4, (&(*a_11)), (&(*b_11)), bits_2, signed_2);
      result_16 = X60Qx_139;}
    break;
    case 44:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      NB8 X60Qx_140 = cmpEq_0_aow2h993l1((&(*a_11)), (&(*b_11)));
      Value_0_valzr1t4f X60Qx_141 = vBool_0_valzr1t4f(X60Qx_140);
      result_16 = X60Qx_141;}
    break;
    case 45:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      NB8 X60Qx_142 = cmpEq_0_aow2h993l1((&(*a_11)), (&(*b_11)));
      Value_0_valzr1t4f X60Qx_143 = vBool_0_valzr1t4f((!X60Qx_142));
      result_16 = X60Qx_143;}
    break;
    case 47:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      NB8 X60Qx_144 = cmpLt_0_aow2h993l1((&(*a_11)), (&(*b_11)));
      Value_0_valzr1t4f X60Qx_145 = vBool_0_valzr1t4f(X60Qx_144);
      result_16 = X60Qx_145;}
    break;
    case 46:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      NB8 X60Qx_146 = cmpLe_0_aow2h993l1((&(*a_11)), (&(*b_11)));
      Value_0_valzr1t4f X60Qx_147 = vBool_0_valzr1t4f(X60Qx_146);
      result_16 = X60Qx_147;}
    break;
    case 17:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      NB8 X60Qx_148;
      NB8 X60Qx_149 = truthy_0_valzr1t4f((&(*a_11)));
      if (X60Qx_149){
        NB8 X60Qx_150 = truthy_0_valzr1t4f((&(*b_11)));
        X60Qx_148 = X60Qx_150;}
      else {
        X60Qx_148 = NIM_FALSE;}
      Value_0_valzr1t4f X60Qx_151 = vBool_0_valzr1t4f(X60Qx_148);
      result_16 = X60Qx_151;}
    break;
    case 18:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      NB8 X60Qx_152;
      NB8 X60Qx_153 = truthy_0_valzr1t4f((&(*a_11)));
      if (X60Qx_153){
        X60Qx_152 = NIM_TRUE;}
      else {
        NB8 X60Qx_154 = truthy_0_valzr1t4f((&(*b_11)));
        X60Qx_152 = X60Qx_154;}
      Value_0_valzr1t4f X60Qx_155 = vBool_0_valzr1t4f(X60Qx_152);
      result_16 = X60Qx_155;}
    break;
    case 19:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      NB8 X60Qx_156 = truthy_0_valzr1t4f((&(*a_11)));
      NB8 X60Qx_157 = truthy_0_valzr1t4f((&(*b_11)));
      Value_0_valzr1t4f X60Qx_158 = vBool_0_valzr1t4f((!(X60Qx_156 == X60Qx_157)));
      result_16 = X60Qx_158;}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_16));
      Value_0_valzr1t4f X60Qx_159 = vNil_0_valzr1t4f();
      result_16 = X60Qx_159;}
    break;}
  return result_16;}
Value_0_valzr1t4f unMagic_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_5, Value_0_valzr1t4f* a_12, NI32 bits_3, NB8 signed_3){
  Value_0_valzr1t4f result_17;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
  Value_0_valzr1t4f X60Qx_160 = vNil_0_valzr1t4f();
  result_17 = X60Qx_160;
  switch (op_5){
    case 21:
    {
      if ((*a_12).kind_0 == 3){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
        Value_0_valzr1t4f X60Qx_161 = vFloat_0_valzr1t4f(((NF64)-(*a_12).fval_0), (*a_12).fbits_0);
        result_17 = X60Qx_161;}
      else {
        xint_0_xinat3x34 X60Qx_162 = toXint_0_aow2h993l1((&(*a_12)));
        xint_0_xinat3x34 X60Qx_163 = minusQ_0_xinat3x34(X60Qx_162);
        xint_0_xinat3x34 m_2 = mask_0_xinat3x34(X60Qx_163, bits_3, signed_3);
        if (signed_3){
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
          Value_0_valzr1t4f X60Qx_164 = vIntX_0_valzr1t4f(m_2, bits_3);
          result_17 = X60Qx_164;}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
          Value_0_valzr1t4f X60Qx_165 = vUIntX_0_valzr1t4f(m_2, bits_3);
          result_17 = X60Qx_165;}}}
    break;
    case 20:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
      NB8 X60Qx_166 = truthy_0_valzr1t4f((&(*a_12)));
      Value_0_valzr1t4f X60Qx_167 = vBool_0_valzr1t4f((!X60Qx_166));
      result_17 = X60Qx_167;}
    break;
    case 43:
    {
      xint_0_xinat3x34 X60Qx_168 = toXint_0_aow2h993l1((&(*a_12)));
      xint_0_xinat3x34 X60Qx_169 = not_0_xinat3x34(X60Qx_168);
      xint_0_xinat3x34 m_3 = mask_0_xinat3x34(X60Qx_169, bits_3, signed_3);
      if (signed_3){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
        Value_0_valzr1t4f X60Qx_170 = vIntX_0_valzr1t4f(m_3, bits_3);
        result_17 = X60Qx_170;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
        Value_0_valzr1t4f X60Qx_171 = vUIntX_0_valzr1t4f(m_3, bits_3);
        result_17 = X60Qx_171;}}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_17));
      Value_0_valzr1t4f X60Qx_172 = vNil_0_valzr1t4f();
      result_17 = X60Qx_172;}
    break;}
  return result_17;}
NB8 fitsSigned_0_aow2h993l1(NI64 v_3, NI32 bits_4){
  NB8 result_18;
  if (64 <= bits_4){
    return NIM_TRUE;}
  NI64 hi_0 = ((NI64)(((NI64)(((NI64)1) << ((NI32)(bits_4 - 1)))) - ((NI64)1)));
  NI64 lo_0 = ((NI64)-((NI64)(((NI64)1) << ((NI32)(bits_4 - 1)))));
  NB8 X60Qx_173;
  if (lo_0 <= v_3){
    X60Qx_173 = (v_3 <= hi_0);}
  else {
    X60Qx_173 = NIM_FALSE;}
  result_18 = X60Qx_173;
  return result_18;}
NB8 arithOverflows_0_aow2h993l1(NimonyExpr_0_nimry5ra91 op_6, Value_0_valzr1t4f* a_13, Value_0_valzr1t4f* b_12, NI32 bits_5, NB8 signed_4){
  NB8 result_19;
  NB8 X60Qx_2;
  X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_0 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
    .a = {
      6u, 0u, 0u}}
  ;
  NU64 X60Qdesugar_1 = ((NU)(*a_13).kind_0);
  if ((!(((NU8)(X60Qdesugar_0.a[((NU)(X60Qdesugar_1 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_1 & 7u)))))) != 0u))){
    X60Qx_2 = NIM_TRUE;}
  else {
    X60Qt_0_IAarrayAuS8ZS3_aow2h993l1 X60Qdesugar_2 = (X60Qt_0_IAarrayAuS8ZS3_aow2h993l1){
      .a = {
        6u, 0u, 0u}}
    ;
    NU64 X60Qdesugar_3 = ((NU)(*b_12).kind_0);
    X60Qx_2 = (!(((NU8)(X60Qdesugar_2.a[((NU)(X60Qdesugar_3 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_3 & 7u)))))) != 0u));}
  if (X60Qx_2){
    return NIM_FALSE;}
  NI64 x_6 = asInt_0_valzr1t4f((&(*a_13)));
  NI64 y_2 = asInt_0_valzr1t4f((&(*b_12)));
  if (signed_4){
    switch (op_6){
      case 33:
      {
        if (bits_5 < 64){
          NB8 X60Qx_174 = fitsSigned_0_aow2h993l1(((NI64)(x_6 + y_2)), bits_5);
          result_19 = (!X60Qx_174);}
        else {
          NI64 s_0 = ((NI64)((NU64)(((NU64)x_6) + ((NU64)y_2))));
          result_19 = (((NI64)(((NI64)(x_6 ^ s_0)) & ((NI64)(y_2 ^ s_0)))) < ((NI64)0));}}
      break;
      case 34:
      {
        if (bits_5 < 64){
          NB8 X60Qx_175 = fitsSigned_0_aow2h993l1(((NI64)(x_6 - y_2)), bits_5);
          result_19 = (!X60Qx_175);}
        else {
          NI64 s_1 = ((NI64)((NU64)(((NU64)x_6) - ((NU64)y_2))));
          result_19 = (((NI64)(((NI64)(x_6 ^ y_2)) & ((NI64)(x_6 ^ s_1)))) < ((NI64)0));}}
      break;
      case 35:
      {
        NB8 X60Qx_176;
        if (x_6 == ((NI64)0)){
          X60Qx_176 = NIM_TRUE;}
        else {
          X60Qx_176 = (y_2 == ((NI64)0));}
        if (X60Qx_176){
          result_19 = NIM_FALSE;}
        else {
          NI64 p_1 = ((NI64)(x_6 * y_2));
          NB8 X60Qx_177;
          if ((!(((NI64)(p_1 / y_2)) == x_6))){
            X60Qx_177 = NIM_TRUE;}
          else {
            NB8 X60Qx_178 = fitsSigned_0_aow2h993l1(p_1, bits_5);
            X60Qx_177 = (!X60Qx_178);}
          result_19 = X60Qx_177;}}
      break;
      default:
      {
        result_19 = NIM_FALSE;}
      break;}}
  else {
    NU64 ux_0 = ((NU64)x_6);
    NU64 uy_0 = ((NU64)y_2);
    NU64 X60Qx_3;
    if (64 <= bits_5){
      X60Qx_3 = ((NU64)18446744073709551615ull);}
    else {
      X60Qx_3 = ((NU64)(((NU64)(((NU64)1u) << bits_5)) - ((NU64)1)));}
    NU64 widthMax_0 = X60Qx_3;
    switch (op_6){
      case 33:
      {
        result_19 = (((NU64)(widthMax_0 - uy_0)) < ux_0);}
      break;
      case 34:
      {
        result_19 = (ux_0 < uy_0);}
      break;
      case 35:
      {
        NB8 X60Qx_179;
        NB8 X60Qx_180;
        if ((!(ux_0 == ((NU64)0u)))){
          X60Qx_180 = (((NU64)(widthMax_0 / ux_0)) < uy_0);}
        else {
          X60Qx_180 = NIM_FALSE;}
        if (X60Qx_180){
          X60Qx_179 = NIM_TRUE;}
        else {
          X60Qx_179 = (widthMax_0 < ((NU64)(ux_0 * uy_0)));}
        result_19 = X60Qx_179;}
      break;
      default:
      {
        result_19 = NIM_FALSE;}
      break;}}
  return result_19;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void dec_1_I2mwrey1_aow2h993l1(NI64* x_8){
  (*x_8) = ((NI64)((*x_8) - ((NI64)1)));}
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_aow2h993l1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_181 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_181){
      eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_182 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_182){
      eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_aow2h993l1(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_183 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_183){
      eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void X60Qini_0_aow2h993l1(void){
  if (X60QiniGuard_0_aow2h993l1){
    return;}
  X60QiniGuard_0_aow2h993l1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_valzr1t4f();
  X60Qini_0_xinat3x34();
  X60Qini_0_nimry5ra91();}
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
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
