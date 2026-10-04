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
NB8 compositeCOk_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_3, NI32 depth_1);
static inline openArray_0_Iczu4791_aow7lb5cq1 toOpenArray_1_I0ef4be1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_29);
static inline NI32 len_3_In63jw61_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_31);
static inline WireField_0_run8hsnpi* getQ_7_Iko57h9_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_32, NI32 i_30);
static inline NI32 len_3_I5m68tr1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_33);
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_7_I45w7c91_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_34, NI32 i_31);
static inline HSlice_0_Inzqy8d_aow7lb5cq1 ___1_Iclcqmw1_aow7lb5cq1(NI32 a_15, NI32 b_2);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline seq_0_Irn2j6w_aow7lb5cq1 newSeqUninit_0_Ifa362m1_aow7lb5cq1(NI32 size_6);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
static inline void add_0_I1xop2a1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* s_39, X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 elem_10);
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_41);
static inline openArray_0_Inqs7yx_aow7lb5cq1 toOpenArray_0_Iccbrld_aow7lb5cq1(X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1* x_8);
static inline NB8 contains_3_Ipa7o28_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_20, NI32 elem_11);
static inline X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* getQ_7_Irlfbqs1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_44, NI32 i_35);
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45);
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_36);
static inline seq_0_Igzebks_aow7lb5cq1 newSeqUninit_0_I6ffb0e1_aow7lb5cq1(NI32 size_16);
static inline NI32 len_3_I44vue3_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_59);
static inline openArray_0_In0ukmu_aow7lb5cq1 toOpenArray_1_Ijdwnsz_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_60);
static inline void add_0_I9iil5u_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* s_62, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* elem_18);
static inline WireField_0_run8hsnpi* rawData_0_Ijd497p_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_64);
static inline NI32 len_6_Ier6z6r1_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 a_26);
static inline WireField_0_run8hsnpi* getQ_10_Id2924z_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 x_11, NI32 idx_5);
static inline NI32 memSizeInBytes_0_I5bna9k_aow7lb5cq1(NI32 size_18);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_27);
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
static inline NI32 capInBytes_0_Ikkv2nv1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_66);
NB8 resize_0_I90dq91_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* dest_7, NI32 addedElements_7);
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67);
static inline NI32 len_6_Igv2wyu1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 a_28);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_aow7lb5cq1(openArray_0_Ig73pnk_aow7lb5cq1 x_13, NI32 idx_7);
NI32 find_0_Iaugz2s1_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_29, NI32 elem_19);
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
static inline NI32 len_6_I9632ti1_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_30);
static inline NI32* getQ_10_I053icq_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 x_14, NI32 idx_8);
static inline NI32 memSizeInBytes_0_I21ctpp_aow7lb5cq1(NI32 size_23);
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** rawData_0_Izez9p81_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_72);
static inline NI32 len_6_Iu1dtri1_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 a_31);
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** getQ_10_I6a58n11_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 x_15, NI32 idx_9);
static inline NI32 capInBytes_0_Iekd9qh_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_73);
NB8 resize_0_Ifgwwnv_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* dest_11, NI32 addedElements_11);
void eQdestroy_1_Iem8q971_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_90);
static inline void eQwasMoved_1_I3l7wpx1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* s_91);
void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
void eQdestroy_1_Iytr7x_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_96);
static inline void eQwasMoved_1_Idjbhcw1_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* s_97);
static inline NI32 memSizeInBytes_0_Io786y61_aow7lb5cq1(NI32 size_29);
static inline NI32 memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(NI32 size_31);
void eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(CSig_0_aow7lb5cq1 dest_0);
void eQwasmovedQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(CSig_0_aow7lb5cq1* dest_0);
void eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0);
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* src_0);
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* src_0);
void eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_aow7lb5cq1(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 dest_0);
void eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
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
extern string_0_sysvq0asl quoteShell_0_oswd7dmm(string_0_sysvq0asl s_2);
extern NI32 execShellCmd_0_oswd7dmm(string_0_sysvq0asl command_0);
extern string_0_sysvq0asl shMkdirP_0_hos14g919(string_0_sysvq0asl d_0);
extern string_0_sysvq0asl shListInto_0_hos14g919(string_0_sysvq0asl pattern_0, string_0_sysvq0asl outFile_0);
extern NB8 open_0_syn1lfpjv(FILE** f_22, string_0_sysvq0asl filename_1, FileMode_0_syn1lfpjv mode_2, NI32 bufSize_0);
extern NB8 readLine_0_syn1lfpjv(FILE* f_26, string_0_sysvq0asl* s_3);
extern string_0_sysvq0asl shRmF_0_hos14g919(string_0_sysvq0asl f_0);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 readFile_0_syn1lfpjv(string_0_sysvq0asl filename_4);
extern ErrorCode_0_sysvq0asl writeFile_0_syn1lfpjv(string_0_sysvq0asl filename_5, string_0_sysvq0asl content_0);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern Program_0_prorcx25w1 prog_0_prorcx25w1;
extern string_0_sysvq0asl parentDir_0_ospaexnw61(string_0_sysvq0asl path_6);
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
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
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
LongString_0_sysvq0asl const strlit_0_I2513678243287852030_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_jit_rd"}
;
LongString_0_sysvq0asl const strlit_0_I10597374192599734484_aow7lb5cq1 = {
  .fullLen_0 = 771, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\012/* ---- aowli JIT shims (uniform flat-buffer ABI) --------------------------- */\012#include <stdlib.h>\012#include <string.h>\012/* Byte-loop reads/writes: args are tight-packed and may be unaligned. */\012static long long aowli_jit_rd(const unsigned char* p, int off, int n) {\012  unsigned long long v = 0; int i;\012  for (i = 0; i < n; i++) v |= ((unsigned long long)p[off + i]) << (8 * i);\012  /* sign-extend so a negative int32/int16/int8 arrives as a negative long long */\012  if (n < 8) {\012    unsigned long long sign = 1ULL << (8 * n - 1);\012    if (v & sign) v |= ~((1ULL << (8 * n)) - 1ULL);\012  }\012  return (long long)v;\012}\012static void aowli_jit_wr(unsigned char* p, int off, int n, long long v) {\012  int i; for (i = 0; i < n; i++) p[off + i] = (unsigned char)((v >> (8 * i)) & 0xff);\012}\012"}
;
LongString_0_sysvq0asl const strlit_0_I1797034738989881978_aow7lb5cq1 = {
  .fullLen_0 = 619, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\012/* ---- aowli JIT string marshaling ---------------------------------------- */\012/* The WHOLE 16-byte struct is the inline buffer: byte 0 is the length and bytes\012   1..15 are the data, so `more_0` holds CHARACTERS for an 8..15 byte string and\012   is not a discriminator. A length byte above 15 cannot be an inline length, so\012   that is the \"payload lives in more_0\" marker (the compiler emits 254).\012   Reading `more_0` as a pointer whenever it was non-zero is what segfaulted on\012   the first COMPUTED 8-byte string: \"<medium>\" stores \'>\' (0x3e) there. */\012#define AOWLI_JIT_INLINE_MAX 15\012\012static long long aowli_jit_slen("}
;
LongString_0_sysvq0asl const strlit_0_I1876279935150955625_aow7lb5cq1 = {
  .fullLen_0 = 204, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "* s) {\012  unsigned char tag = (unsigned char)(s->bytes_0 & 0xffull);\012  if (tag > AOWLI_JIT_INLINE_MAX) return (long long)s->more_0->fullLen_0;\012  return (long long)tag;\012}\012static const char* aowli_jit_sdata("}
;
LongString_0_sysvq0asl const strlit_0_I10786624760865126126_aow7lb5cq1 = {
  .fullLen_0 = 386, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "* s) {\012  unsigned char tag = (unsigned char)(s->bytes_0 & 0xffull);\012  if (tag > AOWLI_JIT_INLINE_MAX) return (const char*)s->more_0->data_0;\012  return ((const char*)s) + 1;          /* byte 0 is the length */\012}\012/* Build a string from raw bytes. <=15 bytes is pure inline: no allocation, so\012   no ownership question at all. Longer goes through the runtime\'s own\012   constructor. */\012static "}
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
LongString_0_sysvq0asl const strlit_0_I13870529507240259253_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  { long long n"}
;
LongString_0_sysvq0asl const strlit_0_I13615089990240707056_aow7lb5cq1 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = aowli_jit_rd(in_, (int)ipos_, 8);\012"}
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
LongString_0_sysvq0asl const strlit_0_I1258558027167527550_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = 0;\012"}
;
LongString_0_sysvq0asl const strlit_0_I17852924351155597464_aow7lb5cq1 = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      for (; i"}
;
LongString_0_sysvq0asl const strlit_0_I11739835173426611508_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " < n"}
;
LongString_0_sysvq0asl const strlit_0_I5544640060524604054_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "; ++i"}
;
LongString_0_sysvq0asl const strlit_0_I17846080716529448640_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") {\012"}
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
LongString_0_sysvq0asl const strlit_0_I15437739651001969444_aow7lb5cq1 = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "] = aowli_jit_smake(in_ + ipos_ + 8, m"}
;
LongString_0_sysvq0asl const strlit_0_I1161825924217342649_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", &o"}
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
LongString_0_sysvq0asl const strlit_0_I16570386306475740535_aow7lb5cq1 = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    _Static_assert(sizeof(*"}
;
LongString_0_sysvq0asl const strlit_0_I17215664847085503029_aow7lb5cq1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0) == "}
;
LongString_0_sysvq0asl const strlit_0_I11947772824232299275_aow7lb5cq1 = {
  .fullLen_0 = 48, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", \"seq element stride disagrees with aowlabi\");\012"}
;
LongString_0_sysvq0asl const strlit_0_I7944783884798134160_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " > 0) {\012"}
;
LongString_0_sysvq0asl const strlit_0_I2130325736493385980_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      "}
;
LongString_0_sysvq0asl const strlit_0_I12628527270567457706_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "      memcpy((void*)"}
;
LongString_0_sysvq0asl const strlit_0_I14428153832606577816_aow7lb5cq1 = {
  .fullLen_0 = 36, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".data_0, in_ + ipos_ + 8, (size_t)(n"}
;
LongString_0_sysvq0asl const strlit_0_I13453311567032255224_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    }\012"}
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
LongString_0_sysvq0asl const strlit_0_I18035457312318603665_aow7lb5cq1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    const char* p"}
;
LongString_0_sysvq0asl const strlit_0_I2252829356077611598_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " = aowli_jit_sdata(&"}
;
LongString_0_sysvq0asl const strlit_0_I592807425861797845_aow7lb5cq1 = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    aowli_jit_wr(ob_, (int)opos_, 8, n"}
;
LongString_0_sysvq0asl const strlit_0_I18148928282892619203_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "); opos_ += 8;\012"}
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
LongString_0_sysvq0asl const strlit_0_I6955924969188267900_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "]);\012"}
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
LongString_0_sysvq0asl const strlit_0_I5572117052193497108_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ", (size_t)m"}
;
LongString_0_sysvq0asl const strlit_0_I4896779559304927306_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "); opos_ += m"}
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
LongString_0_sysvq0asl const strlit_0_I17529382521941393548_aow7lb5cq1 = {
  .fullLen_0 = 31, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  opos_ += 8 + aowli_jit_slen(&"}
;
LongString_0_sysvq0asl const strlit_0_I15937128883579799196_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".len_0; opos_ += 8;\012"}
;
LongString_0_sysvq0asl const strlit_0_I8021182774357012906_aow7lb5cq1 = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "        opos_ += 8 + aowli_jit_slen(&"}
;
LongString_0_sysvq0asl const strlit_0_I15342668115246402447_aow7lb5cq1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    } }\012"}
;
LongString_0_sysvq0asl const strlit_0_I10813034127713670746_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  opos_ += 8 + "}
;
LongString_0_sysvq0asl const strlit_0_I17741661924343507191_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".len_0 * "}
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
LongString_0_sysvq0asl const strlit_0_I10518045726280400131_aow7lb5cq1 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "  _Static_assert(sizeof("}
;
LongString_0_sysvq0asl const strlit_0_I1775559386484707154_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ") == "}
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
LongString_0_sysvq0asl const strlit_0_I10331792544921969752_aow7lb5cq1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " r_ = "}
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
LongString_0_sysvq0asl const strlit_0_I15509854563229856298_aow7lb5cq1 = {
  .fullLen_0 = 65, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    if (outcap < need) return need;   /* aowli retries bigger */\012"}
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
LongString_0_sysvq0asl const strlit_0_I17847894267599352048_aow7lb5cq1 = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "    if (outcap < need) { if (r_.data_0) "}
;
LongString_0_sysvq0asl const strlit_0_I17765033553311774074_aow7lb5cq1 = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "((void*)r_.data_0); return need; }\012"}
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
LongString_0_sysvq0asl const strlit_0_I7830052811571726362_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gcc "}
;
LongString_0_sysvq0asl const strlit_0_I10506424120731942949_aow7lb5cq1 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "-shared -fPIC -O2 -w"}
;
LongString_0_sysvq0asl const strlit_0_I2123011150024992218_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " -o "}
;
LongString_0_sysvq0asl const strlit_0_I14743647238960953227_aow7lb5cq1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " -lm"}
;
LongString_0_sysvq0asl const strlit_0_I278182693605788883_aow7lb5cq1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " 2>&1"}
;
LongString_0_sysvq0asl const strlit_0_I11438303454518475359_aow7lb5cq1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_jit.c"}
;
LongString_0_sysvq0asl const strlit_0_I1947988348543698404_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "build.log"}
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
LongString_0_sysvq0asl const strlit_0_I17605077022815850042_aow7lb5cq1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "string_0_"}
;
LongString_0_sysvq0asl const strlit_0_I15230512448378417494_aow7lb5cq1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "LongString_0_"}
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
LongString_0_sysvq0asl const strlit_0_I7503365064679144772_aow7lb5cq1 = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "libaowli_jit.so"}
;
LongString_0_sysvq0asl const strlit_0_I5560383726051623062_aow7lb5cq1 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit: route=in-process ("}
;
LongString_0_sysvq0asl const strlit_0_I13807919816995135645_aow7lb5cq1 = {
  .fullLen_0 = 49, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " units, no subprocess, no external aowlc needed)\012"}
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
NB8 X60QiniGuard_0_aow7lb5cq1;
AbiKind_0_layptix6a1 leafKind_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_0){
  AbiKind_0_layptix6a1 result_0;
  if (td_0 == NIM_NIL){
    return 5;}
  NB8 X60Qx_37;
  if ((*td_0).d_00.kind_0 == 13){
    X60Qx_37 = (!((*td_0).d_00.elem_0 == NIM_NIL));}
  else {
    X60Qx_37 = NIM_FALSE;}
  if (X60Qx_37){
    AbiKind_0_layptix6a1 X60Qx_38 = leafKind_0_aow7lb5cq1((*td_0).d_00.elem_0);
    result_0 = X60Qx_38;
    return result_0;}
  result_0 = (*td_0).d_00.kind_0;
  return result_0;}
NB8 plainField_0_aow7lb5cq1(WireField_0_run8hsnpi* f_0){
  NB8 result_1;
  NB8 X60Qx_39;
  NB8 X60Qx_40;
  NB8 X60Qx_41;
  NB8 X60Qx_42;
  NB8 X60Qx_43;
  NB8 X60Qx_44;
  NB8 X60Qx_45;
  NB8 X60Qx_46;
  NB8 X60Qx_47;
  if ((*f_0).isEnum_0){
    X60Qx_47 = NIM_TRUE;}
  else {
    X60Qx_47 = (*f_0).isRef_0;}
  if (X60Qx_47){
    X60Qx_46 = NIM_TRUE;}
  else {
    X60Qx_46 = (*f_0).isArenaRef_0;}
  if (X60Qx_46){
    X60Qx_45 = NIM_TRUE;}
  else {
    X60Qx_45 = (*f_0).isArenaPtr_0;}
  if (X60Qx_45){
    X60Qx_44 = NIM_TRUE;}
  else {
    X60Qx_44 = (*f_0).isPtrArena_0;}
  if (X60Qx_44){
    X60Qx_43 = NIM_TRUE;}
  else {
    X60Qx_43 = (*f_0).isForeignPtr_0;}
  if (X60Qx_43){
    X60Qx_42 = NIM_TRUE;}
  else {
    X60Qx_42 = (*f_0).isPod_0;}
  if (X60Qx_42){
    X60Qx_41 = NIM_TRUE;}
  else {
    X60Qx_41 = (*f_0).isString_0;}
  if (X60Qx_41){
    X60Qx_40 = NIM_TRUE;}
  else {
    X60Qx_40 = (*f_0).isSeq_0;}
  if (X60Qx_40){
    X60Qx_39 = NIM_TRUE;}
  else {
    X60Qx_39 = (*f_0).isArray_0;}
  result_1 = (!X60Qx_39);
  return result_1;}
NB8 widthOk_0_aow7lb5cq1(NI32 n_0){
  NB8 result_2;
  NB8 X60Qx_48;
  NB8 X60Qx_49;
  NB8 X60Qx_50;
  if (n_0 == 1){
    X60Qx_50 = NIM_TRUE;}
  else {
    X60Qx_50 = (n_0 == 2);}
  if (X60Qx_50){
    X60Qx_49 = NIM_TRUE;}
  else {
    X60Qx_49 = (n_0 == 4);}
  if (X60Qx_49){
    X60Qx_48 = NIM_TRUE;}
  else {
    X60Qx_48 = (n_0 == 8);}
  result_2 = X60Qx_48;
  return result_2;}
NB8 scalarOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_1){
  NB8 result_3;
  NB8 X60Qx_51;
  NB8 X60Qx_52;
  NB8 X60Qx_53 = plainField_0_aow7lb5cq1((&(*f_1)));
  if ((!X60Qx_53)){
    X60Qx_52 = NIM_TRUE;}
  else {
    X60Qx_52 = (*f_1).isVar_0;}
  if (X60Qx_52){
    X60Qx_51 = NIM_TRUE;}
  else {
    X60Qx_51 = ((*f_1).desc_0 == NIM_NIL);}
  if (X60Qx_51){
    return NIM_FALSE;}
  AbiKind_0_layptix6a1 X60Qx_54 = leafKind_0_aow7lb5cq1((*f_1).desc_0);
  switch (X60Qx_54){
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
  NB8 X60Qx_55 = widthOk_0_aow7lb5cq1((*f_1).wireSize_0);
  result_3 = X60Qx_55;
  return result_3;}
NB8 floatOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_2){
  NB8 result_4;
  NB8 X60Qx_56;
  NB8 X60Qx_57;
  NB8 X60Qx_58 = plainField_0_aow7lb5cq1((&(*f_2)));
  if ((!X60Qx_58)){
    X60Qx_57 = NIM_TRUE;}
  else {
    X60Qx_57 = (*f_2).isVar_0;}
  if (X60Qx_57){
    X60Qx_56 = NIM_TRUE;}
  else {
    X60Qx_56 = ((*f_2).desc_0 == NIM_NIL);}
  if (X60Qx_56){
    return NIM_FALSE;}
  NB8 X60Qx_59;
  AbiKind_0_layptix6a1 X60Qx_60 = leafKind_0_aow7lb5cq1((*f_2).desc_0);
  if (X60Qx_60 == 2){
    NB8 X60Qx_61;
    if ((*f_2).wireSize_0 == 4){
      X60Qx_61 = NIM_TRUE;}
    else {
      X60Qx_61 = ((*f_2).wireSize_0 == 8);}
    X60Qx_59 = X60Qx_61;}
  else {
    X60Qx_59 = NIM_FALSE;}
  result_4 = X60Qx_59;
  return result_4;}
NB8 enumOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_3){
  NB8 result_5;
  NB8 X60Qx_62;
  if ((*f_3).isEnum_0){
    X60Qx_62 = (!(*f_3).isVar_0);}
  else {
    X60Qx_62 = NIM_FALSE;}
  result_5 = X60Qx_62;
  return result_5;}
NB8 podOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_4){
  NB8 result_6;
  NB8 X60Qx_63;
  NB8 X60Qx_64;
  NB8 X60Qx_65;
  NB8 X60Qx_66;
  if ((*f_4).isArenaPtr_0){
    X60Qx_66 = NIM_TRUE;}
  else {
    X60Qx_66 = (*f_4).isPtrArena_0;}
  if (X60Qx_66){
    X60Qx_65 = NIM_TRUE;}
  else {
    X60Qx_65 = (*f_4).isRef_0;}
  if (X60Qx_65){
    X60Qx_64 = NIM_TRUE;}
  else {
    X60Qx_64 = (*f_4).isArenaRef_0;}
  if (X60Qx_64){
    X60Qx_63 = NIM_TRUE;}
  else {
    X60Qx_63 = (*f_4).isVar_0;}
  if (X60Qx_63){
    return NIM_FALSE;}
  NB8 X60Qx_67;
  NB8 X60Qx_68;
  if ((*f_4).isPod_0){
    X60Qx_68 = NIM_TRUE;}
  else {
    X60Qx_68 = (*f_4).isArray_0;}
  if (X60Qx_68){
    X60Qx_67 = (0 < (*f_4).wireSize_0);}
  else {
    X60Qx_67 = NIM_FALSE;}
  result_6 = X60Qx_67;
  return result_6;}
NB8 seqOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_5){
  NB8 result_7;
  NB8 X60Qx_69;
  NB8 X60Qx_70;
  NB8 X60Qx_71;
  if ((*f_5).isVar_0){
    X60Qx_71 = NIM_TRUE;}
  else {
    X60Qx_71 = (*f_5).isRef_0;}
  if (X60Qx_71){
    X60Qx_70 = NIM_TRUE;}
  else {
    X60Qx_70 = (*f_5).isArenaRef_0;}
  if (X60Qx_70){
    X60Qx_69 = NIM_TRUE;}
  else {
    X60Qx_69 = (*f_5).isSink_0;}
  if (X60Qx_69){
    return NIM_FALSE;}
  NB8 X60Qx_72;
  NB8 X60Qx_73;
  if ((*f_5).isSeq_0){
    X60Qx_73 = (!(*f_5).elemVarLen_0);}
  else {
    X60Qx_73 = NIM_FALSE;}
  if (X60Qx_73){
    X60Qx_72 = (0 < (*f_5).elemStride_0);}
  else {
    X60Qx_72 = NIM_FALSE;}
  result_7 = X60Qx_72;
  return result_7;}
NB8 stringOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_6){
  NB8 result_8;
  NB8 X60Qx_74;
  NB8 X60Qx_75;
  NB8 X60Qx_76;
  if ((*f_6).isString_0){
    X60Qx_76 = (!(*f_6).isVar_0);}
  else {
    X60Qx_76 = NIM_FALSE;}
  if (X60Qx_76){
    X60Qx_75 = (!(*f_6).isRef_0);}
  else {
    X60Qx_75 = NIM_FALSE;}
  if (X60Qx_75){
    X60Qx_74 = (!(*f_6).isArenaRef_0);}
  else {
    X60Qx_74 = NIM_FALSE;}
  result_8 = X60Qx_74;
  return result_8;}
NB8 varOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_7){
  NB8 result_9;
  NB8 X60Qx_77;
  NB8 X60Qx_78;
  NB8 X60Qx_79;
  NB8 X60Qx_80;
  if ((!(*f_7).isVar_0)){
    X60Qx_80 = NIM_TRUE;}
  else {
    X60Qx_80 = (*f_7).isRef_0;}
  if (X60Qx_80){
    X60Qx_79 = NIM_TRUE;}
  else {
    X60Qx_79 = (*f_7).isArenaRef_0;}
  if (X60Qx_79){
    X60Qx_78 = NIM_TRUE;}
  else {
    X60Qx_78 = (*f_7).isArenaPtr_0;}
  if (X60Qx_78){
    X60Qx_77 = NIM_TRUE;}
  else {
    X60Qx_77 = (*f_7).isPtrArena_0;}
  if (X60Qx_77){
    return NIM_FALSE;}
  if ((*f_7).wireSize_0 <= 0){
    return NIM_FALSE;}
  NB8 X60Qx_81;
  if ((*f_7).isPod_0){
    X60Qx_81 = NIM_TRUE;}
  else {
    X60Qx_81 = (*f_7).isArray_0;}
  if (X60Qx_81){
    return NIM_TRUE;}
  NB8 X60Qx_82 = plainField_0_aow7lb5cq1((&(*f_7)));
  if ((!X60Qx_82)){
    return NIM_FALSE;}
  AbiKind_0_layptix6a1 X60Qx_83 = leafKind_0_aow7lb5cq1((*f_7).desc_0);
  switch (X60Qx_83){
    case 0:
    case 1:
    case 4:
    case 3:
    {
      NB8 X60Qx_84 = widthOk_0_aow7lb5cq1((*f_7).wireSize_0);
      result_9 = X60Qx_84;}
    break;
    case 2:
    {
      NB8 X60Qx_85;
      if ((*f_7).wireSize_0 == 4){
        X60Qx_85 = NIM_TRUE;}
      else {
        X60Qx_85 = ((*f_7).wireSize_0 == 8);}
      result_9 = X60Qx_85;}
    break;
    default:
    {
      result_9 = NIM_FALSE;}
    break;}
  return result_9;}
NB8 compositeOkHere_0_aow7lb5cq1(WireField_0_run8hsnpi* f_8){
  NB8 result_10;
  NB8 X60Qx_86;
  if ((!((*f_8).desc_0 == NIM_NIL))){
    NB8 X60Qx_87 = compositeCOk_0_aow7lb5cq1((*f_8).desc_0, 0);
    X60Qx_86 = X60Qx_87;}
  else {
    X60Qx_86 = NIM_FALSE;}
  result_10 = X60Qx_86;
  return result_10;}
NB8 argOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_9){
  NB8 result_11;
  if ((*f_9).isComposite_0){
    NB8 X60Qx_88 = compositeOkHere_0_aow7lb5cq1((&(*f_9)));
    result_11 = X60Qx_88;
    return result_11;}
  NB8 X60Qx_89;
  NB8 X60Qx_90;
  NB8 X60Qx_91;
  NB8 X60Qx_92;
  NB8 X60Qx_93;
  NB8 X60Qx_94;
  NB8 X60Qx_95 = scalarOk_0_aow7lb5cq1((&(*f_9)));
  if (X60Qx_95){
    X60Qx_94 = NIM_TRUE;}
  else {
    NB8 X60Qx_96 = floatOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_94 = X60Qx_96;}
  if (X60Qx_94){
    X60Qx_93 = NIM_TRUE;}
  else {
    NB8 X60Qx_97 = enumOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_93 = X60Qx_97;}
  if (X60Qx_93){
    X60Qx_92 = NIM_TRUE;}
  else {
    NB8 X60Qx_98 = stringOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_92 = X60Qx_98;}
  if (X60Qx_92){
    X60Qx_91 = NIM_TRUE;}
  else {
    NB8 X60Qx_99 = podOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_91 = X60Qx_99;}
  if (X60Qx_91){
    X60Qx_90 = NIM_TRUE;}
  else {
    NB8 X60Qx_100 = seqOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_90 = X60Qx_100;}
  if (X60Qx_90){
    X60Qx_89 = NIM_TRUE;}
  else {
    NB8 X60Qx_101 = varOk_0_aow7lb5cq1((&(*f_9)));
    X60Qx_89 = X60Qx_101;}
  result_11 = X60Qx_89;
  return result_11;}
NB8 retOk_0_aow7lb5cq1(WireField_0_run8hsnpi* f_10){
  NB8 result_12;
  if ((*f_10).isComposite_0){
    NB8 X60Qx_102 = compositeOkHere_0_aow7lb5cq1((&(*f_10)));
    result_12 = X60Qx_102;
    return result_12;}
  NB8 X60Qx_103;
  NB8 X60Qx_104;
  NB8 X60Qx_105;
  NB8 X60Qx_106;
  NB8 X60Qx_107;
  NB8 X60Qx_108 = scalarOk_0_aow7lb5cq1((&(*f_10)));
  if (X60Qx_108){
    X60Qx_107 = NIM_TRUE;}
  else {
    NB8 X60Qx_109 = floatOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_107 = X60Qx_109;}
  if (X60Qx_107){
    X60Qx_106 = NIM_TRUE;}
  else {
    NB8 X60Qx_110 = enumOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_106 = X60Qx_110;}
  if (X60Qx_106){
    X60Qx_105 = NIM_TRUE;}
  else {
    NB8 X60Qx_111 = stringOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_105 = X60Qx_111;}
  if (X60Qx_105){
    X60Qx_104 = NIM_TRUE;}
  else {
    NB8 X60Qx_112 = podOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_104 = X60Qx_112;}
  if (X60Qx_104){
    X60Qx_103 = NIM_TRUE;}
  else {
    NB8 X60Qx_113 = seqOk_0_aow7lb5cq1((&(*f_10)));
    X60Qx_103 = X60Qx_113;}
  result_12 = X60Qx_103;
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
    NB8 X60Qx_114;
    if ((*f_11).isSeq_0){
      X60Qx_114 = (*f_11).elemVarLen_0;}
    else {
      X60Qx_114 = NIM_FALSE;}
    if (X60Qx_114){
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
                        AbiKind_0_layptix6a1 X60Qx_115 = leafKind_0_aow7lb5cq1((*f_11).desc_0);
                        switch (X60Qx_115){
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
  NB8 X60Qx_116 = argOk_0_aow7lb5cq1((&(*f_12)));
  if (X60Qx_116){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl s_2 = describeShape_0_aow7lb5cq1((&(*f_12)));
  if ((*f_12).isVar_0){
    string_0_sysvq0asl X60Qlhs_0 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I8367327255669636523_aow7lb5cq1)}
    , s_2);
    nimStrDestroy(s_2);
    s_2 = X60Qlhs_0;}
  if ((*f_12).isSink_0){
    NI32 X60Qx_117 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I6387641605083911873_aow7lb5cq1)}
    );
    NI32 X60Qx_118 = len_4_sysvq0asl(s_2);
    NI32 X60Qx_119 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I6242563128709086705_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_0 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_117 + X60Qx_118)) + X60Qx_119)));
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I6387641605083911873_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_0), s_2);
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I6242563128709086705_aow7lb5cq1)}
    );
    nimStrDestroy(s_2);
    s_2 = X60Qdesugar_0;
    nimStrWasMoved((&X60Qdesugar_0));
    nimStrDestroy(X60Qdesugar_0);}
  string_0_sysvq0asl X60Qdesugar_1 = dollarQ_2_sysvq0asl((*f_12).wireSize_0);
  NI32 X60Qx_120 = len_4_sysvq0asl(s_2);
  NI32 X60Qx_121 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1999118590u, .more_0 = (&strlit_0_I7560857284068051366_aow7lb5cq1)}
  );
  NI32 X60Qx_122 = len_4_sysvq0asl(X60Qdesugar_1);
  NI32 X60Qx_123 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_120 + X60Qx_121)) + X60Qx_122)) + X60Qx_123)));
  add_2_sysvq0asl((&X60Qdesugar_2), s_2);
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 1999118590u, .more_0 = (&strlit_0_I7560857284068051366_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_1);
  add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(result_14);
  result_14 = X60Qdesugar_2;
  nimStrWasMoved((&X60Qdesugar_2));
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(X60Qdesugar_1);
  nimStrDestroy(s_2);
  return result_14;
  nimStrDestroy(X60Qdesugar_2);
  nimStrDestroy(X60Qdesugar_1);
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
        NI32 X60Qx_124 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_124){
          {
            WireField_0_run8hsnpi* X60Qii_2 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_0, X60Qlf_1);
            NB8 X60Qx_125 = argOk_0_aow7lb5cq1((&(*X60Qii_2)));
            if ((!X60Qx_125)){
              return NIM_FALSE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  if ((!(*e_0).d_00.retVoid_0)){
    NB8 X60Qx_126 = retOk_0_aow7lb5cq1((&(*e_0).d_00.ret_0));
    if ((!X60Qx_126)){
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
      NI32 X60Qx_127 = len_3_In63jw61_aow7lb5cq1((*e_1).d_00.args_0);
      if (i_0 < X60Qx_127){
        WireField_0_run8hsnpi* X60Qx_128 = getQ_7_Iko57h9_aow7lb5cq1((*e_1).d_00.args_0, i_0);
        WireField_0_run8hsnpi X60QconstRefTemp_0 = (*X60Qx_128);
        string_0_sysvq0asl w_0 = whyNot_0_aow7lb5cq1((&X60QconstRefTemp_0));
        NI32 X60Qx_129 = len_4_sysvq0asl(w_0);
        if (0 < X60Qx_129){
          string_0_sysvq0asl X60Qdesugar_3 = dollarQ_2_sysvq0asl(i_0);
          NI32 X60Qx_130 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1735549187u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_131 = len_4_sysvq0asl(X60Qdesugar_3);
          NI32 X60Qx_132 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2112002u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_133 = len_4_sysvq0asl(w_0);
          string_0_sysvq0asl X60Qdesugar_4 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_130 + X60Qx_131)) + X60Qx_132)) + X60Qx_133)));
          add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
            .bytes_0 = 1735549187u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_4), X60Qdesugar_3);
          add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
            .bytes_0 = 2112002u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_4), w_0);
          string_0_sysvq0asl X60Qtmp_1 = X60Qdesugar_4;
          nimStrWasMoved((&X60Qdesugar_4));
          nimStrDestroy(X60Qdesugar_4);
          nimStrDestroy(X60Qdesugar_3);
          nimStrDestroy(w_0);
          return X60Qtmp_1;
          nimStrDestroy(X60Qdesugar_4);
          nimStrDestroy(X60Qdesugar_3);}
        inc_1_I6wjjge_aow2h993l1((&i_0));
        nimStrDestroy(w_0);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_134;
  if ((!(*e_1).d_00.retVoid_0)){
    NB8 X60Qx_135 = retOk_0_aow7lb5cq1((&(*e_1).d_00.ret_0));
    X60Qx_134 = (!X60Qx_135);}
  else {
    X60Qx_134 = NIM_FALSE;}
  if (X60Qx_134){
    string_0_sysvq0asl X60Qdesugar_5 = describeShape_0_aow7lb5cq1((&(*e_1).d_00.ret_0));
    string_0_sysvq0asl X60Qdesugar_6 = dollarQ_2_sysvq0asl((*e_1).d_00.ret_0.wireSize_0);
    NI32 X60Qx_136 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I15817754588380596987_aow7lb5cq1)}
    );
    NI32 X60Qx_137 = len_4_sysvq0asl(X60Qdesugar_5);
    NI32 X60Qx_138 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1999118590u, .more_0 = (&strlit_0_I7560857284068051366_aow7lb5cq1)}
    );
    NI32 X60Qx_139 = len_4_sysvq0asl(X60Qdesugar_6);
    NI32 X60Qx_140 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_7 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_136 + X60Qx_137)) + X60Qx_138)) + X60Qx_139)) + X60Qx_140)));
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 1952805630u, .more_0 = (&strlit_0_I15817754588380596987_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_5);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 1999118590u, .more_0 = (&strlit_0_I7560857284068051366_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_7), X60Qdesugar_6);
    add_2_sysvq0asl((&X60Qdesugar_7), (string_0_sysvq0asl){
      .bytes_0 = 10497u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qtmp_2 = X60Qdesugar_7;
    nimStrWasMoved((&X60Qdesugar_7));
    nimStrDestroy(X60Qdesugar_7);
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);
    return X60Qtmp_2;
    nimStrDestroy(X60Qdesugar_7);
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);}
  nimStrDestroy(result_17);
  result_17 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  return result_17;}
NB8 descHasKind_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_1, AbiKind_0_layptix6a1 want_0, NI32 depth_0){
  NB8 result_18;
  NB8 X60Qx_141;
  if (td_1 == NIM_NIL){
    X60Qx_141 = NIM_TRUE;}
  else {
    X60Qx_141 = (8 < depth_0);}
  if (X60Qx_141){
    return NIM_FALSE;}
  if ((*td_1).d_00.kind_0 == want_0){
    return NIM_TRUE;}
  NB8 X60Qx_142;
  if ((!((*td_1).d_00.elem_0 == NIM_NIL))){
    NB8 X60Qx_143 = descHasKind_0_aow7lb5cq1((*td_1).d_00.elem_0, want_0, ((NI32)(depth_0 + 1)));
    X60Qx_142 = X60Qx_143;}
  else {
    X60Qx_142 = NIM_FALSE;}
  if (X60Qx_142){
    return NIM_TRUE;}
  NI32 i_2 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_144 = len_3_I5m68tr1_aow7lb5cq1((*td_1).d_00.fields_0);
      if (i_2 < X60Qx_144){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_145 = getQ_7_I45w7c91_aow7lb5cq1((*td_1).d_00.fields_0, i_2);
        NB8 X60Qx_146 = descHasKind_0_aow7lb5cq1((*X60Qx_145), want_0, ((NI32)(depth_0 + 1)));
        if (X60Qx_146){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_18 = NIM_FALSE;
  return result_18;}
NB8 fieldHasKind_0_aow7lb5cq1(WireField_0_run8hsnpi* f_13, AbiKind_0_layptix6a1 want_1){
  NB8 result_19;
  NB8 X60Qx_147;
  NB8 X60Qx_148;
  if ((*f_13).isComposite_0){
    X60Qx_148 = (!((*f_13).desc_0 == NIM_NIL));}
  else {
    X60Qx_148 = NIM_FALSE;}
  if (X60Qx_148){
    NB8 X60Qx_149 = descHasKind_0_aow7lb5cq1((*f_13).desc_0, want_1, 0);
    X60Qx_147 = X60Qx_149;}
  else {
    X60Qx_147 = NIM_FALSE;}
  result_19 = X60Qx_147;
  return result_19;}
NB8 usesStrings_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_2){
  NB8 result_20;
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_2 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_2).d_00.args_0);
    NI32 X60Qlf_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_150 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_2);
        if (X60Qlf_3 < X60Qx_150){
          {
            WireField_0_run8hsnpi* X60Qii_2 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_2, X60Qlf_3);
            NB8 X60Qx_151;
            NB8 X60Qx_152 = stringOk_0_aow7lb5cq1((&(*X60Qii_2)));
            if (X60Qx_152){
              X60Qx_151 = NIM_TRUE;}
            else {
              NB8 X60Qx_153 = fieldHasKind_0_aow7lb5cq1((&(*X60Qii_2)), 14);
              X60Qx_151 = X60Qx_153;}
            if (X60Qx_151){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NB8 X60Qx_154;
  if ((!(*e_2).d_00.retVoid_0)){
    NB8 X60Qx_155;
    NB8 X60Qx_156 = stringOk_0_aow7lb5cq1((&(*e_2).d_00.ret_0));
    if (X60Qx_156){
      X60Qx_155 = NIM_TRUE;}
    else {
      NB8 X60Qx_157 = fieldHasKind_0_aow7lb5cq1((&(*e_2).d_00.ret_0), 14);
      X60Qx_155 = X60Qx_157;}
    X60Qx_154 = X60Qx_155;}
  else {
    X60Qx_154 = NIM_FALSE;}
  result_20 = X60Qx_154;
  return result_20;}
NB8 usesSeqs_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_3){
  NB8 result_21;
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_4 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_3).d_00.args_0);
    NI32 X60Qlf_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_158 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_4);
        if (X60Qlf_5 < X60Qx_158){
          {
            WireField_0_run8hsnpi* X60Qii_2 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_4, X60Qlf_5);
            NB8 X60Qx_159;
            NB8 X60Qx_160 = seqOk_0_aow7lb5cq1((&(*X60Qii_2)));
            if (X60Qx_160){
              X60Qx_159 = NIM_TRUE;}
            else {
              NB8 X60Qx_161 = fieldHasKind_0_aow7lb5cq1((&(*X60Qii_2)), 15);
              X60Qx_159 = X60Qx_161;}
            if (X60Qx_159){
              return NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NB8 X60Qx_162;
  if ((!(*e_3).d_00.retVoid_0)){
    NB8 X60Qx_163;
    NB8 X60Qx_164 = seqOk_0_aow7lb5cq1((&(*e_3).d_00.ret_0));
    if (X60Qx_164){
      X60Qx_163 = NIM_TRUE;}
    else {
      NB8 X60Qx_165 = fieldHasKind_0_aow7lb5cq1((&(*e_3).d_00.ret_0), 15);
      X60Qx_163 = X60Qx_165;}
    X60Qx_162 = X60Qx_163;}
  else {
    X60Qx_162 = NIM_FALSE;}
  result_21 = X60Qx_162;
  return result_21;}
NB8 hasSub_0_aow7lb5cq1(string_0_sysvq0asl hay_0, string_0_sysvq0asl needle_0){
  NB8 result_22;
  result_22 = NIM_FALSE;
  NB8 X60Qx_166;
  NI32 X60Qx_167 = len_4_sysvq0asl(needle_0);
  if (X60Qx_167 == 0){
    X60Qx_166 = NIM_TRUE;}
  else {
    NI32 X60Qx_168 = len_4_sysvq0asl(hay_0);
    NI32 X60Qx_169 = len_4_sysvq0asl(needle_0);
    X60Qx_166 = (X60Qx_168 < X60Qx_169);}
  if (X60Qx_166){
    return result_22;}
  NI32 i_4 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_170 = len_4_sysvq0asl(needle_0);
      NI32 X60Qx_171 = len_4_sysvq0asl(hay_0);
      if (((NI32)(i_4 + X60Qx_170)) <= X60Qx_171){
        NI32 X60Qx_172 = len_4_sysvq0asl(needle_0);
        HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_173 = ___1_Iclcqmw1_aow7lb5cq1(i_4, ((NI32)(((NI32)(i_4 + X60Qx_172)) - 1)));
        string_0_sysvq0asl X60Qtmp_3 = getQ_14_sysvq0asl(hay_0, X60Qx_173);
        NB8 X60Qx_174 = eqQ_20_sysvq0asl(X60Qtmp_3, needle_0);
        if (X60Qx_174){
          nimStrDestroy(X60Qtmp_3);
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_4));
        nimStrDestroy(X60Qtmp_3);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_22;}
NB8 isIdentChar_0_aow7lb5cq1(NC8 c_0){
  NB8 result_23;
  NB8 X60Qx_175;
  NB8 X60Qx_176;
  NB8 X60Qx_177;
  NB8 X60Qx_178;
  if ((NC8)'a' <= c_0){
    X60Qx_178 = (c_0 <= (NC8)'z');}
  else {
    X60Qx_178 = NIM_FALSE;}
  if (X60Qx_178){
    X60Qx_177 = NIM_TRUE;}
  else {
    NB8 X60Qx_179;
    if ((NC8)'A' <= c_0){
      X60Qx_179 = (c_0 <= (NC8)'Z');}
    else {
      X60Qx_179 = NIM_FALSE;}
    X60Qx_177 = X60Qx_179;}
  if (X60Qx_177){
    X60Qx_176 = NIM_TRUE;}
  else {
    NB8 X60Qx_180;
    if ((NC8)'0' <= c_0){
      X60Qx_180 = (c_0 <= (NC8)'9');}
    else {
      X60Qx_180 = NIM_FALSE;}
    X60Qx_176 = X60Qx_180;}
  if (X60Qx_176){
    X60Qx_175 = NIM_TRUE;}
  else {
    X60Qx_175 = (c_0 == (NC8)'_');}
  result_23 = X60Qx_175;
  return result_23;}
NB8 lineStartsAtColumn0_0_aow7lb5cq1(string_0_sysvq0asl src_0, NI32 pos_0){
  NB8 result_24;
  NI32 i_5 = pos_0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_181;
      if (0 < i_5){
        NC8 X60Qx_182 = getQ_9_sysvq0asl(src_0, ((NI32)(i_5 - 1)));
        X60Qx_181 = (!(X60Qx_182 == (NC8)'\012'));}
      else {
        X60Qx_181 = NIM_FALSE;}
      if (X60Qx_181){
        dec_1_I0nzoz91_aow7lb5cq1((&i_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_183 = len_4_sysvq0asl(src_0);
  if (X60Qx_183 <= i_5){
    return NIM_FALSE;}
  NB8 X60Qx_184;
  NB8 X60Qx_185;
  NB8 X60Qx_186;
  NC8 X60Qx_187 = getQ_9_sysvq0asl(src_0, i_5);
  if ((!(X60Qx_187 == (NC8)' '))){
    NC8 X60Qx_188 = getQ_9_sysvq0asl(src_0, i_5);
    X60Qx_186 = (!(X60Qx_188 == (NC8)'\011'));}
  else {
    X60Qx_186 = NIM_FALSE;}
  if (X60Qx_186){
    NC8 X60Qx_189 = getQ_9_sysvq0asl(src_0, i_5);
    X60Qx_185 = (!(X60Qx_189 == (NC8)'/'));}
  else {
    X60Qx_185 = NIM_FALSE;}
  if (X60Qx_185){
    NC8 X60Qx_190 = getQ_9_sysvq0asl(src_0, i_5);
    X60Qx_184 = (!(X60Qx_190 == (NC8)'#'));}
  else {
    X60Qx_184 = NIM_FALSE;}
  result_24 = X60Qx_184;
  return result_24;}
string_0_sysvq0asl mangledName_0_aow7lb5cq1(string_0_sysvq0asl src_1, string_0_sysvq0asl base_0){
  string_0_sysvq0asl result_25;
  nimStrWasMoved((&result_25));
  nimStrDestroy(result_25);
  result_25 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 n_1 = len_4_sysvq0asl(base_0);
  NB8 X60Qx_191;
  if (n_1 == 0){
    X60Qx_191 = NIM_TRUE;}
  else {
    NI32 X60Qx_192 = len_4_sysvq0asl(src_1);
    X60Qx_191 = (X60Qx_192 == 0);}
  if (X60Qx_191){
    return result_25;}
  NI32 i_6 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_193 = len_4_sysvq0asl(src_1);
      if (((NI32)(i_6 + n_1)) < X60Qx_193){
        NB8 X60Qx_19;
        NB8 X60Qx_194;
        NC8 X60Qx_195 = getQ_9_sysvq0asl(src_1, i_6);
        NC8 X60Qx_196 = getQ_9_sysvq0asl(base_0, 0);
        if (X60Qx_195 == X60Qx_196){
          NB8 X60Qx_197;
          if (i_6 == 0){
            X60Qx_197 = NIM_TRUE;}
          else {
            NC8 X60Qx_198 = getQ_9_sysvq0asl(src_1, ((NI32)(i_6 - 1)));
            NB8 X60Qx_199 = isIdentChar_0_aow7lb5cq1(X60Qx_198);
            X60Qx_197 = (!X60Qx_199);}
          X60Qx_194 = X60Qx_197;}
        else {
          X60Qx_194 = NIM_FALSE;}
        if (X60Qx_194){
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_200 = ___1_Iclcqmw1_aow7lb5cq1(i_6, ((NI32)(((NI32)(i_6 + n_1)) - 1)));
          string_0_sysvq0asl X60Qtmp_4 = getQ_14_sysvq0asl(src_1, X60Qx_200);
          NB8 X60Qx_201 = eqQ_20_sysvq0asl(X60Qtmp_4, base_0);
          X60Qx_19 = X60Qx_201;
          nimStrDestroy(X60Qtmp_4);}
        else {
          X60Qx_19 = NIM_FALSE;}
        if (X60Qx_19){
          NI32 j_0 = ((NI32)(i_6 + n_1));
          NB8 X60Qx_202;
          NI32 X60Qx_203 = len_4_sysvq0asl(src_1);
          if (j_0 < X60Qx_203){
            NC8 X60Qx_204 = getQ_9_sysvq0asl(src_1, j_0);
            X60Qx_202 = (X60Qx_204 == (NC8)'_');}
          else {
            X60Qx_202 = NIM_FALSE;}
          if (X60Qx_202){
            inc_1_I6wjjge_aow2h993l1((&j_0));
            NI32 digits_0 = 0;
            {
              while (NIM_TRUE){
                NB8 X60Qx_205;
                NB8 X60Qx_206;
                NI32 X60Qx_207 = len_4_sysvq0asl(src_1);
                if (j_0 < X60Qx_207){
                  NC8 X60Qx_208 = getQ_9_sysvq0asl(src_1, j_0);
                  X60Qx_206 = ((NC8)'0' <= X60Qx_208);}
                else {
                  X60Qx_206 = NIM_FALSE;}
                if (X60Qx_206){
                  NC8 X60Qx_209 = getQ_9_sysvq0asl(src_1, j_0);
                  X60Qx_205 = (X60Qx_209 <= (NC8)'9');}
                else {
                  X60Qx_205 = NIM_FALSE;}
                if (X60Qx_205){
                  inc_1_I6wjjge_aow2h993l1((&j_0));
                  inc_1_I6wjjge_aow2h993l1((&digits_0));}
                else {
                  break;}}}
            whileStmtLabel_1: ;
            NB8 X60Qx_210;
            NB8 X60Qx_211;
            if (0 < digits_0){
              NI32 X60Qx_212 = len_4_sysvq0asl(src_1);
              X60Qx_211 = (j_0 < X60Qx_212);}
            else {
              X60Qx_211 = NIM_FALSE;}
            if (X60Qx_211){
              NC8 X60Qx_213 = getQ_9_sysvq0asl(src_1, j_0);
              X60Qx_210 = (X60Qx_213 == (NC8)'_');}
            else {
              X60Qx_210 = NIM_FALSE;}
            if (X60Qx_210){
              inc_1_I6wjjge_aow2h993l1((&j_0));
              {
                while (NIM_TRUE){
                  NB8 X60Qx_214;
                  NI32 X60Qx_215 = len_4_sysvq0asl(src_1);
                  if (j_0 < X60Qx_215){
                    NC8 X60Qx_216 = getQ_9_sysvq0asl(src_1, j_0);
                    NB8 X60Qx_217 = isIdentChar_0_aow7lb5cq1(X60Qx_216);
                    X60Qx_214 = X60Qx_217;}
                  else {
                    X60Qx_214 = NIM_FALSE;}
                  if (X60Qx_214){
                    inc_1_I6wjjge_aow2h993l1((&j_0));}
                  else {
                    break;}}}
              whileStmtLabel_2: ;
              NB8 X60Qx_218;
              NB8 X60Qx_219;
              NI32 X60Qx_220 = len_4_sysvq0asl(src_1);
              if (j_0 < X60Qx_220){
                NC8 X60Qx_221 = getQ_9_sysvq0asl(src_1, j_0);
                X60Qx_219 = (X60Qx_221 == (NC8)'(');}
              else {
                X60Qx_219 = NIM_FALSE;}
              if (X60Qx_219){
                NB8 X60Qx_222 = lineStartsAtColumn0_0_aow7lb5cq1(src_1, i_6);
                X60Qx_218 = X60Qx_222;}
              else {
                X60Qx_218 = NIM_FALSE;}
              if (X60Qx_218){
                HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_223 = ___1_Iclcqmw1_aow7lb5cq1(i_6, ((NI32)(j_0 - 1)));
                string_0_sysvq0asl X60Qx_224 = getQ_14_sysvq0asl(src_1, X60Qx_223);
                result_25 = X60Qx_224;
                return result_25;}}}}
        inc_1_I6wjjge_aow2h993l1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_25;}
seq_0_Irn2j6w_aow7lb5cq1 structFields_0_aow7lb5cq1(string_0_sysvq0asl src_2, string_0_sysvq0asl typeName_0){
  seq_0_Irn2j6w_aow7lb5cq1 result_26;
  eQwasMoved_1_I3l7wpx1_aow7lb5cq1((&result_26));
  eQdestroy_1_Iem8q971_aow7lb5cq1(result_26);
  seq_0_Irn2j6w_aow7lb5cq1 X60Qx_225 = newSeqUninit_0_Ifa362m1_aow7lb5cq1(0);
  result_26 = X60Qx_225;
  NI32 X60Qx_226 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
  );
  NI32 X60Qx_227 = len_4_sysvq0asl(typeName_0);
  NI32 X60Qx_228 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 31489u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl X60Qdesugar_8 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_226 + X60Qx_227)) + X60Qx_228)));
  add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I3789116743795128948_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_8), typeName_0);
  add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
    .bytes_0 = 31489u, .more_0 = NIM_NIL}
  );
  string_0_sysvq0asl open_0 = X60Qdesugar_8;
  nimStrWasMoved((&X60Qdesugar_8));
  NI32 i_7 = 0;
  NI32 at_0 = -1;
  {
    while (NIM_TRUE){
      NI32 X60Qx_229 = len_4_sysvq0asl(open_0);
      NI32 X60Qx_230 = len_4_sysvq0asl(src_2);
      if (((NI32)(i_7 + X60Qx_229)) <= X60Qx_230){
        NB8 X60Qx_20;
        NC8 X60Qx_231 = getQ_9_sysvq0asl(src_2, i_7);
        if (X60Qx_231 == (NC8)'t'){
          NI32 X60Qx_232 = len_4_sysvq0asl(open_0);
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_233 = ___1_Iclcqmw1_aow7lb5cq1(i_7, ((NI32)(((NI32)(i_7 + X60Qx_232)) - 1)));
          string_0_sysvq0asl X60Qtmp_5 = getQ_14_sysvq0asl(src_2, X60Qx_233);
          NB8 X60Qx_234 = eqQ_20_sysvq0asl(X60Qtmp_5, open_0);
          X60Qx_20 = X60Qx_234;
          nimStrDestroy(X60Qtmp_5);}
        else {
          X60Qx_20 = NIM_FALSE;}
        if (X60Qx_20){
          NI32 X60Qx_235 = len_4_sysvq0asl(open_0);
          at_0 = ((NI32)(i_7 + X60Qx_235));
          goto whileStmtLabel_0;}
        inc_1_I6wjjge_aow2h993l1((&i_7));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (at_0 < 0){
    seq_0_Irn2j6w_aow7lb5cq1 X60Qx_236 = newSeqUninit_0_Ifa362m1_aow7lb5cq1(0);
    result_26 = X60Qx_236;
    nimStrDestroy(open_0);
    nimStrDestroy(X60Qdesugar_8);
    return result_26;}
  string_0_sysvq0asl cur_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 j_1 = at_0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_237 = len_4_sysvq0asl(src_2);
      if (j_1 < X60Qx_237){
        NC8 c_1 = getQ_9_sysvq0asl(src_2, j_1);
        if (c_1 == (NC8)'}'){
          goto whileStmtLabel_1;}
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
                NI32 X60Qx_238 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_6);
                if (X60Qlf_7 < X60Qx_238){
                  {
                    NC8* X60Qii_4 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_6, X60Qlf_7);
                    NB8 X60Qx_239;
                    NB8 X60Qx_240;
                    NB8 X60Qx_241;
                    if ((*X60Qii_4) == (NC8)' '){
                      X60Qx_241 = NIM_TRUE;}
                    else {
                      X60Qx_241 = ((*X60Qii_4) == ((NC8)10));}
                    if (X60Qx_241){
                      X60Qx_240 = NIM_TRUE;}
                    else {
                      X60Qx_240 = ((*X60Qii_4) == ((NC8)9));}
                    if (X60Qx_240){
                      X60Qx_239 = NIM_TRUE;}
                    else {
                      X60Qx_239 = ((*X60Qii_4) == ((NC8)13));}
                    if (X60Qx_239){
                      NI32 X60Qx_242 = len_4_sysvq0asl(t_1);
                      if (0 < X60Qx_242){
                        string_0_sysvq0asl X60Qtmp_6 = t_1;
                        nimStrWasMoved((&t_1));
                        add_0_Ig6072n_aow7lb5cq1((&toks_0), X60Qtmp_6);}
                      nimStrDestroy(t_1);
                      t_1 = (string_0_sysvq0asl){
                        .bytes_0 = 0u, .more_0 = NIM_NIL}
                      ;}
                    else {
                      add_1_sysvq0asl((&t_1), (*X60Qii_4));}}
                  inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
                else {
                  break;}}}
            whileStmtLabel_3: ;}
          forStmtLabel_2: ;
          NI32 X60Qx_243 = len_4_sysvq0asl(t_1);
          if (0 < X60Qx_243){
            string_0_sysvq0asl X60Qtmp_7 = t_1;
            nimStrWasMoved((&t_1));
            add_0_Ig6072n_aow7lb5cq1((&toks_0), X60Qtmp_7);}
          if (2 <= toks_0.len_0){
            string_0_sysvq0asl ty_0 = (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            ;
            NI32 k_0 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_244 = len_3_Ixq6taz_aow7lb5cq1(toks_0);
                if (k_0 < ((NI32)(X60Qx_244 - 1))){
                  NI32 X60Qx_245 = len_4_sysvq0asl(ty_0);
                  if (0 < X60Qx_245){
                    add_1_sysvq0asl((&ty_0), (NC8)' ');}
                  string_0_sysvq0asl* X60Qx_246 = getQ_7_Ir6d0tw_aow7lb5cq1(toks_0, k_0);
                  add_2_sysvq0asl((&ty_0), (*X60Qx_246));
                  inc_1_I6wjjge_aow2h993l1((&k_0));}
                else {
                  break;}}}
            whileStmtLabel_5: ;
            string_0_sysvq0asl X60Qtmp_8 = ty_0;
            nimStrWasMoved((&ty_0));
            NI32 X60Qx_247 = len_3_Ixq6taz_aow7lb5cq1(toks_0);
            string_0_sysvq0asl* X60Qx_248 = getQ_7_Ir6d0tw_aow7lb5cq1(toks_0, ((NI32)(X60Qx_247 - 1)));
            string_0_sysvq0asl X60Qx_21 = nimStrDup((*X60Qx_248));
            add_0_I1xop2a1_aow7lb5cq1((&result_26), (X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1){
              .fld_0 = X60Qtmp_8, .fld_1 = X60Qx_21}
            );
            nimStrDestroy(ty_0);}
          nimStrDestroy(cur_0);
          cur_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          nimStrDestroy(t_1);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(toks_0);}
        else {
          add_1_sysvq0asl((&cur_0), c_1);}
        inc_1_I6wjjge_aow2h993l1((&j_1));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  nimStrDestroy(cur_0);
  nimStrDestroy(open_0);
  nimStrDestroy(X60Qdesugar_8);
  return result_26;
  nimStrDestroy(cur_0);
  nimStrDestroy(open_0);
  nimStrDestroy(X60Qdesugar_8);
  return result_26;}
NB8 definesExactly_0_aow7lb5cq1(string_0_sysvq0asl src_3, string_0_sysvq0asl name_0){
  NB8 result_27;
  result_27 = NIM_FALSE;
  NI32 n_2 = len_4_sysvq0asl(name_0);
  NB8 X60Qx_249;
  if (n_2 == 0){
    X60Qx_249 = NIM_TRUE;}
  else {
    NI32 X60Qx_250 = len_4_sysvq0asl(src_3);
    X60Qx_249 = (X60Qx_250 == 0);}
  if (X60Qx_249){
    return result_27;}
  NI32 i_9 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_251 = len_4_sysvq0asl(src_3);
      if (((NI32)(i_9 + n_2)) < X60Qx_251){
        NB8 X60Qx_22;
        NB8 X60Qx_23;
        NB8 X60Qx_24;
        NB8 X60Qx_252;
        NC8 X60Qx_253 = getQ_9_sysvq0asl(src_3, i_9);
        NC8 X60Qx_254 = getQ_9_sysvq0asl(name_0, 0);
        if (X60Qx_253 == X60Qx_254){
          NB8 X60Qx_255;
          if (i_9 == 0){
            X60Qx_255 = NIM_TRUE;}
          else {
            NC8 X60Qx_256 = getQ_9_sysvq0asl(src_3, ((NI32)(i_9 - 1)));
            NB8 X60Qx_257 = isIdentChar_0_aow7lb5cq1(X60Qx_256);
            X60Qx_255 = (!X60Qx_257);}
          X60Qx_252 = X60Qx_255;}
        else {
          X60Qx_252 = NIM_FALSE;}
        if (X60Qx_252){
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_258 = ___1_Iclcqmw1_aow7lb5cq1(i_9, ((NI32)(((NI32)(i_9 + n_2)) - 1)));
          string_0_sysvq0asl X60Qtmp_9 = getQ_14_sysvq0asl(src_3, X60Qx_258);
          NB8 X60Qx_259 = eqQ_20_sysvq0asl(X60Qtmp_9, name_0);
          X60Qx_24 = X60Qx_259;
          nimStrDestroy(X60Qtmp_9);}
        else {
          X60Qx_24 = NIM_FALSE;}
        if (X60Qx_24){
          NC8 X60Qx_260 = getQ_9_sysvq0asl(src_3, ((NI32)(i_9 + n_2)));
          X60Qx_23 = (X60Qx_260 == (NC8)'(');}
        else {
          X60Qx_23 = NIM_FALSE;}
        if (X60Qx_23){
          NB8 X60Qx_261 = lineStartsAtColumn0_0_aow7lb5cq1(src_3, i_9);
          X60Qx_22 = X60Qx_261;}
        else {
          X60Qx_22 = NIM_FALSE;}
        if (X60Qx_22){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_9));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_27;}
seq_0_Ixdx2fh1_aow7lb5cq1 mangledNamesFor_0_aow7lb5cq1(string_0_sysvq0asl src_4, string_0_sysvq0asl base_1){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_28;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_28));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_28);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_262 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_28 = X60Qx_262;
  NI32 n_3 = len_4_sysvq0asl(base_1);
  NB8 X60Qx_263;
  if (n_3 == 0){
    X60Qx_263 = NIM_TRUE;}
  else {
    NI32 X60Qx_264 = len_4_sysvq0asl(src_4);
    X60Qx_263 = (X60Qx_264 == 0);}
  if (X60Qx_263){
    return result_28;}
  NI32 i_10 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_265 = len_4_sysvq0asl(src_4);
      if (((NI32)(i_10 + n_3)) < X60Qx_265){
        NB8 X60Qx_25;
        NB8 X60Qx_266;
        NC8 X60Qx_267 = getQ_9_sysvq0asl(src_4, i_10);
        NC8 X60Qx_268 = getQ_9_sysvq0asl(base_1, 0);
        if (X60Qx_267 == X60Qx_268){
          NB8 X60Qx_269;
          if (i_10 == 0){
            X60Qx_269 = NIM_TRUE;}
          else {
            NC8 X60Qx_270 = getQ_9_sysvq0asl(src_4, ((NI32)(i_10 - 1)));
            NB8 X60Qx_271 = isIdentChar_0_aow7lb5cq1(X60Qx_270);
            X60Qx_269 = (!X60Qx_271);}
          X60Qx_266 = X60Qx_269;}
        else {
          X60Qx_266 = NIM_FALSE;}
        if (X60Qx_266){
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_272 = ___1_Iclcqmw1_aow7lb5cq1(i_10, ((NI32)(((NI32)(i_10 + n_3)) - 1)));
          string_0_sysvq0asl X60Qtmp_10 = getQ_14_sysvq0asl(src_4, X60Qx_272);
          NB8 X60Qx_273 = eqQ_20_sysvq0asl(X60Qtmp_10, base_1);
          X60Qx_25 = X60Qx_273;
          nimStrDestroy(X60Qtmp_10);}
        else {
          X60Qx_25 = NIM_FALSE;}
        if (X60Qx_25){
          NI32 j_2 = ((NI32)(i_10 + n_3));
          NB8 X60Qx_274;
          NI32 X60Qx_275 = len_4_sysvq0asl(src_4);
          if (j_2 < X60Qx_275){
            NC8 X60Qx_276 = getQ_9_sysvq0asl(src_4, j_2);
            X60Qx_274 = (X60Qx_276 == (NC8)'_');}
          else {
            X60Qx_274 = NIM_FALSE;}
          if (X60Qx_274){
            inc_1_I6wjjge_aow2h993l1((&j_2));
            NI32 digits_1 = 0;
            {
              while (NIM_TRUE){
                NB8 X60Qx_277;
                NB8 X60Qx_278;
                NI32 X60Qx_279 = len_4_sysvq0asl(src_4);
                if (j_2 < X60Qx_279){
                  NC8 X60Qx_280 = getQ_9_sysvq0asl(src_4, j_2);
                  X60Qx_278 = ((NC8)'0' <= X60Qx_280);}
                else {
                  X60Qx_278 = NIM_FALSE;}
                if (X60Qx_278){
                  NC8 X60Qx_281 = getQ_9_sysvq0asl(src_4, j_2);
                  X60Qx_277 = (X60Qx_281 <= (NC8)'9');}
                else {
                  X60Qx_277 = NIM_FALSE;}
                if (X60Qx_277){
                  inc_1_I6wjjge_aow2h993l1((&j_2));
                  inc_1_I6wjjge_aow2h993l1((&digits_1));}
                else {
                  break;}}}
            whileStmtLabel_1: ;
            NB8 X60Qx_282;
            NB8 X60Qx_283;
            if (0 < digits_1){
              NI32 X60Qx_284 = len_4_sysvq0asl(src_4);
              X60Qx_283 = (j_2 < X60Qx_284);}
            else {
              X60Qx_283 = NIM_FALSE;}
            if (X60Qx_283){
              NC8 X60Qx_285 = getQ_9_sysvq0asl(src_4, j_2);
              X60Qx_282 = (X60Qx_285 == (NC8)'_');}
            else {
              X60Qx_282 = NIM_FALSE;}
            if (X60Qx_282){
              inc_1_I6wjjge_aow2h993l1((&j_2));
              {
                while (NIM_TRUE){
                  NB8 X60Qx_286;
                  NI32 X60Qx_287 = len_4_sysvq0asl(src_4);
                  if (j_2 < X60Qx_287){
                    NC8 X60Qx_288 = getQ_9_sysvq0asl(src_4, j_2);
                    NB8 X60Qx_289 = isIdentChar_0_aow7lb5cq1(X60Qx_288);
                    X60Qx_286 = X60Qx_289;}
                  else {
                    X60Qx_286 = NIM_FALSE;}
                  if (X60Qx_286){
                    inc_1_I6wjjge_aow2h993l1((&j_2));}
                  else {
                    break;}}}
              whileStmtLabel_2: ;
              NB8 X60Qx_290;
              NB8 X60Qx_291;
              NI32 X60Qx_292 = len_4_sysvq0asl(src_4);
              if (j_2 < X60Qx_292){
                NC8 X60Qx_293 = getQ_9_sysvq0asl(src_4, j_2);
                X60Qx_291 = (X60Qx_293 == (NC8)'(');}
              else {
                X60Qx_291 = NIM_FALSE;}
              if (X60Qx_291){
                NB8 X60Qx_294 = lineStartsAtColumn0_0_aow7lb5cq1(src_4, i_10);
                X60Qx_290 = X60Qx_294;}
              else {
                X60Qx_290 = NIM_FALSE;}
              if (X60Qx_290){
                HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_295 = ___1_Iclcqmw1_aow7lb5cq1(i_10, ((NI32)(j_2 - 1)));
                string_0_sysvq0asl nm_0 = getQ_14_sysvq0asl(src_4, X60Qx_295);
                NB8 dup_0 = NIM_FALSE;
                {
                  openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_8 = toOpenArray_1_I6b60gk1_aow7lb5cq1(result_28);
                  NI32 X60Qlf_9 = 0;
                  {
                    while (NIM_TRUE){
                      NI32 X60Qx_296 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_8);
                      if (X60Qlf_9 < X60Qx_296){
                        {
                          string_0_sysvq0asl* X60Qii_5 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_8, X60Qlf_9);
                          NB8 X60Qx_297 = eqQ_20_sysvq0asl((*X60Qii_5), nm_0);
                          if (X60Qx_297){
                            dup_0 = NIM_TRUE;
                            goto forStmtLabel_3;}}
                        inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}
                      else {
                        break;}}}
                  whileStmtLabel_4: ;}
                forStmtLabel_3: ;
                if ((!dup_0)){
                  string_0_sysvq0asl X60Qtmp_11 = nm_0;
                  nimStrWasMoved((&nm_0));
                  add_0_Ig6072n_aow7lb5cq1((&result_28), X60Qtmp_11);}
                nimStrDestroy(nm_0);}}}}
        inc_1_I6wjjge_aow2h993l1((&i_10));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_28;}
string_0_sysvq0asl trimC_0_aow7lb5cq1(string_0_sysvq0asl s_0){
  string_0_sysvq0asl result_29;
  nimStrWasMoved((&result_29));
  NI32 a_7 = 0;
  NI32 X60Qx_298 = len_4_sysvq0asl(s_0);
  NI32 b_1 = ((NI32)(X60Qx_298 - 1));
  {
    while (NIM_TRUE){
      NB8 X60Qx_299;
      if (a_7 <= b_1){
        NB8 X60Qx_300;
        NB8 X60Qx_301;
        NC8 X60Qx_302 = getQ_9_sysvq0asl(s_0, a_7);
        if (X60Qx_302 == (NC8)' '){
          X60Qx_301 = NIM_TRUE;}
        else {
          NC8 X60Qx_303 = getQ_9_sysvq0asl(s_0, a_7);
          X60Qx_301 = (X60Qx_303 == (NC8)'\012');}
        if (X60Qx_301){
          X60Qx_300 = NIM_TRUE;}
        else {
          NC8 X60Qx_304 = getQ_9_sysvq0asl(s_0, a_7);
          X60Qx_300 = (X60Qx_304 == (NC8)'\011');}
        X60Qx_299 = X60Qx_300;}
      else {
        X60Qx_299 = NIM_FALSE;}
      if (X60Qx_299){
        inc_1_I6wjjge_aow2h993l1((&a_7));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  {
    while (NIM_TRUE){
      NB8 X60Qx_305;
      if (a_7 <= b_1){
        NB8 X60Qx_306;
        NB8 X60Qx_307;
        NC8 X60Qx_308 = getQ_9_sysvq0asl(s_0, b_1);
        if (X60Qx_308 == (NC8)' '){
          X60Qx_307 = NIM_TRUE;}
        else {
          NC8 X60Qx_309 = getQ_9_sysvq0asl(s_0, b_1);
          X60Qx_307 = (X60Qx_309 == (NC8)'\012');}
        if (X60Qx_307){
          X60Qx_306 = NIM_TRUE;}
        else {
          NC8 X60Qx_310 = getQ_9_sysvq0asl(s_0, b_1);
          X60Qx_306 = (X60Qx_310 == (NC8)'\011');}
        X60Qx_305 = X60Qx_306;}
      else {
        X60Qx_305 = NIM_FALSE;}
      if (X60Qx_305){
        dec_1_I0nzoz91_aow7lb5cq1((&b_1));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  string_0_sysvq0asl X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  if (b_1 < a_7){
    nimStrDestroy(X60Qx_2);
    X60Qx_2 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  else {
    nimStrDestroy(X60Qx_2);
    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_311 = ___1_Iclcqmw1_aow7lb5cq1(a_7, b_1);
    string_0_sysvq0asl X60Qx_312 = getQ_14_sysvq0asl(s_0, X60Qx_311);
    X60Qx_2 = X60Qx_312;}
  nimStrDestroy(result_29);
  result_29 = X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  nimStrDestroy(X60Qx_2);
  return result_29;
  nimStrDestroy(X60Qx_2);
  return result_29;}
string_0_sysvq0asl paramTypeOf_0_aow7lb5cq1(string_0_sysvq0asl decl_0){
  string_0_sysvq0asl result_30;
  nimStrWasMoved((&result_30));
  string_0_sysvq0asl d_0 = trimC_0_aow7lb5cq1(decl_0);
  NI32 X60Qx_313 = len_4_sysvq0asl(d_0);
  if (X60Qx_313 == 0){
    nimStrDestroy(d_0);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NB8 X60Qx_314 = eqQ_20_sysvq0asl(d_0, (string_0_sysvq0asl){
    .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
  );
  if (X60Qx_314){
    nimStrDestroy(d_0);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 X60Qx_315 = len_4_sysvq0asl(d_0);
  NI32 j_3 = ((NI32)(X60Qx_315 - 1));
  {
    while (NIM_TRUE){
      NB8 X60Qx_316;
      if (0 <= j_3){
        NC8 X60Qx_317 = getQ_9_sysvq0asl(d_0, j_3);
        NB8 X60Qx_318 = isIdentChar_0_aow7lb5cq1(X60Qx_317);
        X60Qx_316 = X60Qx_318;}
      else {
        X60Qx_316 = NIM_FALSE;}
      if (X60Qx_316){
        dec_1_I0nzoz91_aow7lb5cq1((&j_3));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (j_3 < 0){
    string_0_sysvq0asl X60Qtmp_12 = d_0;
    nimStrWasMoved((&d_0));
    nimStrDestroy(d_0);
    return X60Qtmp_12;}
  nimStrDestroy(result_30);
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_319 = ___1_Iclcqmw1_aow7lb5cq1(0, j_3);
  string_0_sysvq0asl X60Qtmp_13 = getQ_14_sysvq0asl(d_0, X60Qx_319);
  string_0_sysvq0asl X60Qx_320 = trimC_0_aow7lb5cq1(X60Qtmp_13);
  result_30 = X60Qx_320;
  nimStrDestroy(X60Qtmp_13);
  nimStrDestroy(d_0);
  return result_30;
  nimStrDestroy(X60Qtmp_13);
  nimStrDestroy(d_0);
  return result_30;}
string_0_sysvq0asl lastToken_0_aow7lb5cq1(string_0_sysvq0asl s_1){
  string_0_sysvq0asl result_31;
  nimStrWasMoved((&result_31));
  string_0_sysvq0asl t_2 = trimC_0_aow7lb5cq1(s_1);
  NI32 X60Qx_321 = len_4_sysvq0asl(t_2);
  NI32 j_4 = ((NI32)(X60Qx_321 - 1));
  {
    while (NIM_TRUE){
      NB8 X60Qx_322;
      NB8 X60Qx_323;
      if (0 <= j_4){
        NC8 X60Qx_324 = getQ_9_sysvq0asl(t_2, j_4);
        X60Qx_323 = (!(X60Qx_324 == (NC8)' '));}
      else {
        X60Qx_323 = NIM_FALSE;}
      if (X60Qx_323){
        NC8 X60Qx_325 = getQ_9_sysvq0asl(t_2, j_4);
        X60Qx_322 = (!(X60Qx_325 == (NC8)'\011'));}
      else {
        X60Qx_322 = NIM_FALSE;}
      if (X60Qx_322){
        dec_1_I0nzoz91_aow7lb5cq1((&j_4));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(result_31);
  NI32 X60Qx_326 = len_4_sysvq0asl(t_2);
  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_327 = ___1_Iclcqmw1_aow7lb5cq1(((NI32)(j_4 + 1)), ((NI32)(X60Qx_326 - 1)));
  string_0_sysvq0asl X60Qx_328 = getQ_14_sysvq0asl(t_2, X60Qx_327);
  result_31 = X60Qx_328;
  nimStrDestroy(t_2);
  return result_31;
  nimStrDestroy(t_2);
  return result_31;}
CSig_0_aow7lb5cq1 sigOf_0_aow7lb5cq1(string_0_sysvq0asl src_5, string_0_sysvq0asl mangled_0){
  CSig_0_aow7lb5cq1 result_32;
  eQwasmovedQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1((&result_32));
  eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(result_32);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_329 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_32 = (CSig_0_aow7lb5cq1){
    .ok_0 = NIM_FALSE, .ret_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .params_0 = X60Qx_329}
  ;
  NI32 n_4 = len_4_sysvq0asl(mangled_0);
  if (n_4 == 0){
    return result_32;}
  NI32 i_11 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_330 = len_4_sysvq0asl(src_5);
      if (((NI32)(i_11 + n_4)) < X60Qx_330){
        NB8 X60Qx_26;
        NB8 X60Qx_27;
        NB8 X60Qx_28;
        NB8 X60Qx_331;
        NC8 X60Qx_332 = getQ_9_sysvq0asl(src_5, i_11);
        NC8 X60Qx_333 = getQ_9_sysvq0asl(mangled_0, 0);
        if (X60Qx_332 == X60Qx_333){
          NB8 X60Qx_334;
          if (i_11 == 0){
            X60Qx_334 = NIM_TRUE;}
          else {
            NC8 X60Qx_335 = getQ_9_sysvq0asl(src_5, ((NI32)(i_11 - 1)));
            NB8 X60Qx_336 = isIdentChar_0_aow7lb5cq1(X60Qx_335);
            X60Qx_334 = (!X60Qx_336);}
          X60Qx_331 = X60Qx_334;}
        else {
          X60Qx_331 = NIM_FALSE;}
        if (X60Qx_331){
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_337 = ___1_Iclcqmw1_aow7lb5cq1(i_11, ((NI32)(((NI32)(i_11 + n_4)) - 1)));
          string_0_sysvq0asl X60Qtmp_14 = getQ_14_sysvq0asl(src_5, X60Qx_337);
          NB8 X60Qx_338 = eqQ_20_sysvq0asl(X60Qtmp_14, mangled_0);
          X60Qx_28 = X60Qx_338;
          nimStrDestroy(X60Qtmp_14);}
        else {
          X60Qx_28 = NIM_FALSE;}
        if (X60Qx_28){
          NC8 X60Qx_339 = getQ_9_sysvq0asl(src_5, ((NI32)(i_11 + n_4)));
          X60Qx_27 = (X60Qx_339 == (NC8)'(');}
        else {
          X60Qx_27 = NIM_FALSE;}
        if (X60Qx_27){
          NB8 X60Qx_340 = lineStartsAtColumn0_0_aow7lb5cq1(src_5, i_11);
          X60Qx_26 = X60Qx_340;}
        else {
          X60Qx_26 = NIM_FALSE;}
        if (X60Qx_26){
          NI32 ls_0 = i_11;
          {
            while (NIM_TRUE){
              NB8 X60Qx_341;
              if (0 < ls_0){
                NC8 X60Qx_342 = getQ_9_sysvq0asl(src_5, ((NI32)(ls_0 - 1)));
                X60Qx_341 = (!(X60Qx_342 == (NC8)'\012'));}
              else {
                X60Qx_341 = NIM_FALSE;}
              if (X60Qx_341){
                dec_1_I0nzoz91_aow7lb5cq1((&ls_0));}
              else {
                break;}}}
          whileStmtLabel_1: ;
          string_0_sysvq0asl* X60Qlhs_15 = (&result_32.ret_0);
          nimStrDestroy((*X60Qlhs_15));
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_343 = ___1_Iclcqmw1_aow7lb5cq1(ls_0, ((NI32)(i_11 - 1)));
          string_0_sysvq0asl X60Qtmp_16 = getQ_14_sysvq0asl(src_5, X60Qx_343);
          string_0_sysvq0asl X60Qx_344 = lastToken_0_aow7lb5cq1(X60Qtmp_16);
          (*X60Qlhs_15) = X60Qx_344;
          NI32 X60Qx_345 = len_4_sysvq0asl(result_32.ret_0);
          if (X60Qx_345 == 0){
            string_0_sysvq0asl* X60Qlhs_17 = (&result_32.ret_0);
            nimStrDestroy((*X60Qlhs_17));
            (*X60Qlhs_17) = (string_0_sysvq0asl){
              .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
            ;}
          NI32 j_5 = ((NI32)(((NI32)(i_11 + n_4)) + 1));
          NI32 depth_3 = 0;
          string_0_sysvq0asl cur_1 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;
          {
            while (NIM_TRUE){
              NI32 X60Qx_346 = len_4_sysvq0asl(src_5);
              if (j_5 < X60Qx_346){
                NC8 c_2 = getQ_9_sysvq0asl(src_5, j_5);
                if (c_2 == (NC8)'('){
                  inc_1_I6wjjge_aow2h993l1((&depth_3));
                  add_1_sysvq0asl((&cur_1), c_2);}
                else {
                  if (c_2 == (NC8)')'){
                    if (depth_3 == 0){
                      string_0_sysvq0asl t_3 = paramTypeOf_0_aow7lb5cq1(cur_1);
                      NI32 X60Qx_347 = len_4_sysvq0asl(t_3);
                      if (0 < X60Qx_347){
                        string_0_sysvq0asl X60Qtmp_18 = t_3;
                        nimStrWasMoved((&t_3));
                        add_0_Ig6072n_aow7lb5cq1((&result_32.params_0), X60Qtmp_18);}
                      else {
                        NB8 X60Qx_29;
                        string_0_sysvq0asl X60Qtmp_19 = trimC_0_aow7lb5cq1(cur_1);
                        NI32 X60Qx_348 = len_4_sysvq0asl(X60Qtmp_19);
                        if (0 < X60Qx_348){
                          string_0_sysvq0asl X60Qtmp_20 = trimC_0_aow7lb5cq1(cur_1);
                          NB8 X60Qx_349 = eqQ_20_sysvq0asl(X60Qtmp_20, (string_0_sysvq0asl){
                            .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
                          );
                          X60Qx_29 = (!X60Qx_349);
                          nimStrDestroy(X60Qtmp_20);}
                        else {
                          X60Qx_29 = NIM_FALSE;}
                        if (X60Qx_29){
                          nimStrDestroy(X60Qtmp_19);
                          nimStrDestroy(t_3);
                          nimStrDestroy(cur_1);
                          nimStrDestroy(X60Qtmp_16);
                          return result_32;}
                        nimStrDestroy(X60Qtmp_19);}
                      result_32.ok_0 = NIM_TRUE;
                      nimStrDestroy(t_3);
                      nimStrDestroy(cur_1);
                      nimStrDestroy(X60Qtmp_16);
                      return result_32;
                      nimStrDestroy(t_3);}
                    dec_1_I0nzoz91_aow7lb5cq1((&depth_3));
                    add_1_sysvq0asl((&cur_1), c_2);}
                  else {
                    NB8 X60Qx_350;
                    if (c_2 == (NC8)','){
                      X60Qx_350 = (depth_3 == 0);}
                    else {
                      X60Qx_350 = NIM_FALSE;}
                    if (X60Qx_350){
                      string_0_sysvq0asl t_4 = paramTypeOf_0_aow7lb5cq1(cur_1);
                      NI32 X60Qx_351 = len_4_sysvq0asl(t_4);
                      if (X60Qx_351 == 0){
                        nimStrDestroy(t_4);
                        nimStrDestroy(cur_1);
                        nimStrDestroy(X60Qtmp_16);
                        return result_32;}
                      string_0_sysvq0asl X60Qtmp_21 = t_4;
                      nimStrWasMoved((&t_4));
                      add_0_Ig6072n_aow7lb5cq1((&result_32.params_0), X60Qtmp_21);
                      nimStrDestroy(cur_1);
                      cur_1 = (string_0_sysvq0asl){
                        .bytes_0 = 0u, .more_0 = NIM_NIL}
                      ;
                      nimStrDestroy(t_4);}
                    else {
                      if (c_2 == (NC8)'\012'){
                        nimStrDestroy(cur_1);
                        nimStrDestroy(X60Qtmp_16);
                        return result_32;}
                      else {
                        add_1_sysvq0asl((&cur_1), c_2);}}}}
                inc_1_I6wjjge_aow2h993l1((&j_5));}
              else {
                break;}}}
          whileStmtLabel_2: ;
          nimStrDestroy(cur_1);
          nimStrDestroy(X60Qtmp_16);
          return result_32;
          nimStrDestroy(cur_1);
          nimStrDestroy(X60Qtmp_16);}
        inc_1_I6wjjge_aow2h993l1((&i_11));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_32;}
string_0_sysvq0asl derefType_0_aow7lb5cq1(string_0_sysvq0asl t_0){
  string_0_sysvq0asl result_33;
  nimStrWasMoved((&result_33));
  string_0_sysvq0asl s_13 = trimC_0_aow7lb5cq1(t_0);
  NB8 X60Qx_352;
  NI32 X60Qx_353 = len_4_sysvq0asl(s_13);
  if (0 < X60Qx_353){
    NI32 X60Qx_354 = len_4_sysvq0asl(s_13);
    NC8 X60Qx_355 = getQ_9_sysvq0asl(s_13, ((NI32)(X60Qx_354 - 1)));
    X60Qx_352 = (X60Qx_355 == (NC8)'*');}
  else {
    X60Qx_352 = NIM_FALSE;}
  if (X60Qx_352){
    nimStrDestroy(result_33);
    NI32 X60Qx_356 = len_4_sysvq0asl(s_13);
    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_357 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_356 - 2)));
    string_0_sysvq0asl X60Qtmp_22 = getQ_14_sysvq0asl(s_13, X60Qx_357);
    string_0_sysvq0asl X60Qx_358 = trimC_0_aow7lb5cq1(X60Qtmp_22);
    result_33 = X60Qx_358;
    nimStrDestroy(X60Qtmp_22);}
  else {
    nimStrDestroy(result_33);
    result_33 = s_13;
    nimStrWasMoved((&s_13));}
  nimStrDestroy(s_13);
  return result_33;
  nimStrDestroy(s_13);
  return result_33;}
string_0_sysvq0asl typeNameAfter_0_aow7lb5cq1(string_0_sysvq0asl src_6, string_0_sysvq0asl prefix_0){
  string_0_sysvq0asl result_34;
  nimStrWasMoved((&result_34));
  nimStrDestroy(result_34);
  result_34 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 i_12 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_359 = len_4_sysvq0asl(prefix_0);
      NI32 X60Qx_360 = len_4_sysvq0asl(src_6);
      if (((NI32)(i_12 + X60Qx_359)) <= X60Qx_360){
        NB8 X60Qx_30;
        NB8 X60Qx_31;
        NC8 X60Qx_361 = getQ_9_sysvq0asl(src_6, i_12);
        NC8 X60Qx_362 = getQ_9_sysvq0asl(prefix_0, 0);
        if (X60Qx_361 == X60Qx_362){
          NI32 X60Qx_363 = len_4_sysvq0asl(prefix_0);
          HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_364 = ___1_Iclcqmw1_aow7lb5cq1(i_12, ((NI32)(((NI32)(i_12 + X60Qx_363)) - 1)));
          string_0_sysvq0asl X60Qtmp_23 = getQ_14_sysvq0asl(src_6, X60Qx_364);
          NB8 X60Qx_365 = eqQ_20_sysvq0asl(X60Qtmp_23, prefix_0);
          X60Qx_31 = X60Qx_365;
          nimStrDestroy(X60Qtmp_23);}
        else {
          X60Qx_31 = NIM_FALSE;}
        if (X60Qx_31){
          NB8 X60Qx_366;
          if (i_12 == 0){
            X60Qx_366 = NIM_TRUE;}
          else {
            NC8 X60Qx_367 = getQ_9_sysvq0asl(src_6, ((NI32)(i_12 - 1)));
            NB8 X60Qx_368 = isIdentChar_0_aow7lb5cq1(X60Qx_367);
            X60Qx_366 = (!X60Qx_368);}
          X60Qx_30 = X60Qx_366;}
        else {
          X60Qx_30 = NIM_FALSE;}
        if (X60Qx_30){
          NI32 X60Qx_369 = len_4_sysvq0asl(prefix_0);
          NI32 j_6 = ((NI32)(i_12 + X60Qx_369));
          {
            while (NIM_TRUE){
              NB8 X60Qx_370;
              NI32 X60Qx_371 = len_4_sysvq0asl(src_6);
              if (j_6 < X60Qx_371){
                NC8 X60Qx_372 = getQ_9_sysvq0asl(src_6, j_6);
                NB8 X60Qx_373 = isIdentChar_0_aow7lb5cq1(X60Qx_372);
                X60Qx_370 = X60Qx_373;}
              else {
                X60Qx_370 = NIM_FALSE;}
              if (X60Qx_370){
                inc_1_I6wjjge_aow2h993l1((&j_6));}
              else {
                break;}}}
          whileStmtLabel_1: ;
          NI32 X60Qx_374 = len_4_sysvq0asl(prefix_0);
          if (((NI32)(i_12 + X60Qx_374)) < j_6){
            HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_375 = ___1_Iclcqmw1_aow7lb5cq1(i_12, ((NI32)(j_6 - 1)));
            string_0_sysvq0asl X60Qx_376 = getQ_14_sysvq0asl(src_6, X60Qx_375);
            result_34 = X60Qx_376;
            return result_34;}}
        inc_1_I6wjjge_aow2h993l1((&i_12));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_34;}
string_0_sysvq0asl strHelpers_0_aow7lb5cq1(string_0_sysvq0asl strT_0, string_0_sysvq0asl longT_0, string_0_sysvq0asl borrowFn_0){
  string_0_sysvq0asl result_35;
  nimStrWasMoved((&result_35));
  NI32 X60Qx_377 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 707726078u, .more_0 = (&strlit_0_I1797034738989881978_aow7lb5cq1)}
  );
  NI32 X60Qx_378 = len_4_sysvq0asl(strT_0);
  NI32 X60Qx_379 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I1876279935150955625_aow7lb5cq1)}
  );
  NI32 X60Qx_380 = len_4_sysvq0asl(strT_0);
  NI32 X60Qx_381 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I10786624760865126126_aow7lb5cq1)}
  );
  NI32 X60Qx_382 = len_4_sysvq0asl(strT_0);
  NI32 X60Qx_383 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1868636414u, .more_0 = (&strlit_0_I2723993762017903615_aow7lb5cq1)}
  );
  NI32 X60Qx_384 = len_4_sysvq0asl(longT_0);
  NI32 X60Qx_385 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 539634430u, .more_0 = (&strlit_0_I3721006562773567258_aow7lb5cq1)}
  );
  NI32 X60Qx_386 = len_4_sysvq0asl(strT_0);
  NI32 X60Qx_387 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 997400830u, .more_0 = (&strlit_0_I9356103350728131647_aow7lb5cq1)}
  );
  NI32 X60Qx_388 = len_4_sysvq0asl(borrowFn_0);
  NI32 X60Qx_389 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1663576318u, .more_0 = (&strlit_0_I12087480461722773288_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_377 + X60Qx_378)) + X60Qx_379)) + X60Qx_380)) + X60Qx_381)) + X60Qx_382)) + X60Qx_383)) + X60Qx_384)) + X60Qx_385)) + X60Qx_386)) + X60Qx_387)) + X60Qx_388)) + X60Qx_389)));
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 707726078u, .more_0 = (&strlit_0_I1797034738989881978_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_9), strT_0);
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I1876279935150955625_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_9), strT_0);
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 1931487998u, .more_0 = (&strlit_0_I10786624760865126126_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_9), strT_0);
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 1868636414u, .more_0 = (&strlit_0_I2723993762017903615_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_9), longT_0);
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 539634430u, .more_0 = (&strlit_0_I3721006562773567258_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_9), strT_0);
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 997400830u, .more_0 = (&strlit_0_I9356103350728131647_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_9), borrowFn_0);
  add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
    .bytes_0 = 1663576318u, .more_0 = (&strlit_0_I12087480461722773288_aow7lb5cq1)}
  );
  nimStrDestroy(result_35);
  result_35 = X60Qdesugar_9;
  nimStrWasMoved((&X60Qdesugar_9));
  nimStrDestroy(X60Qdesugar_9);
  return result_35;
  nimStrDestroy(X60Qdesugar_9);
  return result_35;}
NI32 scalarWidth_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_2){
  NI32 result_36;
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_390 = sizeAlign_1_layptix6a1(td_2, 8);
  result_36 = X60Qx_390.fld_0;
  return result_36;}
NB8 compositeCOk_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_3, NI32 depth_1){
  NB8 result_37;
  if (td_3 == NIM_NIL){
    return NIM_FALSE;}
  if (6 < depth_1){
    return NIM_FALSE;}
  switch ((*td_3).d_00.kind_0){
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
      openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_391 = toOpenArray_0_Iccbrld_aow7lb5cq1((&X60QconstRefTemp_0));
      NI32 X60Qx_392 = scalarWidth_0_aow7lb5cq1(td_3);
      NB8 X60Qx_393 = contains_3_Ipa7o28_aow7lb5cq1(X60Qx_391, X60Qx_392);
      result_37 = X60Qx_393;}
    break;
    case 14:
    {
      result_37 = NIM_TRUE;}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_0 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_3).d_00.elem_0);
      if (el_0 == NIM_NIL){
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_0);
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
          NB8 X60Qx_3;
          NI32 X60Qx_4;
          if (0 < sa_0.fld_1){
            X60Qx_4 = sa_0.fld_1;}
          else {
            X60Qx_4 = 1;}
          NI32 X60Qx_394 = align_0_layptix6a1(sa_0.fld_0, X60Qx_4);
          if (sa_0.fld_0 == X60Qx_394){
            X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1 X60QconstRefTemp_1 = (X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1){
              .a = {
                1, 2, 4, 8}}
            ;
            openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_395 = toOpenArray_0_Iccbrld_aow7lb5cq1((&X60QconstRefTemp_1));
            NB8 X60Qx_396 = contains_3_Ipa7o28_aow7lb5cq1(X60Qx_395, sa_0.fld_0);
            X60Qx_3 = X60Qx_396;}
          else {
            X60Qx_3 = NIM_FALSE;}
          result_37 = X60Qx_3;}
        break;
        case 14:
        {
          result_37 = NIM_TRUE;}
        break;
        default:
        {
          result_37 = NIM_FALSE;}
        break;}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_0);}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_397;
      if ((*td_3).d_00.incomplete_0){
        X60Qx_397 = NIM_TRUE;}
      else {
        X60Qx_397 = (*td_3).d_00.union_0;}
      if (X60Qx_397){
        return NIM_FALSE;}
      NI32 i_13 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_398 = len_3_I5m68tr1_aow7lb5cq1((*td_3).d_00.fields_0);
          if (i_13 < X60Qx_398){
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_399 = getQ_7_I45w7c91_aow7lb5cq1((*td_3).d_00.fields_0, i_13);
            NB8 X60Qx_400 = compositeCOk_0_aow7lb5cq1((*X60Qx_399), ((NI32)(depth_1 + 1)));
            if ((!X60Qx_400)){
              return NIM_FALSE;}
            inc_1_I6wjjge_aow2h993l1((&i_13));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      result_37 = NIM_TRUE;}
    break;
    default:
    {
      result_37 = NIM_FALSE;}
    break;}
  return result_37;}
string_0_sysvq0asl compositeWhyNot_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_4, NI32 depth_2){
  string_0_sysvq0asl result_38;
  nimStrWasMoved((&result_38));
  if (td_4 == NIM_NIL){
    return (string_0_sysvq0asl){
      .bytes_0 = 1818849022u, .more_0 = (&strlit_0_I988991057058608115_aow7lb5cq1)}
    ;}
  if (6 < depth_2){
    return (string_0_sysvq0asl){
      .bytes_0 = 1936027390u, .more_0 = (&strlit_0_I324375890710632441_aow7lb5cq1)}
    ;}
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
      openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_401 = toOpenArray_0_Iccbrld_aow7lb5cq1((&X60QconstRefTemp_0));
      NI32 X60Qx_402 = scalarWidth_0_aow7lb5cq1(td_4);
      NB8 X60Qx_403 = contains_3_Ipa7o28_aow7lb5cq1(X60Qx_401, X60Qx_402);
      if (X60Qx_403){
        return (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;}
      NI32 X60Qx_404 = scalarWidth_0_aow7lb5cq1(td_4);
      string_0_sysvq0asl X60Qdesugar_10 = dollarQ_2_sysvq0asl(X60Qx_404);
      NI32 X60Qx_405 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2121986u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_406 = len_4_sysvq0asl(X60Qdesugar_10);
      NI32 X60Qx_407 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2036477438u, .more_0 = (&strlit_0_I10406916229603502364_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_11 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_405 + X60Qx_406)) + X60Qx_407)));
      add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
        .bytes_0 = 2121986u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_11), X60Qdesugar_10);
      add_2_sysvq0asl((&X60Qdesugar_11), (string_0_sysvq0asl){
        .bytes_0 = 2036477438u, .more_0 = (&strlit_0_I10406916229603502364_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qtmp_24 = X60Qdesugar_11;
      nimStrWasMoved((&X60Qdesugar_11));
      nimStrDestroy(X60Qdesugar_11);
      nimStrDestroy(X60Qdesugar_10);
      return X60Qtmp_24;
      nimStrDestroy(X60Qdesugar_11);
      nimStrDestroy(X60Qdesugar_10);}
    break;
    case 14:
    {
      return (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_1 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_4).d_00.elem_0);
      if (el_1 == NIM_NIL){
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_1);
        return (string_0_sysvq0asl){
          .bytes_0 = 1931502078u, .more_0 = (&strlit_0_I10718771205828439240_aow7lb5cq1)}
        ;}
      switch ((*el_1).d_00.kind_0){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 8:
        {
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_1 = sizeAlign_1_layptix6a1(el_1, 8);
          NB8 X60Qx_5;
          NI32 X60Qx_6;
          if (0 < sa_1.fld_1){
            X60Qx_6 = sa_1.fld_1;}
          else {
            X60Qx_6 = 1;}
          NI32 X60Qx_408 = align_0_layptix6a1(sa_1.fld_0, X60Qx_6);
          if (sa_1.fld_0 == X60Qx_408){
            X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1 X60QconstRefTemp_1 = (X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1){
              .a = {
                1, 2, 4, 8}}
            ;
            openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_409 = toOpenArray_0_Iccbrld_aow7lb5cq1((&X60QconstRefTemp_1));
            NB8 X60Qx_410 = contains_3_Ipa7o28_aow7lb5cq1(X60Qx_409, sa_1.fld_0);
            X60Qx_5 = X60Qx_410;}
          else {
            X60Qx_5 = NIM_FALSE;}
          if (X60Qx_5){
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_1);
            return (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            ;}
          string_0_sysvq0asl X60Qdesugar_12 = dollarQ_2_sysvq0asl(sa_1.fld_0);
          string_0_sysvq0asl X60Qdesugar_13 = dollarQ_2_sysvq0asl(sa_1.fld_1);
          NI32 X60Qx_411 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1931502078u, .more_0 = (&strlit_0_I15127899386611443455_aow7lb5cq1)}
          );
          NI32 X60Qx_412 = len_4_sysvq0asl(X60Qdesugar_12);
          NI32 X60Qx_413 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I12873789045226272086_aow7lb5cq1)}
          );
          NI32 X60Qx_414 = len_4_sysvq0asl(X60Qdesugar_13);
          NI32 X60Qx_415 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 540682750u, .more_0 = (&strlit_0_I3693825722426563353_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_14 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_411 + X60Qx_412)) + X60Qx_413)) + X60Qx_414)) + X60Qx_415)));
          add_2_sysvq0asl((&X60Qdesugar_14), (string_0_sysvq0asl){
            .bytes_0 = 1931502078u, .more_0 = (&strlit_0_I15127899386611443455_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_14), X60Qdesugar_12);
          add_2_sysvq0asl((&X60Qdesugar_14), (string_0_sysvq0asl){
            .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I12873789045226272086_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_14), X60Qdesugar_13);
          add_2_sysvq0asl((&X60Qdesugar_14), (string_0_sysvq0asl){
            .bytes_0 = 540682750u, .more_0 = (&strlit_0_I3693825722426563353_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qtmp_25 = X60Qdesugar_14;
          nimStrWasMoved((&X60Qdesugar_14));
          nimStrDestroy(X60Qdesugar_14);
          nimStrDestroy(X60Qdesugar_13);
          nimStrDestroy(X60Qdesugar_12);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_1);
          return X60Qtmp_25;
          nimStrDestroy(X60Qdesugar_14);
          nimStrDestroy(X60Qdesugar_13);
          nimStrDestroy(X60Qdesugar_12);}
        break;
        case 14:
        {
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_1);
          return (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          ;}
        break;
        default:
        {
          string_0_sysvq0asl X60Qtmp_26 = abiKindName_0_run8hsnpi(el_1);
          string_0_sysvq0asl X60Qx_416 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1931502078u, .more_0 = (&strlit_0_I2553287064141771090_aow7lb5cq1)}
          , X60Qtmp_26);
          result_38 = X60Qx_416;
          nimStrDestroy(X60Qtmp_26);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_1);
          return result_38;
          nimStrDestroy(X60Qtmp_26);}
        break;}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_1);}
    break;
    case 10:
    case 11:
    {
      if ((*td_4).d_00.incomplete_0){
        return (string_0_sysvq0asl){
          .bytes_0 = 544104958u, .more_0 = (&strlit_0_I1157300079854504653_aow7lb5cq1)}
        ;}
      if ((*td_4).d_00.union_0){
        return (string_0_sysvq0asl){
          .bytes_0 = 2065719806u, .more_0 = (&strlit_0_I7806974970349732576_aow7lb5cq1)}
        ;}
      NI32 i_14 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_417 = len_3_I5m68tr1_aow7lb5cq1((*td_4).d_00.fields_0);
          if (i_14 < X60Qx_417){
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_418 = getQ_7_I45w7c91_aow7lb5cq1((*td_4).d_00.fields_0, i_14);
            string_0_sysvq0asl w_1 = compositeWhyNot_0_aow7lb5cq1((*X60Qx_418), ((NI32)(depth_2 + 1)));
            NI32 X60Qx_419 = len_4_sysvq0asl(w_1);
            if (0 < X60Qx_419){
              string_0_sysvq0asl X60Qtmp_27 = w_1;
              nimStrWasMoved((&w_1));
              nimStrDestroy(w_1);
              return X60Qtmp_27;}
            inc_1_I6wjjge_aow2h993l1((&i_14));
            nimStrDestroy(w_1);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      return (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    break;
    default:
    {
      string_0_sysvq0asl X60Qtmp_28 = abiKindName_0_run8hsnpi(td_4);
      string_0_sysvq0asl X60Qx_420 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2121986u, .more_0 = NIM_NIL}
      , X60Qtmp_28);
      result_38 = X60Qx_420;
      nimStrDestroy(X60Qtmp_28);
      return result_38;
      nimStrDestroy(X60Qtmp_28);}
    break;}
  return result_38;}
string_0_sysvq0asl emitCompositeIn_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_5, string_0_sysvq0asl unit_0, string_0_sysvq0asl cty_0, string_0_sysvq0asl dst_0, string_0_sysvq0asl strT_1, string_0_sysvq0asl longT_1, string_0_sysvq0asl allocFn_0, string_0_sysvq0asl deallocFn_0, NI32* tmp_0, string_0_sysvq0asl* owned_0, NB8* ok_0){
  string_0_sysvq0asl result_39;
  nimStrWasMoved((&result_39));
  nimStrDestroy(result_39);
  result_39 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((!(*ok_0))){
    return result_39;}
  inc_1_I6wjjge_aow2h993l1(tmp_0);
  string_0_sysvq0asl k_1 = dollarQ_2_sysvq0asl((*tmp_0));
  switch ((*td_5).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      NI32 X60Qx_421 = scalarWidth_0_aow7lb5cq1(td_5);
      string_0_sysvq0asl w_2 = dollarQ_2_sysvq0asl(X60Qx_421);
      NI32 X60Qx_422 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
      );
      NI32 X60Qx_423 = len_4_sysvq0asl(dst_0);
      NI32 X60Qx_424 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
      );
      NI32 X60Qx_425 = len_4_sysvq0asl(w_2);
      NI32 X60Qx_426 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_15 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_422 + X60Qx_423)) + X60Qx_424)) + X60Qx_425)) + X60Qx_426)));
      add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_15), dst_0);
      add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_15), w_2);
      add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_39), X60Qdesugar_15);
      NI32 X60Qx_427 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
      );
      NI32 X60Qx_428 = len_4_sysvq0asl(w_2);
      NI32 X60Qx_429 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_16 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_427 + X60Qx_428)) + X60Qx_429)));
      add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_16), w_2);
      add_2_sysvq0asl((&X60Qdesugar_16), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_39), X60Qdesugar_16);
      nimStrDestroy(X60Qdesugar_16);
      nimStrDestroy(X60Qdesugar_15);
      nimStrDestroy(w_2);}
    break;
    case 14:
    {
      NI32 X60Qx_430 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
      );
      NI32 X60Qx_431 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_432 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_17 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_430 + X60Qx_431)) + X60Qx_432)));
      add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_17), k_1);
      add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_39), X60Qdesugar_17);
      NI32 X60Qx_433 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
      );
      NI32 X60Qx_434 = len_4_sysvq0asl(longT_1);
      NI32 X60Qx_435 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1864379134u, .more_0 = (&strlit_0_I9396282401636018722_aow7lb5cq1)}
      );
      NI32 X60Qx_436 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_437 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_18 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_433 + X60Qx_434)) + X60Qx_435)) + X60Qx_436)) + X60Qx_437)));
      add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_18), longT_1);
      add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
        .bytes_0 = 1864379134u, .more_0 = (&strlit_0_I9396282401636018722_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_18), k_1);
      add_2_sysvq0asl((&X60Qdesugar_18), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_39), X60Qdesugar_18);
      NI32 X60Qx_438 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
      );
      NI32 X60Qx_439 = len_4_sysvq0asl(dst_0);
      NI32 X60Qx_440 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I459476928402638487_aow7lb5cq1)}
      );
      NI32 X60Qx_441 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_442 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1259136645670664990_aow7lb5cq1)}
      );
      NI32 X60Qx_443 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_444 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_19 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_438 + X60Qx_439)) + X60Qx_440)) + X60Qx_441)) + X60Qx_442)) + X60Qx_443)) + X60Qx_444)));
      add_2_sysvq0asl((&X60Qdesugar_19), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_19), dst_0);
      add_2_sysvq0asl((&X60Qdesugar_19), (string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I459476928402638487_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_19), k_1);
      add_2_sysvq0asl((&X60Qdesugar_19), (string_0_sysvq0asl){
        .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1259136645670664990_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_19), k_1);
      add_2_sysvq0asl((&X60Qdesugar_19), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_39), X60Qdesugar_19);
      NI32 X60Qx_445 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I14393988487556796913_aow7lb5cq1)}
      );
      NI32 X60Qx_446 = len_4_sysvq0asl(k_1);
      NI32 X60Qx_447 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_20 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_445 + X60Qx_446)) + X60Qx_447)));
      add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I14393988487556796913_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_20), k_1);
      add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
        .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_39), X60Qdesugar_20);
      nimStrDestroy(X60Qdesugar_20);
      nimStrDestroy(X60Qdesugar_19);
      nimStrDestroy(X60Qdesugar_18);
      nimStrDestroy(X60Qdesugar_17);}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_2 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_5).d_00.elem_0);
      if (el_2 == NIM_NIL){
        (*ok_0) = NIM_FALSE;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_2);
        nimStrDestroy(k_1);
        return result_39;}
      if ((*el_2).d_00.kind_0 == 14){
        NI32 X60Qx_448 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        NI32 X60Qx_449 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_450 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_21 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_448 + X60Qx_449)) + X60Qx_450)));
        add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_21), k_1);
        add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_21);
        add_2_sysvq0asl((&result_39), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I782490999618302521_aow7lb5cq1)}
        );
        NI32 X60Qx_451 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
        );
        NI32 X60Qx_452 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_453 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
        );
        NI32 X60Qx_454 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_455 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_22 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_451 + X60Qx_452)) + X60Qx_453)) + X60Qx_454)) + X60Qx_455)));
        add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_22), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
          .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_22), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_22), (string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_22);
        NI32 X60Qx_456 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
        );
        NI32 X60Qx_457 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_458 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
        );
        NI32 X60Qx_459 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_460 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_23 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_456 + X60Qx_457)) + X60Qx_458)) + X60Qx_459)) + X60Qx_460)));
        add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_23), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_23), k_1);
        add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_23);
        NI32 X60Qx_461 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
        );
        NI32 X60Qx_462 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_463 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540942590u, .more_0 = (&strlit_0_I13666278637935594890_aow7lb5cq1)}
        );
        NI32 X60Qx_464 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_465 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
        );
        NI32 X60Qx_466 = len_4_sysvq0asl(allocFn_0);
        NI32 X60Qx_467 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
        );
        NI32 X60Qx_468 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_469 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 539631870u, .more_0 = (&strlit_0_I696246876201023085_aow7lb5cq1)}
        );
        NI32 X60Qx_470 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_471 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6286326072955259077_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_24 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_461 + X60Qx_462)) + X60Qx_463)) + X60Qx_464)) + X60Qx_465)) + X60Qx_466)) + X60Qx_467)) + X60Qx_468)) + X60Qx_469)) + X60Qx_470)) + X60Qx_471)));
        add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_24), k_1);
        add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
          .bytes_0 = 540942590u, .more_0 = (&strlit_0_I13666278637935594890_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_24), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_24), allocFn_0);
        add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
          .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_24), k_1);
        add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
          .bytes_0 = 539631870u, .more_0 = (&strlit_0_I696246876201023085_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_24), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_24), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6286326072955259077_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_24);
        NI32 X60Qx_472 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        NI32 X60Qx_473 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_474 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_25 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_472 + X60Qx_473)) + X60Qx_474)));
        add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_25), k_1);
        add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_25);
        NI32 X60Qx_475 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        NI32 X60Qx_476 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_477 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        NI32 X60Qx_478 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_479 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        NI32 X60Qx_480 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_481 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_26 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_475 + X60Qx_476)) + X60Qx_477)) + X60Qx_478)) + X60Qx_479)) + X60Qx_480)) + X60Qx_481)));
        add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_26), k_1);
        add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_26), k_1);
        add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_26), k_1);
        add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_26);
        NI32 X60Qx_482 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5809312286091816554_aow7lb5cq1)}
        );
        NI32 X60Qx_483 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_484 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_27 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_482 + X60Qx_483)) + X60Qx_484)));
        add_2_sysvq0asl((&X60Qdesugar_27), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5809312286091816554_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_27), k_1);
        add_2_sysvq0asl((&X60Qdesugar_27), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_27);
        NI32 X60Qx_485 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5288086118845442921_aow7lb5cq1)}
        );
        NI32 X60Qx_486 = len_4_sysvq0asl(longT_1);
        NI32 X60Qx_487 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1864378883u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_488 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_489 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_28 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_485 + X60Qx_486)) + X60Qx_487)) + X60Qx_488)) + X60Qx_489)));
        add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5288086118845442921_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_28), longT_1);
        add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
          .bytes_0 = 1864378883u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_28), k_1);
        add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_28);
        NI32 X60Qx_490 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5288086118845442921_aow7lb5cq1)}
        );
        NI32 X60Qx_491 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_492 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        NI32 X60Qx_493 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_494 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1025531390u, .more_0 = (&strlit_0_I15437739651001969444_aow7lb5cq1)}
        );
        NI32 X60Qx_495 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_496 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1161825924217342649_aow7lb5cq1)}
        );
        NI32 X60Qx_497 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_498 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_29 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_490 + X60Qx_491)) + X60Qx_492)) + X60Qx_493)) + X60Qx_494)) + X60Qx_495)) + X60Qx_496)) + X60Qx_497)) + X60Qx_498)));
        add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5288086118845442921_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_29), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_29), k_1);
        add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
          .bytes_0 = 1025531390u, .more_0 = (&strlit_0_I15437739651001969444_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_29), k_1);
        add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
          .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1161825924217342649_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_29), k_1);
        add_2_sysvq0asl((&X60Qdesugar_29), (string_0_sysvq0asl){
          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_29);
        NI32 X60Qx_499 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2640784052786307265_aow7lb5cq1)}
        );
        NI32 X60Qx_500 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_501 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_30 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_499 + X60Qx_500)) + X60Qx_501)));
        add_2_sysvq0asl((&X60Qdesugar_30), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2640784052786307265_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_30), k_1);
        add_2_sysvq0asl((&X60Qdesugar_30), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_30);
        add_2_sysvq0asl((&result_39), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I7306224084071035336_aow7lb5cq1)}
        );
        NI32 X60Qx_502 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        NI32 X60Qx_503 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_504 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        NI32 X60Qx_505 = len_4_sysvq0asl(deallocFn_0);
        NI32 X60Qx_506 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        NI32 X60Qx_507 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_508 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_31 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_502 + X60Qx_503)) + X60Qx_504)) + X60Qx_505)) + X60Qx_506)) + X60Qx_507)) + X60Qx_508)));
        add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_31), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_31), deallocFn_0);
        add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_31), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        add_2_sysvq0asl(owned_0, X60Qdesugar_31);
        nimStrDestroy(X60Qdesugar_31);
        nimStrDestroy(X60Qdesugar_30);
        nimStrDestroy(X60Qdesugar_29);
        nimStrDestroy(X60Qdesugar_28);
        nimStrDestroy(X60Qdesugar_27);
        nimStrDestroy(X60Qdesugar_26);
        nimStrDestroy(X60Qdesugar_25);
        nimStrDestroy(X60Qdesugar_24);
        nimStrDestroy(X60Qdesugar_23);
        nimStrDestroy(X60Qdesugar_22);
        nimStrDestroy(X60Qdesugar_21);}
      else {
        NI32 X60Qx_509 = scalarWidth_0_aow7lb5cq1(el_2);
        string_0_sysvq0asl w_3 = dollarQ_2_sysvq0asl(X60Qx_509);
        NI32 X60Qx_510 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        NI32 X60Qx_511 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_512 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_32 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_510 + X60Qx_511)) + X60Qx_512)));
        add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_32), k_1);
        add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_32);
        NI32 X60Qx_513 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16570386306475740535_aow7lb5cq1)}
        );
        NI32 X60Qx_514 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_515 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
        );
        NI32 X60Qx_516 = len_4_sysvq0asl(w_3);
        NI32 X60Qx_517 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_33 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_513 + X60Qx_514)) + X60Qx_515)) + X60Qx_516)) + X60Qx_517)));
        add_2_sysvq0asl((&X60Qdesugar_33), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16570386306475740535_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_33), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_33), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_33), w_3);
        add_2_sysvq0asl((&X60Qdesugar_33), (string_0_sysvq0asl){
          .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_33);
        NI32 X60Qx_518 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
        );
        NI32 X60Qx_519 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_520 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
        );
        NI32 X60Qx_521 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_522 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_34 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_518 + X60Qx_519)) + X60Qx_520)) + X60Qx_521)) + X60Qx_522)));
        add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5104109714558201510_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_34), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
          .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_34), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_34), (string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_34);
        NI32 X60Qx_523 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
        );
        NI32 X60Qx_524 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_525 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
        );
        NI32 X60Qx_526 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_527 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_35 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_523 + X60Qx_524)) + X60Qx_525)) + X60Qx_526)) + X60Qx_527)));
        add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_35), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_35), k_1);
        add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_35);
        NI32 X60Qx_528 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
        );
        NI32 X60Qx_529 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_530 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_36 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_528 + X60Qx_529)) + X60Qx_530)));
        add_2_sysvq0asl((&X60Qdesugar_36), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_36), k_1);
        add_2_sysvq0asl((&X60Qdesugar_36), (string_0_sysvq0asl){
          .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_36);
        NI32 X60Qx_531 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
        );
        NI32 X60Qx_532 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_533 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
        );
        NI32 X60Qx_534 = len_4_sysvq0asl(allocFn_0);
        NI32 X60Qx_535 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
        );
        NI32 X60Qx_536 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_537 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_538 = len_4_sysvq0asl(w_3);
        NI32 X60Qx_539 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_37 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_531 + X60Qx_532)) + X60Qx_533)) + X60Qx_534)) + X60Qx_535)) + X60Qx_536)) + X60Qx_537)) + X60Qx_538)) + X60Qx_539)));
        add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2130325736493385980_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_37), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_37), allocFn_0);
        add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
          .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_37), k_1);
        add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_37), w_3);
        add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_37);
        NI32 X60Qx_540 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12628527270567457706_aow7lb5cq1)}
        );
        NI32 X60Qx_541 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_542 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I14428153832606577816_aow7lb5cq1)}
        );
        NI32 X60Qx_543 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_544 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_545 = len_4_sysvq0asl(w_3);
        NI32 X60Qx_546 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_38 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_540 + X60Qx_541)) + X60Qx_542)) + X60Qx_543)) + X60Qx_544)) + X60Qx_545)) + X60Qx_546)));
        add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12628527270567457706_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_38), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I14428153832606577816_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_38), k_1);
        add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_38), w_3);
        add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_38);
        add_2_sysvq0asl((&result_39), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I13453311567032255224_aow7lb5cq1)}
        );
        NI32 X60Qx_547 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I14393988487556796913_aow7lb5cq1)}
        );
        NI32 X60Qx_548 = len_4_sysvq0asl(k_1);
        NI32 X60Qx_549 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_550 = len_4_sysvq0asl(w_3);
        NI32 X60Qx_551 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_39 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_547 + X60Qx_548)) + X60Qx_549)) + X60Qx_550)) + X60Qx_551)));
        add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I14393988487556796913_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_39), k_1);
        add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_39), w_3);
        add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
          .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_39), X60Qdesugar_39);
        NI32 X60Qx_552 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        NI32 X60Qx_553 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_554 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        NI32 X60Qx_555 = len_4_sysvq0asl(deallocFn_0);
        NI32 X60Qx_556 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        NI32 X60Qx_557 = len_4_sysvq0asl(dst_0);
        NI32 X60Qx_558 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_40 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_552 + X60Qx_553)) + X60Qx_554)) + X60Qx_555)) + X60Qx_556)) + X60Qx_557)) + X60Qx_558)));
        add_2_sysvq0asl((&X60Qdesugar_40), (string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_40), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_40), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_40), deallocFn_0);
        add_2_sysvq0asl((&X60Qdesugar_40), (string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_40), dst_0);
        add_2_sysvq0asl((&X60Qdesugar_40), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        add_2_sysvq0asl(owned_0, X60Qdesugar_40);
        nimStrDestroy(X60Qdesugar_40);
        nimStrDestroy(X60Qdesugar_39);
        nimStrDestroy(X60Qdesugar_38);
        nimStrDestroy(X60Qdesugar_37);
        nimStrDestroy(X60Qdesugar_36);
        nimStrDestroy(X60Qdesugar_35);
        nimStrDestroy(X60Qdesugar_34);
        nimStrDestroy(X60Qdesugar_33);
        nimStrDestroy(X60Qdesugar_32);
        nimStrDestroy(w_3);}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_2);}
    break;
    case 10:
    case 11:
    {
      seq_0_Irn2j6w_aow7lb5cq1 flds_0 = structFields_0_aow7lb5cq1(unit_0, cty_0);
      if ((!(flds_0.len_0 == (*td_5).d_00.fields_0.len_0))){
        (*ok_0) = NIM_FALSE;
        eQdestroy_1_Iem8q971_aow7lb5cq1(flds_0);
        nimStrDestroy(k_1);
        return result_39;}
      NI32 i_15 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_559 = len_3_I5m68tr1_aow7lb5cq1((*td_5).d_00.fields_0);
          if (i_15 < X60Qx_559){
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_560 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_0, i_15);
            string_0_sysvq0asl X60Qdesugar_41 = nimStrDup((*X60Qx_560).fld_1);
            NI32 X60Qx_561 = len_4_sysvq0asl(dst_0);
            NI32 X60Qx_562 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_563 = len_4_sysvq0asl(X60Qdesugar_41);
            string_0_sysvq0asl X60Qdesugar_42 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_561 + X60Qx_562)) + X60Qx_563)));
            add_2_sysvq0asl((&X60Qdesugar_42), dst_0);
            add_2_sysvq0asl((&X60Qdesugar_42), (string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_42), X60Qdesugar_41);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_564 = getQ_7_I45w7c91_aow7lb5cq1((*td_5).d_00.fields_0, i_15);
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_565 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_0, i_15);
            string_0_sysvq0asl X60Qtmp_29 = emitCompositeIn_0_aow7lb5cq1((*X60Qx_564), unit_0, (*X60Qx_565).fld_0, X60Qdesugar_42, strT_1, longT_1, allocFn_0, deallocFn_0, tmp_0, owned_0, ok_0);
            add_2_sysvq0asl((&result_39), X60Qtmp_29);
            if ((!(*ok_0))){
              nimStrDestroy(X60Qtmp_29);
              nimStrDestroy(X60Qdesugar_42);
              nimStrDestroy(X60Qdesugar_41);
              eQdestroy_1_Iem8q971_aow7lb5cq1(flds_0);
              nimStrDestroy(k_1);
              return result_39;}
            inc_1_I6wjjge_aow2h993l1((&i_15));
            nimStrDestroy(X60Qtmp_29);
            nimStrDestroy(X60Qdesugar_42);
            nimStrDestroy(X60Qdesugar_41);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      eQdestroy_1_Iem8q971_aow7lb5cq1(flds_0);}
    break;
    default:
    {
      (*ok_0) = NIM_FALSE;}
    break;}
  nimStrDestroy(k_1);
  return result_39;
  nimStrDestroy(k_1);
  return result_39;}
string_0_sysvq0asl emitCompositeOut_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_6, string_0_sysvq0asl unit_1, string_0_sysvq0asl cty_1, string_0_sysvq0asl src_7, string_0_sysvq0asl deallocFn_1, NI32* tmp_1, string_0_sysvq0asl* freeing_0, NB8* ok_1){
  string_0_sysvq0asl result_40;
  nimStrWasMoved((&result_40));
  nimStrDestroy(result_40);
  result_40 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((!(*ok_1))){
    return result_40;}
  inc_1_I6wjjge_aow2h993l1(tmp_1);
  string_0_sysvq0asl k_2 = dollarQ_2_sysvq0asl((*tmp_1));
  switch ((*td_6).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      NI32 X60Qx_566 = scalarWidth_0_aow7lb5cq1(td_6);
      string_0_sysvq0asl w_4 = dollarQ_2_sysvq0asl(X60Qx_566);
      NI32 X60Qx_567 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I12852333444401487702_aow7lb5cq1)}
      );
      NI32 X60Qx_568 = len_4_sysvq0asl(src_7);
      NI32 X60Qx_569 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2108418u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_570 = len_4_sysvq0asl(w_4);
      NI32 X60Qx_571 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I10044955599202107917_aow7lb5cq1)}
      );
      NI32 X60Qx_572 = len_4_sysvq0asl(w_4);
      NI32 X60Qx_573 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_43 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_567 + X60Qx_568)) + X60Qx_569)) + X60Qx_570)) + X60Qx_571)) + X60Qx_572)) + X60Qx_573)));
      add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I12852333444401487702_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_43), src_7);
      add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
        .bytes_0 = 2108418u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_43), w_4);
      add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I10044955599202107917_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_43), w_4);
      add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_40), X60Qdesugar_43);
      nimStrDestroy(X60Qdesugar_43);
      nimStrDestroy(w_4);}
    break;
    case 14:
    {
      NI32 X60Qx_574 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
      );
      NI32 X60Qx_575 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_576 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
      );
      NI32 X60Qx_577 = len_4_sysvq0asl(src_7);
      NI32 X60Qx_578 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_44 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_574 + X60Qx_575)) + X60Qx_576)) + X60Qx_577)) + X60Qx_578)));
      add_2_sysvq0asl((&X60Qdesugar_44), (string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_44), k_2);
      add_2_sysvq0asl((&X60Qdesugar_44), (string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_44), src_7);
      add_2_sysvq0asl((&X60Qdesugar_44), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_40), X60Qdesugar_44);
      NI32 X60Qx_579 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18035457312318603665_aow7lb5cq1)}
      );
      NI32 X60Qx_580 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_581 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
      );
      NI32 X60Qx_582 = len_4_sysvq0asl(src_7);
      NI32 X60Qx_583 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_45 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_579 + X60Qx_580)) + X60Qx_581)) + X60Qx_582)) + X60Qx_583)));
      add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18035457312318603665_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_45), k_2);
      add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_45), src_7);
      add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_40), X60Qdesugar_45);
      NI32 X60Qx_584 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
      );
      NI32 X60Qx_585 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_586 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_46 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_584 + X60Qx_585)) + X60Qx_586)));
      add_2_sysvq0asl((&X60Qdesugar_46), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_46), k_2);
      add_2_sysvq0asl((&X60Qdesugar_46), (string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_40), X60Qdesugar_46);
      NI32 X60Qx_587 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5713563946092690572_aow7lb5cq1)}
      );
      NI32 X60Qx_588 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_589 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 673197310u, .more_0 = (&strlit_0_I18233374301631325590_aow7lb5cq1)}
      );
      NI32 X60Qx_590 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_591 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I3705825639434928729_aow7lb5cq1)}
      );
      NI32 X60Qx_592 = len_4_sysvq0asl(k_2);
      NI32 X60Qx_593 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_47 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_587 + X60Qx_588)) + X60Qx_589)) + X60Qx_590)) + X60Qx_591)) + X60Qx_592)) + X60Qx_593)));
      add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5713563946092690572_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_47), k_2);
      add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
        .bytes_0 = 673197310u, .more_0 = (&strlit_0_I18233374301631325590_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_47), k_2);
      add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
        .bytes_0 = 540748286u, .more_0 = (&strlit_0_I3705825639434928729_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_47), k_2);
      add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
        .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_40), X60Qdesugar_47);
      nimStrDestroy(X60Qdesugar_47);
      nimStrDestroy(X60Qdesugar_46);
      nimStrDestroy(X60Qdesugar_45);
      nimStrDestroy(X60Qdesugar_44);}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_3 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_6).d_00.elem_0);
      if (el_3 == NIM_NIL){
        (*ok_1) = NIM_FALSE;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_3);
        nimStrDestroy(k_2);
        return result_40;}
      if ((*el_3).d_00.kind_0 == 14){
        NI32 X60Qx_594 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        NI32 X60Qx_595 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_596 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_597 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_598 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_48 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_594 + X60Qx_595)) + X60Qx_596)) + X60Qx_597)) + X60Qx_598)));
        add_2_sysvq0asl((&X60Qdesugar_48), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_48), k_2);
        add_2_sysvq0asl((&X60Qdesugar_48), (string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_48), src_7);
        add_2_sysvq0asl((&X60Qdesugar_48), (string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_48);
        NI32 X60Qx_599 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
        );
        NI32 X60Qx_600 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_601 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_49 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_599 + X60Qx_600)) + X60Qx_601)));
        add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_49), k_2);
        add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_49);
        NI32 X60Qx_602 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        NI32 X60Qx_603 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_604 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_50 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_602 + X60Qx_603)) + X60Qx_604)));
        add_2_sysvq0asl((&X60Qdesugar_50), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_50), k_2);
        add_2_sysvq0asl((&X60Qdesugar_50), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_50);
        NI32 X60Qx_605 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        NI32 X60Qx_606 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_607 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        NI32 X60Qx_608 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_609 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        NI32 X60Qx_610 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_611 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_51 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_605 + X60Qx_606)) + X60Qx_607)) + X60Qx_608)) + X60Qx_609)) + X60Qx_610)) + X60Qx_611)));
        add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_51), k_2);
        add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_51), k_2);
        add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_51), k_2);
        add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
          .bytes_0 = 2065705470u, .more_0 = (&strlit_0_I17846080716529448640_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_51);
        NI32 X60Qx_612 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5809312286091816554_aow7lb5cq1)}
        );
        NI32 X60Qx_613 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_614 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
        );
        NI32 X60Qx_615 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_616 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        NI32 X60Qx_617 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_618 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_52 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_612 + X60Qx_613)) + X60Qx_614)) + X60Qx_615)) + X60Qx_616)) + X60Qx_617)) + X60Qx_618)));
        add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5809312286091816554_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_52), k_2);
        add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I10389080895709581217_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_52), src_7);
        add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_52), k_2);
        add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_52);
        NI32 X60Qx_619 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12283458923584918919_aow7lb5cq1)}
        );
        NI32 X60Qx_620 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_621 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
        );
        NI32 X60Qx_622 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_623 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        NI32 X60Qx_624 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_625 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_53 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_619 + X60Qx_620)) + X60Qx_621)) + X60Qx_622)) + X60Qx_623)) + X60Qx_624)) + X60Qx_625)));
        add_2_sysvq0asl((&X60Qdesugar_53), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12283458923584918919_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_53), k_2);
        add_2_sysvq0asl((&X60Qdesugar_53), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I2252829356077611598_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_53), src_7);
        add_2_sysvq0asl((&X60Qdesugar_53), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_53), k_2);
        add_2_sysvq0asl((&X60Qdesugar_53), (string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_53);
        NI32 X60Qx_626 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4141503729763329410_aow7lb5cq1)}
        );
        NI32 X60Qx_627 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_628 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_54 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_626 + X60Qx_627)) + X60Qx_628)));
        add_2_sysvq0asl((&X60Qdesugar_54), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4141503729763329410_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_54), k_2);
        add_2_sysvq0asl((&X60Qdesugar_54), (string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_54);
        NI32 X60Qx_629 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17936778126182439409_aow7lb5cq1)}
        );
        NI32 X60Qx_630 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_631 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 673197310u, .more_0 = (&strlit_0_I5572117052193497108_aow7lb5cq1)}
        );
        NI32 X60Qx_632 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_633 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I4896779559304927306_aow7lb5cq1)}
        );
        NI32 X60Qx_634 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_635 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_55 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_629 + X60Qx_630)) + X60Qx_631)) + X60Qx_632)) + X60Qx_633)) + X60Qx_634)) + X60Qx_635)));
        add_2_sysvq0asl((&X60Qdesugar_55), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17936778126182439409_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_55), k_2);
        add_2_sysvq0asl((&X60Qdesugar_55), (string_0_sysvq0asl){
          .bytes_0 = 673197310u, .more_0 = (&strlit_0_I5572117052193497108_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_55), k_2);
        add_2_sysvq0asl((&X60Qdesugar_55), (string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I4896779559304927306_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_55), k_2);
        add_2_sysvq0asl((&X60Qdesugar_55), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_55);
        add_2_sysvq0asl((&result_40), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I7306224084071035336_aow7lb5cq1)}
        );
        NI32 X60Qx_636 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        NI32 X60Qx_637 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_638 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        NI32 X60Qx_639 = len_4_sysvq0asl(deallocFn_1);
        NI32 X60Qx_640 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        NI32 X60Qx_641 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_642 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_56 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_636 + X60Qx_637)) + X60Qx_638)) + X60Qx_639)) + X60Qx_640)) + X60Qx_641)) + X60Qx_642)));
        add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_56), src_7);
        add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_56), deallocFn_1);
        add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_56), src_7);
        add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        add_2_sysvq0asl(freeing_0, X60Qdesugar_56);
        nimStrDestroy(X60Qdesugar_56);
        nimStrDestroy(X60Qdesugar_55);
        nimStrDestroy(X60Qdesugar_54);
        nimStrDestroy(X60Qdesugar_53);
        nimStrDestroy(X60Qdesugar_52);
        nimStrDestroy(X60Qdesugar_51);
        nimStrDestroy(X60Qdesugar_50);
        nimStrDestroy(X60Qdesugar_49);
        nimStrDestroy(X60Qdesugar_48);}
      else {
        NI32 X60Qx_643 = scalarWidth_0_aow7lb5cq1(el_3);
        string_0_sysvq0asl w_5 = dollarQ_2_sysvq0asl(X60Qx_643);
        NI32 X60Qx_644 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        NI32 X60Qx_645 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_646 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_647 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_648 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_57 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_644 + X60Qx_645)) + X60Qx_646)) + X60Qx_647)) + X60Qx_648)));
        add_2_sysvq0asl((&X60Qdesugar_57), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_57), k_2);
        add_2_sysvq0asl((&X60Qdesugar_57), (string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_57), src_7);
        add_2_sysvq0asl((&X60Qdesugar_57), (string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I7627703610005382710_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_57);
        NI32 X60Qx_649 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16570386306475740535_aow7lb5cq1)}
        );
        NI32 X60Qx_650 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_651 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
        );
        NI32 X60Qx_652 = len_4_sysvq0asl(w_5);
        NI32 X60Qx_653 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_58 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_649 + X60Qx_650)) + X60Qx_651)) + X60Qx_652)) + X60Qx_653)));
        add_2_sysvq0asl((&X60Qdesugar_58), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16570386306475740535_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_58), src_7);
        add_2_sysvq0asl((&X60Qdesugar_58), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_58), w_5);
        add_2_sysvq0asl((&X60Qdesugar_58), (string_0_sysvq0asl){
          .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_58);
        NI32 X60Qx_654 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
        );
        NI32 X60Qx_655 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_656 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_59 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_654 + X60Qx_655)) + X60Qx_656)));
        add_2_sysvq0asl((&X60Qdesugar_59), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I592807425861797845_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_59), k_2);
        add_2_sysvq0asl((&X60Qdesugar_59), (string_0_sysvq0asl){
          .bytes_0 = 540748286u, .more_0 = (&strlit_0_I18148928282892619203_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_59);
        NI32 X60Qx_657 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
        );
        NI32 X60Qx_658 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_659 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540942590u, .more_0 = (&strlit_0_I16820758988003013266_aow7lb5cq1)}
        );
        NI32 X60Qx_660 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_661 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I8608436586241119281_aow7lb5cq1)}
        );
        NI32 X60Qx_662 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_663 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_664 = len_4_sysvq0asl(w_5);
        NI32 X60Qx_665 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_60 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_657 + X60Qx_658)) + X60Qx_659)) + X60Qx_660)) + X60Qx_661)) + X60Qx_662)) + X60Qx_663)) + X60Qx_664)) + X60Qx_665)));
        add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I2789430258783990977_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_60), k_2);
        add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
          .bytes_0 = 540942590u, .more_0 = (&strlit_0_I16820758988003013266_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_60), src_7);
        add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I8608436586241119281_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_60), k_2);
        add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_60), w_5);
        add_2_sysvq0asl((&X60Qdesugar_60), (string_0_sysvq0asl){
          .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_60);
        NI32 X60Qx_666 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5027967502149894354_aow7lb5cq1)}
        );
        NI32 X60Qx_667 = len_4_sysvq0asl(k_2);
        NI32 X60Qx_668 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_669 = len_4_sysvq0asl(w_5);
        NI32 X60Qx_670 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_61 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_666 + X60Qx_667)) + X60Qx_668)) + X60Qx_669)) + X60Qx_670)));
        add_2_sysvq0asl((&X60Qdesugar_61), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5027967502149894354_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_61), k_2);
        add_2_sysvq0asl((&X60Qdesugar_61), (string_0_sysvq0asl){
          .bytes_0 = 539631619u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_61), w_5);
        add_2_sysvq0asl((&X60Qdesugar_61), (string_0_sysvq0asl){
          .bytes_0 = 2099264510u, .more_0 = (&strlit_0_I15334082442820835739_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_40), X60Qdesugar_61);
        NI32 X60Qx_671 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        NI32 X60Qx_672 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_673 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        NI32 X60Qx_674 = len_4_sysvq0asl(deallocFn_1);
        NI32 X60Qx_675 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        NI32 X60Qx_676 = len_4_sysvq0asl(src_7);
        NI32 X60Qx_677 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_62 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_671 + X60Qx_672)) + X60Qx_673)) + X60Qx_674)) + X60Qx_675)) + X60Qx_676)) + X60Qx_677)));
        add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
          .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_62), src_7);
        add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_62), deallocFn_1);
        add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
          .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_62), src_7);
        add_2_sysvq0asl((&X60Qdesugar_62), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
        );
        add_2_sysvq0asl(freeing_0, X60Qdesugar_62);
        nimStrDestroy(X60Qdesugar_62);
        nimStrDestroy(X60Qdesugar_61);
        nimStrDestroy(X60Qdesugar_60);
        nimStrDestroy(X60Qdesugar_59);
        nimStrDestroy(X60Qdesugar_58);
        nimStrDestroy(X60Qdesugar_57);
        nimStrDestroy(w_5);}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_3);}
    break;
    case 10:
    case 11:
    {
      seq_0_Irn2j6w_aow7lb5cq1 flds_1 = structFields_0_aow7lb5cq1(unit_1, cty_1);
      if ((!(flds_1.len_0 == (*td_6).d_00.fields_0.len_0))){
        (*ok_1) = NIM_FALSE;
        eQdestroy_1_Iem8q971_aow7lb5cq1(flds_1);
        nimStrDestroy(k_2);
        return result_40;}
      NI32 i_17 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_678 = len_3_I5m68tr1_aow7lb5cq1((*td_6).d_00.fields_0);
          if (i_17 < X60Qx_678){
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_679 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_1, i_17);
            string_0_sysvq0asl X60Qdesugar_63 = nimStrDup((*X60Qx_679).fld_1);
            NI32 X60Qx_680 = len_4_sysvq0asl(src_7);
            NI32 X60Qx_681 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_682 = len_4_sysvq0asl(X60Qdesugar_63);
            string_0_sysvq0asl X60Qdesugar_64 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_680 + X60Qx_681)) + X60Qx_682)));
            add_2_sysvq0asl((&X60Qdesugar_64), src_7);
            add_2_sysvq0asl((&X60Qdesugar_64), (string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_64), X60Qdesugar_63);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_683 = getQ_7_I45w7c91_aow7lb5cq1((*td_6).d_00.fields_0, i_17);
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_684 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_1, i_17);
            string_0_sysvq0asl X60Qtmp_30 = emitCompositeOut_0_aow7lb5cq1((*X60Qx_683), unit_1, (*X60Qx_684).fld_0, X60Qdesugar_64, deallocFn_1, tmp_1, freeing_0, ok_1);
            add_2_sysvq0asl((&result_40), X60Qtmp_30);
            if ((!(*ok_1))){
              nimStrDestroy(X60Qtmp_30);
              nimStrDestroy(X60Qdesugar_64);
              nimStrDestroy(X60Qdesugar_63);
              eQdestroy_1_Iem8q971_aow7lb5cq1(flds_1);
              nimStrDestroy(k_2);
              return result_40;}
            inc_1_I6wjjge_aow2h993l1((&i_17));
            nimStrDestroy(X60Qtmp_30);
            nimStrDestroy(X60Qdesugar_64);
            nimStrDestroy(X60Qdesugar_63);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      eQdestroy_1_Iem8q971_aow7lb5cq1(flds_1);}
    break;
    default:
    {
      (*ok_1) = NIM_FALSE;}
    break;}
  nimStrDestroy(k_2);
  return result_40;
  nimStrDestroy(k_2);
  return result_40;}
string_0_sysvq0asl emitCompositeSize_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_7, string_0_sysvq0asl unit_2, string_0_sysvq0asl cty_2, string_0_sysvq0asl src_8, NI32* tmp_2, NB8* ok_2){
  string_0_sysvq0asl result_41;
  nimStrWasMoved((&result_41));
  nimStrDestroy(result_41);
  result_41 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if ((!(*ok_2))){
    return result_41;}
  inc_1_I6wjjge_aow2h993l1(tmp_2);
  string_0_sysvq0asl k_3 = dollarQ_2_sysvq0asl((*tmp_2));
  switch ((*td_7).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    {
      NI32 X60Qx_685 = scalarWidth_0_aow7lb5cq1(td_7);
      string_0_sysvq0asl X60Qdesugar_65 = dollarQ_2_sysvq0asl(X60Qx_685);
      NI32 X60Qx_686 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I6738090623860882514_aow7lb5cq1)}
      );
      NI32 X60Qx_687 = len_4_sysvq0asl(X60Qdesugar_65);
      NI32 X60Qx_688 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_66 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_686 + X60Qx_687)) + X60Qx_688)));
      add_2_sysvq0asl((&X60Qdesugar_66), (string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I6738090623860882514_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_66), X60Qdesugar_65);
      add_2_sysvq0asl((&X60Qdesugar_66), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_41), X60Qdesugar_66);
      nimStrDestroy(X60Qdesugar_66);
      nimStrDestroy(X60Qdesugar_65);}
    break;
    case 14:
    {
      NI32 X60Qx_689 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I17529382521941393548_aow7lb5cq1)}
      );
      NI32 X60Qx_690 = len_4_sysvq0asl(src_8);
      NI32 X60Qx_691 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_67 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_689 + X60Qx_690)) + X60Qx_691)));
      add_2_sysvq0asl((&X60Qdesugar_67), (string_0_sysvq0asl){
        .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I17529382521941393548_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_67), src_8);
      add_2_sysvq0asl((&X60Qdesugar_67), (string_0_sysvq0asl){
        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_41), X60Qdesugar_67);
      nimStrDestroy(X60Qdesugar_67);}
    break;
    case 15:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_4 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1((*td_7).d_00.elem_0);
      if (el_4 == NIM_NIL){
        (*ok_2) = NIM_FALSE;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_4);
        nimStrDestroy(k_3);
        return result_41;}
      if ((*el_4).d_00.kind_0 == 14){
        NI32 X60Qx_692 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        NI32 X60Qx_693 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_694 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_695 = len_4_sysvq0asl(src_8);
        NI32 X60Qx_696 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I15937128883579799196_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_68 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_692 + X60Qx_693)) + X60Qx_694)) + X60Qx_695)) + X60Qx_696)));
        add_2_sysvq0asl((&X60Qdesugar_68), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I13870529507240259253_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_68), k_3);
        add_2_sysvq0asl((&X60Qdesugar_68), (string_0_sysvq0asl){
          .bytes_0 = 540876803u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_68), src_8);
        add_2_sysvq0asl((&X60Qdesugar_68), (string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I15937128883579799196_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_41), X60Qdesugar_68);
        NI32 X60Qx_697 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        NI32 X60Qx_698 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_699 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_69 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_697 + X60Qx_698)) + X60Qx_699)));
        add_2_sysvq0asl((&X60Qdesugar_69), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18385251057949070634_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_69), k_3);
        add_2_sysvq0asl((&X60Qdesugar_69), (string_0_sysvq0asl){
          .bytes_0 = 540877054u, .more_0 = (&strlit_0_I1258558027167527550_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_41), X60Qdesugar_69);
        NI32 X60Qx_700 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        NI32 X60Qx_701 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_702 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        NI32 X60Qx_703 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_704 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        NI32 X60Qx_705 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_706 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 665858u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_70 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_700 + X60Qx_701)) + X60Qx_702)) + X60Qx_703)) + X60Qx_704)) + X60Qx_705)) + X60Qx_706)));
        add_2_sysvq0asl((&X60Qdesugar_70), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17852924351155597464_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_70), k_3);
        add_2_sysvq0asl((&X60Qdesugar_70), (string_0_sysvq0asl){
          .bytes_0 = 540811518u, .more_0 = (&strlit_0_I11739835173426611508_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_70), k_3);
        add_2_sysvq0asl((&X60Qdesugar_70), (string_0_sysvq0asl){
          .bytes_0 = 723532798u, .more_0 = (&strlit_0_I5544640060524604054_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_70), k_3);
        add_2_sysvq0asl((&X60Qdesugar_70), (string_0_sysvq0asl){
          .bytes_0 = 665858u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_41), X60Qdesugar_70);
        NI32 X60Qx_707 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I8021182774357012906_aow7lb5cq1)}
        );
        NI32 X60Qx_708 = len_4_sysvq0asl(src_8);
        NI32 X60Qx_709 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        NI32 X60Qx_710 = len_4_sysvq0asl(k_3);
        NI32 X60Qx_711 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        string_0_sysvq0asl X60Qdesugar_71 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_707 + X60Qx_708)) + X60Qx_709)) + X60Qx_710)) + X60Qx_711)));
        add_2_sysvq0asl((&X60Qdesugar_71), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I8021182774357012906_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_71), src_8);
        add_2_sysvq0asl((&X60Qdesugar_71), (string_0_sysvq0asl){
          .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I10208913608960500894_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_71), k_3);
        add_2_sysvq0asl((&X60Qdesugar_71), (string_0_sysvq0asl){
          .bytes_0 = 992566782u, .more_0 = (&strlit_0_I6955924969188267900_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_41), X60Qdesugar_71);
        add_2_sysvq0asl((&result_41), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15342668115246402447_aow7lb5cq1)}
        );
        nimStrDestroy(X60Qdesugar_71);
        nimStrDestroy(X60Qdesugar_70);
        nimStrDestroy(X60Qdesugar_69);
        nimStrDestroy(X60Qdesugar_68);}
      else {
        NI32 X60Qx_712 = scalarWidth_0_aow7lb5cq1(el_4);
        string_0_sysvq0asl X60Qdesugar_72 = dollarQ_2_sysvq0asl(X60Qx_712);
        NI32 X60Qx_713 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I10813034127713670746_aow7lb5cq1)}
        );
        NI32 X60Qx_714 = len_4_sysvq0asl(src_8);
        NI32 X60Qx_715 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I17741661924343507191_aow7lb5cq1)}
        );
        NI32 X60Qx_716 = len_4_sysvq0asl(X60Qdesugar_72);
        NI32 X60Qx_717 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_73 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_713 + X60Qx_714)) + X60Qx_715)) + X60Qx_716)) + X60Qx_717)));
        add_2_sysvq0asl((&X60Qdesugar_73), (string_0_sysvq0asl){
          .bytes_0 = 1864376574u, .more_0 = (&strlit_0_I10813034127713670746_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_73), src_8);
        add_2_sysvq0asl((&X60Qdesugar_73), (string_0_sysvq0asl){
          .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I17741661924343507191_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_73), X60Qdesugar_72);
        add_2_sysvq0asl((&X60Qdesugar_73), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_41), X60Qdesugar_73);
        nimStrDestroy(X60Qdesugar_73);
        nimStrDestroy(X60Qdesugar_72);}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(el_4);}
    break;
    case 10:
    case 11:
    {
      seq_0_Irn2j6w_aow7lb5cq1 flds_2 = structFields_0_aow7lb5cq1(unit_2, cty_2);
      if ((!(flds_2.len_0 == (*td_7).d_00.fields_0.len_0))){
        (*ok_2) = NIM_FALSE;
        eQdestroy_1_Iem8q971_aow7lb5cq1(flds_2);
        nimStrDestroy(k_3);
        return result_41;}
      NI32 i_18 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_718 = len_3_I5m68tr1_aow7lb5cq1((*td_7).d_00.fields_0);
          if (i_18 < X60Qx_718){
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_719 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_2, i_18);
            string_0_sysvq0asl X60Qdesugar_74 = nimStrDup((*X60Qx_719).fld_1);
            NI32 X60Qx_720 = len_4_sysvq0asl(src_8);
            NI32 X60Qx_721 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_722 = len_4_sysvq0asl(X60Qdesugar_74);
            string_0_sysvq0asl X60Qdesugar_75 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_720 + X60Qx_721)) + X60Qx_722)));
            add_2_sysvq0asl((&X60Qdesugar_75), src_8);
            add_2_sysvq0asl((&X60Qdesugar_75), (string_0_sysvq0asl){
              .bytes_0 = 11777u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_75), X60Qdesugar_74);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_723 = getQ_7_I45w7c91_aow7lb5cq1((*td_7).d_00.fields_0, i_18);
            X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* X60Qx_724 = getQ_7_Irlfbqs1_aow7lb5cq1(flds_2, i_18);
            string_0_sysvq0asl X60Qtmp_31 = emitCompositeSize_0_aow7lb5cq1((*X60Qx_723), unit_2, (*X60Qx_724).fld_0, X60Qdesugar_75, tmp_2, ok_2);
            add_2_sysvq0asl((&result_41), X60Qtmp_31);
            if ((!(*ok_2))){
              nimStrDestroy(X60Qtmp_31);
              nimStrDestroy(X60Qdesugar_75);
              nimStrDestroy(X60Qdesugar_74);
              eQdestroy_1_Iem8q971_aow7lb5cq1(flds_2);
              nimStrDestroy(k_3);
              return result_41;}
            inc_1_I6wjjge_aow2h993l1((&i_18));
            nimStrDestroy(X60Qtmp_31);
            nimStrDestroy(X60Qdesugar_75);
            nimStrDestroy(X60Qdesugar_74);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      eQdestroy_1_Iem8q971_aow7lb5cq1(flds_2);}
    break;
    default:
    {
      (*ok_2) = NIM_FALSE;}
    break;}
  nimStrDestroy(k_3);
  return result_41;
  nimStrDestroy(k_3);
  return result_41;}
string_0_sysvq0asl emitCShim_0_aow7lb5cq1(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_4, string_0_sysvq0asl mangled_1, string_0_sysvq0asl strT_2, string_0_sysvq0asl longT_2, string_0_sysvq0asl allocFn_1, string_0_sysvq0asl deallocFn_2, CSig_0_aow7lb5cq1 sig_0, string_0_sysvq0asl unit_3){
  string_0_sysvq0asl result_42;
  nimStrWasMoved((&result_42));
  nimStrDestroy(result_42);
  result_42 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NB8 X60Qx_725;
  if ((!sig_0.ok_0)){
    X60Qx_725 = NIM_TRUE;}
  else {
    X60Qx_725 = (!(sig_0.params_0.len_0 == (*e_4).d_00.args_0.len_0));}
  if (X60Qx_725){
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  NI32 ctmp_0 = 0;
  string_0_sysvq0asl X60Qdesugar_76 = nimStrDup((*e_4).d_00.shimSym_0);
  NI32 X60Qx_726 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I9877049113831429732_aow7lb5cq1)}
  );
  NI32 X60Qx_727 = len_4_sysvq0asl(X60Qdesugar_76);
  NI32 X60Qx_728 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1868769534u, .more_0 = (&strlit_0_I1708222581923651341_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_77 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_726 + X60Qx_727)) + X60Qx_728)));
  add_2_sysvq0asl((&X60Qdesugar_77), (string_0_sysvq0asl){
    .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I9877049113831429732_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_77), X60Qdesugar_76);
  add_2_sysvq0asl((&X60Qdesugar_77), (string_0_sysvq0asl){
    .bytes_0 = 1868769534u, .more_0 = (&strlit_0_I1708222581923651341_aow7lb5cq1)}
  );
  nimStrDestroy(result_42);
  result_42 = X60Qdesugar_77;
  nimStrWasMoved((&X60Qdesugar_77));
  add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
    .bytes_0 = 1663049982u, .more_0 = (&strlit_0_I10178897100901084906_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
    .bytes_0 = 1965039870u, .more_0 = (&strlit_0_I4393801761698446017_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
    .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I7946228770895663279_aow7lb5cq1)}
  );
  NI32 i_19 = 0;
  string_0_sysvq0asl call_0 = ampQ_0_sysvq0asl(mangled_1, (string_0_sysvq0asl){
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
      NI32 X60Qx_729 = len_3_In63jw61_aow7lb5cq1((*e_4).d_00.args_0);
      if (i_19 < X60Qx_729){
        string_0_sysvq0asl X60Qtmp_32 = dollarQ_2_sysvq0asl(i_19);
        string_0_sysvq0asl a_9 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 24833u, .more_0 = NIM_NIL}
        , X60Qtmp_32);
        WireField_0_run8hsnpi* X60Qx_730 = getQ_7_Iko57h9_aow7lb5cq1((*e_4).d_00.args_0, i_19);
        WireField_0_run8hsnpi X60QconstRefTemp_0 = (*X60Qx_730);
        WireField_0_run8hsnpi f_14 = eQdupQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60QconstRefTemp_0));
        string_0_sysvq0asl* X60Qx_731 = getQ_7_Ir6d0tw_aow7lb5cq1(sig_0.params_0, i_19);
        string_0_sysvq0asl ty_1 = nimStrDup((*X60Qx_731));
        string_0_sysvq0asl w_6 = dollarQ_2_sysvq0asl(f_14.wireSize_0);
        string_0_sysvq0asl argExpr_0 = nimStrDup(a_9);
        if (f_14.isComposite_0){
          NI32 X60Qx_732 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2105346u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_733 = len_4_sysvq0asl(ty_1);
          NI32 X60Qx_734 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 8193u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_735 = len_4_sysvq0asl(a_9);
          NI32 X60Qx_736 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 670466u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_78 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_732 + X60Qx_733)) + X60Qx_734)) + X60Qx_735)) + X60Qx_736)));
          add_2_sysvq0asl((&X60Qdesugar_78), (string_0_sysvq0asl){
            .bytes_0 = 2105346u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_78), ty_1);
          add_2_sysvq0asl((&X60Qdesugar_78), (string_0_sysvq0asl){
            .bytes_0 = 8193u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_78), a_9);
          add_2_sysvq0asl((&X60Qdesugar_78), (string_0_sysvq0asl){
            .bytes_0 = 670466u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&result_42), X60Qdesugar_78);
          NI32 X60Qx_737 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7750355290083529673_aow7lb5cq1)}
          );
          NI32 X60Qx_738 = len_4_sysvq0asl(a_9);
          NI32 X60Qx_739 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
          );
          NI32 X60Qx_740 = len_4_sysvq0asl(a_9);
          NI32 X60Qx_741 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_79 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_737 + X60Qx_738)) + X60Qx_739)) + X60Qx_740)) + X60Qx_741)));
          add_2_sysvq0asl((&X60Qdesugar_79), (string_0_sysvq0asl){
            .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7750355290083529673_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_79), a_9);
          add_2_sysvq0asl((&X60Qdesugar_79), (string_0_sysvq0asl){
            .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_79), a_9);
          add_2_sysvq0asl((&X60Qdesugar_79), (string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_42), X60Qdesugar_79);
          NB8 cok_0 = NIM_TRUE;
          string_0_sysvq0asl body_0 = emitCompositeIn_0_aow7lb5cq1(f_14.desc_0, unit_3, ty_1, a_9, strT_2, longT_2, allocFn_1, deallocFn_2, (&ctmp_0), (&owned_1), (&cok_0));
          if ((!cok_0)){
            nimStrDestroy(body_0);
            nimStrDestroy(X60Qdesugar_79);
            nimStrDestroy(X60Qdesugar_78);
            nimStrDestroy(argExpr_0);
            nimStrDestroy(w_6);
            nimStrDestroy(ty_1);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_14));
            nimStrDestroy(a_9);
            nimStrDestroy(X60Qtmp_32);
            nimStrDestroy(writeback_0);
            nimStrDestroy(owned_1);
            nimStrDestroy(call_0);
            nimStrDestroy(X60Qdesugar_77);
            nimStrDestroy(X60Qdesugar_76);
            return (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            ;}
          add_2_sysvq0asl((&result_42), body_0);
          nimStrDestroy(body_0);
          nimStrDestroy(X60Qdesugar_79);
          nimStrDestroy(X60Qdesugar_78);}
        else {
          NB8 X60Qx_742 = stringOk_0_aow7lb5cq1((&f_14));
          if (X60Qx_742){
            string_0_sysvq0asl X60Qdesugar_80 = dollarQ_2_sysvq0asl(i_19);
            NI32 X60Qx_743 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
            );
            NI32 X60Qx_744 = len_4_sysvq0asl(X60Qdesugar_80);
            NI32 X60Qx_745 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_81 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_743 + X60Qx_744)) + X60Qx_745)));
            add_2_sysvq0asl((&X60Qdesugar_81), (string_0_sysvq0asl){
              .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_81), X60Qdesugar_80);
            add_2_sysvq0asl((&X60Qdesugar_81), (string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_42), X60Qdesugar_81);
            string_0_sysvq0asl X60Qdesugar_82 = dollarQ_2_sysvq0asl(i_19);
            NI32 X60Qx_746 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_747 = len_4_sysvq0asl(longT_2);
            NI32 X60Qx_748 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1864379134u, .more_0 = (&strlit_0_I9396282401636018722_aow7lb5cq1)}
            );
            NI32 X60Qx_749 = len_4_sysvq0asl(X60Qdesugar_82);
            NI32 X60Qx_750 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_83 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_746 + X60Qx_747)) + X60Qx_748)) + X60Qx_749)) + X60Qx_750)));
            add_2_sysvq0asl((&X60Qdesugar_83), (string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_83), longT_2);
            add_2_sysvq0asl((&X60Qdesugar_83), (string_0_sysvq0asl){
              .bytes_0 = 1864379134u, .more_0 = (&strlit_0_I9396282401636018722_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_83), X60Qdesugar_82);
            add_2_sysvq0asl((&X60Qdesugar_83), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_42), X60Qdesugar_83);
            string_0_sysvq0asl X60Qdesugar_84 = dollarQ_2_sysvq0asl(i_19);
            string_0_sysvq0asl X60Qdesugar_85 = dollarQ_2_sysvq0asl(i_19);
            NI32 X60Qx_751 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_752 = len_4_sysvq0asl(strT_2);
            NI32 X60Qx_753 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_754 = len_4_sysvq0asl(a_9);
            NI32 X60Qx_755 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I459476928402638487_aow7lb5cq1)}
            );
            NI32 X60Qx_756 = len_4_sysvq0asl(X60Qdesugar_84);
            NI32 X60Qx_757 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1259136645670664990_aow7lb5cq1)}
            );
            NI32 X60Qx_758 = len_4_sysvq0asl(X60Qdesugar_85);
            NI32 X60Qx_759 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 171649283u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_86 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_751 + X60Qx_752)) + X60Qx_753)) + X60Qx_754)) + X60Qx_755)) + X60Qx_756)) + X60Qx_757)) + X60Qx_758)) + X60Qx_759)));
            add_2_sysvq0asl((&X60Qdesugar_86), (string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_86), strT_2);
            add_2_sysvq0asl((&X60Qdesugar_86), (string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_86), a_9);
            add_2_sysvq0asl((&X60Qdesugar_86), (string_0_sysvq0asl){
              .bytes_0 = 540877054u, .more_0 = (&strlit_0_I459476928402638487_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_86), X60Qdesugar_84);
            add_2_sysvq0asl((&X60Qdesugar_86), (string_0_sysvq0asl){
              .bytes_0 = 639642878u, .more_0 = (&strlit_0_I1259136645670664990_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_86), X60Qdesugar_85);
            add_2_sysvq0asl((&X60Qdesugar_86), (string_0_sysvq0asl){
              .bytes_0 = 171649283u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_42), X60Qdesugar_86);
            string_0_sysvq0asl X60Qdesugar_87 = dollarQ_2_sysvq0asl(i_19);
            NI32 X60Qx_760 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4281043891304848808_aow7lb5cq1)}
            );
            NI32 X60Qx_761 = len_4_sysvq0asl(X60Qdesugar_87);
            NI32 X60Qx_762 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_88 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_760 + X60Qx_761)) + X60Qx_762)));
            add_2_sysvq0asl((&X60Qdesugar_88), (string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4281043891304848808_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_88), X60Qdesugar_87);
            add_2_sysvq0asl((&X60Qdesugar_88), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_42), X60Qdesugar_88);
            add_2_sysvq0asl((&owned_1), (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            );
            nimStrDestroy(X60Qdesugar_88);
            nimStrDestroy(X60Qdesugar_87);
            nimStrDestroy(X60Qdesugar_86);
            nimStrDestroy(X60Qdesugar_85);
            nimStrDestroy(X60Qdesugar_84);
            nimStrDestroy(X60Qdesugar_83);
            nimStrDestroy(X60Qdesugar_82);
            nimStrDestroy(X60Qdesugar_81);
            nimStrDestroy(X60Qdesugar_80);}
          else {
            NB8 X60Qx_763 = seqOk_0_aow7lb5cq1((&f_14));
            if (X60Qx_763){
              string_0_sysvq0asl st_0 = dollarQ_2_sysvq0asl(f_14.elemStride_0);
              string_0_sysvq0asl X60Qdesugar_89 = dollarQ_2_sysvq0asl(i_19);
              NI32 X60Qx_764 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
              );
              NI32 X60Qx_765 = len_4_sysvq0asl(X60Qdesugar_89);
              NI32 X60Qx_766 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_90 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_764 + X60Qx_765)) + X60Qx_766)));
              add_2_sysvq0asl((&X60Qdesugar_90), (string_0_sysvq0asl){
                .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I14735887367309579420_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_90), X60Qdesugar_89);
              add_2_sysvq0asl((&X60Qdesugar_90), (string_0_sysvq0asl){
                .bytes_0 = 540877054u, .more_0 = (&strlit_0_I13615089990240707056_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_90);
              NI32 X60Qx_767 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_768 = len_4_sysvq0asl(ty_1);
              NI32 X60Qx_769 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 8193u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_770 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_771 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_91 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_767 + X60Qx_768)) + X60Qx_769)) + X60Qx_770)) + X60Qx_771)));
              add_2_sysvq0asl((&X60Qdesugar_91), (string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_91), ty_1);
              add_2_sysvq0asl((&X60Qdesugar_91), (string_0_sysvq0asl){
                .bytes_0 = 8193u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_91), a_9);
              add_2_sysvq0asl((&X60Qdesugar_91), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_91);
              NI32 X60Qx_772 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I6378395016434652565_aow7lb5cq1)}
              );
              NI32 X60Qx_773 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_774 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
              );
              NI32 X60Qx_775 = len_4_sysvq0asl(st_0);
              NI32 X60Qx_776 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_92 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_772 + X60Qx_773)) + X60Qx_774)) + X60Qx_775)) + X60Qx_776)));
              add_2_sysvq0asl((&X60Qdesugar_92), (string_0_sysvq0asl){
                .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I6378395016434652565_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_92), a_9);
              add_2_sysvq0asl((&X60Qdesugar_92), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I17215664847085503029_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_92), st_0);
              add_2_sysvq0asl((&X60Qdesugar_92), (string_0_sysvq0asl){
                .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_92);
              NI32 X60Qx_777 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7750355290083529673_aow7lb5cq1)}
              );
              NI32 X60Qx_778 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_779 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
              );
              NI32 X60Qx_780 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_781 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_93 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_777 + X60Qx_778)) + X60Qx_779)) + X60Qx_780)) + X60Qx_781)));
              add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
                .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I7750355290083529673_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_93), a_9);
              add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
                .bytes_0 = 807415038u, .more_0 = (&strlit_0_I6252714416873801350_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_93), a_9);
              add_2_sysvq0asl((&X60Qdesugar_93), (string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_93);
              string_0_sysvq0asl X60Qdesugar_94 = dollarQ_2_sysvq0asl(i_19);
              NI32 X60Qx_782 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_783 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_784 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
              );
              NI32 X60Qx_785 = len_4_sysvq0asl(X60Qdesugar_94);
              NI32 X60Qx_786 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_95 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_782 + X60Qx_783)) + X60Qx_784)) + X60Qx_785)) + X60Qx_786)));
              add_2_sysvq0asl((&X60Qdesugar_95), (string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_95), a_9);
              add_2_sysvq0asl((&X60Qdesugar_95), (string_0_sysvq0asl){
                .bytes_0 = 1701588734u, .more_0 = (&strlit_0_I14627952699985668048_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_95), X60Qdesugar_94);
              add_2_sysvq0asl((&X60Qdesugar_95), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_95);
              string_0_sysvq0asl X60Qdesugar_96 = dollarQ_2_sysvq0asl(i_19);
              NI32 X60Qx_787 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I11268796792645648849_aow7lb5cq1)}
              );
              NI32 X60Qx_788 = len_4_sysvq0asl(X60Qdesugar_96);
              NI32 X60Qx_789 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_97 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_787 + X60Qx_788)) + X60Qx_789)));
              add_2_sysvq0asl((&X60Qdesugar_97), (string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I11268796792645648849_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_97), X60Qdesugar_96);
              add_2_sysvq0asl((&X60Qdesugar_97), (string_0_sysvq0asl){
                .bytes_0 = 540942590u, .more_0 = (&strlit_0_I7944783884798134160_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_97);
              string_0_sysvq0asl X60Qdesugar_98 = dollarQ_2_sysvq0asl(i_19);
              NI32 X60Qx_790 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
              );
              NI32 X60Qx_791 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_792 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
              );
              NI32 X60Qx_793 = len_4_sysvq0asl(allocFn_1);
              NI32 X60Qx_794 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
              );
              NI32 X60Qx_795 = len_4_sysvq0asl(X60Qdesugar_98);
              NI32 X60Qx_796 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_797 = len_4_sysvq0asl(st_0);
              NI32 X60Qx_798 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_99 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_790 + X60Qx_791)) + X60Qx_792)) + X60Qx_793)) + X60Qx_794)) + X60Qx_795)) + X60Qx_796)) + X60Qx_797)) + X60Qx_798)));
              add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1003006025800451514_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_99), a_9);
              add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6999826655792960192_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_99), allocFn_1);
              add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
                .bytes_0 = 1814571262u, .more_0 = (&strlit_0_I5702167724897352728_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_99), X60Qdesugar_98);
              add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_99), st_0);
              add_2_sysvq0asl((&X60Qdesugar_99), (string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_99);
              string_0_sysvq0asl X60Qdesugar_100 = dollarQ_2_sysvq0asl(i_19);
              NI32 X60Qx_799 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I89544630611547045_aow7lb5cq1)}
              );
              NI32 X60Qx_800 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_801 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I7701159626300919437_aow7lb5cq1)}
              );
              NI32 X60Qx_802 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1769154814u, .more_0 = (&strlit_0_I16305850586936607483_aow7lb5cq1)}
              );
              NI32 X60Qx_803 = len_4_sysvq0asl(X60Qdesugar_100);
              NI32 X60Qx_804 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_805 = len_4_sysvq0asl(st_0);
              NI32 X60Qx_806 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_101 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_799 + X60Qx_800)) + X60Qx_801)) + X60Qx_802)) + X60Qx_803)) + X60Qx_804)) + X60Qx_805)) + X60Qx_806)));
              add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I89544630611547045_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_101), a_9);
              add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I7701159626300919437_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
                .bytes_0 = 1769154814u, .more_0 = (&strlit_0_I16305850586936607483_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_101), X60Qdesugar_100);
              add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_101), st_0);
              add_2_sysvq0asl((&X60Qdesugar_101), (string_0_sysvq0asl){
                .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_101);
              add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
                .bytes_0 = 2099257598u, .more_0 = (&strlit_0_I6468377022308900005_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_102 = dollarQ_2_sysvq0asl(i_19);
              NI32 X60Qx_807 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4281043891304848808_aow7lb5cq1)}
              );
              NI32 X60Qx_808 = len_4_sysvq0asl(X60Qdesugar_102);
              NI32 X60Qx_809 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_810 = len_4_sysvq0asl(st_0);
              NI32 X60Qx_811 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_103 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_807 + X60Qx_808)) + X60Qx_809)) + X60Qx_810)) + X60Qx_811)));
              add_2_sysvq0asl((&X60Qdesugar_103), (string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I4281043891304848808_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_103), X60Qdesugar_102);
              add_2_sysvq0asl((&X60Qdesugar_103), (string_0_sysvq0asl){
                .bytes_0 = 539631619u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_103), st_0);
              add_2_sysvq0asl((&X60Qdesugar_103), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_103);
              NI32 X60Qx_812 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
              );
              NI32 X60Qx_813 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_814 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
              );
              NI32 X60Qx_815 = len_4_sysvq0asl(deallocFn_2);
              NI32 X60Qx_816 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
              );
              NI32 X60Qx_817 = len_4_sysvq0asl(a_9);
              NI32 X60Qx_818 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_104 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_812 + X60Qx_813)) + X60Qx_814)) + X60Qx_815)) + X60Qx_816)) + X60Qx_817)) + X60Qx_818)));
              add_2_sysvq0asl((&X60Qdesugar_104), (string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I15158283226406648984_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_104), a_9);
              add_2_sysvq0asl((&X60Qdesugar_104), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I3060741871306050012_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_104), deallocFn_2);
              add_2_sysvq0asl((&X60Qdesugar_104), (string_0_sysvq0asl){
                .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I740199077749326402_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_104), a_9);
              add_2_sysvq0asl((&X60Qdesugar_104), (string_0_sysvq0asl){
                .bytes_0 = 1633955582u, .more_0 = (&strlit_0_I6703734619365257310_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&owned_1), X60Qdesugar_104);
              nimStrDestroy(X60Qdesugar_104);
              nimStrDestroy(X60Qdesugar_103);
              nimStrDestroy(X60Qdesugar_102);
              nimStrDestroy(X60Qdesugar_101);
              nimStrDestroy(X60Qdesugar_100);
              nimStrDestroy(X60Qdesugar_99);
              nimStrDestroy(X60Qdesugar_98);
              nimStrDestroy(X60Qdesugar_97);
              nimStrDestroy(X60Qdesugar_96);
              nimStrDestroy(X60Qdesugar_95);
              nimStrDestroy(X60Qdesugar_94);
              nimStrDestroy(X60Qdesugar_93);
              nimStrDestroy(X60Qdesugar_92);
              nimStrDestroy(X60Qdesugar_91);
              nimStrDestroy(X60Qdesugar_90);
              nimStrDestroy(X60Qdesugar_89);
              nimStrDestroy(st_0);}
            else {
              NB8 X60Qx_819 = podOk_0_aow7lb5cq1((&f_14));
              if (X60Qx_819){
                NI32 X60Qx_820 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_821 = len_4_sysvq0asl(ty_1);
                NI32 X60Qx_822 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 8193u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_823 = len_4_sysvq0asl(a_9);
                NI32 X60Qx_824 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_105 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_820 + X60Qx_821)) + X60Qx_822)) + X60Qx_823)) + X60Qx_824)));
                add_2_sysvq0asl((&X60Qdesugar_105), (string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_105), ty_1);
                add_2_sysvq0asl((&X60Qdesugar_105), (string_0_sysvq0asl){
                  .bytes_0 = 8193u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_105), a_9);
                add_2_sysvq0asl((&X60Qdesugar_105), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_105);
                NI32 X60Qx_825 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                );
                NI32 X60Qx_826 = len_4_sysvq0asl(a_9);
                NI32 X60Qx_827 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                );
                NI32 X60Qx_828 = len_4_sysvq0asl(w_6);
                NI32 X60Qx_829 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 572534014u, .more_0 = (&strlit_0_I17122198299299987856_aow7lb5cq1)}
                );
                string_0_sysvq0asl X60Qdesugar_106 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_825 + X60Qx_826)) + X60Qx_827)) + X60Qx_828)) + X60Qx_829)));
                add_2_sysvq0asl((&X60Qdesugar_106), (string_0_sysvq0asl){
                  .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_106), a_9);
                add_2_sysvq0asl((&X60Qdesugar_106), (string_0_sysvq0asl){
                  .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_106), w_6);
                add_2_sysvq0asl((&X60Qdesugar_106), (string_0_sysvq0asl){
                  .bytes_0 = 572534014u, .more_0 = (&strlit_0_I17122198299299987856_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_106);
                NI32 X60Qx_830 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
                );
                NI32 X60Qx_831 = len_4_sysvq0asl(a_9);
                NI32 X60Qx_832 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
                );
                NI32 X60Qx_833 = len_4_sysvq0asl(w_6);
                NI32 X60Qx_834 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_107 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_830 + X60Qx_831)) + X60Qx_832)) + X60Qx_833)) + X60Qx_834)));
                add_2_sysvq0asl((&X60Qdesugar_107), (string_0_sysvq0asl){
                  .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_107), a_9);
                add_2_sysvq0asl((&X60Qdesugar_107), (string_0_sysvq0asl){
                  .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_107), w_6);
                add_2_sysvq0asl((&X60Qdesugar_107), (string_0_sysvq0asl){
                  .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_107);
                NI32 X60Qx_835 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                );
                NI32 X60Qx_836 = len_4_sysvq0asl(w_6);
                NI32 X60Qx_837 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_108 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_835 + X60Qx_836)) + X60Qx_837)));
                add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_108), w_6);
                add_2_sysvq0asl((&X60Qdesugar_108), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_108);
                nimStrDestroy(X60Qdesugar_108);
                nimStrDestroy(X60Qdesugar_107);
                nimStrDestroy(X60Qdesugar_106);
                nimStrDestroy(X60Qdesugar_105);}
              else {
                NB8 X60Qx_838 = floatOk_0_aow7lb5cq1((&f_14));
                if (X60Qx_838){
                  NI32 X60Qx_839 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                  );
                  NI32 X60Qx_840 = len_4_sysvq0asl(ty_1);
                  NI32 X60Qx_841 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 8193u, .more_0 = NIM_NIL}
                  );
                  NI32 X60Qx_842 = len_4_sysvq0asl(a_9);
                  NI32 X60Qx_843 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_109 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_839 + X60Qx_840)) + X60Qx_841)) + X60Qx_842)) + X60Qx_843)));
                  add_2_sysvq0asl((&X60Qdesugar_109), (string_0_sysvq0asl){
                    .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_109), ty_1);
                  add_2_sysvq0asl((&X60Qdesugar_109), (string_0_sysvq0asl){
                    .bytes_0 = 8193u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_109), a_9);
                  add_2_sysvq0asl((&X60Qdesugar_109), (string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&result_42), X60Qdesugar_109);
                  NI32 X60Qx_844 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                  );
                  NI32 X60Qx_845 = len_4_sysvq0asl(a_9);
                  NI32 X60Qx_846 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                  );
                  NI32 X60Qx_847 = len_4_sysvq0asl(w_6);
                  NI32 X60Qx_848 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 572534014u, .more_0 = (&strlit_0_I7306618916803007629_aow7lb5cq1)}
                  );
                  string_0_sysvq0asl X60Qdesugar_110 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_844 + X60Qx_845)) + X60Qx_846)) + X60Qx_847)) + X60Qx_848)));
                  add_2_sysvq0asl((&X60Qdesugar_110), (string_0_sysvq0asl){
                    .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_110), a_9);
                  add_2_sysvq0asl((&X60Qdesugar_110), (string_0_sysvq0asl){
                    .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_110), w_6);
                  add_2_sysvq0asl((&X60Qdesugar_110), (string_0_sysvq0asl){
                    .bytes_0 = 572534014u, .more_0 = (&strlit_0_I7306618916803007629_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&result_42), X60Qdesugar_110);
                  string_0_sysvq0asl X60Qdesugar_111 = dollarQ_2_sysvq0asl(i_19);
                  NI32 X60Qx_849 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I17558875563685861326_aow7lb5cq1)}
                  );
                  NI32 X60Qx_850 = len_4_sysvq0asl(X60Qdesugar_111);
                  NI32 X60Qx_851 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 540877054u, .more_0 = (&strlit_0_I6387934463080488581_aow7lb5cq1)}
                  );
                  NI32 X60Qx_852 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I15883747490575809941_aow7lb5cq1)}
                  );
                  NI32 X60Qx_853 = len_4_sysvq0asl(w_6);
                  NI32 X60Qx_854 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_112 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_849 + X60Qx_850)) + X60Qx_851)) + X60Qx_852)) + X60Qx_853)) + X60Qx_854)));
                  add_2_sysvq0asl((&X60Qdesugar_112), (string_0_sysvq0asl){
                    .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I17558875563685861326_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_112), X60Qdesugar_111);
                  add_2_sysvq0asl((&X60Qdesugar_112), (string_0_sysvq0asl){
                    .bytes_0 = 540877054u, .more_0 = (&strlit_0_I6387934463080488581_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_112), (string_0_sysvq0asl){
                    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I15883747490575809941_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_112), w_6);
                  add_2_sysvq0asl((&X60Qdesugar_112), (string_0_sysvq0asl){
                    .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&result_42), X60Qdesugar_112);
                  string_0_sysvq0asl X60Qdesugar_113 = dollarQ_2_sysvq0asl(i_19);
                  NI32 X60Qx_855 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18167370821491564789_aow7lb5cq1)}
                  );
                  NI32 X60Qx_856 = len_4_sysvq0asl(a_9);
                  NI32 X60Qx_857 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 639642878u, .more_0 = (&strlit_0_I15101036524968472333_aow7lb5cq1)}
                  );
                  NI32 X60Qx_858 = len_4_sysvq0asl(X60Qdesugar_113);
                  NI32 X60Qx_859 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                  );
                  NI32 X60Qx_860 = len_4_sysvq0asl(w_6);
                  NI32 X60Qx_861 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 540748286u, .more_0 = (&strlit_0_I17415683837379957581_aow7lb5cq1)}
                  );
                  string_0_sysvq0asl X60Qdesugar_114 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_855 + X60Qx_856)) + X60Qx_857)) + X60Qx_858)) + X60Qx_859)) + X60Qx_860)) + X60Qx_861)));
                  add_2_sysvq0asl((&X60Qdesugar_114), (string_0_sysvq0asl){
                    .bytes_0 = 538976510u, .more_0 = (&strlit_0_I18167370821491564789_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_114), a_9);
                  add_2_sysvq0asl((&X60Qdesugar_114), (string_0_sysvq0asl){
                    .bytes_0 = 639642878u, .more_0 = (&strlit_0_I15101036524968472333_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_114), X60Qdesugar_113);
                  add_2_sysvq0asl((&X60Qdesugar_114), (string_0_sysvq0asl){
                    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_114), w_6);
                  add_2_sysvq0asl((&X60Qdesugar_114), (string_0_sysvq0asl){
                    .bytes_0 = 540748286u, .more_0 = (&strlit_0_I17415683837379957581_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&result_42), X60Qdesugar_114);
                  NI32 X60Qx_862 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                  );
                  NI32 X60Qx_863 = len_4_sysvq0asl(w_6);
                  NI32 X60Qx_864 = len_4_sysvq0asl((string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  string_0_sysvq0asl X60Qdesugar_115 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_862 + X60Qx_863)) + X60Qx_864)));
                  add_2_sysvq0asl((&X60Qdesugar_115), (string_0_sysvq0asl){
                    .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                  );
                  add_2_sysvq0asl((&X60Qdesugar_115), w_6);
                  add_2_sysvq0asl((&X60Qdesugar_115), (string_0_sysvq0asl){
                    .bytes_0 = 670466u, .more_0 = NIM_NIL}
                  );
                  add_2_sysvq0asl((&result_42), X60Qdesugar_115);
                  nimStrDestroy(X60Qdesugar_115);
                  nimStrDestroy(X60Qdesugar_114);
                  nimStrDestroy(X60Qdesugar_113);
                  nimStrDestroy(X60Qdesugar_112);
                  nimStrDestroy(X60Qdesugar_111);
                  nimStrDestroy(X60Qdesugar_110);
                  nimStrDestroy(X60Qdesugar_109);}
                else {
                  NB8 X60Qx_865 = enumOk_0_aow7lb5cq1((&f_14));
                  if (X60Qx_865){
                    NI32 X60Qx_866 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                    );
                    NI32 X60Qx_867 = len_4_sysvq0asl(ty_1);
                    NI32 X60Qx_868 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 8193u, .more_0 = NIM_NIL}
                    );
                    NI32 X60Qx_869 = len_4_sysvq0asl(a_9);
                    NI32 X60Qx_870 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 540877054u, .more_0 = (&strlit_0_I18160002208581309871_aow7lb5cq1)}
                    );
                    NI32 X60Qx_871 = len_4_sysvq0asl(ty_1);
                    NI32 X60Qx_872 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1868638718u, .more_0 = (&strlit_0_I7038441574186707900_aow7lb5cq1)}
                    );
                    string_0_sysvq0asl X60Qdesugar_116 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_866 + X60Qx_867)) + X60Qx_868)) + X60Qx_869)) + X60Qx_870)) + X60Qx_871)) + X60Qx_872)));
                    add_2_sysvq0asl((&X60Qdesugar_116), (string_0_sysvq0asl){
                      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_116), ty_1);
                    add_2_sysvq0asl((&X60Qdesugar_116), (string_0_sysvq0asl){
                      .bytes_0 = 8193u, .more_0 = NIM_NIL}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_116), a_9);
                    add_2_sysvq0asl((&X60Qdesugar_116), (string_0_sysvq0asl){
                      .bytes_0 = 540877054u, .more_0 = (&strlit_0_I18160002208581309871_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_116), ty_1);
                    add_2_sysvq0asl((&X60Qdesugar_116), (string_0_sysvq0asl){
                      .bytes_0 = 1868638718u, .more_0 = (&strlit_0_I7038441574186707900_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&result_42), X60Qdesugar_116);
                    add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
                      .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I2765646999664450274_aow7lb5cq1)}
                    );
                    nimStrDestroy(X60Qdesugar_116);}
                  else {
                    NB8 X60Qx_873 = varOk_0_aow7lb5cq1((&f_14));
                    if (X60Qx_873){
                      string_0_sysvq0asl pt_0 = derefType_0_aow7lb5cq1(ty_1);
                      NI32 X60Qx_874 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_875 = len_4_sysvq0asl(pt_0);
                      NI32 X60Qx_876 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_877 = len_4_sysvq0asl(a_9);
                      NI32 X60Qx_878 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_117 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_874 + X60Qx_875)) + X60Qx_876)) + X60Qx_877)) + X60Qx_878)));
                      add_2_sysvq0asl((&X60Qdesugar_117), (string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_117), pt_0);
                      add_2_sysvq0asl((&X60Qdesugar_117), (string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_117), a_9);
                      add_2_sysvq0asl((&X60Qdesugar_117), (string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_42), X60Qdesugar_117);
                      NI32 X60Qx_879 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                      );
                      NI32 X60Qx_880 = len_4_sysvq0asl(a_9);
                      NI32 X60Qx_881 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                      );
                      NI32 X60Qx_882 = len_4_sysvq0asl(w_6);
                      NI32 X60Qx_883 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 572534014u, .more_0 = (&strlit_0_I16666830705696825015_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_118 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_879 + X60Qx_880)) + X60Qx_881)) + X60Qx_882)) + X60Qx_883)));
                      add_2_sysvq0asl((&X60Qdesugar_118), (string_0_sysvq0asl){
                        .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I10518045726280400131_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_118), a_9);
                      add_2_sysvq0asl((&X60Qdesugar_118), (string_0_sysvq0asl){
                        .bytes_0 = 1025518078u, .more_0 = (&strlit_0_I1775559386484707154_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_118), w_6);
                      add_2_sysvq0asl((&X60Qdesugar_118), (string_0_sysvq0asl){
                        .bytes_0 = 572534014u, .more_0 = (&strlit_0_I16666830705696825015_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&result_42), X60Qdesugar_118);
                      NI32 X60Qx_884 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
                      );
                      NI32 X60Qx_885 = len_4_sysvq0asl(a_9);
                      NI32 X60Qx_886 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
                      );
                      NI32 X60Qx_887 = len_4_sysvq0asl(w_6);
                      NI32 X60Qx_888 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_119 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_884 + X60Qx_885)) + X60Qx_886)) + X60Qx_887)) + X60Qx_888)));
                      add_2_sysvq0asl((&X60Qdesugar_119), (string_0_sysvq0asl){
                        .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I4687979134801646472_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_119), a_9);
                      add_2_sysvq0asl((&X60Qdesugar_119), (string_0_sysvq0asl){
                        .bytes_0 = 1763716350u, .more_0 = (&strlit_0_I15444428613251533457_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_119), w_6);
                      add_2_sysvq0asl((&X60Qdesugar_119), (string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_42), X60Qdesugar_119);
                      NI32 X60Qx_889 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                      );
                      NI32 X60Qx_890 = len_4_sysvq0asl(w_6);
                      NI32 X60Qx_891 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_120 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_889 + X60Qx_890)) + X60Qx_891)));
                      add_2_sysvq0asl((&X60Qdesugar_120), (string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_120), w_6);
                      add_2_sysvq0asl((&X60Qdesugar_120), (string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_42), X60Qdesugar_120);
                      nimStrDestroy(argExpr_0);
                      string_0_sysvq0asl X60Qx_892 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 9729u, .more_0 = NIM_NIL}
                      , a_9);
                      argExpr_0 = X60Qx_892;
                      NB8 X60Qx_893;
                      NI32 X60Qx_894 = len_3_I0v1j8d_aow7lb5cq1((*e_4).d_00.outVarOffs_0);
                      if (i_19 < X60Qx_894){
                        NI32* X60Qx_895 = getQ_7_Ir8kccm_aow7lb5cq1((*e_4).d_00.outVarOffs_0, i_19);
                        X60Qx_893 = (0 <= (*X60Qx_895));}
                      else {
                        X60Qx_893 = NIM_FALSE;}
                      if (X60Qx_893){
                        NI32* X60Qx_896 = getQ_7_Ir8kccm_aow7lb5cq1((*e_4).d_00.outVarOffs_0, i_19);
                        string_0_sysvq0asl X60Qdesugar_121 = dollarQ_2_sysvq0asl((*X60Qx_896));
                        NI32 X60Qx_897 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I17822294574896570456_aow7lb5cq1)}
                        );
                        NI32 X60Qx_898 = len_4_sysvq0asl(X60Qdesugar_121);
                        NI32 X60Qx_899 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 639642627u, .more_0 = NIM_NIL}
                        );
                        NI32 X60Qx_900 = len_4_sysvq0asl(a_9);
                        NI32 X60Qx_901 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                        );
                        NI32 X60Qx_902 = len_4_sysvq0asl(w_6);
                        NI32 X60Qx_903 = len_4_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                        );
                        string_0_sysvq0asl X60Qdesugar_122 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_897 + X60Qx_898)) + X60Qx_899)) + X60Qx_900)) + X60Qx_901)) + X60Qx_902)) + X60Qx_903)));
                        add_2_sysvq0asl((&X60Qdesugar_122), (string_0_sysvq0asl){
                          .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I17822294574896570456_aow7lb5cq1)}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_122), X60Qdesugar_121);
                        add_2_sysvq0asl((&X60Qdesugar_122), (string_0_sysvq0asl){
                          .bytes_0 = 639642627u, .more_0 = NIM_NIL}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_122), a_9);
                        add_2_sysvq0asl((&X60Qdesugar_122), (string_0_sysvq0asl){
                          .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                        );
                        add_2_sysvq0asl((&X60Qdesugar_122), w_6);
                        add_2_sysvq0asl((&X60Qdesugar_122), (string_0_sysvq0asl){
                          .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                        );
                        add_2_sysvq0asl((&writeback_0), X60Qdesugar_122);
                        nimStrDestroy(X60Qdesugar_122);
                        nimStrDestroy(X60Qdesugar_121);}
                      nimStrDestroy(X60Qdesugar_120);
                      nimStrDestroy(X60Qdesugar_119);
                      nimStrDestroy(X60Qdesugar_118);
                      nimStrDestroy(X60Qdesugar_117);
                      nimStrDestroy(pt_0);}
                    else {
                      NI32 X60Qx_904 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_905 = len_4_sysvq0asl(ty_1);
                      NI32 X60Qx_906 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_907 = len_4_sysvq0asl(a_9);
                      NI32 X60Qx_908 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I18160002208581309871_aow7lb5cq1)}
                      );
                      NI32 X60Qx_909 = len_4_sysvq0asl(ty_1);
                      NI32 X60Qx_910 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1868638718u, .more_0 = (&strlit_0_I8046607679966277039_aow7lb5cq1)}
                      );
                      NI32 X60Qx_911 = len_4_sysvq0asl(w_6);
                      NI32 X60Qx_912 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_123 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_904 + X60Qx_905)) + X60Qx_906)) + X60Qx_907)) + X60Qx_908)) + X60Qx_909)) + X60Qx_910)) + X60Qx_911)) + X60Qx_912)));
                      add_2_sysvq0asl((&X60Qdesugar_123), (string_0_sysvq0asl){
                        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_123), ty_1);
                      add_2_sysvq0asl((&X60Qdesugar_123), (string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_123), a_9);
                      add_2_sysvq0asl((&X60Qdesugar_123), (string_0_sysvq0asl){
                        .bytes_0 = 540877054u, .more_0 = (&strlit_0_I18160002208581309871_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_123), ty_1);
                      add_2_sysvq0asl((&X60Qdesugar_123), (string_0_sysvq0asl){
                        .bytes_0 = 1868638718u, .more_0 = (&strlit_0_I8046607679966277039_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_123), w_6);
                      add_2_sysvq0asl((&X60Qdesugar_123), (string_0_sysvq0asl){
                        .bytes_0 = 171649283u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_42), X60Qdesugar_123);
                      NI32 X60Qx_913 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                      );
                      NI32 X60Qx_914 = len_4_sysvq0asl(w_6);
                      NI32 X60Qx_915 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_124 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_913 + X60Qx_914)) + X60Qx_915)));
                      add_2_sysvq0asl((&X60Qdesugar_124), (string_0_sysvq0asl){
                        .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I9864864561646881256_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_124), w_6);
                      add_2_sysvq0asl((&X60Qdesugar_124), (string_0_sysvq0asl){
                        .bytes_0 = 670466u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&result_42), X60Qdesugar_124);
                      nimStrDestroy(X60Qdesugar_124);
                      nimStrDestroy(X60Qdesugar_123);}}}}}}}
        if (0 < i_19){
          add_2_sysvq0asl((&call_0), (string_0_sysvq0asl){
            .bytes_0 = 2108418u, .more_0 = NIM_NIL}
          );}
        add_2_sysvq0asl((&call_0), argExpr_0);
        inc_1_I6wjjge_aow2h993l1((&i_19));
        nimStrDestroy(argExpr_0);
        nimStrDestroy(w_6);
        nimStrDestroy(ty_1);
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_14));
        nimStrDestroy(a_9);
        nimStrDestroy(X60Qtmp_32);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  add_2_sysvq0asl((&call_0), (string_0_sysvq0asl){
    .bytes_0 = 10497u, .more_0 = NIM_NIL}
  );
  if ((*e_4).d_00.retVoid_0){
    NI32 X60Qx_916 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_917 = len_4_sysvq0asl(call_0);
    NI32 X60Qx_918 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_125 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_916 + X60Qx_917)) + X60Qx_918)));
    add_2_sysvq0asl((&X60Qdesugar_125), (string_0_sysvq0asl){
      .bytes_0 = 2105346u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_125), call_0);
    add_2_sysvq0asl((&X60Qdesugar_125), (string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&result_42), X60Qdesugar_125);
    add_2_sysvq0asl((&result_42), owned_1);
    add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
      .bytes_0 = 673194238u, .more_0 = (&strlit_0_I13766595355654876791_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_126 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
    string_0_sysvq0asl X60Qdesugar_127 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
    NI32 X60Qx_919 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
    );
    NI32 X60Qx_920 = len_4_sysvq0asl(X60Qdesugar_126);
    NI32 X60Qx_921 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
    );
    NI32 X60Qx_922 = len_4_sysvq0asl(X60Qdesugar_127);
    NI32 X60Qx_923 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_128 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_919 + X60Qx_920)) + X60Qx_921)) + X60Qx_922)) + X60Qx_923)));
    add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
      .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_128), X60Qdesugar_126);
    add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
      .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_128), X60Qdesugar_127);
    add_2_sysvq0asl((&X60Qdesugar_128), (string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&result_42), X60Qdesugar_128);
    add_2_sysvq0asl((&result_42), writeback_0);
    string_0_sysvq0asl X60Qdesugar_129 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
    NI32 X60Qx_924 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
    );
    NI32 X60Qx_925 = len_4_sysvq0asl(X60Qdesugar_129);
    NI32 X60Qx_926 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_130 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_924 + X60Qx_925)) + X60Qx_926)));
    add_2_sysvq0asl((&X60Qdesugar_130), (string_0_sysvq0asl){
      .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_130), X60Qdesugar_129);
    add_2_sysvq0asl((&X60Qdesugar_130), (string_0_sysvq0asl){
      .bytes_0 = 670466u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&result_42), X60Qdesugar_130);
    nimStrDestroy(X60Qdesugar_130);
    nimStrDestroy(X60Qdesugar_129);
    nimStrDestroy(X60Qdesugar_128);
    nimStrDestroy(X60Qdesugar_127);
    nimStrDestroy(X60Qdesugar_126);
    nimStrDestroy(X60Qdesugar_125);}
  else {
    if ((*e_4).d_00.ret_0.isComposite_0){
      NI32 X60Qx_927 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_928 = len_4_sysvq0asl(sig_0.ret_0);
      NI32 X60Qx_929 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
      );
      NI32 X60Qx_930 = len_4_sysvq0asl(call_0);
      NI32 X60Qx_931 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_131 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_927 + X60Qx_928)) + X60Qx_929)) + X60Qx_930)) + X60Qx_931)));
      add_2_sysvq0asl((&X60Qdesugar_131), (string_0_sysvq0asl){
        .bytes_0 = 2105346u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_131), sig_0.ret_0);
      add_2_sysvq0asl((&X60Qdesugar_131), (string_0_sysvq0asl){
        .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_131), call_0);
      add_2_sysvq0asl((&X60Qdesugar_131), (string_0_sysvq0asl){
        .bytes_0 = 670466u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&result_42), X60Qdesugar_131);
      add_2_sysvq0asl((&result_42), owned_1);
      NB8 sok_0 = NIM_TRUE;
      string_0_sysvq0asl sizePass_0 = emitCompositeSize_0_aow7lb5cq1((*e_4).d_00.ret_0.desc_0, unit_3, sig_0.ret_0, (string_0_sysvq0asl){
        .bytes_0 = 6255106u, .more_0 = NIM_NIL}
      , (&ctmp_0), (&sok_0));
      string_0_sysvq0asl freeing_1 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      string_0_sysvq0asl writePass_0 = emitCompositeOut_0_aow7lb5cq1((*e_4).d_00.ret_0.desc_0, unit_3, sig_0.ret_0, (string_0_sysvq0asl){
        .bytes_0 = 6255106u, .more_0 = NIM_NIL}
      , deallocFn_2, (&ctmp_0), (&freeing_1), (&sok_0));
      if ((!sok_0)){
        nimStrDestroy(writePass_0);
        nimStrDestroy(freeing_1);
        nimStrDestroy(sizePass_0);
        nimStrDestroy(X60Qdesugar_131);
        nimStrDestroy(writeback_0);
        nimStrDestroy(owned_1);
        nimStrDestroy(call_0);
        nimStrDestroy(X60Qdesugar_77);
        nimStrDestroy(X60Qdesugar_76);
        return (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;}
      add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
        .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I17934854375404503520_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_42), sizePass_0);
      add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I12313396470659978363_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10672841733508358863_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_42), freeing_1);
      add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I4649953770147481749_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5487312882993115281_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10166787625402032659_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_42), writePass_0);
      add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I13914791540775111549_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&result_42), freeing_1);
      add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
        .bytes_0 = 538976510u, .more_0 = (&strlit_0_I6654729803687239304_aow7lb5cq1)}
      );
      nimStrDestroy(writePass_0);
      nimStrDestroy(freeing_1);
      nimStrDestroy(sizePass_0);
      nimStrDestroy(X60Qdesugar_131);}
    else {
      NB8 X60Qx_932 = stringOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
      if (X60Qx_932){
        NI32 X60Qx_933 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2105346u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_934 = len_4_sysvq0asl(strT_2);
        NI32 X60Qx_935 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
        );
        NI32 X60Qx_936 = len_4_sysvq0asl(call_0);
        NI32 X60Qx_937 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_132 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_933 + X60Qx_934)) + X60Qx_935)) + X60Qx_936)) + X60Qx_937)));
        add_2_sysvq0asl((&X60Qdesugar_132), (string_0_sysvq0asl){
          .bytes_0 = 2105346u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_132), strT_2);
        add_2_sysvq0asl((&X60Qdesugar_132), (string_0_sysvq0asl){
          .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_132), call_0);
        add_2_sysvq0asl((&X60Qdesugar_132), (string_0_sysvq0asl){
          .bytes_0 = 670466u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&result_42), X60Qdesugar_132);
        add_2_sysvq0asl((&result_42), owned_1);
        add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
          .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I12522613173660839319_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I3911820715027972186_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I790167309358444658_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I5310786661721115423_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15509854563229856298_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11068729316509706393_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I9486276691579103789_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
          .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1654792515589026066_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
          .bytes_0 = 2099257598u, .more_0 = (&strlit_0_I6468377022308900005_aow7lb5cq1)}
        );
        nimStrDestroy(X60Qdesugar_132);}
      else {
        NB8 X60Qx_938 = seqOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
        if (X60Qx_938){
          string_0_sysvq0asl st_1 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.elemStride_0);
          NI32 X60Qx_939 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2105346u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_940 = len_4_sysvq0asl(sig_0.ret_0);
          NI32 X60Qx_941 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
          );
          NI32 X60Qx_942 = len_4_sysvq0asl(call_0);
          NI32 X60Qx_943 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 670466u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_133 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_939 + X60Qx_940)) + X60Qx_941)) + X60Qx_942)) + X60Qx_943)));
          add_2_sysvq0asl((&X60Qdesugar_133), (string_0_sysvq0asl){
            .bytes_0 = 2105346u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_133), sig_0.ret_0);
          add_2_sysvq0asl((&X60Qdesugar_133), (string_0_sysvq0asl){
            .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_133), call_0);
          add_2_sysvq0asl((&X60Qdesugar_133), (string_0_sysvq0asl){
            .bytes_0 = 670466u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&result_42), X60Qdesugar_133);
          add_2_sysvq0asl((&result_42), owned_1);
          NI32 X60Qx_944 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I4970679303273918317_aow7lb5cq1)}
          );
          NI32 X60Qx_945 = len_4_sysvq0asl(st_1);
          NI32 X60Qx_946 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_134 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_944 + X60Qx_945)) + X60Qx_946)));
          add_2_sysvq0asl((&X60Qdesugar_134), (string_0_sysvq0asl){
            .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I4970679303273918317_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_134), st_1);
          add_2_sysvq0asl((&X60Qdesugar_134), (string_0_sysvq0asl){
            .bytes_0 = 572534014u, .more_0 = (&strlit_0_I11947772824232299275_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_42), X60Qdesugar_134);
          add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
            .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I12522613173660839319_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11224338710434874543_aow7lb5cq1)}
          );
          NI32 X60Qx_947 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16703820542586360166_aow7lb5cq1)}
          );
          NI32 X60Qx_948 = len_4_sysvq0asl(st_1);
          NI32 X60Qx_949 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 171649283u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_135 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_947 + X60Qx_948)) + X60Qx_949)));
          add_2_sysvq0asl((&X60Qdesugar_135), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I16703820542586360166_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_135), st_1);
          add_2_sysvq0asl((&X60Qdesugar_135), (string_0_sysvq0asl){
            .bytes_0 = 171649283u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&result_42), X60Qdesugar_135);
          NI32 X60Qx_950 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17847894267599352048_aow7lb5cq1)}
          );
          NI32 X60Qx_951 = len_4_sysvq0asl(deallocFn_2);
          NI32 X60Qx_952 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I17765033553311774074_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_136 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_950 + X60Qx_951)) + X60Qx_952)));
          add_2_sysvq0asl((&X60Qdesugar_136), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I17847894267599352048_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_136), deallocFn_2);
          add_2_sysvq0asl((&X60Qdesugar_136), (string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I17765033553311774074_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_42), X60Qdesugar_136);
          add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I11068729316509706393_aow7lb5cq1)}
          );
          NI32 X60Qx_953 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15275851150300379331_aow7lb5cq1)}
          );
          NI32 X60Qx_954 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1769154814u, .more_0 = (&strlit_0_I3690031806701659348_aow7lb5cq1)}
          );
          NI32 X60Qx_955 = len_4_sysvq0asl(st_1);
          NI32 X60Qx_956 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_137 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_953 + X60Qx_954)) + X60Qx_955)) + X60Qx_956)));
          add_2_sysvq0asl((&X60Qdesugar_137), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I15275851150300379331_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_137), (string_0_sysvq0asl){
            .bytes_0 = 1769154814u, .more_0 = (&strlit_0_I3690031806701659348_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_137), st_1);
          add_2_sysvq0asl((&X60Qdesugar_137), (string_0_sysvq0asl){
            .bytes_0 = 992553470u, .more_0 = (&strlit_0_I12127742131857817540_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_42), X60Qdesugar_137);
          NI32 X60Qx_957 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I8277570052652068250_aow7lb5cq1)}
          );
          NI32 X60Qx_958 = len_4_sysvq0asl(deallocFn_2);
          NI32 X60Qx_959 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I8678069405976132067_aow7lb5cq1)}
          );
          string_0_sysvq0asl X60Qdesugar_138 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_957 + X60Qx_958)) + X60Qx_959)));
          add_2_sysvq0asl((&X60Qdesugar_138), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I8277570052652068250_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&X60Qdesugar_138), deallocFn_2);
          add_2_sysvq0asl((&X60Qdesugar_138), (string_0_sysvq0asl){
            .bytes_0 = 1982343422u, .more_0 = (&strlit_0_I8678069405976132067_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_42), X60Qdesugar_138);
          add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
            .bytes_0 = 538976510u, .more_0 = (&strlit_0_I1654792515589026066_aow7lb5cq1)}
          );
          add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
            .bytes_0 = 2099257598u, .more_0 = (&strlit_0_I6468377022308900005_aow7lb5cq1)}
          );
          nimStrDestroy(X60Qdesugar_138);
          nimStrDestroy(X60Qdesugar_137);
          nimStrDestroy(X60Qdesugar_136);
          nimStrDestroy(X60Qdesugar_135);
          nimStrDestroy(X60Qdesugar_134);
          nimStrDestroy(X60Qdesugar_133);
          nimStrDestroy(st_1);}
        else {
          NB8 X60Qx_960 = podOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
          if (X60Qx_960){
            NI32 X60Qx_961 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_962 = len_4_sysvq0asl(sig_0.ret_0);
            NI32 X60Qx_963 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
            );
            NI32 X60Qx_964 = len_4_sysvq0asl(call_0);
            NI32 X60Qx_965 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_139 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_961 + X60Qx_962)) + X60Qx_963)) + X60Qx_964)) + X60Qx_965)));
            add_2_sysvq0asl((&X60Qdesugar_139), (string_0_sysvq0asl){
              .bytes_0 = 2105346u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_139), sig_0.ret_0);
            add_2_sysvq0asl((&X60Qdesugar_139), (string_0_sysvq0asl){
              .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_139), call_0);
            add_2_sysvq0asl((&X60Qdesugar_139), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_42), X60Qdesugar_139);
            add_2_sysvq0asl((&result_42), owned_1);
            string_0_sysvq0asl X60Qdesugar_140 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
            NI32 X60Qx_966 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I15878504505370534443_aow7lb5cq1)}
            );
            NI32 X60Qx_967 = len_4_sysvq0asl(X60Qdesugar_140);
            NI32 X60Qx_968 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 572534014u, .more_0 = (&strlit_0_I17578962040280315901_aow7lb5cq1)}
            );
            string_0_sysvq0asl X60Qdesugar_141 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_966 + X60Qx_967)) + X60Qx_968)));
            add_2_sysvq0asl((&X60Qdesugar_141), (string_0_sysvq0asl){
              .bytes_0 = 1595941118u, .more_0 = (&strlit_0_I15878504505370534443_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_141), X60Qdesugar_140);
            add_2_sysvq0asl((&X60Qdesugar_141), (string_0_sysvq0asl){
              .bytes_0 = 572534014u, .more_0 = (&strlit_0_I17578962040280315901_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&result_42), X60Qdesugar_141);
            string_0_sysvq0asl X60Qdesugar_142 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
            string_0_sysvq0asl X60Qdesugar_143 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
            NI32 X60Qx_969 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
            );
            NI32 X60Qx_970 = len_4_sysvq0asl(X60Qdesugar_142);
            NI32 X60Qx_971 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
            );
            NI32 X60Qx_972 = len_4_sysvq0asl(X60Qdesugar_143);
            NI32 X60Qx_973 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_144 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_969 + X60Qx_970)) + X60Qx_971)) + X60Qx_972)) + X60Qx_973)));
            add_2_sysvq0asl((&X60Qdesugar_144), (string_0_sysvq0asl){
              .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_144), X60Qdesugar_142);
            add_2_sysvq0asl((&X60Qdesugar_144), (string_0_sysvq0asl){
              .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_144), X60Qdesugar_143);
            add_2_sysvq0asl((&X60Qdesugar_144), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_42), X60Qdesugar_144);
            string_0_sysvq0asl X60Qdesugar_145 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
            NI32 X60Qx_974 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I5036188731385662161_aow7lb5cq1)}
            );
            NI32 X60Qx_975 = len_4_sysvq0asl(X60Qdesugar_145);
            NI32 X60Qx_976 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 171649283u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_146 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_974 + X60Qx_975)) + X60Qx_976)));
            add_2_sysvq0asl((&X60Qdesugar_146), (string_0_sysvq0asl){
              .bytes_0 = 1830822142u, .more_0 = (&strlit_0_I5036188731385662161_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_146), X60Qdesugar_145);
            add_2_sysvq0asl((&X60Qdesugar_146), (string_0_sysvq0asl){
              .bytes_0 = 171649283u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_42), X60Qdesugar_146);
            add_2_sysvq0asl((&result_42), writeback_0);
            string_0_sysvq0asl X60Qdesugar_147 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
            NI32 X60Qx_977 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
            );
            NI32 X60Qx_978 = len_4_sysvq0asl(X60Qdesugar_147);
            NI32 X60Qx_979 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_148 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_977 + X60Qx_978)) + X60Qx_979)));
            add_2_sysvq0asl((&X60Qdesugar_148), (string_0_sysvq0asl){
              .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
            );
            add_2_sysvq0asl((&X60Qdesugar_148), X60Qdesugar_147);
            add_2_sysvq0asl((&X60Qdesugar_148), (string_0_sysvq0asl){
              .bytes_0 = 670466u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&result_42), X60Qdesugar_148);
            nimStrDestroy(X60Qdesugar_148);
            nimStrDestroy(X60Qdesugar_147);
            nimStrDestroy(X60Qdesugar_146);
            nimStrDestroy(X60Qdesugar_145);
            nimStrDestroy(X60Qdesugar_144);
            nimStrDestroy(X60Qdesugar_143);
            nimStrDestroy(X60Qdesugar_142);
            nimStrDestroy(X60Qdesugar_141);
            nimStrDestroy(X60Qdesugar_140);
            nimStrDestroy(X60Qdesugar_139);}
          else {
            NB8 X60Qx_980 = floatOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
            if (X60Qx_980){
              NI32 X60Qx_981 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_982 = len_4_sysvq0asl(sig_0.ret_0);
              NI32 X60Qx_983 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
              );
              NI32 X60Qx_984 = len_4_sysvq0asl(call_0);
              NI32 X60Qx_985 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_149 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_981 + X60Qx_982)) + X60Qx_983)) + X60Qx_984)) + X60Qx_985)));
              add_2_sysvq0asl((&X60Qdesugar_149), (string_0_sysvq0asl){
                .bytes_0 = 2105346u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_149), sig_0.ret_0);
              add_2_sysvq0asl((&X60Qdesugar_149), (string_0_sysvq0asl){
                .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_149), call_0);
              add_2_sysvq0asl((&X60Qdesugar_149), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_149);
              add_2_sysvq0asl((&result_42), owned_1);
              string_0_sysvq0asl X60Qdesugar_150 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
              string_0_sysvq0asl X60Qdesugar_151 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
              NI32 X60Qx_986 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
              );
              NI32 X60Qx_987 = len_4_sysvq0asl(X60Qdesugar_150);
              NI32 X60Qx_988 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
              );
              NI32 X60Qx_989 = len_4_sysvq0asl(X60Qdesugar_151);
              NI32 X60Qx_990 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_152 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_986 + X60Qx_987)) + X60Qx_988)) + X60Qx_989)) + X60Qx_990)));
              add_2_sysvq0asl((&X60Qdesugar_152), (string_0_sysvq0asl){
                .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_152), X60Qdesugar_150);
              add_2_sysvq0asl((&X60Qdesugar_152), (string_0_sysvq0asl){
                .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_152), X60Qdesugar_151);
              add_2_sysvq0asl((&X60Qdesugar_152), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_152);
              string_0_sysvq0asl X60Qdesugar_153 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
              NI32 X60Qx_991 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I9629254699824304600_aow7lb5cq1)}
              );
              NI32 X60Qx_992 = len_4_sysvq0asl(X60Qdesugar_153);
              NI32 X60Qx_993 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 171649283u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_154 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_991 + X60Qx_992)) + X60Qx_993)));
              add_2_sysvq0asl((&X60Qdesugar_154), (string_0_sysvq0asl){
                .bytes_0 = 2065703166u, .more_0 = (&strlit_0_I9629254699824304600_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_154), X60Qdesugar_153);
              add_2_sysvq0asl((&X60Qdesugar_154), (string_0_sysvq0asl){
                .bytes_0 = 171649283u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_154);
              string_0_sysvq0asl X60Qdesugar_155 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
              NI32 X60Qx_994 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10542844442866812539_aow7lb5cq1)}
              );
              NI32 X60Qx_995 = len_4_sysvq0asl(X60Qdesugar_155);
              NI32 X60Qx_996 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 673197310u, .more_0 = (&strlit_0_I10562638173522793194_aow7lb5cq1)}
              );
              string_0_sysvq0asl X60Qdesugar_156 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_994 + X60Qx_995)) + X60Qx_996)));
              add_2_sysvq0asl((&X60Qdesugar_156), (string_0_sysvq0asl){
                .bytes_0 = 538976510u, .more_0 = (&strlit_0_I10542844442866812539_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_156), X60Qdesugar_155);
              add_2_sysvq0asl((&X60Qdesugar_156), (string_0_sysvq0asl){
                .bytes_0 = 673197310u, .more_0 = (&strlit_0_I10562638173522793194_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_156);
              add_2_sysvq0asl((&result_42), writeback_0);
              string_0_sysvq0asl X60Qdesugar_157 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
              NI32 X60Qx_997 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
              );
              NI32 X60Qx_998 = len_4_sysvq0asl(X60Qdesugar_157);
              NI32 X60Qx_999 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_158 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_997 + X60Qx_998)) + X60Qx_999)));
              add_2_sysvq0asl((&X60Qdesugar_158), (string_0_sysvq0asl){
                .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_158), X60Qdesugar_157);
              add_2_sysvq0asl((&X60Qdesugar_158), (string_0_sysvq0asl){
                .bytes_0 = 670466u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&result_42), X60Qdesugar_158);
              nimStrDestroy(X60Qdesugar_158);
              nimStrDestroy(X60Qdesugar_157);
              nimStrDestroy(X60Qdesugar_156);
              nimStrDestroy(X60Qdesugar_155);
              nimStrDestroy(X60Qdesugar_154);
              nimStrDestroy(X60Qdesugar_153);
              nimStrDestroy(X60Qdesugar_152);
              nimStrDestroy(X60Qdesugar_151);
              nimStrDestroy(X60Qdesugar_150);
              nimStrDestroy(X60Qdesugar_149);}
            else {
              NB8 X60Qx_1000 = enumOk_0_aow7lb5cq1((&(*e_4).d_00.ret_0));
              if (X60Qx_1000){
                NI32 X60Qx_1001 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                NI32 X60Qx_1002 = len_4_sysvq0asl(sig_0.ret_0);
                NI32 X60Qx_1003 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
                );
                NI32 X60Qx_1004 = len_4_sysvq0asl(call_0);
                NI32 X60Qx_1005 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_159 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1001 + X60Qx_1002)) + X60Qx_1003)) + X60Qx_1004)) + X60Qx_1005)));
                add_2_sysvq0asl((&X60Qdesugar_159), (string_0_sysvq0asl){
                  .bytes_0 = 2105346u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&X60Qdesugar_159), sig_0.ret_0);
                add_2_sysvq0asl((&X60Qdesugar_159), (string_0_sysvq0asl){
                  .bytes_0 = 1601315070u, .more_0 = (&strlit_0_I10331792544921969752_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_159), call_0);
                add_2_sysvq0asl((&X60Qdesugar_159), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_159);
                add_2_sysvq0asl((&result_42), owned_1);
                string_0_sysvq0asl X60Qdesugar_160 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                string_0_sysvq0asl X60Qdesugar_161 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                NI32 X60Qx_1006 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
                );
                NI32 X60Qx_1007 = len_4_sysvq0asl(X60Qdesugar_160);
                NI32 X60Qx_1008 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
                );
                NI32 X60Qx_1009 = len_4_sysvq0asl(X60Qdesugar_161);
                NI32 X60Qx_1010 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_162 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1006 + X60Qx_1007)) + X60Qx_1008)) + X60Qx_1009)) + X60Qx_1010)));
                add_2_sysvq0asl((&X60Qdesugar_162), (string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_162), X60Qdesugar_160);
                add_2_sysvq0asl((&X60Qdesugar_162), (string_0_sysvq0asl){
                  .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_162), X60Qdesugar_161);
                add_2_sysvq0asl((&X60Qdesugar_162), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_162);
                add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
                  .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I5435985303747042468_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&result_42), writeback_0);
                string_0_sysvq0asl X60Qdesugar_163 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                NI32 X60Qx_1011 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
                );
                NI32 X60Qx_1012 = len_4_sysvq0asl(X60Qdesugar_163);
                NI32 X60Qx_1013 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_164 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1011 + X60Qx_1012)) + X60Qx_1013)));
                add_2_sysvq0asl((&X60Qdesugar_164), (string_0_sysvq0asl){
                  .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_164), X60Qdesugar_163);
                add_2_sysvq0asl((&X60Qdesugar_164), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_164);
                nimStrDestroy(X60Qdesugar_164);
                nimStrDestroy(X60Qdesugar_163);
                nimStrDestroy(X60Qdesugar_162);
                nimStrDestroy(X60Qdesugar_161);
                nimStrDestroy(X60Qdesugar_160);
                nimStrDestroy(X60Qdesugar_159);}
              else {
                NI32 X60Qx_1014 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I15987315423624941794_aow7lb5cq1)}
                );
                NI32 X60Qx_1015 = len_4_sysvq0asl(call_0);
                NI32 X60Qx_1016 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_165 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1014 + X60Qx_1015)) + X60Qx_1016)));
                add_2_sysvq0asl((&X60Qdesugar_165), (string_0_sysvq0asl){
                  .bytes_0 = 1814044926u, .more_0 = (&strlit_0_I15987315423624941794_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_165), call_0);
                add_2_sysvq0asl((&X60Qdesugar_165), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_165);
                add_2_sysvq0asl((&result_42), owned_1);
                string_0_sysvq0asl X60Qdesugar_166 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                string_0_sysvq0asl X60Qdesugar_167 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                NI32 X60Qx_1017 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
                );
                NI32 X60Qx_1018 = len_4_sysvq0asl(X60Qdesugar_166);
                NI32 X60Qx_1019 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
                );
                NI32 X60Qx_1020 = len_4_sysvq0asl(X60Qdesugar_167);
                NI32 X60Qx_1021 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_168 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1017 + X60Qx_1018)) + X60Qx_1019)) + X60Qx_1020)) + X60Qx_1021)));
                add_2_sysvq0asl((&X60Qdesugar_168), (string_0_sysvq0asl){
                  .bytes_0 = 1763713278u, .more_0 = (&strlit_0_I10937820481528361631_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_168), X60Qdesugar_166);
                add_2_sysvq0asl((&X60Qdesugar_168), (string_0_sysvq0asl){
                  .bytes_0 = 1914710526u, .more_0 = (&strlit_0_I9204300727068638698_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_168), X60Qdesugar_167);
                add_2_sysvq0asl((&X60Qdesugar_168), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_168);
                string_0_sysvq0asl X60Qdesugar_169 = dollarQ_2_sysvq0asl((*e_4).d_00.ret_0.wireSize_0);
                NI32 X60Qx_1022 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I5946066183656141387_aow7lb5cq1)}
                );
                NI32 X60Qx_1023 = len_4_sysvq0asl(X60Qdesugar_169);
                NI32 X60Qx_1024 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914711294u, .more_0 = (&strlit_0_I6448058756119716242_aow7lb5cq1)}
                );
                string_0_sysvq0asl X60Qdesugar_170 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1022 + X60Qx_1023)) + X60Qx_1024)));
                add_2_sysvq0asl((&X60Qdesugar_170), (string_0_sysvq0asl){
                  .bytes_0 = 1629495550u, .more_0 = (&strlit_0_I5946066183656141387_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_170), X60Qdesugar_169);
                add_2_sysvq0asl((&X60Qdesugar_170), (string_0_sysvq0asl){
                  .bytes_0 = 1914711294u, .more_0 = (&strlit_0_I6448058756119716242_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_170);
                add_2_sysvq0asl((&result_42), writeback_0);
                string_0_sysvq0asl X60Qdesugar_171 = dollarQ_2_sysvq0asl((*e_4).d_00.outSize_0);
                NI32 X60Qx_1025 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
                );
                NI32 X60Qx_1026 = len_4_sysvq0asl(X60Qdesugar_171);
                NI32 X60Qx_1027 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                string_0_sysvq0asl X60Qdesugar_172 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1025 + X60Qx_1026)) + X60Qx_1027)));
                add_2_sysvq0asl((&X60Qdesugar_172), (string_0_sysvq0asl){
                  .bytes_0 = 1914708222u, .more_0 = (&strlit_0_I10167060501195745097_aow7lb5cq1)}
                );
                add_2_sysvq0asl((&X60Qdesugar_172), X60Qdesugar_171);
                add_2_sysvq0asl((&X60Qdesugar_172), (string_0_sysvq0asl){
                  .bytes_0 = 670466u, .more_0 = NIM_NIL}
                );
                add_2_sysvq0asl((&result_42), X60Qdesugar_172);
                nimStrDestroy(X60Qdesugar_172);
                nimStrDestroy(X60Qdesugar_171);
                nimStrDestroy(X60Qdesugar_170);
                nimStrDestroy(X60Qdesugar_169);
                nimStrDestroy(X60Qdesugar_168);
                nimStrDestroy(X60Qdesugar_167);
                nimStrDestroy(X60Qdesugar_166);
                nimStrDestroy(X60Qdesugar_165);}}}}}}}
  add_2_sysvq0asl((&result_42), (string_0_sysvq0asl){
    .bytes_0 = 687362u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(writeback_0);
  nimStrDestroy(owned_1);
  nimStrDestroy(call_0);
  nimStrDestroy(X60Qdesugar_77);
  nimStrDestroy(X60Qdesugar_76);
  return result_42;
  nimStrDestroy(writeback_0);
  nimStrDestroy(owned_1);
  nimStrDestroy(call_0);
  nimStrDestroy(X60Qdesugar_77);
  nimStrDestroy(X60Qdesugar_76);
  return result_42;}
string_0_sysvq0asl aowlcBin_0_aow7lb5cq1(void){
  string_0_sysvq0asl result_43;
  nimStrWasMoved((&result_43));
  nimStrDestroy(result_43);
  string_0_sysvq0asl X60Qx_1028 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I13635149261874571511_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  result_43 = X60Qx_1028;
  NI32 X60Qx_1029 = len_4_sysvq0asl(result_43);
  if (X60Qx_1029 == 0){
    nimStrDestroy(result_43);
    string_0_sysvq0asl X60Qtmp_35 = getHomeDir_0_osalirkw71();
    string_0_sysvq0asl X60Qtmp_34 = slashQ_0_ospaexnw61(X60Qtmp_35, (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I2994922137697771110_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qtmp_33 = slashQ_0_ospaexnw61(X60Qtmp_34, (string_0_sysvq0asl){
      .bytes_0 = 1852400131u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qx_1030 = slashQ_0_ospaexnw61(X60Qtmp_33, (string_0_sysvq0asl){
      .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I2994922137697771110_aow7lb5cq1)}
    );
    result_43 = X60Qx_1030;
    nimStrDestroy(X60Qtmp_33);
    nimStrDestroy(X60Qtmp_34);
    nimStrDestroy(X60Qtmp_35);}
  return result_43;}
string_0_sysvq0asl moduleSuffix_0_aow7lb5cq1(string_0_sysvq0asl path_0){
  string_0_sysvq0asl result_44;
  nimStrWasMoved((&result_44));
  nimStrDestroy(result_44);
  string_0_sysvq0asl X60Qx_1031 = extractFilename_0_ospaexnw61(path_0);
  result_44 = X60Qx_1031;
  NB8 X60Qx_32;
  NI32 X60Qx_1032 = len_4_sysvq0asl(result_44);
  if (6 < X60Qx_1032){
    NB8 X60Qx_33;
    NI32 X60Qx_1033 = len_4_sysvq0asl(result_44);
    NI32 X60Qx_1034 = len_4_sysvq0asl(result_44);
    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1035 = ___1_Iclcqmw1_aow7lb5cq1(((NI32)(X60Qx_1033 - 6)), ((NI32)(X60Qx_1034 - 1)));
    string_0_sysvq0asl X60Qtmp_36 = getQ_14_sysvq0asl(result_44, X60Qx_1035);
    NB8 X60Qx_1036 = eqQ_20_sysvq0asl(X60Qtmp_36, (string_0_sysvq0asl){
      .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17410079638349000741_aow7lb5cq1)}
    );
    if (X60Qx_1036){
      X60Qx_33 = NIM_TRUE;}
    else {
      NI32 X60Qx_1037 = len_4_sysvq0asl(result_44);
      NI32 X60Qx_1038 = len_4_sysvq0asl(result_44);
      HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1039 = ___1_Iclcqmw1_aow7lb5cq1(((NI32)(X60Qx_1037 - 6)), ((NI32)(X60Qx_1038 - 1)));
      string_0_sysvq0asl X60Qtmp_37 = getQ_14_sysvq0asl(result_44, X60Qx_1039);
      NB8 X60Qx_1040 = eqQ_20_sysvq0asl(X60Qtmp_37, (string_0_sysvq0asl){
        .bytes_0 = 779628286u, .more_0 = (&strlit_0_I14570291026200354739_aow7lb5cq1)}
      );
      X60Qx_33 = X60Qx_1040;
      nimStrDestroy(X60Qtmp_37);}
    X60Qx_32 = X60Qx_33;
    nimStrDestroy(X60Qtmp_36);}
  else {
    X60Qx_32 = NIM_FALSE;}
  if (X60Qx_32){
    NI32 X60Qx_1041 = len_4_sysvq0asl(result_44);
    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1042 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_1041 - 7)));
    string_0_sysvq0asl X60Qlhs_38 = getQ_14_sysvq0asl(result_44, X60Qx_1042);
    nimStrDestroy(result_44);
    result_44 = X60Qlhs_38;}
  return result_44;}
NB8 gccSharedMany_0_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 cpaths_0, string_0_sysvq0asl soPath_0, string_0_sysvq0asl logFile_0){
  NB8 result_47;
  string_0_sysvq0asl cmd_0 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I7830052811571726362_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 1752378878u, .more_0 = (&strlit_0_I10506424120731942949_aow7lb5cq1)}
  );
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_14 = toOpenArray_1_I6b60gk1_aow7lb5cq1(cpaths_0);
    NI32 X60Qlf_15 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1071 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_14);
        if (X60Qlf_15 < X60Qx_1071){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_14, X60Qlf_15);
            string_0_sysvq0asl X60Qtmp_41 = quoteShell_0_oswd7dmm((*X60Qii_2));
            string_0_sysvq0asl X60Qtmp_40 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            , X60Qtmp_41);
            add_2_sysvq0asl((&cmd_0), X60Qtmp_40);
            nimStrDestroy(X60Qtmp_40);
            nimStrDestroy(X60Qtmp_41);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_15));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl X60Qdesugar_173 = quoteShell_0_oswd7dmm(soPath_0);
  string_0_sysvq0asl X60Qdesugar_174 = quoteShell_0_oswd7dmm(logFile_0);
  NI32 X60Qx_1072 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  NI32 X60Qx_1073 = len_4_sysvq0asl(X60Qdesugar_173);
  NI32 X60Qx_1074 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  NI32 X60Qx_1075 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1076 = len_4_sysvq0asl(X60Qdesugar_174);
  NI32 X60Qx_1077 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_175 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1072 + X60Qx_1073)) + X60Qx_1074)) + X60Qx_1075)) + X60Qx_1076)) + X60Qx_1077)));
  add_2_sysvq0asl((&X60Qdesugar_175), (string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_175), X60Qdesugar_173);
  add_2_sysvq0asl((&X60Qdesugar_175), (string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_175), (string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_175), X60Qdesugar_174);
  add_2_sysvq0asl((&X60Qdesugar_175), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&cmd_0), X60Qdesugar_175);
  NI32 X60Qx_1078 = execShellCmd_0_oswd7dmm(cmd_0);
  result_47 = (X60Qx_1078 == 0);
  nimStrDestroy(X60Qdesugar_175);
  nimStrDestroy(X60Qdesugar_174);
  nimStrDestroy(X60Qdesugar_173);
  nimStrDestroy(cmd_0);
  return result_47;
  nimStrDestroy(X60Qdesugar_175);
  nimStrDestroy(X60Qdesugar_174);
  nimStrDestroy(X60Qdesugar_173);
  nimStrDestroy(cmd_0);
  return result_47;}
NB8 gccShared_0_aow7lb5cq1(string_0_sysvq0asl cpath_0, string_0_sysvq0asl soPath_1, string_0_sysvq0asl logFile_1){
  NB8 result_48;
  string_0_sysvq0asl X60Qdesugar_176 = quoteShell_0_oswd7dmm(cpath_0);
  string_0_sysvq0asl X60Qdesugar_177 = quoteShell_0_oswd7dmm(soPath_1);
  string_0_sysvq0asl X60Qdesugar_178 = quoteShell_0_oswd7dmm(logFile_1);
  NI32 X60Qx_1079 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I7830052811571726362_aow7lb5cq1)}
  );
  NI32 X60Qx_1080 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1752378878u, .more_0 = (&strlit_0_I10506424120731942949_aow7lb5cq1)}
  );
  NI32 X60Qx_1081 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1082 = len_4_sysvq0asl(X60Qdesugar_176);
  NI32 X60Qx_1083 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  NI32 X60Qx_1084 = len_4_sysvq0asl(X60Qdesugar_177);
  NI32 X60Qx_1085 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  NI32 X60Qx_1086 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1087 = len_4_sysvq0asl(X60Qdesugar_178);
  NI32 X60Qx_1088 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_179 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1079 + X60Qx_1080)) + X60Qx_1081)) + X60Qx_1082)) + X60Qx_1083)) + X60Qx_1084)) + X60Qx_1085)) + X60Qx_1086)) + X60Qx_1087)) + X60Qx_1088)));
  add_2_sysvq0asl((&X60Qdesugar_179), (string_0_sysvq0asl){
    .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I7830052811571726362_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_179), (string_0_sysvq0asl){
    .bytes_0 = 1752378878u, .more_0 = (&strlit_0_I10506424120731942949_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_179), (string_0_sysvq0asl){
    .bytes_0 = 8193u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_179), X60Qdesugar_176);
  add_2_sysvq0asl((&X60Qdesugar_179), (string_0_sysvq0asl){
    .bytes_0 = 1865228542u, .more_0 = (&strlit_0_I2123011150024992218_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_179), X60Qdesugar_177);
  add_2_sysvq0asl((&X60Qdesugar_179), (string_0_sysvq0asl){
    .bytes_0 = 1814896894u, .more_0 = (&strlit_0_I14743647238960953227_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_179), (string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_179), X60Qdesugar_178);
  add_2_sysvq0asl((&X60Qdesugar_179), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  NI32 X60Qx_1089 = execShellCmd_0_oswd7dmm(X60Qdesugar_179);
  result_48 = (X60Qx_1089 == 0);
  nimStrDestroy(X60Qdesugar_179);
  nimStrDestroy(X60Qdesugar_178);
  nimStrDestroy(X60Qdesugar_177);
  nimStrDestroy(X60Qdesugar_176);
  return result_48;
  nimStrDestroy(X60Qdesugar_179);
  nimStrDestroy(X60Qdesugar_178);
  nimStrDestroy(X60Qdesugar_177);
  nimStrDestroy(X60Qdesugar_176);
  return result_48;}
string_0_sysvq0asl buildShimsC_0_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 entries_0, string_0_sysvq0asl cnifDir_0, string_0_sysvq0asl buildDir_0, seq_0_Igzebks_aow7lb5cq1* shimmed_0){
  string_0_sysvq0asl result_49;
  nimStrWasMoved((&result_49));
  nimStrDestroy(result_49);
  result_49 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  eQdestroy_1_Iytr7x_aow7lb5cq1((*shimmed_0));
  seq_0_Igzebks_aow7lb5cq1 X60Qx_1090 = newSeqUninit_0_I6ffb0e1_aow7lb5cq1(0);
  (*shimmed_0) = X60Qx_1090;
  NI32 X60Qx_1091 = len_3_I44vue3_aow7lb5cq1(entries_0);
  if (X60Qx_1091 == 0){
    return result_49;}
  string_0_sysvq0asl X60Qtmp_42 = shMkdirP_0_hos14g919(buildDir_0);
  NI32 X60Qx_1092 = execShellCmd_0_oswd7dmm(X60Qtmp_42);
  string_0_sysvq0asl cFile_0 = slashQ_0_ospaexnw61(buildDir_0, (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I11438303454518475359_aow7lb5cq1)}
  );
  string_0_sysvq0asl logFile_2 = slashQ_0_ospaexnw61(buildDir_0, (string_0_sysvq0asl){
    .bytes_0 = 1769300734u, .more_0 = (&strlit_0_I1947988348543698404_aow7lb5cq1)}
  );
  string_0_sysvq0asl listFile_0 = slashQ_0_ospaexnw61(buildDir_0, (string_0_sysvq0asl){
    .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I9032354697946540937_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_180 = quoteShell_0_oswd7dmm(cnifDir_0);
  string_0_sysvq0asl X60Qdesugar_181 = quoteShell_0_oswd7dmm(cnifDir_0);
  NI32 X60Qx_1093 = len_4_sysvq0asl(X60Qdesugar_180);
  NI32 X60Qx_1094 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 774516734u, .more_0 = (&strlit_0_I14177207265498126630_aow7lb5cq1)}
  );
  NI32 X60Qx_1095 = len_4_sysvq0asl(X60Qdesugar_181);
  NI32 X60Qx_1096 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 791293950u, .more_0 = (&strlit_0_I267845865139732674_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_182 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1093 + X60Qx_1094)) + X60Qx_1095)) + X60Qx_1096)));
  add_2_sysvq0asl((&X60Qdesugar_182), X60Qdesugar_180);
  add_2_sysvq0asl((&X60Qdesugar_182), (string_0_sysvq0asl){
    .bytes_0 = 774516734u, .more_0 = (&strlit_0_I14177207265498126630_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_182), X60Qdesugar_181);
  add_2_sysvq0asl((&X60Qdesugar_182), (string_0_sysvq0asl){
    .bytes_0 = 791293950u, .more_0 = (&strlit_0_I267845865139732674_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qtmp_43 = shListInto_0_hos14g919(X60Qdesugar_182, listFile_0);
  NI32 X60Qx_1097 = execShellCmd_0_oswd7dmm(X60Qtmp_43);
  seq_0_Ixdx2fh1_aow7lb5cq1 cmods_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  {
    string_0_sysvq0asl X60Qlf_16 = listFile_0;
    FILE* X60Qlf_17;
    NB8 X60Qx_1098 = open_0_syn1lfpjv((&X60Qlf_17), X60Qlf_16, 0, -1);
    if (X60Qx_1098){
      string_0_sysvq0asl X60Qlf_18 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      {
        while (NIM_TRUE){
          NB8 X60Qx_1099 = readLine_0_syn1lfpjv(X60Qlf_17, (&X60Qlf_18));
          if (X60Qx_1099){
            {
              string_0_sysvq0asl X60Qii_2 = nimStrDup(X60Qlf_18);
              while (NIM_TRUE){
                NB8 X60Qx_1100;
                NI32 X60Qx_1101 = len_4_sysvq0asl(X60Qii_2);
                if (0 < X60Qx_1101){
                  NB8 X60Qx_1102;
                  NB8 X60Qx_1103;
                  NI32 X60Qx_1104 = len_4_sysvq0asl(X60Qii_2);
                  NC8 X60Qx_1105 = getQ_9_sysvq0asl(X60Qii_2, ((NI32)(X60Qx_1104 - 1)));
                  if (X60Qx_1105 == (NC8)'\012'){
                    X60Qx_1103 = NIM_TRUE;}
                  else {
                    NI32 X60Qx_1106 = len_4_sysvq0asl(X60Qii_2);
                    NC8 X60Qx_1107 = getQ_9_sysvq0asl(X60Qii_2, ((NI32)(X60Qx_1106 - 1)));
                    X60Qx_1103 = (X60Qx_1107 == (NC8)'\015');}
                  if (X60Qx_1103){
                    X60Qx_1102 = NIM_TRUE;}
                  else {
                    NI32 X60Qx_1108 = len_4_sysvq0asl(X60Qii_2);
                    NC8 X60Qx_1109 = getQ_9_sysvq0asl(X60Qii_2, ((NI32)(X60Qx_1108 - 1)));
                    X60Qx_1102 = (X60Qx_1109 == (NC8)' ');}
                  X60Qx_1100 = X60Qx_1102;}
                else {
                  X60Qx_1100 = NIM_FALSE;}
                if (X60Qx_1100){
                  NI32 X60Qx_1110 = len_4_sysvq0asl(X60Qii_2);
                  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1111 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_1110 - 2)));
                  string_0_sysvq0asl X60Qlhs_44 = getQ_14_sysvq0asl(X60Qii_2, X60Qx_1111);
                  nimStrDestroy(X60Qii_2);
                  X60Qii_2 = X60Qlhs_44;}
                else {
                  break;}}
              NI32 X60Qx_1112 = len_4_sysvq0asl(X60Qii_2);
              if (0 < X60Qx_1112){
                string_0_sysvq0asl X60Qtmp_45 = X60Qii_2;
                nimStrWasMoved((&X60Qii_2));
                add_0_Ig6072n_aow7lb5cq1((&cmods_0), X60Qtmp_45);}
              nimStrDestroy(X60Qii_2);}}
          else {
            break;}}}
      whileStmtLabel_1: ;
      NI32 X60Qx_1113 = fclose(X60Qlf_17);
      nimStrDestroy(X60Qlf_18);}}
  forStmtLabel_0: ;
  if (NIM_FALSE){
    X60Qexlab_0: ;}
  NI32 X60Qx_1114 = len_3_Ixq6taz_aow7lb5cq1(cmods_0);
  if (X60Qx_1114 == 0){
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
  string_0_sysvq0asl X60Qtmp_46 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I18192332346447245389_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 wantPreDce_0 = eqQ_20_sysvq0asl(X60Qtmp_46, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  seq_0_Ixdx2fh1_aow7lb5cq1 xmods_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  if (wantPreDce_0){
    string_0_sysvq0asl xListFile_0 = slashQ_0_ospaexnw61(buildDir_0, (string_0_sysvq0asl){
      .bytes_0 = 1869445374u, .more_0 = (&strlit_0_I7475120879548367157_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_183 = quoteShell_0_oswd7dmm(cnifDir_0);
    string_0_sysvq0asl X60Qdesugar_184 = quoteShell_0_oswd7dmm(cnifDir_0);
    NI32 X60Qx_1115 = len_4_sysvq0asl(X60Qdesugar_183);
    NI32 X60Qx_1116 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 774516734u, .more_0 = (&strlit_0_I18095216927531186533_aow7lb5cq1)}
    );
    NI32 X60Qx_1117 = len_4_sysvq0asl(X60Qdesugar_184);
    NI32 X60Qx_1118 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791293950u, .more_0 = (&strlit_0_I16254858060766665859_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_185 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1115 + X60Qx_1116)) + X60Qx_1117)) + X60Qx_1118)));
    add_2_sysvq0asl((&X60Qdesugar_185), X60Qdesugar_183);
    add_2_sysvq0asl((&X60Qdesugar_185), (string_0_sysvq0asl){
      .bytes_0 = 774516734u, .more_0 = (&strlit_0_I18095216927531186533_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_185), X60Qdesugar_184);
    add_2_sysvq0asl((&X60Qdesugar_185), (string_0_sysvq0asl){
      .bytes_0 = 791293950u, .more_0 = (&strlit_0_I16254858060766665859_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qtmp_47 = shListInto_0_hos14g919(X60Qdesugar_185, xListFile_0);
    NI32 X60Qx_1119 = execShellCmd_0_oswd7dmm(X60Qtmp_47);
    {
      string_0_sysvq0asl X60Qlf_19 = xListFile_0;
      FILE* X60Qlf_20;
      NB8 X60Qx_1120 = open_0_syn1lfpjv((&X60Qlf_20), X60Qlf_19, 0, -1);
      if (X60Qx_1120){
        string_0_sysvq0asl X60Qlf_21 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;
        {
          while (NIM_TRUE){
            NB8 X60Qx_1121 = readLine_0_syn1lfpjv(X60Qlf_20, (&X60Qlf_21));
            if (X60Qx_1121){
              {
                string_0_sysvq0asl X60Qii_5 = nimStrDup(X60Qlf_21);
                while (NIM_TRUE){
                  NB8 X60Qx_1122;
                  NI32 X60Qx_1123 = len_4_sysvq0asl(X60Qii_5);
                  if (0 < X60Qx_1123){
                    NB8 X60Qx_1124;
                    NB8 X60Qx_1125;
                    NI32 X60Qx_1126 = len_4_sysvq0asl(X60Qii_5);
                    NC8 X60Qx_1127 = getQ_9_sysvq0asl(X60Qii_5, ((NI32)(X60Qx_1126 - 1)));
                    if (X60Qx_1127 == (NC8)'\012'){
                      X60Qx_1125 = NIM_TRUE;}
                    else {
                      NI32 X60Qx_1128 = len_4_sysvq0asl(X60Qii_5);
                      NC8 X60Qx_1129 = getQ_9_sysvq0asl(X60Qii_5, ((NI32)(X60Qx_1128 - 1)));
                      X60Qx_1125 = (X60Qx_1129 == (NC8)'\015');}
                    if (X60Qx_1125){
                      X60Qx_1124 = NIM_TRUE;}
                    else {
                      NI32 X60Qx_1130 = len_4_sysvq0asl(X60Qii_5);
                      NC8 X60Qx_1131 = getQ_9_sysvq0asl(X60Qii_5, ((NI32)(X60Qx_1130 - 1)));
                      X60Qx_1124 = (X60Qx_1131 == (NC8)' ');}
                    X60Qx_1122 = X60Qx_1124;}
                  else {
                    X60Qx_1122 = NIM_FALSE;}
                  if (X60Qx_1122){
                    NI32 X60Qx_1132 = len_4_sysvq0asl(X60Qii_5);
                    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1133 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_1132 - 2)));
                    string_0_sysvq0asl X60Qlhs_48 = getQ_14_sysvq0asl(X60Qii_5, X60Qx_1133);
                    nimStrDestroy(X60Qii_5);
                    X60Qii_5 = X60Qlhs_48;}
                  else {
                    break;}}
                NI32 X60Qx_1134 = len_4_sysvq0asl(X60Qii_5);
                if (0 < X60Qx_1134){
                  string_0_sysvq0asl X60Qtmp_49 = X60Qii_5;
                  nimStrWasMoved((&X60Qii_5));
                  add_0_Ig6072n_aow7lb5cq1((&xmods_0), X60Qtmp_49);}
                nimStrDestroy(X60Qii_5);}}
            else {
              break;}}}
        whileStmtLabel_4: ;
        NI32 X60Qx_1135 = fclose(X60Qlf_20);
        nimStrDestroy(X60Qlf_21);}}
    forStmtLabel_3: ;
    if (NIM_FALSE){
      X60Qexlab_1: ;}
    string_0_sysvq0asl X60Qtmp_50 = shRmF_0_hos14g919(xListFile_0);
    NI32 X60Qx_1136 = execShellCmd_0_oswd7dmm(X60Qtmp_50);
    nimStrDestroy(X60Qtmp_50);
    nimStrDestroy(X60Qtmp_47);
    nimStrDestroy(X60Qdesugar_185);
    nimStrDestroy(X60Qdesugar_184);
    nimStrDestroy(X60Qdesugar_183);
    nimStrDestroy(xListFile_0);}
  NB8 X60Qx_1137;
  if (0 < xmods_0.len_0){
    X60Qx_1137 = wantPreDce_0;}
  else {
    X60Qx_1137 = NIM_FALSE;}
  NB8 usingX_0 = X60Qx_1137;
  string_0_sysvq0asl stageDir_0 = slashQ_0_ospaexnw61(buildDir_0, (string_0_sysvq0asl){
    .bytes_0 = 1768847614u, .more_0 = (&strlit_0_I6141559193247183651_aow7lb5cq1)}
  );
  if (usingX_0){
    string_0_sysvq0asl X60Qtmp_51 = shMkdirP_0_hos14g919(stageDir_0);
    NI32 X60Qx_1138 = execShellCmd_0_oswd7dmm(X60Qtmp_51);
    seq_0_Ixdx2fh1_aow7lb5cq1 staged_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
    NI32 xi_0 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1139 = len_3_Ixq6taz_aow7lb5cq1(xmods_0);
        if (xi_0 < X60Qx_1139){
          string_0_sysvq0asl* X60Qx_1140 = getQ_7_Ir6d0tw_aow7lb5cq1(xmods_0, xi_0);
          string_0_sysvq0asl X60Qtmp_53 = moduleSuffix_0_aow7lb5cq1((*X60Qx_1140));
          string_0_sysvq0asl X60Qtmp_52 = ampQ_0_sysvq0asl(X60Qtmp_53, (string_0_sysvq0asl){
            .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17410079638349000741_aow7lb5cq1)}
          );
          string_0_sysvq0asl dst_1 = slashQ_0_ospaexnw61(stageDir_0, X60Qtmp_52);
          string_0_sysvq0asl* X60Qx_1141 = getQ_7_Ir6d0tw_aow7lb5cq1(xmods_0, xi_0);
          X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_1 = readFile_0_syn1lfpjv((*X60Qx_1141));
          if (X60QcanRaise_1.fld_0){
            goto X60Qexlab_2;}
          ErrorCode_0_sysvq0asl X60QcanRaise_0 = writeFile_0_syn1lfpjv(dst_1, X60QcanRaise_1.fld_1);
          if (X60QcanRaise_0){
            goto X60Qexlab_2;}
          string_0_sysvq0asl X60Qtmp_54 = dst_1;
          nimStrWasMoved((&dst_1));
          add_0_Ig6072n_aow7lb5cq1((&staged_0), X60Qtmp_54);
          if (NIM_FALSE){
            X60Qexlab_2: ;}
          inc_1_I6wjjge_aow2h993l1((&xi_0));
          nimStrDestroy(dst_1);
          nimStrDestroy(X60Qtmp_52);
          nimStrDestroy(X60Qtmp_53);}
        else {
          break;}}}
    whileStmtLabel_6: ;
    NI32 X60Qx_1142 = len_3_Ixq6taz_aow7lb5cq1(staged_0);
    NI32 X60Qx_1143 = len_3_Ixq6taz_aow7lb5cq1(xmods_0);
    if (X60Qx_1142 == X60Qx_1143){
      eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
      xmods_0 = staged_0;
      eQwasMoved_1_I5vdnla_aow7lb5cq1((&staged_0));}
    else {
      usingX_0 = NIM_FALSE;}
    eQdestroy_1_Ivioh0a_aow7lb5cq1(staged_0);
    nimStrDestroy(X60Qtmp_51);}
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_7;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&X60Qx_7));
  if (usingX_0){
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    X60Qx_7 = xmods_0;
    eQwasMoved_1_I5vdnla_aow7lb5cq1((&xmods_0));}
  else {
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    X60Qx_7 = cmods_0;
    eQwasMoved_1_I5vdnla_aow7lb5cq1((&cmods_0));}
  seq_0_Ixdx2fh1_aow7lb5cq1 mods_2 = X60Qx_7;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&X60Qx_7));
  string_0_sysvq0asl X60Qtmp_55 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_1144 = eqQ_20_sysvq0asl(X60Qtmp_55, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  if (X60Qx_1144){
    string_0_sysvq0asl X60Qx_8;
    nimStrWasMoved((&X60Qx_8));
    if (usingX_0){
      nimStrDestroy(X60Qx_8);
      X60Qx_8 = (string_0_sysvq0asl){
        .bytes_0 = 779628286u, .more_0 = (&strlit_0_I17588196217130192428_aow7lb5cq1)}
      ;}
    else {
      nimStrDestroy(X60Qx_8);
      X60Qx_8 = (string_0_sysvq0asl){
        .bytes_0 = 778252030u, .more_0 = (&strlit_0_I17145838109380889823_aow7lb5cq1)}
      ;}
    string_0_sysvq0asl X60Qdesugar_186 = X60Qx_8;
    nimStrWasMoved((&X60Qx_8));
    NI32 X60Qx_1145 = len_3_Ixq6taz_aow7lb5cq1(mods_2);
    string_0_sysvq0asl X60Qdesugar_187 = dollarQ_2_sysvq0asl(X60Qx_1145);
    NI32 X60Qx_1146 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I4565430035092908447_aow7lb5cq1)}
    );
    NI32 X60Qx_1147 = len_4_sysvq0asl(X60Qdesugar_186);
    NI32 X60Qx_1148 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
    );
    NI32 X60Qx_1149 = len_4_sysvq0asl(X60Qdesugar_187);
    NI32 X60Qx_1150 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I17138688373536918376_aow7lb5cq1)}
    );
    string_0_sysvq0asl X60Qdesugar_188 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1146 + X60Qx_1147)) + X60Qx_1148)) + X60Qx_1149)) + X60Qx_1150)));
    add_2_sysvq0asl((&X60Qdesugar_188), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I4565430035092908447_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_188), X60Qdesugar_186);
    add_2_sysvq0asl((&X60Qdesugar_188), (string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_188), X60Qdesugar_187);
    add_2_sysvq0asl((&X60Qdesugar_188), (string_0_sysvq0asl){
      .bytes_0 = 1869422846u, .more_0 = (&strlit_0_I17138688373536918376_aow7lb5cq1)}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_188);
    nimStrDestroy(X60Qdesugar_188);
    nimStrDestroy(X60Qdesugar_187);
    nimStrDestroy(X60Qdesugar_186);
    nimStrDestroy(X60Qx_8);}
  NI32 X60Qx_1151 = len_3_Ixq6taz_aow7lb5cq1(mods_2);
  if (X60Qx_1151 == 0){
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
  string_0_sysvq0asl savedMainDir_0 = nimStrDup(prog_0_prorcx25w1.main_0.dir_0);
  string_0_sysvq0asl* X60Qlhs_56 = (&prog_0_prorcx25w1.main_0.dir_0);
  nimStrDestroy((*X60Qlhs_56));
  string_0_sysvq0asl* X60Qx_1152 = getQ_7_Ir6d0tw_aow7lb5cq1(mods_2, 0);
  string_0_sysvq0asl X60Qx_1153 = parentDir_0_ospaexnw61((*X60Qx_1152));
  (*X60Qlhs_56) = X60Qx_1153;
  seq_0_Ixdx2fh1_aow7lb5cq1 texts_1 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  NI32 i_27 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1154 = len_3_Ixq6taz_aow7lb5cq1(mods_2);
      if (i_27 < X60Qx_1154){
        string_0_sysvq0asl* X60Qx_1155 = getQ_7_Ir6d0tw_aow7lb5cq1(mods_2, i_27);
        TokenBuf_0_nifb6mq6y1 buf_0 = parseFromFile_0_nifb6mq6y1((*X60Qx_1155), 100);
        Cursor_0_nifb6mq6y1 root_0 = beginRead_0_nifb6mq6y1((&buf_0));
        string_0_sysvq0asl X60Qx_1156 = emitModuleBody_0_emi78vuj01((&root_0));
        add_0_Ig6072n_aow7lb5cq1((&texts_1), X60Qx_1156);
        endRead_0_nifb6mq6y1((&buf_0));
        inc_1_I6wjjge_aow2h993l1((&i_27));
        eQdestroy_0_nifb6mq6y1((&root_0));
        eQdestroy_1_nifb6mq6y1((&buf_0));}
      else {
        break;}}}
  whileStmtLabel_7: ;
  string_0_sysvq0asl* X60Qlhs_57 = (&prog_0_prorcx25w1.main_0.dir_0);
  nimStrDestroy((*X60Qlhs_57));
  (*X60Qlhs_57) = savedMainDir_0;
  nimStrWasMoved((&savedMainDir_0));
  string_0_sysvq0asl strT_3 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl longT_3 = (string_0_sysvq0asl){
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
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_22 = toOpenArray_1_I6b60gk1_aow7lb5cq1(texts_1);
    NI32 X60Qlf_23 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1157 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_22);
        if (X60Qlf_23 < X60Qx_1157){
          {
            string_0_sysvq0asl* X60Qii_10 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_22, X60Qlf_23);
            NI32 X60Qx_1158 = len_4_sysvq0asl(strT_3);
            if (X60Qx_1158 == 0){
              nimStrDestroy(strT_3);
              string_0_sysvq0asl X60Qx_1159 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I17605077022815850042_aow7lb5cq1)}
              );
              strT_3 = X60Qx_1159;}
            NI32 X60Qx_1160 = len_4_sysvq0asl(longT_3);
            if (X60Qx_1160 == 0){
              nimStrDestroy(longT_3);
              string_0_sysvq0asl X60Qx_1161 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1852787966u, .more_0 = (&strlit_0_I15230512448378417494_aow7lb5cq1)}
              );
              longT_3 = X60Qx_1161;}
            NI32 X60Qx_1162 = len_4_sysvq0asl(borrowFn_1);
            if (X60Qx_1162 == 0){
              nimStrDestroy(borrowFn_1);
              string_0_sysvq0asl X60Qx_1163 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1919902462u, .more_0 = (&strlit_0_I9467484319694674619_aow7lb5cq1)}
              );
              borrowFn_1 = X60Qx_1163;}
            NI32 X60Qx_1164 = len_4_sysvq0asl(deallocFn_3);
            if (X60Qx_1164 == 0){
              nimStrDestroy(deallocFn_3);
              string_0_sysvq0asl X60Qx_1165 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1634034942u, .more_0 = (&strlit_0_I16718063019512574093_aow7lb5cq1)}
              );
              deallocFn_3 = X60Qx_1165;}
            NI32 X60Qx_1166 = len_4_sysvq0asl(allocFn_2);
            if (X60Qx_1166 == 0){
              nimStrDestroy(allocFn_2);
              string_0_sysvq0asl X60Qx_1167 = typeNameAfter_0_aow7lb5cq1((*X60Qii_10), (string_0_sysvq0asl){
                .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I5607995952013721966_aow7lb5cq1)}
              );
              allocFn_2 = X60Qx_1167;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_23));}
        else {
          break;}}}
    whileStmtLabel_9: ;}
  forStmtLabel_8: ;
  NI32 made_0 = 0;
  NI32 byExact_0 = 0;
  NI32 byBase_0 = 0;
  NI32 noBody_0 = 0;
  NI32 ambiguousMisses_0 = 0;
  {
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_24 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_0);
    NI32 X60Qlf_25 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1168 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_24);
        if (X60Qlf_25 < X60Qx_1168){
          {
            {
              X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_14 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_24, X60Qlf_25);
              NB8 X60Qx_1169 = jitEligible_0_aow7lb5cq1((*X60Qii_14));
              if ((!X60Qx_1169)){
                goto continueLabel_13;}
              NB8 X60Qx_1170;
              NB8 X60Qx_1171 = usesStrings_0_aow7lb5cq1((*X60Qii_14));
              if (X60Qx_1171){
                NB8 X60Qx_1172;
                NB8 X60Qx_1173;
                NI32 X60Qx_1174 = len_4_sysvq0asl(strT_3);
                if (X60Qx_1174 == 0){
                  X60Qx_1173 = NIM_TRUE;}
                else {
                  NI32 X60Qx_1175 = len_4_sysvq0asl(longT_3);
                  X60Qx_1173 = (X60Qx_1175 == 0);}
                if (X60Qx_1173){
                  X60Qx_1172 = NIM_TRUE;}
                else {
                  NI32 X60Qx_1176 = len_4_sysvq0asl(borrowFn_1);
                  X60Qx_1172 = (X60Qx_1176 == 0);}
                X60Qx_1170 = X60Qx_1172;}
              else {
                X60Qx_1170 = NIM_FALSE;}
              if (X60Qx_1170){
                goto continueLabel_13;}
              NB8 X60Qx_1177;
              NB8 X60Qx_1178 = usesSeqs_0_aow7lb5cq1((*X60Qii_14));
              if (X60Qx_1178){
                NB8 X60Qx_1179;
                NI32 X60Qx_1180 = len_4_sysvq0asl(allocFn_2);
                if (X60Qx_1180 == 0){
                  X60Qx_1179 = NIM_TRUE;}
                else {
                  NI32 X60Qx_1181 = len_4_sysvq0asl(deallocFn_3);
                  X60Qx_1179 = (X60Qx_1181 == 0);}
                X60Qx_1177 = X60Qx_1179;}
              else {
                X60Qx_1177 = NIM_FALSE;}
              if (X60Qx_1177){
                goto continueLabel_13;}
              string_0_sysvq0asl X60Qii_15 = aowlcSymName_0_run8hsnpi((*(*X60Qii_14)).d_00.sym_0);
              NI32 X60Qii_16 = -1;
              string_0_sysvq0asl X60Qii_17 = (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              ;
              NI32 X60Qii_18 = 0;
              while (NIM_TRUE){
                NI32 X60Qx_1182 = len_3_Ixq6taz_aow7lb5cq1(texts_1);
                if (X60Qii_18 < X60Qx_1182){
                  NB8 X60Qx_1183;
                  NI32 X60Qx_1184 = len_4_sysvq0asl(X60Qii_15);
                  if (0 < X60Qx_1184){
                    string_0_sysvq0asl* X60Qx_1185 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                    NB8 X60Qx_1186 = definesExactly_0_aow7lb5cq1((*X60Qx_1185), X60Qii_15);
                    X60Qx_1183 = X60Qx_1186;}
                  else {
                    X60Qx_1183 = NIM_FALSE;}
                  if (X60Qx_1183){
                    X60Qii_16 = X60Qii_18;
                    nimStrDestroy(X60Qii_17);
                    string_0_sysvq0asl X60Qx_1187 = nimStrDup(X60Qii_15);
                    X60Qii_17 = X60Qx_1187;
                    break;}
                  inc_1_I6wjjge_aow2h993l1((&X60Qii_18));}
                else {
                  break;}}
              NB8 X60Qx_1188;
              if (X60Qii_16 < 0){
                NI32 X60Qx_1189 = len_4_sysvq0asl(X60Qii_15);
                X60Qx_1188 = (X60Qx_1189 == 0);}
              else {
                X60Qx_1188 = NIM_FALSE;}
              if (X60Qx_1188){
                string_0_sysvq0asl X60Qii_19 = (string_0_sysvq0asl){
                  .bytes_0 = 0u, .more_0 = NIM_NIL}
                ;
                NI32 X60Qii_20 = -1;
                NB8 X60Qii_21 = NIM_FALSE;
                X60Qii_18 = 0;
                while (NIM_TRUE){
                  NI32 X60Qx_1190 = len_3_Ixq6taz_aow7lb5cq1(texts_1);
                  if (X60Qii_18 < X60Qx_1190){
                    string_0_sysvq0asl* X60Qx_1191 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qii_22 = mangledNamesFor_0_aow7lb5cq1((*X60Qx_1191), (*(*X60Qii_14)).d_00.base_0);
                    NI32 X60Qii_23 = 0;
                    while (NIM_TRUE){
                      NI32 X60Qx_1192 = len_3_Ixq6taz_aow7lb5cq1(X60Qii_22);
                      if (X60Qii_23 < X60Qx_1192){
                        NI32 X60Qx_1193 = len_4_sysvq0asl(X60Qii_19);
                        if (X60Qx_1193 == 0){
                          nimStrDestroy(X60Qii_19);
                          string_0_sysvq0asl* X60Qx_1194 = getQ_7_Ir6d0tw_aow7lb5cq1(X60Qii_22, X60Qii_23);
                          string_0_sysvq0asl X60Qx_1195 = nimStrDup((*X60Qx_1194));
                          X60Qii_19 = X60Qx_1195;
                          X60Qii_20 = X60Qii_18;}
                        else {
                          string_0_sysvq0asl* X60Qx_1196 = getQ_7_Ir6d0tw_aow7lb5cq1(X60Qii_22, X60Qii_23);
                          NB8 X60Qx_1197 = eqQ_20_sysvq0asl((*X60Qx_1196), X60Qii_19);
                          if ((!X60Qx_1197)){
                            X60Qii_21 = NIM_TRUE;}}
                        inc_1_I6wjjge_aow2h993l1((&X60Qii_23));}
                      else {
                        break;}}
                    inc_1_I6wjjge_aow2h993l1((&X60Qii_18));
                    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qii_22);}
                  else {
                    break;}}
                NB8 X60Qx_1198;
                NI32 X60Qx_1199 = len_4_sysvq0asl(X60Qii_19);
                if (0 < X60Qx_1199){
                  X60Qx_1198 = (!X60Qii_21);}
                else {
                  X60Qx_1198 = NIM_FALSE;}
                if (X60Qx_1198){
                  X60Qii_16 = X60Qii_20;
                  nimStrDestroy(X60Qii_17);
                  X60Qii_17 = X60Qii_19;
                  nimStrWasMoved((&X60Qii_19));
                  inc_1_I6wjjge_aow2h993l1((&byBase_0));}
                else {
                  if (X60Qii_21){
                    inc_1_I6wjjge_aow2h993l1((&ambiguousMisses_0));
                    string_0_sysvq0asl X60Qtmp_58 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
                      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 0u, .more_0 = NIM_NIL}
                    );
                    NB8 X60Qx_1200 = eqQ_20_sysvq0asl(X60Qtmp_58, (string_0_sysvq0asl){
                      .bytes_0 = 12545u, .more_0 = NIM_NIL}
                    );
                    if (X60Qx_1200){
                      string_0_sysvq0asl X60Qdesugar_189 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                      NI32 X60Qx_1201 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1202 = len_4_sysvq0asl(X60Qdesugar_189);
                      NI32 X60Qx_1203 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1204 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I9306212446656051791_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1205 = len_4_sysvq0asl(X60Qii_15);
                      NI32 X60Qx_1206 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I13430982929222912407_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_190 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1201 + X60Qx_1202)) + X60Qx_1203)) + X60Qx_1204)) + X60Qx_1205)) + X60Qx_1206)));
                      add_2_sysvq0asl((&X60Qdesugar_190), (string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_190), X60Qdesugar_189);
                      add_2_sysvq0asl((&X60Qdesugar_190), (string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_190), (string_0_sysvq0asl){
                        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I9306212446656051791_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_190), X60Qii_15);
                      add_2_sysvq0asl((&X60Qdesugar_190), (string_0_sysvq0asl){
                        .bytes_0 = 1629498622u, .more_0 = (&strlit_0_I13430982929222912407_aow7lb5cq1)}
                      );
                      write_0_syn1lfpjv(stderr, X60Qdesugar_190);
                      nimStrDestroy(X60Qdesugar_190);
                      nimStrDestroy(X60Qdesugar_189);}
                    nimStrDestroy(X60Qtmp_58);}
                  else {
                    inc_1_I6wjjge_aow2h993l1((&noBody_0));
                    string_0_sysvq0asl X60Qtmp_59 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
                      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 0u, .more_0 = NIM_NIL}
                    );
                    NB8 X60Qx_1207 = eqQ_20_sysvq0asl(X60Qtmp_59, (string_0_sysvq0asl){
                      .bytes_0 = 12545u, .more_0 = NIM_NIL}
                    );
                    if (X60Qx_1207){
                      string_0_sysvq0asl X60Qdesugar_191 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                      NI32 X60Qx_1208 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1209 = len_4_sysvq0asl(X60Qdesugar_191);
                      NI32 X60Qx_1210 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1211 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I4639961614947029451_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_192 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1208 + X60Qx_1209)) + X60Qx_1210)) + X60Qx_1211)));
                      add_2_sysvq0asl((&X60Qdesugar_192), (string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_192), X60Qdesugar_191);
                      add_2_sysvq0asl((&X60Qdesugar_192), (string_0_sysvq0asl){
                        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_192), (string_0_sysvq0asl){
                        .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I4639961614947029451_aow7lb5cq1)}
                      );
                      write_0_syn1lfpjv(stderr, X60Qdesugar_192);
                      nimStrDestroy(X60Qdesugar_192);
                      nimStrDestroy(X60Qdesugar_191);}
                    nimStrDestroy(X60Qtmp_59);}}
                nimStrDestroy(X60Qii_19);}
              else {
                if (X60Qii_16 < 0){
                  inc_1_I6wjjge_aow2h993l1((&noBody_0));
                  string_0_sysvq0asl X60Qtmp_60 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
                    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
                  , (string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  );
                  NB8 X60Qx_1212 = eqQ_20_sysvq0asl(X60Qtmp_60, (string_0_sysvq0asl){
                    .bytes_0 = 12545u, .more_0 = NIM_NIL}
                  );
                  if (X60Qx_1212){
                    string_0_sysvq0asl X60Qdesugar_193 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                    NI32 X60Qx_1213 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1214 = len_4_sysvq0asl(X60Qdesugar_193);
                    NI32 X60Qx_1215 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1216 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I9306212446656051791_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1217 = len_4_sysvq0asl(X60Qii_15);
                    NI32 X60Qx_1218 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1680351486u, .more_0 = (&strlit_0_I14045175378979266023_aow7lb5cq1)}
                    );
                    string_0_sysvq0asl X60Qdesugar_194 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1213 + X60Qx_1214)) + X60Qx_1215)) + X60Qx_1216)) + X60Qx_1217)) + X60Qx_1218)));
                    add_2_sysvq0asl((&X60Qdesugar_194), (string_0_sysvq0asl){
                      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_194), X60Qdesugar_193);
                    add_2_sysvq0asl((&X60Qdesugar_194), (string_0_sysvq0asl){
                      .bytes_0 = 540680446u, .more_0 = (&strlit_0_I7386731376022360794_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_194), (string_0_sysvq0asl){
                      .bytes_0 = 1717921022u, .more_0 = (&strlit_0_I9306212446656051791_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_194), X60Qii_15);
                    add_2_sysvq0asl((&X60Qdesugar_194), (string_0_sysvq0asl){
                      .bytes_0 = 1680351486u, .more_0 = (&strlit_0_I14045175378979266023_aow7lb5cq1)}
                    );
                    write_0_syn1lfpjv(stderr, X60Qdesugar_194);
                    nimStrDestroy(X60Qdesugar_194);
                    nimStrDestroy(X60Qdesugar_193);}
                  nimStrDestroy(X60Qtmp_60);}
                else {
                  inc_1_I6wjjge_aow2h993l1((&byExact_0));}}
              X60Qii_18 = X60Qii_16;
              {
                NI32 X60Qx_1219 = len_4_sysvq0asl(X60Qii_17);
                if (0 < X60Qx_1219){
                  string_0_sysvq0asl* X60Qx_1220 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                  CSig_0_aow7lb5cq1 X60Qtmp_61 = sigOf_0_aow7lb5cq1((*X60Qx_1220), X60Qii_17);
                  string_0_sysvq0asl* X60Qx_1221 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                  string_0_sysvq0asl X60Qii_24 = emitCShim_0_aow7lb5cq1((*X60Qii_14), X60Qii_17, strT_3, longT_3, allocFn_2, deallocFn_3, X60Qtmp_61, (*X60Qx_1221));
                  NI32 X60Qx_1222 = len_4_sysvq0asl(X60Qii_24);
                  if (X60Qx_1222 == 0){
                    string_0_sysvq0asl X60Qtmp_62 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
                      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
                    , (string_0_sysvq0asl){
                      .bytes_0 = 0u, .more_0 = NIM_NIL}
                    );
                    NB8 X60Qx_1223 = eqQ_20_sysvq0asl(X60Qtmp_62, (string_0_sysvq0asl){
                      .bytes_0 = 12545u, .more_0 = NIM_NIL}
                    );
                    if (X60Qx_1223){
                      string_0_sysvq0asl X60Qii_25 = (string_0_sysvq0asl){
                        .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I9361295413614208495_aow7lb5cq1)}
                      ;
                      {
                        openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_26 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*(*X60Qii_14)).d_00.args_0);
                        NI32 X60Qlf_27 = 0;
                        {
                          while (NIM_TRUE){
                            NI32 X60Qx_1224 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_26);
                            if (X60Qlf_27 < X60Qx_1224){
                              {
                                WireField_0_run8hsnpi* X60Qii_28 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_26, X60Qlf_27);
                                NB8 X60Qx_1225;
                                if ((*X60Qii_28).isComposite_0){
                                  X60Qx_1225 = (!((*X60Qii_28).desc_0 == NIM_NIL));}
                                else {
                                  X60Qx_1225 = NIM_FALSE;}
                                if (X60Qx_1225){
                                  string_0_sysvq0asl X60Qii_29 = compositeWhyNot_0_aow7lb5cq1((*X60Qii_28).desc_0, 0);
                                  NI32 X60Qx_1226 = len_4_sysvq0asl(X60Qii_29);
                                  if (0 < X60Qx_1226){
                                    nimStrDestroy(X60Qii_25);
                                    string_0_sysvq0asl X60Qx_1227 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                                      .bytes_0 = 544104958u, .more_0 = (&strlit_0_I2584675443025991433_aow7lb5cq1)}
                                    , X60Qii_29);
                                    X60Qii_25 = X60Qx_1227;}
                                  nimStrDestroy(X60Qii_29);}}
                              inc_1_I6wjjge_aow2h993l1((&X60Qlf_27));}
                            else {
                              break;}}}
                        whileStmtLabel_27: ;}
                      forStmtLabel_26: ;
                      NB8 X60Qx_1228;
                      NB8 X60Qx_1229;
                      if ((!(*(*X60Qii_14)).d_00.retVoid_0)){
                        X60Qx_1229 = (*(*X60Qii_14)).d_00.ret_0.isComposite_0;}
                      else {
                        X60Qx_1229 = NIM_FALSE;}
                      if (X60Qx_1229){
                        X60Qx_1228 = (!((*(*X60Qii_14)).d_00.ret_0.desc_0 == NIM_NIL));}
                      else {
                        X60Qx_1228 = NIM_FALSE;}
                      if (X60Qx_1228){
                        string_0_sysvq0asl X60Qii_30 = compositeWhyNot_0_aow7lb5cq1((*(*X60Qii_14)).d_00.ret_0.desc_0, 0);
                        NI32 X60Qx_1230 = len_4_sysvq0asl(X60Qii_30);
                        if (0 < X60Qx_1230){
                          nimStrDestroy(X60Qii_25);
                          string_0_sysvq0asl X60Qx_1231 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I12438589081047852308_aow7lb5cq1)}
                          , X60Qii_30);
                          X60Qii_25 = X60Qx_1231;}
                        nimStrDestroy(X60Qii_30);}
                      string_0_sysvq0asl X60Qdesugar_195 = nimStrDup((*(*X60Qii_14)).d_00.base_0);
                      NI32 X60Qx_1232 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1233 = len_4_sysvq0asl(X60Qdesugar_195);
                      NI32 X60Qx_1234 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1235 = len_4_sysvq0asl(X60Qii_25);
                      NI32 X60Qx_1236 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2561u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_196 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1232 + X60Qx_1233)) + X60Qx_1234)) + X60Qx_1235)) + X60Qx_1236)));
                      add_2_sysvq0asl((&X60Qdesugar_196), (string_0_sysvq0asl){
                        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I18346817918174572282_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_196), X60Qdesugar_195);
                      add_2_sysvq0asl((&X60Qdesugar_196), (string_0_sysvq0asl){
                        .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_196), X60Qii_25);
                      add_2_sysvq0asl((&X60Qdesugar_196), (string_0_sysvq0asl){
                        .bytes_0 = 2561u, .more_0 = NIM_NIL}
                      );
                      write_0_syn1lfpjv(stderr, X60Qdesugar_196);
                      nimStrDestroy(X60Qdesugar_196);
                      nimStrDestroy(X60Qdesugar_195);
                      nimStrDestroy(X60Qii_25);}
                    nimStrDestroy(X60Qtmp_62);
                    nimStrDestroy(X60Qii_24);
                    eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(X60Qtmp_61);
                    goto emitOne_0;
                    nimStrDestroy(X60Qtmp_62);}
                  string_0_sysvq0asl* X60Qx_1237 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                  NB8 X60Qx_1238 = hasSub_0_aow7lb5cq1((*X60Qx_1237), (string_0_sysvq0asl){
                    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I2513678243287852030_aow7lb5cq1)}
                  );
                  if ((!X60Qx_1238)){
                    string_0_sysvq0asl* X60Qx_1239 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                    add_2_sysvq0asl(X60Qx_1239, (string_0_sysvq0asl){
                      .bytes_0 = 707726078u, .more_0 = (&strlit_0_I10597374192599734484_aow7lb5cq1)}
                    );}
                  NB8 X60Qx_1240;
                  string_0_sysvq0asl* X60Qx_1241 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                  NB8 X60Qx_1242 = hasSub_0_aow7lb5cq1((*X60Qx_1241), (string_0_sysvq0asl){
                    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3443046107169670104_aow7lb5cq1)}
                  );
                  if ((!X60Qx_1242)){
                    NB8 X60Qx_1243 = usesStrings_0_aow7lb5cq1((*X60Qii_14));
                    X60Qx_1240 = X60Qx_1243;}
                  else {
                    X60Qx_1240 = NIM_FALSE;}
                  if (X60Qx_1240){
                    string_0_sysvq0asl X60Qtmp_63 = ampQ_0_sysvq0asl(borrowFn_1, (string_0_sysvq0asl){
                      .bytes_0 = 10241u, .more_0 = NIM_NIL}
                    );
                    string_0_sysvq0asl* X60Qx_1244 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                    NB8 X60Qx_1245 = hasSub_0_aow7lb5cq1((*X60Qx_1244), X60Qtmp_63);
                    if ((!X60Qx_1245)){
                      NI32 X60Qx_1246 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 2019887870u, .more_0 = (&strlit_0_I2317332660687858480_aow7lb5cq1)}
                      );
                      NI32 X60Qx_1247 = len_4_sysvq0asl(strT_3);
                      NI32 X60Qx_1248 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_1249 = len_4_sysvq0asl(borrowFn_1);
                      NI32 X60Qx_1250 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1853171966u, .more_0 = (&strlit_0_I16715136830670315920_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl X60Qdesugar_197 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1246 + X60Qx_1247)) + X60Qx_1248)) + X60Qx_1249)) + X60Qx_1250)));
                      add_2_sysvq0asl((&X60Qdesugar_197), (string_0_sysvq0asl){
                        .bytes_0 = 2019887870u, .more_0 = (&strlit_0_I2317332660687858480_aow7lb5cq1)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_197), strT_3);
                      add_2_sysvq0asl((&X60Qdesugar_197), (string_0_sysvq0asl){
                        .bytes_0 = 8193u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_197), borrowFn_1);
                      add_2_sysvq0asl((&X60Qdesugar_197), (string_0_sysvq0asl){
                        .bytes_0 = 1853171966u, .more_0 = (&strlit_0_I16715136830670315920_aow7lb5cq1)}
                      );
                      string_0_sysvq0asl* X60Qx_1251 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                      add_2_sysvq0asl(X60Qx_1251, X60Qdesugar_197);
                      nimStrDestroy(X60Qdesugar_197);}
                    string_0_sysvq0asl X60Qtmp_64 = strHelpers_0_aow7lb5cq1(strT_3, longT_3, borrowFn_1);
                    string_0_sysvq0asl* X60Qx_1252 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                    add_2_sysvq0asl(X60Qx_1252, X60Qtmp_64);
                    nimStrDestroy(X60Qtmp_64);
                    nimStrDestroy(X60Qtmp_63);}
                  NB8 X60Qx_35;
                  NB8 X60Qx_1253 = usesSeqs_0_aow7lb5cq1((*X60Qii_14));
                  if (X60Qx_1253){
                    string_0_sysvq0asl X60Qtmp_65 = ampQ_0_sysvq0asl(allocFn_2, (string_0_sysvq0asl){
                      .bytes_0 = 10241u, .more_0 = NIM_NIL}
                    );
                    string_0_sysvq0asl* X60Qx_1254 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                    NB8 X60Qx_1255 = hasSub_0_aow7lb5cq1((*X60Qx_1254), X60Qtmp_65);
                    X60Qx_35 = (!X60Qx_1255);
                    nimStrDestroy(X60Qtmp_65);}
                  else {
                    X60Qx_35 = NIM_FALSE;}
                  if (X60Qx_35){
                    NI32 X60Qx_1256 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 2019887870u, .more_0 = (&strlit_0_I3018204930238191970_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1257 = len_4_sysvq0asl(allocFn_2);
                    NI32 X60Qx_1258 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1869359358u, .more_0 = (&strlit_0_I13922026781561364508_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1259 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I16286562635260071850_aow7lb5cq1)}
                    );
                    NI32 X60Qx_1260 = len_4_sysvq0asl(deallocFn_3);
                    NI32 X60Qx_1261 = len_4_sysvq0asl((string_0_sysvq0asl){
                      .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I4552606806654256453_aow7lb5cq1)}
                    );
                    string_0_sysvq0asl X60Qdesugar_198 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1256 + X60Qx_1257)) + X60Qx_1258)) + X60Qx_1259)) + X60Qx_1260)) + X60Qx_1261)));
                    add_2_sysvq0asl((&X60Qdesugar_198), (string_0_sysvq0asl){
                      .bytes_0 = 2019887870u, .more_0 = (&strlit_0_I3018204930238191970_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_198), allocFn_2);
                    add_2_sysvq0asl((&X60Qdesugar_198), (string_0_sysvq0asl){
                      .bytes_0 = 1869359358u, .more_0 = (&strlit_0_I13922026781561364508_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_198), (string_0_sysvq0asl){
                      .bytes_0 = 1954047486u, .more_0 = (&strlit_0_I16286562635260071850_aow7lb5cq1)}
                    );
                    add_2_sysvq0asl((&X60Qdesugar_198), deallocFn_3);
                    add_2_sysvq0asl((&X60Qdesugar_198), (string_0_sysvq0asl){
                      .bytes_0 = 1870014718u, .more_0 = (&strlit_0_I4552606806654256453_aow7lb5cq1)}
                    );
                    string_0_sysvq0asl* X60Qx_1262 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                    add_2_sysvq0asl(X60Qx_1262, X60Qdesugar_198);
                    nimStrDestroy(X60Qdesugar_198);}
                  string_0_sysvq0asl* X60Qx_1263 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, X60Qii_18);
                  add_2_sysvq0asl(X60Qx_1263, X60Qii_24);
                  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_1264 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1((*X60Qii_14));
                  add_0_I9iil5u_aow7lb5cq1(shimmed_0, X60Qx_1264);
                  inc_1_I6wjjge_aow2h993l1((&made_0));
                  nimStrDestroy(X60Qii_24);
                  eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(X60Qtmp_61);}}
              emitOne_0: ;
              nimStrDestroy(X60Qii_17);
              nimStrDestroy(X60Qii_15);}
            continueLabel_13: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_25));}
        else {
          break;}}}
    whileStmtLabel_12: ;}
  forStmtLabel_11: ;
  string_0_sysvq0asl X60Qtmp_66 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_1265 = eqQ_20_sysvq0asl(X60Qtmp_66, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  if (X60Qx_1265){
    string_0_sysvq0asl X60Qdesugar_199 = dollarQ_2_sysvq0asl(made_0);
    string_0_sysvq0asl X60Qdesugar_200 = dollarQ_2_sysvq0asl(byExact_0);
    string_0_sysvq0asl X60Qdesugar_201 = dollarQ_2_sysvq0asl(byBase_0);
    string_0_sysvq0asl X60Qdesugar_202 = dollarQ_2_sysvq0asl(noBody_0);
    string_0_sysvq0asl X60Qdesugar_203 = dollarQ_2_sysvq0asl(ambiguousMisses_0);
    NI32 X60Qx_1266 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I11456809569861300725_aow7lb5cq1)}
    );
    NI32 X60Qx_1267 = len_4_sysvq0asl(X60Qdesugar_199);
    NI32 X60Qx_1268 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1697128702u, .more_0 = (&strlit_0_I17792640634769934702_aow7lb5cq1)}
    );
    NI32 X60Qx_1269 = len_4_sysvq0asl(X60Qdesugar_200);
    NI32 X60Qx_1270 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I18342294718160420153_aow7lb5cq1)}
    );
    NI32 X60Qx_1271 = len_4_sysvq0asl(X60Qdesugar_201);
    NI32 X60Qx_1272 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1847601662u, .more_0 = (&strlit_0_I172984808378442068_aow7lb5cq1)}
    );
    NI32 X60Qx_1273 = len_4_sysvq0asl(X60Qdesugar_202);
    NI32 X60Qx_1274 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1835081982u, .more_0 = (&strlit_0_I14472242329998166714_aow7lb5cq1)}
    );
    NI32 X60Qx_1275 = len_4_sysvq0asl(X60Qdesugar_203);
    NI32 X60Qx_1276 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_204 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1266 + X60Qx_1267)) + X60Qx_1268)) + X60Qx_1269)) + X60Qx_1270)) + X60Qx_1271)) + X60Qx_1272)) + X60Qx_1273)) + X60Qx_1274)) + X60Qx_1275)) + X60Qx_1276)));
    add_2_sysvq0asl((&X60Qdesugar_204), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I11456809569861300725_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_204), X60Qdesugar_199);
    add_2_sysvq0asl((&X60Qdesugar_204), (string_0_sysvq0asl){
      .bytes_0 = 1697128702u, .more_0 = (&strlit_0_I17792640634769934702_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_204), X60Qdesugar_200);
    add_2_sysvq0asl((&X60Qdesugar_204), (string_0_sysvq0asl){
      .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I18342294718160420153_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_204), X60Qdesugar_201);
    add_2_sysvq0asl((&X60Qdesugar_204), (string_0_sysvq0asl){
      .bytes_0 = 1847601662u, .more_0 = (&strlit_0_I172984808378442068_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_204), X60Qdesugar_202);
    add_2_sysvq0asl((&X60Qdesugar_204), (string_0_sysvq0asl){
      .bytes_0 = 1835081982u, .more_0 = (&strlit_0_I14472242329998166714_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_204), X60Qdesugar_203);
    add_2_sysvq0asl((&X60Qdesugar_204), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_204);
    nimStrDestroy(X60Qdesugar_204);
    nimStrDestroy(X60Qdesugar_203);
    nimStrDestroy(X60Qdesugar_202);
    nimStrDestroy(X60Qdesugar_201);
    nimStrDestroy(X60Qdesugar_200);
    nimStrDestroy(X60Qdesugar_199);}
  if (made_0 == 0){
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
  seq_0_Ixdx2fh1_aow7lb5cq1 files_0 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  NI32 w_9 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1277 = len_3_Ixq6taz_aow7lb5cq1(texts_1);
      if (w_9 < X60Qx_1277){
        string_0_sysvq0asl X60Qdesugar_205 = dollarQ_2_sysvq0asl(w_9);
        NI32 X60Qx_1278 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I8179081380582823378_aow7lb5cq1)}
        );
        NI32 X60Qx_1279 = len_4_sysvq0asl(X60Qdesugar_205);
        NI32 X60Qx_1280 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 6499842u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_206 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1278 + X60Qx_1279)) + X60Qx_1280)));
        add_2_sysvq0asl((&X60Qdesugar_206), (string_0_sysvq0asl){
          .bytes_0 = 1685024254u, .more_0 = (&strlit_0_I8179081380582823378_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_206), X60Qdesugar_205);
        add_2_sysvq0asl((&X60Qdesugar_206), (string_0_sysvq0asl){
          .bytes_0 = 6499842u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl p_2 = slashQ_0_ospaexnw61(buildDir_0, X60Qdesugar_206);
        string_0_sysvq0asl* X60Qx_1281 = getQ_7_Ir6d0tw_aow7lb5cq1(texts_1, w_9);
        string_0_sysvq0asl X60Qdesugar_207 = nimStrDup((*X60Qx_1281));
        NI32 X60Qx_1282 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 539635710u, .more_0 = (&strlit_0_I15752602684027218635_aow7lb5cq1)}
        );
        NI32 X60Qx_1283 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );
        NI32 X60Qx_1284 = len_4_sysvq0asl(X60Qdesugar_207);
        NI32 X60Qx_1285 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_208 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1282 + X60Qx_1283)) + X60Qx_1284)) + X60Qx_1285)));
        add_2_sysvq0asl((&X60Qdesugar_208), (string_0_sysvq0asl){
          .bytes_0 = 539635710u, .more_0 = (&strlit_0_I15752602684027218635_aow7lb5cq1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_208), (string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );
        add_2_sysvq0asl((&X60Qdesugar_208), X60Qdesugar_207);
        add_2_sysvq0asl((&X60Qdesugar_208), (string_0_sysvq0asl){
          .bytes_0 = 2561u, .more_0 = NIM_NIL}
        );
        ErrorCode_0_sysvq0asl X60QcanRaise_2 = writeFile_0_syn1lfpjv(p_2, X60Qdesugar_208);
        if (X60QcanRaise_2){
          nimStrDestroy(X60Qdesugar_208);
          nimStrDestroy(X60Qdesugar_207);
          goto X60Qexlab_3;}
        nimStrDestroy(X60Qdesugar_208);
        nimStrDestroy(X60Qdesugar_207);
        if (NIM_FALSE){
          X60Qexlab_3: ;
          nimStrDestroy(p_2);
          nimStrDestroy(X60Qdesugar_206);
          nimStrDestroy(X60Qdesugar_205);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
          nimStrDestroy(X60Qtmp_66);
          nimStrDestroy(deallocFn_3);
          nimStrDestroy(allocFn_2);
          nimStrDestroy(borrowFn_1);
          nimStrDestroy(longT_3);
          nimStrDestroy(strT_3);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
          nimStrDestroy(savedMainDir_0);
          nimStrDestroy(X60Qtmp_55);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
          nimStrDestroy(stageDir_0);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
          nimStrDestroy(X60Qtmp_46);
          eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
          nimStrDestroy(X60Qtmp_43);
          nimStrDestroy(X60Qdesugar_182);
          nimStrDestroy(X60Qdesugar_181);
          nimStrDestroy(X60Qdesugar_180);
          nimStrDestroy(listFile_0);
          nimStrDestroy(logFile_2);
          nimStrDestroy(cFile_0);
          nimStrDestroy(X60Qtmp_42);
          return result_49;}
        string_0_sysvq0asl X60Qtmp_67 = p_2;
        nimStrWasMoved((&p_2));
        add_0_Ig6072n_aow7lb5cq1((&files_0), X60Qtmp_67);
        inc_1_I6wjjge_aow2h993l1((&w_9));
        nimStrDestroy(p_2);
        nimStrDestroy(X60Qdesugar_206);
        nimStrDestroy(X60Qdesugar_205);}
      else {
        break;}}}
  whileStmtLabel_31: ;
  string_0_sysvq0asl so_0 = slashQ_0_ospaexnw61(buildDir_0, (string_0_sysvq0asl){
    .bytes_0 = 1651076350u, .more_0 = (&strlit_0_I7503365064679144772_aow7lb5cq1)}
  );
  NB8 X60Qx_1286;
  NB8 X60Qx_1287 = gccSharedMany_0_aow7lb5cq1(files_0, so_0, logFile_2);
  if (X60Qx_1287){
    NB8 X60Qx_1288 = fileExists_0_osc4bsu0d1(so_0);
    X60Qx_1286 = X60Qx_1288;}
  else {
    X60Qx_1286 = NIM_FALSE;}
  if (X60Qx_1286){
    string_0_sysvq0asl X60Qtmp_68 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_1289 = eqQ_20_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
      .bytes_0 = 12545u, .more_0 = NIM_NIL}
    );
    if (X60Qx_1289){
      NI32 X60Qx_1290 = len_3_Ixq6taz_aow7lb5cq1(files_0);
      string_0_sysvq0asl X60Qdesugar_209 = dollarQ_2_sysvq0asl(X60Qx_1290);
      NI32 X60Qx_1291 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I5560383726051623062_aow7lb5cq1)}
      );
      NI32 X60Qx_1292 = len_4_sysvq0asl(X60Qdesugar_209);
      NI32 X60Qx_1293 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I13807919816995135645_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_210 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1291 + X60Qx_1292)) + X60Qx_1293)));
      add_2_sysvq0asl((&X60Qdesugar_210), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I5560383726051623062_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_210), X60Qdesugar_209);
      add_2_sysvq0asl((&X60Qdesugar_210), (string_0_sysvq0asl){
        .bytes_0 = 1853169918u, .more_0 = (&strlit_0_I13807919816995135645_aow7lb5cq1)}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_210);
      nimStrDestroy(X60Qdesugar_210);
      nimStrDestroy(X60Qdesugar_209);}
    string_0_sysvq0asl X60Qtmp_69 = so_0;
    nimStrWasMoved((&so_0));
    nimStrDestroy(X60Qtmp_68);
    nimStrDestroy(so_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return X60Qtmp_69;
    nimStrDestroy(X60Qtmp_68);}
  string_0_sysvq0asl drv_0 = aowlcBin_0_aow7lb5cq1();
  string_0_sysvq0asl X60Qtmp_70 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_1294 = eqQ_20_sysvq0asl(X60Qtmp_70, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  if (X60Qx_1294){
    string_0_sysvq0asl why_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    {
      string_0_sysvq0asl X60Qlf_28 = logFile_2;
      FILE* X60Qlf_29;
      NB8 X60Qx_1295 = open_0_syn1lfpjv((&X60Qlf_29), X60Qlf_28, 0, -1);
      if (X60Qx_1295){
        string_0_sysvq0asl X60Qlf_30 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;
        {
          while (NIM_TRUE){
            NB8 X60Qx_1296 = readLine_0_syn1lfpjv(X60Qlf_29, (&X60Qlf_30));
            if (X60Qx_1296){
              {
                NB8 X60Qx_1297 = hasSub_0_aow7lb5cq1(X60Qlf_30, (string_0_sysvq0asl){
                  .bytes_0 = 1919230206u, .more_0 = (&strlit_0_I5994905260270776565_aow7lb5cq1)}
                );
                if (X60Qx_1297){
                  nimStrDestroy(why_1);
                  why_1 = X60Qlf_30;
                  nimStrWasMoved((&X60Qlf_30));
                  nimStrDestroy(X60Qlf_30);
                  goto forStmtLabel_32;}}}
            else {
              break;}}}
        whileStmtLabel_33: ;
        NI32 X60Qx_1298 = fclose(X60Qlf_29);
        nimStrDestroy(X60Qlf_30);}}
    forStmtLabel_32: ;
    if (NIM_FALSE){
      X60Qexlab_4: ;}
    NI32 X60Qx_1299 = len_4_sysvq0asl(why_1);
    if (X60Qx_1299 == 0){
      NI32 X60Qx_1300 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I12082841593871989252_aow7lb5cq1)}
      );
      NI32 X60Qx_1301 = len_4_sysvq0asl(logFile_2);
      NI32 X60Qx_1302 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 10497u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_211 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1300 + X60Qx_1301)) + X60Qx_1302)));
      add_2_sysvq0asl((&X60Qdesugar_211), (string_0_sysvq0asl){
        .bytes_0 = 1667459070u, .more_0 = (&strlit_0_I12082841593871989252_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_211), logFile_2);
      add_2_sysvq0asl((&X60Qdesugar_211), (string_0_sysvq0asl){
        .bytes_0 = 10497u, .more_0 = NIM_NIL}
      );
      nimStrDestroy(why_1);
      why_1 = X60Qdesugar_211;
      nimStrWasMoved((&X60Qdesugar_211));
      nimStrDestroy(X60Qdesugar_211);}
    string_0_sysvq0asl X60Qtmp_71 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I6593187846888673991_aow7lb5cq1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I14068837617402760607_aow7lb5cq1)}
    );
    write_0_syn1lfpjv(stderr, X60Qtmp_71);
    NI32 X60Qx_1303 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I9780003836072079947_aow7lb5cq1)}
    );
    NI32 X60Qx_1304 = len_4_sysvq0asl(why_1);
    NI32 X60Qx_1305 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_212 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1303 + X60Qx_1304)) + X60Qx_1305)));
    add_2_sysvq0asl((&X60Qdesugar_212), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I9780003836072079947_aow7lb5cq1)}
    );
    add_2_sysvq0asl((&X60Qdesugar_212), why_1);
    add_2_sysvq0asl((&X60Qdesugar_212), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_212);
    string_0_sysvq0asl X60Qtmp_72 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I10430587979360259626_aow7lb5cq1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 1684955646u, .more_0 = (&strlit_0_I5082076793001871145_aow7lb5cq1)}
    );
    write_0_syn1lfpjv(stderr, X60Qtmp_72);
    nimStrDestroy(X60Qtmp_72);
    nimStrDestroy(X60Qdesugar_212);
    nimStrDestroy(X60Qtmp_71);
    nimStrDestroy(why_1);}
  NB8 X60Qx_1306 = fileExists_0_osc4bsu0d1(drv_0);
  if ((!X60Qx_1306)){
    string_0_sysvq0asl X60Qtmp_73 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
      .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
    , (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_1307 = eqQ_20_sysvq0asl(X60Qtmp_73, (string_0_sysvq0asl){
      .bytes_0 = 12545u, .more_0 = NIM_NIL}
    );
    if (X60Qx_1307){
      NI32 X60Qx_1308 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I17458548344829006286_aow7lb5cq1)}
      );
      NI32 X60Qx_1309 = len_4_sysvq0asl(drv_0);
      NI32 X60Qx_1310 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13273991446069831203_aow7lb5cq1)}
      );
      string_0_sysvq0asl X60Qdesugar_213 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1308 + X60Qx_1309)) + X60Qx_1310)));
      add_2_sysvq0asl((&X60Qdesugar_213), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I17458548344829006286_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_213), drv_0);
      add_2_sysvq0asl((&X60Qdesugar_213), (string_0_sysvq0asl){
        .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13273991446069831203_aow7lb5cq1)}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_213);
      nimStrDestroy(X60Qdesugar_213);}
    nimStrDestroy(X60Qtmp_73);
    nimStrDestroy(X60Qtmp_70);
    nimStrDestroy(drv_0);
    nimStrDestroy(so_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;
    nimStrDestroy(X60Qtmp_73);}
  string_0_sysvq0asl cFile2_0 = slashQ_0_ospaexnw61(buildDir_0, (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I12623205787878531514_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qtmp_74 = quoteShell_0_oswd7dmm(drv_0);
  string_0_sysvq0asl cmd_1 = ampQ_0_sysvq0asl(X60Qtmp_74, (string_0_sysvq0asl){
    .bytes_0 = 1768694014u, .more_0 = (&strlit_0_I13081134508802474439_aow7lb5cq1)}
  );
  {
    openArray_0_Ig73pnk_aow7lb5cq1 X60Qlf_31 = toOpenArray_1_I6b60gk1_aow7lb5cq1(mods_2);
    NI32 X60Qlf_32 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1311 = len_6_Igv2wyu1_aow7lb5cq1(X60Qlf_31);
        if (X60Qlf_32 < X60Qx_1311){
          {
            string_0_sysvq0asl* X60Qii_36 = getQ_10_Ik9hgkq1_aow7lb5cq1(X60Qlf_31, X60Qlf_32);
            string_0_sysvq0asl X60Qtmp_76 = quoteShell_0_oswd7dmm((*X60Qii_36));
            string_0_sysvq0asl X60Qtmp_75 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 8193u, .more_0 = NIM_NIL}
            , X60Qtmp_76);
            add_2_sysvq0asl((&cmd_1), X60Qtmp_75);
            nimStrDestroy(X60Qtmp_75);
            nimStrDestroy(X60Qtmp_76);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_32));}
        else {
          break;}}}
    whileStmtLabel_35: ;}
  forStmtLabel_34: ;
  string_0_sysvq0asl X60Qdesugar_214 = quoteShell_0_oswd7dmm(cFile2_0);
  string_0_sysvq0asl X60Qdesugar_215 = quoteShell_0_oswd7dmm(logFile_2);
  NI32 X60Qx_1312 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 757932286u, .more_0 = (&strlit_0_I2781643746782836964_aow7lb5cq1)}
  );
  NI32 X60Qx_1313 = len_4_sysvq0asl(X60Qdesugar_214);
  NI32 X60Qx_1314 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  NI32 X60Qx_1315 = len_4_sysvq0asl(X60Qdesugar_215);
  NI32 X60Qx_1316 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_216 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1312 + X60Qx_1313)) + X60Qx_1314)) + X60Qx_1315)) + X60Qx_1316)));
  add_2_sysvq0asl((&X60Qdesugar_216), (string_0_sysvq0asl){
    .bytes_0 = 757932286u, .more_0 = (&strlit_0_I2781643746782836964_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_216), X60Qdesugar_214);
  add_2_sysvq0asl((&X60Qdesugar_216), (string_0_sysvq0asl){
    .bytes_0 = 1044258819u, .more_0 = NIM_NIL}
  );
  add_2_sysvq0asl((&X60Qdesugar_216), X60Qdesugar_215);
  add_2_sysvq0asl((&X60Qdesugar_216), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I278182693605788883_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&cmd_1), X60Qdesugar_216);
  NI32 X60Qx_1317 = execShellCmd_0_oswd7dmm(cmd_1);
  NB8 X60Qx_1318 = fileExists_0_osc4bsu0d1(cFile2_0);
  if ((!X60Qx_1318)){
    nimStrDestroy(X60Qdesugar_216);
    nimStrDestroy(X60Qdesugar_215);
    nimStrDestroy(X60Qdesugar_214);
    nimStrDestroy(cmd_1);
    nimStrDestroy(X60Qtmp_74);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_70);
    nimStrDestroy(drv_0);
    nimStrDestroy(so_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
  string_0_sysvq0asl src2_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aow7lb5cq1 X60QcanRaise_3 = readFile_0_syn1lfpjv(cFile2_0);
  if (X60QcanRaise_3.fld_0){
    goto X60Qexlab_5;}
  nimStrDestroy(src2_0);
  string_0_sysvq0asl X60Qx_1319 = nimStrDup(X60QcanRaise_3.fld_1);
  src2_0 = X60Qx_1319;
  if (NIM_FALSE){
    X60Qexlab_5: ;
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_216);
    nimStrDestroy(X60Qdesugar_215);
    nimStrDestroy(X60Qdesugar_214);
    nimStrDestroy(cmd_1);
    nimStrDestroy(X60Qtmp_74);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_70);
    nimStrDestroy(drv_0);
    nimStrDestroy(so_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
  NI32 X60Qx_1320 = len_4_sysvq0asl(src2_0);
  if (X60Qx_1320 == 0){
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_216);
    nimStrDestroy(X60Qdesugar_215);
    nimStrDestroy(X60Qdesugar_214);
    nimStrDestroy(cmd_1);
    nimStrDestroy(X60Qtmp_74);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_70);
    nimStrDestroy(drv_0);
    nimStrDestroy(so_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
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
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_33 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_0);
    NI32 X60Qlf_34 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1321 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_33);
        if (X60Qlf_34 < X60Qx_1321){
          {
            X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_39 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_33, X60Qlf_34);
            NB8 X60Qx_1322;
            NB8 X60Qx_1323 = jitEligible_0_aow7lb5cq1((*X60Qii_39));
            if (X60Qx_1323){
              NB8 X60Qx_1324 = usesStrings_0_aow7lb5cq1((*X60Qii_39));
              X60Qx_1322 = X60Qx_1324;}
            else {
              X60Qx_1322 = NIM_FALSE;}
            if (X60Qx_1322){
              needStr_0 = NIM_TRUE;}
            NB8 X60Qx_1325;
            NB8 X60Qx_1326 = jitEligible_0_aow7lb5cq1((*X60Qii_39));
            if (X60Qx_1326){
              NB8 X60Qx_1327 = usesSeqs_0_aow7lb5cq1((*X60Qii_39));
              X60Qx_1325 = X60Qx_1327;}
            else {
              X60Qx_1325 = NIM_FALSE;}
            if (X60Qx_1325){
              needSeq_0 = NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_34));}
        else {
          break;}}}
    whileStmtLabel_38: ;}
  forStmtLabel_37: ;
  NB8 X60Qx_1328;
  if (needStr_0){
    NB8 X60Qx_1329;
    NB8 X60Qx_1330;
    NI32 X60Qx_1331 = len_4_sysvq0asl(strT2_0);
    if (X60Qx_1331 == 0){
      X60Qx_1330 = NIM_TRUE;}
    else {
      NI32 X60Qx_1332 = len_4_sysvq0asl(longT2_0);
      X60Qx_1330 = (X60Qx_1332 == 0);}
    if (X60Qx_1330){
      X60Qx_1329 = NIM_TRUE;}
    else {
      NI32 X60Qx_1333 = len_4_sysvq0asl(borrowFn2_0);
      X60Qx_1329 = (X60Qx_1333 == 0);}
    X60Qx_1328 = X60Qx_1329;}
  else {
    X60Qx_1328 = NIM_FALSE;}
  if (X60Qx_1328){
    nimStrDestroy(allocFn2_0);
    nimStrDestroy(deallocFn2_0);
    nimStrDestroy(borrowFn2_0);
    nimStrDestroy(longT2_0);
    nimStrDestroy(strT2_0);
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_216);
    nimStrDestroy(X60Qdesugar_215);
    nimStrDestroy(X60Qdesugar_214);
    nimStrDestroy(cmd_1);
    nimStrDestroy(X60Qtmp_74);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_70);
    nimStrDestroy(drv_0);
    nimStrDestroy(so_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
  NB8 X60Qx_1334;
  if (needSeq_0){
    NB8 X60Qx_1335;
    NI32 X60Qx_1336 = len_4_sysvq0asl(allocFn2_0);
    if (X60Qx_1336 == 0){
      X60Qx_1335 = NIM_TRUE;}
    else {
      NI32 X60Qx_1337 = len_4_sysvq0asl(deallocFn2_0);
      X60Qx_1335 = (X60Qx_1337 == 0);}
    X60Qx_1334 = X60Qx_1335;}
  else {
    X60Qx_1334 = NIM_FALSE;}
  if (X60Qx_1334){
    nimStrDestroy(allocFn2_0);
    nimStrDestroy(deallocFn2_0);
    nimStrDestroy(borrowFn2_0);
    nimStrDestroy(longT2_0);
    nimStrDestroy(strT2_0);
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_216);
    nimStrDestroy(X60Qdesugar_215);
    nimStrDestroy(X60Qdesugar_214);
    nimStrDestroy(cmd_1);
    nimStrDestroy(X60Qtmp_74);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_70);
    nimStrDestroy(drv_0);
    nimStrDestroy(so_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
  string_0_sysvq0asl shims_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 n2_0 = 0;
  {
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_35 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_0);
    NI32 X60Qlf_36 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1338 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_35);
        if (X60Qlf_36 < X60Qx_1338){
          {
            {
              X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_43 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_35, X60Qlf_36);
              NB8 X60Qx_1339 = jitEligible_0_aow7lb5cq1((*X60Qii_43));
              if ((!X60Qx_1339)){
                goto continueLabel_42;}
              string_0_sysvq0asl X60Qii_44 = mangledName_0_aow7lb5cq1(src2_0, (*(*X60Qii_43)).d_00.base_0);
              NI32 X60Qx_1340 = len_4_sysvq0asl(X60Qii_44);
              if (X60Qx_1340 == 0){
                nimStrDestroy(X60Qii_44);
                goto continueLabel_42;}
              CSig_0_aow7lb5cq1 X60Qtmp_77 = sigOf_0_aow7lb5cq1(src2_0, X60Qii_44);
              string_0_sysvq0asl X60Qii_45 = emitCShim_0_aow7lb5cq1((*X60Qii_43), X60Qii_44, strT2_0, longT2_0, allocFn2_0, deallocFn2_0, X60Qtmp_77, (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_1341 = len_4_sysvq0asl(X60Qii_45);
              if (X60Qx_1341 == 0){
                nimStrDestroy(X60Qii_45);
                eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(X60Qtmp_77);
                nimStrDestroy(X60Qii_44);
                goto continueLabel_42;}
              NB8 X60Qx_1342;
              if (needStr_0){
                NB8 X60Qx_1343 = hasSub_0_aow7lb5cq1(shims_0, (string_0_sysvq0asl){
                  .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I3443046107169670104_aow7lb5cq1)}
                );
                X60Qx_1342 = (!X60Qx_1343);}
              else {
                X60Qx_1342 = NIM_FALSE;}
              if (X60Qx_1342){
                string_0_sysvq0asl X60Qtmp_78 = strHelpers_0_aow7lb5cq1(strT2_0, longT2_0, borrowFn2_0);
                add_2_sysvq0asl((&shims_0), X60Qtmp_78);
                nimStrDestroy(X60Qtmp_78);}
              add_2_sysvq0asl((&shims_0), X60Qii_45);
              inc_1_I6wjjge_aow2h993l1((&n2_0));
              nimStrDestroy(X60Qii_45);
              eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(X60Qtmp_77);
              nimStrDestroy(X60Qii_44);}
            continueLabel_42: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_36));}
        else {
          break;}}}
    whileStmtLabel_41: ;}
  forStmtLabel_40: ;
  if (n2_0 == 0){
    nimStrDestroy(shims_0);
    nimStrDestroy(allocFn2_0);
    nimStrDestroy(deallocFn2_0);
    nimStrDestroy(borrowFn2_0);
    nimStrDestroy(longT2_0);
    nimStrDestroy(strT2_0);
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_216);
    nimStrDestroy(X60Qdesugar_215);
    nimStrDestroy(X60Qdesugar_214);
    nimStrDestroy(cmd_1);
    nimStrDestroy(X60Qtmp_74);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_70);
    nimStrDestroy(drv_0);
    nimStrDestroy(so_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
  add_2_sysvq0asl((&src2_0), (string_0_sysvq0asl){
    .bytes_0 = 707726078u, .more_0 = (&strlit_0_I10597374192599734484_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&src2_0), shims_0);
  ErrorCode_0_sysvq0asl X60QcanRaise_4 = writeFile_0_syn1lfpjv(cFile2_0, src2_0);
  if (X60QcanRaise_4){
    goto X60Qexlab_6;}
  if (NIM_FALSE){
    X60Qexlab_6: ;
    nimStrDestroy(shims_0);
    nimStrDestroy(allocFn2_0);
    nimStrDestroy(deallocFn2_0);
    nimStrDestroy(borrowFn2_0);
    nimStrDestroy(longT2_0);
    nimStrDestroy(strT2_0);
    nimStrDestroy(src2_0);
    nimStrDestroy(X60Qdesugar_216);
    nimStrDestroy(X60Qdesugar_215);
    nimStrDestroy(X60Qdesugar_214);
    nimStrDestroy(cmd_1);
    nimStrDestroy(X60Qtmp_74);
    nimStrDestroy(cFile2_0);
    nimStrDestroy(X60Qtmp_70);
    nimStrDestroy(drv_0);
    nimStrDestroy(so_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
    nimStrDestroy(X60Qtmp_66);
    nimStrDestroy(deallocFn_3);
    nimStrDestroy(allocFn_2);
    nimStrDestroy(borrowFn_1);
    nimStrDestroy(longT_3);
    nimStrDestroy(strT_3);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
    nimStrDestroy(savedMainDir_0);
    nimStrDestroy(X60Qtmp_55);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
    nimStrDestroy(stageDir_0);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
    nimStrDestroy(X60Qtmp_46);
    eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
    nimStrDestroy(X60Qtmp_43);
    nimStrDestroy(X60Qdesugar_182);
    nimStrDestroy(X60Qdesugar_181);
    nimStrDestroy(X60Qdesugar_180);
    nimStrDestroy(listFile_0);
    nimStrDestroy(logFile_2);
    nimStrDestroy(cFile_0);
    nimStrDestroy(X60Qtmp_42);
    return result_49;}
  NB8 X60Qx_1344;
  NB8 X60Qx_1345 = gccShared_0_aow7lb5cq1(cFile2_0, so_0, logFile_2);
  if (X60Qx_1345){
    NB8 X60Qx_1346 = fileExists_0_osc4bsu0d1(so_0);
    X60Qx_1344 = X60Qx_1346;}
  else {
    X60Qx_1344 = NIM_FALSE;}
  if (X60Qx_1344){
    nimStrDestroy(result_49);
    result_49 = so_0;
    nimStrWasMoved((&so_0));}
  nimStrDestroy(shims_0);
  nimStrDestroy(allocFn2_0);
  nimStrDestroy(deallocFn2_0);
  nimStrDestroy(borrowFn2_0);
  nimStrDestroy(longT2_0);
  nimStrDestroy(strT2_0);
  nimStrDestroy(src2_0);
  nimStrDestroy(X60Qdesugar_216);
  nimStrDestroy(X60Qdesugar_215);
  nimStrDestroy(X60Qdesugar_214);
  nimStrDestroy(cmd_1);
  nimStrDestroy(X60Qtmp_74);
  nimStrDestroy(cFile2_0);
  nimStrDestroy(X60Qtmp_70);
  nimStrDestroy(drv_0);
  nimStrDestroy(so_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
  nimStrDestroy(X60Qtmp_66);
  nimStrDestroy(deallocFn_3);
  nimStrDestroy(allocFn_2);
  nimStrDestroy(borrowFn_1);
  nimStrDestroy(longT_3);
  nimStrDestroy(strT_3);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
  nimStrDestroy(savedMainDir_0);
  nimStrDestroy(X60Qtmp_55);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
  nimStrDestroy(stageDir_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
  nimStrDestroy(X60Qtmp_46);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
  nimStrDestroy(X60Qtmp_43);
  nimStrDestroy(X60Qdesugar_182);
  nimStrDestroy(X60Qdesugar_181);
  nimStrDestroy(X60Qdesugar_180);
  nimStrDestroy(listFile_0);
  nimStrDestroy(logFile_2);
  nimStrDestroy(cFile_0);
  nimStrDestroy(X60Qtmp_42);
  return result_49;
  nimStrDestroy(shims_0);
  nimStrDestroy(allocFn2_0);
  nimStrDestroy(deallocFn2_0);
  nimStrDestroy(borrowFn2_0);
  nimStrDestroy(longT2_0);
  nimStrDestroy(strT2_0);
  nimStrDestroy(src2_0);
  nimStrDestroy(X60Qdesugar_216);
  nimStrDestroy(X60Qdesugar_215);
  nimStrDestroy(X60Qdesugar_214);
  nimStrDestroy(cmd_1);
  nimStrDestroy(X60Qtmp_74);
  nimStrDestroy(cFile2_0);
  nimStrDestroy(X60Qtmp_70);
  nimStrDestroy(drv_0);
  nimStrDestroy(so_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(files_0);
  nimStrDestroy(X60Qtmp_66);
  nimStrDestroy(deallocFn_3);
  nimStrDestroy(allocFn_2);
  nimStrDestroy(borrowFn_1);
  nimStrDestroy(longT_3);
  nimStrDestroy(strT_3);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(texts_1);
  nimStrDestroy(savedMainDir_0);
  nimStrDestroy(X60Qtmp_55);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(mods_2);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(X60Qx_7);
  nimStrDestroy(stageDir_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(xmods_0);
  nimStrDestroy(X60Qtmp_46);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(cmods_0);
  nimStrDestroy(X60Qtmp_43);
  nimStrDestroy(X60Qdesugar_182);
  nimStrDestroy(X60Qdesugar_181);
  nimStrDestroy(X60Qdesugar_180);
  nimStrDestroy(listFile_0);
  nimStrDestroy(logFile_2);
  nimStrDestroy(cFile_0);
  nimStrDestroy(X60Qtmp_42);
  return result_49;}
void moduleSourceMap_0_aow7lb5cq1(string_0_sysvq0asl dir_0, string_0_sysvq0asl scratch_0, seq_0_Ixdx2fh1_aow7lb5cq1* mods_1, seq_0_Ixdx2fh1_aow7lb5cq1* srcs_0){
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*mods_1));
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1347 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  (*mods_1) = X60Qx_1347;
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*srcs_0));
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1348 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  (*srcs_0) = X60Qx_1348;
  string_0_sysvq0asl X60Qtmp_80 = parentDir_0_ospaexnw61(scratch_0);
  string_0_sysvq0asl X60Qtmp_79 = shMkdirP_0_hos14g919(X60Qtmp_80);
  NI32 X60Qx_1349 = execShellCmd_0_oswd7dmm(X60Qtmp_79);
  string_0_sysvq0asl X60Qtmp_81 = shRmF_0_hos14g919(scratch_0);
  NI32 X60Qx_1350 = execShellCmd_0_oswd7dmm(X60Qtmp_81);
  string_0_sysvq0asl X60Qdesugar_217 = quoteShell_0_oswd7dmm(dir_0);
  string_0_sysvq0asl X60Qdesugar_218 = quoteShell_0_oswd7dmm(scratch_0);
  NI32 X60Qx_1351 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I9946169762350422666_aow7lb5cq1)}
  );
  NI32 X60Qx_1352 = len_4_sysvq0asl(X60Qdesugar_217);
  NI32 X60Qx_1353 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 774516734u, .more_0 = (&strlit_0_I8938930563455684877_aow7lb5cq1)}
  );
  NI32 X60Qx_1354 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 757095422u, .more_0 = (&strlit_0_I17505878642142243233_aow7lb5cq1)}
  );
  NI32 X60Qx_1355 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1919183102u, .more_0 = (&strlit_0_I9003811850995758106_aow7lb5cq1)}
  );
  NI32 X60Qx_1356 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1668445182u, .more_0 = (&strlit_0_I5022596381085879336_aow7lb5cq1)}
  );
  NI32 X60Qx_1357 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1684370430u, .more_0 = (&strlit_0_I3301261775358999833_aow7lb5cq1)}
  );
  NI32 X60Qx_1358 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1769107710u, .more_0 = (&strlit_0_I1367334208925539560_aow7lb5cq1)}
  );
  NI32 X60Qx_1359 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1852794110u, .more_0 = (&strlit_0_I15015826066028142083_aow7lb5cq1)}
  );
  NI32 X60Qx_1360 = len_4_sysvq0asl(X60Qdesugar_218);
  NI32 X60Qx_1361 = len_4_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I14102627614057926696_aow7lb5cq1)}
  );
  string_0_sysvq0asl X60Qdesugar_219 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1351 + X60Qx_1352)) + X60Qx_1353)) + X60Qx_1354)) + X60Qx_1355)) + X60Qx_1356)) + X60Qx_1357)) + X60Qx_1358)) + X60Qx_1359)) + X60Qx_1360)) + X60Qx_1361)));
  add_2_sysvq0asl((&X60Qdesugar_219), (string_0_sysvq0asl){
    .bytes_0 = 1919903486u, .more_0 = (&strlit_0_I9946169762350422666_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_219), X60Qdesugar_217);
  add_2_sysvq0asl((&X60Qdesugar_219), (string_0_sysvq0asl){
    .bytes_0 = 774516734u, .more_0 = (&strlit_0_I8938930563455684877_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_219), (string_0_sysvq0asl){
    .bytes_0 = 757095422u, .more_0 = (&strlit_0_I17505878642142243233_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_219), (string_0_sysvq0asl){
    .bytes_0 = 1919183102u, .more_0 = (&strlit_0_I9003811850995758106_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_219), (string_0_sysvq0asl){
    .bytes_0 = 1668445182u, .more_0 = (&strlit_0_I5022596381085879336_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_219), (string_0_sysvq0asl){
    .bytes_0 = 1684370430u, .more_0 = (&strlit_0_I3301261775358999833_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_219), (string_0_sysvq0asl){
    .bytes_0 = 1769107710u, .more_0 = (&strlit_0_I1367334208925539560_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_219), (string_0_sysvq0asl){
    .bytes_0 = 1852794110u, .more_0 = (&strlit_0_I15015826066028142083_aow7lb5cq1)}
  );
  add_2_sysvq0asl((&X60Qdesugar_219), X60Qdesugar_218);
  add_2_sysvq0asl((&X60Qdesugar_219), (string_0_sysvq0asl){
    .bytes_0 = 1043472638u, .more_0 = (&strlit_0_I14102627614057926696_aow7lb5cq1)}
  );
  NI32 X60Qx_1362 = execShellCmd_0_oswd7dmm(X60Qdesugar_219);
  {
    string_0_sysvq0asl X60Qlf_37 = scratch_0;
    FILE* X60Qlf_38;
    NB8 X60Qx_1363 = open_0_syn1lfpjv((&X60Qlf_38), X60Qlf_37, 0, -1);
    if (X60Qx_1363){
      string_0_sysvq0asl X60Qlf_39 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      {
        while (NIM_TRUE){
          NB8 X60Qx_1364 = readLine_0_syn1lfpjv(X60Qlf_38, (&X60Qlf_39));
          if (X60Qx_1364){
            {
              {
                string_0_sysvq0asl X60Qii_3 = nimStrDup(X60Qlf_39);
                while (NIM_TRUE){
                  NB8 X60Qx_1365;
                  NI32 X60Qx_1366 = len_4_sysvq0asl(X60Qii_3);
                  if (0 < X60Qx_1366){
                    NB8 X60Qx_1367;
                    NB8 X60Qx_1368;
                    NI32 X60Qx_1369 = len_4_sysvq0asl(X60Qii_3);
                    NC8 X60Qx_1370 = getQ_9_sysvq0asl(X60Qii_3, ((NI32)(X60Qx_1369 - 1)));
                    if (X60Qx_1370 == (NC8)'\012'){
                      X60Qx_1368 = NIM_TRUE;}
                    else {
                      NI32 X60Qx_1371 = len_4_sysvq0asl(X60Qii_3);
                      NC8 X60Qx_1372 = getQ_9_sysvq0asl(X60Qii_3, ((NI32)(X60Qx_1371 - 1)));
                      X60Qx_1368 = (X60Qx_1372 == (NC8)'\015');}
                    if (X60Qx_1368){
                      X60Qx_1367 = NIM_TRUE;}
                    else {
                      NI32 X60Qx_1373 = len_4_sysvq0asl(X60Qii_3);
                      NC8 X60Qx_1374 = getQ_9_sysvq0asl(X60Qii_3, ((NI32)(X60Qx_1373 - 1)));
                      X60Qx_1367 = (X60Qx_1374 == (NC8)' ');}
                    X60Qx_1365 = X60Qx_1367;}
                  else {
                    X60Qx_1365 = NIM_FALSE;}
                  if (X60Qx_1365){
                    NI32 X60Qx_1375 = len_4_sysvq0asl(X60Qii_3);
                    HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1376 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qx_1375 - 2)));
                    string_0_sysvq0asl X60Qlhs_82 = getQ_14_sysvq0asl(X60Qii_3, X60Qx_1376);
                    nimStrDestroy(X60Qii_3);
                    X60Qii_3 = X60Qlhs_82;}
                  else {
                    break;}}
                NI32 X60Qx_1377 = len_4_sysvq0asl(X60Qii_3);
                if (X60Qx_1377 == 0){
                  nimStrDestroy(X60Qii_3);
                  goto continueLabel_2;}
                NI32 X60Qii_4 = -1;
                NI32 X60Qii_5 = 0;
                while (NIM_TRUE){
                  NI32 X60Qx_1378 = len_4_sysvq0asl(X60Qii_3);
                  if (X60Qii_5 < X60Qx_1378){
                    NC8 X60Qx_1379 = getQ_9_sysvq0asl(X60Qii_3, X60Qii_5);
                    if (X60Qx_1379 == (NC8)'\011'){
                      X60Qii_4 = X60Qii_5;
                      break;}
                    inc_1_I6wjjge_aow2h993l1((&X60Qii_5));}
                  else {
                    break;}}
                if (X60Qii_4 <= 0){
                  nimStrDestroy(X60Qii_3);
                  goto continueLabel_2;}
                HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1380 = ___1_Iclcqmw1_aow7lb5cq1(0, ((NI32)(X60Qii_4 - 1)));
                string_0_sysvq0asl X60Qx_1381 = getQ_14_sysvq0asl(X60Qii_3, X60Qx_1380);
                add_0_Ig6072n_aow7lb5cq1(mods_1, X60Qx_1381);
                string_0_sysvq0asl X60Qx_9;
                nimStrWasMoved((&X60Qx_9));
                NI32 X60Qx_1382 = len_4_sysvq0asl(X60Qii_3);
                if (((NI32)(X60Qii_4 + 1)) <= ((NI32)(X60Qx_1382 - 1))){
                  nimStrDestroy(X60Qx_9);
                  NI32 X60Qx_1383 = len_4_sysvq0asl(X60Qii_3);
                  HSlice_0_Inzqy8d_aow7lb5cq1 X60Qx_1384 = ___1_Iclcqmw1_aow7lb5cq1(((NI32)(X60Qii_4 + 1)), ((NI32)(X60Qx_1383 - 1)));
                  string_0_sysvq0asl X60Qx_1385 = getQ_14_sysvq0asl(X60Qii_3, X60Qx_1384);
                  X60Qx_9 = X60Qx_1385;}
                else {
                  nimStrDestroy(X60Qx_9);
                  X60Qx_9 = (string_0_sysvq0asl){
                    .bytes_0 = 0u, .more_0 = NIM_NIL}
                  ;}
                string_0_sysvq0asl X60Qtmp_83 = X60Qx_9;
                nimStrWasMoved((&X60Qx_9));
                add_0_Ig6072n_aow7lb5cq1(srcs_0, X60Qtmp_83);
                nimStrDestroy(X60Qx_9);
                nimStrDestroy(X60Qii_3);}
              continueLabel_2: ;}}
          else {
            break;}}}
      whileStmtLabel_1: ;
      NI32 X60Qx_1386 = fclose(X60Qlf_38);
      nimStrDestroy(X60Qlf_39);}}
  forStmtLabel_0: ;
  if (NIM_FALSE){
    X60Qexlab_7: ;}
  string_0_sysvq0asl X60Qtmp_84 = shRmF_0_hos14g919(scratch_0);
  NI32 X60Qx_1387 = execShellCmd_0_oswd7dmm(X60Qtmp_84);
  nimStrDestroy(X60Qtmp_84);
  nimStrDestroy(X60Qdesugar_219);
  nimStrDestroy(X60Qdesugar_218);
  nimStrDestroy(X60Qdesugar_217);
  nimStrDestroy(X60Qtmp_81);
  nimStrDestroy(X60Qtmp_79);
  nimStrDestroy(X60Qtmp_80);}
seq_0_Igzebks_aow7lb5cq1 jitEligibleEntries_0_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 entries_1){
  seq_0_Igzebks_aow7lb5cq1 result_50;
  eQwasMoved_1_Idjbhcw1_aow7lb5cq1((&result_50));
  eQdestroy_1_Iytr7x_aow7lb5cq1(result_50);
  seq_0_Igzebks_aow7lb5cq1 X60Qx_1388 = newSeqUninit_0_I6ffb0e1_aow7lb5cq1(0);
  result_50 = X60Qx_1388;
  {
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_40 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_1);
    NI32 X60Qlf_41 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1389 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_40);
        if (X60Qlf_41 < X60Qx_1389){
          {
            X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_2 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_40, X60Qlf_41);
            NB8 X60Qx_1390 = jitEligible_0_aow7lb5cq1((*X60Qii_2));
            if (X60Qx_1390){
              X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_1391 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1((*X60Qii_2));
              add_0_I9iil5u_aow7lb5cq1((&result_50), X60Qx_1391);}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_41));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_50;}
static inline openArray_0_Iczu4791_aow7lb5cq1 toOpenArray_1_I0ef4be1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_29){
  openArray_0_Iczu4791_aow7lb5cq1 result_52;
  WireField_0_run8hsnpi* X60Qx_1427 = rawData_0_Ijd497p_aow7lb5cq1(s_29);
  result_52 = (openArray_0_Iczu4791_aow7lb5cq1){
    .a_0 = X60Qx_1427, .len_0 = s_29.len_0}
  ;
  return result_52;}
static inline NI32 len_3_In63jw61_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_31){
  NI32 result_53;
  result_53 = s_31.len_0;
  return result_53;}
static inline WireField_0_run8hsnpi* getQ_7_Iko57h9_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_32, NI32 i_30){
  NB8 X60Qx_1428;
  if (i_30 < s_32.len_0){
    X60Qx_1428 = (0 <= i_30);}
  else {
    X60Qx_1428 = NIM_FALSE;}
  if ((!X60Qx_1428)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  WireField_0_run8hsnpi* result_54;
  result_54 = (&s_32.data_0[i_30]);
  return result_54;}
static inline NI32 len_3_I5m68tr1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_33){
  NI32 result_55;
  result_55 = s_33.len_0;
  return result_55;}
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_7_I45w7c91_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_34, NI32 i_31){
  NB8 X60Qx_1429;
  if (i_31 < s_34.len_0){
    X60Qx_1429 = (0 <= i_31);}
  else {
    X60Qx_1429 = NIM_FALSE;}
  if ((!X60Qx_1429)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** result_56;
  result_56 = (&s_34.data_0[i_31]);
  return result_56;}
static inline HSlice_0_Inzqy8d_aow7lb5cq1 ___1_Iclcqmw1_aow7lb5cq1(NI32 a_15, NI32 b_2){
  HSlice_0_Inzqy8d_aow7lb5cq1 result_57;
  result_57 = (HSlice_0_Inzqy8d_aow7lb5cq1){
    .a_0 = a_15, .b_0 = b_2}
  ;
  return result_57;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline seq_0_Irn2j6w_aow7lb5cq1 newSeqUninit_0_Ifa362m1_aow7lb5cq1(NI32 size_6){
  seq_0_Irn2j6w_aow7lb5cq1 result_58;
  if (size_6 == 0){
    result_58 = (seq_0_Irn2j6w_aow7lb5cq1){
      .len_0 = size_6, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_I5bna9k_aow7lb5cq1(size_6);
    void* X60Qx_1430 = alloc_1_sysvq0asl(memSize_0);
    result_58 = (seq_0_Irn2j6w_aow7lb5cq1){
      .len_0 = size_6, .data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1*)X60Qx_1430)}
    ;
    if ((!(result_58.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1431 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_58.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_58;}
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
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37){
  NI32 result_60;
  result_60 = s_37.len_0;
  return result_60;}
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
static inline void add_0_I1xop2a1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* s_39, X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1 elem_10){
  NI32 L_1 = (*s_39).len_0;
  NI32 X60Qx_1437 = capInBytes_0_Ikkv2nv1_aow7lb5cq1((*s_39));
  if (X60Qx_1437 < ((NI32)(((NI32)(L_1 * sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1))) + sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1)))){
    NB8 X60Qx_1438 = resize_0_I90dq91_aow7lb5cq1(s_39, 1);
    if ((!X60Qx_1438)){
      eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_aow7lb5cq1(elem_10);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_39).len_0));
  (*s_39).data_0[L_1] = elem_10;}
static inline openArray_0_Ig73pnk_aow7lb5cq1 toOpenArray_1_I6b60gk1_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_41){
  openArray_0_Ig73pnk_aow7lb5cq1 result_62;
  string_0_sysvq0asl* X60Qx_1439 = rawData_0_I65w5sr_aow7lb5cq1(s_41);
  result_62 = (openArray_0_Ig73pnk_aow7lb5cq1){
    .a_0 = X60Qx_1439, .len_0 = s_41.len_0}
  ;
  return result_62;}
static inline openArray_0_Inqs7yx_aow7lb5cq1 toOpenArray_0_Iccbrld_aow7lb5cq1(X60Qt_0_IAarrayAiS32ZS4_aow7lb5cq1* x_8){
  openArray_0_Inqs7yx_aow7lb5cq1 result_63;
  openArray_0_Inqs7yx_aow7lb5cq1 X60Qx_10;
  if (((NI32)(((NI32)(((NI32)((NI32)3)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_10 = (openArray_0_Inqs7yx_aow7lb5cq1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_10 = (openArray_0_Inqs7yx_aow7lb5cq1){
      .a_0 = ((NI32*)(&(*x_8))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)3)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_63 = X60Qx_10;
  return result_63;}
static inline NB8 contains_3_Ipa7o28_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_20, NI32 elem_11){
  NB8 result_64;
  NI32 X60Qx_1440 = find_0_Iaugz2s1_aow7lb5cq1(a_20, elem_11);
  result_64 = (0 <= X60Qx_1440);
  return result_64;}
static inline X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* getQ_7_Irlfbqs1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_44, NI32 i_35){
  NB8 X60Qx_1441;
  if (i_35 < s_44.len_0){
    X60Qx_1441 = (0 <= i_35);}
  else {
    X60Qx_1441 = NIM_FALSE;}
  if ((!X60Qx_1441)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1* result_66;
  result_66 = (&s_44.data_0[i_35]);
  return result_66;}
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45){
  NI32 result_67;
  result_67 = s_45.len_0;
  return result_67;}
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_36){
  NB8 X60Qx_1442;
  if (i_36 < s_46.len_0){
    X60Qx_1442 = (0 <= i_36);}
  else {
    X60Qx_1442 = NIM_FALSE;}
  if ((!X60Qx_1442)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NI32* result_68;
  result_68 = (&s_46.data_0[i_36]);
  return result_68;}
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10){
  seq_0_Ift2sne_aow7lb5cq1 result_69;
  if (size_10 == 0){
    result_69 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Inv7kg3_aow7lb5cq1(size_10);
    void* X60Qx_1443 = alloc_1_sysvq0asl(memSize_2);
    result_69 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = ((NI32*)X60Qx_1443)}
    ;
    if ((!(result_69.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1444 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_69.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_69;}
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_1445 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_1445 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1446 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_1446)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
static inline seq_0_Ik7wkpe_aow7lb5cq1 newSeqUninit_0_Idxnvmq_aow7lb5cq1(NI32 size_12){
  seq_0_Ik7wkpe_aow7lb5cq1 result_70;
  if (size_12 == 0){
    result_70 = (seq_0_Ik7wkpe_aow7lb5cq1){
      .len_0 = size_12, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_I03jys01_aow7lb5cq1(size_12);
    void* X60Qx_1447 = alloc_1_sysvq0asl(memSize_3);
    result_70 = (seq_0_Ik7wkpe_aow7lb5cq1){
      .len_0 = size_12, .data_0 = ((seq_0_Ift2sne_aow7lb5cq1*)X60Qx_1447)}
    ;
    if ((!(result_70.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1448 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_70.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_70;}
static inline void add_0_Iivdbhc_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1* s_49, seq_0_Ift2sne_aow7lb5cq1 elem_14){
  NI32 L_3 = (*s_49).len_0;
  NI32 X60Qx_1449 = capInBytes_0_Iri1hlt1_aow7lb5cq1((*s_49));
  if (X60Qx_1449 < ((NI32)(((NI32)(L_3 * sizeof(seq_0_Ift2sne_aow7lb5cq1))) + sizeof(seq_0_Ift2sne_aow7lb5cq1)))){
    NB8 X60Qx_1450 = resize_0_I9lztdq1_aow7lb5cq1(s_49, 1);
    if ((!X60Qx_1450)){
      eQdestroy_1_Iv9ij5i1_aow7lb5cq1(elem_14);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_49).len_0));
  (*s_49).data_0[L_3] = elem_14;}
static inline seq_0_Ift2sne_aow7lb5cq1* getQ_7_Iurb46i_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_51, NI32 i_37){
  NB8 X60Qx_1451;
  if (i_37 < s_51.len_0){
    X60Qx_1451 = (0 <= i_37);}
  else {
    X60Qx_1451 = NIM_FALSE;}
  if ((!X60Qx_1451)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  seq_0_Ift2sne_aow7lb5cq1* result_71;
  result_71 = (&s_51.data_0[i_37]);
  return result_71;}
static inline void putQ_7_Ifvyck5_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_52, NI32 i_38, NI32 elem_15){
  NB8 X60Qx_1452;
  if (i_38 < (*s_52).len_0){
    X60Qx_1452 = (0 <= i_38);}
  else {
    X60Qx_1452 = NIM_FALSE;}
  if ((!X60Qx_1452)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_52).data_0[i_38] = elem_15;}
static inline seq_0_Iflf8jf1_aow7lb5cq1 newSeqUninit_0_I5mozxi1_aow7lb5cq1(NI32 size_14){
  seq_0_Iflf8jf1_aow7lb5cq1 result_72;
  if (size_14 == 0){
    result_72 = (seq_0_Iflf8jf1_aow7lb5cq1){
      .len_0 = size_14, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_4 = memSizeInBytes_0_Ih4q01h_aow7lb5cq1(size_14);
    void* X60Qx_1453 = alloc_1_sysvq0asl(memSize_4);
    result_72 = (seq_0_Iflf8jf1_aow7lb5cq1){
      .len_0 = size_14, .data_0 = ((NB8*)X60Qx_1453)}
    ;
    if ((!(result_72.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1454 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_72.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_4);}}
  return result_72;}
static inline void add_0_Irnc3p1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_53, NB8 elem_16){
  NI32 L_4 = (*s_53).len_0;
  NI32 X60Qx_1455 = capInBytes_0_In1m6ni_aow7lb5cq1((*s_53));
  if (X60Qx_1455 < ((NI32)(((NI32)(L_4 * sizeof(NB8))) + sizeof(NB8)))){
    NB8 X60Qx_1456 = resize_0_I2yw78g1_aow7lb5cq1(s_53, 1);
    if ((!X60Qx_1456)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_53).len_0));
  (*s_53).data_0[L_4] = elem_16;}
static inline NB8* getQ_7_Iul1no9_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_55, NI32 i_39){
  NB8 X60Qx_1457;
  if (i_39 < s_55.len_0){
    X60Qx_1457 = (0 <= i_39);}
  else {
    X60Qx_1457 = NIM_FALSE;}
  if ((!X60Qx_1457)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NB8* result_73;
  result_73 = (&s_55.data_0[i_39]);
  return result_73;}
static inline void putQ_7_Iiblebk_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* s_56, NI32 i_40, NB8 elem_17){
  NB8 X60Qx_1458;
  if (i_40 < (*s_56).len_0){
    X60Qx_1458 = (0 <= i_40);}
  else {
    X60Qx_1458 = NIM_FALSE;}
  if ((!X60Qx_1458)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_56).data_0[i_40] = elem_17;}
static inline openArray_0_Inqs7yx_aow7lb5cq1 toOpenArray_1_Ibqb4ob_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_57){
  openArray_0_Inqs7yx_aow7lb5cq1 result_74;
  NI32* X60Qx_1459 = rawData_0_Ic25u3r_aow7lb5cq1(s_57);
  result_74 = (openArray_0_Inqs7yx_aow7lb5cq1){
    .a_0 = X60Qx_1459, .len_0 = s_57.len_0}
  ;
  return result_74;}
static inline seq_0_Igzebks_aow7lb5cq1 newSeqUninit_0_I6ffb0e1_aow7lb5cq1(NI32 size_16){
  seq_0_Igzebks_aow7lb5cq1 result_75;
  if (size_16 == 0){
    result_75 = (seq_0_Igzebks_aow7lb5cq1){
      .len_0 = size_16, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_5 = memSizeInBytes_0_I21ctpp_aow7lb5cq1(size_16);
    void* X60Qx_1460 = alloc_1_sysvq0asl(memSize_5);
    result_75 = (seq_0_Igzebks_aow7lb5cq1){
      .len_0 = size_16, .data_0 = ((X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1**)X60Qx_1460)}
    ;
    if ((!(result_75.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1461 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_75.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_5);}}
  return result_75;}
static inline NI32 len_3_I44vue3_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_59){
  NI32 result_76;
  result_76 = s_59.len_0;
  return result_76;}
static inline openArray_0_In0ukmu_aow7lb5cq1 toOpenArray_1_Ijdwnsz_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_60){
  openArray_0_In0ukmu_aow7lb5cq1 result_77;
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qx_1462 = rawData_0_Izez9p81_aow7lb5cq1(s_60);
  result_77 = (openArray_0_In0ukmu_aow7lb5cq1){
    .a_0 = X60Qx_1462, .len_0 = s_60.len_0}
  ;
  return result_77;}
static inline void add_0_I9iil5u_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* s_62, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* elem_18){
  NI32 L_5 = (*s_62).len_0;
  NI32 X60Qx_1463 = capInBytes_0_Iekd9qh_aow7lb5cq1((*s_62));
  if (X60Qx_1463 < ((NI32)(((NI32)(L_5 * sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*))) + sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*)))){
    NB8 X60Qx_1464 = resize_0_Ifgwwnv_aow7lb5cq1(s_62, 1);
    if ((!X60Qx_1464)){
      eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(elem_18);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_62).len_0));
  (*s_62).data_0[L_5] = elem_18;}
static inline WireField_0_run8hsnpi* rawData_0_Ijd497p_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_64){
  WireField_0_run8hsnpi* result_78;
  result_78 = s_64.data_0;
  return result_78;}
static inline NI32 len_6_Ier6z6r1_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 a_26){
  NI32 result_79;
  result_79 = a_26.len_0;
  return result_79;}
static inline WireField_0_run8hsnpi* getQ_10_Id2924z_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 x_11, NI32 idx_5){
  NB8 X60Qx_1465;
  if (0 <= idx_5){
    X60Qx_1465 = (idx_5 < x_11.len_0);}
  else {
    X60Qx_1465 = NIM_FALSE;}
  if ((!X60Qx_1465)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  WireField_0_run8hsnpi* result_80;
  result_80 = (&x_11.a_0[idx_5]);
  return result_80;}
static inline NI32 memSizeInBytes_0_I5bna9k_aow7lb5cq1(NI32 size_18){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_81;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_18, sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_81 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_81 = ((NI32)2147483647);}
  return result_81;}
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
NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6){
  NB8 result_86;
  NI32 X60Qx_1468 = capInBytes_0_Ih2sbn01_aow7lb5cq1((*dest_6));
  NI32 oldCap_0 = ((NI32)(X60Qx_1468 / sizeof(string_0_sysvq0asl)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_6);
  NI32 memSize_6 = memSizeInBytes_0_I7me00i_aow7lb5cq1(newCap_0);
  void* X60Qx_1469 = realloc_1_sysvq0asl(((void*)((void*)(*dest_6).data_0)), memSize_6);
  (*dest_6).data_0 = ((string_0_sysvq0asl*)X60Qx_1469);
  if ((*dest_6).data_0 == NIM_NIL){
    (*dest_6).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_6);
    result_86 = NIM_FALSE;}
  else {
    result_86 = NIM_TRUE;}
  return result_86;}
static inline NI32 capInBytes_0_Ikkv2nv1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_66){
  NI32 result_87;
  NI32 X60Qx_12;
  if ((!(s_66.data_0 == NIM_NIL))){
    NI32 X60Qx_1470 = allocatedSize_0_sysvq0asl(((void*)((void*)s_66.data_0)));
    X60Qx_12 = X60Qx_1470;}
  else {
    X60Qx_12 = 0;}
  result_87 = X60Qx_12;
  return result_87;}
NB8 resize_0_I90dq91_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* dest_7, NI32 addedElements_7){
  NB8 result_88;
  NI32 X60Qx_1471 = capInBytes_0_Ikkv2nv1_aow7lb5cq1((*dest_7));
  NI32 oldCap_1 = ((NI32)(X60Qx_1471 / sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_7);
  NI32 memSize_7 = memSizeInBytes_0_I5bna9k_aow7lb5cq1(newCap_1);
  void* X60Qx_1472 = realloc_1_sysvq0asl(((void*)((void*)(*dest_7).data_0)), memSize_7);
  (*dest_7).data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSR6_aow7lb5cq1*)X60Qx_1472);
  if ((*dest_7).data_0 == NIM_NIL){
    (*dest_7).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_7);
    result_88 = NIM_FALSE;}
  else {
    result_88 = NIM_TRUE;}
  return result_88;}
static inline string_0_sysvq0asl* rawData_0_I65w5sr_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_67){
  string_0_sysvq0asl* result_89;
  result_89 = s_67.data_0;
  return result_89;}
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
NI32 find_0_Iaugz2s1_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_29, NI32 elem_19){
  NI32 result_92;
  NI32 i_43 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1474 = len_6_I9632ti1_aow7lb5cq1(a_29);
      if (i_43 < X60Qx_1474){
        NI32* X60Qx_1475 = getQ_10_I053icq_aow7lb5cq1(a_29, i_43);
        if ((*X60Qx_1475) == elem_19){
          return i_43;}
        inc_1_I6wjjge_aow2h993l1((&i_43));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return -1;
  return result_92;}
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_93;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_20, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_93 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_93 = ((NI32)2147483647);}
  return result_93;}
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68){
  NI32 result_94;
  NI32 X60Qx_13;
  if ((!(s_68.data_0 == NIM_NIL))){
    NI32 X60Qx_1476 = allocatedSize_0_sysvq0asl(((void*)((void*)s_68.data_0)));
    X60Qx_13 = X60Qx_1476;}
  else {
    X60Qx_13 = 0;}
  result_94 = X60Qx_13;
  return result_94;}
NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8){
  NB8 result_95;
  NI32 X60Qx_1477 = capInBytes_0_Iet286n_aow7lb5cq1((*dest_8));
  NI32 oldCap_2 = ((NI32)(X60Qx_1477 / sizeof(NI32)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_8);
  NI32 memSize_8 = memSizeInBytes_0_Inv7kg3_aow7lb5cq1(newCap_2);
  void* X60Qx_1478 = realloc_1_sysvq0asl(((void*)((void*)(*dest_8).data_0)), memSize_8);
  (*dest_8).data_0 = ((NI32*)X60Qx_1478);
  if ((*dest_8).data_0 == NIM_NIL){
    (*dest_8).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_8);
    result_95 = NIM_FALSE;}
  else {
    result_95 = NIM_TRUE;}
  return result_95;}
static inline NI32 memSizeInBytes_0_I03jys01_aow7lb5cq1(NI32 size_21){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_96;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_21, sizeof(seq_0_Ift2sne_aow7lb5cq1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_96 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_96 = ((NI32)2147483647);}
  return result_96;}
static inline NI32 capInBytes_0_Iri1hlt1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_69){
  NI32 result_97;
  NI32 X60Qx_14;
  if ((!(s_69.data_0 == NIM_NIL))){
    NI32 X60Qx_1479 = allocatedSize_0_sysvq0asl(((void*)((void*)s_69.data_0)));
    X60Qx_14 = X60Qx_1479;}
  else {
    X60Qx_14 = 0;}
  result_97 = X60Qx_14;
  return result_97;}
NB8 resize_0_I9lztdq1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1* dest_9, NI32 addedElements_9){
  NB8 result_98;
  NI32 X60Qx_1480 = capInBytes_0_Iri1hlt1_aow7lb5cq1((*dest_9));
  NI32 oldCap_3 = ((NI32)(X60Qx_1480 / sizeof(seq_0_Ift2sne_aow7lb5cq1)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_9);
  NI32 memSize_9 = memSizeInBytes_0_I03jys01_aow7lb5cq1(newCap_3);
  void* X60Qx_1481 = realloc_1_sysvq0asl(((void*)((void*)(*dest_9).data_0)), memSize_9);
  (*dest_9).data_0 = ((seq_0_Ift2sne_aow7lb5cq1*)X60Qx_1481);
  if ((*dest_9).data_0 == NIM_NIL){
    (*dest_9).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_9);
    result_98 = NIM_FALSE;}
  else {
    result_98 = NIM_TRUE;}
  return result_98;}
static inline NI32 memSizeInBytes_0_Ih4q01h_aow7lb5cq1(NI32 size_22){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_99;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_22, sizeof(NB8), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_99 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_99 = ((NI32)2147483647);}
  return result_99;}
static inline NI32 capInBytes_0_In1m6ni_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_70){
  NI32 result_100;
  NI32 X60Qx_15;
  if ((!(s_70.data_0 == NIM_NIL))){
    NI32 X60Qx_1482 = allocatedSize_0_sysvq0asl(((void*)((void*)s_70.data_0)));
    X60Qx_15 = X60Qx_1482;}
  else {
    X60Qx_15 = 0;}
  result_100 = X60Qx_15;
  return result_100;}
NB8 resize_0_I2yw78g1_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1* dest_10, NI32 addedElements_10){
  NB8 result_101;
  NI32 X60Qx_1483 = capInBytes_0_In1m6ni_aow7lb5cq1((*dest_10));
  NI32 oldCap_4 = ((NI32)(X60Qx_1483 / sizeof(NB8)));
  NI32 newCap_4 = recalcCap_0_sysvq0asl(oldCap_4, addedElements_10);
  NI32 memSize_10 = memSizeInBytes_0_Ih4q01h_aow7lb5cq1(newCap_4);
  void* X60Qx_1484 = realloc_1_sysvq0asl(((void*)((void*)(*dest_10).data_0)), memSize_10);
  (*dest_10).data_0 = ((NB8*)X60Qx_1484);
  if ((*dest_10).data_0 == NIM_NIL){
    (*dest_10).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_10);
    result_101 = NIM_FALSE;}
  else {
    result_101 = NIM_TRUE;}
  return result_101;}
static inline NI32* rawData_0_Ic25u3r_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_71){
  NI32* result_102;
  result_102 = s_71.data_0;
  return result_102;}
static inline NI32 len_6_I9632ti1_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 a_30){
  NI32 result_103;
  result_103 = a_30.len_0;
  return result_103;}
static inline NI32* getQ_10_I053icq_aow7lb5cq1(openArray_0_Inqs7yx_aow7lb5cq1 x_14, NI32 idx_8){
  NB8 X60Qx_1485;
  if (0 <= idx_8){
    X60Qx_1485 = (idx_8 < x_14.len_0);}
  else {
    X60Qx_1485 = NIM_FALSE;}
  if ((!X60Qx_1485)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NI32* result_104;
  result_104 = (&x_14.a_0[idx_8]);
  return result_104;}
static inline NI32 memSizeInBytes_0_I21ctpp_aow7lb5cq1(NI32 size_23){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_105;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_23, sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_105 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_105 = ((NI32)2147483647);}
  return result_105;}
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** rawData_0_Izez9p81_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_72){
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** result_106;
  result_106 = s_72.data_0;
  return result_106;}
static inline NI32 len_6_Iu1dtri1_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 a_31){
  NI32 result_107;
  result_107 = a_31.len_0;
  return result_107;}
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** getQ_10_I6a58n11_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 x_15, NI32 idx_9){
  NB8 X60Qx_1486;
  if (0 <= idx_9){
    X60Qx_1486 = (idx_9 < x_15.len_0);}
  else {
    X60Qx_1486 = NIM_FALSE;}
  if ((!X60Qx_1486)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** result_108;
  result_108 = (&x_15.a_0[idx_9]);
  return result_108;}
static inline NI32 capInBytes_0_Iekd9qh_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_73){
  NI32 result_109;
  NI32 X60Qx_16;
  if ((!(s_73.data_0 == NIM_NIL))){
    NI32 X60Qx_1487 = allocatedSize_0_sysvq0asl(((void*)((void*)s_73.data_0)));
    X60Qx_16 = X60Qx_1487;}
  else {
    X60Qx_16 = 0;}
  result_109 = X60Qx_16;
  return result_109;}
NB8 resize_0_Ifgwwnv_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* dest_11, NI32 addedElements_11){
  NB8 result_110;
  NI32 X60Qx_1488 = capInBytes_0_Iekd9qh_aow7lb5cq1((*dest_11));
  NI32 oldCap_5 = ((NI32)(X60Qx_1488 / sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*)));
  NI32 newCap_5 = recalcCap_0_sysvq0asl(oldCap_5, addedElements_11);
  NI32 memSize_11 = memSizeInBytes_0_I21ctpp_aow7lb5cq1(newCap_5);
  void* X60Qx_1489 = realloc_1_sysvq0asl(((void*)((void*)(*dest_11).data_0)), memSize_11);
  (*dest_11).data_0 = ((X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1**)X60Qx_1489);
  if ((*dest_11).data_0 == NIM_NIL){
    (*dest_11).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_11);
    result_110 = NIM_FALSE;}
  else {
    result_110 = NIM_TRUE;}
  return result_110;}
void eQdestroy_1_Iem8q971_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1 s_90){
  if ((!(s_90.data_0 == NIM_NIL))){
    NI32 i_44 = 0;
    {
      while (i_44 < s_90.len_0){
        eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_aow7lb5cq1(s_90.data_0[i_44]);
        inc_1_I6wjjge_aow2h993l1((&i_44));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_90.data_0)));}}
static inline void eQwasMoved_1_I3l7wpx1_aow7lb5cq1(seq_0_Irn2j6w_aow7lb5cq1* s_91){
  (*s_91).len_0 = 0;
  (*s_91).data_0 = NIM_NIL;}
void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92){
  if ((!(s_92.data_0 == NIM_NIL))){
    NI32 i_48 = 0;
    {
      while (i_48 < s_92.len_0){
        nimStrDestroy(s_92.data_0[i_48]);
        inc_1_I6wjjge_aow2h993l1((&i_48));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_92.data_0)));}}
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93){
  (*s_93).len_0 = 0;
  (*s_93).data_0 = NIM_NIL;}
seq_0_Ixdx2fh1_aow7lb5cq1 eQdup_1_Imq0s4c_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 a_41){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_112;
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_1496 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(a_41.len_0);
  result_112 = X60Qx_1496;
  NI32 i_49 = 0;
  {
    while (i_49 < a_41.len_0){
      string_0_sysvq0asl X60Qx_1497 = nimStrDup(a_41.data_0[i_49]);
      result_112.data_0[i_49] = X60Qx_1497;
      inc_1_I6wjjge_aow2h993l1((&i_49));}}
  whileStmtLabel_0: ;
  return result_112;}
void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94){
  if ((!(s_94.data_0 == NIM_NIL))){
    NI32 i_52 = 0;
    {
      while (i_52 < s_94.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_52));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_94.data_0)));}}
static inline void eQwasMoved_1_Ix88qzs1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_95){
  (*s_95).len_0 = 0;
  (*s_95).data_0 = NIM_NIL;}
seq_0_Ift2sne_aow7lb5cq1 eQdup_1_Iplow11_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 a_42){
  seq_0_Ift2sne_aow7lb5cq1 result_113;
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_1502 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(a_42.len_0);
  result_113 = X60Qx_1502;
  NI32 i_53 = 0;
  {
    while (i_53 < a_42.len_0){
      result_113.data_0[i_53] = a_42.data_0[i_53];
      inc_1_I6wjjge_aow2h993l1((&i_53));}}
  whileStmtLabel_0: ;
  return result_113;}
void eQdestroy_1_Iytr7x_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_96){
  if ((!(s_96.data_0 == NIM_NIL))){
    NI32 i_56 = 0;
    {
      while (i_56 < s_96.len_0){
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_aow7lb5cq1(s_96.data_0[i_56]);
        inc_1_I6wjjge_aow2h993l1((&i_56));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_96.data_0)));}}
static inline void eQwasMoved_1_Idjbhcw1_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1* s_97){
  (*s_97).len_0 = 0;
  (*s_97).data_0 = NIM_NIL;}
void eQdestroy_1_Ij4pznj1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_98){
  if ((!(s_98.data_0 == NIM_NIL))){
    NI32 i_60 = 0;
    {
      while (i_60 < s_98.len_0){
        eQdestroy_1_Iv9ij5i1_aow7lb5cq1(s_98.data_0[i_60]);
        inc_1_I6wjjge_aow2h993l1((&i_60));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_98.data_0)));}}
void eQdestroy_1_I7a20g9_aow7lb5cq1(seq_0_Iflf8jf1_aow7lb5cq1 s_100){
  if ((!(s_100.data_0 == NIM_NIL))){
    NI32 i_64 = 0;
    {
      while (i_64 < s_100.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_64));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_100.data_0)));}}
void eQdestroy_1_Iksn09f_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_102){
  if ((!(s_102.data_0 == NIM_NIL))){
    NI32 i_68 = 0;
    {
      while (i_68 < s_102.len_0){
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&s_102.data_0[i_68]));
        inc_1_I6wjjge_aow2h993l1((&i_68));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_102.data_0)));}}
void eQdestroy_1_Iqg9snl1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_105){
  if ((!(s_105.data_0 == NIM_NIL))){
    NI32 i_72 = 0;
    {
      while (i_72 < s_105.len_0){
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(s_105.data_0[i_72]);
        inc_1_I6wjjge_aow2h993l1((&i_72));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_105.data_0)));}}
static inline void eQwasMoved_1_Iba95rl_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1* s_106){
  (*s_106).len_0 = 0;
  (*s_106).data_0 = NIM_NIL;}
static inline seq_0_Il8twp61_aow7lb5cq1 newSeqUninit_0_Iopvcdu1_aow7lb5cq1(NI32 size_28){
  seq_0_Il8twp61_aow7lb5cq1 result_119;
  if (size_28 == 0){
    result_119 = (seq_0_Il8twp61_aow7lb5cq1){
      .len_0 = size_28, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_20 = memSizeInBytes_0_Io786y61_aow7lb5cq1(size_28);
    void* X60Qx_1534 = alloc_1_sysvq0asl(memSize_20);
    result_119 = (seq_0_Il8twp61_aow7lb5cq1){
      .len_0 = size_28, .data_0 = ((WireField_0_run8hsnpi*)X60Qx_1534)}
    ;
    if ((!(result_119.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1535 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_119.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_20);}}
  return result_119;}
static inline NI32 capInBytes_0_I51wdad1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_108){
  NI32 result_120;
  NI32 X60Qx_17;
  if ((!(s_108.data_0 == NIM_NIL))){
    NI32 X60Qx_1536 = allocatedSize_0_sysvq0asl(((void*)((void*)s_108.data_0)));
    X60Qx_17 = X60Qx_1536;}
  else {
    X60Qx_17 = 0;}
  result_120 = X60Qx_17;
  return result_120;}
static inline NI32 memSizeInBytes_0_Io786y61_aow7lb5cq1(NI32 size_29){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_121;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_29, sizeof(WireField_0_run8hsnpi), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_121 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_121 = ((NI32)2147483647);}
  return result_121;}
static inline seq_0_I3ump14_aow7lb5cq1 newSeqUninit_0_I978ktq1_aow7lb5cq1(NI32 size_30){
  seq_0_I3ump14_aow7lb5cq1 result_122;
  if (size_30 == 0){
    result_122 = (seq_0_I3ump14_aow7lb5cq1){
      .len_0 = size_30, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_21 = memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(size_30);
    void* X60Qx_1537 = alloc_1_sysvq0asl(memSize_21);
    result_122 = (seq_0_I3ump14_aow7lb5cq1){
      .len_0 = size_30, .data_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1**)X60Qx_1537)}
    ;
    if ((!(result_122.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1538 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_122.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_21);}}
  return result_122;}
static inline NI32 capInBytes_0_Iho46001_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_109){
  NI32 result_123;
  NI32 X60Qx_18;
  if ((!(s_109.data_0 == NIM_NIL))){
    NI32 X60Qx_1539 = allocatedSize_0_sysvq0asl(((void*)((void*)s_109.data_0)));
    X60Qx_18 = X60Qx_1539;}
  else {
    X60Qx_18 = 0;}
  result_123 = X60Qx_18;
  return result_123;}
static inline NI32 memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(NI32 size_31){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_124;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_31, sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_124 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_124 = ((NI32)2147483647);}
  return result_124;}
void eQdestroyQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(CSig_0_aow7lb5cq1 dest_0){
  eQdestroy_1_Ivioh0a_aow7lb5cq1(dest_0.params_0);
  nimStrDestroy(dest_0.ret_0);}
void eQwasmovedQ_SX43X53ig0aow7lb5cq1_0_aow7lb5cq1(CSig_0_aow7lb5cq1* dest_0){
  nimStrWasMoved((&(*dest_0).ret_0));
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&(*dest_0).params_0));}
void eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_1542 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1542){
      eQdestroyQ_SX54ypeX44escX4fbj0layptix6a1_0_layptix6a1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_aow7lb5cq1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* src_0){
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
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
    NB8 X60Qx_1543 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1543){
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
