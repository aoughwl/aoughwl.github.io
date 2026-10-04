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
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1 X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1;
typedef struct WireField_0_run8hsnpi WireField_0_run8hsnpi;
typedef struct seq_0_Ift2sne_aow7lb5cq1 seq_0_Ift2sne_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1 X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1;
typedef struct seq_0_I3ump14_aow7lb5cq1 seq_0_I3ump14_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5 X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct seq_0_I50urnw_croph25r5 seq_0_I50urnw_croph25r5;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1 X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct ToplevelEntry_0_prorcx25w1 ToplevelEntry_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct PathGrant_0_iop7yt73v PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v ReadRecord_0_iop7yt73v;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct CSig_0_aow7lb5cq1{
  NB8 ok_0;
  string_0_sysvq0asl ret_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 params_0;}
CSig_0_aow7lb5cq1;
typedef struct seq_0_Irn2j6w_aow7lb5cq1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* data_0;}
seq_0_Irn2j6w_aow7lb5cq1;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct seq_0_Igzebks_aow7lb5cq1{
  NI32 len_0;
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** data_0;}
seq_0_Igzebks_aow7lb5cq1;
typedef struct openArray_0_Iczu4791_aow7lb5cq1{
  WireField_0_run8hsnpi* a_0;
  NI32 len_0;}
openArray_0_Iczu4791_aow7lb5cq1;
typedef struct HSlice_0_Inzqy8d_aow7lb5cq1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_aow7lb5cq1;
typedef struct openArray_0_Ig73pnk_aow7lb5cq1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_aow7lb5cq1;
typedef struct openArray_0_Inqs7yx_aow7lb5cq1{
  NI32* a_0;
  NI32 len_0;}
openArray_0_Inqs7yx_aow7lb5cq1;
typedef struct seq_0_Ik7wkpe_aow7lb5cq1{
  NI32 len_0;
  seq_0_Ift2sne_aow7lb5cq1* data_0;}
seq_0_Ik7wkpe_aow7lb5cq1;
typedef struct seq_0_Iflf8jf1_aow7lb5cq1{
  NI32 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_aow7lb5cq1;
typedef struct openArray_0_In0ukmu_aow7lb5cq1{
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** a_0;
  NI32 len_0;}
openArray_0_In0ukmu_aow7lb5cq1;
typedef struct seq_0_Il8twp61_aow7lb5cq1{
  NI32 len_0;
  WireField_0_run8hsnpi* data_0;}
seq_0_Il8twp61_aow7lb5cq1;
typedef struct seq_0_I3ump14_aow7lb5cq1{
  NI32 len_0;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** data_0;}
seq_0_I3ump14_aow7lb5cq1;
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
typedef NU8 AbiKind_0_layptix6a1;

#define akInt_0_layptix6a1 ((NU8)0)
#define akUInt_0_layptix6a1 ((NU8)1)
#define akFloat_0_layptix6a1 ((NU8)2)
#define akChar_0_layptix6a1 ((NU8)3)
#define akBool_0_layptix6a1 ((NU8)4)
#define akPtr_0_layptix6a1 ((NU8)5)
#define akRef_0_layptix6a1 ((NU8)6)
#define akClosure_0_layptix6a1 ((NU8)7)
#define akEnum_0_layptix6a1 ((NU8)8)
#define akArray_0_layptix6a1 ((NU8)9)
#define akObject_0_layptix6a1 ((NU8)10)
#define akTuple_0_layptix6a1 ((NU8)11)
#define akVariant_0_layptix6a1 ((NU8)12)
#define akDistinct_0_layptix6a1 ((NU8)13)
#define akString_0_layptix6a1 ((NU8)14)
#define akSeq_0_layptix6a1 ((NU8)15)
#define akSet_0_layptix6a1 ((NU8)16)
#define akRange_0_layptix6a1 ((NU8)17)
#define akUnchecked_0_layptix6a1 ((NU8)18)
typedef struct seq_0_Ie088gc_heapjafyf1{
  NI32 len_0;
  seq_0_I3ump14_aow7lb5cq1* data_0;}
seq_0_Ie088gc_heapjafyf1;
typedef struct TypeDesc_Obj_0_layptix6a1{
  AbiKind_0_layptix6a1 kind_0;
  NI32 bits_0;
  NI32 count_0;
  NI32 enumLo_0;
  NI32 enumHi_0;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_0;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* base_0;
  NB8 rtti_0;
  NB8 packed_0;
  NB8 union_0;
  NB8 incomplete_0;
  seq_0_I3ump14_aow7lb5cq1 fields_0;
  seq_0_Ie088gc_heapjafyf1 branches_0;}
TypeDesc_Obj_0_layptix6a1;
typedef struct X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1{
  NI r_00;
  TypeDesc_Obj_0_layptix6a1 d_00;}
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1;
typedef struct WireField_0_run8hsnpi{
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* desc_0;
  string_0_sysvq0asl srcType_0;
  NB8 isEnum_0;
  NB8 isVar_0;
  NB8 isRef_0;
  NB8 isArenaRef_0;
  NB8 isArenaPtr_0;
  NB8 isPtrArena_0;
  NB8 isForeignPtr_0;
  NB8 isSink_0;
  NB8 isPod_0;
  NB8 isComposite_0;
  NB8 isString_0;
  NB8 isSeq_0;
  NB8 isArray_0;
  NI32 arrCount_0;
  NB8 elemVarLen_0;
  string_0_sysvq0asl elemLeafName_0;
  NU32 enumSym_0;
  NU32 typeSym_0;
  NI32 wireSize_0;
  NI32 wireAlign_0;
  string_0_sysvq0asl elemSrcType_0;
  NI32 elemSize_0;
  NI32 elemStride_0;
  NU32 elemTypeSym_0;}
WireField_0_run8hsnpi;
typedef N_CDECL_PTR(NI32,  X60Qt_0_IApointerZAR0ZAiS32ZAiS32ZAcdeclZAfalseZAR32_run8hsnpi)(void*, void*, NI32);
typedef struct ShimEntry_Obj_0_run8hsnpi{
  NU32 sym_0;
  string_0_sysvq0asl base_0;
  string_0_sysvq0asl shimSym_0;
  seq_0_Il8twp61_aow7lb5cq1 args_0;
  seq_0_Ift2sne_aow7lb5cq1 argOffs_0;
  NI32 inSize_0;
  WireField_0_run8hsnpi ret_0;
  NB8 retVoid_0;
  seq_0_Ift2sne_aow7lb5cq1 outVarOffs_0;
  NI32 outSize_0;
  seq_0_Ixdx2fh1_aow7lb5cq1 redeclTypes_0;
  string_0_sysvq0asl redeclProc_0;
  seq_0_Ik7wkpe_aow7lb5cq1 noDerefOffs_0;
  NI32 nCalls_0;
  NI32 nBytesIn_0;
  NI32 nBytesOut_0;
  X60Qt_0_IApointerZAR0ZAiS32ZAiS32ZAcdeclZAfalseZAR32_run8hsnpi fn_0;
  NB8 resolved_0;}
ShimEntry_Obj_0_run8hsnpi;
typedef struct X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1{
  NI r_00;
  ShimEntry_Obj_0_run8hsnpi d_00;}
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1;
typedef N_NIMCALL_PTR(Value_0_valzr1t4f,  X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251ZSstring0sysvq0aslSseq0X4950urnwSX56alue0valzr1t4fAnimcallZAfalseZAR91_croph25r5)(X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5*, string_0_sysvq0asl, seq_0_I50urnw_croph25r5);
typedef NU8 CrossRoute_0_croph25r5;

#define crNone_0_croph25r5 ((NU8)0)
#define crHostNative_0_croph25r5 ((NU8)1)
#define crSyscall_0_croph25r5 ((NU8)2)
#define crHybridNative_0_croph25r5 ((NU8)3)
#define crInterpret_0_croph25r5 ((NU8)4)
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
typedef struct X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1{
  NI r_00;
  XProvider_Obj_0_croph25r5 d_00;}
X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1{
  NI32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1;
typedef struct X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1{
  NI32 a[4];}
X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1;
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
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1{
  ErrorCode_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1{
  NB8 fld_0;
  string_0_sysvq0asl fld_1;
  seq_0_Ixdx2fh1_aow7lb5cq1 fld_2;}
X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct seq_0_I7dew2c_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* data_0;}
seq_0_I7dew2c_prorcx25w1;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_Ij858uv_prorcx25w1{
  seq_0_I7dew2c_prorcx25w1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ij858uv_prorcx25w1;
typedef struct SplittedModulePath_0_symkyk35i1{
  string_0_sysvq0asl dir_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl ext_0;}
SplittedModulePath_0_symkyk35i1;
typedef struct seq_0_Ikxamj_prorcx25w1{
  NI32 len_0;
  ToplevelEntry_0_prorcx25w1* data_0;}
seq_0_Ikxamj_prorcx25w1;
typedef struct seq_0_I8hny96_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax* data_0;}
seq_0_I8hny96_intzsnzax;
typedef struct Table_0_Idzo7511_intzsnzax{
  seq_0_I8hny96_intzsnzax data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Idzo7511_intzsnzax;
typedef struct ToplevelEntries_0_prorcx25w1{
  seq_0_Ikxamj_prorcx25w1 entries_0;
  Table_0_Idzo7511_intzsnzax bySymId_0;}
ToplevelEntries_0_prorcx25w1;
typedef struct Program_0_prorcx25w1{
  Table_0_Ij858uv_prorcx25w1 mods_0;
  SplittedModulePath_0_symkyk35i1 main_0;
  ToplevelEntries_0_prorcx25w1 mem_0;}
Program_0_prorcx25w1;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef NU8 FileMode_0_syn1lfpjv;

#define fmRead_0_syn1lfpjv ((NU8)0)
#define fmWrite_0_syn1lfpjv ((NU8)1)
#define fmReadWrite_0_syn1lfpjv ((NU8)2)
#define fmReadWriteExisting_0_syn1lfpjv ((NU8)3)
#define fmAppend_0_syn1lfpjv ((NU8)4)
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
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
typedef struct seq_0_I50urnw_croph25r5{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_croph25r5;
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
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1{
  string_0_sysvq0asl fld_0;
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef NU8 SemPhase_0_prorcx25w1;

#define SemcheckTopLevelSyms_0_prorcx25w1 ((NU8)0)
#define SemcheckSignaturesInProgress_0_prorcx25w1 ((NU8)1)
#define SemcheckSignatures_0_prorcx25w1 ((NU8)2)
#define SemcheckBodiesInProgress_0_prorcx25w1 ((NU8)3)
#define SemcheckBodies_0_prorcx25w1 ((NU8)4)
typedef struct ToplevelEntry_0_prorcx25w1{
  TokenBuf_0_nifb6mq6y1 buffer_0;
  SemPhase_0_prorcx25w1 phase_0;}
ToplevelEntry_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax{
  NU32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_intzsnzax;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
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
typedef struct MemFile_0_memlzdyby{
  void* mem_0;
  NI32 size_0;
  int handle_0;
  int flags_0;}
MemFile_0_memlzdyby;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1)(VfsBlob_0_vfsc9jn7*);
typedef struct VfsBlob_0_vfsc9jn7{
  void* data_0;
  NI32 size_0;
  MemFile_0_memlzdyby mf_0;
  void* cookie_0;
  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_nif81dubp1 cleanup_0;}
VfsBlob_0_vfsc9jn7;
typedef NU8 NifKind_0_nif81dubp1;

#define UnknownToken_0_nif81dubp1 ((NU8)0)
#define EofToken_0_nif81dubp1 ((NU8)1)
#define DotToken_0_nif81dubp1 ((NU8)2)
#define Ident_0_nif81dubp1 ((NU8)3)
#define Symbol_0_nif81dubp1 ((NU8)4)
#define SymbolDef_0_nif81dubp1 ((NU8)5)
#define StringLit_0_nif81dubp1 ((NU8)6)
#define CharLit_0_nif81dubp1 ((NU8)7)
#define IntLit_0_nif81dubp1 ((NU8)8)
#define UIntLit_0_nif81dubp1 ((NU8)9)
#define FloatLit_0_nif81dubp1 ((NU8)10)
#define ParLe_0_nif81dubp1 ((NU8)11)
#define ParRi_0_nif81dubp1 ((NU8)12)
typedef struct StringView_0_strdllfw2{
  NC8* p_0;
  NI32 len_0;}
StringView_0_strdllfw2;
typedef struct FilePos_0_nif81dubp1{
  NI32 col_0;
  NI32 line_0;}
FilePos_0_nif81dubp1;
typedef struct ExpandedToken_0_nif81dubp1{
  NifKind_0_nif81dubp1 tk_0;
  NU8 flags_0;
  NU16 kind_0;
  StringView_0_strdllfw2 data_0;
  FilePos_0_nif81dubp1 pos_0;
  StringView_0_strdllfw2 filename_0;
  StringView_0_strdllfw2 comment_0;}
ExpandedToken_0_nif81dubp1;
typedef struct Reader_0_nif81dubp1{
  NC8* p_0;
  void* eof_0;
  VfsBlob_0_vfsc9jn7 f_0;
  string_0_sysvq0asl buf_0;
  string_0_sysvq0asl thisModule_0;
  NI32 line_0;
  NI32 indexAt_0;
  ExpandedToken_0_nif81dubp1 unusedNameHint_0;}
Reader_0_nif81dubp1;
typedef struct seq_0_Io4pvgy1_nifb6mq6y1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Io4pvgy1_nifb6mq6y1;
typedef struct Stream_0_nifh7u8pu1{
  Reader_0_nif81dubp1 r_0;
  seq_0_Io4pvgy1_nifb6mq6y1 parents_0;}
Stream_0_nifh7u8pu1;
typedef struct seq_0_Ilvi9zw_intzsnzax{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* data_0;}
seq_0_Ilvi9zw_intzsnzax;
typedef struct seq_0_Imzz798_nifa1znj21{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21* data_0;}
seq_0_Imzz798_nifa1znj21;
typedef struct NifIndex_0_nifa1znj21{
  seq_0_Ilvi9zw_intzsnzax converters_0;
  seq_0_Imzz798_nifa1znj21 exports_0;}
NifIndex_0_nifa1znj21;
typedef struct seq_0_Irkj95k_nifa1znj21{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* data_0;}
seq_0_Irkj95k_nifa1znj21;
typedef struct Table_0_Iyfwn301_nifa1znj21{
  seq_0_Irkj95k_nifa1znj21 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Iyfwn301_nifa1znj21;
typedef struct NifModule_Obj_0_prorcx25w1{
  Stream_0_nifh7u8pu1 stream_0;
  NifIndex_0_nifa1znj21 index_0;
  Table_0_Iyfwn301_nifa1znj21 public_0;
  Table_0_Iyfwn301_nifa1znj21 private_0;}
NifModule_Obj_0_prorcx25w1;
typedef struct X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1{
  NI r_00;
  NifModule_Obj_0_prorcx25w1 d_00;}
X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
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
typedef NU16 NifIndexKind_0_nif12fhfr1;

#define NoIndexTag_0_nif12fhfr1 ((NU16)0)
#define KvIdx_0_nif12fhfr1 ((NU16)30)
#define VvIdx_0_nif12fhfr1 ((NU16)31)
#define GvarIdx_0_nif12fhfr1 ((NU16)54)
#define TvarIdx_0_nif12fhfr1 ((NU16)55)
#define VarIdx_0_nif12fhfr1 ((NU16)56)
#define ConstIdx_0_nif12fhfr1 ((NU16)58)
#define GletIdx_0_nif12fhfr1 ((NU16)60)
#define TletIdx_0_nif12fhfr1 ((NU16)61)
#define LetIdx_0_nif12fhfr1 ((NU16)62)
#define CursorIdx_0_nif12fhfr1 ((NU16)63)
#define ProcIdx_0_nif12fhfr1 ((NU16)70)
#define FuncIdx_0_nif12fhfr1 ((NU16)71)
#define IteratorIdx_0_nif12fhfr1 ((NU16)72)
#define ConverterIdx_0_nif12fhfr1 ((NU16)73)
#define MethodIdx_0_nif12fhfr1 ((NU16)74)
#define MacroIdx_0_nif12fhfr1 ((NU16)75)
#define TemplateIdx_0_nif12fhfr1 ((NU16)76)
#define TypeIdx_0_nif12fhfr1 ((NU16)77)
#define InlineIdx_0_nif12fhfr1 ((NU16)132)
#define ExportIdx_0_nif12fhfr1 ((NU16)153)
#define FromexportIdx_0_nif12fhfr1 ((NU16)154)
#define ExportexceptIdx_0_nif12fhfr1 ((NU16)155)
#define BuildIdx_0_nif12fhfr1 ((NU16)230)
#define IndexIdx_0_nif12fhfr1 ((NU16)302)
#define BundleIdx_0_nif12fhfr1 ((NU16)340)
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21{
  string_0_sysvq0asl fld_0;
  NifIndexKind_0_nif12fhfr1 fld_1;
  seq_0_Izov3yo_ast8ri79k fld_2;}
X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21;
typedef NU8 IndexVisibility_0_nifa1znj21;

#define Hidden_0_nifa1znj21 ((NU8)0)
#define Exported_0_nifa1znj21 ((NU8)1)
typedef struct NifIndexEntry_0_nifa1znj21{
  NI32 offset_0;
  NU32 info_0;
  IndexVisibility_0_nifa1znj21 vis_0;}
NifIndexEntry_0_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21{
  string_0_sysvq0asl fld_0;
  NifIndexEntry_0_nifa1znj21 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21;
NB8 compositeCOk_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_4, NI32 depth_2);
string_0_sysvq0asl compositeWhyNot_1_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_5, NI32 depth_3);
static inline openArray_0_Iczu4791_aow7lb5cq1 toOpenArray_1_I0ef4be1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_29);
static inline NI32 len_3_In63jw61_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_31);
static inline WireField_0_run8hsnpi* getQ_7_Iko57h9_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_32, NI32 i_36);
static inline NI32 len_3_I5m68tr1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_33);
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_7_I45w7c91_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_34, NI32 i_37);
static inline HSlice_0_Inzqy8d_aow7lb5cq1 ___1_Iclcqmw1_aow7lb5cq1(NI32 a_16, NI32 b_3);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline seq_0_Irn2j6w_aow7lb5cq1 newSeqUninit_0_Ifa362m1_aow7lb5cq1(NI32 size_6);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39);
static inline void add_0_I1xop2a1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* s_39, X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 elem_10);
static inline NI32 len_3_Ijhqs0r1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_41);
static inline X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* getQ_7_Irlfbqs1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_42, NI32 i_40);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_43);
static inline openArray_0_Inqs7yx_aow7lb5cq1 toOpenArray_0_Iccbrld_aow7lb5cq1(X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1* x_8);
static inline NB8 contains_3_Ipa7o28_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_21, NI32 elem_11);
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45);
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_42);
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10);
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13);
static inline openArray_0_Inqs7yx_aow7lb5cq1 toOpenArray_1_Ibqb4ob_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_57);
static inline seq_0_Igzebks_aow7lb5cq1 newSeqUninit_0_I6ffb0e1_aow7lb5cq1(NI32 size_16);
static inline NI32 len_3_I44vue3_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_59);
static inline openArray_0_In0ukmu_aow7lb5cq1 toOpenArray_1_Ijdwnsz_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_60);
static inline void add_0_I9iil5u_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* s_62, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* elem_18);
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_aow7lb5cq1(NI32 a_27, NI32 b_4);
static inline WireField_0_run8hsnpi* rawData_0_Ijd497p_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_64);
static inline NI32 len_6_Ier6z6r1_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 a_28);
static inline WireField_0_run8hsnpi* getQ_10_Id2924z_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 x_11, NI32 idx_5);
static inline NI32 memSizeInBytes_0_I5bna9k_aow7lb5cq1(NI32 size_18);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_29);
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
static inline NI32 capInBytes_0_Ikkv2nv1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_66);
NB8 resize_0_I90dq91_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* dest_7, NI32 addedElements_7);
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67);
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_30);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7);
NI32 find_0_Iaugz2s1_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_31, NI32 elem_19);
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20);
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68);
NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8);
static inline NI32 memSizeInBytes_0_I03jys01_aow7lb5cq1(NI32 size_21);
static inline NI32 capInBytes_0_Iri1hlt1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_69);
NB8 resize_0_I9lztdq1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1* dest_9, NI32 addedElements_9);
static inline NI32 memSizeInBytes_0_Ih4q01h_aow7lb5cq1(NI32 size_22);
static inline NI32 capInBytes_0_In1m6ni_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_70);
NB8 resize_0_I2yw78g1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* dest_10, NI32 addedElements_10);
static inline NI32* rawData_0_Ic25u3r_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_71);
static inline NI32 len_6_I9632ti1_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_32);
static inline NI32* getQ_10_I053icq_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 x_14, NI32 idx_8);
static inline NI32 memSizeInBytes_0_I21ctpp_aow7lb5cq1(NI32 size_23);
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** rawData_0_Izez9p81_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_72);
static inline NI32 len_6_Iu1dtri1_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 a_33);
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** getQ_10_I6a58n11_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 x_15, NI32 idx_9);
static inline NI32 capInBytes_0_Iekd9qh_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_73);
NB8 resize_0_Ifgwwnv_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* dest_11, NI32 addedElements_11);
void eQdestroy_1_Iem8q971_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_90);
static inline void eQwasMoved_1_I3l7wpx1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* s_91);
void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
seq_0_Ixdx2fh1_aow7lb5cq1 eQdup_1_Imq0s4c_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 a_43);
void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
void eQdestroy_1_Iytr7x_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_96);
static inline void eQwasMoved_1_Idjbhcw1_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* s_97);
static inline NI32 memSizeInBytes_0_Io786y61_aow7lb5cq1(NI32 size_29);
static inline NI32 memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(NI32 size_31);
void eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(CSig_0_aow7lb5cq1 dest_0);
void eQwasmovedQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(CSig_0_aow7lb5cq1* dest_0);
void eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0);
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* src_0);
void eQwasmovedQ_AtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_0_aow7lb5cq1(X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1* dest_0);
void eQdestroyQ_AtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_0_aow7lb5cq1(X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1 dest_0);
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* src_0);
void eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_aow7lb5cq1(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 dest_0);
void eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sizeAlign_1_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_3, NI32 ptrSize_2);
static inline NI32 align_0_layptix6a1(NI32 address_0, NI32 alignment_0);
extern string_0_sysvq0asl abiKindName_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_2);
extern WireField_0_run8hsnpi eQdupQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi(WireField_0_run8hsnpi* src_0);
extern void eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi(WireField_0_run8hsnpi* dest_0);
extern string_0_sysvq0asl getEnv_0_envto7w6l1(string_0_sysvq0asl key_1, string_0_sysvq0asl default_0);
extern string_0_sysvq0asl getHomeDir_0_osalirkw71(void);
static inline string_0_sysvq0asl slashQ_0_ospaexnw61(string_0_sysvq0asl head_1, string_0_sysvq0asl tail_2);
extern string_0_sysvq0asl extractFilename_0_ospaexnw61(string_0_sysvq0asl path_12);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 readFile_0_syn1lfpjv(string_0_sysvq0asl filename_4);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
extern ErrorCode_0_sysvq0asl writeFile_0_syn1lfpjv(string_0_sysvq0asl filename_5, string_0_sysvq0asl content_0);
extern NB8 open_0_syn1lfpjv(FILE** f_22, string_0_sysvq0asl filename_1, FileMode_0_syn1lfpjv mode_2, NI32 bufSize_0);
extern NB8 readLine_0_syn1lfpjv(FILE* f_26, string_0_sysvq0asl* s_3);
extern string_0_sysvq0asl quoteShell_0_oswd7dmm(string_0_sysvq0asl s_2);
extern NI32 execShellCmd_0_oswd7dmm(string_0_sysvq0asl command_0);
extern string_0_sysvq0asl shMkdirP_0_hos14g919(string_0_sysvq0asl d_0);
extern string_0_sysvq0asl shListInto_0_hos14g919(string_0_sysvq0asl pattern_0, string_0_sysvq0asl outFile_0);
extern string_0_sysvq0asl shRmF_0_hos14g919(string_0_sysvq0asl f_0);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern Program_0_prorcx25w1 prog_0_prorcx25w1;
extern string_0_sysvq0asl parentDir_0_ospaexnw61(string_0_sysvq0asl path_6);
extern void setupProgramForTesting_0_prorcx25w1(string_0_sysvq0asl dir_0, string_0_sysvq0asl file_0, string_0_sysvq0asl ext_0);
extern TokenBuf_0_nifb6mq6y1 parseFromFile_0_nifb6mq6y1(string_0_sysvq0asl filename_1, NI32 sizeHint_1);
extern Cursor_0_nifb6mq6y1 beginRead_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_4);
extern string_0_sysvq0asl emitModuleBody_0_emi78vuj01(Cursor_0_nifb6mq6y1* root_1);
static inline void endRead_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_5);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3);
extern string_0_sysvq0asl aowlcSymName_0_run8hsnpi(NU32 sym_7);
extern NB8 fileExists_0_osc4bsu0d1(string_0_sysvq0asl filename_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void eQdestroyQ_SX54ypeX44escX4fbj0layptix6a1_0_layptix6a1(TypeDesc_Obj_0_layptix6a1* dest_0);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void eQdestroyQ_SX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(ShimEntry_Obj_0_run8hsnpi* dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_envto7w6l1(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_aowqg5vb41(void);
extern void X60Qini_0_layptix6a1(void);
extern void X60Qini_0_heapjafyf1(void);
extern void X60Qini_0_marbdjk4t1(void);
extern void X60Qini_0_run8hsnpi(void);
extern void X60Qini_0_croph25r5(void);
extern void X60Qini_0_buiyylk1h1(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_hos14g919(void);
extern void X60Qini_0_emi78vuj01(void);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
extern LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l;
extern string_0_sysvq0asl joinPath_0_ospaexnw61(string_0_sysvq0asl head_0, string_0_sysvq0asl tail_1);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I4511345809429878981_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "string"}
;
LongString_0_sysvq0asl const strlit_0_I14729875263638323136_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq[var-length elem]"}
;
LongString_0_sysvq0asl const strlit_0_I1177603226064417776_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "array"}
;
LongString_0_sysvq0asl const strlit_0_I1511321639927761117_aow7lb5cq1 = {
  .fullLen_0 = 76, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ptr T by arena address \342\200\224 crosses on the nimony-shim route, not this C tier"}
;
LongString_0_sysvq0asl const strlit_0_I8953619849411242452_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arena-ptr aggregate"}
;
LongString_0_sysvq0asl const strlit_0_I4979221678562578996_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ref (arena)"}
;
LongString_0_sysvq0asl const strlit_0_I1700559883491695059_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "object/tuple"}
;
LongString_0_sysvq0asl const strlit_0_I10462096440466995513_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "enum"}
;
LongString_0_sysvq0asl const strlit_0_I11155032387348830029_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "void"}
;
LongString_0_sysvq0asl const strlit_0_I11643015150811461308_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "float"}
;
LongString_0_sysvq0asl const strlit_0_I18357185398770638485_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "uint"}
;
LongString_0_sysvq0asl const strlit_0_I11024699549390617459_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bool"}
;
LongString_0_sysvq0asl const strlit_0_I3703322799828345117_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "char"}
;
LongString_0_sysvq0asl const strlit_0_I7876088876044165226_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "other"}
;
LongString_0_sysvq0asl const strlit_0_I4094444552473946043_aow7lb5cq1 = {
  .fullLen_0 = 44, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "compositeCOk refused it but compositeWhyNot "}
;
LongString_0_sysvq0asl const strlit_0_I11608426675167768974_aow7lb5cq1 = {
  .fullLen_0 = 39, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "found no field - the two walks disagree"}
;
LongString_0_sysvq0asl const strlit_0_I8911147075483498441_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "composite "}
;
LongString_0_sysvq0asl const strlit_0_I8367327255669636523_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var "}
;
LongString_0_sysvq0asl const strlit_0_I6387641605083911873_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sink "}
;
LongString_0_sysvq0asl const strlit_0_I6242563128709086705_aow7lb5cq1 = {
  .fullLen_0 = 51, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 consumed by the callee, the shim cannot own it"}
;
LongString_0_sysvq0asl const strlit_0_I7560857284068051366_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " (wire "}
;
LongString_0_sysvq0asl const strlit_0_I16091381376142210228_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "no signature"}
;
LongString_0_sysvq0asl const strlit_0_I15817754588380596987_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "return: "}
;
LongString_0_sysvq0asl const strlit_0_I3789116743795128948_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typedef struct "}
;
LongString_0_sysvq0asl const strlit_0_I16904210374251152424_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "data_0"}
;
LongString_0_sysvq0asl const strlit_0_I2513678243287852030_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_jit_rd"}
;
LongString_0_sysvq0asl const strlit_0_I10597374192599734484_aow7lb5cq1 = {
  .fullLen_0 = 771, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\012/* ---- aowli JIT shims (uniform flat-buffer ABI) --------------------------- */\012#include <stdlib.h>\012#include <string.h>\012/* Byte-loop reads/writes: args are tight-packed and may be unaligned. */\012static long long aowli_jit_rd(const unsigned char* p, int off, int n) {\012  unsigned long long v = 0; int i;\012  for (i = 0; i < n; i++) v |= ((unsigned long long)p[off + i]) << (8 * i);\012  /* sign-extend so a negative int32/int16/int8 arrives as a negative long long */\012  if (n < 8) {\012    unsigned long long sign = 1ULL << (8 * n - 1);\012    if (v & sign) v |= ~((1ULL << (8 * n)) - 1ULL);\012  }\012  return (long long)v;\012}\012static void aowli_jit_wr(unsigned char* p, int off, int n, long long v) {\012  int i; for (i = 0; i < n; i++) p[off + i] = (unsigned char)((v >> (8 * i)) & 0xff);\012}\012"}
;
LongString_0_sysvq0asl const strlit_0_I7463840659243061209_aow7lb5cq1 = {
  .fullLen_0 = 1350, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\012/* ---- aowli JIT string marshaling ---------------------------------------- */\012/* The WHOLE 16-byte struct is the inline buffer: byte 0 is the length and bytes\012   1.. are the data, so `more_0` holds CHARACTERS for a medium string and is not\012   a discriminator. A length byte above the inline maximum cannot be an inline\012   length, so that is the \"payload lives in more_0\" marker (the compiler emits\012   254 for a literal and 255 for a heap string). Reading `more_0` as a pointer\012   whenever it was non-zero is what segfaulted on the first COMPUTED 8-byte\012   string: \"<medium>\" stores \'>\' (0x3e) there.\012\012   AND THE MAXIMUM IS 14, NOT 15, however much room the struct looks like it\012   has. `stringimpl.nim` sets `PayloadSize = (sizeof(uint) - 1) + sizeof(ptr) -\012   1` = 14 and `len()` reads `more.fullLen` for ANY length byte ABOVE that - so\012   a 15-byte string written inline here is read back by the runtime as a heap\012   string whose `more` pointer is its own last eight characters. It dereferences\012   them. Measured: `aoughwl.settings` crossing `stateKey(s: Setting)`, whose\012   `key` is \"airAcceleration\" - fifteen letters - segfaulted inside the shimmed\012   proc on the first call. Nothing of 0..14 or of 16-and-up was ever wrong,\012   which is why this survived: it is one length. */\012#define AOWLI_JIT_INLINE_MAX 14\012\012static long long aowli_jit_slen("}
;
LongString_0_sysvq0asl const strlit_0_I1876279935150955625_aow7lb5cq1 = {
  .fullLen_0 = 204, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "* s) {\012  unsigned char tag = (unsigned char)(s->bytes_0 & 0xffull);\012  if (tag > AOWLI_JIT_INLINE_MAX) return (long long)s->more_0->fullLen_0;\012  return (long long)tag;\012}\012static const char* aowli_jit_sdata("}
;
LongString_0_sysvq0asl const strlit_0_I15783140816581038667_aow7lb5cq1 = {
  .fullLen_0 = 402, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "* s) {\012  unsigned char tag = (unsigned char)(s->bytes_0 & 0xffull);\012  if (tag > AOWLI_JIT_INLINE_MAX) return (const char*)s->more_0->data_0;\012  return ((const char*)s) + 1;          /* byte 0 is the length */\012}\012/* Build a string from raw bytes. Up to AOWLI_JIT_INLINE_MAX is pure inline: no\012   allocation, so no ownership question at all. Longer goes through the\012   runtime\'s own constructor. */\012static "}
;
LongString_0_sysvq0asl const strlit_0_I2723993762017903615_aow7lb5cq1 = {
  .fullLen_0 = 94, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " aowli_jit_smake(const unsigned char* p, long long n,\012                                        "}
;
LongString_0_sysvq0asl const strlit_0_I3721006562773567258_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "** own) {\012  "}
;
LongString_0_sysvq0asl const strlit_0_I9356103350728131647_aow7lb5cq1 = {
  .fullLen_0 = 214, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " s;\012  memset(&s, 0, sizeof(s));\012  *own = 0;\012  if (n <= AOWLI_JIT_INLINE_MAX) {\012    ((unsigned char*)&s)[0] = (unsigned char)n;\012    if (n > 0) memcpy(((unsigned char*)&s) + 1, p, (size_t)n);\012    return s;\012  }\012  s = "}
;
LongString_0_sysvq0asl const strlit_0_I12087480461722773288_aow7lb5cq1 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "((char*)p, (long long)n);\012  return s;\012}\012"}
;
LongString_0_sysvq0asl const strlit_0_I988991057058608115_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nil type"}
;
LongString_0_sysvq0asl const strlit_0_I324375890710632441_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nested deeper than 6"}
;
LongString_0_sysvq0asl const strlit_0_I10406916229603502364_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-byte scalar"}
;
LongString_0_sysvq0asl const strlit_0_I10718771205828439240_aow7lb5cq1 = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "a seq with no element type"}
;
LongString_0_sysvq0asl const strlit_0_I15127899386611443455_aow7lb5cq1 = {
  .fullLen_0 = 36, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "a seq whose element is padded (size "}
;
LongString_0_sysvq0asl const strlit_0_I12873789045226272086_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", align "}
;
LongString_0_sysvq0asl const strlit_0_I3693825722426563353_aow7lb5cq1 = {
  .fullLen_0 = 42, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "): the wire is packed and the block is not"}
;
LongString_0_sysvq0asl const strlit_0_I2553287064141771090_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "a seq of "}
;
LongString_0_sysvq0asl const strlit_0_I9648376121717153253_aow7lb5cq1 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "an array with no element type"}
;
LongString_0_sysvq0asl const strlit_0_I9905848785981538384_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "an array of no elements"}
;
LongString_0_sysvq0asl const strlit_0_I10012566867423011324_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "an array of "}
;
LongString_0_sysvq0asl const strlit_0_I1157300079854504653_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "an {.incompleteStruct.}"}
;
LongString_0_sysvq0asl const strlit_0_I7806974970349732576_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "a {.union.}"}
;
LongString_0_sysvq0asl const strlit_0_I4687979134801646472_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  memcpy(&"}
;
LongString_0_sysvq0asl const strlit_0_I15444428613251533457_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", in_ + ipos_, "}
;
LongString_0_sysvq0asl const strlit_0_I9864864561646881256_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  ipos_ += "}
;
LongString_0_sysvq0asl const strlit_0_I8924957223949144062_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  { long long i"}
;
LongString_0_sysvq0asl const strlit_0_I1258558027167527550_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I15674259086726680393_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    for (; i"}
;
LongString_0_sysvq0asl const strlit_0_I5544640060524604054_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "; ++i"}
;
LongString_0_sysvq0asl const strlit_0_I17846080716529448640_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") {\012"}
;
LongString_0_sysvq0asl const strlit_0_I3568409834490710820_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      long long m"}
;
LongString_0_sysvq0asl const strlit_0_I13615089990240707056_aow7lb5cq1 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = aowli_jit_rd(in_, (int)ipos_, 8);\012"}
;
LongString_0_sysvq0asl const strlit_0_I2130325736493385980_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      "}
;
LongString_0_sysvq0asl const strlit_0_I15437739651001969444_aow7lb5cq1 = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "] = aowli_jit_smake(in_ + ipos_ + 8, m"}
;
LongString_0_sysvq0asl const strlit_0_I1161825924217342649_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", &o"}
;
LongString_0_sysvq0asl const strlit_0_I2839767760384294121_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      ipos_ += 8 + m"}
;
LongString_0_sysvq0asl const strlit_0_I15342668115246402447_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    } }\012"}
;
LongString_0_sysvq0asl const strlit_0_I10518045726280400131_aow7lb5cq1 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  _Static_assert(sizeof("}
;
LongString_0_sysvq0asl const strlit_0_I1775559386484707154_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") == "}
;
LongString_0_sysvq0asl const strlit_0_I4129744452504341063_aow7lb5cq1 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", \"array size disagrees with aowlabi\");\012"}
;
LongString_0_sysvq0asl const strlit_0_I7486184284809924372_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  memcpy((void*)"}
;
LongString_0_sysvq0asl const strlit_0_I9161878147184120533_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "); ipos_ += "}
;
LongString_0_sysvq0asl const strlit_0_I13870529507240259253_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  { long long n"}
;
LongString_0_sysvq0asl const strlit_0_I1003006025800451514_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    "}
;
LongString_0_sysvq0asl const strlit_0_I9396282401636018722_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "* own"}
;
LongString_0_sysvq0asl const strlit_0_I459476928402638487_aow7lb5cq1 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = aowli_jit_smake(in_ + ipos_ + 8, n"}
;
LongString_0_sysvq0asl const strlit_0_I1259136645670664990_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", &own"}
;
LongString_0_sysvq0asl const strlit_0_I14393988487556796913_aow7lb5cq1 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    ipos_ += 8 + n"}
;
LongString_0_sysvq0asl const strlit_0_I15334082442820835739_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "; }\012"}
;
LongString_0_sysvq0asl const strlit_0_I782490999618302521_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    ipos_ += 8;\012"}
;
LongString_0_sysvq0asl const strlit_0_I5104109714558201510_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    memset(&"}
;
LongString_0_sysvq0asl const strlit_0_I6252714416873801350_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", 0, sizeof("}
;
LongString_0_sysvq0asl const strlit_0_I12127742131857817540_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "));\012"}
;
LongString_0_sysvq0asl const strlit_0_I14627952699985668048_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".len_0 = n"}
;
LongString_0_sysvq0asl const strlit_0_I2789430258783990977_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    if (n"}
;
LongString_0_sysvq0asl const strlit_0_I13666278637935594890_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " > 0) "}
;
LongString_0_sysvq0asl const strlit_0_I6999826655792960192_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0 = "}
;
LongString_0_sysvq0asl const strlit_0_I5702167724897352728_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "((long long)(n"}
;
LongString_0_sysvq0asl const strlit_0_I696246876201023085_aow7lb5cq1 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " * (long long)sizeof(*"}
;
LongString_0_sysvq0asl const strlit_0_I6286326072955259077_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0)));\012"}
;
LongString_0_sysvq0asl const strlit_0_I18385251057949070634_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    { long long i"}
;
LongString_0_sysvq0asl const strlit_0_I17852924351155597464_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      for (; i"}
;
LongString_0_sysvq0asl const strlit_0_I11739835173426611508_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " < n"}
;
LongString_0_sysvq0asl const strlit_0_I5809312286091816554_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        long long m"}
;
LongString_0_sysvq0asl const strlit_0_I5288086118845442921_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        "}
;
LongString_0_sysvq0asl const strlit_0_I10208913608960500894_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0[i"}
;
LongString_0_sysvq0asl const strlit_0_I2640784052786307265_aow7lb5cq1 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        ipos_ += 8 + m"}
;
LongString_0_sysvq0asl const strlit_0_I7306224084071035336_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      } } }\012"}
;
LongString_0_sysvq0asl const strlit_0_I15158283226406648984_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if ("}
;
LongString_0_sysvq0asl const strlit_0_I3060741871306050012_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0) "}
;
LongString_0_sysvq0asl const strlit_0_I740199077749326402_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "((void*)"}
;
LongString_0_sysvq0asl const strlit_0_I6703734619365257310_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0);\012"}
;
LongString_0_sysvq0asl const strlit_0_I7944783884798134160_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " > 0) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I10073469962794762804_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      memset((void*)"}
;
LongString_0_sysvq0asl const strlit_0_I6519573624018950997_aow7lb5cq1 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0, 0, (size_t)(n"}
;
LongString_0_sysvq0asl const strlit_0_I13453311567032255224_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    }\012"}
;
LongString_0_sysvq0asl const strlit_0_I6325254588340587598_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".len_0; ++i"}
;
LongString_0_sysvq0asl const strlit_0_I16570386306475740535_aow7lb5cq1 = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    _Static_assert(sizeof(*"}
;
LongString_0_sysvq0asl const strlit_0_I17215664847085503029_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0) == "}
;
LongString_0_sysvq0asl const strlit_0_I11947772824232299275_aow7lb5cq1 = {
  .fullLen_0 = 48, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", \"seq element stride disagrees with aowlabi\");\012"}
;
LongString_0_sysvq0asl const strlit_0_I12628527270567457706_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      memcpy((void*)"}
;
LongString_0_sysvq0asl const strlit_0_I14428153832606577816_aow7lb5cq1 = {
  .fullLen_0 = 36, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0, in_ + ipos_ + 8, (size_t)(n"}
;
LongString_0_sysvq0asl const strlit_0_I12852333444401487702_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  memcpy(ob_ + opos_, &"}
;
LongString_0_sysvq0asl const strlit_0_I10044955599202107917_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "); opos_ += "}
;
LongString_0_sysvq0asl const strlit_0_I10389080895709581217_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = aowli_jit_slen(&"}
;
LongString_0_sysvq0asl const strlit_0_I6955924969188267900_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "]);\012"}
;
LongString_0_sysvq0asl const strlit_0_I5460632544853264193_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      const char* q"}
;
LongString_0_sysvq0asl const strlit_0_I2252829356077611598_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = aowli_jit_sdata(&"}
;
LongString_0_sysvq0asl const strlit_0_I3320250923810778188_aow7lb5cq1 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      aowli_jit_wr(ob_, (int)opos_, 8, m"}
;
LongString_0_sysvq0asl const strlit_0_I18148928282892619203_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "); opos_ += 8;\012"}
;
LongString_0_sysvq0asl const strlit_0_I11728457182134346010_aow7lb5cq1 = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      memcpy(ob_ + opos_, q"}
;
LongString_0_sysvq0asl const strlit_0_I5572117052193497108_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", (size_t)m"}
;
LongString_0_sysvq0asl const strlit_0_I4896779559304927306_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "); opos_ += m"}
;
LongString_0_sysvq0asl const strlit_0_I11758806364787972807_aow7lb5cq1 = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  memcpy(ob_ + opos_, (const void*)"}
;
LongString_0_sysvq0asl const strlit_0_I18035457312318603665_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    const char* p"}
;
LongString_0_sysvq0asl const strlit_0_I592807425861797845_aow7lb5cq1 = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    aowli_jit_wr(ob_, (int)opos_, 8, n"}
;
LongString_0_sysvq0asl const strlit_0_I5713563946092690572_aow7lb5cq1 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    memcpy(ob_ + opos_, p"}
;
LongString_0_sysvq0asl const strlit_0_I18233374301631325590_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", (size_t)n"}
;
LongString_0_sysvq0asl const strlit_0_I3705825639434928729_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "); opos_ += n"}
;
LongString_0_sysvq0asl const strlit_0_I7627703610005382710_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".len_0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I12283458923584918919_aow7lb5cq1 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        const char* q"}
;
LongString_0_sysvq0asl const strlit_0_I4141503729763329410_aow7lb5cq1 = {
  .fullLen_0 = 42, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        aowli_jit_wr(ob_, (int)opos_, 8, m"}
;
LongString_0_sysvq0asl const strlit_0_I17936778126182439409_aow7lb5cq1 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        memcpy(ob_ + opos_, q"}
;
LongString_0_sysvq0asl const strlit_0_I16820758988003013266_aow7lb5cq1 = {
  .fullLen_0 = 39, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " > 0) memcpy(ob_ + opos_, (const void*)"}
;
LongString_0_sysvq0asl const strlit_0_I8608436586241119281_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0, (size_t)(n"}
;
LongString_0_sysvq0asl const strlit_0_I5027967502149894354_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    opos_ += n"}
;
LongString_0_sysvq0asl const strlit_0_I6738090623860882514_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  opos_ += "}
;
LongString_0_sysvq0asl const strlit_0_I15442873908045290837_aow7lb5cq1 = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      opos_ += 8 + aowli_jit_slen(&"}
;
LongString_0_sysvq0asl const strlit_0_I17529382521941393548_aow7lb5cq1 = {
  .fullLen_0 = 31, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  opos_ += 8 + aowli_jit_slen(&"}
;
LongString_0_sysvq0asl const strlit_0_I15937128883579799196_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".len_0; opos_ += 8;\012"}
;
LongString_0_sysvq0asl const strlit_0_I8021182774357012906_aow7lb5cq1 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        opos_ += 8 + aowli_jit_slen(&"}
;
LongString_0_sysvq0asl const strlit_0_I12898632421854814588_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  opos_ += 8;\012"}
;
LongString_0_sysvq0asl const strlit_0_I10813034127713670746_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  opos_ += 8 + "}
;
LongString_0_sysvq0asl const strlit_0_I17741661924343507191_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".len_0 * "}
;
LongString_0_sysvq0asl const strlit_0_I16883230891360796278_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  static "}
;
LongString_0_sysvq0asl const strlit_0_I5733847686152760297_aow7lb5cq1 = {
  .fullLen_0 = 47, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " aowli_stash_r; static int aowli_stash_ok = 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I10110734980645466271_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " r_;\012"}
;
LongString_0_sysvq0asl const strlit_0_I3029774243415831428_aow7lb5cq1 = {
  .fullLen_0 = 66, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if (aowli_stash_ok) { r_ = aowli_stash_r; aowli_stash_ok = 0; }\012"}
;
LongString_0_sysvq0asl const strlit_0_I9923484708672022736_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  else r_ = "}
;
LongString_0_sysvq0asl const strlit_0_I9877049113831429732_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "int "}
;
LongString_0_sysvq0asl const strlit_0_I1708222581923651341_aow7lb5cq1 = {
  .fullLen_0 = 48, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(const void* inbuf, void* outbuf, int outcap) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I10178897100901084906_aow7lb5cq1 = {
  .fullLen_0 = 58, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  const unsigned char* in_ = (const unsigned char*)inbuf;\012"}
;
LongString_0_sysvq0asl const strlit_0_I4393801761698446017_aow7lb5cq1 = {
  .fullLen_0 = 48, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  unsigned char* out_ = (unsigned char*)outbuf;\012"}
;
LongString_0_sysvq0asl const strlit_0_I7946228770895663279_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  long long ipos_ = 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I7750355290083529673_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  memset(&"}
;
LongString_0_sysvq0asl const strlit_0_I14735887367309579420_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  long long n"}
;
LongString_0_sysvq0asl const strlit_0_I4281043891304848808_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  ipos_ += 8 + n"}
;
LongString_0_sysvq0asl const strlit_0_I6378395016434652565_aow7lb5cq1 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  _Static_assert(sizeof(*"}
;
LongString_0_sysvq0asl const strlit_0_I11268796792645648849_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if (n"}
;
LongString_0_sysvq0asl const strlit_0_I89544630611547045_aow7lb5cq1 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    memcpy((void*)"}
;
LongString_0_sysvq0asl const strlit_0_I7701159626300919437_aow7lb5cq1 = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0, in_ + ipos_ + 8, "}
;
LongString_0_sysvq0asl const strlit_0_I16305850586936607483_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(size_t)(n"}
;
LongString_0_sysvq0asl const strlit_0_I6468377022308900005_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  }\012"}
;
LongString_0_sysvq0asl const strlit_0_I17122198299299987856_aow7lb5cq1 = {
  .fullLen_0 = 44, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", \"aggregate size disagrees with aowlabi\");\012"}
;
LongString_0_sysvq0asl const strlit_0_I7306618916803007629_aow7lb5cq1 = {
  .fullLen_0 = 41, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", \"float width disagrees with aowlabi\");\012"}
;
LongString_0_sysvq0asl const strlit_0_I17558875563685861326_aow7lb5cq1 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  { unsigned long long b"}
;
LongString_0_sysvq0asl const strlit_0_I6387934463080488581_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = (unsigned long long)"}
;
LongString_0_sysvq0asl const strlit_0_I15883747490575809941_aow7lb5cq1 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_jit_rd(in_, (int)ipos_, "}
;
LongString_0_sysvq0asl const strlit_0_I18167370821491564789_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    memcpy(&"}
;
LongString_0_sysvq0asl const strlit_0_I15101036524968472333_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", &b"}
;
LongString_0_sysvq0asl const strlit_0_I17415683837379957581_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "); }\012"}
;
LongString_0_sysvq0asl const strlit_0_I18160002208581309871_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = ("}
;
LongString_0_sysvq0asl const strlit_0_I7038441574186707900_aow7lb5cq1 = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ")aowli_jit_rd(in_, (int)ipos_, 4);\012"}
;
LongString_0_sysvq0asl const strlit_0_I2765646999664450274_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  ipos_ += 4;\012"}
;
LongString_0_sysvq0asl const strlit_0_I16666830705696825015_aow7lb5cq1 = {
  .fullLen_0 = 44, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", \"var-param size disagrees with aowlabi\");\012"}
;
LongString_0_sysvq0asl const strlit_0_I17822294574896570456_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  memcpy(out_ + "}
;
LongString_0_sysvq0asl const strlit_0_I8046607679966277039_aow7lb5cq1 = {
  .fullLen_0 = 31, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ")aowli_jit_rd(in_, (int)ipos_, "}
;
LongString_0_sysvq0asl const strlit_0_I13766595355654876791_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  (void)out_;\012"}
;
LongString_0_sysvq0asl const strlit_0_I10937820481528361631_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if (outcap < "}
;
LongString_0_sysvq0asl const strlit_0_I9204300727068638698_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") return "}
;
LongString_0_sysvq0asl const strlit_0_I10167060501195745097_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  return "}
;
LongString_0_sysvq0asl const strlit_0_I17934854375404503520_aow7lb5cq1 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  { long long opos_ = 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I12313396470659978363_aow7lb5cq1 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    { int need = (int)opos_;\012"}
;
LongString_0_sysvq0asl const strlit_0_I10672841733508358863_aow7lb5cq1 = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      if (outcap < need) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I4024411879076867166_aow7lb5cq1 = {
  .fullLen_0 = 48, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        aowli_stash_r = r_; aowli_stash_ok = 1;\012"}
;
LongString_0_sysvq0asl const strlit_0_I4649953770147481749_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        return need; }\012"}
;
LongString_0_sysvq0asl const strlit_0_I5487312882993115281_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      opos_ = 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I10166787625402032659_aow7lb5cq1 = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      { unsigned char* ob_ = out_;\012"}
;
LongString_0_sysvq0asl const strlit_0_I13914791540775111549_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      }\012"}
;
LongString_0_sysvq0asl const strlit_0_I6654729803687239304_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      return need; } }\012"}
;
LongString_0_sysvq0asl const strlit_0_I12522613173660839319_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  {\012"}
;
LongString_0_sysvq0asl const strlit_0_I3911820715027972186_aow7lb5cq1 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    long long rn = aowli_jit_slen(&r_);\012"}
;
LongString_0_sysvq0asl const strlit_0_I790167309358444658_aow7lb5cq1 = {
  .fullLen_0 = 43, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    const char* rp = aowli_jit_sdata(&r_);\012"}
;
LongString_0_sysvq0asl const strlit_0_I5310786661721115423_aow7lb5cq1 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    int need = (int)(8 + rn);\012"}
;
LongString_0_sysvq0asl const strlit_0_I8269886702836948419_aow7lb5cq1 = {
  .fullLen_0 = 79, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    if (outcap < need) { aowli_stash_r = r_; aowli_stash_ok = 1; return need; }"}
;
LongString_0_sysvq0asl const strlit_0_I14081904980903256320_aow7lb5cq1 = {
  .fullLen_0 = 54, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "   /* aowli retries bigger: keep r_, do not re-run */\012"}
;
LongString_0_sysvq0asl const strlit_0_I11068729316509706393_aow7lb5cq1 = {
  .fullLen_0 = 34, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    aowli_jit_wr(out_, 0, 8, rn);\012"}
;
LongString_0_sysvq0asl const strlit_0_I9486276691579103789_aow7lb5cq1 = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    memcpy(out_ + 8, rp, (size_t)rn);\012"}
;
LongString_0_sysvq0asl const strlit_0_I1654792515589026066_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    return need;\012"}
;
LongString_0_sysvq0asl const strlit_0_I4970679303273918317_aow7lb5cq1 = {
  .fullLen_0 = 39, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  _Static_assert(sizeof(*r_.data_0) == "}
;
LongString_0_sysvq0asl const strlit_0_I11224338710434874543_aow7lb5cq1 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    long long rn = r_.len_0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I16703820542586360166_aow7lb5cq1 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    int need = (int)(8 + rn * "}
;
LongString_0_sysvq0asl const strlit_0_I31630099792905633_aow7lb5cq1 = {
  .fullLen_0 = 80, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    if (outcap < need) { aowli_stash_r = r_; aowli_stash_ok = 1; return need; }\012"}
;
LongString_0_sysvq0asl const strlit_0_I15275851150300379331_aow7lb5cq1 = {
  .fullLen_0 = 57, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    if (rn > 0) memcpy(out_ + 8, (const void*)r_.data_0, "}
;
LongString_0_sysvq0asl const strlit_0_I3690031806701659348_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(size_t)(rn * "}
;
LongString_0_sysvq0asl const strlit_0_I8277570052652068250_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    if (r_.data_0) "}
;
LongString_0_sysvq0asl const strlit_0_I8678069405976132067_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "((void*)r_.data_0);\012"}
;
LongString_0_sysvq0asl const strlit_0_I10331792544921969752_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " r_ = "}
;
LongString_0_sysvq0asl const strlit_0_I15878504505370534443_aow7lb5cq1 = {
  .fullLen_0 = 31, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  _Static_assert(sizeof(r_) == "}
;
LongString_0_sysvq0asl const strlit_0_I17578962040280315901_aow7lb5cq1 = {
  .fullLen_0 = 51, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", \"aggregate return size disagrees with aowlabi\");\012"}
;
LongString_0_sysvq0asl const strlit_0_I5036188731385662161_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  memcpy(out_, &r_, "}
;
LongString_0_sysvq0asl const strlit_0_I9629254699824304600_aow7lb5cq1 = {
  .fullLen_0 = 50, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  { unsigned long long rb_ = 0; memcpy(&rb_, &r_, "}
;
LongString_0_sysvq0asl const strlit_0_I10542844442866812539_aow7lb5cq1 = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    aowli_jit_wr(out_, 0, "}
;
LongString_0_sysvq0asl const strlit_0_I10562638173522793194_aow7lb5cq1 = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", (long long)rb_); }\012"}
;
LongString_0_sysvq0asl const strlit_0_I5435985303747042468_aow7lb5cq1 = {
  .fullLen_0 = 43, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  aowli_jit_wr(out_, 0, 4, (long long)r_);\012"}
;
LongString_0_sysvq0asl const strlit_0_I15987315423624941794_aow7lb5cq1 = {
  .fullLen_0 = 28, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  long long r_ = (long long)"}
;
LongString_0_sysvq0asl const strlit_0_I5946066183656141387_aow7lb5cq1 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  aowli_jit_wr(out_, 0, "}
;
LongString_0_sysvq0asl const strlit_0_I6448058756119716242_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", r_);\012"}
;
LongString_0_sysvq0asl const strlit_0_I13635149261874571511_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLC"}
;
LongString_0_sysvq0asl const strlit_0_I2994922137697771110_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowlc"}
;
LongString_0_sysvq0asl const strlit_0_I17410079638349000741_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".c.nif"}
;
LongString_0_sysvq0asl const strlit_0_I14570291026200354739_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".x.nif"}
;
LongString_0_sysvq0asl const strlit_0_I7764585516723727988_aow7lb5cq1 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "undefined symbol: "}
;
LongString_0_sysvq0asl const strlit_0_I4549886150357915156_aow7lb5cq1 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "undefined reference to"}
;
LongString_0_sysvq0asl const strlit_0_I5505906462732536404_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "void "}
;
LongString_0_sysvq0asl const strlit_0_I15685635656363446690_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(void);\012"}
;
LongString_0_sysvq0asl const strlit_0_I8791916773570277091_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(void) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I11203801610929465702_aow7lb5cq1 = {
  .fullLen_0 = 63, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  fprintf(stderr, \"aowli JIT: native code called the host API \'"}
;
LongString_0_sysvq0asl const strlit_0_I10981136843517635042_aow7lb5cq1 = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\', which has no C definition.\\n\"\012"}
;
LongString_0_sysvq0asl const strlit_0_I2252264930722086145_aow7lb5cq1 = {
  .fullLen_0 = 70, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "                  \"A proc that can reach it should have been declined "}
;
LongString_0_sysvq0asl const strlit_0_I2450606786241534151_aow7lb5cq1 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(routineHostReach).\\n\");\012"}
;
LongString_0_sysvq0asl const strlit_0_I1178222426333560473_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  abort();\012}\012"}
;
LongString_0_sysvq0asl const strlit_0_I6323980750145937682_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NI64"}
;
LongString_0_sysvq0asl const strlit_0_I11372099257973387468_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NF64"}
;
LongString_0_sysvq0asl const strlit_0_I14550266631180595513_aow7lb5cq1 = {
  .fullLen_0 = 70, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typedef unsigned char NC8;\012typedef uint64_t NU64;\012#include <string.h>\012"}
;
LongString_0_sysvq0asl const strlit_0_I17287368031653860530_aow7lb5cq1 = {
  .fullLen_0 = 46, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " { NI64 fullLen_0; NI64 rc_0; NI64 capImpl_0; "}
;
LongString_0_sysvq0asl const strlit_0_I10892961668711831093_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "NC8 data_0[]; } "}
;
LongString_0_sysvq0asl const strlit_0_I9899413235396384892_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " { NU64 bytes_0; "}
;
LongString_0_sysvq0asl const strlit_0_I8710817496071376231_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "* more_0; } "}
;
LongString_0_sysvq0asl const strlit_0_I4134269184822004129_aow7lb5cq1 = {
  .fullLen_0 = 31, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "#define AOWLI_FS_INLINE_MAX 14\012"}
;
LongString_0_sysvq0asl const strlit_0_I8765082779704797141_aow7lb5cq1 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static long long aowli_fs_len("}
;
LongString_0_sysvq0asl const strlit_0_I15451086062892265134_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "* s) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I8418239454781733599_aow7lb5cq1 = {
  .fullLen_0 = 61, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  unsigned char tag = (unsigned char)(s->bytes_0 & 0xffull);\012"}
;
LongString_0_sysvq0asl const strlit_0_I18133447078079322724_aow7lb5cq1 = {
  .fullLen_0 = 73, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if (tag > AOWLI_FS_INLINE_MAX) return (long long)s->more_0->fullLen_0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I13047606667692590573_aow7lb5cq1 = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  return (long long)tag;\012}\012"}
;
LongString_0_sysvq0asl const strlit_0_I9945958517074851424_aow7lb5cq1 = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static const char* aowli_fs_data("}
;
LongString_0_sysvq0asl const strlit_0_I15880987555885680275_aow7lb5cq1 = {
  .fullLen_0 = 72, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if (tag > AOWLI_FS_INLINE_MAX) return (const char*)s->more_0->data_0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I7716657792389848635_aow7lb5cq1 = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  return ((const char*)s) + 1;\012}\012"}
;
LongString_0_sysvq0asl const strlit_0_I4474515410797177574_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static "}
;
LongString_0_sysvq0asl const strlit_0_I8668648937944324958_aow7lb5cq1 = {
  .fullLen_0 = 39, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " aowli_fs_from_cstr(const char* src) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I12082599546615751634_aow7lb5cq1 = {
  .fullLen_0 = 36, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " out; memset(&out, 0, sizeof(out));\012"}
;
LongString_0_sysvq0asl const strlit_0_I2988859641805316168_aow7lb5cq1 = {
  .fullLen_0 = 50, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  long long n = src \? (long long)strlen(src) : 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I13388832424567330741_aow7lb5cq1 = {
  .fullLen_0 = 34, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if (n <= AOWLI_FS_INLINE_MAX) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I364500875769014308_aow7lb5cq1 = {
  .fullLen_0 = 50, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    ((unsigned char*)&out)[0] = (unsigned char)n;\012"}
;
LongString_0_sysvq0asl const strlit_0_I16864298447618496683_aow7lb5cq1 = {
  .fullLen_0 = 54, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    if (n) memcpy(((char*)&out) + 1, src, (size_t)n);\012"}
;
LongString_0_sysvq0asl const strlit_0_I9346609203048705053_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    return out;\012"}
;
LongString_0_sysvq0asl const strlit_0_I7232983627022515607_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "* p = ("}
;
LongString_0_sysvq0asl const strlit_0_I18203647199095237467_aow7lb5cq1 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "*)malloc(3 * sizeof(NI64) + (size_t)n);\012"}
;
LongString_0_sysvq0asl const strlit_0_I7640768363785909614_aow7lb5cq1 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if (!p) return out;\012"}
;
LongString_0_sysvq0asl const strlit_0_I12091536289913666620_aow7lb5cq1 = {
  .fullLen_0 = 51, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  p->fullLen_0 = n; p->rc_0 = 0; p->capImpl_0 = n;\012"}
;
LongString_0_sysvq0asl const strlit_0_I11749156186693331548_aow7lb5cq1 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  memcpy(p->data_0, src, (size_t)n);\012"}
;
LongString_0_sysvq0asl const strlit_0_I2907747001831285170_aow7lb5cq1 = {
  .fullLen_0 = 51, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  out.more_0 = p; ((unsigned char*)&out)[0] = 255;\012"}
;
LongString_0_sysvq0asl const strlit_0_I15874091423332818451_aow7lb5cq1 = {
  .fullLen_0 = 43, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  memcpy(((char*)&out) + 1, p->data_0, 7);\012"}
;
LongString_0_sysvq0asl const strlit_0_I10757245804552490900_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  return out;\012}\012"}
;
LongString_0_sysvq0asl const strlit_0_I17605077022815850042_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "string_0_"}
;
LongString_0_sysvq0asl const strlit_0_I15230512448378417494_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "LongString_0_"}
;
LongString_0_sysvq0asl const strlit_0_I5637264954227160523_aow7lb5cq1 = {
  .fullLen_0 = 68, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* aowli JIT: host-call stubs for symbols with no translation unit.\012"}
;
LongString_0_sysvq0asl const strlit_0_I17177110499767132265_aow7lb5cq1 = {
  .fullLen_0 = 70, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "   A FORWARDER reaches the embedder\'s host through aowli_hf; anything\012"}
;
LongString_0_sysvq0asl const strlit_0_I5674099961252277032_aow7lb5cq1 = {
  .fullLen_0 = 67, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "   whose prototype is not forwardable ABORTS, and routineHostReach\012"}
;
LongString_0_sysvq0asl const strlit_0_I17380335403814435655_aow7lb5cq1 = {
  .fullLen_0 = 61, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "   still declines every proc that can reach one of those. */\012"}
;
LongString_0_sysvq0asl const strlit_0_I4507293232177819398_aow7lb5cq1 = {
  .fullLen_0 = 59, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "#include <stdio.h>\012#include <stdlib.h>\012#include <stdint.h>\012"}
;
LongString_0_sysvq0asl const strlit_0_I5192493655371327513_aow7lb5cq1 = {
  .fullLen_0 = 61, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "#define NB8 _Bool\012typedef double NF64;\012typedef int64_t NI64;\012"}
;
LongString_0_sysvq0asl const strlit_0_I13866842447811724506_aow7lb5cq1 = {
  .fullLen_0 = 61, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typedef struct { int kind; long long integer; double number;\012"}
;
LongString_0_sysvq0asl const strlit_0_I7968170841241575315_aow7lb5cq1 = {
  .fullLen_0 = 53, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "                 const char* text; } AowliHostValue;\012"}
;
LongString_0_sysvq0asl const strlit_0_I1573076124429889532_aow7lb5cq1 = {
  .fullLen_0 = 59, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "typedef int (*aowli_hf_t)(const char*, void*, int, void*);\012"}
;
LongString_0_sysvq0asl const strlit_0_I9225250353289554045_aow7lb5cq1 = {
  .fullLen_0 = 32, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static aowli_hf_t aowli_hf = 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I8164311879278760128_aow7lb5cq1 = {
  .fullLen_0 = 49, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "#if defined(_WIN32)\012__declspec(dllexport)\012#endif\012"}
;
LongString_0_sysvq0asl const strlit_0_I14087883000254015324_aow7lb5cq1 = {
  .fullLen_0 = 62, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "void aowli_set_host_forward(aowli_hf_t fn) { aowli_hf = fn; }\012"}
;
LongString_0_sysvq0asl const strlit_0_I9983178280678633983_aow7lb5cq1 = {
  .fullLen_0 = 46, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static void aowli_hf_missing(const char* n) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I10092270157963981938_aow7lb5cq1 = {
  .fullLen_0 = 76, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  fprintf(stderr, \"aowli JIT: native code called the host API \'%s\' but no \"\012"}
;
LongString_0_sysvq0asl const strlit_0_I11609677804622622241_aow7lb5cq1 = {
  .fullLen_0 = 57, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "                  \"host forwarder was installed.\\n\", n);\012"}
;
LongString_0_sysvq0asl const strlit_0_I14032647850895285638_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  AowliHostValue av["}
;
LongString_0_sysvq0asl const strlit_0_I18306619155145694585_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".integer = 0; "}
;
LongString_0_sysvq0asl const strlit_0_I829567100987362370_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".number = 0; "}
;
LongString_0_sysvq0asl const strlit_0_I470006872129730788_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".text = 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I2417009231442816373_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".kind = 2; "}
;
LongString_0_sysvq0asl const strlit_0_I16152225727888320114_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".number = a"}
;
LongString_0_sysvq0asl const strlit_0_I3027407436919667588_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".kind = 3; "}
;
LongString_0_sysvq0asl const strlit_0_I11723720343194599649_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".integer = a"}
;
LongString_0_sysvq0asl const strlit_0_I4433735051247999596_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \? 1 : 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I11838551355314224182_aow7lb5cq1 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = aowli_fs_len(&a"}
;
LongString_0_sysvq0asl const strlit_0_I18298778748534440366_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  char* t"}
;
LongString_0_sysvq0asl const strlit_0_I6279534061532764400_aow7lb5cq1 = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = (char*)malloc((size_t)n"}
;
LongString_0_sysvq0asl const strlit_0_I999642826010098592_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " + 1);\012"}
;
LongString_0_sysvq0asl const strlit_0_I18051931441392338794_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if (t"}
;
LongString_0_sysvq0asl const strlit_0_I14188028891984688503_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") { if (n"}
;
LongString_0_sysvq0asl const strlit_0_I12896234052304697321_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " > 0) memcpy(t"}
;
LongString_0_sysvq0asl const strlit_0_I15085895479102727221_aow7lb5cq1 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", aowli_fs_data(&a"}
;
LongString_0_sysvq0asl const strlit_0_I13873650213014514182_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "), (size_t)n"}
;
LongString_0_sysvq0asl const strlit_0_I16538839068818699094_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "); t"}
;
LongString_0_sysvq0asl const strlit_0_I522319342984753436_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "] = 0; }\012"}
;
LongString_0_sysvq0asl const strlit_0_I2950111016992692895_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".kind = 4; "}
;
LongString_0_sysvq0asl const strlit_0_I9906658197478316873_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".text = t"}
;
LongString_0_sysvq0asl const strlit_0_I16354051738273881375_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \? t"}
;
LongString_0_sysvq0asl const strlit_0_I1386869864609809741_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " : \"\";\012"}
;
LongString_0_sysvq0asl const strlit_0_I2409465560036334351_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".kind = 1; "}
;
LongString_0_sysvq0asl const strlit_0_I12472622578803491916_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".integer = (long long)a"}
;
LongString_0_sysvq0asl const strlit_0_I9727381277316448500_aow7lb5cq1 = {
  .fullLen_0 = 73, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  AowliHostValue r; r.kind = 0; r.integer = 0; r.number = 0; r.text = 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I4239050738771163905_aow7lb5cq1 = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  if (!aowli_hf) aowli_hf_missing(\""}
;
LongString_0_sysvq0asl const strlit_0_I4880342578591911379_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\");\012"}
;
LongString_0_sysvq0asl const strlit_0_I17618980285034117678_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  aowli_hf(\""}
;
LongString_0_sysvq0asl const strlit_0_I15379383283362004468_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\", av, "}
;
LongString_0_sysvq0asl const strlit_0_I15447660952270510385_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", &r);\012"}
;
LongString_0_sysvq0asl const strlit_0_I13053102254449164970_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  free(t"}
;
LongString_0_sysvq0asl const strlit_0_I8589617518665240758_aow7lb5cq1 = {
  .fullLen_0 = 51, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  return r.kind == 2 \? r.number : (NF64)r.integer;\012"}
;
LongString_0_sysvq0asl const strlit_0_I10391326054084265825_aow7lb5cq1 = {
  .fullLen_0 = 59, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  return r.kind == 2 \? (r.number != 0) : (r.integer != 0);\012"}
;
LongString_0_sysvq0asl const strlit_0_I17794303870586718664_aow7lb5cq1 = {
  .fullLen_0 = 57, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  return r.kind == 2 \? (NI64)r.number : (NI64)r.integer;\012"}
;
LongString_0_sysvq0asl const strlit_0_I7118603062085015288_aow7lb5cq1 = {
  .fullLen_0 = 60, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  { const char* rt = (r.kind == 4 && r.text) \? r.text : \"\";\012"}
;
LongString_0_sysvq0asl const strlit_0_I1702752895680478826_aow7lb5cq1 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    return aowli_fs_from_cstr(rt); }\012"}
;
LongString_0_sysvq0asl const strlit_0_I15753997017069821155_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hostfwd.txt"}
;
LongString_0_sysvq0asl const strlit_0_I16911823819878676030_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-fPIC -O2 -w"}
;
LongString_0_sysvq0asl const strlit_0_I1487126578772208186_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gcc -c "}
;
LongString_0_sysvq0asl const strlit_0_I2123011150024992218_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " -o "}
;
LongString_0_sysvq0asl const strlit_0_I278182693605788883_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " 2>&1"}
;
LongString_0_sysvq0asl const strlit_0_I7830052811571726362_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gcc "}
;
LongString_0_sysvq0asl const strlit_0_I10506424120731942949_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-shared -fPIC -O2 -w"}
;
LongString_0_sysvq0asl const strlit_0_I3033588956580774226_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " -Wl,--whole-archive"}
;
LongString_0_sysvq0asl const strlit_0_I6185901741629117379_aow7lb5cq1 = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " -Wl,--no-whole-archive -o "}
;
LongString_0_sysvq0asl const strlit_0_I14743647238960953227_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " -lm"}
;
LongString_0_sysvq0asl const strlit_0_I11438303454518475359_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_jit.c"}
;
LongString_0_sysvq0asl const strlit_0_I1947988348543698404_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "build.log"}
;
LongString_0_sysvq0asl const strlit_0_I12541394025232970491_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "host-stubs.revision"}
;
LongString_0_sysvq0asl const strlit_0_I9032354697946540937_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "modules.txt"}
;
LongString_0_sysvq0asl const strlit_0_I14177207265498126630_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/*.c.nif "}
;
LongString_0_sysvq0asl const strlit_0_I267845865139732674_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/*/*.c.nif"}
;
LongString_0_sysvq0asl const strlit_0_I18192332346447245389_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_JIT_PREDCE"}
;
LongString_0_sysvq0asl const strlit_0_I7475120879548367157_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "xmodules.txt"}
;
LongString_0_sysvq0asl const strlit_0_I18095216927531186533_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/*.x.nif "}
;
LongString_0_sysvq0asl const strlit_0_I16254858060766665859_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/*/*.x.nif"}
;
LongString_0_sysvq0asl const strlit_0_I6141559193247183651_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "xnif"}
;
LongString_0_sysvq0asl const strlit_0_I6946320866761157030_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_JIT_LOG"}
;
LongString_0_sysvq0asl const strlit_0_I17588196217130192428_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".x.nif (pre-DCE)"}
;
LongString_0_sysvq0asl const strlit_0_I17145838109380889823_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".c.nif (post-DCE)"}
;
LongString_0_sysvq0asl const strlit_0_I4565430035092908447_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: bodies from "}
;
LongString_0_sysvq0asl const strlit_0_I13319807167292544980_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 "}
;
LongString_0_sysvq0asl const strlit_0_I17138688373536918376_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " modules\012"}
;
LongString_0_sysvq0asl const strlit_0_I9467484319694674619_aow7lb5cq1 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "borrowCStringUnsafe_0_"}
;
LongString_0_sysvq0asl const strlit_0_I16718063019512574093_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dealloc_0_"}
;
LongString_0_sysvq0asl const strlit_0_I5607995952013721966_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "alloc_0_"}
;
LongString_0_sysvq0asl const strlit_0_I18346817918174572282_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit-decline "}
;
LongString_0_sysvq0asl const strlit_0_I5568421909041685451_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " [emitter]\012"}
;
LongString_0_sysvq0asl const strlit_0_I2902833179283423287_aow7lb5cq1 = {
  .fullLen_0 = 34, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " : takes a string, and this build "}
;
LongString_0_sysvq0asl const strlit_0_I11009621119207680114_aow7lb5cq1 = {
  .fullLen_0 = 48, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "has no string runtime helpers to call [emitter]\012"}
;
LongString_0_sysvq0asl const strlit_0_I16752411121828324346_aow7lb5cq1 = {
  .fullLen_0 = 31, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " : takes a seq, and this build "}
;
LongString_0_sysvq0asl const strlit_0_I3740790232156408913_aow7lb5cq1 = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "has no allocator to call [emitter]\012"}
;
LongString_0_sysvq0asl const strlit_0_I7386731376022360794_aow7lb5cq1 = {
  .fullLen_0 = 28, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " : the emitted C carries no "}
;
LongString_0_sysvq0asl const strlit_0_I9306212446656051791_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "definition named "}
;
LongString_0_sysvq0asl const strlit_0_I13430982929222912407_aow7lb5cq1 = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", and its base name is ambiguous\012"}
;
LongString_0_sysvq0asl const strlit_0_I4639961614947029451_aow7lb5cq1 = {
  .fullLen_0 = 62, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "definition of it at all (inlined away, or eliminated as dead)\012"}
;
LongString_0_sysvq0asl const strlit_0_I14045175378979266023_aow7lb5cq1 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " (dead code, or inlined away)\012"}
;
LongString_0_sysvq0asl const strlit_0_I9361295413614208495_aow7lb5cq1 = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "the C signature could not be parsed"}
;
LongString_0_sysvq0asl const strlit_0_I2584675443025991433_aow7lb5cq1 = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "an argument is a composite containing "}
;
LongString_0_sysvq0asl const strlit_0_I12438589081047852308_aow7lb5cq1 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "the return is a composite containing "}
;
LongString_0_sysvq0asl const strlit_0_I3443046107169670104_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_jit_slen"}
;
LongString_0_sysvq0asl const strlit_0_I2317332660687858480_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\012extern "}
;
LongString_0_sysvq0asl const strlit_0_I16715136830670315920_aow7lb5cq1 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(unsigned char*, long long);\012"}
;
LongString_0_sysvq0asl const strlit_0_I3018204930238191970_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\012extern void* "}
;
LongString_0_sysvq0asl const strlit_0_I13922026781561364508_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(long long);\012"}
;
LongString_0_sysvq0asl const strlit_0_I16286562635260071850_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "extern void "}
;
LongString_0_sysvq0asl const strlit_0_I4552606806654256453_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(void*);\012"}
;
LongString_0_sysvq0asl const strlit_0_I11456809569861300725_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: shims="}
;
LongString_0_sysvq0asl const strlit_0_I17792640634769934702_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " (exact="}
;
LongString_0_sysvq0asl const strlit_0_I18342294718160420153_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " by-base="}
;
LongString_0_sysvq0asl const strlit_0_I172984808378442068_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") no-C-body="}
;
LongString_0_sysvq0asl const strlit_0_I14472242329998166714_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " ambiguous="}
;
LongString_0_sysvq0asl const strlit_0_I8179081380582823378_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mod_"}
;
LongString_0_sysvq0asl const strlit_0_I15752602684027218635_aow7lb5cq1 = {
  .fullLen_0 = 2026, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/* GENERATED BY aowlc. DO NOT EDIT. */\012#define NIM_INTBITS 64\012#include <stdint.h>\012#include <stddef.h>\012#include <stdbool.h>\012#include <math.h>\012\012#define NIM_NIL NULL\012#define NB8 _Bool\012typedef unsigned char NC8;\012typedef uint16_t NC16;\012typedef uint32_t NC32;\012typedef float  NF32;\012typedef double NF64;\012typedef double NF;\012typedef int8_t  NI8;  typedef int16_t  NI16; typedef int32_t  NI32; typedef int64_t  NI64;\012typedef uint8_t NU8;  typedef uint16_t NU16; typedef uint32_t NU32; typedef uint64_t NU64;\012typedef NI64 NI;      typedef NU64 NU;\012\012#define NIM_TRUE true\012#define NIM_FALSE false\012#ifndef INF\012#  ifdef INFINITY\012#    define INF INFINITY\012#  else\012#    define INF (1.0/0.0)\012#  endif\012#endif\012#if defined(__GNUC__) || defined(_MSC_VER)\012#  define IL64(x) x##LL\012#else\012#  define IL64(x) ((NI64)x)\012#endif\012#define NIM_ALIGN(x)  __attribute__((aligned(x)))\012#define NIM_ALIGNOF(x) __alignof__(x)\012#if defined(__GNUC__) || defined(__clang__)\012#  /* Eight more pragmas used to sit here: -Wint-conversion,\012#     -Wincompatible-pointer-types, -Wbuiltin-declaration-mismatch,\012#     -Wimplicit-function-declaration, -Wmain, -Wreturn-type,\012#     -Wparentheses, -Wattributes. Measured across the whole e2e corpus\012#     with the pragmas stripped: not one of them fires. They suppressed\012#     nothing and could only ever hide a NEW defect -- -Wreturn-type is\012#     exactly what hid a bare no-value return emitted from a\012#     struct-returning function. test/e2e.sh enforces that they stay\012#     silent. The six below DO fire and are noise for generated code:\012#     an emitter cannot know a label or a temp goes unused. */\012#  pragma GCC diagnostic ignored \"-Wpointer-sign\"\012#  pragma GCC diagnostic ignored \"-Wunused-label\"\012#  pragma GCC diagnostic ignored \"-Wunused-variable\"\012#  pragma GCC diagnostic ignored \"-Wunused-function\"\012#  pragma GCC diagnostic ignored \"-Wformat\"\012#  pragma GCC diagnostic ignored \"-Wdiscarded-qualifiers\"\012#  pragma GCC diagnostic ignored \"-Wunused-but-set-variable\"\012#  pragma GCC diagnostic ignored \"-Wmissing-braces\"\012#endif\012"}
;
LongString_0_sysvq0asl const strlit_0_I5350979616169502278_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_native_init.c"}
;
LongString_0_sysvq0asl const strlit_0_I16159220003410283764_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jester_native_"}
;
LongString_0_sysvq0asl const strlit_0_I12714862762194711353_aow7lb5cq1 = {
  .fullLen_0 = 54, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "#if defined(_WIN32)\012__declspec(dllexport) extern void "}
;
LongString_0_sysvq0asl const strlit_0_I2451862973728995994_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(void);\012#endif\012"}
;
LongString_0_sysvq0asl const strlit_0_I8659447081661426280_aow7lb5cq1 = {
  .fullLen_0 = 71, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "LIBRARY aowli_jit.dll\012EXPORTS\012aowli_native_init\012aowli_set_host_forward\012"}
;
LongString_0_sysvq0asl const strlit_0_I3392786984146350459_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_exports.def"}
;
LongString_0_sysvq0asl const strlit_0_I6929186202351031481_aow7lb5cq1 = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "extern int main(int, char**, char**);\012"}
;
LongString_0_sysvq0asl const strlit_0_I16378428795907340016_aow7lb5cq1 = {
  .fullLen_0 = 60, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "void aowli_native_init(void) { static char a0[] = \"jester\"; "}
;
LongString_0_sysvq0asl const strlit_0_I12606525818129378590_aow7lb5cq1 = {
  .fullLen_0 = 72, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "static char* av[] = { a0, (char*)0 }; static char* ep[] = { (char*)0 }; "}
;
LongString_0_sysvq0asl const strlit_0_I3706874824641185916_aow7lb5cq1 = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "(void)main(1, av, ep); }\012"}
;
LongString_0_sysvq0asl const strlit_0_I18217798024384389773_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_native_init.o"}
;
LongString_0_sysvq0asl const strlit_0_I841702713041921937_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: "}
;
LongString_0_sysvq0asl const strlit_0_I8474398651341962338_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " of "}
;
LongString_0_sysvq0asl const strlit_0_I7467151943153133040_aow7lb5cq1 = {
  .fullLen_0 = 50, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " units needed compiling (the rest were unchanged)\012"}
;
LongString_0_sysvq0asl const strlit_0_I7503365064679144772_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "libaowli_jit.so"}
;
LongString_0_sysvq0asl const strlit_0_I5516325166660413504_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_jit_stubs.o"}
;
LongString_0_sysvq0asl const strlit_0_I15089684066203031656_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: route=cached ("}
;
LongString_0_sysvq0asl const strlit_0_I4172422166419302997_aow7lb5cq1 = {
  .fullLen_0 = 34, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " units unchanged, library reused)\012"}
;
LongString_0_sysvq0asl const strlit_0_I15934887379077153009_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: route=objects ("}
;
LongString_0_sysvq0asl const strlit_0_I6305068438373177994_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " units)\012"}
;
LongString_0_sysvq0asl const strlit_0_I10407826023453223595_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_jit_stubs.c"}
;
LongString_0_sysvq0asl const strlit_0_I20870224864136604_aow7lb5cq1 = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: route=objects+stubs ("}
;
LongString_0_sysvq0asl const strlit_0_I10939655993194240046_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " units, "}
;
LongString_0_sysvq0asl const strlit_0_I17840704925771562650_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " host symbols: "}
;
LongString_0_sysvq0asl const strlit_0_I16618787334720904331_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " forwarded, "}
;
LongString_0_sysvq0asl const strlit_0_I11669336360358941120_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " abort)\012"}
;
LongString_0_sysvq0asl const strlit_0_I5560383726051623062_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: route=in-process ("}
;
LongString_0_sysvq0asl const strlit_0_I13807919816995135645_aow7lb5cq1 = {
  .fullLen_0 = 49, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " units, no subprocess, no external aowlc needed)\012"}
;
LongString_0_sysvq0asl const strlit_0_I3929042842498019668_aow7lb5cq1 = {
  .fullLen_0 = 61, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " host symbols have no C definition; linking with abort stubs\012"}
;
LongString_0_sysvq0asl const strlit_0_I137218741528845722_aow7lb5cq1 = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: route=in-process+stubs ("}
;
LongString_0_sysvq0asl const strlit_0_I5994905260270776565_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " error: "}
;
LongString_0_sysvq0asl const strlit_0_I12082841593871989252_aow7lb5cq1 = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gcc failed with no error line (see "}
;
LongString_0_sysvq0asl const strlit_0_I6593187846888673991_aow7lb5cq1 = {
  .fullLen_0 = 63, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: route=SUBPROCESS \342\200\224 the in-process emit did not compile, "}
;
LongString_0_sysvq0asl const strlit_0_I14068837617402760607_aow7lb5cq1 = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "falling back to `aowlc link`.\012"}
;
LongString_0_sysvq0asl const strlit_0_I9780003836072079947_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit:   reason: "}
;
LongString_0_sysvq0asl const strlit_0_I10430587979360259626_aow7lb5cq1 = {
  .fullLen_0 = 63, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit:   this route needs a correctly-built aowlc driver on disk "}
;
LongString_0_sysvq0asl const strlit_0_I5082076793001871145_aow7lb5cq1 = {
  .fullLen_0 = 42, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "and forks it while the program is PAUSED.\012"}
;
LongString_0_sysvq0asl const strlit_0_I17458548344829006286_aow7lb5cq1 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: no aowlc driver at "}
;
LongString_0_sysvq0asl const strlit_0_I13273991446069831203_aow7lb5cq1 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 nothing compiled\012"}
;
LongString_0_sysvq0asl const strlit_0_I12623205787878531514_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_jit_drv.c"}
;
LongString_0_sysvq0asl const strlit_0_I13081134508802474439_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " link"}
;
LongString_0_sysvq0asl const strlit_0_I2781643746782836964_aow7lb5cq1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " --emit-only -o "}
;
LongString_0_sysvq0asl const strlit_0_I9946169762350422666_aow7lb5cq1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "for sn in "}
;
LongString_0_sysvq0asl const strlit_0_I8938930563455684877_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "/*.s.nif; do "}
;
LongString_0_sysvq0asl const strlit_0_I17505878642142243233_aow7lb5cq1 = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "[ -f \"$sn\" ] || continue; "}
;
LongString_0_sysvq0asl const strlit_0_I9003811850995758106_aow7lb5cq1 = {
  .fullLen_0 = 57, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hdr=$(awk \'/^\\(stmts@/{print; exit}\' \"$sn\" 2>/dev/null); "}
;
LongString_0_sysvq0asl const strlit_0_I5022596381085879336_aow7lb5cq1 = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "src=$(printf \'%s\' \"$hdr\" | "}
;
LongString_0_sysvq0asl const strlit_0_I3301261775358999833_aow7lb5cq1 = {
  .fullLen_0 = 60, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sed -n \'s/^(stmts@[^,]*,[^,]*,\"\\{0,1\\}\\([^\" )]*\\).*/\\1/p\'); "}
;
LongString_0_sysvq0asl const strlit_0_I1367334208925539560_aow7lb5cq1 = {
  .fullLen_0 = 67, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "printf \'%s\\t%s\\n\' \"$(basename \"$sn\" .s.nif)\" \"$(basename \"$src\")\"; "}
;
LongString_0_sysvq0asl const strlit_0_I15015826066028142083_aow7lb5cq1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "done > "}
;
LongString_0_sysvq0asl const strlit_0_I14102627614057926696_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " 2>/dev/null"}
;
LongString_0_sysvq0asl const strlit_0_I1968479202869160466_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " [eligibility]\012"}
;
LongString_0_sysvq0asl const strlit_0_I12313941242067973473_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sysvq0asl"}
;
LongString_0_sysvq0asl const strlit_0_I7882222020183427492_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "main"}
;
LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1 = {
  .fullLen_0 = 113, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/seqimpl.nim(167, 41): i < s.len and 0 <= i [AssertionDefect]\012"}
;
LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1 = {
  .fullLen_0 = 19, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "leave uninitialized"}
;
LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1 = {
  .fullLen_0 = 113, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/seqimpl.nim(169, 53): i < s.len and 0 <= i [AssertionDefect]\012"}
;
LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1 = {
  .fullLen_0 = 119, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/openarrays.nim(10, 49): 0 <= idx and idx < x.len [AssertionDefect]\012"}
;
static string_0_sysvq0asl const HostStubAbiRevision_0 = {
  .bytes_0 = 3354882u, .more_0 = NIM_NIL}
;
NB8 X60QiniGuard_0_aow7lb5cq1;
AbiKind_0_layptix6a1 leafKind_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_0){
  AbiKind_0_layptix6a1 result_0;
  if (td_0 == NIM_NIL){
    return 5;}
  NB8 X60Qx_48;
  if ((*td_0).d_00.kind_0 == 13){
    X60Qx_48 = (!((*td_0).d_00.elem_0 == NIM_NIL));}
  else {
    X60Qx_48 = NIM_FALSE;}
  if (X60Qx_48){
    AbiKind_0_layptix6a1 X60Qx_49 = leafKind_0_aow7lb5cq1((*td_0).d_00.elem_0);
    result_0 = X60Qx_49;
    return result_0;}
  result_0 = (*td_0).d_00.kind_0;
  return result_0;}
NB8 plainField_0_aow7lb5cq1(WireField_0_run8hsnpi* f_0){
  NB8 result_1;
  NB8 X60Qx_50;
  NB8 X60Qx_51;
  NB8 X60Qx_52;
  NB8 X60Qx_53;
  NB8 X60Qx_54;
  NB8 X60Qx_55;
  NB8 X60Qx_56;
  NB8 X60Qx_57;
  NB8 X60Qx_58;
  if ((*f_0).isEnum_0){
    X60Qx_58 = NIM_TRUE;}
  else {
    X60Qx_58 = (*f_0).isRef_0;}
  if (X60Qx_58){
    X60Qx_57 = NIM_TRUE;}
  else {
    X60Qx_57 = (*f_0).isArenaRef_0;}
  if (X60Qx_57){
    X60Qx_56 = NIM_TRUE;}
  else {
    X60Qx_56 = (*f_0).isArenaPtr_0;}
  if (X60Qx_56){
    X60Qx_55 = NIM_TRUE;}
  else {
    X60Qx_55 = (*f_0).isPtrArena_0;}
  if (X60Qx_55){
    X60Qx_54 = NIM_TRUE;}
  else {
    X60Qx_54 = (*f_0).isForeignPtr_0;}
  if (X60Qx_54){
    X60Qx_53 = NIM_TRUE;}
  else {
    X60Qx_53 = (*f_0).isPod_0;}
  if (X60Qx_53){
    X60Qx_52 = NIM_TRUE;}
  else {
    X60Qx_52 = (*f_0).isString_0;}
  if (X60Qx_52){
    X60Qx_51 = NIM_TRUE;}
  else {
    X60Qx_51 = (*f_0).isSeq_0;}
  if (X60Qx_51){
    X60Qx_50 = NIM_TRUE;}
  else {
    X60Qx_50 = (*f_0).isArray_0;}
  result_1 = (!X60Qx_50);
  return result_1;}
NB8 widthOk_0_aow7lb5cq1(NI32 n_0){
  NB8 result_2;
  NB8 X60Qx_59;
  NB8 X60Qx_60;
  NB8 X60Qx_61;
  if (n_0 == 1){
    X60Qx_61 = NIM_TRUE;}
  else {
    X60Qx_61 = (n_0 == 2);}
  if (X60Qx_61){
    X60Qx_60 = NIM_TRUE;}
  else {
    X60Qx_60 = (n_0 == 4);}
  if (X60Qx_60){
    X60Qx_59 = NIM_TRUE;}
  else {
    X60Qx_59 = (n_0 == 8);}
  result_2 = X60Qx_59;
  return result_2;}
NB8 scalarOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_1){
  NB8 result_3;
  NB8 X60Qx_62;
  NB8 X60Qx_63;
  NB8 X60Qx_64 = plainField_0_aow7lb5cq1((&(*f_1)));
  if ((!X60Qx_64)){
    X60Qx_63 = NIM_TRUE;}
  else {
    X60Qx_63 = (*f_1).isVar_0;}
  if (X60Qx_63){
    X60Qx_62 = NIM_TRUE;}
  else {
    X60Qx_62 = ((*f_1).desc_0 == NIM_NIL);}
  if (X60Qx_62){
    return NIM_FALSE;}
  AbiKind_0_layptix6a1 X60Qx_65 = leafKind_0_aow7lb5cq1((*f_1).desc_0);
  switch (X60Qx_65){
    case 0:
    case 1:
    case 4:
    case 3:
    {
      }
    break;
    default:
    {
      return NIM_FALSE;}
    break;}
  NB8 X60Qx_66 = widthOk_0_aow7lb5cq1((*f_1).wireSize_0);
  result_3 = X60Qx_66;
  return result_3;}
NB8 floatOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_2){
  NB8 result_4;
  NB8 X60Qx_67;
  NB8 X60Qx_68;
  NB8 X60Qx_69 = plainField_0_aow7lb5cq1((&(*f_2)));
  if ((!X60Qx_69)){
    X60Qx_68 = NIM_TRUE;}
  else {
    X60Qx_68 = (*f_2).isVar_0;}
  if (X60Qx_68){
    X60Qx_67 = NIM_TRUE;}
  else {
    X60Qx_67 = ((*f_2).desc_0 == NIM_NIL);}
  if (X60Qx_67){
    return NIM_FALSE;}
  NB8 X60Qx_70;
  AbiKind_0_layptix6a1 X60Qx_71 = leafKind_0_aow7lb5cq1((*f_2).desc_0);
  if (X60Qx_71 == 2){
    NB8 X60Qx_72;
    if ((*f_2).wireSize_0 == 4){
      X60Qx_72 = NIM_TRUE;}
    else {
      X60Qx_72 = ((*f_2).wireSize_0 == 8);}
    X60Qx_70 = X60Qx_72;}
  else {
    X60Qx_70 = NIM_FALSE;}
  result_4 = X60Qx_70;
  return result_4;}
NB8 enumOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_3){
  NB8 result_5;
  NB8 X60Qx_73;
  if ((*f_3).isEnum_0){
    X60Qx_73 = (!(*f_3).isVar_0);}
  else {
    X60Qx_73 = NIM_FALSE;}
  result_5 = X60Qx_73;
  return result_5;}
NB8 podOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_4){
  NB8 result_6;
  NB8 X60Qx_74;
  NB8 X60Qx_75;
  NB8 X60Qx_76;
  NB8 X60Qx_77;
  if ((*f_4).isArenaPtr_0){
    X60Qx_77 = NIM_TRUE;}
  else {
    X60Qx_77 = (*f_4).isPtrArena_0;}
  if (X60Qx_77){
    X60Qx_76 = NIM_TRUE;}
  else {
    X60Qx_76 = (*f_4).isRef_0;}
  if (X60Qx_76){
    X60Qx_75 = NIM_TRUE;}
  else {
    X60Qx_75 = (*f_4).isArenaRef_0;}
  if (X60Qx_75){
    X60Qx_74 = NIM_TRUE;}
  else {
    X60Qx_74 = (*f_4).isVar_0;}
  if (X60Qx_74){
    return NIM_FALSE;}
  NB8 X60Qx_78;
  NB8 X60Qx_79;
  if ((*f_4).isPod_0){
    X60Qx_79 = NIM_TRUE;}
  else {
    X60Qx_79 = (*f_4).isArray_0;}
  if (X60Qx_79){
    X60Qx_78 = (0 < (*f_4).wireSize_0);}
  else {
    X60Qx_78 = NIM_FALSE;}
  result_6 = X60Qx_78;
  return result_6;}
NB8 seqOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_5){
  NB8 result_7;
  NB8 X60Qx_80;
  NB8 X60Qx_81;
  NB8 X60Qx_82;
  if ((*f_5).isVar_0){
    X60Qx_82 = NIM_TRUE;}
  else {
    X60Qx_82 = (*f_5).isRef_0;}
  if (X60Qx_82){
    X60Qx_81 = NIM_TRUE;}
  else {
    X60Qx_81 = (*f_5).isArenaRef_0;}
  if (X60Qx_81){
    X60Qx_80 = NIM_TRUE;}
  else {
    X60Qx_80 = (*f_5).isSink_0;}
  if (X60Qx_80){
    return NIM_FALSE;}
  NB8 X60Qx_83;
  NB8 X60Qx_84;
  if ((*f_5).isSeq_0){
    X60Qx_84 = (!(*f_5).elemVarLen_0);}
  else {
    X60Qx_84 = NIM_FALSE;}
  if (X60Qx_84){
    X60Qx_83 = (0 < (*f_5).elemStride_0);}
  else {
    X60Qx_83 = NIM_FALSE;}
  result_7 = X60Qx_83;
  return result_7;}
NB8 stringOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_6){
  NB8 result_8;
  NB8 X60Qx_85;
  NB8 X60Qx_86;
  NB8 X60Qx_87;
  if ((*f_6).isString_0){
    X60Qx_87 = (!(*f_6).isVar_0);}
  else {
    X60Qx_87 = NIM_FALSE;}
  if (X60Qx_87){
    X60Qx_86 = (!(*f_6).isRef_0);}
  else {
    X60Qx_86 = NIM_FALSE;}
  if (X60Qx_86){
    X60Qx_85 = (!(*f_6).isArenaRef_0);}
  else {
    X60Qx_85 = NIM_FALSE;}
  result_8 = X60Qx_85;
  return result_8;}
NB8 varOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_7){
  NB8 result_9;
  NB8 X60Qx_88;
  NB8 X60Qx_89;
  NB8 X60Qx_90;
  NB8 X60Qx_91;
  if ((!(*f_7).isVar_0)){
    X60Qx_91 = NIM_TRUE;}
  else {
    X60Qx_91 = (*f_7).isRef_0;}
  if (X60Qx_91){
    X60Qx_90 = NIM_TRUE;}
  else {
    X60Qx_90 = (*f_7).isArenaRef_0;}
  if (X60Qx_90){
    X60Qx_89 = NIM_TRUE;}
  else {
    X60Qx_89 = (*f_7).isArenaPtr_0;}
  if (X60Qx_89){
    X60Qx_88 = NIM_TRUE;}
  else {
    X60Qx_88 = (*f_7).isPtrArena_0;}
  if (X60Qx_88){
    return NIM_FALSE;}
  if ((*f_7).wireSize_0 <= 0){
    return NIM_FALSE;}
  NB8 X60Qx_92;
  if ((*f_7).isPod_0){
    X60Qx_92 = NIM_TRUE;}
  else {
    X60Qx_92 = (*f_7).isArray_0;}
  if (X60Qx_92){
    return NIM_TRUE;}
  NB8 X60Qx_93 = plainField_0_aow7lb5cq1((&(*f_7)));
  if ((!X60Qx_93)){
    return NIM_FALSE;}
  AbiKind_0_layptix6a1 X60Qx_94 = leafKind_0_aow7lb5cq1((*f_7).desc_0);
  switch (X60Qx_94){
    case 0:
    case 1:
    case 4:
    case 3:
    {
      NB8 X60Qx_95 = widthOk_0_aow7lb5cq1((*f_7).wireSize_0);
      result_9 = X60Qx_95;}
    break;
    case 2:
    {
      NB8 X60Qx_96;
      if ((*f_7).wireSize_0 == 4){
        X60Qx_96 = NIM_TRUE;}
      else {
        X60Qx_96 = ((*f_7).wireSize_0 == 8);}
      result_9 = X60Qx_96;}
    break;
    default:
    {
      result_9 = NIM_FALSE;}
    break;}
  return result_9;}
NB8 compositeOkHere_0_aow7lb5cq1(WireField_0_run8hsnpi* f_8){
  NB8 result_10;
  NB8 X60Qx_97;
  if ((!((*f_8).desc_0 == NIM_NIL))){
    NB8 X60Qx_98 = compositeCOk_0_aow7lb5cq1((*f_8).desc_0, 0);
    X60Qx_97 = X60Qx_98;}
  else {
    X60Qx_97 = NIM_FALSE;}
  result_10 = X60Qx_97;
  return result_10;}
NB8 argOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_9){
  NB8 result_11;
  if ((*f_9).isComposite_0){
    NB8 X60Qx_99 = compositeOkHere_0_aow7lb5cq1((&(*f_9)));
    result_11 = X60Qx_99;
    return result_11;}
  NB8 X60Qx_100;
  NB8 X60Qx_101;
  NB8 X60Qx_102;
  NB8 X60Qx_103;
  NB8 X60Qx_104;
  NB8 X60Qx_105;
  NB8 X60Qx_106 = scalarOk_0_aow7lb5cq1((&(*f_9)));
  if (X60Qx_106){
    X60Qx_105 = NIM_TRUE;}
  else {
    NB8 X60Qx_107 = floatOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_105 = X60Qx_107;}
  if (X60Qx_105){
    X60Qx_104 = NIM_TRUE;}
  else {
    NB8 X60Qx_108 = enumOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_104 = X60Qx_108;}
  if (X60Qx_104){
    X60Qx_103 = NIM_TRUE;}
  else {
    NB8 X60Qx_109 = stringOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_103 = X60Qx_109;}
  if (X60Qx_103){
    X60Qx_102 = NIM_TRUE;}
  else {
    NB8 X60Qx_110 = podOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_102 = X60Qx_110;}
  if (X60Qx_102){
    X60Qx_101 = NIM_TRUE;}
  else {
    NB8 X60Qx_111 = seqOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_101 = X60Qx_111;}
  if (X60Qx_101){
    X60Qx_100 = NIM_TRUE;}
  else {
    NB8 X60Qx_112 = varOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_100 = X60Qx_112;}
  result_11 = X60Qx_100;
  return result_11;}
NB8 retOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_10){
  NB8 result_12;
  if ((*f_10).isComposite_0){
    NB8 X60Qx_113 = compositeOkHere_0_aow7lb5cq1((&(*f_10)));
    result_12 = X60Qx_113;
    return result_12;}
  NB8 X60Qx_114;
  NB8 X60Qx_115;
  NB8 X60Qx_116;
  NB8 X60Qx_117;
  NB8 X60Qx_118;
  NB8 X60Qx_119 = scalarOk_0_aow7lb5cq1((&(*f_10)));
  if (X60Qx_119){
    X60Qx_118 = NIM_TRUE;}
  else {
    NB8 X60Qx_120 = floatOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_118 = X60Qx_120;}
  if (X60Qx_118){
    X60Qx_117 = NIM_TRUE;}
  else {
    NB8 X60Qx_121 = enumOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_117 = X60Qx_121;}
  if (X60Qx_117){
    X60Qx_116 = NIM_TRUE;}
  else {
    NB8 X60Qx_122 = stringOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_116 = X60Qx_122;}
  if (X60Qx_116){
    X60Qx_115 = NIM_TRUE;}
  else {
    NB8 X60Qx_123 = podOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_115 = X60Qx_123;}
  if (X60Qx_115){
    X60Qx_114 = NIM_TRUE;}
  else {
    NB8 X60Qx_124 = seqOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_114 = X60Qx_124;}
  result_12 = X60Qx_114;
  return result_12;}
string_0_sysvq0asl describeShape_0_aow7lb5cq1(WireField_0_run8hsnpi* f_11){
  string_0_sysvq0asl result_13;
  nimStrWasMoved((&result_13));
  string_0_sysvq0asl X60Qx_0;
  nimStrWasMoved((&X60Qx_0));
  if ((*f_11).isString_0){
    nimStrDestroy(X60Qx_0);
    X60Qx_0 = (string_0_sysvq0asl){
      .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
    ;}
  else {
    NB8 X60Qx_125;
    if ((*f_11).isSeq_0){
      X60Qx_125 = (*f_11).elemVarLen_0;}
    else {
      X60Qx_125 = NIM_FALSE;}
    if (X60Qx_125){
      nimStrDestroy(X60Qx_0);
      X60Qx_0 = (string_0_sysvq0asl){
        .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I14729875263638323136_aow7lb5cq1)}
      ;}
    else {
      if ((*f_11).isSeq_0){
        nimStrDestroy(X60Qx_0);
        X60Qx_0 = (string_0_sysvq0asl){
          .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
        ;}
      else {
        if ((*f_11).isArray_0){
          nimStrDestroy(X60Qx_0);
          X60Qx_0 = (string_0_sysvq0asl){
            .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
          ;}
        else {
          if ((*f_11).isPtrArena_0){
            nimStrDestroy(X60Qx_0);
            X60Qx_0 = (string_0_sysvq0asl){
              .bytes_0 = 1920233726u, .more_0 = (&strlit_0_I1511321639927761117_aow7lb5cq1)}
            ;}
          else {
            if ((*f_11).isArenaPtr_0){
              nimStrDestroy(X60Qx_0);
              X60Qx_0 = (string_0_sysvq0asl){
                .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I8953619849411242452_aow7lb5cq1)}
              ;}
            else {
              if ((*f_11).isArenaRef_0){
                nimStrDestroy(X60Qx_0);
                X60Qx_0 = (string_0_sysvq0asl){
                  .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I4979221678562578996_aow7lb5cq1)}
                ;}
              else {
                if ((*f_11).isRef_0){
                  nimStrDestroy(X60Qx_0);
                  X60Qx_0 = (string_0_sysvq0asl){
                    .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
                  ;}
                else {
                  if ((*f_11).isPod_0){
                    nimStrDestroy(X60Qx_0);
                    X60Qx_0 = (string_0_sysvq0asl){
                      .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I1700559883491695059_aow7lb5cq1)}
                    ;}
                  else {
                    if ((*f_11).isEnum_0){
                      nimStrDestroy(X60Qx_0);
                      X60Qx_0 = (string_0_sysvq0asl){
                        .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
                      ;}
                    else {
                      if ((*f_11).desc_0 == NIM_NIL){
                        nimStrDestroy(X60Qx_0);
                        X60Qx_0 = (string_0_sysvq0asl){
                          .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
                        ;}
                      else {
                        string_0_sysvq0asl X60Qx_1;
                        nimStrWasMoved((&X60Qx_1));
                        AbiKind_0_layptix6a1 X60Qx_126 = leafKind_0_aow7lb5cq1((*f_11).desc_0);
                        switch (X60Qx_126){
                          case 2:
                          {
                            nimStrDestroy(X60Qx_1);
                            X60Qx_1 = (string_0_sysvq0asl){
                              .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I11643015150811461308_aow7lb5cq1)}
                            ;}
                          break;
                          case 0:
                          {
                            nimStrDestroy(X60Qx_1);
                            X60Qx_1 = (string_0_sysvq0asl){
                              .bytes_0 = 1953392899u, .more_0 = NIM_NIL}
                            ;}
                          break;
                          case 1:
                          {
                            nimStrDestroy(X60Qx_1);
                            X60Qx_1 = (string_0_sysvq0asl){
                              .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I18357185398770638485_aow7lb5cq1)}
                            ;}
                          break;
                          case 4:
                          {
                            nimStrDestroy(X60Qx_1);
                            X60Qx_1 = (string_0_sysvq0asl){
                              .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
                            ;}
                          break;
                          case 3:
                          {
                            nimStrDestroy(X60Qx_1);
                            X60Qx_1 = (string_0_sysvq0asl){
                              .bytes_0 = 1634231294u, .more_0 = (&strlit_0_I3703322799828345117_aow7lb5cq1)}
                            ;}
                          break;
                          case 5:
                          {
                            nimStrDestroy(X60Qx_1);
                            X60Qx_1 = (string_0_sysvq0asl){
                              .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
                            ;}
                          break;
                          default:
                          {
                            nimStrDestroy(X60Qx_1);
                            X60Qx_1 = (string_0_sysvq0asl){
                              .bytes_0 = 1752461310u, .more_0 = (&strlit_0_I7876088876044165226_aow7lb5cq1)}
                            ;}
                          break;}
                        nimStrDestroy(X60Qx_0);
                        X60Qx_0 = X60Qx_1;
                        nimStrWasMoved((&X60Qx_1));
                        nimStrDestroy(X60Qx_1);}}}}}}}}}}}
  nimStrDestroy(result_13);
  result_13 = X60Qx_0;
  nimStrWasMoved((&X60Qx_0));
  nimStrDestroy(X60Qx_0);
  return result_13;
  nimStrDestroy(X60Qx_0);
  return result_13;}
string_0_sysvq0asl whyNot_0_aow7lb5cq1(WireField_0_run8hsnpi* f_12){
  string_0_sysvq0asl result_14;
  nimStrWasMoved((&result_14));
  NB8 X60Qx_127 = argOk_0_aow7lb5cq1((&(*f_12)));
  if (X60Qx_127){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NB8 X60Qx_128;
  if ((*f_12).isComposite_0){
    X60Qx_128 = (!((*f_12).desc_0 == NIM_NIL));}
  else {
    X60Qx_128 = NIM_FALSE;}
  if (X60Qx_128){
    string_0_sysvq0asl w_0 = compositeWhyNot_1_aow7lb5cq1((*f_12).desc_0, 0);
    string_0_sysvq0asl X60Qx_2;
    nimStrWasMoved((&X60Qx_2));
    NI32 X60Qx_129 = len_4_sysvq0asl(w_0);
    if (0 < X60Qx_129){
      nimStrDestroy(X60Qx_2);
      X60Qx_2 = w_0;
      nimStrWasMoved((&w_0));}
    else {
      nimStrDestroy(X60Qx_2);
      string_0_sysvq0asl X60Qx_130 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I4094444552473946043_aow7lb5cq1)}
      , (string_0_sysvq0asl){
        .bytes_0 = 1970235134u, .more_0 = (&strlit_0_I11608426675167768974_aow7lb5cq1)}
      );
      X60Qx_2 = X60Qx_130;}
    string_0_sysvq0asl X60Qdesugar_0 = X60Qx_2;
    nimStrWasMoved((&X60Qx_2));
    NI32 X60Qx_131 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I8911147075483498441_aow7lb5cq1)}
    );
    NI32 X60Qx_132 = len_4_sysvq0asl((*f_12).srcType_0);
    NI32 X60Qx_133 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2112002u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_134 = len_4_sysvq0asl(X60Qdesugar_0);
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_131 + X60Qx_132)) + X60Qx_133)) + X60Qx_134)));
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I8911147075483498441_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), (*f_12).srcType_0);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 2112002u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), X60Qdesugar_0);
    string_0_sysvq0asl X60Qtmp_0 = X60Qdesugar_1;
    nimStrWasMoved((&X60Qdesugar_1));
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);
    nimStrDestroy(X60Qx_2);
    nimStrDestroy(w_0);
    return X60Qtmp_0;
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);
    nimStrDestroy(X60Qx_2);
    nimStrDestroy(w_0);}
  string_0_sysvq0asl s_2 = describeShape_0_aow7lb5cq1((&(*f_12)));
  if ((*f_12).isVar_0){
    string_0_sysvq0asl X60Qlhs_1 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I8367327255669636523_aow7lb5cq1)}
    , s_2);
    nimStrDestroy(s_2);
    s_2 = X60Qlhs_1;}
  if ((*f_12).isSink_0){
    NI32 X60Qx_135 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I6387641605083911873_aow7lb5cq1)}
    );
    NI32 X60Qx_136 = len_4_sysvq0asl(s_2);
    NI32 X60Qx_137 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I6242563128709086705_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_135 + X60Qx_136)) + X60Qx_137)));
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I6387641605083911873_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_2), s_2);
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I6242563128709086705_aow7lb5cq1)}
    );
    nimStrDestroy(s_2);
    s_2 = X60Qdesugar_2;
    nimStrWasMoved((&X60Qdesugar_2));
    nimStrDestroy(X60Qdesugar_2);}
  string_0_sysvq0asl X60Qdesugar_3 = dollarQ_2_sysvq0asl((*f_12).wireSize_0);
  NI32 X60Qx_138 = len_4_sysvq0asl(s_2);
  NI32 X60Qx_139 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1999118590u, .more_0 = (&strlit_0_I7560857284068051366_aow7lb5cq1)}
  );
  NI32 X60Qx_140 = len_4_sysvq0asl(X60Qdesugar_3);
  NI32 X60Qx_141 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_4 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_138 + X60Qx_139)) + X60Qx_140)) + X60Qx_141)));
  add_2_sysvq0asl((&X60Qdesugar_4), s_2);
  add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
    .bytes_0 = 1999118590u, .more_0 = (&strlit_0_I7560857284068051366_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_4), X60Qdesugar_3);
  add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(result_14);
  result_14 = X60Qdesugar_4;
  nimStrWasMoved((&X60Qdesugar_4));
  nimStrDestroy(X60Qdesugar_4);
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(s_2);
  return result_14;
  nimStrDestroy(X60Qdesugar_4);
  nimStrDestroy(X60Qdesugar_3);
  nimStrDestroy(s_2);
  return result_14;}
NB8 jitEligible_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_0){
  NB8 result_15;
  if (e_0 == NIM_NIL){
    return NIM_FALSE;}
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_0 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_0).d_00.args_0);
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_142 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_142){
          {
            WireField_0_run8hsnpi* X60Qii_2 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_0, X60Qlf_1);
            NB8 X60Qx_143 = argOk_0_aow7lb5cq1((&(*X60Qii_2)));
            if ((!X60Qx_143)){
              return NIM_FALSE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  if ((!(*e_0).d_00.retVoid_0)){
    NB8 X60Qx_144 = retOk_0_aow7lb5cq1((&(*e_0).d_00.ret_0));
    if ((!X60Qx_144)){
      return NIM_FALSE;}}
  result_15 = NIM_TRUE;
  return result_15;}
NB8 jitCShimAttest_0_aow7lb5cq1(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* p_0){
  NB8 result_16;
  result_16 = NIM_FALSE;
  return result_16;}
string_0_sysvq0asl jitDeclineReason_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_1){
  string_0_sysvq0asl result_17;
  nimStrWasMoved((&result_17));
  if (e_1 == NIM_NIL){
    return (string_0_sysvq0asl){
      .bytes_0 = 544173822u, .more_0 = (&strlit_0_I16091381376142210228_aow7lb5cq1)}
    ;}
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_145 = len_3_In63jw61_aow7lb5cq1((*e_1).d_00.args_0);
      if (i_0 < X60Qx_145){
        WireField_0_run8hsnpi* X60Qx_146 = getQ_7_Iko57h9_aow7lb5cq1((*e_1).d_00.args_0, i_0);
        WireField_0_run8hsnpi X60QconstRefTemp_0 = (*X60Qx_146);
        string_0_sysvq0asl w_1 = whyNot_0_aow7lb5cq1((&X60QconstRefTemp_0));
        NI32 X60Qx_147 = len_4_sysvq0asl(w_1);
        if (0 < X60Qx_147){
          string_0_sysvq0asl X60Qdesugar_5 = dollarQ_2_sysvq0asl(i_0);
          NI32 X60Qx_148 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1735549187u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_149 = len_4_sysvq0asl(X60Qdesugar_5);
          NI32 X60Qx_150 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2112002u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_151 = len_4_sysvq0asl(w_1);
          string_0_sysvq0asl X60Qdesugar_6 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_148 + X60Qx_149)) + X60Qx_150)) + X60Qx_151)));
          add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
            .bytes_0 = 1735549187u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_6), X60Qdesugar_5);
          add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
            .bytes_0 = 2112002u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_6), w_1);
          string_0_sysvq0asl X60Qtmp_2 = X60Qdesugar_6;
          nimStrWasMoved((&X60Qdesugar_6));
          nimStrDestroy(X60Qdesugar_6);
          nimStrDestroy(X60Qdesugar_5);
          nimStrDestroy(w_1);
          return X60Qtmp_2;
          nimStrDestroy(X60Qdesugar_6);
          nimStrDestroy(X60Qdesugar_5);}
        inc_1_I6wjjge_aow2h993l1((&i_0));
        nimStrDestroy(w_1);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_152;
  if ((!(*e_1).d_00.retVoid_0)){
    NB8 X60Qx_153 = retOk_0_aow7lb5cq1((&(*e_1).d_00.ret_0));
    X60Qx_152 = (!X60Qx_153);}
  else {
    X60Qx_152 = NIM_FALSE;}
  if (X60Qx_152){
    string_0_sysvq0asl X60Qdesugar_7 = describeShape_0_aow7lb5cq1((&(*e_1).d_00.ret_0));
    string_0_sysvq0asl X60Qdesugar_8 = dollarQ_2_sysvq0asl((*e_1).d_00.ret_0.wireSize_0);
    NI32 X60Qx_154 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I15817754588380596987_aow7lb5cq1)}
    );
    NI32 X60Qx_155 = len_4_sysvq0asl(X60Qdesugar_7);
    NI32 X60Qx_156 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1999118590u, .more_0 = (&strlit_0_I7560857284068051366_aow7lb5cq1)}
    );
    NI32 X60Qx_157 = len_4_sysvq0asl(X60Qdesugar_8);
    NI32 X60Qx_158 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_154 + X60Qx_155)) + X60Qx_156)) + X60Qx_157)) + X60Qx_158)));
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I15817754588380596987_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_9), X60Qdesugar_7);
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 1999118590u, .more_0 = (&strlit_0_I7560857284068051366_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_9), X60Qdesugar_8);
    add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_3 = X60Qdesugar_9;
    nimStrWasMoved((&X60Qdesugar_9));
    nimStrDestroy(X60Qdesugar_9);
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qdesugar_7);
    return X60Qtmp_3;
    nimStrDestroy(X60Qdesugar_9);
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qdesugar_7);}
  nimStrDestroy(result_17);
  result_17 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_17;}
NB8 descHasKind_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_2, AbiKind_0_layptix6a1 want_0, NI32 depth_1){
  NB8 result_18;
  NB8 X60Qx_159;
  if (td_2 == NIM_NIL){
    X60Qx_159 = NIM_TRUE;}
  else {
    X60Qx_159 = (8 < depth_1);}
  if (X60Qx_159){
    return NIM_FALSE;}
  if ((*td_2).d_00.kind_0 == want_0){
    return NIM_TRUE;}
  NB8 X60Qx_160;
  if ((!((*td_2).d_00.elem_0 == NIM_NIL))){
    NB8 X60Qx_161 = descHasKind_0_aow7lb5cq1((*td_2).d_00.elem_0, want_0, ((NI32)(depth_1 + 1)));
    X60Qx_160 = X60Qx_161;}
  else {
    X60Qx_160 = NIM_FALSE;}
  if (X60Qx_160){
    return NIM_TRUE;}
  NI32 i_2 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_162 = len_3_I5m68tr1_aow7lb5cq1((*td_2).d_00.fields_0);
      if (i_2 < X60Qx_162){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_163 = getQ_7_I45w7c91_aow7lb5cq1((*td_2).d_00.fields_0, i_2);
        NB8 X60Qx_164 = descHasKind_0_aow7lb5cq1((*X60Qx_163), want_0, ((NI32)(depth_1 + 1)));
        if (X60Qx_164){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_18 = NIM_FALSE;
  return result_18;}
NB8 fieldHasKind_0_aow7lb5cq1(WireField_0_run8hsnpi* f_13, AbiKind_0_layptix6a1 want_1){
  NB8 result_19;
  NB8 X60Qx_165;
  NB8 X60Qx_166;
  if ((*f_13).isComposite_0){
    X60Qx_166 = (!((*f_13).desc_0 == NIM_NIL));}
  else {
    X60Qx_166 = NIM_FALSE;}
  if (X60Qx_166){
    NB8 X60Qx_167 = descHasKind_0_aow7lb5cq1((*f_13).desc_0, want_1, 0);
    X60Qx_165 = X60Qx_167;}
  else {
    X60Qx_165 = NIM_FALSE;}
  result_19 = X60Qx_165;
  return result_19;}
NB8 usesStrings_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_2){
  NB8 result_20;
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_2 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_2).d_00.args_0);
    NI32 X60Qlf_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_168 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_2);
        if (X60Qlf_3 < X60Qx_168){
          {
            WireField_0_run8hsnpi* X60Qii_2 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_2, X60Qlf_3);
            NB8 X60Qx_169;
            NB8 X60Qx_170 = stringOk_0_aow7lb5cq1((&(*X60Qii_2)));
            if (X60Qx_170){
              X60Qx_169 = NIM_TRUE;}
            else {
              NB8 X60Qx_171 = fieldHasKind_0_aow7lb5cq1((&(*X60Qii_2)), 14);
              X60Qx_169 = X60Qx_171;}
            if (X60Qx_169){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NB8 X60Qx_172;
  if ((!(*e_2).d_00.retVoid_0)){
    NB8 X60Qx_173;
    NB8 X60Qx_174 = stringOk_0_aow7lb5cq1((&(*e_2).d_00.ret_0));
    if (X60Qx_174){
      X60Qx_173 = NIM_TRUE;}
    else {
      NB8 X60Qx_175 = fieldHasKind_0_aow7lb5cq1((&(*e_2).d_00.ret_0), 14);
      X60Qx_173 = X60Qx_175;}
    X60Qx_172 = X60Qx_173;}
  else {
    X60Qx_172 = NIM_FALSE;}
  result_20 = X60Qx_172;
  return result_20;}
NB8 usesSeqs_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_3){
  NB8 result_21;
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_4 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_3).d_00.args_0);
    NI32 X60Qlf_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_176 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_4);
        if (X60Qlf_5 < X60Qx_176){
          {
            WireField_0_run8hsnpi* X60Qii_2 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_4, X60Qlf_5);
            NB8 X60Qx_177;
            NB8 X60Qx_178 = seqOk_0_aow7lb5cq1((&(*X60Qii_2)));
            if (X60Qx_178){
              X60Qx_177 = NIM_TRUE;}
            else {
              NB8 X60Qx_179 = fieldHasKind_0_aow7lb5cq1((&(*X60Qii_2)), 15);
              X60Qx_177 = X60Qx_179;}
            if (X60Qx_177){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NB8 X60Qx_180;
  if ((!(*e_3).d_00.retVoid_0)){
    NB8 X60Qx_181;
    NB8 X60Qx_182 = seqOk_0_aow7lb5cq1((&(*e_3).d_00.ret_0));
    if (X60Qx_182){
      X60Qx_181 = NIM_TRUE;}
    else {
      NB8 X60Qx_183 = fieldHasKind_0_aow7lb5cq1((&(*e_3).d_00.ret_0), 15);
      X60Qx_181 = X60Qx_183;}
    X60Qx_180 = X60Qx_181;}
  else {
    X60Qx_180 = NIM_FALSE;}
  result_21 = X60Qx_180;
  return result_21;}
NB8 hasSub_0_aow7lb5cq1(string_0_sysvq0asl hay_0, string_0_sysvq0asl needle_0){
  NB8 result_22;
  result_22 = NIM_FALSE;
  NB8 X60Qx_184;
  NI32 X60Qx_185 = len_4_sysvq0asl(needle_0);
  if (X60Qx_185 == 0){
    X60Qx_184 = NIM_TRUE;}
  else {
    NI32 X60Qx_186 = len_4_sysvq0asl(hay_0);
    NI32 X60Qx_187 = len_4_sysvq0asl(needle_0);
    X60Qx_184 = (X60Qx_186 < X60Qx_187);}
  if (X60Qx_184){
    return result_22;}
  NI32 i_4 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_188 = len_4_sysvq0asl(needle_0);
      NI32 X60Qx_189 = len_4_sysvq0asl(hay_0);
      if (((NI32)(i_4 + X60Qx_188)) <= X60Qx_189){
        NI32 X60Qx_190 = len_4_sysvq0asl(needle_0);
        HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_191 = ___1_Iclcqmw1_aow7lb5cq1(i_4, ((NI32)(((NI32)(i_4 + X60Qx_190)) - 1)));
        string_0_sysvq0asl X60Qtmp_4 = getQ_14_sysvq0asl(hay_0, X60Qx_191);
        NB8 X60Qx_192 = eqQ_20_sysvq0asl(X60Qtmp_4, needle_0);
        if (X60Qx_192){
          nimStrDestroy(X60Qtmp_4);
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_4));
        nimStrDestroy(X60Qtmp_4);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_22;}
NI32 subAt_0_aow7lb5cq1(string_0_sysvq0asl hay_1, string_0_sysvq0asl needle_1, NI32 start_0){
  NI32 result_23;
  NI32 X60Qx_193 = len_4_sysvq0asl(needle_1);
  if (X60Qx_193 == 0){
    return start_0;}
  NI32 i_5 = start_0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_194 = len_4_sysvq0asl(needle_1);
      NI32 X60Qx_195 = len_4_sysvq0asl(hay_1);
      if (((NI32)(i_5 + X60Qx_194)) <= X60Qx_195){
        NI32 X60Qx_196 = len_4_sysvq0asl(needle_1);
        HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_197 = ___1_Iclcqmw1_aow7lb5cq1(i_5, ((NI32)(((NI32)(i_5 + X60Qx_196)) - 1)));
        string_0_sysvq0asl X60Qtmp_5 = getQ_14_sysvq0asl(hay_1, X60Qx_197);
        NB8 X60Qx_198 = eqQ_20_sysvq0asl(X60Qtmp_5, needle_1);
        if (X60Qx_198){
          nimStrDestroy(X60Qtmp_5);
          return i_5;}
        inc_1_I6wjjge_aow2h993l1((&i_5));
        nimStrDestroy(X60Qtmp_5);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_23 = -1;
  return result_23;}
NB8 isIdentChar_0_aow7lb5cq1(NC8 c_0){
  NB8 result_24;
  NB8 X60Qx_199;
  NB8 X60Qx_200;
  NB8 X60Qx_201;
  NB8 X60Qx_202;
  if ((NC8)'a' <= c_0){
    X60Qx_202 = (c_0 <= (NC8)'z');}
  else {
    X60Qx_202 = NIM_FALSE;}
  if (X60Qx_202){
    X60Qx_201 = NIM_TRUE;}
  else {
    NB8 X60Qx_203;
    if ((NC8)'A' <= c_0){
      X60Qx_203 = (c_0 <= (NC8)'Z');}
    else {
      X60Qx_203 = NIM_FALSE;}
    X60Qx_201 = X60Qx_203;}
  if (X60Qx_201){
    X60Qx_200 = NIM_TRUE;}
  else {
    NB8 X60Qx_204;
    if ((NC8)'0' <= c_0){
      X60Qx_204 = (c_0 <= (NC8)'9');}
    else {
      X60Qx_204 = NIM_FALSE;}
    X60Qx_200 = X60Qx_204;}
  if (X60Qx_200){
    X60Qx_199 = NIM_TRUE;}
  else {
    X60Qx_199 = (c_0 == (NC8)'_');}
  result_24 = X60Qx_199;
  return result_24;}
NB8 lineStartsAtColumn0_0_aow7lb5cq1(string_0_sysvq0asl src_0, NI32 pos_0){
  NB8 result_25;
  NI32 i_6 = pos_0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_205;
      if (0 < i_6){
        NC8 X60Qx_206 = getQ_9_sysvq0asl(src_0, ((NI32)(i_6 - 1)));
        X60Qx_205 = (!(X60Qx_206 == (NC8)'\012'));}
      else {
        X60Qx_205 = NIM_FALSE;}
      if (X60Qx_205){
        dec_1_I0nzoz91_aow7lb5cq1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_207 = len_4_sysvq0asl(src_0);
  if (X60Qx_207 <= i_6){
    return NIM_FALSE;}
  NB8 X60Qx_208;
  NB8 X60Qx_209;
  NB8 X60Qx_210;
  NC8 X60Qx_211 = getQ_9_sysvq0asl(src_0, i_6);
  if ((!(X60Qx_211 == (NC8)' '))){
    NC8 X60Qx_212 = getQ_9_sysvq0asl(src_0, i_6);
    X60Qx_210 = (!(X60Qx_212 == (NC8)'\011'));}
  else {
    X60Qx_210 = NIM_FALSE;}
  if (X60Qx_210){
    NC8 X60Qx_213 = getQ_9_sysvq0asl(src_0, i_6);
    X60Qx_209 = (!(X60Qx_213 == (NC8)'/'));}
  else {
    X60Qx_209 = NIM_FALSE;}
  if (X60Qx_209){
    NC8 X60Qx_214 = getQ_9_sysvq0asl(src_0, i_6);
    X60Qx_208 = (!(X60Qx_214 == (NC8)'#'));}
  else {
    X60Qx_208 = NIM_FALSE;}
  result_25 = X60Qx_208;
  return result_25;}
seq_0_Irn2j6w_aow7lb5cq1 structFields_0_aow7lb5cq1(string_0_sysvq0asl src_2, string_0_sysvq0asl typeName_0){
  seq_0_Irn2j6w_aow7lb5cq1 result_27;
  eQwasMoved_1_I3l7wpx1_aow7lb5cq1((&result_27));
  eQdestroy_1_Iem8q971_aow7lb5cq1(result_27);
  seq_0_Irn2j6w_aow7lb5cq1 X60Qx_249 = newSeqUninit_0_Ifa362m1_aow7lb5cq1(0);
  result_27 = X60Qx_249;
  string_0_sysvq0asl open_0 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
  , typeName_0);
  NI32 i_8 = 0;
  NI32 at_0 = -1;
  {
    while (NIM_TRUE){
      NI32 X60Qx_250 = len_4_sysvq0asl(open_0);
      NI32 X60Qx_251 = len_4_sysvq0asl(src_2);
      if (((NI32)(i_8 + X60Qx_250)) < X60Qx_251){
        NB8 X60Qx_27;
        NC8 X60Qx_252 = getQ_9_sysvq0asl(src_2, i_8);
        if (X60Qx_252 == (NC8)'t'){
          NI32 X60Qx_253 = len_4_sysvq0asl(open_0);
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_254 = ___1_Iclcqmw1_aow7lb5cq1(i_8, ((NI32)(((NI32)(i_8 + X60Qx_253)) - 1)));
          string_0_sysvq0asl X60Qtmp_7 = getQ_14_sysvq0asl(src_2, X60Qx_254);
          NB8 X60Qx_255 = eqQ_20_sysvq0asl(X60Qtmp_7, open_0);
          X60Qx_27 = X60Qx_255;
          nimStrDestroy(X60Qtmp_7);}
        else {
          X60Qx_27 = NIM_FALSE;}
        if (X60Qx_27){
          NI32 X60Qx_256 = len_4_sysvq0asl(open_0);
          NI32 j_1 = ((NI32)(i_8 + X60Qx_256));
          {
            while (NIM_TRUE){
              NB8 X60Qx_257;
              NI32 X60Qx_258 = len_4_sysvq0asl(src_2);
              if (j_1 < X60Qx_258){
                NB8 X60Qx_259;
                NC8 X60Qx_260 = getQ_9_sysvq0asl(src_2, j_1);
                if (X60Qx_260 == (NC8)' '){
                  X60Qx_259 = NIM_TRUE;}
                else {
                  NC8 X60Qx_261 = getQ_9_sysvq0asl(src_2, j_1);
                  X60Qx_259 = (X60Qx_261 == ((NC8)9));}
                X60Qx_257 = X60Qx_259;}
              else {
                X60Qx_257 = NIM_FALSE;}
              if (X60Qx_257){
                inc_1_I6wjjge_aow2h993l1((&j_1));}
              else {
                break;}}}
          whileStmtLabel_1: ;
          NB8 X60Qx_262;
          NI32 X60Qx_263 = len_4_sysvq0asl(src_2);
          if (j_1 < X60Qx_263){
            NC8 X60Qx_264 = getQ_9_sysvq0asl(src_2, j_1);
            X60Qx_262 = (X60Qx_264 == (NC8)'{');}
          else {
            X60Qx_262 = NIM_FALSE;}
          if (X60Qx_262){
            at_0 = ((NI32)(j_1 + 1));
            goto whileStmtLabel_0;}}
        inc_1_I6wjjge_aow2h993l1((&i_8));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (at_0 < 0){
    seq_0_Irn2j6w_aow7lb5cq1 X60Qx_265 = newSeqUninit_0_Ifa362m1_aow7lb5cq1(0);
    result_27 = X60Qx_265;
    nimStrDestroy(open_0);
    return result_27;}
  string_0_sysvq0asl cur_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 j_2 = at_0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_266 = len_4_sysvq0asl(src_2);
      if (j_2 < X60Qx_266){
        NC8 c_1 = getQ_9_sysvq0asl(src_2, j_2);
        if (c_1 == (NC8)'}'){
          goto whileStmtLabel_2;}
        if (c_1 == (NC8)';'){
          seq_0_Ixdx2fh1_aow7lb5cq1 toks_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
          string_0_sysvq0asl t_1 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          {
            openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_6 = toOpenArray_2_sysvq0asl((&cur_0));
            NI32 X60Qlf_7 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_267 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_6);
                if (X60Qlf_7 < X60Qx_267){
                  {
                    NC8* X60Qii_5 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_6, X60Qlf_7);
                    NB8 X60Qx_268;
                    NB8 X60Qx_269;
                    NB8 X60Qx_270;
                    if ((*X60Qii_5) == (NC8)' '){
                      X60Qx_270 = NIM_TRUE;}
                    else {
                      X60Qx_270 = ((*X60Qii_5) == ((NC8)10));}
                    if (X60Qx_270){
                      X60Qx_269 = NIM_TRUE;}
                    else {
                      X60Qx_269 = ((*X60Qii_5) == ((NC8)9));}
                    if (X60Qx_269){
                      X60Qx_268 = NIM_TRUE;}
                    else {
                      X60Qx_268 = ((*X60Qii_5) == ((NC8)13));}
                    if (X60Qx_268){
                      NI32 X60Qx_271 = len_4_sysvq0asl(t_1);
                      if (0 < X60Qx_271){
                        string_0_sysvq0asl X60Qtmp_8 = t_1;
                        nimStrWasMoved((&t_1));
                        add_0_Ig6072n_aow7lb5cq1((&toks_0), X60Qtmp_8);}
                      nimStrDestroy(t_1);
                      t_1 = (string_0_sysvq0asl){
                        .bytes_0 = 0u, .more_0 = NIM_NIL}
                      ;}
                    else {
                      add_1_sysvq0asl((&t_1), (*X60Qii_5));}}
                  inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
                else {
                  break;}}}
            whileStmtLabel_4: ;}
          forStmtLabel_3: ;
          NI32 X60Qx_272 = len_4_sysvq0asl(t_1);
          if (0 < X60Qx_272){
            string_0_sysvq0asl X60Qtmp_9 = t_1;
            nimStrWasMoved((&t_1));
            add_0_Ig6072n_aow7lb5cq1((&toks_0), X60Qtmp_9);}
          if (2 <= toks_0.len_0){
            string_0_sysvq0asl ty_1 = (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            ;
            NI32 k_0 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_273 = len_3_Ixq6taz_aow7lb5cq1(toks_0);
                if (k_0 < ((NI32)(X60Qx_273 - 1))){
                  NI32 X60Qx_274 = len_4_sysvq0asl(ty_1);
                  if (0 < X60Qx_274){
                    add_1_sysvq0asl((&ty_1), (NC8)' ');}
                  string_0_sysvq0asl* X60Qx_275 = getQ_7_Ir6d0tw_aow7lb5cq1(toks_0, k_0);
                  add_2_sysvq0asl((&ty_1), (*X60Qx_275));
                  inc_1_I6wjjge_aow2h993l1((&k_0));}
                else {
                  break;}}}
            whileStmtLabel_6: ;
            string_0_sysvq0asl X60Qtmp_10 = ty_1;
            nimStrWasMoved((&ty_1));
            NI32 X60Qx_276 = len_3_Ixq6taz_aow7lb5cq1(toks_0);
            string_0_sysvq0asl* X60Qx_277 = getQ_7_Ir6d0tw_aow7lb5cq1(toks_0, ((NI32)(X60Qx_276 - 1)));
            string_0_sysvq0asl X60Qx_28 = nimStrDup((*X60Qx_277));
            add_0_I1xop2a1_aow7lb5cq1((&result_27), (X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1){
              .fld_0 = X60Qtmp_10, .fld_1 = X60Qx_28}
            );
            nimStrDestroy(ty_1);}
          nimStrDestroy(cur_0);
          cur_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          nimStrDestroy(t_1);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(toks_0);}
        else {
          add_1_sysvq0asl((&cur_0), c_1);}
        inc_1_I6wjjge_aow2h993l1((&j_2));}
      else {
        break;}}}
  whileStmtLabel_2: ;
  nimStrDestroy(cur_0);
  nimStrDestroy(open_0);
  return result_27;
  nimStrDestroy(cur_0);
  nimStrDestroy(open_0);
  return result_27;}
string_0_sysvq0asl seqElemCType_0_aow7lb5cq1(string_0_sysvq0asl unit_0, string_0_sysvq0asl seqCty_0){
  string_0_sysvq0asl result_28;
  nimStrWasMoved((&result_28));
  nimStrDestroy(result_28);
  result_28 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  seq_0_Irn2j6w_aow7lb5cq1 flds_0 = structFields_0_aow7lb5cq1(unit_0, seqCty_0);
  NI32 i_10 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_278 = len_3_Ijhqs0r1_aow7lb5cq1(flds_0);
      if (i_10 < X60Qx_278){
        X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_279 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_0, i_10);
        NB8 X60Qx_280 = eqQ_20_sysvq0asl((*X60Qx_279).fld_1, (string_0_sysvq0asl){
          .bytes_0 = 1952539902u, .more_0 = (&strlit_0_I16904210374251152424_aow7lb5cq1)}
        );
        if (X60Qx_280){
          X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_281 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_0, i_10);
          string_0_sysvq0asl t_2 = nimStrDup((*X60Qx_281).fld_0);
          NB8 X60Qx_282;
          NI32 X60Qx_283 = len_4_sysvq0asl(t_2);
          if (2 <= X60Qx_283){
            NI32 X60Qx_284 = len_4_sysvq0asl(t_2);
            NC8 X60Qx_285 = getQ_9_sysvq0asl(t_2, ((NI32)(X60Qx_284 - 1)));
            X60Qx_282 = (X60Qx_285 == (NC8)'*');}
          else {
            X60Qx_282 = NIM_FALSE;}
          if (X60Qx_282){
            nimStrDestroy(result_28);
            NI32 X60Qx_286 = len_4_sysvq0asl(t_2);
            HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_287 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_286 - 2)));
            string_0_sysvq0asl X60Qx_288 = getQ_14_sysvq0asl(t_2, X60Qx_287);
            result_28 = X60Qx_288;}
          nimStrDestroy(t_2);
          eQdestroy_1_Iem8q971_aow7lb5cq1(flds_0);
          return result_28;
          nimStrDestroy(t_2);}
        inc_1_I6wjjge_aow2h993l1((&i_10));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Iem8q971_aow7lb5cq1(flds_0);
  return result_28;
  eQdestroy_1_Iem8q971_aow7lb5cq1(flds_0);
  return result_28;}
NB8 definesExactly_0_aow7lb5cq1(string_0_sysvq0asl src_3, string_0_sysvq0asl name_0){
  NB8 result_29;
  result_29 = NIM_FALSE;
  NI32 n_2 = len_4_sysvq0asl(name_0);
  NB8 X60Qx_289;
  if (n_2 == 0){
    X60Qx_289 = NIM_TRUE;}
  else {
    NI32 X60Qx_290 = len_4_sysvq0asl(src_3);
    X60Qx_289 = (X60Qx_290 == 0);}
  if (X60Qx_289){
    return result_29;}
  NI32 i_12 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_291 = len_4_sysvq0asl(src_3);
      if (((NI32)(i_12 + n_2)) < X60Qx_291){
        NB8 X60Qx_29;
        NB8 X60Qx_30;
        NB8 X60Qx_31;
        NB8 X60Qx_292;
        NC8 X60Qx_293 = getQ_9_sysvq0asl(src_3, i_12);
        NC8 X60Qx_294 = getQ_9_sysvq0asl(name_0, 0);
        if (X60Qx_293 == X60Qx_294){
          NB8 X60Qx_295;
          if (i_12 == 0){
            X60Qx_295 = NIM_TRUE;}
          else {
            NC8 X60Qx_296 = getQ_9_sysvq0asl(src_3, ((NI32)(i_12 - 1)));
            NB8 X60Qx_297 = isIdentChar_0_aow7lb5cq1(X60Qx_296);
            X60Qx_295 = (!X60Qx_297);}
          X60Qx_292 = X60Qx_295;}
        else {
          X60Qx_292 = NIM_FALSE;}
        if (X60Qx_292){
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_298 = ___1_Iclcqmw1_aow7lb5cq1(i_12, ((NI32)(((NI32)(i_12 + n_2)) - 1)));
          string_0_sysvq0asl X60Qtmp_11 = getQ_14_sysvq0asl(src_3, X60Qx_298);
          NB8 X60Qx_299 = eqQ_20_sysvq0asl(X60Qtmp_11, name_0);
          X60Qx_31 = X60Qx_299;
          nimStrDestroy(X60Qtmp_11);}
        else {
          X60Qx_31 = NIM_FALSE;}
        if (X60Qx_31){
          NC8 X60Qx_300 = getQ_9_sysvq0asl(src_3, ((NI32)(i_12 + n_2)));
          X60Qx_30 = (X60Qx_300 == (NC8)'(');}
        else {
          X60Qx_30 = NIM_FALSE;}
        if (X60Qx_30){
          NB8 X60Qx_301 = lineStartsAtColumn0_0_aow7lb5cq1(src_3, i_12);
          X60Qx_29 = X60Qx_301;}
        else {
          X60Qx_29 = NIM_FALSE;}
        if (X60Qx_29){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_12));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_29;}
seq_0_Ixdx2fh1_aow7lb5cq1 mangledNamesFor_0_aow7lb5cq1(string_0_sysvq0asl src_4, string_0_sysvq0asl base_1){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_30;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_30));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_30);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_302 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_30 = X60Qx_302;
  NI32 n_3 = len_4_sysvq0asl(base_1);
  NB8 X60Qx_303;
  if (n_3 == 0){
    X60Qx_303 = NIM_TRUE;}
  else {
    NI32 X60Qx_304 = len_4_sysvq0asl(src_4);
    X60Qx_303 = (X60Qx_304 == 0);}
  if (X60Qx_303){
    return result_30;}
  NI32 i_13 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_305 = len_4_sysvq0asl(src_4);
      if (((NI32)(i_13 + n_3)) < X60Qx_305){
        NB8 X60Qx_32;
        NB8 X60Qx_306;
        NC8 X60Qx_307 = getQ_9_sysvq0asl(src_4, i_13);
        NC8 X60Qx_308 = getQ_9_sysvq0asl(base_1, 0);
        if (X60Qx_307 == X60Qx_308){
          NB8 X60Qx_309;
          if (i_13 == 0){
            X60Qx_309 = NIM_TRUE;}
          else {
            NC8 X60Qx_310 = getQ_9_sysvq0asl(src_4, ((NI32)(i_13 - 1)));
            NB8 X60Qx_311 = isIdentChar_0_aow7lb5cq1(X60Qx_310);
            X60Qx_309 = (!X60Qx_311);}
          X60Qx_306 = X60Qx_309;}
        else {
          X60Qx_306 = NIM_FALSE;}
        if (X60Qx_306){
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_312 = ___1_Iclcqmw1_aow7lb5cq1(i_13, ((NI32)(((NI32)(i_13 + n_3)) - 1)));
          string_0_sysvq0asl X60Qtmp_12 = getQ_14_sysvq0asl(src_4, X60Qx_312);
          NB8 X60Qx_313 = eqQ_20_sysvq0asl(X60Qtmp_12, base_1);
          X60Qx_32 = X60Qx_313;
          nimStrDestroy(X60Qtmp_12);}
        else {
          X60Qx_32 = NIM_FALSE;}
        if (X60Qx_32){
          NI32 j_3 = ((NI32)(i_13 + n_3));
          NB8 X60Qx_314;
          NI32 X60Qx_315 = len_4_sysvq0asl(src_4);
          if (j_3 < X60Qx_315){
            NC8 X60Qx_316 = getQ_9_sysvq0asl(src_4, j_3);
            X60Qx_314 = (X60Qx_316 == (NC8)'_');}
          else {
            X60Qx_314 = NIM_FALSE;}
          if (X60Qx_314){
            inc_1_I6wjjge_aow2h993l1((&j_3));
            NI32 digits_1 = 0;
            {
              while (NIM_TRUE){
                NB8 X60Qx_317;
                NB8 X60Qx_318;
                NI32 X60Qx_319 = len_4_sysvq0asl(src_4);
                if (j_3 < X60Qx_319){
                  NC8 X60Qx_320 = getQ_9_sysvq0asl(src_4, j_3);
                  X60Qx_318 = ((NC8)'0' <= X60Qx_320);}
                else {
                  X60Qx_318 = NIM_FALSE;}
                if (X60Qx_318){
                  NC8 X60Qx_321 = getQ_9_sysvq0asl(src_4, j_3);
                  X60Qx_317 = (X60Qx_321 <= (NC8)'9');}
                else {
                  X60Qx_317 = NIM_FALSE;}
                if (X60Qx_317){
                  inc_1_I6wjjge_aow2h993l1((&j_3));
                  inc_1_I6wjjge_aow2h993l1((&digits_1));}
                else {
                  break;}}}
            whileStmtLabel_1: ;
            NB8 X60Qx_322;
            NB8 X60Qx_323;
            if (0 < digits_1){
              NI32 X60Qx_324 = len_4_sysvq0asl(src_4);
              X60Qx_323 = (j_3 < X60Qx_324);}
            else {
              X60Qx_323 = NIM_FALSE;}
            if (X60Qx_323){
              NC8 X60Qx_325 = getQ_9_sysvq0asl(src_4, j_3);
              X60Qx_322 = (X60Qx_325 == (NC8)'_');}
            else {
              X60Qx_322 = NIM_FALSE;}
            if (X60Qx_322){
              inc_1_I6wjjge_aow2h993l1((&j_3));
              {
                while (NIM_TRUE){
                  NB8 X60Qx_326;
                  NI32 X60Qx_327 = len_4_sysvq0asl(src_4);
                  if (j_3 < X60Qx_327){
                    NC8 X60Qx_328 = getQ_9_sysvq0asl(src_4, j_3);
                    NB8 X60Qx_329 = isIdentChar_0_aow7lb5cq1(X60Qx_328);
                    X60Qx_326 = X60Qx_329;}
                  else {
                    X60Qx_326 = NIM_FALSE;}
                  if (X60Qx_326){
                    inc_1_I6wjjge_aow2h993l1((&j_3));}
                  else {
                    break;}}}
              whileStmtLabel_2: ;
              NB8 X60Qx_330;
              NB8 X60Qx_331;
              NI32 X60Qx_332 = len_4_sysvq0asl(src_4);
              if (j_3 < X60Qx_332){
                NC8 X60Qx_333 = getQ_9_sysvq0asl(src_4, j_3);
                X60Qx_331 = (X60Qx_333 == (NC8)'(');}
              else {
                X60Qx_331 = NIM_FALSE;}
              if (X60Qx_331){
                NB8 X60Qx_334 = lineStartsAtColumn0_0_aow7lb5cq1(src_4, i_13);
                X60Qx_330 = X60Qx_334;}
              else {
                X60Qx_330 = NIM_FALSE;}
              if (X60Qx_330){
                HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_335 = ___1_Iclcqmw1_aow7lb5cq1(i_13, ((NI32)(j_3 - 1)));
                string_0_sysvq0asl nm_0 = getQ_14_sysvq0asl(src_4, X60Qx_335);
                NB8 dup_0 = NIM_FALSE;
                {
                  openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_8 = toOpenArray_1_I6b60gk1_aow7lb5cq1(result_30);
                  NI32 X60Qlf_9 = 0;
                  {
                    while (NIM_TRUE){
                      NI32 X60Qx_336 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_8);
                      if (X60Qlf_9 < X60Qx_336){
                        {
                          string_0_sysvq0asl* X60Qii_5 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_8, X60Qlf_9);
                          NB8 X60Qx_337 = eqQ_20_sysvq0asl((*X60Qii_5), nm_0);
                          if (X60Qx_337){
                            dup_0 = NIM_TRUE;
                            goto forStmtLabel_3;}}
                        inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}
                      else {
                        break;}}}
                  whileStmtLabel_4: ;}
                forStmtLabel_3: ;
                if ((!dup_0)){
                  string_0_sysvq0asl X60Qtmp_13 = nm_0;
                  nimStrWasMoved((&nm_0));
                  add_0_Ig6072n_aow7lb5cq1((&result_30), X60Qtmp_13);}
                nimStrDestroy(nm_0);}}}}
        inc_1_I6wjjge_aow2h993l1((&i_13));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_30;}
string_0_sysvq0asl trimC_0_aow7lb5cq1(string_0_sysvq0asl s_0){
  string_0_sysvq0asl result_31;
  nimStrWasMoved((&result_31));
  NI32 a_7 = 0;
  NI32 X60Qx_338 = len_4_sysvq0asl(s_0);
  NI32 b_1 = ((NI32)(X60Qx_338 - 1));
  {
    while (NIM_TRUE){
      NB8 X60Qx_339;
      if (a_7 <= b_1){
        NB8 X60Qx_340;
        NB8 X60Qx_341;
        NC8 X60Qx_342 = getQ_9_sysvq0asl(s_0, a_7);
        if (X60Qx_342 == (NC8)' '){
          X60Qx_341 = NIM_TRUE;}
        else {
          NC8 X60Qx_343 = getQ_9_sysvq0asl(s_0, a_7);
          X60Qx_341 = (X60Qx_343 == (NC8)'\012');}
        if (X60Qx_341){
          X60Qx_340 = NIM_TRUE;}
        else {
          NC8 X60Qx_344 = getQ_9_sysvq0asl(s_0, a_7);
          X60Qx_340 = (X60Qx_344 == (NC8)'\011');}
        X60Qx_339 = X60Qx_340;}
      else {
        X60Qx_339 = NIM_FALSE;}
      if (X60Qx_339){
        inc_1_I6wjjge_aow2h993l1((&a_7));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  {
    while (NIM_TRUE){
      NB8 X60Qx_345;
      if (a_7 <= b_1){
        NB8 X60Qx_346;
        NB8 X60Qx_347;
        NC8 X60Qx_348 = getQ_9_sysvq0asl(s_0, b_1);
        if (X60Qx_348 == (NC8)' '){
          X60Qx_347 = NIM_TRUE;}
        else {
          NC8 X60Qx_349 = getQ_9_sysvq0asl(s_0, b_1);
          X60Qx_347 = (X60Qx_349 == (NC8)'\012');}
        if (X60Qx_347){
          X60Qx_346 = NIM_TRUE;}
        else {
          NC8 X60Qx_350 = getQ_9_sysvq0asl(s_0, b_1);
          X60Qx_346 = (X60Qx_350 == (NC8)'\011');}
        X60Qx_345 = X60Qx_346;}
      else {
        X60Qx_345 = NIM_FALSE;}
      if (X60Qx_345){
        dec_1_I0nzoz91_aow7lb5cq1((&b_1));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  string_0_sysvq0asl X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  if (b_1 < a_7){
    nimStrDestroy(X60Qx_3);
    X60Qx_3 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  else {
    nimStrDestroy(X60Qx_3);
    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_351 = ___1_Iclcqmw1_aow7lb5cq1(a_7, b_1);
    string_0_sysvq0asl X60Qx_352 = getQ_14_sysvq0asl(s_0, X60Qx_351);
    X60Qx_3 = X60Qx_352;}
  nimStrDestroy(result_31);
  result_31 = X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  nimStrDestroy(X60Qx_3);
  return result_31;
  nimStrDestroy(X60Qx_3);
  return result_31;}
string_0_sysvq0asl paramTypeOf_0_aow7lb5cq1(string_0_sysvq0asl decl_0){
  string_0_sysvq0asl result_32;
  nimStrWasMoved((&result_32));
  string_0_sysvq0asl d_0 = trimC_0_aow7lb5cq1(decl_0);
  NI32 X60Qx_353 = len_4_sysvq0asl(d_0);
  if (X60Qx_353 == 0){
    nimStrDestroy(d_0);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NB8 X60Qx_354 = eqQ_20_sysvq0asl(d_0, (string_0_sysvq0asl){
    .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
  );
  if (X60Qx_354){
    nimStrDestroy(d_0);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 X60Qx_355 = len_4_sysvq0asl(d_0);
  NI32 j_4 = ((NI32)(X60Qx_355 - 1));
  {
    while (NIM_TRUE){
      NB8 X60Qx_356;
      if (0 <= j_4){
        NC8 X60Qx_357 = getQ_9_sysvq0asl(d_0, j_4);
        NB8 X60Qx_358 = isIdentChar_0_aow7lb5cq1(X60Qx_357);
        X60Qx_356 = X60Qx_358;}
      else {
        X60Qx_356 = NIM_FALSE;}
      if (X60Qx_356){
        dec_1_I0nzoz91_aow7lb5cq1((&j_4));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (j_4 < 0){
    string_0_sysvq0asl X60Qtmp_14 = d_0;
    nimStrWasMoved((&d_0));
    nimStrDestroy(d_0);
    return X60Qtmp_14;}
  nimStrDestroy(result_32);
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_359 = ___1_Iclcqmw1_aow7lb5cq1(0, j_4);
  string_0_sysvq0asl X60Qtmp_15 = getQ_14_sysvq0asl(d_0, X60Qx_359);
  string_0_sysvq0asl X60Qx_360 = trimC_0_aow7lb5cq1(X60Qtmp_15);
  result_32 = X60Qx_360;
  nimStrDestroy(X60Qtmp_15);
  nimStrDestroy(d_0);
  return result_32;
  nimStrDestroy(X60Qtmp_15);
  nimStrDestroy(d_0);
  return result_32;}
string_0_sysvq0asl lastToken_0_aow7lb5cq1(string_0_sysvq0asl s_1){
  string_0_sysvq0asl result_33;
  nimStrWasMoved((&result_33));
  string_0_sysvq0asl t_3 = trimC_0_aow7lb5cq1(s_1);
  NI32 X60Qx_361 = len_4_sysvq0asl(t_3);
  NI32 j_5 = ((NI32)(X60Qx_361 - 1));
  {
    while (NIM_TRUE){
      NB8 X60Qx_362;
      NB8 X60Qx_363;
      if (0 <= j_5){
        NC8 X60Qx_364 = getQ_9_sysvq0asl(t_3, j_5);
        X60Qx_363 = (!(X60Qx_364 == (NC8)' '));}
      else {
        X60Qx_363 = NIM_FALSE;}
      if (X60Qx_363){
        NC8 X60Qx_365 = getQ_9_sysvq0asl(t_3, j_5);
        X60Qx_362 = (!(X60Qx_365 == (NC8)'\011'));}
      else {
        X60Qx_362 = NIM_FALSE;}
      if (X60Qx_362){
        dec_1_I0nzoz91_aow7lb5cq1((&j_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(result_33);
  NI32 X60Qx_366 = len_4_sysvq0asl(t_3);
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_367 = ___1_Iclcqmw1_aow7lb5cq1(((NI32)(j_5 + 1)), ((NI32)(X60Qx_366 - 1)));
  string_0_sysvq0asl X60Qx_368 = getQ_14_sysvq0asl(t_3, X60Qx_367);
  result_33 = X60Qx_368;
  nimStrDestroy(t_3);
  return result_33;
  nimStrDestroy(t_3);
  return result_33;}
CSig_0_aow7lb5cq1 sigOf_0_aow7lb5cq1(string_0_sysvq0asl src_5, string_0_sysvq0asl mangled_0){
  CSig_0_aow7lb5cq1 result_34;
  eQwasmovedQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1((&result_34));
  eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(result_34);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_369 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_34 = (CSig_0_aow7lb5cq1){
    .ok_0 = NIM_FALSE, .ret_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .params_0 = X60Qx_369}
  ;
  NI32 n_4 = len_4_sysvq0asl(mangled_0);
  if (n_4 == 0){
    return result_34;}
  NI32 i_14 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_370 = len_4_sysvq0asl(src_5);
      if (((NI32)(i_14 + n_4)) < X60Qx_370){
        NB8 X60Qx_33;
        NB8 X60Qx_34;
        NB8 X60Qx_35;
        NB8 X60Qx_371;
        NC8 X60Qx_372 = getQ_9_sysvq0asl(src_5, i_14);
        NC8 X60Qx_373 = getQ_9_sysvq0asl(mangled_0, 0);
        if (X60Qx_372 == X60Qx_373){
          NB8 X60Qx_374;
          if (i_14 == 0){
            X60Qx_374 = NIM_TRUE;}
          else {
            NC8 X60Qx_375 = getQ_9_sysvq0asl(src_5, ((NI32)(i_14 - 1)));
            NB8 X60Qx_376 = isIdentChar_0_aow7lb5cq1(X60Qx_375);
            X60Qx_374 = (!X60Qx_376);}
          X60Qx_371 = X60Qx_374;}
        else {
          X60Qx_371 = NIM_FALSE;}
        if (X60Qx_371){
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_377 = ___1_Iclcqmw1_aow7lb5cq1(i_14, ((NI32)(((NI32)(i_14 + n_4)) - 1)));
          string_0_sysvq0asl X60Qtmp_16 = getQ_14_sysvq0asl(src_5, X60Qx_377);
          NB8 X60Qx_378 = eqQ_20_sysvq0asl(X60Qtmp_16, mangled_0);
          X60Qx_35 = X60Qx_378;
          nimStrDestroy(X60Qtmp_16);}
        else {
          X60Qx_35 = NIM_FALSE;}
        if (X60Qx_35){
          NC8 X60Qx_379 = getQ_9_sysvq0asl(src_5, ((NI32)(i_14 + n_4)));
          X60Qx_34 = (X60Qx_379 == (NC8)'(');}
        else {
          X60Qx_34 = NIM_FALSE;}
        if (X60Qx_34){
          NB8 X60Qx_380 = lineStartsAtColumn0_0_aow7lb5cq1(src_5, i_14);
          X60Qx_33 = X60Qx_380;}
        else {
          X60Qx_33 = NIM_FALSE;}
        if (X60Qx_33){
          NI32 ls_0 = i_14;
          {
            while (NIM_TRUE){
              NB8 X60Qx_381;
              if (0 < ls_0){
                NC8 X60Qx_382 = getQ_9_sysvq0asl(src_5, ((NI32)(ls_0 - 1)));
                X60Qx_381 = (!(X60Qx_382 == (NC8)'\012'));}
              else {
                X60Qx_381 = NIM_FALSE;}
              if (X60Qx_381){
                dec_1_I0nzoz91_aow7lb5cq1((&ls_0));}
              else {
                break;}}}
          whileStmtLabel_1: ;
          string_0_sysvq0asl* X60Qlhs_17 = (&result_34.ret_0);
          nimStrDestroy((*X60Qlhs_17));
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_383 = ___1_Iclcqmw1_aow7lb5cq1(ls_0, ((NI32)(i_14 - 1)));
          string_0_sysvq0asl X60Qtmp_18 = getQ_14_sysvq0asl(src_5, X60Qx_383);
          string_0_sysvq0asl X60Qx_384 = lastToken_0_aow7lb5cq1(X60Qtmp_18);
          (*X60Qlhs_17) = X60Qx_384;
          NI32 X60Qx_385 = len_4_sysvq0asl(result_34.ret_0);
          if (X60Qx_385 == 0){
            string_0_sysvq0asl* X60Qlhs_19 = (&result_34.ret_0);
            nimStrDestroy((*X60Qlhs_19));
            (*X60Qlhs_19) = (string_0_sysvq0asl){
              .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
            ;}
          NI32 j_6 = ((NI32)(((NI32)(i_14 + n_4)) + 1));
          NI32 depth_4 = 0;
          string_0_sysvq0asl cur_1 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          {
            while (NIM_TRUE){
              NI32 X60Qx_386 = len_4_sysvq0asl(src_5);
              if (j_6 < X60Qx_386){
                NC8 c_2 = getQ_9_sysvq0asl(src_5, j_6);
                if (c_2 == (NC8)'('){
                  inc_1_I6wjjge_aow2h993l1((&depth_4));
                  add_1_sysvq0asl((&cur_1), c_2);}
                else {
                  if (c_2 == (NC8)')'){
                    if (depth_4 == 0){
                      string_0_sysvq0asl t_4 = paramTypeOf_0_aow7lb5cq1(cur_1);
                      NI32 X60Qx_387 = len_4_sysvq0asl(t_4);
                      if (0 < X60Qx_387){
                        string_0_sysvq0asl X60Qtmp_20 = t_4;
                        nimStrWasMoved((&t_4));
                        add_0_Ig6072n_aow7lb5cq1((&result_34.params_0), X60Qtmp_20);}
                      else {
                        NB8 X60Qx_36;
                        string_0_sysvq0asl X60Qtmp_21 = trimC_0_aow7lb5cq1(cur_1);
                        NI32 X60Qx_388 = len_4_sysvq0asl(X60Qtmp_21);
                        if (0 < X60Qx_388){
                          string_0_sysvq0asl X60Qtmp_22 = trimC_0_aow7lb5cq1(cur_1);
                          NB8 X60Qx_389 = eqQ_20_sysvq0asl(X60Qtmp_22, (string_0_sysvq0asl){
                            .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
                          );
                          X60Qx_36 = (!X60Qx_389);
                          nimStrDestroy(X60Qtmp_22);}
                        else {
                          X60Qx_36 = NIM_FALSE;}
                        if (X60Qx_36){
                          nimStrDestroy(X60Qtmp_21);
                          nimStrDestroy(t_4);
                          nimStrDestroy(cur_1);
                          nimStrDestroy(X60Qtmp_18);
                          return result_34;}
                        nimStrDestroy(X60Qtmp_21);}
                      result_34.ok_0 = NIM_TRUE;
                      nimStrDestroy(t_4);
                      nimStrDestroy(cur_1);
                      nimStrDestroy(X60Qtmp_18);
                      return result_34;
                      nimStrDestroy(t_4);}
                    dec_1_I0nzoz91_aow7lb5cq1((&depth_4));
                    add_1_sysvq0asl((&cur_1), c_2);}
                  else {
                    NB8 X60Qx_390;
                    if (c_2 == (NC8)','){
                      X60Qx_390 = (depth_4 == 0);}
                    else {
                      X60Qx_390 = NIM_FALSE;}
                    if (X60Qx_390){
                      string_0_sysvq0asl t_5 = paramTypeOf_0_aow7lb5cq1(cur_1);
                      NI32 X60Qx_391 = len_4_sysvq0asl(t_5);
                      if (X60Qx_391 == 0){
                        nimStrDestroy(t_5);
                        nimStrDestroy(cur_1);
                        nimStrDestroy(X60Qtmp_18);
                        return result_34;}
                      string_0_sysvq0asl X60Qtmp_23 = t_5;
                      nimStrWasMoved((&t_5));
                      add_0_Ig6072n_aow7lb5cq1((&result_34.params_0), X60Qtmp_23);
                      nimStrDestroy(cur_1);
                      cur_1 = (string_0_sysvq0asl){
                        .bytes_0 = 0u, .more_0 = NIM_NIL}
                      ;
                      nimStrDestroy(t_5);}
                    else {
                      if (c_2 == (NC8)'\012'){
                        nimStrDestroy(cur_1);
                        nimStrDestroy(X60Qtmp_18);
                        return result_34;}
                      else {
                        add_1_sysvq0asl((&cur_1), c_2);}}}}
                inc_1_I6wjjge_aow2h993l1((&j_6));}
              else {
                break;}}}
          whileStmtLabel_2: ;
          nimStrDestroy(cur_1);
          nimStrDestroy(X60Qtmp_18);
          return result_34;
          nimStrDestroy(cur_1);
          nimStrDestroy(X60Qtmp_18);}
        inc_1_I6wjjge_aow2h993l1((&i_14));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_34;}
string_0_sysvq0asl derefType_0_aow7lb5cq1(string_0_sysvq0asl t_0){
  string_0_sysvq0asl result_35;
  nimStrWasMoved((&result_35));
  string_0_sysvq0asl s_15 = trimC_0_aow7lb5cq1(t_0);
  NB8 X60Qx_392;
  NI32 X60Qx_393 = len_4_sysvq0asl(s_15);
  if (0 < X60Qx_393){
    NI32 X60Qx_394 = len_4_sysvq0asl(s_15);
    NC8 X60Qx_395 = getQ_9_sysvq0asl(s_15, ((NI32)(X60Qx_394 - 1)));
    X60Qx_392 = (X60Qx_395 == (NC8)'*');}
  else {
    X60Qx_392 = NIM_FALSE;}
  if (X60Qx_392){
    nimStrDestroy(result_35);
    NI32 X60Qx_396 = len_4_sysvq0asl(s_15);
    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_397 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_396 - 2)));
    string_0_sysvq0asl X60Qtmp_24 = getQ_14_sysvq0asl(s_15, X60Qx_397);
    string_0_sysvq0asl X60Qx_398 = trimC_0_aow7lb5cq1(X60Qtmp_24);
    result_35 = X60Qx_398;
    nimStrDestroy(X60Qtmp_24);}
  else {
    nimStrDestroy(result_35);
    result_35 = s_15;
    nimStrWasMoved((&s_15));}
  nimStrDestroy(s_15);
  return result_35;
  nimStrDestroy(s_15);
  return result_35;}
string_0_sysvq0asl typeNameAfter_0_aow7lb5cq1(string_0_sysvq0asl src_6, string_0_sysvq0asl prefix_0){
  string_0_sysvq0asl result_36;
  nimStrWasMoved((&result_36));
  nimStrDestroy(result_36);
  result_36 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 i_15 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_399 = len_4_sysvq0asl(prefix_0);
      NI32 X60Qx_400 = len_4_sysvq0asl(src_6);
      if (((NI32)(i_15 + X60Qx_399)) <= X60Qx_400){
        NB8 X60Qx_37;
        NB8 X60Qx_38;
        NC8 X60Qx_401 = getQ_9_sysvq0asl(src_6, i_15);
        NC8 X60Qx_402 = getQ_9_sysvq0asl(prefix_0, 0);
        if (X60Qx_401 == X60Qx_402){
          NI32 X60Qx_403 = len_4_sysvq0asl(prefix_0);
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_404 = ___1_Iclcqmw1_aow7lb5cq1(i_15, ((NI32)(((NI32)(i_15 + X60Qx_403)) - 1)));
          string_0_sysvq0asl X60Qtmp_25 = getQ_14_sysvq0asl(src_6, X60Qx_404);
          NB8 X60Qx_405 = eqQ_20_sysvq0asl(X60Qtmp_25, prefix_0);
          X60Qx_38 = X60Qx_405;
          nimStrDestroy(X60Qtmp_25);}
        else {
          X60Qx_38 = NIM_FALSE;}
        if (X60Qx_38){
          NB8 X60Qx_406;
          if (i_15 == 0){
            X60Qx_406 = NIM_TRUE;}
          else {
            NC8 X60Qx_407 = getQ_9_sysvq0asl(src_6, ((NI32)(i_15 - 1)));
            NB8 X60Qx_408 = isIdentChar_0_aow7lb5cq1(X60Qx_407);
            X60Qx_406 = (!X60Qx_408);}
          X60Qx_37 = X60Qx_406;}
        else {
          X60Qx_37 = NIM_FALSE;}
        if (X60Qx_37){
          NI32 X60Qx_409 = len_4_sysvq0asl(prefix_0);
          NI32 j_7 = ((NI32)(i_15 + X60Qx_409));
          {
            while (NIM_TRUE){
              NB8 X60Qx_410;
              NI32 X60Qx_411 = len_4_sysvq0asl(src_6);
              if (j_7 < X60Qx_411){
                NC8 X60Qx_412 = getQ_9_sysvq0asl(src_6, j_7);
                NB8 X60Qx_413 = isIdentChar_0_aow7lb5cq1(X60Qx_412);
                X60Qx_410 = X60Qx_413;}
              else {
                X60Qx_410 = NIM_FALSE;}
              if (X60Qx_410){
                inc_1_I6wjjge_aow2h993l1((&j_7));}
              else {
                break;}}}
          whileStmtLabel_1: ;
          NI32 X60Qx_414 = len_4_sysvq0asl(prefix_0);
          if (((NI32)(i_15 + X60Qx_414)) < j_7){
            HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_415 = ___1_Iclcqmw1_aow7lb5cq1(i_15, ((NI32)(j_7 - 1)));
            string_0_sysvq0asl X60Qx_416 = getQ_14_sysvq0asl(src_6, X60Qx_415);
            result_36 = X60Qx_416;
            return result_36;}}
        inc_1_I6wjjge_aow2h993l1((&i_15));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_36;}
string_0_sysvq0asl strHelpers_0_aow7lb5cq1(string_0_sysvq0asl strT_0, string_0_sysvq0asl longT_0, string_0_sysvq0asl borrowFn_0){
  string_0_sysvq0asl result_37;
  nimStrWasMoved((&result_37));
  NI32 X60Qx_417 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 707726078u, .more_0 = (&strlit_0_I7463840659243061209_aow7lb5cq1)}
  );
  NI32 X60Qx_418 = len_4_sysvq0asl(strT_0);
  NI32 X60Qx_419 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I1876279935150955625_aow7lb5cq1)}
  );
  NI32 X60Qx_420 = len_4_sysvq0asl(strT_0);
  NI32 X60Qx_421 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I15783140816581038667_aow7lb5cq1)}
  );
  NI32 X60Qx_422 = len_4_sysvq0asl(strT_0);
  NI32 X60Qx_423 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1868636414u, .more_0 = (&strlit_0_I2723993762017903615_aow7lb5cq1)}
  );
  NI32 X60Qx_424 = len_4_sysvq0asl(longT_0);
  NI32 X60Qx_425 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 539634430u, .more_0 = (&strlit_0_I3721006562773567258_aow7lb5cq1)}
  );
  NI32 X60Qx_426 = len_4_sysvq0asl(strT_0);
  NI32 X60Qx_427 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 997400830u, .more_0 = (&strlit_0_I9356103350728131647_aow7lb5cq1)}
  );
  NI32 X60Qx_428 = len_4_sysvq0asl(borrowFn_0);
  NI32 X60Qx_429 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1663576318u, .more_0 = (&strlit_0_I12087480461722773288_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_10 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_417 + X60Qx_418)) + X60Qx_419)) + X60Qx_420)) + X60Qx_421)) + X60Qx_422)) + X60Qx_423)) + X60Qx_424)) + X60Qx_425)) + X60Qx_426)) + X60Qx_427)) + X60Qx_428)) + X60Qx_429)));
  add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
    .bytes_0 = 707726078u, .more_0 = (&strlit_0_I7463840659243061209_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_10), strT_0);
  add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I1876279935150955625_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_10), strT_0);
  add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I15783140816581038667_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_10), strT_0);
  add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
    .bytes_0 = 1868636414u, .more_0 = (&strlit_0_I2723993762017903615_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_10), longT_0);
  add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
    .bytes_0 = 539634430u, .more_0 = (&strlit_0_I3721006562773567258_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_10), strT_0);
  add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
    .bytes_0 = 997400830u, .more_0 = (&strlit_0_I9356103350728131647_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_10), borrowFn_0);
  add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
    .bytes_0 = 1663576318u, .more_0 = (&strlit_0_I12087480461722773288_aow7lb5cq1)}
  );
  nimStrDestroy(result_37);
  result_37 = X60Qdesugar_10;
  nimStrWasMoved((&X60Qdesugar_10));
  nimStrDestroy(X60Qdesugar_10);
  return result_37;
  nimStrDestroy(X60Qdesugar_10);
  return result_37;}
NI32 scalarWidth_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_3){
  NI32 result_38;
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_430 = sizeAlign_1_layptix6a1(td_3, 8);
  result_38 = X60Qx_430.fld_0;
  return result_38;}
NB8 packedScalarOk_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_0){
  NB8 result_39;
  if (el_0 == NIM_NIL){
    return NIM_FALSE;}
  switch ((*el_0).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_0 = sizeAlign_1_layptix6a1(el_0, 8);
      NB8 X60Qx_4;
      NI32 X60Qx_5;
      if (0 < sa_0.fld_1){
        X60Qx_5 = sa_0.fld_1;}
      else {
        X60Qx_5 = 1;}
      NI32 X60Qx_431 = align_0_layptix6a1(sa_0.fld_0, X60Qx_5);
      if (sa_0.fld_0 == X60Qx_431){
        X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1 X60QconstRefTemp_0 = (X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1){
          .a = {
            1, 2, 4, 8}}
        ;
        openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_432 = toOpenArray_0_Iccbrld_aow7lb5cq1((&X60QconstRefTemp_0));
        NB8 X60Qx_433 = contains_3_Ipa7o28_aow7lb5cq1(X60Qx_432, sa_0.fld_0);
        X60Qx_4 = X60Qx_433;}
      else {
        X60Qx_4 = NIM_FALSE;}
      result_39 = X60Qx_4;}
    break;
    default:
    {
      result_39 = NIM_FALSE;}
    break;}
  return result_39;}
string_0_sysvq0asl arrayInnerName_0_aow7lb5cq1(string_0_sysvq0asl unit_1, string_0_sysvq0asl wrapperCty_0){
  string_0_sysvq0asl result_40;
  nimStrWasMoved((&result_40));
  nimStrDestroy(result_40);
  result_40 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  seq_0_Irn2j6w_aow7lb5cq1 flds_1 = structFields_0_aow7lb5cq1(unit_1, wrapperCty_0);
  if ((!(flds_1.len_0 == 1))){
    eQdestroy_1_Iem8q971_aow7lb5cq1(flds_1);
    return result_40;}
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_434 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_1, 0);
  string_0_sysvq0asl nm_1 = nimStrDup((*X60Qx_434).fld_1);
  NI32 i_16 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_435;
      NI32 X60Qx_436 = len_4_sysvq0asl(nm_1);
      if (i_16 < X60Qx_436){
        NC8 X60Qx_437 = getQ_9_sysvq0asl(nm_1, i_16);
        X60Qx_435 = (!(X60Qx_437 == (NC8)'['));}
      else {
        X60Qx_435 = NIM_FALSE;}
      if (X60Qx_435){
        inc_1_I6wjjge_aow2h993l1((&i_16));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_438;
  NB8 X60Qx_439;
  if (i_16 == 0){
    X60Qx_439 = NIM_TRUE;}
  else {
    NI32 X60Qx_440 = len_4_sysvq0asl(nm_1);
    X60Qx_439 = (X60Qx_440 <= i_16);}
  if (X60Qx_439){
    X60Qx_438 = NIM_TRUE;}
  else {
    NI32 X60Qx_441 = len_4_sysvq0asl(nm_1);
    NC8 X60Qx_442 = getQ_9_sysvq0asl(nm_1, ((NI32)(X60Qx_441 - 1)));
    X60Qx_438 = (!(X60Qx_442 == (NC8)']'));}
  if (X60Qx_438){
    nimStrDestroy(nm_1);
    eQdestroy_1_Iem8q971_aow7lb5cq1(flds_1);
    return result_40;}
  nimStrDestroy(result_40);
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_443 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(i_16 - 1)));
  string_0_sysvq0asl X60Qx_444 = getQ_14_sysvq0asl(nm_1, X60Qx_443);
  result_40 = X60Qx_444;
  nimStrDestroy(nm_1);
  eQdestroy_1_Iem8q971_aow7lb5cq1(flds_1);
  return result_40;
  nimStrDestroy(nm_1);
  eQdestroy_1_Iem8q971_aow7lb5cq1(flds_1);
  return result_40;}
NB8 compositeCOk_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_4, NI32 depth_2){
  NB8 result_41;
  if (td_4 == NIM_NIL){
    return NIM_FALSE;}
  if (6 < depth_2){
    return NIM_FALSE;}
  switch ((*td_4).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1 X60QconstRefTemp_0 = (X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1){
        .a = {
          1, 2, 4, 8}}
      ;
      openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_445 = toOpenArray_0_Iccbrld_aow7lb5cq1((&X60QconstRefTemp_0));
      NI32 X60Qx_446 = scalarWidth_0_aow7lb5cq1(td_4);
      NB8 X60Qx_447 = contains_3_Ipa7o28_aow7lb5cq1(X60Qx_445, X60Qx_446);
      result_41 = X60Qx_447;}
    break;
    case 14:
    {
      result_41 = NIM_TRUE;}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_1 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_4).d_00.elem_0);
      if (el_1 == NIM_NIL){
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_1);
        return NIM_FALSE;}
      switch ((*el_1).d_00.kind_0){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 8:
        {
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_1 = sizeAlign_1_layptix6a1(el_1, 8);
          NB8 X60Qx_6;
          NI32 X60Qx_7;
          if (0 < sa_1.fld_1){
            X60Qx_7 = sa_1.fld_1;}
          else {
            X60Qx_7 = 1;}
          NI32 X60Qx_448 = align_0_layptix6a1(sa_1.fld_0, X60Qx_7);
          if (sa_1.fld_0 == X60Qx_448){
            X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1 X60QconstRefTemp_1 = (X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1){
              .a = {
                1, 2, 4, 8}}
            ;
            openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_449 = toOpenArray_0_Iccbrld_aow7lb5cq1((&X60QconstRefTemp_1));
            NB8 X60Qx_450 = contains_3_Ipa7o28_aow7lb5cq1(X60Qx_449, sa_1.fld_0);
            X60Qx_6 = X60Qx_450;}
          else {
            X60Qx_6 = NIM_FALSE;}
          result_41 = X60Qx_6;}
        break;
        case 14:
        {
          result_41 = NIM_TRUE;}
        break;
        case 10:
        case 11:
        {
          NB8 X60Qx_451 = compositeCOk_0_aow7lb5cq1(el_1, ((NI32)(depth_2 + 1)));
          result_41 = X60Qx_451;}
        break;
        default:
        {
          result_41 = NIM_FALSE;}
        break;}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_1);}
    break;
    case 9:
    {
      NB8 X60Qx_452;
      NB8 X60Qx_453;
      if (0 < (*td_4).d_00.count_0){
        X60Qx_453 = (!((*td_4).d_00.elem_0 == NIM_NIL));}
      else {
        X60Qx_453 = NIM_FALSE;}
      if (X60Qx_453){
        NB8 X60Qx_454;
        NB8 X60Qx_455 = packedScalarOk_0_aow7lb5cq1((*td_4).d_00.elem_0);
        if (X60Qx_455){
          X60Qx_454 = NIM_TRUE;}
        else {
          X60Qx_454 = ((*(*td_4).d_00.elem_0).d_00.kind_0 == 14);}
        X60Qx_452 = X60Qx_454;}
      else {
        X60Qx_452 = NIM_FALSE;}
      result_41 = X60Qx_452;}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_456;
      if ((*td_4).d_00.incomplete_0){
        X60Qx_456 = NIM_TRUE;}
      else {
        X60Qx_456 = (*td_4).d_00.union_0;}
      if (X60Qx_456){
        return NIM_FALSE;}
      NI32 i_17 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_457 = len_3_I5m68tr1_aow7lb5cq1((*td_4).d_00.fields_0);
          if (i_17 < X60Qx_457){
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_458 = getQ_7_I45w7c91_aow7lb5cq1((*td_4).d_00.fields_0, i_17);
            NB8 X60Qx_459 = compositeCOk_0_aow7lb5cq1((*X60Qx_458), ((NI32)(depth_2 + 1)));
            if ((!X60Qx_459)){
              return NIM_FALSE;}
            inc_1_I6wjjge_aow2h993l1((&i_17));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      result_41 = NIM_TRUE;}
    break;
    default:
    {
      result_41 = NIM_FALSE;}
    break;}
  return result_41;}
string_0_sysvq0asl compositeWhyNot_1_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_5, NI32 depth_3){
  string_0_sysvq0asl result_42;
  nimStrWasMoved((&result_42));
  if (td_5 == NIM_NIL){
    return (string_0_sysvq0asl){
      .bytes_0 = 1818849022u, .more_0 = (&strlit_0_I988991057058608115_aow7lb5cq1)}
    ;}
  if (6 < depth_3){
    return (string_0_sysvq0asl){
      .bytes_0 = 1936027390u, .more_0 = (&strlit_0_I324375890710632441_aow7lb5cq1)}
    ;}
  switch ((*td_5).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1 X60QconstRefTemp_0 = (X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1){
        .a = {
          1, 2, 4, 8}}
      ;
      openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_460 = toOpenArray_0_Iccbrld_aow7lb5cq1((&X60QconstRefTemp_0));
      NI32 X60Qx_461 = scalarWidth_0_aow7lb5cq1(td_5);
      NB8 X60Qx_462 = contains_3_Ipa7o28_aow7lb5cq1(X60Qx_460, X60Qx_461);
      if (X60Qx_462){
        return (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;}
      NI32 X60Qx_463 = scalarWidth_0_aow7lb5cq1(td_5);
      string_0_sysvq0asl X60Qdesugar_11 = dollarQ_2_sysvq0asl(X60Qx_463);
      NI32 X60Qx_464 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2121986u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_465 = len_4_sysvq0asl(X60Qdesugar_11);
      NI32 X60Qx_466 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2036477438u, .more_0 = (&strlit_0_I10406916229603502364_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_12 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_464 + X60Qx_465)) + X60Qx_466)));
      add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
        .bytes_0 = 2121986u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_11);
      add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
        .bytes_0 = 2036477438u, .more_0 = (&strlit_0_I10406916229603502364_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qtmp_26 = X60Qdesugar_12;
      nimStrWasMoved((&X60Qdesugar_12));
      nimStrDestroy(X60Qdesugar_12);
      nimStrDestroy(X60Qdesugar_11);
      return X60Qtmp_26;
      nimStrDestroy(X60Qdesugar_12);
      nimStrDestroy(X60Qdesugar_11);}
    break;
    case 14:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_2 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_5).d_00.elem_0);
      if (el_2 == NIM_NIL){
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_2);
        return (string_0_sysvq0asl){
          .bytes_0 = 1931502078u, .more_0 = (&strlit_0_I10718771205828439240_aow7lb5cq1)}
        ;}
      switch ((*el_2).d_00.kind_0){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 8:
        {
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_2 = sizeAlign_1_layptix6a1(el_2, 8);
          NB8 X60Qx_8;
          NI32 X60Qx_9;
          if (0 < sa_2.fld_1){
            X60Qx_9 = sa_2.fld_1;}
          else {
            X60Qx_9 = 1;}
          NI32 X60Qx_467 = align_0_layptix6a1(sa_2.fld_0, X60Qx_9);
          if (sa_2.fld_0 == X60Qx_467){
            X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1 X60QconstRefTemp_1 = (X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1){
              .a = {
                1, 2, 4, 8}}
            ;
            openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_468 = toOpenArray_0_Iccbrld_aow7lb5cq1((&X60QconstRefTemp_1));
            NB8 X60Qx_469 = contains_3_Ipa7o28_aow7lb5cq1(X60Qx_468, sa_2.fld_0);
            X60Qx_8 = X60Qx_469;}
          else {
            X60Qx_8 = NIM_FALSE;}
          if (X60Qx_8){
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_2);
            return (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            ;}
          string_0_sysvq0asl X60Qdesugar_13 = dollarQ_2_sysvq0asl(sa_2.fld_0);
          string_0_sysvq0asl X60Qdesugar_14 = dollarQ_2_sysvq0asl(sa_2.fld_1);
          NI32 X60Qx_470 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1931502078u, .more_0 = (&strlit_0_I15127899386611443455_aow7lb5cq1)}
          );
          NI32 X60Qx_471 = len_4_sysvq0asl(X60Qdesugar_13);
          NI32 X60Qx_472 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I12873789045226272086_aow7lb5cq1)}
          );
          NI32 X60Qx_473 = len_4_sysvq0asl(X60Qdesugar_14);
          NI32 X60Qx_474 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540682750u, .more_0 = (&strlit_0_I3693825722426563353_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_15 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_470 + X60Qx_471)) + X60Qx_472)) + X60Qx_473)) + X60Qx_474)));
          add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
            .bytes_0 = 1931502078u, .more_0 = (&strlit_0_I15127899386611443455_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_13);
          add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
            .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I12873789045226272086_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_14);
          add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
            .bytes_0 = 540682750u, .more_0 = (&strlit_0_I3693825722426563353_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qtmp_27 = X60Qdesugar_15;
          nimStrWasMoved((&X60Qdesugar_15));
          nimStrDestroy(X60Qdesugar_15);
          nimStrDestroy(X60Qdesugar_14);
          nimStrDestroy(X60Qdesugar_13);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_2);
          return X60Qtmp_27;
          nimStrDestroy(X60Qdesugar_15);
          nimStrDestroy(X60Qdesugar_14);
          nimStrDestroy(X60Qdesugar_13);}
        break;
        case 14:
        {
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_2);
          return (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;}
        break;
        case 10:
        case 11:
        {
          string_0_sysvq0asl X60Qx_475 = compositeWhyNot_1_aow7lb5cq1(el_2, ((NI32)(depth_3 + 1)));
          result_42 = X60Qx_475;
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_2);
          return result_42;}
        break;
        default:
        {
          string_0_sysvq0asl X60Qtmp_28 = abiKindName_0_run8hsnpi(el_2);
          string_0_sysvq0asl X60Qx_476 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1931502078u, .more_0 = (&strlit_0_I2553287064141771090_aow7lb5cq1)}
          , X60Qtmp_28);
          result_42 = X60Qx_476;
          nimStrDestroy(X60Qtmp_28);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_2);
          return result_42;
          nimStrDestroy(X60Qtmp_28);}
        break;}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_2);}
    break;
    case 9:
    {
      if ((*td_5).d_00.elem_0 == NIM_NIL){
        return (string_0_sysvq0asl){
          .bytes_0 = 544104958u, .more_0 = (&strlit_0_I9648376121717153253_aow7lb5cq1)}
        ;}
      if ((*td_5).d_00.count_0 <= 0){
        return (string_0_sysvq0asl){
          .bytes_0 = 544104958u, .more_0 = (&strlit_0_I9905848785981538384_aow7lb5cq1)}
        ;}
      NB8 X60Qx_477;
      NB8 X60Qx_478 = packedScalarOk_0_aow7lb5cq1((*td_5).d_00.elem_0);
      if ((!X60Qx_478)){
        X60Qx_477 = (!((*(*td_5).d_00.elem_0).d_00.kind_0 == 14));}
      else {
        X60Qx_477 = NIM_FALSE;}
      if (X60Qx_477){
        string_0_sysvq0asl X60Qtmp_29 = abiKindName_0_run8hsnpi((*td_5).d_00.elem_0);
        string_0_sysvq0asl X60Qx_479 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 544104958u, .more_0 = (&strlit_0_I10012566867423011324_aow7lb5cq1)}
        , X60Qtmp_29);
        result_42 = X60Qx_479;
        nimStrDestroy(X60Qtmp_29);
        return result_42;
        nimStrDestroy(X60Qtmp_29);}
      return (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    break;
    case 10:
    case 11:
    {
      if ((*td_5).d_00.incomplete_0){
        return (string_0_sysvq0asl){
          .bytes_0 = 544104958u, .more_0 = (&strlit_0_I1157300079854504653_aow7lb5cq1)}
        ;}
      if ((*td_5).d_00.union_0){
        return (string_0_sysvq0asl){
          .bytes_0 = 2065719806u, .more_0 = (&strlit_0_I7806974970349732576_aow7lb5cq1)}
        ;}
      NI32 i_18 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_480 = len_3_I5m68tr1_aow7lb5cq1((*td_5).d_00.fields_0);
          if (i_18 < X60Qx_480){
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_481 = getQ_7_I45w7c91_aow7lb5cq1((*td_5).d_00.fields_0, i_18);
            string_0_sysvq0asl w_2 = compositeWhyNot_1_aow7lb5cq1((*X60Qx_481), ((NI32)(depth_3 + 1)));
            NI32 X60Qx_482 = len_4_sysvq0asl(w_2);
            if (0 < X60Qx_482){
              string_0_sysvq0asl X60Qtmp_30 = w_2;
              nimStrWasMoved((&w_2));
              nimStrDestroy(w_2);
              return X60Qtmp_30;}
            inc_1_I6wjjge_aow2h993l1((&i_18));
            nimStrDestroy(w_2);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      return (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    break;
    default:
    {
      string_0_sysvq0asl X60Qtmp_31 = abiKindName_0_run8hsnpi(td_5);
      string_0_sysvq0asl X60Qx_483 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2121986u, .more_0 = NIM_NIL}
      , X60Qtmp_31);
      result_42 = X60Qx_483;
      nimStrDestroy(X60Qtmp_31);
      return result_42;
      nimStrDestroy(X60Qtmp_31);}
    break;}
  return result_42;}
string_0_sysvq0asl emitCompositeIn_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_6, string_0_sysvq0asl unit_2, string_0_sysvq0asl cty_0, string_0_sysvq0asl dst_0, string_0_sysvq0asl strT_1, string_0_sysvq0asl longT_1, string_0_sysvq0asl allocFn_0, string_0_sysvq0asl deallocFn_0, NI32* tmp_0, string_0_sysvq0asl* owned_0, NB8* ok_0){
  string_0_sysvq0asl result_43;
  nimStrWasMoved((&result_43));
  nimStrDestroy(result_43);
  result_43 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((!(*ok_0))){
    return result_43;}
  inc_1_I6wjjge_aow2h993l1(tmp_0);
  string_0_sysvq0asl k_1 = dollarQ_2_sysvq0asl((*tmp_0));
  switch ((*td_6).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      NI32 X60Qx_484 = scalarWidth_0_aow7lb5cq1(td_6);
      string_0_sysvq0asl w_3 = dollarQ_2_sysvq0asl(X60Qx_484);
      NI32 X60Qx_485 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
      );
      NI32 X60Qx_486 = len_4_sysvq0asl(dst_0);
      NI32 X60Qx_487 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
      );
      NI32 X60Qx_488 = len_4_sysvq0asl(w_3);
      NI32 X60Qx_489 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_16 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_485 + X60Qx_486)) + X60Qx_487)) + X60Qx_488)) + X60Qx_489)));
      add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_16), dst_0);
      add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_16), w_3);
      add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_43), X60Qdesugar_16);
      NI32 X60Qx_490 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
      );
      NI32 X60Qx_491 = len_4_sysvq0asl(w_3);
      NI32 X60Qx_492 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_17 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_490 + X60Qx_491)) + X60Qx_492)));
      add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_17), w_3);
      add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_43), X60Qdesugar_17);
      nimStrDestroy(X60Qdesugar_17);
      nimStrDestroy(X60Qdesugar_16);
      nimStrDestroy(w_3);}
    break;
    case 9:
    {
      NB8 X60Qx_493;
      NB8 X60Qx_494;
      if ((!((*td_6).d_00.elem_0 == NIM_NIL))){
        X60Qx_494 = ((*(*td_6).d_00.elem_0).d_00.kind_0 == 14);}
      else {
        X60Qx_494 = NIM_FALSE;}
      if (X60Qx_494){
        X60Qx_493 = (0 < (*td_6).d_00.count_0);}
      else {
        X60Qx_493 = NIM_FALSE;}
      if (X60Qx_493){
        string_0_sysvq0asl inner_0 = arrayInnerName_0_aow7lb5cq1(unit_2, cty_0);
        NI32 X60Qx_495 = len_4_sysvq0asl(inner_0);
        if (X60Qx_495 == 0){
          (*ok_0) = NIM_FALSE;
          nimStrDestroy(inner_0);
          nimStrDestroy(k_1);
          return result_43;}
        NI32 X60Qx_496 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
        );
        NI32 X60Qx_497 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_498 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_18 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_496 + X60Qx_497)) + X60Qx_498)));
        add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_18), k_1);
        add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_18);
        string_0_sysvq0asl X60Qdesugar_19 = dollarQ_2_sysvq0asl((*td_6).d_00.count_0);
        NI32 X60Qx_499 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
        );
        NI32 X60Qx_500 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_501 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540811267u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_502 = len_4_sysvq0asl(X60Qdesugar_19);
        NI32 X60Qx_503 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        NI32 X60Qx_504 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_505 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_20 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_499 + X60Qx_500)) + X60Qx_501)) + X60Qx_502)) + X60Qx_503)) + X60Qx_504)) + X60Qx_505)));
        add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_20), k_1);
        add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
          .bytes_0 = 540811267u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_20), X60Qdesugar_19);
        add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_20), k_1);
        add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_20);
        NI32 X60Qx_506 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I3568409834490710820_aow7lb5cq1)}
        );
        NI32 X60Qx_507 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_508 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_21 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_506 + X60Qx_507)) + X60Qx_508)));
        add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I3568409834490710820_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_21), k_1);
        add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_21);
        NI32 X60Qx_509 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
        );
        NI32 X60Qx_510 = len_4_sysvq0asl(longT_1);
        NI32 X60Qx_511 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1864378883u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_512 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_513 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_22 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_509 + X60Qx_510)) + X60Qx_511)) + X60Qx_512)) + X60Qx_513)));
        add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_22), longT_1);
        add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
          .bytes_0 = 1864378883u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_22), k_1);
        add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_22);
        NI32 X60Qx_514 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
        );
        NI32 X60Qx_515 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_516 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 11777u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_517 = len_4_sysvq0asl(inner_0);
        NI32 X60Qx_518 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 6904578u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_519 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_520 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1025531390u, .more_0 = (&strlit_0_I15437739651001969444_aow7lb5cq1)}
        );
        NI32 X60Qx_521 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_522 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1161825924217342649_aow7lb5cq1)}
        );
        NI32 X60Qx_523 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_524 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_23 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_514 + X60Qx_515)) + X60Qx_516)) + X60Qx_517)) + X60Qx_518)) + X60Qx_519)) + X60Qx_520)) + X60Qx_521)) + X60Qx_522)) + X60Qx_523)) + X60Qx_524)));
        add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_23), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
          .bytes_0 = 11777u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_23), inner_0);
        add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
          .bytes_0 = 6904578u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_23), k_1);
        add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
          .bytes_0 = 1025531390u, .more_0 = (&strlit_0_I15437739651001969444_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_23), k_1);
        add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
          .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1161825924217342649_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_23), k_1);
        add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_23);
        NI32 X60Qx_525 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2839767760384294121_aow7lb5cq1)}
        );
        NI32 X60Qx_526 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_527 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_24 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_525 + X60Qx_526)) + X60Qx_527)));
        add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2839767760384294121_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_24), k_1);
        add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_24);
        add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15342668115246402447_aow7lb5cq1)}
        );
        nimStrDestroy(X60Qdesugar_24);
        nimStrDestroy(X60Qdesugar_23);
        nimStrDestroy(X60Qdesugar_22);
        nimStrDestroy(X60Qdesugar_21);
        nimStrDestroy(X60Qdesugar_20);
        nimStrDestroy(X60Qdesugar_19);
        nimStrDestroy(X60Qdesugar_18);
        nimStrDestroy(inner_0);
        nimStrDestroy(k_1);
        return result_43;
        nimStrDestroy(X60Qdesugar_24);
        nimStrDestroy(X60Qdesugar_23);
        nimStrDestroy(X60Qdesugar_22);
        nimStrDestroy(X60Qdesugar_21);
        nimStrDestroy(X60Qdesugar_20);
        nimStrDestroy(X60Qdesugar_19);
        nimStrDestroy(X60Qdesugar_18);
        nimStrDestroy(inner_0);}
      NB8 X60Qx_528;
      NB8 X60Qx_529 = packedScalarOk_0_aow7lb5cq1((*td_6).d_00.elem_0);
      if ((!X60Qx_529)){
        X60Qx_528 = NIM_TRUE;}
      else {
        X60Qx_528 = ((*td_6).d_00.count_0 <= 0);}
      if (X60Qx_528){
        (*ok_0) = NIM_FALSE;
        nimStrDestroy(k_1);
        return result_43;}
      string_0_sysvq0asl inner_1 = arrayInnerName_0_aow7lb5cq1(unit_2, cty_0);
      NI32 X60Qx_530 = len_4_sysvq0asl(inner_1);
      if (X60Qx_530 == 0){
        (*ok_0) = NIM_FALSE;
        nimStrDestroy(inner_1);
        nimStrDestroy(k_1);
        return result_43;}
      NI32 X60Qx_531 = scalarWidth_0_aow7lb5cq1((*td_6).d_00.elem_0);
      string_0_sysvq0asl nb_0 = dollarQ_2_sysvq0asl(((NI32)((*td_6).d_00.count_0 * X60Qx_531)));
      NI32 X60Qx_532 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
      );
      NI32 X60Qx_533 = len_4_sysvq0asl(dst_0);
      NI32 X60Qx_534 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 11777u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_535 = len_4_sysvq0asl(inner_1);
      NI32 X60Qx_536 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
      );
      NI32 X60Qx_537 = len_4_sysvq0asl(nb_0);
      NI32 X60Qx_538 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 572534014u, .more_0 = (&strlit_0_I4129744452504341063_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_25 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_532 + X60Qx_533)) + X60Qx_534)) + X60Qx_535)) + X60Qx_536)) + X60Qx_537)) + X60Qx_538)));
      add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
        .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_25), dst_0);
      add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
        .bytes_0 = 11777u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_25), inner_1);
      add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
        .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_25), nb_0);
      add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
        .bytes_0 = 572534014u, .more_0 = (&strlit_0_I4129744452504341063_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_43), X60Qdesugar_25);
      NI32 X60Qx_539 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7486184284809924372_aow7lb5cq1)}
      );
      NI32 X60Qx_540 = len_4_sysvq0asl(dst_0);
      NI32 X60Qx_541 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 11777u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_542 = len_4_sysvq0asl(inner_1);
      NI32 X60Qx_543 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
      );
      NI32 X60Qx_544 = len_4_sysvq0asl(nb_0);
      NI32 X60Qx_545 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I9161878147184120533_aow7lb5cq1)}
      );
      NI32 X60Qx_546 = len_4_sysvq0asl(nb_0);
      NI32 X60Qx_547 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_26 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_539 + X60Qx_540)) + X60Qx_541)) + X60Qx_542)) + X60Qx_543)) + X60Qx_544)) + X60Qx_545)) + X60Qx_546)) + X60Qx_547)));
      add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7486184284809924372_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_26), dst_0);
      add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
        .bytes_0 = 11777u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_26), inner_1);
      add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_26), nb_0);
      add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I9161878147184120533_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_26), nb_0);
      add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_43), X60Qdesugar_26);
      nimStrDestroy(X60Qdesugar_26);
      nimStrDestroy(X60Qdesugar_25);
      nimStrDestroy(nb_0);
      nimStrDestroy(inner_1);}
    break;
    case 14:
    {
      NI32 X60Qx_548 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
      );
      NI32 X60Qx_549 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_550 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_27 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_548 + X60Qx_549)) + X60Qx_550)));
      add_2_sysvq0asl((&X60Qdesugar_27), (string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_27), k_1);
      add_2_sysvq0asl((&X60Qdesugar_27), (string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_43), X60Qdesugar_27);
      NI32 X60Qx_551 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
      );
      NI32 X60Qx_552 = len_4_sysvq0asl(longT_1);
      NI32 X60Qx_553 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1864379134u, .more_0 = (&strlit_0_I9396282401636018722_aow7lb5cq1)}
      );
      NI32 X60Qx_554 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_555 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_28 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_551 + X60Qx_552)) + X60Qx_553)) + X60Qx_554)) + X60Qx_555)));
      add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_28), longT_1);
      add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
        .bytes_0 = 1864379134u, .more_0 = (&strlit_0_I9396282401636018722_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_28), k_1);
      add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_43), X60Qdesugar_28);
      NI32 X60Qx_556 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
      );
      NI32 X60Qx_557 = len_4_sysvq0asl(dst_0);
      NI32 X60Qx_558 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I459476928402638487_aow7lb5cq1)}
      );
      NI32 X60Qx_559 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_560 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1259136645670664990_aow7lb5cq1)}
      );
      NI32 X60Qx_561 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_562 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_29 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_556 + X60Qx_557)) + X60Qx_558)) + X60Qx_559)) + X60Qx_560)) + X60Qx_561)) + X60Qx_562)));
      add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_29), dst_0);
      add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I459476928402638487_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_29), k_1);
      add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
        .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1259136645670664990_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_29), k_1);
      add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_43), X60Qdesugar_29);
      NI32 X60Qx_563 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I14393988487556796913_aow7lb5cq1)}
      );
      NI32 X60Qx_564 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_565 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_30 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_563 + X60Qx_564)) + X60Qx_565)));
      add_2_sysvq0asl((&X60Qdesugar_30), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I14393988487556796913_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_30), k_1);
      add_2_sysvq0asl((&X60Qdesugar_30), (string_0_sysvq0asl){
        .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_43), X60Qdesugar_30);
      nimStrDestroy(X60Qdesugar_30);
      nimStrDestroy(X60Qdesugar_29);
      nimStrDestroy(X60Qdesugar_28);
      nimStrDestroy(X60Qdesugar_27);}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_3 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_6).d_00.elem_0);
      if (el_3 == NIM_NIL){
        (*ok_0) = NIM_FALSE;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_3);
        nimStrDestroy(k_1);
        return result_43;}
      if ((*el_3).d_00.kind_0 == 14){
        NI32 X60Qx_566 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        NI32 X60Qx_567 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_568 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_31 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_566 + X60Qx_567)) + X60Qx_568)));
        add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_31), k_1);
        add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_31);
        add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I782490999618302521_aow7lb5cq1)}
        );
        NI32 X60Qx_569 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
        );
        NI32 X60Qx_570 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_571 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
        );
        NI32 X60Qx_572 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_573 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_32 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_569 + X60Qx_570)) + X60Qx_571)) + X60Qx_572)) + X60Qx_573)));
        add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_32), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
          .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_32), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_32);
        NI32 X60Qx_574 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
        );
        NI32 X60Qx_575 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_576 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
        );
        NI32 X60Qx_577 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_578 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_33 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_574 + X60Qx_575)) + X60Qx_576)) + X60Qx_577)) + X60Qx_578)));
        add_2_sysvq0asl((&X60Qdesugar_33), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_33), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_33), (string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_33), k_1);
        add_2_sysvq0asl((&X60Qdesugar_33), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_33);
        NI32 X60Qx_579 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
        );
        NI32 X60Qx_580 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_581 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540942590u, .more_0 = (&strlit_0_I13666278637935594890_aow7lb5cq1)}
        );
        NI32 X60Qx_582 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_583 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
        );
        NI32 X60Qx_584 = len_4_sysvq0asl(allocFn_0);
        NI32 X60Qx_585 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
        );
        NI32 X60Qx_586 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_587 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 539631870u, .more_0 = (&strlit_0_I696246876201023085_aow7lb5cq1)}
        );
        NI32 X60Qx_588 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_589 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6286326072955259077_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_34 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_579 + X60Qx_580)) + X60Qx_581)) + X60Qx_582)) + X60Qx_583)) + X60Qx_584)) + X60Qx_585)) + X60Qx_586)) + X60Qx_587)) + X60Qx_588)) + X60Qx_589)));
        add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_34), k_1);
        add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
          .bytes_0 = 540942590u, .more_0 = (&strlit_0_I13666278637935594890_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_34), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_34), allocFn_0);
        add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
          .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_34), k_1);
        add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
          .bytes_0 = 539631870u, .more_0 = (&strlit_0_I696246876201023085_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_34), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6286326072955259077_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_34);
        NI32 X60Qx_590 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        NI32 X60Qx_591 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_592 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_35 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_590 + X60Qx_591)) + X60Qx_592)));
        add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_35), k_1);
        add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_35);
        NI32 X60Qx_593 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        NI32 X60Qx_594 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_595 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        NI32 X60Qx_596 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_597 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        NI32 X60Qx_598 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_599 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_36 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_593 + X60Qx_594)) + X60Qx_595)) + X60Qx_596)) + X60Qx_597)) + X60Qx_598)) + X60Qx_599)));
        add_2_sysvq0asl((&X60Qdesugar_36), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_36), k_1);
        add_2_sysvq0asl((&X60Qdesugar_36), (string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_36), k_1);
        add_2_sysvq0asl((&X60Qdesugar_36), (string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_36), k_1);
        add_2_sysvq0asl((&X60Qdesugar_36), (string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_36);
        NI32 X60Qx_600 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5809312286091816554_aow7lb5cq1)}
        );
        NI32 X60Qx_601 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_602 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_37 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_600 + X60Qx_601)) + X60Qx_602)));
        add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5809312286091816554_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_37), k_1);
        add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_37);
        NI32 X60Qx_603 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5288086118845442921_aow7lb5cq1)}
        );
        NI32 X60Qx_604 = len_4_sysvq0asl(longT_1);
        NI32 X60Qx_605 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1864378883u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_606 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_607 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_38 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_603 + X60Qx_604)) + X60Qx_605)) + X60Qx_606)) + X60Qx_607)));
        add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5288086118845442921_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_38), longT_1);
        add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
          .bytes_0 = 1864378883u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_38), k_1);
        add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_38);
        NI32 X60Qx_608 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5288086118845442921_aow7lb5cq1)}
        );
        NI32 X60Qx_609 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_610 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        NI32 X60Qx_611 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_612 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1025531390u, .more_0 = (&strlit_0_I15437739651001969444_aow7lb5cq1)}
        );
        NI32 X60Qx_613 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_614 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1161825924217342649_aow7lb5cq1)}
        );
        NI32 X60Qx_615 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_616 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_39 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_608 + X60Qx_609)) + X60Qx_610)) + X60Qx_611)) + X60Qx_612)) + X60Qx_613)) + X60Qx_614)) + X60Qx_615)) + X60Qx_616)));
        add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5288086118845442921_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_39), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_39), k_1);
        add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
          .bytes_0 = 1025531390u, .more_0 = (&strlit_0_I15437739651001969444_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_39), k_1);
        add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
          .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1161825924217342649_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_39), k_1);
        add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_39);
        NI32 X60Qx_617 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2640784052786307265_aow7lb5cq1)}
        );
        NI32 X60Qx_618 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_619 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_40 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_617 + X60Qx_618)) + X60Qx_619)));
        add_2_sysvq0asl((&X60Qdesugar_40), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2640784052786307265_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_40), k_1);
        add_2_sysvq0asl((&X60Qdesugar_40), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_43), X60Qdesugar_40);
        add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I7306224084071035336_aow7lb5cq1)}
        );
        NI32 X60Qx_620 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        NI32 X60Qx_621 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_622 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        NI32 X60Qx_623 = len_4_sysvq0asl(deallocFn_0);
        NI32 X60Qx_624 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        NI32 X60Qx_625 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_626 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_41 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_620 + X60Qx_621)) + X60Qx_622)) + X60Qx_623)) + X60Qx_624)) + X60Qx_625)) + X60Qx_626)));
        add_2_sysvq0asl((&X60Qdesugar_41), (string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_41), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_41), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_41), deallocFn_0);
        add_2_sysvq0asl((&X60Qdesugar_41), (string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_41), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_41), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        add_2_sysvq0asl(owned_0, X60Qdesugar_41);
        nimStrDestroy(X60Qdesugar_41);
        nimStrDestroy(X60Qdesugar_40);
        nimStrDestroy(X60Qdesugar_39);
        nimStrDestroy(X60Qdesugar_38);
        nimStrDestroy(X60Qdesugar_37);
        nimStrDestroy(X60Qdesugar_36);
        nimStrDestroy(X60Qdesugar_35);
        nimStrDestroy(X60Qdesugar_34);
        nimStrDestroy(X60Qdesugar_33);
        nimStrDestroy(X60Qdesugar_32);
        nimStrDestroy(X60Qdesugar_31);}
      else {
        NB8 X60Qx_627;
        if ((*el_3).d_00.kind_0 == 10){
          X60Qx_627 = NIM_TRUE;}
        else {
          X60Qx_627 = ((*el_3).d_00.kind_0 == 11);}
        if (X60Qx_627){
          string_0_sysvq0asl ect_0 = seqElemCType_0_aow7lb5cq1(unit_2, cty_0);
          NI32 X60Qx_628 = len_4_sysvq0asl(ect_0);
          if (X60Qx_628 == 0){
            (*ok_0) = NIM_FALSE;
            nimStrDestroy(ect_0);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_3);
            nimStrDestroy(k_1);
            return result_43;}
          NI32 X60Qx_629 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
          );
          NI32 X60Qx_630 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_631 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_42 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_629 + X60Qx_630)) + X60Qx_631)));
          add_2_sysvq0asl((&X60Qdesugar_42), (string_0_sysvq0asl){
            .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_42), k_1);
          add_2_sysvq0asl((&X60Qdesugar_42), (string_0_sysvq0asl){
            .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_42);
          add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I782490999618302521_aow7lb5cq1)}
          );
          NI32 X60Qx_632 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
          );
          NI32 X60Qx_633 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_634 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
          );
          NI32 X60Qx_635 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_636 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_43 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_632 + X60Qx_633)) + X60Qx_634)) + X60Qx_635)) + X60Qx_636)));
          add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_43), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
            .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_43), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_43);
          NI32 X60Qx_637 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
          );
          NI32 X60Qx_638 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_639 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
          );
          NI32 X60Qx_640 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_641 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 670466u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_44 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_637 + X60Qx_638)) + X60Qx_639)) + X60Qx_640)) + X60Qx_641)));
          add_2_sysvq0asl((&X60Qdesugar_44), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_44), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_44), (string_0_sysvq0asl){
            .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_44), k_1);
          add_2_sysvq0asl((&X60Qdesugar_44), (string_0_sysvq0asl){
            .bytes_0 = 670466u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_44);
          NI32 X60Qx_642 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
          );
          NI32 X60Qx_643 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_644 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_45 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_642 + X60Qx_643)) + X60Qx_644)));
          add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_45), k_1);
          add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
            .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_45);
          NI32 X60Qx_645 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
          );
          NI32 X60Qx_646 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_647 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
          );
          NI32 X60Qx_648 = len_4_sysvq0asl(allocFn_0);
          NI32 X60Qx_649 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
          );
          NI32 X60Qx_650 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_651 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 539631870u, .more_0 = (&strlit_0_I696246876201023085_aow7lb5cq1)}
          );
          NI32 X60Qx_652 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_653 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6286326072955259077_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_46 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_645 + X60Qx_646)) + X60Qx_647)) + X60Qx_648)) + X60Qx_649)) + X60Qx_650)) + X60Qx_651)) + X60Qx_652)) + X60Qx_653)));
          add_2_sysvq0asl((&X60Qdesugar_46), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_46), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_46), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_46), allocFn_0);
          add_2_sysvq0asl((&X60Qdesugar_46), (string_0_sysvq0asl){
            .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_46), k_1);
          add_2_sysvq0asl((&X60Qdesugar_46), (string_0_sysvq0asl){
            .bytes_0 = 539631870u, .more_0 = (&strlit_0_I696246876201023085_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_46), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_46), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6286326072955259077_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_46);
          NI32 X60Qx_654 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10073469962794762804_aow7lb5cq1)}
          );
          NI32 X60Qx_655 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_656 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6519573624018950997_aow7lb5cq1)}
          );
          NI32 X60Qx_657 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_658 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 539631870u, .more_0 = (&strlit_0_I696246876201023085_aow7lb5cq1)}
          );
          NI32 X60Qx_659 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_660 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6286326072955259077_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_47 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_654 + X60Qx_655)) + X60Qx_656)) + X60Qx_657)) + X60Qx_658)) + X60Qx_659)) + X60Qx_660)));
          add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10073469962794762804_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_47), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6519573624018950997_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_47), k_1);
          add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
            .bytes_0 = 539631870u, .more_0 = (&strlit_0_I696246876201023085_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_47), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6286326072955259077_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_47);
          add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I13453311567032255224_aow7lb5cq1)}
          );
          NI32 X60Qx_661 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
          );
          NI32 X60Qx_662 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_663 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_48 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_661 + X60Qx_662)) + X60Qx_663)));
          add_2_sysvq0asl((&X60Qdesugar_48), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_48), k_1);
          add_2_sysvq0asl((&X60Qdesugar_48), (string_0_sysvq0asl){
            .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_48);
          NI32 X60Qx_664 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
          );
          NI32 X60Qx_665 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_666 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
          );
          NI32 X60Qx_667 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_668 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
          );
          NI32 X60Qx_669 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_670 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_49 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_664 + X60Qx_665)) + X60Qx_666)) + X60Qx_667)) + X60Qx_668)) + X60Qx_669)) + X60Qx_670)));
          add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_49), k_1);
          add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
            .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_49), k_1);
          add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
            .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_49), k_1);
          add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
            .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_43), X60Qdesugar_49);
          string_0_sysvq0asl elemOwned_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          NI32 X60Qx_671 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_672 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
          );
          NI32 X60Qx_673 = len_4_sysvq0asl(k_1);
          NI32 X60Qx_674 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_50 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_671 + X60Qx_672)) + X60Qx_673)) + X60Qx_674)));
          add_2_sysvq0asl((&X60Qdesugar_50), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_50), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_50), k_1);
          add_2_sysvq0asl((&X60Qdesugar_50), (string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl body_1 = emitCompositeIn_0_aow7lb5cq1(el_3, unit_2, ect_0, X60Qdesugar_50, strT_1, longT_1, allocFn_0, deallocFn_0, tmp_0, (&elemOwned_0), ok_0);
          if ((!(*ok_0))){
            nimStrDestroy(body_1);
            nimStrDestroy(X60Qdesugar_50);
            nimStrDestroy(elemOwned_0);
            nimStrDestroy(X60Qdesugar_49);
            nimStrDestroy(X60Qdesugar_48);
            nimStrDestroy(X60Qdesugar_47);
            nimStrDestroy(X60Qdesugar_46);
            nimStrDestroy(X60Qdesugar_45);
            nimStrDestroy(X60Qdesugar_44);
            nimStrDestroy(X60Qdesugar_43);
            nimStrDestroy(X60Qdesugar_42);
            nimStrDestroy(ect_0);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_3);
            nimStrDestroy(k_1);
            return result_43;}
          add_2_sysvq0asl((&result_43), body_1);
          add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I7306224084071035336_aow7lb5cq1)}
          );
          NI32 X60Qx_675 = len_4_sysvq0asl(elemOwned_0);
          if (0 < X60Qx_675){
            NI32 X60Qx_676 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
            );
            NI32 X60Qx_677 = len_4_sysvq0asl(k_1);
            NI32 X60Qx_678 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_51 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_676 + X60Qx_677)) + X60Qx_678)));
            add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
              .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_51), k_1);
            add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
            );
            add_2_sysvq0asl(owned_0, X60Qdesugar_51);
            NI32 X60Qx_679 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
            );
            NI32 X60Qx_680 = len_4_sysvq0asl(k_1);
            NI32 X60Qx_681 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540811267u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_682 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_683 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I6325254588340587598_aow7lb5cq1)}
            );
            NI32 X60Qx_684 = len_4_sysvq0asl(k_1);
            NI32 X60Qx_685 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_52 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_679 + X60Qx_680)) + X60Qx_681)) + X60Qx_682)) + X60Qx_683)) + X60Qx_684)) + X60Qx_685)));
            add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_52), k_1);
            add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
              .bytes_0 = 540811267u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_52), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I6325254588340587598_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_52), k_1);
            add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
              .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
            );
            add_2_sysvq0asl(owned_0, X60Qdesugar_52);
            add_2_sysvq0asl(owned_0, elemOwned_0);
            add_2_sysvq0asl(owned_0, (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15342668115246402447_aow7lb5cq1)}
            );
            nimStrDestroy(X60Qdesugar_52);
            nimStrDestroy(X60Qdesugar_51);}
          NI32 X60Qx_686 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
          );
          NI32 X60Qx_687 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_688 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
          );
          NI32 X60Qx_689 = len_4_sysvq0asl(deallocFn_0);
          NI32 X60Qx_690 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
          );
          NI32 X60Qx_691 = len_4_sysvq0asl(dst_0);
          NI32 X60Qx_692 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_53 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_686 + X60Qx_687)) + X60Qx_688)) + X60Qx_689)) + X60Qx_690)) + X60Qx_691)) + X60Qx_692)));
          add_2_sysvq0asl((&X60Qdesugar_53), (string_0_sysvq0asl){
            .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_53), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_53), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_53), deallocFn_0);
          add_2_sysvq0asl((&X60Qdesugar_53), (string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_53), dst_0);
          add_2_sysvq0asl((&X60Qdesugar_53), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
          );
          add_2_sysvq0asl(owned_0, X60Qdesugar_53);
          nimStrDestroy(X60Qdesugar_53);
          nimStrDestroy(body_1);
          nimStrDestroy(X60Qdesugar_50);
          nimStrDestroy(elemOwned_0);
          nimStrDestroy(X60Qdesugar_49);
          nimStrDestroy(X60Qdesugar_48);
          nimStrDestroy(X60Qdesugar_47);
          nimStrDestroy(X60Qdesugar_46);
          nimStrDestroy(X60Qdesugar_45);
          nimStrDestroy(X60Qdesugar_44);
          nimStrDestroy(X60Qdesugar_43);
          nimStrDestroy(X60Qdesugar_42);
          nimStrDestroy(ect_0);}
        else {
          NB8 X60Qx_693;
          NB8 X60Qx_694;
          NB8 X60Qx_695;
          NB8 X60Qx_696;
          NB8 X60Qx_697;
          if ((*el_3).d_00.kind_0 == 0){
            X60Qx_697 = NIM_TRUE;}
          else {
            X60Qx_697 = ((*el_3).d_00.kind_0 == 1);}
          if (X60Qx_697){
            X60Qx_696 = NIM_TRUE;}
          else {
            X60Qx_696 = ((*el_3).d_00.kind_0 == 2);}
          if (X60Qx_696){
            X60Qx_695 = NIM_TRUE;}
          else {
            X60Qx_695 = ((*el_3).d_00.kind_0 == 3);}
          if (X60Qx_695){
            X60Qx_694 = NIM_TRUE;}
          else {
            X60Qx_694 = ((*el_3).d_00.kind_0 == 4);}
          if (X60Qx_694){
            X60Qx_693 = NIM_TRUE;}
          else {
            X60Qx_693 = ((*el_3).d_00.kind_0 == 8);}
          if (X60Qx_693){
            NI32 X60Qx_698 = scalarWidth_0_aow7lb5cq1(el_3);
            string_0_sysvq0asl w_4 = dollarQ_2_sysvq0asl(X60Qx_698);
            NI32 X60Qx_699 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
            );
            NI32 X60Qx_700 = len_4_sysvq0asl(k_1);
            NI32 X60Qx_701 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_54 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_699 + X60Qx_700)) + X60Qx_701)));
            add_2_sysvq0asl((&X60Qdesugar_54), (string_0_sysvq0asl){
              .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_54), k_1);
            add_2_sysvq0asl((&X60Qdesugar_54), (string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_43), X60Qdesugar_54);
            NI32 X60Qx_702 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16570386306475740535_aow7lb5cq1)}
            );
            NI32 X60Qx_703 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_704 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
            );
            NI32 X60Qx_705 = len_4_sysvq0asl(w_4);
            NI32 X60Qx_706 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_55 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_702 + X60Qx_703)) + X60Qx_704)) + X60Qx_705)) + X60Qx_706)));
            add_2_sysvq0asl((&X60Qdesugar_55), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16570386306475740535_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_55), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_55), (string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_55), w_4);
            add_2_sysvq0asl((&X60Qdesugar_55), (string_0_sysvq0asl){
              .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_43), X60Qdesugar_55);
            NI32 X60Qx_707 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
            );
            NI32 X60Qx_708 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_709 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
            );
            NI32 X60Qx_710 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_711 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_56 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_707 + X60Qx_708)) + X60Qx_709)) + X60Qx_710)) + X60Qx_711)));
            add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_56), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
              .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_56), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
              .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_43), X60Qdesugar_56);
            NI32 X60Qx_712 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
            );
            NI32 X60Qx_713 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_714 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
            );
            NI32 X60Qx_715 = len_4_sysvq0asl(k_1);
            NI32 X60Qx_716 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_57 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_712 + X60Qx_713)) + X60Qx_714)) + X60Qx_715)) + X60Qx_716)));
            add_2_sysvq0asl((&X60Qdesugar_57), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_57), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_57), (string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_57), k_1);
            add_2_sysvq0asl((&X60Qdesugar_57), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_43), X60Qdesugar_57);
            NI32 X60Qx_717 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
            );
            NI32 X60Qx_718 = len_4_sysvq0asl(k_1);
            NI32 X60Qx_719 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_58 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_717 + X60Qx_718)) + X60Qx_719)));
            add_2_sysvq0asl((&X60Qdesugar_58), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_58), k_1);
            add_2_sysvq0asl((&X60Qdesugar_58), (string_0_sysvq0asl){
              .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_43), X60Qdesugar_58);
            NI32 X60Qx_720 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
            );
            NI32 X60Qx_721 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_722 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
            );
            NI32 X60Qx_723 = len_4_sysvq0asl(allocFn_0);
            NI32 X60Qx_724 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
            );
            NI32 X60Qx_725 = len_4_sysvq0asl(k_1);
            NI32 X60Qx_726 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_727 = len_4_sysvq0asl(w_4);
            NI32 X60Qx_728 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_59 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_720 + X60Qx_721)) + X60Qx_722)) + X60Qx_723)) + X60Qx_724)) + X60Qx_725)) + X60Qx_726)) + X60Qx_727)) + X60Qx_728)));
            add_2_sysvq0asl((&X60Qdesugar_59), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_59), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_59), (string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_59), allocFn_0);
            add_2_sysvq0asl((&X60Qdesugar_59), (string_0_sysvq0asl){
              .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_59), k_1);
            add_2_sysvq0asl((&X60Qdesugar_59), (string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_59), w_4);
            add_2_sysvq0asl((&X60Qdesugar_59), (string_0_sysvq0asl){
              .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_43), X60Qdesugar_59);
            NI32 X60Qx_729 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12628527270567457706_aow7lb5cq1)}
            );
            NI32 X60Qx_730 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_731 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I14428153832606577816_aow7lb5cq1)}
            );
            NI32 X60Qx_732 = len_4_sysvq0asl(k_1);
            NI32 X60Qx_733 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_734 = len_4_sysvq0asl(w_4);
            NI32 X60Qx_735 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_60 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_729 + X60Qx_730)) + X60Qx_731)) + X60Qx_732)) + X60Qx_733)) + X60Qx_734)) + X60Qx_735)));
            add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12628527270567457706_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_60), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I14428153832606577816_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_60), k_1);
            add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_60), w_4);
            add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
              .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_43), X60Qdesugar_60);
            add_2_sysvq0asl((&result_43), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I13453311567032255224_aow7lb5cq1)}
            );
            NI32 X60Qx_736 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I14393988487556796913_aow7lb5cq1)}
            );
            NI32 X60Qx_737 = len_4_sysvq0asl(k_1);
            NI32 X60Qx_738 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_739 = len_4_sysvq0asl(w_4);
            NI32 X60Qx_740 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_61 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_736 + X60Qx_737)) + X60Qx_738)) + X60Qx_739)) + X60Qx_740)));
            add_2_sysvq0asl((&X60Qdesugar_61), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I14393988487556796913_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_61), k_1);
            add_2_sysvq0asl((&X60Qdesugar_61), (string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_61), w_4);
            add_2_sysvq0asl((&X60Qdesugar_61), (string_0_sysvq0asl){
              .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_43), X60Qdesugar_61);
            NI32 X60Qx_741 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
            );
            NI32 X60Qx_742 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_743 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
            );
            NI32 X60Qx_744 = len_4_sysvq0asl(deallocFn_0);
            NI32 X60Qx_745 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
            );
            NI32 X60Qx_746 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_747 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_62 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_741 + X60Qx_742)) + X60Qx_743)) + X60Qx_744)) + X60Qx_745)) + X60Qx_746)) + X60Qx_747)));
            add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_62), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_62), deallocFn_0);
            add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
              .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_62), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
            );
            add_2_sysvq0asl(owned_0, X60Qdesugar_62);
            nimStrDestroy(X60Qdesugar_62);
            nimStrDestroy(X60Qdesugar_61);
            nimStrDestroy(X60Qdesugar_60);
            nimStrDestroy(X60Qdesugar_59);
            nimStrDestroy(X60Qdesugar_58);
            nimStrDestroy(X60Qdesugar_57);
            nimStrDestroy(X60Qdesugar_56);
            nimStrDestroy(X60Qdesugar_55);
            nimStrDestroy(X60Qdesugar_54);
            nimStrDestroy(w_4);}
          else {
            (*ok_0) = NIM_FALSE;}}}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_3);}
    break;
    case 10:
    case 11:
    {
      seq_0_Irn2j6w_aow7lb5cq1 flds_2 = structFields_0_aow7lb5cq1(unit_2, cty_0);
      if ((!(flds_2.len_0 == (*td_6).d_00.fields_0.len_0))){
        (*ok_0) = NIM_FALSE;
        eQdestroy_1_Iem8q971_aow7lb5cq1(flds_2);
        nimStrDestroy(k_1);
        return result_43;}
      NI32 i_19 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_748 = len_3_I5m68tr1_aow7lb5cq1((*td_6).d_00.fields_0);
          if (i_19 < X60Qx_748){
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_749 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_2, i_19);
            string_0_sysvq0asl X60Qdesugar_63 = nimStrDup((*X60Qx_749).fld_1);
            NI32 X60Qx_750 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_751 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_752 = len_4_sysvq0asl(X60Qdesugar_63);
            string_0_sysvq0asl X60Qdesugar_64 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_750 + X60Qx_751)) + X60Qx_752)));
            add_2_sysvq0asl((&X60Qdesugar_64), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_64), (string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_64), X60Qdesugar_63);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_753 = getQ_7_I45w7c91_aow7lb5cq1((*td_6).d_00.fields_0, i_19);
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_754 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_2, i_19);
            string_0_sysvq0asl X60Qtmp_32 = emitCompositeIn_0_aow7lb5cq1((*X60Qx_753), unit_2, (*X60Qx_754).fld_0, X60Qdesugar_64, strT_1, longT_1, allocFn_0, deallocFn_0, tmp_0, owned_0, ok_0);
            add_2_sysvq0asl((&result_43), X60Qtmp_32);
            if ((!(*ok_0))){
              nimStrDestroy(X60Qtmp_32);
              nimStrDestroy(X60Qdesugar_64);
              nimStrDestroy(X60Qdesugar_63);
              eQdestroy_1_Iem8q971_aow7lb5cq1(flds_2);
              nimStrDestroy(k_1);
              return result_43;}
            inc_1_I6wjjge_aow2h993l1((&i_19));
            nimStrDestroy(X60Qtmp_32);
            nimStrDestroy(X60Qdesugar_64);
            nimStrDestroy(X60Qdesugar_63);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      eQdestroy_1_Iem8q971_aow7lb5cq1(flds_2);}
    break;
    default:
    {
      (*ok_0) = NIM_FALSE;}
    break;}
  nimStrDestroy(k_1);
  return result_43;
  nimStrDestroy(k_1);
  return result_43;}
string_0_sysvq0asl emitCompositeOut_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_7, string_0_sysvq0asl unit_3, string_0_sysvq0asl cty_1, string_0_sysvq0asl src_7, string_0_sysvq0asl deallocFn_1, NI32* tmp_1, string_0_sysvq0asl* freeing_0, NB8* ok_1){
  string_0_sysvq0asl result_44;
  nimStrWasMoved((&result_44));
  nimStrDestroy(result_44);
  result_44 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((!(*ok_1))){
    return result_44;}
  inc_1_I6wjjge_aow2h993l1(tmp_1);
  string_0_sysvq0asl k_2 = dollarQ_2_sysvq0asl((*tmp_1));
  switch ((*td_7).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      NI32 X60Qx_755 = scalarWidth_0_aow7lb5cq1(td_7);
      string_0_sysvq0asl w_5 = dollarQ_2_sysvq0asl(X60Qx_755);
      NI32 X60Qx_756 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I12852333444401487702_aow7lb5cq1)}
      );
      NI32 X60Qx_757 = len_4_sysvq0asl(src_7);
      NI32 X60Qx_758 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2108418u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_759 = len_4_sysvq0asl(w_5);
      NI32 X60Qx_760 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I10044955599202107917_aow7lb5cq1)}
      );
      NI32 X60Qx_761 = len_4_sysvq0asl(w_5);
      NI32 X60Qx_762 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_65 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_756 + X60Qx_757)) + X60Qx_758)) + X60Qx_759)) + X60Qx_760)) + X60Qx_761)) + X60Qx_762)));
      add_2_sysvq0asl((&X60Qdesugar_65), (string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I12852333444401487702_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_65), src_7);
      add_2_sysvq0asl((&X60Qdesugar_65), (string_0_sysvq0asl){
        .bytes_0 = 2108418u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_65), w_5);
      add_2_sysvq0asl((&X60Qdesugar_65), (string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I10044955599202107917_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_65), w_5);
      add_2_sysvq0asl((&X60Qdesugar_65), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_44), X60Qdesugar_65);
      nimStrDestroy(X60Qdesugar_65);
      nimStrDestroy(w_5);}
    break;
    case 9:
    {
      NB8 X60Qx_763;
      NB8 X60Qx_764;
      if ((!((*td_7).d_00.elem_0 == NIM_NIL))){
        X60Qx_764 = ((*(*td_7).d_00.elem_0).d_00.kind_0 == 14);}
      else {
        X60Qx_764 = NIM_FALSE;}
      if (X60Qx_764){
        X60Qx_763 = (0 < (*td_7).d_00.count_0);}
      else {
        X60Qx_763 = NIM_FALSE;}
      if (X60Qx_763){
        string_0_sysvq0asl inner_2 = arrayInnerName_0_aow7lb5cq1(unit_3, cty_1);
        NI32 X60Qx_765 = len_4_sysvq0asl(inner_2);
        if (X60Qx_765 == 0){
          (*ok_1) = NIM_FALSE;
          nimStrDestroy(inner_2);
          nimStrDestroy(k_2);
          return result_44;}
        NI32 X60Qx_766 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
        );
        NI32 X60Qx_767 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_768 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_66 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_766 + X60Qx_767)) + X60Qx_768)));
        add_2_sysvq0asl((&X60Qdesugar_66), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_66), k_2);
        add_2_sysvq0asl((&X60Qdesugar_66), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_66);
        string_0_sysvq0asl X60Qdesugar_67 = dollarQ_2_sysvq0asl((*td_7).d_00.count_0);
        NI32 X60Qx_769 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
        );
        NI32 X60Qx_770 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_771 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540811267u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_772 = len_4_sysvq0asl(X60Qdesugar_67);
        NI32 X60Qx_773 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        NI32 X60Qx_774 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_775 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_68 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_769 + X60Qx_770)) + X60Qx_771)) + X60Qx_772)) + X60Qx_773)) + X60Qx_774)) + X60Qx_775)));
        add_2_sysvq0asl((&X60Qdesugar_68), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_68), k_2);
        add_2_sysvq0asl((&X60Qdesugar_68), (string_0_sysvq0asl){
          .bytes_0 = 540811267u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_68), X60Qdesugar_67);
        add_2_sysvq0asl((&X60Qdesugar_68), (string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_68), k_2);
        add_2_sysvq0asl((&X60Qdesugar_68), (string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_68);
        NI32 X60Qx_776 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I3568409834490710820_aow7lb5cq1)}
        );
        NI32 X60Qx_777 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_778 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
        );
        NI32 X60Qx_779 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_780 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 11777u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_781 = len_4_sysvq0asl(inner_2);
        NI32 X60Qx_782 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 6904578u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_783 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_784 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_69 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_776 + X60Qx_777)) + X60Qx_778)) + X60Qx_779)) + X60Qx_780)) + X60Qx_781)) + X60Qx_782)) + X60Qx_783)) + X60Qx_784)));
        add_2_sysvq0asl((&X60Qdesugar_69), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I3568409834490710820_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_69), k_2);
        add_2_sysvq0asl((&X60Qdesugar_69), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_69), src_7);
        add_2_sysvq0asl((&X60Qdesugar_69), (string_0_sysvq0asl){
          .bytes_0 = 11777u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_69), inner_2);
        add_2_sysvq0asl((&X60Qdesugar_69), (string_0_sysvq0asl){
          .bytes_0 = 6904578u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_69), k_2);
        add_2_sysvq0asl((&X60Qdesugar_69), (string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_69);
        NI32 X60Qx_785 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5460632544853264193_aow7lb5cq1)}
        );
        NI32 X60Qx_786 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_787 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
        );
        NI32 X60Qx_788 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_789 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 11777u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_790 = len_4_sysvq0asl(inner_2);
        NI32 X60Qx_791 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 6904578u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_792 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_793 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_70 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_785 + X60Qx_786)) + X60Qx_787)) + X60Qx_788)) + X60Qx_789)) + X60Qx_790)) + X60Qx_791)) + X60Qx_792)) + X60Qx_793)));
        add_2_sysvq0asl((&X60Qdesugar_70), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5460632544853264193_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_70), k_2);
        add_2_sysvq0asl((&X60Qdesugar_70), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_70), src_7);
        add_2_sysvq0asl((&X60Qdesugar_70), (string_0_sysvq0asl){
          .bytes_0 = 11777u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_70), inner_2);
        add_2_sysvq0asl((&X60Qdesugar_70), (string_0_sysvq0asl){
          .bytes_0 = 6904578u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_70), k_2);
        add_2_sysvq0asl((&X60Qdesugar_70), (string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_70);
        NI32 X60Qx_794 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I3320250923810778188_aow7lb5cq1)}
        );
        NI32 X60Qx_795 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_796 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_71 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_794 + X60Qx_795)) + X60Qx_796)));
        add_2_sysvq0asl((&X60Qdesugar_71), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I3320250923810778188_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_71), k_2);
        add_2_sysvq0asl((&X60Qdesugar_71), (string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_71);
        NI32 X60Qx_797 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11728457182134346010_aow7lb5cq1)}
        );
        NI32 X60Qx_798 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_799 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 673197310u, .more_0 = (&strlit_0_I5572117052193497108_aow7lb5cq1)}
        );
        NI32 X60Qx_800 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_801 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I4896779559304927306_aow7lb5cq1)}
        );
        NI32 X60Qx_802 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_803 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_72 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_797 + X60Qx_798)) + X60Qx_799)) + X60Qx_800)) + X60Qx_801)) + X60Qx_802)) + X60Qx_803)));
        add_2_sysvq0asl((&X60Qdesugar_72), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11728457182134346010_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_72), k_2);
        add_2_sysvq0asl((&X60Qdesugar_72), (string_0_sysvq0asl){
          .bytes_0 = 673197310u, .more_0 = (&strlit_0_I5572117052193497108_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_72), k_2);
        add_2_sysvq0asl((&X60Qdesugar_72), (string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I4896779559304927306_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_72), k_2);
        add_2_sysvq0asl((&X60Qdesugar_72), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_72);
        add_2_sysvq0asl((&result_44), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15342668115246402447_aow7lb5cq1)}
        );
        nimStrDestroy(X60Qdesugar_72);
        nimStrDestroy(X60Qdesugar_71);
        nimStrDestroy(X60Qdesugar_70);
        nimStrDestroy(X60Qdesugar_69);
        nimStrDestroy(X60Qdesugar_68);
        nimStrDestroy(X60Qdesugar_67);
        nimStrDestroy(X60Qdesugar_66);
        nimStrDestroy(inner_2);
        nimStrDestroy(k_2);
        return result_44;
        nimStrDestroy(X60Qdesugar_72);
        nimStrDestroy(X60Qdesugar_71);
        nimStrDestroy(X60Qdesugar_70);
        nimStrDestroy(X60Qdesugar_69);
        nimStrDestroy(X60Qdesugar_68);
        nimStrDestroy(X60Qdesugar_67);
        nimStrDestroy(X60Qdesugar_66);
        nimStrDestroy(inner_2);}
      NB8 X60Qx_804;
      NB8 X60Qx_805 = packedScalarOk_0_aow7lb5cq1((*td_7).d_00.elem_0);
      if ((!X60Qx_805)){
        X60Qx_804 = NIM_TRUE;}
      else {
        X60Qx_804 = ((*td_7).d_00.count_0 <= 0);}
      if (X60Qx_804){
        (*ok_1) = NIM_FALSE;
        nimStrDestroy(k_2);
        return result_44;}
      string_0_sysvq0asl inner_3 = arrayInnerName_0_aow7lb5cq1(unit_3, cty_1);
      NI32 X60Qx_806 = len_4_sysvq0asl(inner_3);
      if (X60Qx_806 == 0){
        (*ok_1) = NIM_FALSE;
        nimStrDestroy(inner_3);
        nimStrDestroy(k_2);
        return result_44;}
      NI32 X60Qx_807 = scalarWidth_0_aow7lb5cq1((*td_7).d_00.elem_0);
      string_0_sysvq0asl nb_1 = dollarQ_2_sysvq0asl(((NI32)((*td_7).d_00.count_0 * X60Qx_807)));
      NI32 X60Qx_808 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
      );
      NI32 X60Qx_809 = len_4_sysvq0asl(src_7);
      NI32 X60Qx_810 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 11777u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_811 = len_4_sysvq0asl(inner_3);
      NI32 X60Qx_812 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
      );
      NI32 X60Qx_813 = len_4_sysvq0asl(nb_1);
      NI32 X60Qx_814 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 572534014u, .more_0 = (&strlit_0_I4129744452504341063_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_73 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_808 + X60Qx_809)) + X60Qx_810)) + X60Qx_811)) + X60Qx_812)) + X60Qx_813)) + X60Qx_814)));
      add_2_sysvq0asl((&X60Qdesugar_73), (string_0_sysvq0asl){
        .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_73), src_7);
      add_2_sysvq0asl((&X60Qdesugar_73), (string_0_sysvq0asl){
        .bytes_0 = 11777u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_73), inner_3);
      add_2_sysvq0asl((&X60Qdesugar_73), (string_0_sysvq0asl){
        .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_73), nb_1);
      add_2_sysvq0asl((&X60Qdesugar_73), (string_0_sysvq0asl){
        .bytes_0 = 572534014u, .more_0 = (&strlit_0_I4129744452504341063_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_44), X60Qdesugar_73);
      NI32 X60Qx_815 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I11758806364787972807_aow7lb5cq1)}
      );
      NI32 X60Qx_816 = len_4_sysvq0asl(src_7);
      NI32 X60Qx_817 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 11777u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_818 = len_4_sysvq0asl(inner_3);
      NI32 X60Qx_819 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2108418u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_820 = len_4_sysvq0asl(nb_1);
      NI32 X60Qx_821 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I10044955599202107917_aow7lb5cq1)}
      );
      NI32 X60Qx_822 = len_4_sysvq0asl(nb_1);
      NI32 X60Qx_823 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_74 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_815 + X60Qx_816)) + X60Qx_817)) + X60Qx_818)) + X60Qx_819)) + X60Qx_820)) + X60Qx_821)) + X60Qx_822)) + X60Qx_823)));
      add_2_sysvq0asl((&X60Qdesugar_74), (string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I11758806364787972807_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_74), src_7);
      add_2_sysvq0asl((&X60Qdesugar_74), (string_0_sysvq0asl){
        .bytes_0 = 11777u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_74), inner_3);
      add_2_sysvq0asl((&X60Qdesugar_74), (string_0_sysvq0asl){
        .bytes_0 = 2108418u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_74), nb_1);
      add_2_sysvq0asl((&X60Qdesugar_74), (string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I10044955599202107917_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_74), nb_1);
      add_2_sysvq0asl((&X60Qdesugar_74), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_44), X60Qdesugar_74);
      nimStrDestroy(X60Qdesugar_74);
      nimStrDestroy(X60Qdesugar_73);
      nimStrDestroy(nb_1);
      nimStrDestroy(inner_3);}
    break;
    case 14:
    {
      NI32 X60Qx_824 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
      );
      NI32 X60Qx_825 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_826 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
      );
      NI32 X60Qx_827 = len_4_sysvq0asl(src_7);
      NI32 X60Qx_828 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_75 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_824 + X60Qx_825)) + X60Qx_826)) + X60Qx_827)) + X60Qx_828)));
      add_2_sysvq0asl((&X60Qdesugar_75), (string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_75), k_2);
      add_2_sysvq0asl((&X60Qdesugar_75), (string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_75), src_7);
      add_2_sysvq0asl((&X60Qdesugar_75), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_44), X60Qdesugar_75);
      NI32 X60Qx_829 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18035457312318603665_aow7lb5cq1)}
      );
      NI32 X60Qx_830 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_831 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
      );
      NI32 X60Qx_832 = len_4_sysvq0asl(src_7);
      NI32 X60Qx_833 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_76 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_829 + X60Qx_830)) + X60Qx_831)) + X60Qx_832)) + X60Qx_833)));
      add_2_sysvq0asl((&X60Qdesugar_76), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18035457312318603665_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_76), k_2);
      add_2_sysvq0asl((&X60Qdesugar_76), (string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_76), src_7);
      add_2_sysvq0asl((&X60Qdesugar_76), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_44), X60Qdesugar_76);
      NI32 X60Qx_834 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
      );
      NI32 X60Qx_835 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_836 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_77 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_834 + X60Qx_835)) + X60Qx_836)));
      add_2_sysvq0asl((&X60Qdesugar_77), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_77), k_2);
      add_2_sysvq0asl((&X60Qdesugar_77), (string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_44), X60Qdesugar_77);
      NI32 X60Qx_837 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5713563946092690572_aow7lb5cq1)}
      );
      NI32 X60Qx_838 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_839 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 673197310u, .more_0 = (&strlit_0_I18233374301631325590_aow7lb5cq1)}
      );
      NI32 X60Qx_840 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_841 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I3705825639434928729_aow7lb5cq1)}
      );
      NI32 X60Qx_842 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_843 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_78 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_837 + X60Qx_838)) + X60Qx_839)) + X60Qx_840)) + X60Qx_841)) + X60Qx_842)) + X60Qx_843)));
      add_2_sysvq0asl((&X60Qdesugar_78), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5713563946092690572_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_78), k_2);
      add_2_sysvq0asl((&X60Qdesugar_78), (string_0_sysvq0asl){
        .bytes_0 = 673197310u, .more_0 = (&strlit_0_I18233374301631325590_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_78), k_2);
      add_2_sysvq0asl((&X60Qdesugar_78), (string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I3705825639434928729_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_78), k_2);
      add_2_sysvq0asl((&X60Qdesugar_78), (string_0_sysvq0asl){
        .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_44), X60Qdesugar_78);
      nimStrDestroy(X60Qdesugar_78);
      nimStrDestroy(X60Qdesugar_77);
      nimStrDestroy(X60Qdesugar_76);
      nimStrDestroy(X60Qdesugar_75);}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_4 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_7).d_00.elem_0);
      if (el_4 == NIM_NIL){
        (*ok_1) = NIM_FALSE;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_4);
        nimStrDestroy(k_2);
        return result_44;}
      if ((*el_4).d_00.kind_0 == 14){
        NI32 X60Qx_844 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        NI32 X60Qx_845 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_846 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_847 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_848 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_79 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_844 + X60Qx_845)) + X60Qx_846)) + X60Qx_847)) + X60Qx_848)));
        add_2_sysvq0asl((&X60Qdesugar_79), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_79), k_2);
        add_2_sysvq0asl((&X60Qdesugar_79), (string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_79), src_7);
        add_2_sysvq0asl((&X60Qdesugar_79), (string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_79);
        NI32 X60Qx_849 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
        );
        NI32 X60Qx_850 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_851 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_80 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_849 + X60Qx_850)) + X60Qx_851)));
        add_2_sysvq0asl((&X60Qdesugar_80), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_80), k_2);
        add_2_sysvq0asl((&X60Qdesugar_80), (string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_80);
        NI32 X60Qx_852 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        NI32 X60Qx_853 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_854 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_81 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_852 + X60Qx_853)) + X60Qx_854)));
        add_2_sysvq0asl((&X60Qdesugar_81), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_81), k_2);
        add_2_sysvq0asl((&X60Qdesugar_81), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_81);
        NI32 X60Qx_855 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        NI32 X60Qx_856 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_857 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        NI32 X60Qx_858 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_859 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        NI32 X60Qx_860 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_861 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_82 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_855 + X60Qx_856)) + X60Qx_857)) + X60Qx_858)) + X60Qx_859)) + X60Qx_860)) + X60Qx_861)));
        add_2_sysvq0asl((&X60Qdesugar_82), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_82), k_2);
        add_2_sysvq0asl((&X60Qdesugar_82), (string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_82), k_2);
        add_2_sysvq0asl((&X60Qdesugar_82), (string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_82), k_2);
        add_2_sysvq0asl((&X60Qdesugar_82), (string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_82);
        NI32 X60Qx_862 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5809312286091816554_aow7lb5cq1)}
        );
        NI32 X60Qx_863 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_864 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
        );
        NI32 X60Qx_865 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_866 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        NI32 X60Qx_867 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_868 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_83 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_862 + X60Qx_863)) + X60Qx_864)) + X60Qx_865)) + X60Qx_866)) + X60Qx_867)) + X60Qx_868)));
        add_2_sysvq0asl((&X60Qdesugar_83), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5809312286091816554_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_83), k_2);
        add_2_sysvq0asl((&X60Qdesugar_83), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_83), src_7);
        add_2_sysvq0asl((&X60Qdesugar_83), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_83), k_2);
        add_2_sysvq0asl((&X60Qdesugar_83), (string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_83);
        NI32 X60Qx_869 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12283458923584918919_aow7lb5cq1)}
        );
        NI32 X60Qx_870 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_871 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
        );
        NI32 X60Qx_872 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_873 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        NI32 X60Qx_874 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_875 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_84 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_869 + X60Qx_870)) + X60Qx_871)) + X60Qx_872)) + X60Qx_873)) + X60Qx_874)) + X60Qx_875)));
        add_2_sysvq0asl((&X60Qdesugar_84), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12283458923584918919_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_84), k_2);
        add_2_sysvq0asl((&X60Qdesugar_84), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_84), src_7);
        add_2_sysvq0asl((&X60Qdesugar_84), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_84), k_2);
        add_2_sysvq0asl((&X60Qdesugar_84), (string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_84);
        NI32 X60Qx_876 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4141503729763329410_aow7lb5cq1)}
        );
        NI32 X60Qx_877 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_878 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_85 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_876 + X60Qx_877)) + X60Qx_878)));
        add_2_sysvq0asl((&X60Qdesugar_85), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4141503729763329410_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_85), k_2);
        add_2_sysvq0asl((&X60Qdesugar_85), (string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_85);
        NI32 X60Qx_879 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17936778126182439409_aow7lb5cq1)}
        );
        NI32 X60Qx_880 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_881 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 673197310u, .more_0 = (&strlit_0_I5572117052193497108_aow7lb5cq1)}
        );
        NI32 X60Qx_882 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_883 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I4896779559304927306_aow7lb5cq1)}
        );
        NI32 X60Qx_884 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_885 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_86 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_879 + X60Qx_880)) + X60Qx_881)) + X60Qx_882)) + X60Qx_883)) + X60Qx_884)) + X60Qx_885)));
        add_2_sysvq0asl((&X60Qdesugar_86), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17936778126182439409_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_86), k_2);
        add_2_sysvq0asl((&X60Qdesugar_86), (string_0_sysvq0asl){
          .bytes_0 = 673197310u, .more_0 = (&strlit_0_I5572117052193497108_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_86), k_2);
        add_2_sysvq0asl((&X60Qdesugar_86), (string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I4896779559304927306_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_86), k_2);
        add_2_sysvq0asl((&X60Qdesugar_86), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_44), X60Qdesugar_86);
        add_2_sysvq0asl((&result_44), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I7306224084071035336_aow7lb5cq1)}
        );
        NI32 X60Qx_886 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        NI32 X60Qx_887 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_888 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        NI32 X60Qx_889 = len_4_sysvq0asl(deallocFn_1);
        NI32 X60Qx_890 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        NI32 X60Qx_891 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_892 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_87 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_886 + X60Qx_887)) + X60Qx_888)) + X60Qx_889)) + X60Qx_890)) + X60Qx_891)) + X60Qx_892)));
        add_2_sysvq0asl((&X60Qdesugar_87), (string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_87), src_7);
        add_2_sysvq0asl((&X60Qdesugar_87), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_87), deallocFn_1);
        add_2_sysvq0asl((&X60Qdesugar_87), (string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_87), src_7);
        add_2_sysvq0asl((&X60Qdesugar_87), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        add_2_sysvq0asl(freeing_0, X60Qdesugar_87);
        nimStrDestroy(X60Qdesugar_87);
        nimStrDestroy(X60Qdesugar_86);
        nimStrDestroy(X60Qdesugar_85);
        nimStrDestroy(X60Qdesugar_84);
        nimStrDestroy(X60Qdesugar_83);
        nimStrDestroy(X60Qdesugar_82);
        nimStrDestroy(X60Qdesugar_81);
        nimStrDestroy(X60Qdesugar_80);
        nimStrDestroy(X60Qdesugar_79);}
      else {
        NB8 X60Qx_893;
        if ((*el_4).d_00.kind_0 == 10){
          X60Qx_893 = NIM_TRUE;}
        else {
          X60Qx_893 = ((*el_4).d_00.kind_0 == 11);}
        if (X60Qx_893){
          string_0_sysvq0asl ect_1 = seqElemCType_0_aow7lb5cq1(unit_3, cty_1);
          NI32 X60Qx_894 = len_4_sysvq0asl(ect_1);
          if (X60Qx_894 == 0){
            (*ok_1) = NIM_FALSE;
            nimStrDestroy(ect_1);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_4);
            nimStrDestroy(k_2);
            return result_44;}
          NI32 X60Qx_895 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
          );
          NI32 X60Qx_896 = len_4_sysvq0asl(k_2);
          NI32 X60Qx_897 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540876803u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_898 = len_4_sysvq0asl(src_7);
          NI32 X60Qx_899 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_88 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_895 + X60Qx_896)) + X60Qx_897)) + X60Qx_898)) + X60Qx_899)));
          add_2_sysvq0asl((&X60Qdesugar_88), (string_0_sysvq0asl){
            .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_88), k_2);
          add_2_sysvq0asl((&X60Qdesugar_88), (string_0_sysvq0asl){
            .bytes_0 = 540876803u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_88), src_7);
          add_2_sysvq0asl((&X60Qdesugar_88), (string_0_sysvq0asl){
            .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_44), X60Qdesugar_88);
          NI32 X60Qx_900 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
          );
          NI32 X60Qx_901 = len_4_sysvq0asl(k_2);
          NI32 X60Qx_902 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_89 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_900 + X60Qx_901)) + X60Qx_902)));
          add_2_sysvq0asl((&X60Qdesugar_89), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_89), k_2);
          add_2_sysvq0asl((&X60Qdesugar_89), (string_0_sysvq0asl){
            .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_44), X60Qdesugar_89);
          NI32 X60Qx_903 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
          );
          NI32 X60Qx_904 = len_4_sysvq0asl(k_2);
          NI32 X60Qx_905 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_90 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_903 + X60Qx_904)) + X60Qx_905)));
          add_2_sysvq0asl((&X60Qdesugar_90), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_90), k_2);
          add_2_sysvq0asl((&X60Qdesugar_90), (string_0_sysvq0asl){
            .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_44), X60Qdesugar_90);
          NI32 X60Qx_906 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
          );
          NI32 X60Qx_907 = len_4_sysvq0asl(k_2);
          NI32 X60Qx_908 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
          );
          NI32 X60Qx_909 = len_4_sysvq0asl(k_2);
          NI32 X60Qx_910 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
          );
          NI32 X60Qx_911 = len_4_sysvq0asl(k_2);
          NI32 X60Qx_912 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_91 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_906 + X60Qx_907)) + X60Qx_908)) + X60Qx_909)) + X60Qx_910)) + X60Qx_911)) + X60Qx_912)));
          add_2_sysvq0asl((&X60Qdesugar_91), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_91), k_2);
          add_2_sysvq0asl((&X60Qdesugar_91), (string_0_sysvq0asl){
            .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_91), k_2);
          add_2_sysvq0asl((&X60Qdesugar_91), (string_0_sysvq0asl){
            .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_91), k_2);
          add_2_sysvq0asl((&X60Qdesugar_91), (string_0_sysvq0asl){
            .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_44), X60Qdesugar_91);
          string_0_sysvq0asl elemFreeing_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          NI32 X60Qx_913 = len_4_sysvq0asl(src_7);
          NI32 X60Qx_914 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
          );
          NI32 X60Qx_915 = len_4_sysvq0asl(k_2);
          NI32 X60Qx_916 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_92 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_913 + X60Qx_914)) + X60Qx_915)) + X60Qx_916)));
          add_2_sysvq0asl((&X60Qdesugar_92), src_7);
          add_2_sysvq0asl((&X60Qdesugar_92), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_92), k_2);
          add_2_sysvq0asl((&X60Qdesugar_92), (string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl body_2 = emitCompositeOut_0_aow7lb5cq1(el_4, unit_3, ect_1, X60Qdesugar_92, deallocFn_1, tmp_1, (&elemFreeing_0), ok_1);
          if ((!(*ok_1))){
            nimStrDestroy(body_2);
            nimStrDestroy(X60Qdesugar_92);
            nimStrDestroy(elemFreeing_0);
            nimStrDestroy(X60Qdesugar_91);
            nimStrDestroy(X60Qdesugar_90);
            nimStrDestroy(X60Qdesugar_89);
            nimStrDestroy(X60Qdesugar_88);
            nimStrDestroy(ect_1);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_4);
            nimStrDestroy(k_2);
            return result_44;}
          add_2_sysvq0asl((&result_44), body_2);
          add_2_sysvq0asl((&result_44), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I7306224084071035336_aow7lb5cq1)}
          );
          NI32 X60Qx_917 = len_4_sysvq0asl(elemFreeing_0);
          if (0 < X60Qx_917){
            NI32 X60Qx_918 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
            );
            NI32 X60Qx_919 = len_4_sysvq0asl(k_2);
            NI32 X60Qx_920 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_93 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_918 + X60Qx_919)) + X60Qx_920)));
            add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
              .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_93), k_2);
            add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
            );
            add_2_sysvq0asl(freeing_0, X60Qdesugar_93);
            NI32 X60Qx_921 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
            );
            NI32 X60Qx_922 = len_4_sysvq0asl(k_2);
            NI32 X60Qx_923 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540811267u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_924 = len_4_sysvq0asl(src_7);
            NI32 X60Qx_925 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I6325254588340587598_aow7lb5cq1)}
            );
            NI32 X60Qx_926 = len_4_sysvq0asl(k_2);
            NI32 X60Qx_927 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_94 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_921 + X60Qx_922)) + X60Qx_923)) + X60Qx_924)) + X60Qx_925)) + X60Qx_926)) + X60Qx_927)));
            add_2_sysvq0asl((&X60Qdesugar_94), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_94), k_2);
            add_2_sysvq0asl((&X60Qdesugar_94), (string_0_sysvq0asl){
              .bytes_0 = 540811267u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_94), src_7);
            add_2_sysvq0asl((&X60Qdesugar_94), (string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I6325254588340587598_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_94), k_2);
            add_2_sysvq0asl((&X60Qdesugar_94), (string_0_sysvq0asl){
              .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
            );
            add_2_sysvq0asl(freeing_0, X60Qdesugar_94);
            add_2_sysvq0asl(freeing_0, elemFreeing_0);
            add_2_sysvq0asl(freeing_0, (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15342668115246402447_aow7lb5cq1)}
            );
            nimStrDestroy(X60Qdesugar_94);
            nimStrDestroy(X60Qdesugar_93);}
          NI32 X60Qx_928 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
          );
          NI32 X60Qx_929 = len_4_sysvq0asl(src_7);
          NI32 X60Qx_930 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
          );
          NI32 X60Qx_931 = len_4_sysvq0asl(deallocFn_1);
          NI32 X60Qx_932 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
          );
          NI32 X60Qx_933 = len_4_sysvq0asl(src_7);
          NI32 X60Qx_934 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_95 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_928 + X60Qx_929)) + X60Qx_930)) + X60Qx_931)) + X60Qx_932)) + X60Qx_933)) + X60Qx_934)));
          add_2_sysvq0asl((&X60Qdesugar_95), (string_0_sysvq0asl){
            .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_95), src_7);
          add_2_sysvq0asl((&X60Qdesugar_95), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_95), deallocFn_1);
          add_2_sysvq0asl((&X60Qdesugar_95), (string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_95), src_7);
          add_2_sysvq0asl((&X60Qdesugar_95), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
          );
          add_2_sysvq0asl(freeing_0, X60Qdesugar_95);
          nimStrDestroy(X60Qdesugar_95);
          nimStrDestroy(body_2);
          nimStrDestroy(X60Qdesugar_92);
          nimStrDestroy(elemFreeing_0);
          nimStrDestroy(X60Qdesugar_91);
          nimStrDestroy(X60Qdesugar_90);
          nimStrDestroy(X60Qdesugar_89);
          nimStrDestroy(X60Qdesugar_88);
          nimStrDestroy(ect_1);}
        else {
          NB8 X60Qx_935;
          NB8 X60Qx_936;
          NB8 X60Qx_937;
          NB8 X60Qx_938;
          NB8 X60Qx_939;
          if ((*el_4).d_00.kind_0 == 0){
            X60Qx_939 = NIM_TRUE;}
          else {
            X60Qx_939 = ((*el_4).d_00.kind_0 == 1);}
          if (X60Qx_939){
            X60Qx_938 = NIM_TRUE;}
          else {
            X60Qx_938 = ((*el_4).d_00.kind_0 == 2);}
          if (X60Qx_938){
            X60Qx_937 = NIM_TRUE;}
          else {
            X60Qx_937 = ((*el_4).d_00.kind_0 == 3);}
          if (X60Qx_937){
            X60Qx_936 = NIM_TRUE;}
          else {
            X60Qx_936 = ((*el_4).d_00.kind_0 == 4);}
          if (X60Qx_936){
            X60Qx_935 = NIM_TRUE;}
          else {
            X60Qx_935 = ((*el_4).d_00.kind_0 == 8);}
          if (X60Qx_935){
            NI32 X60Qx_940 = scalarWidth_0_aow7lb5cq1(el_4);
            string_0_sysvq0asl w_6 = dollarQ_2_sysvq0asl(X60Qx_940);
            NI32 X60Qx_941 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
            );
            NI32 X60Qx_942 = len_4_sysvq0asl(k_2);
            NI32 X60Qx_943 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540876803u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_944 = len_4_sysvq0asl(src_7);
            NI32 X60Qx_945 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_96 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_941 + X60Qx_942)) + X60Qx_943)) + X60Qx_944)) + X60Qx_945)));
            add_2_sysvq0asl((&X60Qdesugar_96), (string_0_sysvq0asl){
              .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_96), k_2);
            add_2_sysvq0asl((&X60Qdesugar_96), (string_0_sysvq0asl){
              .bytes_0 = 540876803u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_96), src_7);
            add_2_sysvq0asl((&X60Qdesugar_96), (string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_44), X60Qdesugar_96);
            NI32 X60Qx_946 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16570386306475740535_aow7lb5cq1)}
            );
            NI32 X60Qx_947 = len_4_sysvq0asl(src_7);
            NI32 X60Qx_948 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
            );
            NI32 X60Qx_949 = len_4_sysvq0asl(w_6);
            NI32 X60Qx_950 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_97 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_946 + X60Qx_947)) + X60Qx_948)) + X60Qx_949)) + X60Qx_950)));
            add_2_sysvq0asl((&X60Qdesugar_97), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16570386306475740535_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_97), src_7);
            add_2_sysvq0asl((&X60Qdesugar_97), (string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_97), w_6);
            add_2_sysvq0asl((&X60Qdesugar_97), (string_0_sysvq0asl){
              .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_44), X60Qdesugar_97);
            NI32 X60Qx_951 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
            );
            NI32 X60Qx_952 = len_4_sysvq0asl(k_2);
            NI32 X60Qx_953 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_98 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_951 + X60Qx_952)) + X60Qx_953)));
            add_2_sysvq0asl((&X60Qdesugar_98), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_98), k_2);
            add_2_sysvq0asl((&X60Qdesugar_98), (string_0_sysvq0asl){
              .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_44), X60Qdesugar_98);
            NI32 X60Qx_954 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
            );
            NI32 X60Qx_955 = len_4_sysvq0asl(k_2);
            NI32 X60Qx_956 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540942590u, .more_0 = (&strlit_0_I16820758988003013266_aow7lb5cq1)}
            );
            NI32 X60Qx_957 = len_4_sysvq0asl(src_7);
            NI32 X60Qx_958 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I8608436586241119281_aow7lb5cq1)}
            );
            NI32 X60Qx_959 = len_4_sysvq0asl(k_2);
            NI32 X60Qx_960 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_961 = len_4_sysvq0asl(w_6);
            NI32 X60Qx_962 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_99 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_954 + X60Qx_955)) + X60Qx_956)) + X60Qx_957)) + X60Qx_958)) + X60Qx_959)) + X60Qx_960)) + X60Qx_961)) + X60Qx_962)));
            add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_99), k_2);
            add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
              .bytes_0 = 540942590u, .more_0 = (&strlit_0_I16820758988003013266_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_99), src_7);
            add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I8608436586241119281_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_99), k_2);
            add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_99), w_6);
            add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
              .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_44), X60Qdesugar_99);
            NI32 X60Qx_963 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5027967502149894354_aow7lb5cq1)}
            );
            NI32 X60Qx_964 = len_4_sysvq0asl(k_2);
            NI32 X60Qx_965 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_966 = len_4_sysvq0asl(w_6);
            NI32 X60Qx_967 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_100 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_963 + X60Qx_964)) + X60Qx_965)) + X60Qx_966)) + X60Qx_967)));
            add_2_sysvq0asl((&X60Qdesugar_100), (string_0_sysvq0asl){
              .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5027967502149894354_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_100), k_2);
            add_2_sysvq0asl((&X60Qdesugar_100), (string_0_sysvq0asl){
              .bytes_0 = 539631619u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_100), w_6);
            add_2_sysvq0asl((&X60Qdesugar_100), (string_0_sysvq0asl){
              .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_44), X60Qdesugar_100);
            NI32 X60Qx_968 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
            );
            NI32 X60Qx_969 = len_4_sysvq0asl(src_7);
            NI32 X60Qx_970 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
            );
            NI32 X60Qx_971 = len_4_sysvq0asl(deallocFn_1);
            NI32 X60Qx_972 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
            );
            NI32 X60Qx_973 = len_4_sysvq0asl(src_7);
            NI32 X60Qx_974 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_101 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_968 + X60Qx_969)) + X60Qx_970)) + X60Qx_971)) + X60Qx_972)) + X60Qx_973)) + X60Qx_974)));
            add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_101), src_7);
            add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_101), deallocFn_1);
            add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
              .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_101), src_7);
            add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
              .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
            );
            add_2_sysvq0asl(freeing_0, X60Qdesugar_101);
            nimStrDestroy(X60Qdesugar_101);
            nimStrDestroy(X60Qdesugar_100);
            nimStrDestroy(X60Qdesugar_99);
            nimStrDestroy(X60Qdesugar_98);
            nimStrDestroy(X60Qdesugar_97);
            nimStrDestroy(X60Qdesugar_96);
            nimStrDestroy(w_6);}
          else {
            (*ok_1) = NIM_FALSE;}}}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_4);}
    break;
    case 10:
    case 11:
    {
      seq_0_Irn2j6w_aow7lb5cq1 flds_3 = structFields_0_aow7lb5cq1(unit_3, cty_1);
      if ((!(flds_3.len_0 == (*td_7).d_00.fields_0.len_0))){
        (*ok_1) = NIM_FALSE;
        eQdestroy_1_Iem8q971_aow7lb5cq1(flds_3);
        nimStrDestroy(k_2);
        return result_44;}
      NI32 i_20 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_975 = len_3_I5m68tr1_aow7lb5cq1((*td_7).d_00.fields_0);
          if (i_20 < X60Qx_975){
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_976 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_3, i_20);
            string_0_sysvq0asl X60Qdesugar_102 = nimStrDup((*X60Qx_976).fld_1);
            NI32 X60Qx_977 = len_4_sysvq0asl(src_7);
            NI32 X60Qx_978 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_979 = len_4_sysvq0asl(X60Qdesugar_102);
            string_0_sysvq0asl X60Qdesugar_103 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_977 + X60Qx_978)) + X60Qx_979)));
            add_2_sysvq0asl((&X60Qdesugar_103), src_7);
            add_2_sysvq0asl((&X60Qdesugar_103), (string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_103), X60Qdesugar_102);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_980 = getQ_7_I45w7c91_aow7lb5cq1((*td_7).d_00.fields_0, i_20);
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_981 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_3, i_20);
            string_0_sysvq0asl X60Qtmp_33 = emitCompositeOut_0_aow7lb5cq1((*X60Qx_980), unit_3, (*X60Qx_981).fld_0, X60Qdesugar_103, deallocFn_1, tmp_1, freeing_0, ok_1);
            add_2_sysvq0asl((&result_44), X60Qtmp_33);
            if ((!(*ok_1))){
              nimStrDestroy(X60Qtmp_33);
              nimStrDestroy(X60Qdesugar_103);
              nimStrDestroy(X60Qdesugar_102);
              eQdestroy_1_Iem8q971_aow7lb5cq1(flds_3);
              nimStrDestroy(k_2);
              return result_44;}
            inc_1_I6wjjge_aow2h993l1((&i_20));
            nimStrDestroy(X60Qtmp_33);
            nimStrDestroy(X60Qdesugar_103);
            nimStrDestroy(X60Qdesugar_102);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      eQdestroy_1_Iem8q971_aow7lb5cq1(flds_3);}
    break;
    default:
    {
      (*ok_1) = NIM_FALSE;}
    break;}
  nimStrDestroy(k_2);
  return result_44;
  nimStrDestroy(k_2);
  return result_44;}
string_0_sysvq0asl emitCompositeSize_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_8, string_0_sysvq0asl unit_4, string_0_sysvq0asl cty_2, string_0_sysvq0asl src_8, NI32* tmp_2, NB8* ok_2){
  string_0_sysvq0asl result_45;
  nimStrWasMoved((&result_45));
  nimStrDestroy(result_45);
  result_45 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((!(*ok_2))){
    return result_45;}
  inc_1_I6wjjge_aow2h993l1(tmp_2);
  string_0_sysvq0asl k_3 = dollarQ_2_sysvq0asl((*tmp_2));
  switch ((*td_8).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      NI32 X60Qx_982 = scalarWidth_0_aow7lb5cq1(td_8);
      string_0_sysvq0asl X60Qdesugar_104 = dollarQ_2_sysvq0asl(X60Qx_982);
      NI32 X60Qx_983 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I6738090623860882514_aow7lb5cq1)}
      );
      NI32 X60Qx_984 = len_4_sysvq0asl(X60Qdesugar_104);
      NI32 X60Qx_985 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_105 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_983 + X60Qx_984)) + X60Qx_985)));
      add_2_sysvq0asl((&X60Qdesugar_105), (string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I6738090623860882514_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_105), X60Qdesugar_104);
      add_2_sysvq0asl((&X60Qdesugar_105), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_45), X60Qdesugar_105);
      nimStrDestroy(X60Qdesugar_105);
      nimStrDestroy(X60Qdesugar_104);}
    break;
    case 9:
    {
      NB8 X60Qx_986;
      NB8 X60Qx_987;
      if ((!((*td_8).d_00.elem_0 == NIM_NIL))){
        X60Qx_987 = ((*(*td_8).d_00.elem_0).d_00.kind_0 == 14);}
      else {
        X60Qx_987 = NIM_FALSE;}
      if (X60Qx_987){
        X60Qx_986 = (0 < (*td_8).d_00.count_0);}
      else {
        X60Qx_986 = NIM_FALSE;}
      if (X60Qx_986){
        string_0_sysvq0asl inner_4 = arrayInnerName_0_aow7lb5cq1(unit_4, cty_2);
        NI32 X60Qx_988 = len_4_sysvq0asl(inner_4);
        if (X60Qx_988 == 0){
          (*ok_2) = NIM_FALSE;
          nimStrDestroy(inner_4);
          nimStrDestroy(k_3);
          return result_45;}
        NI32 X60Qx_989 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
        );
        NI32 X60Qx_990 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_991 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_106 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_989 + X60Qx_990)) + X60Qx_991)));
        add_2_sysvq0asl((&X60Qdesugar_106), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_106), k_3);
        add_2_sysvq0asl((&X60Qdesugar_106), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_45), X60Qdesugar_106);
        string_0_sysvq0asl X60Qdesugar_107 = dollarQ_2_sysvq0asl((*td_8).d_00.count_0);
        NI32 X60Qx_992 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
        );
        NI32 X60Qx_993 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_994 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540811267u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_995 = len_4_sysvq0asl(X60Qdesugar_107);
        NI32 X60Qx_996 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        NI32 X60Qx_997 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_998 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 665858u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_108 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_992 + X60Qx_993)) + X60Qx_994)) + X60Qx_995)) + X60Qx_996)) + X60Qx_997)) + X60Qx_998)));
        add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_108), k_3);
        add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
          .bytes_0 = 540811267u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_108), X60Qdesugar_107);
        add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_108), k_3);
        add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
          .bytes_0 = 665858u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_45), X60Qdesugar_108);
        NI32 X60Qx_999 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15442873908045290837_aow7lb5cq1)}
        );
        NI32 X60Qx_1000 = len_4_sysvq0asl(src_8);
        NI32 X60Qx_1001 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 11777u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_1002 = len_4_sysvq0asl(inner_4);
        NI32 X60Qx_1003 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 6904578u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_1004 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_1005 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_109 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_999 + X60Qx_1000)) + X60Qx_1001)) + X60Qx_1002)) + X60Qx_1003)) + X60Qx_1004)) + X60Qx_1005)));
        add_2_sysvq0asl((&X60Qdesugar_109), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15442873908045290837_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_109), src_8);
        add_2_sysvq0asl((&X60Qdesugar_109), (string_0_sysvq0asl){
          .bytes_0 = 11777u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_109), inner_4);
        add_2_sysvq0asl((&X60Qdesugar_109), (string_0_sysvq0asl){
          .bytes_0 = 6904578u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_109), k_3);
        add_2_sysvq0asl((&X60Qdesugar_109), (string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_45), X60Qdesugar_109);
        add_2_sysvq0asl((&result_45), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I13453311567032255224_aow7lb5cq1)}
        );
        nimStrDestroy(X60Qdesugar_109);
        nimStrDestroy(X60Qdesugar_108);
        nimStrDestroy(X60Qdesugar_107);
        nimStrDestroy(X60Qdesugar_106);
        nimStrDestroy(inner_4);
        nimStrDestroy(k_3);
        return result_45;
        nimStrDestroy(X60Qdesugar_109);
        nimStrDestroy(X60Qdesugar_108);
        nimStrDestroy(X60Qdesugar_107);
        nimStrDestroy(X60Qdesugar_106);
        nimStrDestroy(inner_4);}
      NB8 X60Qx_1006;
      NB8 X60Qx_1007 = packedScalarOk_0_aow7lb5cq1((*td_8).d_00.elem_0);
      if ((!X60Qx_1007)){
        X60Qx_1006 = NIM_TRUE;}
      else {
        X60Qx_1006 = ((*td_8).d_00.count_0 <= 0);}
      if (X60Qx_1006){
        (*ok_2) = NIM_FALSE;
        nimStrDestroy(k_3);
        return result_45;}
      NI32 X60Qx_1008 = scalarWidth_0_aow7lb5cq1((*td_8).d_00.elem_0);
      string_0_sysvq0asl X60Qdesugar_110 = dollarQ_2_sysvq0asl(((NI32)((*td_8).d_00.count_0 * X60Qx_1008)));
      NI32 X60Qx_1009 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I6738090623860882514_aow7lb5cq1)}
      );
      NI32 X60Qx_1010 = len_4_sysvq0asl(X60Qdesugar_110);
      NI32 X60Qx_1011 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_111 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1009 + X60Qx_1010)) + X60Qx_1011)));
      add_2_sysvq0asl((&X60Qdesugar_111), (string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I6738090623860882514_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_111), X60Qdesugar_110);
      add_2_sysvq0asl((&X60Qdesugar_111), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_45), X60Qdesugar_111);
      nimStrDestroy(X60Qdesugar_111);
      nimStrDestroy(X60Qdesugar_110);}
    break;
    case 14:
    {
      NI32 X60Qx_1012 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I17529382521941393548_aow7lb5cq1)}
      );
      NI32 X60Qx_1013 = len_4_sysvq0asl(src_8);
      NI32 X60Qx_1014 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_112 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1012 + X60Qx_1013)) + X60Qx_1014)));
      add_2_sysvq0asl((&X60Qdesugar_112), (string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I17529382521941393548_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_112), src_8);
      add_2_sysvq0asl((&X60Qdesugar_112), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_45), X60Qdesugar_112);
      nimStrDestroy(X60Qdesugar_112);}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_5 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_8).d_00.elem_0);
      if (el_5 == NIM_NIL){
        (*ok_2) = NIM_FALSE;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_5);
        nimStrDestroy(k_3);
        return result_45;}
      if ((*el_5).d_00.kind_0 == 14){
        NI32 X60Qx_1015 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        NI32 X60Qx_1016 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_1017 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_1018 = len_4_sysvq0asl(src_8);
        NI32 X60Qx_1019 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I15937128883579799196_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_113 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1015 + X60Qx_1016)) + X60Qx_1017)) + X60Qx_1018)) + X60Qx_1019)));
        add_2_sysvq0asl((&X60Qdesugar_113), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_113), k_3);
        add_2_sysvq0asl((&X60Qdesugar_113), (string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_113), src_8);
        add_2_sysvq0asl((&X60Qdesugar_113), (string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I15937128883579799196_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_45), X60Qdesugar_113);
        NI32 X60Qx_1020 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        NI32 X60Qx_1021 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_1022 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_114 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1020 + X60Qx_1021)) + X60Qx_1022)));
        add_2_sysvq0asl((&X60Qdesugar_114), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_114), k_3);
        add_2_sysvq0asl((&X60Qdesugar_114), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_45), X60Qdesugar_114);
        NI32 X60Qx_1023 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        NI32 X60Qx_1024 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_1025 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        NI32 X60Qx_1026 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_1027 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        NI32 X60Qx_1028 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_1029 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 665858u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_115 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1023 + X60Qx_1024)) + X60Qx_1025)) + X60Qx_1026)) + X60Qx_1027)) + X60Qx_1028)) + X60Qx_1029)));
        add_2_sysvq0asl((&X60Qdesugar_115), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_115), k_3);
        add_2_sysvq0asl((&X60Qdesugar_115), (string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_115), k_3);
        add_2_sysvq0asl((&X60Qdesugar_115), (string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_115), k_3);
        add_2_sysvq0asl((&X60Qdesugar_115), (string_0_sysvq0asl){
          .bytes_0 = 665858u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_45), X60Qdesugar_115);
        NI32 X60Qx_1030 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I8021182774357012906_aow7lb5cq1)}
        );
        NI32 X60Qx_1031 = len_4_sysvq0asl(src_8);
        NI32 X60Qx_1032 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        NI32 X60Qx_1033 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_1034 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_116 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1030 + X60Qx_1031)) + X60Qx_1032)) + X60Qx_1033)) + X60Qx_1034)));
        add_2_sysvq0asl((&X60Qdesugar_116), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I8021182774357012906_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_116), src_8);
        add_2_sysvq0asl((&X60Qdesugar_116), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_116), k_3);
        add_2_sysvq0asl((&X60Qdesugar_116), (string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_45), X60Qdesugar_116);
        add_2_sysvq0asl((&result_45), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15342668115246402447_aow7lb5cq1)}
        );
        nimStrDestroy(X60Qdesugar_116);
        nimStrDestroy(X60Qdesugar_115);
        nimStrDestroy(X60Qdesugar_114);
        nimStrDestroy(X60Qdesugar_113);}
      else {
        NB8 X60Qx_1035;
        if ((*el_5).d_00.kind_0 == 10){
          X60Qx_1035 = NIM_TRUE;}
        else {
          X60Qx_1035 = ((*el_5).d_00.kind_0 == 11);}
        if (X60Qx_1035){
          string_0_sysvq0asl ect_2 = seqElemCType_0_aow7lb5cq1(unit_4, cty_2);
          NI32 X60Qx_1036 = len_4_sysvq0asl(ect_2);
          if (X60Qx_1036 == 0){
            (*ok_2) = NIM_FALSE;
            nimStrDestroy(ect_2);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_5);
            nimStrDestroy(k_3);
            return result_45;}
          add_2_sysvq0asl((&result_45), (string_0_sysvq0asl){
            .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I12898632421854814588_aow7lb5cq1)}
          );
          NI32 X60Qx_1037 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
          );
          NI32 X60Qx_1038 = len_4_sysvq0asl(k_3);
          NI32 X60Qx_1039 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_117 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1037 + X60Qx_1038)) + X60Qx_1039)));
          add_2_sysvq0asl((&X60Qdesugar_117), (string_0_sysvq0asl){
            .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I8924957223949144062_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_117), k_3);
          add_2_sysvq0asl((&X60Qdesugar_117), (string_0_sysvq0asl){
            .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_45), X60Qdesugar_117);
          NI32 X60Qx_1040 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
          );
          NI32 X60Qx_1041 = len_4_sysvq0asl(k_3);
          NI32 X60Qx_1042 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540811267u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_1043 = len_4_sysvq0asl(src_8);
          NI32 X60Qx_1044 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I6325254588340587598_aow7lb5cq1)}
          );
          NI32 X60Qx_1045 = len_4_sysvq0asl(k_3);
          NI32 X60Qx_1046 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_118 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1040 + X60Qx_1041)) + X60Qx_1042)) + X60Qx_1043)) + X60Qx_1044)) + X60Qx_1045)) + X60Qx_1046)));
          add_2_sysvq0asl((&X60Qdesugar_118), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15674259086726680393_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_118), k_3);
          add_2_sysvq0asl((&X60Qdesugar_118), (string_0_sysvq0asl){
            .bytes_0 = 540811267u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_118), src_8);
          add_2_sysvq0asl((&X60Qdesugar_118), (string_0_sysvq0asl){
            .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I6325254588340587598_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_118), k_3);
          add_2_sysvq0asl((&X60Qdesugar_118), (string_0_sysvq0asl){
            .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_45), X60Qdesugar_118);
          NI32 X60Qx_1047 = len_4_sysvq0asl(src_8);
          NI32 X60Qx_1048 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
          );
          NI32 X60Qx_1049 = len_4_sysvq0asl(k_3);
          NI32 X60Qx_1050 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_119 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1047 + X60Qx_1048)) + X60Qx_1049)) + X60Qx_1050)));
          add_2_sysvq0asl((&X60Qdesugar_119), src_8);
          add_2_sysvq0asl((&X60Qdesugar_119), (string_0_sysvq0asl){
            .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_119), k_3);
          add_2_sysvq0asl((&X60Qdesugar_119), (string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl body_3 = emitCompositeSize_0_aow7lb5cq1(el_5, unit_4, ect_2, X60Qdesugar_119, tmp_2, ok_2);
          if ((!(*ok_2))){
            nimStrDestroy(body_3);
            nimStrDestroy(X60Qdesugar_119);
            nimStrDestroy(X60Qdesugar_118);
            nimStrDestroy(X60Qdesugar_117);
            nimStrDestroy(ect_2);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_5);
            nimStrDestroy(k_3);
            return result_45;}
          add_2_sysvq0asl((&result_45), body_3);
          add_2_sysvq0asl((&result_45), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15342668115246402447_aow7lb5cq1)}
          );
          nimStrDestroy(body_3);
          nimStrDestroy(X60Qdesugar_119);
          nimStrDestroy(X60Qdesugar_118);
          nimStrDestroy(X60Qdesugar_117);
          nimStrDestroy(ect_2);}
        else {
          NB8 X60Qx_1051;
          NB8 X60Qx_1052;
          NB8 X60Qx_1053;
          NB8 X60Qx_1054;
          NB8 X60Qx_1055;
          if ((*el_5).d_00.kind_0 == 0){
            X60Qx_1055 = NIM_TRUE;}
          else {
            X60Qx_1055 = ((*el_5).d_00.kind_0 == 1);}
          if (X60Qx_1055){
            X60Qx_1054 = NIM_TRUE;}
          else {
            X60Qx_1054 = ((*el_5).d_00.kind_0 == 2);}
          if (X60Qx_1054){
            X60Qx_1053 = NIM_TRUE;}
          else {
            X60Qx_1053 = ((*el_5).d_00.kind_0 == 3);}
          if (X60Qx_1053){
            X60Qx_1052 = NIM_TRUE;}
          else {
            X60Qx_1052 = ((*el_5).d_00.kind_0 == 4);}
          if (X60Qx_1052){
            X60Qx_1051 = NIM_TRUE;}
          else {
            X60Qx_1051 = ((*el_5).d_00.kind_0 == 8);}
          if (X60Qx_1051){
            NI32 X60Qx_1056 = scalarWidth_0_aow7lb5cq1(el_5);
            string_0_sysvq0asl X60Qdesugar_120 = dollarQ_2_sysvq0asl(X60Qx_1056);
            NI32 X60Qx_1057 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I10813034127713670746_aow7lb5cq1)}
            );
            NI32 X60Qx_1058 = len_4_sysvq0asl(src_8);
            NI32 X60Qx_1059 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I17741661924343507191_aow7lb5cq1)}
            );
            NI32 X60Qx_1060 = len_4_sysvq0asl(X60Qdesugar_120);
            NI32 X60Qx_1061 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_121 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1057 + X60Qx_1058)) + X60Qx_1059)) + X60Qx_1060)) + X60Qx_1061)));
            add_2_sysvq0asl((&X60Qdesugar_121), (string_0_sysvq0asl){
              .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I10813034127713670746_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_121), src_8);
            add_2_sysvq0asl((&X60Qdesugar_121), (string_0_sysvq0asl){
              .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I17741661924343507191_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_121), X60Qdesugar_120);
            add_2_sysvq0asl((&X60Qdesugar_121), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_45), X60Qdesugar_121);
            nimStrDestroy(X60Qdesugar_121);
            nimStrDestroy(X60Qdesugar_120);}
          else {
            (*ok_2) = NIM_FALSE;}}}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_5);}
    break;
    case 10:
    case 11:
    {
      seq_0_Irn2j6w_aow7lb5cq1 flds_4 = structFields_0_aow7lb5cq1(unit_4, cty_2);
      if ((!(flds_4.len_0 == (*td_8).d_00.fields_0.len_0))){
        (*ok_2) = NIM_FALSE;
        eQdestroy_1_Iem8q971_aow7lb5cq1(flds_4);
        nimStrDestroy(k_3);
        return result_45;}
      NI32 i_21 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1062 = len_3_I5m68tr1_aow7lb5cq1((*td_8).d_00.fields_0);
          if (i_21 < X60Qx_1062){
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_1063 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_4, i_21);
            string_0_sysvq0asl X60Qdesugar_122 = nimStrDup((*X60Qx_1063).fld_1);
            NI32 X60Qx_1064 = len_4_sysvq0asl(src_8);
            NI32 X60Qx_1065 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_1066 = len_4_sysvq0asl(X60Qdesugar_122);
            string_0_sysvq0asl X60Qdesugar_123 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1064 + X60Qx_1065)) + X60Qx_1066)));
            add_2_sysvq0asl((&X60Qdesugar_123), src_8);
            add_2_sysvq0asl((&X60Qdesugar_123), (string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_123), X60Qdesugar_122);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_1067 = getQ_7_I45w7c91_aow7lb5cq1((*td_8).d_00.fields_0, i_21);
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_1068 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_4, i_21);
            string_0_sysvq0asl X60Qtmp_34 = emitCompositeSize_0_aow7lb5cq1((*X60Qx_1067), unit_4, (*X60Qx_1068).fld_0, X60Qdesugar_123, tmp_2, ok_2);
            add_2_sysvq0asl((&result_45), X60Qtmp_34);
            if ((!(*ok_2))){
              nimStrDestroy(X60Qtmp_34);
              nimStrDestroy(X60Qdesugar_123);
              nimStrDestroy(X60Qdesugar_122);
              eQdestroy_1_Iem8q971_aow7lb5cq1(flds_4);
              nimStrDestroy(k_3);
              return result_45;}
            inc_1_I6wjjge_aow2h993l1((&i_21));
            nimStrDestroy(X60Qtmp_34);
            nimStrDestroy(X60Qdesugar_123);
            nimStrDestroy(X60Qdesugar_122);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      eQdestroy_1_Iem8q971_aow7lb5cq1(flds_4);}
    break;
    default:
    {
      (*ok_2) = NIM_FALSE;}
    break;}
  nimStrDestroy(k_3);
  return result_45;
  nimStrDestroy(k_3);
  return result_45;}
string_0_sysvq0asl stashedCall_0_aow7lb5cq1(string_0_sysvq0asl retT_0, string_0_sysvq0asl call_0){
  string_0_sysvq0asl result_46;
  nimStrWasMoved((&result_46));
  NI32 X60Qx_1069 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1931485438u, .more_0 = (&strlit_0_I16883230891360796278_aow7lb5cq1)}
  );
  NI32 X60Qx_1070 = len_4_sysvq0asl(retT_0);
  NI32 X60Qx_1071 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1868636414u, .more_0 = (&strlit_0_I5733847686152760297_aow7lb5cq1)}
  );
  NI32 X60Qx_1072 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1073 = len_4_sysvq0asl(retT_0);
  NI32 X60Qx_1074 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10110734980645466271_aow7lb5cq1)}
  );
  NI32 X60Qx_1075 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I3029774243415831428_aow7lb5cq1)}
  );
  NI32 X60Qx_1076 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1696604414u, .more_0 = (&strlit_0_I9923484708672022736_aow7lb5cq1)}
  );
  NI32 X60Qx_1077 = len_4_sysvq0asl(call_0);
  NI32 X60Qx_1078 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 670466u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_124 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1069 + X60Qx_1070)) + X60Qx_1071)) + X60Qx_1072)) + X60Qx_1073)) + X60Qx_1074)) + X60Qx_1075)) + X60Qx_1076)) + X60Qx_1077)) + X60Qx_1078)));
  add_2_sysvq0asl((&X60Qdesugar_124), (string_0_sysvq0asl){
    .bytes_0 = 1931485438u, .more_0 = (&strlit_0_I16883230891360796278_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_124), retT_0);
  add_2_sysvq0asl((&X60Qdesugar_124), (string_0_sysvq0asl){
    .bytes_0 = 1868636414u, .more_0 = (&strlit_0_I5733847686152760297_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_124), (string_0_sysvq0asl){
    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_124), retT_0);
  add_2_sysvq0asl((&X60Qdesugar_124), (string_0_sysvq0asl){
    .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10110734980645466271_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_124), (string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I3029774243415831428_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_124), (string_0_sysvq0asl){
    .bytes_0 = 1696604414u, .more_0 = (&strlit_0_I9923484708672022736_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_124), call_0);
  add_2_sysvq0asl((&X60Qdesugar_124), (string_0_sysvq0asl){
    .bytes_0 = 670466u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(result_46);
  result_46 = X60Qdesugar_124;
  nimStrWasMoved((&X60Qdesugar_124));
  nimStrDestroy(X60Qdesugar_124);
  return result_46;
  nimStrDestroy(X60Qdesugar_124);
  return result_46;}
string_0_sysvq0asl emitCShim_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_4, string_0_sysvq0asl mangled_1, string_0_sysvq0asl strT_2, string_0_sysvq0asl longT_2, string_0_sysvq0asl allocFn_1, string_0_sysvq0asl deallocFn_2, CSig_0_aow7lb5cq1 sig_0, string_0_sysvq0asl unit_5){
  string_0_sysvq0asl result_47;
  nimStrWasMoved((&result_47));
  nimStrDestroy(result_47);
  result_47 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_1079;
  if ((!sig_0.ok_0)){
    X60Qx_1079 = NIM_TRUE;}
  else {
    X60Qx_1079 = (!(sig_0.params_0.len_0 == (*e_4).d_00.args_0.len_0));}
  if (X60Qx_1079){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 ctmp_0 = 0;
  string_0_sysvq0asl X60Qdesugar_125 = nimStrDup((*e_4).d_00.shimSym_0);
  NI32 X60Qx_1080 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I9877049113831429732_aow7lb5cq1)}
  );
  NI32 X60Qx_1081 = len_4_sysvq0asl(X60Qdesugar_125);
  NI32 X60Qx_1082 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1868769534u, .more_0 = (&strlit_0_I1708222581923651341_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_126 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1080 + X60Qx_1081)) + X60Qx_1082)));
  add_2_sysvq0asl((&X60Qdesugar_126), (string_0_sysvq0asl){
    .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I9877049113831429732_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_126), X60Qdesugar_125);
  add_2_sysvq0asl((&X60Qdesugar_126), (string_0_sysvq0asl){
    .bytes_0 = 1868769534u, .more_0 = (&strlit_0_I1708222581923651341_aow7lb5cq1)}
  );
  nimStrDestroy(result_47);
  result_47 = X60Qdesugar_126;
  nimStrWasMoved((&X60Qdesugar_126));
  add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
    .bytes_0 = 1663049982u, .more_0 = (&strlit_0_I10178897100901084906_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
    .bytes_0 = 1965039870u, .more_0 = (&strlit_0_I4393801761698446017_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
    .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I7946228770895663279_aow7lb5cq1)}
  );
  NI32 i_22 = 0;
  string_0_sysvq0asl call_1 = ampQ_0_sysvq0asl(mangled_1, (string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl owned_1 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl writeback_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1083 = len_3_In63jw61_aow7lb5cq1((*e_4).d_00.args_0);
      if (i_22 < X60Qx_1083){
        string_0_sysvq0asl X60Qtmp_35 = dollarQ_2_sysvq0asl(i_22);
        string_0_sysvq0asl a_9 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 24833u, .more_0 = NIM_NIL}
        , X60Qtmp_35);
        WireField_0_run8hsnpi* X60Qx_1084 = getQ_7_Iko57h9_aow7lb5cq1((*e_4).d_00.args_0, i_22);
        WireField_0_run8hsnpi X60QconstRefTemp_0 = (*X60Qx_1084);
        WireField_0_run8hsnpi f_14 = eQdupQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60QconstRefTemp_0));
        string_0_sysvq0asl* X60Qx_1085 = getQ_7_Ir6d0tw_aow7lb5cq1(sig_0.params_0, i_22);
        string_0_sysvq0asl ty_2 = nimStrDup((*X60Qx_1085));
        string_0_sysvq0asl w_7 = dollarQ_2_sysvq0asl(f_14.wireSize_0);
        string_0_sysvq0asl argExpr_0 = nimStrDup(a_9);
        if (f_14.isComposite_0){
          NB8 X60Qx_1086;
          NI32 X60Qx_1087 = len_4_sysvq0asl(ty_2);
          if (0 < X60Qx_1087){
            NI32 X60Qx_1088 = len_4_sysvq0asl(ty_2);
            NC8 X60Qx_1089 = getQ_9_sysvq0asl(ty_2, ((NI32)(X60Qx_1088 - 1)));
            X60Qx_1086 = (X60Qx_1089 == (NC8)'*');}
          else {
            X60Qx_1086 = NIM_FALSE;}
          NB8 byPtr_0 = X60Qx_1086;
          string_0_sysvq0asl X60Qx_10;
          nimStrWasMoved((&X60Qx_10));
          if (byPtr_0){
            nimStrDestroy(X60Qx_10);
            string_0_sysvq0asl X60Qx_1090 = derefType_0_aow7lb5cq1(ty_2);
            X60Qx_10 = X60Qx_1090;}
          else {
            nimStrDestroy(X60Qx_10);
            X60Qx_10 = ty_2;
            nimStrWasMoved((&ty_2));}
          string_0_sysvq0asl sty_0 = X60Qx_10;
          nimStrWasMoved((&X60Qx_10));
          NI32 X60Qx_1091 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2105346u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_1092 = len_4_sysvq0asl(sty_0);
          NI32 X60Qx_1093 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 8193u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_1094 = len_4_sysvq0asl(a_9);
          NI32 X60Qx_1095 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 670466u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_127 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1091 + X60Qx_1092)) + X60Qx_1093)) + X60Qx_1094)) + X60Qx_1095)));
          add_2_sysvq0asl((&X60Qdesugar_127), (string_0_sysvq0asl){
            .bytes_0 = 2105346u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_127), sty_0);
          add_2_sysvq0asl((&X60Qdesugar_127), (string_0_sysvq0asl){
            .bytes_0 = 8193u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_127), a_9);
          add_2_sysvq0asl((&X60Qdesugar_127), (string_0_sysvq0asl){
            .bytes_0 = 670466u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&result_47), X60Qdesugar_127);
          NI32 X60Qx_1096 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7750355290083529673_aow7lb5cq1)}
          );
          NI32 X60Qx_1097 = len_4_sysvq0asl(a_9);
          NI32 X60Qx_1098 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
          );
          NI32 X60Qx_1099 = len_4_sysvq0asl(a_9);
          NI32 X60Qx_1100 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_128 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1096 + X60Qx_1097)) + X60Qx_1098)) + X60Qx_1099)) + X60Qx_1100)));
          add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
            .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7750355290083529673_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_128), a_9);
          add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
            .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_128), a_9);
          add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_47), X60Qdesugar_128);
          NB8 cok_0 = NIM_TRUE;
          string_0_sysvq0asl body_4 = emitCompositeIn_0_aow7lb5cq1(f_14.desc_0, unit_5, sty_0, a_9, strT_2, longT_2, allocFn_1, deallocFn_2, (&ctmp_0), (&owned_1), (&cok_0));
          if ((!cok_0)){
            nimStrDestroy(body_4);
            nimStrDestroy(X60Qdesugar_128);
            nimStrDestroy(X60Qdesugar_127);
            nimStrDestroy(sty_0);
            nimStrDestroy(X60Qx_10);
            nimStrDestroy(argExpr_0);
            nimStrDestroy(w_7);
            nimStrDestroy(ty_2);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_14));
            nimStrDestroy(a_9);
            nimStrDestroy(X60Qtmp_35);
            nimStrDestroy(writeback_0);
            nimStrDestroy(owned_1);
            nimStrDestroy(call_1);
            nimStrDestroy(X60Qdesugar_126);
            nimStrDestroy(X60Qdesugar_125);
            return (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            ;}
          add_2_sysvq0asl((&result_47), body_4);
          if (byPtr_0){
            nimStrDestroy(argExpr_0);
            string_0_sysvq0asl X60Qx_1101 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 9729u, .more_0 = NIM_NIL}
            , a_9);
            argExpr_0 = X60Qx_1101;}
          nimStrDestroy(body_4);
          nimStrDestroy(X60Qdesugar_128);
          nimStrDestroy(X60Qdesugar_127);
          nimStrDestroy(sty_0);
          nimStrDestroy(X60Qx_10);}
        else {
          NB8 X60Qx_1102 = stringOk_0_aow7lb5cq1((&f_14));
          if (X60Qx_1102){
            string_0_sysvq0asl X60Qdesugar_129 = dollarQ_2_sysvq0asl(i_22);
            NI32 X60Qx_1103 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
            );
            NI32 X60Qx_1104 = len_4_sysvq0asl(X60Qdesugar_129);
            NI32 X60Qx_1105 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_130 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1103 + X60Qx_1104)) + X60Qx_1105)));
            add_2_sysvq0asl((&X60Qdesugar_130), (string_0_sysvq0asl){
              .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_130), X60Qdesugar_129);
            add_2_sysvq0asl((&X60Qdesugar_130), (string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_47), X60Qdesugar_130);
            string_0_sysvq0asl X60Qdesugar_131 = dollarQ_2_sysvq0asl(i_22);
            NI32 X60Qx_1106 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_1107 = len_4_sysvq0asl(longT_2);
            NI32 X60Qx_1108 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1864379134u, .more_0 = (&strlit_0_I9396282401636018722_aow7lb5cq1)}
            );
            NI32 X60Qx_1109 = len_4_sysvq0asl(X60Qdesugar_131);
            NI32 X60Qx_1110 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_132 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1106 + X60Qx_1107)) + X60Qx_1108)) + X60Qx_1109)) + X60Qx_1110)));
            add_2_sysvq0asl((&X60Qdesugar_132), (string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_132), longT_2);
            add_2_sysvq0asl((&X60Qdesugar_132), (string_0_sysvq0asl){
              .bytes_0 = 1864379134u, .more_0 = (&strlit_0_I9396282401636018722_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_132), X60Qdesugar_131);
            add_2_sysvq0asl((&X60Qdesugar_132), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_47), X60Qdesugar_132);
            string_0_sysvq0asl X60Qdesugar_133 = dollarQ_2_sysvq0asl(i_22);
            string_0_sysvq0asl X60Qdesugar_134 = dollarQ_2_sysvq0asl(i_22);
            NI32 X60Qx_1111 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_1112 = len_4_sysvq0asl(strT_2);
            NI32 X60Qx_1113 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_1114 = len_4_sysvq0asl(a_9);
            NI32 X60Qx_1115 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I459476928402638487_aow7lb5cq1)}
            );
            NI32 X60Qx_1116 = len_4_sysvq0asl(X60Qdesugar_133);
            NI32 X60Qx_1117 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1259136645670664990_aow7lb5cq1)}
            );
            NI32 X60Qx_1118 = len_4_sysvq0asl(X60Qdesugar_134);
            NI32 X60Qx_1119 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 171649283u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_135 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1111 + X60Qx_1112)) + X60Qx_1113)) + X60Qx_1114)) + X60Qx_1115)) + X60Qx_1116)) + X60Qx_1117)) + X60Qx_1118)) + X60Qx_1119)));
            add_2_sysvq0asl((&X60Qdesugar_135), (string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_135), strT_2);
            add_2_sysvq0asl((&X60Qdesugar_135), (string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_135), a_9);
            add_2_sysvq0asl((&X60Qdesugar_135), (string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I459476928402638487_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_135), X60Qdesugar_133);
            add_2_sysvq0asl((&X60Qdesugar_135), (string_0_sysvq0asl){
              .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1259136645670664990_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_135), X60Qdesugar_134);
            add_2_sysvq0asl((&X60Qdesugar_135), (string_0_sysvq0asl){
              .bytes_0 = 171649283u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_47), X60Qdesugar_135);
            string_0_sysvq0asl X60Qdesugar_136 = dollarQ_2_sysvq0asl(i_22);
            NI32 X60Qx_1120 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4281043891304848808_aow7lb5cq1)}
            );
            NI32 X60Qx_1121 = len_4_sysvq0asl(X60Qdesugar_136);
            NI32 X60Qx_1122 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_137 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1120 + X60Qx_1121)) + X60Qx_1122)));
            add_2_sysvq0asl((&X60Qdesugar_137), (string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4281043891304848808_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_137), X60Qdesugar_136);
            add_2_sysvq0asl((&X60Qdesugar_137), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_47), X60Qdesugar_137);
            add_2_sysvq0asl((&owned_1), (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            );
            nimStrDestroy(X60Qdesugar_137);
            nimStrDestroy(X60Qdesugar_136);
            nimStrDestroy(X60Qdesugar_135);
            nimStrDestroy(X60Qdesugar_134);
            nimStrDestroy(X60Qdesugar_133);
            nimStrDestroy(X60Qdesugar_132);
            nimStrDestroy(X60Qdesugar_131);
            nimStrDestroy(X60Qdesugar_130);
            nimStrDestroy(X60Qdesugar_129);}
          else {
            NB8 X60Qx_1123 = seqOk_0_aow7lb5cq1((&f_14));
            if (X60Qx_1123){
              string_0_sysvq0asl st_0 = dollarQ_2_sysvq0asl(f_14.elemStride_0);
              string_0_sysvq0asl X60Qdesugar_138 = dollarQ_2_sysvq0asl(i_22);
              NI32 X60Qx_1124 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
              );
              NI32 X60Qx_1125 = len_4_sysvq0asl(X60Qdesugar_138);
              NI32 X60Qx_1126 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_139 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1124 + X60Qx_1125)) + X60Qx_1126)));
              add_2_sysvq0asl((&X60Qdesugar_139), (string_0_sysvq0asl){
                .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_139), X60Qdesugar_138);
              add_2_sysvq0asl((&X60Qdesugar_139), (string_0_sysvq0asl){
                .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_139);
              NI32 X60Qx_1127 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1128 = len_4_sysvq0asl(ty_2);
              NI32 X60Qx_1129 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 8193u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1130 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_1131 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_140 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1127 + X60Qx_1128)) + X60Qx_1129)) + X60Qx_1130)) + X60Qx_1131)));
              add_2_sysvq0asl((&X60Qdesugar_140), (string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_140), ty_2);
              add_2_sysvq0asl((&X60Qdesugar_140), (string_0_sysvq0asl){
                .bytes_0 = 8193u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_140), a_9);
              add_2_sysvq0asl((&X60Qdesugar_140), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_140);
              NI32 X60Qx_1132 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I6378395016434652565_aow7lb5cq1)}
              );
              NI32 X60Qx_1133 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_1134 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
              );
              NI32 X60Qx_1135 = len_4_sysvq0asl(st_0);
              NI32 X60Qx_1136 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_141 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1132 + X60Qx_1133)) + X60Qx_1134)) + X60Qx_1135)) + X60Qx_1136)));
              add_2_sysvq0asl((&X60Qdesugar_141), (string_0_sysvq0asl){
                .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I6378395016434652565_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_141), a_9);
              add_2_sysvq0asl((&X60Qdesugar_141), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_141), st_0);
              add_2_sysvq0asl((&X60Qdesugar_141), (string_0_sysvq0asl){
                .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_141);
              NI32 X60Qx_1137 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7750355290083529673_aow7lb5cq1)}
              );
              NI32 X60Qx_1138 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_1139 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
              );
              NI32 X60Qx_1140 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_1141 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_142 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1137 + X60Qx_1138)) + X60Qx_1139)) + X60Qx_1140)) + X60Qx_1141)));
              add_2_sysvq0asl((&X60Qdesugar_142), (string_0_sysvq0asl){
                .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7750355290083529673_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_142), a_9);
              add_2_sysvq0asl((&X60Qdesugar_142), (string_0_sysvq0asl){
                .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_142), a_9);
              add_2_sysvq0asl((&X60Qdesugar_142), (string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_142);
              string_0_sysvq0asl X60Qdesugar_143 = dollarQ_2_sysvq0asl(i_22);
              NI32 X60Qx_1142 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1143 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_1144 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
              );
              NI32 X60Qx_1145 = len_4_sysvq0asl(X60Qdesugar_143);
              NI32 X60Qx_1146 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_144 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1142 + X60Qx_1143)) + X60Qx_1144)) + X60Qx_1145)) + X60Qx_1146)));
              add_2_sysvq0asl((&X60Qdesugar_144), (string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_144), a_9);
              add_2_sysvq0asl((&X60Qdesugar_144), (string_0_sysvq0asl){
                .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_144), X60Qdesugar_143);
              add_2_sysvq0asl((&X60Qdesugar_144), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_144);
              string_0_sysvq0asl X60Qdesugar_145 = dollarQ_2_sysvq0asl(i_22);
              NI32 X60Qx_1147 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I11268796792645648849_aow7lb5cq1)}
              );
              NI32 X60Qx_1148 = len_4_sysvq0asl(X60Qdesugar_145);
              NI32 X60Qx_1149 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_146 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1147 + X60Qx_1148)) + X60Qx_1149)));
              add_2_sysvq0asl((&X60Qdesugar_146), (string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I11268796792645648849_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_146), X60Qdesugar_145);
              add_2_sysvq0asl((&X60Qdesugar_146), (string_0_sysvq0asl){
                .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_146);
              string_0_sysvq0asl X60Qdesugar_147 = dollarQ_2_sysvq0asl(i_22);
              NI32 X60Qx_1150 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
              );
              NI32 X60Qx_1151 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_1152 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
              );
              NI32 X60Qx_1153 = len_4_sysvq0asl(allocFn_1);
              NI32 X60Qx_1154 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
              );
              NI32 X60Qx_1155 = len_4_sysvq0asl(X60Qdesugar_147);
              NI32 X60Qx_1156 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1157 = len_4_sysvq0asl(st_0);
              NI32 X60Qx_1158 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_148 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1150 + X60Qx_1151)) + X60Qx_1152)) + X60Qx_1153)) + X60Qx_1154)) + X60Qx_1155)) + X60Qx_1156)) + X60Qx_1157)) + X60Qx_1158)));
              add_2_sysvq0asl((&X60Qdesugar_148), (string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_148), a_9);
              add_2_sysvq0asl((&X60Qdesugar_148), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_148), allocFn_1);
              add_2_sysvq0asl((&X60Qdesugar_148), (string_0_sysvq0asl){
                .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_148), X60Qdesugar_147);
              add_2_sysvq0asl((&X60Qdesugar_148), (string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_148), st_0);
              add_2_sysvq0asl((&X60Qdesugar_148), (string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_148);
              string_0_sysvq0asl X60Qdesugar_149 = dollarQ_2_sysvq0asl(i_22);
              NI32 X60Qx_1159 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I89544630611547045_aow7lb5cq1)}
              );
              NI32 X60Qx_1160 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_1161 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I7701159626300919437_aow7lb5cq1)}
              );
              NI32 X60Qx_1162 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1769154814u, .more_0 = (&strlit_0_I16305850586936607483_aow7lb5cq1)}
              );
              NI32 X60Qx_1163 = len_4_sysvq0asl(X60Qdesugar_149);
              NI32 X60Qx_1164 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1165 = len_4_sysvq0asl(st_0);
              NI32 X60Qx_1166 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_150 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1159 + X60Qx_1160)) + X60Qx_1161)) + X60Qx_1162)) + X60Qx_1163)) + X60Qx_1164)) + X60Qx_1165)) + X60Qx_1166)));
              add_2_sysvq0asl((&X60Qdesugar_150), (string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I89544630611547045_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_150), a_9);
              add_2_sysvq0asl((&X60Qdesugar_150), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I7701159626300919437_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_150), (string_0_sysvq0asl){
                .bytes_0 = 1769154814u, .more_0 = (&strlit_0_I16305850586936607483_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_150), X60Qdesugar_149);
              add_2_sysvq0asl((&X60Qdesugar_150), (string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_150), st_0);
              add_2_sysvq0asl((&X60Qdesugar_150), (string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_150);
              add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
                .bytes_0 = 2099257598u, .more_0 = (&strlit_0_I6468377022308900005_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_151 = dollarQ_2_sysvq0asl(i_22);
              NI32 X60Qx_1167 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4281043891304848808_aow7lb5cq1)}
              );
              NI32 X60Qx_1168 = len_4_sysvq0asl(X60Qdesugar_151);
              NI32 X60Qx_1169 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1170 = len_4_sysvq0asl(st_0);
              NI32 X60Qx_1171 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_152 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1167 + X60Qx_1168)) + X60Qx_1169)) + X60Qx_1170)) + X60Qx_1171)));
              add_2_sysvq0asl((&X60Qdesugar_152), (string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4281043891304848808_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_152), X60Qdesugar_151);
              add_2_sysvq0asl((&X60Qdesugar_152), (string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_152), st_0);
              add_2_sysvq0asl((&X60Qdesugar_152), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_152);
              NI32 X60Qx_1172 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
              );
              NI32 X60Qx_1173 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_1174 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
              );
              NI32 X60Qx_1175 = len_4_sysvq0asl(deallocFn_2);
              NI32 X60Qx_1176 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
              );
              NI32 X60Qx_1177 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_1178 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_153 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1172 + X60Qx_1173)) + X60Qx_1174)) + X60Qx_1175)) + X60Qx_1176)) + X60Qx_1177)) + X60Qx_1178)));
              add_2_sysvq0asl((&X60Qdesugar_153), (string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_153), a_9);
              add_2_sysvq0asl((&X60Qdesugar_153), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_153), deallocFn_2);
              add_2_sysvq0asl((&X60Qdesugar_153), (string_0_sysvq0asl){
                .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_153), a_9);
              add_2_sysvq0asl((&X60Qdesugar_153), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&owned_1), X60Qdesugar_153);
              nimStrDestroy(X60Qdesugar_153);
              nimStrDestroy(X60Qdesugar_152);
              nimStrDestroy(X60Qdesugar_151);
              nimStrDestroy(X60Qdesugar_150);
              nimStrDestroy(X60Qdesugar_149);
              nimStrDestroy(X60Qdesugar_148);
              nimStrDestroy(X60Qdesugar_147);
              nimStrDestroy(X60Qdesugar_146);
              nimStrDestroy(X60Qdesugar_145);
              nimStrDestroy(X60Qdesugar_144);
              nimStrDestroy(X60Qdesugar_143);
              nimStrDestroy(X60Qdesugar_142);
              nimStrDestroy(X60Qdesugar_141);
              nimStrDestroy(X60Qdesugar_140);
              nimStrDestroy(X60Qdesugar_139);
              nimStrDestroy(X60Qdesugar_138);
              nimStrDestroy(st_0);}
            else {
              NB8 X60Qx_1179 = podOk_0_aow7lb5cq1((&f_14));
              if (X60Qx_1179){
                NB8 X60Qx_1180;
                NI32 X60Qx_1181 = len_4_sysvq0asl(ty_2);
                if (0 < X60Qx_1181){
                  NI32 X60Qx_1182 = len_4_sysvq0asl(ty_2);
                  NC8 X60Qx_1183 = getQ_9_sysvq0asl(ty_2, ((NI32)(X60Qx_1182 - 1)));
                  X60Qx_1180 = (X60Qx_1183 == (NC8)'*');}
                else {
                  X60Qx_1180 = NIM_FALSE;}
                NB8 podByPtr_0 = X60Qx_1180;
                string_0_sysvq0asl X60Qx_11;
                nimStrWasMoved((&X60Qx_11));
                if (podByPtr_0){
                  nimStrDestroy(X60Qx_11);
                  string_0_sysvq0asl X60Qx_1184 = derefType_0_aow7lb5cq1(ty_2);
                  X60Qx_11 = X60Qx_1184;}
                else {
                  nimStrDestroy(X60Qx_11);
                  X60Qx_11 = ty_2;
                  nimStrWasMoved((&ty_2));}
                string_0_sysvq0asl podTy_0 = X60Qx_11;
                nimStrWasMoved((&X60Qx_11));
                NI32 X60Qx_1185 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_1186 = len_4_sysvq0asl(podTy_0);
                NI32 X60Qx_1187 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 8193u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_1188 = len_4_sysvq0asl(a_9);
                NI32 X60Qx_1189 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_154 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1185 + X60Qx_1186)) + X60Qx_1187)) + X60Qx_1188)) + X60Qx_1189)));
                add_2_sysvq0asl((&X60Qdesugar_154), (string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_154), podTy_0);
                add_2_sysvq0asl((&X60Qdesugar_154), (string_0_sysvq0asl){
                  .bytes_0 = 8193u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_154), a_9);
                add_2_sysvq0asl((&X60Qdesugar_154), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_154);
                NI32 X60Qx_1190 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                );
                NI32 X60Qx_1191 = len_4_sysvq0asl(a_9);
                NI32 X60Qx_1192 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                );
                NI32 X60Qx_1193 = len_4_sysvq0asl(w_7);
                NI32 X60Qx_1194 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 572534014u, .more_0 = (&strlit_0_I17122198299299987856_aow7lb5cq1)}
                );
                string_0_sysvq0asl X60Qdesugar_155 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1190 + X60Qx_1191)) + X60Qx_1192)) + X60Qx_1193)) + X60Qx_1194)));
                add_2_sysvq0asl((&X60Qdesugar_155), (string_0_sysvq0asl){
                  .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_155), a_9);
                add_2_sysvq0asl((&X60Qdesugar_155), (string_0_sysvq0asl){
                  .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_155), w_7);
                add_2_sysvq0asl((&X60Qdesugar_155), (string_0_sysvq0asl){
                  .bytes_0 = 572534014u, .more_0 = (&strlit_0_I17122198299299987856_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_155);
                NI32 X60Qx_1195 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
                );
                NI32 X60Qx_1196 = len_4_sysvq0asl(a_9);
                NI32 X60Qx_1197 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
                );
                NI32 X60Qx_1198 = len_4_sysvq0asl(w_7);
                NI32 X60Qx_1199 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_156 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1195 + X60Qx_1196)) + X60Qx_1197)) + X60Qx_1198)) + X60Qx_1199)));
                add_2_sysvq0asl((&X60Qdesugar_156), (string_0_sysvq0asl){
                  .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_156), a_9);
                add_2_sysvq0asl((&X60Qdesugar_156), (string_0_sysvq0asl){
                  .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_156), w_7);
                add_2_sysvq0asl((&X60Qdesugar_156), (string_0_sysvq0asl){
                  .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_156);
                NI32 X60Qx_1200 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                );
                NI32 X60Qx_1201 = len_4_sysvq0asl(w_7);
                NI32 X60Qx_1202 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_157 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1200 + X60Qx_1201)) + X60Qx_1202)));
                add_2_sysvq0asl((&X60Qdesugar_157), (string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_157), w_7);
                add_2_sysvq0asl((&X60Qdesugar_157), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_157);
                if (podByPtr_0){
                  nimStrDestroy(argExpr_0);
                  string_0_sysvq0asl X60Qx_1203 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 9729u, .more_0 = NIM_NIL}
                  , a_9);
                  argExpr_0 = X60Qx_1203;}
                nimStrDestroy(X60Qdesugar_157);
                nimStrDestroy(X60Qdesugar_156);
                nimStrDestroy(X60Qdesugar_155);
                nimStrDestroy(X60Qdesugar_154);
                nimStrDestroy(podTy_0);
                nimStrDestroy(X60Qx_11);}
              else {
                NB8 X60Qx_1204 = floatOk_0_aow7lb5cq1((&f_14));
                if (X60Qx_1204){
                  NI32 X60Qx_1205 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                  );
                  NI32 X60Qx_1206 = len_4_sysvq0asl(ty_2);
                  NI32 X60Qx_1207 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 8193u, .more_0 = NIM_NIL}
                  );
                  NI32 X60Qx_1208 = len_4_sysvq0asl(a_9);
                  NI32 X60Qx_1209 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_158 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1205 + X60Qx_1206)) + X60Qx_1207)) + X60Qx_1208)) + X60Qx_1209)));
                  add_2_sysvq0asl((&X60Qdesugar_158), (string_0_sysvq0asl){
                    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_158), ty_2);
                  add_2_sysvq0asl((&X60Qdesugar_158), (string_0_sysvq0asl){
                    .bytes_0 = 8193u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_158), a_9);
                  add_2_sysvq0asl((&X60Qdesugar_158), (string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&result_47), X60Qdesugar_158);
                  NI32 X60Qx_1210 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1211 = len_4_sysvq0asl(a_9);
                  NI32 X60Qx_1212 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1213 = len_4_sysvq0asl(w_7);
                  NI32 X60Qx_1214 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 572534014u, .more_0 = (&strlit_0_I7306618916803007629_aow7lb5cq1)}
                  );
                  string_0_sysvq0asl X60Qdesugar_159 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1210 + X60Qx_1211)) + X60Qx_1212)) + X60Qx_1213)) + X60Qx_1214)));
                  add_2_sysvq0asl((&X60Qdesugar_159), (string_0_sysvq0asl){
                    .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_159), a_9);
                  add_2_sysvq0asl((&X60Qdesugar_159), (string_0_sysvq0asl){
                    .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_159), w_7);
                  add_2_sysvq0asl((&X60Qdesugar_159), (string_0_sysvq0asl){
                    .bytes_0 = 572534014u, .more_0 = (&strlit_0_I7306618916803007629_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&result_47), X60Qdesugar_159);
                  string_0_sysvq0asl X60Qdesugar_160 = dollarQ_2_sysvq0asl(i_22);
                  NI32 X60Qx_1215 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I17558875563685861326_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1216 = len_4_sysvq0asl(X60Qdesugar_160);
                  NI32 X60Qx_1217 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 540877054u, .more_0 = (&strlit_0_I6387934463080488581_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1218 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I15883747490575809941_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1219 = len_4_sysvq0asl(w_7);
                  NI32 X60Qx_1220 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_161 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1215 + X60Qx_1216)) + X60Qx_1217)) + X60Qx_1218)) + X60Qx_1219)) + X60Qx_1220)));
                  add_2_sysvq0asl((&X60Qdesugar_161), (string_0_sysvq0asl){
                    .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I17558875563685861326_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_161), X60Qdesugar_160);
                  add_2_sysvq0asl((&X60Qdesugar_161), (string_0_sysvq0asl){
                    .bytes_0 = 540877054u, .more_0 = (&strlit_0_I6387934463080488581_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_161), (string_0_sysvq0asl){
                    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I15883747490575809941_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_161), w_7);
                  add_2_sysvq0asl((&X60Qdesugar_161), (string_0_sysvq0asl){
                    .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&result_47), X60Qdesugar_161);
                  string_0_sysvq0asl X60Qdesugar_162 = dollarQ_2_sysvq0asl(i_22);
                  NI32 X60Qx_1221 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18167370821491564789_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1222 = len_4_sysvq0asl(a_9);
                  NI32 X60Qx_1223 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 639642878u, .more_0 = (&strlit_0_I15101036524968472333_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1224 = len_4_sysvq0asl(X60Qdesugar_162);
                  NI32 X60Qx_1225 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                  );
                  NI32 X60Qx_1226 = len_4_sysvq0asl(w_7);
                  NI32 X60Qx_1227 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 540748286u, .more_0 = (&strlit_0_I17415683837379957581_aow7lb5cq1)}
                  );
                  string_0_sysvq0asl X60Qdesugar_163 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1221 + X60Qx_1222)) + X60Qx_1223)) + X60Qx_1224)) + X60Qx_1225)) + X60Qx_1226)) + X60Qx_1227)));
                  add_2_sysvq0asl((&X60Qdesugar_163), (string_0_sysvq0asl){
                    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18167370821491564789_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_163), a_9);
                  add_2_sysvq0asl((&X60Qdesugar_163), (string_0_sysvq0asl){
                    .bytes_0 = 639642878u, .more_0 = (&strlit_0_I15101036524968472333_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_163), X60Qdesugar_162);
                  add_2_sysvq0asl((&X60Qdesugar_163), (string_0_sysvq0asl){
                    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_163), w_7);
                  add_2_sysvq0asl((&X60Qdesugar_163), (string_0_sysvq0asl){
                    .bytes_0 = 540748286u, .more_0 = (&strlit_0_I17415683837379957581_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&result_47), X60Qdesugar_163);
                  NI32 X60Qx_1228 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1229 = len_4_sysvq0asl(w_7);
                  NI32 X60Qx_1230 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_164 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1228 + X60Qx_1229)) + X60Qx_1230)));
                  add_2_sysvq0asl((&X60Qdesugar_164), (string_0_sysvq0asl){
                    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_164), w_7);
                  add_2_sysvq0asl((&X60Qdesugar_164), (string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&result_47), X60Qdesugar_164);
                  nimStrDestroy(X60Qdesugar_164);
                  nimStrDestroy(X60Qdesugar_163);
                  nimStrDestroy(X60Qdesugar_162);
                  nimStrDestroy(X60Qdesugar_161);
                  nimStrDestroy(X60Qdesugar_160);
                  nimStrDestroy(X60Qdesugar_159);
                  nimStrDestroy(X60Qdesugar_158);}
                else {
                  NB8 X60Qx_1231 = enumOk_0_aow7lb5cq1((&f_14));
                  if (X60Qx_1231){
                    NI32 X60Qx_1232 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                    );
                    NI32 X60Qx_1233 = len_4_sysvq0asl(ty_2);
                    NI32 X60Qx_1234 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 8193u, .more_0 = NIM_NIL}
                    );
                    NI32 X60Qx_1235 = len_4_sysvq0asl(a_9);
                    NI32 X60Qx_1236 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 540877054u, .more_0 = (&strlit_0_I18160002208581309871_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1237 = len_4_sysvq0asl(ty_2);
                    NI32 X60Qx_1238 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1868638718u, .more_0 = (&strlit_0_I7038441574186707900_aow7lb5cq1)}
                    );
                    string_0_sysvq0asl X60Qdesugar_165 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1232 + X60Qx_1233)) + X60Qx_1234)) + X60Qx_1235)) + X60Qx_1236)) + X60Qx_1237)) + X60Qx_1238)));
                    add_2_sysvq0asl((&X60Qdesugar_165), (string_0_sysvq0asl){
                      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_165), ty_2);
                    add_2_sysvq0asl((&X60Qdesugar_165), (string_0_sysvq0asl){
                      .bytes_0 = 8193u, .more_0 = NIM_NIL}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_165), a_9);
                    add_2_sysvq0asl((&X60Qdesugar_165), (string_0_sysvq0asl){
                      .bytes_0 = 540877054u, .more_0 = (&strlit_0_I18160002208581309871_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_165), ty_2);
                    add_2_sysvq0asl((&X60Qdesugar_165), (string_0_sysvq0asl){
                      .bytes_0 = 1868638718u, .more_0 = (&strlit_0_I7038441574186707900_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&result_47), X60Qdesugar_165);
                    add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
                      .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I2765646999664450274_aow7lb5cq1)}
                    );
                    nimStrDestroy(X60Qdesugar_165);}
                  else {
                    NB8 X60Qx_1239 = varOk_0_aow7lb5cq1((&f_14));
                    if (X60Qx_1239){
                      string_0_sysvq0asl pt_0 = derefType_0_aow7lb5cq1(ty_2);
                      NI32 X60Qx_1240 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1241 = len_4_sysvq0asl(pt_0);
                      NI32 X60Qx_1242 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1243 = len_4_sysvq0asl(a_9);
                      NI32 X60Qx_1244 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_166 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1240 + X60Qx_1241)) + X60Qx_1242)) + X60Qx_1243)) + X60Qx_1244)));
                      add_2_sysvq0asl((&X60Qdesugar_166), (string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_166), pt_0);
                      add_2_sysvq0asl((&X60Qdesugar_166), (string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_166), a_9);
                      add_2_sysvq0asl((&X60Qdesugar_166), (string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_47), X60Qdesugar_166);
                      NI32 X60Qx_1245 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1246 = len_4_sysvq0asl(a_9);
                      NI32 X60Qx_1247 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1248 = len_4_sysvq0asl(w_7);
                      NI32 X60Qx_1249 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 572534014u, .more_0 = (&strlit_0_I16666830705696825015_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_167 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1245 + X60Qx_1246)) + X60Qx_1247)) + X60Qx_1248)) + X60Qx_1249)));
                      add_2_sysvq0asl((&X60Qdesugar_167), (string_0_sysvq0asl){
                        .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_167), a_9);
                      add_2_sysvq0asl((&X60Qdesugar_167), (string_0_sysvq0asl){
                        .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_167), w_7);
                      add_2_sysvq0asl((&X60Qdesugar_167), (string_0_sysvq0asl){
                        .bytes_0 = 572534014u, .more_0 = (&strlit_0_I16666830705696825015_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&result_47), X60Qdesugar_167);
                      NI32 X60Qx_1250 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1251 = len_4_sysvq0asl(a_9);
                      NI32 X60Qx_1252 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1253 = len_4_sysvq0asl(w_7);
                      NI32 X60Qx_1254 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_168 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1250 + X60Qx_1251)) + X60Qx_1252)) + X60Qx_1253)) + X60Qx_1254)));
                      add_2_sysvq0asl((&X60Qdesugar_168), (string_0_sysvq0asl){
                        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_168), a_9);
                      add_2_sysvq0asl((&X60Qdesugar_168), (string_0_sysvq0asl){
                        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_168), w_7);
                      add_2_sysvq0asl((&X60Qdesugar_168), (string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_47), X60Qdesugar_168);
                      NI32 X60Qx_1255 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1256 = len_4_sysvq0asl(w_7);
                      NI32 X60Qx_1257 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_169 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1255 + X60Qx_1256)) + X60Qx_1257)));
                      add_2_sysvq0asl((&X60Qdesugar_169), (string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_169), w_7);
                      add_2_sysvq0asl((&X60Qdesugar_169), (string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_47), X60Qdesugar_169);
                      nimStrDestroy(argExpr_0);
                      string_0_sysvq0asl X60Qx_1258 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 9729u, .more_0 = NIM_NIL}
                      , a_9);
                      argExpr_0 = X60Qx_1258;
                      NB8 X60Qx_1259;
                      NI32 X60Qx_1260 = len_3_I0v1j8d_aow7lb5cq1((*e_4).d_00.outVarOffs_0);
                      if (i_22 < X60Qx_1260){
                        NI32* X60Qx_1261 = getQ_7_Ir8kccm_aow7lb5cq1((*e_4).d_00.outVarOffs_0, i_22);
                        X60Qx_1259 = (0 <= (*X60Qx_1261));}
                      else {
                        X60Qx_1259 = NIM_FALSE;}
                      if (X60Qx_1259){
                        NI32* X60Qx_1262 = getQ_7_Ir8kccm_aow7lb5cq1((*e_4).d_00.outVarOffs_0, i_22);
                        string_0_sysvq0asl X60Qdesugar_170 = dollarQ_2_sysvq0asl((*X60Qx_1262));
                        NI32 X60Qx_1263 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I17822294574896570456_aow7lb5cq1)}
                        );
                        NI32 X60Qx_1264 = len_4_sysvq0asl(X60Qdesugar_170);
                        NI32 X60Qx_1265 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 639642627u, .more_0 = NIM_NIL}
                        );
                        NI32 X60Qx_1266 = len_4_sysvq0asl(a_9);
                        NI32 X60Qx_1267 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                        );
                        NI32 X60Qx_1268 = len_4_sysvq0asl(w_7);
                        NI32 X60Qx_1269 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                        );
                        string_0_sysvq0asl X60Qdesugar_171 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1263 + X60Qx_1264)) + X60Qx_1265)) + X60Qx_1266)) + X60Qx_1267)) + X60Qx_1268)) + X60Qx_1269)));
                        add_2_sysvq0asl((&X60Qdesugar_171), (string_0_sysvq0asl){
                          .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I17822294574896570456_aow7lb5cq1)}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_171), X60Qdesugar_170);
                        add_2_sysvq0asl((&X60Qdesugar_171), (string_0_sysvq0asl){
                          .bytes_0 = 639642627u, .more_0 = NIM_NIL}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_171), a_9);
                        add_2_sysvq0asl((&X60Qdesugar_171), (string_0_sysvq0asl){
                          .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_171), w_7);
                        add_2_sysvq0asl((&X60Qdesugar_171), (string_0_sysvq0asl){
                          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                        );
                        add_2_sysvq0asl((&writeback_0), X60Qdesugar_171);
                        nimStrDestroy(X60Qdesugar_171);
                        nimStrDestroy(X60Qdesugar_170);}
                      nimStrDestroy(X60Qdesugar_169);
                      nimStrDestroy(X60Qdesugar_168);
                      nimStrDestroy(X60Qdesugar_167);
                      nimStrDestroy(X60Qdesugar_166);
                      nimStrDestroy(pt_0);}
                    else {
                      NI32 X60Qx_1270 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1271 = len_4_sysvq0asl(ty_2);
                      NI32 X60Qx_1272 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1273 = len_4_sysvq0asl(a_9);
                      NI32 X60Qx_1274 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I18160002208581309871_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1275 = len_4_sysvq0asl(ty_2);
                      NI32 X60Qx_1276 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1868638718u, .more_0 = (&strlit_0_I8046607679966277039_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1277 = len_4_sysvq0asl(w_7);
                      NI32 X60Qx_1278 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_172 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1270 + X60Qx_1271)) + X60Qx_1272)) + X60Qx_1273)) + X60Qx_1274)) + X60Qx_1275)) + X60Qx_1276)) + X60Qx_1277)) + X60Qx_1278)));
                      add_2_sysvq0asl((&X60Qdesugar_172), (string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_172), ty_2);
                      add_2_sysvq0asl((&X60Qdesugar_172), (string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_172), a_9);
                      add_2_sysvq0asl((&X60Qdesugar_172), (string_0_sysvq0asl){
                        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I18160002208581309871_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_172), ty_2);
                      add_2_sysvq0asl((&X60Qdesugar_172), (string_0_sysvq0asl){
                        .bytes_0 = 1868638718u, .more_0 = (&strlit_0_I8046607679966277039_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_172), w_7);
                      add_2_sysvq0asl((&X60Qdesugar_172), (string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_47), X60Qdesugar_172);
                      NI32 X60Qx_1279 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1280 = len_4_sysvq0asl(w_7);
                      NI32 X60Qx_1281 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_173 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1279 + X60Qx_1280)) + X60Qx_1281)));
                      add_2_sysvq0asl((&X60Qdesugar_173), (string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_173), w_7);
                      add_2_sysvq0asl((&X60Qdesugar_173), (string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_47), X60Qdesugar_173);
                      nimStrDestroy(X60Qdesugar_173);
                      nimStrDestroy(X60Qdesugar_172);}}}}}}}
        if (0 < i_22){
          add_2_sysvq0asl((&call_1), (string_0_sysvq0asl){
            .bytes_0 = 2108418u, .more_0 = NIM_NIL}
          );}
        add_2_sysvq0asl((&call_1), argExpr_0);
        inc_1_I6wjjge_aow2h993l1((&i_22));
        nimStrDestroy(argExpr_0);
        nimStrDestroy(w_7);
        nimStrDestroy(ty_2);
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_14));
        nimStrDestroy(a_9);
        nimStrDestroy(X60Qtmp_35);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  add_2_sysvq0asl((&call_1), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  if ((*e_4).d_00.retVoid_0){
    NI32 X60Qx_1282 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1283 = len_4_sysvq0asl(call_1);
    NI32 X60Qx_1284 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_174 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1282 + X60Qx_1283)) + X60Qx_1284)));
    add_2_sysvq0asl((&X60Qdesugar_174), (string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_174), call_1);
    add_2_sysvq0asl((&X60Qdesugar_174), (string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&result_47), X60Qdesugar_174);
    add_2_sysvq0asl((&result_47), owned_1);
    add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
      .bytes_0 = 673194238u, .more_0 = (&strlit_0_I13766595355654876791_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_175 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
    string_0_sysvq0asl X60Qdesugar_176 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
    NI32 X60Qx_1285 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
    );
    NI32 X60Qx_1286 = len_4_sysvq0asl(X60Qdesugar_175);
    NI32 X60Qx_1287 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
    );
    NI32 X60Qx_1288 = len_4_sysvq0asl(X60Qdesugar_176);
    NI32 X60Qx_1289 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_177 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1285 + X60Qx_1286)) + X60Qx_1287)) + X60Qx_1288)) + X60Qx_1289)));
    add_2_sysvq0asl((&X60Qdesugar_177), (string_0_sysvq0asl){
      .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_177), X60Qdesugar_175);
    add_2_sysvq0asl((&X60Qdesugar_177), (string_0_sysvq0asl){
      .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_177), X60Qdesugar_176);
    add_2_sysvq0asl((&X60Qdesugar_177), (string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&result_47), X60Qdesugar_177);
    add_2_sysvq0asl((&result_47), writeback_0);
    string_0_sysvq0asl X60Qdesugar_178 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
    NI32 X60Qx_1290 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
    );
    NI32 X60Qx_1291 = len_4_sysvq0asl(X60Qdesugar_178);
    NI32 X60Qx_1292 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_179 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1290 + X60Qx_1291)) + X60Qx_1292)));
    add_2_sysvq0asl((&X60Qdesugar_179), (string_0_sysvq0asl){
      .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_179), X60Qdesugar_178);
    add_2_sysvq0asl((&X60Qdesugar_179), (string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&result_47), X60Qdesugar_179);
    nimStrDestroy(X60Qdesugar_179);
    nimStrDestroy(X60Qdesugar_178);
    nimStrDestroy(X60Qdesugar_177);
    nimStrDestroy(X60Qdesugar_176);
    nimStrDestroy(X60Qdesugar_175);
    nimStrDestroy(X60Qdesugar_174);}
  else {
    if ((*e_4).d_00.ret_0.isComposite_0){
      string_0_sysvq0asl X60Qtmp_36 = stashedCall_0_aow7lb5cq1(sig_0.ret_0, call_1);
      add_2_sysvq0asl((&result_47), X60Qtmp_36);
      add_2_sysvq0asl((&result_47), owned_1);
      NB8 sok_0 = NIM_TRUE;
      string_0_sysvq0asl sizePass_0 = emitCompositeSize_0_aow7lb5cq1((*e_4).d_00.ret_0.desc_0, unit_5, sig_0.ret_0, (string_0_sysvq0asl){
        .bytes_0 = 6255106u, .more_0 = NIM_NIL}
      , (&ctmp_0), (&sok_0));
      string_0_sysvq0asl freeing_1 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      string_0_sysvq0asl writePass_0 = emitCompositeOut_0_aow7lb5cq1((*e_4).d_00.ret_0.desc_0, unit_5, sig_0.ret_0, (string_0_sysvq0asl){
        .bytes_0 = 6255106u, .more_0 = NIM_NIL}
      , deallocFn_2, (&ctmp_0), (&freeing_1), (&sok_0));
      if ((!sok_0)){
        nimStrDestroy(writePass_0);
        nimStrDestroy(freeing_1);
        nimStrDestroy(sizePass_0);
        nimStrDestroy(X60Qtmp_36);
        nimStrDestroy(writeback_0);
        nimStrDestroy(owned_1);
        nimStrDestroy(call_1);
        nimStrDestroy(X60Qdesugar_126);
        nimStrDestroy(X60Qdesugar_125);
        return (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;}
      add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I17934854375404503520_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_47), sizePass_0);
      add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12313396470659978363_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10672841733508358863_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4024411879076867166_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4649953770147481749_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5487312882993115281_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10166787625402032659_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_47), writePass_0);
      add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I13914791540775111549_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_47), freeing_1);
      add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I6654729803687239304_aow7lb5cq1)}
      );
      nimStrDestroy(writePass_0);
      nimStrDestroy(freeing_1);
      nimStrDestroy(sizePass_0);
      nimStrDestroy(X60Qtmp_36);}
    else {
      NB8 X60Qx_1293 = stringOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
      if (X60Qx_1293){
        string_0_sysvq0asl X60Qtmp_37 = stashedCall_0_aow7lb5cq1(strT_2, call_1);
        add_2_sysvq0asl((&result_47), X60Qtmp_37);
        add_2_sysvq0asl((&result_47), owned_1);
        add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I12522613173660839319_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I3911820715027972186_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I790167309358444658_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5310786661721115423_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qtmp_38 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I8269886702836948419_aow7lb5cq1)}
        , (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I14081904980903256320_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_47), X60Qtmp_38);
        add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11068729316509706393_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I9486276691579103789_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1654792515589026066_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
          .bytes_0 = 2099257598u, .more_0 = (&strlit_0_I6468377022308900005_aow7lb5cq1)}
        );
        nimStrDestroy(X60Qtmp_38);
        nimStrDestroy(X60Qtmp_37);}
      else {
        NB8 X60Qx_1294 = seqOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
        if (X60Qx_1294){
          string_0_sysvq0asl st_1 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.elemStride_0);
          string_0_sysvq0asl X60Qtmp_39 = stashedCall_0_aow7lb5cq1(sig_0.ret_0, call_1);
          add_2_sysvq0asl((&result_47), X60Qtmp_39);
          add_2_sysvq0asl((&result_47), owned_1);
          NI32 X60Qx_1295 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I4970679303273918317_aow7lb5cq1)}
          );
          NI32 X60Qx_1296 = len_4_sysvq0asl(st_1);
          NI32 X60Qx_1297 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_180 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1295 + X60Qx_1296)) + X60Qx_1297)));
          add_2_sysvq0asl((&X60Qdesugar_180), (string_0_sysvq0asl){
            .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I4970679303273918317_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_180), st_1);
          add_2_sysvq0asl((&X60Qdesugar_180), (string_0_sysvq0asl){
            .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_47), X60Qdesugar_180);
          add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
            .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I12522613173660839319_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11224338710434874543_aow7lb5cq1)}
          );
          NI32 X60Qx_1298 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16703820542586360166_aow7lb5cq1)}
          );
          NI32 X60Qx_1299 = len_4_sysvq0asl(st_1);
          NI32 X60Qx_1300 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 171649283u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_181 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1298 + X60Qx_1299)) + X60Qx_1300)));
          add_2_sysvq0asl((&X60Qdesugar_181), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16703820542586360166_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_181), st_1);
          add_2_sysvq0asl((&X60Qdesugar_181), (string_0_sysvq0asl){
            .bytes_0 = 171649283u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&result_47), X60Qdesugar_181);
          add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I31630099792905633_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11068729316509706393_aow7lb5cq1)}
          );
          NI32 X60Qx_1301 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15275851150300379331_aow7lb5cq1)}
          );
          NI32 X60Qx_1302 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1769154814u, .more_0 = (&strlit_0_I3690031806701659348_aow7lb5cq1)}
          );
          NI32 X60Qx_1303 = len_4_sysvq0asl(st_1);
          NI32 X60Qx_1304 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_182 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1301 + X60Qx_1302)) + X60Qx_1303)) + X60Qx_1304)));
          add_2_sysvq0asl((&X60Qdesugar_182), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15275851150300379331_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_182), (string_0_sysvq0asl){
            .bytes_0 = 1769154814u, .more_0 = (&strlit_0_I3690031806701659348_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_182), st_1);
          add_2_sysvq0asl((&X60Qdesugar_182), (string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_47), X60Qdesugar_182);
          NI32 X60Qx_1305 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I8277570052652068250_aow7lb5cq1)}
          );
          NI32 X60Qx_1306 = len_4_sysvq0asl(deallocFn_2);
          NI32 X60Qx_1307 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I8678069405976132067_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_183 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1305 + X60Qx_1306)) + X60Qx_1307)));
          add_2_sysvq0asl((&X60Qdesugar_183), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I8277570052652068250_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_183), deallocFn_2);
          add_2_sysvq0asl((&X60Qdesugar_183), (string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I8678069405976132067_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_47), X60Qdesugar_183);
          add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1654792515589026066_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
            .bytes_0 = 2099257598u, .more_0 = (&strlit_0_I6468377022308900005_aow7lb5cq1)}
          );
          nimStrDestroy(X60Qdesugar_183);
          nimStrDestroy(X60Qdesugar_182);
          nimStrDestroy(X60Qdesugar_181);
          nimStrDestroy(X60Qdesugar_180);
          nimStrDestroy(X60Qtmp_39);
          nimStrDestroy(st_1);}
        else {
          NB8 X60Qx_1308 = podOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
          if (X60Qx_1308){
            NI32 X60Qx_1309 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_1310 = len_4_sysvq0asl(sig_0.ret_0);
            NI32 X60Qx_1311 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
            );
            NI32 X60Qx_1312 = len_4_sysvq0asl(call_1);
            NI32 X60Qx_1313 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_184 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1309 + X60Qx_1310)) + X60Qx_1311)) + X60Qx_1312)) + X60Qx_1313)));
            add_2_sysvq0asl((&X60Qdesugar_184), (string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_184), sig_0.ret_0);
            add_2_sysvq0asl((&X60Qdesugar_184), (string_0_sysvq0asl){
              .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_184), call_1);
            add_2_sysvq0asl((&X60Qdesugar_184), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_47), X60Qdesugar_184);
            add_2_sysvq0asl((&result_47), owned_1);
            string_0_sysvq0asl X60Qdesugar_185 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
            NI32 X60Qx_1314 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I15878504505370534443_aow7lb5cq1)}
            );
            NI32 X60Qx_1315 = len_4_sysvq0asl(X60Qdesugar_185);
            NI32 X60Qx_1316 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 572534014u, .more_0 = (&strlit_0_I17578962040280315901_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_186 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1314 + X60Qx_1315)) + X60Qx_1316)));
            add_2_sysvq0asl((&X60Qdesugar_186), (string_0_sysvq0asl){
              .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I15878504505370534443_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_186), X60Qdesugar_185);
            add_2_sysvq0asl((&X60Qdesugar_186), (string_0_sysvq0asl){
              .bytes_0 = 572534014u, .more_0 = (&strlit_0_I17578962040280315901_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_47), X60Qdesugar_186);
            string_0_sysvq0asl X60Qdesugar_187 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
            string_0_sysvq0asl X60Qdesugar_188 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
            NI32 X60Qx_1317 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
            );
            NI32 X60Qx_1318 = len_4_sysvq0asl(X60Qdesugar_187);
            NI32 X60Qx_1319 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
            );
            NI32 X60Qx_1320 = len_4_sysvq0asl(X60Qdesugar_188);
            NI32 X60Qx_1321 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_189 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1317 + X60Qx_1318)) + X60Qx_1319)) + X60Qx_1320)) + X60Qx_1321)));
            add_2_sysvq0asl((&X60Qdesugar_189), (string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_189), X60Qdesugar_187);
            add_2_sysvq0asl((&X60Qdesugar_189), (string_0_sysvq0asl){
              .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_189), X60Qdesugar_188);
            add_2_sysvq0asl((&X60Qdesugar_189), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_47), X60Qdesugar_189);
            string_0_sysvq0asl X60Qdesugar_190 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
            NI32 X60Qx_1322 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I5036188731385662161_aow7lb5cq1)}
            );
            NI32 X60Qx_1323 = len_4_sysvq0asl(X60Qdesugar_190);
            NI32 X60Qx_1324 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 171649283u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_191 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1322 + X60Qx_1323)) + X60Qx_1324)));
            add_2_sysvq0asl((&X60Qdesugar_191), (string_0_sysvq0asl){
              .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I5036188731385662161_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_191), X60Qdesugar_190);
            add_2_sysvq0asl((&X60Qdesugar_191), (string_0_sysvq0asl){
              .bytes_0 = 171649283u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_47), X60Qdesugar_191);
            add_2_sysvq0asl((&result_47), writeback_0);
            string_0_sysvq0asl X60Qdesugar_192 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
            NI32 X60Qx_1325 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
            );
            NI32 X60Qx_1326 = len_4_sysvq0asl(X60Qdesugar_192);
            NI32 X60Qx_1327 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_193 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1325 + X60Qx_1326)) + X60Qx_1327)));
            add_2_sysvq0asl((&X60Qdesugar_193), (string_0_sysvq0asl){
              .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_193), X60Qdesugar_192);
            add_2_sysvq0asl((&X60Qdesugar_193), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_47), X60Qdesugar_193);
            nimStrDestroy(X60Qdesugar_193);
            nimStrDestroy(X60Qdesugar_192);
            nimStrDestroy(X60Qdesugar_191);
            nimStrDestroy(X60Qdesugar_190);
            nimStrDestroy(X60Qdesugar_189);
            nimStrDestroy(X60Qdesugar_188);
            nimStrDestroy(X60Qdesugar_187);
            nimStrDestroy(X60Qdesugar_186);
            nimStrDestroy(X60Qdesugar_185);
            nimStrDestroy(X60Qdesugar_184);}
          else {
            NB8 X60Qx_1328 = floatOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
            if (X60Qx_1328){
              NI32 X60Qx_1329 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1330 = len_4_sysvq0asl(sig_0.ret_0);
              NI32 X60Qx_1331 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
              );
              NI32 X60Qx_1332 = len_4_sysvq0asl(call_1);
              NI32 X60Qx_1333 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_194 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1329 + X60Qx_1330)) + X60Qx_1331)) + X60Qx_1332)) + X60Qx_1333)));
              add_2_sysvq0asl((&X60Qdesugar_194), (string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_194), sig_0.ret_0);
              add_2_sysvq0asl((&X60Qdesugar_194), (string_0_sysvq0asl){
                .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_194), call_1);
              add_2_sysvq0asl((&X60Qdesugar_194), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_194);
              add_2_sysvq0asl((&result_47), owned_1);
              string_0_sysvq0asl X60Qdesugar_195 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
              string_0_sysvq0asl X60Qdesugar_196 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
              NI32 X60Qx_1334 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
              );
              NI32 X60Qx_1335 = len_4_sysvq0asl(X60Qdesugar_195);
              NI32 X60Qx_1336 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
              );
              NI32 X60Qx_1337 = len_4_sysvq0asl(X60Qdesugar_196);
              NI32 X60Qx_1338 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_197 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1334 + X60Qx_1335)) + X60Qx_1336)) + X60Qx_1337)) + X60Qx_1338)));
              add_2_sysvq0asl((&X60Qdesugar_197), (string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_197), X60Qdesugar_195);
              add_2_sysvq0asl((&X60Qdesugar_197), (string_0_sysvq0asl){
                .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_197), X60Qdesugar_196);
              add_2_sysvq0asl((&X60Qdesugar_197), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_197);
              string_0_sysvq0asl X60Qdesugar_198 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
              NI32 X60Qx_1339 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I9629254699824304600_aow7lb5cq1)}
              );
              NI32 X60Qx_1340 = len_4_sysvq0asl(X60Qdesugar_198);
              NI32 X60Qx_1341 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 171649283u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_199 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1339 + X60Qx_1340)) + X60Qx_1341)));
              add_2_sysvq0asl((&X60Qdesugar_199), (string_0_sysvq0asl){
                .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I9629254699824304600_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_199), X60Qdesugar_198);
              add_2_sysvq0asl((&X60Qdesugar_199), (string_0_sysvq0asl){
                .bytes_0 = 171649283u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_199);
              string_0_sysvq0asl X60Qdesugar_200 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
              NI32 X60Qx_1342 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10542844442866812539_aow7lb5cq1)}
              );
              NI32 X60Qx_1343 = len_4_sysvq0asl(X60Qdesugar_200);
              NI32 X60Qx_1344 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 673197310u, .more_0 = (&strlit_0_I10562638173522793194_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_201 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1342 + X60Qx_1343)) + X60Qx_1344)));
              add_2_sysvq0asl((&X60Qdesugar_201), (string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10542844442866812539_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_201), X60Qdesugar_200);
              add_2_sysvq0asl((&X60Qdesugar_201), (string_0_sysvq0asl){
                .bytes_0 = 673197310u, .more_0 = (&strlit_0_I10562638173522793194_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_201);
              add_2_sysvq0asl((&result_47), writeback_0);
              string_0_sysvq0asl X60Qdesugar_202 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
              NI32 X60Qx_1345 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
              );
              NI32 X60Qx_1346 = len_4_sysvq0asl(X60Qdesugar_202);
              NI32 X60Qx_1347 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_203 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1345 + X60Qx_1346)) + X60Qx_1347)));
              add_2_sysvq0asl((&X60Qdesugar_203), (string_0_sysvq0asl){
                .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_203), X60Qdesugar_202);
              add_2_sysvq0asl((&X60Qdesugar_203), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_47), X60Qdesugar_203);
              nimStrDestroy(X60Qdesugar_203);
              nimStrDestroy(X60Qdesugar_202);
              nimStrDestroy(X60Qdesugar_201);
              nimStrDestroy(X60Qdesugar_200);
              nimStrDestroy(X60Qdesugar_199);
              nimStrDestroy(X60Qdesugar_198);
              nimStrDestroy(X60Qdesugar_197);
              nimStrDestroy(X60Qdesugar_196);
              nimStrDestroy(X60Qdesugar_195);
              nimStrDestroy(X60Qdesugar_194);}
            else {
              NB8 X60Qx_1348 = enumOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
              if (X60Qx_1348){
                NI32 X60Qx_1349 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_1350 = len_4_sysvq0asl(sig_0.ret_0);
                NI32 X60Qx_1351 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
                );
                NI32 X60Qx_1352 = len_4_sysvq0asl(call_1);
                NI32 X60Qx_1353 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_204 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1349 + X60Qx_1350)) + X60Qx_1351)) + X60Qx_1352)) + X60Qx_1353)));
                add_2_sysvq0asl((&X60Qdesugar_204), (string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_204), sig_0.ret_0);
                add_2_sysvq0asl((&X60Qdesugar_204), (string_0_sysvq0asl){
                  .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_204), call_1);
                add_2_sysvq0asl((&X60Qdesugar_204), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_204);
                add_2_sysvq0asl((&result_47), owned_1);
                string_0_sysvq0asl X60Qdesugar_205 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                string_0_sysvq0asl X60Qdesugar_206 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                NI32 X60Qx_1354 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
                );
                NI32 X60Qx_1355 = len_4_sysvq0asl(X60Qdesugar_205);
                NI32 X60Qx_1356 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
                );
                NI32 X60Qx_1357 = len_4_sysvq0asl(X60Qdesugar_206);
                NI32 X60Qx_1358 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_207 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1354 + X60Qx_1355)) + X60Qx_1356)) + X60Qx_1357)) + X60Qx_1358)));
                add_2_sysvq0asl((&X60Qdesugar_207), (string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_207), X60Qdesugar_205);
                add_2_sysvq0asl((&X60Qdesugar_207), (string_0_sysvq0asl){
                  .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_207), X60Qdesugar_206);
                add_2_sysvq0asl((&X60Qdesugar_207), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_207);
                add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
                  .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I5435985303747042468_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&result_47), writeback_0);
                string_0_sysvq0asl X60Qdesugar_208 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                NI32 X60Qx_1359 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
                );
                NI32 X60Qx_1360 = len_4_sysvq0asl(X60Qdesugar_208);
                NI32 X60Qx_1361 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_209 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1359 + X60Qx_1360)) + X60Qx_1361)));
                add_2_sysvq0asl((&X60Qdesugar_209), (string_0_sysvq0asl){
                  .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_209), X60Qdesugar_208);
                add_2_sysvq0asl((&X60Qdesugar_209), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_209);
                nimStrDestroy(X60Qdesugar_209);
                nimStrDestroy(X60Qdesugar_208);
                nimStrDestroy(X60Qdesugar_207);
                nimStrDestroy(X60Qdesugar_206);
                nimStrDestroy(X60Qdesugar_205);
                nimStrDestroy(X60Qdesugar_204);}
              else {
                NI32 X60Qx_1362 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I15987315423624941794_aow7lb5cq1)}
                );
                NI32 X60Qx_1363 = len_4_sysvq0asl(call_1);
                NI32 X60Qx_1364 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_210 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1362 + X60Qx_1363)) + X60Qx_1364)));
                add_2_sysvq0asl((&X60Qdesugar_210), (string_0_sysvq0asl){
                  .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I15987315423624941794_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_210), call_1);
                add_2_sysvq0asl((&X60Qdesugar_210), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_210);
                add_2_sysvq0asl((&result_47), owned_1);
                string_0_sysvq0asl X60Qdesugar_211 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                string_0_sysvq0asl X60Qdesugar_212 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                NI32 X60Qx_1365 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
                );
                NI32 X60Qx_1366 = len_4_sysvq0asl(X60Qdesugar_211);
                NI32 X60Qx_1367 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
                );
                NI32 X60Qx_1368 = len_4_sysvq0asl(X60Qdesugar_212);
                NI32 X60Qx_1369 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_213 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1365 + X60Qx_1366)) + X60Qx_1367)) + X60Qx_1368)) + X60Qx_1369)));
                add_2_sysvq0asl((&X60Qdesugar_213), (string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_213), X60Qdesugar_211);
                add_2_sysvq0asl((&X60Qdesugar_213), (string_0_sysvq0asl){
                  .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_213), X60Qdesugar_212);
                add_2_sysvq0asl((&X60Qdesugar_213), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_213);
                string_0_sysvq0asl X60Qdesugar_214 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
                NI32 X60Qx_1370 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I5946066183656141387_aow7lb5cq1)}
                );
                NI32 X60Qx_1371 = len_4_sysvq0asl(X60Qdesugar_214);
                NI32 X60Qx_1372 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914711294u, .more_0 = (&strlit_0_I6448058756119716242_aow7lb5cq1)}
                );
                string_0_sysvq0asl X60Qdesugar_215 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1370 + X60Qx_1371)) + X60Qx_1372)));
                add_2_sysvq0asl((&X60Qdesugar_215), (string_0_sysvq0asl){
                  .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I5946066183656141387_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_215), X60Qdesugar_214);
                add_2_sysvq0asl((&X60Qdesugar_215), (string_0_sysvq0asl){
                  .bytes_0 = 1914711294u, .more_0 = (&strlit_0_I6448058756119716242_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_215);
                add_2_sysvq0asl((&result_47), writeback_0);
                string_0_sysvq0asl X60Qdesugar_216 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                NI32 X60Qx_1373 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
                );
                NI32 X60Qx_1374 = len_4_sysvq0asl(X60Qdesugar_216);
                NI32 X60Qx_1375 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_217 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1373 + X60Qx_1374)) + X60Qx_1375)));
                add_2_sysvq0asl((&X60Qdesugar_217), (string_0_sysvq0asl){
                  .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_217), X60Qdesugar_216);
                add_2_sysvq0asl((&X60Qdesugar_217), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_47), X60Qdesugar_217);
                nimStrDestroy(X60Qdesugar_217);
                nimStrDestroy(X60Qdesugar_216);
                nimStrDestroy(X60Qdesugar_215);
                nimStrDestroy(X60Qdesugar_214);
                nimStrDestroy(X60Qdesugar_213);
                nimStrDestroy(X60Qdesugar_212);
                nimStrDestroy(X60Qdesugar_211);
                nimStrDestroy(X60Qdesugar_210);}}}}}}}
  add_2_sysvq0asl((&result_47), (string_0_sysvq0asl){
    .bytes_0 = 687362u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(writeback_0);
  nimStrDestroy(owned_1);
  nimStrDestroy(call_1);
  nimStrDestroy(X60Qdesugar_126);
  nimStrDestroy(X60Qdesugar_125);
  return result_47;
  nimStrDestroy(writeback_0);
  nimStrDestroy(owned_1);
  nimStrDestroy(call_1);
  nimStrDestroy(X60Qdesugar_126);
  nimStrDestroy(X60Qdesugar_125);
  return result_47;}
string_0_sysvq0asl aowlcBin_0_aow7lb5cq1(void){
  string_0_sysvq0asl result_48;
  nimStrWasMoved((&result_48));
  nimStrDestroy(result_48);
  string_0_sysvq0asl X60Qx_1376 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I13635149261874571511_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  result_48 = X60Qx_1376;
  NI32 X60Qx_1377 = len_4_sysvq0asl(result_48);
  if (X60Qx_1377 == 0){
    nimStrDestroy(result_48);
    string_0_sysvq0asl X60Qtmp_42 = getHomeDir_0_osalirkw71();
    string_0_sysvq0asl X60Qtmp_41 = slashQ_0_ospaexnw61(X60Qtmp_42, (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I2994922137697771110_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qtmp_40 = slashQ_0_ospaexnw61(X60Qtmp_41, (string_0_sysvq0asl){
      .bytes_0 = 1852400131u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qx_1378 = slashQ_0_ospaexnw61(X60Qtmp_40, (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I2994922137697771110_aow7lb5cq1)}
    );
    result_48 = X60Qx_1378;
    nimStrDestroy(X60Qtmp_40);
    nimStrDestroy(X60Qtmp_41);
    nimStrDestroy(X60Qtmp_42);}
  return result_48;}
string_0_sysvq0asl moduleSuffix_0_aow7lb5cq1(string_0_sysvq0asl path_0){
  string_0_sysvq0asl result_49;
  nimStrWasMoved((&result_49));
  nimStrDestroy(result_49);
  string_0_sysvq0asl X60Qx_1379 = extractFilename_0_ospaexnw61(path_0);
  result_49 = X60Qx_1379;
  NB8 X60Qx_39;
  NI32 X60Qx_1380 = len_4_sysvq0asl(result_49);
  if (6 < X60Qx_1380){
    NB8 X60Qx_40;
    NI32 X60Qx_1381 = len_4_sysvq0asl(result_49);
    NI32 X60Qx_1382 = len_4_sysvq0asl(result_49);
    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1383 = ___1_Iclcqmw1_aow7lb5cq1(((NI32)(X60Qx_1381 - 6)), ((NI32)(X60Qx_1382 - 1)));
    string_0_sysvq0asl X60Qtmp_43 = getQ_14_sysvq0asl(result_49, X60Qx_1383);
    NB8 X60Qx_1384 = eqQ_20_sysvq0asl(X60Qtmp_43, (string_0_sysvq0asl){
      .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17410079638349000741_aow7lb5cq1)}
    );
    if (X60Qx_1384){
      X60Qx_40 = NIM_TRUE;}
    else {
      NI32 X60Qx_1385 = len_4_sysvq0asl(result_49);
      NI32 X60Qx_1386 = len_4_sysvq0asl(result_49);
      HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1387 = ___1_Iclcqmw1_aow7lb5cq1(((NI32)(X60Qx_1385 - 6)), ((NI32)(X60Qx_1386 - 1)));
      string_0_sysvq0asl X60Qtmp_44 = getQ_14_sysvq0asl(result_49, X60Qx_1387);
      NB8 X60Qx_1388 = eqQ_20_sysvq0asl(X60Qtmp_44, (string_0_sysvq0asl){
        .bytes_0 = 779628286u, .more_0 = (&strlit_0_I14570291026200354739_aow7lb5cq1)}
      );
      X60Qx_40 = X60Qx_1388;
      nimStrDestroy(X60Qtmp_44);}
    X60Qx_39 = X60Qx_40;
    nimStrDestroy(X60Qtmp_43);}
  else {
    X60Qx_39 = NIM_FALSE;}
  if (X60Qx_39){
    NI32 X60Qx_1389 = len_4_sysvq0asl(result_49);
    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1390 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_1389 - 7)));
    string_0_sysvq0asl X60Qlhs_45 = getQ_14_sysvq0asl(result_49, X60Qx_1390);
    nimStrDestroy(result_49);
    result_49 = X60Qlhs_45;}
  return result_49;}
seq_0_Ixdx2fh1_aow7lb5cq1 undefinedFromLog_0_aow7lb5cq1(string_0_sysvq0asl logFile_0){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_52;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_52));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_52);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1419 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_52 = X60Qx_1419;
  string_0_sysvq0asl text_1 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_0 = readFile_0_syn1lfpjv(logFile_0);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_0;}
  nimStrDestroy(text_1);
  string_0_sysvq0asl X60Qx_1420 = nimStrDup(X60QcanRaise_0.fld_1);
  text_1 = X60Qx_1420;
  if (NIM_FALSE){
    X60Qexlab_0: ;
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1421 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    result_52 = X60Qx_1421;
    nimStrDestroy(text_1);
    return result_52;}
  NI32 i_30 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1422 = len_4_sysvq0asl(text_1);
      if (i_30 < X60Qx_1422){
        string_0_sysvq0asl name_3 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;
        NB8 X60Qx_42;
        NB8 X60Qx_1423;
        NC8 X60Qx_1424 = getQ_9_sysvq0asl(text_1, i_30);
        if (X60Qx_1424 == (NC8)'u'){
          NI32 X60Qx_1425 = len_4_sysvq0asl(text_1);
          X60Qx_1423 = (((NI32)(i_30 + 18)) <= X60Qx_1425);}
        else {
          X60Qx_1423 = NIM_FALSE;}
        if (X60Qx_1423){
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1426 = ___1_Iclcqmw1_aow7lb5cq1(i_30, ((NI32)(i_30 + 17)));
          string_0_sysvq0asl X60Qtmp_47 = getQ_14_sysvq0asl(text_1, X60Qx_1426);
          NB8 X60Qx_1427 = eqQ_20_sysvq0asl(X60Qtmp_47, (string_0_sysvq0asl){
            .bytes_0 = 1684960766u, .more_0 = (&strlit_0_I7764585516723727988_aow7lb5cq1)}
          );
          X60Qx_42 = X60Qx_1427;
          nimStrDestroy(X60Qtmp_47);}
        else {
          X60Qx_42 = NIM_FALSE;}
        if (X60Qx_42){
          NI32 j_9 = ((NI32)(i_30 + 18));
          {
            while (NIM_TRUE){
              NB8 X60Qx_1428;
              NI32 X60Qx_1429 = len_4_sysvq0asl(text_1);
              if (j_9 < X60Qx_1429){
                NC8 X60Qx_1430 = getQ_9_sysvq0asl(text_1, j_9);
                NB8 X60Qx_1431 = isIdentChar_0_aow7lb5cq1(X60Qx_1430);
                X60Qx_1428 = X60Qx_1431;}
              else {
                X60Qx_1428 = NIM_FALSE;}
              if (X60Qx_1428){
                NC8 X60Qx_1432 = getQ_9_sysvq0asl(text_1, j_9);
                add_1_sysvq0asl((&name_3), X60Qx_1432);
                inc_1_I6wjjge_aow2h993l1((&j_9));}
              else {
                break;}}}
          whileStmtLabel_1: ;}
        else {
          NB8 X60Qx_43;
          NB8 X60Qx_1433;
          NC8 X60Qx_1434 = getQ_9_sysvq0asl(text_1, i_30);
          if (X60Qx_1434 == (NC8)'u'){
            NI32 X60Qx_1435 = len_4_sysvq0asl(text_1);
            X60Qx_1433 = (((NI32)(i_30 + 22)) <= X60Qx_1435);}
          else {
            X60Qx_1433 = NIM_FALSE;}
          if (X60Qx_1433){
            string_0_sysvq0asl X60Qtmp_48 = substr_0_sysvq0asl(text_1, i_30, ((NI32)(i_30 + 21)));
            NB8 X60Qx_1436 = eqQ_20_sysvq0asl(X60Qtmp_48, (string_0_sysvq0asl){
              .bytes_0 = 1684960766u, .more_0 = (&strlit_0_I4549886150357915156_aow7lb5cq1)}
            );
            X60Qx_43 = X60Qx_1436;
            nimStrDestroy(X60Qtmp_48);}
          else {
            X60Qx_43 = NIM_FALSE;}
          if (X60Qx_43){
            NI32 j_10 = ((NI32)(i_30 + 22));
            {
              while (NIM_TRUE){
                NB8 X60Qx_1437;
                NI32 X60Qx_1438 = len_4_sysvq0asl(text_1);
                if (j_10 < X60Qx_1438){
                  NB8 X60Qx_1439;
                  NB8 X60Qx_1440;
                  NC8 X60Qx_1441 = getQ_9_sysvq0asl(text_1, j_10);
                  if (X60Qx_1441 == (NC8)' '){
                    X60Qx_1440 = NIM_TRUE;}
                  else {
                    NC8 X60Qx_1442 = getQ_9_sysvq0asl(text_1, j_10);
                    X60Qx_1440 = (X60Qx_1442 == (NC8)'`');}
                  if (X60Qx_1440){
                    X60Qx_1439 = NIM_TRUE;}
                  else {
                    NC8 X60Qx_1443 = getQ_9_sysvq0asl(text_1, j_10);
                    X60Qx_1439 = (X60Qx_1443 == (NC8)'\'');}
                  X60Qx_1437 = X60Qx_1439;}
                else {
                  X60Qx_1437 = NIM_FALSE;}
                if (X60Qx_1437){
                  inc_1_I6wjjge_aow2h993l1((&j_10));}
                else {
                  break;}}}
            whileStmtLabel_2: ;
            {
              while (NIM_TRUE){
                NB8 X60Qx_1444;
                NI32 X60Qx_1445 = len_4_sysvq0asl(text_1);
                if (j_10 < X60Qx_1445){
                  NC8 X60Qx_1446 = getQ_9_sysvq0asl(text_1, j_10);
                  NB8 X60Qx_1447 = isIdentChar_0_aow7lb5cq1(X60Qx_1446);
                  X60Qx_1444 = X60Qx_1447;}
                else {
                  X60Qx_1444 = NIM_FALSE;}
                if (X60Qx_1444){
                  NC8 X60Qx_1448 = getQ_9_sysvq0asl(text_1, j_10);
                  add_1_sysvq0asl((&name_3), X60Qx_1448);
                  inc_1_I6wjjge_aow2h993l1((&j_10));}
                else {
                  break;}}}
            whileStmtLabel_3: ;}}
        NI32 X60Qx_1449 = len_4_sysvq0asl(name_3);
        if (0 < X60Qx_1449){
          NB8 dup_1 = NIM_FALSE;
          {
            openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_14 = toOpenArray_1_I6b60gk1_aow7lb5cq1(result_52);
            NI32 X60Qlf_15 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_1450 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_14);
                if (X60Qlf_15 < X60Qx_1450){
                  {
                    string_0_sysvq0asl* X60Qii_6 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_14, X60Qlf_15);
                    NB8 X60Qx_1451 = eqQ_20_sysvq0asl((*X60Qii_6), name_3);
                    if (X60Qx_1451){
                      dup_1 = NIM_TRUE;
                      goto forStmtLabel_4;}}
                  inc_1_I6wjjge_aow2h993l1((&X60Qlf_15));}
                else {
                  break;}}}
            whileStmtLabel_5: ;}
          forStmtLabel_4: ;
          if ((!dup_1)){
            string_0_sysvq0asl X60Qtmp_49 = name_3;
            nimStrWasMoved((&name_3));
            add_0_Ig6072n_aow7lb5cq1((&result_52), X60Qtmp_49);}}
        inc_1_I6wjjge_aow2h993l1((&i_30));
        nimStrDestroy(name_3);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(text_1);
  return result_52;
  nimStrDestroy(text_1);
  return result_52;}
X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1 hostProtoOf_0_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 texts_1, string_0_sysvq0asl name_1){
  X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1 result_54;
  eQwasmovedQ_AtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_0_aow7lb5cq1((&result_54));
  eQdestroyQ_AtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_0_aow7lb5cq1(result_54);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1467 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_54 = (X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1){
    .fld_0 = NIM_FALSE, .fld_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .fld_2 = X60Qx_1467}
  ;
  NI32 X60Qx_1468 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1469 = len_4_sysvq0asl(name_1);
  NI32 X60Qx_1470 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_225 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1468 + X60Qx_1469)) + X60Qx_1470)));
  add_2_sysvq0asl((&X60Qdesugar_225), (string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_225), name_1);
  add_2_sysvq0asl((&X60Qdesugar_225), (string_0_sysvq0asl){
    .bytes_0 = 10241u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl want_2 = X60Qdesugar_225;
  nimStrWasMoved((&X60Qdesugar_225));
  NI32 t_6 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1471 = len_3_Ixq6taz_aow7lb5cq1(texts_1);
      if (t_6 < X60Qx_1471){
        {
          string_0_sysvq0asl* X60Qx_1472 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, t_6);
          string_0_sysvq0asl src_9 = nimStrDup((*X60Qx_1472));
          NI32 at_1 = 0;
          {
            while (NIM_TRUE){
              {
                NI32 hit_0 = -1;
                NI32 i_31 = at_1;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_1473 = len_4_sysvq0asl(want_2);
                    NI32 X60Qx_1474 = len_4_sysvq0asl(src_9);
                    if (((NI32)(i_31 + X60Qx_1473)) <= X60Qx_1474){
                      NB8 X60Qx_44;
                      NC8 X60Qx_1475 = getQ_9_sysvq0asl(src_9, i_31);
                      if (X60Qx_1475 == (NC8)' '){
                        NI32 X60Qx_1476 = len_4_sysvq0asl(want_2);
                        HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1477 = ___1_Iclcqmw1_aow7lb5cq1(i_31, ((NI32)(((NI32)(i_31 + X60Qx_1476)) - 1)));
                        string_0_sysvq0asl X60Qtmp_51 = getQ_14_sysvq0asl(src_9, X60Qx_1477);
                        NB8 X60Qx_1478 = eqQ_20_sysvq0asl(X60Qtmp_51, want_2);
                        X60Qx_44 = X60Qx_1478;
                        nimStrDestroy(X60Qtmp_51);}
                      else {
                        X60Qx_44 = NIM_FALSE;}
                      if (X60Qx_44){
                        hit_0 = i_31;
                        goto whileStmtLabel_4;}
                      inc_1_I6wjjge_aow2h993l1((&i_31));}
                    else {
                      break;}}}
                whileStmtLabel_4: ;
                if (hit_0 < 0){
                  goto whileStmtLabel_2;}
                at_1 = ((NI32)(hit_0 + 1));
                NI32 ls_1 = hit_0;
                {
                  while (NIM_TRUE){
                    NB8 X60Qx_1479;
                    if (0 < ls_1){
                      NC8 X60Qx_1480 = getQ_9_sysvq0asl(src_9, ((NI32)(ls_1 - 1)));
                      X60Qx_1479 = (!(X60Qx_1480 == (NC8)'\012'));}
                    else {
                      X60Qx_1479 = NIM_FALSE;}
                    if (X60Qx_1479){
                      dec_1_I0nzoz91_aow7lb5cq1((&ls_1));}
                    else {
                      break;}}}
                whileStmtLabel_5: ;
                HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1481 = ___1_Iclcqmw1_aow7lb5cq1(ls_1, ((NI32)(hit_0 - 1)));
                string_0_sysvq0asl ret_0 = getQ_14_sysvq0asl(src_9, X60Qx_1481);
                NB8 X60Qx_1482;
                NB8 X60Qx_1483;
                NI32 X60Qx_1484 = len_4_sysvq0asl(ret_0);
                if (X60Qx_1484 == 0){
                  X60Qx_1483 = NIM_TRUE;}
                else {
                  NC8 X60Qx_1485 = getQ_9_sysvq0asl(ret_0, 0);
                  X60Qx_1483 = (X60Qx_1485 == (NC8)' ');}
                if (X60Qx_1483){
                  X60Qx_1482 = NIM_TRUE;}
                else {
                  NC8 X60Qx_1486 = getQ_9_sysvq0asl(ret_0, 0);
                  X60Qx_1482 = (X60Qx_1486 == (NC8)'\011');}
                if (X60Qx_1482){
                  nimStrDestroy(ret_0);
                  goto continueLabel_3;}
                NI32 X60Qx_1487 = len_4_sysvq0asl(want_2);
                NI32 close_0 = ((NI32)(hit_0 + X60Qx_1487));
                NI32 depth_5 = 1;
                {
                  while (NIM_TRUE){
                    NB8 X60Qx_1488;
                    NI32 X60Qx_1489 = len_4_sysvq0asl(src_9);
                    if (close_0 < X60Qx_1489){
                      X60Qx_1488 = (0 < depth_5);}
                    else {
                      X60Qx_1488 = NIM_FALSE;}
                    if (X60Qx_1488){
                      NC8 X60Qx_1490 = getQ_9_sysvq0asl(src_9, close_0);
                      if (X60Qx_1490 == (NC8)'('){
                        inc_1_I6wjjge_aow2h993l1((&depth_5));}
                      else {
                        NC8 X60Qx_1491 = getQ_9_sysvq0asl(src_9, close_0);
                        if (X60Qx_1491 == (NC8)')'){
                          dec_1_I0nzoz91_aow7lb5cq1((&depth_5));}}
                      if (0 < depth_5){
                        inc_1_I6wjjge_aow2h993l1((&close_0));}}
                    else {
                      break;}}}
                whileStmtLabel_6: ;
                NB8 X60Qx_1492;
                NI32 X60Qx_1493 = len_4_sysvq0asl(src_9);
                if (X60Qx_1493 <= ((NI32)(close_0 + 1))){
                  X60Qx_1492 = NIM_TRUE;}
                else {
                  NC8 X60Qx_1494 = getQ_9_sysvq0asl(src_9, ((NI32)(close_0 + 1)));
                  X60Qx_1492 = (!(X60Qx_1494 == (NC8)';'));}
                if (X60Qx_1492){
                  nimStrDestroy(ret_0);
                  goto continueLabel_3;}
                NI32 X60Qx_1495 = len_4_sysvq0asl(want_2);
                HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1496 = ___1_Iclcqmw1_aow7lb5cq1(((NI32)(hit_0 + X60Qx_1495)), ((NI32)(close_0 - 1)));
                string_0_sysvq0asl inner_5 = getQ_14_sysvq0asl(src_9, X60Qx_1496);
                seq_0_Ixdx2fh1_aow7lb5cq1 params_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
                NB8 X60Qx_1497;
                NB8 X60Qx_1498 = eqQ_20_sysvq0asl(inner_5, (string_0_sysvq0asl){
                  .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
                );
                if ((!X60Qx_1498)){
                  NI32 X60Qx_1499 = len_4_sysvq0asl(inner_5);
                  X60Qx_1497 = (0 < X60Qx_1499);}
                else {
                  X60Qx_1497 = NIM_FALSE;}
                if (X60Qx_1497){
                  string_0_sysvq0asl cur_2 = (string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  ;
                  NI32 k_6 = 0;
                  {
                    while (NIM_TRUE){
                      NI32 X60Qx_1500 = len_4_sysvq0asl(inner_5);
                      if (k_6 <= X60Qx_1500){
                        NB8 X60Qx_1501;
                        NI32 X60Qx_1502 = len_4_sysvq0asl(inner_5);
                        if (k_6 == X60Qx_1502){
                          X60Qx_1501 = NIM_TRUE;}
                        else {
                          NC8 X60Qx_1503 = getQ_9_sysvq0asl(inner_5, k_6);
                          X60Qx_1501 = (X60Qx_1503 == (NC8)',');}
                        if (X60Qx_1501){
                          string_0_sysvq0asl e_5 = cur_2;
                          nimStrWasMoved((&cur_2));
                          {
                            while (NIM_TRUE){
                              NB8 X60Qx_1504;
                              NI32 X60Qx_1505 = len_4_sysvq0asl(e_5);
                              if (0 < X60Qx_1505){
                                NC8 X60Qx_1506 = getQ_9_sysvq0asl(e_5, 0);
                                X60Qx_1504 = (X60Qx_1506 == (NC8)' ');}
                              else {
                                X60Qx_1504 = NIM_FALSE;}
                              if (X60Qx_1504){
                                NI32 X60Qx_1507 = len_4_sysvq0asl(e_5);
                                HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1508 = ___1_Iclcqmw1_aow7lb5cq1(1, ((NI32)(X60Qx_1507 - 1)));
                                string_0_sysvq0asl X60Qlhs_52 = getQ_14_sysvq0asl(e_5, X60Qx_1508);
                                nimStrDestroy(e_5);
                                e_5 = X60Qlhs_52;}
                              else {
                                break;}}}
                          whileStmtLabel_8: ;
                          NI32 X60Qx_1509 = len_4_sysvq0asl(e_5);
                          NI32 sp_0 = ((NI32)(X60Qx_1509 - 1));
                          {
                            while (NIM_TRUE){
                              NB8 X60Qx_1510;
                              if (0 <= sp_0){
                                NC8 X60Qx_1511 = getQ_9_sysvq0asl(e_5, sp_0);
                                X60Qx_1510 = (!(X60Qx_1511 == (NC8)' '));}
                              else {
                                X60Qx_1510 = NIM_FALSE;}
                              if (X60Qx_1510){
                                dec_1_I0nzoz91_aow7lb5cq1((&sp_0));}
                              else {
                                break;}}}
                          whileStmtLabel_9: ;
                          string_0_sysvq0asl X60Qx_12;
                          nimStrWasMoved((&X60Qx_12));
                          if (0 < sp_0){
                            nimStrDestroy(X60Qx_12);
                            HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1512 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(sp_0 - 1)));
                            string_0_sysvq0asl X60Qx_1513 = getQ_14_sysvq0asl(e_5, X60Qx_1512);
                            X60Qx_12 = X60Qx_1513;}
                          else {
                            nimStrDestroy(X60Qx_12);
                            X60Qx_12 = e_5;
                            nimStrWasMoved((&e_5));}
                          string_0_sysvq0asl X60Qtmp_53 = X60Qx_12;
                          nimStrWasMoved((&X60Qx_12));
                          add_0_Ig6072n_aow7lb5cq1((&params_0), X60Qtmp_53);
                          nimStrDestroy(cur_2);
                          cur_2 = (string_0_sysvq0asl){
                            .bytes_0 = 0u, .more_0 = NIM_NIL}
                          ;
                          nimStrDestroy(X60Qx_12);
                          nimStrDestroy(e_5);}
                        else {
                          NC8 X60Qx_1514 = getQ_9_sysvq0asl(inner_5, k_6);
                          add_1_sysvq0asl((&cur_2), X60Qx_1514);}
                        inc_1_I6wjjge_aow2h993l1((&k_6));}
                      else {
                        break;}}}
                  whileStmtLabel_7: ;
                  nimStrDestroy(cur_2);}
                string_0_sysvq0asl X60Qtmp_54 = ret_0;
                nimStrWasMoved((&ret_0));
                seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_55 = params_0;
                eQwasMoved_1_I5vdnla_aow7lb5cq1((&params_0));
                result_54 = (X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1){
                  .fld_0 = NIM_TRUE, .fld_1 = X60Qtmp_54, .fld_2 = X60Qtmp_55}
                ;
                eQdestroy_1_Ivioh0a_aow7lb5cq1(params_0);
                nimStrDestroy(inner_5);
                nimStrDestroy(ret_0);
                nimStrDestroy(src_9);
                nimStrDestroy(want_2);
                nimStrDestroy(X60Qdesugar_225);
                return result_54;
                eQdestroy_1_Ivioh0a_aow7lb5cq1(params_0);
                nimStrDestroy(inner_5);
                nimStrDestroy(ret_0);}
              continueLabel_3: ;}}
          whileStmtLabel_2: ;
          inc_1_I6wjjge_aow2h993l1((&t_6));
          nimStrDestroy(src_9);}
        continueLabel_1: ;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(want_2);
  nimStrDestroy(X60Qdesugar_225);
  return result_54;
  nimStrDestroy(want_2);
  nimStrDestroy(X60Qdesugar_225);
  return result_54;}
NB8 forwardableScalar_0_aow7lb5cq1(string_0_sysvq0asl ty_0){
  NB8 result_55;
  NB8 X60Qx_1515;
  NB8 X60Qx_1516;
  NB8 X60Qx_1517 = eqQ_20_sysvq0asl(ty_0, (string_0_sysvq0asl){
    .bytes_0 = 910774014u, .more_0 = (&strlit_0_I6323980750145937682_aow7lb5cq1)}
  );
  if (X60Qx_1517){
    X60Qx_1516 = NIM_TRUE;}
  else {
    NB8 X60Qx_1518 = eqQ_20_sysvq0asl(ty_0, (string_0_sysvq0asl){
      .bytes_0 = 910577406u, .more_0 = (&strlit_0_I11372099257973387468_aow7lb5cq1)}
    );
    X60Qx_1516 = X60Qx_1518;}
  if (X60Qx_1516){
    X60Qx_1515 = NIM_TRUE;}
  else {
    NB8 X60Qx_1519 = eqQ_20_sysvq0asl(ty_0, (string_0_sysvq0asl){
      .bytes_0 = 943869443u, .more_0 = NIM_NIL}
    );
    X60Qx_1515 = X60Qx_1519;}
  result_55 = X60Qx_1515;
  return result_55;}
string_0_sysvq0asl stringPreamble_0_aow7lb5cq1(string_0_sysvq0asl strT_3, string_0_sysvq0asl longT_3){
  string_0_sysvq0asl result_57;
  nimStrWasMoved((&result_57));
  NI32 X60Qx_1545 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I14550266631180595513_aow7lb5cq1)}
  );
  NI32 X60Qx_1546 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
  );
  NI32 X60Qx_1547 = len_4_sysvq0asl(longT_3);
  NI32 X60Qx_1548 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 544940286u, .more_0 = (&strlit_0_I17287368031653860530_aow7lb5cq1)}
  );
  NI32 X60Qx_1549 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 943935230u, .more_0 = (&strlit_0_I10892961668711831093_aow7lb5cq1)}
  );
  NI32 X60Qx_1550 = len_4_sysvq0asl(longT_3);
  NI32 X60Qx_1551 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 670466u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1552 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
  );
  NI32 X60Qx_1553 = len_4_sysvq0asl(strT_3);
  NI32 X60Qx_1554 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 544940286u, .more_0 = (&strlit_0_I9899413235396384892_aow7lb5cq1)}
  );
  NI32 X60Qx_1555 = len_4_sysvq0asl(longT_3);
  NI32 X60Qx_1556 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1830824702u, .more_0 = (&strlit_0_I8710817496071376231_aow7lb5cq1)}
  );
  NI32 X60Qx_1557 = len_4_sysvq0asl(strT_3);
  NI32 X60Qx_1558 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 670466u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1559 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1701061630u, .more_0 = (&strlit_0_I4134269184822004129_aow7lb5cq1)}
  );
  NI32 X60Qx_1560 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I8765082779704797141_aow7lb5cq1)}
  );
  NI32 X60Qx_1561 = len_4_sysvq0asl(strT_3);
  NI32 X60Qx_1562 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I15451086062892265134_aow7lb5cq1)}
  );
  NI32 X60Qx_1563 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1965039870u, .more_0 = (&strlit_0_I8418239454781733599_aow7lb5cq1)}
  );
  NI32 X60Qx_1564 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I18133447078079322724_aow7lb5cq1)}
  );
  NI32 X60Qx_1565 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I13047606667692590573_aow7lb5cq1)}
  );
  NI32 X60Qx_1566 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I9945958517074851424_aow7lb5cq1)}
  );
  NI32 X60Qx_1567 = len_4_sysvq0asl(strT_3);
  NI32 X60Qx_1568 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I15451086062892265134_aow7lb5cq1)}
  );
  NI32 X60Qx_1569 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1965039870u, .more_0 = (&strlit_0_I8418239454781733599_aow7lb5cq1)}
  );
  NI32 X60Qx_1570 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15880987555885680275_aow7lb5cq1)}
  );
  NI32 X60Qx_1571 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I7716657792389848635_aow7lb5cq1)}
  );
  NI32 X60Qx_1572 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I4474515410797177574_aow7lb5cq1)}
  );
  NI32 X60Qx_1573 = len_4_sysvq0asl(strT_3);
  NI32 X60Qx_1574 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1868636414u, .more_0 = (&strlit_0_I8668648937944324958_aow7lb5cq1)}
  );
  NI32 X60Qx_1575 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1576 = len_4_sysvq0asl(strT_3);
  NI32 X60Qx_1577 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1970217214u, .more_0 = (&strlit_0_I12082599546615751634_aow7lb5cq1)}
  );
  NI32 X60Qx_1578 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I2988859641805316168_aow7lb5cq1)}
  );
  NI32 X60Qx_1579 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I13388832424567330741_aow7lb5cq1)}
  );
  NI32 X60Qx_1580 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I364500875769014308_aow7lb5cq1)}
  );
  NI32 X60Qx_1581 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16864298447618496683_aow7lb5cq1)}
  );
  NI32 X60Qx_1582 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I9346609203048705053_aow7lb5cq1)}
  );
  NI32 X60Qx_1583 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2099257598u, .more_0 = (&strlit_0_I6468377022308900005_aow7lb5cq1)}
  );
  NI32 X60Qx_1584 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1585 = len_4_sysvq0asl(longT_3);
  NI32 X60Qx_1586 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1881156350u, .more_0 = (&strlit_0_I7232983627022515607_aow7lb5cq1)}
  );
  NI32 X60Qx_1587 = len_4_sysvq0asl(longT_3);
  NI32 X60Qx_1588 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1831414526u, .more_0 = (&strlit_0_I18203647199095237467_aow7lb5cq1)}
  );
  NI32 X60Qx_1589 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I7640768363785909614_aow7lb5cq1)}
  );
  NI32 X60Qx_1590 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1881153790u, .more_0 = (&strlit_0_I12091536289913666620_aow7lb5cq1)}
  );
  NI32 X60Qx_1591 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I11749156186693331548_aow7lb5cq1)}
  );
  NI32 X60Qx_1592 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I2907747001831285170_aow7lb5cq1)}
  );
  NI32 X60Qx_1593 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I15874091423332818451_aow7lb5cq1)}
  );
  NI32 X60Qx_1594 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10757245804552490900_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_227 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1545 + X60Qx_1546)) + X60Qx_1547)) + X60Qx_1548)) + X60Qx_1549)) + X60Qx_1550)) + X60Qx_1551)) + X60Qx_1552)) + X60Qx_1553)) + X60Qx_1554)) + X60Qx_1555)) + X60Qx_1556)) + X60Qx_1557)) + X60Qx_1558)) + X60Qx_1559)) + X60Qx_1560)) + X60Qx_1561)) + X60Qx_1562)) + X60Qx_1563)) + X60Qx_1564)) + X60Qx_1565)) + X60Qx_1566)) + X60Qx_1567)) + X60Qx_1568)) + X60Qx_1569)) + X60Qx_1570)) + X60Qx_1571)) + X60Qx_1572)) + X60Qx_1573)) + X60Qx_1574)) + X60Qx_1575)) + X60Qx_1576)) + X60Qx_1577)) + X60Qx_1578)) + X60Qx_1579)) + X60Qx_1580)) + X60Qx_1581)) + X60Qx_1582)) + X60Qx_1583)) + X60Qx_1584)) + X60Qx_1585)) + X60Qx_1586)) + X60Qx_1587)) + X60Qx_1588)) + X60Qx_1589)) + X60Qx_1590)) + X60Qx_1591)) + X60Qx_1592)) + X60Qx_1593)) + X60Qx_1594)));
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I14550266631180595513_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), longT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 544940286u, .more_0 = (&strlit_0_I17287368031653860530_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 943935230u, .more_0 = (&strlit_0_I10892961668711831093_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), longT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 670466u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), strT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 544940286u, .more_0 = (&strlit_0_I9899413235396384892_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), longT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1830824702u, .more_0 = (&strlit_0_I8710817496071376231_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), strT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 670466u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1701061630u, .more_0 = (&strlit_0_I4134269184822004129_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I8765082779704797141_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), strT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I15451086062892265134_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1965039870u, .more_0 = (&strlit_0_I8418239454781733599_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I18133447078079322724_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I13047606667692590573_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I9945958517074851424_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), strT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I15451086062892265134_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1965039870u, .more_0 = (&strlit_0_I8418239454781733599_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15880987555885680275_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I7716657792389848635_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I4474515410797177574_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), strT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1868636414u, .more_0 = (&strlit_0_I8668648937944324958_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), strT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1970217214u, .more_0 = (&strlit_0_I12082599546615751634_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I2988859641805316168_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I13388832424567330741_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I364500875769014308_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16864298447618496683_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I9346609203048705053_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 2099257598u, .more_0 = (&strlit_0_I6468377022308900005_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), longT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1881156350u, .more_0 = (&strlit_0_I7232983627022515607_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), longT_3);
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1831414526u, .more_0 = (&strlit_0_I18203647199095237467_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I7640768363785909614_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1881153790u, .more_0 = (&strlit_0_I12091536289913666620_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I11749156186693331548_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I2907747001831285170_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I15874091423332818451_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_227), (string_0_sysvq0asl){
    .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10757245804552490900_aow7lb5cq1)}
  );
  nimStrDestroy(result_57);
  result_57 = X60Qdesugar_227;
  nimStrWasMoved((&X60Qdesugar_227));
  nimStrDestroy(X60Qdesugar_227);
  return result_57;
  nimStrDestroy(X60Qdesugar_227);
  return result_57;}
NB8 writeHostStubs_0_aow7lb5cq1(string_0_sysvq0asl path_2, seq_0_Ixdx2fh1_aow7lb5cq1 names_1, seq_0_Ixdx2fh1_aow7lb5cq1 texts_3, seq_0_Ixdx2fh1_aow7lb5cq1* forwarded_0){
  NB8 result_58;
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*forwarded_0));
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1595 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  (*forwarded_0) = X60Qx_1595;
  NI32 X60Qx_1596 = len_3_Ixq6taz_aow7lb5cq1(names_1);
  if (X60Qx_1596 == 0){
    return NIM_FALSE;}
  string_0_sysvq0asl strT_4 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl longT_4 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 ti_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_1597;
      NI32 X60Qx_1598 = len_3_Ixq6taz_aow7lb5cq1(texts_3);
      if (ti_0 < X60Qx_1598){
        NB8 X60Qx_1599;
        NI32 X60Qx_1600 = len_4_sysvq0asl(strT_4);
        if (X60Qx_1600 == 0){
          X60Qx_1599 = NIM_TRUE;}
        else {
          NI32 X60Qx_1601 = len_4_sysvq0asl(longT_4);
          X60Qx_1599 = (X60Qx_1601 == 0);}
        X60Qx_1597 = X60Qx_1599;}
      else {
        X60Qx_1597 = NIM_FALSE;}
      if (X60Qx_1597){
        NI32 X60Qx_1602 = len_4_sysvq0asl(strT_4);
        if (X60Qx_1602 == 0){
          nimStrDestroy(strT_4);
          string_0_sysvq0asl* X60Qx_1603 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_3, ti_0);
          string_0_sysvq0asl X60Qx_1604 = typeNameAfter_0_aow7lb5cq1((*X60Qx_1603), (string_0_sysvq0asl){
            .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I17605077022815850042_aow7lb5cq1)}
          );
          strT_4 = X60Qx_1604;}
        NI32 X60Qx_1605 = len_4_sysvq0asl(longT_4);
        if (X60Qx_1605 == 0){
          nimStrDestroy(longT_4);
          string_0_sysvq0asl* X60Qx_1606 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_3, ti_0);
          string_0_sysvq0asl X60Qx_1607 = typeNameAfter_0_aow7lb5cq1((*X60Qx_1606), (string_0_sysvq0asl){
            .bytes_0 = 1852787966u, .more_0 = (&strlit_0_I15230512448378417494_aow7lb5cq1)}
          );
          longT_4 = X60Qx_1607;}
        inc_1_I6wjjge_aow2h993l1((&ti_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_1608;
  NI32 X60Qx_1609 = len_4_sysvq0asl(strT_4);
  if (0 < X60Qx_1609){
    NI32 X60Qx_1610 = len_4_sysvq0asl(longT_4);
    X60Qx_1608 = (0 < X60Qx_1610);}
  else {
    X60Qx_1608 = NIM_FALSE;}
  NB8 strOk_0 = X60Qx_1608;
  NI32 X60Qx_1611 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 539635710u, .more_0 = (&strlit_0_I5637264954227160523_aow7lb5cq1)}
  );
  NI32 X60Qx_1612 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17177110499767132265_aow7lb5cq1)}
  );
  NI32 X60Qx_1613 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5674099961252277032_aow7lb5cq1)}
  );
  NI32 X60Qx_1614 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17380335403814435655_aow7lb5cq1)}
  );
  NI32 X60Qx_1615 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1852384254u, .more_0 = (&strlit_0_I4507293232177819398_aow7lb5cq1)}
  );
  NI32 X60Qx_1616 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1701061630u, .more_0 = (&strlit_0_I5192493655371327513_aow7lb5cq1)}
  );
  NI32 X60Qx_1617 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13866842447811724506_aow7lb5cq1)}
  );
  NI32 X60Qx_1618 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I7968170841241575315_aow7lb5cq1)}
  );
  NI32 X60Qx_1619 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I1573076124429889532_aow7lb5cq1)}
  );
  NI32 X60Qx_1620 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I9225250353289554045_aow7lb5cq1)}
  );
  NI32 X60Qx_1621 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1718166526u, .more_0 = (&strlit_0_I8164311879278760128_aow7lb5cq1)}
  );
  NI32 X60Qx_1622 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I14087883000254015324_aow7lb5cq1)}
  );
  NI32 X60Qx_1623 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I9983178280678633983_aow7lb5cq1)}
  );
  NI32 X60Qx_1624 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1713381630u, .more_0 = (&strlit_0_I10092270157963981938_aow7lb5cq1)}
  );
  NI32 X60Qx_1625 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11609677804622622241_aow7lb5cq1)}
  );
  NI32 X60Qx_1626 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I1178222426333560473_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_228 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1611 + X60Qx_1612)) + X60Qx_1613)) + X60Qx_1614)) + X60Qx_1615)) + X60Qx_1616)) + X60Qx_1617)) + X60Qx_1618)) + X60Qx_1619)) + X60Qx_1620)) + X60Qx_1621)) + X60Qx_1622)) + X60Qx_1623)) + X60Qx_1624)) + X60Qx_1625)) + X60Qx_1626)));
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 539635710u, .more_0 = (&strlit_0_I5637264954227160523_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17177110499767132265_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5674099961252277032_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17380335403814435655_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1852384254u, .more_0 = (&strlit_0_I4507293232177819398_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1701061630u, .more_0 = (&strlit_0_I5192493655371327513_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13866842447811724506_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I7968170841241575315_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I1573076124429889532_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I9225250353289554045_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1718166526u, .more_0 = (&strlit_0_I8164311879278760128_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I14087883000254015324_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I9983178280678633983_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1713381630u, .more_0 = (&strlit_0_I10092270157963981938_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11609677804622622241_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_228), (string_0_sysvq0asl){
    .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I1178222426333560473_aow7lb5cq1)}
  );
  string_0_sysvq0asl c_4 = X60Qdesugar_228;
  nimStrWasMoved((&X60Qdesugar_228));
  if (strOk_0){
    string_0_sysvq0asl X60Qtmp_57 = stringPreamble_0_aow7lb5cq1(strT_4, longT_4);
    add_2_sysvq0asl((&c_4), X60Qtmp_57);
    nimStrDestroy(X60Qtmp_57);}
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_18 = toOpenArray_1_I6b60gk1_aow7lb5cq1(names_1);
    NI32 X60Qlf_19 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1627 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_18);
        if (X60Qlf_19 < X60Qx_1627){
          {
            {
              string_0_sysvq0asl* X60Qii_4 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_18, X60Qlf_19);
              X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1 X60Qii_5 = hostProtoOf_0_aow7lb5cq1(texts_3, (*X60Qii_4));
              NB8 X60Qx_1628;
              if (X60Qii_5.fld_0){
                NB8 X60Qx_1629;
                NB8 X60Qx_1630;
                NB8 X60Qx_1631 = eqQ_20_sysvq0asl(X60Qii_5.fld_1, (string_0_sysvq0asl){
                  .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
                );
                if (X60Qx_1631){
                  X60Qx_1630 = NIM_TRUE;}
                else {
                  NB8 X60Qx_1632 = forwardableScalar_0_aow7lb5cq1(X60Qii_5.fld_1);
                  X60Qx_1630 = X60Qx_1632;}
                if (X60Qx_1630){
                  X60Qx_1629 = NIM_TRUE;}
                else {
                  NB8 X60Qx_1633;
                  if (strOk_0){
                    NB8 X60Qx_1634 = eqQ_20_sysvq0asl(X60Qii_5.fld_1, strT_4);
                    X60Qx_1633 = X60Qx_1634;}
                  else {
                    X60Qx_1633 = NIM_FALSE;}
                  X60Qx_1629 = X60Qx_1633;}
                X60Qx_1628 = X60Qx_1629;}
              else {
                X60Qx_1628 = NIM_FALSE;}
              NB8 X60Qii_6 = X60Qx_1628;
              if (X60Qii_6){
                {
                  openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_20 = toOpenArray_1_I6b60gk1_aow7lb5cq1(X60Qii_5.fld_2);
                  NI32 X60Qlf_21 = 0;
                  {
                    while (NIM_TRUE){
                      NI32 X60Qx_1635 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_20);
                      if (X60Qlf_21 < X60Qx_1635){
                        {
                          string_0_sysvq0asl* X60Qii_9 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_20, X60Qlf_21);
                          NB8 X60Qx_1636;
                          NB8 X60Qx_1637 = forwardableScalar_0_aow7lb5cq1((*X60Qii_9));
                          if ((!X60Qx_1637)){
                            NB8 X60Qx_1638;
                            if (strOk_0){
                              NB8 X60Qx_1639 = eqQ_20_sysvq0asl((*X60Qii_9), strT_4);
                              X60Qx_1638 = X60Qx_1639;}
                            else {
                              X60Qx_1638 = NIM_FALSE;}
                            X60Qx_1636 = (!X60Qx_1638);}
                          else {
                            X60Qx_1636 = NIM_FALSE;}
                          if (X60Qx_1636){
                            X60Qii_6 = NIM_FALSE;}}
                        inc_1_I6wjjge_aow2h993l1((&X60Qlf_21));}
                      else {
                        break;}}}
                  whileStmtLabel_8: ;}
                forStmtLabel_7: ;}
              if ((!X60Qii_6)){
                string_0_sysvq0asl X60Qdesugar_229 = nimStrDup((*X60Qii_4));
                NI32 X60Qx_1640 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I5505906462732536404_aow7lb5cq1)}
                );
                NI32 X60Qx_1641 = len_4_sysvq0asl(X60Qdesugar_229);
                NI32 X60Qx_1642 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I15685635656363446690_aow7lb5cq1)}
                );
                string_0_sysvq0asl X60Qdesugar_230 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1640 + X60Qx_1641)) + X60Qx_1642)));
                add_2_sysvq0asl((&X60Qdesugar_230), (string_0_sysvq0asl){
                  .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I5505906462732536404_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_230), X60Qdesugar_229);
                add_2_sysvq0asl((&X60Qdesugar_230), (string_0_sysvq0asl){
                  .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I15685635656363446690_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&c_4), X60Qdesugar_230);
                string_0_sysvq0asl X60Qdesugar_231 = nimStrDup((*X60Qii_4));
                NI32 X60Qx_1643 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I5505906462732536404_aow7lb5cq1)}
                );
                NI32 X60Qx_1644 = len_4_sysvq0asl(X60Qdesugar_231);
                NI32 X60Qx_1645 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I8791916773570277091_aow7lb5cq1)}
                );
                string_0_sysvq0asl X60Qdesugar_232 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1643 + X60Qx_1644)) + X60Qx_1645)));
                add_2_sysvq0asl((&X60Qdesugar_232), (string_0_sysvq0asl){
                  .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I5505906462732536404_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_232), X60Qdesugar_231);
                add_2_sysvq0asl((&X60Qdesugar_232), (string_0_sysvq0asl){
                  .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I8791916773570277091_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&c_4), X60Qdesugar_232);
                string_0_sysvq0asl X60Qdesugar_233 = nimStrDup((*X60Qii_4));
                NI32 X60Qx_1646 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1713381630u, .more_0 = (&strlit_0_I11203801610929465702_aow7lb5cq1)}
                );
                NI32 X60Qx_1647 = len_4_sysvq0asl(X60Qdesugar_233);
                NI32 X60Qx_1648 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 539764734u, .more_0 = (&strlit_0_I10981136843517635042_aow7lb5cq1)}
                );
                string_0_sysvq0asl X60Qdesugar_234 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1646 + X60Qx_1647)) + X60Qx_1648)));
                add_2_sysvq0asl((&X60Qdesugar_234), (string_0_sysvq0asl){
                  .bytes_0 = 1713381630u, .more_0 = (&strlit_0_I11203801610929465702_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_234), X60Qdesugar_233);
                add_2_sysvq0asl((&X60Qdesugar_234), (string_0_sysvq0asl){
                  .bytes_0 = 539764734u, .more_0 = (&strlit_0_I10981136843517635042_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&c_4), X60Qdesugar_234);
                string_0_sysvq0asl X60Qtmp_58 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2252264930722086145_aow7lb5cq1)}
                , (string_0_sysvq0asl){
                  .bytes_0 = 1869752574u, .more_0 = (&strlit_0_I2450606786241534151_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&c_4), X60Qtmp_58);
                add_2_sysvq0asl((&c_4), (string_0_sysvq0asl){
                  .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I1178222426333560473_aow7lb5cq1)}
                );
                nimStrDestroy(X60Qtmp_58);
                nimStrDestroy(X60Qdesugar_234);
                nimStrDestroy(X60Qdesugar_233);
                nimStrDestroy(X60Qdesugar_232);
                nimStrDestroy(X60Qdesugar_231);
                nimStrDestroy(X60Qdesugar_230);
                nimStrDestroy(X60Qdesugar_229);
                eQdestroyQ_AtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_0_aow7lb5cq1(X60Qii_5);
                goto continueLabel_3;
                nimStrDestroy(X60Qtmp_58);
                nimStrDestroy(X60Qdesugar_234);
                nimStrDestroy(X60Qdesugar_233);
                nimStrDestroy(X60Qdesugar_232);
                nimStrDestroy(X60Qdesugar_231);
                nimStrDestroy(X60Qdesugar_230);
                nimStrDestroy(X60Qdesugar_229);}
              string_0_sysvq0asl X60Qx_1649 = nimStrDup((*X60Qii_4));
              add_0_Ig6072n_aow7lb5cq1(forwarded_0, X60Qx_1649);
              seq_0_Ift2sne_aow7lb5cq1 X60Qii_10 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
              string_0_sysvq0asl X60Qdesugar_235 = nimStrDup((*X60Qii_4));
              NI32 X60Qx_1650 = len_4_sysvq0asl(X60Qii_5.fld_1);
              NI32 X60Qx_1651 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 8193u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1652 = len_4_sysvq0asl(X60Qdesugar_235);
              NI32 X60Qx_1653 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 10241u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_236 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1650 + X60Qx_1651)) + X60Qx_1652)) + X60Qx_1653)));
              add_2_sysvq0asl((&X60Qdesugar_236), X60Qii_5.fld_1);
              add_2_sysvq0asl((&X60Qdesugar_236), (string_0_sysvq0asl){
                .bytes_0 = 8193u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_236), X60Qdesugar_235);
              add_2_sysvq0asl((&X60Qdesugar_236), (string_0_sysvq0asl){
                .bytes_0 = 10241u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qii_11 = X60Qdesugar_236;
              nimStrWasMoved((&X60Qdesugar_236));
              string_0_sysvq0asl X60Qii_12 = (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              ;
              NI32 X60Qii_13 = len_3_Ixq6taz_aow7lb5cq1(X60Qii_5.fld_2);
              NI32 X60Qx_13;
              if (0 < X60Qii_13){
                X60Qx_13 = X60Qii_13;}
              else {
                X60Qx_13 = 1;}
              string_0_sysvq0asl X60Qdesugar_237 = dollarQ_2_sysvq0asl(X60Qx_13);
              NI32 X60Qx_1654 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1092624638u, .more_0 = (&strlit_0_I14032647850895285638_aow7lb5cq1)}
              );
              NI32 X60Qx_1655 = len_4_sysvq0asl(X60Qdesugar_237);
              NI32 X60Qx_1656 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 171662595u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_238 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1654 + X60Qx_1655)) + X60Qx_1656)));
              add_2_sysvq0asl((&X60Qdesugar_238), (string_0_sysvq0asl){
                .bytes_0 = 1092624638u, .more_0 = (&strlit_0_I14032647850895285638_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_238), X60Qdesugar_237);
              add_2_sysvq0asl((&X60Qdesugar_238), (string_0_sysvq0asl){
                .bytes_0 = 171662595u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_238);
              NI32 X60Qii_14 = 0;
              while (X60Qii_14 < X60Qii_13){
                string_0_sysvq0asl* X60Qx_1657 = getQ_7_Ir6d0tw_aow7lb5cq1(X60Qii_5.fld_2, X60Qii_14);
                string_0_sysvq0asl X60Qii_15 = nimStrDup((*X60Qx_1657));
                if (0 < X60Qii_14){
                  add_2_sysvq0asl((&X60Qii_11), (string_0_sysvq0asl){
                    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                  );}
                string_0_sysvq0asl X60Qdesugar_239 = dollarQ_2_sysvq0asl(X60Qii_14);
                NI32 X60Qx_1658 = len_4_sysvq0asl(X60Qii_15);
                NI32 X60Qx_1659 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 6365186u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_1660 = len_4_sysvq0asl(X60Qdesugar_239);
                string_0_sysvq0asl X60Qdesugar_240 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1658 + X60Qx_1659)) + X60Qx_1660)));
                add_2_sysvq0asl((&X60Qdesugar_240), X60Qii_15);
                add_2_sysvq0asl((&X60Qdesugar_240), (string_0_sysvq0asl){
                  .bytes_0 = 6365186u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_240), X60Qdesugar_239);
                add_2_sysvq0asl((&X60Qii_11), X60Qdesugar_240);
                string_0_sysvq0asl X60Qdesugar_241 = dollarQ_2_sysvq0asl(X60Qii_14);
                NI32 X60Qx_1661 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1534484739u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_1662 = len_4_sysvq0asl(X60Qdesugar_241);
                NI32 X60Qx_1663 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 23809u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_242 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1661 + X60Qx_1662)) + X60Qx_1663)));
                add_2_sysvq0asl((&X60Qdesugar_242), (string_0_sysvq0asl){
                  .bytes_0 = 1534484739u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_242), X60Qdesugar_241);
                add_2_sysvq0asl((&X60Qdesugar_242), (string_0_sysvq0asl){
                  .bytes_0 = 23809u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qii_16 = X60Qdesugar_242;
                nimStrWasMoved((&X60Qdesugar_242));
                NI32 X60Qx_1664 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_1665 = len_4_sysvq0asl(X60Qii_16);
                NI32 X60Qx_1666 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1852387070u, .more_0 = (&strlit_0_I18306619155145694585_aow7lb5cq1)}
                );
                NI32 X60Qx_1667 = len_4_sysvq0asl(X60Qii_16);
                NI32 X60Qx_1668 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1970155262u, .more_0 = (&strlit_0_I829567100987362370_aow7lb5cq1)}
                );
                NI32 X60Qx_1669 = len_4_sysvq0asl(X60Qii_16);
                NI32 X60Qx_1670 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1702113022u, .more_0 = (&strlit_0_I470006872129730788_aow7lb5cq1)}
                );
                string_0_sysvq0asl X60Qdesugar_243 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1664 + X60Qx_1665)) + X60Qx_1666)) + X60Qx_1667)) + X60Qx_1668)) + X60Qx_1669)) + X60Qx_1670)));
                add_2_sysvq0asl((&X60Qdesugar_243), (string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_243), X60Qii_16);
                add_2_sysvq0asl((&X60Qdesugar_243), (string_0_sysvq0asl){
                  .bytes_0 = 1852387070u, .more_0 = (&strlit_0_I18306619155145694585_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_243), X60Qii_16);
                add_2_sysvq0asl((&X60Qdesugar_243), (string_0_sysvq0asl){
                  .bytes_0 = 1970155262u, .more_0 = (&strlit_0_I829567100987362370_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_243), X60Qii_16);
                add_2_sysvq0asl((&X60Qdesugar_243), (string_0_sysvq0asl){
                  .bytes_0 = 1702113022u, .more_0 = (&strlit_0_I470006872129730788_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_243);
                NB8 X60Qx_1671 = eqQ_20_sysvq0asl(X60Qii_15, (string_0_sysvq0asl){
                  .bytes_0 = 910577406u, .more_0 = (&strlit_0_I11372099257973387468_aow7lb5cq1)}
                );
                if (X60Qx_1671){
                  string_0_sysvq0asl X60Qdesugar_244 = dollarQ_2_sysvq0asl(X60Qii_14);
                  NI32 X60Qx_1672 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                  );
                  NI32 X60Qx_1673 = len_4_sysvq0asl(X60Qii_16);
                  NI32 X60Qx_1674 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1768632062u, .more_0 = (&strlit_0_I2417009231442816373_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1675 = len_4_sysvq0asl(X60Qii_16);
                  NI32 X60Qx_1676 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1970155262u, .more_0 = (&strlit_0_I16152225727888320114_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1677 = len_4_sysvq0asl(X60Qdesugar_244);
                  NI32 X60Qx_1678 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_245 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1672 + X60Qx_1673)) + X60Qx_1674)) + X60Qx_1675)) + X60Qx_1676)) + X60Qx_1677)) + X60Qx_1678)));
                  add_2_sysvq0asl((&X60Qdesugar_245), (string_0_sysvq0asl){
                    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_245), X60Qii_16);
                  add_2_sysvq0asl((&X60Qdesugar_245), (string_0_sysvq0asl){
                    .bytes_0 = 1768632062u, .more_0 = (&strlit_0_I2417009231442816373_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_245), X60Qii_16);
                  add_2_sysvq0asl((&X60Qdesugar_245), (string_0_sysvq0asl){
                    .bytes_0 = 1970155262u, .more_0 = (&strlit_0_I16152225727888320114_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_245), X60Qdesugar_244);
                  add_2_sysvq0asl((&X60Qdesugar_245), (string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_245);
                  nimStrDestroy(X60Qdesugar_245);
                  nimStrDestroy(X60Qdesugar_244);}
                else {
                  NB8 X60Qx_1679 = eqQ_20_sysvq0asl(X60Qii_15, (string_0_sysvq0asl){
                    .bytes_0 = 943869443u, .more_0 = NIM_NIL}
                  );
                  if (X60Qx_1679){
                    string_0_sysvq0asl X60Qdesugar_246 = dollarQ_2_sysvq0asl(X60Qii_14);
                    NI32 X60Qx_1680 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                    );
                    NI32 X60Qx_1681 = len_4_sysvq0asl(X60Qii_16);
                    NI32 X60Qx_1682 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1768632062u, .more_0 = (&strlit_0_I3027407436919667588_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1683 = len_4_sysvq0asl(X60Qii_16);
                    NI32 X60Qx_1684 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1852387070u, .more_0 = (&strlit_0_I11723720343194599649_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1685 = len_4_sysvq0asl(X60Qdesugar_246);
                    NI32 X60Qx_1686 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 541008126u, .more_0 = (&strlit_0_I4433735051247999596_aow7lb5cq1)}
                    );
                    string_0_sysvq0asl X60Qdesugar_247 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1680 + X60Qx_1681)) + X60Qx_1682)) + X60Qx_1683)) + X60Qx_1684)) + X60Qx_1685)) + X60Qx_1686)));
                    add_2_sysvq0asl((&X60Qdesugar_247), (string_0_sysvq0asl){
                      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_247), X60Qii_16);
                    add_2_sysvq0asl((&X60Qdesugar_247), (string_0_sysvq0asl){
                      .bytes_0 = 1768632062u, .more_0 = (&strlit_0_I3027407436919667588_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_247), X60Qii_16);
                    add_2_sysvq0asl((&X60Qdesugar_247), (string_0_sysvq0asl){
                      .bytes_0 = 1852387070u, .more_0 = (&strlit_0_I11723720343194599649_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_247), X60Qdesugar_246);
                    add_2_sysvq0asl((&X60Qdesugar_247), (string_0_sysvq0asl){
                      .bytes_0 = 541008126u, .more_0 = (&strlit_0_I4433735051247999596_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_247);
                    nimStrDestroy(X60Qdesugar_247);
                    nimStrDestroy(X60Qdesugar_246);}
                  else {
                    NB8 X60Qx_1687;
                    if (strOk_0){
                      NB8 X60Qx_1688 = eqQ_20_sysvq0asl(X60Qii_15, strT_4);
                      X60Qx_1687 = X60Qx_1688;}
                    else {
                      X60Qx_1687 = NIM_FALSE;}
                    if (X60Qx_1687){
                      string_0_sysvq0asl X60Qii_17 = dollarQ_2_sysvq0asl(X60Qii_14);
                      NI32 X60Qx_1689 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1690 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1691 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I11838551355314224182_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1692 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1693 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_248 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1689 + X60Qx_1690)) + X60Qx_1691)) + X60Qx_1692)) + X60Qx_1693)));
                      add_2_sysvq0asl((&X60Qdesugar_248), (string_0_sysvq0asl){
                        .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_248), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_248), (string_0_sysvq0asl){
                        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I11838551355314224182_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_248), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_248), (string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_248);
                      NI32 X60Qx_1694 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1663049982u, .more_0 = (&strlit_0_I18298778748534440366_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1695 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1696 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I6279534061532764400_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1697 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1698 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 539697406u, .more_0 = (&strlit_0_I999642826010098592_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_249 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1694 + X60Qx_1695)) + X60Qx_1696)) + X60Qx_1697)) + X60Qx_1698)));
                      add_2_sysvq0asl((&X60Qdesugar_249), (string_0_sysvq0asl){
                        .bytes_0 = 1663049982u, .more_0 = (&strlit_0_I18298778748534440366_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_249), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_249), (string_0_sysvq0asl){
                        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I6279534061532764400_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_249), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_249), (string_0_sysvq0asl){
                        .bytes_0 = 539697406u, .more_0 = (&strlit_0_I999642826010098592_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_249);
                      NI32 X60Qx_1699 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I18051931441392338794_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1700 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1701 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I14188028891984688503_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1702 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1703 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540942590u, .more_0 = (&strlit_0_I12896234052304697321_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1704 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1705 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I15085895479102727221_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1706 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1707 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 539765246u, .more_0 = (&strlit_0_I13873650213014514182_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1708 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1709 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I16538839068818699094_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1710 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1711 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 7232258u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1712 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1713 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1025531390u, .more_0 = (&strlit_0_I522319342984753436_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_250 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1699 + X60Qx_1700)) + X60Qx_1701)) + X60Qx_1702)) + X60Qx_1703)) + X60Qx_1704)) + X60Qx_1705)) + X60Qx_1706)) + X60Qx_1707)) + X60Qx_1708)) + X60Qx_1709)) + X60Qx_1710)) + X60Qx_1711)) + X60Qx_1712)) + X60Qx_1713)));
                      add_2_sysvq0asl((&X60Qdesugar_250), (string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I18051931441392338794_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_250), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_250), (string_0_sysvq0asl){
                        .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I14188028891984688503_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_250), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_250), (string_0_sysvq0asl){
                        .bytes_0 = 540942590u, .more_0 = (&strlit_0_I12896234052304697321_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_250), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_250), (string_0_sysvq0asl){
                        .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I15085895479102727221_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_250), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_250), (string_0_sysvq0asl){
                        .bytes_0 = 539765246u, .more_0 = (&strlit_0_I13873650213014514182_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_250), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_250), (string_0_sysvq0asl){
                        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I16538839068818699094_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_250), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_250), (string_0_sysvq0asl){
                        .bytes_0 = 7232258u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_250), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_250), (string_0_sysvq0asl){
                        .bytes_0 = 1025531390u, .more_0 = (&strlit_0_I522319342984753436_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_250);
                      NI32 X60Qx_1714 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1715 = len_4_sysvq0asl(X60Qii_16);
                      NI32 X60Qx_1716 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1768632062u, .more_0 = (&strlit_0_I2950111016992692895_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1717 = len_4_sysvq0asl(X60Qii_16);
                      NI32 X60Qx_1718 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1702113022u, .more_0 = (&strlit_0_I9906658197478316873_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1719 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1720 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 541008126u, .more_0 = (&strlit_0_I16354051738273881375_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1721 = len_4_sysvq0asl(X60Qii_17);
                      NI32 X60Qx_1722 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I1386869864609809741_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_251 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1714 + X60Qx_1715)) + X60Qx_1716)) + X60Qx_1717)) + X60Qx_1718)) + X60Qx_1719)) + X60Qx_1720)) + X60Qx_1721)) + X60Qx_1722)));
                      add_2_sysvq0asl((&X60Qdesugar_251), (string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_251), X60Qii_16);
                      add_2_sysvq0asl((&X60Qdesugar_251), (string_0_sysvq0asl){
                        .bytes_0 = 1768632062u, .more_0 = (&strlit_0_I2950111016992692895_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_251), X60Qii_16);
                      add_2_sysvq0asl((&X60Qdesugar_251), (string_0_sysvq0asl){
                        .bytes_0 = 1702113022u, .more_0 = (&strlit_0_I9906658197478316873_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_251), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_251), (string_0_sysvq0asl){
                        .bytes_0 = 541008126u, .more_0 = (&strlit_0_I16354051738273881375_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_251), X60Qii_17);
                      add_2_sysvq0asl((&X60Qdesugar_251), (string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I1386869864609809741_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_251);
                      add_0_I8kd4i4_aow7lb5cq1((&X60Qii_10), X60Qii_14);
                      nimStrDestroy(X60Qdesugar_251);
                      nimStrDestroy(X60Qdesugar_250);
                      nimStrDestroy(X60Qdesugar_249);
                      nimStrDestroy(X60Qdesugar_248);
                      nimStrDestroy(X60Qii_17);}
                    else {
                      string_0_sysvq0asl X60Qdesugar_252 = dollarQ_2_sysvq0asl(X60Qii_14);
                      NI32 X60Qx_1723 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1724 = len_4_sysvq0asl(X60Qii_16);
                      NI32 X60Qx_1725 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1768632062u, .more_0 = (&strlit_0_I2409465560036334351_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1726 = len_4_sysvq0asl(X60Qii_16);
                      NI32 X60Qx_1727 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1852387070u, .more_0 = (&strlit_0_I12472622578803491916_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1728 = len_4_sysvq0asl(X60Qdesugar_252);
                      NI32 X60Qx_1729 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_253 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1723 + X60Qx_1724)) + X60Qx_1725)) + X60Qx_1726)) + X60Qx_1727)) + X60Qx_1728)) + X60Qx_1729)));
                      add_2_sysvq0asl((&X60Qdesugar_253), (string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_253), X60Qii_16);
                      add_2_sysvq0asl((&X60Qdesugar_253), (string_0_sysvq0asl){
                        .bytes_0 = 1768632062u, .more_0 = (&strlit_0_I2409465560036334351_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_253), X60Qii_16);
                      add_2_sysvq0asl((&X60Qdesugar_253), (string_0_sysvq0asl){
                        .bytes_0 = 1852387070u, .more_0 = (&strlit_0_I12472622578803491916_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_253), X60Qdesugar_252);
                      add_2_sysvq0asl((&X60Qdesugar_253), (string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_253);
                      nimStrDestroy(X60Qdesugar_253);
                      nimStrDestroy(X60Qdesugar_252);}}}
                inc_1_I6wjjge_aow2h993l1((&X60Qii_14));
                nimStrDestroy(X60Qdesugar_243);
                nimStrDestroy(X60Qii_16);
                nimStrDestroy(X60Qdesugar_242);
                nimStrDestroy(X60Qdesugar_241);
                nimStrDestroy(X60Qdesugar_240);
                nimStrDestroy(X60Qdesugar_239);
                nimStrDestroy(X60Qii_15);}
              if (X60Qii_13 == 0){
                add_2_sysvq0asl((&X60Qii_11), (string_0_sysvq0asl){
                  .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
                );}
              add_2_sysvq0asl((&X60Qii_11), (string_0_sysvq0asl){
                .bytes_0 = 10497u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qii_12), (string_0_sysvq0asl){
                .bytes_0 = 1092624638u, .more_0 = (&strlit_0_I9727381277316448500_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_254 = nimStrDup((*X60Qii_4));
              NI32 X60Qx_1730 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4239050738771163905_aow7lb5cq1)}
              );
              NI32 X60Qx_1731 = len_4_sysvq0asl(X60Qdesugar_254);
              NI32 X60Qx_1732 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 992551678u, .more_0 = (&strlit_0_I4880342578591911379_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_255 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1730 + X60Qx_1731)) + X60Qx_1732)));
              add_2_sysvq0asl((&X60Qdesugar_255), (string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4239050738771163905_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_255), X60Qdesugar_254);
              add_2_sysvq0asl((&X60Qdesugar_255), (string_0_sysvq0asl){
                .bytes_0 = 992551678u, .more_0 = (&strlit_0_I4880342578591911379_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_255);
              string_0_sysvq0asl X60Qdesugar_256 = nimStrDup((*X60Qii_4));
              string_0_sysvq0asl X60Qdesugar_257 = dollarQ_2_sysvq0asl(X60Qii_13);
              NI32 X60Qx_1733 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I17618980285034117678_aow7lb5cq1)}
              );
              NI32 X60Qx_1734 = len_4_sysvq0asl(X60Qdesugar_256);
              NI32 X60Qx_1735 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 539763454u, .more_0 = (&strlit_0_I15379383283362004468_aow7lb5cq1)}
              );
              NI32 X60Qx_1736 = len_4_sysvq0asl(X60Qdesugar_257);
              NI32 X60Qx_1737 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 639642878u, .more_0 = (&strlit_0_I15447660952270510385_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_258 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1733 + X60Qx_1734)) + X60Qx_1735)) + X60Qx_1736)) + X60Qx_1737)));
              add_2_sysvq0asl((&X60Qdesugar_258), (string_0_sysvq0asl){
                .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I17618980285034117678_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_258), X60Qdesugar_256);
              add_2_sysvq0asl((&X60Qdesugar_258), (string_0_sysvq0asl){
                .bytes_0 = 539763454u, .more_0 = (&strlit_0_I15379383283362004468_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_258), X60Qdesugar_257);
              add_2_sysvq0asl((&X60Qdesugar_258), (string_0_sysvq0asl){
                .bytes_0 = 639642878u, .more_0 = (&strlit_0_I15447660952270510385_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_258);
              {
                openArray_0_Inqs7yx_aow7lb5cq1 X60Qlf_22 = toOpenArray_1_Ibqb4ob_aow7lb5cq1(X60Qii_10);
                NI32 X60Qlf_23 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_1738 = len_6_I9632ti1_aow7lb5cq1(X60Qlf_22);
                    if (X60Qlf_23 < X60Qx_1738){
                      {
                        NI32* X60Qii_20 = getQ_10_I053icq_aow7lb5cq1(X60Qlf_22, X60Qlf_23);
                        string_0_sysvq0asl X60Qdesugar_259 = dollarQ_2_sysvq0asl((*X60Qii_20));
                        NI32 X60Qx_1739 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1713381630u, .more_0 = (&strlit_0_I13053102254449164970_aow7lb5cq1)}
                        );
                        NI32 X60Qx_1740 = len_4_sysvq0asl(X60Qdesugar_259);
                        NI32 X60Qx_1741 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                        );
                        string_0_sysvq0asl X60Qdesugar_260 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1739 + X60Qx_1740)) + X60Qx_1741)));
                        add_2_sysvq0asl((&X60Qdesugar_260), (string_0_sysvq0asl){
                          .bytes_0 = 1713381630u, .more_0 = (&strlit_0_I13053102254449164970_aow7lb5cq1)}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_260), X60Qdesugar_259);
                        add_2_sysvq0asl((&X60Qdesugar_260), (string_0_sysvq0asl){
                          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                        );
                        add_2_sysvq0asl((&X60Qii_12), X60Qdesugar_260);
                        nimStrDestroy(X60Qdesugar_260);
                        nimStrDestroy(X60Qdesugar_259);}
                      inc_1_I6wjjge_aow2h993l1((&X60Qlf_23));}
                    else {
                      break;}}}
                whileStmtLabel_19: ;}
              forStmtLabel_18: ;
              NB8 X60Qx_1742 = eqQ_20_sysvq0asl(X60Qii_5.fld_1, (string_0_sysvq0asl){
                .bytes_0 = 910577406u, .more_0 = (&strlit_0_I11372099257973387468_aow7lb5cq1)}
              );
              if (X60Qx_1742){
                add_2_sysvq0asl((&X60Qii_12), (string_0_sysvq0asl){
                  .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I8589617518665240758_aow7lb5cq1)}
                );}
              else {
                NB8 X60Qx_1743 = eqQ_20_sysvq0asl(X60Qii_5.fld_1, (string_0_sysvq0asl){
                  .bytes_0 = 943869443u, .more_0 = NIM_NIL}
                );
                if (X60Qx_1743){
                  add_2_sysvq0asl((&X60Qii_12), (string_0_sysvq0asl){
                    .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10391326054084265825_aow7lb5cq1)}
                  );}
                else {
                  NB8 X60Qx_1744 = eqQ_20_sysvq0asl(X60Qii_5.fld_1, (string_0_sysvq0asl){
                    .bytes_0 = 910774014u, .more_0 = (&strlit_0_I6323980750145937682_aow7lb5cq1)}
                  );
                  if (X60Qx_1744){
                    add_2_sysvq0asl((&X60Qii_12), (string_0_sysvq0asl){
                      .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I17794303870586718664_aow7lb5cq1)}
                    );}
                  else {
                    NB8 X60Qx_1745;
                    if (strOk_0){
                      NB8 X60Qx_1746 = eqQ_20_sysvq0asl(X60Qii_5.fld_1, strT_4);
                      X60Qx_1745 = X60Qx_1746;}
                    else {
                      X60Qx_1745 = NIM_FALSE;}
                    if (X60Qx_1745){
                      add_2_sysvq0asl((&X60Qii_12), (string_0_sysvq0asl){
                        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I7118603062085015288_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qii_12), (string_0_sysvq0asl){
                        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1702752895680478826_aow7lb5cq1)}
                      );}}}}
              NI32 X60Qx_1747 = len_4_sysvq0asl(X60Qii_11);
              NI32 X60Qx_1748 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1749 = len_4_sysvq0asl(X60Qii_11);
              NI32 X60Qx_1750 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 175841283u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1751 = len_4_sysvq0asl(X60Qii_12);
              NI32 X60Qx_1752 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 687362u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_261 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1747 + X60Qx_1748)) + X60Qx_1749)) + X60Qx_1750)) + X60Qx_1751)) + X60Qx_1752)));
              add_2_sysvq0asl((&X60Qdesugar_261), X60Qii_11);
              add_2_sysvq0asl((&X60Qdesugar_261), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_261), X60Qii_11);
              add_2_sysvq0asl((&X60Qdesugar_261), (string_0_sysvq0asl){
                .bytes_0 = 175841283u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_261), X60Qii_12);
              add_2_sysvq0asl((&X60Qdesugar_261), (string_0_sysvq0asl){
                .bytes_0 = 687362u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&c_4), X60Qdesugar_261);
              nimStrDestroy(X60Qdesugar_261);
              nimStrDestroy(X60Qdesugar_258);
              nimStrDestroy(X60Qdesugar_257);
              nimStrDestroy(X60Qdesugar_256);
              nimStrDestroy(X60Qdesugar_255);
              nimStrDestroy(X60Qdesugar_254);
              nimStrDestroy(X60Qdesugar_238);
              nimStrDestroy(X60Qdesugar_237);
              nimStrDestroy(X60Qii_12);
              nimStrDestroy(X60Qii_11);
              nimStrDestroy(X60Qdesugar_236);
              nimStrDestroy(X60Qdesugar_235);
              eQdestroy_1_Iv9ij5i1_aow7lb5cq1(X60Qii_10);
              eQdestroyQ_AtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_0_aow7lb5cq1(X60Qii_5);}
            continueLabel_3: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_19));}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  forStmtLabel_1: ;
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = writeFile_0_syn1lfpjv(path_2, c_4);
  if (X60QcanRaise_0){
    goto X60Qexlab_2;}
  if (NIM_FALSE){
    X60Qexlab_2: ;
    nimStrDestroy(c_4);
    nimStrDestroy(X60Qdesugar_228);
    nimStrDestroy(longT_4);
    nimStrDestroy(strT_4);
    return NIM_FALSE;}
  result_58 = NIM_TRUE;
  nimStrDestroy(c_4);
  nimStrDestroy(X60Qdesugar_228);
  nimStrDestroy(longT_4);
  nimStrDestroy(strT_4);
  return result_58;
  nimStrDestroy(c_4);
  nimStrDestroy(X60Qdesugar_228);
  nimStrDestroy(longT_4);
  nimStrDestroy(strT_4);
  return result_58;}
void writeFwdList_0_aow7lb5cq1(string_0_sysvq0asl buildDir_0, seq_0_Ixdx2fh1_aow7lb5cq1 names_2){
  string_0_sysvq0asl t_8 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_24 = toOpenArray_1_I6b60gk1_aow7lb5cq1(names_2);
    NI32 X60Qlf_25 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1753 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_24);
        if (X60Qlf_25 < X60Qx_1753){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_24, X60Qlf_25);
            string_0_sysvq0asl X60Qtmp_59 = ampQ_0_sysvq0asl((*X60Qii_2), (string_0_sysvq0asl){
              .bytes_0 = 2561u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&t_8), X60Qtmp_59);
            nimStrDestroy(X60Qtmp_59);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_25));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qtmp_60 = slashQ_0_ospaexnw61(buildDir_0, (string_0_sysvq0asl){
    .bytes_0 = 1936681214u, .more_0 = (&strlit_0_I15753997017069821155_aow7lb5cq1)}
  );
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = writeFile_0_syn1lfpjv(X60Qtmp_60, t_8);
  if (X60QcanRaise_0){
    nimStrDestroy(X60Qtmp_60);
    goto X60Qexlab_3;}
  nimStrDestroy(X60Qtmp_60);
  if (NIM_FALSE){
    X60Qexlab_3: ;}
  nimStrDestroy(t_8);}
seq_0_Ixdx2fh1_aow7lb5cq1 minusForwarded_0_aow7lb5cq1(string_0_sysvq0asl buildDir_1, seq_0_Ixdx2fh1_aow7lb5cq1 names_3){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_59;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_59));
  seq_0_Ixdx2fh1_aow7lb5cq1 fw_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    string_0_sysvq0asl X60Qlf_26 = slashQ_0_ospaexnw61(buildDir_1, (string_0_sysvq0asl){
      .bytes_0 = 1936681214u, .more_0 = (&strlit_0_I15753997017069821155_aow7lb5cq1)}
    );
    FILE* X60Qlf_27;
    NB8 X60Qx_1754 = open_0_syn1lfpjv((&X60Qlf_27), X60Qlf_26, 0, -1);
    if (X60Qx_1754){
      string_0_sysvq0asl X60Qlf_28 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      {
        while (NIM_TRUE){
          NB8 X60Qx_1755 = readLine_0_syn1lfpjv(X60Qlf_27, (&X60Qlf_28));
          if (X60Qx_1755){
            {
              NI32 X60Qx_1756 = len_4_sysvq0asl(X60Qlf_28);
              if (0 < X60Qx_1756){
                string_0_sysvq0asl X60Qx_1757 = nimStrDup(X60Qlf_28);
                add_0_Ig6072n_aow7lb5cq1((&fw_0), X60Qx_1757);}}}
          else {
            break;}}}
      whileStmtLabel_1: ;
      NI32 X60Qx_1758 = fclose(X60Qlf_27);
      nimStrDestroy(X60Qlf_28);}
    nimStrDestroy(X60Qlf_26);}
  forStmtLabel_0: ;
  if (NIM_FALSE){
    X60Qexlab_4: ;}
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_59);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1759 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_59 = X60Qx_1759;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_29 = toOpenArray_1_I6b60gk1_aow7lb5cq1(names_3);
    NI32 X60Qlf_30 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1760 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_29);
        if (X60Qlf_30 < X60Qx_1760){
          {
            string_0_sysvq0asl* X60Qii_4 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_29, X60Qlf_30);
            NB8 X60Qii_5 = NIM_FALSE;
            {
              openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_31 = toOpenArray_1_I6b60gk1_aow7lb5cq1(fw_0);
              NI32 X60Qlf_32 = 0;
              {
                while (NIM_TRUE){
                  NI32 X60Qx_1761 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_31);
                  if (X60Qlf_32 < X60Qx_1761){
                    {
                      string_0_sysvq0asl* X60Qii_8 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_31, X60Qlf_32);
                      NB8 X60Qx_1762 = eqQ_20_sysvq0asl((*X60Qii_8), (*X60Qii_4));
                      if (X60Qx_1762){
                        X60Qii_5 = NIM_TRUE;}}
                    inc_1_I6wjjge_aow2h993l1((&X60Qlf_32));}
                  else {
                    break;}}}
              whileStmtLabel_7: ;}
            forStmtLabel_6: ;
            if ((!X60Qii_5)){
              string_0_sysvq0asl X60Qx_1763 = nimStrDup((*X60Qii_4));
              add_0_Ig6072n_aow7lb5cq1((&result_59), X60Qx_1763);}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_30));}
        else {
          break;}}}
    whileStmtLabel_3: ;}
  forStmtLabel_2: ;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(fw_0);
  return result_59;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(fw_0);
  return result_59;}
NB8 gccCompileOne_0_aow7lb5cq1(string_0_sysvq0asl cpath_0, string_0_sysvq0asl oPath_0, string_0_sysvq0asl logFile_1){
  NB8 result_60;
  string_0_sysvq0asl X60Qdesugar_262 = quoteShell_0_oswd7dmm(cpath_0);
  string_0_sysvq0asl X60Qdesugar_263 = quoteShell_0_oswd7dmm(oPath_0);
  string_0_sysvq0asl X60Qdesugar_264 = quoteShell_0_oswd7dmm(logFile_1);
  NI32 X60Qx_1764 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I1487126578772208186_aow7lb5cq1)}
  );
  NI32 X60Qx_1765 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1348873726u, .more_0 = (&strlit_0_I16911823819878676030_aow7lb5cq1)}
  );
  NI32 X60Qx_1766 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1767 = len_4_sysvq0asl(X60Qdesugar_262);
  NI32 X60Qx_1768 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  NI32 X60Qx_1769 = len_4_sysvq0asl(X60Qdesugar_263);
  NI32 X60Qx_1770 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1771 = len_4_sysvq0asl(X60Qdesugar_264);
  NI32 X60Qx_1772 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_265 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1764 + X60Qx_1765)) + X60Qx_1766)) + X60Qx_1767)) + X60Qx_1768)) + X60Qx_1769)) + X60Qx_1770)) + X60Qx_1771)) + X60Qx_1772)));
  add_2_sysvq0asl((&X60Qdesugar_265), (string_0_sysvq0asl){
    .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I1487126578772208186_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_265), (string_0_sysvq0asl){
    .bytes_0 = 1348873726u, .more_0 = (&strlit_0_I16911823819878676030_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_265), (string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_265), X60Qdesugar_262);
  add_2_sysvq0asl((&X60Qdesugar_265), (string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_265), X60Qdesugar_263);
  add_2_sysvq0asl((&X60Qdesugar_265), (string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_265), X60Qdesugar_264);
  add_2_sysvq0asl((&X60Qdesugar_265), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  NI32 X60Qx_1773 = execShellCmd_0_oswd7dmm(X60Qdesugar_265);
  result_60 = (X60Qx_1773 == 0);
  nimStrDestroy(X60Qdesugar_265);
  nimStrDestroy(X60Qdesugar_264);
  nimStrDestroy(X60Qdesugar_263);
  nimStrDestroy(X60Qdesugar_262);
  return result_60;
  nimStrDestroy(X60Qdesugar_265);
  nimStrDestroy(X60Qdesugar_264);
  nimStrDestroy(X60Qdesugar_263);
  nimStrDestroy(X60Qdesugar_262);
  return result_60;}
NB8 gccLinkObjects_0_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 oPaths_0, string_0_sysvq0asl soPath_0, string_0_sysvq0asl logFile_2){
  NB8 result_61;
  string_0_sysvq0asl cmd_0 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I7830052811571726362_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 1752378878u, .more_0 = (&strlit_0_I10506424120731942949_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&cmd_0), (string_0_sysvq0asl){
    .bytes_0 = 1462575358u, .more_0 = (&strlit_0_I3033588956580774226_aow7lb5cq1)}
  );
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_33 = toOpenArray_1_I6b60gk1_aow7lb5cq1(oPaths_0);
    NI32 X60Qlf_34 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1774 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_33);
        if (X60Qlf_34 < X60Qx_1774){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_33, X60Qlf_34);
            string_0_sysvq0asl X60Qtmp_62 = quoteShell_0_oswd7dmm((*X60Qii_2));
            string_0_sysvq0asl X60Qtmp_61 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            , X60Qtmp_62);
            add_2_sysvq0asl((&cmd_0), X60Qtmp_61);
            nimStrDestroy(X60Qtmp_61);
            nimStrDestroy(X60Qtmp_62);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_34));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qdesugar_266 = quoteShell_0_oswd7dmm(soPath_0);
  string_0_sysvq0asl X60Qdesugar_267 = quoteShell_0_oswd7dmm(logFile_2);
  NI32 X60Qx_1775 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1462575358u, .more_0 = (&strlit_0_I6185901741629117379_aow7lb5cq1)}
  );
  NI32 X60Qx_1776 = len_4_sysvq0asl(X60Qdesugar_266);
  NI32 X60Qx_1777 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  NI32 X60Qx_1778 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1779 = len_4_sysvq0asl(X60Qdesugar_267);
  NI32 X60Qx_1780 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_268 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1775 + X60Qx_1776)) + X60Qx_1777)) + X60Qx_1778)) + X60Qx_1779)) + X60Qx_1780)));
  add_2_sysvq0asl((&X60Qdesugar_268), (string_0_sysvq0asl){
    .bytes_0 = 1462575358u, .more_0 = (&strlit_0_I6185901741629117379_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_268), X60Qdesugar_266);
  add_2_sysvq0asl((&X60Qdesugar_268), (string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_268), (string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_268), X60Qdesugar_267);
  add_2_sysvq0asl((&X60Qdesugar_268), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&cmd_0), X60Qdesugar_268);
  NI32 X60Qx_1781 = execShellCmd_0_oswd7dmm(cmd_0);
  result_61 = (X60Qx_1781 == 0);
  nimStrDestroy(X60Qdesugar_268);
  nimStrDestroy(X60Qdesugar_267);
  nimStrDestroy(X60Qdesugar_266);
  nimStrDestroy(cmd_0);
  return result_61;
  nimStrDestroy(X60Qdesugar_268);
  nimStrDestroy(X60Qdesugar_267);
  nimStrDestroy(X60Qdesugar_266);
  nimStrDestroy(cmd_0);
  return result_61;}
NB8 writeIfChanged_0_aow7lb5cq1(string_0_sysvq0asl path_3, string_0_sysvq0asl body_0){
  NB8 result_62;
  string_0_sysvq0asl old_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_0 = readFile_0_syn1lfpjv(path_3);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_5;}
  nimStrDestroy(old_0);
  string_0_sysvq0asl X60Qx_1782 = nimStrDup(X60QcanRaise_0.fld_1);
  old_0 = X60Qx_1782;
  if (NIM_FALSE){
    X60Qexlab_5: ;
    nimStrDestroy(old_0);
    old_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NB8 X60Qx_1783 = eqQ_20_sysvq0asl(old_0, body_0);
  if (X60Qx_1783){
    nimStrDestroy(old_0);
    return NIM_FALSE;}
  ErrorCode_0_sysvq0asl X60QcanRaise_1 = writeFile_0_syn1lfpjv(path_3, body_0);
  if (X60QcanRaise_1){
    goto X60Qexlab_6;}
  if (NIM_FALSE){
    X60Qexlab_6: ;
    nimStrDestroy(old_0);
    return NIM_TRUE;}
  result_62 = NIM_TRUE;
  nimStrDestroy(old_0);
  return result_62;
  nimStrDestroy(old_0);
  return result_62;}
NB8 gccSharedMany_0_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 cpaths_0, string_0_sysvq0asl soPath_1, string_0_sysvq0asl logFile_3){
  NB8 result_63;
  string_0_sysvq0asl cmd_1 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I7830052811571726362_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 1752378878u, .more_0 = (&strlit_0_I10506424120731942949_aow7lb5cq1)}
  );
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_35 = toOpenArray_1_I6b60gk1_aow7lb5cq1(cpaths_0);
    NI32 X60Qlf_36 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1784 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_35);
        if (X60Qlf_36 < X60Qx_1784){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_35, X60Qlf_36);
            string_0_sysvq0asl X60Qtmp_64 = quoteShell_0_oswd7dmm((*X60Qii_2));
            string_0_sysvq0asl X60Qtmp_63 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            , X60Qtmp_64);
            add_2_sysvq0asl((&cmd_1), X60Qtmp_63);
            nimStrDestroy(X60Qtmp_63);
            nimStrDestroy(X60Qtmp_64);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_36));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qdesugar_269 = quoteShell_0_oswd7dmm(soPath_1);
  string_0_sysvq0asl X60Qdesugar_270 = quoteShell_0_oswd7dmm(logFile_3);
  NI32 X60Qx_1785 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  NI32 X60Qx_1786 = len_4_sysvq0asl(X60Qdesugar_269);
  NI32 X60Qx_1787 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  NI32 X60Qx_1788 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1789 = len_4_sysvq0asl(X60Qdesugar_270);
  NI32 X60Qx_1790 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_271 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1785 + X60Qx_1786)) + X60Qx_1787)) + X60Qx_1788)) + X60Qx_1789)) + X60Qx_1790)));
  add_2_sysvq0asl((&X60Qdesugar_271), (string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_271), X60Qdesugar_269);
  add_2_sysvq0asl((&X60Qdesugar_271), (string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_271), (string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_271), X60Qdesugar_270);
  add_2_sysvq0asl((&X60Qdesugar_271), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&cmd_1), X60Qdesugar_271);
  NI32 X60Qx_1791 = execShellCmd_0_oswd7dmm(cmd_1);
  result_63 = (X60Qx_1791 == 0);
  nimStrDestroy(X60Qdesugar_271);
  nimStrDestroy(X60Qdesugar_270);
  nimStrDestroy(X60Qdesugar_269);
  nimStrDestroy(cmd_1);
  return result_63;
  nimStrDestroy(X60Qdesugar_271);
  nimStrDestroy(X60Qdesugar_270);
  nimStrDestroy(X60Qdesugar_269);
  nimStrDestroy(cmd_1);
  return result_63;}
NB8 gccShared_0_aow7lb5cq1(string_0_sysvq0asl cpath_1, string_0_sysvq0asl soPath_2, string_0_sysvq0asl logFile_4){
  NB8 result_64;
  string_0_sysvq0asl X60Qdesugar_272 = quoteShell_0_oswd7dmm(cpath_1);
  string_0_sysvq0asl X60Qdesugar_273 = quoteShell_0_oswd7dmm(soPath_2);
  string_0_sysvq0asl X60Qdesugar_274 = quoteShell_0_oswd7dmm(logFile_4);
  NI32 X60Qx_1792 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I7830052811571726362_aow7lb5cq1)}
  );
  NI32 X60Qx_1793 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1752378878u, .more_0 = (&strlit_0_I10506424120731942949_aow7lb5cq1)}
  );
  NI32 X60Qx_1794 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1795 = len_4_sysvq0asl(X60Qdesugar_272);
  NI32 X60Qx_1796 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  NI32 X60Qx_1797 = len_4_sysvq0asl(X60Qdesugar_273);
  NI32 X60Qx_1798 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  NI32 X60Qx_1799 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1800 = len_4_sysvq0asl(X60Qdesugar_274);
  NI32 X60Qx_1801 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_275 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1792 + X60Qx_1793)) + X60Qx_1794)) + X60Qx_1795)) + X60Qx_1796)) + X60Qx_1797)) + X60Qx_1798)) + X60Qx_1799)) + X60Qx_1800)) + X60Qx_1801)));
  add_2_sysvq0asl((&X60Qdesugar_275), (string_0_sysvq0asl){
    .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I7830052811571726362_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_275), (string_0_sysvq0asl){
    .bytes_0 = 1752378878u, .more_0 = (&strlit_0_I10506424120731942949_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_275), (string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_275), X60Qdesugar_272);
  add_2_sysvq0asl((&X60Qdesugar_275), (string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_275), X60Qdesugar_273);
  add_2_sysvq0asl((&X60Qdesugar_275), (string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_275), (string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_275), X60Qdesugar_274);
  add_2_sysvq0asl((&X60Qdesugar_275), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  NI32 X60Qx_1802 = execShellCmd_0_oswd7dmm(X60Qdesugar_275);
  result_64 = (X60Qx_1802 == 0);
  nimStrDestroy(X60Qdesugar_275);
  nimStrDestroy(X60Qdesugar_274);
  nimStrDestroy(X60Qdesugar_273);
  nimStrDestroy(X60Qdesugar_272);
  return result_64;
  nimStrDestroy(X60Qdesugar_275);
  nimStrDestroy(X60Qdesugar_274);
  nimStrDestroy(X60Qdesugar_273);
  nimStrDestroy(X60Qdesugar_272);
  return result_64;}
string_0_sysvq0asl buildShimsC_0_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 entries_0, string_0_sysvq0asl cnifDir_0, string_0_sysvq0asl buildDir_2, seq_0_Igzebks_aow7lb5cq1* shimmed_0, seq_0_Ixdx2fh1_aow7lb5cq1* undefined_0, NB8 wholeProgram_0){
  string_0_sysvq0asl result_65;
  nimStrWasMoved((&result_65));
  nimStrDestroy(result_65);
  result_65 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  eQdestroy_1_Iytr7x_aow7lb5cq1((*shimmed_0));
  seq_0_Igzebks_aow7lb5cq1 X60Qx_1803 = newSeqUninit_0_I6ffb0e1_aow7lb5cq1(0);
  (*shimmed_0) = X60Qx_1803;
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*undefined_0));
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1804 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  (*undefined_0) = X60Qx_1804;
  NB8 X60Qx_1805;
  NI32 X60Qx_1806 = len_3_I44vue3_aow7lb5cq1(entries_0);
  if (X60Qx_1806 == 0){
    X60Qx_1805 = (!wholeProgram_0);}
  else {
    X60Qx_1805 = NIM_FALSE;}
  if (X60Qx_1805){
    return result_65;}
  string_0_sysvq0asl X60Qtmp_65 = shMkdirP_0_hos14g919(buildDir_2);
  NI32 X60Qx_1807 = execShellCmd_0_oswd7dmm(X60Qtmp_65);
  string_0_sysvq0asl cFile_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I11438303454518475359_aow7lb5cq1)}
  );
  string_0_sysvq0asl logFile_5 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 1769300734u, .more_0 = (&strlit_0_I1947988348543698404_aow7lb5cq1)}
  );
  string_0_sysvq0asl stubRevisionFile_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 1936681214u, .more_0 = (&strlit_0_I12541394025232970491_aow7lb5cq1)}
  );
  NB8 stubsCurrent_0 = NIM_FALSE;
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_0 = readFile_0_syn1lfpjv(stubRevisionFile_0);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_7;}
  string_0_sysvq0asl X60Qtmp_66 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3354882u, .more_0 = NIM_NIL}
  , (string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_1808 = eqQ_20_sysvq0asl(X60QcanRaise_0.fld_1, X60Qtmp_66);
  stubsCurrent_0 = X60Qx_1808;
  nimStrDestroy(X60Qtmp_66);
  if (NIM_FALSE){
    X60Qexlab_7: ;}
  if ((!stubsCurrent_0)){
    string_0_sysvq0asl X60Qtmp_67 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 3354882u, .more_0 = NIM_NIL}
    , (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    ErrorCode_0_sysvq0asl X60QcanRaise_1 = writeFile_0_syn1lfpjv(stubRevisionFile_0, X60Qtmp_67);
    if (X60QcanRaise_1){
      nimStrDestroy(X60Qtmp_67);
      goto X60Qexlab_8;}
    nimStrDestroy(X60Qtmp_67);
    if (NIM_FALSE){
      X60Qexlab_8: ;}}
  string_0_sysvq0asl listFile_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I9032354697946540937_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_276 = quoteShell_0_oswd7dmm(cnifDir_0);
  string_0_sysvq0asl X60Qdesugar_277 = quoteShell_0_oswd7dmm(cnifDir_0);
  NI32 X60Qx_1809 = len_4_sysvq0asl(X60Qdesugar_276);
  NI32 X60Qx_1810 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 774516734u, .more_0 = (&strlit_0_I14177207265498126630_aow7lb5cq1)}
  );
  NI32 X60Qx_1811 = len_4_sysvq0asl(X60Qdesugar_277);
  NI32 X60Qx_1812 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 791293950u, .more_0 = (&strlit_0_I267845865139732674_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_278 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1809 + X60Qx_1810)) + X60Qx_1811)) + X60Qx_1812)));
  add_2_sysvq0asl((&X60Qdesugar_278), X60Qdesugar_276);
  add_2_sysvq0asl((&X60Qdesugar_278), (string_0_sysvq0asl){
    .bytes_0 = 774516734u, .more_0 = (&strlit_0_I14177207265498126630_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_278), X60Qdesugar_277);
  add_2_sysvq0asl((&X60Qdesugar_278), (string_0_sysvq0asl){
    .bytes_0 = 791293950u, .more_0 = (&strlit_0_I267845865139732674_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qtmp_68 = shListInto_0_hos14g919(X60Qdesugar_278, listFile_0);
  NI32 X60Qx_1813 = execShellCmd_0_oswd7dmm(X60Qtmp_68);
  seq_0_Ixdx2fh1_aow7lb5cq1 cmods_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    string_0_sysvq0asl X60Qlf_37 = listFile_0;
    FILE* X60Qlf_38;
    NB8 X60Qx_1814 = open_0_syn1lfpjv((&X60Qlf_38), X60Qlf_37, 0, -1);
    if (X60Qx_1814){
      string_0_sysvq0asl X60Qlf_39 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      {
        while (NIM_TRUE){
          NB8 X60Qx_1815 = readLine_0_syn1lfpjv(X60Qlf_38, (&X60Qlf_39));
          if (X60Qx_1815){
            {
              string_0_sysvq0asl X60Qii_2 = nimStrDup(X60Qlf_39);
              while (NIM_TRUE){
                NB8 X60Qx_1816;
                NI32 X60Qx_1817 = len_4_sysvq0asl(X60Qii_2);
                if (0 < X60Qx_1817){
                  NB8 X60Qx_1818;
                  NB8 X60Qx_1819;
                  NI32 X60Qx_1820 = len_4_sysvq0asl(X60Qii_2);
                  NC8 X60Qx_1821 = getQ_9_sysvq0asl(X60Qii_2, ((NI32)(X60Qx_1820 - 1)));
                  if (X60Qx_1821 == (NC8)'\012'){
                    X60Qx_1819 = NIM_TRUE;}
                  else {
                    NI32 X60Qx_1822 = len_4_sysvq0asl(X60Qii_2);
                    NC8 X60Qx_1823 = getQ_9_sysvq0asl(X60Qii_2, ((NI32)(X60Qx_1822 - 1)));
                    X60Qx_1819 = (X60Qx_1823 == (NC8)'\015');}
                  if (X60Qx_1819){
                    X60Qx_1818 = NIM_TRUE;}
                  else {
                    NI32 X60Qx_1824 = len_4_sysvq0asl(X60Qii_2);
                    NC8 X60Qx_1825 = getQ_9_sysvq0asl(X60Qii_2, ((NI32)(X60Qx_1824 - 1)));
                    X60Qx_1818 = (X60Qx_1825 == (NC8)' ');}
                  X60Qx_1816 = X60Qx_1818;}
                else {
                  X60Qx_1816 = NIM_FALSE;}
                if (X60Qx_1816){
                  NI32 X60Qx_1826 = len_4_sysvq0asl(X60Qii_2);
                  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1827 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_1826 - 2)));
                  string_0_sysvq0asl X60Qlhs_69 = getQ_14_sysvq0asl(X60Qii_2, X60Qx_1827);
                  nimStrDestroy(X60Qii_2);
                  X60Qii_2 = X60Qlhs_69;}
                else {
                  break;}}
              NI32 X60Qx_1828 = len_4_sysvq0asl(X60Qii_2);
              if (0 < X60Qx_1828){
                string_0_sysvq0asl X60Qtmp_70 = X60Qii_2;
                nimStrWasMoved((&X60Qii_2));
                add_0_Ig6072n_aow7lb5cq1((&cmods_0), X60Qtmp_70);}
              nimStrDestroy(X60Qii_2);}}
          else {
            break;}}}
      whileStmtLabel_1: ;
      NI32 X60Qx_1829 = fclose(X60Qlf_38);
      nimStrDestroy(X60Qlf_39);}}
  forStmtLabel_0: ;
  if (NIM_FALSE){
    X60Qexlab_9: ;}
  NI32 X60Qx_1830 = len_3_Ixq6taz_aow7lb5cq1(cmods_0);
  if (X60Qx_1830 == 0){
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  string_0_sysvq0asl X60Qtmp_71 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I18192332346447245389_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 wantPreDce_0 = eqQ_20_sysvq0asl(X60Qtmp_71, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  seq_0_Ixdx2fh1_aow7lb5cq1 xmods_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  if (wantPreDce_0){
    string_0_sysvq0asl xListFile_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
      .bytes_0 = 1869445374u, .more_0 = (&strlit_0_I7475120879548367157_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_279 = quoteShell_0_oswd7dmm(cnifDir_0);
    string_0_sysvq0asl X60Qdesugar_280 = quoteShell_0_oswd7dmm(cnifDir_0);
    NI32 X60Qx_1831 = len_4_sysvq0asl(X60Qdesugar_279);
    NI32 X60Qx_1832 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 774516734u, .more_0 = (&strlit_0_I18095216927531186533_aow7lb5cq1)}
    );
    NI32 X60Qx_1833 = len_4_sysvq0asl(X60Qdesugar_280);
    NI32 X60Qx_1834 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791293950u, .more_0 = (&strlit_0_I16254858060766665859_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_281 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1831 + X60Qx_1832)) + X60Qx_1833)) + X60Qx_1834)));
    add_2_sysvq0asl((&X60Qdesugar_281), X60Qdesugar_279);
    add_2_sysvq0asl((&X60Qdesugar_281), (string_0_sysvq0asl){
      .bytes_0 = 774516734u, .more_0 = (&strlit_0_I18095216927531186533_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_281), X60Qdesugar_280);
    add_2_sysvq0asl((&X60Qdesugar_281), (string_0_sysvq0asl){
      .bytes_0 = 791293950u, .more_0 = (&strlit_0_I16254858060766665859_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qtmp_72 = shListInto_0_hos14g919(X60Qdesugar_281, xListFile_0);
    NI32 X60Qx_1835 = execShellCmd_0_oswd7dmm(X60Qtmp_72);
    {
      string_0_sysvq0asl X60Qlf_40 = xListFile_0;
      FILE* X60Qlf_41;
      NB8 X60Qx_1836 = open_0_syn1lfpjv((&X60Qlf_41), X60Qlf_40, 0, -1);
      if (X60Qx_1836){
        string_0_sysvq0asl X60Qlf_42 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;
        {
          while (NIM_TRUE){
            NB8 X60Qx_1837 = readLine_0_syn1lfpjv(X60Qlf_41, (&X60Qlf_42));
            if (X60Qx_1837){
              {
                string_0_sysvq0asl X60Qii_5 = nimStrDup(X60Qlf_42);
                while (NIM_TRUE){
                  NB8 X60Qx_1838;
                  NI32 X60Qx_1839 = len_4_sysvq0asl(X60Qii_5);
                  if (0 < X60Qx_1839){
                    NB8 X60Qx_1840;
                    NB8 X60Qx_1841;
                    NI32 X60Qx_1842 = len_4_sysvq0asl(X60Qii_5);
                    NC8 X60Qx_1843 = getQ_9_sysvq0asl(X60Qii_5, ((NI32)(X60Qx_1842 - 1)));
                    if (X60Qx_1843 == (NC8)'\012'){
                      X60Qx_1841 = NIM_TRUE;}
                    else {
                      NI32 X60Qx_1844 = len_4_sysvq0asl(X60Qii_5);
                      NC8 X60Qx_1845 = getQ_9_sysvq0asl(X60Qii_5, ((NI32)(X60Qx_1844 - 1)));
                      X60Qx_1841 = (X60Qx_1845 == (NC8)'\015');}
                    if (X60Qx_1841){
                      X60Qx_1840 = NIM_TRUE;}
                    else {
                      NI32 X60Qx_1846 = len_4_sysvq0asl(X60Qii_5);
                      NC8 X60Qx_1847 = getQ_9_sysvq0asl(X60Qii_5, ((NI32)(X60Qx_1846 - 1)));
                      X60Qx_1840 = (X60Qx_1847 == (NC8)' ');}
                    X60Qx_1838 = X60Qx_1840;}
                  else {
                    X60Qx_1838 = NIM_FALSE;}
                  if (X60Qx_1838){
                    NI32 X60Qx_1848 = len_4_sysvq0asl(X60Qii_5);
                    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1849 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_1848 - 2)));
                    string_0_sysvq0asl X60Qlhs_73 = getQ_14_sysvq0asl(X60Qii_5, X60Qx_1849);
                    nimStrDestroy(X60Qii_5);
                    X60Qii_5 = X60Qlhs_73;}
                  else {
                    break;}}
                NI32 X60Qx_1850 = len_4_sysvq0asl(X60Qii_5);
                if (0 < X60Qx_1850){
                  string_0_sysvq0asl X60Qtmp_74 = X60Qii_5;
                  nimStrWasMoved((&X60Qii_5));
                  add_0_Ig6072n_aow7lb5cq1((&xmods_0), X60Qtmp_74);}
                nimStrDestroy(X60Qii_5);}}
            else {
              break;}}}
        whileStmtLabel_4: ;
        NI32 X60Qx_1851 = fclose(X60Qlf_41);
        nimStrDestroy(X60Qlf_42);}}
    forStmtLabel_3: ;
    if (NIM_FALSE){
      X60Qexlab_10: ;}
    string_0_sysvq0asl X60Qtmp_75 = shRmF_0_hos14g919(xListFile_0);
    NI32 X60Qx_1852 = execShellCmd_0_oswd7dmm(X60Qtmp_75);
    nimStrDestroy(X60Qtmp_75);
    nimStrDestroy(X60Qtmp_72);
    nimStrDestroy(X60Qdesugar_281);
    nimStrDestroy(X60Qdesugar_280);
    nimStrDestroy(X60Qdesugar_279);
    nimStrDestroy(xListFile_0);}
  NB8 X60Qx_1853;
  if (0 < xmods_0.len_0){
    X60Qx_1853 = wantPreDce_0;}
  else {
    X60Qx_1853 = NIM_FALSE;}
  NB8 usingX_0 = X60Qx_1853;
  string_0_sysvq0asl stageDir_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 1768847614u, .more_0 = (&strlit_0_I6141559193247183651_aow7lb5cq1)}
  );
  if (usingX_0){
    string_0_sysvq0asl X60Qtmp_76 = shMkdirP_0_hos14g919(stageDir_0);
    NI32 X60Qx_1854 = execShellCmd_0_oswd7dmm(X60Qtmp_76);
    seq_0_Ixdx2fh1_aow7lb5cq1 staged_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    NI32 xi_0 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1855 = len_3_Ixq6taz_aow7lb5cq1(xmods_0);
        if (xi_0 < X60Qx_1855){
          string_0_sysvq0asl* X60Qx_1856 = getQ_7_Ir6d0tw_aow7lb5cq1(xmods_0, xi_0);
          string_0_sysvq0asl X60Qtmp_78 = moduleSuffix_0_aow7lb5cq1((*X60Qx_1856));
          string_0_sysvq0asl X60Qtmp_77 = ampQ_0_sysvq0asl(X60Qtmp_78, (string_0_sysvq0asl){
            .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17410079638349000741_aow7lb5cq1)}
          );
          string_0_sysvq0asl dst_1 = slashQ_0_ospaexnw61(stageDir_0, X60Qtmp_77);
          string_0_sysvq0asl* X60Qx_1857 = getQ_7_Ir6d0tw_aow7lb5cq1(xmods_0, xi_0);
          X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_3 = readFile_0_syn1lfpjv((*X60Qx_1857));
          if (X60QcanRaise_3.fld_0){
            goto X60Qexlab_11;}
          ErrorCode_0_sysvq0asl X60QcanRaise_2 = writeFile_0_syn1lfpjv(dst_1, X60QcanRaise_3.fld_1);
          if (X60QcanRaise_2){
            goto X60Qexlab_11;}
          string_0_sysvq0asl X60Qtmp_79 = dst_1;
          nimStrWasMoved((&dst_1));
          add_0_Ig6072n_aow7lb5cq1((&staged_0), X60Qtmp_79);
          if (NIM_FALSE){
            X60Qexlab_11: ;}
          inc_1_I6wjjge_aow2h993l1((&xi_0));
          nimStrDestroy(dst_1);
          nimStrDestroy(X60Qtmp_77);
          nimStrDestroy(X60Qtmp_78);}
        else {
          break;}}}
    whileStmtLabel_6: ;
    NI32 X60Qx_1858 = len_3_Ixq6taz_aow7lb5cq1(staged_0);
    NI32 X60Qx_1859 = len_3_Ixq6taz_aow7lb5cq1(xmods_0);
    if (X60Qx_1858 == X60Qx_1859){
      eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
      xmods_0 = staged_0;
      eQwasMoved_1_I5vdnla_aow7lb5cq1((&staged_0));}
    else {
      usingX_0 = NIM_FALSE;}
    eQdestroy_1_Ivioh0a_aow7lb5cq1(staged_0);
    nimStrDestroy(X60Qtmp_76);}
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_14;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&X60Qx_14));
  if (usingX_0){
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    X60Qx_14 = xmods_0;
    eQwasMoved_1_I5vdnla_aow7lb5cq1((&xmods_0));}
  else {
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    X60Qx_14 = cmods_0;
    eQwasMoved_1_I5vdnla_aow7lb5cq1((&cmods_0));}
  seq_0_Ixdx2fh1_aow7lb5cq1 mods_2 = X60Qx_14;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&X60Qx_14));
  string_0_sysvq0asl X60Qtmp_80 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_1860 = eqQ_20_sysvq0asl(X60Qtmp_80, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  if (X60Qx_1860){
    string_0_sysvq0asl X60Qx_15;
    nimStrWasMoved((&X60Qx_15));
    if (usingX_0){
      nimStrDestroy(X60Qx_15);
      X60Qx_15 = (string_0_sysvq0asl){
        .bytes_0 = 779628286u, .more_0 = (&strlit_0_I17588196217130192428_aow7lb5cq1)}
      ;}
    else {
      nimStrDestroy(X60Qx_15);
      X60Qx_15 = (string_0_sysvq0asl){
        .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17145838109380889823_aow7lb5cq1)}
      ;}
    string_0_sysvq0asl X60Qdesugar_282 = X60Qx_15;
    nimStrWasMoved((&X60Qx_15));
    NI32 X60Qx_1861 = len_3_Ixq6taz_aow7lb5cq1(mods_2);
    string_0_sysvq0asl X60Qdesugar_283 = dollarQ_2_sysvq0asl(X60Qx_1861);
    NI32 X60Qx_1862 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I4565430035092908447_aow7lb5cq1)}
    );
    NI32 X60Qx_1863 = len_4_sysvq0asl(X60Qdesugar_282);
    NI32 X60Qx_1864 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
    );
    NI32 X60Qx_1865 = len_4_sysvq0asl(X60Qdesugar_283);
    NI32 X60Qx_1866 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I17138688373536918376_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_284 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1862 + X60Qx_1863)) + X60Qx_1864)) + X60Qx_1865)) + X60Qx_1866)));
    add_2_sysvq0asl((&X60Qdesugar_284), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I4565430035092908447_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_284), X60Qdesugar_282);
    add_2_sysvq0asl((&X60Qdesugar_284), (string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_284), X60Qdesugar_283);
    add_2_sysvq0asl((&X60Qdesugar_284), (string_0_sysvq0asl){
      .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I17138688373536918376_aow7lb5cq1)}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_284);
    nimStrDestroy(X60Qdesugar_284);
    nimStrDestroy(X60Qdesugar_283);
    nimStrDestroy(X60Qdesugar_282);
    nimStrDestroy(X60Qx_15);}
  NI32 X60Qx_1867 = len_3_Ixq6taz_aow7lb5cq1(mods_2);
  if (X60Qx_1867 == 0){
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  string_0_sysvq0asl savedMainDir_0 = nimStrDup(prog_0_prorcx25w1.main_0.dir_0);
  string_0_sysvq0asl savedMainName_0 = nimStrDup(prog_0_prorcx25w1.main_0.name_0);
  string_0_sysvq0asl savedMainExt_0 = nimStrDup(prog_0_prorcx25w1.main_0.ext_0);
  seq_0_Ixdx2fh1_aow7lb5cq1 texts_4 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  NI32 i_33 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1868 = len_3_Ixq6taz_aow7lb5cq1(mods_2);
      if (i_33 < X60Qx_1868){
        string_0_sysvq0asl* X60Qx_1869 = getQ_7_Ir6d0tw_aow7lb5cq1(mods_2, i_33);
        string_0_sysvq0asl X60Qtmp_81 = parentDir_0_ospaexnw61((*X60Qx_1869));
        string_0_sysvq0asl* X60Qx_1870 = getQ_7_Ir6d0tw_aow7lb5cq1(mods_2, i_33);
        string_0_sysvq0asl X60Qtmp_82 = moduleSuffix_0_aow7lb5cq1((*X60Qx_1870));
        setupProgramForTesting_0_prorcx25w1(X60Qtmp_81, X60Qtmp_82, (string_0_sysvq0asl){
          .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17410079638349000741_aow7lb5cq1)}
        );
        string_0_sysvq0asl* X60Qx_1871 = getQ_7_Ir6d0tw_aow7lb5cq1(mods_2, i_33);
        TokenBuf_0_nifb6mq6y1 buf_0 = parseFromFile_0_nifb6mq6y1((*X60Qx_1871), 100);
        Cursor_0_nifb6mq6y1 root_0 = beginRead_0_nifb6mq6y1((&buf_0));
        string_0_sysvq0asl X60Qx_1872 = emitModuleBody_0_emi78vuj01((&root_0));
        add_0_Ig6072n_aow7lb5cq1((&texts_4), X60Qx_1872);
        endRead_0_nifb6mq6y1((&buf_0));
        inc_1_I6wjjge_aow2h993l1((&i_33));
        eQdestroy_0_nifb6mq6y1((&root_0));
        eQdestroy_1_nifb6mq6y1((&buf_0));
        nimStrDestroy(X60Qtmp_82);
        nimStrDestroy(X60Qtmp_81);}
      else {
        break;}}}
  whileStmtLabel_7: ;
  string_0_sysvq0asl* X60Qlhs_83 = (&prog_0_prorcx25w1.main_0.dir_0);
  nimStrDestroy((*X60Qlhs_83));
  (*X60Qlhs_83) = savedMainDir_0;
  nimStrWasMoved((&savedMainDir_0));
  string_0_sysvq0asl* X60Qlhs_84 = (&prog_0_prorcx25w1.main_0.name_0);
  nimStrDestroy((*X60Qlhs_84));
  (*X60Qlhs_84) = savedMainName_0;
  nimStrWasMoved((&savedMainName_0));
  string_0_sysvq0asl* X60Qlhs_85 = (&prog_0_prorcx25w1.main_0.ext_0);
  nimStrDestroy((*X60Qlhs_85));
  (*X60Qlhs_85) = savedMainExt_0;
  nimStrWasMoved((&savedMainExt_0));
  string_0_sysvq0asl strT_5 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl longT_5 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl borrowFn_1 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl allocFn_2 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl deallocFn_3 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_43 = toOpenArray_1_I6b60gk1_aow7lb5cq1(texts_4);
    NI32 X60Qlf_44 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1873 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_43);
        if (X60Qlf_44 < X60Qx_1873){
          {
            string_0_sysvq0asl* X60Qii_10 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_43, X60Qlf_44);
            NI32 X60Qx_1874 = len_4_sysvq0asl(strT_5);
            if (X60Qx_1874 == 0){
              nimStrDestroy(strT_5);
              string_0_sysvq0asl X60Qx_1875 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I17605077022815850042_aow7lb5cq1)}
              );
              strT_5 = X60Qx_1875;}
            NI32 X60Qx_1876 = len_4_sysvq0asl(longT_5);
            if (X60Qx_1876 == 0){
              nimStrDestroy(longT_5);
              string_0_sysvq0asl X60Qx_1877 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1852787966u, .more_0 = (&strlit_0_I15230512448378417494_aow7lb5cq1)}
              );
              longT_5 = X60Qx_1877;}
            NI32 X60Qx_1878 = len_4_sysvq0asl(borrowFn_1);
            if (X60Qx_1878 == 0){
              nimStrDestroy(borrowFn_1);
              string_0_sysvq0asl X60Qx_1879 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1919902462u, .more_0 = (&strlit_0_I9467484319694674619_aow7lb5cq1)}
              );
              borrowFn_1 = X60Qx_1879;}
            NI32 X60Qx_1880 = len_4_sysvq0asl(deallocFn_3);
            if (X60Qx_1880 == 0){
              nimStrDestroy(deallocFn_3);
              string_0_sysvq0asl X60Qx_1881 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1634034942u, .more_0 = (&strlit_0_I16718063019512574093_aow7lb5cq1)}
              );
              deallocFn_3 = X60Qx_1881;}
            NI32 X60Qx_1882 = len_4_sysvq0asl(allocFn_2);
            if (X60Qx_1882 == 0){
              nimStrDestroy(allocFn_2);
              string_0_sysvq0asl X60Qx_1883 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I5607995952013721966_aow7lb5cq1)}
              );
              allocFn_2 = X60Qx_1883;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_44));}
        else {
          break;}}}
    whileStmtLabel_9: ;}
  forStmtLabel_8: ;
  NI32 made_0 = 0;
  NI32 byExact_0 = 0;
  NI32 byBase_0 = 0;
  NI32 noBody_0 = 0;
  NI32 ambiguousMisses_0 = 0;
  string_0_sysvq0asl X60Qtmp_86 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 logDeclines_0 = eqQ_20_sysvq0asl(X60Qtmp_86, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  {
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_45 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_0);
    NI32 X60Qlf_46 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1884 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_45);
        if (X60Qlf_46 < X60Qx_1884){
          {
            {
              X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_14 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_45, X60Qlf_46);
              NB8 X60Qx_1885 = jitEligible_0_aow7lb5cq1((*X60Qii_14));
              if ((!X60Qx_1885)){
                if (logDeclines_0){
                  string_0_sysvq0asl X60Qdesugar_285 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                  string_0_sysvq0asl X60Qdesugar_286 = jitDeclineReason_0_aow7lb5cq1((*X60Qii_14));
                  NI32 X60Qx_1886 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1887 = len_4_sysvq0asl(X60Qdesugar_285);
                  NI32 X60Qx_1888 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                  );
                  NI32 X60Qx_1889 = len_4_sysvq0asl(X60Qdesugar_286);
                  NI32 X60Qx_1890 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I5568421909041685451_aow7lb5cq1)}
                  );
                  string_0_sysvq0asl X60Qdesugar_287 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1886 + X60Qx_1887)) + X60Qx_1888)) + X60Qx_1889)) + X60Qx_1890)));
                  add_2_sysvq0asl((&X60Qdesugar_287), (string_0_sysvq0asl){
                    .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_287), X60Qdesugar_285);
                  add_2_sysvq0asl((&X60Qdesugar_287), (string_0_sysvq0asl){
                    .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_287), X60Qdesugar_286);
                  add_2_sysvq0asl((&X60Qdesugar_287), (string_0_sysvq0asl){
                    .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I5568421909041685451_aow7lb5cq1)}
                  );
                  write_0_syn1lfpjv(stderr, X60Qdesugar_287);
                  nimStrDestroy(X60Qdesugar_287);
                  nimStrDestroy(X60Qdesugar_286);
                  nimStrDestroy(X60Qdesugar_285);}
                goto continueLabel_13;}
              NB8 X60Qx_1891;
              NB8 X60Qx_1892 = usesStrings_0_aow7lb5cq1((*X60Qii_14));
              if (X60Qx_1892){
                NB8 X60Qx_1893;
                NB8 X60Qx_1894;
                NI32 X60Qx_1895 = len_4_sysvq0asl(strT_5);
                if (X60Qx_1895 == 0){
                  X60Qx_1894 = NIM_TRUE;}
                else {
                  NI32 X60Qx_1896 = len_4_sysvq0asl(longT_5);
                  X60Qx_1894 = (X60Qx_1896 == 0);}
                if (X60Qx_1894){
                  X60Qx_1893 = NIM_TRUE;}
                else {
                  NI32 X60Qx_1897 = len_4_sysvq0asl(borrowFn_1);
                  X60Qx_1893 = (X60Qx_1897 == 0);}
                X60Qx_1891 = X60Qx_1893;}
              else {
                X60Qx_1891 = NIM_FALSE;}
              if (X60Qx_1891){
                if (logDeclines_0){
                  string_0_sysvq0asl X60Qdesugar_288 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                  NI32 X60Qx_1898 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1899 = len_4_sysvq0asl(X60Qdesugar_288);
                  NI32 X60Qx_1900 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 540680446u, .more_0 = (&strlit_0_I2902833179283423287_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1901 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1935763710u, .more_0 = (&strlit_0_I11009621119207680114_aow7lb5cq1)}
                  );
                  string_0_sysvq0asl X60Qdesugar_289 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1898 + X60Qx_1899)) + X60Qx_1900)) + X60Qx_1901)));
                  add_2_sysvq0asl((&X60Qdesugar_289), (string_0_sysvq0asl){
                    .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_289), X60Qdesugar_288);
                  add_2_sysvq0asl((&X60Qdesugar_289), (string_0_sysvq0asl){
                    .bytes_0 = 540680446u, .more_0 = (&strlit_0_I2902833179283423287_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_289), (string_0_sysvq0asl){
                    .bytes_0 = 1935763710u, .more_0 = (&strlit_0_I11009621119207680114_aow7lb5cq1)}
                  );
                  write_0_syn1lfpjv(stderr, X60Qdesugar_289);
                  nimStrDestroy(X60Qdesugar_289);
                  nimStrDestroy(X60Qdesugar_288);}
                goto continueLabel_13;}
              NB8 X60Qx_1902;
              NB8 X60Qx_1903 = usesSeqs_0_aow7lb5cq1((*X60Qii_14));
              if (X60Qx_1903){
                NB8 X60Qx_1904;
                NI32 X60Qx_1905 = len_4_sysvq0asl(allocFn_2);
                if (X60Qx_1905 == 0){
                  X60Qx_1904 = NIM_TRUE;}
                else {
                  NI32 X60Qx_1906 = len_4_sysvq0asl(deallocFn_3);
                  X60Qx_1904 = (X60Qx_1906 == 0);}
                X60Qx_1902 = X60Qx_1904;}
              else {
                X60Qx_1902 = NIM_FALSE;}
              if (X60Qx_1902){
                if (logDeclines_0){
                  string_0_sysvq0asl X60Qdesugar_290 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                  NI32 X60Qx_1907 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1908 = len_4_sysvq0asl(X60Qdesugar_290);
                  NI32 X60Qx_1909 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 540680446u, .more_0 = (&strlit_0_I16752411121828324346_aow7lb5cq1)}
                  );
                  NI32 X60Qx_1910 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1935763710u, .more_0 = (&strlit_0_I3740790232156408913_aow7lb5cq1)}
                  );
                  string_0_sysvq0asl X60Qdesugar_291 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1907 + X60Qx_1908)) + X60Qx_1909)) + X60Qx_1910)));
                  add_2_sysvq0asl((&X60Qdesugar_291), (string_0_sysvq0asl){
                    .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_291), X60Qdesugar_290);
                  add_2_sysvq0asl((&X60Qdesugar_291), (string_0_sysvq0asl){
                    .bytes_0 = 540680446u, .more_0 = (&strlit_0_I16752411121828324346_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_291), (string_0_sysvq0asl){
                    .bytes_0 = 1935763710u, .more_0 = (&strlit_0_I3740790232156408913_aow7lb5cq1)}
                  );
                  write_0_syn1lfpjv(stderr, X60Qdesugar_291);
                  nimStrDestroy(X60Qdesugar_291);
                  nimStrDestroy(X60Qdesugar_290);}
                goto continueLabel_13;}
              string_0_sysvq0asl X60Qii_15 = aowlcSymName_0_run8hsnpi((*(*X60Qii_14)).d_00.sym_0);
              NI32 X60Qii_16 = -1;
              string_0_sysvq0asl X60Qii_17 = (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              ;
              NI32 X60Qii_18 = 0;
              while (NIM_TRUE){
                NI32 X60Qx_1911 = len_3_Ixq6taz_aow7lb5cq1(texts_4);
                if (X60Qii_18 < X60Qx_1911){
                  NB8 X60Qx_1912;
                  NI32 X60Qx_1913 = len_4_sysvq0asl(X60Qii_15);
                  if (0 < X60Qx_1913){
                    string_0_sysvq0asl* X60Qx_1914 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                    NB8 X60Qx_1915 = definesExactly_0_aow7lb5cq1((*X60Qx_1914), X60Qii_15);
                    X60Qx_1912 = X60Qx_1915;}
                  else {
                    X60Qx_1912 = NIM_FALSE;}
                  if (X60Qx_1912){
                    X60Qii_16 = X60Qii_18;
                    nimStrDestroy(X60Qii_17);
                    string_0_sysvq0asl X60Qx_1916 = nimStrDup(X60Qii_15);
                    X60Qii_17 = X60Qx_1916;
                    break;}
                  inc_1_I6wjjge_aow2h993l1((&X60Qii_18));}
                else {
                  break;}}
              NB8 X60Qx_1917;
              if (X60Qii_16 < 0){
                NI32 X60Qx_1918 = len_4_sysvq0asl(X60Qii_15);
                X60Qx_1917 = (X60Qx_1918 == 0);}
              else {
                X60Qx_1917 = NIM_FALSE;}
              if (X60Qx_1917){
                string_0_sysvq0asl X60Qii_19 = (string_0_sysvq0asl){
                  .bytes_0 = 0u, .more_0 = NIM_NIL}
                ;
                NI32 X60Qii_20 = -1;
                NB8 X60Qii_21 = NIM_FALSE;
                X60Qii_18 = 0;
                while (NIM_TRUE){
                  NI32 X60Qx_1919 = len_3_Ixq6taz_aow7lb5cq1(texts_4);
                  if (X60Qii_18 < X60Qx_1919){
                    string_0_sysvq0asl* X60Qx_1920 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qii_22 = mangledNamesFor_0_aow7lb5cq1((*X60Qx_1920), (*(*X60Qii_14)).d_00.base_0);
                    NI32 X60Qii_23 = 0;
                    while (NIM_TRUE){
                      NI32 X60Qx_1921 = len_3_Ixq6taz_aow7lb5cq1(X60Qii_22);
                      if (X60Qii_23 < X60Qx_1921){
                        NI32 X60Qx_1922 = len_4_sysvq0asl(X60Qii_19);
                        if (X60Qx_1922 == 0){
                          nimStrDestroy(X60Qii_19);
                          string_0_sysvq0asl* X60Qx_1923 = getQ_7_Ir6d0tw_aow7lb5cq1(X60Qii_22, X60Qii_23);
                          string_0_sysvq0asl X60Qx_1924 = nimStrDup((*X60Qx_1923));
                          X60Qii_19 = X60Qx_1924;
                          X60Qii_20 = X60Qii_18;}
                        else {
                          string_0_sysvq0asl* X60Qx_1925 = getQ_7_Ir6d0tw_aow7lb5cq1(X60Qii_22, X60Qii_23);
                          NB8 X60Qx_1926 = eqQ_20_sysvq0asl((*X60Qx_1925), X60Qii_19);
                          if ((!X60Qx_1926)){
                            X60Qii_21 = NIM_TRUE;}}
                        inc_1_I6wjjge_aow2h993l1((&X60Qii_23));}
                      else {
                        break;}}
                    inc_1_I6wjjge_aow2h993l1((&X60Qii_18));
                    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qii_22);}
                  else {
                    break;}}
                NB8 X60Qx_1927;
                NI32 X60Qx_1928 = len_4_sysvq0asl(X60Qii_19);
                if (0 < X60Qx_1928){
                  X60Qx_1927 = (!X60Qii_21);}
                else {
                  X60Qx_1927 = NIM_FALSE;}
                if (X60Qx_1927){
                  X60Qii_16 = X60Qii_20;
                  nimStrDestroy(X60Qii_17);
                  X60Qii_17 = X60Qii_19;
                  nimStrWasMoved((&X60Qii_19));
                  inc_1_I6wjjge_aow2h993l1((&byBase_0));}
                else {
                  if (X60Qii_21){
                    inc_1_I6wjjge_aow2h993l1((&ambiguousMisses_0));
                    string_0_sysvq0asl X60Qtmp_87 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
                      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 0u, .more_0 = NIM_NIL}
                    );
                    NB8 X60Qx_1929 = eqQ_20_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
                      .bytes_0 = 12545u, .more_0 = NIM_NIL}
                    );
                    if (X60Qx_1929){
                      string_0_sysvq0asl X60Qdesugar_292 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                      NI32 X60Qx_1930 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1931 = len_4_sysvq0asl(X60Qdesugar_292);
                      NI32 X60Qx_1932 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1933 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I9306212446656051791_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1934 = len_4_sysvq0asl(X60Qii_15);
                      NI32 X60Qx_1935 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I13430982929222912407_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_293 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1930 + X60Qx_1931)) + X60Qx_1932)) + X60Qx_1933)) + X60Qx_1934)) + X60Qx_1935)));
                      add_2_sysvq0asl((&X60Qdesugar_293), (string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_293), X60Qdesugar_292);
                      add_2_sysvq0asl((&X60Qdesugar_293), (string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_293), (string_0_sysvq0asl){
                        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I9306212446656051791_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_293), X60Qii_15);
                      add_2_sysvq0asl((&X60Qdesugar_293), (string_0_sysvq0asl){
                        .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I13430982929222912407_aow7lb5cq1)}
                      );
                      write_0_syn1lfpjv(stderr, X60Qdesugar_293);
                      nimStrDestroy(X60Qdesugar_293);
                      nimStrDestroy(X60Qdesugar_292);}
                    nimStrDestroy(X60Qtmp_87);}
                  else {
                    inc_1_I6wjjge_aow2h993l1((&noBody_0));
                    string_0_sysvq0asl X60Qtmp_88 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
                      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 0u, .more_0 = NIM_NIL}
                    );
                    NB8 X60Qx_1936 = eqQ_20_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
                      .bytes_0 = 12545u, .more_0 = NIM_NIL}
                    );
                    if (X60Qx_1936){
                      string_0_sysvq0asl X60Qdesugar_294 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                      NI32 X60Qx_1937 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1938 = len_4_sysvq0asl(X60Qdesugar_294);
                      NI32 X60Qx_1939 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1940 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I4639961614947029451_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_295 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1937 + X60Qx_1938)) + X60Qx_1939)) + X60Qx_1940)));
                      add_2_sysvq0asl((&X60Qdesugar_295), (string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_295), X60Qdesugar_294);
                      add_2_sysvq0asl((&X60Qdesugar_295), (string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_295), (string_0_sysvq0asl){
                        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I4639961614947029451_aow7lb5cq1)}
                      );
                      write_0_syn1lfpjv(stderr, X60Qdesugar_295);
                      nimStrDestroy(X60Qdesugar_295);
                      nimStrDestroy(X60Qdesugar_294);}
                    nimStrDestroy(X60Qtmp_88);}}
                nimStrDestroy(X60Qii_19);}
              else {
                if (X60Qii_16 < 0){
                  inc_1_I6wjjge_aow2h993l1((&noBody_0));
                  string_0_sysvq0asl X60Qtmp_89 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
                    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  );
                  NB8 X60Qx_1941 = eqQ_20_sysvq0asl(X60Qtmp_89, (string_0_sysvq0asl){
                    .bytes_0 = 12545u, .more_0 = NIM_NIL}
                  );
                  if (X60Qx_1941){
                    string_0_sysvq0asl X60Qdesugar_296 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                    NI32 X60Qx_1942 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1943 = len_4_sysvq0asl(X60Qdesugar_296);
                    NI32 X60Qx_1944 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1945 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I9306212446656051791_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1946 = len_4_sysvq0asl(X60Qii_15);
                    NI32 X60Qx_1947 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1680351486u, .more_0 = (&strlit_0_I14045175378979266023_aow7lb5cq1)}
                    );
                    string_0_sysvq0asl X60Qdesugar_297 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1942 + X60Qx_1943)) + X60Qx_1944)) + X60Qx_1945)) + X60Qx_1946)) + X60Qx_1947)));
                    add_2_sysvq0asl((&X60Qdesugar_297), (string_0_sysvq0asl){
                      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_297), X60Qdesugar_296);
                    add_2_sysvq0asl((&X60Qdesugar_297), (string_0_sysvq0asl){
                      .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_297), (string_0_sysvq0asl){
                      .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I9306212446656051791_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_297), X60Qii_15);
                    add_2_sysvq0asl((&X60Qdesugar_297), (string_0_sysvq0asl){
                      .bytes_0 = 1680351486u, .more_0 = (&strlit_0_I14045175378979266023_aow7lb5cq1)}
                    );
                    write_0_syn1lfpjv(stderr, X60Qdesugar_297);
                    nimStrDestroy(X60Qdesugar_297);
                    nimStrDestroy(X60Qdesugar_296);}
                  nimStrDestroy(X60Qtmp_89);}
                else {
                  inc_1_I6wjjge_aow2h993l1((&byExact_0));}}
              X60Qii_18 = X60Qii_16;
              {
                NI32 X60Qx_1948 = len_4_sysvq0asl(X60Qii_17);
                if (0 < X60Qx_1948){
                  string_0_sysvq0asl* X60Qx_1949 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                  CSig_0_aow7lb5cq1 X60Qtmp_90 = sigOf_0_aow7lb5cq1((*X60Qx_1949), X60Qii_17);
                  string_0_sysvq0asl* X60Qx_1950 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                  string_0_sysvq0asl X60Qii_24 = emitCShim_0_aow7lb5cq1((*X60Qii_14), X60Qii_17, strT_5, longT_5, allocFn_2, deallocFn_3, X60Qtmp_90, (*X60Qx_1950));
                  NI32 X60Qx_1951 = len_4_sysvq0asl(X60Qii_24);
                  if (X60Qx_1951 == 0){
                    string_0_sysvq0asl X60Qtmp_91 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
                      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 0u, .more_0 = NIM_NIL}
                    );
                    NB8 X60Qx_1952 = eqQ_20_sysvq0asl(X60Qtmp_91, (string_0_sysvq0asl){
                      .bytes_0 = 12545u, .more_0 = NIM_NIL}
                    );
                    if (X60Qx_1952){
                      string_0_sysvq0asl X60Qii_25 = (string_0_sysvq0asl){
                        .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I9361295413614208495_aow7lb5cq1)}
                      ;
                      {
                        openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_47 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*(*X60Qii_14)).d_00.args_0);
                        NI32 X60Qlf_48 = 0;
                        {
                          while (NIM_TRUE){
                            NI32 X60Qx_1953 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_47);
                            if (X60Qlf_48 < X60Qx_1953){
                              {
                                WireField_0_run8hsnpi* X60Qii_28 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_47, X60Qlf_48);
                                NB8 X60Qx_1954;
                                if ((*X60Qii_28).isComposite_0){
                                  X60Qx_1954 = (!((*X60Qii_28).desc_0 == NIM_NIL));}
                                else {
                                  X60Qx_1954 = NIM_FALSE;}
                                if (X60Qx_1954){
                                  string_0_sysvq0asl X60Qii_29 = compositeWhyNot_1_aow7lb5cq1((*X60Qii_28).desc_0, 0);
                                  NI32 X60Qx_1955 = len_4_sysvq0asl(X60Qii_29);
                                  if (0 < X60Qx_1955){
                                    nimStrDestroy(X60Qii_25);
                                    string_0_sysvq0asl X60Qx_1956 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                                      .bytes_0 = 544104958u, .more_0 = (&strlit_0_I2584675443025991433_aow7lb5cq1)}
                                    , X60Qii_29);
                                    X60Qii_25 = X60Qx_1956;}
                                  nimStrDestroy(X60Qii_29);}}
                              inc_1_I6wjjge_aow2h993l1((&X60Qlf_48));}
                            else {
                              break;}}}
                        whileStmtLabel_27: ;}
                      forStmtLabel_26: ;
                      NB8 X60Qx_1957;
                      NB8 X60Qx_1958;
                      if ((!(*(*X60Qii_14)).d_00.retVoid_0)){
                        X60Qx_1958 = (*(*X60Qii_14)).d_00.ret_0.isComposite_0;}
                      else {
                        X60Qx_1958 = NIM_FALSE;}
                      if (X60Qx_1958){
                        X60Qx_1957 = (!((*(*X60Qii_14)).d_00.ret_0.desc_0 == NIM_NIL));}
                      else {
                        X60Qx_1957 = NIM_FALSE;}
                      if (X60Qx_1957){
                        string_0_sysvq0asl X60Qii_30 = compositeWhyNot_1_aow7lb5cq1((*(*X60Qii_14)).d_00.ret_0.desc_0, 0);
                        NI32 X60Qx_1959 = len_4_sysvq0asl(X60Qii_30);
                        if (0 < X60Qx_1959){
                          nimStrDestroy(X60Qii_25);
                          string_0_sysvq0asl X60Qx_1960 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I12438589081047852308_aow7lb5cq1)}
                          , X60Qii_30);
                          X60Qii_25 = X60Qx_1960;}
                        nimStrDestroy(X60Qii_30);}
                      string_0_sysvq0asl X60Qdesugar_298 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                      NI32 X60Qx_1961 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1962 = len_4_sysvq0asl(X60Qdesugar_298);
                      NI32 X60Qx_1963 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1964 = len_4_sysvq0asl(X60Qii_25);
                      NI32 X60Qx_1965 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2561u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_299 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1961 + X60Qx_1962)) + X60Qx_1963)) + X60Qx_1964)) + X60Qx_1965)));
                      add_2_sysvq0asl((&X60Qdesugar_299), (string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_299), X60Qdesugar_298);
                      add_2_sysvq0asl((&X60Qdesugar_299), (string_0_sysvq0asl){
                        .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_299), X60Qii_25);
                      add_2_sysvq0asl((&X60Qdesugar_299), (string_0_sysvq0asl){
                        .bytes_0 = 2561u, .more_0 = NIM_NIL}
                      );
                      write_0_syn1lfpjv(stderr, X60Qdesugar_299);
                      nimStrDestroy(X60Qdesugar_299);
                      nimStrDestroy(X60Qdesugar_298);
                      nimStrDestroy(X60Qii_25);}
                    nimStrDestroy(X60Qtmp_91);
                    nimStrDestroy(X60Qii_24);
                    eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(X60Qtmp_90);
                    goto emitOne_0;
                    nimStrDestroy(X60Qtmp_91);}
                  string_0_sysvq0asl* X60Qx_1966 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                  NB8 X60Qx_1967 = hasSub_0_aow7lb5cq1((*X60Qx_1966), (string_0_sysvq0asl){
                    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I2513678243287852030_aow7lb5cq1)}
                  );
                  if ((!X60Qx_1967)){
                    string_0_sysvq0asl* X60Qx_1968 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                    add_2_sysvq0asl(X60Qx_1968, (string_0_sysvq0asl){
                      .bytes_0 = 707726078u, .more_0 = (&strlit_0_I10597374192599734484_aow7lb5cq1)}
                    );}
                  NB8 X60Qx_1969;
                  string_0_sysvq0asl* X60Qx_1970 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                  NB8 X60Qx_1971 = hasSub_0_aow7lb5cq1((*X60Qx_1970), (string_0_sysvq0asl){
                    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3443046107169670104_aow7lb5cq1)}
                  );
                  if ((!X60Qx_1971)){
                    NB8 X60Qx_1972 = usesStrings_0_aow7lb5cq1((*X60Qii_14));
                    X60Qx_1969 = X60Qx_1972;}
                  else {
                    X60Qx_1969 = NIM_FALSE;}
                  if (X60Qx_1969){
                    string_0_sysvq0asl X60Qtmp_92 = ampQ_0_sysvq0asl(borrowFn_1, (string_0_sysvq0asl){
                      .bytes_0 = 10241u, .more_0 = NIM_NIL}
                    );
                    string_0_sysvq0asl* X60Qx_1973 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                    NB8 X60Qx_1974 = hasSub_0_aow7lb5cq1((*X60Qx_1973), X60Qtmp_92);
                    if ((!X60Qx_1974)){
                      NI32 X60Qx_1975 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2019887870u, .more_0 = (&strlit_0_I2317332660687858480_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1976 = len_4_sysvq0asl(strT_5);
                      NI32 X60Qx_1977 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1978 = len_4_sysvq0asl(borrowFn_1);
                      NI32 X60Qx_1979 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1853171966u, .more_0 = (&strlit_0_I16715136830670315920_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_300 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1975 + X60Qx_1976)) + X60Qx_1977)) + X60Qx_1978)) + X60Qx_1979)));
                      add_2_sysvq0asl((&X60Qdesugar_300), (string_0_sysvq0asl){
                        .bytes_0 = 2019887870u, .more_0 = (&strlit_0_I2317332660687858480_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_300), strT_5);
                      add_2_sysvq0asl((&X60Qdesugar_300), (string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_300), borrowFn_1);
                      add_2_sysvq0asl((&X60Qdesugar_300), (string_0_sysvq0asl){
                        .bytes_0 = 1853171966u, .more_0 = (&strlit_0_I16715136830670315920_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl* X60Qx_1980 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                      add_2_sysvq0asl(X60Qx_1980, X60Qdesugar_300);
                      nimStrDestroy(X60Qdesugar_300);}
                    string_0_sysvq0asl X60Qtmp_93 = strHelpers_0_aow7lb5cq1(strT_5, longT_5, borrowFn_1);
                    string_0_sysvq0asl* X60Qx_1981 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                    add_2_sysvq0asl(X60Qx_1981, X60Qtmp_93);
                    nimStrDestroy(X60Qtmp_93);
                    nimStrDestroy(X60Qtmp_92);}
                  NB8 X60Qx_46;
                  NB8 X60Qx_1982 = usesSeqs_0_aow7lb5cq1((*X60Qii_14));
                  if (X60Qx_1982){
                    string_0_sysvq0asl X60Qtmp_94 = ampQ_0_sysvq0asl(allocFn_2, (string_0_sysvq0asl){
                      .bytes_0 = 10241u, .more_0 = NIM_NIL}
                    );
                    string_0_sysvq0asl* X60Qx_1983 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                    NB8 X60Qx_1984 = hasSub_0_aow7lb5cq1((*X60Qx_1983), X60Qtmp_94);
                    X60Qx_46 = (!X60Qx_1984);
                    nimStrDestroy(X60Qtmp_94);}
                  else {
                    X60Qx_46 = NIM_FALSE;}
                  if (X60Qx_46){
                    NI32 X60Qx_1985 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 2019887870u, .more_0 = (&strlit_0_I3018204930238191970_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1986 = len_4_sysvq0asl(allocFn_2);
                    NI32 X60Qx_1987 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1869359358u, .more_0 = (&strlit_0_I13922026781561364508_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1988 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I16286562635260071850_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1989 = len_4_sysvq0asl(deallocFn_3);
                    NI32 X60Qx_1990 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I4552606806654256453_aow7lb5cq1)}
                    );
                    string_0_sysvq0asl X60Qdesugar_301 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1985 + X60Qx_1986)) + X60Qx_1987)) + X60Qx_1988)) + X60Qx_1989)) + X60Qx_1990)));
                    add_2_sysvq0asl((&X60Qdesugar_301), (string_0_sysvq0asl){
                      .bytes_0 = 2019887870u, .more_0 = (&strlit_0_I3018204930238191970_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_301), allocFn_2);
                    add_2_sysvq0asl((&X60Qdesugar_301), (string_0_sysvq0asl){
                      .bytes_0 = 1869359358u, .more_0 = (&strlit_0_I13922026781561364508_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_301), (string_0_sysvq0asl){
                      .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I16286562635260071850_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_301), deallocFn_3);
                    add_2_sysvq0asl((&X60Qdesugar_301), (string_0_sysvq0asl){
                      .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I4552606806654256453_aow7lb5cq1)}
                    );
                    string_0_sysvq0asl* X60Qx_1991 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                    add_2_sysvq0asl(X60Qx_1991, X60Qdesugar_301);
                    nimStrDestroy(X60Qdesugar_301);}
                  string_0_sysvq0asl* X60Qx_1992 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, X60Qii_18);
                  add_2_sysvq0asl(X60Qx_1992, X60Qii_24);
                  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_1993 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1((*X60Qii_14));
                  add_0_I9iil5u_aow7lb5cq1(shimmed_0, X60Qx_1993);
                  inc_1_I6wjjge_aow2h993l1((&made_0));
                  nimStrDestroy(X60Qii_24);
                  eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(X60Qtmp_90);}}
              emitOne_0: ;
              nimStrDestroy(X60Qii_17);
              nimStrDestroy(X60Qii_15);}
            continueLabel_13: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_46));}
        else {
          break;}}}
    whileStmtLabel_12: ;}
  forStmtLabel_11: ;
  string_0_sysvq0asl X60Qtmp_95 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_1994 = eqQ_20_sysvq0asl(X60Qtmp_95, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  if (X60Qx_1994){
    string_0_sysvq0asl X60Qdesugar_302 = dollarQ_2_sysvq0asl(made_0);
    string_0_sysvq0asl X60Qdesugar_303 = dollarQ_2_sysvq0asl(byExact_0);
    string_0_sysvq0asl X60Qdesugar_304 = dollarQ_2_sysvq0asl(byBase_0);
    string_0_sysvq0asl X60Qdesugar_305 = dollarQ_2_sysvq0asl(noBody_0);
    string_0_sysvq0asl X60Qdesugar_306 = dollarQ_2_sysvq0asl(ambiguousMisses_0);
    NI32 X60Qx_1995 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I11456809569861300725_aow7lb5cq1)}
    );
    NI32 X60Qx_1996 = len_4_sysvq0asl(X60Qdesugar_302);
    NI32 X60Qx_1997 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1697128702u, .more_0 = (&strlit_0_I17792640634769934702_aow7lb5cq1)}
    );
    NI32 X60Qx_1998 = len_4_sysvq0asl(X60Qdesugar_303);
    NI32 X60Qx_1999 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I18342294718160420153_aow7lb5cq1)}
    );
    NI32 X60Qx_2000 = len_4_sysvq0asl(X60Qdesugar_304);
    NI32 X60Qx_2001 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1847601662u, .more_0 = (&strlit_0_I172984808378442068_aow7lb5cq1)}
    );
    NI32 X60Qx_2002 = len_4_sysvq0asl(X60Qdesugar_305);
    NI32 X60Qx_2003 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1835081982u, .more_0 = (&strlit_0_I14472242329998166714_aow7lb5cq1)}
    );
    NI32 X60Qx_2004 = len_4_sysvq0asl(X60Qdesugar_306);
    NI32 X60Qx_2005 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_307 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1995 + X60Qx_1996)) + X60Qx_1997)) + X60Qx_1998)) + X60Qx_1999)) + X60Qx_2000)) + X60Qx_2001)) + X60Qx_2002)) + X60Qx_2003)) + X60Qx_2004)) + X60Qx_2005)));
    add_2_sysvq0asl((&X60Qdesugar_307), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I11456809569861300725_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_307), X60Qdesugar_302);
    add_2_sysvq0asl((&X60Qdesugar_307), (string_0_sysvq0asl){
      .bytes_0 = 1697128702u, .more_0 = (&strlit_0_I17792640634769934702_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_307), X60Qdesugar_303);
    add_2_sysvq0asl((&X60Qdesugar_307), (string_0_sysvq0asl){
      .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I18342294718160420153_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_307), X60Qdesugar_304);
    add_2_sysvq0asl((&X60Qdesugar_307), (string_0_sysvq0asl){
      .bytes_0 = 1847601662u, .more_0 = (&strlit_0_I172984808378442068_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_307), X60Qdesugar_305);
    add_2_sysvq0asl((&X60Qdesugar_307), (string_0_sysvq0asl){
      .bytes_0 = 1835081982u, .more_0 = (&strlit_0_I14472242329998166714_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_307), X60Qdesugar_306);
    add_2_sysvq0asl((&X60Qdesugar_307), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_307);
    nimStrDestroy(X60Qdesugar_307);
    nimStrDestroy(X60Qdesugar_306);
    nimStrDestroy(X60Qdesugar_305);
    nimStrDestroy(X60Qdesugar_304);
    nimStrDestroy(X60Qdesugar_303);
    nimStrDestroy(X60Qdesugar_302);}
  NB8 X60Qx_2006;
  if (made_0 == 0){
    X60Qx_2006 = (!wholeProgram_0);}
  else {
    X60Qx_2006 = NIM_FALSE;}
  if (X60Qx_2006){
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  seq_0_Ixdx2fh1_aow7lb5cq1 files_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 objs_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  NI32 recompiled_0 = 0;
  NI32 w_10 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_2007 = len_3_Ixq6taz_aow7lb5cq1(texts_4);
      if (w_10 < X60Qx_2007){
        string_0_sysvq0asl X60Qdesugar_308 = dollarQ_2_sysvq0asl(w_10);
        NI32 X60Qx_2008 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I8179081380582823378_aow7lb5cq1)}
        );
        NI32 X60Qx_2009 = len_4_sysvq0asl(X60Qdesugar_308);
        NI32 X60Qx_2010 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 6499842u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_309 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2008 + X60Qx_2009)) + X60Qx_2010)));
        add_2_sysvq0asl((&X60Qdesugar_309), (string_0_sysvq0asl){
          .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I8179081380582823378_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_309), X60Qdesugar_308);
        add_2_sysvq0asl((&X60Qdesugar_309), (string_0_sysvq0asl){
          .bytes_0 = 6499842u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl p_2 = slashQ_0_ospaexnw61(buildDir_2, X60Qdesugar_309);
        string_0_sysvq0asl X60Qdesugar_310 = dollarQ_2_sysvq0asl(w_10);
        NI32 X60Qx_2011 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I8179081380582823378_aow7lb5cq1)}
        );
        NI32 X60Qx_2012 = len_4_sysvq0asl(X60Qdesugar_310);
        NI32 X60Qx_2013 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 7286274u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_311 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2011 + X60Qx_2012)) + X60Qx_2013)));
        add_2_sysvq0asl((&X60Qdesugar_311), (string_0_sysvq0asl){
          .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I8179081380582823378_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_311), X60Qdesugar_310);
        add_2_sysvq0asl((&X60Qdesugar_311), (string_0_sysvq0asl){
          .bytes_0 = 7286274u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl o_1 = slashQ_0_ospaexnw61(buildDir_2, X60Qdesugar_311);
        string_0_sysvq0asl* X60Qx_2014 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_4, w_10);
        string_0_sysvq0asl X60Qdesugar_312 = nimStrDup((*X60Qx_2014));
        NI32 X60Qx_2015 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 539635710u, .more_0 = (&strlit_0_I15752602684027218635_aow7lb5cq1)}
        );
        NI32 X60Qx_2016 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_2017 = len_4_sysvq0asl(X60Qdesugar_312);
        NI32 X60Qx_2018 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_313 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_2015 + X60Qx_2016)) + X60Qx_2017)) + X60Qx_2018)));
        add_2_sysvq0asl((&X60Qdesugar_313), (string_0_sysvq0asl){
          .bytes_0 = 539635710u, .more_0 = (&strlit_0_I15752602684027218635_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_313), (string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_313), X60Qdesugar_312);
        add_2_sysvq0asl((&X60Qdesugar_313), (string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl body_6 = X60Qdesugar_313;
        nimStrWasMoved((&X60Qdesugar_313));
        NB8 changed_0 = writeIfChanged_0_aow7lb5cq1(p_2, body_6);
        string_0_sysvq0asl X60Qx_2019 = nimStrDup(p_2);
        add_0_Ig6072n_aow7lb5cq1((&files_0), X60Qx_2019);
        string_0_sysvq0asl X60Qx_2020 = nimStrDup(o_1);
        add_0_Ig6072n_aow7lb5cq1((&objs_0), X60Qx_2020);
        NB8 X60Qx_2021;
        if (changed_0){
          X60Qx_2021 = NIM_TRUE;}
        else {
          NB8 X60Qx_2022 = fileExists_0_osc4bsu0d1(o_1);
          X60Qx_2021 = (!X60Qx_2022);}
        if (X60Qx_2021){
          NB8 X60Qx_2023 = gccCompileOne_0_aow7lb5cq1(p_2, o_1, logFile_5);
          if ((!X60Qx_2023)){
            eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
            seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2024 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
            objs_0 = X60Qx_2024;
            nimStrDestroy(body_6);
            nimStrDestroy(X60Qdesugar_313);
            nimStrDestroy(X60Qdesugar_312);
            nimStrDestroy(o_1);
            nimStrDestroy(X60Qdesugar_311);
            nimStrDestroy(X60Qdesugar_310);
            nimStrDestroy(p_2);
            nimStrDestroy(X60Qdesugar_309);
            nimStrDestroy(X60Qdesugar_308);
            goto whileStmtLabel_31;}
          inc_1_I6wjjge_aow2h993l1((&recompiled_0));}
        inc_1_I6wjjge_aow2h993l1((&w_10));
        nimStrDestroy(body_6);
        nimStrDestroy(X60Qdesugar_313);
        nimStrDestroy(X60Qdesugar_312);
        nimStrDestroy(o_1);
        nimStrDestroy(X60Qdesugar_311);
        nimStrDestroy(X60Qdesugar_310);
        nimStrDestroy(p_2);
        nimStrDestroy(X60Qdesugar_309);
        nimStrDestroy(X60Qdesugar_308);}
      else {
        break;}}}
  whileStmtLabel_31: ;
  string_0_sysvq0asl initC_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I5350979616169502278_aow7lb5cq1)}
  );
  seq_0_Ixdx2fh1_aow7lb5cq1 nativeExports_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_49 = toOpenArray_1_I6b60gk1_aow7lb5cq1(texts_4);
    NI32 X60Qlf_50 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_2025 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_49);
        if (X60Qlf_50 < X60Qx_2025){
          {
            string_0_sysvq0asl* X60Qii_34 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_49, X60Qlf_50);
            NI32 X60Qii_35 = subAt_0_aow7lb5cq1((*X60Qii_34), (string_0_sysvq0asl){
              .bytes_0 = 1936026366u, .more_0 = (&strlit_0_I16159220003410283764_aow7lb5cq1)}
            , 0);
            while (0 <= X60Qii_35){
              NI32 X60Qii_36 = X60Qii_35;
              while (NIM_TRUE){
                NB8 X60Qx_2026;
                NI32 X60Qx_2027 = len_4_sysvq0asl((*X60Qii_34));
                if (X60Qii_36 < X60Qx_2027){
                  NC8 X60Qx_2028 = getQ_9_sysvq0asl((*X60Qii_34), X60Qii_36);
                  NB8 X60Qx_2029 = isIdentChar_0_aow7lb5cq1(X60Qx_2028);
                  X60Qx_2026 = X60Qx_2029;}
                else {
                  X60Qx_2026 = NIM_FALSE;}
                if (X60Qx_2026){
                  inc_1_I6wjjge_aow2h993l1((&X60Qii_36));}
                else {
                  break;}}
              HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_2030 = __ltQ_1_Ij9jwi_aow7lb5cq1(X60Qii_35, X60Qii_36);
              string_0_sysvq0asl X60Qii_37 = getQ_14_sysvq0asl((*X60Qii_34), X60Qx_2030);
              NB8 X60Qii_38 = NIM_FALSE;
              {
                openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_51 = toOpenArray_1_I6b60gk1_aow7lb5cq1(nativeExports_0);
                NI32 X60Qlf_52 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_2031 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_51);
                    if (X60Qlf_52 < X60Qx_2031){
                      {
                        string_0_sysvq0asl* X60Qii_41 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_51, X60Qlf_52);
                        NB8 X60Qx_2032 = eqQ_20_sysvq0asl((*X60Qii_41), X60Qii_37);
                        if (X60Qx_2032){
                          X60Qii_38 = NIM_TRUE;}}
                      inc_1_I6wjjge_aow2h993l1((&X60Qlf_52));}
                    else {
                      break;}}}
                whileStmtLabel_40: ;}
              forStmtLabel_39: ;
              if ((!X60Qii_38)){
                string_0_sysvq0asl X60Qtmp_96 = X60Qii_37;
                nimStrWasMoved((&X60Qii_37));
                add_0_Ig6072n_aow7lb5cq1((&nativeExports_0), X60Qtmp_96);}
              NI32 X60Qx_2033 = subAt_0_aow7lb5cq1((*X60Qii_34), (string_0_sysvq0asl){
                .bytes_0 = 1936026366u, .more_0 = (&strlit_0_I16159220003410283764_aow7lb5cq1)}
              , X60Qii_36);
              X60Qii_35 = X60Qx_2033;
              nimStrDestroy(X60Qii_37);}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_50));}
        else {
          break;}}}
    whileStmtLabel_33: ;}
  forStmtLabel_32: ;
  string_0_sysvq0asl exportDecls_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_53 = toOpenArray_1_I6b60gk1_aow7lb5cq1(nativeExports_0);
    NI32 X60Qlf_54 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_2034 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_53);
        if (X60Qlf_54 < X60Qx_2034){
          {
            string_0_sysvq0asl* X60Qii_44 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_53, X60Qlf_54);
            string_0_sysvq0asl X60Qdesugar_314 = nimStrDup((*X60Qii_44));
            NI32 X60Qx_2035 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1718166526u, .more_0 = (&strlit_0_I12714862762194711353_aow7lb5cq1)}
            );
            NI32 X60Qx_2036 = len_4_sysvq0asl(X60Qdesugar_314);
            NI32 X60Qx_2037 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I2451862973728995994_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_315 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2035 + X60Qx_2036)) + X60Qx_2037)));
            add_2_sysvq0asl((&X60Qdesugar_315), (string_0_sysvq0asl){
              .bytes_0 = 1718166526u, .more_0 = (&strlit_0_I12714862762194711353_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_315), X60Qdesugar_314);
            add_2_sysvq0asl((&X60Qdesugar_315), (string_0_sysvq0asl){
              .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I2451862973728995994_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&exportDecls_0), X60Qdesugar_315);
            nimStrDestroy(X60Qdesugar_315);
            nimStrDestroy(X60Qdesugar_314);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_54));}
        else {
          break;}}}
    whileStmtLabel_43: ;}
  forStmtLabel_42: ;
  string_0_sysvq0asl defBody_0 = (string_0_sysvq0asl){
    .bytes_0 = 1112100094u, .more_0 = (&strlit_0_I8659447081661426280_aow7lb5cq1)}
  ;
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_55 = toOpenArray_1_I6b60gk1_aow7lb5cq1(nativeExports_0);
    NI32 X60Qlf_56 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_2038 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_55);
        if (X60Qlf_56 < X60Qx_2038){
          {
            string_0_sysvq0asl* X60Qii_47 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_55, X60Qlf_56);
            string_0_sysvq0asl X60Qtmp_97 = ampQ_0_sysvq0asl((*X60Qii_47), (string_0_sysvq0asl){
              .bytes_0 = 2561u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&defBody_0), X60Qtmp_97);
            nimStrDestroy(X60Qtmp_97);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_56));}
        else {
          break;}}}
    whileStmtLabel_46: ;}
  forStmtLabel_45: ;
  string_0_sysvq0asl X60Qtmp_98 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3392786984146350459_aow7lb5cq1)}
  );
  ErrorCode_0_sysvq0asl X60QcanRaise_4 = writeFile_0_syn1lfpjv(X60Qtmp_98, defBody_0);
  if (X60QcanRaise_4){
    nimStrDestroy(X60Qtmp_98);
    goto X60Qexlab_12;}
  nimStrDestroy(X60Qtmp_98);
  if (NIM_FALSE){
    X60Qexlab_12: ;}
  string_0_sysvq0asl X60Qx_2039 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3392786984146350459_aow7lb5cq1)}
  );
  add_0_Ig6072n_aow7lb5cq1((&files_0), X60Qx_2039);
  NI32 X60Qx_2040 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I6929186202351031481_aow7lb5cq1)}
  );
  NI32 X60Qx_2041 = len_4_sysvq0asl(exportDecls_0);
  NI32 X60Qx_2042 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1718166526u, .more_0 = (&strlit_0_I8164311879278760128_aow7lb5cq1)}
  );
  NI32 X60Qx_2043 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I16378428795907340016_aow7lb5cq1)}
  );
  NI32 X60Qx_2044 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I12606525818129378590_aow7lb5cq1)}
  );
  NI32 X60Qx_2045 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I3706874824641185916_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_316 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_2040 + X60Qx_2041)) + X60Qx_2042)) + X60Qx_2043)) + X60Qx_2044)) + X60Qx_2045)));
  add_2_sysvq0asl((&X60Qdesugar_316), (string_0_sysvq0asl){
    .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I6929186202351031481_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_316), exportDecls_0);
  add_2_sysvq0asl((&X60Qdesugar_316), (string_0_sysvq0asl){
    .bytes_0 = 1718166526u, .more_0 = (&strlit_0_I8164311879278760128_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_316), (string_0_sysvq0asl){
    .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I16378428795907340016_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_316), (string_0_sysvq0asl){
    .bytes_0 = 1635021822u, .more_0 = (&strlit_0_I12606525818129378590_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_316), (string_0_sysvq0asl){
    .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I3706874824641185916_aow7lb5cq1)}
  );
  string_0_sysvq0asl initBody_0 = X60Qdesugar_316;
  nimStrWasMoved((&X60Qdesugar_316));
  NB8 X60Qx_2046 = writeIfChanged_0_aow7lb5cq1(initC_0, initBody_0);
  if (X60Qx_2046){
    }
  string_0_sysvq0asl X60Qx_2047 = nimStrDup(initC_0);
  add_0_Ig6072n_aow7lb5cq1((&files_0), X60Qx_2047);
  string_0_sysvq0asl initO_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I18217798024384389773_aow7lb5cq1)}
  );
  NI32 X60Qx_2048 = len_3_Ixq6taz_aow7lb5cq1(objs_0);
  NI32 X60Qx_2049 = len_3_Ixq6taz_aow7lb5cq1(texts_4);
  if (X60Qx_2048 == ((NI32)(X60Qx_2049 + 1))){
    NB8 X60Qx_2050;
    NB8 X60Qx_2051 = fileExists_0_osc4bsu0d1(initO_0);
    if ((!X60Qx_2051)){
      X60Qx_2050 = NIM_TRUE;}
    else {
      NB8 X60Qx_2052 = gccCompileOne_0_aow7lb5cq1(initC_0, initO_0, logFile_5);
      X60Qx_2050 = (!X60Qx_2052);}
    if (X60Qx_2050){
      eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
      seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2053 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
      objs_0 = X60Qx_2053;}
    else {
      string_0_sysvq0asl X60Qtmp_99 = initO_0;
      nimStrWasMoved((&initO_0));
      add_0_Ig6072n_aow7lb5cq1((&objs_0), X60Qtmp_99);}}
  NI32 X60Qx_2054 = len_3_Ixq6taz_aow7lb5cq1(objs_0);
  NI32 X60Qx_2055 = len_3_Ixq6taz_aow7lb5cq1(texts_4);
  if (X60Qx_2054 == ((NI32)(X60Qx_2055 + 1))){
    string_0_sysvq0asl X60Qtmp_100 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_2056 = eqQ_20_sysvq0asl(X60Qtmp_100, (string_0_sysvq0asl){
      .bytes_0 = 12545u, .more_0 = NIM_NIL}
    );
    if (X60Qx_2056){
      string_0_sysvq0asl X60Qdesugar_317 = dollarQ_2_sysvq0asl(recompiled_0);
      NI32 X60Qx_2057 = len_3_Ixq6taz_aow7lb5cq1(texts_4);
      string_0_sysvq0asl X60Qdesugar_318 = dollarQ_2_sysvq0asl(X60Qx_2057);
      NI32 X60Qx_2058 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I841702713041921937_aow7lb5cq1)}
      );
      NI32 X60Qx_2059 = len_4_sysvq0asl(X60Qdesugar_317);
      NI32 X60Qx_2060 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1718558974u, .more_0 = (&strlit_0_I8474398651341962338_aow7lb5cq1)}
      );
      NI32 X60Qx_2061 = len_4_sysvq0asl(X60Qdesugar_318);
      NI32 X60Qx_2062 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I7467151943153133040_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_319 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_2058 + X60Qx_2059)) + X60Qx_2060)) + X60Qx_2061)) + X60Qx_2062)));
      add_2_sysvq0asl((&X60Qdesugar_319), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I841702713041921937_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_319), X60Qdesugar_317);
      add_2_sysvq0asl((&X60Qdesugar_319), (string_0_sysvq0asl){
        .bytes_0 = 1718558974u, .more_0 = (&strlit_0_I8474398651341962338_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_319), X60Qdesugar_318);
      add_2_sysvq0asl((&X60Qdesugar_319), (string_0_sysvq0asl){
        .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I7467151943153133040_aow7lb5cq1)}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_319);
      nimStrDestroy(X60Qdesugar_319);
      nimStrDestroy(X60Qdesugar_318);
      nimStrDestroy(X60Qdesugar_317);}
    nimStrDestroy(X60Qtmp_100);}
  string_0_sysvq0asl so_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 1651076350u, .more_0 = (&strlit_0_I7503365064679144772_aow7lb5cq1)}
  );
  NI32 X60Qx_2063 = len_3_Ixq6taz_aow7lb5cq1(objs_0);
  NI32 X60Qx_2064 = len_3_Ixq6taz_aow7lb5cq1(texts_4);
  if (X60Qx_2063 == ((NI32)(X60Qx_2064 + 1))){
    string_0_sysvq0asl stubO_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I5516325166660413504_aow7lb5cq1)}
    );
    NB8 X60Qx_2065;
    NB8 X60Qx_2066;
    if (recompiled_0 == 0){
      X60Qx_2066 = stubsCurrent_0;}
    else {
      X60Qx_2066 = NIM_FALSE;}
    if (X60Qx_2066){
      NB8 X60Qx_2067 = fileExists_0_osc4bsu0d1(so_0);
      X60Qx_2065 = X60Qx_2067;}
    else {
      X60Qx_2065 = NIM_FALSE;}
    if (X60Qx_2065){
      string_0_sysvq0asl X60Qtmp_101 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
        .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
      , (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      );
      NB8 X60Qx_2068 = eqQ_20_sysvq0asl(X60Qtmp_101, (string_0_sysvq0asl){
        .bytes_0 = 12545u, .more_0 = NIM_NIL}
      );
      if (X60Qx_2068){
        NI32 X60Qx_2069 = len_3_Ixq6taz_aow7lb5cq1(objs_0);
        string_0_sysvq0asl X60Qdesugar_320 = dollarQ_2_sysvq0asl(X60Qx_2069);
        NI32 X60Qx_2070 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I15089684066203031656_aow7lb5cq1)}
        );
        NI32 X60Qx_2071 = len_4_sysvq0asl(X60Qdesugar_320);
        NI32 X60Qx_2072 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I4172422166419302997_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_321 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2070 + X60Qx_2071)) + X60Qx_2072)));
        add_2_sysvq0asl((&X60Qdesugar_321), (string_0_sysvq0asl){
          .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I15089684066203031656_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_321), X60Qdesugar_320);
        add_2_sysvq0asl((&X60Qdesugar_321), (string_0_sysvq0asl){
          .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I4172422166419302997_aow7lb5cq1)}
        );
        write_0_syn1lfpjv(stderr, X60Qdesugar_321);
        nimStrDestroy(X60Qdesugar_321);
        nimStrDestroy(X60Qdesugar_320);}
      eQdestroy_1_Ivioh0a_aow7lb5cq1((*undefined_0));
      seq_0_Ixdx2fh1_aow7lb5cq1 X60Qtmp_102 = undefinedFromLog_0_aow7lb5cq1(logFile_5);
      seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2073 = minusForwarded_0_aow7lb5cq1(buildDir_2, X60Qtmp_102);
      (*undefined_0) = X60Qx_2073;
      string_0_sysvq0asl X60Qtmp_103 = so_0;
      nimStrWasMoved((&so_0));
      eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_102);
      nimStrDestroy(X60Qtmp_101);
      nimStrDestroy(stubO_0);
      nimStrDestroy(so_0);
      nimStrDestroy(initO_0);
      nimStrDestroy(initBody_0);
      nimStrDestroy(X60Qdesugar_316);
      nimStrDestroy(defBody_0);
      nimStrDestroy(exportDecls_0);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
      nimStrDestroy(initC_0);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
      nimStrDestroy(X60Qtmp_95);
      nimStrDestroy(X60Qtmp_86);
      nimStrDestroy(deallocFn_3);
      nimStrDestroy(allocFn_2);
      nimStrDestroy(borrowFn_1);
      nimStrDestroy(longT_5);
      nimStrDestroy(strT_5);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
      nimStrDestroy(savedMainExt_0);
      nimStrDestroy(savedMainName_0);
      nimStrDestroy(savedMainDir_0);
      nimStrDestroy(X60Qtmp_80);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
      nimStrDestroy(stageDir_0);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
      nimStrDestroy(X60Qtmp_71);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
      nimStrDestroy(X60Qtmp_68);
      nimStrDestroy(X60Qdesugar_278);
      nimStrDestroy(X60Qdesugar_277);
      nimStrDestroy(X60Qdesugar_276);
      nimStrDestroy(listFile_0);
      nimStrDestroy(stubRevisionFile_0);
      nimStrDestroy(logFile_5);
      nimStrDestroy(cFile_0);
      nimStrDestroy(X60Qtmp_65);
      return X60Qtmp_103;
      eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qtmp_102);
      nimStrDestroy(X60Qtmp_101);}
    NB8 X60Qx_2074;
    NB8 X60Qx_2075 = gccLinkObjects_0_aow7lb5cq1(objs_0, so_0, logFile_5);
    if (X60Qx_2075){
      NB8 X60Qx_2076 = fileExists_0_osc4bsu0d1(so_0);
      X60Qx_2074 = X60Qx_2076;}
    else {
      X60Qx_2074 = NIM_FALSE;}
    if (X60Qx_2074){
      string_0_sysvq0asl X60Qtmp_104 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
        .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
      , (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      );
      NB8 X60Qx_2077 = eqQ_20_sysvq0asl(X60Qtmp_104, (string_0_sysvq0asl){
        .bytes_0 = 12545u, .more_0 = NIM_NIL}
      );
      if (X60Qx_2077){
        NI32 X60Qx_2078 = len_3_Ixq6taz_aow7lb5cq1(objs_0);
        string_0_sysvq0asl X60Qdesugar_322 = dollarQ_2_sysvq0asl(X60Qx_2078);
        NI32 X60Qx_2079 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I15934887379077153009_aow7lb5cq1)}
        );
        NI32 X60Qx_2080 = len_4_sysvq0asl(X60Qdesugar_322);
        NI32 X60Qx_2081 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I6305068438373177994_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_323 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2079 + X60Qx_2080)) + X60Qx_2081)));
        add_2_sysvq0asl((&X60Qdesugar_323), (string_0_sysvq0asl){
          .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I15934887379077153009_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_323), X60Qdesugar_322);
        add_2_sysvq0asl((&X60Qdesugar_323), (string_0_sysvq0asl){
          .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I6305068438373177994_aow7lb5cq1)}
        );
        write_0_syn1lfpjv(stderr, X60Qdesugar_323);
        nimStrDestroy(X60Qdesugar_323);
        nimStrDestroy(X60Qdesugar_322);}
      string_0_sysvq0asl X60Qtmp_105 = so_0;
      nimStrWasMoved((&so_0));
      nimStrDestroy(X60Qtmp_104);
      nimStrDestroy(stubO_0);
      nimStrDestroy(so_0);
      nimStrDestroy(initO_0);
      nimStrDestroy(initBody_0);
      nimStrDestroy(X60Qdesugar_316);
      nimStrDestroy(defBody_0);
      nimStrDestroy(exportDecls_0);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
      nimStrDestroy(initC_0);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
      nimStrDestroy(X60Qtmp_95);
      nimStrDestroy(X60Qtmp_86);
      nimStrDestroy(deallocFn_3);
      nimStrDestroy(allocFn_2);
      nimStrDestroy(borrowFn_1);
      nimStrDestroy(longT_5);
      nimStrDestroy(strT_5);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
      nimStrDestroy(savedMainExt_0);
      nimStrDestroy(savedMainName_0);
      nimStrDestroy(savedMainDir_0);
      nimStrDestroy(X60Qtmp_80);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
      nimStrDestroy(stageDir_0);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
      nimStrDestroy(X60Qtmp_71);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
      nimStrDestroy(X60Qtmp_68);
      nimStrDestroy(X60Qdesugar_278);
      nimStrDestroy(X60Qdesugar_277);
      nimStrDestroy(X60Qdesugar_276);
      nimStrDestroy(listFile_0);
      nimStrDestroy(stubRevisionFile_0);
      nimStrDestroy(logFile_5);
      nimStrDestroy(cFile_0);
      nimStrDestroy(X60Qtmp_65);
      return X60Qtmp_105;
      nimStrDestroy(X60Qtmp_104);}
    seq_0_Ixdx2fh1_aow7lb5cq1 miss_0 = undefinedFromLog_0_aow7lb5cq1(logFile_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1((*undefined_0));
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2082 = eQdup_1_Imq0s4c_aow7lb5cq1(miss_0);
    (*undefined_0) = X60Qx_2082;
    if (0 < miss_0.len_0){
      string_0_sysvq0asl stubC_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
        .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I10407826023453223595_aow7lb5cq1)}
      );
      seq_0_Ixdx2fh1_aow7lb5cq1 fwdNames_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
      NB8 X60Qx_2083;
      NB8 X60Qx_2084 = writeHostStubs_0_aow7lb5cq1(stubC_0, miss_0, texts_4, (&fwdNames_0));
      if (X60Qx_2084){
        NB8 X60Qx_2085 = gccCompileOne_0_aow7lb5cq1(stubC_0, stubO_0, logFile_5);
        X60Qx_2083 = X60Qx_2085;}
      else {
        X60Qx_2083 = NIM_FALSE;}
      if (X60Qx_2083){
        writeFwdList_0_aow7lb5cq1(buildDir_2, fwdNames_0);
        eQdestroy_1_Ivioh0a_aow7lb5cq1((*undefined_0));
        seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2086 = minusForwarded_0_aow7lb5cq1(buildDir_2, miss_0);
        (*undefined_0) = X60Qx_2086;
        seq_0_Ixdx2fh1_aow7lb5cq1 withStubs_0 = objs_0;
        eQwasMoved_1_I5vdnla_aow7lb5cq1((&objs_0));
        string_0_sysvq0asl X60Qtmp_106 = stubO_0;
        nimStrWasMoved((&stubO_0));
        add_0_Ig6072n_aow7lb5cq1((&withStubs_0), X60Qtmp_106);
        NB8 X60Qx_2087;
        NB8 X60Qx_2088 = gccLinkObjects_0_aow7lb5cq1(withStubs_0, so_0, logFile_5);
        if (X60Qx_2088){
          NB8 X60Qx_2089 = fileExists_0_osc4bsu0d1(so_0);
          X60Qx_2087 = X60Qx_2089;}
        else {
          X60Qx_2087 = NIM_FALSE;}
        if (X60Qx_2087){
          string_0_sysvq0asl X60Qtmp_107 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
            .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
          , (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          );
          NB8 X60Qx_2090 = eqQ_20_sysvq0asl(X60Qtmp_107, (string_0_sysvq0asl){
            .bytes_0 = 12545u, .more_0 = NIM_NIL}
          );
          if (X60Qx_2090){
            NI32 X60Qx_2091 = len_3_Ixq6taz_aow7lb5cq1(withStubs_0);
            string_0_sysvq0asl X60Qdesugar_324 = dollarQ_2_sysvq0asl(X60Qx_2091);
            NI32 X60Qx_2092 = len_3_Ixq6taz_aow7lb5cq1(miss_0);
            string_0_sysvq0asl X60Qdesugar_325 = dollarQ_2_sysvq0asl(X60Qx_2092);
            NI32 X60Qx_2093 = len_3_Ixq6taz_aow7lb5cq1(miss_0);
            NI32 X60Qx_2094 = len_3_Ixq6taz_aow7lb5cq1((*undefined_0));
            string_0_sysvq0asl X60Qdesugar_326 = dollarQ_2_sysvq0asl(((NI32)(X60Qx_2093 - X60Qx_2094)));
            NI32 X60Qx_2095 = len_3_Ixq6taz_aow7lb5cq1((*undefined_0));
            string_0_sysvq0asl X60Qdesugar_327 = dollarQ_2_sysvq0asl(X60Qx_2095);
            NI32 X60Qx_2096 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I20870224864136604_aow7lb5cq1)}
            );
            NI32 X60Qx_2097 = len_4_sysvq0asl(X60Qdesugar_324);
            NI32 X60Qx_2098 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I10939655993194240046_aow7lb5cq1)}
            );
            NI32 X60Qx_2099 = len_4_sysvq0asl(X60Qdesugar_325);
            NI32 X60Qx_2100 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1869095166u, .more_0 = (&strlit_0_I17840704925771562650_aow7lb5cq1)}
            );
            NI32 X60Qx_2101 = len_4_sysvq0asl(X60Qdesugar_326);
            NI32 X60Qx_2102 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1868964094u, .more_0 = (&strlit_0_I16618787334720904331_aow7lb5cq1)}
            );
            NI32 X60Qx_2103 = len_4_sysvq0asl(X60Qdesugar_327);
            NI32 X60Qx_2104 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1650532606u, .more_0 = (&strlit_0_I11669336360358941120_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_328 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_2096 + X60Qx_2097)) + X60Qx_2098)) + X60Qx_2099)) + X60Qx_2100)) + X60Qx_2101)) + X60Qx_2102)) + X60Qx_2103)) + X60Qx_2104)));
            add_2_sysvq0asl((&X60Qdesugar_328), (string_0_sysvq0asl){
              .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I20870224864136604_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_328), X60Qdesugar_324);
            add_2_sysvq0asl((&X60Qdesugar_328), (string_0_sysvq0asl){
              .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I10939655993194240046_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_328), X60Qdesugar_325);
            add_2_sysvq0asl((&X60Qdesugar_328), (string_0_sysvq0asl){
              .bytes_0 = 1869095166u, .more_0 = (&strlit_0_I17840704925771562650_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_328), X60Qdesugar_326);
            add_2_sysvq0asl((&X60Qdesugar_328), (string_0_sysvq0asl){
              .bytes_0 = 1868964094u, .more_0 = (&strlit_0_I16618787334720904331_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_328), X60Qdesugar_327);
            add_2_sysvq0asl((&X60Qdesugar_328), (string_0_sysvq0asl){
              .bytes_0 = 1650532606u, .more_0 = (&strlit_0_I11669336360358941120_aow7lb5cq1)}
            );
            write_0_syn1lfpjv(stderr, X60Qdesugar_328);
            nimStrDestroy(X60Qdesugar_328);
            nimStrDestroy(X60Qdesugar_327);
            nimStrDestroy(X60Qdesugar_326);
            nimStrDestroy(X60Qdesugar_325);
            nimStrDestroy(X60Qdesugar_324);}
          string_0_sysvq0asl X60Qtmp_108 = so_0;
          nimStrWasMoved((&so_0));
          nimStrDestroy(X60Qtmp_107);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(withStubs_0);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(fwdNames_0);
          nimStrDestroy(stubC_0);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(miss_0);
          nimStrDestroy(stubO_0);
          nimStrDestroy(so_0);
          nimStrDestroy(initO_0);
          nimStrDestroy(initBody_0);
          nimStrDestroy(X60Qdesugar_316);
          nimStrDestroy(defBody_0);
          nimStrDestroy(exportDecls_0);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
          nimStrDestroy(initC_0);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
          nimStrDestroy(X60Qtmp_95);
          nimStrDestroy(X60Qtmp_86);
          nimStrDestroy(deallocFn_3);
          nimStrDestroy(allocFn_2);
          nimStrDestroy(borrowFn_1);
          nimStrDestroy(longT_5);
          nimStrDestroy(strT_5);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
          nimStrDestroy(savedMainExt_0);
          nimStrDestroy(savedMainName_0);
          nimStrDestroy(savedMainDir_0);
          nimStrDestroy(X60Qtmp_80);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
          nimStrDestroy(stageDir_0);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
          nimStrDestroy(X60Qtmp_71);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
          nimStrDestroy(X60Qtmp_68);
          nimStrDestroy(X60Qdesugar_278);
          nimStrDestroy(X60Qdesugar_277);
          nimStrDestroy(X60Qdesugar_276);
          nimStrDestroy(listFile_0);
          nimStrDestroy(stubRevisionFile_0);
          nimStrDestroy(logFile_5);
          nimStrDestroy(cFile_0);
          nimStrDestroy(X60Qtmp_65);
          return X60Qtmp_108;
          nimStrDestroy(X60Qtmp_107);}
        eQdestroy_1_Ivioh0a_aow7lb5cq1(withStubs_0);}
      eQdestroy_1_Ivioh0a_aow7lb5cq1(fwdNames_0);
      nimStrDestroy(stubC_0);}
    eQdestroy_1_Ivioh0a_aow7lb5cq1(miss_0);
    nimStrDestroy(stubO_0);}
  NB8 X60Qx_2105;
  NB8 X60Qx_2106 = gccSharedMany_0_aow7lb5cq1(files_0, so_0, logFile_5);
  if (X60Qx_2106){
    NB8 X60Qx_2107 = fileExists_0_osc4bsu0d1(so_0);
    X60Qx_2105 = X60Qx_2107;}
  else {
    X60Qx_2105 = NIM_FALSE;}
  if (X60Qx_2105){
    string_0_sysvq0asl X60Qtmp_109 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_2108 = eqQ_20_sysvq0asl(X60Qtmp_109, (string_0_sysvq0asl){
      .bytes_0 = 12545u, .more_0 = NIM_NIL}
    );
    if (X60Qx_2108){
      NI32 X60Qx_2109 = len_3_Ixq6taz_aow7lb5cq1(files_0);
      string_0_sysvq0asl X60Qdesugar_329 = dollarQ_2_sysvq0asl(X60Qx_2109);
      NI32 X60Qx_2110 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I5560383726051623062_aow7lb5cq1)}
      );
      NI32 X60Qx_2111 = len_4_sysvq0asl(X60Qdesugar_329);
      NI32 X60Qx_2112 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I13807919816995135645_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_330 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2110 + X60Qx_2111)) + X60Qx_2112)));
      add_2_sysvq0asl((&X60Qdesugar_330), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I5560383726051623062_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_330), X60Qdesugar_329);
      add_2_sysvq0asl((&X60Qdesugar_330), (string_0_sysvq0asl){
        .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I13807919816995135645_aow7lb5cq1)}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_330);
      nimStrDestroy(X60Qdesugar_330);
      nimStrDestroy(X60Qdesugar_329);}
    string_0_sysvq0asl X60Qtmp_110 = so_0;
    nimStrWasMoved((&so_0));
    nimStrDestroy(X60Qtmp_109);
    nimStrDestroy(so_0);
    nimStrDestroy(initO_0);
    nimStrDestroy(initBody_0);
    nimStrDestroy(X60Qdesugar_316);
    nimStrDestroy(defBody_0);
    nimStrDestroy(exportDecls_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
    nimStrDestroy(initC_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return X60Qtmp_110;
    nimStrDestroy(X60Qtmp_109);}
  seq_0_Ixdx2fh1_aow7lb5cq1 missing_0 = undefinedFromLog_0_aow7lb5cq1(logFile_5);
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*undefined_0));
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2113 = eQdup_1_Imq0s4c_aow7lb5cq1(missing_0);
  (*undefined_0) = X60Qx_2113;
  if (0 < missing_0.len_0){
    string_0_sysvq0asl stubC_1 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I10407826023453223595_aow7lb5cq1)}
    );
    seq_0_Ixdx2fh1_aow7lb5cq1 fwdNames_1 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    NB8 X60Qx_2114 = writeHostStubs_0_aow7lb5cq1(stubC_1, missing_0, texts_4, (&fwdNames_1));
    if (X60Qx_2114){
      writeFwdList_0_aow7lb5cq1(buildDir_2, fwdNames_1);
      eQdestroy_1_Ivioh0a_aow7lb5cq1((*undefined_0));
      seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2115 = minusForwarded_0_aow7lb5cq1(buildDir_2, missing_0);
      (*undefined_0) = X60Qx_2115;
      seq_0_Ixdx2fh1_aow7lb5cq1 withStubs_1 = files_0;
      eQwasMoved_1_I5vdnla_aow7lb5cq1((&files_0));
      string_0_sysvq0asl X60Qtmp_111 = stubC_1;
      nimStrWasMoved((&stubC_1));
      add_0_Ig6072n_aow7lb5cq1((&withStubs_1), X60Qtmp_111);
      string_0_sysvq0asl X60Qtmp_112 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
        .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
      , (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      );
      NB8 X60Qx_2116 = eqQ_20_sysvq0asl(X60Qtmp_112, (string_0_sysvq0asl){
        .bytes_0 = 12545u, .more_0 = NIM_NIL}
      );
      if (X60Qx_2116){
        NI32 X60Qx_2117 = len_3_Ixq6taz_aow7lb5cq1(missing_0);
        string_0_sysvq0asl X60Qdesugar_331 = dollarQ_2_sysvq0asl(X60Qx_2117);
        NI32 X60Qx_2118 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I841702713041921937_aow7lb5cq1)}
        );
        NI32 X60Qx_2119 = len_4_sysvq0asl(X60Qdesugar_331);
        NI32 X60Qx_2120 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1869095166u, .more_0 = (&strlit_0_I3929042842498019668_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_332 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2118 + X60Qx_2119)) + X60Qx_2120)));
        add_2_sysvq0asl((&X60Qdesugar_332), (string_0_sysvq0asl){
          .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I841702713041921937_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_332), X60Qdesugar_331);
        add_2_sysvq0asl((&X60Qdesugar_332), (string_0_sysvq0asl){
          .bytes_0 = 1869095166u, .more_0 = (&strlit_0_I3929042842498019668_aow7lb5cq1)}
        );
        write_0_syn1lfpjv(stderr, X60Qdesugar_332);
        nimStrDestroy(X60Qdesugar_332);
        nimStrDestroy(X60Qdesugar_331);}
      NB8 X60Qx_2121;
      NB8 X60Qx_2122 = gccSharedMany_0_aow7lb5cq1(withStubs_1, so_0, logFile_5);
      if (X60Qx_2122){
        NB8 X60Qx_2123 = fileExists_0_osc4bsu0d1(so_0);
        X60Qx_2121 = X60Qx_2123;}
      else {
        X60Qx_2121 = NIM_FALSE;}
      if (X60Qx_2121){
        string_0_sysvq0asl X60Qtmp_113 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
          .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
        , (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        );
        NB8 X60Qx_2124 = eqQ_20_sysvq0asl(X60Qtmp_113, (string_0_sysvq0asl){
          .bytes_0 = 12545u, .more_0 = NIM_NIL}
        );
        if (X60Qx_2124){
          NI32 X60Qx_2125 = len_3_Ixq6taz_aow7lb5cq1(withStubs_1);
          string_0_sysvq0asl X60Qdesugar_333 = dollarQ_2_sysvq0asl(X60Qx_2125);
          NI32 X60Qx_2126 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I137218741528845722_aow7lb5cq1)}
          );
          NI32 X60Qx_2127 = len_4_sysvq0asl(X60Qdesugar_333);
          NI32 X60Qx_2128 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I6305068438373177994_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_334 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2126 + X60Qx_2127)) + X60Qx_2128)));
          add_2_sysvq0asl((&X60Qdesugar_334), (string_0_sysvq0asl){
            .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I137218741528845722_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_334), X60Qdesugar_333);
          add_2_sysvq0asl((&X60Qdesugar_334), (string_0_sysvq0asl){
            .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I6305068438373177994_aow7lb5cq1)}
          );
          write_0_syn1lfpjv(stderr, X60Qdesugar_334);
          nimStrDestroy(X60Qdesugar_334);
          nimStrDestroy(X60Qdesugar_333);}
        string_0_sysvq0asl X60Qtmp_114 = so_0;
        nimStrWasMoved((&so_0));
        nimStrDestroy(X60Qtmp_113);
        nimStrDestroy(X60Qtmp_112);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(withStubs_1);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(fwdNames_1);
        nimStrDestroy(stubC_1);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
        nimStrDestroy(so_0);
        nimStrDestroy(initO_0);
        nimStrDestroy(initBody_0);
        nimStrDestroy(X60Qdesugar_316);
        nimStrDestroy(defBody_0);
        nimStrDestroy(exportDecls_0);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
        nimStrDestroy(initC_0);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
        nimStrDestroy(X60Qtmp_95);
        nimStrDestroy(X60Qtmp_86);
        nimStrDestroy(deallocFn_3);
        nimStrDestroy(allocFn_2);
        nimStrDestroy(borrowFn_1);
        nimStrDestroy(longT_5);
        nimStrDestroy(strT_5);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
        nimStrDestroy(savedMainExt_0);
        nimStrDestroy(savedMainName_0);
        nimStrDestroy(savedMainDir_0);
        nimStrDestroy(X60Qtmp_80);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
        nimStrDestroy(stageDir_0);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
        nimStrDestroy(X60Qtmp_71);
        eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
        nimStrDestroy(X60Qtmp_68);
        nimStrDestroy(X60Qdesugar_278);
        nimStrDestroy(X60Qdesugar_277);
        nimStrDestroy(X60Qdesugar_276);
        nimStrDestroy(listFile_0);
        nimStrDestroy(stubRevisionFile_0);
        nimStrDestroy(logFile_5);
        nimStrDestroy(cFile_0);
        nimStrDestroy(X60Qtmp_65);
        return X60Qtmp_114;
        nimStrDestroy(X60Qtmp_113);}
      nimStrDestroy(X60Qtmp_112);
      eQdestroy_1_Ivioh0a_aow7lb5cq1(withStubs_1);}
    eQdestroy_1_Ivioh0a_aow7lb5cq1(fwdNames_1);
    nimStrDestroy(stubC_1);}
  string_0_sysvq0asl drv_0 = aowlcBin_0_aow7lb5cq1();
  string_0_sysvq0asl X60Qtmp_115 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_2129 = eqQ_20_sysvq0asl(X60Qtmp_115, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  if (X60Qx_2129){
    string_0_sysvq0asl why_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    {
      string_0_sysvq0asl X60Qlf_57 = logFile_5;
      FILE* X60Qlf_58;
      NB8 X60Qx_2130 = open_0_syn1lfpjv((&X60Qlf_58), X60Qlf_57, 0, -1);
      if (X60Qx_2130){
        string_0_sysvq0asl X60Qlf_59 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;
        {
          while (NIM_TRUE){
            NB8 X60Qx_2131 = readLine_0_syn1lfpjv(X60Qlf_58, (&X60Qlf_59));
            if (X60Qx_2131){
              {
                NB8 X60Qx_2132 = hasSub_0_aow7lb5cq1(X60Qlf_59, (string_0_sysvq0asl){
                  .bytes_0 = 1919230206u, .more_0 = (&strlit_0_I5994905260270776565_aow7lb5cq1)}
                );
                if (X60Qx_2132){
                  nimStrDestroy(why_1);
                  why_1 = X60Qlf_59;
                  nimStrWasMoved((&X60Qlf_59));
                  nimStrDestroy(X60Qlf_59);
                  goto forStmtLabel_48;}}}
            else {
              break;}}}
        whileStmtLabel_49: ;
        NI32 X60Qx_2133 = fclose(X60Qlf_58);
        nimStrDestroy(X60Qlf_59);}}
    forStmtLabel_48: ;
    if (NIM_FALSE){
      X60Qexlab_13: ;}
    NI32 X60Qx_2134 = len_4_sysvq0asl(why_1);
    if (X60Qx_2134 == 0){
      NI32 X60Qx_2135 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I12082841593871989252_aow7lb5cq1)}
      );
      NI32 X60Qx_2136 = len_4_sysvq0asl(logFile_5);
      NI32 X60Qx_2137 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 10497u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_335 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2135 + X60Qx_2136)) + X60Qx_2137)));
      add_2_sysvq0asl((&X60Qdesugar_335), (string_0_sysvq0asl){
        .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I12082841593871989252_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_335), logFile_5);
      add_2_sysvq0asl((&X60Qdesugar_335), (string_0_sysvq0asl){
        .bytes_0 = 10497u, .more_0 = NIM_NIL}
      );
      nimStrDestroy(why_1);
      why_1 = X60Qdesugar_335;
      nimStrWasMoved((&X60Qdesugar_335));
      nimStrDestroy(X60Qdesugar_335);}
    string_0_sysvq0asl X60Qtmp_116 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I6593187846888673991_aow7lb5cq1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I14068837617402760607_aow7lb5cq1)}
    );
    write_0_syn1lfpjv(stderr, X60Qtmp_116);
    NI32 X60Qx_2138 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I9780003836072079947_aow7lb5cq1)}
    );
    NI32 X60Qx_2139 = len_4_sysvq0asl(why_1);
    NI32 X60Qx_2140 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_336 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2138 + X60Qx_2139)) + X60Qx_2140)));
    add_2_sysvq0asl((&X60Qdesugar_336), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I9780003836072079947_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_336), why_1);
    add_2_sysvq0asl((&X60Qdesugar_336), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_336);
    string_0_sysvq0asl X60Qtmp_117 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I10430587979360259626_aow7lb5cq1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 1684955646u, .more_0 = (&strlit_0_I5082076793001871145_aow7lb5cq1)}
    );
    write_0_syn1lfpjv(stderr, X60Qtmp_117);
    nimStrDestroy(X60Qtmp_117);
    nimStrDestroy(X60Qdesugar_336);
    nimStrDestroy(X60Qtmp_116);
    nimStrDestroy(why_1);}
  NB8 X60Qx_2141 = fileExists_0_osc4bsu0d1(drv_0);
  if ((!X60Qx_2141)){
    string_0_sysvq0asl X60Qtmp_118 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_2142 = eqQ_20_sysvq0asl(X60Qtmp_118, (string_0_sysvq0asl){
      .bytes_0 = 12545u, .more_0 = NIM_NIL}
    );
    if (X60Qx_2142){
      NI32 X60Qx_2143 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I17458548344829006286_aow7lb5cq1)}
      );
      NI32 X60Qx_2144 = len_4_sysvq0asl(drv_0);
      NI32 X60Qx_2145 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13273991446069831203_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_337 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_2143 + X60Qx_2144)) + X60Qx_2145)));
      add_2_sysvq0asl((&X60Qdesugar_337), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I17458548344829006286_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_337), drv_0);
      add_2_sysvq0asl((&X60Qdesugar_337), (string_0_sysvq0asl){
        .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13273991446069831203_aow7lb5cq1)}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_337);
      nimStrDestroy(X60Qdesugar_337);}
    nimStrDestroy(X60Qtmp_118);
    nimStrDestroy(X60Qtmp_115);
    nimStrDestroy(drv_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
    nimStrDestroy(so_0);
    nimStrDestroy(initO_0);
    nimStrDestroy(initBody_0);
    nimStrDestroy(X60Qdesugar_316);
    nimStrDestroy(defBody_0);
    nimStrDestroy(exportDecls_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
    nimStrDestroy(initC_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;
    nimStrDestroy(X60Qtmp_118);}
  string_0_sysvq0asl cFile2_0 = slashQ_0_ospaexnw61(buildDir_2, (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I12623205787878531514_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qtmp_119 = quoteShell_0_oswd7dmm(drv_0);
  string_0_sysvq0asl cmd_2 = ampQ_0_sysvq0asl(X60Qtmp_119, (string_0_sysvq0asl){
    .bytes_0 = 1768694014u, .more_0 = (&strlit_0_I13081134508802474439_aow7lb5cq1)}
  );
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_60 = toOpenArray_1_I6b60gk1_aow7lb5cq1(mods_2);
    NI32 X60Qlf_61 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_2146 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_60);
        if (X60Qlf_61 < X60Qx_2146){
          {
            string_0_sysvq0asl* X60Qii_52 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_60, X60Qlf_61);
            string_0_sysvq0asl X60Qtmp_121 = quoteShell_0_oswd7dmm((*X60Qii_52));
            string_0_sysvq0asl X60Qtmp_120 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            , X60Qtmp_121);
            add_2_sysvq0asl((&cmd_2), X60Qtmp_120);
            nimStrDestroy(X60Qtmp_120);
            nimStrDestroy(X60Qtmp_121);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_61));}
        else {
          break;}}}
    whileStmtLabel_51: ;}
  forStmtLabel_50: ;
  string_0_sysvq0asl X60Qdesugar_338 = quoteShell_0_oswd7dmm(cFile2_0);
  string_0_sysvq0asl X60Qdesugar_339 = quoteShell_0_oswd7dmm(logFile_5);
  NI32 X60Qx_2147 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 757932286u, .more_0 = (&strlit_0_I2781643746782836964_aow7lb5cq1)}
  );
  NI32 X60Qx_2148 = len_4_sysvq0asl(X60Qdesugar_338);
  NI32 X60Qx_2149 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_2150 = len_4_sysvq0asl(X60Qdesugar_339);
  NI32 X60Qx_2151 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_340 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_2147 + X60Qx_2148)) + X60Qx_2149)) + X60Qx_2150)) + X60Qx_2151)));
  add_2_sysvq0asl((&X60Qdesugar_340), (string_0_sysvq0asl){
    .bytes_0 = 757932286u, .more_0 = (&strlit_0_I2781643746782836964_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_340), X60Qdesugar_338);
  add_2_sysvq0asl((&X60Qdesugar_340), (string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_340), X60Qdesugar_339);
  add_2_sysvq0asl((&X60Qdesugar_340), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&cmd_2), X60Qdesugar_340);
  NI32 X60Qx_2152 = execShellCmd_0_oswd7dmm(cmd_2);
  NB8 X60Qx_2153 = fileExists_0_osc4bsu0d1(cFile2_0);
  if ((!X60Qx_2153)){
    nimStrDestroy(X60Qdesugar_340);
    nimStrDestroy(X60Qdesugar_339);
    nimStrDestroy(X60Qdesugar_338);
    nimStrDestroy(cmd_2);
    nimStrDestroy(X60Qtmp_119);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_115);
    nimStrDestroy(drv_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
    nimStrDestroy(so_0);
    nimStrDestroy(initO_0);
    nimStrDestroy(initBody_0);
    nimStrDestroy(X60Qdesugar_316);
    nimStrDestroy(defBody_0);
    nimStrDestroy(exportDecls_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
    nimStrDestroy(initC_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  string_0_sysvq0asl src2_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_5 = readFile_0_syn1lfpjv(cFile2_0);
  if (X60QcanRaise_5.fld_0){
    goto X60Qexlab_14;}
  nimStrDestroy(src2_0);
  string_0_sysvq0asl X60Qx_2154 = nimStrDup(X60QcanRaise_5.fld_1);
  src2_0 = X60Qx_2154;
  if (NIM_FALSE){
    X60Qexlab_14: ;
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_340);
    nimStrDestroy(X60Qdesugar_339);
    nimStrDestroy(X60Qdesugar_338);
    nimStrDestroy(cmd_2);
    nimStrDestroy(X60Qtmp_119);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_115);
    nimStrDestroy(drv_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
    nimStrDestroy(so_0);
    nimStrDestroy(initO_0);
    nimStrDestroy(initBody_0);
    nimStrDestroy(X60Qdesugar_316);
    nimStrDestroy(defBody_0);
    nimStrDestroy(exportDecls_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
    nimStrDestroy(initC_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  NI32 X60Qx_2155 = len_4_sysvq0asl(src2_0);
  if (X60Qx_2155 == 0){
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_340);
    nimStrDestroy(X60Qdesugar_339);
    nimStrDestroy(X60Qdesugar_338);
    nimStrDestroy(cmd_2);
    nimStrDestroy(X60Qtmp_119);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_115);
    nimStrDestroy(drv_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
    nimStrDestroy(so_0);
    nimStrDestroy(initO_0);
    nimStrDestroy(initBody_0);
    nimStrDestroy(X60Qdesugar_316);
    nimStrDestroy(defBody_0);
    nimStrDestroy(exportDecls_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
    nimStrDestroy(initC_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  string_0_sysvq0asl strT2_0 = typeNameAfter_0_aow7lb5cq1(src2_0, (string_0_sysvq0asl){
    .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I17605077022815850042_aow7lb5cq1)}
  );
  string_0_sysvq0asl longT2_0 = typeNameAfter_0_aow7lb5cq1(src2_0, (string_0_sysvq0asl){
    .bytes_0 = 1852787966u, .more_0 = (&strlit_0_I15230512448378417494_aow7lb5cq1)}
  );
  string_0_sysvq0asl borrowFn2_0 = typeNameAfter_0_aow7lb5cq1(src2_0, (string_0_sysvq0asl){
    .bytes_0 = 1919902462u, .more_0 = (&strlit_0_I9467484319694674619_aow7lb5cq1)}
  );
  string_0_sysvq0asl deallocFn2_0 = typeNameAfter_0_aow7lb5cq1(src2_0, (string_0_sysvq0asl){
    .bytes_0 = 1634034942u, .more_0 = (&strlit_0_I16718063019512574093_aow7lb5cq1)}
  );
  string_0_sysvq0asl allocFn2_0 = typeNameAfter_0_aow7lb5cq1(src2_0, (string_0_sysvq0asl){
    .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I5607995952013721966_aow7lb5cq1)}
  );
  NB8 needStr_0 = NIM_FALSE;
  NB8 needSeq_0 = NIM_FALSE;
  {
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_62 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_0);
    NI32 X60Qlf_63 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_2156 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_62);
        if (X60Qlf_63 < X60Qx_2156){
          {
            X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_55 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_62, X60Qlf_63);
            NB8 X60Qx_2157;
            NB8 X60Qx_2158 = jitEligible_0_aow7lb5cq1((*X60Qii_55));
            if (X60Qx_2158){
              NB8 X60Qx_2159 = usesStrings_0_aow7lb5cq1((*X60Qii_55));
              X60Qx_2157 = X60Qx_2159;}
            else {
              X60Qx_2157 = NIM_FALSE;}
            if (X60Qx_2157){
              needStr_0 = NIM_TRUE;}
            NB8 X60Qx_2160;
            NB8 X60Qx_2161 = jitEligible_0_aow7lb5cq1((*X60Qii_55));
            if (X60Qx_2161){
              NB8 X60Qx_2162 = usesSeqs_0_aow7lb5cq1((*X60Qii_55));
              X60Qx_2160 = X60Qx_2162;}
            else {
              X60Qx_2160 = NIM_FALSE;}
            if (X60Qx_2160){
              needSeq_0 = NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_63));}
        else {
          break;}}}
    whileStmtLabel_54: ;}
  forStmtLabel_53: ;
  NB8 X60Qx_2163;
  if (needStr_0){
    NB8 X60Qx_2164;
    NB8 X60Qx_2165;
    NI32 X60Qx_2166 = len_4_sysvq0asl(strT2_0);
    if (X60Qx_2166 == 0){
      X60Qx_2165 = NIM_TRUE;}
    else {
      NI32 X60Qx_2167 = len_4_sysvq0asl(longT2_0);
      X60Qx_2165 = (X60Qx_2167 == 0);}
    if (X60Qx_2165){
      X60Qx_2164 = NIM_TRUE;}
    else {
      NI32 X60Qx_2168 = len_4_sysvq0asl(borrowFn2_0);
      X60Qx_2164 = (X60Qx_2168 == 0);}
    X60Qx_2163 = X60Qx_2164;}
  else {
    X60Qx_2163 = NIM_FALSE;}
  if (X60Qx_2163){
    nimStrDestroy(allocFn2_0);
    nimStrDestroy(deallocFn2_0);
    nimStrDestroy(borrowFn2_0);
    nimStrDestroy(longT2_0);
    nimStrDestroy(strT2_0);
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_340);
    nimStrDestroy(X60Qdesugar_339);
    nimStrDestroy(X60Qdesugar_338);
    nimStrDestroy(cmd_2);
    nimStrDestroy(X60Qtmp_119);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_115);
    nimStrDestroy(drv_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
    nimStrDestroy(so_0);
    nimStrDestroy(initO_0);
    nimStrDestroy(initBody_0);
    nimStrDestroy(X60Qdesugar_316);
    nimStrDestroy(defBody_0);
    nimStrDestroy(exportDecls_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
    nimStrDestroy(initC_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  NB8 X60Qx_2169;
  if (needSeq_0){
    NB8 X60Qx_2170;
    NI32 X60Qx_2171 = len_4_sysvq0asl(allocFn2_0);
    if (X60Qx_2171 == 0){
      X60Qx_2170 = NIM_TRUE;}
    else {
      NI32 X60Qx_2172 = len_4_sysvq0asl(deallocFn2_0);
      X60Qx_2170 = (X60Qx_2172 == 0);}
    X60Qx_2169 = X60Qx_2170;}
  else {
    X60Qx_2169 = NIM_FALSE;}
  if (X60Qx_2169){
    nimStrDestroy(allocFn2_0);
    nimStrDestroy(deallocFn2_0);
    nimStrDestroy(borrowFn2_0);
    nimStrDestroy(longT2_0);
    nimStrDestroy(strT2_0);
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_340);
    nimStrDestroy(X60Qdesugar_339);
    nimStrDestroy(X60Qdesugar_338);
    nimStrDestroy(cmd_2);
    nimStrDestroy(X60Qtmp_119);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_115);
    nimStrDestroy(drv_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
    nimStrDestroy(so_0);
    nimStrDestroy(initO_0);
    nimStrDestroy(initBody_0);
    nimStrDestroy(X60Qdesugar_316);
    nimStrDestroy(defBody_0);
    nimStrDestroy(exportDecls_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
    nimStrDestroy(initC_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  string_0_sysvq0asl shims_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 n2_0 = 0;
  {
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_64 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_0);
    NI32 X60Qlf_65 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_2173 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_64);
        if (X60Qlf_65 < X60Qx_2173){
          {
            {
              X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_59 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_64, X60Qlf_65);
              NB8 X60Qx_2174 = jitEligible_0_aow7lb5cq1((*X60Qii_59));
              if ((!X60Qx_2174)){
                goto continueLabel_58;}
              string_0_sysvq0asl X60Qii_60 = aowlcSymName_0_run8hsnpi((*(*X60Qii_59)).d_00.sym_0);
              string_0_sysvq0asl X60Qii_61 = (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              ;
              NB8 X60Qx_2175;
              NI32 X60Qx_2176 = len_4_sysvq0asl(X60Qii_60);
              if (0 < X60Qx_2176){
                NB8 X60Qx_2177 = definesExactly_0_aow7lb5cq1(src2_0, X60Qii_60);
                X60Qx_2175 = X60Qx_2177;}
              else {
                X60Qx_2175 = NIM_FALSE;}
              if (X60Qx_2175){
                nimStrDestroy(X60Qii_61);
                X60Qii_61 = X60Qii_60;
                nimStrWasMoved((&X60Qii_60));}
              else {
                NI32 X60Qx_2178 = len_4_sysvq0asl(X60Qii_60);
                if (X60Qx_2178 == 0){
                  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qii_62 = mangledNamesFor_0_aow7lb5cq1(src2_0, (*(*X60Qii_59)).d_00.base_0);
                  NI32 X60Qx_2179 = len_3_Ixq6taz_aow7lb5cq1(X60Qii_62);
                  if (X60Qx_2179 == 1){
                    nimStrDestroy(X60Qii_61);
                    string_0_sysvq0asl* X60Qx_2180 = getQ_7_Ir6d0tw_aow7lb5cq1(X60Qii_62, 0);
                    string_0_sysvq0asl X60Qx_2181 = nimStrDup((*X60Qx_2180));
                    X60Qii_61 = X60Qx_2181;}
                  eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qii_62);}}
              NI32 X60Qx_2182 = len_4_sysvq0asl(X60Qii_61);
              if (X60Qx_2182 == 0){
                nimStrDestroy(X60Qii_61);
                nimStrDestroy(X60Qii_60);
                goto continueLabel_58;}
              CSig_0_aow7lb5cq1 X60Qtmp_122 = sigOf_0_aow7lb5cq1(src2_0, X60Qii_61);
              string_0_sysvq0asl X60Qii_63 = emitCShim_0_aow7lb5cq1((*X60Qii_59), X60Qii_61, strT2_0, longT2_0, allocFn2_0, deallocFn2_0, X60Qtmp_122, (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_2183 = len_4_sysvq0asl(X60Qii_63);
              if (X60Qx_2183 == 0){
                nimStrDestroy(X60Qii_63);
                eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(X60Qtmp_122);
                nimStrDestroy(X60Qii_61);
                nimStrDestroy(X60Qii_60);
                goto continueLabel_58;}
              NB8 X60Qx_2184;
              if (needStr_0){
                NB8 X60Qx_2185 = hasSub_0_aow7lb5cq1(shims_0, (string_0_sysvq0asl){
                  .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3443046107169670104_aow7lb5cq1)}
                );
                X60Qx_2184 = (!X60Qx_2185);}
              else {
                X60Qx_2184 = NIM_FALSE;}
              if (X60Qx_2184){
                string_0_sysvq0asl X60Qtmp_123 = strHelpers_0_aow7lb5cq1(strT2_0, longT2_0, borrowFn2_0);
                add_2_sysvq0asl((&shims_0), X60Qtmp_123);
                nimStrDestroy(X60Qtmp_123);}
              add_2_sysvq0asl((&shims_0), X60Qii_63);
              inc_1_I6wjjge_aow2h993l1((&n2_0));
              nimStrDestroy(X60Qii_63);
              eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(X60Qtmp_122);
              nimStrDestroy(X60Qii_61);
              nimStrDestroy(X60Qii_60);}
            continueLabel_58: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_65));}
        else {
          break;}}}
    whileStmtLabel_57: ;}
  forStmtLabel_56: ;
  if (n2_0 == 0){
    nimStrDestroy(shims_0);
    nimStrDestroy(allocFn2_0);
    nimStrDestroy(deallocFn2_0);
    nimStrDestroy(borrowFn2_0);
    nimStrDestroy(longT2_0);
    nimStrDestroy(strT2_0);
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_340);
    nimStrDestroy(X60Qdesugar_339);
    nimStrDestroy(X60Qdesugar_338);
    nimStrDestroy(cmd_2);
    nimStrDestroy(X60Qtmp_119);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_115);
    nimStrDestroy(drv_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
    nimStrDestroy(so_0);
    nimStrDestroy(initO_0);
    nimStrDestroy(initBody_0);
    nimStrDestroy(X60Qdesugar_316);
    nimStrDestroy(defBody_0);
    nimStrDestroy(exportDecls_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
    nimStrDestroy(initC_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  add_2_sysvq0asl((&src2_0), (string_0_sysvq0asl){
    .bytes_0 = 707726078u, .more_0 = (&strlit_0_I10597374192599734484_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&src2_0), shims_0);
  ErrorCode_0_sysvq0asl X60QcanRaise_6 = writeFile_0_syn1lfpjv(cFile2_0, src2_0);
  if (X60QcanRaise_6){
    goto X60Qexlab_15;}
  if (NIM_FALSE){
    X60Qexlab_15: ;
    nimStrDestroy(shims_0);
    nimStrDestroy(allocFn2_0);
    nimStrDestroy(deallocFn2_0);
    nimStrDestroy(borrowFn2_0);
    nimStrDestroy(longT2_0);
    nimStrDestroy(strT2_0);
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_340);
    nimStrDestroy(X60Qdesugar_339);
    nimStrDestroy(X60Qdesugar_338);
    nimStrDestroy(cmd_2);
    nimStrDestroy(X60Qtmp_119);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_115);
    nimStrDestroy(drv_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
    nimStrDestroy(so_0);
    nimStrDestroy(initO_0);
    nimStrDestroy(initBody_0);
    nimStrDestroy(X60Qdesugar_316);
    nimStrDestroy(defBody_0);
    nimStrDestroy(exportDecls_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
    nimStrDestroy(initC_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_95);
    nimStrDestroy(X60Qtmp_86);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_5);
    nimStrDestroy(strT_5);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
    nimStrDestroy(savedMainExt_0);
    nimStrDestroy(savedMainName_0);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_80);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_71);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(X60Qdesugar_278);
    nimStrDestroy(X60Qdesugar_277);
    nimStrDestroy(X60Qdesugar_276);
    nimStrDestroy(listFile_0);
    nimStrDestroy(stubRevisionFile_0);
    nimStrDestroy(logFile_5);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_65);
    return result_65;}
  NB8 X60Qx_2186;
  NB8 X60Qx_2187 = gccShared_0_aow7lb5cq1(cFile2_0, so_0, logFile_5);
  if (X60Qx_2187){
    NB8 X60Qx_2188 = fileExists_0_osc4bsu0d1(so_0);
    X60Qx_2186 = X60Qx_2188;}
  else {
    X60Qx_2186 = NIM_FALSE;}
  if (X60Qx_2186){
    nimStrDestroy(result_65);
    result_65 = so_0;
    nimStrWasMoved((&so_0));}
  nimStrDestroy(shims_0);
  nimStrDestroy(allocFn2_0);
  nimStrDestroy(deallocFn2_0);
  nimStrDestroy(borrowFn2_0);
  nimStrDestroy(longT2_0);
  nimStrDestroy(strT2_0);
  nimStrDestroy(src2_0);
  nimStrDestroy(X60Qdesugar_340);
  nimStrDestroy(X60Qdesugar_339);
  nimStrDestroy(X60Qdesugar_338);
  nimStrDestroy(cmd_2);
  nimStrDestroy(X60Qtmp_119);
  nimStrDestroy(cFile2_0);
  nimStrDestroy(X60Qtmp_115);
  nimStrDestroy(drv_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
  nimStrDestroy(so_0);
  nimStrDestroy(initO_0);
  nimStrDestroy(initBody_0);
  nimStrDestroy(X60Qdesugar_316);
  nimStrDestroy(defBody_0);
  nimStrDestroy(exportDecls_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
  nimStrDestroy(initC_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
  nimStrDestroy(X60Qtmp_95);
  nimStrDestroy(X60Qtmp_86);
  nimStrDestroy(deallocFn_3);
  nimStrDestroy(allocFn_2);
  nimStrDestroy(borrowFn_1);
  nimStrDestroy(longT_5);
  nimStrDestroy(strT_5);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
  nimStrDestroy(savedMainExt_0);
  nimStrDestroy(savedMainName_0);
  nimStrDestroy(savedMainDir_0);
  nimStrDestroy(X60Qtmp_80);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
  nimStrDestroy(stageDir_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
  nimStrDestroy(X60Qtmp_71);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
  nimStrDestroy(X60Qtmp_68);
  nimStrDestroy(X60Qdesugar_278);
  nimStrDestroy(X60Qdesugar_277);
  nimStrDestroy(X60Qdesugar_276);
  nimStrDestroy(listFile_0);
  nimStrDestroy(stubRevisionFile_0);
  nimStrDestroy(logFile_5);
  nimStrDestroy(cFile_0);
  nimStrDestroy(X60Qtmp_65);
  return result_65;
  nimStrDestroy(shims_0);
  nimStrDestroy(allocFn2_0);
  nimStrDestroy(deallocFn2_0);
  nimStrDestroy(borrowFn2_0);
  nimStrDestroy(longT2_0);
  nimStrDestroy(strT2_0);
  nimStrDestroy(src2_0);
  nimStrDestroy(X60Qdesugar_340);
  nimStrDestroy(X60Qdesugar_339);
  nimStrDestroy(X60Qdesugar_338);
  nimStrDestroy(cmd_2);
  nimStrDestroy(X60Qtmp_119);
  nimStrDestroy(cFile2_0);
  nimStrDestroy(X60Qtmp_115);
  nimStrDestroy(drv_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(missing_0);
  nimStrDestroy(so_0);
  nimStrDestroy(initO_0);
  nimStrDestroy(initBody_0);
  nimStrDestroy(X60Qdesugar_316);
  nimStrDestroy(defBody_0);
  nimStrDestroy(exportDecls_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(nativeExports_0);
  nimStrDestroy(initC_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(objs_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
  nimStrDestroy(X60Qtmp_95);
  nimStrDestroy(X60Qtmp_86);
  nimStrDestroy(deallocFn_3);
  nimStrDestroy(allocFn_2);
  nimStrDestroy(borrowFn_1);
  nimStrDestroy(longT_5);
  nimStrDestroy(strT_5);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_4);
  nimStrDestroy(savedMainExt_0);
  nimStrDestroy(savedMainName_0);
  nimStrDestroy(savedMainDir_0);
  nimStrDestroy(X60Qtmp_80);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_14);
  nimStrDestroy(stageDir_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
  nimStrDestroy(X60Qtmp_71);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
  nimStrDestroy(X60Qtmp_68);
  nimStrDestroy(X60Qdesugar_278);
  nimStrDestroy(X60Qdesugar_277);
  nimStrDestroy(X60Qdesugar_276);
  nimStrDestroy(listFile_0);
  nimStrDestroy(stubRevisionFile_0);
  nimStrDestroy(logFile_5);
  nimStrDestroy(cFile_0);
  nimStrDestroy(X60Qtmp_65);
  return result_65;}
void moduleSourceMap_0_aow7lb5cq1(string_0_sysvq0asl dir_0, string_0_sysvq0asl scratch_0, seq_0_Ixdx2fh1_aow7lb5cq1* mods_1, seq_0_Ixdx2fh1_aow7lb5cq1* srcs_0){
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*mods_1));
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2189 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  (*mods_1) = X60Qx_2189;
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*srcs_0));
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2190 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  (*srcs_0) = X60Qx_2190;
  string_0_sysvq0asl X60Qtmp_125 = parentDir_0_ospaexnw61(scratch_0);
  string_0_sysvq0asl X60Qtmp_124 = shMkdirP_0_hos14g919(X60Qtmp_125);
  NI32 X60Qx_2191 = execShellCmd_0_oswd7dmm(X60Qtmp_124);
  string_0_sysvq0asl X60Qtmp_126 = shRmF_0_hos14g919(scratch_0);
  NI32 X60Qx_2192 = execShellCmd_0_oswd7dmm(X60Qtmp_126);
  string_0_sysvq0asl X60Qdesugar_341 = quoteShell_0_oswd7dmm(dir_0);
  string_0_sysvq0asl X60Qdesugar_342 = quoteShell_0_oswd7dmm(scratch_0);
  NI32 X60Qx_2193 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I9946169762350422666_aow7lb5cq1)}
  );
  NI32 X60Qx_2194 = len_4_sysvq0asl(X60Qdesugar_341);
  NI32 X60Qx_2195 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 774516734u, .more_0 = (&strlit_0_I8938930563455684877_aow7lb5cq1)}
  );
  NI32 X60Qx_2196 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 757095422u, .more_0 = (&strlit_0_I17505878642142243233_aow7lb5cq1)}
  );
  NI32 X60Qx_2197 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1919183102u, .more_0 = (&strlit_0_I9003811850995758106_aow7lb5cq1)}
  );
  NI32 X60Qx_2198 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1668445182u, .more_0 = (&strlit_0_I5022596381085879336_aow7lb5cq1)}
  );
  NI32 X60Qx_2199 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1684370430u, .more_0 = (&strlit_0_I3301261775358999833_aow7lb5cq1)}
  );
  NI32 X60Qx_2200 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1769107710u, .more_0 = (&strlit_0_I1367334208925539560_aow7lb5cq1)}
  );
  NI32 X60Qx_2201 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1852794110u, .more_0 = (&strlit_0_I15015826066028142083_aow7lb5cq1)}
  );
  NI32 X60Qx_2202 = len_4_sysvq0asl(X60Qdesugar_342);
  NI32 X60Qx_2203 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I14102627614057926696_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_343 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_2193 + X60Qx_2194)) + X60Qx_2195)) + X60Qx_2196)) + X60Qx_2197)) + X60Qx_2198)) + X60Qx_2199)) + X60Qx_2200)) + X60Qx_2201)) + X60Qx_2202)) + X60Qx_2203)));
  add_2_sysvq0asl((&X60Qdesugar_343), (string_0_sysvq0asl){
    .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I9946169762350422666_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_343), X60Qdesugar_341);
  add_2_sysvq0asl((&X60Qdesugar_343), (string_0_sysvq0asl){
    .bytes_0 = 774516734u, .more_0 = (&strlit_0_I8938930563455684877_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_343), (string_0_sysvq0asl){
    .bytes_0 = 757095422u, .more_0 = (&strlit_0_I17505878642142243233_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_343), (string_0_sysvq0asl){
    .bytes_0 = 1919183102u, .more_0 = (&strlit_0_I9003811850995758106_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_343), (string_0_sysvq0asl){
    .bytes_0 = 1668445182u, .more_0 = (&strlit_0_I5022596381085879336_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_343), (string_0_sysvq0asl){
    .bytes_0 = 1684370430u, .more_0 = (&strlit_0_I3301261775358999833_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_343), (string_0_sysvq0asl){
    .bytes_0 = 1769107710u, .more_0 = (&strlit_0_I1367334208925539560_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_343), (string_0_sysvq0asl){
    .bytes_0 = 1852794110u, .more_0 = (&strlit_0_I15015826066028142083_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_343), X60Qdesugar_342);
  add_2_sysvq0asl((&X60Qdesugar_343), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I14102627614057926696_aow7lb5cq1)}
  );
  NI32 X60Qx_2204 = execShellCmd_0_oswd7dmm(X60Qdesugar_343);
  {
    string_0_sysvq0asl X60Qlf_66 = scratch_0;
    FILE* X60Qlf_67;
    NB8 X60Qx_2205 = open_0_syn1lfpjv((&X60Qlf_67), X60Qlf_66, 0, -1);
    if (X60Qx_2205){
      string_0_sysvq0asl X60Qlf_68 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      {
        while (NIM_TRUE){
          NB8 X60Qx_2206 = readLine_0_syn1lfpjv(X60Qlf_67, (&X60Qlf_68));
          if (X60Qx_2206){
            {
              {
                string_0_sysvq0asl X60Qii_3 = nimStrDup(X60Qlf_68);
                while (NIM_TRUE){
                  NB8 X60Qx_2207;
                  NI32 X60Qx_2208 = len_4_sysvq0asl(X60Qii_3);
                  if (0 < X60Qx_2208){
                    NB8 X60Qx_2209;
                    NB8 X60Qx_2210;
                    NI32 X60Qx_2211 = len_4_sysvq0asl(X60Qii_3);
                    NC8 X60Qx_2212 = getQ_9_sysvq0asl(X60Qii_3, ((NI32)(X60Qx_2211 - 1)));
                    if (X60Qx_2212 == (NC8)'\012'){
                      X60Qx_2210 = NIM_TRUE;}
                    else {
                      NI32 X60Qx_2213 = len_4_sysvq0asl(X60Qii_3);
                      NC8 X60Qx_2214 = getQ_9_sysvq0asl(X60Qii_3, ((NI32)(X60Qx_2213 - 1)));
                      X60Qx_2210 = (X60Qx_2214 == (NC8)'\015');}
                    if (X60Qx_2210){
                      X60Qx_2209 = NIM_TRUE;}
                    else {
                      NI32 X60Qx_2215 = len_4_sysvq0asl(X60Qii_3);
                      NC8 X60Qx_2216 = getQ_9_sysvq0asl(X60Qii_3, ((NI32)(X60Qx_2215 - 1)));
                      X60Qx_2209 = (X60Qx_2216 == (NC8)' ');}
                    X60Qx_2207 = X60Qx_2209;}
                  else {
                    X60Qx_2207 = NIM_FALSE;}
                  if (X60Qx_2207){
                    NI32 X60Qx_2217 = len_4_sysvq0asl(X60Qii_3);
                    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_2218 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_2217 - 2)));
                    string_0_sysvq0asl X60Qlhs_127 = getQ_14_sysvq0asl(X60Qii_3, X60Qx_2218);
                    nimStrDestroy(X60Qii_3);
                    X60Qii_3 = X60Qlhs_127;}
                  else {
                    break;}}
                NI32 X60Qx_2219 = len_4_sysvq0asl(X60Qii_3);
                if (X60Qx_2219 == 0){
                  nimStrDestroy(X60Qii_3);
                  goto continueLabel_2;}
                NI32 X60Qii_4 = -1;
                NI32 X60Qii_5 = 0;
                while (NIM_TRUE){
                  NI32 X60Qx_2220 = len_4_sysvq0asl(X60Qii_3);
                  if (X60Qii_5 < X60Qx_2220){
                    NC8 X60Qx_2221 = getQ_9_sysvq0asl(X60Qii_3, X60Qii_5);
                    if (X60Qx_2221 == (NC8)'\011'){
                      X60Qii_4 = X60Qii_5;
                      break;}
                    inc_1_I6wjjge_aow2h993l1((&X60Qii_5));}
                  else {
                    break;}}
                if (X60Qii_4 <= 0){
                  nimStrDestroy(X60Qii_3);
                  goto continueLabel_2;}
                HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_2222 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qii_4 - 1)));
                string_0_sysvq0asl X60Qx_2223 = getQ_14_sysvq0asl(X60Qii_3, X60Qx_2222);
                add_0_Ig6072n_aow7lb5cq1(mods_1, X60Qx_2223);
                string_0_sysvq0asl X60Qx_16;
                nimStrWasMoved((&X60Qx_16));
                NI32 X60Qx_2224 = len_4_sysvq0asl(X60Qii_3);
                if (((NI32)(X60Qii_4 + 1)) <= ((NI32)(X60Qx_2224 - 1))){
                  nimStrDestroy(X60Qx_16);
                  NI32 X60Qx_2225 = len_4_sysvq0asl(X60Qii_3);
                  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_2226 = ___1_Iclcqmw1_aow7lb5cq1(((NI32)(X60Qii_4 + 1)), ((NI32)(X60Qx_2225 - 1)));
                  string_0_sysvq0asl X60Qx_2227 = getQ_14_sysvq0asl(X60Qii_3, X60Qx_2226);
                  X60Qx_16 = X60Qx_2227;}
                else {
                  nimStrDestroy(X60Qx_16);
                  X60Qx_16 = (string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  ;}
                string_0_sysvq0asl X60Qtmp_128 = X60Qx_16;
                nimStrWasMoved((&X60Qx_16));
                add_0_Ig6072n_aow7lb5cq1(srcs_0, X60Qtmp_128);
                nimStrDestroy(X60Qx_16);
                nimStrDestroy(X60Qii_3);}
              continueLabel_2: ;}}
          else {
            break;}}}
      whileStmtLabel_1: ;
      NI32 X60Qx_2228 = fclose(X60Qlf_67);
      nimStrDestroy(X60Qlf_68);}}
  forStmtLabel_0: ;
  if (NIM_FALSE){
    X60Qexlab_16: ;}
  string_0_sysvq0asl X60Qtmp_129 = shRmF_0_hos14g919(scratch_0);
  NI32 X60Qx_2229 = execShellCmd_0_oswd7dmm(X60Qtmp_129);
  nimStrDestroy(X60Qtmp_129);
  nimStrDestroy(X60Qdesugar_343);
  nimStrDestroy(X60Qdesugar_342);
  nimStrDestroy(X60Qdesugar_341);
  nimStrDestroy(X60Qtmp_126);
  nimStrDestroy(X60Qtmp_124);
  nimStrDestroy(X60Qtmp_125);}
seq_0_Igzebks_aow7lb5cq1 jitEligibleEntries_0_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 entries_1){
  seq_0_Igzebks_aow7lb5cq1 result_66;
  eQwasMoved_1_Idjbhcw1_aow7lb5cq1((&result_66));
  eQdestroy_1_Iytr7x_aow7lb5cq1(result_66);
  seq_0_Igzebks_aow7lb5cq1 X60Qx_2230 = newSeqUninit_0_I6ffb0e1_aow7lb5cq1(0);
  result_66 = X60Qx_2230;
  string_0_sysvq0asl X60Qtmp_130 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 logDeclines_1 = eqQ_20_sysvq0asl(X60Qtmp_130, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  {
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_69 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_1);
    NI32 X60Qlf_70 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_2231 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_69);
        if (X60Qlf_70 < X60Qx_2231){
          {
            X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_2 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_69, X60Qlf_70);
            NB8 X60Qx_2232 = jitEligible_0_aow7lb5cq1((*X60Qii_2));
            if (X60Qx_2232){
              X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_2233 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1((*X60Qii_2));
              add_0_I9iil5u_aow7lb5cq1((&result_66), X60Qx_2233);}
            else {
              if (logDeclines_1){
                string_0_sysvq0asl X60Qdesugar_344 = nimStrDup((*(*X60Qii_2)).d_00.base_0);
                string_0_sysvq0asl X60Qdesugar_345 = jitDeclineReason_0_aow7lb5cq1((*X60Qii_2));
                NI32 X60Qx_2234 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                );
                NI32 X60Qx_2235 = len_4_sysvq0asl(X60Qdesugar_344);
                NI32 X60Qx_2236 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_2237 = len_4_sysvq0asl(X60Qdesugar_345);
                NI32 X60Qx_2238 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I1968479202869160466_aow7lb5cq1)}
                );
                string_0_sysvq0asl X60Qdesugar_346 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_2234 + X60Qx_2235)) + X60Qx_2236)) + X60Qx_2237)) + X60Qx_2238)));
                add_2_sysvq0asl((&X60Qdesugar_346), (string_0_sysvq0asl){
                  .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_346), X60Qdesugar_344);
                add_2_sysvq0asl((&X60Qdesugar_346), (string_0_sysvq0asl){
                  .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_346), X60Qdesugar_345);
                add_2_sysvq0asl((&X60Qdesugar_346), (string_0_sysvq0asl){
                  .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I1968479202869160466_aow7lb5cq1)}
                );
                write_0_syn1lfpjv(stderr, X60Qdesugar_346);
                nimStrDestroy(X60Qdesugar_346);
                nimStrDestroy(X60Qdesugar_345);
                nimStrDestroy(X60Qdesugar_344);}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_70));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  nimStrDestroy(X60Qtmp_130);
  return result_66;
  nimStrDestroy(X60Qtmp_130);
  return result_66;}
static inline openArray_0_Iczu4791_aow7lb5cq1 toOpenArray_1_I0ef4be1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_29){
  openArray_0_Iczu4791_aow7lb5cq1 result_68;
  WireField_0_run8hsnpi* X60Qx_2274 = rawData_0_Ijd497p_aow7lb5cq1(s_29);
  result_68 = (openArray_0_Iczu4791_aow7lb5cq1){
    .a_0 = X60Qx_2274, .len_0 = s_29.len_0}
  ;
  return result_68;}
static inline NI32 len_3_In63jw61_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_31){
  NI32 result_69;
  result_69 = s_31.len_0;
  return result_69;}
static inline WireField_0_run8hsnpi* getQ_7_Iko57h9_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_32, NI32 i_36){
  NB8 X60Qx_2275;
  if (i_36 < s_32.len_0){
    X60Qx_2275 = (0 <= i_36);}
  else {
    X60Qx_2275 = NIM_FALSE;}
  if ((!X60Qx_2275)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  WireField_0_run8hsnpi* result_70;
  result_70 = (&s_32.data_0[i_36]);
  return result_70;}
static inline NI32 len_3_I5m68tr1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_33){
  NI32 result_71;
  result_71 = s_33.len_0;
  return result_71;}
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_7_I45w7c91_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_34, NI32 i_37){
  NB8 X60Qx_2276;
  if (i_37 < s_34.len_0){
    X60Qx_2276 = (0 <= i_37);}
  else {
    X60Qx_2276 = NIM_FALSE;}
  if ((!X60Qx_2276)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** result_72;
  result_72 = (&s_34.data_0[i_37]);
  return result_72;}
static inline HSlice_0_Inzqy8d_aow7lb5cq1 ___1_Iclcqmw1_aow7lb5cq1(NI32 a_16, NI32 b_3){
  HSlice_0_Inzqy8d_aow7lb5cq1 result_73;
  result_73 = (HSlice_0_Inzqy8d_aow7lb5cq1){
    .a_0 = a_16, .b_0 = b_3}
  ;
  return result_73;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline seq_0_Irn2j6w_aow7lb5cq1 newSeqUninit_0_Ifa362m1_aow7lb5cq1(NI32 size_6){
  seq_0_Irn2j6w_aow7lb5cq1 result_74;
  if (size_6 == 0){
    result_74 = (seq_0_Irn2j6w_aow7lb5cq1){
      .len_0 = size_6, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_I5bna9k_aow7lb5cq1(size_6);
    void* X60Qx_2277 = alloc_1_sysvq0asl(memSize_0);
    result_74 = (seq_0_Irn2j6w_aow7lb5cq1){
      .len_0 = size_6, .data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1*)X60Qx_2277)}
    ;
    if ((!(result_74.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2278 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_74.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_74;}
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
static inline void add_0_I1xop2a1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* s_39, X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 elem_10){
  NI32 L_1 = (*s_39).len_0;
  NI32 X60Qx_2284 = capInBytes_0_Ikkv2nv1_aow7lb5cq1((*s_39));
  if (X60Qx_2284 < ((NI32)(((NI32)(L_1 * sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1))) + sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1)))){
    NB8 X60Qx_2285 = resize_0_I90dq91_aow7lb5cq1(s_39, 1);
    if ((!X60Qx_2285)){
      eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_aow7lb5cq1(elem_10);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_39).len_0));
  (*s_39).data_0[L_1] = elem_10;}
static inline NI32 len_3_Ijhqs0r1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_41){
  NI32 result_78;
  result_78 = s_41.len_0;
  return result_78;}
static inline X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* getQ_7_Irlfbqs1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_42, NI32 i_40){
  NB8 X60Qx_2286;
  if (i_40 < s_42.len_0){
    X60Qx_2286 = (0 <= i_40);}
  else {
    X60Qx_2286 = NIM_FALSE;}
  if ((!X60Qx_2286)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* result_79;
  result_79 = (&s_42.data_0[i_40]);
  return result_79;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_43){
  openArray_0_Ig73pnk_aow7lb5cq1 result_80;
  string_0_sysvq0asl* X60Qx_2287 = rawData_0_I65w5sr_aow7lb5cq1(s_43);
  result_80 = (openArray_0_Ig73pnk_aow7lb5cq1){
    .a_0 = X60Qx_2287, .len_0 = s_43.len_0}
  ;
  return result_80;}
static inline openArray_0_Inqs7yx_aow7lb5cq1 toOpenArray_0_Iccbrld_aow7lb5cq1(X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1* x_8){
  openArray_0_Inqs7yx_aow7lb5cq1 result_81;
  openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_17;
  if (((NI32)(((NI32)(((NI32)((NI32)3)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_17 = (openArray_0_Inqs7yx_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_17 = (openArray_0_Inqs7yx_aow7lb5cq1){
      .a_0 = ((NI32*)(&(*x_8))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)3)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_81 = X60Qx_17;
  return result_81;}
static inline NB8 contains_3_Ipa7o28_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_21, NI32 elem_11){
  NB8 result_82;
  NI32 X60Qx_2288 = find_0_Iaugz2s1_aow7lb5cq1(a_21, elem_11);
  result_82 = (0 <= X60Qx_2288);
  return result_82;}
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45){
  NI32 result_83;
  result_83 = s_45.len_0;
  return result_83;}
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_42){
  NB8 X60Qx_2289;
  if (i_42 < s_46.len_0){
    X60Qx_2289 = (0 <= i_42);}
  else {
    X60Qx_2289 = NIM_FALSE;}
  if ((!X60Qx_2289)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NI32* result_84;
  result_84 = (&s_46.data_0[i_42]);
  return result_84;}
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10){
  seq_0_Ift2sne_aow7lb5cq1 result_85;
  if (size_10 == 0){
    result_85 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Inv7kg3_aow7lb5cq1(size_10);
    void* X60Qx_2290 = alloc_1_sysvq0asl(memSize_2);
    result_85 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = ((NI32*)X60Qx_2290)}
    ;
    if ((!(result_85.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2291 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_85.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_85;}
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_2292 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_2292 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_2293 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_2293)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
static inline seq_0_Ik7wkpe_aow7lb5cq1 newSeqUninit_0_Idxnvmq_aow7lb5cq1(NI32 size_12){
  seq_0_Ik7wkpe_aow7lb5cq1 result_86;
  if (size_12 == 0){
    result_86 = (seq_0_Ik7wkpe_aow7lb5cq1){
      .len_0 = size_12, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_I03jys01_aow7lb5cq1(size_12);
    void* X60Qx_2294 = alloc_1_sysvq0asl(memSize_3);
    result_86 = (seq_0_Ik7wkpe_aow7lb5cq1){
      .len_0 = size_12, .data_0 = ((seq_0_Ift2sne_aow7lb5cq1*)X60Qx_2294)}
    ;
    if ((!(result_86.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2295 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_86.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_86;}
static inline void add_0_Iivdbhc_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1* s_49, seq_0_Ift2sne_aow7lb5cq1 elem_14){
  NI32 L_3 = (*s_49).len_0;
  NI32 X60Qx_2296 = capInBytes_0_Iri1hlt1_aow7lb5cq1((*s_49));
  if (X60Qx_2296 < ((NI32)(((NI32)(L_3 * sizeof(seq_0_Ift2sne_aow7lb5cq1))) + sizeof(seq_0_Ift2sne_aow7lb5cq1)))){
    NB8 X60Qx_2297 = resize_0_I9lztdq1_aow7lb5cq1(s_49, 1);
    if ((!X60Qx_2297)){
      eQdestroy_1_Iv9ij5i1_aow7lb5cq1(elem_14);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_49).len_0));
  (*s_49).data_0[L_3] = elem_14;}
static inline seq_0_Ift2sne_aow7lb5cq1* getQ_7_Iurb46i_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_51, NI32 i_43){
  NB8 X60Qx_2298;
  if (i_43 < s_51.len_0){
    X60Qx_2298 = (0 <= i_43);}
  else {
    X60Qx_2298 = NIM_FALSE;}
  if ((!X60Qx_2298)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  seq_0_Ift2sne_aow7lb5cq1* result_87;
  result_87 = (&s_51.data_0[i_43]);
  return result_87;}
static inline void putQ_7_Ifvyck5_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_52, NI32 i_44, NI32 elem_15){
  NB8 X60Qx_2299;
  if (i_44 < (*s_52).len_0){
    X60Qx_2299 = (0 <= i_44);}
  else {
    X60Qx_2299 = NIM_FALSE;}
  if ((!X60Qx_2299)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_52).data_0[i_44] = elem_15;}
static inline seq_0_Iflf8jf1_aow7lb5cq1 newSeqUninit_0_I5mozxi1_aow7lb5cq1(NI32 size_14){
  seq_0_Iflf8jf1_aow7lb5cq1 result_88;
  if (size_14 == 0){
    result_88 = (seq_0_Iflf8jf1_aow7lb5cq1){
      .len_0 = size_14, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_4 = memSizeInBytes_0_Ih4q01h_aow7lb5cq1(size_14);
    void* X60Qx_2300 = alloc_1_sysvq0asl(memSize_4);
    result_88 = (seq_0_Iflf8jf1_aow7lb5cq1){
      .len_0 = size_14, .data_0 = ((NB8*)X60Qx_2300)}
    ;
    if ((!(result_88.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2301 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_88.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_4);}}
  return result_88;}
static inline void add_0_Irnc3p1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_53, NB8 elem_16){
  NI32 L_4 = (*s_53).len_0;
  NI32 X60Qx_2302 = capInBytes_0_In1m6ni_aow7lb5cq1((*s_53));
  if (X60Qx_2302 < ((NI32)(((NI32)(L_4 * sizeof(NB8))) + sizeof(NB8)))){
    NB8 X60Qx_2303 = resize_0_I2yw78g1_aow7lb5cq1(s_53, 1);
    if ((!X60Qx_2303)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_53).len_0));
  (*s_53).data_0[L_4] = elem_16;}
static inline NB8* getQ_7_Iul1no9_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_55, NI32 i_45){
  NB8 X60Qx_2304;
  if (i_45 < s_55.len_0){
    X60Qx_2304 = (0 <= i_45);}
  else {
    X60Qx_2304 = NIM_FALSE;}
  if ((!X60Qx_2304)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NB8* result_89;
  result_89 = (&s_55.data_0[i_45]);
  return result_89;}
static inline void putQ_7_Iiblebk_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_56, NI32 i_46, NB8 elem_17){
  NB8 X60Qx_2305;
  if (i_46 < (*s_56).len_0){
    X60Qx_2305 = (0 <= i_46);}
  else {
    X60Qx_2305 = NIM_FALSE;}
  if ((!X60Qx_2305)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_56).data_0[i_46] = elem_17;}
static inline openArray_0_Inqs7yx_aow7lb5cq1 toOpenArray_1_Ibqb4ob_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_57){
  openArray_0_Inqs7yx_aow7lb5cq1 result_90;
  NI32* X60Qx_2306 = rawData_0_Ic25u3r_aow7lb5cq1(s_57);
  result_90 = (openArray_0_Inqs7yx_aow7lb5cq1){
    .a_0 = X60Qx_2306, .len_0 = s_57.len_0}
  ;
  return result_90;}
static inline seq_0_Igzebks_aow7lb5cq1 newSeqUninit_0_I6ffb0e1_aow7lb5cq1(NI32 size_16){
  seq_0_Igzebks_aow7lb5cq1 result_91;
  if (size_16 == 0){
    result_91 = (seq_0_Igzebks_aow7lb5cq1){
      .len_0 = size_16, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_5 = memSizeInBytes_0_I21ctpp_aow7lb5cq1(size_16);
    void* X60Qx_2307 = alloc_1_sysvq0asl(memSize_5);
    result_91 = (seq_0_Igzebks_aow7lb5cq1){
      .len_0 = size_16, .data_0 = ((X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1**)X60Qx_2307)}
    ;
    if ((!(result_91.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2308 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_91.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_5);}}
  return result_91;}
static inline NI32 len_3_I44vue3_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_59){
  NI32 result_92;
  result_92 = s_59.len_0;
  return result_92;}
static inline openArray_0_In0ukmu_aow7lb5cq1 toOpenArray_1_Ijdwnsz_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_60){
  openArray_0_In0ukmu_aow7lb5cq1 result_93;
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qx_2309 = rawData_0_Izez9p81_aow7lb5cq1(s_60);
  result_93 = (openArray_0_In0ukmu_aow7lb5cq1){
    .a_0 = X60Qx_2309, .len_0 = s_60.len_0}
  ;
  return result_93;}
static inline void add_0_I9iil5u_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* s_62, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* elem_18){
  NI32 L_5 = (*s_62).len_0;
  NI32 X60Qx_2310 = capInBytes_0_Iekd9qh_aow7lb5cq1((*s_62));
  if (X60Qx_2310 < ((NI32)(((NI32)(L_5 * sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*))) + sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*)))){
    NB8 X60Qx_2311 = resize_0_Ifgwwnv_aow7lb5cq1(s_62, 1);
    if ((!X60Qx_2311)){
      eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(elem_18);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_62).len_0));
  (*s_62).data_0[L_5] = elem_18;}
static inline HSlice_0_Inzqy8d_aow7lb5cq1 __ltQ_1_Ij9jwi_aow7lb5cq1(NI32 a_27, NI32 b_4){
  HSlice_0_Inzqy8d_aow7lb5cq1 result_94;
  result_94 = (HSlice_0_Inzqy8d_aow7lb5cq1){
    .a_0 = a_27, .b_0 = ((NI32)(b_4 - ((NI32)1)))}
  ;
  return result_94;}
static inline WireField_0_run8hsnpi* rawData_0_Ijd497p_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_64){
  WireField_0_run8hsnpi* result_95;
  result_95 = s_64.data_0;
  return result_95;}
static inline NI32 len_6_Ier6z6r1_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 a_28){
  NI32 result_96;
  result_96 = a_28.len_0;
  return result_96;}
static inline WireField_0_run8hsnpi* getQ_10_Id2924z_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 x_11, NI32 idx_5){
  NB8 X60Qx_2312;
  if (0 <= idx_5){
    X60Qx_2312 = (idx_5 < x_11.len_0);}
  else {
    X60Qx_2312 = NIM_FALSE;}
  if ((!X60Qx_2312)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  WireField_0_run8hsnpi* result_97;
  result_97 = (&x_11.a_0[idx_5]);
  return result_97;}
static inline NI32 memSizeInBytes_0_I5bna9k_aow7lb5cq1(NI32 size_18){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_98;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_18, sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_98 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_98 = ((NI32)2147483647);}
  return result_98;}
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
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_29){
  NI32 result_100;
  result_100 = a_29.len_0;
  return result_100;}
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6){
  NB8 X60Qx_2313;
  if (0 <= idx_6){
    X60Qx_2313 = (idx_6 < x_12.len_0);}
  else {
    X60Qx_2313 = NIM_FALSE;}
  if ((!X60Qx_2313)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NC8* result_101;
  result_101 = (&x_12.a_0[idx_6]);
  return result_101;}
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
NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6){
  NB8 result_103;
  NI32 X60Qx_2315 = capInBytes_0_Ih2sbn01_aow7lb5cq1((*dest_6));
  NI32 oldCap_0 = ((NI32)(X60Qx_2315 / sizeof(string_0_sysvq0asl)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_6);
  NI32 memSize_6 = memSizeInBytes_0_I7me00i_aow7lb5cq1(newCap_0);
  void* X60Qx_2316 = realloc_1_sysvq0asl(((void*)((void*)(*dest_6).data_0)), memSize_6);
  (*dest_6).data_0 = ((string_0_sysvq0asl*)X60Qx_2316);
  if ((*dest_6).data_0 == NIM_NIL){
    (*dest_6).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_6);
    result_103 = NIM_FALSE;}
  else {
    result_103 = NIM_TRUE;}
  return result_103;}
static inline NI32 capInBytes_0_Ikkv2nv1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_66){
  NI32 result_104;
  NI32 X60Qx_19;
  if ((!(s_66.data_0 == NIM_NIL))){
    NI32 X60Qx_2317 = allocatedSize_0_sysvq0asl(((void*)((void*)s_66.data_0)));
    X60Qx_19 = X60Qx_2317;}
  else {
    X60Qx_19 = 0;}
  result_104 = X60Qx_19;
  return result_104;}
NB8 resize_0_I90dq91_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* dest_7, NI32 addedElements_7){
  NB8 result_105;
  NI32 X60Qx_2318 = capInBytes_0_Ikkv2nv1_aow7lb5cq1((*dest_7));
  NI32 oldCap_1 = ((NI32)(X60Qx_2318 / sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_7);
  NI32 memSize_7 = memSizeInBytes_0_I5bna9k_aow7lb5cq1(newCap_1);
  void* X60Qx_2319 = realloc_1_sysvq0asl(((void*)((void*)(*dest_7).data_0)), memSize_7);
  (*dest_7).data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1*)X60Qx_2319);
  if ((*dest_7).data_0 == NIM_NIL){
    (*dest_7).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_7);
    result_105 = NIM_FALSE;}
  else {
    result_105 = NIM_TRUE;}
  return result_105;}
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67){
  string_0_sysvq0asl* result_106;
  result_106 = s_67.data_0;
  return result_106;}
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_30){
  NI32 result_107;
  result_107 = a_30.len_0;
  return result_107;}
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7){
  NB8 X60Qx_2320;
  if (0 <= idx_7){
    X60Qx_2320 = (idx_7 < x_13.len_0);}
  else {
    X60Qx_2320 = NIM_FALSE;}
  if ((!X60Qx_2320)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  string_0_sysvq0asl* result_108;
  result_108 = (&x_13.a_0[idx_7]);
  return result_108;}
NI32 find_0_Iaugz2s1_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_31, NI32 elem_19){
  NI32 result_109;
  NI32 i_49 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_2321 = len_6_I9632ti1_aow7lb5cq1(a_31);
      if (i_49 < X60Qx_2321){
        NI32* X60Qx_2322 = getQ_10_I053icq_aow7lb5cq1(a_31, i_49);
        if ((*X60Qx_2322) == elem_19){
          return i_49;}
        inc_1_I6wjjge_aow2h993l1((&i_49));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return -1;
  return result_109;}
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_110;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_20, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_110 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_110 = ((NI32)2147483647);}
  return result_110;}
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68){
  NI32 result_111;
  NI32 X60Qx_20;
  if ((!(s_68.data_0 == NIM_NIL))){
    NI32 X60Qx_2323 = allocatedSize_0_sysvq0asl(((void*)((void*)s_68.data_0)));
    X60Qx_20 = X60Qx_2323;}
  else {
    X60Qx_20 = 0;}
  result_111 = X60Qx_20;
  return result_111;}
NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8){
  NB8 result_112;
  NI32 X60Qx_2324 = capInBytes_0_Iet286n_aow7lb5cq1((*dest_8));
  NI32 oldCap_2 = ((NI32)(X60Qx_2324 / sizeof(NI32)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_8);
  NI32 memSize_8 = memSizeInBytes_0_Inv7kg3_aow7lb5cq1(newCap_2);
  void* X60Qx_2325 = realloc_1_sysvq0asl(((void*)((void*)(*dest_8).data_0)), memSize_8);
  (*dest_8).data_0 = ((NI32*)X60Qx_2325);
  if ((*dest_8).data_0 == NIM_NIL){
    (*dest_8).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_8);
    result_112 = NIM_FALSE;}
  else {
    result_112 = NIM_TRUE;}
  return result_112;}
static inline NI32 memSizeInBytes_0_I03jys01_aow7lb5cq1(NI32 size_21){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_113;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_21, sizeof(seq_0_Ift2sne_aow7lb5cq1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_113 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_113 = ((NI32)2147483647);}
  return result_113;}
static inline NI32 capInBytes_0_Iri1hlt1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_69){
  NI32 result_114;
  NI32 X60Qx_21;
  if ((!(s_69.data_0 == NIM_NIL))){
    NI32 X60Qx_2326 = allocatedSize_0_sysvq0asl(((void*)((void*)s_69.data_0)));
    X60Qx_21 = X60Qx_2326;}
  else {
    X60Qx_21 = 0;}
  result_114 = X60Qx_21;
  return result_114;}
NB8 resize_0_I9lztdq1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1* dest_9, NI32 addedElements_9){
  NB8 result_115;
  NI32 X60Qx_2327 = capInBytes_0_Iri1hlt1_aow7lb5cq1((*dest_9));
  NI32 oldCap_3 = ((NI32)(X60Qx_2327 / sizeof(seq_0_Ift2sne_aow7lb5cq1)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_9);
  NI32 memSize_9 = memSizeInBytes_0_I03jys01_aow7lb5cq1(newCap_3);
  void* X60Qx_2328 = realloc_1_sysvq0asl(((void*)((void*)(*dest_9).data_0)), memSize_9);
  (*dest_9).data_0 = ((seq_0_Ift2sne_aow7lb5cq1*)X60Qx_2328);
  if ((*dest_9).data_0 == NIM_NIL){
    (*dest_9).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_9);
    result_115 = NIM_FALSE;}
  else {
    result_115 = NIM_TRUE;}
  return result_115;}
static inline NI32 memSizeInBytes_0_Ih4q01h_aow7lb5cq1(NI32 size_22){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_116;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_22, sizeof(NB8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_116 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_116 = ((NI32)2147483647);}
  return result_116;}
static inline NI32 capInBytes_0_In1m6ni_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_70){
  NI32 result_117;
  NI32 X60Qx_22;
  if ((!(s_70.data_0 == NIM_NIL))){
    NI32 X60Qx_2329 = allocatedSize_0_sysvq0asl(((void*)((void*)s_70.data_0)));
    X60Qx_22 = X60Qx_2329;}
  else {
    X60Qx_22 = 0;}
  result_117 = X60Qx_22;
  return result_117;}
NB8 resize_0_I2yw78g1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* dest_10, NI32 addedElements_10){
  NB8 result_118;
  NI32 X60Qx_2330 = capInBytes_0_In1m6ni_aow7lb5cq1((*dest_10));
  NI32 oldCap_4 = ((NI32)(X60Qx_2330 / sizeof(NB8)));
  NI32 newCap_4 = recalcCap_0_sysvq0asl(oldCap_4, addedElements_10);
  NI32 memSize_10 = memSizeInBytes_0_Ih4q01h_aow7lb5cq1(newCap_4);
  void* X60Qx_2331 = realloc_1_sysvq0asl(((void*)((void*)(*dest_10).data_0)), memSize_10);
  (*dest_10).data_0 = ((NB8*)X60Qx_2331);
  if ((*dest_10).data_0 == NIM_NIL){
    (*dest_10).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_10);
    result_118 = NIM_FALSE;}
  else {
    result_118 = NIM_TRUE;}
  return result_118;}
static inline NI32* rawData_0_Ic25u3r_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_71){
  NI32* result_119;
  result_119 = s_71.data_0;
  return result_119;}
static inline NI32 len_6_I9632ti1_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_32){
  NI32 result_120;
  result_120 = a_32.len_0;
  return result_120;}
static inline NI32* getQ_10_I053icq_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 x_14, NI32 idx_8){
  NB8 X60Qx_2332;
  if (0 <= idx_8){
    X60Qx_2332 = (idx_8 < x_14.len_0);}
  else {
    X60Qx_2332 = NIM_FALSE;}
  if ((!X60Qx_2332)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NI32* result_121;
  result_121 = (&x_14.a_0[idx_8]);
  return result_121;}
static inline NI32 memSizeInBytes_0_I21ctpp_aow7lb5cq1(NI32 size_23){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_122;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_23, sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_122 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_122 = ((NI32)2147483647);}
  return result_122;}
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** rawData_0_Izez9p81_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_72){
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** result_123;
  result_123 = s_72.data_0;
  return result_123;}
static inline NI32 len_6_Iu1dtri1_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 a_33){
  NI32 result_124;
  result_124 = a_33.len_0;
  return result_124;}
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** getQ_10_I6a58n11_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 x_15, NI32 idx_9){
  NB8 X60Qx_2333;
  if (0 <= idx_9){
    X60Qx_2333 = (idx_9 < x_15.len_0);}
  else {
    X60Qx_2333 = NIM_FALSE;}
  if ((!X60Qx_2333)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** result_125;
  result_125 = (&x_15.a_0[idx_9]);
  return result_125;}
static inline NI32 capInBytes_0_Iekd9qh_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_73){
  NI32 result_126;
  NI32 X60Qx_23;
  if ((!(s_73.data_0 == NIM_NIL))){
    NI32 X60Qx_2334 = allocatedSize_0_sysvq0asl(((void*)((void*)s_73.data_0)));
    X60Qx_23 = X60Qx_2334;}
  else {
    X60Qx_23 = 0;}
  result_126 = X60Qx_23;
  return result_126;}
NB8 resize_0_Ifgwwnv_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* dest_11, NI32 addedElements_11){
  NB8 result_127;
  NI32 X60Qx_2335 = capInBytes_0_Iekd9qh_aow7lb5cq1((*dest_11));
  NI32 oldCap_5 = ((NI32)(X60Qx_2335 / sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*)));
  NI32 newCap_5 = recalcCap_0_sysvq0asl(oldCap_5, addedElements_11);
  NI32 memSize_11 = memSizeInBytes_0_I21ctpp_aow7lb5cq1(newCap_5);
  void* X60Qx_2336 = realloc_1_sysvq0asl(((void*)((void*)(*dest_11).data_0)), memSize_11);
  (*dest_11).data_0 = ((X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1**)X60Qx_2336);
  if ((*dest_11).data_0 == NIM_NIL){
    (*dest_11).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_11);
    result_127 = NIM_FALSE;}
  else {
    result_127 = NIM_TRUE;}
  return result_127;}
void eQdestroy_1_Iem8q971_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_90){
  if ((!(s_90.data_0 == NIM_NIL))){
    NI32 i_50 = 0;
    {
      while (i_50 < s_90.len_0){
        eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_aow7lb5cq1(s_90.data_0[i_50]);
        inc_1_I6wjjge_aow2h993l1((&i_50));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_90.data_0)));}}
static inline void eQwasMoved_1_I3l7wpx1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* s_91){
  (*s_91).len_0 = 0;
  (*s_91).data_0 = NIM_NIL;}
void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92){
  if ((!(s_92.data_0 == NIM_NIL))){
    NI32 i_54 = 0;
    {
      while (i_54 < s_92.len_0){
        nimStrDestroy(s_92.data_0[i_54]);
        inc_1_I6wjjge_aow2h993l1((&i_54));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_92.data_0)));}}
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93){
  (*s_93).len_0 = 0;
  (*s_93).data_0 = NIM_NIL;}
seq_0_Ixdx2fh1_aow7lb5cq1 eQdup_1_Imq0s4c_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 a_43){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_129;
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_2343 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(a_43.len_0);
  result_129 = X60Qx_2343;
  NI32 i_55 = 0;
  {
    while (i_55 < a_43.len_0){
      string_0_sysvq0asl X60Qx_2344 = nimStrDup(a_43.data_0[i_55]);
      result_129.data_0[i_55] = X60Qx_2344;
      inc_1_I6wjjge_aow2h993l1((&i_55));}}
  whileStmtLabel_0: ;
  return result_129;}
void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94){
  if ((!(s_94.data_0 == NIM_NIL))){
    NI32 i_58 = 0;
    {
      while (i_58 < s_94.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_58));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_94.data_0)));}}
static inline void eQwasMoved_1_Ix88qzs1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_95){
  (*s_95).len_0 = 0;
  (*s_95).data_0 = NIM_NIL;}
seq_0_Ift2sne_aow7lb5cq1 eQdup_1_Iplow11_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 a_44){
  seq_0_Ift2sne_aow7lb5cq1 result_130;
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_2349 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(a_44.len_0);
  result_130 = X60Qx_2349;
  NI32 i_59 = 0;
  {
    while (i_59 < a_44.len_0){
      result_130.data_0[i_59] = a_44.data_0[i_59];
      inc_1_I6wjjge_aow2h993l1((&i_59));}}
  whileStmtLabel_0: ;
  return result_130;}
void eQdestroy_1_Iytr7x_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_96){
  if ((!(s_96.data_0 == NIM_NIL))){
    NI32 i_62 = 0;
    {
      while (i_62 < s_96.len_0){
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(s_96.data_0[i_62]);
        inc_1_I6wjjge_aow2h993l1((&i_62));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_96.data_0)));}}
static inline void eQwasMoved_1_Idjbhcw1_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* s_97){
  (*s_97).len_0 = 0;
  (*s_97).data_0 = NIM_NIL;}
seq_0_Igzebks_aow7lb5cq1 eQdup_1_Imteumu1_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 a_45){
  seq_0_Igzebks_aow7lb5cq1 result_131;
  seq_0_Igzebks_aow7lb5cq1 X60Qx_2353 = newSeqUninit_0_I6ffb0e1_aow7lb5cq1(a_45.len_0);
  result_131 = X60Qx_2353;
  NI32 i_63 = 0;
  {
    while (i_63 < a_45.len_0){
      X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_2354 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(a_45.data_0[i_63]);
      result_131.data_0[i_63] = X60Qx_2354;
      inc_1_I6wjjge_aow2h993l1((&i_63));}}
  whileStmtLabel_0: ;
  return result_131;}
void eQdestroy_1_Ij4pznj1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_98){
  if ((!(s_98.data_0 == NIM_NIL))){
    NI32 i_66 = 0;
    {
      while (i_66 < s_98.len_0){
        eQdestroy_1_Iv9ij5i1_aow7lb5cq1(s_98.data_0[i_66]);
        inc_1_I6wjjge_aow2h993l1((&i_66));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_98.data_0)));}}
void eQdestroy_1_I7a20g9_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_100){
  if ((!(s_100.data_0 == NIM_NIL))){
    NI32 i_70 = 0;
    {
      while (i_70 < s_100.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_70));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_100.data_0)));}}
void eQdestroy_1_Iksn09f_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_102){
  if ((!(s_102.data_0 == NIM_NIL))){
    NI32 i_74 = 0;
    {
      while (i_74 < s_102.len_0){
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&s_102.data_0[i_74]));
        inc_1_I6wjjge_aow2h993l1((&i_74));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_102.data_0)));}}
void eQdestroy_1_Iqg9snl1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_105){
  if ((!(s_105.data_0 == NIM_NIL))){
    NI32 i_78 = 0;
    {
      while (i_78 < s_105.len_0){
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(s_105.data_0[i_78]);
        inc_1_I6wjjge_aow2h993l1((&i_78));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_105.data_0)));}}
static inline void eQwasMoved_1_Iba95rl_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1* s_106){
  (*s_106).len_0 = 0;
  (*s_106).data_0 = NIM_NIL;}
static inline seq_0_Il8twp61_aow7lb5cq1 newSeqUninit_0_Iopvcdu1_aow7lb5cq1(NI32 size_28){
  seq_0_Il8twp61_aow7lb5cq1 result_136;
  if (size_28 == 0){
    result_136 = (seq_0_Il8twp61_aow7lb5cq1){
      .len_0 = size_28, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_20 = memSizeInBytes_0_Io786y61_aow7lb5cq1(size_28);
    void* X60Qx_2381 = alloc_1_sysvq0asl(memSize_20);
    result_136 = (seq_0_Il8twp61_aow7lb5cq1){
      .len_0 = size_28, .data_0 = ((WireField_0_run8hsnpi*)X60Qx_2381)}
    ;
    if ((!(result_136.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2382 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_136.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_20);}}
  return result_136;}
static inline NI32 capInBytes_0_I51wdad1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_108){
  NI32 result_137;
  NI32 X60Qx_24;
  if ((!(s_108.data_0 == NIM_NIL))){
    NI32 X60Qx_2383 = allocatedSize_0_sysvq0asl(((void*)((void*)s_108.data_0)));
    X60Qx_24 = X60Qx_2383;}
  else {
    X60Qx_24 = 0;}
  result_137 = X60Qx_24;
  return result_137;}
static inline NI32 memSizeInBytes_0_Io786y61_aow7lb5cq1(NI32 size_29){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_138;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_29, sizeof(WireField_0_run8hsnpi), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_138 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_138 = ((NI32)2147483647);}
  return result_138;}
static inline seq_0_I3ump14_aow7lb5cq1 newSeqUninit_0_I978ktq1_aow7lb5cq1(NI32 size_30){
  seq_0_I3ump14_aow7lb5cq1 result_139;
  if (size_30 == 0){
    result_139 = (seq_0_I3ump14_aow7lb5cq1){
      .len_0 = size_30, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_21 = memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(size_30);
    void* X60Qx_2384 = alloc_1_sysvq0asl(memSize_21);
    result_139 = (seq_0_I3ump14_aow7lb5cq1){
      .len_0 = size_30, .data_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1**)X60Qx_2384)}
    ;
    if ((!(result_139.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2385 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_139.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_21);}}
  return result_139;}
static inline NI32 capInBytes_0_Iho46001_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_109){
  NI32 result_140;
  NI32 X60Qx_25;
  if ((!(s_109.data_0 == NIM_NIL))){
    NI32 X60Qx_2386 = allocatedSize_0_sysvq0asl(((void*)((void*)s_109.data_0)));
    X60Qx_25 = X60Qx_2386;}
  else {
    X60Qx_25 = 0;}
  result_140 = X60Qx_25;
  return result_140;}
static inline NI32 memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(NI32 size_31){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_141;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_31, sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_141 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_141 = ((NI32)2147483647);}
  return result_141;}
void eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(CSig_0_aow7lb5cq1 dest_0){
  eQdestroy_1_Ivioh0a_aow7lb5cq1(dest_0.params_0);
  nimStrDestroy(dest_0.ret_0);}
void eQwasmovedQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(CSig_0_aow7lb5cq1* dest_0){
  nimStrWasMoved((&(*dest_0).ret_0));
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&(*dest_0).params_0));}
void eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_2389 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2389){
      eQdestroyQ_SX54ypeX44escX4fbj0layptix6a1_0_layptix6a1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* src_0){
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQwasmovedQ_AtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_0_aow7lb5cq1(X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1* dest_0){
  nimStrWasMoved((&(*dest_0).fld_1));
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&(*dest_0).fld_2));}
void eQdestroyQ_AtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_0_aow7lb5cq1(X60Qt_0_IAtupleAboolZSstring0sysvq0aslSseq0X49xdx2fh1_aow7lb5cq1 dest_0){
  nimStrDestroy(dest_0.fld_1);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(dest_0.fld_2);}
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* src_0){
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_aow7lb5cq1(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 dest_0){
  nimStrDestroy(dest_0.fld_0);
  nimStrDestroy(dest_0.fld_1);}
void eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_2390 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2390){
      eQdestroyQ_SX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void X60Qini_0_aow7lb5cq1(void){
  if (X60QiniGuard_0_aow7lb5cq1){
    return;}
  X60QiniGuard_0_aow7lb5cq1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_envto7w6l1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_aowqg5vb41();
  X60Qini_0_layptix6a1();
  X60Qini_0_heapjafyf1();
  X60Qini_0_marbdjk4t1();
  X60Qini_0_run8hsnpi();
  X60Qini_0_croph25r5();
  X60Qini_0_buiyylk1h1();
  X60Qini_0_prorcx25w1();
  X60Qini_0_hos14g919();
  X60Qini_0_emi78vuj01();}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_aow7lb5cq1 x_355){
  string_0_sysvq0asl result_224;
  nimStrWasMoved((&result_224));
  nimStrDestroy(result_224);
  string_0_sysvq0asl X60Qx_437 = substr_0_sysvq0asl(s_77, x_355.a_0, x_355.b_0);
  result_224 = X60Qx_437;
  return result_224;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67){
  openArray_0_Ijk0jkw1_aow7lb5cq1 result_146;
  NC8* X60Qx_316 = readRawData_0_sysvq0asl((&(*s_67)), 0);
  NI32 X60Qx_317 = len_4_sysvq0asl((*s_67));
  result_146 = (openArray_0_Ijk0jkw1_aow7lb5cq1){
    .a_0 = X60Qx_316, .len_0 = X60Qx_317}
  ;
  return result_146;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline NI32 align_0_layptix6a1(NI32 address_0, NI32 alignment_0){
  NI32 result_1;
  result_1 = ((NI32)(((NI32)(address_0 + ((NI32)(alignment_0 - 1)))) & ((NI32) ~ ((NI32)(alignment_0 - 1)))));
  return result_1;}
static inline string_0_sysvq0asl slashQ_0_ospaexnw61(string_0_sysvq0asl head_1, string_0_sysvq0asl tail_2){
  string_0_sysvq0asl result_2;
  nimStrWasMoved((&result_2));
  string_0_sysvq0asl X60Qx_39 = (string_0_sysvq0asl){
    .bytes_0 = 1852271102u, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  nimStrDestroy(result_2);
  string_0_sysvq0asl X60Qx_40 = joinPath_0_ospaexnw61(head_1, tail_2);
  result_2 = X60Qx_40;
  return result_2;}
static inline void endRead_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_5){
  }
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3){
  if ((!((*dest_3).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*dest_3).owner_0).rc_0));
    if ((*(*dest_3).owner_0).rc_0 == 0){
      if ((!((*(*dest_3).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*dest_3).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*dest_3).owner_0)));}}
  else {
    if ((!((*dest_3).data_0 == NIM_NIL))){
      dealloc_1_sysvq0asl(((void*)(*dest_3).data_0));}}}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
