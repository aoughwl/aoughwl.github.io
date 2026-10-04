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
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct seq_0_Iele5kv_arewp645e1{
  NI32 len_0;
  void** data_0;}
seq_0_Iele5kv_arewp645e1;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
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
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline seq_0_Iele5kv_arewp645e1 newSeqUninit_0_I257ttf1_arewp645e1(NI32 size_4);
static inline void add_0_Ir5coiw1_arewp645e1(seq_0_Iele5kv_arewp645e1* s_5, void* elem_2);
static inline NI32 len_3_I3wfzur_arewp645e1(seq_0_Iele5kv_arewp645e1 s_9);
static inline void** getQ_7_Itn5o4y1_arewp645e1(seq_0_Iele5kv_arewp645e1 s_11, NI32 i_6);
static inline NI32 memSizeInBytes_0_Ixzft2y_arewp645e1(NI32 size_8);
static inline NI32 capInBytes_0_I2a0sy5_arewp645e1(seq_0_Iele5kv_arewp645e1 s_12);
NB8 resize_0_Irdgezg_arewp645e1(seq_0_Iele5kv_arewp645e1* dest_2, NI32 addedElements_2);
void eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_arewp645e1(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* dest_0);
void eQwasmovedQ_ArefSX41renaX4fbj0arewp645e1_0_arewp645e1(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v** dest_0);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13);
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_36);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void X60Qini_0_sysvq0asl(void);
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20);
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68);
extern NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8);
NB8 X60QiniGuard_0_arewp645e1;
static inline NI32 alignUp_0_arewp645e1(NI32 x_0, NI32 a_0){
  NI32 result_0;
  NI64 X60Qx_0;
  if (a_0 < 1){
    X60Qx_0 = 1;}
  else {
    X60Qx_0 = a_0;}
  NI32 m_0 = X60Qx_0;
  result_0 = ((NI32)(((NI32)(((NI32)(x_0 + m_0)) - 1)) & ((NI32) ~ ((NI32)(m_0 - 1)))));
  return result_0;}
X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* newArena_0_arewp645e1(NI32 chunkSize_0){
  X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* result_1;
  eQwasmovedQ_ArefSX41renaX4fbj0arewp645e1_0_arewp645e1((&result_1));
  eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_arewp645e1(result_1);
  void* X60Qx_4 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v));
  X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* X60Qtmp_0 = ((X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v*)X60Qx_4);
  seq_0_Iele5kv_arewp645e1 X60Qx_5 = newSeqUninit_0_I257ttf1_arewp645e1(0);
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_6 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  NI32 X60Qx_7 = max_2_sysvq0asl(chunkSize_0, 64);
  (*X60Qtmp_0) = (X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v){
    .r_00 = 0, .d_00 = (Arena_Obj_0_arewp645e1){
      .chunks_0 = X60Qx_5, .sizes_0 = X60Qx_6, .chunkSize_0 = X60Qx_7, .cur_0 = -1, .off_0 = 0, .total_0 = 0}}
  ;
  result_1 = X60Qtmp_0;
  return result_1;}
NI32 addChunk_0_arewp645e1(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* a_1, NI32 cap_0){
  NI32 result_2;
  void* p_5 = malloc(((NU32)cap_0));
  if (p_5 == NIM_NIL){
    abort();}
  add_0_Ir5coiw1_arewp645e1((&(*a_1).d_00.chunks_0), p_5);
  add_0_I8kd4i4_aow7lb5cq1((&(*a_1).d_00.sizes_0), cap_0);
  NI32 X60Qx_8 = len_3_I3wfzur_arewp645e1((*a_1).d_00.chunks_0);
  result_2 = ((NI32)(X60Qx_8 - 1));
  return result_2;}
void* arenaAlloc_0_arewp645e1(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* a_2, NI32 size_1, NI32 align_0){
  void* result_3;
  NI32 sz_0 = max_2_sysvq0asl(size_1, 0);
  NI64 X60Qx_1;
  if (align_0 < 1){
    X60Qx_1 = 1;}
  else {
    X60Qx_1 = align_0;}
  NI32 al_0 = X60Qx_1;
  if ((*a_2).d_00.cur_0 < 0){
    NI32 X60Qx_9 = addChunk_0_arewp645e1(a_2, (*a_2).d_00.chunkSize_0);
    (*a_2).d_00.cur_0 = X60Qx_9;
    (*a_2).d_00.off_0 = 0;}
  NI32 start_0 = alignUp_0_arewp645e1((*a_2).d_00.off_0, al_0);
  NI32* X60Qx_10 = getQ_7_Ir8kccm_aow7lb5cq1((*a_2).d_00.sizes_0, (*a_2).d_00.cur_0);
  if ((*X60Qx_10) < ((NI32)(start_0 + sz_0))){
    if ((*a_2).d_00.chunkSize_0 < ((NI32)(sz_0 + al_0))){
      NI32 idx_0 = addChunk_0_arewp645e1(a_2, ((NI32)(sz_0 + al_0)));
      void** X60Qx_11 = getQ_7_Itn5o4y1_arewp645e1((*a_2).d_00.chunks_0, idx_0);
      NU32 ubase_0 = ((NU32)(*X60Qx_11));
      NU32 addrU_0 = ((NU32)(((NU32)(((NU32)(ubase_0 + ((NU32)al_0))) - 1u)) & ((NU32) ~ ((NU32)(((NU32)al_0) - 1u)))));
      (*a_2).d_00.total_0 = ((NI32)((*a_2).d_00.total_0 + sz_0));
      return ((void*)addrU_0);}
    NI32 X60Qx_12 = addChunk_0_arewp645e1(a_2, (*a_2).d_00.chunkSize_0);
    (*a_2).d_00.cur_0 = X60Qx_12;
    (*a_2).d_00.off_0 = 0;
    NI32 X60Qx_13 = alignUp_0_arewp645e1((*a_2).d_00.off_0, al_0);
    start_0 = X60Qx_13;}
  void** X60Qx_14 = getQ_7_Itn5o4y1_arewp645e1((*a_2).d_00.chunks_0, (*a_2).d_00.cur_0);
  NU32 base_0 = ((NU32)(*X60Qx_14));
  NU32 addrU_1 = ((NU32)(base_0 + ((NU32)start_0)));
  (*a_2).d_00.off_0 = ((NI32)(start_0 + sz_0));
  (*a_2).d_00.total_0 = ((NI32)((*a_2).d_00.total_0 + sz_0));
  result_3 = ((void*)addrU_1);
  return result_3;}
void arenaReset_0_arewp645e1(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* a_5){
  if (0 < (*a_5).d_00.chunks_0.len_0){
    (*a_5).d_00.cur_0 = 0;
    (*a_5).d_00.off_0 = 0;}
  else {
    (*a_5).d_00.cur_0 = -1;
    (*a_5).d_00.off_0 = 0;}
  (*a_5).d_00.total_0 = 0;}
static inline void pokeByte_0_arewp645e1(void* p_1, NI32 off_0, NU8 v_0){
  (*((NU8*)((void*)((NU32)(((NU32)p_1) + ((NU32)off_0)))))) = v_0;}
static inline NU8 peekByte_0_arewp645e1(void* p_2, NI32 off_1){
  NU8 result_6;
  result_6 = (*((NU8*)((void*)((NU32)(((NU32)p_2) + ((NU32)off_1))))));
  return result_6;}
void pokeU64_0_arewp645e1(void* p_3, NI32 off_2, NU64 v_1){
  NI32 i_3 = 0;
  {
    while (i_3 < 8){
      pokeByte_0_arewp645e1(p_3, ((NI32)(off_2 + i_3)), ((NU8)((NU64)(((NU64)(v_1 >> ((NU32)(((NU32)i_3) * 8u)))) & ((NU64)255u)))));
      inc_1_I6wjjge_aow2h993l1((&i_3));}}
  whileStmtLabel_0: ;}
static inline seq_0_Iele5kv_arewp645e1 newSeqUninit_0_I257ttf1_arewp645e1(NI32 size_4){
  seq_0_Iele5kv_arewp645e1 result_8;
  if (size_4 == 0){
    result_8 = (seq_0_Iele5kv_arewp645e1){
      .len_0 = size_4, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_Ixzft2y_arewp645e1(size_4);
    void* X60Qx_20 = alloc_1_sysvq0asl(memSize_0);
    result_8 = (seq_0_Iele5kv_arewp645e1){
      .len_0 = size_4, .data_0 = ((void**)X60Qx_20)}
    ;
    if ((!(result_8.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_21 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_8.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_8;}
static inline void add_0_Ir5coiw1_arewp645e1(seq_0_Iele5kv_arewp645e1* s_5, void* elem_2){
  NI32 L_0 = (*s_5).len_0;
  NI32 X60Qx_24 = capInBytes_0_I2a0sy5_arewp645e1((*s_5));
  if (X60Qx_24 < ((NI32)(((NI32)(L_0 * sizeof(void*))) + sizeof(void*)))){
    NB8 X60Qx_25 = resize_0_Irdgezg_arewp645e1(s_5, 1);
    if ((!X60Qx_25)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_5).len_0));
  (*s_5).data_0[L_0] = elem_2;}
static inline NI32 len_3_I3wfzur_arewp645e1(seq_0_Iele5kv_arewp645e1 s_9){
  NI32 result_10;
  result_10 = s_9.len_0;
  return result_10;}
static inline void** getQ_7_Itn5o4y1_arewp645e1(seq_0_Iele5kv_arewp645e1 s_11, NI32 i_6){
  NB8 X60Qx_29;
  if (i_6 < s_11.len_0){
    X60Qx_29 = (0 <= i_6);}
  else {
    X60Qx_29 = NIM_FALSE;}
  if ((!X60Qx_29)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  void** result_12;
  result_12 = (&s_11.data_0[i_6]);
  return result_12;}
static inline NI32 memSizeInBytes_0_Ixzft2y_arewp645e1(NI32 size_8){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_13;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_8, sizeof(void*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_13 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_13 = ((NI32)2147483647);}
  return result_13;}
static inline NI32 capInBytes_0_I2a0sy5_arewp645e1(seq_0_Iele5kv_arewp645e1 s_12){
  NI32 result_15;
  NI32 X60Qx_2;
  if ((!(s_12.data_0 == NIM_NIL))){
    NI32 X60Qx_30 = allocatedSize_0_sysvq0asl(((void*)((void*)s_12.data_0)));
    X60Qx_2 = X60Qx_30;}
  else {
    X60Qx_2 = 0;}
  result_15 = X60Qx_2;
  return result_15;}
NB8 resize_0_Irdgezg_arewp645e1(seq_0_Iele5kv_arewp645e1* dest_2, NI32 addedElements_2){
  NB8 result_16;
  NI32 X60Qx_31 = capInBytes_0_I2a0sy5_arewp645e1((*dest_2));
  NI32 oldCap_0 = ((NI32)(X60Qx_31 / sizeof(void*)));
  NI32 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_2);
  NI32 memSize_2 = memSizeInBytes_0_Ixzft2y_arewp645e1(newCap_0);
  void* X60Qx_32 = realloc_1_sysvq0asl(((void*)((void*)(*dest_2).data_0)), memSize_2);
  (*dest_2).data_0 = ((void**)X60Qx_32);
  if ((*dest_2).data_0 == NIM_NIL){
    (*dest_2).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_2);
    result_16 = NIM_FALSE;}
  else {
    result_16 = NIM_TRUE;}
  return result_16;}
void eQdestroy_1_I0wifam_arewp645e1(seq_0_Iele5kv_arewp645e1 s_18){
  if ((!(s_18.data_0 == NIM_NIL))){
    NI32 i_7 = 0;
    {
      while (i_7 < s_18.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_7));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_18.data_0)));}}
void eQdestroyQ_SX41renaX4fbj0arewp645e1_0_arewp645e1(Arena_Obj_0_arewp645e1* dest_0){
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1((*dest_0).sizes_0);
  eQdestroy_1_I0wifam_arewp645e1((*dest_0).chunks_0);}
void eQdestroyQ_ArefSX41renaX4fbj0arewp645e1_0_arewp645e1(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v* dest_0){
  if (dest_0){
    NB8 X60Qx_47 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_47){
      eQdestroyQ_SX41renaX4fbj0arewp645e1_0_arewp645e1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX41renaX4fbj0arewp645e1_0_arewp645e1(X60Qt_0_IArefSX41renaX4fbj0arewp645e1_arecyyj7v** dest_0){
  (*dest_0) = NIM_NIL;}
void X60Qini_0_arewp645e1(void){
  if (X60QiniGuard_0_arewp645e1){
    return;}
  X60QiniGuard_0_arewp645e1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_1445 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_1445 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1446 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_1446)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
