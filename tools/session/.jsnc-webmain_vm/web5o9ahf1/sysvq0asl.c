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
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <stdio.h>
#include <dlfcn.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct Trunk_0_sysvq0asl Trunk_0_sysvq0asl;
typedef struct LLChunk_0_sysvq0asl LLChunk_0_sysvq0asl;
typedef struct AvlNode_0_sysvq0asl AvlNode_0_sysvq0asl;
typedef struct FreeCell_0_sysvq0asl FreeCell_0_sysvq0asl;
typedef struct MemRegion_0_sysvq0asl MemRegion_0_sysvq0asl;
typedef struct SmallChunk_0_sysvq0asl SmallChunk_0_sysvq0asl;
typedef struct BigChunk_0_sysvq0asl BigChunk_0_sysvq0asl;
typedef struct HeapLinks_0_sysvq0asl HeapLinks_0_sysvq0asl;
typedef struct CoroutineBase_0_sysvq0asl CoroutineBase_0_sysvq0asl;
typedef struct Continuation_0_sysvq0asl Continuation_0_sysvq0asl;
typedef struct Exception_0_sysvq0asl Exception_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct X60Qt_0_IAarrayAuS32ZS16_sysvq0asl{
  NU32 a[16];}
X60Qt_0_IAarrayAuS32ZS16_sysvq0asl;
typedef struct Trunk_0_sysvq0asl{
  Trunk_0_sysvq0asl* next_0;
  NI32 key_0;
  X60Qt_0_IAarrayAuS32ZS16_sysvq0asl bits_0;}
Trunk_0_sysvq0asl;
typedef struct X60Qt_0_IAarrayAptrSX54runk0sysvq0aslZS256_sysvq0asl{
  Trunk_0_sysvq0asl* a[256];}
X60Qt_0_IAarrayAptrSX54runk0sysvq0aslZS256_sysvq0asl;
typedef struct IntSet_0_sysvq0asl{
  X60Qt_0_IAarrayAptrSX54runk0sysvq0aslZS256_sysvq0asl data_0;}
IntSet_0_sysvq0asl;
typedef struct LLChunk_0_sysvq0asl{
  NI32 size_0;
  NI32 acc_0;
  LLChunk_0_sysvq0asl* next_0;}
LLChunk_0_sysvq0asl;
typedef struct X60Qt_0_IAarrayAptrSX41vlX4eode0sysvq0aslZS2_sysvq0asl{
  AvlNode_0_sysvq0asl* a[2];}
X60Qt_0_IAarrayAptrSX41vlX4eode0sysvq0aslZS2_sysvq0asl;
typedef struct AvlNode_0_sysvq0asl{
  X60Qt_0_IAarrayAptrSX41vlX4eode0sysvq0aslZS2_sysvq0asl link_0;
  NI32 key_0;
  NI32 upperBound_0;
  NI32 level_0;}
AvlNode_0_sysvq0asl;
typedef struct FreeCell_0_sysvq0asl{
  FreeCell_0_sysvq0asl* next_0;
  NI32 alignment_0;}
FreeCell_0_sysvq0asl;
typedef struct BaseChunk_0_sysvq0asl{
  NI32 prevSize_0;
  NI32 size_0;
  MemRegion_0_sysvq0asl* owner_0;}
BaseChunk_0_sysvq0asl;
typedef struct SmallChunk_0_sysvq0asl{
  BaseChunk_0_sysvq0asl Q;
  SmallChunk_0_sysvq0asl* next_0;
  SmallChunk_0_sysvq0asl* prev_0;
  FreeCell_0_sysvq0asl* freeList_0;
  NI32 free_0;
  NU32 acc_0;
  NI32 foreignCells_0;
  NI32 chunkAlignOff_0;
   NIM_ALIGN(16)NU8 data_0[];}
SmallChunk_0_sysvq0asl;
typedef struct BigChunk_0_sysvq0asl{
  BaseChunk_0_sysvq0asl Q;
  BigChunk_0_sysvq0asl* next_0;
  BigChunk_0_sysvq0asl* prev_0;
   NIM_ALIGN(16)NU8 data_0[];}
BigChunk_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleAptrSX42igX43hunk0sysvq0aslZAiS32_sysvq0asl{
  BigChunk_0_sysvq0asl* fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAptrSX42igX43hunk0sysvq0aslZAiS32_sysvq0asl;
typedef struct X60Qt_0_IAarrayAtupleAptrSX42igX43hunk0sysvq0aslZAiS32ZZS30_sysvq0asl{
  X60Qt_0_IAtupleAptrSX42igX43hunk0sysvq0aslZAiS32_sysvq0asl a[30];}
X60Qt_0_IAarrayAtupleAptrSX42igX43hunk0sysvq0aslZAiS32ZZS30_sysvq0asl;
typedef struct HeapLinks_0_sysvq0asl{
  NI32 count_0;
  X60Qt_0_IAarrayAtupleAptrSX42igX43hunk0sysvq0aslZAiS32ZZS30_sysvq0asl chunks_0;
  HeapLinks_0_sysvq0asl* next_0;}
HeapLinks_0_sysvq0asl;
typedef struct X60Qt_0_IAarrayAptrSX53mallX43hunk0sysvq0aslZS256_sysvq0asl{
  SmallChunk_0_sysvq0asl* a[256];}
X60Qt_0_IAarrayAptrSX53mallX43hunk0sysvq0aslZS256_sysvq0asl;
typedef struct X60Qt_0_IAarrayAptrSX46reeX43ell0sysvq0aslZS256_sysvq0asl{
  FreeCell_0_sysvq0asl* a[256];}
X60Qt_0_IAarrayAptrSX46reeX43ell0sysvq0aslZS256_sysvq0asl;
typedef struct X60Qt_0_IAarrayAuS32ZS24_sysvq0asl{
  NU32 a[24];}
X60Qt_0_IAarrayAuS32ZS24_sysvq0asl;
typedef struct X60Qt_0_IAarrayAptrSX42igX43hunk0sysvq0aslZS32_sysvq0asl{
  BigChunk_0_sysvq0asl* a[32];}
X60Qt_0_IAarrayAptrSX42igX43hunk0sysvq0aslZS32_sysvq0asl;
typedef struct X60Qt_0_IAarrayAR0AptrSX42igX43hunk0sysvq0aslZS32ZS24_sysvq0asl{
  X60Qt_0_IAarrayAptrSX42igX43hunk0sysvq0aslZS32_sysvq0asl a[24];}
X60Qt_0_IAarrayAR0AptrSX42igX43hunk0sysvq0aslZS32ZS24_sysvq0asl;
typedef struct MemRegion_0_sysvq0asl{
  X60Qt_0_IAarrayAptrSX53mallX43hunk0sysvq0aslZS256_sysvq0asl freeSmallChunks_0;
  X60Qt_0_IAarrayAptrSX46reeX43ell0sysvq0aslZS256_sysvq0asl sharedFreeLists_0;
  NU32 flBitmap_0;
  X60Qt_0_IAarrayAuS32ZS24_sysvq0asl slBitmap_0;
  X60Qt_0_IAarrayAR0AptrSX42igX43hunk0sysvq0aslZS32ZS24_sysvq0asl matrix_0;
  LLChunk_0_sysvq0asl* llmem_0;
  NI32 currMem_0;
  NI32 maxMem_0;
  NI32 freeMem_0;
  NI32 occ_0;
  NI32 lastSize_0;
  BigChunk_0_sysvq0asl* sharedFreeListBigChunks_0;
  IntSet_0_sysvq0asl chunkStarts_0;
  NB8 lockActive_0;
  NB8 locked_0;
  NB8 blockChunkSizeIncrease_0;
  NI32 nextChunkSize_0;
  HeapLinks_0_sysvq0asl heapLinks_0;}
MemRegion_0_sysvq0asl;
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
typedef struct Single_0_sysvq0asl{
  NU32 bits_0;}
Single_0_sysvq0asl;
typedef struct FloatingDecimal32_0_sysvq0asl{
  NU32 digits_0;
  NI32 exponent_0;}
FloatingDecimal32_0_sysvq0asl;
typedef struct Double_0_sysvq0asl{
  NU64 bits_0;}
Double_0_sysvq0asl;
typedef struct uint64x2_0_sysvq0asl{
  NU64 hi_0;
  NU64 lo_0;}
uint64x2_0_sysvq0asl;
typedef struct MulCmp_0_sysvq0asl{
  NU64 mul_0;
  NU64 cmp_0;}
MulCmp_0_sysvq0asl;
typedef struct FloatingDecimal64_0_sysvq0asl{
  NU64 significand_0;
  NI32 exponent_0;}
FloatingDecimal64_0_sysvq0asl;
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
typedef N_NIMCALL_PTR(Continuation_0_sysvq0asl,  X60Qt_0_IAptrSX43oroutineX42ase0sysvq0aslZSX43ontinuation0R22AnimcallZAfalseZAR61_sysvq0asl)(CoroutineBase_0_sysvq0asl*);
typedef struct Continuation_0_sysvq0asl{
  X60Qt_0_IAptrSX43oroutineX42ase0sysvq0aslZSX43ontinuation0R22AnimcallZAfalseZAR61_sysvq0asl fn_0;
  CoroutineBase_0_sysvq0asl* env_0;}
Continuation_0_sysvq0asl;
typedef struct CoroutineBase_0_sysvq0asl{
  RootObj_0_sysvq0asl Q;
  Continuation_0_sysvq0asl caller_0;
  CoroutineBase_0_sysvq0asl* callee_0;}
CoroutineBase_0_sysvq0asl;
typedef NU8 TypeOfMode_0_sysvq0asl;

#define typeOfProc_0_sysvq0asl ((NU8)0)
#define typeOfIter_0_sysvq0asl ((NU8)1)
typedef struct Exception_0_sysvq0asl{
  RootObj_0_sysvq0asl Q;
  string_0_sysvq0asl msg_0;}
Exception_0_sysvq0asl;
typedef struct openArray_0_Ijk0jkw1_feaji4clb1{
  NC8* a_0;
  NI32 len_0;}
openArray_0_Ijk0jkw1_feaji4clb1;
typedef struct HSlice_0_Inzqy8d_comaa5xpt1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_comaa5xpt1;
typedef struct HSlice_0_I8tnmvh1_comaa5xpt1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_I8tnmvh1_comaa5xpt1;
typedef struct X60Qt_0_IArefSX52ootX4fbj0sysvq0asl_sysvq0asl{
  NI r_00;
  RootObj_0_sysvq0asl d_00;}
X60Qt_0_IArefSX52ootX4fbj0sysvq0asl_sysvq0asl;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS10_sysvq0asl{
  string_0_sysvq0asl a[10];}
X60Qt_0_IAarraySstring0sysvq0aslS10_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21)(void);
typedef struct X60Qt_0_IAarrayAuS8ZS256_sysvq0asl{
  NU8 a[256];}
X60Qt_0_IAarrayAuS8ZS256_sysvq0asl;
typedef struct X60Qt_0_IAarrayAiS8ZS256_sysvq0asl{
  NI8 a[256];}
X60Qt_0_IAarrayAiS8ZS256_sysvq0asl;
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1{
  NI32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct X60Qt_0_IAarrayAiS8ZS100_sysvq0asl{
  NI8 a[100];}
X60Qt_0_IAarrayAiS8ZS100_sysvq0asl;
typedef struct X60Qt_0_IAarrayAcS8ZS200_sysvq0asl{
  NC8 a[200];}
X60Qt_0_IAarrayAcS8ZS200_sysvq0asl;
typedef struct X60Qt_0_IAarrayAuS64ZS77_sysvq0asl{
  NU64 a[77];}
X60Qt_0_IAarrayAuS64ZS77_sysvq0asl;
typedef struct X60Qt_0_IAarraySuint64x20sysvq0aslS619_sysvq0asl{
  uint64x2_0_sysvq0asl a[619];}
X60Qt_0_IAarraySuint64x20sysvq0aslS619_sysvq0asl;
typedef struct X60Qt_0_IAarraySX4dulX43mp0sysvq0aslS25_sysvq0asl{
  MulCmp_0_sysvq0asl a[25];}
X60Qt_0_IAarraySX4dulX43mp0sysvq0aslS25_sysvq0asl;
typedef struct X60Qt_0_IAarrayAcS8ZS16_sysvq0asl{
  NC8 a[16];}
X60Qt_0_IAarrayAcS8ZS16_sysvq0asl;
typedef struct X60Qt_0_IAarrayAcS8ZS65_sysvq0asl{
  NC8 a[65];}
X60Qt_0_IAarrayAcS8ZS65_sysvq0asl;
typedef N_NIMCALL_PTR(Continuation_0_sysvq0asl,  X60Qt_0_ISX43ontinuation0sysvq0aslSR0AnimcallZAfalseZAR37_sysvq0asl)(Continuation_0_sysvq0asl);
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAptrSX43oroutineX42ase0sysvq0aslZSEAnimcallZAfalseZAR44_sysvq0asl)(CoroutineBase_0_sysvq0asl*);
typedef struct X60Qt_0_IArefSX45xception0sysvq0asl_sysvq0asl{
  NI r_00;
  Exception_0_sysvq0asl d_00;}
X60Qt_0_IArefSX45xception0sysvq0asl_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISX45xception0sysvq0aslSEAnimcallZAfalseZAR33_sysvq0asl)(Exception_0_sysvq0asl*);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15);
string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0);
string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
static inline NB8 arcIsUnique_0_sysvq0asl(NI32* memLoc_2);
void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
static inline NU32 nimUcheckB(NU32 i_21, NU32 b_24);
static inline void listAdd_0_Ik4wxhz_sysvq0asl(SmallChunk_0_sysvq0asl** head_5, SmallChunk_0_sysvq0asl* c_38);
static inline void listRemove_0_Ibzev091_sysvq0asl(SmallChunk_0_sysvq0asl** head_6, SmallChunk_0_sysvq0asl* c_39);
void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
void raiseIndexError3_0_Ic5mmkg_sysvq0asl(NU32 i_69, NU32 a_84, NU32 b_39);
static inline void putQ_10_If2353w_sysvq0asl(openArray_0_Ijk0jkw1_feaji4clb1 x_380, NI32 i_70, NC8 elem_13);
static inline void dec_0_Idgnuqw1_sysvq0asl(NU64* x_382, NU64 y_218);
static inline void plusQeQ_0_Iar0t5x_sysvq0asl(NU64* x_384, NU64 y_220);
static inline void dec_1_Ifi4w3m1_sysvq0asl(NU64* x_385);
static inline X60Qt_0_IAarrayAcS8ZS16_sysvq0asl default_23_I1t3hvc_sysvq0asl(void);
static inline X60Qt_0_IAarrayAcS8ZS65_sysvq0asl default_23_Insyi17_sysvq0asl(void);
static inline openArray_0_Ijk0jkw1_feaji4clb1 toOpenArray_0_Iwrwfj81_sysvq0asl(X60Qt_0_IAarrayAcS8ZS65_sysvq0asl* x_388);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline void dec_0_Ig5i8xp_nifb6mq6y1(NI32* x_18, NI32 y_4);
static inline void inc_0_Iloplki_party5a2l1(NI32* x_10, NI32 y_3);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
static inline void inc_0_Ineawm41_party5a2l1(NU64* x_8, NU64 y_2);
static inline NC8* getQ_10_I5nt6we_feaji4clb1(openArray_0_Ijk0jkw1_feaji4clb1 x_2, NI32 idx_1);
extern LongString_0_sysvq0asl const strlit_0_I8062030498282895634_str7j0ifg;
extern LongString_0_sysvq0asl const strlit_0_I3193426178656842898_comaa5xpt1;
LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl = {
  .fullLen_0 = 117, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/stringimpl.nim(403, 37): i < len(s) and 0 <= i [AssertionDefect]\012"}
;
LongString_0_sysvq0asl const strlit_0_I11201514831099767300_sysvq0asl = {
  .fullLen_0 = 117, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/stringimpl.nim(407, 45): i < len(s) and 0 <= i [AssertionDefect]\012"}
;
LongString_0_sysvq0asl const strlit_0_I15539159382304113184_sysvq0asl = {
  .fullLen_0 = 27, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "invalid object conversion: "}
;
LongString_0_sysvq0asl const strlit_0_I14281474217946372742_sysvq0asl = {
  .fullLen_0 = 35, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cannot dispatch; dispatcher is nil\012"}
;
LongString_0_sysvq0asl const strlit_0_I16690852185662743073_sysvq0asl = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "could not load: "}
;
LongString_0_sysvq0asl const strlit_0_I10604297744791418982_sysvq0asl = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "could not import: "}
;
LongString_0_sysvq0asl const strlit_0_I11614695157650328859_sysvq0asl = {
  .fullLen_0 = 21, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "index out of bounds: "}
;
LongString_0_sysvq0asl const strlit_0_I16845119709590674135_sysvq0asl = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = " notin "}
;
X60Qt_0_IAarraySstring0sysvq0aslS10_sysvq0asl const NegTen_0_sysvq0asl = {
  .a = {
    {
      .bytes_0 = 3157250u, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3222786u, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3288322u, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3353858u, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3419394u, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3484930u, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3550466u, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3616002u, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3681538u, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3747074u, .more_0 = NIM_NIL}}}
;
X60Qt_0_ISEAnimcallZAfalseZAR11_jsfc0lwq21 gExitFlush_0_sysvq0asl;
X60Qt_0_IAarrayAiS8ZS256_sysvq0asl const fsLookupTable_0_sysvq0asl = {
  .a = {
    ((NI8)-1), ((NI8)0), ((NI8)1), ((NI8)1), ((NI8)2), ((NI8)2), ((NI8)2), ((NI8)2), ((NI8)3), ((NI8)3), ((NI8)3), ((NI8)3), ((NI8)3), ((NI8)3), ((NI8)3), ((NI8)3), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)4), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)5), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)6), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7), ((NI8)7)}}
;
__thread MemRegion_0_sysvq0asl allocator_0_sysvq0asl;
__thread NI32 missingBytes_0_sysvq0asl;
X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
X60Qt_0_IAarrayAiS8ZS100_sysvq0asl const trailingZeros100_0_sysvq0asl = {
  .a = {
    ((NI8)2), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)1), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)1), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)1), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)1), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)1), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)1), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)1), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)1), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)1), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0), ((NI8)0)}}
;
X60Qt_0_IAarrayAcS8ZS200_sysvq0asl const digits100_0_sysvq0asl = {
  .a = {
    (NC8)'0', (NC8)'0', (NC8)'0', (NC8)'1', (NC8)'0', (NC8)'2', (NC8)'0', (NC8)'3', (NC8)'0', (NC8)'4', (NC8)'0', (NC8)'5', (NC8)'0', (NC8)'6', (NC8)'0', (NC8)'7', (NC8)'0', (NC8)'8', (NC8)'0', (NC8)'9', (NC8)'1', (NC8)'0', (NC8)'1', (NC8)'1', (NC8)'1', (NC8)'2', (NC8)'1', (NC8)'3', (NC8)'1', (NC8)'4', (NC8)'1', (NC8)'5', (NC8)'1', (NC8)'6', (NC8)'1', (NC8)'7', (NC8)'1', (NC8)'8', (NC8)'1', (NC8)'9', (NC8)'2', (NC8)'0', (NC8)'2', (NC8)'1', (NC8)'2', (NC8)'2', (NC8)'2', (NC8)'3', (NC8)'2', (NC8)'4', (NC8)'2', (NC8)'5', (NC8)'2', (NC8)'6', (NC8)'2', (NC8)'7', (NC8)'2', (NC8)'8', (NC8)'2', (NC8)'9', (NC8)'3', (NC8)'0', (NC8)'3', (NC8)'1', (NC8)'3', (NC8)'2', (NC8)'3', (NC8)'3', (NC8)'3', (NC8)'4', (NC8)'3', (NC8)'5', (NC8)'3', (NC8)'6', (NC8)'3', (NC8)'7', (NC8)'3', (NC8)'8', (NC8)'3', (NC8)'9', (NC8)'4', (NC8)'0', (NC8)'4', (NC8)'1', (NC8)'4', (NC8)'2', (NC8)'4', (NC8)'3', (NC8)'4', (NC8)'4', (NC8)'4', (NC8)'5', (NC8)'4', (NC8)'6', (NC8)'4', (NC8)'7', (NC8)'4', (NC8)'8', (NC8)'4', (NC8)'9', (NC8)'5', (NC8)'0', (NC8)'5', (NC8)'1', (NC8)'5', (NC8)'2', (NC8)'5', (NC8)'3', (NC8)'5', (NC8)'4', (NC8)'5', (NC8)'5', (NC8)'5', (NC8)'6', (NC8)'5', (NC8)'7', (NC8)'5', (NC8)'8', (NC8)'5', (NC8)'9', (NC8)'6', (NC8)'0', (NC8)'6', (NC8)'1', (NC8)'6', (NC8)'2', (NC8)'6', (NC8)'3', (NC8)'6', (NC8)'4', (NC8)'6', (NC8)'5', (NC8)'6', (NC8)'6', (NC8)'6', (NC8)'7', (NC8)'6', (NC8)'8', (NC8)'6', (NC8)'9', (NC8)'7', (NC8)'0', (NC8)'7', (NC8)'1', (NC8)'7', (NC8)'2', (NC8)'7', (NC8)'3', (NC8)'7', (NC8)'4', (NC8)'7', (NC8)'5', (NC8)'7', (NC8)'6', (NC8)'7', (NC8)'7', (NC8)'7', (NC8)'8', (NC8)'7', (NC8)'9', (NC8)'8', (NC8)'0', (NC8)'8', (NC8)'1', (NC8)'8', (NC8)'2', (NC8)'8', (NC8)'3', (NC8)'8', (NC8)'4', (NC8)'8', (NC8)'5', (NC8)'8', (NC8)'6', (NC8)'8', (NC8)'7', (NC8)'8', (NC8)'8', (NC8)'8', (NC8)'9', (NC8)'9', (NC8)'0', (NC8)'9', (NC8)'1', (NC8)'9', (NC8)'2', (NC8)'9', (NC8)'3', (NC8)'9', (NC8)'4', (NC8)'9', (NC8)'5', (NC8)'9', (NC8)'6', (NC8)'9', (NC8)'7', (NC8)'9', (NC8)'8', (NC8)'9', (NC8)'9'}}
;
static NI32 const kMin_0 = ((NI32)-292);
static NI32 const kMax_0 = ((NI32)326);
static X60Qt_0_IAarraySuint64x20sysvq0aslS619_sysvq0asl const pow10_3 = {
  .a = {
    {
      .hi_0 = ((NU64)18408377700990114895ull), .lo_0 = ((NU64)2731688931043774331ull)}
    , {
      .hi_0 = ((NU64)11505236063118821809ull), .lo_0 = ((NU64)8624834609543440813ull)}
    , {
      .hi_0 = ((NU64)14381545078898527261ull), .lo_0 = ((NU64)15392729280356688920ull)}
    , {
      .hi_0 = ((NU64)17976931348623159077ull), .lo_0 = ((NU64)5405853545163697438ull)}
    , {
      .hi_0 = ((NU64)11235582092889474423ull), .lo_0 = ((NU64)5684501474941004851ull)}
    , {
      .hi_0 = ((NU64)14044477616111843029ull), .lo_0 = ((NU64)2493940825248868160ull)}
    , {
      .hi_0 = ((NU64)17555597020139803786ull), .lo_0 = ((NU64)7729112049988473104ull)}
    , {
      .hi_0 = ((NU64)10972248137587377366ull), .lo_0 = ((NU64)9442381049670183594ull)}
    , {
      .hi_0 = ((NU64)13715310171984221708ull), .lo_0 = ((NU64)2579604275232953684ull)}
    , {
      .hi_0 = ((NU64)17144137714980277135ull), .lo_0 = ((NU64)3224505344041192105ull)}
    , {
      .hi_0 = ((NU64)10715086071862673209ull), .lo_0 = ((NU64)8932844867666826922ull)}
    , {
      .hi_0 = ((NU64)13393857589828341511ull), .lo_0 = ((NU64)15777742103010921556ull)}
    , {
      .hi_0 = ((NU64)16742321987285426889ull), .lo_0 = ((NU64)15110491610336264041ull)}
    , {
      .hi_0 = ((NU64)10463951242053391806ull), .lo_0 = ((NU64)2526528228819083170ull)}
    , {
      .hi_0 = ((NU64)13079939052566739757ull), .lo_0 = ((NU64)12381532322878629771ull)}
    , {
      .hi_0 = ((NU64)16349923815708424697ull), .lo_0 = ((NU64)1641857348316123501ull)}
    , {
      .hi_0 = ((NU64)10218702384817765435ull), .lo_0 = ((NU64)12555375888766046948ull)}
    , {
      .hi_0 = ((NU64)12773377981022206794ull), .lo_0 = ((NU64)11082533842530170781ull)}
    , {
      .hi_0 = ((NU64)15966722476277758493ull), .lo_0 = ((NU64)4629795266307937668ull)}
    , {
      .hi_0 = ((NU64)9979201547673599058ull), .lo_0 = ((NU64)5199465050656154995ull)}
    , {
      .hi_0 = ((NU64)12474001934591998822ull), .lo_0 = ((NU64)15722703350174969552ull)}
    , {
      .hi_0 = ((NU64)15592502418239998528ull), .lo_0 = ((NU64)10430007150863936131ull)}
    , {
      .hi_0 = ((NU64)9745314011399999080ull), .lo_0 = ((NU64)6518754469289960082ull)}
    , {
      .hi_0 = ((NU64)12181642514249998850ull), .lo_0 = ((NU64)8148443086612450103ull)}
    , {
      .hi_0 = ((NU64)15227053142812498563ull), .lo_0 = ((NU64)962181821410786820ull)}
    , {
      .hi_0 = ((NU64)9516908214257811601ull), .lo_0 = ((NU64)16742264702877599427ull)}
    , {
      .hi_0 = ((NU64)11896135267822264502ull), .lo_0 = ((NU64)7092772823314835571ull)}
    , {
      .hi_0 = ((NU64)14870169084777830627ull), .lo_0 = ((NU64)18089338065998320272ull)}
    , {
      .hi_0 = ((NU64)9293855677986144142ull), .lo_0 = ((NU64)8999993282035256218ull)}
    , {
      .hi_0 = ((NU64)11617319597482680178ull), .lo_0 = ((NU64)2026619565689294465ull)}
    , {
      .hi_0 = ((NU64)14521649496853350222ull), .lo_0 = ((NU64)11756646493966393889ull)}
    , {
      .hi_0 = ((NU64)18152061871066687778ull), .lo_0 = ((NU64)5472436080603216553ull)}
    , {
      .hi_0 = ((NU64)11345038669416679861ull), .lo_0 = ((NU64)8031958568804398250ull)}
    , {
      .hi_0 = ((NU64)14181298336770849826ull), .lo_0 = ((NU64)14651634229432885716ull)}
    , {
      .hi_0 = ((NU64)17726622920963562283ull), .lo_0 = ((NU64)9091170749936331337ull)}
    , {
      .hi_0 = ((NU64)11079139325602226427ull), .lo_0 = ((NU64)3376138709496513134ull)}
    , {
      .hi_0 = ((NU64)13848924157002783033ull), .lo_0 = ((NU64)18055231442152805129ull)}
    , {
      .hi_0 = ((NU64)17311155196253478792ull), .lo_0 = ((NU64)8733981247408842699ull)}
    , {
      .hi_0 = ((NU64)10819471997658424245ull), .lo_0 = ((NU64)5458738279630526687ull)}
    , {
      .hi_0 = ((NU64)13524339997073030306ull), .lo_0 = ((NU64)11435108867965546263ull)}
    , {
      .hi_0 = ((NU64)16905424996341287883ull), .lo_0 = ((NU64)5070514048102157021ull)}
    , {
      .hi_0 = ((NU64)10565890622713304927ull), .lo_0 = ((NU64)863228270850154186ull)}
    , {
      .hi_0 = ((NU64)13207363278391631158ull), .lo_0 = ((NU64)14914093393844856444ull)}
    , {
      .hi_0 = ((NU64)16509204097989538948ull), .lo_0 = ((NU64)9419244705451294747ull)}
    , {
      .hi_0 = ((NU64)10318252561243461842ull), .lo_0 = ((NU64)15110399977761835025ull)}
    , {
      .hi_0 = ((NU64)12897815701554327303ull), .lo_0 = ((NU64)9664627935347517974ull)}
    , {
      .hi_0 = ((NU64)16122269626942909129ull), .lo_0 = ((NU64)7469098900757009563ull)}
    , {
      .hi_0 = ((NU64)10076418516839318205ull), .lo_0 = ((NU64)16197401859041600737ull)}
    , {
      .hi_0 = ((NU64)12595523146049147757ull), .lo_0 = ((NU64)6411694268519837209ull)}
    , {
      .hi_0 = ((NU64)15744403932561434696ull), .lo_0 = ((NU64)12626303854077184415ull)}
    , {
      .hi_0 = ((NU64)9840252457850896685ull), .lo_0 = ((NU64)7891439908798240260ull)}
    , {
      .hi_0 = ((NU64)12300315572313620856ull), .lo_0 = ((NU64)14475985904425188228ull)}
    , {
      .hi_0 = ((NU64)15375394465392026070ull), .lo_0 = ((NU64)18094982380531485285ull)}
    , {
      .hi_0 = ((NU64)9609621540870016294ull), .lo_0 = ((NU64)6697677969404790400ull)}
    , {
      .hi_0 = ((NU64)12012026926087520367ull), .lo_0 = ((NU64)17595469498610763807ull)}
    , {
      .hi_0 = ((NU64)15015033657609400459ull), .lo_0 = ((NU64)17382650854836066855ull)}
    , {
      .hi_0 = ((NU64)9384396036005875287ull), .lo_0 = ((NU64)8558313775058847833ull)}
    , {
      .hi_0 = ((NU64)11730495045007344109ull), .lo_0 = ((NU64)6086206200396171887ull)}
    , {
      .hi_0 = ((NU64)14663118806259180136ull), .lo_0 = ((NU64)12219443768922602762ull)}
    , {
      .hi_0 = ((NU64)18328898507823975170ull), .lo_0 = ((NU64)15274304711153253453ull)}
    , {
      .hi_0 = ((NU64)11455561567389984481ull), .lo_0 = ((NU64)14158126462898171312ull)}
    , {
      .hi_0 = ((NU64)14319451959237480602ull), .lo_0 = ((NU64)3862600023340550428ull)}
    , {
      .hi_0 = ((NU64)17899314949046850752ull), .lo_0 = ((NU64)14051622066030463843ull)}
    , {
      .hi_0 = ((NU64)11187071843154281720ull), .lo_0 = ((NU64)8782263791269039902ull)}
    , {
      .hi_0 = ((NU64)13983839803942852150ull), .lo_0 = ((NU64)10977829739086299877ull)}
    , {
      .hi_0 = ((NU64)17479799754928565188ull), .lo_0 = ((NU64)4498915137003099038ull)}
    , {
      .hi_0 = ((NU64)10924874846830353242ull), .lo_0 = ((NU64)12035193997481712707ull)}
    , {
      .hi_0 = ((NU64)13656093558537941553ull), .lo_0 = ((NU64)5820620459997365076ull)}
    , {
      .hi_0 = ((NU64)17070116948172426941ull), .lo_0 = ((NU64)11887461593424094249ull)}
    , {
      .hi_0 = ((NU64)10668823092607766838ull), .lo_0 = ((NU64)9735506505103752858ull)}
    , {
      .hi_0 = ((NU64)13336028865759708548ull), .lo_0 = ((NU64)2946011094524915264ull)}
    , {
      .hi_0 = ((NU64)16670036082199635685ull), .lo_0 = ((NU64)3682513868156144080ull)}
    , {
      .hi_0 = ((NU64)10418772551374772303ull), .lo_0 = ((NU64)4607414176811284002ull)}
    , {
      .hi_0 = ((NU64)13023465689218465379ull), .lo_0 = ((NU64)1147581702586717098ull)}
    , {
      .hi_0 = ((NU64)16279332111523081723ull), .lo_0 = ((NU64)15269535183515560085ull)}
    , {
      .hi_0 = ((NU64)10174582569701926077ull), .lo_0 = ((NU64)7237616480483531101ull)}
    , {
      .hi_0 = ((NU64)12718228212127407596ull), .lo_0 = ((NU64)13658706619031801780ull)}
    , {
      .hi_0 = ((NU64)15897785265159259495ull), .lo_0 = ((NU64)17073383273789752225ull)}
    , {
      .hi_0 = ((NU64)9936115790724537184ull), .lo_0 = ((NU64)17588393573759676997ull)}
    , {
      .hi_0 = ((NU64)12420144738405671481ull), .lo_0 = ((NU64)3538747893490044630ull)}
    , {
      .hi_0 = ((NU64)15525180923007089351ull), .lo_0 = ((NU64)9035120885289943692ull)}
    , {
      .hi_0 = ((NU64)9703238076879430844ull), .lo_0 = ((NU64)12564479580947296664ull)}
    , {
      .hi_0 = ((NU64)12129047596099288555ull), .lo_0 = ((NU64)15705599476184120829ull)}
    , {
      .hi_0 = ((NU64)15161309495124110694ull), .lo_0 = ((NU64)15020313326802763132ull)}
    , {
      .hi_0 = ((NU64)9475818434452569184ull), .lo_0 = ((NU64)4776009810824339054ull)}
    , {
      .hi_0 = ((NU64)11844773043065711480ull), .lo_0 = ((NU64)5970012263530423817ull)}
    , {
      .hi_0 = ((NU64)14805966303832139350ull), .lo_0 = ((NU64)7462515329413029772ull)}
    , {
      .hi_0 = ((NU64)9253728939895087094ull), .lo_0 = ((NU64)52386062455755703ull)}
    , {
      .hi_0 = ((NU64)11567161174868858867ull), .lo_0 = ((NU64)9288854614924470437ull)}
    , {
      .hi_0 = ((NU64)14458951468586073584ull), .lo_0 = ((NU64)6999382250228200142ull)}
    , {
      .hi_0 = ((NU64)18073689335732591980ull), .lo_0 = ((NU64)8749227812785250178ull)}
    , {
      .hi_0 = ((NU64)11296055834832869987ull), .lo_0 = ((NU64)14691639419845557169ull)}
    , {
      .hi_0 = ((NU64)14120069793541087484ull), .lo_0 = ((NU64)13752863256379558557ull)}
    , {
      .hi_0 = ((NU64)17650087241926359355ull), .lo_0 = ((NU64)17191079070474448197ull)}
    , {
      .hi_0 = ((NU64)11031304526203974597ull), .lo_0 = ((NU64)8438581409832836171ull)}
    , {
      .hi_0 = ((NU64)13789130657754968246ull), .lo_0 = ((NU64)15159912780718433118ull)}
    , {
      .hi_0 = ((NU64)17236413322193710308ull), .lo_0 = ((NU64)9726518939043265589ull)}
    , {
      .hi_0 = ((NU64)10772758326371068942ull), .lo_0 = ((NU64)15302446373756816801ull)}
    , {
      .hi_0 = ((NU64)13465947907963836178ull), .lo_0 = ((NU64)9904685930341245194ull)}
    , {
      .hi_0 = ((NU64)16832434884954795223ull), .lo_0 = ((NU64)3157485376071780684ull)}
    , {
      .hi_0 = ((NU64)10520271803096747014ull), .lo_0 = ((NU64)8890957387685944784ull)}
    , {
      .hi_0 = ((NU64)13150339753870933768ull), .lo_0 = ((NU64)1890324697752655171ull)}
    , {
      .hi_0 = ((NU64)16437924692338667210ull), .lo_0 = ((NU64)2362905872190818964ull)}
    , {
      .hi_0 = ((NU64)10273702932711667006ull), .lo_0 = ((NU64)6088502188546649757ull)}
    , {
      .hi_0 = ((NU64)12842128665889583757ull), .lo_0 = ((NU64)16833999772538088004ull)}
    , {
      .hi_0 = ((NU64)16052660832361979697ull), .lo_0 = ((NU64)7207441660390446293ull)}
    , {
      .hi_0 = ((NU64)10032913020226237310ull), .lo_0 = ((NU64)16033866083812498693ull)}
    , {
      .hi_0 = ((NU64)12541141275282796638ull), .lo_0 = ((NU64)10818960567910847558ull)}
    , {
      .hi_0 = ((NU64)15676426594103495798ull), .lo_0 = ((NU64)4300328673033783640ull)}
    , {
      .hi_0 = ((NU64)9797766621314684873ull), .lo_0 = ((NU64)16522763475928278487ull)}
    , {
      .hi_0 = ((NU64)12247208276643356092ull), .lo_0 = ((NU64)6818396289628184397ull)}
    , {
      .hi_0 = ((NU64)15309010345804195115ull), .lo_0 = ((NU64)8522995362035230496ull)}
    , {
      .hi_0 = ((NU64)9568131466127621947ull), .lo_0 = ((NU64)3021029092058325108ull)}
    , {
      .hi_0 = ((NU64)11960164332659527433ull), .lo_0 = ((NU64)17611344420355070097ull)}
    , {
      .hi_0 = ((NU64)14950205415824409292ull), .lo_0 = ((NU64)8179122470161673909ull)}
    , {
      .hi_0 = ((NU64)9343878384890255807ull), .lo_0 = ((NU64)14335323580705822001ull)}
    , {
      .hi_0 = ((NU64)11679847981112819759ull), .lo_0 = ((NU64)13307468457454889597ull)}
    , {
      .hi_0 = ((NU64)14599809976391024699ull), .lo_0 = ((NU64)12022649553391224093ull)}
    , {
      .hi_0 = ((NU64)18249762470488780874ull), .lo_0 = ((NU64)10416625923311642212ull)}
    , {
      .hi_0 = ((NU64)11406101544055488046ull), .lo_0 = ((NU64)11122077220497164287ull)}
    , {
      .hi_0 = ((NU64)14257626930069360058ull), .lo_0 = ((NU64)4679224488766679550ull)}
    , {
      .hi_0 = ((NU64)17822033662586700072ull), .lo_0 = ((NU64)15072402647813125245ull)}
    , {
      .hi_0 = ((NU64)11138771039116687545ull), .lo_0 = ((NU64)9420251654883203279ull)}
    , {
      .hi_0 = ((NU64)13923463798895859431ull), .lo_0 = ((NU64)16387000587031392002ull)}
    , {
      .hi_0 = ((NU64)17404329748619824289ull), .lo_0 = ((NU64)15872064715361852098ull)}
    , {
      .hi_0 = ((NU64)10877706092887390181ull), .lo_0 = ((NU64)3002511419460075706ull)}
    , {
      .hi_0 = ((NU64)13597132616109237726ull), .lo_0 = ((NU64)8364825292752482536ull)}
    , {
      .hi_0 = ((NU64)16996415770136547158ull), .lo_0 = ((NU64)1232659579085827362ull)}
    , {
      .hi_0 = ((NU64)10622759856335341973ull), .lo_0 = ((NU64)14605470292210805813ull)}
    , {
      .hi_0 = ((NU64)13278449820419177467ull), .lo_0 = ((NU64)4421779809981343555ull)}
    , {
      .hi_0 = ((NU64)16598062275523971834ull), .lo_0 = ((NU64)915538744049291539ull)}
    , {
      .hi_0 = ((NU64)10373788922202482396ull), .lo_0 = ((NU64)5183897733458195116ull)}
    , {
      .hi_0 = ((NU64)12967236152753102995ull), .lo_0 = ((NU64)6479872166822743895ull)}
    , {
      .hi_0 = ((NU64)16209045190941378744ull), .lo_0 = ((NU64)3488154190101041965ull)}
    , {
      .hi_0 = ((NU64)10130653244338361715ull), .lo_0 = ((NU64)2180096368813151228ull)}
    , {
      .hi_0 = ((NU64)12663316555422952143ull), .lo_0 = ((NU64)16560178516298602747ull)}
    , {
      .hi_0 = ((NU64)15829145694278690179ull), .lo_0 = ((NU64)16088537126945865530ull)}
    , {
      .hi_0 = ((NU64)9893216058924181362ull), .lo_0 = ((NU64)7749492695127472004ull)}
    , {
      .hi_0 = ((NU64)12366520073655226703ull), .lo_0 = ((NU64)463493832054564197ull)}
    , {
      .hi_0 = ((NU64)15458150092069033378ull), .lo_0 = ((NU64)14414425345350368958ull)}
    , {
      .hi_0 = ((NU64)9661343807543145861ull), .lo_0 = ((NU64)13620701859271368503ull)}
    , {
      .hi_0 = ((NU64)12076679759428932327ull), .lo_0 = ((NU64)3190819268807046917ull)}
    , {
      .hi_0 = ((NU64)15095849699286165408ull), .lo_0 = ((NU64)17823582141290972358ull)}
    , {
      .hi_0 = ((NU64)9434906062053853380ull), .lo_0 = ((NU64)11139738838306857724ull)}
    , {
      .hi_0 = ((NU64)11793632577567316725ull), .lo_0 = ((NU64)13924673547883572155ull)}
    , {
      .hi_0 = ((NU64)14742040721959145907ull), .lo_0 = ((NU64)3570783879572301481ull)}
    , {
      .hi_0 = ((NU64)18427550902448932383ull), .lo_0 = ((NU64)18298537904747540563ull)}
    , {
      .hi_0 = ((NU64)11517219314030582739ull), .lo_0 = ((NU64)18354115218108294708ull)}
    , {
      .hi_0 = ((NU64)14396524142538228424ull), .lo_0 = ((NU64)18330958004207980481ull)}
    , {
      .hi_0 = ((NU64)17995655178172785531ull), .lo_0 = ((NU64)4466953431550423985ull)}
    , {
      .hi_0 = ((NU64)11247284486357990957ull), .lo_0 = ((NU64)486002885505321039ull)}
    , {
      .hi_0 = ((NU64)14059105607947488696ull), .lo_0 = ((NU64)5219189625309039203ull)}
    , {
      .hi_0 = ((NU64)17573882009934360870ull), .lo_0 = ((NU64)6523987031636299003ull)}
    , {
      .hi_0 = ((NU64)10983676256208975543ull), .lo_0 = ((NU64)17912549950054850589ull)}
    , {
      .hi_0 = ((NU64)13729595320261219429ull), .lo_0 = ((NU64)17779001419141175332ull)}
    , {
      .hi_0 = ((NU64)17161994150326524287ull), .lo_0 = ((NU64)8388693718644305453ull)}
    , {
      .hi_0 = ((NU64)10726246343954077679ull), .lo_0 = ((NU64)12160462601793772765ull)}
    , {
      .hi_0 = ((NU64)13407807929942597099ull), .lo_0 = ((NU64)10588892233814828052ull)}
    , {
      .hi_0 = ((NU64)16759759912428246374ull), .lo_0 = ((NU64)8624429273841147160ull)}
    , {
      .hi_0 = ((NU64)10474849945267653984ull), .lo_0 = ((NU64)778582277723329071ull)}
    , {
      .hi_0 = ((NU64)13093562431584567480ull), .lo_0 = ((NU64)973227847154161339ull)}
    , {
      .hi_0 = ((NU64)16366953039480709350ull), .lo_0 = ((NU64)1216534808942701674ull)}
    , {
      .hi_0 = ((NU64)10229345649675443343ull), .lo_0 = ((NU64)14595392310871352258ull)}
    , {
      .hi_0 = ((NU64)12786682062094304179ull), .lo_0 = ((NU64)13632554370161802419ull)}
    , {
      .hi_0 = ((NU64)15983352577617880224ull), .lo_0 = ((NU64)12429006944274865119ull)}
    , {
      .hi_0 = ((NU64)9989595361011175140ull), .lo_0 = ((NU64)7768129340171790700ull)}
    , {
      .hi_0 = ((NU64)12486994201263968925ull), .lo_0 = ((NU64)9710161675214738375ull)}
    , {
      .hi_0 = ((NU64)15608742751579961156ull), .lo_0 = ((NU64)16749388112445810872ull)}
    , {
      .hi_0 = ((NU64)9755464219737475723ull), .lo_0 = ((NU64)1244995533423855987ull)}
    , {
      .hi_0 = ((NU64)12194330274671844653ull), .lo_0 = ((NU64)15391302472061983696ull)}
    , {
      .hi_0 = ((NU64)15242912843339805817ull), .lo_0 = ((NU64)5404070034795315908ull)}
    , {
      .hi_0 = ((NU64)9526820527087378635ull), .lo_0 = ((NU64)14906758817815542203ull)}
    , {
      .hi_0 = ((NU64)11908525658859223294ull), .lo_0 = ((NU64)14021762503842039849ull)}
    , {
      .hi_0 = ((NU64)14885657073574029118ull), .lo_0 = ((NU64)8303831092947774003ull)}
    , {
      .hi_0 = ((NU64)9303535670983768199ull), .lo_0 = ((NU64)578208414664970848ull)}
    , {
      .hi_0 = ((NU64)11629419588729710248ull), .lo_0 = ((NU64)14557818573613377272ull)}
    , {
      .hi_0 = ((NU64)14536774485912137810ull), .lo_0 = ((NU64)18197273217016721590ull)}
    , {
      .hi_0 = ((NU64)18170968107390172263ull), .lo_0 = ((NU64)13523219484416126179ull)}
    , {
      .hi_0 = ((NU64)11356855067118857664ull), .lo_0 = ((NU64)15369541205401160718ull)}
    , {
      .hi_0 = ((NU64)14196068833898572081ull), .lo_0 = ((NU64)765182433041899282ull)}
    , {
      .hi_0 = ((NU64)17745086042373215101ull), .lo_0 = ((NU64)5568164059729762006ull)}
    , {
      .hi_0 = ((NU64)11090678776483259438ull), .lo_0 = ((NU64)5785945546544795206ull)}
    , {
      .hi_0 = ((NU64)13863348470604074297ull), .lo_0 = ((NU64)16455803970035769815ull)}
    , {
      .hi_0 = ((NU64)17329185588255092872ull), .lo_0 = ((NU64)6734696907262548557ull)}
    , {
      .hi_0 = ((NU64)10830740992659433045ull), .lo_0 = ((NU64)4209185567039092848ull)}
    , {
      .hi_0 = ((NU64)13538426240824291306ull), .lo_0 = ((NU64)9873167977226253964ull)}
    , {
      .hi_0 = ((NU64)16923032801030364133ull), .lo_0 = ((NU64)3118087934678041647ull)}
    , {
      .hi_0 = ((NU64)10576895500643977583ull), .lo_0 = ((NU64)4254647968387469982ull)}
    , {
      .hi_0 = ((NU64)13221119375804971979ull), .lo_0 = ((NU64)706623942056949573ull)}
    , {
      .hi_0 = ((NU64)16526399219756214973ull), .lo_0 = ((NU64)14718337982853350678ull)}
    , {
      .hi_0 = ((NU64)10328999512347634358ull), .lo_0 = ((NU64)11504804248497038126ull)}
    , {
      .hi_0 = ((NU64)12911249390434542948ull), .lo_0 = ((NU64)5157633273766521850ull)}
    , {
      .hi_0 = ((NU64)16139061738043178685ull), .lo_0 = ((NU64)6447041592208152312ull)}
    , {
      .hi_0 = ((NU64)10086913586276986678ull), .lo_0 = ((NU64)6335244004343789147ull)}
    , {
      .hi_0 = ((NU64)12608641982846233347ull), .lo_0 = ((NU64)17142427042284512242ull)}
    , {
      .hi_0 = ((NU64)15760802478557791684ull), .lo_0 = ((NU64)16816347784428252398ull)}
    , {
      .hi_0 = ((NU64)9850501549098619803ull), .lo_0 = ((NU64)1286845328412881941ull)}
    , {
      .hi_0 = ((NU64)12313126936373274753ull), .lo_0 = ((NU64)15443614715798266138ull)}
    , {
      .hi_0 = ((NU64)15391408670466593442ull), .lo_0 = ((NU64)5469460339465668960ull)}
    , {
      .hi_0 = ((NU64)9619630419041620901ull), .lo_0 = ((NU64)8030098730593431004ull)}
    , {
      .hi_0 = ((NU64)12024538023802026126ull), .lo_0 = ((NU64)14649309431669176659ull)}
    , {
      .hi_0 = ((NU64)15030672529752532658ull), .lo_0 = ((NU64)9088264752731695016ull)}
    , {
      .hi_0 = ((NU64)9394170331095332911ull), .lo_0 = ((NU64)10291851488884697289ull)}
    , {
      .hi_0 = ((NU64)11742712913869166139ull), .lo_0 = ((NU64)8253128342678483707ull)}
    , {
      .hi_0 = ((NU64)14678391142336457674ull), .lo_0 = ((NU64)5704724409920716730ull)}
    , {
      .hi_0 = ((NU64)18347988927920572092ull), .lo_0 = ((NU64)16354277549255671721ull)}
    , {
      .hi_0 = ((NU64)11467493079950357558ull), .lo_0 = ((NU64)998051431430019018ull)}
    , {
      .hi_0 = ((NU64)14334366349937946947ull), .lo_0 = ((NU64)10470936326142299580ull)}
    , {
      .hi_0 = ((NU64)17917957937422433684ull), .lo_0 = ((NU64)8476984389250486571ull)}
    , {
      .hi_0 = ((NU64)11198723710889021052ull), .lo_0 = ((NU64)14521487280136329915ull)}
    , {
      .hi_0 = ((NU64)13998404638611276315ull), .lo_0 = ((NU64)18151859100170412393ull)}
    , {
      .hi_0 = ((NU64)17498005798264095394ull), .lo_0 = ((NU64)18078137856785627588ull)}
    , {
      .hi_0 = ((NU64)10936253623915059621ull), .lo_0 = ((NU64)15910522178918405147ull)}
    , {
      .hi_0 = ((NU64)13670317029893824527ull), .lo_0 = ((NU64)6053094668365842721ull)}
    , {
      .hi_0 = ((NU64)17087896287367280659ull), .lo_0 = ((NU64)2954682317029915497ull)}
    , {
      .hi_0 = ((NU64)10679935179604550411ull), .lo_0 = ((NU64)17987577512639554850ull)}
    , {
      .hi_0 = ((NU64)13349918974505688014ull), .lo_0 = ((NU64)17872785872372055658ull)}
    , {
      .hi_0 = ((NU64)16687398718132110018ull), .lo_0 = ((NU64)13117610303610293765ull)}
    , {
      .hi_0 = ((NU64)10429624198832568761ull), .lo_0 = ((NU64)12810192458183821507ull)}
    , {
      .hi_0 = ((NU64)13037030248540710952ull), .lo_0 = ((NU64)2177682517447613172ull)}
    , {
      .hi_0 = ((NU64)16296287810675888690ull), .lo_0 = ((NU64)2722103146809516465ull)}
    , {
      .hi_0 = ((NU64)10185179881672430431ull), .lo_0 = ((NU64)6313000485183335695ull)}
    , {
      .hi_0 = ((NU64)12731474852090538039ull), .lo_0 = ((NU64)3279564588051781714ull)}
    , {
      .hi_0 = ((NU64)15914343565113172548ull), .lo_0 = ((NU64)17934513790346890854ull)}
    , {
      .hi_0 = ((NU64)9946464728195732843ull), .lo_0 = ((NU64)1985699082112030976ull)}
    , {
      .hi_0 = ((NU64)12433080910244666053ull), .lo_0 = ((NU64)16317181907922202432ull)}
    , {
      .hi_0 = ((NU64)15541351137805832567ull), .lo_0 = ((NU64)6561419329620589328ull)}
    , {
      .hi_0 = ((NU64)9713344461128645354ull), .lo_0 = ((NU64)11018416108653950186ull)}
    , {
      .hi_0 = ((NU64)12141680576410806693ull), .lo_0 = ((NU64)4549648098962661925ull)}
    , {
      .hi_0 = ((NU64)15177100720513508366ull), .lo_0 = ((NU64)10298746142130715310ull)}
    , {
      .hi_0 = ((NU64)9485687950320942729ull), .lo_0 = ((NU64)1825030320404309165ull)}
    , {
      .hi_0 = ((NU64)11857109937901178411ull), .lo_0 = ((NU64)6892973918932774360ull)}
    , {
      .hi_0 = ((NU64)14821387422376473014ull), .lo_0 = ((NU64)4004531380238580046ull)}
    , {
      .hi_0 = ((NU64)9263367138985295633ull), .lo_0 = ((NU64)16337890167931276241ull)}
    , {
      .hi_0 = ((NU64)11579208923731619542ull), .lo_0 = ((NU64)6587304654631931589ull)}
    , {
      .hi_0 = ((NU64)14474011154664524427ull), .lo_0 = ((NU64)17457502855144690294ull)}
    , {
      .hi_0 = ((NU64)18092513943330655534ull), .lo_0 = ((NU64)17210192550503474963ull)}
    , {
      .hi_0 = ((NU64)11307821214581659709ull), .lo_0 = ((NU64)6144684325637283948ull)}
    , {
      .hi_0 = ((NU64)14134776518227074636ull), .lo_0 = ((NU64)12292541425473992839ull)}
    , {
      .hi_0 = ((NU64)17668470647783843295ull), .lo_0 = ((NU64)15365676781842491049ull)}
    , {
      .hi_0 = ((NU64)11042794154864902059ull), .lo_0 = ((NU64)16521077016292638762ull)}
    , {
      .hi_0 = ((NU64)13803492693581127574ull), .lo_0 = ((NU64)16039660251938410548ull)}
    , {
      .hi_0 = ((NU64)17254365866976409468ull), .lo_0 = ((NU64)10826203278068237377ull)}
    , {
      .hi_0 = ((NU64)10783978666860255917ull), .lo_0 = ((NU64)15989749085647424169ull)}
    , {
      .hi_0 = ((NU64)13479973333575319897ull), .lo_0 = ((NU64)6152128301777116499ull)}
    , {
      .hi_0 = ((NU64)16849966666969149871ull), .lo_0 = ((NU64)12301846395648783527ull)}
    , {
      .hi_0 = ((NU64)10531229166855718669ull), .lo_0 = ((NU64)14606183024921571561ull)}
    , {
      .hi_0 = ((NU64)13164036458569648337ull), .lo_0 = ((NU64)4422670725869800739ull)}
    , {
      .hi_0 = ((NU64)16455045573212060421ull), .lo_0 = ((NU64)10140024425764638827ull)}
    , {
      .hi_0 = ((NU64)10284403483257537763ull), .lo_0 = ((NU64)8643358275316593219ull)}
    , {
      .hi_0 = ((NU64)12855504354071922204ull), .lo_0 = ((NU64)6192511825718353620ull)}
    , {
      .hi_0 = ((NU64)16069380442589902755ull), .lo_0 = ((NU64)7740639782147942025ull)}
    , {
      .hi_0 = ((NU64)10043362776618689222ull), .lo_0 = ((NU64)2532056854628769814ull)}
    , {
      .hi_0 = ((NU64)12554203470773361527ull), .lo_0 = ((NU64)12388443105140738075ull)}
    , {
      .hi_0 = ((NU64)15692754338466701909ull), .lo_0 = ((NU64)10873867862998534690ull)}
    , {
      .hi_0 = ((NU64)9807971461541688693ull), .lo_0 = ((NU64)9102010423587778133ull)}
    , {
      .hi_0 = ((NU64)12259964326927110866ull), .lo_0 = ((NU64)15989199047912110570ull)}
    , {
      .hi_0 = ((NU64)15324955408658888583ull), .lo_0 = ((NU64)10763126773035362405ull)}
    , {
      .hi_0 = ((NU64)9578097130411805364ull), .lo_0 = ((NU64)13644483260788183359ull)}
    , {
      .hi_0 = ((NU64)11972621413014756705ull), .lo_0 = ((NU64)17055604075985229199ull)}
    , {
      .hi_0 = ((NU64)14965776766268445882ull), .lo_0 = ((NU64)7484447039699372787ull)}
    , {
      .hi_0 = ((NU64)9353610478917778676ull), .lo_0 = ((NU64)9289465418239495896ull)}
    , {
      .hi_0 = ((NU64)11692013098647223345ull), .lo_0 = ((NU64)11611831772799369870ull)}
    , {
      .hi_0 = ((NU64)14615016373309029182ull), .lo_0 = ((NU64)679731660717048625ull)}
    , {
      .hi_0 = ((NU64)18268770466636286477ull), .lo_0 = ((NU64)10073036612751086589ull)}
    , {
      .hi_0 = ((NU64)11417981541647679048ull), .lo_0 = ((NU64)8601490892183123070ull)}
    , {
      .hi_0 = ((NU64)14272476927059598810ull), .lo_0 = ((NU64)10751863615228903838ull)}
    , {
      .hi_0 = ((NU64)17840596158824498513ull), .lo_0 = ((NU64)4216457482181353989ull)}
    , {
      .hi_0 = ((NU64)11150372599265311570ull), .lo_0 = ((NU64)14164500972431816003ull)}
    , {
      .hi_0 = ((NU64)13937965749081639463ull), .lo_0 = ((NU64)8482254178684994196ull)}
    , {
      .hi_0 = ((NU64)17422457186352049329ull), .lo_0 = ((NU64)5991131704928854841ull)}
    , {
      .hi_0 = ((NU64)10889035741470030830ull), .lo_0 = ((NU64)15273672361649004036ull)}
    , {
      .hi_0 = ((NU64)13611294676837538538ull), .lo_0 = ((NU64)9868718415206479237ull)}
    , {
      .hi_0 = ((NU64)17014118346046923173ull), .lo_0 = ((NU64)3112525982153323238ull)}
    , {
      .hi_0 = ((NU64)10633823966279326983ull), .lo_0 = ((NU64)4251171748059520976ull)}
    , {
      .hi_0 = ((NU64)13292279957849158729ull), .lo_0 = ((NU64)702278666647013315ull)}
    , {
      .hi_0 = ((NU64)16615349947311448411ull), .lo_0 = ((NU64)5489534351736154548ull)}
    , {
      .hi_0 = ((NU64)10384593717069655257ull), .lo_0 = ((NU64)1125115960621402641ull)}
    , {
      .hi_0 = ((NU64)12980742146337069071ull), .lo_0 = ((NU64)6018080969204141205ull)}
    , {
      .hi_0 = ((NU64)16225927682921336339ull), .lo_0 = ((NU64)2910915193077788602ull)}
    , {
      .hi_0 = ((NU64)10141204801825835211ull), .lo_0 = ((NU64)17960223060169475540ull)}
    , {
      .hi_0 = ((NU64)12676506002282294014ull), .lo_0 = ((NU64)17838592806784456521ull)}
    , {
      .hi_0 = ((NU64)15845632502852867518ull), .lo_0 = ((NU64)13074868971625794844ull)}
    , {
      .hi_0 = ((NU64)9903520314283042199ull), .lo_0 = ((NU64)3560107088838733873ull)}
    , {
      .hi_0 = ((NU64)12379400392853802748ull), .lo_0 = ((NU64)18285191916330581054ull)}
    , {
      .hi_0 = ((NU64)15474250491067253436ull), .lo_0 = ((NU64)4409745821703674701ull)}
    , {
      .hi_0 = ((NU64)9671406556917033397ull), .lo_0 = ((NU64)11979463175419572496ull)}
    , {
      .hi_0 = ((NU64)12089258196146291747ull), .lo_0 = ((NU64)1139270913992301908ull)}
    , {
      .hi_0 = ((NU64)15111572745182864683ull), .lo_0 = ((NU64)15259146697772541097ull)}
    , {
      .hi_0 = ((NU64)9444732965739290427ull), .lo_0 = ((NU64)7231123676894144234ull)}
    , {
      .hi_0 = ((NU64)11805916207174113034ull), .lo_0 = ((NU64)4427218577690292388ull)}
    , {
      .hi_0 = ((NU64)14757395258967641292ull), .lo_0 = ((NU64)14757395258967641293ull)}
    , {
      .hi_0 = ((NU64)9223372036854775808ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)11529215046068469760ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)14411518807585587200ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)18014398509481984000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)11258999068426240000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)14073748835532800000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)17592186044416000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)10995116277760000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)13743895347200000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)17179869184000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)10737418240000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)13421772800000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)16777216000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)10485760000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)13107200000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)16384000000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)10240000000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)12800000000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)16000000000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)10000000000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)12500000000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)15625000000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)9765625000000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)12207031250000000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)15258789062500000000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)9536743164062500000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)11920928955078125000ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)14901161193847656250ull), .lo_0 = ((NU64)0u)}
    , {
      .hi_0 = ((NU64)9313225746154785156ull), .lo_0 = ((NU64)4611686018427387904ull)}
    , {
      .hi_0 = ((NU64)11641532182693481445ull), .lo_0 = ((NU64)5764607523034234880ull)}
    , {
      .hi_0 = ((NU64)14551915228366851806ull), .lo_0 = ((NU64)11817445422220181504ull)}
    , {
      .hi_0 = ((NU64)18189894035458564758ull), .lo_0 = ((NU64)5548434740920451072ull)}
    , {
      .hi_0 = ((NU64)11368683772161602973ull), .lo_0 = ((NU64)17302829768357445632ull)}
    , {
      .hi_0 = ((NU64)14210854715202003717ull), .lo_0 = ((NU64)7793479155164643328ull)}
    , {
      .hi_0 = ((NU64)17763568394002504646ull), .lo_0 = ((NU64)14353534962383192064ull)}
    , {
      .hi_0 = ((NU64)11102230246251565404ull), .lo_0 = ((NU64)4359273333062107136ull)}
    , {
      .hi_0 = ((NU64)13877787807814456755ull), .lo_0 = ((NU64)5449091666327633920ull)}
    , {
      .hi_0 = ((NU64)17347234759768070944ull), .lo_0 = ((NU64)2199678564482154496ull)}
    , {
      .hi_0 = ((NU64)10842021724855044340ull), .lo_0 = ((NU64)1374799102801346560ull)}
    , {
      .hi_0 = ((NU64)13552527156068805425ull), .lo_0 = ((NU64)1718498878501683200ull)}
    , {
      .hi_0 = ((NU64)16940658945086006781ull), .lo_0 = ((NU64)6759809616554491904ull)}
    , {
      .hi_0 = ((NU64)10587911840678754238ull), .lo_0 = ((NU64)6530724019560251392ull)}
    , {
      .hi_0 = ((NU64)13234889800848442797ull), .lo_0 = ((NU64)17386777061305090048ull)}
    , {
      .hi_0 = ((NU64)16543612251060553497ull), .lo_0 = ((NU64)7898413271349198848ull)}
    , {
      .hi_0 = ((NU64)10339757656912845935ull), .lo_0 = ((NU64)16465723340661719040ull)}
    , {
      .hi_0 = ((NU64)12924697071141057419ull), .lo_0 = ((NU64)15970468157399760896ull)}
    , {
      .hi_0 = ((NU64)16155871338926321774ull), .lo_0 = ((NU64)15351399178322313216ull)}
    , {
      .hi_0 = ((NU64)10097419586828951109ull), .lo_0 = ((NU64)4982938468024057856ull)}
    , {
      .hi_0 = ((NU64)12621774483536188886ull), .lo_0 = ((NU64)10840359103457460224ull)}
    , {
      .hi_0 = ((NU64)15777218104420236108ull), .lo_0 = ((NU64)4327076842467049472ull)}
    , {
      .hi_0 = ((NU64)9860761315262647567ull), .lo_0 = ((NU64)11927795063396681728ull)}
    , {
      .hi_0 = ((NU64)12325951644078309459ull), .lo_0 = ((NU64)10298057810818464256ull)}
    , {
      .hi_0 = ((NU64)15407439555097886824ull), .lo_0 = ((NU64)8260886245095692416ull)}
    , {
      .hi_0 = ((NU64)9629649721936179265ull), .lo_0 = ((NU64)5163053903184807760ull)}
    , {
      .hi_0 = ((NU64)12037062152420224081ull), .lo_0 = ((NU64)11065503397408397604ull)}
    , {
      .hi_0 = ((NU64)15046327690525280101ull), .lo_0 = ((NU64)18443565265187884909ull)}
    , {
      .hi_0 = ((NU64)9403954806578300063ull), .lo_0 = ((NU64)13833071299956122020ull)}
    , {
      .hi_0 = ((NU64)11754943508222875079ull), .lo_0 = ((NU64)12679653106517764621ull)}
    , {
      .hi_0 = ((NU64)14693679385278593849ull), .lo_0 = ((NU64)11237880364719817872ull)}
    , {
      .hi_0 = ((NU64)18367099231598242312ull), .lo_0 = ((NU64)212292400617608628ull)}
    , {
      .hi_0 = ((NU64)11479437019748901445ull), .lo_0 = ((NU64)132682750386005392ull)}
    , {
      .hi_0 = ((NU64)14349296274686126806ull), .lo_0 = ((NU64)4777539456409894645ull)}
    , {
      .hi_0 = ((NU64)17936620343357658507ull), .lo_0 = ((NU64)15195296357367144114ull)}
    , {
      .hi_0 = ((NU64)11210387714598536567ull), .lo_0 = ((NU64)7191217214140771119ull)}
    , {
      .hi_0 = ((NU64)14012984643248170709ull), .lo_0 = ((NU64)4377335499248575995ull)}
    , {
      .hi_0 = ((NU64)17516230804060213386ull), .lo_0 = ((NU64)10083355392488107898ull)}
    , {
      .hi_0 = ((NU64)10947644252537633366ull), .lo_0 = ((NU64)10913783138732455340ull)}
    , {
      .hi_0 = ((NU64)13684555315672041708ull), .lo_0 = ((NU64)4418856886560793367ull)}
    , {
      .hi_0 = ((NU64)17105694144590052135ull), .lo_0 = ((NU64)5523571108200991709ull)}
    , {
      .hi_0 = ((NU64)10691058840368782584ull), .lo_0 = ((NU64)10369760970266701674ull)}
    , {
      .hi_0 = ((NU64)13363823550460978230ull), .lo_0 = ((NU64)12962201212833377092ull)}
    , {
      .hi_0 = ((NU64)16704779438076222788ull), .lo_0 = ((NU64)6979379479186945558ull)}
    , {
      .hi_0 = ((NU64)10440487148797639242ull), .lo_0 = ((NU64)13585484211346616781ull)}
    , {
      .hi_0 = ((NU64)13050608935997049053ull), .lo_0 = ((NU64)7758483227328495169ull)}
    , {
      .hi_0 = ((NU64)16313261169996311316ull), .lo_0 = ((NU64)14309790052588006865ull)}
    , {
      .hi_0 = ((NU64)10195788231247694572ull), .lo_0 = ((NU64)18166990819722280098ull)}
    , {
      .hi_0 = ((NU64)12744735289059618216ull), .lo_0 = ((NU64)4261994450943298507ull)}
    , {
      .hi_0 = ((NU64)15930919111324522770ull), .lo_0 = ((NU64)5327493063679123134ull)}
    , {
      .hi_0 = ((NU64)9956824444577826731ull), .lo_0 = ((NU64)7941369183226839863ull)}
    , {
      .hi_0 = ((NU64)12446030555722283414ull), .lo_0 = ((NU64)5315025460606161924ull)}
    , {
      .hi_0 = ((NU64)15557538194652854267ull), .lo_0 = ((NU64)15867153862612478214ull)}
    , {
      .hi_0 = ((NU64)9723461371658033917ull), .lo_0 = ((NU64)7611128154919104931ull)}
    , {
      .hi_0 = ((NU64)12154326714572542396ull), .lo_0 = ((NU64)14125596212076269068ull)}
    , {
      .hi_0 = ((NU64)15192908393215677995ull), .lo_0 = ((NU64)17656995265095336336ull)}
    , {
      .hi_0 = ((NU64)9495567745759798747ull), .lo_0 = ((NU64)8729779031470891258ull)}
    , {
      .hi_0 = ((NU64)11869459682199748434ull), .lo_0 = ((NU64)6300537770911226168ull)}
    , {
      .hi_0 = ((NU64)14836824602749685542ull), .lo_0 = ((NU64)17099044250493808518ull)}
    , {
      .hi_0 = ((NU64)9273015376718553464ull), .lo_0 = ((NU64)6075216638131242420ull)}
    , {
      .hi_0 = ((NU64)11591269220898191830ull), .lo_0 = ((NU64)7594020797664053025ull)}
    , {
      .hi_0 = ((NU64)14489086526122739788ull), .lo_0 = ((NU64)269153960225290473ull)}
    , {
      .hi_0 = ((NU64)18111358157653424735ull), .lo_0 = ((NU64)336442450281613091ull)}
    , {
      .hi_0 = ((NU64)11319598848533390459ull), .lo_0 = ((NU64)7127805559067090038ull)}
    , {
      .hi_0 = ((NU64)14149498560666738074ull), .lo_0 = ((NU64)4298070930406474644ull)}
    , {
      .hi_0 = ((NU64)17686873200833422592ull), .lo_0 = ((NU64)14595960699862869113ull)}
    , {
      .hi_0 = ((NU64)11054295750520889120ull), .lo_0 = ((NU64)9122475437414293195ull)}
    , {
      .hi_0 = ((NU64)13817869688151111400ull), .lo_0 = ((NU64)11403094296767866494ull)}
    , {
      .hi_0 = ((NU64)17272337110188889250ull), .lo_0 = ((NU64)14253867870959833118ull)}
    , {
      .hi_0 = ((NU64)10795210693868055781ull), .lo_0 = ((NU64)13520353437777283602ull)}
    , {
      .hi_0 = ((NU64)13494013367335069727ull), .lo_0 = ((NU64)3065383741939440791ull)}
    , {
      .hi_0 = ((NU64)16867516709168837158ull), .lo_0 = ((NU64)17666787732706464701ull)}
    , {
      .hi_0 = ((NU64)10542197943230523224ull), .lo_0 = ((NU64)6430056314514152534ull)}
    , {
      .hi_0 = ((NU64)13177747429038154030ull), .lo_0 = ((NU64)8037570393142690668ull)}
    , {
      .hi_0 = ((NU64)16472184286297692538ull), .lo_0 = ((NU64)823590954573587527ull)}
    , {
      .hi_0 = ((NU64)10295115178936057836ull), .lo_0 = ((NU64)5126430365035880108ull)}
    , {
      .hi_0 = ((NU64)12868893973670072295ull), .lo_0 = ((NU64)6408037956294850135ull)}
    , {
      .hi_0 = ((NU64)16086117467087590369ull), .lo_0 = ((NU64)3398361426941174765ull)}
    , {
      .hi_0 = ((NU64)10053823416929743980ull), .lo_0 = ((NU64)13653190937906703988ull)}
    , {
      .hi_0 = ((NU64)12567279271162179975ull), .lo_0 = ((NU64)17066488672383379985ull)}
    , {
      .hi_0 = ((NU64)15709099088952724969ull), .lo_0 = ((NU64)16721424822051837077ull)}
    , {
      .hi_0 = ((NU64)9818186930595453106ull), .lo_0 = ((NU64)3533361486141316317ull)}
    , {
      .hi_0 = ((NU64)12272733663244316382ull), .lo_0 = ((NU64)13640073894531421205ull)}
    , {
      .hi_0 = ((NU64)15340917079055395478ull), .lo_0 = ((NU64)7826720331309500698ull)}
    , {
      .hi_0 = ((NU64)9588073174409622174ull), .lo_0 = ((NU64)280014188641050032ull)}
    , {
      .hi_0 = ((NU64)11985091468012027717ull), .lo_0 = ((NU64)9573389772656088348ull)}
    , {
      .hi_0 = ((NU64)14981364335015034646ull), .lo_0 = ((NU64)16578423234247498339ull)}
    , {
      .hi_0 = ((NU64)9363352709384396654ull), .lo_0 = ((NU64)5749828502977298558ull)}
    , {
      .hi_0 = ((NU64)11704190886730495817ull), .lo_0 = ((NU64)16410657665576399005ull)}
    , {
      .hi_0 = ((NU64)14630238608413119772ull), .lo_0 = ((NU64)6678264026688335045ull)}
    , {
      .hi_0 = ((NU64)18287798260516399715ull), .lo_0 = ((NU64)8347830033360418806ull)}
    , {
      .hi_0 = ((NU64)11429873912822749822ull), .lo_0 = ((NU64)2911550761636567802ull)}
    , {
      .hi_0 = ((NU64)14287342391028437277ull), .lo_0 = ((NU64)12862810488900485560ull)}
    , {
      .hi_0 = ((NU64)17859177988785546597ull), .lo_0 = ((NU64)2243455055843443238ull)}
    , {
      .hi_0 = ((NU64)11161986242990966623ull), .lo_0 = ((NU64)3708002419115845976ull)}
    , {
      .hi_0 = ((NU64)13952482803738708279ull), .lo_0 = ((NU64)23317005467419566ull)}
    , {
      .hi_0 = ((NU64)17440603504673385348ull), .lo_0 = ((NU64)13864204312116438170ull)}
    , {
      .hi_0 = ((NU64)10900377190420865842ull), .lo_0 = ((NU64)17888499731927549664ull)}
    , {
      .hi_0 = ((NU64)13625471488026082303ull), .lo_0 = ((NU64)13137252628054661272ull)}
    , {
      .hi_0 = ((NU64)17031839360032602879ull), .lo_0 = ((NU64)11809879766640938686ull)}
    , {
      .hi_0 = ((NU64)10644899600020376799ull), .lo_0 = ((NU64)14298703881791668535ull)}
    , {
      .hi_0 = ((NU64)13306124500025470999ull), .lo_0 = ((NU64)13261693833812197764ull)}
    , {
      .hi_0 = ((NU64)16632655625031838749ull), .lo_0 = ((NU64)11965431273837859301ull)}
    , {
      .hi_0 = ((NU64)10395409765644899218ull), .lo_0 = ((NU64)9784237555362356015ull)}
    , {
      .hi_0 = ((NU64)12994262207056124023ull), .lo_0 = ((NU64)3006924907348169211ull)}
    , {
      .hi_0 = ((NU64)16242827758820155028ull), .lo_0 = ((NU64)17593714189467375226ull)}
    , {
      .hi_0 = ((NU64)10151767349262596893ull), .lo_0 = ((NU64)1772699331562333708ull)}
    , {
      .hi_0 = ((NU64)12689709186578246116ull), .lo_0 = ((NU64)6827560182880305039ull)}
    , {
      .hi_0 = ((NU64)15862136483222807645ull), .lo_0 = ((NU64)8534450228600381299ull)}
    , {
      .hi_0 = ((NU64)9913835302014254778ull), .lo_0 = ((NU64)7639874402088932264ull)}
    , {
      .hi_0 = ((NU64)12392294127517818473ull), .lo_0 = ((NU64)326470965756389522ull)}
    , {
      .hi_0 = ((NU64)15490367659397273091ull), .lo_0 = ((NU64)5019774725622874806ull)}
    , {
      .hi_0 = ((NU64)9681479787123295682ull), .lo_0 = ((NU64)831516194300602802ull)}
    , {
      .hi_0 = ((NU64)12101849733904119602ull), .lo_0 = ((NU64)10262767279730529310ull)}
    , {
      .hi_0 = ((NU64)15127312167380149503ull), .lo_0 = ((NU64)3605087062808385830ull)}
    , {
      .hi_0 = ((NU64)9454570104612593439ull), .lo_0 = ((NU64)9170708441896323000ull)}
    , {
      .hi_0 = ((NU64)11818212630765741799ull), .lo_0 = ((NU64)6851699533943015846ull)}
    , {
      .hi_0 = ((NU64)14772765788457177249ull), .lo_0 = ((NU64)3952938399001381903ull)}
    , {
      .hi_0 = ((NU64)9232978617785735780ull), .lo_0 = ((NU64)13999801545444333449ull)}
    , {
      .hi_0 = ((NU64)11541223272232169725ull), .lo_0 = ((NU64)17499751931805416812ull)}
    , {
      .hi_0 = ((NU64)14426529090290212157ull), .lo_0 = ((NU64)8039631859474607303ull)}
    , {
      .hi_0 = ((NU64)18033161362862765196ull), .lo_0 = ((NU64)14661225842770647033ull)}
    , {
      .hi_0 = ((NU64)11270725851789228247ull), .lo_0 = ((NU64)18386638188586430203ull)}
    , {
      .hi_0 = ((NU64)14088407314736535309ull), .lo_0 = ((NU64)18371611717305649850ull)}
    , {
      .hi_0 = ((NU64)17610509143420669137ull), .lo_0 = ((NU64)9129456591349898601ull)}
    , {
      .hi_0 = ((NU64)11006568214637918210ull), .lo_0 = ((NU64)17235125415662156385ull)}
    , {
      .hi_0 = ((NU64)13758210268297397763ull), .lo_0 = ((NU64)12320534732722919674ull)}
    , {
      .hi_0 = ((NU64)17197762835371747204ull), .lo_0 = ((NU64)10788982397476261688ull)}
    , {
      .hi_0 = ((NU64)10748601772107342002ull), .lo_0 = ((NU64)15966486035277439363ull)}
    , {
      .hi_0 = ((NU64)13435752215134177503ull), .lo_0 = ((NU64)10734735507242023396ull)}
    , {
      .hi_0 = ((NU64)16794690268917721879ull), .lo_0 = ((NU64)8806733365625141341ull)}
    , {
      .hi_0 = ((NU64)10496681418073576174ull), .lo_0 = ((NU64)12421737381156795194ull)}
    , {
      .hi_0 = ((NU64)13120851772591970218ull), .lo_0 = ((NU64)6303799689591218185ull)}
    , {
      .hi_0 = ((NU64)16401064715739962772ull), .lo_0 = ((NU64)17103121648843798539ull)}
    , {
      .hi_0 = ((NU64)10250665447337476733ull), .lo_0 = ((NU64)1466078993672598279ull)}
    , {
      .hi_0 = ((NU64)12813331809171845916ull), .lo_0 = ((NU64)6444284760518135752ull)}
    , {
      .hi_0 = ((NU64)16016664761464807395ull), .lo_0 = ((NU64)8055355950647669691ull)}
    , {
      .hi_0 = ((NU64)10010415475915504622ull), .lo_0 = ((NU64)2728754459941099604ull)}
    , {
      .hi_0 = ((NU64)12513019344894380777ull), .lo_0 = ((NU64)12634315111781150314ull)}
    , {
      .hi_0 = ((NU64)15641274181117975972ull), .lo_0 = ((NU64)1957835834444274180ull)}
    , {
      .hi_0 = ((NU64)9775796363198734982ull), .lo_0 = ((NU64)10447019433382447170ull)}
    , {
      .hi_0 = ((NU64)12219745453998418728ull), .lo_0 = ((NU64)3835402254873283155ull)}
    , {
      .hi_0 = ((NU64)15274681817498023410ull), .lo_0 = ((NU64)4794252818591603944ull)}
    , {
      .hi_0 = ((NU64)9546676135936264631ull), .lo_0 = ((NU64)7608094030047140369ull)}
    , {
      .hi_0 = ((NU64)11933345169920330789ull), .lo_0 = ((NU64)4898431519131537557ull)}
    , {
      .hi_0 = ((NU64)14916681462400413486ull), .lo_0 = ((NU64)10734725417341809851ull)}
    , {
      .hi_0 = ((NU64)9322925914000258429ull), .lo_0 = ((NU64)2097517367411243253ull)}
    , {
      .hi_0 = ((NU64)11653657392500323036ull), .lo_0 = ((NU64)7233582727691441970ull)}
    , {
      .hi_0 = ((NU64)14567071740625403795ull), .lo_0 = ((NU64)9041978409614302462ull)}
    , {
      .hi_0 = ((NU64)18208839675781754744ull), .lo_0 = ((NU64)6690786993590490174ull)}
    , {
      .hi_0 = ((NU64)11380524797363596715ull), .lo_0 = ((NU64)4181741870994056359ull)}
    , {
      .hi_0 = ((NU64)14225655996704495894ull), .lo_0 = ((NU64)615491320315182544ull)}
    , {
      .hi_0 = ((NU64)17782069995880619867ull), .lo_0 = ((NU64)9992736187248753989ull)}
    , {
      .hi_0 = ((NU64)11113793747425387417ull), .lo_0 = ((NU64)3939617107816777291ull)}
    , {
      .hi_0 = ((NU64)13892242184281734271ull), .lo_0 = ((NU64)9536207403198359517ull)}
    , {
      .hi_0 = ((NU64)17365302730352167839ull), .lo_0 = ((NU64)7308573235570561493ull)}
    , {
      .hi_0 = ((NU64)10853314206470104899ull), .lo_0 = ((NU64)11485387299872682789ull)}
    , {
      .hi_0 = ((NU64)13566642758087631124ull), .lo_0 = ((NU64)9745048106413465582ull)}
    , {
      .hi_0 = ((NU64)16958303447609538905ull), .lo_0 = ((NU64)12181310133016831978ull)}
    , {
      .hi_0 = ((NU64)10598939654755961816ull), .lo_0 = ((NU64)695789805494438130ull)}
    , {
      .hi_0 = ((NU64)13248674568444952270ull), .lo_0 = ((NU64)869737256868047663ull)}
    , {
      .hi_0 = ((NU64)16560843210556190337ull), .lo_0 = ((NU64)10310543607939835386ull)}
    , {
      .hi_0 = ((NU64)10350527006597618960ull), .lo_0 = ((NU64)17973304801030866876ull)}
    , {
      .hi_0 = ((NU64)12938158758247023701ull), .lo_0 = ((NU64)4019886927579031980ull)}
    , {
      .hi_0 = ((NU64)16172698447808779626ull), .lo_0 = ((NU64)9636544677901177879ull)}
    , {
      .hi_0 = ((NU64)10107936529880487266ull), .lo_0 = ((NU64)10634526442115624078ull)}
    , {
      .hi_0 = ((NU64)12634920662350609083ull), .lo_0 = ((NU64)4069786015789754290ull)}
    , {
      .hi_0 = ((NU64)15793650827938261354ull), .lo_0 = ((NU64)475546501309804958ull)}
    , {
      .hi_0 = ((NU64)9871031767461413346ull), .lo_0 = ((NU64)4908902581746016003ull)}
    , {
      .hi_0 = ((NU64)12338789709326766682ull), .lo_0 = ((NU64)15359500264037295811ull)}
    , {
      .hi_0 = ((NU64)15423487136658458353ull), .lo_0 = ((NU64)9976003293191843956ull)}
    , {
      .hi_0 = ((NU64)9639679460411536470ull), .lo_0 = ((NU64)17764217104313372233ull)}
    , {
      .hi_0 = ((NU64)12049599325514420588ull), .lo_0 = ((NU64)12981899343536939483ull)}
    , {
      .hi_0 = ((NU64)15061999156893025735ull), .lo_0 = ((NU64)16227374179421174354ull)}
    , {
      .hi_0 = ((NU64)9413749473058141084ull), .lo_0 = ((NU64)17059637889779315827ull)}
    , {
      .hi_0 = ((NU64)11767186841322676356ull), .lo_0 = ((NU64)2877803288514593168ull)}
    , {
      .hi_0 = ((NU64)14708983551653345445ull), .lo_0 = ((NU64)3597254110643241460ull)}
    , {
      .hi_0 = ((NU64)18386229439566681806ull), .lo_0 = ((NU64)9108253656731439729ull)}
    , {
      .hi_0 = ((NU64)11491393399729176129ull), .lo_0 = ((NU64)1080972517029761926ull)}
    , {
      .hi_0 = ((NU64)14364241749661470161ull), .lo_0 = ((NU64)5962901664714590312ull)}
    , {
      .hi_0 = ((NU64)17955302187076837701ull), .lo_0 = ((NU64)12065313099320625794ull)}
    , {
      .hi_0 = ((NU64)11222063866923023563ull), .lo_0 = ((NU64)9846663696289085073ull)}
    , {
      .hi_0 = ((NU64)14027579833653779454ull), .lo_0 = ((NU64)7696643601933968437ull)}
    , {
      .hi_0 = ((NU64)17534474792067224318ull), .lo_0 = ((NU64)397432465562684739ull)}
    , {
      .hi_0 = ((NU64)10959046745042015198ull), .lo_0 = ((NU64)14083453346258841674ull)}
    , {
      .hi_0 = ((NU64)13698808431302518998ull), .lo_0 = ((NU64)8380944645968776284ull)}
    , {
      .hi_0 = ((NU64)17123510539128148748ull), .lo_0 = ((NU64)1252808770606194547ull)}
    , {
      .hi_0 = ((NU64)10702194086955092967ull), .lo_0 = ((NU64)10006377518483647400ull)}
    , {
      .hi_0 = ((NU64)13377742608693866209ull), .lo_0 = ((NU64)7896285879677171346ull)}
    , {
      .hi_0 = ((NU64)16722178260867332761ull), .lo_0 = ((NU64)14482043368023852087ull)}
    , {
      .hi_0 = ((NU64)10451361413042082976ull), .lo_0 = ((NU64)2133748077373825698ull)}
    , {
      .hi_0 = ((NU64)13064201766302603720ull), .lo_0 = ((NU64)2667185096717282123ull)}
    , {
      .hi_0 = ((NU64)16330252207878254650ull), .lo_0 = ((NU64)3333981370896602653ull)}
    , {
      .hi_0 = ((NU64)10206407629923909156ull), .lo_0 = ((NU64)6695424375237764562ull)}
    , {
      .hi_0 = ((NU64)12758009537404886445ull), .lo_0 = ((NU64)8369280469047205703ull)}
    , {
      .hi_0 = ((NU64)15947511921756108056ull), .lo_0 = ((NU64)15073286604736395033ull)}
    , {
      .hi_0 = ((NU64)9967194951097567535ull), .lo_0 = ((NU64)9420804127960246895ull)}
    , {
      .hi_0 = ((NU64)12458993688871959419ull), .lo_0 = ((NU64)7164319141522920715ull)}
    , {
      .hi_0 = ((NU64)15573742111089949274ull), .lo_0 = ((NU64)4343712908476262990ull)}
    , {
      .hi_0 = ((NU64)9733588819431218296ull), .lo_0 = ((NU64)7326506586225052273ull)}
    , {
      .hi_0 = ((NU64)12166986024289022870ull), .lo_0 = ((NU64)9158133232781315341ull)}
    , {
      .hi_0 = ((NU64)15208732530361278588ull), .lo_0 = ((NU64)2224294504121868368ull)}
    , {
      .hi_0 = ((NU64)9505457831475799117ull), .lo_0 = ((NU64)10613556101930943538ull)}
    , {
      .hi_0 = ((NU64)11881822289344748896ull), .lo_0 = ((NU64)17878631145841067327ull)}
    , {
      .hi_0 = ((NU64)14852277861680936121ull), .lo_0 = ((NU64)3901544858591782542ull)}
    , {
      .hi_0 = ((NU64)9282673663550585075ull), .lo_0 = ((NU64)13967680582688333849ull)}
    , {
      .hi_0 = ((NU64)11603342079438231344ull), .lo_0 = ((NU64)12847914709933029407ull)}
    , {
      .hi_0 = ((NU64)14504177599297789180ull), .lo_0 = ((NU64)16059893387416286759ull)}
    , {
      .hi_0 = ((NU64)18130221999122236476ull), .lo_0 = ((NU64)1628122660560806833ull)}
    , {
      .hi_0 = ((NU64)11331388749451397797ull), .lo_0 = ((NU64)10240948699705280078ull)}
    , {
      .hi_0 = ((NU64)14164235936814247246ull), .lo_0 = ((NU64)17412871893058988002ull)}
    , {
      .hi_0 = ((NU64)17705294921017809058ull), .lo_0 = ((NU64)12542717829468959195ull)}
    , {
      .hi_0 = ((NU64)11065809325636130661ull), .lo_0 = ((NU64)12450884661845487401ull)}
    , {
      .hi_0 = ((NU64)13832261657045163327ull), .lo_0 = ((NU64)1728547772024695539ull)}
    , {
      .hi_0 = ((NU64)17290327071306454158ull), .lo_0 = ((NU64)15995742770313033136ull)}
    , {
      .hi_0 = ((NU64)10806454419566533849ull), .lo_0 = ((NU64)5385653213018257806ull)}
    , {
      .hi_0 = ((NU64)13508068024458167311ull), .lo_0 = ((NU64)11343752534700210161ull)}
    , {
      .hi_0 = ((NU64)16885085030572709139ull), .lo_0 = ((NU64)9568004649947874797ull)}
    , {
      .hi_0 = ((NU64)10553178144107943212ull), .lo_0 = ((NU64)3674159897003727796ull)}
    , {
      .hi_0 = ((NU64)13191472680134929015ull), .lo_0 = ((NU64)4592699871254659745ull)}
    , {
      .hi_0 = ((NU64)16489340850168661269ull), .lo_0 = ((NU64)1129188820640936778ull)}
    , {
      .hi_0 = ((NU64)10305838031355413293ull), .lo_0 = ((NU64)3011586022114279438ull)}
    , {
      .hi_0 = ((NU64)12882297539194266616ull), .lo_0 = ((NU64)8376168546070237202ull)}
    , {
      .hi_0 = ((NU64)16102871923992833270ull), .lo_0 = ((NU64)10470210682587796502ull)}
    , {
      .hi_0 = ((NU64)10064294952495520794ull), .lo_0 = ((NU64)1932195658189984910ull)}
    , {
      .hi_0 = ((NU64)12580368690619400992ull), .lo_0 = ((NU64)11638616609592256945ull)}
    , {
      .hi_0 = ((NU64)15725460863274251240ull), .lo_0 = ((NU64)14548270761990321182ull)}
    , {
      .hi_0 = ((NU64)9828413039546407025ull), .lo_0 = ((NU64)9092669226243950738ull)}
    , {
      .hi_0 = ((NU64)12285516299433008781ull), .lo_0 = ((NU64)15977522551232326327ull)}
    , {
      .hi_0 = ((NU64)15356895374291260977ull), .lo_0 = ((NU64)6136845133758244197ull)}
    , {
      .hi_0 = ((NU64)9598059608932038110ull), .lo_0 = ((NU64)15364743254667372383ull)}
    , {
      .hi_0 = ((NU64)11997574511165047638ull), .lo_0 = ((NU64)9982557031479439671ull)}
    , {
      .hi_0 = ((NU64)14996968138956309548ull), .lo_0 = ((NU64)3254824252494523781ull)}
    , {
      .hi_0 = ((NU64)9373105086847693467ull), .lo_0 = ((NU64)11257637194663853171ull)}
    , {
      .hi_0 = ((NU64)11716381358559616834ull), .lo_0 = ((NU64)9460360474902428559ull)}
    , {
      .hi_0 = ((NU64)14645476698199521043ull), .lo_0 = ((NU64)2602078556773259891ull)}
    , {
      .hi_0 = ((NU64)18306845872749401303ull), .lo_0 = ((NU64)17087656251248738576ull)}
    , {
      .hi_0 = ((NU64)11441778670468375814ull), .lo_0 = ((NU64)17597314184671543466ull)}
    , {
      .hi_0 = ((NU64)14302223338085469768ull), .lo_0 = ((NU64)12773270693984653525ull)}
    , {
      .hi_0 = ((NU64)17877779172606837210ull), .lo_0 = ((NU64)15966588367480816906ull)}
    , {
      .hi_0 = ((NU64)11173611982879273256ull), .lo_0 = ((NU64)14590803748102898470ull)}
    , {
      .hi_0 = ((NU64)13967014978599091570ull), .lo_0 = ((NU64)18238504685128623088ull)}
    , {
      .hi_0 = ((NU64)17458768723248864463ull), .lo_0 = ((NU64)13574758819556003052ull)}
    , {
      .hi_0 = ((NU64)10911730452030540289ull), .lo_0 = ((NU64)15401753289863583763ull)}
    , {
      .hi_0 = ((NU64)13639663065038175362ull), .lo_0 = ((NU64)5417133557047315992ull)}
    , {
      .hi_0 = ((NU64)17049578831297719202ull), .lo_0 = ((NU64)15994788983163920798ull)}
    , {
      .hi_0 = ((NU64)10655986769561074501ull), .lo_0 = ((NU64)14608429132904838403ull)}
    , {
      .hi_0 = ((NU64)13319983461951343127ull), .lo_0 = ((NU64)4425478360848884291ull)}
    , {
      .hi_0 = ((NU64)16649979327439178909ull), .lo_0 = ((NU64)920161932633717460ull)}
    , {
      .hi_0 = ((NU64)10406237079649486818ull), .lo_0 = ((NU64)2880944217109767365ull)}
    , {
      .hi_0 = ((NU64)13007796349561858522ull), .lo_0 = ((NU64)12824552308241985014ull)}
    , {
      .hi_0 = ((NU64)16259745436952323153ull), .lo_0 = ((NU64)6807318348447705459ull)}
    , {
      .hi_0 = ((NU64)10162340898095201970ull), .lo_0 = ((NU64)15783789013848285672ull)}
    , {
      .hi_0 = ((NU64)12702926122619002463ull), .lo_0 = ((NU64)10506364230455581282ull)}
    , {
      .hi_0 = ((NU64)15878657653273753079ull), .lo_0 = ((NU64)8521269269642088699ull)}
    , {
      .hi_0 = ((NU64)9924161033296095674ull), .lo_0 = ((NU64)12243322321167387293ull)}
    , {
      .hi_0 = ((NU64)12405201291620119593ull), .lo_0 = ((NU64)6080780864604458308ull)}
    , {
      .hi_0 = ((NU64)15506501614525149491ull), .lo_0 = ((NU64)12212662099182960789ull)}
    , {
      .hi_0 = ((NU64)9691563509078218432ull), .lo_0 = ((NU64)5327070802775656541ull)}
    , {
      .hi_0 = ((NU64)12114454386347773040ull), .lo_0 = ((NU64)6658838503469570676ull)}
    , {
      .hi_0 = ((NU64)15143067982934716300ull), .lo_0 = ((NU64)8323548129336963345ull)}
    , {
      .hi_0 = ((NU64)9464417489334197687ull), .lo_0 = ((NU64)14425589617690377899ull)}
    , {
      .hi_0 = ((NU64)11830521861667747109ull), .lo_0 = ((NU64)13420301003685584469ull)}
    , {
      .hi_0 = ((NU64)14788152327084683887ull), .lo_0 = ((NU64)2940318199324816875ull)}
    , {
      .hi_0 = ((NU64)9242595204427927429ull), .lo_0 = ((NU64)8755227902219092403ull)}
    , {
      .hi_0 = ((NU64)11553244005534909286ull), .lo_0 = ((NU64)15555720896201253407ull)}
    , {
      .hi_0 = ((NU64)14441555006918636608ull), .lo_0 = ((NU64)10221279083396790951ull)}
    , {
      .hi_0 = ((NU64)18051943758648295760ull), .lo_0 = ((NU64)12776598854245988689ull)}
    , {
      .hi_0 = ((NU64)11282464849155184850ull), .lo_0 = ((NU64)7985374283903742931ull)}
    , {
      .hi_0 = ((NU64)14103081061443981063ull), .lo_0 = ((NU64)758345818024902856ull)}
    , {
      .hi_0 = ((NU64)17628851326804976328ull), .lo_0 = ((NU64)14782990327813292282ull)}
    , {
      .hi_0 = ((NU64)11018032079253110205ull), .lo_0 = ((NU64)9239368954883307676ull)}
    , {
      .hi_0 = ((NU64)13772540099066387756ull), .lo_0 = ((NU64)16160897212031522499ull)}
    , {
      .hi_0 = ((NU64)17215675123832984696ull), .lo_0 = ((NU64)1754377441329851508ull)}
    , {
      .hi_0 = ((NU64)10759796952395615435ull), .lo_0 = ((NU64)1096485900831157192ull)}
    , {
      .hi_0 = ((NU64)13449746190494519293ull), .lo_0 = ((NU64)15205665431321110202ull)}
    , {
      .hi_0 = ((NU64)16812182738118149117ull), .lo_0 = ((NU64)5172023733869224041ull)}
    , {
      .hi_0 = ((NU64)10507614211323843198ull), .lo_0 = ((NU64)5538357842881958977ull)}
    , {
      .hi_0 = ((NU64)13134517764154803997ull), .lo_0 = ((NU64)16146319340457224530ull)}
    , {
      .hi_0 = ((NU64)16418147205193504997ull), .lo_0 = ((NU64)6347841120289366950ull)}
    , {
      .hi_0 = ((NU64)10261342003245940623ull), .lo_0 = ((NU64)6273243709394548296ull)}
    , {
      .hi_0 = ((NU64)12826677504057425779ull), .lo_0 = ((NU64)3229868618315797466ull)}
    , {
      .hi_0 = ((NU64)16033346880071782223ull), .lo_0 = ((NU64)17872393828176910545ull)}
    , {
      .hi_0 = ((NU64)10020841800044863889ull), .lo_0 = ((NU64)18087775170251650946ull)}
    , {
      .hi_0 = ((NU64)12526052250056079862ull), .lo_0 = ((NU64)8774660907532399971ull)}
    , {
      .hi_0 = ((NU64)15657565312570099828ull), .lo_0 = ((NU64)1744954097560724156ull)}
    , {
      .hi_0 = ((NU64)9785978320356312392ull), .lo_0 = ((NU64)10313968347830228405ull)}
    , {
      .hi_0 = ((NU64)12232472900445390490ull), .lo_0 = ((NU64)12892460434787785506ull)}
    , {
      .hi_0 = ((NU64)15290591125556738113ull), .lo_0 = ((NU64)6892203506629956075ull)}
    , {
      .hi_0 = ((NU64)9556619453472961320ull), .lo_0 = ((NU64)15836842237712192307ull)}
    , {
      .hi_0 = ((NU64)11945774316841201651ull), .lo_0 = ((NU64)1349308723430688768ull)}
    , {
      .hi_0 = ((NU64)14932217896051502063ull), .lo_0 = ((NU64)15521693959570524672ull)}
    , {
      .hi_0 = ((NU64)9332636185032188789ull), .lo_0 = ((NU64)16618587752372659776ull)}
    , {
      .hi_0 = ((NU64)11665795231290235987ull), .lo_0 = ((NU64)6938176635183661008ull)}
    , {
      .hi_0 = ((NU64)14582244039112794984ull), .lo_0 = ((NU64)4061034775552188356ull)}
    , {
      .hi_0 = ((NU64)18227805048890993730ull), .lo_0 = ((NU64)5076293469440235445ull)}
    , {
      .hi_0 = ((NU64)11392378155556871081ull), .lo_0 = ((NU64)7784369436827535057ull)}
    , {
      .hi_0 = ((NU64)14240472694446088851ull), .lo_0 = ((NU64)14342147814461806725ull)}
    , {
      .hi_0 = ((NU64)17800590868057611064ull), .lo_0 = ((NU64)13315998749649870503ull)}}}
;
static X60Qt_0_IAarraySX4dulX43mp0sysvq0aslS25_sysvq0asl const mod5_0 = {
  .a = {
    {
      .mul_0 = ((NU64)1u), .cmp_0 = ((NU64)18446744073709551615ull)}
    , {
      .mul_0 = ((NU64)14757395258967641293ull), .cmp_0 = ((NU64)3689348814741910323ull)}
    , {
      .mul_0 = ((NU64)10330176681277348905ull), .cmp_0 = ((NU64)737869762948382064ull)}
    , {
      .mul_0 = ((NU64)2066035336255469781ull), .cmp_0 = ((NU64)147573952589676412ull)}
    , {
      .mul_0 = ((NU64)15170602326218735249ull), .cmp_0 = ((NU64)29514790517935282ull)}
    , {
      .mul_0 = ((NU64)6723469279985657373ull), .cmp_0 = ((NU64)5902958103587056ull)}
    , {
      .mul_0 = ((NU64)8723391485480952121ull), .cmp_0 = ((NU64)1180591620717411ull)}
    , {
      .mul_0 = ((NU64)16502073556063831717ull), .cmp_0 = ((NU64)236118324143482ull)}
    , {
      .mul_0 = ((NU64)14368461155438497313ull), .cmp_0 = ((NU64)47223664828696ull)}
    , {
      .mul_0 = ((NU64)10252389860571520109ull), .cmp_0 = ((NU64)9444732965739ull)}
    , {
      .mul_0 = ((NU64)5739826786856214345ull), .cmp_0 = ((NU64)1888946593147ull)}
    , {
      .mul_0 = ((NU64)1147965357371242869ull), .cmp_0 = ((NU64)377789318629ull)}
    , {
      .mul_0 = ((NU64)3918941886216158897ull), .cmp_0 = ((NU64)75557863725ull)}
    , {
      .mul_0 = ((NU64)11851834821468962749ull), .cmp_0 = ((NU64)15111572745ull)}
    , {
      .mul_0 = ((NU64)6059715779035702873ull), .cmp_0 = ((NU64)3022314549u)}
    , {
      .mul_0 = ((NU64)8590640785290961221ull), .cmp_0 = ((NU64)604462909u)}
    , {
      .mul_0 = ((NU64)16475523416025833537ull), .cmp_0 = ((NU64)120892581u)}
    , {
      .mul_0 = ((NU64)14363151127430897677ull), .cmp_0 = ((NU64)24178516u)}
    , {
      .mul_0 = ((NU64)13940676669711910505ull), .cmp_0 = ((NU64)4835703u)}
    , {
      .mul_0 = ((NU64)2788135333942382101ull), .cmp_0 = ((NU64)967140u)}
    , {
      .mul_0 = ((NU64)15315022325756117713ull), .cmp_0 = ((NU64)193428u)}
    , {
      .mul_0 = ((NU64)10441702094635044189ull), .cmp_0 = ((NU64)38685u)}
    , {
      .mul_0 = ((NU64)5777689233668919161ull), .cmp_0 = ((NU64)7737u)}
    , {
      .mul_0 = ((NU64)15912933105701425125ull), .cmp_0 = ((NU64)1547u)}
    , {
      .mul_0 = ((NU64)3182586621140285025ull), .cmp_0 = ((NU64)309u)}}}
;
static NI32 const P_0 = ((NI32)53);
static NI32 const kappa_0 = ((NI32)2);
static NU32 const bigDivisor_0 = ((NU32)1000u);
static NU32 const smallDivisor_0 = ((NU32)100u);
static NI32 const minFixedDecimalPoint_1 = ((NI32)-6);
static NI32 const maxFixedDecimalPoint_1 = ((NI32)17);
__thread X60Qt_0_IArefSX45xception0sysvq0asl_sysvq0asl* exc_0_sysvq0asl;
NB8 X60QiniGuard_0_sysvq0asl;
static inline NI32 min_2_sysvq0asl(NI32 x_204, NI32 y_161){
  NI32 result_5;
  NI32 X60Qx_2;
  if (x_204 <= y_161){
    X60Qx_2 = x_204;}
  else {
    X60Qx_2 = y_161;}
  result_5 = X60Qx_2;
  return result_5;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
string_0_sysvq0asl dollarQ_0_sysvq0asl(NU64 x_224){
  string_0_sysvq0asl result_19;
  nimStrWasMoved((&result_19));
  nimStrDestroy(result_19);
  result_19 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (x_224 < ((NU64)10)){
    nimStrDestroy(result_19);
    NI32 X60Qx_57 = nimIcheckB(((NI32)x_224), 9);
    string_0_sysvq0asl X60Qx_58 = substr_0_sysvq0asl(NegTen_0_sysvq0asl.a[X60Qx_57], 1, 1);
    result_19 = X60Qx_58;}
  else {
    NU64 y_208 = x_224;
    {
      while (NIM_TRUE){
        add_1_sysvq0asl((&result_19), ((NC8)((NU64)(((NU64)(y_208 % ((NU64)10u))) + ((NU64)((NU32)(NC8)'0'))))));
        y_208 = ((NU64)(y_208 / ((NU64)10u)));
        if (y_208 == ((NU64)0u)){
          goto whileStmtLabel_0;}}}
    whileStmtLabel_0: ;
    NI32 X60Qx_59 = len_4_sysvq0asl(result_19);
    NI32 last_3 = ((NI32)(X60Qx_59 - 1));
    NI32 i_25 = 0;
    NI32 X60Qx_60 = len_4_sysvq0asl(result_19);
    NI32 b_29 = ((NI32)(X60Qx_60 / 2));
    {
      while (i_25 < b_29){
        NC8 ch_1 = getQ_9_sysvq0asl(result_19, i_25);
        NC8 X60Qx_61 = getQ_9_sysvq0asl(result_19, ((NI32)(last_3 - i_25)));
        putQ_9_sysvq0asl((&result_19), i_25, X60Qx_61);
        putQ_9_sysvq0asl((&result_19), ((NI32)(last_3 - i_25)), ch_1);
        inc_1_I6wjjge_aow2h993l1((&i_25));}}
    whileStmtLabel_1: ;}
  return result_19;}
string_0_sysvq0asl dollarQ_1_sysvq0asl(NI64 x_225){
  string_0_sysvq0asl result_20;
  nimStrWasMoved((&result_20));
  if (x_225 < ((NI64)0)){
    if (((NI64)-10) < x_225){
      nimStrDestroy(result_20);
      NI32 X60Qx_62 = nimIcheckB(((NI32)((NI64)-x_225)), 9);
      string_0_sysvq0asl X60Qx_63 = nimStrDup(NegTen_0_sysvq0asl.a[X60Qx_62]);
      result_20 = X60Qx_63;}
    else {
      if (x_225 == ((NI64)(IL64(-9223372036854775807) - IL64(1)))){
        nimStrDestroy(result_20);
        string_0_sysvq0asl X60Qtmp_0 = dollarQ_0_sysvq0asl(((NU64)x_225));
        string_0_sysvq0asl X60Qx_64 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 11521u, .more_0 = NIM_NIL}
        , X60Qtmp_0);
        result_20 = X60Qx_64;
        nimStrDestroy(X60Qtmp_0);}
      else {
        nimStrDestroy(result_20);
        string_0_sysvq0asl X60Qtmp_1 = dollarQ_1_sysvq0asl(((NI64)(((NI64)0) - x_225)));
        string_0_sysvq0asl X60Qx_65 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 11521u, .more_0 = NIM_NIL}
        , X60Qtmp_1);
        result_20 = X60Qx_65;
        nimStrDestroy(X60Qtmp_1);}}}
  else {
    if (x_225 < ((NI64)10)){
      nimStrDestroy(result_20);
      result_20 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      add_1_sysvq0asl((&result_20), ((NC8)((NI64)(x_225 + ((NI64)(NC8)'0')))));}
    else {
      nimStrDestroy(result_20);
      string_0_sysvq0asl X60Qx_66 = dollarQ_0_sysvq0asl(((NU64)x_225));
      result_20 = X60Qx_66;}}
  return result_20;}
string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226){
  string_0_sysvq0asl result_21;
  nimStrWasMoved((&result_21));
  nimStrDestroy(result_21);
  string_0_sysvq0asl X60Qx_67 = dollarQ_1_sysvq0asl(((NI64)x_226));
  result_21 = X60Qx_67;
  return result_21;}
N_NIMCALL(void, nimNoopFlush_0_sysvq0asl)(void){
  }
void nimFlushStdStreams(void){
  gExitFlush_0_sysvq0asl();}
void cExit_0_sysvq0asl(NI32 code_1){
  gExitFlush_0_sysvq0asl();
  exit(((NI32)code_1));}
void cAbort_0_sysvq0asl(void){
  gExitFlush_0_sysvq0asl();
  abort();}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline NI32 cmpMem_0_sysvq0asl(void* a_5, void* b_6, NI32 size_5){
  NI32 result_29;
  int X60Qx_77 = memcmp(a_5, b_6, ((size_t)size_5));
  result_29 = X60Qx_77;
  return result_29;}
static inline void zeroMem_0_sysvq0asl(void* dest_6, NI32 size_6){
  memset(dest_6, 0, ((size_t)size_6));}
void raiseOutOfMem_0_sysvq0asl(void){
  cAbort_0_sysvq0asl();}
static inline NI32 align_0_sysvq0asl(NI32 address_0, NI32 alignment_0){
  NI32 result_30;
  result_30 = ((NI32)(((NI32)(address_0 + ((NI32)(alignment_0 - 1)))) & ((NI32) ~ ((NI32)(alignment_0 - 1)))));
  return result_30;}
static inline NI32 roundup_0_sysvq0asl(NI32 x_297, NI32 v_0){
  NI32 result_31;
  result_31 = ((NI32)(((NI32)(x_297 + ((NI32)(v_0 - 1)))) & ((NI32) ~ ((NI32)(v_0 - 1)))));
  return result_31;}
static inline void* osAllocPages_0_sysvq0asl(NI32 size_7){
  void* result_32;
  void* X60Qx_78 = mmap(NIM_NIL, ((size_t)size_7), ((int)((NI32)(((NI32)1) | ((NI32)2)))), ((int)((NI32)(((NI32)(((NI32)32) | ((NI32)2))) | ((NI32)0)))), ((int)-1), 0);
  result_32 = X60Qx_78;
  NB8 X60Qx_79;
  if (result_32 == NIM_NIL){
    X60Qx_79 = NIM_TRUE;}
  else {
    X60Qx_79 = (result_32 == ((void*)-1));}
  if (X60Qx_79){
    raiseOutOfMem_0_sysvq0asl();}
  return result_32;}
static inline void* osTryAllocPages_0_sysvq0asl(NI32 size_8){
  void* result_33;
  void* X60Qx_80 = mmap(NIM_NIL, ((size_t)size_8), ((int)((NI32)(((NI32)1) | ((NI32)2)))), ((int)((NI32)(((NI32)(((NI32)32) | ((NI32)2))) | ((NI32)0)))), ((int)-1), 0);
  result_33 = X60Qx_80;
  if (result_33 == ((void*)-1)){
    result_33 = NIM_NIL;}
  return result_33;}
static inline void osDeallocPages_0_sysvq0asl(void* p_9, NI32 size_9){
  }
static inline NI32 msbit_0_sysvq0asl(NU32 x_302){
  NI32 result_34;
  NI64 X60Qx_13;
  if (x_302 <= ((NU32)65535u)){
    NI64 X60Qx_14;
    if (x_302 <= ((NU32)255)){
      X60Qx_14 = 0;}
    else {
      X60Qx_14 = 8;}
    X60Qx_13 = X60Qx_14;}
  else {
    NI64 X60Qx_15;
    if (x_302 <= ((NU32)16777215u)){
      X60Qx_15 = 16;}
    else {
      X60Qx_15 = 24;}
    X60Qx_13 = X60Qx_15;}
  NI32 a_74 = X60Qx_13;
  NU32 X60Qx_81 = nimUcheckB(((NU8)((NU32)(x_302 >> a_74))), 255);
  result_34 = ((NI32)(((NI32)fsLookupTable_0_sysvq0asl.a[X60Qx_81]) + a_74));
  return result_34;}
static inline NI32 lsbit_0_sysvq0asl(NU32 x_303){
  NI32 result_35;
  NI32 X60Qx_82 = msbit_0_sysvq0asl(((NU32)(x_303 & ((NU32)(((NU32) ~ x_303) + ((NU32)1))))));
  result_35 = X60Qx_82;
  return result_35;}
static inline void setBit_0_sysvq0asl(NI32 nr_0, NU32* dest_7){
  (*dest_7) = ((NU32)((*dest_7) | ((NU32)(((NU32)1u) << ((NI32)(nr_0 & 31))))));}
static inline void clearBit_0_sysvq0asl(NI32 nr_1, NU32* dest_8){
  (*dest_8) = ((NU32)((*dest_8) & ((NU32) ~ ((NU32)(((NU32)1u) << ((NI32)(nr_1 & 31)))))));}
static inline void mappingSearch_0_sysvq0asl(NI32* r_0, NI32* fl_0, NI32* sl_0){
  NI32 X60Qx_83 = msbit_0_sysvq0asl(((NU32)(*r_0)));
  NI32 X60Qx_84 = roundup_0_sysvq0asl(((NI32)(1 << ((NI32)(X60Qx_83 - ((NI32)5))))), ((NI32)4096));
  NI32 t_3 = ((NI32)(X60Qx_84 - 1));
  (*r_0) = ((NI32)((*r_0) + t_3));
  (*r_0) = ((NI32)((*r_0) & ((NI32) ~ t_3)));
  NI32 X60Qx_85 = min_2_sysvq0asl((*r_0), ((NI32)1056964608));
  (*r_0) = ((NI32)X60Qx_85);
  NI32 X60Qx_86 = msbit_0_sysvq0asl(((NU32)(*r_0)));
  (*fl_0) = X60Qx_86;
  (*sl_0) = ((NI32)(((NI32)(((NI32)(*r_0)) >> ((NU32)((NI32)((*fl_0) - ((NI32)5)))))) - ((NI32)32)));
  dec_0_Ig5i8xp_nifb6mq6y1(fl_0, ((NI32)6));}
static inline X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 mappingInsert_0_sysvq0asl(NI32 r_1){
  X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 result_36;
  NI32 fl_4 = msbit_0_sysvq0asl(((NU32)r_1));
  NI32 sl_5 = ((NI32)(((NI32)(((NI32)r_1) >> ((NU32)((NI32)(fl_4 - ((NI32)5)))))) - ((NI32)32)));
  fl_4 = ((NI32)(fl_4 - ((NI32)6)));
  result_36 = (X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1){
    .fld_0 = fl_4, .fld_1 = sl_5}
  ;
  return result_36;}
static inline BigChunk_0_sysvq0asl* findSuitableBlock_0_sysvq0asl(MemRegion_0_sysvq0asl* a_6, NI32* fl_1, NI32* sl_1){
  BigChunk_0_sysvq0asl* result_37;
  NI32 X60Qx_87 = nimIcheckB((*fl_1), 23);
  NU32 tmp_2 = ((NU32)((*a_6).slBitmap_0.a[X60Qx_87] & ((NU32)(((NU32) ~ ((NU32)0u)) << (*sl_1)))));
  result_37 = NIM_NIL;
  if ((!(tmp_2 == ((NU32)0)))){
    NI32 X60Qx_88 = lsbit_0_sysvq0asl(tmp_2);
    (*sl_1) = X60Qx_88;
    NI32 X60Qx_89 = nimIcheckB((*fl_1), 23);
    NI32 X60Qx_90 = nimIcheckB((*sl_1), 31);
    result_37 = (*a_6).matrix_0.a[X60Qx_89].a[X60Qx_90];}
  else {
    NI32 X60Qx_91 = lsbit_0_sysvq0asl(((NU32)((*a_6).flBitmap_0 & ((NU32)(((NU32) ~ ((NU32)0u)) << ((NI32)((*fl_1) + 1)))))));
    (*fl_1) = X60Qx_91;
    if (0 < (*fl_1)){
      NI32 X60Qx_92 = nimIcheckB((*fl_1), 23);
      NI32 X60Qx_93 = lsbit_0_sysvq0asl((*a_6).slBitmap_0.a[X60Qx_92]);
      (*sl_1) = X60Qx_93;
      NI32 X60Qx_94 = nimIcheckB((*fl_1), 23);
      NI32 X60Qx_95 = nimIcheckB((*sl_1), 31);
      result_37 = (*a_6).matrix_0.a[X60Qx_94].a[X60Qx_95];}}
  return result_37;}
void removeChunkFromMatrix_0_sysvq0asl(MemRegion_0_sysvq0asl* a_7, BigChunk_0_sysvq0asl* b_7){
  X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 X60Qtmptup_0 = mappingInsert_0_sysvq0asl((*b_7).Q.size_0);
  NI32 fl_5 = X60Qtmptup_0.fld_0;
  NI32 sl_6 = X60Qtmptup_0.fld_1;
  if ((!((*b_7).next_0 == NIM_NIL))){
    (*(*b_7).next_0).prev_0 = (*b_7).prev_0;}
  if ((!((*b_7).prev_0 == NIM_NIL))){
    (*(*b_7).prev_0).next_0 = (*b_7).next_0;}
  NI32 X60Qx_96 = nimIcheckB(fl_5, 23);
  NI32 X60Qx_97 = nimIcheckB(sl_6, 31);
  if ((*a_7).matrix_0.a[X60Qx_96].a[X60Qx_97] == b_7){
    NI32 X60Qx_98 = nimIcheckB(fl_5, 23);
    NI32 X60Qx_99 = nimIcheckB(sl_6, 31);
    (*a_7).matrix_0.a[X60Qx_98].a[X60Qx_99] = (*b_7).next_0;
    NI32 X60Qx_100 = nimIcheckB(fl_5, 23);
    NI32 X60Qx_101 = nimIcheckB(sl_6, 31);
    if ((*a_7).matrix_0.a[X60Qx_100].a[X60Qx_101] == NIM_NIL){
      NI32 X60Qx_102 = nimIcheckB(fl_5, 23);
      clearBit_0_sysvq0asl(sl_6, (&(*a_7).slBitmap_0.a[X60Qx_102]));
      NI32 X60Qx_103 = nimIcheckB(fl_5, 23);
      if ((*a_7).slBitmap_0.a[X60Qx_103] == ((NU32)0u)){
        clearBit_0_sysvq0asl(fl_5, (&(*a_7).flBitmap_0));}}}
  (*b_7).prev_0 = NIM_NIL;
  (*b_7).next_0 = NIM_NIL;}
void removeChunkFromMatrix2_0_sysvq0asl(MemRegion_0_sysvq0asl* a_8, BigChunk_0_sysvq0asl* b_8, NI32 fl_3, NI32 sl_3){
  NI32 X60Qx_104 = nimIcheckB(fl_3, 23);
  NI32 X60Qx_105 = nimIcheckB(sl_3, 31);
  (*a_8).matrix_0.a[X60Qx_104].a[X60Qx_105] = (*b_8).next_0;
  NI32 X60Qx_106 = nimIcheckB(fl_3, 23);
  NI32 X60Qx_107 = nimIcheckB(sl_3, 31);
  if ((!((*a_8).matrix_0.a[X60Qx_106].a[X60Qx_107] == NIM_NIL))){
    NI32 X60Qx_108 = nimIcheckB(fl_3, 23);
    NI32 X60Qx_109 = nimIcheckB(sl_3, 31);
    (*(*a_8).matrix_0.a[X60Qx_108].a[X60Qx_109]).prev_0 = NIM_NIL;}
  else {
    NI32 X60Qx_110 = nimIcheckB(fl_3, 23);
    clearBit_0_sysvq0asl(sl_3, (&(*a_8).slBitmap_0.a[X60Qx_110]));
    NI32 X60Qx_111 = nimIcheckB(fl_3, 23);
    if ((*a_8).slBitmap_0.a[X60Qx_111] == ((NU32)0u)){
      clearBit_0_sysvq0asl(fl_3, (&(*a_8).flBitmap_0));}}
  (*b_8).prev_0 = NIM_NIL;
  (*b_8).next_0 = NIM_NIL;}
void addChunkToMatrix_0_sysvq0asl(MemRegion_0_sysvq0asl* a_9, BigChunk_0_sysvq0asl* b_9){
  X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 X60Qtmptup_1 = mappingInsert_0_sysvq0asl((*b_9).Q.size_0);
  NI32 fl_6 = X60Qtmptup_1.fld_0;
  NI32 sl_7 = X60Qtmptup_1.fld_1;
  (*b_9).prev_0 = NIM_NIL;
  NI32 X60Qx_112 = nimIcheckB(fl_6, 23);
  NI32 X60Qx_113 = nimIcheckB(sl_7, 31);
  (*b_9).next_0 = (*a_9).matrix_0.a[X60Qx_112].a[X60Qx_113];
  NI32 X60Qx_114 = nimIcheckB(fl_6, 23);
  NI32 X60Qx_115 = nimIcheckB(sl_7, 31);
  if ((!((*a_9).matrix_0.a[X60Qx_114].a[X60Qx_115] == NIM_NIL))){
    NI32 X60Qx_116 = nimIcheckB(fl_6, 23);
    NI32 X60Qx_117 = nimIcheckB(sl_7, 31);
    (*(*a_9).matrix_0.a[X60Qx_116].a[X60Qx_117]).prev_0 = b_9;}
  NI32 X60Qx_118 = nimIcheckB(fl_6, 23);
  NI32 X60Qx_119 = nimIcheckB(sl_7, 31);
  (*a_9).matrix_0.a[X60Qx_118].a[X60Qx_119] = b_9;
  NI32 X60Qx_120 = nimIcheckB(fl_6, 23);
  setBit_0_sysvq0asl(sl_7, (&(*a_9).slBitmap_0.a[X60Qx_120]));
  setBit_0_sysvq0asl(fl_6, (&(*a_9).flBitmap_0));}
static inline void incCurrMem_0_sysvq0asl(MemRegion_0_sysvq0asl* a_10, NI32 bytes_0){
  inc_0_Iloplki_party5a2l1((&(*a_10).currMem_0), bytes_0);}
static inline void decCurrMem_0_sysvq0asl(MemRegion_0_sysvq0asl* a_11, NI32 bytes_1){
  NI32 X60Qx_121 = max_2_sysvq0asl((*a_11).maxMem_0, (*a_11).currMem_0);
  (*a_11).maxMem_0 = X60Qx_121;
  dec_0_Ig5i8xp_nifb6mq6y1((&(*a_11).currMem_0), bytes_1);}
void* allocPages_0_sysvq0asl(MemRegion_0_sysvq0asl* a_13, NI32 size_11){
  void* result_39;
  void* X60Qx_123 = osAllocPages_0_sysvq0asl(size_11);
  result_39 = X60Qx_123;
  return result_39;}
void* tryAllocPages_0_sysvq0asl(MemRegion_0_sysvq0asl* a_14, NI32 size_12){
  void* result_40;
  void* X60Qx_124 = osTryAllocPages_0_sysvq0asl(size_12);
  result_40 = X60Qx_124;
  return result_40;}
void* llAlloc_0_sysvq0asl(MemRegion_0_sysvq0asl* a_15, NI32 size_13){
  void* result_41;
  NB8 X60Qx_125;
  if ((*a_15).llmem_0 == NIM_NIL){
    X60Qx_125 = NIM_TRUE;}
  else {
    X60Qx_125 = ((*(*a_15).llmem_0).size_0 < size_13);}
  if (X60Qx_125){
    LLChunk_0_sysvq0asl* old_1 = (*a_15).llmem_0;
    void* X60Qx_126 = allocPages_0_sysvq0asl(a_15, ((NI32)4096));
    (*a_15).llmem_0 = ((LLChunk_0_sysvq0asl*)X60Qx_126);
    incCurrMem_0_sysvq0asl(a_15, ((NI32)4096));
    (*(*a_15).llmem_0).size_0 = ((NI32)(((NI32)4096) - sizeof(LLChunk_0_sysvq0asl)));
    (*(*a_15).llmem_0).acc_0 = sizeof(LLChunk_0_sysvq0asl);
    (*(*a_15).llmem_0).next_0 = old_1;}
  result_41 = ((void*)((NI32)(((NI32)(*a_15).llmem_0) + (*(*a_15).llmem_0).acc_0)));
  dec_0_Ig5i8xp_nifb6mq6y1((&(*(*a_15).llmem_0).size_0), size_13);
  inc_0_Iloplki_party5a2l1((&(*(*a_15).llmem_0).acc_0), size_13);
  zeroMem_0_sysvq0asl(result_41, size_13);
  return result_41;}
HeapLinks_0_sysvq0asl* addHeapLink_0_sysvq0asl(MemRegion_0_sysvq0asl* a_16, BigChunk_0_sysvq0asl* p_10, NI32 size_14){
  HeapLinks_0_sysvq0asl* result_42;
  HeapLinks_0_sysvq0asl* it_0 = (&(*a_16).heapLinks_0);
  {
    while (NIM_TRUE){
      NB8 X60Qx_127;
      if ((!(it_0 == NIM_NIL))){
        X60Qx_127 = (((NI32)(((NI32)(((NI32)((NI32)29)) - ((NI32)((NI32)0)))) + 1)) <= (*it_0).count_0);}
      else {
        X60Qx_127 = NIM_FALSE;}
      if (X60Qx_127){
        it_0 = (*it_0).next_0;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (it_0 == NIM_NIL){
    void* X60Qx_128 = llAlloc_0_sysvq0asl(a_16, sizeof(HeapLinks_0_sysvq0asl));
    HeapLinks_0_sysvq0asl* n_7 = ((HeapLinks_0_sysvq0asl*)X60Qx_128);
    (*n_7).next_0 = (*a_16).heapLinks_0.next_0;
    (*a_16).heapLinks_0.next_0 = n_7;
    NI32 X60Qx_129 = nimIcheckB(0, 29);
    (*n_7).chunks_0.a[X60Qx_129] = (X60Qt_0_IAtupleAptrSX42igX43hunk0sysvq0aslZAiS32_sysvq0asl){
      .fld_0 = p_10, .fld_1 = size_14}
    ;
    (*n_7).count_0 = 1;
    result_42 = n_7;}
  else {
    NI32 L_0 = (*it_0).count_0;
    NI32 X60Qx_130 = nimIcheckB(L_0, 29);
    (*it_0).chunks_0.a[X60Qx_130] = (X60Qt_0_IAtupleAptrSX42igX43hunk0sysvq0aslZAiS32_sysvq0asl){
      .fld_0 = p_10, .fld_1 = size_14}
    ;
    inc_1_I6wjjge_aow2h993l1((&(*it_0).count_0));
    result_42 = it_0;}
  return result_42;}
Trunk_0_sysvq0asl* intSetGet_0_sysvq0asl(IntSet_0_sysvq0asl* t_0, NI32 key_0){
  Trunk_0_sysvq0asl* result_43;
  NI32 X60Qx_131 = nimIcheckB(((NI32)(key_0 & ((NI32)255))), 255);
  Trunk_0_sysvq0asl* it_2 = (*t_0).data_0.a[X60Qx_131];
  {
    while ((!(it_2 == NIM_NIL))){
      if ((*it_2).key_0 == key_0){
        return it_2;}
      it_2 = (*it_2).next_0;}}
  whileStmtLabel_0: ;
  result_43 = NIM_NIL;
  return result_43;}
Trunk_0_sysvq0asl* intSetPut_0_sysvq0asl(MemRegion_0_sysvq0asl* a_18, NI32 key_1){
  Trunk_0_sysvq0asl* result_44;
  Trunk_0_sysvq0asl* X60Qx_132 = intSetGet_0_sysvq0asl((&(*a_18).chunkStarts_0), key_1);
  result_44 = X60Qx_132;
  if (result_44 == NIM_NIL){
    void* X60Qx_133 = llAlloc_0_sysvq0asl(a_18, sizeof(Trunk_0_sysvq0asl));
    result_44 = ((Trunk_0_sysvq0asl*)X60Qx_133);
    NI32 X60Qx_134 = nimIcheckB(((NI32)(key_1 & ((NI32)255))), 255);
    (*result_44).next_0 = (*a_18).chunkStarts_0.data_0.a[X60Qx_134];
    NI32 X60Qx_135 = nimIcheckB(((NI32)(key_1 & ((NI32)255))), 255);
    (*a_18).chunkStarts_0.data_0.a[X60Qx_135] = result_44;
    (*result_44).key_0 = key_1;}
  return result_44;}
NB8 contains_1_sysvq0asl(IntSet_0_sysvq0asl* s_4, NI32 key_2){
  NB8 result_45;
  Trunk_0_sysvq0asl* t_4 = intSetGet_0_sysvq0asl((&(*s_4)), ((NI32)(((NI32)key_2) >> ((NU32)((NI32)9)))));
  if ((!(t_4 == NIM_NIL))){
    NI32 u_1 = ((NI32)(key_2 & ((NI32)511)));
    NI32 X60Qx_136 = nimIcheckB(((NI32)(((NI32)u_1) >> ((NU32)((NI32)5)))), 15);
    result_45 = (!(((NU32)((*t_4).bits_0.a[X60Qx_136] & ((NU32)(((NU32)1) << ((NI32)(u_1 & ((NI32)31))))))) == ((NU32)0)));}
  else {
    result_45 = NIM_FALSE;}
  return result_45;}
void incl_2_sysvq0asl(MemRegion_0_sysvq0asl* a_19, NI32 key_3){
  Trunk_0_sysvq0asl* t_5 = intSetPut_0_sysvq0asl(a_19, ((NI32)(((NI32)key_3) >> ((NU32)((NI32)9)))));
  NI32 u_2 = ((NI32)(key_3 & ((NI32)511)));
  NI32 X60Qx_137 = nimIcheckB(((NI32)(((NI32)u_2) >> ((NU32)((NI32)5)))), 15);
  NI32 X60Qx_138 = nimIcheckB(((NI32)(((NI32)u_2) >> ((NU32)((NI32)5)))), 15);
  (*t_5).bits_0.a[X60Qx_137] = ((NU32)((*t_5).bits_0.a[X60Qx_138] | ((NU32)(((NU32)1) << ((NI32)(u_2 & ((NI32)31)))))));}
void excl_2_sysvq0asl(IntSet_0_sysvq0asl* s_5, NI32 key_4){
  Trunk_0_sysvq0asl* t_6 = intSetGet_0_sysvq0asl((&(*s_5)), ((NI32)(((NI32)key_4) >> ((NU32)((NI32)9)))));
  if ((!(t_6 == NIM_NIL))){
    NI32 u_3 = ((NI32)(key_4 & ((NI32)511)));
    NI32 X60Qx_139 = nimIcheckB(((NI32)(((NI32)u_3) >> ((NU32)((NI32)5)))), 15);
    NI32 X60Qx_140 = nimIcheckB(((NI32)(((NI32)u_3) >> ((NU32)((NI32)5)))), 15);
    (*t_6).bits_0.a[X60Qx_139] = ((NU32)((*t_6).bits_0.a[X60Qx_140] & ((NU32) ~ ((NU32)(((NU32)1) << ((NI32)(u_3 & ((NI32)31))))))));}}
static inline NB8 isSmallChunk_0_sysvq0asl(BaseChunk_0_sysvq0asl* c_0){
  NB8 result_46;
  result_46 = ((*c_0).size_0 <= ((NI32)(((NI32)4096) - sizeof(SmallChunk_0_sysvq0asl))));
  return result_46;}
static inline NB8 chunkUnused_0_sysvq0asl(BaseChunk_0_sysvq0asl* c_1){
  NB8 result_47;
  result_47 = (((NI32)((*c_1).prevSize_0 & 1)) == 0);
  return result_47;}
static inline NI32 pageIndex_0_sysvq0asl(BaseChunk_0_sysvq0asl* c_2){
  NI32 result_48;
  result_48 = ((NI32)(((NI32)((NI32)c_2)) >> ((NU32)((NI32)12))));
  return result_48;}
static inline NI32 pageIndex_1_sysvq0asl(void* p_11){
  NI32 result_49;
  result_49 = ((NI32)(((NI32)((NI32)p_11)) >> ((NU32)((NI32)12))));
  return result_49;}
static inline BaseChunk_0_sysvq0asl* pageAddr_0_sysvq0asl(void* p_12){
  BaseChunk_0_sysvq0asl* result_50;
  result_50 = ((BaseChunk_0_sysvq0asl*)((NI32)(((NI32)p_12) & ((NI32) ~ ((NI32)4095)))));
  return result_50;}
BigChunk_0_sysvq0asl* requestOsChunks_0_sysvq0asl(MemRegion_0_sysvq0asl* a_20, NI32 size_15){
  BigChunk_0_sysvq0asl* result_51;
  if ((!(*a_20).blockChunkSizeIncrease_0)){
    NI32 usedMem_0 = (*a_20).occ_0;
    if (usedMem_0 < ((NI32)(64 * 1024))){
      (*a_20).nextChunkSize_0 = ((NI32)(((NI32)4096) * 4));}
    else {
      NI32 X60Qx_141 = roundup_0_sysvq0asl(((NI32)(((NI32)usedMem_0) >> ((NU32)2))), ((NI32)4096));
      NI32 X60Qx_142 = min_2_sysvq0asl(X60Qx_141, ((NI32)((*a_20).nextChunkSize_0 * 2)));
      (*a_20).nextChunkSize_0 = X60Qx_142;
      NI32 X60Qx_143 = min_2_sysvq0asl((*a_20).nextChunkSize_0, ((NI32)1056964608));
      (*a_20).nextChunkSize_0 = ((NI32)X60Qx_143);}}
  NI32 size_36 = size_15;
  if ((*a_20).nextChunkSize_0 < size_36){
    void* X60Qx_144 = allocPages_0_sysvq0asl(a_20, size_36);
    result_51 = ((BigChunk_0_sysvq0asl*)X60Qx_144);}
  else {
    void* X60Qx_145 = tryAllocPages_0_sysvq0asl(a_20, (*a_20).nextChunkSize_0);
    result_51 = ((BigChunk_0_sysvq0asl*)X60Qx_145);
    if (result_51 == NIM_NIL){
      void* X60Qx_146 = allocPages_0_sysvq0asl(a_20, size_36);
      result_51 = ((BigChunk_0_sysvq0asl*)X60Qx_146);
      (*a_20).blockChunkSizeIncrease_0 = NIM_TRUE;}
    else {
      size_36 = (*a_20).nextChunkSize_0;}}
  incCurrMem_0_sysvq0asl(a_20, size_36);
  inc_0_Iloplki_party5a2l1((&(*a_20).freeMem_0), size_36);
  HeapLinks_0_sysvq0asl* heapLink_0 = addHeapLink_0_sysvq0asl(a_20, result_51, size_36);
  (*result_51).next_0 = NIM_NIL;
  (*result_51).prev_0 = NIM_NIL;
  (*result_51).Q.size_0 = size_36;
  NI32 nxt_0 = ((NI32)((NU32)(((NU32)((NI32)result_51)) + ((NU32)size_36))));
  BaseChunk_0_sysvq0asl* next_1 = ((BaseChunk_0_sysvq0asl*)nxt_0);
  NI32 X60Qx_147 = pageIndex_0_sysvq0asl(next_1);
  NB8 X60Qx_148 = contains_1_sysvq0asl((&(*a_20).chunkStarts_0), X60Qx_147);
  if (X60Qx_148){
    (*next_1).prevSize_0 = ((NI32)(size_36 | ((NI32)((*next_1).prevSize_0 & 1))));}
  NI32 X60Qx_16;
  if ((!((*a_20).lastSize_0 == 0))){
    X60Qx_16 = (*a_20).lastSize_0;}
  else {
    X60Qx_16 = ((NI32)4096);}
  NI32 lastSize_0 = X60Qx_16;
  NI32 prv_0 = ((NI32)((NU32)(((NU32)((NI32)result_51)) - ((NU32)lastSize_0))));
  BaseChunk_0_sysvq0asl* prev_1 = ((BaseChunk_0_sysvq0asl*)prv_0);
  NB8 X60Qx_149;
  NI32 X60Qx_150 = pageIndex_0_sysvq0asl(prev_1);
  NB8 X60Qx_151 = contains_1_sysvq0asl((&(*a_20).chunkStarts_0), X60Qx_150);
  if (X60Qx_151){
    X60Qx_149 = ((*prev_1).size_0 == lastSize_0);}
  else {
    X60Qx_149 = NIM_FALSE;}
  if (X60Qx_149){
    (*result_51).Q.prevSize_0 = ((NI32)(lastSize_0 | ((NI32)((*result_51).Q.prevSize_0 & 1))));}
  else {
    (*result_51).Q.prevSize_0 = ((NI32)(0 | ((NI32)((*result_51).Q.prevSize_0 & 1))));}
  (*a_20).lastSize_0 = size_36;
  return result_51;}
static inline NB8 isAccessible_0_sysvq0asl(MemRegion_0_sysvq0asl* a_21, void* p_13){
  NB8 result_52;
  NI32 X60Qx_152 = pageIndex_1_sysvq0asl(p_13);
  NB8 X60Qx_153 = contains_1_sysvq0asl((&(*a_21).chunkStarts_0), X60Qx_152);
  result_52 = X60Qx_153;
  return result_52;}
static inline void updatePrevSize_0_sysvq0asl(MemRegion_0_sysvq0asl* a_22, BigChunk_0_sysvq0asl* c_5, NI32 prevSize_0){
  BaseChunk_0_sysvq0asl* ri_0 = ((BaseChunk_0_sysvq0asl*)((NI32)((NU32)(((NU32)((NI32)c_5)) + ((NU32)(*c_5).Q.size_0)))));
  NB8 X60Qx_154 = isAccessible_0_sysvq0asl((&(*a_22)), ((void*)ri_0));
  if (X60Qx_154){
    (*ri_0).prevSize_0 = ((NI32)(prevSize_0 | ((NI32)((*ri_0).prevSize_0 & 1))));}}
BigChunk_0_sysvq0asl* splitChunk2_0_sysvq0asl(MemRegion_0_sysvq0asl* a_23, BigChunk_0_sysvq0asl* c_6, NI32 size_16){
  BigChunk_0_sysvq0asl* result_53;
  result_53 = ((BigChunk_0_sysvq0asl*)((NI32)((NU32)(((NU32)((NI32)c_6)) + ((NU32)size_16)))));
  (*result_53).Q.size_0 = ((NI32)((*c_6).Q.size_0 - size_16));
  (*result_53).next_0 = NIM_NIL;
  (*result_53).prev_0 = NIM_NIL;
  (*result_53).Q.prevSize_0 = size_16;
  (*result_53).Q.owner_0 = (&(*a_23));
  updatePrevSize_0_sysvq0asl(a_23, c_6, (*result_53).Q.size_0);
  (*c_6).Q.size_0 = size_16;
  NI32 X60Qx_155 = pageIndex_0_sysvq0asl(((BaseChunk_0_sysvq0asl*)result_53));
  incl_2_sysvq0asl(a_23, X60Qx_155);
  return result_53;}
void splitChunk_0_sysvq0asl(MemRegion_0_sysvq0asl* a_24, BigChunk_0_sysvq0asl* c_7, NI32 size_17){
  BigChunk_0_sysvq0asl* rest_0 = splitChunk2_0_sysvq0asl(a_24, c_7, size_17);
  addChunkToMatrix_0_sysvq0asl(a_24, rest_0);}
void freeBigChunk_0_sysvq0asl(MemRegion_0_sysvq0asl* a_25, BigChunk_0_sysvq0asl* c_8){
  BigChunk_0_sysvq0asl* c_28 = c_8;
  inc_0_Iloplki_party5a2l1((&(*a_25).freeMem_0), (*c_28).Q.size_0);
  (*c_28).Q.prevSize_0 = ((NI32)((*c_28).Q.prevSize_0 & ((NI32) ~ 1)));
  NI32 prevSize_1 = (*c_28).Q.prevSize_0;
  if ((!(prevSize_1 == 0))){
    BaseChunk_0_sysvq0asl* le_0 = ((BaseChunk_0_sysvq0asl*)((NI32)((NU32)(((NU32)((NI32)c_28)) - ((NU32)prevSize_1)))));
    NB8 X60Qx_156;
    NB8 X60Qx_157 = isAccessible_0_sysvq0asl((&(*a_25)), ((void*)le_0));
    if (X60Qx_157){
      NB8 X60Qx_158 = chunkUnused_0_sysvq0asl(le_0);
      X60Qx_156 = X60Qx_158;}
    else {
      X60Qx_156 = NIM_FALSE;}
    if (X60Qx_156){
      NB8 X60Qx_159;
      NB8 X60Qx_160 = isSmallChunk_0_sysvq0asl(le_0);
      if ((!X60Qx_160)){
        X60Qx_159 = ((*le_0).size_0 < ((NI32)1056964608));}
      else {
        X60Qx_159 = NIM_FALSE;}
      if (X60Qx_159){
        removeChunkFromMatrix_0_sysvq0asl(a_25, ((BigChunk_0_sysvq0asl*)le_0));
        inc_0_Iloplki_party5a2l1((&(*le_0).size_0), (*c_28).Q.size_0);
        NI32 X60Qx_161 = pageIndex_0_sysvq0asl(((BaseChunk_0_sysvq0asl*)c_28));
        excl_2_sysvq0asl((&(*a_25).chunkStarts_0), X60Qx_161);
        c_28 = ((BigChunk_0_sysvq0asl*)le_0);
        if (((NI32)1056964608) < (*c_28).Q.size_0){
          BigChunk_0_sysvq0asl* rest_1 = splitChunk2_0_sysvq0asl(a_25, c_28, ((NI32)1056964608));
          addChunkToMatrix_0_sysvq0asl(a_25, c_28);
          c_28 = rest_1;}}}}
  BaseChunk_0_sysvq0asl* ri_1 = ((BaseChunk_0_sysvq0asl*)((NI32)((NU32)(((NU32)((NI32)c_28)) + ((NU32)(*c_28).Q.size_0)))));
  NB8 X60Qx_162;
  NB8 X60Qx_163 = isAccessible_0_sysvq0asl((&(*a_25)), ((void*)ri_1));
  if (X60Qx_163){
    NB8 X60Qx_164 = chunkUnused_0_sysvq0asl(ri_1);
    X60Qx_162 = X60Qx_164;}
  else {
    X60Qx_162 = NIM_FALSE;}
  if (X60Qx_162){
    NB8 X60Qx_165;
    NB8 X60Qx_166 = isSmallChunk_0_sysvq0asl(ri_1);
    if ((!X60Qx_166)){
      X60Qx_165 = ((*c_28).Q.size_0 < ((NI32)1056964608));}
    else {
      X60Qx_165 = NIM_FALSE;}
    if (X60Qx_165){
      removeChunkFromMatrix_0_sysvq0asl(a_25, ((BigChunk_0_sysvq0asl*)ri_1));
      inc_0_Iloplki_party5a2l1((&(*c_28).Q.size_0), (*ri_1).size_0);
      NI32 X60Qx_167 = pageIndex_0_sysvq0asl(ri_1);
      excl_2_sysvq0asl((&(*a_25).chunkStarts_0), X60Qx_167);
      if (((NI32)1056964608) < (*c_28).Q.size_0){
        BigChunk_0_sysvq0asl* rest_2 = splitChunk2_0_sysvq0asl(a_25, c_28, ((NI32)1056964608));
        addChunkToMatrix_0_sysvq0asl(a_25, rest_2);}}}
  addChunkToMatrix_0_sysvq0asl(a_25, c_28);}
BigChunk_0_sysvq0asl* getBigChunk_0_sysvq0asl(MemRegion_0_sysvq0asl* a_26, NI32 size_18){
  BigChunk_0_sysvq0asl* result_54;
  NI32 size_37 = size_18;
  NI32 fl_7 = 0;
  NI32 sl_8 = 0;
  mappingSearch_0_sysvq0asl((&size_37), (&fl_7), (&sl_8));
  BigChunk_0_sysvq0asl* X60Qx_168 = findSuitableBlock_0_sysvq0asl((&(*a_26)), (&fl_7), (&sl_8));
  result_54 = X60Qx_168;
  if (result_54 == NIM_NIL){
    if (size_37 < ((NI32)(((NI32)128) * ((NI32)4096)))){
      BigChunk_0_sysvq0asl* X60Qx_169 = requestOsChunks_0_sysvq0asl(a_26, ((NI32)(((NI32)128) * ((NI32)4096))));
      result_54 = X60Qx_169;
      splitChunk_0_sysvq0asl(a_26, result_54, size_37);}
    else {
      BigChunk_0_sysvq0asl* X60Qx_170 = requestOsChunks_0_sysvq0asl(a_26, size_37);
      result_54 = X60Qx_170;
      if (size_37 < (*result_54).Q.size_0){
        splitChunk_0_sysvq0asl(a_26, result_54, size_37);}}
    (*result_54).Q.owner_0 = (&(*a_26));}
  else {
    removeChunkFromMatrix2_0_sysvq0asl(a_26, result_54, fl_7, sl_8);
    if (((NI32)(size_37 + ((NI32)4096))) <= (*result_54).Q.size_0){
      splitChunk_0_sysvq0asl(a_26, result_54, size_37);}}
  (*result_54).Q.prevSize_0 = 1;
  NI32 X60Qx_171 = pageIndex_0_sysvq0asl(((BaseChunk_0_sysvq0asl*)result_54));
  incl_2_sysvq0asl(a_26, X60Qx_171);
  dec_0_Ig5i8xp_nifb6mq6y1((&(*a_26).freeMem_0), size_37);
  return result_54;}
BigChunk_0_sysvq0asl* getHugeChunk_0_sysvq0asl(MemRegion_0_sysvq0asl* a_27, NI32 size_19){
  BigChunk_0_sysvq0asl* result_55;
  void* X60Qx_172 = allocPages_0_sysvq0asl(a_27, size_19);
  result_55 = ((BigChunk_0_sysvq0asl*)X60Qx_172);
  incCurrMem_0_sysvq0asl(a_27, size_19);
  (*result_55).next_0 = NIM_NIL;
  (*result_55).prev_0 = NIM_NIL;
  (*result_55).Q.size_0 = size_19;
  (*result_55).Q.prevSize_0 = 1;
  (*result_55).Q.owner_0 = (&(*a_27));
  NI32 X60Qx_173 = pageIndex_0_sysvq0asl(((BaseChunk_0_sysvq0asl*)result_55));
  incl_2_sysvq0asl(a_27, X60Qx_173);
  return result_55;}
void freeHugeChunk_0_sysvq0asl(MemRegion_0_sysvq0asl* a_28, BigChunk_0_sysvq0asl* c_9){
  NI32 size_38 = (*c_9).Q.size_0;
  NI32 X60Qx_174 = pageIndex_0_sysvq0asl(((BaseChunk_0_sysvq0asl*)c_9));
  excl_2_sysvq0asl((&(*a_28).chunkStarts_0), X60Qx_174);
  decCurrMem_0_sysvq0asl(a_28, size_38);
  osDeallocPages_0_sysvq0asl(((void*)c_9), size_38);}
SmallChunk_0_sysvq0asl* getSmallChunk_0_sysvq0asl(MemRegion_0_sysvq0asl* a_29){
  SmallChunk_0_sysvq0asl* result_56;
  BigChunk_0_sysvq0asl* res_1 = getBigChunk_0_sysvq0asl(a_29, ((NI32)4096));
  result_56 = ((SmallChunk_0_sysvq0asl*)res_1);
  return result_56;}
void deallocBigChunk_0_sysvq0asl(MemRegion_0_sysvq0asl* a_31, BigChunk_0_sysvq0asl* c_10){
  dec_0_Ig5i8xp_nifb6mq6y1((&(*a_31).occ_0), (*c_10).Q.size_0);
  (*c_10).prev_0 = NIM_NIL;
  if (((NI32)1056964609) <= (*c_10).Q.size_0){
    freeHugeChunk_0_sysvq0asl(a_31, c_10);}
  else {
    freeBigChunk_0_sysvq0asl(a_31, c_10);}}
static inline void addToSharedFreeListBigChunks_0_sysvq0asl(MemRegion_0_sysvq0asl* a_32, BigChunk_0_sysvq0asl* c_11){
  {
    while (NIM_TRUE){
      BigChunk_0_sysvq0asl* X60Qx_175 = __atomic_load_n((&(*a_32).sharedFreeListBigChunks_0), __ATOMIC_RELAXED);
      __atomic_store_n((&(*c_11).next_0), X60Qx_175, __ATOMIC_RELAXED);
      NB8 X60Qx_176 = __atomic_compare_exchange_n((&(*a_32).sharedFreeListBigChunks_0), (&(*c_11).next_0), c_11, NIM_TRUE, __ATOMIC_RELEASE, __ATOMIC_RELAXED);
      if (X60Qx_176){
        goto whileStmtLabel_0;}}}
  whileStmtLabel_0: ;}
static inline void addToSharedFreeList_0_sysvq0asl(SmallChunk_0_sysvq0asl* c_12, FreeCell_0_sysvq0asl* f_0, NI32 size_20){
  {
    while (NIM_TRUE){
      NI32 X60Qx_177 = nimIcheckB(size_20, 255);
      FreeCell_0_sysvq0asl* X60Qx_178 = __atomic_load_n((&(*(*c_12).Q.owner_0).sharedFreeLists_0.a[X60Qx_177]), __ATOMIC_RELAXED);
      __atomic_store_n((&(*f_0).next_0), X60Qx_178, __ATOMIC_RELAXED);
      NI32 X60Qx_179 = nimIcheckB(size_20, 255);
      NB8 X60Qx_180 = __atomic_compare_exchange_n((&(*(*c_12).Q.owner_0).sharedFreeLists_0.a[X60Qx_179]), (&(*f_0).next_0), f_0, NIM_TRUE, __ATOMIC_RELEASE, __ATOMIC_RELAXED);
      if (X60Qx_180){
        goto whileStmtLabel_0;}}}
  whileStmtLabel_0: ;}
void compensateCounters_0_sysvq0asl(MemRegion_0_sysvq0asl* a_33, SmallChunk_0_sysvq0asl* c_13, NI32 size_21){
  FreeCell_0_sysvq0asl* it_3 = (*c_13).freeList_0;
  NI32 total_0 = 0;
  {
    while ((!(it_3 == NIM_NIL))){
      inc_0_Iloplki_party5a2l1((&total_0), size_21);
      BaseChunk_0_sysvq0asl* X60Qx_181 = pageAddr_0_sysvq0asl(((void*)it_3));
      SmallChunk_0_sysvq0asl* chunk_0 = ((SmallChunk_0_sysvq0asl*)X60Qx_181);
      if ((!(c_13 == chunk_0))){
        (*c_13).foreignCells_0 = ((NI32)((*c_13).foreignCells_0 + ((NI32)1)));}
      it_3 = (*it_3).next_0;}}
  whileStmtLabel_0: ;
  (*c_13).free_0 = ((NI32)((*c_13).free_0 + ((NI32)total_0)));
  dec_0_Ig5i8xp_nifb6mq6y1((&(*a_33).occ_0), total_0);}
void freeDeferredObjects_0_sysvq0asl(MemRegion_0_sysvq0asl* a_34, BigChunk_0_sysvq0asl* root_0){
  BigChunk_0_sysvq0asl* it_4 = root_0;
  NI32 maxIters_0 = ((NI32)20);
  {
    while (NIM_TRUE){
      BigChunk_0_sysvq0asl* rest_3 = __atomic_load_n((&(*it_4).next_0), __ATOMIC_RELAXED);
      __atomic_store_n((&(*it_4).next_0), NIM_NIL, __ATOMIC_RELAXED);
      deallocBigChunk_0_sysvq0asl(a_34, ((BigChunk_0_sysvq0asl*)it_4));
      if (maxIters_0 == 0){
        if ((!(rest_3 == NIM_NIL))){
          addToSharedFreeListBigChunks_0_sysvq0asl((&(*a_34)), rest_3);}
        goto whileStmtLabel_0;}
      it_4 = rest_3;
      dec_1_I0nzoz91_ast8ri79k((&maxIters_0));
      if (it_4 == NIM_NIL){
        goto whileStmtLabel_0;}}}
  whileStmtLabel_0: ;}
static inline NI32 smallChunkAlignOffset_0_sysvq0asl(NI32 alignment_1){
  NI32 result_57;
  if (alignment_1 <= ((NI32)16)){
    result_57 = 0;}
  else {
    NI32 X60Qx_182 = align_0_sysvq0asl(((NI32)(sizeof(SmallChunk_0_sysvq0asl) + sizeof(FreeCell_0_sysvq0asl))), alignment_1);
    result_57 = ((NI32)(((NI32)(X60Qx_182 - sizeof(SmallChunk_0_sysvq0asl))) - sizeof(FreeCell_0_sysvq0asl)));}
  return result_57;}
static inline NI32 bigChunkAlignOffset_0_sysvq0asl(NI32 alignment_2){
  NI32 result_58;
  if (alignment_2 == 0){
    result_58 = 0;}
  else {
    NI32 X60Qx_183 = align_0_sysvq0asl(((NI32)(sizeof(BigChunk_0_sysvq0asl) + sizeof(FreeCell_0_sysvq0asl))), alignment_2);
    result_58 = ((NI32)(((NI32)(X60Qx_183 - sizeof(BigChunk_0_sysvq0asl))) - sizeof(FreeCell_0_sysvq0asl)));}
  return result_58;}
void* rawAlloc_0_sysvq0asl(MemRegion_0_sysvq0asl* a_35, NI32 requestedSize_0, NI32 alignment_3){
  void* result_59;
  NI32 X60Qx_184 = max_2_sysvq0asl(((NI32)16), alignment_3);
  NI32 size_39 = roundup_0_sysvq0asl(requestedSize_0, X60Qx_184);
  NI32 alignOff_0 = smallChunkAlignOffset_0_sysvq0asl(alignment_3);
  if (((NI32)(size_39 + alignOff_0)) <= ((NI32)(((NI32)4096) - sizeof(SmallChunk_0_sysvq0asl)))){
    NI32 s_82 = ((NI32)(size_39 / ((NI32)16)));
    NI32 X60Qx_185 = nimIcheckB(s_82, 255);
    SmallChunk_0_sysvq0asl* c_29 = (*a_35).freeSmallChunks_0.a[X60Qx_185];
    NB8 X60Qx_186;
    if ((!(c_29 == NIM_NIL))){
      X60Qx_186 = (!((*c_29).chunkAlignOff_0 == ((NI32)alignOff_0)));}
    else {
      X60Qx_186 = NIM_FALSE;}
    if (X60Qx_186){
      c_29 = NIM_NIL;}
    if (c_29 == NIM_NIL){
      SmallChunk_0_sysvq0asl* X60Qx_187 = getSmallChunk_0_sysvq0asl(a_35);
      c_29 = X60Qx_187;
      (*c_29).freeList_0 = NIM_NIL;
      (*c_29).foreignCells_0 = 0;
      (*c_29).chunkAlignOff_0 = ((NI32)alignOff_0);
      (*c_29).Q.size_0 = size_39;
      (*c_29).acc_0 = ((NU32)((NI32)(alignOff_0 + size_39)));
      (*c_29).free_0 = ((NI32)((NI32)(((NI32)(((NI32)(((NI32)4096) - sizeof(SmallChunk_0_sysvq0asl))) - alignOff_0)) - size_39)));
      (*c_29).next_0 = NIM_NIL;
      (*c_29).prev_0 = NIM_NIL;
      if ((*c_29).freeList_0 == NIM_NIL){
        NI32 X60Qx_188 = nimIcheckB(s_82, 255);
        FreeCell_0_sysvq0asl* X60Qx_189 = __atomic_exchange_n((&(*a_35).sharedFreeLists_0.a[X60Qx_188]), NIM_NIL, __ATOMIC_RELAXED);
        (*c_29).freeList_0 = X60Qx_189;
        compensateCounters_0_sysvq0asl(a_35, c_29, size_39);}
      if (size_39 <= (*c_29).free_0){
        NI32 X60Qx_190 = nimIcheckB(s_82, 255);
        listAdd_0_Ik4wxhz_sysvq0asl((&(*a_35).freeSmallChunks_0.a[X60Qx_190]), c_29);}
      result_59 = ((void*)((NI32)(((NI32)((void*)((void*)(&(*c_29).data_0)))) + alignOff_0)));}
    else {
      if ((*c_29).freeList_0 == NIM_NIL){
        result_59 = ((void*)((NI32)((NU32)(((NU32)((NI32)(&(*c_29).data_0))) + ((NU32)((NI32)(*c_29).acc_0))))));
        (*c_29).acc_0 = ((NU32)((*c_29).acc_0 + ((NU32)size_39)));}
      else {
        result_59 = ((void*)(*c_29).freeList_0);
        (*c_29).freeList_0 = (*(*c_29).freeList_0).next_0;
        BaseChunk_0_sysvq0asl* X60Qx_191 = pageAddr_0_sysvq0asl(result_59);
        if ((!(((SmallChunk_0_sysvq0asl*)X60Qx_191) == c_29))){
          (*c_29).foreignCells_0 = ((NI32)((*c_29).foreignCells_0 - ((NI32)1)));}
        else {
          }}
      (*c_29).free_0 = ((NI32)((*c_29).free_0 - ((NI32)size_39)));
      if ((*c_29).freeList_0 == NIM_NIL){
        NI32 X60Qx_192 = nimIcheckB(s_82, 255);
        FreeCell_0_sysvq0asl* X60Qx_193 = __atomic_exchange_n((&(*a_35).sharedFreeLists_0.a[X60Qx_192]), NIM_NIL, __ATOMIC_RELAXED);
        (*c_29).freeList_0 = X60Qx_193;
        compensateCounters_0_sysvq0asl(a_35, c_29, size_39);}
      if ((*c_29).free_0 < size_39){
        NI32 X60Qx_194 = nimIcheckB(s_82, 255);
        listRemove_0_Ibzev091_sysvq0asl((&(*a_35).freeSmallChunks_0.a[X60Qx_194]), c_29);}}
    inc_0_Iloplki_party5a2l1((&(*a_35).occ_0), size_39);}
  else {
    BigChunk_0_sysvq0asl* deferredFrees_0 = __atomic_exchange_n((&(*a_35).sharedFreeListBigChunks_0), NIM_NIL, __ATOMIC_RELAXED);
    if ((!(deferredFrees_0 == NIM_NIL))){
      freeDeferredObjects_0_sysvq0asl(a_35, deferredFrees_0);}
    NI32 alignPad_0 = bigChunkAlignOffset_0_sysvq0asl(alignment_3);
    size_39 = ((NI32)(((NI32)(requestedSize_0 + sizeof(BigChunk_0_sysvq0asl))) + alignPad_0));
    BigChunk_0_sysvq0asl* X60Qx_17;
    if (((NI32)1056964609) <= size_39){
      BigChunk_0_sysvq0asl* X60Qx_195 = getHugeChunk_0_sysvq0asl(a_35, size_39);
      X60Qx_17 = X60Qx_195;}
    else {
      BigChunk_0_sysvq0asl* X60Qx_196 = getBigChunk_0_sysvq0asl(a_35, size_39);
      X60Qx_17 = X60Qx_196;}
    BigChunk_0_sysvq0asl* c_32 = X60Qx_17;
    result_59 = ((void*)((NI32)(((NI32)((void*)((void*)(&(*c_32).data_0)))) + alignPad_0)));
    (*c_32).prev_0 = ((BigChunk_0_sysvq0asl*)result_59);
    inc_0_Iloplki_party5a2l1((&(*a_35).occ_0), (*c_32).Q.size_0);}
  return result_59;}
void rawDealloc_0_sysvq0asl(MemRegion_0_sysvq0asl* a_37, void* p_14){
  BaseChunk_0_sysvq0asl* c_33 = pageAddr_0_sysvq0asl(p_14);
  NB8 X60Qx_198 = isSmallChunk_0_sysvq0asl(c_33);
  if (X60Qx_198){
    SmallChunk_0_sysvq0asl* c_34 = ((SmallChunk_0_sysvq0asl*)c_33);
    NI32 s_83 = (*c_34).Q.size_0;
    FreeCell_0_sysvq0asl* f_3 = ((FreeCell_0_sysvq0asl*)p_14);
    if ((*c_34).Q.owner_0 == (&(*a_37))){
      dec_0_Ig5i8xp_nifb6mq6y1((&(*a_37).occ_0), s_83);
      NI32 X60Qx_199 = nimIcheckB(((NI32)(s_83 / ((NI32)16))), 255);
      SmallChunk_0_sysvq0asl* activeChunk_0 = (*a_37).freeSmallChunks_0.a[X60Qx_199];
      NB8 X60Qx_200;
      NB8 X60Qx_201;
      if ((!(activeChunk_0 == NIM_NIL))){
        X60Qx_201 = (!(c_34 == activeChunk_0));}
      else {
        X60Qx_201 = NIM_FALSE;}
      if (X60Qx_201){
        X60Qx_200 = ((*activeChunk_0).chunkAlignOff_0 == (*c_34).chunkAlignOff_0);}
      else {
        X60Qx_200 = NIM_FALSE;}
      if (X60Qx_200){
        (*f_3).next_0 = (*activeChunk_0).freeList_0;
        (*activeChunk_0).freeList_0 = f_3;
        (*activeChunk_0).free_0 = ((NI32)((*activeChunk_0).free_0 + ((NI32)s_83)));
        (*activeChunk_0).foreignCells_0 = ((NI32)((*activeChunk_0).foreignCells_0 + ((NI32)1)));}
      else {
        (*f_3).next_0 = (*c_34).freeList_0;
        (*c_34).freeList_0 = f_3;
        if ((*c_34).free_0 < s_83){
          NI32 X60Qx_202 = nimIcheckB(((NI32)(s_83 / ((NI32)16))), 255);
          listAdd_0_Ik4wxhz_sysvq0asl((&(*a_37).freeSmallChunks_0.a[X60Qx_202]), c_34);
          (*c_34).free_0 = ((NI32)((*c_34).free_0 + ((NI32)s_83)));}
        else {
          (*c_34).free_0 = ((NI32)((*c_34).free_0 + ((NI32)s_83)));}}}
    else {
      addToSharedFreeList_0_sysvq0asl(c_34, f_3, ((NI32)(s_83 / ((NI32)16))));}}
  else {
    if ((*c_33).owner_0 == (&(*a_37))){
      deallocBigChunk_0_sysvq0asl(a_37, ((BigChunk_0_sysvq0asl*)c_33));}
    else {
      addToSharedFreeListBigChunks_0_sysvq0asl((*c_33).owner_0, ((BigChunk_0_sysvq0asl*)c_33));}}}
NI32 ptrSize_0_sysvq0asl(void* p_15){
  NI32 result_61;
  BaseChunk_0_sysvq0asl* c_35 = pageAddr_0_sysvq0asl(p_15);
  result_61 = (*c_35).size_0;
  NB8 X60Qx_203 = isSmallChunk_0_sysvq0asl(c_35);
  if ((!X60Qx_203)){
    dec_0_Ig5i8xp_nifb6mq6y1((&result_61), sizeof(BigChunk_0_sysvq0asl));}
  return result_61;}
void* alloc_0_sysvq0asl(MemRegion_0_sysvq0asl* allocator_0, NI32 size_22){
  void* result_62;
  void* X60Qx_204 = rawAlloc_0_sysvq0asl(allocator_0, size_22, 0);
  result_62 = X60Qx_204;
  return result_62;}
void* alloc0_0_sysvq0asl(MemRegion_0_sysvq0asl* allocator_1, NI32 size_23){
  void* result_63;
  void* X60Qx_205 = alloc_0_sysvq0asl(allocator_1, size_23);
  result_63 = X60Qx_205;
  zeroMem_0_sysvq0asl(result_63, size_23);
  return result_63;}
void dealloc_0_sysvq0asl(MemRegion_0_sysvq0asl* allocator_2, void* p_16){
  rawDealloc_0_sysvq0asl(allocator_2, p_16);}
void* realloc_0_sysvq0asl(MemRegion_0_sysvq0asl* allocator_3, void* p_17, NI32 newsize_0){
  void* result_64;
  result_64 = NIM_NIL;
  if (0 < newsize_0){
    void* X60Qx_206 = alloc_0_sysvq0asl(allocator_3, newsize_0);
    result_64 = X60Qx_206;
    if ((!(p_17 == NIM_NIL))){
      NI32 X60Qx_207 = ptrSize_0_sysvq0asl(p_17);
      NI32 X60Qx_208 = min_2_sysvq0asl(X60Qx_207, newsize_0);
      copyMem_0_sysvq0asl(result_64, p_17, X60Qx_208);
      dealloc_0_sysvq0asl(allocator_3, p_17);}}
  else {
    if ((!(p_17 == NIM_NIL))){
      dealloc_0_sysvq0asl(allocator_3, p_17);}}
  return result_64;}
void* alloc_1_sysvq0asl(NI32 size_24){
  void* result_69;
  void* X60Qx_211 = alloc_0_sysvq0asl((&allocator_0_sysvq0asl), size_24);
  result_69 = X60Qx_211;
  return result_69;}
void* alloc0_1_sysvq0asl(NI32 size_25){
  void* result_70;
  void* X60Qx_212 = alloc0_0_sysvq0asl((&allocator_0_sysvq0asl), size_25);
  result_70 = X60Qx_212;
  return result_70;}
void* realloc_1_sysvq0asl(void* p_19, NI32 size_26){
  void* result_71;
  void* X60Qx_213 = realloc_0_sysvq0asl((&allocator_0_sysvq0asl), p_19, size_26);
  result_71 = X60Qx_213;
  return result_71;}
void dealloc_1_sysvq0asl(void* p_20){
  dealloc_0_sysvq0asl((&allocator_0_sysvq0asl), p_20);}
NI32 allocatedSize_0_sysvq0asl(void* p_21){
  NI32 result_72;
  NI32 X60Qx_214 = ptrSize_0_sysvq0asl(p_21);
  result_72 = X60Qx_214;
  return result_72;}
void* allocFixed_0_sysvq0asl(NI32 size_27){
  void* result_76;
  void* X60Qx_218 = alloc_1_sysvq0asl(size_27);
  result_76 = X60Qx_218;
  return result_76;}
void deallocFixed_0_sysvq0asl(void* p_22){
  dealloc_1_sysvq0asl(p_22);}
N_NIMCALL(void, continueAfterOutOfMem_0_sysvq0asl)(NI32 size_28){
  if (missingBytes_0_sysvq0asl < ((NI32)(((NI32)2147483647) - size_28))){
    missingBytes_0_sysvq0asl = ((NI32)(missingBytes_0_sysvq0asl + size_28));}
  else {
    missingBytes_0_sysvq0asl = ((NI32)2147483647);}}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline NC8* rawData_1_sysvq0asl(string_0_sysvq0asl* s_33){
  NC8* result_96;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_33).bytes_0))))){
    result_96 = ((NC8*)(&(*(*s_33).more_0).data_0[0]));}
  else {
    result_96 = ((NC8*)((NU32)(((NU32)(&(*s_33).bytes_0)) + 1u)));}
  return result_96;}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline NI32 high_4_sysvq0asl(string_0_sysvq0asl s_35){
  NI32 result_99;
  NI32 X60Qx_220 = len_4_sysvq0asl(s_35);
  result_99 = ((NI32)(X60Qx_220 - 1));
  return result_99;}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_39, NI32 start_0){
  NC8* result_103;
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_39).bytes_0))))){
    result_103 = ((NC8*)((NU32)(((NU32)(&(*(*s_39).more_0).data_0[0])) + ((NU32)start_0))));}
  else {
    result_103 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_39).bytes_0)) + 1u)))) + ((NU32)start_0))));}
  return result_103;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
void nimStrCopy(string_0_sysvq0asl* dest_11, string_0_sysvq0asl src_6){
  NI32 ssrc_0 = ((NI32)(*((NU8*)(&src_6.bytes_0))));
  if (ssrc_0 <= ((NI32)6)){
    NI32 sdest_0 = ((NI32)(*((NU8*)(&(*dest_11).bytes_0))));
    if (sdest_0 == ((NI32)255)){
      NB8 X60Qx_222 = arcDec_0_sysvq0asl((&(*(*dest_11).more_0).rc_0));
      if (X60Qx_222){
        dealloc_1_sysvq0asl(((void*)(*dest_11).more_0));}}
    copyMem_0_sysvq0asl(((void*)(&(*dest_11).bytes_0)), ((void*)(&src_6.bytes_0)), sizeof(string_0_sysvq0asl));}
  else {
    if ((&(*dest_11)) == (&src_6)){
      return;}
    NI32 sdest_1 = ((NI32)(*((NU8*)(&(*dest_11).bytes_0))));
    if (sdest_1 == ((NI32)255)){
      NB8 X60Qx_223 = arcDec_0_sysvq0asl((&(*(*dest_11).more_0).rc_0));
      if (X60Qx_223){
        dealloc_1_sysvq0asl(((void*)(*dest_11).more_0));}}
    if (ssrc_0 == ((NI32)255)){
      arcInc_0_sysvq0asl((&(*src_6.more_0).rc_0));}
    copyMem_0_sysvq0asl(((void*)(&(*dest_11).bytes_0)), ((void*)(&src_6.bytes_0)), sizeof(string_0_sysvq0asl));}}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline NI32 len_5_sysvq0asl(NC8* a_46){
  NI32 result_105;
  NI64 X60Qx_19;
  if (((void*)a_46) == NIM_NIL){
    X60Qx_19 = 0;}
  else {
    size_t X60Qx_225 = strlen(a_46);
    X60Qx_19 = ((NI32)X60Qx_225);}
  result_105 = X60Qx_19;
  return result_105;}
static inline NI32 ssResize_0_sysvq0asl(NI32 old_0){
  NI32 result_106;
  NI64 X60Qx_20;
  if (old_0 <= 0){
    X60Qx_20 = 4;}
  else {
    if (old_0 <= 32767){
      X60Qx_20 = ((NI32)(old_0 * 2));}
    else {
      X60Qx_20 = ((NI32)(((NI32)(old_0 / 2)) + old_0));}}
  result_106 = X60Qx_20;
  return result_106;}
void ensureUniqueLong_0_sysvq0asl(string_0_sysvq0asl* s_43, NI32 oldLen_0, NI32 newLen_5){
  NI32 sl_10 = ((NI32)(*((NU8*)(&(*s_43).bytes_0))));
  NB8 isHeap_0 = (sl_10 == ((NI32)255));
  NI32 X60Qx_21;
  if (isHeap_0){
    X60Qx_21 = (*(*s_43).more_0).capImpl_0;}
  else {
    X60Qx_21 = 0;}
  NI32 cap_1 = X60Qx_21;
  NB8 X60Qx_226;
  NB8 X60Qx_227;
  if (isHeap_0){
    NB8 X60Qx_228 = arcIsUnique_0_sysvq0asl((&(*(*s_43).more_0).rc_0));
    X60Qx_227 = X60Qx_228;}
  else {
    X60Qx_227 = NIM_FALSE;}
  if (X60Qx_227){
    X60Qx_226 = (newLen_5 <= cap_1);}
  else {
    X60Qx_226 = NIM_FALSE;}
  if (X60Qx_226){
    (*(*s_43).more_0).fullLen_0 = newLen_5;
    NI32 X60Qx_229 = min_2_sysvq0asl(oldLen_0, ((NI32)3));
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_43).bytes_0)) + 1u)))), ((void*)(&(*(*s_43).more_0).data_0[0])), X60Qx_229);}
  else {
    NI32 X60Qx_22;
    if (cap_1 < newLen_5){
      NI32 X60Qx_230 = ssResize_0_sysvq0asl(cap_1);
      NI32 X60Qx_231 = max_2_sysvq0asl(newLen_5, X60Qx_230);
      X60Qx_22 = X60Qx_231;}
    else {
      X60Qx_22 = cap_1;}
    NI32 newCap_2 = X60Qx_22;
    void* X60Qx_232 = alloc_1_sysvq0asl(((NI32)(((NI32)12) + newCap_2)));
    LongString_0_sysvq0asl* p_35 = ((LongString_0_sysvq0asl*)X60Qx_232);
    if ((!(p_35 == NIM_NIL))){
      (*p_35).rc_0 = 0;
      (*p_35).fullLen_0 = newLen_5;
      (*p_35).capImpl_0 = newCap_2;
      if (isHeap_0){
        LongString_0_sysvq0asl* old_2 = (*s_43).more_0;
        NI32 X60Qx_233 = min_2_sysvq0asl(oldLen_0, newCap_2);
        copyMem_0_sysvq0asl(((void*)(&(*p_35).data_0[0])), ((void*)(&(*old_2).data_0[0])), X60Qx_233);
        NB8 X60Qx_234 = arcDec_0_sysvq0asl((&(*old_2).rc_0));
        if (X60Qx_234){
          dealloc_1_sysvq0asl(((void*)old_2));}}
      else {
        NI32 X60Qx_235 = min_2_sysvq0asl(oldLen_0, newCap_2);
        copyMem_0_sysvq0asl(((void*)(&(*p_35).data_0[0])), ((void*)(&(*(*s_43).more_0).data_0[0])), X60Qx_235);}
      (*s_43).more_0 = p_35;
      (*((NU8*)(&(*s_43).bytes_0))) = ((NU8)((NI32)255));
      NI32 X60Qx_236 = min_2_sysvq0asl(oldLen_0, ((NI32)3));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_43).bytes_0)) + 1u)))), ((void*)(&(*p_35).data_0[0])), X60Qx_236);}
    else {
      oomHandler_0_sysvq0asl(((NI32)(((NI32)12) + newCap_2)));
      (*s_43).bytes_0 = ((NU32)21760775509248519ull);
      (*s_43).more_0 = NIM_NIL;}}}
void transitionToLong_0_sysvq0asl(string_0_sysvq0asl* s_44, NI32 sl_4, NI32 newLen_6){
  NI32 X60Qx_237 = ssResize_0_sysvq0asl(newLen_6);
  NI32 newCap_3 = max_2_sysvq0asl(newLen_6, X60Qx_237);
  void* X60Qx_238 = alloc_1_sysvq0asl(((NI32)(((NI32)12) + newCap_3)));
  LongString_0_sysvq0asl* p_36 = ((LongString_0_sysvq0asl*)X60Qx_238);
  if ((!(p_36 == NIM_NIL))){
    (*p_36).rc_0 = 0;
    (*p_36).fullLen_0 = newLen_6;
    (*p_36).capImpl_0 = newCap_3;
    copyMem_0_sysvq0asl(((void*)(&(*p_36).data_0[0])), ((void*)((NC8*)((NU32)(((NU32)(&(*s_44).bytes_0)) + 1u)))), sl_4);
    (*s_44).more_0 = p_36;
    (*((NU8*)(&(*s_44).bytes_0))) = ((NU8)((NI32)255));
    NI32 X60Qx_239 = min_2_sysvq0asl(sl_4, ((NI32)3));
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_44).bytes_0)) + 1u)))), ((void*)(&(*p_36).data_0[0])), X60Qx_239);}
  else {
    oomHandler_0_sysvq0asl(((NI32)(((NI32)12) + newCap_3)));
    (*s_44).bytes_0 = ((NU32)21760775509248519ull);
    (*s_44).more_0 = NIM_NIL;}}
NC8* readRawDataStable_0_sysvq0asl(string_0_sysvq0asl* s_45, NI32 start_1){
  NC8* result_107;
  NI32 sl_11 = ((NI32)(*((NU8*)(&(*s_45).bytes_0))));
  NB8 X60Qx_240;
  if (0 < sl_11){
    X60Qx_240 = (sl_11 <= ((NI32)6));}
  else {
    X60Qx_240 = NIM_FALSE;}
  if (X60Qx_240){
    transitionToLong_0_sysvq0asl(s_45, sl_11, sl_11);}
  NC8* X60Qx_241 = rawData_1_sysvq0asl((&(*s_45)));
  result_107 = ((NC8*)((NU32)(((NU32)X60Qx_241) + ((NU32)start_1))));
  return result_107;}
void prepareMutation_0_sysvq0asl(string_0_sysvq0asl* s_46){
  NI32 sl_12 = ((NI32)(*((NU8*)(&(*s_46).bytes_0))));
  NB8 X60Qx_242;
  if (sl_12 == ((NI32)254)){
    X60Qx_242 = NIM_TRUE;}
  else {
    NB8 X60Qx_243;
    if (sl_12 == ((NI32)255)){
      NB8 X60Qx_244 = arcIsUnique_0_sysvq0asl((&(*(*s_46).more_0).rc_0));
      X60Qx_243 = (!X60Qx_244);}
    else {
      X60Qx_243 = NIM_FALSE;}
    X60Qx_242 = X60Qx_243;}
  if (X60Qx_242){
    if (sl_12 == ((NI32)255)){
      NB8 X60Qx_245 = arcDec_0_sysvq0asl((&(*(*s_46).more_0).rc_0));}
    LongString_0_sysvq0asl* old_3 = (*s_46).more_0;
    NI32 oldLen_1 = (*old_3).fullLen_0;
    void* X60Qx_246 = alloc_1_sysvq0asl(((NI32)(((NI32)12) + oldLen_1)));
    LongString_0_sysvq0asl* p_37 = ((LongString_0_sysvq0asl*)X60Qx_246);
    if ((!(p_37 == NIM_NIL))){
      (*p_37).rc_0 = 0;
      (*p_37).fullLen_0 = oldLen_1;
      (*p_37).capImpl_0 = oldLen_1;
      copyMem_0_sysvq0asl(((void*)(&(*p_37).data_0[0])), ((void*)(&(*old_3).data_0[0])), oldLen_1);
      (*s_46).more_0 = p_37;
      (*((NU8*)(&(*s_46).bytes_0))) = ((NU8)((NI32)255));}
    else {
      oomHandler_0_sysvq0asl(((NI32)(((NI32)12) + oldLen_1)));
      (*s_46).bytes_0 = ((NU32)21760775509248519ull);
      (*s_46).more_0 = NIM_NIL;}}}
NC8* beginStore_0_sysvq0asl(string_0_sysvq0asl* s_47, NI32 newLen_7, NI32 start_2){
  NC8* result_108;
  NI32 sl_13 = ((NI32)(*((NU8*)(&(*s_47).bytes_0))));
  NI32 X60Qx_23;
  if (((NI32)6) < sl_13){
    X60Qx_23 = (*(*s_47).more_0).fullLen_0;}
  else {
    X60Qx_23 = sl_13;}
  NI32 curLen_0 = X60Qx_23;
  NB8 X60Qx_247;
  if (newLen_7 <= ((NI32)6)){
    X60Qx_247 = (sl_13 <= ((NI32)6));}
  else {
    X60Qx_247 = NIM_FALSE;}
  if (X60Qx_247){
    if ((!(newLen_7 == curLen_0))){
      (*((NU8*)(&(*s_47).bytes_0))) = ((NU8)newLen_7);}
    result_108 = ((NC8*)((NU32)(((NU32)((NC8*)((NU32)(((NU32)(&(*s_47).bytes_0)) + 1u)))) + ((NU32)start_2))));}
  else {
    if (sl_13 <= ((NI32)6)){
      transitionToLong_0_sysvq0asl(s_47, curLen_0, newLen_7);
      result_108 = ((NC8*)((NU32)(((NU32)(&(*(*s_47).more_0).data_0[0])) + ((NU32)start_2))));}
    else {
      ensureUniqueLong_0_sysvq0asl(s_47, curLen_0, newLen_7);
      result_108 = ((NC8*)((NU32)(((NU32)(&(*(*s_47).more_0).data_0[0])) + ((NU32)start_2))));}}
  return result_108;}
static inline void endStore_0_sysvq0asl(string_0_sysvq0asl* s_48){
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_48).bytes_0))))){
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_48).bytes_0)) + 1u)))), ((void*)(&(*(*s_48).more_0).data_0[0])), ((NI32)3));}}
void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14){
  NI32 sl_14 = ((NI32)(*((NU8*)(&(*s_49).bytes_0))));
  if (sl_14 < ((NI32)6)){
    NI32 newLen_14 = ((NI32)(sl_14 + 1));
    ((NC8*)((NU32)(((NU32)(&(*s_49).bytes_0)) + 1u)))[sl_14] = c_14;
    (*((NU8*)(&(*s_49).bytes_0))) = ((NU8)newLen_14);}
  else {
    if (((NI32)6) < sl_14){
      NI32 l_1 = (*(*s_49).more_0).fullLen_0;
      NB8 X60Qx_248;
      NB8 X60Qx_249;
      if (sl_14 == ((NI32)255)){
        NB8 X60Qx_250 = arcIsUnique_0_sysvq0asl((&(*(*s_49).more_0).rc_0));
        X60Qx_249 = X60Qx_250;}
      else {
        X60Qx_249 = NIM_FALSE;}
      if (X60Qx_249){
        X60Qx_248 = (l_1 < (*(*s_49).more_0).capImpl_0);}
      else {
        X60Qx_248 = NIM_FALSE;}
      if (X60Qx_248){
        (*(*s_49).more_0).data_0[l_1] = c_14;
        (*(*s_49).more_0).fullLen_0 = ((NI32)(l_1 + 1));
        if (l_1 < ((NI32)3)){
          ((NC8*)((NU32)(((NU32)(&(*s_49).bytes_0)) + 1u)))[l_1] = c_14;}}
      else {
        NI32 oldLen_2 = (*(*s_49).more_0).fullLen_0;
        ensureUniqueLong_0_sysvq0asl(s_49, oldLen_2, ((NI32)(oldLen_2 + 1)));
        if (((NI32)(*((NU8*)(&(*s_49).bytes_0)))) == ((NI32)255)){
          (*(*s_49).more_0).data_0[oldLen_2] = c_14;
          if (oldLen_2 < ((NI32)3)){
            ((NC8*)((NU32)(((NU32)(&(*s_49).bytes_0)) + 1u)))[oldLen_2] = c_14;}}}}
    else {
      transitionToLong_0_sysvq0asl(s_49, sl_14, ((NI32)(sl_14 + 1)));
      if (((NI32)(*((NU8*)(&(*s_49).bytes_0)))) == ((NI32)255)){
        (*(*s_49).more_0).data_0[sl_14] = c_14;}}}}
void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0){
  NI32 partLen_0 = len_4_sysvq0asl(part_0);
  if (partLen_0 == 0){
    return;}
  NC8* partData_0 = rawData_1_sysvq0asl((&part_0));
  NI32 sl_15 = ((NI32)(*((NU8*)(&(*s_50).bytes_0))));
  if (sl_15 <= ((NI32)6)){
    NI32 sLen_0 = sl_15;
    NI32 newLen_15 = ((NI32)(sLen_0 + partLen_0));
    if (newLen_15 <= ((NI32)6)){
      copyMem_0_sysvq0asl(((void*)((NU32)(((NU32)(((NU32)(&(*s_50).bytes_0)) + 1u)) + ((NU32)sLen_0)))), ((void*)partData_0), partLen_0);
      (*((NU8*)(&(*s_50).bytes_0))) = ((NU8)newLen_15);}
    else {
      transitionToLong_0_sysvq0asl(s_50, sLen_0, newLen_15);
      if (((NI32)(*((NU8*)(&(*s_50).bytes_0)))) == ((NI32)255)){
        copyMem_0_sysvq0asl(((void*)((NU32)(((NU32)(&(*(*s_50).more_0).data_0[0])) + ((NU32)sLen_0)))), ((void*)partData_0), partLen_0);
        copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_50).bytes_0)) + 1u)))), ((void*)(&(*(*s_50).more_0).data_0[0])), ((NI32)3));}}}
  else {
    NI32 sLen_1 = (*(*s_50).more_0).fullLen_0;
    NI32 newLen_16 = ((NI32)(sLen_1 + partLen_0));
    ensureUniqueLong_0_sysvq0asl(s_50, sLen_1, newLen_16);
    if (((NI32)(*((NU8*)(&(*s_50).bytes_0)))) == ((NI32)255)){
      copyMem_0_sysvq0asl(((void*)((NU32)(((NU32)(&(*(*s_50).more_0).data_0[0])) + ((NU32)sLen_1)))), ((void*)partData_0), partLen_0);
      if (sLen_1 < ((NI32)3)){
        copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_50).bytes_0)) + 1u)))), ((void*)(&(*(*s_50).more_0).data_0[0])), ((NI32)3));}}}}
static inline NU32 zeroSwarPadImplLE_0_sysvq0asl(NU32 bytes_4, NI32 newLen_9){
  NU32 result_110;
  NU32 keepBits_0 = ((NU32)((NI32)(((NI32)(newLen_9 + 1)) * 8)));
  NU32 X60Qx_25;
  if (((NU32)((NI32)(sizeof(NU32) * 8))) <= keepBits_0){
    X60Qx_25 = ((NU32) ~ 0u);}
  else {
    X60Qx_25 = ((NU32)(((NU32)(((NU32)1) << keepBits_0)) - 1u));}
  NU32 mask_0 = X60Qx_25;
  result_110 = ((NU32)(((NU32)(bytes_4 & ((NU32)(mask_0 & ((NU32) ~ 255u))))) | ((NU32)newLen_9)));
  return result_110;}
static inline NU32 zeroSwarPadImpl_0_sysvq0asl(NU32 bytes_5, NI32 newLen_10){
  NU32 result_111;
  NU32 X60Qx_251 = zeroSwarPadImplLE_0_sysvq0asl(bytes_5, newLen_10);
  result_111 = X60Qx_251;
  return result_111;}
void shrink_1_sysvq0asl(string_0_sysvq0asl* s_52, NI32 newLen_12){
  NI32 X60Qx_252 = len_4_sysvq0asl((*s_52));
  if (newLen_12 <= X60Qx_252){
    NI32 sl_16 = ((NI32)(*((NU8*)(&(*s_52).bytes_0))));
    if (sl_16 <= ((NI32)6)){
      if (newLen_12 <= ((NI32)3)){
        NU32 X60Qx_253 = zeroSwarPadImpl_0_sysvq0asl((*s_52).bytes_0, newLen_12);
        (*s_52).bytes_0 = X60Qx_253;}
      else {
        (*((NU8*)(&(*s_52).bytes_0))) = ((NU8)newLen_12);}}
    else {
      prepareMutation_0_sysvq0asl(s_52);
      (*(*s_52).more_0).fullLen_0 = newLen_12;
      NI32 X60Qx_254 = min_2_sysvq0asl(newLen_12, ((NI32)3));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_52).bytes_0)) + 1u)))), ((void*)(&(*(*s_52).more_0).data_0[0])), X60Qx_254);}}}
void setLen_1_sysvq0asl(string_0_sysvq0asl* s_53, NI32 newLen_13){
  NI32 X60Qx_255 = len_4_sysvq0asl((*s_53));
  if (newLen_13 <= X60Qx_255){
    shrink_1_sysvq0asl(s_53, newLen_13);
    return;}
  NI32 sl_17 = ((NI32)(*((NU8*)(&(*s_53).bytes_0))));
  if (sl_17 <= ((NI32)6)){
    NI32 curLen_1 = len_4_sysvq0asl((*s_53));
    if (newLen_13 <= ((NI32)6)){
      NC8* inl_0 = ((NC8*)((NU32)(((NU32)(&(*s_53).bytes_0)) + 1u)));
      if (curLen_1 < newLen_13){
        zeroMem_0_sysvq0asl(((void*)((NU32)(((NU32)(((NU32)(&(*s_53).bytes_0)) + 1u)) + ((NU32)curLen_1)))), ((NI32)(newLen_13 - curLen_1)));
        (*((NU8*)(&(*s_53).bytes_0))) = ((NU8)newLen_13);}
      else {
        if (newLen_13 <= ((NI32)3)){
          NU32 X60Qx_256 = zeroSwarPadImpl_0_sysvq0asl((*s_53).bytes_0, newLen_13);
          (*s_53).bytes_0 = X60Qx_256;}
        else {
          (*((NU8*)(&(*s_53).bytes_0))) = ((NU8)newLen_13);}}}
    else {
      transitionToLong_0_sysvq0asl(s_53, curLen_1, newLen_13);
      if (((NI32)(*((NU8*)(&(*s_53).bytes_0)))) == ((NI32)255)){
        zeroMem_0_sysvq0asl(((void*)((NU32)(((NU32)(&(*(*s_53).more_0).data_0[0])) + ((NU32)curLen_1)))), ((NI32)(newLen_13 - curLen_1)));}}}
  else {
    NI32 curLen_2 = len_4_sysvq0asl((*s_53));
    ensureUniqueLong_0_sysvq0asl(s_53, curLen_2, newLen_13);
    if (((NI32)(*((NU8*)(&(*s_53).bytes_0)))) == ((NI32)255)){
      if (curLen_2 < newLen_13){
        zeroMem_0_sysvq0asl(((void*)((NU32)(((NU32)(&(*(*s_53).more_0).data_0[0])) + ((NU32)curLen_2)))), ((NI32)(newLen_13 - curLen_2)));}
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&(*s_53).bytes_0)) + 1u)))), ((void*)(&(*(*s_53).more_0).data_0[0])), ((NI32)3));}}}
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
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_55, NI32 i_15, NC8 c_15){
  NB8 X60Qx_259;
  NI32 X60Qx_260 = len_4_sysvq0asl((*s_55));
  if (i_15 < X60Qx_260){
    X60Qx_259 = (0 <= i_15);}
  else {
    X60Qx_259 = NIM_FALSE;}
  if ((!X60Qx_259)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I11201514831099767300_sysvq0asl)}
    );}
  prepareMutation_0_sysvq0asl(s_55);
  if (((NI32)6) < ((NI32)(*((NU8*)(&(*s_55).bytes_0))))){
    (*(*s_55).more_0).data_0[i_15] = c_15;
    if (i_15 < ((NI32)3)){
      ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
  else {
    ((NC8*)((NU32)(((NU32)(&(*s_55).bytes_0)) + 1u)))[i_15] = c_15;}}
string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_56, NI32 first_0, NI32 last_0){
  string_0_sysvq0asl result_113;
  nimStrWasMoved((&result_113));
  nimStrDestroy(result_113);
  result_113 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 sLen_2 = len_4_sysvq0asl(s_56);
  NI32 f_4 = max_2_sysvq0asl(first_0, 0);
  NI32 X60Qx_261 = min_2_sysvq0asl(last_0, ((NI32)(sLen_2 - 1)));
  NI32 l_2 = ((NI32)(X60Qx_261 + 1));
  if (l_2 <= f_4){
    return result_113;}
  NI32 newLen_17 = ((NI32)(l_2 - f_4));
  NC8* src_7 = rawData_1_sysvq0asl((&s_56));
  if (newLen_17 <= ((NI32)6)){
    (*((NU8*)(&result_113.bytes_0))) = ((NU8)newLen_17);
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&result_113.bytes_0)) + 1u)))), ((void*)((NU32)(((NU32)src_7) + ((NU32)f_4)))), newLen_17);}
  else {
    void* X60Qx_262 = alloc_1_sysvq0asl(((NI32)(((NI32)12) + newLen_17)));
    LongString_0_sysvq0asl* p_38 = ((LongString_0_sysvq0asl*)X60Qx_262);
    if ((!(p_38 == NIM_NIL))){
      (*p_38).rc_0 = 0;
      (*p_38).fullLen_0 = newLen_17;
      (*p_38).capImpl_0 = newLen_17;
      copyMem_0_sysvq0asl(((void*)(&(*p_38).data_0[0])), ((void*)((NU32)(((NU32)src_7) + ((NU32)f_4)))), newLen_17);
      result_113.more_0 = p_38;
      (*((NU8*)(&result_113.bytes_0))) = ((NU8)((NI32)255));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&result_113.bytes_0)) + 1u)))), ((void*)(&(*p_38).data_0[0])), ((NI32)3));}
    else {
      oomHandler_0_sysvq0asl(((NI32)(((NI32)12) + newLen_17)));
      result_113.bytes_0 = ((NU32)21760775509248519ull);
      result_113.more_0 = NIM_NIL;}}
  return result_113;}
string_0_sysvq0asl substr_1_sysvq0asl(string_0_sysvq0asl s_57, NI32 first_1){
  string_0_sysvq0asl result_114;
  nimStrWasMoved((&result_114));
  nimStrDestroy(result_114);
  NI32 X60Qx_263 = high_4_sysvq0asl(s_57);
  string_0_sysvq0asl X60Qx_264 = substr_0_sysvq0asl(s_57, first_1, X60Qx_263);
  result_114 = X60Qx_264;
  return result_114;}
static inline NI32 ctzImpl_0_sysvq0asl(NU32 x_313){
  NI32 result_116;
  NI32 X60Qx_266 = __builtin_ctzll(((NU64)x_313));
  result_116 = ((NI32)X60Qx_266);
  return result_116;}
static inline NU32 swarCharMask_0_sysvq0asl(NI32 n_2){
  NU32 result_119;
  result_119 = ((NU32)(((NU32)(((NU32)(1u << ((NU32)((NI32)(n_2 * 8))))) - 1u)) << 8));
  return result_119;}
static inline NI32 cmpInlineBytes_0_sysvq0asl(NC8* a_47, NC8* b_10, NI32 n_3){
  NI32 result_120;
  result_120 = 0;
  {
    NI32 X60Qlf_3 = 0;
    NI32 X60Qlf_4 = n_3;
    NI32 X60Qlf_5 = X60Qlf_3;
    {
      while (X60Qlf_5 < X60Qlf_4){
        {
          NC8 X60Qii_2 = a_47[X60Qlf_5];
          NC8 X60Qii_3 = b_10[X60Qlf_5];
          if (X60Qii_2 < X60Qii_3){
            return -1;}
          if (X60Qii_3 < X60Qii_2){
            return 1;}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_120;}
static inline NI32 cmpShortInlineLE_0_sysvq0asl(NU32 abytes_1, NU32 bbytes_1, NI32 aslen_1, NI32 bslen_1){
  NI32 result_122;
  NI32 minLen_1 = min_2_sysvq0asl(aslen_1, bslen_1);
  if (0 < minLen_1){
    NU32 diffMask_0 = ((NU32)(((NU32)(1u << ((NI32)(minLen_1 * 8)))) - 1u));
    NU32 diff_3 = ((NU32)(((NU32)(((NU32)(abytes_1 ^ bbytes_1)) >> 8)) & diffMask_0));
    if ((!(diff_3 == ((NU32)0)))){
      NI32 X60Qx_270 = ctzImpl_0_sysvq0asl(diff_3);
      NI32 byteShift_0 = ((NI32)(((NI32)(((NI32)(((NI32)X60Qx_270) >> ((NU32)3))) * 8)) + 8));
      NU32 ac_2 = ((NU32)(((NU32)(abytes_1 >> byteShift_0)) & 255u));
      NU32 bc_2 = ((NU32)(((NU32)(bbytes_1 >> byteShift_0)) & 255u));
      if (ac_2 < bc_2){
        return -1;}
      return 1;}}
  result_122 = ((NI32)(aslen_1 - bslen_1));
  return result_122;}
static inline NI32 cmpShortInline_0_sysvq0asl(NU32 abytes_2, NU32 bbytes_2, NI32 aslen_2, NI32 bslen_2){
  NI32 result_123;
  NI32 X60Qx_271 = cmpShortInlineLE_0_sysvq0asl(abytes_2, bbytes_2, aslen_2, bslen_2);
  result_123 = X60Qx_271;
  return result_123;}
NI32 cmpStringPtrs_0_sysvq0asl(string_0_sysvq0asl* a_48, string_0_sysvq0asl* b_11){
  NI32 result_124;
  NU32 abytes_3 = (*a_48).bytes_0;
  NU32 bbytes_3 = (*b_11).bytes_0;
  NI32 aslen_3 = ssLenOf_0_sysvq0asl(abytes_3);
  NI32 bslen_3 = ssLenOf_0_sysvq0asl(bbytes_3);
  NB8 X60Qx_272;
  if (aslen_3 <= ((NI32)3)){
    X60Qx_272 = (bslen_3 <= ((NI32)3));}
  else {
    X60Qx_272 = NIM_FALSE;}
  if (X60Qx_272){
    NI32 X60Qx_273 = cmpShortInline_0_sysvq0asl(abytes_3, bbytes_3, aslen_3, bslen_3);
    result_124 = X60Qx_273;
    return result_124;}
  NB8 X60Qx_274;
  if (aslen_3 <= ((NI32)6)){
    X60Qx_274 = (bslen_3 <= ((NI32)6));}
  else {
    X60Qx_274 = NIM_FALSE;}
  if (X60Qx_274){
    NI32 minLen_2 = min_2_sysvq0asl(aslen_3, bslen_3);
    NI32 pfxLen_0 = min_2_sysvq0asl(minLen_2, ((NI32)3));
    NI32 X60Qx_275 = cmpInlineBytes_0_sysvq0asl(((NC8*)((NU32)(((NU32)a_48) + 1u))), ((NC8*)((NU32)(((NU32)b_11) + 1u))), pfxLen_0);
    result_124 = X60Qx_275;
    if ((!(result_124 == 0))){
      return result_124;}
    if (((NI32)3) < minLen_2){
      NI32 X60Qx_276 = cmpInlineBytes_0_sysvq0asl(((NC8*)((NU32)(((NU32)(((NU32)a_48) + 1u)) + ((NU32)((NI32)3))))), ((NC8*)((NU32)(((NU32)(((NU32)b_11) + 1u)) + ((NU32)((NI32)3))))), ((NI32)(minLen_2 - ((NI32)3))));
      result_124 = X60Qx_276;}
    if (result_124 == 0){
      result_124 = ((NI32)(aslen_3 - bslen_3));}
    return result_124;}
  NI32 X60Qx_27;
  if (((NI32)6) < aslen_3){
    X60Qx_27 = (*(*a_48).more_0).fullLen_0;}
  else {
    X60Qx_27 = aslen_3;}
  NI32 la_0 = X60Qx_27;
  NI32 X60Qx_28;
  if (((NI32)6) < bslen_3){
    X60Qx_28 = (*(*b_11).more_0).fullLen_0;}
  else {
    X60Qx_28 = bslen_3;}
  NI32 lb_0 = X60Qx_28;
  NI32 minLen_3 = min_2_sysvq0asl(la_0, lb_0);
  NI32 pfxLen_1 = min_2_sysvq0asl(minLen_3, ((NI32)3));
  NI32 X60Qx_277 = cmpInlineBytes_0_sysvq0asl(((NC8*)((NU32)(((NU32)a_48) + 1u))), ((NC8*)((NU32)(((NU32)b_11) + 1u))), pfxLen_1);
  result_124 = X60Qx_277;
  if ((!(result_124 == 0))){
    return result_124;}
  if (minLen_3 <= ((NI32)3)){
    result_124 = ((NI32)(la_0 - lb_0));
    return result_124;}
  NC8* X60Qx_29;
  if (((NI32)6) < aslen_3){
    X60Qx_29 = ((NC8*)((NU32)(((NU32)(&(*(*a_48).more_0).data_0[0])) + ((NU32)((NI32)3)))));}
  else {
    X60Qx_29 = ((NC8*)((NU32)(((NU32)(((NU32)a_48) + 1u)) + ((NU32)((NI32)3)))));}
  NC8* ap_0 = X60Qx_29;
  NC8* X60Qx_30;
  if (((NI32)6) < bslen_3){
    X60Qx_30 = ((NC8*)((NU32)(((NU32)(&(*(*b_11).more_0).data_0[0])) + ((NU32)((NI32)3)))));}
  else {
    X60Qx_30 = ((NC8*)((NU32)(((NU32)(((NU32)b_11) + 1u)) + ((NU32)((NI32)3)))));}
  NC8* bp_0 = X60Qx_30;
  NI32 X60Qx_278 = cmpMem_0_sysvq0asl(((void*)ap_0), ((void*)bp_0), ((NI32)(minLen_3 - ((NI32)3))));
  result_124 = X60Qx_278;
  if (result_124 == 0){
    result_124 = ((NI32)(la_0 - lb_0));}
  return result_124;}
NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12){
  NB8 result_125;
  NU32 abytes_4 = a_49.bytes_0;
  NU32 bbytes_4 = b_12.bytes_0;
  NI32 aslen_4 = ssLenOf_0_sysvq0asl(abytes_4);
  NI32 bslen_4 = ssLenOf_0_sysvq0asl(bbytes_4);
  NB8 X60Qx_279;
  if (aslen_4 <= ((NI32)3)){
    X60Qx_279 = (bslen_4 <= ((NI32)3));}
  else {
    X60Qx_279 = NIM_FALSE;}
  if (X60Qx_279){
    result_125 = (abytes_4 == bbytes_4);
    return result_125;}
  NI32 X60Qx_31;
  if (((NI32)6) < aslen_4){
    X60Qx_31 = (*a_49.more_0).fullLen_0;}
  else {
    X60Qx_31 = aslen_4;}
  NI32 la_1 = X60Qx_31;
  NI32 X60Qx_32;
  if (((NI32)6) < bslen_4){
    X60Qx_32 = (*b_12.more_0).fullLen_0;}
  else {
    X60Qx_32 = bslen_4;}
  NI32 lb_1 = X60Qx_32;
  if ((!(la_1 == lb_1))){
    return NIM_FALSE;}
  if (la_1 == 0){
    return NIM_TRUE;}
  NB8 X60Qx_280;
  if (aslen_4 <= ((NI32)6)){
    X60Qx_280 = (bslen_4 <= ((NI32)6));}
  else {
    X60Qx_280 = NIM_FALSE;}
  if (X60Qx_280){
    if ((!(abytes_4 == bbytes_4))){
      return NIM_FALSE;}
    NI32 X60Qx_281 = cmpMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(((NU32)(&a_49)) + 1u)) + ((NU32)((NI32)3)))))), ((void*)((NC8*)((NU32)(((NU32)(((NU32)(&b_12)) + 1u)) + ((NU32)((NI32)3)))))), ((NI32)(la_1 - ((NI32)3))));
    result_125 = (X60Qx_281 == 0);
    return result_125;}
  NI32 X60Qx_282 = cmpStringPtrs_0_sysvq0asl((&a_49), (&b_12));
  result_125 = (X60Qx_282 == 0);
  return result_125;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
NI32 cmp_1_sysvq0asl(string_0_sysvq0asl a_51, string_0_sysvq0asl b_14){
  NI32 result_128;
  NU32 abytes_5 = a_51.bytes_0;
  NU32 bbytes_5 = b_14.bytes_0;
  NI32 aslen_5 = ssLenOf_0_sysvq0asl(abytes_5);
  NI32 bslen_5 = ssLenOf_0_sysvq0asl(bbytes_5);
  NB8 X60Qx_287;
  if (aslen_5 <= ((NI32)3)){
    X60Qx_287 = (bslen_5 <= ((NI32)3));}
  else {
    X60Qx_287 = NIM_FALSE;}
  if (X60Qx_287){
    NI32 X60Qx_288 = cmpShortInline_0_sysvq0asl(abytes_5, bbytes_5, aslen_5, bslen_5);
    result_128 = X60Qx_288;
    return result_128;}
  NI32 X60Qx_289 = cmpStringPtrs_0_sysvq0asl((&a_51), (&b_14));
  result_128 = X60Qx_289;
  return result_128;}
static inline NB8 ltQ_17_sysvq0asl(string_0_sysvq0asl a_53, string_0_sysvq0asl b_16){
  NB8 result_130;
  NI32 X60Qx_291 = cmp_1_sysvq0asl(a_53, b_16);
  result_130 = (X60Qx_291 < 0);
  return result_130;}
NB8 startsWithImpl_0_sysvq0asl(string_0_sysvq0asl s_59, string_0_sysvq0asl prefix_0){
  NB8 result_131;
  NU32 pbytes_0 = prefix_0.bytes_0;
  NI32 pslen_0 = ssLenOf_0_sysvq0asl(pbytes_0);
  NU32 sbytes_0 = s_59.bytes_0;
  NI32 sslen_0 = ssLenOf_0_sysvq0asl(sbytes_0);
  NI32 X60Qx_292 = min_2_sysvq0asl(pslen_0, ((NI32)3));
  NU32 charMask_0 = swarCharMask_0_sysvq0asl(X60Qx_292);
  if ((!(((NU32)(sbytes_0 & charMask_0)) == ((NU32)(pbytes_0 & charMask_0))))){
    return NIM_FALSE;}
  NI32 X60Qx_33;
  if (((NI32)6) < sslen_0){
    X60Qx_33 = (*s_59.more_0).fullLen_0;}
  else {
    X60Qx_33 = sslen_0;}
  NI32 sLen_3 = X60Qx_33;
  NI32 X60Qx_34;
  if (((NI32)6) < pslen_0){
    X60Qx_34 = (*prefix_0.more_0).fullLen_0;}
  else {
    X60Qx_34 = pslen_0;}
  NI32 pLen_0 = X60Qx_34;
  if (sLen_3 < pLen_0){
    return NIM_FALSE;}
  if (pLen_0 <= ((NI32)3)){
    return NIM_TRUE;}
  NC8* X60Qx_35;
  if (((NI32)6) < sslen_0){
    X60Qx_35 = ((NC8*)((NU32)(((NU32)(&(*s_59.more_0).data_0[0])) + ((NU32)((NI32)3)))));}
  else {
    X60Qx_35 = ((NC8*)((NU32)(((NU32)(((NU32)(&s_59)) + 1u)) + ((NU32)((NI32)3)))));}
  NC8* sTail_0 = X60Qx_35;
  NC8* X60Qx_36;
  if (((NI32)6) < pslen_0){
    X60Qx_36 = ((NC8*)((NU32)(((NU32)(&(*prefix_0.more_0).data_0[0])) + ((NU32)((NI32)3)))));}
  else {
    X60Qx_36 = ((NC8*)((NU32)(((NU32)(((NU32)(&prefix_0)) + 1u)) + ((NU32)((NI32)3)))));}
  NC8* pTail_0 = X60Qx_36;
  NI32 X60Qx_293 = cmpMem_0_sysvq0asl(((void*)sTail_0), ((void*)pTail_0), ((NI32)(pLen_0 - ((NI32)3))));
  result_131 = (X60Qx_293 == 0);
  return result_131;}
string_0_sysvq0asl newString_0_sysvq0asl(NI32 len_4){
  string_0_sysvq0asl result_132;
  nimStrWasMoved((&result_132));
  nimStrDestroy(result_132);
  result_132 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (len_4 <= 0){
    return result_132;}
  if (len_4 <= ((NI32)6)){
    (*((NU8*)(&result_132.bytes_0))) = ((NU8)len_4);
    zeroMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&result_132.bytes_0)) + 1u)))), len_4);}
  else {
    void* X60Qx_294 = alloc_1_sysvq0asl(((NI32)(((NI32)12) + len_4)));
    LongString_0_sysvq0asl* p_39 = ((LongString_0_sysvq0asl*)X60Qx_294);
    if ((!(p_39 == NIM_NIL))){
      zeroMem_0_sysvq0asl(((void*)p_39), ((NI32)(((NI32)12) + len_4)));
      (*p_39).rc_0 = 0;
      (*p_39).fullLen_0 = len_4;
      (*p_39).capImpl_0 = len_4;
      result_132.more_0 = p_39;
      (*((NU8*)(&result_132.bytes_0))) = ((NU8)((NI32)255));}
    else {
      oomHandler_0_sysvq0asl(((NI32)(((NI32)12) + len_4)));
      result_132.bytes_0 = ((NU32)21760775509248519ull);
      result_132.more_0 = NIM_NIL;}}
  return result_132;}
string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5){
  string_0_sysvq0asl result_133;
  nimStrWasMoved((&result_133));
  nimStrDestroy(result_133);
  result_133 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (len_5 <= ((NI32)6)){
    return result_133;}
  void* X60Qx_295 = alloc_1_sysvq0asl(((NI32)(((NI32)12) + len_5)));
  LongString_0_sysvq0asl* p_40 = ((LongString_0_sysvq0asl*)X60Qx_295);
  if ((!(p_40 == NIM_NIL))){
    zeroMem_0_sysvq0asl(((void*)p_40), ((NI32)(((NI32)12) + len_5)));
    (*p_40).rc_0 = 0;
    (*p_40).fullLen_0 = 0;
    (*p_40).capImpl_0 = len_5;
    result_133.more_0 = p_40;
    (*((NU8*)(&result_133.bytes_0))) = ((NU8)((NI32)255));}
  else {
    oomHandler_0_sysvq0asl(((NI32)(((NI32)12) + len_5)));
    result_133.bytes_0 = ((NU32)21760775509248519ull);
    result_133.more_0 = NIM_NIL;}
  return result_133;}
string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17){
  string_0_sysvq0asl result_134;
  nimStrWasMoved((&result_134));
  nimStrDestroy(result_134);
  result_134 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 X60Qx_296 = len_4_sysvq0asl(a_54);
  NI32 X60Qx_297 = len_4_sysvq0asl(b_17);
  NI32 rlen_0 = ((NI32)(X60Qx_296 + X60Qx_297));
  if (rlen_0 == 0){
    return result_134;}
  if (rlen_0 <= ((NI32)6)){
    NI32 al_0 = len_4_sysvq0asl(a_54);
    (*((NU8*)(&result_134.bytes_0))) = ((NU8)rlen_0);
    if (0 < al_0){
      NC8* X60Qx_298 = rawData_1_sysvq0asl((&a_54));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&result_134.bytes_0)) + 1u)))), ((void*)X60Qx_298), al_0);}
    NI32 X60Qx_299 = len_4_sysvq0asl(b_17);
    if (0 < X60Qx_299){
      NC8* X60Qx_300 = rawData_1_sysvq0asl((&b_17));
      NI32 X60Qx_301 = len_4_sysvq0asl(b_17);
      copyMem_0_sysvq0asl(((void*)((NU32)(((NU32)(((NU32)(&result_134.bytes_0)) + 1u)) + ((NU32)al_0)))), ((void*)X60Qx_300), X60Qx_301);}}
  else {
    void* X60Qx_302 = alloc_1_sysvq0asl(((NI32)(((NI32)12) + rlen_0)));
    LongString_0_sysvq0asl* p_41 = ((LongString_0_sysvq0asl*)X60Qx_302);
    if ((!(p_41 == NIM_NIL))){
      (*p_41).rc_0 = 0;
      (*p_41).fullLen_0 = rlen_0;
      (*p_41).capImpl_0 = rlen_0;
      NI32 al_1 = len_4_sysvq0asl(a_54);
      if (0 < al_1){
        NC8* X60Qx_303 = rawData_1_sysvq0asl((&a_54));
        copyMem_0_sysvq0asl(((void*)(&(*p_41).data_0[0])), ((void*)X60Qx_303), al_1);}
      NI32 X60Qx_304 = len_4_sysvq0asl(b_17);
      if (0 < X60Qx_304){
        NC8* X60Qx_305 = rawData_1_sysvq0asl((&b_17));
        NI32 X60Qx_306 = len_4_sysvq0asl(b_17);
        copyMem_0_sysvq0asl(((void*)((NU32)(((NU32)(&(*p_41).data_0[0])) + ((NU32)al_1)))), ((void*)X60Qx_305), X60Qx_306);}
      result_134.more_0 = p_41;
      (*((NU8*)(&result_134.bytes_0))) = ((NU8)((NI32)255));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&result_134.bytes_0)) + 1u)))), ((void*)(&(*p_41).data_0[0])), ((NI32)3));}
    else {
      oomHandler_0_sysvq0asl(((NI32)(((NI32)12) + rlen_0)));
      result_134.bytes_0 = ((NU32)21760775509248519ull);
      result_134.more_0 = NIM_NIL;}}
  return result_134;}
static inline string_0_sysvq0asl terminatingZero_0_sysvq0asl(string_0_sysvq0asl s_60){
  string_0_sysvq0asl result_138;
  nimStrWasMoved((&result_138));
  nimStrDestroy(result_138);
  string_0_sysvq0asl X60Qx_309 = ampQ_0_sysvq0asl(s_60, (string_0_sysvq0asl){
    .bytes_0 = 1u, .more_0 = NIM_NIL}
  );
  result_138 = X60Qx_309;
  NI32 X60Qx_310 = len_4_sysvq0asl(s_60);
  shrink_1_sysvq0asl((&result_138), X60Qx_310);
  return result_138;}
string_0_sysvq0asl borrowCStringUnsafe_0_sysvq0asl(NC8* s_61, NI32 l_0){
  string_0_sysvq0asl result_139;
  nimStrWasMoved((&result_139));
  nimStrDestroy(result_139);
  result_139 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (l_0 <= 0){
    return result_139;}
  if (l_0 <= ((NI32)6)){
    (*((NU8*)(&result_139.bytes_0))) = ((NU8)l_0);
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&result_139.bytes_0)) + 1u)))), ((void*)s_61), l_0);}
  else {
    void* X60Qx_311 = alloc_1_sysvq0asl(((NI32)(((NI32)12) + l_0)));
    LongString_0_sysvq0asl* p_42 = ((LongString_0_sysvq0asl*)X60Qx_311);
    if ((!(p_42 == NIM_NIL))){
      (*p_42).rc_0 = 0;
      (*p_42).fullLen_0 = l_0;
      (*p_42).capImpl_0 = l_0;
      copyMem_0_sysvq0asl(((void*)(&(*p_42).data_0[0])), ((void*)s_61), l_0);
      result_139.more_0 = p_42;
      (*((NU8*)(&result_139.bytes_0))) = ((NU8)((NI32)255));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&result_139.bytes_0)) + 1u)))), ((void*)(&(*p_42).data_0[0])), ((NI32)3));}
    else {
      oomHandler_0_sysvq0asl(((NI32)(((NI32)12) + l_0)));
      result_139.bytes_0 = ((NU32)21760775509248519ull);
      result_139.more_0 = NIM_NIL;}}
  return result_139;}
string_0_sysvq0asl nimBorrowCStringUnsafe(NC8* s_62){
  string_0_sysvq0asl result_140;
  nimStrWasMoved((&result_140));
  nimStrDestroy(result_140);
  NI32 X60Qx_312 = len_5_sysvq0asl(s_62);
  string_0_sysvq0asl X60Qx_313 = borrowCStringUnsafe_0_sysvq0asl(s_62, X60Qx_312);
  result_140 = X60Qx_313;
  return result_140;}
void ensureTerminatingZero_0_sysvq0asl(string_0_sysvq0asl* s_63){
  NI32 oldLen_3 = len_4_sysvq0asl((*s_63));
  add_1_sysvq0asl(s_63, (NC8)'\000');
  shrink_1_sysvq0asl(s_63, oldLen_3);}
NC8* toCString_0_sysvq0asl(string_0_sysvq0asl* s_64){
  NC8* result_141;
  ensureTerminatingZero_0_sysvq0asl(s_64);
  NC8* X60Qx_314 = rawData_1_sysvq0asl((&(*s_64)));
  result_141 = ((NC8*)X60Qx_314);
  return result_141;}
string_0_sysvq0asl fromCString_0_sysvq0asl(NC8* s_65){
  string_0_sysvq0asl result_142;
  nimStrWasMoved((&result_142));
  nimStrDestroy(result_142);
  result_142 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NI32 l_3 = len_5_sysvq0asl(s_65);
  if (l_3 == 0){
    return result_142;}
  if (l_3 <= ((NI32)6)){
    (*((NU8*)(&result_142.bytes_0))) = ((NU8)l_3);
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&result_142.bytes_0)) + 1u)))), ((void*)s_65), l_3);}
  else {
    void* X60Qx_315 = alloc_1_sysvq0asl(((NI32)(((NI32)12) + l_3)));
    LongString_0_sysvq0asl* p_43 = ((LongString_0_sysvq0asl*)X60Qx_315);
    if ((!(p_43 == NIM_NIL))){
      (*p_43).rc_0 = 0;
      (*p_43).fullLen_0 = l_3;
      (*p_43).capImpl_0 = l_3;
      copyMem_0_sysvq0asl(((void*)(&(*p_43).data_0[0])), ((void*)s_65), l_3);
      result_142.more_0 = p_43;
      (*((NU8*)(&result_142.bytes_0))) = ((NU8)((NI32)255));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU32)(((NU32)(&result_142.bytes_0)) + 1u)))), ((void*)(&(*p_43).data_0[0])), ((NI32)3));}
    else {
      oomHandler_0_sysvq0asl(((NI32)(((NI32)12) + l_3)));
      result_142.bytes_0 = ((NU32)21760775509248519ull);
      result_142.more_0 = NIM_NIL;}}
  return result_142;}
static inline openArray_0_Ijk0jkw1_feaji4clb1 toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_67){
  openArray_0_Ijk0jkw1_feaji4clb1 result_146;
  NC8* X60Qx_316 = readRawData_0_sysvq0asl((&(*s_67)), 0);
  NI32 X60Qx_317 = len_4_sysvq0asl((*s_67));
  result_146 = (openArray_0_Ijk0jkw1_feaji4clb1){
    .a_0 = X60Qx_316, .len_0 = X60Qx_317}
  ;
  return result_146;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline NB8 arcIsUnique_0_sysvq0asl(NI32* memLoc_2){
  NB8 result_157;
  NI32 X60Qx_320 = __atomic_load_n((&(*memLoc_2)), __ATOMIC_ACQUIRE);
  result_157 = (X60Qx_320 == 0);
  return result_157;}
void writeErr_0_sysvq0asl(NI64 x_330){
  fprintf(stderr, "%lld", x_330);}
void writeErr_1_sysvq0asl(NU64 x_331){
  fprintf(stderr, "%llu", x_331);}
void writeErr_2_sysvq0asl(string_0_sysvq0asl s_68){
  NC8* X60Qx_321 = readRawData_0_sysvq0asl((&s_68), 0);
  NI32 X60Qx_322 = len_4_sysvq0asl(s_68);
  NU32 X60Qx_323 = fwrite(((void*)X60Qx_321), 1u, ((NU32)X60Qx_322), stderr);}
void writeErr_3_sysvq0asl(NC8* s_69){
  NI32 X60Qx_324 = len_5_sysvq0asl(s_69);
  NU32 X60Qx_325 = fwrite(((void*)s_69), 1u, ((NU32)X60Qx_324), stderr);}
void panic_0_sysvq0asl(string_0_sysvq0asl s_70){
  writeErr_2_sysvq0asl(s_70);
  exit(((NI32)1));}
static inline NI32 nimIcheckAB(NI32 i_18, NI32 a_68, NI32 b_21){
  NI32 result_158;
  NB8 X60Qx_326;
  if (a_68 <= i_18){
    X60Qx_326 = (i_18 <= b_21);}
  else {
    X60Qx_326 = NIM_FALSE;}
  if (X60Qx_326){
    result_158 = ((NI32)(i_18 - a_68));}
  else {
    result_158 = 0;
    raiseIndexError3_0_I113jpc1_sysvq0asl(i_18, a_68, b_21);}
  return result_158;}
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22){
  NI32 result_159;
  NB8 X60Qx_327;
  if (0 <= i_19){
    X60Qx_327 = (i_19 <= b_22);}
  else {
    X60Qx_327 = NIM_FALSE;}
  if (X60Qx_327){
    result_159 = i_19;}
  else {
    result_159 = 0;
    raiseIndexError3_0_I113jpc1_sysvq0asl(i_19, 0, b_22);}
  return result_159;}
static inline NU32 nimUcheckAB(NU32 i_20, NU32 a_69, NU32 b_23){
  NU32 result_160;
  result_160 = ((NU32)(i_20 - a_69));
  if (b_23 < result_160){
    raiseIndexError3_0_Ic5mmkg_sysvq0asl(i_20, a_69, b_23);}
  return result_160;}
static inline NU32 nimUcheckB(NU32 i_21, NU32 b_24){
  NU32 result_161;
  result_161 = i_21;
  if (b_24 < result_161){
    raiseIndexError3_0_Ic5mmkg_sysvq0asl(i_21, ((NU32)0), b_24);}
  return result_161;}
static inline void nimInvalidObjConv(string_0_sysvq0asl name_0){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1986947582u, .more_0 = (&strlit_0_I15539159382304113184_sysvq0asl)}
  );
  writeErr_2_sysvq0asl(name_0);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  exit(((NI32)1));}
static inline void nimChckNilDisp(void* p_25){
  if (p_25 == NIM_NIL){
    writeErr_2_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1851876350u, .more_0 = (&strlit_0_I14281474217946372742_sysvq0asl)}
    );
    exit(((NI32)1));}}
void procAddrError_0_sysvq0asl(NC8* name_1){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1970234366u, .more_0 = (&strlit_0_I10604297744791418982_sysvq0asl)}
  );
  writeErr_3_sysvq0asl(name_1);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  exit(1);}
void* nimLoadLibrary(NC8* path_2){
  void* result_162;
  int flags_1 = ((NI32)2);
  void* X60Qx_328 = dlopen(path_2, flags_1);
  result_162 = X60Qx_328;
  return result_162;}
void* nimGetProcAddr(void* lib_3, NC8* name_3){
  void* result_163;
  void* X60Qx_329 = dlsym(lib_3, name_3);
  result_163 = X60Qx_329;
  if (result_163 == NIM_NIL){
    procAddrError_0_sysvq0asl(name_3);}
  return result_163;}
void* nimDynlibLoadStep(void* prev_0, NC8* cand_0){
  void* result_164;
  if ((!(prev_0 == NIM_NIL))){
    result_164 = prev_0;}
  else {
    void* X60Qx_330 = nimLoadLibrary(cand_0);
    result_164 = X60Qx_330;}
  return result_164;}
void* nimDynlibCheck(void* lib_4, NC8* path_3){
  void* result_165;
  if (lib_4 == NIM_NIL){
    writeErr_2_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1970234366u, .more_0 = (&strlit_0_I16690852185662743073_sysvq0asl)}
    );
    writeErr_3_sysvq0asl(path_3);
    writeErr_2_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561u, .more_0 = NIM_NIL}
    );
    exit(1);}
  result_165 = lib_4;
  return result_165;}
static inline NC8 chr_0_sysvq0asl(NI32 u_0){
  NC8 result_168;
  result_168 = ((NC8)((NI32)u_0));
  return result_168;}
static inline void utoa2Digits_0_sysvq0asl(openArray_0_Ijk0jkw1_feaji4clb1 buf_1, NI32 pos_0, NU32 digits_0){
  NI32 X60Qx_332 = nimIcheckB(((NI32)((NU32)(((NU32)2) * digits_0))), 199);
  putQ_10_If2353w_sysvq0asl(buf_1, pos_0, digits100_0_sysvq0asl.a[X60Qx_332]);
  NI32 X60Qx_333 = nimIcheckB(((NI32)((NU32)(((NU32)(((NU32)2) * digits_0)) + ((NU32)1)))), 199);
  putQ_10_If2353w_sysvq0asl(buf_1, ((NI32)(pos_0 + 1)), digits100_0_sysvq0asl.a[X60Qx_333]);}
static inline NI32 trailingZeros2Digits_0_sysvq0asl(NU32 digits_1){
  NI32 result_169;
  NI32 X60Qx_334 = nimIcheckB(((NI32)digits_1), 99);
  result_169 = ((NI32)trailingZeros100_0_sysvq0asl.a[X60Qx_334]);
  return result_169;}
Double_0_sysvq0asl constructDouble_0_sysvq0asl(NF64 value_3){
  Double_0_sysvq0asl result_186;
  NU64 X60Qx_361;
  copyMem_0_sysvq0asl((&X60Qx_361), (&value_3), sizeof(NU64));
  result_186 = (Double_0_sysvq0asl){
    .bits_0 = X60Qx_361}
  ;
  return result_186;}
NU64 physicalSignificand_1_sysvq0asl(Double_0_sysvq0asl this_3){
  NU64 result_187;
  result_187 = ((NU64)(this_3.bits_0 & ((NU64)4503599627370495ull)));
  return result_187;}
NU64 physicalExponent_1_sysvq0asl(Double_0_sysvq0asl this_4){
  NU64 result_188;
  result_188 = ((NU64)(((NU64)(this_4.bits_0 & ((NU64)9218868437227405312ull))) >> ((NI32)(((NI32)53) - 1))));
  return result_188;}
NI32 signBit_1_sysvq0asl(Double_0_sysvq0asl this_5){
  NI32 result_189;
  result_189 = ((NI32)(!(((NU64)(this_5.bits_0 & ((NU64)9223372036854775808ull))) == ((NU64)0))));
  return result_189;}
static inline NI32 dbFloorDivPow2_0_sysvq0asl(NI32 x_342, NI32 n_6){
  NI32 result_190;
  result_190 = ((NI32)(((NI32)x_342) >> ((NU32)n_6)));
  return result_190;}
static inline NI32 dbFloorLog2Pow10_0_sysvq0asl(NI32 e_2){
  NI32 result_191;
  NI32 X60Qx_362 = dbFloorDivPow2_0_sysvq0asl(((NI32)(e_2 * 1741647)), 19);
  result_191 = X60Qx_362;
  return result_191;}
static inline NI32 dbFloorLog10Pow2_0_sysvq0asl(NI32 e_3){
  NI32 result_192;
  NI32 X60Qx_363 = dbFloorDivPow2_0_sysvq0asl(((NI32)(e_3 * 1262611)), 22);
  result_192 = X60Qx_363;
  return result_192;}
static inline NI32 dbFloorLog10ThreeQQuartersPow2_0_sysvq0asl(NI32 e_4){
  NI32 result_193;
  NI32 X60Qx_364 = dbFloorDivPow2_0_sysvq0asl(((NI32)(((NI32)(e_4 * 1262611)) - 524031)), 22);
  result_193 = X60Qx_364;
  return result_193;}
static inline uint64x2_0_sysvq0asl computePow10_0_sysvq0asl(NI32 k_1){
  uint64x2_0_sysvq0asl result_194;
  NI32 X60Qx_365 = nimIcheckB(((NI32)(k_1 - ((NI32)-292))), 618);
  result_194 = pow10_3.a[X60Qx_365];
  return result_194;}
static inline NB8 multipleOfPow2_1_sysvq0asl(NU64 value_4, NI32 e2_1){
  NB8 result_195;
  NB8 X60Qx_366;
  if (e2_1 < 64){
    X60Qx_366 = (((NU64)(value_4 & ((NU64)(((NU64)(((NU64)1) << e2_1)) - ((NU64)1))))) == ((NU64)0));}
  else {
    X60Qx_366 = NIM_FALSE;}
  result_195 = X60Qx_366;
  return result_195;}
static inline NB8 multipleOfPow5_0_sysvq0asl(NU64 value_5, NI32 e5_0){
  NB8 result_196;
  NI32 X60Qx_367 = nimIcheckB(e5_0, 24);
  MulCmp_0_sysvq0asl m5_0 = mod5_0.a[X60Qx_367];
  result_196 = (((NU64)(value_5 * m5_0.mul_0)) <= m5_0.cmp_0);
  return result_196;}
static inline FloatingDecimal64_0_sysvq0asl toDecimal64AsymmetricInterval_0_sysvq0asl(NI32 e2_2){
  FloatingDecimal64_0_sysvq0asl result_197;
  NI32 minusK_2 = dbFloorLog10ThreeQQuartersPow2_0_sysvq0asl(e2_2);
  NI32 X60Qx_368 = dbFloorLog2Pow10_0_sysvq0asl(((NI32)-minusK_2));
  NI32 betaMinus1_2 = ((NI32)(e2_2 + X60Qx_368));
  uint64x2_0_sysvq0asl pow10_4 = computePow10_0_sysvq0asl(((NI32)-minusK_2));
  NU64 lowerEndpoint_0 = ((NU64)(((NU64)(pow10_4.hi_0 - ((NU64)(pow10_4.hi_0 >> ((NI32)(((NI32)53) + 1)))))) >> ((NI32)(((NI32)(64 - ((NI32)53))) - betaMinus1_2))));
  NU64 upperEndpoint_0 = ((NU64)(((NU64)(pow10_4.hi_0 + ((NU64)(pow10_4.hi_0 >> ((NI32)(((NI32)53) + 0)))))) >> ((NI32)(((NI32)(64 - ((NI32)53))) - betaMinus1_2))));
  NB8 X60Qx_369;
  if (2 <= e2_2){
    X60Qx_369 = (e2_2 <= 3);}
  else {
    X60Qx_369 = NIM_FALSE;}
  NB8 lowerEndpointIsInteger_0 = X60Qx_369;
  NU64 xi_0 = ((NU64)(lowerEndpoint_0 + ((NU64)(!lowerEndpointIsInteger_0))));
  NU64 zi_0 = upperEndpoint_0;
  NU64 q_5 = ((NU64)(zi_0 / ((NU64)10)));
  if (xi_0 <= ((NU64)(q_5 * ((NU64)10)))){
    result_197 = (FloatingDecimal64_0_sysvq0asl){
      .significand_0 = q_5, .exponent_0 = ((NI32)(minusK_2 + 1))}
    ;
    return result_197;}
  q_5 = ((NU64)(((NU64)(((NU64)(pow10_4.hi_0 >> ((NI32)(((NI32)(64 - ((NI32)(((NI32)53) + 1)))) - betaMinus1_2)))) + ((NU64)1))) / ((NU64)2)));
  if (e2_2 == -77){
    dec_0_Idgnuqw1_sysvq0asl((&q_5), ((NU64)((NI32)(!(((NU64)(q_5 % ((NU64)2))) == ((NU64)0))))));}
  else {
    inc_0_Ineawm41_party5a2l1((&q_5), ((NU64)((NI32)(q_5 < xi_0))));}
  result_197 = (FloatingDecimal64_0_sysvq0asl){
    .significand_0 = q_5, .exponent_0 = minusK_2}
  ;
  return result_197;}
static inline NU32 computeDelta_0_sysvq0asl(uint64x2_0_sysvq0asl pow10_0, NI32 betaMinus1_0){
  NU32 result_198;
  result_198 = ((NU32)((NU64)(pow10_0.hi_0 >> ((NI32)(((NI32)(64 - 1)) - betaMinus1_0)))));
  return result_198;}
static inline NU32 dbLo32_0_sysvq0asl(NU64 x_343){
  NU32 result_199;
  result_199 = ((NU32)x_343);
  return result_199;}
static inline NU32 dbHi32_0_sysvq0asl(NU64 x_344){
  NU32 result_200;
  result_200 = ((NU32)((NU64)(x_344 >> 32)));
  return result_200;}
static inline uint64x2_0_sysvq0asl mul128_0_sysvq0asl(NU64 a_70, NU64 b_25){
  uint64x2_0_sysvq0asl result_201;
  NU32 X60Qx_370 = dbLo32_0_sysvq0asl(a_70);
  NU32 X60Qx_371 = dbLo32_0_sysvq0asl(b_25);
  NU64 b00_0 = ((NU64)(((NU64)X60Qx_370) * ((NU64)X60Qx_371)));
  NU32 X60Qx_372 = dbLo32_0_sysvq0asl(a_70);
  NU32 X60Qx_373 = dbHi32_0_sysvq0asl(b_25);
  NU64 b01_1 = ((NU64)(((NU64)X60Qx_372) * ((NU64)X60Qx_373)));
  NU32 X60Qx_374 = dbHi32_0_sysvq0asl(a_70);
  NU32 X60Qx_375 = dbLo32_0_sysvq0asl(b_25);
  NU64 b10_0 = ((NU64)(((NU64)X60Qx_374) * ((NU64)X60Qx_375)));
  NU32 X60Qx_376 = dbHi32_0_sysvq0asl(a_70);
  NU32 X60Qx_377 = dbHi32_0_sysvq0asl(b_25);
  NU64 b11_1 = ((NU64)(((NU64)X60Qx_376) * ((NU64)X60Qx_377)));
  NU32 X60Qx_378 = dbHi32_0_sysvq0asl(b00_0);
  NU64 mid1_0 = ((NU64)(b10_0 + ((NU64)X60Qx_378)));
  NU32 X60Qx_379 = dbLo32_0_sysvq0asl(mid1_0);
  NU64 mid2_0 = ((NU64)(b01_1 + ((NU64)X60Qx_379)));
  NU32 X60Qx_380 = dbHi32_0_sysvq0asl(mid1_0);
  NU32 X60Qx_381 = dbHi32_0_sysvq0asl(mid2_0);
  NU64 hi_1 = ((NU64)(((NU64)(b11_1 + ((NU64)X60Qx_380))) + ((NU64)X60Qx_381)));
  NU32 X60Qx_382 = dbLo32_0_sysvq0asl(b00_0);
  NU32 X60Qx_383 = dbLo32_0_sysvq0asl(mid2_0);
  NU64 lo_0 = ((NU64)(((NU64)X60Qx_382) | ((NU64)(((NU64)X60Qx_383) << 32))));
  result_201 = (uint64x2_0_sysvq0asl){
    .hi_0 = hi_1, .lo_0 = lo_0}
  ;
  return result_201;}
static inline NU64 mulShift_0_sysvq0asl(NU64 x_345, uint64x2_0_sysvq0asl y_205){
  NU64 result_202;
  uint64x2_0_sysvq0asl p1_0 = mul128_0_sysvq0asl(x_345, y_205.hi_0);
  uint64x2_0_sysvq0asl p0_0 = mul128_0_sysvq0asl(x_345, y_205.lo_0);
  plusQeQ_0_Iar0t5x_sysvq0asl((&p1_0.lo_0), p0_0.hi_0);
  inc_0_Ineawm41_party5a2l1((&p1_0.hi_0), ((NU64)((NI32)(p1_0.lo_0 < p0_0.hi_0))));
  result_202 = p1_0.hi_0;
  return result_202;}
static inline NB8 mulParity_0_sysvq0asl(NU64 twoF_0, uint64x2_0_sysvq0asl pow10_1, NI32 betaMinus1_1){
  NB8 result_203;
  NU64 p01_0 = ((NU64)(twoF_0 * pow10_1.hi_0));
  uint64x2_0_sysvq0asl X60Qx_384 = mul128_0_sysvq0asl(twoF_0, pow10_1.lo_0);
  NU64 p10_0 = X60Qx_384.hi_0;
  NU64 mid_1 = ((NU64)(p01_0 + p10_0));
  result_203 = (!(((NU64)(mid_1 & ((NU64)(((NU64)1) << ((NI32)(64 - betaMinus1_1)))))) == ((NU64)0)));
  return result_203;}
static inline NB8 isIntegralEndpoint_0_sysvq0asl(NU64 twoF_1, NI32 e2_3, NI32 minusK_0){
  NB8 result_204;
  if (e2_3 < -2){
    return NIM_FALSE;}
  if (e2_3 <= 9){
    return NIM_TRUE;}
  if (e2_3 <= 86){
    NB8 X60Qx_385 = multipleOfPow5_0_sysvq0asl(twoF_1, minusK_0);
    result_204 = X60Qx_385;
    return result_204;}
  result_204 = NIM_FALSE;
  return result_204;}
static inline NB8 isIntegralMidpoint_0_sysvq0asl(NU64 twoF_2, NI32 e2_4, NI32 minusK_1){
  NB8 result_205;
  if (e2_4 < -4){
    NB8 X60Qx_386 = multipleOfPow2_1_sysvq0asl(twoF_2, ((NI32)(((NI32)(minusK_1 - e2_4)) + 1)));
    result_205 = X60Qx_386;
    return result_205;}
  if (e2_4 <= 9){
    return NIM_TRUE;}
  if (e2_4 <= 86){
    NB8 X60Qx_387 = multipleOfPow5_0_sysvq0asl(twoF_2, minusK_1);
    result_205 = X60Qx_387;
    return result_205;}
  result_205 = NIM_FALSE;
  return result_205;}
FloatingDecimal64_0_sysvq0asl toDecimal64_0_sysvq0asl(NU64 ieeeSignificand_1, NU64 ieeeExponent_1){
  FloatingDecimal64_0_sysvq0asl result_206;
  NU64 m2_0;
  NI32 e2_5;
  if ((!(ieeeExponent_1 == ((NU64)0)))){
    m2_0 = ((NU64)(((NU64)4503599627370496ull) | ieeeSignificand_1));
    e2_5 = ((NI32)(((NI32)ieeeExponent_1) - ((NI32)1075)));
    NB8 X60Qx_388;
    NB8 X60Qx_389;
    if (0 <= ((NI32)-e2_5)){
      X60Qx_389 = (((NI32)-e2_5) < ((NI32)53));}
    else {
      X60Qx_389 = NIM_FALSE;}
    if (X60Qx_389){
      NB8 X60Qx_390 = multipleOfPow2_1_sysvq0asl(m2_0, ((NI32)-e2_5));
      X60Qx_388 = X60Qx_390;}
    else {
      X60Qx_388 = NIM_FALSE;}
    if (X60Qx_388){
      result_206 = (FloatingDecimal64_0_sysvq0asl){
        .significand_0 = ((NU64)(m2_0 >> ((NI32)-e2_5))), .exponent_0 = 0}
      ;
      return result_206;}
    NB8 X60Qx_391;
    if (ieeeSignificand_1 == ((NU64)0)){
      X60Qx_391 = (((NU64)1) < ieeeExponent_1);}
    else {
      X60Qx_391 = NIM_FALSE;}
    if (X60Qx_391){
      FloatingDecimal64_0_sysvq0asl X60Qx_392 = toDecimal64AsymmetricInterval_0_sysvq0asl(e2_5);
      result_206 = X60Qx_392;
      return result_206;}}
  else {
    m2_0 = ieeeSignificand_1;
    e2_5 = ((NI32)(1 - ((NI32)1075)));}
  NB8 isEven_1 = (((NU64)(m2_0 % ((NU64)2))) == ((NU64)0));
  NB8 acceptLower_0 = isEven_1;
  NB8 acceptUpper_0 = isEven_1;
  NI32 X60Qx_393 = dbFloorLog10Pow2_0_sysvq0asl(e2_5);
  NI32 minusK_3 = ((NI32)(X60Qx_393 - ((NI32)2)));
  NI32 X60Qx_394 = dbFloorLog2Pow10_0_sysvq0asl(((NI32)-minusK_3));
  NI32 betaMinus1_3 = ((NI32)(e2_5 + X60Qx_394));
  uint64x2_0_sysvq0asl pow10_5 = computePow10_0_sysvq0asl(((NI32)-minusK_3));
  NU32 delta_0 = computeDelta_0_sysvq0asl(pow10_5, betaMinus1_3);
  NU64 twoFl_0 = ((NU64)(((NU64)(((NU64)2) * m2_0)) - ((NU64)1)));
  NU64 twoFc_0 = ((NU64)(((NU64)2) * m2_0));
  NU64 twoFr_0 = ((NU64)(((NU64)(((NU64)2) * m2_0)) + ((NU64)1)));
  NU64 zi_1 = mulShift_0_sysvq0asl(((NU64)(twoFr_0 << betaMinus1_3)), pow10_5);
  NU64 q_6 = ((NU64)(zi_1 / ((NU64)((NU32)1000u))));
  NU32 r_5 = ((NU32)(((NU32)zi_1) - ((NU32)(((NU32)1000u) * ((NU32)q_6)))));
  if (r_5 < delta_0){
    NB8 X60Qx_395;
    NB8 X60Qx_396;
    if ((!(r_5 == ((NU32)0)))){
      X60Qx_396 = NIM_TRUE;}
    else {
      X60Qx_396 = acceptUpper_0;}
    if (X60Qx_396){
      X60Qx_395 = NIM_TRUE;}
    else {
      NB8 X60Qx_397 = isIntegralEndpoint_0_sysvq0asl(twoFr_0, e2_5, minusK_3);
      X60Qx_395 = (!X60Qx_397);}
    if (X60Qx_395){
      result_206 = (FloatingDecimal64_0_sysvq0asl){
        .significand_0 = q_6, .exponent_0 = ((NI32)(((NI32)(minusK_3 + ((NI32)2))) + 1))}
      ;
      return result_206;}
    dec_1_Ifi4w3m1_sysvq0asl((&q_6));
    r_5 = ((NU32)1000u);}
  else {
    if (r_5 == delta_0){
      NB8 X60Qx_398;
      NB8 X60Qx_399;
      if (acceptLower_0){
        NB8 X60Qx_400 = isIntegralEndpoint_0_sysvq0asl(twoFl_0, e2_5, minusK_3);
        X60Qx_399 = X60Qx_400;}
      else {
        X60Qx_399 = NIM_FALSE;}
      if (X60Qx_399){
        X60Qx_398 = NIM_TRUE;}
      else {
        NB8 X60Qx_401 = mulParity_0_sysvq0asl(twoFl_0, pow10_5, betaMinus1_3);
        X60Qx_398 = X60Qx_401;}
      if (X60Qx_398){
        result_206 = (FloatingDecimal64_0_sysvq0asl){
          .significand_0 = q_6, .exponent_0 = ((NI32)(((NI32)(minusK_3 + ((NI32)2))) + 1))}
        ;
        return result_206;}}
    else {
      }}
  q_6 = ((NU64)(q_6 * ((NU64)10)));
  NU32 dist_0 = ((NU32)(((NU32)(r_5 - ((NU32)(delta_0 / ((NU32)2))))) + ((NU32)(((NU32)100u) / ((NU32)2)))));
  NU32 distQQ_0 = ((NU32)(dist_0 / ((NU32)100)));
  plusQeQ_0_Iar0t5x_sysvq0asl((&q_6), ((NU64)distQQ_0));
  if (dist_0 == ((NU32)(distQQ_0 * ((NU32)100)))){
    NB8 approxYParity_0 = (!(((NU32)(dist_0 & ((NU32)1))) == ((NU32)0)));
    NB8 X60Qx_402 = mulParity_0_sysvq0asl(twoFc_0, pow10_5, betaMinus1_3);
    if ((!(X60Qx_402 == approxYParity_0))){
      dec_1_Ifi4w3m1_sysvq0asl((&q_6));}
    else {
      NB8 X60Qx_403;
      if ((!(((NU64)(q_6 % ((NU64)2))) == ((NU64)0)))){
        NB8 X60Qx_404 = isIntegralMidpoint_0_sysvq0asl(twoFc_0, e2_5, minusK_3);
        X60Qx_403 = X60Qx_404;}
      else {
        X60Qx_403 = NIM_FALSE;}
      if (X60Qx_403){
        dec_1_Ifi4w3m1_sysvq0asl((&q_6));}}}
  result_206 = (FloatingDecimal64_0_sysvq0asl){
    .significand_0 = q_6, .exponent_0 = ((NI32)(minusK_3 + ((NI32)2)))}
  ;
  return result_206;}
static inline NI32 utoa8DigitsSkipTrailingZeros_0_sysvq0asl(openArray_0_Ijk0jkw1_feaji4clb1 buf_3, NI32 pos_3, NU32 digits_3){
  NI32 result_207;
  NU32 q_7 = ((NU32)(digits_3 / ((NU32)10000)));
  NU32 r_6 = ((NU32)(digits_3 % ((NU32)10000)));
  NU32 qH_0 = ((NU32)(q_7 / ((NU32)100)));
  NU32 qL_0 = ((NU32)(q_7 % ((NU32)100)));
  utoa2Digits_0_sysvq0asl(buf_3, pos_3, qH_0);
  utoa2Digits_0_sysvq0asl(buf_3, ((NI32)(pos_3 + 2)), qL_0);
  if (r_6 == ((NU32)0)){
    NU32 X60Qx_43;
    if (qL_0 == ((NU32)0)){
      X60Qx_43 = qH_0;}
    else {
      X60Qx_43 = qL_0;}
    NI64 X60Qx_44;
    if (qL_0 == ((NU32)0)){
      X60Qx_44 = 6;}
    else {
      X60Qx_44 = 4;}
    NI32 X60Qx_405 = trailingZeros2Digits_0_sysvq0asl(X60Qx_43);
    result_207 = ((NI32)(X60Qx_405 + X60Qx_44));}
  else {
    NU32 rH_1 = ((NU32)(r_6 / ((NU32)100)));
    NU32 rL_1 = ((NU32)(r_6 % ((NU32)100)));
    utoa2Digits_0_sysvq0asl(buf_3, ((NI32)(pos_3 + 4)), rH_1);
    utoa2Digits_0_sysvq0asl(buf_3, ((NI32)(pos_3 + 6)), rL_1);
    NU32 X60Qx_45;
    if (rL_1 == ((NU32)0)){
      X60Qx_45 = rH_1;}
    else {
      X60Qx_45 = rL_1;}
    NI64 X60Qx_46;
    if (rL_1 == ((NU32)0)){
      X60Qx_46 = 2;}
    else {
      X60Qx_46 = 0;}
    NI32 X60Qx_406 = trailingZeros2Digits_0_sysvq0asl(X60Qx_45);
    result_207 = ((NI32)(X60Qx_406 + X60Qx_46));}
  return result_207;}
static inline NI32 printDecimalDigitsBackwards_1_sysvq0asl(openArray_0_Ijk0jkw1_feaji4clb1 buf_4, NI32 pos_4, NU64 output64_0){
  NI32 result_208;
  NI32 pos_9 = pos_4;
  NU64 output64_1 = output64_0;
  NI32 tz_2 = 0;
  NI32 nd_1 = 0;
  if (((NU64)100000000u) <= output64_1){
    NU64 q_8 = ((NU64)(output64_1 / ((NU64)100000000u)));
    NU32 r_7 = ((NU32)((NU64)(output64_1 % ((NU64)100000000u))));
    output64_1 = q_8;
    dec_0_Ig5i8xp_nifb6mq6y1((&pos_9), 8);
    if ((!(r_7 == ((NU32)0)))){
      NI32 X60Qx_407 = utoa8DigitsSkipTrailingZeros_0_sysvq0asl(buf_4, pos_9, r_7);
      tz_2 = X60Qx_407;}
    else {
      tz_2 = 8;}
    nd_1 = 8;}
  NU32 output_2 = ((NU32)output64_1);
  if (((NU32)10000) <= output_2){
    NU32 q_9 = ((NU32)(output_2 / ((NU32)10000)));
    NU32 r_8 = ((NU32)(output_2 % ((NU32)10000)));
    output_2 = q_9;
    dec_0_Ig5i8xp_nifb6mq6y1((&pos_9), 4);
    if ((!(r_8 == ((NU32)0)))){
      NU32 rH_2 = ((NU32)(r_8 / ((NU32)100)));
      NU32 rL_2 = ((NU32)(r_8 % ((NU32)100)));
      utoa2Digits_0_sysvq0asl(buf_4, pos_9, rH_2);
      utoa2Digits_0_sysvq0asl(buf_4, ((NI32)(pos_9 + 2)), rL_2);
      if (tz_2 == nd_1){
        NU32 X60Qx_47;
        if (rL_2 == ((NU32)0)){
          X60Qx_47 = rH_2;}
        else {
          X60Qx_47 = rL_2;}
        NI64 X60Qx_48;
        if (rL_2 == ((NU32)0)){
          X60Qx_48 = 2;}
        else {
          X60Qx_48 = 0;}
        NI32 X60Qx_408 = trailingZeros2Digits_0_sysvq0asl(X60Qx_47);
        inc_0_Iloplki_party5a2l1((&tz_2), ((NI32)(X60Qx_408 + X60Qx_48)));}}
    else {
      if (tz_2 == nd_1){
        inc_0_Iloplki_party5a2l1((&tz_2), 4);}
      else {
        {
          NI32 X60Qlf_13 = 0;
          NI32 X60Qlf_14 = 3;
          NI32 X60Qlf_15 = X60Qlf_13;
          {
            while (X60Qlf_15 <= X60Qlf_14){
              {
                putQ_10_If2353w_sysvq0asl(buf_4, ((NI32)(pos_9 + X60Qlf_15)), (NC8)'0');}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_15));}}
          whileStmtLabel_1: ;}
        forStmtLabel_0: ;}}
    inc_0_Iloplki_party5a2l1((&nd_1), 4);}
  if (((NU32)100) <= output_2){
    NU32 q_10 = ((NU32)(output_2 / ((NU32)100)));
    NU32 r_9 = ((NU32)(output_2 % ((NU32)100)));
    output_2 = q_10;
    dec_0_Ig5i8xp_nifb6mq6y1((&pos_9), 2);
    utoa2Digits_0_sysvq0asl(buf_4, pos_9, r_9);
    if (tz_2 == nd_1){
      NI32 X60Qx_409 = trailingZeros2Digits_0_sysvq0asl(r_9);
      inc_0_Iloplki_party5a2l1((&tz_2), X60Qx_409);}
    inc_0_Iloplki_party5a2l1((&nd_1), 2);
    if (((NU32)100) <= output_2){
      NU32 q2_1 = ((NU32)(output_2 / ((NU32)100)));
      NU32 r2_1 = ((NU32)(output_2 % ((NU32)100)));
      output_2 = q2_1;
      dec_0_Ig5i8xp_nifb6mq6y1((&pos_9), 2);
      utoa2Digits_0_sysvq0asl(buf_4, pos_9, r2_1);
      if (tz_2 == nd_1){
        NI32 X60Qx_410 = trailingZeros2Digits_0_sysvq0asl(r2_1);
        inc_0_Iloplki_party5a2l1((&tz_2), X60Qx_410);}
      inc_0_Iloplki_party5a2l1((&nd_1), 2);}}
  if (((NU32)10) <= output_2){
    NU32 q_11 = output_2;
    dec_0_Ig5i8xp_nifb6mq6y1((&pos_9), 2);
    utoa2Digits_0_sysvq0asl(buf_4, pos_9, q_11);
    if (tz_2 == nd_1){
      NI32 X60Qx_411 = trailingZeros2Digits_0_sysvq0asl(q_11);
      inc_0_Iloplki_party5a2l1((&tz_2), X60Qx_411);}}
  else {
    NU32 q_12 = output_2;
    dec_1_I0nzoz91_ast8ri79k((&pos_9));
    NC8 X60Qx_412 = chr_0_sysvq0asl(((NI32)(((NI32)(NC8)'0') + ((NI32)q_12))));
    putQ_10_If2353w_sysvq0asl(buf_4, pos_9, X60Qx_412);}
  result_208 = tz_2;
  return result_208;}
static inline NI32 decimalLength_1_sysvq0asl(NU64 v_4){
  NI32 result_209;
  if ((!(((NU32)((NU64)(v_4 >> 32))) == ((NU32)0)))){
    if (((NU64)10000000000000000ull) <= v_4){
      return 17;}
    if (((NU64)1000000000000000ull) <= v_4){
      return 16;}
    if (((NU64)100000000000000ull) <= v_4){
      return 15;}
    if (((NU64)10000000000000ull) <= v_4){
      return 14;}
    if (((NU64)1000000000000ull) <= v_4){
      return 13;}
    if (((NU64)100000000000ull) <= v_4){
      return 12;}
    if (((NU64)10000000000ull) <= v_4){
      return 11;}
    return 10;}
  NU32 v32_0 = ((NU32)v_4);
  if (((NU32)1000000000u) <= v32_0){
    return 10;}
  if (((NU32)100000000u) <= v32_0){
    return 9;}
  if (((NU32)10000000u) <= v32_0){
    return 8;}
  if (((NU32)1000000u) <= v32_0){
    return 7;}
  if (((NU32)100000u) <= v32_0){
    return 6;}
  if (((NU32)10000u) <= v32_0){
    return 5;}
  if (((NU32)1000u) <= v32_0){
    return 4;}
  if (((NU32)100u) <= v32_0){
    return 3;}
  if (((NU32)10u) <= v32_0){
    return 2;}
  result_209 = 1;
  return result_209;}
static inline NI32 formatDigits_1_sysvq0asl(openArray_0_Ijk0jkw1_feaji4clb1 buffer_2, NI32 pos_5, NU64 digits_4, NI32 decimalExponent_1, NB8 forceTrailingDotZero_2){
  NI32 result_210;
  NI32 pos_10 = pos_5;
  NI32 numDigits_1 = decimalLength_1_sysvq0asl(digits_4);
  NI32 decimalPoint_1 = ((NI32)(numDigits_1 + decimalExponent_1));
  NB8 X60Qx_413;
  if (((NI32)-6) <= decimalPoint_1){
    X60Qx_413 = (decimalPoint_1 <= ((NI32)17));}
  else {
    X60Qx_413 = NIM_FALSE;}
  NB8 useFixed_1 = X60Qx_413;
  {
    NI32 X60Qlf_16 = 0;
    NI32 X60Qlf_17 = 32;
    NI32 X60Qlf_18 = X60Qlf_16;
    {
      while (X60Qlf_18 < X60Qlf_17){
        {
          putQ_10_If2353w_sysvq0asl(buffer_2, ((NI32)(pos_10 + X60Qlf_18)), (NC8)'0');}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_18));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NI32 decimalDigitsPosition_1;
  if (useFixed_1){
    if (decimalPoint_1 <= 0){
      decimalDigitsPosition_1 = ((NI32)(2 - decimalPoint_1));}
    else {
      decimalDigitsPosition_1 = 0;}}
  else {
    decimalDigitsPosition_1 = 1;}
  NI32 digitsEnd_1 = ((NI32)(((NI32)(pos_10 + decimalDigitsPosition_1)) + numDigits_1));
  NI32 tz_3 = printDecimalDigitsBackwards_1_sysvq0asl(buffer_2, digitsEnd_1, digits_4);
  dec_0_Ig5i8xp_nifb6mq6y1((&digitsEnd_1), tz_3);
  dec_0_Ig5i8xp_nifb6mq6y1((&numDigits_1), tz_3);
  if (useFixed_1){
    if (decimalPoint_1 <= 0){
      putQ_10_If2353w_sysvq0asl(buffer_2, ((NI32)(pos_10 + 1)), (NC8)'.');
      pos_10 = digitsEnd_1;}
    else {
      if (decimalPoint_1 < numDigits_1){
        X60Qt_0_IAarrayAcS8ZS16_sysvq0asl tmp_3 = default_23_I1t3hvc_sysvq0asl();
        {
          NI32 X60Qlf_19 = 0;
          NI32 X60Qlf_20 = 16;
          NI32 X60Qlf_21 = X60Qlf_19;
          {
            while (X60Qlf_21 < X60Qlf_20){
              {
                NI32 X60Qx_414 = nimIcheckB(X60Qlf_21, 15);
                NC8* X60Qx_415 = getQ_10_I5nt6we_feaji4clb1(buffer_2, ((NI32)(((NI32)(X60Qlf_21 + pos_10)) + decimalPoint_1)));
                tmp_3.a[X60Qx_414] = (*X60Qx_415);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_21));}}
          whileStmtLabel_3: ;}
        forStmtLabel_2: ;
        {
          NI32 X60Qlf_22 = 0;
          NI32 X60Qlf_23 = 16;
          NI32 X60Qlf_24 = X60Qlf_22;
          {
            while (X60Qlf_24 < X60Qlf_23){
              {
                NI32 X60Qx_416 = nimIcheckB(X60Qlf_24, 15);
                putQ_10_If2353w_sysvq0asl(buffer_2, ((NI32)(((NI32)(((NI32)(X60Qlf_24 + pos_10)) + decimalPoint_1)) + 1)), tmp_3.a[X60Qx_416]);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_24));}}
          whileStmtLabel_5: ;}
        forStmtLabel_4: ;
        putQ_10_If2353w_sysvq0asl(buffer_2, ((NI32)(pos_10 + decimalPoint_1)), (NC8)'.');
        pos_10 = ((NI32)(digitsEnd_1 + 1));}
      else {
        inc_0_Iloplki_party5a2l1((&pos_10), decimalPoint_1);
        if (forceTrailingDotZero_2){
          putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, (NC8)'.');
          putQ_10_If2353w_sysvq0asl(buffer_2, ((NI32)(pos_10 + 1)), (NC8)'0');
          inc_0_Iloplki_party5a2l1((&pos_10), 2);}}}}
  else {
    NC8* X60Qx_417 = getQ_10_I5nt6we_feaji4clb1(buffer_2, ((NI32)(pos_10 + 1)));
    putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, (*X60Qx_417));
    if (numDigits_1 == 1){
      inc_1_I6wjjge_aow2h993l1((&pos_10));}
    else {
      putQ_10_If2353w_sysvq0asl(buffer_2, ((NI32)(pos_10 + 1)), (NC8)'.');
      pos_10 = digitsEnd_1;}
    NI32 scientificExponent_1 = ((NI32)(decimalPoint_1 - 1));
    putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, (NC8)'e');
    NC8 X60Qx_49;
    if (scientificExponent_1 < 0){
      X60Qx_49 = (NC8)'-';}
    else {
      X60Qx_49 = (NC8)'+';}
    putQ_10_If2353w_sysvq0asl(buffer_2, ((NI32)(pos_10 + 1)), X60Qx_49);
    inc_0_Iloplki_party5a2l1((&pos_10), 2);
    NI32 X60Qx_50;
    if (scientificExponent_1 < 0){
      X60Qx_50 = ((NI32)-scientificExponent_1);}
    else {
      X60Qx_50 = scientificExponent_1;}
    NU32 k_4 = ((NU32)X60Qx_50);
    if (k_4 < ((NU32)10)){
      NC8 X60Qx_418 = chr_0_sysvq0asl(((NI32)(((NI32)(NC8)'0') + ((NI32)k_4))));
      putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, X60Qx_418);
      inc_1_I6wjjge_aow2h993l1((&pos_10));}
    else {
      if (k_4 < ((NU32)100)){
        utoa2Digits_0_sysvq0asl(buffer_2, pos_10, k_4);
        inc_0_Iloplki_party5a2l1((&pos_10), 2);}
      else {
        NU32 q_13 = ((NU32)(k_4 / ((NU32)100)));
        NU32 r_10 = ((NU32)(k_4 % ((NU32)100)));
        NC8 X60Qx_419 = chr_0_sysvq0asl(((NI32)(((NI32)(NC8)'0') + ((NI32)q_13))));
        putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, X60Qx_419);
        inc_1_I6wjjge_aow2h993l1((&pos_10));
        utoa2Digits_0_sysvq0asl(buffer_2, pos_10, r_10);
        inc_0_Iloplki_party5a2l1((&pos_10), 2);}}}
  result_210 = pos_10;
  return result_210;}
NI32 toChars_0_sysvq0asl(openArray_0_Ijk0jkw1_feaji4clb1 buffer_3, NF64 v_5, NB8 forceTrailingDotZero_3){
  NI32 result_211;
  NI32 pos_11 = 0;
  Double_0_sysvq0asl double_0 = constructDouble_0_sysvq0asl(v_5);
  NU64 significand_1 = physicalSignificand_1_sysvq0asl(double_0);
  NU64 exponent_1 = physicalExponent_1_sysvq0asl(double_0);
  if ((!(exponent_1 == ((NU64)2047u)))){
    putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'-');
    NI32 X60Qx_420 = signBit_1_sysvq0asl(double_0);
    inc_0_Iloplki_party5a2l1((&pos_11), X60Qx_420);
    NB8 X60Qx_421;
    if ((!(exponent_1 == ((NU64)0)))){
      X60Qx_421 = NIM_TRUE;}
    else {
      X60Qx_421 = (!(significand_1 == ((NU64)0)));}
    if (X60Qx_421){
      FloatingDecimal64_0_sysvq0asl dec_1 = toDecimal64_0_sysvq0asl(significand_1, exponent_1);
      NI32 X60Qx_422 = formatDigits_1_sysvq0asl(buffer_3, pos_11, dec_1.significand_0, ((NI32)dec_1.exponent_0), forceTrailingDotZero_3);
      result_211 = X60Qx_422;
      return result_211;}
    else {
      putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'0');
      putQ_10_If2353w_sysvq0asl(buffer_3, ((NI32)(pos_11 + 1)), (NC8)'.');
      putQ_10_If2353w_sysvq0asl(buffer_3, ((NI32)(pos_11 + 2)), (NC8)'0');
      putQ_10_If2353w_sysvq0asl(buffer_3, ((NI32)(pos_11 + 3)), (NC8)' ');
      NI64 X60Qx_51;
      if (forceTrailingDotZero_3){
        X60Qx_51 = 3;}
      else {
        X60Qx_51 = 1;}
      inc_0_Iloplki_party5a2l1((&pos_11), X60Qx_51);
      return pos_11;}}
  if (significand_1 == ((NU64)0)){
    putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'-');
    NI32 X60Qx_423 = signBit_1_sysvq0asl(double_0);
    inc_0_Iloplki_party5a2l1((&pos_11), X60Qx_423);
    putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'i');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI32)(pos_11 + 1)), (NC8)'n');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI32)(pos_11 + 2)), (NC8)'f');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI32)(pos_11 + 3)), (NC8)' ');
    result_211 = ((NI32)(pos_11 + 3));
    return result_211;}
  else {
    putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'n');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI32)(pos_11 + 1)), (NC8)'a');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI32)(pos_11 + 2)), (NC8)'n');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI32)(pos_11 + 3)), (NC8)' ');
    result_211 = ((NI32)(pos_11 + 3));
    return result_211;}
  return result_211;}
void addFloat_0_sysvq0asl(string_0_sysvq0asl* result_0, NF64 x_346){
  X60Qt_0_IAarrayAcS8ZS65_sysvq0asl buffer_4 = default_23_Insyi17_sysvq0asl();
  openArray_0_Ijk0jkw1_feaji4clb1 X60Qx_424 = toOpenArray_0_Iwrwfj81_sysvq0asl((&buffer_4));
  NI32 n_8 = toChars_0_sysvq0asl(X60Qx_424, x_346, NIM_TRUE);
  {
    NI32 X60Qlf_25 = 0;
    NI32 X60Qlf_26 = n_8;
    NI32 X60Qlf_27 = X60Qlf_25;
    {
      while (X60Qlf_27 < X60Qlf_26){
        {
          NI32 X60Qx_425 = nimIcheckB(X60Qlf_27, 64);
          add_1_sysvq0asl(result_0, buffer_4.a[X60Qx_425]);}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_27));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
string_0_sysvq0asl dollarQ_7_sysvq0asl(NF64 x_348){
  string_0_sysvq0asl result_212;
  nimStrWasMoved((&result_212));
  nimStrDestroy(result_212);
  result_212 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  addFloat_0_sysvq0asl((&result_212), x_348);
  return result_212;}
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_77, HSlice_0_Inzqy8d_comaa5xpt1 x_355){
  string_0_sysvq0asl result_224;
  nimStrWasMoved((&result_224));
  nimStrDestroy(result_224);
  string_0_sysvq0asl X60Qx_437 = substr_0_sysvq0asl(s_77, x_355.a_0, x_355.b_0);
  result_224 = X60Qx_437;
  return result_224;}
static inline void listAdd_0_Ik4wxhz_sysvq0asl(SmallChunk_0_sysvq0asl** head_5, SmallChunk_0_sysvq0asl* c_38){
  (*c_38).next_0 = (*head_5);
  if ((!((*head_5) == NIM_NIL))){
    (*(*head_5)).prev_0 = c_38;}
  (*head_5) = c_38;}
static inline void listRemove_0_Ibzev091_sysvq0asl(SmallChunk_0_sysvq0asl** head_6, SmallChunk_0_sysvq0asl* c_39){
  if (c_39 == (*head_6)){
    (*head_6) = (*c_39).next_0;
    if ((!((*head_6) == NIM_NIL))){
      (*(*head_6)).prev_0 = NIM_NIL;}}
  else {
    (*(*c_39).prev_0).next_0 = (*c_39).next_0;
    if ((!((*c_39).next_0 == NIM_NIL))){
      (*(*c_39).next_0).prev_0 = (*c_39).prev_0;}}
  (*c_39).next_0 = NIM_NIL;
  (*c_39).prev_0 = NIM_NIL;}
void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1684957694u, .more_0 = (&strlit_0_I11614695157650328859_sysvq0asl)}
  );
  writeErr_0_sysvq0asl(((NI64)i_68));
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1869488382u, .more_0 = (&strlit_0_I16845119709590674135_sysvq0asl)}
  );
  writeErr_0_sysvq0asl(((NI64)a_83));
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3026434u, .more_0 = NIM_NIL}
  );
  writeErr_0_sysvq0asl(((NI64)b_38));
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  exit(((NI32)1));}
void raiseIndexError3_0_Ic5mmkg_sysvq0asl(NU32 i_69, NU32 a_84, NU32 b_39){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1684957694u, .more_0 = (&strlit_0_I11614695157650328859_sysvq0asl)}
  );
  writeErr_1_sysvq0asl(((NU64)i_69));
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 1869488382u, .more_0 = (&strlit_0_I16845119709590674135_sysvq0asl)}
  );
  writeErr_1_sysvq0asl(((NU64)a_84));
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3026434u, .more_0 = NIM_NIL}
  );
  writeErr_1_sysvq0asl(((NU64)b_39));
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561u, .more_0 = NIM_NIL}
  );
  exit(((NI32)1));}
static inline void putQ_10_If2353w_sysvq0asl(openArray_0_Ijk0jkw1_feaji4clb1 x_380, NI32 i_70, NC8 elem_13){
  NB8 X60Qx_441;
  if (0 <= i_70){
    X60Qx_441 = (i_70 < x_380.len_0);}
  else {
    X60Qx_441 = NIM_FALSE;}
  if ((!X60Qx_441)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8062030498282895634_str7j0ifg)}
    );}
  NC8* X60Qx_442 = getQ_10_I5nt6we_feaji4clb1(x_380, i_70);
  (*X60Qx_442) = elem_13;}
static inline void dec_0_Idgnuqw1_sysvq0asl(NU64* x_382, NU64 y_218){
  (*x_382) = ((NU64)((*x_382) - y_218));}
static inline void plusQeQ_0_Iar0t5x_sysvq0asl(NU64* x_384, NU64 y_220){
  (*x_384) = ((NU64)((*x_384) + y_220));}
static inline void dec_1_Ifi4w3m1_sysvq0asl(NU64* x_385){
  (*x_385) = ((NU64)((*x_385) - ((NU64)1)));}
static inline X60Qt_0_IAarrayAcS8ZS16_sysvq0asl default_23_I1t3hvc_sysvq0asl(void){
  X60Qt_0_IAarrayAcS8ZS16_sysvq0asl result_231;
  {
    NI32 X60Qlf_31 = ((NI32)0);
    NI32 X60Qlf_32 = ((NI32)15);
    NI32 X60Qlf_33 = X60Qlf_31;
    {
      while (X60Qlf_33 <= X60Qlf_32){
        {
          NI32 X60Qx_444 = nimIcheckB(X60Qlf_33, 15);
          result_231.a[X60Qx_444] = (NC8)'\000';}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_33));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_231;}
static inline X60Qt_0_IAarrayAcS8ZS65_sysvq0asl default_23_Insyi17_sysvq0asl(void){
  X60Qt_0_IAarrayAcS8ZS65_sysvq0asl result_232;
  {
    NI32 X60Qlf_34 = ((NI32)0);
    NI32 X60Qlf_35 = ((NI32)64);
    NI32 X60Qlf_36 = X60Qlf_34;
    {
      while (X60Qlf_36 <= X60Qlf_35){
        {
          NI32 X60Qx_445 = nimIcheckB(X60Qlf_36, 64);
          result_232.a[X60Qx_445] = (NC8)'\000';}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_36));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_232;}
static inline openArray_0_Ijk0jkw1_feaji4clb1 toOpenArray_0_Iwrwfj81_sysvq0asl(X60Qt_0_IAarrayAcS8ZS65_sysvq0asl* x_388){
  openArray_0_Ijk0jkw1_feaji4clb1 result_233;
  openArray_0_Ijk0jkw1_feaji4clb1 X60Qx_52;
  if (((NI32)(((NI32)(((NI32)((NI32)64)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_52 = (openArray_0_Ijk0jkw1_feaji4clb1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_52 = (openArray_0_Ijk0jkw1_feaji4clb1){
      .a_0 = ((NC8*)(&(*x_388))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)64)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_233 = X60Qx_52;
  return result_233;}
void eQwasmovedQ_ArefSX45xception0sysvq0asl_0_sysvq0asl(X60Qt_0_IArefSX45xception0sysvq0asl_sysvq0asl** dest_0){
  (*dest_0) = NIM_NIL;}
void X60Qini_0_sysvq0asl(void){
  if (X60QiniGuard_0_sysvq0asl){
    return;}
  X60QiniGuard_0_sysvq0asl = NIM_TRUE;
  eQwasmovedQ_ArefSX45xception0sysvq0asl_0_sysvq0asl((&exc_0_sysvq0asl));}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void dec_0_Ig5i8xp_nifb6mq6y1(NI32* x_18, NI32 y_4){
  (*x_18) = ((NI32)((*x_18) - y_4));}
static inline void inc_0_Iloplki_party5a2l1(NI32* x_10, NI32 y_3){
  (*x_10) = ((NI32)((*x_10) + y_3));}
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
static inline void inc_0_Ineawm41_party5a2l1(NU64* x_8, NU64 y_2){
  (*x_8) = ((NU64)((*x_8) + y_2));}
static inline NC8* getQ_10_I5nt6we_feaji4clb1(openArray_0_Ijk0jkw1_feaji4clb1 x_2, NI32 idx_1){
  NB8 X60Qx_6;
  if (0 <= idx_1){
    X60Qx_6 = (idx_1 < x_2.len_0);}
  else {
    X60Qx_6 = NIM_FALSE;}
  if ((!X60Qx_6)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  NC8* result_4;
  result_4 = (&x_2.a_0[idx_1]);
  return result_4;}
static void __attribute__((constructor)) init(void) {gExitFlush_0_sysvq0asl = nimNoopFlush_0_sysvq0asl;
oomHandler_0_sysvq0asl = continueAfterOutOfMem_0_sysvq0asl;
}

