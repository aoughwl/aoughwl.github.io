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
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct HookIndexEntry_0_nifa1znj21{
  NU32 typ_0;
  NU32 hook_0;
  NB8 isGeneric_0;}
HookIndexEntry_0_nifa1znj21;
typedef struct seq_0_Ig3ia49_nifa1znj21{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21* data_0;}
seq_0_Ig3ia49_nifa1znj21;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef struct IndexSections_0_nifa1znj21{
  seq_0_Ig3ia49_nifa1znj21 converters_0;
  TokenBuf_0_nifb6mq6y1 exportBuf_0;}
IndexSections_0_nifa1znj21;
typedef NU8 IndexVisibility_0_nifa1znj21;

#define Hidden_0_nifa1znj21 ((NU8)0)
#define Exported_0_nifa1znj21 ((NU8)1)
typedef struct NifIndexEntry_0_nifa1znj21{
  NI32 offset_0;
  NU32 info_0;
  IndexVisibility_0_nifa1znj21 vis_0;}
NifIndexEntry_0_nifa1znj21;
typedef struct seq_0_Ilvi9zw_nifa1znj21{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21* data_0;}
seq_0_Ilvi9zw_nifa1znj21;
typedef struct seq_0_Imzz798_nifa1znj21{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21* data_0;}
seq_0_Imzz798_nifa1znj21;
typedef struct NifIndex_0_nifa1znj21{
  seq_0_Ilvi9zw_nifa1znj21 converters_0;
  seq_0_Imzz798_nifa1znj21 exports_0;}
NifIndex_0_nifa1znj21;
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct seq_0_Irkj95k_nifa1znj21{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* data_0;}
seq_0_Irkj95k_nifa1znj21;
typedef struct seq_0_Ikxuplm1_filqx2b6r1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_filqx2b6r1;
typedef struct Table_0_Iyfwn301_nifa1znj21{
  seq_0_Irkj95k_nifa1znj21 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Iyfwn301_nifa1znj21;
typedef struct openArray_0_If8oj2w_nifa1znj21{
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21* a_0;
  NI32 len_0;}
openArray_0_If8oj2w_nifa1znj21;
typedef struct openArray_0_Ijk0jkw1_feaji4clb1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_feaji4clb1;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_In6doa_ast8ri79k keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_Izov3yo_ast8ri79k keys_0;}
BiTable_0_Ipgo74p_ast8ri79k;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
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
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21{
  NU32 fld_0;
  NU32 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1SR6_nifa1znj21;
typedef struct X60Qt_0_IAarrayAuS8ZS20_nif7eu7bj1{
  NU8 a[20];}
X60Qt_0_IAarrayAuS8ZS20_nif7eu7bj1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21{
  string_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21;
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
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21{
  string_0_sysvq0asl fld_0;
  NifIndexKind_0_nif12fhfr1 fld_1;
  seq_0_Izov3yo_ast8ri79k fld_2;}
X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21{
  string_0_sysvq0asl fld_0;
  NifIndexEntry_0_nifa1znj21 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
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
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct seq_0_Ivkh6l1_linxafkvx1{
  NI32 len_0;
  LineInfoUnpacked_0_linxafkvx1* data_0;}
seq_0_Ivkh6l1_linxafkvx1;
typedef struct LineInfoManager_0_linxafkvx1{
  seq_0_Ivkh6l1_linxafkvx1 aside_0;}
LineInfoManager_0_linxafkvx1;
typedef struct seq_0_If70loa_nifh7u8pu1{
  NI32 len_0;
  NU32* data_0;}
seq_0_If70loa_nifh7u8pu1;
typedef struct BiTable_0_Ieutpr21_nifh7u8pu1{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_If70loa_nifh7u8pu1 keys_0;}
BiTable_0_Ieutpr21_nifh7u8pu1;
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
  BiTable_0_Ieutpr21_nifh7u8pu1 files_0;
  BiTable_0_I0ksat5_ast8ri79k syms_0;
  BiTable_0_Ipgo74p_ast8ri79k strings_0;
  BiTable_0_Itvq7bk_ast8ri79k integers_0;
  BiTable_0_Itxao711_ast8ri79k uintegers_0;
  BiTable_0_Iojfwmy1_ast8ri79k floats_0;}
Literals_0_nifh7u8pu1;
typedef NU8 DirectivesResult_0_nif81dubp1;

#define WrongHeader_0_nif81dubp1 ((NU8)0)
#define WrongMeta_0_nif81dubp1 ((NU8)1)
#define Success_0_nif81dubp1 ((NU8)2)
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
static inline void add_0_I3qbx4y1_nifa1znj21(seq_0_Ilvi9zw_nifa1znj21* s_14, X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21 elem_3);
static inline seq_0_Ilvi9zw_nifa1znj21 newSeqUninit_0_Ihdba9y1_nifa1znj21(NI32 size_6);
static inline seq_0_Imzz798_nifa1znj21 newSeqUninit_0_I29q3sg_nifa1znj21(NI32 size_8);
static inline void add_0_Ir9zc7r1_nifa1znj21(seq_0_Imzz798_nifa1znj21* s_18, X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 elem_5);
Table_0_Iyfwn301_nifa1znj21 initTable_0_Igzeek4_nifa1znj21(void);
void putQ_0_Iaeqq6y_nifa1znj21(Table_0_Iyfwn301_nifa1znj21* t_15, string_0_sysvq0asl k_2, NifIndexEntry_0_nifa1znj21 v_3);
static inline NI32 capInBytes_0_I3z3fql_nifa1znj21(seq_0_Ilvi9zw_nifa1znj21 s_29);
NB8 resize_0_Irkn77m1_nifa1znj21(seq_0_Ilvi9zw_nifa1znj21* dest_4, NI32 addedElements_3);
static inline NI32 memSizeInBytes_0_Iwy52zt1_nifa1znj21(NI32 size_15);
static inline NI32 memSizeInBytes_0_Iecjnu51_nifa1znj21(NI32 size_16);
static inline NI32 capInBytes_0_Iwb6i161_nifa1znj21(seq_0_Imzz798_nifa1znj21 s_31);
NB8 resize_0_Iogmdb61_nifa1znj21(seq_0_Imzz798_nifa1znj21* dest_6, NI32 addedElements_5);
static inline seq_0_Irkj95k_nifa1znj21 newSeqUninit_0_Igwcld2_nifa1znj21(NI32 size_18);
NI32 rawGet_0_Ilpzx5l1_nifa1znj21(Table_0_Iyfwn301_nifa1znj21 t_19, string_0_sysvq0asl k_5, NU32 kh_1);
static inline X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* getQ_7_I1m5sw7_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_47, NI32 i_16);
void rawPut_0_Iujg1bp1_nifa1znj21(Table_0_Iyfwn301_nifa1znj21* t_20, string_0_sysvq0asl k_6, NifIndexEntry_0_nifa1znj21 v_5, NU32 h_4);
static inline NI32 memSizeInBytes_0_Imuag1k_nifa1znj21(NI32 size_22);
static inline NI32 len_3_Ikddlyh1_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_58);
void fillHashPart_0_Izlqcme1_nifa1znj21(Table_0_Iyfwn301_nifa1znj21* t_22);
static inline void add_0_Isv2voo1_nifa1znj21(seq_0_Irkj95k_nifa1znj21* s_62, X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 elem_12);
static inline NI32 capInBytes_0_Izw3nef1_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_66);
NB8 resize_0_Iwd40sa1_nifa1znj21(seq_0_Irkj95k_nifa1znj21* dest_12, NI32 addedElements_11);
void eQdestroyQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21(NifIndex_0_nifa1znj21 dest_0);
void eQwasmovedQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21(NifIndex_0_nifa1znj21* dest_0);
void eQdestroyQ_SX54able0X49yfwn301_0_nifa1znj21(Table_0_Iyfwn301_nifa1znj21 dest_0);
void eQwasmovedQ_SX54able0X49yfwn301_0_nifa1znj21(Table_0_Iyfwn301_nifa1znj21* dest_0);
void eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_nifa1znj21(X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21 dest_0);
void eQdestroyQ_AtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_0_nifa1znj21(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 dest_0);
void eQdestroyQ_AtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_0_nifa1znj21(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 dest_0);
extern PackedToken_0_nifh7u8pu1 next_0_nifh7u8pu1(Stream_0_nifh7u8pu1* s_5);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
static inline NB8 eqQ_5_nifh7u8pu1(NU32 a_5, NU32 b_5);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline NU32 litId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_9);
static inline string_0_sysvq0asl* getQ_0_Iplpzal1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k t_6, NU32 litId_5);
extern void raiseAssert_0_assy765wm(string_0_sysvq0asl msg_1);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
extern Stream_0_nifh7u8pu1 open_0_nifh7u8pu1(string_0_sysvq0asl filename_0);
extern DirectivesResult_0_nif81dubp1 processDirectives_0_nif81dubp1(Reader_0_nif81dubp1* r_11);
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16);
static inline seq_0_Izov3yo_ast8ri79k newSeqUninit_0_In7hr9h_ast8ri79k(NI32 size_21);
static inline void add_0_Ixkocf1_ide5ljwgh1(seq_0_Izov3yo_ast8ri79k* s_14, NU32 elem_6);
static inline void eQwasMoved_1_I94uyip1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_49);
extern void eQdestroy_1_In04crl1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_48);
extern void eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1(Stream_0_nifh7u8pu1* dest_0);
extern NI32 indexStartsAt_0_nif81dubp1(Reader_0_nif81dubp1* r_15);
static inline NI32 offset_0_nif81dubp1(Reader_0_nif81dubp1* r_13);
static inline void jumpTo_0_nif81dubp1(Reader_0_nif81dubp1* r_14, NI32 offset_0);
extern NU32 getOrIncl_0_Is83dq9_buiyylk1h1(BiTable_0_Icvz6lt_buiyylk1h1* t_3, string_0_sysvq0asl v_3);
static inline string_0_sysvq0asl* getQ_0_I93d71y_comaa5xpt1(BiTable_0_Icvz6lt_buiyylk1h1 t_21, NU32 litId_6);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12);
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline seq_0_Ikxuplm1_filqx2b6r1 newSeqUninit_0_Iie69x21_filqx2b6r1(NI32 size_13);
extern NU32 hash_1_has9tn57v(string_0_sysvq0asl s_0);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
static inline NI32 high_3_Iyuup9h1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_17);
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_18, NU32 i_9);
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2);
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
static inline NI32 len_3_Iiefpcc1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_19);
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0);
extern void resize_0_tabcr240b1(seq_0_Ikxuplm1_filqx2b6r1* t_0);
static inline void putQ_8_Ipchg2a_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_22, NU32 i_11, HashEntry_0_tabcr240b1 elem_5);
extern void eQdestroy_1_I5skmro_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_34);
extern seq_0_Ikxuplm1_filqx2b6r1 newSeq_0_Iv3lu2h1_filqx2b6r1(NI32 size_5);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline void eQwasMoved_1_I8aeezd1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_35);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tabcr240b1(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_has9tn57v(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_str7j0ifg(void);
extern void X60Qini_0_bitekkhcx1(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nif7eu7bj1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_tagygirdh1(void);
extern void X60Qini_0_nif12fhfr1(void);
extern void X60Qini_0_shaw6o8p31(void);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern NU32 const ErrT_0_nifh7u8pu1;
static inline NI32 memSizeInBytes_0_Iu5tdzt_ast8ri79k(NI32 size_5);
static inline NI32 capInBytes_0_I2v1dsn1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_29);
extern NB8 resize_0_Itvf2zj1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* dest_3, NI32 addedElements_3);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
static inline NI32 memSizeInBytes_0_Ilp7p16_filqx2b6r1(NI32 size_8);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
LongString_0_sysvq0asl const strlit_0_I3766396236263132858_nifa1znj21 = {
  .fullLen_0 = 39, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "invalid (kv) construct: symbol expected"}
;
LongString_0_sysvq0asl const strlit_0_I1238133175560029754_nifa1znj21 = {
  .fullLen_0 = 36, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "invalid (kv) construct: \')\' expected"}
;
LongString_0_sysvq0asl const strlit_0_I12580956342669616395_nifa1znj21 = {
  .fullLen_0 = 23, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "expected (kv) construct"}
;
LongString_0_sysvq0asl const strlit_0_I349988152327552405_nifa1znj21 = {
  .fullLen_0 = 20, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "expected \'index\' tag"}
;
LongString_0_sysvq0asl const strlit_0_I3971089468521913333_nifa1znj21 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".index"}
;
LongString_0_sysvq0asl const strlit_0_I13965700393025800564_nifa1znj21 = {
  .fullLen_0 = 39, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "invalid (kv) in .index: symbol expected"}
;
NB8 X60QiniGuard_0_nifa1znj21;
void readSymbolSection_0_nifa1znj21(Stream_0_nifh7u8pu1* s_1, seq_0_Ilvi9zw_nifa1znj21* tab_0){
  PackedToken_0_nifh7u8pu1 t_0 = next_0_nifh7u8pu1(s_1);
  NI32 nested_1 = 1;
  {
    while ((!(((NifKind_0_nif81dubp1)((NU32)(t_0.x_0 & ((NU32)15u)))) == 1))){
      if (((NifKind_0_nif81dubp1)((NU32)(t_0.x_0 & ((NU32)15u)))) == 11){
        inc_1_I6wjjge_aow2h993l1((&nested_1));
        NU32 X60Qx_42 = tagId_0_nifh7u8pu1(t_0);
        NB8 X60Qx_43 = eqQ_5_nifh7u8pu1(X60Qx_42, ((NU32)30));
        if (X60Qx_43){
          PackedToken_0_nifh7u8pu1 X60Qx_44 = next_0_nifh7u8pu1(s_1);
          t_0 = X60Qx_44;
          string_0_sysvq0asl key_1;
          nimStrWasMoved((&key_1));
          if (((NifKind_0_nif81dubp1)((NU32)(t_0.x_0 & ((NU32)15u)))) == 4){
            nimStrDestroy(key_1);
            NU32 X60Qx_45 = symId_0_nifh7u8pu1(t_0);
            string_0_sysvq0asl* X60Qx_46 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, X60Qx_45);
            string_0_sysvq0asl X60Qx_47 = nimStrDup((*X60Qx_46));
            key_1 = X60Qx_47;}
          else {
            if (((NifKind_0_nif81dubp1)((NU32)(t_0.x_0 & ((NU32)15u)))) == 3){
              nimStrDestroy(key_1);
              NU32 X60Qx_48 = litId_0_nifh7u8pu1(t_0);
              string_0_sysvq0asl* X60Qx_49 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_48);
              string_0_sysvq0asl X60Qx_50 = nimStrDup((*X60Qx_49));
              key_1 = X60Qx_50;}
            else {
              if (((NifKind_0_nif81dubp1)((NU32)(t_0.x_0 & ((NU32)15u)))) == 2){
                nimStrDestroy(key_1);
                key_1 = (string_0_sysvq0asl){
                  .bytes_0 = 11777u, .more_0 = NIM_NIL}
                ;}
              else {
                raiseAssert_0_assy765wm((string_0_sysvq0asl){
                  .bytes_0 = 1986947582u, .more_0 = (&strlit_0_I3766396236263132858_nifa1znj21)}
                );}}}
          PackedToken_0_nifh7u8pu1 X60Qx_51 = next_0_nifh7u8pu1(s_1);
          t_0 = X60Qx_51;
          string_0_sysvq0asl value_1;
          nimStrWasMoved((&value_1));
          if (((NifKind_0_nif81dubp1)((NU32)(t_0.x_0 & ((NU32)15u)))) == 4){
            nimStrDestroy(value_1);
            NU32 X60Qx_52 = symId_0_nifh7u8pu1(t_0);
            string_0_sysvq0asl* X60Qx_53 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, X60Qx_52);
            string_0_sysvq0asl X60Qx_54 = nimStrDup((*X60Qx_53));
            value_1 = X60Qx_54;}
          else {
            if (((NifKind_0_nif81dubp1)((NU32)(t_0.x_0 & ((NU32)15u)))) == 3){
              nimStrDestroy(value_1);
              NU32 X60Qx_55 = litId_0_nifh7u8pu1(t_0);
              string_0_sysvq0asl* X60Qx_56 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_55);
              string_0_sysvq0asl X60Qx_57 = nimStrDup((*X60Qx_56));
              value_1 = X60Qx_57;}
            else {
              raiseAssert_0_assy765wm((string_0_sysvq0asl){
                .bytes_0 = 1986947582u, .more_0 = (&strlit_0_I3766396236263132858_nifa1znj21)}
              );}}
          PackedToken_0_nifh7u8pu1 X60Qx_58 = next_0_nifh7u8pu1(s_1);
          t_0 = X60Qx_58;
          string_0_sysvq0asl X60Qtmp_3 = key_1;
          nimStrWasMoved((&key_1));
          string_0_sysvq0asl X60Qtmp_4 = value_1;
          nimStrWasMoved((&value_1));
          add_0_I3qbx4y1_nifa1znj21(tab_0, (X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21){
            .fld_0 = X60Qtmp_3, .fld_1 = X60Qtmp_4}
          );
          if (((NifKind_0_nif81dubp1)((NU32)(t_0.x_0 & ((NU32)15u)))) == 12){
            PackedToken_0_nifh7u8pu1 X60Qx_59 = next_0_nifh7u8pu1(s_1);
            t_0 = X60Qx_59;
            dec_1_I0nzoz91_ast8ri79k((&nested_1));}
          else {
            if ((!NIM_FALSE)){
              write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
              );
              write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                .bytes_0 = 1986947582u, .more_0 = (&strlit_0_I1238133175560029754_nifa1znj21)}
              );
              write_7_syn1lfpjv(stdout, (NC8)'\012');
              quit_0_syn1lfpjv(1);}}
          nimStrDestroy(value_1);
          nimStrDestroy(key_1);}
        else {
          if ((!NIM_FALSE)){
            write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
              .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
            );
            write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
              .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I12580956342669616395_nifa1znj21)}
            );
            write_7_syn1lfpjv(stdout, (NC8)'\012');
            quit_0_syn1lfpjv(1);}}}
      else {
        if (((NifKind_0_nif81dubp1)((NU32)(t_0.x_0 & ((NU32)15u)))) == 12){
          dec_1_I0nzoz91_ast8ri79k((&nested_1));
          if (nested_1 == 0){
            goto whileStmtLabel_0;}
          PackedToken_0_nifh7u8pu1 X60Qx_60 = next_0_nifh7u8pu1(s_1);
          t_0 = X60Qx_60;}
        else {
          if ((!NIM_FALSE)){
            write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
              .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
            );
            write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
              .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I12580956342669616395_nifa1znj21)}
            );
            write_7_syn1lfpjv(stdout, (NC8)'\012');
            quit_0_syn1lfpjv(1);}}}}}
  whileStmtLabel_0: ;}
NifIndex_0_nifa1znj21 readIndex_0_nifa1znj21(string_0_sysvq0asl indexName_0){
  NifIndex_0_nifa1znj21 result_5;
  eQwasmovedQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21((&result_5));
  Stream_0_nifh7u8pu1 s_7 = open_0_nifh7u8pu1(indexName_0);
  DirectivesResult_0_nif81dubp1 res_0 = processDirectives_0_nif81dubp1((&s_7.r_0));
  if ((!(res_0 == ((DirectivesResult_0_nif81dubp1)2)))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  eQdestroyQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21(result_5);
  seq_0_Ilvi9zw_nifa1znj21 X60Qx_61 = newSeqUninit_0_Ihdba9y1_nifa1znj21(0);
  seq_0_Imzz798_nifa1znj21 X60Qx_62 = newSeqUninit_0_I29q3sg_nifa1znj21(0);
  result_5 = (NifIndex_0_nifa1znj21){
    .converters_0 = X60Qx_61, .exports_0 = X60Qx_62}
  ;
  PackedToken_0_nifh7u8pu1 t_3 = next_0_nifh7u8pu1((&s_7));
  NU32 X60Qx_63 = tag_0_nifh7u8pu1(t_3);
  NB8 X60Qx_64 = eqQ_5_nifh7u8pu1(X60Qx_63, ((NU32)302));
  if ((!X60Qx_64)){
    if ((!NIM_FALSE)){
      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
        .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
      );
      write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
        .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I349988152327552405_nifa1znj21)}
      );
      write_7_syn1lfpjv(stdout, (NC8)'\012');
      quit_0_syn1lfpjv(1);}}
  PackedToken_0_nifh7u8pu1 X60Qx_65 = next_0_nifh7u8pu1((&s_7));
  t_3 = X60Qx_65;
  {
    while (NIM_TRUE){
      NB8 X60Qx_66;
      if ((!(((NifKind_0_nif81dubp1)((NU32)(t_3.x_0 & ((NU32)15u)))) == 12))){
        X60Qx_66 = (!(((NifKind_0_nif81dubp1)((NU32)(t_3.x_0 & ((NU32)15u)))) == 1));}
      else {
        X60Qx_66 = NIM_FALSE;}
      if (X60Qx_66){
        if (((NifKind_0_nif81dubp1)((NU32)(t_3.x_0 & ((NU32)15u)))) == 11){
          NU32 X60Qx_67 = tagId_0_nifh7u8pu1(t_3);
          switch (X60Qx_67){
            case ((NU32)73):
            {
              readSymbolSection_0_nifa1znj21((&s_7), (&result_5.converters_0));
              PackedToken_0_nifh7u8pu1 X60Qx_68 = next_0_nifh7u8pu1((&s_7));
              t_3 = X60Qx_68;}
            break;
            case ((NU32)153):
            case ((NU32)154):
            case ((NU32)155):
            {
              NU32 X60Qx_69 = tag_0_nifh7u8pu1(t_3);
              NifIndexKind_0_nif12fhfr1 kind_0 = ((NifIndexKind_0_nif12fhfr1)X60Qx_69);
              PackedToken_0_nifh7u8pu1 X60Qx_70 = next_0_nifh7u8pu1((&s_7));
              t_3 = X60Qx_70;
              if ((!(((NifKind_0_nif81dubp1)((NU32)(t_3.x_0 & ((NU32)15u)))) == 6))){
                write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                  .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
                );
                write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                  .bytes_0 = 0u, .more_0 = NIM_NIL}
                );
                write_7_syn1lfpjv(stdout, (NC8)'\012');
                quit_0_syn1lfpjv(1);}
              NU32 X60Qx_71 = litId_0_nifh7u8pu1(t_3);
              string_0_sysvq0asl* X60Qx_72 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_71);
              string_0_sysvq0asl path_0 = nimStrDup((*X60Qx_72));
              PackedToken_0_nifh7u8pu1 X60Qx_73 = next_0_nifh7u8pu1((&s_7));
              t_3 = X60Qx_73;
              seq_0_Izov3yo_ast8ri79k names_0 = newSeqUninit_0_In7hr9h_ast8ri79k(0);
              {
                while ((!(((NifKind_0_nif81dubp1)((NU32)(t_3.x_0 & ((NU32)15u)))) == 12))){
                  if ((!(((NifKind_0_nif81dubp1)((NU32)(t_3.x_0 & ((NU32)15u)))) == 3))){
                    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
                    );
                    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
                      .bytes_0 = 0u, .more_0 = NIM_NIL}
                    );
                    write_7_syn1lfpjv(stdout, (NC8)'\012');
                    quit_0_syn1lfpjv(1);}
                  NU32 X60Qx_74 = litId_0_nifh7u8pu1(t_3);
                  add_0_Ixkocf1_ide5ljwgh1((&names_0), X60Qx_74);
                  PackedToken_0_nifh7u8pu1 X60Qx_75 = next_0_nifh7u8pu1((&s_7));
                  t_3 = X60Qx_75;}}
              whileStmtLabel_1: ;
              string_0_sysvq0asl X60Qtmp_5 = path_0;
              nimStrWasMoved((&path_0));
              seq_0_Izov3yo_ast8ri79k X60Qtmp_6 = names_0;
              eQwasMoved_1_I94uyip1_ast8ri79k((&names_0));
              add_0_Ir9zc7r1_nifa1znj21((&result_5.exports_0), (X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21){
                .fld_0 = X60Qtmp_5, .fld_1 = kind_0, .fld_2 = X60Qtmp_6}
              );
              PackedToken_0_nifh7u8pu1 X60Qx_76 = next_0_nifh7u8pu1((&s_7));
              t_3 = X60Qx_76;
              eQdestroy_1_In04crl1_ast8ri79k(names_0);
              nimStrDestroy(path_0);}
            break;
            default:
            {
              NI32 nested_2 = 1;
              PackedToken_0_nifh7u8pu1 X60Qx_77 = next_0_nifh7u8pu1((&s_7));
              t_3 = X60Qx_77;
              {
                while ((!(((NifKind_0_nif81dubp1)((NU32)(t_3.x_0 & ((NU32)15u)))) == 1))){
                  switch (((NifKind_0_nif81dubp1)((NU32)(t_3.x_0 & ((NU32)15u))))){
                    case 11:
                    {
                      inc_1_I6wjjge_aow2h993l1((&nested_2));}
                    break;
                    case 12:
                    {
                      dec_1_I0nzoz91_ast8ri79k((&nested_2));
                      if (nested_2 == 0){
                        goto whileStmtLabel_2;}}
                    break;
                    default:
                    {
                      }
                    break;}
                  PackedToken_0_nifh7u8pu1 X60Qx_78 = next_0_nifh7u8pu1((&s_7));
                  t_3 = X60Qx_78;}}
              whileStmtLabel_2: ;
              PackedToken_0_nifh7u8pu1 X60Qx_79 = next_0_nifh7u8pu1((&s_7));
              t_3 = X60Qx_79;}
            break;}}
        else {
          PackedToken_0_nifh7u8pu1 X60Qx_80 = next_0_nifh7u8pu1((&s_7));
          t_3 = X60Qx_80;}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1((&s_7));
  return result_5;
  eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1((&s_7));
  return result_5;}
Table_0_Iyfwn301_nifa1znj21 readEmbeddedIndex_0_nifa1znj21(Stream_0_nifh7u8pu1* s_2){
  Table_0_Iyfwn301_nifa1znj21 result_6;
  eQwasmovedQ_SX54able0X49yfwn301_0_nifa1znj21((&result_6));
  eQdestroyQ_SX54able0X49yfwn301_0_nifa1znj21(result_6);
  Table_0_Iyfwn301_nifa1znj21 X60Qx_81 = initTable_0_Igzeek4_nifa1znj21();
  result_6 = X60Qx_81;
  NI32 indexPos_0 = indexStartsAt_0_nif81dubp1((&(*s_2).r_0));
  if (indexPos_0 <= 0){
    return result_6;}
  NI32 contentPos_0 = offset_0_nif81dubp1((&(*s_2).r_0));
  jumpTo_0_nif81dubp1((&(*s_2).r_0), indexPos_0);
  NI32 previousOffset_0 = 0;
  PackedToken_0_nifh7u8pu1 t_4 = next_0_nifh7u8pu1(s_2);
  NU32 exportedTagId_0 = getOrIncl_0_Is83dq9_buiyylk1h1((&pool_0_nifh7u8pu1.tags_0), (string_0_sysvq0asl){
    .bytes_0 = 30721u, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_82;
  if (((NifKind_0_nif81dubp1)((NU32)(t_4.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_83 = tagId_0_nifh7u8pu1(t_4);
    string_0_sysvq0asl* X60Qx_84 = getQ_0_I93d71y_comaa5xpt1(pool_0_nifh7u8pu1.tags_0, X60Qx_83);
    NB8 X60Qx_85 = eqQ_20_sysvq0asl((*X60Qx_84), (string_0_sysvq0asl){
      .bytes_0 = 1852387070u, .more_0 = (&strlit_0_I3971089468521913333_nifa1znj21)}
    );
    X60Qx_82 = X60Qx_85;}
  else {
    X60Qx_82 = NIM_FALSE;}
  if (X60Qx_82){
    PackedToken_0_nifh7u8pu1 X60Qx_86 = next_0_nifh7u8pu1(s_2);
    t_4 = X60Qx_86;
    {
      while (NIM_TRUE){
        NB8 X60Qx_87;
        if ((!(((NifKind_0_nif81dubp1)((NU32)(t_4.x_0 & ((NU32)15u)))) == 1))){
          X60Qx_87 = (!(((NifKind_0_nif81dubp1)((NU32)(t_4.x_0 & ((NU32)15u)))) == 12));}
        else {
          X60Qx_87 = NIM_FALSE;}
        if (X60Qx_87){
          if (((NifKind_0_nif81dubp1)((NU32)(t_4.x_0 & ((NU32)15u)))) == 11){
            IndexVisibility_0_nifa1znj21 X60Qx_2;
            NU32 X60Qx_88 = tagId_0_nifh7u8pu1(t_4);
            NB8 X60Qx_89 = eqQ_5_nifh7u8pu1(X60Qx_88, exportedTagId_0);
            if (X60Qx_89){
              X60Qx_2 = 1;}
            else {
              X60Qx_2 = 0;}
            IndexVisibility_0_nifa1znj21 vis_0 = X60Qx_2;
            NU32 info_0 = t_4.info_0;
            PackedToken_0_nifh7u8pu1 X60Qx_90 = next_0_nifh7u8pu1(s_2);
            t_4 = X60Qx_90;
            string_0_sysvq0asl key_2 = (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            ;
            if (((NifKind_0_nif81dubp1)((NU32)(t_4.x_0 & ((NU32)15u)))) == 4){
              nimStrDestroy(key_2);
              NU32 X60Qx_91 = symId_0_nifh7u8pu1(t_4);
              string_0_sysvq0asl* X60Qx_92 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, X60Qx_91);
              string_0_sysvq0asl X60Qx_93 = nimStrDup((*X60Qx_92));
              key_2 = X60Qx_93;}
            else {
              raiseAssert_0_assy765wm((string_0_sysvq0asl){
                .bytes_0 = 1986947582u, .more_0 = (&strlit_0_I13965700393025800564_nifa1znj21)}
              );}
            PackedToken_0_nifh7u8pu1 X60Qx_94 = next_0_nifh7u8pu1(s_2);
            t_4 = X60Qx_94;
            if (((NifKind_0_nif81dubp1)((NU32)(t_4.x_0 & ((NU32)15u)))) == 8){
              NU32 X60Qx_95 = intId_0_nifh7u8pu1(t_4);
              NI64* X60Qx_96 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_95);
              NI32 offset_0 = ((NI32)(((NI32)(*X60Qx_96)) + previousOffset_0));
              string_0_sysvq0asl X60Qtmp_7 = key_2;
              nimStrWasMoved((&key_2));
              putQ_0_Iaeqq6y_nifa1znj21((&result_6), X60Qtmp_7, (NifIndexEntry_0_nifa1znj21){
                .offset_0 = offset_0, .info_0 = info_0, .vis_0 = vis_0}
              );
              previousOffset_0 = offset_0;}
            PackedToken_0_nifh7u8pu1 X60Qx_97 = next_0_nifh7u8pu1(s_2);
            t_4 = X60Qx_97;
            if (((NifKind_0_nif81dubp1)((NU32)(t_4.x_0 & ((NU32)15u)))) == 12){
              PackedToken_0_nifh7u8pu1 X60Qx_98 = next_0_nifh7u8pu1(s_2);
              t_4 = X60Qx_98;}
            nimStrDestroy(key_2);}
          else {
            PackedToken_0_nifh7u8pu1 X60Qx_99 = next_0_nifh7u8pu1(s_2);
            t_4 = X60Qx_99;}}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  jumpTo_0_nif81dubp1((&(*s_2).r_0), contentPos_0);
  return result_6;}
static inline void add_0_I3qbx4y1_nifa1znj21(seq_0_Ilvi9zw_nifa1znj21* s_14, X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21 elem_3){
  NI32 L_0 = (*s_14).len_0;
  NI32 X60Qx_105 = capInBytes_0_I3z3fql_nifa1znj21((*s_14));
  if (X60Qx_105 < ((NI32)(((NI32)(L_0 * sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21))) + sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21)))){
    NB8 X60Qx_106 = resize_0_Irkn77m1_nifa1znj21(s_14, 1);
    if ((!X60Qx_106)){
      eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_nifa1znj21(elem_3);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_14).len_0));
  (*s_14).data_0[L_0] = elem_3;}
static inline seq_0_Ilvi9zw_nifa1znj21 newSeqUninit_0_Ihdba9y1_nifa1znj21(NI32 size_6){
  seq_0_Ilvi9zw_nifa1znj21 result_12;
  if (size_6 == 0){
    result_12 = (seq_0_Ilvi9zw_nifa1znj21){
      .len_0 = size_6, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Iwy52zt1_nifa1znj21(size_6);
    void* X60Qx_107 = alloc_1_sysvq0asl(memSize_1);
    result_12 = (seq_0_Ilvi9zw_nifa1znj21){
      .len_0 = size_6, .data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21*)X60Qx_107)}
    ;
    if ((!(result_12.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_108 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_12.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_12;}
static inline seq_0_Imzz798_nifa1znj21 newSeqUninit_0_I29q3sg_nifa1znj21(NI32 size_8){
  seq_0_Imzz798_nifa1znj21 result_13;
  if (size_8 == 0){
    result_13 = (seq_0_Imzz798_nifa1znj21){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Iecjnu51_nifa1znj21(size_8);
    void* X60Qx_109 = alloc_1_sysvq0asl(memSize_2);
    result_13 = (seq_0_Imzz798_nifa1znj21){
      .len_0 = size_8, .data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21*)X60Qx_109)}
    ;
    if ((!(result_13.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_110 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_13.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_13;}
static inline void add_0_Ir9zc7r1_nifa1znj21(seq_0_Imzz798_nifa1znj21* s_18, X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 elem_5){
  NI32 L_2 = (*s_18).len_0;
  NI32 X60Qx_115 = capInBytes_0_Iwb6i161_nifa1znj21((*s_18));
  if (X60Qx_115 < ((NI32)(((NI32)(L_2 * sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21))) + sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21)))){
    NB8 X60Qx_116 = resize_0_Iogmdb61_nifa1znj21(s_18, 1);
    if ((!X60Qx_116)){
      eQdestroyQ_AtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_0_nifa1znj21(elem_5);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_18).len_0));
  (*s_18).data_0[L_2] = elem_5;}
Table_0_Iyfwn301_nifa1znj21 initTable_0_Igzeek4_nifa1znj21(void){
  Table_0_Iyfwn301_nifa1znj21 result_15;
  eQwasmovedQ_SX54able0X49yfwn301_0_nifa1znj21((&result_15));
  eQdestroyQ_SX54able0X49yfwn301_0_nifa1znj21(result_15);
  seq_0_Irkj95k_nifa1znj21 X60Qx_117 = newSeqUninit_0_Igwcld2_nifa1znj21(0);
  seq_0_Ikxuplm1_filqx2b6r1 X60Qx_118 = newSeqUninit_0_Iie69x21_filqx2b6r1(0);
  result_15 = (Table_0_Iyfwn301_nifa1znj21){
    .data_0 = X60Qx_117, .hashes_0 = X60Qx_118}
  ;
  return result_15;}
void putQ_0_Iaeqq6y_nifa1znj21(Table_0_Iyfwn301_nifa1znj21* t_15, string_0_sysvq0asl k_2, NifIndexEntry_0_nifa1znj21 v_3){
  NU32 h_1 = hash_1_has9tn57v(k_2);
  NI32 idx_6 = rawGet_0_Ilpzx5l1_nifa1znj21((*t_15), k_2, h_1);
  if (0 <= idx_6){
    X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* X60Qx_135 = getQ_7_I1m5sw7_nifa1znj21((*t_15).data_0, idx_6);
    (*X60Qx_135).fld_1 = v_3;}
  else {
    string_0_sysvq0asl X60Qtmp_8 = k_2;
    nimStrWasMoved((&k_2));
    rawPut_0_Iujg1bp1_nifa1znj21(t_15, X60Qtmp_8, v_3, h_1);}
  nimStrDestroy(k_2);}
static inline NI32 capInBytes_0_I3z3fql_nifa1znj21(seq_0_Ilvi9zw_nifa1znj21 s_29){
  NI32 result_26;
  NI32 X60Qx_3;
  if ((!(s_29.data_0 == NIM_NIL))){
    NI32 X60Qx_139 = allocatedSize_0_sysvq0asl(((void*)((void*)s_29.data_0)));
    X60Qx_3 = X60Qx_139;}
  else {
    X60Qx_3 = 0;}
  result_26 = X60Qx_3;
  return result_26;}
NB8 resize_0_Irkn77m1_nifa1znj21(seq_0_Ilvi9zw_nifa1znj21* dest_4, NI32 addedElements_3){
  NB8 result_27;
  NI32 X60Qx_140 = capInBytes_0_I3z3fql_nifa1znj21((*dest_4));
  NI32 oldCap_0 = ((NI32)(X60Qx_140 / sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_3);
  NI32 memSize_4 = memSizeInBytes_0_Iwy52zt1_nifa1znj21(newCap_0);
  void* X60Qx_141 = realloc_1_sysvq0asl(((void*)((void*)(*dest_4).data_0)), memSize_4);
  (*dest_4).data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21*)X60Qx_141);
  if ((*dest_4).data_0 == NIM_NIL){
    (*dest_4).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_4);
    result_27 = NIM_FALSE;}
  else {
    result_27 = NIM_TRUE;}
  return result_27;}
static inline NI32 memSizeInBytes_0_Iwy52zt1_nifa1znj21(NI32 size_15){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_28;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_15, sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_28 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_28 = ((NI32)2147483647);}
  return result_28;}
static inline NI32 memSizeInBytes_0_Iecjnu51_nifa1znj21(NI32 size_16){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_29;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_16, sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_29 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_29 = ((NI32)2147483647);}
  return result_29;}
static inline NI32 capInBytes_0_Iwb6i161_nifa1znj21(seq_0_Imzz798_nifa1znj21 s_31){
  NI32 result_33;
  NI32 X60Qx_5;
  if ((!(s_31.data_0 == NIM_NIL))){
    NI32 X60Qx_145 = allocatedSize_0_sysvq0asl(((void*)((void*)s_31.data_0)));
    X60Qx_5 = X60Qx_145;}
  else {
    X60Qx_5 = 0;}
  result_33 = X60Qx_5;
  return result_33;}
NB8 resize_0_Iogmdb61_nifa1znj21(seq_0_Imzz798_nifa1znj21* dest_6, NI32 addedElements_5){
  NB8 result_34;
  NI32 X60Qx_146 = capInBytes_0_Iwb6i161_nifa1znj21((*dest_6));
  NI32 oldCap_2 = ((NI32)(X60Qx_146 / sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_5);
  NI32 memSize_6 = memSizeInBytes_0_Iecjnu51_nifa1znj21(newCap_2);
  void* X60Qx_147 = realloc_1_sysvq0asl(((void*)((void*)(*dest_6).data_0)), memSize_6);
  (*dest_6).data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21*)X60Qx_147);
  if ((*dest_6).data_0 == NIM_NIL){
    (*dest_6).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_6);
    result_34 = NIM_FALSE;}
  else {
    result_34 = NIM_TRUE;}
  return result_34;}
static inline seq_0_Irkj95k_nifa1znj21 newSeqUninit_0_Igwcld2_nifa1znj21(NI32 size_18){
  seq_0_Irkj95k_nifa1znj21 result_35;
  if (size_18 == 0){
    result_35 = (seq_0_Irkj95k_nifa1znj21){
      .len_0 = size_18, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_7 = memSizeInBytes_0_Imuag1k_nifa1znj21(size_18);
    void* X60Qx_148 = alloc_1_sysvq0asl(memSize_7);
    result_35 = (seq_0_Irkj95k_nifa1znj21){
      .len_0 = size_18, .data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21*)X60Qx_148)}
    ;
    if ((!(result_35.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_149 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_35.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_7);}}
  return result_35;}
NI32 rawGet_0_Ilpzx5l1_nifa1znj21(Table_0_Iyfwn301_nifa1znj21 t_19, string_0_sysvq0asl k_5, NU32 kh_1){
  NI32 result_40;
  NI32 X60Qx_165 = len_3_Ikddlyh1_nifa1znj21(t_19.data_0);
  if (X60Qx_165 <= ((NI32)4)){
    {
      NI32 X60Qlf_7 = 0;
      NI32 X60Qlf_8 = len_3_Ikddlyh1_nifa1znj21(t_19.data_0);
      NI32 X60Qlf_9 = X60Qlf_7;
      {
        while (X60Qlf_9 < X60Qlf_8){
          {
            X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* X60Qx_166 = getQ_7_I1m5sw7_nifa1znj21(t_19.data_0, X60Qlf_9);
            NB8 X60Qx_167 = eqQ_20_sysvq0asl((*X60Qx_166).fld_0, k_5);
            if (X60Qx_167){
              return X60Qlf_9;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_168 = high_3_Iyuup9h1_filqx2b6r1(t_19.hashes_0);
    NU32 h_3 = ((NU32)(kh_1 & ((NU32)X60Qx_168)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_169 = getQ_8_Imt2zi01_filqx2b6r1(t_19.hashes_0, h_3);
        NB8 X60Qx_170 = isFilled_0_tabcr240b1((*X60Qx_169));
        if (X60Qx_170){
          HashEntry_0_tabcr240b1* X60Qx_171 = getQ_8_Imt2zi01_filqx2b6r1(t_19.hashes_0, h_3);
          HashEntry_0_tabcr240b1 d_0 = (*X60Qx_171);
          NB8 X60Qx_172;
          if (d_0.fullhash_0 == kh_1){
            X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* X60Qx_173 = getQ_7_I1m5sw7_nifa1znj21(t_19.data_0, ((NI32)(d_0.position_0 - 1)));
            NB8 X60Qx_174 = eqQ_20_sysvq0asl((*X60Qx_173).fld_0, k_5);
            X60Qx_172 = X60Qx_174;}
          else {
            X60Qx_172 = NIM_FALSE;}
          if (X60Qx_172){
            result_40 = ((NI32)(d_0.position_0 - 1));
            return result_40;}
          NI32 X60Qx_175 = high_3_Iyuup9h1_filqx2b6r1(t_19.hashes_0);
          NU32 X60Qx_176 = nextTry_0_has9tn57v(h_3, X60Qx_175);
          h_3 = X60Qx_176;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_40 = -1;
  return result_40;}
static inline X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* getQ_7_I1m5sw7_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_47, NI32 i_16){
  NB8 X60Qx_177;
  if (i_16 < s_47.len_0){
    X60Qx_177 = (0 <= i_16);}
  else {
    X60Qx_177 = NIM_FALSE;}
  if ((!X60Qx_177)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* result_41;
  result_41 = (&s_47.data_0[i_16]);
  return result_41;}
void rawPut_0_Iujg1bp1_nifa1znj21(Table_0_Iyfwn301_nifa1znj21* t_20, string_0_sysvq0asl k_6, NifIndexEntry_0_nifa1znj21 v_5, NU32 h_4){
  NI32 X60Qx_178 = len_3_Ikddlyh1_nifa1znj21((*t_20).data_0);
  if (X60Qx_178 == ((NI32)4)){
    fillHashPart_0_Izlqcme1_nifa1znj21(t_20);}
  else {
    NI32 X60Qx_179 = len_3_Iiefpcc1_filqx2b6r1((*t_20).hashes_0);
    NI32 X60Qx_180 = len_3_Ikddlyh1_nifa1znj21((*t_20).data_0);
    NB8 X60Qx_181 = mustRehash_0_tabcr240b1(X60Qx_179, X60Qx_180);
    if (X60Qx_181){
      resize_0_tabcr240b1((&(*t_20).hashes_0));}}
  string_0_sysvq0asl X60Qtmp_9 = k_6;
  nimStrWasMoved((&k_6));
  add_0_Isv2voo1_nifa1znj21((&(*t_20).data_0), (X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21){
    .fld_0 = X60Qtmp_9, .fld_1 = v_5}
  );
  NI32 X60Qx_182 = high_3_Iyuup9h1_filqx2b6r1((*t_20).hashes_0);
  NU32 hi_0 = ((NU32)(h_4 & ((NU32)X60Qx_182)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_183 = getQ_8_Imt2zi01_filqx2b6r1((*t_20).hashes_0, hi_0);
      NB8 X60Qx_184 = isFilled_0_tabcr240b1((*X60Qx_183));
      if (X60Qx_184){
        NI32 X60Qx_185 = high_3_Iyuup9h1_filqx2b6r1((*t_20).hashes_0);
        NU32 X60Qx_186 = nextTry_0_has9tn57v(hi_0, X60Qx_185);
        hi_0 = X60Qx_186;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_187 = len_3_Ikddlyh1_nifa1znj21((*t_20).data_0);
  putQ_8_Ipchg2a_filqx2b6r1((&(*t_20).hashes_0), hi_0, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_4, .position_0 = X60Qx_187}
  );
  nimStrDestroy(k_6);}
static inline NI32 memSizeInBytes_0_Imuag1k_nifa1znj21(NI32 size_22){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_42;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_22, sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_42 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_42 = ((NI32)2147483647);}
  return result_42;}
static inline NI32 len_3_Ikddlyh1_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_58){
  NI32 result_49;
  result_49 = s_58.len_0;
  return result_49;}
void fillHashPart_0_Izlqcme1_nifa1znj21(Table_0_Iyfwn301_nifa1znj21* t_22){
  seq_0_Ikxuplm1_filqx2b6r1* X60Qlhs_10 = (&(*t_22).hashes_0);
  eQdestroy_1_I5skmro_filqx2b6r1((*X60Qlhs_10));
  seq_0_Ikxuplm1_filqx2b6r1 X60Qx_195 = newSeq_0_Iv3lu2h1_filqx2b6r1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_10) = X60Qx_195;
  {
    NI32 X60Qlf_10 = 0;
    NI32 X60Qlf_11 = len_3_Ikddlyh1_nifa1znj21((*t_22).data_0);
    NI32 X60Qlf_12 = X60Qlf_10;
    {
      while (X60Qlf_12 < X60Qlf_11){
        {
          X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* X60Qx_196 = getQ_7_I1m5sw7_nifa1znj21((*t_22).data_0, X60Qlf_12);
          NU32 X60Qii_2 = hash_1_has9tn57v((*X60Qx_196).fld_0);
          NI32 X60Qx_197 = high_3_Iyuup9h1_filqx2b6r1((*t_22).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_197)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_198 = getQ_8_Imt2zi01_filqx2b6r1((*t_22).hashes_0, X60Qii_3);
            NB8 X60Qx_199 = isFilled_0_tabcr240b1((*X60Qx_198));
            if (X60Qx_199){
              NI32 X60Qx_200 = high_3_Iyuup9h1_filqx2b6r1((*t_22).hashes_0);
              NU32 X60Qx_201 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_200);
              X60Qii_3 = X60Qx_201;}
            else {
              break;}}
          putQ_8_Ipchg2a_filqx2b6r1((&(*t_22).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_12 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_12));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_Isv2voo1_nifa1znj21(seq_0_Irkj95k_nifa1znj21* s_62, X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 elem_12){
  NI32 L_4 = (*s_62).len_0;
  NI32 X60Qx_202 = capInBytes_0_Izw3nef1_nifa1znj21((*s_62));
  if (X60Qx_202 < ((NI32)(((NI32)(L_4 * sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21))) + sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21)))){
    NB8 X60Qx_203 = resize_0_Iwd40sa1_nifa1znj21(s_62, 1);
    if ((!X60Qx_203)){
      eQdestroyQ_AtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_0_nifa1znj21(elem_12);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_62).len_0));
  (*s_62).data_0[L_4] = elem_12;}
static inline NI32 capInBytes_0_Izw3nef1_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_66){
  NI32 result_58;
  NI32 X60Qx_8;
  if ((!(s_66.data_0 == NIM_NIL))){
    NI32 X60Qx_209 = allocatedSize_0_sysvq0asl(((void*)((void*)s_66.data_0)));
    X60Qx_8 = X60Qx_209;}
  else {
    X60Qx_8 = 0;}
  result_58 = X60Qx_8;
  return result_58;}
NB8 resize_0_Iwd40sa1_nifa1znj21(seq_0_Irkj95k_nifa1znj21* dest_12, NI32 addedElements_11){
  NB8 result_59;
  NI32 X60Qx_210 = capInBytes_0_Izw3nef1_nifa1znj21((*dest_12));
  NI32 oldCap_5 = ((NI32)(X60Qx_210 / sizeof(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21)));
  NI32 newCap_5 = recalcCap_0_sysvq0asl(oldCap_5, addedElements_11);
  NI32 memSize_13 = memSizeInBytes_0_Imuag1k_nifa1znj21(newCap_5);
  void* X60Qx_211 = realloc_1_sysvq0asl(((void*)((void*)(*dest_12).data_0)), memSize_13);
  (*dest_12).data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21*)X60Qx_211);
  if ((*dest_12).data_0 == NIM_NIL){
    (*dest_12).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_13);
    result_59 = NIM_FALSE;}
  else {
    result_59 = NIM_TRUE;}
  return result_59;}
void eQdestroy_1_Iufzhtc1_nifa1znj21(seq_0_Ilvi9zw_nifa1znj21 s_92){
  if ((!(s_92.data_0 == NIM_NIL))){
    NI32 i_31 = 0;
    {
      while (i_31 < s_92.len_0){
        eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_nifa1znj21(s_92.data_0[i_31]);
        inc_1_I6wjjge_aow2h993l1((&i_31));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_92.data_0)));}}
static inline void eQwasMoved_1_Iqkhh121_nifa1znj21(seq_0_Ilvi9zw_nifa1znj21* s_93){
  (*s_93).len_0 = 0;
  (*s_93).data_0 = NIM_NIL;}
void eQdestroy_1_Ii0wn2p1_nifa1znj21(seq_0_Imzz798_nifa1znj21 s_96){
  if ((!(s_96.data_0 == NIM_NIL))){
    NI32 i_39 = 0;
    {
      while (i_39 < s_96.len_0){
        eQdestroyQ_AtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_0_nifa1znj21(s_96.data_0[i_39]);
        inc_1_I6wjjge_aow2h993l1((&i_39));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_96.data_0)));}}
static inline void eQwasMoved_1_I2eudh01_nifa1znj21(seq_0_Imzz798_nifa1znj21* s_97){
  (*s_97).len_0 = 0;
  (*s_97).data_0 = NIM_NIL;}
void eQdestroy_1_Ixsq1x81_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_98){
  if ((!(s_98.data_0 == NIM_NIL))){
    NI32 i_43 = 0;
    {
      while (i_43 < s_98.len_0){
        eQdestroyQ_AtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_0_nifa1znj21(s_98.data_0[i_43]);
        inc_1_I6wjjge_aow2h993l1((&i_43));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_98.data_0)));}}
static inline void eQwasMoved_1_Iw26nrm1_nifa1znj21(seq_0_Irkj95k_nifa1znj21* s_99){
  (*s_99).len_0 = 0;
  (*s_99).data_0 = NIM_NIL;}
void eQdestroyQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21(NifIndex_0_nifa1znj21 dest_0){
  eQdestroy_1_Ii0wn2p1_nifa1znj21(dest_0.exports_0);
  eQdestroy_1_Iufzhtc1_nifa1znj21(dest_0.converters_0);}
void eQwasmovedQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21(NifIndex_0_nifa1znj21* dest_0){
  eQwasMoved_1_Iqkhh121_nifa1znj21((&(*dest_0).converters_0));
  eQwasMoved_1_I2eudh01_nifa1znj21((&(*dest_0).exports_0));}
void eQdestroyQ_SX54able0X49yfwn301_0_nifa1znj21(Table_0_Iyfwn301_nifa1znj21 dest_0){
  eQdestroy_1_I5skmro_filqx2b6r1(dest_0.hashes_0);
  eQdestroy_1_Ixsq1x81_nifa1znj21(dest_0.data_0);}
void eQwasmovedQ_SX54able0X49yfwn301_0_nifa1znj21(Table_0_Iyfwn301_nifa1znj21* dest_0){
  eQwasMoved_1_Iw26nrm1_nifa1znj21((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_filqx2b6r1((&(*dest_0).hashes_0));}
void eQdestroyQ_AtupleSstring0sysvq0aslSR6_0_nifa1znj21(X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21 dest_0){
  nimStrDestroy(dest_0.fld_0);
  nimStrDestroy(dest_0.fld_1);}
void eQdestroyQ_AtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_0_nifa1znj21(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 dest_0){
  nimStrDestroy(dest_0.fld_0);
  eQdestroy_1_In04crl1_ast8ri79k(dest_0.fld_2);}
void eQdestroyQ_AtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_0_nifa1znj21(X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 dest_0){
  nimStrDestroy(dest_0.fld_0);}
void X60Qini_0_nifa1znj21(void){
  if (X60QiniGuard_0_nifa1znj21){
    return;}
  X60QiniGuard_0_nifa1znj21 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tabcr240b1();
  X60Qini_0_assy765wm();
  X60Qini_0_has9tn57v();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_str7j0ifg();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_linxafkvx1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nif7eu7bj1();
  X60Qini_0_symkyk35i1();
  X60Qini_0_tagygirdh1();
  X60Qini_0_nif12fhfr1();
  X60Qini_0_shaw6o8p31();}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline NB8 eqQ_5_nifh7u8pu1(NU32 a_5, NU32 b_5){
  NB8 result_10;
  result_10 = (a_5 == b_5);
  return result_10;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
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
  string_0_sysvq0asl* X60Qx_51 = getQ_7_Ir6d0tw_ast8ri79k(t_13.vals_0, idx_3);
  result_8 = X60Qx_51;
  return result_8;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline NU32 litId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_9){
  NU32 result_36;
  NU16 X60Qdesugar_0 = 72u;
  NU64 X60Qdesugar_1 = ((NU)((NifKind_0_nif81dubp1)((NU32)(n_9.x_0 & ((NU32)15u)))));
  if ((!(((NU16)(X60Qdesugar_0 & ((NU16)(((NU16)1) << ((NU)(X60Qdesugar_1 & 15u)))))) != 0u))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_36 = ((NU32)((NU32)(n_9.x_0 >> ((NU32)4u))));
  return result_36;}
static inline string_0_sysvq0asl* getQ_0_Iplpzal1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k t_6, NU32 litId_5){
  string_0_sysvq0asl* result_3;
  NI32 idx_0 = ((NI32)(((NI32)litId_5) - ((NI32)1)));
  if ((!(idx_0 < t_6.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  string_0_sysvq0asl* X60Qx_31 = getQ_7_Ir6d0tw_ast8ri79k(t_6.vals_0, idx_0);
  result_3 = X60Qx_31;
  return result_3;}
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16){
  NU32 result_43;
  if (((NifKind_0_nif81dubp1)((NU32)(n_16.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_88 = tagId_0_nifh7u8pu1(n_16);
    result_43 = X60Qx_88;}
  else {
    result_43 = ErrT_0_nifh7u8pu1;}
  return result_43;}
static inline seq_0_Izov3yo_ast8ri79k newSeqUninit_0_In7hr9h_ast8ri79k(NI32 size_21){
  seq_0_Izov3yo_ast8ri79k result_34;
  if (size_21 == 0){
    result_34 = (seq_0_Izov3yo_ast8ri79k){
      .len_0 = size_21, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_12 = memSizeInBytes_0_Iu5tdzt_ast8ri79k(size_21);
    void* X60Qx_115 = alloc_1_sysvq0asl(memSize_12);
    result_34 = (seq_0_Izov3yo_ast8ri79k){
      .len_0 = size_21, .data_0 = ((NU32*)X60Qx_115)}
    ;
    if ((!(result_34.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_116 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_34.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_12);}}
  return result_34;}
static inline void add_0_Ixkocf1_ide5ljwgh1(seq_0_Izov3yo_ast8ri79k* s_14, NU32 elem_6){
  NI32 L_0 = (*s_14).len_0;
  NI32 X60Qx_51 = capInBytes_0_I2v1dsn1_ast8ri79k((*s_14));
  if (X60Qx_51 < ((NI32)(((NI32)(L_0 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_52 = resize_0_Itvf2zj1_ast8ri79k(s_14, 1);
    if ((!X60Qx_52)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_14).len_0));
  (*s_14).data_0[L_0] = elem_6;}
static inline void eQwasMoved_1_I94uyip1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_49){
  (*s_49).len_0 = 0;
  (*s_49).data_0 = NIM_NIL;}
static inline NI32 offset_0_nif81dubp1(Reader_0_nif81dubp1* r_13){
  NI32 result_26;
  result_26 = ((NI32)(((NI32)(*r_13).p_0) - ((NI32)((NC8*)(*r_13).f_0.data_0))));
  return result_26;}
static inline void jumpTo_0_nif81dubp1(Reader_0_nif81dubp1* r_14, NI32 offset_0){
  (*r_14).p_0 = ((NC8*)((NI32)(((NI32)((NC8*)(*r_14).f_0.data_0)) + offset_0)));
  NB8 X60Qx_64;
  if ((*r_14).f_0.data_0 <= ((void*)(*r_14).p_0)){
    X60Qx_64 = (((void*)((void*)(*r_14).p_0)) < (*r_14).eof_0);}
  else {
    X60Qx_64 = NIM_FALSE;}
  if ((!X60Qx_64)){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}}
static inline string_0_sysvq0asl* getQ_0_I93d71y_comaa5xpt1(BiTable_0_Icvz6lt_buiyylk1h1 t_21, NU32 litId_6){
  string_0_sysvq0asl* result_63;
  NI32 idx_10 = ((NI32)(((NI32)litId_6) - ((NI32)1)));
  if ((!(idx_10 < t_21.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  string_0_sysvq0asl* X60Qx_1799 = getQ_7_Ir6d0tw_ast8ri79k(t_21.vals_0, idx_10);
  result_63 = X60Qx_1799;
  return result_63;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline void eQwasMoved_1_I8aeezd1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_35){
  (*s_35).len_0 = 0;
  (*s_35).data_0 = NIM_NIL;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5){
  NB8 X60Qx_52;
  if (i_5 < s_8.len_0){
    X60Qx_52 = (0 <= i_5);}
  else {
    X60Qx_52 = NIM_FALSE;}
  if ((!X60Qx_52)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  string_0_sysvq0asl* result_9;
  result_9 = (&s_8.data_0[i_5]);
  return result_9;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NI32 memSizeInBytes_0_Iu5tdzt_ast8ri79k(NI32 size_5){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_24;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_5, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_24 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_24 = ((NI32)2147483647);}
  return result_24;}
static inline NI32 capInBytes_0_I2v1dsn1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_29){
  NI32 result_21;
  NI32 X60Qx_1;
  if ((!(s_29.data_0 == NIM_NIL))){
    NI32 X60Qx_76 = allocatedSize_0_sysvq0asl(((void*)((void*)s_29.data_0)));
    X60Qx_1 = X60Qx_76;}
  else {
    X60Qx_1 = 0;}
  result_21 = X60Qx_1;
  return result_21;}
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6){
  NB8 X60Qx_53;
  if (i_6 < s_9.len_0){
    X60Qx_53 = (0 <= i_6);}
  else {
    X60Qx_53 = NIM_FALSE;}
  if ((!X60Qx_53)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NI64* result_10;
  result_10 = (&s_9.data_0[i_6]);
  return result_10;}
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
