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
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct SizeAlign_0_siz2wt1it{
  NI32 size_0;
  NI32 align_0;}
SizeAlign_0_siz2wt1it;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
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
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
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
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_In6doa_ast8ri79k keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
typedef struct seq_0_Izov3yo_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_Izov3yo_ast8ri79k;
typedef struct BiTable_0_Ipgo74p_ast8ri79k{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
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
  BiTable_0_Ieutpr21_nifh7u8pu1 files_0;
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
typedef NU8 LoadStatus_0_prorcx25w1;

#define LacksModuleName_0_prorcx25w1 ((NU8)0)
#define LacksOffset_0_prorcx25w1 ((NU8)1)
#define LacksPosition_0_prorcx25w1 ((NU8)2)
#define LacksNothing_0_prorcx25w1 ((NU8)3)
typedef struct LoadResult_0_prorcx25w1{
  LoadStatus_0_prorcx25w1 status_0;
  Cursor_0_nifb6mq6y1 decl_0;}
LoadResult_0_prorcx25w1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13);
static inline string_0_sysvq0asl* getQ_0_I93d71y_comaa5xpt1(BiTable_0_Icvz6lt_buiyylk1h1 t_21, NU32 litId_6);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
extern LoadResult_0_prorcx25w1 tryLoadSymSafe_0_modzy18mg1(NU32 s_0);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
extern LongString_0_sysvq0asl const strlit_0_I13413619771642637377_comaa5xpt1;
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
extern LongString_0_sysvq0asl const strlit_0_I7023501325319911082_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6332049561104653135_nimry5ra91;
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10);
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6);
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern LongString_0_sysvq0asl const strlit_0_I11024699549390617459_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I1177603226064417776_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14727864736786204059_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I10462096440466995513_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I3021806080610957510_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I14845240230376595005_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I3225181402180923291_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I973692718279674627_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I6300154543333844069_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I5316556160589403975_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I13752166055203769914_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I18086024188298164462_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I16393544569146403439_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I4956278306908871092_comaa5xpt1;
extern LongString_0_sysvq0asl const strlit_0_I4167480082662538754_comaa5xpt1;
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_modzy18mg1(void);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void dealloc_1_sysvq0asl(void* p_20);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
LongString_0_sysvq0asl const strlit_0_I18029839360381635789_siz2wt1it = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "routine"}
;
NB8 X60QiniGuard_0_siz2wt1it;
string_0_sysvq0asl nodeTag_0_siz2wt1it(Cursor_0_nifb6mq6y1 n_0){
  string_0_sysvq0asl result_0;
  nimStrWasMoved((&result_0));
  nimStrDestroy(result_0);
  NU32 X60Qx_17 = tagId_0_nifb6mq6y1(n_0);
  string_0_sysvq0asl* X60Qx_18 = getQ_0_I93d71y_comaa5xpt1(pool_0_nifh7u8pu1.tags_0, X60Qx_17);
  string_0_sysvq0asl X60Qx_19 = nimStrDup((*X60Qx_18));
  result_0 = X60Qx_19;
  return result_0;}
SizeAlign_0_siz2wt1it sizeAlignOfType_0_siz2wt1it(Cursor_0_nifb6mq6y1 typ_0, NI32 depth_0){
  SizeAlign_0_siz2wt1it result_1;
  result_1 = (SizeAlign_0_siz2wt1it){
    .size_0 = ((NI32)0), .align_0 = ((NI32)0)}
  ;
  result_1.size_0 = -1;
  result_1.align_0 = -1;
  if (64 < depth_0){
    return result_1;}
  Cursor_0_nifb6mq6y1 t_1 = eQdup_0_nifb6mq6y1(typ_0);
  NifKind_0_nif81dubp1 X60Qx_20 = kind_0_nifb6mq6y1(t_1);
  if (X60Qx_20 == 4){
    NU32 sym_0 = symId_0_nifb6mq6y1(t_1);
    if (((NU32)sym_0) == ((NU32)0u)){
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;}
    LoadResult_0_prorcx25w1 res_0 = tryLoadSymSafe_0_modzy18mg1(sym_0);
    NB8 X60Qx_8;
    NB8 X60Qx_21;
    if ((!(res_0.status_0 == 3))){
      X60Qx_21 = NIM_TRUE;}
    else {
      NifKind_0_nif81dubp1 X60Qx_22 = kind_0_nifb6mq6y1(res_0.decl_0);
      X60Qx_21 = (!(X60Qx_22 == 11));}
    if (X60Qx_21){
      X60Qx_8 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_0 = nodeTag_0_siz2wt1it(res_0.decl_0);
      NB8 X60Qx_23 = eqQ_20_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
      );
      X60Qx_8 = (!X60Qx_23);
      nimStrDestroy(X60Qtmp_0);}
    if (X60Qx_8){
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;}
    Cursor_0_nifb6mq6y1 d_0 = res_0.decl_0;
    eQwasMoved_0_nifb6mq6y1((&res_0.decl_0));
    inc_0_nifb6mq6y1((&d_0));
    NI32 explicitSize_0 = -1;
    NI32 bodySize_0 = -1;
    NI32 bodyAlign_0 = -1;
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_24 = kind_0_nifb6mq6y1(d_0);
        if ((!(X60Qx_24 == 12))){
          NifKind_0_nif81dubp1 X60Qx_25 = kind_0_nifb6mq6y1(d_0);
          if (X60Qx_25 == 11){
            string_0_sysvq0asl X60Qtmp_1 = nodeTag_0_siz2wt1it(d_0);
            NB8 X60Qx_26 = eqQ_20_sysvq0asl(X60Qtmp_1, (string_0_sysvq0asl){
              .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_comaa5xpt1)}
            );
            if (X60Qx_26){
              Cursor_0_nifb6mq6y1 p_0 = eQdup_0_nifb6mq6y1(d_0);
              inc_0_nifb6mq6y1((&p_0));
              {
                while (NIM_TRUE){
                  NifKind_0_nif81dubp1 X60Qx_27 = kind_0_nifb6mq6y1(p_0);
                  if ((!(X60Qx_27 == 12))){
                    NB8 X60Qx_9;
                    NifKind_0_nif81dubp1 X60Qx_28 = kind_0_nifb6mq6y1(p_0);
                    if (X60Qx_28 == 11){
                      string_0_sysvq0asl X60Qtmp_2 = nodeTag_0_siz2wt1it(p_0);
                      NB8 X60Qx_29 = eqQ_20_sysvq0asl(X60Qtmp_2, (string_0_sysvq0asl){
                        .bytes_0 = 2053731326u, .more_0 = (&strlit_0_I6332049561104653135_nimry5ra91)}
                      );
                      X60Qx_9 = X60Qx_29;
                      nimStrDestroy(X60Qtmp_2);}
                    else {
                      X60Qx_9 = NIM_FALSE;}
                    if (X60Qx_9){
                      Cursor_0_nifb6mq6y1 s_0 = eQdup_0_nifb6mq6y1(p_0);
                      inc_0_nifb6mq6y1((&s_0));
                      NifKind_0_nif81dubp1 X60Qx_30 = kind_0_nifb6mq6y1(s_0);
                      if (X60Qx_30 == 8){
                        NU32 X60Qx_31 = intId_0_nifb6mq6y1(s_0);
                        NI64* X60Qx_32 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_31);
                        explicitSize_0 = ((NI32)(*X60Qx_32));}
                      eQdestroy_0_nifb6mq6y1((&s_0));}
                    skip_0_nifb6mq6y1((&p_0));}
                  else {
                    break;}}}
              whileStmtLabel_1: ;
              eQdestroy_0_nifb6mq6y1((&p_0));}
            else {
              SizeAlign_0_siz2wt1it sa_0 = sizeAlignOfType_0_siz2wt1it(d_0, ((NI32)(depth_0 + 1)));
              bodySize_0 = sa_0.size_0;
              bodyAlign_0 = sa_0.align_0;}
            nimStrDestroy(X60Qtmp_1);}
          skip_0_nifb6mq6y1((&d_0));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    if (0 <= explicitSize_0){
      result_1.size_0 = explicitSize_0;
      NI32 X60Qx_0;
      if (0 < bodyAlign_0){
        X60Qx_0 = bodyAlign_0;}
      else {
        X60Qx_0 = explicitSize_0;}
      result_1.align_0 = X60Qx_0;
      eQdestroy_0_nifb6mq6y1((&d_0));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;}
    result_1.size_0 = bodySize_0;
    result_1.align_0 = bodyAlign_0;
    eQdestroy_0_nifb6mq6y1((&d_0));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    eQdestroy_0_nifb6mq6y1((&t_1));
    return result_1;
    eQdestroy_0_nifb6mq6y1((&d_0));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);}
  else {
    NifKind_0_nif81dubp1 X60Qx_33 = kind_0_nifb6mq6y1(t_1);
    if (X60Qx_33 == 11){
      string_0_sysvq0asl X60Qtmp_3 = nodeTag_0_siz2wt1it(t_1);
      NB8 X60Qtc_8 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 0, (NC8)'n');
      if (X60Qtc_8){
        NB8 X60Qtc_9 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 0, (NC8)'c');
        if (X60Qtc_9){
          NB8 X60Qtc_10 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 0, (NC8)'b');
          if (X60Qtc_10){
            if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_buiyylk1h1)}
            )){
              goto X60Qsc_1;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_comaa5xpt1)}
            )){
              goto X60Qsc_5;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 25345u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_1;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
            )){
              goto X60Qsc_2;}}}
        else {
          NB8 X60Qtc_11 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 0, (NC8)'f');
          if (X60Qtc_11){
            NB8 X60Qtc_12 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 0, (NC8)'e');
            if (X60Qtc_12){
              if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_comaa5xpt1)}
              )){
                goto X60Qsc_3;}
              else if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_comaa5xpt1)}
              )){
                goto X60Qsc_4;}}
            else {
              if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 26113u, .more_0 = NIM_NIL}
              )){
                goto X60Qsc_0;}}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 26881u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_0;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 1818849022u, .more_0 = (&strlit_0_I14845240230376595005_buiyylk1h1)}
            )){
              goto X60Qsc_2;}}}}
      else {
        NB8 X60Qtc_13 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 0, (NC8)'p');
        if (X60Qtc_13){
          NB8 X60Qtc_14 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 0, (NC8)'o');
          if (X60Qtc_14){
            if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_comaa5xpt1)}
            )){
              goto X60Qsc_3;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
            )){
              goto X60Qsc_6;}}
          else {
            NB8 X60Qtc_15 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 1, (NC8)'o');
            if (X60Qtc_15){
              if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I6300154543333844069_comaa5xpt1)}
              )){
                goto X60Qsc_2;}}
            else {
              if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
              )){
                goto X60Qsc_2;}
              else if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I5316556160589403975_comaa5xpt1)}
              )){
                goto X60Qsc_2;}}}}
        else {
          NB8 X60Qtc_16 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 0, (NC8)'r');
          if (X60Qtc_16){
            if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_2;}
            else if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
              .bytes_0 = 1970238206u, .more_0 = (&strlit_0_I18029839360381635789_siz2wt1it)}
            )){
              goto X60Qsc_2;}}
          else {
            NB8 X60Qtc_17 = nimStrAtLe_0_sysvq0asl(X60Qtmp_3, 0, (NC8)'s');
            if (X60Qtc_17){
              if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_comaa5xpt1)}
              )){
                goto X60Qsc_6;}}
            else {
              if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 29953u, .more_0 = NIM_NIL}
              )){
                goto X60Qsc_0;}
              else if (equalStrings_0_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
                .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
              )){
                goto X60Qsc_7;}}}}}
      goto X60Qsc_19;
      X60Qsc_0: ;
      Cursor_0_nifb6mq6y1 w_0 = t_1;
      eQwasMoved_0_nifb6mq6y1((&t_1));
      inc_0_nifb6mq6y1((&w_0));
      NifKind_0_nif81dubp1 X60Qx_34 = kind_0_nifb6mq6y1(w_0);
      if (X60Qx_34 == 8){
        NU32 X60Qx_35 = intId_0_nifb6mq6y1(w_0);
        NI64* X60Qx_36 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_35);
        NI32 bytes_0 = ((NI32)(((NI32)(*X60Qx_36)) / 8));
        result_1.size_0 = bytes_0;
        result_1.align_0 = bytes_0;}
      eQdestroy_0_nifb6mq6y1((&w_0));
      nimStrDestroy(X60Qtmp_3);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;
      eQdestroy_0_nifb6mq6y1((&w_0));
      goto X60Qsc_18;
      X60Qsc_1: ;
      result_1.size_0 = 1;
      result_1.align_0 = 1;
      nimStrDestroy(X60Qtmp_3);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;
      goto X60Qsc_18;
      X60Qsc_2: ;
      result_1.size_0 = 8;
      result_1.align_0 = 8;
      nimStrDestroy(X60Qtmp_3);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;
      goto X60Qsc_18;
      X60Qsc_3: ;
      Cursor_0_nifb6mq6y1 e_0 = t_1;
      eQwasMoved_0_nifb6mq6y1((&t_1));
      inc_0_nifb6mq6y1((&e_0));
      NB8 X60Qx_10;
      NifKind_0_nif81dubp1 X60Qx_37 = kind_0_nifb6mq6y1(e_0);
      if (X60Qx_37 == 11){
        NB8 X60Qx_11;
        string_0_sysvq0asl X60Qtmp_4 = nodeTag_0_siz2wt1it(e_0);
        NB8 X60Qx_38 = eqQ_20_sysvq0asl(X60Qtmp_4, (string_0_sysvq0asl){
          .bytes_0 = 26881u, .more_0 = NIM_NIL}
        );
        if (X60Qx_38){
          X60Qx_11 = NIM_TRUE;}
        else {
          string_0_sysvq0asl X60Qtmp_5 = nodeTag_0_siz2wt1it(e_0);
          NB8 X60Qx_39 = eqQ_20_sysvq0asl(X60Qtmp_5, (string_0_sysvq0asl){
            .bytes_0 = 29953u, .more_0 = NIM_NIL}
          );
          X60Qx_11 = X60Qx_39;
          nimStrDestroy(X60Qtmp_5);}
        X60Qx_10 = X60Qx_11;
        nimStrDestroy(X60Qtmp_4);}
      else {
        X60Qx_10 = NIM_FALSE;}
      if (X60Qx_10){
        Cursor_0_nifb6mq6y1 w_1 = e_0;
        eQwasMoved_0_nifb6mq6y1((&e_0));
        inc_0_nifb6mq6y1((&w_1));
        NifKind_0_nif81dubp1 X60Qx_40 = kind_0_nifb6mq6y1(w_1);
        if (X60Qx_40 == 8){
          NU32 X60Qx_41 = intId_0_nifb6mq6y1(w_1);
          NI64* X60Qx_42 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_41);
          NI32 bytes_1 = ((NI32)(((NI32)(*X60Qx_42)) / 8));
          result_1.size_0 = bytes_1;
          result_1.align_0 = bytes_1;}
        eQdestroy_0_nifb6mq6y1((&w_1));}
      eQdestroy_0_nifb6mq6y1((&e_0));
      nimStrDestroy(X60Qtmp_3);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;
      eQdestroy_0_nifb6mq6y1((&e_0));
      goto X60Qsc_18;
      X60Qsc_4: ;
      Cursor_0_nifb6mq6y1 b_0 = t_1;
      eQwasMoved_0_nifb6mq6y1((&t_1));
      inc_0_nifb6mq6y1((&b_0));
      SizeAlign_0_siz2wt1it X60Qx_43 = sizeAlignOfType_0_siz2wt1it(b_0, ((NI32)(depth_0 + 1)));
      result_1 = X60Qx_43;
      eQdestroy_0_nifb6mq6y1((&b_0));
      nimStrDestroy(X60Qtmp_3);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;
      eQdestroy_0_nifb6mq6y1((&b_0));
      goto X60Qsc_18;
      X60Qsc_5: ;
      Cursor_0_nifb6mq6y1 c_0 = t_1;
      eQwasMoved_0_nifb6mq6y1((&t_1));
      inc_0_nifb6mq6y1((&c_0));
      Cursor_0_nifb6mq6y1 elemCur_0 = eQdup_0_nifb6mq6y1(c_0);
      skip_0_nifb6mq6y1((&c_0));
      NI32 lo_0 = 0;
      NI32 hi_0 = -1;
      NB8 X60Qx_12;
      NifKind_0_nif81dubp1 X60Qx_44 = kind_0_nifb6mq6y1(c_0);
      if (X60Qx_44 == 11){
        string_0_sysvq0asl X60Qtmp_6 = nodeTag_0_siz2wt1it(c_0);
        NB8 X60Qx_45 = eqQ_20_sysvq0asl(X60Qtmp_6, (string_0_sysvq0asl){
          .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16393544569146403439_comaa5xpt1)}
        );
        X60Qx_12 = X60Qx_45;
        nimStrDestroy(X60Qtmp_6);}
      else {
        X60Qx_12 = NIM_FALSE;}
      if (X60Qx_12){
        Cursor_0_nifb6mq6y1 r_0 = c_0;
        eQwasMoved_0_nifb6mq6y1((&c_0));
        inc_0_nifb6mq6y1((&r_0));
        skip_0_nifb6mq6y1((&r_0));
        NifKind_0_nif81dubp1 X60Qx_46 = kind_0_nifb6mq6y1(r_0);
        if (X60Qx_46 == 8){
          NU32 X60Qx_47 = intId_0_nifb6mq6y1(r_0);
          NI64* X60Qx_48 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_47);
          lo_0 = ((NI32)(*X60Qx_48));}
        skip_0_nifb6mq6y1((&r_0));
        NifKind_0_nif81dubp1 X60Qx_49 = kind_0_nifb6mq6y1(r_0);
        if (X60Qx_49 == 8){
          NU32 X60Qx_50 = intId_0_nifb6mq6y1(r_0);
          NI64* X60Qx_51 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_50);
          hi_0 = ((NI32)(*X60Qx_51));}
        eQdestroy_0_nifb6mq6y1((&r_0));}
      SizeAlign_0_siz2wt1it sa_1 = sizeAlignOfType_0_siz2wt1it(elemCur_0, ((NI32)(depth_0 + 1)));
      if (sa_1.size_0 < 0){
        eQdestroy_0_nifb6mq6y1((&elemCur_0));
        eQdestroy_0_nifb6mq6y1((&c_0));
        nimStrDestroy(X60Qtmp_3);
        eQdestroy_0_nifb6mq6y1((&t_1));
        return result_1;}
      NI32 count_0 = ((NI32)(((NI32)(hi_0 - lo_0)) + 1));
      if (count_0 <= 0){
        result_1.size_0 = 0;
        result_1.align_0 = sa_1.align_0;
        eQdestroy_0_nifb6mq6y1((&elemCur_0));
        eQdestroy_0_nifb6mq6y1((&c_0));
        nimStrDestroy(X60Qtmp_3);
        eQdestroy_0_nifb6mq6y1((&t_1));
        return result_1;}
      result_1.size_0 = ((NI32)(sa_1.size_0 * count_0));
      result_1.align_0 = sa_1.align_0;
      eQdestroy_0_nifb6mq6y1((&elemCur_0));
      eQdestroy_0_nifb6mq6y1((&c_0));
      nimStrDestroy(X60Qtmp_3);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;
      eQdestroy_0_nifb6mq6y1((&elemCur_0));
      eQdestroy_0_nifb6mq6y1((&c_0));
      goto X60Qsc_18;
      X60Qsc_6: ;
      Cursor_0_nifb6mq6y1 c_1 = eQdup_0_nifb6mq6y1(t_1);
      inc_0_nifb6mq6y1((&c_1));
      NI32 offset_0 = 0;
      NI32 maxAlign_0 = 1;
      string_0_sysvq0asl X60Qtmp_7 = nodeTag_0_siz2wt1it(t_1);
      NB8 X60Qx_52 = eqQ_20_sysvq0asl(X60Qtmp_7, (string_0_sysvq0asl){
        .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
      );
      if (X60Qx_52){
        NifKind_0_nif81dubp1 X60Qx_53 = kind_0_nifb6mq6y1(c_1);
        if (X60Qx_53 == 4){
          SizeAlign_0_siz2wt1it bsa_0 = sizeAlignOfType_0_siz2wt1it(c_1, ((NI32)(depth_0 + 1)));
          if (bsa_0.size_0 < 0){
            nimStrDestroy(X60Qtmp_7);
            eQdestroy_0_nifb6mq6y1((&c_1));
            nimStrDestroy(X60Qtmp_3);
            eQdestroy_0_nifb6mq6y1((&t_1));
            return result_1;}
          offset_0 = bsa_0.size_0;
          if (maxAlign_0 < bsa_0.align_0){
            maxAlign_0 = bsa_0.align_0;}}
        skip_0_nifb6mq6y1((&c_1));}
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_54 = kind_0_nifb6mq6y1(c_1);
          if ((!(X60Qx_54 == 12))){
            NifKind_0_nif81dubp1 X60Qx_55 = kind_0_nifb6mq6y1(c_1);
            if (X60Qx_55 == 11){
              string_0_sysvq0asl tg_0 = nodeTag_0_siz2wt1it(c_1);
              NB8 X60Qx_56 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
              );
              if (X60Qx_56){
                Cursor_0_nifb6mq6y1 f_0 = eQdup_0_nifb6mq6y1(c_1);
                inc_0_nifb6mq6y1((&f_0));
                skip_0_nifb6mq6y1((&f_0));
                skip_0_nifb6mq6y1((&f_0));
                skip_0_nifb6mq6y1((&f_0));
                SizeAlign_0_siz2wt1it fsa_0 = sizeAlignOfType_0_siz2wt1it(f_0, ((NI32)(depth_0 + 1)));
                if (fsa_0.size_0 < 0){
                  eQdestroy_0_nifb6mq6y1((&f_0));
                  nimStrDestroy(tg_0);
                  nimStrDestroy(X60Qtmp_7);
                  eQdestroy_0_nifb6mq6y1((&c_1));
                  nimStrDestroy(X60Qtmp_3);
                  eQdestroy_0_nifb6mq6y1((&t_1));
                  return result_1;}
                NI32 X60Qx_1;
                if (0 < fsa_0.align_0){
                  X60Qx_1 = fsa_0.align_0;}
                else {
                  X60Qx_1 = 1;}
                NI32 a_0 = X60Qx_1;
                if ((!(((NI32)(offset_0 % a_0)) == 0))){
                  offset_0 = ((NI32)(((NI32)(offset_0 + a_0)) - ((NI32)(offset_0 % a_0))));}
                offset_0 = ((NI32)(offset_0 + fsa_0.size_0));
                if (maxAlign_0 < a_0){
                  maxAlign_0 = a_0;}
                eQdestroy_0_nifb6mq6y1((&f_0));}
              else {
                NB8 X60Qx_57 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
                  .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_comaa5xpt1)}
                );
                if (X60Qx_57){
                  Cursor_0_nifb6mq6y1 k_0 = eQdup_0_nifb6mq6y1(c_1);
                  inc_0_nifb6mq6y1((&k_0));
                  NB8 X60Qx_13;
                  NifKind_0_nif81dubp1 X60Qx_58 = kind_0_nifb6mq6y1(k_0);
                  if (X60Qx_58 == 11){
                    string_0_sysvq0asl X60Qtmp_8 = nodeTag_0_siz2wt1it(k_0);
                    NB8 X60Qx_59 = eqQ_20_sysvq0asl(X60Qtmp_8, (string_0_sysvq0asl){
                      .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
                    );
                    X60Qx_13 = X60Qx_59;
                    nimStrDestroy(X60Qtmp_8);}
                  else {
                    X60Qx_13 = NIM_FALSE;}
                  if (X60Qx_13){
                    Cursor_0_nifb6mq6y1 f_1 = eQdup_0_nifb6mq6y1(k_0);
                    inc_0_nifb6mq6y1((&f_1));
                    skip_0_nifb6mq6y1((&f_1));
                    skip_0_nifb6mq6y1((&f_1));
                    skip_0_nifb6mq6y1((&f_1));
                    SizeAlign_0_siz2wt1it dsa_0 = sizeAlignOfType_0_siz2wt1it(f_1, ((NI32)(depth_0 + 1)));
                    if (dsa_0.size_0 < 0){
                      eQdestroy_0_nifb6mq6y1((&f_1));
                      eQdestroy_0_nifb6mq6y1((&k_0));
                      nimStrDestroy(tg_0);
                      nimStrDestroy(X60Qtmp_7);
                      eQdestroy_0_nifb6mq6y1((&c_1));
                      nimStrDestroy(X60Qtmp_3);
                      eQdestroy_0_nifb6mq6y1((&t_1));
                      return result_1;}
                    NI32 X60Qx_2;
                    if (0 < dsa_0.align_0){
                      X60Qx_2 = dsa_0.align_0;}
                    else {
                      X60Qx_2 = 1;}
                    NI32 a_1 = X60Qx_2;
                    if ((!(((NI32)(offset_0 % a_1)) == 0))){
                      offset_0 = ((NI32)(((NI32)(offset_0 + a_1)) - ((NI32)(offset_0 % a_1))));}
                    offset_0 = ((NI32)(offset_0 + dsa_0.size_0));
                    if (maxAlign_0 < a_1){
                      maxAlign_0 = a_1;}
                    eQdestroy_0_nifb6mq6y1((&f_1));}
                  skip_0_nifb6mq6y1((&k_0));
                  NI32 uSize_0 = 0;
                  NI32 uAlign_0 = 1;
                  {
                    while (NIM_TRUE){
                      NifKind_0_nif81dubp1 X60Qx_60 = kind_0_nifb6mq6y1(k_0);
                      if ((!(X60Qx_60 == 12))){
                        NB8 X60Qx_14;
                        NifKind_0_nif81dubp1 X60Qx_61 = kind_0_nifb6mq6y1(k_0);
                        if (X60Qx_61 == 11){
                          NB8 X60Qx_15;
                          string_0_sysvq0asl X60Qtmp_9 = nodeTag_0_siz2wt1it(k_0);
                          NB8 X60Qx_62 = eqQ_20_sysvq0asl(X60Qtmp_9, (string_0_sysvq0asl){
                            .bytes_0 = 6713090u, .more_0 = NIM_NIL}
                          );
                          if (X60Qx_62){
                            X60Qx_15 = NIM_TRUE;}
                          else {
                            string_0_sysvq0asl X60Qtmp_10 = nodeTag_0_siz2wt1it(k_0);
                            NB8 X60Qx_63 = eqQ_20_sysvq0asl(X60Qtmp_10, (string_0_sysvq0asl){
                              .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_comaa5xpt1)}
                            );
                            X60Qx_15 = X60Qx_63;
                            nimStrDestroy(X60Qtmp_10);}
                          X60Qx_14 = X60Qx_15;
                          nimStrDestroy(X60Qtmp_9);}
                        else {
                          X60Qx_14 = NIM_FALSE;}
                        if (X60Qx_14){
                          Cursor_0_nifb6mq6y1 b_1 = eQdup_0_nifb6mq6y1(k_0);
                          inc_0_nifb6mq6y1((&b_1));
                          string_0_sysvq0asl X60Qtmp_11 = nodeTag_0_siz2wt1it(k_0);
                          NB8 X60Qx_64 = eqQ_20_sysvq0asl(X60Qtmp_11, (string_0_sysvq0asl){
                            .bytes_0 = 6713090u, .more_0 = NIM_NIL}
                          );
                          if (X60Qx_64){
                            skip_0_nifb6mq6y1((&b_1));}
                          NB8 X60Qx_16;
                          NifKind_0_nif81dubp1 X60Qx_65 = kind_0_nifb6mq6y1(b_1);
                          if (X60Qx_65 == 11){
                            string_0_sysvq0asl X60Qtmp_12 = nodeTag_0_siz2wt1it(b_1);
                            NB8 X60Qx_66 = eqQ_20_sysvq0asl(X60Qtmp_12, (string_0_sysvq0asl){
                              .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_comaa5xpt1)}
                            );
                            X60Qx_16 = X60Qx_66;
                            nimStrDestroy(X60Qtmp_12);}
                          else {
                            X60Qx_16 = NIM_FALSE;}
                          if (X60Qx_16){
                            SizeAlign_0_siz2wt1it bsa_1 = sizeAlignOfType_0_siz2wt1it(b_1, ((NI32)(depth_0 + 1)));
                            if (bsa_1.size_0 < 0){
                              nimStrDestroy(X60Qtmp_11);
                              eQdestroy_0_nifb6mq6y1((&b_1));
                              eQdestroy_0_nifb6mq6y1((&k_0));
                              nimStrDestroy(tg_0);
                              nimStrDestroy(X60Qtmp_7);
                              eQdestroy_0_nifb6mq6y1((&c_1));
                              nimStrDestroy(X60Qtmp_3);
                              eQdestroy_0_nifb6mq6y1((&t_1));
                              return result_1;}
                            if (uSize_0 < bsa_1.size_0){
                              uSize_0 = bsa_1.size_0;}
                            if (uAlign_0 < bsa_1.align_0){
                              uAlign_0 = bsa_1.align_0;}}
                          nimStrDestroy(X60Qtmp_11);
                          eQdestroy_0_nifb6mq6y1((&b_1));}
                        skip_0_nifb6mq6y1((&k_0));}
                      else {
                        break;}}}
                  whileStmtLabel_3: ;
                  if (0 < uSize_0){
                    if ((!(((NI32)(offset_0 % uAlign_0)) == 0))){
                      offset_0 = ((NI32)(((NI32)(offset_0 + uAlign_0)) - ((NI32)(offset_0 % uAlign_0))));}
                    offset_0 = ((NI32)(offset_0 + uSize_0));
                    if (maxAlign_0 < uAlign_0){
                      maxAlign_0 = uAlign_0;}}
                  eQdestroy_0_nifb6mq6y1((&k_0));}}
              nimStrDestroy(tg_0);}
            skip_0_nifb6mq6y1((&c_1));}
          else {
            break;}}}
      whileStmtLabel_2: ;
      if ((!(((NI32)(offset_0 % maxAlign_0)) == 0))){
        offset_0 = ((NI32)(((NI32)(offset_0 + maxAlign_0)) - ((NI32)(offset_0 % maxAlign_0))));}
      result_1.size_0 = offset_0;
      result_1.align_0 = maxAlign_0;
      nimStrDestroy(X60Qtmp_7);
      eQdestroy_0_nifb6mq6y1((&c_1));
      nimStrDestroy(X60Qtmp_3);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;
      nimStrDestroy(X60Qtmp_7);
      eQdestroy_0_nifb6mq6y1((&c_1));
      goto X60Qsc_18;
      X60Qsc_7: ;
      Cursor_0_nifb6mq6y1 c_2 = t_1;
      eQwasMoved_0_nifb6mq6y1((&t_1));
      inc_0_nifb6mq6y1((&c_2));
      NI32 offset_1 = 0;
      NI32 maxAlign_1 = 1;
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_67 = kind_0_nifb6mq6y1(c_2);
          if ((!(X60Qx_67 == 12))){
            NifKind_0_nif81dubp1 X60Qx_68 = kind_0_nifb6mq6y1(c_2);
            if (X60Qx_68 == 11){
              Cursor_0_nifb6mq6y1 fieldCur_0 = eQdup_0_nifb6mq6y1(c_2);
              string_0_sysvq0asl X60Qtmp_13 = nodeTag_0_siz2wt1it(c_2);
              NB8 X60Qx_69 = eqQ_20_sysvq0asl(X60Qtmp_13, (string_0_sysvq0asl){
                .bytes_0 = 7760642u, .more_0 = NIM_NIL}
              );
              if (X60Qx_69){
                Cursor_0_nifb6mq6y1 k_1 = eQdup_0_nifb6mq6y1(c_2);
                inc_0_nifb6mq6y1((&k_1));
                skip_0_nifb6mq6y1((&k_1));
                eQdestroy_0_nifb6mq6y1((&fieldCur_0));
                fieldCur_0 = k_1;
                eQwasMoved_0_nifb6mq6y1((&k_1));
                eQdestroy_0_nifb6mq6y1((&k_1));}
              SizeAlign_0_siz2wt1it fsa_1 = sizeAlignOfType_0_siz2wt1it(fieldCur_0, ((NI32)(depth_0 + 1)));
              if (fsa_1.size_0 < 0){
                nimStrDestroy(X60Qtmp_13);
                eQdestroy_0_nifb6mq6y1((&fieldCur_0));
                eQdestroy_0_nifb6mq6y1((&c_2));
                nimStrDestroy(X60Qtmp_3);
                eQdestroy_0_nifb6mq6y1((&t_1));
                return result_1;}
              NI32 X60Qx_3;
              if (0 < fsa_1.align_0){
                X60Qx_3 = fsa_1.align_0;}
              else {
                X60Qx_3 = 1;}
              NI32 a_2 = X60Qx_3;
              if ((!(((NI32)(offset_1 % a_2)) == 0))){
                offset_1 = ((NI32)(((NI32)(offset_1 + a_2)) - ((NI32)(offset_1 % a_2))));}
              offset_1 = ((NI32)(offset_1 + fsa_1.size_0));
              if (maxAlign_1 < a_2){
                maxAlign_1 = a_2;}
              nimStrDestroy(X60Qtmp_13);
              eQdestroy_0_nifb6mq6y1((&fieldCur_0));}
            skip_0_nifb6mq6y1((&c_2));}
          else {
            break;}}}
      whileStmtLabel_4: ;
      if ((!(((NI32)(offset_1 % maxAlign_1)) == 0))){
        offset_1 = ((NI32)(((NI32)(offset_1 + maxAlign_1)) - ((NI32)(offset_1 % maxAlign_1))));}
      result_1.size_0 = offset_1;
      result_1.align_0 = maxAlign_1;
      eQdestroy_0_nifb6mq6y1((&c_2));
      nimStrDestroy(X60Qtmp_3);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;
      eQdestroy_0_nifb6mq6y1((&c_2));
      goto X60Qsc_18;
      X60Qsc_19: ;
      nimStrDestroy(X60Qtmp_3);
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;
      X60Qsc_18: ;
      nimStrDestroy(X60Qtmp_3);}
    else {
      eQdestroy_0_nifb6mq6y1((&t_1));
      return result_1;}}
  eQdestroy_0_nifb6mq6y1((&t_1));
  return result_1;
  eQdestroy_0_nifb6mq6y1((&t_1));
  return result_1;}
void X60Qini_0_siz2wt1it(void){
  if (X60QiniGuard_0_siz2wt1it){
    return;}
  X60QiniGuard_0_siz2wt1it = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_prorcx25w1();
  X60Qini_0_symkyk35i1();
  X60Qini_0_modzy18mg1();}
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
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8){
  NU32 result_11;
  PackedToken_0_nifh7u8pu1 X60Qx_26 = load_0_nifb6mq6y1(c_8);
  NU32 X60Qx_27 = symId_0_nifh7u8pu1(X60Qx_26);
  result_11 = X60Qx_27;
  return result_11;}
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_ast8ri79k((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13){
  NB8 result_126;
  NB8 X60Qx_283 = equalStrings_0_sysvq0asl(a_50, b_13);
  result_126 = X60Qx_283;
  return result_126;}
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
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
  dec_1_I0nzoz91_ast8ri79k((&(*c_18).rem_0));}
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
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
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
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NI64* result_10;
  result_10 = (&s_9.data_0[i_6]);
  return result_10;}
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
