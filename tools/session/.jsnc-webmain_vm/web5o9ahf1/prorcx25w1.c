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
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21 X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct ToplevelEntry_0_prorcx25w1 ToplevelEntry_0_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1 X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1 X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX49mportX46ilter0prorcx25w1_prorcx25w1 X60Qt_0_IAtupleSstring0sysvq0aslSX49mportX46ilter0prorcx25w1_prorcx25w1;
typedef struct NifIndexEntry_0_nifa1znj21 NifIndexEntry_0_nifa1znj21;
typedef struct X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
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
typedef struct NifModule_Obj_0_prorcx25w1{
  Stream_0_nifh7u8pu1 stream_0;
  NifIndex_0_nifa1znj21 index_0;
  Table_0_Iyfwn301_nifa1znj21 public_0;
  Table_0_Iyfwn301_nifa1znj21 private_0;}
NifModule_Obj_0_prorcx25w1;
typedef NU8 SemPhase_0_prorcx25w1;

#define SemcheckTopLevelSyms_0_prorcx25w1 ((NU8)0)
#define SemcheckSignaturesInProgress_0_prorcx25w1 ((NU8)1)
#define SemcheckSignatures_0_prorcx25w1 ((NU8)2)
#define SemcheckBodiesInProgress_0_prorcx25w1 ((NU8)3)
#define SemcheckBodies_0_prorcx25w1 ((NU8)4)
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef struct ToplevelEntry_0_prorcx25w1{
  TokenBuf_0_nifb6mq6y1 buffer_0;
  SemPhase_0_prorcx25w1 phase_0;}
ToplevelEntry_0_prorcx25w1;
typedef struct seq_0_Ikxamj_prorcx25w1{
  NI32 len_0;
  ToplevelEntry_0_prorcx25w1* data_0;}
seq_0_Ikxamj_prorcx25w1;
typedef struct seq_0_I8hny96_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1* data_0;}
seq_0_I8hny96_prorcx25w1;
typedef struct Table_0_Idzo7511_prorcx25w1{
  seq_0_I8hny96_prorcx25w1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Idzo7511_prorcx25w1;
typedef struct ToplevelEntries_0_prorcx25w1{
  seq_0_Ikxamj_prorcx25w1 entries_0;
  Table_0_Idzo7511_prorcx25w1 bySymId_0;}
ToplevelEntries_0_prorcx25w1;
typedef struct seq_0_I7dew2c_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* data_0;}
seq_0_I7dew2c_prorcx25w1;
typedef struct Table_0_Ij858uv_prorcx25w1{
  seq_0_I7dew2c_prorcx25w1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Ij858uv_prorcx25w1;
typedef struct SplittedModulePath_0_symkyk35i1{
  string_0_sysvq0asl dir_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl ext_0;}
SplittedModulePath_0_symkyk35i1;
typedef struct Program_0_prorcx25w1{
  Table_0_Ij858uv_prorcx25w1 mods_0;
  SplittedModulePath_0_symkyk35i1 main_0;
  ToplevelEntries_0_prorcx25w1 mem_0;}
Program_0_prorcx25w1;
typedef NU8 ImportFilterKind_0_prorcx25w1;

#define ImportAll_0_prorcx25w1 ((NU8)0)
#define FromImport_0_prorcx25w1 ((NU8)1)
#define ImportExcept_0_prorcx25w1 ((NU8)2)
typedef struct seq_0_I0i3btg1_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1* data_0;}
seq_0_I0i3btg1_prorcx25w1;
typedef struct Table_0_Ik52dhu1_prorcx25w1{
  seq_0_I0i3btg1_prorcx25w1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_Ik52dhu1_prorcx25w1;
typedef struct HashSet_0_Ipcrj631_prorcx25w1{
  Table_0_Ik52dhu1_prorcx25w1 t_0;}
HashSet_0_Ipcrj631_prorcx25w1;
typedef struct ImportFilter_0_prorcx25w1{
  ImportFilterKind_0_prorcx25w1 kind_0;
  HashSet_0_Ipcrj631_prorcx25w1 list_0;}
ImportFilter_0_prorcx25w1;
typedef NU8 EnsurePhaseResult_0_prorcx25w1;

#define PhaseOk_0_prorcx25w1 ((NU8)0)
#define PhaseCycle_0_prorcx25w1 ((NU8)1)
#define PhaseNotFound_0_prorcx25w1 ((NU8)2)
typedef NU8 LoadStatus_0_prorcx25w1;

#define LacksModuleName_0_prorcx25w1 ((NU8)0)
#define LacksOffset_0_prorcx25w1 ((NU8)1)
#define LacksPosition_0_prorcx25w1 ((NU8)2)
#define LacksNothing_0_prorcx25w1 ((NU8)3)
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct LoadResult_0_prorcx25w1{
  LoadStatus_0_prorcx25w1 status_0;
  Cursor_0_nifb6mq6y1 decl_0;}
LoadResult_0_prorcx25w1;
typedef NU8 AttachedOp_0_prorcx25w1;

#define attachedDestroy_0_prorcx25w1 ((NU8)0)
#define attachedWasMoved_0_prorcx25w1 ((NU8)1)
#define attachedDup_0_prorcx25w1 ((NU8)2)
#define attachedCopy_0_prorcx25w1 ((NU8)3)
#define attachedSink_0_prorcx25w1 ((NU8)4)
#define attachedTrace_0_prorcx25w1 ((NU8)5)
typedef struct X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S6_prorcx25w1{
  NU32 a[6];}
X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S6_prorcx25w1;
typedef struct HooksPerType_0_prorcx25w1{
  X60Qt_0_IAarraySX53ymX49d0nifh7u8pu1S6_prorcx25w1 a_0;}
HooksPerType_0_prorcx25w1;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct seq_0_Izphk88_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1* data_0;}
seq_0_Izphk88_prorcx25w1;
typedef struct Table_0_I4dbdda_prorcx25w1{
  seq_0_Izphk88_prorcx25w1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_I4dbdda_prorcx25w1;
typedef struct openArray_0_Ig73pnk_comaa5xpt1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_comaa5xpt1;
typedef struct seq_0_Idyps081_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1* data_0;}
seq_0_Idyps081_prorcx25w1;
typedef struct Table_0_I2pi31q1_prorcx25w1{
  seq_0_Idyps081_prorcx25w1 data_0;
  seq_0_Ikxuplm1_filqx2b6r1 hashes_0;}
Table_0_I2pi31q1_prorcx25w1;
typedef struct seq_0_Iarn3qg1_prorcx25w1{
  NI32 len_0;
  X60Qt_0_IAtupleSstring0sysvq0aslSX49mportX46ilter0prorcx25w1_prorcx25w1* data_0;}
seq_0_Iarn3qg1_prorcx25w1;
typedef struct openArray_0_Iq84i8o_prorcx25w1{
  ToplevelEntry_0_prorcx25w1* a_0;
  NI32 len_0;}
openArray_0_Iq84i8o_prorcx25w1;
typedef struct openArray_0_Ihfaw761_prorcx25w1{
  X60Qt_0_IAtupleSstring0sysvq0aslSR6_nifa1znj21* a_0;
  NI32 len_0;}
openArray_0_Ihfaw761_prorcx25w1;
typedef struct openArray_0_Ir53qdx_comaa5xpt1{
  NU32* a_0;
  NI32 len_0;}
openArray_0_Ir53qdx_comaa5xpt1;
typedef struct openArray_0_Ik6y8he1_prorcx25w1{
  X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX4bind0nif12fhfr1Sseq0X49zov3yo_nifa1znj21* a_0;
  NI32 len_0;}
openArray_0_Ik6y8he1_prorcx25w1;
typedef struct openArray_0_Imjppfb_ide5ljwgh1{
  NU32* a_0;
  NI32 len_0;}
openArray_0_Imjppfb_ide5ljwgh1;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_Izov3yo_ast8ri79k keys_0;}
BiTable_0_Ipgo74p_ast8ri79k;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_In6doa_ast8ri79k keys_0;}
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
typedef struct X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1{
  NI r_00;
  NifModule_Obj_0_prorcx25w1 d_00;}
X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
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
typedef struct X60Qt_0_IAtupleAlentSstring0sysvq0aslZAR6SX4eifX49ndexX45ntry0nifa1znj21_prorcx25w1{
  string_0_sysvq0asl* fld_0;
  NifIndexEntry_0_nifa1znj21* fld_1;}
X60Qt_0_IAtupleAlentSstring0sysvq0aslZAR6SX4eifX49ndexX45ntry0nifa1znj21_prorcx25w1;
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
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1{
  ErrorCode_0_sysvq0asl fld_0;
  NI64 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_hos1fpv3m1;
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
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslSX49mportX46ilter0prorcx25w1_prorcx25w1{
  string_0_sysvq0asl fld_0;
  ImportFilter_0_prorcx25w1 fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslSX49mportX46ilter0prorcx25w1_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1{
  ErrorCode_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_filqx2b6r1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1{
  NU32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1;
typedef struct X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1{
  string_0_sysvq0asl fld_0;
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* fld_1;}
X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1{
  NU32 fld_0;
  NB8 fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Abool_prorcx25w1;
typedef struct X60Qt_0_IAtupleAlentSX53trX49d0nifh7u8pu1ZAR6Abool_prorcx25w1{
  NU32* fld_0;
  NB8* fld_1;}
X60Qt_0_IAtupleAlentSX53trX49d0nifh7u8pu1ZAR6Abool_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1{
  NU32 fld_0;
  seq_0_In6doa_ast8ri79k fld_1;}
X60Qt_0_IAtupleSX53trX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef struct X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1{
  NU32 fld_0;
  seq_0_In6doa_ast8ri79k fld_1;}
X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1Sseq0X49n6doa_prorcx25w1;
typedef NU8 DirectivesResult_0_nif81dubp1;

#define WrongHeader_0_nif81dubp1 ((NU8)0)
#define WrongMeta_0_nif81dubp1 ((NU8)1)
#define Success_0_nif81dubp1 ((NU8)2)
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
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
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
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
static inline NI32 len_3_Inv614o_prorcx25w1(seq_0_Ikxamj_prorcx25w1 s_32);
static inline NB8 hasKey_0_Ihimb3m1_prorcx25w1(Table_0_Idzo7511_prorcx25w1 t_35, NU32 k_22);
static inline ToplevelEntry_0_prorcx25w1* getQ_7_Ibc9d7t1_prorcx25w1(seq_0_Ikxamj_prorcx25w1 s_34, NI32 i_6);
NI32 getOrDefault_0_Ia2ap27_prorcx25w1(Table_0_Idzo7511_prorcx25w1 t_39, NU32 k_26);
static inline void putQ_7_In0g3y61_prorcx25w1(seq_0_Ikxamj_prorcx25w1* s_35, NI32 i_7, ToplevelEntry_0_prorcx25w1 elem_5);
static inline void add_0_I1w6azk1_prorcx25w1(seq_0_Ikxamj_prorcx25w1* s_36, ToplevelEntry_0_prorcx25w1 elem_6);
void putQ_0_Ioui0yi_prorcx25w1(Table_0_Idzo7511_prorcx25w1* t_40, NU32 k_27, NI32 v_10);
void putQ_0_Ixpvfkm_prorcx25w1(Table_0_Ij858uv_prorcx25w1* t_48, string_0_sysvq0asl k_33, X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* v_14);
static inline NB8 hasKey_0_Ihi6ll91_prorcx25w1(Table_0_Ij858uv_prorcx25w1 t_51, string_0_sysvq0asl k_36);
static inline NI32 len_0_Ickzzw8_prorcx25w1(Table_0_Iyfwn301_nifa1znj21 t_53);
X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* getOrDefault_0_Ibv556r_prorcx25w1(Table_0_Ij858uv_prorcx25w1 t_54, string_0_sysvq0asl k_38);
NifIndexEntry_0_nifa1znj21 getOrDefault_0_Impbwl31_prorcx25w1(Table_0_Iyfwn301_nifa1znj21 t_71, string_0_sysvq0asl k_49);
static inline NB8 contains_0_Ix54wnr1_prorcx25w1(Table_0_Idzo7511_prorcx25w1 t_74, NU32 k_50);
NI32 rawGet_0_I1waarx1_prorcx25w1(Table_0_Idzo7511_prorcx25w1 t_75, NU32 k_51, NU32 kh_5);
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1* getQ_7_Ib1kjrf1_prorcx25w1(seq_0_I8hny96_prorcx25w1 s_92, NI32 i_37);
static inline NI32 capInBytes_0_Iondjzw_prorcx25w1(seq_0_Ikxamj_prorcx25w1 s_93);
NB8 resize_0_I59ha4h1_prorcx25w1(seq_0_Ikxamj_prorcx25w1* dest_6, NI32 addedElements_3);
void rawPut_0_I4mfs8l1_prorcx25w1(Table_0_Idzo7511_prorcx25w1* t_76, NU32 k_52, NI32 v_24, NU32 h_14);
static inline NI32 len_3_Iznbp3e_prorcx25w1(seq_0_I8hny96_prorcx25w1 s_96);
NI32 rawGet_0_Igxgdwo1_prorcx25w1(Table_0_Ij858uv_prorcx25w1 t_81, string_0_sysvq0asl k_55, NU32 kh_7);
static inline X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* getQ_7_Iu68xw61_prorcx25w1(seq_0_I7dew2c_prorcx25w1 s_108, NI32 i_47);
void rawPut_0_Ilrji3k_prorcx25w1(Table_0_Ij858uv_prorcx25w1* t_82, string_0_sysvq0asl k_56, X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* v_26, NU32 h_18);
static inline NB8 contains_0_I0bsn0y1_prorcx25w1(Table_0_Ij858uv_prorcx25w1 t_84, string_0_sysvq0asl k_57);
static inline NI32 memSizeInBytes_0_I7gtjtc_prorcx25w1(NI32 size_28);
void fillHashPart_0_Iogtr6v_prorcx25w1(Table_0_Idzo7511_prorcx25w1* t_99);
static inline void add_0_I2lrufu1_prorcx25w1(seq_0_I8hny96_prorcx25w1* s_159, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1 elem_31);
static inline NI32 len_3_I9e1ja3_prorcx25w1(seq_0_I7dew2c_prorcx25w1 s_163);
void fillHashPart_0_Ivt0bgj1_prorcx25w1(Table_0_Ij858uv_prorcx25w1* t_101);
static inline void add_0_Injpqso_prorcx25w1(seq_0_I7dew2c_prorcx25w1* s_164, X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 elem_33);
static inline NI32 capInBytes_0_Izl8skj_prorcx25w1(seq_0_I8hny96_prorcx25w1 s_191);
NB8 resize_0_Iaw0j0a1_prorcx25w1(seq_0_I8hny96_prorcx25w1* dest_20, NI32 addedElements_17);
static inline NI32 capInBytes_0_Ib1s9hw1_prorcx25w1(seq_0_I7dew2c_prorcx25w1 s_193);
NB8 resize_0_Ioofely_prorcx25w1(seq_0_I7dew2c_prorcx25w1* dest_22, NI32 addedElements_19);
static inline NI32 memSizeInBytes_0_Iksokhb1_prorcx25w1(NI32 size_47);
static inline NI32 memSizeInBytes_0_Iojhvkv_prorcx25w1(NI32 size_48);
void eQdestroyQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1(ToplevelEntry_0_prorcx25w1 dest_0);
void eQwasmovedQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1(ToplevelEntry_0_prorcx25w1* dest_0);
void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
void eQwasmovedQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1* dest_0);
void eQdestroyQ_SX54able0X49yfwn301_0_prorcx25w1(Table_0_Iyfwn301_nifa1znj21 dest_0);
void eQwasmovedQ_SX54able0X49dzo7511_0_prorcx25w1(Table_0_Idzo7511_prorcx25w1* dest_0);
void eQwasmovedQ_SX54able0X49j858uv_0_prorcx25w1(Table_0_Ij858uv_prorcx25w1* dest_0);
void eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* dest_0);
void eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1** dest_0);
X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* eQdupQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* src_0);
void eQdestroyQ_AtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 dest_0);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
extern Stream_0_nifh7u8pu1 open_0_nifh7u8pu1(string_0_sysvq0asl filename_0);
static inline seq_0_Ilvi9zw_nifa1znj21 newSeqUninit_0_Ihdba9y1_nifa1znj21(NI32 size_6);
static inline seq_0_Imzz798_nifa1znj21 newSeqUninit_0_I29q3sg_nifa1znj21(NI32 size_8);
extern Table_0_Iyfwn301_nifa1znj21 initTable_0_Igzeek4_nifa1znj21(void);
extern DirectivesResult_0_nif81dubp1 processDirectives_0_nif81dubp1(Reader_0_nif81dubp1* r_11);
static inline NI32 len_3_Ikddlyh1_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_58);
static inline X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* getQ_7_I1m5sw7_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_47, NI32 i_16);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void putQ_0_Iaeqq6y_nifa1znj21(Table_0_Iyfwn301_nifa1znj21* t_15, string_0_sysvq0asl k_2, NifIndexEntry_0_nifa1znj21 v_3);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern LongString_0_sysvq0asl const strlit_0_I11901799661097360525_modzy18mg1;
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern LongString_0_sysvq0asl const strlit_0_I5065733472155119234_comaa5xpt1;
static inline string_0_sysvq0asl slashQ_0_ospaexnw61(string_0_sysvq0asl head_1, string_0_sysvq0asl tail_2);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern LongString_0_sysvq0asl const strlit_0_I4912791914873646233_modzy18mg1;
extern LongString_0_sysvq0asl const strlit_0_I16810923556642427947_modzy18mg1;
extern void eQdestroyQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21(NifIndex_0_nifa1znj21 dest_0);
extern Table_0_Iyfwn301_nifa1znj21 readEmbeddedIndex_0_nifa1znj21(Stream_0_nifh7u8pu1* s_2);
extern string_0_sysvq0asl changeModuleExt_0_symkyk35i1(string_0_sysvq0asl s_11, string_0_sysvq0asl ext_0);
extern NifIndex_0_nifa1znj21 readIndex_0_nifa1znj21(string_0_sysvq0asl indexName_0);
static inline Cursor_0_nifb6mq6y1 cursorAt_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_11, NI32 i_2);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
extern string_0_sysvq0asl extractModule_0_symkyk35i1(string_0_sysvq0asl s_2);
static inline void jumpTo_0_nif81dubp1(Reader_0_nif81dubp1* r_14, NI32 offset_0);
extern TokenBuf_0_nifb6mq6y1 createTokenBuf_0_nifb6mq6y1(NI32 cap_1);
extern void parse_0_nifb6mq6y1(Stream_0_nifh7u8pu1* r_0, TokenBuf_0_nifb6mq6y1* dest_27, NU32 parentInfo_0, NB8 debug_0);
static inline void eQwasMoved_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_2);
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3);
extern NU32 getOrIncl_0_Inyo00c_buiyylk1h1(BiTable_0_I0ksat5_ast8ri79k* t_5, string_0_sysvq0asl v_4);
extern LongString_0_sysvq0asl const strlit_0_I10459095262102366334_buiyylk1h1;
extern NU32 getOrIncl_0_Ix6biej1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k* t_11, string_0_sysvq0asl v_1);
extern LongString_0_sysvq0asl const strlit_0_I4783242303970288541_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I18083737681243856668_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I9664704115936008796_buiyylk1h1;
static inline PackedToken_0_nifh7u8pu1 parLeTokenUnchecked_0_nifb6mq6y1(string_0_sysvq0asl tag_3, NU32 info_14);
extern LongString_0_sysvq0asl const strlit_0_I13413619771642637377_comaa5xpt1;
extern NU32 const NoLineInfo_0_linxafkvx1;
static inline void add_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_7, PackedToken_0_nifh7u8pu1 item_1);
static inline PackedToken_0_nifh7u8pu1 symdefToken_0_nifh7u8pu1(NU32 s_2, NU32 info_8);
static inline PackedToken_0_nifh7u8pu1 identToken_0_nifh7u8pu1(NU32 s_0, NU32 info_5);
extern void addDotToken_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_14);
extern LongString_0_sysvq0asl const strlit_0_I973692718279674627_comaa5xpt1;
extern NU32 getOrIncl_0_I4rntkc_buiyylk1h1(BiTable_0_Itvq7bk_ast8ri79k* t_7, NI64 v_5);
static inline PackedToken_0_nifh7u8pu1 intToken_0_nifh7u8pu1(NU32 id_2, NU32 info_11);
extern void addParRi_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_11);
static inline PackedToken_0_nifh7u8pu1 symToken_0_nifh7u8pu1(NU32 s_1, NU32 info_6);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0);
extern LongString_0_sysvq0asl const strlit_0_I767816010166080526_comaa5xpt1;
extern NU32 hash_1_has9tn57v(string_0_sysvq0asl s_0);
extern NI32 rawGet_0_Ilpzx5l1_nifa1znj21(Table_0_Iyfwn301_nifa1znj21 t_19, string_0_sysvq0asl k_5, NU32 kh_1);
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
static inline NI32 high_3_Iyuup9h1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_17);
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_18, NU32 i_9);
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2);
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 len_3_Iiefpcc1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_19);
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0);
extern void resize_0_tabcr240b1(seq_0_Ikxuplm1_filqx2b6r1* t_0);
static inline void putQ_8_Ipchg2a_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_22, NU32 i_11, HashEntry_0_tabcr240b1 elem_5);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
extern void eQdestroy_1_I5skmro_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1 s_34);
extern seq_0_Ikxuplm1_filqx2b6r1 newSeq_0_Iv3lu2h1_filqx2b6r1(NI32 size_5);
extern void eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1(Stream_0_nifh7u8pu1* dest_0);
extern void eQwasmovedQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1(SplittedModulePath_0_symkyk35i1* dest_0);
extern void eQdestroy_1_Ixsq1x81_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_98);
static inline void eQwasMoved_1_I8aeezd1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_35);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_has9tn57v(void);
extern void X60Qini_0_tabcr240b1(void);
extern void X60Qini_0_set37vj3r(void);
extern void X60Qini_0_bitekkhcx1(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_nifjp9lau1(void);
extern void X60Qini_0_nifa1znj21(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_modjbswg91(void);
extern void X60Qini_0_repa2y0od1(void);
extern void X60Qini_0_buiyylk1h1(void);
extern void X60Qini_0_decqocs071(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_symiqlwtg1(void);
extern void X60Qini_0_ide5ljwgh1(void);
extern void X60Qini_0_nif12fhfr1(void);
static inline NI32 memSizeInBytes_0_Iwy52zt1_nifa1znj21(NI32 size_15);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
static inline NI32 memSizeInBytes_0_Iecjnu51_nifa1znj21(NI32 size_16);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern void dealloc_1_sysvq0asl(void* p_20);
extern LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l;
extern string_0_sysvq0asl joinPath_0_ospaexnw61(string_0_sysvq0asl head_0, string_0_sysvq0asl tail_1);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
extern void* alloc0_1_sysvq0asl(NI32 size_25);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5);
extern NU32 getOrIncl_0_Is83dq9_buiyylk1h1(BiTable_0_Icvz6lt_buiyylk1h1* t_3, string_0_sysvq0asl v_3);
static inline PackedToken_0_nifh7u8pu1 parLeToken_0_nifh7u8pu1(NU32 t_0, NU32 info_9);
static inline void prepareMutation_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_0);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iip05tk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_10, NU32 id_14, NU32 info_29);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ika21pk_nifh7u8pu1(NifKind_0_nif81dubp1 kind_9, NU32 id_13, NU32 info_28);
static inline PackedToken_0_nifh7u8pu1 toToken_0_Is7quwk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_13, NU32 id_17, NU32 info_32);
static inline NU32 hash_2_has9tn57v(NU32 u_0);
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iz0lv7d1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_12, NU32 id_16, NU32 info_31);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
Program_0_prorcx25w1 prog_0_prorcx25w1;
NB8 X60QiniGuard_0_prorcx25w1;
static inline NB8 hasKey_0_prorcx25w1(ToplevelEntries_0_prorcx25w1 t_1, NU32 s_0){
  NB8 result_3;
  NB8 X60Qx_32 = hasKey_0_Ihimb3m1_prorcx25w1(t_1.bySymId_0, s_0);
  result_3 = X60Qx_32;
  return result_3;}
static inline ToplevelEntry_0_prorcx25w1* getQ_0_prorcx25w1(ToplevelEntries_0_prorcx25w1 t_3, NU32 s_2){
  ToplevelEntry_0_prorcx25w1* result_5;
  NI32 X60Qx_34 = getOrDefault_0_Ia2ap27_prorcx25w1(t_3.bySymId_0, s_2);
  ToplevelEntry_0_prorcx25w1* X60Qx_35 = getQ_7_Ibc9d7t1_prorcx25w1(t_3.entries_0, X60Qx_34);
  result_5 = X60Qx_35;
  return result_5;}
void putQ_0_prorcx25w1(ToplevelEntries_0_prorcx25w1* t_4, NU32 s_3, ToplevelEntry_0_prorcx25w1 entry_0){
  NB8 X60Qx_36 = hasKey_0_Ihimb3m1_prorcx25w1((*t_4).bySymId_0, s_3);
  if (X60Qx_36){
    ToplevelEntry_0_prorcx25w1 X60Qtmp_0 = entry_0;
    eQwasmovedQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1((&entry_0));
    NI32 X60Qx_37 = getOrDefault_0_Ia2ap27_prorcx25w1((*t_4).bySymId_0, s_3);
    putQ_7_In0g3y61_prorcx25w1((&(*t_4).entries_0), X60Qx_37, X60Qtmp_0);}
  else {
    NI32 idx_0 = len_3_Inv614o_prorcx25w1((*t_4).entries_0);
    ToplevelEntry_0_prorcx25w1 X60Qtmp_1 = entry_0;
    eQwasmovedQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1((&entry_0));
    add_0_I1w6azk1_prorcx25w1((&(*t_4).entries_0), X60Qtmp_1);
    putQ_0_Ioui0yi_prorcx25w1((&(*t_4).bySymId_0), s_3, idx_0);}
  eQdestroyQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1(entry_0);}
X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* newNifModule_0_prorcx25w1(string_0_sysvq0asl infile_0){
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* result_8;
  eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((&result_8));
  eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(result_8);
  void* X60Qx_42 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1));
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qtmp_5 = ((X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1*)X60Qx_42);
  Stream_0_nifh7u8pu1 X60Qx_43 = open_0_nifh7u8pu1(infile_0);
  seq_0_Ilvi9zw_nifa1znj21 X60Qx_44 = newSeqUninit_0_Ihdba9y1_nifa1znj21(0);
  seq_0_Imzz798_nifa1znj21 X60Qx_45 = newSeqUninit_0_I29q3sg_nifa1znj21(0);
  Table_0_Iyfwn301_nifa1znj21 X60Qx_46 = initTable_0_Igzeek4_nifa1znj21();
  Table_0_Iyfwn301_nifa1znj21 X60Qx_47 = initTable_0_Igzeek4_nifa1znj21();
  (*X60Qtmp_5) = (X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1){
    .r_00 = 0, .d_00 = (NifModule_Obj_0_prorcx25w1){
      .stream_0 = X60Qx_43, .index_0 = (NifIndex_0_nifa1znj21){
        .converters_0 = X60Qx_44, .exports_0 = X60Qx_45}
      , .public_0 = X60Qx_46, .private_0 = X60Qx_47}}
  ;
  result_8 = X60Qtmp_5;
  DirectivesResult_0_nif81dubp1 X60Qx_48 = processDirectives_0_nif81dubp1((&(*result_8).d_00.stream_0.r_0));
  return result_8;}
void addEmbeddedIndex_0_prorcx25w1(Table_0_Iyfwn301_nifa1znj21* public_0, Table_0_Iyfwn301_nifa1znj21* private_0, Table_0_Iyfwn301_nifa1znj21 embedded_0){
  {
    Table_0_Iyfwn301_nifa1znj21 X60Qlf_0 = embedded_0;
    {
      NI32 X60Qlf_2 = 0;
      NI32 X60Qlf_3 = len_3_Ikddlyh1_nifa1znj21(X60Qlf_0.data_0);
      NI32 X60Qlf_4 = X60Qlf_2;
      {
        while (X60Qlf_4 < X60Qlf_3){
          {
            {
              X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* X60Qx_49 = getQ_7_I1m5sw7_nifa1znj21(X60Qlf_0.data_0, X60Qlf_4);
              X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* X60Qx_50 = getQ_7_I1m5sw7_nifa1znj21(X60Qlf_0.data_0, X60Qlf_4);
              X60Qt_0_IAtupleAlentSstring0sysvq0aslZAR6SX4eifX49ndexX45ntry0nifa1znj21_prorcx25w1 X60Qii_3 = (X60Qt_0_IAtupleAlentSstring0sysvq0aslZAR6SX4eifX49ndexX45ntry0nifa1znj21_prorcx25w1){
                .fld_0 = (&(*X60Qx_49).fld_0), .fld_1 = (&(*X60Qx_50).fld_1)}
              ;
              string_0_sysvq0asl* k_8 = X60Qii_3.fld_0;
              NifIndexEntry_0_nifa1znj21* v_1 = X60Qii_3.fld_1;
              if ((*v_1).vis_0 == 1){
                string_0_sysvq0asl X60Qx_51 = nimStrDup((*k_8));
                putQ_0_Iaeqq6y_nifa1znj21(public_0, X60Qx_51, (*v_1));}
              else {
                string_0_sysvq0asl X60Qx_52 = nimStrDup((*k_8));
                putQ_0_Iaeqq6y_nifa1znj21(private_0, X60Qx_52, (*v_1));}}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_4));}}
      whileStmtLabel_2: ;}
    forStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline string_0_sysvq0asl suffixToNif_0_prorcx25w1(string_0_sysvq0asl suffix_1){
  string_0_sysvq0asl result_11;
  nimStrWasMoved((&result_11));
  string_0_sysvq0asl X60Qx_1;
  nimStrWasMoved((&X60Qx_1));
  NB8 X60Qx_58 = eqQ_20_sysvq0asl(prog_0_prorcx25w1.main_0.ext_0, (string_0_sysvq0asl){
    .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
  );
  if (X60Qx_58){
    nimStrDestroy(X60Qx_1);
    X60Qx_1 = (string_0_sysvq0asl){
      .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
    ;}
  else {
    nimStrDestroy(X60Qx_1);
    X60Qx_1 = (string_0_sysvq0asl){
      .bytes_0 = 779300606u, .more_0 = (&strlit_0_I5065733472155119234_comaa5xpt1)}
    ;}
  string_0_sysvq0asl ext_1 = X60Qx_1;
  nimStrWasMoved((&X60Qx_1));
  nimStrDestroy(result_11);
  string_0_sysvq0asl X60Qtmp_9 = slashQ_0_ospaexnw61(prog_0_prorcx25w1.main_0.dir_0, suffix_1);
  string_0_sysvq0asl X60Qx_59 = ampQ_0_sysvq0asl(X60Qtmp_9, ext_1);
  result_11 = X60Qx_59;
  nimStrDestroy(X60Qtmp_9);
  nimStrDestroy(ext_1);
  nimStrDestroy(X60Qx_1);
  return result_11;
  nimStrDestroy(X60Qtmp_9);
  nimStrDestroy(ext_1);
  nimStrDestroy(X60Qx_1);
  return result_11;}
static inline string_0_sysvq0asl semIndexExt_0_prorcx25w1(void){
  string_0_sysvq0asl result_13;
  nimStrWasMoved((&result_13));
  string_0_sysvq0asl X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  NB8 X60Qx_61 = eqQ_20_sysvq0asl(prog_0_prorcx25w1.main_0.ext_0, (string_0_sysvq0asl){
    .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I11901799661097360525_modzy18mg1)}
  );
  if (X60Qx_61){
    nimStrDestroy(X60Qx_2);
    X60Qx_2 = (string_0_sysvq0asl){
      .bytes_0 = 1668493054u, .more_0 = (&strlit_0_I4912791914873646233_modzy18mg1)}
    ;}
  else {
    nimStrDestroy(X60Qx_2);
    X60Qx_2 = (string_0_sysvq0asl){
      .bytes_0 = 779300606u, .more_0 = (&strlit_0_I16810923556642427947_modzy18mg1)}
    ;}
  nimStrDestroy(result_13);
  result_13 = X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  nimStrDestroy(X60Qx_2);
  return result_13;
  nimStrDestroy(X60Qx_2);
  return result_13;}
X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* load_0_prorcx25w1(string_0_sysvq0asl suffix_3){
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* result_15;
  eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((&result_15));
  NB8 X60Qx_63 = hasKey_0_Ihi6ll91_prorcx25w1(prog_0_prorcx25w1.mods_0, suffix_3);
  if ((!X60Qx_63)){
    string_0_sysvq0asl infile_4 = suffixToNif_0_prorcx25w1(suffix_3);
    eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(result_15);
    X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_64 = newNifModule_0_prorcx25w1(infile_4);
    result_15 = X60Qx_64;
    NifIndex_0_nifa1znj21* X60Qlhs_11 = (&(*result_15).d_00.index_0);
    seq_0_Ilvi9zw_nifa1znj21 X60Qx_65 = newSeqUninit_0_Ihdba9y1_nifa1znj21(0);
    seq_0_Imzz798_nifa1znj21 X60Qx_66 = newSeqUninit_0_I29q3sg_nifa1znj21(0);
    NifIndex_0_nifa1znj21 X60Qlhs_12 = (NifIndex_0_nifa1znj21){
      .converters_0 = X60Qx_65, .exports_0 = X60Qx_66}
    ;
    eQdestroyQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21((*X60Qlhs_11));
    (*X60Qlhs_11) = X60Qlhs_12;
    Table_0_Iyfwn301_nifa1znj21 embedded_1 = readEmbeddedIndex_0_nifa1znj21((&(*result_15).d_00.stream_0));
    NI32 X60Qx_67 = len_0_Ickzzw8_prorcx25w1(embedded_1);
    if (0 < X60Qx_67){
      addEmbeddedIndex_0_prorcx25w1((&(*result_15).d_00.public_0), (&(*result_15).d_00.private_0), embedded_1);}
    string_0_sysvq0asl X60Qtmp_13 = semIndexExt_0_prorcx25w1();
    string_0_sysvq0asl indexName_0 = changeModuleExt_0_symkyk35i1(infile_4, X60Qtmp_13);
    NifIndex_0_nifa1znj21* X60Qlhs_14 = (&(*result_15).d_00.index_0);
    NifIndex_0_nifa1znj21 X60Qlhs_15 = readIndex_0_nifa1znj21(indexName_0);
    eQdestroyQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21((*X60Qlhs_14));
    (*X60Qlhs_14) = X60Qlhs_15;
    string_0_sysvq0asl X60Qx_68 = nimStrDup(suffix_3);
    X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_69 = eQdupQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(result_15);
    putQ_0_Ixpvfkm_prorcx25w1((&prog_0_prorcx25w1.mods_0), X60Qx_68, X60Qx_69);
    nimStrDestroy(indexName_0);
    nimStrDestroy(X60Qtmp_13);
    eQdestroyQ_SX54able0X49yfwn301_0_prorcx25w1(embedded_1);
    nimStrDestroy(infile_4);}
  else {
    eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(result_15);
    X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_70 = getOrDefault_0_Ibv556r_prorcx25w1(prog_0_prorcx25w1.mods_0, suffix_3);
    result_15 = X60Qx_70;}
  return result_15;}
LoadResult_0_prorcx25w1 tryLoadSym_0_prorcx25w1(NU32 s_5){
  LoadResult_0_prorcx25w1 result_18;
  eQwasmovedQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1((&result_18));
  NB8 X60Qx_97 = hasKey_0_prorcx25w1(prog_0_prorcx25w1.mem_0, s_5);
  if (X60Qx_97){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(result_18);
    ToplevelEntry_0_prorcx25w1* X60Qx_98 = getQ_0_prorcx25w1(prog_0_prorcx25w1.mem_0, s_5);
    Cursor_0_nifb6mq6y1 X60Qx_99 = cursorAt_0_nifb6mq6y1((&(*X60Qx_98).buffer_0), 0);
    result_18 = (LoadResult_0_prorcx25w1){
      .status_0 = 3, .decl_0 = X60Qx_99}
    ;}
  else {
    string_0_sysvq0asl* X60Qx_100 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_5);
    string_0_sysvq0asl nifName_0 = nimStrDup((*X60Qx_100));
    string_0_sysvq0asl modname_0 = extractModule_0_symkyk35i1(nifName_0);
    NB8 X60Qx_101 = eqQ_20_sysvq0asl(modname_0, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    if (X60Qx_101){
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(result_18);
      result_18 = (LoadResult_0_prorcx25w1){
        .status_0 = 0, .decl_0 = (Cursor_0_nifb6mq6y1){
          .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}}
      ;}
    else {
      X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* m_3 = load_0_prorcx25w1(modname_0);
      NifIndexEntry_0_nifa1znj21 indexEntry_0 = getOrDefault_0_Impbwl31_prorcx25w1((*m_3).d_00.public_0, nifName_0);
      if (indexEntry_0.offset_0 == 0){
        NifIndexEntry_0_nifa1znj21 X60Qx_102 = getOrDefault_0_Impbwl31_prorcx25w1((*m_3).d_00.private_0, nifName_0);
        indexEntry_0 = X60Qx_102;}
      if (indexEntry_0.offset_0 == 0){
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(result_18);
        result_18 = (LoadResult_0_prorcx25w1){
          .status_0 = 1, .decl_0 = (Cursor_0_nifb6mq6y1){
            .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}}
        ;}
      else {
        jumpTo_0_nif81dubp1((&(*m_3).d_00.stream_0.r_0), indexEntry_0.offset_0);
        TokenBuf_0_nifb6mq6y1 buf_1 = createTokenBuf_0_nifb6mq6y1(30);
        parse_0_nifb6mq6y1((&(*m_3).d_00.stream_0), (&buf_1), indexEntry_0.info_0, NIM_FALSE);
        Cursor_0_nifb6mq6y1 decl_0 = cursorAt_0_nifb6mq6y1((&buf_1), 0);
        TokenBuf_0_nifb6mq6y1 X60Qtmp_21 = buf_1;
        eQwasMoved_1_nifb6mq6y1((&buf_1));
        putQ_0_prorcx25w1((&prog_0_prorcx25w1.mem_0), s_5, (ToplevelEntry_0_prorcx25w1){
          .buffer_0 = X60Qtmp_21, .phase_0 = 4}
        );
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(result_18);
        Cursor_0_nifb6mq6y1 X60Qtmp_22 = decl_0;
        eQwasMoved_0_nifb6mq6y1((&decl_0));
        result_18 = (LoadResult_0_prorcx25w1){
          .status_0 = 3, .decl_0 = X60Qtmp_22}
        ;
        eQdestroy_0_nifb6mq6y1((&decl_0));
        eQdestroy_1_nifb6mq6y1((&buf_1));}
      eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(m_3);}
    nimStrDestroy(modname_0);
    nimStrDestroy(nifName_0);}
  return result_18;}
void publish_0_prorcx25w1(NU32 s_8, TokenBuf_0_nifb6mq6y1 buf_0, SemPhase_0_prorcx25w1 phase_0){
  NB8 X60Qx_139 = hasKey_0_prorcx25w1(prog_0_prorcx25w1.mem_0, s_8);
  if (X60Qx_139){
    ToplevelEntry_0_prorcx25w1* X60Qx_140 = getQ_0_prorcx25w1(prog_0_prorcx25w1.mem_0, s_8);
    TokenBuf_0_nifb6mq6y1* X60Qlhs_23 = (&(*X60Qx_140).buffer_0);
    TokenBuf_0_nifb6mq6y1 X60Qlhs_24 = buf_0;
    eQwasMoved_1_nifb6mq6y1((&buf_0));
    eQdestroy_1_nifb6mq6y1((&(*X60Qlhs_23)));
    (*X60Qlhs_23) = X60Qlhs_24;
    ToplevelEntry_0_prorcx25w1* X60Qx_141 = getQ_0_prorcx25w1(prog_0_prorcx25w1.mem_0, s_8);
    (*X60Qx_141).phase_0 = phase_0;}
  else {
    TokenBuf_0_nifb6mq6y1 X60Qtmp_25 = buf_0;
    eQwasMoved_1_nifb6mq6y1((&buf_0));
    putQ_0_prorcx25w1((&prog_0_prorcx25w1.mem_0), s_8, (ToplevelEntry_0_prorcx25w1){
      .buffer_0 = X60Qtmp_25, .phase_0 = phase_0}
    );}
  eQdestroy_1_nifb6mq6y1((&buf_0));}
void publishStringType_0_prorcx25w1(void){
  NU32 symId_3 = getOrIncl_0_Inyo00c_buiyylk1h1((&pool_0_nifh7u8pu1.syms_0), (string_0_sysvq0asl){
    .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I10459095262102366334_buiyylk1h1)}
  );
  NU32 exportMarker_0 = getOrIncl_0_Ix6biej1_ast8ri79k((&pool_0_nifh7u8pu1.strings_0), (string_0_sysvq0asl){
    .bytes_0 = 30721u, .more_0 = NIM_NIL}
  );
  TokenBuf_0_nifb6mq6y1 str_0 = createTokenBuf_0_nifb6mq6y1(10);
  NU32 bytesId_0 = getOrIncl_0_Inyo00c_buiyylk1h1((&pool_0_nifh7u8pu1.syms_0), (string_0_sysvq0asl){
    .bytes_0 = 1954112254u, .more_0 = (&strlit_0_I4783242303970288541_buiyylk1h1)}
  );
  NU32 moreId_0 = getOrIncl_0_Inyo00c_buiyylk1h1((&pool_0_nifh7u8pu1.syms_0), (string_0_sysvq0asl){
    .bytes_0 = 1919905278u, .more_0 = (&strlit_0_I18083737681243856668_buiyylk1h1)}
  );
  NU32 longStrSymId_0 = getOrIncl_0_Inyo00c_buiyylk1h1((&pool_0_nifh7u8pu1.syms_0), (string_0_sysvq0asl){
    .bytes_0 = 1852787966u, .more_0 = (&strlit_0_I9664704115936008796_buiyylk1h1)}
  );
  PackedToken_0_nifh7u8pu1 X60Qx_146 = parLeTokenUnchecked_0_nifb6mq6y1((string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
  , NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_146);
  PackedToken_0_nifh7u8pu1 X60Qx_147 = symdefToken_0_nifh7u8pu1(symId_3, NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_147);
  PackedToken_0_nifh7u8pu1 X60Qx_148 = identToken_0_nifh7u8pu1(exportMarker_0, NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_148);
  addDotToken_0_nifb6mq6y1((&str_0));
  addDotToken_0_nifb6mq6y1((&str_0));
  PackedToken_0_nifh7u8pu1 X60Qx_149 = parLeTokenUnchecked_0_nifb6mq6y1((string_0_sysvq0asl){
    .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
  , NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_149);
  addDotToken_0_nifb6mq6y1((&str_0));
  PackedToken_0_nifh7u8pu1 X60Qx_150 = parLeTokenUnchecked_0_nifb6mq6y1((string_0_sysvq0asl){
    .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
  , NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_150);
  PackedToken_0_nifh7u8pu1 X60Qx_151 = symdefToken_0_nifh7u8pu1(bytesId_0, NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_151);
  addDotToken_0_nifb6mq6y1((&str_0));
  addDotToken_0_nifb6mq6y1((&str_0));
  PackedToken_0_nifh7u8pu1 X60Qx_152 = parLeTokenUnchecked_0_nifb6mq6y1((string_0_sysvq0asl){
    .bytes_0 = 29953u, .more_0 = NIM_NIL}
  , NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_152);
  NU32 X60Qx_153 = getOrIncl_0_I4rntkc_buiyylk1h1((&pool_0_nifh7u8pu1.integers_0), ((NI64)-1));
  PackedToken_0_nifh7u8pu1 X60Qx_154 = intToken_0_nifh7u8pu1(X60Qx_153, NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_154);
  addParRi_0_nifb6mq6y1((&str_0));
  addDotToken_0_nifb6mq6y1((&str_0));
  addParRi_0_nifb6mq6y1((&str_0));
  PackedToken_0_nifh7u8pu1 X60Qx_155 = parLeTokenUnchecked_0_nifb6mq6y1((string_0_sysvq0asl){
    .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
  , NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_155);
  PackedToken_0_nifh7u8pu1 X60Qx_156 = symdefToken_0_nifh7u8pu1(moreId_0, NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_156);
  addDotToken_0_nifb6mq6y1((&str_0));
  addDotToken_0_nifb6mq6y1((&str_0));
  PackedToken_0_nifh7u8pu1 X60Qx_157 = parLeTokenUnchecked_0_nifb6mq6y1((string_0_sysvq0asl){
    .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
  , NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_157);
  PackedToken_0_nifh7u8pu1 X60Qx_158 = symToken_0_nifh7u8pu1(longStrSymId_0, NoLineInfo_0_linxafkvx1);
  add_0_nifb6mq6y1((&str_0), X60Qx_158);
  addParRi_0_nifb6mq6y1((&str_0));
  addDotToken_0_nifb6mq6y1((&str_0));
  addParRi_0_nifb6mq6y1((&str_0));
  addParRi_0_nifb6mq6y1((&str_0));
  addParRi_0_nifb6mq6y1((&str_0));
  TokenBuf_0_nifb6mq6y1 X60Qtmp_28 = str_0;
  eQwasMoved_1_nifb6mq6y1((&str_0));
  publish_0_prorcx25w1(symId_3, X60Qtmp_28, 4);
  eQdestroy_1_nifb6mq6y1((&str_0));}
void setupProgramForTesting_0_prorcx25w1(string_0_sysvq0asl dir_0, string_0_sysvq0asl file_0, string_0_sysvq0asl ext_0){
  string_0_sysvq0asl* X60Qlhs_38 = (&prog_0_prorcx25w1.main_0.dir_0);
  nimStrDestroy((*X60Qlhs_38));
  string_0_sysvq0asl X60Qx_168 = nimStrDup(dir_0);
  (*X60Qlhs_38) = X60Qx_168;
  string_0_sysvq0asl* X60Qlhs_39 = (&prog_0_prorcx25w1.main_0.name_0);
  nimStrDestroy((*X60Qlhs_39));
  string_0_sysvq0asl X60Qx_169 = nimStrDup(file_0);
  (*X60Qlhs_39) = X60Qx_169;
  string_0_sysvq0asl* X60Qlhs_40 = (&prog_0_prorcx25w1.main_0.ext_0);
  nimStrDestroy((*X60Qlhs_40));
  string_0_sysvq0asl X60Qx_170 = nimStrDup(ext_0);
  (*X60Qlhs_40) = X60Qx_170;
  publishStringType_0_prorcx25w1();}
static inline NI32 len_3_Inv614o_prorcx25w1(seq_0_Ikxamj_prorcx25w1 s_32){
  NI32 result_29;
  result_29 = s_32.len_0;
  return result_29;}
static inline NB8 hasKey_0_Ihimb3m1_prorcx25w1(Table_0_Idzo7511_prorcx25w1 t_35, NU32 k_22){
  NB8 result_30;
  NB8 X60Qx_174 = contains_0_Ix54wnr1_prorcx25w1(t_35, k_22);
  result_30 = X60Qx_174;
  return result_30;}
static inline ToplevelEntry_0_prorcx25w1* getQ_7_Ibc9d7t1_prorcx25w1(seq_0_Ikxamj_prorcx25w1 s_34, NI32 i_6){
  NB8 X60Qx_177;
  if (i_6 < s_34.len_0){
    X60Qx_177 = (0 <= i_6);}
  else {
    X60Qx_177 = NIM_FALSE;}
  if ((!X60Qx_177)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  ToplevelEntry_0_prorcx25w1* result_32;
  result_32 = (&s_34.data_0[i_6]);
  return result_32;}
NI32 getOrDefault_0_Ia2ap27_prorcx25w1(Table_0_Idzo7511_prorcx25w1 t_39, NU32 k_26){
  NI32 result_33;
  NU32 X60Qx_178 = hash_0_nifh7u8pu1(k_26);
  NI32 idx_3 = rawGet_0_I1waarx1_prorcx25w1(t_39, k_26, X60Qx_178);
  NI32 X60Qx_9;
  if (0 <= idx_3){
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1* X60Qx_179 = getQ_7_Ib1kjrf1_prorcx25w1(t_39.data_0, idx_3);
    X60Qx_9 = (*X60Qx_179).fld_1;}
  else {
    X60Qx_9 = ((NI32)0);}
  result_33 = X60Qx_9;
  return result_33;}
static inline void putQ_7_In0g3y61_prorcx25w1(seq_0_Ikxamj_prorcx25w1* s_35, NI32 i_7, ToplevelEntry_0_prorcx25w1 elem_5){
  NB8 X60Qx_180;
  if (i_7 < (*s_35).len_0){
    X60Qx_180 = (0 <= i_7);}
  else {
    X60Qx_180 = NIM_FALSE;}
  if ((!X60Qx_180)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  ToplevelEntry_0_prorcx25w1* X60Qlhs_41 = (&(*s_35).data_0[i_7]);
  ToplevelEntry_0_prorcx25w1 X60Qlhs_42 = elem_5;
  eQwasmovedQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1((&elem_5));
  eQdestroyQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1((*X60Qlhs_41));
  (*X60Qlhs_41) = X60Qlhs_42;
  eQdestroyQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1(elem_5);}
static inline void add_0_I1w6azk1_prorcx25w1(seq_0_Ikxamj_prorcx25w1* s_36, ToplevelEntry_0_prorcx25w1 elem_6){
  NI32 L_0 = (*s_36).len_0;
  NI32 X60Qx_181 = capInBytes_0_Iondjzw_prorcx25w1((*s_36));
  if (X60Qx_181 < ((NI32)(((NI32)(L_0 * sizeof(ToplevelEntry_0_prorcx25w1))) + sizeof(ToplevelEntry_0_prorcx25w1)))){
    NB8 X60Qx_182 = resize_0_I59ha4h1_prorcx25w1(s_36, 1);
    if ((!X60Qx_182)){
      eQdestroyQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1(elem_6);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_36).len_0));
  (*s_36).data_0[L_0] = elem_6;}
void putQ_0_Ioui0yi_prorcx25w1(Table_0_Idzo7511_prorcx25w1* t_40, NU32 k_27, NI32 v_10){
  NU32 h_0 = hash_0_nifh7u8pu1(k_27);
  NI32 idx_4 = rawGet_0_I1waarx1_prorcx25w1((*t_40), k_27, h_0);
  if (0 <= idx_4){
    X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1* X60Qx_183 = getQ_7_Ib1kjrf1_prorcx25w1((*t_40).data_0, idx_4);
    (*X60Qx_183).fld_1 = v_10;}
  else {
    rawPut_0_I4mfs8l1_prorcx25w1(t_40, k_27, v_10, h_0);}}
void putQ_0_Ixpvfkm_prorcx25w1(Table_0_Ij858uv_prorcx25w1* t_48, string_0_sysvq0asl k_33, X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* v_14){
  NU32 h_4 = hash_1_has9tn57v(k_33);
  NI32 idx_8 = rawGet_0_Igxgdwo1_prorcx25w1((*t_48), k_33, h_4);
  if (0 <= idx_8){
    X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_204 = getQ_7_Iu68xw61_prorcx25w1((*t_48).data_0, idx_8);
    X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1** X60Qlhs_45 = (&(*X60Qx_204).fld_1);
    X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qlhs_46 = v_14;
    eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((&v_14));
    eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((*X60Qlhs_45));
    (*X60Qlhs_45) = X60Qlhs_46;}
  else {
    string_0_sysvq0asl X60Qtmp_47 = k_33;
    nimStrWasMoved((&k_33));
    X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qtmp_48 = v_14;
    eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((&v_14));
    rawPut_0_Ilrji3k_prorcx25w1(t_48, X60Qtmp_47, X60Qtmp_48, h_4);}
  eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(v_14);
  nimStrDestroy(k_33);}
static inline NB8 hasKey_0_Ihi6ll91_prorcx25w1(Table_0_Ij858uv_prorcx25w1 t_51, string_0_sysvq0asl k_36){
  NB8 result_38;
  NB8 X60Qx_205 = contains_0_I0bsn0y1_prorcx25w1(t_51, k_36);
  result_38 = X60Qx_205;
  return result_38;}
static inline NI32 len_0_Ickzzw8_prorcx25w1(Table_0_Iyfwn301_nifa1znj21 t_53){
  NI32 result_39;
  NI32 X60Qx_206 = len_3_Ikddlyh1_nifa1znj21(t_53.data_0);
  result_39 = X60Qx_206;
  return result_39;}
X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* getOrDefault_0_Ibv556r_prorcx25w1(Table_0_Ij858uv_prorcx25w1 t_54, string_0_sysvq0asl k_38){
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* result_40;
  eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((&result_40));
  NU32 X60Qx_207 = hash_1_has9tn57v(k_38);
  NI32 idx_9 = rawGet_0_Igxgdwo1_prorcx25w1(t_54, k_38, X60Qx_207);
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_10;
  eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((&X60Qx_10));
  if (0 <= idx_9){
    eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qx_10);
    X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_208 = getQ_7_Iu68xw61_prorcx25w1(t_54.data_0, idx_9);
    X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_209 = eQdupQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((*X60Qx_208).fld_1);
    X60Qx_10 = X60Qx_209;}
  else {
    eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qx_10);
    X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_210 = eQdupQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(((X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1*)NIM_NIL));
    X60Qx_10 = X60Qx_210;}
  eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(result_40);
  result_40 = X60Qx_10;
  eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((&X60Qx_10));
  eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qx_10);
  return result_40;
  eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qx_10);
  return result_40;}
NifIndexEntry_0_nifa1znj21 getOrDefault_0_Impbwl31_prorcx25w1(Table_0_Iyfwn301_nifa1znj21 t_71, string_0_sysvq0asl k_49){
  NifIndexEntry_0_nifa1znj21 result_61;
  NU32 X60Qx_279 = hash_1_has9tn57v(k_49);
  NI32 idx_17 = rawGet_0_Ilpzx5l1_nifa1znj21(t_71, k_49, X60Qx_279);
  NifIndexEntry_0_nifa1znj21 X60Qx_12;
  if (0 <= idx_17){
    X60Qt_0_IAtupleSstring0sysvq0aslSX4eifX49ndexX45ntry0nifa1znj21_nifa1znj21* X60Qx_280 = getQ_7_I1m5sw7_nifa1znj21(t_71.data_0, idx_17);
    X60Qx_12 = (*X60Qx_280).fld_1;}
  else {
    X60Qx_12 = (NifIndexEntry_0_nifa1znj21){
      .offset_0 = ((NI32)0), .info_0 = ((NU32)0u), .vis_0 = 0}
    ;}
  result_61 = X60Qx_12;
  return result_61;}
static inline NB8 contains_0_Ix54wnr1_prorcx25w1(Table_0_Idzo7511_prorcx25w1 t_74, NU32 k_50){
  NB8 result_64;
  NU32 X60Qx_294 = hash_0_nifh7u8pu1(k_50);
  NI32 X60Qx_295 = rawGet_0_I1waarx1_prorcx25w1(t_74, k_50, X60Qx_294);
  result_64 = (0 <= X60Qx_295);
  return result_64;}
NI32 rawGet_0_I1waarx1_prorcx25w1(Table_0_Idzo7511_prorcx25w1 t_75, NU32 k_51, NU32 kh_5){
  NI32 result_65;
  NI32 X60Qx_296 = len_3_Iznbp3e_prorcx25w1(t_75.data_0);
  if (X60Qx_296 <= ((NI32)4)){
    {
      NI32 X60Qlf_60 = 0;
      NI32 X60Qlf_61 = len_3_Iznbp3e_prorcx25w1(t_75.data_0);
      NI32 X60Qlf_62 = X60Qlf_60;
      {
        while (X60Qlf_62 < X60Qlf_61){
          {
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1* X60Qx_297 = getQ_7_Ib1kjrf1_prorcx25w1(t_75.data_0, X60Qlf_62);
            NB8 X60Qx_298 = eqQ_0_nifh7u8pu1((*X60Qx_297).fld_0, k_51);
            if (X60Qx_298){
              return X60Qlf_62;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_62));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_299 = high_3_Iyuup9h1_filqx2b6r1(t_75.hashes_0);
    NU32 h_13 = ((NU32)(kh_5 & ((NU32)X60Qx_299)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_300 = getQ_8_Imt2zi01_filqx2b6r1(t_75.hashes_0, h_13);
        NB8 X60Qx_301 = isFilled_0_tabcr240b1((*X60Qx_300));
        if (X60Qx_301){
          HashEntry_0_tabcr240b1* X60Qx_302 = getQ_8_Imt2zi01_filqx2b6r1(t_75.hashes_0, h_13);
          HashEntry_0_tabcr240b1 d_3 = (*X60Qx_302);
          NB8 X60Qx_303;
          if (d_3.fullhash_0 == kh_5){
            X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1* X60Qx_304 = getQ_7_Ib1kjrf1_prorcx25w1(t_75.data_0, ((NI32)(d_3.position_0 - 1)));
            NB8 X60Qx_305 = eqQ_0_nifh7u8pu1((*X60Qx_304).fld_0, k_51);
            X60Qx_303 = X60Qx_305;}
          else {
            X60Qx_303 = NIM_FALSE;}
          if (X60Qx_303){
            result_65 = ((NI32)(d_3.position_0 - 1));
            return result_65;}
          NI32 X60Qx_306 = high_3_Iyuup9h1_filqx2b6r1(t_75.hashes_0);
          NU32 X60Qx_307 = nextTry_0_has9tn57v(h_13, X60Qx_306);
          h_13 = X60Qx_307;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_65 = -1;
  return result_65;}
static inline X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1* getQ_7_Ib1kjrf1_prorcx25w1(seq_0_I8hny96_prorcx25w1 s_92, NI32 i_37){
  NB8 X60Qx_308;
  if (i_37 < s_92.len_0){
    X60Qx_308 = (0 <= i_37);}
  else {
    X60Qx_308 = NIM_FALSE;}
  if ((!X60Qx_308)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1* result_66;
  result_66 = (&s_92.data_0[i_37]);
  return result_66;}
static inline NI32 capInBytes_0_Iondjzw_prorcx25w1(seq_0_Ikxamj_prorcx25w1 s_93){
  NI32 result_67;
  NI32 X60Qx_13;
  if ((!(s_93.data_0 == NIM_NIL))){
    NI32 X60Qx_309 = allocatedSize_0_sysvq0asl(((void*)((void*)s_93.data_0)));
    X60Qx_13 = X60Qx_309;}
  else {
    X60Qx_13 = 0;}
  result_67 = X60Qx_13;
  return result_67;}
NB8 resize_0_I59ha4h1_prorcx25w1(seq_0_Ikxamj_prorcx25w1* dest_6, NI32 addedElements_3){
  NB8 result_68;
  NI32 X60Qx_310 = capInBytes_0_Iondjzw_prorcx25w1((*dest_6));
  NI32 oldCap_0 = ((NI32)(X60Qx_310 / sizeof(ToplevelEntry_0_prorcx25w1)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_3);
  NI32 memSize_5 = memSizeInBytes_0_I7gtjtc_prorcx25w1(newCap_0);
  void* X60Qx_311 = realloc_1_sysvq0asl(((void*)((void*)(*dest_6).data_0)), memSize_5);
  (*dest_6).data_0 = ((ToplevelEntry_0_prorcx25w1*)X60Qx_311);
  if ((*dest_6).data_0 == NIM_NIL){
    (*dest_6).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_5);
    result_68 = NIM_FALSE;}
  else {
    result_68 = NIM_TRUE;}
  return result_68;}
void rawPut_0_I4mfs8l1_prorcx25w1(Table_0_Idzo7511_prorcx25w1* t_76, NU32 k_52, NI32 v_24, NU32 h_14){
  NI32 X60Qx_312 = len_3_Iznbp3e_prorcx25w1((*t_76).data_0);
  if (X60Qx_312 == ((NI32)4)){
    fillHashPart_0_Iogtr6v_prorcx25w1(t_76);}
  else {
    NI32 X60Qx_313 = len_3_Iiefpcc1_filqx2b6r1((*t_76).hashes_0);
    NI32 X60Qx_314 = len_3_Iznbp3e_prorcx25w1((*t_76).data_0);
    NB8 X60Qx_315 = mustRehash_0_tabcr240b1(X60Qx_313, X60Qx_314);
    if (X60Qx_315){
      resize_0_tabcr240b1((&(*t_76).hashes_0));}}
  add_0_I2lrufu1_prorcx25w1((&(*t_76).data_0), (X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1){
    .fld_0 = k_52, .fld_1 = v_24}
  );
  NI32 X60Qx_316 = high_3_Iyuup9h1_filqx2b6r1((*t_76).hashes_0);
  NU32 hi_1 = ((NU32)(h_14 & ((NU32)X60Qx_316)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_317 = getQ_8_Imt2zi01_filqx2b6r1((*t_76).hashes_0, hi_1);
      NB8 X60Qx_318 = isFilled_0_tabcr240b1((*X60Qx_317));
      if (X60Qx_318){
        NI32 X60Qx_319 = high_3_Iyuup9h1_filqx2b6r1((*t_76).hashes_0);
        NU32 X60Qx_320 = nextTry_0_has9tn57v(hi_1, X60Qx_319);
        hi_1 = X60Qx_320;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_321 = len_3_Iznbp3e_prorcx25w1((*t_76).data_0);
  putQ_8_Ipchg2a_filqx2b6r1((&(*t_76).hashes_0), hi_1, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_14, .position_0 = X60Qx_321}
  );}
static inline NI32 len_3_Iznbp3e_prorcx25w1(seq_0_I8hny96_prorcx25w1 s_96){
  NI32 result_69;
  result_69 = s_96.len_0;
  return result_69;}
void shrink_0_Io47po81_prorcx25w1(seq_0_Ikxuplm1_filqx2b6r1* s_102, NI32 newLen_6){
  NI32 i_43 = ((NI32)((*s_102).len_0 - 1));
  {
    while (newLen_6 <= i_43){
      dec_1_I0nzoz91_ast8ri79k((&i_43));}}
  whileStmtLabel_0: ;
  (*s_102).len_0 = newLen_6;}
NI32 rawGet_0_Igxgdwo1_prorcx25w1(Table_0_Ij858uv_prorcx25w1 t_81, string_0_sysvq0asl k_55, NU32 kh_7){
  NI32 result_82;
  NI32 X60Qx_350 = len_3_I9e1ja3_prorcx25w1(t_81.data_0);
  if (X60Qx_350 <= ((NI32)4)){
    {
      NI32 X60Qlf_66 = 0;
      NI32 X60Qlf_67 = len_3_I9e1ja3_prorcx25w1(t_81.data_0);
      NI32 X60Qlf_68 = X60Qlf_66;
      {
        while (X60Qlf_68 < X60Qlf_67){
          {
            X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_351 = getQ_7_Iu68xw61_prorcx25w1(t_81.data_0, X60Qlf_68);
            NB8 X60Qx_352 = eqQ_20_sysvq0asl((*X60Qx_351).fld_0, k_55);
            if (X60Qx_352){
              return X60Qlf_68;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_68));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_353 = high_3_Iyuup9h1_filqx2b6r1(t_81.hashes_0);
    NU32 h_17 = ((NU32)(kh_7 & ((NU32)X60Qx_353)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_354 = getQ_8_Imt2zi01_filqx2b6r1(t_81.hashes_0, h_17);
        NB8 X60Qx_355 = isFilled_0_tabcr240b1((*X60Qx_354));
        if (X60Qx_355){
          HashEntry_0_tabcr240b1* X60Qx_356 = getQ_8_Imt2zi01_filqx2b6r1(t_81.hashes_0, h_17);
          HashEntry_0_tabcr240b1 d_5 = (*X60Qx_356);
          NB8 X60Qx_357;
          if (d_5.fullhash_0 == kh_7){
            X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_358 = getQ_7_Iu68xw61_prorcx25w1(t_81.data_0, ((NI32)(d_5.position_0 - 1)));
            NB8 X60Qx_359 = eqQ_20_sysvq0asl((*X60Qx_358).fld_0, k_55);
            X60Qx_357 = X60Qx_359;}
          else {
            X60Qx_357 = NIM_FALSE;}
          if (X60Qx_357){
            result_82 = ((NI32)(d_5.position_0 - 1));
            return result_82;}
          NI32 X60Qx_360 = high_3_Iyuup9h1_filqx2b6r1(t_81.hashes_0);
          NU32 X60Qx_361 = nextTry_0_has9tn57v(h_17, X60Qx_360);
          h_17 = X60Qx_361;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_82 = -1;
  return result_82;}
static inline X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* getQ_7_Iu68xw61_prorcx25w1(seq_0_I7dew2c_prorcx25w1 s_108, NI32 i_47){
  NB8 X60Qx_362;
  if (i_47 < s_108.len_0){
    X60Qx_362 = (0 <= i_47);}
  else {
    X60Qx_362 = NIM_FALSE;}
  if ((!X60Qx_362)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* result_83;
  result_83 = (&s_108.data_0[i_47]);
  return result_83;}
void rawPut_0_Ilrji3k_prorcx25w1(Table_0_Ij858uv_prorcx25w1* t_82, string_0_sysvq0asl k_56, X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* v_26, NU32 h_18){
  NI32 X60Qx_363 = len_3_I9e1ja3_prorcx25w1((*t_82).data_0);
  if (X60Qx_363 == ((NI32)4)){
    fillHashPart_0_Ivt0bgj1_prorcx25w1(t_82);}
  else {
    NI32 X60Qx_364 = len_3_Iiefpcc1_filqx2b6r1((*t_82).hashes_0);
    NI32 X60Qx_365 = len_3_I9e1ja3_prorcx25w1((*t_82).data_0);
    NB8 X60Qx_366 = mustRehash_0_tabcr240b1(X60Qx_364, X60Qx_365);
    if (X60Qx_366){
      resize_0_tabcr240b1((&(*t_82).hashes_0));}}
  string_0_sysvq0asl X60Qtmp_52 = k_56;
  nimStrWasMoved((&k_56));
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qtmp_53 = v_26;
  eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((&v_26));
  add_0_Injpqso_prorcx25w1((&(*t_82).data_0), (X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1){
    .fld_0 = X60Qtmp_52, .fld_1 = X60Qtmp_53}
  );
  NI32 X60Qx_367 = high_3_Iyuup9h1_filqx2b6r1((*t_82).hashes_0);
  NU32 hi_3 = ((NU32)(h_18 & ((NU32)X60Qx_367)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_368 = getQ_8_Imt2zi01_filqx2b6r1((*t_82).hashes_0, hi_3);
      NB8 X60Qx_369 = isFilled_0_tabcr240b1((*X60Qx_368));
      if (X60Qx_369){
        NI32 X60Qx_370 = high_3_Iyuup9h1_filqx2b6r1((*t_82).hashes_0);
        NU32 X60Qx_371 = nextTry_0_has9tn57v(hi_3, X60Qx_370);
        hi_3 = X60Qx_371;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_372 = len_3_I9e1ja3_prorcx25w1((*t_82).data_0);
  putQ_8_Ipchg2a_filqx2b6r1((&(*t_82).hashes_0), hi_3, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_18, .position_0 = X60Qx_372}
  );
  eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(v_26);
  nimStrDestroy(k_56);}
static inline NB8 contains_0_I0bsn0y1_prorcx25w1(Table_0_Ij858uv_prorcx25w1 t_84, string_0_sysvq0asl k_57){
  NB8 result_84;
  NU32 X60Qx_373 = hash_1_has9tn57v(k_57);
  NI32 X60Qx_374 = rawGet_0_Igxgdwo1_prorcx25w1(t_84, k_57, X60Qx_373);
  result_84 = (0 <= X60Qx_374);
  return result_84;}
static inline NI32 memSizeInBytes_0_I7gtjtc_prorcx25w1(NI32 size_28){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_120;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_28, sizeof(ToplevelEntry_0_prorcx25w1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_120 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_120 = ((NI32)2147483647);}
  return result_120;}
void fillHashPart_0_Iogtr6v_prorcx25w1(Table_0_Idzo7511_prorcx25w1* t_99){
  seq_0_Ikxuplm1_filqx2b6r1* X60Qlhs_56 = (&(*t_99).hashes_0);
  eQdestroy_1_I5skmro_filqx2b6r1((*X60Qlhs_56));
  seq_0_Ikxuplm1_filqx2b6r1 X60Qx_474 = newSeq_0_Iv3lu2h1_filqx2b6r1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_56) = X60Qx_474;
  {
    NI32 X60Qlf_84 = 0;
    NI32 X60Qlf_85 = len_3_Iznbp3e_prorcx25w1((*t_99).data_0);
    NI32 X60Qlf_86 = X60Qlf_84;
    {
      while (X60Qlf_86 < X60Qlf_85){
        {
          X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1* X60Qx_475 = getQ_7_Ib1kjrf1_prorcx25w1((*t_99).data_0, X60Qlf_86);
          NU32 X60Qii_2 = hash_0_nifh7u8pu1((*X60Qx_475).fld_0);
          NI32 X60Qx_476 = high_3_Iyuup9h1_filqx2b6r1((*t_99).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_476)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_477 = getQ_8_Imt2zi01_filqx2b6r1((*t_99).hashes_0, X60Qii_3);
            NB8 X60Qx_478 = isFilled_0_tabcr240b1((*X60Qx_477));
            if (X60Qx_478){
              NI32 X60Qx_479 = high_3_Iyuup9h1_filqx2b6r1((*t_99).hashes_0);
              NU32 X60Qx_480 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_479);
              X60Qii_3 = X60Qx_480;}
            else {
              break;}}
          putQ_8_Ipchg2a_filqx2b6r1((&(*t_99).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_86 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_86));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_I2lrufu1_prorcx25w1(seq_0_I8hny96_prorcx25w1* s_159, X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1 elem_31){
  NI32 L_5 = (*s_159).len_0;
  NI32 X60Qx_481 = capInBytes_0_Izl8skj_prorcx25w1((*s_159));
  if (X60Qx_481 < ((NI32)(((NI32)(L_5 * sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1))) + sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1)))){
    NB8 X60Qx_482 = resize_0_Iaw0j0a1_prorcx25w1(s_159, 1);
    if ((!X60Qx_482)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_159).len_0));
  (*s_159).data_0[L_5] = elem_31;}
static inline NI32 len_3_I9e1ja3_prorcx25w1(seq_0_I7dew2c_prorcx25w1 s_163){
  NI32 result_123;
  result_123 = s_163.len_0;
  return result_123;}
void fillHashPart_0_Ivt0bgj1_prorcx25w1(Table_0_Ij858uv_prorcx25w1* t_101){
  seq_0_Ikxuplm1_filqx2b6r1* X60Qlhs_58 = (&(*t_101).hashes_0);
  eQdestroy_1_I5skmro_filqx2b6r1((*X60Qlhs_58));
  seq_0_Ikxuplm1_filqx2b6r1 X60Qx_492 = newSeq_0_Iv3lu2h1_filqx2b6r1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_58) = X60Qx_492;
  {
    NI32 X60Qlf_90 = 0;
    NI32 X60Qlf_91 = len_3_I9e1ja3_prorcx25w1((*t_101).data_0);
    NI32 X60Qlf_92 = X60Qlf_90;
    {
      while (X60Qlf_92 < X60Qlf_91){
        {
          X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* X60Qx_493 = getQ_7_Iu68xw61_prorcx25w1((*t_101).data_0, X60Qlf_92);
          NU32 X60Qii_2 = hash_1_has9tn57v((*X60Qx_493).fld_0);
          NI32 X60Qx_494 = high_3_Iyuup9h1_filqx2b6r1((*t_101).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_494)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_495 = getQ_8_Imt2zi01_filqx2b6r1((*t_101).hashes_0, X60Qii_3);
            NB8 X60Qx_496 = isFilled_0_tabcr240b1((*X60Qx_495));
            if (X60Qx_496){
              NI32 X60Qx_497 = high_3_Iyuup9h1_filqx2b6r1((*t_101).hashes_0);
              NU32 X60Qx_498 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_497);
              X60Qii_3 = X60Qx_498;}
            else {
              break;}}
          putQ_8_Ipchg2a_filqx2b6r1((&(*t_101).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_92 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_92));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_Injpqso_prorcx25w1(seq_0_I7dew2c_prorcx25w1* s_164, X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 elem_33){
  NI32 L_7 = (*s_164).len_0;
  NI32 X60Qx_499 = capInBytes_0_Ib1s9hw1_prorcx25w1((*s_164));
  if (X60Qx_499 < ((NI32)(((NI32)(L_7 * sizeof(X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1))) + sizeof(X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1)))){
    NB8 X60Qx_500 = resize_0_Ioofely_prorcx25w1(s_164, 1);
    if ((!X60Qx_500)){
      eQdestroyQ_AtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(elem_33);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_164).len_0));
  (*s_164).data_0[L_7] = elem_33;}
static inline NI32 capInBytes_0_Izl8skj_prorcx25w1(seq_0_I8hny96_prorcx25w1 s_191){
  NI32 result_142;
  NI32 X60Qx_19;
  if ((!(s_191.data_0 == NIM_NIL))){
    NI32 X60Qx_562 = allocatedSize_0_sysvq0asl(((void*)((void*)s_191.data_0)));
    X60Qx_19 = X60Qx_562;}
  else {
    X60Qx_19 = 0;}
  result_142 = X60Qx_19;
  return result_142;}
NB8 resize_0_Iaw0j0a1_prorcx25w1(seq_0_I8hny96_prorcx25w1* dest_20, NI32 addedElements_17){
  NB8 result_143;
  NI32 X60Qx_563 = capInBytes_0_Izl8skj_prorcx25w1((*dest_20));
  NI32 oldCap_5 = ((NI32)(X60Qx_563 / sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1)));
  NI32 newCap_5 = recalcCap_0_sysvq0asl(oldCap_5, addedElements_17);
  NI32 memSize_12 = memSizeInBytes_0_Iksokhb1_prorcx25w1(newCap_5);
  void* X60Qx_564 = realloc_1_sysvq0asl(((void*)((void*)(*dest_20).data_0)), memSize_12);
  (*dest_20).data_0 = ((X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1*)X60Qx_564);
  if ((*dest_20).data_0 == NIM_NIL){
    (*dest_20).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_12);
    result_143 = NIM_FALSE;}
  else {
    result_143 = NIM_TRUE;}
  return result_143;}
static inline NI32 capInBytes_0_Ib1s9hw1_prorcx25w1(seq_0_I7dew2c_prorcx25w1 s_193){
  NI32 result_146;
  NI32 X60Qx_21;
  if ((!(s_193.data_0 == NIM_NIL))){
    NI32 X60Qx_568 = allocatedSize_0_sysvq0asl(((void*)((void*)s_193.data_0)));
    X60Qx_21 = X60Qx_568;}
  else {
    X60Qx_21 = 0;}
  result_146 = X60Qx_21;
  return result_146;}
NB8 resize_0_Ioofely_prorcx25w1(seq_0_I7dew2c_prorcx25w1* dest_22, NI32 addedElements_19){
  NB8 result_147;
  NI32 X60Qx_569 = capInBytes_0_Ib1s9hw1_prorcx25w1((*dest_22));
  NI32 oldCap_7 = ((NI32)(X60Qx_569 / sizeof(X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1)));
  NI32 newCap_7 = recalcCap_0_sysvq0asl(oldCap_7, addedElements_19);
  NI32 memSize_14 = memSizeInBytes_0_Iojhvkv_prorcx25w1(newCap_7);
  void* X60Qx_570 = realloc_1_sysvq0asl(((void*)((void*)(*dest_22).data_0)), memSize_14);
  (*dest_22).data_0 = ((X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1*)X60Qx_570);
  if ((*dest_22).data_0 == NIM_NIL){
    (*dest_22).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_14);
    result_147 = NIM_FALSE;}
  else {
    result_147 = NIM_TRUE;}
  return result_147;}
static inline NI32 memSizeInBytes_0_Iksokhb1_prorcx25w1(NI32 size_47){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_162;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_47, sizeof(X60Qt_0_IAtupleSX53ymX49d0nifh7u8pu1AiS32_prorcx25w1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_162 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_162 = ((NI32)2147483647);}
  return result_162;}
static inline NI32 memSizeInBytes_0_Iojhvkv_prorcx25w1(NI32 size_48){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_163;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_48, sizeof(X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_163 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_163 = ((NI32)2147483647);}
  return result_163;}
static inline void eQwasMoved_1_Iyox4dh_prorcx25w1(seq_0_Ikxamj_prorcx25w1* s_241){
  (*s_241).len_0 = 0;
  (*s_241).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_Icsy95j1_prorcx25w1(seq_0_I8hny96_prorcx25w1* s_243){
  (*s_243).len_0 = 0;
  (*s_243).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_Itdnwi21_prorcx25w1(seq_0_I7dew2c_prorcx25w1* s_245){
  (*s_245).len_0 = 0;
  (*s_245).data_0 = NIM_NIL;}
void eQdestroyQ_SX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(NifModule_Obj_0_prorcx25w1* dest_0){
  eQdestroyQ_SX54able0X49yfwn301_0_prorcx25w1((*dest_0).private_0);
  eQdestroyQ_SX54able0X49yfwn301_0_prorcx25w1((*dest_0).public_0);
  eQdestroyQ_SX4eifX49ndex0nifa1znj21_0_nifa1znj21((*dest_0).index_0);
  eQdestroyQ_SX53tream0nifh7u8pu1_0_nifh7u8pu1((&(*dest_0).stream_0));}
void eQdestroyQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1(ToplevelEntry_0_prorcx25w1 dest_0){
  eQdestroy_1_nifb6mq6y1((&dest_0.buffer_0));}
void eQwasmovedQ_SX54oplevelX45ntry0prorcx25w1_0_prorcx25w1(ToplevelEntry_0_prorcx25w1* dest_0){
  eQwasMoved_1_nifb6mq6y1((&(*dest_0).buffer_0));}
void eQwasmovedQ_SX54oplevelX45ntries0prorcx25w1_0_prorcx25w1(ToplevelEntries_0_prorcx25w1* dest_0){
  eQwasMoved_1_Iyox4dh_prorcx25w1((&(*dest_0).entries_0));
  eQwasmovedQ_SX54able0X49dzo7511_0_prorcx25w1((&(*dest_0).bySymId_0));}
void eQwasmovedQ_SX50rogram0prorcx25w1_0_prorcx25w1(Program_0_prorcx25w1* dest_0){
  eQwasmovedQ_SX54able0X49j858uv_0_prorcx25w1((&(*dest_0).mods_0));
  eQwasmovedQ_SX53plittedX4doduleX50ath0symkyk35i1_0_symkyk35i1((&(*dest_0).main_0));
  eQwasmovedQ_SX54oplevelX45ntries0prorcx25w1_0_prorcx25w1((&(*dest_0).mem_0));}
void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0){
  eQdestroy_0_nifb6mq6y1((&dest_0.decl_0));}
void eQwasmovedQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1* dest_0){
  eQwasMoved_0_nifb6mq6y1((&(*dest_0).decl_0));}
void eQdestroyQ_SX54able0X49yfwn301_0_prorcx25w1(Table_0_Iyfwn301_nifa1znj21 dest_0){
  eQdestroy_1_I5skmro_filqx2b6r1(dest_0.hashes_0);
  eQdestroy_1_Ixsq1x81_nifa1znj21(dest_0.data_0);}
void eQwasmovedQ_SX54able0X49dzo7511_0_prorcx25w1(Table_0_Idzo7511_prorcx25w1* dest_0){
  eQwasMoved_1_Icsy95j1_prorcx25w1((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_filqx2b6r1((&(*dest_0).hashes_0));}
void eQwasmovedQ_SX54able0X49j858uv_0_prorcx25w1(Table_0_Ij858uv_prorcx25w1* dest_0){
  eQwasMoved_1_Itdnwi21_prorcx25w1((&(*dest_0).data_0));
  eQwasMoved_1_I8aeezd1_filqx2b6r1((&(*dest_0).hashes_0));}
void eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* dest_0){
  if (dest_0){
    NB8 X60Qx_734 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_734){
      eQdestroyQ_SX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1** dest_0){
  (*dest_0) = NIM_NIL;}
X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* eQdupQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* src_0){
  X60Qt_0_IArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_AtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(X60Qt_0_IAtupleSstring0sysvq0aslArefSX4eifX4doduleX4fbj0prorcx25w1_prorcx25w1 dest_0){
  nimStrDestroy(dest_0.fld_0);
  eQdestroyQ_ArefSX4eifX4doduleX4fbj0prorcx25w1_0_prorcx25w1(dest_0.fld_1);}
void X60Qini_0_prorcx25w1(void){
  if (X60QiniGuard_0_prorcx25w1){
    return;}
  X60QiniGuard_0_prorcx25w1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_has9tn57v();
  X60Qini_0_tabcr240b1();
  X60Qini_0_set37vj3r();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_linxafkvx1();
  X60Qini_0_nifjp9lau1();
  X60Qini_0_nifa1znj21();
  X60Qini_0_symkyk35i1();
  X60Qini_0_modjbswg91();
  X60Qini_0_repa2y0od1();
  X60Qini_0_buiyylk1h1();
  X60Qini_0_decqocs071();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_symiqlwtg1();
  X60Qini_0_ide5ljwgh1();
  X60Qini_0_nif12fhfr1();
  eQwasmovedQ_SX50rogram0prorcx25w1_0_prorcx25w1((&prog_0_prorcx25w1));}
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
static inline NI32 len_3_Ikddlyh1_nifa1znj21(seq_0_Irkj95k_nifa1znj21 s_58){
  NI32 result_49;
  result_49 = s_58.len_0;
  return result_49;}
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
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
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
static inline Cursor_0_nifb6mq6y1 cursorAt_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_11, NI32 i_2){
  Cursor_0_nifb6mq6y1 result_29;
  eQwasMoved_0_nifb6mq6y1((&result_29));
  NB8 X60Qx_70;
  if (0 <= i_2){
    X60Qx_70 = (i_2 < (*b_11).len_0);}
  else {
    X60Qx_70 = NIM_FALSE;}
  if ((!X60Qx_70)){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  if ((*b_11).owner_0 == NIM_NIL){
    void* X60Qx_71 = alloc0_1_sysvq0asl(sizeof(CursorOwnerObj_0_nifb6mq6y1));
    (*b_11).owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)X60Qx_71);
    (*(*b_11).owner_0).data_0 = (*b_11).data_0;
    (*(*b_11).owner_0).rc_0 = 1;}
  inc_1_I6wjjge_aow2h993l1((&(*(*b_11).owner_0).rc_0));
  eQdestroy_0_nifb6mq6y1((&result_29));
  result_29 = (Cursor_0_nifb6mq6y1){
    .owner_0 = (*b_11).owner_0, .p_0 = (&(*b_11).data_0[i_2]), .rem_0 = ((NI32)((*b_11).len_0 - i_2))}
  ;
  return result_29;}
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
static inline void eQwasMoved_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_2){
  (*dest_2).data_0 = NIM_NIL;
  (*dest_2).len_0 = 0;
  (*dest_2).cap_0 = 0;
  (*dest_2).owner_0 = NIM_NIL;}
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_ast8ri79k((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3){
  if ((!((*dest_3).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_ast8ri79k((&(*(*dest_3).owner_0).rc_0));
    if ((*(*dest_3).owner_0).rc_0 == 0){
      if ((!((*(*dest_3).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*dest_3).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*dest_3).owner_0)));}}
  else {
    if ((!((*dest_3).data_0 == NIM_NIL))){
      dealloc_1_sysvq0asl(((void*)(*dest_3).data_0));}}}
static inline PackedToken_0_nifh7u8pu1 parLeTokenUnchecked_0_nifb6mq6y1(string_0_sysvq0asl tag_3, NU32 info_14){
  PackedToken_0_nifh7u8pu1 result_43;
  NU32 X60Qx_130 = getOrIncl_0_Is83dq9_buiyylk1h1((&pool_0_nifh7u8pu1.tags_0), tag_3);
  PackedToken_0_nifh7u8pu1 X60Qx_131 = parLeToken_0_nifh7u8pu1(X60Qx_130, info_14);
  result_43 = X60Qx_131;
  return result_43;}
static inline void add_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_7, PackedToken_0_nifh7u8pu1 item_1){
  if ((!((*b_7).owner_0 == NIM_NIL))){
    prepareMutation_0_nifb6mq6y1(b_7);}
  if ((*b_7).cap_0 <= (*b_7).len_0){
    NI32 X60Qx_66 = max_2_sysvq0asl(((NI32)(((NI32)((*b_7).cap_0 / 2)) + (*b_7).cap_0)), 8);
    (*b_7).cap_0 = X60Qx_66;
    void* X60Qx_67 = realloc_1_sysvq0asl(((void*)(*b_7).data_0), ((NI32)(sizeof(PackedToken_0_nifh7u8pu1) * (*b_7).cap_0)));
    (*b_7).data_0 = ((PackedToken_0_nifh7u8pu1*)X60Qx_67);}
  (*b_7).data_0[(*b_7).len_0] = item_1;
  inc_1_I6wjjge_aow2h993l1((&(*b_7).len_0));}
static inline PackedToken_0_nifh7u8pu1 symdefToken_0_nifh7u8pu1(NU32 s_2, NU32 info_8){
  PackedToken_0_nifh7u8pu1 result_21;
  PackedToken_0_nifh7u8pu1 X60Qx_47 = toToken_0_Iip05tk1_nifh7u8pu1(5, s_2, info_8);
  result_21 = X60Qx_47;
  return result_21;}
static inline PackedToken_0_nifh7u8pu1 identToken_0_nifh7u8pu1(NU32 s_0, NU32 info_5){
  PackedToken_0_nifh7u8pu1 result_18;
  PackedToken_0_nifh7u8pu1 X60Qx_44 = toToken_0_Ika21pk_nifh7u8pu1(3, s_0, info_5);
  result_18 = X60Qx_44;
  return result_18;}
static inline PackedToken_0_nifh7u8pu1 intToken_0_nifh7u8pu1(NU32 id_2, NU32 info_11){
  PackedToken_0_nifh7u8pu1 result_25;
  PackedToken_0_nifh7u8pu1 X60Qx_51 = toToken_0_Is7quwk1_nifh7u8pu1(8, id_2, info_11);
  result_25 = X60Qx_51;
  return result_25;}
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
static inline NU32 hash_0_nifh7u8pu1(NU32 x_0){
  NU32 result_11;
  NU32 X60Qx_20 = hash_2_has9tn57v(x_0);
  result_11 = X60Qx_20;
  return result_11;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
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
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
static inline void eQwasMoved_1_I8aeezd1_filqx2b6r1(seq_0_Ikxuplm1_filqx2b6r1* s_35){
  (*s_35).len_0 = 0;
  (*s_35).data_0 = NIM_NIL;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
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
static inline PackedToken_0_nifh7u8pu1 parLeToken_0_nifh7u8pu1(NU32 t_0, NU32 info_9){
  PackedToken_0_nifh7u8pu1 result_22;
  PackedToken_0_nifh7u8pu1 X60Qx_48 = toToken_0_Iz0lv7d1_nifh7u8pu1(11, t_0, info_9);
  result_22 = X60Qx_48;
  return result_22;}
static inline void prepareMutation_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* b_0){
  if ((!((*b_0).owner_0 == NIM_NIL))){
    if ((*(*b_0).owner_0).rc_0 == 1){
      dealloc_1_sysvq0asl(((void*)(*b_0).owner_0));
      (*b_0).owner_0 = NIM_NIL;}
    else {
      NI32 X60Qx_61 = max_2_sysvq0asl((*b_0).cap_0, 8);
      void* X60Qx_62 = alloc_1_sysvq0asl(((NI32)(sizeof(PackedToken_0_nifh7u8pu1) * X60Qx_61)));
      PackedToken_0_nifh7u8pu1* newData_0 = ((PackedToken_0_nifh7u8pu1*)X60Qx_62);
      copyMem_0_sysvq0asl(((void*)newData_0), ((void*)(*b_0).data_0), ((NI32)(sizeof(PackedToken_0_nifh7u8pu1) * (*b_0).len_0)));
      dec_1_I0nzoz91_ast8ri79k((&(*(*b_0).owner_0).rc_0));
      if ((*(*b_0).owner_0).rc_0 == 0){
        if ((!((*(*b_0).owner_0).data_0 == NIM_NIL))){
          dealloc_1_sysvq0asl(((void*)((void*)(*(*b_0).owner_0).data_0)));}
        dealloc_1_sysvq0asl(((void*)((void*)(*b_0).owner_0)));}
      (*b_0).owner_0 = NIM_NIL;
      (*b_0).data_0 = newData_0;}}}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iip05tk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_10, NU32 id_14, NU32 info_29){
  PackedToken_0_nifh7u8pu1 result_63;
  result_63 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_10) | ((NU32)(((NU32)id_14) << ((NU32)4u))))), .info_0 = info_29}
  ;
  return result_63;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Ika21pk_nifh7u8pu1(NifKind_0_nif81dubp1 kind_9, NU32 id_13, NU32 info_28){
  PackedToken_0_nifh7u8pu1 result_62;
  result_62 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_9) | ((NU32)(((NU32)id_13) << ((NU32)4u))))), .info_0 = info_28}
  ;
  return result_62;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Is7quwk1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_13, NU32 id_17, NU32 info_32){
  PackedToken_0_nifh7u8pu1 result_66;
  result_66 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_13) | ((NU32)(((NU32)id_17) << ((NU32)4u))))), .info_0 = info_32}
  ;
  return result_66;}
static inline NU32 hash_2_has9tn57v(NU32 u_0){
  NU32 result_3;
  result_3 = u_0;
  return result_3;}
static inline PackedToken_0_nifh7u8pu1 toToken_0_Iz0lv7d1_nifh7u8pu1(NifKind_0_nif81dubp1 kind_12, NU32 id_16, NU32 info_31){
  PackedToken_0_nifh7u8pu1 result_65;
  result_65 = (PackedToken_0_nifh7u8pu1){
    .x_0 = ((NU32)(((NU32)kind_12) | ((NU32)(((NU32)id_16) << ((NU32)4u))))), .info_0 = info_31}
  ;
  return result_65;}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
