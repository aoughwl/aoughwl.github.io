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
#include <string.h>
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax;
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
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
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
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
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
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
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
typedef struct seq_0_Iajrb23_nifb6mq6y1{
  NI32 len_0;
  PackedToken_0_nifh7u8pu1* data_0;}
seq_0_Iajrb23_nifb6mq6y1;
typedef struct openArray_0_Ixtg67b1_nifh7u8pu1{
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* a_0;
  NI32 len_0;}
openArray_0_Ixtg67b1_nifh7u8pu1;
typedef struct openArray_0_I0m47e11_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* a_0;
  NI32 len_0;}
openArray_0_I0m47e11_nifb6mq6y1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax{
  string_0_sysvq0asl fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax;
typedef struct X60Qt_0_IAarrayAtupleSstring0sysvq0aslAiS32ZZS342_nifh7u8pu1{
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax a[342];}
X60Qt_0_IAarrayAtupleSstring0sysvq0aslAiS32ZZS342_nifh7u8pu1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
typedef NU8 Mode_0_nifjp9lau1;

#define UsesMem_0_nifjp9lau1 ((NU8)0)
#define UsesFile_0_nifjp9lau1 ((NU8)1)
typedef NU8 FileWriteMode_0_vfsc9jn7;

#define AlwaysWrite_0_vfsc9jn7 ((NU8)0)
#define OnlyIfChanged_0_vfsc9jn7 ((NU8)1)
typedef struct Builder_0_nifjp9lau1{
  string_0_sysvq0asl buffer_0;
  Mode_0_nifjp9lau1 mode_0;
  FileWriteMode_0_vfsc9jn7 writeMode_0;
  NB8 compact_0;
  string_0_sysvq0asl filename_0;
  NI32 nesting_0;
  NI32 offs_0;}
Builder_0_nifjp9lau1;
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
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline NI32 len_6_I5j2qim1_nifh7u8pu1(openArray_0_Ixtg67b1_nifh7u8pu1 a_9);
static inline X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* getQ_10_Ieolp4z_nifh7u8pu1(openArray_0_Ixtg67b1_nifh7u8pu1 x_11, NI32 idx_2);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ika21pk_nifh7u8pu1(NifKind_0_nif81dubp1 kind_9, NU32 id_13, NU32 info_28);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iip05tk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_10, NU32 id_14, NU32 info_29);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ie5j2hb_nifh7u8pu1(NifKind_0_nif81dubp1 kind_11, NU32 id_15, NU32 info_30);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iz0lv7d1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_12, NU32 id_16, NU32 info_31);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Is7quwk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_13, NU32 id_17, NU32 info_32);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ikm2gt2_nifh7u8pu1(NifKind_0_nif81dubp1 kind_14, NU32 id_18, NU32 info_33);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ifgbqjw1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_15, NU32 id_19, NU32 info_34);
static inline void add_0_I6yw3841_nifh7u8pu1(seq_0_Io4pvgy1_nifb6mq6y1* s_17, NU32 elem_3);
static inline NU32* getQ_7_I4w3aqj1_nifh7u8pu1(seq_0_Io4pvgy1_nifb6mq6y1 s_23, NI32 i_8);
NU32 getOrIncl_0_Iaj0qm3_nifh7u8pu1(BiTable_0_Ieutpr21_intzsnzax* t_26, string_0_sysvq0asl v_10);
static inline NU32 pop_0_I608lbn1_nifh7u8pu1(seq_0_Io4pvgy1_nifb6mq6y1* s_29);
NU32 getOrInclFromView_0_Iledlgq1_nifh7u8pu1(BiTable_0_Icvz6lt_buiyylk1h1* t_28, StringView_0_strdllfw2 v_11);
NB8 resize_0_I9xvz9p1_nifh7u8pu1(seq_0_Io4pvgy1_nifb6mq6y1* dest_6, NI32 addedElements_2);
static inline NI32 high_3_Izd57vi1_nifh7u8pu1(seq_0_If70loa_intzsnzax s_68);
static inline NU32* getQ_8_I1x0pam_nifh7u8pu1(seq_0_If70loa_intzsnzax s_69, NU32 i_30);
void enlarge_0_Iffz5zw1_nifh7u8pu1(BiTable_0_Ieutpr21_intzsnzax* t_47);
void setLen_0_Izwgy3z_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_73, NI32 newLen_15);
static inline void putQ_8_Ird3zar1_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_76, NU32 i_34, NU32 elem_14);
static inline NI32 len_3_I2lzgei1_nifh7u8pu1(seq_0_If70loa_intzsnzax s_127);
static inline void newSeq_1_Ijeltsd1_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_128, NI32 newLen_37);
static inline void swap_0_Iu9nbuo1_nifh7u8pu1(seq_0_If70loa_intzsnzax* x_32, seq_0_If70loa_intzsnzax* y_8);
static inline NU32* getQ_7_Ic0x56f1_nifh7u8pu1(seq_0_If70loa_intzsnzax s_129, NI32 i_59);
static inline NU32 move_0_I4g2vpk_nifh7u8pu1(NU32* x_33);
void shrink_0_Icn19hv_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_130, NI32 newLen_38);
void growUnsafe_0_Iugjmld1_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_131, NI32 newLen_39);
seq_0_If70loa_intzsnzax newSeq_0_Ix86g6u_nifh7u8pu1(NI32 size_56);
NB8 resize_0_Io7u6td1_nifh7u8pu1(seq_0_If70loa_intzsnzax* dest_20, NI32 addedElements_16);
void eQdestroyQ_SX4citerals0nifh7u8pu1_0_nifh7u8pu1(Literals_0_nifh7u8pu1* dest_0);
void eQwasmovedQ_SX4citerals0nifh7u8pu1_0_nifh7u8pu1(Literals_0_nifh7u8pu1* dest_0);
void eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1(Stream_0_nifh7u8pu1* dest_0);
void eQwasmovedQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1(Stream_0_nifh7u8pu1* dest_0);
void eQdestroyQ_SX42iX54able0X49cvz6lt_0_nifh7u8pu1(BiTable_0_Icvz6lt_buiyylk1h1 dest_0);
void eQwasmovedQ_SX42iX54able0X49cvz6lt_0_nifh7u8pu1(BiTable_0_Icvz6lt_buiyylk1h1* dest_0);
void eQdestroyQ_SX42iX54able0X49eutpr21_0_nifh7u8pu1(BiTable_0_Ieutpr21_intzsnzax dest_0);
void eQwasmovedQ_SX42iX54able0X49eutpr21_0_nifh7u8pu1(BiTable_0_Ieutpr21_intzsnzax* dest_0);
void eQdestroyQ_SX42iX54able0X490ksat5_0_nifh7u8pu1(BiTable_0_I0ksat5_ast8ri79k dest_0);
void eQwasmovedQ_SX42iX54able0X490ksat5_0_nifh7u8pu1(BiTable_0_I0ksat5_ast8ri79k* dest_0);
void eQdestroyQ_SX42iX54able0X49pgo74p_0_nifh7u8pu1(BiTable_0_Ipgo74p_ast8ri79k dest_0);
void eQwasmovedQ_SX42iX54able0X49pgo74p_0_nifh7u8pu1(BiTable_0_Ipgo74p_ast8ri79k* dest_0);
void eQdestroyQ_SX42iX54able0X49tvq7bk_0_nifh7u8pu1(BiTable_0_Itvq7bk_ast8ri79k dest_0);
void eQwasmovedQ_SX42iX54able0X49tvq7bk_0_nifh7u8pu1(BiTable_0_Itvq7bk_ast8ri79k* dest_0);
void eQdestroyQ_SX42iX54able0X49txao711_0_nifh7u8pu1(BiTable_0_Itxao711_ast8ri79k dest_0);
void eQwasmovedQ_SX42iX54able0X49txao711_0_nifh7u8pu1(BiTable_0_Itxao711_ast8ri79k* dest_0);
void eQdestroyQ_SX42iX54ableX46loat0X49u8fssa_0_nifh7u8pu1(BiTable_0_Iojfwmy1_ast8ri79k dest_0);
void eQwasmovedQ_SX42iX54ableX46loat0X49u8fssa_0_nifh7u8pu1(BiTable_0_Iojfwmy1_ast8ri79k* dest_0);
void eQdestroyQ_SX42iX54able0X49ojfwmy1_0_nifh7u8pu1(BiTable_0_Iojfwmy1_ast8ri79k dest_0);
void eQwasmovedQ_SX42iX54able0X49ojfwmy1_0_nifh7u8pu1(BiTable_0_Iojfwmy1_ast8ri79k* dest_0);
void eQdestroyQ_SX42uilder0nifjp9lau1_0_nifh7u8pu1(Builder_0_nifjp9lau1* dest_0);
void eQwasmovedQ_SX42uilder0nifjp9lau1_0_nifh7u8pu1(Builder_0_nifjp9lau1* dest_0);
static inline NU32 hash_2_has9tn57v(NU32 u_0);
static inline seq_0_Ivkh6l1_linxafkvx1 newSeqUninit_0_Izs0ei1_linxafkvx1(NI32 size_3);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline seq_0_Iaza5ca1_buiyylk1h1 newSeqUninit_0_Ikst8ta1_buiyylk1h1(NI32 size_22);
static inline seq_0_If70loa_intzsnzax newSeqUninit_0_Il1doiw_intzsnzax(NI32 size_158);
static inline seq_0_In6doa_arecyyj7v newSeqUninit_0_Ieodq4s1_arecyyj7v(NI32 size_28);
static inline seq_0_Izov3yo_ast8ri79k newSeqUninit_0_In7hr9h_ast8ri79k(NI32 size_21);
static inline seq_0_Iotb7mc_ast8ri79k newSeqUninit_0_I7whkjh1_ast8ri79k(NI32 size_22);
static inline seq_0_Iwy7s2o_ast8ri79k newSeqUninit_0_Isaraw1_ast8ri79k(NI32 size_24);
static inline seq_0_Ijmiee61_ast8ri79k newSeqUninit_0_Igtmzv6_ast8ri79k(NI32 size_26);
static inline seq_0_Ipw48je1_ast8ri79k newSeqUninit_0_I8tb1fi1_ast8ri79k(NI32 size_28);
static inline seq_0_Isoawlw1_ast8ri79k newSeqUninit_0_Ivz95ii_ast8ri79k(NI32 size_30);
extern NU32 getOrIncl_0_Is83dq9_buiyylk1h1(BiTable_0_Icvz6lt_buiyylk1h1* t_3, string_0_sysvq0asl v_3);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern Reader_0_nif81dubp1 open_0_nif81dubp1(string_0_sysvq0asl filename_1);
static inline seq_0_Io4pvgy1_nifb6mq6y1 newSeqUninit_0_Ijkckzz_nifb6mq6y1(NI32 size_48);
extern NU32 const NoLineInfo_0_linxafkvx1;
extern string_0_sysvq0asl decodeComment_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_3);
extern NU32 getOrIncl_0_Ix6biej1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k* t_11, string_0_sysvq0asl v_1);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern LineInfoUnpacked_0_linxafkvx1 unpack_0_linxafkvx1(LineInfoManager_0_linxafkvx1 m_2, NU32 info_0);
extern NU32 packWithComment_0_linxafkvx1(LineInfoManager_0_linxafkvx1* m_1, NU32 file_1, NI32 line_1, NI32 col_1, NU32 comment_0);
extern string_0_sysvq0asl decodeFilename_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_4);
extern NU32 stripComment_0_linxafkvx1(LineInfoManager_0_linxafkvx1* m_3, NU32 info_1);
extern string_0_sysvq0asl decodeStr_0_nif81dubp1(Reader_0_nif81dubp1* r_3, ExpandedToken_0_nif81dubp1* t_2);
extern NU32 getOrIncl_0_Inyo00c_buiyylk1h1(BiTable_0_I0ksat5_ast8ri79k* t_5, string_0_sysvq0asl v_4);
extern NC8 decodeChar_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_1);
extern NI64 decodeInt_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_7);
extern NU32 getOrIncl_0_I4rntkc_buiyylk1h1(BiTable_0_Itvq7bk_ast8ri79k* t_7, NI64 v_5);
extern NU64 decodeUInt_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_6);
extern NU32 getOrIncl_0_Icm7gb1_explnj22x1(BiTable_0_Itxao711_ast8ri79k* t_24, NU64 v_7);
extern NF64 decodeFloat_0_nif81dubp1(ExpandedToken_0_nif81dubp1* t_5);
static inline NU32 getOrIncl_1_Ijmj1s_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_26, NF64 v_8);
extern void next_0_nif81dubp1(Reader_0_nif81dubp1* r_7, ExpandedToken_0_nif81dubp1* result_4);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
static inline NB8 isValid_1_linxafkvx1(NU32 x_1);
static inline NB8 isValid_0_linxafkvx1(NU32 x_0);
static inline NB8 eqQ_0_linxafkvx1(NU32 a_0, NU32 b_0);
static inline string_0_sysvq0asl* getQ_0_Io78pjy1_intzsnzax(BiTable_0_Ieutpr21_intzsnzax t_41, NU32 litId_8);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern void attachLineInfo_1_nifjp9lau1(Builder_0_nifjp9lau1* b_27, NI32 col_2, NI32 line_2, string_0_sysvq0asl file_2);
static inline string_0_sysvq0asl* getQ_0_Iplpzal1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k t_6, NU32 litId_5);
extern void attachComment_0_nifjp9lau1(Builder_0_nifjp9lau1* b_29, string_0_sysvq0asl s_12);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline NI32 len_6_I4emj7h_nifb6mq6y1(openArray_0_I0m47e11_nifb6mq6y1 a_4);
extern Builder_0_nifjp9lau1 open_1_nifjp9lau1(NI32 sizeHint_0, NB8 compact_1);
static inline PackedToken_0_nifh7u8pu1* getQ_10_Iids335_nifb6mq6y1(openArray_0_I0m47e11_nifb6mq6y1 x_8, NI32 idx_1);
extern void addEmpty_0_nifjp9lau1(Builder_0_nifjp9lau1* b_19, NI32 count_0);
extern void addIdent_0_nifjp9lau1(Builder_0_nifjp9lau1* b_12, string_0_sysvq0asl s_5);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern void addSymbol_0_nifjp9lau1(Builder_0_nifjp9lau1* b_14, string_0_sysvq0asl s_7);
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6);
extern void addIntLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_21, NI64 i_0);
static inline NU64* getQ_0_Iebom0i1_ast8ri79k(BiTable_0_Itxao711_ast8ri79k t_8, NU32 litId_7);
extern void addUIntLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_22, NU64 u_0);
static inline NF64 getQ_1_I4qx0py_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_9, NU32 litId_8);
extern void addFloatLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_24, NF64 f_0, NI32 col_1, NI32 line_1, string_0_sysvq0asl file_1);
extern void addSymbolDef_0_nifjp9lau1(Builder_0_nifjp9lau1* b_15, string_0_sysvq0asl s_8);
extern void addCharLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_20, NC8 c_2);
extern void addStrLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_18, string_0_sysvq0asl s_11);
extern LongString_0_sysvq0asl const strlit_0_I11191788154693975321_nif81dubp1;
extern void endTree_0_nifjp9lau1(Builder_0_nifjp9lau1* b_32);
static inline string_0_sysvq0asl* getQ_0_I93d71y_der823rwr1(BiTable_0_Icvz6lt_buiyylk1h1 t_5, NU32 litId_1);
extern void addTree_0_nifjp9lau1(Builder_0_nifjp9lau1* b_31, string_0_sysvq0asl kind_0);
extern string_0_sysvq0asl extract_0_nifjp9lau1(Builder_0_nifjp9lau1 b_1);
extern void eQdestroy_1_I35tn0j_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1 s_168);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_aow7lb5cq1;
static inline NI32 capInBytes_0_Id76iiw1_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1 s_171);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NU32 hash_1_has9tn57v(string_0_sysvq0asl s_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NU32 nextTry_0_bitekkhcx1(NU32 h_0, NU32 maxHash_0);
static inline NB8 mustRehash_0_bitekkhcx1(NI32 length_0, NI32 counter_0);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline NU32 hash_0_strdllfw2(StringView_0_strdllfw2 a_2);
static inline NI32 high_3_Ib20i801_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_16);
static inline NU32* getQ_8_I1lkkvo_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_17, NU32 i_8);
extern NB8 eqQ_1_strdllfw2(StringView_0_strdllfw2 a_1, string_0_sysvq0asl b_1);
extern void enlarge_0_I4mrsk51_buiyylk1h1(BiTable_0_Icvz6lt_buiyylk1h1* t_9);
extern void setLen_0_Isypn1s_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_22, NI32 newLen_4);
static inline void putQ_8_Iltefhx_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_25, NU32 i_13, NU32 elem_5);
extern string_0_sysvq0asl dollarQ_0_strdllfw2(StringView_0_strdllfw2 s_3);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
static inline NI32 memSizeInBytes_0_Isupifd_nifb6mq6y1(NI32 size_49);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
static inline void eQwasMoved_1_Idi7njb_intzsnzax(seq_0_If70loa_intzsnzax* s_546);
extern void eQdestroy_1_Iv1ystk1_intzsnzax(seq_0_If70loa_intzsnzax s_545);
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline NI32 capInBytes_0_Iryrob_intzsnzax(seq_0_If70loa_intzsnzax s_572);
static inline NI32 memSizeInBytes_0_Ib1bjtc_intzsnzax(NI32 size_159);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern void eQdestroyQ_SX4cineX49nfoX4danager0linxafkvx1_0_linxafkvx1(LineInfoManager_0_linxafkvx1 dest_0);
extern void eQwasmovedQ_SX4cineX49nfoX4danager0linxafkvx1_0_linxafkvx1(LineInfoManager_0_linxafkvx1* dest_0);
extern void eQdestroyQ_SX52eader0nif81dubp1_0_nif81dubp1(Reader_0_nif81dubp1* dest_0);
extern void eQwasmovedQ_SX52eader0nif81dubp1_0_nif81dubp1(Reader_0_nif81dubp1* dest_0);
static inline void eQwasMoved_1_Igz5mgz_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1* s_169);
extern void eQdestroy_1_I5fjqyi1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_84);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
static inline void eQwasMoved_1_Iew8iz1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_85);
extern void eQdestroy_1_Iscb4i31_arecyyj7v(seq_0_In6doa_arecyyj7v s_81);
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82);
extern void eQdestroy_1_In04crl1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_48);
static inline void eQwasMoved_1_I94uyip1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_49);
extern void eQdestroy_1_Inr6ycs1_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k s_53);
extern void eQdestroy_1_Iez2nr5_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_50);
static inline void eQwasMoved_1_Ia0kll01_ast8ri79k(seq_0_Iotb7mc_ast8ri79k* s_51);
static inline void eQwasMoved_1_I5re2ul_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k* s_54);
extern void eQdestroy_1_I7og8li_ast8ri79k(seq_0_Ipw48je1_ast8ri79k s_59);
extern void eQdestroy_1_Ic8bbvt1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_56);
static inline void eQwasMoved_1_I6m9e8j_ast8ri79k(seq_0_Ijmiee61_ast8ri79k* s_57);
static inline void eQwasMoved_1_I52bdqo1_ast8ri79k(seq_0_Ipw48je1_ast8ri79k* s_60);
extern void eQdestroy_1_Iz0k69p1_ast8ri79k(seq_0_Isoawlw1_ast8ri79k s_62);
static inline void eQwasMoved_1_I5y4iq9_ast8ri79k(seq_0_Isoawlw1_ast8ri79k* s_63);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_has9tn57v(void);
extern void X60Qini_0_bitekkhcx1(void);
extern void X60Qini_0_strdllfw2(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nifjp9lau1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_tagygirdh1(void);
extern X60Qt_0_IAarrayAtupleSstring0sysvq0aslAiS32ZZS342_nifh7u8pu1 const TagData_0_tagygirdh1;
static inline NI32 memSizeInBytes_0_Imnzl86_linxafkvx1(NI32 size_1);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
static inline NI32 memSizeInBytes_0_Igp775b_buiyylk1h1(NI32 size_13);
static inline NI32 memSizeInBytes_0_Ivqzo5x1_arecyyj7v(NI32 size_29);
static inline NI32 memSizeInBytes_0_Iu5tdzt_ast8ri79k(NI32 size_5);
static inline NI32 memSizeInBytes_0_Iqj0wsf_ast8ri79k(NI32 size_23);
static inline NI32 memSizeInBytes_0_I4sctiu_ast8ri79k(NI32 size_25);
static inline NI32 memSizeInBytes_0_Iom723i1_ast8ri79k(NI32 size_27);
static inline NI32 memSizeInBytes_0_Itq6t0c1_ast8ri79k(NI32 size_29);
static inline NI32 memSizeInBytes_0_Iidgqw2_ast8ri79k(NI32 size_31);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
extern NU32 getOrIncl_0_Ivbdpqo_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_35, NU64 v_10);
extern NU32 const NoFile_0_linxafkvx1;
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
static inline NU64* getQ_7_Ifaxado1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_10, NI32 i_7);
static inline NU64* getQ_0_I3qz68f_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_14, NU32 litId_13);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
extern string_0_sysvq0asl borrowCStringUnsafe_0_sysvq0asl(NC8* s_61, NI32 l_0);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I4759879970636729446_nifh7u8pu1 = {
  .fullLen_0 = 102, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/seqimpl.nim(256, 32): 0 < s.len [AssertionDefect]\012"}
;
NU32 const ErrT_0_nifh7u8pu1 = ((NU32)1u);
Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
NB8 X60QiniGuard_0_nifh7u8pu1;
static inline PackedToken_0_nifh7u8pu1 parRiToken_0_nifh7u8pu1(NU32 info_2){
  PackedToken_0_nifh7u8pu1 result_3;
  result_3 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)12) | ((NU32)(((NU32)0u) << ((NU32)4u))))), .info_0 = info_2}
  ;
  return result_3;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
static inline NB8 eqQ_1_nifh7u8pu1(NU32 a_1, NU32 b_1){
  NB8 result_6;
  result_6 = (a_1 == b_1);
  return result_6;}
static inline NB8 eqQ_5_nifh7u8pu1(NU32 a_5, NU32 b_5){
  NB8 result_10;
  result_10 = (a_5 == b_5);
  return result_10;}
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0){
  NU32 result_11;
  NU32 X60Qx_20 = hash_2_has9tn57v(x_0);
  result_11 = X60Qx_20;
  return result_11;}
Literals_0_nifh7u8pu1 createLiterals_0_nifh7u8pu1(openArray_0_Ixtg67b1_nifh7u8pu1 data_0){
  Literals_0_nifh7u8pu1 result_17;
  eQwasmovedQ_SX4citerals0nifh7u8pu1_0_nifh7u8pu1((&result_17));
  eQdestroyQ_SX4citerals0nifh7u8pu1_0_nifh7u8pu1((&result_17));
  seq_0_Ivkh6l1_linxafkvx1 X60Qx_26 = newSeqUninit_0_Izs0ei1_linxafkvx1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_27 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Iaza5ca1_buiyylk1h1 X60Qx_28 = newSeqUninit_0_Ikst8ta1_buiyylk1h1(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_29 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_If70loa_intzsnzax X60Qx_30 = newSeqUninit_0_Il1doiw_intzsnzax(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_31 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_In6doa_arecyyj7v X60Qx_32 = newSeqUninit_0_Ieodq4s1_arecyyj7v(0);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_33 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  seq_0_Izov3yo_ast8ri79k X60Qx_34 = newSeqUninit_0_In7hr9h_ast8ri79k(0);
  seq_0_Iotb7mc_ast8ri79k X60Qx_35 = newSeqUninit_0_I7whkjh1_ast8ri79k(0);
  seq_0_Iwy7s2o_ast8ri79k X60Qx_36 = newSeqUninit_0_Isaraw1_ast8ri79k(0);
  seq_0_Ijmiee61_ast8ri79k X60Qx_37 = newSeqUninit_0_Igtmzv6_ast8ri79k(0);
  seq_0_Ipw48je1_ast8ri79k X60Qx_38 = newSeqUninit_0_I8tb1fi1_ast8ri79k(0);
  seq_0_Ijmiee61_ast8ri79k X60Qx_39 = newSeqUninit_0_Igtmzv6_ast8ri79k(0);
  seq_0_Isoawlw1_ast8ri79k X60Qx_40 = newSeqUninit_0_Ivz95ii_ast8ri79k(0);
  result_17 = (Literals_0_nifh7u8pu1){
    .man_0 = (LineInfoManager_0_linxafkvx1){
      .aside_0 = X60Qx_26}
    , .tags_0 = (BiTable_0_Icvz6lt_buiyylk1h1){
      .vals_0 = X60Qx_27, .keys_0 = X60Qx_28}
    , .files_0 = (BiTable_0_Ieutpr21_intzsnzax){
      .vals_0 = X60Qx_29, .keys_0 = X60Qx_30}
    , .syms_0 = (BiTable_0_I0ksat5_ast8ri79k){
      .vals_0 = X60Qx_31, .keys_0 = X60Qx_32}
    , .strings_0 = (BiTable_0_Ipgo74p_ast8ri79k){
      .vals_0 = X60Qx_33, .keys_0 = X60Qx_34}
    , .integers_0 = (BiTable_0_Itvq7bk_ast8ri79k){
      .vals_0 = X60Qx_35, .keys_0 = X60Qx_36}
    , .uintegers_0 = (BiTable_0_Itxao711_ast8ri79k){
      .vals_0 = X60Qx_37, .keys_0 = X60Qx_38}
    , .floats_0 = (BiTable_0_Iojfwmy1_ast8ri79k){
      .vals_0 = X60Qx_39, .keys_0 = X60Qx_40}}
  ;
  {
    NI32 X60Qlf_0 = 1;
    NI32 X60Qlf_1 = len_6_I5j2qim1_nifh7u8pu1(data_0);
    NI32 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 < X60Qlf_1){
        {
          X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* X60Qx_41 = getQ_10_Ieolp4z_nifh7u8pu1(data_0, X60Qlf_2);
          NU32 X60Qii_2 = getOrIncl_0_Is83dq9_buiyylk1h1((&result_17.tags_0), (*X60Qx_41).fld_0);
          X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* X60Qx_42 = getQ_10_Ieolp4z_nifh7u8pu1(data_0, X60Qlf_2);
          if ((!(((NI32)X60Qii_2) == (*X60Qx_42).fld_1))){
            write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
              .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
            );
            write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            );
            write_7_syn1lfpjv(stdout, (NC8)'\012');
            quit_0_syn1lfpjv(1);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_17;}
static inline PackedToken_0_nifh7u8pu1 identToken_0_nifh7u8pu1(NU32 s_0, NU32 info_5){
  PackedToken_0_nifh7u8pu1 result_18;
  PackedToken_0_nifh7u8pu1 X60Qx_44 = toToken_0_Ika21pk_nifh7u8pu1(3, s_0, info_5);
  result_18 = X60Qx_44;
  return result_18;}
static inline PackedToken_0_nifh7u8pu1 symToken_0_nifh7u8pu1(NU32 s_1, NU32 info_6){
  PackedToken_0_nifh7u8pu1 result_19;
  if ((!(((NU32)0u) < ((NU32)s_1)))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  PackedToken_0_nifh7u8pu1 X60Qx_45 = toToken_0_Iip05tk1_nifh7u8pu1(4, s_1, info_6);
  result_19 = X60Qx_45;
  return result_19;}
static inline PackedToken_0_nifh7u8pu1 dotToken_0_nifh7u8pu1(NU32 info_7){
  PackedToken_0_nifh7u8pu1 result_20;
  PackedToken_0_nifh7u8pu1 X60Qx_46 = toToken_0_Ie5j2hb_nifh7u8pu1(2, ((NU32)0u), info_7);
  result_20 = X60Qx_46;
  return result_20;}
static inline PackedToken_0_nifh7u8pu1 symdefToken_0_nifh7u8pu1(NU32 s_2, NU32 info_8){
  PackedToken_0_nifh7u8pu1 result_21;
  PackedToken_0_nifh7u8pu1 X60Qx_47 = toToken_0_Iip05tk1_nifh7u8pu1(5, s_2, info_8);
  result_21 = X60Qx_47;
  return result_21;}
static inline PackedToken_0_nifh7u8pu1 parLeToken_0_nifh7u8pu1(NU32 t_0, NU32 info_9){
  PackedToken_0_nifh7u8pu1 result_22;
  PackedToken_0_nifh7u8pu1 X60Qx_48 = toToken_0_Iz0lv7d1_nifh7u8pu1(11, t_0, info_9);
  result_22 = X60Qx_48;
  return result_22;}
static inline PackedToken_0_nifh7u8pu1 intToken_0_nifh7u8pu1(NU32 id_2, NU32 info_11){
  PackedToken_0_nifh7u8pu1 result_25;
  PackedToken_0_nifh7u8pu1 X60Qx_51 = toToken_0_Is7quwk1_nifh7u8pu1(8, id_2, info_11);
  result_25 = X60Qx_51;
  return result_25;}
static inline PackedToken_0_nifh7u8pu1 uintToken_0_nifh7u8pu1(NU32 id_3, NU32 info_12){
  PackedToken_0_nifh7u8pu1 result_26;
  PackedToken_0_nifh7u8pu1 X60Qx_52 = toToken_0_Ikm2gt2_nifh7u8pu1(9, id_3, info_12);
  result_26 = X60Qx_52;
  return result_26;}
static inline PackedToken_0_nifh7u8pu1 floatToken_0_nifh7u8pu1(NU32 id_4, NU32 info_13){
  PackedToken_0_nifh7u8pu1 result_27;
  PackedToken_0_nifh7u8pu1 X60Qx_53 = toToken_0_Ifgbqjw1_nifh7u8pu1(10, id_4, info_13);
  result_27 = X60Qx_53;
  return result_27;}
static inline PackedToken_0_nifh7u8pu1 strToken_0_nifh7u8pu1(NU32 id_5, NU32 info_15){
  PackedToken_0_nifh7u8pu1 result_29;
  PackedToken_0_nifh7u8pu1 X60Qx_55 = toToken_0_Ika21pk_nifh7u8pu1(6, id_5, info_15);
  result_29 = X60Qx_55;
  return result_29;}
NU32 registerTag_0_nifh7u8pu1(string_0_sysvq0asl tag_0){
  NU32 result_30;
  NU32 X60Qx_56 = getOrIncl_0_Is83dq9_buiyylk1h1((&pool_0_nifh7u8pu1.tags_0), tag_0);
  result_30 = X60Qx_56;
  return result_30;}
Stream_0_nifh7u8pu1 open_0_nifh7u8pu1(string_0_sysvq0asl filename_0){
  Stream_0_nifh7u8pu1 result_31;
  eQwasmovedQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1((&result_31));
  eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1((&result_31));
  Reader_0_nif81dubp1 X60Qx_57 = open_0_nif81dubp1(filename_0);
  seq_0_Io4pvgy1_nifb6mq6y1 X60Qx_58 = newSeqUninit_0_Ijkckzz_nifb6mq6y1(0);
  result_31 = (Stream_0_nifh7u8pu1){
    .r_0 = X60Qx_57, .parents_0 = X60Qx_58}
  ;
  add_0_I6yw3841_nifh7u8pu1((&result_31.parents_0), NoLineInfo_0_linxafkvx1);
  return result_31;}
PackedToken_0_nifh7u8pu1 rawNext_0_nifh7u8pu1(Stream_0_nifh7u8pu1* s_4, ExpandedToken_0_nif81dubp1* t_3){
  PackedToken_0_nifh7u8pu1 result_33;
  NU32 currentInfo_0 = NoLineInfo_0_linxafkvx1;
  NU32 X60Qx_0;
  if ((*t_3).comment_0.len_0 == 0){
    X60Qx_0 = ((NU32)0u);}
  else {
    string_0_sysvq0asl X60Qtmp_5 = decodeComment_0_nif81dubp1((&(*t_3)));
    NU32 X60Qx_59 = getOrIncl_0_Ix6biej1_ast8ri79k((&pool_0_nifh7u8pu1.strings_0), X60Qtmp_5);
    X60Qx_0 = ((NU32)X60Qx_59);
    nimStrDestroy(X60Qtmp_5);}
  NU32 commentId_0 = X60Qx_0;
  if ((*t_3).filename_0.len_0 == 0){
    NB8 X60Qx_60;
    NB8 X60Qx_61;
    if ((!((*t_3).pos_0.line_0 == 0))){
      X60Qx_61 = NIM_TRUE;}
    else {
      X60Qx_61 = (!((*t_3).pos_0.col_0 == 0));}
    if (X60Qx_61){
      X60Qx_60 = NIM_TRUE;}
    else {
      X60Qx_60 = (!(commentId_0 == ((NU32)0u)));}
    if (X60Qx_60){
      NU32* X60Qx_62 = getQ_7_I4w3aqj1_nifh7u8pu1((*s_4).parents_0, ((NI32)((*s_4).parents_0.len_0 - ((NI32)((NI32)1)))));
      LineInfoUnpacked_0_linxafkvx1 rawInfo_0 = unpack_0_linxafkvx1(pool_0_nifh7u8pu1.man_0, (*X60Qx_62));
      NU32 X60Qx_63 = packWithComment_0_linxafkvx1((&pool_0_nifh7u8pu1.man_0), rawInfo_0.file_0, ((NI32)(rawInfo_0.line_0 + (*t_3).pos_0.line_0)), ((NI32)(rawInfo_0.col_0 + (*t_3).pos_0.col_0)), commentId_0);
      currentInfo_0 = X60Qx_63;}
    else {
      NU32* X60Qx_64 = getQ_7_I4w3aqj1_nifh7u8pu1((*s_4).parents_0, ((NI32)((*s_4).parents_0.len_0 - ((NI32)((NI32)1)))));
      currentInfo_0 = (*X60Qx_64);}}
  else {
    string_0_sysvq0asl X60Qtmp_6 = decodeFilename_0_nif81dubp1((&(*t_3)));
    NU32 fileId_0 = getOrIncl_0_Iaj0qm3_nifh7u8pu1((&pool_0_nifh7u8pu1.files_0), X60Qtmp_6);
    NU32 X60Qx_65 = packWithComment_0_linxafkvx1((&pool_0_nifh7u8pu1.man_0), fileId_0, (*t_3).pos_0.line_0, (*t_3).pos_0.col_0, commentId_0);
    currentInfo_0 = X60Qx_65;
    nimStrDestroy(X60Qtmp_6);}
  switch ((*t_3).tk_0){
    case 12:
    {
      PackedToken_0_nifh7u8pu1 X60Qx_66 = toToken_0_Ie5j2hb_nifh7u8pu1((*t_3).tk_0, ((NU32)0u), currentInfo_0);
      result_33 = X60Qx_66;
      if (1 < (*s_4).parents_0.len_0){
        NU32 X60Qx_67 = pop_0_I608lbn1_nifh7u8pu1((&(*s_4).parents_0));}}
    break;
    case 1:
    case 0:
    case 2:
    {
      PackedToken_0_nifh7u8pu1 X60Qx_68 = toToken_0_Ie5j2hb_nifh7u8pu1((*t_3).tk_0, ((NU32)0u), currentInfo_0);
      result_33 = X60Qx_68;}
    break;
    case 11:
    {
      NU32 ka_0 = getOrInclFromView_0_Iledlgq1_nifh7u8pu1((&pool_0_nifh7u8pu1.tags_0), (*t_3).data_0);
      PackedToken_0_nifh7u8pu1 X60Qx_69 = toToken_0_Iz0lv7d1_nifh7u8pu1(11, ka_0, currentInfo_0);
      result_33 = X60Qx_69;
      NU32 X60Qx_70 = stripComment_0_linxafkvx1((&pool_0_nifh7u8pu1.man_0), currentInfo_0);
      add_0_I6yw3841_nifh7u8pu1((&(*s_4).parents_0), X60Qx_70);}
    break;
    case 3:
    case 6:
    {
      string_0_sysvq0asl X60Qtmp_7 = decodeStr_0_nif81dubp1((&(*s_4).r_0), (&(*t_3)));
      NU32 X60Qx_71 = getOrIncl_0_Ix6biej1_ast8ri79k((&pool_0_nifh7u8pu1.strings_0), X60Qtmp_7);
      PackedToken_0_nifh7u8pu1 X60Qx_72 = toToken_0_Ika21pk_nifh7u8pu1((*t_3).tk_0, X60Qx_71, currentInfo_0);
      result_33 = X60Qx_72;
      nimStrDestroy(X60Qtmp_7);}
    break;
    case 4:
    case 5:
    {
      string_0_sysvq0asl X60Qtmp_8 = decodeStr_0_nif81dubp1((&(*s_4).r_0), (&(*t_3)));
      NU32 X60Qx_73 = getOrIncl_0_Inyo00c_buiyylk1h1((&pool_0_nifh7u8pu1.syms_0), X60Qtmp_8);
      PackedToken_0_nifh7u8pu1 X60Qx_74 = toToken_0_Iip05tk1_nifh7u8pu1((*t_3).tk_0, X60Qx_73, currentInfo_0);
      result_33 = X60Qx_74;
      nimStrDestroy(X60Qtmp_8);}
    break;
    case 7:
    {
      NC8 X60Qx_75 = decodeChar_0_nif81dubp1((&(*t_3)));
      PackedToken_0_nifh7u8pu1 X60Qx_76 = toToken_0_Ie5j2hb_nifh7u8pu1(7, ((NU32)X60Qx_75), currentInfo_0);
      result_33 = X60Qx_76;}
    break;
    case 8:
    {
      NI64 X60Qx_77 = decodeInt_0_nif81dubp1((&(*t_3)));
      NU32 X60Qx_78 = getOrIncl_0_I4rntkc_buiyylk1h1((&pool_0_nifh7u8pu1.integers_0), X60Qx_77);
      PackedToken_0_nifh7u8pu1 X60Qx_79 = toToken_0_Is7quwk1_nifh7u8pu1(8, X60Qx_78, currentInfo_0);
      result_33 = X60Qx_79;}
    break;
    case 9:
    {
      NU64 X60Qx_80 = decodeUInt_0_nif81dubp1((&(*t_3)));
      NU32 X60Qx_81 = getOrIncl_0_Icm7gb1_explnj22x1((&pool_0_nifh7u8pu1.uintegers_0), X60Qx_80);
      PackedToken_0_nifh7u8pu1 X60Qx_82 = toToken_0_Ikm2gt2_nifh7u8pu1(9, X60Qx_81, currentInfo_0);
      result_33 = X60Qx_82;}
    break;
    case 10:
    {
      NF64 X60Qx_83 = decodeFloat_0_nif81dubp1((&(*t_3)));
      NU32 X60Qx_84 = getOrIncl_1_Ijmj1s_explnj22x1((&pool_0_nifh7u8pu1.floats_0), X60Qx_83);
      PackedToken_0_nifh7u8pu1 X60Qx_85 = toToken_0_Ifgbqjw1_nifh7u8pu1(10, X60Qx_84, currentInfo_0);
      result_33 = X60Qx_85;}
    break;}
  return result_33;}
PackedToken_0_nifh7u8pu1 next_0_nifh7u8pu1(Stream_0_nifh7u8pu1* s_5){
  PackedToken_0_nifh7u8pu1 result_34;
  ExpandedToken_0_nif81dubp1 t_13 = (ExpandedToken_0_nif81dubp1){
    .tk_0 = 0, .flags_0 = 0u, .kind_0 = ((NU16)0u), .data_0 = (StringView_0_strdllfw2){
      .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}
    , .pos_0 = (FilePos_0_nif81dubp1){
      .col_0 = ((NI32)0), .line_0 = ((NI32)0)}
    , .filename_0 = (StringView_0_strdllfw2){
      .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}
    , .comment_0 = (StringView_0_strdllfw2){
      .p_0 = ((NC8*)NIM_NIL), .len_0 = ((NI32)0)}}
  ;
  next_0_nif81dubp1((&(*s_5).r_0), (&t_13));
  PackedToken_0_nifh7u8pu1 X60Qx_86 = rawNext_0_nifh7u8pu1(s_5, (&t_13));
  result_34 = X60Qx_86;
  return result_34;}
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
static inline NC8 charLit_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_10){
  NC8 result_37;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_10.x_0 & ((NU32)15u)))) == 7))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_37 = ((NC8)((NU32)(n_10.x_0 >> ((NU32)4u))));
  return result_37;}
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
static inline NU32 uintId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_13){
  NU32 result_40;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_13.x_0 & ((NU32)15u)))) == 9))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_40 = ((NU32)((NU32)(n_13.x_0 >> ((NU32)4u))));
  return result_40;}
static inline NU32 floatId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_14){
  NU32 result_41;
  if ((!(((NifKind_0_nif81dubp1)((NU32)(n_14.x_0 & ((NU32)15u)))) == 10))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_41 = ((NU32)((NU32)(n_14.x_0 >> ((NU32)4u))));
  return result_41;}
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
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16){
  NU32 result_43;
  if (((NifKind_0_nif81dubp1)((NU32)(n_16.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_88 = tagId_0_nifh7u8pu1(n_16);
    result_43 = X60Qx_88;}
  else {
    result_43 = ErrT_0_nifh7u8pu1;}
  return result_43;}
void emitLineInfo_0_nifh7u8pu1(Builder_0_nifjp9lau1* b_6, NU32 info_18, NU32 parentInfo_0){
  LineInfoUnpacked_0_linxafkvx1 rawInfo_1 = unpack_0_linxafkvx1(pool_0_nifh7u8pu1.man_0, info_18);
  NU32 file_0 = rawInfo_1.file_0;
  NI32 line_0 = rawInfo_1.line_0;
  NI32 col_0 = rawInfo_1.col_0;
  NB8 X60Qx_91 = isValid_1_linxafkvx1(file_0);
  if (X60Qx_91){
    string_0_sysvq0asl fileAsStr_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    NB8 X60Qx_92 = isValid_0_linxafkvx1(parentInfo_0);
    if (X60Qx_92){
      LineInfoUnpacked_0_linxafkvx1 pRawInfo_0 = unpack_0_linxafkvx1(pool_0_nifh7u8pu1.man_0, parentInfo_0);
      NB8 X60Qx_93 = eqQ_0_linxafkvx1(file_0, pRawInfo_0.file_0);
      if ((!X60Qx_93)){
        nimStrDestroy(fileAsStr_0);
        string_0_sysvq0asl* X60Qx_94 = getQ_0_Io78pjy1_intzsnzax(pool_0_nifh7u8pu1.files_0, file_0);
        string_0_sysvq0asl X60Qx_95 = nimStrDup((*X60Qx_94));
        fileAsStr_0 = X60Qx_95;}
      NI32 X60Qx_96 = len_4_sysvq0asl(fileAsStr_0);
      if (X60Qx_96 == 0){
        line_0 = ((NI32)(line_0 - pRawInfo_0.line_0));
        col_0 = ((NI32)(col_0 - pRawInfo_0.col_0));}}
    else {
      nimStrDestroy(fileAsStr_0);
      string_0_sysvq0asl* X60Qx_97 = getQ_0_Io78pjy1_intzsnzax(pool_0_nifh7u8pu1.files_0, file_0);
      string_0_sysvq0asl X60Qx_98 = nimStrDup((*X60Qx_97));
      fileAsStr_0 = X60Qx_98;}
    attachLineInfo_1_nifjp9lau1(b_6, col_0, line_0, fileAsStr_0);
    nimStrDestroy(fileAsStr_0);}
  if ((!(rawInfo_1.comment_0 == ((NU32)0u)))){
    string_0_sysvq0asl* X60Qx_99 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, ((NU32)rawInfo_1.comment_0));
    attachComment_0_nifjp9lau1(b_6, (*X60Qx_99));}}
string_0_sysvq0asl toString_0_nifh7u8pu1(openArray_0_I0m47e11_nifb6mq6y1 tree_1, NB8 produceLineInfo_0){
  string_0_sysvq0asl result_45;
  nimStrWasMoved((&result_45));
  NI32 X60Qx_100 = len_6_I4emj7h_nifb6mq6y1(tree_1);
  Builder_0_nifjp9lau1 b_8 = open_1_nifjp9lau1(((NI32)(X60Qx_100 * 20)), NIM_FALSE);
  seq_0_Io4pvgy1_nifb6mq6y1 stack_0 = newSeqUninit_0_Ijkckzz_nifb6mq6y1(0);
  {
    NI32 X60Qlf_3 = 0;
    NI32 X60Qlf_4 = len_6_I4emj7h_nifb6mq6y1(tree_1);
    NI32 X60Qlf_5 = X60Qlf_3;
    {
      while (X60Qlf_5 < X60Qlf_4){
        {
          PackedToken_0_nifh7u8pu1* X60Qx_101 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
          NU32 X60Qii_2 = (*X60Qx_101).info_0;
          PackedToken_0_nifh7u8pu1* X60Qx_102 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
          NifKind_0_nif81dubp1 X60Qii_3 = ((NifKind_0_nif81dubp1)((NU32)((*X60Qx_102).x_0 & ((NU32)15u))));
          switch (X60Qii_3){
            case 2:
            {
              addEmpty_0_nifjp9lau1((&b_8), 1);}
            break;
            case 3:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_103 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              NU32 X60Qx_104 = litId_0_nifh7u8pu1((*X60Qx_103));
              string_0_sysvq0asl* X60Qx_105 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_104);
              addIdent_0_nifjp9lau1((&b_8), (*X60Qx_105));}
            break;
            case 4:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_106 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              NU32 X60Qx_107 = symId_0_nifh7u8pu1((*X60Qx_106));
              string_0_sysvq0asl* X60Qx_108 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, X60Qx_107);
              addSymbol_0_nifjp9lau1((&b_8), (*X60Qx_108));}
            break;
            case 8:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_109 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              NU32 X60Qx_110 = intId_0_nifh7u8pu1((*X60Qx_109));
              NI64* X60Qx_111 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_110);
              addIntLit_0_nifjp9lau1((&b_8), (*X60Qx_111));}
            break;
            case 9:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_112 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              NU32 X60Qx_113 = uintId_0_nifh7u8pu1((*X60Qx_112));
              NU64* X60Qx_114 = getQ_0_Iebom0i1_ast8ri79k(pool_0_nifh7u8pu1.uintegers_0, X60Qx_113);
              addUIntLit_0_nifjp9lau1((&b_8), (*X60Qx_114));}
            break;
            case 10:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_115 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              NU32 X60Qx_116 = floatId_0_nifh7u8pu1((*X60Qx_115));
              NF64 X60Qx_117 = getQ_1_I4qx0py_ast8ri79k(pool_0_nifh7u8pu1.floats_0, X60Qx_116);
              addFloatLit_0_nifjp9lau1((&b_8), X60Qx_117, 0, 0, (string_0_sysvq0asl){
                .bytes_0 = 0u, .more_0 = NIM_NIL}
              );}
            break;
            case 5:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_118 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              NU32 X60Qx_119 = symId_0_nifh7u8pu1((*X60Qx_118));
              string_0_sysvq0asl* X60Qx_120 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, X60Qx_119);
              addSymbolDef_0_nifjp9lau1((&b_8), (*X60Qx_120));}
            break;
            case 7:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_121 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              addCharLit_0_nifjp9lau1((&b_8), ((NC8)((NU32)((*X60Qx_121).x_0 >> ((NU32)4u)))));}
            break;
            case 6:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_122 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              NU32 X60Qx_123 = litId_0_nifh7u8pu1((*X60Qx_122));
              string_0_sysvq0asl* X60Qx_124 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_123);
              addStrLit_0_nifjp9lau1((&b_8), (*X60Qx_124));}
            break;
            case 0:
            {
              addIdent_0_nifjp9lau1((&b_8), (string_0_sysvq0asl){
                .bytes_0 = 1853177086u, .more_0 = (&strlit_0_I11191788154693975321_nif81dubp1)}
              );}
            break;
            case 1:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_125 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              addIntLit_0_nifjp9lau1((&b_8), ((NI64)((NI32)((NU32)((*X60Qx_125).x_0 >> ((NU32)4u))))));}
            break;
            case 12:
            {
              if (0 < stack_0.len_0){
                NU32 X60Qx_126 = pop_0_I608lbn1_nifh7u8pu1((&stack_0));}
              endTree_0_nifjp9lau1((&b_8));}
            break;
            case 11:
            {
              PackedToken_0_nifh7u8pu1* X60Qx_127 = getQ_10_Iids335_nifb6mq6y1(tree_1, X60Qlf_5);
              NU32 X60Qx_128 = tagId_0_nifh7u8pu1((*X60Qx_127));
              string_0_sysvq0asl* X60Qx_129 = getQ_0_I93d71y_der823rwr1(pool_0_nifh7u8pu1.tags_0, X60Qx_128);
              addTree_0_nifjp9lau1((&b_8), (*X60Qx_129));}
            break;}
          NB8 X60Qx_130;
          NB8 X60Qx_131;
          if (produceLineInfo_0){
            NB8 X60Qx_132 = isValid_0_linxafkvx1(X60Qii_2);
            X60Qx_131 = X60Qx_132;}
          else {
            X60Qx_131 = NIM_FALSE;}
          if (X60Qx_131){
            X60Qx_130 = (!(X60Qii_3 == 12));}
          else {
            X60Qx_130 = NIM_FALSE;}
          if (X60Qx_130){
            NU32 X60Qx_1;
            if (0 < stack_0.len_0){
              NU32* X60Qx_133 = getQ_7_I4w3aqj1_nifh7u8pu1(stack_0, ((NI32)(stack_0.len_0 - ((NI32)((NI32)1)))));
              X60Qx_1 = (*X60Qx_133);}
            else {
              X60Qx_1 = NoLineInfo_0_linxafkvx1;}
            emitLineInfo_0_nifh7u8pu1((&b_8), X60Qii_2, X60Qx_1);}
          if (X60Qii_3 == 11){
            add_0_I6yw3841_nifh7u8pu1((&stack_0), X60Qii_2);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  nimStrDestroy(result_45);
  Builder_0_nifjp9lau1 X60Qtmp_10 = b_8;
  eQwasmovedQ_SX42uilder0nifjp9lau1_0_nifh7u8pu1((&b_8));
  string_0_sysvq0asl X60Qx_134 = extract_0_nifjp9lau1(X60Qtmp_10);
  result_45 = X60Qx_134;
  eQdestroy_1_I35tn0j_nifb6mq6y1(stack_0);
  eQdestroyQ_SX42uilder0nifjp9lau1_0_nifh7u8pu1((&b_8));
  return result_45;
  eQdestroy_1_I35tn0j_nifb6mq6y1(stack_0);
  eQdestroyQ_SX42uilder0nifjp9lau1_0_nifh7u8pu1((&b_8));
  return result_45;}
static inline NI32 len_6_I5j2qim1_nifh7u8pu1(openArray_0_Ixtg67b1_nifh7u8pu1 a_9){
  NI32 result_58;
  result_58 = a_9.len_0;
  return result_58;}
static inline X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* getQ_10_Ieolp4z_nifh7u8pu1(openArray_0_Ixtg67b1_nifh7u8pu1 x_11, NI32 idx_2){
  NB8 X60Qx_202;
  if (0 <= idx_2){
    X60Qx_202 = (idx_2 < x_11.len_0);}
  else {
    X60Qx_202 = NIM_FALSE;}
  if ((!X60Qx_202)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax* result_59;
  result_59 = (&x_11.a_0[idx_2]);
  return result_59;}
static inline openArray_0_Ixtg67b1_nifh7u8pu1 toOpenArray_0_Isa0kxh_nifh7u8pu1(X60Qt_0_IAarrayAtupleSstring0sysvq0aslAiS32ZZS342_nifh7u8pu1* x_12){
  openArray_0_Ixtg67b1_nifh7u8pu1 result_61;
  openArray_0_Ixtg67b1_nifh7u8pu1 X60Qx_4;
  if (((NI32)(((NI32)(((NI32)((TagEnum_0_tagygirdh1)341)) - ((NI32)((TagEnum_0_tagygirdh1)0)))) + 1)) == 0){
    X60Qx_4 = (openArray_0_Ixtg67b1_nifh7u8pu1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_4 = (openArray_0_Ixtg67b1_nifh7u8pu1){
      .a_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslAiS32_intzsnzax*)(&(*x_12))), .len_0 = ((NI32)(((NI32)(((NI32)((TagEnum_0_tagygirdh1)341)) - ((NI32)((TagEnum_0_tagygirdh1)0)))) + 1))}
    ;}
  result_61 = X60Qx_4;
  return result_61;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ika21pk_nifh7u8pu1(NifKind_0_nif81dubp1 kind_9, NU32 id_13, NU32 info_28){
  PackedToken_0_nifh7u8pu1 result_62;
  result_62 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_9) | ((NU32)(((NU32)id_13) << ((NU32)4u))))), .info_0 = info_28}
  ;
  return result_62;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iip05tk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_10, NU32 id_14, NU32 info_29){
  PackedToken_0_nifh7u8pu1 result_63;
  result_63 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_10) | ((NU32)(((NU32)id_14) << ((NU32)4u))))), .info_0 = info_29}
  ;
  return result_63;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ie5j2hb_nifh7u8pu1(NifKind_0_nif81dubp1 kind_11, NU32 id_15, NU32 info_30){
  PackedToken_0_nifh7u8pu1 result_64;
  result_64 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_11) | ((NU32)(((NU32)id_15) << ((NU32)4u))))), .info_0 = info_30}
  ;
  return result_64;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iz0lv7d1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_12, NU32 id_16, NU32 info_31){
  PackedToken_0_nifh7u8pu1 result_65;
  result_65 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_12) | ((NU32)(((NU32)id_16) << ((NU32)4u))))), .info_0 = info_31}
  ;
  return result_65;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Is7quwk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_13, NU32 id_17, NU32 info_32){
  PackedToken_0_nifh7u8pu1 result_66;
  result_66 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_13) | ((NU32)(((NU32)id_17) << ((NU32)4u))))), .info_0 = info_32}
  ;
  return result_66;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ikm2gt2_nifh7u8pu1(NifKind_0_nif81dubp1 kind_14, NU32 id_18, NU32 info_33){
  PackedToken_0_nifh7u8pu1 result_67;
  result_67 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_14) | ((NU32)(((NU32)id_18) << ((NU32)4u))))), .info_0 = info_33}
  ;
  return result_67;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ifgbqjw1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_15, NU32 id_19, NU32 info_34){
  PackedToken_0_nifh7u8pu1 result_68;
  result_68 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_15) | ((NU32)(((NU32)id_19) << ((NU32)4u))))), .info_0 = info_34}
  ;
  return result_68;}
static inline void add_0_I6yw3841_nifh7u8pu1(seq_0_Io4pvgy1_nifb6mq6y1* s_17, NU32 elem_3){
  NI32 L_0 = (*s_17).len_0;
  NI32 X60Qx_219 = capInBytes_0_Id76iiw1_nifb6mq6y1((*s_17));
  if (X60Qx_219 < ((NI32)(((NI32)(L_0 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_220 = resize_0_I9xvz9p1_nifh7u8pu1(s_17, 1);
    if ((!X60Qx_220)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_17).len_0));
  (*s_17).data_0[L_0] = elem_3;}
static inline NU32* getQ_7_I4w3aqj1_nifh7u8pu1(seq_0_Io4pvgy1_nifb6mq6y1 s_23, NI32 i_8){
  NB8 X60Qx_235;
  if (i_8 < s_23.len_0){
    X60Qx_235 = (0 <= i_8);}
  else {
    X60Qx_235 = NIM_FALSE;}
  if ((!X60Qx_235)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_71;
  result_71 = (&s_23.data_0[i_8]);
  return result_71;}
NU32 getOrIncl_0_Iaj0qm3_nifh7u8pu1(BiTable_0_Ieutpr21_intzsnzax* t_26, string_0_sysvq0asl v_10){
  NU32 result_72;
  NU32 origH_2 = hash_1_has9tn57v(v_10);
  NI32 X60Qx_236 = high_3_Izd57vi1_nifh7u8pu1((*t_26).keys_0);
  NU32 h_2 = ((NU32)(origH_2 & ((NU32)X60Qx_236)));
  if ((!((*t_26).keys_0.len_0 == 0))){
    {
      while (NIM_TRUE){
        NU32* X60Qx_237 = getQ_8_I1x0pam_nifh7u8pu1((*t_26).keys_0, h_2);
        NU32 litId_11 = (*X60Qx_237);
        if ((!(((NU32)0u) < ((NU32)litId_11)))){
          goto whileStmtLabel_0;}
        NU32* X60Qx_238 = getQ_8_I1x0pam_nifh7u8pu1((*t_26).keys_0, h_2);
        string_0_sysvq0asl* X60Qx_239 = getQ_7_Ir6d0tw_aow7lb5cq1((*t_26).vals_0, ((NI32)(((NI32)(*X60Qx_238)) - ((NI32)1))));
        NB8 X60Qx_240 = eqQ_20_sysvq0asl(v_10, (*X60Qx_239));
        if (X60Qx_240){
          return litId_11;}
        NI32 X60Qx_241 = high_3_Izd57vi1_nifh7u8pu1((*t_26).keys_0);
        NU32 X60Qx_242 = nextTry_0_bitekkhcx1(h_2, ((NU32)X60Qx_241));
        h_2 = X60Qx_242;}}
    whileStmtLabel_0: ;
    NB8 X60Qx_243 = mustRehash_0_bitekkhcx1((*t_26).keys_0.len_0, (*t_26).vals_0.len_0);
    if (X60Qx_243){
      enlarge_0_Iffz5zw1_nifh7u8pu1(t_26);
      NI32 X60Qx_244 = high_3_Izd57vi1_nifh7u8pu1((*t_26).keys_0);
      h_2 = ((NU32)(origH_2 & ((NU32)X60Qx_244)));
      {
        while (NIM_TRUE){
          NU32* X60Qx_245 = getQ_8_I1x0pam_nifh7u8pu1((*t_26).keys_0, h_2);
          NU32 litId_12 = (*X60Qx_245);
          if ((!(((NU32)0u) < ((NU32)litId_12)))){
            goto whileStmtLabel_1;}
          NI32 X60Qx_246 = high_3_Izd57vi1_nifh7u8pu1((*t_26).keys_0);
          NU32 X60Qx_247 = nextTry_0_bitekkhcx1(h_2, ((NU32)X60Qx_246));
          h_2 = X60Qx_247;}}
      whileStmtLabel_1: ;}}
  else {
    setLen_0_Izwgy3z_nifh7u8pu1((&(*t_26).keys_0), 16);
    NI32 X60Qx_248 = high_3_Izd57vi1_nifh7u8pu1((*t_26).keys_0);
    h_2 = ((NU32)(origH_2 & ((NU32)X60Qx_248)));}
  result_72 = ((NU32)((NI32)((*t_26).vals_0.len_0 + ((NI32)1))));
  putQ_8_Ird3zar1_nifh7u8pu1((&(*t_26).keys_0), h_2, result_72);
  string_0_sysvq0asl X60Qx_249 = nimStrDup(v_10);
  add_0_Ig6072n_aow7lb5cq1((&(*t_26).vals_0), X60Qx_249);
  return result_72;}
static inline NU32 pop_0_I608lbn1_nifh7u8pu1(seq_0_Io4pvgy1_nifb6mq6y1* s_29){
  if ((!(0 < (*s_29).len_0))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I4759879970636729446_nifh7u8pu1)}
    );}
  NU32 result_74;
  NI32 L_1 = ((NI32)((*s_29).len_0 - 1));
  NU32* X60Qx_250 = getQ_7_I4w3aqj1_nifh7u8pu1((*s_29), L_1);
  result_74 = (*X60Qx_250);
  (*s_29).len_0 = L_1;
  return result_74;}
NU32 getOrInclFromView_0_Iledlgq1_nifh7u8pu1(BiTable_0_Icvz6lt_buiyylk1h1* t_28, StringView_0_strdllfw2 v_11){
  NU32 result_75;
  NU32 origH_3 = hash_0_strdllfw2(v_11);
  NI32 X60Qx_251 = high_3_Ib20i801_buiyylk1h1((*t_28).keys_0);
  NU32 h_3 = ((NU32)(origH_3 & ((NU32)X60Qx_251)));
  if ((!((*t_28).keys_0.len_0 == 0))){
    {
      while (NIM_TRUE){
        NU32* X60Qx_252 = getQ_8_I1lkkvo_buiyylk1h1((*t_28).keys_0, h_3);
        NU32 litId_13 = (*X60Qx_252);
        if ((!(((NU32)0u) < ((NU32)litId_13)))){
          goto whileStmtLabel_0;}
        NU32* X60Qx_253 = getQ_8_I1lkkvo_buiyylk1h1((*t_28).keys_0, h_3);
        string_0_sysvq0asl* X60Qx_254 = getQ_7_Ir6d0tw_aow7lb5cq1((*t_28).vals_0, ((NI32)(((NI32)(*X60Qx_253)) - ((NI32)1))));
        NB8 X60Qx_255 = eqQ_1_strdllfw2(v_11, (*X60Qx_254));
        if (X60Qx_255){
          return litId_13;}
        NI32 X60Qx_256 = high_3_Ib20i801_buiyylk1h1((*t_28).keys_0);
        NU32 X60Qx_257 = nextTry_0_bitekkhcx1(h_3, ((NU32)X60Qx_256));
        h_3 = X60Qx_257;}}
    whileStmtLabel_0: ;
    NB8 X60Qx_258 = mustRehash_0_bitekkhcx1((*t_28).keys_0.len_0, (*t_28).vals_0.len_0);
    if (X60Qx_258){
      enlarge_0_I4mrsk51_buiyylk1h1(t_28);
      NI32 X60Qx_259 = high_3_Ib20i801_buiyylk1h1((*t_28).keys_0);
      h_3 = ((NU32)(origH_3 & ((NU32)X60Qx_259)));
      {
        while (NIM_TRUE){
          NU32* X60Qx_260 = getQ_8_I1lkkvo_buiyylk1h1((*t_28).keys_0, h_3);
          NU32 litId_14 = (*X60Qx_260);
          if ((!(((NU32)0u) < ((NU32)litId_14)))){
            goto whileStmtLabel_1;}
          NI32 X60Qx_261 = high_3_Ib20i801_buiyylk1h1((*t_28).keys_0);
          NU32 X60Qx_262 = nextTry_0_bitekkhcx1(h_3, ((NU32)X60Qx_261));
          h_3 = X60Qx_262;}}
      whileStmtLabel_1: ;}}
  else {
    setLen_0_Isypn1s_buiyylk1h1((&(*t_28).keys_0), 16);
    NI32 X60Qx_263 = high_3_Ib20i801_buiyylk1h1((*t_28).keys_0);
    h_3 = ((NU32)(origH_3 & ((NU32)X60Qx_263)));}
  result_75 = ((NU32)((NI32)((*t_28).vals_0.len_0 + ((NI32)1))));
  putQ_8_Iltefhx_buiyylk1h1((&(*t_28).keys_0), h_3, result_75);
  string_0_sysvq0asl X60Qx_264 = dollarQ_0_strdllfw2(v_11);
  add_0_Ig6072n_aow7lb5cq1((&(*t_28).vals_0), X60Qx_264);
  return result_75;}
NB8 resize_0_I9xvz9p1_nifh7u8pu1(seq_0_Io4pvgy1_nifb6mq6y1* dest_6, NI32 addedElements_2){
  NB8 result_105;
  NI32 X60Qx_329 = capInBytes_0_Id76iiw1_nifb6mq6y1((*dest_6));
  NI32 oldCap_0 = ((NI32)(X60Qx_329 / sizeof(NU32)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_2);
  NI32 memSize_12 = memSizeInBytes_0_Isupifd_nifb6mq6y1(newCap_0);
  void* X60Qx_330 = realloc_1_sysvq0asl(((void*)((void*)(*dest_6).data_0)), memSize_12);
  (*dest_6).data_0 = ((NU32*)X60Qx_330);
  if ((*dest_6).data_0 == NIM_NIL){
    (*dest_6).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_12);
    result_105 = NIM_FALSE;}
  else {
    result_105 = NIM_TRUE;}
  return result_105;}
static inline NI32 high_3_Izd57vi1_nifh7u8pu1(seq_0_If70loa_intzsnzax s_68){
  NI32 result_108;
  result_108 = ((NI32)(s_68.len_0 - 1));
  return result_108;}
static inline NU32* getQ_8_I1x0pam_nifh7u8pu1(seq_0_If70loa_intzsnzax s_69, NU32 i_30){
  if ((!(i_30 < ((NU32)s_69.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  NU32* result_109;
  result_109 = (&s_69.data_0[((NI32)i_30)]);
  return result_109;}
void enlarge_0_Iffz5zw1_nifh7u8pu1(BiTable_0_Ieutpr21_intzsnzax* t_47){
  seq_0_If70loa_intzsnzax n_22;
  eQwasMoved_1_Idi7njb_intzsnzax((&n_22));
  NI32 X60Qx_341 = len_3_I2lzgei1_nifh7u8pu1((*t_47).keys_0);
  newSeq_1_Ijeltsd1_nifh7u8pu1((&n_22), ((NI32)(X60Qx_341 * 2)));
  swap_0_Iu9nbuo1_nifh7u8pu1((&(*t_47).keys_0), (&n_22));
  {
    NI32 X60Qlf_15 = 0;
    NI32 X60Qlf_16 = high_3_Izd57vi1_nifh7u8pu1(n_22);
    NI32 X60Qlf_17 = X60Qlf_15;
    {
      while (X60Qlf_17 <= X60Qlf_16){
        {
          NU32* X60Qx_342 = getQ_7_Ic0x56f1_nifh7u8pu1(n_22, X60Qlf_17);
          NU32 X60Qii_2 = (*X60Qx_342);
          if (((NU32)0u) < ((NU32)X60Qii_2)){
            string_0_sysvq0asl* X60Qx_343 = getQ_7_Ir6d0tw_aow7lb5cq1((*t_47).vals_0, ((NI32)(((NI32)X60Qii_2) - ((NI32)1))));
            NU32 X60Qx_344 = hash_1_has9tn57v((*X60Qx_343));
            NI32 X60Qx_345 = high_3_Izd57vi1_nifh7u8pu1((*t_47).keys_0);
            NU32 X60Qii_3 = ((NU32)(X60Qx_344 & ((NU32)X60Qx_345)));
            while (NIM_TRUE){
              NU32* X60Qx_346 = getQ_8_I1x0pam_nifh7u8pu1((*t_47).keys_0, X60Qii_3);
              if (((NU32)0u) < ((NU32)(*X60Qx_346))){
                NI32 X60Qx_347 = high_3_Izd57vi1_nifh7u8pu1((*t_47).keys_0);
                NU32 X60Qx_348 = nextTry_0_bitekkhcx1(X60Qii_3, ((NU32)X60Qx_347));
                X60Qii_3 = X60Qx_348;}
              else {
                break;}}
            NU32* X60Qx_349 = getQ_7_Ic0x56f1_nifh7u8pu1(n_22, X60Qlf_17);
            NU32 X60Qx_350 = move_0_I4g2vpk_nifh7u8pu1(X60Qx_349);
            putQ_8_Ird3zar1_nifh7u8pu1((&(*t_47).keys_0), X60Qii_3, X60Qx_350);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_17));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroy_1_Iv1ystk1_intzsnzax(n_22);}
void setLen_0_Izwgy3z_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_73, NI32 newLen_15){
  if (newLen_15 < (*s_73).len_0){
    shrink_0_Icn19hv_nifh7u8pu1(s_73, newLen_15);}
  else {
    NI32 i_33 = (*s_73).len_0;
    growUnsafe_0_Iugjmld1_nifh7u8pu1(s_73, newLen_15);
    if ((*s_73).data_0 == NIM_NIL){
      return;}
    {
      while (i_33 < newLen_15){
        (*s_73).data_0[i_33] = ((NU32)0u);
        inc_1_I6wjjge_aow2h993l1((&i_33));}}
    whileStmtLabel_0: ;}}
static inline void putQ_8_Ird3zar1_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_76, NU32 i_34, NU32 elem_14){
  if ((!(i_34 < ((NU32)(*s_76).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_76).data_0[((NI32)i_34)] = elem_14;}
static inline NI32 len_3_I2lzgei1_nifh7u8pu1(seq_0_If70loa_intzsnzax s_127){
  NI32 result_128;
  result_128 = s_127.len_0;
  return result_128;}
static inline void newSeq_1_Ijeltsd1_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_128, NI32 newLen_37){
  seq_0_If70loa_intzsnzax X60Qx_411 = newSeq_0_Ix86g6u_nifh7u8pu1(newLen_37);
  (*s_128) = X60Qx_411;}
static inline void swap_0_Iu9nbuo1_nifh7u8pu1(seq_0_If70loa_intzsnzax* x_32, seq_0_If70loa_intzsnzax* y_8){
  seq_0_If70loa_intzsnzax tmp_2 = (*x_32);
  (*x_32) = (*y_8);
  (*y_8) = tmp_2;}
static inline NU32* getQ_7_Ic0x56f1_nifh7u8pu1(seq_0_If70loa_intzsnzax s_129, NI32 i_59){
  NB8 X60Qx_412;
  if (i_59 < s_129.len_0){
    X60Qx_412 = (0 <= i_59);}
  else {
    X60Qx_412 = NIM_FALSE;}
  if ((!X60Qx_412)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_129;
  result_129 = (&s_129.data_0[i_59]);
  return result_129;}
static inline NU32 move_0_I4g2vpk_nifh7u8pu1(NU32* x_33){
  NU32 result_130;
  result_130 = (*x_33);
  return result_130;}
void shrink_0_Icn19hv_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_130, NI32 newLen_38){
  NI32 i_60 = ((NI32)((*s_130).len_0 - 1));
  {
    while (newLen_38 <= i_60){
      dec_1_I0nzoz91_aow7lb5cq1((&i_60));}}
  whileStmtLabel_0: ;
  (*s_130).len_0 = newLen_38;}
void growUnsafe_0_Iugjmld1_nifh7u8pu1(seq_0_If70loa_intzsnzax* s_131, NI32 newLen_39){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_39, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_2 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_413 = capInBytes_0_Iryrob_intzsnzax((*s_131));
  if (X60Qx_413 < newSize_2){
    NB8 X60Qx_414 = resize_0_Io7u6td1_nifh7u8pu1(s_131, ((NI32)(newLen_39 - (*s_131).len_0)));
    if ((!X60Qx_414)){
      return;}}
  (*s_131).len_0 = newLen_39;}
seq_0_If70loa_intzsnzax newSeq_0_Ix86g6u_nifh7u8pu1(NI32 size_56){
  seq_0_If70loa_intzsnzax result_152;
  if (size_56 == 0){
    result_152 = (seq_0_If70loa_intzsnzax){
      .len_0 = size_56, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_20 = memSizeInBytes_0_Ib1bjtc_intzsnzax(size_56);
    void* X60Qx_451 = alloc_1_sysvq0asl(memSize_20);
    result_152 = (seq_0_If70loa_intzsnzax){
      .len_0 = size_56, .data_0 = ((NU32*)X60Qx_451)}
    ;
    if ((!(result_152.data_0 == NIM_NIL))){
      NI32 i_74 = 0;
      {
        while (i_74 < size_56){
          result_152.data_0[i_74] = ((NU32)0u);
          inc_1_I6wjjge_aow2h993l1((&i_74));}}
      whileStmtLabel_0: ;}
    else {
      result_152.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_20);}}
  return result_152;}
NB8 resize_0_Io7u6td1_nifh7u8pu1(seq_0_If70loa_intzsnzax* dest_20, NI32 addedElements_16){
  NB8 result_154;
  NI32 X60Qx_453 = capInBytes_0_Iryrob_intzsnzax((*dest_20));
  NI32 oldCap_6 = ((NI32)(X60Qx_453 / sizeof(NU32)));
  NI32 newCap_6 = recalcCap_0_sysvq0asl(oldCap_6, addedElements_16);
  NI32 memSize_21 = memSizeInBytes_0_Ib1bjtc_intzsnzax(newCap_6);
  void* X60Qx_454 = realloc_1_sysvq0asl(((void*)((void*)(*dest_20).data_0)), memSize_21);
  (*dest_20).data_0 = ((NU32*)X60Qx_454);
  if ((*dest_20).data_0 == NIM_NIL){
    (*dest_20).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_21);
    result_154 = NIM_FALSE;}
  else {
    result_154 = NIM_TRUE;}
  return result_154;}
void eQdestroyQ_SX4citerals0nifh7u8pu1_0_nifh7u8pu1(Literals_0_nifh7u8pu1* dest_0){
  eQdestroyQ_SX42iX54ableX46loat0X49u8fssa_0_nifh7u8pu1((*dest_0).floats_0);
  eQdestroyQ_SX42iX54able0X49txao711_0_nifh7u8pu1((*dest_0).uintegers_0);
  eQdestroyQ_SX42iX54able0X49tvq7bk_0_nifh7u8pu1((*dest_0).integers_0);
  eQdestroyQ_SX42iX54able0X49pgo74p_0_nifh7u8pu1((*dest_0).strings_0);
  eQdestroyQ_SX42iX54able0X490ksat5_0_nifh7u8pu1((*dest_0).syms_0);
  eQdestroyQ_SX42iX54able0X49eutpr21_0_nifh7u8pu1((*dest_0).files_0);
  eQdestroyQ_SX42iX54able0X49cvz6lt_0_nifh7u8pu1((*dest_0).tags_0);
  eQdestroyQ_SX4cineX49nfoX4danager0linxafkvx1_0_linxafkvx1((*dest_0).man_0);}
void eQwasmovedQ_SX4citerals0nifh7u8pu1_0_nifh7u8pu1(Literals_0_nifh7u8pu1* dest_0){
  eQwasmovedQ_SX4cineX49nfoX4danager0linxafkvx1_0_linxafkvx1((&(*dest_0).man_0));
  eQwasmovedQ_SX42iX54able0X49cvz6lt_0_nifh7u8pu1((&(*dest_0).tags_0));
  eQwasmovedQ_SX42iX54able0X49eutpr21_0_nifh7u8pu1((&(*dest_0).files_0));
  eQwasmovedQ_SX42iX54able0X490ksat5_0_nifh7u8pu1((&(*dest_0).syms_0));
  eQwasmovedQ_SX42iX54able0X49pgo74p_0_nifh7u8pu1((&(*dest_0).strings_0));
  eQwasmovedQ_SX42iX54able0X49tvq7bk_0_nifh7u8pu1((&(*dest_0).integers_0));
  eQwasmovedQ_SX42iX54able0X49txao711_0_nifh7u8pu1((&(*dest_0).uintegers_0));
  eQwasmovedQ_SX42iX54ableX46loat0X49u8fssa_0_nifh7u8pu1((&(*dest_0).floats_0));}
void eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1(Stream_0_nifh7u8pu1* dest_0){
  eQdestroy_1_I35tn0j_nifb6mq6y1((*dest_0).parents_0);
  eQdestroyQ_SX52eader0nif81dubp1_0_nif81dubp1((&(*dest_0).r_0));}
void eQwasmovedQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1(Stream_0_nifh7u8pu1* dest_0){
  eQwasmovedQ_SX52eader0nif81dubp1_0_nif81dubp1((&(*dest_0).r_0));
  eQwasMoved_1_Igz5mgz_nifb6mq6y1((&(*dest_0).parents_0));}
void eQdestroyQ_SX42iX54able0X49cvz6lt_0_nifh7u8pu1(BiTable_0_Icvz6lt_buiyylk1h1 dest_0){
  eQdestroy_1_I5fjqyi1_buiyylk1h1(dest_0.keys_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(dest_0.vals_0);}
void eQwasmovedQ_SX42iX54able0X49cvz6lt_0_nifh7u8pu1(BiTable_0_Icvz6lt_buiyylk1h1* dest_0){
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&(*dest_0).vals_0));
  eQwasMoved_1_Iew8iz1_buiyylk1h1((&(*dest_0).keys_0));}
void eQdestroyQ_SX42iX54able0X49eutpr21_0_nifh7u8pu1(BiTable_0_Ieutpr21_intzsnzax dest_0){
  eQdestroy_1_Iv1ystk1_intzsnzax(dest_0.keys_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(dest_0.vals_0);}
void eQwasmovedQ_SX42iX54able0X49eutpr21_0_nifh7u8pu1(BiTable_0_Ieutpr21_intzsnzax* dest_0){
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&(*dest_0).vals_0));
  eQwasMoved_1_Idi7njb_intzsnzax((&(*dest_0).keys_0));}
void eQdestroyQ_SX42iX54able0X490ksat5_0_nifh7u8pu1(BiTable_0_I0ksat5_ast8ri79k dest_0){
  eQdestroy_1_Iscb4i31_arecyyj7v(dest_0.keys_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(dest_0.vals_0);}
void eQwasmovedQ_SX42iX54able0X490ksat5_0_nifh7u8pu1(BiTable_0_I0ksat5_ast8ri79k* dest_0){
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&(*dest_0).vals_0));
  eQwasMoved_1_I2k4kel_arecyyj7v((&(*dest_0).keys_0));}
void eQdestroyQ_SX42iX54able0X49pgo74p_0_nifh7u8pu1(BiTable_0_Ipgo74p_ast8ri79k dest_0){
  eQdestroy_1_In04crl1_ast8ri79k(dest_0.keys_0);
  eQdestroy_1_Ivioh0a_aow7lb5cq1(dest_0.vals_0);}
void eQwasmovedQ_SX42iX54able0X49pgo74p_0_nifh7u8pu1(BiTable_0_Ipgo74p_ast8ri79k* dest_0){
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&(*dest_0).vals_0));
  eQwasMoved_1_I94uyip1_ast8ri79k((&(*dest_0).keys_0));}
void eQdestroyQ_SX42iX54able0X49tvq7bk_0_nifh7u8pu1(BiTable_0_Itvq7bk_ast8ri79k dest_0){
  eQdestroy_1_Inr6ycs1_ast8ri79k(dest_0.keys_0);
  eQdestroy_1_Iez2nr5_ast8ri79k(dest_0.vals_0);}
void eQwasmovedQ_SX42iX54able0X49tvq7bk_0_nifh7u8pu1(BiTable_0_Itvq7bk_ast8ri79k* dest_0){
  eQwasMoved_1_Ia0kll01_ast8ri79k((&(*dest_0).vals_0));
  eQwasMoved_1_I5re2ul_ast8ri79k((&(*dest_0).keys_0));}
void eQdestroyQ_SX42iX54able0X49txao711_0_nifh7u8pu1(BiTable_0_Itxao711_ast8ri79k dest_0){
  eQdestroy_1_I7og8li_ast8ri79k(dest_0.keys_0);
  eQdestroy_1_Ic8bbvt1_ast8ri79k(dest_0.vals_0);}
void eQwasmovedQ_SX42iX54able0X49txao711_0_nifh7u8pu1(BiTable_0_Itxao711_ast8ri79k* dest_0){
  eQwasMoved_1_I6m9e8j_ast8ri79k((&(*dest_0).vals_0));
  eQwasMoved_1_I52bdqo1_ast8ri79k((&(*dest_0).keys_0));}
void eQdestroyQ_SX42iX54ableX46loat0X49u8fssa_0_nifh7u8pu1(BiTable_0_Iojfwmy1_ast8ri79k dest_0){
  eQdestroyQ_SX42iX54able0X49ojfwmy1_0_nifh7u8pu1(dest_0);}
void eQwasmovedQ_SX42iX54ableX46loat0X49u8fssa_0_nifh7u8pu1(BiTable_0_Iojfwmy1_ast8ri79k* dest_0){
  eQwasmovedQ_SX42iX54able0X49ojfwmy1_0_nifh7u8pu1(dest_0);}
void eQdestroyQ_SX42iX54able0X49ojfwmy1_0_nifh7u8pu1(BiTable_0_Iojfwmy1_ast8ri79k dest_0){
  eQdestroy_1_Iz0k69p1_ast8ri79k(dest_0.keys_0);
  eQdestroy_1_Ic8bbvt1_ast8ri79k(dest_0.vals_0);}
void eQwasmovedQ_SX42iX54able0X49ojfwmy1_0_nifh7u8pu1(BiTable_0_Iojfwmy1_ast8ri79k* dest_0){
  eQwasMoved_1_I6m9e8j_ast8ri79k((&(*dest_0).vals_0));
  eQwasMoved_1_I5y4iq9_ast8ri79k((&(*dest_0).keys_0));}
void eQdestroyQ_SX42uilder0nifjp9lau1_0_nifh7u8pu1(Builder_0_nifjp9lau1* dest_0){
  nimStrDestroy((*dest_0).filename_0);
  nimStrDestroy((*dest_0).buffer_0);}
void eQwasmovedQ_SX42uilder0nifjp9lau1_0_nifh7u8pu1(Builder_0_nifjp9lau1* dest_0){
  nimStrWasMoved((&(*dest_0).buffer_0));
  nimStrWasMoved((&(*dest_0).filename_0));}
void X60Qini_0_nifh7u8pu1(void){
  if (X60QiniGuard_0_nifh7u8pu1){
    return;}
  X60QiniGuard_0_nifh7u8pu1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_assy765wm();
  X60Qini_0_has9tn57v();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_strdllfw2();
  X60Qini_0_linxafkvx1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nifjp9lau1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_tagygirdh1();
  openArray_0_Ixtg67b1_nifh7u8pu1 X60Qx_43 = toOpenArray_0_Isa0kxh_nifh7u8pu1((&TagData_0_tagygirdh1));
  pool_0_nifh7u8pu1 = createLiterals_0_nifh7u8pu1(X60Qx_43);}
static inline NU32 hash_2_has9tn57v(NU32 u_0){
  NU32 result_3;
  result_3 = u_0;
  return result_3;}
static inline seq_0_Ivkh6l1_linxafkvx1 newSeqUninit_0_Izs0ei1_linxafkvx1(NI32 size_3){
  seq_0_Ivkh6l1_linxafkvx1 result_21;
  if (size_3 == 0){
    result_21 = (seq_0_Ivkh6l1_linxafkvx1){
      .len_0 = size_3, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Imnzl86_linxafkvx1(size_3);
    void* X60Qx_27 = alloc_1_sysvq0asl(memSize_2);
    result_21 = (seq_0_Ivkh6l1_linxafkvx1){
      .len_0 = size_3, .data_0 = ((LineInfoUnpacked_0_linxafkvx1*)X60Qx_27)}
    ;
    if ((!(result_21.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_28 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_21.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_21;}
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
static inline seq_0_Iaza5ca1_buiyylk1h1 newSeqUninit_0_Ikst8ta1_buiyylk1h1(NI32 size_22){
  seq_0_Iaza5ca1_buiyylk1h1 result_48;
  if (size_22 == 0){
    result_48 = (seq_0_Iaza5ca1_buiyylk1h1){
      .len_0 = size_22, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_14 = memSizeInBytes_0_Igp775b_buiyylk1h1(size_22);
    void* X60Qx_201 = alloc_1_sysvq0asl(memSize_14);
    result_48 = (seq_0_Iaza5ca1_buiyylk1h1){
      .len_0 = size_22, .data_0 = ((NU32*)X60Qx_201)}
    ;
    if ((!(result_48.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_202 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_48.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_14);}}
  return result_48;}
static inline seq_0_If70loa_intzsnzax newSeqUninit_0_Il1doiw_intzsnzax(NI32 size_158){
  seq_0_If70loa_intzsnzax result_501;
  if (size_158 == 0){
    result_501 = (seq_0_If70loa_intzsnzax){
      .len_0 = size_158, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_110 = memSizeInBytes_0_Ib1bjtc_intzsnzax(size_158);
    void* X60Qx_4636 = alloc_1_sysvq0asl(memSize_110);
    result_501 = (seq_0_If70loa_intzsnzax){
      .len_0 = size_158, .data_0 = ((NU32*)X60Qx_4636)}
    ;
    if ((!(result_501.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_4637 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_501.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_110);}}
  return result_501;}
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
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_34.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_12);}}
  return result_34;}
static inline seq_0_Iotb7mc_ast8ri79k newSeqUninit_0_I7whkjh1_ast8ri79k(NI32 size_22){
  seq_0_Iotb7mc_ast8ri79k result_35;
  if (size_22 == 0){
    result_35 = (seq_0_Iotb7mc_ast8ri79k){
      .len_0 = size_22, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_13 = memSizeInBytes_0_Iqj0wsf_ast8ri79k(size_22);
    void* X60Qx_117 = alloc_1_sysvq0asl(memSize_13);
    result_35 = (seq_0_Iotb7mc_ast8ri79k){
      .len_0 = size_22, .data_0 = ((NI64*)X60Qx_117)}
    ;
    if ((!(result_35.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_118 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_35.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_13);}}
  return result_35;}
static inline seq_0_Iwy7s2o_ast8ri79k newSeqUninit_0_Isaraw1_ast8ri79k(NI32 size_24){
  seq_0_Iwy7s2o_ast8ri79k result_38;
  if (size_24 == 0){
    result_38 = (seq_0_Iwy7s2o_ast8ri79k){
      .len_0 = size_24, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_14 = memSizeInBytes_0_I4sctiu_ast8ri79k(size_24);
    void* X60Qx_120 = alloc_1_sysvq0asl(memSize_14);
    result_38 = (seq_0_Iwy7s2o_ast8ri79k){
      .len_0 = size_24, .data_0 = ((NU32*)X60Qx_120)}
    ;
    if ((!(result_38.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_121 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_38.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_14);}}
  return result_38;}
static inline seq_0_Ijmiee61_ast8ri79k newSeqUninit_0_Igtmzv6_ast8ri79k(NI32 size_26){
  seq_0_Ijmiee61_ast8ri79k result_41;
  if (size_26 == 0){
    result_41 = (seq_0_Ijmiee61_ast8ri79k){
      .len_0 = size_26, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_15 = memSizeInBytes_0_Iom723i1_ast8ri79k(size_26);
    void* X60Qx_123 = alloc_1_sysvq0asl(memSize_15);
    result_41 = (seq_0_Ijmiee61_ast8ri79k){
      .len_0 = size_26, .data_0 = ((NU64*)X60Qx_123)}
    ;
    if ((!(result_41.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_124 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_41.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_15);}}
  return result_41;}
static inline seq_0_Ipw48je1_ast8ri79k newSeqUninit_0_I8tb1fi1_ast8ri79k(NI32 size_28){
  seq_0_Ipw48je1_ast8ri79k result_44;
  if (size_28 == 0){
    result_44 = (seq_0_Ipw48je1_ast8ri79k){
      .len_0 = size_28, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_16 = memSizeInBytes_0_Itq6t0c1_ast8ri79k(size_28);
    void* X60Qx_126 = alloc_1_sysvq0asl(memSize_16);
    result_44 = (seq_0_Ipw48je1_ast8ri79k){
      .len_0 = size_28, .data_0 = ((NU32*)X60Qx_126)}
    ;
    if ((!(result_44.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_127 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_44.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_16);}}
  return result_44;}
static inline seq_0_Isoawlw1_ast8ri79k newSeqUninit_0_Ivz95ii_ast8ri79k(NI32 size_30){
  seq_0_Isoawlw1_ast8ri79k result_47;
  if (size_30 == 0){
    result_47 = (seq_0_Isoawlw1_ast8ri79k){
      .len_0 = size_30, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_17 = memSizeInBytes_0_Iidgqw2_ast8ri79k(size_30);
    void* X60Qx_129 = alloc_1_sysvq0asl(memSize_17);
    result_47 = (seq_0_Isoawlw1_ast8ri79k){
      .len_0 = size_30, .data_0 = ((NU32*)X60Qx_129)}
    ;
    if ((!(result_47.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_130 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_47.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_17);}}
  return result_47;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline seq_0_Io4pvgy1_nifb6mq6y1 newSeqUninit_0_Ijkckzz_nifb6mq6y1(NI32 size_48){
  seq_0_Io4pvgy1_nifb6mq6y1 result_141;
  if (size_48 == 0){
    result_141 = (seq_0_Io4pvgy1_nifb6mq6y1){
      .len_0 = size_48, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_33 = memSizeInBytes_0_Isupifd_nifb6mq6y1(size_48);
    void* X60Qx_382 = alloc_1_sysvq0asl(memSize_33);
    result_141 = (seq_0_Io4pvgy1_nifb6mq6y1){
      .len_0 = size_48, .data_0 = ((NU32*)X60Qx_382)}
    ;
    if ((!(result_141.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_383 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_141.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_33);}}
  return result_141;}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NU32 getOrIncl_1_Ijmj1s_explnj22x1(BiTable_0_Iojfwmy1_ast8ri79k* t_26, NF64 v_8){
  NU32 result_48;
  NU64 X60Qx_1406;
  copyMem_0_sysvq0asl((&X60Qx_1406), (&v_8), sizeof(NU64));
  NU32 X60Qx_1407 = getOrIncl_0_Ivbdpqo_explnj22x1(t_26, X60Qx_1406);
  result_48 = X60Qx_1407;
  return result_48;}
static inline NB8 isValid_1_linxafkvx1(NU32 x_1){
  NB8 result_5;
  NB8 X60Qx_5 = eqQ_0_linxafkvx1(x_1, NoFile_0_linxafkvx1);
  result_5 = (!X60Qx_5);
  return result_5;}
static inline NB8 isValid_0_linxafkvx1(NU32 x_0){
  NB8 result_4;
  result_4 = (!(((NU32)x_0) == ((NU32)NoLineInfo_0_linxafkvx1)));
  return result_4;}
static inline NB8 eqQ_0_linxafkvx1(NU32 a_0, NU32 b_0){
  NB8 result_0;
  result_0 = (a_0 == b_0);
  return result_0;}
static inline string_0_sysvq0asl* getQ_0_Io78pjy1_intzsnzax(BiTable_0_Ieutpr21_intzsnzax t_41, NU32 litId_8){
  string_0_sysvq0asl* result_174;
  NI32 idx_10 = ((NI32)(((NI32)litId_8) - ((NI32)1)));
  if ((!(idx_10 < t_41.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  string_0_sysvq0asl* X60Qx_3711 = getQ_7_Ir6d0tw_aow7lb5cq1(t_41.vals_0, idx_10);
  result_174 = X60Qx_3711;
  return result_174;}
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
  string_0_sysvq0asl* X60Qx_31 = getQ_7_Ir6d0tw_aow7lb5cq1(t_6.vals_0, idx_0);
  result_3 = X60Qx_31;
  return result_3;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline NI32 len_6_I4emj7h_nifb6mq6y1(openArray_0_I0m47e11_nifb6mq6y1 a_4){
  NI32 result_53;
  result_53 = a_4.len_0;
  return result_53;}
static inline PackedToken_0_nifh7u8pu1* getQ_10_Iids335_nifb6mq6y1(openArray_0_I0m47e11_nifb6mq6y1 x_8, NI32 idx_1){
  NB8 X60Qx_141;
  if (0 <= idx_1){
    X60Qx_141 = (idx_1 < x_8.len_0);}
  else {
    X60Qx_141 = NIM_FALSE;}
  if ((!X60Qx_141)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_aow7lb5cq1)}
    );}
  PackedToken_0_nifh7u8pu1* result_52;
  result_52 = (&x_8.a_0[idx_1]);
  return result_52;}
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
static inline NU64* getQ_0_Iebom0i1_ast8ri79k(BiTable_0_Itxao711_ast8ri79k t_8, NU32 litId_7){
  NU64* result_5;
  NI32 idx_2 = ((NI32)(((NI32)litId_7) - ((NI32)1)));
  if ((!(idx_2 < t_8.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NU64* X60Qx_33 = getQ_7_Ifaxado1_ast8ri79k(t_8.vals_0, idx_2);
  result_5 = X60Qx_33;
  return result_5;}
static inline NF64 getQ_1_I4qx0py_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_9, NU32 litId_8){
  NF64 result_6;
  NU64* X60Qx_34 = getQ_0_I3qz68f_ast8ri79k(t_9, litId_8);
  NU64 X60Qx_35 = (*X60Qx_34);
  NF64 X60Qx_36;
  copyMem_0_sysvq0asl((&X60Qx_36), (&X60Qx_35), sizeof(NF64));
  result_6 = X60Qx_36;
  return result_6;}
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
static inline NI32 capInBytes_0_Id76iiw1_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1 s_171){
  NI32 result_142;
  NI32 X60Qx_14;
  if ((!(s_171.data_0 == NIM_NIL))){
    NI32 X60Qx_384 = allocatedSize_0_sysvq0asl(((void*)((void*)s_171.data_0)));
    X60Qx_14 = X60Qx_384;}
  else {
    X60Qx_14 = 0;}
  result_142 = X60Qx_14;
  return result_142;}
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
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline NU32 nextTry_0_bitekkhcx1(NU32 h_0, NU32 maxHash_0){
  NU32 result_0;
  result_0 = ((NU32)(((NU32)(h_0 + ((NU32)1))) & maxHash_0));
  return result_0;}
static inline NB8 mustRehash_0_bitekkhcx1(NI32 length_0, NI32 counter_0){
  NB8 result_1;
  if ((!(counter_0 < length_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NB8 X60Qx_0;
  if (length_0 < ((NI32)(((NI32)(counter_0 / 2)) + counter_0))){
    X60Qx_0 = NIM_TRUE;}
  else {
    X60Qx_0 = (((NI32)(length_0 - counter_0)) < 4);}
  result_1 = X60Qx_0;
  return result_1;}
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
static inline NU32 hash_0_strdllfw2(StringView_0_strdllfw2 a_2){
  NU32 result_5;
  string_0_sysvq0asl X60Qtmp_0 = borrowCStringUnsafe_0_sysvq0asl(((NC8*)a_2.p_0), a_2.len_0);
  NU32 X60Qx_9 = hash_1_has9tn57v(X60Qtmp_0);
  result_5 = X60Qx_9;
  nimStrDestroy(X60Qtmp_0);
  return result_5;
  nimStrDestroy(X60Qtmp_0);
  return result_5;}
static inline NI32 high_3_Ib20i801_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_16){
  NI32 result_7;
  result_7 = ((NI32)(s_16.len_0 - 1));
  return result_7;}
static inline NU32* getQ_8_I1lkkvo_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_17, NU32 i_8){
  if ((!(i_8 < ((NU32)s_17.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  NU32* result_8;
  result_8 = (&s_17.data_0[((NI32)i_8)]);
  return result_8;}
static inline void putQ_8_Iltefhx_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_25, NU32 i_13, NU32 elem_5){
  if ((!(i_13 < ((NU32)(*s_25).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_25).data_0[((NI32)i_13)] = elem_5;}
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
static inline NI32 memSizeInBytes_0_Isupifd_nifb6mq6y1(NI32 size_49){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_143;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_49, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_143 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_143 = ((NI32)2147483647);}
  return result_143;}
static inline void eQwasMoved_1_Idi7njb_intzsnzax(seq_0_If70loa_intzsnzax* s_546){
  (*s_546).len_0 = 0;
  (*s_546).data_0 = NIM_NIL;}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline NI32 capInBytes_0_Iryrob_intzsnzax(seq_0_If70loa_intzsnzax s_572){
  NI32 result_502;
  NI32 X60Qx_133;
  if ((!(s_572.data_0 == NIM_NIL))){
    NI32 X60Qx_4638 = allocatedSize_0_sysvq0asl(((void*)((void*)s_572.data_0)));
    X60Qx_133 = X60Qx_4638;}
  else {
    X60Qx_133 = 0;}
  result_502 = X60Qx_133;
  return result_502;}
static inline NI32 memSizeInBytes_0_Ib1bjtc_intzsnzax(NI32 size_159){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_503;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_159, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_503 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_503 = ((NI32)2147483647);}
  return result_503;}
static inline void eQwasMoved_1_Igz5mgz_nifb6mq6y1(seq_0_Io4pvgy1_nifb6mq6y1* s_169){
  (*s_169).len_0 = 0;
  (*s_169).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93){
  (*s_93).len_0 = 0;
  (*s_93).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_Iew8iz1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_85){
  (*s_85).len_0 = 0;
  (*s_85).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82){
  (*s_82).len_0 = 0;
  (*s_82).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I94uyip1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_49){
  (*s_49).len_0 = 0;
  (*s_49).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_Ia0kll01_ast8ri79k(seq_0_Iotb7mc_ast8ri79k* s_51){
  (*s_51).len_0 = 0;
  (*s_51).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I5re2ul_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I6m9e8j_ast8ri79k(seq_0_Ijmiee61_ast8ri79k* s_57){
  (*s_57).len_0 = 0;
  (*s_57).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I52bdqo1_ast8ri79k(seq_0_Ipw48je1_ast8ri79k* s_60){
  (*s_60).len_0 = 0;
  (*s_60).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I5y4iq9_ast8ri79k(seq_0_Isoawlw1_ast8ri79k* s_63){
  (*s_63).len_0 = 0;
  (*s_63).data_0 = NIM_NIL;}
static inline NI32 memSizeInBytes_0_Imnzl86_linxafkvx1(NI32 size_1){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_19;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_1, sizeof(LineInfoUnpacked_0_linxafkvx1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_19 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_19 = ((NI32)2147483647);}
  return result_19;}
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
static inline NI32 memSizeInBytes_0_Igp775b_buiyylk1h1(NI32 size_13){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_39;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_13, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_39 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_39 = ((NI32)2147483647);}
  return result_39;}
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
static inline NI32 memSizeInBytes_0_Iqj0wsf_ast8ri79k(NI32 size_23){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_37;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_23, sizeof(NI64), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_37 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_37 = ((NI32)2147483647);}
  return result_37;}
static inline NI32 memSizeInBytes_0_I4sctiu_ast8ri79k(NI32 size_25){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_40;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_25, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_40 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_40 = ((NI32)2147483647);}
  return result_40;}
static inline NI32 memSizeInBytes_0_Iom723i1_ast8ri79k(NI32 size_27){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_43;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_27, sizeof(NU64), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_43 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_43 = ((NI32)2147483647);}
  return result_43;}
static inline NI32 memSizeInBytes_0_Itq6t0c1_ast8ri79k(NI32 size_29){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_46;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_29, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_46 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_46 = ((NI32)2147483647);}
  return result_46;}
static inline NI32 memSizeInBytes_0_Iidgqw2_ast8ri79k(NI32 size_31){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_49;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_31, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_49 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_49 = ((NI32)2147483647);}
  return result_49;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline NU64* getQ_7_Ifaxado1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_10, NI32 i_7){
  NB8 X60Qx_54;
  if (i_7 < s_10.len_0){
    X60Qx_54 = (0 <= i_7);}
  else {
    X60Qx_54 = NIM_FALSE;}
  if ((!X60Qx_54)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU64* result_11;
  result_11 = (&s_10.data_0[i_7]);
  return result_11;}
static inline NU64* getQ_0_I3qz68f_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_14, NU32 litId_13){
  NU64* result_12;
  NI32 idx_4 = ((NI32)(((NI32)litId_13) - ((NI32)1)));
  if ((!(idx_4 < t_14.vals_0.len_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  NU64* X60Qx_55 = getQ_7_Ifaxado1_ast8ri79k(t_14.vals_0, idx_4);
  result_12 = X60Qx_55;
  return result_12;}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
