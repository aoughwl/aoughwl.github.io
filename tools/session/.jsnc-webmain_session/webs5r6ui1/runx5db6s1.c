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
typedef struct X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1 X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1;
typedef struct HashEntry_0_tabcr240b1 HashEntry_0_tabcr240b1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v X60Qt_0_IArefSX50trX4fvX4fbj0valzr1t4f_arecyyj7v;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
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
typedef struct seq_0_Ixktxxh1_runx5db6s1{
  NI32 len_0;
  X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* data_0;}
seq_0_Ixktxxh1_runx5db6s1;
typedef struct seq_0_Ikxuplm1_der823rwr1{
  NI32 len_0;
  HashEntry_0_tabcr240b1* data_0;}
seq_0_Ikxuplm1_der823rwr1;
typedef struct Table_0_If84ub3_runx5db6s1{
  seq_0_Ixktxxh1_runx5db6s1 data_0;
  seq_0_Ikxuplm1_der823rwr1 hashes_0;}
Table_0_If84ub3_runx5db6s1;
typedef struct seq_0_Ift2sne_aow7lb5cq1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_aow7lb5cq1;
typedef struct RunEmitter_Obj_0_runx5db6s1{
  NB8 enabled_0;
  NB8 ops_0;
  TokenBuf_0_nifb6mq6y1 buf_0;
  Cursor_0_nifb6mq6y1 base_0;
  Table_0_If84ub3_runx5db6s1 cellId_0;
  NI32 nextId_0;
  seq_0_Ift2sne_aow7lb5cq1 iterStack_0;
  NU32 tRunmod_0;
  NU32 tRunstmts_0;
  NU32 tRunlet_0;
  NU32 tAt_0;
  NU32 tRunloop_0;
  NU32 tRuniter_0;
  NU32 tBinds_0;
  NU32 tBind_0;
  NU32 tRunop_0;
  NU32 tRuncall_0;
  NU32 tVnil_0;
  NU32 tVint_0;
  NU32 tVuint_0;
  NU32 tVfloat_0;
  NU32 tVbool_0;
  NU32 tVchar_0;
  NU32 tVstr_0;
  NU32 tVenum_0;
  NU32 tVseq_0;
  NU32 tVarr_0;
  NU32 tVtup_0;
  NU32 tVobj_0;
  NU32 tFld_0;
  NU32 tVref_0;
  NU32 tVptr_0;
  NU32 tVrefback_0;
  NU32 tVset_0;
  NU32 tVproc_0;
  NU32 tVstream_0;}
RunEmitter_Obj_0_runx5db6s1;
typedef struct seq_0_In6doa_arecyyj7v{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_arecyyj7v;
typedef struct seq_0_Iw8xl5b1_arecyyj7v{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_arecyyj7v;
typedef struct seq_0_Ixdx2fh1_aow7lb5cq1{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aow7lb5cq1;
typedef struct BiTable_0_I0ksat5_ast8ri79k{
  seq_0_Ixdx2fh1_aow7lb5cq1 vals_0;
  seq_0_In6doa_arecyyj7v keys_0;}
BiTable_0_I0ksat5_ast8ri79k;
typedef struct X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax{
  NI r_00;
  RunEmitter_Obj_0_runx5db6s1 d_00;}
X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax;
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
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
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
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_arecyyj7v names_0;
  seq_0_Iw8xl5b1_arecyyj7v cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_arecyyj7v elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
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
typedef struct X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1{
  NU32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
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
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
typedef struct HashEntry_0_tabcr240b1{
  NU32 fullhash_0;
  NI32 position_0;}
HashEntry_0_tabcr240b1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
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
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_intzsnzax;
typedef NU8 RegionKind_0_valzr1t4f;

#define rkBytes_0_valzr1t4f ((NU8)0)
#define rkSeq_0_valzr1t4f ((NU8)1)
#define rkArr_0_valzr1t4f ((NU8)2)
#define rkStr_0_valzr1t4f ((NU8)3)
#define rkCell_0_valzr1t4f ((NU8)4)
#define rkObj_0_valzr1t4f ((NU8)5)
#define rkForeign_0_valzr1t4f ((NU8)6)
typedef struct seq_0_Incv1wn_arecyyj7v{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_arecyyj7v;
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
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
void emitValue_1_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_7, Value_0_valzr1t4f* v_1);
static inline seq_0_Ixktxxh1_runx5db6s1 newSeqUninit_0_Iffy1oe_runx5db6s1(NI32 size_3);
NI32 getOrDefault_1_If49zfn1_runx5db6s1(Table_0_If84ub3_runx5db6s1 t_4, NU32 k_2, NI32 fallback_1);
void putQ_0_Id3nrix_runx5db6s1(Table_0_If84ub3_runx5db6s1* t_6, NU32 k_4, NI32 v_5);
static inline NI32 memSizeInBytes_0_Ikrs9ds1_runx5db6s1(NI32 size_9);
NI32 rawGet_0_I2x6853_runx5db6s1(Table_0_If84ub3_runx5db6s1 t_8, NU32 k_6, NU32 kh_1);
static inline X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* getQ_7_Ixxbya51_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1 s_26, NI32 i_16);
void rawPut_0_Iq89pu61_runx5db6s1(Table_0_If84ub3_runx5db6s1* t_9, NU32 k_7, NI32 v_7, NU32 h_3);
static inline NI32 len_3_I4n61wj_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1 s_33);
void fillHashPart_0_Iptna4d_runx5db6s1(Table_0_If84ub3_runx5db6s1* t_11);
static inline void add_0_Idnjvjv_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1* s_37, X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1 elem_4);
static inline NI32 capInBytes_0_Ii4os3u1_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1 s_40);
NB8 resize_0_I50vlpq1_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1* dest_3, NI32 addedElements_3);
void eQdestroyQ_SX54able0X49f84ub3_0_runx5db6s1(Table_0_If84ub3_runx5db6s1 dest_0);
void eQdestroyQ_ArefSX52unX45mitterX4fbj0runx5db6s1_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* dest_0);
void eQwasmovedQ_ArefSX52unX45mitterX4fbj0runx5db6s1_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax** dest_0);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
extern TokenBuf_0_nifb6mq6y1 createTokenBuf_0_nifb6mq6y1(NI32 cap_1);
static inline seq_0_Ikxuplm1_der823rwr1 newSeqUninit_0_Iie69x21_der823rwr1(NI32 size_10);
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10);
extern NU32 registerTag_0_nifh7u8pu1(string_0_sysvq0asl tag_0);
extern LongString_0_sysvq0asl const strlit_0_I18337270522941735704_iop7yt73v;
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
extern void extractBasename_1_symkyk35i1(string_0_sysvq0asl* s_1);
extern void addParLe_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_10, NU32 tag_1, NU32 info_4);
extern NU32 const NoLineInfo_0_linxafkvx1;
extern void addParRi_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_11);
static inline NI32 len_3_I83dzei_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_25);
static inline NI32 len_3_I6y2imo_arecyyj7v(seq_0_In6doa_arecyyj7v s_37);
static inline NU32* getQ_7_I2v00yv1_arecyyj7v(seq_0_In6doa_arecyyj7v s_40, NI32 i_33);
extern void addIdent_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_18, string_0_sysvq0asl s_5, NU32 info_10);
extern string_0_sysvq0asl itoa_0_valzr1t4f(NI64 x_0);
static inline X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** getQ_7_Ii14ync1_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_26, NI32 i_28);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern void addIntLit_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_16, NI64 i_4, NU32 info_8);
extern NI64 asSigned_0_xinat3x34(xint_0_xinat3x34 x_2, NB8* err_0);
extern NU64 asUnsigned_0_xinat3x34(xint_0_xinat3x34 x_3, NB8* err_1);
extern void addUIntLit_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_17, NU64 i_5, NU32 info_9);
extern void addFloatLit_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_20, NF64 f_0, NU32 info_12);
extern LongString_0_sysvq0asl const strlit_0_I8572766038233537570_emi78vuj01;
extern LongString_0_sysvq0asl const strlit_0_I3372626016653902757_emi78vuj01;
extern void addStrLit_0_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_15, string_0_sysvq0asl s_4, NU32 info_7);
extern string_0_sysvq0asl enumDisplay_0_valzr1t4f(Value_0_valzr1t4f* v_16);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
static inline NI32 cursorToPosition_1_nifb6mq6y1(Cursor_0_nifb6mq6y1 base_0, Cursor_0_nifb6mq6y1 c_30);
static inline NU32 info_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_5);
extern LineInfoUnpacked_0_linxafkvx1 unpack_0_linxafkvx1(LineInfoManager_0_linxafkvx1 m_2, NU32 info_0);
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13);
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45);
extern void setLen_0_Ik1cud6_intzsnzax(seq_0_Ift2sne_aow7lb5cq1* s_209, NI32 newLen_27);
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_42);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aow7lb5cq1;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NU32 hash_2_has9tn57v(NU32 u_0);
static inline NI32 high_3_Iyuup9h1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_28);
static inline HashEntry_0_tabcr240b1* getQ_8_Imt2zi01_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_29, NU32 i_17);
static inline NB8 isFilled_0_tabcr240b1(HashEntry_0_tabcr240b1 a_2);
static inline NU32 nextTry_0_has9tn57v(NU32 h_2, NI32 maxHash_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_aow7lb5cq1;
static inline NI32 len_3_Iiefpcc1_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_30);
static inline NB8 mustRehash_0_tabcr240b1(NI32 length_0, NI32 counter_0);
extern void resize_0_tabcr240b1(seq_0_Ikxuplm1_der823rwr1* t_0);
static inline void putQ_8_Ipchg2a_der823rwr1(seq_0_Ikxuplm1_der823rwr1* s_33, NU32 i_19, HashEntry_0_tabcr240b1 elem_7);
extern void eQdestroy_1_I5skmro_der823rwr1(seq_0_Ikxuplm1_der823rwr1 s_53);
extern seq_0_Ikxuplm1_der823rwr1 newSeq_0_Iv3lu2h1_der823rwr1(NI32 size_17);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_Iv9ij5i1_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_94);
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tabcr240b1(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_xinat3x34(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_valzr1t4f(void);
static inline NI32 memSizeInBytes_0_Ilp7p16_der823rwr1(NI32 size_15);
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aow7lb5cq1(seq_0_Ixdx2fh1_aow7lb5cq1 s_38, NI32 i_39);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5);
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68);
extern NB8 resize_0_I8l4tya_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* dest_8, NI32 addedElements_8);
extern LongString_0_sysvq0asl const strlit_0_I6139986957253126309_ast8ri79k;
extern LongString_0_sysvq0asl const strlit_0_I8762445540754965479_ast8ri79k;
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
LongString_0_sysvq0asl const strlit_0_I3189707859059679558_runx5db6s1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "runmod"}
;
LongString_0_sysvq0asl const strlit_0_I11492847565276868139_runx5db6s1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "runstmts"}
;
LongString_0_sysvq0asl const strlit_0_I7286688051143249331_runx5db6s1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "runlet"}
;
LongString_0_sysvq0asl const strlit_0_I10520244650166242299_runx5db6s1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "runloop"}
;
LongString_0_sysvq0asl const strlit_0_I3376361268234296876_runx5db6s1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "runiter"}
;
LongString_0_sysvq0asl const strlit_0_I18229363775251268332_runx5db6s1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "runop"}
;
LongString_0_sysvq0asl const strlit_0_I4268143267205611865_runx5db6s1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "runcall"}
;
LongString_0_sysvq0asl const strlit_0_I14331248138070811147_runx5db6s1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "binds"}
;
LongString_0_sysvq0asl const strlit_0_I306466946165416757_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vnil"}
;
LongString_0_sysvq0asl const strlit_0_I17654207531595880634_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vint"}
;
LongString_0_sysvq0asl const strlit_0_I5145374791852265206_runx5db6s1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vuint"}
;
LongString_0_sysvq0asl const strlit_0_I6262900030818271404_runx5db6s1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vfloat"}
;
LongString_0_sysvq0asl const strlit_0_I10798567198907616953_runx5db6s1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vbool"}
;
LongString_0_sysvq0asl const strlit_0_I1012244424231218563_runx5db6s1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vchar"}
;
LongString_0_sysvq0asl const strlit_0_I5589899029279415897_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vstr"}
;
LongString_0_sysvq0asl const strlit_0_I3951415961399775860_runx5db6s1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "venum"}
;
LongString_0_sysvq0asl const strlit_0_I1363178256387256683_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vseq"}
;
LongString_0_sysvq0asl const strlit_0_I10521105230302092461_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "varr"}
;
LongString_0_sysvq0asl const strlit_0_I12581222733274917198_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vtup"}
;
LongString_0_sysvq0asl const strlit_0_I501217579589176822_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vobj"}
;
LongString_0_sysvq0asl const strlit_0_I16201796961872740700_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vref"}
;
LongString_0_sysvq0asl const strlit_0_I3334722923779719571_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vptr"}
;
LongString_0_sysvq0asl const strlit_0_I4633515737362255821_runx5db6s1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vrefback"}
;
LongString_0_sysvq0asl const strlit_0_I2881507886587413150_runx5db6s1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vset"}
;
LongString_0_sysvq0asl const strlit_0_I1179040973393329931_runx5db6s1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vproc"}
;
LongString_0_sysvq0asl const strlit_0_I5629657802413720096_runx5db6s1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "vstream"}
;
NB8 X60QiniGuard_0_runx5db6s1;
X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* newRunEmitter_0_runx5db6s1(void){
  X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* result_0;
  eQwasmovedQ_ArefSX52unX45mitterX4fbj0runx5db6s1_0_runx5db6s1((&result_0));
  eQdestroyQ_ArefSX52unX45mitterX4fbj0runx5db6s1_0_runx5db6s1(result_0);
  void* X60Qx_10 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax));
  X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* X60Qtmp_0 = ((X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax*)X60Qx_10);
  TokenBuf_0_nifb6mq6y1 X60Qx_11 = createTokenBuf_0_nifb6mq6y1(64);
  seq_0_Ixktxxh1_runx5db6s1 X60Qx_12 = newSeqUninit_0_Iffy1oe_runx5db6s1(0);
  seq_0_Ikxuplm1_der823rwr1 X60Qx_13 = newSeqUninit_0_Iie69x21_der823rwr1(0);
  seq_0_Ift2sne_aow7lb5cq1 X60Qx_14 = newSeqUninit_0_Iggfvwp_aow7lb5cq1(0);
  (*X60Qtmp_0) = (X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax){
    .r_00 = 0, .d_00 = (RunEmitter_Obj_0_runx5db6s1){
      .enabled_0 = NIM_FALSE, .ops_0 = NIM_FALSE, .buf_0 = X60Qx_11, .base_0 = (Cursor_0_nifb6mq6y1){
        .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
      , .cellId_0 = (Table_0_If84ub3_runx5db6s1){
        .data_0 = X60Qx_12, .hashes_0 = X60Qx_13}
      , .nextId_0 = 0, .iterStack_0 = X60Qx_14, .tRunmod_0 = ((NU32)0u), .tRunstmts_0 = ((NU32)0u), .tRunlet_0 = ((NU32)0u), .tAt_0 = ((NU32)0u), .tRunloop_0 = ((NU32)0u), .tRuniter_0 = ((NU32)0u), .tBinds_0 = ((NU32)0u), .tBind_0 = ((NU32)0u), .tRunop_0 = ((NU32)0u), .tRuncall_0 = ((NU32)0u), .tVnil_0 = ((NU32)0u), .tVint_0 = ((NU32)0u), .tVuint_0 = ((NU32)0u), .tVfloat_0 = ((NU32)0u), .tVbool_0 = ((NU32)0u), .tVchar_0 = ((NU32)0u), .tVstr_0 = ((NU32)0u), .tVenum_0 = ((NU32)0u), .tVseq_0 = ((NU32)0u), .tVarr_0 = ((NU32)0u), .tVtup_0 = ((NU32)0u), .tVobj_0 = ((NU32)0u), .tFld_0 = ((NU32)0u), .tVref_0 = ((NU32)0u), .tVptr_0 = ((NU32)0u), .tVrefback_0 = ((NU32)0u), .tVset_0 = ((NU32)0u), .tVproc_0 = ((NU32)0u), .tVstream_0 = ((NU32)0u)}}
  ;
  result_0 = X60Qtmp_0;
  NU32 X60Qx_15 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I3189707859059679558_runx5db6s1)}
  );
  (*result_0).d_00.tRunmod_0 = X60Qx_15;
  NU32 X60Qx_16 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I11492847565276868139_runx5db6s1)}
  );
  (*result_0).d_00.tRunstmts_0 = X60Qx_16;
  NU32 X60Qx_17 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I7286688051143249331_runx5db6s1)}
  );
  (*result_0).d_00.tRunlet_0 = X60Qx_17;
  NU32 X60Qx_18 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 7627010u, .more_0 = NIM_NIL}
  );
  (*result_0).d_00.tAt_0 = X60Qx_18;
  NU32 X60Qx_19 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I10520244650166242299_runx5db6s1)}
  );
  (*result_0).d_00.tRunloop_0 = X60Qx_19;
  NU32 X60Qx_20 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I3376361268234296876_runx5db6s1)}
  );
  (*result_0).d_00.tRuniter_0 = X60Qx_20;
  NU32 X60Qx_21 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I18229363775251268332_runx5db6s1)}
  );
  (*result_0).d_00.tRunop_0 = X60Qx_21;
  NU32 X60Qx_22 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1853190910u, .more_0 = (&strlit_0_I4268143267205611865_runx5db6s1)}
  );
  (*result_0).d_00.tRuncall_0 = X60Qx_22;
  NU32 X60Qx_23 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1852400382u, .more_0 = (&strlit_0_I14331248138070811147_runx5db6s1)}
  );
  (*result_0).d_00.tBinds_0 = X60Qx_23;
  NU32 X60Qx_24 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1852400382u, .more_0 = (&strlit_0_I18337270522941735704_iop7yt73v)}
  );
  (*result_0).d_00.tBind_0 = X60Qx_24;
  NU32 X60Qx_25 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1768847102u, .more_0 = (&strlit_0_I306466946165416757_runx5db6s1)}
  );
  (*result_0).d_00.tVnil_0 = X60Qx_25;
  NU32 X60Qx_26 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1852405502u, .more_0 = (&strlit_0_I17654207531595880634_runx5db6s1)}
  );
  (*result_0).d_00.tVint_0 = X60Qx_26;
  NU32 X60Qx_27 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1769305854u, .more_0 = (&strlit_0_I5145374791852265206_runx5db6s1)}
  );
  (*result_0).d_00.tVuint_0 = X60Qx_27;
  NU32 X60Qx_28 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1818654462u, .more_0 = (&strlit_0_I6262900030818271404_runx5db6s1)}
  );
  (*result_0).d_00.tVfloat_0 = X60Qx_28;
  NU32 X60Qx_29 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1868723966u, .more_0 = (&strlit_0_I10798567198907616953_runx5db6s1)}
  );
  (*result_0).d_00.tVbool_0 = X60Qx_29;
  NU32 X60Qx_30 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1751348990u, .more_0 = (&strlit_0_I1012244424231218563_runx5db6s1)}
  );
  (*result_0).d_00.tVchar_0 = X60Qx_30;
  NU32 X60Qx_31 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1953724158u, .more_0 = (&strlit_0_I5589899029279415897_runx5db6s1)}
  );
  (*result_0).d_00.tVstr_0 = X60Qx_31;
  NU32 X60Qx_32 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1852143358u, .more_0 = (&strlit_0_I3951415961399775860_runx5db6s1)}
  );
  (*result_0).d_00.tVenum_0 = X60Qx_32;
  NU32 X60Qx_33 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1702065918u, .more_0 = (&strlit_0_I1363178256387256683_runx5db6s1)}
  );
  (*result_0).d_00.tVseq_0 = X60Qx_33;
  NU32 X60Qx_34 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1918990078u, .more_0 = (&strlit_0_I10521105230302092461_runx5db6s1)}
  );
  (*result_0).d_00.tVarr_0 = X60Qx_34;
  NU32 X60Qx_35 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1970566910u, .more_0 = (&strlit_0_I12581222733274917198_runx5db6s1)}
  );
  (*result_0).d_00.tVtup_0 = X60Qx_35;
  NU32 X60Qx_36 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1651472126u, .more_0 = (&strlit_0_I501217579589176822_runx5db6s1)}
  );
  (*result_0).d_00.tVobj_0 = X60Qx_36;
  NU32 X60Qx_37 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
  );
  (*result_0).d_00.tFld_0 = X60Qx_37;
  NU32 X60Qx_38 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1702000382u, .more_0 = (&strlit_0_I16201796961872740700_runx5db6s1)}
  );
  (*result_0).d_00.tVref_0 = X60Qx_38;
  NU32 X60Qx_39 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1953527550u, .more_0 = (&strlit_0_I3334722923779719571_runx5db6s1)}
  );
  (*result_0).d_00.tVptr_0 = X60Qx_39;
  NU32 X60Qx_40 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1702000382u, .more_0 = (&strlit_0_I4633515737362255821_runx5db6s1)}
  );
  (*result_0).d_00.tVrefback_0 = X60Qx_40;
  NU32 X60Qx_41 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1702065918u, .more_0 = (&strlit_0_I2881507886587413150_runx5db6s1)}
  );
  (*result_0).d_00.tVset_0 = X60Qx_41;
  NU32 X60Qx_42 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1919973118u, .more_0 = (&strlit_0_I1179040973393329931_runx5db6s1)}
  );
  (*result_0).d_00.tVproc_0 = X60Qx_42;
  NU32 X60Qx_43 = registerTag_0_nifh7u8pu1((string_0_sysvq0asl){
    .bytes_0 = 1953724158u, .more_0 = (&strlit_0_I5629657802413720096_runx5db6s1)}
  );
  (*result_0).d_00.tVstream_0 = X60Qx_43;
  return result_0;}
string_0_sysvq0asl symName_0_runx5db6s1(NU32 s_0){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  nimStrDestroy(result_1);
  string_0_sysvq0asl* X60Qx_44 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_0);
  string_0_sysvq0asl X60Qx_45 = nimStrDup((*X60Qx_44));
  result_1 = X60Qx_45;
  extractBasename_1_symkyk35i1((&result_1));
  return result_1;}
void emitNil_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_3){
  addParLe_0_nifb6mq6y1((&(*em_3).d_00.buf_0), (*em_3).d_00.tVnil_0, NoLineInfo_0_linxafkvx1);
  addParRi_0_nifb6mq6y1((&(*em_3).d_00.buf_0));}
void emitCell_1_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_4, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* c_1){
  if (c_1 == NIM_NIL){
    emitNil_0_runx5db6s1(em_4);}
  else {
    emitValue_1_runx5db6s1(em_4, (&(*c_1).d_00.v_0));}}
void emitFields_1_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_5, X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1* obj_1){
  if (obj_1 == NIM_NIL){
    return;}
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_46 = len_3_I83dzei_arecyyj7v((*obj_1).d_00.cells_0);
      if (i_0 < X60Qx_46){
        addParLe_0_nifb6mq6y1((&(*em_5).d_00.buf_0), (*em_5).d_00.tFld_0, NoLineInfo_0_linxafkvx1);
        NI32 X60Qx_47 = len_3_I6y2imo_arecyyj7v((*obj_1).d_00.names_0);
        if (i_0 < X60Qx_47){
          NU32* X60Qx_48 = getQ_7_I2v00yv1_arecyyj7v((*obj_1).d_00.names_0, i_0);
          string_0_sysvq0asl X60Qtmp_1 = symName_0_runx5db6s1((*X60Qx_48));
          addIdent_0_nifb6mq6y1((&(*em_5).d_00.buf_0), X60Qtmp_1, NoLineInfo_0_linxafkvx1);
          nimStrDestroy(X60Qtmp_1);}
        else {
          string_0_sysvq0asl X60Qtmp_2 = itoa_0_valzr1t4f(((NI64)i_0));
          addIdent_0_nifb6mq6y1((&(*em_5).d_00.buf_0), X60Qtmp_2, NoLineInfo_0_linxafkvx1);
          nimStrDestroy(X60Qtmp_2);}
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_49 = getQ_7_Ii14ync1_arecyyj7v((*obj_1).d_00.cells_0, i_0);
        emitCell_1_runx5db6s1(em_5, (*X60Qx_49));
        addParRi_0_nifb6mq6y1((&(*em_5).d_00.buf_0));
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;}
void emitRef_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_6, X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* cell_0, NU32 refTag_0, NU32 backTag_0){
  if (cell_0 == NIM_NIL){
    emitNil_0_runx5db6s1(em_6);
    return;}
  NU32 key_0 = ((NU32)((void*)cell_0));
  NI32 ex_0 = getOrDefault_1_If49zfn1_runx5db6s1((*em_6).d_00.cellId_0, key_0, -1);
  if (0 <= ex_0){
    addParLe_0_nifb6mq6y1((&(*em_6).d_00.buf_0), backTag_0, NoLineInfo_0_linxafkvx1);
    addIntLit_0_nifb6mq6y1((&(*em_6).d_00.buf_0), ((NI64)ex_0), NoLineInfo_0_linxafkvx1);
    addParRi_0_nifb6mq6y1((&(*em_6).d_00.buf_0));}
  else {
    NI32 id_0 = (*em_6).d_00.nextId_0;
    inc_1_I6wjjge_aow2h993l1((&(*em_6).d_00.nextId_0));
    putQ_0_Id3nrix_runx5db6s1((&(*em_6).d_00.cellId_0), key_0, id_0);
    addParLe_0_nifb6mq6y1((&(*em_6).d_00.buf_0), refTag_0, NoLineInfo_0_linxafkvx1);
    addIntLit_0_nifb6mq6y1((&(*em_6).d_00.buf_0), ((NI64)id_0), NoLineInfo_0_linxafkvx1);
    emitValue_1_runx5db6s1(em_6, (&(*cell_0).d_00.v_0));
    addParRi_0_nifb6mq6y1((&(*em_6).d_00.buf_0));}}
void emitValue_1_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_7, Value_0_valzr1t4f* v_1){
  switch ((*v_1).kind_0){
    case 0:
    {
      emitNil_0_runx5db6s1(em_7);}
    break;
    case 1:
    {
      NB8 err_0 = NIM_FALSE;
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVint_0, NoLineInfo_0_linxafkvx1);
      NI64 X60Qx_50 = asSigned_0_xinat3x34((*v_1).ival_0, (&err_0));
      addIntLit_0_nifb6mq6y1((&(*em_7).d_00.buf_0), X60Qx_50, NoLineInfo_0_linxafkvx1);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 2:
    {
      NB8 err_1 = NIM_FALSE;
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVuint_0, NoLineInfo_0_linxafkvx1);
      NU64 X60Qx_51 = asUnsigned_0_xinat3x34((*v_1).ival_0, (&err_1));
      addUIntLit_0_nifb6mq6y1((&(*em_7).d_00.buf_0), X60Qx_51, NoLineInfo_0_linxafkvx1);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 3:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVfloat_0, NoLineInfo_0_linxafkvx1);
      addFloatLit_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*v_1).fval_0, NoLineInfo_0_linxafkvx1);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 4:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVbool_0, NoLineInfo_0_linxafkvx1);
      string_0_sysvq0asl X60Qx_0;
      nimStrWasMoved((&X60Qx_0));
      if ((*v_1).bval_0){
        nimStrDestroy(X60Qx_0);
        X60Qx_0 = (string_0_sysvq0asl){
          .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I8572766038233537570_emi78vuj01)}
        ;}
      else {
        nimStrDestroy(X60Qx_0);
        X60Qx_0 = (string_0_sysvq0asl){
          .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I3372626016653902757_emi78vuj01)}
        ;}
      addIdent_0_nifb6mq6y1((&(*em_7).d_00.buf_0), X60Qx_0, NoLineInfo_0_linxafkvx1);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));
      nimStrDestroy(X60Qx_0);}
    break;
    case 5:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVchar_0, NoLineInfo_0_linxafkvx1);
      addIntLit_0_nifb6mq6y1((&(*em_7).d_00.buf_0), ((NI64)((NI32)(*v_1).cval_0)), NoLineInfo_0_linxafkvx1);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 6:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVstr_0, NoLineInfo_0_linxafkvx1);
      addStrLit_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*v_1).sval_0, NoLineInfo_0_linxafkvx1);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 7:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVenum_0, NoLineInfo_0_linxafkvx1);
      string_0_sysvq0asl X60Qtmp_3 = enumDisplay_0_valzr1t4f((&(*v_1)));
      addStrLit_0_nifb6mq6y1((&(*em_7).d_00.buf_0), X60Qtmp_3, NoLineInfo_0_linxafkvx1);
      addIntLit_0_nifb6mq6y1((&(*em_7).d_00.buf_0), ((NI64)(*v_1).eord_0), NoLineInfo_0_linxafkvx1);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));
      nimStrDestroy(X60Qtmp_3);}
    break;
    case 8:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVseq_0, NoLineInfo_0_linxafkvx1);
      if ((!((*v_1).sq_0 == NIM_NIL))){
        NI32 i_3 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_52 = len_3_I83dzei_arecyyj7v((*(*v_1).sq_0).d_00.elems_0);
            if (i_3 < X60Qx_52){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_53 = getQ_7_Ii14ync1_arecyyj7v((*(*v_1).sq_0).d_00.elems_0, i_3);
              emitCell_1_runx5db6s1(em_7, (*X60Qx_53));
              inc_1_I6wjjge_aow2h993l1((&i_3));}
            else {
              break;}}}
        whileStmtLabel_0: ;}
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 9:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVarr_0, NoLineInfo_0_linxafkvx1);
      if ((!((*v_1).arr_0 == NIM_NIL))){
        addIntLit_0_nifb6mq6y1((&(*em_7).d_00.buf_0), ((NI64)(*(*v_1).arr_0).d_00.lo_0), NoLineInfo_0_linxafkvx1);
        NI32 i_4 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_54 = len_3_I83dzei_arecyyj7v((*(*v_1).arr_0).d_00.elems_0);
            if (i_4 < X60Qx_54){
              X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_55 = getQ_7_Ii14ync1_arecyyj7v((*(*v_1).arr_0).d_00.elems_0, i_4);
              emitCell_1_runx5db6s1(em_7, (*X60Qx_55));
              inc_1_I6wjjge_aow2h993l1((&i_4));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 10:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVtup_0, NoLineInfo_0_linxafkvx1);
      emitFields_1_runx5db6s1(em_7, (*v_1).obj_0);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 11:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVobj_0, NoLineInfo_0_linxafkvx1);
      if ((!((*v_1).obj_0 == NIM_NIL))){
        string_0_sysvq0asl X60Qtmp_4 = symName_0_runx5db6s1((*(*v_1).obj_0).d_00.typeSym_0);
        addIdent_0_nifb6mq6y1((&(*em_7).d_00.buf_0), X60Qtmp_4, NoLineInfo_0_linxafkvx1);
        nimStrDestroy(X60Qtmp_4);}
      emitFields_1_runx5db6s1(em_7, (*v_1).obj_0);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 12:
    {
      emitRef_0_runx5db6s1(em_7, (*v_1).rf_0, (*em_7).d_00.tVref_0, (*em_7).d_00.tVrefback_0);}
    break;
    case 13:
    {
      emitRef_0_runx5db6s1(em_7, (*v_1).loc_0, (*em_7).d_00.tVptr_0, (*em_7).d_00.tVptr_0);}
    break;
    case 14:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVset_0, NoLineInfo_0_linxafkvx1);
      if ((!((*v_1).st_0 == NIM_NIL))){
        NI32 w_0 = 0;
        {
          while (w_0 < 4){
            NI32 X60Qx_56 = nimIcheckB(w_0, 3);
            addUIntLit_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*(*v_1).st_0).d_00.words_0.a[X60Qx_56], NoLineInfo_0_linxafkvx1);
            inc_1_I6wjjge_aow2h993l1((&w_0));}}
        whileStmtLabel_2: ;}
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));}
    break;
    case 15:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVproc_0, NoLineInfo_0_linxafkvx1);
      string_0_sysvq0asl X60Qtmp_5 = symName_0_runx5db6s1((*v_1).fn_0);
      addIdent_0_nifb6mq6y1((&(*em_7).d_00.buf_0), X60Qtmp_5, NoLineInfo_0_linxafkvx1);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));
      nimStrDestroy(X60Qtmp_5);}
    break;
    case 16:
    {
      addParLe_0_nifb6mq6y1((&(*em_7).d_00.buf_0), (*em_7).d_00.tVstream_0, NoLineInfo_0_linxafkvx1);
      string_0_sysvq0asl X60Qx_1;
      nimStrWasMoved((&X60Qx_1));
      if ((*v_1).toErr_0){
        nimStrDestroy(X60Qx_1);
        X60Qx_1 = (string_0_sysvq0asl){
          .bytes_0 = 1920099587u, .more_0 = NIM_NIL}
        ;}
      else {
        nimStrDestroy(X60Qx_1);
        X60Qx_1 = (string_0_sysvq0asl){
          .bytes_0 = 1953853187u, .more_0 = NIM_NIL}
        ;}
      addIdent_0_nifb6mq6y1((&(*em_7).d_00.buf_0), X60Qx_1, NoLineInfo_0_linxafkvx1);
      addParRi_0_nifb6mq6y1((&(*em_7).d_00.buf_0));
      nimStrDestroy(X60Qx_1);}
    break;
    case 17:
    {
      emitNil_0_runx5db6s1(em_7);}
    break;}}
void emitAt_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_8, Cursor_0_nifb6mq6y1 site_0){
  addParLe_0_nifb6mq6y1((&(*em_8).d_00.buf_0), (*em_8).d_00.tAt_0, NoLineInfo_0_linxafkvx1);
  NI32 X60Qx_57 = cursorToPosition_1_nifb6mq6y1((*em_8).d_00.base_0, site_0);
  addIntLit_0_nifb6mq6y1((&(*em_8).d_00.buf_0), ((NI64)X60Qx_57), NoLineInfo_0_linxafkvx1);
  NU32 X60Qx_58 = info_0_nifb6mq6y1(site_0);
  LineInfoUnpacked_0_linxafkvx1 u_0 = unpack_0_linxafkvx1(pool_0_nifh7u8pu1.man_0, X60Qx_58);
  addIntLit_0_nifb6mq6y1((&(*em_8).d_00.buf_0), ((NI64)u_0.line_0), NoLineInfo_0_linxafkvx1);
  addIntLit_0_nifb6mq6y1((&(*em_8).d_00.buf_0), ((NI64)u_0.col_0), NoLineInfo_0_linxafkvx1);
  addParRi_0_nifb6mq6y1((&(*em_8).d_00.buf_0));}
void beginRun_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_9, Cursor_0_nifb6mq6y1 base_0){
  Cursor_0_nifb6mq6y1* X60Qlhs_6 = (&(*em_9).d_00.base_0);
  Cursor_0_nifb6mq6y1 X60Qlhs_7 = (*em_9).d_00.base_0;
  Cursor_0_nifb6mq6y1 X60Qx_59 = eQdup_0_nifb6mq6y1(base_0);
  (*X60Qlhs_6) = X60Qx_59;
  eQdestroy_0_nifb6mq6y1((&X60Qlhs_7));
  addParLe_0_nifb6mq6y1((&(*em_9).d_00.buf_0), (*em_9).d_00.tRunmod_0, NoLineInfo_0_linxafkvx1);
  addParLe_0_nifb6mq6y1((&(*em_9).d_00.buf_0), (*em_9).d_00.tRunstmts_0, NoLineInfo_0_linxafkvx1);}
void emitRunLet_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_10, NU32 name_0, Value_0_valzr1t4f* v_2, Cursor_0_nifb6mq6y1 site_1){
  addParLe_0_nifb6mq6y1((&(*em_10).d_00.buf_0), (*em_10).d_00.tRunlet_0, NoLineInfo_0_linxafkvx1);
  emitAt_0_runx5db6s1(em_10, site_1);
  string_0_sysvq0asl X60Qtmp_8 = symName_0_runx5db6s1(name_0);
  addIdent_0_nifb6mq6y1((&(*em_10).d_00.buf_0), X60Qtmp_8, NoLineInfo_0_linxafkvx1);
  emitValue_1_runx5db6s1(em_10, (&(*v_2)));
  addParRi_0_nifb6mq6y1((&(*em_10).d_00.buf_0));
  nimStrDestroy(X60Qtmp_8);}
void emitRunOp_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_11, string_0_sysvq0asl op_0, Value_0_valzr1t4f* v_3, Cursor_0_nifb6mq6y1 site_2){
  addParLe_0_nifb6mq6y1((&(*em_11).d_00.buf_0), (*em_11).d_00.tRunop_0, NoLineInfo_0_linxafkvx1);
  emitAt_0_runx5db6s1(em_11, site_2);
  addIdent_0_nifb6mq6y1((&(*em_11).d_00.buf_0), op_0, NoLineInfo_0_linxafkvx1);
  emitValue_1_runx5db6s1(em_11, (&(*v_3)));
  addParRi_0_nifb6mq6y1((&(*em_11).d_00.buf_0));}
void beginCall_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_12, string_0_sysvq0asl name_1, Cursor_0_nifb6mq6y1 site_3){
  addParLe_0_nifb6mq6y1((&(*em_12).d_00.buf_0), (*em_12).d_00.tRuncall_0, NoLineInfo_0_linxafkvx1);
  emitAt_0_runx5db6s1(em_12, site_3);
  addIdent_0_nifb6mq6y1((&(*em_12).d_00.buf_0), name_1, NoLineInfo_0_linxafkvx1);
  addParLe_0_nifb6mq6y1((&(*em_12).d_00.buf_0), (*em_12).d_00.tRunstmts_0, NoLineInfo_0_linxafkvx1);}
void endCall_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_13){
  addParRi_0_nifb6mq6y1((&(*em_13).d_00.buf_0));
  addParRi_0_nifb6mq6y1((&(*em_13).d_00.buf_0));}
void beginLoop_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_14, string_0_sysvq0asl kind_0, Cursor_0_nifb6mq6y1 site_4){
  addParLe_0_nifb6mq6y1((&(*em_14).d_00.buf_0), (*em_14).d_00.tRunloop_0, NoLineInfo_0_linxafkvx1);
  emitAt_0_runx5db6s1(em_14, site_4);
  addIdent_0_nifb6mq6y1((&(*em_14).d_00.buf_0), kind_0, NoLineInfo_0_linxafkvx1);
  add_0_I8kd4i4_aow7lb5cq1((&(*em_14).d_00.iterStack_0), 0);}
void endLoop_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_15){
  addParRi_0_nifb6mq6y1((&(*em_15).d_00.buf_0));
  if (0 < (*em_15).d_00.iterStack_0.len_0){
    NI32 X60Qx_60 = len_3_I0v1j8d_aow7lb5cq1((*em_15).d_00.iterStack_0);
    setLen_0_Ik1cud6_intzsnzax((&(*em_15).d_00.iterStack_0), ((NI32)(X60Qx_60 - 1)));}}
void beginIter_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_16, seq_0_In6doa_arecyyj7v names_0, seq_0_Iw8xl5b1_arecyyj7v cells_0, Cursor_0_nifb6mq6y1 site_5){
  NI32 X60Qx_2;
  if (0 < (*em_16).d_00.iterStack_0.len_0){
    NI32* X60Qx_61 = getQ_7_Ir8kccm_aow7lb5cq1((*em_16).d_00.iterStack_0, ((NI32)((*em_16).d_00.iterStack_0.len_0 - ((NI32)((NI32)1)))));
    X60Qx_2 = (*X60Qx_61);}
  else {
    X60Qx_2 = 0;}
  NI32 idx_0 = X60Qx_2;
  if (0 < (*em_16).d_00.iterStack_0.len_0){
    NI32* X60Qx_62 = getQ_7_Ir8kccm_aow7lb5cq1((*em_16).d_00.iterStack_0, ((NI32)((*em_16).d_00.iterStack_0.len_0 - ((NI32)((NI32)1)))));
    inc_1_I6wjjge_aow2h993l1(X60Qx_62);}
  addParLe_0_nifb6mq6y1((&(*em_16).d_00.buf_0), (*em_16).d_00.tRuniter_0, NoLineInfo_0_linxafkvx1);
  emitAt_0_runx5db6s1(em_16, site_5);
  addIntLit_0_nifb6mq6y1((&(*em_16).d_00.buf_0), ((NI64)idx_0), NoLineInfo_0_linxafkvx1);
  addParLe_0_nifb6mq6y1((&(*em_16).d_00.buf_0), (*em_16).d_00.tBinds_0, NoLineInfo_0_linxafkvx1);
  NI32 i_6 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_63 = len_3_I83dzei_arecyyj7v(cells_0);
      if (i_6 < X60Qx_63){
        addParLe_0_nifb6mq6y1((&(*em_16).d_00.buf_0), (*em_16).d_00.tBind_0, NoLineInfo_0_linxafkvx1);
        NI32 X60Qx_64 = len_3_I6y2imo_arecyyj7v(names_0);
        if (i_6 < X60Qx_64){
          NU32* X60Qx_65 = getQ_7_I2v00yv1_arecyyj7v(names_0, i_6);
          string_0_sysvq0asl X60Qtmp_9 = symName_0_runx5db6s1((*X60Qx_65));
          addIdent_0_nifb6mq6y1((&(*em_16).d_00.buf_0), X60Qtmp_9, NoLineInfo_0_linxafkvx1);
          nimStrDestroy(X60Qtmp_9);}
        else {
          string_0_sysvq0asl X60Qtmp_10 = itoa_0_valzr1t4f(((NI64)i_6));
          addIdent_0_nifb6mq6y1((&(*em_16).d_00.buf_0), X60Qtmp_10, NoLineInfo_0_linxafkvx1);
          nimStrDestroy(X60Qtmp_10);}
        X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** X60Qx_66 = getQ_7_Ii14ync1_arecyyj7v(cells_0, i_6);
        emitCell_1_runx5db6s1(em_16, (*X60Qx_66));
        addParRi_0_nifb6mq6y1((&(*em_16).d_00.buf_0));
        inc_1_I6wjjge_aow2h993l1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  addParRi_0_nifb6mq6y1((&(*em_16).d_00.buf_0));
  addParLe_0_nifb6mq6y1((&(*em_16).d_00.buf_0), (*em_16).d_00.tRunstmts_0, NoLineInfo_0_linxafkvx1);}
void endIter_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_17){
  addParRi_0_nifb6mq6y1((&(*em_17).d_00.buf_0));
  addParRi_0_nifb6mq6y1((&(*em_17).d_00.buf_0));}
void finishRun_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* em_18){
  addParRi_0_nifb6mq6y1((&(*em_18).d_00.buf_0));
  addParRi_0_nifb6mq6y1((&(*em_18).d_00.buf_0));}
static inline seq_0_Ixktxxh1_runx5db6s1 newSeqUninit_0_Iffy1oe_runx5db6s1(NI32 size_3){
  seq_0_Ixktxxh1_runx5db6s1 result_3;
  if (size_3 == 0){
    result_3 = (seq_0_Ixktxxh1_runx5db6s1){
      .len_0 = size_3, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_0 = memSizeInBytes_0_Ikrs9ds1_runx5db6s1(size_3);
    void* X60Qx_68 = alloc_1_sysvq0asl(memSize_0);
    result_3 = (seq_0_Ixktxxh1_runx5db6s1){
      .len_0 = size_3, .data_0 = ((X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1*)X60Qx_68)}
    ;
    if ((!(result_3.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_69 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_3.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_3;}
NI32 getOrDefault_1_If49zfn1_runx5db6s1(Table_0_If84ub3_runx5db6s1 t_4, NU32 k_2, NI32 fallback_1){
  NI32 result_11;
  NU32 X60Qx_77 = hash_2_has9tn57v(k_2);
  NI32 idx_2 = rawGet_0_I2x6853_runx5db6s1(t_4, k_2, X60Qx_77);
  NI32 X60Qx_3;
  if (0 <= idx_2){
    X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* X60Qx_78 = getQ_7_Ixxbya51_runx5db6s1(t_4.data_0, idx_2);
    X60Qx_3 = (*X60Qx_78).fld_1;}
  else {
    X60Qx_3 = fallback_1;}
  result_11 = X60Qx_3;
  return result_11;}
void putQ_0_Id3nrix_runx5db6s1(Table_0_If84ub3_runx5db6s1* t_6, NU32 k_4, NI32 v_5){
  NU32 h_0 = hash_2_has9tn57v(k_4);
  NI32 idx_3 = rawGet_0_I2x6853_runx5db6s1((*t_6), k_4, h_0);
  if (0 <= idx_3){
    X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* X60Qx_79 = getQ_7_Ixxbya51_runx5db6s1((*t_6).data_0, idx_3);
    (*X60Qx_79).fld_1 = v_5;}
  else {
    rawPut_0_Iq89pu61_runx5db6s1(t_6, k_4, v_5, h_0);}}
static inline NI32 memSizeInBytes_0_Ikrs9ds1_runx5db6s1(NI32 size_9){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_14;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_9, sizeof(X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_14 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_14 = ((NI32)2147483647);}
  return result_14;}
NI32 rawGet_0_I2x6853_runx5db6s1(Table_0_If84ub3_runx5db6s1 t_8, NU32 k_6, NU32 kh_1){
  NI32 result_18;
  NI32 X60Qx_84 = len_3_I4n61wj_runx5db6s1(t_8.data_0);
  if (X60Qx_84 <= ((NI32)4)){
    {
      NI32 X60Qlf_0 = 0;
      NI32 X60Qlf_1 = len_3_I4n61wj_runx5db6s1(t_8.data_0);
      NI32 X60Qlf_2 = X60Qlf_0;
      {
        while (X60Qlf_2 < X60Qlf_1){
          {
            X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* X60Qx_85 = getQ_7_Ixxbya51_runx5db6s1(t_8.data_0, X60Qlf_2);
            if ((*X60Qx_85).fld_0 == k_6){
              return X60Qlf_2;}}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_2));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}
  else {
    NI32 X60Qx_86 = high_3_Iyuup9h1_der823rwr1(t_8.hashes_0);
    NU32 h_2 = ((NU32)(kh_1 & ((NU32)X60Qx_86)));
    {
      while (NIM_TRUE){
        HashEntry_0_tabcr240b1* X60Qx_87 = getQ_8_Imt2zi01_der823rwr1(t_8.hashes_0, h_2);
        NB8 X60Qx_88 = isFilled_0_tabcr240b1((*X60Qx_87));
        if (X60Qx_88){
          HashEntry_0_tabcr240b1* X60Qx_89 = getQ_8_Imt2zi01_der823rwr1(t_8.hashes_0, h_2);
          HashEntry_0_tabcr240b1 d_0 = (*X60Qx_89);
          NB8 X60Qx_90;
          if (d_0.fullhash_0 == kh_1){
            X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* X60Qx_91 = getQ_7_Ixxbya51_runx5db6s1(t_8.data_0, ((NI32)(d_0.position_0 - 1)));
            X60Qx_90 = ((*X60Qx_91).fld_0 == k_6);}
          else {
            X60Qx_90 = NIM_FALSE;}
          if (X60Qx_90){
            result_18 = ((NI32)(d_0.position_0 - 1));
            return result_18;}
          NI32 X60Qx_92 = high_3_Iyuup9h1_der823rwr1(t_8.hashes_0);
          NU32 X60Qx_93 = nextTry_0_has9tn57v(h_2, X60Qx_92);
          h_2 = X60Qx_93;}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  result_18 = -1;
  return result_18;}
static inline X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* getQ_7_Ixxbya51_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1 s_26, NI32 i_16){
  NB8 X60Qx_94;
  if (i_16 < s_26.len_0){
    X60Qx_94 = (0 <= i_16);}
  else {
    X60Qx_94 = NIM_FALSE;}
  if ((!X60Qx_94)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* result_19;
  result_19 = (&s_26.data_0[i_16]);
  return result_19;}
void rawPut_0_Iq89pu61_runx5db6s1(Table_0_If84ub3_runx5db6s1* t_9, NU32 k_7, NI32 v_7, NU32 h_3){
  NI32 X60Qx_95 = len_3_I4n61wj_runx5db6s1((*t_9).data_0);
  if (X60Qx_95 == ((NI32)4)){
    fillHashPart_0_Iptna4d_runx5db6s1(t_9);}
  else {
    NI32 X60Qx_96 = len_3_Iiefpcc1_der823rwr1((*t_9).hashes_0);
    NI32 X60Qx_97 = len_3_I4n61wj_runx5db6s1((*t_9).data_0);
    NB8 X60Qx_98 = mustRehash_0_tabcr240b1(X60Qx_96, X60Qx_97);
    if (X60Qx_98){
      resize_0_tabcr240b1((&(*t_9).hashes_0));}}
  add_0_Idnjvjv_runx5db6s1((&(*t_9).data_0), (X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1){
    .fld_0 = k_7, .fld_1 = v_7}
  );
  NI32 X60Qx_99 = high_3_Iyuup9h1_der823rwr1((*t_9).hashes_0);
  NU32 hi_0 = ((NU32)(h_3 & ((NU32)X60Qx_99)));
  {
    while (NIM_TRUE){
      HashEntry_0_tabcr240b1* X60Qx_100 = getQ_8_Imt2zi01_der823rwr1((*t_9).hashes_0, hi_0);
      NB8 X60Qx_101 = isFilled_0_tabcr240b1((*X60Qx_100));
      if (X60Qx_101){
        NI32 X60Qx_102 = high_3_Iyuup9h1_der823rwr1((*t_9).hashes_0);
        NU32 X60Qx_103 = nextTry_0_has9tn57v(hi_0, X60Qx_102);
        hi_0 = X60Qx_103;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_104 = len_3_I4n61wj_runx5db6s1((*t_9).data_0);
  putQ_8_Ipchg2a_der823rwr1((&(*t_9).hashes_0), hi_0, (HashEntry_0_tabcr240b1){
    .fullhash_0 = h_3, .position_0 = X60Qx_104}
  );}
static inline NI32 len_3_I4n61wj_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1 s_33){
  NI32 result_22;
  result_22 = s_33.len_0;
  return result_22;}
void fillHashPart_0_Iptna4d_runx5db6s1(Table_0_If84ub3_runx5db6s1* t_11){
  seq_0_Ikxuplm1_der823rwr1* X60Qlhs_11 = (&(*t_11).hashes_0);
  eQdestroy_1_I5skmro_der823rwr1((*X60Qlhs_11));
  seq_0_Ikxuplm1_der823rwr1 X60Qx_110 = newSeq_0_Iv3lu2h1_der823rwr1(((NI32)(((NI32)4) * 2)));
  (*X60Qlhs_11) = X60Qx_110;
  {
    NI32 X60Qlf_3 = 0;
    NI32 X60Qlf_4 = len_3_I4n61wj_runx5db6s1((*t_11).data_0);
    NI32 X60Qlf_5 = X60Qlf_3;
    {
      while (X60Qlf_5 < X60Qlf_4){
        {
          X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1* X60Qx_111 = getQ_7_Ixxbya51_runx5db6s1((*t_11).data_0, X60Qlf_5);
          NU32 X60Qii_2 = hash_2_has9tn57v((*X60Qx_111).fld_0);
          NI32 X60Qx_112 = high_3_Iyuup9h1_der823rwr1((*t_11).hashes_0);
          NU32 X60Qii_3 = ((NU32)(X60Qii_2 & ((NU32)X60Qx_112)));
          while (NIM_TRUE){
            HashEntry_0_tabcr240b1* X60Qx_113 = getQ_8_Imt2zi01_der823rwr1((*t_11).hashes_0, X60Qii_3);
            NB8 X60Qx_114 = isFilled_0_tabcr240b1((*X60Qx_113));
            if (X60Qx_114){
              NI32 X60Qx_115 = high_3_Iyuup9h1_der823rwr1((*t_11).hashes_0);
              NU32 X60Qx_116 = nextTry_0_has9tn57v(X60Qii_3, X60Qx_115);
              X60Qii_3 = X60Qx_116;}
            else {
              break;}}
          putQ_8_Ipchg2a_der823rwr1((&(*t_11).hashes_0), X60Qii_3, (HashEntry_0_tabcr240b1){
            .fullhash_0 = X60Qii_2, .position_0 = ((NI32)(X60Qlf_5 + 1))}
          );}
        inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline void add_0_Idnjvjv_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1* s_37, X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1 elem_4){
  NI32 L_1 = (*s_37).len_0;
  NI32 X60Qx_117 = capInBytes_0_Ii4os3u1_runx5db6s1((*s_37));
  if (X60Qx_117 < ((NI32)(((NI32)(L_1 * sizeof(X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1))) + sizeof(X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1)))){
    NB8 X60Qx_118 = resize_0_I50vlpq1_runx5db6s1(s_37, 1);
    if ((!X60Qx_118)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_37).len_0));
  (*s_37).data_0[L_1] = elem_4;}
static inline NI32 capInBytes_0_Ii4os3u1_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1 s_40){
  NI32 result_27;
  NI32 X60Qx_5;
  if ((!(s_40.data_0 == NIM_NIL))){
    NI32 X60Qx_120 = allocatedSize_0_sysvq0asl(((void*)((void*)s_40.data_0)));
    X60Qx_5 = X60Qx_120;}
  else {
    X60Qx_5 = 0;}
  result_27 = X60Qx_5;
  return result_27;}
NB8 resize_0_I50vlpq1_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1* dest_3, NI32 addedElements_3){
  NB8 result_28;
  NI32 X60Qx_121 = capInBytes_0_Ii4os3u1_runx5db6s1((*dest_3));
  NI32 oldCap_1 = ((NI32)(X60Qx_121 / sizeof(X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_3);
  NI32 memSize_5 = memSizeInBytes_0_Ikrs9ds1_runx5db6s1(newCap_1);
  void* X60Qx_122 = realloc_1_sysvq0asl(((void*)((void*)(*dest_3).data_0)), memSize_5);
  (*dest_3).data_0 = ((X60Qt_0_IAtupleAuS32ZAiS32_runx5db6s1*)X60Qx_122);
  if ((*dest_3).data_0 == NIM_NIL){
    (*dest_3).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_5);
    result_28 = NIM_FALSE;}
  else {
    result_28 = NIM_TRUE;}
  return result_28;}
void eQdestroy_1_Iiw7ji_runx5db6s1(seq_0_Ixktxxh1_runx5db6s1 s_53){
  if ((!(s_53.data_0 == NIM_NIL))){
    NI32 i_24 = 0;
    {
      while (i_24 < s_53.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_24));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_53.data_0)));}}
void eQdestroyQ_SX52unX45mitterX4fbj0runx5db6s1_0_runx5db6s1(RunEmitter_Obj_0_runx5db6s1* dest_0){
  eQdestroy_1_Iv9ij5i1_aow7lb5cq1((*dest_0).iterStack_0);
  eQdestroyQ_SX54able0X49f84ub3_0_runx5db6s1((*dest_0).cellId_0);
  eQdestroy_0_nifb6mq6y1((&(*dest_0).base_0));
  eQdestroy_1_nifb6mq6y1((&(*dest_0).buf_0));}
void eQdestroyQ_SX54able0X49f84ub3_0_runx5db6s1(Table_0_If84ub3_runx5db6s1 dest_0){
  eQdestroy_1_I5skmro_der823rwr1(dest_0.hashes_0);
  eQdestroy_1_Iiw7ji_runx5db6s1(dest_0.data_0);}
void eQdestroyQ_ArefSX52unX45mitterX4fbj0runx5db6s1_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax* dest_0){
  if (dest_0){
    NB8 X60Qx_166 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_166){
      eQdestroyQ_SX52unX45mitterX4fbj0runx5db6s1_0_runx5db6s1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQwasmovedQ_ArefSX52unX45mitterX4fbj0runx5db6s1_0_runx5db6s1(X60Qt_0_IArefSX52unX45mitterX4fbj0runx5db6s1_intzsnzax** dest_0){
  (*dest_0) = NIM_NIL;}
void X60Qini_0_runx5db6s1(void){
  if (X60QiniGuard_0_runx5db6s1){
    return;}
  X60QiniGuard_0_runx5db6s1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tabcr240b1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_symkyk35i1();
  X60Qini_0_xinat3x34();
  X60Qini_0_linxafkvx1();
  X60Qini_0_valzr1t4f();}
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
static inline seq_0_Ift2sne_aow7lb5cq1 newSeqUninit_0_Iggfvwp_aow7lb5cq1(NI32 size_10){
  seq_0_Ift2sne_aow7lb5cq1 result_85;
  if (size_10 == 0){
    result_85 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_2 = memSizeInBytes_0_Inv7kg3_aow7lb5cq1(size_10);
    void* X60Qx_2290 = alloc_1_sysvq0asl(memSize_2);
    result_85 = (seq_0_Ift2sne_aow7lb5cq1){
      .len_0 = size_10, .data_0 = ((NI32*)X60Qx_2290)}
    ;
    if ((!(result_85.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2291 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_aow7lb5cq1)}
      ;}
    else {
      result_85.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_85;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
static inline void nimStrDestroy(string_0_sysvq0asl s_41){
  if (((NI32)(*((NU8*)(&s_41.bytes_0)))) == ((NI32)255)){
    NB8 X60Qx_221 = arcDec_0_sysvq0asl((&(*s_41.more_0).rc_0));
    if (X60Qx_221){
      dealloc_1_sysvq0asl(((void*)s_41.more_0));}}}
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
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
static inline NI32 len_3_I83dzei_arecyyj7v(seq_0_Iw8xl5b1_arecyyj7v s_25){
  NI32 result_26;
  result_26 = s_25.len_0;
  return result_26;}
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
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
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
static inline NI32 cursorToPosition_1_nifb6mq6y1(Cursor_0_nifb6mq6y1 base_0, Cursor_0_nifb6mq6y1 c_30){
  NI32 result_33;
  NI32 c_46 = ((NI32)c_30.p_0);
  NI32 base_1 = ((NI32)base_0.p_0);
  if ((!(base_1 <= c_46))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  result_33 = ((NI32)(((NI32)(c_46 - base_1)) / sizeof(PackedToken_0_nifh7u8pu1)));
  if ((!(result_33 < 1000000))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  return result_33;}
static inline NU32 info_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_5){
  NU32 result_9;
  PackedToken_0_nifh7u8pu1 X60Qx_23 = load_0_nifb6mq6y1(c_5);
  result_9 = X60Qx_23.info_0;
  return result_9;}
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1){
  Cursor_0_nifb6mq6y1 result_4;
  result_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = src_1.owner_0, .p_0 = src_1.p_0, .rem_0 = src_1.rem_0}
  ;
  if ((!(result_4.owner_0 == NIM_NIL))){
    inc_1_I6wjjge_aow2h993l1((&(*result_4.owner_0).rc_0));}
  return result_4;}
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
static inline void add_0_I8kd4i4_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1* s_47, NI32 elem_13){
  NI32 L_2 = (*s_47).len_0;
  NI32 X60Qx_2292 = capInBytes_0_Iet286n_aow7lb5cq1((*s_47));
  if (X60Qx_2292 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_2293 = resize_0_I8l4tya_aow7lb5cq1(s_47, 1);
    if ((!X60Qx_2293)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_47).len_0));
  (*s_47).data_0[L_2] = elem_13;}
static inline NI32 len_3_I0v1j8d_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_45){
  NI32 result_83;
  result_83 = s_45.len_0;
  return result_83;}
static inline NI32* getQ_7_Ir8kccm_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_46, NI32 i_42){
  NB8 X60Qx_2289;
  if (i_42 < s_46.len_0){
    X60Qx_2289 = (0 <= i_42);}
  else {
    X60Qx_2289 = NIM_FALSE;}
  if ((!X60Qx_2289)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_aow7lb5cq1)}
    );}
  NI32* result_84;
  result_84 = (&s_46.data_0[i_42]);
  return result_84;}
static inline NU32 hash_2_has9tn57v(NU32 u_0){
  NU32 result_3;
  result_3 = u_0;
  return result_3;}
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
static inline void eQdestroy_1_nifb6mq6y1(TokenBuf_0_nifb6mq6y1* dest_3){
  if ((!((*dest_3).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_aow7lb5cq1((&(*(*dest_3).owner_0).rc_0));
    if ((*(*dest_3).owner_0).rc_0 == 0){
      if ((!((*(*dest_3).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*dest_3).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*dest_3).owner_0)));}}
  else {
    if ((!((*dest_3).data_0 == NIM_NIL))){
      dealloc_1_sysvq0asl(((void*)(*dest_3).data_0));}}}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
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
static inline NI32 memSizeInBytes_0_Inv7kg3_aow7lb5cq1(NI32 size_20){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_110;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_20, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_110 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_110 = ((NI32)2147483647);}
  return result_110;}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0){
  NI32 X60Qx_318 = __atomic_add_fetch((&(*memLoc_0)), 1, __ATOMIC_SEQ_CST);}
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
static inline void dec_1_I0nzoz91_aow7lb5cq1(NI32* x_5){
  (*x_5) = ((NI32)((*x_5) - ((NI32)1)));}
static inline NI32 capInBytes_0_Iet286n_aow7lb5cq1(seq_0_Ift2sne_aow7lb5cq1 s_68){
  NI32 result_111;
  NI32 X60Qx_20;
  if ((!(s_68.data_0 == NIM_NIL))){
    NI32 X60Qx_2323 = allocatedSize_0_sysvq0asl(((void*)((void*)s_68.data_0)));
    X60Qx_20 = X60Qx_2323;}
  else {
    X60Qx_20 = 0;}
  result_111 = X60Qx_20;
  return result_111;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
