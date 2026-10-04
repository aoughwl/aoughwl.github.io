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
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
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
typedef struct BuiltinTypes_0_buiyylk1h1{
  TokenBuf_0_nifb6mq6y1 mem_0;
  Cursor_0_nifb6mq6y1 autoType_0;
  Cursor_0_nifb6mq6y1 stringType_0;
  Cursor_0_nifb6mq6y1 intType_0;
  Cursor_0_nifb6mq6y1 uintType_0;
  Cursor_0_nifb6mq6y1 floatType_0;
  Cursor_0_nifb6mq6y1 boolType_0;
  Cursor_0_nifb6mq6y1 charType_0;
  Cursor_0_nifb6mq6y1 voidType_0;
  Cursor_0_nifb6mq6y1 nilType_0;
  Cursor_0_nifb6mq6y1 int8Type_0;
  Cursor_0_nifb6mq6y1 int16Type_0;
  Cursor_0_nifb6mq6y1 int32Type_0;
  Cursor_0_nifb6mq6y1 int64Type_0;
  Cursor_0_nifb6mq6y1 uint8Type_0;
  Cursor_0_nifb6mq6y1 uint16Type_0;
  Cursor_0_nifb6mq6y1 uint32Type_0;
  Cursor_0_nifb6mq6y1 uint64Type_0;
  Cursor_0_nifb6mq6y1 float32Type_0;
  Cursor_0_nifb6mq6y1 float64Type_0;
  Cursor_0_nifb6mq6y1 emptyTupleType_0;
  Cursor_0_nifb6mq6y1 untypedType_0;
  Cursor_0_nifb6mq6y1 cstringType_0;
  Cursor_0_nifb6mq6y1 vtableType_0;
  Cursor_0_nifb6mq6y1 continuationType_0;}
BuiltinTypes_0_buiyylk1h1;
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
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
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
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
static inline NI32 high_3_Ib20i801_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_16);
static inline NU32* getQ_8_I1lkkvo_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_17, NU32 i_8);
void enlarge_0_I4mrsk51_buiyylk1h1(BiTable_0_Icvz6lt_buiyylk1h1* t_9);
void setLen_0_Isypn1s_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_22, NI32 newLen_4);
static inline void putQ_8_Iltefhx_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_25, NU32 i_13, NU32 elem_5);
static inline NI32 high_3_Ifgr4t11_buiyylk1h1(seq_0_In6doa_arecyyj7v s_28);
static inline NU32* getQ_8_Ii9prbm1_buiyylk1h1(seq_0_In6doa_arecyyj7v s_29, NU32 i_14);
void enlarge_0_Ix6p1u01_buiyylk1h1(BiTable_0_I0ksat5_ast8ri79k* t_10);
void setLen_0_Ihfm18w_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_33, NI32 newLen_8);
static inline void putQ_8_Ipsd6qc1_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_36, NU32 i_18, NU32 elem_7);
static inline NI32 high_3_Izsl4h11_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k s_37);
static inline NU32* getQ_8_Ipe8xs01_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k s_38, NU32 i_19);
void enlarge_0_Ihigsb71_buiyylk1h1(BiTable_0_Itvq7bk_ast8ri79k* t_11);
void setLen_0_Itea5o81_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_43, NI32 newLen_12);
static inline void putQ_8_It4t9dr_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_46, NU32 i_24, NU32 elem_8);
static inline void add_0_I8fahwb_buiyylk1h1(seq_0_Iotb7mc_ast8ri79k* s_47, NI64 elem_9);
static inline NI32 len_3_If16jqr1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_49);
static inline void newSeq_1_Iq8m0a91_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_50, NI32 newLen_15);
static inline void swap_0_Iy6v9ra1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* x_7, seq_0_Iaza5ca1_buiyylk1h1* y_3);
static inline NU32* getQ_7_Iy9op7o1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_51, NI32 i_26);
static inline NU32 move_0_Ijeywfo_buiyylk1h1(NU32* x_8);
void shrink_0_Idm4aal_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_52, NI32 newLen_16);
void growUnsafe_0_I70ktio1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_53, NI32 newLen_17);
static inline void newSeq_1_I32yucz_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_57, NI32 newLen_18);
static inline void swap_0_Ir1sacn1_buiyylk1h1(seq_0_In6doa_arecyyj7v* x_11, seq_0_In6doa_arecyyj7v* y_4);
static inline NU32 move_0_Izg2fga1_buiyylk1h1(NU32* x_12);
void shrink_0_Im65e8d_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_59, NI32 newLen_19);
void growUnsafe_0_Ikzmt9l1_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_60, NI32 newLen_20);
static inline NI32 len_3_Iuo2rc51_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k s_62);
static inline void newSeq_1_I6ltqq61_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_63, NI32 newLen_21);
static inline void swap_0_I6eckbf1_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* x_13, seq_0_Iwy7s2o_ast8ri79k* y_5);
static inline NU32* getQ_7_Ilsb84j1_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k s_64, NI32 i_30);
static inline NU32 move_0_Ietsi66_buiyylk1h1(NU32* x_14);
void shrink_0_It5i65g1_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_65, NI32 newLen_22);
void growUnsafe_0_In7jweg_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_66, NI32 newLen_23);
NB8 resize_0_Itn1ieo1_buiyylk1h1(seq_0_Iotb7mc_ast8ri79k* dest_6, NI32 addedElements_6);
seq_0_Iaza5ca1_buiyylk1h1 newSeq_0_Ilpxoqc1_buiyylk1h1(NI32 size_5);
static inline NI32 capInBytes_0_Ipcgi0v1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_69);
NB8 resize_0_Iuxedyo1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* dest_7, NI32 addedElements_7);
seq_0_In6doa_arecyyj7v newSeq_0_Ikhckyq1_buiyylk1h1(NI32 size_8);
NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_arecyyj7v* dest_8, NI32 addedElements_8);
seq_0_Iwy7s2o_ast8ri79k newSeq_0_Ixuxdi21_buiyylk1h1(NI32 size_10);
NB8 resize_0_Isps98o_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* dest_9, NI32 addedElements_9);
static inline NI32 memSizeInBytes_0_Igp775b_buiyylk1h1(NI32 size_13);
void eQdestroy_1_I5fjqyi1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_84);
static inline void eQwasMoved_1_Iew8iz1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_85);
extern NU32 hash_1_has9tn57v(string_0_sysvq0asl s_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_33);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline NU32 nextTry_0_bitekkhcx1(NU32 h_0, NU32 maxHash_0);
static inline NB8 mustRehash_0_bitekkhcx1(NI32 length_0, NI32 counter_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline void add_0_Ig6072n_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* s_35, string_0_sysvq0asl elem_9);
static inline NU32 hash_3_has9tn57v(NI64 x_0);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82);
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37);
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33);
extern void eQdestroy_1_Iscb4i31_arecyyj7v(seq_0_In6doa_arecyyj7v s_81);
static inline void eQwasMoved_1_I5re2ul_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k* s_54);
extern void eQdestroy_1_Inr6ycs1_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k s_53);
static inline NI32 capInBytes_0_Ilkynur1_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_68);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 capInBytes_0_Iev6wua1_arecyyj7v(seq_0_In6doa_arecyyj7v s_89);
static inline NI32 capInBytes_0_Ittsk85_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k s_69);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
static inline NI32 memSizeInBytes_0_Iqj0wsf_ast8ri79k(NI32 size_23);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 memSizeInBytes_0_Ivqzo5x1_arecyyj7v(NI32 size_29);
static inline NI32 memSizeInBytes_0_I4sctiu_ast8ri79k(NI32 size_25);
extern void dealloc_1_sysvq0asl(void* p_20);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern void X60Qini_0_sysvq0asl(void);
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
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline NI32 capInBytes_0_Ih2sbn01_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_65);
extern NB8 resize_0_I4buliy_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1* dest_6, NI32 addedElements_6);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
LongString_0_sysvq0asl const strlit_0_I10459095262102366334_buiyylk1h1 = {
  .fullLen_0 = 18, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "string.0.sysvq0asl"}
;
LongString_0_sysvq0asl const strlit_0_I9664704115936008796_buiyylk1h1 = {
  .fullLen_0 = 22, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "LongString.0.sysvq0asl"}
;
LongString_0_sysvq0asl const strlit_0_I4783242303970288541_buiyylk1h1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bytes.0"}
;
LongString_0_sysvq0asl const strlit_0_I18083737681243856668_buiyylk1h1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "more.0"}
;
LongString_0_sysvq0asl const strlit_0_I16529829149455363342_buiyylk1h1 = {
  .fullLen_0 = 24, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "Continuation.0.sysvq0asl"}
;
LongString_0_sysvq0asl const strlit_0_I2419004569819514924_buiyylk1h1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "auto"}
;
LongString_0_sysvq0asl const strlit_0_I14845240230376595005_buiyylk1h1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "nilt"}
;
LongString_0_sysvq0asl const strlit_0_I18086024188298164462_buiyylk1h1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tuple"}
;
LongString_0_sysvq0asl const strlit_0_I1016912281706840257_buiyylk1h1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "untyped"}
;
LongString_0_sysvq0asl const strlit_0_I14727864736786204059_buiyylk1h1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cstring"}
;
LongString_0_sysvq0asl const strlit_0_I12905769428011359788_buiyylk1h1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "notnil"}
;
LongString_0_sysvq0asl const strlit_0_I2984705338531181753_buiyylk1h1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "uarray"}
;
NB8 X60QiniGuard_0_buiyylk1h1;
NU32 getOrIncl_0_Is83dq9_buiyylk1h1(BiTable_0_Icvz6lt_buiyylk1h1* t_3, string_0_sysvq0asl v_3){
  NU32 result_4;
  NU32 origH_0 = hash_1_has9tn57v(v_3);
  NI32 X60Qx_71 = high_3_Ib20i801_buiyylk1h1((*t_3).keys_0);
  NU32 h_0 = ((NU32)(origH_0 & ((NU32)X60Qx_71)));
  if ((!((*t_3).keys_0.len_0 == 0))){
    {
      while (NIM_TRUE){
        NU32* X60Qx_72 = getQ_8_I1lkkvo_buiyylk1h1((*t_3).keys_0, h_0);
        NU32 litId_0 = (*X60Qx_72);
        if ((!(((NU32)0u) < ((NU32)litId_0)))){
          goto whileStmtLabel_0;}
        NU32* X60Qx_73 = getQ_8_I1lkkvo_buiyylk1h1((*t_3).keys_0, h_0);
        string_0_sysvq0asl* X60Qx_74 = getQ_7_Ir6d0tw_aow7lb5cq1((*t_3).vals_0, ((NI32)(((NI32)(*X60Qx_73)) - ((NI32)1))));
        NB8 X60Qx_75 = eqQ_20_sysvq0asl(v_3, (*X60Qx_74));
        if (X60Qx_75){
          return litId_0;}
        NI32 X60Qx_76 = high_3_Ib20i801_buiyylk1h1((*t_3).keys_0);
        NU32 X60Qx_77 = nextTry_0_bitekkhcx1(h_0, ((NU32)X60Qx_76));
        h_0 = X60Qx_77;}}
    whileStmtLabel_0: ;
    NB8 X60Qx_78 = mustRehash_0_bitekkhcx1((*t_3).keys_0.len_0, (*t_3).vals_0.len_0);
    if (X60Qx_78){
      enlarge_0_I4mrsk51_buiyylk1h1(t_3);
      NI32 X60Qx_79 = high_3_Ib20i801_buiyylk1h1((*t_3).keys_0);
      h_0 = ((NU32)(origH_0 & ((NU32)X60Qx_79)));
      {
        while (NIM_TRUE){
          NU32* X60Qx_80 = getQ_8_I1lkkvo_buiyylk1h1((*t_3).keys_0, h_0);
          NU32 litId_1 = (*X60Qx_80);
          if ((!(((NU32)0u) < ((NU32)litId_1)))){
            goto whileStmtLabel_1;}
          NI32 X60Qx_81 = high_3_Ib20i801_buiyylk1h1((*t_3).keys_0);
          NU32 X60Qx_82 = nextTry_0_bitekkhcx1(h_0, ((NU32)X60Qx_81));
          h_0 = X60Qx_82;}}
      whileStmtLabel_1: ;}}
  else {
    setLen_0_Isypn1s_buiyylk1h1((&(*t_3).keys_0), 16);
    NI32 X60Qx_83 = high_3_Ib20i801_buiyylk1h1((*t_3).keys_0);
    h_0 = ((NU32)(origH_0 & ((NU32)X60Qx_83)));}
  result_4 = ((NU32)((NI32)((*t_3).vals_0.len_0 + ((NI32)1))));
  putQ_8_Iltefhx_buiyylk1h1((&(*t_3).keys_0), h_0, result_4);
  string_0_sysvq0asl X60Qx_84 = nimStrDup(v_3);
  add_0_Ig6072n_aow7lb5cq1((&(*t_3).vals_0), X60Qx_84);
  return result_4;}
NU32 getOrIncl_0_Inyo00c_buiyylk1h1(BiTable_0_I0ksat5_ast8ri79k* t_5, string_0_sysvq0asl v_4){
  NU32 result_5;
  NU32 origH_1 = hash_1_has9tn57v(v_4);
  NI32 X60Qx_85 = high_3_Ifgr4t11_buiyylk1h1((*t_5).keys_0);
  NU32 h_1 = ((NU32)(origH_1 & ((NU32)X60Qx_85)));
  if ((!((*t_5).keys_0.len_0 == 0))){
    {
      while (NIM_TRUE){
        NU32* X60Qx_86 = getQ_8_Ii9prbm1_buiyylk1h1((*t_5).keys_0, h_1);
        NU32 litId_2 = (*X60Qx_86);
        if ((!(((NU32)0u) < ((NU32)litId_2)))){
          goto whileStmtLabel_0;}
        NU32* X60Qx_87 = getQ_8_Ii9prbm1_buiyylk1h1((*t_5).keys_0, h_1);
        string_0_sysvq0asl* X60Qx_88 = getQ_7_Ir6d0tw_aow7lb5cq1((*t_5).vals_0, ((NI32)(((NI32)(*X60Qx_87)) - ((NI32)1))));
        NB8 X60Qx_89 = eqQ_20_sysvq0asl(v_4, (*X60Qx_88));
        if (X60Qx_89){
          return litId_2;}
        NI32 X60Qx_90 = high_3_Ifgr4t11_buiyylk1h1((*t_5).keys_0);
        NU32 X60Qx_91 = nextTry_0_bitekkhcx1(h_1, ((NU32)X60Qx_90));
        h_1 = X60Qx_91;}}
    whileStmtLabel_0: ;
    NB8 X60Qx_92 = mustRehash_0_bitekkhcx1((*t_5).keys_0.len_0, (*t_5).vals_0.len_0);
    if (X60Qx_92){
      enlarge_0_Ix6p1u01_buiyylk1h1(t_5);
      NI32 X60Qx_93 = high_3_Ifgr4t11_buiyylk1h1((*t_5).keys_0);
      h_1 = ((NU32)(origH_1 & ((NU32)X60Qx_93)));
      {
        while (NIM_TRUE){
          NU32* X60Qx_94 = getQ_8_Ii9prbm1_buiyylk1h1((*t_5).keys_0, h_1);
          NU32 litId_3 = (*X60Qx_94);
          if ((!(((NU32)0u) < ((NU32)litId_3)))){
            goto whileStmtLabel_1;}
          NI32 X60Qx_95 = high_3_Ifgr4t11_buiyylk1h1((*t_5).keys_0);
          NU32 X60Qx_96 = nextTry_0_bitekkhcx1(h_1, ((NU32)X60Qx_95));
          h_1 = X60Qx_96;}}
      whileStmtLabel_1: ;}}
  else {
    setLen_0_Ihfm18w_buiyylk1h1((&(*t_5).keys_0), 16);
    NI32 X60Qx_97 = high_3_Ifgr4t11_buiyylk1h1((*t_5).keys_0);
    h_1 = ((NU32)(origH_1 & ((NU32)X60Qx_97)));}
  result_5 = ((NU32)((NI32)((*t_5).vals_0.len_0 + ((NI32)1))));
  putQ_8_Ipsd6qc1_buiyylk1h1((&(*t_5).keys_0), h_1, result_5);
  string_0_sysvq0asl X60Qx_98 = nimStrDup(v_4);
  add_0_Ig6072n_aow7lb5cq1((&(*t_5).vals_0), X60Qx_98);
  return result_5;}
NU32 getOrIncl_0_I4rntkc_buiyylk1h1(BiTable_0_Itvq7bk_ast8ri79k* t_7, NI64 v_5){
  NU32 result_6;
  NU32 origH_2 = hash_3_has9tn57v(v_5);
  NI32 X60Qx_99 = high_3_Izsl4h11_buiyylk1h1((*t_7).keys_0);
  NU32 h_2 = ((NU32)(origH_2 & ((NU32)X60Qx_99)));
  if ((!((*t_7).keys_0.len_0 == 0))){
    {
      while (NIM_TRUE){
        NU32* X60Qx_100 = getQ_8_Ipe8xs01_buiyylk1h1((*t_7).keys_0, h_2);
        NU32 litId_4 = (*X60Qx_100);
        if ((!(((NU32)0u) < ((NU32)litId_4)))){
          goto whileStmtLabel_0;}
        NU32* X60Qx_101 = getQ_8_Ipe8xs01_buiyylk1h1((*t_7).keys_0, h_2);
        NI64* X60Qx_102 = getQ_7_Ite3z0o_ast8ri79k((*t_7).vals_0, ((NI32)(((NI32)(*X60Qx_101)) - ((NI32)1))));
        if (v_5 == (*X60Qx_102)){
          return litId_4;}
        NI32 X60Qx_103 = high_3_Izsl4h11_buiyylk1h1((*t_7).keys_0);
        NU32 X60Qx_104 = nextTry_0_bitekkhcx1(h_2, ((NU32)X60Qx_103));
        h_2 = X60Qx_104;}}
    whileStmtLabel_0: ;
    NB8 X60Qx_105 = mustRehash_0_bitekkhcx1((*t_7).keys_0.len_0, (*t_7).vals_0.len_0);
    if (X60Qx_105){
      enlarge_0_Ihigsb71_buiyylk1h1(t_7);
      NI32 X60Qx_106 = high_3_Izsl4h11_buiyylk1h1((*t_7).keys_0);
      h_2 = ((NU32)(origH_2 & ((NU32)X60Qx_106)));
      {
        while (NIM_TRUE){
          NU32* X60Qx_107 = getQ_8_Ipe8xs01_buiyylk1h1((*t_7).keys_0, h_2);
          NU32 litId_5 = (*X60Qx_107);
          if ((!(((NU32)0u) < ((NU32)litId_5)))){
            goto whileStmtLabel_1;}
          NI32 X60Qx_108 = high_3_Izsl4h11_buiyylk1h1((*t_7).keys_0);
          NU32 X60Qx_109 = nextTry_0_bitekkhcx1(h_2, ((NU32)X60Qx_108));
          h_2 = X60Qx_109;}}
      whileStmtLabel_1: ;}}
  else {
    setLen_0_Itea5o81_buiyylk1h1((&(*t_7).keys_0), 16);
    NI32 X60Qx_110 = high_3_Izsl4h11_buiyylk1h1((*t_7).keys_0);
    h_2 = ((NU32)(origH_2 & ((NU32)X60Qx_110)));}
  result_6 = ((NU32)((NI32)((*t_7).vals_0.len_0 + ((NI32)1))));
  putQ_8_It4t9dr_buiyylk1h1((&(*t_7).keys_0), h_2, result_6);
  add_0_I8fahwb_buiyylk1h1((&(*t_7).vals_0), v_5);
  return result_6;}
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
void enlarge_0_I4mrsk51_buiyylk1h1(BiTable_0_Icvz6lt_buiyylk1h1* t_9){
  seq_0_Iaza5ca1_buiyylk1h1 n_0;
  eQwasMoved_1_Iew8iz1_buiyylk1h1((&n_0));
  NI32 X60Qx_112 = len_3_If16jqr1_buiyylk1h1((*t_9).keys_0);
  newSeq_1_Iq8m0a91_buiyylk1h1((&n_0), ((NI32)(X60Qx_112 * 2)));
  swap_0_Iy6v9ra1_buiyylk1h1((&(*t_9).keys_0), (&n_0));
  {
    NI32 X60Qlf_0 = 0;
    NI32 X60Qlf_1 = high_3_Ib20i801_buiyylk1h1(n_0);
    NI32 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 <= X60Qlf_1){
        {
          NU32* X60Qx_113 = getQ_7_Iy9op7o1_buiyylk1h1(n_0, X60Qlf_2);
          NU32 X60Qii_2 = (*X60Qx_113);
          if (((NU32)0u) < ((NU32)X60Qii_2)){
            string_0_sysvq0asl* X60Qx_114 = getQ_7_Ir6d0tw_aow7lb5cq1((*t_9).vals_0, ((NI32)(((NI32)X60Qii_2) - ((NI32)1))));
            NU32 X60Qx_115 = hash_1_has9tn57v((*X60Qx_114));
            NI32 X60Qx_116 = high_3_Ib20i801_buiyylk1h1((*t_9).keys_0);
            NU32 X60Qii_3 = ((NU32)(X60Qx_115 & ((NU32)X60Qx_116)));
            while (NIM_TRUE){
              NU32* X60Qx_117 = getQ_8_I1lkkvo_buiyylk1h1((*t_9).keys_0, X60Qii_3);
              if (((NU32)0u) < ((NU32)(*X60Qx_117))){
                NI32 X60Qx_118 = high_3_Ib20i801_buiyylk1h1((*t_9).keys_0);
                NU32 X60Qx_119 = nextTry_0_bitekkhcx1(X60Qii_3, ((NU32)X60Qx_118));
                X60Qii_3 = X60Qx_119;}
              else {
                break;}}
            NU32* X60Qx_120 = getQ_7_Iy9op7o1_buiyylk1h1(n_0, X60Qlf_2);
            NU32 X60Qx_121 = move_0_Ijeywfo_buiyylk1h1(X60Qx_120);
            putQ_8_Iltefhx_buiyylk1h1((&(*t_9).keys_0), X60Qii_3, X60Qx_121);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroy_1_I5fjqyi1_buiyylk1h1(n_0);}
void setLen_0_Isypn1s_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_22, NI32 newLen_4){
  if (newLen_4 < (*s_22).len_0){
    shrink_0_Idm4aal_buiyylk1h1(s_22, newLen_4);}
  else {
    NI32 i_12 = (*s_22).len_0;
    growUnsafe_0_I70ktio1_buiyylk1h1(s_22, newLen_4);
    if ((*s_22).data_0 == NIM_NIL){
      return;}
    {
      while (i_12 < newLen_4){
        (*s_22).data_0[i_12] = ((NU32)0u);
        inc_1_I6wjjge_aow2h993l1((&i_12));}}
    whileStmtLabel_0: ;}}
static inline void putQ_8_Iltefhx_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_25, NU32 i_13, NU32 elem_5){
  if ((!(i_13 < ((NU32)(*s_25).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_25).data_0[((NI32)i_13)] = elem_5;}
static inline NI32 high_3_Ifgr4t11_buiyylk1h1(seq_0_In6doa_arecyyj7v s_28){
  NI32 result_10;
  result_10 = ((NI32)(s_28.len_0 - 1));
  return result_10;}
static inline NU32* getQ_8_Ii9prbm1_buiyylk1h1(seq_0_In6doa_arecyyj7v s_29, NU32 i_14){
  if ((!(i_14 < ((NU32)s_29.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  NU32* result_11;
  result_11 = (&s_29.data_0[((NI32)i_14)]);
  return result_11;}
void enlarge_0_Ix6p1u01_buiyylk1h1(BiTable_0_I0ksat5_ast8ri79k* t_10){
  seq_0_In6doa_arecyyj7v n_1;
  eQwasMoved_1_I2k4kel_arecyyj7v((&n_1));
  NI32 X60Qx_124 = len_3_I6y2imo_arecyyj7v((*t_10).keys_0);
  newSeq_1_I32yucz_buiyylk1h1((&n_1), ((NI32)(X60Qx_124 * 2)));
  swap_0_Ir1sacn1_buiyylk1h1((&(*t_10).keys_0), (&n_1));
  {
    NI32 X60Qlf_3 = 0;
    NI32 X60Qlf_4 = high_3_Ifgr4t11_buiyylk1h1(n_1);
    NI32 X60Qlf_5 = X60Qlf_3;
    {
      while (X60Qlf_5 <= X60Qlf_4){
        {
          NU32* X60Qx_125 = getQ_7_I2v00yv1_arecyyj7v(n_1, X60Qlf_5);
          NU32 X60Qii_2 = (*X60Qx_125);
          if (((NU32)0u) < ((NU32)X60Qii_2)){
            string_0_sysvq0asl* X60Qx_126 = getQ_7_Ir6d0tw_aow7lb5cq1((*t_10).vals_0, ((NI32)(((NI32)X60Qii_2) - ((NI32)1))));
            NU32 X60Qx_127 = hash_1_has9tn57v((*X60Qx_126));
            NI32 X60Qx_128 = high_3_Ifgr4t11_buiyylk1h1((*t_10).keys_0);
            NU32 X60Qii_3 = ((NU32)(X60Qx_127 & ((NU32)X60Qx_128)));
            while (NIM_TRUE){
              NU32* X60Qx_129 = getQ_8_Ii9prbm1_buiyylk1h1((*t_10).keys_0, X60Qii_3);
              if (((NU32)0u) < ((NU32)(*X60Qx_129))){
                NI32 X60Qx_130 = high_3_Ifgr4t11_buiyylk1h1((*t_10).keys_0);
                NU32 X60Qx_131 = nextTry_0_bitekkhcx1(X60Qii_3, ((NU32)X60Qx_130));
                X60Qii_3 = X60Qx_131;}
              else {
                break;}}
            NU32* X60Qx_132 = getQ_7_I2v00yv1_arecyyj7v(n_1, X60Qlf_5);
            NU32 X60Qx_133 = move_0_Izg2fga1_buiyylk1h1(X60Qx_132);
            putQ_8_Ipsd6qc1_buiyylk1h1((&(*t_10).keys_0), X60Qii_3, X60Qx_133);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroy_1_Iscb4i31_arecyyj7v(n_1);}
void setLen_0_Ihfm18w_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_33, NI32 newLen_8){
  if (newLen_8 < (*s_33).len_0){
    shrink_0_Im65e8d_buiyylk1h1(s_33, newLen_8);}
  else {
    NI32 i_17 = (*s_33).len_0;
    growUnsafe_0_Ikzmt9l1_buiyylk1h1(s_33, newLen_8);
    if ((*s_33).data_0 == NIM_NIL){
      return;}
    {
      while (i_17 < newLen_8){
        (*s_33).data_0[i_17] = ((NU32)0u);
        inc_1_I6wjjge_aow2h993l1((&i_17));}}
    whileStmtLabel_0: ;}}
static inline void putQ_8_Ipsd6qc1_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_36, NU32 i_18, NU32 elem_7){
  if ((!(i_18 < ((NU32)(*s_36).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_36).data_0[((NI32)i_18)] = elem_7;}
static inline NI32 high_3_Izsl4h11_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k s_37){
  NI32 result_12;
  result_12 = ((NI32)(s_37.len_0 - 1));
  return result_12;}
static inline NU32* getQ_8_Ipe8xs01_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k s_38, NU32 i_19){
  if ((!(i_19 < ((NU32)s_38.len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I6139986957253126309_ast8ri79k)}
    );}
  NU32* result_13;
  result_13 = (&s_38.data_0[((NI32)i_19)]);
  return result_13;}
void enlarge_0_Ihigsb71_buiyylk1h1(BiTable_0_Itvq7bk_ast8ri79k* t_11){
  seq_0_Iwy7s2o_ast8ri79k n_2;
  eQwasMoved_1_I5re2ul_ast8ri79k((&n_2));
  NI32 X60Qx_135 = len_3_Iuo2rc51_buiyylk1h1((*t_11).keys_0);
  newSeq_1_I6ltqq61_buiyylk1h1((&n_2), ((NI32)(X60Qx_135 * 2)));
  swap_0_I6eckbf1_buiyylk1h1((&(*t_11).keys_0), (&n_2));
  {
    NI32 X60Qlf_6 = 0;
    NI32 X60Qlf_7 = high_3_Izsl4h11_buiyylk1h1(n_2);
    NI32 X60Qlf_8 = X60Qlf_6;
    {
      while (X60Qlf_8 <= X60Qlf_7){
        {
          NU32* X60Qx_136 = getQ_7_Ilsb84j1_buiyylk1h1(n_2, X60Qlf_8);
          NU32 X60Qii_2 = (*X60Qx_136);
          if (((NU32)0u) < ((NU32)X60Qii_2)){
            NI64* X60Qx_137 = getQ_7_Ite3z0o_ast8ri79k((*t_11).vals_0, ((NI32)(((NI32)X60Qii_2) - ((NI32)1))));
            NU32 X60Qx_138 = hash_3_has9tn57v((*X60Qx_137));
            NI32 X60Qx_139 = high_3_Izsl4h11_buiyylk1h1((*t_11).keys_0);
            NU32 X60Qii_3 = ((NU32)(X60Qx_138 & ((NU32)X60Qx_139)));
            while (NIM_TRUE){
              NU32* X60Qx_140 = getQ_8_Ipe8xs01_buiyylk1h1((*t_11).keys_0, X60Qii_3);
              if (((NU32)0u) < ((NU32)(*X60Qx_140))){
                NI32 X60Qx_141 = high_3_Izsl4h11_buiyylk1h1((*t_11).keys_0);
                NU32 X60Qx_142 = nextTry_0_bitekkhcx1(X60Qii_3, ((NU32)X60Qx_141));
                X60Qii_3 = X60Qx_142;}
              else {
                break;}}
            NU32* X60Qx_143 = getQ_7_Ilsb84j1_buiyylk1h1(n_2, X60Qlf_8);
            NU32 X60Qx_144 = move_0_Ietsi66_buiyylk1h1(X60Qx_143);
            putQ_8_It4t9dr_buiyylk1h1((&(*t_11).keys_0), X60Qii_3, X60Qx_144);}}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_8));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroy_1_Inr6ycs1_ast8ri79k(n_2);}
void setLen_0_Itea5o81_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_43, NI32 newLen_12){
  if (newLen_12 < (*s_43).len_0){
    shrink_0_It5i65g1_buiyylk1h1(s_43, newLen_12);}
  else {
    NI32 i_23 = (*s_43).len_0;
    growUnsafe_0_In7jweg_buiyylk1h1(s_43, newLen_12);
    if ((*s_43).data_0 == NIM_NIL){
      return;}
    {
      while (i_23 < newLen_12){
        (*s_43).data_0[i_23] = ((NU32)0u);
        inc_1_I6wjjge_aow2h993l1((&i_23));}}
    whileStmtLabel_0: ;}}
static inline void putQ_8_It4t9dr_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_46, NU32 i_24, NU32 elem_8){
  if ((!(i_24 < ((NU32)(*s_46).len_0)))){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I8762445540754965479_ast8ri79k)}
    );}
  (*s_46).data_0[((NI32)i_24)] = elem_8;}
static inline void add_0_I8fahwb_buiyylk1h1(seq_0_Iotb7mc_ast8ri79k* s_47, NI64 elem_9){
  NI32 L_1 = (*s_47).len_0;
  NI32 X60Qx_145 = capInBytes_0_Ilkynur1_ast8ri79k((*s_47));
  if (X60Qx_145 < ((NI32)(((NI32)(L_1 * sizeof(NI64))) + sizeof(NI64)))){
    NB8 X60Qx_146 = resize_0_Itn1ieo1_buiyylk1h1(s_47, 1);
    if ((!X60Qx_146)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_1] = elem_9;}
static inline NI32 len_3_If16jqr1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_49){
  NI32 result_15;
  result_15 = s_49.len_0;
  return result_15;}
static inline void newSeq_1_Iq8m0a91_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_50, NI32 newLen_15){
  seq_0_Iaza5ca1_buiyylk1h1 X60Qx_147 = newSeq_0_Ilpxoqc1_buiyylk1h1(newLen_15);
  (*s_50) = X60Qx_147;}
static inline void swap_0_Iy6v9ra1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* x_7, seq_0_Iaza5ca1_buiyylk1h1* y_3){
  seq_0_Iaza5ca1_buiyylk1h1 tmp_0 = (*x_7);
  (*x_7) = (*y_3);
  (*y_3) = tmp_0;}
static inline NU32* getQ_7_Iy9op7o1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_51, NI32 i_26){
  NB8 X60Qx_148;
  if (i_26 < s_51.len_0){
    X60Qx_148 = (0 <= i_26);}
  else {
    X60Qx_148 = NIM_FALSE;}
  if ((!X60Qx_148)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_16;
  result_16 = (&s_51.data_0[i_26]);
  return result_16;}
static inline NU32 move_0_Ijeywfo_buiyylk1h1(NU32* x_8){
  NU32 result_17;
  result_17 = (*x_8);
  return result_17;}
void shrink_0_Idm4aal_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_52, NI32 newLen_16){
  NI32 i_27 = ((NI32)((*s_52).len_0 - 1));
  {
    while (newLen_16 <= i_27){
      dec_1_I0nzoz91_aow7lb5cq1((&i_27));}}
  whileStmtLabel_0: ;
  (*s_52).len_0 = newLen_16;}
void growUnsafe_0_I70ktio1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_53, NI32 newLen_17){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_17, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_0 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_149 = capInBytes_0_Ipcgi0v1_buiyylk1h1((*s_53));
  if (X60Qx_149 < newSize_0){
    NB8 X60Qx_150 = resize_0_Iuxedyo1_buiyylk1h1(s_53, ((NI32)(newLen_17 - (*s_53).len_0)));
    if ((!X60Qx_150)){
      return;}}
  (*s_53).len_0 = newLen_17;}
static inline void newSeq_1_I32yucz_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_57, NI32 newLen_18){
  seq_0_In6doa_arecyyj7v X60Qx_154 = newSeq_0_Ikhckyq1_buiyylk1h1(newLen_18);
  (*s_57) = X60Qx_154;}
static inline void swap_0_Ir1sacn1_buiyylk1h1(seq_0_In6doa_arecyyj7v* x_11, seq_0_In6doa_arecyyj7v* y_4){
  seq_0_In6doa_arecyyj7v tmp_1 = (*x_11);
  (*x_11) = (*y_4);
  (*y_4) = tmp_1;}
static inline NU32 move_0_Izg2fga1_buiyylk1h1(NU32* x_12){
  NU32 result_22;
  result_22 = (*x_12);
  return result_22;}
void shrink_0_Im65e8d_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_59, NI32 newLen_19){
  NI32 i_29 = ((NI32)((*s_59).len_0 - 1));
  {
    while (newLen_19 <= i_29){
      dec_1_I0nzoz91_aow7lb5cq1((&i_29));}}
  whileStmtLabel_0: ;
  (*s_59).len_0 = newLen_19;}
void growUnsafe_0_Ikzmt9l1_buiyylk1h1(seq_0_In6doa_arecyyj7v* s_60, NI32 newLen_20){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_20, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_1 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_156 = capInBytes_0_Iev6wua1_arecyyj7v((*s_60));
  if (X60Qx_156 < newSize_1){
    NB8 X60Qx_157 = resize_0_I6ho9ve_buiyylk1h1(s_60, ((NI32)(newLen_20 - (*s_60).len_0)));
    if ((!X60Qx_157)){
      return;}}
  (*s_60).len_0 = newLen_20;}
static inline NI32 len_3_Iuo2rc51_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k s_62){
  NI32 result_23;
  result_23 = s_62.len_0;
  return result_23;}
static inline void newSeq_1_I6ltqq61_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_63, NI32 newLen_21){
  seq_0_Iwy7s2o_ast8ri79k X60Qx_158 = newSeq_0_Ixuxdi21_buiyylk1h1(newLen_21);
  (*s_63) = X60Qx_158;}
static inline void swap_0_I6eckbf1_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* x_13, seq_0_Iwy7s2o_ast8ri79k* y_5){
  seq_0_Iwy7s2o_ast8ri79k tmp_2 = (*x_13);
  (*x_13) = (*y_5);
  (*y_5) = tmp_2;}
static inline NU32* getQ_7_Ilsb84j1_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k s_64, NI32 i_30){
  NB8 X60Qx_159;
  if (i_30 < s_64.len_0){
    X60Qx_159 = (0 <= i_30);}
  else {
    X60Qx_159 = NIM_FALSE;}
  if ((!X60Qx_159)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NU32* result_24;
  result_24 = (&s_64.data_0[i_30]);
  return result_24;}
static inline NU32 move_0_Ietsi66_buiyylk1h1(NU32* x_14){
  NU32 result_25;
  result_25 = (*x_14);
  return result_25;}
void shrink_0_It5i65g1_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_65, NI32 newLen_22){
  NI32 i_31 = ((NI32)((*s_65).len_0 - 1));
  {
    while (newLen_22 <= i_31){
      dec_1_I0nzoz91_aow7lb5cq1((&i_31));}}
  whileStmtLabel_0: ;
  (*s_65).len_0 = newLen_22;}
void growUnsafe_0_In7jweg_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* s_66, NI32 newLen_23){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_23, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_2 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_160 = capInBytes_0_Ittsk85_ast8ri79k((*s_66));
  if (X60Qx_160 < newSize_2){
    NB8 X60Qx_161 = resize_0_Isps98o_buiyylk1h1(s_66, ((NI32)(newLen_23 - (*s_66).len_0)));
    if ((!X60Qx_161)){
      return;}}
  (*s_66).len_0 = newLen_23;}
NB8 resize_0_Itn1ieo1_buiyylk1h1(seq_0_Iotb7mc_ast8ri79k* dest_6, NI32 addedElements_6){
  NB8 result_27;
  NI32 X60Qx_163 = capInBytes_0_Ilkynur1_ast8ri79k((*dest_6));
  NI32 oldCap_1 = ((NI32)(X60Qx_163 / sizeof(NI64)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_6);
  NI32 memSize_1 = memSizeInBytes_0_Iqj0wsf_ast8ri79k(newCap_1);
  void* X60Qx_164 = realloc_1_sysvq0asl(((void*)((void*)(*dest_6).data_0)), memSize_1);
  (*dest_6).data_0 = ((NI64*)X60Qx_164);
  if ((*dest_6).data_0 == NIM_NIL){
    (*dest_6).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_1);
    result_27 = NIM_FALSE;}
  else {
    result_27 = NIM_TRUE;}
  return result_27;}
seq_0_Iaza5ca1_buiyylk1h1 newSeq_0_Ilpxoqc1_buiyylk1h1(NI32 size_5){
  seq_0_Iaza5ca1_buiyylk1h1 result_28;
  if (size_5 == 0){
    result_28 = (seq_0_Iaza5ca1_buiyylk1h1){
      .len_0 = size_5, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Igp775b_buiyylk1h1(size_5);
    void* X60Qx_165 = alloc_1_sysvq0asl(memSize_2);
    result_28 = (seq_0_Iaza5ca1_buiyylk1h1){
      .len_0 = size_5, .data_0 = ((NU32*)X60Qx_165)}
    ;
    if ((!(result_28.data_0 == NIM_NIL))){
      NI32 i_32 = 0;
      {
        while (i_32 < size_5){
          result_28.data_0[i_32] = ((NU32)0u);
          inc_1_I6wjjge_aow2h993l1((&i_32));}}
      whileStmtLabel_0: ;}
    else {
      result_28.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_28;}
static inline NI32 capInBytes_0_Ipcgi0v1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_69){
  NI32 result_29;
  NI32 X60Qx_2;
  if ((!(s_69.data_0 == NIM_NIL))){
    NI32 X60Qx_166 = allocatedSize_0_sysvq0asl(((void*)((void*)s_69.data_0)));
    X60Qx_2 = X60Qx_166;}
  else {
    X60Qx_2 = 0;}
  result_29 = X60Qx_2;
  return result_29;}
NB8 resize_0_Iuxedyo1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* dest_7, NI32 addedElements_7){
  NB8 result_30;
  NI32 X60Qx_167 = capInBytes_0_Ipcgi0v1_buiyylk1h1((*dest_7));
  NI32 oldCap_2 = ((NI32)(X60Qx_167 / sizeof(NU32)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_7);
  NI32 memSize_3 = memSizeInBytes_0_Igp775b_buiyylk1h1(newCap_2);
  void* X60Qx_168 = realloc_1_sysvq0asl(((void*)((void*)(*dest_7).data_0)), memSize_3);
  (*dest_7).data_0 = ((NU32*)X60Qx_168);
  if ((*dest_7).data_0 == NIM_NIL){
    (*dest_7).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_3);
    result_30 = NIM_FALSE;}
  else {
    result_30 = NIM_TRUE;}
  return result_30;}
seq_0_In6doa_arecyyj7v newSeq_0_Ikhckyq1_buiyylk1h1(NI32 size_8){
  seq_0_In6doa_arecyyj7v result_32;
  if (size_8 == 0){
    result_32 = (seq_0_In6doa_arecyyj7v){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_4 = memSizeInBytes_0_Ivqzo5x1_arecyyj7v(size_8);
    void* X60Qx_169 = alloc_1_sysvq0asl(memSize_4);
    result_32 = (seq_0_In6doa_arecyyj7v){
      .len_0 = size_8, .data_0 = ((NU32*)X60Qx_169)}
    ;
    if ((!(result_32.data_0 == NIM_NIL))){
      NI32 i_33 = 0;
      {
        while (i_33 < size_8){
          result_32.data_0[i_33] = ((NU32)0u);
          inc_1_I6wjjge_aow2h993l1((&i_33));}}
      whileStmtLabel_0: ;}
    else {
      result_32.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_4);}}
  return result_32;}
NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_arecyyj7v* dest_8, NI32 addedElements_8){
  NB8 result_34;
  NI32 X60Qx_171 = capInBytes_0_Iev6wua1_arecyyj7v((*dest_8));
  NI32 oldCap_3 = ((NI32)(X60Qx_171 / sizeof(NU32)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_8);
  NI32 memSize_5 = memSizeInBytes_0_Ivqzo5x1_arecyyj7v(newCap_3);
  void* X60Qx_172 = realloc_1_sysvq0asl(((void*)((void*)(*dest_8).data_0)), memSize_5);
  (*dest_8).data_0 = ((NU32*)X60Qx_172);
  if ((*dest_8).data_0 == NIM_NIL){
    (*dest_8).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_5);
    result_34 = NIM_FALSE;}
  else {
    result_34 = NIM_TRUE;}
  return result_34;}
seq_0_Iwy7s2o_ast8ri79k newSeq_0_Ixuxdi21_buiyylk1h1(NI32 size_10){
  seq_0_Iwy7s2o_ast8ri79k result_35;
  if (size_10 == 0){
    result_35 = (seq_0_Iwy7s2o_ast8ri79k){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_6 = memSizeInBytes_0_I4sctiu_ast8ri79k(size_10);
    void* X60Qx_173 = alloc_1_sysvq0asl(memSize_6);
    result_35 = (seq_0_Iwy7s2o_ast8ri79k){
      .len_0 = size_10, .data_0 = ((NU32*)X60Qx_173)}
    ;
    if ((!(result_35.data_0 == NIM_NIL))){
      NI32 i_34 = 0;
      {
        while (i_34 < size_10){
          result_35.data_0[i_34] = ((NU32)0u);
          inc_1_I6wjjge_aow2h993l1((&i_34));}}
      whileStmtLabel_0: ;}
    else {
      result_35.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_6);}}
  return result_35;}
NB8 resize_0_Isps98o_buiyylk1h1(seq_0_Iwy7s2o_ast8ri79k* dest_9, NI32 addedElements_9){
  NB8 result_37;
  NI32 X60Qx_175 = capInBytes_0_Ittsk85_ast8ri79k((*dest_9));
  NI32 oldCap_4 = ((NI32)(X60Qx_175 / sizeof(NU32)));
  NI32 newCap_4 = recalcCap_0_sysvq0asl(oldCap_4, addedElements_9);
  NI32 memSize_7 = memSizeInBytes_0_I4sctiu_ast8ri79k(newCap_4);
  void* X60Qx_176 = realloc_1_sysvq0asl(((void*)((void*)(*dest_9).data_0)), memSize_7);
  (*dest_9).data_0 = ((NU32*)X60Qx_176);
  if ((*dest_9).data_0 == NIM_NIL){
    (*dest_9).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_7);
    result_37 = NIM_FALSE;}
  else {
    result_37 = NIM_TRUE;}
  return result_37;}
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
void eQdestroy_1_I5fjqyi1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1 s_84){
  if ((!(s_84.data_0 == NIM_NIL))){
    NI32 i_39 = 0;
    {
      while (i_39 < s_84.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_39));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_84.data_0)));}}
static inline void eQwasMoved_1_Iew8iz1_buiyylk1h1(seq_0_Iaza5ca1_buiyylk1h1* s_85){
  (*s_85).len_0 = 0;
  (*s_85).data_0 = NIM_NIL;}
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
void X60Qini_0_buiyylk1h1(void){
  if (X60QiniGuard_0_buiyylk1h1){
    return;}
  X60QiniGuard_0_buiyylk1h1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_bitekkhcx1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_linxafkvx1();
  X60Qini_0_nifjp9lau1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();}
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
static inline NU32 hash_3_has9tn57v(NI64 x_0){
  NU32 result_4;
  result_4 = ((NU32)x_0);
  return result_4;}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void eQwasMoved_1_I2k4kel_arecyyj7v(seq_0_In6doa_arecyyj7v* s_82){
  (*s_82).len_0 = 0;
  (*s_82).data_0 = NIM_NIL;}
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
static inline void eQwasMoved_1_I5re2ul_ast8ri79k(seq_0_Iwy7s2o_ast8ri79k* s_54){
  (*s_54).len_0 = 0;
  (*s_54).data_0 = NIM_NIL;}
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
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
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
