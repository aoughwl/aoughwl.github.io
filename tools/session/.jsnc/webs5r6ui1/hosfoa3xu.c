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
#include <stdlib.h>
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct Bounce_0_hosfoa3xu Bounce_0_hosfoa3xu;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct Bounce_0_hosfoa3xu{
  void* mem_0;
  NI32 n_0;}
Bounce_0_hosfoa3xu;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct seq_0_Ijmiee61_ast8ri79k{
  NI32 len_0;
  NU64* data_0;}
seq_0_Ijmiee61_ast8ri79k;
typedef struct seq_0_Iele5kv_arewp645e1{
  NI32 len_0;
  void** data_0;}
seq_0_Iele5kv_arewp645e1;
typedef struct seq_0_Ikz9gft_hosfoa3xu{
  NI32 len_0;
  Bounce_0_hosfoa3xu* data_0;}
seq_0_Ikz9gft_hosfoa3xu;
typedef N_CDECL_PTR(NU64,  X60Qt_0_IAuS64ZAcdeclZAfalseZAR13_hosfoa3xu)(void);
typedef N_CDECL_PTR(NU64,  X60Qt_0_IAuS64ZAuS64ZAcdeclZAfalseZAR19_hosfoa3xu)(NU64);
typedef N_CDECL_PTR(NU64,  X60Qt_0_IAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR25_hosfoa3xu)(NU64, NU64);
typedef N_CDECL_PTR(NU64,  X60Qt_0_IAuS64ZAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR31_hosfoa3xu)(NU64, NU64, NU64);
typedef N_CDECL_PTR(NU64,  X60Qt_0_IAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR37_hosfoa3xu)(NU64, NU64, NU64, NU64);
typedef N_CDECL_PTR(NU64,  X60Qt_0_IAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR43_hosfoa3xu)(NU64, NU64, NU64, NU64, NU64);
typedef N_CDECL_PTR(NU64,  X60Qt_0_IAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR49_hosfoa3xu)(NU64, NU64, NU64, NU64, NU64, NU64);
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01{
  string_0_sysvq0asl a[1];}
X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline NI32 len_3_I9otiog_hosfoa3xu(seq_0_Ijmiee61_ast8ri79k s_17);
static inline seq_0_Ikz9gft_hosfoa3xu newSeqUninit_0_Ibfnk9h_hosfoa3xu(NI32 size_7);
static inline void add_0_Iqbdi0m1_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu* s_19, Bounce_0_hosfoa3xu elem_5);
static inline NI32 len_3_I9nsg9i1_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu s_21);
static inline Bounce_0_hosfoa3xu* getQ_7_Izms2pr_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu s_22, NI32 i_14);
static inline NI32 memSizeInBytes_0_I8e952c1_hosfoa3xu(NI32 size_11);
static inline NI32 capInBytes_0_Ipembym_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu s_25);
NB8 resize_0_Idd5aie_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu* dest_5, NI32 addedElements_5);
void eQdestroy_1_Ibf67vc_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu s_41);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_49, NC8 c_14);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern NC8* toCString_0_sysvq0asl(string_0_sysvq0asl* s_64);
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93);
extern void eQdestroy_1_Ivioh0a_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_92);
static inline seq_0_Ixdx2fh1_aow7lb5cq1 newSeqUninit_0_Im3cqd9_aow7lb5cq1(NI32 size_8);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline string_0_sysvq0asl ampQ_1_sysvq0asl(string_0_sysvq0asl x_316, NC8 y_199);
static inline NI32 len_3_Ixq6taz_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_37);
extern seq_0_Ixdx2fh1_aow7lb5cq1 atQ_0_I508dwj_hos1fpv3m1(X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01 a_7);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline void** getQ_7_Itn5o4y1_arewp645e1(seq_0_Iele5kv_arewp645e1 s_11, NI32 i_6);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI32 len_5);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_50, string_0_sysvq0asl part_0);
static inline void add_0_Ir5coiw1_arewp645e1(seq_0_Iele5kv_arewp645e1* s_5, void* elem_2);
extern NB8 capsDeniedOn_1_iop7yt73v(NI32 need_1, string_0_sysvq0asl path_1);
extern void recordViolation_1_iop7yt73v(string_0_sysvq0asl name_4, NI32 needed_3);
static inline NU64* getQ_7_Ifaxado1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_10, NI32 i_7);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_iop7yt73v(void);
static inline seq_0_Iele5kv_arewp645e1 newSeqUninit_0_I257ttf1_arewp645e1(NI32 size_4);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NI32 memSizeInBytes_0_I7me00i_aow7lb5cq1(NI32 size_19);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
extern string_0_sysvq0asl charToString_0_sysvq0asl(NC8 c_16);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_54, string_0_sysvq0asl b_17);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline NI32 capInBytes_0_I2a0sy5_arewp645e1(seq_0_Iele5kv_arewp645e1 s_12);
extern NB8 resize_0_Irdgezg_arewp645e1(seq_0_Iele5kv_arewp645e1* dest_2, NI32 addedElements_2);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline NI32 memSizeInBytes_0_Ixzft2y_arewp645e1(NI32 size_8);
LongString_0_sysvq0asl const strlit_0_I12683361638006699212_hosfoa3xu = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dlopen(\'"}
;
LongString_0_sysvq0asl const strlit_0_I14816527950215133999_hosfoa3xu = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\') failed: "}
;
LongString_0_sysvq0asl const strlit_0_I1041341657034196624_hosfoa3xu = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dlsym(\'"}
;
LongString_0_sysvq0asl const strlit_0_I8484753484558739254_hosfoa3xu = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\') not found in \'"}
;
LongString_0_sysvq0asl const strlit_0_I12127486366082406825_hosfoa3xu = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dynlib call \'"}
;
LongString_0_sysvq0asl const strlit_0_I4088803189581246608_hosfoa3xu = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "\' in "}
;
seq_0_Ixdx2fh1_aow7lb5cq1 gLibNames_0_hosfoa3xu;
seq_0_Iele5kv_arewp645e1 gLibHandles_0_hosfoa3xu;
seq_0_Ixdx2fh1_aow7lb5cq1 gSymLib_0_hosfoa3xu;
seq_0_Ixdx2fh1_aow7lb5cq1 gSymName_0_hosfoa3xu;
seq_0_Iele5kv_arewp645e1 gSymAddr_0_hosfoa3xu;
string_0_sysvq0asl gLastError_0_hosfoa3xu = {
  .bytes_0 = 0u, .more_0 = NIM_NIL}
;
seq_0_Ikz9gft_hosfoa3xu gBounces_0_hosfoa3xu;
NB8 X60QiniGuard_0_hosfoa3xu;
string_0_sysvq0asl dynLastError_0_hosfoa3xu(void){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  nimStrDestroy(result_0);
  string_0_sysvq0asl X60Qx_4 = nimStrDup(gLastError_0_hosfoa3xu);
  result_0 = X60Qx_4;
  return result_0;}
string_0_sysvq0asl cstrToStr_0_hosfoa3xu(NC8* p_1){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  nimStrDestroy(result_1);
  result_1 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  if (((void*)p_1) == NIM_NIL){
    return result_1;}
  NU8* b_6 = ((NU8*)p_1);
  NI32 i_0 = 0;
  {
    while (i_0 < 4096){
      if (b_6[i_0] == ((NU8)0u)){
        goto whileStmtLabel_0;}
      add_1_sysvq0asl((&result_1), ((NC8)b_6[i_0]));
      inc_1_I6wjjge_aow2h993l1((&i_0));}}
  whileStmtLabel_0: ;
  return result_1;}
void* dlopenOne_0_hosfoa3xu(string_0_sysvq0asl name_7){
  void* result_2;
  string_0_sysvq0asl v_0 = nimStrDup(name_7);
  NC8* X60Qx_5 = toCString_0_sysvq0asl((&v_0));
  void* X60Qx_6 = dlopen(X60Qx_5, ((NI32)(((NI32)2) | ((NI32)256))));
  result_2 = X60Qx_6;
  nimStrDestroy(v_0);
  return result_2;
  nimStrDestroy(v_0);
  return result_2;}
seq_0_Ixdx2fh1_aow7lb5cq1 libAlternatives_0_hosfoa3xu(string_0_sysvq0asl spec_0){
  seq_0_Ixdx2fh1_aow7lb5cq1 result_3;
  eQwasMoved_1_I5vdnla_aow7lb5cq1((&result_3));
  eQdestroy_1_Ivioh0a_aow7lb5cq1(result_3);
  seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_7 = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  result_3 = X60Qx_7;
  NB8 X60Qx_8;
  NB8 X60Qx_9;
  NI32 X60Qx_10 = len_4_sysvq0asl(spec_0);
  if (2 <= X60Qx_10){
    NC8 X60Qx_11 = getQ_9_sysvq0asl(spec_0, 0);
    X60Qx_9 = (X60Qx_11 == (NC8)'(');}
  else {
    X60Qx_9 = NIM_FALSE;}
  if (X60Qx_9){
    NI32 X60Qx_12 = len_4_sysvq0asl(spec_0);
    NC8 X60Qx_13 = getQ_9_sysvq0asl(spec_0, ((NI32)(X60Qx_12 - 1)));
    X60Qx_8 = (X60Qx_13 == (NC8)')');}
  else {
    X60Qx_8 = NIM_FALSE;}
  if (X60Qx_8){
    string_0_sysvq0asl cur_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    ;
    NI32 i_1 = 1;
    {
      while (NIM_TRUE){
        NI32 X60Qx_14 = len_4_sysvq0asl(spec_0);
        if (i_1 < ((NI32)(X60Qx_14 - 1))){
          NC8 X60Qx_15 = getQ_9_sysvq0asl(spec_0, i_1);
          if (X60Qx_15 == (NC8)'|'){
            NI32 X60Qx_16 = len_4_sysvq0asl(cur_0);
            if (0 < X60Qx_16){
              string_0_sysvq0asl X60Qtmp_0 = cur_0;
              nimStrWasMoved((&cur_0));
              add_0_Ig6072n_aow7lb5cq1((&result_3), X60Qtmp_0);}
            nimStrDestroy(cur_0);
            cur_0 = (string_0_sysvq0asl){
              .bytes_0 = 0u, .more_0 = NIM_NIL}
            ;}
          else {
            NC8 X60Qx_17 = getQ_9_sysvq0asl(spec_0, i_1);
            string_0_sysvq0asl X60Qlhs_1 = ampQ_1_sysvq0asl(cur_0, X60Qx_17);
            nimStrDestroy(cur_0);
            cur_0 = X60Qlhs_1;}
          inc_1_I6wjjge_aow2h993l1((&i_1));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    NI32 X60Qx_18 = len_4_sysvq0asl(cur_0);
    if (0 < X60Qx_18){
      string_0_sysvq0asl X60Qtmp_2 = cur_0;
      nimStrWasMoved((&cur_0));
      add_0_Ig6072n_aow7lb5cq1((&result_3), X60Qtmp_2);}
    nimStrDestroy(cur_0);}
  NI32 X60Qx_19 = len_3_Ixq6taz_aow7lb5cq1(result_3);
  if (X60Qx_19 == 0){
    eQdestroy_1_Ivioh0a_aow7lb5cq1(result_3);
    seq_0_Ixdx2fh1_aow7lb5cq1 X60Qx_20 = atQ_0_I508dwj_hos1fpv3m1((X60Qt_0_IAarraySstring0sysvq0aslS1_emi78vuj01){
      .a = {
        spec_0}}
    );
    result_3 = X60Qx_20;}
  return result_3;}
void* openLib_0_hosfoa3xu(string_0_sysvq0asl lib_7){
  void* result_4;
  NI32 i_2 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_21 = len_3_Ixq6taz_aow7lb5cq1(gLibNames_0_hosfoa3xu);
      if (i_2 < X60Qx_21){
        string_0_sysvq0asl* X60Qx_22 = getQ_7_Ir6d0tw_aow7lb5cq1(gLibNames_0_hosfoa3xu, i_2);
        NB8 X60Qx_23 = eqQ_20_sysvq0asl((*X60Qx_22), lib_7);
        if (X60Qx_23){
          void** X60Qx_24 = getQ_7_Itn5o4y1_arewp645e1(gLibHandles_0_hosfoa3xu, i_2);
          result_4 = (*X60Qx_24);
          return result_4;}
        inc_1_I6wjjge_aow2h993l1((&i_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  void* h_0 = NIM_NIL;
  seq_0_Ixdx2fh1_aow7lb5cq1 cands_0 = libAlternatives_0_hosfoa3xu(lib_7);
  NI32 k_0 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_25;
      NI32 X60Qx_26 = len_3_Ixq6taz_aow7lb5cq1(cands_0);
      if (k_0 < X60Qx_26){
        X60Qx_25 = (h_0 == NIM_NIL);}
      else {
        X60Qx_25 = NIM_FALSE;}
      if (X60Qx_25){
        string_0_sysvq0asl* X60Qx_27 = getQ_7_Ir6d0tw_aow7lb5cq1(cands_0, k_0);
        void* X60Qx_28 = dlopenOne_0_hosfoa3xu((*X60Qx_27));
        h_0 = X60Qx_28;
        inc_1_I6wjjge_aow2h993l1((&k_0));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  if (h_0 == NIM_NIL){
    NC8* X60Qx_29 = dlerror();
    string_0_sysvq0asl X60Qdesugar_0 = cstrToStr_0_hosfoa3xu(X60Qx_29);
    NI32 X60Qx_30 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1869374718u, .more_0 = (&strlit_0_I12683361638006699212_hosfoa3xu)}
    );
    NI32 X60Qx_31 = len_4_sysvq0asl(lib_7);
    NI32 X60Qx_32 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 539568126u, .more_0 = (&strlit_0_I14816527950215133999_hosfoa3xu)}
    );
    NI32 X60Qx_33 = len_4_sysvq0asl(X60Qdesugar_0);
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_30 + X60Qx_31)) + X60Qx_32)) + X60Qx_33)));
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 1869374718u, .more_0 = (&strlit_0_I12683361638006699212_hosfoa3xu)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), lib_7);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 539568126u, .more_0 = (&strlit_0_I14816527950215133999_hosfoa3xu)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), X60Qdesugar_0);
    nimStrDestroy(gLastError_0_hosfoa3xu);
    gLastError_0_hosfoa3xu = X60Qdesugar_1;
    nimStrWasMoved((&X60Qdesugar_1));
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);}
  string_0_sysvq0asl X60Qx_34 = nimStrDup(lib_7);
  add_0_Ig6072n_aow7lb5cq1((&gLibNames_0_hosfoa3xu), X60Qx_34);
  add_0_Ir5coiw1_arewp645e1((&gLibHandles_0_hosfoa3xu), h_0);
  result_4 = h_0;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(cands_0);
  return result_4;
  eQdestroy_1_Ivioh0a_aow7lb5cq1(cands_0);
  return result_4;}
void* dynResolve_0_hosfoa3xu(string_0_sysvq0asl lib_8, string_0_sysvq0asl sym_1){
  void* result_5;
  NI32 i_5 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_35 = len_3_Ixq6taz_aow7lb5cq1(gSymLib_0_hosfoa3xu);
      if (i_5 < X60Qx_35){
        NB8 X60Qx_36;
        string_0_sysvq0asl* X60Qx_37 = getQ_7_Ir6d0tw_aow7lb5cq1(gSymLib_0_hosfoa3xu, i_5);
        NB8 X60Qx_38 = eqQ_20_sysvq0asl((*X60Qx_37), lib_8);
        if (X60Qx_38){
          string_0_sysvq0asl* X60Qx_39 = getQ_7_Ir6d0tw_aow7lb5cq1(gSymName_0_hosfoa3xu, i_5);
          NB8 X60Qx_40 = eqQ_20_sysvq0asl((*X60Qx_39), sym_1);
          X60Qx_36 = X60Qx_40;}
        else {
          X60Qx_36 = NIM_FALSE;}
        if (X60Qx_36){
          void** X60Qx_41 = getQ_7_Itn5o4y1_arewp645e1(gSymAddr_0_hosfoa3xu, i_5);
          result_5 = (*X60Qx_41);
          return result_5;}
        inc_1_I6wjjge_aow2h993l1((&i_5));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  nimStrDestroy(gLastError_0_hosfoa3xu);
  gLastError_0_hosfoa3xu = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  void* h_1 = openLib_0_hosfoa3xu(lib_8);
  void* a_7 = NIM_NIL;
  if ((!(h_1 == NIM_NIL))){
    string_0_sysvq0asl symv_0 = nimStrDup(sym_1);
    NC8* X60Qx_42 = toCString_0_sysvq0asl((&symv_0));
    void* X60Qx_43 = dlsym(h_1, X60Qx_42);
    a_7 = X60Qx_43;
    if (a_7 == NIM_NIL){
      NC8* X60Qx_44 = dlerror();
      string_0_sysvq0asl X60Qdesugar_2 = cstrToStr_0_hosfoa3xu(X60Qx_44);
      NI32 X60Qx_45 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 1936483582u, .more_0 = (&strlit_0_I1041341657034196624_hosfoa3xu)}
      );
      NI32 X60Qx_46 = len_4_sysvq0asl(sym_1);
      NI32 X60Qx_47 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 539568126u, .more_0 = (&strlit_0_I8484753484558739254_hosfoa3xu)}
      );
      NI32 X60Qx_48 = len_4_sysvq0asl(lib_8);
      NI32 X60Qx_49 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 540681987u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_50 = len_4_sysvq0asl(X60Qdesugar_2);
      string_0_sysvq0asl X60Qdesugar_3 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_45 + X60Qx_46)) + X60Qx_47)) + X60Qx_48)) + X60Qx_49)) + X60Qx_50)));
      add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
        .bytes_0 = 1936483582u, .more_0 = (&strlit_0_I1041341657034196624_hosfoa3xu)}
      );
      add_2_sysvq0asl((&X60Qdesugar_3), sym_1);
      add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
        .bytes_0 = 539568126u, .more_0 = (&strlit_0_I8484753484558739254_hosfoa3xu)}
      );
      add_2_sysvq0asl((&X60Qdesugar_3), lib_8);
      add_2_sysvq0asl((&X60Qdesugar_3), (string_0_sysvq0asl){
        .bytes_0 = 540681987u, .more_0 = NIM_NIL}
      );
      add_2_sysvq0asl((&X60Qdesugar_3), X60Qdesugar_2);
      nimStrDestroy(gLastError_0_hosfoa3xu);
      gLastError_0_hosfoa3xu = X60Qdesugar_3;
      nimStrWasMoved((&X60Qdesugar_3));
      nimStrDestroy(X60Qdesugar_3);
      nimStrDestroy(X60Qdesugar_2);}
    nimStrDestroy(symv_0);}
  string_0_sysvq0asl X60Qx_51 = nimStrDup(lib_8);
  add_0_Ig6072n_aow7lb5cq1((&gSymLib_0_hosfoa3xu), X60Qx_51);
  string_0_sysvq0asl X60Qx_52 = nimStrDup(sym_1);
  add_0_Ig6072n_aow7lb5cq1((&gSymName_0_hosfoa3xu), X60Qx_52);
  add_0_Ir5coiw1_arewp645e1((&gSymAddr_0_hosfoa3xu), a_7);
  result_5 = a_7;
  return result_5;}
NB8 dynDenied_0_hosfoa3xu(string_0_sysvq0asl sym_2, string_0_sysvq0asl lib_9){
  NB8 result_6;
  NB8 X60Qx_53 = capsDeniedOn_1_iop7yt73v(((NI32)64), (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  );
  if (X60Qx_53){
    NI32 X60Qx_54 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1853449470u, .more_0 = (&strlit_0_I12127486366082406825_hosfoa3xu)}
    );
    NI32 X60Qx_55 = len_4_sysvq0asl(sym_2);
    NI32 X60Qx_56 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 1763715070u, .more_0 = (&strlit_0_I4088803189581246608_hosfoa3xu)}
    );
    NI32 X60Qx_57 = len_4_sysvq0asl(lib_9);
    string_0_sysvq0asl X60Qdesugar_4 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(X60Qx_54 + X60Qx_55)) + X60Qx_56)) + X60Qx_57)));
    add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
      .bytes_0 = 1853449470u, .more_0 = (&strlit_0_I12127486366082406825_hosfoa3xu)}
    );
    add_2_sysvq0asl((&X60Qdesugar_4), sym_2);
    add_2_sysvq0asl((&X60Qdesugar_4), (string_0_sysvq0asl){
      .bytes_0 = 1763715070u, .more_0 = (&strlit_0_I4088803189581246608_hosfoa3xu)}
    );
    add_2_sysvq0asl((&X60Qdesugar_4), lib_9);
    recordViolation_1_iop7yt73v(X60Qdesugar_4, ((NI32)64));
    result_6 = NIM_TRUE;
    nimStrDestroy(X60Qdesugar_4);}
  else {
    result_6 = NIM_FALSE;}
  return result_6;}
NU64 dynCall_0_hosfoa3xu(string_0_sysvq0asl lib_10, string_0_sysvq0asl sym_3, seq_0_Ijmiee61_ast8ri79k args_0, NB8* ok_0){
  NU64 result_7;
  (*ok_0) = NIM_TRUE;
  result_7 = ((NU64)0u);
  if (((NI32)6) < args_0.len_0){
    (*ok_0) = NIM_FALSE;
    return result_7;}
  void* h_2 = openLib_0_hosfoa3xu(lib_10);
  if (h_2 == NIM_NIL){
    (*ok_0) = NIM_FALSE;
    return result_7;}
  string_0_sysvq0asl symv_1 = nimStrDup(sym_3);
  NC8* nm_0 = toCString_0_sysvq0asl((&symv_1));
  NI32 X60Qx_58 = len_3_I9otiog_hosfoa3xu(args_0);
  switch (X60Qx_58){
    case 0:
    {
      X60Qt_0_IAuS64ZAcdeclZAfalseZAR13_hosfoa3xu f_1 = dlsym(h_2, nm_0);
      if (((void*)f_1) == NIM_NIL){
        (*ok_0) = NIM_FALSE;}
      else {
        NU64 X60Qx_59 = f_1();
        result_7 = X60Qx_59;}}
    break;
    case 1:
    {
      X60Qt_0_IAuS64ZAuS64ZAcdeclZAfalseZAR19_hosfoa3xu f_2 = dlsym(h_2, nm_0);
      if (((void*)f_2) == NIM_NIL){
        (*ok_0) = NIM_FALSE;}
      else {
        NU64* X60Qx_60 = getQ_7_Ifaxado1_ast8ri79k(args_0, 0);
        NU64 X60Qx_61 = f_2((*X60Qx_60));
        result_7 = X60Qx_61;}}
    break;
    case 2:
    {
      X60Qt_0_IAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR25_hosfoa3xu f_3 = dlsym(h_2, nm_0);
      if (((void*)f_3) == NIM_NIL){
        (*ok_0) = NIM_FALSE;}
      else {
        NU64* X60Qx_62 = getQ_7_Ifaxado1_ast8ri79k(args_0, 0);
        NU64* X60Qx_63 = getQ_7_Ifaxado1_ast8ri79k(args_0, 1);
        NU64 X60Qx_64 = f_3((*X60Qx_62), (*X60Qx_63));
        result_7 = X60Qx_64;}}
    break;
    case 3:
    {
      X60Qt_0_IAuS64ZAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR31_hosfoa3xu f_4 = dlsym(h_2, nm_0);
      if (((void*)f_4) == NIM_NIL){
        (*ok_0) = NIM_FALSE;}
      else {
        NU64* X60Qx_65 = getQ_7_Ifaxado1_ast8ri79k(args_0, 0);
        NU64* X60Qx_66 = getQ_7_Ifaxado1_ast8ri79k(args_0, 1);
        NU64* X60Qx_67 = getQ_7_Ifaxado1_ast8ri79k(args_0, 2);
        NU64 X60Qx_68 = f_4((*X60Qx_65), (*X60Qx_66), (*X60Qx_67));
        result_7 = X60Qx_68;}}
    break;
    case 4:
    {
      X60Qt_0_IAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR37_hosfoa3xu f_5 = dlsym(h_2, nm_0);
      if (((void*)f_5) == NIM_NIL){
        (*ok_0) = NIM_FALSE;}
      else {
        NU64* X60Qx_69 = getQ_7_Ifaxado1_ast8ri79k(args_0, 0);
        NU64* X60Qx_70 = getQ_7_Ifaxado1_ast8ri79k(args_0, 1);
        NU64* X60Qx_71 = getQ_7_Ifaxado1_ast8ri79k(args_0, 2);
        NU64* X60Qx_72 = getQ_7_Ifaxado1_ast8ri79k(args_0, 3);
        NU64 X60Qx_73 = f_5((*X60Qx_69), (*X60Qx_70), (*X60Qx_71), (*X60Qx_72));
        result_7 = X60Qx_73;}}
    break;
    case 5:
    {
      X60Qt_0_IAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR43_hosfoa3xu f_6 = dlsym(h_2, nm_0);
      if (((void*)f_6) == NIM_NIL){
        (*ok_0) = NIM_FALSE;}
      else {
        NU64* X60Qx_74 = getQ_7_Ifaxado1_ast8ri79k(args_0, 0);
        NU64* X60Qx_75 = getQ_7_Ifaxado1_ast8ri79k(args_0, 1);
        NU64* X60Qx_76 = getQ_7_Ifaxado1_ast8ri79k(args_0, 2);
        NU64* X60Qx_77 = getQ_7_Ifaxado1_ast8ri79k(args_0, 3);
        NU64* X60Qx_78 = getQ_7_Ifaxado1_ast8ri79k(args_0, 4);
        NU64 X60Qx_79 = f_6((*X60Qx_74), (*X60Qx_75), (*X60Qx_76), (*X60Qx_77), (*X60Qx_78));
        result_7 = X60Qx_79;}}
    break;
    default:
    {
      X60Qt_0_IAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAuS64ZAcdeclZAfalseZAR49_hosfoa3xu f_7 = dlsym(h_2, nm_0);
      if (((void*)f_7) == NIM_NIL){
        (*ok_0) = NIM_FALSE;}
      else {
        NU64* X60Qx_80 = getQ_7_Ifaxado1_ast8ri79k(args_0, 0);
        NU64* X60Qx_81 = getQ_7_Ifaxado1_ast8ri79k(args_0, 1);
        NU64* X60Qx_82 = getQ_7_Ifaxado1_ast8ri79k(args_0, 2);
        NU64* X60Qx_83 = getQ_7_Ifaxado1_ast8ri79k(args_0, 3);
        NU64* X60Qx_84 = getQ_7_Ifaxado1_ast8ri79k(args_0, 4);
        NU64* X60Qx_85 = getQ_7_Ifaxado1_ast8ri79k(args_0, 5);
        NU64 X60Qx_86 = f_7((*X60Qx_80), (*X60Qx_81), (*X60Qx_82), (*X60Qx_83), (*X60Qx_84), (*X60Qx_85));
        result_7 = X60Qx_86;}}
    break;}
  nimStrDestroy(symv_1);
  return result_7;
  nimStrDestroy(symv_1);
  return result_7;}
void* bounceAlloc_0_hosfoa3xu(NI32 n_1){
  void* result_8;
  if (n_1 <= 0){
    return NIM_NIL;}
  void* p_4 = malloc(((size_t)n_1));
  if (p_4 == NIM_NIL){
    return NIM_NIL;}
  NI32 i_7 = 0;
  NU8* b_7 = ((NU8*)p_4);
  {
    while (i_7 < n_1){
      b_7[i_7] = ((NU8)0u);
      inc_1_I6wjjge_aow2h993l1((&i_7));}}
  whileStmtLabel_0: ;
  add_0_Iqbdi0m1_hosfoa3xu((&gBounces_0_hosfoa3xu), (Bounce_0_hosfoa3xu){
    .mem_0 = p_4, .n_0 = n_1}
  );
  result_8 = p_4;
  return result_8;}
void bounceWrite_0_hosfoa3xu(void* p_2, NI32 off_0, NU8 b_5){
  NB8 X60Qx_87;
  if (p_2 == NIM_NIL){
    X60Qx_87 = NIM_TRUE;}
  else {
    X60Qx_87 = (off_0 < 0);}
  if (X60Qx_87){
    return;}
  ((NU8*)p_2)[off_0] = ((NU8)b_5);}
NU8 bounceRead_0_hosfoa3xu(void* p_3, NI32 off_1){
  NU8 result_9;
  NB8 X60Qx_88;
  if (p_3 == NIM_NIL){
    X60Qx_88 = NIM_TRUE;}
  else {
    X60Qx_88 = (off_1 < 0);}
  if (X60Qx_88){
    return ((NU8)0u);}
  result_9 = ((NU8)((NU8*)p_3)[off_1]);
  return result_9;}
void bounceFreeAll_0_hosfoa3xu(void){
  NI32 i_8 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_89 = len_3_I9nsg9i1_hosfoa3xu(gBounces_0_hosfoa3xu);
      if (i_8 < X60Qx_89){
        Bounce_0_hosfoa3xu* X60Qx_90 = getQ_7_Izms2pr_hosfoa3xu(gBounces_0_hosfoa3xu, i_8);
        if ((!((*X60Qx_90).mem_0 == NIM_NIL))){
          Bounce_0_hosfoa3xu* X60Qx_91 = getQ_7_Izms2pr_hosfoa3xu(gBounces_0_hosfoa3xu, i_8);
          free((*X60Qx_91).mem_0);}
        inc_1_I6wjjge_aow2h993l1((&i_8));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_1_Ibf67vc_hosfoa3xu(gBounces_0_hosfoa3xu);
  seq_0_Ikz9gft_hosfoa3xu X60Qx_92 = newSeqUninit_0_Ibfnk9h_hosfoa3xu(0);
  gBounces_0_hosfoa3xu = X60Qx_92;}
static inline NI32 len_3_I9otiog_hosfoa3xu(seq_0_Ijmiee61_ast8ri79k s_17){
  NI32 result_17;
  result_17 = s_17.len_0;
  return result_17;}
static inline seq_0_Ikz9gft_hosfoa3xu newSeqUninit_0_Ibfnk9h_hosfoa3xu(NI32 size_7){
  seq_0_Ikz9gft_hosfoa3xu result_19;
  if (size_7 == 0){
    result_19 = (seq_0_Ikz9gft_hosfoa3xu){
      .len_0 = size_7, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_I8e952c1_hosfoa3xu(size_7);
    void* X60Qx_108 = alloc_1_sysvq0asl(memSize_2);
    result_19 = (seq_0_Ikz9gft_hosfoa3xu){
      .len_0 = size_7, .data_0 = ((Bounce_0_hosfoa3xu*)X60Qx_108)}
    ;
    if ((!(result_19.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_109 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_19.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_19;}
static inline void add_0_Iqbdi0m1_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu* s_19, Bounce_0_hosfoa3xu elem_5){
  NI32 L_2 = (*s_19).len_0;
  NI32 X60Qx_110 = capInBytes_0_Ipembym_hosfoa3xu((*s_19));
  if (X60Qx_110 < ((NI32)(((NI32)(L_2 * sizeof(Bounce_0_hosfoa3xu))) + sizeof(Bounce_0_hosfoa3xu)))){
    NB8 X60Qx_111 = resize_0_Idd5aie_hosfoa3xu(s_19, 1);
    if ((!X60Qx_111)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_19).len_0));
  (*s_19).data_0[L_2] = elem_5;}
static inline NI32 len_3_I9nsg9i1_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu s_21){
  NI32 result_20;
  result_20 = s_21.len_0;
  return result_20;}
static inline Bounce_0_hosfoa3xu* getQ_7_Izms2pr_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu s_22, NI32 i_14){
  NB8 X60Qx_112;
  if (i_14 < s_22.len_0){
    X60Qx_112 = (0 <= i_14);}
  else {
    X60Qx_112 = NIM_FALSE;}
  if ((!X60Qx_112)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  Bounce_0_hosfoa3xu* result_21;
  result_21 = (&s_22.data_0[i_14]);
  return result_21;}
static inline NI32 memSizeInBytes_0_I8e952c1_hosfoa3xu(NI32 size_11){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_28;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_11, sizeof(Bounce_0_hosfoa3xu), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_28 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_28 = ((NI32)2147483647);}
  return result_28;}
static inline NI32 capInBytes_0_Ipembym_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu s_25){
  NI32 result_29;
  NI32 X60Qx_2;
  if ((!(s_25.data_0 == NIM_NIL))){
    NI32 X60Qx_119 = allocatedSize_0_sysvq0asl(((void*)((void*)s_25.data_0)));
    X60Qx_2 = X60Qx_119;}
  else {
    X60Qx_2 = 0;}
  result_29 = X60Qx_2;
  return result_29;}
NB8 resize_0_Idd5aie_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu* dest_5, NI32 addedElements_5){
  NB8 result_30;
  NI32 X60Qx_120 = capInBytes_0_Ipembym_hosfoa3xu((*dest_5));
  NI32 oldCap_2 = ((NI32)(X60Qx_120 / sizeof(Bounce_0_hosfoa3xu)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_5);
  NI32 memSize_5 = memSizeInBytes_0_I8e952c1_hosfoa3xu(newCap_2);
  void* X60Qx_121 = realloc_1_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_5);
  (*dest_5).data_0 = ((Bounce_0_hosfoa3xu*)X60Qx_121);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_5);
    result_30 = NIM_FALSE;}
  else {
    result_30 = NIM_TRUE;}
  return result_30;}
void eQdestroy_1_Ibf67vc_hosfoa3xu(seq_0_Ikz9gft_hosfoa3xu s_41){
  if ((!(s_41.data_0 == NIM_NIL))){
    NI32 i_27 = 0;
    {
      while (i_27 < s_41.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_27));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_41.data_0)));}}
void X60Qini_0_hosfoa3xu(void){
  if (X60QiniGuard_0_hosfoa3xu){
    return;}
  X60QiniGuard_0_hosfoa3xu = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_iop7yt73v();
  gLibNames_0_hosfoa3xu = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  gLibHandles_0_hosfoa3xu = newSeqUninit_0_I257ttf1_arewp645e1(0);
  gSymLib_0_hosfoa3xu = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  gSymName_0_hosfoa3xu = newSeqUninit_0_Im3cqd9_aow7lb5cq1(0);
  gSymAddr_0_hosfoa3xu = newSeqUninit_0_I257ttf1_arewp645e1(0);
  gBounces_0_hosfoa3xu = newSeqUninit_0_Ibfnk9h_hosfoa3xu(0);}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
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
static inline void eQwasMoved_1_I5vdnla_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_93){
  (*s_93).len_0 = 0;
  (*s_93).data_0 = NIM_NIL;}
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
static inline string_0_sysvq0asl ampQ_1_sysvq0asl(string_0_sysvq0asl x_316, NC8 y_199){
  string_0_sysvq0asl result_136;
  nimStrWasMoved((&result_136));
  nimStrDestroy(result_136);
  string_0_sysvq0asl X60Qtmp_4 = charToString_0_sysvq0asl(y_199);
  string_0_sysvq0asl X60Qx_307 = ampQ_0_sysvq0asl(x_316, X60Qtmp_4);
  result_136 = X60Qx_307;
  nimStrDestroy(X60Qtmp_4);
  return result_136;
  nimStrDestroy(X60Qtmp_4);
  return result_136;}
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
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
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
static inline void add_0_Ir5coiw1_arewp645e1(seq_0_Iele5kv_arewp645e1* s_5, void* elem_2){
  NI32 L_0 = (*s_5).len_0;
  NI32 X60Qx_24 = capInBytes_0_I2a0sy5_arewp645e1((*s_5));
  if (X60Qx_24 < ((NI32)(((NI32)(L_0 * sizeof(void*))) + sizeof(void*)))){
    NB8 X60Qx_25 = resize_0_Irdgezg_arewp645e1(s_5, 1);
    if ((!X60Qx_25)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_5).len_0));
  (*s_5).data_0[L_0] = elem_2;}
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
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
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
