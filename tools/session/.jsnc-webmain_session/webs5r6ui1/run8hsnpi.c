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
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct seq_0_I50urnw_croph25r5 seq_0_I50urnw_croph25r5;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1 X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1;
typedef struct WireField_0_run8hsnpi WireField_0_run8hsnpi;
typedef struct seq_0_Ift2sne_aow7lb5cq1 seq_0_Ift2sne_aow7lb5cq1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v;
typedef struct X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1 X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1 X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1;
typedef struct seq_0_I3ump14_aow7lb5cq1 seq_0_I3ump14_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi;
typedef struct MatEntry_0_arecyyj7v MatEntry_0_arecyyj7v;
typedef struct BlockEntry_0_arecyyj7v BlockEntry_0_arecyyj7v;
typedef struct RegionHandout_0_arecyyj7v RegionHandout_0_arecyyj7v;
typedef struct X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi;
typedef struct X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5 X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251_croph25r5;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct HybridProvider_Obj_0_run8hsnpi HybridProvider_Obj_0_run8hsnpi;
typedef struct CabiSpikeProvider_Obj_0_run8hsnpi CabiSpikeProvider_Obj_0_run8hsnpi;
typedef struct CabiGenProvider_Obj_0_run8hsnpi CabiGenProvider_Obj_0_run8hsnpi;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11 X60Qt_0_IArefSX50ipeX42ufX4fbj0natd5co251_hos5i19e11;
typedef struct X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax X60Qt_0_IArefSX49oX50olicyX4fbj0iop7yt73v_intzsnzax;
typedef struct PathGrant_0_iop7yt73v PathGrant_0_iop7yt73v;
typedef struct ReadRecord_0_iop7yt73v ReadRecord_0_iop7yt73v;
typedef NU8 ProviderKind_0_run8hsnpi;

#define pkInterpret_0_run8hsnpi ((NU8)0)
#define pkHostNative_0_run8hsnpi ((NU8)1)
#define pkSyscall_0_run8hsnpi ((NU8)2)
#define pkHybridNative_0_run8hsnpi ((NU8)3)
typedef NU8 Codec_0_run8hsnpi;

#define codecIdentity_0_run8hsnpi ((NU8)0)
#define codecFlatCAbi_0_run8hsnpi ((NU8)1)
#define codecJsValue_0_run8hsnpi ((NU8)2)
typedef NU8 Policy_0_run8hsnpi;

#define polFailLoud_0_run8hsnpi ((NU8)0)
#define polFallbackInterpret_0_run8hsnpi ((NU8)1)
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSstring0sysvq0aslAboolZAnimcallZAfalseZAR71_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSseq0X4950urnwAboolZAnimcallZAfalseZAR68_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, seq_0_I50urnw_croph25r5);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX56alue0valzr1t4fAmutSR39ZAboolZAnimcallZAfalseZAR81_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, Value_0_valzr1t4f*, Value_0_valzr1t4f*);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX53ymX49d0nifh7u8pu1AboolZAnimcallZAfalseZAR75_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, NU32);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX53ymX49d0nifh7u8pu1Sstring0sysvq0aslSseq0X4950urnwAmutSX56alue0valzr1t4fZAboolZAnimcallZAfalseZAR129_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*, NU32, string_0_sysvq0asl, seq_0_I50urnw_croph25r5, Value_0_valzr1t4f*);
typedef struct HybridProvider_Obj_0_run8hsnpi{
  RootObj_0_sysvq0asl Q;
  ProviderKind_0_run8hsnpi kind_0;
  Codec_0_run8hsnpi codec_0;
  Policy_0_run8hsnpi policy_0;
  string_0_sysvq0asl name_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSstring0sysvq0aslAboolZAnimcallZAfalseZAR71_run8hsnpi resolveFastImpl_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSseq0X4950urnwAboolZAnimcallZAfalseZAR68_run8hsnpi marshalArgs_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX56alue0valzr1t4fAmutSR39ZAboolZAnimcallZAfalseZAR81_run8hsnpi marshalReturn_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX53ymX49d0nifh7u8pu1AboolZAnimcallZAfalseZAR75_run8hsnpi ownsImpl_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX53ymX49d0nifh7u8pu1Sstring0sysvq0aslSseq0X4950urnwAmutSX56alue0valzr1t4fZAboolZAnimcallZAfalseZAR129_run8hsnpi invoke_0;}
HybridProvider_Obj_0_run8hsnpi;
typedef struct seq_0_Ixkko8n_run8hsnpi{
  NI32 len_0;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** data_0;}
seq_0_Ixkko8n_run8hsnpi;
typedef struct HybridRegistry_Obj_0_run8hsnpi{
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* provider_0;
  seq_0_Ixkko8n_run8hsnpi extra_0;}
HybridRegistry_Obj_0_run8hsnpi;
typedef N_CDECL_PTR(int,  X60Qt_0_IAiS32AimportcSUintUZZAiS32AR5SUintUZZAcdeclZAfalseZAR44_run8hsnpi)(int);
typedef struct CabiSpikeProvider_Obj_0_run8hsnpi{
  HybridProvider_Obj_0_run8hsnpi Q;
  string_0_sysvq0asl soPath_0;
  void* handle_0;
  X60Qt_0_IAiS32AimportcSUintUZZAiS32AR5SUintUZZAcdeclZAfalseZAR44_run8hsnpi addoneFn_0;
  NB8 resolved_0;}
CabiSpikeProvider_Obj_0_run8hsnpi;
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
typedef struct seq_0_Il8twp61_aow7lb5cq1{
  NI32 len_0;
  WireField_0_run8hsnpi* data_0;}
seq_0_Il8twp61_aow7lb5cq1;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_Ik7wkpe_aow7lb5cq1{
  NI32 len_0;
  seq_0_Ift2sne_aow7lb5cq1* data_0;}
seq_0_Ik7wkpe_aow7lb5cq1;
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
typedef struct seq_0_Iwk350i1_run8hsnpi{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* data_0;}
seq_0_Iwk350i1_run8hsnpi;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_Ivb80lo_run8hsnpi{
  seq_0_Iwk350i1_run8hsnpi data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_Ivb80lo_run8hsnpi;
typedef struct CabiGenProvider_Obj_0_run8hsnpi{
  HybridProvider_Obj_0_run8hsnpi Q;
  string_0_sysvq0asl soPath_0;
  void* handle_0;
  NB8 opened_0;
  Table_0_Ivb80lo_run8hsnpi table_0;
  X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* arena_0;
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* xp_0;}
CabiGenProvider_Obj_0_run8hsnpi;
typedef struct seq_0_I50urnw_croph25r5{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_croph25r5;
typedef struct seq_0_I3ump14_aow7lb5cq1{
  NI32 len_0;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** data_0;}
seq_0_I3ump14_aow7lb5cq1;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct seq_0_Incv1wn_arecyyj7v{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_arecyyj7v;
typedef struct seq_0_Igzebks_aow7lb5cq1{
  NI32 len_0;
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** data_0;}
seq_0_Igzebks_aow7lb5cq1;
typedef struct seq_0_Ie088gc_heapjafyf1{
  NI32 len_0;
  seq_0_I3ump14_aow7lb5cq1* data_0;}
seq_0_Ie088gc_heapjafyf1;
typedef struct openArray_0_I3ca6t4_layptix6a1{
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** a_0;
  NI32 len_0;}
openArray_0_I3ca6t4_layptix6a1;
typedef struct openArray_0_Ihcf6y9_run8hsnpi{
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** a_0;
  NI32 len_0;}
openArray_0_Ihcf6y9_run8hsnpi;
typedef struct openArray_0_Iczu4791_aow7lb5cq1{
  WireField_0_run8hsnpi* a_0;
  NI32 len_0;}
openArray_0_Iczu4791_aow7lb5cq1;
typedef struct seq_0_Iw8xl5b1_arecyyj7v{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_arecyyj7v;
typedef struct openArray_0_Is74e021_explnj22x1{
  NU8* a_0;
  NI32 len_0;}
openArray_0_Is74e021_explnj22x1;
typedef struct seq_0_Ie7vbta_run8hsnpi{
  NI32 len_0;
  X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* data_0;}
seq_0_Ie7vbta_run8hsnpi;
typedef struct openArray_0_Icv4v4b1_run8hsnpi{
  X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* a_0;
  NI32 len_0;}
openArray_0_Icv4v4b1_run8hsnpi;
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
typedef struct seq_0_Iq1shzq1_run8hsnpi{
  NI32 len_0;
  X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* data_0;}
seq_0_Iq1shzq1_run8hsnpi;
typedef struct openArray_0_In0ukmu_aow7lb5cq1{
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** a_0;
  NI32 len_0;}
openArray_0_In0ukmu_aow7lb5cq1;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
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
typedef struct openArray_0_Ijk0jkw1_aow7lb5cq1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax{
  NI r_00;
  HybridProvider_Obj_0_run8hsnpi d_00;}
X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax;
typedef struct X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax{
  NI r_00;
  HybridRegistry_Obj_0_run8hsnpi d_00;}
X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax;
typedef struct X60Qt_0_IArefSX43abiX53pikeX50roviderX4fbj0run8hsnpi_run8hsnpi{
  NI r_00;
  CabiSpikeProvider_Obj_0_run8hsnpi d_00;}
X60Qt_0_IArefSX43abiX53pikeX50roviderX4fbj0run8hsnpi_run8hsnpi;
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
typedef N_CDECL_PTR(NI32,  X60Qt_0_IAcstringZApointerZAiS32ZAR9ZAiS32ZAcdeclZAfalseZAR41_run8hsnpi)(NC8*, void*, NI32, void*);
typedef N_CDECL_PTR(void,  X60Qt_0_IAcstringZApointerZAiS32ZAR9ZAiS32ZAcdeclZAfalseZAR41SEAcdeclZAfalseZAR61_run8hsnpi)(X60Qt_0_IAcstringZApointerZAiS32ZAR9ZAiS32ZAcdeclZAfalseZAR41_run8hsnpi);
typedef struct X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1{
  NI r_00;
  ShimEntry_Obj_0_run8hsnpi d_00;}
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1;
typedef struct X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi{
  NI r_00;
  CabiGenProvider_Obj_0_run8hsnpi d_00;}
X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi;
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
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32ZAboolZAR29ZAR29ZAR29ZAR29ZAR29_run8hsnpi{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;
  NB8 fld_2;
  NB8 fld_3;
  NB8 fld_4;
  NB8 fld_5;
  NB8 fld_6;
  NB8 fld_7;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32ZAboolZAR29ZAR29ZAR29ZAR29ZAR29_run8hsnpi;
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1{
  NI32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi{
  Cursor_0_nifb6mq6y1 fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi{
  string_0_sysvq0asl fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21{
  string_0_sysvq0asl fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21;
typedef struct X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi{
  NB8 fld_0;
  seq_0_In6doa_arecyyj7v fld_1;
  seq_0_In6doa_arecyyj7v fld_2;}
X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi;
typedef struct X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi{
  WireField_0_run8hsnpi fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi;
typedef struct X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax{
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_arecyyj7v names_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
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
typedef struct Cell_Obj_0_valzr1t4f{
  Value_0_valzr1t4f v_0;}
Cell_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  Cell_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
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
typedef NU8 AnVerdict_0_der823rwr1;

#define avNeverTouched_0_der823rwr1 ((NU8)0)
#define avTouched_0_der823rwr1 ((NU8)1)
#define avUnknown_0_der823rwr1 ((NU8)2)
typedef NU8 AnGiveUp_0_der823rwr1;

#define agNone_0_der823rwr1 ((NU8)0)
#define agNoBody_0_der823rwr1 ((NU8)1)
#define agMethod_0_der823rwr1 ((NU8)2)
#define agRecursion_0_der823rwr1 ((NU8)3)
#define agDepth_0_der823rwr1 ((NU8)4)
#define agShape_0_der823rwr1 ((NU8)5)
#define agCalleeUnknown_0_der823rwr1 ((NU8)6)
#define agNoParam_0_der823rwr1 ((NU8)7)
#define agNoField_0_der823rwr1 ((NU8)8)
typedef struct X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1{
  AnVerdict_0_der823rwr1 fld_0;
  AnGiveUp_0_der823rwr1 fld_1;
  string_0_sysvq0asl fld_2;}
X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1;
typedef struct X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v{
  Value_0_valzr1t4f fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v;
typedef struct X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi{
  NI32 fld_0;
  Value_0_valzr1t4f fld_1;}
X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi;
typedef struct X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi{
  Value_0_valzr1t4f fld_0;
  void* fld_1;}
X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi{
  NU32 fld_0;
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi;
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISX48ybridX50roviderX4fbj0run8hsnpiSEAnimcallZAfalseZAR45_intzsnzax)(HybridProvider_Obj_0_run8hsnpi*);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISX43abiX53pikeX50roviderX4fbj0run8hsnpiSEAnimcallZAfalseZAR50_run8hsnpi)(CabiSpikeProvider_Obj_0_run8hsnpi*);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISX43abiX47enX50roviderX4fbj0run8hsnpiSEAnimcallZAfalseZAR48_run8hsnpi)(CabiGenProvider_Obj_0_run8hsnpi*);
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
typedef struct seq_0_Ivkh6l1_linxafkvx1{
  NI32 len_0;
  LineInfoUnpacked_0_linxafkvx1* data_0;}
seq_0_Ivkh6l1_linxafkvx1;
typedef struct LineInfoManager_0_linxafkvx1{
  seq_0_Ivkh6l1_linxafkvx1 aside_0;}
LineInfoManager_0_linxafkvx1;
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
typedef NU16 TagEnum_0_tagygirdh1;

#define InvalidTagId_0_tagygirdh1 ((NU16)0)
#define ErrTagId_0_tagygirdh1 ((NU16)1)
#define SufTagId_0_tagygirdh1 ((NU16)2)
#define AtTagId_0_tagygirdh1 ((NU16)3)
#define DerefTagId_0_tagygirdh1 ((NU16)4)
#define DotTagId_0_tagygirdh1 ((NU16)5)
#define PatTagId_0_tagygirdh1 ((NU16)6)
#define ParTagId_0_tagygirdh1 ((NU16)7)
#define AddrTagId_0_tagygirdh1 ((NU16)8)
#define NilTagId_0_tagygirdh1 ((NU16)9)
#define NotnilTagId_0_tagygirdh1 ((NU16)10)
#define UncheckedTagId_0_tagygirdh1 ((NU16)11)
#define InfTagId_0_tagygirdh1 ((NU16)12)
#define NeginfTagId_0_tagygirdh1 ((NU16)13)
#define NanTagId_0_tagygirdh1 ((NU16)14)
#define FalseTagId_0_tagygirdh1 ((NU16)15)
#define TrueTagId_0_tagygirdh1 ((NU16)16)
#define AndTagId_0_tagygirdh1 ((NU16)17)
#define OrTagId_0_tagygirdh1 ((NU16)18)
#define XorTagId_0_tagygirdh1 ((NU16)19)
#define NotTagId_0_tagygirdh1 ((NU16)20)
#define NegTagId_0_tagygirdh1 ((NU16)21)
#define SizeofTagId_0_tagygirdh1 ((NU16)22)
#define AlignofTagId_0_tagygirdh1 ((NU16)23)
#define OffsetofTagId_0_tagygirdh1 ((NU16)24)
#define OconstrTagId_0_tagygirdh1 ((NU16)25)
#define AconstrTagId_0_tagygirdh1 ((NU16)26)
#define BracketTagId_0_tagygirdh1 ((NU16)27)
#define CurlyTagId_0_tagygirdh1 ((NU16)28)
#define CurlyatTagId_0_tagygirdh1 ((NU16)29)
#define KvTagId_0_tagygirdh1 ((NU16)30)
#define VvTagId_0_tagygirdh1 ((NU16)31)
#define OvfTagId_0_tagygirdh1 ((NU16)32)
#define AddTagId_0_tagygirdh1 ((NU16)33)
#define SubTagId_0_tagygirdh1 ((NU16)34)
#define MulTagId_0_tagygirdh1 ((NU16)35)
#define DivTagId_0_tagygirdh1 ((NU16)36)
#define ModTagId_0_tagygirdh1 ((NU16)37)
#define ShrTagId_0_tagygirdh1 ((NU16)38)
#define ShlTagId_0_tagygirdh1 ((NU16)39)
#define BitandTagId_0_tagygirdh1 ((NU16)40)
#define BitorTagId_0_tagygirdh1 ((NU16)41)
#define BitxorTagId_0_tagygirdh1 ((NU16)42)
#define BitnotTagId_0_tagygirdh1 ((NU16)43)
#define EqTagId_0_tagygirdh1 ((NU16)44)
#define NeqTagId_0_tagygirdh1 ((NU16)45)
#define LeTagId_0_tagygirdh1 ((NU16)46)
#define LtTagId_0_tagygirdh1 ((NU16)47)
#define CastTagId_0_tagygirdh1 ((NU16)48)
#define ConvTagId_0_tagygirdh1 ((NU16)49)
#define CallTagId_0_tagygirdh1 ((NU16)50)
#define CmdTagId_0_tagygirdh1 ((NU16)51)
#define RangeTagId_0_tagygirdh1 ((NU16)52)
#define RangesTagId_0_tagygirdh1 ((NU16)53)
#define GvarTagId_0_tagygirdh1 ((NU16)54)
#define TvarTagId_0_tagygirdh1 ((NU16)55)
#define VarTagId_0_tagygirdh1 ((NU16)56)
#define ParamTagId_0_tagygirdh1 ((NU16)57)
#define ConstTagId_0_tagygirdh1 ((NU16)58)
#define ResultTagId_0_tagygirdh1 ((NU16)59)
#define GletTagId_0_tagygirdh1 ((NU16)60)
#define TletTagId_0_tagygirdh1 ((NU16)61)
#define LetTagId_0_tagygirdh1 ((NU16)62)
#define CursorTagId_0_tagygirdh1 ((NU16)63)
#define PatternvarTagId_0_tagygirdh1 ((NU16)64)
#define TypevarTagId_0_tagygirdh1 ((NU16)65)
#define StaticTypevarTagId_0_tagygirdh1 ((NU16)66)
#define EfldTagId_0_tagygirdh1 ((NU16)67)
#define FldTagId_0_tagygirdh1 ((NU16)68)
#define GfldTagId_0_tagygirdh1 ((NU16)69)
#define ProcTagId_0_tagygirdh1 ((NU16)70)
#define FuncTagId_0_tagygirdh1 ((NU16)71)
#define IteratorTagId_0_tagygirdh1 ((NU16)72)
#define ConverterTagId_0_tagygirdh1 ((NU16)73)
#define MethodTagId_0_tagygirdh1 ((NU16)74)
#define MacroTagId_0_tagygirdh1 ((NU16)75)
#define TemplateTagId_0_tagygirdh1 ((NU16)76)
#define TypeTagId_0_tagygirdh1 ((NU16)77)
#define BlockTagId_0_tagygirdh1 ((NU16)78)
#define ModuleTagId_0_tagygirdh1 ((NU16)79)
#define CchoiceTagId_0_tagygirdh1 ((NU16)80)
#define OchoiceTagId_0_tagygirdh1 ((NU16)81)
#define EmitTagId_0_tagygirdh1 ((NU16)82)
#define AsgnTagId_0_tagygirdh1 ((NU16)83)
#define StoreTagId_0_tagygirdh1 ((NU16)84)
#define KeepovfTagId_0_tagygirdh1 ((NU16)85)
#define ScopeTagId_0_tagygirdh1 ((NU16)86)
#define IfTagId_0_tagygirdh1 ((NU16)87)
#define WhenTagId_0_tagygirdh1 ((NU16)88)
#define ElifTagId_0_tagygirdh1 ((NU16)89)
#define ElseTagId_0_tagygirdh1 ((NU16)90)
#define TypevarsTagId_0_tagygirdh1 ((NU16)91)
#define BreakTagId_0_tagygirdh1 ((NU16)92)
#define ContinueTagId_0_tagygirdh1 ((NU16)93)
#define ForTagId_0_tagygirdh1 ((NU16)94)
#define WhileTagId_0_tagygirdh1 ((NU16)95)
#define CoroforTagId_0_tagygirdh1 ((NU16)96)
#define CaseTagId_0_tagygirdh1 ((NU16)97)
#define OfTagId_0_tagygirdh1 ((NU16)98)
#define LabTagId_0_tagygirdh1 ((NU16)99)
#define JmpTagId_0_tagygirdh1 ((NU16)100)
#define RetTagId_0_tagygirdh1 ((NU16)101)
#define YldTagId_0_tagygirdh1 ((NU16)102)
#define StmtsTagId_0_tagygirdh1 ((NU16)103)
#define ParamsTagId_0_tagygirdh1 ((NU16)104)
#define UnionTagId_0_tagygirdh1 ((NU16)105)
#define ObjectTagId_0_tagygirdh1 ((NU16)106)
#define EnumTagId_0_tagygirdh1 ((NU16)107)
#define ProctypeTagId_0_tagygirdh1 ((NU16)108)
#define AtomicTagId_0_tagygirdh1 ((NU16)109)
#define RoTagId_0_tagygirdh1 ((NU16)110)
#define RestrictTagId_0_tagygirdh1 ((NU16)111)
#define CpprefTagId_0_tagygirdh1 ((NU16)112)
#define ITagId_0_tagygirdh1 ((NU16)113)
#define UTagId_0_tagygirdh1 ((NU16)114)
#define FTagId_0_tagygirdh1 ((NU16)115)
#define CTagId_0_tagygirdh1 ((NU16)116)
#define BoolTagId_0_tagygirdh1 ((NU16)117)
#define VoidTagId_0_tagygirdh1 ((NU16)118)
#define PtrTagId_0_tagygirdh1 ((NU16)119)
#define ArrayTagId_0_tagygirdh1 ((NU16)120)
#define FlexarrayTagId_0_tagygirdh1 ((NU16)121)
#define AptrTagId_0_tagygirdh1 ((NU16)122)
#define CdeclTagId_0_tagygirdh1 ((NU16)123)
#define StdcallTagId_0_tagygirdh1 ((NU16)124)
#define SafecallTagId_0_tagygirdh1 ((NU16)125)
#define SyscallTagId_0_tagygirdh1 ((NU16)126)
#define FastcallTagId_0_tagygirdh1 ((NU16)127)
#define ThiscallTagId_0_tagygirdh1 ((NU16)128)
#define NoconvTagId_0_tagygirdh1 ((NU16)129)
#define MemberTagId_0_tagygirdh1 ((NU16)130)
#define NimcallTagId_0_tagygirdh1 ((NU16)131)
#define InlineTagId_0_tagygirdh1 ((NU16)132)
#define NoinlineTagId_0_tagygirdh1 ((NU16)133)
#define ClosureTagId_0_tagygirdh1 ((NU16)134)
#define AttrTagId_0_tagygirdh1 ((NU16)135)
#define SmryTagId_0_tagygirdh1 ((NU16)136)
#define VarargsTagId_0_tagygirdh1 ((NU16)137)
#define WasTagId_0_tagygirdh1 ((NU16)138)
#define SelectanyTagId_0_tagygirdh1 ((NU16)139)
#define PragmasTagId_0_tagygirdh1 ((NU16)140)
#define PragmaxTagId_0_tagygirdh1 ((NU16)141)
#define AlignTagId_0_tagygirdh1 ((NU16)142)
#define BitsTagId_0_tagygirdh1 ((NU16)143)
#define VectorTagId_0_tagygirdh1 ((NU16)144)
#define NodeclTagId_0_tagygirdh1 ((NU16)145)
#define InclTagId_0_tagygirdh1 ((NU16)146)
#define ExclTagId_0_tagygirdh1 ((NU16)147)
#define IncludeTagId_0_tagygirdh1 ((NU16)148)
#define ImportTagId_0_tagygirdh1 ((NU16)149)
#define ImportasTagId_0_tagygirdh1 ((NU16)150)
#define FromimportTagId_0_tagygirdh1 ((NU16)151)
#define ImportexceptTagId_0_tagygirdh1 ((NU16)152)
#define ExportTagId_0_tagygirdh1 ((NU16)153)
#define FromexportTagId_0_tagygirdh1 ((NU16)154)
#define ExportexceptTagId_0_tagygirdh1 ((NU16)155)
#define CommentTagId_0_tagygirdh1 ((NU16)156)
#define DiscardTagId_0_tagygirdh1 ((NU16)157)
#define TryTagId_0_tagygirdh1 ((NU16)158)
#define RaiseTagId_0_tagygirdh1 ((NU16)159)
#define OnerrTagId_0_tagygirdh1 ((NU16)160)
#define RaisesTagId_0_tagygirdh1 ((NU16)161)
#define ErrsTagId_0_tagygirdh1 ((NU16)162)
#define StaticTagId_0_tagygirdh1 ((NU16)163)
#define IteTagId_0_tagygirdh1 ((NU16)164)
#define ItecTagId_0_tagygirdh1 ((NU16)165)
#define LoopTagId_0_tagygirdh1 ((NU16)166)
#define VTagId_0_tagygirdh1 ((NU16)167)
#define EtupatTagId_0_tagygirdh1 ((NU16)168)
#define UnknownTagId_0_tagygirdh1 ((NU16)169)
#define JtrueTagId_0_tagygirdh1 ((NU16)170)
#define MflagTagId_0_tagygirdh1 ((NU16)171)
#define VflagTagId_0_tagygirdh1 ((NU16)172)
#define EitherTagId_0_tagygirdh1 ((NU16)173)
#define JoinTagId_0_tagygirdh1 ((NU16)174)
#define GraphTagId_0_tagygirdh1 ((NU16)175)
#define ForbindTagId_0_tagygirdh1 ((NU16)176)
#define KillTagId_0_tagygirdh1 ((NU16)177)
#define UnpackflatTagId_0_tagygirdh1 ((NU16)178)
#define UnpacktupTagId_0_tagygirdh1 ((NU16)179)
#define CallargsTagId_0_tagygirdh1 ((NU16)180)
#define ForcallTagId_0_tagygirdh1 ((NU16)181)
#define UnpackdeclTagId_0_tagygirdh1 ((NU16)182)
#define ExceptTagId_0_tagygirdh1 ((NU16)183)
#define FinTagId_0_tagygirdh1 ((NU16)184)
#define TupleTagId_0_tagygirdh1 ((NU16)185)
#define OnumTagId_0_tagygirdh1 ((NU16)186)
#define AnumTagId_0_tagygirdh1 ((NU16)187)
#define RefTagId_0_tagygirdh1 ((NU16)188)
#define MutTagId_0_tagygirdh1 ((NU16)189)
#define OutTagId_0_tagygirdh1 ((NU16)190)
#define LentTagId_0_tagygirdh1 ((NU16)191)
#define SinkTagId_0_tagygirdh1 ((NU16)192)
#define NiltTagId_0_tagygirdh1 ((NU16)193)
#define ConceptTagId_0_tagygirdh1 ((NU16)194)
#define DistinctTagId_0_tagygirdh1 ((NU16)195)
#define ItertypeTagId_0_tagygirdh1 ((NU16)196)
#define RangetypeTagId_0_tagygirdh1 ((NU16)197)
#define UarrayTagId_0_tagygirdh1 ((NU16)198)
#define SetTagId_0_tagygirdh1 ((NU16)199)
#define AutoTagId_0_tagygirdh1 ((NU16)200)
#define SymkindTagId_0_tagygirdh1 ((NU16)201)
#define TypekindTagId_0_tagygirdh1 ((NU16)202)
#define TypedescTagId_0_tagygirdh1 ((NU16)203)
#define UntypedTagId_0_tagygirdh1 ((NU16)204)
#define TypedTagId_0_tagygirdh1 ((NU16)205)
#define CstringTagId_0_tagygirdh1 ((NU16)206)
#define PointerTagId_0_tagygirdh1 ((NU16)207)
#define OrdinalTagId_0_tagygirdh1 ((NU16)208)
#define MagicTagId_0_tagygirdh1 ((NU16)209)
#define ImportcTagId_0_tagygirdh1 ((NU16)210)
#define ImportcppTagId_0_tagygirdh1 ((NU16)211)
#define DynlibTagId_0_tagygirdh1 ((NU16)212)
#define ExportcTagId_0_tagygirdh1 ((NU16)213)
#define HeaderTagId_0_tagygirdh1 ((NU16)214)
#define ThreadvarTagId_0_tagygirdh1 ((NU16)215)
#define GlobalTagId_0_tagygirdh1 ((NU16)216)
#define DiscardableTagId_0_tagygirdh1 ((NU16)217)
#define NoreturnTagId_0_tagygirdh1 ((NU16)218)
#define BorrowTagId_0_tagygirdh1 ((NU16)219)
#define NoSideEffectTagId_0_tagygirdh1 ((NU16)220)
#define NodestroyTagId_0_tagygirdh1 ((NU16)221)
#define PluginTagId_0_tagygirdh1 ((NU16)222)
#define BycopyTagId_0_tagygirdh1 ((NU16)223)
#define ByrefTagId_0_tagygirdh1 ((NU16)224)
#define NoinitTagId_0_tagygirdh1 ((NU16)225)
#define RequiresTagId_0_tagygirdh1 ((NU16)226)
#define EnsuresTagId_0_tagygirdh1 ((NU16)227)
#define AssumeTagId_0_tagygirdh1 ((NU16)228)
#define AssertTagId_0_tagygirdh1 ((NU16)229)
#define BuildTagId_0_tagygirdh1 ((NU16)230)
#define FeatureTagId_0_tagygirdh1 ((NU16)231)
#define StringTagId_0_tagygirdh1 ((NU16)232)
#define ViewTagId_0_tagygirdh1 ((NU16)233)
#define IncompleteStructTagId_0_tagygirdh1 ((NU16)234)
#define QQuotedTagId_0_tagygirdh1 ((NU16)235)
#define HderefTagId_0_tagygirdh1 ((NU16)236)
#define DdotTagId_0_tagygirdh1 ((NU16)237)
#define HaddrTagId_0_tagygirdh1 ((NU16)238)
#define NewrefTagId_0_tagygirdh1 ((NU16)239)
#define NewobjTagId_0_tagygirdh1 ((NU16)240)
#define TupTagId_0_tagygirdh1 ((NU16)241)
#define TupconstrTagId_0_tagygirdh1 ((NU16)242)
#define SetconstrTagId_0_tagygirdh1 ((NU16)243)
#define TabconstrTagId_0_tagygirdh1 ((NU16)244)
#define AshrTagId_0_tagygirdh1 ((NU16)245)
#define BaseobjTagId_0_tagygirdh1 ((NU16)246)
#define HconvTagId_0_tagygirdh1 ((NU16)247)
#define DconvTagId_0_tagygirdh1 ((NU16)248)
#define CallstrlitTagId_0_tagygirdh1 ((NU16)249)
#define InfixTagId_0_tagygirdh1 ((NU16)250)
#define PrefixTagId_0_tagygirdh1 ((NU16)251)
#define HcallTagId_0_tagygirdh1 ((NU16)252)
#define CompilesTagId_0_tagygirdh1 ((NU16)253)
#define DeclaredTagId_0_tagygirdh1 ((NU16)254)
#define DefinedTagId_0_tagygirdh1 ((NU16)255)
#define AstToStrTagId_0_tagygirdh1 ((NU16)256)
#define BindSymTagId_0_tagygirdh1 ((NU16)257)
#define BindSymNameTagId_0_tagygirdh1 ((NU16)258)
#define InstanceofTagId_0_tagygirdh1 ((NU16)259)
#define ProccallTagId_0_tagygirdh1 ((NU16)260)
#define HighTagId_0_tagygirdh1 ((NU16)261)
#define LowTagId_0_tagygirdh1 ((NU16)262)
#define TypeofTagId_0_tagygirdh1 ((NU16)263)
#define UnpackTagId_0_tagygirdh1 ((NU16)264)
#define FieldsTagId_0_tagygirdh1 ((NU16)265)
#define FieldpairsTagId_0_tagygirdh1 ((NU16)266)
#define EnumtostrTagId_0_tagygirdh1 ((NU16)267)
#define IsmainmoduleTagId_0_tagygirdh1 ((NU16)268)
#define DefaultobjTagId_0_tagygirdh1 ((NU16)269)
#define DefaulttupTagId_0_tagygirdh1 ((NU16)270)
#define DefaultdistinctTagId_0_tagygirdh1 ((NU16)271)
#define DelayTagId_0_tagygirdh1 ((NU16)272)
#define Delay0TagId_0_tagygirdh1 ((NU16)273)
#define SuspendTagId_0_tagygirdh1 ((NU16)274)
#define ExprTagId_0_tagygirdh1 ((NU16)275)
#define DoTagId_0_tagygirdh1 ((NU16)276)
#define ArratTagId_0_tagygirdh1 ((NU16)277)
#define TupatTagId_0_tagygirdh1 ((NU16)278)
#define PlussetTagId_0_tagygirdh1 ((NU16)279)
#define MinussetTagId_0_tagygirdh1 ((NU16)280)
#define MulsetTagId_0_tagygirdh1 ((NU16)281)
#define XorsetTagId_0_tagygirdh1 ((NU16)282)
#define EqsetTagId_0_tagygirdh1 ((NU16)283)
#define LesetTagId_0_tagygirdh1 ((NU16)284)
#define LtsetTagId_0_tagygirdh1 ((NU16)285)
#define InsetTagId_0_tagygirdh1 ((NU16)286)
#define CardTagId_0_tagygirdh1 ((NU16)287)
#define EmoveTagId_0_tagygirdh1 ((NU16)288)
#define DestroyTagId_0_tagygirdh1 ((NU16)289)
#define DupTagId_0_tagygirdh1 ((NU16)290)
#define CopyTagId_0_tagygirdh1 ((NU16)291)
#define WasmovedTagId_0_tagygirdh1 ((NU16)292)
#define SinkhTagId_0_tagygirdh1 ((NU16)293)
#define TraceTagId_0_tagygirdh1 ((NU16)294)
#define ErrvTagId_0_tagygirdh1 ((NU16)295)
#define StaticstmtTagId_0_tagygirdh1 ((NU16)296)
#define BindTagId_0_tagygirdh1 ((NU16)297)
#define MixinTagId_0_tagygirdh1 ((NU16)298)
#define UsingTagId_0_tagygirdh1 ((NU16)299)
#define AsmTagId_0_tagygirdh1 ((NU16)300)
#define DeferTagId_0_tagygirdh1 ((NU16)301)
#define IndexTagId_0_tagygirdh1 ((NU16)302)
#define InjectTagId_0_tagygirdh1 ((NU16)303)
#define GensymTagId_0_tagygirdh1 ((NU16)304)
#define DirtyTagId_0_tagygirdh1 ((NU16)305)
#define ErrorTagId_0_tagygirdh1 ((NU16)306)
#define ReportTagId_0_tagygirdh1 ((NU16)307)
#define TagsTagId_0_tagygirdh1 ((NU16)308)
#define DeprecatedTagId_0_tagygirdh1 ((NU16)309)
#define SideEffectTagId_0_tagygirdh1 ((NU16)310)
#define KeepOverflowFlagTagId_0_tagygirdh1 ((NU16)311)
#define SemanticsTagId_0_tagygirdh1 ((NU16)312)
#define InheritableTagId_0_tagygirdh1 ((NU16)313)
#define BaseTagId_0_tagygirdh1 ((NU16)314)
#define PureTagId_0_tagygirdh1 ((NU16)315)
#define FinalTagId_0_tagygirdh1 ((NU16)316)
#define AcyclicTagId_0_tagygirdh1 ((NU16)317)
#define PragmaTagId_0_tagygirdh1 ((NU16)318)
#define InternalTypeNameTagId_0_tagygirdh1 ((NU16)319)
#define InternalFieldPairsTagId_0_tagygirdh1 ((NU16)320)
#define FailedTagId_0_tagygirdh1 ((NU16)321)
#define IsTagId_0_tagygirdh1 ((NU16)322)
#define EnvpTagId_0_tagygirdh1 ((NU16)323)
#define PackedTagId_0_tagygirdh1 ((NU16)324)
#define PassiveTagId_0_tagygirdh1 ((NU16)325)
#define PushTagId_0_tagygirdh1 ((NU16)326)
#define CallConvTagId_0_tagygirdh1 ((NU16)327)
#define PopTagId_0_tagygirdh1 ((NU16)328)
#define PassLTagId_0_tagygirdh1 ((NU16)329)
#define PassCTagId_0_tagygirdh1 ((NU16)330)
#define MethodsTagId_0_tagygirdh1 ((NU16)331)
#define SizeTagId_0_tagygirdh1 ((NU16)332)
#define UncheckedAccessTagId_0_tagygirdh1 ((NU16)333)
#define UncheckedAssignTagId_0_tagygirdh1 ((NU16)334)
#define ProfilerTagId_0_tagygirdh1 ((NU16)335)
#define StacktraceTagId_0_tagygirdh1 ((NU16)336)
#define GcsafeTagId_0_tagygirdh1 ((NU16)337)
#define UsedTagId_0_tagygirdh1 ((NU16)338)
#define CompileTagId_0_tagygirdh1 ((NU16)339)
#define BundleTagId_0_tagygirdh1 ((NU16)340)
#define ToClosureTagId_0_tagygirdh1 ((NU16)341)
typedef NU8 LoadStatus_0_prorcx25w1;

#define LacksModuleName_0_prorcx25w1 ((NU8)0)
#define LacksOffset_0_prorcx25w1 ((NU8)1)
#define LacksPosition_0_prorcx25w1 ((NU8)2)
#define LacksNothing_0_prorcx25w1 ((NU8)3)
typedef struct LoadResult_0_prorcx25w1{
  LoadStatus_0_prorcx25w1 status_0;
  Cursor_0_nifb6mq6y1 decl_0;}
LoadResult_0_prorcx25w1;
typedef NU8 NimonySym_0_nimry5ra91;

#define NoSym_0_nimry5ra91 ((NU8)0)
#define GvarY_0_nimry5ra91 ((NU8)54)
#define TvarY_0_nimry5ra91 ((NU8)55)
#define VarY_0_nimry5ra91 ((NU8)56)
#define ParamY_0_nimry5ra91 ((NU8)57)
#define ConstY_0_nimry5ra91 ((NU8)58)
#define ResultY_0_nimry5ra91 ((NU8)59)
#define GletY_0_nimry5ra91 ((NU8)60)
#define TletY_0_nimry5ra91 ((NU8)61)
#define LetY_0_nimry5ra91 ((NU8)62)
#define CursorY_0_nimry5ra91 ((NU8)63)
#define PatternvarY_0_nimry5ra91 ((NU8)64)
#define TypevarY_0_nimry5ra91 ((NU8)65)
#define StaticTypevarY_0_nimry5ra91 ((NU8)66)
#define EfldY_0_nimry5ra91 ((NU8)67)
#define FldY_0_nimry5ra91 ((NU8)68)
#define GfldY_0_nimry5ra91 ((NU8)69)
#define ProcY_0_nimry5ra91 ((NU8)70)
#define FuncY_0_nimry5ra91 ((NU8)71)
#define IteratorY_0_nimry5ra91 ((NU8)72)
#define ConverterY_0_nimry5ra91 ((NU8)73)
#define MethodY_0_nimry5ra91 ((NU8)74)
#define MacroY_0_nimry5ra91 ((NU8)75)
#define TemplateY_0_nimry5ra91 ((NU8)76)
#define TypeY_0_nimry5ra91 ((NU8)77)
#define BlockY_0_nimry5ra91 ((NU8)78)
#define ModuleY_0_nimry5ra91 ((NU8)79)
#define CchoiceY_0_nimry5ra91 ((NU8)80)
typedef struct TypeDecl_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 typevars_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 body_0;}
TypeDecl_0_decqocs071;
typedef NU8 MarshalClass_0_marbdjk4t1;

#define mcScalar_0_marbdjk4t1 ((NU8)0)
#define mcPod_0_marbdjk4t1 ((NU8)1)
#define mcString_0_marbdjk4t1 ((NU8)2)
#define mcSeq_0_marbdjk4t1 ((NU8)3)
#define mcRef_0_marbdjk4t1 ((NU8)4)
#define mcClosure_0_marbdjk4t1 ((NU8)5)
#define mcUnsafe_0_marbdjk4t1 ((NU8)6)
typedef struct Routine_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 pattern_0;
  Cursor_0_nifb6mq6y1 typevars_0;
  Cursor_0_nifb6mq6y1 params_0;
  Cursor_0_nifb6mq6y1 retType_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 effects_0;
  Cursor_0_nifb6mq6y1 body_0;}
Routine_0_decqocs071;
typedef struct Local_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 typ_0;
  Cursor_0_nifb6mq6y1 val_0;}
Local_0_decqocs071;
typedef struct CrossOutcome_0_croph25r5{
  NB8 handled_0;
  Value_0_valzr1t4f v_0;
  CrossRoute_0_croph25r5 route_0;
  string_0_sysvq0asl detail_0;}
CrossOutcome_0_croph25r5;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct ArenaMat_0_arecyyj7v{
  X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* a_0;
  seq_0_Isge9lx_arecyyj7v seen_0;
  seq_0_Idhq52f_arecyyj7v blocks_0;
  seq_0_Ijes23h1_arecyyj7v regions_0;}
ArenaMat_0_arecyyj7v;
typedef struct BlockEntry_0_arecyyj7v{
  NU32 key_0;
  NU32 data_0;
  NI32 stride_0;
  NI32 count_0;
  X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sq_0;
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arr_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_0;}
BlockEntry_0_arecyyj7v;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef NU8 SkipMode_0_decqocs071;

#define SkipExclBody_0_decqocs071 ((NU8)0)
#define SkipInclBody_0_decqocs071 ((NU8)1)
#define SkipFinalParRi_0_decqocs071 ((NU8)2)
typedef NU8 DeclineStage_0_croph25r5;

#define dsCensus_0_croph25r5 ((NU8)0)
#define dsMarshal_0_croph25r5 ((NU8)1)
#define dsCallee_0_croph25r5 ((NU8)2)
#define dsArena_0_croph25r5 ((NU8)3)
#define dsAnalysis_0_croph25r5 ((NU8)4)
#define dsJit_0_croph25r5 ((NU8)5)
#define dsBuild_0_croph25r5 ((NU8)6)
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
typedef struct MatEntry_0_arecyyj7v{
  NU32 key_0;
  NU32 box_0;}
MatEntry_0_arecyyj7v;
typedef struct RegionHandout_0_arecyyj7v{
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_0;
  NU32 base_0;
  NI32 size_0;}
RegionHandout_0_arecyyj7v;
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
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
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
NB8 jitTraceLog_0_run8hsnpi(void);
Value_0_valzr1t4f scalarFromBits_0_run8hsnpi(NU64 u_2, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_9, NU32 typeSym_3);
X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi podFieldInfo_1_run8hsnpi(NU32 typeSym_4);
static inline void add_0_Ijteip9_run8hsnpi(seq_0_I3ump14_aow7lb5cq1* s_47, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_17);
static inline seq_0_Ixkko8n_run8hsnpi newSeqUninit_0_Iyquyq_run8hsnpi(NI32 size_21);
static inline openArray_0_Ihcf6y9_run8hsnpi toOpenArray_1_Iumnf4i1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_53);
static inline void add_0_Itzi0i7_run8hsnpi(seq_0_Il8twp61_aow7lb5cq1* s_59, WireField_0_run8hsnpi elem_18);
static inline void add_0_Ibphvmo_run8hsnpi(seq_0_Incv1wn_arecyyj7v* s_75, NU8 elem_22);
static inline NI32 len_3_Irjnvku_run8hsnpi(seq_0_Ik7wkpe_aow7lb5cq1 s_87);
static inline seq_0_Ie7vbta_run8hsnpi newSeqUninit_0_I32zp0x_run8hsnpi(NI32 size_40);
static inline void add_0_Ivy8r7k1_run8hsnpi(seq_0_Ie7vbta_run8hsnpi* s_91, X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi elem_26);
static inline openArray_0_Icv4v4b1_run8hsnpi toOpenArray_1_Io2cvnr_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_93);
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* getOrDefault_1_Imr3kd01_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_15, NU32 k_6, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* fallback_1);
static inline NI32 len_0_Ifyaclq_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_17);
static inline seq_0_Iq1shzq1_run8hsnpi newSeqUninit_0_Ie5g2lj_run8hsnpi(NI32 size_48);
static inline void add_0_Ii05ltt1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi* s_97, X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi elem_27);
static inline NI32 len_3_Iibq2ff1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_99);
static inline X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* getQ_7_Ir6lnzn1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_100, NI32 i_59);
Table_0_Ivb80lo_run8hsnpi initTable_0_Iag3oaw1_run8hsnpi(void);
void putQ_0_I4rb4at_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_18, NU32 k_8, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* v_10);
static inline void add_0_Ixve43b1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi* s_104, X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* elem_28);
NB8 resize_0_Ithn1vs_run8hsnpi(seq_0_I3ump14_aow7lb5cq1* dest_11, NI32 addedElements_11);
static inline NI32 memSizeInBytes_0_Irm6f661_run8hsnpi(NI32 size_54);
static inline X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** rawData_0_Ix1iq6g1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_110);
static inline NI32 len_6_Ij4lmhs_run8hsnpi(openArray_0_Ihcf6y9_run8hsnpi a_24);
static inline X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** getQ_10_Iwwsp9w1_run8hsnpi(openArray_0_Ihcf6y9_run8hsnpi x_15, NI32 idx_14);
NB8 resize_0_I6di9mo1_run8hsnpi(seq_0_Il8twp61_aow7lb5cq1* dest_12, NI32 addedElements_12);
static inline NI32 memSizeInBytes_0_Ip0vdbh_run8hsnpi(NI32 size_63);
static inline NI32 capInBytes_0_Ivcwflf1_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_122);
NB8 resize_0_Igrgn3v_run8hsnpi(seq_0_Ie7vbta_run8hsnpi* dest_19, NI32 addedElements_19);
static inline X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* rawData_0_Ir5lda7_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_123);
static inline NI32 len_6_Ivyewcw1_run8hsnpi(openArray_0_Icv4v4b1_run8hsnpi a_28);
static inline X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* getQ_10_Ijhkrt71_run8hsnpi(openArray_0_Icv4v4b1_run8hsnpi x_20, NI32 idx_18);
NI32 rawGet_0_Ihcxbwv_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_20, NU32 k_10, NU32 kh_1);
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* getQ_7_I46cuah_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_126, NI32 i_66);
static inline NI32 len_3_I849zvk_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_127);
static inline NI32 memSizeInBytes_0_Ifk9c7h1_run8hsnpi(NI32 size_67);
static inline NI32 capInBytes_0_In8my0q1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_128);
NB8 resize_0_I5hcuwh1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi* dest_20, NI32 addedElements_20);
static inline seq_0_Iwk350i1_run8hsnpi newSeqUninit_0_Iyp3d871_run8hsnpi(NI32 size_68);
void rawPut_0_Ifxcxpb1_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_21, NU32 k_11, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* v_12, NU32 h_4);
static inline NI32 capInBytes_0_I0n41e91_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_133);
NB8 resize_0_I9hyasp_run8hsnpi(seq_0_Ixkko8n_run8hsnpi* dest_21, NI32 addedElements_21);
static inline NI32 memSizeInBytes_0_I7xitnl1_run8hsnpi(NI32 size_72);
void fillHashPart_0_I20rkt9_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_23);
static inline void add_0_Ihgv7q7_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* s_137, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi elem_31);
static inline NI32 capInBytes_0_Ilido7m1_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_140);
NB8 resize_0_Ie728b71_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* dest_23, NI32 addedElements_23);
void eQdestroy_1_I2vp2bj_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_214);
void eQdestroy_1_Imh4l59_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_225);
void eQdestroyQ_SX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(HybridProvider_Obj_0_run8hsnpi* dest_0);
void eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi(WireField_0_run8hsnpi* dest_0);
void eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi(WireField_0_run8hsnpi* dest_0);
WireField_0_run8hsnpi eQdupQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi(WireField_0_run8hsnpi* src_0);
void eQdestroyQ_SX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(CabiGenProvider_Obj_0_run8hsnpi* dest_0);
void eQtraceQ_SX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(CabiGenProvider_Obj_0_run8hsnpi* dest_0, void* src_0);
void eQdestroyQ_SX54able0X49vb80lo_0_run8hsnpi(Table_0_Ivb80lo_run8hsnpi dest_0);
void eQwasmovedQ_SX54able0X49vb80lo_0_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* dest_0);
void eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* dest_0);
void eQdestroyQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* dest_0);
void eQwasmovedQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** dest_0);
void eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0);
void eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** dest_0);
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* src_0);
void eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* dest_0);
void eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* dest_0);
void eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_run8hsnpi(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* dest_0);
void eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_run8hsnpi(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* dest_0);
void eQtraceQ_ArefSX41renaX4fbj0arewp645e1_0_run8hsnpi(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v** dest_0, void* src_0);
void eQtraceQ_ArefSX58X50roviderX4fbj0croph25r5_0_run8hsnpi(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1** dest_0, void* src_0);
void eQwasmovedQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax** dest_0);
void eQwasmovedQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi* dest_0);
void eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi dest_0);
void eQwasmovedQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi* dest_0);
void eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi dest_0);
void eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21* dest_0);
void eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 dest_0);
void eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi dest_0);
void eQwasmovedQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi(X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi* dest_0);
void eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi(X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi* dest_0);
void eQwasmovedQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax* dest_0);
void eQdestroyQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax dest_0);
void eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** dest_0);
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi* dest_0);
void eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_run8hsnpi(X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 dest_0);
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_run8hsnpi(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v* dest_0);
X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* eQdupQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* src_0);
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* src_0);
void eQdestroyQ_AtupleAiS32ZSX56alue0valzr1t4f_0_run8hsnpi(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* dest_0);
void eQdestroyQ_AtupleSX56alue0valzr1t4fApointer_0_run8hsnpi(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* dest_0);
void eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi dest_0);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13);
static inline string_0_sysvq0asl* getQ_0_I93d71y_der823rwr1(BiTable_0_Icvz6lt_buiyylk1h1 t_5, NU32 litId_1);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14);
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern void extractBasename_1_symkyk35i1(string_0_sysvq0asl* s_1);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern LongString_0_sysvq0asl const strlit_0_I4511345809429878981_aow7lb5cq1;
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_I3ump14_aow7lb5cq1 newSeqUninit_0_I978ktq1_aow7lb5cq1(NI32 size_30);
static inline seq_0_Ie088gc_heapjafyf1 newSeqUninit_0_Inwn9fa_heapjafyf1(NI32 size_4);
extern LoadResult_0_prorcx25w1 tryLoadSymSafe_0_modzy18mg1(NU32 s_0);
extern LongString_0_sysvq0asl const strlit_0_I13413619771642637377_emi78vuj01;
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
extern TypeDecl_0_decqocs071 asTypeDecl_0_decqocs071(Cursor_0_nifb6mq6y1 c_10);
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
extern void eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071(TypeDecl_0_decqocs071* dest_0);
extern LongString_0_sysvq0asl const strlit_0_I973692718279674627_emi78vuj01;
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I11024699549390617459_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I10462096440466995513_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I3021806080610957510_fiepkwzpc;
extern LongString_0_sysvq0asl const strlit_0_I14845240230376595005_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I6008424852838151324_nimry5ra91;
extern LongString_0_sysvq0asl const strlit_0_I3225181402180923291_fiepkwzpc;
extern LongString_0_sysvq0asl const strlit_0_I6300154543333844069_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I18029839360381635789_intzsnzax;
extern LongString_0_sysvq0asl const strlit_0_I5595596763809202512_nim30udrv;
extern LongString_0_sysvq0asl const strlit_0_I1177603226064417776_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I14727864736786204059_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I5316556160589403975_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I18086024188298164462_buiyylk1h1;
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10);
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6);
extern LongString_0_sysvq0asl const strlit_0_I2171368188661376471_emi78vuj01;
extern X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* enumDesc_0_layptix6a1(NI32 lo_0, NI32 hi_0, NI32 bits_1);
extern LongString_0_sysvq0asl const strlit_0_I16393544569146403439_intzsnzax;
extern void eQdestroy_1_Iqg9snl1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_105);
static inline void eQwasMoved_1_Iba95rl_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1* s_106);
extern LongString_0_sysvq0asl const strlit_0_I4956278306908871092_emi78vuj01;
static inline openArray_0_I3ca6t4_layptix6a1 toOpenArray_1_I0zz6qv1_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_8);
static inline NI32 len_6_I0tpktl1_layptix6a1(openArray_0_I3ca6t4_layptix6a1 a_18);
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_10_Ikixp7k_layptix6a1(openArray_0_I3ca6t4_layptix6a1 x_3, NI32 idx_2);
extern MarshalClass_0_marbdjk4t1 marshalClass_0_marbdjk4t1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_8);
extern NB8 isArenaPtrAggregate_0_marbdjk4t1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_7);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern Routine_0_decqocs071 asRoutine_0_decqocs071(Cursor_0_nifb6mq6y1 c_8, SkipMode_0_decqocs071 mode_3);
extern LongString_0_sysvq0asl const strlit_0_I5367917178860180580_der823rwr1;
extern Local_0_decqocs071 takeLocal_0_decqocs071(Cursor_0_nifb6mq6y1* c_4, SkipMode_0_decqocs071 mode_0);
extern void eQdestroyQ_SX4cocal0decqocs071_0_decqocs071(Local_0_decqocs071* dest_0);
extern void eQdestroyQ_SX52outine0decqocs071_0_decqocs071(Routine_0_decqocs071* dest_0);
extern void declineBegin_0_croph25r5(string_0_sysvq0asl callee_0);
extern void declineNote_0_croph25r5(DeclineStage_0_croph25r5 stage_0, string_0_sysvq0asl reason_1);
extern void eQwasmovedQ_SX43rossX4futcome0croph25r5_0_croph25r5(CrossOutcome_0_croph25r5* dest_0);
extern CrossOutcome_0_croph25r5 crossDecline_0_croph25r5(CrossRoute_0_croph25r5 route_1, string_0_sysvq0asl reason_0);
extern CrossOutcome_0_croph25r5 crossOk_0_croph25r5(Value_0_valzr1t4f* v_0, CrossRoute_0_croph25r5 route_0, string_0_sysvq0asl detail_0);
extern NB8 routeLog_0_croph25r5(void);
extern string_0_sysvq0asl blockerReason_0_croph25r5(void);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern void eQdestroyQ_SX43rossX4futcome0croph25r5_0_croph25r5(CrossOutcome_0_croph25r5* dest_0);
extern string_0_sysvq0asl getEnv_0_envto7w6l1(string_0_sysvq0asl key_1, string_0_sysvq0asl default_0);
extern LongString_0_sysvq0asl const strlit_0_I819492781050547440_croph25r5;
extern LongString_0_sysvq0asl const strlit_0_I6946320866761157030_aow7lb5cq1;
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_29);
static inline NC8* getQ_10_I5nt6we_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 x_12, NI32 idx_6);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
extern LongString_0_sysvq0asl const strlit_0_I17873677997389965638_red2rogzl;
extern LongString_0_sysvq0asl const strlit_0_I17450945768583924279_red2rogzl;
extern LongString_0_sysvq0asl const strlit_0_I6136553206224205495_red2rogzl;
extern LongString_0_sysvq0asl const strlit_0_I7032352044772062024_red2rogzl;
extern LongString_0_sysvq0asl const strlit_0_I1184649450617298588_red2rogzl;
extern LongString_0_sysvq0asl const strlit_0_I13604536769712135534_red2rogzl;
extern LongString_0_sysvq0asl const strlit_0_I18357185398770638485_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I589554620119875380_red2rogzl;
extern LongString_0_sysvq0asl const strlit_0_I11643015150811461308_aow7lb5cq1;
extern LongString_0_sysvq0asl const strlit_0_I3703322799828345117_aow7lb5cq1;
extern NI32 setSizeInBytes_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* base_4);
static inline NI32 len_3_I5m68tr1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_33);
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37);
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33);
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_7_I45w7c91_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_34, NI32 i_37);
extern LongString_0_sysvq0asl const strlit_0_I16597999082088934835_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I16971225136864641703_nimry5ra91;
extern LongString_0_sysvq0asl const strlit_0_I9228293753161605925_maglvku5g;
extern LongString_0_sysvq0asl const strlit_0_I990882640025799687_marbdjk4t1;
extern LongString_0_sysvq0asl const strlit_0_I3470422228391514573_marbdjk4t1;
extern LongString_0_sysvq0asl const strlit_0_I696057604909997793_marbdjk4t1;
extern LongString_0_sysvq0asl const strlit_0_I17665588267585860306_marbdjk4t1;
extern LongString_0_sysvq0asl const strlit_0_I8160649543150574237_marbdjk4t1;
extern LongString_0_sysvq0asl const strlit_0_I12549307355442489107_marbdjk4t1;
extern LongString_0_sysvq0asl const strlit_0_I3538386510047344326_marbdjk4t1;
extern string_0_sysvq0asl dollarX60Q_AbiKind_0_layptix6a1(AbiKind_0_layptix6a1 e_0);
extern X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sizeAlign_1_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_3, NI32 ptrSize_2);
static inline NI32 align_0_layptix6a1(NI32 address_0, NI32 alignment_0);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern LongString_0_sysvq0asl const strlit_0_I16157109470490228308_red2rogzl;
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
extern LongString_0_sysvq0asl const strlit_0_I409803864855967452_obs4v9ato1;
extern LongString_0_sysvq0asl const strlit_0_I6105018409752412263_dbg4n0xd21;
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void minusQeQ_0_Ipe1u69_hos5i19e11(NI32* x_5, NI32 y_1);
static inline seq_0_Il8twp61_aow7lb5cq1 newSeqUninit_0_Iopvcdu1_aow7lb5cq1(NI32 size_28);
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline seq_0_Ik7wkpe_aow7lb5cq1 newSeqUninit_0_Idxnvmq_aow7lb5cq1(NI32 size_12);
extern LongString_0_sysvq0asl const strlit_0_I11155032387348830029_aow7lb5cq1;
static inline openArray_0_Iczu4791_aow7lb5cq1 toOpenArray_1_I0ef4be1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_29);
static inline NI32 len_6_Ier6z6r1_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 a_28);
static inline WireField_0_run8hsnpi* getQ_10_Id2924z_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 x_11, NI32 idx_5);
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13);
static inline NI32 len_3_In63jw61_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_31);
static inline WireField_0_run8hsnpi* getQ_7_Iko57h9_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_32, NI32 i_36);
extern void eQdestroy_1_Ij4pznj1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_98);
extern seq_0_Ift2sne_aow7lb5cq1 newSeq_0_I7328u4_flaksyopx1(NI32 size_13);
static inline void add_0_Iivdbhc_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1* s_49, seq_0_Ift2sne_aow7lb5cq1 elem_14);
extern NI64 asInt_0_valzr1t4f(Value_0_valzr1t4f* v_17);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
static inline void putQ_7_Ipw0nqk1_explnj22x1(seq_0_Incv1wn_arecyyj7v* s_29, NI32 i_26, NU8 elem_9);
static inline NU8* getQ_7_Ig0r1051_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_32, NI32 i_30);
extern seq_0_Ift2sne_aow7lb5cq1 fieldOffsets_0_layptix6a1(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_4, NI32 ptrSize_3);
extern void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
static inline NI32 len_3_I83dzei_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_25);
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45);
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_26, NI32 i_28);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_42);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern void* materializePtr_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_12, Value_0_valzr1t4f* v_6, NB8 noDeref_0, NI32 wantSize_1);
extern BlockEntry_0_arecyyj7v seqBlock_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_7, X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_0);
extern void eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v(BlockEntry_0_arecyyj7v* dest_0);
static inline void eQwasMoved_1_I861g1c1_arecyyj7v(seq_0_Incv1wn_arecyyj7v* s_79);
extern void eQdestroy_1_Ijx6eoq_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_78);
extern seq_0_Incv1wn_arecyyj7v newSeq_0_Ivbxvoi1_explnj22x1(NI32 size_3);
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern Value_0_valzr1t4f vNil_0_valzr1t4f(void);
extern string_0_sysvq0asl dollarQ_0_valzr1t4f(Value_0_valzr1t4f* v_19);
static inline NI32 len_3_Izoe8zv_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_31);
extern void setLen_0_I9zf5sf1_flaksyopx1(seq_0_Incv1wn_arecyyj7v* s_41, NI32 newLen_1);
static inline seq_0_In6doa_arecyyj7v newSeqUninit_0_Ieodq4s1_arecyyj7v(NI32 size_28);
static inline seq_0_Iw8xl5b1_arecyyj7v newSeqUninit_0_I1tbjnk1_arecyyj7v(NI32 size_24);
static inline void add_0_I34il1q_der823rwr1(seq_0_In6doa_arecyyj7v* s_12, NU32 elem_2);
extern X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* newCell_0_valzr1t4f(Value_0_valzr1t4f* v_0);
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_arecyyj7v* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8);
extern Value_0_valzr1t4f vStr_0_valzr1t4f(string_0_sysvq0asl s_0);
static inline openArray_0_Is74e021_explnj22x1 toOpenArray_1_Itrkyf61_explnj22x1(seq_0_Incv1wn_arecyyj7v s_27);
static inline NI32 len_6_Itc4yka_explnj22x1(openArray_0_Is74e021_explnj22x1 a_42);
static inline NU8* getQ_10_Ikgj4ax_explnj22x1(openArray_0_Is74e021_explnj22x1 x_33, NI32 idx_5);
extern Value_0_valzr1t4f vEnum_0_valzr1t4f(NI32 ord_0, NU32 ekind_0);
extern Value_0_valzr1t4f reinterpToInt_0_flaksyopx1(NU64 raw_0, NI32 tbits_0, NB8 tsigned_0);
extern Value_0_valzr1t4f vUInt_0_valzr1t4f(NU64 x_4, NI32 bits_2);
extern Value_0_valzr1t4f vFloat_0_valzr1t4f(NF64 f_0, NI32 bits_4);
extern Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0);
extern Value_0_valzr1t4f vChar_0_valzr1t4f(NC8 c_0);
extern LongString_0_sysvq0asl const strlit_0_I8845991054942562031_intzsnzax;
extern X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 fieldVerdict_0_der823rwr1(NU32 calleeSym_0, NI32 paramIdx_0, NU32 fieldSym_0);
extern NB8 fieldNeverTouched_0_der823rwr1(NU32 calleeSym_1, NI32 paramIdx_1, NU32 fieldSym_1);
static inline seq_0_Ift2sne_aow7lb5cq1* getQ_7_Iurb46i_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_51, NI32 i_43);
extern LongString_0_sysvq0asl const strlit_0_I17300657558726488198_intzsnzax;
extern string_0_sysvq0asl giveUpName_0_der823rwr1(AnGiveUp_0_der823rwr1 g_0);
extern LongString_0_sysvq0asl const strlit_0_I12933864966599503538_der823rwr1;
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
static inline Value_0_valzr1t4f vPtrLoc_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1);
extern Value_0_valzr1t4f vPtrReg_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* reg_1, NI32 fo_1, NI16 eb_1, TCode_0_valzr1t4f ec_1);
static inline NI32 base_0_valzr1t4f(Value_0_valzr1t4f* v_6);
static inline X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0_valzr1t4f(Value_0_valzr1t4f* v_7);
static inline NI32 foff_0_valzr1t4f(Value_0_valzr1t4f* v_8);
static inline seq_0_I50urnw_croph25r5 newSeqUninit_0_I8oufjc_croph25r5(NI32 size_10);
extern void eQdestroy_1_Inxd7ue1_croph25r5(seq_0_I50urnw_croph25r5 s_23);
static inline void add_0_Itre92n_intzsnzax(seq_0_I50urnw_croph25r5* s_140, Value_0_valzr1t4f elem_31);
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_143, NI32 i_95);
extern X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flObjRegion_0_flaksyopx1(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_2);
extern void setByteAt_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_4, NI32 off_2, NU8 b_1);
extern X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v unmaterializePtr_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_11, NU32 a_1, Value_0_valzr1t4f* old_0);
static inline void nimInvalidObjConv(string_0_sysvq0asl name_0);
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_142);
extern NC8* toCString_0_sysvq0asl(string_0_sysvq0asl* s_64);
static inline seq_0_Isge9lx_arecyyj7v newSeqUninit_0_Iglb3hm1_arecyyj7v(NI32 size_4);
static inline seq_0_Idhq52f_arecyyj7v newSeqUninit_0_I7mggr11_arecyyj7v(NI32 size_6);
static inline seq_0_Ijes23h1_arecyyj7v newSeqUninit_0_I1oegnq1_arecyyj7v(NI32 size_8);
extern X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* newArena_0_arewp645e1(NI32 chunkSize_0);
extern void arenaReset_0_arewp645e1(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* a_5);
extern void eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v(ArenaMat_0_arecyyj7v* dest_0);
extern ArenaMat_0_arecyyj7v initArenaMat_0_arecyyj7v(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* a_0);
extern void* materialize_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_19, Value_0_valzr1t4f* v_11);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
extern NB8 grantsHonoured_0_croph25r5(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* p_2);
extern seq_0_Ift2sne_aow7lb5cq1 eQdup_1_Iplow11_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 a_44);
extern void bump_0_croph25r5(NI32 c_0, NI32 by_0);
extern NI32 const cAnHonoured_0_croph25r5;
extern NI32 const cAnRevoked_0_croph25r5;
extern NB8 arenaMatFailed_0_arecyyj7v;
extern NI32 const cArenaDeclines_0_croph25r5;
extern NI32 countOf_0_croph25r5(NI32 c_1);
extern string_0_sysvq0asl arenaReport_0_arecyyj7v(void);
extern LongString_0_sysvq0asl const strlit_0_I13319807167292544980_aow7lb5cq1;
extern NI32 const cHybridCalls_0_croph25r5;
extern void syncBack_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_17, Value_0_valzr1t4f* v_10, void* root_0);
extern void syncBlocks_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_18);
extern LongString_0_sysvq0asl const strlit_0_I11209019673050966371_intzsnzax;
static inline openArray_0_In0ukmu_aow7lb5cq1 toOpenArray_1_Ijdwnsz_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_60);
static inline NI32 len_6_Iu1dtri1_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 a_33);
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** getQ_10_I6a58n11_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 x_15, NI32 idx_9);
extern X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* newXProvider_0_croph25r5(string_0_sysvq0asl name_1, X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251ZSstring0sysvq0aslSseq0X4950urnwSX56alue0valzr1t4fAnimcallZAfalseZAR91_croph25r5 run_0, X60Qt_0_ISstring0sysvq0aslSX43rossX52oute0croph25r5AnimcallZAfalseZAR51_croph25r5 route_2, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_0, string_0_sysvq0asl artifact_0);
static inline NI32 len_3_I44vue3_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_59);
static inline NI32 capInBytes_0_Iho46001_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_109);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 capInBytes_0_I51wdad1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_108);
static inline NI32 capInBytes_0_Iffahgv_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_88);
extern NB8 resize_0_Iuiuhg71_flaksyopx1(seq_0_Incv1wn_arecyyj7v* dest_7, NI32 addedElements_7);
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline seq_0_Ikxuplm1_der823rwr1 newSeqUninit_0_Iie69x21_der823rwr1(NI32 size_10);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
static inline NI32 memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(NI32 size_31);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
static inline NI32 memSizeInBytes_0_Io786y61_aow7lb5cq1(NI32 size_29);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 high_3_Iyuup9h1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_28);
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_29, NU32 i_17);
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2);
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0);
static inline NI32 len_3_Iiefpcc1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_30);
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0);
extern void resize_0_tabcr240b1(seq_0_Ikxuplm1_der823rwr1* t_0);
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7);
extern void eQdestroy_1_I5skmro_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_53);
extern seq_0_Ikxuplm1_der823rwr1 newSeq_0_Iv3lu2h1_der823rwr1(NI32 size_17);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
extern void eQdestroy_1_Iksn09f_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_102);
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void eQdestroyQ_SX54ypeX44escX4fbj0layptix6a1_0_layptix6a1(TypeDesc_Obj_0_layptix6a1* dest_0);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void eQdestroyQ_SX58X50roviderX4fbj0croph25r5_0_croph25r5(XProvider_Obj_0_croph25r5* dest_0);
extern void eQdestroyQ_SX41renaX4fbj0arewp645e1_0_arewp645e1(Arena_Obj_0_arewp645e1* dest_0);
extern void eQdestroy_1_Iscb4i31_arecyyj7v(seq_0_In6doa_arecyyj7v s_81);
extern void eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(ObjBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(ArrBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(SeqBox_Obj_0_valzr1t4f dest_0);
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82);
extern void eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(FlatRegion_Obj_0_valzr1t4f dest_0);
extern void eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f(Cell_Obj_0_valzr1t4f* dest_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_decqocs071(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_modzy18mg1(void);
extern void X60Qini_0_tagygirdh1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_tabcr240b1(void);
extern void X60Qini_0_envto7w6l1(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_aowqg5vb41(void);
extern void X60Qini_0_layptix6a1(void);
extern void X60Qini_0_heapjafyf1(void);
extern void X60Qini_0_marbdjk4t1(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_arewp645e1(void);
extern void X60Qini_0_arecyyj7v(void);
extern void X60Qini_0_flaksyopx1(void);
extern void X60Qini_0_natd5co251(void);
extern void X60Qini_0_runot4689(void);
extern void X60Qini_0_der823rwr1(void);
extern void X60Qini_0_croph25r5(void);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline NI32 memSizeInBytes_0_Ilxpm6v1_heapjafyf1(NI32 size_7);
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** rawData_0_I2xua2q_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_20);
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NI32 memSizeInBytes_0_I03jys01_aow7lb5cq1(NI32 size_21);
static inline WireField_0_run8hsnpi* rawData_0_Ijd497p_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_64);
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68);
extern NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8);
static inline NI32 capInBytes_0_Iri1hlt1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_69);
extern NB8 resize_0_I9lztdq1_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1* dest_9, NI32 addedElements_9);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_aow7lb5cq1;
static inline NI32 memSizeInBytes_0_Ivqzo5x1_arecyyj7v(NI32 size_29);
static inline NI32 memSizeInBytes_0_Ixcobep_arecyyj7v(NI32 size_25);
static inline NI32 capInBytes_0_Iev6wua1_arecyyj7v(seq_0_In6doa_arecyyj7v s_89);
extern NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_arecyyj7v* dest_8, NI32 addedElements_8);
static inline NI32 capInBytes_0_Iih34tr1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_87);
extern NB8 resize_0_If3pogj_flaksyopx1(seq_0_Iw8xl5b1_arecyyj7v* dest_4, NI32 addedElements_4);
extern void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_flaksyopx1(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0);
static inline NU8* rawData_0_Ihjhfzs_explnj22x1(seq_0_Incv1wn_arecyyj7v s_70);
extern X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0);
extern void eQwasmovedQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1** dest_0);
extern void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0);
extern X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* src_0);
static inline NI32 memSizeInBytes_0_Itmy7ww1_croph25r5(NI32 size_11);
static inline NI32 capInBytes_0_Ihvsegh1_croph25r5(seq_0_I50urnw_croph25r5 s_30);
extern NB8 resize_0_Iz8tg361_intzsnzax(seq_0_I50urnw_croph25r5* dest_23, NI32 addedElements_23);
extern void writeErr_2_sysvq0asl(string_0_sysvq0asl s_68);
extern LongString_0_sysvq0asl const strlit_0_I15539159382304113184_sysvq0asl;
static inline NI32 memSizeInBytes_0_Isdq9ys1_arecyyj7v(NI32 size_12);
static inline NI32 memSizeInBytes_0_Iovtwg11_arecyyj7v(NI32 size_13);
static inline NI32 memSizeInBytes_0_If6e4np_arecyyj7v(NI32 size_14);
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** rawData_0_Izez9p81_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_72);
static inline NU32 hash_2_has9tn57v(NU32 u_0);
static inline NI32 memSizeInBytes_0_Ilp7p16_der823rwr1(NI32 size_15);
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
extern NU32 const ErrT_0_nifh7u8pu1;
LongString_0_sysvq0asl const strlit_0_I16922689447350274615_run8hsnpi = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "holes"}
;
LongString_0_sysvq0asl const strlit_0_I233467988036736238_run8hsnpi = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "procty"}
;
LongString_0_sysvq0asl const strlit_0_I1952482970424587404_run8hsnpi = {
  .fullLen_0 = 46, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "the Phase-1 cabi stub provider handles no call"}
;
LongString_0_sysvq0asl const strlit_0_I5159512292478983011_run8hsnpi = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cabi-stub"}
;
LongString_0_sysvq0asl const strlit_0_I2753240950845275664_run8hsnpi = {
  .fullLen_0 = 28, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "no hybrid provider installed"}
;
LongString_0_sysvq0asl const strlit_0_I13886929192389480583_run8hsnpi = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "no provider holds this callee"}
;
LongString_0_sysvq0asl const strlit_0_I7414938221747216170_run8hsnpi = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "provider \'"}
;
LongString_0_sysvq0asl const strlit_0_I5892731654726801288_run8hsnpi = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' declined \'"}
;
LongString_0_sysvq0asl const strlit_0_I9873774322074382144_run8hsnpi = {
  .fullLen_0 = 25, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' without noting a reason"}
;
LongString_0_sysvq0asl const strlit_0_I12470586101363112036_run8hsnpi = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "AOWLI_JIT_TRACE"}
;
LongString_0_sysvq0asl const strlit_0_I1742168074744315372_run8hsnpi = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq["}
;
LongString_0_sysvq0asl const strlit_0_I2937163572003096168_run8hsnpi = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "variant"}
;
LongString_0_sysvq0asl const strlit_0_I13019318966386094724_run8hsnpi = {
  .fullLen_0 = 62, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "the type has no resolved description (typeDescOf returned nil)"}
;
LongString_0_sysvq0asl const strlit_0_I4958048190723036074_run8hsnpi = {
  .fullLen_0 = 75, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "`ptr T` whose POINTEE has no resolved description (typeDescOf returned nil)"}
;
LongString_0_sysvq0asl const strlit_0_I16235671060003324787_run8hsnpi = {
  .fullLen_0 = 53, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "`ptr T` whose pointee is an unresolved distinct chain"}
;
LongString_0_sysvq0asl const strlit_0_I13225935872158492040_run8hsnpi = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "`ptr T` whose pointee is a "}
;
LongString_0_sysvq0asl const strlit_0_I3673080887886368090_run8hsnpi = {
  .fullLen_0 = 91, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 the arena has no faithful place/sync pair for it, so a mutation could not be read back"}
;
LongString_0_sysvq0asl const strlit_0_I4342340915346939023_run8hsnpi = {
  .fullLen_0 = 59, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "`ptr T` whose pointee type has no name the shim could spell"}
;
LongString_0_sysvq0asl const strlit_0_I8993670282046711299_run8hsnpi = {
  .fullLen_0 = 53, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "`ptr T` whose pointee has zero or unknown native size"}
;
LongString_0_sysvq0asl const strlit_0_I8793898668013225318_run8hsnpi = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pointer/nilt"}
;
LongString_0_sysvq0asl const strlit_0_I4709633162961732303_run8hsnpi = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "opaque host pointer ("}
;
LongString_0_sysvq0asl const strlit_0_I2888973717457040847_run8hsnpi = {
  .fullLen_0 = 129, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "): no pointee type, so nothing can be laid out or reconstructed by a shim; admitting it would also pull I/O procs into the census"}
;
LongString_0_sysvq0asl const strlit_0_I13889320805933294264_run8hsnpi = {
  .fullLen_0 = 49, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "array with no element type or non-positive length"}
;
LongString_0_sysvq0asl const strlit_0_I16185026956335355254_run8hsnpi = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "array of a non-scalar, non-POD element"}
;
LongString_0_sysvq0asl const strlit_0_I10498682809148144310_run8hsnpi = {
  .fullLen_0 = 65, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "array whose POD element itself contains an enum or a nested array"}
;
LongString_0_sysvq0asl const strlit_0_I15756359906215420366_run8hsnpi = {
  .fullLen_0 = 51, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "array element type has no name the shim could spell"}
;
LongString_0_sysvq0asl const strlit_0_I12763724795707366899_run8hsnpi = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "array of POD with no element type symbol"}
;
LongString_0_sysvq0asl const strlit_0_I15672252006839982641_run8hsnpi = {
  .fullLen_0 = 43, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ref whose payload is not an object or tuple"}
;
LongString_0_sysvq0asl const strlit_0_I11886991017504759357_run8hsnpi = {
  .fullLen_0 = 62, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ref type not written as (ref SYM) \342\200\224 the shim cannot spell it"}
;
LongString_0_sysvq0asl const strlit_0_I10876541292033031825_run8hsnpi = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ref payload is not a named symbol"}
;
LongString_0_sysvq0asl const strlit_0_I5262176531977851534_run8hsnpi = {
  .fullLen_0 = 58, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ref payload has no name or symbol for the shim declaration"}
;
LongString_0_sysvq0asl const strlit_0_I10983318047828523597_run8hsnpi = {
  .fullLen_0 = 73, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arena-pointer aggregate with no named type \342\200\224 the shim cannot declare it"}
;
LongString_0_sysvq0asl const strlit_0_I14209940706925738676_run8hsnpi = {
  .fullLen_0 = 47, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arena-pointer aggregate of zero or unknown size"}
;
LongString_0_sysvq0asl const strlit_0_I10048895548644967963_run8hsnpi = {
  .fullLen_0 = 51, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "anonymous enum \342\200\224 the shim needs a named enum type"}
;
LongString_0_sysvq0asl const strlit_0_I11975016787032525042_run8hsnpi = {
  .fullLen_0 = 40, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "scalar with no spellable C/nim type name"}
;
LongString_0_sysvq0asl const strlit_0_I2580450898984919640_run8hsnpi = {
  .fullLen_0 = 50, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "POD aggregate containing an enum or a nested array"}
;
LongString_0_sysvq0asl const strlit_0_I4239904353946109281_run8hsnpi = {
  .fullLen_0 = 60, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "anonymous tuple with a leaf that has no nameable scalar type"}
;
LongString_0_sysvq0asl const strlit_0_I4762276063258106479_run8hsnpi = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq with no element type"}
;
LongString_0_sysvq0asl const strlit_0_I17656025713398431513_run8hsnpi = {
  .fullLen_0 = 56, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq whose POD element contains an enum or a nested array"}
;
LongString_0_sysvq0asl const strlit_0_I18020228616198309266_run8hsnpi = {
  .fullLen_0 = 49, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq element type has no name the shim could spell"}
;
LongString_0_sysvq0asl const strlit_0_I8778022564813250551_run8hsnpi = {
  .fullLen_0 = 38, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq of POD with no element type symbol"}
;
LongString_0_sysvq0asl const strlit_0_I2962236368520039866_run8hsnpi = {
  .fullLen_0 = 41, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq element type could not be described: "}
;
LongString_0_sysvq0asl const strlit_0_I14789285714436344509_run8hsnpi = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq of "}
;
LongString_0_sysvq0asl const strlit_0_I14207751904824393164_run8hsnpi = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " whose element type sym "}
;
LongString_0_sysvq0asl const strlit_0_I9036228806849239375_run8hsnpi = {
  .fullLen_0 = 67, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "is not recoverable - refused rather than crossing positional cells "}
;
LongString_0_sysvq0asl const strlit_0_I2343043800903051371_run8hsnpi = {
  .fullLen_0 = 34, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "whose `.field` would fail silently"}
;
LongString_0_sysvq0asl const strlit_0_I17842927025719761_run8hsnpi = {
  .fullLen_0 = 51, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq of aggregate whose element cannot cross by copy"}
;
LongString_0_sysvq0asl const strlit_0_I2511330594188339324_run8hsnpi = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " [elem "}
;
LongString_0_sysvq0asl const strlit_0_I95191463816654317_run8hsnpi = {
  .fullLen_0 = 60, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq of ref/closure/unsafe element \342\200\224 ownership cannot cross"}
;
LongString_0_sysvq0asl const strlit_0_I3480347692445760496_run8hsnpi = {
  .fullLen_0 = 51, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cannot cross: an anonymous object \342\200\224 the far side "}
;
LongString_0_sysvq0asl const strlit_0_I8515203893767693394_run8hsnpi = {
  .fullLen_0 = 67, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "could rebuild its fields positionally but not BY NAME, and a value "}
;
LongString_0_sysvq0asl const strlit_0_I4435949299172777945_run8hsnpi = {
  .fullLen_0 = 67, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "whose `.field` access silently fails is a wrong answer that prints "}
;
LongString_0_sysvq0asl const strlit_0_I9019415731558934837_run8hsnpi = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "like a right one"}
;
LongString_0_sysvq0asl const strlit_0_I15413645776922620897_run8hsnpi = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "<aggregate>"}
;
LongString_0_sysvq0asl const strlit_0_I16798826875811747463_run8hsnpi = {
  .fullLen_0 = 66, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 a value aggregate with a variable-length field (seq/string), "}
;
LongString_0_sysvq0asl const strlit_0_I5244465630440985265_run8hsnpi = {
  .fullLen_0 = 33, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "which has no flat byte form today"}
;
LongString_0_sysvq0asl const strlit_0_I14538563795054532983_run8hsnpi = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 a GC ref: ownership cannot cross"}
;
LongString_0_sysvq0asl const strlit_0_I7336782688302392152_run8hsnpi = {
  .fullLen_0 = 43, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 a closure: captured state cannot cross"}
;
LongString_0_sysvq0asl const strlit_0_I9738203171686931162_run8hsnpi = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 no byte form"}
;
LongString_0_sysvq0asl const strlit_0_I7830412320232756549_run8hsnpi = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cannot cross: "}
;
LongString_0_sysvq0asl const strlit_0_I15938467040282102084_run8hsnpi = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " is "}
;
LongString_0_sysvq0asl const strlit_0_I7431751303130250076_run8hsnpi = {
  .fullLen_0 = 237, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var/out `cstring`: the write-back slot would carry a raw FOREIGN address into the caller\'s live Cell as an integer. A cstring crosses in RETURN position only, where it is wrapped in an `rkForeign` region that knows what the address means"}
;
LongString_0_sysvq0asl const strlit_0_I275891954373591862_run8hsnpi = {
  .fullLen_0 = 305, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var/out `ptr T`: the write-back slot would carry a raw ARENA ADDRESS into the caller\'s live pointer Cell (the `skip(var Cursor)` corruption one level up). A `ptr T` INPUT crosses; a `ptr T` that comes back out needs `unmaterializePtr`, which needs an interpreter pointer to carry the pointee metadata from"}
;
LongString_0_sysvq0asl const strlit_0_I138105002306121085_run8hsnpi = {
  .fullLen_0 = 220, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var/out array whose ELEMENT cannot be rebuilt from wire bytes (enum, pointer or POD element): the inverse `scalarFromBits` answers nil for it, so the write-back would silently store 0 into the caller\'s live element Cells"}
;
LongString_0_sysvq0asl const strlit_0_I4823751142713875849_run8hsnpi = {
  .fullLen_0 = 72, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var/out array with no usable fixed wire geometry (count/elemSize/stride)"}
;
LongString_0_sysvq0asl const strlit_0_I11949153613191379336_run8hsnpi = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "a non-flat type"}
;
LongString_0_sysvq0asl const strlit_0_I12459124382821890348_run8hsnpi = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var/out of "}
;
LongString_0_sysvq0asl const strlit_0_I14049035126231656660_run8hsnpi = {
  .fullLen_0 = 91, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " \342\200\224 write-back is only safe for a fixed-size scalar, flat-POD or scalar-element array leaf"}
;
LongString_0_sysvq0asl const strlit_0_I4209738878907651049_run8hsnpi = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_shim_"}
;
LongString_0_sysvq0asl const strlit_0_I12060659291606161857_run8hsnpi = {
  .fullLen_0 = 211, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "`cstring` PARAM: an interpreted string\'s bytes live in a Cell, so there is no contiguous C address to hand to the shim. A cstring crosses in RETURN position only (the address comes FROM native, where it is real)"}
;
LongString_0_sysvq0asl const strlit_0_I9252022049267197370_run8hsnpi = {
  .fullLen_0 = 86, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ref return: a fresh vkRef would have to be synthesized caller-side (identity/lifetime)"}
;
LongString_0_sysvq0asl const strlit_0_I293621626120980652_run8hsnpi = {
  .fullLen_0 = 183, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "`ptr T` return: the address would have to be inverted with no `old` interpreter pointer to carry the pointee metadata from \342\200\224 INPUT-position `ptr T` crosses, return position does not"}
;
LongString_0_sysvq0asl const strlit_0_I12129503281566277309_run8hsnpi = {
  .fullLen_0 = 129, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "anonymous POD return: field names cannot be recovered without a type sym (a tuple return is exempt \342\200\224 its fields are positional)"}
;
LongString_0_sysvq0asl const strlit_0_I15683387437464179193_run8hsnpi = {
  .fullLen_0 = 166, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var/out arg combined with a var-length (string/seq) return: the write-back slots sit AFTER the fixed return value, and a growing return has no fixed size to sit after"}
;
LongString_0_sysvq0asl const strlit_0_I4449311905133063423_run8hsnpi = {
  .fullLen_0 = 31, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var-arena-ptr: no nameable type"}
;
LongString_0_sysvq0asl const strlit_0_I12911497544173404865_run8hsnpi = {
  .fullLen_0 = 34, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var-arena-ptr: not an object/tuple"}
;
LongString_0_sysvq0asl const strlit_0_I12139432315779883303_run8hsnpi = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var-arena-ptr: unmapped field"}
;
LongString_0_sysvq0asl const strlit_0_I3386527286220271425_run8hsnpi = {
  .fullLen_0 = 28, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "var-arena-ptr: non-flat leaf"}
;
LongString_0_sysvq0asl const strlit_0_I4311268661432640709_run8hsnpi = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " arg"}
;
LongString_0_sysvq0asl const strlit_0_I7498181021040919538_run8hsnpi = {
  .fullLen_0 = 32, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "TOUCHED (property of the callee)"}
;
LongString_0_sysvq0asl const strlit_0_I4863082586268738407_run8hsnpi = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "UNKNOWN "}
;
LongString_0_sysvq0asl const strlit_0_I5868316469075155783_run8hsnpi = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " (property of the ANALYSIS)"}
;
LongString_0_sysvq0asl const strlit_0_I18334688814084301714_run8hsnpi = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ref CabiGenProvider.Obj"}
;
LongString_0_sysvq0asl const strlit_0_I17755916622381260779_run8hsnpi = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit-try "}
;
LongString_0_sysvq0asl const strlit_0_I13879001563082667471_run8hsnpi = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit-no "}
;
LongString_0_sysvq0asl const strlit_0_I6867780705510740199_run8hsnpi = {
  .fullLen_0 = 32, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " : not in the dispatch table of "}
;
LongString_0_sysvq0asl const strlit_0_I6591882555819548044_run8hsnpi = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " entries\012"}
;
LongString_0_sysvq0asl const strlit_0_I8323340401993503906_run8hsnpi = {
  .fullLen_0 = 30, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "not in the shim dispatch table"}
;
LongString_0_sysvq0asl const strlit_0_I17183936099286931213_run8hsnpi = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arity mismatch: "}
;
LongString_0_sysvq0asl const strlit_0_I18255814566225474086_run8hsnpi = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " args vs "}
;
LongString_0_sysvq0asl const strlit_0_I2164128916027878689_run8hsnpi = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " on the wire"}
;
LongString_0_sysvq0asl const strlit_0_I601893499622124267_run8hsnpi = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aowli_set_host_forward"}
;
LongString_0_sysvq0asl const strlit_0_I11555090815403677726_run8hsnpi = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " : dlopen failed for "}
;
LongString_0_sysvq0asl const strlit_0_I8932411087278802551_run8hsnpi = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dlopen failed for "}
;
LongString_0_sysvq0asl const strlit_0_I15980317227653665914_run8hsnpi = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " : dlsym found no "}
;
LongString_0_sysvq0asl const strlit_0_I9471465608874713306_run8hsnpi = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dlsym found no shim symbol "}
;
LongString_0_sysvq0asl const strlit_0_I3278143169533289085_run8hsnpi = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ptr arg"}
;
LongString_0_sysvq0asl const strlit_0_I13592592763606903879_run8hsnpi = {
  .fullLen_0 = 77, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ": the pointee names no storage the arena can lay out (materializePtr refused)"}
;
LongString_0_sysvq0asl const strlit_0_I1069507577923700528_run8hsnpi = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arena-ptr arg"}
;
LongString_0_sysvq0asl const strlit_0_I8163890759512608411_run8hsnpi = {
  .fullLen_0 = 37, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ": pointee not layable in native bytes"}
;
LongString_0_sysvq0asl const strlit_0_I15611778738489493776_run8hsnpi = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hybrid: DECLINE "}
;
LongString_0_sysvq0asl const strlit_0_I15730584599751133452_run8hsnpi = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hybrid: pre-call "}
;
LongString_0_sysvq0asl const strlit_0_I2491960150546354308_run8hsnpi = {
  .fullLen_0 = 15, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "shim asked for "}
;
LongString_0_sysvq0asl const strlit_0_I2284540631411732658_run8hsnpi = {
  .fullLen_0 = 29, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " bytes twice (not idempotent)"}
;
LongString_0_sysvq0asl const strlit_0_I10032287891621565925_run8hsnpi = {
  .fullLen_0 = 14, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "write-back arg"}
;
LongString_0_sysvq0asl const strlit_0_I11519459256921757232_run8hsnpi = {
  .fullLen_0 = 62, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ": a pointer leaf came back naming no byte this pass handed out"}
;
LongString_0_sysvq0asl const strlit_0_I8945843855761550514_run8hsnpi = {
  .fullLen_0 = 26, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hybrid: WRITEBACK-DECLINE "}
;
LongString_0_sysvq0asl const strlit_0_I9993579587050855651_run8hsnpi = {
  .fullLen_0 = 70, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ": a var/out array element could not be rebuilt from the shim\'s bytes, "}
;
LongString_0_sysvq0asl const strlit_0_I16678242556164327223_run8hsnpi = {
  .fullLen_0 = 50, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "or the argument does not name the whole live array"}
;
LongString_0_sysvq0asl const strlit_0_I87927900075392640_run8hsnpi = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit-bytes "}
;
LongString_0_sysvq0asl const strlit_0_I12313134788378398246_run8hsnpi = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " calls="}
;
LongString_0_sysvq0asl const strlit_0_I9006312985088794180_run8hsnpi = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " out="}
;
LongString_0_sysvq0asl const strlit_0_I10836411368895577019_run8hsnpi = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " avg-in="}
;
LongString_0_sysvq0asl const strlit_0_I16930409917808841651_run8hsnpi = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "jit-cross "}
;
LongString_0_sysvq0asl const strlit_0_I9558933350530343618_run8hsnpi = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cabi-gen"}
;
NU32 const HybridProvider_Obj_0_dy_run8hsnpi[] = {
  1294232418u, 3892737894u}
;
Rtti_0_sysvq0asl const HybridProvider_Obj_0_vt_run8hsnpi = {
  .dl_0 = 2, .dy_0 = ((NU32*)HybridProvider_Obj_0_dy_run8hsnpi), .mt_0 = {
    ((void*)eQdestroyQ_SX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi), ((void*)eQdestroyQ_SX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi)}}
;
NU32 const CabiGenProvider_Obj_0_dy_run8hsnpi[] = {
  1294232418u, 3892737894u, 4174408912u}
;
Rtti_0_sysvq0asl const CabiGenProvider_Obj_0_vt_run8hsnpi = {
  .dl_0 = 3, .dy_0 = ((NU32*)CabiGenProvider_Obj_0_dy_run8hsnpi), .mt_0 = {
    ((void*)eQdestroyQ_SX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi), ((void*)eQdestroyQ_SX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi), ((void*)eQdestroyQ_SX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi), ((void*)eQtraceQ_SX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi), ((void*)eQtraceQ_SX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi)}}
;
X60Qt_0_IAcstringZApointerZAiS32ZAR9ZAiS32ZAcdeclZAfalseZAR41_run8hsnpi gHostForward_0_run8hsnpi = NIM_NIL;
static string_0_sysvq0asl const hexd_0 = {
  .bytes_0 = 842084606u, .more_0 = (&strlit_0_I6105018409752412263_dbg4n0xd21)}
;
NB8 X60QiniGuard_0_run8hsnpi;
string_0_sysvq0asl nodeTag_0_run8hsnpi(Cursor_0_nifb6mq6y1 n_0){
  string_0_sysvq0asl result_3;
  nimStrWasMoved((&result_3));
  nimStrDestroy(result_3);
  NU32 X60Qx_132 = tagId_0_nifb6mq6y1(n_0);
  string_0_sysvq0asl* X60Qx_133 = getQ_0_I93d71y_der823rwr1(pool_0_nifh7u8pu1.tags_0, X60Qx_132);
  string_0_sysvq0asl X60Qx_134 = nimStrDup((*X60Qx_133));
  result_3 = X60Qx_134;
  return result_3;}
NB8 pragmasHaveInheritable_0_run8hsnpi(Cursor_0_nifb6mq6y1 pragmasCur_0){
  NB8 result_4;
  Cursor_0_nifb6mq6y1 c_0 = eQdup_0_nifb6mq6y1(pragmasCur_0);
  NifKind_0_nif81dubp1 X60Qx_135 = kind_0_nifb6mq6y1(c_0);
  if ((!(X60Qx_135 == 11))){
    eQdestroy_0_nifb6mq6y1((&c_0));
    return NIM_FALSE;}
  inc_0_nifb6mq6y1((&c_0));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_136 = kind_0_nifb6mq6y1(c_0);
      if ((!(X60Qx_136 == 12))){
        NB8 X60Qx_137;
        NifKind_0_nif81dubp1 X60Qx_138 = kind_0_nifb6mq6y1(c_0);
        if (X60Qx_138 == 11){
          NU32 X60Qx_139 = tag_0_nifb6mq6y1(c_0);
          X60Qx_137 = (((TagEnum_0_tagygirdh1)X60Qx_139) == 313);}
        else {
          X60Qx_137 = NIM_FALSE;}
        if (X60Qx_137){
          eQdestroy_0_nifb6mq6y1((&c_0));
          return NIM_TRUE;}
        skip_0_nifb6mq6y1((&c_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_4 = NIM_FALSE;
  eQdestroy_0_nifb6mq6y1((&c_0));
  return result_4;
  eQdestroy_0_nifb6mq6y1((&c_0));
  return result_4;}
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* typeDescOf_0_run8hsnpi(Cursor_0_nifb6mq6y1 t_0, NI32 depth_0){
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* result_5;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&result_5));
  if (32 < depth_0){
    return NIM_NIL;}
  Cursor_0_nifb6mq6y1 c_1 = eQdup_0_nifb6mq6y1(t_0);
  NifKind_0_nif81dubp1 X60Qx_140 = kind_0_nifb6mq6y1(c_1);
  if (X60Qx_140 == 4){
    NU32 sym_12 = symId_0_nifb6mq6y1(c_1);
    if (((NU32)sym_12) == ((NU32)0u)){
      eQdestroy_0_nifb6mq6y1((&c_1));
      return NIM_NIL;}
    string_0_sysvq0asl* X60Qx_141 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_12);
    string_0_sysvq0asl bn_0 = nimStrDup((*X60Qx_141));
    extractBasename_1_symkyk35i1((&bn_0));
    NB8 X60Qx_142 = eqQ_20_sysvq0asl(bn_0, (string_0_sysvq0asl){
      .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
    );
    if (X60Qx_142){
      void* X60Qx_143 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_143);
      seq_0_I3ump14_aow7lb5cq1 X60Qx_144 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
      seq_0_Ie088gc_heapjafyf1 X60Qx_145 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
      (*X60Qtmp_0) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
        .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
          .kind_0 = 14, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_144, .branches_0 = X60Qx_145}}
      ;
      result_5 = X60Qtmp_0;
      nimStrDestroy(bn_0);
      eQdestroy_0_nifb6mq6y1((&c_1));
      return result_5;}
    LoadResult_0_prorcx25w1 res_7 = tryLoadSymSafe_0_modzy18mg1(sym_12);
    NB8 X60Qx_91;
    NB8 X60Qx_146;
    if ((!(res_7.status_0 == 3))){
      X60Qx_146 = NIM_TRUE;}
    else {
      NifKind_0_nif81dubp1 X60Qx_147 = kind_0_nifb6mq6y1(res_7.decl_0);
      X60Qx_146 = (!(X60Qx_147 == 11));}
    if (X60Qx_146){
      X60Qx_91 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_1 = nodeTag_0_run8hsnpi(res_7.decl_0);
      NB8 X60Qx_148 = eqQ_20_sysvq0asl(X60Qtmp_1, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
      );
      X60Qx_91 = (!X60Qx_148);
      nimStrDestroy(X60Qtmp_1);}
    if (X60Qx_91){
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
      nimStrDestroy(bn_0);
      eQdestroy_0_nifb6mq6y1((&c_1));
      return NIM_NIL;}
    TypeDecl_0_decqocs071 td_11 = asTypeDecl_0_decqocs071(res_7.decl_0);
    NB8 X60Qx_149 = eqQ_20_sysvq0asl(bn_0, (string_0_sysvq0asl){
      .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
    );
    if (X60Qx_149){
      Cursor_0_nifb6mq6y1 b_0 = td_11.typevars_0;
      eQwasMoved_0_nifb6mq6y1((&td_11.typevars_0));
      NB8 X60Qx_92;
      NifKind_0_nif81dubp1 X60Qx_150 = kind_0_nifb6mq6y1(b_0);
      if (X60Qx_150 == 11){
        string_0_sysvq0asl X60Qtmp_2 = nodeTag_0_run8hsnpi(b_0);
        NB8 X60Qx_151 = eqQ_20_sysvq0asl(X60Qtmp_2, (string_0_sysvq0asl){
          .bytes_0 = 7627010u, .more_0 = NIM_NIL}
        );
        X60Qx_92 = X60Qx_151;
        nimStrDestroy(X60Qtmp_2);}
      else {
        X60Qx_92 = NIM_FALSE;}
      if (X60Qx_92){
        inc_0_nifb6mq6y1((&b_0));
        skip_0_nifb6mq6y1((&b_0));
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_2 = typeDescOf_0_run8hsnpi(b_0, ((NI32)(depth_0 + 1)));
        if (elem_2 == NIM_NIL){
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_2);
          eQdestroy_0_nifb6mq6y1((&b_0));
          eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
          nimStrDestroy(bn_0);
          eQdestroy_0_nifb6mq6y1((&c_1));
          return NIM_NIL;}
        void* X60Qx_152 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_3 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_152);
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_4 = elem_2;
        eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&elem_2));
        seq_0_I3ump14_aow7lb5cq1 X60Qx_93 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
        seq_0_Ie088gc_heapjafyf1 X60Qx_94 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
        (*X60Qtmp_3) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
          .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
            .kind_0 = 15, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_4, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_93, .branches_0 = X60Qx_94}}
        ;
        result_5 = X60Qtmp_3;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_2);
        eQdestroy_0_nifb6mq6y1((&b_0));
        eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
        nimStrDestroy(bn_0);
        eQdestroy_0_nifb6mq6y1((&c_1));
        return result_5;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_2);}
      eQdestroy_0_nifb6mq6y1((&b_0));
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
      nimStrDestroy(bn_0);
      eQdestroy_0_nifb6mq6y1((&c_1));
      return NIM_NIL;
      eQdestroy_0_nifb6mq6y1((&b_0));}
    NB8 X60Qx_95;
    NB8 X60Qx_96;
    NifKind_0_nif81dubp1 X60Qx_153 = kind_0_nifb6mq6y1(td_11.body_0);
    if (X60Qx_153 == 11){
      string_0_sysvq0asl X60Qtmp_5 = nodeTag_0_run8hsnpi(td_11.body_0);
      NB8 X60Qx_154 = eqQ_20_sysvq0asl(X60Qtmp_5, (string_0_sysvq0asl){
        .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
      );
      X60Qx_96 = X60Qx_154;
      nimStrDestroy(X60Qtmp_5);}
    else {
      X60Qx_96 = NIM_FALSE;}
    if (X60Qx_96){
      NB8 X60Qx_155 = pragmasHaveInheritable_0_run8hsnpi(td_11.pragmas_0);
      X60Qx_95 = X60Qx_155;}
    else {
      X60Qx_95 = NIM_FALSE;}
    if (X60Qx_95){
      void* X60Qx_156 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_6 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_156);
      seq_0_I3ump14_aow7lb5cq1 X60Qx_157 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
      seq_0_Ie088gc_heapjafyf1 X60Qx_158 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
      (*X60Qtmp_6) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
        .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
          .kind_0 = 12, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_157, .branches_0 = X60Qx_158}}
      ;
      result_5 = X60Qtmp_6;
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
      nimStrDestroy(bn_0);
      eQdestroy_0_nifb6mq6y1((&c_1));
      return result_5;}
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_159 = typeDescOf_0_run8hsnpi(td_11.body_0, ((NI32)(depth_0 + 1)));
    result_5 = X60Qx_159;
    eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
    nimStrDestroy(bn_0);
    eQdestroy_0_nifb6mq6y1((&c_1));
    return result_5;
    eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
    nimStrDestroy(bn_0);}
  NifKind_0_nif81dubp1 X60Qx_160 = kind_0_nifb6mq6y1(c_1);
  if ((!(X60Qx_160 == 11))){
    eQdestroy_0_nifb6mq6y1((&c_1));
    return NIM_NIL;}
  string_0_sysvq0asl X60Qtmp_7 = nodeTag_0_run8hsnpi(c_1);
  NB8 X60Qtc_16 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 1, (NC8)'o');
  if (X60Qtc_16){
    NB8 X60Qtc_17 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'n');
    if (X60Qtc_17){
      NB8 X60Qtc_18 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'e');
      if (X60Qtc_18){
        NB8 X60Qtc_19 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'b');
        if (X60Qtc_19){
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
          )){
            goto X60Qsc_4;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
          )){
            goto X60Qsc_5;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_fiepkwzpc)}
          )){
            goto X60Qsc_12;}}}
      else {
        NB8 X60Qtc_20 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'h');
        if (X60Qtc_20){
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1819240702u, .more_0 = (&strlit_0_I16922689447350274615_run8hsnpi)}
          )){
            goto X60Qsc_5;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1818849022u, .more_0 = (&strlit_0_I14845240230376595005_buiyylk1h1)}
          )){
            goto X60Qsc_6;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1852140798u, .more_0 = (&strlit_0_I6008424852838151324_nimry5ra91)}
          )){
            goto X60Qsc_11;}}}}
    else {
      NB8 X60Qtc_21 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'p');
      if (X60Qtc_21){
        NB8 X60Qtc_22 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'o');
        if (X60Qtc_22){
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_fiepkwzpc)}
          )){
            goto X60Qsc_5;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
          )){
            goto X60Qsc_15;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I6300154543333844069_intzsnzax)}
          )){
            goto X60Qsc_6;}}}
      else {
        NB8 X60Qtc_23 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'r');
        if (X60Qtc_23){
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_7;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1970238206u, .more_0 = (&strlit_0_I18029839360381635789_intzsnzax)}
          )){
            goto X60Qsc_8;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_10;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I5595596763809202512_nim30udrv)}
          )){
            goto X60Qsc_11;}}}}}
  else {
    NB8 X60Qtc_24 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'m');
    if (X60Qtc_24){
      NB8 X60Qtc_25 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'c');
      if (X60Qtc_25){
        NB8 X60Qtc_26 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'a');
        if (X60Qtc_26){
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
          )){
            goto X60Qsc_13;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 25345u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_3;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
          )){
            goto X60Qsc_6;}}}
      else {
        NB8 X60Qtc_27 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'i');
        if (X60Qtc_27){
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 26881u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_0;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 26113u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_2;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1953852675u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_11;}}}}
    else {
      NB8 X60Qtc_28 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'p');
      if (X60Qtc_28){
        NB8 X60Qtc_29 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 1, (NC8)'r');
        if (X60Qtc_29){
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I5316556160589403975_emi78vuj01)}
          )){
            goto X60Qsc_8;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I233467988036736238_run8hsnpi)}
          )){
            goto X60Qsc_8;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_6;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1953853187u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_11;}}}
      else {
        NB8 X60Qtc_30 = nimStrAtLe_0_sysvq0asl(X60Qtmp_7, 0, (NC8)'s');
        if (X60Qtc_30){
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
          )){
            goto X60Qsc_9;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 29953u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_1;}
          else if (equalStrings_0_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
            .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
          )){
            goto X60Qsc_14;}}}}}
  goto X60Qsc_32;
  X60Qsc_0: ;
  Cursor_0_nifb6mq6y1 w_0 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&w_0));
  NI32 X60Qx_0;
  NifKind_0_nif81dubp1 X60Qx_161 = kind_0_nifb6mq6y1(w_0);
  if (X60Qx_161 == 8){
    NU32 X60Qx_162 = intId_0_nifb6mq6y1(w_0);
    NI64* X60Qx_163 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_162);
    X60Qx_0 = ((NI32)(*X60Qx_163));}
  else {
    X60Qx_0 = 0;}
  NI32 bits_0 = X60Qx_0;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_164 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_8 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_164);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_165 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_166 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_8) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 0, .bits_0 = bits_0, .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_165, .branches_0 = X60Qx_166}}
  ;
  result_5 = X60Qtmp_8;
  eQdestroy_0_nifb6mq6y1((&w_0));
  goto X60Qsc_31;
  X60Qsc_1: ;
  Cursor_0_nifb6mq6y1 w_1 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&w_1));
  NI32 X60Qx_1;
  NifKind_0_nif81dubp1 X60Qx_167 = kind_0_nifb6mq6y1(w_1);
  if (X60Qx_167 == 8){
    NU32 X60Qx_168 = intId_0_nifb6mq6y1(w_1);
    NI64* X60Qx_169 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_168);
    X60Qx_1 = ((NI32)(*X60Qx_169));}
  else {
    X60Qx_1 = 0;}
  NI32 bits_1 = X60Qx_1;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_170 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_9 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_170);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_171 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_172 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_9) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 1, .bits_0 = bits_1, .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_171, .branches_0 = X60Qx_172}}
  ;
  result_5 = X60Qtmp_9;
  eQdestroy_0_nifb6mq6y1((&w_1));
  goto X60Qsc_31;
  X60Qsc_2: ;
  Cursor_0_nifb6mq6y1 w_2 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&w_2));
  NI32 X60Qx_2;
  NifKind_0_nif81dubp1 X60Qx_173 = kind_0_nifb6mq6y1(w_2);
  if (X60Qx_173 == 8){
    NU32 X60Qx_174 = intId_0_nifb6mq6y1(w_2);
    NI64* X60Qx_175 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_174);
    X60Qx_2 = ((NI32)(*X60Qx_175));}
  else {
    X60Qx_2 = 64;}
  NI32 bits_2 = X60Qx_2;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_176 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_10 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_176);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_177 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_178 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_10) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 2, .bits_0 = bits_2, .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_177, .branches_0 = X60Qx_178}}
  ;
  result_5 = X60Qtmp_10;
  eQdestroy_0_nifb6mq6y1((&w_2));
  goto X60Qsc_31;
  X60Qsc_3: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_179 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_11 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_179);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_180 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_181 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_11) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 3, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_180, .branches_0 = X60Qx_181}}
  ;
  result_5 = X60Qtmp_11;
  goto X60Qsc_31;
  X60Qsc_4: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_182 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_12 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_182);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_183 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_184 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_12) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 4, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_183, .branches_0 = X60Qx_184}}
  ;
  result_5 = X60Qtmp_12;
  goto X60Qsc_31;
  X60Qsc_5: ;
  NI32 lo_0 = 0;
  NI32 hi_0 = 0;
  NB8 seen_0 = NIM_FALSE;
  NI32 ebits_0 = 0;
  Cursor_0_nifb6mq6y1 e_5 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&e_5));
  NB8 X60Qx_97;
  NifKind_0_nif81dubp1 X60Qx_185 = kind_0_nifb6mq6y1(e_5);
  if (X60Qx_185 == 11){
    NB8 X60Qx_98;
    string_0_sysvq0asl X60Qtmp_13 = nodeTag_0_run8hsnpi(e_5);
    NB8 X60Qx_186 = eqQ_20_sysvq0asl(X60Qtmp_13, (string_0_sysvq0asl){
      .bytes_0 = 29953u, .more_0 = NIM_NIL}
    );
    if (X60Qx_186){
      X60Qx_98 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_14 = nodeTag_0_run8hsnpi(e_5);
      NB8 X60Qx_187 = eqQ_20_sysvq0asl(X60Qtmp_14, (string_0_sysvq0asl){
        .bytes_0 = 26881u, .more_0 = NIM_NIL}
      );
      X60Qx_98 = X60Qx_187;
      nimStrDestroy(X60Qtmp_14);}
    X60Qx_97 = X60Qx_98;
    nimStrDestroy(X60Qtmp_13);}
  else {
    X60Qx_97 = NIM_FALSE;}
  if (X60Qx_97){
    Cursor_0_nifb6mq6y1 w_3 = eQdup_0_nifb6mq6y1(e_5);
    inc_0_nifb6mq6y1((&w_3));
    NifKind_0_nif81dubp1 X60Qx_188 = kind_0_nifb6mq6y1(w_3);
    if (X60Qx_188 == 8){
      NU32 X60Qx_189 = intId_0_nifb6mq6y1(w_3);
      NI64* X60Qx_190 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_189);
      ebits_0 = ((NI32)(*X60Qx_190));}
    eQdestroy_0_nifb6mq6y1((&w_3));}
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_191 = kind_0_nifb6mq6y1(e_5);
      if ((!(X60Qx_191 == 12))){
        NB8 X60Qx_99;
        NifKind_0_nif81dubp1 X60Qx_192 = kind_0_nifb6mq6y1(e_5);
        if (X60Qx_192 == 11){
          string_0_sysvq0asl X60Qtmp_15 = nodeTag_0_run8hsnpi(e_5);
          NB8 X60Qx_193 = eqQ_20_sysvq0asl(X60Qtmp_15, (string_0_sysvq0asl){
            .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_emi78vuj01)}
          );
          X60Qx_99 = X60Qx_193;
          nimStrDestroy(X60Qtmp_15);}
        else {
          X60Qx_99 = NIM_FALSE;}
        if (X60Qx_99){
          Cursor_0_nifb6mq6y1 f_5 = eQdup_0_nifb6mq6y1(e_5);
          inc_0_nifb6mq6y1((&f_5));
          skip_0_nifb6mq6y1((&f_5));
          skip_0_nifb6mq6y1((&f_5));
          skip_0_nifb6mq6y1((&f_5));
          skip_0_nifb6mq6y1((&f_5));
          NifKind_0_nif81dubp1 X60Qx_194 = kind_0_nifb6mq6y1(f_5);
          if (X60Qx_194 == 11){
            Cursor_0_nifb6mq6y1 t_7 = f_5;
            eQwasMoved_0_nifb6mq6y1((&f_5));
            inc_0_nifb6mq6y1((&t_7));
            NifKind_0_nif81dubp1 X60Qx_195 = kind_0_nifb6mq6y1(t_7);
            if (X60Qx_195 == 8){
              NU32 X60Qx_196 = intId_0_nifb6mq6y1(t_7);
              NI64* X60Qx_197 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_196);
              NI32 o_0 = ((NI32)(*X60Qx_197));
              if ((!seen_0)){
                lo_0 = o_0;
                hi_0 = o_0;
                seen_0 = NIM_TRUE;}
              else {
                if (o_0 < lo_0){
                  lo_0 = o_0;}
                else {
                  if (hi_0 < o_0){
                    hi_0 = o_0;}}}}
            eQdestroy_0_nifb6mq6y1((&t_7));}
          eQdestroy_0_nifb6mq6y1((&f_5));}
        skip_0_nifb6mq6y1((&e_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_198 = enumDesc_0_layptix6a1(lo_0, hi_0, ebits_0);
  result_5 = X60Qx_198;
  eQdestroy_0_nifb6mq6y1((&e_5));
  goto X60Qsc_31;
  X60Qsc_6: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_199 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_16 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_199);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_200 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_201 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_16) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 5, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_200, .branches_0 = X60Qx_201}}
  ;
  result_5 = X60Qtmp_16;
  goto X60Qsc_31;
  X60Qsc_7: ;
  Cursor_0_nifb6mq6y1 e_6 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&e_6));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_1 = typeDescOf_0_run8hsnpi(e_6, ((NI32)(depth_0 + 1)));
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_202 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_17 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_202);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_18 = el_1;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&el_1));
  seq_0_I3ump14_aow7lb5cq1 X60Qx_100 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_101 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_17) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 6, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_18, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_100, .branches_0 = X60Qx_101}}
  ;
  result_5 = X60Qtmp_17;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_1);
  eQdestroy_0_nifb6mq6y1((&e_6));
  goto X60Qsc_31;
  X60Qsc_8: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_203 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_19 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_203);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_204 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_205 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_19) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 7, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_204, .branches_0 = X60Qx_205}}
  ;
  result_5 = X60Qtmp_19;
  goto X60Qsc_31;
  X60Qsc_9: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_206 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_20 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_206);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_207 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_208 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_20) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 14, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_207, .branches_0 = X60Qx_208}}
  ;
  result_5 = X60Qtmp_20;
  goto X60Qsc_31;
  X60Qsc_10: ;
  Cursor_0_nifb6mq6y1 e_7 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&e_7));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_3 = typeDescOf_0_run8hsnpi(e_7, ((NI32)(depth_0 + 1)));
  if (elem_3 == NIM_NIL){
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_3);
    eQdestroy_0_nifb6mq6y1((&e_7));
    nimStrDestroy(X60Qtmp_7);
    eQdestroy_0_nifb6mq6y1((&c_1));
    return NIM_NIL;}
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_209 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_21 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_209);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_22 = elem_3;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&elem_3));
  seq_0_I3ump14_aow7lb5cq1 X60Qx_102 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_103 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_21) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 15, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_22, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_102, .branches_0 = X60Qx_103}}
  ;
  result_5 = X60Qtmp_21;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_3);
  eQdestroy_0_nifb6mq6y1((&e_7));
  goto X60Qsc_31;
  X60Qsc_11: ;
  Cursor_0_nifb6mq6y1 e_8 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&e_8));
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_210 = typeDescOf_0_run8hsnpi(e_8, ((NI32)(depth_0 + 1)));
  result_5 = X60Qx_210;
  eQdestroy_0_nifb6mq6y1((&e_8));
  goto X60Qsc_31;
  X60Qsc_12: ;
  Cursor_0_nifb6mq6y1 e_9 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&e_9));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* inner_0 = typeDescOf_0_run8hsnpi(e_9, ((NI32)(depth_0 + 1)));
  if (inner_0 == NIM_NIL){
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(inner_0);
    eQdestroy_0_nifb6mq6y1((&e_9));
    nimStrDestroy(X60Qtmp_7);
    eQdestroy_0_nifb6mq6y1((&c_1));
    return NIM_NIL;}
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_211 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_23 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_211);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_24 = inner_0;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&inner_0));
  seq_0_I3ump14_aow7lb5cq1 X60Qx_104 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_105 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_23) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 13, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_24, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_104, .branches_0 = X60Qx_105}}
  ;
  result_5 = X60Qtmp_23;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(inner_0);
  eQdestroy_0_nifb6mq6y1((&e_9));
  goto X60Qsc_31;
  X60Qsc_13: ;
  Cursor_0_nifb6mq6y1 e_10 = eQdup_0_nifb6mq6y1(c_1);
  inc_0_nifb6mq6y1((&e_10));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_4 = typeDescOf_0_run8hsnpi(e_10, ((NI32)(depth_0 + 1)));
  if (elem_4 == NIM_NIL){
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_4);
    eQdestroy_0_nifb6mq6y1((&e_10));
    nimStrDestroy(X60Qtmp_7);
    eQdestroy_0_nifb6mq6y1((&c_1));
    return NIM_NIL;}
  Cursor_0_nifb6mq6y1 idx_0 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&idx_0));
  skip_0_nifb6mq6y1((&idx_0));
  NI32 lo_1 = 0;
  NI32 hi_1 = -1;
  NB8 X60Qx_106;
  NifKind_0_nif81dubp1 X60Qx_212 = kind_0_nifb6mq6y1(idx_0);
  if (X60Qx_212 == 11){
    string_0_sysvq0asl X60Qtmp_25 = nodeTag_0_run8hsnpi(idx_0);
    NB8 X60Qx_213 = eqQ_20_sysvq0asl(X60Qtmp_25, (string_0_sysvq0asl){
      .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16393544569146403439_intzsnzax)}
    );
    X60Qx_106 = X60Qx_213;
    nimStrDestroy(X60Qtmp_25);}
  else {
    X60Qx_106 = NIM_FALSE;}
  if (X60Qx_106){
    Cursor_0_nifb6mq6y1 r_0 = idx_0;
    eQwasMoved_0_nifb6mq6y1((&idx_0));
    inc_0_nifb6mq6y1((&r_0));
    skip_0_nifb6mq6y1((&r_0));
    NifKind_0_nif81dubp1 X60Qx_214 = kind_0_nifb6mq6y1(r_0);
    if (X60Qx_214 == 8){
      NU32 X60Qx_215 = intId_0_nifb6mq6y1(r_0);
      NI64* X60Qx_216 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_215);
      lo_1 = ((NI32)(*X60Qx_216));}
    skip_0_nifb6mq6y1((&r_0));
    NifKind_0_nif81dubp1 X60Qx_217 = kind_0_nifb6mq6y1(r_0);
    if (X60Qx_217 == 8){
      NU32 X60Qx_218 = intId_0_nifb6mq6y1(r_0);
      NI64* X60Qx_219 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_218);
      hi_1 = ((NI32)(*X60Qx_219));}
    eQdestroy_0_nifb6mq6y1((&r_0));}
  NI32 count_0 = ((NI32)(((NI32)(hi_1 - lo_1)) + 1));
  if (count_0 <= 0){
    eQdestroy_0_nifb6mq6y1((&idx_0));
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_4);
    eQdestroy_0_nifb6mq6y1((&e_10));
    nimStrDestroy(X60Qtmp_7);
    eQdestroy_0_nifb6mq6y1((&c_1));
    return NIM_NIL;}
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_220 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_26 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_220);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_27 = elem_4;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&elem_4));
  seq_0_I3ump14_aow7lb5cq1 X60Qx_107 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_108 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_26) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 9, .bits_0 = ((NI32)0), .count_0 = count_0, .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_27, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_107, .branches_0 = X60Qx_108}}
  ;
  result_5 = X60Qtmp_26;
  eQdestroy_0_nifb6mq6y1((&idx_0));
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_4);
  eQdestroy_0_nifb6mq6y1((&e_10));
  goto X60Qsc_31;
  X60Qsc_14: ;
  seq_0_I3ump14_aow7lb5cq1 fields_0 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  Cursor_0_nifb6mq6y1 f_6 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&f_6));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_221 = kind_0_nifb6mq6y1(f_6);
      if ((!(X60Qx_221 == 12))){
        NifKind_0_nif81dubp1 X60Qx_222 = kind_0_nifb6mq6y1(f_6);
        if (X60Qx_222 == 11){
          Cursor_0_nifb6mq6y1 fc_0 = eQdup_0_nifb6mq6y1(f_6);
          string_0_sysvq0asl X60Qtmp_28 = nodeTag_0_run8hsnpi(f_6);
          NB8 X60Qx_223 = eqQ_20_sysvq0asl(X60Qtmp_28, (string_0_sysvq0asl){
            .bytes_0 = 7760642u, .more_0 = NIM_NIL}
          );
          if (X60Qx_223){
            inc_0_nifb6mq6y1((&fc_0));
            skip_0_nifb6mq6y1((&fc_0));}
          X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* fd_0 = typeDescOf_0_run8hsnpi(fc_0, ((NI32)(depth_0 + 1)));
          if (fd_0 == NIM_NIL){
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_0);
            nimStrDestroy(X60Qtmp_28);
            eQdestroy_0_nifb6mq6y1((&fc_0));
            eQdestroy_0_nifb6mq6y1((&f_6));
            eQdestroy_1_Iqg9snl1_aow7lb5cq1(fields_0);
            nimStrDestroy(X60Qtmp_7);
            eQdestroy_0_nifb6mq6y1((&c_1));
            return NIM_NIL;}
          X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_29 = fd_0;
          eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&fd_0));
          add_0_Ijteip9_run8hsnpi((&fields_0), X60Qtmp_29);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_0);
          nimStrDestroy(X60Qtmp_28);
          eQdestroy_0_nifb6mq6y1((&fc_0));}
        skip_0_nifb6mq6y1((&f_6));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_224 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_30 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_224);
  seq_0_I3ump14_aow7lb5cq1 X60Qtmp_31 = fields_0;
  eQwasMoved_1_Iba95rl_aow7lb5cq1((&fields_0));
  seq_0_Ie088gc_heapjafyf1 X60Qx_109 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_30) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 11, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qtmp_31, .branches_0 = X60Qx_109}}
  ;
  result_5 = X60Qtmp_30;
  eQdestroy_0_nifb6mq6y1((&f_6));
  eQdestroy_1_Iqg9snl1_aow7lb5cq1(fields_0);
  goto X60Qsc_31;
  X60Qsc_15: ;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* base_7 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL));
  seq_0_I3ump14_aow7lb5cq1 fields_1 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  Cursor_0_nifb6mq6y1 oc_0 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&oc_0));
  NifKind_0_nif81dubp1 X60Qx_225 = kind_0_nifb6mq6y1(oc_0);
  if (X60Qx_225 == 4){
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(base_7);
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_226 = typeDescOf_0_run8hsnpi(oc_0, ((NI32)(depth_0 + 1)));
    base_7 = X60Qx_226;
    if (base_7 == NIM_NIL){
      eQdestroy_0_nifb6mq6y1((&oc_0));
      eQdestroy_1_Iqg9snl1_aow7lb5cq1(fields_1);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(base_7);
      nimStrDestroy(X60Qtmp_7);
      eQdestroy_0_nifb6mq6y1((&c_1));
      return NIM_NIL;}}
  skip_0_nifb6mq6y1((&oc_0));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_227 = kind_0_nifb6mq6y1(oc_0);
      if ((!(X60Qx_227 == 12))){
        NifKind_0_nif81dubp1 X60Qx_228 = kind_0_nifb6mq6y1(oc_0);
        if (X60Qx_228 == 11){
          string_0_sysvq0asl tg_0 = nodeTag_0_run8hsnpi(oc_0);
          NB8 X60Qx_229 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
            .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
          );
          if (X60Qx_229){
            Cursor_0_nifb6mq6y1 fc_1 = eQdup_0_nifb6mq6y1(oc_0);
            inc_0_nifb6mq6y1((&fc_1));
            skip_0_nifb6mq6y1((&fc_1));
            skip_0_nifb6mq6y1((&fc_1));
            skip_0_nifb6mq6y1((&fc_1));
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* fd_1 = typeDescOf_0_run8hsnpi(fc_1, ((NI32)(depth_0 + 1)));
            if (fd_1 == NIM_NIL){
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_1);
              eQdestroy_0_nifb6mq6y1((&fc_1));
              nimStrDestroy(tg_0);
              eQdestroy_0_nifb6mq6y1((&oc_0));
              eQdestroy_1_Iqg9snl1_aow7lb5cq1(fields_1);
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(base_7);
              nimStrDestroy(X60Qtmp_7);
              eQdestroy_0_nifb6mq6y1((&c_1));
              return NIM_NIL;}
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_32 = fd_1;
            eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&fd_1));
            add_0_Ijteip9_run8hsnpi((&fields_1), X60Qtmp_32);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_1);
            eQdestroy_0_nifb6mq6y1((&fc_1));}
          else {
            NB8 X60Qx_230 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
              .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_emi78vuj01)}
            );
            if (X60Qx_230){
              void* X60Qx_231 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
              X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_33 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_231);
              seq_0_I3ump14_aow7lb5cq1 X60Qx_232 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
              seq_0_Ie088gc_heapjafyf1 X60Qx_233 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
              (*X60Qtmp_33) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
                .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
                  .kind_0 = 12, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_232, .branches_0 = X60Qx_233}}
              ;
              result_5 = X60Qtmp_33;
              nimStrDestroy(tg_0);
              eQdestroy_0_nifb6mq6y1((&oc_0));
              eQdestroy_1_Iqg9snl1_aow7lb5cq1(fields_1);
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(base_7);
              nimStrDestroy(X60Qtmp_7);
              eQdestroy_0_nifb6mq6y1((&c_1));
              return result_5;}}
          nimStrDestroy(tg_0);}
        skip_0_nifb6mq6y1((&oc_0));}
      else {
        break;}}}
  whileStmtLabel_2: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_234 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_34 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_234);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_35 = base_7;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&base_7));
  seq_0_I3ump14_aow7lb5cq1 X60Qtmp_36 = fields_1;
  eQwasMoved_1_Iba95rl_aow7lb5cq1((&fields_1));
  seq_0_Ie088gc_heapjafyf1 X60Qx_110 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_34) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 10, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = X60Qtmp_35, .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qtmp_36, .branches_0 = X60Qx_110}}
  ;
  result_5 = X60Qtmp_34;
  eQdestroy_0_nifb6mq6y1((&oc_0));
  eQdestroy_1_Iqg9snl1_aow7lb5cq1(fields_1);
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(base_7);
  goto X60Qsc_31;
  X60Qsc_32: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_235 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL));
  result_5 = X60Qx_235;
  X60Qsc_31: ;
  nimStrDestroy(X60Qtmp_7);
  eQdestroy_0_nifb6mq6y1((&c_1));
  return result_5;
  nimStrDestroy(X60Qtmp_7);
  eQdestroy_0_nifb6mq6y1((&c_1));
  return result_5;}
static inline NB8 marshalSafe_0_run8hsnpi(MarshalClass_0_marbdjk4t1 cls_0){
  NB8 result_6;
  NB8 X60Qx_236;
  NB8 X60Qx_237;
  NB8 X60Qx_238;
  if (cls_0 == 0){
    X60Qx_238 = NIM_TRUE;}
  else {
    X60Qx_238 = (cls_0 == 1);}
  if (X60Qx_238){
    X60Qx_237 = NIM_TRUE;}
  else {
    X60Qx_237 = (cls_0 == 2);}
  if (X60Qx_237){
    X60Qx_236 = NIM_TRUE;}
  else {
    X60Qx_236 = (cls_0 == 3);}
  result_6 = X60Qx_236;
  return result_6;}
NB8 hybridDecision_0_run8hsnpi(seq_0_I3ump14_aow7lb5cq1 params_0, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* ret_0){
  NB8 result_7;
  {
    openArray_0_I3ca6t4_layptix6a1 X60Qlf_0 = toOpenArray_1_I0zz6qv1_layptix6a1(params_0);
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_239 = len_6_I0tpktl1_layptix6a1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_239){
          {
            {
              X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_3 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_0, X60Qlf_1);
              if ((*X60Qii_3) == NIM_NIL){
                return NIM_FALSE;}
              MarshalClass_0_marbdjk4t1 X60Qx_240 = marshalClass_0_marbdjk4t1((*X60Qii_3));
              NB8 X60Qx_241 = marshalSafe_0_run8hsnpi(X60Qx_240);
              if (X60Qx_241){
                goto continueLabel_2;}
              NB8 X60Qx_242;
              NB8 X60Qx_243;
              if ((*(*X60Qii_3)).d_00.kind_0 == 6){
                X60Qx_243 = (!((*(*X60Qii_3)).d_00.elem_0 == NIM_NIL));}
              else {
                X60Qx_243 = NIM_FALSE;}
              if (X60Qx_243){
                NB8 X60Qx_244;
                if ((*(*(*X60Qii_3)).d_00.elem_0).d_00.kind_0 == 10){
                  X60Qx_244 = NIM_TRUE;}
                else {
                  X60Qx_244 = ((*(*(*X60Qii_3)).d_00.elem_0).d_00.kind_0 == 11);}
                X60Qx_242 = X60Qx_244;}
              else {
                X60Qx_242 = NIM_FALSE;}
              if (X60Qx_242){
                goto continueLabel_2;}
              NB8 X60Qx_245 = isArenaPtrAggregate_0_marbdjk4t1((*X60Qii_3));
              if (X60Qx_245){
                goto continueLabel_2;}
              if ((*(*X60Qii_3)).d_00.kind_0 == 5){
                goto continueLabel_2;}
              return NIM_FALSE;}
            continueLabel_2: ;}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NB8 X60Qx_246;
  if ((!(ret_0 == NIM_NIL))){
    MarshalClass_0_marbdjk4t1 X60Qx_247 = marshalClass_0_marbdjk4t1(ret_0);
    NB8 X60Qx_248 = marshalSafe_0_run8hsnpi(X60Qx_247);
    X60Qx_246 = (!X60Qx_248);}
  else {
    X60Qx_246 = NIM_FALSE;}
  if (X60Qx_246){
    return NIM_FALSE;}
  result_7 = NIM_TRUE;
  return result_7;}
NB8 hybridSigEligible_0_run8hsnpi(Cursor_0_nifb6mq6y1 procCur_0){
  NB8 result_8;
  Routine_0_decqocs071 r_1 = asRoutine_0_decqocs071(procCur_0, 0);
  seq_0_I3ump14_aow7lb5cq1 descs_0 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  Cursor_0_nifb6mq6y1 pc_0 = r_1.params_0;
  eQwasMoved_0_nifb6mq6y1((&r_1.params_0));
  NB8 X60Qx_111;
  NifKind_0_nif81dubp1 X60Qx_249 = kind_0_nifb6mq6y1(pc_0);
  if (X60Qx_249 == 11){
    string_0_sysvq0asl X60Qtmp_37 = nodeTag_0_run8hsnpi(pc_0);
    NB8 X60Qx_250 = eqQ_20_sysvq0asl(X60Qtmp_37, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_der823rwr1)}
    );
    X60Qx_111 = X60Qx_250;
    nimStrDestroy(X60Qtmp_37);}
  else {
    X60Qx_111 = NIM_FALSE;}
  if (X60Qx_111){
    inc_0_nifb6mq6y1((&pc_0));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_251 = kind_0_nifb6mq6y1(pc_0);
        if ((!(X60Qx_251 == 12))){
          NifKind_0_nif81dubp1 X60Qx_252 = kind_0_nifb6mq6y1(pc_0);
          if (X60Qx_252 == 11){
            Local_0_decqocs071 loc_0 = takeLocal_0_decqocs071((&pc_0), 2);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_253 = typeDescOf_0_run8hsnpi(loc_0.typ_0, 0);
            add_0_Ijteip9_run8hsnpi((&descs_0), X60Qx_253);
            eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_0));}
          else {
            skip_0_nifb6mq6y1((&pc_0));}}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* ret_1 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL));
  NB8 X60Qx_254;
  NifKind_0_nif81dubp1 X60Qx_255 = kind_0_nifb6mq6y1(r_1.retType_0);
  if (X60Qx_255 == 11){
    X60Qx_254 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_256 = kind_0_nifb6mq6y1(r_1.retType_0);
    X60Qx_254 = (X60Qx_256 == 4);}
  if (X60Qx_254){
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(ret_1);
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_257 = typeDescOf_0_run8hsnpi(r_1.retType_0, 0);
    ret_1 = X60Qx_257;}
  NB8 X60Qx_258 = hybridDecision_0_run8hsnpi(descs_0, ret_1);
  result_8 = X60Qx_258;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(ret_1);
  eQdestroy_0_nifb6mq6y1((&pc_0));
  eQdestroy_1_Iqg9snl1_aow7lb5cq1(descs_0);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
  return result_8;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(ret_1);
  eQdestroy_0_nifb6mq6y1((&pc_0));
  eQdestroy_1_Iqg9snl1_aow7lb5cq1(descs_0);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
  return result_8;}
N_NIMCALL(NB8, stubDecline_0_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* p_5, NU32 sym_2, string_0_sysvq0asl base_2, seq_0_I50urnw_croph25r5 args_2, Value_0_valzr1t4f* res_2){
  NB8 result_9;
  declineBegin_0_croph25r5(base_2);
  declineNote_0_croph25r5(2, (string_0_sysvq0asl){
    .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I1952482970424587404_run8hsnpi)}
  );
  result_9 = NIM_FALSE;
  return result_9;}
X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* newCabiProviderStub_0_run8hsnpi(void){
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* result_10;
  eQwasmovedQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi((&result_10));
  eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(result_10);
  void* X60Qx_259 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax));
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* X60Qtmp_38 = ((X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*)X60Qx_259);
  (*X60Qtmp_38) = (X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax){
    .r_00 = 0, .d_00 = (HybridProvider_Obj_0_run8hsnpi){
      (&HybridProvider_Obj_0_vt_run8hsnpi), .kind_0 = 3, .codec_0 = 1, .policy_0 = 1, .name_0 = (string_0_sysvq0asl){
        .bytes_0 = 1650549758u, .more_0 = (&strlit_0_I5159512292478983011_run8hsnpi)}
      , .resolveFastImpl_0 = NIM_NIL, .marshalArgs_0 = NIM_NIL, .marshalReturn_0 = NIM_NIL, .ownsImpl_0 = ((X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpiZSX53ymX49d0nifh7u8pu1AboolZAnimcallZAfalseZAR75_run8hsnpi)NIM_NIL), .invoke_0 = stubDecline_0_run8hsnpi}}
  ;
  result_10 = X60Qtmp_38;
  return result_10;}
X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* newHybridRegistry_0_run8hsnpi(void){
  X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* result_11;
  eQwasmovedQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi((&result_11));
  eQdestroyQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi(result_11);
  void* X60Qx_260 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax));
  X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* X60Qtmp_39 = ((X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax*)X60Qx_260);
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* X60Qx_261 = newCabiProviderStub_0_run8hsnpi();
  seq_0_Ixkko8n_run8hsnpi X60Qx_262 = newSeqUninit_0_Iyquyq_run8hsnpi(0);
  (*X60Qtmp_39) = (X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax){
    .r_00 = 0, .d_00 = (HybridRegistry_Obj_0_run8hsnpi){
      .provider_0 = X60Qx_261, .extra_0 = X60Qx_262}}
  ;
  result_11 = X60Qtmp_39;
  return result_11;}
NB8 providerMayOwn_0_run8hsnpi(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* p_7, NU32 sym_4){
  NB8 result_15;
  NB8 X60Qx_279;
  if (p_7 == NIM_NIL){
    X60Qx_279 = NIM_TRUE;}
  else {
    X60Qx_279 = (((void*)(*p_7).d_00.invoke_0) == NIM_NIL);}
  if (X60Qx_279){
    return NIM_FALSE;}
  if (((void*)(*p_7).d_00.ownsImpl_0) == NIM_NIL){
    return NIM_TRUE;}
  NB8 X60Qx_280 = (*p_7).d_00.ownsImpl_0(p_7, sym_4);
  result_15 = X60Qx_280;
  return result_15;}
CrossOutcome_0_croph25r5 hybridTryDispatch_0_run8hsnpi(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* reg_0, NU32 sym_5, string_0_sysvq0asl base_4, seq_0_I50urnw_croph25r5 args_5, Value_0_valzr1t4f* res_5){
  CrossOutcome_0_croph25r5 result_16;
  eQwasmovedQ_SX43rossX4futcome0croph25r5_0_croph25r5((&result_16));
  NB8 X60Qx_281;
  NB8 X60Qx_282;
  if (reg_0 == NIM_NIL){
    X60Qx_282 = NIM_TRUE;}
  else {
    X60Qx_282 = ((*reg_0).d_00.provider_0 == NIM_NIL);}
  if (X60Qx_282){
    X60Qx_281 = NIM_TRUE;}
  else {
    X60Qx_281 = (((void*)(*(*reg_0).d_00.provider_0).d_00.invoke_0) == NIM_NIL);}
  if (X60Qx_281){
    CrossOutcome_0_croph25r5 X60Qx_283 = crossDecline_0_croph25r5(4, (string_0_sysvq0asl){
      .bytes_0 = 544173822u, .more_0 = (&strlit_0_I2753240950845275664_run8hsnpi)}
    );
    result_16 = X60Qx_283;
    return result_16;}
  NB8 asked_0 = NIM_FALSE;
  NB8 X60Qx_284 = providerMayOwn_0_run8hsnpi((*reg_0).d_00.provider_0, sym_5);
  if (X60Qx_284){
    asked_0 = NIM_TRUE;
    NB8 X60Qx_285 = (*(*reg_0).d_00.provider_0).d_00.invoke_0((*reg_0).d_00.provider_0, sym_5, base_4, args_5, res_5);
    if (X60Qx_285){
      CrossOutcome_0_croph25r5 X60Qx_286 = crossOk_0_croph25r5((&(*res_5)), 3, base_4);
      result_16 = X60Qx_286;
      return result_16;}}
  {
    openArray_0_Ihcf6y9_run8hsnpi X60Qlf_2 = toOpenArray_1_Iumnf4i1_run8hsnpi((*reg_0).d_00.extra_0);
    NI32 X60Qlf_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_287 = len_6_Ij4lmhs_run8hsnpi(X60Qlf_2);
        if (X60Qlf_3 < X60Qx_287){
          {
            X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** X60Qii_2 = getQ_10_Iwwsp9w1_run8hsnpi(X60Qlf_2, X60Qlf_3);
            NB8 X60Qx_288 = providerMayOwn_0_run8hsnpi((*X60Qii_2), sym_5);
            if (X60Qx_288){
              asked_0 = NIM_TRUE;
              NB8 X60Qx_289 = (*(*X60Qii_2)).d_00.invoke_0((*X60Qii_2), sym_5, base_4, args_5, res_5);
              if (X60Qx_289){
                CrossOutcome_0_croph25r5 X60Qx_290 = crossOk_0_croph25r5((&(*res_5)), 3, base_4);
                result_16 = X60Qx_290;
                return result_16;}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  if ((!asked_0)){
    NB8 X60Qx_291;
    NB8 X60Qx_292 = routeLog_0_croph25r5();
    if (X60Qx_292){
      X60Qx_291 = NIM_TRUE;}
    else {
      NB8 X60Qx_293 = jitTraceLog_0_run8hsnpi();
      X60Qx_291 = X60Qx_293;}
    if (X60Qx_291){
      NB8 X60Qx_294 = (*(*reg_0).d_00.provider_0).d_00.invoke_0((*reg_0).d_00.provider_0, sym_5, base_4, args_5, res_5);}
    else {
      CrossOutcome_0_croph25r5 X60Qx_295 = crossDecline_0_croph25r5(3, (string_0_sysvq0asl){
        .bytes_0 = 544173822u, .more_0 = (&strlit_0_I13886929192389480583_run8hsnpi)}
      );
      result_16 = X60Qx_295;
      return result_16;}}
  string_0_sysvq0asl why_0 = blockerReason_0_croph25r5();
  NI32 X60Qx_296 = len_4_sysvq0asl(why_0);
  if (X60Qx_296 == 0){
    string_0_sysvq0asl X60Qdesugar_0 = nimStrDup((*(*reg_0).d_00.provider_0).d_00.name_0);
    NI32 X60Qx_297 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I7414938221747216170_run8hsnpi)}
    );
    NI32 X60Qx_298 = len_4_sysvq0asl(X60Qdesugar_0);
    NI32 X60Qx_299 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1679828990u, .more_0 = (&strlit_0_I5892731654726801288_run8hsnpi)}
    );
    NI32 X60Qx_300 = len_4_sysvq0asl(base_4);
    NI32 X60Qx_301 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1998596094u, .more_0 = (&strlit_0_I9873774322074382144_run8hsnpi)}
    );
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_297 + X60Qx_298)) + X60Qx_299)) + X60Qx_300)) + X60Qx_301)));
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I7414938221747216170_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), X60Qdesugar_0);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 1679828990u, .more_0 = (&strlit_0_I5892731654726801288_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), base_4);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 1998596094u, .more_0 = (&strlit_0_I9873774322074382144_run8hsnpi)}
    );
    nimStrDestroy(why_0);
    why_0 = X60Qdesugar_1;
    nimStrWasMoved((&X60Qdesugar_1));
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);}
  eQdestroyQ_SX43rossX4futcome0croph25r5_0_croph25r5((&result_16));
  CrossOutcome_0_croph25r5 X60Qx_302 = crossDecline_0_croph25r5(3, why_0);
  result_16 = X60Qx_302;
  nimStrDestroy(why_0);
  return result_16;
  nimStrDestroy(why_0);
  return result_16;}
NB8 hybridArenaTrace_0_run8hsnpi(void){
  NB8 result_19;
  string_0_sysvq0asl X60Qtmp_42 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I819492781050547440_croph25r5)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_305 = eqQ_20_sysvq0asl(X60Qtmp_42, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  result_19 = X60Qx_305;
  nimStrDestroy(X60Qtmp_42);
  return result_19;
  nimStrDestroy(X60Qtmp_42);
  return result_19;}
NB8 jitCallLog_0_run8hsnpi(void){
  NB8 result_20;
  string_0_sysvq0asl X60Qtmp_43 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I6946320866761157030_aow7lb5cq1)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_306 = eqQ_20_sysvq0asl(X60Qtmp_43, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  result_20 = X60Qx_306;
  nimStrDestroy(X60Qtmp_43);
  return result_20;
  nimStrDestroy(X60Qtmp_43);
  return result_20;}
NB8 jitTraceLog_0_run8hsnpi(void){
  NB8 result_21;
  string_0_sysvq0asl X60Qtmp_44 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I12470586101363112036_run8hsnpi)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_307 = eqQ_20_sysvq0asl(X60Qtmp_44, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  result_21 = X60Qx_307;
  nimStrDestroy(X60Qtmp_44);
  return result_21;
  nimStrDestroy(X60Qtmp_44);
  return result_21;}
string_0_sysvq0asl baseNameOf_0_run8hsnpi(NU32 sym_6){
  string_0_sysvq0asl result_22;
  nimStrWasMoved((&result_22));
  nimStrDestroy(result_22);
  string_0_sysvq0asl* X60Qx_308 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_6);
  string_0_sysvq0asl X60Qx_309 = nimStrDup((*X60Qx_308));
  result_22 = X60Qx_309;
  extractBasename_1_symkyk35i1((&result_22));
  return result_22;}
string_0_sysvq0asl aowlcSymName_0_run8hsnpi(NU32 sym_7){
  string_0_sysvq0asl result_23;
  nimStrWasMoved((&result_23));
  string_0_sysvq0asl* X60Qx_310 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_7);
  string_0_sysvq0asl s_5 = nimStrDup((*X60Qx_310));
  NI32 X60Qx_311 = len_4_sysvq0asl(s_5);
  if (X60Qx_311 == 0){
    nimStrDestroy(s_5);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_23);
  result_23 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_4 = toOpenArray_2_sysvq0asl((&s_5));
    NI32 X60Qlf_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_312 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_4);
        if (X60Qlf_5 < X60Qx_312){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_4, X60Qlf_5);
            if ((*X60Qii_2) == (NC8)'.'){
              add_1_sysvq0asl((&result_23), (NC8)'_');}
            else {
              NB8 X60Qx_313;
              NB8 X60Qx_314;
              NB8 X60Qx_315;
              NB8 X60Qx_316;
              if ((NC8)'a' <= (*X60Qii_2)){
                X60Qx_316 = ((*X60Qii_2) <= (NC8)'z');}
              else {
                X60Qx_316 = NIM_FALSE;}
              if (X60Qx_316){
                X60Qx_315 = NIM_TRUE;}
              else {
                NB8 X60Qx_317;
                if ((NC8)'A' <= (*X60Qii_2)){
                  X60Qx_317 = ((*X60Qii_2) <= (NC8)'Z');}
                else {
                  X60Qx_317 = NIM_FALSE;}
                X60Qx_315 = X60Qx_317;}
              if (X60Qx_315){
                X60Qx_314 = NIM_TRUE;}
              else {
                NB8 X60Qx_318;
                if ((NC8)'0' <= (*X60Qii_2)){
                  X60Qx_318 = ((*X60Qii_2) <= (NC8)'9');}
                else {
                  X60Qx_318 = NIM_FALSE;}
                X60Qx_314 = X60Qx_318;}
              if (X60Qx_314){
                X60Qx_313 = NIM_TRUE;}
              else {
                X60Qx_313 = ((*X60Qii_2) == (NC8)'_');}
              if (X60Qx_313){
                add_1_sysvq0asl((&result_23), (*X60Qii_2));}
              else {
                nimStrDestroy(s_5);
                return (string_0_sysvq0asl){
                  .bytes_0 = 0u, .more_0 = NIM_NIL}
                ;}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  nimStrDestroy(s_5);
  return result_23;
  nimStrDestroy(s_5);
  return result_23;}
string_0_sysvq0asl srcScalarName_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_0){
  string_0_sysvq0asl result_24;
  nimStrWasMoved((&result_24));
  string_0_sysvq0asl X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  switch ((*td_0).d_00.kind_0){
    case 0:
    {
      string_0_sysvq0asl X60Qx_4;
      nimStrWasMoved((&X60Qx_4));
      NI64 X60Qx_5;
      if ((*td_0).d_00.bits_0 <= 0){
        X60Qx_5 = 64;}
      else {
        X60Qx_5 = (*td_0).d_00.bits_0;}
      switch (X60Qx_5){
        case 8:
        {
          nimStrDestroy(X60Qx_4);
          X60Qx_4 = (string_0_sysvq0asl){
            .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I17873677997389965638_red2rogzl)}
          ;}
        break;
        case 16:
        {
          nimStrDestroy(X60Qx_4);
          X60Qx_4 = (string_0_sysvq0asl){
            .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I17450945768583924279_red2rogzl)}
          ;}
        break;
        case 32:
        {
          nimStrDestroy(X60Qx_4);
          X60Qx_4 = (string_0_sysvq0asl){
            .bytes_0 = 1953393150u, .more_0 = (&strlit_0_I6136553206224205495_red2rogzl)}
          ;}
        break;
        default:
        {
          nimStrDestroy(X60Qx_4);
          X60Qx_4 = (string_0_sysvq0asl){
            .bytes_0 = 1953392899u, .more_0 = NIM_NIL}
          ;}
        break;}
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = X60Qx_4;
      nimStrWasMoved((&X60Qx_4));
      nimStrDestroy(X60Qx_4);}
    break;
    case 1:
    {
      string_0_sysvq0asl X60Qx_6;
      nimStrWasMoved((&X60Qx_6));
      NI64 X60Qx_7;
      if ((*td_0).d_00.bits_0 <= 0){
        X60Qx_7 = 64;}
      else {
        X60Qx_7 = (*td_0).d_00.bits_0;}
      switch (X60Qx_7){
        case 8:
        {
          nimStrDestroy(X60Qx_6);
          X60Qx_6 = (string_0_sysvq0asl){
            .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I7032352044772062024_red2rogzl)}
          ;}
        break;
        case 16:
        {
          nimStrDestroy(X60Qx_6);
          X60Qx_6 = (string_0_sysvq0asl){
            .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I1184649450617298588_red2rogzl)}
          ;}
        break;
        case 32:
        {
          nimStrDestroy(X60Qx_6);
          X60Qx_6 = (string_0_sysvq0asl){
            .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I13604536769712135534_red2rogzl)}
          ;}
        break;
        default:
        {
          nimStrDestroy(X60Qx_6);
          X60Qx_6 = (string_0_sysvq0asl){
            .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I18357185398770638485_aow7lb5cq1)}
          ;}
        break;}
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = X60Qx_6;
      nimStrWasMoved((&X60Qx_6));
      nimStrDestroy(X60Qx_6);}
    break;
    case 2:
    {
      string_0_sysvq0asl X60Qx_8;
      nimStrWasMoved((&X60Qx_8));
      if ((*td_0).d_00.bits_0 == 32){
        nimStrDestroy(X60Qx_8);
        X60Qx_8 = (string_0_sysvq0asl){
          .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I589554620119875380_red2rogzl)}
        ;}
      else {
        nimStrDestroy(X60Qx_8);
        X60Qx_8 = (string_0_sysvq0asl){
          .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I11643015150811461308_aow7lb5cq1)}
        ;}
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = X60Qx_8;
      nimStrWasMoved((&X60Qx_8));
      nimStrDestroy(X60Qx_8);}
    break;
    case 4:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
      ;}
    break;
    case 3:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1634231294u, .more_0 = (&strlit_0_I3703322799828345117_aow7lb5cq1)}
      ;}
    break;
    case 5:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I6300154543333844069_intzsnzax)}
      ;}
    break;
    default:
    {
      nimStrDestroy(X60Qx_3);
      X60Qx_3 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    break;}
  nimStrDestroy(result_24);
  result_24 = X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  nimStrDestroy(X60Qx_3);
  return result_24;
  nimStrDestroy(X60Qx_3);
  return result_24;}
NB8 podHasEnumOrArray_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_1){
  NB8 result_26;
  switch ((*td_1).d_00.kind_0){
    case 8:
    case 9:
    {
      result_26 = NIM_TRUE;}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_325;
      if ((!((*td_1).d_00.base_0 == NIM_NIL))){
        NB8 X60Qx_326 = podHasEnumOrArray_0_run8hsnpi((*td_1).d_00.base_0);
        X60Qx_325 = X60Qx_326;}
      else {
        X60Qx_325 = NIM_FALSE;}
      if (X60Qx_325){
        return NIM_TRUE;}
      {
        openArray_0_I3ca6t4_layptix6a1 X60Qlf_6 = toOpenArray_1_I0zz6qv1_layptix6a1((*td_1).d_00.fields_0);
        NI32 X60Qlf_7 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_327 = len_6_I0tpktl1_layptix6a1(X60Qlf_6);
            if (X60Qlf_7 < X60Qx_327){
              {
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_2 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_6, X60Qlf_7);
                NB8 X60Qx_328 = podHasEnumOrArray_0_run8hsnpi((*X60Qii_2));
                if (X60Qx_328){
                  return NIM_TRUE;}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;
      result_26 = NIM_FALSE;}
    break;
    case 13:
    {
      NB8 X60Qx_329;
      if ((!((*td_1).d_00.elem_0 == NIM_NIL))){
        NB8 X60Qx_330 = podHasEnumOrArray_0_run8hsnpi((*td_1).d_00.elem_0);
        X60Qx_329 = X60Qx_330;}
      else {
        X60Qx_329 = NIM_FALSE;}
      result_26 = X60Qx_329;}
    break;
    default:
    {
      result_26 = NIM_FALSE;}
    break;}
  return result_26;}
X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi seqElemCursor_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_1){
  X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi result_27;
  eQwasmovedQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi((&result_27));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(result_27);
  result_27 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
    .fld_0 = (Cursor_0_nifb6mq6y1){
      .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
    , .fld_1 = NIM_FALSE}
  ;
  NB8 X60Qx_113;
  NifKind_0_nif81dubp1 X60Qx_331 = kind_0_nifb6mq6y1(cur_1);
  if (X60Qx_331 == 11){
    string_0_sysvq0asl X60Qtmp_47 = nodeTag_0_run8hsnpi(cur_1);
    NB8 X60Qx_332 = eqQ_20_sysvq0asl(X60Qtmp_47, (string_0_sysvq0asl){
      .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
    );
    X60Qx_113 = X60Qx_332;
    nimStrDestroy(X60Qtmp_47);}
  else {
    X60Qx_113 = NIM_FALSE;}
  if (X60Qx_113){
    Cursor_0_nifb6mq6y1 e_11 = eQdup_0_nifb6mq6y1(cur_1);
    inc_0_nifb6mq6y1((&e_11));
    Cursor_0_nifb6mq6y1 X60Qtmp_48 = e_11;
    eQwasMoved_0_nifb6mq6y1((&e_11));
    result_27 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
      .fld_0 = X60Qtmp_48, .fld_1 = NIM_TRUE}
    ;
    eQdestroy_0_nifb6mq6y1((&e_11));
    return result_27;
    eQdestroy_0_nifb6mq6y1((&e_11));}
  NifKind_0_nif81dubp1 X60Qx_333 = kind_0_nifb6mq6y1(cur_1);
  if (X60Qx_333 == 4){
    NU32 X60Qx_334 = symId_0_nifb6mq6y1(cur_1);
    LoadResult_0_prorcx25w1 res_8 = tryLoadSymSafe_0_modzy18mg1(X60Qx_334);
    NB8 X60Qx_114;
    NB8 X60Qx_335;
    if (res_8.status_0 == 3){
      NifKind_0_nif81dubp1 X60Qx_336 = kind_0_nifb6mq6y1(res_8.decl_0);
      X60Qx_335 = (X60Qx_336 == 11);}
    else {
      X60Qx_335 = NIM_FALSE;}
    if (X60Qx_335){
      string_0_sysvq0asl X60Qtmp_49 = nodeTag_0_run8hsnpi(res_8.decl_0);
      NB8 X60Qx_337 = eqQ_20_sysvq0asl(X60Qtmp_49, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
      );
      X60Qx_114 = X60Qx_337;
      nimStrDestroy(X60Qtmp_49);}
    else {
      X60Qx_114 = NIM_FALSE;}
    if (X60Qx_114){
      TypeDecl_0_decqocs071 td_13 = asTypeDecl_0_decqocs071(res_8.decl_0);
      Cursor_0_nifb6mq6y1 b_1 = td_13.typevars_0;
      eQwasMoved_0_nifb6mq6y1((&td_13.typevars_0));
      NB8 X60Qx_115;
      NifKind_0_nif81dubp1 X60Qx_338 = kind_0_nifb6mq6y1(b_1);
      if (X60Qx_338 == 11){
        string_0_sysvq0asl X60Qtmp_50 = nodeTag_0_run8hsnpi(b_1);
        NB8 X60Qx_339 = eqQ_20_sysvq0asl(X60Qtmp_50, (string_0_sysvq0asl){
          .bytes_0 = 7627010u, .more_0 = NIM_NIL}
        );
        X60Qx_115 = X60Qx_339;
        nimStrDestroy(X60Qtmp_50);}
      else {
        X60Qx_115 = NIM_FALSE;}
      if (X60Qx_115){
        inc_0_nifb6mq6y1((&b_1));
        skip_0_nifb6mq6y1((&b_1));
        Cursor_0_nifb6mq6y1 X60Qtmp_51 = b_1;
        eQwasMoved_0_nifb6mq6y1((&b_1));
        result_27 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
          .fld_0 = X60Qtmp_51, .fld_1 = NIM_TRUE}
        ;
        eQdestroy_0_nifb6mq6y1((&b_1));
        eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_13));
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
        return result_27;}
      eQdestroy_0_nifb6mq6y1((&b_1));
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_13));}
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);}
  return result_27;}
X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi seqElemNameSym_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_2, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_0){
  X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi result_28;
  eQwasmovedQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi((&result_28));
  eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(result_28);
  result_28 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
    .fld_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .fld_1 = ((NU32)0u)}
  ;
  X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi X60Qtmptup_0 = seqElemCursor_0_run8hsnpi(cur_2);
  Cursor_0_nifb6mq6y1 ec_0 = X60Qtmptup_0.fld_0;
  eQwasMoved_0_nifb6mq6y1((&X60Qtmptup_0.fld_0));
  NB8 ok_0 = X60Qtmptup_0.fld_1;
  NB8 X60Qx_340;
  if (ok_0){
    NifKind_0_nif81dubp1 X60Qx_341 = kind_0_nifb6mq6y1(ec_0);
    X60Qx_340 = (X60Qx_341 == 4);}
  else {
    X60Qx_340 = NIM_FALSE;}
  if (X60Qx_340){
    NU32 X60Qx_342 = symId_0_nifb6mq6y1(ec_0);
    string_0_sysvq0asl X60Qx_343 = baseNameOf_0_run8hsnpi(X60Qx_342);
    NU32 X60Qx_344 = symId_0_nifb6mq6y1(ec_0);
    result_28 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
      .fld_0 = X60Qx_343, .fld_1 = X60Qx_344}
    ;
    eQdestroy_0_nifb6mq6y1((&ec_0));
    eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_0);
    return result_28;}
  eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(result_28);
  string_0_sysvq0asl X60Qx_345 = srcScalarName_0_run8hsnpi(elem_0);
  result_28 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
    .fld_0 = X60Qx_345, .fld_1 = ((NU32)0u)}
  ;
  eQdestroy_0_nifb6mq6y1((&ec_0));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_0);
  return result_28;
  eQdestroy_0_nifb6mq6y1((&ec_0));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_0);
  return result_28;}
NU32 seqElemSymOf_0_run8hsnpi(NU32 typeSym_0){
  NU32 result_29;
  result_29 = ((NU32)0u);
  if (((NU32)typeSym_0) == ((NU32)0u)){
    return result_29;}
  LoadResult_0_prorcx25w1 res_9 = tryLoadSymSafe_0_modzy18mg1(typeSym_0);
  NB8 X60Qx_116;
  NB8 X60Qx_346;
  if ((!(res_9.status_0 == 3))){
    X60Qx_346 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_347 = kind_0_nifb6mq6y1(res_9.decl_0);
    X60Qx_346 = (!(X60Qx_347 == 11));}
  if (X60Qx_346){
    X60Qx_116 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_52 = nodeTag_0_run8hsnpi(res_9.decl_0);
    NB8 X60Qx_348 = eqQ_20_sysvq0asl(X60Qtmp_52, (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
    );
    X60Qx_116 = (!X60Qx_348);
    nimStrDestroy(X60Qtmp_52);}
  if (X60Qx_116){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
    return result_29;}
  TypeDecl_0_decqocs071 td_14 = asTypeDecl_0_decqocs071(res_9.decl_0);
  Cursor_0_nifb6mq6y1 b_2 = td_14.typevars_0;
  eQwasMoved_0_nifb6mq6y1((&td_14.typevars_0));
  NB8 X60Qx_117;
  NifKind_0_nif81dubp1 X60Qx_349 = kind_0_nifb6mq6y1(b_2);
  if (X60Qx_349 == 11){
    string_0_sysvq0asl X60Qtmp_53 = nodeTag_0_run8hsnpi(b_2);
    NB8 X60Qx_350 = eqQ_20_sysvq0asl(X60Qtmp_53, (string_0_sysvq0asl){
      .bytes_0 = 7627010u, .more_0 = NIM_NIL}
    );
    X60Qx_117 = X60Qx_350;
    nimStrDestroy(X60Qtmp_53);}
  else {
    X60Qx_117 = NIM_FALSE;}
  if (X60Qx_117){
    inc_0_nifb6mq6y1((&b_2));
    skip_0_nifb6mq6y1((&b_2));
    NifKind_0_nif81dubp1 X60Qx_351 = kind_0_nifb6mq6y1(b_2);
    if (X60Qx_351 == 4){
      NU32 X60Qx_352 = symId_0_nifb6mq6y1(b_2);
      result_29 = X60Qx_352;}}
  eQdestroy_0_nifb6mq6y1((&b_2));
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_14));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
  return result_29;
  eQdestroy_0_nifb6mq6y1((&b_2));
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_14));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
  return result_29;}
X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi arrayElemCursor_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_3){
  X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi result_30;
  eQwasmovedQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi((&result_30));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(result_30);
  result_30 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
    .fld_0 = (Cursor_0_nifb6mq6y1){
      .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
    , .fld_1 = NIM_FALSE}
  ;
  NB8 X60Qx_118;
  NifKind_0_nif81dubp1 X60Qx_353 = kind_0_nifb6mq6y1(cur_3);
  if (X60Qx_353 == 11){
    string_0_sysvq0asl X60Qtmp_54 = nodeTag_0_run8hsnpi(cur_3);
    NB8 X60Qx_354 = eqQ_20_sysvq0asl(X60Qtmp_54, (string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
    );
    X60Qx_118 = X60Qx_354;
    nimStrDestroy(X60Qtmp_54);}
  else {
    X60Qx_118 = NIM_FALSE;}
  if (X60Qx_118){
    Cursor_0_nifb6mq6y1 e_12 = eQdup_0_nifb6mq6y1(cur_3);
    inc_0_nifb6mq6y1((&e_12));
    Cursor_0_nifb6mq6y1 X60Qtmp_55 = e_12;
    eQwasMoved_0_nifb6mq6y1((&e_12));
    result_30 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
      .fld_0 = X60Qtmp_55, .fld_1 = NIM_TRUE}
    ;
    eQdestroy_0_nifb6mq6y1((&e_12));
    return result_30;
    eQdestroy_0_nifb6mq6y1((&e_12));}
  NifKind_0_nif81dubp1 X60Qx_355 = kind_0_nifb6mq6y1(cur_3);
  if (X60Qx_355 == 4){
    NU32 X60Qx_356 = symId_0_nifb6mq6y1(cur_3);
    LoadResult_0_prorcx25w1 res_10 = tryLoadSymSafe_0_modzy18mg1(X60Qx_356);
    NB8 X60Qx_119;
    NB8 X60Qx_357;
    if (res_10.status_0 == 3){
      NifKind_0_nif81dubp1 X60Qx_358 = kind_0_nifb6mq6y1(res_10.decl_0);
      X60Qx_357 = (X60Qx_358 == 11);}
    else {
      X60Qx_357 = NIM_FALSE;}
    if (X60Qx_357){
      string_0_sysvq0asl X60Qtmp_56 = nodeTag_0_run8hsnpi(res_10.decl_0);
      NB8 X60Qx_359 = eqQ_20_sysvq0asl(X60Qtmp_56, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
      );
      X60Qx_119 = X60Qx_359;
      nimStrDestroy(X60Qtmp_56);}
    else {
      X60Qx_119 = NIM_FALSE;}
    if (X60Qx_119){
      TypeDecl_0_decqocs071 td_15 = asTypeDecl_0_decqocs071(res_10.decl_0);
      NB8 X60Qx_120;
      NifKind_0_nif81dubp1 X60Qx_360 = kind_0_nifb6mq6y1(td_15.body_0);
      if (X60Qx_360 == 11){
        string_0_sysvq0asl X60Qtmp_57 = nodeTag_0_run8hsnpi(td_15.body_0);
        NB8 X60Qx_361 = eqQ_20_sysvq0asl(X60Qtmp_57, (string_0_sysvq0asl){
          .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
        );
        X60Qx_120 = X60Qx_361;
        nimStrDestroy(X60Qtmp_57);}
      else {
        X60Qx_120 = NIM_FALSE;}
      if (X60Qx_120){
        Cursor_0_nifb6mq6y1 e_13 = td_15.body_0;
        eQwasMoved_0_nifb6mq6y1((&td_15.body_0));
        inc_0_nifb6mq6y1((&e_13));
        Cursor_0_nifb6mq6y1 X60Qtmp_58 = e_13;
        eQwasMoved_0_nifb6mq6y1((&e_13));
        result_30 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
          .fld_0 = X60Qtmp_58, .fld_1 = NIM_TRUE}
        ;
        eQdestroy_0_nifb6mq6y1((&e_13));
        eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_15));
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_10);
        return result_30;
        eQdestroy_0_nifb6mq6y1((&e_13));}
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_15));}
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_10);}
  return result_30;}
X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi arrayElemNameSym_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_4, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_1){
  X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi result_31;
  eQwasmovedQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi((&result_31));
  eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(result_31);
  result_31 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
    .fld_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .fld_1 = ((NU32)0u)}
  ;
  X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi X60Qtmptup_1 = arrayElemCursor_0_run8hsnpi(cur_4);
  Cursor_0_nifb6mq6y1 ec_1 = X60Qtmptup_1.fld_0;
  eQwasMoved_0_nifb6mq6y1((&X60Qtmptup_1.fld_0));
  NB8 ok_1 = X60Qtmptup_1.fld_1;
  NB8 X60Qx_362;
  if (ok_1){
    NifKind_0_nif81dubp1 X60Qx_363 = kind_0_nifb6mq6y1(ec_1);
    X60Qx_362 = (X60Qx_363 == 4);}
  else {
    X60Qx_362 = NIM_FALSE;}
  if (X60Qx_362){
    NU32 X60Qx_364 = symId_0_nifb6mq6y1(ec_1);
    string_0_sysvq0asl X60Qx_365 = baseNameOf_0_run8hsnpi(X60Qx_364);
    NU32 X60Qx_366 = symId_0_nifb6mq6y1(ec_1);
    result_31 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
      .fld_0 = X60Qx_365, .fld_1 = X60Qx_366}
    ;
    eQdestroy_0_nifb6mq6y1((&ec_1));
    eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_1);
    return result_31;}
  eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(result_31);
  string_0_sysvq0asl X60Qx_367 = srcScalarName_0_run8hsnpi(elem_1);
  result_31 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
    .fld_0 = X60Qx_367, .fld_1 = ((NU32)0u)}
  ;
  eQdestroy_0_nifb6mq6y1((&ec_1));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_1);
  return result_31;
  eQdestroy_0_nifb6mq6y1((&ec_1));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_1);
  return result_31;}
X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 varElemExpr_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_5, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_2){
  X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 result_32;
  eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi((&result_32));
  switch ((*td_2).d_00.kind_0){
    case 14:
    {
      result_32 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = (string_0_sysvq0asl){
          .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
        , .fld_1 = NIM_TRUE}
      ;
      return result_32;}
    break;
    case 0:
    case 1:
    case 2:
    case 4:
    case 3:
    {
      string_0_sysvq0asl n_5 = srcScalarName_0_run8hsnpi(td_2);
      string_0_sysvq0asl X60Qx_368 = nimStrDup(n_5);
      NI32 X60Qx_369 = len_4_sysvq0asl(n_5);
      result_32 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = X60Qx_368, .fld_1 = (0 < X60Qx_369)}
      ;
      nimStrDestroy(n_5);
      return result_32;
      nimStrDestroy(n_5);}
    break;
    case 15:
    {
      if ((*td_2).d_00.elem_0 == NIM_NIL){
        result_32 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
          .fld_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .fld_1 = NIM_FALSE}
        ;
        return result_32;}
      X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi X60Qtmptup_2 = seqElemCursor_0_run8hsnpi(cur_5);
      Cursor_0_nifb6mq6y1 ec_2 = X60Qtmptup_2.fld_0;
      eQwasMoved_0_nifb6mq6y1((&X60Qtmptup_2.fld_0));
      NB8 ok_2 = X60Qtmptup_2.fld_1;
      if ((!ok_2)){
        result_32 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
          .fld_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .fld_1 = NIM_FALSE}
        ;
        eQdestroy_0_nifb6mq6y1((&ec_2));
        eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_2);
        return result_32;}
      X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 X60Qtmptup_3 = varElemExpr_0_run8hsnpi(ec_2, (*td_2).d_00.elem_0);
      string_0_sysvq0asl inner_1 = X60Qtmptup_3.fld_0;
      nimStrWasMoved((&X60Qtmptup_3.fld_0));
      NB8 iok_0 = X60Qtmptup_3.fld_1;
      if ((!iok_0)){
        result_32 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
          .fld_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .fld_1 = NIM_FALSE}
        ;
        nimStrDestroy(inner_1);
        eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_3);
        eQdestroy_0_nifb6mq6y1((&ec_2));
        eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_2);
        return result_32;}
      NI32 X60Qx_370 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
      );
      NI32 X60Qx_371 = len_4_sysvq0asl(inner_1);
      NI32 X60Qx_372 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 23809u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_370 + X60Qx_371)) + X60Qx_372)));
      add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
        .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_2), inner_1);
      add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
        .bytes_0 = 23809u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qtmp_59 = X60Qdesugar_2;
      nimStrWasMoved((&X60Qdesugar_2));
      result_32 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = X60Qtmp_59, .fld_1 = NIM_TRUE}
      ;
      nimStrDestroy(X60Qdesugar_2);
      nimStrDestroy(inner_1);
      eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_3);
      eQdestroy_0_nifb6mq6y1((&ec_2));
      eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_2);
      return result_32;
      nimStrDestroy(X60Qdesugar_2);
      nimStrDestroy(inner_1);
      eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_3);
      eQdestroy_0_nifb6mq6y1((&ec_2));
      eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_2);}
    break;
    default:
    {
      result_32 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .fld_1 = NIM_FALSE}
      ;
      return result_32;}
    break;}
  return result_32;}
string_0_sysvq0asl leafScalarName_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_3){
  string_0_sysvq0asl result_33;
  nimStrWasMoved((&result_33));
  switch ((*td_3).d_00.kind_0){
    case 15:
    case 9:
    {
      string_0_sysvq0asl X60Qx_9;
      nimStrWasMoved((&X60Qx_9));
      if ((!((*td_3).d_00.elem_0 == NIM_NIL))){
        nimStrDestroy(X60Qx_9);
        string_0_sysvq0asl X60Qx_373 = leafScalarName_0_run8hsnpi((*td_3).d_00.elem_0);
        X60Qx_9 = X60Qx_373;}
      else {
        nimStrDestroy(X60Qx_9);
        X60Qx_9 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;}
      nimStrDestroy(result_33);
      result_33 = X60Qx_9;
      nimStrWasMoved((&X60Qx_9));
      nimStrDestroy(X60Qx_9);}
    break;
    case 14:
    {
      nimStrDestroy(result_33);
      result_33 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    break;
    default:
    {
      nimStrDestroy(result_33);
      string_0_sysvq0asl X60Qx_374 = srcScalarName_0_run8hsnpi(td_3);
      result_33 = X60Qx_374;}
    break;}
  return result_33;}
NB8 compositeOk_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_1, NI32 depth_1, NU32 tsym_0){
  NB8 result_34;
  if (t_1 == NIM_NIL){
    return NIM_FALSE;}
  if (8 < depth_1){
    return NIM_FALSE;}
  switch ((*t_1).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    case 14:
    {
      result_34 = NIM_TRUE;}
    break;
    case 17:
    case 13:
    {
      NB8 X60Qx_375;
      if ((!((*t_1).d_00.elem_0 == NIM_NIL))){
        NB8 X60Qx_376 = compositeOk_0_run8hsnpi((*t_1).d_00.elem_0, ((NI32)(depth_1 + 1)), ((NU32)0u));
        X60Qx_375 = X60Qx_376;}
      else {
        X60Qx_375 = NIM_FALSE;}
      result_34 = X60Qx_375;}
    break;
    case 16:
    {
      NI32 X60Qx_377 = setSizeInBytes_0_layptix6a1((*t_1).d_00.elem_0);
      result_34 = (0 < X60Qx_377);}
    break;
    case 15:
    {
      if ((*t_1).d_00.elem_0 == NIM_NIL){
        return NIM_FALSE;}
      NU32 es_0 = seqElemSymOf_0_run8hsnpi(tsym_0);
      NB8 X60Qx_378;
      if ((*(*t_1).d_00.elem_0).d_00.kind_0 == 10){
        X60Qx_378 = NIM_TRUE;}
      else {
        X60Qx_378 = ((*(*t_1).d_00.elem_0).d_00.kind_0 == 11);}
      if (X60Qx_378){
        if (((NU32)es_0) == ((NU32)0u)){
          return NIM_FALSE;}
        NB8 X60Qx_379 = compositeOk_0_run8hsnpi((*t_1).d_00.elem_0, ((NI32)(depth_1 + 1)), es_0);
        result_34 = X60Qx_379;
        return result_34;}
      NB8 X60Qx_380 = compositeOk_0_run8hsnpi((*t_1).d_00.elem_0, ((NI32)(depth_1 + 1)), es_0);
      result_34 = X60Qx_380;}
    break;
    case 9:
    {
      if ((*t_1).d_00.elem_0 == NIM_NIL){
        return NIM_FALSE;}
      NB8 X60Qx_381;
      if ((*(*t_1).d_00.elem_0).d_00.kind_0 == 10){
        X60Qx_381 = NIM_TRUE;}
      else {
        X60Qx_381 = ((*(*t_1).d_00.elem_0).d_00.kind_0 == 11);}
      if (X60Qx_381){
        return NIM_FALSE;}
      NB8 X60Qx_382 = compositeOk_0_run8hsnpi((*t_1).d_00.elem_0, ((NI32)(depth_1 + 1)), ((NU32)0u));
      result_34 = X60Qx_382;}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_383;
      if ((*t_1).d_00.incomplete_0){
        X60Qx_383 = NIM_TRUE;}
      else {
        X60Qx_383 = (*t_1).d_00.union_0;}
      if (X60Qx_383){
        return NIM_FALSE;}
      X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi info_0 = podFieldInfo_1_run8hsnpi(tsym_0);
      NI32 i_1 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_384 = len_3_I5m68tr1_aow7lb5cq1((*t_1).d_00.fields_0);
          if (i_1 < X60Qx_384){
            NU32 X60Qx_10;
            NI32 X60Qx_385 = len_3_I6y2imo_arecyyj7v(info_0.fld_2);
            if (i_1 < X60Qx_385){
              NU32* X60Qx_386 = getQ_7_I2v00yv1_arecyyj7v(info_0.fld_2, i_1);
              X60Qx_10 = (*X60Qx_386);}
            else {
              X60Qx_10 = ((NU32)0u);}
            NU32 fts_0 = X60Qx_10;
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_387 = getQ_7_I45w7c91_aow7lb5cq1((*t_1).d_00.fields_0, i_1);
            NB8 X60Qx_388 = compositeOk_0_run8hsnpi((*X60Qx_387), ((NI32)(depth_1 + 1)), fts_0);
            if ((!X60Qx_388)){
              eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_0);
              return NIM_FALSE;}
            inc_1_I6wjjge_aow2h993l1((&i_1));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      result_34 = NIM_TRUE;
      eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_0);}
    break;
    case 5:
    {
      result_34 = NIM_FALSE;}
    break;
    case 6:
    case 7:
    case 12:
    case 18:
    {
      result_34 = NIM_FALSE;}
    break;}
  return result_34;}
string_0_sysvq0asl abiKindName_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_2){
  string_0_sysvq0asl result_35;
  nimStrWasMoved((&result_35));
  if (t_2 == NIM_NIL){
    return (string_0_sysvq0asl){
      .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl X60Qx_11;
  nimStrWasMoved((&X60Qx_11));
  switch ((*t_2).d_00.kind_0){
    case 0:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1953392899u, .more_0 = NIM_NIL}
      ;}
    break;
    case 1:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I18357185398770638485_aow7lb5cq1)}
      ;}
    break;
    case 2:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I11643015150811461308_aow7lb5cq1)}
      ;}
    break;
    case 3:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1634231294u, .more_0 = (&strlit_0_I3703322799828345117_aow7lb5cq1)}
      ;}
    break;
    case 4:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
      ;}
    break;
    case 8:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
      ;}
    break;
    case 17:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16597999082088934835_emi78vuj01)}
      ;}
    break;
    case 16:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1952805635u, .more_0 = NIM_NIL}
      ;}
    break;
    case 5:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
      ;}
    break;
    case 6:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
      ;}
    break;
    case 7:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I16971225136864641703_nimry5ra91)}
      ;}
    break;
    case 13:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_fiepkwzpc)}
      ;}
    break;
    case 14:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
      ;}
    break;
    case 15:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
      ;}
    break;
    case 9:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
      ;}
    break;
    case 11:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
      ;}
    break;
    case 10:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
      ;}
    break;
    case 12:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I2937163572003096168_run8hsnpi)}
      ;}
    break;
    case 18:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1668175358u, .more_0 = (&strlit_0_I9228293753161605925_maglvku5g)}
      ;}
    break;}
  nimStrDestroy(result_35);
  result_35 = X60Qx_11;
  nimStrWasMoved((&X60Qx_11));
  nimStrDestroy(X60Qx_11);
  return result_35;
  nimStrDestroy(X60Qx_11);
  return result_35;}
string_0_sysvq0asl marshalClassName_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_3){
  string_0_sysvq0asl result_36;
  nimStrWasMoved((&result_36));
  if (t_3 == NIM_NIL){
    return (string_0_sysvq0asl){
      .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl X60Qx_12;
  nimStrWasMoved((&X60Qx_12));
  MarshalClass_0_marbdjk4t1 X60Qx_389 = marshalClass_0_marbdjk4t1(t_3);
  switch (X60Qx_389){
    case 0:
    {
      nimStrDestroy(X60Qx_12);
      X60Qx_12 = (string_0_sysvq0asl){
        .bytes_0 = 1399025150u, .more_0 = (&strlit_0_I990882640025799687_marbdjk4t1)}
      ;}
    break;
    case 1:
    {
      nimStrDestroy(X60Qx_12);
      X60Qx_12 = (string_0_sysvq0asl){
        .bytes_0 = 1348693502u, .more_0 = (&strlit_0_I3470422228391514573_marbdjk4t1)}
      ;}
    break;
    case 2:
    {
      nimStrDestroy(X60Qx_12);
      X60Qx_12 = (string_0_sysvq0asl){
        .bytes_0 = 1399025150u, .more_0 = (&strlit_0_I696057604909997793_marbdjk4t1)}
      ;}
    break;
    case 3:
    {
      nimStrDestroy(X60Qx_12);
      X60Qx_12 = (string_0_sysvq0asl){
        .bytes_0 = 1399025150u, .more_0 = (&strlit_0_I17665588267585860306_marbdjk4t1)}
      ;}
    break;
    case 4:
    {
      nimStrDestroy(X60Qx_12);
      X60Qx_12 = (string_0_sysvq0asl){
        .bytes_0 = 1382247934u, .more_0 = (&strlit_0_I8160649543150574237_marbdjk4t1)}
      ;}
    break;
    case 5:
    {
      nimStrDestroy(X60Qx_12);
      X60Qx_12 = (string_0_sysvq0asl){
        .bytes_0 = 1130589694u, .more_0 = (&strlit_0_I12549307355442489107_marbdjk4t1)}
      ;}
    break;
    case 6:
    {
      nimStrDestroy(X60Qx_12);
      X60Qx_12 = (string_0_sysvq0asl){
        .bytes_0 = 1432579582u, .more_0 = (&strlit_0_I3538386510047344326_marbdjk4t1)}
      ;}
    break;}
  nimStrDestroy(result_36);
  result_36 = X60Qx_12;
  nimStrWasMoved((&X60Qx_12));
  nimStrDestroy(X60Qx_12);
  return result_36;
  nimStrDestroy(X60Qx_12);
  return result_36;}
X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi declineWire_0_run8hsnpi(string_0_sysvq0asl reason_0){
  X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi result_37;
  eQwasmovedQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_37));
  declineNote_0_croph25r5(1, reason_0);
  eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_37));
  result_37 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
    .fld_0 = (WireField_0_run8hsnpi){
      .desc_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .srcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
    , .fld_1 = NIM_FALSE}
  ;
  return result_37;}
X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi describeTypeCore_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_6){
  X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi result_38;
  eQwasmovedQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_38));
  string_0_sysvq0asl srcName_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NU32 esym_0 = ((NU32)0u);
  NifKind_0_nif81dubp1 X60Qx_390 = kind_0_nifb6mq6y1(cur_6);
  if (X60Qx_390 == 4){
    nimStrDestroy(srcName_0);
    NU32 X60Qx_391 = symId_0_nifb6mq6y1(cur_6);
    string_0_sysvq0asl X60Qx_392 = baseNameOf_0_run8hsnpi(X60Qx_391);
    srcName_0 = X60Qx_392;
    NU32 X60Qx_393 = symId_0_nifb6mq6y1(cur_6);
    esym_0 = X60Qx_393;}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_16 = typeDescOf_0_run8hsnpi(cur_6, 0);
  if (td_16 == NIM_NIL){
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_394 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
      .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I13019318966386094724_run8hsnpi)}
    );
    result_38 = X60Qx_394;
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
    nimStrDestroy(srcName_0);
    return result_38;}
  if ((*td_16).d_00.kind_0 == 5){
    string_0_sysvq0asl ptag_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    NifKind_0_nif81dubp1 X60Qx_395 = kind_0_nifb6mq6y1(cur_6);
    if (X60Qx_395 == 11){
      nimStrDestroy(ptag_0);
      string_0_sysvq0asl X60Qx_396 = nodeTag_0_run8hsnpi(cur_6);
      ptag_0 = X60Qx_396;}
    NB8 X60Qx_397 = eqQ_20_sysvq0asl(ptag_0, (string_0_sysvq0asl){
      .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
    );
    if (X60Qx_397){
      Cursor_0_nifb6mq6y1 pc_1 = eQdup_0_nifb6mq6y1(cur_6);
      inc_0_nifb6mq6y1((&pc_1));
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* pd_0 = typeDescOf_0_run8hsnpi(pc_1, 0);
      if (pd_0 == NIM_NIL){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_398 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I4958048190723036074_run8hsnpi)}
        );
        result_38 = X60Qx_398;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
        eQdestroy_0_nifb6mq6y1((&pc_1));
        nimStrDestroy(ptag_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
        nimStrDestroy(srcName_0);
        return result_38;}
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* flat_0 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
      {
        while (NIM_TRUE){
          NB8 X60Qx_399;
          if ((!(flat_0 == NIM_NIL))){
            X60Qx_399 = ((*flat_0).d_00.kind_0 == 13);}
          else {
            X60Qx_399 = NIM_FALSE;}
          if (X60Qx_399){
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qlhs_60 = flat_0;
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_400 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*flat_0).d_00.elem_0);
            flat_0 = X60Qx_400;
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qlhs_60);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      if (flat_0 == NIM_NIL){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_401 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I16235671060003324787_run8hsnpi)}
        );
        result_38 = X60Qx_401;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
        eQdestroy_0_nifb6mq6y1((&pc_1));
        nimStrDestroy(ptag_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
        nimStrDestroy(srcName_0);
        return result_38;}
      switch ((*flat_0).d_00.kind_0){
        case 0:
        case 1:
        case 2:
        case 4:
        case 3:
        case 8:
        case 10:
        case 11:
        case 9:
        {
          }
        break;
        default:
        {
          string_0_sysvq0asl X60Qdesugar_3 = dollarX60Q_AbiKind_0_layptix6a1((*flat_0).d_00.kind_0);
          NI32 X60Qx_402 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I13225935872158492040_run8hsnpi)}
          );
          NI32 X60Qx_403 = len_4_sysvq0asl(X60Qdesugar_3);
          NI32 X60Qx_404 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I3673080887886368090_run8hsnpi)}
          );
          string_0_sysvq0asl X60Qdesugar_4 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_402 + X60Qx_403)) + X60Qx_404)));
          add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
            .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I13225935872158492040_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_4), X60Qdesugar_3);
          add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
            .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I3673080887886368090_run8hsnpi)}
          );
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_405 = declineWire_0_run8hsnpi(X60Qdesugar_4);
          result_38 = X60Qx_405;
          nimStrDestroy(X60Qdesugar_4);
          nimStrDestroy(X60Qdesugar_3);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
          eQdestroy_0_nifb6mq6y1((&pc_1));
          nimStrDestroy(ptag_0);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
          nimStrDestroy(srcName_0);
          return result_38;
          nimStrDestroy(X60Qdesugar_4);
          nimStrDestroy(X60Qdesugar_3);}
        break;}
      string_0_sysvq0asl pn_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NU32 psym_0 = ((NU32)0u);
      NifKind_0_nif81dubp1 X60Qx_406 = kind_0_nifb6mq6y1(pc_1);
      if (X60Qx_406 == 4){
        NU32 X60Qx_407 = symId_0_nifb6mq6y1(pc_1);
        psym_0 = X60Qx_407;
        nimStrDestroy(pn_0);
        string_0_sysvq0asl X60Qx_408 = baseNameOf_0_run8hsnpi(psym_0);
        pn_0 = X60Qx_408;}
      else {
        nimStrDestroy(pn_0);
        string_0_sysvq0asl X60Qx_409 = srcScalarName_0_run8hsnpi(pd_0);
        pn_0 = X60Qx_409;}
      NI32 X60Qx_410 = len_4_sysvq0asl(pn_0);
      if (X60Qx_410 == 0){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_411 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I4342340915346939023_run8hsnpi)}
        );
        result_38 = X60Qx_411;
        nimStrDestroy(pn_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
        eQdestroy_0_nifb6mq6y1((&pc_1));
        nimStrDestroy(ptag_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
        nimStrDestroy(srcName_0);
        return result_38;}
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 psa_0 = sizeAlign_1_layptix6a1(pd_0, 8);
      if (psa_0.fld_0 <= 0){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_412 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I8993670282046711299_run8hsnpi)}
        );
        result_38 = X60Qx_412;
        nimStrDestroy(pn_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
        eQdestroy_0_nifb6mq6y1((&pc_1));
        nimStrDestroy(ptag_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
        nimStrDestroy(srcName_0);
        return result_38;}
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_61 = pd_0;
      eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&pd_0));
      WireField_0_run8hsnpi pf_0 = (WireField_0_run8hsnpi){
        .desc_0 = X60Qtmp_61, .srcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
      ;
      pf_0.isPtrArena_0 = NIM_TRUE;
      string_0_sysvq0asl* X60Qlhs_62 = (&pf_0.srcType_0);
      nimStrDestroy((*X60Qlhs_62));
      string_0_sysvq0asl X60Qx_413 = nimStrDup(pn_0);
      (*X60Qlhs_62) = X60Qx_413;
      pf_0.typeSym_0 = psym_0;
      string_0_sysvq0asl* X60Qlhs_63 = (&pf_0.elemSrcType_0);
      nimStrDestroy((*X60Qlhs_63));
      (*X60Qlhs_63) = pn_0;
      nimStrWasMoved((&pn_0));
      pf_0.elemSize_0 = psa_0.fld_0;
      pf_0.wireSize_0 = 8;
      pf_0.wireAlign_0 = 8;
      WireField_0_run8hsnpi X60Qtmp_64 = pf_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_0));
      result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_64, .fld_1 = NIM_TRUE}
      ;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_0));
      nimStrDestroy(pn_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
      eQdestroy_0_nifb6mq6y1((&pc_1));
      nimStrDestroy(ptag_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_0));
      nimStrDestroy(pn_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
      eQdestroy_0_nifb6mq6y1((&pc_1));}
    NB8 X60Qx_414 = eqQ_20_sysvq0asl(ptag_0, (string_0_sysvq0asl){
      .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
    );
    if (X60Qx_414){
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_65 = td_16;
      eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&td_16));
      WireField_0_run8hsnpi cf_0 = (WireField_0_run8hsnpi){
        .desc_0 = X60Qtmp_65, .srcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
      ;
      cf_0.isForeignPtr_0 = NIM_TRUE;
      string_0_sysvq0asl* X60Qlhs_66 = (&cf_0.srcType_0);
      nimStrDestroy((*X60Qlhs_66));
      (*X60Qlhs_66) = (string_0_sysvq0asl){
        .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
      ;
      cf_0.wireSize_0 = 8;
      cf_0.wireAlign_0 = 8;
      WireField_0_run8hsnpi X60Qtmp_67 = cf_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&cf_0));
      result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_67, .fld_1 = NIM_TRUE}
      ;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&cf_0));
      nimStrDestroy(ptag_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&cf_0));}
    string_0_sysvq0asl X60Qx_13;
    nimStrWasMoved((&X60Qx_13));
    NI32 X60Qx_415 = len_4_sysvq0asl(ptag_0);
    if (0 < X60Qx_415){
      nimStrDestroy(X60Qx_13);
      X60Qx_13 = ptag_0;
      nimStrWasMoved((&ptag_0));}
    else {
      nimStrDestroy(X60Qx_13);
      X60Qx_13 = (string_0_sysvq0asl){
        .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I8793898668013225318_run8hsnpi)}
      ;}
    string_0_sysvq0asl X60Qdesugar_5 = X60Qx_13;
    nimStrWasMoved((&X60Qx_13));
    NI32 X60Qx_416 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1634758654u, .more_0 = (&strlit_0_I4709633162961732303_run8hsnpi)}
    );
    NI32 X60Qx_417 = len_4_sysvq0asl(X60Qdesugar_5);
    NI32 X60Qx_418 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 540682750u, .more_0 = (&strlit_0_I2888973717457040847_run8hsnpi)}
    );
    string_0_sysvq0asl X60Qdesugar_6 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_416 + X60Qx_417)) + X60Qx_418)));
    add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
      .bytes_0 = 1634758654u, .more_0 = (&strlit_0_I4709633162961732303_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_6), X60Qdesugar_5);
    add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
      .bytes_0 = 540682750u, .more_0 = (&strlit_0_I2888973717457040847_run8hsnpi)}
    );
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_419 = declineWire_0_run8hsnpi(X60Qdesugar_6);
    result_38 = X60Qx_419;
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qx_13);
    nimStrDestroy(ptag_0);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
    nimStrDestroy(srcName_0);
    return result_38;
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qx_13);
    nimStrDestroy(ptag_0);}
  if ((*td_16).d_00.kind_0 == 9){
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_2 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*td_16).d_00.elem_0);
    NB8 X60Qx_420;
    if (el_2 == NIM_NIL){
      X60Qx_420 = NIM_TRUE;}
    else {
      X60Qx_420 = ((*td_16).d_00.count_0 <= 0);}
    if (X60Qx_420){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_421 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I13889320805933294264_run8hsnpi)}
      );
      result_38 = X60Qx_421;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    MarshalClass_0_marbdjk4t1 ec_3 = marshalClass_0_marbdjk4t1(el_2);
    NB8 X60Qx_422;
    if (ec_3 == 0){
      X60Qx_422 = NIM_TRUE;}
    else {
      X60Qx_422 = (ec_3 == 1);}
    if ((!X60Qx_422)){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_423 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I16185026956335355254_run8hsnpi)}
      );
      result_38 = X60Qx_423;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    NB8 X60Qx_424;
    if (ec_3 == 1){
      NB8 X60Qx_425 = podHasEnumOrArray_0_run8hsnpi(el_2);
      X60Qx_424 = X60Qx_425;}
    else {
      X60Qx_424 = NIM_FALSE;}
    if (X60Qx_424){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_426 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I10498682809148144310_run8hsnpi)}
      );
      result_38 = X60Qx_426;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi X60Qtmptup_4 = arrayElemNameSym_0_run8hsnpi(cur_6, el_2);
    string_0_sysvq0asl en_0 = X60Qtmptup_4.fld_0;
    nimStrWasMoved((&X60Qtmptup_4.fld_0));
    NU32 ets_0 = X60Qtmptup_4.fld_1;
    NI32 X60Qx_427 = len_4_sysvq0asl(en_0);
    if (X60Qx_427 == 0){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_428 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I15756359906215420366_run8hsnpi)}
      );
      result_38 = X60Qx_428;
      nimStrDestroy(en_0);
      eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_4);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    NB8 X60Qx_429;
    if (ec_3 == 1){
      X60Qx_429 = (((NU32)ets_0) == ((NU32)0u));}
    else {
      X60Qx_429 = NIM_FALSE;}
    if (X60Qx_429){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_430 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I12763724795707366899_run8hsnpi)}
      );
      result_38 = X60Qx_430;
      nimStrDestroy(en_0);
      eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_4);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 esa_0 = sizeAlign_1_layptix6a1(el_2, 8);
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_431 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
    WireField_0_run8hsnpi af_0 = (WireField_0_run8hsnpi){
      .desc_0 = X60Qx_431, .srcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
    ;
    af_0.isArray_0 = NIM_TRUE;
    af_0.arrCount_0 = (*td_16).d_00.count_0;
    af_0.elemTypeSym_0 = ets_0;
    string_0_sysvq0asl* X60Qlhs_68 = (&af_0.elemSrcType_0);
    nimStrDestroy((*X60Qlhs_68));
    string_0_sysvq0asl X60Qx_432 = nimStrDup(en_0);
    (*X60Qlhs_68) = X60Qx_432;
    af_0.elemSize_0 = esa_0.fld_0;
    NI32 X60Qx_14;
    if (0 < esa_0.fld_1){
      X60Qx_14 = esa_0.fld_1;}
    else {
      X60Qx_14 = 1;}
    NI32 X60Qx_433 = align_0_layptix6a1(esa_0.fld_0, X60Qx_14);
    af_0.elemStride_0 = X60Qx_433;
    string_0_sysvq0asl X60Qdesugar_7 = dollarQ_2_sysvq0asl((*td_16).d_00.count_0);
    NI32 X60Qx_434 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I16157109470490228308_red2rogzl)}
    );
    NI32 X60Qx_435 = len_4_sysvq0asl(X60Qdesugar_7);
    NI32 X60Qx_436 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2108418u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_437 = len_4_sysvq0asl(en_0);
    NI32 X60Qx_438 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 23809u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_8 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_434 + X60Qx_435)) + X60Qx_436)) + X60Qx_437)) + X60Qx_438)));
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I16157109470490228308_red2rogzl)}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), X60Qdesugar_7);
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 2108418u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_8), en_0);
    add_2_sysvq0asl((&X60Qdesugar_8), (string_0_sysvq0asl){
      .bytes_0 = 23809u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl* X60Qlhs_69 = (&af_0.srcType_0);
    nimStrDestroy((*X60Qlhs_69));
    (*X60Qlhs_69) = X60Qdesugar_8;
    nimStrWasMoved((&X60Qdesugar_8));
    af_0.wireSize_0 = ((NI32)(af_0.elemStride_0 * (*td_16).d_00.count_0));
    NI32 X60Qx_15;
    if (0 < esa_0.fld_1){
      X60Qx_15 = esa_0.fld_1;}
    else {
      X60Qx_15 = 1;}
    af_0.wireAlign_0 = X60Qx_15;
    WireField_0_run8hsnpi X60Qtmp_70 = af_0;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&af_0));
    result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_70, .fld_1 = NIM_TRUE}
    ;
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qdesugar_7);
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&af_0));
    nimStrDestroy(en_0);
    eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
    nimStrDestroy(srcName_0);
    return result_38;
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qdesugar_7);
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&af_0));
    nimStrDestroy(en_0);
    eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);}
  if ((*td_16).d_00.kind_0 == 6){
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* pl_0 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*td_16).d_00.elem_0);
    NB8 X60Qx_439;
    if (pl_0 == NIM_NIL){
      X60Qx_439 = NIM_TRUE;}
    else {
      NB8 X60Qx_440;
      if ((*pl_0).d_00.kind_0 == 10){
        X60Qx_440 = NIM_TRUE;}
      else {
        X60Qx_440 = ((*pl_0).d_00.kind_0 == 11);}
      X60Qx_439 = (!X60Qx_440);}
    if (X60Qx_439){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_441 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I15672252006839982641_run8hsnpi)}
      );
      result_38 = X60Qx_441;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    Cursor_0_nifb6mq6y1 rc_0 = eQdup_0_nifb6mq6y1(cur_6);
    NB8 X60Qx_121;
    NifKind_0_nif81dubp1 X60Qx_442 = kind_0_nifb6mq6y1(rc_0);
    if ((!(X60Qx_442 == 11))){
      X60Qx_121 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_71 = nodeTag_0_run8hsnpi(rc_0);
      NB8 X60Qx_443 = eqQ_20_sysvq0asl(X60Qtmp_71, (string_0_sysvq0asl){
        .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
      );
      X60Qx_121 = (!X60Qx_443);
      nimStrDestroy(X60Qtmp_71);}
    if (X60Qx_121){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_444 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I11886991017504759357_run8hsnpi)}
      );
      result_38 = X60Qx_444;
      eQdestroy_0_nifb6mq6y1((&rc_0));
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    inc_0_nifb6mq6y1((&rc_0));
    NifKind_0_nif81dubp1 X60Qx_445 = kind_0_nifb6mq6y1(rc_0);
    if ((!(X60Qx_445 == 4))){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_446 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I10876541292033031825_run8hsnpi)}
      );
      result_38 = X60Qx_446;
      eQdestroy_0_nifb6mq6y1((&rc_0));
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    NU32 psym_1 = symId_0_nifb6mq6y1(rc_0);
    string_0_sysvq0asl pn_1 = baseNameOf_0_run8hsnpi(psym_1);
    NB8 X60Qx_447;
    NI32 X60Qx_448 = len_4_sysvq0asl(pn_1);
    if (X60Qx_448 == 0){
      X60Qx_447 = NIM_TRUE;}
    else {
      X60Qx_447 = (((NU32)psym_1) == ((NU32)0u));}
    if (X60Qx_447){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_449 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I5262176531977851534_run8hsnpi)}
      );
      result_38 = X60Qx_449;
      nimStrDestroy(pn_1);
      eQdestroy_0_nifb6mq6y1((&rc_0));
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    NB8 X60Qx_450;
    MarshalClass_0_marbdjk4t1 X60Qx_451 = marshalClass_0_marbdjk4t1(pl_0);
    if (X60Qx_451 == 1){
      NB8 X60Qx_452 = podHasEnumOrArray_0_run8hsnpi(pl_0);
      X60Qx_450 = (!X60Qx_452);}
    else {
      X60Qx_450 = NIM_FALSE;}
    if (X60Qx_450){
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_453 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      WireField_0_run8hsnpi rfld_0 = (WireField_0_run8hsnpi){
        .desc_0 = X60Qx_453, .srcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
      ;
      rfld_0.isRef_0 = NIM_TRUE;
      rfld_0.isPod_0 = NIM_TRUE;
      rfld_0.isVar_0 = NIM_TRUE;
      rfld_0.typeSym_0 = psym_1;
      string_0_sysvq0asl* X60Qlhs_72 = (&rfld_0.srcType_0);
      nimStrDestroy((*X60Qlhs_72));
      (*X60Qlhs_72) = pn_1;
      nimStrWasMoved((&pn_1));
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 psa_1 = sizeAlign_1_layptix6a1(pl_0, 8);
      rfld_0.wireSize_0 = psa_1.fld_0;
      NI32 X60Qx_16;
      if (0 < psa_1.fld_1){
        X60Qx_16 = psa_1.fld_1;}
      else {
        X60Qx_16 = 1;}
      rfld_0.wireAlign_0 = X60Qx_16;
      WireField_0_run8hsnpi X60Qtmp_73 = rfld_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&rfld_0));
      result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_73, .fld_1 = NIM_TRUE}
      ;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&rfld_0));
      nimStrDestroy(pn_1);
      eQdestroy_0_nifb6mq6y1((&rc_0));
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&rfld_0));}
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_74 = pl_0;
    eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&pl_0));
    WireField_0_run8hsnpi afld_0 = (WireField_0_run8hsnpi){
      .desc_0 = X60Qtmp_74, .srcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
    ;
    afld_0.isArenaRef_0 = NIM_TRUE;
    afld_0.typeSym_0 = psym_1;
    string_0_sysvq0asl* X60Qlhs_75 = (&afld_0.srcType_0);
    nimStrDestroy((*X60Qlhs_75));
    (*X60Qlhs_75) = pn_1;
    nimStrWasMoved((&pn_1));
    afld_0.wireSize_0 = 8;
    afld_0.wireAlign_0 = 8;
    WireField_0_run8hsnpi X60Qtmp_76 = afld_0;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&afld_0));
    result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_76, .fld_1 = NIM_TRUE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&afld_0));
    nimStrDestroy(pn_1);
    eQdestroy_0_nifb6mq6y1((&rc_0));
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
    nimStrDestroy(srcName_0);
    return result_38;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&afld_0));
    nimStrDestroy(pn_1);
    eQdestroy_0_nifb6mq6y1((&rc_0));
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);}
  NB8 X60Qx_454 = isArenaPtrAggregate_0_marbdjk4t1(td_16);
  if (X60Qx_454){
    NB8 X60Qx_455;
    NI32 X60Qx_456 = len_4_sysvq0asl(srcName_0);
    if (X60Qx_456 == 0){
      X60Qx_455 = NIM_TRUE;}
    else {
      X60Qx_455 = (((NU32)esym_0) == ((NU32)0u));}
    if (X60Qx_455){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_457 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I10983318047828523597_run8hsnpi)}
      );
      result_38 = X60Qx_457;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_0 = sizeAlign_1_layptix6a1(td_16, 8);
    if (sa_0.fld_0 <= 0){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_458 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I14209940706925738676_run8hsnpi)}
      );
      result_38 = X60Qx_458;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
      nimStrDestroy(srcName_0);
      return result_38;}
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_77 = td_16;
    eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&td_16));
    WireField_0_run8hsnpi pf_1 = (WireField_0_run8hsnpi){
      .desc_0 = X60Qtmp_77, .srcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
    ;
    pf_1.isPod_0 = NIM_TRUE;
    pf_1.isArenaPtr_0 = NIM_TRUE;
    string_0_sysvq0asl* X60Qlhs_78 = (&pf_1.srcType_0);
    nimStrDestroy((*X60Qlhs_78));
    (*X60Qlhs_78) = srcName_0;
    nimStrWasMoved((&srcName_0));
    pf_1.typeSym_0 = esym_0;
    pf_1.wireSize_0 = sa_0.fld_0;
    NI32 X60Qx_17;
    if (0 < sa_0.fld_1){
      X60Qx_17 = sa_0.fld_1;}
    else {
      X60Qx_17 = 1;}
    pf_1.wireAlign_0 = X60Qx_17;
    WireField_0_run8hsnpi X60Qtmp_79 = pf_1;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_1));
    result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_79, .fld_1 = NIM_TRUE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_1));
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
    nimStrDestroy(srcName_0);
    return result_38;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_1));}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_459 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
  WireField_0_run8hsnpi f_8 = (WireField_0_run8hsnpi){
    .desc_0 = X60Qx_459, .srcType_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
  ;
  MarshalClass_0_marbdjk4t1 X60Qx_460 = marshalClass_0_marbdjk4t1(td_16);
  switch (X60Qx_460){
    case 0:
    {
      if ((*td_16).d_00.kind_0 == 8){
        NI32 X60Qx_461 = len_4_sysvq0asl(srcName_0);
        if (X60Qx_461 == 0){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_462 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1869505022u, .more_0 = (&strlit_0_I10048895548644967963_run8hsnpi)}
          );
          result_38 = X60Qx_462;
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
          nimStrDestroy(srcName_0);
          return result_38;}
        f_8.isEnum_0 = NIM_TRUE;
        string_0_sysvq0asl* X60Qlhs_80 = (&f_8.srcType_0);
        nimStrDestroy((*X60Qlhs_80));
        (*X60Qlhs_80) = srcName_0;
        nimStrWasMoved((&srcName_0));
        f_8.enumSym_0 = esym_0;
        f_8.wireSize_0 = 4;
        f_8.wireAlign_0 = 4;}
      else {
        X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_1 = sizeAlign_1_layptix6a1(td_16, 8);
        f_8.wireSize_0 = sa_1.fld_0;
        NI32 X60Qx_18;
        if (0 < sa_1.fld_1){
          X60Qx_18 = sa_1.fld_1;}
        else {
          X60Qx_18 = 1;}
        f_8.wireAlign_0 = X60Qx_18;
        string_0_sysvq0asl X60Qx_19;
        nimStrWasMoved((&X60Qx_19));
        NI32 X60Qx_463 = len_4_sysvq0asl(srcName_0);
        if (0 < X60Qx_463){
          nimStrDestroy(X60Qx_19);
          X60Qx_19 = srcName_0;
          nimStrWasMoved((&srcName_0));}
        else {
          nimStrDestroy(X60Qx_19);
          string_0_sysvq0asl X60Qx_464 = srcScalarName_0_run8hsnpi(td_16);
          X60Qx_19 = X60Qx_464;}
        string_0_sysvq0asl* X60Qlhs_81 = (&f_8.srcType_0);
        nimStrDestroy((*X60Qlhs_81));
        (*X60Qlhs_81) = X60Qx_19;
        nimStrWasMoved((&X60Qx_19));
        NI32 X60Qx_465 = len_4_sysvq0asl(f_8.srcType_0);
        if (X60Qx_465 == 0){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_466 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1633907710u, .more_0 = (&strlit_0_I11975016787032525042_run8hsnpi)}
          );
          result_38 = X60Qx_466;
          nimStrDestroy(X60Qx_19);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
          nimStrDestroy(srcName_0);
          return result_38;}
        nimStrDestroy(X60Qx_19);}
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_38));
      WireField_0_run8hsnpi X60Qtmp_82 = f_8;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
      result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_82, .fld_1 = NIM_TRUE}
      ;}
    break;
    case 1:
    {
      NB8 X60Qx_467 = podHasEnumOrArray_0_run8hsnpi(td_16);
      if (X60Qx_467){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_468 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1146048766u, .more_0 = (&strlit_0_I2580450898984919640_run8hsnpi)}
        );
        result_38 = X60Qx_468;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
        nimStrDestroy(srcName_0);
        return result_38;}
      string_0_sysvq0asl sname_0 = srcName_0;
      nimStrWasMoved((&srcName_0));
      NI32 X60Qx_469 = len_4_sysvq0asl(sname_0);
      if (X60Qx_469 == 0){
        if ((*td_16).d_00.kind_0 == 11){
          string_0_sysvq0asl s_10 = (string_0_sysvq0asl){
            .bytes_0 = 10241u, .more_0 = NIM_NIL}
          ;
          NI32 i_4 = 0;
          NB8 okAll_0 = NIM_TRUE;
          {
            while (NIM_TRUE){
              NI32 X60Qx_470 = len_3_I5m68tr1_aow7lb5cq1((*td_16).d_00.fields_0);
              if (i_4 < X60Qx_470){
                if (0 < i_4){
                  add_2_sysvq0asl((&s_10), (string_0_sysvq0asl){
                    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                  );}
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_471 = getQ_7_I45w7c91_aow7lb5cq1((*td_16).d_00.fields_0, i_4);
                string_0_sysvq0asl n_6 = srcScalarName_0_run8hsnpi((*X60Qx_471));
                NI32 X60Qx_472 = len_4_sysvq0asl(n_6);
                if (X60Qx_472 == 0){
                  okAll_0 = NIM_FALSE;
                  nimStrDestroy(n_6);
                  goto whileStmtLabel_1;}
                add_2_sysvq0asl((&s_10), n_6);
                inc_1_I6wjjge_aow2h993l1((&i_4));
                nimStrDestroy(n_6);}
              else {
                break;}}}
          whileStmtLabel_1: ;
          NB8 X60Qx_473;
          if (okAll_0){
            X60Qx_473 = (0 < (*td_16).d_00.fields_0.len_0);}
          else {
            X60Qx_473 = NIM_FALSE;}
          if (X60Qx_473){
            add_2_sysvq0asl((&s_10), (string_0_sysvq0asl){
              .bytes_0 = 10497u, .more_0 = NIM_NIL}
            );
            nimStrDestroy(sname_0);
            sname_0 = s_10;
            nimStrWasMoved((&s_10));}
          nimStrDestroy(s_10);}
        NI32 X60Qx_474 = len_4_sysvq0asl(sname_0);
        if (X60Qx_474 == 0){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_475 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1869505022u, .more_0 = (&strlit_0_I4239904353946109281_run8hsnpi)}
          );
          result_38 = X60Qx_475;
          nimStrDestroy(sname_0);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
          nimStrDestroy(srcName_0);
          return result_38;}}
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_2 = sizeAlign_1_layptix6a1(td_16, 8);
      f_8.isPod_0 = NIM_TRUE;
      string_0_sysvq0asl* X60Qlhs_83 = (&f_8.srcType_0);
      nimStrDestroy((*X60Qlhs_83));
      (*X60Qlhs_83) = sname_0;
      nimStrWasMoved((&sname_0));
      f_8.typeSym_0 = esym_0;
      f_8.wireSize_0 = sa_2.fld_0;
      NI32 X60Qx_20;
      if (0 < sa_2.fld_1){
        X60Qx_20 = sa_2.fld_1;}
      else {
        X60Qx_20 = 1;}
      f_8.wireAlign_0 = X60Qx_20;
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_38));
      WireField_0_run8hsnpi X60Qtmp_84 = f_8;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
      result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_84, .fld_1 = NIM_TRUE}
      ;
      nimStrDestroy(sname_0);}
    break;
    case 2:
    {
      f_8.isString_0 = NIM_TRUE;
      string_0_sysvq0asl* X60Qlhs_85 = (&f_8.srcType_0);
      nimStrDestroy((*X60Qlhs_85));
      (*X60Qlhs_85) = (string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
      ;
      f_8.wireSize_0 = 0;
      f_8.wireAlign_0 = 8;
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_38));
      WireField_0_run8hsnpi X60Qtmp_86 = f_8;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
      result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_86, .fld_1 = NIM_TRUE}
      ;}
    break;
    case 3:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_3 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*td_16).d_00.elem_0);
      if (el_3 == NIM_NIL){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_476 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I4762276063258106479_run8hsnpi)}
        );
        result_38 = X60Qx_476;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
        nimStrDestroy(srcName_0);
        return result_38;}
      MarshalClass_0_marbdjk4t1 ec_4 = marshalClass_0_marbdjk4t1(el_3);
      NB8 X60Qx_477;
      if (ec_4 == 0){
        X60Qx_477 = NIM_TRUE;}
      else {
        X60Qx_477 = (ec_4 == 1);}
      if (X60Qx_477){
        NB8 X60Qx_478;
        if (ec_4 == 1){
          NB8 X60Qx_479 = podHasEnumOrArray_0_run8hsnpi(el_3);
          X60Qx_478 = X60Qx_479;}
        else {
          X60Qx_478 = NIM_FALSE;}
        if (X60Qx_478){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_480 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I17656025713398431513_run8hsnpi)}
          );
          result_38 = X60Qx_480;
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
          nimStrDestroy(srcName_0);
          return result_38;}
        X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi X60Qtmptup_5 = seqElemNameSym_0_run8hsnpi(cur_6, el_3);
        string_0_sysvq0asl en_1 = X60Qtmptup_5.fld_0;
        nimStrWasMoved((&X60Qtmptup_5.fld_0));
        NU32 ets_1 = X60Qtmptup_5.fld_1;
        NI32 X60Qx_481 = len_4_sysvq0asl(en_1);
        if (X60Qx_481 == 0){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_482 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I18020228616198309266_run8hsnpi)}
          );
          result_38 = X60Qx_482;
          nimStrDestroy(en_1);
          eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_5);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
          nimStrDestroy(srcName_0);
          return result_38;}
        NB8 X60Qx_483;
        if (ec_4 == 1){
          X60Qx_483 = (((NU32)ets_1) == ((NU32)0u));}
        else {
          X60Qx_483 = NIM_FALSE;}
        if (X60Qx_483){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_484 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I8778022564813250551_run8hsnpi)}
          );
          result_38 = X60Qx_484;
          nimStrDestroy(en_1);
          eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_5);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
          nimStrDestroy(srcName_0);
          return result_38;}
        X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 esa_1 = sizeAlign_1_layptix6a1(el_3, 8);
        f_8.elemTypeSym_0 = ets_1;
        f_8.isSeq_0 = NIM_TRUE;
        NI32 X60Qx_485 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
        );
        NI32 X60Qx_486 = len_4_sysvq0asl(en_1);
        NI32 X60Qx_487 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 23809u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_485 + X60Qx_486)) + X60Qx_487)));
        add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
          .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
        );
        add_2_sysvq0asl((&X60Qdesugar_9), en_1);
        add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
          .bytes_0 = 23809u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl* X60Qlhs_87 = (&f_8.srcType_0);
        nimStrDestroy((*X60Qlhs_87));
        (*X60Qlhs_87) = X60Qdesugar_9;
        nimStrWasMoved((&X60Qdesugar_9));
        string_0_sysvq0asl* X60Qlhs_88 = (&f_8.elemSrcType_0);
        nimStrDestroy((*X60Qlhs_88));
        (*X60Qlhs_88) = en_1;
        nimStrWasMoved((&en_1));
        f_8.elemSize_0 = esa_1.fld_0;
        NI32 X60Qx_21;
        if (0 < esa_1.fld_1){
          X60Qx_21 = esa_1.fld_1;}
        else {
          X60Qx_21 = 1;}
        NI32 X60Qx_488 = align_0_layptix6a1(esa_1.fld_0, X60Qx_21);
        f_8.elemStride_0 = X60Qx_488;
        f_8.wireSize_0 = 0;
        f_8.wireAlign_0 = 8;
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_38));
        WireField_0_run8hsnpi X60Qtmp_89 = f_8;
        eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
          .fld_0 = X60Qtmp_89, .fld_1 = NIM_TRUE}
        ;
        nimStrDestroy(X60Qdesugar_9);
        nimStrDestroy(en_1);
        eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_5);}
      else {
        NB8 X60Qx_489;
        if (ec_4 == 2){
          X60Qx_489 = NIM_TRUE;}
        else {
          X60Qx_489 = (ec_4 == 3);}
        if (X60Qx_489){
          X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi X60Qtmptup_6 = seqElemCursor_0_run8hsnpi(cur_6);
          Cursor_0_nifb6mq6y1 ecur_0 = X60Qtmptup_6.fld_0;
          eQwasMoved_0_nifb6mq6y1((&X60Qtmptup_6.fld_0));
          NB8 cok_0 = X60Qtmptup_6.fld_1;
          if ((!cok_0)){
            string_0_sysvq0asl X60Qtmp_91 = blockerReason_0_croph25r5();
            string_0_sysvq0asl X60Qtmp_90 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I2962236368520039866_run8hsnpi)}
            , X60Qtmp_91);
            X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_490 = declineWire_0_run8hsnpi(X60Qtmp_90);
            result_38 = X60Qx_490;
            nimStrDestroy(X60Qtmp_90);
            nimStrDestroy(X60Qtmp_91);
            eQdestroy_0_nifb6mq6y1((&ecur_0));
            eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_6);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
            nimStrDestroy(srcName_0);
            return result_38;
            nimStrDestroy(X60Qtmp_90);
            nimStrDestroy(X60Qtmp_91);}
          X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 X60Qtmptup_7 = varElemExpr_0_run8hsnpi(ecur_0, el_3);
          string_0_sysvq0asl expr_0 = X60Qtmptup_7.fld_0;
          nimStrWasMoved((&X60Qtmptup_7.fld_0));
          NB8 eok_0 = X60Qtmptup_7.fld_1;
          if ((!eok_0)){
            string_0_sysvq0asl X60Qtmp_93 = blockerReason_0_croph25r5();
            string_0_sysvq0asl X60Qtmp_92 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I2962236368520039866_run8hsnpi)}
            , X60Qtmp_93);
            X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_491 = declineWire_0_run8hsnpi(X60Qtmp_92);
            result_38 = X60Qx_491;
            nimStrDestroy(X60Qtmp_92);
            nimStrDestroy(X60Qtmp_93);
            nimStrDestroy(expr_0);
            eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_7);
            eQdestroy_0_nifb6mq6y1((&ecur_0));
            eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_6);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
            nimStrDestroy(srcName_0);
            return result_38;
            nimStrDestroy(X60Qtmp_92);
            nimStrDestroy(X60Qtmp_93);}
          f_8.isSeq_0 = NIM_TRUE;
          f_8.elemVarLen_0 = NIM_TRUE;
          NI32 X60Qx_492 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
          );
          NI32 X60Qx_493 = len_4_sysvq0asl(expr_0);
          NI32 X60Qx_494 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_10 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_492 + X60Qx_493)) + X60Qx_494)));
          add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_10), expr_0);
          add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl* X60Qlhs_94 = (&f_8.srcType_0);
          nimStrDestroy((*X60Qlhs_94));
          (*X60Qlhs_94) = X60Qdesugar_10;
          nimStrWasMoved((&X60Qdesugar_10));
          string_0_sysvq0asl* X60Qlhs_95 = (&f_8.elemSrcType_0);
          nimStrDestroy((*X60Qlhs_95));
          (*X60Qlhs_95) = expr_0;
          nimStrWasMoved((&expr_0));
          string_0_sysvq0asl* X60Qlhs_96 = (&f_8.elemLeafName_0);
          nimStrDestroy((*X60Qlhs_96));
          string_0_sysvq0asl X60Qx_495 = leafScalarName_0_run8hsnpi(el_3);
          (*X60Qlhs_96) = X60Qx_495;
          f_8.wireSize_0 = 0;
          f_8.wireAlign_0 = 8;
          eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_38));
          WireField_0_run8hsnpi X60Qtmp_97 = f_8;
          eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
            .fld_0 = X60Qtmp_97, .fld_1 = NIM_TRUE}
          ;
          nimStrDestroy(X60Qdesugar_10);
          nimStrDestroy(expr_0);
          eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_7);
          eQdestroy_0_nifb6mq6y1((&ecur_0));
          eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_6);}
        else {
          NB8 X60Qx_496;
          if ((*el_3).d_00.kind_0 == 10){
            X60Qx_496 = NIM_TRUE;}
          else {
            X60Qx_496 = ((*el_3).d_00.kind_0 == 11);}
          if (X60Qx_496){
            NU32 X60Qx_497 = seqElemSymOf_0_run8hsnpi(esym_0);
            if (((NU32)X60Qx_497) == ((NU32)0u)){
              string_0_sysvq0asl X60Qdesugar_11 = abiKindName_0_run8hsnpi(el_3);
              NI32 X60Qx_498 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I14789285714436344509_run8hsnpi)}
              );
              NI32 X60Qx_499 = len_4_sysvq0asl(X60Qdesugar_11);
              NI32 X60Qx_500 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1752637694u, .more_0 = (&strlit_0_I14207751904824393164_run8hsnpi)}
              );
              NI32 X60Qx_501 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 544434686u, .more_0 = (&strlit_0_I9036228806849239375_run8hsnpi)}
              );
              NI32 X60Qx_502 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1869117438u, .more_0 = (&strlit_0_I2343043800903051371_run8hsnpi)}
              );
              string_0_sysvq0asl X60Qdesugar_12 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_498 + X60Qx_499)) + X60Qx_500)) + X60Qx_501)) + X60Qx_502)));
              add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
                .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I14789285714436344509_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_12), X60Qdesugar_11);
              add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
                .bytes_0 = 1752637694u, .more_0 = (&strlit_0_I14207751904824393164_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
                .bytes_0 = 544434686u, .more_0 = (&strlit_0_I9036228806849239375_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_12), (string_0_sysvq0asl){
                .bytes_0 = 1869117438u, .more_0 = (&strlit_0_I2343043800903051371_run8hsnpi)}
              );
              X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_503 = declineWire_0_run8hsnpi(X60Qdesugar_12);
              result_38 = X60Qx_503;
              nimStrDestroy(X60Qdesugar_12);
              nimStrDestroy(X60Qdesugar_11);
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
              eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
              nimStrDestroy(srcName_0);
              return result_38;
              nimStrDestroy(X60Qdesugar_12);
              nimStrDestroy(X60Qdesugar_11);}
            NB8 X60Qx_504 = compositeOk_0_run8hsnpi(td_16, 0, esym_0);
            if ((!X60Qx_504)){
              string_0_sysvq0asl X60Qdesugar_13 = abiKindName_0_run8hsnpi(el_3);
              string_0_sysvq0asl X60Qdesugar_14 = marshalClassName_0_run8hsnpi(el_3);
              NI32 X60Qx_505 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I17842927025719761_run8hsnpi)}
              );
              NI32 X60Qx_506 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I2511330594188339324_run8hsnpi)}
              );
              NI32 X60Qx_507 = len_4_sysvq0asl(X60Qdesugar_13);
              NI32 X60Qx_508 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 12033u, .more_0 = NIM_NIL}
              );
              NI32 X60Qx_509 = len_4_sysvq0asl(X60Qdesugar_14);
              NI32 X60Qx_510 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 23809u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_15 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_505 + X60Qx_506)) + X60Qx_507)) + X60Qx_508)) + X60Qx_509)) + X60Qx_510)));
              add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
                .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I17842927025719761_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
                .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I2511330594188339324_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_13);
              add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
                .bytes_0 = 12033u, .more_0 = NIM_NIL}
              );
              add_2_sysvq0asl((&X60Qdesugar_15), X60Qdesugar_14);
              add_2_sysvq0asl((&X60Qdesugar_15), (string_0_sysvq0asl){
                .bytes_0 = 23809u, .more_0 = NIM_NIL}
              );
              X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_511 = declineWire_0_run8hsnpi(X60Qdesugar_15);
              result_38 = X60Qx_511;
              nimStrDestroy(X60Qdesugar_15);
              nimStrDestroy(X60Qdesugar_14);
              nimStrDestroy(X60Qdesugar_13);
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
              eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
              nimStrDestroy(srcName_0);
              return result_38;
              nimStrDestroy(X60Qdesugar_15);
              nimStrDestroy(X60Qdesugar_14);
              nimStrDestroy(X60Qdesugar_13);}
            f_8.isComposite_0 = NIM_TRUE;
            string_0_sysvq0asl X60Qx_22;
            nimStrWasMoved((&X60Qx_22));
            NI32 X60Qx_512 = len_4_sysvq0asl(srcName_0);
            if (0 < X60Qx_512){
              nimStrDestroy(X60Qx_22);
              X60Qx_22 = srcName_0;
              nimStrWasMoved((&srcName_0));}
            else {
              NU32 X60Qx_513 = seqElemSymOf_0_run8hsnpi(esym_0);
              string_0_sysvq0asl X60Qdesugar_16 = baseNameOf_0_run8hsnpi(X60Qx_513);
              NI32 X60Qx_514 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
              );
              NI32 X60Qx_515 = len_4_sysvq0asl(X60Qdesugar_16);
              NI32 X60Qx_516 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 23809u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_17 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_514 + X60Qx_515)) + X60Qx_516)));
              add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
                .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_17), X60Qdesugar_16);
              add_2_sysvq0asl((&X60Qdesugar_17), (string_0_sysvq0asl){
                .bytes_0 = 23809u, .more_0 = NIM_NIL}
              );
              nimStrDestroy(X60Qx_22);
              X60Qx_22 = X60Qdesugar_17;
              nimStrWasMoved((&X60Qdesugar_17));
              nimStrDestroy(X60Qdesugar_17);
              nimStrDestroy(X60Qdesugar_16);}
            string_0_sysvq0asl* X60Qlhs_98 = (&f_8.srcType_0);
            nimStrDestroy((*X60Qlhs_98));
            (*X60Qlhs_98) = X60Qx_22;
            nimStrWasMoved((&X60Qx_22));
            f_8.typeSym_0 = esym_0;
            f_8.wireSize_0 = 0;
            f_8.wireAlign_0 = 8;
            eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_38));
            WireField_0_run8hsnpi X60Qtmp_99 = f_8;
            eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
            result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
              .fld_0 = X60Qtmp_99, .fld_1 = NIM_TRUE}
            ;
            nimStrDestroy(X60Qx_22);}
          else {
            string_0_sysvq0asl X60Qdesugar_18 = abiKindName_0_run8hsnpi(el_3);
            string_0_sysvq0asl X60Qdesugar_19 = marshalClassName_0_run8hsnpi(el_3);
            NI32 X60Qx_517 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I95191463816654317_run8hsnpi)}
            );
            NI32 X60Qx_518 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I2511330594188339324_run8hsnpi)}
            );
            NI32 X60Qx_519 = len_4_sysvq0asl(X60Qdesugar_18);
            NI32 X60Qx_520 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 12033u, .more_0 = NIM_NIL}
            );
            NI32 X60Qx_521 = len_4_sysvq0asl(X60Qdesugar_19);
            NI32 X60Qx_522 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 23809u, .more_0 = NIM_NIL}
            );
            string_0_sysvq0asl X60Qdesugar_20 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_517 + X60Qx_518)) + X60Qx_519)) + X60Qx_520)) + X60Qx_521)) + X60Qx_522)));
            add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
              .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I95191463816654317_run8hsnpi)}
            );
            add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
              .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I2511330594188339324_run8hsnpi)}
            );
            add_2_sysvq0asl((&X60Qdesugar_20), X60Qdesugar_18);
            add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
              .bytes_0 = 12033u, .more_0 = NIM_NIL}
            );
            add_2_sysvq0asl((&X60Qdesugar_20), X60Qdesugar_19);
            add_2_sysvq0asl((&X60Qdesugar_20), (string_0_sysvq0asl){
              .bytes_0 = 23809u, .more_0 = NIM_NIL}
            );
            X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_523 = declineWire_0_run8hsnpi(X60Qdesugar_20);
            result_38 = X60Qx_523;
            nimStrDestroy(X60Qdesugar_20);
            nimStrDestroy(X60Qdesugar_19);
            nimStrDestroy(X60Qdesugar_18);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
            nimStrDestroy(srcName_0);
            return result_38;
            nimStrDestroy(X60Qdesugar_20);
            nimStrDestroy(X60Qdesugar_19);
            nimStrDestroy(X60Qdesugar_18);}}}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);}
    break;
    default:
    {
      NB8 X60Qx_524;
      NB8 X60Qx_525;
      NB8 X60Qx_526;
      NB8 X60Qx_527;
      if ((*td_16).d_00.kind_0 == 10){
        X60Qx_527 = NIM_TRUE;}
      else {
        X60Qx_527 = ((*td_16).d_00.kind_0 == 11);}
      if (X60Qx_527){
        X60Qx_526 = (!(*td_16).d_00.incomplete_0);}
      else {
        X60Qx_526 = NIM_FALSE;}
      if (X60Qx_526){
        X60Qx_525 = (!(*td_16).d_00.union_0);}
      else {
        X60Qx_525 = NIM_FALSE;}
      if (X60Qx_525){
        NB8 X60Qx_528 = compositeOk_0_run8hsnpi(td_16, 0, esym_0);
        X60Qx_524 = X60Qx_528;}
      else {
        X60Qx_524 = NIM_FALSE;}
      if (X60Qx_524){
        NB8 X60Qx_529;
        NB8 X60Qx_530 = eqQ_0_nifh7u8pu1(esym_0, ((NU32)0u));
        if (X60Qx_530){
          X60Qx_529 = ((*td_16).d_00.kind_0 == 10);}
        else {
          X60Qx_529 = NIM_FALSE;}
        if (X60Qx_529){
          NI32 X60Qx_531 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1851876350u, .more_0 = (&strlit_0_I3480347692445760496_run8hsnpi)}
          );
          NI32 X60Qx_532 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1970234366u, .more_0 = (&strlit_0_I8515203893767693394_run8hsnpi)}
          );
          NI32 X60Qx_533 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1869117438u, .more_0 = (&strlit_0_I4435949299172777945_run8hsnpi)}
          );
          NI32 X60Qx_534 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1802071294u, .more_0 = (&strlit_0_I9019415731558934837_run8hsnpi)}
          );
          string_0_sysvq0asl X60Qdesugar_21 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_531 + X60Qx_532)) + X60Qx_533)) + X60Qx_534)));
          add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
            .bytes_0 = 1851876350u, .more_0 = (&strlit_0_I3480347692445760496_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
            .bytes_0 = 1970234366u, .more_0 = (&strlit_0_I8515203893767693394_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
            .bytes_0 = 1869117438u, .more_0 = (&strlit_0_I4435949299172777945_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
            .bytes_0 = 1802071294u, .more_0 = (&strlit_0_I9019415731558934837_run8hsnpi)}
          );
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_535 = declineWire_0_run8hsnpi(X60Qdesugar_21);
          result_38 = X60Qx_535;
          nimStrDestroy(X60Qdesugar_21);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
          nimStrDestroy(srcName_0);
          return result_38;
          nimStrDestroy(X60Qdesugar_21);}
        f_8.isComposite_0 = NIM_TRUE;
        string_0_sysvq0asl X60Qx_23;
        nimStrWasMoved((&X60Qx_23));
        NI32 X60Qx_536 = len_4_sysvq0asl(srcName_0);
        if (0 < X60Qx_536){
          nimStrDestroy(X60Qx_23);
          X60Qx_23 = srcName_0;
          nimStrWasMoved((&srcName_0));}
        else {
          nimStrDestroy(X60Qx_23);
          X60Qx_23 = (string_0_sysvq0asl){
            .bytes_0 = 1734425854u, .more_0 = (&strlit_0_I15413645776922620897_run8hsnpi)}
          ;}
        string_0_sysvq0asl* X60Qlhs_100 = (&f_8.srcType_0);
        nimStrDestroy((*X60Qlhs_100));
        (*X60Qlhs_100) = X60Qx_23;
        nimStrWasMoved((&X60Qx_23));
        f_8.typeSym_0 = esym_0;
        f_8.wireSize_0 = 0;
        f_8.wireAlign_0 = 8;
        WireField_0_run8hsnpi X60Qtmp_101 = f_8;
        eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        result_38 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
          .fld_0 = X60Qtmp_101, .fld_1 = NIM_TRUE}
        ;
        nimStrDestroy(X60Qx_23);
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
        nimStrDestroy(srcName_0);
        return result_38;
        nimStrDestroy(X60Qx_23);}
      string_0_sysvq0asl X60Qx_24;
      nimStrWasMoved((&X60Qx_24));
      NI32 X60Qx_537 = len_4_sysvq0asl(srcName_0);
      if (0 < X60Qx_537){
        nimStrDestroy(X60Qx_24);
        X60Qx_24 = srcName_0;
        nimStrWasMoved((&srcName_0));}
      else {
        nimStrDestroy(X60Qx_24);
        X60Qx_24 = (string_0_sysvq0asl){
          .bytes_0 = 1851866366u, .more_0 = (&strlit_0_I409803864855967452_obs4v9ato1)}
        ;}
      string_0_sysvq0asl X60Qdesugar_22 = X60Qx_24;
      nimStrWasMoved((&X60Qx_24));
      string_0_sysvq0asl X60Qdesugar_23 = abiKindName_0_run8hsnpi(td_16);
      string_0_sysvq0asl X60Qdesugar_24 = marshalClassName_0_run8hsnpi(td_16);
      string_0_sysvq0asl X60Qx_25;
      nimStrWasMoved((&X60Qx_25));
      NB8 X60Qx_538;
      if ((*td_16).d_00.kind_0 == 10){
        X60Qx_538 = NIM_TRUE;}
      else {
        X60Qx_538 = ((*td_16).d_00.kind_0 == 11);}
      if (X60Qx_538){
        nimStrDestroy(X60Qx_25);
        string_0_sysvq0asl X60Qx_539 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I16798826875811747463_run8hsnpi)}
        , (string_0_sysvq0asl){
          .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I5244465630440985265_run8hsnpi)}
        );
        X60Qx_25 = X60Qx_539;}
      else {
        if ((*td_16).d_00.kind_0 == 6){
          nimStrDestroy(X60Qx_25);
          X60Qx_25 = (string_0_sysvq0asl){
            .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I14538563795054532983_run8hsnpi)}
          ;}
        else {
          if ((*td_16).d_00.kind_0 == 7){
            nimStrDestroy(X60Qx_25);
            X60Qx_25 = (string_0_sysvq0asl){
              .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I7336782688302392152_run8hsnpi)}
            ;}
          else {
            nimStrDestroy(X60Qx_25);
            X60Qx_25 = (string_0_sysvq0asl){
              .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I9738203171686931162_run8hsnpi)}
            ;}}}
      string_0_sysvq0asl X60Qdesugar_25 = X60Qx_25;
      nimStrWasMoved((&X60Qx_25));
      NI32 X60Qx_540 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1851876350u, .more_0 = (&strlit_0_I7830412320232756549_run8hsnpi)}
      );
      NI32 X60Qx_541 = len_4_sysvq0asl(X60Qdesugar_22);
      NI32 X60Qx_542 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1936269566u, .more_0 = (&strlit_0_I15938467040282102084_run8hsnpi)}
      );
      NI32 X60Qx_543 = len_4_sysvq0asl(X60Qdesugar_23);
      NI32 X60Qx_544 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 12033u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_545 = len_4_sysvq0asl(X60Qdesugar_24);
      NI32 X60Qx_546 = len_4_sysvq0asl(X60Qdesugar_25);
      string_0_sysvq0asl X60Qdesugar_26 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_540 + X60Qx_541)) + X60Qx_542)) + X60Qx_543)) + X60Qx_544)) + X60Qx_545)) + X60Qx_546)));
      add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
        .bytes_0 = 1851876350u, .more_0 = (&strlit_0_I7830412320232756549_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_22);
      add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
        .bytes_0 = 1936269566u, .more_0 = (&strlit_0_I15938467040282102084_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_23);
      add_2_sysvq0asl((&X60Qdesugar_26), (string_0_sysvq0asl){
        .bytes_0 = 12033u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_24);
      add_2_sysvq0asl((&X60Qdesugar_26), X60Qdesugar_25);
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_38));
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_547 = declineWire_0_run8hsnpi(X60Qdesugar_26);
      result_38 = X60Qx_547;
      nimStrDestroy(X60Qdesugar_26);
      nimStrDestroy(X60Qdesugar_25);
      nimStrDestroy(X60Qx_25);
      nimStrDestroy(X60Qdesugar_24);
      nimStrDestroy(X60Qdesugar_23);
      nimStrDestroy(X60Qdesugar_22);
      nimStrDestroy(X60Qx_24);}
    break;}
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
  nimStrDestroy(srcName_0);
  return result_38;
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_16);
  nimStrDestroy(srcName_0);
  return result_38;}
NB8 arrayWritebackSafe_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_0){
  NB8 result_39;
  if (el_0 == NIM_NIL){
    return NIM_FALSE;}
  switch ((*el_0).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 4:
    case 3:
    {
      result_39 = NIM_TRUE;}
    break;
    case 13:
    {
      NB8 X60Qx_548 = arrayWritebackSafe_0_run8hsnpi((*el_0).d_00.elem_0);
      result_39 = X60Qx_548;}
    break;
    default:
    {
      result_39 = NIM_FALSE;}
    break;}
  return result_39;}
X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi describeType_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_7){
  X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi result_40;
  eQwasmovedQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_40));
  Cursor_0_nifb6mq6y1 c_2 = eQdup_0_nifb6mq6y1(cur_7);
  NB8 wantVar_0 = NIM_FALSE;
  NB8 wantSink_0 = NIM_FALSE;
  NB8 X60Qx_122;
  NifKind_0_nif81dubp1 X60Qx_549 = kind_0_nifb6mq6y1(c_2);
  if (X60Qx_549 == 11){
    NB8 X60Qx_123;
    string_0_sysvq0asl X60Qtmp_102 = nodeTag_0_run8hsnpi(c_2);
    NB8 X60Qx_550 = eqQ_20_sysvq0asl(X60Qtmp_102, (string_0_sysvq0asl){
      .bytes_0 = 1953852675u, .more_0 = NIM_NIL}
    );
    if (X60Qx_550){
      X60Qx_123 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_103 = nodeTag_0_run8hsnpi(c_2);
      NB8 X60Qx_551 = eqQ_20_sysvq0asl(X60Qtmp_103, (string_0_sysvq0asl){
        .bytes_0 = 1953853187u, .more_0 = NIM_NIL}
      );
      X60Qx_123 = X60Qx_551;
      nimStrDestroy(X60Qtmp_103);}
    X60Qx_122 = X60Qx_123;
    nimStrDestroy(X60Qtmp_102);}
  else {
    X60Qx_122 = NIM_FALSE;}
  if (X60Qx_122){
    wantVar_0 = NIM_TRUE;
    inc_0_nifb6mq6y1((&c_2));}
  else {
    NB8 X60Qx_124;
    NifKind_0_nif81dubp1 X60Qx_552 = kind_0_nifb6mq6y1(c_2);
    if (X60Qx_552 == 11){
      string_0_sysvq0asl X60Qtmp_104 = nodeTag_0_run8hsnpi(c_2);
      NB8 X60Qx_553 = eqQ_20_sysvq0asl(X60Qtmp_104, (string_0_sysvq0asl){
        .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I5595596763809202512_nim30udrv)}
      );
      X60Qx_124 = X60Qx_553;
      nimStrDestroy(X60Qtmp_104);}
    else {
      X60Qx_124 = NIM_FALSE;}
    if (X60Qx_124){
      wantSink_0 = NIM_TRUE;}}
  X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qtmptup_8 = describeTypeCore_0_run8hsnpi(c_2);
  WireField_0_run8hsnpi f_9 = X60Qtmptup_8.fld_0;
  eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60Qtmptup_8.fld_0));
  NB8 ok_3 = X60Qtmptup_8.fld_1;
  if ((!ok_3)){
    WireField_0_run8hsnpi X60Qtmp_105 = f_9;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    result_40 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_105, .fld_1 = NIM_FALSE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_40;}
  if ((!wantVar_0)){
    if (wantSink_0){
      WireField_0_run8hsnpi fs_0 = f_9;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
      fs_0.isSink_0 = NIM_TRUE;
      WireField_0_run8hsnpi X60Qtmp_106 = fs_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fs_0));
      result_40 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_106, .fld_1 = NIM_TRUE}
      ;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fs_0));
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
      eQdestroy_0_nifb6mq6y1((&c_2));
      return result_40;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fs_0));}
    WireField_0_run8hsnpi X60Qtmp_107 = f_9;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    result_40 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_107, .fld_1 = NIM_TRUE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_40;}
  if (f_9.isForeignPtr_0){
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_554 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I7431751303130250076_run8hsnpi)}
    );
    result_40 = X60Qx_554;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_40;}
  if (f_9.isPtrArena_0){
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_555 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I275891954373591862_run8hsnpi)}
    );
    result_40 = X60Qx_555;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_40;}
  NB8 X60Qx_556;
  NB8 X60Qx_557;
  NB8 X60Qx_558;
  NB8 X60Qx_559;
  NB8 X60Qx_560;
  if ((!f_9.isString_0)){
    X60Qx_560 = (!f_9.isSeq_0);}
  else {
    X60Qx_560 = NIM_FALSE;}
  if (X60Qx_560){
    X60Qx_559 = (!f_9.isArray_0);}
  else {
    X60Qx_559 = NIM_FALSE;}
  if (X60Qx_559){
    X60Qx_558 = (!f_9.isEnum_0);}
  else {
    X60Qx_558 = NIM_FALSE;}
  if (X60Qx_558){
    X60Qx_557 = (!f_9.isPod_0);}
  else {
    X60Qx_557 = NIM_FALSE;}
  if (X60Qx_557){
    X60Qx_556 = (0 < f_9.wireSize_0);}
  else {
    X60Qx_556 = NIM_FALSE;}
  NB8 scalarLeaf_0 = X60Qx_556;
  if (f_9.isArray_0){
    NB8 X60Qx_561;
    if (f_9.desc_0 == NIM_NIL){
      X60Qx_561 = NIM_TRUE;}
    else {
      NB8 X60Qx_562 = arrayWritebackSafe_0_run8hsnpi((*f_9.desc_0).d_00.elem_0);
      X60Qx_561 = (!X60Qx_562);}
    if (X60Qx_561){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_563 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I138105002306121085_run8hsnpi)}
      );
      result_40 = X60Qx_563;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
      eQdestroy_0_nifb6mq6y1((&c_2));
      return result_40;}
    NB8 X60Qx_564;
    NB8 X60Qx_565;
    NB8 X60Qx_566;
    if (f_9.arrCount_0 <= 0){
      X60Qx_566 = NIM_TRUE;}
    else {
      X60Qx_566 = (f_9.elemSize_0 <= 0);}
    if (X60Qx_566){
      X60Qx_565 = NIM_TRUE;}
    else {
      X60Qx_565 = (f_9.elemStride_0 < f_9.elemSize_0);}
    if (X60Qx_565){
      X60Qx_564 = NIM_TRUE;}
    else {
      X60Qx_564 = (f_9.wireSize_0 <= 0);}
    if (X60Qx_564){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_567 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I4823751142713875849_run8hsnpi)}
      );
      result_40 = X60Qx_567;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
      eQdestroy_0_nifb6mq6y1((&c_2));
      return result_40;}
    WireField_0_run8hsnpi fa_0 = f_9;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    fa_0.isVar_0 = NIM_TRUE;
    WireField_0_run8hsnpi X60Qtmp_108 = fa_0;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fa_0));
    result_40 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_108, .fld_1 = NIM_TRUE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fa_0));
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_40;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fa_0));}
  NB8 X60Qx_568;
  if (f_9.isPod_0){
    X60Qx_568 = NIM_TRUE;}
  else {
    X60Qx_568 = scalarLeaf_0;}
  if ((!X60Qx_568)){
    string_0_sysvq0asl X60Qx_26;
    nimStrWasMoved((&X60Qx_26));
    if (f_9.isString_0){
      nimStrDestroy(X60Qx_26);
      X60Qx_26 = (string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
      ;}
    else {
      string_0_sysvq0asl X60Qx_27;
      nimStrWasMoved((&X60Qx_27));
      if (f_9.isSeq_0){
        nimStrDestroy(X60Qx_27);
        X60Qx_27 = (string_0_sysvq0asl){
          .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
        ;}
      else {
        string_0_sysvq0asl X60Qx_28;
        nimStrWasMoved((&X60Qx_28));
        if (f_9.isEnum_0){
          nimStrDestroy(X60Qx_28);
          X60Qx_28 = (string_0_sysvq0asl){
            .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
          ;}
        else {
          nimStrDestroy(X60Qx_28);
          X60Qx_28 = (string_0_sysvq0asl){
            .bytes_0 = 1847615998u, .more_0 = (&strlit_0_I11949153613191379336_run8hsnpi)}
          ;}
        nimStrDestroy(X60Qx_27);
        X60Qx_27 = X60Qx_28;
        nimStrWasMoved((&X60Qx_28));
        nimStrDestroy(X60Qx_28);}
      nimStrDestroy(X60Qx_26);
      X60Qx_26 = X60Qx_27;
      nimStrWasMoved((&X60Qx_27));
      nimStrDestroy(X60Qx_27);}
    string_0_sysvq0asl X60Qdesugar_27 = X60Qx_26;
    nimStrWasMoved((&X60Qx_26));
    NI32 X60Qx_569 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I12459124382821890348_run8hsnpi)}
    );
    NI32 X60Qx_570 = len_4_sysvq0asl(X60Qdesugar_27);
    NI32 X60Qx_571 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I14049035126231656660_run8hsnpi)}
    );
    string_0_sysvq0asl X60Qdesugar_28 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_569 + X60Qx_570)) + X60Qx_571)));
    add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I12459124382821890348_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_28), X60Qdesugar_27);
    add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I14049035126231656660_run8hsnpi)}
    );
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_572 = declineWire_0_run8hsnpi(X60Qdesugar_28);
    result_40 = X60Qx_572;
    nimStrDestroy(X60Qdesugar_28);
    nimStrDestroy(X60Qdesugar_27);
    nimStrDestroy(X60Qx_26);
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_40;
    nimStrDestroy(X60Qdesugar_28);
    nimStrDestroy(X60Qdesugar_27);
    nimStrDestroy(X60Qx_26);}
  WireField_0_run8hsnpi f2_0 = f_9;
  eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
  f2_0.isVar_0 = NIM_TRUE;
  eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_40));
  WireField_0_run8hsnpi X60Qtmp_109 = f2_0;
  eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f2_0));
  result_40 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
    .fld_0 = X60Qtmp_109, .fld_1 = NIM_TRUE}
  ;
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f2_0));
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
  eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
  eQdestroy_0_nifb6mq6y1((&c_2));
  return result_40;
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f2_0));
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
  eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
  eQdestroy_0_nifb6mq6y1((&c_2));
  return result_40;}
string_0_sysvq0asl shimNameFor_0_run8hsnpi(NU32 sym_8){
  string_0_sysvq0asl result_41;
  nimStrWasMoved((&result_41));
  NU64 h_0 = ((NU64)14695981039346656037ull);
  {
    string_0_sysvq0asl* X60Qx_573 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_8);
    string_0_sysvq0asl X60QconstRefTemp_0 = (*X60Qx_573);
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_8 = toOpenArray_2_sysvq0asl((&X60QconstRefTemp_0));
    NI32 X60Qlf_9 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_574 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_8);
        if (X60Qlf_9 < X60Qx_574){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_8, X60Qlf_9);
            h_0 = ((NU64)(h_0 ^ ((NU64)((NU8)(*X60Qii_2)))));
            h_0 = ((NU64)(h_0 * ((NU64)1099511628211ull)));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl s_11 = (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I4209738878907651049_run8hsnpi)}
  ;
  NI32 i_5 = 60;
  {
    while (0 <= i_5){
      NC8 X60Qx_575 = getQ_9_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 842084606u, .more_0 = (&strlit_0_I6105018409752412263_dbg4n0xd21)}
      , ((NI32)((NU64)(((NU64)(h_0 >> ((NU32)i_5))) & ((NU64)15u)))));
      add_1_sysvq0asl((&s_11), X60Qx_575);
      minusQeQ_0_Ipe1u69_hos5i19e11((&i_5), 4);}}
  whileStmtLabel_3: ;
  nimStrDestroy(result_41);
  result_41 = s_11;
  nimStrWasMoved((&s_11));
  nimStrDestroy(s_11);
  return result_41;
  nimStrDestroy(s_11);
  return result_41;}
X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax declineShim_0_run8hsnpi(string_0_sysvq0asl reason_1){
  X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax result_42;
  eQwasmovedQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi((&result_42));
  declineNote_0_croph25r5(2, reason_1);
  eQdestroyQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(result_42);
  result_42 = (X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax){
    .fld_0 = NIM_NIL, .fld_1 = NIM_FALSE}
  ;
  return result_42;}
X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax describeCallee_0_run8hsnpi(NU32 sym_9, Cursor_0_nifb6mq6y1 body_0){
  X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax result_43;
  eQwasmovedQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi((&result_43));
  Routine_0_decqocs071 r_3 = asRoutine_0_decqocs071(body_0, 0);
  void* X60Qx_576 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1));
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_110 = ((X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*)X60Qx_576);
  string_0_sysvq0asl X60Qx_577 = baseNameOf_0_run8hsnpi(sym_9);
  string_0_sysvq0asl X60Qx_578 = shimNameFor_0_run8hsnpi(sym_9);
  seq_0_Il8twp61_aow7lb5cq1 X60Qx_579 = newSeqUninit_0_Iopvcdu1_aow7lb5cq1(0);
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_580 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_581 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_582 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ik7wkpe_aow7lb5cq1 X60Qx_583 = newSeqUninit_0_Idxnvmq_aow7lb5cq1(0);
  (*X60Qtmp_110) = (X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1){
    .r_00 = 0, .d_00 = (ShimEntry_Obj_0_run8hsnpi){
      .sym_0 = sym_9, .base_0 = X60Qx_577, .shimSym_0 = X60Qx_578, .args_0 = X60Qx_579, .argOffs_0 = X60Qx_580, .inSize_0 = ((NI32)0), .ret_0 = (WireField_0_run8hsnpi){
        .desc_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .srcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
      , .retVoid_0 = NIM_FALSE, .outVarOffs_0 = X60Qx_581, .outSize_0 = ((NI32)0), .redeclTypes_0 = X60Qx_582, .redeclProc_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .noDerefOffs_0 = X60Qx_583, .nCalls_0 = ((NI32)0), .nBytesIn_0 = ((NI32)0), .nBytesOut_0 = ((NI32)0), .fn_0 = ((X60Qt_0_IApointerZAR0ZAiS32ZAiS32ZAcdeclZAfalseZAR32_run8hsnpi)NIM_NIL), .resolved_0 = NIM_FALSE}}
  ;
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_14 = X60Qtmp_110;
  Cursor_0_nifb6mq6y1 pc_2 = r_3.params_0;
  eQwasMoved_0_nifb6mq6y1((&r_3.params_0));
  NB8 X60Qx_125;
  NifKind_0_nif81dubp1 X60Qx_584 = kind_0_nifb6mq6y1(pc_2);
  if (X60Qx_584 == 11){
    string_0_sysvq0asl X60Qtmp_111 = nodeTag_0_run8hsnpi(pc_2);
    NB8 X60Qx_585 = eqQ_20_sysvq0asl(X60Qtmp_111, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_der823rwr1)}
    );
    X60Qx_125 = X60Qx_585;
    nimStrDestroy(X60Qtmp_111);}
  else {
    X60Qx_125 = NIM_FALSE;}
  if (X60Qx_125){
    inc_0_nifb6mq6y1((&pc_2));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_586 = kind_0_nifb6mq6y1(pc_2);
        if ((!(X60Qx_586 == 12))){
          NifKind_0_nif81dubp1 X60Qx_587 = kind_0_nifb6mq6y1(pc_2);
          if (X60Qx_587 == 11){
            Local_0_decqocs071 loc_1 = takeLocal_0_decqocs071((&pc_2), 2);
            X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qtmptup_9 = describeType_0_run8hsnpi(loc_1.typ_0);
            WireField_0_run8hsnpi f_10 = X60Qtmptup_9.fld_0;
            eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60Qtmptup_9.fld_0));
            NB8 ok_4 = X60Qtmptup_9.fld_1;
            if ((!ok_4)){
              result_43 = (X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax){
                .fld_0 = NIM_NIL, .fld_1 = NIM_FALSE}
              ;
              eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_10));
              eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_9));
              eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_1));
              eQdestroy_0_nifb6mq6y1((&pc_2));
              eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
              eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
              return result_43;}
            if (f_10.isForeignPtr_0){
              X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_588 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                .bytes_0 = 1935892734u, .more_0 = (&strlit_0_I12060659291606161857_run8hsnpi)}
              );
              result_43 = X60Qx_588;
              eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_10));
              eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_9));
              eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_1));
              eQdestroy_0_nifb6mq6y1((&pc_2));
              eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
              eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
              return result_43;}
            WireField_0_run8hsnpi X60Qtmp_112 = f_10;
            eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_10));
            add_0_Itzi0i7_run8hsnpi((&(*e_14).d_00.args_0), X60Qtmp_112);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_10));
            eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_9));
            eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_1));}
          else {
            skip_0_nifb6mq6y1((&pc_2));}}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  NB8 X60Qx_589;
  NifKind_0_nif81dubp1 X60Qx_590 = kind_0_nifb6mq6y1(r_3.retType_0);
  if (X60Qx_590 == 11){
    X60Qx_589 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_591 = kind_0_nifb6mq6y1(r_3.retType_0);
    X60Qx_589 = (X60Qx_591 == 4);}
  if (X60Qx_589){
    string_0_sysvq0asl X60Qx_29;
    nimStrWasMoved((&X60Qx_29));
    NifKind_0_nif81dubp1 X60Qx_592 = kind_0_nifb6mq6y1(r_3.retType_0);
    if (X60Qx_592 == 11){
      nimStrDestroy(X60Qx_29);
      string_0_sysvq0asl X60Qx_593 = nodeTag_0_run8hsnpi(r_3.retType_0);
      X60Qx_29 = X60Qx_593;}
    else {
      nimStrDestroy(X60Qx_29);
      X60Qx_29 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl rtag_0 = X60Qx_29;
    nimStrWasMoved((&X60Qx_29));
    NB8 X60Qx_594 = eqQ_20_sysvq0asl(rtag_0, (string_0_sysvq0asl){
      .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
    );
    if (X60Qx_594){
      (*e_14).d_00.retVoid_0 = NIM_TRUE;}
    else {
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qtmptup_10 = describeType_0_run8hsnpi(r_3.retType_0);
      WireField_0_run8hsnpi f_11 = X60Qtmptup_10.fld_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60Qtmptup_10.fld_0));
      NB8 ok_5 = X60Qtmptup_10.fld_1;
      if ((!ok_5)){
        result_43 = (X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax){
          .fld_0 = NIM_NIL, .fld_1 = NIM_FALSE}
        ;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));
        nimStrDestroy(rtag_0);
        nimStrDestroy(X60Qx_29);
        eQdestroy_0_nifb6mq6y1((&pc_2));
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
        return result_43;}
      NB8 X60Qx_595;
      if (f_11.isRef_0){
        X60Qx_595 = NIM_TRUE;}
      else {
        X60Qx_595 = f_11.isArenaRef_0;}
      if (X60Qx_595){
        X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_596 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I9252022049267197370_run8hsnpi)}
        );
        result_43 = X60Qx_596;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));
        nimStrDestroy(rtag_0);
        nimStrDestroy(X60Qx_29);
        eQdestroy_0_nifb6mq6y1((&pc_2));
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
        return result_43;}
      if (f_11.isPtrArena_0){
        X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_597 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I293621626120980652_run8hsnpi)}
        );
        result_43 = X60Qx_597;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));
        nimStrDestroy(rtag_0);
        nimStrDestroy(X60Qx_29);
        eQdestroy_0_nifb6mq6y1((&pc_2));
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
        return result_43;}
      NB8 X60Qx_598;
      NB8 X60Qx_599;
      if (f_11.isPod_0){
        X60Qx_599 = (((NU32)f_11.typeSym_0) == ((NU32)0u));}
      else {
        X60Qx_599 = NIM_FALSE;}
      if (X60Qx_599){
        NB8 X60Qx_600;
        if (f_11.desc_0 == NIM_NIL){
          X60Qx_600 = NIM_TRUE;}
        else {
          X60Qx_600 = (!((*f_11.desc_0).d_00.kind_0 == 11));}
        X60Qx_598 = X60Qx_600;}
      else {
        X60Qx_598 = NIM_FALSE;}
      if (X60Qx_598){
        X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_601 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1869505022u, .more_0 = (&strlit_0_I12129503281566277309_run8hsnpi)}
        );
        result_43 = X60Qx_601;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));
        nimStrDestroy(rtag_0);
        nimStrDestroy(X60Qx_29);
        eQdestroy_0_nifb6mq6y1((&pc_2));
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
        return result_43;}
      WireField_0_run8hsnpi* X60Qlhs_113 = (&(*e_14).d_00.ret_0);
      WireField_0_run8hsnpi X60Qlhs_114 = f_11;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&(*X60Qlhs_113)));
      (*X60Qlhs_113) = X60Qlhs_114;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));}
    nimStrDestroy(rtag_0);
    nimStrDestroy(X60Qx_29);}
  else {
    (*e_14).d_00.retVoid_0 = NIM_TRUE;}
  NI32 off_8 = 0;
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_10 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_14).d_00.args_0);
    NI32 X60Qlf_11 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_602 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_10);
        if (X60Qlf_11 < X60Qx_602){
          {
            WireField_0_run8hsnpi* X60Qii_3 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_10, X60Qlf_11);
            add_0_I8kd4i4_aow7lb5cq1((&(*e_14).d_00.argOffs_0), off_8);
            NI32 X60Qx_30;
            if (0 < (*X60Qii_3).wireSize_0){
              X60Qx_30 = (*X60Qii_3).wireSize_0;}
            else {
              X60Qx_30 = 8;}
            off_8 = ((NI32)(off_8 + X60Qx_30));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_11));}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  forStmtLabel_1: ;
  (*e_14).d_00.inSize_0 = off_8;
  NB8 hasVar_0 = NIM_FALSE;
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_12 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_14).d_00.args_0);
    NI32 X60Qlf_13 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_603 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_12);
        if (X60Qlf_13 < X60Qx_603){
          {
            WireField_0_run8hsnpi* X60Qii_6 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_12, X60Qlf_13);
            if ((*X60Qii_6).isVar_0){
              hasVar_0 = NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_13));}
        else {
          break;}}}
    whileStmtLabel_5: ;}
  forStmtLabel_4: ;
  NB8 X60Qx_604;
  NB8 X60Qx_605;
  if (hasVar_0){
    X60Qx_605 = (!(*e_14).d_00.retVoid_0);}
  else {
    X60Qx_605 = NIM_FALSE;}
  if (X60Qx_605){
    X60Qx_604 = ((*e_14).d_00.ret_0.wireSize_0 == 0);}
  else {
    X60Qx_604 = NIM_FALSE;}
  if (X60Qx_604){
    X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_606 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I15683387437464179193_run8hsnpi)}
    );
    result_43 = X60Qx_606;
    eQdestroy_0_nifb6mq6y1((&pc_2));
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
    return result_43;}
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_14 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_14).d_00.args_0);
    NI32 X60Qlf_15 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_607 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_14);
        if (X60Qlf_15 < X60Qx_607){
          {
            WireField_0_run8hsnpi* X60Qii_9 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_14, X60Qlf_15);
            NB8 X60Qx_608;
            if ((*X60Qii_9).isVar_0){
              X60Qx_608 = (*X60Qii_9).isArenaPtr_0;}
            else {
              X60Qx_608 = NIM_FALSE;}
            if (X60Qx_608){
              NB8 X60Qx_609;
              if ((*X60Qii_9).desc_0 == NIM_NIL){
                X60Qx_609 = NIM_TRUE;}
              else {
                X60Qx_609 = (((NU32)(*X60Qii_9).typeSym_0) == ((NU32)0u));}
              if (X60Qx_609){
                X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_610 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                  .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I4449311905133063423_run8hsnpi)}
                );
                result_43 = X60Qx_610;
                eQdestroy_0_nifb6mq6y1((&pc_2));
                eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
                eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
                return result_43;}
              X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qii_10 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qii_9).desc_0);
              while (NIM_TRUE){
                NB8 X60Qx_611;
                if ((!(X60Qii_10 == NIM_NIL))){
                  X60Qx_611 = ((*X60Qii_10).d_00.kind_0 == 13);}
                else {
                  X60Qx_611 = NIM_FALSE;}
                if (X60Qx_611){
                  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qlhs_115 = X60Qii_10;
                  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_612 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qii_10).d_00.elem_0);
                  X60Qii_10 = X60Qx_612;
                  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qlhs_115);}
                else {
                  break;}}
              NB8 X60Qx_613;
              if (X60Qii_10 == NIM_NIL){
                X60Qx_613 = NIM_TRUE;}
              else {
                NB8 X60Qx_614;
                if ((!((*X60Qii_10).d_00.kind_0 == 10))){
                  X60Qx_614 = (!((*X60Qii_10).d_00.kind_0 == 11));}
                else {
                  X60Qx_614 = NIM_FALSE;}
                X60Qx_613 = X60Qx_614;}
              if (X60Qx_613){
                X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_615 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                  .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I12911497544173404865_run8hsnpi)}
                );
                result_43 = X60Qx_615;
                eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qii_10);
                eQdestroy_0_nifb6mq6y1((&pc_2));
                eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
                eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
                return result_43;}
              {
                openArray_0_I3ca6t4_layptix6a1 X60Qlf_16 = toOpenArray_1_I0zz6qv1_layptix6a1((*X60Qii_10).d_00.fields_0);
                NI32 X60Qlf_17 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_616 = len_6_I0tpktl1_layptix6a1(X60Qlf_16);
                    if (X60Qlf_17 < X60Qx_616){
                      {
                        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_13 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_16, X60Qlf_17);
                        if ((*X60Qii_13) == NIM_NIL){
                          X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_617 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                            .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I12139432315779883303_run8hsnpi)}
                          );
                          result_43 = X60Qx_617;
                          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qii_10);
                          eQdestroy_0_nifb6mq6y1((&pc_2));
                          eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
                          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
                          return result_43;}
                        NB8 X60Qx_618;
                        NB8 X60Qx_619;
                        NB8 X60Qx_620;
                        NB8 X60Qx_621;
                        NB8 X60Qx_622;
                        NB8 X60Qx_623;
                        if ((*(*X60Qii_13)).d_00.kind_0 == 10){
                          X60Qx_623 = NIM_TRUE;}
                        else {
                          X60Qx_623 = ((*(*X60Qii_13)).d_00.kind_0 == 11);}
                        if (X60Qx_623){
                          X60Qx_622 = NIM_TRUE;}
                        else {
                          X60Qx_622 = ((*(*X60Qii_13)).d_00.kind_0 == 13);}
                        if (X60Qx_622){
                          X60Qx_621 = NIM_TRUE;}
                        else {
                          X60Qx_621 = ((*(*X60Qii_13)).d_00.kind_0 == 15);}
                        if (X60Qx_621){
                          X60Qx_620 = NIM_TRUE;}
                        else {
                          X60Qx_620 = ((*(*X60Qii_13)).d_00.kind_0 == 9);}
                        if (X60Qx_620){
                          X60Qx_619 = NIM_TRUE;}
                        else {
                          X60Qx_619 = ((*(*X60Qii_13)).d_00.kind_0 == 6);}
                        if (X60Qx_619){
                          X60Qx_618 = NIM_TRUE;}
                        else {
                          X60Qx_618 = ((*(*X60Qii_13)).d_00.kind_0 == 12);}
                        if (X60Qx_618){
                          X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_624 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                            .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I3386527286220271425_run8hsnpi)}
                          );
                          result_43 = X60Qx_624;
                          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qii_10);
                          eQdestroy_0_nifb6mq6y1((&pc_2));
                          eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
                          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
                          return result_43;}}
                      inc_1_I6wjjge_aow2h993l1((&X60Qlf_17));}
                    else {
                      break;}}}
                whileStmtLabel_12: ;}
              forStmtLabel_11: ;
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qii_10);}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_15));}
        else {
          break;}}}
    whileStmtLabel_8: ;}
  forStmtLabel_7: ;
  NI64 X60Qx_31;
  if ((*e_14).d_00.retVoid_0){
    X60Qx_31 = 0;}
  else {
    X60Qx_31 = (*e_14).d_00.ret_0.wireSize_0;}
  NI32 retFixed_0 = X60Qx_31;
  NI32 wb_0 = retFixed_0;
  NI32 vi_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_625 = len_3_In63jw61_aow7lb5cq1((*e_14).d_00.args_0);
      if (vi_0 < X60Qx_625){
        WireField_0_run8hsnpi* X60Qx_626 = getQ_7_Iko57h9_aow7lb5cq1((*e_14).d_00.args_0, vi_0);
        if ((*X60Qx_626).isVar_0){
          add_0_I8kd4i4_aow7lb5cq1((&(*e_14).d_00.outVarOffs_0), wb_0);
          WireField_0_run8hsnpi* X60Qx_627 = getQ_7_Iko57h9_aow7lb5cq1((*e_14).d_00.args_0, vi_0);
          wb_0 = ((NI32)(wb_0 + (*X60Qx_627).wireSize_0));}
        else {
          add_0_I8kd4i4_aow7lb5cq1((&(*e_14).d_00.outVarOffs_0), -1);}
        inc_1_I6wjjge_aow2h993l1((&vi_0));}
      else {
        break;}}}
  whileStmtLabel_14: ;
  NI32 X60Qx_32;
  if (hasVar_0){
    X60Qx_32 = wb_0;}
  else {
    if ((*e_14).d_00.retVoid_0){
      X60Qx_32 = 0;}
    else {
      NI32 X60Qx_33;
      if (0 < (*e_14).d_00.ret_0.wireSize_0){
        X60Qx_33 = (*e_14).d_00.ret_0.wireSize_0;}
      else {
        X60Qx_33 = 64;}
      X60Qx_32 = X60Qx_33;}}
  (*e_14).d_00.outSize_0 = X60Qx_32;
  seq_0_Ik7wkpe_aow7lb5cq1* X60Qlhs_116 = (&(*e_14).d_00.noDerefOffs_0);
  seq_0_Ik7wkpe_aow7lb5cq1 X60Qlhs_117 = newSeqUninit_0_Idxnvmq_aow7lb5cq1(0);
  eQdestroy_1_Ij4pznj1_aow7lb5cq1((*X60Qlhs_116));
  (*X60Qlhs_116) = X60Qlhs_117;
  NI32 gi_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_628 = len_3_In63jw61_aow7lb5cq1((*e_14).d_00.args_0);
      if (gi_0 < X60Qx_628){
        seq_0_Ift2sne_aow7lb5cq1 X60Qx_629 = newSeq_0_I7328u4_flaksyopx1(0);
        add_0_Iivdbhc_aow7lb5cq1((&(*e_14).d_00.noDerefOffs_0), X60Qx_629);
        inc_1_I6wjjge_aow2h993l1((&gi_0));}
      else {
        break;}}}
  whileStmtLabel_15: ;
  eQdestroyQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(result_43);
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_118 = e_14;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&e_14));
  result_43 = (X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax){
    .fld_0 = X60Qtmp_118, .fld_1 = NIM_TRUE}
  ;
  eQdestroy_0_nifb6mq6y1((&pc_2));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
  return result_43;
  eQdestroy_0_nifb6mq6y1((&pc_2));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
  return result_43;}
NU64 valToU64_0_run8hsnpi(Value_0_valzr1t4f* v_0){
  NU64 result_44;
  NU64 X60Qx_34;
  switch ((*v_0).kind_0){
    case 1:
    case 2:
    {
      NI64 X60Qx_630 = asInt_0_valzr1t4f((&(*v_0)));
      X60Qx_34 = ((NU64)X60Qx_630);}
    break;
    case 5:
    {
      X60Qx_34 = ((NU64)((NU8)(*v_0).cval_0));}
    break;
    case 4:
    {
      NU64 X60Qx_35;
      if ((*v_0).bval_0){
        X60Qx_35 = ((NU64)1u);}
      else {
        X60Qx_35 = ((NU64)0u);}
      X60Qx_34 = X60Qx_35;}
    break;
    case 7:
    {
      X60Qx_34 = ((NU64)((NU32)((NI32)(*v_0).eord_0)));}
    break;
    case 3:
    {
      NU64 X60Qx_36;
      if ((*v_0).fbits_0 == 32){
        NF32 X60Qx_631 = ((NF32)(*v_0).fval_0);
        NU32 X60Qx_632;
        copyMem_0_sysvq0asl((&X60Qx_632), (&X60Qx_631), sizeof(NU32));
        X60Qx_36 = ((NU64)X60Qx_632);}
      else {
        NF64 X60Qx_633 = (*v_0).fval_0;
        NU64 X60Qx_634;
        copyMem_0_sysvq0asl((&X60Qx_634), (&X60Qx_633), sizeof(NU64));
        X60Qx_36 = X60Qx_634;}
      X60Qx_34 = X60Qx_36;}
    break;
    default:
    {
      X60Qx_34 = ((NU64)0u);}
    break;}
  result_44 = X60Qx_34;
  return result_44;}
void writeBytes_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_0, NI32 off_0, NU64 u_0, NI32 n_1){
  NI32 i_7 = 0;
  {
    while (i_7 < n_1){
      putQ_7_Ipw0nqk1_explnj22x1(buf_0, ((NI32)(off_0 + i_7)), ((NU8)((NU64)(((NU64)(u_0 >> ((NU32)(((NU32)i_7) * 8u)))) & ((NU64)255u)))));
      inc_1_I6wjjge_aow2h993l1((&i_7));}}
  whileStmtLabel_0: ;}
NU64 readBytes_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v buf_1, NI32 off_1, NI32 n_2){
  NU64 result_45;
  NU64 u_3 = ((NU64)0u);
  NI32 i_9 = 0;
  {
    while (i_9 < n_2){
      NU8* X60Qx_635 = getQ_7_Ig0r1051_arecyyj7v(buf_1, ((NI32)(off_1 + i_9)));
      u_3 = ((NU64)(u_3 | ((NU64)(((NU64)(*X60Qx_635)) << ((NU32)(((NU32)i_9) * 8u))))));
      inc_1_I6wjjge_aow2h993l1((&i_9));}}
  whileStmtLabel_0: ;
  result_45 = u_3;
  return result_45;}
void packPod_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_2, NI32 off_2, Value_0_valzr1t4f* v_1, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_4){
  seq_0_Ift2sne_aow7lb5cq1 offs_0 = fieldOffsets_0_layptix6a1(td_4, 8);
  if ((*v_1).obj_0 == NIM_NIL){
    eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_0);
    return;}
  NI32 i_11 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_636;
      NB8 X60Qx_637;
      NI32 X60Qx_638 = len_3_I5m68tr1_aow7lb5cq1((*td_4).d_00.fields_0);
      if (i_11 < X60Qx_638){
        NI32 X60Qx_639 = len_3_I83dzei_arecyyj7v((*(*v_1).obj_0).d_00.cells_0);
        X60Qx_637 = (i_11 < X60Qx_639);}
      else {
        X60Qx_637 = NIM_FALSE;}
      if (X60Qx_637){
        NI32 X60Qx_640 = len_3_I0v1j8d_aow7lb5cq1(offs_0);
        X60Qx_636 = (i_11 < X60Qx_640);}
      else {
        X60Qx_636 = NIM_FALSE;}
      if (X60Qx_636){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_641 = getQ_7_I45w7c91_aow7lb5cq1((*td_4).d_00.fields_0, i_11);
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* fd_3 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qx_641));
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_642 = getQ_7_Ii14ync1_arecyyj7v((*(*v_1).obj_0).d_00.cells_0, i_11);
        Value_0_valzr1t4f cv_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_642)).d_00.v_0));
        NB8 X60Qx_643;
        if ((*fd_3).d_00.kind_0 == 10){
          X60Qx_643 = NIM_TRUE;}
        else {
          X60Qx_643 = ((*fd_3).d_00.kind_0 == 11);}
        if (X60Qx_643){
          NI32* X60Qx_644 = getQ_7_Ir8kccm_aow7lb5cq1(offs_0, i_11);
          packPod_0_run8hsnpi(buf_2, ((NI32)(off_2 + (*X60Qx_644))), (&cv_0), fd_3);}
        else {
          NI32* X60Qx_645 = getQ_7_Ir8kccm_aow7lb5cq1(offs_0, i_11);
          NU64 X60Qx_646 = valToU64_0_run8hsnpi((&cv_0));
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_647 = sizeAlign_1_layptix6a1(fd_3, 8);
          writeBytes_0_run8hsnpi(buf_2, ((NI32)(off_2 + (*X60Qx_645))), X60Qx_646, X60Qx_647.fld_0);}
        inc_1_I6wjjge_aow2h993l1((&i_11));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_0));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_3);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_0);}
NB8 packPodArena_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_3, NI32 off_3, Value_0_valzr1t4f* v_2, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_5, ArenaMat_0_arecyyj7v* m_0, seq_0_Ift2sne_aow7lb5cq1 noDerefOffs_0){
  NB8 result_46;
  if (td_5 == NIM_NIL){
    return NIM_FALSE;}
  if ((*td_5).d_00.kind_0 == 13){
    NB8 X60Qx_648;
    if ((!((*td_5).d_00.elem_0 == NIM_NIL))){
      NB8 X60Qx_649 = packPodArena_0_run8hsnpi(buf_3, off_3, (&(*v_2)), (*td_5).d_00.elem_0, m_0, noDerefOffs_0);
      X60Qx_648 = X60Qx_649;}
    else {
      X60Qx_648 = NIM_FALSE;}
    result_46 = X60Qx_648;
    return result_46;}
  if ((*v_2).obj_0 == NIM_NIL){
    return NIM_FALSE;}
  seq_0_Ift2sne_aow7lb5cq1 offs_1 = fieldOffsets_0_layptix6a1(td_5, 8);
  result_46 = NIM_TRUE;
  NI32 i_14 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_650;
      NB8 X60Qx_651;
      NI32 X60Qx_652 = len_3_I5m68tr1_aow7lb5cq1((*td_5).d_00.fields_0);
      if (i_14 < X60Qx_652){
        NI32 X60Qx_653 = len_3_I83dzei_arecyyj7v((*(*v_2).obj_0).d_00.cells_0);
        X60Qx_651 = (i_14 < X60Qx_653);}
      else {
        X60Qx_651 = NIM_FALSE;}
      if (X60Qx_651){
        NI32 X60Qx_654 = len_3_I0v1j8d_aow7lb5cq1(offs_1);
        X60Qx_650 = (i_14 < X60Qx_654);}
      else {
        X60Qx_650 = NIM_FALSE;}
      if (X60Qx_650){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_655 = getQ_7_I45w7c91_aow7lb5cq1((*td_5).d_00.fields_0, i_14);
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* fd_4 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qx_655));
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_656 = getQ_7_Ii14ync1_arecyyj7v((*(*v_2).obj_0).d_00.cells_0, i_14);
        Value_0_valzr1t4f cv_1 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_656)).d_00.v_0));
        if ((*fd_4).d_00.kind_0 == 5){
          NB8 nd_0 = NIM_FALSE;
          NI32 q_0 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_657 = len_3_I0v1j8d_aow7lb5cq1(noDerefOffs_0);
              if (q_0 < X60Qx_657){
                NI32* X60Qx_658 = getQ_7_Ir8kccm_aow7lb5cq1(noDerefOffs_0, q_0);
                NI32* X60Qx_659 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_14);
                if ((*X60Qx_658) == (*X60Qx_659)){
                  nd_0 = NIM_TRUE;
                  goto whileStmtLabel_1;}
                inc_1_I6wjjge_aow2h993l1((&q_0));}
              else {
                break;}}}
          whileStmtLabel_1: ;
          void* p_12 = materializePtr_0_arecyyj7v(m_0, (&cv_1), nd_0, 0);
          if (p_12 == NIM_NIL){
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_1));
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_4);
            eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_1);
            return NIM_FALSE;}
          NI32* X60Qx_660 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_14);
          writeBytes_0_run8hsnpi(buf_3, ((NI32)(off_3 + (*X60Qx_660))), ((NU64)((NU32)p_12)), 8);}
        else {
          if ((*fd_4).d_00.kind_0 == 15){
            if ((!(cv_1.kind_0 == 8))){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_1));
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_4);
              eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_1);
              return NIM_FALSE;}
            BlockEntry_0_arecyyj7v b_3 = seqBlock_0_arecyyj7v(m_0, cv_1.sq_0);
            NI32* X60Qx_661 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_14);
            writeBytes_0_run8hsnpi(buf_3, ((NI32)(((NI32)(off_3 + (*X60Qx_661))) + ((NI32)0))), ((NU64)b_3.count_0), 8);
            NI32* X60Qx_662 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_14);
            writeBytes_0_run8hsnpi(buf_3, ((NI32)(((NI32)(off_3 + (*X60Qx_662))) + ((NI32)8))), ((NU64)b_3.data_0), 8);
            eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_3));}
          else {
            NB8 X60Qx_663;
            NB8 X60Qx_664;
            if ((*fd_4).d_00.kind_0 == 10){
              X60Qx_664 = NIM_TRUE;}
            else {
              X60Qx_664 = ((*fd_4).d_00.kind_0 == 11);}
            if (X60Qx_664){
              X60Qx_663 = NIM_TRUE;}
            else {
              X60Qx_663 = ((*fd_4).d_00.kind_0 == 13);}
            if (X60Qx_663){
              seq_0_Ift2sne_aow7lb5cq1 X60Qtmp_119 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
              NI32* X60Qx_665 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_14);
              NB8 X60Qx_666 = packPodArena_0_run8hsnpi(buf_3, ((NI32)(off_3 + (*X60Qx_665))), (&cv_1), fd_4, m_0, X60Qtmp_119);
              if ((!X60Qx_666)){
                eQdestroy_1_Iv9ij5i1_aow7lb5cq1(X60Qtmp_119);
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_1));
                eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_4);
                eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_1);
                return NIM_FALSE;}
              eQdestroy_1_Iv9ij5i1_aow7lb5cq1(X60Qtmp_119);}
            else {
              NI32* X60Qx_667 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_14);
              NU64 X60Qx_668 = valToU64_0_run8hsnpi((&cv_1));
              X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_669 = sizeAlign_1_layptix6a1(fd_4, 8);
              writeBytes_0_run8hsnpi(buf_3, ((NI32)(off_3 + (*X60Qx_667))), X60Qx_668, X60Qx_669.fld_0);}}}
        inc_1_I6wjjge_aow2h993l1((&i_14));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_1));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_4);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_1);
  return result_46;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_1);
  return result_46;}
void appendU_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_4, NU64 u_1, NI32 n_3){
  NI32 i_15 = 0;
  {
    while (i_15 < n_3){
      add_0_Ibphvmo_run8hsnpi(buf_4, ((NU8)((NU64)(((NU64)(u_1 >> ((NU32)(((NU32)i_15) * 8u)))) & ((NU64)255u)))));
      inc_1_I6wjjge_aow2h993l1((&i_15));}}
  whileStmtLabel_0: ;}
seq_0_Incv1wn_arecyyj7v podBytes_0_run8hsnpi(Value_0_valzr1t4f* v_3, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_6){
  seq_0_Incv1wn_arecyyj7v result_47;
  eQwasMoved_1_I861g1c1_arecyyj7v((&result_47));
  eQdestroy_1_Ijx6eoq_arecyyj7v(result_47);
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_670 = sizeAlign_1_layptix6a1(td_6, 8);
  seq_0_Incv1wn_arecyyj7v X60Qx_671 = newSeq_0_Ivbxvoi1_explnj22x1(X60Qx_670.fld_0);
  result_47 = X60Qx_671;
  packPod_0_run8hsnpi((&result_47), 0, (&(*v_3)), td_6);
  return result_47;}
void appendVal_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_5, Value_0_valzr1t4f* v_4, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_7){
  switch ((*td_7).d_00.kind_0){
    case 10:
    case 11:
    {
      NI32 i_16 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_672 = len_3_I5m68tr1_aow7lb5cq1((*td_7).d_00.fields_0);
          if (i_16 < X60Qx_672){
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_37;
            eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_37));
            NB8 X60Qx_673;
            if ((*v_4).kind_0 == 11){
              X60Qx_673 = NIM_TRUE;}
            else {
              X60Qx_673 = ((*v_4).kind_0 == 10);}
            if (X60Qx_673){
              eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_37);
              X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_674 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((*v_4).obj_0);
              X60Qx_37 = X60Qx_674;}
            else {
              eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_37);
              X60Qx_37 = NIM_NIL;}
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_0 = X60Qx_37;
            eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_37));
            Value_0_valzr1t4f X60Qx_38;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_38));
            NB8 X60Qx_675;
            NB8 X60Qx_676;
            if ((!(box_0 == NIM_NIL))){
              NI32 X60Qx_677 = len_3_I83dzei_arecyyj7v((*box_0).d_00.cells_0);
              X60Qx_676 = (i_16 < X60Qx_677);}
            else {
              X60Qx_676 = NIM_FALSE;}
            if (X60Qx_676){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_678 = getQ_7_Ii14ync1_arecyyj7v((*box_0).d_00.cells_0, i_16);
              X60Qx_675 = (!((*X60Qx_678) == NIM_NIL));}
            else {
              X60Qx_675 = NIM_FALSE;}
            if (X60Qx_675){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_38));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_679 = getQ_7_Ii14ync1_arecyyj7v((*box_0).d_00.cells_0, i_16);
              Value_0_valzr1t4f X60Qx_680 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_679)).d_00.v_0));
              X60Qx_38 = X60Qx_680;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_38));
              Value_0_valzr1t4f X60Qx_681 = vNil_0_valzr1t4f();
              X60Qx_38 = X60Qx_681;}
            Value_0_valzr1t4f fv_0 = X60Qx_38;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_38));
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_682 = getQ_7_I45w7c91_aow7lb5cq1((*td_7).d_00.fields_0, i_16);
            appendVal_0_run8hsnpi(buf_5, (&fv_0), (*X60Qx_682));
            inc_1_I6wjjge_aow2h993l1((&i_16));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fv_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_38));
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_0);
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_37);}
          else {
            break;}}}
      whileStmtLabel_0: ;}
    break;
    case 14:
    {
      string_0_sysvq0asl X60Qx_39;
      nimStrWasMoved((&X60Qx_39));
      if ((*v_4).kind_0 == 6){
        nimStrDestroy(X60Qx_39);
        string_0_sysvq0asl X60Qx_683 = nimStrDup((*v_4).sval_0);
        X60Qx_39 = X60Qx_683;}
      else {
        nimStrDestroy(X60Qx_39);
        string_0_sysvq0asl X60Qx_684 = dollarQ_0_valzr1t4f((&(*v_4)));
        X60Qx_39 = X60Qx_684;}
      string_0_sysvq0asl s_25 = X60Qx_39;
      nimStrWasMoved((&X60Qx_39));
      NI32 X60Qx_685 = len_4_sysvq0asl(s_25);
      appendU_0_run8hsnpi(buf_5, ((NU64)X60Qx_685), 8);
      {
        openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_18 = toOpenArray_2_sysvq0asl((&s_25));
        NI32 X60Qlf_19 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_686 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_18);
            if (X60Qlf_19 < X60Qx_686){
              {
                NC8* X60Qii_3 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_18, X60Qlf_19);
                add_0_Ibphvmo_run8hsnpi(buf_5, ((NU8)(*X60Qii_3)));}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_19));}
            else {
              break;}}}
        whileStmtLabel_2: ;}
      forStmtLabel_1: ;
      nimStrDestroy(s_25);
      nimStrDestroy(X60Qx_39);}
    break;
    case 15:
    {
      NI32 X60Qx_40;
      NB8 X60Qx_687;
      if ((*v_4).kind_0 == 8){
        X60Qx_687 = (!((*v_4).sq_0 == NIM_NIL));}
      else {
        X60Qx_687 = NIM_FALSE;}
      if (X60Qx_687){
        NI32 X60Qx_688 = len_3_I83dzei_arecyyj7v((*(*v_4).sq_0).d_00.elems_0);
        X60Qx_40 = X60Qx_688;}
      else {
        X60Qx_40 = 0;}
      NI32 n_7 = X60Qx_40;
      appendU_0_run8hsnpi(buf_5, ((NU64)n_7), 8);
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_4 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*td_7).d_00.elem_0);
      NB8 flat_2 = NIM_FALSE;
      NI32 w_4 = 0;
      if ((!(el_4 == NIM_NIL))){
        switch ((*el_4).d_00.kind_0){
          case 0:
          case 1:
          case 2:
          case 3:
          case 4:
          case 8:
          {
            X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_689 = sizeAlign_1_layptix6a1(el_4, 8);
            w_4 = X60Qx_689.fld_0;
            NB8 X60Qx_690;
            NB8 X60Qx_691;
            NB8 X60Qx_692;
            if (w_4 == 1){
              X60Qx_692 = NIM_TRUE;}
            else {
              X60Qx_692 = (w_4 == 2);}
            if (X60Qx_692){
              X60Qx_691 = NIM_TRUE;}
            else {
              X60Qx_691 = (w_4 == 4);}
            if (X60Qx_691){
              X60Qx_690 = NIM_TRUE;}
            else {
              X60Qx_690 = (w_4 == 8);}
            flat_2 = X60Qx_690;}
          break;
          default:
          {
            }
          break;}}
      NB8 X60Qx_693;
      if (flat_2){
        X60Qx_693 = (0 < n_7);}
      else {
        X60Qx_693 = NIM_FALSE;}
      if (X60Qx_693){
        NI32 base_8 = len_3_Izoe8zv_arecyyj7v((*buf_5));
        setLen_0_I9zf5sf1_flaksyopx1(buf_5, ((NI32)(base_8 + ((NI32)(n_7 * w_4)))));
        NI32 i_17 = 0;
        {
          while (i_17 < n_7){
            Value_0_valzr1t4f X60Qx_41;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_41));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_694 = getQ_7_Ii14ync1_arecyyj7v((*(*v_4).sq_0).d_00.elems_0, i_17);
            if ((!((*X60Qx_694) == NIM_NIL))){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_41));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_695 = getQ_7_Ii14ync1_arecyyj7v((*(*v_4).sq_0).d_00.elems_0, i_17);
              Value_0_valzr1t4f X60Qx_696 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_695)).d_00.v_0));
              X60Qx_41 = X60Qx_696;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_41));
              Value_0_valzr1t4f X60Qx_697 = vNil_0_valzr1t4f();
              X60Qx_41 = X60Qx_697;}
            Value_0_valzr1t4f ev_0 = X60Qx_41;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_41));
            NU64 X60Qx_698 = valToU64_0_run8hsnpi((&ev_0));
            writeBytes_0_run8hsnpi(buf_5, ((NI32)(base_8 + ((NI32)(i_17 * w_4)))), X60Qx_698, w_4);
            inc_1_I6wjjge_aow2h993l1((&i_17));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_41));}}
        whileStmtLabel_4: ;}
      else {
        NI32 i_18 = 0;
        {
          while (i_18 < n_7){
            Value_0_valzr1t4f X60Qx_42;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_699 = getQ_7_Ii14ync1_arecyyj7v((*(*v_4).sq_0).d_00.elems_0, i_18);
            if ((!((*X60Qx_699) == NIM_NIL))){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_700 = getQ_7_Ii14ync1_arecyyj7v((*(*v_4).sq_0).d_00.elems_0, i_18);
              Value_0_valzr1t4f X60Qx_701 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_700)).d_00.v_0));
              X60Qx_42 = X60Qx_701;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
              Value_0_valzr1t4f X60Qx_702 = vNil_0_valzr1t4f();
              X60Qx_42 = X60Qx_702;}
            Value_0_valzr1t4f ev_1 = X60Qx_42;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
            appendVal_0_run8hsnpi(buf_5, (&ev_1), (*td_7).d_00.elem_0);
            inc_1_I6wjjge_aow2h993l1((&i_18));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_1));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));}}
        whileStmtLabel_5: ;}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_4);}
    break;
    case 9:
    {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_43;
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_43));
      if ((*v_4).kind_0 == 9){
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_43);
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_703 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((*v_4).arr_0);
        X60Qx_43 = X60Qx_703;}
      else {
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_43);
        X60Qx_43 = NIM_NIL;}
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* box_1 = X60Qx_43;
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_43));
      NI32 i_19 = 0;
      {
        while (i_19 < (*td_7).d_00.count_0){
          Value_0_valzr1t4f X60Qx_44;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));
          NB8 X60Qx_704;
          NB8 X60Qx_705;
          if ((!(box_1 == NIM_NIL))){
            NI32 X60Qx_706 = len_3_I83dzei_arecyyj7v((*box_1).d_00.elems_0);
            X60Qx_705 = (i_19 < X60Qx_706);}
          else {
            X60Qx_705 = NIM_FALSE;}
          if (X60Qx_705){
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_707 = getQ_7_Ii14ync1_arecyyj7v((*box_1).d_00.elems_0, i_19);
            X60Qx_704 = (!((*X60Qx_707) == NIM_NIL));}
          else {
            X60Qx_704 = NIM_FALSE;}
          if (X60Qx_704){
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_708 = getQ_7_Ii14ync1_arecyyj7v((*box_1).d_00.elems_0, i_19);
            Value_0_valzr1t4f X60Qx_709 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_708)).d_00.v_0));
            X60Qx_44 = X60Qx_709;}
          else {
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));
            Value_0_valzr1t4f X60Qx_710 = vNil_0_valzr1t4f();
            X60Qx_44 = X60Qx_710;}
          Value_0_valzr1t4f ev_2 = X60Qx_44;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));
          appendVal_0_run8hsnpi(buf_5, (&ev_2), (*td_7).d_00.elem_0);
          inc_1_I6wjjge_aow2h993l1((&i_19));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_2));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_44));}}
      whileStmtLabel_6: ;
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_1);
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_43);}
    break;
    default:
    {
      NU64 X60Qx_711 = valToU64_0_run8hsnpi((&(*v_4)));
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_712 = sizeAlign_1_layptix6a1(td_7, 8);
      appendU_0_run8hsnpi(buf_5, X60Qx_711, X60Qx_712.fld_0);}
    break;}}
Value_0_valzr1t4f readVal_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v buf_6, NI32* pos_0, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_8, NU32 typeSym_2){
  Value_0_valzr1t4f result_48;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_48));
  switch ((*td_8).d_00.kind_0){
    case 10:
    case 11:
    {
      X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi info_1 = podFieldInfo_1_run8hsnpi(typeSym_2);
      void* X60Qx_713 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_120 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_713);
      seq_0_In6doa_arecyyj7v X60Qx_714 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_715 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_120) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
          .typeSym_0 = typeSym_2, .names_0 = X60Qx_714, .cells_0 = X60Qx_715}}
      ;
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_2 = X60Qtmp_120;
      NI32 i_20 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_716 = len_3_I5m68tr1_aow7lb5cq1((*td_8).d_00.fields_0);
          if (i_20 < X60Qx_716){
            NU32 X60Qx_45;
            NI32 X60Qx_717 = len_3_I6y2imo_arecyyj7v(info_1.fld_1);
            if (i_20 < X60Qx_717){
              NU32* X60Qx_718 = getQ_7_I2v00yv1_arecyyj7v(info_1.fld_1, i_20);
              X60Qx_45 = (*X60Qx_718);}
            else {
              X60Qx_45 = ((NU32)0u);}
            NU32 nm_0 = X60Qx_45;
            NU32 X60Qx_46;
            NI32 X60Qx_719 = len_3_I6y2imo_arecyyj7v(info_1.fld_2);
            if (i_20 < X60Qx_719){
              NU32* X60Qx_720 = getQ_7_I2v00yv1_arecyyj7v(info_1.fld_2, i_20);
              X60Qx_46 = (*X60Qx_720);}
            else {
              X60Qx_46 = ((NU32)0u);}
            NU32 fts_1 = X60Qx_46;
            add_0_I34il1q_der823rwr1((&(*box_2).d_00.names_0), nm_0);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_721 = getQ_7_I45w7c91_aow7lb5cq1((*td_8).d_00.fields_0, i_20);
            Value_0_valzr1t4f X60Qtmp_121 = readVal_0_run8hsnpi(buf_6, pos_0, (*X60Qx_721), fts_1);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_722 = newCell_0_valzr1t4f((&X60Qtmp_121));
            add_0_Ijpw0mu_flaksyopx1((&(*box_2).d_00.cells_0), X60Qx_722);
            inc_1_I6wjjge_aow2h993l1((&i_20));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_121));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      Value_0_valzr1t4f X60Qx_47;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));
      NB8 X60Qx_723;
      if ((*td_8).d_00.kind_0 == 11){
        X60Qx_723 = NIM_TRUE;}
      else {
        X60Qx_723 = info_1.fld_0;}
      if (X60Qx_723){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_122 = box_2;
        eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&box_2));
        X60Qx_47 = (Value_0_valzr1t4f){
          .kind_0 = 10, .obj_0 = X60Qtmp_122}
        ;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_123 = box_2;
        eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&box_2));
        X60Qx_47 = (Value_0_valzr1t4f){
          .kind_0 = 11, .obj_0 = X60Qtmp_123}
        ;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_48));
      result_48 = X60Qx_47;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_2);
      eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_1);}
    break;
    case 14:
    {
      NU64 X60Qx_724 = readBytes_0_run8hsnpi(buf_6, (*pos_0), 8);
      NI32 n_8 = ((NI32)X60Qx_724);
      (*pos_0) = ((NI32)((*pos_0) + 8));
      string_0_sysvq0asl s_30 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NI32 i_21 = 0;
      {
        while (i_21 < n_8){
          NU8* X60Qx_725 = getQ_7_Ig0r1051_arecyyj7v(buf_6, ((NI32)((*pos_0) + i_21)));
          add_1_sysvq0asl((&s_30), ((NC8)((NU8)(*X60Qx_725))));
          inc_1_I6wjjge_aow2h993l1((&i_21));}}
      whileStmtLabel_1: ;
      (*pos_0) = ((NI32)((*pos_0) + n_8));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_48));
      Value_0_valzr1t4f X60Qx_726 = vStr_0_valzr1t4f(s_30);
      result_48 = X60Qx_726;
      nimStrDestroy(s_30);}
    break;
    case 15:
    {
      NU64 X60Qx_727 = readBytes_0_run8hsnpi(buf_6, (*pos_0), 8);
      NI32 n_9 = ((NI32)X60Qx_727);
      (*pos_0) = ((NI32)((*pos_0) + 8));
      void* X60Qx_728 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_124 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_728);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_729 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_124) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
          .elems_0 = X60Qx_729, .flat_0 = NIM_NIL}}
      ;
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_0 = X60Qtmp_124;
      NU32 esym_1 = seqElemSymOf_0_run8hsnpi(typeSym_2);
      NI32 i_22 = 0;
      {
        while (i_22 < n_9){
          Value_0_valzr1t4f X60Qtmp_125 = readVal_0_run8hsnpi(buf_6, pos_0, (*td_8).d_00.elem_0, esym_1);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_730 = newCell_0_valzr1t4f((&X60Qtmp_125));
          add_0_Ijpw0mu_flaksyopx1((&(*sb_0).d_00.elems_0), X60Qx_730);
          inc_1_I6wjjge_aow2h993l1((&i_22));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_125));}}
      whileStmtLabel_2: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_48));
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_126 = sb_0;
      eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi((&sb_0));
      result_48 = (Value_0_valzr1t4f){
        .kind_0 = 8, .sq_0 = X60Qtmp_126}
      ;
      eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(sb_0);}
    break;
    case 9:
    {
      void* X60Qx_731 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_127 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_731);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_732 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_127) = (X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (ArrBox_Obj_0_valzr1t4f){
          .elems_0 = X60Qx_732, .lo_0 = 0, .flat_0 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)NIM_NIL)}}
      ;
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* ab_0 = X60Qtmp_127;
      NI32 i_23 = 0;
      {
        while (i_23 < (*td_8).d_00.count_0){
          Value_0_valzr1t4f X60Qtmp_128 = readVal_0_run8hsnpi(buf_6, pos_0, (*td_8).d_00.elem_0, ((NU32)0u));
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_733 = newCell_0_valzr1t4f((&X60Qtmp_128));
          add_0_Ijpw0mu_flaksyopx1((&(*ab_0).d_00.elems_0), X60Qx_733);
          inc_1_I6wjjge_aow2h993l1((&i_23));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_128));}}
      whileStmtLabel_3: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_48));
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_129 = ab_0;
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&ab_0));
      result_48 = (Value_0_valzr1t4f){
        .kind_0 = 9, .arr_0 = X60Qtmp_129}
      ;
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(ab_0);}
    break;
    default:
    {
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_734 = sizeAlign_1_layptix6a1(td_8, 8);
      NI32 sz_1 = X60Qx_734.fld_0;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_48));
      NU64 X60Qx_735 = readBytes_0_run8hsnpi(buf_6, (*pos_0), sz_1);
      Value_0_valzr1t4f X60Qx_736 = scalarFromBits_0_run8hsnpi(X60Qx_735, td_8, typeSym_2);
      result_48 = X60Qx_736;
      (*pos_0) = ((NI32)((*pos_0) + sz_1));}
    break;}
  return result_48;}
void appendField_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_7, Value_0_valzr1t4f* v_5, WireField_0_run8hsnpi* f_0){
  if ((*f_0).isComposite_0){
    appendVal_0_run8hsnpi(buf_7, (&(*v_5)), (*f_0).desc_0);}
  else {
    if ((*f_0).isString_0){
      string_0_sysvq0asl X60Qx_48;
      nimStrWasMoved((&X60Qx_48));
      if ((*v_5).kind_0 == 6){
        nimStrDestroy(X60Qx_48);
        string_0_sysvq0asl X60Qx_737 = nimStrDup((*v_5).sval_0);
        X60Qx_48 = X60Qx_737;}
      else {
        nimStrDestroy(X60Qx_48);
        string_0_sysvq0asl X60Qx_738 = dollarQ_0_valzr1t4f((&(*v_5)));
        X60Qx_48 = X60Qx_738;}
      string_0_sysvq0asl s_31 = X60Qx_48;
      nimStrWasMoved((&X60Qx_48));
      NI32 X60Qx_739 = len_4_sysvq0asl(s_31);
      appendU_0_run8hsnpi(buf_7, ((NU64)X60Qx_739), 8);
      {
        openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_20 = toOpenArray_2_sysvq0asl((&s_31));
        NI32 X60Qlf_21 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_740 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_20);
            if (X60Qlf_21 < X60Qx_740){
              {
                NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_20, X60Qlf_21);
                add_0_Ibphvmo_run8hsnpi(buf_7, ((NU8)(*X60Qii_2)));}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_21));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;
      nimStrDestroy(s_31);
      nimStrDestroy(X60Qx_48);}
    else {
      NB8 X60Qx_741;
      if ((*f_0).isSeq_0){
        X60Qx_741 = (*f_0).elemVarLen_0;}
      else {
        X60Qx_741 = NIM_FALSE;}
      if (X60Qx_741){
        NI32 X60Qx_49;
        NB8 X60Qx_742;
        if ((*v_5).kind_0 == 8){
          X60Qx_742 = (!((*v_5).sq_0 == NIM_NIL));}
        else {
          X60Qx_742 = NIM_FALSE;}
        if (X60Qx_742){
          NI32 X60Qx_743 = len_3_I83dzei_arecyyj7v((*(*v_5).sq_0).d_00.elems_0);
          X60Qx_49 = X60Qx_743;}
        else {
          X60Qx_49 = 0;}
        NI32 n_10 = X60Qx_49;
        appendU_0_run8hsnpi(buf_7, ((NU64)n_10), 8);
        NI32 i_24 = 0;
        {
          while (i_24 < n_10){
            Value_0_valzr1t4f X60Qx_50;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_50));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_744 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).sq_0).d_00.elems_0, i_24);
            if ((!((*X60Qx_744) == NIM_NIL))){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_50));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_745 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).sq_0).d_00.elems_0, i_24);
              Value_0_valzr1t4f X60Qx_746 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_745)).d_00.v_0));
              X60Qx_50 = X60Qx_746;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_50));
              Value_0_valzr1t4f X60Qx_747 = vNil_0_valzr1t4f();
              X60Qx_50 = X60Qx_747;}
            Value_0_valzr1t4f ev_3 = X60Qx_50;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_50));
            appendVal_0_run8hsnpi(buf_7, (&ev_3), (*(*f_0).desc_0).d_00.elem_0);
            inc_1_I6wjjge_aow2h993l1((&i_24));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_3));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_50));}}
        whileStmtLabel_3: ;}
      else {
        if ((*f_0).isSeq_0){
          NI32 X60Qx_51;
          if ((*v_5).kind_0 == 8){
            NI32 X60Qx_748 = len_3_I83dzei_arecyyj7v((*(*v_5).sq_0).d_00.elems_0);
            X60Qx_51 = X60Qx_748;}
          else {
            X60Qx_51 = 0;}
          NI32 n_11 = X60Qx_51;
          appendU_0_run8hsnpi(buf_7, ((NU64)n_11), 8);
          NB8 X60Qx_749;
          if ((*(*(*f_0).desc_0).d_00.elem_0).d_00.kind_0 == 10){
            X60Qx_749 = NIM_TRUE;}
          else {
            X60Qx_749 = ((*(*(*f_0).desc_0).d_00.elem_0).d_00.kind_0 == 11);}
          NB8 elemIsPod_0 = X60Qx_749;
          NI32 i_25 = 0;
          {
            while (i_25 < n_11){
              Value_0_valzr1t4f X60Qx_52;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_52));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_750 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).sq_0).d_00.elems_0, i_25);
              if ((!((*X60Qx_750) == NIM_NIL))){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_52));
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_751 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).sq_0).d_00.elems_0, i_25);
                Value_0_valzr1t4f X60Qx_752 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_751)).d_00.v_0));
                X60Qx_52 = X60Qx_752;}
              else {
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_52));
                Value_0_valzr1t4f X60Qx_753 = vNil_0_valzr1t4f();
                X60Qx_52 = X60Qx_753;}
              Value_0_valzr1t4f ev_4 = X60Qx_52;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_52));
              seq_0_Incv1wn_arecyyj7v eb_0;
              eQwasMoved_1_I861g1c1_arecyyj7v((&eb_0));
              if (elemIsPod_0){
                eQdestroy_1_Ijx6eoq_arecyyj7v(eb_0);
                seq_0_Incv1wn_arecyyj7v X60Qx_754 = podBytes_0_run8hsnpi((&ev_4), (*(*f_0).desc_0).d_00.elem_0);
                eb_0 = X60Qx_754;}
              else {
                eQdestroy_1_Ijx6eoq_arecyyj7v(eb_0);
                seq_0_Incv1wn_arecyyj7v X60Qx_755 = newSeq_0_Ivbxvoi1_explnj22x1((*f_0).elemSize_0);
                eb_0 = X60Qx_755;
                NU64 X60Qx_756 = valToU64_0_run8hsnpi((&ev_4));
                writeBytes_0_run8hsnpi((&eb_0), 0, X60Qx_756, (*f_0).elemSize_0);}
              NI32 k_0 = 0;
              {
                while (k_0 < (*f_0).elemStride_0){
                  NU8 X60Qx_53;
                  NI32 X60Qx_757 = len_3_Izoe8zv_arecyyj7v(eb_0);
                  if (k_0 < X60Qx_757){
                    NU8* X60Qx_758 = getQ_7_Ig0r1051_arecyyj7v(eb_0, k_0);
                    X60Qx_53 = (*X60Qx_758);}
                  else {
                    X60Qx_53 = ((NU8)0u);}
                  add_0_Ibphvmo_run8hsnpi(buf_7, X60Qx_53);
                  inc_1_I6wjjge_aow2h993l1((&k_0));}}
              whileStmtLabel_5: ;
              inc_1_I6wjjge_aow2h993l1((&i_25));
              eQdestroy_1_Ijx6eoq_arecyyj7v(eb_0);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_4));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_52));}}
          whileStmtLabel_4: ;}
        else {
          if ((*f_0).isArray_0){
            NB8 X60Qx_759;
            if ((*(*(*f_0).desc_0).d_00.elem_0).d_00.kind_0 == 10){
              X60Qx_759 = NIM_TRUE;}
            else {
              X60Qx_759 = ((*(*(*f_0).desc_0).d_00.elem_0).d_00.kind_0 == 11);}
            NB8 elemIsPod_1 = X60Qx_759;
            NI32 i_26 = 0;
            {
              while (i_26 < (*f_0).arrCount_0){
                Value_0_valzr1t4f X60Qx_54;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));
                NB8 X60Qx_760;
                NB8 X60Qx_761;
                NB8 X60Qx_762;
                if ((*v_5).kind_0 == 9){
                  X60Qx_762 = (!((*v_5).arr_0 == NIM_NIL));}
                else {
                  X60Qx_762 = NIM_FALSE;}
                if (X60Qx_762){
                  NI32 X60Qx_763 = len_3_I83dzei_arecyyj7v((*(*v_5).arr_0).d_00.elems_0);
                  X60Qx_761 = (i_26 < X60Qx_763);}
                else {
                  X60Qx_761 = NIM_FALSE;}
                if (X60Qx_761){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_764 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).arr_0).d_00.elems_0, i_26);
                  X60Qx_760 = (!((*X60Qx_764) == NIM_NIL));}
                else {
                  X60Qx_760 = NIM_FALSE;}
                if (X60Qx_760){
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_765 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).arr_0).d_00.elems_0, i_26);
                  Value_0_valzr1t4f X60Qx_766 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_765)).d_00.v_0));
                  X60Qx_54 = X60Qx_766;}
                else {
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));
                  Value_0_valzr1t4f X60Qx_767 = vNil_0_valzr1t4f();
                  X60Qx_54 = X60Qx_767;}
                Value_0_valzr1t4f ev_5 = X60Qx_54;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));
                seq_0_Incv1wn_arecyyj7v eb_1;
                eQwasMoved_1_I861g1c1_arecyyj7v((&eb_1));
                if (elemIsPod_1){
                  eQdestroy_1_Ijx6eoq_arecyyj7v(eb_1);
                  seq_0_Incv1wn_arecyyj7v X60Qx_768 = podBytes_0_run8hsnpi((&ev_5), (*(*f_0).desc_0).d_00.elem_0);
                  eb_1 = X60Qx_768;}
                else {
                  eQdestroy_1_Ijx6eoq_arecyyj7v(eb_1);
                  seq_0_Incv1wn_arecyyj7v X60Qx_769 = newSeq_0_Ivbxvoi1_explnj22x1((*f_0).elemSize_0);
                  eb_1 = X60Qx_769;
                  NU64 X60Qx_770 = valToU64_0_run8hsnpi((&ev_5));
                  writeBytes_0_run8hsnpi((&eb_1), 0, X60Qx_770, (*f_0).elemSize_0);}
                NI32 k_1 = 0;
                {
                  while (k_1 < (*f_0).elemStride_0){
                    NU8 X60Qx_55;
                    NI32 X60Qx_771 = len_3_Izoe8zv_arecyyj7v(eb_1);
                    if (k_1 < X60Qx_771){
                      NU8* X60Qx_772 = getQ_7_Ig0r1051_arecyyj7v(eb_1, k_1);
                      X60Qx_55 = (*X60Qx_772);}
                    else {
                      X60Qx_55 = ((NU8)0u);}
                    add_0_Ibphvmo_run8hsnpi(buf_7, X60Qx_55);
                    inc_1_I6wjjge_aow2h993l1((&k_1));}}
                whileStmtLabel_7: ;
                inc_1_I6wjjge_aow2h993l1((&i_26));
                eQdestroy_1_Ijx6eoq_arecyyj7v(eb_1);
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_5));
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));}}
            whileStmtLabel_6: ;}
          else {
            if ((*f_0).isPod_0){
              {
                seq_0_Incv1wn_arecyyj7v X60Qtmp_130 = podBytes_0_run8hsnpi((&(*v_5)), (*f_0).desc_0);
                openArray_0_Is74e021_explnj22x1 X60Qlf_22 = toOpenArray_1_Itrkyf61_explnj22x1(X60Qtmp_130);
                NI32 X60Qlf_23 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_773 = len_6_Itc4yka_explnj22x1(X60Qlf_22);
                    if (X60Qlf_23 < X60Qx_773){
                      {
                        NU8* X60Qii_10 = getQ_10_Ikgj4ax_explnj22x1(X60Qlf_22, X60Qlf_23);
                        add_0_Ibphvmo_run8hsnpi(buf_7, (*X60Qii_10));}
                      inc_1_I6wjjge_aow2h993l1((&X60Qlf_23));}
                    else {
                      break;}}}
                whileStmtLabel_9: ;
                eQdestroy_1_Ijx6eoq_arecyyj7v(X60Qtmp_130);}
              forStmtLabel_8: ;}
            else {
              if ((*f_0).isEnum_0){
                NI64 X60Qx_774 = asInt_0_valzr1t4f((&(*v_5)));
                appendU_0_run8hsnpi(buf_7, ((NU64)((NU32)((NI32)X60Qx_774))), 4);}
              else {
                NU64 X60Qx_775 = valToU64_0_run8hsnpi((&(*v_5)));
                appendU_0_run8hsnpi(buf_7, X60Qx_775, (*f_0).wireSize_0);}}}}}}}}
Value_0_valzr1t4f scalarFromBits_0_run8hsnpi(NU64 u_2, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_9, NU32 typeSym_3){
  Value_0_valzr1t4f result_49;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
  switch ((*td_9).d_00.kind_0){
    case 8:
    {
      NI32 o_1 = ((NI32)u_2);
      if ((*td_9).d_00.enumLo_0 < 0){
        X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_776 = sizeAlign_1_layptix6a1(td_9, 8);
        NI32 bits_3 = ((NI32)(X60Qx_776.fld_0 * 8));
        NB8 X60Qx_777;
        if (0 < bits_3){
          X60Qx_777 = (bits_3 < 64);}
        else {
          X60Qx_777 = NIM_FALSE;}
        if (X60Qx_777){
          NU64 signBit_0 = ((NU64)(((NU64)1u) << ((NU32)((NI32)(bits_3 - 1)))));
          if ((!(((NU64)(u_2 & signBit_0)) == ((NU64)0u)))){
            o_1 = ((NI32)((NI64)(((NI64)u_2) - ((NI64)((NU64)(((NU64)1u) << ((NU32)bits_3)))))));}}}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
      Value_0_valzr1t4f X60Qx_778 = vEnum_0_valzr1t4f(o_1, typeSym_3);
      result_49 = X60Qx_778;}
    break;
    case 0:
    {
      NI64 X60Qx_56;
      if ((*td_9).d_00.bits_0 <= 0){
        X60Qx_56 = 64;}
      else {
        X60Qx_56 = (*td_9).d_00.bits_0;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
      Value_0_valzr1t4f X60Qx_779 = reinterpToInt_0_flaksyopx1(u_2, X60Qx_56, NIM_TRUE);
      result_49 = X60Qx_779;}
    break;
    case 1:
    {
      NI64 X60Qx_57;
      if ((*td_9).d_00.bits_0 <= 0){
        X60Qx_57 = 64;}
      else {
        X60Qx_57 = (*td_9).d_00.bits_0;}
      NI32 b_5 = X60Qx_57;
      NU64 X60Qx_58;
      if (64 <= b_5){
        X60Qx_58 = u_2;}
      else {
        X60Qx_58 = ((NU64)(u_2 & ((NU64)(((NU64)(((NU64)1u) << ((NU32)b_5))) - ((NU64)1u)))));}
      NU64 m_2 = X60Qx_58;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
      Value_0_valzr1t4f X60Qx_780 = vUInt_0_valzr1t4f(m_2, b_5);
      result_49 = X60Qx_780;}
    break;
    case 2:
    {
      if ((*td_9).d_00.bits_0 == 32){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
        NU32 X60Qx_781 = ((NU32)((NU64)(u_2 & ((NU64)4294967295u))));
        NF32 X60Qx_782;
        copyMem_0_sysvq0asl((&X60Qx_782), (&X60Qx_781), sizeof(NF32));
        Value_0_valzr1t4f X60Qx_783 = vFloat_0_valzr1t4f(((NF64)X60Qx_782), 32);
        result_49 = X60Qx_783;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
        NF64 X60Qx_784;
        copyMem_0_sysvq0asl((&X60Qx_784), (&u_2), sizeof(NF64));
        Value_0_valzr1t4f X60Qx_785 = vFloat_0_valzr1t4f(X60Qx_784, 64);
        result_49 = X60Qx_785;}}
    break;
    case 4:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
      Value_0_valzr1t4f X60Qx_786 = vBool_0_valzr1t4f((!(((NU64)(u_2 & ((NU64)1u))) == ((NU64)0u))));
      result_49 = X60Qx_786;}
    break;
    case 3:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
      Value_0_valzr1t4f X60Qx_787 = vChar_0_valzr1t4f(((NC8)((NU8)((NU64)(u_2 & ((NU64)255u))))));
      result_49 = X60Qx_787;}
    break;
    case 5:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
      Value_0_valzr1t4f X60Qx_788 = reinterpToInt_0_flaksyopx1(u_2, 64, NIM_FALSE);
      result_49 = X60Qx_788;}
    break;
    case 13:
    {
      Value_0_valzr1t4f X60Qx_59;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_59));
      if ((!((*td_9).d_00.elem_0 == NIM_NIL))){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_59));
        Value_0_valzr1t4f X60Qx_789 = scalarFromBits_0_run8hsnpi(u_2, (*td_9).d_00.elem_0, typeSym_3);
        X60Qx_59 = X60Qx_789;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_59));
        Value_0_valzr1t4f X60Qx_790 = vNil_0_valzr1t4f();
        X60Qx_59 = X60Qx_790;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
      result_49 = X60Qx_59;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_59));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_59));}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
      Value_0_valzr1t4f X60Qx_791 = vNil_0_valzr1t4f();
      result_49 = X60Qx_791;}
    break;}
  return result_49;}
X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi podFieldInfo_1_run8hsnpi(NU32 typeSym_4){
  X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi result_50;
  eQwasmovedQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi((&result_50));
  eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(result_50);
  seq_0_In6doa_arecyyj7v X60Qx_792 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
  seq_0_In6doa_arecyyj7v X60Qx_793 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
  result_50 = (X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi){
    .fld_0 = NIM_FALSE, .fld_1 = X60Qx_792, .fld_2 = X60Qx_793}
  ;
  if (((NU32)typeSym_4) == ((NU32)0u)){
    return result_50;}
  LoadResult_0_prorcx25w1 res_11 = tryLoadSymSafe_0_modzy18mg1(typeSym_4);
  NB8 X60Qx_126;
  NB8 X60Qx_794;
  if ((!(res_11.status_0 == 3))){
    X60Qx_794 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_795 = kind_0_nifb6mq6y1(res_11.decl_0);
    X60Qx_794 = (!(X60Qx_795 == 11));}
  if (X60Qx_794){
    X60Qx_126 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_131 = nodeTag_0_run8hsnpi(res_11.decl_0);
    NB8 X60Qx_796 = eqQ_20_sysvq0asl(X60Qtmp_131, (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
    );
    X60Qx_126 = (!X60Qx_796);
    nimStrDestroy(X60Qtmp_131);}
  if (X60Qx_126){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_11);
    return result_50;}
  TypeDecl_0_decqocs071 td_17 = asTypeDecl_0_decqocs071(res_11.decl_0);
  Cursor_0_nifb6mq6y1 b_6 = td_17.body_0;
  eQwasMoved_0_nifb6mq6y1((&td_17.body_0));
  NifKind_0_nif81dubp1 X60Qx_797 = kind_0_nifb6mq6y1(b_6);
  if ((!(X60Qx_797 == 11))){
    eQdestroy_0_nifb6mq6y1((&b_6));
    eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_17));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_11);
    return result_50;}
  string_0_sysvq0asl tag_0 = nodeTag_0_run8hsnpi(b_6);
  NB8 X60Qx_798 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
  );
  if (X60Qx_798){
    Cursor_0_nifb6mq6y1 oc_1 = b_6;
    eQwasMoved_0_nifb6mq6y1((&b_6));
    inc_0_nifb6mq6y1((&oc_1));
    skip_0_nifb6mq6y1((&oc_1));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_799 = kind_0_nifb6mq6y1(oc_1);
        if ((!(X60Qx_799 == 12))){
          NB8 X60Qx_127;
          NifKind_0_nif81dubp1 X60Qx_800 = kind_0_nifb6mq6y1(oc_1);
          if (X60Qx_800 == 11){
            string_0_sysvq0asl X60Qtmp_132 = nodeTag_0_run8hsnpi(oc_1);
            NB8 X60Qx_801 = eqQ_20_sysvq0asl(X60Qtmp_132, (string_0_sysvq0asl){
              .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
            );
            X60Qx_127 = X60Qx_801;
            nimStrDestroy(X60Qtmp_132);}
          else {
            X60Qx_127 = NIM_FALSE;}
          if (X60Qx_127){
            Cursor_0_nifb6mq6y1 fc_2 = eQdup_0_nifb6mq6y1(oc_1);
            inc_0_nifb6mq6y1((&fc_2));
            NU32 nm_1 = ((NU32)0u);
            NB8 X60Qx_802;
            NifKind_0_nif81dubp1 X60Qx_803 = kind_0_nifb6mq6y1(fc_2);
            if (X60Qx_803 == 4){
              X60Qx_802 = NIM_TRUE;}
            else {
              NifKind_0_nif81dubp1 X60Qx_804 = kind_0_nifb6mq6y1(fc_2);
              X60Qx_802 = (X60Qx_804 == 5);}
            if (X60Qx_802){
              NU32 X60Qx_805 = symId_0_nifb6mq6y1(fc_2);
              nm_1 = X60Qx_805;}
            skip_0_nifb6mq6y1((&fc_2));
            skip_0_nifb6mq6y1((&fc_2));
            skip_0_nifb6mq6y1((&fc_2));
            NU32 ts_0 = ((NU32)0u);
            NifKind_0_nif81dubp1 X60Qx_806 = kind_0_nifb6mq6y1(fc_2);
            if (X60Qx_806 == 4){
              NU32 X60Qx_807 = symId_0_nifb6mq6y1(fc_2);
              ts_0 = X60Qx_807;}
            add_0_I34il1q_der823rwr1((&result_50.fld_1), nm_1);
            add_0_I34il1q_der823rwr1((&result_50.fld_2), ts_0);
            eQdestroy_0_nifb6mq6y1((&fc_2));}
          skip_0_nifb6mq6y1((&oc_1));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    eQdestroy_0_nifb6mq6y1((&oc_1));}
  else {
    NB8 X60Qx_808 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
    );
    if (X60Qx_808){
      result_50.fld_0 = NIM_TRUE;
      Cursor_0_nifb6mq6y1 f_15 = b_6;
      eQwasMoved_0_nifb6mq6y1((&b_6));
      inc_0_nifb6mq6y1((&f_15));
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_809 = kind_0_nifb6mq6y1(f_15);
          if ((!(X60Qx_809 == 12))){
            NifKind_0_nif81dubp1 X60Qx_810 = kind_0_nifb6mq6y1(f_15);
            if (X60Qx_810 == 11){
              Cursor_0_nifb6mq6y1 fc_3 = eQdup_0_nifb6mq6y1(f_15);
              NU32 nm_2 = ((NU32)0u);
              string_0_sysvq0asl X60Qtmp_133 = nodeTag_0_run8hsnpi(f_15);
              NB8 X60Qx_811 = eqQ_20_sysvq0asl(X60Qtmp_133, (string_0_sysvq0asl){
                .bytes_0 = 7760642u, .more_0 = NIM_NIL}
              );
              if (X60Qx_811){
                inc_0_nifb6mq6y1((&fc_3));
                NB8 X60Qx_812;
                NifKind_0_nif81dubp1 X60Qx_813 = kind_0_nifb6mq6y1(fc_3);
                if (X60Qx_813 == 4){
                  X60Qx_812 = NIM_TRUE;}
                else {
                  NifKind_0_nif81dubp1 X60Qx_814 = kind_0_nifb6mq6y1(fc_3);
                  X60Qx_812 = (X60Qx_814 == 5);}
                if (X60Qx_812){
                  NU32 X60Qx_815 = symId_0_nifb6mq6y1(fc_3);
                  nm_2 = X60Qx_815;}
                skip_0_nifb6mq6y1((&fc_3));}
              NU32 ts_1 = ((NU32)0u);
              NifKind_0_nif81dubp1 X60Qx_816 = kind_0_nifb6mq6y1(fc_3);
              if (X60Qx_816 == 4){
                NU32 X60Qx_817 = symId_0_nifb6mq6y1(fc_3);
                ts_1 = X60Qx_817;}
              add_0_I34il1q_der823rwr1((&result_50.fld_1), nm_2);
              add_0_I34il1q_der823rwr1((&result_50.fld_2), ts_1);
              nimStrDestroy(X60Qtmp_133);
              eQdestroy_0_nifb6mq6y1((&fc_3));}
            skip_0_nifb6mq6y1((&f_15));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      eQdestroy_0_nifb6mq6y1((&f_15));}}
  nimStrDestroy(tag_0);
  eQdestroy_0_nifb6mq6y1((&b_6));
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_17));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_11);
  return result_50;
  nimStrDestroy(tag_0);
  eQdestroy_0_nifb6mq6y1((&b_6));
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_17));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_11);
  return result_50;}
void grantNoDerefs_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_3){
  if (e_3 == NIM_NIL){
    return;}
  string_0_sysvq0asl X60Qtmp_134 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I8845991054942562031_intzsnzax)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 dbg_0 = eqQ_20_sysvq0asl(X60Qtmp_134, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  NI32 i_27 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_818;
      NI32 X60Qx_819 = len_3_In63jw61_aow7lb5cq1((*e_3).d_00.args_0);
      if (i_27 < X60Qx_819){
        NI32 X60Qx_820 = len_3_Irjnvku_run8hsnpi((*e_3).d_00.noDerefOffs_0);
        X60Qx_818 = (i_27 < X60Qx_820);}
      else {
        X60Qx_818 = NIM_FALSE;}
      if (X60Qx_818){
        {
          WireField_0_run8hsnpi* X60Qx_821 = getQ_7_Iko57h9_aow7lb5cq1((*e_3).d_00.args_0, i_27);
          WireField_0_run8hsnpi X60QconstRefTemp_0 = (*X60Qx_821);
          WireField_0_run8hsnpi f_16 = eQdupQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60QconstRefTemp_0));
          NB8 X60Qx_822;
          NB8 X60Qx_823;
          if ((!f_16.isArenaPtr_0)){
            X60Qx_823 = NIM_TRUE;}
          else {
            X60Qx_823 = (f_16.desc_0 == NIM_NIL);}
          if (X60Qx_823){
            X60Qx_822 = NIM_TRUE;}
          else {
            X60Qx_822 = (((NU32)f_16.typeSym_0) == ((NU32)0u));}
          if (X60Qx_822){
            inc_1_I6wjjge_aow2h993l1((&i_27));
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_16));
            goto continueLabel_1;}
          X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi info_2 = podFieldInfo_1_run8hsnpi(f_16.typeSym_0);
          seq_0_Ift2sne_aow7lb5cq1 offs_2 = fieldOffsets_0_layptix6a1(f_16.desc_0, 8);
          NB8 X60Qx_824;
          if ((!(info_2.fld_1.len_0 == (*f_16.desc_0).d_00.fields_0.len_0))){
            X60Qx_824 = NIM_TRUE;}
          else {
            X60Qx_824 = (!(offs_2.len_0 == (*f_16.desc_0).d_00.fields_0.len_0));}
          if (X60Qx_824){
            inc_1_I6wjjge_aow2h993l1((&i_27));
            eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_2);
            eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_2);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_16));
            goto continueLabel_1;}
          NI32 j_0 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_825 = len_3_I5m68tr1_aow7lb5cq1((*f_16.desc_0).d_00.fields_0);
              if (j_0 < X60Qx_825){
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_826 = getQ_7_I45w7c91_aow7lb5cq1((*f_16.desc_0).d_00.fields_0, j_0);
                if ((*(*X60Qx_826)).d_00.kind_0 == 5){
                  NU32* X60Qx_827 = getQ_7_I2v00yv1_arecyyj7v(info_2.fld_1, j_0);
                  X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 X60Qtmptup_11 = fieldVerdict_0_der823rwr1((*e_3).d_00.sym_0, i_27, (*X60Qx_827));
                  AnVerdict_0_der823rwr1 v_8 = X60Qtmptup_11.fld_0;
                  AnGiveUp_0_der823rwr1 why_1 = X60Qtmptup_11.fld_1;
                  string_0_sysvq0asl at_0 = X60Qtmptup_11.fld_2;
                  nimStrWasMoved((&X60Qtmptup_11.fld_2));
                  NU32* X60Qx_828 = getQ_7_I2v00yv1_arecyyj7v(info_2.fld_1, j_0);
                  NB8 X60Qx_829 = fieldNeverTouched_0_der823rwr1((*e_3).d_00.sym_0, i_27, (*X60Qx_828));
                  if (X60Qx_829){
                    seq_0_Ift2sne_aow7lb5cq1* X60Qx_830 = getQ_7_Iurb46i_aow7lb5cq1((*e_3).d_00.noDerefOffs_0, i_27);
                    NI32* X60Qx_831 = getQ_7_Ir8kccm_aow7lb5cq1(offs_2, j_0);
                    add_0_I8kd4i4_aow7lb5cq1(X60Qx_830, (*X60Qx_831));}
                  else {
                    if (dbg_0){
                      string_0_sysvq0asl* X60Qx_832 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*e_3).d_00.sym_0);
                      string_0_sysvq0asl cn_0 = nimStrDup((*X60Qx_832));
                      extractBasename_1_symkyk35i1((&cn_0));
                      NU32* X60Qx_833 = getQ_7_I2v00yv1_arecyyj7v(info_2.fld_1, j_0);
                      string_0_sysvq0asl* X60Qx_834 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*X60Qx_833));
                      string_0_sysvq0asl fn_2 = nimStrDup((*X60Qx_834));
                      extractBasename_1_symkyk35i1((&fn_2));
                      string_0_sysvq0asl X60Qdesugar_29 = dollarQ_2_sysvq0asl(i_27);
                      NI32 X60Qx_835 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1847599358u, .more_0 = (&strlit_0_I17300657558726488198_intzsnzax)}
                      );
                      NI32 X60Qx_836 = len_4_sysvq0asl(cn_0);
                      NI32 X60Qx_837 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I4311268661432640709_run8hsnpi)}
                      );
                      NI32 X60Qx_838 = len_4_sysvq0asl(X60Qdesugar_29);
                      NI32 X60Qx_839 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 3022850u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_840 = len_4_sysvq0asl(fn_2);
                      NI32 X60Qx_841 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_30 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_835 + X60Qx_836)) + X60Qx_837)) + X60Qx_838)) + X60Qx_839)) + X60Qx_840)) + X60Qx_841)));
                      add_2_sysvq0asl((&X60Qdesugar_30), (string_0_sysvq0asl){
                        .bytes_0 = 1847599358u, .more_0 = (&strlit_0_I17300657558726488198_intzsnzax)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_30), cn_0);
                      add_2_sysvq0asl((&X60Qdesugar_30), (string_0_sysvq0asl){
                        .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I4311268661432640709_run8hsnpi)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_30), X60Qdesugar_29);
                      add_2_sysvq0asl((&X60Qdesugar_30), (string_0_sysvq0asl){
                        .bytes_0 = 3022850u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_30), fn_2);
                      add_2_sysvq0asl((&X60Qdesugar_30), (string_0_sysvq0asl){
                        .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl m_3 = X60Qdesugar_30;
                      nimStrWasMoved((&X60Qdesugar_30));
                      if (v_8 == 1){
                        add_2_sysvq0asl((&m_3), (string_0_sysvq0asl){
                          .bytes_0 = 1431262462u, .more_0 = (&strlit_0_I7498181021040919538_run8hsnpi)}
                        );}
                      else {
                        string_0_sysvq0asl X60Qtmp_136 = giveUpName_0_der823rwr1(why_1);
                        string_0_sysvq0asl X60Qtmp_135 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1263425022u, .more_0 = (&strlit_0_I4863082586268738407_run8hsnpi)}
                        , X60Qtmp_136);
                        add_2_sysvq0asl((&m_3), X60Qtmp_135);
                        NI32 X60Qx_842 = len_4_sysvq0asl(at_0);
                        if (0 < X60Qx_842){
                          string_0_sysvq0asl X60Qtmp_137 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 1952522494u, .more_0 = (&strlit_0_I12933864966599503538_der823rwr1)}
                          , at_0);
                          add_2_sysvq0asl((&m_3), X60Qtmp_137);
                          nimStrDestroy(X60Qtmp_137);}
                        add_2_sysvq0asl((&m_3), (string_0_sysvq0asl){
                          .bytes_0 = 1881678078u, .more_0 = (&strlit_0_I5868316469075155783_run8hsnpi)}
                        );
                        nimStrDestroy(X60Qtmp_135);
                        nimStrDestroy(X60Qtmp_136);}
                      string_0_sysvq0asl X60Qtmp_138 = ampQ_0_sysvq0asl(m_3, (string_0_sysvq0asl){
                        .bytes_0 = 2561u, .more_0 = NIM_NIL}
                      );
                      write_0_syn1lfpjv(stderr, X60Qtmp_138);
                      nimStrDestroy(X60Qtmp_138);
                      nimStrDestroy(m_3);
                      nimStrDestroy(X60Qdesugar_30);
                      nimStrDestroy(X60Qdesugar_29);
                      nimStrDestroy(fn_2);
                      nimStrDestroy(cn_0);}}
                  nimStrDestroy(at_0);
                  eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_run8hsnpi(X60Qtmptup_11);}
                inc_1_I6wjjge_aow2h993l1((&j_0));}
              else {
                break;}}}
          whileStmtLabel_2: ;
          inc_1_I6wjjge_aow2h993l1((&i_27));
          eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_2);
          eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_2);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_16));}
        continueLabel_1: ;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(X60Qtmp_134);}
NB8 hasNoDerefGrant_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_4){
  NB8 result_51;
  result_51 = NIM_FALSE;
  if (e_4 == NIM_NIL){
    return result_51;}
  NI32 i_29 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_843 = len_3_Irjnvku_run8hsnpi((*e_4).d_00.noDerefOffs_0);
      if (i_29 < X60Qx_843){
        seq_0_Ift2sne_aow7lb5cq1* X60Qx_844 = getQ_7_Iurb46i_aow7lb5cq1((*e_4).d_00.noDerefOffs_0, i_29);
        if (0 < (*X60Qx_844).len_0){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_29));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_51;}
Value_0_valzr1t4f synthPodValue_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v buf_8, NI32 off_4, NU32 typeSym_5, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_10){
  Value_0_valzr1t4f result_52;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_52));
  X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi info_3 = podFieldInfo_1_run8hsnpi(typeSym_5);
  seq_0_Ift2sne_aow7lb5cq1 offs_3 = fieldOffsets_0_layptix6a1(td_10, 8);
  void* X60Qx_845 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_139 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_845);
  seq_0_In6doa_arecyyj7v X60Qx_846 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_847 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  (*X60Qtmp_139) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
      .typeSym_0 = typeSym_5, .names_0 = X60Qx_846, .cells_0 = X60Qx_847}}
  ;
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_3 = X60Qtmp_139;
  NI32 i_30 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_848;
      NI32 X60Qx_849 = len_3_I5m68tr1_aow7lb5cq1((*td_10).d_00.fields_0);
      if (i_30 < X60Qx_849){
        NI32 X60Qx_850 = len_3_I0v1j8d_aow7lb5cq1(offs_3);
        X60Qx_848 = (i_30 < X60Qx_850);}
      else {
        X60Qx_848 = NIM_FALSE;}
      if (X60Qx_848){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_851 = getQ_7_I45w7c91_aow7lb5cq1((*td_10).d_00.fields_0, i_30);
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* fd_5 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qx_851));
        NU32 X60Qx_60;
        NI32 X60Qx_852 = len_3_I6y2imo_arecyyj7v(info_3.fld_1);
        if (i_30 < X60Qx_852){
          NU32* X60Qx_853 = getQ_7_I2v00yv1_arecyyj7v(info_3.fld_1, i_30);
          X60Qx_60 = (*X60Qx_853);}
        else {
          X60Qx_60 = ((NU32)0u);}
        NU32 nm_3 = X60Qx_60;
        Value_0_valzr1t4f cv_2;
        eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_2));
        NB8 X60Qx_854;
        NB8 X60Qx_855;
        if ((*fd_5).d_00.kind_0 == 10){
          X60Qx_855 = NIM_TRUE;}
        else {
          X60Qx_855 = ((*fd_5).d_00.kind_0 == 11);}
        if (X60Qx_855){
          X60Qx_854 = NIM_TRUE;}
        else {
          NB8 X60Qx_856;
          NB8 X60Qx_857;
          if ((*fd_5).d_00.kind_0 == 13){
            X60Qx_857 = (!((*fd_5).d_00.elem_0 == NIM_NIL));}
          else {
            X60Qx_857 = NIM_FALSE;}
          if (X60Qx_857){
            NB8 X60Qx_858;
            if ((*(*fd_5).d_00.elem_0).d_00.kind_0 == 10){
              X60Qx_858 = NIM_TRUE;}
            else {
              X60Qx_858 = ((*(*fd_5).d_00.elem_0).d_00.kind_0 == 11);}
            X60Qx_856 = X60Qx_858;}
          else {
            X60Qx_856 = NIM_FALSE;}
          X60Qx_854 = X60Qx_856;}
        if (X60Qx_854){
          NU32 X60Qx_61;
          NI32 X60Qx_859 = len_3_I6y2imo_arecyyj7v(info_3.fld_2);
          if (i_30 < X60Qx_859){
            NU32* X60Qx_860 = getQ_7_I2v00yv1_arecyyj7v(info_3.fld_2, i_30);
            X60Qx_61 = (*X60Qx_860);}
          else {
            X60Qx_61 = ((NU32)0u);}
          NU32 fts_2 = X60Qx_61;
          X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_62;
          eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&X60Qx_62));
          if ((*fd_5).d_00.kind_0 == 13){
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qx_62);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_861 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*fd_5).d_00.elem_0);
            X60Qx_62 = X60Qx_861;}
          else {
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qx_62);
            X60Qx_62 = fd_5;
            eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&fd_5));}
          X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* ad_0 = X60Qx_62;
          eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&X60Qx_62));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_2));
          NI32* X60Qx_862 = getQ_7_Ir8kccm_aow7lb5cq1(offs_3, i_30);
          Value_0_valzr1t4f X60Qx_863 = synthPodValue_0_run8hsnpi(buf_8, ((NI32)(off_4 + (*X60Qx_862))), fts_2, ad_0);
          cv_2 = X60Qx_863;
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(ad_0);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qx_62);}
        else {
          NU32 X60Qx_63;
          NI32 X60Qx_864 = len_3_I6y2imo_arecyyj7v(info_3.fld_2);
          if (i_30 < X60Qx_864){
            NU32* X60Qx_865 = getQ_7_I2v00yv1_arecyyj7v(info_3.fld_2, i_30);
            X60Qx_63 = (*X60Qx_865);}
          else {
            X60Qx_63 = ((NU32)0u);}
          NU32 sts_0 = X60Qx_63;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_2));
          NI32* X60Qx_866 = getQ_7_Ir8kccm_aow7lb5cq1(offs_3, i_30);
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_867 = sizeAlign_1_layptix6a1(fd_5, 8);
          NU64 X60Qx_868 = readBytes_0_run8hsnpi(buf_8, ((NI32)(off_4 + (*X60Qx_866))), X60Qx_867.fld_0);
          Value_0_valzr1t4f X60Qx_869 = scalarFromBits_0_run8hsnpi(X60Qx_868, fd_5, sts_0);
          cv_2 = X60Qx_869;}
        add_0_I34il1q_der823rwr1((&(*box_3).d_00.names_0), nm_3);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_870 = newCell_0_valzr1t4f((&cv_2));
        add_0_Ijpw0mu_flaksyopx1((&(*box_3).d_00.cells_0), X60Qx_870);
        inc_1_I6wjjge_aow2h993l1((&i_30));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_2));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_5);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  Value_0_valzr1t4f X60Qx_64;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_64));
  NB8 X60Qx_871;
  if (info_3.fld_0){
    X60Qx_871 = NIM_TRUE;}
  else {
    X60Qx_871 = ((*td_10).d_00.kind_0 == 11);}
  if (X60Qx_871){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_64));
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_140 = box_3;
    eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&box_3));
    X60Qx_64 = (Value_0_valzr1t4f){
      .kind_0 = 10, .obj_0 = X60Qtmp_140}
    ;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_64));
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_141 = box_3;
    eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&box_3));
    X60Qx_64 = (Value_0_valzr1t4f){
      .kind_0 = 11, .obj_0 = X60Qtmp_141}
    ;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_52));
  result_52 = X60Qx_64;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_64));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_64));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_3);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_3);
  eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_3);
  return result_52;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_64));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_3);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_3);
  eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_3);
  return result_52;}
Value_0_valzr1t4f unpackReturn_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v buf_9, WireField_0_run8hsnpi* f_1){
  Value_0_valzr1t4f result_53;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
  if ((*f_1).isComposite_0){
    NI32 pos_1 = 0;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
    Value_0_valzr1t4f X60Qx_872 = readVal_0_run8hsnpi(buf_9, (&pos_1), (*f_1).desc_0, (*f_1).typeSym_0);
    result_53 = X60Qx_872;}
  else {
    if ((*f_1).isString_0){
      NU64 X60Qx_873 = readBytes_0_run8hsnpi(buf_9, 0, 8);
      NI32 n_12 = ((NI32)X60Qx_873);
      string_0_sysvq0asl s_35 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NI32 i_31 = 0;
      {
        while (i_31 < n_12){
          NU8* X60Qx_874 = getQ_7_Ig0r1051_arecyyj7v(buf_9, ((NI32)(8 + i_31)));
          add_1_sysvq0asl((&s_35), ((NC8)((NU8)(*X60Qx_874))));
          inc_1_I6wjjge_aow2h993l1((&i_31));}}
      whileStmtLabel_0: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
      Value_0_valzr1t4f X60Qx_875 = vStr_0_valzr1t4f(s_35);
      result_53 = X60Qx_875;
      nimStrDestroy(s_35);}
    else {
      NB8 X60Qx_876;
      if ((*f_1).isSeq_0){
        X60Qx_876 = (*f_1).elemVarLen_0;}
      else {
        X60Qx_876 = NIM_FALSE;}
      if (X60Qx_876){
        NI32 pos_2 = 0;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
        Value_0_valzr1t4f X60Qx_877 = readVal_0_run8hsnpi(buf_9, (&pos_2), (*f_1).desc_0, ((NU32)0u));
        result_53 = X60Qx_877;}
      else {
        if ((*f_1).isSeq_0){
          NU64 X60Qx_878 = readBytes_0_run8hsnpi(buf_9, 0, 8);
          NI32 n_13 = ((NI32)X60Qx_878);
          NB8 X60Qx_879;
          if ((*(*(*f_1).desc_0).d_00.elem_0).d_00.kind_0 == 10){
            X60Qx_879 = NIM_TRUE;}
          else {
            X60Qx_879 = ((*(*(*f_1).desc_0).d_00.elem_0).d_00.kind_0 == 11);}
          NB8 elemIsPod_2 = X60Qx_879;
          void* X60Qx_880 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
          X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_142 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_880);
          seq_0_Iw8xl5b1_arecyyj7v X60Qx_881 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
          (*X60Qtmp_142) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
            .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
              .elems_0 = X60Qx_881, .flat_0 = NIM_NIL}}
          ;
          X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_1 = X60Qtmp_142;
          NI32 i_32 = 0;
          {
            while (i_32 < n_13){
              NI32 eoff_0 = ((NI32)(8 + ((NI32)(i_32 * (*f_1).elemStride_0))));
              Value_0_valzr1t4f ev_6;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_6));
              if (elemIsPod_2){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_6));
                Value_0_valzr1t4f X60Qx_882 = synthPodValue_0_run8hsnpi(buf_9, eoff_0, (*f_1).elemTypeSym_0, (*(*f_1).desc_0).d_00.elem_0);
                ev_6 = X60Qx_882;}
              else {
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_6));
                NU64 X60Qx_883 = readBytes_0_run8hsnpi(buf_9, eoff_0, (*f_1).elemSize_0);
                Value_0_valzr1t4f X60Qx_884 = scalarFromBits_0_run8hsnpi(X60Qx_883, (*(*f_1).desc_0).d_00.elem_0, ((NU32)0u));
                ev_6 = X60Qx_884;}
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_885 = newCell_0_valzr1t4f((&ev_6));
              add_0_Ijpw0mu_flaksyopx1((&(*sb_1).d_00.elems_0), X60Qx_885);
              inc_1_I6wjjge_aow2h993l1((&i_32));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_6));}}
          whileStmtLabel_1: ;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
          X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_143 = sb_1;
          eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi((&sb_1));
          result_53 = (Value_0_valzr1t4f){
            .kind_0 = 8, .sq_0 = X60Qtmp_143}
          ;
          eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(sb_1);}
        else {
          if ((*f_1).isArray_0){
            NB8 X60Qx_886;
            if ((*(*(*f_1).desc_0).d_00.elem_0).d_00.kind_0 == 10){
              X60Qx_886 = NIM_TRUE;}
            else {
              X60Qx_886 = ((*(*(*f_1).desc_0).d_00.elem_0).d_00.kind_0 == 11);}
            NB8 elemIsPod_3 = X60Qx_886;
            void* X60Qx_887 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1));
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_144 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_887);
            seq_0_Iw8xl5b1_arecyyj7v X60Qx_888 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
            (*X60Qtmp_144) = (X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1){
              .r_00 = 0, .d_00 = (ArrBox_Obj_0_valzr1t4f){
                .elems_0 = X60Qx_888, .lo_0 = 0, .flat_0 = NIM_NIL}}
            ;
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* ab_1 = X60Qtmp_144;
            NI32 i_33 = 0;
            {
              while (i_33 < (*f_1).arrCount_0){
                NI32 eoff_1 = ((NI32)(i_33 * (*f_1).elemStride_0));
                Value_0_valzr1t4f ev_7;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_7));
                if (elemIsPod_3){
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_7));
                  Value_0_valzr1t4f X60Qx_889 = synthPodValue_0_run8hsnpi(buf_9, eoff_1, (*f_1).elemTypeSym_0, (*(*f_1).desc_0).d_00.elem_0);
                  ev_7 = X60Qx_889;}
                else {
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_7));
                  NU64 X60Qx_890 = readBytes_0_run8hsnpi(buf_9, eoff_1, (*f_1).elemSize_0);
                  Value_0_valzr1t4f X60Qx_891 = scalarFromBits_0_run8hsnpi(X60Qx_890, (*(*f_1).desc_0).d_00.elem_0, ((NU32)0u));
                  ev_7 = X60Qx_891;}
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_892 = newCell_0_valzr1t4f((&ev_7));
                add_0_Ijpw0mu_flaksyopx1((&(*ab_1).d_00.elems_0), X60Qx_892);
                inc_1_I6wjjge_aow2h993l1((&i_33));
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_7));}}
            whileStmtLabel_2: ;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_145 = ab_1;
            eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&ab_1));
            result_53 = (Value_0_valzr1t4f){
              .kind_0 = 9, .arr_0 = X60Qtmp_145}
            ;
            eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(ab_1);}
          else {
            if ((*f_1).isForeignPtr_0){
              NU64 a_5 = readBytes_0_run8hsnpi(buf_9, 0, 8);
              if (a_5 == ((NU64)0u)){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
                Value_0_valzr1t4f X60Qx_893 = vPtrLoc_0_valzr1t4f(NIM_NIL);
                result_53 = X60Qx_893;}
              else {
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
                void* X60Qx_894 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
                X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_146 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_894);
                (*X60Qtmp_146) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
                  .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
                    .kind_0 = 6, .haddr_0 = a_5, .hlen_0 = -1}}
                ;
                Value_0_valzr1t4f X60Qx_895 = vPtrReg_0_valzr1t4f(X60Qtmp_146, ((NI32)0), ((NI16)8), 0);
                result_53 = X60Qx_895;
                eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qtmp_146);}}
            else {
              if ((*f_1).isPod_0){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
                Value_0_valzr1t4f X60Qx_896 = synthPodValue_0_run8hsnpi(buf_9, 0, (*f_1).typeSym_0, (*f_1).desc_0);
                result_53 = X60Qx_896;}
              else {
                if ((*f_1).isEnum_0){
                  NU64 X60Qx_897 = readBytes_0_run8hsnpi(buf_9, 0, 4);
                  NI32 o_2 = ((NI32)((NI32)((NU64)(X60Qx_897 & ((NU64)4294967295u)))));
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
                  Value_0_valzr1t4f X60Qx_898 = vEnum_0_valzr1t4f(o_2, (*f_1).enumSym_0);
                  result_53 = X60Qx_898;}
                else {
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_53));
                  NU64 X60Qx_899 = readBytes_0_run8hsnpi(buf_9, 0, (*f_1).wireSize_0);
                  Value_0_valzr1t4f X60Qx_900 = scalarFromBits_0_run8hsnpi(X60Qx_899, (*f_1).desc_0, ((NU32)0u));
                  result_53 = X60Qx_900;}}}}}}}}
  return result_53;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* argObjBox_0_run8hsnpi(Value_0_valzr1t4f* v_6){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* result_54;
  eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&result_54));
  switch ((*v_6).kind_0){
    case 11:
    case 10:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_54);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_901 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((*v_6).obj_0);
      result_54 = X60Qx_901;}
    break;
    case 12:
    {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_65;
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_65));
      NB8 X60Qx_902;
      if ((!((*v_6).rf_0 == NIM_NIL))){
        NB8 X60Qx_903;
        if ((*(*v_6).rf_0).d_00.v_0.kind_0 == 11){
          X60Qx_903 = NIM_TRUE;}
        else {
          X60Qx_903 = ((*(*v_6).rf_0).d_00.v_0.kind_0 == 10);}
        X60Qx_902 = X60Qx_903;}
      else {
        X60Qx_902 = NIM_FALSE;}
      if (X60Qx_902){
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_65);
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_904 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((*(*v_6).rf_0).d_00.v_0.obj_0);
        X60Qx_65 = X60Qx_904;}
      else {
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_65);
        X60Qx_65 = NIM_NIL;}
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_54);
      result_54 = X60Qx_65;
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_65));
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_65);}
    break;
    case 13:
    {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_66;
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_66));
      NB8 X60Qx_905;
      if ((!((*v_6).loc_0 == NIM_NIL))){
        NB8 X60Qx_906;
        if ((*(*v_6).loc_0).d_00.v_0.kind_0 == 11){
          X60Qx_906 = NIM_TRUE;}
        else {
          X60Qx_906 = ((*(*v_6).loc_0).d_00.v_0.kind_0 == 10);}
        X60Qx_905 = X60Qx_906;}
      else {
        X60Qx_905 = NIM_FALSE;}
      if (X60Qx_905){
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_66);
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_907 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((*(*v_6).loc_0).d_00.v_0.obj_0);
        X60Qx_66 = X60Qx_907;}
      else {
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_66);
        X60Qx_66 = NIM_NIL;}
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_54);
      result_54 = X60Qx_66;
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_66));
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_66);}
    break;
    default:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_54);
      result_54 = NIM_NIL;}
    break;}
  return result_54;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* argArrBox_0_run8hsnpi(Value_0_valzr1t4f* v_7){
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* result_55;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&result_55));
  switch ((*v_7).kind_0){
    case 9:
    {
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_55);
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_908 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((*v_7).arr_0);
      result_55 = X60Qx_908;}
    break;
    case 13:
    {
      NB8 X60Qx_909;
      NB8 X60Qx_910;
      if ((!((*v_7).loc_0 == NIM_NIL))){
        X60Qx_910 = ((*(*v_7).loc_0).d_00.v_0.kind_0 == 9);}
      else {
        X60Qx_910 = NIM_FALSE;}
      if (X60Qx_910){
        NI32 X60Qx_911 = base_0_valzr1t4f((&(*v_7)));
        X60Qx_909 = (X60Qx_911 == 0);}
      else {
        X60Qx_909 = NIM_FALSE;}
      if (X60Qx_909){
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_55);
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_912 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((*(*v_7).loc_0).d_00.v_0.arr_0);
        result_55 = X60Qx_912;}
      else {
        NB8 X60Qx_128;
        NB8 X60Qx_129;
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_147 = region_0_valzr1t4f((&(*v_7)));
        if ((!(X60Qtmp_147 == NIM_NIL))){
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_148 = region_0_valzr1t4f((&(*v_7)));
          X60Qx_129 = ((*X60Qtmp_148).d_00.kind_0 == 2);
          eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qtmp_148);}
        else {
          X60Qx_129 = NIM_FALSE;}
        if (X60Qx_129){
          NI32 X60Qx_913 = foff_0_valzr1t4f((&(*v_7)));
          X60Qx_128 = (X60Qx_913 == ((NI32)0));}
        else {
          X60Qx_128 = NIM_FALSE;}
        if (X60Qx_128){
          eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_55);
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_149 = region_0_valzr1t4f((&(*v_7)));
          X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_914 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((*X60Qtmp_149).d_00.abox_0);
          result_55 = X60Qx_914;
          eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qtmp_149);}
        else {
          eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_55);
          result_55 = NIM_NIL;}
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qtmp_147);}}
    break;
    case 12:
    {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_67;
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_67));
      NB8 X60Qx_915;
      if ((!((*v_7).rf_0 == NIM_NIL))){
        X60Qx_915 = ((*(*v_7).rf_0).d_00.v_0.kind_0 == 9);}
      else {
        X60Qx_915 = NIM_FALSE;}
      if (X60Qx_915){
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_67);
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_916 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((*(*v_7).rf_0).d_00.v_0.arr_0);
        X60Qx_67 = X60Qx_916;}
      else {
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_67);
        X60Qx_67 = NIM_NIL;}
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_55);
      result_55 = X60Qx_67;
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_67));
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_67);}
    break;
    default:
    {
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_55);
      result_55 = NIM_NIL;}
    break;}
  return result_55;}
NB8 applyWritebackArray_0_run8hsnpi(Value_0_valzr1t4f* arg_0, seq_0_Incv1wn_arecyyj7v buf_10, NI32 off_5, WireField_0_run8hsnpi* f_2){
  NB8 result_56;
  NB8 X60Qx_917;
  if ((*f_2).desc_0 == NIM_NIL){
    X60Qx_917 = NIM_TRUE;}
  else {
    X60Qx_917 = ((*(*f_2).desc_0).d_00.elem_0 == NIM_NIL);}
  if (X60Qx_917){
    return NIM_FALSE;}
  NB8 X60Qx_918;
  NB8 X60Qx_919;
  if ((*f_2).arrCount_0 <= 0){
    X60Qx_919 = NIM_TRUE;}
  else {
    X60Qx_919 = ((*f_2).elemSize_0 <= 0);}
  if (X60Qx_919){
    X60Qx_918 = NIM_TRUE;}
  else {
    X60Qx_918 = ((*f_2).elemStride_0 < (*f_2).elemSize_0);}
  if (X60Qx_918){
    return NIM_FALSE;}
  NB8 X60Qx_920;
  if (off_5 < 0){
    X60Qx_920 = NIM_TRUE;}
  else {
    X60Qx_920 = (buf_10.len_0 < ((NI32)(off_5 + ((NI32)((*f_2).arrCount_0 * (*f_2).elemStride_0)))));}
  if (X60Qx_920){
    return NIM_FALSE;}
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* box_4 = argArrBox_0_run8hsnpi((&(*arg_0)));
  if (box_4 == NIM_NIL){
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_4);
    return NIM_FALSE;}
  if ((!((*box_4).d_00.elems_0.len_0 == (*f_2).arrCount_0))){
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_4);
    return NIM_FALSE;}
  seq_0_I50urnw_croph25r5 vals_0 = newSeqUninit_0_I8oufjc_croph25r5(0);
  NI32 i_34 = 0;
  {
    while (i_34 < (*f_2).arrCount_0){
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_921 = getQ_7_Ii14ync1_arecyyj7v((*box_4).d_00.elems_0, i_34);
      if ((*X60Qx_921) == NIM_NIL){
        eQdestroy_1_Inxd7ue1_croph25r5(vals_0);
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_4);
        return NIM_FALSE;}
      NU64 X60Qx_922 = readBytes_0_run8hsnpi(buf_10, ((NI32)(off_5 + ((NI32)(i_34 * (*f_2).elemStride_0)))), (*f_2).elemSize_0);
      Value_0_valzr1t4f nv_0 = scalarFromBits_0_run8hsnpi(X60Qx_922, (*(*f_2).desc_0).d_00.elem_0, ((NU32)0u));
      if (nv_0.kind_0 == 0){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
        eQdestroy_1_Inxd7ue1_croph25r5(vals_0);
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_4);
        return NIM_FALSE;}
      Value_0_valzr1t4f X60Qtmp_150 = nv_0;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
      add_0_Itre92n_intzsnzax((&vals_0), X60Qtmp_150);
      inc_1_I6wjjge_aow2h993l1((&i_34));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));}}
  whileStmtLabel_0: ;
  i_34 = 0;
  {
    while (i_34 < (*f_2).arrCount_0){
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_923 = getQ_7_Ii14ync1_arecyyj7v((*box_4).d_00.elems_0, i_34);
      Value_0_valzr1t4f* X60Qlhs_151 = (&(*(*X60Qx_923)).d_00.v_0);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_924 = getQ_7_Ii14ync1_arecyyj7v((*box_4).d_00.elems_0, i_34);
      Value_0_valzr1t4f X60Qlhs_152 = (*(*X60Qx_924)).d_00.v_0;
      Value_0_valzr1t4f* X60Qx_925 = getQ_7_Ine8yq71_intzsnzax(vals_0, i_34);
      Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_925);
      Value_0_valzr1t4f X60Qx_926 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
      (*X60Qlhs_151) = X60Qx_926;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_152));
      inc_1_I6wjjge_aow2h993l1((&i_34));}}
  whileStmtLabel_1: ;
  result_56 = NIM_TRUE;
  eQdestroy_1_Inxd7ue1_croph25r5(vals_0);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_4);
  return result_56;
  eQdestroy_1_Inxd7ue1_croph25r5(vals_0);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_4);
  return result_56;}
void applyWriteback_0_run8hsnpi(Value_0_valzr1t4f* arg_1, seq_0_Incv1wn_arecyyj7v buf_11, NI32 off_6, WireField_0_run8hsnpi* f_3){
  if ((*f_3).isPod_0){
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_5 = argObjBox_0_run8hsnpi((&(*arg_1)));
    if (box_5 == NIM_NIL){
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
      return;}
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_4 = flObjRegion_0_flaksyopx1(box_5);
    if (r_4 == NIM_NIL){
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_4);
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
      return;}
    NI32 k_2 = 0;
    {
      while (k_2 < (*f_3).wireSize_0){
        NU8* X60Qx_927 = getQ_7_Ig0r1051_arecyyj7v(buf_11, ((NI32)(off_6 + k_2)));
        setByteAt_0_flaksyopx1(r_4, k_2, (*X60Qx_927));
        inc_1_I6wjjge_aow2h993l1((&k_2));}}
    whileStmtLabel_0: ;
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_4);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);}
  else {
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_0 = NIM_NIL;
    NB8 X60Qx_928;
    if ((*arg_1).kind_0 == 13){
      X60Qx_928 = (!((*arg_1).loc_0 == NIM_NIL));}
    else {
      X60Qx_928 = NIM_FALSE;}
    if (X60Qx_928){
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi(cell_0);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_929 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi((*arg_1).loc_0);
      cell_0 = X60Qx_929;}
    if ((!(cell_0 == NIM_NIL))){
      Value_0_valzr1t4f* X60Qlhs_153 = (&(*cell_0).d_00.v_0);
      NU64 X60Qx_930 = readBytes_0_run8hsnpi(buf_11, off_6, (*f_3).wireSize_0);
      Value_0_valzr1t4f X60Qlhs_154 = scalarFromBits_0_run8hsnpi(X60Qx_930, (*f_3).desc_0, ((NU32)0u));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_153)));
      (*X60Qlhs_153) = X60Qlhs_154;}
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi(cell_0);}}
NB8 applyWritebackArena_0_run8hsnpi(Value_0_valzr1t4f* arg_2, seq_0_Incv1wn_arecyyj7v buf_12, NI32 off_7, WireField_0_run8hsnpi* f_4, ArenaMat_0_arecyyj7v* m_1){
  NB8 result_57;
  if ((*f_4).desc_0 == NIM_NIL){
    return NIM_FALSE;}
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_6 = argObjBox_0_run8hsnpi((&(*arg_2)));
  if (box_6 == NIM_NIL){
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_6);
    return NIM_FALSE;}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_18 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*f_4).desc_0);
  {
    while (NIM_TRUE){
      NB8 X60Qx_931;
      if ((!(td_18 == NIM_NIL))){
        X60Qx_931 = ((*td_18).d_00.kind_0 == 13);}
      else {
        X60Qx_931 = NIM_FALSE;}
      if (X60Qx_931){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qlhs_155 = td_18;
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_932 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*td_18).d_00.elem_0);
        td_18 = X60Qx_932;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qlhs_155);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (td_18 == NIM_NIL){
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_18);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_6);
    return NIM_FALSE;}
  seq_0_Ift2sne_aow7lb5cq1 offs_4 = fieldOffsets_0_layptix6a1(td_18, 8);
  if ((!(offs_4.len_0 == (*td_18).d_00.fields_0.len_0))){
    eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_18);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_6);
    return NIM_FALSE;}
  NI32 X60Qx_933 = len_3_I83dzei_arecyyj7v((*box_6).d_00.cells_0);
  NI32 X60Qx_934 = len_3_I5m68tr1_aow7lb5cq1((*td_18).d_00.fields_0);
  if (X60Qx_933 < X60Qx_934){
    eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_18);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_6);
    return NIM_FALSE;}
  seq_0_Ie7vbta_run8hsnpi newPtrs_0 = newSeqUninit_0_I32zp0x_run8hsnpi(0);
  NI32 i_35 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_935 = len_3_I5m68tr1_aow7lb5cq1((*td_18).d_00.fields_0);
      if (i_35 < X60Qx_935){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_936 = getQ_7_I45w7c91_aow7lb5cq1((*td_18).d_00.fields_0, i_35);
        if ((*(*X60Qx_936)).d_00.kind_0 == 5){
          NI32* X60Qx_937 = getQ_7_Ir8kccm_aow7lb5cq1(offs_4, i_35);
          NU64 X60Qx_938 = readBytes_0_run8hsnpi(buf_12, ((NI32)(off_7 + (*X60Qx_937))), 8);
          NU32 a_6 = ((NU32)X60Qx_938);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_939 = getQ_7_Ii14ync1_arecyyj7v((*box_6).d_00.cells_0, i_35);
          X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v X60Qtmptup_12 = unmaterializePtr_0_arecyyj7v((&(*m_1)), a_6, (&(*(*X60Qx_939)).d_00.v_0));
          Value_0_valzr1t4f nv_1 = X60Qtmptup_12.fld_0;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmptup_12.fld_0));
          NB8 ok_6 = X60Qtmptup_12.fld_1;
          if ((!ok_6)){
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_1));
            eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_run8hsnpi((&X60Qtmptup_12));
            eQdestroy_1_I2vp2bj_run8hsnpi(newPtrs_0);
            eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_18);
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_6);
            return NIM_FALSE;}
          Value_0_valzr1t4f X60Qtmp_156 = nv_1;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_1));
          add_0_Ivy8r7k1_run8hsnpi((&newPtrs_0), (X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi){
            .fld_0 = i_35, .fld_1 = X60Qtmp_156}
          );
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_1));
          eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_run8hsnpi((&X60Qtmptup_12));}
        inc_1_I6wjjge_aow2h993l1((&i_35));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_5 = flObjRegion_0_flaksyopx1(box_6);
  if (r_5 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_5);
    eQdestroy_1_I2vp2bj_run8hsnpi(newPtrs_0);
    eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_18);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_6);
    return NIM_FALSE;}
  i_35 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_940 = len_3_I5m68tr1_aow7lb5cq1((*td_18).d_00.fields_0);
      if (i_35 < X60Qx_940){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_941 = getQ_7_I45w7c91_aow7lb5cq1((*td_18).d_00.fields_0, i_35);
        if ((!((*(*X60Qx_941)).d_00.kind_0 == 5))){
          X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_942 = getQ_7_I45w7c91_aow7lb5cq1((*td_18).d_00.fields_0, i_35);
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_943 = sizeAlign_1_layptix6a1((*X60Qx_942), 8);
          NI32 sz_2 = X60Qx_943.fld_0;
          NI32 k_3 = 0;
          {
            while (NIM_TRUE){
              NB8 X60Qx_944;
              if (k_3 < sz_2){
                NI32* X60Qx_945 = getQ_7_Ir8kccm_aow7lb5cq1(offs_4, i_35);
                X60Qx_944 = (((NI32)((*X60Qx_945) + k_3)) < (*f_4).wireSize_0);}
              else {
                X60Qx_944 = NIM_FALSE;}
              if (X60Qx_944){
                NI32* X60Qx_946 = getQ_7_Ir8kccm_aow7lb5cq1(offs_4, i_35);
                NI32* X60Qx_947 = getQ_7_Ir8kccm_aow7lb5cq1(offs_4, i_35);
                NU8* X60Qx_948 = getQ_7_Ig0r1051_arecyyj7v(buf_12, ((NI32)(((NI32)(off_7 + (*X60Qx_947))) + k_3)));
                setByteAt_0_flaksyopx1(r_5, ((NI32)((*X60Qx_946) + k_3)), (*X60Qx_948));
                inc_1_I6wjjge_aow2h993l1((&k_3));}
              else {
                break;}}}
          whileStmtLabel_3: ;}
        inc_1_I6wjjge_aow2h993l1((&i_35));}
      else {
        break;}}}
  whileStmtLabel_2: ;
  {
    openArray_0_Icv4v4b1_run8hsnpi X60Qlf_24 = toOpenArray_1_Io2cvnr_run8hsnpi(newPtrs_0);
    NI32 X60Qlf_25 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_949 = len_6_Ivyewcw1_run8hsnpi(X60Qlf_24);
        if (X60Qlf_25 < X60Qx_949){
          {
            X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* X60Qii_6 = getQ_10_Ijhkrt71_run8hsnpi(X60Qlf_24, X60Qlf_25);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_950 = getQ_7_Ii14ync1_arecyyj7v((*box_6).d_00.cells_0, (*X60Qii_6).fld_0);
            Value_0_valzr1t4f* X60Qlhs_157 = (&(*(*X60Qx_950)).d_00.v_0);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_951 = getQ_7_Ii14ync1_arecyyj7v((*box_6).d_00.cells_0, (*X60Qii_6).fld_0);
            Value_0_valzr1t4f X60Qlhs_158 = (*(*X60Qx_951)).d_00.v_0;
            Value_0_valzr1t4f X60Qx_952 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qii_6).fld_1));
            (*X60Qlhs_157) = X60Qx_952;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_158));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_25));}
        else {
          break;}}}
    whileStmtLabel_5: ;}
  forStmtLabel_4: ;
  result_57 = NIM_TRUE;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_5);
  eQdestroy_1_I2vp2bj_run8hsnpi(newPtrs_0);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_18);
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_6);
  return result_57;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_5);
  eQdestroy_1_I2vp2bj_run8hsnpi(newPtrs_0);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_18);
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_6);
  return result_57;}
N_NIMCALL(NB8, cabiGenOwns_0_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* p_8, NU32 sym_10){
  NB8 result_58;
  NB8 X60Qx_953;
  if (((void*)p_8) == NIM_NIL){
    X60Qx_953 = NIM_TRUE;}
  else {
    Rtti_0_sysvq0asl* X60QvtableTemp_1 = (*p_8).d_00.Q.vt_00;
    NB8 X60Qx_954;
    if (2 < (*X60QvtableTemp_1).dl_0){
      X60Qx_954 = ((*X60QvtableTemp_1).dy_0[2] == 4174408912u);}
    else {
      X60Qx_954 = NIM_FALSE;}
    X60Qx_953 = X60Qx_954;}
  if ((!X60Qx_953)){
    nimInvalidObjConv((string_0_sysvq0asl){
      .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I18334688814084301714_run8hsnpi)}
    );}
  X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* gp_0 = eQdupQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi((*((X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi**)(&p_8))));
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_159 = getOrDefault_1_Imr3kd01_run8hsnpi((*gp_0).d_00.table_0, sym_10, NIM_NIL);
  result_58 = (!(X60Qtmp_159 == NIM_NIL));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qtmp_159);
  eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_0);
  return result_58;
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qtmp_159);
  eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_0);
  return result_58;}
N_NIMCALL(NB8, cabiGenInvoke_0_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* p_9, NU32 sym_11, string_0_sysvq0asl base_5, seq_0_I50urnw_croph25r5 args_6, Value_0_valzr1t4f* res_6){
  NB8 result_59;
  NB8 X60Qx_955;
  if (((void*)p_9) == NIM_NIL){
    X60Qx_955 = NIM_TRUE;}
  else {
    Rtti_0_sysvq0asl* X60QvtableTemp_2 = (*p_9).d_00.Q.vt_00;
    NB8 X60Qx_956;
    if (2 < (*X60QvtableTemp_2).dl_0){
      X60Qx_956 = ((*X60QvtableTemp_2).dy_0[2] == 4174408912u);}
    else {
      X60Qx_956 = NIM_FALSE;}
    X60Qx_955 = X60Qx_956;}
  if ((!X60Qx_955)){
    nimInvalidObjConv((string_0_sysvq0asl){
      .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I18334688814084301714_run8hsnpi)}
    );}
  X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* gp_1 = eQdupQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi((*((X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi**)(&p_9))));
  declineBegin_0_croph25r5(base_5);
  NB8 X60Qx_957 = jitTraceLog_0_run8hsnpi();
  if (X60Qx_957){
    string_0_sysvq0asl* X60Qx_958 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_11);
    string_0_sysvq0asl X60Qdesugar_31 = nimStrDup((*X60Qx_958));
    NI32 X60Qx_959 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I17755916622381260779_run8hsnpi)}
    );
    NI32 X60Qx_960 = len_4_sysvq0asl(X60Qdesugar_31);
    NI32 X60Qx_961 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_32 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_959 + X60Qx_960)) + X60Qx_961)));
    add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I17755916622381260779_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_32), X60Qdesugar_31);
    add_2_sysvq0asl((&X60Qdesugar_32), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_32);
    nimStrDestroy(X60Qdesugar_32);
    nimStrDestroy(X60Qdesugar_31);}
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_15 = getOrDefault_1_Imr3kd01_run8hsnpi((*gp_1).d_00.table_0, sym_11, NIM_NIL);
  if (e_15 == NIM_NIL){
    NB8 X60Qx_962 = jitTraceLog_0_run8hsnpi();
    if (X60Qx_962){
      string_0_sysvq0asl* X60Qx_963 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_11);
      string_0_sysvq0asl X60Qdesugar_33 = nimStrDup((*X60Qx_963));
      NI32 X60Qx_964 = len_0_Ifyaclq_run8hsnpi((*gp_1).d_00.table_0);
      string_0_sysvq0asl X60Qdesugar_34 = dollarQ_2_sysvq0asl(X60Qx_964);
      NI32 X60Qx_965 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      NI32 X60Qx_966 = len_4_sysvq0asl(X60Qdesugar_33);
      NI32 X60Qx_967 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I6867780705510740199_run8hsnpi)}
      );
      NI32 X60Qx_968 = len_4_sysvq0asl(X60Qdesugar_34);
      NI32 X60Qx_969 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1852121342u, .more_0 = (&strlit_0_I6591882555819548044_run8hsnpi)}
      );
      string_0_sysvq0asl X60Qdesugar_35 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_965 + X60Qx_966)) + X60Qx_967)) + X60Qx_968)) + X60Qx_969)));
      add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_35), X60Qdesugar_33);
      add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I6867780705510740199_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_35), X60Qdesugar_34);
      add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
        .bytes_0 = 1852121342u, .more_0 = (&strlit_0_I6591882555819548044_run8hsnpi)}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_35);
      nimStrDestroy(X60Qdesugar_35);
      nimStrDestroy(X60Qdesugar_34);
      nimStrDestroy(X60Qdesugar_33);}
    declineNote_0_croph25r5(2, (string_0_sysvq0asl){
      .bytes_0 = 1953459966u, .more_0 = (&strlit_0_I8323340401993503906_run8hsnpi)}
    );
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;}
  if ((!(args_6.len_0 == (*e_15).d_00.args_0.len_0))){
    NI32 X60Qx_970 = len_3_I4n9kvq_intzsnzax(args_6);
    string_0_sysvq0asl X60Qdesugar_36 = dollarQ_2_sysvq0asl(X60Qx_970);
    NI32 X60Qx_971 = len_3_In63jw61_aow7lb5cq1((*e_15).d_00.args_0);
    string_0_sysvq0asl X60Qdesugar_37 = dollarQ_2_sysvq0asl(X60Qx_971);
    NI32 X60Qx_972 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1769103870u, .more_0 = (&strlit_0_I17183936099286931213_run8hsnpi)}
    );
    NI32 X60Qx_973 = len_4_sysvq0asl(X60Qdesugar_36);
    NI32 X60Qx_974 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I18255814566225474086_run8hsnpi)}
    );
    NI32 X60Qx_975 = len_4_sysvq0asl(X60Qdesugar_37);
    NI32 X60Qx_976 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I2164128916027878689_run8hsnpi)}
    );
    string_0_sysvq0asl X60Qdesugar_38 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_972 + X60Qx_973)) + X60Qx_974)) + X60Qx_975)) + X60Qx_976)));
    add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
      .bytes_0 = 1769103870u, .more_0 = (&strlit_0_I17183936099286931213_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_38), X60Qdesugar_36);
    add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
      .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I18255814566225474086_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_38), X60Qdesugar_37);
    add_2_sysvq0asl((&X60Qdesugar_38), (string_0_sysvq0asl){
      .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I2164128916027878689_run8hsnpi)}
    );
    declineNote_0_croph25r5(2, X60Qdesugar_38);
    nimStrDestroy(X60Qdesugar_38);
    nimStrDestroy(X60Qdesugar_37);
    nimStrDestroy(X60Qdesugar_36);
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;
    nimStrDestroy(X60Qdesugar_38);
    nimStrDestroy(X60Qdesugar_37);
    nimStrDestroy(X60Qdesugar_36);}
  if ((!(*gp_1).d_00.opened_0)){
    (*gp_1).d_00.opened_0 = NIM_TRUE;
    NI32 X60Qx_977 = len_4_sysvq0asl((*gp_1).d_00.soPath_0);
    if (0 < X60Qx_977){
      string_0_sysvq0asl path_2 = nimStrDup((*gp_1).d_00.soPath_0);
      NC8* X60Qx_978 = toCString_0_sysvq0asl((&path_2));
      void* X60Qx_979 = dlopen(X60Qx_978, ((int)2));
      (*gp_1).d_00.handle_0 = X60Qx_979;
      NB8 X60Qx_980;
      if ((!((*gp_1).d_00.handle_0 == NIM_NIL))){
        X60Qx_980 = (!(((void*)gHostForward_0_run8hsnpi) == NIM_NIL));}
      else {
        X60Qx_980 = NIM_FALSE;}
      if (X60Qx_980){
        string_0_sysvq0asl setterName_0 = (string_0_sysvq0asl){
          .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I601893499622124267_run8hsnpi)}
        ;
        NC8* X60Qx_981 = toCString_0_sysvq0asl((&setterName_0));
        X60Qt_0_IAcstringZApointerZAiS32ZAR9ZAiS32ZAcdeclZAfalseZAR41SEAcdeclZAfalseZAR61_run8hsnpi setter_0 = dlsym((*gp_1).d_00.handle_0, X60Qx_981);
        if ((!(((void*)setter_0) == NIM_NIL))){
          setter_0(gHostForward_0_run8hsnpi);}
        nimStrDestroy(setterName_0);}
      nimStrDestroy(path_2);}}
  if ((*gp_1).d_00.handle_0 == NIM_NIL){
    NB8 X60Qx_982 = jitTraceLog_0_run8hsnpi();
    if (X60Qx_982){
      string_0_sysvq0asl X60Qdesugar_39 = nimStrDup((*gp_1).d_00.soPath_0);
      NI32 X60Qx_983 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      NI32 X60Qx_984 = len_4_sysvq0asl(base_5);
      NI32 X60Qx_985 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I11555090815403677726_run8hsnpi)}
      );
      NI32 X60Qx_986 = len_4_sysvq0asl(X60Qdesugar_39);
      NI32 X60Qx_987 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_40 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_983 + X60Qx_984)) + X60Qx_985)) + X60Qx_986)) + X60Qx_987)));
      add_2_sysvq0asl((&X60Qdesugar_40), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_40), base_5);
      add_2_sysvq0asl((&X60Qdesugar_40), (string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I11555090815403677726_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_40), X60Qdesugar_39);
      add_2_sysvq0asl((&X60Qdesugar_40), (string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_40);
      nimStrDestroy(X60Qdesugar_40);
      nimStrDestroy(X60Qdesugar_39);}
    string_0_sysvq0asl X60Qtmp_160 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869374718u, .more_0 = (&strlit_0_I8932411087278802551_run8hsnpi)}
    , (*gp_1).d_00.soPath_0);
    declineNote_0_croph25r5(6, X60Qtmp_160);
    nimStrDestroy(X60Qtmp_160);
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;
    nimStrDestroy(X60Qtmp_160);}
  if ((!(*e_15).d_00.resolved_0)){
    (*e_15).d_00.resolved_0 = NIM_TRUE;
    string_0_sysvq0asl nm_4 = nimStrDup((*e_15).d_00.shimSym_0);
    NC8* X60Qx_988 = toCString_0_sysvq0asl((&nm_4));
    X60Qt_0_IApointerZAR0ZAiS32ZAiS32ZAcdeclZAfalseZAR32_run8hsnpi X60Qx_989 = dlsym((*gp_1).d_00.handle_0, X60Qx_988);
    (*e_15).d_00.fn_0 = X60Qx_989;
    nimStrDestroy(nm_4);}
  if (((void*)(*e_15).d_00.fn_0) == NIM_NIL){
    NB8 X60Qx_990 = jitTraceLog_0_run8hsnpi();
    if (X60Qx_990){
      string_0_sysvq0asl X60Qdesugar_41 = nimStrDup((*e_15).d_00.shimSym_0);
      NI32 X60Qx_991 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      NI32 X60Qx_992 = len_4_sysvq0asl(base_5);
      NI32 X60Qx_993 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I15980317227653665914_run8hsnpi)}
      );
      NI32 X60Qx_994 = len_4_sysvq0asl(X60Qdesugar_41);
      NI32 X60Qx_995 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_42 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_991 + X60Qx_992)) + X60Qx_993)) + X60Qx_994)) + X60Qx_995)));
      add_2_sysvq0asl((&X60Qdesugar_42), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_42), base_5);
      add_2_sysvq0asl((&X60Qdesugar_42), (string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I15980317227653665914_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_42), X60Qdesugar_41);
      add_2_sysvq0asl((&X60Qdesugar_42), (string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_42);
      nimStrDestroy(X60Qdesugar_42);
      nimStrDestroy(X60Qdesugar_41);}
    string_0_sysvq0asl X60Qtmp_161 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1936483582u, .more_0 = (&strlit_0_I9471465608874713306_run8hsnpi)}
    , (*e_15).d_00.shimSym_0);
    declineNote_0_croph25r5(6, X60Qtmp_161);
    nimStrDestroy(X60Qtmp_161);
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;
    nimStrDestroy(X60Qtmp_161);}
  NB8 anyArena_0 = NIM_FALSE;
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_26 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_15).d_00.args_0);
    NI32 X60Qlf_27 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_996 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_26);
        if (X60Qlf_27 < X60Qx_996){
          {
            WireField_0_run8hsnpi* X60Qii_2 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_26, X60Qlf_27);
            NB8 X60Qx_997;
            NB8 X60Qx_998;
            if ((*X60Qii_2).isArenaRef_0){
              X60Qx_998 = NIM_TRUE;}
            else {
              X60Qx_998 = (*X60Qii_2).isArenaPtr_0;}
            if (X60Qx_998){
              X60Qx_997 = NIM_TRUE;}
            else {
              X60Qx_997 = (*X60Qii_2).isPtrArena_0;}
            if (X60Qx_997){
              anyArena_0 = NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_27));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  seq_0_Isge9lx_arecyyj7v X60Qx_999 = newSeqUninit_0_Iglb3hm1_arecyyj7v(0);
  seq_0_Idhq52f_arecyyj7v X60Qx_1000 = newSeqUninit_0_I7mggr11_arecyyj7v(0);
  seq_0_Ijes23h1_arecyyj7v X60Qx_1001 = newSeqUninit_0_I1oegnq1_arecyyj7v(0);
  ArenaMat_0_arecyyj7v m_4 = (ArenaMat_0_arecyyj7v){
    .a_0 = ((X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v*)NIM_NIL), .seen_0 = X60Qx_999, .blocks_0 = X60Qx_1000, .regions_0 = X60Qx_1001}
  ;
  seq_0_Iq1shzq1_run8hsnpi arenaSync_0 = newSeqUninit_0_Ie5g2lj_run8hsnpi(0);
  if (anyArena_0){
    if ((*gp_1).d_00.arena_0 == NIM_NIL){
      X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v** X60Qlhs_162 = (&(*gp_1).d_00.arena_0);
      X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* X60Qlhs_163 = newArena_0_arewp645e1(((NI32)1048576));
      eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_run8hsnpi((*X60Qlhs_162));
      (*X60Qlhs_162) = X60Qlhs_163;}
    arenaReset_0_arewp645e1((*gp_1).d_00.arena_0);
    eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
    ArenaMat_0_arecyyj7v X60Qx_1002 = initArenaMat_0_arecyyj7v((*gp_1).d_00.arena_0);
    m_4 = X60Qx_1002;}
  seq_0_Incv1wn_arecyyj7v inbuf_1 = newSeq_0_Ivbxvoi1_explnj22x1(0);
  NI32 i_36 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1003 = len_3_In63jw61_aow7lb5cq1((*e_15).d_00.args_0);
      if (i_36 < X60Qx_1003){
        Value_0_valzr1t4f* X60Qx_1004 = getQ_7_Ine8yq71_intzsnzax(args_6, i_36);
        Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_1004);
        Value_0_valzr1t4f av_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
        WireField_0_run8hsnpi* X60Qx_1005 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_36);
        if ((*X60Qx_1005).isArenaRef_0){
          NB8 X60Qx_1006;
          if (av_0.kind_0 == 13){
            X60Qx_1006 = (!(av_0.loc_0 == NIM_NIL));}
          else {
            X60Qx_1006 = NIM_FALSE;}
          if (X60Qx_1006){
            Value_0_valzr1t4f X60Qlhs_164 = av_0;
            Value_0_valzr1t4f X60Qx_1007 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*av_0.loc_0).d_00.v_0));
            av_0 = X60Qx_1007;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_164));}
          void* box_7 = materialize_0_arecyyj7v((&m_4), (&av_0));
          appendU_0_run8hsnpi((&inbuf_1), ((NU64)((NU32)box_7)), 8);
          Value_0_valzr1t4f X60Qtmp_165 = av_0;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&av_0));
          add_0_Ii05ltt1_run8hsnpi((&arenaSync_0), (X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi){
            .fld_0 = X60Qtmp_165, .fld_1 = box_7}
          );}
        else {
          WireField_0_run8hsnpi* X60Qx_1008 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_36);
          if ((*X60Qx_1008).isPtrArena_0){
            WireField_0_run8hsnpi* X60Qx_1009 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_36);
            void* pa_0 = materializePtr_0_arecyyj7v((&m_4), (&av_0), NIM_FALSE, (*X60Qx_1009).elemSize_0);
            if (pa_0 == NIM_NIL){
              string_0_sysvq0asl X60Qdesugar_43 = dollarQ_2_sysvq0asl(i_36);
              NI32 X60Qx_1010 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1920233726u, .more_0 = (&strlit_0_I3278143169533289085_run8hsnpi)}
              );
              NI32 X60Qx_1011 = len_4_sysvq0asl(X60Qdesugar_43);
              NI32 X60Qx_1012 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1948269310u, .more_0 = (&strlit_0_I13592592763606903879_run8hsnpi)}
              );
              string_0_sysvq0asl X60Qdesugar_44 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1010 + X60Qx_1011)) + X60Qx_1012)));
              add_2_sysvq0asl((&X60Qdesugar_44), (string_0_sysvq0asl){
                .bytes_0 = 1920233726u, .more_0 = (&strlit_0_I3278143169533289085_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_44), X60Qdesugar_43);
              add_2_sysvq0asl((&X60Qdesugar_44), (string_0_sysvq0asl){
                .bytes_0 = 1948269310u, .more_0 = (&strlit_0_I13592592763606903879_run8hsnpi)}
              );
              declineNote_0_croph25r5(3, X60Qdesugar_44);
              nimStrDestroy(X60Qdesugar_44);
              nimStrDestroy(X60Qdesugar_43);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&av_0));
              eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
              eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
              eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
              eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
              eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
              return NIM_FALSE;
              nimStrDestroy(X60Qdesugar_44);
              nimStrDestroy(X60Qdesugar_43);}
            appendU_0_run8hsnpi((&inbuf_1), ((NU64)((NU32)pa_0)), 8);}
          else {
            WireField_0_run8hsnpi* X60Qx_1013 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_36);
            if ((*X60Qx_1013).isArenaPtr_0){
              NB8 X60Qx_1014;
              if (av_0.kind_0 == 13){
                X60Qx_1014 = (!(av_0.loc_0 == NIM_NIL));}
              else {
                X60Qx_1014 = NIM_FALSE;}
              if (X60Qx_1014){
                Value_0_valzr1t4f X60Qlhs_166 = av_0;
                Value_0_valzr1t4f X60Qx_1015 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*av_0.loc_0).d_00.v_0));
                av_0 = X60Qx_1015;
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_166));}
              WireField_0_run8hsnpi* X60Qx_1016 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_36);
              NI32 X60Qx_1017 = max_2_sysvq0asl((*X60Qx_1016).wireSize_0, 1);
              seq_0_Incv1wn_arecyyj7v pb_0 = newSeq_0_Ivbxvoi1_explnj22x1(X60Qx_1017);
              seq_0_Ift2sne_aow7lb5cq1 nd_1 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
              NB8 X60Qx_1018;
              NI32 X60Qx_1019 = len_3_Irjnvku_run8hsnpi((*e_15).d_00.noDerefOffs_0);
              if (i_36 < X60Qx_1019){
                NB8 X60Qx_1020 = grantsHonoured_0_croph25r5((*gp_1).d_00.xp_0);
                X60Qx_1018 = X60Qx_1020;}
              else {
                X60Qx_1018 = NIM_FALSE;}
              NB8 honoured_0 = X60Qx_1018;
              NB8 X60Qx_1021;
              NI32 X60Qx_1022 = len_3_Irjnvku_run8hsnpi((*e_15).d_00.noDerefOffs_0);
              if (i_36 < X60Qx_1022){
                seq_0_Ift2sne_aow7lb5cq1* X60Qx_1023 = getQ_7_Iurb46i_aow7lb5cq1((*e_15).d_00.noDerefOffs_0, i_36);
                X60Qx_1021 = (0 < (*X60Qx_1023).len_0);}
              else {
                X60Qx_1021 = NIM_FALSE;}
              if (X60Qx_1021){
                if (honoured_0){
                  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(nd_1);
                  seq_0_Ift2sne_aow7lb5cq1* X60Qx_1024 = getQ_7_Iurb46i_aow7lb5cq1((*e_15).d_00.noDerefOffs_0, i_36);
                  seq_0_Ift2sne_aow7lb5cq1 X60Qx_1025 = eQdup_1_Iplow11_aow7lb5cq1((*X60Qx_1024));
                  nd_1 = X60Qx_1025;
                  bump_0_croph25r5(cAnHonoured_0_croph25r5, 1);}
                else {
                  bump_0_croph25r5(cAnRevoked_0_croph25r5, 1);}}
              WireField_0_run8hsnpi* X60Qx_1026 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_36);
              NB8 X60Qx_1027 = packPodArena_0_run8hsnpi((&pb_0), 0, (&av_0), (*X60Qx_1026).desc_0, (&m_4), nd_1);
              if ((!X60Qx_1027)){
                string_0_sysvq0asl X60Qdesugar_45 = dollarQ_2_sysvq0asl(i_36);
                NI32 X60Qx_1028 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I1069507577923700528_run8hsnpi)}
                );
                NI32 X60Qx_1029 = len_4_sysvq0asl(X60Qdesugar_45);
                NI32 X60Qx_1030 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1881160446u, .more_0 = (&strlit_0_I8163890759512608411_run8hsnpi)}
                );
                string_0_sysvq0asl X60Qdesugar_46 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1028 + X60Qx_1029)) + X60Qx_1030)));
                add_2_sysvq0asl((&X60Qdesugar_46), (string_0_sysvq0asl){
                  .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I1069507577923700528_run8hsnpi)}
                );
                add_2_sysvq0asl((&X60Qdesugar_46), X60Qdesugar_45);
                add_2_sysvq0asl((&X60Qdesugar_46), (string_0_sysvq0asl){
                  .bytes_0 = 1881160446u, .more_0 = (&strlit_0_I8163890759512608411_run8hsnpi)}
                );
                declineNote_0_croph25r5(3, X60Qdesugar_46);
                nimStrDestroy(X60Qdesugar_46);
                nimStrDestroy(X60Qdesugar_45);
                eQdestroy_1_Iv9ij5i1_aow7lb5cq1(nd_1);
                eQdestroy_1_Ijx6eoq_arecyyj7v(pb_0);
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&av_0));
                eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
                eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
                eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
                eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
                eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
                return NIM_FALSE;
                nimStrDestroy(X60Qdesugar_46);
                nimStrDestroy(X60Qdesugar_45);}
              NI32 pk_0 = 0;
              {
                while (NIM_TRUE){
                  WireField_0_run8hsnpi* X60Qx_1031 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_36);
                  if (pk_0 < (*X60Qx_1031).wireSize_0){
                    NU8* X60Qx_1032 = getQ_7_Ig0r1051_arecyyj7v(pb_0, pk_0);
                    add_0_Ibphvmo_run8hsnpi((&inbuf_1), (*X60Qx_1032));
                    inc_1_I6wjjge_aow2h993l1((&pk_0));}
                  else {
                    break;}}}
              whileStmtLabel_4: ;
              eQdestroy_1_Iv9ij5i1_aow7lb5cq1(nd_1);
              eQdestroy_1_Ijx6eoq_arecyyj7v(pb_0);}
            else {
              WireField_0_run8hsnpi* X60Qx_1033 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_36);
              if ((*X60Qx_1033).isVar_0){
                NB8 X60Qx_1034;
                if (av_0.kind_0 == 13){
                  X60Qx_1034 = (!(av_0.loc_0 == NIM_NIL));}
                else {
                  X60Qx_1034 = NIM_FALSE;}
                if (X60Qx_1034){
                  Value_0_valzr1t4f X60Qlhs_167 = av_0;
                  Value_0_valzr1t4f X60Qx_1035 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*av_0.loc_0).d_00.v_0));
                  av_0 = X60Qx_1035;
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_167));}
                else {
                  NB8 X60Qx_1036;
                  if (av_0.kind_0 == 12){
                    X60Qx_1036 = (!(av_0.rf_0 == NIM_NIL));}
                  else {
                    X60Qx_1036 = NIM_FALSE;}
                  if (X60Qx_1036){
                    Value_0_valzr1t4f X60Qlhs_168 = av_0;
                    Value_0_valzr1t4f X60Qx_1037 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*av_0.rf_0).d_00.v_0));
                    av_0 = X60Qx_1037;
                    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_168));}}}
              WireField_0_run8hsnpi* X60Qx_1038 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_36);
              WireField_0_run8hsnpi X60QconstRefTemp_1 = (*X60Qx_1038);
              appendField_0_run8hsnpi((&inbuf_1), (&av_0), (&X60QconstRefTemp_1));}}}
        inc_1_I6wjjge_aow2h993l1((&i_36));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&av_0));}
      else {
        break;}}}
  whileStmtLabel_3: ;
  NB8 X60Qx_1039;
  if (anyArena_0){
    X60Qx_1039 = arenaMatFailed_0_arecyyj7v;}
  else {
    X60Qx_1039 = NIM_FALSE;}
  if (X60Qx_1039){
    bump_0_croph25r5(cArenaDeclines_0_croph25r5, 1);
    NB8 X60Qx_1040;
    NB8 X60Qx_1041 = hybridArenaTrace_0_run8hsnpi();
    if (X60Qx_1041){
      NI32 X60Qx_1042 = countOf_0_croph25r5(cArenaDeclines_0_croph25r5);
      X60Qx_1040 = (X60Qx_1042 <= 3);}
    else {
      X60Qx_1040 = NIM_FALSE;}
    if (X60Qx_1040){
      string_0_sysvq0asl X60Qdesugar_47 = arenaReport_0_arecyyj7v();
      NI32 X60Qx_1043 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I15611778738489493776_run8hsnpi)}
      );
      NI32 X60Qx_1044 = len_4_sysvq0asl(base_5);
      NI32 X60Qx_1045 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
      );
      NI32 X60Qx_1046 = len_4_sysvq0asl(X60Qdesugar_47);
      NI32 X60Qx_1047 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_48 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1043 + X60Qx_1044)) + X60Qx_1045)) + X60Qx_1046)) + X60Qx_1047)));
      add_2_sysvq0asl((&X60Qdesugar_48), (string_0_sysvq0asl){
        .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I15611778738489493776_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_48), base_5);
      add_2_sysvq0asl((&X60Qdesugar_48), (string_0_sysvq0asl){
        .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_48), X60Qdesugar_47);
      add_2_sysvq0asl((&X60Qdesugar_48), (string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_48);
      nimStrDestroy(X60Qdesugar_48);
      nimStrDestroy(X60Qdesugar_47);}
    eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
    eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
    eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;}
  NB8 X60Qx_1048;
  NB8 X60Qx_1049;
  if (anyArena_0){
    NB8 X60Qx_1050 = hybridArenaTrace_0_run8hsnpi();
    X60Qx_1049 = X60Qx_1050;}
  else {
    X60Qx_1049 = NIM_FALSE;}
  if (X60Qx_1049){
    NI32 X60Qx_1051 = countOf_0_croph25r5(cHybridCalls_0_croph25r5);
    X60Qx_1048 = (X60Qx_1051 < 4);}
  else {
    X60Qx_1048 = NIM_FALSE;}
  if (X60Qx_1048){
    string_0_sysvq0asl X60Qdesugar_49 = arenaReport_0_arecyyj7v();
    NI32 X60Qx_1052 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I15730584599751133452_run8hsnpi)}
    );
    NI32 X60Qx_1053 = len_4_sysvq0asl(base_5);
    NI32 X60Qx_1054 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_1055 = len_4_sysvq0asl(X60Qdesugar_49);
    NI32 X60Qx_1056 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_50 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1052 + X60Qx_1053)) + X60Qx_1054)) + X60Qx_1055)) + X60Qx_1056)));
    add_2_sysvq0asl((&X60Qdesugar_50), (string_0_sysvq0asl){
      .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I15730584599751133452_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_50), base_5);
    add_2_sysvq0asl((&X60Qdesugar_50), (string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_50), X60Qdesugar_49);
    add_2_sysvq0asl((&X60Qdesugar_50), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_50);
    nimStrDestroy(X60Qdesugar_50);
    nimStrDestroy(X60Qdesugar_49);}
  (*e_15).d_00.nCalls_0 = ((NI32)((*e_15).d_00.nCalls_0 + 1));
  NI32 X60Qx_1057 = len_3_Izoe8zv_arecyyj7v(inbuf_1);
  (*e_15).d_00.nBytesIn_0 = ((NI32)((*e_15).d_00.nBytesIn_0 + X60Qx_1057));
  NI32 X60Qx_1058 = len_3_Izoe8zv_arecyyj7v(inbuf_1);
  if (X60Qx_1058 == 0){
    add_0_Ibphvmo_run8hsnpi((&inbuf_1), ((NU8)0u));}
  NU8* X60Qx_1059 = getQ_7_Ig0r1051_arecyyj7v(inbuf_1, 0);
  void* inp_0 = ((void*)(&(*X60Qx_1059)));
  NI32 cap_0 = max_2_sysvq0asl((*e_15).d_00.outSize_0, 1);
  seq_0_Incv1wn_arecyyj7v outbuf_1 = newSeq_0_Ivbxvoi1_explnj22x1(cap_0);
  NU8* X60Qx_1060 = getQ_7_Ig0r1051_arecyyj7v(outbuf_1, 0);
  NI32 need_0 = (*e_15).d_00.fn_0(inp_0, ((void*)(&(*X60Qx_1060))), cap_0);
  if (cap_0 < need_0){
    cap_0 = need_0;
    eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
    seq_0_Incv1wn_arecyyj7v X60Qx_1061 = newSeq_0_Ivbxvoi1_explnj22x1(cap_0);
    outbuf_1 = X60Qx_1061;
    NU8* X60Qx_1062 = getQ_7_Ig0r1051_arecyyj7v(outbuf_1, 0);
    NI32 X60Qx_1063 = (*e_15).d_00.fn_0(inp_0, ((void*)(&(*X60Qx_1062))), cap_0);
    need_0 = X60Qx_1063;
    if (cap_0 < need_0){
      string_0_sysvq0asl X60Qdesugar_51 = dollarQ_2_sysvq0asl(need_0);
      NI32 X60Qx_1064 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1768453118u, .more_0 = (&strlit_0_I2491960150546354308_run8hsnpi)}
      );
      NI32 X60Qx_1065 = len_4_sysvq0asl(X60Qdesugar_51);
      NI32 X60Qx_1066 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I2284540631411732658_run8hsnpi)}
      );
      string_0_sysvq0asl X60Qdesugar_52 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1064 + X60Qx_1065)) + X60Qx_1066)));
      add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
        .bytes_0 = 1768453118u, .more_0 = (&strlit_0_I2491960150546354308_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_52), X60Qdesugar_51);
      add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
        .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I2284540631411732658_run8hsnpi)}
      );
      declineNote_0_croph25r5(6, X60Qdesugar_52);
      nimStrDestroy(X60Qdesugar_52);
      nimStrDestroy(X60Qdesugar_51);
      eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
      eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
      eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
      eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
      eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
      eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
      return NIM_FALSE;
      nimStrDestroy(X60Qdesugar_52);
      nimStrDestroy(X60Qdesugar_51);}}
  NI32 ai_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_1067;
      NI32 X60Qx_1068 = len_3_In63jw61_aow7lb5cq1((*e_15).d_00.args_0);
      if (ai_0 < X60Qx_1068){
        NI32 X60Qx_1069 = len_3_I0v1j8d_aow7lb5cq1((*e_15).d_00.outVarOffs_0);
        X60Qx_1067 = (ai_0 < X60Qx_1069);}
      else {
        X60Qx_1067 = NIM_FALSE;}
      if (X60Qx_1067){
        NB8 X60Qx_1070;
        NB8 X60Qx_1071;
        WireField_0_run8hsnpi* X60Qx_1072 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
        if ((*X60Qx_1072).isVar_0){
          WireField_0_run8hsnpi* X60Qx_1073 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          X60Qx_1071 = (*X60Qx_1073).isArenaPtr_0;}
        else {
          X60Qx_1071 = NIM_FALSE;}
        if (X60Qx_1071){
          NI32* X60Qx_1074 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          X60Qx_1070 = (0 <= (*X60Qx_1074));}
        else {
          X60Qx_1070 = NIM_FALSE;}
        if (X60Qx_1070){
          Value_0_valzr1t4f* X60Qx_1075 = getQ_7_Ine8yq71_intzsnzax(args_6, ai_0);
          Value_0_valzr1t4f X60QconstRefTemp_2 = (*X60Qx_1075);
          NI32* X60Qx_1076 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          WireField_0_run8hsnpi* X60Qx_1077 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          WireField_0_run8hsnpi X60QconstRefTemp_3 = (*X60Qx_1077);
          NB8 X60Qx_1078 = applyWritebackArena_0_run8hsnpi((&X60QconstRefTemp_2), outbuf_1, (*X60Qx_1076), (&X60QconstRefTemp_3), (&m_4));
          if ((!X60Qx_1078)){
            bump_0_croph25r5(cArenaDeclines_0_croph25r5, 1);
            string_0_sysvq0asl X60Qdesugar_53 = dollarQ_2_sysvq0asl(ai_0);
            NI32 X60Qx_1079 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I10032287891621565925_run8hsnpi)}
            );
            NI32 X60Qx_1080 = len_4_sysvq0asl(X60Qdesugar_53);
            NI32 X60Qx_1081 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1629502206u, .more_0 = (&strlit_0_I11519459256921757232_run8hsnpi)}
            );
            string_0_sysvq0asl X60Qdesugar_54 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1079 + X60Qx_1080)) + X60Qx_1081)));
            add_2_sysvq0asl((&X60Qdesugar_54), (string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I10032287891621565925_run8hsnpi)}
            );
            add_2_sysvq0asl((&X60Qdesugar_54), X60Qdesugar_53);
            add_2_sysvq0asl((&X60Qdesugar_54), (string_0_sysvq0asl){
              .bytes_0 = 1629502206u, .more_0 = (&strlit_0_I11519459256921757232_run8hsnpi)}
            );
            declineNote_0_croph25r5(3, X60Qdesugar_54);
            NB8 X60Qx_1082;
            NB8 X60Qx_1083 = hybridArenaTrace_0_run8hsnpi();
            if (X60Qx_1083){
              NI32 X60Qx_1084 = countOf_0_croph25r5(cArenaDeclines_0_croph25r5);
              X60Qx_1082 = (X60Qx_1084 <= 3);}
            else {
              X60Qx_1082 = NIM_FALSE;}
            if (X60Qx_1082){
              string_0_sysvq0asl X60Qdesugar_55 = arenaReport_0_arecyyj7v();
              NI32 X60Qx_1085 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I8945843855761550514_run8hsnpi)}
              );
              NI32 X60Qx_1086 = len_4_sysvq0asl(base_5);
              NI32 X60Qx_1087 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
              );
              NI32 X60Qx_1088 = len_4_sysvq0asl(X60Qdesugar_55);
              NI32 X60Qx_1089 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2561u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_56 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1085 + X60Qx_1086)) + X60Qx_1087)) + X60Qx_1088)) + X60Qx_1089)));
              add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
                .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I8945843855761550514_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_56), base_5);
              add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
                .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_56), X60Qdesugar_55);
              add_2_sysvq0asl((&X60Qdesugar_56), (string_0_sysvq0asl){
                .bytes_0 = 2561u, .more_0 = NIM_NIL}
              );
              write_0_syn1lfpjv(stderr, X60Qdesugar_56);
              nimStrDestroy(X60Qdesugar_56);
              nimStrDestroy(X60Qdesugar_55);}
            nimStrDestroy(X60Qdesugar_54);
            nimStrDestroy(X60Qdesugar_53);
            eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
            eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
            eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
            eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
            eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
            eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
            return NIM_FALSE;
            nimStrDestroy(X60Qdesugar_54);
            nimStrDestroy(X60Qdesugar_53);}}
        NB8 X60Qx_1090;
        NB8 X60Qx_1091;
        WireField_0_run8hsnpi* X60Qx_1092 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
        if ((*X60Qx_1092).isVar_0){
          WireField_0_run8hsnpi* X60Qx_1093 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          X60Qx_1091 = (*X60Qx_1093).isArray_0;}
        else {
          X60Qx_1091 = NIM_FALSE;}
        if (X60Qx_1091){
          NI32* X60Qx_1094 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          X60Qx_1090 = (0 <= (*X60Qx_1094));}
        else {
          X60Qx_1090 = NIM_FALSE;}
        if (X60Qx_1090){
          Value_0_valzr1t4f* X60Qx_1095 = getQ_7_Ine8yq71_intzsnzax(args_6, ai_0);
          Value_0_valzr1t4f X60QconstRefTemp_4 = (*X60Qx_1095);
          NI32* X60Qx_1096 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          WireField_0_run8hsnpi* X60Qx_1097 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          WireField_0_run8hsnpi X60QconstRefTemp_5 = (*X60Qx_1097);
          NB8 X60Qx_1098 = applyWritebackArray_0_run8hsnpi((&X60QconstRefTemp_4), outbuf_1, (*X60Qx_1096), (&X60QconstRefTemp_5));
          if ((!X60Qx_1098)){
            string_0_sysvq0asl X60Qdesugar_57 = dollarQ_2_sysvq0asl(ai_0);
            NI32 X60Qx_1099 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I10032287891621565925_run8hsnpi)}
            );
            NI32 X60Qx_1100 = len_4_sysvq0asl(X60Qdesugar_57);
            NI32 X60Qx_1101 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1629502206u, .more_0 = (&strlit_0_I9993579587050855651_run8hsnpi)}
            );
            NI32 X60Qx_1102 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 544370686u, .more_0 = (&strlit_0_I16678242556164327223_run8hsnpi)}
            );
            string_0_sysvq0asl X60Qdesugar_58 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1099 + X60Qx_1100)) + X60Qx_1101)) + X60Qx_1102)));
            add_2_sysvq0asl((&X60Qdesugar_58), (string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I10032287891621565925_run8hsnpi)}
            );
            add_2_sysvq0asl((&X60Qdesugar_58), X60Qdesugar_57);
            add_2_sysvq0asl((&X60Qdesugar_58), (string_0_sysvq0asl){
              .bytes_0 = 1629502206u, .more_0 = (&strlit_0_I9993579587050855651_run8hsnpi)}
            );
            add_2_sysvq0asl((&X60Qdesugar_58), (string_0_sysvq0asl){
              .bytes_0 = 544370686u, .more_0 = (&strlit_0_I16678242556164327223_run8hsnpi)}
            );
            declineNote_0_croph25r5(1, X60Qdesugar_58);
            nimStrDestroy(X60Qdesugar_58);
            nimStrDestroy(X60Qdesugar_57);
            eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
            eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
            eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
            eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
            eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
            eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
            return NIM_FALSE;
            nimStrDestroy(X60Qdesugar_58);
            nimStrDestroy(X60Qdesugar_57);}}
        inc_1_I6wjjge_aow2h993l1((&ai_0));}
      else {
        break;}}}
  whileStmtLabel_5: ;
  if ((*e_15).d_00.retVoid_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*res_6)));
    Value_0_valzr1t4f X60Qx_1103 = vNil_0_valzr1t4f();
    (*res_6) = X60Qx_1103;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*res_6)));
    Value_0_valzr1t4f X60Qx_1104 = unpackReturn_0_run8hsnpi(outbuf_1, (&(*e_15).d_00.ret_0));
    (*res_6) = X60Qx_1104;}
  ai_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_1105;
      NI32 X60Qx_1106 = len_3_In63jw61_aow7lb5cq1((*e_15).d_00.args_0);
      if (ai_0 < X60Qx_1106){
        NI32 X60Qx_1107 = len_3_I0v1j8d_aow7lb5cq1((*e_15).d_00.outVarOffs_0);
        X60Qx_1105 = (ai_0 < X60Qx_1107);}
      else {
        X60Qx_1105 = NIM_FALSE;}
      if (X60Qx_1105){
        NB8 X60Qx_1108;
        NB8 X60Qx_1109;
        NB8 X60Qx_1110;
        WireField_0_run8hsnpi* X60Qx_1111 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
        if ((*X60Qx_1111).isVar_0){
          NI32* X60Qx_1112 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          X60Qx_1110 = (0 <= (*X60Qx_1112));}
        else {
          X60Qx_1110 = NIM_FALSE;}
        if (X60Qx_1110){
          WireField_0_run8hsnpi* X60Qx_1113 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          X60Qx_1109 = (!(*X60Qx_1113).isArenaPtr_0);}
        else {
          X60Qx_1109 = NIM_FALSE;}
        if (X60Qx_1109){
          WireField_0_run8hsnpi* X60Qx_1114 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          X60Qx_1108 = (!(*X60Qx_1114).isArray_0);}
        else {
          X60Qx_1108 = NIM_FALSE;}
        if (X60Qx_1108){
          Value_0_valzr1t4f* X60Qx_1115 = getQ_7_Ine8yq71_intzsnzax(args_6, ai_0);
          Value_0_valzr1t4f X60QconstRefTemp_6 = (*X60Qx_1115);
          NI32* X60Qx_1116 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          WireField_0_run8hsnpi* X60Qx_1117 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          WireField_0_run8hsnpi X60QconstRefTemp_7 = (*X60Qx_1117);
          applyWriteback_0_run8hsnpi((&X60QconstRefTemp_6), outbuf_1, (*X60Qx_1116), (&X60QconstRefTemp_7));}
        inc_1_I6wjjge_aow2h993l1((&ai_0));}
      else {
        break;}}}
  whileStmtLabel_6: ;
  NI32 si_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1118 = len_3_Iibq2ff1_run8hsnpi(arenaSync_0);
      if (si_0 < X60Qx_1118){
        X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* X60Qx_1119 = getQ_7_Ir6lnzn1_run8hsnpi(arenaSync_0, si_0);
        X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* X60Qx_1120 = getQ_7_Ir6lnzn1_run8hsnpi(arenaSync_0, si_0);
        syncBack_0_arecyyj7v((&m_4), (&(*X60Qx_1119).fld_0), (*X60Qx_1120).fld_1);
        inc_1_I6wjjge_aow2h993l1((&si_0));}
      else {
        break;}}}
  whileStmtLabel_7: ;
  if (anyArena_0){
    syncBlocks_0_arecyyj7v((&m_4));}
  bump_0_croph25r5(cHybridCalls_0_croph25r5, 1);
  (*e_15).d_00.nBytesOut_0 = ((NI32)((*e_15).d_00.nBytesOut_0 + need_0));
  NB8 X60Qx_1121 = jitCallLog_0_run8hsnpi();
  if (X60Qx_1121){
    NI32 p_14 = 1;
    {
      while (p_14 < (*e_15).d_00.nCalls_0){
        p_14 = ((NI32)(p_14 * 10));}}
    whileStmtLabel_8: ;
    if (p_14 == (*e_15).d_00.nCalls_0){
      string_0_sysvq0asl X60Qdesugar_59 = dollarQ_2_sysvq0asl((*e_15).d_00.nCalls_0);
      string_0_sysvq0asl X60Qdesugar_60 = dollarQ_2_sysvq0asl((*e_15).d_00.nBytesIn_0);
      string_0_sysvq0asl X60Qdesugar_61 = dollarQ_2_sysvq0asl((*e_15).d_00.nBytesOut_0);
      string_0_sysvq0asl X60Qdesugar_62 = dollarQ_2_sysvq0asl(((NI32)((*e_15).d_00.nBytesIn_0 / (*e_15).d_00.nCalls_0)));
      NI32 X60Qx_1122 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I87927900075392640_run8hsnpi)}
      );
      NI32 X60Qx_1123 = len_4_sysvq0asl(base_5);
      NI32 X60Qx_1124 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1633886462u, .more_0 = (&strlit_0_I12313134788378398246_run8hsnpi)}
      );
      NI32 X60Qx_1125 = len_4_sysvq0asl(X60Qdesugar_59);
      NI32 X60Qx_1126 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1852383486u, .more_0 = (&strlit_0_I11209019673050966371_intzsnzax)}
      );
      NI32 X60Qx_1127 = len_4_sysvq0asl(X60Qdesugar_60);
      NI32 X60Qx_1128 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1970217214u, .more_0 = (&strlit_0_I9006312985088794180_run8hsnpi)}
      );
      NI32 X60Qx_1129 = len_4_sysvq0asl(X60Qdesugar_61);
      NI32 X60Qx_1130 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1986076926u, .more_0 = (&strlit_0_I10836411368895577019_run8hsnpi)}
      );
      NI32 X60Qx_1131 = len_4_sysvq0asl(X60Qdesugar_62);
      NI32 X60Qx_1132 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 672258u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_63 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_1122 + X60Qx_1123)) + X60Qx_1124)) + X60Qx_1125)) + X60Qx_1126)) + X60Qx_1127)) + X60Qx_1128)) + X60Qx_1129)) + X60Qx_1130)) + X60Qx_1131)) + X60Qx_1132)));
      add_2_sysvq0asl((&X60Qdesugar_63), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I87927900075392640_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_63), base_5);
      add_2_sysvq0asl((&X60Qdesugar_63), (string_0_sysvq0asl){
        .bytes_0 = 1633886462u, .more_0 = (&strlit_0_I12313134788378398246_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_63), X60Qdesugar_59);
      add_2_sysvq0asl((&X60Qdesugar_63), (string_0_sysvq0asl){
        .bytes_0 = 1852383486u, .more_0 = (&strlit_0_I11209019673050966371_intzsnzax)}
      );
      add_2_sysvq0asl((&X60Qdesugar_63), X60Qdesugar_60);
      add_2_sysvq0asl((&X60Qdesugar_63), (string_0_sysvq0asl){
        .bytes_0 = 1970217214u, .more_0 = (&strlit_0_I9006312985088794180_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_63), X60Qdesugar_61);
      add_2_sysvq0asl((&X60Qdesugar_63), (string_0_sysvq0asl){
        .bytes_0 = 1986076926u, .more_0 = (&strlit_0_I10836411368895577019_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_63), X60Qdesugar_62);
      add_2_sysvq0asl((&X60Qdesugar_63), (string_0_sysvq0asl){
        .bytes_0 = 672258u, .more_0 = NIM_NIL}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_63);
      nimStrDestroy(X60Qdesugar_63);
      nimStrDestroy(X60Qdesugar_62);
      nimStrDestroy(X60Qdesugar_61);
      nimStrDestroy(X60Qdesugar_60);
      nimStrDestroy(X60Qdesugar_59);}}
  NB8 X60Qx_1133 = jitTraceLog_0_run8hsnpi();
  if (X60Qx_1133){
    NI32 X60Qx_1134 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I16930409917808841651_run8hsnpi)}
    );
    NI32 X60Qx_1135 = len_4_sysvq0asl(base_5);
    NI32 X60Qx_1136 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_64 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1134 + X60Qx_1135)) + X60Qx_1136)));
    add_2_sysvq0asl((&X60Qdesugar_64), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I16930409917808841651_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_64), base_5);
    add_2_sysvq0asl((&X60Qdesugar_64), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_64);
    nimStrDestroy(X60Qdesugar_64);}
  result_59 = NIM_TRUE;
  eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
  eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
  eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
  eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
  eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
  return result_59;
  eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
  eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
  eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
  eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
  eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
  return result_59;}
CrossRoute_0_croph25r5 genRoute_0_run8hsnpi(string_0_sysvq0asl base_6){
  CrossRoute_0_croph25r5 result_60;
  result_60 = 3;
  return result_60;}
X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* newCabiProviderGen_0_run8hsnpi(string_0_sysvq0asl soPath_2, seq_0_Igzebks_aow7lb5cq1 entries_0, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_0){
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* result_61;
  eQwasmovedQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi((&result_61));
  Table_0_Ivb80lo_run8hsnpi t_10 = initTable_0_Iag3oaw1_run8hsnpi();
  {
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_28 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_0);
    NI32 X60Qlf_29 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1137 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_28);
        if (X60Qlf_29 < X60Qx_1137){
          {
            X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_2 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_28, X60Qlf_29);
            X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_1138 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((*X60Qii_2));
            putQ_0_I4rb4at_run8hsnpi((&t_10), (*(*X60Qii_2)).d_00.sym_0, X60Qx_1138);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_29));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(result_61);
  void* X60Qx_1139 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi));
  X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* X60Qtmp_169 = ((X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi*)X60Qx_1139);
  string_0_sysvq0asl X60Qx_130 = nimStrDup(soPath_2);
  Table_0_Ivb80lo_run8hsnpi X60Qtmp_170 = t_10;
  eQwasmovedQ_SX54able0X49vb80lo_0_run8hsnpi((&t_10));
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qx_131 = newXProvider_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1650549758u, .more_0 = (&strlit_0_I9558933350530343618_run8hsnpi)}
  , NIM_NIL, genRoute_0_run8hsnpi, attest_0, soPath_2);
  (*X60Qtmp_169) = (X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi){
    .r_00 = 0, .d_00 = (CabiGenProvider_Obj_0_run8hsnpi){
      (&CabiGenProvider_Obj_0_vt_run8hsnpi), .Q.kind_0 = 3, .Q.codec_0 = 1, .Q.policy_0 = 1, .Q.name_0 = (string_0_sysvq0asl){
        .bytes_0 = 1650549758u, .more_0 = (&strlit_0_I9558933350530343618_run8hsnpi)}
      , .Q.resolveFastImpl_0 = NIM_NIL, .Q.marshalArgs_0 = NIM_NIL, .Q.marshalReturn_0 = NIM_NIL, .Q.ownsImpl_0 = cabiGenOwns_0_run8hsnpi, .Q.invoke_0 = cabiGenInvoke_0_run8hsnpi, .soPath_0 = X60Qx_130, .handle_0 = NIM_NIL, .opened_0 = NIM_FALSE, .table_0 = X60Qtmp_170, .arena_0 = ((X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v*)NIM_NIL), .xp_0 = X60Qx_131}}
  ;
  result_61 = ((X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*)X60Qtmp_169);
  eQdestroyQ_SX54able0X49vb80lo_0_run8hsnpi(t_10);
  return result_61;
  eQdestroyQ_SX54able0X49vb80lo_0_run8hsnpi(t_10);
  return result_61;}
X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* newHybridRegistryGen_0_run8hsnpi(string_0_sysvq0asl soPath_3, seq_0_Igzebks_aow7lb5cq1 entries_1, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_1){
  X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* result_62;
  eQwasmovedQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi((&result_62));
  eQdestroyQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi(result_62);
  void* X60Qx_1140 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax));
  X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* X60Qtmp_171 = ((X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax*)X60Qx_1140);
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* X60Qx_1141 = newCabiProviderGen_0_run8hsnpi(soPath_3, entries_1, attest_1);
  seq_0_Ixkko8n_run8hsnpi X60Qx_1142 = newSeqUninit_0_Iyquyq_run8hsnpi(0);
  (*X60Qtmp_171) = (X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax){
    .r_00 = 0, .d_00 = (HybridRegistry_Obj_0_run8hsnpi){
      .provider_0 = X60Qx_1141, .extra_0 = X60Qx_1142}}
  ;
  result_62 = X60Qtmp_171;
  return result_62;}
void addHybridProviderGen_0_run8hsnpi(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* reg_1, string_0_sysvq0asl soPath_4, seq_0_Igzebks_aow7lb5cq1 entries_2, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_2){
  NB8 X60Qx_1143;
  NB8 X60Qx_1144;
  if (reg_1 == NIM_NIL){
    X60Qx_1144 = NIM_TRUE;}
  else {
    NI32 X60Qx_1145 = len_4_sysvq0asl(soPath_4);
    X60Qx_1144 = (X60Qx_1145 == 0);}
  if (X60Qx_1144){
    X60Qx_1143 = NIM_TRUE;}
  else {
    NI32 X60Qx_1146 = len_3_I44vue3_aow7lb5cq1(entries_2);
    X60Qx_1143 = (X60Qx_1146 == 0);}
  if (X60Qx_1143){
    return;}
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* X60Qx_1147 = newCabiProviderGen_0_run8hsnpi(soPath_4, entries_2, attest_2);
  add_0_Ixve43b1_run8hsnpi((&(*reg_1).d_00.extra_0), X60Qx_1147);}
static inline void add_0_Ijteip9_run8hsnpi(seq_0_I3ump14_aow7lb5cq1* s_47, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_17){
  NI32 L_0 = (*s_47).len_0;
  NI32 X60Qx_1155 = capInBytes_0_Iho46001_aow7lb5cq1((*s_47));
  if (X60Qx_1155 < ((NI32)(((NI32)(L_0 * sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*))) + sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)))){
    NB8 X60Qx_1156 = resize_0_Ithn1vs_run8hsnpi(s_47, 1);
    if ((!X60Qx_1156)){
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_17);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_0] = elem_17;}
static inline seq_0_Ixkko8n_run8hsnpi newSeqUninit_0_Iyquyq_run8hsnpi(NI32 size_21){
  seq_0_Ixkko8n_run8hsnpi result_69;
  if (size_21 == 0){
    result_69 = (seq_0_Ixkko8n_run8hsnpi){
      .len_0 = size_21, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Irm6f661_run8hsnpi(size_21);
    void* X60Qx_1158 = alloc_1_sysvq0asl(memSize_2);
    result_69 = (seq_0_Ixkko8n_run8hsnpi){
      .len_0 = size_21, .data_0 = ((X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax**)X60Qx_1158)}
    ;
    if ((!(result_69.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1159 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_69.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_69;}
static inline openArray_0_Ihcf6y9_run8hsnpi toOpenArray_1_Iumnf4i1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_53){
  openArray_0_Ihcf6y9_run8hsnpi result_72;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** X60Qx_1161 = rawData_0_Ix1iq6g1_run8hsnpi(s_53);
  result_72 = (openArray_0_Ihcf6y9_run8hsnpi){
    .a_0 = X60Qx_1161, .len_0 = s_53.len_0}
  ;
  return result_72;}
static inline void add_0_Itzi0i7_run8hsnpi(seq_0_Il8twp61_aow7lb5cq1* s_59, WireField_0_run8hsnpi elem_18){
  NI32 L_1 = (*s_59).len_0;
  NI32 X60Qx_1172 = capInBytes_0_I51wdad1_aow7lb5cq1((*s_59));
  if (X60Qx_1172 < ((NI32)(((NI32)(L_1 * sizeof(WireField_0_run8hsnpi))) + sizeof(WireField_0_run8hsnpi)))){
    NB8 X60Qx_1173 = resize_0_I6di9mo1_run8hsnpi(s_59, 1);
    if ((!X60Qx_1173)){
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&elem_18));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_59).len_0));
  (*s_59).data_0[L_1] = elem_18;}
static inline void add_0_Ibphvmo_run8hsnpi(seq_0_Incv1wn_arecyyj7v* s_75, NU8 elem_22){
  NI32 L_4 = (*s_75).len_0;
  NI32 X60Qx_1185 = capInBytes_0_Iffahgv_arecyyj7v((*s_75));
  if (X60Qx_1185 < ((NI32)(((NI32)(L_4 * sizeof(NU8))) + sizeof(NU8)))){
    NB8 X60Qx_1186 = resize_0_Iuiuhg71_flaksyopx1(s_75, 1);
    if ((!X60Qx_1186)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_75).len_0));
  (*s_75).data_0[L_4] = elem_22;}
static inline NI32 len_3_Irjnvku_run8hsnpi(seq_0_Ik7wkpe_aow7lb5cq1 s_87){
  NI32 result_95;
  result_95 = s_87.len_0;
  return result_95;}
static inline seq_0_Ie7vbta_run8hsnpi newSeqUninit_0_I32zp0x_run8hsnpi(NI32 size_40){
  seq_0_Ie7vbta_run8hsnpi result_98;
  if (size_40 == 0){
    result_98 = (seq_0_Ie7vbta_run8hsnpi){
      .len_0 = size_40, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_12 = memSizeInBytes_0_Ip0vdbh_run8hsnpi(size_40);
    void* X60Qx_1202 = alloc_1_sysvq0asl(memSize_12);
    result_98 = (seq_0_Ie7vbta_run8hsnpi){
      .len_0 = size_40, .data_0 = ((X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi*)X60Qx_1202)}
    ;
    if ((!(result_98.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1203 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_98.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_12);}}
  return result_98;}
static inline void add_0_Ivy8r7k1_run8hsnpi(seq_0_Ie7vbta_run8hsnpi* s_91, X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi elem_26){
  NI32 L_8 = (*s_91).len_0;
  NI32 X60Qx_1204 = capInBytes_0_Ivcwflf1_run8hsnpi((*s_91));
  if (X60Qx_1204 < ((NI32)(((NI32)(L_8 * sizeof(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi))) + sizeof(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi)))){
    NB8 X60Qx_1205 = resize_0_Igrgn3v_run8hsnpi(s_91, 1);
    if ((!X60Qx_1205)){
      eQdestroyQ_AtupleAiS32ZSX56alue0valzr1t4f_0_run8hsnpi((&elem_26));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_91).len_0));
  (*s_91).data_0[L_8] = elem_26;}
static inline openArray_0_Icv4v4b1_run8hsnpi toOpenArray_1_Io2cvnr_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_93){
  openArray_0_Icv4v4b1_run8hsnpi result_99;
  X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* X60Qx_1206 = rawData_0_Ir5lda7_run8hsnpi(s_93);
  result_99 = (openArray_0_Icv4v4b1_run8hsnpi){
    .a_0 = X60Qx_1206, .len_0 = s_93.len_0}
  ;
  return result_99;}
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* getOrDefault_1_Imr3kd01_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_15, NU32 k_6, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* fallback_1){
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* result_100;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&result_100));
  NU32 X60Qx_1207 = hash_0_nifh7u8pu1(k_6);
  NI32 idx_10 = rawGet_0_Ihcxbwv_run8hsnpi(t_15, k_6, X60Qx_1207);
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_68;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&X60Qx_68));
  if (0 <= idx_10){
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qx_68);
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1208 = getQ_7_I46cuah_run8hsnpi(t_15.data_0, idx_10);
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_1209 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((*X60Qx_1208).fld_1);
    X60Qx_68 = X60Qx_1209;}
  else {
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qx_68);
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_1210 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(fallback_1);
    X60Qx_68 = X60Qx_1210;}
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(result_100);
  result_100 = X60Qx_68;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&X60Qx_68));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qx_68);
  return result_100;
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qx_68);
  return result_100;}
static inline NI32 len_0_Ifyaclq_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_17){
  NI32 result_101;
  NI32 X60Qx_1211 = len_3_I849zvk_run8hsnpi(t_17.data_0);
  result_101 = X60Qx_1211;
  return result_101;}
static inline seq_0_Iq1shzq1_run8hsnpi newSeqUninit_0_Ie5g2lj_run8hsnpi(NI32 size_48){
  seq_0_Iq1shzq1_run8hsnpi result_105;
  if (size_48 == 0){
    result_105 = (seq_0_Iq1shzq1_run8hsnpi){
      .len_0 = size_48, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_16 = memSizeInBytes_0_Ifk9c7h1_run8hsnpi(size_48);
    void* X60Qx_1218 = alloc_1_sysvq0asl(memSize_16);
    result_105 = (seq_0_Iq1shzq1_run8hsnpi){
      .len_0 = size_48, .data_0 = ((X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi*)X60Qx_1218)}
    ;
    if ((!(result_105.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1219 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_105.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_16);}}
  return result_105;}
static inline void add_0_Ii05ltt1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi* s_97, X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi elem_27){
  NI32 L_9 = (*s_97).len_0;
  NI32 X60Qx_1220 = capInBytes_0_In8my0q1_run8hsnpi((*s_97));
  if (X60Qx_1220 < ((NI32)(((NI32)(L_9 * sizeof(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi))) + sizeof(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi)))){
    NB8 X60Qx_1221 = resize_0_I5hcuwh1_run8hsnpi(s_97, 1);
    if ((!X60Qx_1221)){
      eQdestroyQ_AtupleSX56alue0valzr1t4fApointer_0_run8hsnpi((&elem_27));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_97).len_0));
  (*s_97).data_0[L_9] = elem_27;}
static inline NI32 len_3_Iibq2ff1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_99){
  NI32 result_106;
  result_106 = s_99.len_0;
  return result_106;}
static inline X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* getQ_7_Ir6lnzn1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_100, NI32 i_59){
  NB8 X60Qx_1222;
  if (i_59 < s_100.len_0){
    X60Qx_1222 = (0 <= i_59);}
  else {
    X60Qx_1222 = NIM_FALSE;}
  if ((!X60Qx_1222)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* result_107;
  result_107 = (&s_100.data_0[i_59]);
  return result_107;}
Table_0_Ivb80lo_run8hsnpi initTable_0_Iag3oaw1_run8hsnpi(void){
  Table_0_Ivb80lo_run8hsnpi result_108;
  eQwasmovedQ_SX54able0X49vb80lo_0_run8hsnpi((&result_108));
  eQdestroyQ_SX54able0X49vb80lo_0_run8hsnpi(result_108);
  seq_0_Iwk350i1_run8hsnpi X60Qx_1223 = newSeqUninit_0_Iyp3d871_run8hsnpi(0);
  seq_0_Ikxuplm1_der823rwr1 X60Qx_1224 = newSeqUninit_0_Iie69x21_der823rwr1(0);
  result_108 = (Table_0_Ivb80lo_run8hsnpi){
    .data_0 = X60Qx_1223, .hashes_0 = X60Qx_1224}
  ;
  return result_108;}
void putQ_0_I4rb4at_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_18, NU32 k_8, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* v_10){
  NU32 h_1 = hash_0_nifh7u8pu1(k_8);
  NI32 idx_12 = rawGet_0_Ihcxbwv_run8hsnpi((*t_18), k_8, h_1);
  if (0 <= idx_12){
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1226 = getQ_7_I46cuah_run8hsnpi((*t_18).data_0, idx_12);
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qlhs_172 = (&(*X60Qx_1226).fld_1);
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qlhs_173 = v_10;
    eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&v_10));
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((*X60Qlhs_172));
    (*X60Qlhs_172) = X60Qlhs_173;}
  else {
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_174 = v_10;
    eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&v_10));
    rawPut_0_Ifxcxpb1_run8hsnpi(t_18, k_8, X60Qtmp_174, h_1);}
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(v_10);}
static inline void add_0_Ixve43b1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi* s_104, X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* elem_28){
  NI32 L_10 = (*s_104).len_0;
  NI32 X60Qx_1227 = capInBytes_0_I0n41e91_run8hsnpi((*s_104));
  if (X60Qx_1227 < ((NI32)(((NI32)(L_10 * sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*))) + sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*)))){
    NB8 X60Qx_1228 = resize_0_I9hyasp_run8hsnpi(s_104, 1);
    if ((!X60Qx_1228)){
      eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(elem_28);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_104).len_0));
  (*s_104).data_0[L_10] = elem_28;}
NB8 resize_0_Ithn1vs_run8hsnpi(seq_0_I3ump14_aow7lb5cq1* dest_11, NI32 addedElements_11){
  NB8 result_116;
  NI32 X60Qx_1232 = capInBytes_0_Iho46001_aow7lb5cq1((*dest_11));
  NI32 oldCap_0 = ((NI32)(X60Qx_1232 / sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_11);
  NI32 memSize_17 = memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(newCap_0);
  void* X60Qx_1233 = realloc_1_sysvq0asl(((void*)((void*)(*dest_11).data_0)), memSize_17);
  (*dest_11).data_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1**)X60Qx_1233);
  if ((*dest_11).data_0 == NIM_NIL){
    (*dest_11).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_17);
    result_116 = NIM_FALSE;}
  else {
    result_116 = NIM_TRUE;}
  return result_116;}
static inline NI32 memSizeInBytes_0_Irm6f661_run8hsnpi(NI32 size_54){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_120;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_54, sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_120 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_120 = ((NI32)2147483647);}
  return result_120;}
static inline X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** rawData_0_Ix1iq6g1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_110){
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** result_121;
  result_121 = s_110.data_0;
  return result_121;}
static inline NI32 len_6_Ij4lmhs_run8hsnpi(openArray_0_Ihcf6y9_run8hsnpi a_24){
  NI32 result_122;
  result_122 = a_24.len_0;
  return result_122;}
static inline X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** getQ_10_Iwwsp9w1_run8hsnpi(openArray_0_Ihcf6y9_run8hsnpi x_15, NI32 idx_14){
  NB8 X60Qx_1235;
  if (0 <= idx_14){
    X60Qx_1235 = (idx_14 < x_15.len_0);}
  else {
    X60Qx_1235 = NIM_FALSE;}
  if ((!X60Qx_1235)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** result_123;
  result_123 = (&x_15.a_0[idx_14]);
  return result_123;}
NB8 resize_0_I6di9mo1_run8hsnpi(seq_0_Il8twp61_aow7lb5cq1* dest_12, NI32 addedElements_12){
  NB8 result_131;
  NI32 X60Qx_1238 = capInBytes_0_I51wdad1_aow7lb5cq1((*dest_12));
  NI32 oldCap_1 = ((NI32)(X60Qx_1238 / sizeof(WireField_0_run8hsnpi)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_12);
  NI32 memSize_18 = memSizeInBytes_0_Io786y61_aow7lb5cq1(newCap_1);
  void* X60Qx_1239 = realloc_1_sysvq0asl(((void*)((void*)(*dest_12).data_0)), memSize_18);
  (*dest_12).data_0 = ((WireField_0_run8hsnpi*)X60Qx_1239);
  if ((*dest_12).data_0 == NIM_NIL){
    (*dest_12).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_18);
    result_131 = NIM_FALSE;}
  else {
    result_131 = NIM_TRUE;}
  return result_131;}
static inline NI32 memSizeInBytes_0_Ip0vdbh_run8hsnpi(NI32 size_63){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_154;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_63, sizeof(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_154 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_154 = ((NI32)2147483647);}
  return result_154;}
static inline NI32 capInBytes_0_Ivcwflf1_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_122){
  NI32 result_155;
  NI32 X60Qx_77;
  if ((!(s_122.data_0 == NIM_NIL))){
    NI32 X60Qx_1262 = allocatedSize_0_sysvq0asl(((void*)((void*)s_122.data_0)));
    X60Qx_77 = X60Qx_1262;}
  else {
    X60Qx_77 = 0;}
  result_155 = X60Qx_77;
  return result_155;}
NB8 resize_0_Igrgn3v_run8hsnpi(seq_0_Ie7vbta_run8hsnpi* dest_19, NI32 addedElements_19){
  NB8 result_156;
  NI32 X60Qx_1263 = capInBytes_0_Ivcwflf1_run8hsnpi((*dest_19));
  NI32 oldCap_8 = ((NI32)(X60Qx_1263 / sizeof(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi)));
  NI32 newCap_8 = recalcCap_0_sysvq0asl(oldCap_8, addedElements_19);
  NI32 memSize_25 = memSizeInBytes_0_Ip0vdbh_run8hsnpi(newCap_8);
  void* X60Qx_1264 = realloc_1_sysvq0asl(((void*)((void*)(*dest_19).data_0)), memSize_25);
  (*dest_19).data_0 = ((X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi*)X60Qx_1264);
  if ((*dest_19).data_0 == NIM_NIL){
    (*dest_19).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_25);
    result_156 = NIM_FALSE;}
  else {
    result_156 = NIM_TRUE;}
  return result_156;}
static inline X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* rawData_0_Ir5lda7_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_123){
  X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* result_157;
  result_157 = s_123.data_0;
  return result_157;}
static inline NI32 len_6_Ivyewcw1_run8hsnpi(openArray_0_Icv4v4b1_run8hsnpi a_28){
  NI32 result_158;
  result_158 = a_28.len_0;
  return result_158;}
static inline X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* getQ_10_Ijhkrt71_run8hsnpi(openArray_0_Icv4v4b1_run8hsnpi x_20, NI32 idx_18){
  NB8 X60Qx_1265;
  if (0 <= idx_18){
    X60Qx_1265 = (idx_18 < x_20.len_0);}
  else {
    X60Qx_1265 = NIM_FALSE;}
  if ((!X60Qx_1265)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* result_159;
  result_159 = (&x_20.a_0[idx_18]);
  return result_159;}
NI32 rawGet_0_Ihcxbwv_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_20, NU32 k_10, NU32 kh_1){
  NI32 result_160;
  NI32 X60Qx_1266 = len_3_I849zvk_run8hsnpi(t_20.data_0);
  if (X60Qx_1266 <= ((NI32)4)){
    {
      NI32 X60Qlf_30 = 0;
      NI32 X60Qlf_31 = len_3_I849zvk_run8hsnpi(t_20.data_0);
      NI32 X60Qlf_32 = X60Qlf_30;
      {
        while (X60Qlf_32 < X60Qlf_31){
          {
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1267 = getQ_7_I46cuah_run8hsnpi(t_20.data_0, X60Qlf_32);
            NB8 X60Qx_1268 = eqQ_0_nifh7u8pu1((*X60Qx_1267).fld_0, k_10);
            if (X60Qx_1268){
              return X60Qlf_32;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_32));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_1269 = high_3_Iyuup9h1_der823rwr1(t_20.hashes_0);
    NU32 h_3 = ((NU32)(kh_1 & ((NU32)X60Qx_1269)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_1270 = getQ_8_Imt2zi01_der823rwr1(t_20.hashes_0, h_3);
        NB8 X60Qx_1271 = isFilled_0_tabcr240b1((*X60Qx_1270));
        if (X60Qx_1271){
          HashEntry_0_tabcr240b1* X60Qx_1272 = getQ_8_Imt2zi01_der823rwr1(t_20.hashes_0, h_3);
          HashEntry_0_tabcr240b1 d_0 = (*X60Qx_1272);
          NB8 X60Qx_1273;
          if (d_0.fullhash_0 == kh_1){
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1274 = getQ_7_I46cuah_run8hsnpi(t_20.data_0, ((NI32)(d_0.position_0 - 1)));
            NB8 X60Qx_1275 = eqQ_0_nifh7u8pu1((*X60Qx_1274).fld_0, k_10);
            X60Qx_1273 = X60Qx_1275;}
          else {
            X60Qx_1273 = NIM_FALSE;}
          if (X60Qx_1273){
            result_160 = ((NI32)(d_0.position_0 - 1));
            return result_160;}
          NI32 X60Qx_1276 = high_3_Iyuup9h1_der823rwr1(t_20.hashes_0);
          NU32 X60Qx_1277 = nextTry_0_has9tn57v(h_3, X60Qx_1276);
          h_3 = X60Qx_1277;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_160 = -1;
  return result_160;}
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* getQ_7_I46cuah_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_126, NI32 i_66){
  NB8 X60Qx_1278;
  if (i_66 < s_126.len_0){
    X60Qx_1278 = (0 <= i_66);}
  else {
    X60Qx_1278 = NIM_FALSE;}
  if ((!X60Qx_1278)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* result_161;
  result_161 = (&s_126.data_0[i_66]);
  return result_161;}
static inline NI32 len_3_I849zvk_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_127){
  NI32 result_162;
  result_162 = s_127.len_0;
  return result_162;}
static inline NI32 memSizeInBytes_0_Ifk9c7h1_run8hsnpi(NI32 size_67){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_166;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_67, sizeof(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_166 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_166 = ((NI32)2147483647);}
  return result_166;}
static inline NI32 capInBytes_0_In8my0q1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_128){
  NI32 result_167;
  NI32 X60Qx_78;
  if ((!(s_128.data_0 == NIM_NIL))){
    NI32 X60Qx_1279 = allocatedSize_0_sysvq0asl(((void*)((void*)s_128.data_0)));
    X60Qx_78 = X60Qx_1279;}
  else {
    X60Qx_78 = 0;}
  result_167 = X60Qx_78;
  return result_167;}
NB8 resize_0_I5hcuwh1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi* dest_20, NI32 addedElements_20){
  NB8 result_168;
  NI32 X60Qx_1280 = capInBytes_0_In8my0q1_run8hsnpi((*dest_20));
  NI32 oldCap_9 = ((NI32)(X60Qx_1280 / sizeof(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi)));
  NI32 newCap_9 = recalcCap_0_sysvq0asl(oldCap_9, addedElements_20);
  NI32 memSize_26 = memSizeInBytes_0_Ifk9c7h1_run8hsnpi(newCap_9);
  void* X60Qx_1281 = realloc_1_sysvq0asl(((void*)((void*)(*dest_20).data_0)), memSize_26);
  (*dest_20).data_0 = ((X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi*)X60Qx_1281);
  if ((*dest_20).data_0 == NIM_NIL){
    (*dest_20).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_26);
    result_168 = NIM_FALSE;}
  else {
    result_168 = NIM_TRUE;}
  return result_168;}
static inline seq_0_Iwk350i1_run8hsnpi newSeqUninit_0_Iyp3d871_run8hsnpi(NI32 size_68){
  seq_0_Iwk350i1_run8hsnpi result_169;
  if (size_68 == 0){
    result_169 = (seq_0_Iwk350i1_run8hsnpi){
      .len_0 = size_68, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_27 = memSizeInBytes_0_I7xitnl1_run8hsnpi(size_68);
    void* X60Qx_1282 = alloc_1_sysvq0asl(memSize_27);
    result_169 = (seq_0_Iwk350i1_run8hsnpi){
      .len_0 = size_68, .data_0 = ((X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi*)X60Qx_1282)}
    ;
    if ((!(result_169.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1283 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_169.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_27);}}
  return result_169;}
void rawPut_0_Ifxcxpb1_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_21, NU32 k_11, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* v_12, NU32 h_4){
  NI32 X60Qx_1287 = len_3_I849zvk_run8hsnpi((*t_21).data_0);
  if (X60Qx_1287 == ((NI32)4)){
    fillHashPart_0_I20rkt9_run8hsnpi(t_21);}
  else {
    NI32 X60Qx_1288 = len_3_Iiefpcc1_der823rwr1((*t_21).hashes_0);
    NI32 X60Qx_1289 = len_3_I849zvk_run8hsnpi((*t_21).data_0);
    NB8 X60Qx_1290 = mustRehash_0_tabcr240b1(X60Qx_1288, X60Qx_1289);
    if (X60Qx_1290){
      resize_0_tabcr240b1((&(*t_21).hashes_0));}}
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_175 = v_12;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&v_12));
  add_0_Ihgv7q7_run8hsnpi((&(*t_21).data_0), (X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi){
    .fld_0 = k_11, .fld_1 = X60Qtmp_175}
  );
  NI32 X60Qx_1291 = high_3_Iyuup9h1_der823rwr1((*t_21).hashes_0);
  NU32 hi_2 = ((NU32)(h_4 & ((NU32)X60Qx_1291)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_1292 = getQ_8_Imt2zi01_der823rwr1((*t_21).hashes_0, hi_2);
      NB8 X60Qx_1293 = isFilled_0_tabcr240b1((*X60Qx_1292));
      if (X60Qx_1293){
        NI32 X60Qx_1294 = high_3_Iyuup9h1_der823rwr1((*t_21).hashes_0);
        NU32 X60Qx_1295 = nextTry_0_has9tn57v(hi_2, X60Qx_1294);
        hi_2 = X60Qx_1295;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_1296 = len_3_I849zvk_run8hsnpi((*t_21).data_0);
  putQ_8_Ipchg2a_der823rwr1((&(*t_21).hashes_0), hi_2, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_4, .position_0 = X60Qx_1296}
  );
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(v_12);}
static inline NI32 capInBytes_0_I0n41e91_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_133){
  NI32 result_174;
  NI32 X60Qx_79;
  if ((!(s_133.data_0 == NIM_NIL))){
    NI32 X60Qx_1297 = allocatedSize_0_sysvq0asl(((void*)((void*)s_133.data_0)));
    X60Qx_79 = X60Qx_1297;}
  else {
    X60Qx_79 = 0;}
  result_174 = X60Qx_79;
  return result_174;}
NB8 resize_0_I9hyasp_run8hsnpi(seq_0_Ixkko8n_run8hsnpi* dest_21, NI32 addedElements_21){
  NB8 result_175;
  NI32 X60Qx_1298 = capInBytes_0_I0n41e91_run8hsnpi((*dest_21));
  NI32 oldCap_10 = ((NI32)(X60Qx_1298 / sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*)));
  NI32 newCap_10 = recalcCap_0_sysvq0asl(oldCap_10, addedElements_21);
  NI32 memSize_29 = memSizeInBytes_0_Irm6f661_run8hsnpi(newCap_10);
  void* X60Qx_1299 = realloc_1_sysvq0asl(((void*)((void*)(*dest_21).data_0)), memSize_29);
  (*dest_21).data_0 = ((X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax**)X60Qx_1299);
  if ((*dest_21).data_0 == NIM_NIL){
    (*dest_21).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_29);
    result_175 = NIM_FALSE;}
  else {
    result_175 = NIM_TRUE;}
  return result_175;}
static inline NI32 memSizeInBytes_0_I7xitnl1_run8hsnpi(NI32 size_72){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_178;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_72, sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_178 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_178 = ((NI32)2147483647);}
  return result_178;}
void fillHashPart_0_I20rkt9_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_23){
  seq_0_Ikxuplm1_der823rwr1* X60Qlhs_176 = (&(*t_23).hashes_0);
  eQdestroy_1_I5skmro_der823rwr1((*X60Qlhs_176));
  seq_0_Ikxuplm1_der823rwr1 X60Qx_1300 = newSeq_0_Iv3lu2h1_der823rwr1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_176) = X60Qx_1300;
  {
    NI32 X60Qlf_33 = 0;
    NI32 X60Qlf_34 = len_3_I849zvk_run8hsnpi((*t_23).data_0);
    NI32 X60Qlf_35 = X60Qlf_33;
    {
      while (X60Qlf_35 < X60Qlf_34){
        {
          X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1301 = getQ_7_I46cuah_run8hsnpi((*t_23).data_0, X60Qlf_35);
          NU32 X60Qii_2 = hash_0_nifh7u8pu1((*X60Qx_1301).fld_0);
          NI32 X60Qx_1302 = high_3_Iyuup9h1_der823rwr1((*t_23).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_1302)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_1303 = getQ_8_Imt2zi01_der823rwr1((*t_23).hashes_0, X60Qii_3);
            NB8 X60Qx_1304 = isFilled_0_tabcr240b1((*X60Qx_1303));
            if (X60Qx_1304){
              NI32 X60Qx_1305 = high_3_Iyuup9h1_der823rwr1((*t_23).hashes_0);
              NU32 X60Qx_1306 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_1305);
              X60Qii_3 = X60Qx_1306;}
            else {
              break;}}
          putQ_8_Ipchg2a_der823rwr1((&(*t_23).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_35 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_35));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_Ihgv7q7_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* s_137, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi elem_31){
  NI32 L_11 = (*s_137).len_0;
  NI32 X60Qx_1307 = capInBytes_0_Ilido7m1_run8hsnpi((*s_137));
  if (X60Qx_1307 < ((NI32)(((NI32)(L_11 * sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi))) + sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi)))){
    NB8 X60Qx_1308 = resize_0_Ie728b71_run8hsnpi(s_137, 1);
    if ((!X60Qx_1308)){
      eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(elem_31);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_137).len_0));
  (*s_137).data_0[L_11] = elem_31;}
static inline NI32 capInBytes_0_Ilido7m1_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_140){
  NI32 result_182;
  NI32 X60Qx_80;
  if ((!(s_140.data_0 == NIM_NIL))){
    NI32 X60Qx_1310 = allocatedSize_0_sysvq0asl(((void*)((void*)s_140.data_0)));
    X60Qx_80 = X60Qx_1310;}
  else {
    X60Qx_80 = 0;}
  result_182 = X60Qx_80;
  return result_182;}
NB8 resize_0_Ie728b71_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* dest_23, NI32 addedElements_23){
  NB8 result_183;
  NI32 X60Qx_1311 = capInBytes_0_Ilido7m1_run8hsnpi((*dest_23));
  NI32 oldCap_11 = ((NI32)(X60Qx_1311 / sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi)));
  NI32 newCap_11 = recalcCap_0_sysvq0asl(oldCap_11, addedElements_23);
  NI32 memSize_31 = memSizeInBytes_0_I7xitnl1_run8hsnpi(newCap_11);
  void* X60Qx_1312 = realloc_1_sysvq0asl(((void*)((void*)(*dest_23).data_0)), memSize_31);
  (*dest_23).data_0 = ((X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi*)X60Qx_1312);
  if ((*dest_23).data_0 == NIM_NIL){
    (*dest_23).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_31);
    result_183 = NIM_FALSE;}
  else {
    result_183 = NIM_TRUE;}
  return result_183;}
void eQdestroy_1_Iuvcrzj_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_187){
  if ((!(s_187.data_0 == NIM_NIL))){
    NI32 i_77 = 0;
    {
      while (i_77 < s_187.len_0){
        eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(s_187.data_0[i_77]);
        inc_1_I6wjjge_aow2h993l1((&i_77));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_187.data_0)));}}
void eQdestroy_1_Ick5hx01_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_200){
  if ((!(s_200.data_0 == NIM_NIL))){
    NI32 i_101 = 0;
    {
      while (i_101 < s_200.len_0){
        eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(s_200.data_0[i_101]);
        inc_1_I6wjjge_aow2h993l1((&i_101));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_200.data_0)));}}
static inline void eQwasMoved_1_I2k3j3n_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* s_201){
  (*s_201).len_0 = 0;
  (*s_201).data_0 = NIM_NIL;}
void eQdestroy_1_I2vp2bj_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_214){
  if ((!(s_214.data_0 == NIM_NIL))){
    NI32 i_125 = 0;
    {
      while (i_125 < s_214.len_0){
        eQdestroyQ_AtupleAiS32ZSX56alue0valzr1t4f_0_run8hsnpi((&s_214.data_0[i_125]));
        inc_1_I6wjjge_aow2h993l1((&i_125));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_214.data_0)));}}
void eQdestroy_1_Imh4l59_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_225){
  if ((!(s_225.data_0 == NIM_NIL))){
    NI32 i_141 = 0;
    {
      while (i_141 < s_225.len_0){
        eQdestroyQ_AtupleSX56alue0valzr1t4fApointer_0_run8hsnpi((&s_225.data_0[i_141]));
        inc_1_I6wjjge_aow2h993l1((&i_141));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_225.data_0)));}}
void eQdestroyQ_SX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(HybridProvider_Obj_0_run8hsnpi* dest_0){
  nimStrDestroy((*dest_0).name_0);}
void eQdestroyQ_SX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi(HybridRegistry_Obj_0_run8hsnpi dest_0){
  eQdestroy_1_Iuvcrzj_run8hsnpi(dest_0.extra_0);
  eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(dest_0.provider_0);}
void eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi(WireField_0_run8hsnpi* dest_0){
  nimStrDestroy((*dest_0).elemSrcType_0);
  nimStrDestroy((*dest_0).elemLeafName_0);
  nimStrDestroy((*dest_0).srcType_0);
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*dest_0).desc_0);}
void eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi(WireField_0_run8hsnpi* dest_0){
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&(*dest_0).desc_0));
  nimStrWasMoved((&(*dest_0).srcType_0));
  nimStrWasMoved((&(*dest_0).elemLeafName_0));
  nimStrWasMoved((&(*dest_0).elemSrcType_0));}
WireField_0_run8hsnpi eQdupQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi(WireField_0_run8hsnpi* src_0){
  WireField_0_run8hsnpi dest_0;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_1457 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*src_0).desc_0);
  dest_0.desc_0 = X60Qx_1457;
  string_0_sysvq0asl X60Qx_1458 = nimStrDup((*src_0).srcType_0);
  dest_0.srcType_0 = X60Qx_1458;
  dest_0.isEnum_0 = (*src_0).isEnum_0;
  dest_0.isVar_0 = (*src_0).isVar_0;
  dest_0.isRef_0 = (*src_0).isRef_0;
  dest_0.isArenaRef_0 = (*src_0).isArenaRef_0;
  dest_0.isArenaPtr_0 = (*src_0).isArenaPtr_0;
  dest_0.isPtrArena_0 = (*src_0).isPtrArena_0;
  dest_0.isForeignPtr_0 = (*src_0).isForeignPtr_0;
  dest_0.isSink_0 = (*src_0).isSink_0;
  dest_0.isPod_0 = (*src_0).isPod_0;
  dest_0.isComposite_0 = (*src_0).isComposite_0;
  dest_0.isString_0 = (*src_0).isString_0;
  dest_0.isSeq_0 = (*src_0).isSeq_0;
  dest_0.isArray_0 = (*src_0).isArray_0;
  dest_0.arrCount_0 = (*src_0).arrCount_0;
  dest_0.elemVarLen_0 = (*src_0).elemVarLen_0;
  string_0_sysvq0asl X60Qx_1459 = nimStrDup((*src_0).elemLeafName_0);
  dest_0.elemLeafName_0 = X60Qx_1459;
  dest_0.enumSym_0 = (*src_0).enumSym_0;
  dest_0.typeSym_0 = (*src_0).typeSym_0;
  dest_0.wireSize_0 = (*src_0).wireSize_0;
  dest_0.wireAlign_0 = (*src_0).wireAlign_0;
  string_0_sysvq0asl X60Qx_1460 = nimStrDup((*src_0).elemSrcType_0);
  dest_0.elemSrcType_0 = X60Qx_1460;
  dest_0.elemSize_0 = (*src_0).elemSize_0;
  dest_0.elemStride_0 = (*src_0).elemStride_0;
  dest_0.elemTypeSym_0 = (*src_0).elemTypeSym_0;
  return dest_0;}
void eQdestroyQ_SX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(ShimEntry_Obj_0_run8hsnpi* dest_0){
  eQdestroy_1_Ij4pznj1_aow7lb5cq1((*dest_0).noDerefOffs_0);
  nimStrDestroy((*dest_0).redeclProc_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1((*dest_0).redeclTypes_0);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1((*dest_0).outVarOffs_0);
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&(*dest_0).ret_0));
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1((*dest_0).argOffs_0);
  eQdestroy_1_Iksn09f_aow7lb5cq1((*dest_0).args_0);
  nimStrDestroy((*dest_0).shimSym_0);
  nimStrDestroy((*dest_0).base_0);}
void eQdestroyQ_SX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(CabiGenProvider_Obj_0_run8hsnpi* dest_0){
  eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_run8hsnpi((*dest_0).xp_0);
  eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_run8hsnpi((*dest_0).arena_0);
  eQdestroyQ_SX54able0X49vb80lo_0_run8hsnpi((*dest_0).table_0);
  nimStrDestroy((*dest_0).soPath_0);
  eQdestroyQ_SX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi((&(*dest_0).Q));}
void eQtraceQ_SX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(CabiGenProvider_Obj_0_run8hsnpi* dest_0, void* src_0){
  eQtraceQ_ArefSX41renaX4fbj0arewp645e1_0_run8hsnpi((&(*dest_0).arena_0), src_0);
  eQtraceQ_ArefSX58X50roviderX4fbj0croph25r5_0_run8hsnpi((&(*dest_0).xp_0), src_0);}
void eQdestroyQ_SX54able0X49vb80lo_0_run8hsnpi(Table_0_Ivb80lo_run8hsnpi dest_0){
  eQdestroy_1_I5skmro_der823rwr1(dest_0.hashes_0);
  eQdestroy_1_Ick5hx01_run8hsnpi(dest_0.data_0);}
void eQwasmovedQ_SX54able0X49vb80lo_0_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* dest_0){
  eQwasMoved_1_I2k3j3n_run8hsnpi((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_der823rwr1((&(*dest_0).hashes_0));}
void eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_1485 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1485){
      HybridProvider_Obj_0_run8hsnpi* X60QvtableTemp_6 = (&(*dest_0).d_00);
      ((X60Qt_0_ISX48ybridX50roviderX4fbj0run8hsnpiSEAnimcallZAfalseZAR45_intzsnzax)(*(*X60QvtableTemp_6).Q.vt_00).mt_0[0])((&(*X60QvtableTemp_6)));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_1486 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1486){
      eQdestroyQ_SX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_1488 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1488){
      eQdestroyQ_SX54ypeX44escX4fbj0layptix6a1_0_layptix6a1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* src_0){
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_1489 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1489){
      eQdestroyQ_SX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* dest_0){
  if (dest_0){
    NB8 X60Qx_1490 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1490){
      CabiGenProvider_Obj_0_run8hsnpi* X60QvtableTemp_8 = (&(*dest_0).d_00);
      ((X60Qt_0_ISX43abiX47enX50roviderX4fbj0run8hsnpiSEAnimcallZAfalseZAR48_run8hsnpi)(*(*X60QvtableTemp_8).Q.Q.vt_00).mt_0[1])((&(*X60QvtableTemp_8)));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_run8hsnpi(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_1491 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1491){
      eQdestroyQ_SX58X50roviderX4fbj0croph25r5_0_croph25r5((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_run8hsnpi(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* dest_0){
  if (dest_0){
    NB8 X60Qx_1492 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1492){
      eQdestroyQ_SX41renaX4fbj0arewp645e1_0_arewp645e1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQtraceQ_ArefSX41renaX4fbj0arewp645e1_0_run8hsnpi(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v** dest_0, void* src_0){
  }
void eQtraceQ_ArefSX58X50roviderX4fbj0croph25r5_0_run8hsnpi(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1** dest_0, void* src_0){
  }
void eQwasmovedQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi* dest_0){
  eQwasMoved_0_nifb6mq6y1((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi dest_0){
  eQdestroy_0_nifb6mq6y1((&dest_0.fld_0));}
void eQwasmovedQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi* dest_0){
  nimStrWasMoved((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi dest_0){
  nimStrDestroy(dest_0.fld_0);}
void eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21* dest_0){
  nimStrWasMoved((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 dest_0){
  nimStrDestroy(dest_0.fld_0);}
void eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi dest_0){
  eQdestroy_1_Iscb4i31_arecyyj7v(dest_0.fld_1);
  eQdestroy_1_Iscb4i31_arecyyj7v(dest_0.fld_2);}
void eQwasmovedQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi(X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi* dest_0){
  eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi(X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi* dest_0){
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&(*dest_0).fld_0));}
void eQwasmovedQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax* dest_0){
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax dest_0){
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(dest_0.fld_0);}
void eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1493 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1493){
      eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1494 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1494){
      eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1495 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1495){
      eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi* dest_0){
  eQwasMoved_1_I2k4kel_arecyyj7v((&(*dest_0).fld_1));
  eQwasMoved_1_I2k4kel_arecyyj7v((&(*dest_0).fld_2));}
void eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_run8hsnpi(X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 dest_0){
  nimStrDestroy(dest_0.fld_2);}
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1496 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1496){
      eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1497 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1497){
      eQdestroyQ_SX43ellX4fbj0valzr1t4f_0_valzr1t4f((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_run8hsnpi(X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_0));}
X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* eQdupQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* src_0){
  X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* src_0){
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_AtupleAiS32ZSX56alue0valzr1t4f_0_run8hsnpi(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_1));}
void eQdestroyQ_AtupleSX56alue0valzr1t4fApointer_0_run8hsnpi(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* dest_0){
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*dest_0).fld_0));}
void eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi dest_0){
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(dest_0.fld_1);}
void X60Qini_0_run8hsnpi(void){
  if (X60QiniGuard_0_run8hsnpi){
    return;}
  X60QiniGuard_0_run8hsnpi = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_decqocs071();
  X60Qini_0_prorcx25w1();
  X60Qini_0_modzy18mg1();
  X60Qini_0_tagygirdh1();
  X60Qini_0_symkyk35i1();
  X60Qini_0_tabcr240b1();
  X60Qini_0_envto7w6l1();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_aowqg5vb41();
  X60Qini_0_layptix6a1();
  X60Qini_0_heapjafyf1();
  X60Qini_0_marbdjk4t1();
  X60Qini_0_valzr1t4f();
  X60Qini_0_arewp645e1();
  X60Qini_0_arecyyj7v();
  X60Qini_0_flaksyopx1();
  X60Qini_0_natd5co251();
  X60Qini_0_runot4689();
  X60Qini_0_der823rwr1();
  X60Qini_0_croph25r5();}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13){
  NU32 result_16;
  PackedToken_0_nifh7u8pu1 X60Qx_36 = load_0_nifb6mq6y1(c_13);
  NU32 X60Qx_37 = tagId_0_nifh7u8pu1(X60Qx_36);
  result_16 = X60Qx_37;
  return result_16;}
static inline string_0_sysvq0asl* getQ_0_I93d71y_der823rwr1(BiTable_0_Icvz6lt_buiyylk1h1 t_5, NU32 litId_1){
  string_0_sysvq0asl* result_13;
  NI32 idx_0 = ((NI32)(((NI32)litId_1) - ((NI32)1)));
  if ((!(idx_0 < t_5.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  string_0_sysvq0asl* X60Qx_187 = getQ_7_Ir6d0tw_aow7lb5cq1(t_5.vals_0, idx_0);
  result_13 = X60Qx_187;
  return result_13;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1){
  Cursor_0_nifb6mq6y1 result_4;
  result_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = src_1.owner_0, .p_0 = src_1.p_0, .rem_0 = src_1.rem_0}
  ;
  if ((!(result_4.owner_0 == NIM_NIL))){
    inc_1_I6wjjge_aow2h993l1((&(*result_4.owner_0).rc_0));}
  return result_4;}
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18){
  if ((!(0 < (*c_18).rem_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  (*c_18).p_0 = ((PackedToken_0_nifh7u8pu1*)((NU32)(((NU32)(*c_18).p_0) + ((NU32)sizeof(PackedToken_0_nifh7u8pu1)))));
  dec_1_I0nzoz91_aow7lb5cq1((&(*c_18).rem_0));}
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14){
  NU32 result_17;
  PackedToken_0_nifh7u8pu1 X60Qx_38 = load_0_nifb6mq6y1(c_14);
  NU32 X60Qx_39 = tag_0_nifh7u8pu1(X60Qx_38);
  result_17 = X60Qx_39;
  return result_17;}
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8){
  NU32 result_11;
  PackedToken_0_nifh7u8pu1 X60Qx_26 = load_0_nifb6mq6y1(c_8);
  NU32 X60Qx_27 = symId_0_nifh7u8pu1(X60Qx_26);
  result_11 = X60Qx_27;
  return result_11;}
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
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline seq_0_Ie088gc_heapjafyf1 newSeqUninit_0_Inwn9fa_heapjafyf1(NI32 size_4){
  seq_0_Ie088gc_heapjafyf1 result_19;
  if (size_4 == 0){
    result_19 = (seq_0_Ie088gc_heapjafyf1){
      .len_0 = size_4, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Ilxpm6v1_heapjafyf1(size_4);
    void* X60Qx_23 = alloc_1_sysvq0asl(memSize_1);
    result_19 = (seq_0_Ie088gc_heapjafyf1){
      .len_0 = size_4, .data_0 = ((seq_0_I3ump14_aow7lb5cq1*)X60Qx_23)}
    ;
    if ((!(result_19.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_24 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_19.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_19;}
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
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
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10){
  NU32 result_13;
  PackedToken_0_nifh7u8pu1 X60Qx_30 = load_0_nifb6mq6y1(c_10);
  NU32 X60Qx_31 = intId_0_nifh7u8pu1(X60Qx_30);
  result_13 = X60Qx_31;
  return result_13;}
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6){
  NI64* result_4;
  NI32 idx_1 = ((NI32)(((NI32)litId_6) - ((NI32)1)));
  if ((!(idx_1 < t_7.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NI64* X60Qx_32 = getQ_7_Ite3z0o_ast8ri79k(t_7.vals_0, idx_1);
  result_4 = X60Qx_32;
  return result_4;}
static inline void eQwasMoved_1_Iba95rl_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1* s_106){
  (*s_106).len_0 = 0;
  (*s_106).data_0 = NIM_NIL;}
static inline openArray_0_I3ca6t4_layptix6a1 toOpenArray_1_I0zz6qv1_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_8){
  openArray_0_I3ca6t4_layptix6a1 result_23;
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_193 = rawData_0_I2xua2q_layptix6a1(s_8);
  result_23 = (openArray_0_I3ca6t4_layptix6a1){
    .a_0 = X60Qx_193, .len_0 = s_8.len_0}
  ;
  return result_23;}
static inline NI32 len_6_I0tpktl1_layptix6a1(openArray_0_I3ca6t4_layptix6a1 a_18){
  NI32 result_34;
  result_34 = a_18.len_0;
  return result_34;}
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_10_Ikixp7k_layptix6a1(openArray_0_I3ca6t4_layptix6a1 x_3, NI32 idx_2){
  NB8 X60Qx_205;
  if (0 <= idx_2){
    X60Qx_205 = (idx_2 < x_3.len_0);}
  else {
    X60Qx_205 = NIM_FALSE;}
  if ((!X60Qx_205)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** result_35;
  result_35 = (&x_3.a_0[idx_2]);
  return result_35;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67){
  openArray_0_Ijk0jkw1_aow7lb5cq1 result_146;
  NC8* X60Qx_316 = readRawData_0_sysvq0asl((&(*s_67)), 0);
  NI32 X60Qx_317 = len_4_sysvq0asl((*s_67));
  result_146 = (openArray_0_Ijk0jkw1_aow7lb5cq1){
    .a_0 = X60Qx_316, .len_0 = X60Qx_317}
  ;
  return result_146;}
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
static inline NI32 len_3_I5m68tr1_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_33){
  NI32 result_71;
  result_71 = s_33.len_0;
  return result_71;}
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
static inline NI32 align_0_layptix6a1(NI32 address_0, NI32 alignment_0){
  NI32 result_1;
  result_1 = ((NI32)(((NI32)(address_0 + ((NI32)(alignment_0 - 1)))) & ((NI32) ~ ((NI32)(alignment_0 - 1)))));
  return result_1;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
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
static inline void minusQeQ_0_Ipe1u69_hos5i19e11(NI32* x_5, NI32 y_1){
  (*x_5) = ((NI32)((*x_5) - y_1));}
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
static inline openArray_0_Iczu4791_aow7lb5cq1 toOpenArray_1_I0ef4be1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_29){
  openArray_0_Iczu4791_aow7lb5cq1 result_68;
  WireField_0_run8hsnpi* X60Qx_2274 = rawData_0_Ijd497p_aow7lb5cq1(s_29);
  result_68 = (openArray_0_Iczu4791_aow7lb5cq1){
    .a_0 = X60Qx_2274, .len_0 = s_29.len_0}
  ;
  return result_68;}
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
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_2292 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_2292 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_2293 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_2293)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
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
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline void putQ_7_Ipw0nqk1_explnj22x1(seq_0_Incv1wn_arecyyj7v* s_29, NI32 i_26, NU8 elem_9){
  NB8 X60Qx_1414;
  if (i_26 < (*s_29).len_0){
    X60Qx_1414 = (0 <= i_26);}
  else {
    X60Qx_1414 = NIM_FALSE;}
  if ((!X60Qx_1414)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_aow7lb5cq1)}
    );}
  (*s_29).data_0[i_26] = elem_9;}
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
static inline NI32 len_3_I83dzei_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_25){
  NI32 result_26;
  result_26 = s_25.len_0;
  return result_26;}
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45){
  NI32 result_83;
  result_83 = s_45.len_0;
  return result_83;}
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
static inline void eQwasMoved_1_I861g1c1_arecyyj7v(seq_0_Incv1wn_arecyyj7v* s_79){
  (*s_79).len_0 = 0;
  (*s_79).data_0 = NIM_NIL;}
static inline NI32 len_3_Izoe8zv_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_31){
  NI32 result_30;
  result_30 = s_31.len_0;
  return result_30;}
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
static inline void add_0_I34il1q_der823rwr1(seq_0_In6doa_arecyyj7v* s_12, NU32 elem_2){
  NI32 L_0 = (*s_12).len_0;
  NI32 X60Qx_190 = capInBytes_0_Iev6wua1_arecyyj7v((*s_12));
  if (X60Qx_190 < ((NI32)(((NI32)(L_0 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_191 = resize_0_I6ho9ve_buiyylk1h1(s_12, 1);
    if ((!X60Qx_191)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_12).len_0));
  (*s_12).data_0[L_0] = elem_2;}
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
static inline openArray_0_Is74e021_explnj22x1 toOpenArray_1_Itrkyf61_explnj22x1(seq_0_Incv1wn_arecyyj7v s_27){
  openArray_0_Is74e021_explnj22x1 result_52;
  NU8* X60Qx_1412 = rawData_0_Ihjhfzs_explnj22x1(s_27);
  result_52 = (openArray_0_Is74e021_explnj22x1){
    .a_0 = X60Qx_1412, .len_0 = s_27.len_0}
  ;
  return result_52;}
static inline NI32 len_6_Itc4yka_explnj22x1(openArray_0_Is74e021_explnj22x1 a_42){
  NI32 result_69;
  result_69 = a_42.len_0;
  return result_69;}
static inline NU8* getQ_10_Ikgj4ax_explnj22x1(openArray_0_Is74e021_explnj22x1 x_33, NI32 idx_5){
  NB8 X60Qx_1473;
  if (0 <= idx_5){
    X60Qx_1473 = (idx_5 < x_33.len_0);}
  else {
    X60Qx_1473 = NIM_FALSE;}
  if ((!X60Qx_1473)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  NU8* result_70;
  result_70 = (&x_33.a_0[idx_5]);
  return result_70;}
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
static inline Value_0_valzr1t4f vPtrLoc_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1){
  Value_0_valzr1t4f result_18;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_18));
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_69 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_valzr1t4f(c_1);
  result_18 = (Value_0_valzr1t4f){
    .kind_0 = 13, .loc_0 = X60Qx_69, .ov_0 = ((X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v*)NIM_NIL)}
  ;
  return result_18;}
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
static inline void add_0_Itre92n_intzsnzax(seq_0_I50urnw_croph25r5* s_140, Value_0_valzr1t4f elem_31){
  NI32 L_2 = (*s_140).len_0;
  NI32 X60Qx_3738 = capInBytes_0_Ihvsegh1_croph25r5((*s_140));
  if (X60Qx_3738 < ((NI32)(((NI32)(L_2 * sizeof(Value_0_valzr1t4f))) + sizeof(Value_0_valzr1t4f)))){
    NB8 X60Qx_3739 = resize_0_Iz8tg361_intzsnzax(s_140, 1);
    if ((!X60Qx_3739)){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&elem_31));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_140).len_0));
  (*s_140).data_0[L_2] = elem_31;}
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_143, NI32 i_95){
  NB8 X60Qx_3740;
  if (i_95 < s_143.len_0){
    X60Qx_3740 = (0 <= i_95);}
  else {
    X60Qx_3740 = NIM_FALSE;}
  if ((!X60Qx_3740)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  Value_0_valzr1t4f* result_192;
  result_192 = (&s_143.data_0[i_95]);
  return result_192;}
static inline void nimInvalidObjConv(string_0_sysvq0asl name_0){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1986947582u, .more_0 = (&strlit_0_I15539159382304113184_sysvq0asl)}
  );
  writeErr_2_sysvq0asl(name_0);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  exit(((NI32)1));}
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_142){
  NI32 result_191;
  result_191 = s_142.len_0;
  return result_191;}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline openArray_0_In0ukmu_aow7lb5cq1 toOpenArray_1_Ijdwnsz_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_60){
  openArray_0_In0ukmu_aow7lb5cq1 result_93;
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qx_2309 = rawData_0_Izez9p81_aow7lb5cq1(s_60);
  result_93 = (openArray_0_In0ukmu_aow7lb5cq1){
    .a_0 = X60Qx_2309, .len_0 = s_60.len_0}
  ;
  return result_93;}
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
static inline NI32 len_3_I44vue3_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_59){
  NI32 result_92;
  result_92 = s_59.len_0;
  return result_92;}
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
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0){
  NU32 result_11;
  NU32 X60Qx_20 = hash_2_has9tn57v(x_0);
  result_11 = X60Qx_20;
  return result_11;}
static inline seq_0_Ikxuplm1_der823rwr1 newSeqUninit_0_Iie69x21_der823rwr1(NI32 size_10){
  seq_0_Ikxuplm1_der823rwr1 result_22;
  if (size_10 == 0){
    result_22 = (seq_0_Ikxuplm1_der823rwr1){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_Ilp7p16_der823rwr1(size_10);
    void* X60Qx_205 = alloc_1_sysvq0asl(memSize_3);
    result_22 = (seq_0_Ikxuplm1_der823rwr1){
      .len_0 = size_10, .data_0 = ((HashEntry_0_tabcr240b1*)X60Qx_205)}
    ;
    if ((!(result_22.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_206 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_22.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_22;}
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
static inline NI32 high_3_Iyuup9h1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_28){
  NI32 result_35;
  result_35 = ((NI32)(s_28.len_0 - 1));
  return result_35;}
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_29, NU32 i_17){
  if ((!(i_17 < ((NU32)s_29.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  HashEntry_0_tabcr240b1* result_36;
  result_36 = (&s_29.data_0[((NI32)i_17)]);
  return result_36;}
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2){
  NB8 result_1;
  result_1 = (0 < a_2.position_0);
  return result_1;}
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0){
  NU32 result_14;
  result_14 = ((NU32)(((NU32)(h_2 + 1u)) & ((NU32)maxHash_0)));
  return result_14;}
static inline NI32 len_3_Iiefpcc1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_30){
  NI32 result_37;
  result_37 = s_30.len_0;
  return result_37;}
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0){
  NB8 result_0;
  NB8 X60Qx_2;
  if (length_0 < ((NI32)(((NI32)(counter_0 / 2)) + counter_0))){
    X60Qx_2 = NIM_TRUE;}
  else {
    X60Qx_2 = (((NI32)(length_0 - counter_0)) < 4);}
  result_0 = X60Qx_2;
  return result_0;}
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7){
  if ((!(i_19 < ((NU32)(*s_33).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_33).data_0[((NI32)i_19)] = elem_7;}
static inline void eQwasMoved_1_I8aeezd1_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82){
  (*s_82).len_0 = 0;
  (*s_82).data_0 = NIM_NIL;}
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3){
  PackedToken_0_nifh7u8pu1 result_7;
  NB8 X60Qx_21;
  if ((!(c_3.p_0 == NIM_NIL))){
    X60Qx_21 = (0 < c_3.rem_0);}
  else {
    X60Qx_21 = NIM_FALSE;}
  if ((!X60Qx_21)){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_7 = (*c_3.p_0);
  return result_7;}
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15){
  NU32 result_42;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_15.x_0 & ((NU32)15u)))) == 11))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    string_0_sysvq0asl X60Qtmp_9 = dollarX60Q_NifKind_0_nif81dubp1(((NifKind_0_nif81dubp1)((NU32)(n_15.x_0 & ((NU32)15u)))));
    write_0_syn1lfpjv(stdout, X60Qtmp_9);
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);
    nimStrDestroy(X60Qtmp_9);}
  result_42 = ((NU32)((NU32)(n_15.x_0 >> ((NU32)4u))));
  return result_42;}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16){
  NU32 result_43;
  if (((NifKind_0_nif81dubp1)((NU32)(n_16.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_88 = tagId_0_nifh7u8pu1(n_16);
    result_43 = X60Qx_88;}
  else {
    result_43 = ErrT_0_nifh7u8pu1;}
  return result_43;}
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11){
  NU32 result_38;
  NU16 X60Qdesugar_2 = 48u;
  NU64 X60Qdesugar_3 = ((NU)((NifKind_0_nif81dubp1)((NU32)(n_11.x_0 & ((NU32)15u)))));
  if ((!(((NU16)(X60Qdesugar_2 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_3 & 15u)))))) != 0u))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_38 = ((NU32)((NU32)(n_11.x_0 >> ((NU32)4u))));
  return result_38;}
static inline NI32 memSizeInBytes_0_Ilxpm6v1_heapjafyf1(NI32 size_7){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_22;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_7, sizeof(seq_0_I3ump14_aow7lb5cq1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_22 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_22 = ((NI32)2147483647);}
  return result_22;}
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12){
  NU32 result_39;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_12.x_0 & ((NU32)15u)))) == 8))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_39 = ((NU32)((NU32)(n_12.x_0 >> ((NU32)4u))));
  return result_39;}
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6){
  NB8 X60Qx_53;
  if (i_6 < s_9.len_0){
    X60Qx_53 = (0 <= i_6);}
  else {
    X60Qx_53 = NIM_FALSE;}
  if ((!X60Qx_53)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NI64* result_10;
  result_10 = (&s_9.data_0[i_6]);
  return result_10;}
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** rawData_0_I2xua2q_layptix6a1(seq_0_I3ump14_aow7lb5cq1 s_20){
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** result_33;
  result_33 = s_20.data_0;
  return result_33;}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0){
  NC8* result_103;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_39).bytes_0))))){
    result_103 = ((NC8*)((NU32)(((NU32)(&(*(*s_39).more_0).data_0[0])) + ((NU32)start_0))));}
  else {
    result_103 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_39).bytes_0)) + 1u)))) + ((NU32)start_0))));}
  return result_103;}
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
static inline WireField_0_run8hsnpi* rawData_0_Ijd497p_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_64){
  WireField_0_run8hsnpi* result_95;
  result_95 = s_64.data_0;
  return result_95;}
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
static inline NU8* rawData_0_Ihjhfzs_explnj22x1(seq_0_Incv1wn_arecyyj7v s_70){
  NU8* result_68;
  result_68 = s_70.data_0;
  return result_68;}
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
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** rawData_0_Izez9p81_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_72){
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** result_123;
  result_123 = s_72.data_0;
  return result_123;}
static inline NU32 hash_2_has9tn57v(NU32 u_0){
  NU32 result_3;
  result_3 = u_0;
  return result_3;}
static inline NI32 memSizeInBytes_0_Ilp7p16_der823rwr1(NI32 size_15){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_33;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_15, sizeof(HashEntry_0_tabcr240b1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_33 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_33 = ((NI32)2147483647);}
  return result_33;}
