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
typedef struct seq_0_Incv1wn_arecyyj7v{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_arecyyj7v;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
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
typedef struct X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi{
  NB8 fld_0;
  seq_0_In6doa_arecyyj7v fld_1;
  seq_0_In6doa_arecyyj7v fld_2;}
X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
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
Value_0_valzr1t4f scalarFromBits_0_run8hsnpi(NU64 u_2, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_9);
X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi podFieldInfo_1_run8hsnpi(NU32 typeSym_2);
static inline void add_0_Ijteip9_run8hsnpi(seq_0_I3ump14_aow7lb5cq1* s_46, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_17);
static inline seq_0_Ixkko8n_run8hsnpi newSeqUninit_0_Iyquyq_run8hsnpi(NI32 size_21);
static inline openArray_0_Ihcf6y9_run8hsnpi toOpenArray_1_Iumnf4i1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_52);
static inline void add_0_Itzi0i7_run8hsnpi(seq_0_Il8twp61_aow7lb5cq1* s_56, WireField_0_run8hsnpi elem_18);
static inline void add_0_Ibphvmo_run8hsnpi(seq_0_Incv1wn_arecyyj7v* s_72, NU8 elem_22);
static inline NI32 len_3_Irjnvku_run8hsnpi(seq_0_Ik7wkpe_aow7lb5cq1 s_83);
static inline seq_0_Ie7vbta_run8hsnpi newSeqUninit_0_I32zp0x_run8hsnpi(NI32 size_40);
static inline void add_0_Ivy8r7k1_run8hsnpi(seq_0_Ie7vbta_run8hsnpi* s_87, X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi elem_26);
static inline openArray_0_Icv4v4b1_run8hsnpi toOpenArray_1_Io2cvnr_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_89);
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* getOrDefault_1_Imr3kd01_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_15, NU32 k_6, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* fallback_1);
static inline NI32 len_0_Ifyaclq_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_17);
static inline seq_0_Iq1shzq1_run8hsnpi newSeqUninit_0_Ie5g2lj_run8hsnpi(NI32 size_48);
static inline void add_0_Ii05ltt1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi* s_93, X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi elem_27);
static inline NI32 len_3_Iibq2ff1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_95);
static inline X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* getQ_7_Ir6lnzn1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_96, NI32 i_55);
Table_0_Ivb80lo_run8hsnpi initTable_0_Iag3oaw1_run8hsnpi(void);
void putQ_0_I4rb4at_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_18, NU32 k_8, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* v_10);
static inline void add_0_Ixve43b1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi* s_100, X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* elem_28);
NB8 resize_0_Ithn1vs_run8hsnpi(seq_0_I3ump14_aow7lb5cq1* dest_11, NI32 addedElements_11);
static inline NI32 memSizeInBytes_0_Irm6f661_run8hsnpi(NI32 size_54);
static inline X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** rawData_0_Ix1iq6g1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_106);
static inline NI32 len_6_Ij4lmhs_run8hsnpi(openArray_0_Ihcf6y9_run8hsnpi a_24);
static inline X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** getQ_10_Iwwsp9w1_run8hsnpi(openArray_0_Ihcf6y9_run8hsnpi x_15, NI32 idx_14);
NB8 resize_0_I6di9mo1_run8hsnpi(seq_0_Il8twp61_aow7lb5cq1* dest_12, NI32 addedElements_12);
static inline NI32 memSizeInBytes_0_Ip0vdbh_run8hsnpi(NI32 size_63);
static inline NI32 capInBytes_0_Ivcwflf1_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_116);
NB8 resize_0_Igrgn3v_run8hsnpi(seq_0_Ie7vbta_run8hsnpi* dest_19, NI32 addedElements_19);
static inline X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* rawData_0_Ir5lda7_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_117);
static inline NI32 len_6_Ivyewcw1_run8hsnpi(openArray_0_Icv4v4b1_run8hsnpi a_28);
static inline X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* getQ_10_Ijhkrt71_run8hsnpi(openArray_0_Icv4v4b1_run8hsnpi x_19, NI32 idx_18);
NI32 rawGet_0_Ihcxbwv_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_20, NU32 k_10, NU32 kh_1);
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* getQ_7_I46cuah_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_120, NI32 i_61);
static inline NI32 len_3_I849zvk_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_121);
static inline NI32 memSizeInBytes_0_Ifk9c7h1_run8hsnpi(NI32 size_67);
static inline NI32 capInBytes_0_In8my0q1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_122);
NB8 resize_0_I5hcuwh1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi* dest_20, NI32 addedElements_20);
static inline seq_0_Iwk350i1_run8hsnpi newSeqUninit_0_Iyp3d871_run8hsnpi(NI32 size_68);
void rawPut_0_Ifxcxpb1_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_21, NU32 k_11, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* v_12, NU32 h_4);
static inline NI32 capInBytes_0_I0n41e91_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_127);
NB8 resize_0_I9hyasp_run8hsnpi(seq_0_Ixkko8n_run8hsnpi* dest_21, NI32 addedElements_21);
static inline NI32 memSizeInBytes_0_I7xitnl1_run8hsnpi(NI32 size_72);
void fillHashPart_0_I20rkt9_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_23);
static inline void add_0_Ihgv7q7_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* s_131, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi elem_31);
static inline NI32 capInBytes_0_Ilido7m1_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_134);
NB8 resize_0_Ie728b71_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* dest_23, NI32 addedElements_23);
void eQdestroy_1_I2vp2bj_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_208);
void eQdestroy_1_Imh4l59_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_219);
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
void eQwasmovedQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi(X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi* dest_0);
void eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi(X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi* dest_0);
void eQwasmovedQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax* dest_0);
void eQdestroyQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax dest_0);
void eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** dest_0);
void eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
void eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi dest_0);
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
void eQwasmovedQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi* dest_0);
void eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_run8hsnpi(X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 dest_0);
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0);
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0);
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0);
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
extern NB8 routeLog_0_croph25r5;
extern string_0_sysvq0asl blockerReason_0_croph25r5(void);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
extern void eQdestroyQ_SX43rossX4futcome0croph25r5_0_croph25r5(CrossOutcome_0_croph25r5* dest_0);
extern string_0_sysvq0asl getEnv_0_envto7w6l1(string_0_sysvq0asl key_1, string_0_sysvq0asl default_0);
static inline openArray_0_Ijk0jkw1_aow7lb5cq1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67);
static inline NI32 len_6_Iroq7kd1_aow7lb5cq1(openArray_0_Ijk0jkw1_aow7lb5cq1 a_27);
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
static inline X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** getQ_7_I45w7c91_aow7lb5cq1(seq_0_I3ump14_aow7lb5cq1 s_34, NI32 i_31);
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
static inline NI32 len_6_Ier6z6r1_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 a_26);
static inline WireField_0_run8hsnpi* getQ_10_Id2924z_aow7lb5cq1(openArray_0_Iczu4791_aow7lb5cq1 x_11, NI32 idx_5);
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13);
static inline NI32 len_3_In63jw61_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_31);
static inline WireField_0_run8hsnpi* getQ_7_Iko57h9_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_32, NI32 i_30);
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
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_36);
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
static inline seq_0_In6doa_arecyyj7v newSeqUninit_0_Ieodq4s1_arecyyj7v(NI32 size_28);
static inline seq_0_Iw8xl5b1_arecyyj7v newSeqUninit_0_I1tbjnk1_arecyyj7v(NI32 size_24);
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37);
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33);
static inline void add_0_I34il1q_der823rwr1(seq_0_In6doa_arecyyj7v* s_12, NU32 elem_2);
extern X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* newCell_0_valzr1t4f(Value_0_valzr1t4f* v_0);
static inline void add_0_Ijpw0mu_flaksyopx1(seq_0_Iw8xl5b1_arecyyj7v* s_32, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* elem_8);
extern Value_0_valzr1t4f vStr_0_valzr1t4f(string_0_sysvq0asl s_0);
static inline NI32 len_3_Izoe8zv_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_31);
static inline openArray_0_Is74e021_explnj22x1 toOpenArray_1_Itrkyf61_explnj22x1(seq_0_Incv1wn_arecyyj7v s_27);
static inline NI32 len_6_Itc4yka_explnj22x1(openArray_0_Is74e021_explnj22x1 a_42);
static inline NU8* getQ_10_Ikgj4ax_explnj22x1(openArray_0_Is74e021_explnj22x1 x_33, NI32 idx_5);
extern Value_0_valzr1t4f reinterpToInt_0_flaksyopx1(NU64 raw_0, NI32 tbits_0, NB8 tsigned_0);
extern Value_0_valzr1t4f vUInt_0_valzr1t4f(NU64 x_4, NI32 bits_2);
extern Value_0_valzr1t4f vFloat_0_valzr1t4f(NF64 f_0, NI32 bits_4);
extern Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0);
extern Value_0_valzr1t4f vChar_0_valzr1t4f(NC8 c_0);
extern LongString_0_sysvq0asl const strlit_0_I8845991054942562031_intzsnzax;
extern X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 fieldVerdict_0_der823rwr1(NU32 calleeSym_0, NI32 paramIdx_0, NU32 fieldSym_0);
extern NB8 fieldNeverTouched_0_der823rwr1(NU32 calleeSym_1, NI32 paramIdx_1, NU32 fieldSym_1);
static inline seq_0_Ift2sne_aow7lb5cq1* getQ_7_Iurb46i_aow7lb5cq1(seq_0_Ik7wkpe_aow7lb5cq1 s_51, NI32 i_37);
extern LongString_0_sysvq0asl const strlit_0_I17300657558726488198_intzsnzax;
extern string_0_sysvq0asl giveUpName_0_der823rwr1(AnGiveUp_0_der823rwr1 g_0);
extern LongString_0_sysvq0asl const strlit_0_I12933864966599503538_der823rwr1;
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
static inline Value_0_valzr1t4f vPtrLoc_0_valzr1t4f(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1);
extern Value_0_valzr1t4f vPtrReg_0_valzr1t4f(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* reg_1, NI32 fo_1, NI16 eb_1, TCode_0_valzr1t4f ec_1);
extern Value_0_valzr1t4f vEnum_0_valzr1t4f(NI32 ord_0, NU32 ekind_0);
static inline NI32 base_0_valzr1t4f(Value_0_valzr1t4f* v_6);
static inline X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0_valzr1t4f(Value_0_valzr1t4f* v_7);
static inline NI32 foff_0_valzr1t4f(Value_0_valzr1t4f* v_8);
static inline seq_0_I50urnw_croph25r5 newSeqUninit_0_I8oufjc_croph25r5(NI32 size_14);
extern void eQdestroy_1_Inxd7ue1_croph25r5(seq_0_I50urnw_croph25r5 s_35);
static inline void add_0_Itre92n_intzsnzax(seq_0_I50urnw_croph25r5* s_137, Value_0_valzr1t4f elem_30);
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_140, NI32 i_94);
extern X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flObjRegion_0_flaksyopx1(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_2);
extern void setByteAt_0_flaksyopx1(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_4, NI32 off_2, NU8 b_1);
extern X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v unmaterializePtr_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_11, NU32 a_1, Value_0_valzr1t4f* old_0);
static inline void nimInvalidObjConv(string_0_sysvq0asl name_0);
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_139);
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
extern seq_0_Ift2sne_aow7lb5cq1 eQdup_1_Iplow11_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 a_42);
extern void bump_0_croph25r5(NI32 c_0, NI32 by_0);
extern NI32 cAnHonoured_0_der823rwr1;
extern NI32 cAnRevoked_0_der823rwr1;
extern NB8 arenaMatFailed_0_arecyyj7v;
extern NI32 countOf_0_croph25r5(NI32 c_1);
extern string_0_sysvq0asl arenaReport_0_arecyyj7v(void);
extern LongString_0_sysvq0asl const strlit_0_I13319807167292544980_aow7lb5cq1;
extern void syncBack_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_17, Value_0_valzr1t4f* v_10, void* root_0);
extern void syncBlocks_0_arecyyj7v(ArenaMat_0_arecyyj7v* m_18);
static inline openArray_0_In0ukmu_aow7lb5cq1 toOpenArray_1_Ijdwnsz_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_60);
static inline NI32 len_6_Iu1dtri1_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 a_31);
static inline X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** getQ_10_I6a58n11_aow7lb5cq1(openArray_0_In0ukmu_aow7lb5cq1 x_15, NI32 idx_9);
extern X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* newXProvider_0_croph25r5(string_0_sysvq0asl name_2, X60Qt_0_IArefSX4futX53inkX4fbj0natd5co251ZSstring0sysvq0aslSseq0X4950urnwSX56alue0valzr1t4fAnimcallZAfalseZAR91_croph25r5 run_0, X60Qt_0_ISstring0sysvq0aslSX43rossX52oute0croph25r5AnimcallZAfalseZAR51_croph25r5 route_2, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_0, string_0_sysvq0asl artifact_0);
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
extern void eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f(ObjBox_Obj_0_valzr1t4f dest_0);
extern void eQdestroy_1_Iscb4i31_arecyyj7v(seq_0_In6doa_arecyyj7v s_81);
extern void eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f(SeqBox_Obj_0_valzr1t4f dest_0);
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82);
extern void eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f(ArrBox_Obj_0_valzr1t4f dest_0);
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
extern NI32 newRouteCounter_0_croph25r5(string_0_sysvq0asl name_0);
extern LongString_0_sysvq0asl const strlit_0_I819492781050547440_croph25r5;
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
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
static inline NI32 memSizeInBytes_0_Itmy7ww1_croph25r5(NI32 size_15);
static inline NI32 capInBytes_0_Ihvsegh1_croph25r5(seq_0_I50urnw_croph25r5 s_44);
extern NB8 resize_0_Iz8tg361_intzsnzax(seq_0_I50urnw_croph25r5* dest_22, NI32 addedElements_22);
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
LongString_0_sysvq0asl const strlit_0_I40788521789328021_run8hsnpi = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hybrid.nativeCalls"}
;
LongString_0_sysvq0asl const strlit_0_I17821885512794003803_run8hsnpi = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hybrid.arenaDeclines"}
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
LongString_0_sysvq0asl const strlit_0_I95191463816654317_run8hsnpi = {
  .fullLen_0 = 60, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "seq of ref/closure/unsafe element \342\200\224 ownership cannot cross"}
;
LongString_0_sysvq0asl const strlit_0_I2511330594188339324_run8hsnpi = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " [elem "}
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
NI32 cHybridCalls_0_run8hsnpi;
NI32 cArenaDeclines_0_run8hsnpi;
NB8 hybridArenaTrace_0_run8hsnpi;
static string_0_sysvq0asl const hexd_0 = {
  .bytes_0 = 842084606u, .more_0 = (&strlit_0_I6105018409752412263_dbg4n0xd21)}
;
NB8 X60QiniGuard_0_run8hsnpi;
string_0_sysvq0asl nodeTag_0_run8hsnpi(Cursor_0_nifb6mq6y1 n_0){
  string_0_sysvq0asl result_3;
  nimStrWasMoved((&result_3));
  nimStrDestroy(result_3);
  NU32 X60Qx_124 = tagId_0_nifb6mq6y1(n_0);
  string_0_sysvq0asl* X60Qx_125 = getQ_0_I93d71y_der823rwr1(pool_0_nifh7u8pu1.tags_0, X60Qx_124);
  string_0_sysvq0asl X60Qx_126 = nimStrDup((*X60Qx_125));
  result_3 = X60Qx_126;
  return result_3;}
NB8 pragmasHaveInheritable_0_run8hsnpi(Cursor_0_nifb6mq6y1 pragmasCur_0){
  NB8 result_4;
  Cursor_0_nifb6mq6y1 c_0 = eQdup_0_nifb6mq6y1(pragmasCur_0);
  NifKind_0_nif81dubp1 X60Qx_127 = kind_0_nifb6mq6y1(c_0);
  if ((!(X60Qx_127 == 11))){
    eQdestroy_0_nifb6mq6y1((&c_0));
    return NIM_FALSE;}
  inc_0_nifb6mq6y1((&c_0));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_128 = kind_0_nifb6mq6y1(c_0);
      if ((!(X60Qx_128 == 12))){
        NB8 X60Qx_129;
        NifKind_0_nif81dubp1 X60Qx_130 = kind_0_nifb6mq6y1(c_0);
        if (X60Qx_130 == 11){
          NU32 X60Qx_131 = tag_0_nifb6mq6y1(c_0);
          X60Qx_129 = (((TagEnum_0_tagygirdh1)X60Qx_131) == 313);}
        else {
          X60Qx_129 = NIM_FALSE;}
        if (X60Qx_129){
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
  NifKind_0_nif81dubp1 X60Qx_132 = kind_0_nifb6mq6y1(c_1);
  if (X60Qx_132 == 4){
    NU32 sym_12 = symId_0_nifb6mq6y1(c_1);
    if (((NU32)sym_12) == ((NU32)0u)){
      eQdestroy_0_nifb6mq6y1((&c_1));
      return NIM_NIL;}
    string_0_sysvq0asl* X60Qx_133 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_12);
    string_0_sysvq0asl bn_0 = nimStrDup((*X60Qx_133));
    extractBasename_1_symkyk35i1((&bn_0));
    NB8 X60Qx_134 = eqQ_20_sysvq0asl(bn_0, (string_0_sysvq0asl){
      .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
    );
    if (X60Qx_134){
      void* X60Qx_135 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_135);
      seq_0_I3ump14_aow7lb5cq1 X60Qx_136 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
      seq_0_Ie088gc_heapjafyf1 X60Qx_137 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
      (*X60Qtmp_0) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
        .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
          .kind_0 = 14, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_136, .branches_0 = X60Qx_137}}
      ;
      result_5 = X60Qtmp_0;
      nimStrDestroy(bn_0);
      eQdestroy_0_nifb6mq6y1((&c_1));
      return result_5;}
    LoadResult_0_prorcx25w1 res_6 = tryLoadSymSafe_0_modzy18mg1(sym_12);
    NB8 X60Qx_85;
    NB8 X60Qx_138;
    if ((!(res_6.status_0 == 3))){
      X60Qx_138 = NIM_TRUE;}
    else {
      NifKind_0_nif81dubp1 X60Qx_139 = kind_0_nifb6mq6y1(res_6.decl_0);
      X60Qx_138 = (!(X60Qx_139 == 11));}
    if (X60Qx_138){
      X60Qx_85 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_1 = nodeTag_0_run8hsnpi(res_6.decl_0);
      NB8 X60Qx_140 = eqQ_20_sysvq0asl(X60Qtmp_1, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
      );
      X60Qx_85 = (!X60Qx_140);
      nimStrDestroy(X60Qtmp_1);}
    if (X60Qx_85){
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
      nimStrDestroy(bn_0);
      eQdestroy_0_nifb6mq6y1((&c_1));
      return NIM_NIL;}
    TypeDecl_0_decqocs071 td_11 = asTypeDecl_0_decqocs071(res_6.decl_0);
    NB8 X60Qx_141 = eqQ_20_sysvq0asl(bn_0, (string_0_sysvq0asl){
      .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
    );
    if (X60Qx_141){
      Cursor_0_nifb6mq6y1 b_0 = td_11.typevars_0;
      eQwasMoved_0_nifb6mq6y1((&td_11.typevars_0));
      NB8 X60Qx_86;
      NifKind_0_nif81dubp1 X60Qx_142 = kind_0_nifb6mq6y1(b_0);
      if (X60Qx_142 == 11){
        string_0_sysvq0asl X60Qtmp_2 = nodeTag_0_run8hsnpi(b_0);
        NB8 X60Qx_143 = eqQ_20_sysvq0asl(X60Qtmp_2, (string_0_sysvq0asl){
          .bytes_0 = 7627010u, .more_0 = NIM_NIL}
        );
        X60Qx_86 = X60Qx_143;
        nimStrDestroy(X60Qtmp_2);}
      else {
        X60Qx_86 = NIM_FALSE;}
      if (X60Qx_86){
        inc_0_nifb6mq6y1((&b_0));
        skip_0_nifb6mq6y1((&b_0));
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_2 = typeDescOf_0_run8hsnpi(b_0, ((NI32)(depth_0 + 1)));
        if (elem_2 == NIM_NIL){
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_2);
          eQdestroy_0_nifb6mq6y1((&b_0));
          eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
          nimStrDestroy(bn_0);
          eQdestroy_0_nifb6mq6y1((&c_1));
          return NIM_NIL;}
        void* X60Qx_144 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_3 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_144);
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_4 = elem_2;
        eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&elem_2));
        seq_0_I3ump14_aow7lb5cq1 X60Qx_87 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
        seq_0_Ie088gc_heapjafyf1 X60Qx_88 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
        (*X60Qtmp_3) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
          .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
            .kind_0 = 15, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_4, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_87, .branches_0 = X60Qx_88}}
        ;
        result_5 = X60Qtmp_3;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_2);
        eQdestroy_0_nifb6mq6y1((&b_0));
        eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
        nimStrDestroy(bn_0);
        eQdestroy_0_nifb6mq6y1((&c_1));
        return result_5;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_2);}
      eQdestroy_0_nifb6mq6y1((&b_0));
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
      nimStrDestroy(bn_0);
      eQdestroy_0_nifb6mq6y1((&c_1));
      return NIM_NIL;
      eQdestroy_0_nifb6mq6y1((&b_0));}
    NB8 X60Qx_89;
    NB8 X60Qx_90;
    NifKind_0_nif81dubp1 X60Qx_145 = kind_0_nifb6mq6y1(td_11.body_0);
    if (X60Qx_145 == 11){
      string_0_sysvq0asl X60Qtmp_5 = nodeTag_0_run8hsnpi(td_11.body_0);
      NB8 X60Qx_146 = eqQ_20_sysvq0asl(X60Qtmp_5, (string_0_sysvq0asl){
        .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
      );
      X60Qx_90 = X60Qx_146;
      nimStrDestroy(X60Qtmp_5);}
    else {
      X60Qx_90 = NIM_FALSE;}
    if (X60Qx_90){
      NB8 X60Qx_147 = pragmasHaveInheritable_0_run8hsnpi(td_11.pragmas_0);
      X60Qx_89 = X60Qx_147;}
    else {
      X60Qx_89 = NIM_FALSE;}
    if (X60Qx_89){
      void* X60Qx_148 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_6 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_148);
      seq_0_I3ump14_aow7lb5cq1 X60Qx_149 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
      seq_0_Ie088gc_heapjafyf1 X60Qx_150 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
      (*X60Qtmp_6) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
        .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
          .kind_0 = 12, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_149, .branches_0 = X60Qx_150}}
      ;
      result_5 = X60Qtmp_6;
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
      nimStrDestroy(bn_0);
      eQdestroy_0_nifb6mq6y1((&c_1));
      return result_5;}
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_151 = typeDescOf_0_run8hsnpi(td_11.body_0, ((NI32)(depth_0 + 1)));
    result_5 = X60Qx_151;
    eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
    nimStrDestroy(bn_0);
    eQdestroy_0_nifb6mq6y1((&c_1));
    return result_5;
    eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_11));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
    nimStrDestroy(bn_0);}
  NifKind_0_nif81dubp1 X60Qx_152 = kind_0_nifb6mq6y1(c_1);
  if ((!(X60Qx_152 == 11))){
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
  NifKind_0_nif81dubp1 X60Qx_153 = kind_0_nifb6mq6y1(w_0);
  if (X60Qx_153 == 8){
    NU32 X60Qx_154 = intId_0_nifb6mq6y1(w_0);
    NI64* X60Qx_155 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_154);
    X60Qx_0 = ((NI32)(*X60Qx_155));}
  else {
    X60Qx_0 = 0;}
  NI32 bits_0 = X60Qx_0;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_156 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_8 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_156);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_157 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_158 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_8) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 0, .bits_0 = bits_0, .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_157, .branches_0 = X60Qx_158}}
  ;
  result_5 = X60Qtmp_8;
  eQdestroy_0_nifb6mq6y1((&w_0));
  goto X60Qsc_31;
  X60Qsc_1: ;
  Cursor_0_nifb6mq6y1 w_1 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&w_1));
  NI32 X60Qx_1;
  NifKind_0_nif81dubp1 X60Qx_159 = kind_0_nifb6mq6y1(w_1);
  if (X60Qx_159 == 8){
    NU32 X60Qx_160 = intId_0_nifb6mq6y1(w_1);
    NI64* X60Qx_161 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_160);
    X60Qx_1 = ((NI32)(*X60Qx_161));}
  else {
    X60Qx_1 = 0;}
  NI32 bits_1 = X60Qx_1;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_162 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_9 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_162);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_163 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_164 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_9) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 1, .bits_0 = bits_1, .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_163, .branches_0 = X60Qx_164}}
  ;
  result_5 = X60Qtmp_9;
  eQdestroy_0_nifb6mq6y1((&w_1));
  goto X60Qsc_31;
  X60Qsc_2: ;
  Cursor_0_nifb6mq6y1 w_2 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&w_2));
  NI32 X60Qx_2;
  NifKind_0_nif81dubp1 X60Qx_165 = kind_0_nifb6mq6y1(w_2);
  if (X60Qx_165 == 8){
    NU32 X60Qx_166 = intId_0_nifb6mq6y1(w_2);
    NI64* X60Qx_167 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_166);
    X60Qx_2 = ((NI32)(*X60Qx_167));}
  else {
    X60Qx_2 = 64;}
  NI32 bits_2 = X60Qx_2;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_168 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_10 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_168);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_169 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_170 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_10) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 2, .bits_0 = bits_2, .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_169, .branches_0 = X60Qx_170}}
  ;
  result_5 = X60Qtmp_10;
  eQdestroy_0_nifb6mq6y1((&w_2));
  goto X60Qsc_31;
  X60Qsc_3: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_171 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_11 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_171);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_172 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_173 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_11) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 3, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_172, .branches_0 = X60Qx_173}}
  ;
  result_5 = X60Qtmp_11;
  goto X60Qsc_31;
  X60Qsc_4: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_174 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_12 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_174);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_175 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_176 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_12) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 4, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_175, .branches_0 = X60Qx_176}}
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
  NB8 X60Qx_91;
  NifKind_0_nif81dubp1 X60Qx_177 = kind_0_nifb6mq6y1(e_5);
  if (X60Qx_177 == 11){
    NB8 X60Qx_92;
    string_0_sysvq0asl X60Qtmp_13 = nodeTag_0_run8hsnpi(e_5);
    NB8 X60Qx_178 = eqQ_20_sysvq0asl(X60Qtmp_13, (string_0_sysvq0asl){
      .bytes_0 = 29953u, .more_0 = NIM_NIL}
    );
    if (X60Qx_178){
      X60Qx_92 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_14 = nodeTag_0_run8hsnpi(e_5);
      NB8 X60Qx_179 = eqQ_20_sysvq0asl(X60Qtmp_14, (string_0_sysvq0asl){
        .bytes_0 = 26881u, .more_0 = NIM_NIL}
      );
      X60Qx_92 = X60Qx_179;
      nimStrDestroy(X60Qtmp_14);}
    X60Qx_91 = X60Qx_92;
    nimStrDestroy(X60Qtmp_13);}
  else {
    X60Qx_91 = NIM_FALSE;}
  if (X60Qx_91){
    Cursor_0_nifb6mq6y1 w_3 = eQdup_0_nifb6mq6y1(e_5);
    inc_0_nifb6mq6y1((&w_3));
    NifKind_0_nif81dubp1 X60Qx_180 = kind_0_nifb6mq6y1(w_3);
    if (X60Qx_180 == 8){
      NU32 X60Qx_181 = intId_0_nifb6mq6y1(w_3);
      NI64* X60Qx_182 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_181);
      ebits_0 = ((NI32)(*X60Qx_182));}
    eQdestroy_0_nifb6mq6y1((&w_3));}
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_183 = kind_0_nifb6mq6y1(e_5);
      if ((!(X60Qx_183 == 12))){
        NB8 X60Qx_93;
        NifKind_0_nif81dubp1 X60Qx_184 = kind_0_nifb6mq6y1(e_5);
        if (X60Qx_184 == 11){
          string_0_sysvq0asl X60Qtmp_15 = nodeTag_0_run8hsnpi(e_5);
          NB8 X60Qx_185 = eqQ_20_sysvq0asl(X60Qtmp_15, (string_0_sysvq0asl){
            .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_emi78vuj01)}
          );
          X60Qx_93 = X60Qx_185;
          nimStrDestroy(X60Qtmp_15);}
        else {
          X60Qx_93 = NIM_FALSE;}
        if (X60Qx_93){
          Cursor_0_nifb6mq6y1 f_5 = eQdup_0_nifb6mq6y1(e_5);
          inc_0_nifb6mq6y1((&f_5));
          skip_0_nifb6mq6y1((&f_5));
          skip_0_nifb6mq6y1((&f_5));
          skip_0_nifb6mq6y1((&f_5));
          skip_0_nifb6mq6y1((&f_5));
          NifKind_0_nif81dubp1 X60Qx_186 = kind_0_nifb6mq6y1(f_5);
          if (X60Qx_186 == 11){
            Cursor_0_nifb6mq6y1 t_7 = f_5;
            eQwasMoved_0_nifb6mq6y1((&f_5));
            inc_0_nifb6mq6y1((&t_7));
            NifKind_0_nif81dubp1 X60Qx_187 = kind_0_nifb6mq6y1(t_7);
            if (X60Qx_187 == 8){
              NU32 X60Qx_188 = intId_0_nifb6mq6y1(t_7);
              NI64* X60Qx_189 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_188);
              NI32 o_0 = ((NI32)(*X60Qx_189));
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
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_190 = enumDesc_0_layptix6a1(lo_0, hi_0, ebits_0);
  result_5 = X60Qx_190;
  eQdestroy_0_nifb6mq6y1((&e_5));
  goto X60Qsc_31;
  X60Qsc_6: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_191 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_16 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_191);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_192 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_193 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_16) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 5, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_192, .branches_0 = X60Qx_193}}
  ;
  result_5 = X60Qtmp_16;
  goto X60Qsc_31;
  X60Qsc_7: ;
  Cursor_0_nifb6mq6y1 e_6 = c_1;
  eQwasMoved_0_nifb6mq6y1((&c_1));
  inc_0_nifb6mq6y1((&e_6));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_1 = typeDescOf_0_run8hsnpi(e_6, ((NI32)(depth_0 + 1)));
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_194 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_17 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_194);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_18 = el_1;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&el_1));
  seq_0_I3ump14_aow7lb5cq1 X60Qx_94 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_95 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_17) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 6, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_18, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_94, .branches_0 = X60Qx_95}}
  ;
  result_5 = X60Qtmp_17;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_1);
  eQdestroy_0_nifb6mq6y1((&e_6));
  goto X60Qsc_31;
  X60Qsc_8: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_195 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_19 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_195);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_196 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_197 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_19) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 7, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_196, .branches_0 = X60Qx_197}}
  ;
  result_5 = X60Qtmp_19;
  goto X60Qsc_31;
  X60Qsc_9: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  void* X60Qx_198 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_20 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_198);
  seq_0_I3ump14_aow7lb5cq1 X60Qx_199 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_200 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_20) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 14, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_199, .branches_0 = X60Qx_200}}
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
  void* X60Qx_201 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_21 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_201);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_22 = elem_3;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&elem_3));
  seq_0_I3ump14_aow7lb5cq1 X60Qx_96 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_97 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_21) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 15, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_22, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_96, .branches_0 = X60Qx_97}}
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
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_202 = typeDescOf_0_run8hsnpi(e_8, ((NI32)(depth_0 + 1)));
  result_5 = X60Qx_202;
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
  void* X60Qx_203 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_23 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_203);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_24 = inner_0;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&inner_0));
  seq_0_I3ump14_aow7lb5cq1 X60Qx_98 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_99 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_23) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 13, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_24, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_98, .branches_0 = X60Qx_99}}
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
  NB8 X60Qx_100;
  NifKind_0_nif81dubp1 X60Qx_204 = kind_0_nifb6mq6y1(idx_0);
  if (X60Qx_204 == 11){
    string_0_sysvq0asl X60Qtmp_25 = nodeTag_0_run8hsnpi(idx_0);
    NB8 X60Qx_205 = eqQ_20_sysvq0asl(X60Qtmp_25, (string_0_sysvq0asl){
      .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16393544569146403439_intzsnzax)}
    );
    X60Qx_100 = X60Qx_205;
    nimStrDestroy(X60Qtmp_25);}
  else {
    X60Qx_100 = NIM_FALSE;}
  if (X60Qx_100){
    Cursor_0_nifb6mq6y1 r_0 = idx_0;
    eQwasMoved_0_nifb6mq6y1((&idx_0));
    inc_0_nifb6mq6y1((&r_0));
    skip_0_nifb6mq6y1((&r_0));
    NifKind_0_nif81dubp1 X60Qx_206 = kind_0_nifb6mq6y1(r_0);
    if (X60Qx_206 == 8){
      NU32 X60Qx_207 = intId_0_nifb6mq6y1(r_0);
      NI64* X60Qx_208 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_207);
      lo_1 = ((NI32)(*X60Qx_208));}
    skip_0_nifb6mq6y1((&r_0));
    NifKind_0_nif81dubp1 X60Qx_209 = kind_0_nifb6mq6y1(r_0);
    if (X60Qx_209 == 8){
      NU32 X60Qx_210 = intId_0_nifb6mq6y1(r_0);
      NI64* X60Qx_211 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_210);
      hi_1 = ((NI32)(*X60Qx_211));}
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
  void* X60Qx_212 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_26 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_212);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_27 = elem_4;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&elem_4));
  seq_0_I3ump14_aow7lb5cq1 X60Qx_101 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  seq_0_Ie088gc_heapjafyf1 X60Qx_102 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_26) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 9, .bits_0 = ((NI32)0), .count_0 = count_0, .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = X60Qtmp_27, .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_101, .branches_0 = X60Qx_102}}
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
      NifKind_0_nif81dubp1 X60Qx_213 = kind_0_nifb6mq6y1(f_6);
      if ((!(X60Qx_213 == 12))){
        NifKind_0_nif81dubp1 X60Qx_214 = kind_0_nifb6mq6y1(f_6);
        if (X60Qx_214 == 11){
          Cursor_0_nifb6mq6y1 fc_0 = eQdup_0_nifb6mq6y1(f_6);
          string_0_sysvq0asl X60Qtmp_28 = nodeTag_0_run8hsnpi(f_6);
          NB8 X60Qx_215 = eqQ_20_sysvq0asl(X60Qtmp_28, (string_0_sysvq0asl){
            .bytes_0 = 7760642u, .more_0 = NIM_NIL}
          );
          if (X60Qx_215){
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
  void* X60Qx_216 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_30 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_216);
  seq_0_I3ump14_aow7lb5cq1 X60Qtmp_31 = fields_0;
  eQwasMoved_1_Iba95rl_aow7lb5cq1((&fields_0));
  seq_0_Ie088gc_heapjafyf1 X60Qx_103 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_30) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 11, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qtmp_31, .branches_0 = X60Qx_103}}
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
  NifKind_0_nif81dubp1 X60Qx_217 = kind_0_nifb6mq6y1(oc_0);
  if (X60Qx_217 == 4){
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(base_7);
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_218 = typeDescOf_0_run8hsnpi(oc_0, ((NI32)(depth_0 + 1)));
    base_7 = X60Qx_218;
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
      NifKind_0_nif81dubp1 X60Qx_219 = kind_0_nifb6mq6y1(oc_0);
      if ((!(X60Qx_219 == 12))){
        NifKind_0_nif81dubp1 X60Qx_220 = kind_0_nifb6mq6y1(oc_0);
        if (X60Qx_220 == 11){
          string_0_sysvq0asl tg_0 = nodeTag_0_run8hsnpi(oc_0);
          NB8 X60Qx_221 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
            .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
          );
          if (X60Qx_221){
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
            NB8 X60Qx_222 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
              .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_emi78vuj01)}
            );
            if (X60Qx_222){
              void* X60Qx_223 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
              X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_33 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_223);
              seq_0_I3ump14_aow7lb5cq1 X60Qx_224 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
              seq_0_Ie088gc_heapjafyf1 X60Qx_225 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
              (*X60Qtmp_33) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
                .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
                  .kind_0 = 12, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qx_224, .branches_0 = X60Qx_225}}
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
  void* X60Qx_226 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1));
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_34 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)X60Qx_226);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_35 = base_7;
  eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&base_7));
  seq_0_I3ump14_aow7lb5cq1 X60Qtmp_36 = fields_1;
  eQwasMoved_1_Iba95rl_aow7lb5cq1((&fields_1));
  seq_0_Ie088gc_heapjafyf1 X60Qx_104 = newSeqUninit_0_Inwn9fa_heapjafyf1(0);
  (*X60Qtmp_34) = (X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1){
    .r_00 = 0, .d_00 = (TypeDesc_Obj_0_layptix6a1){
      .kind_0 = 10, .bits_0 = ((NI32)0), .count_0 = ((NI32)0), .enumLo_0 = ((NI32)0), .enumHi_0 = ((NI32)0), .elem_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .base_0 = X60Qtmp_35, .rtti_0 = NIM_FALSE, .packed_0 = NIM_FALSE, .union_0 = NIM_FALSE, .incomplete_0 = NIM_FALSE, .fields_0 = X60Qtmp_36, .branches_0 = X60Qx_104}}
  ;
  result_5 = X60Qtmp_34;
  eQdestroy_0_nifb6mq6y1((&oc_0));
  eQdestroy_1_Iqg9snl1_aow7lb5cq1(fields_1);
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(base_7);
  goto X60Qsc_31;
  X60Qsc_32: ;
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(result_5);
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_227 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL));
  result_5 = X60Qx_227;
  X60Qsc_31: ;
  nimStrDestroy(X60Qtmp_7);
  eQdestroy_0_nifb6mq6y1((&c_1));
  return result_5;
  nimStrDestroy(X60Qtmp_7);
  eQdestroy_0_nifb6mq6y1((&c_1));
  return result_5;}
static inline NB8 marshalSafe_0_run8hsnpi(MarshalClass_0_marbdjk4t1 cls_0){
  NB8 result_6;
  NB8 X60Qx_228;
  NB8 X60Qx_229;
  NB8 X60Qx_230;
  if (cls_0 == 0){
    X60Qx_230 = NIM_TRUE;}
  else {
    X60Qx_230 = (cls_0 == 1);}
  if (X60Qx_230){
    X60Qx_229 = NIM_TRUE;}
  else {
    X60Qx_229 = (cls_0 == 2);}
  if (X60Qx_229){
    X60Qx_228 = NIM_TRUE;}
  else {
    X60Qx_228 = (cls_0 == 3);}
  result_6 = X60Qx_228;
  return result_6;}
NB8 hybridDecision_0_run8hsnpi(seq_0_I3ump14_aow7lb5cq1 params_0, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* ret_0){
  NB8 result_7;
  {
    openArray_0_I3ca6t4_layptix6a1 X60Qlf_0 = toOpenArray_1_I0zz6qv1_layptix6a1(params_0);
    NI32 X60Qlf_1 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_231 = len_6_I0tpktl1_layptix6a1(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_231){
          {
            {
              X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_3 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_0, X60Qlf_1);
              if ((*X60Qii_3) == NIM_NIL){
                return NIM_FALSE;}
              MarshalClass_0_marbdjk4t1 X60Qx_232 = marshalClass_0_marbdjk4t1((*X60Qii_3));
              NB8 X60Qx_233 = marshalSafe_0_run8hsnpi(X60Qx_232);
              if (X60Qx_233){
                goto continueLabel_2;}
              NB8 X60Qx_234;
              NB8 X60Qx_235;
              if ((*(*X60Qii_3)).d_00.kind_0 == 6){
                X60Qx_235 = (!((*(*X60Qii_3)).d_00.elem_0 == NIM_NIL));}
              else {
                X60Qx_235 = NIM_FALSE;}
              if (X60Qx_235){
                NB8 X60Qx_236;
                if ((*(*(*X60Qii_3)).d_00.elem_0).d_00.kind_0 == 10){
                  X60Qx_236 = NIM_TRUE;}
                else {
                  X60Qx_236 = ((*(*(*X60Qii_3)).d_00.elem_0).d_00.kind_0 == 11);}
                X60Qx_234 = X60Qx_236;}
              else {
                X60Qx_234 = NIM_FALSE;}
              if (X60Qx_234){
                goto continueLabel_2;}
              NB8 X60Qx_237 = isArenaPtrAggregate_0_marbdjk4t1((*X60Qii_3));
              if (X60Qx_237){
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
  NB8 X60Qx_238;
  if ((!(ret_0 == NIM_NIL))){
    MarshalClass_0_marbdjk4t1 X60Qx_239 = marshalClass_0_marbdjk4t1(ret_0);
    NB8 X60Qx_240 = marshalSafe_0_run8hsnpi(X60Qx_239);
    X60Qx_238 = (!X60Qx_240);}
  else {
    X60Qx_238 = NIM_FALSE;}
  if (X60Qx_238){
    return NIM_FALSE;}
  result_7 = NIM_TRUE;
  return result_7;}
NB8 hybridSigEligible_0_run8hsnpi(Cursor_0_nifb6mq6y1 procCur_0){
  NB8 result_8;
  Routine_0_decqocs071 r_1 = asRoutine_0_decqocs071(procCur_0, 0);
  seq_0_I3ump14_aow7lb5cq1 descs_0 = newSeqUninit_0_I978ktq1_aow7lb5cq1(0);
  Cursor_0_nifb6mq6y1 pc_0 = r_1.params_0;
  eQwasMoved_0_nifb6mq6y1((&r_1.params_0));
  NB8 X60Qx_105;
  NifKind_0_nif81dubp1 X60Qx_241 = kind_0_nifb6mq6y1(pc_0);
  if (X60Qx_241 == 11){
    string_0_sysvq0asl X60Qtmp_37 = nodeTag_0_run8hsnpi(pc_0);
    NB8 X60Qx_242 = eqQ_20_sysvq0asl(X60Qtmp_37, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_der823rwr1)}
    );
    X60Qx_105 = X60Qx_242;
    nimStrDestroy(X60Qtmp_37);}
  else {
    X60Qx_105 = NIM_FALSE;}
  if (X60Qx_105){
    inc_0_nifb6mq6y1((&pc_0));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_243 = kind_0_nifb6mq6y1(pc_0);
        if ((!(X60Qx_243 == 12))){
          NifKind_0_nif81dubp1 X60Qx_244 = kind_0_nifb6mq6y1(pc_0);
          if (X60Qx_244 == 11){
            Local_0_decqocs071 loc_0 = takeLocal_0_decqocs071((&pc_0), 2);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_245 = typeDescOf_0_run8hsnpi(loc_0.typ_0, 0);
            add_0_Ijteip9_run8hsnpi((&descs_0), X60Qx_245);
            eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_0));}
          else {
            skip_0_nifb6mq6y1((&pc_0));}}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* ret_1 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL));
  NB8 X60Qx_246;
  NifKind_0_nif81dubp1 X60Qx_247 = kind_0_nifb6mq6y1(r_1.retType_0);
  if (X60Qx_247 == 11){
    X60Qx_246 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_248 = kind_0_nifb6mq6y1(r_1.retType_0);
    X60Qx_246 = (X60Qx_248 == 4);}
  if (X60Qx_246){
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(ret_1);
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_249 = typeDescOf_0_run8hsnpi(r_1.retType_0, 0);
    ret_1 = X60Qx_249;}
  NB8 X60Qx_250 = hybridDecision_0_run8hsnpi(descs_0, ret_1);
  result_8 = X60Qx_250;
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
  void* X60Qx_251 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax));
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* X60Qtmp_38 = ((X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*)X60Qx_251);
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
  void* X60Qx_252 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax));
  X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* X60Qtmp_39 = ((X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax*)X60Qx_252);
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* X60Qx_253 = newCabiProviderStub_0_run8hsnpi();
  seq_0_Ixkko8n_run8hsnpi X60Qx_254 = newSeqUninit_0_Iyquyq_run8hsnpi(0);
  (*X60Qtmp_39) = (X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax){
    .r_00 = 0, .d_00 = (HybridRegistry_Obj_0_run8hsnpi){
      .provider_0 = X60Qx_253, .extra_0 = X60Qx_254}}
  ;
  result_11 = X60Qtmp_39;
  return result_11;}
NB8 providerMayOwn_0_run8hsnpi(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* p_7, NU32 sym_4){
  NB8 result_15;
  NB8 X60Qx_271;
  if (p_7 == NIM_NIL){
    X60Qx_271 = NIM_TRUE;}
  else {
    X60Qx_271 = (((void*)(*p_7).d_00.invoke_0) == NIM_NIL);}
  if (X60Qx_271){
    return NIM_FALSE;}
  if (((void*)(*p_7).d_00.ownsImpl_0) == NIM_NIL){
    return NIM_TRUE;}
  NB8 X60Qx_272 = (*p_7).d_00.ownsImpl_0(p_7, sym_4);
  result_15 = X60Qx_272;
  return result_15;}
CrossOutcome_0_croph25r5 hybridTryDispatch_0_run8hsnpi(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* reg_0, NU32 sym_5, string_0_sysvq0asl base_4, seq_0_I50urnw_croph25r5 args_4, Value_0_valzr1t4f* res_4){
  CrossOutcome_0_croph25r5 result_16;
  eQwasmovedQ_SX43rossX4futcome0croph25r5_0_croph25r5((&result_16));
  NB8 X60Qx_273;
  NB8 X60Qx_274;
  if (reg_0 == NIM_NIL){
    X60Qx_274 = NIM_TRUE;}
  else {
    X60Qx_274 = ((*reg_0).d_00.provider_0 == NIM_NIL);}
  if (X60Qx_274){
    X60Qx_273 = NIM_TRUE;}
  else {
    X60Qx_273 = (((void*)(*(*reg_0).d_00.provider_0).d_00.invoke_0) == NIM_NIL);}
  if (X60Qx_273){
    CrossOutcome_0_croph25r5 X60Qx_275 = crossDecline_0_croph25r5(4, (string_0_sysvq0asl){
      .bytes_0 = 544173822u, .more_0 = (&strlit_0_I2753240950845275664_run8hsnpi)}
    );
    result_16 = X60Qx_275;
    return result_16;}
  NB8 asked_0 = NIM_FALSE;
  NB8 X60Qx_276 = providerMayOwn_0_run8hsnpi((*reg_0).d_00.provider_0, sym_5);
  if (X60Qx_276){
    asked_0 = NIM_TRUE;
    NB8 X60Qx_277 = (*(*reg_0).d_00.provider_0).d_00.invoke_0((*reg_0).d_00.provider_0, sym_5, base_4, args_4, res_4);
    if (X60Qx_277){
      CrossOutcome_0_croph25r5 X60Qx_278 = crossOk_0_croph25r5((&(*res_4)), 3, base_4);
      result_16 = X60Qx_278;
      return result_16;}}
  {
    openArray_0_Ihcf6y9_run8hsnpi X60Qlf_2 = toOpenArray_1_Iumnf4i1_run8hsnpi((*reg_0).d_00.extra_0);
    NI32 X60Qlf_3 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_279 = len_6_Ij4lmhs_run8hsnpi(X60Qlf_2);
        if (X60Qlf_3 < X60Qx_279){
          {
            X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** X60Qii_2 = getQ_10_Iwwsp9w1_run8hsnpi(X60Qlf_2, X60Qlf_3);
            NB8 X60Qx_280 = providerMayOwn_0_run8hsnpi((*X60Qii_2), sym_5);
            if (X60Qx_280){
              asked_0 = NIM_TRUE;
              NB8 X60Qx_281 = (*(*X60Qii_2)).d_00.invoke_0((*X60Qii_2), sym_5, base_4, args_4, res_4);
              if (X60Qx_281){
                CrossOutcome_0_croph25r5 X60Qx_282 = crossOk_0_croph25r5((&(*res_4)), 3, base_4);
                result_16 = X60Qx_282;
                return result_16;}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  if ((!asked_0)){
    NB8 X60Qx_283;
    if (routeLog_0_croph25r5){
      X60Qx_283 = NIM_TRUE;}
    else {
      NB8 X60Qx_284 = jitTraceLog_0_run8hsnpi();
      X60Qx_283 = X60Qx_284;}
    if (X60Qx_283){
      NB8 X60Qx_285 = (*(*reg_0).d_00.provider_0).d_00.invoke_0((*reg_0).d_00.provider_0, sym_5, base_4, args_4, res_4);}
    else {
      CrossOutcome_0_croph25r5 X60Qx_286 = crossDecline_0_croph25r5(3, (string_0_sysvq0asl){
        .bytes_0 = 544173822u, .more_0 = (&strlit_0_I13886929192389480583_run8hsnpi)}
      );
      result_16 = X60Qx_286;
      return result_16;}}
  string_0_sysvq0asl why_0 = blockerReason_0_croph25r5();
  NI32 X60Qx_287 = len_4_sysvq0asl(why_0);
  if (X60Qx_287 == 0){
    string_0_sysvq0asl X60Qdesugar_0 = nimStrDup((*(*reg_0).d_00.provider_0).d_00.name_0);
    NI32 X60Qx_288 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I7414938221747216170_run8hsnpi)}
    );
    NI32 X60Qx_289 = len_4_sysvq0asl(X60Qdesugar_0);
    NI32 X60Qx_290 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1679828990u, .more_0 = (&strlit_0_I5892731654726801288_run8hsnpi)}
    );
    NI32 X60Qx_291 = len_4_sysvq0asl(base_4);
    NI32 X60Qx_292 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1998596094u, .more_0 = (&strlit_0_I9873774322074382144_run8hsnpi)}
    );
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_288 + X60Qx_289)) + X60Qx_290)) + X60Qx_291)) + X60Qx_292)));
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
  CrossOutcome_0_croph25r5 X60Qx_293 = crossDecline_0_croph25r5(3, why_0);
  result_16 = X60Qx_293;
  nimStrDestroy(why_0);
  return result_16;
  nimStrDestroy(why_0);
  return result_16;}
NB8 jitTraceLog_0_run8hsnpi(void){
  NB8 result_19;
  string_0_sysvq0asl X60Qtmp_43 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I12470586101363112036_run8hsnpi)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_296 = eqQ_20_sysvq0asl(X60Qtmp_43, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  result_19 = X60Qx_296;
  nimStrDestroy(X60Qtmp_43);
  return result_19;
  nimStrDestroy(X60Qtmp_43);
  return result_19;}
string_0_sysvq0asl baseNameOf_0_run8hsnpi(NU32 sym_6){
  string_0_sysvq0asl result_20;
  nimStrWasMoved((&result_20));
  nimStrDestroy(result_20);
  string_0_sysvq0asl* X60Qx_297 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_6);
  string_0_sysvq0asl X60Qx_298 = nimStrDup((*X60Qx_297));
  result_20 = X60Qx_298;
  extractBasename_1_symkyk35i1((&result_20));
  return result_20;}
string_0_sysvq0asl aowlcSymName_0_run8hsnpi(NU32 sym_7){
  string_0_sysvq0asl result_21;
  nimStrWasMoved((&result_21));
  string_0_sysvq0asl* X60Qx_299 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_7);
  string_0_sysvq0asl s_5 = nimStrDup((*X60Qx_299));
  NI32 X60Qx_300 = len_4_sysvq0asl(s_5);
  if (X60Qx_300 == 0){
    nimStrDestroy(s_5);
    return (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_21);
  result_21 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  {
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_4 = toOpenArray_2_sysvq0asl((&s_5));
    NI32 X60Qlf_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_301 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_4);
        if (X60Qlf_5 < X60Qx_301){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_4, X60Qlf_5);
            if ((*X60Qii_2) == (NC8)'.'){
              add_1_sysvq0asl((&result_21), (NC8)'_');}
            else {
              NB8 X60Qx_302;
              NB8 X60Qx_303;
              NB8 X60Qx_304;
              NB8 X60Qx_305;
              if ((NC8)'a' <= (*X60Qii_2)){
                X60Qx_305 = ((*X60Qii_2) <= (NC8)'z');}
              else {
                X60Qx_305 = NIM_FALSE;}
              if (X60Qx_305){
                X60Qx_304 = NIM_TRUE;}
              else {
                NB8 X60Qx_306;
                if ((NC8)'A' <= (*X60Qii_2)){
                  X60Qx_306 = ((*X60Qii_2) <= (NC8)'Z');}
                else {
                  X60Qx_306 = NIM_FALSE;}
                X60Qx_304 = X60Qx_306;}
              if (X60Qx_304){
                X60Qx_303 = NIM_TRUE;}
              else {
                NB8 X60Qx_307;
                if ((NC8)'0' <= (*X60Qii_2)){
                  X60Qx_307 = ((*X60Qii_2) <= (NC8)'9');}
                else {
                  X60Qx_307 = NIM_FALSE;}
                X60Qx_303 = X60Qx_307;}
              if (X60Qx_303){
                X60Qx_302 = NIM_TRUE;}
              else {
                X60Qx_302 = ((*X60Qii_2) == (NC8)'_');}
              if (X60Qx_302){
                add_1_sysvq0asl((&result_21), (*X60Qii_2));}
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
  return result_21;
  nimStrDestroy(s_5);
  return result_21;}
string_0_sysvq0asl srcScalarName_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_0){
  string_0_sysvq0asl result_22;
  nimStrWasMoved((&result_22));
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
  nimStrDestroy(result_22);
  result_22 = X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  nimStrDestroy(X60Qx_3);
  return result_22;
  nimStrDestroy(X60Qx_3);
  return result_22;}
NB8 podHasEnumOrArray_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_1){
  NB8 result_24;
  switch ((*td_1).d_00.kind_0){
    case 8:
    case 9:
    {
      result_24 = NIM_TRUE;}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_314;
      if ((!((*td_1).d_00.base_0 == NIM_NIL))){
        NB8 X60Qx_315 = podHasEnumOrArray_0_run8hsnpi((*td_1).d_00.base_0);
        X60Qx_314 = X60Qx_315;}
      else {
        X60Qx_314 = NIM_FALSE;}
      if (X60Qx_314){
        return NIM_TRUE;}
      {
        openArray_0_I3ca6t4_layptix6a1 X60Qlf_6 = toOpenArray_1_I0zz6qv1_layptix6a1((*td_1).d_00.fields_0);
        NI32 X60Qlf_7 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_316 = len_6_I0tpktl1_layptix6a1(X60Qlf_6);
            if (X60Qlf_7 < X60Qx_316){
              {
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_2 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_6, X60Qlf_7);
                NB8 X60Qx_317 = podHasEnumOrArray_0_run8hsnpi((*X60Qii_2));
                if (X60Qx_317){
                  return NIM_TRUE;}}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;
      result_24 = NIM_FALSE;}
    break;
    case 13:
    {
      NB8 X60Qx_318;
      if ((!((*td_1).d_00.elem_0 == NIM_NIL))){
        NB8 X60Qx_319 = podHasEnumOrArray_0_run8hsnpi((*td_1).d_00.elem_0);
        X60Qx_318 = X60Qx_319;}
      else {
        X60Qx_318 = NIM_FALSE;}
      result_24 = X60Qx_318;}
    break;
    default:
    {
      result_24 = NIM_FALSE;}
    break;}
  return result_24;}
X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi seqElemCursor_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_1){
  X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi result_25;
  eQwasmovedQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi((&result_25));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(result_25);
  result_25 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
    .fld_0 = (Cursor_0_nifb6mq6y1){
      .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
    , .fld_1 = NIM_FALSE}
  ;
  NB8 X60Qx_107;
  NifKind_0_nif81dubp1 X60Qx_320 = kind_0_nifb6mq6y1(cur_1);
  if (X60Qx_320 == 11){
    string_0_sysvq0asl X60Qtmp_46 = nodeTag_0_run8hsnpi(cur_1);
    NB8 X60Qx_321 = eqQ_20_sysvq0asl(X60Qtmp_46, (string_0_sysvq0asl){
      .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
    );
    X60Qx_107 = X60Qx_321;
    nimStrDestroy(X60Qtmp_46);}
  else {
    X60Qx_107 = NIM_FALSE;}
  if (X60Qx_107){
    Cursor_0_nifb6mq6y1 e_11 = eQdup_0_nifb6mq6y1(cur_1);
    inc_0_nifb6mq6y1((&e_11));
    Cursor_0_nifb6mq6y1 X60Qtmp_47 = e_11;
    eQwasMoved_0_nifb6mq6y1((&e_11));
    result_25 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
      .fld_0 = X60Qtmp_47, .fld_1 = NIM_TRUE}
    ;
    eQdestroy_0_nifb6mq6y1((&e_11));
    return result_25;
    eQdestroy_0_nifb6mq6y1((&e_11));}
  NifKind_0_nif81dubp1 X60Qx_322 = kind_0_nifb6mq6y1(cur_1);
  if (X60Qx_322 == 4){
    NU32 X60Qx_323 = symId_0_nifb6mq6y1(cur_1);
    LoadResult_0_prorcx25w1 res_7 = tryLoadSymSafe_0_modzy18mg1(X60Qx_323);
    NB8 X60Qx_108;
    NB8 X60Qx_324;
    if (res_7.status_0 == 3){
      NifKind_0_nif81dubp1 X60Qx_325 = kind_0_nifb6mq6y1(res_7.decl_0);
      X60Qx_324 = (X60Qx_325 == 11);}
    else {
      X60Qx_324 = NIM_FALSE;}
    if (X60Qx_324){
      string_0_sysvq0asl X60Qtmp_48 = nodeTag_0_run8hsnpi(res_7.decl_0);
      NB8 X60Qx_326 = eqQ_20_sysvq0asl(X60Qtmp_48, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
      );
      X60Qx_108 = X60Qx_326;
      nimStrDestroy(X60Qtmp_48);}
    else {
      X60Qx_108 = NIM_FALSE;}
    if (X60Qx_108){
      TypeDecl_0_decqocs071 td_13 = asTypeDecl_0_decqocs071(res_7.decl_0);
      Cursor_0_nifb6mq6y1 b_1 = td_13.typevars_0;
      eQwasMoved_0_nifb6mq6y1((&td_13.typevars_0));
      NB8 X60Qx_109;
      NifKind_0_nif81dubp1 X60Qx_327 = kind_0_nifb6mq6y1(b_1);
      if (X60Qx_327 == 11){
        string_0_sysvq0asl X60Qtmp_49 = nodeTag_0_run8hsnpi(b_1);
        NB8 X60Qx_328 = eqQ_20_sysvq0asl(X60Qtmp_49, (string_0_sysvq0asl){
          .bytes_0 = 7627010u, .more_0 = NIM_NIL}
        );
        X60Qx_109 = X60Qx_328;
        nimStrDestroy(X60Qtmp_49);}
      else {
        X60Qx_109 = NIM_FALSE;}
      if (X60Qx_109){
        inc_0_nifb6mq6y1((&b_1));
        skip_0_nifb6mq6y1((&b_1));
        Cursor_0_nifb6mq6y1 X60Qtmp_50 = b_1;
        eQwasMoved_0_nifb6mq6y1((&b_1));
        result_25 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
          .fld_0 = X60Qtmp_50, .fld_1 = NIM_TRUE}
        ;
        eQdestroy_0_nifb6mq6y1((&b_1));
        eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_13));
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
        return result_25;}
      eQdestroy_0_nifb6mq6y1((&b_1));
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_13));}
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);}
  return result_25;}
X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi seqElemNameSym_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_2, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_0){
  X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi result_26;
  eQwasmovedQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi((&result_26));
  eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(result_26);
  result_26 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
    .fld_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .fld_1 = ((NU32)0u)}
  ;
  X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi X60Qtmptup_0 = seqElemCursor_0_run8hsnpi(cur_2);
  Cursor_0_nifb6mq6y1 ec_0 = X60Qtmptup_0.fld_0;
  eQwasMoved_0_nifb6mq6y1((&X60Qtmptup_0.fld_0));
  NB8 ok_0 = X60Qtmptup_0.fld_1;
  NB8 X60Qx_329;
  if (ok_0){
    NifKind_0_nif81dubp1 X60Qx_330 = kind_0_nifb6mq6y1(ec_0);
    X60Qx_329 = (X60Qx_330 == 4);}
  else {
    X60Qx_329 = NIM_FALSE;}
  if (X60Qx_329){
    NU32 X60Qx_331 = symId_0_nifb6mq6y1(ec_0);
    string_0_sysvq0asl X60Qx_332 = baseNameOf_0_run8hsnpi(X60Qx_331);
    NU32 X60Qx_333 = symId_0_nifb6mq6y1(ec_0);
    result_26 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
      .fld_0 = X60Qx_332, .fld_1 = X60Qx_333}
    ;
    eQdestroy_0_nifb6mq6y1((&ec_0));
    eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_0);
    return result_26;}
  eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(result_26);
  string_0_sysvq0asl X60Qx_334 = srcScalarName_0_run8hsnpi(elem_0);
  result_26 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
    .fld_0 = X60Qx_334, .fld_1 = ((NU32)0u)}
  ;
  eQdestroy_0_nifb6mq6y1((&ec_0));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_0);
  return result_26;
  eQdestroy_0_nifb6mq6y1((&ec_0));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_0);
  return result_26;}
X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi arrayElemCursor_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_3){
  X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi result_27;
  eQwasmovedQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi((&result_27));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(result_27);
  result_27 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
    .fld_0 = (Cursor_0_nifb6mq6y1){
      .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
    , .fld_1 = NIM_FALSE}
  ;
  NB8 X60Qx_110;
  NifKind_0_nif81dubp1 X60Qx_335 = kind_0_nifb6mq6y1(cur_3);
  if (X60Qx_335 == 11){
    string_0_sysvq0asl X60Qtmp_51 = nodeTag_0_run8hsnpi(cur_3);
    NB8 X60Qx_336 = eqQ_20_sysvq0asl(X60Qtmp_51, (string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
    );
    X60Qx_110 = X60Qx_336;
    nimStrDestroy(X60Qtmp_51);}
  else {
    X60Qx_110 = NIM_FALSE;}
  if (X60Qx_110){
    Cursor_0_nifb6mq6y1 e_12 = eQdup_0_nifb6mq6y1(cur_3);
    inc_0_nifb6mq6y1((&e_12));
    Cursor_0_nifb6mq6y1 X60Qtmp_52 = e_12;
    eQwasMoved_0_nifb6mq6y1((&e_12));
    result_27 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
      .fld_0 = X60Qtmp_52, .fld_1 = NIM_TRUE}
    ;
    eQdestroy_0_nifb6mq6y1((&e_12));
    return result_27;
    eQdestroy_0_nifb6mq6y1((&e_12));}
  NifKind_0_nif81dubp1 X60Qx_337 = kind_0_nifb6mq6y1(cur_3);
  if (X60Qx_337 == 4){
    NU32 X60Qx_338 = symId_0_nifb6mq6y1(cur_3);
    LoadResult_0_prorcx25w1 res_8 = tryLoadSymSafe_0_modzy18mg1(X60Qx_338);
    NB8 X60Qx_111;
    NB8 X60Qx_339;
    if (res_8.status_0 == 3){
      NifKind_0_nif81dubp1 X60Qx_340 = kind_0_nifb6mq6y1(res_8.decl_0);
      X60Qx_339 = (X60Qx_340 == 11);}
    else {
      X60Qx_339 = NIM_FALSE;}
    if (X60Qx_339){
      string_0_sysvq0asl X60Qtmp_53 = nodeTag_0_run8hsnpi(res_8.decl_0);
      NB8 X60Qx_341 = eqQ_20_sysvq0asl(X60Qtmp_53, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
      );
      X60Qx_111 = X60Qx_341;
      nimStrDestroy(X60Qtmp_53);}
    else {
      X60Qx_111 = NIM_FALSE;}
    if (X60Qx_111){
      TypeDecl_0_decqocs071 td_14 = asTypeDecl_0_decqocs071(res_8.decl_0);
      NB8 X60Qx_112;
      NifKind_0_nif81dubp1 X60Qx_342 = kind_0_nifb6mq6y1(td_14.body_0);
      if (X60Qx_342 == 11){
        string_0_sysvq0asl X60Qtmp_54 = nodeTag_0_run8hsnpi(td_14.body_0);
        NB8 X60Qx_343 = eqQ_20_sysvq0asl(X60Qtmp_54, (string_0_sysvq0asl){
          .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
        );
        X60Qx_112 = X60Qx_343;
        nimStrDestroy(X60Qtmp_54);}
      else {
        X60Qx_112 = NIM_FALSE;}
      if (X60Qx_112){
        Cursor_0_nifb6mq6y1 e_13 = td_14.body_0;
        eQwasMoved_0_nifb6mq6y1((&td_14.body_0));
        inc_0_nifb6mq6y1((&e_13));
        Cursor_0_nifb6mq6y1 X60Qtmp_55 = e_13;
        eQwasMoved_0_nifb6mq6y1((&e_13));
        result_27 = (X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi){
          .fld_0 = X60Qtmp_55, .fld_1 = NIM_TRUE}
        ;
        eQdestroy_0_nifb6mq6y1((&e_13));
        eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_14));
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
        return result_27;
        eQdestroy_0_nifb6mq6y1((&e_13));}
      eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_14));}
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);}
  return result_27;}
X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi arrayElemNameSym_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_4, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_1){
  X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi result_28;
  eQwasmovedQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi((&result_28));
  eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(result_28);
  result_28 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
    .fld_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .fld_1 = ((NU32)0u)}
  ;
  X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi X60Qtmptup_1 = arrayElemCursor_0_run8hsnpi(cur_4);
  Cursor_0_nifb6mq6y1 ec_1 = X60Qtmptup_1.fld_0;
  eQwasMoved_0_nifb6mq6y1((&X60Qtmptup_1.fld_0));
  NB8 ok_1 = X60Qtmptup_1.fld_1;
  NB8 X60Qx_344;
  if (ok_1){
    NifKind_0_nif81dubp1 X60Qx_345 = kind_0_nifb6mq6y1(ec_1);
    X60Qx_344 = (X60Qx_345 == 4);}
  else {
    X60Qx_344 = NIM_FALSE;}
  if (X60Qx_344){
    NU32 X60Qx_346 = symId_0_nifb6mq6y1(ec_1);
    string_0_sysvq0asl X60Qx_347 = baseNameOf_0_run8hsnpi(X60Qx_346);
    NU32 X60Qx_348 = symId_0_nifb6mq6y1(ec_1);
    result_28 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
      .fld_0 = X60Qx_347, .fld_1 = X60Qx_348}
    ;
    eQdestroy_0_nifb6mq6y1((&ec_1));
    eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_1);
    return result_28;}
  eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(result_28);
  string_0_sysvq0asl X60Qx_349 = srcScalarName_0_run8hsnpi(elem_1);
  result_28 = (X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi){
    .fld_0 = X60Qx_349, .fld_1 = ((NU32)0u)}
  ;
  eQdestroy_0_nifb6mq6y1((&ec_1));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_1);
  return result_28;
  eQdestroy_0_nifb6mq6y1((&ec_1));
  eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_1);
  return result_28;}
X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 varElemExpr_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_5, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_2){
  X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 result_29;
  eQwasmovedQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi((&result_29));
  switch ((*td_2).d_00.kind_0){
    case 14:
    {
      result_29 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = (string_0_sysvq0asl){
          .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
        , .fld_1 = NIM_TRUE}
      ;
      return result_29;}
    break;
    case 0:
    case 1:
    case 2:
    case 4:
    case 3:
    {
      string_0_sysvq0asl n_5 = srcScalarName_0_run8hsnpi(td_2);
      string_0_sysvq0asl X60Qx_350 = nimStrDup(n_5);
      NI32 X60Qx_351 = len_4_sysvq0asl(n_5);
      result_29 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = X60Qx_350, .fld_1 = (0 < X60Qx_351)}
      ;
      nimStrDestroy(n_5);
      return result_29;
      nimStrDestroy(n_5);}
    break;
    case 15:
    {
      if ((*td_2).d_00.elem_0 == NIM_NIL){
        result_29 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
          .fld_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .fld_1 = NIM_FALSE}
        ;
        return result_29;}
      X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi X60Qtmptup_2 = seqElemCursor_0_run8hsnpi(cur_5);
      Cursor_0_nifb6mq6y1 ec_2 = X60Qtmptup_2.fld_0;
      eQwasMoved_0_nifb6mq6y1((&X60Qtmptup_2.fld_0));
      NB8 ok_2 = X60Qtmptup_2.fld_1;
      if ((!ok_2)){
        result_29 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
          .fld_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .fld_1 = NIM_FALSE}
        ;
        eQdestroy_0_nifb6mq6y1((&ec_2));
        eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_2);
        return result_29;}
      X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 X60Qtmptup_3 = varElemExpr_0_run8hsnpi(ec_2, (*td_2).d_00.elem_0);
      string_0_sysvq0asl inner_1 = X60Qtmptup_3.fld_0;
      nimStrWasMoved((&X60Qtmptup_3.fld_0));
      NB8 iok_0 = X60Qtmptup_3.fld_1;
      if ((!iok_0)){
        result_29 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
          .fld_0 = (string_0_sysvq0asl){
            .bytes_0 = 0u, .more_0 = NIM_NIL}
          , .fld_1 = NIM_FALSE}
        ;
        nimStrDestroy(inner_1);
        eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_3);
        eQdestroy_0_nifb6mq6y1((&ec_2));
        eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_2);
        return result_29;}
      NI32 X60Qx_352 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
      );
      NI32 X60Qx_353 = len_4_sysvq0asl(inner_1);
      NI32 X60Qx_354 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 23809u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_352 + X60Qx_353)) + X60Qx_354)));
      add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
        .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_2), inner_1);
      add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
        .bytes_0 = 23809u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qtmp_56 = X60Qdesugar_2;
      nimStrWasMoved((&X60Qdesugar_2));
      result_29 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = X60Qtmp_56, .fld_1 = NIM_TRUE}
      ;
      nimStrDestroy(X60Qdesugar_2);
      nimStrDestroy(inner_1);
      eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_3);
      eQdestroy_0_nifb6mq6y1((&ec_2));
      eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_2);
      return result_29;
      nimStrDestroy(X60Qdesugar_2);
      nimStrDestroy(inner_1);
      eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_3);
      eQdestroy_0_nifb6mq6y1((&ec_2));
      eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_2);}
    break;
    default:
    {
      result_29 = (X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21){
        .fld_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .fld_1 = NIM_FALSE}
      ;
      return result_29;}
    break;}
  return result_29;}
string_0_sysvq0asl leafScalarName_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_3){
  string_0_sysvq0asl result_30;
  nimStrWasMoved((&result_30));
  switch ((*td_3).d_00.kind_0){
    case 15:
    case 9:
    {
      string_0_sysvq0asl X60Qx_9;
      nimStrWasMoved((&X60Qx_9));
      if ((!((*td_3).d_00.elem_0 == NIM_NIL))){
        nimStrDestroy(X60Qx_9);
        string_0_sysvq0asl X60Qx_355 = leafScalarName_0_run8hsnpi((*td_3).d_00.elem_0);
        X60Qx_9 = X60Qx_355;}
      else {
        nimStrDestroy(X60Qx_9);
        X60Qx_9 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        ;}
      nimStrDestroy(result_30);
      result_30 = X60Qx_9;
      nimStrWasMoved((&X60Qx_9));
      nimStrDestroy(X60Qx_9);}
    break;
    case 14:
    {
      nimStrDestroy(result_30);
      result_30 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    break;
    default:
    {
      nimStrDestroy(result_30);
      string_0_sysvq0asl X60Qx_356 = srcScalarName_0_run8hsnpi(td_3);
      result_30 = X60Qx_356;}
    break;}
  return result_30;}
NB8 compositeOk_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_1, NI32 depth_1){
  NB8 result_31;
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
      result_31 = NIM_TRUE;}
    break;
    case 17:
    case 13:
    {
      NB8 X60Qx_357;
      if ((!((*t_1).d_00.elem_0 == NIM_NIL))){
        NB8 X60Qx_358 = compositeOk_0_run8hsnpi((*t_1).d_00.elem_0, ((NI32)(depth_1 + 1)));
        X60Qx_357 = X60Qx_358;}
      else {
        X60Qx_357 = NIM_FALSE;}
      result_31 = X60Qx_357;}
    break;
    case 16:
    {
      NI32 X60Qx_359 = setSizeInBytes_0_layptix6a1((*t_1).d_00.elem_0);
      result_31 = (0 < X60Qx_359);}
    break;
    case 15:
    {
      if ((*t_1).d_00.elem_0 == NIM_NIL){
        return NIM_FALSE;}
      NB8 X60Qx_360;
      if ((*(*t_1).d_00.elem_0).d_00.kind_0 == 10){
        X60Qx_360 = NIM_TRUE;}
      else {
        X60Qx_360 = ((*(*t_1).d_00.elem_0).d_00.kind_0 == 11);}
      if (X60Qx_360){
        return NIM_FALSE;}
      NB8 X60Qx_361 = compositeOk_0_run8hsnpi((*t_1).d_00.elem_0, ((NI32)(depth_1 + 1)));
      result_31 = X60Qx_361;}
    break;
    case 9:
    {
      if ((*t_1).d_00.elem_0 == NIM_NIL){
        return NIM_FALSE;}
      NB8 X60Qx_362;
      if ((*(*t_1).d_00.elem_0).d_00.kind_0 == 10){
        X60Qx_362 = NIM_TRUE;}
      else {
        X60Qx_362 = ((*(*t_1).d_00.elem_0).d_00.kind_0 == 11);}
      if (X60Qx_362){
        return NIM_FALSE;}
      NB8 X60Qx_363 = compositeOk_0_run8hsnpi((*t_1).d_00.elem_0, ((NI32)(depth_1 + 1)));
      result_31 = X60Qx_363;}
    break;
    case 10:
    case 11:
    {
      NB8 X60Qx_364;
      if ((*t_1).d_00.incomplete_0){
        X60Qx_364 = NIM_TRUE;}
      else {
        X60Qx_364 = (*t_1).d_00.union_0;}
      if (X60Qx_364){
        return NIM_FALSE;}
      NI32 i_1 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_365 = len_3_I5m68tr1_aow7lb5cq1((*t_1).d_00.fields_0);
          if (i_1 < X60Qx_365){
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_366 = getQ_7_I45w7c91_aow7lb5cq1((*t_1).d_00.fields_0, i_1);
            NB8 X60Qx_367 = compositeOk_0_run8hsnpi((*X60Qx_366), ((NI32)(depth_1 + 1)));
            if ((!X60Qx_367)){
              return NIM_FALSE;}
            inc_1_I6wjjge_aow2h993l1((&i_1));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      result_31 = NIM_TRUE;}
    break;
    case 5:
    {
      result_31 = NIM_FALSE;}
    break;
    case 6:
    case 7:
    case 12:
    case 18:
    {
      result_31 = NIM_FALSE;}
    break;}
  return result_31;}
string_0_sysvq0asl abiKindName_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_2){
  string_0_sysvq0asl result_32;
  nimStrWasMoved((&result_32));
  if (t_2 == NIM_NIL){
    return (string_0_sysvq0asl){
      .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl X60Qx_10;
  nimStrWasMoved((&X60Qx_10));
  switch ((*t_2).d_00.kind_0){
    case 0:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1953392899u, .more_0 = NIM_NIL}
      ;}
    break;
    case 1:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1852405246u, .more_0 = (&strlit_0_I18357185398770638485_aow7lb5cq1)}
      ;}
    break;
    case 2:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1869375230u, .more_0 = (&strlit_0_I11643015150811461308_aow7lb5cq1)}
      ;}
    break;
    case 3:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1634231294u, .more_0 = (&strlit_0_I3703322799828345117_aow7lb5cq1)}
      ;}
    break;
    case 4:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_aow7lb5cq1)}
      ;}
    break;
    case 8:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
      ;}
    break;
    case 17:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16597999082088934835_emi78vuj01)}
      ;}
    break;
    case 16:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1952805635u, .more_0 = NIM_NIL}
      ;}
    break;
    case 5:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
      ;}
    break;
    case 6:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
      ;}
    break;
    case 7:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I16971225136864641703_nimry5ra91)}
      ;}
    break;
    case 13:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_fiepkwzpc)}
      ;}
    break;
    case 14:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
      ;}
    break;
    case 15:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
      ;}
    break;
    case 9:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_aow7lb5cq1)}
      ;}
    break;
    case 11:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
      ;}
    break;
    case 10:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
      ;}
    break;
    case 12:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I2937163572003096168_run8hsnpi)}
      ;}
    break;
    case 18:
    {
      nimStrDestroy(X60Qx_10);
      X60Qx_10 = (string_0_sysvq0asl){
        .bytes_0 = 1668175358u, .more_0 = (&strlit_0_I9228293753161605925_maglvku5g)}
      ;}
    break;}
  nimStrDestroy(result_32);
  result_32 = X60Qx_10;
  nimStrWasMoved((&X60Qx_10));
  nimStrDestroy(X60Qx_10);
  return result_32;
  nimStrDestroy(X60Qx_10);
  return result_32;}
string_0_sysvq0asl marshalClassName_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* t_3){
  string_0_sysvq0asl result_33;
  nimStrWasMoved((&result_33));
  if (t_3 == NIM_NIL){
    return (string_0_sysvq0asl){
      .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
    ;}
  string_0_sysvq0asl X60Qx_11;
  nimStrWasMoved((&X60Qx_11));
  MarshalClass_0_marbdjk4t1 X60Qx_368 = marshalClass_0_marbdjk4t1(t_3);
  switch (X60Qx_368){
    case 0:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1399025150u, .more_0 = (&strlit_0_I990882640025799687_marbdjk4t1)}
      ;}
    break;
    case 1:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1348693502u, .more_0 = (&strlit_0_I3470422228391514573_marbdjk4t1)}
      ;}
    break;
    case 2:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1399025150u, .more_0 = (&strlit_0_I696057604909997793_marbdjk4t1)}
      ;}
    break;
    case 3:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1399025150u, .more_0 = (&strlit_0_I17665588267585860306_marbdjk4t1)}
      ;}
    break;
    case 4:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1382247934u, .more_0 = (&strlit_0_I8160649543150574237_marbdjk4t1)}
      ;}
    break;
    case 5:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1130589694u, .more_0 = (&strlit_0_I12549307355442489107_marbdjk4t1)}
      ;}
    break;
    case 6:
    {
      nimStrDestroy(X60Qx_11);
      X60Qx_11 = (string_0_sysvq0asl){
        .bytes_0 = 1432579582u, .more_0 = (&strlit_0_I3538386510047344326_marbdjk4t1)}
      ;}
    break;}
  nimStrDestroy(result_33);
  result_33 = X60Qx_11;
  nimStrWasMoved((&X60Qx_11));
  nimStrDestroy(X60Qx_11);
  return result_33;
  nimStrDestroy(X60Qx_11);
  return result_33;}
X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi declineWire_0_run8hsnpi(string_0_sysvq0asl reason_0){
  X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi result_34;
  eQwasmovedQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_34));
  declineNote_0_croph25r5(1, reason_0);
  eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_34));
  result_34 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
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
  return result_34;}
X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi describeTypeCore_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_6){
  X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi result_35;
  eQwasmovedQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_35));
  string_0_sysvq0asl srcName_0 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NU32 esym_0 = ((NU32)0u);
  NifKind_0_nif81dubp1 X60Qx_369 = kind_0_nifb6mq6y1(cur_6);
  if (X60Qx_369 == 4){
    nimStrDestroy(srcName_0);
    NU32 X60Qx_370 = symId_0_nifb6mq6y1(cur_6);
    string_0_sysvq0asl X60Qx_371 = baseNameOf_0_run8hsnpi(X60Qx_370);
    srcName_0 = X60Qx_371;
    NU32 X60Qx_372 = symId_0_nifb6mq6y1(cur_6);
    esym_0 = X60Qx_372;}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_15 = typeDescOf_0_run8hsnpi(cur_6, 0);
  if (td_15 == NIM_NIL){
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_373 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
      .bytes_0 = 1701344510u, .more_0 = (&strlit_0_I13019318966386094724_run8hsnpi)}
    );
    result_35 = X60Qx_373;
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
    nimStrDestroy(srcName_0);
    return result_35;}
  if ((*td_15).d_00.kind_0 == 5){
    string_0_sysvq0asl ptag_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    NifKind_0_nif81dubp1 X60Qx_374 = kind_0_nifb6mq6y1(cur_6);
    if (X60Qx_374 == 11){
      nimStrDestroy(ptag_0);
      string_0_sysvq0asl X60Qx_375 = nodeTag_0_run8hsnpi(cur_6);
      ptag_0 = X60Qx_375;}
    NB8 X60Qx_376 = eqQ_20_sysvq0asl(ptag_0, (string_0_sysvq0asl){
      .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
    );
    if (X60Qx_376){
      Cursor_0_nifb6mq6y1 pc_1 = eQdup_0_nifb6mq6y1(cur_6);
      inc_0_nifb6mq6y1((&pc_1));
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* pd_0 = typeDescOf_0_run8hsnpi(pc_1, 0);
      if (pd_0 == NIM_NIL){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_377 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I4958048190723036074_run8hsnpi)}
        );
        result_35 = X60Qx_377;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
        eQdestroy_0_nifb6mq6y1((&pc_1));
        nimStrDestroy(ptag_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
        nimStrDestroy(srcName_0);
        return result_35;}
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* flat_0 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
      {
        while (NIM_TRUE){
          NB8 X60Qx_378;
          if ((!(flat_0 == NIM_NIL))){
            X60Qx_378 = ((*flat_0).d_00.kind_0 == 13);}
          else {
            X60Qx_378 = NIM_FALSE;}
          if (X60Qx_378){
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qlhs_57 = flat_0;
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_379 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*flat_0).d_00.elem_0);
            flat_0 = X60Qx_379;
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qlhs_57);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      if (flat_0 == NIM_NIL){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_380 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I16235671060003324787_run8hsnpi)}
        );
        result_35 = X60Qx_380;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
        eQdestroy_0_nifb6mq6y1((&pc_1));
        nimStrDestroy(ptag_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
        nimStrDestroy(srcName_0);
        return result_35;}
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
          NI32 X60Qx_381 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I13225935872158492040_run8hsnpi)}
          );
          NI32 X60Qx_382 = len_4_sysvq0asl(X60Qdesugar_3);
          NI32 X60Qx_383 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I3673080887886368090_run8hsnpi)}
          );
          string_0_sysvq0asl X60Qdesugar_4 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_381 + X60Qx_382)) + X60Qx_383)));
          add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
            .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I13225935872158492040_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_4), X60Qdesugar_3);
          add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
            .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I3673080887886368090_run8hsnpi)}
          );
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_384 = declineWire_0_run8hsnpi(X60Qdesugar_4);
          result_35 = X60Qx_384;
          nimStrDestroy(X60Qdesugar_4);
          nimStrDestroy(X60Qdesugar_3);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
          eQdestroy_0_nifb6mq6y1((&pc_1));
          nimStrDestroy(ptag_0);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
          nimStrDestroy(srcName_0);
          return result_35;
          nimStrDestroy(X60Qdesugar_4);
          nimStrDestroy(X60Qdesugar_3);}
        break;}
      string_0_sysvq0asl pn_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NU32 psym_0 = ((NU32)0u);
      NifKind_0_nif81dubp1 X60Qx_385 = kind_0_nifb6mq6y1(pc_1);
      if (X60Qx_385 == 4){
        NU32 X60Qx_386 = symId_0_nifb6mq6y1(pc_1);
        psym_0 = X60Qx_386;
        nimStrDestroy(pn_0);
        string_0_sysvq0asl X60Qx_387 = baseNameOf_0_run8hsnpi(psym_0);
        pn_0 = X60Qx_387;}
      else {
        nimStrDestroy(pn_0);
        string_0_sysvq0asl X60Qx_388 = srcScalarName_0_run8hsnpi(pd_0);
        pn_0 = X60Qx_388;}
      NI32 X60Qx_389 = len_4_sysvq0asl(pn_0);
      if (X60Qx_389 == 0){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_390 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I4342340915346939023_run8hsnpi)}
        );
        result_35 = X60Qx_390;
        nimStrDestroy(pn_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
        eQdestroy_0_nifb6mq6y1((&pc_1));
        nimStrDestroy(ptag_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
        nimStrDestroy(srcName_0);
        return result_35;}
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 psa_0 = sizeAlign_1_layptix6a1(pd_0, 8);
      if (psa_0.fld_0 <= 0){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_391 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I8993670282046711299_run8hsnpi)}
        );
        result_35 = X60Qx_391;
        nimStrDestroy(pn_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
        eQdestroy_0_nifb6mq6y1((&pc_1));
        nimStrDestroy(ptag_0);
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
        nimStrDestroy(srcName_0);
        return result_35;}
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_58 = pd_0;
      eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&pd_0));
      WireField_0_run8hsnpi pf_0 = (WireField_0_run8hsnpi){
        .desc_0 = X60Qtmp_58, .srcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
      ;
      pf_0.isPtrArena_0 = NIM_TRUE;
      string_0_sysvq0asl* X60Qlhs_59 = (&pf_0.srcType_0);
      nimStrDestroy((*X60Qlhs_59));
      string_0_sysvq0asl X60Qx_392 = nimStrDup(pn_0);
      (*X60Qlhs_59) = X60Qx_392;
      pf_0.typeSym_0 = psym_0;
      string_0_sysvq0asl* X60Qlhs_60 = (&pf_0.elemSrcType_0);
      nimStrDestroy((*X60Qlhs_60));
      (*X60Qlhs_60) = pn_0;
      nimStrWasMoved((&pn_0));
      pf_0.elemSize_0 = psa_0.fld_0;
      pf_0.wireSize_0 = 8;
      pf_0.wireAlign_0 = 8;
      WireField_0_run8hsnpi X60Qtmp_61 = pf_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_0));
      result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_61, .fld_1 = NIM_TRUE}
      ;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_0));
      nimStrDestroy(pn_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
      eQdestroy_0_nifb6mq6y1((&pc_1));
      nimStrDestroy(ptag_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_0));
      nimStrDestroy(pn_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(flat_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pd_0);
      eQdestroy_0_nifb6mq6y1((&pc_1));}
    NB8 X60Qx_393 = eqQ_20_sysvq0asl(ptag_0, (string_0_sysvq0asl){
      .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
    );
    if (X60Qx_393){
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_62 = td_15;
      eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&td_15));
      WireField_0_run8hsnpi cf_0 = (WireField_0_run8hsnpi){
        .desc_0 = X60Qtmp_62, .srcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
      ;
      cf_0.isForeignPtr_0 = NIM_TRUE;
      string_0_sysvq0asl* X60Qlhs_63 = (&cf_0.srcType_0);
      nimStrDestroy((*X60Qlhs_63));
      (*X60Qlhs_63) = (string_0_sysvq0asl){
        .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
      ;
      cf_0.wireSize_0 = 8;
      cf_0.wireAlign_0 = 8;
      WireField_0_run8hsnpi X60Qtmp_64 = cf_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&cf_0));
      result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_64, .fld_1 = NIM_TRUE}
      ;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&cf_0));
      nimStrDestroy(ptag_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&cf_0));}
    string_0_sysvq0asl X60Qx_12;
    nimStrWasMoved((&X60Qx_12));
    NI32 X60Qx_394 = len_4_sysvq0asl(ptag_0);
    if (0 < X60Qx_394){
      nimStrDestroy(X60Qx_12);
      X60Qx_12 = ptag_0;
      nimStrWasMoved((&ptag_0));}
    else {
      nimStrDestroy(X60Qx_12);
      X60Qx_12 = (string_0_sysvq0asl){
        .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I8793898668013225318_run8hsnpi)}
      ;}
    string_0_sysvq0asl X60Qdesugar_5 = X60Qx_12;
    nimStrWasMoved((&X60Qx_12));
    NI32 X60Qx_395 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1634758654u, .more_0 = (&strlit_0_I4709633162961732303_run8hsnpi)}
    );
    NI32 X60Qx_396 = len_4_sysvq0asl(X60Qdesugar_5);
    NI32 X60Qx_397 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 540682750u, .more_0 = (&strlit_0_I2888973717457040847_run8hsnpi)}
    );
    string_0_sysvq0asl X60Qdesugar_6 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_395 + X60Qx_396)) + X60Qx_397)));
    add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
      .bytes_0 = 1634758654u, .more_0 = (&strlit_0_I4709633162961732303_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_6), X60Qdesugar_5);
    add_2_sysvq0asl((&X60Qdesugar_6), (string_0_sysvq0asl){
      .bytes_0 = 540682750u, .more_0 = (&strlit_0_I2888973717457040847_run8hsnpi)}
    );
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_398 = declineWire_0_run8hsnpi(X60Qdesugar_6);
    result_35 = X60Qx_398;
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qx_12);
    nimStrDestroy(ptag_0);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
    nimStrDestroy(srcName_0);
    return result_35;
    nimStrDestroy(X60Qdesugar_6);
    nimStrDestroy(X60Qdesugar_5);
    nimStrDestroy(X60Qx_12);
    nimStrDestroy(ptag_0);}
  if ((*td_15).d_00.kind_0 == 9){
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_2 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*td_15).d_00.elem_0);
    NB8 X60Qx_399;
    if (el_2 == NIM_NIL){
      X60Qx_399 = NIM_TRUE;}
    else {
      X60Qx_399 = ((*td_15).d_00.count_0 <= 0);}
    if (X60Qx_399){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_400 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I13889320805933294264_run8hsnpi)}
      );
      result_35 = X60Qx_400;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    MarshalClass_0_marbdjk4t1 ec_3 = marshalClass_0_marbdjk4t1(el_2);
    NB8 X60Qx_401;
    if (ec_3 == 0){
      X60Qx_401 = NIM_TRUE;}
    else {
      X60Qx_401 = (ec_3 == 1);}
    if ((!X60Qx_401)){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_402 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I16185026956335355254_run8hsnpi)}
      );
      result_35 = X60Qx_402;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    NB8 X60Qx_403;
    if (ec_3 == 1){
      NB8 X60Qx_404 = podHasEnumOrArray_0_run8hsnpi(el_2);
      X60Qx_403 = X60Qx_404;}
    else {
      X60Qx_403 = NIM_FALSE;}
    if (X60Qx_403){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_405 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I10498682809148144310_run8hsnpi)}
      );
      result_35 = X60Qx_405;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi X60Qtmptup_4 = arrayElemNameSym_0_run8hsnpi(cur_6, el_2);
    string_0_sysvq0asl en_0 = X60Qtmptup_4.fld_0;
    nimStrWasMoved((&X60Qtmptup_4.fld_0));
    NU32 ets_0 = X60Qtmptup_4.fld_1;
    NI32 X60Qx_406 = len_4_sysvq0asl(en_0);
    if (X60Qx_406 == 0){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_407 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I15756359906215420366_run8hsnpi)}
      );
      result_35 = X60Qx_407;
      nimStrDestroy(en_0);
      eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_4);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    NB8 X60Qx_408;
    if (ec_3 == 1){
      X60Qx_408 = (((NU32)ets_0) == ((NU32)0u));}
    else {
      X60Qx_408 = NIM_FALSE;}
    if (X60Qx_408){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_409 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I12763724795707366899_run8hsnpi)}
      );
      result_35 = X60Qx_409;
      nimStrDestroy(en_0);
      eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_4);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 esa_0 = sizeAlign_1_layptix6a1(el_2, 8);
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_410 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
    WireField_0_run8hsnpi af_0 = (WireField_0_run8hsnpi){
      .desc_0 = X60Qx_410, .srcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
    ;
    af_0.isArray_0 = NIM_TRUE;
    af_0.arrCount_0 = (*td_15).d_00.count_0;
    af_0.elemTypeSym_0 = ets_0;
    string_0_sysvq0asl* X60Qlhs_65 = (&af_0.elemSrcType_0);
    nimStrDestroy((*X60Qlhs_65));
    string_0_sysvq0asl X60Qx_411 = nimStrDup(en_0);
    (*X60Qlhs_65) = X60Qx_411;
    af_0.elemSize_0 = esa_0.fld_0;
    NI32 X60Qx_13;
    if (0 < esa_0.fld_1){
      X60Qx_13 = esa_0.fld_1;}
    else {
      X60Qx_13 = 1;}
    NI32 X60Qx_412 = align_0_layptix6a1(esa_0.fld_0, X60Qx_13);
    af_0.elemStride_0 = X60Qx_412;
    string_0_sysvq0asl X60Qdesugar_7 = dollarQ_2_sysvq0asl((*td_15).d_00.count_0);
    NI32 X60Qx_413 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I16157109470490228308_red2rogzl)}
    );
    NI32 X60Qx_414 = len_4_sysvq0asl(X60Qdesugar_7);
    NI32 X60Qx_415 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2108418u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_416 = len_4_sysvq0asl(en_0);
    NI32 X60Qx_417 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 23809u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_8 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_413 + X60Qx_414)) + X60Qx_415)) + X60Qx_416)) + X60Qx_417)));
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
    string_0_sysvq0asl* X60Qlhs_66 = (&af_0.srcType_0);
    nimStrDestroy((*X60Qlhs_66));
    (*X60Qlhs_66) = X60Qdesugar_8;
    nimStrWasMoved((&X60Qdesugar_8));
    af_0.wireSize_0 = ((NI32)(af_0.elemStride_0 * (*td_15).d_00.count_0));
    NI32 X60Qx_14;
    if (0 < esa_0.fld_1){
      X60Qx_14 = esa_0.fld_1;}
    else {
      X60Qx_14 = 1;}
    af_0.wireAlign_0 = X60Qx_14;
    WireField_0_run8hsnpi X60Qtmp_67 = af_0;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&af_0));
    result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_67, .fld_1 = NIM_TRUE}
    ;
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qdesugar_7);
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&af_0));
    nimStrDestroy(en_0);
    eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
    nimStrDestroy(srcName_0);
    return result_35;
    nimStrDestroy(X60Qdesugar_8);
    nimStrDestroy(X60Qdesugar_7);
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&af_0));
    nimStrDestroy(en_0);
    eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_2);}
  if ((*td_15).d_00.kind_0 == 6){
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* pl_0 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*td_15).d_00.elem_0);
    NB8 X60Qx_418;
    if (pl_0 == NIM_NIL){
      X60Qx_418 = NIM_TRUE;}
    else {
      NB8 X60Qx_419;
      if ((*pl_0).d_00.kind_0 == 10){
        X60Qx_419 = NIM_TRUE;}
      else {
        X60Qx_419 = ((*pl_0).d_00.kind_0 == 11);}
      X60Qx_418 = (!X60Qx_419);}
    if (X60Qx_418){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_420 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I15672252006839982641_run8hsnpi)}
      );
      result_35 = X60Qx_420;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    Cursor_0_nifb6mq6y1 rc_0 = eQdup_0_nifb6mq6y1(cur_6);
    NB8 X60Qx_113;
    NifKind_0_nif81dubp1 X60Qx_421 = kind_0_nifb6mq6y1(rc_0);
    if ((!(X60Qx_421 == 11))){
      X60Qx_113 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_68 = nodeTag_0_run8hsnpi(rc_0);
      NB8 X60Qx_422 = eqQ_20_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
        .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
      );
      X60Qx_113 = (!X60Qx_422);
      nimStrDestroy(X60Qtmp_68);}
    if (X60Qx_113){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_423 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I11886991017504759357_run8hsnpi)}
      );
      result_35 = X60Qx_423;
      eQdestroy_0_nifb6mq6y1((&rc_0));
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    inc_0_nifb6mq6y1((&rc_0));
    NifKind_0_nif81dubp1 X60Qx_424 = kind_0_nifb6mq6y1(rc_0);
    if ((!(X60Qx_424 == 4))){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_425 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I10876541292033031825_run8hsnpi)}
      );
      result_35 = X60Qx_425;
      eQdestroy_0_nifb6mq6y1((&rc_0));
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    NU32 psym_1 = symId_0_nifb6mq6y1(rc_0);
    string_0_sysvq0asl pn_1 = baseNameOf_0_run8hsnpi(psym_1);
    NB8 X60Qx_426;
    NI32 X60Qx_427 = len_4_sysvq0asl(pn_1);
    if (X60Qx_427 == 0){
      X60Qx_426 = NIM_TRUE;}
    else {
      X60Qx_426 = (((NU32)psym_1) == ((NU32)0u));}
    if (X60Qx_426){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_428 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I5262176531977851534_run8hsnpi)}
      );
      result_35 = X60Qx_428;
      nimStrDestroy(pn_1);
      eQdestroy_0_nifb6mq6y1((&rc_0));
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    NB8 X60Qx_429;
    MarshalClass_0_marbdjk4t1 X60Qx_430 = marshalClass_0_marbdjk4t1(pl_0);
    if (X60Qx_430 == 1){
      NB8 X60Qx_431 = podHasEnumOrArray_0_run8hsnpi(pl_0);
      X60Qx_429 = (!X60Qx_431);}
    else {
      X60Qx_429 = NIM_FALSE;}
    if (X60Qx_429){
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_432 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      WireField_0_run8hsnpi rfld_0 = (WireField_0_run8hsnpi){
        .desc_0 = X60Qx_432, .srcType_0 = (string_0_sysvq0asl){
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
      string_0_sysvq0asl* X60Qlhs_69 = (&rfld_0.srcType_0);
      nimStrDestroy((*X60Qlhs_69));
      (*X60Qlhs_69) = pn_1;
      nimStrWasMoved((&pn_1));
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 psa_1 = sizeAlign_1_layptix6a1(pl_0, 8);
      rfld_0.wireSize_0 = psa_1.fld_0;
      NI32 X60Qx_15;
      if (0 < psa_1.fld_1){
        X60Qx_15 = psa_1.fld_1;}
      else {
        X60Qx_15 = 1;}
      rfld_0.wireAlign_0 = X60Qx_15;
      WireField_0_run8hsnpi X60Qtmp_70 = rfld_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&rfld_0));
      result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_70, .fld_1 = NIM_TRUE}
      ;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&rfld_0));
      nimStrDestroy(pn_1);
      eQdestroy_0_nifb6mq6y1((&rc_0));
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&rfld_0));}
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_71 = pl_0;
    eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&pl_0));
    WireField_0_run8hsnpi afld_0 = (WireField_0_run8hsnpi){
      .desc_0 = X60Qtmp_71, .srcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
    ;
    afld_0.isArenaRef_0 = NIM_TRUE;
    afld_0.typeSym_0 = psym_1;
    string_0_sysvq0asl* X60Qlhs_72 = (&afld_0.srcType_0);
    nimStrDestroy((*X60Qlhs_72));
    (*X60Qlhs_72) = pn_1;
    nimStrWasMoved((&pn_1));
    afld_0.wireSize_0 = 8;
    afld_0.wireAlign_0 = 8;
    WireField_0_run8hsnpi X60Qtmp_73 = afld_0;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&afld_0));
    result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_73, .fld_1 = NIM_TRUE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&afld_0));
    nimStrDestroy(pn_1);
    eQdestroy_0_nifb6mq6y1((&rc_0));
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
    nimStrDestroy(srcName_0);
    return result_35;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&afld_0));
    nimStrDestroy(pn_1);
    eQdestroy_0_nifb6mq6y1((&rc_0));
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(pl_0);}
  NB8 X60Qx_433 = isArenaPtrAggregate_0_marbdjk4t1(td_15);
  if (X60Qx_433){
    NB8 X60Qx_434;
    NI32 X60Qx_435 = len_4_sysvq0asl(srcName_0);
    if (X60Qx_435 == 0){
      X60Qx_434 = NIM_TRUE;}
    else {
      X60Qx_434 = (((NU32)esym_0) == ((NU32)0u));}
    if (X60Qx_434){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_436 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I10983318047828523597_run8hsnpi)}
      );
      result_35 = X60Qx_436;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_0 = sizeAlign_1_layptix6a1(td_15, 8);
    if (sa_0.fld_0 <= 0){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_437 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I14209940706925738676_run8hsnpi)}
      );
      result_35 = X60Qx_437;
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
      nimStrDestroy(srcName_0);
      return result_35;}
    X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qtmp_74 = td_15;
    eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&td_15));
    WireField_0_run8hsnpi pf_1 = (WireField_0_run8hsnpi){
      .desc_0 = X60Qtmp_74, .srcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
    ;
    pf_1.isPod_0 = NIM_TRUE;
    pf_1.isArenaPtr_0 = NIM_TRUE;
    string_0_sysvq0asl* X60Qlhs_75 = (&pf_1.srcType_0);
    nimStrDestroy((*X60Qlhs_75));
    (*X60Qlhs_75) = srcName_0;
    nimStrWasMoved((&srcName_0));
    pf_1.typeSym_0 = esym_0;
    pf_1.wireSize_0 = sa_0.fld_0;
    NI32 X60Qx_16;
    if (0 < sa_0.fld_1){
      X60Qx_16 = sa_0.fld_1;}
    else {
      X60Qx_16 = 1;}
    pf_1.wireAlign_0 = X60Qx_16;
    WireField_0_run8hsnpi X60Qtmp_76 = pf_1;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_1));
    result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_76, .fld_1 = NIM_TRUE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_1));
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
    nimStrDestroy(srcName_0);
    return result_35;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&pf_1));}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_438 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
  WireField_0_run8hsnpi f_8 = (WireField_0_run8hsnpi){
    .desc_0 = X60Qx_438, .srcType_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
  ;
  MarshalClass_0_marbdjk4t1 X60Qx_439 = marshalClass_0_marbdjk4t1(td_15);
  switch (X60Qx_439){
    case 0:
    {
      if ((*td_15).d_00.kind_0 == 8){
        NI32 X60Qx_440 = len_4_sysvq0asl(srcName_0);
        if (X60Qx_440 == 0){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_441 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1869505022u, .more_0 = (&strlit_0_I10048895548644967963_run8hsnpi)}
          );
          result_35 = X60Qx_441;
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
          nimStrDestroy(srcName_0);
          return result_35;}
        f_8.isEnum_0 = NIM_TRUE;
        string_0_sysvq0asl* X60Qlhs_77 = (&f_8.srcType_0);
        nimStrDestroy((*X60Qlhs_77));
        (*X60Qlhs_77) = srcName_0;
        nimStrWasMoved((&srcName_0));
        f_8.enumSym_0 = esym_0;
        f_8.wireSize_0 = 4;
        f_8.wireAlign_0 = 4;}
      else {
        X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_1 = sizeAlign_1_layptix6a1(td_15, 8);
        f_8.wireSize_0 = sa_1.fld_0;
        NI32 X60Qx_17;
        if (0 < sa_1.fld_1){
          X60Qx_17 = sa_1.fld_1;}
        else {
          X60Qx_17 = 1;}
        f_8.wireAlign_0 = X60Qx_17;
        string_0_sysvq0asl X60Qx_18;
        nimStrWasMoved((&X60Qx_18));
        NI32 X60Qx_442 = len_4_sysvq0asl(srcName_0);
        if (0 < X60Qx_442){
          nimStrDestroy(X60Qx_18);
          X60Qx_18 = srcName_0;
          nimStrWasMoved((&srcName_0));}
        else {
          nimStrDestroy(X60Qx_18);
          string_0_sysvq0asl X60Qx_443 = srcScalarName_0_run8hsnpi(td_15);
          X60Qx_18 = X60Qx_443;}
        string_0_sysvq0asl* X60Qlhs_78 = (&f_8.srcType_0);
        nimStrDestroy((*X60Qlhs_78));
        (*X60Qlhs_78) = X60Qx_18;
        nimStrWasMoved((&X60Qx_18));
        NI32 X60Qx_444 = len_4_sysvq0asl(f_8.srcType_0);
        if (X60Qx_444 == 0){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_445 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1633907710u, .more_0 = (&strlit_0_I11975016787032525042_run8hsnpi)}
          );
          result_35 = X60Qx_445;
          nimStrDestroy(X60Qx_18);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
          nimStrDestroy(srcName_0);
          return result_35;}
        nimStrDestroy(X60Qx_18);}
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_35));
      WireField_0_run8hsnpi X60Qtmp_79 = f_8;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
      result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_79, .fld_1 = NIM_TRUE}
      ;}
    break;
    case 1:
    {
      NB8 X60Qx_446 = podHasEnumOrArray_0_run8hsnpi(td_15);
      if (X60Qx_446){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_447 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1146048766u, .more_0 = (&strlit_0_I2580450898984919640_run8hsnpi)}
        );
        result_35 = X60Qx_447;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
        nimStrDestroy(srcName_0);
        return result_35;}
      string_0_sysvq0asl sname_0 = srcName_0;
      nimStrWasMoved((&srcName_0));
      NI32 X60Qx_448 = len_4_sysvq0asl(sname_0);
      if (X60Qx_448 == 0){
        if ((*td_15).d_00.kind_0 == 11){
          string_0_sysvq0asl s_8 = (string_0_sysvq0asl){
            .bytes_0 = 10241u, .more_0 = NIM_NIL}
          ;
          NI32 i_3 = 0;
          NB8 okAll_0 = NIM_TRUE;
          {
            while (NIM_TRUE){
              NI32 X60Qx_449 = len_3_I5m68tr1_aow7lb5cq1((*td_15).d_00.fields_0);
              if (i_3 < X60Qx_449){
                if (0 < i_3){
                  add_2_sysvq0asl((&s_8), (string_0_sysvq0asl){
                    .bytes_0 = 2108418u, .more_0 = NIM_NIL}
                  );}
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_450 = getQ_7_I45w7c91_aow7lb5cq1((*td_15).d_00.fields_0, i_3);
                string_0_sysvq0asl n_6 = srcScalarName_0_run8hsnpi((*X60Qx_450));
                NI32 X60Qx_451 = len_4_sysvq0asl(n_6);
                if (X60Qx_451 == 0){
                  okAll_0 = NIM_FALSE;
                  nimStrDestroy(n_6);
                  goto whileStmtLabel_1;}
                add_2_sysvq0asl((&s_8), n_6);
                inc_1_I6wjjge_aow2h993l1((&i_3));
                nimStrDestroy(n_6);}
              else {
                break;}}}
          whileStmtLabel_1: ;
          NB8 X60Qx_452;
          if (okAll_0){
            X60Qx_452 = (0 < (*td_15).d_00.fields_0.len_0);}
          else {
            X60Qx_452 = NIM_FALSE;}
          if (X60Qx_452){
            add_2_sysvq0asl((&s_8), (string_0_sysvq0asl){
              .bytes_0 = 10497u, .more_0 = NIM_NIL}
            );
            nimStrDestroy(sname_0);
            sname_0 = s_8;
            nimStrWasMoved((&s_8));}
          nimStrDestroy(s_8);}
        NI32 X60Qx_453 = len_4_sysvq0asl(sname_0);
        if (X60Qx_453 == 0){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_454 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1869505022u, .more_0 = (&strlit_0_I4239904353946109281_run8hsnpi)}
          );
          result_35 = X60Qx_454;
          nimStrDestroy(sname_0);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
          nimStrDestroy(srcName_0);
          return result_35;}}
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 sa_2 = sizeAlign_1_layptix6a1(td_15, 8);
      f_8.isPod_0 = NIM_TRUE;
      string_0_sysvq0asl* X60Qlhs_80 = (&f_8.srcType_0);
      nimStrDestroy((*X60Qlhs_80));
      (*X60Qlhs_80) = sname_0;
      nimStrWasMoved((&sname_0));
      f_8.typeSym_0 = esym_0;
      f_8.wireSize_0 = sa_2.fld_0;
      NI32 X60Qx_19;
      if (0 < sa_2.fld_1){
        X60Qx_19 = sa_2.fld_1;}
      else {
        X60Qx_19 = 1;}
      f_8.wireAlign_0 = X60Qx_19;
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_35));
      WireField_0_run8hsnpi X60Qtmp_81 = f_8;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
      result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_81, .fld_1 = NIM_TRUE}
      ;
      nimStrDestroy(sname_0);}
    break;
    case 2:
    {
      f_8.isString_0 = NIM_TRUE;
      string_0_sysvq0asl* X60Qlhs_82 = (&f_8.srcType_0);
      nimStrDestroy((*X60Qlhs_82));
      (*X60Qlhs_82) = (string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
      ;
      f_8.wireSize_0 = 0;
      f_8.wireAlign_0 = 8;
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_35));
      WireField_0_run8hsnpi X60Qtmp_83 = f_8;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
      result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_83, .fld_1 = NIM_TRUE}
      ;}
    break;
    case 3:
    {
      X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_3 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*td_15).d_00.elem_0);
      if (el_3 == NIM_NIL){
        X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_455 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I4762276063258106479_run8hsnpi)}
        );
        result_35 = X60Qx_455;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
        nimStrDestroy(srcName_0);
        return result_35;}
      MarshalClass_0_marbdjk4t1 ec_4 = marshalClass_0_marbdjk4t1(el_3);
      NB8 X60Qx_456;
      if (ec_4 == 0){
        X60Qx_456 = NIM_TRUE;}
      else {
        X60Qx_456 = (ec_4 == 1);}
      if (X60Qx_456){
        NB8 X60Qx_457;
        if (ec_4 == 1){
          NB8 X60Qx_458 = podHasEnumOrArray_0_run8hsnpi(el_3);
          X60Qx_457 = X60Qx_458;}
        else {
          X60Qx_457 = NIM_FALSE;}
        if (X60Qx_457){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_459 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I17656025713398431513_run8hsnpi)}
          );
          result_35 = X60Qx_459;
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
          nimStrDestroy(srcName_0);
          return result_35;}
        X60Qt_0_IAtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_run8hsnpi X60Qtmptup_5 = seqElemNameSym_0_run8hsnpi(cur_6, el_3);
        string_0_sysvq0asl en_1 = X60Qtmptup_5.fld_0;
        nimStrWasMoved((&X60Qtmptup_5.fld_0));
        NU32 ets_1 = X60Qtmptup_5.fld_1;
        NI32 X60Qx_460 = len_4_sysvq0asl(en_1);
        if (X60Qx_460 == 0){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_461 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I18020228616198309266_run8hsnpi)}
          );
          result_35 = X60Qx_461;
          nimStrDestroy(en_1);
          eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_5);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
          nimStrDestroy(srcName_0);
          return result_35;}
        NB8 X60Qx_462;
        if (ec_4 == 1){
          X60Qx_462 = (((NU32)ets_1) == ((NU32)0u));}
        else {
          X60Qx_462 = NIM_FALSE;}
        if (X60Qx_462){
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_463 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I8778022564813250551_run8hsnpi)}
          );
          result_35 = X60Qx_463;
          nimStrDestroy(en_1);
          eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_5);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
          nimStrDestroy(srcName_0);
          return result_35;}
        X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 esa_1 = sizeAlign_1_layptix6a1(el_3, 8);
        f_8.elemTypeSym_0 = ets_1;
        f_8.isSeq_0 = NIM_TRUE;
        NI32 X60Qx_464 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
        );
        NI32 X60Qx_465 = len_4_sysvq0asl(en_1);
        NI32 X60Qx_466 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 23809u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl X60Qdesugar_9 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_464 + X60Qx_465)) + X60Qx_466)));
        add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
          .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
        );
        add_2_sysvq0asl((&X60Qdesugar_9), en_1);
        add_2_sysvq0asl((&X60Qdesugar_9), (string_0_sysvq0asl){
          .bytes_0 = 23809u, .more_0 = NIM_NIL}
        );
        string_0_sysvq0asl* X60Qlhs_84 = (&f_8.srcType_0);
        nimStrDestroy((*X60Qlhs_84));
        (*X60Qlhs_84) = X60Qdesugar_9;
        nimStrWasMoved((&X60Qdesugar_9));
        string_0_sysvq0asl* X60Qlhs_85 = (&f_8.elemSrcType_0);
        nimStrDestroy((*X60Qlhs_85));
        (*X60Qlhs_85) = en_1;
        nimStrWasMoved((&en_1));
        f_8.elemSize_0 = esa_1.fld_0;
        NI32 X60Qx_20;
        if (0 < esa_1.fld_1){
          X60Qx_20 = esa_1.fld_1;}
        else {
          X60Qx_20 = 1;}
        NI32 X60Qx_467 = align_0_layptix6a1(esa_1.fld_0, X60Qx_20);
        f_8.elemStride_0 = X60Qx_467;
        f_8.wireSize_0 = 0;
        f_8.wireAlign_0 = 8;
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_35));
        WireField_0_run8hsnpi X60Qtmp_86 = f_8;
        eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
          .fld_0 = X60Qtmp_86, .fld_1 = NIM_TRUE}
        ;
        nimStrDestroy(X60Qdesugar_9);
        nimStrDestroy(en_1);
        eQdestroyQ_AtupleSstring0sysvq0aslSX53ymX49d0nifh7u8pu1_0_run8hsnpi(X60Qtmptup_5);}
      else {
        NB8 X60Qx_468;
        if (ec_4 == 2){
          X60Qx_468 = NIM_TRUE;}
        else {
          X60Qx_468 = (ec_4 == 3);}
        if (X60Qx_468){
          X60Qt_0_IAtupleSX43ursor0nifb6mq6y1Abool_run8hsnpi X60Qtmptup_6 = seqElemCursor_0_run8hsnpi(cur_6);
          Cursor_0_nifb6mq6y1 ecur_0 = X60Qtmptup_6.fld_0;
          eQwasMoved_0_nifb6mq6y1((&X60Qtmptup_6.fld_0));
          NB8 cok_0 = X60Qtmptup_6.fld_1;
          if ((!cok_0)){
            string_0_sysvq0asl X60Qtmp_88 = blockerReason_0_croph25r5();
            string_0_sysvq0asl X60Qtmp_87 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I2962236368520039866_run8hsnpi)}
            , X60Qtmp_88);
            X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_469 = declineWire_0_run8hsnpi(X60Qtmp_87);
            result_35 = X60Qx_469;
            nimStrDestroy(X60Qtmp_87);
            nimStrDestroy(X60Qtmp_88);
            eQdestroy_0_nifb6mq6y1((&ecur_0));
            eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_6);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
            nimStrDestroy(srcName_0);
            return result_35;
            nimStrDestroy(X60Qtmp_87);
            nimStrDestroy(X60Qtmp_88);}
          X60Qt_0_IAtupleSstring0sysvq0aslAbool_dbg4n0xd21 X60Qtmptup_7 = varElemExpr_0_run8hsnpi(ecur_0, el_3);
          string_0_sysvq0asl expr_0 = X60Qtmptup_7.fld_0;
          nimStrWasMoved((&X60Qtmptup_7.fld_0));
          NB8 eok_0 = X60Qtmptup_7.fld_1;
          if ((!eok_0)){
            string_0_sysvq0asl X60Qtmp_90 = blockerReason_0_croph25r5();
            string_0_sysvq0asl X60Qtmp_89 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I2962236368520039866_run8hsnpi)}
            , X60Qtmp_90);
            X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_470 = declineWire_0_run8hsnpi(X60Qtmp_89);
            result_35 = X60Qx_470;
            nimStrDestroy(X60Qtmp_89);
            nimStrDestroy(X60Qtmp_90);
            nimStrDestroy(expr_0);
            eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_7);
            eQdestroy_0_nifb6mq6y1((&ecur_0));
            eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_6);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
            nimStrDestroy(srcName_0);
            return result_35;
            nimStrDestroy(X60Qtmp_89);
            nimStrDestroy(X60Qtmp_90);}
          f_8.isSeq_0 = NIM_TRUE;
          f_8.elemVarLen_0 = NIM_TRUE;
          NI32 X60Qx_471 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
          );
          NI32 X60Qx_472 = len_4_sysvq0asl(expr_0);
          NI32 X60Qx_473 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_10 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_471 + X60Qx_472)) + X60Qx_473)));
          add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I1742168074744315372_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_10), expr_0);
          add_2_sysvq0asl((&X60Qdesugar_10), (string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl* X60Qlhs_91 = (&f_8.srcType_0);
          nimStrDestroy((*X60Qlhs_91));
          (*X60Qlhs_91) = X60Qdesugar_10;
          nimStrWasMoved((&X60Qdesugar_10));
          string_0_sysvq0asl* X60Qlhs_92 = (&f_8.elemSrcType_0);
          nimStrDestroy((*X60Qlhs_92));
          (*X60Qlhs_92) = expr_0;
          nimStrWasMoved((&expr_0));
          string_0_sysvq0asl* X60Qlhs_93 = (&f_8.elemLeafName_0);
          nimStrDestroy((*X60Qlhs_93));
          string_0_sysvq0asl X60Qx_474 = leafScalarName_0_run8hsnpi(el_3);
          (*X60Qlhs_93) = X60Qx_474;
          f_8.wireSize_0 = 0;
          f_8.wireAlign_0 = 8;
          eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_35));
          WireField_0_run8hsnpi X60Qtmp_94 = f_8;
          eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
            .fld_0 = X60Qtmp_94, .fld_1 = NIM_TRUE}
          ;
          nimStrDestroy(X60Qdesugar_10);
          nimStrDestroy(expr_0);
          eQdestroyQ_AtupleSstring0sysvq0aslAbool_0_run8hsnpi(X60Qtmptup_7);
          eQdestroy_0_nifb6mq6y1((&ecur_0));
          eQdestroyQ_AtupleSX43ursor0nifb6mq6y1Abool_0_run8hsnpi(X60Qtmptup_6);}
        else {
          string_0_sysvq0asl X60Qdesugar_11 = abiKindName_0_run8hsnpi(el_3);
          string_0_sysvq0asl X60Qdesugar_12 = marshalClassName_0_run8hsnpi(el_3);
          NI32 X60Qx_475 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I95191463816654317_run8hsnpi)}
          );
          NI32 X60Qx_476 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I2511330594188339324_run8hsnpi)}
          );
          NI32 X60Qx_477 = len_4_sysvq0asl(X60Qdesugar_11);
          NI32 X60Qx_478 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 12033u, .more_0 = NIM_NIL}
          );
          NI32 X60Qx_479 = len_4_sysvq0asl(X60Qdesugar_12);
          NI32 X60Qx_480 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          string_0_sysvq0asl X60Qdesugar_13 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_475 + X60Qx_476)) + X60Qx_477)) + X60Qx_478)) + X60Qx_479)) + X60Qx_480)));
          add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
            .bytes_0 = 1902474238u, .more_0 = (&strlit_0_I95191463816654317_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
            .bytes_0 = 1700471038u, .more_0 = (&strlit_0_I2511330594188339324_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_13), X60Qdesugar_11);
          add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
            .bytes_0 = 12033u, .more_0 = NIM_NIL}
          );
          add_2_sysvq0asl((&X60Qdesugar_13), X60Qdesugar_12);
          add_2_sysvq0asl((&X60Qdesugar_13), (string_0_sysvq0asl){
            .bytes_0 = 23809u, .more_0 = NIM_NIL}
          );
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_481 = declineWire_0_run8hsnpi(X60Qdesugar_13);
          result_35 = X60Qx_481;
          nimStrDestroy(X60Qdesugar_13);
          nimStrDestroy(X60Qdesugar_12);
          nimStrDestroy(X60Qdesugar_11);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
          nimStrDestroy(srcName_0);
          return result_35;
          nimStrDestroy(X60Qdesugar_13);
          nimStrDestroy(X60Qdesugar_12);
          nimStrDestroy(X60Qdesugar_11);}}
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(el_3);}
    break;
    default:
    {
      NB8 X60Qx_482;
      NB8 X60Qx_483;
      NB8 X60Qx_484;
      NB8 X60Qx_485;
      if ((*td_15).d_00.kind_0 == 10){
        X60Qx_485 = NIM_TRUE;}
      else {
        X60Qx_485 = ((*td_15).d_00.kind_0 == 11);}
      if (X60Qx_485){
        X60Qx_484 = (!(*td_15).d_00.incomplete_0);}
      else {
        X60Qx_484 = NIM_FALSE;}
      if (X60Qx_484){
        X60Qx_483 = (!(*td_15).d_00.union_0);}
      else {
        X60Qx_483 = NIM_FALSE;}
      if (X60Qx_483){
        NB8 X60Qx_486 = compositeOk_0_run8hsnpi(td_15, 0);
        X60Qx_482 = X60Qx_486;}
      else {
        X60Qx_482 = NIM_FALSE;}
      if (X60Qx_482){
        NB8 X60Qx_487;
        NB8 X60Qx_488 = eqQ_0_nifh7u8pu1(esym_0, ((NU32)0u));
        if (X60Qx_488){
          X60Qx_487 = ((*td_15).d_00.kind_0 == 10);}
        else {
          X60Qx_487 = NIM_FALSE;}
        if (X60Qx_487){
          NI32 X60Qx_489 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1851876350u, .more_0 = (&strlit_0_I3480347692445760496_run8hsnpi)}
          );
          NI32 X60Qx_490 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1970234366u, .more_0 = (&strlit_0_I8515203893767693394_run8hsnpi)}
          );
          NI32 X60Qx_491 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1869117438u, .more_0 = (&strlit_0_I4435949299172777945_run8hsnpi)}
          );
          NI32 X60Qx_492 = len_4_sysvq0asl((string_0_sysvq0asl){
            .bytes_0 = 1802071294u, .more_0 = (&strlit_0_I9019415731558934837_run8hsnpi)}
          );
          string_0_sysvq0asl X60Qdesugar_14 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_489 + X60Qx_490)) + X60Qx_491)) + X60Qx_492)));
          add_2_sysvq0asl((&X60Qdesugar_14), (string_0_sysvq0asl){
            .bytes_0 = 1851876350u, .more_0 = (&strlit_0_I3480347692445760496_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_14), (string_0_sysvq0asl){
            .bytes_0 = 1970234366u, .more_0 = (&strlit_0_I8515203893767693394_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_14), (string_0_sysvq0asl){
            .bytes_0 = 1869117438u, .more_0 = (&strlit_0_I4435949299172777945_run8hsnpi)}
          );
          add_2_sysvq0asl((&X60Qdesugar_14), (string_0_sysvq0asl){
            .bytes_0 = 1802071294u, .more_0 = (&strlit_0_I9019415731558934837_run8hsnpi)}
          );
          X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_493 = declineWire_0_run8hsnpi(X60Qdesugar_14);
          result_35 = X60Qx_493;
          nimStrDestroy(X60Qdesugar_14);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
          nimStrDestroy(srcName_0);
          return result_35;
          nimStrDestroy(X60Qdesugar_14);}
        f_8.isComposite_0 = NIM_TRUE;
        string_0_sysvq0asl X60Qx_21;
        nimStrWasMoved((&X60Qx_21));
        NI32 X60Qx_494 = len_4_sysvq0asl(srcName_0);
        if (0 < X60Qx_494){
          nimStrDestroy(X60Qx_21);
          X60Qx_21 = srcName_0;
          nimStrWasMoved((&srcName_0));}
        else {
          nimStrDestroy(X60Qx_21);
          X60Qx_21 = (string_0_sysvq0asl){
            .bytes_0 = 1734425854u, .more_0 = (&strlit_0_I15413645776922620897_run8hsnpi)}
          ;}
        string_0_sysvq0asl* X60Qlhs_95 = (&f_8.srcType_0);
        nimStrDestroy((*X60Qlhs_95));
        (*X60Qlhs_95) = X60Qx_21;
        nimStrWasMoved((&X60Qx_21));
        f_8.typeSym_0 = esym_0;
        f_8.wireSize_0 = 0;
        f_8.wireAlign_0 = 8;
        WireField_0_run8hsnpi X60Qtmp_96 = f_8;
        eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        result_35 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
          .fld_0 = X60Qtmp_96, .fld_1 = NIM_TRUE}
        ;
        nimStrDestroy(X60Qx_21);
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
        nimStrDestroy(srcName_0);
        return result_35;
        nimStrDestroy(X60Qx_21);}
      string_0_sysvq0asl X60Qx_22;
      nimStrWasMoved((&X60Qx_22));
      NI32 X60Qx_495 = len_4_sysvq0asl(srcName_0);
      if (0 < X60Qx_495){
        nimStrDestroy(X60Qx_22);
        X60Qx_22 = srcName_0;
        nimStrWasMoved((&srcName_0));}
      else {
        nimStrDestroy(X60Qx_22);
        X60Qx_22 = (string_0_sysvq0asl){
          .bytes_0 = 1851866366u, .more_0 = (&strlit_0_I409803864855967452_obs4v9ato1)}
        ;}
      string_0_sysvq0asl X60Qdesugar_15 = X60Qx_22;
      nimStrWasMoved((&X60Qx_22));
      string_0_sysvq0asl X60Qdesugar_16 = abiKindName_0_run8hsnpi(td_15);
      string_0_sysvq0asl X60Qdesugar_17 = marshalClassName_0_run8hsnpi(td_15);
      string_0_sysvq0asl X60Qx_23;
      nimStrWasMoved((&X60Qx_23));
      NB8 X60Qx_496;
      if ((*td_15).d_00.kind_0 == 10){
        X60Qx_496 = NIM_TRUE;}
      else {
        X60Qx_496 = ((*td_15).d_00.kind_0 == 11);}
      if (X60Qx_496){
        nimStrDestroy(X60Qx_23);
        string_0_sysvq0asl X60Qx_497 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I16798826875811747463_run8hsnpi)}
        , (string_0_sysvq0asl){
          .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I5244465630440985265_run8hsnpi)}
        );
        X60Qx_23 = X60Qx_497;}
      else {
        if ((*td_15).d_00.kind_0 == 6){
          nimStrDestroy(X60Qx_23);
          X60Qx_23 = (string_0_sysvq0asl){
            .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I14538563795054532983_run8hsnpi)}
          ;}
        else {
          if ((*td_15).d_00.kind_0 == 7){
            nimStrDestroy(X60Qx_23);
            X60Qx_23 = (string_0_sysvq0asl){
              .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I7336782688302392152_run8hsnpi)}
            ;}
          else {
            nimStrDestroy(X60Qx_23);
            X60Qx_23 = (string_0_sysvq0asl){
              .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I9738203171686931162_run8hsnpi)}
            ;}}}
      string_0_sysvq0asl X60Qdesugar_18 = X60Qx_23;
      nimStrWasMoved((&X60Qx_23));
      NI32 X60Qx_498 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1851876350u, .more_0 = (&strlit_0_I7830412320232756549_run8hsnpi)}
      );
      NI32 X60Qx_499 = len_4_sysvq0asl(X60Qdesugar_15);
      NI32 X60Qx_500 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1936269566u, .more_0 = (&strlit_0_I15938467040282102084_run8hsnpi)}
      );
      NI32 X60Qx_501 = len_4_sysvq0asl(X60Qdesugar_16);
      NI32 X60Qx_502 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 12033u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_503 = len_4_sysvq0asl(X60Qdesugar_17);
      NI32 X60Qx_504 = len_4_sysvq0asl(X60Qdesugar_18);
      string_0_sysvq0asl X60Qdesugar_19 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_498 + X60Qx_499)) + X60Qx_500)) + X60Qx_501)) + X60Qx_502)) + X60Qx_503)) + X60Qx_504)));
      add_2_sysvq0asl((&X60Qdesugar_19), (string_0_sysvq0asl){
        .bytes_0 = 1851876350u, .more_0 = (&strlit_0_I7830412320232756549_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_19), X60Qdesugar_15);
      add_2_sysvq0asl((&X60Qdesugar_19), (string_0_sysvq0asl){
        .bytes_0 = 1936269566u, .more_0 = (&strlit_0_I15938467040282102084_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_19), X60Qdesugar_16);
      add_2_sysvq0asl((&X60Qdesugar_19), (string_0_sysvq0asl){
        .bytes_0 = 12033u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_19), X60Qdesugar_17);
      add_2_sysvq0asl((&X60Qdesugar_19), X60Qdesugar_18);
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_35));
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_505 = declineWire_0_run8hsnpi(X60Qdesugar_19);
      result_35 = X60Qx_505;
      nimStrDestroy(X60Qdesugar_19);
      nimStrDestroy(X60Qdesugar_18);
      nimStrDestroy(X60Qx_23);
      nimStrDestroy(X60Qdesugar_17);
      nimStrDestroy(X60Qdesugar_16);
      nimStrDestroy(X60Qdesugar_15);
      nimStrDestroy(X60Qx_22);}
    break;}
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
  nimStrDestroy(srcName_0);
  return result_35;
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_8));
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_15);
  nimStrDestroy(srcName_0);
  return result_35;}
NB8 arrayWritebackSafe_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* el_0){
  NB8 result_36;
  if (el_0 == NIM_NIL){
    return NIM_FALSE;}
  switch ((*el_0).d_00.kind_0){
    case 0:
    case 1:
    case 2:
    case 4:
    case 3:
    {
      result_36 = NIM_TRUE;}
    break;
    case 13:
    {
      NB8 X60Qx_506 = arrayWritebackSafe_0_run8hsnpi((*el_0).d_00.elem_0);
      result_36 = X60Qx_506;}
    break;
    default:
    {
      result_36 = NIM_FALSE;}
    break;}
  return result_36;}
X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi describeType_0_run8hsnpi(Cursor_0_nifb6mq6y1 cur_7){
  X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi result_37;
  eQwasmovedQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_37));
  Cursor_0_nifb6mq6y1 c_2 = eQdup_0_nifb6mq6y1(cur_7);
  NB8 wantVar_0 = NIM_FALSE;
  NB8 wantSink_0 = NIM_FALSE;
  NB8 X60Qx_114;
  NifKind_0_nif81dubp1 X60Qx_507 = kind_0_nifb6mq6y1(c_2);
  if (X60Qx_507 == 11){
    NB8 X60Qx_115;
    string_0_sysvq0asl X60Qtmp_97 = nodeTag_0_run8hsnpi(c_2);
    NB8 X60Qx_508 = eqQ_20_sysvq0asl(X60Qtmp_97, (string_0_sysvq0asl){
      .bytes_0 = 1953852675u, .more_0 = NIM_NIL}
    );
    if (X60Qx_508){
      X60Qx_115 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_98 = nodeTag_0_run8hsnpi(c_2);
      NB8 X60Qx_509 = eqQ_20_sysvq0asl(X60Qtmp_98, (string_0_sysvq0asl){
        .bytes_0 = 1953853187u, .more_0 = NIM_NIL}
      );
      X60Qx_115 = X60Qx_509;
      nimStrDestroy(X60Qtmp_98);}
    X60Qx_114 = X60Qx_115;
    nimStrDestroy(X60Qtmp_97);}
  else {
    X60Qx_114 = NIM_FALSE;}
  if (X60Qx_114){
    wantVar_0 = NIM_TRUE;
    inc_0_nifb6mq6y1((&c_2));}
  else {
    NB8 X60Qx_116;
    NifKind_0_nif81dubp1 X60Qx_510 = kind_0_nifb6mq6y1(c_2);
    if (X60Qx_510 == 11){
      string_0_sysvq0asl X60Qtmp_99 = nodeTag_0_run8hsnpi(c_2);
      NB8 X60Qx_511 = eqQ_20_sysvq0asl(X60Qtmp_99, (string_0_sysvq0asl){
        .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I5595596763809202512_nim30udrv)}
      );
      X60Qx_116 = X60Qx_511;
      nimStrDestroy(X60Qtmp_99);}
    else {
      X60Qx_116 = NIM_FALSE;}
    if (X60Qx_116){
      wantSink_0 = NIM_TRUE;}}
  X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qtmptup_8 = describeTypeCore_0_run8hsnpi(c_2);
  WireField_0_run8hsnpi f_9 = X60Qtmptup_8.fld_0;
  eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60Qtmptup_8.fld_0));
  NB8 ok_3 = X60Qtmptup_8.fld_1;
  if ((!ok_3)){
    WireField_0_run8hsnpi X60Qtmp_100 = f_9;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    result_37 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_100, .fld_1 = NIM_FALSE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_37;}
  if ((!wantVar_0)){
    if (wantSink_0){
      WireField_0_run8hsnpi fs_0 = f_9;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
      fs_0.isSink_0 = NIM_TRUE;
      WireField_0_run8hsnpi X60Qtmp_101 = fs_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fs_0));
      result_37 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
        .fld_0 = X60Qtmp_101, .fld_1 = NIM_TRUE}
      ;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fs_0));
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
      eQdestroy_0_nifb6mq6y1((&c_2));
      return result_37;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fs_0));}
    WireField_0_run8hsnpi X60Qtmp_102 = f_9;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    result_37 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_102, .fld_1 = NIM_TRUE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_37;}
  if (f_9.isForeignPtr_0){
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_512 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I7431751303130250076_run8hsnpi)}
    );
    result_37 = X60Qx_512;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_37;}
  if (f_9.isPtrArena_0){
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_513 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I275891954373591862_run8hsnpi)}
    );
    result_37 = X60Qx_513;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_37;}
  NB8 X60Qx_514;
  NB8 X60Qx_515;
  NB8 X60Qx_516;
  NB8 X60Qx_517;
  NB8 X60Qx_518;
  if ((!f_9.isString_0)){
    X60Qx_518 = (!f_9.isSeq_0);}
  else {
    X60Qx_518 = NIM_FALSE;}
  if (X60Qx_518){
    X60Qx_517 = (!f_9.isArray_0);}
  else {
    X60Qx_517 = NIM_FALSE;}
  if (X60Qx_517){
    X60Qx_516 = (!f_9.isEnum_0);}
  else {
    X60Qx_516 = NIM_FALSE;}
  if (X60Qx_516){
    X60Qx_515 = (!f_9.isPod_0);}
  else {
    X60Qx_515 = NIM_FALSE;}
  if (X60Qx_515){
    X60Qx_514 = (0 < f_9.wireSize_0);}
  else {
    X60Qx_514 = NIM_FALSE;}
  NB8 scalarLeaf_0 = X60Qx_514;
  if (f_9.isArray_0){
    NB8 X60Qx_519;
    if (f_9.desc_0 == NIM_NIL){
      X60Qx_519 = NIM_TRUE;}
    else {
      NB8 X60Qx_520 = arrayWritebackSafe_0_run8hsnpi((*f_9.desc_0).d_00.elem_0);
      X60Qx_519 = (!X60Qx_520);}
    if (X60Qx_519){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_521 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I138105002306121085_run8hsnpi)}
      );
      result_37 = X60Qx_521;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
      eQdestroy_0_nifb6mq6y1((&c_2));
      return result_37;}
    NB8 X60Qx_522;
    NB8 X60Qx_523;
    NB8 X60Qx_524;
    if (f_9.arrCount_0 <= 0){
      X60Qx_524 = NIM_TRUE;}
    else {
      X60Qx_524 = (f_9.elemSize_0 <= 0);}
    if (X60Qx_524){
      X60Qx_523 = NIM_TRUE;}
    else {
      X60Qx_523 = (f_9.elemStride_0 < f_9.elemSize_0);}
    if (X60Qx_523){
      X60Qx_522 = NIM_TRUE;}
    else {
      X60Qx_522 = (f_9.wireSize_0 <= 0);}
    if (X60Qx_522){
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_525 = declineWire_0_run8hsnpi((string_0_sysvq0asl){
        .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I4823751142713875849_run8hsnpi)}
      );
      result_37 = X60Qx_525;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
      eQdestroy_0_nifb6mq6y1((&c_2));
      return result_37;}
    WireField_0_run8hsnpi fa_0 = f_9;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    fa_0.isVar_0 = NIM_TRUE;
    WireField_0_run8hsnpi X60Qtmp_103 = fa_0;
    eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fa_0));
    result_37 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
      .fld_0 = X60Qtmp_103, .fld_1 = NIM_TRUE}
    ;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fa_0));
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_37;
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&fa_0));}
  NB8 X60Qx_526;
  if (f_9.isPod_0){
    X60Qx_526 = NIM_TRUE;}
  else {
    X60Qx_526 = scalarLeaf_0;}
  if ((!X60Qx_526)){
    string_0_sysvq0asl X60Qx_24;
    nimStrWasMoved((&X60Qx_24));
    if (f_9.isString_0){
      nimStrDestroy(X60Qx_24);
      X60Qx_24 = (string_0_sysvq0asl){
        .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_aow7lb5cq1)}
      ;}
    else {
      string_0_sysvq0asl X60Qx_25;
      nimStrWasMoved((&X60Qx_25));
      if (f_9.isSeq_0){
        nimStrDestroy(X60Qx_25);
        X60Qx_25 = (string_0_sysvq0asl){
          .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
        ;}
      else {
        string_0_sysvq0asl X60Qx_26;
        nimStrWasMoved((&X60Qx_26));
        if (f_9.isEnum_0){
          nimStrDestroy(X60Qx_26);
          X60Qx_26 = (string_0_sysvq0asl){
            .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_aow7lb5cq1)}
          ;}
        else {
          nimStrDestroy(X60Qx_26);
          X60Qx_26 = (string_0_sysvq0asl){
            .bytes_0 = 1847615998u, .more_0 = (&strlit_0_I11949153613191379336_run8hsnpi)}
          ;}
        nimStrDestroy(X60Qx_25);
        X60Qx_25 = X60Qx_26;
        nimStrWasMoved((&X60Qx_26));
        nimStrDestroy(X60Qx_26);}
      nimStrDestroy(X60Qx_24);
      X60Qx_24 = X60Qx_25;
      nimStrWasMoved((&X60Qx_25));
      nimStrDestroy(X60Qx_25);}
    string_0_sysvq0asl X60Qdesugar_20 = X60Qx_24;
    nimStrWasMoved((&X60Qx_24));
    NI32 X60Qx_527 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I12459124382821890348_run8hsnpi)}
    );
    NI32 X60Qx_528 = len_4_sysvq0asl(X60Qdesugar_20);
    NI32 X60Qx_529 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I14049035126231656660_run8hsnpi)}
    );
    string_0_sysvq0asl X60Qdesugar_21 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_527 + X60Qx_528)) + X60Qx_529)));
    add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I12459124382821890348_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_21), X60Qdesugar_20);
    add_2_sysvq0asl((&X60Qdesugar_21), (string_0_sysvq0asl){
      .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I14049035126231656660_run8hsnpi)}
    );
    X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qx_530 = declineWire_0_run8hsnpi(X60Qdesugar_21);
    result_37 = X60Qx_530;
    nimStrDestroy(X60Qdesugar_21);
    nimStrDestroy(X60Qdesugar_20);
    nimStrDestroy(X60Qx_24);
    eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
    eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
    eQdestroy_0_nifb6mq6y1((&c_2));
    return result_37;
    nimStrDestroy(X60Qdesugar_21);
    nimStrDestroy(X60Qdesugar_20);
    nimStrDestroy(X60Qx_24);}
  WireField_0_run8hsnpi f2_0 = f_9;
  eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
  f2_0.isVar_0 = NIM_TRUE;
  eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&result_37));
  WireField_0_run8hsnpi X60Qtmp_104 = f2_0;
  eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f2_0));
  result_37 = (X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi){
    .fld_0 = X60Qtmp_104, .fld_1 = NIM_TRUE}
  ;
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f2_0));
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
  eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
  eQdestroy_0_nifb6mq6y1((&c_2));
  return result_37;
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f2_0));
  eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_9));
  eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_8));
  eQdestroy_0_nifb6mq6y1((&c_2));
  return result_37;}
string_0_sysvq0asl shimNameFor_0_run8hsnpi(NU32 sym_8){
  string_0_sysvq0asl result_38;
  nimStrWasMoved((&result_38));
  NU64 h_0 = ((NU64)14695981039346656037ull);
  {
    string_0_sysvq0asl* X60Qx_531 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_8);
    string_0_sysvq0asl X60QconstRefTemp_0 = (*X60Qx_531);
    openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_8 = toOpenArray_2_sysvq0asl((&X60QconstRefTemp_0));
    NI32 X60Qlf_9 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_532 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_8);
        if (X60Qlf_9 < X60Qx_532){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_8, X60Qlf_9);
            h_0 = ((NU64)(h_0 ^ ((NU64)((NU8)(*X60Qii_2)))));
            h_0 = ((NU64)(h_0 * ((NU64)1099511628211ull)));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  string_0_sysvq0asl s_9 = (string_0_sysvq0asl){
    .bytes_0 = 2003788286u, .more_0 = (&strlit_0_I4209738878907651049_run8hsnpi)}
  ;
  NI32 i_4 = 60;
  {
    while (0 <= i_4){
      NC8 X60Qx_533 = getQ_9_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 842084606u, .more_0 = (&strlit_0_I6105018409752412263_dbg4n0xd21)}
      , ((NI32)((NU64)(((NU64)(h_0 >> ((NU32)i_4))) & ((NU64)15u)))));
      add_1_sysvq0asl((&s_9), X60Qx_533);
      minusQeQ_0_Ipe1u69_hos5i19e11((&i_4), 4);}}
  whileStmtLabel_3: ;
  nimStrDestroy(result_38);
  result_38 = s_9;
  nimStrWasMoved((&s_9));
  nimStrDestroy(s_9);
  return result_38;
  nimStrDestroy(s_9);
  return result_38;}
X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax declineShim_0_run8hsnpi(string_0_sysvq0asl reason_1){
  X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax result_39;
  eQwasmovedQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi((&result_39));
  declineNote_0_croph25r5(2, reason_1);
  eQdestroyQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(result_39);
  result_39 = (X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax){
    .fld_0 = NIM_NIL, .fld_1 = NIM_FALSE}
  ;
  return result_39;}
X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax describeCallee_0_run8hsnpi(NU32 sym_9, Cursor_0_nifb6mq6y1 body_0){
  X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax result_40;
  eQwasmovedQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi((&result_40));
  Routine_0_decqocs071 r_3 = asRoutine_0_decqocs071(body_0, 0);
  void* X60Qx_534 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1));
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_105 = ((X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1*)X60Qx_534);
  string_0_sysvq0asl X60Qx_535 = baseNameOf_0_run8hsnpi(sym_9);
  string_0_sysvq0asl X60Qx_536 = shimNameFor_0_run8hsnpi(sym_9);
  seq_0_Il8twp61_aow7lb5cq1 X60Qx_537 = newSeqUninit_0_Iopvcdu1_aow7lb5cq1(0);
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_538 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_539 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_540 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Ik7wkpe_aow7lb5cq1 X60Qx_541 = newSeqUninit_0_Idxnvmq_aow7lb5cq1(0);
  (*X60Qtmp_105) = (X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1){
    .r_00 = 0, .d_00 = (ShimEntry_Obj_0_run8hsnpi){
      .sym_0 = sym_9, .base_0 = X60Qx_535, .shimSym_0 = X60Qx_536, .args_0 = X60Qx_537, .argOffs_0 = X60Qx_538, .inSize_0 = ((NI32)0), .ret_0 = (WireField_0_run8hsnpi){
        .desc_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)NIM_NIL), .srcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .isEnum_0 = NIM_FALSE, .isVar_0 = NIM_FALSE, .isRef_0 = NIM_FALSE, .isArenaRef_0 = NIM_FALSE, .isArenaPtr_0 = NIM_FALSE, .isPtrArena_0 = NIM_FALSE, .isForeignPtr_0 = NIM_FALSE, .isSink_0 = NIM_FALSE, .isPod_0 = NIM_FALSE, .isComposite_0 = NIM_FALSE, .isString_0 = NIM_FALSE, .isSeq_0 = NIM_FALSE, .isArray_0 = NIM_FALSE, .arrCount_0 = ((NI32)0), .elemVarLen_0 = NIM_FALSE, .elemLeafName_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .enumSym_0 = ((NU32)0u), .typeSym_0 = ((NU32)0u), .wireSize_0 = ((NI32)0), .wireAlign_0 = ((NI32)0), .elemSrcType_0 = (string_0_sysvq0asl){
          .bytes_0 = 0u, .more_0 = NIM_NIL}
        , .elemSize_0 = ((NI32)0), .elemStride_0 = ((NI32)0), .elemTypeSym_0 = ((NU32)0u)}
      , .retVoid_0 = NIM_FALSE, .outVarOffs_0 = X60Qx_539, .outSize_0 = ((NI32)0), .redeclTypes_0 = X60Qx_540, .redeclProc_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .noDerefOffs_0 = X60Qx_541, .fn_0 = ((X60Qt_0_IApointerZAR0ZAiS32ZAiS32ZAcdeclZAfalseZAR32_run8hsnpi)NIM_NIL), .resolved_0 = NIM_FALSE}}
  ;
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_14 = X60Qtmp_105;
  Cursor_0_nifb6mq6y1 pc_2 = r_3.params_0;
  eQwasMoved_0_nifb6mq6y1((&r_3.params_0));
  NB8 X60Qx_117;
  NifKind_0_nif81dubp1 X60Qx_542 = kind_0_nifb6mq6y1(pc_2);
  if (X60Qx_542 == 11){
    string_0_sysvq0asl X60Qtmp_106 = nodeTag_0_run8hsnpi(pc_2);
    NB8 X60Qx_543 = eqQ_20_sysvq0asl(X60Qtmp_106, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I5367917178860180580_der823rwr1)}
    );
    X60Qx_117 = X60Qx_543;
    nimStrDestroy(X60Qtmp_106);}
  else {
    X60Qx_117 = NIM_FALSE;}
  if (X60Qx_117){
    inc_0_nifb6mq6y1((&pc_2));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_544 = kind_0_nifb6mq6y1(pc_2);
        if ((!(X60Qx_544 == 12))){
          NifKind_0_nif81dubp1 X60Qx_545 = kind_0_nifb6mq6y1(pc_2);
          if (X60Qx_545 == 11){
            Local_0_decqocs071 loc_1 = takeLocal_0_decqocs071((&pc_2), 2);
            X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qtmptup_9 = describeType_0_run8hsnpi(loc_1.typ_0);
            WireField_0_run8hsnpi f_10 = X60Qtmptup_9.fld_0;
            eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60Qtmptup_9.fld_0));
            NB8 ok_4 = X60Qtmptup_9.fld_1;
            if ((!ok_4)){
              result_40 = (X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax){
                .fld_0 = NIM_NIL, .fld_1 = NIM_FALSE}
              ;
              eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_10));
              eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_9));
              eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_1));
              eQdestroy_0_nifb6mq6y1((&pc_2));
              eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
              eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
              return result_40;}
            if (f_10.isForeignPtr_0){
              X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_546 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                .bytes_0 = 1935892734u, .more_0 = (&strlit_0_I12060659291606161857_run8hsnpi)}
              );
              result_40 = X60Qx_546;
              eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_10));
              eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_9));
              eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_1));
              eQdestroy_0_nifb6mq6y1((&pc_2));
              eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
              eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
              return result_40;}
            WireField_0_run8hsnpi X60Qtmp_107 = f_10;
            eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_10));
            add_0_Itzi0i7_run8hsnpi((&(*e_14).d_00.args_0), X60Qtmp_107);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_10));
            eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_9));
            eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_1));}
          else {
            skip_0_nifb6mq6y1((&pc_2));}}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  NB8 X60Qx_547;
  NifKind_0_nif81dubp1 X60Qx_548 = kind_0_nifb6mq6y1(r_3.retType_0);
  if (X60Qx_548 == 11){
    X60Qx_547 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_549 = kind_0_nifb6mq6y1(r_3.retType_0);
    X60Qx_547 = (X60Qx_549 == 4);}
  if (X60Qx_547){
    string_0_sysvq0asl X60Qx_27;
    nimStrWasMoved((&X60Qx_27));
    NifKind_0_nif81dubp1 X60Qx_550 = kind_0_nifb6mq6y1(r_3.retType_0);
    if (X60Qx_550 == 11){
      nimStrDestroy(X60Qx_27);
      string_0_sysvq0asl X60Qx_551 = nodeTag_0_run8hsnpi(r_3.retType_0);
      X60Qx_27 = X60Qx_551;}
    else {
      nimStrDestroy(X60Qx_27);
      X60Qx_27 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;}
    string_0_sysvq0asl rtag_0 = X60Qx_27;
    nimStrWasMoved((&X60Qx_27));
    NB8 X60Qx_552 = eqQ_20_sysvq0asl(rtag_0, (string_0_sysvq0asl){
      .bytes_0 = 1768912638u, .more_0 = (&strlit_0_I11155032387348830029_aow7lb5cq1)}
    );
    if (X60Qx_552){
      (*e_14).d_00.retVoid_0 = NIM_TRUE;}
    else {
      X60Qt_0_IAtupleSX57ireX46ield0run8hsnpiAbool_run8hsnpi X60Qtmptup_10 = describeType_0_run8hsnpi(r_3.retType_0);
      WireField_0_run8hsnpi f_11 = X60Qtmptup_10.fld_0;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60Qtmptup_10.fld_0));
      NB8 ok_5 = X60Qtmptup_10.fld_1;
      if ((!ok_5)){
        result_40 = (X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax){
          .fld_0 = NIM_NIL, .fld_1 = NIM_FALSE}
        ;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));
        nimStrDestroy(rtag_0);
        nimStrDestroy(X60Qx_27);
        eQdestroy_0_nifb6mq6y1((&pc_2));
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
        return result_40;}
      NB8 X60Qx_553;
      if (f_11.isRef_0){
        X60Qx_553 = NIM_TRUE;}
      else {
        X60Qx_553 = f_11.isArenaRef_0;}
      if (X60Qx_553){
        X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_554 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I9252022049267197370_run8hsnpi)}
        );
        result_40 = X60Qx_554;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));
        nimStrDestroy(rtag_0);
        nimStrDestroy(X60Qx_27);
        eQdestroy_0_nifb6mq6y1((&pc_2));
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
        return result_40;}
      if (f_11.isPtrArena_0){
        X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_555 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1953521918u, .more_0 = (&strlit_0_I293621626120980652_run8hsnpi)}
        );
        result_40 = X60Qx_555;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));
        nimStrDestroy(rtag_0);
        nimStrDestroy(X60Qx_27);
        eQdestroy_0_nifb6mq6y1((&pc_2));
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
        return result_40;}
      NB8 X60Qx_556;
      NB8 X60Qx_557;
      if (f_11.isPod_0){
        X60Qx_557 = (((NU32)f_11.typeSym_0) == ((NU32)0u));}
      else {
        X60Qx_557 = NIM_FALSE;}
      if (X60Qx_557){
        NB8 X60Qx_558;
        if (f_11.desc_0 == NIM_NIL){
          X60Qx_558 = NIM_TRUE;}
        else {
          X60Qx_558 = (!((*f_11.desc_0).d_00.kind_0 == 11));}
        X60Qx_556 = X60Qx_558;}
      else {
        X60Qx_556 = NIM_FALSE;}
      if (X60Qx_556){
        X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_559 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
          .bytes_0 = 1869505022u, .more_0 = (&strlit_0_I12129503281566277309_run8hsnpi)}
        );
        result_40 = X60Qx_559;
        eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
        eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));
        nimStrDestroy(rtag_0);
        nimStrDestroy(X60Qx_27);
        eQdestroy_0_nifb6mq6y1((&pc_2));
        eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
        return result_40;}
      WireField_0_run8hsnpi* X60Qlhs_108 = (&(*e_14).d_00.ret_0);
      WireField_0_run8hsnpi X60Qlhs_109 = f_11;
      eQwasmovedQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&(*X60Qlhs_108)));
      (*X60Qlhs_108) = X60Qlhs_109;
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_11));
      eQdestroyQ_AtupleSX57ireX46ield0run8hsnpiAbool_0_run8hsnpi((&X60Qtmptup_10));}
    nimStrDestroy(rtag_0);
    nimStrDestroy(X60Qx_27);}
  else {
    (*e_14).d_00.retVoid_0 = NIM_TRUE;}
  NI32 off_8 = 0;
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_10 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_14).d_00.args_0);
    NI32 X60Qlf_11 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_560 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_10);
        if (X60Qlf_11 < X60Qx_560){
          {
            WireField_0_run8hsnpi* X60Qii_3 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_10, X60Qlf_11);
            add_0_I8kd4i4_aow7lb5cq1((&(*e_14).d_00.argOffs_0), off_8);
            NI32 X60Qx_28;
            if (0 < (*X60Qii_3).wireSize_0){
              X60Qx_28 = (*X60Qii_3).wireSize_0;}
            else {
              X60Qx_28 = 8;}
            off_8 = ((NI32)(off_8 + X60Qx_28));}
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
        NI32 X60Qx_561 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_12);
        if (X60Qlf_13 < X60Qx_561){
          {
            WireField_0_run8hsnpi* X60Qii_6 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_12, X60Qlf_13);
            if ((*X60Qii_6).isVar_0){
              hasVar_0 = NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_13));}
        else {
          break;}}}
    whileStmtLabel_5: ;}
  forStmtLabel_4: ;
  NB8 X60Qx_562;
  NB8 X60Qx_563;
  if (hasVar_0){
    X60Qx_563 = (!(*e_14).d_00.retVoid_0);}
  else {
    X60Qx_563 = NIM_FALSE;}
  if (X60Qx_563){
    X60Qx_562 = ((*e_14).d_00.ret_0.wireSize_0 == 0);}
  else {
    X60Qx_562 = NIM_FALSE;}
  if (X60Qx_562){
    X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_564 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
      .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I15683387437464179193_run8hsnpi)}
    );
    result_40 = X60Qx_564;
    eQdestroy_0_nifb6mq6y1((&pc_2));
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
    return result_40;}
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_14 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_14).d_00.args_0);
    NI32 X60Qlf_15 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_565 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_14);
        if (X60Qlf_15 < X60Qx_565){
          {
            WireField_0_run8hsnpi* X60Qii_9 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_14, X60Qlf_15);
            NB8 X60Qx_566;
            if ((*X60Qii_9).isVar_0){
              X60Qx_566 = (*X60Qii_9).isArenaPtr_0;}
            else {
              X60Qx_566 = NIM_FALSE;}
            if (X60Qx_566){
              NB8 X60Qx_567;
              if ((*X60Qii_9).desc_0 == NIM_NIL){
                X60Qx_567 = NIM_TRUE;}
              else {
                X60Qx_567 = (((NU32)(*X60Qii_9).typeSym_0) == ((NU32)0u));}
              if (X60Qx_567){
                X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_568 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                  .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I4449311905133063423_run8hsnpi)}
                );
                result_40 = X60Qx_568;
                eQdestroy_0_nifb6mq6y1((&pc_2));
                eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
                eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
                return result_40;}
              X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qii_10 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qii_9).desc_0);
              while (NIM_TRUE){
                NB8 X60Qx_569;
                if ((!(X60Qii_10 == NIM_NIL))){
                  X60Qx_569 = ((*X60Qii_10).d_00.kind_0 == 13);}
                else {
                  X60Qx_569 = NIM_FALSE;}
                if (X60Qx_569){
                  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qlhs_110 = X60Qii_10;
                  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_570 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qii_10).d_00.elem_0);
                  X60Qii_10 = X60Qx_570;
                  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qlhs_110);}
                else {
                  break;}}
              NB8 X60Qx_571;
              if (X60Qii_10 == NIM_NIL){
                X60Qx_571 = NIM_TRUE;}
              else {
                NB8 X60Qx_572;
                if ((!((*X60Qii_10).d_00.kind_0 == 10))){
                  X60Qx_572 = (!((*X60Qii_10).d_00.kind_0 == 11));}
                else {
                  X60Qx_572 = NIM_FALSE;}
                X60Qx_571 = X60Qx_572;}
              if (X60Qx_571){
                X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_573 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                  .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I12911497544173404865_run8hsnpi)}
                );
                result_40 = X60Qx_573;
                eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qii_10);
                eQdestroy_0_nifb6mq6y1((&pc_2));
                eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
                eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
                return result_40;}
              {
                openArray_0_I3ca6t4_layptix6a1 X60Qlf_16 = toOpenArray_1_I0zz6qv1_layptix6a1((*X60Qii_10).d_00.fields_0);
                NI32 X60Qlf_17 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_574 = len_6_I0tpktl1_layptix6a1(X60Qlf_16);
                    if (X60Qlf_17 < X60Qx_574){
                      {
                        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qii_13 = getQ_10_Ikixp7k_layptix6a1(X60Qlf_16, X60Qlf_17);
                        if ((*X60Qii_13) == NIM_NIL){
                          X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_575 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                            .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I12139432315779883303_run8hsnpi)}
                          );
                          result_40 = X60Qx_575;
                          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qii_10);
                          eQdestroy_0_nifb6mq6y1((&pc_2));
                          eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
                          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
                          return result_40;}
                        NB8 X60Qx_576;
                        NB8 X60Qx_577;
                        NB8 X60Qx_578;
                        NB8 X60Qx_579;
                        NB8 X60Qx_580;
                        NB8 X60Qx_581;
                        if ((*(*X60Qii_13)).d_00.kind_0 == 10){
                          X60Qx_581 = NIM_TRUE;}
                        else {
                          X60Qx_581 = ((*(*X60Qii_13)).d_00.kind_0 == 11);}
                        if (X60Qx_581){
                          X60Qx_580 = NIM_TRUE;}
                        else {
                          X60Qx_580 = ((*(*X60Qii_13)).d_00.kind_0 == 13);}
                        if (X60Qx_580){
                          X60Qx_579 = NIM_TRUE;}
                        else {
                          X60Qx_579 = ((*(*X60Qii_13)).d_00.kind_0 == 15);}
                        if (X60Qx_579){
                          X60Qx_578 = NIM_TRUE;}
                        else {
                          X60Qx_578 = ((*(*X60Qii_13)).d_00.kind_0 == 9);}
                        if (X60Qx_578){
                          X60Qx_577 = NIM_TRUE;}
                        else {
                          X60Qx_577 = ((*(*X60Qii_13)).d_00.kind_0 == 6);}
                        if (X60Qx_577){
                          X60Qx_576 = NIM_TRUE;}
                        else {
                          X60Qx_576 = ((*(*X60Qii_13)).d_00.kind_0 == 12);}
                        if (X60Qx_576){
                          X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax X60Qx_582 = declineShim_0_run8hsnpi((string_0_sysvq0asl){
                            .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I3386527286220271425_run8hsnpi)}
                          );
                          result_40 = X60Qx_582;
                          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qii_10);
                          eQdestroy_0_nifb6mq6y1((&pc_2));
                          eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
                          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
                          return result_40;}}
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
  NI64 X60Qx_29;
  if ((*e_14).d_00.retVoid_0){
    X60Qx_29 = 0;}
  else {
    X60Qx_29 = (*e_14).d_00.ret_0.wireSize_0;}
  NI32 retFixed_0 = X60Qx_29;
  NI32 wb_0 = retFixed_0;
  NI32 vi_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_583 = len_3_In63jw61_aow7lb5cq1((*e_14).d_00.args_0);
      if (vi_0 < X60Qx_583){
        WireField_0_run8hsnpi* X60Qx_584 = getQ_7_Iko57h9_aow7lb5cq1((*e_14).d_00.args_0, vi_0);
        if ((*X60Qx_584).isVar_0){
          add_0_I8kd4i4_aow7lb5cq1((&(*e_14).d_00.outVarOffs_0), wb_0);
          WireField_0_run8hsnpi* X60Qx_585 = getQ_7_Iko57h9_aow7lb5cq1((*e_14).d_00.args_0, vi_0);
          wb_0 = ((NI32)(wb_0 + (*X60Qx_585).wireSize_0));}
        else {
          add_0_I8kd4i4_aow7lb5cq1((&(*e_14).d_00.outVarOffs_0), -1);}
        inc_1_I6wjjge_aow2h993l1((&vi_0));}
      else {
        break;}}}
  whileStmtLabel_14: ;
  NI32 X60Qx_30;
  if (hasVar_0){
    X60Qx_30 = wb_0;}
  else {
    if ((*e_14).d_00.retVoid_0){
      X60Qx_30 = 0;}
    else {
      NI32 X60Qx_31;
      if (0 < (*e_14).d_00.ret_0.wireSize_0){
        X60Qx_31 = (*e_14).d_00.ret_0.wireSize_0;}
      else {
        X60Qx_31 = 64;}
      X60Qx_30 = X60Qx_31;}}
  (*e_14).d_00.outSize_0 = X60Qx_30;
  seq_0_Ik7wkpe_aow7lb5cq1* X60Qlhs_111 = (&(*e_14).d_00.noDerefOffs_0);
  seq_0_Ik7wkpe_aow7lb5cq1 X60Qlhs_112 = newSeqUninit_0_Idxnvmq_aow7lb5cq1(0);
  eQdestroy_1_Ij4pznj1_aow7lb5cq1((*X60Qlhs_111));
  (*X60Qlhs_111) = X60Qlhs_112;
  NI32 gi_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_586 = len_3_In63jw61_aow7lb5cq1((*e_14).d_00.args_0);
      if (gi_0 < X60Qx_586){
        seq_0_Ift2sne_aow7lb5cq1 X60Qx_587 = newSeq_0_I7328u4_flaksyopx1(0);
        add_0_Iivdbhc_aow7lb5cq1((&(*e_14).d_00.noDerefOffs_0), X60Qx_587);
        inc_1_I6wjjge_aow2h993l1((&gi_0));}
      else {
        break;}}}
  whileStmtLabel_15: ;
  eQdestroyQ_AtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_0_run8hsnpi(result_40);
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_113 = e_14;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&e_14));
  result_40 = (X60Qt_0_IAtupleArefSX53himX45ntryX4fbj0run8hsnpiZAbool_intzsnzax){
    .fld_0 = X60Qtmp_113, .fld_1 = NIM_TRUE}
  ;
  eQdestroy_0_nifb6mq6y1((&pc_2));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
  return result_40;
  eQdestroy_0_nifb6mq6y1((&pc_2));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_14);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
  return result_40;}
NU64 valToU64_0_run8hsnpi(Value_0_valzr1t4f* v_0){
  NU64 result_41;
  NU64 X60Qx_32;
  switch ((*v_0).kind_0){
    case 1:
    case 2:
    {
      NI64 X60Qx_588 = asInt_0_valzr1t4f((&(*v_0)));
      X60Qx_32 = ((NU64)X60Qx_588);}
    break;
    case 5:
    {
      X60Qx_32 = ((NU64)((NU8)(*v_0).cval_0));}
    break;
    case 4:
    {
      NU64 X60Qx_33;
      if ((*v_0).bval_0){
        X60Qx_33 = ((NU64)1u);}
      else {
        X60Qx_33 = ((NU64)0u);}
      X60Qx_32 = X60Qx_33;}
    break;
    case 7:
    {
      X60Qx_32 = ((NU64)((NU32)((NI32)(*v_0).eord_0)));}
    break;
    case 3:
    {
      NU64 X60Qx_34;
      if ((*v_0).fbits_0 == 32){
        NF32 X60Qx_589 = ((NF32)(*v_0).fval_0);
        NU32 X60Qx_590;
        copyMem_0_sysvq0asl((&X60Qx_590), (&X60Qx_589), sizeof(NU32));
        X60Qx_34 = ((NU64)X60Qx_590);}
      else {
        NF64 X60Qx_591 = (*v_0).fval_0;
        NU64 X60Qx_592;
        copyMem_0_sysvq0asl((&X60Qx_592), (&X60Qx_591), sizeof(NU64));
        X60Qx_34 = X60Qx_592;}
      X60Qx_32 = X60Qx_34;}
    break;
    default:
    {
      X60Qx_32 = ((NU64)0u);}
    break;}
  result_41 = X60Qx_32;
  return result_41;}
void writeBytes_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_0, NI32 off_0, NU64 u_0, NI32 n_1){
  NI32 i_6 = 0;
  {
    while (i_6 < n_1){
      putQ_7_Ipw0nqk1_explnj22x1(buf_0, ((NI32)(off_0 + i_6)), ((NU8)((NU64)(((NU64)(u_0 >> ((NU32)(((NU32)i_6) * 8u)))) & ((NU64)255u)))));
      inc_1_I6wjjge_aow2h993l1((&i_6));}}
  whileStmtLabel_0: ;}
NU64 readBytes_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v buf_1, NI32 off_1, NI32 n_2){
  NU64 result_42;
  NU64 u_3 = ((NU64)0u);
  NI32 i_8 = 0;
  {
    while (i_8 < n_2){
      NU8* X60Qx_593 = getQ_7_Ig0r1051_arecyyj7v(buf_1, ((NI32)(off_1 + i_8)));
      u_3 = ((NU64)(u_3 | ((NU64)(((NU64)(*X60Qx_593)) << ((NU32)(((NU32)i_8) * 8u))))));
      inc_1_I6wjjge_aow2h993l1((&i_8));}}
  whileStmtLabel_0: ;
  result_42 = u_3;
  return result_42;}
void packPod_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_2, NI32 off_2, Value_0_valzr1t4f* v_1, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_4){
  seq_0_Ift2sne_aow7lb5cq1 offs_0 = fieldOffsets_0_layptix6a1(td_4, 8);
  if ((*v_1).obj_0 == NIM_NIL){
    eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_0);
    return;}
  NI32 i_10 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_594;
      NB8 X60Qx_595;
      NI32 X60Qx_596 = len_3_I5m68tr1_aow7lb5cq1((*td_4).d_00.fields_0);
      if (i_10 < X60Qx_596){
        NI32 X60Qx_597 = len_3_I83dzei_arecyyj7v((*(*v_1).obj_0).d_00.cells_0);
        X60Qx_595 = (i_10 < X60Qx_597);}
      else {
        X60Qx_595 = NIM_FALSE;}
      if (X60Qx_595){
        NI32 X60Qx_598 = len_3_I0v1j8d_aow7lb5cq1(offs_0);
        X60Qx_594 = (i_10 < X60Qx_598);}
      else {
        X60Qx_594 = NIM_FALSE;}
      if (X60Qx_594){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_599 = getQ_7_I45w7c91_aow7lb5cq1((*td_4).d_00.fields_0, i_10);
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* fd_3 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qx_599));
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_600 = getQ_7_Ii14ync1_arecyyj7v((*(*v_1).obj_0).d_00.cells_0, i_10);
        Value_0_valzr1t4f cv_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_600)).d_00.v_0));
        NB8 X60Qx_601;
        if ((*fd_3).d_00.kind_0 == 10){
          X60Qx_601 = NIM_TRUE;}
        else {
          X60Qx_601 = ((*fd_3).d_00.kind_0 == 11);}
        if (X60Qx_601){
          NI32* X60Qx_602 = getQ_7_Ir8kccm_aow7lb5cq1(offs_0, i_10);
          packPod_0_run8hsnpi(buf_2, ((NI32)(off_2 + (*X60Qx_602))), (&cv_0), fd_3);}
        else {
          NI32* X60Qx_603 = getQ_7_Ir8kccm_aow7lb5cq1(offs_0, i_10);
          NU64 X60Qx_604 = valToU64_0_run8hsnpi((&cv_0));
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_605 = sizeAlign_1_layptix6a1(fd_3, 8);
          writeBytes_0_run8hsnpi(buf_2, ((NI32)(off_2 + (*X60Qx_603))), X60Qx_604, X60Qx_605.fld_0);}
        inc_1_I6wjjge_aow2h993l1((&i_10));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_0));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_3);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_0);}
NB8 packPodArena_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_3, NI32 off_3, Value_0_valzr1t4f* v_2, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_5, ArenaMat_0_arecyyj7v* m_0, seq_0_Ift2sne_aow7lb5cq1 noDerefOffs_0){
  NB8 result_43;
  if (td_5 == NIM_NIL){
    return NIM_FALSE;}
  if ((*td_5).d_00.kind_0 == 13){
    NB8 X60Qx_606;
    if ((!((*td_5).d_00.elem_0 == NIM_NIL))){
      NB8 X60Qx_607 = packPodArena_0_run8hsnpi(buf_3, off_3, (&(*v_2)), (*td_5).d_00.elem_0, m_0, noDerefOffs_0);
      X60Qx_606 = X60Qx_607;}
    else {
      X60Qx_606 = NIM_FALSE;}
    result_43 = X60Qx_606;
    return result_43;}
  if ((*v_2).obj_0 == NIM_NIL){
    return NIM_FALSE;}
  seq_0_Ift2sne_aow7lb5cq1 offs_1 = fieldOffsets_0_layptix6a1(td_5, 8);
  result_43 = NIM_TRUE;
  NI32 i_13 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_608;
      NB8 X60Qx_609;
      NI32 X60Qx_610 = len_3_I5m68tr1_aow7lb5cq1((*td_5).d_00.fields_0);
      if (i_13 < X60Qx_610){
        NI32 X60Qx_611 = len_3_I83dzei_arecyyj7v((*(*v_2).obj_0).d_00.cells_0);
        X60Qx_609 = (i_13 < X60Qx_611);}
      else {
        X60Qx_609 = NIM_FALSE;}
      if (X60Qx_609){
        NI32 X60Qx_612 = len_3_I0v1j8d_aow7lb5cq1(offs_1);
        X60Qx_608 = (i_13 < X60Qx_612);}
      else {
        X60Qx_608 = NIM_FALSE;}
      if (X60Qx_608){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_613 = getQ_7_I45w7c91_aow7lb5cq1((*td_5).d_00.fields_0, i_13);
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* fd_4 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qx_613));
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_614 = getQ_7_Ii14ync1_arecyyj7v((*(*v_2).obj_0).d_00.cells_0, i_13);
        Value_0_valzr1t4f cv_1 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_614)).d_00.v_0));
        if ((*fd_4).d_00.kind_0 == 5){
          NB8 nd_0 = NIM_FALSE;
          NI32 q_0 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_615 = len_3_I0v1j8d_aow7lb5cq1(noDerefOffs_0);
              if (q_0 < X60Qx_615){
                NI32* X60Qx_616 = getQ_7_Ir8kccm_aow7lb5cq1(noDerefOffs_0, q_0);
                NI32* X60Qx_617 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_13);
                if ((*X60Qx_616) == (*X60Qx_617)){
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
          NI32* X60Qx_618 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_13);
          writeBytes_0_run8hsnpi(buf_3, ((NI32)(off_3 + (*X60Qx_618))), ((NU64)((NU32)p_12)), 8);}
        else {
          if ((*fd_4).d_00.kind_0 == 15){
            if ((!(cv_1.kind_0 == 8))){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_1));
              eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_4);
              eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_1);
              return NIM_FALSE;}
            BlockEntry_0_arecyyj7v b_2 = seqBlock_0_arecyyj7v(m_0, cv_1.sq_0);
            NI32* X60Qx_619 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_13);
            writeBytes_0_run8hsnpi(buf_3, ((NI32)(((NI32)(off_3 + (*X60Qx_619))) + ((NI32)0))), ((NU64)b_2.count_0), 8);
            NI32* X60Qx_620 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_13);
            writeBytes_0_run8hsnpi(buf_3, ((NI32)(((NI32)(off_3 + (*X60Qx_620))) + ((NI32)8))), ((NU64)b_2.data_0), 8);
            eQdestroyQ_SX42lockX45ntry0arecyyj7v_0_arecyyj7v((&b_2));}
          else {
            NB8 X60Qx_621;
            NB8 X60Qx_622;
            if ((*fd_4).d_00.kind_0 == 10){
              X60Qx_622 = NIM_TRUE;}
            else {
              X60Qx_622 = ((*fd_4).d_00.kind_0 == 11);}
            if (X60Qx_622){
              X60Qx_621 = NIM_TRUE;}
            else {
              X60Qx_621 = ((*fd_4).d_00.kind_0 == 13);}
            if (X60Qx_621){
              seq_0_Ift2sne_aow7lb5cq1 X60Qtmp_114 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
              NI32* X60Qx_623 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_13);
              NB8 X60Qx_624 = packPodArena_0_run8hsnpi(buf_3, ((NI32)(off_3 + (*X60Qx_623))), (&cv_1), fd_4, m_0, X60Qtmp_114);
              if ((!X60Qx_624)){
                eQdestroy_1_Iv9ij5i1_aow7lb5cq1(X60Qtmp_114);
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_1));
                eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_4);
                eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_1);
                return NIM_FALSE;}
              eQdestroy_1_Iv9ij5i1_aow7lb5cq1(X60Qtmp_114);}
            else {
              NI32* X60Qx_625 = getQ_7_Ir8kccm_aow7lb5cq1(offs_1, i_13);
              NU64 X60Qx_626 = valToU64_0_run8hsnpi((&cv_1));
              X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_627 = sizeAlign_1_layptix6a1(fd_4, 8);
              writeBytes_0_run8hsnpi(buf_3, ((NI32)(off_3 + (*X60Qx_625))), X60Qx_626, X60Qx_627.fld_0);}}}
        inc_1_I6wjjge_aow2h993l1((&i_13));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_1));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_4);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_1);
  return result_43;
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_1);
  return result_43;}
void appendU_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_4, NU64 u_1, NI32 n_3){
  NI32 i_14 = 0;
  {
    while (i_14 < n_3){
      add_0_Ibphvmo_run8hsnpi(buf_4, ((NU8)((NU64)(((NU64)(u_1 >> ((NU32)(((NU32)i_14) * 8u)))) & ((NU64)255u)))));
      inc_1_I6wjjge_aow2h993l1((&i_14));}}
  whileStmtLabel_0: ;}
seq_0_Incv1wn_arecyyj7v podBytes_0_run8hsnpi(Value_0_valzr1t4f* v_3, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_6){
  seq_0_Incv1wn_arecyyj7v result_44;
  eQwasMoved_1_I861g1c1_arecyyj7v((&result_44));
  eQdestroy_1_Ijx6eoq_arecyyj7v(result_44);
  X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_628 = sizeAlign_1_layptix6a1(td_6, 8);
  seq_0_Incv1wn_arecyyj7v X60Qx_629 = newSeq_0_Ivbxvoi1_explnj22x1(X60Qx_628.fld_0);
  result_44 = X60Qx_629;
  packPod_0_run8hsnpi((&result_44), 0, (&(*v_3)), td_6);
  return result_44;}
void appendVal_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_5, Value_0_valzr1t4f* v_4, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_7){
  switch ((*td_7).d_00.kind_0){
    case 10:
    case 11:
    {
      NI32 i_15 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_630 = len_3_I5m68tr1_aow7lb5cq1((*td_7).d_00.fields_0);
          if (i_15 < X60Qx_630){
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_35;
            eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_35));
            NB8 X60Qx_631;
            if ((*v_4).kind_0 == 11){
              X60Qx_631 = NIM_TRUE;}
            else {
              X60Qx_631 = ((*v_4).kind_0 == 10);}
            if (X60Qx_631){
              eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_35);
              X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_632 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((*v_4).obj_0);
              X60Qx_35 = X60Qx_632;}
            else {
              eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_35);
              X60Qx_35 = NIM_NIL;}
            X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_0 = X60Qx_35;
            eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_35));
            Value_0_valzr1t4f X60Qx_36;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_36));
            NB8 X60Qx_633;
            NB8 X60Qx_634;
            if ((!(box_0 == NIM_NIL))){
              NI32 X60Qx_635 = len_3_I83dzei_arecyyj7v((*box_0).d_00.cells_0);
              X60Qx_634 = (i_15 < X60Qx_635);}
            else {
              X60Qx_634 = NIM_FALSE;}
            if (X60Qx_634){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_636 = getQ_7_Ii14ync1_arecyyj7v((*box_0).d_00.cells_0, i_15);
              X60Qx_633 = (!((*X60Qx_636) == NIM_NIL));}
            else {
              X60Qx_633 = NIM_FALSE;}
            if (X60Qx_633){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_36));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_637 = getQ_7_Ii14ync1_arecyyj7v((*box_0).d_00.cells_0, i_15);
              Value_0_valzr1t4f X60Qx_638 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_637)).d_00.v_0));
              X60Qx_36 = X60Qx_638;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_36));
              Value_0_valzr1t4f X60Qx_639 = vNil_0_valzr1t4f();
              X60Qx_36 = X60Qx_639;}
            Value_0_valzr1t4f fv_0 = X60Qx_36;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_36));
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_640 = getQ_7_I45w7c91_aow7lb5cq1((*td_7).d_00.fields_0, i_15);
            appendVal_0_run8hsnpi(buf_5, (&fv_0), (*X60Qx_640));
            inc_1_I6wjjge_aow2h993l1((&i_15));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&fv_0));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_36));
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_0);
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_35);}
          else {
            break;}}}
      whileStmtLabel_0: ;}
    break;
    case 14:
    {
      string_0_sysvq0asl X60Qx_37;
      nimStrWasMoved((&X60Qx_37));
      if ((*v_4).kind_0 == 6){
        nimStrDestroy(X60Qx_37);
        string_0_sysvq0asl X60Qx_641 = nimStrDup((*v_4).sval_0);
        X60Qx_37 = X60Qx_641;}
      else {
        nimStrDestroy(X60Qx_37);
        string_0_sysvq0asl X60Qx_642 = dollarQ_0_valzr1t4f((&(*v_4)));
        X60Qx_37 = X60Qx_642;}
      string_0_sysvq0asl s_23 = X60Qx_37;
      nimStrWasMoved((&X60Qx_37));
      NI32 X60Qx_643 = len_4_sysvq0asl(s_23);
      appendU_0_run8hsnpi(buf_5, ((NU64)X60Qx_643), 8);
      {
        openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_18 = toOpenArray_2_sysvq0asl((&s_23));
        NI32 X60Qlf_19 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_644 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_18);
            if (X60Qlf_19 < X60Qx_644){
              {
                NC8* X60Qii_3 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_18, X60Qlf_19);
                add_0_Ibphvmo_run8hsnpi(buf_5, ((NU8)(*X60Qii_3)));}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_19));}
            else {
              break;}}}
        whileStmtLabel_2: ;}
      forStmtLabel_1: ;
      nimStrDestroy(s_23);
      nimStrDestroy(X60Qx_37);}
    break;
    case 15:
    {
      NI32 X60Qx_38;
      NB8 X60Qx_645;
      if ((*v_4).kind_0 == 8){
        X60Qx_645 = (!((*v_4).sq_0 == NIM_NIL));}
      else {
        X60Qx_645 = NIM_FALSE;}
      if (X60Qx_645){
        NI32 X60Qx_646 = len_3_I83dzei_arecyyj7v((*(*v_4).sq_0).d_00.elems_0);
        X60Qx_38 = X60Qx_646;}
      else {
        X60Qx_38 = 0;}
      NI32 n_7 = X60Qx_38;
      appendU_0_run8hsnpi(buf_5, ((NU64)n_7), 8);
      NI32 i_16 = 0;
      {
        while (i_16 < n_7){
          Value_0_valzr1t4f X60Qx_39;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_39));
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_647 = getQ_7_Ii14ync1_arecyyj7v((*(*v_4).sq_0).d_00.elems_0, i_16);
          if ((!((*X60Qx_647) == NIM_NIL))){
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_39));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_648 = getQ_7_Ii14ync1_arecyyj7v((*(*v_4).sq_0).d_00.elems_0, i_16);
            Value_0_valzr1t4f X60Qx_649 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_648)).d_00.v_0));
            X60Qx_39 = X60Qx_649;}
          else {
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_39));
            Value_0_valzr1t4f X60Qx_650 = vNil_0_valzr1t4f();
            X60Qx_39 = X60Qx_650;}
          Value_0_valzr1t4f ev_0 = X60Qx_39;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_39));
          appendVal_0_run8hsnpi(buf_5, (&ev_0), (*td_7).d_00.elem_0);
          inc_1_I6wjjge_aow2h993l1((&i_16));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_0));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_39));}}
      whileStmtLabel_4: ;}
    break;
    default:
    {
      NU64 X60Qx_651 = valToU64_0_run8hsnpi((&(*v_4)));
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_652 = sizeAlign_1_layptix6a1(td_7, 8);
      appendU_0_run8hsnpi(buf_5, X60Qx_651, X60Qx_652.fld_0);}
    break;}}
Value_0_valzr1t4f readVal_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v buf_6, NI32* pos_0, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_8, NU32 typeSym_1){
  Value_0_valzr1t4f result_45;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_45));
  switch ((*td_8).d_00.kind_0){
    case 10:
    case 11:
    {
      X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi info_0 = podFieldInfo_1_run8hsnpi(typeSym_1);
      void* X60Qx_653 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_115 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_653);
      seq_0_In6doa_arecyyj7v X60Qx_654 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_655 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_115) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
          .typeSym_0 = typeSym_1, .names_0 = X60Qx_654, .cells_0 = X60Qx_655}}
      ;
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_1 = X60Qtmp_115;
      NI32 i_17 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_656 = len_3_I5m68tr1_aow7lb5cq1((*td_8).d_00.fields_0);
          if (i_17 < X60Qx_656){
            NU32 X60Qx_40;
            NI32 X60Qx_657 = len_3_I6y2imo_arecyyj7v(info_0.fld_1);
            if (i_17 < X60Qx_657){
              NU32* X60Qx_658 = getQ_7_I2v00yv1_arecyyj7v(info_0.fld_1, i_17);
              X60Qx_40 = (*X60Qx_658);}
            else {
              X60Qx_40 = ((NU32)0u);}
            NU32 nm_0 = X60Qx_40;
            NU32 X60Qx_41;
            NI32 X60Qx_659 = len_3_I6y2imo_arecyyj7v(info_0.fld_2);
            if (i_17 < X60Qx_659){
              NU32* X60Qx_660 = getQ_7_I2v00yv1_arecyyj7v(info_0.fld_2, i_17);
              X60Qx_41 = (*X60Qx_660);}
            else {
              X60Qx_41 = ((NU32)0u);}
            NU32 fts_0 = X60Qx_41;
            add_0_I34il1q_der823rwr1((&(*box_1).d_00.names_0), nm_0);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_661 = getQ_7_I45w7c91_aow7lb5cq1((*td_8).d_00.fields_0, i_17);
            Value_0_valzr1t4f X60Qtmp_116 = readVal_0_run8hsnpi(buf_6, pos_0, (*X60Qx_661), fts_0);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_662 = newCell_0_valzr1t4f((&X60Qtmp_116));
            add_0_Ijpw0mu_flaksyopx1((&(*box_1).d_00.cells_0), X60Qx_662);
            inc_1_I6wjjge_aow2h993l1((&i_17));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_116));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      Value_0_valzr1t4f X60Qx_42;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
      NB8 X60Qx_663;
      if ((*td_8).d_00.kind_0 == 11){
        X60Qx_663 = NIM_TRUE;}
      else {
        X60Qx_663 = info_0.fld_0;}
      if (X60Qx_663){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_117 = box_1;
        eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&box_1));
        X60Qx_42 = (Value_0_valzr1t4f){
          .kind_0 = 10, .obj_0 = X60Qtmp_117}
        ;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_118 = box_1;
        eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&box_1));
        X60Qx_42 = (Value_0_valzr1t4f){
          .kind_0 = 11, .obj_0 = X60Qtmp_118}
        ;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_45));
      result_45 = X60Qx_42;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_42));
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_1);
      eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_0);}
    break;
    case 14:
    {
      NU64 X60Qx_664 = readBytes_0_run8hsnpi(buf_6, (*pos_0), 8);
      NI32 n_8 = ((NI32)X60Qx_664);
      (*pos_0) = ((NI32)((*pos_0) + 8));
      string_0_sysvq0asl s_28 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NI32 i_19 = 0;
      {
        while (i_19 < n_8){
          NU8* X60Qx_665 = getQ_7_Ig0r1051_arecyyj7v(buf_6, ((NI32)((*pos_0) + i_19)));
          add_1_sysvq0asl((&s_28), ((NC8)((NU8)(*X60Qx_665))));
          inc_1_I6wjjge_aow2h993l1((&i_19));}}
      whileStmtLabel_1: ;
      (*pos_0) = ((NI32)((*pos_0) + n_8));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_45));
      Value_0_valzr1t4f X60Qx_666 = vStr_0_valzr1t4f(s_28);
      result_45 = X60Qx_666;
      nimStrDestroy(s_28);}
    break;
    case 15:
    {
      NU64 X60Qx_667 = readBytes_0_run8hsnpi(buf_6, (*pos_0), 8);
      NI32 n_9 = ((NI32)X60Qx_667);
      (*pos_0) = ((NI32)((*pos_0) + 8));
      void* X60Qx_668 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_119 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_668);
      seq_0_Iw8xl5b1_arecyyj7v X60Qx_669 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
      (*X60Qtmp_119) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
        .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
          .elems_0 = X60Qx_669, .flat_0 = NIM_NIL}}
      ;
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_0 = X60Qtmp_119;
      NI32 i_20 = 0;
      {
        while (i_20 < n_9){
          Value_0_valzr1t4f X60Qtmp_120 = readVal_0_run8hsnpi(buf_6, pos_0, (*td_8).d_00.elem_0, ((NU32)0u));
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_670 = newCell_0_valzr1t4f((&X60Qtmp_120));
          add_0_Ijpw0mu_flaksyopx1((&(*sb_0).d_00.elems_0), X60Qx_670);
          inc_1_I6wjjge_aow2h993l1((&i_20));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_120));}}
      whileStmtLabel_2: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_45));
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_121 = sb_0;
      eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi((&sb_0));
      result_45 = (Value_0_valzr1t4f){
        .kind_0 = 8, .sq_0 = X60Qtmp_121}
      ;
      eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(sb_0);}
    break;
    default:
    {
      X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_671 = sizeAlign_1_layptix6a1(td_8, 8);
      NI32 sz_1 = X60Qx_671.fld_0;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_45));
      NU64 X60Qx_672 = readBytes_0_run8hsnpi(buf_6, (*pos_0), sz_1);
      Value_0_valzr1t4f X60Qx_673 = scalarFromBits_0_run8hsnpi(X60Qx_672, td_8);
      result_45 = X60Qx_673;
      (*pos_0) = ((NI32)((*pos_0) + sz_1));}
    break;}
  return result_45;}
void appendField_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v* buf_7, Value_0_valzr1t4f* v_5, WireField_0_run8hsnpi* f_0){
  if ((*f_0).isComposite_0){
    appendVal_0_run8hsnpi(buf_7, (&(*v_5)), (*f_0).desc_0);}
  else {
    if ((*f_0).isString_0){
      string_0_sysvq0asl X60Qx_43;
      nimStrWasMoved((&X60Qx_43));
      if ((*v_5).kind_0 == 6){
        nimStrDestroy(X60Qx_43);
        string_0_sysvq0asl X60Qx_674 = nimStrDup((*v_5).sval_0);
        X60Qx_43 = X60Qx_674;}
      else {
        nimStrDestroy(X60Qx_43);
        string_0_sysvq0asl X60Qx_675 = dollarQ_0_valzr1t4f((&(*v_5)));
        X60Qx_43 = X60Qx_675;}
      string_0_sysvq0asl s_29 = X60Qx_43;
      nimStrWasMoved((&X60Qx_43));
      NI32 X60Qx_676 = len_4_sysvq0asl(s_29);
      appendU_0_run8hsnpi(buf_7, ((NU64)X60Qx_676), 8);
      {
        openArray_0_Ijk0jkw1_aow7lb5cq1 X60Qlf_20 = toOpenArray_2_sysvq0asl((&s_29));
        NI32 X60Qlf_21 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_677 = len_6_Iroq7kd1_aow7lb5cq1(X60Qlf_20);
            if (X60Qlf_21 < X60Qx_677){
              {
                NC8* X60Qii_2 = getQ_10_I5nt6we_aow7lb5cq1(X60Qlf_20, X60Qlf_21);
                add_0_Ibphvmo_run8hsnpi(buf_7, ((NU8)(*X60Qii_2)));}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_21));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;
      nimStrDestroy(s_29);
      nimStrDestroy(X60Qx_43);}
    else {
      NB8 X60Qx_678;
      if ((*f_0).isSeq_0){
        X60Qx_678 = (*f_0).elemVarLen_0;}
      else {
        X60Qx_678 = NIM_FALSE;}
      if (X60Qx_678){
        NI32 X60Qx_44;
        NB8 X60Qx_679;
        if ((*v_5).kind_0 == 8){
          X60Qx_679 = (!((*v_5).sq_0 == NIM_NIL));}
        else {
          X60Qx_679 = NIM_FALSE;}
        if (X60Qx_679){
          NI32 X60Qx_680 = len_3_I83dzei_arecyyj7v((*(*v_5).sq_0).d_00.elems_0);
          X60Qx_44 = X60Qx_680;}
        else {
          X60Qx_44 = 0;}
        NI32 n_10 = X60Qx_44;
        appendU_0_run8hsnpi(buf_7, ((NU64)n_10), 8);
        NI32 i_21 = 0;
        {
          while (i_21 < n_10){
            Value_0_valzr1t4f X60Qx_45;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_681 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).sq_0).d_00.elems_0, i_21);
            if ((!((*X60Qx_681) == NIM_NIL))){
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_682 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).sq_0).d_00.elems_0, i_21);
              Value_0_valzr1t4f X60Qx_683 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_682)).d_00.v_0));
              X60Qx_45 = X60Qx_683;}
            else {
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));
              Value_0_valzr1t4f X60Qx_684 = vNil_0_valzr1t4f();
              X60Qx_45 = X60Qx_684;}
            Value_0_valzr1t4f ev_1 = X60Qx_45;
            eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));
            appendVal_0_run8hsnpi(buf_7, (&ev_1), (*(*f_0).desc_0).d_00.elem_0);
            inc_1_I6wjjge_aow2h993l1((&i_21));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_1));
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_45));}}
        whileStmtLabel_3: ;}
      else {
        if ((*f_0).isSeq_0){
          NI32 X60Qx_46;
          if ((*v_5).kind_0 == 8){
            NI32 X60Qx_685 = len_3_I83dzei_arecyyj7v((*(*v_5).sq_0).d_00.elems_0);
            X60Qx_46 = X60Qx_685;}
          else {
            X60Qx_46 = 0;}
          NI32 n_11 = X60Qx_46;
          appendU_0_run8hsnpi(buf_7, ((NU64)n_11), 8);
          NB8 X60Qx_686;
          if ((*(*(*f_0).desc_0).d_00.elem_0).d_00.kind_0 == 10){
            X60Qx_686 = NIM_TRUE;}
          else {
            X60Qx_686 = ((*(*(*f_0).desc_0).d_00.elem_0).d_00.kind_0 == 11);}
          NB8 elemIsPod_0 = X60Qx_686;
          NI32 i_22 = 0;
          {
            while (i_22 < n_11){
              Value_0_valzr1t4f X60Qx_47;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_687 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).sq_0).d_00.elems_0, i_22);
              if ((!((*X60Qx_687) == NIM_NIL))){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_688 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).sq_0).d_00.elems_0, i_22);
                Value_0_valzr1t4f X60Qx_689 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_688)).d_00.v_0));
                X60Qx_47 = X60Qx_689;}
              else {
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));
                Value_0_valzr1t4f X60Qx_690 = vNil_0_valzr1t4f();
                X60Qx_47 = X60Qx_690;}
              Value_0_valzr1t4f ev_2 = X60Qx_47;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));
              seq_0_Incv1wn_arecyyj7v eb_0;
              eQwasMoved_1_I861g1c1_arecyyj7v((&eb_0));
              if (elemIsPod_0){
                eQdestroy_1_Ijx6eoq_arecyyj7v(eb_0);
                seq_0_Incv1wn_arecyyj7v X60Qx_691 = podBytes_0_run8hsnpi((&ev_2), (*(*f_0).desc_0).d_00.elem_0);
                eb_0 = X60Qx_691;}
              else {
                eQdestroy_1_Ijx6eoq_arecyyj7v(eb_0);
                seq_0_Incv1wn_arecyyj7v X60Qx_692 = newSeq_0_Ivbxvoi1_explnj22x1((*f_0).elemSize_0);
                eb_0 = X60Qx_692;
                NU64 X60Qx_693 = valToU64_0_run8hsnpi((&ev_2));
                writeBytes_0_run8hsnpi((&eb_0), 0, X60Qx_693, (*f_0).elemSize_0);}
              NI32 k_0 = 0;
              {
                while (k_0 < (*f_0).elemStride_0){
                  NU8 X60Qx_48;
                  NI32 X60Qx_694 = len_3_Izoe8zv_arecyyj7v(eb_0);
                  if (k_0 < X60Qx_694){
                    NU8* X60Qx_695 = getQ_7_Ig0r1051_arecyyj7v(eb_0, k_0);
                    X60Qx_48 = (*X60Qx_695);}
                  else {
                    X60Qx_48 = ((NU8)0u);}
                  add_0_Ibphvmo_run8hsnpi(buf_7, X60Qx_48);
                  inc_1_I6wjjge_aow2h993l1((&k_0));}}
              whileStmtLabel_5: ;
              inc_1_I6wjjge_aow2h993l1((&i_22));
              eQdestroy_1_Ijx6eoq_arecyyj7v(eb_0);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_2));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_47));}}
          whileStmtLabel_4: ;}
        else {
          if ((*f_0).isArray_0){
            NB8 X60Qx_696;
            if ((*(*(*f_0).desc_0).d_00.elem_0).d_00.kind_0 == 10){
              X60Qx_696 = NIM_TRUE;}
            else {
              X60Qx_696 = ((*(*(*f_0).desc_0).d_00.elem_0).d_00.kind_0 == 11);}
            NB8 elemIsPod_1 = X60Qx_696;
            NI32 i_23 = 0;
            {
              while (i_23 < (*f_0).arrCount_0){
                Value_0_valzr1t4f X60Qx_49;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_49));
                NB8 X60Qx_697;
                NB8 X60Qx_698;
                NB8 X60Qx_699;
                if ((*v_5).kind_0 == 9){
                  X60Qx_699 = (!((*v_5).arr_0 == NIM_NIL));}
                else {
                  X60Qx_699 = NIM_FALSE;}
                if (X60Qx_699){
                  NI32 X60Qx_700 = len_3_I83dzei_arecyyj7v((*(*v_5).arr_0).d_00.elems_0);
                  X60Qx_698 = (i_23 < X60Qx_700);}
                else {
                  X60Qx_698 = NIM_FALSE;}
                if (X60Qx_698){
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_701 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).arr_0).d_00.elems_0, i_23);
                  X60Qx_697 = (!((*X60Qx_701) == NIM_NIL));}
                else {
                  X60Qx_697 = NIM_FALSE;}
                if (X60Qx_697){
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_49));
                  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_702 = getQ_7_Ii14ync1_arecyyj7v((*(*v_5).arr_0).d_00.elems_0, i_23);
                  Value_0_valzr1t4f X60Qx_703 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*(*X60Qx_702)).d_00.v_0));
                  X60Qx_49 = X60Qx_703;}
                else {
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_49));
                  Value_0_valzr1t4f X60Qx_704 = vNil_0_valzr1t4f();
                  X60Qx_49 = X60Qx_704;}
                Value_0_valzr1t4f ev_3 = X60Qx_49;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_49));
                seq_0_Incv1wn_arecyyj7v eb_1;
                eQwasMoved_1_I861g1c1_arecyyj7v((&eb_1));
                if (elemIsPod_1){
                  eQdestroy_1_Ijx6eoq_arecyyj7v(eb_1);
                  seq_0_Incv1wn_arecyyj7v X60Qx_705 = podBytes_0_run8hsnpi((&ev_3), (*(*f_0).desc_0).d_00.elem_0);
                  eb_1 = X60Qx_705;}
                else {
                  eQdestroy_1_Ijx6eoq_arecyyj7v(eb_1);
                  seq_0_Incv1wn_arecyyj7v X60Qx_706 = newSeq_0_Ivbxvoi1_explnj22x1((*f_0).elemSize_0);
                  eb_1 = X60Qx_706;
                  NU64 X60Qx_707 = valToU64_0_run8hsnpi((&ev_3));
                  writeBytes_0_run8hsnpi((&eb_1), 0, X60Qx_707, (*f_0).elemSize_0);}
                NI32 k_1 = 0;
                {
                  while (k_1 < (*f_0).elemStride_0){
                    NU8 X60Qx_50;
                    NI32 X60Qx_708 = len_3_Izoe8zv_arecyyj7v(eb_1);
                    if (k_1 < X60Qx_708){
                      NU8* X60Qx_709 = getQ_7_Ig0r1051_arecyyj7v(eb_1, k_1);
                      X60Qx_50 = (*X60Qx_709);}
                    else {
                      X60Qx_50 = ((NU8)0u);}
                    add_0_Ibphvmo_run8hsnpi(buf_7, X60Qx_50);
                    inc_1_I6wjjge_aow2h993l1((&k_1));}}
                whileStmtLabel_7: ;
                inc_1_I6wjjge_aow2h993l1((&i_23));
                eQdestroy_1_Ijx6eoq_arecyyj7v(eb_1);
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_3));
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_49));}}
            whileStmtLabel_6: ;}
          else {
            if ((*f_0).isPod_0){
              {
                seq_0_Incv1wn_arecyyj7v X60Qtmp_122 = podBytes_0_run8hsnpi((&(*v_5)), (*f_0).desc_0);
                openArray_0_Is74e021_explnj22x1 X60Qlf_22 = toOpenArray_1_Itrkyf61_explnj22x1(X60Qtmp_122);
                NI32 X60Qlf_23 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_710 = len_6_Itc4yka_explnj22x1(X60Qlf_22);
                    if (X60Qlf_23 < X60Qx_710){
                      {
                        NU8* X60Qii_10 = getQ_10_Ikgj4ax_explnj22x1(X60Qlf_22, X60Qlf_23);
                        add_0_Ibphvmo_run8hsnpi(buf_7, (*X60Qii_10));}
                      inc_1_I6wjjge_aow2h993l1((&X60Qlf_23));}
                    else {
                      break;}}}
                whileStmtLabel_9: ;
                eQdestroy_1_Ijx6eoq_arecyyj7v(X60Qtmp_122);}
              forStmtLabel_8: ;}
            else {
              if ((*f_0).isEnum_0){
                NI64 X60Qx_711 = asInt_0_valzr1t4f((&(*v_5)));
                appendU_0_run8hsnpi(buf_7, ((NU64)((NU32)((NI32)X60Qx_711))), 4);}
              else {
                NU64 X60Qx_712 = valToU64_0_run8hsnpi((&(*v_5)));
                appendU_0_run8hsnpi(buf_7, X60Qx_712, (*f_0).wireSize_0);}}}}}}}}
Value_0_valzr1t4f scalarFromBits_0_run8hsnpi(NU64 u_2, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_9){
  Value_0_valzr1t4f result_46;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
  switch ((*td_9).d_00.kind_0){
    case 0:
    {
      NI64 X60Qx_51;
      if ((*td_9).d_00.bits_0 <= 0){
        X60Qx_51 = 64;}
      else {
        X60Qx_51 = (*td_9).d_00.bits_0;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
      Value_0_valzr1t4f X60Qx_713 = reinterpToInt_0_flaksyopx1(u_2, X60Qx_51, NIM_TRUE);
      result_46 = X60Qx_713;}
    break;
    case 1:
    {
      NI64 X60Qx_52;
      if ((*td_9).d_00.bits_0 <= 0){
        X60Qx_52 = 64;}
      else {
        X60Qx_52 = (*td_9).d_00.bits_0;}
      NI32 b_4 = X60Qx_52;
      NU64 X60Qx_53;
      if (64 <= b_4){
        X60Qx_53 = u_2;}
      else {
        X60Qx_53 = ((NU64)(u_2 & ((NU64)(((NU64)(((NU64)1u) << ((NU32)b_4))) - ((NU64)1u)))));}
      NU64 m_2 = X60Qx_53;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
      Value_0_valzr1t4f X60Qx_714 = vUInt_0_valzr1t4f(m_2, b_4);
      result_46 = X60Qx_714;}
    break;
    case 2:
    {
      if ((*td_9).d_00.bits_0 == 32){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
        NU32 X60Qx_715 = ((NU32)((NU64)(u_2 & ((NU64)4294967295u))));
        NF32 X60Qx_716;
        copyMem_0_sysvq0asl((&X60Qx_716), (&X60Qx_715), sizeof(NF32));
        Value_0_valzr1t4f X60Qx_717 = vFloat_0_valzr1t4f(((NF64)X60Qx_716), 32);
        result_46 = X60Qx_717;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
        NF64 X60Qx_718;
        copyMem_0_sysvq0asl((&X60Qx_718), (&u_2), sizeof(NF64));
        Value_0_valzr1t4f X60Qx_719 = vFloat_0_valzr1t4f(X60Qx_718, 64);
        result_46 = X60Qx_719;}}
    break;
    case 4:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
      Value_0_valzr1t4f X60Qx_720 = vBool_0_valzr1t4f((!(((NU64)(u_2 & ((NU64)1u))) == ((NU64)0u))));
      result_46 = X60Qx_720;}
    break;
    case 3:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
      Value_0_valzr1t4f X60Qx_721 = vChar_0_valzr1t4f(((NC8)((NU8)((NU64)(u_2 & ((NU64)255u))))));
      result_46 = X60Qx_721;}
    break;
    case 5:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
      Value_0_valzr1t4f X60Qx_722 = reinterpToInt_0_flaksyopx1(u_2, 64, NIM_FALSE);
      result_46 = X60Qx_722;}
    break;
    case 13:
    {
      Value_0_valzr1t4f X60Qx_54;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));
      if ((!((*td_9).d_00.elem_0 == NIM_NIL))){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));
        Value_0_valzr1t4f X60Qx_723 = scalarFromBits_0_run8hsnpi(u_2, (*td_9).d_00.elem_0);
        X60Qx_54 = X60Qx_723;}
      else {
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));
        Value_0_valzr1t4f X60Qx_724 = vNil_0_valzr1t4f();
        X60Qx_54 = X60Qx_724;}
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
      result_46 = X60Qx_54;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_54));}
    break;
    default:
    {
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_46));
      Value_0_valzr1t4f X60Qx_725 = vNil_0_valzr1t4f();
      result_46 = X60Qx_725;}
    break;}
  return result_46;}
X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi podFieldInfo_1_run8hsnpi(NU32 typeSym_2){
  X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi result_47;
  eQwasmovedQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi((&result_47));
  eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(result_47);
  seq_0_In6doa_arecyyj7v X60Qx_726 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
  seq_0_In6doa_arecyyj7v X60Qx_727 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
  result_47 = (X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi){
    .fld_0 = NIM_FALSE, .fld_1 = X60Qx_726, .fld_2 = X60Qx_727}
  ;
  if (((NU32)typeSym_2) == ((NU32)0u)){
    return result_47;}
  LoadResult_0_prorcx25w1 res_9 = tryLoadSymSafe_0_modzy18mg1(typeSym_2);
  NB8 X60Qx_118;
  NB8 X60Qx_728;
  if ((!(res_9.status_0 == 3))){
    X60Qx_728 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_729 = kind_0_nifb6mq6y1(res_9.decl_0);
    X60Qx_728 = (!(X60Qx_729 == 11));}
  if (X60Qx_728){
    X60Qx_118 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_123 = nodeTag_0_run8hsnpi(res_9.decl_0);
    NB8 X60Qx_730 = eqQ_20_sysvq0asl(X60Qtmp_123, (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_emi78vuj01)}
    );
    X60Qx_118 = (!X60Qx_730);
    nimStrDestroy(X60Qtmp_123);}
  if (X60Qx_118){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
    return result_47;}
  TypeDecl_0_decqocs071 td_16 = asTypeDecl_0_decqocs071(res_9.decl_0);
  Cursor_0_nifb6mq6y1 b_5 = td_16.body_0;
  eQwasMoved_0_nifb6mq6y1((&td_16.body_0));
  NifKind_0_nif81dubp1 X60Qx_731 = kind_0_nifb6mq6y1(b_5);
  if ((!(X60Qx_731 == 11))){
    eQdestroy_0_nifb6mq6y1((&b_5));
    eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_16));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
    return result_47;}
  string_0_sysvq0asl tag_0 = nodeTag_0_run8hsnpi(b_5);
  NB8 X60Qx_732 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_emi78vuj01)}
  );
  if (X60Qx_732){
    Cursor_0_nifb6mq6y1 oc_1 = b_5;
    eQwasMoved_0_nifb6mq6y1((&b_5));
    inc_0_nifb6mq6y1((&oc_1));
    skip_0_nifb6mq6y1((&oc_1));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_733 = kind_0_nifb6mq6y1(oc_1);
        if ((!(X60Qx_733 == 12))){
          NB8 X60Qx_119;
          NifKind_0_nif81dubp1 X60Qx_734 = kind_0_nifb6mq6y1(oc_1);
          if (X60Qx_734 == 11){
            string_0_sysvq0asl X60Qtmp_124 = nodeTag_0_run8hsnpi(oc_1);
            NB8 X60Qx_735 = eqQ_20_sysvq0asl(X60Qtmp_124, (string_0_sysvq0asl){
              .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
            );
            X60Qx_119 = X60Qx_735;
            nimStrDestroy(X60Qtmp_124);}
          else {
            X60Qx_119 = NIM_FALSE;}
          if (X60Qx_119){
            Cursor_0_nifb6mq6y1 fc_2 = eQdup_0_nifb6mq6y1(oc_1);
            inc_0_nifb6mq6y1((&fc_2));
            NU32 nm_1 = ((NU32)0u);
            NB8 X60Qx_736;
            NifKind_0_nif81dubp1 X60Qx_737 = kind_0_nifb6mq6y1(fc_2);
            if (X60Qx_737 == 4){
              X60Qx_736 = NIM_TRUE;}
            else {
              NifKind_0_nif81dubp1 X60Qx_738 = kind_0_nifb6mq6y1(fc_2);
              X60Qx_736 = (X60Qx_738 == 5);}
            if (X60Qx_736){
              NU32 X60Qx_739 = symId_0_nifb6mq6y1(fc_2);
              nm_1 = X60Qx_739;}
            skip_0_nifb6mq6y1((&fc_2));
            skip_0_nifb6mq6y1((&fc_2));
            skip_0_nifb6mq6y1((&fc_2));
            NU32 ts_0 = ((NU32)0u);
            NifKind_0_nif81dubp1 X60Qx_740 = kind_0_nifb6mq6y1(fc_2);
            if (X60Qx_740 == 4){
              NU32 X60Qx_741 = symId_0_nifb6mq6y1(fc_2);
              ts_0 = X60Qx_741;}
            add_0_I34il1q_der823rwr1((&result_47.fld_1), nm_1);
            add_0_I34il1q_der823rwr1((&result_47.fld_2), ts_0);
            eQdestroy_0_nifb6mq6y1((&fc_2));}
          skip_0_nifb6mq6y1((&oc_1));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    eQdestroy_0_nifb6mq6y1((&oc_1));}
  else {
    NB8 X60Qx_742 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
    );
    if (X60Qx_742){
      result_47.fld_0 = NIM_TRUE;
      Cursor_0_nifb6mq6y1 f_15 = b_5;
      eQwasMoved_0_nifb6mq6y1((&b_5));
      inc_0_nifb6mq6y1((&f_15));
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_743 = kind_0_nifb6mq6y1(f_15);
          if ((!(X60Qx_743 == 12))){
            NifKind_0_nif81dubp1 X60Qx_744 = kind_0_nifb6mq6y1(f_15);
            if (X60Qx_744 == 11){
              Cursor_0_nifb6mq6y1 fc_3 = eQdup_0_nifb6mq6y1(f_15);
              NU32 nm_2 = ((NU32)0u);
              string_0_sysvq0asl X60Qtmp_125 = nodeTag_0_run8hsnpi(f_15);
              NB8 X60Qx_745 = eqQ_20_sysvq0asl(X60Qtmp_125, (string_0_sysvq0asl){
                .bytes_0 = 7760642u, .more_0 = NIM_NIL}
              );
              if (X60Qx_745){
                inc_0_nifb6mq6y1((&fc_3));
                NB8 X60Qx_746;
                NifKind_0_nif81dubp1 X60Qx_747 = kind_0_nifb6mq6y1(fc_3);
                if (X60Qx_747 == 4){
                  X60Qx_746 = NIM_TRUE;}
                else {
                  NifKind_0_nif81dubp1 X60Qx_748 = kind_0_nifb6mq6y1(fc_3);
                  X60Qx_746 = (X60Qx_748 == 5);}
                if (X60Qx_746){
                  NU32 X60Qx_749 = symId_0_nifb6mq6y1(fc_3);
                  nm_2 = X60Qx_749;}
                skip_0_nifb6mq6y1((&fc_3));}
              NU32 ts_1 = ((NU32)0u);
              NifKind_0_nif81dubp1 X60Qx_750 = kind_0_nifb6mq6y1(fc_3);
              if (X60Qx_750 == 4){
                NU32 X60Qx_751 = symId_0_nifb6mq6y1(fc_3);
                ts_1 = X60Qx_751;}
              add_0_I34il1q_der823rwr1((&result_47.fld_1), nm_2);
              add_0_I34il1q_der823rwr1((&result_47.fld_2), ts_1);
              nimStrDestroy(X60Qtmp_125);
              eQdestroy_0_nifb6mq6y1((&fc_3));}
            skip_0_nifb6mq6y1((&f_15));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      eQdestroy_0_nifb6mq6y1((&f_15));}}
  nimStrDestroy(tag_0);
  eQdestroy_0_nifb6mq6y1((&b_5));
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_16));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
  return result_47;
  nimStrDestroy(tag_0);
  eQdestroy_0_nifb6mq6y1((&b_5));
  eQdestroyQ_SX54ypeX44ecl0decqocs071_0_decqocs071((&td_16));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);
  return result_47;}
void grantNoDerefs_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_3){
  if (e_3 == NIM_NIL){
    return;}
  string_0_sysvq0asl X60Qtmp_126 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I8845991054942562031_intzsnzax)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  NB8 dbg_0 = eqQ_20_sysvq0asl(X60Qtmp_126, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  NI32 i_24 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_752;
      NI32 X60Qx_753 = len_3_In63jw61_aow7lb5cq1((*e_3).d_00.args_0);
      if (i_24 < X60Qx_753){
        NI32 X60Qx_754 = len_3_Irjnvku_run8hsnpi((*e_3).d_00.noDerefOffs_0);
        X60Qx_752 = (i_24 < X60Qx_754);}
      else {
        X60Qx_752 = NIM_FALSE;}
      if (X60Qx_752){
        {
          WireField_0_run8hsnpi* X60Qx_755 = getQ_7_Iko57h9_aow7lb5cq1((*e_3).d_00.args_0, i_24);
          WireField_0_run8hsnpi X60QconstRefTemp_0 = (*X60Qx_755);
          WireField_0_run8hsnpi f_16 = eQdupQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&X60QconstRefTemp_0));
          NB8 X60Qx_756;
          NB8 X60Qx_757;
          if ((!f_16.isArenaPtr_0)){
            X60Qx_757 = NIM_TRUE;}
          else {
            X60Qx_757 = (f_16.desc_0 == NIM_NIL);}
          if (X60Qx_757){
            X60Qx_756 = NIM_TRUE;}
          else {
            X60Qx_756 = (((NU32)f_16.typeSym_0) == ((NU32)0u));}
          if (X60Qx_756){
            inc_1_I6wjjge_aow2h993l1((&i_24));
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_16));
            goto continueLabel_1;}
          X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi info_1 = podFieldInfo_1_run8hsnpi(f_16.typeSym_0);
          seq_0_Ift2sne_aow7lb5cq1 offs_2 = fieldOffsets_0_layptix6a1(f_16.desc_0, 8);
          NB8 X60Qx_758;
          if ((!(info_1.fld_1.len_0 == (*f_16.desc_0).d_00.fields_0.len_0))){
            X60Qx_758 = NIM_TRUE;}
          else {
            X60Qx_758 = (!(offs_2.len_0 == (*f_16.desc_0).d_00.fields_0.len_0));}
          if (X60Qx_758){
            inc_1_I6wjjge_aow2h993l1((&i_24));
            eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_2);
            eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_1);
            eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_16));
            goto continueLabel_1;}
          NI32 j_0 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_759 = len_3_I5m68tr1_aow7lb5cq1((*f_16.desc_0).d_00.fields_0);
              if (j_0 < X60Qx_759){
                X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_760 = getQ_7_I45w7c91_aow7lb5cq1((*f_16.desc_0).d_00.fields_0, j_0);
                if ((*(*X60Qx_760)).d_00.kind_0 == 5){
                  NU32* X60Qx_761 = getQ_7_I2v00yv1_arecyyj7v(info_1.fld_1, j_0);
                  X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 X60Qtmptup_11 = fieldVerdict_0_der823rwr1((*e_3).d_00.sym_0, i_24, (*X60Qx_761));
                  AnVerdict_0_der823rwr1 v_8 = X60Qtmptup_11.fld_0;
                  AnGiveUp_0_der823rwr1 why_1 = X60Qtmptup_11.fld_1;
                  string_0_sysvq0asl at_0 = X60Qtmptup_11.fld_2;
                  nimStrWasMoved((&X60Qtmptup_11.fld_2));
                  NU32* X60Qx_762 = getQ_7_I2v00yv1_arecyyj7v(info_1.fld_1, j_0);
                  NB8 X60Qx_763 = fieldNeverTouched_0_der823rwr1((*e_3).d_00.sym_0, i_24, (*X60Qx_762));
                  if (X60Qx_763){
                    seq_0_Ift2sne_aow7lb5cq1* X60Qx_764 = getQ_7_Iurb46i_aow7lb5cq1((*e_3).d_00.noDerefOffs_0, i_24);
                    NI32* X60Qx_765 = getQ_7_Ir8kccm_aow7lb5cq1(offs_2, j_0);
                    add_0_I8kd4i4_aow7lb5cq1(X60Qx_764, (*X60Qx_765));}
                  else {
                    if (dbg_0){
                      string_0_sysvq0asl* X60Qx_766 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*e_3).d_00.sym_0);
                      string_0_sysvq0asl cn_0 = nimStrDup((*X60Qx_766));
                      extractBasename_1_symkyk35i1((&cn_0));
                      NU32* X60Qx_767 = getQ_7_I2v00yv1_arecyyj7v(info_1.fld_1, j_0);
                      string_0_sysvq0asl* X60Qx_768 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, (*X60Qx_767));
                      string_0_sysvq0asl fn_0 = nimStrDup((*X60Qx_768));
                      extractBasename_1_symkyk35i1((&fn_0));
                      string_0_sysvq0asl X60Qdesugar_22 = dollarQ_2_sysvq0asl(i_24);
                      NI32 X60Qx_769 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1847599358u, .more_0 = (&strlit_0_I17300657558726488198_intzsnzax)}
                      );
                      NI32 X60Qx_770 = len_4_sysvq0asl(cn_0);
                      NI32 X60Qx_771 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I4311268661432640709_run8hsnpi)}
                      );
                      NI32 X60Qx_772 = len_4_sysvq0asl(X60Qdesugar_22);
                      NI32 X60Qx_773 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 3022850u, .more_0 = NIM_NIL}
                      );
                      NI32 X60Qx_774 = len_4_sysvq0asl(fn_0);
                      NI32 X60Qx_775 = len_4_sysvq0asl((string_0_sysvq0asl){
                        .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl X60Qdesugar_23 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_769 + X60Qx_770)) + X60Qx_771)) + X60Qx_772)) + X60Qx_773)) + X60Qx_774)) + X60Qx_775)));
                      add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
                        .bytes_0 = 1847599358u, .more_0 = (&strlit_0_I17300657558726488198_intzsnzax)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_23), cn_0);
                      add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
                        .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I4311268661432640709_run8hsnpi)}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_23), X60Qdesugar_22);
                      add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
                        .bytes_0 = 3022850u, .more_0 = NIM_NIL}
                      );
                      add_2_sysvq0asl((&X60Qdesugar_23), fn_0);
                      add_2_sysvq0asl((&X60Qdesugar_23), (string_0_sysvq0asl){
                        .bytes_0 = 540680195u, .more_0 = NIM_NIL}
                      );
                      string_0_sysvq0asl m_3 = X60Qdesugar_23;
                      nimStrWasMoved((&X60Qdesugar_23));
                      if (v_8 == 1){
                        add_2_sysvq0asl((&m_3), (string_0_sysvq0asl){
                          .bytes_0 = 1431262462u, .more_0 = (&strlit_0_I7498181021040919538_run8hsnpi)}
                        );}
                      else {
                        string_0_sysvq0asl X60Qtmp_128 = giveUpName_0_der823rwr1(why_1);
                        string_0_sysvq0asl X60Qtmp_127 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                          .bytes_0 = 1263425022u, .more_0 = (&strlit_0_I4863082586268738407_run8hsnpi)}
                        , X60Qtmp_128);
                        add_2_sysvq0asl((&m_3), X60Qtmp_127);
                        NI32 X60Qx_776 = len_4_sysvq0asl(at_0);
                        if (0 < X60Qx_776){
                          string_0_sysvq0asl X60Qtmp_129 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
                            .bytes_0 = 1952522494u, .more_0 = (&strlit_0_I12933864966599503538_der823rwr1)}
                          , at_0);
                          add_2_sysvq0asl((&m_3), X60Qtmp_129);
                          nimStrDestroy(X60Qtmp_129);}
                        add_2_sysvq0asl((&m_3), (string_0_sysvq0asl){
                          .bytes_0 = 1881678078u, .more_0 = (&strlit_0_I5868316469075155783_run8hsnpi)}
                        );
                        nimStrDestroy(X60Qtmp_127);
                        nimStrDestroy(X60Qtmp_128);}
                      string_0_sysvq0asl X60Qtmp_130 = ampQ_0_sysvq0asl(m_3, (string_0_sysvq0asl){
                        .bytes_0 = 2561u, .more_0 = NIM_NIL}
                      );
                      write_0_syn1lfpjv(stderr, X60Qtmp_130);
                      nimStrDestroy(X60Qtmp_130);
                      nimStrDestroy(m_3);
                      nimStrDestroy(X60Qdesugar_23);
                      nimStrDestroy(X60Qdesugar_22);
                      nimStrDestroy(fn_0);
                      nimStrDestroy(cn_0);}}
                  nimStrDestroy(at_0);
                  eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_run8hsnpi(X60Qtmptup_11);}
                inc_1_I6wjjge_aow2h993l1((&j_0));}
              else {
                break;}}}
          whileStmtLabel_2: ;
          inc_1_I6wjjge_aow2h993l1((&i_24));
          eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_2);
          eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_1);
          eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&f_16));}
        continueLabel_1: ;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(X60Qtmp_126);}
NB8 hasNoDerefGrant_0_run8hsnpi(X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_4){
  NB8 result_48;
  result_48 = NIM_FALSE;
  if (e_4 == NIM_NIL){
    return result_48;}
  NI32 i_26 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_777 = len_3_Irjnvku_run8hsnpi((*e_4).d_00.noDerefOffs_0);
      if (i_26 < X60Qx_777){
        seq_0_Ift2sne_aow7lb5cq1* X60Qx_778 = getQ_7_Iurb46i_aow7lb5cq1((*e_4).d_00.noDerefOffs_0, i_26);
        if (0 < (*X60Qx_778).len_0){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_26));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_48;}
Value_0_valzr1t4f synthPodValue_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v buf_8, NI32 off_4, NU32 typeSym_3, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_10){
  Value_0_valzr1t4f result_49;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
  X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi info_2 = podFieldInfo_1_run8hsnpi(typeSym_3);
  seq_0_Ift2sne_aow7lb5cq1 offs_3 = fieldOffsets_0_layptix6a1(td_10, 8);
  void* X60Qx_779 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1));
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_131 = ((X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_779);
  seq_0_In6doa_arecyyj7v X60Qx_780 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
  seq_0_Iw8xl5b1_arecyyj7v X60Qx_781 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
  (*X60Qtmp_131) = (X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1){
    .r_00 = 0, .d_00 = (ObjBox_Obj_0_valzr1t4f){
      .typeSym_0 = typeSym_3, .names_0 = X60Qx_780, .cells_0 = X60Qx_781}}
  ;
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_2 = X60Qtmp_131;
  NI32 i_27 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_782;
      NI32 X60Qx_783 = len_3_I5m68tr1_aow7lb5cq1((*td_10).d_00.fields_0);
      if (i_27 < X60Qx_783){
        NI32 X60Qx_784 = len_3_I0v1j8d_aow7lb5cq1(offs_3);
        X60Qx_782 = (i_27 < X60Qx_784);}
      else {
        X60Qx_782 = NIM_FALSE;}
      if (X60Qx_782){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_785 = getQ_7_I45w7c91_aow7lb5cq1((*td_10).d_00.fields_0, i_27);
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* fd_5 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*X60Qx_785));
        NU32 X60Qx_55;
        NI32 X60Qx_786 = len_3_I6y2imo_arecyyj7v(info_2.fld_1);
        if (i_27 < X60Qx_786){
          NU32* X60Qx_787 = getQ_7_I2v00yv1_arecyyj7v(info_2.fld_1, i_27);
          X60Qx_55 = (*X60Qx_787);}
        else {
          X60Qx_55 = ((NU32)0u);}
        NU32 nm_3 = X60Qx_55;
        Value_0_valzr1t4f cv_2;
        eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_2));
        NB8 X60Qx_788;
        NB8 X60Qx_789;
        if ((*fd_5).d_00.kind_0 == 10){
          X60Qx_789 = NIM_TRUE;}
        else {
          X60Qx_789 = ((*fd_5).d_00.kind_0 == 11);}
        if (X60Qx_789){
          X60Qx_788 = NIM_TRUE;}
        else {
          NB8 X60Qx_790;
          NB8 X60Qx_791;
          if ((*fd_5).d_00.kind_0 == 13){
            X60Qx_791 = (!((*fd_5).d_00.elem_0 == NIM_NIL));}
          else {
            X60Qx_791 = NIM_FALSE;}
          if (X60Qx_791){
            NB8 X60Qx_792;
            if ((*(*fd_5).d_00.elem_0).d_00.kind_0 == 10){
              X60Qx_792 = NIM_TRUE;}
            else {
              X60Qx_792 = ((*(*fd_5).d_00.elem_0).d_00.kind_0 == 11);}
            X60Qx_790 = X60Qx_792;}
          else {
            X60Qx_790 = NIM_FALSE;}
          X60Qx_788 = X60Qx_790;}
        if (X60Qx_788){
          NU32 X60Qx_56;
          NI32 X60Qx_793 = len_3_I6y2imo_arecyyj7v(info_2.fld_2);
          if (i_27 < X60Qx_793){
            NU32* X60Qx_794 = getQ_7_I2v00yv1_arecyyj7v(info_2.fld_2, i_27);
            X60Qx_56 = (*X60Qx_794);}
          else {
            X60Qx_56 = ((NU32)0u);}
          NU32 fts_1 = X60Qx_56;
          X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_57;
          eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&X60Qx_57));
          if ((*fd_5).d_00.kind_0 == 13){
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qx_57);
            X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_795 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*fd_5).d_00.elem_0);
            X60Qx_57 = X60Qx_795;}
          else {
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qx_57);
            X60Qx_57 = fd_5;
            eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&fd_5));}
          X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* ad_0 = X60Qx_57;
          eQwasmovedQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((&X60Qx_57));
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_2));
          NI32* X60Qx_796 = getQ_7_Ir8kccm_aow7lb5cq1(offs_3, i_27);
          Value_0_valzr1t4f X60Qx_797 = synthPodValue_0_run8hsnpi(buf_8, ((NI32)(off_4 + (*X60Qx_796))), fts_1, ad_0);
          cv_2 = X60Qx_797;
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(ad_0);
          eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qx_57);}
        else {
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_2));
          NI32* X60Qx_798 = getQ_7_Ir8kccm_aow7lb5cq1(offs_3, i_27);
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_799 = sizeAlign_1_layptix6a1(fd_5, 8);
          NU64 X60Qx_800 = readBytes_0_run8hsnpi(buf_8, ((NI32)(off_4 + (*X60Qx_798))), X60Qx_799.fld_0);
          Value_0_valzr1t4f X60Qx_801 = scalarFromBits_0_run8hsnpi(X60Qx_800, fd_5);
          cv_2 = X60Qx_801;}
        add_0_I34il1q_der823rwr1((&(*box_2).d_00.names_0), nm_3);
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_802 = newCell_0_valzr1t4f((&cv_2));
        add_0_Ijpw0mu_flaksyopx1((&(*box_2).d_00.cells_0), X60Qx_802);
        inc_1_I6wjjge_aow2h993l1((&i_27));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&cv_2));
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(fd_5);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  Value_0_valzr1t4f X60Qx_58;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_58));
  NB8 X60Qx_803;
  if (info_2.fld_0){
    X60Qx_803 = NIM_TRUE;}
  else {
    X60Qx_803 = ((*td_10).d_00.kind_0 == 11);}
  if (X60Qx_803){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_58));
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_132 = box_2;
    eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&box_2));
    X60Qx_58 = (Value_0_valzr1t4f){
      .kind_0 = 10, .obj_0 = X60Qtmp_132}
    ;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_58));
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_133 = box_2;
    eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&box_2));
    X60Qx_58 = (Value_0_valzr1t4f){
      .kind_0 = 11, .obj_0 = X60Qtmp_133}
    ;}
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_49));
  result_49 = X60Qx_58;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_58));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_58));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_2);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_3);
  eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_2);
  return result_49;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_58));
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_2);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_3);
  eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(info_2);
  return result_49;}
Value_0_valzr1t4f unpackReturn_0_run8hsnpi(seq_0_Incv1wn_arecyyj7v buf_9, WireField_0_run8hsnpi* f_1){
  Value_0_valzr1t4f result_50;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
  if ((*f_1).isComposite_0){
    NI32 pos_1 = 0;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
    Value_0_valzr1t4f X60Qx_804 = readVal_0_run8hsnpi(buf_9, (&pos_1), (*f_1).desc_0, (*f_1).typeSym_0);
    result_50 = X60Qx_804;}
  else {
    if ((*f_1).isString_0){
      NU64 X60Qx_805 = readBytes_0_run8hsnpi(buf_9, 0, 8);
      NI32 n_12 = ((NI32)X60Qx_805);
      string_0_sysvq0asl s_34 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NI32 i_28 = 0;
      {
        while (i_28 < n_12){
          NU8* X60Qx_806 = getQ_7_Ig0r1051_arecyyj7v(buf_9, ((NI32)(8 + i_28)));
          add_1_sysvq0asl((&s_34), ((NC8)((NU8)(*X60Qx_806))));
          inc_1_I6wjjge_aow2h993l1((&i_28));}}
      whileStmtLabel_0: ;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
      Value_0_valzr1t4f X60Qx_807 = vStr_0_valzr1t4f(s_34);
      result_50 = X60Qx_807;
      nimStrDestroy(s_34);}
    else {
      NB8 X60Qx_808;
      if ((*f_1).isSeq_0){
        X60Qx_808 = (*f_1).elemVarLen_0;}
      else {
        X60Qx_808 = NIM_FALSE;}
      if (X60Qx_808){
        NI32 pos_2 = 0;
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
        Value_0_valzr1t4f X60Qx_809 = readVal_0_run8hsnpi(buf_9, (&pos_2), (*f_1).desc_0, ((NU32)0u));
        result_50 = X60Qx_809;}
      else {
        if ((*f_1).isSeq_0){
          NU64 X60Qx_810 = readBytes_0_run8hsnpi(buf_9, 0, 8);
          NI32 n_13 = ((NI32)X60Qx_810);
          NB8 X60Qx_811;
          if ((*(*(*f_1).desc_0).d_00.elem_0).d_00.kind_0 == 10){
            X60Qx_811 = NIM_TRUE;}
          else {
            X60Qx_811 = ((*(*(*f_1).desc_0).d_00.elem_0).d_00.kind_0 == 11);}
          NB8 elemIsPod_2 = X60Qx_811;
          void* X60Qx_812 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1));
          X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_134 = ((X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_812);
          seq_0_Iw8xl5b1_arecyyj7v X60Qx_813 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
          (*X60Qtmp_134) = (X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1){
            .r_00 = 0, .d_00 = (SeqBox_Obj_0_valzr1t4f){
              .elems_0 = X60Qx_813, .flat_0 = NIM_NIL}}
          ;
          X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* sb_1 = X60Qtmp_134;
          NI32 i_29 = 0;
          {
            while (i_29 < n_13){
              NI32 eoff_0 = ((NI32)(8 + ((NI32)(i_29 * (*f_1).elemStride_0))));
              Value_0_valzr1t4f ev_4;
              eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_4));
              if (elemIsPod_2){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_4));
                Value_0_valzr1t4f X60Qx_814 = synthPodValue_0_run8hsnpi(buf_9, eoff_0, (*f_1).elemTypeSym_0, (*(*f_1).desc_0).d_00.elem_0);
                ev_4 = X60Qx_814;}
              else {
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_4));
                NU64 X60Qx_815 = readBytes_0_run8hsnpi(buf_9, eoff_0, (*f_1).elemSize_0);
                Value_0_valzr1t4f X60Qx_816 = scalarFromBits_0_run8hsnpi(X60Qx_815, (*(*f_1).desc_0).d_00.elem_0);
                ev_4 = X60Qx_816;}
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_817 = newCell_0_valzr1t4f((&ev_4));
              add_0_Ijpw0mu_flaksyopx1((&(*sb_1).d_00.elems_0), X60Qx_817);
              inc_1_I6wjjge_aow2h993l1((&i_29));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_4));}}
          whileStmtLabel_1: ;
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
          X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_135 = sb_1;
          eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi((&sb_1));
          result_50 = (Value_0_valzr1t4f){
            .kind_0 = 8, .sq_0 = X60Qtmp_135}
          ;
          eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(sb_1);}
        else {
          if ((*f_1).isArray_0){
            NB8 X60Qx_818;
            if ((*(*(*f_1).desc_0).d_00.elem_0).d_00.kind_0 == 10){
              X60Qx_818 = NIM_TRUE;}
            else {
              X60Qx_818 = ((*(*(*f_1).desc_0).d_00.elem_0).d_00.kind_0 == 11);}
            NB8 elemIsPod_3 = X60Qx_818;
            void* X60Qx_819 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1));
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_136 = ((X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1*)X60Qx_819);
            seq_0_Iw8xl5b1_arecyyj7v X60Qx_820 = newSeqUninit_0_I1tbjnk1_arecyyj7v(0);
            (*X60Qtmp_136) = (X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1){
              .r_00 = 0, .d_00 = (ArrBox_Obj_0_valzr1t4f){
                .elems_0 = X60Qx_820, .lo_0 = 0, .flat_0 = NIM_NIL}}
            ;
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* ab_0 = X60Qtmp_136;
            NI32 i_30 = 0;
            {
              while (i_30 < (*f_1).arrCount_0){
                NI32 eoff_1 = ((NI32)(i_30 * (*f_1).elemStride_0));
                Value_0_valzr1t4f ev_5;
                eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_5));
                if (elemIsPod_3){
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_5));
                  Value_0_valzr1t4f X60Qx_821 = synthPodValue_0_run8hsnpi(buf_9, eoff_1, (*f_1).elemTypeSym_0, (*(*f_1).desc_0).d_00.elem_0);
                  ev_5 = X60Qx_821;}
                else {
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_5));
                  NU64 X60Qx_822 = readBytes_0_run8hsnpi(buf_9, eoff_1, (*f_1).elemSize_0);
                  Value_0_valzr1t4f X60Qx_823 = scalarFromBits_0_run8hsnpi(X60Qx_822, (*(*f_1).desc_0).d_00.elem_0);
                  ev_5 = X60Qx_823;}
                X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_824 = newCell_0_valzr1t4f((&ev_5));
                add_0_Ijpw0mu_flaksyopx1((&(*ab_0).d_00.elems_0), X60Qx_824);
                inc_1_I6wjjge_aow2h993l1((&i_30));
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&ev_5));}}
            whileStmtLabel_2: ;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
            X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_137 = ab_0;
            eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&ab_0));
            result_50 = (Value_0_valzr1t4f){
              .kind_0 = 9, .arr_0 = X60Qtmp_137}
            ;
            eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(ab_0);}
          else {
            if ((*f_1).isForeignPtr_0){
              NU64 a_5 = readBytes_0_run8hsnpi(buf_9, 0, 8);
              if (a_5 == ((NU64)0u)){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
                Value_0_valzr1t4f X60Qx_825 = vPtrLoc_0_valzr1t4f(NIM_NIL);
                result_50 = X60Qx_825;}
              else {
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
                void* X60Qx_826 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1));
                X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_138 = ((X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1*)X60Qx_826);
                (*X60Qtmp_138) = (X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1){
                  .r_00 = 0, .d_00 = (FlatRegion_Obj_0_valzr1t4f){
                    .kind_0 = 6, .haddr_0 = a_5, .hlen_0 = -1}}
                ;
                Value_0_valzr1t4f X60Qx_827 = vPtrReg_0_valzr1t4f(X60Qtmp_138, ((NI32)0), ((NI16)8), 0);
                result_50 = X60Qx_827;
                eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qtmp_138);}}
            else {
              if ((*f_1).isPod_0){
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
                Value_0_valzr1t4f X60Qx_828 = synthPodValue_0_run8hsnpi(buf_9, 0, (*f_1).typeSym_0, (*f_1).desc_0);
                result_50 = X60Qx_828;}
              else {
                if ((*f_1).isEnum_0){
                  NU64 X60Qx_829 = readBytes_0_run8hsnpi(buf_9, 0, 4);
                  NI32 o_1 = ((NI32)((NI32)((NU64)(X60Qx_829 & ((NU64)4294967295u)))));
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
                  Value_0_valzr1t4f X60Qx_830 = vEnum_0_valzr1t4f(o_1, (*f_1).enumSym_0);
                  result_50 = X60Qx_830;}
                else {
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&result_50));
                  NU64 X60Qx_831 = readBytes_0_run8hsnpi(buf_9, 0, (*f_1).wireSize_0);
                  Value_0_valzr1t4f X60Qx_832 = scalarFromBits_0_run8hsnpi(X60Qx_831, (*f_1).desc_0);
                  result_50 = X60Qx_832;}}}}}}}}
  return result_50;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* argObjBox_0_run8hsnpi(Value_0_valzr1t4f* v_6){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* result_51;
  eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&result_51));
  switch ((*v_6).kind_0){
    case 11:
    case 10:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_51);
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_833 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((*v_6).obj_0);
      result_51 = X60Qx_833;}
    break;
    case 12:
    {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_59;
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_59));
      NB8 X60Qx_834;
      if ((!((*v_6).rf_0 == NIM_NIL))){
        NB8 X60Qx_835;
        if ((*(*v_6).rf_0).d_00.v_0.kind_0 == 11){
          X60Qx_835 = NIM_TRUE;}
        else {
          X60Qx_835 = ((*(*v_6).rf_0).d_00.v_0.kind_0 == 10);}
        X60Qx_834 = X60Qx_835;}
      else {
        X60Qx_834 = NIM_FALSE;}
      if (X60Qx_834){
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_59);
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_836 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((*(*v_6).rf_0).d_00.v_0.obj_0);
        X60Qx_59 = X60Qx_836;}
      else {
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_59);
        X60Qx_59 = NIM_NIL;}
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_51);
      result_51 = X60Qx_59;
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_59));
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_59);}
    break;
    case 13:
    {
      X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_60;
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_60));
      NB8 X60Qx_837;
      if ((!((*v_6).loc_0 == NIM_NIL))){
        NB8 X60Qx_838;
        if ((*(*v_6).loc_0).d_00.v_0.kind_0 == 11){
          X60Qx_838 = NIM_TRUE;}
        else {
          X60Qx_838 = ((*(*v_6).loc_0).d_00.v_0.kind_0 == 10);}
        X60Qx_837 = X60Qx_838;}
      else {
        X60Qx_837 = NIM_FALSE;}
      if (X60Qx_837){
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_60);
        X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_839 = eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((*(*v_6).loc_0).d_00.v_0.obj_0);
        X60Qx_60 = X60Qx_839;}
      else {
        eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_60);
        X60Qx_60 = NIM_NIL;}
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_51);
      result_51 = X60Qx_60;
      eQwasmovedQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_60));
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_60);}
    break;
    default:
    {
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_51);
      result_51 = NIM_NIL;}
    break;}
  return result_51;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* argArrBox_0_run8hsnpi(Value_0_valzr1t4f* v_7){
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* result_52;
  eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&result_52));
  switch ((*v_7).kind_0){
    case 9:
    {
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_52);
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_840 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((*v_7).arr_0);
      result_52 = X60Qx_840;}
    break;
    case 13:
    {
      NB8 X60Qx_841;
      NB8 X60Qx_842;
      if ((!((*v_7).loc_0 == NIM_NIL))){
        X60Qx_842 = ((*(*v_7).loc_0).d_00.v_0.kind_0 == 9);}
      else {
        X60Qx_842 = NIM_FALSE;}
      if (X60Qx_842){
        NI32 X60Qx_843 = base_0_valzr1t4f((&(*v_7)));
        X60Qx_841 = (X60Qx_843 == 0);}
      else {
        X60Qx_841 = NIM_FALSE;}
      if (X60Qx_841){
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_52);
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_844 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((*(*v_7).loc_0).d_00.v_0.arr_0);
        result_52 = X60Qx_844;}
      else {
        NB8 X60Qx_120;
        NB8 X60Qx_121;
        X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_139 = region_0_valzr1t4f((&(*v_7)));
        if ((!(X60Qtmp_139 == NIM_NIL))){
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_140 = region_0_valzr1t4f((&(*v_7)));
          X60Qx_121 = ((*X60Qtmp_140).d_00.kind_0 == 2);
          eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qtmp_140);}
        else {
          X60Qx_121 = NIM_FALSE;}
        if (X60Qx_121){
          NI32 X60Qx_845 = foff_0_valzr1t4f((&(*v_7)));
          X60Qx_120 = (X60Qx_845 == ((NI32)0));}
        else {
          X60Qx_120 = NIM_FALSE;}
        if (X60Qx_120){
          eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_52);
          X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* X60Qtmp_141 = region_0_valzr1t4f((&(*v_7)));
          X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_846 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((*X60Qtmp_141).d_00.abox_0);
          result_52 = X60Qx_846;
          eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qtmp_141);}
        else {
          eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_52);
          result_52 = NIM_NIL;}
        eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qtmp_139);}}
    break;
    case 12:
    {
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_61;
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_61));
      NB8 X60Qx_847;
      if ((!((*v_7).rf_0 == NIM_NIL))){
        X60Qx_847 = ((*(*v_7).rf_0).d_00.v_0.kind_0 == 9);}
      else {
        X60Qx_847 = NIM_FALSE;}
      if (X60Qx_847){
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_61);
        X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* X60Qx_848 = eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((*(*v_7).rf_0).d_00.v_0.arr_0);
        X60Qx_61 = X60Qx_848;}
      else {
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_61);
        X60Qx_61 = NIM_NIL;}
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_52);
      result_52 = X60Qx_61;
      eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi((&X60Qx_61));
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qx_61);}
    break;
    default:
    {
      eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(result_52);
      result_52 = NIM_NIL;}
    break;}
  return result_52;}
NB8 applyWritebackArray_0_run8hsnpi(Value_0_valzr1t4f* arg_0, seq_0_Incv1wn_arecyyj7v buf_10, NI32 off_5, WireField_0_run8hsnpi* f_2){
  NB8 result_53;
  NB8 X60Qx_849;
  if ((*f_2).desc_0 == NIM_NIL){
    X60Qx_849 = NIM_TRUE;}
  else {
    X60Qx_849 = ((*(*f_2).desc_0).d_00.elem_0 == NIM_NIL);}
  if (X60Qx_849){
    return NIM_FALSE;}
  NB8 X60Qx_850;
  NB8 X60Qx_851;
  if ((*f_2).arrCount_0 <= 0){
    X60Qx_851 = NIM_TRUE;}
  else {
    X60Qx_851 = ((*f_2).elemSize_0 <= 0);}
  if (X60Qx_851){
    X60Qx_850 = NIM_TRUE;}
  else {
    X60Qx_850 = ((*f_2).elemStride_0 < (*f_2).elemSize_0);}
  if (X60Qx_850){
    return NIM_FALSE;}
  NB8 X60Qx_852;
  if (off_5 < 0){
    X60Qx_852 = NIM_TRUE;}
  else {
    X60Qx_852 = (buf_10.len_0 < ((NI32)(off_5 + ((NI32)((*f_2).arrCount_0 * (*f_2).elemStride_0)))));}
  if (X60Qx_852){
    return NIM_FALSE;}
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* box_3 = argArrBox_0_run8hsnpi((&(*arg_0)));
  if (box_3 == NIM_NIL){
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_3);
    return NIM_FALSE;}
  if ((!((*box_3).d_00.elems_0.len_0 == (*f_2).arrCount_0))){
    eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_3);
    return NIM_FALSE;}
  seq_0_I50urnw_croph25r5 vals_0 = newSeqUninit_0_I8oufjc_croph25r5(0);
  NI32 i_31 = 0;
  {
    while (i_31 < (*f_2).arrCount_0){
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_853 = getQ_7_Ii14ync1_arecyyj7v((*box_3).d_00.elems_0, i_31);
      if ((*X60Qx_853) == NIM_NIL){
        eQdestroy_1_Inxd7ue1_croph25r5(vals_0);
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_3);
        return NIM_FALSE;}
      NU64 X60Qx_854 = readBytes_0_run8hsnpi(buf_10, ((NI32)(off_5 + ((NI32)(i_31 * (*f_2).elemStride_0)))), (*f_2).elemSize_0);
      Value_0_valzr1t4f nv_0 = scalarFromBits_0_run8hsnpi(X60Qx_854, (*(*f_2).desc_0).d_00.elem_0);
      if (nv_0.kind_0 == 0){
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
        eQdestroy_1_Inxd7ue1_croph25r5(vals_0);
        eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_3);
        return NIM_FALSE;}
      Value_0_valzr1t4f X60Qtmp_142 = nv_0;
      eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));
      add_0_Itre92n_intzsnzax((&vals_0), X60Qtmp_142);
      inc_1_I6wjjge_aow2h993l1((&i_31));
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_0));}}
  whileStmtLabel_0: ;
  i_31 = 0;
  {
    while (i_31 < (*f_2).arrCount_0){
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_855 = getQ_7_Ii14ync1_arecyyj7v((*box_3).d_00.elems_0, i_31);
      Value_0_valzr1t4f* X60Qlhs_143 = (&(*(*X60Qx_855)).d_00.v_0);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_856 = getQ_7_Ii14ync1_arecyyj7v((*box_3).d_00.elems_0, i_31);
      Value_0_valzr1t4f X60Qlhs_144 = (*(*X60Qx_856)).d_00.v_0;
      Value_0_valzr1t4f* X60Qx_857 = getQ_7_Ine8yq71_intzsnzax(vals_0, i_31);
      Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_857);
      Value_0_valzr1t4f X60Qx_858 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
      (*X60Qlhs_143) = X60Qx_858;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_144));
      inc_1_I6wjjge_aow2h993l1((&i_31));}}
  whileStmtLabel_1: ;
  result_53 = NIM_TRUE;
  eQdestroy_1_Inxd7ue1_croph25r5(vals_0);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_3);
  return result_53;
  eQdestroy_1_Inxd7ue1_croph25r5(vals_0);
  eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_3);
  return result_53;}
void applyWriteback_0_run8hsnpi(Value_0_valzr1t4f* arg_1, seq_0_Incv1wn_arecyyj7v buf_11, NI32 off_6, WireField_0_run8hsnpi* f_3){
  if ((*f_3).isPod_0){
    X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_4 = argObjBox_0_run8hsnpi((&(*arg_1)));
    if (box_4 == NIM_NIL){
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_4);
      return;}
    X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_4 = flObjRegion_0_flaksyopx1(box_4);
    if (r_4 == NIM_NIL){
      eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_4);
      eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_4);
      return;}
    NI32 k_2 = 0;
    {
      while (k_2 < (*f_3).wireSize_0){
        NU8* X60Qx_859 = getQ_7_Ig0r1051_arecyyj7v(buf_11, ((NI32)(off_6 + k_2)));
        setByteAt_0_flaksyopx1(r_4, k_2, (*X60Qx_859));
        inc_1_I6wjjge_aow2h993l1((&k_2));}}
    whileStmtLabel_0: ;
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_4);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_4);}
  else {
    X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_0 = NIM_NIL;
    NB8 X60Qx_860;
    if ((*arg_1).kind_0 == 13){
      X60Qx_860 = (!((*arg_1).loc_0 == NIM_NIL));}
    else {
      X60Qx_860 = NIM_FALSE;}
    if (X60Qx_860){
      eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi(cell_0);
      X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* X60Qx_861 = eQdupQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi((*arg_1).loc_0);
      cell_0 = X60Qx_861;}
    if ((!(cell_0 == NIM_NIL))){
      Value_0_valzr1t4f* X60Qlhs_145 = (&(*cell_0).d_00.v_0);
      NU64 X60Qx_862 = readBytes_0_run8hsnpi(buf_11, off_6, (*f_3).wireSize_0);
      Value_0_valzr1t4f X60Qlhs_146 = scalarFromBits_0_run8hsnpi(X60Qx_862, (*f_3).desc_0);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qlhs_145)));
      (*X60Qlhs_145) = X60Qlhs_146;}
    eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi(cell_0);}}
NB8 applyWritebackArena_0_run8hsnpi(Value_0_valzr1t4f* arg_2, seq_0_Incv1wn_arecyyj7v buf_12, NI32 off_7, WireField_0_run8hsnpi* f_4, ArenaMat_0_arecyyj7v* m_1){
  NB8 result_54;
  if ((*f_4).desc_0 == NIM_NIL){
    return NIM_FALSE;}
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* box_5 = argObjBox_0_run8hsnpi((&(*arg_2)));
  if (box_5 == NIM_NIL){
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
    return NIM_FALSE;}
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* td_17 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*f_4).desc_0);
  {
    while (NIM_TRUE){
      NB8 X60Qx_863;
      if ((!(td_17 == NIM_NIL))){
        X60Qx_863 = ((*td_17).d_00.kind_0 == 13);}
      else {
        X60Qx_863 = NIM_FALSE;}
      if (X60Qx_863){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qlhs_147 = td_17;
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_864 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*td_17).d_00.elem_0);
        td_17 = X60Qx_864;
        eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qlhs_147);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (td_17 == NIM_NIL){
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_17);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
    return NIM_FALSE;}
  seq_0_Ift2sne_aow7lb5cq1 offs_4 = fieldOffsets_0_layptix6a1(td_17, 8);
  if ((!(offs_4.len_0 == (*td_17).d_00.fields_0.len_0))){
    eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_17);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
    return NIM_FALSE;}
  NI32 X60Qx_865 = len_3_I83dzei_arecyyj7v((*box_5).d_00.cells_0);
  NI32 X60Qx_866 = len_3_I5m68tr1_aow7lb5cq1((*td_17).d_00.fields_0);
  if (X60Qx_865 < X60Qx_866){
    eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_17);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
    return NIM_FALSE;}
  seq_0_Ie7vbta_run8hsnpi newPtrs_0 = newSeqUninit_0_I32zp0x_run8hsnpi(0);
  NI32 i_32 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_867 = len_3_I5m68tr1_aow7lb5cq1((*td_17).d_00.fields_0);
      if (i_32 < X60Qx_867){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_868 = getQ_7_I45w7c91_aow7lb5cq1((*td_17).d_00.fields_0, i_32);
        if ((*(*X60Qx_868)).d_00.kind_0 == 5){
          NI32* X60Qx_869 = getQ_7_Ir8kccm_aow7lb5cq1(offs_4, i_32);
          NU64 X60Qx_870 = readBytes_0_run8hsnpi(buf_12, ((NI32)(off_7 + (*X60Qx_869))), 8);
          NU32 a_6 = ((NU32)X60Qx_870);
          X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_871 = getQ_7_Ii14ync1_arecyyj7v((*box_5).d_00.cells_0, i_32);
          X60Qt_0_IAtupleSX56alue0valzr1t4fAbool_arecyyj7v X60Qtmptup_12 = unmaterializePtr_0_arecyyj7v((&(*m_1)), a_6, (&(*(*X60Qx_871)).d_00.v_0));
          Value_0_valzr1t4f nv_1 = X60Qtmptup_12.fld_0;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmptup_12.fld_0));
          NB8 ok_6 = X60Qtmptup_12.fld_1;
          if ((!ok_6)){
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_1));
            eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_run8hsnpi((&X60Qtmptup_12));
            eQdestroy_1_I2vp2bj_run8hsnpi(newPtrs_0);
            eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
            eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_17);
            eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
            return NIM_FALSE;}
          Value_0_valzr1t4f X60Qtmp_148 = nv_1;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_1));
          add_0_Ivy8r7k1_run8hsnpi((&newPtrs_0), (X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi){
            .fld_0 = i_32, .fld_1 = X60Qtmp_148}
          );
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&nv_1));
          eQdestroyQ_AtupleSX56alue0valzr1t4fAbool_0_run8hsnpi((&X60Qtmptup_12));}
        inc_1_I6wjjge_aow2h993l1((&i_32));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* r_5 = flObjRegion_0_flaksyopx1(box_5);
  if (r_5 == NIM_NIL){
    eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_5);
    eQdestroy_1_I2vp2bj_run8hsnpi(newPtrs_0);
    eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
    eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_17);
    eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
    return NIM_FALSE;}
  i_32 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_872 = len_3_I5m68tr1_aow7lb5cq1((*td_17).d_00.fields_0);
      if (i_32 < X60Qx_872){
        X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_873 = getQ_7_I45w7c91_aow7lb5cq1((*td_17).d_00.fields_0, i_32);
        if ((!((*(*X60Qx_873)).d_00.kind_0 == 5))){
          X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1** X60Qx_874 = getQ_7_I45w7c91_aow7lb5cq1((*td_17).d_00.fields_0, i_32);
          X60Qt_0_IAtupleAiS32ZAiS32_aow7lb5cq1 X60Qx_875 = sizeAlign_1_layptix6a1((*X60Qx_874), 8);
          NI32 sz_2 = X60Qx_875.fld_0;
          NI32 k_3 = 0;
          {
            while (NIM_TRUE){
              NB8 X60Qx_876;
              if (k_3 < sz_2){
                NI32* X60Qx_877 = getQ_7_Ir8kccm_aow7lb5cq1(offs_4, i_32);
                X60Qx_876 = (((NI32)((*X60Qx_877) + k_3)) < (*f_4).wireSize_0);}
              else {
                X60Qx_876 = NIM_FALSE;}
              if (X60Qx_876){
                NI32* X60Qx_878 = getQ_7_Ir8kccm_aow7lb5cq1(offs_4, i_32);
                NI32* X60Qx_879 = getQ_7_Ir8kccm_aow7lb5cq1(offs_4, i_32);
                NU8* X60Qx_880 = getQ_7_Ig0r1051_arecyyj7v(buf_12, ((NI32)(((NI32)(off_7 + (*X60Qx_879))) + k_3)));
                setByteAt_0_flaksyopx1(r_5, ((NI32)((*X60Qx_878) + k_3)), (*X60Qx_880));
                inc_1_I6wjjge_aow2h993l1((&k_3));}
              else {
                break;}}}
          whileStmtLabel_3: ;}
        inc_1_I6wjjge_aow2h993l1((&i_32));}
      else {
        break;}}}
  whileStmtLabel_2: ;
  {
    openArray_0_Icv4v4b1_run8hsnpi X60Qlf_24 = toOpenArray_1_Io2cvnr_run8hsnpi(newPtrs_0);
    NI32 X60Qlf_25 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_881 = len_6_Ivyewcw1_run8hsnpi(X60Qlf_24);
        if (X60Qlf_25 < X60Qx_881){
          {
            X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* X60Qii_6 = getQ_10_Ijhkrt71_run8hsnpi(X60Qlf_24, X60Qlf_25);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_882 = getQ_7_Ii14ync1_arecyyj7v((*box_5).d_00.cells_0, (*X60Qii_6).fld_0);
            Value_0_valzr1t4f* X60Qlhs_149 = (&(*(*X60Qx_882)).d_00.v_0);
            X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_883 = getQ_7_Ii14ync1_arecyyj7v((*box_5).d_00.cells_0, (*X60Qii_6).fld_0);
            Value_0_valzr1t4f X60Qlhs_150 = (*(*X60Qx_883)).d_00.v_0;
            Value_0_valzr1t4f X60Qx_884 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*X60Qii_6).fld_1));
            (*X60Qlhs_149) = X60Qx_884;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_150));}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_25));}
        else {
          break;}}}
    whileStmtLabel_5: ;}
  forStmtLabel_4: ;
  result_54 = NIM_TRUE;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_5);
  eQdestroy_1_I2vp2bj_run8hsnpi(newPtrs_0);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_17);
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
  return result_54;
  eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(r_5);
  eQdestroy_1_I2vp2bj_run8hsnpi(newPtrs_0);
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(offs_4);
  eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(td_17);
  eQdestroyQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(box_5);
  return result_54;}
N_NIMCALL(NB8, cabiGenOwns_0_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* p_8, NU32 sym_10){
  NB8 result_55;
  NB8 X60Qx_885;
  if (((void*)p_8) == NIM_NIL){
    X60Qx_885 = NIM_TRUE;}
  else {
    Rtti_0_sysvq0asl* X60QvtableTemp_1 = (*p_8).d_00.Q.vt_00;
    NB8 X60Qx_886;
    if (2 < (*X60QvtableTemp_1).dl_0){
      X60Qx_886 = ((*X60QvtableTemp_1).dy_0[2] == 4174408912u);}
    else {
      X60Qx_886 = NIM_FALSE;}
    X60Qx_885 = X60Qx_886;}
  if ((!X60Qx_885)){
    nimInvalidObjConv((string_0_sysvq0asl){
      .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I18334688814084301714_run8hsnpi)}
    );}
  X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* gp_0 = eQdupQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi((*((X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi**)(&p_8))));
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_151 = getOrDefault_1_Imr3kd01_run8hsnpi((*gp_0).d_00.table_0, sym_10, NIM_NIL);
  result_55 = (!(X60Qtmp_151 == NIM_NIL));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qtmp_151);
  eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_0);
  return result_55;
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qtmp_151);
  eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_0);
  return result_55;}
N_NIMCALL(NB8, cabiGenInvoke_0_run8hsnpi)(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* p_9, NU32 sym_11, string_0_sysvq0asl base_5, seq_0_I50urnw_croph25r5 args_5, Value_0_valzr1t4f* res_5){
  NB8 result_56;
  NB8 X60Qx_887;
  if (((void*)p_9) == NIM_NIL){
    X60Qx_887 = NIM_TRUE;}
  else {
    Rtti_0_sysvq0asl* X60QvtableTemp_2 = (*p_9).d_00.Q.vt_00;
    NB8 X60Qx_888;
    if (2 < (*X60QvtableTemp_2).dl_0){
      X60Qx_888 = ((*X60QvtableTemp_2).dy_0[2] == 4174408912u);}
    else {
      X60Qx_888 = NIM_FALSE;}
    X60Qx_887 = X60Qx_888;}
  if ((!X60Qx_887)){
    nimInvalidObjConv((string_0_sysvq0asl){
      .bytes_0 = 1717924606u, .more_0 = (&strlit_0_I18334688814084301714_run8hsnpi)}
    );}
  X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* gp_1 = eQdupQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi((*((X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi**)(&p_9))));
  declineBegin_0_croph25r5(base_5);
  NB8 X60Qx_889 = jitTraceLog_0_run8hsnpi();
  if (X60Qx_889){
    string_0_sysvq0asl* X60Qx_890 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_11);
    string_0_sysvq0asl X60Qdesugar_24 = nimStrDup((*X60Qx_890));
    NI32 X60Qx_891 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I17755916622381260779_run8hsnpi)}
    );
    NI32 X60Qx_892 = len_4_sysvq0asl(X60Qdesugar_24);
    NI32 X60Qx_893 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_25 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_891 + X60Qx_892)) + X60Qx_893)));
    add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I17755916622381260779_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_25), X60Qdesugar_24);
    add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_25);
    nimStrDestroy(X60Qdesugar_25);
    nimStrDestroy(X60Qdesugar_24);}
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* e_15 = getOrDefault_1_Imr3kd01_run8hsnpi((*gp_1).d_00.table_0, sym_11, NIM_NIL);
  if (e_15 == NIM_NIL){
    NB8 X60Qx_894 = jitTraceLog_0_run8hsnpi();
    if (X60Qx_894){
      string_0_sysvq0asl* X60Qx_895 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, sym_11);
      string_0_sysvq0asl X60Qdesugar_26 = nimStrDup((*X60Qx_895));
      NI32 X60Qx_896 = len_0_Ifyaclq_run8hsnpi((*gp_1).d_00.table_0);
      string_0_sysvq0asl X60Qdesugar_27 = dollarQ_2_sysvq0asl(X60Qx_896);
      NI32 X60Qx_897 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      NI32 X60Qx_898 = len_4_sysvq0asl(X60Qdesugar_26);
      NI32 X60Qx_899 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I6867780705510740199_run8hsnpi)}
      );
      NI32 X60Qx_900 = len_4_sysvq0asl(X60Qdesugar_27);
      NI32 X60Qx_901 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1852121342u, .more_0 = (&strlit_0_I6591882555819548044_run8hsnpi)}
      );
      string_0_sysvq0asl X60Qdesugar_28 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_897 + X60Qx_898)) + X60Qx_899)) + X60Qx_900)) + X60Qx_901)));
      add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_28), X60Qdesugar_26);
      add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I6867780705510740199_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_28), X60Qdesugar_27);
      add_2_sysvq0asl((&X60Qdesugar_28), (string_0_sysvq0asl){
        .bytes_0 = 1852121342u, .more_0 = (&strlit_0_I6591882555819548044_run8hsnpi)}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_28);
      nimStrDestroy(X60Qdesugar_28);
      nimStrDestroy(X60Qdesugar_27);
      nimStrDestroy(X60Qdesugar_26);}
    declineNote_0_croph25r5(2, (string_0_sysvq0asl){
      .bytes_0 = 1953459966u, .more_0 = (&strlit_0_I8323340401993503906_run8hsnpi)}
    );
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;}
  if ((!(args_5.len_0 == (*e_15).d_00.args_0.len_0))){
    NI32 X60Qx_902 = len_3_I4n9kvq_intzsnzax(args_5);
    string_0_sysvq0asl X60Qdesugar_29 = dollarQ_2_sysvq0asl(X60Qx_902);
    NI32 X60Qx_903 = len_3_In63jw61_aow7lb5cq1((*e_15).d_00.args_0);
    string_0_sysvq0asl X60Qdesugar_30 = dollarQ_2_sysvq0asl(X60Qx_903);
    NI32 X60Qx_904 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1769103870u, .more_0 = (&strlit_0_I17183936099286931213_run8hsnpi)}
    );
    NI32 X60Qx_905 = len_4_sysvq0asl(X60Qdesugar_29);
    NI32 X60Qx_906 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I18255814566225474086_run8hsnpi)}
    );
    NI32 X60Qx_907 = len_4_sysvq0asl(X60Qdesugar_30);
    NI32 X60Qx_908 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I2164128916027878689_run8hsnpi)}
    );
    string_0_sysvq0asl X60Qdesugar_31 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_904 + X60Qx_905)) + X60Qx_906)) + X60Qx_907)) + X60Qx_908)));
    add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
      .bytes_0 = 1769103870u, .more_0 = (&strlit_0_I17183936099286931213_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_31), X60Qdesugar_29);
    add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
      .bytes_0 = 1918968062u, .more_0 = (&strlit_0_I18255814566225474086_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_31), X60Qdesugar_30);
    add_2_sysvq0asl((&X60Qdesugar_31), (string_0_sysvq0asl){
      .bytes_0 = 1852776702u, .more_0 = (&strlit_0_I2164128916027878689_run8hsnpi)}
    );
    declineNote_0_croph25r5(2, X60Qdesugar_31);
    nimStrDestroy(X60Qdesugar_31);
    nimStrDestroy(X60Qdesugar_30);
    nimStrDestroy(X60Qdesugar_29);
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;
    nimStrDestroy(X60Qdesugar_31);
    nimStrDestroy(X60Qdesugar_30);
    nimStrDestroy(X60Qdesugar_29);}
  if ((!(*gp_1).d_00.opened_0)){
    (*gp_1).d_00.opened_0 = NIM_TRUE;
    NI32 X60Qx_909 = len_4_sysvq0asl((*gp_1).d_00.soPath_0);
    if (0 < X60Qx_909){
      string_0_sysvq0asl path_2 = nimStrDup((*gp_1).d_00.soPath_0);
      NC8* X60Qx_910 = toCString_0_sysvq0asl((&path_2));
      void* X60Qx_911 = dlopen(X60Qx_910, ((int)2));
      (*gp_1).d_00.handle_0 = X60Qx_911;
      nimStrDestroy(path_2);}}
  if ((*gp_1).d_00.handle_0 == NIM_NIL){
    NB8 X60Qx_912 = jitTraceLog_0_run8hsnpi();
    if (X60Qx_912){
      string_0_sysvq0asl X60Qdesugar_32 = nimStrDup((*gp_1).d_00.soPath_0);
      NI32 X60Qx_913 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      NI32 X60Qx_914 = len_4_sysvq0asl(base_5);
      NI32 X60Qx_915 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I11555090815403677726_run8hsnpi)}
      );
      NI32 X60Qx_916 = len_4_sysvq0asl(X60Qdesugar_32);
      NI32 X60Qx_917 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_33 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_913 + X60Qx_914)) + X60Qx_915)) + X60Qx_916)) + X60Qx_917)));
      add_2_sysvq0asl((&X60Qdesugar_33), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_33), base_5);
      add_2_sysvq0asl((&X60Qdesugar_33), (string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I11555090815403677726_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_33), X60Qdesugar_32);
      add_2_sysvq0asl((&X60Qdesugar_33), (string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_33);
      nimStrDestroy(X60Qdesugar_33);
      nimStrDestroy(X60Qdesugar_32);}
    string_0_sysvq0asl X60Qtmp_152 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869374718u, .more_0 = (&strlit_0_I8932411087278802551_run8hsnpi)}
    , (*gp_1).d_00.soPath_0);
    declineNote_0_croph25r5(6, X60Qtmp_152);
    nimStrDestroy(X60Qtmp_152);
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;
    nimStrDestroy(X60Qtmp_152);}
  if ((!(*e_15).d_00.resolved_0)){
    (*e_15).d_00.resolved_0 = NIM_TRUE;
    string_0_sysvq0asl nm_4 = nimStrDup((*e_15).d_00.shimSym_0);
    NC8* X60Qx_918 = toCString_0_sysvq0asl((&nm_4));
    X60Qt_0_IApointerZAR0ZAiS32ZAiS32ZAcdeclZAfalseZAR32_run8hsnpi X60Qx_919 = dlsym((*gp_1).d_00.handle_0, X60Qx_918);
    (*e_15).d_00.fn_0 = X60Qx_919;
    nimStrDestroy(nm_4);}
  if (((void*)(*e_15).d_00.fn_0) == NIM_NIL){
    NB8 X60Qx_920 = jitTraceLog_0_run8hsnpi();
    if (X60Qx_920){
      string_0_sysvq0asl X60Qdesugar_34 = nimStrDup((*e_15).d_00.shimSym_0);
      NI32 X60Qx_921 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      NI32 X60Qx_922 = len_4_sysvq0asl(base_5);
      NI32 X60Qx_923 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I15980317227653665914_run8hsnpi)}
      );
      NI32 X60Qx_924 = len_4_sysvq0asl(X60Qdesugar_34);
      NI32 X60Qx_925 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_35 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_921 + X60Qx_922)) + X60Qx_923)) + X60Qx_924)) + X60Qx_925)));
      add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
        .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I13879001563082667471_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_35), base_5);
      add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
        .bytes_0 = 540680446u, .more_0 = (&strlit_0_I15980317227653665914_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_35), X60Qdesugar_34);
      add_2_sysvq0asl((&X60Qdesugar_35), (string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_35);
      nimStrDestroy(X60Qdesugar_35);
      nimStrDestroy(X60Qdesugar_34);}
    string_0_sysvq0asl X60Qtmp_153 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1936483582u, .more_0 = (&strlit_0_I9471465608874713306_run8hsnpi)}
    , (*e_15).d_00.shimSym_0);
    declineNote_0_croph25r5(6, X60Qtmp_153);
    nimStrDestroy(X60Qtmp_153);
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;
    nimStrDestroy(X60Qtmp_153);}
  NB8 anyArena_0 = NIM_FALSE;
  {
    openArray_0_Iczu4791_aow7lb5cq1 X60Qlf_26 = toOpenArray_1_I0ef4be1_aow7lb5cq1((*e_15).d_00.args_0);
    NI32 X60Qlf_27 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_926 = len_6_Ier6z6r1_aow7lb5cq1(X60Qlf_26);
        if (X60Qlf_27 < X60Qx_926){
          {
            WireField_0_run8hsnpi* X60Qii_2 = getQ_10_Id2924z_aow7lb5cq1(X60Qlf_26, X60Qlf_27);
            NB8 X60Qx_927;
            NB8 X60Qx_928;
            if ((*X60Qii_2).isArenaRef_0){
              X60Qx_928 = NIM_TRUE;}
            else {
              X60Qx_928 = (*X60Qii_2).isArenaPtr_0;}
            if (X60Qx_928){
              X60Qx_927 = NIM_TRUE;}
            else {
              X60Qx_927 = (*X60Qii_2).isPtrArena_0;}
            if (X60Qx_927){
              anyArena_0 = NIM_TRUE;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_27));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  seq_0_Isge9lx_arecyyj7v X60Qx_929 = newSeqUninit_0_Iglb3hm1_arecyyj7v(0);
  seq_0_Idhq52f_arecyyj7v X60Qx_930 = newSeqUninit_0_I7mggr11_arecyyj7v(0);
  seq_0_Ijes23h1_arecyyj7v X60Qx_931 = newSeqUninit_0_I1oegnq1_arecyyj7v(0);
  ArenaMat_0_arecyyj7v m_4 = (ArenaMat_0_arecyyj7v){
    .a_0 = ((X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v*)NIM_NIL), .seen_0 = X60Qx_929, .blocks_0 = X60Qx_930, .regions_0 = X60Qx_931}
  ;
  seq_0_Iq1shzq1_run8hsnpi arenaSync_0 = newSeqUninit_0_Ie5g2lj_run8hsnpi(0);
  if (anyArena_0){
    if ((*gp_1).d_00.arena_0 == NIM_NIL){
      X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v** X60Qlhs_154 = (&(*gp_1).d_00.arena_0);
      X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* X60Qlhs_155 = newArena_0_arewp645e1(((NI32)1048576));
      eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_run8hsnpi((*X60Qlhs_154));
      (*X60Qlhs_154) = X60Qlhs_155;}
    arenaReset_0_arewp645e1((*gp_1).d_00.arena_0);
    eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
    ArenaMat_0_arecyyj7v X60Qx_932 = initArenaMat_0_arecyyj7v((*gp_1).d_00.arena_0);
    m_4 = X60Qx_932;}
  seq_0_Incv1wn_arecyyj7v inbuf_1 = newSeq_0_Ivbxvoi1_explnj22x1(0);
  NI32 i_33 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_933 = len_3_In63jw61_aow7lb5cq1((*e_15).d_00.args_0);
      if (i_33 < X60Qx_933){
        Value_0_valzr1t4f* X60Qx_934 = getQ_7_Ine8yq71_intzsnzax(args_5, i_33);
        Value_0_valzr1t4f X60QconstRefTemp_0 = (*X60Qx_934);
        Value_0_valzr1t4f av_0 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60QconstRefTemp_0));
        WireField_0_run8hsnpi* X60Qx_935 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_33);
        if ((*X60Qx_935).isArenaRef_0){
          NB8 X60Qx_936;
          if (av_0.kind_0 == 13){
            X60Qx_936 = (!(av_0.loc_0 == NIM_NIL));}
          else {
            X60Qx_936 = NIM_FALSE;}
          if (X60Qx_936){
            Value_0_valzr1t4f X60Qlhs_156 = av_0;
            Value_0_valzr1t4f X60Qx_937 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*av_0.loc_0).d_00.v_0));
            av_0 = X60Qx_937;
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_156));}
          void* box_6 = materialize_0_arecyyj7v((&m_4), (&av_0));
          appendU_0_run8hsnpi((&inbuf_1), ((NU64)((NU32)box_6)), 8);
          Value_0_valzr1t4f X60Qtmp_157 = av_0;
          eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&av_0));
          add_0_Ii05ltt1_run8hsnpi((&arenaSync_0), (X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi){
            .fld_0 = X60Qtmp_157, .fld_1 = box_6}
          );}
        else {
          WireField_0_run8hsnpi* X60Qx_938 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_33);
          if ((*X60Qx_938).isPtrArena_0){
            WireField_0_run8hsnpi* X60Qx_939 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_33);
            void* pa_0 = materializePtr_0_arecyyj7v((&m_4), (&av_0), NIM_FALSE, (*X60Qx_939).elemSize_0);
            if (pa_0 == NIM_NIL){
              string_0_sysvq0asl X60Qdesugar_36 = dollarQ_2_sysvq0asl(i_33);
              NI32 X60Qx_940 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1920233726u, .more_0 = (&strlit_0_I3278143169533289085_run8hsnpi)}
              );
              NI32 X60Qx_941 = len_4_sysvq0asl(X60Qdesugar_36);
              NI32 X60Qx_942 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1948269310u, .more_0 = (&strlit_0_I13592592763606903879_run8hsnpi)}
              );
              string_0_sysvq0asl X60Qdesugar_37 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_940 + X60Qx_941)) + X60Qx_942)));
              add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
                .bytes_0 = 1920233726u, .more_0 = (&strlit_0_I3278143169533289085_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_37), X60Qdesugar_36);
              add_2_sysvq0asl((&X60Qdesugar_37), (string_0_sysvq0asl){
                .bytes_0 = 1948269310u, .more_0 = (&strlit_0_I13592592763606903879_run8hsnpi)}
              );
              declineNote_0_croph25r5(3, X60Qdesugar_37);
              nimStrDestroy(X60Qdesugar_37);
              nimStrDestroy(X60Qdesugar_36);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&av_0));
              eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
              eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
              eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
              eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
              eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
              return NIM_FALSE;
              nimStrDestroy(X60Qdesugar_37);
              nimStrDestroy(X60Qdesugar_36);}
            appendU_0_run8hsnpi((&inbuf_1), ((NU64)((NU32)pa_0)), 8);}
          else {
            WireField_0_run8hsnpi* X60Qx_943 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_33);
            if ((*X60Qx_943).isArenaPtr_0){
              NB8 X60Qx_944;
              if (av_0.kind_0 == 13){
                X60Qx_944 = (!(av_0.loc_0 == NIM_NIL));}
              else {
                X60Qx_944 = NIM_FALSE;}
              if (X60Qx_944){
                Value_0_valzr1t4f X60Qlhs_158 = av_0;
                Value_0_valzr1t4f X60Qx_945 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*av_0.loc_0).d_00.v_0));
                av_0 = X60Qx_945;
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_158));}
              WireField_0_run8hsnpi* X60Qx_946 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_33);
              NI32 X60Qx_947 = max_2_sysvq0asl((*X60Qx_946).wireSize_0, 1);
              seq_0_Incv1wn_arecyyj7v pb_0 = newSeq_0_Ivbxvoi1_explnj22x1(X60Qx_947);
              seq_0_Ift2sne_aow7lb5cq1 nd_1 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
              NB8 X60Qx_948;
              NI32 X60Qx_949 = len_3_Irjnvku_run8hsnpi((*e_15).d_00.noDerefOffs_0);
              if (i_33 < X60Qx_949){
                NB8 X60Qx_950 = grantsHonoured_0_croph25r5((*gp_1).d_00.xp_0);
                X60Qx_948 = X60Qx_950;}
              else {
                X60Qx_948 = NIM_FALSE;}
              NB8 honoured_0 = X60Qx_948;
              NB8 X60Qx_951;
              NI32 X60Qx_952 = len_3_Irjnvku_run8hsnpi((*e_15).d_00.noDerefOffs_0);
              if (i_33 < X60Qx_952){
                seq_0_Ift2sne_aow7lb5cq1* X60Qx_953 = getQ_7_Iurb46i_aow7lb5cq1((*e_15).d_00.noDerefOffs_0, i_33);
                X60Qx_951 = (0 < (*X60Qx_953).len_0);}
              else {
                X60Qx_951 = NIM_FALSE;}
              if (X60Qx_951){
                if (honoured_0){
                  eQdestroy_1_Iv9ij5i1_aow7lb5cq1(nd_1);
                  seq_0_Ift2sne_aow7lb5cq1* X60Qx_954 = getQ_7_Iurb46i_aow7lb5cq1((*e_15).d_00.noDerefOffs_0, i_33);
                  seq_0_Ift2sne_aow7lb5cq1 X60Qx_955 = eQdup_1_Iplow11_aow7lb5cq1((*X60Qx_954));
                  nd_1 = X60Qx_955;
                  bump_0_croph25r5(cAnHonoured_0_der823rwr1, 1);}
                else {
                  bump_0_croph25r5(cAnRevoked_0_der823rwr1, 1);}}
              WireField_0_run8hsnpi* X60Qx_956 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_33);
              NB8 X60Qx_957 = packPodArena_0_run8hsnpi((&pb_0), 0, (&av_0), (*X60Qx_956).desc_0, (&m_4), nd_1);
              if ((!X60Qx_957)){
                string_0_sysvq0asl X60Qdesugar_38 = dollarQ_2_sysvq0asl(i_33);
                NI32 X60Qx_958 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I1069507577923700528_run8hsnpi)}
                );
                NI32 X60Qx_959 = len_4_sysvq0asl(X60Qdesugar_38);
                NI32 X60Qx_960 = len_4_sysvq0asl((string_0_sysvq0asl){
                  .bytes_0 = 1881160446u, .more_0 = (&strlit_0_I8163890759512608411_run8hsnpi)}
                );
                string_0_sysvq0asl X60Qdesugar_39 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_958 + X60Qx_959)) + X60Qx_960)));
                add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
                  .bytes_0 = 1701995006u, .more_0 = (&strlit_0_I1069507577923700528_run8hsnpi)}
                );
                add_2_sysvq0asl((&X60Qdesugar_39), X60Qdesugar_38);
                add_2_sysvq0asl((&X60Qdesugar_39), (string_0_sysvq0asl){
                  .bytes_0 = 1881160446u, .more_0 = (&strlit_0_I8163890759512608411_run8hsnpi)}
                );
                declineNote_0_croph25r5(3, X60Qdesugar_39);
                nimStrDestroy(X60Qdesugar_39);
                nimStrDestroy(X60Qdesugar_38);
                eQdestroy_1_Iv9ij5i1_aow7lb5cq1(nd_1);
                eQdestroy_1_Ijx6eoq_arecyyj7v(pb_0);
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&av_0));
                eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
                eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
                eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
                eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
                eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
                return NIM_FALSE;
                nimStrDestroy(X60Qdesugar_39);
                nimStrDestroy(X60Qdesugar_38);}
              NI32 pk_0 = 0;
              {
                while (NIM_TRUE){
                  WireField_0_run8hsnpi* X60Qx_961 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_33);
                  if (pk_0 < (*X60Qx_961).wireSize_0){
                    NU8* X60Qx_962 = getQ_7_Ig0r1051_arecyyj7v(pb_0, pk_0);
                    add_0_Ibphvmo_run8hsnpi((&inbuf_1), (*X60Qx_962));
                    inc_1_I6wjjge_aow2h993l1((&pk_0));}
                  else {
                    break;}}}
              whileStmtLabel_4: ;
              eQdestroy_1_Iv9ij5i1_aow7lb5cq1(nd_1);
              eQdestroy_1_Ijx6eoq_arecyyj7v(pb_0);}
            else {
              WireField_0_run8hsnpi* X60Qx_963 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_33);
              if ((*X60Qx_963).isVar_0){
                NB8 X60Qx_964;
                if (av_0.kind_0 == 13){
                  X60Qx_964 = (!(av_0.loc_0 == NIM_NIL));}
                else {
                  X60Qx_964 = NIM_FALSE;}
                if (X60Qx_964){
                  Value_0_valzr1t4f X60Qlhs_159 = av_0;
                  Value_0_valzr1t4f X60Qx_965 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*av_0.loc_0).d_00.v_0));
                  av_0 = X60Qx_965;
                  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_159));}
                else {
                  NB8 X60Qx_966;
                  if (av_0.kind_0 == 12){
                    X60Qx_966 = (!(av_0.rf_0 == NIM_NIL));}
                  else {
                    X60Qx_966 = NIM_FALSE;}
                  if (X60Qx_966){
                    Value_0_valzr1t4f X60Qlhs_160 = av_0;
                    Value_0_valzr1t4f X60Qx_967 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*av_0.rf_0).d_00.v_0));
                    av_0 = X60Qx_967;
                    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qlhs_160));}}}
              WireField_0_run8hsnpi* X60Qx_968 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, i_33);
              WireField_0_run8hsnpi X60QconstRefTemp_1 = (*X60Qx_968);
              appendField_0_run8hsnpi((&inbuf_1), (&av_0), (&X60QconstRefTemp_1));}}}
        inc_1_I6wjjge_aow2h993l1((&i_33));
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&av_0));}
      else {
        break;}}}
  whileStmtLabel_3: ;
  NB8 X60Qx_969;
  if (anyArena_0){
    X60Qx_969 = arenaMatFailed_0_arecyyj7v;}
  else {
    X60Qx_969 = NIM_FALSE;}
  if (X60Qx_969){
    bump_0_croph25r5(cArenaDeclines_0_run8hsnpi, 1);
    NB8 X60Qx_970;
    if (hybridArenaTrace_0_run8hsnpi){
      NI32 X60Qx_971 = countOf_0_croph25r5(cArenaDeclines_0_run8hsnpi);
      X60Qx_970 = (X60Qx_971 <= 3);}
    else {
      X60Qx_970 = NIM_FALSE;}
    if (X60Qx_970){
      string_0_sysvq0asl X60Qdesugar_40 = arenaReport_0_arecyyj7v();
      NI32 X60Qx_972 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I15611778738489493776_run8hsnpi)}
      );
      NI32 X60Qx_973 = len_4_sysvq0asl(base_5);
      NI32 X60Qx_974 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
      );
      NI32 X60Qx_975 = len_4_sysvq0asl(X60Qdesugar_40);
      NI32 X60Qx_976 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      string_0_sysvq0asl X60Qdesugar_41 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_972 + X60Qx_973)) + X60Qx_974)) + X60Qx_975)) + X60Qx_976)));
      add_2_sysvq0asl((&X60Qdesugar_41), (string_0_sysvq0asl){
        .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I15611778738489493776_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_41), base_5);
      add_2_sysvq0asl((&X60Qdesugar_41), (string_0_sysvq0asl){
        .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_41), X60Qdesugar_40);
      add_2_sysvq0asl((&X60Qdesugar_41), (string_0_sysvq0asl){
        .bytes_0 = 2561u, .more_0 = NIM_NIL}
      );
      write_0_syn1lfpjv(stderr, X60Qdesugar_41);
      nimStrDestroy(X60Qdesugar_41);
      nimStrDestroy(X60Qdesugar_40);}
    eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
    eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
    eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
    eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
    return NIM_FALSE;}
  NB8 X60Qx_977;
  NB8 X60Qx_978;
  if (anyArena_0){
    X60Qx_978 = hybridArenaTrace_0_run8hsnpi;}
  else {
    X60Qx_978 = NIM_FALSE;}
  if (X60Qx_978){
    NI32 X60Qx_979 = countOf_0_croph25r5(cHybridCalls_0_run8hsnpi);
    X60Qx_977 = (X60Qx_979 < 4);}
  else {
    X60Qx_977 = NIM_FALSE;}
  if (X60Qx_977){
    string_0_sysvq0asl X60Qdesugar_42 = arenaReport_0_arecyyj7v();
    NI32 X60Qx_980 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I15730584599751133452_run8hsnpi)}
    );
    NI32 X60Qx_981 = len_4_sysvq0asl(base_5);
    NI32 X60Qx_982 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    NI32 X60Qx_983 = len_4_sysvq0asl(X60Qdesugar_42);
    NI32 X60Qx_984 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_43 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_980 + X60Qx_981)) + X60Qx_982)) + X60Qx_983)) + X60Qx_984)));
    add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
      .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I15730584599751133452_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_43), base_5);
    add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
      .bytes_0 = 8193u, .more_0 = NIM_NIL}
    );
    add_2_sysvq0asl((&X60Qdesugar_43), X60Qdesugar_42);
    add_2_sysvq0asl((&X60Qdesugar_43), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_43);
    nimStrDestroy(X60Qdesugar_43);
    nimStrDestroy(X60Qdesugar_42);}
  NI32 X60Qx_985 = len_3_Izoe8zv_arecyyj7v(inbuf_1);
  if (X60Qx_985 == 0){
    add_0_Ibphvmo_run8hsnpi((&inbuf_1), ((NU8)0u));}
  NU8* X60Qx_986 = getQ_7_Ig0r1051_arecyyj7v(inbuf_1, 0);
  void* inp_0 = ((void*)(&(*X60Qx_986)));
  NI32 cap_0 = max_2_sysvq0asl((*e_15).d_00.outSize_0, 1);
  seq_0_Incv1wn_arecyyj7v outbuf_1 = newSeq_0_Ivbxvoi1_explnj22x1(cap_0);
  NU8* X60Qx_987 = getQ_7_Ig0r1051_arecyyj7v(outbuf_1, 0);
  NI32 need_0 = (*e_15).d_00.fn_0(inp_0, ((void*)(&(*X60Qx_987))), cap_0);
  if (cap_0 < need_0){
    cap_0 = need_0;
    eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
    seq_0_Incv1wn_arecyyj7v X60Qx_988 = newSeq_0_Ivbxvoi1_explnj22x1(cap_0);
    outbuf_1 = X60Qx_988;
    NU8* X60Qx_989 = getQ_7_Ig0r1051_arecyyj7v(outbuf_1, 0);
    NI32 X60Qx_990 = (*e_15).d_00.fn_0(inp_0, ((void*)(&(*X60Qx_989))), cap_0);
    need_0 = X60Qx_990;
    if (cap_0 < need_0){
      string_0_sysvq0asl X60Qdesugar_44 = dollarQ_2_sysvq0asl(need_0);
      NI32 X60Qx_991 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1768453118u, .more_0 = (&strlit_0_I2491960150546354308_run8hsnpi)}
      );
      NI32 X60Qx_992 = len_4_sysvq0asl(X60Qdesugar_44);
      NI32 X60Qx_993 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I2284540631411732658_run8hsnpi)}
      );
      string_0_sysvq0asl X60Qdesugar_45 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_991 + X60Qx_992)) + X60Qx_993)));
      add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
        .bytes_0 = 1768453118u, .more_0 = (&strlit_0_I2491960150546354308_run8hsnpi)}
      );
      add_2_sysvq0asl((&X60Qdesugar_45), X60Qdesugar_44);
      add_2_sysvq0asl((&X60Qdesugar_45), (string_0_sysvq0asl){
        .bytes_0 = 2036474110u, .more_0 = (&strlit_0_I2284540631411732658_run8hsnpi)}
      );
      declineNote_0_croph25r5(6, X60Qdesugar_45);
      nimStrDestroy(X60Qdesugar_45);
      nimStrDestroy(X60Qdesugar_44);
      eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
      eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
      eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
      eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
      eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
      eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
      return NIM_FALSE;
      nimStrDestroy(X60Qdesugar_45);
      nimStrDestroy(X60Qdesugar_44);}}
  NI32 ai_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_994;
      NI32 X60Qx_995 = len_3_In63jw61_aow7lb5cq1((*e_15).d_00.args_0);
      if (ai_0 < X60Qx_995){
        NI32 X60Qx_996 = len_3_I0v1j8d_aow7lb5cq1((*e_15).d_00.outVarOffs_0);
        X60Qx_994 = (ai_0 < X60Qx_996);}
      else {
        X60Qx_994 = NIM_FALSE;}
      if (X60Qx_994){
        NB8 X60Qx_997;
        NB8 X60Qx_998;
        WireField_0_run8hsnpi* X60Qx_999 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
        if ((*X60Qx_999).isVar_0){
          WireField_0_run8hsnpi* X60Qx_1000 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          X60Qx_998 = (*X60Qx_1000).isArenaPtr_0;}
        else {
          X60Qx_998 = NIM_FALSE;}
        if (X60Qx_998){
          NI32* X60Qx_1001 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          X60Qx_997 = (0 <= (*X60Qx_1001));}
        else {
          X60Qx_997 = NIM_FALSE;}
        if (X60Qx_997){
          Value_0_valzr1t4f* X60Qx_1002 = getQ_7_Ine8yq71_intzsnzax(args_5, ai_0);
          Value_0_valzr1t4f X60QconstRefTemp_2 = (*X60Qx_1002);
          NI32* X60Qx_1003 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          WireField_0_run8hsnpi* X60Qx_1004 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          WireField_0_run8hsnpi X60QconstRefTemp_3 = (*X60Qx_1004);
          NB8 X60Qx_1005 = applyWritebackArena_0_run8hsnpi((&X60QconstRefTemp_2), outbuf_1, (*X60Qx_1003), (&X60QconstRefTemp_3), (&m_4));
          if ((!X60Qx_1005)){
            bump_0_croph25r5(cArenaDeclines_0_run8hsnpi, 1);
            string_0_sysvq0asl X60Qdesugar_46 = dollarQ_2_sysvq0asl(ai_0);
            NI32 X60Qx_1006 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I10032287891621565925_run8hsnpi)}
            );
            NI32 X60Qx_1007 = len_4_sysvq0asl(X60Qdesugar_46);
            NI32 X60Qx_1008 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1629502206u, .more_0 = (&strlit_0_I11519459256921757232_run8hsnpi)}
            );
            string_0_sysvq0asl X60Qdesugar_47 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1006 + X60Qx_1007)) + X60Qx_1008)));
            add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I10032287891621565925_run8hsnpi)}
            );
            add_2_sysvq0asl((&X60Qdesugar_47), X60Qdesugar_46);
            add_2_sysvq0asl((&X60Qdesugar_47), (string_0_sysvq0asl){
              .bytes_0 = 1629502206u, .more_0 = (&strlit_0_I11519459256921757232_run8hsnpi)}
            );
            declineNote_0_croph25r5(3, X60Qdesugar_47);
            NB8 X60Qx_1009;
            if (hybridArenaTrace_0_run8hsnpi){
              NI32 X60Qx_1010 = countOf_0_croph25r5(cArenaDeclines_0_run8hsnpi);
              X60Qx_1009 = (X60Qx_1010 <= 3);}
            else {
              X60Qx_1009 = NIM_FALSE;}
            if (X60Qx_1009){
              string_0_sysvq0asl X60Qdesugar_48 = arenaReport_0_arecyyj7v();
              NI32 X60Qx_1011 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I8945843855761550514_run8hsnpi)}
              );
              NI32 X60Qx_1012 = len_4_sysvq0asl(base_5);
              NI32 X60Qx_1013 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
              );
              NI32 X60Qx_1014 = len_4_sysvq0asl(X60Qdesugar_48);
              NI32 X60Qx_1015 = len_4_sysvq0asl((string_0_sysvq0asl){
                .bytes_0 = 2561u, .more_0 = NIM_NIL}
              );
              string_0_sysvq0asl X60Qdesugar_49 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_1011 + X60Qx_1012)) + X60Qx_1013)) + X60Qx_1014)) + X60Qx_1015)));
              add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
                .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I8945843855761550514_run8hsnpi)}
              );
              add_2_sysvq0asl((&X60Qdesugar_49), base_5);
              add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
                .bytes_0 = 2162303230u, .more_0 = (&strlit_0_I13319807167292544980_aow7lb5cq1)}
              );
              add_2_sysvq0asl((&X60Qdesugar_49), X60Qdesugar_48);
              add_2_sysvq0asl((&X60Qdesugar_49), (string_0_sysvq0asl){
                .bytes_0 = 2561u, .more_0 = NIM_NIL}
              );
              write_0_syn1lfpjv(stderr, X60Qdesugar_49);
              nimStrDestroy(X60Qdesugar_49);
              nimStrDestroy(X60Qdesugar_48);}
            nimStrDestroy(X60Qdesugar_47);
            nimStrDestroy(X60Qdesugar_46);
            eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
            eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
            eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
            eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
            eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
            eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
            return NIM_FALSE;
            nimStrDestroy(X60Qdesugar_47);
            nimStrDestroy(X60Qdesugar_46);}}
        NB8 X60Qx_1016;
        NB8 X60Qx_1017;
        WireField_0_run8hsnpi* X60Qx_1018 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
        if ((*X60Qx_1018).isVar_0){
          WireField_0_run8hsnpi* X60Qx_1019 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          X60Qx_1017 = (*X60Qx_1019).isArray_0;}
        else {
          X60Qx_1017 = NIM_FALSE;}
        if (X60Qx_1017){
          NI32* X60Qx_1020 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          X60Qx_1016 = (0 <= (*X60Qx_1020));}
        else {
          X60Qx_1016 = NIM_FALSE;}
        if (X60Qx_1016){
          Value_0_valzr1t4f* X60Qx_1021 = getQ_7_Ine8yq71_intzsnzax(args_5, ai_0);
          Value_0_valzr1t4f X60QconstRefTemp_4 = (*X60Qx_1021);
          NI32* X60Qx_1022 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          WireField_0_run8hsnpi* X60Qx_1023 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          WireField_0_run8hsnpi X60QconstRefTemp_5 = (*X60Qx_1023);
          NB8 X60Qx_1024 = applyWritebackArray_0_run8hsnpi((&X60QconstRefTemp_4), outbuf_1, (*X60Qx_1022), (&X60QconstRefTemp_5));
          if ((!X60Qx_1024)){
            string_0_sysvq0asl X60Qdesugar_50 = dollarQ_2_sysvq0asl(ai_0);
            NI32 X60Qx_1025 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I10032287891621565925_run8hsnpi)}
            );
            NI32 X60Qx_1026 = len_4_sysvq0asl(X60Qdesugar_50);
            NI32 X60Qx_1027 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 1629502206u, .more_0 = (&strlit_0_I9993579587050855651_run8hsnpi)}
            );
            NI32 X60Qx_1028 = len_4_sysvq0asl((string_0_sysvq0asl){
              .bytes_0 = 544370686u, .more_0 = (&strlit_0_I16678242556164327223_run8hsnpi)}
            );
            string_0_sysvq0asl X60Qdesugar_51 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_1025 + X60Qx_1026)) + X60Qx_1027)) + X60Qx_1028)));
            add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
              .bytes_0 = 1769109502u, .more_0 = (&strlit_0_I10032287891621565925_run8hsnpi)}
            );
            add_2_sysvq0asl((&X60Qdesugar_51), X60Qdesugar_50);
            add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
              .bytes_0 = 1629502206u, .more_0 = (&strlit_0_I9993579587050855651_run8hsnpi)}
            );
            add_2_sysvq0asl((&X60Qdesugar_51), (string_0_sysvq0asl){
              .bytes_0 = 544370686u, .more_0 = (&strlit_0_I16678242556164327223_run8hsnpi)}
            );
            declineNote_0_croph25r5(1, X60Qdesugar_51);
            nimStrDestroy(X60Qdesugar_51);
            nimStrDestroy(X60Qdesugar_50);
            eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
            eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
            eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
            eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
            eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
            eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
            return NIM_FALSE;
            nimStrDestroy(X60Qdesugar_51);
            nimStrDestroy(X60Qdesugar_50);}}
        inc_1_I6wjjge_aow2h993l1((&ai_0));}
      else {
        break;}}}
  whileStmtLabel_5: ;
  if ((*e_15).d_00.retVoid_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*res_5)));
    Value_0_valzr1t4f X60Qx_1029 = vNil_0_valzr1t4f();
    (*res_5) = X60Qx_1029;}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*res_5)));
    Value_0_valzr1t4f X60Qx_1030 = unpackReturn_0_run8hsnpi(outbuf_1, (&(*e_15).d_00.ret_0));
    (*res_5) = X60Qx_1030;}
  ai_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_1031;
      NI32 X60Qx_1032 = len_3_In63jw61_aow7lb5cq1((*e_15).d_00.args_0);
      if (ai_0 < X60Qx_1032){
        NI32 X60Qx_1033 = len_3_I0v1j8d_aow7lb5cq1((*e_15).d_00.outVarOffs_0);
        X60Qx_1031 = (ai_0 < X60Qx_1033);}
      else {
        X60Qx_1031 = NIM_FALSE;}
      if (X60Qx_1031){
        NB8 X60Qx_1034;
        NB8 X60Qx_1035;
        NB8 X60Qx_1036;
        WireField_0_run8hsnpi* X60Qx_1037 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
        if ((*X60Qx_1037).isVar_0){
          NI32* X60Qx_1038 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          X60Qx_1036 = (0 <= (*X60Qx_1038));}
        else {
          X60Qx_1036 = NIM_FALSE;}
        if (X60Qx_1036){
          WireField_0_run8hsnpi* X60Qx_1039 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          X60Qx_1035 = (!(*X60Qx_1039).isArenaPtr_0);}
        else {
          X60Qx_1035 = NIM_FALSE;}
        if (X60Qx_1035){
          WireField_0_run8hsnpi* X60Qx_1040 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          X60Qx_1034 = (!(*X60Qx_1040).isArray_0);}
        else {
          X60Qx_1034 = NIM_FALSE;}
        if (X60Qx_1034){
          Value_0_valzr1t4f* X60Qx_1041 = getQ_7_Ine8yq71_intzsnzax(args_5, ai_0);
          Value_0_valzr1t4f X60QconstRefTemp_6 = (*X60Qx_1041);
          NI32* X60Qx_1042 = getQ_7_Ir8kccm_aow7lb5cq1((*e_15).d_00.outVarOffs_0, ai_0);
          WireField_0_run8hsnpi* X60Qx_1043 = getQ_7_Iko57h9_aow7lb5cq1((*e_15).d_00.args_0, ai_0);
          WireField_0_run8hsnpi X60QconstRefTemp_7 = (*X60Qx_1043);
          applyWriteback_0_run8hsnpi((&X60QconstRefTemp_6), outbuf_1, (*X60Qx_1042), (&X60QconstRefTemp_7));}
        inc_1_I6wjjge_aow2h993l1((&ai_0));}
      else {
        break;}}}
  whileStmtLabel_6: ;
  NI32 si_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1044 = len_3_Iibq2ff1_run8hsnpi(arenaSync_0);
      if (si_0 < X60Qx_1044){
        X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* X60Qx_1045 = getQ_7_Ir6lnzn1_run8hsnpi(arenaSync_0, si_0);
        X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* X60Qx_1046 = getQ_7_Ir6lnzn1_run8hsnpi(arenaSync_0, si_0);
        syncBack_0_arecyyj7v((&m_4), (&(*X60Qx_1045).fld_0), (*X60Qx_1046).fld_1);
        inc_1_I6wjjge_aow2h993l1((&si_0));}
      else {
        break;}}}
  whileStmtLabel_7: ;
  if (anyArena_0){
    syncBlocks_0_arecyyj7v((&m_4));}
  bump_0_croph25r5(cHybridCalls_0_run8hsnpi, 1);
  NB8 X60Qx_1047 = jitTraceLog_0_run8hsnpi();
  if (X60Qx_1047){
    NI32 X60Qx_1048 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I16930409917808841651_run8hsnpi)}
    );
    NI32 X60Qx_1049 = len_4_sysvq0asl(base_5);
    NI32 X60Qx_1050 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_52 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_1048 + X60Qx_1049)) + X60Qx_1050)));
    add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
      .bytes_0 = 1953065726u, .more_0 = (&strlit_0_I16930409917808841651_run8hsnpi)}
    );
    add_2_sysvq0asl((&X60Qdesugar_52), base_5);
    add_2_sysvq0asl((&X60Qdesugar_52), (string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_52);
    nimStrDestroy(X60Qdesugar_52);}
  result_56 = NIM_TRUE;
  eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
  eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
  eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
  eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
  eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
  return result_56;
  eQdestroy_1_Ijx6eoq_arecyyj7v(outbuf_1);
  eQdestroy_1_Ijx6eoq_arecyyj7v(inbuf_1);
  eQdestroy_1_Imh4l59_run8hsnpi(arenaSync_0);
  eQdestroyQ_SX41renaX4dat0arecyyj7v_0_arecyyj7v((&m_4));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(e_15);
  eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(gp_1);
  return result_56;}
CrossRoute_0_croph25r5 genRoute_0_run8hsnpi(string_0_sysvq0asl base_6){
  CrossRoute_0_croph25r5 result_57;
  result_57 = 3;
  return result_57;}
X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* newCabiProviderGen_0_run8hsnpi(string_0_sysvq0asl soPath_2, seq_0_Igzebks_aow7lb5cq1 entries_0, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_0){
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* result_58;
  eQwasmovedQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi((&result_58));
  Table_0_Ivb80lo_run8hsnpi t_10 = initTable_0_Iag3oaw1_run8hsnpi();
  {
    openArray_0_In0ukmu_aow7lb5cq1 X60Qlf_28 = toOpenArray_1_Ijdwnsz_aow7lb5cq1(entries_0);
    NI32 X60Qlf_29 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1051 = len_6_Iu1dtri1_aow7lb5cq1(X60Qlf_28);
        if (X60Qlf_29 < X60Qx_1051){
          {
            X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qii_2 = getQ_10_I6a58n11_aow7lb5cq1(X60Qlf_28, X60Qlf_29);
            X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_1052 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((*X60Qii_2));
            putQ_0_I4rb4at_run8hsnpi((&t_10), (*(*X60Qii_2)).d_00.sym_0, X60Qx_1052);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_29));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(result_58);
  void* X60Qx_1053 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi));
  X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* X60Qtmp_161 = ((X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi*)X60Qx_1053);
  string_0_sysvq0asl X60Qx_122 = nimStrDup(soPath_2);
  Table_0_Ivb80lo_run8hsnpi X60Qtmp_162 = t_10;
  eQwasmovedQ_SX54able0X49vb80lo_0_run8hsnpi((&t_10));
  X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* X60Qx_123 = newXProvider_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1650549758u, .more_0 = (&strlit_0_I9558933350530343618_run8hsnpi)}
  , NIM_NIL, genRoute_0_run8hsnpi, attest_0, soPath_2);
  (*X60Qtmp_161) = (X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi){
    .r_00 = 0, .d_00 = (CabiGenProvider_Obj_0_run8hsnpi){
      (&CabiGenProvider_Obj_0_vt_run8hsnpi), .Q.kind_0 = 3, .Q.codec_0 = 1, .Q.policy_0 = 1, .Q.name_0 = (string_0_sysvq0asl){
        .bytes_0 = 1650549758u, .more_0 = (&strlit_0_I9558933350530343618_run8hsnpi)}
      , .Q.resolveFastImpl_0 = NIM_NIL, .Q.marshalArgs_0 = NIM_NIL, .Q.marshalReturn_0 = NIM_NIL, .Q.ownsImpl_0 = cabiGenOwns_0_run8hsnpi, .Q.invoke_0 = cabiGenInvoke_0_run8hsnpi, .soPath_0 = X60Qx_122, .handle_0 = NIM_NIL, .opened_0 = NIM_FALSE, .table_0 = X60Qtmp_162, .arena_0 = ((X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v*)NIM_NIL), .xp_0 = X60Qx_123}}
  ;
  result_58 = ((X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*)X60Qtmp_161);
  eQdestroyQ_SX54able0X49vb80lo_0_run8hsnpi(t_10);
  return result_58;
  eQdestroyQ_SX54able0X49vb80lo_0_run8hsnpi(t_10);
  return result_58;}
X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* newHybridRegistryGen_0_run8hsnpi(string_0_sysvq0asl soPath_3, seq_0_Igzebks_aow7lb5cq1 entries_1, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_1){
  X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* result_59;
  eQwasmovedQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi((&result_59));
  eQdestroyQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi(result_59);
  void* X60Qx_1054 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax));
  X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* X60Qtmp_163 = ((X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax*)X60Qx_1054);
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* X60Qx_1055 = newCabiProviderGen_0_run8hsnpi(soPath_3, entries_1, attest_1);
  seq_0_Ixkko8n_run8hsnpi X60Qx_1056 = newSeqUninit_0_Iyquyq_run8hsnpi(0);
  (*X60Qtmp_163) = (X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax){
    .r_00 = 0, .d_00 = (HybridRegistry_Obj_0_run8hsnpi){
      .provider_0 = X60Qx_1055, .extra_0 = X60Qx_1056}}
  ;
  result_59 = X60Qtmp_163;
  return result_59;}
void addHybridProviderGen_0_run8hsnpi(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* reg_1, string_0_sysvq0asl soPath_4, seq_0_Igzebks_aow7lb5cq1 entries_2, X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5ZAboolZAnimcallZAfalseZAR49_croph25r5 attest_2){
  NB8 X60Qx_1057;
  NB8 X60Qx_1058;
  if (reg_1 == NIM_NIL){
    X60Qx_1058 = NIM_TRUE;}
  else {
    NI32 X60Qx_1059 = len_4_sysvq0asl(soPath_4);
    X60Qx_1058 = (X60Qx_1059 == 0);}
  if (X60Qx_1058){
    X60Qx_1057 = NIM_TRUE;}
  else {
    NI32 X60Qx_1060 = len_3_I44vue3_aow7lb5cq1(entries_2);
    X60Qx_1057 = (X60Qx_1060 == 0);}
  if (X60Qx_1057){
    return;}
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* X60Qx_1061 = newCabiProviderGen_0_run8hsnpi(soPath_4, entries_2, attest_2);
  add_0_Ixve43b1_run8hsnpi((&(*reg_1).d_00.extra_0), X60Qx_1061);}
static inline void add_0_Ijteip9_run8hsnpi(seq_0_I3ump14_aow7lb5cq1* s_46, X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* elem_17){
  NI32 L_0 = (*s_46).len_0;
  NI32 X60Qx_1069 = capInBytes_0_Iho46001_aow7lb5cq1((*s_46));
  if (X60Qx_1069 < ((NI32)(((NI32)(L_0 * sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*))) + sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)))){
    NB8 X60Qx_1070 = resize_0_Ithn1vs_run8hsnpi(s_46, 1);
    if ((!X60Qx_1070)){
      eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(elem_17);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_46).len_0));
  (*s_46).data_0[L_0] = elem_17;}
static inline seq_0_Ixkko8n_run8hsnpi newSeqUninit_0_Iyquyq_run8hsnpi(NI32 size_21){
  seq_0_Ixkko8n_run8hsnpi result_66;
  if (size_21 == 0){
    result_66 = (seq_0_Ixkko8n_run8hsnpi){
      .len_0 = size_21, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Irm6f661_run8hsnpi(size_21);
    void* X60Qx_1072 = alloc_1_sysvq0asl(memSize_2);
    result_66 = (seq_0_Ixkko8n_run8hsnpi){
      .len_0 = size_21, .data_0 = ((X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax**)X60Qx_1072)}
    ;
    if ((!(result_66.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1073 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_66.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_66;}
static inline openArray_0_Ihcf6y9_run8hsnpi toOpenArray_1_Iumnf4i1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_52){
  openArray_0_Ihcf6y9_run8hsnpi result_69;
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** X60Qx_1075 = rawData_0_Ix1iq6g1_run8hsnpi(s_52);
  result_69 = (openArray_0_Ihcf6y9_run8hsnpi){
    .a_0 = X60Qx_1075, .len_0 = s_52.len_0}
  ;
  return result_69;}
static inline void add_0_Itzi0i7_run8hsnpi(seq_0_Il8twp61_aow7lb5cq1* s_56, WireField_0_run8hsnpi elem_18){
  NI32 L_1 = (*s_56).len_0;
  NI32 X60Qx_1085 = capInBytes_0_I51wdad1_aow7lb5cq1((*s_56));
  if (X60Qx_1085 < ((NI32)(((NI32)(L_1 * sizeof(WireField_0_run8hsnpi))) + sizeof(WireField_0_run8hsnpi)))){
    NB8 X60Qx_1086 = resize_0_I6di9mo1_run8hsnpi(s_56, 1);
    if ((!X60Qx_1086)){
      eQdestroyQ_SX57ireX46ield0run8hsnpi_0_run8hsnpi((&elem_18));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_56).len_0));
  (*s_56).data_0[L_1] = elem_18;}
static inline void add_0_Ibphvmo_run8hsnpi(seq_0_Incv1wn_arecyyj7v* s_72, NU8 elem_22){
  NI32 L_4 = (*s_72).len_0;
  NI32 X60Qx_1098 = capInBytes_0_Iffahgv_arecyyj7v((*s_72));
  if (X60Qx_1098 < ((NI32)(((NI32)(L_4 * sizeof(NU8))) + sizeof(NU8)))){
    NB8 X60Qx_1099 = resize_0_Iuiuhg71_flaksyopx1(s_72, 1);
    if ((!X60Qx_1099)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_72).len_0));
  (*s_72).data_0[L_4] = elem_22;}
static inline NI32 len_3_Irjnvku_run8hsnpi(seq_0_Ik7wkpe_aow7lb5cq1 s_83){
  NI32 result_92;
  result_92 = s_83.len_0;
  return result_92;}
static inline seq_0_Ie7vbta_run8hsnpi newSeqUninit_0_I32zp0x_run8hsnpi(NI32 size_40){
  seq_0_Ie7vbta_run8hsnpi result_95;
  if (size_40 == 0){
    result_95 = (seq_0_Ie7vbta_run8hsnpi){
      .len_0 = size_40, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_12 = memSizeInBytes_0_Ip0vdbh_run8hsnpi(size_40);
    void* X60Qx_1116 = alloc_1_sysvq0asl(memSize_12);
    result_95 = (seq_0_Ie7vbta_run8hsnpi){
      .len_0 = size_40, .data_0 = ((X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi*)X60Qx_1116)}
    ;
    if ((!(result_95.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1117 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_95.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_12);}}
  return result_95;}
static inline void add_0_Ivy8r7k1_run8hsnpi(seq_0_Ie7vbta_run8hsnpi* s_87, X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi elem_26){
  NI32 L_8 = (*s_87).len_0;
  NI32 X60Qx_1118 = capInBytes_0_Ivcwflf1_run8hsnpi((*s_87));
  if (X60Qx_1118 < ((NI32)(((NI32)(L_8 * sizeof(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi))) + sizeof(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi)))){
    NB8 X60Qx_1119 = resize_0_Igrgn3v_run8hsnpi(s_87, 1);
    if ((!X60Qx_1119)){
      eQdestroyQ_AtupleAiS32ZSX56alue0valzr1t4f_0_run8hsnpi((&elem_26));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_87).len_0));
  (*s_87).data_0[L_8] = elem_26;}
static inline openArray_0_Icv4v4b1_run8hsnpi toOpenArray_1_Io2cvnr_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_89){
  openArray_0_Icv4v4b1_run8hsnpi result_96;
  X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* X60Qx_1120 = rawData_0_Ir5lda7_run8hsnpi(s_89);
  result_96 = (openArray_0_Icv4v4b1_run8hsnpi){
    .a_0 = X60Qx_1120, .len_0 = s_89.len_0}
  ;
  return result_96;}
X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* getOrDefault_1_Imr3kd01_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_15, NU32 k_6, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* fallback_1){
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* result_97;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&result_97));
  NU32 X60Qx_1121 = hash_0_nifh7u8pu1(k_6);
  NI32 idx_10 = rawGet_0_Ihcxbwv_run8hsnpi(t_15, k_6, X60Qx_1121);
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_62;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&X60Qx_62));
  if (0 <= idx_10){
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qx_62);
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1122 = getQ_7_I46cuah_run8hsnpi(t_15.data_0, idx_10);
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_1123 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((*X60Qx_1122).fld_1);
    X60Qx_62 = X60Qx_1123;}
  else {
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qx_62);
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qx_1124 = eQdupQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(fallback_1);
    X60Qx_62 = X60Qx_1124;}
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(result_97);
  result_97 = X60Qx_62;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&X60Qx_62));
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qx_62);
  return result_97;
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(X60Qx_62);
  return result_97;}
static inline NI32 len_0_Ifyaclq_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_17){
  NI32 result_98;
  NI32 X60Qx_1125 = len_3_I849zvk_run8hsnpi(t_17.data_0);
  result_98 = X60Qx_1125;
  return result_98;}
static inline seq_0_Iq1shzq1_run8hsnpi newSeqUninit_0_Ie5g2lj_run8hsnpi(NI32 size_48){
  seq_0_Iq1shzq1_run8hsnpi result_102;
  if (size_48 == 0){
    result_102 = (seq_0_Iq1shzq1_run8hsnpi){
      .len_0 = size_48, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_16 = memSizeInBytes_0_Ifk9c7h1_run8hsnpi(size_48);
    void* X60Qx_1132 = alloc_1_sysvq0asl(memSize_16);
    result_102 = (seq_0_Iq1shzq1_run8hsnpi){
      .len_0 = size_48, .data_0 = ((X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi*)X60Qx_1132)}
    ;
    if ((!(result_102.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1133 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_102.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_16);}}
  return result_102;}
static inline void add_0_Ii05ltt1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi* s_93, X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi elem_27){
  NI32 L_9 = (*s_93).len_0;
  NI32 X60Qx_1134 = capInBytes_0_In8my0q1_run8hsnpi((*s_93));
  if (X60Qx_1134 < ((NI32)(((NI32)(L_9 * sizeof(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi))) + sizeof(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi)))){
    NB8 X60Qx_1135 = resize_0_I5hcuwh1_run8hsnpi(s_93, 1);
    if ((!X60Qx_1135)){
      eQdestroyQ_AtupleSX56alue0valzr1t4fApointer_0_run8hsnpi((&elem_27));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_93).len_0));
  (*s_93).data_0[L_9] = elem_27;}
static inline NI32 len_3_Iibq2ff1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_95){
  NI32 result_103;
  result_103 = s_95.len_0;
  return result_103;}
static inline X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* getQ_7_Ir6lnzn1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_96, NI32 i_55){
  NB8 X60Qx_1136;
  if (i_55 < s_96.len_0){
    X60Qx_1136 = (0 <= i_55);}
  else {
    X60Qx_1136 = NIM_FALSE;}
  if ((!X60Qx_1136)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi* result_104;
  result_104 = (&s_96.data_0[i_55]);
  return result_104;}
Table_0_Ivb80lo_run8hsnpi initTable_0_Iag3oaw1_run8hsnpi(void){
  Table_0_Ivb80lo_run8hsnpi result_105;
  eQwasmovedQ_SX54able0X49vb80lo_0_run8hsnpi((&result_105));
  eQdestroyQ_SX54able0X49vb80lo_0_run8hsnpi(result_105);
  seq_0_Iwk350i1_run8hsnpi X60Qx_1137 = newSeqUninit_0_Iyp3d871_run8hsnpi(0);
  seq_0_Ikxuplm1_der823rwr1 X60Qx_1138 = newSeqUninit_0_Iie69x21_der823rwr1(0);
  result_105 = (Table_0_Ivb80lo_run8hsnpi){
    .data_0 = X60Qx_1137, .hashes_0 = X60Qx_1138}
  ;
  return result_105;}
void putQ_0_I4rb4at_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_18, NU32 k_8, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* v_10){
  NU32 h_1 = hash_0_nifh7u8pu1(k_8);
  NI32 idx_12 = rawGet_0_Ihcxbwv_run8hsnpi((*t_18), k_8, h_1);
  if (0 <= idx_12){
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1140 = getQ_7_I46cuah_run8hsnpi((*t_18).data_0, idx_12);
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qlhs_164 = (&(*X60Qx_1140).fld_1);
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qlhs_165 = v_10;
    eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&v_10));
    eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((*X60Qlhs_164));
    (*X60Qlhs_164) = X60Qlhs_165;}
  else {
    X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_166 = v_10;
    eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&v_10));
    rawPut_0_Ifxcxpb1_run8hsnpi(t_18, k_8, X60Qtmp_166, h_1);}
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(v_10);}
static inline void add_0_Ixve43b1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi* s_100, X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax* elem_28){
  NI32 L_10 = (*s_100).len_0;
  NI32 X60Qx_1141 = capInBytes_0_I0n41e91_run8hsnpi((*s_100));
  if (X60Qx_1141 < ((NI32)(((NI32)(L_10 * sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*))) + sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*)))){
    NB8 X60Qx_1142 = resize_0_I9hyasp_run8hsnpi(s_100, 1);
    if ((!X60Qx_1142)){
      eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(elem_28);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_100).len_0));
  (*s_100).data_0[L_10] = elem_28;}
NB8 resize_0_Ithn1vs_run8hsnpi(seq_0_I3ump14_aow7lb5cq1* dest_11, NI32 addedElements_11){
  NB8 result_113;
  NI32 X60Qx_1146 = capInBytes_0_Iho46001_aow7lb5cq1((*dest_11));
  NI32 oldCap_0 = ((NI32)(X60Qx_1146 / sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_11);
  NI32 memSize_17 = memSizeInBytes_0_I6h5zpv1_aow7lb5cq1(newCap_0);
  void* X60Qx_1147 = realloc_1_sysvq0asl(((void*)((void*)(*dest_11).data_0)), memSize_17);
  (*dest_11).data_0 = ((X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1**)X60Qx_1147);
  if ((*dest_11).data_0 == NIM_NIL){
    (*dest_11).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_17);
    result_113 = NIM_FALSE;}
  else {
    result_113 = NIM_TRUE;}
  return result_113;}
static inline NI32 memSizeInBytes_0_Irm6f661_run8hsnpi(NI32 size_54){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_117;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_54, sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_117 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_117 = ((NI32)2147483647);}
  return result_117;}
static inline X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** rawData_0_Ix1iq6g1_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_106){
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** result_118;
  result_118 = s_106.data_0;
  return result_118;}
static inline NI32 len_6_Ij4lmhs_run8hsnpi(openArray_0_Ihcf6y9_run8hsnpi a_24){
  NI32 result_119;
  result_119 = a_24.len_0;
  return result_119;}
static inline X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** getQ_10_Iwwsp9w1_run8hsnpi(openArray_0_Ihcf6y9_run8hsnpi x_15, NI32 idx_14){
  NB8 X60Qx_1149;
  if (0 <= idx_14){
    X60Qx_1149 = (idx_14 < x_15.len_0);}
  else {
    X60Qx_1149 = NIM_FALSE;}
  if ((!X60Qx_1149)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** result_120;
  result_120 = (&x_15.a_0[idx_14]);
  return result_120;}
NB8 resize_0_I6di9mo1_run8hsnpi(seq_0_Il8twp61_aow7lb5cq1* dest_12, NI32 addedElements_12){
  NB8 result_128;
  NI32 X60Qx_1152 = capInBytes_0_I51wdad1_aow7lb5cq1((*dest_12));
  NI32 oldCap_1 = ((NI32)(X60Qx_1152 / sizeof(WireField_0_run8hsnpi)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_12);
  NI32 memSize_18 = memSizeInBytes_0_Io786y61_aow7lb5cq1(newCap_1);
  void* X60Qx_1153 = realloc_1_sysvq0asl(((void*)((void*)(*dest_12).data_0)), memSize_18);
  (*dest_12).data_0 = ((WireField_0_run8hsnpi*)X60Qx_1153);
  if ((*dest_12).data_0 == NIM_NIL){
    (*dest_12).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_18);
    result_128 = NIM_FALSE;}
  else {
    result_128 = NIM_TRUE;}
  return result_128;}
static inline NI32 memSizeInBytes_0_Ip0vdbh_run8hsnpi(NI32 size_63){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_151;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_63, sizeof(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_151 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_151 = ((NI32)2147483647);}
  return result_151;}
static inline NI32 capInBytes_0_Ivcwflf1_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_116){
  NI32 result_152;
  NI32 X60Qx_71;
  if ((!(s_116.data_0 == NIM_NIL))){
    NI32 X60Qx_1174 = allocatedSize_0_sysvq0asl(((void*)((void*)s_116.data_0)));
    X60Qx_71 = X60Qx_1174;}
  else {
    X60Qx_71 = 0;}
  result_152 = X60Qx_71;
  return result_152;}
NB8 resize_0_Igrgn3v_run8hsnpi(seq_0_Ie7vbta_run8hsnpi* dest_19, NI32 addedElements_19){
  NB8 result_153;
  NI32 X60Qx_1175 = capInBytes_0_Ivcwflf1_run8hsnpi((*dest_19));
  NI32 oldCap_8 = ((NI32)(X60Qx_1175 / sizeof(X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi)));
  NI32 newCap_8 = recalcCap_0_sysvq0asl(oldCap_8, addedElements_19);
  NI32 memSize_25 = memSizeInBytes_0_Ip0vdbh_run8hsnpi(newCap_8);
  void* X60Qx_1176 = realloc_1_sysvq0asl(((void*)((void*)(*dest_19).data_0)), memSize_25);
  (*dest_19).data_0 = ((X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi*)X60Qx_1176);
  if ((*dest_19).data_0 == NIM_NIL){
    (*dest_19).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_25);
    result_153 = NIM_FALSE;}
  else {
    result_153 = NIM_TRUE;}
  return result_153;}
static inline X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* rawData_0_Ir5lda7_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_117){
  X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* result_154;
  result_154 = s_117.data_0;
  return result_154;}
static inline NI32 len_6_Ivyewcw1_run8hsnpi(openArray_0_Icv4v4b1_run8hsnpi a_28){
  NI32 result_155;
  result_155 = a_28.len_0;
  return result_155;}
static inline X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* getQ_10_Ijhkrt71_run8hsnpi(openArray_0_Icv4v4b1_run8hsnpi x_19, NI32 idx_18){
  NB8 X60Qx_1177;
  if (0 <= idx_18){
    X60Qx_1177 = (idx_18 < x_19.len_0);}
  else {
    X60Qx_1177 = NIM_FALSE;}
  if ((!X60Qx_1177)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleAiS32ZSX56alue0valzr1t4f_run8hsnpi* result_156;
  result_156 = (&x_19.a_0[idx_18]);
  return result_156;}
NI32 rawGet_0_Ihcxbwv_run8hsnpi(Table_0_Ivb80lo_run8hsnpi t_20, NU32 k_10, NU32 kh_1){
  NI32 result_157;
  NI32 X60Qx_1178 = len_3_I849zvk_run8hsnpi(t_20.data_0);
  if (X60Qx_1178 <= ((NI32)4)){
    {
      NI32 X60Qlf_30 = 0;
      NI32 X60Qlf_31 = len_3_I849zvk_run8hsnpi(t_20.data_0);
      NI32 X60Qlf_32 = X60Qlf_30;
      {
        while (X60Qlf_32 < X60Qlf_31){
          {
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1179 = getQ_7_I46cuah_run8hsnpi(t_20.data_0, X60Qlf_32);
            NB8 X60Qx_1180 = eqQ_0_nifh7u8pu1((*X60Qx_1179).fld_0, k_10);
            if (X60Qx_1180){
              return X60Qlf_32;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_32));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_1181 = high_3_Iyuup9h1_der823rwr1(t_20.hashes_0);
    NU32 h_3 = ((NU32)(kh_1 & ((NU32)X60Qx_1181)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_1182 = getQ_8_Imt2zi01_der823rwr1(t_20.hashes_0, h_3);
        NB8 X60Qx_1183 = isFilled_0_tabcr240b1((*X60Qx_1182));
        if (X60Qx_1183){
          HashEntry_0_tabcr240b1* X60Qx_1184 = getQ_8_Imt2zi01_der823rwr1(t_20.hashes_0, h_3);
          HashEntry_0_tabcr240b1 d_0 = (*X60Qx_1184);
          NB8 X60Qx_1185;
          if (d_0.fullhash_0 == kh_1){
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1186 = getQ_7_I46cuah_run8hsnpi(t_20.data_0, ((NI32)(d_0.position_0 - 1)));
            NB8 X60Qx_1187 = eqQ_0_nifh7u8pu1((*X60Qx_1186).fld_0, k_10);
            X60Qx_1185 = X60Qx_1187;}
          else {
            X60Qx_1185 = NIM_FALSE;}
          if (X60Qx_1185){
            result_157 = ((NI32)(d_0.position_0 - 1));
            return result_157;}
          NI32 X60Qx_1188 = high_3_Iyuup9h1_der823rwr1(t_20.hashes_0);
          NU32 X60Qx_1189 = nextTry_0_has9tn57v(h_3, X60Qx_1188);
          h_3 = X60Qx_1189;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_157 = -1;
  return result_157;}
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* getQ_7_I46cuah_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_120, NI32 i_61){
  NB8 X60Qx_1190;
  if (i_61 < s_120.len_0){
    X60Qx_1190 = (0 <= i_61);}
  else {
    X60Qx_1190 = NIM_FALSE;}
  if ((!X60Qx_1190)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* result_158;
  result_158 = (&s_120.data_0[i_61]);
  return result_158;}
static inline NI32 len_3_I849zvk_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_121){
  NI32 result_159;
  result_159 = s_121.len_0;
  return result_159;}
static inline NI32 memSizeInBytes_0_Ifk9c7h1_run8hsnpi(NI32 size_67){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_163;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_67, sizeof(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_163 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_163 = ((NI32)2147483647);}
  return result_163;}
static inline NI32 capInBytes_0_In8my0q1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_122){
  NI32 result_164;
  NI32 X60Qx_72;
  if ((!(s_122.data_0 == NIM_NIL))){
    NI32 X60Qx_1191 = allocatedSize_0_sysvq0asl(((void*)((void*)s_122.data_0)));
    X60Qx_72 = X60Qx_1191;}
  else {
    X60Qx_72 = 0;}
  result_164 = X60Qx_72;
  return result_164;}
NB8 resize_0_I5hcuwh1_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi* dest_20, NI32 addedElements_20){
  NB8 result_165;
  NI32 X60Qx_1192 = capInBytes_0_In8my0q1_run8hsnpi((*dest_20));
  NI32 oldCap_9 = ((NI32)(X60Qx_1192 / sizeof(X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi)));
  NI32 newCap_9 = recalcCap_0_sysvq0asl(oldCap_9, addedElements_20);
  NI32 memSize_26 = memSizeInBytes_0_Ifk9c7h1_run8hsnpi(newCap_9);
  void* X60Qx_1193 = realloc_1_sysvq0asl(((void*)((void*)(*dest_20).data_0)), memSize_26);
  (*dest_20).data_0 = ((X60Qt_0_IAtupleSX56alue0valzr1t4fApointer_run8hsnpi*)X60Qx_1193);
  if ((*dest_20).data_0 == NIM_NIL){
    (*dest_20).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_26);
    result_165 = NIM_FALSE;}
  else {
    result_165 = NIM_TRUE;}
  return result_165;}
static inline seq_0_Iwk350i1_run8hsnpi newSeqUninit_0_Iyp3d871_run8hsnpi(NI32 size_68){
  seq_0_Iwk350i1_run8hsnpi result_166;
  if (size_68 == 0){
    result_166 = (seq_0_Iwk350i1_run8hsnpi){
      .len_0 = size_68, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_27 = memSizeInBytes_0_I7xitnl1_run8hsnpi(size_68);
    void* X60Qx_1194 = alloc_1_sysvq0asl(memSize_27);
    result_166 = (seq_0_Iwk350i1_run8hsnpi){
      .len_0 = size_68, .data_0 = ((X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi*)X60Qx_1194)}
    ;
    if ((!(result_166.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1195 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_166.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_27);}}
  return result_166;}
void rawPut_0_Ifxcxpb1_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_21, NU32 k_11, X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* v_12, NU32 h_4){
  NI32 X60Qx_1199 = len_3_I849zvk_run8hsnpi((*t_21).data_0);
  if (X60Qx_1199 == ((NI32)4)){
    fillHashPart_0_I20rkt9_run8hsnpi(t_21);}
  else {
    NI32 X60Qx_1200 = len_3_Iiefpcc1_der823rwr1((*t_21).hashes_0);
    NI32 X60Qx_1201 = len_3_I849zvk_run8hsnpi((*t_21).data_0);
    NB8 X60Qx_1202 = mustRehash_0_tabcr240b1(X60Qx_1200, X60Qx_1201);
    if (X60Qx_1202){
      resize_0_tabcr240b1((&(*t_21).hashes_0));}}
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1* X60Qtmp_167 = v_12;
  eQwasmovedQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&v_12));
  add_0_Ihgv7q7_run8hsnpi((&(*t_21).data_0), (X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi){
    .fld_0 = k_11, .fld_1 = X60Qtmp_167}
  );
  NI32 X60Qx_1203 = high_3_Iyuup9h1_der823rwr1((*t_21).hashes_0);
  NU32 hi_2 = ((NU32)(h_4 & ((NU32)X60Qx_1203)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_1204 = getQ_8_Imt2zi01_der823rwr1((*t_21).hashes_0, hi_2);
      NB8 X60Qx_1205 = isFilled_0_tabcr240b1((*X60Qx_1204));
      if (X60Qx_1205){
        NI32 X60Qx_1206 = high_3_Iyuup9h1_der823rwr1((*t_21).hashes_0);
        NU32 X60Qx_1207 = nextTry_0_has9tn57v(hi_2, X60Qx_1206);
        hi_2 = X60Qx_1207;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_1208 = len_3_I849zvk_run8hsnpi((*t_21).data_0);
  putQ_8_Ipchg2a_der823rwr1((&(*t_21).hashes_0), hi_2, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_4, .position_0 = X60Qx_1208}
  );
  eQdestroyQ_ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(v_12);}
static inline NI32 capInBytes_0_I0n41e91_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_127){
  NI32 result_171;
  NI32 X60Qx_73;
  if ((!(s_127.data_0 == NIM_NIL))){
    NI32 X60Qx_1209 = allocatedSize_0_sysvq0asl(((void*)((void*)s_127.data_0)));
    X60Qx_73 = X60Qx_1209;}
  else {
    X60Qx_73 = 0;}
  result_171 = X60Qx_73;
  return result_171;}
NB8 resize_0_I9hyasp_run8hsnpi(seq_0_Ixkko8n_run8hsnpi* dest_21, NI32 addedElements_21){
  NB8 result_172;
  NI32 X60Qx_1210 = capInBytes_0_I0n41e91_run8hsnpi((*dest_21));
  NI32 oldCap_10 = ((NI32)(X60Qx_1210 / sizeof(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax*)));
  NI32 newCap_10 = recalcCap_0_sysvq0asl(oldCap_10, addedElements_21);
  NI32 memSize_29 = memSizeInBytes_0_Irm6f661_run8hsnpi(newCap_10);
  void* X60Qx_1211 = realloc_1_sysvq0asl(((void*)((void*)(*dest_21).data_0)), memSize_29);
  (*dest_21).data_0 = ((X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax**)X60Qx_1211);
  if ((*dest_21).data_0 == NIM_NIL){
    (*dest_21).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_29);
    result_172 = NIM_FALSE;}
  else {
    result_172 = NIM_TRUE;}
  return result_172;}
static inline NI32 memSizeInBytes_0_I7xitnl1_run8hsnpi(NI32 size_72){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_175;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_72, sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_175 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_175 = ((NI32)2147483647);}
  return result_175;}
void fillHashPart_0_I20rkt9_run8hsnpi(Table_0_Ivb80lo_run8hsnpi* t_23){
  seq_0_Ikxuplm1_der823rwr1* X60Qlhs_168 = (&(*t_23).hashes_0);
  eQdestroy_1_I5skmro_der823rwr1((*X60Qlhs_168));
  seq_0_Ikxuplm1_der823rwr1 X60Qx_1212 = newSeq_0_Iv3lu2h1_der823rwr1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_168) = X60Qx_1212;
  {
    NI32 X60Qlf_33 = 0;
    NI32 X60Qlf_34 = len_3_I849zvk_run8hsnpi((*t_23).data_0);
    NI32 X60Qlf_35 = X60Qlf_33;
    {
      while (X60Qlf_35 < X60Qlf_34){
        {
          X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi* X60Qx_1213 = getQ_7_I46cuah_run8hsnpi((*t_23).data_0, X60Qlf_35);
          NU32 X60Qii_2 = hash_0_nifh7u8pu1((*X60Qx_1213).fld_0);
          NI32 X60Qx_1214 = high_3_Iyuup9h1_der823rwr1((*t_23).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_1214)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_1215 = getQ_8_Imt2zi01_der823rwr1((*t_23).hashes_0, X60Qii_3);
            NB8 X60Qx_1216 = isFilled_0_tabcr240b1((*X60Qx_1215));
            if (X60Qx_1216){
              NI32 X60Qx_1217 = high_3_Iyuup9h1_der823rwr1((*t_23).hashes_0);
              NU32 X60Qx_1218 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_1217);
              X60Qii_3 = X60Qx_1218;}
            else {
              break;}}
          putQ_8_Ipchg2a_der823rwr1((&(*t_23).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_35 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_35));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_Ihgv7q7_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* s_131, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi elem_31){
  NI32 L_11 = (*s_131).len_0;
  NI32 X60Qx_1219 = capInBytes_0_Ilido7m1_run8hsnpi((*s_131));
  if (X60Qx_1219 < ((NI32)(((NI32)(L_11 * sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi))) + sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi)))){
    NB8 X60Qx_1220 = resize_0_Ie728b71_run8hsnpi(s_131, 1);
    if ((!X60Qx_1220)){
      eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(elem_31);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_131).len_0));
  (*s_131).data_0[L_11] = elem_31;}
static inline NI32 capInBytes_0_Ilido7m1_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_134){
  NI32 result_179;
  NI32 X60Qx_74;
  if ((!(s_134.data_0 == NIM_NIL))){
    NI32 X60Qx_1222 = allocatedSize_0_sysvq0asl(((void*)((void*)s_134.data_0)));
    X60Qx_74 = X60Qx_1222;}
  else {
    X60Qx_74 = 0;}
  result_179 = X60Qx_74;
  return result_179;}
NB8 resize_0_Ie728b71_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* dest_23, NI32 addedElements_23){
  NB8 result_180;
  NI32 X60Qx_1223 = capInBytes_0_Ilido7m1_run8hsnpi((*dest_23));
  NI32 oldCap_11 = ((NI32)(X60Qx_1223 / sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi)));
  NI32 newCap_11 = recalcCap_0_sysvq0asl(oldCap_11, addedElements_23);
  NI32 memSize_31 = memSizeInBytes_0_I7xitnl1_run8hsnpi(newCap_11);
  void* X60Qx_1224 = realloc_1_sysvq0asl(((void*)((void*)(*dest_23).data_0)), memSize_31);
  (*dest_23).data_0 = ((X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_run8hsnpi*)X60Qx_1224);
  if ((*dest_23).data_0 == NIM_NIL){
    (*dest_23).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_31);
    result_180 = NIM_FALSE;}
  else {
    result_180 = NIM_TRUE;}
  return result_180;}
void eQdestroy_1_Iuvcrzj_run8hsnpi(seq_0_Ixkko8n_run8hsnpi s_181){
  if ((!(s_181.data_0 == NIM_NIL))){
    NI32 i_72 = 0;
    {
      while (i_72 < s_181.len_0){
        eQdestroyQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(s_181.data_0[i_72]);
        inc_1_I6wjjge_aow2h993l1((&i_72));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_181.data_0)));}}
void eQdestroy_1_Ick5hx01_run8hsnpi(seq_0_Iwk350i1_run8hsnpi s_194){
  if ((!(s_194.data_0 == NIM_NIL))){
    NI32 i_96 = 0;
    {
      while (i_96 < s_194.len_0){
        eQdestroyQ_AtupleSX53ymX49d0nifh7u8pu1ArefSX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi(s_194.data_0[i_96]);
        inc_1_I6wjjge_aow2h993l1((&i_96));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_194.data_0)));}}
static inline void eQwasMoved_1_I2k3j3n_run8hsnpi(seq_0_Iwk350i1_run8hsnpi* s_195){
  (*s_195).len_0 = 0;
  (*s_195).data_0 = NIM_NIL;}
void eQdestroy_1_I2vp2bj_run8hsnpi(seq_0_Ie7vbta_run8hsnpi s_208){
  if ((!(s_208.data_0 == NIM_NIL))){
    NI32 i_120 = 0;
    {
      while (i_120 < s_208.len_0){
        eQdestroyQ_AtupleAiS32ZSX56alue0valzr1t4f_0_run8hsnpi((&s_208.data_0[i_120]));
        inc_1_I6wjjge_aow2h993l1((&i_120));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_208.data_0)));}}
void eQdestroy_1_Imh4l59_run8hsnpi(seq_0_Iq1shzq1_run8hsnpi s_219){
  if ((!(s_219.data_0 == NIM_NIL))){
    NI32 i_136 = 0;
    {
      while (i_136 < s_219.len_0){
        eQdestroyQ_AtupleSX56alue0valzr1t4fApointer_0_run8hsnpi((&s_219.data_0[i_136]));
        inc_1_I6wjjge_aow2h993l1((&i_136));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_219.data_0)));}}
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
  X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* X60Qx_1369 = eQdupQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi((*src_0).desc_0);
  dest_0.desc_0 = X60Qx_1369;
  string_0_sysvq0asl X60Qx_1370 = nimStrDup((*src_0).srcType_0);
  dest_0.srcType_0 = X60Qx_1370;
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
  string_0_sysvq0asl X60Qx_1371 = nimStrDup((*src_0).elemLeafName_0);
  dest_0.elemLeafName_0 = X60Qx_1371;
  dest_0.enumSym_0 = (*src_0).enumSym_0;
  dest_0.typeSym_0 = (*src_0).typeSym_0;
  dest_0.wireSize_0 = (*src_0).wireSize_0;
  dest_0.wireAlign_0 = (*src_0).wireAlign_0;
  string_0_sysvq0asl X60Qx_1372 = nimStrDup((*src_0).elemSrcType_0);
  dest_0.elemSrcType_0 = X60Qx_1372;
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
    NB8 X60Qx_1397 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1397){
      HybridProvider_Obj_0_run8hsnpi* X60QvtableTemp_6 = (&(*dest_0).d_00);
      ((X60Qt_0_ISX48ybridX50roviderX4fbj0run8hsnpiSEAnimcallZAfalseZAR45_intzsnzax)(*(*X60QvtableTemp_6).Q.vt_00).mt_0[0])((&(*X60QvtableTemp_6)));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX52egistryX4fbj0run8hsnpi_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_1398 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1398){
      eQdestroyQ_SX48ybridX52egistryX4fbj0run8hsnpi_0_run8hsnpi((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX48ybridX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX48ybridX50roviderX4fbj0run8hsnpi_intzsnzax** dest_0){
  (*dest_0) = NIM_NIL;}
void eQdestroyQ_ArefSX54ypeX44escX4fbj0layptix6a1_0_run8hsnpi(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_1400 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1400){
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
    NB8 X60Qx_1401 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1401){
      eQdestroyQ_SX53himX45ntryX4fbj0run8hsnpi_0_run8hsnpi((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX43abiX47enX50roviderX4fbj0run8hsnpi_0_run8hsnpi(X60Qt_0_IArefSX43abiX47enX50roviderX4fbj0run8hsnpi_run8hsnpi* dest_0){
  if (dest_0){
    NB8 X60Qx_1402 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1402){
      CabiGenProvider_Obj_0_run8hsnpi* X60QvtableTemp_8 = (&(*dest_0).d_00);
      ((X60Qt_0_ISX43abiX47enX50roviderX4fbj0run8hsnpiSEAnimcallZAfalseZAR48_run8hsnpi)(*(*X60QvtableTemp_8).Q.Q.vt_00).mt_0[1])((&(*X60QvtableTemp_8)));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX58X50roviderX4fbj0croph25r5_0_run8hsnpi(X60Qt_0_IArefSX58X50roviderX4fbj0croph25r5_aow7lb5cq1* dest_0){
  if (dest_0){
    NB8 X60Qx_1403 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1403){
      eQdestroyQ_SX58X50roviderX4fbj0croph25r5_0_croph25r5((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_run8hsnpi(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* dest_0){
  if (dest_0){
    NB8 X60Qx_1404 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1404){
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
    NB8 X60Qx_1405 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1405){
      eQdestroyQ_SX4fbjX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX4fbjX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi dest_0){
  eQdestroy_1_Iscb4i31_arecyyj7v(dest_0.fld_1);
  eQdestroy_1_Iscb4i31_arecyyj7v(dest_0.fld_2);}
void eQdestroyQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1406 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1406){
      eQdestroyQ_SX53eqX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX53eqX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_AtupleAboolZSseq0X49n6doaSR12_0_run8hsnpi(X60Qt_0_IAtupleAboolZSseq0X49n6doaSR12_run8hsnpi* dest_0){
  eQwasMoved_1_I2k4kel_arecyyj7v((&(*dest_0).fld_1));
  eQwasMoved_1_I2k4kel_arecyyj7v((&(*dest_0).fld_2));}
void eQdestroyQ_AtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_0_run8hsnpi(X60Qt_0_IAtupleSX41nX56erdict0der823rwr1SX41nX47iveX55p0R20Sstring0sysvq0asl_der823rwr1 dest_0){
  nimStrDestroy(dest_0.fld_2);}
void eQdestroyQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1407 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1407){
      eQdestroyQ_SX41rrX42oxX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* eQdupQ_ArefSX41rrX42oxX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* src_0){
  X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_ArefSX46latX52egionX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1408 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1408){
      eQdestroyQ_SX46latX52egionX4fbj0valzr1t4f_0_valzr1t4f((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX43ellX4fbj0valzr1t4f_0_run8hsnpi(X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0){
  if (dest_0){
    NB8 X60Qx_1409 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_1409){
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
  X60Qini_0_croph25r5();
  cHybridCalls_0_run8hsnpi = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I40788521789328021_run8hsnpi)}
  );
  cArenaDeclines_0_run8hsnpi = newRouteCounter_0_croph25r5((string_0_sysvq0asl){
    .bytes_0 = 1652123902u, .more_0 = (&strlit_0_I17821885512794003803_run8hsnpi)}
  );
  string_0_sysvq0asl X60Qtmp_42 = getEnv_0_envto7w6l1((string_0_sysvq0asl){
    .bytes_0 = 1464812030u, .more_0 = (&strlit_0_I819492781050547440_croph25r5)}
  , (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  hybridArenaTrace_0_run8hsnpi = eqQ_20_sysvq0asl(X60Qtmp_42, (string_0_sysvq0asl){
    .bytes_0 = 12545u, .more_0 = NIM_NIL}
  );
  nimStrDestroy(X60Qtmp_42);}
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
static inline openArray_0_Iczu4791_aow7lb5cq1 toOpenArray_1_I0ef4be1_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_29){
  openArray_0_Iczu4791_aow7lb5cq1 result_52;
  WireField_0_run8hsnpi* X60Qx_1427 = rawData_0_Ijd497p_aow7lb5cq1(s_29);
  result_52 = (openArray_0_Iczu4791_aow7lb5cq1){
    .a_0 = X60Qx_1427, .len_0 = s_29.len_0}
  ;
  return result_52;}
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
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_1445 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_1445 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1446 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_1446)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
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
  NI32 result_67;
  result_67 = s_45.len_0;
  return result_67;}
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
static inline void eQwasMoved_1_I861g1c1_arecyyj7v(seq_0_Incv1wn_arecyyj7v* s_79){
  (*s_79).len_0 = 0;
  (*s_79).data_0 = NIM_NIL;}
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
static inline NI32 len_3_Izoe8zv_arecyyj7v(seq_0_Incv1wn_arecyyj7v s_31){
  NI32 result_30;
  result_30 = s_31.len_0;
  return result_30;}
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
static inline seq_0_I50urnw_croph25r5 newSeqUninit_0_I8oufjc_croph25r5(NI32 size_14){
  seq_0_I50urnw_croph25r5 result_49;
  if (size_14 == 0){
    result_49 = (seq_0_I50urnw_croph25r5){
      .len_0 = size_14, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_10 = memSizeInBytes_0_Itmy7ww1_croph25r5(size_14);
    void* X60Qx_152 = alloc_1_sysvq0asl(memSize_10);
    result_49 = (seq_0_I50urnw_croph25r5){
      .len_0 = size_14, .data_0 = ((Value_0_valzr1t4f*)X60Qx_152)}
    ;
    if ((!(result_49.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_153 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_49.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_10);}}
  return result_49;}
static inline void add_0_Itre92n_intzsnzax(seq_0_I50urnw_croph25r5* s_137, Value_0_valzr1t4f elem_30){
  NI32 L_2 = (*s_137).len_0;
  NI32 X60Qx_3642 = capInBytes_0_Ihvsegh1_croph25r5((*s_137));
  if (X60Qx_3642 < ((NI32)(((NI32)(L_2 * sizeof(Value_0_valzr1t4f))) + sizeof(Value_0_valzr1t4f)))){
    NB8 X60Qx_3643 = resize_0_Iz8tg361_intzsnzax(s_137, 1);
    if ((!X60Qx_3643)){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&elem_30));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_137).len_0));
  (*s_137).data_0[L_2] = elem_30;}
static inline Value_0_valzr1t4f* getQ_7_Ine8yq71_intzsnzax(seq_0_I50urnw_croph25r5 s_140, NI32 i_94){
  NB8 X60Qx_3644;
  if (i_94 < s_140.len_0){
    X60Qx_3644 = (0 <= i_94);}
  else {
    X60Qx_3644 = NIM_FALSE;}
  if ((!X60Qx_3644)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  Value_0_valzr1t4f* result_190;
  result_190 = (&s_140.data_0[i_94]);
  return result_190;}
static inline void nimInvalidObjConv(string_0_sysvq0asl name_0){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1986947582u, .more_0 = (&strlit_0_I15539159382304113184_sysvq0asl)}
  );
  writeErr_2_sysvq0asl(name_0);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  exit(((NI32)1));}
static inline NI32 len_3_I4n9kvq_intzsnzax(seq_0_I50urnw_croph25r5 s_139){
  NI32 result_189;
  result_189 = s_139.len_0;
  return result_189;}
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
  openArray_0_In0ukmu_aow7lb5cq1 result_77;
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** X60Qx_1462 = rawData_0_Izez9p81_aow7lb5cq1(s_60);
  result_77 = (openArray_0_In0ukmu_aow7lb5cq1){
    .a_0 = X60Qx_1462, .len_0 = s_60.len_0}
  ;
  return result_77;}
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
static inline NI32 len_3_I44vue3_aow7lb5cq1(seq_0_Igzebks_aow7lb5cq1 s_59){
  NI32 result_76;
  result_76 = s_59.len_0;
  return result_76;}
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
  NI32 result_124;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_31, sizeof(X60Qt_0_IArefSX54ypeX44escX4fbj0layptix6a1_aow7lb5cq1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_124 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_124 = ((NI32)2147483647);}
  return result_124;}
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
  NI32 result_93;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_20, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_93 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_93 = ((NI32)2147483647);}
  return result_93;}
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
static inline WireField_0_run8hsnpi* rawData_0_Ijd497p_aow7lb5cq1(seq_0_Il8twp61_aow7lb5cq1 s_64){
  WireField_0_run8hsnpi* result_78;
  result_78 = s_64.data_0;
  return result_78;}
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
static inline NI32 memSizeInBytes_0_Itmy7ww1_croph25r5(NI32 size_15){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_51;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_15, sizeof(Value_0_valzr1t4f), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_51 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_51 = ((NI32)2147483647);}
  return result_51;}
static inline NI32 capInBytes_0_Ihvsegh1_croph25r5(seq_0_I50urnw_croph25r5 s_44){
  NI32 result_50;
  NI32 X60Qx_7;
  if ((!(s_44.data_0 == NIM_NIL))){
    NI32 X60Qx_154 = allocatedSize_0_sysvq0asl(((void*)((void*)s_44.data_0)));
    X60Qx_7 = X60Qx_154;}
  else {
    X60Qx_7 = 0;}
  result_50 = X60Qx_7;
  return result_50;}
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
  X60Qt_0_IArefSX53himX45ntryX4fbj0run8hsnpi_aow7lb5cq1** result_106;
  result_106 = s_72.data_0;
  return result_106;}
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
