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
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
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
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
typedef struct X60Qt_0_IAarrayAuS8ZS43_ast8ri79k{
  NU8 a[43];}
X60Qt_0_IAarrayAuS8ZS43_ast8ri79k;
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
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
static inline NU64* getQ_7_Ifaxado1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_10, NI32 i_7);
static inline NU64* getQ_0_I3qz68f_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_14, NU32 litId_13);
static inline NI32 high_3_Izxucdl_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_11);
static inline NU32* getQ_8_Ikc5fbr_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_12, NU32 i_8);
void enlarge_0_Ig89cp21_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k* t_15);
void setLen_0_Ibzv7hh_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_16, NI32 newLen_2);
static inline void putQ_8_Ioc8g62_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_19, NU32 i_12, NU32 elem_2);
static inline NI32 len_3_Ijagz1k_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_22);
static inline void newSeq_1_Ildm5l2_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_23, NI32 newLen_5);
static inline void swap_0_Ia4b84l_ast8ri79k(seq_0_Izov3yo_ast8ri79k* x_6, seq_0_Izov3yo_ast8ri79k* y_1);
static inline NU32* getQ_7_Idda6ys1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_24, NI32 i_14);
static inline NU32 move_0_Ii1uxvw_ast8ri79k(NU32* x_7);
void shrink_0_Ieny4k81_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_25, NI32 newLen_6);
void growUnsafe_0_I21nsd8_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_26, NI32 newLen_7);
seq_0_Izov3yo_ast8ri79k newSeq_0_Iyso6231_ast8ri79k(NI32 size_2);
static inline NI32 capInBytes_0_I2v1dsn1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_29);
NB8 resize_0_Itvf2zj1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* dest_3, NI32 addedElements_3);
static inline NI32 memSizeInBytes_0_Iu5tdzt_ast8ri79k(NI32 size_5);
void eQdestroy_1_In04crl1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_48);
static inline void eQwasMoved_1_I94uyip1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_49);
static inline NI32 memSizeInBytes_0_Iqj0wsf_ast8ri79k(NI32 size_23);
static inline NI32 memSizeInBytes_0_I4sctiu_ast8ri79k(NI32 size_25);
static inline NI32 memSizeInBytes_0_Iom723i1_ast8ri79k(NI32 size_27);
static inline NI32 memSizeInBytes_0_Itq6t0c1_ast8ri79k(NI32 size_29);
static inline NI32 memSizeInBytes_0_Iidgqw2_ast8ri79k(NI32 size_31);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
extern NU32 hash_1_has9tn57v(string_0_sysvq0asl s_0);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NU32 nextTry_0_bitekkhcx1(NU32 h_0, NU32 maxHash_0);
static inline NB8 mustRehash_0_bitekkhcx1(NI32 length_0, NI32 counter_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tabcr240b1(void);
extern void X60Qini_0_set37vj3r(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_for2ybv4p1(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_bitekkhcx1(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_nifjp9lau1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_symkyk35i1(void);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k = {
  .fullLen_0 = 110, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/seqimpl.nim(172, 42): i < uint32(s.len) [AssertionDefect]\012"}
;
LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k = {
  .fullLen_0 = 110, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/seqimpl.nim(174, 54): i < uint32(s.len) [AssertionDefect]\012"}
;
NB8 X60QiniGuard_0_ast8ri79k;
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
NU32 getOrIncl_0_Ix6biej1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k* t_11, string_0_sysvq0asl v_1){
  NU32 result_7;
  NU32 origH_0 = hash_1_has9tn57v(v_1);
  NI32 X60Qx_37 = high_3_Izxucdl_ast8ri79k((*t_11).keys_0);
  NU32 h_0 = ((NU32)(origH_0 & ((NU32)X60Qx_37)));
  if ((!((*t_11).keys_0.len_0 == 0))){
    {
      while (NIM_TRUE){
        NU32* X60Qx_38 = getQ_8_Ikc5fbr_ast8ri79k((*t_11).keys_0, h_0);
        NU32 litId_10 = (*X60Qx_38);
        if ((!(((NU32)0u) < ((NU32)litId_10)))){
          goto whileStmtLabel_0;}
        NU32* X60Qx_39 = getQ_8_Ikc5fbr_ast8ri79k((*t_11).keys_0, h_0);
        string_0_sysvq0asl* X60Qx_40 = getQ_7_Ir6d0tw_aow7lb5cq1((*t_11).vals_0, ((NI32)(((NI32)(*X60Qx_39)) - ((NI32)1))));
        NB8 X60Qx_41 = eqQ_20_sysvq0asl(v_1, (*X60Qx_40));
        if (X60Qx_41){
          return litId_10;}
        NI32 X60Qx_42 = high_3_Izxucdl_ast8ri79k((*t_11).keys_0);
        NU32 X60Qx_43 = nextTry_0_bitekkhcx1(h_0, ((NU32)X60Qx_42));
        h_0 = X60Qx_43;}}
    whileStmtLabel_0: ;
    NB8 X60Qx_44 = mustRehash_0_bitekkhcx1((*t_11).keys_0.len_0, (*t_11).vals_0.len_0);
    if (X60Qx_44){
      enlarge_0_Ig89cp21_ast8ri79k(t_11);
      NI32 X60Qx_45 = high_3_Izxucdl_ast8ri79k((*t_11).keys_0);
      h_0 = ((NU32)(origH_0 & ((NU32)X60Qx_45)));
      {
        while (NIM_TRUE){
          NU32* X60Qx_46 = getQ_8_Ikc5fbr_ast8ri79k((*t_11).keys_0, h_0);
          NU32 litId_11 = (*X60Qx_46);
          if ((!(((NU32)0u) < ((NU32)litId_11)))){
            goto whileStmtLabel_1;}
          NI32 X60Qx_47 = high_3_Izxucdl_ast8ri79k((*t_11).keys_0);
          NU32 X60Qx_48 = nextTry_0_bitekkhcx1(h_0, ((NU32)X60Qx_47));
          h_0 = X60Qx_48;}}
      whileStmtLabel_1: ;}}
  else {
    setLen_0_Ibzv7hh_ast8ri79k((&(*t_11).keys_0), 16);
    NI32 X60Qx_49 = high_3_Izxucdl_ast8ri79k((*t_11).keys_0);
    h_0 = ((NU32)(origH_0 & ((NU32)X60Qx_49)));}
  result_7 = ((NU32)((NI32)((*t_11).vals_0.len_0 + ((NI32)1))));
  putQ_8_Ioc8g62_ast8ri79k((&(*t_11).keys_0), h_0, result_7);
  string_0_sysvq0asl X60Qx_50 = nimStrDup(v_1);
  add_0_Ig6072n_aow7lb5cq1((&(*t_11).vals_0), X60Qx_50);
  return result_7;}
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
static inline NI32 high_3_Izxucdl_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_11){
  NI32 result_13;
  result_13 = ((NI32)(s_11.len_0 - 1));
  return result_13;}
static inline NU32* getQ_8_Ikc5fbr_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_12, NU32 i_8){
  if ((!(i_8 < ((NU32)s_12.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  NU32* result_14;
  result_14 = (&s_12.data_0[((NI32)i_8)]);
  return result_14;}
void enlarge_0_Ig89cp21_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k* t_15){
  seq_0_Izov3yo_ast8ri79k n_3;
  eQwasMoved_1_I94uyip1_ast8ri79k((&n_3));
  NI32 X60Qx_56 = len_3_Ijagz1k_ast8ri79k((*t_15).keys_0);
  newSeq_1_Ildm5l2_ast8ri79k((&n_3), ((NI32)(X60Qx_56 * 2)));
  swap_0_Ia4b84l_ast8ri79k((&(*t_15).keys_0), (&n_3));
  {
    NI32 X60Qlf_0 = 0;
    NI32 X60Qlf_1 = high_3_Izxucdl_ast8ri79k(n_3);
    NI32 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 <= X60Qlf_1){
        {
          NU32* X60Qx_57 = getQ_7_Idda6ys1_ast8ri79k(n_3, X60Qlf_2);
          NU32 X60Qii_2 = (*X60Qx_57);
          if (((NU32)0u) < ((NU32)X60Qii_2)){
            string_0_sysvq0asl* X60Qx_58 = getQ_7_Ir6d0tw_aow7lb5cq1((*t_15).vals_0, ((NI32)(((NI32)X60Qii_2) - ((NI32)1))));
            NU32 X60Qx_59 = hash_1_has9tn57v((*X60Qx_58));
            NI32 X60Qx_60 = high_3_Izxucdl_ast8ri79k((*t_15).keys_0);
            NU32 X60Qii_3 = ((NU32)(X60Qx_59 & ((NU32)X60Qx_60)));
            while (NIM_TRUE){
              NU32* X60Qx_61 = getQ_8_Ikc5fbr_ast8ri79k((*t_15).keys_0, X60Qii_3);
              if (((NU32)0u) < ((NU32)(*X60Qx_61))){
                NI32 X60Qx_62 = high_3_Izxucdl_ast8ri79k((*t_15).keys_0);
                NU32 X60Qx_63 = nextTry_0_bitekkhcx1(X60Qii_3, ((NU32)X60Qx_62));
                X60Qii_3 = X60Qx_63;}
              else {
                break;}}
            NU32* X60Qx_64 = getQ_7_Idda6ys1_ast8ri79k(n_3, X60Qlf_2);
            NU32 X60Qx_65 = move_0_Ii1uxvw_ast8ri79k(X60Qx_64);
            putQ_8_Ioc8g62_ast8ri79k((&(*t_15).keys_0), X60Qii_3, X60Qx_65);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroy_1_In04crl1_ast8ri79k(n_3);}
void setLen_0_Ibzv7hh_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_16, NI32 newLen_2){
  if (newLen_2 < (*s_16).len_0){
    shrink_0_Ieny4k81_ast8ri79k(s_16, newLen_2);}
  else {
    NI32 i_11 = (*s_16).len_0;
    growUnsafe_0_I21nsd8_ast8ri79k(s_16, newLen_2);
    if ((*s_16).data_0 == NIM_NIL){
      return;}
    {
      while (i_11 < newLen_2){
        (*s_16).data_0[i_11] = ((NU32)0u);
        inc_1_I6wjjge_aow2h993l1((&i_11));}}
    whileStmtLabel_0: ;}}
static inline void putQ_8_Ioc8g62_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_19, NU32 i_12, NU32 elem_2){
  if ((!(i_12 < ((NU32)(*s_19).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_19).data_0[((NI32)i_12)] = elem_2;}
static inline NI32 len_3_Ijagz1k_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_22){
  NI32 result_15;
  result_15 = s_22.len_0;
  return result_15;}
static inline void newSeq_1_Ildm5l2_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_23, NI32 newLen_5){
  seq_0_Izov3yo_ast8ri79k X60Qx_68 = newSeq_0_Iyso6231_ast8ri79k(newLen_5);
  (*s_23) = X60Qx_68;}
static inline void swap_0_Ia4b84l_ast8ri79k(seq_0_Izov3yo_ast8ri79k* x_6, seq_0_Izov3yo_ast8ri79k* y_1){
  seq_0_Izov3yo_ast8ri79k tmp_0 = (*x_6);
  (*x_6) = (*y_1);
  (*y_1) = tmp_0;}
static inline NU32* getQ_7_Idda6ys1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_24, NI32 i_14){
  NB8 X60Qx_69;
  if (i_14 < s_24.len_0){
    X60Qx_69 = (0 <= i_14);}
  else {
    X60Qx_69 = NIM_FALSE;}
  if ((!X60Qx_69)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_16;
  result_16 = (&s_24.data_0[i_14]);
  return result_16;}
static inline NU32 move_0_Ii1uxvw_ast8ri79k(NU32* x_7){
  NU32 result_17;
  result_17 = (*x_7);
  return result_17;}
void shrink_0_Ieny4k81_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_25, NI32 newLen_6){
  NI32 i_15 = ((NI32)((*s_25).len_0 - 1));
  {
    while (newLen_6 <= i_15){
      dec_1_I0nzoz91_aow7lb5cq1((&i_15));}}
  whileStmtLabel_0: ;
  (*s_25).len_0 = newLen_6;}
void growUnsafe_0_I21nsd8_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_26, NI32 newLen_7){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_7, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_0 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_70 = capInBytes_0_I2v1dsn1_ast8ri79k((*s_26));
  if (X60Qx_70 < newSize_0){
    NB8 X60Qx_71 = resize_0_Itvf2zj1_ast8ri79k(s_26, ((NI32)(newLen_7 - (*s_26).len_0)));
    if ((!X60Qx_71)){
      return;}}
  (*s_26).len_0 = newLen_7;}
seq_0_Izov3yo_ast8ri79k newSeq_0_Iyso6231_ast8ri79k(NI32 size_2){
  seq_0_Izov3yo_ast8ri79k result_20;
  if (size_2 == 0){
    result_20 = (seq_0_Izov3yo_ast8ri79k){
      .len_0 = size_2, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_1 = memSizeInBytes_0_Iu5tdzt_ast8ri79k(size_2);
    void* X60Qx_75 = alloc_1_sysvq0asl(memSize_1);
    result_20 = (seq_0_Izov3yo_ast8ri79k){
      .len_0 = size_2, .data_0 = ((NU32*)X60Qx_75)}
    ;
    if ((!(result_20.data_0 == NIM_NIL))){
      NI32 i_16 = 0;
      {
        while (i_16 < size_2){
          result_20.data_0[i_16] = ((NU32)0u);
          inc_1_I6wjjge_aow2h993l1((&i_16));}}
      whileStmtLabel_0: ;}
    else {
      result_20.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_1);}}
  return result_20;}
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
NB8 resize_0_Itvf2zj1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* dest_3, NI32 addedElements_3){
  NB8 result_22;
  NI32 X60Qx_77 = capInBytes_0_I2v1dsn1_ast8ri79k((*dest_3));
  NI32 oldCap_1 = ((NI32)(X60Qx_77 / sizeof(NU32)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_3);
  NI32 memSize_2 = memSizeInBytes_0_Iu5tdzt_ast8ri79k(newCap_1);
  void* X60Qx_78 = realloc_1_sysvq0asl(((void*)((void*)(*dest_3).data_0)), memSize_2);
  (*dest_3).data_0 = ((NU32*)X60Qx_78);
  if ((*dest_3).data_0 == NIM_NIL){
    (*dest_3).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_2);
    result_22 = NIM_FALSE;}
  else {
    result_22 = NIM_TRUE;}
  return result_22;}
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
void eQdestroy_1_In04crl1_ast8ri79k(seq_0_Izov3yo_ast8ri79k s_48){
  if ((!(s_48.data_0 == NIM_NIL))){
    NI32 i_21 = 0;
    {
      while (i_21 < s_48.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_21));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_48.data_0)));}}
static inline void eQwasMoved_1_I94uyip1_ast8ri79k(seq_0_Izov3yo_ast8ri79k* s_49){
  (*s_49).len_0 = 0;
  (*s_49).data_0 = NIM_NIL;}
void eQdestroy_1_Iez2nr5_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_50){
  if ((!(s_50.data_0 == NIM_NIL))){
    NI32 i_25 = 0;
    {
      while (i_25 < s_50.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_25));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_50.data_0)));}}
static inline void eQwasMoved_1_Ia0kll01_ast8ri79k(seq_0_Iotb7mc_ast8ri79k* s_51){
  (*s_51).len_0 = 0;
  (*s_51).data_0 = NIM_NIL;}
void eQdestroy_1_Inr6ycs1_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k s_53){
  if ((!(s_53.data_0 == NIM_NIL))){
    NI32 i_29 = 0;
    {
      while (i_29 < s_53.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_29));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_53.data_0)));}}
static inline void eQwasMoved_1_I5re2ul_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
void eQdestroy_1_Ic8bbvt1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_56){
  if ((!(s_56.data_0 == NIM_NIL))){
    NI32 i_33 = 0;
    {
      while (i_33 < s_56.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_33));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_56.data_0)));}}
static inline void eQwasMoved_1_I6m9e8j_ast8ri79k(seq_0_Ijmiee61_ast8ri79k* s_57){
  (*s_57).len_0 = 0;
  (*s_57).data_0 = NIM_NIL;}
void eQdestroy_1_I7og8li_ast8ri79k(seq_0_Ipw48je1_ast8ri79k s_59){
  if ((!(s_59.data_0 == NIM_NIL))){
    NI32 i_37 = 0;
    {
      while (i_37 < s_59.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_37));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_59.data_0)));}}
static inline void eQwasMoved_1_I52bdqo1_ast8ri79k(seq_0_Ipw48je1_ast8ri79k* s_60){
  (*s_60).len_0 = 0;
  (*s_60).data_0 = NIM_NIL;}
void eQdestroy_1_Iz0k69p1_ast8ri79k(seq_0_Isoawlw1_ast8ri79k s_62){
  if ((!(s_62.data_0 == NIM_NIL))){
    NI32 i_41 = 0;
    {
      while (i_41 < s_62.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_41));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_62.data_0)));}}
static inline void eQwasMoved_1_I5y4iq9_ast8ri79k(seq_0_Isoawlw1_ast8ri79k* s_63){
  (*s_63).len_0 = 0;
  (*s_63).data_0 = NIM_NIL;}
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
static inline NI32 capInBytes_0_Ilkynur1_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_68){
  NI32 result_36;
  NI32 X60Qx_2;
  if ((!(s_68.data_0 == NIM_NIL))){
    NI32 X60Qx_119 = allocatedSize_0_sysvq0asl(((void*)((void*)s_68.data_0)));
    X60Qx_2 = X60Qx_119;}
  else {
    X60Qx_2 = 0;}
  result_36 = X60Qx_2;
  return result_36;}
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
static inline NI32 capInBytes_0_Ittsk85_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k s_69){
  NI32 result_39;
  NI32 X60Qx_3;
  if ((!(s_69.data_0 == NIM_NIL))){
    NI32 X60Qx_122 = allocatedSize_0_sysvq0asl(((void*)((void*)s_69.data_0)));
    X60Qx_3 = X60Qx_122;}
  else {
    X60Qx_3 = 0;}
  result_39 = X60Qx_3;
  return result_39;}
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
static inline NI32 capInBytes_0_Iifs4oa_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_70){
  NI32 result_42;
  NI32 X60Qx_4;
  if ((!(s_70.data_0 == NIM_NIL))){
    NI32 X60Qx_125 = allocatedSize_0_sysvq0asl(((void*)((void*)s_70.data_0)));
    X60Qx_4 = X60Qx_125;}
  else {
    X60Qx_4 = 0;}
  result_42 = X60Qx_4;
  return result_42;}
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
static inline NI32 capInBytes_0_I4tsb7_ast8ri79k(seq_0_Ipw48je1_ast8ri79k s_71){
  NI32 result_45;
  NI32 X60Qx_5;
  if ((!(s_71.data_0 == NIM_NIL))){
    NI32 X60Qx_128 = allocatedSize_0_sysvq0asl(((void*)((void*)s_71.data_0)));
    X60Qx_5 = X60Qx_128;}
  else {
    X60Qx_5 = 0;}
  result_45 = X60Qx_5;
  return result_45;}
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
static inline NI32 capInBytes_0_Iktr4pk_ast8ri79k(seq_0_Isoawlw1_ast8ri79k s_72){
  NI32 result_48;
  NI32 X60Qx_6;
  if ((!(s_72.data_0 == NIM_NIL))){
    NI32 X60Qx_131 = allocatedSize_0_sysvq0asl(((void*)((void*)s_72.data_0)));
    X60Qx_6 = X60Qx_131;}
  else {
    X60Qx_6 = 0;}
  result_48 = X60Qx_6;
  return result_48;}
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
void X60Qini_0_ast8ri79k(void){
  if (X60QiniGuard_0_ast8ri79k){
    return;}
  X60QiniGuard_0_ast8ri79k = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tabcr240b1();
  X60Qini_0_set37vj3r();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_for2ybv4p1();
  X60Qini_0_assy765wm();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_linxafkvx1();
  X60Qini_0_nifjp9lau1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_symkyk35i1();}
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
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
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
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
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
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
