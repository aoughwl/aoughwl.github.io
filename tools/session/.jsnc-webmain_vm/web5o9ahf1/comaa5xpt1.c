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
typedef struct CursorOwnerObj_0_nifb6mq6y1 CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1 PackedToken_0_nifh7u8pu1;
typedef struct seq_0_Ift2sne_chu5m1rja1 seq_0_Ift2sne_chu5m1rja1;
typedef struct Instr_0_chu5m1rja1 Instr_0_chu5m1rja1;
typedef struct X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1 X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1;
typedef struct FinScope_0_comaa5xpt1 FinScope_0_comaa5xpt1;
typedef struct X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1 X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1;
typedef struct Proc_0_chu5m1rja1 Proc_0_chu5m1rja1;
typedef struct Value_0_valzr1t4f Value_0_valzr1t4f;
typedef struct MagicSpec_0_chu5m1rja1 MagicSpec_0_chu5m1rja1;
typedef struct ConvSpec_0_chu5m1rja1 ConvSpec_0_chu5m1rja1;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct GatedCall_0_chu5m1rja1 GatedCall_0_chu5m1rja1;
typedef struct ObjInfo_0_chu5m1rja1 ObjInfo_0_chu5m1rja1;
typedef struct ObjSpec_0_chu5m1rja1 ObjSpec_0_chu5m1rja1;
typedef struct GlobalSeed_0_chu5m1rja1 GlobalSeed_0_chu5m1rja1;
typedef struct Cursor_0_nifb6mq6y1 Cursor_0_nifb6mq6y1;
typedef struct MethodSite_0_chu5m1rja1 MethodSite_0_chu5m1rja1;
typedef struct MethodEntry_0_chu5m1rja1 MethodEntry_0_chu5m1rja1;
typedef struct X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1 X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1;
typedef struct TokenBuf_0_nifb6mq6y1 TokenBuf_0_nifb6mq6y1;
typedef struct MethodIndexEntry_0_sempjk6bn1 MethodIndexEntry_0_sempjk6bn1;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct LineInfoUnpacked_0_linxafkvx1 LineInfoUnpacked_0_linxafkvx1;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1 X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689 X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1 X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct seq_0_In6doa_ast8ri79k{
  NI32 len_0;
  NU32* data_0;}
seq_0_In6doa_ast8ri79k;
typedef struct seq_0_Ift2sne_chu5m1rja1{
  NI32 len_0;
  NI32* data_0;}
seq_0_Ift2sne_chu5m1rja1;
typedef struct SymMap_0_comaa5xpt1{
  seq_0_In6doa_ast8ri79k keys_0;
  seq_0_Ift2sne_chu5m1rja1 vals_0;}
SymMap_0_comaa5xpt1;
typedef struct Loop_Obj_0_comaa5xpt1{
  NI32 contTarget_0;
  seq_0_Ift2sne_chu5m1rja1 breaks_0;
  seq_0_Ift2sne_chu5m1rja1 continues_0;
  NU32 label_0;}
Loop_Obj_0_comaa5xpt1;
typedef struct Cursor_0_nifb6mq6y1{
  CursorOwnerObj_0_nifb6mq6y1* owner_0;
  PackedToken_0_nifh7u8pu1* p_0;
  NI32 rem_0;}
Cursor_0_nifb6mq6y1;
typedef struct FinScope_0_comaa5xpt1{
  Cursor_0_nifb6mq6y1 finCur_0;
  NI32 loopLen_0;
  NI32 handlerCount_0;}
FinScope_0_comaa5xpt1;
typedef struct seq_0_Ik7wkpe_comaa5xpt1{
  NI32 len_0;
  seq_0_Ift2sne_chu5m1rja1* data_0;}
seq_0_Ik7wkpe_comaa5xpt1;
typedef struct YieldFrame_Obj_0_comaa5xpt1{
  seq_0_Ift2sne_chu5m1rja1 loopSlots_0;
  seq_0_Ik7wkpe_comaa5xpt1 unpackPlan_0;
  NI32 tmpSlot_0;
  NI32 nestTmpSlot_0;
  Cursor_0_nifb6mq6y1 bodyCur_0;
  NI32 consumerIdx_0;}
YieldFrame_Obj_0_comaa5xpt1;
typedef struct seq_0_Izok7jt1_chu5m1rja1{
  NI32 len_0;
  Instr_0_chu5m1rja1* data_0;}
seq_0_Izok7jt1_chu5m1rja1;
typedef struct seq_0_Iscf6bn_comaa5xpt1{
  NI32 len_0;
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** data_0;}
seq_0_Iscf6bn_comaa5xpt1;
typedef struct seq_0_I806bg1_comaa5xpt1{
  NI32 len_0;
  FinScope_0_comaa5xpt1* data_0;}
seq_0_I806bg1_comaa5xpt1;
typedef struct seq_0_Igm8woo1_comaa5xpt1{
  NI32 len_0;
  X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1** data_0;}
seq_0_Igm8woo1_comaa5xpt1;
typedef struct ProcCtx_Obj_0_comaa5xpt1{
  seq_0_Izok7jt1_chu5m1rja1 code_0;
  seq_0_Ift2sne_chu5m1rja1 codeLines_0;
  NI32 curLine_0;
  SymMap_0_comaa5xpt1 smap_0;
  NI32 numLocals_0;
  NI32 numParams_0;
  NI32 resultSlot_0;
  NB8 isTop_0;
  NB8 isNested_0;
  NB8 isPassive_0;
  seq_0_Iscf6bn_comaa5xpt1 loops_0;
  seq_0_I806bg1_comaa5xpt1 finallys_0;
  seq_0_Igm8woo1_comaa5xpt1 yields_0;
  NU32 guardSym_0;}
ProcCtx_Obj_0_comaa5xpt1;
typedef struct seq_0_Inaua171_chu5m1rja1{
  NI32 len_0;
  Proc_0_chu5m1rja1* data_0;}
seq_0_Inaua171_chu5m1rja1;
typedef struct seq_0_I50urnw_chu5m1rja1{
  NI32 len_0;
  Value_0_valzr1t4f* data_0;}
seq_0_I50urnw_chu5m1rja1;
typedef struct seq_0_Ie9rikd_chu5m1rja1{
  NI32 len_0;
  MagicSpec_0_chu5m1rja1* data_0;}
seq_0_Ie9rikd_chu5m1rja1;
typedef struct seq_0_Iknt7a3_chu5m1rja1{
  NI32 len_0;
  ConvSpec_0_chu5m1rja1* data_0;}
seq_0_Iknt7a3_chu5m1rja1;
typedef struct seq_0_Ixdx2fh1_ast8ri79k{
  NI32 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_ast8ri79k;
typedef struct seq_0_Id5h4uf_chu5m1rja1{
  NI32 len_0;
  GatedCall_0_chu5m1rja1* data_0;}
seq_0_Id5h4uf_chu5m1rja1;
typedef struct seq_0_I2neof81_chu5m1rja1{
  NI32 len_0;
  ObjInfo_0_chu5m1rja1* data_0;}
seq_0_I2neof81_chu5m1rja1;
typedef struct seq_0_Isww99s_chu5m1rja1{
  NI32 len_0;
  ObjSpec_0_chu5m1rja1* data_0;}
seq_0_Isww99s_chu5m1rja1;
typedef struct seq_0_Iioxqbu_chu5m1rja1{
  NI32 len_0;
  GlobalSeed_0_chu5m1rja1* data_0;}
seq_0_Iioxqbu_chu5m1rja1;
typedef struct seq_0_Isyzizu1_comaa5xpt1{
  NI32 len_0;
  Cursor_0_nifb6mq6y1* data_0;}
seq_0_Isyzizu1_comaa5xpt1;
typedef struct seq_0_Ir067xu1_chu5m1rja1{
  NI32 len_0;
  MethodSite_0_chu5m1rja1* data_0;}
seq_0_Ir067xu1_chu5m1rja1;
typedef struct seq_0_I88k8j01_chu5m1rja1{
  NI32 len_0;
  MethodEntry_0_chu5m1rja1* data_0;}
seq_0_I88k8j01_chu5m1rja1;
typedef struct seq_0_Ik8dusv_comaa5xpt1{
  NI32 len_0;
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1** data_0;}
seq_0_Ik8dusv_comaa5xpt1;
typedef struct Compiler_Obj_0_comaa5xpt1{
  seq_0_Inaua171_chu5m1rja1 procs_0;
  seq_0_I50urnw_chu5m1rja1 consts_0;
  seq_0_Ie9rikd_chu5m1rja1 magics_0;
  seq_0_Iknt7a3_chu5m1rja1 convs_0;
  seq_0_Ixdx2fh1_ast8ri79k natives_0;
  seq_0_In6doa_ast8ri79k enumWraps_0;
  seq_0_Id5h4uf_chu5m1rja1 gatedCalls_0;
  seq_0_I2neof81_chu5m1rja1 objInfos_0;
  seq_0_In6doa_ast8ri79k fieldSyms_0;
  seq_0_Isww99s_chu5m1rja1 objSpecs_0;
  seq_0_In6doa_ast8ri79k typeSyms_0;
  SymMap_0_comaa5xpt1 gmap_0;
  NI32 numGlobals_0;
  seq_0_Iioxqbu_chu5m1rja1 globalSeeds_0;
  SymMap_0_comaa5xpt1 pmap_0;
  seq_0_In6doa_ast8ri79k procDefSyms_0;
  seq_0_Isyzizu1_comaa5xpt1 procDefCursors_0;
  seq_0_Ir067xu1_chu5m1rja1 methodSites_0;
  seq_0_I88k8j01_chu5m1rja1 methodTable_0;
  seq_0_In6doa_ast8ri79k enumSyms_0;
  seq_0_Ift2sne_chu5m1rja1 enumOrds_0;
  seq_0_Ixdx2fh1_ast8ri79k enumNames_0;
  SymMap_0_comaa5xpt1 nestedSyms_0;
  seq_0_In6doa_ast8ri79k envSyms_0;
  NB8 usesScheduler_0;
  seq_0_Ik8dusv_comaa5xpt1 ctxStack_0;
  seq_0_In6doa_ast8ri79k importGlobalSyms_0;
  seq_0_Ift2sne_chu5m1rja1 importGlobalSlots_0;
  seq_0_Ift2sne_chu5m1rja1 importGlobalInits_0;}
Compiler_Obj_0_comaa5xpt1;
typedef struct seq_0_I8t027x1_comaa5xpt1{
  NI32 len_0;
  TokenBuf_0_nifb6mq6y1* data_0;}
seq_0_I8t027x1_comaa5xpt1;
typedef struct openArray_0_Imqex5f1_comaa5xpt1{
  Cursor_0_nifb6mq6y1* a_0;
  NI32 len_0;}
openArray_0_Imqex5f1_comaa5xpt1;
typedef struct openArray_0_Inqs7yx_comaa5xpt1{
  NI32* a_0;
  NI32 len_0;}
openArray_0_Inqs7yx_comaa5xpt1;
typedef struct HSlice_0_I8tnmvh1_comaa5xpt1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_I8tnmvh1_comaa5xpt1;
typedef struct openArray_0_I6xd9vz_comaa5xpt1{
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** a_0;
  NI32 len_0;}
openArray_0_I6xd9vz_comaa5xpt1;
typedef struct openArray_0_In1h8lr1_comaa5xpt1{
  MethodIndexEntry_0_sempjk6bn1* a_0;
  NI32 len_0;}
openArray_0_In1h8lr1_comaa5xpt1;
typedef struct openArray_0_Iz8j0ra_comaa5xpt1{
  ObjInfo_0_chu5m1rja1* a_0;
  NI32 len_0;}
openArray_0_Iz8j0ra_comaa5xpt1;
typedef struct openArray_0_I94odo91_comaa5xpt1{
  ObjSpec_0_chu5m1rja1* a_0;
  NI32 len_0;}
openArray_0_I94odo91_comaa5xpt1;
typedef struct openArray_0_Ir53qdx_comaa5xpt1{
  NU32* a_0;
  NI32 len_0;}
openArray_0_Ir53qdx_comaa5xpt1;
typedef struct HSlice_0_Inzqy8d_comaa5xpt1{
  NI32 a_0;
  NI32 b_0;}
HSlice_0_Inzqy8d_comaa5xpt1;
typedef struct openArray_0_Ig73pnk_comaa5xpt1{
  string_0_sysvq0asl* a_0;
  NI32 len_0;}
openArray_0_Ig73pnk_comaa5xpt1;
typedef struct seq_0_Iaza5ca1_buiyylk1h1{
  NI32 len_0;
  NU32* data_0;}
seq_0_Iaza5ca1_buiyylk1h1;
typedef struct BiTable_0_Icvz6lt_buiyylk1h1{
  seq_0_Ixdx2fh1_ast8ri79k vals_0;
  seq_0_Iaza5ca1_buiyylk1h1 keys_0;}
BiTable_0_Icvz6lt_buiyylk1h1;
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
typedef struct seq_0_Idl3iy1_comaa5xpt1{
  NI32 len_0;
  MethodIndexEntry_0_sempjk6bn1* data_0;}
seq_0_Idl3iy1_comaa5xpt1;
typedef struct X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1{
  NI r_00;
  Loop_Obj_0_comaa5xpt1 d_00;}
X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1;
typedef struct X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1{
  NI r_00;
  YieldFrame_Obj_0_comaa5xpt1 d_00;}
X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1;
typedef struct X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1{
  NI r_00;
  ProcCtx_Obj_0_comaa5xpt1 d_00;}
X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1;
typedef struct X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1{
  NI r_00;
  Compiler_Obj_0_comaa5xpt1 d_00;}
X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1;
typedef struct X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1{
  NI32 fld_0;
  NI32 fld_1;}
X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1;
typedef struct seq_0_Iw8xl5b1_flaksyopx1{
  NI32 len_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1** data_0;}
seq_0_Iw8xl5b1_flaksyopx1;
typedef struct ClosureEnv_Obj_0_valzr1t4f{
  seq_0_In6doa_ast8ri79k vars_0;
  seq_0_Iw8xl5b1_flaksyopx1 cells_0;
  X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* coro_0;
  X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1* dest_0;}
ClosureEnv_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1{
  NI r_00;
  ClosureEnv_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1;
typedef struct string_0_sysvq0asl{
  NU32 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1{
  NB8 fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1;
typedef NU8 TCode_0_valzr1t4f;

#define tcU_0_valzr1t4f ((NU8)0)
#define tcI_0_valzr1t4f ((NU8)1)
#define tcF_0_valzr1t4f ((NU8)2)
#define tcRaw_0_valzr1t4f ((NU8)3)
#define tcBool_0_valzr1t4f ((NU8)4)
#define tcChar_0_valzr1t4f ((NU8)5)
#define tcNone_0_valzr1t4f ((NU8)6)
#define tcObj_0_valzr1t4f ((NU8)7)
typedef struct X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1{
  NI32 fld_0;
  TCode_0_valzr1t4f fld_1;
  NB8 fld_2;}
X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1;
typedef struct X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAboolZSX53ymX49d0nifh7u8pu1_comaa5xpt1{
  NI32 fld_0;
  TCode_0_valzr1t4f fld_1;
  NB8 fld_2;
  NU32 fld_3;}
X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAboolZSX53ymX49d0nifh7u8pu1_comaa5xpt1;
typedef struct X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1{
  NB8 fld_0;
  Cursor_0_nifb6mq6y1 fld_1;}
X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1;
typedef struct X60Qt_0_IAarrayAiS32ZS1_comaa5xpt1{
  NI32 a[1];}
X60Qt_0_IAarrayAiS32ZS1_comaa5xpt1;
typedef struct X60Qt_0_IAarraySX43ursor0nifb6mq6y1S0_comaa5xpt1{
  Cursor_0_nifb6mq6y1 a[0];}
X60Qt_0_IAarraySX43ursor0nifb6mq6y1S0_comaa5xpt1;
typedef struct LongString_0_sysvq0asl{
  NI32 fullLen_0;
  NI32 rc_0;
  NI32 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef NU8 NimonySym_0_nimry5ra91;

#define NoSym_0_nimry5ra91 ((NU8)0)
#define GvarY_0_nimry5ra91 ((NU8)54)
#define TvarY_0_nimry5ra91 ((NU8)55)
#define VarY_0_nimry5ra91 ((NU8)56)
#define ParamY_0_nimry5ra91 ((NU8)57)
#define ConstY_0_nimry5ra91 ((NU8)58)
#define ResultY_0_nimry5ra91 ((NU8)59)
#define GletY_0_nimry5ra91 ((NU8)60)
#define TletY_0_nimry5ra91 ((NU8)61)
#define LetY_0_nimry5ra91 ((NU8)62)
#define CursorY_0_nimry5ra91 ((NU8)63)
#define PatternvarY_0_nimry5ra91 ((NU8)64)
#define TypevarY_0_nimry5ra91 ((NU8)65)
#define StaticTypevarY_0_nimry5ra91 ((NU8)66)
#define EfldY_0_nimry5ra91 ((NU8)67)
#define FldY_0_nimry5ra91 ((NU8)68)
#define GfldY_0_nimry5ra91 ((NU8)69)
#define ProcY_0_nimry5ra91 ((NU8)70)
#define FuncY_0_nimry5ra91 ((NU8)71)
#define IteratorY_0_nimry5ra91 ((NU8)72)
#define ConverterY_0_nimry5ra91 ((NU8)73)
#define MethodY_0_nimry5ra91 ((NU8)74)
#define MacroY_0_nimry5ra91 ((NU8)75)
#define TemplateY_0_nimry5ra91 ((NU8)76)
#define TypeY_0_nimry5ra91 ((NU8)77)
#define BlockY_0_nimry5ra91 ((NU8)78)
#define ModuleY_0_nimry5ra91 ((NU8)79)
#define CchoiceY_0_nimry5ra91 ((NU8)80)
typedef struct Routine_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 pattern_0;
  Cursor_0_nifb6mq6y1 typevars_0;
  Cursor_0_nifb6mq6y1 params_0;
  Cursor_0_nifb6mq6y1 retType_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 effects_0;
  Cursor_0_nifb6mq6y1 body_0;}
Routine_0_decqocs071;
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
typedef struct LineInfoUnpacked_0_linxafkvx1{
  NU32 file_0;
  NI32 line_0;
  NI32 col_0;
  NU32 comment_0;}
LineInfoUnpacked_0_linxafkvx1;
typedef NU8 OpCode_0_chu5m1rja1;

#define opPushConst_0_chu5m1rja1 ((NU8)0)
#define opPushNil_0_chu5m1rja1 ((NU8)1)
#define opPushEmptySeq_0_chu5m1rja1 ((NU8)2)
#define opPushEmptyStr_0_chu5m1rja1 ((NU8)3)
#define opPop_0_chu5m1rja1 ((NU8)4)
#define opLoadLocal_0_chu5m1rja1 ((NU8)5)
#define opStoreLocal_0_chu5m1rja1 ((NU8)6)
#define opLoadLocalAddr_0_chu5m1rja1 ((NU8)7)
#define opLoadGlobal_0_chu5m1rja1 ((NU8)8)
#define opStoreGlobal_0_chu5m1rja1 ((NU8)9)
#define opLoadGlobalAddr_0_chu5m1rja1 ((NU8)10)
#define opLoadGlobalInit_0_chu5m1rja1 ((NU8)11)
#define opLoadGlobalAddrInit_0_chu5m1rja1 ((NU8)12)
#define opDeref_0_chu5m1rja1 ((NU8)13)
#define opStoreDeref_0_chu5m1rja1 ((NU8)14)
#define opWasMoved_0_chu5m1rja1 ((NU8)15)
#define opKeepOvfBegin_0_chu5m1rja1 ((NU8)16)
#define opKeepOvfEnd_0_chu5m1rja1 ((NU8)17)
#define opOverflowFlag_0_chu5m1rja1 ((NU8)18)
#define opBinMagic_0_chu5m1rja1 ((NU8)19)
#define opUnMagic_0_chu5m1rja1 ((NU8)20)
#define opConv_0_chu5m1rja1 ((NU8)21)
#define opRewidth_0_chu5m1rja1 ((NU8)22)
#define opEnumWrap_0_chu5m1rja1 ((NU8)23)
#define opJump_0_chu5m1rja1 ((NU8)24)
#define opJumpIfFalse_0_chu5m1rja1 ((NU8)25)
#define opCall_0_chu5m1rja1 ((NU8)26)
#define opCallIndirect_0_chu5m1rja1 ((NU8)27)
#define opCallMethod_0_chu5m1rja1 ((NU8)28)
#define opCallNested_0_chu5m1rja1 ((NU8)29)
#define opLoadEnv_0_chu5m1rja1 ((NU8)30)
#define opStoreEnv_0_chu5m1rja1 ((NU8)31)
#define opLoadEnvAddr_0_chu5m1rja1 ((NU8)32)
#define opCaptureEnv_0_chu5m1rja1 ((NU8)33)
#define opCallNative_0_chu5m1rja1 ((NU8)34)
#define opCallNativeGated_0_chu5m1rja1 ((NU8)35)
#define opRet_0_chu5m1rja1 ((NU8)36)
#define opMakeObj_0_chu5m1rja1 ((NU8)37)
#define opMakeRef_0_chu5m1rja1 ((NU8)38)
#define opNewRefInit_0_chu5m1rja1 ((NU8)39)
#define opMakeTuple_0_chu5m1rja1 ((NU8)40)
#define opLoadField_0_chu5m1rja1 ((NU8)41)
#define opLoadFieldAddr_0_chu5m1rja1 ((NU8)42)
#define opTupIndex_0_chu5m1rja1 ((NU8)43)
#define opTupIndexAddr_0_chu5m1rja1 ((NU8)44)
#define opMakeArray_0_chu5m1rja1 ((NU8)45)
#define opMakeSeq_0_chu5m1rja1 ((NU8)46)
#define opFillSeqDefaults_0_chu5m1rja1 ((NU8)47)
#define opIndexGet_0_chu5m1rja1 ((NU8)48)
#define opIndexAddr_0_chu5m1rja1 ((NU8)49)
#define opIndexSet_0_chu5m1rja1 ((NU8)50)
#define opCopyAssign_0_chu5m1rja1 ((NU8)51)
#define opNewSet_0_chu5m1rja1 ((NU8)52)
#define opSetInclTos_0_chu5m1rja1 ((NU8)53)
#define opSetInclRangeTos_0_chu5m1rja1 ((NU8)54)
#define opSetIncl_0_chu5m1rja1 ((NU8)55)
#define opSetExcl_0_chu5m1rja1 ((NU8)56)
#define opInSet_0_chu5m1rja1 ((NU8)57)
#define opCard_0_chu5m1rja1 ((NU8)58)
#define opSetCombine_0_chu5m1rja1 ((NU8)59)
#define opSetCmp_0_chu5m1rja1 ((NU8)60)
#define opNewObj_0_chu5m1rja1 ((NU8)61)
#define opGetField_0_chu5m1rja1 ((NU8)62)
#define opInstanceOf_0_chu5m1rja1 ((NU8)63)
#define opSetupTry_0_chu5m1rja1 ((NU8)64)
#define opPopTry_0_chu5m1rja1 ((NU8)65)
#define opRaise_0_chu5m1rja1 ((NU8)66)
#define opReRaise_0_chu5m1rja1 ((NU8)67)
#define opEndFinally_0_chu5m1rja1 ((NU8)68)
#define opLoadExc_0_chu5m1rja1 ((NU8)69)
#define opFinMark_0_chu5m1rja1 ((NU8)70)
#define opFinSkip_0_chu5m1rja1 ((NU8)71)
#define opYield_0_chu5m1rja1 ((NU8)72)
#define opCoroInit_0_chu5m1rja1 ((NU8)73)
#define opCoroResume_0_chu5m1rja1 ((NU8)74)
#define opSetScheduler_0_chu5m1rja1 ((NU8)75)
#define opDelay0_0_chu5m1rja1 ((NU8)76)
#define opDelay_0_chu5m1rja1 ((NU8)77)
#define opSuspend_0_chu5m1rja1 ((NU8)78)
#define opPassiveCall_0_chu5m1rja1 ((NU8)79)
#define opDrivePassive_0_chu5m1rja1 ((NU8)80)
#define opPassiveMethodCall_0_chu5m1rja1 ((NU8)81)
#define opDrivePassiveMethod_0_chu5m1rja1 ((NU8)82)
typedef struct Instr_0_chu5m1rja1{
  OpCode_0_chu5m1rja1 op_0;
  NI32 a_0;
  NI32 b_0;}
Instr_0_chu5m1rja1;
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
      NU32 ekind_0;
      string_0_sysvq0asl ename_0;}
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
      X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1* arrOwn_0;
      X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1* seqOwn_0;
      NI32 base_0;
      X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* region_0;
      NI32 foff_0;
      NI16 elemBits_0;
      TCode_0_valzr1t4f ecode_0;
      NU32 etype_0;}
    ;
    struct {
      X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689* st_0;}
    ;
    struct {
      NU32 fn_0;
      NI32 pidx_0;
      X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1* env_0;
      NI32 resume_0;}
    ;
    struct {
      NB8 toErr_0;}
    ;
    struct {
      X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f* coro_0;}
    ;}
  ;}
Value_0_valzr1t4f;
typedef NU8 LoadStatus_0_prorcx25w1;

#define LacksModuleName_0_prorcx25w1 ((NU8)0)
#define LacksOffset_0_prorcx25w1 ((NU8)1)
#define LacksPosition_0_prorcx25w1 ((NU8)2)
#define LacksNothing_0_prorcx25w1 ((NU8)3)
typedef struct LoadResult_0_prorcx25w1{
  LoadStatus_0_prorcx25w1 status_0;
  Cursor_0_nifb6mq6y1 decl_0;}
LoadResult_0_prorcx25w1;
typedef struct CursorOwnerObj_0_nifb6mq6y1{
  NI32 rc_0;
  PackedToken_0_nifh7u8pu1* data_0;}
CursorOwnerObj_0_nifb6mq6y1;
typedef struct PackedToken_0_nifh7u8pu1{
  NU32 x_0;
  NU32 info_0;}
PackedToken_0_nifh7u8pu1;
typedef NU16 NimonyExpr_0_nimry5ra91;

#define NoExpr_0_nimry5ra91 ((NU16)0)
#define ErrX_0_nimry5ra91 ((NU16)1)
#define SufX_0_nimry5ra91 ((NU16)2)
#define AtX_0_nimry5ra91 ((NU16)3)
#define DerefX_0_nimry5ra91 ((NU16)4)
#define DotX_0_nimry5ra91 ((NU16)5)
#define PatX_0_nimry5ra91 ((NU16)6)
#define ParX_0_nimry5ra91 ((NU16)7)
#define AddrX_0_nimry5ra91 ((NU16)8)
#define NilX_0_nimry5ra91 ((NU16)9)
#define InfX_0_nimry5ra91 ((NU16)12)
#define NeginfX_0_nimry5ra91 ((NU16)13)
#define NanX_0_nimry5ra91 ((NU16)14)
#define FalseX_0_nimry5ra91 ((NU16)15)
#define TrueX_0_nimry5ra91 ((NU16)16)
#define AndX_0_nimry5ra91 ((NU16)17)
#define OrX_0_nimry5ra91 ((NU16)18)
#define XorX_0_nimry5ra91 ((NU16)19)
#define NotX_0_nimry5ra91 ((NU16)20)
#define NegX_0_nimry5ra91 ((NU16)21)
#define SizeofX_0_nimry5ra91 ((NU16)22)
#define AlignofX_0_nimry5ra91 ((NU16)23)
#define OffsetofX_0_nimry5ra91 ((NU16)24)
#define OconstrX_0_nimry5ra91 ((NU16)25)
#define AconstrX_0_nimry5ra91 ((NU16)26)
#define BracketX_0_nimry5ra91 ((NU16)27)
#define CurlyX_0_nimry5ra91 ((NU16)28)
#define CurlyatX_0_nimry5ra91 ((NU16)29)
#define KvX_0_nimry5ra91 ((NU16)30)
#define OvfX_0_nimry5ra91 ((NU16)32)
#define AddX_0_nimry5ra91 ((NU16)33)
#define SubX_0_nimry5ra91 ((NU16)34)
#define MulX_0_nimry5ra91 ((NU16)35)
#define DivX_0_nimry5ra91 ((NU16)36)
#define ModX_0_nimry5ra91 ((NU16)37)
#define ShrX_0_nimry5ra91 ((NU16)38)
#define ShlX_0_nimry5ra91 ((NU16)39)
#define BitandX_0_nimry5ra91 ((NU16)40)
#define BitorX_0_nimry5ra91 ((NU16)41)
#define BitxorX_0_nimry5ra91 ((NU16)42)
#define BitnotX_0_nimry5ra91 ((NU16)43)
#define EqX_0_nimry5ra91 ((NU16)44)
#define NeqX_0_nimry5ra91 ((NU16)45)
#define LeX_0_nimry5ra91 ((NU16)46)
#define LtX_0_nimry5ra91 ((NU16)47)
#define CastX_0_nimry5ra91 ((NU16)48)
#define ConvX_0_nimry5ra91 ((NU16)49)
#define CallX_0_nimry5ra91 ((NU16)50)
#define CmdX_0_nimry5ra91 ((NU16)51)
#define CchoiceX_0_nimry5ra91 ((NU16)80)
#define OchoiceX_0_nimry5ra91 ((NU16)81)
#define PragmaxX_0_nimry5ra91 ((NU16)141)
#define QQuotedX_0_nimry5ra91 ((NU16)235)
#define HderefX_0_nimry5ra91 ((NU16)236)
#define DdotX_0_nimry5ra91 ((NU16)237)
#define HaddrX_0_nimry5ra91 ((NU16)238)
#define NewrefX_0_nimry5ra91 ((NU16)239)
#define NewobjX_0_nimry5ra91 ((NU16)240)
#define TupX_0_nimry5ra91 ((NU16)241)
#define TupconstrX_0_nimry5ra91 ((NU16)242)
#define SetconstrX_0_nimry5ra91 ((NU16)243)
#define TabconstrX_0_nimry5ra91 ((NU16)244)
#define AshrX_0_nimry5ra91 ((NU16)245)
#define BaseobjX_0_nimry5ra91 ((NU16)246)
#define HconvX_0_nimry5ra91 ((NU16)247)
#define DconvX_0_nimry5ra91 ((NU16)248)
#define CallstrlitX_0_nimry5ra91 ((NU16)249)
#define InfixX_0_nimry5ra91 ((NU16)250)
#define PrefixX_0_nimry5ra91 ((NU16)251)
#define HcallX_0_nimry5ra91 ((NU16)252)
#define CompilesX_0_nimry5ra91 ((NU16)253)
#define DeclaredX_0_nimry5ra91 ((NU16)254)
#define DefinedX_0_nimry5ra91 ((NU16)255)
#define AstToStrX_0_nimry5ra91 ((NU16)256)
#define BindSymX_0_nimry5ra91 ((NU16)257)
#define BindSymNameX_0_nimry5ra91 ((NU16)258)
#define InstanceofX_0_nimry5ra91 ((NU16)259)
#define ProccallX_0_nimry5ra91 ((NU16)260)
#define HighX_0_nimry5ra91 ((NU16)261)
#define LowX_0_nimry5ra91 ((NU16)262)
#define TypeofX_0_nimry5ra91 ((NU16)263)
#define UnpackX_0_nimry5ra91 ((NU16)264)
#define FieldsX_0_nimry5ra91 ((NU16)265)
#define FieldpairsX_0_nimry5ra91 ((NU16)266)
#define EnumtostrX_0_nimry5ra91 ((NU16)267)
#define IsmainmoduleX_0_nimry5ra91 ((NU16)268)
#define DefaultobjX_0_nimry5ra91 ((NU16)269)
#define DefaulttupX_0_nimry5ra91 ((NU16)270)
#define DefaultdistinctX_0_nimry5ra91 ((NU16)271)
#define DelayX_0_nimry5ra91 ((NU16)272)
#define Delay0X_0_nimry5ra91 ((NU16)273)
#define SuspendX_0_nimry5ra91 ((NU16)274)
#define ExprX_0_nimry5ra91 ((NU16)275)
#define DoX_0_nimry5ra91 ((NU16)276)
#define ArratX_0_nimry5ra91 ((NU16)277)
#define TupatX_0_nimry5ra91 ((NU16)278)
#define PlussetX_0_nimry5ra91 ((NU16)279)
#define MinussetX_0_nimry5ra91 ((NU16)280)
#define MulsetX_0_nimry5ra91 ((NU16)281)
#define XorsetX_0_nimry5ra91 ((NU16)282)
#define EqsetX_0_nimry5ra91 ((NU16)283)
#define LesetX_0_nimry5ra91 ((NU16)284)
#define LtsetX_0_nimry5ra91 ((NU16)285)
#define InsetX_0_nimry5ra91 ((NU16)286)
#define CardX_0_nimry5ra91 ((NU16)287)
#define EmoveX_0_nimry5ra91 ((NU16)288)
#define DestroyX_0_nimry5ra91 ((NU16)289)
#define DupX_0_nimry5ra91 ((NU16)290)
#define CopyX_0_nimry5ra91 ((NU16)291)
#define WasmovedX_0_nimry5ra91 ((NU16)292)
#define SinkhX_0_nimry5ra91 ((NU16)293)
#define TraceX_0_nimry5ra91 ((NU16)294)
#define InternalTypeNameX_0_nimry5ra91 ((NU16)319)
#define InternalFieldPairsX_0_nimry5ra91 ((NU16)320)
#define FailedX_0_nimry5ra91 ((NU16)321)
#define IsX_0_nimry5ra91 ((NU16)322)
#define EnvpX_0_nimry5ra91 ((NU16)323)
#define ToClosureX_0_nimry5ra91 ((NU16)341)
typedef struct MagicSpec_0_chu5m1rja1{
  NimonyExpr_0_nimry5ra91 op_0;
  NI32 bits_0;
  NB8 signed_0;
  NB8 caseEq_0;}
MagicSpec_0_chu5m1rja1;
typedef struct ConvSpec_0_chu5m1rja1{
  NI32 mode_0;
  NI32 bits_0;
  NB8 signed_0;
  TCode_0_valzr1t4f code_0;
  NU32 etype_0;}
ConvSpec_0_chu5m1rja1;
typedef struct GatedCall_0_chu5m1rja1{
  NI32 nat_0;
  NI32 fallback_0;
  NB8 dollarScalar_0;}
GatedCall_0_chu5m1rja1;
typedef struct ObjInfo_0_chu5m1rja1{
  NU32 typeSym_0;
  seq_0_In6doa_ast8ri79k fieldSyms_0;}
ObjInfo_0_chu5m1rja1;
typedef struct Local_0_decqocs071{
  NimonySym_0_nimry5ra91 kind_0;
  Cursor_0_nifb6mq6y1 name_0;
  Cursor_0_nifb6mq6y1 exported_0;
  Cursor_0_nifb6mq6y1 pragmas_0;
  Cursor_0_nifb6mq6y1 typ_0;
  Cursor_0_nifb6mq6y1 val_0;}
Local_0_decqocs071;
typedef struct Proc_0_chu5m1rja1{
  seq_0_Izok7jt1_chu5m1rja1 code_0;
  seq_0_Ift2sne_chu5m1rja1 lines_0;
  NI32 numParams_0;
  NI32 numLocals_0;
  NI32 resultSlot_0;
  string_0_sysvq0asl name_0;
  NB8 isPassive_0;
  seq_0_In6doa_ast8ri79k slotSyms_0;}
Proc_0_chu5m1rja1;
typedef struct GlobalSeed_0_chu5m1rja1{
  NI32 slot_0;
  string_0_sysvq0asl name_0;
  string_0_sysvq0asl cname_0;
  Value_0_valzr1t4f v_0;}
GlobalSeed_0_chu5m1rja1;
typedef struct SizeAlign_0_siz2wt1it{
  NI32 size_0;
  NI32 align_0;}
SizeAlign_0_siz2wt1it;
typedef struct MethodSite_0_chu5m1rja1{
  NU32 staticFn_0;
  NI32 fallbackIdx_0;}
MethodSite_0_chu5m1rja1;
typedef struct MethodEntry_0_chu5m1rja1{
  NU32 sym_0;
  NI32 idx_0;}
MethodEntry_0_chu5m1rja1;
typedef struct MethodIndexEntry_0_sempjk6bn1{
  NU32 fn_0;
  NU32 signature_0;}
MethodIndexEntry_0_sempjk6bn1;
typedef struct ObjSpec_0_chu5m1rja1{
  NU32 typeSym_0;
  NB8 isRef_0;
  seq_0_In6doa_ast8ri79k fields_0;}
ObjSpec_0_chu5m1rja1;
typedef struct VmProgram_0_chu5m1rja1{
  seq_0_Inaua171_chu5m1rja1 procs_0;
  seq_0_I50urnw_chu5m1rja1 consts_0;
  seq_0_Ie9rikd_chu5m1rja1 magics_0;
  seq_0_Iknt7a3_chu5m1rja1 convs_0;
  seq_0_Ixdx2fh1_ast8ri79k natives_0;
  seq_0_In6doa_ast8ri79k enumWraps_0;
  seq_0_Id5h4uf_chu5m1rja1 gatedCalls_0;
  seq_0_I2neof81_chu5m1rja1 objInfos_0;
  seq_0_In6doa_ast8ri79k fieldSyms_0;
  seq_0_Isww99s_chu5m1rja1 objSpecs_0;
  seq_0_In6doa_ast8ri79k typeSyms_0;
  seq_0_In6doa_ast8ri79k envSyms_0;
  seq_0_Ir067xu1_chu5m1rja1 methodSites_0;
  seq_0_I88k8j01_chu5m1rja1 methodTable_0;
  Proc_0_chu5m1rja1 top_0;
  seq_0_Inaua171_chu5m1rja1 inits_0;
  NI32 numGlobals_0;
  seq_0_Iioxqbu_chu5m1rja1 globalSeeds_0;}
VmProgram_0_chu5m1rja1;
typedef NU8 SkipMode_0_decqocs071;

#define SkipExclBody_0_decqocs071 ((NU8)0)
#define SkipInclBody_0_decqocs071 ((NU8)1)
#define SkipFinalParRi_0_decqocs071 ((NU8)2)
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
typedef struct X60Qt_0_IAarrayAuS8ZS11_decqocs071{
  NU8 a[11];}
X60Qt_0_IAarrayAuS8ZS11_decqocs071;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI32);
typedef struct X60Qt_0_IAarrayAuS8ZS43_ast8ri79k{
  NU8 a[43];}
X60Qt_0_IAarrayAuS8ZS43_ast8ri79k;
typedef struct TokenBuf_0_nifb6mq6y1{
  PackedToken_0_nifh7u8pu1* data_0;
  NI32 len_0;
  NI32 cap_0;
  CursorOwnerObj_0_nifb6mq6y1* owner_0;}
TokenBuf_0_nifb6mq6y1;
typedef struct Cell_Obj_0_valzr1t4f{
  Value_0_valzr1t4f v_0;}
Cell_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  Cell_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43ellX4fbj0valzr1t4f_aow2h993l1;
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct CoroRef_Obj_0_valzr1t4f{
  RootObj_0_sysvq0asl Q;}
CoroRef_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f{
  NI r_00;
  CoroRef_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX43oroX52efX4fbj0valzr1t4f_valzr1t4f;
typedef struct SeqBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
SeqBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  SeqBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53eqX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ArrBox_Obj_0_valzr1t4f{
  seq_0_Iw8xl5b1_flaksyopx1 elems_0;
  NI32 lo_0;
  X60Qt_0_IArefSX46latX52egionX4fbj0valzr1t4f_aow2h993l1* flat_0;}
ArrBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ArrBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX41rrX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef struct ObjBox_Obj_0_valzr1t4f{
  NU32 typeSym_0;
  seq_0_In6doa_ast8ri79k names_0;
  seq_0_Iw8xl5b1_flaksyopx1 cells_0;}
ObjBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1{
  NI r_00;
  ObjBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX4fbjX42oxX4fbj0valzr1t4f_aow2h993l1;
typedef NU8 RegionKind_0_valzr1t4f;

#define rkBytes_0_valzr1t4f ((NU8)0)
#define rkSeq_0_valzr1t4f ((NU8)1)
#define rkArr_0_valzr1t4f ((NU8)2)
#define rkStr_0_valzr1t4f ((NU8)3)
#define rkCell_0_valzr1t4f ((NU8)4)
#define rkObj_0_valzr1t4f ((NU8)5)
#define rkForeign_0_valzr1t4f ((NU8)6)
typedef struct seq_0_Incv1wn_explnj22x1{
  NI32 len_0;
  NU8* data_0;}
seq_0_Incv1wn_explnj22x1;
typedef struct FlatRegion_Obj_0_valzr1t4f{
  RegionKind_0_valzr1t4f kind_0;
  union {
    struct {
      seq_0_Incv1wn_explnj22x1 bytes_0;
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
      seq_0_Ift2sne_chu5m1rja1 offs_0;}
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
typedef struct X60Qt_0_IAarrayAuS64ZS4_runot4689{
  NU64 a[4];}
X60Qt_0_IAarrayAuS64ZS4_runot4689;
typedef struct SetBox_Obj_0_valzr1t4f{
  X60Qt_0_IAarrayAuS64ZS4_runot4689 words_0;}
SetBox_Obj_0_valzr1t4f;
typedef struct X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689{
  NI r_00;
  SetBox_Obj_0_valzr1t4f d_00;}
X60Qt_0_IArefSX53etX42oxX4fbj0valzr1t4f_runot4689;
typedef struct Rtti_0_sysvq0asl{
  NI32 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 importedGlobal_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_49, NU32 s_23, Cursor_0_nifb6mq6y1 initExpr_1);
void compileExpr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_55, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_27, Cursor_0_nifb6mq6y1* n_25);
void compileAddr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_56, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_28, Cursor_0_nifb6mq6y1* n_26);
void emitFieldAddr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_57, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_29, Cursor_0_nifb6mq6y1* n_27);
void emitTupIndex_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_58, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_30, Cursor_0_nifb6mq6y1* n_28, NB8 wantAddr_1);
void compileConstr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_59, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_31, Cursor_0_nifb6mq6y1* n_29);
void compileCall_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_60, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_32, Cursor_0_nifb6mq6y1* n_30, NB8 forceStatic_1);
void compileConv_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_61, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_33, Cursor_0_nifb6mq6y1* n_31);
void compileSuf_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_62, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_34, Cursor_0_nifb6mq6y1* n_32);
void compileArrayConstr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_63, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_35, Cursor_0_nifb6mq6y1* n_33);
void compileIndexGet_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_64, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_36, Cursor_0_nifb6mq6y1* n_34);
void compileSetConstr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_65, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_37, Cursor_0_nifb6mq6y1* n_35);
void compileInstanceOf_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_68, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_40, Cursor_0_nifb6mq6y1* n_38);
void compileCaseExpr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_71, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_43, Cursor_0_nifb6mq6y1* n_39);
void compileIfExpr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_72, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_44, Cursor_0_nifb6mq6y1* n_40);
void collectObjectFields_1_comaa5xpt1(NU32 typeSym_3, seq_0_In6doa_ast8ri79k* fields_1);
void compileTryExpr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_91, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_63, Cursor_0_nifb6mq6y1* n_50);
void compileStmt_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_94, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_66, Cursor_0_nifb6mq6y1* n_53);
NB8 isMethodSym_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_96, NU32 s_26);
NB8 routineExistsVM_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_97, NU32 s_27);
NB8 symIsPassive_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_98, NU32 s_28);
NB8 firstParamContainer_1_comaa5xpt1(NU32 s_29);
NB8 returnsMutLocation_1_comaa5xpt1(NU32 s_30);
X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1 foreignLeafOf_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_100, NU32 s_32);
NI32 getProcIdx_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_101, NU32 s_33);
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36);
static inline void putQ_7_Ifvyck5_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_111, NI32 i_37, NI32 elem_25);
static inline void add_0_I34il1q_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_112, NU32 elem_26);
static inline void add_0_I8kd4i4_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_114, NI32 elem_27);
static inline string_0_sysvq0asl* getQ_0_I93d71y_comaa5xpt1(BiTable_0_Icvz6lt_buiyylk1h1 t_21, NU32 litId_6);
static inline NI32 len_3_Icgec691_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1 s_116);
static inline void add_0_Ibh17rk1_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1* s_117, Instr_0_chu5m1rja1 elem_28);
static inline Instr_0_chu5m1rja1* getQ_7_Iuezo3v1_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1 s_119, NI32 i_38);
static inline void putQ_7_Iko5vvk1_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1* s_120, NI32 i_39, Instr_0_chu5m1rja1 elem_29);
static inline NI32 len_3_I4n9kvq_comaa5xpt1(seq_0_I50urnw_chu5m1rja1 s_121);
static inline void add_0_Itre92n_comaa5xpt1(seq_0_I50urnw_chu5m1rja1* s_122, Value_0_valzr1t4f elem_30);
static inline NI32 len_3_Idcvg0j1_comaa5xpt1(seq_0_Ie9rikd_chu5m1rja1 s_124);
static inline void add_0_Iv446pn1_comaa5xpt1(seq_0_Ie9rikd_chu5m1rja1* s_125, MagicSpec_0_chu5m1rja1 elem_31);
static inline NI32 len_3_Iiake9l_comaa5xpt1(seq_0_Iknt7a3_chu5m1rja1 s_127);
static inline void add_0_Imr7j74_comaa5xpt1(seq_0_Iknt7a3_chu5m1rja1* s_128, ConvSpec_0_chu5m1rja1 elem_32);
static inline NI32 len_3_Ixq6taz_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_130);
static inline NI32 len_3_I18vp0c1_comaa5xpt1(seq_0_Id5h4uf_chu5m1rja1 s_134);
static inline void add_0_Iybug3z_comaa5xpt1(seq_0_Id5h4uf_chu5m1rja1* s_135, GatedCall_0_chu5m1rja1 elem_34);
static inline NI32 len_3_Ibeqm1v_comaa5xpt1(seq_0_I2neof81_chu5m1rja1 s_137);
static inline void add_0_Iwx7sdj1_comaa5xpt1(seq_0_I2neof81_chu5m1rja1* s_138, ObjInfo_0_chu5m1rja1 elem_35);
static inline void add_0_Insw6ce1_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1* s_144, Cursor_0_nifb6mq6y1 elem_37);
static inline NI32 len_3_Ibv77kg1_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1 s_146);
static inline X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1** getQ_7_Ivqabz61_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1 s_147, NI32 i_42);
static inline seq_0_Iscf6bn_comaa5xpt1 newSeqUninit_0_Ib8z3ow_comaa5xpt1(NI32 size_26);
static inline seq_0_Igm8woo1_comaa5xpt1 newSeqUninit_0_I8nq5k8_comaa5xpt1(NI32 size_28);
static inline seq_0_I806bg1_comaa5xpt1 newSeqUninit_0_Iqckanu_comaa5xpt1(NI32 size_30);
static inline NI32 len_3_I05nxx61_comaa5xpt1(seq_0_Inaua171_chu5m1rja1 s_148);
static inline void add_0_Iss439i1_comaa5xpt1(seq_0_Inaua171_chu5m1rja1* s_149, Proc_0_chu5m1rja1 elem_38);
static inline NI32 len_3_Iuz7erf_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1 s_151);
static inline GlobalSeed_0_chu5m1rja1* getQ_7_Ijx02qt_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1 s_152, NI32 i_43);
static inline void add_0_Iyv2a7e1_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1* s_153, GlobalSeed_0_chu5m1rja1 elem_39);
static inline Cursor_0_nifb6mq6y1* getQ_7_Iyegbq3_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_155, NI32 i_44);
static inline void add_0_Iuw4xx01_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_157, X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* elem_40);
static inline X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** getQ_7_I6yhgto_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_159, NI32 i_46);
static inline openArray_0_Inqs7yx_comaa5xpt1 toOpenArray_1_Ibqb4ob_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_160);
static inline NI32 len_3_Ij0uoqp_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_162);
void setLen_0_Ivhuv1v1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_163, NI32 newLen_4);
static inline NI32 len_3_In1ttqs_comaa5xpt1(seq_0_Ir067xu1_chu5m1rja1 s_166);
static inline void add_0_Inwn80m1_comaa5xpt1(seq_0_Ir067xu1_chu5m1rja1* s_167, MethodSite_0_chu5m1rja1 elem_41);
static inline seq_0_Isyzizu1_comaa5xpt1 newSeqUninit_0_Iikx2qh1_comaa5xpt1(NI32 size_32);
static inline seq_0_Ik7wkpe_comaa5xpt1 newSeqUninit_0_Idxnvmq_comaa5xpt1(NI32 size_34);
seq_0_Ift2sne_chu5m1rja1 atQ_0_Iy7v4si1_comaa5xpt1(X60Qt_0_IAarrayAiS32ZS1_comaa5xpt1 a_16);
static inline void add_0_Iivdbhc_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1* s_169, seq_0_Ift2sne_chu5m1rja1 elem_42);
static inline NI32 len_3_Irjnvku_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 s_171);
static inline seq_0_Ift2sne_chu5m1rja1* getQ_7_Iurb46i_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 s_172, NI32 i_50);
static inline NI32 len_3_I0v1j8d_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_173);
static inline NI32 len_3_Ilsmz1h_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_174);
static inline HSlice_0_I8tnmvh1_comaa5xpt1 ___1_Ico26mb_comaa5xpt1(NI32 a_17, NI32 b_12);
static inline seq_0_Ift2sne_chu5m1rja1 getQ_17_I2og8ah1_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_175, HSlice_0_I8tnmvh1_comaa5xpt1 x_9);
static inline void add_0_Iype0e61_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* s_177, X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* elem_43);
static inline NI32 len_3_I7uqqfu1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1 s_179);
void setLen_0_I93919j1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* s_180, NI32 newLen_7);
static inline void add_0_Ie3v897_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* s_183, FinScope_0_comaa5xpt1 elem_44);
static inline NI32 len_3_I8hzf0s1_comaa5xpt1(seq_0_I806bg1_comaa5xpt1 s_185);
void setLen_0_I53ui2z_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* s_186, NI32 newLen_10);
static inline FinScope_0_comaa5xpt1* getQ_7_Irfu7p7_comaa5xpt1(seq_0_I806bg1_comaa5xpt1 s_189, NI32 i_53);
static inline X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1** getQ_7_Iklts1k_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1 s_190, NI32 i_54);
static inline seq_0_Iscf6bn_comaa5xpt1 getQ_17_Iuwh3901_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_191, HSlice_0_I8tnmvh1_comaa5xpt1 x_11);
static inline openArray_0_I6xd9vz_comaa5xpt1 toOpenArray_1_Ibb6pci1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_193);
static inline void putQ_7_Ia9tk91_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_195, NI32 i_56, NU32 elem_45);
static inline void add_0_If3vc0y1_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* s_196, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* elem_46);
void setLen_0_Izc6r611_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* s_198, NI32 newLen_13);
static inline void putQ_7_I5scqr1_comaa5xpt1(seq_0_Inaua171_chu5m1rja1* s_201, NI32 i_58, Proc_0_chu5m1rja1 elem_47);
static inline NI32 len_3_I2qk2yu1_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1 s_202);
static inline MethodEntry_0_chu5m1rja1* getQ_7_I8226yy1_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1 s_203, NI32 i_59);
static inline openArray_0_In1h8lr1_comaa5xpt1 toOpenArray_1_Ivm9z5a_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_204);
static inline void add_0_I3fda3s1_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1* s_206, MethodEntry_0_chu5m1rja1 elem_48);
static inline openArray_0_Iz8j0ra_comaa5xpt1 toOpenArray_1_Ipyn7lx1_comaa5xpt1(seq_0_I2neof81_chu5m1rja1 s_208);
static inline openArray_0_I94odo91_comaa5xpt1 toOpenArray_1_Itwyxk01_comaa5xpt1(seq_0_Isww99s_chu5m1rja1 s_210);
static inline openArray_0_Ir53qdx_comaa5xpt1 toOpenArray_1_I02c2wz_comaa5xpt1(seq_0_In6doa_ast8ri79k s_212);
static inline HSlice_0_Inzqy8d_comaa5xpt1 ___1_Iclcqmw1_comaa5xpt1(NI32 a_28, NI32 b_13);
static inline seq_0_Ik8dusv_comaa5xpt1 newSeqUninit_0_Ichtepn1_comaa5xpt1(NI32 size_54);
static inline NI32 len_6_Imwfq2l1_comaa5xpt1(openArray_0_Imqex5f1_comaa5xpt1 a_31);
static inline Cursor_0_nifb6mq6y1* getQ_10_I3gtmqq1_comaa5xpt1(openArray_0_Imqex5f1_comaa5xpt1 x_20, NI32 idx_22);
NB8 resize_0_I8l4tya_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* dest_22, NI32 addedElements_22);
NB8 resize_0_Izte9pz_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1* dest_23, NI32 addedElements_23);
NB8 resize_0_Iz8tg361_comaa5xpt1(seq_0_I50urnw_chu5m1rja1* dest_24, NI32 addedElements_24);
NB8 resize_0_Itdw5n21_comaa5xpt1(seq_0_Ie9rikd_chu5m1rja1* dest_25, NI32 addedElements_25);
NB8 resize_0_Ikaiuf5_comaa5xpt1(seq_0_Iknt7a3_chu5m1rja1* dest_26, NI32 addedElements_26);
NB8 resize_0_I9r5bp3_comaa5xpt1(seq_0_Id5h4uf_chu5m1rja1* dest_28, NI32 addedElements_28);
NB8 resize_0_Ib3lf9y1_comaa5xpt1(seq_0_I2neof81_chu5m1rja1* dest_29, NI32 addedElements_29);
static inline NI32 capInBytes_0_I0ia6g61_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_231);
NB8 resize_0_I6nu0dd_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1* dest_31, NI32 addedElements_31);
static inline NI32 memSizeInBytes_0_I11sygp_comaa5xpt1(NI32 size_63);
static inline NI32 memSizeInBytes_0_Ichxqj91_comaa5xpt1(NI32 size_64);
static inline NI32 memSizeInBytes_0_I86jswb1_comaa5xpt1(NI32 size_65);
NB8 resize_0_I91teg71_comaa5xpt1(seq_0_Inaua171_chu5m1rja1* dest_32, NI32 addedElements_32);
NB8 resize_0_Ijlhibe1_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1* dest_33, NI32 addedElements_33);
static inline NI32 capInBytes_0_Itl2tw2_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_235);
NB8 resize_0_I606t801_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* dest_34, NI32 addedElements_34);
static inline NI32* rawData_0_Ic25u3r_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_236);
static inline NI32 len_6_I9632ti1_comaa5xpt1(openArray_0_Inqs7yx_comaa5xpt1 a_32);
static inline NI32* getQ_10_I053icq_comaa5xpt1(openArray_0_Inqs7yx_comaa5xpt1 x_21, NI32 idx_24);
void shrink_0_Irsuiak1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_237, NI32 newLen_16);
void growUnsafe_0_Io18vke_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_238, NI32 newLen_17);
NB8 resize_0_Ig21eot_comaa5xpt1(seq_0_Ir067xu1_chu5m1rja1* dest_35, NI32 addedElements_35);
static inline NI32 memSizeInBytes_0_I3r8cpo1_comaa5xpt1(NI32 size_66);
static inline NI32 memSizeInBytes_0_I03jys01_comaa5xpt1(NI32 size_67);
static inline NI32 capInBytes_0_Iri1hlt1_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 s_240);
NB8 resize_0_I9lztdq1_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1* dest_36, NI32 addedElements_36);
seq_0_Ift2sne_chu5m1rja1 getQ_16_Ijvcpzq1_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_241, HSlice_0_Inzqy8d_comaa5xpt1 x_22);
static inline NI32 capInBytes_0_Idtacij1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1 s_242);
NB8 resize_0_Iiusqmu1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* dest_37, NI32 addedElements_37);
void shrink_0_I6q9rej1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* s_243, NI32 newLen_18);
void growUnsafe_0_Itey597_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* s_244, NI32 newLen_19);
static inline NI32 capInBytes_0_Ipkd9yl_comaa5xpt1(seq_0_I806bg1_comaa5xpt1 s_245);
NB8 resize_0_Ix9q1o91_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* dest_38, NI32 addedElements_38);
void shrink_0_Ic6ijzf_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* s_246, NI32 newLen_20);
void growUnsafe_0_I2ptrki_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* s_247, NI32 newLen_21);
seq_0_Iscf6bn_comaa5xpt1 getQ_16_Iansvof1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_248, HSlice_0_Inzqy8d_comaa5xpt1 x_23);
static inline X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** rawData_0_Iabis8p_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_249);
static inline NI32 len_6_Ie5pl0g_comaa5xpt1(openArray_0_I6xd9vz_comaa5xpt1 a_35);
static inline X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** getQ_10_Itsygq7_comaa5xpt1(openArray_0_I6xd9vz_comaa5xpt1 x_24, NI32 idx_25);
static inline NI32 capInBytes_0_Iz2n5ul_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1 s_250);
NB8 resize_0_Iymm5xw_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* dest_39, NI32 addedElements_39);
void shrink_0_I5z0zky1_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* s_251, NI32 newLen_22);
void growUnsafe_0_I1b8vl2_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* s_252, NI32 newLen_23);
static inline MethodIndexEntry_0_sempjk6bn1* rawData_0_I0uy4q51_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_253);
static inline NI32 len_6_I8gnayb_comaa5xpt1(openArray_0_In1h8lr1_comaa5xpt1 a_36);
static inline MethodIndexEntry_0_sempjk6bn1* getQ_10_Izev5kw1_comaa5xpt1(openArray_0_In1h8lr1_comaa5xpt1 x_25, NI32 idx_26);
NB8 resize_0_I6yc4yx_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1* dest_40, NI32 addedElements_40);
static inline ObjInfo_0_chu5m1rja1* rawData_0_Icrhavl1_comaa5xpt1(seq_0_I2neof81_chu5m1rja1 s_255);
static inline NI32 len_6_Io9vvx7_comaa5xpt1(openArray_0_Iz8j0ra_comaa5xpt1 a_37);
static inline ObjInfo_0_chu5m1rja1* getQ_10_Ij5s4n11_comaa5xpt1(openArray_0_Iz8j0ra_comaa5xpt1 x_26, NI32 idx_27);
static inline ObjSpec_0_chu5m1rja1* rawData_0_I3cvan_comaa5xpt1(seq_0_Isww99s_chu5m1rja1 s_256);
static inline NI32 len_6_I7v6wrd_comaa5xpt1(openArray_0_I94odo91_comaa5xpt1 a_38);
static inline ObjSpec_0_chu5m1rja1* getQ_10_I3bn8xm1_comaa5xpt1(openArray_0_I94odo91_comaa5xpt1 x_27, NI32 idx_28);
static inline NU32* rawData_0_I9ky6gs1_comaa5xpt1(seq_0_In6doa_ast8ri79k s_257);
static inline NI32 len_6_Ijqv54i_comaa5xpt1(openArray_0_Ir53qdx_comaa5xpt1 a_39);
static inline NU32* getQ_10_Ibernwj1_comaa5xpt1(openArray_0_Ir53qdx_comaa5xpt1 x_28, NI32 idx_29);
static inline string_0_sysvq0asl* rawData_0_I65w5sr_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_258);
static inline NI32 memSizeInBytes_0_I68vum51_comaa5xpt1(NI32 size_78);
void eQdestroy_1_Ij4pznj1_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 s_322);
static inline void eQwasMoved_1_I1l3xdo1_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1* s_323);
seq_0_Ik7wkpe_comaa5xpt1 eQdup_1_Iqlupf9_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 a_72);
void eQdestroy_1_Irljx3e1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_326);
static inline void eQwasMoved_1_Iw33v4x_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_327);
void eQdestroy_1_Ir7cqbo_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_350);
void eQdestroy_1_Iph9dp4_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_381);
static inline NI32 memSizeInBytes_0_Ikui0mk_comaa5xpt1(NI32 size_115);
void eQdestroyQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1(SymMap_0_comaa5xpt1 dest_0);
void eQwasmovedQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1(SymMap_0_comaa5xpt1* dest_0);
SymMap_0_comaa5xpt1 eQdupQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1(SymMap_0_comaa5xpt1 src_0);
void eQdestroyQ_SX46inX53cope0comaa5xpt1_0_comaa5xpt1(FinScope_0_comaa5xpt1 dest_0);
void eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* dest_0);
void eQdestroyQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* dest_0);
void eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* dest_0);
void eQdestroyQ_ArefSX43ompilerX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* dest_0);
X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* eQdupQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* src_0);
X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* src_0);
void eQdestroyQ_AtupleAboolZSstring0sysvq0asl_0_comaa5xpt1(X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1 dest_0);
void eQwasmovedQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1* dest_0);
void eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1 dest_0);
X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* eQdupQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* src_0);
void eQwasmovedQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1** dest_0);
void eQwasmovedQ_AtupleAboolZSstring0sysvq0asl_0_comaa5xpt1(X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1* dest_0);
static inline NI32 len_3_I6y2imo_buiyylk1h1(seq_0_In6doa_ast8ri79k s_56);
static inline NU32* getQ_7_I2v00yv1_buiyylk1h1(seq_0_In6doa_ast8ri79k s_58, NI32 i_28);
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0);
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7);
extern Routine_0_decqocs071 asRoutine_0_decqocs071(Cursor_0_nifb6mq6y1 c_8, SkipMode_0_decqocs071 mode_3);
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1);
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4);
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0);
extern void eQdestroyQ_SX52outine0decqocs071_0_decqocs071(Routine_0_decqocs071* dest_0);
static inline void inc_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_18);
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13);
extern Literals_0_nifh7u8pu1 pool_0_nifh7u8pu1;
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_50, string_0_sysvq0asl b_13);
static inline void nimStrDestroy(string_0_sysvq0asl s_41);
extern void skip_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_24);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40);
static inline string_0_sysvq0asl* getQ_0_In1k2p81_ast8ri79k(BiTable_0_I0ksat5_ast8ri79k t_13, NU32 litId_12);
extern void extractBasename_1_symkyk35i1(string_0_sysvq0asl* s_1);
static inline NU32 info_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_5);
extern LineInfoUnpacked_0_linxafkvx1 unpack_0_linxafkvx1(LineInfoManager_0_linxafkvx1 m_2, NU32 info_0);
extern Value_0_valzr1t4f eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* src_0);
extern LoadResult_0_prorcx25w1 tryLoadSymSafe_0_modzy18mg1(NU32 s_0);
extern void eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(LoadResult_0_prorcx25w1 dest_0);
extern Value_0_valzr1t4f defaultForType_1_runot4689(Cursor_0_nifb6mq6y1 typ_2);
extern void eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_8, NI32 i_5);
static inline void add_0_Ig6072n_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_20, string_0_sysvq0asl elem_3);
extern seq_0_In6doa_ast8ri79k eQdup_1_Idg8rf9_ast8ri79k(seq_0_In6doa_ast8ri79k a_17);
extern NB8 isNativeBase_0_runot4689(string_0_sysvq0asl base_0);
extern string_0_sysvq0asl trueModuleOf_0_runot4689(NU32 sym_1);
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34);
extern NB8 nativeProvidesSym_0_runot4689(NU32 sym_3);
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1);
static inline NU32 intId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_10);
static inline NI64* getQ_0_Irwkiny1_ast8ri79k(BiTable_0_Itvq7bk_ast8ri79k t_7, NU32 litId_6);
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8);
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3);
static inline NU32 litId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_7);
static inline string_0_sysvq0asl* getQ_0_Iplpzal1_ast8ri79k(BiTable_0_Ipgo74p_ast8ri79k t_6, NU32 litId_5);
static inline NimonySym_0_nimry5ra91 symKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_11);
static inline NB8 isRoutine_0_decqocs071(NimonySym_0_nimry5ra91 t_0);
extern void publishFieldDecls_0_runot4689(Cursor_0_nifb6mq6y1 n_2);
static inline void consumeParRi_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_19);
extern Local_0_decqocs071 asLocal_0_decqocs071(Cursor_0_nifb6mq6y1 c_5, SkipMode_0_decqocs071 mode_1);
extern void eQdestroyQ_SX4cocal0decqocs071_0_decqocs071(Local_0_decqocs071* dest_0);
extern void* allocFixed_0_sysvq0asl(NI32 size_27);
static inline seq_0_Izok7jt1_chu5m1rja1 newSeqUninit_0_I82j90d_chu5m1rja1(NI32 size_30);
static inline seq_0_Ift2sne_chu5m1rja1 newSeqUninit_0_Iggfvwp_chu5m1rja1(NI32 size_32);
static inline seq_0_In6doa_ast8ri79k newSeqUninit_0_Ieodq4s1_ast8ri79k(NI32 size_32);
extern seq_0_Izok7jt1_chu5m1rja1 eQdup_1_Ir0cadv1_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1 a_15);
extern seq_0_Ift2sne_chu5m1rja1 eQdup_1_Iplow11_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 a_16);
extern Value_0_valzr1t4f libcConstVal_0_runot4689(string_0_sysvq0asl b_2, NB8* found_4);
extern void eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f(Value_0_valzr1t4f* dest_0);
extern string_0_sysvq0asl importcName_0_hlc70y78v(Cursor_0_nifb6mq6y1 pragmasCur_4);
extern Value_0_valzr1t4f vEnum_0_valzr1t4f(NI32 ord_0, NU32 ekind_0, string_0_sysvq0asl name_0);
extern xint_0_xinat3x34 createXint_0_xinat3x34(NI64 x_4);
extern Value_0_valzr1t4f vIntX_0_valzr1t4f(xint_0_xinat3x34 x_3, NI32 bits_1);
static inline NU32 uintId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_11);
static inline NU64* getQ_0_Iebom0i1_ast8ri79k(BiTable_0_Itxao711_ast8ri79k t_8, NU32 litId_7);
extern Value_0_valzr1t4f vUIntX_0_valzr1t4f(xint_0_xinat3x34 x_5, NI32 bits_3);
static inline NU32 floatId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_12);
static inline NF64 getQ_1_I4qx0py_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_9, NU32 litId_8);
extern Value_0_valzr1t4f vFloat_0_valzr1t4f(NF64 f_0, NI32 bits_4);
static inline NC8 charLit_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_9);
extern Value_0_valzr1t4f vChar_0_valzr1t4f(NC8 c_0);
extern Value_0_valzr1t4f vStr_0_valzr1t4f(string_0_sysvq0asl s_0);
static inline NimonyExpr_0_nimry5ra91 exprKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_10);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_58, NI32 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_49, string_0_sysvq0asl b_12);
extern Value_0_valzr1t4f vBool_0_valzr1t4f(NB8 b_0);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3);
extern SizeAlign_0_siz2wt1it sizeAlignOfType_0_siz2wt1it(Cursor_0_nifb6mq6y1 typ_0, NI32 depth_0);
extern Value_0_valzr1t4f vInt_0_valzr1t4f(NI64 x_2, NI32 bits_0);
extern NB8 isEnumType_0_runot4689(NU32 sym_0);
extern void eQdestroy_1_Iscb4i31_ast8ri79k(seq_0_In6doa_ast8ri79k s_65);
extern LongString_0_sysvq0asl const strlit_0_I12313941242067973473_buiyylk1h1;
extern NB8 isGatedNative_0_runot4689(string_0_sysvq0asl base_1);
extern NB8 isStreamGatableIO_0_runot4689(string_0_sysvq0asl base_2);
extern LongString_0_sysvq0asl const strlit_0_I11024699549390617459_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I2984705338531181753_buiyylk1h1;
extern NI32 sizeOfSym_0_fiepkwzpc(NU32 typeSym_3);
extern NB8 isFlatPodType_0_fiepkwzpc(NU32 typeSym_2);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_54, NI32 i_14);
extern NI32 arrayLowFromType_0_runot4689(Cursor_0_nifb6mq6y1 typeCur_0);
extern void eQdestroy_1_Iv9ij5i1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_34);
extern NI32 typeDefaultKind_0_runot4689(Cursor_0_nifb6mq6y1 typ_0);
extern LongString_0_sysvq0asl const strlit_0_I18086024188298164462_buiyylk1h1;
extern LongString_0_sysvq0asl const strlit_0_I14727864736786204059_buiyylk1h1;
extern string_0_sysvq0asl enumFieldName_0_runot4689(NU32 enumType_0, NI32 ord_0);
extern NB8 hasImportc_0_hlc70y78v(Cursor_0_nifb6mq6y1 pragmasCur_3);
static inline void eQwasMoved_1_Ix88qzs1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1* s_35);
extern NU32 enumTypeOfField_0_runot4689(NU32 fieldSym_0);
static inline void eQwasMoved_1_I2k4kel_ast8ri79k(seq_0_In6doa_ast8ri79k* s_66);
extern void eQwasmovedQ_SX50roc0chu5m1rja1_0_chu5m1rja1(Proc_0_chu5m1rja1* dest_0);
extern NB8 isInterceptedForeign_0_runot4689(string_0_sysvq0asl base_4);
extern void eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1(Proc_0_chu5m1rja1* dest_0);
extern seq_0_Idl3iy1_comaa5xpt1 loadVTable_0_vtanlalcx(NU32 typ_0);
extern NB8 isGenericRoutine_0_runot4689(NU32 fn_0);
extern NU32 objBaseSym_0_runot4689(NU32 typeSym_0);
extern void eQwasmovedQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1(VmProgram_0_chu5m1rja1* dest_0);
static inline seq_0_Inaua171_chu5m1rja1 newSeqUninit_0_Isa1q0a_chu5m1rja1(NI32 size_34);
static inline seq_0_I50urnw_chu5m1rja1 newSeqUninit_0_I8oufjc_chu5m1rja1(NI32 size_36);
static inline seq_0_Ie9rikd_chu5m1rja1 newSeqUninit_0_Iqh1pff1_chu5m1rja1(NI32 size_38);
static inline seq_0_Iknt7a3_chu5m1rja1 newSeqUninit_0_I16oi801_chu5m1rja1(NI32 size_40);
static inline seq_0_Ixdx2fh1_ast8ri79k newSeqUninit_0_Im3cqd9_ast8ri79k(NI32 size_20);
static inline seq_0_Id5h4uf_chu5m1rja1 newSeqUninit_0_Ii76u2d1_chu5m1rja1(NI32 size_44);
static inline seq_0_I2neof81_chu5m1rja1 newSeqUninit_0_In1bf9z_chu5m1rja1(NI32 size_46);
static inline seq_0_Isww99s_chu5m1rja1 newSeqUninit_0_Iuxy4sp1_chu5m1rja1(NI32 size_48);
static inline seq_0_Iioxqbu_chu5m1rja1 newSeqUninit_0_Iqy0tna1_chu5m1rja1(NI32 size_54);
static inline seq_0_Ir067xu1_chu5m1rja1 newSeqUninit_0_Im7kjnr_chu5m1rja1(NI32 size_50);
static inline seq_0_I88k8j01_chu5m1rja1 newSeqUninit_0_I0s7mv21_chu5m1rja1(NI32 size_52);
extern void eQdestroyQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1(VmProgram_0_chu5m1rja1* dest_0);
extern seq_0_Inaua171_chu5m1rja1 eQdup_1_Iz0ujbh_chu5m1rja1(seq_0_Inaua171_chu5m1rja1 a_17);
extern seq_0_I50urnw_chu5m1rja1 eQdup_1_I28mx5s1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 a_18);
extern seq_0_Ie9rikd_chu5m1rja1 eQdup_1_Ivlbiyc_chu5m1rja1(seq_0_Ie9rikd_chu5m1rja1 a_19);
extern seq_0_Iknt7a3_chu5m1rja1 eQdup_1_Iivi5nx1_chu5m1rja1(seq_0_Iknt7a3_chu5m1rja1 a_20);
extern seq_0_Ixdx2fh1_ast8ri79k eQdup_1_Imq0s4c_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k a_10);
extern seq_0_Id5h4uf_chu5m1rja1 eQdup_1_I00ryxj_chu5m1rja1(seq_0_Id5h4uf_chu5m1rja1 a_22);
extern seq_0_I2neof81_chu5m1rja1 eQdup_1_I09s8x31_chu5m1rja1(seq_0_I2neof81_chu5m1rja1 a_23);
extern seq_0_Isww99s_chu5m1rja1 eQdup_1_I41eryb1_chu5m1rja1(seq_0_Isww99s_chu5m1rja1 a_24);
extern seq_0_Ir067xu1_chu5m1rja1 eQdup_1_I85r9nd1_chu5m1rja1(seq_0_Ir067xu1_chu5m1rja1 a_25);
extern seq_0_I88k8j01_chu5m1rja1 eQdup_1_Ishf7nq1_chu5m1rja1(seq_0_I88k8j01_chu5m1rja1 a_26);
static inline void eQwasMoved_1_Iwfxwnm_chu5m1rja1(seq_0_Inaua171_chu5m1rja1* s_38);
extern seq_0_Iioxqbu_chu5m1rja1 eQdup_1_Iwrxt2p_chu5m1rja1(seq_0_Iioxqbu_chu5m1rja1 a_27);
extern void eQdestroy_1_Iwhufig1_chu5m1rja1(seq_0_Inaua171_chu5m1rja1 s_37);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_70);
extern LongString_0_sysvq0asl const strlit_0_I5736347696189397304_ast8ri79k;
static inline NI32 capInBytes_0_Iev6wua1_ast8ri79k(seq_0_In6doa_ast8ri79k s_73);
extern NB8 resize_0_I6ho9ve_buiyylk1h1(seq_0_In6doa_ast8ri79k* dest_8, NI32 addedElements_8);
static inline NI32 capInBytes_0_Iet286n_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_72);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI32 value_0);
static inline NI32 capInBytes_0_Io1cymi_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1 s_71);
static inline NI32 capInBytes_0_Ihvsegh1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 s_74);
static inline NI32 capInBytes_0_I02yj151_chu5m1rja1(seq_0_Ie9rikd_chu5m1rja1 s_75);
static inline NI32 capInBytes_0_Iccedzq_chu5m1rja1(seq_0_Iknt7a3_chu5m1rja1 s_76);
static inline NI32 capInBytes_0_Ihi6tep_chu5m1rja1(seq_0_Id5h4uf_chu5m1rja1 s_78);
static inline NI32 capInBytes_0_I27hxyl_chu5m1rja1(seq_0_I2neof81_chu5m1rja1 s_79);
extern void eQdestroyQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(ObjInfo_0_chu5m1rja1 dest_0);
extern void* alloc_1_sysvq0asl(NI32 size_24);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_ast8ri79k;
extern X60Qt_0_IAiS32ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI32 capInBytes_0_Ifvg4nq1_chu5m1rja1(seq_0_Inaua171_chu5m1rja1 s_73);
static inline NI32 capInBytes_0_I38sirs1_chu5m1rja1(seq_0_Iioxqbu_chu5m1rja1 s_83);
extern void eQdestroyQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1(GlobalSeed_0_chu5m1rja1* dest_0);
static inline NI32 capInBytes_0_Ivj8jl41_chu5m1rja1(seq_0_Ir067xu1_chu5m1rja1 s_81);
static inline NI32 nimIcheckB(NI32 i_19, NI32 b_22);
static inline NI32 capInBytes_0_I6qhu63_chu5m1rja1(seq_0_I88k8j01_chu5m1rja1 s_82);
static inline NI32 recalcCap_0_sysvq0asl(NI32 oldCap_0, NI32 addedElements_0);
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33);
extern void* realloc_1_sysvq0asl(void* p_19, NI32 size_26);
static inline NI32 memSizeInBytes_0_I58le2f1_chu5m1rja1(NI32 size_31);
static inline NI32 memSizeInBytes_0_Itmy7ww1_chu5m1rja1(NI32 size_37);
static inline NI32 memSizeInBytes_0_Ikrq3db1_chu5m1rja1(NI32 size_39);
static inline NI32 memSizeInBytes_0_I3p8ndy_chu5m1rja1(NI32 size_41);
static inline NI32 memSizeInBytes_0_Ifccb5x1_chu5m1rja1(NI32 size_45);
static inline NI32 memSizeInBytes_0_I6hayax_chu5m1rja1(NI32 size_47);
extern NI32 allocatedSize_0_sysvq0asl(void* p_21);
static inline NI32 memSizeInBytes_0_Iq7wi6a_chu5m1rja1(NI32 size_35);
static inline NI32 memSizeInBytes_0_Iywqtuz_chu5m1rja1(NI32 size_55);
static inline NI32 memSizeInBytes_0_Iqssf4e1_chu5m1rja1(NI32 size_51);
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168);
static inline NI32 min_2_sysvq0asl(NI32 x_204, NI32 y_161);
static inline NI32 memSizeInBytes_0_Ij5c7dh1_chu5m1rja1(NI32 size_53);
extern void dealloc_1_sysvq0asl(void* p_20);
extern void eQdestroy_1_Ipa2mag1_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1 s_31);
extern void eQdestroy_1_Ivioh0a_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_46);
extern void eQdestroy_1_Id0rxta_chu5m1rja1(seq_0_I88k8j01_chu5m1rja1 s_64);
extern void eQdestroy_1_Ivzn3k81_chu5m1rja1(seq_0_Ir067xu1_chu5m1rja1 s_61);
extern void eQdestroy_1_I6lze041_chu5m1rja1(seq_0_Iioxqbu_chu5m1rja1 s_67);
extern void eQdestroy_1_Iymp2mv1_chu5m1rja1(seq_0_Isww99s_chu5m1rja1 s_58);
extern void eQdestroy_1_Icae6hi1_chu5m1rja1(seq_0_I2neof81_chu5m1rja1 s_55);
extern void eQdestroy_1_Iwyaew9_chu5m1rja1(seq_0_Id5h4uf_chu5m1rja1 s_52);
extern void eQdestroy_1_Ik9jljs1_chu5m1rja1(seq_0_Iknt7a3_chu5m1rja1 s_46);
extern void eQdestroy_1_Is2um9k1_chu5m1rja1(seq_0_Ie9rikd_chu5m1rja1 s_43);
extern void eQdestroy_1_Inxd7ue1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 s_40);
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1);
extern void deallocFixed_0_sysvq0asl(void* p_22);
static inline void arcInc_0_sysvq0asl(NI32* memLoc_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_modzy18mg1(void);
extern void X60Qini_0_nifb6mq6y1(void);
extern void X60Qini_0_nifh7u8pu1(void);
extern void X60Qini_0_nif81dubp1(void);
extern void X60Qini_0_nim30udrv(void);
extern void X60Qini_0_nimry5ra91(void);
extern void X60Qini_0_cal1yym9t1(void);
extern void X60Qini_0_decqocs071(void);
extern void X60Qini_0_prorcx25w1(void);
extern void X60Qini_0_symkyk35i1(void);
extern void X60Qini_0_xinat3x34(void);
extern void X60Qini_0_buiyylk1h1(void);
extern void X60Qini_0_linxafkvx1(void);
extern void X60Qini_0_valzr1t4f(void);
extern void X60Qini_0_chu5m1rja1(void);
extern void X60Qini_0_runot4689(void);
extern void X60Qini_0_siz2wt1it(void);
extern void X60Qini_0_flaksyopx1(void);
extern void X60Qini_0_fiepkwzpc(void);
extern void X60Qini_0_vtanlalcx(void);
extern void X60Qini_0_hlc70y78v(void);
extern void X60Qini_0_hlld75j0s(void);
static inline PackedToken_0_nifh7u8pu1 load_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_3);
static inline NU32 tagId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_15);
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2);
static inline NI32 capInBytes_0_Ih2sbn01_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_28);
extern NB8 resize_0_I4buliy_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* dest_2, NI32 addedElements_2);
static inline NU32 intId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_12);
static inline NI64* getQ_7_Ite3z0o_ast8ri79k(seq_0_Iotb7mc_ast8ri79k s_9, NI32 i_6);
static inline NU32 symId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_11);
static inline NU32 litId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_9);
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14);
static inline NB8 rawTagIsNimonySym_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_5);
extern LongString_0_sysvq0asl const strlit_0_I17128882682348225350_nifb6mq6y1;
static inline NI32 memSizeInBytes_0_Ivqzo5x1_ast8ri79k(NI32 size_33);
static inline NU32 uintId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_13);
static inline NU64* getQ_7_Ifaxado1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_10, NI32 i_7);
static inline NU32 floatId_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_14);
static inline NU64* getQ_0_I3qz68f_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_14, NU32 litId_13);
static inline NC8 charLit_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_10);
static inline NimonyExpr_0_nimry5ra91 exprKind_0_nim30udrv(PackedToken_0_nifh7u8pu1 c_9);
extern LongString_0_sysvq0asl const strlit_0_I5239124994330926419_sysvq0asl;
static inline NI32 memSizeInBytes_0_I7me00i_ast8ri79k(NI32 size_4);
static inline NI32 memSizeInBytes_0_Ie1nwe7_chu5m1rja1(NI32 size_49);
extern void raiseIndexError3_0_I113jpc1_sysvq0asl(NI32 i_68, NI32 a_83, NI32 b_38);
extern string_0_sysvq0asl dollarX60Q_NifKind_0_nif81dubp1(NifKind_0_nif81dubp1 e_0);
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16);
static inline NB8 rawTagIsNimonyExpr_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_0);
extern NU32 const ErrT_0_nifh7u8pu1;
LongString_0_sysvq0asl const strlit_0_I16971225136864641703_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "closure"}
;
LongString_0_sysvq0asl const strlit_0_I8800776328647009306_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "passive"}
;
LongString_0_sysvq0asl const strlit_0_I9071657656589967445_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "iterator"}
;
LongString_0_sysvq0asl const strlit_0_I5316556160589403975_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "proc"}
;
LongString_0_sysvq0asl const strlit_0_I9991102891510134496_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "func"}
;
LongString_0_sysvq0asl const strlit_0_I6517805684605582485_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "method"}
;
LongString_0_sysvq0asl const strlit_0_I6864681898360807206_comaa5xpt1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "converter"}
;
LongString_0_sysvq0asl const strlit_0_I3777428167486794959_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "macro"}
;
LongString_0_sysvq0asl const strlit_0_I17987658270787974407_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "template"}
;
LongString_0_sysvq0asl const strlit_0_I13413619771642637377_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "type"}
;
LongString_0_sysvq0asl const strlit_0_I10578126245728228512_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "import"}
;
LongString_0_sysvq0asl const strlit_0_I16948548629793503007_comaa5xpt1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "importexcept"}
;
LongString_0_sysvq0asl const strlit_0_I15371509460875483150_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "from"}
;
LongString_0_sysvq0asl const strlit_0_I3312144845751804851_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "include"}
;
LongString_0_sysvq0asl const strlit_0_I6313045265747232047_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "export"}
;
LongString_0_sysvq0asl const strlit_0_I18257730313531980409_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "comment"}
;
LongString_0_sysvq0asl const strlit_0_I7023501325319911082_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pragmas"}
;
LongString_0_sysvq0asl const strlit_0_I15803870852433253359_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "using"}
;
LongString_0_sysvq0asl const strlit_0_I11023901819970991276_comaa5xpt1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "setScheduler"}
;
LongString_0_sysvq0asl const strlit_0_I2171368188661376471_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "efld"}
;
LongString_0_sysvq0asl const strlit_0_I5723805845286553140_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "glet"}
;
LongString_0_sysvq0asl const strlit_0_I1281801651151844468_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "gvar"}
;
LongString_0_sysvq0asl const strlit_0_I13046452236886743244_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tvar"}
;
LongString_0_sysvq0asl const strlit_0_I2681092370707159476_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "asgn"}
;
LongString_0_sysvq0asl const strlit_0_I13752166055203769914_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "stmts"}
;
LongString_0_sysvq0asl const strlit_0_I1990248930136438291_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "stdout"}
;
LongString_0_sysvq0asl const strlit_0_I9873340078075426535_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "stderr"}
;
LongString_0_sysvq0asl const strlit_0_I14266456148715147463_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "stdin"}
;
LongString_0_sysvq0asl const strlit_0_I12999086881046019782_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "const"}
;
LongString_0_sysvq0asl const strlit_0_I4543393450896359795_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "baseobj"}
;
LongString_0_sysvq0asl const strlit_0_I17573272885368898989_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "aconstr"}
;
LongString_0_sysvq0asl const strlit_0_I9217337746930322866_comaa5xpt1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "callstrlit"}
;
LongString_0_sysvq0asl const strlit_0_I8939511674443647382_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "deref"}
;
LongString_0_sysvq0asl const strlit_0_I6041839086284145320_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bitnot"}
;
LongString_0_sysvq0asl const strlit_0_I9830314142150548690_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "block"}
;
LongString_0_sysvq0asl const strlit_0_I14055597598996035090_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "bracket"}
;
LongString_0_sysvq0asl const strlit_0_I3001676635385606767_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arrat"}
;
LongString_0_sysvq0asl const strlit_0_I7330775407653057337_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "emove"}
;
LongString_0_sysvq0asl const strlit_0_I17580784255599249694_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "eqset"}
;
LongString_0_sysvq0asl const strlit_0_I3372626016653902757_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "false"}
;
LongString_0_sysvq0asl const strlit_0_I14845204679832807538_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "failed"}
;
LongString_0_sysvq0asl const strlit_0_I12061648672903694946_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hcall"}
;
LongString_0_sysvq0asl const strlit_0_I17469384850928897790_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "haddr"}
;
LongString_0_sysvq0asl const strlit_0_I4196580491060784277_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hderef"}
;
LongString_0_sysvq0asl const strlit_0_I4161172010043268705_comaa5xpt1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "instanceof"}
;
LongString_0_sysvq0asl const strlit_0_I17286088029172964552_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "inset"}
;
LongString_0_sysvq0asl const strlit_0_I7755216903854853291_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "leset"}
;
LongString_0_sysvq0asl const strlit_0_I6438757400198936067_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ltset"}
;
LongString_0_sysvq0asl const strlit_0_I896709357113617264_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "minusset"}
;
LongString_0_sysvq0asl const strlit_0_I6462229405280805082_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mulset"}
;
LongString_0_sysvq0asl const strlit_0_I186799702831424311_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "neginf"}
;
LongString_0_sysvq0asl const strlit_0_I7084116572891045059_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "oconstr"}
;
LongString_0_sysvq0asl const strlit_0_I12337342044224817361_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "newobj"}
;
LongString_0_sysvq0asl const strlit_0_I9268166327583521131_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "newref"}
;
LongString_0_sysvq0asl const strlit_0_I6487260469238205337_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "paren"}
;
LongString_0_sysvq0asl const strlit_0_I12557166611382145809_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "plusset"}
;
LongString_0_sysvq0asl const strlit_0_I8954722698363393223_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "prefix"}
;
LongString_0_sysvq0asl const strlit_0_I3485566669610392440_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "proccall"}
;
LongString_0_sysvq0asl const strlit_0_I7358334719788826533_comaa5xpt1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "setconstr"}
;
LongString_0_sysvq0asl const strlit_0_I14042222260391466396_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sizeof"}
;
LongString_0_sysvq0asl const strlit_0_I17716058327968275251_comaa5xpt1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tupconstr"}
;
LongString_0_sysvq0asl const strlit_0_I5323221927989235116_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "tupat"}
;
LongString_0_sysvq0asl const strlit_0_I11168045910199617169_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "xorset"}
;
LongString_0_sysvq0asl const strlit_0_I1707222714195181991_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "call"}
;
LongString_0_sysvq0asl const strlit_0_I655215872312446365_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "card"}
;
LongString_0_sysvq0asl const strlit_0_I13909093427330098489_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cast"}
;
LongString_0_sysvq0asl const strlit_0_I4956278306908871092_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "case"}
;
LongString_0_sysvq0asl const strlit_0_I710932595938440230_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hconv"}
;
LongString_0_sysvq0asl const strlit_0_I9667346611828510523_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "dconv"}
;
LongString_0_sysvq0asl const strlit_0_I9557201018976274010_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "addr"}
;
LongString_0_sysvq0asl const strlit_0_I14457488926480995039_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ddot"}
;
LongString_0_sysvq0asl const strlit_0_I2501487269769466366_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "conv"}
;
LongString_0_sysvq0asl const strlit_0_I10209608037894561257_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "curly"}
;
LongString_0_sysvq0asl const strlit_0_I14418907618963914168_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "delay0"}
;
LongString_0_sysvq0asl const strlit_0_I358872489388858575_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "delay"}
;
LongString_0_sysvq0asl const strlit_0_I13798915436014509391_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "expr"}
;
LongString_0_sysvq0asl const strlit_0_I8390060478375454995_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "infix"}
;
LongString_0_sysvq0asl const strlit_0_I17583757001664695776_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "move"}
;
LongString_0_sysvq0asl const strlit_0_I8572766038233537570_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "true"}
;
LongString_0_sysvq0asl const strlit_0_I12477614342947401988_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "data"}
;
LongString_0_sysvq0asl const strlit_0_I7514604024534592575_comaa5xpt1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readRawData"}
;
LongString_0_sysvq0asl const strlit_0_I7466143617196742693_comaa5xpt1 = {
  .fullLen_0 = 17, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "readRawDataStable"}
;
LongString_0_sysvq0asl const strlit_0_I10157464168546919252_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "=destroy"}
;
LongString_0_sysvq0asl const strlit_0_I11614359337083319489_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "=dup"}
;
LongString_0_sysvq0asl const strlit_0_I14683201540015467042_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "=copy"}
;
LongString_0_sysvq0asl const strlit_0_I17069683611453604721_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "=sink"}
;
LongString_0_sysvq0asl const strlit_0_I9151517089334711309_comaa5xpt1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "=wasMoved"}
;
LongString_0_sysvq0asl const strlit_0_I7262382801534885590_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "=trace"}
;
LongString_0_sysvq0asl const strlit_0_I5348593791521339691_comaa5xpt1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "allocFixed"}
;
LongString_0_sysvq0asl const strlit_0_I13537887754319196487_comaa5xpt1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "allocFixed0"}
;
LongString_0_sysvq0asl const strlit_0_I930249616028346462_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arcInc"}
;
LongString_0_sysvq0asl const strlit_0_I4547290982746310667_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arcDec"}
;
LongString_0_sysvq0asl const strlit_0_I2856626897374252538_comaa5xpt1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "arcIsUnique"}
;
LongString_0_sysvq0asl const strlit_0_I3225684998187034911_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "newSeq"}
;
LongString_0_sysvq0asl const strlit_0_I11042971208590088895_comaa5xpt1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "newSeqUninit"}
;
LongString_0_sysvq0asl const strlit_0_I15541155848264557133_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "initPool"}
;
LongString_0_sysvq0asl const strlit_0_I3798637678053249641_comaa5xpt1 = {
  .fullLen_0 = 13, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "ensureParPool"}
;
LongString_0_sysvq0asl const strlit_0_I16581638230773281198_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "submit"}
;
LongString_0_sysvq0asl const strlit_0_I1232877487365112244_comaa5xpt1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "parSubmit"}
;
LongString_0_sysvq0asl const strlit_0_I8602794362013704992_comaa5xpt1 = {
  .fullLen_0 = 12, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "shutdownPool"}
;
LongString_0_sysvq0asl const strlit_0_I11010039520288330211_comaa5xpt1 = {
  .fullLen_0 = 11, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "poolStopped"}
;
LongString_0_sysvq0asl const strlit_0_I10257712218960831919_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "poolHelp"}
;
LongString_0_sysvq0asl const strlit_0_I12770529794932993973_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "parWait"}
;
LongString_0_sysvq0asl const strlit_0_I13045133590002807130_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "complete"}
;
LongString_0_sysvq0asl const strlit_0_I9592449470941440445_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "open"}
;
LongString_0_sysvq0asl const strlit_0_I17711552707752383867_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "hash"}
;
LongString_0_sysvq0asl const strlit_0_I3021806080610957510_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "distinct"}
;
LongString_0_sysvq0asl const strlit_0_I10462096440466995513_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "enum"}
;
LongString_0_sysvq0asl const strlit_0_I3225181402180923291_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "onum"}
;
LongString_0_sysvq0asl const strlit_0_I6300154543333844069_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pointer"}
;
LongString_0_sysvq0asl const strlit_0_I1177603226064417776_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "array"}
;
LongString_0_sysvq0asl const strlit_0_I16597999082088934835_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "range"}
;
LongString_0_sysvq0asl const strlit_0_I4167480082662538754_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "else"}
;
LongString_0_sysvq0asl const strlit_0_I13424873862977158440_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "elif"}
;
LongString_0_sysvq0asl const strlit_0_I973692718279674627_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "object"}
;
LongString_0_sysvq0asl const strlit_0_I4511345809429878981_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "string"}
;
LongString_0_sysvq0asl const strlit_0_I16393544569146403439_comaa5xpt1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "rangetype"}
;
LongString_0_sysvq0asl const strlit_0_I1237672436915077942_comaa5xpt1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "unpacktup"}
;
LongString_0_sysvq0asl const strlit_0_I1074026605013007683_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "items"}
;
LongString_0_sysvq0asl const strlit_0_I749353374909415178_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mitems"}
;
LongString_0_sysvq0asl const strlit_0_I10146300619167329886_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pairs"}
;
LongString_0_sysvq0asl const strlit_0_I16434641538762240521_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "mpairs"}
;
LongString_0_sysvq0asl const strlit_0_I9792473688321036479_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "param"}
;
LongString_0_sysvq0asl const strlit_0_I17735862253056247523_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "cursor"}
;
LongString_0_sysvq0asl const strlit_0_I16264910594287870354_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "except"}
;
LongString_0_sysvq0asl const strlit_0_I8380221545607033154_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "break"}
;
LongString_0_sysvq0asl const strlit_0_I2210116261907819816_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "continue"}
;
LongString_0_sysvq0asl const strlit_0_I2956720964102846418_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "discard"}
;
LongString_0_sysvq0asl const strlit_0_I2784804726569183623_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "excl"}
;
LongString_0_sysvq0asl const strlit_0_I17199005983847516849_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "pragmax"}
;
LongString_0_sysvq0asl const strlit_0_I14732757010146030568_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "incl"}
;
LongString_0_sysvq0asl const strlit_0_I2416437014800228590_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "result"}
;
LongString_0_sysvq0asl const strlit_0_I6137881024046402116_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "raise"}
;
LongString_0_sysvq0asl const strlit_0_I3786558325628924612_comaa5xpt1 = {
  .fullLen_0 = 10, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "patternvar"}
;
LongString_0_sysvq0asl const strlit_0_I11512946405431690565_comaa5xpt1 = {
  .fullLen_0 = 7, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "suspend"}
;
LongString_0_sysvq0asl const strlit_0_I13200118161122656888_comaa5xpt1 = {
  .fullLen_0 = 5, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "while"}
;
LongString_0_sysvq0asl const strlit_0_I10163392937326623266_comaa5xpt1 = {
  .fullLen_0 = 8, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "wasmoved"}
;
LongString_0_sysvq0asl const strlit_0_I10356331269374273950_comaa5xpt1 = {
  .fullLen_0 = 16, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "keepOverflowFlag"}
;
LongString_0_sysvq0asl const strlit_0_I5595596763809202512_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "sink"}
;
LongString_0_sysvq0asl const strlit_0_I6008424852838151324_comaa5xpt1 = {
  .fullLen_0 = 4, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "lent"}
;
LongString_0_sysvq0asl const strlit_0_I14469962976530872646_comaa5xpt1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "openarray"}
;
LongString_0_sysvq0asl const strlit_0_I4271430978068613410_comaa5xpt1 = {
  .fullLen_0 = 9, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "openArray"}
;
LongString_0_sysvq0asl const strlit_0_I5065733472155119234_comaa5xpt1 = {
  .fullLen_0 = 6, .rc_0 = 0, .capImpl_0 = 0, .data_0 = ".s.nif"}
;
LongString_0_sysvq0asl const strlit_0_I767816010166080526_comaa5xpt1 = {
  .fullLen_0 = 113, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/seqimpl.nim(169, 53): i < s.len and 0 <= i [AssertionDefect]\012"}
;
LongString_0_sysvq0asl const strlit_0_I3193426178656842898_comaa5xpt1 = {
  .fullLen_0 = 119, .rc_0 = 0, .capImpl_0 = 0, .data_0 = "../../../../../../home/savant/nimony/lib/std/system/openarrays.nim(10, 49): 0 <= idx and idx < x.len [AssertionDefect]\012"}
;
NB8 X60QiniGuard_0_comaa5xpt1;
NI32 find_0_comaa5xpt1(SymMap_0_comaa5xpt1 m_0, NU32 s_0){
  NI32 result_0;
  result_0 = -1;
  NI32 i_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_128 = len_3_I6y2imo_buiyylk1h1(m_0.keys_0);
      if (i_0 < X60Qx_128){
        NU32* X60Qx_129 = getQ_7_I2v00yv1_buiyylk1h1(m_0.keys_0, i_0);
        NB8 X60Qx_130 = eqQ_0_nifh7u8pu1((*X60Qx_129), s_0);
        if (X60Qx_130){
          return i_0;}
        inc_1_I6wjjge_aow2h993l1((&i_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_0;}
NI32 get_0_comaa5xpt1(SymMap_0_comaa5xpt1 m_1, NU32 s_1){
  NI32 result_1;
  NI32 i_2 = find_0_comaa5xpt1(m_1, s_1);
  if (0 <= i_2){
    NI32* X60Qx_131 = getQ_7_Ir8kccm_comaa5xpt1(m_1.vals_0, i_2);
    result_1 = (*X60Qx_131);}
  else {
    result_1 = -1;}
  return result_1;}
void put_0_comaa5xpt1(SymMap_0_comaa5xpt1* m_2, NU32 s_2, NI32 v_0){
  NI32 i_4 = find_0_comaa5xpt1((*m_2), s_2);
  if (0 <= i_4){
    putQ_7_Ifvyck5_comaa5xpt1((&(*m_2).vals_0), i_4, v_0);}
  else {
    add_0_I34il1q_comaa5xpt1((&(*m_2).keys_0), s_2);
    add_0_I8kd4i4_comaa5xpt1((&(*m_2).vals_0), v_0);}}
NI32 symIndex_0_comaa5xpt1(seq_0_In6doa_ast8ri79k xs_0, NU32 s_3){
  NI32 result_2;
  result_2 = -1;
  NI32 i_6 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_132 = len_3_I6y2imo_buiyylk1h1(xs_0);
      if (i_6 < X60Qx_132){
        NU32* X60Qx_133 = getQ_7_I2v00yv1_buiyylk1h1(xs_0, i_6);
        NB8 X60Qx_134 = eqQ_0_nifh7u8pu1((*X60Qx_133), s_3);
        if (X60Qx_134){
          return i_6;}
        inc_1_I6wjjge_aow2h993l1((&i_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_2;}
NB8 routineHasClosureOrPassive_0_comaa5xpt1(Cursor_0_nifb6mq6y1 cur_0){
  NB8 result_3;
  Routine_0_decqocs071 r_0 = asRoutine_0_decqocs071(cur_0, 1);
  Cursor_0_nifb6mq6y1 p_0 = r_0.pragmas_0;
  eQwasMoved_0_nifb6mq6y1((&r_0.pragmas_0));
  NifKind_0_nif81dubp1 X60Qx_135 = kind_0_nifb6mq6y1(p_0);
  if ((!(X60Qx_135 == 11))){
    eQdestroy_0_nifb6mq6y1((&p_0));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_0));
    return NIM_FALSE;}
  inc_0_nifb6mq6y1((&p_0));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_136 = kind_0_nifb6mq6y1(p_0);
      if ((!(X60Qx_136 == 12))){
        NifKind_0_nif81dubp1 X60Qx_137 = kind_0_nifb6mq6y1(p_0);
        if (X60Qx_137 == 11){
          NU32 X60Qx_138 = tagId_0_nifb6mq6y1(p_0);
          string_0_sysvq0asl* X60Qx_139 = getQ_0_I93d71y_comaa5xpt1(pool_0_nifh7u8pu1.tags_0, X60Qx_138);
          string_0_sysvq0asl t_1 = nimStrDup((*X60Qx_139));
          NB8 X60Qx_140;
          NB8 X60Qx_141 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
            .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I16971225136864641703_comaa5xpt1)}
          );
          if (X60Qx_141){
            X60Qx_140 = NIM_TRUE;}
          else {
            NB8 X60Qx_142 = eqQ_20_sysvq0asl(t_1, (string_0_sysvq0asl){
              .bytes_0 = 1935765758u, .more_0 = (&strlit_0_I8800776328647009306_comaa5xpt1)}
            );
            X60Qx_140 = X60Qx_142;}
          if (X60Qx_140){
            nimStrDestroy(t_1);
            eQdestroy_0_nifb6mq6y1((&p_0));
            eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_0));
            return NIM_TRUE;}
          nimStrDestroy(t_1);}
        skip_0_nifb6mq6y1((&p_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&p_0));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_0));
  return NIM_FALSE;
  eQdestroy_0_nifb6mq6y1((&p_0));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_0));
  return result_3;
  eQdestroy_0_nifb6mq6y1((&p_0));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_0));
  return result_3;}
NB8 routineIsClosureIter_0_comaa5xpt1(Cursor_0_nifb6mq6y1 cur_1){
  NB8 result_4;
  NU32 X60Qx_143 = tagId_0_nifb6mq6y1(cur_1);
  string_0_sysvq0asl* X60Qx_144 = getQ_0_I93d71y_comaa5xpt1(pool_0_nifh7u8pu1.tags_0, X60Qx_143);
  NB8 X60Qx_145 = eqQ_20_sysvq0asl((*X60Qx_144), (string_0_sysvq0asl){
    .bytes_0 = 1702128126u, .more_0 = (&strlit_0_I9071657656589967445_comaa5xpt1)}
  );
  if ((!X60Qx_145)){
    return NIM_FALSE;}
  Routine_0_decqocs071 r_1 = asRoutine_0_decqocs071(cur_1, 1);
  Cursor_0_nifb6mq6y1 p_1 = r_1.pragmas_0;
  eQwasMoved_0_nifb6mq6y1((&r_1.pragmas_0));
  NifKind_0_nif81dubp1 X60Qx_146 = kind_0_nifb6mq6y1(p_1);
  if ((!(X60Qx_146 == 11))){
    eQdestroy_0_nifb6mq6y1((&p_1));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
    return NIM_FALSE;}
  inc_0_nifb6mq6y1((&p_1));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_147 = kind_0_nifb6mq6y1(p_1);
      if ((!(X60Qx_147 == 12))){
        NB8 X60Qx_148;
        NifKind_0_nif81dubp1 X60Qx_149 = kind_0_nifb6mq6y1(p_1);
        if (X60Qx_149 == 11){
          NU32 X60Qx_150 = tagId_0_nifb6mq6y1(p_1);
          string_0_sysvq0asl* X60Qx_151 = getQ_0_I93d71y_comaa5xpt1(pool_0_nifh7u8pu1.tags_0, X60Qx_150);
          NB8 X60Qx_152 = eqQ_20_sysvq0asl((*X60Qx_151), (string_0_sysvq0asl){
            .bytes_0 = 1869374462u, .more_0 = (&strlit_0_I16971225136864641703_comaa5xpt1)}
          );
          X60Qx_148 = X60Qx_152;}
        else {
          X60Qx_148 = NIM_FALSE;}
        if (X60Qx_148){
          eQdestroy_0_nifb6mq6y1((&p_1));
          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
          return NIM_TRUE;}
        skip_0_nifb6mq6y1((&p_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&p_1));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
  return NIM_FALSE;
  eQdestroy_0_nifb6mq6y1((&p_1));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
  return result_4;
  eQdestroy_0_nifb6mq6y1((&p_1));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_1));
  return result_4;}
NB8 routineIsPassive_0_comaa5xpt1(Cursor_0_nifb6mq6y1 cur_2){
  NB8 result_5;
  Routine_0_decqocs071 r_2 = asRoutine_0_decqocs071(cur_2, 1);
  Cursor_0_nifb6mq6y1 p_2 = r_2.pragmas_0;
  eQwasMoved_0_nifb6mq6y1((&r_2.pragmas_0));
  NifKind_0_nif81dubp1 X60Qx_153 = kind_0_nifb6mq6y1(p_2);
  if ((!(X60Qx_153 == 11))){
    eQdestroy_0_nifb6mq6y1((&p_2));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_2));
    return NIM_FALSE;}
  inc_0_nifb6mq6y1((&p_2));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_154 = kind_0_nifb6mq6y1(p_2);
      if ((!(X60Qx_154 == 12))){
        NB8 X60Qx_155;
        NifKind_0_nif81dubp1 X60Qx_156 = kind_0_nifb6mq6y1(p_2);
        if (X60Qx_156 == 11){
          NU32 X60Qx_157 = tagId_0_nifb6mq6y1(p_2);
          string_0_sysvq0asl* X60Qx_158 = getQ_0_I93d71y_comaa5xpt1(pool_0_nifh7u8pu1.tags_0, X60Qx_157);
          NB8 X60Qx_159 = eqQ_20_sysvq0asl((*X60Qx_158), (string_0_sysvq0asl){
            .bytes_0 = 1935765758u, .more_0 = (&strlit_0_I8800776328647009306_comaa5xpt1)}
          );
          X60Qx_155 = X60Qx_159;}
        else {
          X60Qx_155 = NIM_FALSE;}
        if (X60Qx_155){
          eQdestroy_0_nifb6mq6y1((&p_2));
          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_2));
          return NIM_TRUE;}
        skip_0_nifb6mq6y1((&p_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&p_2));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_2));
  return NIM_FALSE;
  eQdestroy_0_nifb6mq6y1((&p_2));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_2));
  return result_5;
  eQdestroy_0_nifb6mq6y1((&p_2));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_2));
  return result_5;}
string_0_sysvq0asl nodeTag_0_comaa5xpt1(Cursor_0_nifb6mq6y1 n_0){
  string_0_sysvq0asl result_6;
  nimStrWasMoved((&result_6));
  nimStrDestroy(result_6);
  NU32 X60Qx_160 = tagId_0_nifb6mq6y1(n_0);
  string_0_sysvq0asl* X60Qx_161 = getQ_0_I93d71y_comaa5xpt1(pool_0_nifh7u8pu1.tags_0, X60Qx_160);
  string_0_sysvq0asl X60Qx_162 = nimStrDup((*X60Qx_161));
  result_6 = X60Qx_162;
  return result_6;}
string_0_sysvq0asl baseName_0_comaa5xpt1(NU32 s_4){
  string_0_sysvq0asl result_7;
  nimStrWasMoved((&result_7));
  nimStrDestroy(result_7);
  string_0_sysvq0asl* X60Qx_163 = getQ_0_In1k2p81_ast8ri79k(pool_0_nifh7u8pu1.syms_0, s_4);
  string_0_sysvq0asl X60Qx_164 = nimStrDup((*X60Qx_163));
  result_7 = X60Qx_164;
  extractBasename_1_symkyk35i1((&result_7));
  return result_7;}
NI32 lineOf_0_comaa5xpt1(Cursor_0_nifb6mq6y1 n_1){
  NI32 result_8;
  NU32 X60Qx_165 = info_0_nifb6mq6y1(n_1);
  LineInfoUnpacked_0_linxafkvx1 X60Qx_166 = unpack_0_linxafkvx1(pool_0_nifh7u8pu1.man_0, X60Qx_165);
  result_8 = ((NI32)X60Qx_166.line_0);
  return result_8;}
NI32 emit_0_comaa5xpt1(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_0, OpCode_0_chu5m1rja1 op_0, NI32 a_0, NI32 b_0){
  NI32 result_9;
  NI32 X60Qx_167 = len_3_Icgec691_comaa5xpt1((*ctx_0).d_00.code_0);
  result_9 = X60Qx_167;
  add_0_Ibh17rk1_comaa5xpt1((&(*ctx_0).d_00.code_0), (Instr_0_chu5m1rja1){
    .op_0 = op_0, .a_0 = a_0, .b_0 = b_0}
  );
  add_0_I8kd4i4_comaa5xpt1((&(*ctx_0).d_00.codeLines_0), (*ctx_0).d_00.curLine_0);
  return result_9;}
void patch_0_comaa5xpt1(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_1, NI32 idx_0, NI32 target_0){
  Instr_0_chu5m1rja1* X60Qx_168 = getQ_7_Iuezo3v1_comaa5xpt1((*ctx_1).d_00.code_0, idx_0);
  Instr_0_chu5m1rja1 ins_0 = (*X60Qx_168);
  ins_0.a_0 = target_0;
  putQ_7_Iko5vvk1_comaa5xpt1((&(*ctx_1).d_00.code_0), idx_0, ins_0);}
void patchB_0_comaa5xpt1(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_2, NI32 idx_1, NI32 target_1){
  Instr_0_chu5m1rja1* X60Qx_169 = getQ_7_Iuezo3v1_comaa5xpt1((*ctx_2).d_00.code_0, idx_1);
  Instr_0_chu5m1rja1 ins_1 = (*X60Qx_169);
  ins_1.b_0 = target_1;
  putQ_7_Iko5vvk1_comaa5xpt1((&(*ctx_2).d_00.code_0), idx_1, ins_1);}
NI32 addConst_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_0, Value_0_valzr1t4f* v_1){
  NI32 result_10;
  NI32 X60Qx_170 = len_3_I4n9kvq_comaa5xpt1((*c_0).d_00.consts_0);
  result_10 = X60Qx_170;
  Value_0_valzr1t4f X60Qx_171 = eQdupQ_SX56alue0valzr1t4f_0_valzr1t4f((&(*v_1)));
  add_0_Itre92n_comaa5xpt1((&(*c_0).d_00.consts_0), X60Qx_171);
  return result_10;}
NI32 newSeqElemDefaultConst_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_1, NU32 sym_0){
  NI32 result_11;
  result_11 = -1;
  LoadResult_0_prorcx25w1 res_0 = tryLoadSymSafe_0_modzy18mg1(sym_0);
  NB8 X60Qx_172;
  if ((!(res_0.status_0 == 3))){
    X60Qx_172 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_173 = kind_0_nifb6mq6y1(res_0.decl_0);
    X60Qx_172 = (!(X60Qx_173 == 11));}
  if (X60Qx_172){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    return result_11;}
  Cursor_0_nifb6mq6y1 d_0 = res_0.decl_0;
  eQwasMoved_0_nifb6mq6y1((&res_0.decl_0));
  inc_0_nifb6mq6y1((&d_0));
  Cursor_0_nifb6mq6y1 elemCur_0 = (Cursor_0_nifb6mq6y1){
    .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
  ;
  NB8 found_0 = NIM_FALSE;
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_174 = kind_0_nifb6mq6y1(d_0);
      if ((!(X60Qx_174 == 12))){
        NB8 X60Qx_53;
        NifKind_0_nif81dubp1 X60Qx_175 = kind_0_nifb6mq6y1(d_0);
        if (X60Qx_175 == 11){
          string_0_sysvq0asl X60Qtmp_0 = nodeTag_0_comaa5xpt1(d_0);
          NB8 X60Qx_176 = eqQ_20_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
            .bytes_0 = 7627010u, .more_0 = NIM_NIL}
          );
          X60Qx_53 = X60Qx_176;
          nimStrDestroy(X60Qtmp_0);}
        else {
          X60Qx_53 = NIM_FALSE;}
        if (X60Qx_53){
          Cursor_0_nifb6mq6y1 a_1 = d_0;
          eQwasMoved_0_nifb6mq6y1((&d_0));
          inc_0_nifb6mq6y1((&a_1));
          skip_0_nifb6mq6y1((&a_1));
          NifKind_0_nif81dubp1 X60Qx_177 = kind_0_nifb6mq6y1(a_1);
          if ((!(X60Qx_177 == 12))){
            eQdestroy_0_nifb6mq6y1((&elemCur_0));
            elemCur_0 = a_1;
            eQwasMoved_0_nifb6mq6y1((&a_1));
            found_0 = NIM_TRUE;}
          eQdestroy_0_nifb6mq6y1((&a_1));
          goto whileStmtLabel_0;
          eQdestroy_0_nifb6mq6y1((&a_1));}
        NifKind_0_nif81dubp1 X60Qx_178 = kind_0_nifb6mq6y1(d_0);
        if (X60Qx_178 == 11){
          skip_0_nifb6mq6y1((&d_0));}
        else {
          inc_0_nifb6mq6y1((&d_0));}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if ((!found_0)){
    eQdestroy_0_nifb6mq6y1((&elemCur_0));
    eQdestroy_0_nifb6mq6y1((&d_0));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
    return result_11;}
  Value_0_valzr1t4f X60Qtmp_1 = defaultForType_1_runot4689(elemCur_0);
  NI32 X60Qx_179 = addConst_0_comaa5xpt1(c_1, (&X60Qtmp_1));
  result_11 = X60Qx_179;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_1));
  eQdestroy_0_nifb6mq6y1((&elemCur_0));
  eQdestroy_0_nifb6mq6y1((&d_0));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_11;
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_1));
  eQdestroy_0_nifb6mq6y1((&elemCur_0));
  eQdestroy_0_nifb6mq6y1((&d_0));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_0);
  return result_11;}
NI32 addMagic_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_2, NimonyExpr_0_nimry5ra91 op_1, NI32 bits_0, NB8 signed_0, NB8 caseEq_0){
  NI32 result_12;
  NI32 X60Qx_180 = len_3_Idcvg0j1_comaa5xpt1((*c_2).d_00.magics_0);
  result_12 = X60Qx_180;
  add_0_Iv446pn1_comaa5xpt1((&(*c_2).d_00.magics_0), (MagicSpec_0_chu5m1rja1){
    .op_0 = op_1, .bits_0 = bits_0, .signed_0 = signed_0, .caseEq_0 = caseEq_0}
  );
  return result_12;}
NI32 addConv_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_3, NI32 mode_0, NI32 bits_1, NB8 signed_1){
  NI32 result_13;
  NI32 X60Qx_181 = len_3_Iiake9l_comaa5xpt1((*c_3).d_00.convs_0);
  result_13 = X60Qx_181;
  add_0_Imr7j74_comaa5xpt1((&(*c_3).d_00.convs_0), (ConvSpec_0_chu5m1rja1){
    .mode_0 = mode_0, .bits_0 = bits_1, .signed_0 = signed_1, .code_0 = 0, .etype_0 = ((NU32)0u)}
  );
  return result_13;}
NI32 addPtrConv_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_4, NI32 bits_2, TCode_0_valzr1t4f code_0, NU32 etype_0){
  NI32 result_14;
  NI32 X60Qx_182 = len_3_Iiake9l_comaa5xpt1((*c_4).d_00.convs_0);
  result_14 = X60Qx_182;
  add_0_Imr7j74_comaa5xpt1((&(*c_4).d_00.convs_0), (ConvSpec_0_chu5m1rja1){
    .mode_0 = 6, .bits_0 = bits_2, .signed_0 = NIM_FALSE, .code_0 = code_0, .etype_0 = etype_0}
  );
  return result_14;}
NI32 addNative_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_5, string_0_sysvq0asl name_0){
  NI32 result_15;
  NI32 i_9 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_183 = len_3_Ixq6taz_comaa5xpt1((*c_5).d_00.natives_0);
      if (i_9 < X60Qx_183){
        string_0_sysvq0asl* X60Qx_184 = getQ_7_Ir6d0tw_ast8ri79k((*c_5).d_00.natives_0, i_9);
        NB8 X60Qx_185 = eqQ_20_sysvq0asl((*X60Qx_184), name_0);
        if (X60Qx_185){
          return i_9;}
        inc_1_I6wjjge_aow2h993l1((&i_9));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_186 = len_3_Ixq6taz_comaa5xpt1((*c_5).d_00.natives_0);
  result_15 = X60Qx_186;
  string_0_sysvq0asl X60Qx_187 = nimStrDup(name_0);
  add_0_Ig6072n_ast8ri79k((&(*c_5).d_00.natives_0), X60Qx_187);
  return result_15;}
NI32 addEnumWrap_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_6, NU32 enumType_0){
  NI32 result_16;
  NI32 X60Qx_188 = len_3_I6y2imo_buiyylk1h1((*c_6).d_00.enumWraps_0);
  result_16 = X60Qx_188;
  add_0_I34il1q_comaa5xpt1((&(*c_6).d_00.enumWraps_0), enumType_0);
  return result_16;}
NI32 addGatedCall_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_7, NI32 natIdx_0, NI32 fallback_0, NB8 dollarScalar_0){
  NI32 result_17;
  NI32 X60Qx_189 = len_3_I18vp0c1_comaa5xpt1((*c_7).d_00.gatedCalls_0);
  result_17 = X60Qx_189;
  add_0_Iybug3z_comaa5xpt1((&(*c_7).d_00.gatedCalls_0), (GatedCall_0_chu5m1rja1){
    .nat_0 = natIdx_0, .fallback_0 = fallback_0, .dollarScalar_0 = dollarScalar_0}
  );
  return result_17;}
NI32 addObjInfo_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_8, NU32 typeSym_0, seq_0_In6doa_ast8ri79k fieldSyms_0){
  NI32 result_18;
  NI32 X60Qx_190 = len_3_Ibeqm1v_comaa5xpt1((*c_8).d_00.objInfos_0);
  result_18 = X60Qx_190;
  seq_0_In6doa_ast8ri79k X60Qx_191 = eQdup_1_Idg8rf9_ast8ri79k(fieldSyms_0);
  add_0_Iwx7sdj1_comaa5xpt1((&(*c_8).d_00.objInfos_0), (ObjInfo_0_chu5m1rja1){
    .typeSym_0 = typeSym_0, .fieldSyms_0 = X60Qx_191}
  );
  return result_18;}
NI32 addFieldSym_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_10, NU32 s_5){
  NI32 result_20;
  NI32 X60Qx_194 = len_3_I6y2imo_buiyylk1h1((*c_10).d_00.fieldSyms_0);
  result_20 = X60Qx_194;
  add_0_I34il1q_comaa5xpt1((&(*c_10).d_00.fieldSyms_0), s_5);
  return result_20;}
NI32 addTypeSym_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_11, NU32 s_6){
  NI32 result_21;
  NI32 X60Qx_195 = len_3_I6y2imo_buiyylk1h1((*c_11).d_00.typeSyms_0);
  result_21 = X60Qx_195;
  add_0_I34il1q_comaa5xpt1((&(*c_11).d_00.typeSyms_0), s_6);
  return result_21;}
NB8 isNativeVM_0_comaa5xpt1(string_0_sysvq0asl base_0){
  NB8 result_22;
  NB8 X60Qx_196 = isNativeBase_0_runot4689(base_0);
  result_22 = X60Qx_196;
  return result_22;}
string_0_sysvq0asl trueModule_0_comaa5xpt1(NU32 s_7){
  string_0_sysvq0asl result_23;
  nimStrWasMoved((&result_23));
  nimStrDestroy(result_23);
  string_0_sysvq0asl X60Qx_197 = trueModuleOf_0_runot4689(s_7);
  result_23 = X60Qx_197;
  return result_23;}
NB8 calleeIsProvider_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_12, NU32 s_8){
  NB8 result_24;
  string_0_sysvq0asl X60Qtmp_2 = trueModule_0_comaa5xpt1(s_8);
  NI32 X60Qx_198 = len_4_sysvq0asl(X60Qtmp_2);
  result_24 = (0 < X60Qx_198);
  nimStrDestroy(X60Qtmp_2);
  return result_24;
  nimStrDestroy(X60Qtmp_2);
  return result_24;}
NB8 nativeProvidesVM_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_13, NU32 s_9){
  NB8 result_25;
  NB8 X60Qx_199 = nativeProvidesSym_0_runot4689(s_9);
  result_25 = X60Qx_199;
  return result_25;}
NB8 isBinMagicOp_0_comaa5xpt1(NimonyExpr_0_nimry5ra91 ek_0){
  NB8 result_26;
  switch (ek_0){
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 40:
    case 41:
    case 42:
    case 39:
    case 38:
    case 245:
    case 44:
    case 45:
    case 47:
    case 46:
    case 17:
    case 18:
    case 19:
    {
      result_26 = NIM_TRUE;}
    break;
    default:
    {
      result_26 = NIM_FALSE;}
    break;}
  return result_26;}
NB8 isDeclTag_0_comaa5xpt1(string_0_sysvq0asl tag_0){
  NB8 result_27;
  NB8 X60Qx_200;
  NB8 X60Qx_201;
  NB8 X60Qx_202;
  NB8 X60Qx_203;
  NB8 X60Qx_204;
  NB8 X60Qx_205;
  NB8 X60Qx_206;
  NB8 X60Qx_207;
  NB8 X60Qx_208;
  NB8 X60Qx_209;
  NB8 X60Qx_210;
  NB8 X60Qx_211;
  NB8 X60Qx_212;
  NB8 X60Qx_213;
  NB8 X60Qx_214;
  NB8 X60Qx_215 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
    .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I5316556160589403975_comaa5xpt1)}
  );
  if (X60Qx_215){
    X60Qx_214 = NIM_TRUE;}
  else {
    NB8 X60Qx_216 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1853187838u, .more_0 = (&strlit_0_I9991102891510134496_comaa5xpt1)}
    );
    X60Qx_214 = X60Qx_216;}
  if (X60Qx_214){
    X60Qx_213 = NIM_TRUE;}
  else {
    NB8 X60Qx_217 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1702128126u, .more_0 = (&strlit_0_I9071657656589967445_comaa5xpt1)}
    );
    X60Qx_213 = X60Qx_217;}
  if (X60Qx_213){
    X60Qx_212 = NIM_TRUE;}
  else {
    NB8 X60Qx_218 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_comaa5xpt1)}
    );
    X60Qx_212 = X60Qx_218;}
  if (X60Qx_212){
    X60Qx_211 = NIM_TRUE;}
  else {
    NB8 X60Qx_219 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I6864681898360807206_comaa5xpt1)}
    );
    X60Qx_211 = X60Qx_219;}
  if (X60Qx_211){
    X60Qx_210 = NIM_TRUE;}
  else {
    NB8 X60Qx_220 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1667329534u, .more_0 = (&strlit_0_I3777428167486794959_comaa5xpt1)}
    );
    X60Qx_210 = X60Qx_220;}
  if (X60Qx_210){
    X60Qx_209 = NIM_TRUE;}
  else {
    NB8 X60Qx_221 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1835365630u, .more_0 = (&strlit_0_I17987658270787974407_comaa5xpt1)}
    );
    X60Qx_209 = X60Qx_221;}
  if (X60Qx_209){
    X60Qx_208 = NIM_TRUE;}
  else {
    NB8 X60Qx_222 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
    );
    X60Qx_208 = X60Qx_222;}
  if (X60Qx_208){
    X60Qx_207 = NIM_TRUE;}
  else {
    NB8 X60Qx_223 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I10578126245728228512_comaa5xpt1)}
    );
    X60Qx_207 = X60Qx_223;}
  if (X60Qx_207){
    X60Qx_206 = NIM_TRUE;}
  else {
    NB8 X60Qx_224 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1886218750u, .more_0 = (&strlit_0_I16948548629793503007_comaa5xpt1)}
    );
    X60Qx_206 = X60Qx_224;}
  if (X60Qx_206){
    X60Qx_205 = NIM_TRUE;}
  else {
    NB8 X60Qx_225 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1869768446u, .more_0 = (&strlit_0_I15371509460875483150_comaa5xpt1)}
    );
    X60Qx_205 = X60Qx_225;}
  if (X60Qx_205){
    X60Qx_204 = NIM_TRUE;}
  else {
    NB8 X60Qx_226 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I3312144845751804851_comaa5xpt1)}
    );
    X60Qx_204 = X60Qx_226;}
  if (X60Qx_204){
    X60Qx_203 = NIM_TRUE;}
  else {
    NB8 X60Qx_227 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I6313045265747232047_comaa5xpt1)}
    );
    X60Qx_203 = X60Qx_227;}
  if (X60Qx_203){
    X60Qx_202 = NIM_TRUE;}
  else {
    NB8 X60Qx_228 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I18257730313531980409_comaa5xpt1)}
    );
    X60Qx_202 = X60Qx_228;}
  if (X60Qx_202){
    X60Qx_201 = NIM_TRUE;}
  else {
    NB8 X60Qx_229 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_comaa5xpt1)}
    );
    X60Qx_201 = X60Qx_229;}
  if (X60Qx_201){
    X60Qx_200 = NIM_TRUE;}
  else {
    NB8 X60Qx_230 = eqQ_20_sysvq0asl(tag_0, (string_0_sysvq0asl){
      .bytes_0 = 1769174526u, .more_0 = (&strlit_0_I15803870852433253359_comaa5xpt1)}
    );
    X60Qx_200 = X60Qx_230;}
  result_27 = X60Qx_200;
  return result_27;}
void readOptType_0_comaa5xpt1(Cursor_0_nifb6mq6y1* n_2, NI32* bits_3, NB8* signed_2){
  (*bits_3) = 64;
  (*signed_2) = NIM_TRUE;
  NifKind_0_nif81dubp1 X60Qx_231 = kind_0_nifb6mq6y1((*n_2));
  if (X60Qx_231 == 11){
    string_0_sysvq0asl t_4 = nodeTag_0_comaa5xpt1((*n_2));
    NB8 X60Qx_232;
    NB8 X60Qx_233;
    NB8 X60Qx_234;
    NB8 X60Qx_235 = eqQ_20_sysvq0asl(t_4, (string_0_sysvq0asl){
      .bytes_0 = 26881u, .more_0 = NIM_NIL}
    );
    if (X60Qx_235){
      X60Qx_234 = NIM_TRUE;}
    else {
      NB8 X60Qx_236 = eqQ_20_sysvq0asl(t_4, (string_0_sysvq0asl){
        .bytes_0 = 29953u, .more_0 = NIM_NIL}
      );
      X60Qx_234 = X60Qx_236;}
    if (X60Qx_234){
      X60Qx_233 = NIM_TRUE;}
    else {
      NB8 X60Qx_237 = eqQ_20_sysvq0asl(t_4, (string_0_sysvq0asl){
        .bytes_0 = 26113u, .more_0 = NIM_NIL}
      );
      X60Qx_233 = X60Qx_237;}
    if (X60Qx_233){
      X60Qx_232 = NIM_TRUE;}
    else {
      NB8 X60Qx_238 = eqQ_20_sysvq0asl(t_4, (string_0_sysvq0asl){
        .bytes_0 = 25345u, .more_0 = NIM_NIL}
      );
      X60Qx_232 = X60Qx_238;}
    if (X60Qx_232){
      NB8 X60Qx_239;
      NB8 X60Qx_240 = eqQ_20_sysvq0asl(t_4, (string_0_sysvq0asl){
        .bytes_0 = 26881u, .more_0 = NIM_NIL}
      );
      if (X60Qx_240){
        X60Qx_239 = NIM_TRUE;}
      else {
        NB8 X60Qx_241 = eqQ_20_sysvq0asl(t_4, (string_0_sysvq0asl){
          .bytes_0 = 26113u, .more_0 = NIM_NIL}
        );
        X60Qx_239 = X60Qx_241;}
      (*signed_2) = X60Qx_239;
      NB8 X60Qx_242 = eqQ_20_sysvq0asl(t_4, (string_0_sysvq0asl){
        .bytes_0 = 25345u, .more_0 = NIM_NIL}
      );
      if (X60Qx_242){
        (*bits_3) = 8;}
      Cursor_0_nifb6mq6y1 cc_1 = eQdup_0_nifb6mq6y1((*n_2));
      inc_0_nifb6mq6y1((&cc_1));
      NifKind_0_nif81dubp1 X60Qx_243 = kind_0_nifb6mq6y1(cc_1);
      if (X60Qx_243 == 8){
        NU32 X60Qx_244 = intId_0_nifb6mq6y1(cc_1);
        NI64* X60Qx_245 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_244);
        (*bits_3) = ((NI32)(*X60Qx_245));
        if ((*bits_3) <= 0){
          (*bits_3) = ((NI32)(sizeof(NI32) * 8));}}
      eQdestroy_0_nifb6mq6y1((&cc_1));}
    skip_0_nifb6mq6y1(n_2);
    nimStrDestroy(t_4);}
  else {
    NB8 X60Qx_246;
    NifKind_0_nif81dubp1 X60Qx_247 = kind_0_nifb6mq6y1((*n_2));
    if (X60Qx_247 == 4){
      X60Qx_246 = NIM_TRUE;}
    else {
      NifKind_0_nif81dubp1 X60Qx_248 = kind_0_nifb6mq6y1((*n_2));
      X60Qx_246 = (X60Qx_248 == 2);}
    if (X60Qx_246){
      inc_0_nifb6mq6y1(n_2);}}}
NB8 mentionsSetScheduler_0_comaa5xpt1(Cursor_0_nifb6mq6y1 root_0){
  NB8 result_28;
  result_28 = NIM_FALSE;
  Cursor_0_nifb6mq6y1 n_54 = eQdup_0_nifb6mq6y1(root_0);
  NI32 depth_1 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_249;
      NifKind_0_nif81dubp1 X60Qx_250 = kind_0_nifb6mq6y1(n_54);
      if (X60Qx_250 == 4){
        X60Qx_249 = NIM_TRUE;}
      else {
        NifKind_0_nif81dubp1 X60Qx_251 = kind_0_nifb6mq6y1(n_54);
        X60Qx_249 = (X60Qx_251 == 5);}
      if (X60Qx_249){
        NU32 X60Qx_252 = symId_0_nifb6mq6y1(n_54);
        string_0_sysvq0asl X60Qtmp_3 = baseName_0_comaa5xpt1(X60Qx_252);
        NB8 X60Qx_253 = eqQ_20_sysvq0asl(X60Qtmp_3, (string_0_sysvq0asl){
          .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I11023901819970991276_comaa5xpt1)}
        );
        if (X60Qx_253){
          nimStrDestroy(X60Qtmp_3);
          eQdestroy_0_nifb6mq6y1((&n_54));
          return NIM_TRUE;}
        nimStrDestroy(X60Qtmp_3);}
      else {
        NifKind_0_nif81dubp1 X60Qx_254 = kind_0_nifb6mq6y1(n_54);
        if (X60Qx_254 == 11){
          inc_1_I6wjjge_aow2h993l1((&depth_1));}
        else {
          NifKind_0_nif81dubp1 X60Qx_255 = kind_0_nifb6mq6y1(n_54);
          if (X60Qx_255 == 12){
            dec_1_I0nzoz91_ast8ri79k((&depth_1));
            if (depth_1 <= 0){
              eQdestroy_0_nifb6mq6y1((&n_54));
              return NIM_FALSE;}}}}
      inc_0_nifb6mq6y1((&n_54));}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&n_54));
  return result_28;
  eQdestroy_0_nifb6mq6y1((&n_54));
  return result_28;}
void collectDecls_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_43, Cursor_0_nifb6mq6y1* n_23){
  NifKind_0_nif81dubp1 X60Qx_256 = kind_0_nifb6mq6y1((*n_23));
  if ((!(X60Qx_256 == 11))){
    inc_0_nifb6mq6y1(n_23);
    return;}
  string_0_sysvq0asl tag_1 = nodeTag_0_comaa5xpt1((*n_23));
  NB8 X60Qx_257 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
    .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_comaa5xpt1)}
  );
  if (X60Qx_257){
    Cursor_0_nifb6mq6y1 cc_2 = eQdup_0_nifb6mq6y1((*n_23));
    inc_0_nifb6mq6y1((&cc_2));
    NifKind_0_nif81dubp1 X60Qx_258 = kind_0_nifb6mq6y1(cc_2);
    if (X60Qx_258 == 5){
      NU32 esym_0 = symId_0_nifb6mq6y1(cc_2);
      skip_0_nifb6mq6y1((&cc_2));
      skip_0_nifb6mq6y1((&cc_2));
      skip_0_nifb6mq6y1((&cc_2));
      skip_0_nifb6mq6y1((&cc_2));
      NI32 ord_0 = 0;
      string_0_sysvq0asl ename_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NifKind_0_nif81dubp1 X60Qx_259 = kind_0_nifb6mq6y1(cc_2);
      if (X60Qx_259 == 11){
        Cursor_0_nifb6mq6y1 t_6 = cc_2;
        eQwasMoved_0_nifb6mq6y1((&cc_2));
        inc_0_nifb6mq6y1((&t_6));
        NifKind_0_nif81dubp1 X60Qx_260 = kind_0_nifb6mq6y1(t_6);
        if (X60Qx_260 == 8){
          NU32 X60Qx_261 = intId_0_nifb6mq6y1(t_6);
          NI64* X60Qx_262 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_261);
          ord_0 = ((NI32)(*X60Qx_262));}
        skip_0_nifb6mq6y1((&t_6));
        NifKind_0_nif81dubp1 X60Qx_263 = kind_0_nifb6mq6y1(t_6);
        if (X60Qx_263 == 6){
          nimStrDestroy(ename_0);
          NU32 X60Qx_264 = litId_0_nifb6mq6y1(t_6);
          string_0_sysvq0asl* X60Qx_265 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_264);
          string_0_sysvq0asl X60Qx_266 = nimStrDup((*X60Qx_265));
          ename_0 = X60Qx_266;}
        eQdestroy_0_nifb6mq6y1((&t_6));}
      add_0_I34il1q_comaa5xpt1((&(*c_43).d_00.enumSyms_0), esym_0);
      add_0_I8kd4i4_comaa5xpt1((&(*c_43).d_00.enumOrds_0), ord_0);
      string_0_sysvq0asl X60Qtmp_4 = ename_0;
      nimStrWasMoved((&ename_0));
      add_0_Ig6072n_ast8ri79k((&(*c_43).d_00.enumNames_0), X60Qtmp_4);
      nimStrDestroy(ename_0);}
    skip_0_nifb6mq6y1(n_23);
    eQdestroy_0_nifb6mq6y1((&cc_2));
    nimStrDestroy(tag_1);
    return;
    eQdestroy_0_nifb6mq6y1((&cc_2));}
  NimonySym_0_nimry5ra91 X60Qx_267 = symKind_0_nim30udrv((*n_23));
  NB8 X60Qx_268 = isRoutine_0_decqocs071(X60Qx_267);
  if (X60Qx_268){
    Cursor_0_nifb6mq6y1 start_0 = eQdup_0_nifb6mq6y1((*n_23));
    Cursor_0_nifb6mq6y1 cc_3 = eQdup_0_nifb6mq6y1((*n_23));
    inc_0_nifb6mq6y1((&cc_3));
    NifKind_0_nif81dubp1 X60Qx_269 = kind_0_nifb6mq6y1(cc_3);
    if (X60Qx_269 == 5){
      NU32 X60Qx_270 = symId_0_nifb6mq6y1(cc_3);
      add_0_I34il1q_comaa5xpt1((&(*c_43).d_00.procDefSyms_0), X60Qx_270);
      Cursor_0_nifb6mq6y1 X60Qtmp_5 = start_0;
      eQwasMoved_0_nifb6mq6y1((&start_0));
      add_0_Insw6ce1_comaa5xpt1((&(*c_43).d_00.procDefCursors_0), X60Qtmp_5);}
    skip_0_nifb6mq6y1(n_23);
    eQdestroy_0_nifb6mq6y1((&cc_3));
    eQdestroy_0_nifb6mq6y1((&start_0));
    nimStrDestroy(tag_1);
    return;
    eQdestroy_0_nifb6mq6y1((&cc_3));
    eQdestroy_0_nifb6mq6y1((&start_0));}
  NB8 X60Qx_271 = eqQ_20_sysvq0asl(tag_1, (string_0_sysvq0asl){
    .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
  );
  if (X60Qx_271){
    publishFieldDecls_0_runot4689((*n_23));}
  inc_0_nifb6mq6y1(n_23);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_272 = kind_0_nifb6mq6y1((*n_23));
      if ((!(X60Qx_272 == 12))){
        collectDecls_0_comaa5xpt1(c_43, n_23);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_23);
  nimStrDestroy(tag_1);}
NI32 addEnvSym_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_44, NU32 s_19){
  NI32 result_29;
  NI32 X60Qx_273 = symIndex_0_comaa5xpt1((*c_44).d_00.envSyms_0, s_19);
  result_29 = X60Qx_273;
  if (0 <= result_29){
    return result_29;}
  NI32 X60Qx_274 = len_3_I6y2imo_buiyylk1h1((*c_44).d_00.envSyms_0);
  result_29 = X60Qx_274;
  add_0_I34il1q_comaa5xpt1((&(*c_44).d_00.envSyms_0), s_19);
  return result_29;}
void registerNestedRoutines_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_45, Cursor_0_nifb6mq6y1* n_24){
  NifKind_0_nif81dubp1 X60Qx_275 = kind_0_nifb6mq6y1((*n_24));
  if ((!(X60Qx_275 == 11))){
    inc_0_nifb6mq6y1(n_24);
    return;}
  NimonySym_0_nimry5ra91 X60Qx_276 = symKind_0_nim30udrv((*n_24));
  NB8 X60Qx_277 = isRoutine_0_decqocs071(X60Qx_276);
  if (X60Qx_277){
    Cursor_0_nifb6mq6y1 cc_4 = eQdup_0_nifb6mq6y1((*n_24));
    inc_0_nifb6mq6y1((&cc_4));
    NifKind_0_nif81dubp1 X60Qx_278 = kind_0_nifb6mq6y1(cc_4);
    if (X60Qx_278 == 5){
      NU32 X60Qx_279 = symId_0_nifb6mq6y1(cc_4);
      put_0_comaa5xpt1((&(*c_45).d_00.nestedSyms_0), X60Qx_279, 1);}
    Routine_0_decqocs071 r_3 = asRoutine_0_decqocs071((*n_24), 1);
    Cursor_0_nifb6mq6y1 b_1 = r_3.body_0;
    eQwasMoved_0_nifb6mq6y1((&r_3.body_0));
    NifKind_0_nif81dubp1 X60Qx_280 = kind_0_nifb6mq6y1(b_1);
    if (X60Qx_280 == 11){
      registerNestedRoutines_0_comaa5xpt1(c_45, (&b_1));}
    skip_0_nifb6mq6y1(n_24);
    eQdestroy_0_nifb6mq6y1((&b_1));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
    eQdestroy_0_nifb6mq6y1((&cc_4));
    return;
    eQdestroy_0_nifb6mq6y1((&b_1));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_3));
    eQdestroy_0_nifb6mq6y1((&cc_4));}
  inc_0_nifb6mq6y1(n_24);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_281 = kind_0_nifb6mq6y1((*n_24));
      if ((!(X60Qx_281 == 12))){
        registerNestedRoutines_0_comaa5xpt1(c_45, n_24);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_24);}
NB8 capturedSym_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_46, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_25, NU32 s_20){
  NB8 result_30;
  if ((!(*ctx_25).d_00.isNested_0)){
    return NIM_FALSE;}
  NI32 X60Qx_282 = len_3_Ibv77kg1_comaa5xpt1((*c_46).d_00.ctxStack_0);
  NI32 i_11 = ((NI32)(X60Qx_282 - 1));
  {
    while (0 <= i_11){
      X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_283 = getQ_7_Ivqabz61_comaa5xpt1((*c_46).d_00.ctxStack_0, i_11);
      X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* e_0 = eQdupQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_283));
      NB8 X60Qx_284;
      if ((!(e_0 == ctx_25))){
        NI32 X60Qx_285 = get_0_comaa5xpt1((*e_0).d_00.smap_0, s_20);
        X60Qx_284 = (0 <= X60Qx_285);}
      else {
        X60Qx_284 = NIM_FALSE;}
      if (X60Qx_284){
        eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(e_0);
        return NIM_TRUE;}
      dec_1_I0nzoz91_ast8ri79k((&i_11));
      eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(e_0);}}
  whileStmtLabel_0: ;
  result_30 = NIM_FALSE;
  return result_30;}
NI32 implicitGlobal_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_47, NU32 s_21){
  NI32 result_31;
  NI32 X60Qx_286 = get_0_comaa5xpt1((*c_47).d_00.gmap_0, s_21);
  result_31 = X60Qx_286;
  if (0 <= result_31){
    return result_31;}
  result_31 = (*c_47).d_00.numGlobals_0;
  inc_1_I6wjjge_aow2h993l1((&(*c_47).d_00.numGlobals_0));
  put_0_comaa5xpt1((&(*c_47).d_00.gmap_0), s_21, result_31);
  return result_31;}
X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 importedGlobalAddr_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_48, NU32 s_22){
  X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 result_32;
  NI32 i_13 = symIndex_0_comaa5xpt1((*c_48).d_00.importGlobalSyms_0, s_22);
  if (0 <= i_13){
    NI32* X60Qx_287 = getQ_7_Ir8kccm_comaa5xpt1((*c_48).d_00.importGlobalSlots_0, i_13);
    NI32* X60Qx_288 = getQ_7_Ir8kccm_comaa5xpt1((*c_48).d_00.importGlobalInits_0, i_13);
    result_32 = (X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1){
      .fld_0 = (*X60Qx_287), .fld_1 = (*X60Qx_288)}
    ;
    return result_32;}
  LoadResult_0_prorcx25w1 res_1 = tryLoadSymSafe_0_modzy18mg1(s_22);
  if ((!(res_1.status_0 == 3))){
    result_32 = (X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1){
      .fld_0 = -1, .fld_1 = -1}
    ;
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
    return result_32;}
  string_0_sysvq0asl dt_0 = nodeTag_0_comaa5xpt1(res_1.decl_0);
  NB8 X60Qx_289;
  NB8 X60Qx_290;
  NB8 X60Qx_291 = eqQ_20_sysvq0asl(dt_0, (string_0_sysvq0asl){
    .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
  );
  if ((!X60Qx_291)){
    NB8 X60Qx_292 = eqQ_20_sysvq0asl(dt_0, (string_0_sysvq0asl){
      .bytes_0 = 1701603326u, .more_0 = (&strlit_0_I5723805845286553140_comaa5xpt1)}
    );
    X60Qx_290 = (!X60Qx_292);}
  else {
    X60Qx_290 = NIM_FALSE;}
  if (X60Qx_290){
    NB8 X60Qx_293 = eqQ_20_sysvq0asl(dt_0, (string_0_sysvq0asl){
      .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_comaa5xpt1)}
    );
    X60Qx_289 = (!X60Qx_293);}
  else {
    X60Qx_289 = NIM_FALSE;}
  if (X60Qx_289){
    result_32 = (X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1){
      .fld_0 = -1, .fld_1 = -1}
    ;
    nimStrDestroy(dt_0);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
    return result_32;}
  Local_0_decqocs071 loc_0 = asLocal_0_decqocs071(res_1.decl_0, 1);
  NifKind_0_nif81dubp1 X60Qx_294 = kind_0_nifb6mq6y1(loc_0.val_0);
  if (X60Qx_294 == 2){
    result_32 = (X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1){
      .fld_0 = -1, .fld_1 = -1}
    ;
    eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_0));
    nimStrDestroy(dt_0);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
    return result_32;}
  X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 X60Qx_295 = importedGlobal_1_comaa5xpt1(c_48, s_22, loc_0.val_0);
  result_32 = X60Qx_295;
  eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_0));
  nimStrDestroy(dt_0);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
  return result_32;
  eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_0));
  nimStrDestroy(dt_0);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_1);
  return result_32;}
X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 importedGlobal_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_49, NU32 s_23, Cursor_0_nifb6mq6y1 initExpr_1){
  X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 result_33;
  NI32 i_14 = symIndex_0_comaa5xpt1((*c_49).d_00.importGlobalSyms_0, s_23);
  if (0 <= i_14){
    NI32* X60Qx_296 = getQ_7_Ir8kccm_comaa5xpt1((*c_49).d_00.importGlobalSlots_0, i_14);
    NI32* X60Qx_297 = getQ_7_Ir8kccm_comaa5xpt1((*c_49).d_00.importGlobalInits_0, i_14);
    result_33 = (X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1){
      .fld_0 = (*X60Qx_296), .fld_1 = (*X60Qx_297)}
    ;
    return result_33;}
  NI32 slot_1 = (*c_49).d_00.numGlobals_0;
  inc_1_I6wjjge_aow2h993l1((&(*c_49).d_00.numGlobals_0));
  add_0_I34il1q_comaa5xpt1((&(*c_49).d_00.importGlobalSyms_0), s_23);
  add_0_I8kd4i4_comaa5xpt1((&(*c_49).d_00.importGlobalSlots_0), slot_1);
  add_0_I8kd4i4_comaa5xpt1((&(*c_49).d_00.importGlobalInits_0), 0);
  NI32 X60Qx_298 = len_3_I6y2imo_buiyylk1h1((*c_49).d_00.importGlobalSyms_0);
  NI32 recIdx_0 = ((NI32)(X60Qx_298 - 1));
  void* X60Qx_299 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1));
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_6 = ((X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_299);
  seq_0_Izok7jt1_chu5m1rja1 X60Qx_300 = newSeqUninit_0_I82j90d_chu5m1rja1(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_301 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_302 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_303 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Iscf6bn_comaa5xpt1 X60Qx_304 = newSeqUninit_0_Ib8z3ow_comaa5xpt1(0);
  seq_0_I806bg1_comaa5xpt1 X60Qx_305 = newSeqUninit_0_Iqckanu_comaa5xpt1(0);
  seq_0_Igm8woo1_comaa5xpt1 X60Qx_306 = newSeqUninit_0_I8nq5k8_comaa5xpt1(0);
  (*X60Qtmp_6) = (X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1){
    .r_00 = 0, .d_00 = (ProcCtx_Obj_0_comaa5xpt1){
      .code_0 = X60Qx_300, .codeLines_0 = X60Qx_301, .curLine_0 = ((NI32)0), .smap_0 = (SymMap_0_comaa5xpt1){
        .keys_0 = X60Qx_302, .vals_0 = X60Qx_303}
      , .numLocals_0 = 0, .numParams_0 = 0, .resultSlot_0 = -1, .isTop_0 = NIM_FALSE, .isNested_0 = NIM_FALSE, .isPassive_0 = NIM_FALSE, .loops_0 = X60Qx_304, .finallys_0 = X60Qx_305, .yields_0 = X60Qx_306, .guardSym_0 = ((NU32)0u)}}
  ;
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* tctx_0 = X60Qtmp_6;
  Cursor_0_nifb6mq6y1 vc_0 = eQdup_0_nifb6mq6y1(initExpr_1);
  compileExpr_1_comaa5xpt1(c_49, tctx_0, (&vc_0));
  NI32 X60Qx_307 = emit_0_comaa5xpt1(tctx_0, 36, 0, 0);
  NI32 initIdx_0 = len_3_I05nxx61_comaa5xpt1((*c_49).d_00.procs_0);
  seq_0_Izok7jt1_chu5m1rja1 X60Qx_308 = eQdup_1_Ir0cadv1_chu5m1rja1((*tctx_0).d_00.code_0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_309 = eQdup_1_Iplow11_chu5m1rja1((*tctx_0).d_00.codeLines_0);
  string_0_sysvq0asl X60Qx_310 = baseName_0_comaa5xpt1(s_23);
  seq_0_In6doa_ast8ri79k X60Qx_311 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  add_0_Iss439i1_comaa5xpt1((&(*c_49).d_00.procs_0), (Proc_0_chu5m1rja1){
    .code_0 = X60Qx_308, .lines_0 = X60Qx_309, .numParams_0 = 0, .numLocals_0 = (*tctx_0).d_00.numLocals_0, .resultSlot_0 = -1, .name_0 = X60Qx_310, .isPassive_0 = NIM_FALSE, .slotSyms_0 = X60Qx_311}
  );
  putQ_7_Ifvyck5_comaa5xpt1((&(*c_49).d_00.importGlobalInits_0), recIdx_0, initIdx_0);
  result_33 = (X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1){
    .fld_0 = slot_1, .fld_1 = initIdx_0}
  ;
  eQdestroy_0_nifb6mq6y1((&vc_0));
  eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(tctx_0);
  return result_33;
  eQdestroy_0_nifb6mq6y1((&vc_0));
  eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(tctx_0);
  return result_33;}
void seedGlobal_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_50, NI32 slot_0, string_0_sysvq0asl bn_0, string_0_sysvq0asl cname_0, Cursor_0_nifb6mq6y1 typ_0){
  NI32 i_15 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_312 = len_3_Iuz7erf_comaa5xpt1((*c_50).d_00.globalSeeds_0);
      if (i_15 < X60Qx_312){
        GlobalSeed_0_chu5m1rja1* X60Qx_313 = getQ_7_Ijx02qt_comaa5xpt1((*c_50).d_00.globalSeeds_0, i_15);
        if ((*X60Qx_313).slot_0 == slot_0){
          return;}
        inc_1_I6wjjge_aow2h993l1((&i_15));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NB8 lcFound_0 = NIM_FALSE;
  Value_0_valzr1t4f lc_0 = libcConstVal_0_runot4689(bn_0, (&lcFound_0));
  Value_0_valzr1t4f X60Qx_0;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
  if (lcFound_0){
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
    X60Qx_0 = lc_0;
    eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_0));}
  else {
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
    Value_0_valzr1t4f X60Qx_314 = defaultForType_1_runot4689(typ_0);
    X60Qx_0 = X60Qx_314;}
  Value_0_valzr1t4f v_2 = X60Qx_0;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
  string_0_sysvq0asl X60Qx_54 = nimStrDup(bn_0);
  string_0_sysvq0asl X60Qx_55 = nimStrDup(cname_0);
  Value_0_valzr1t4f X60Qtmp_7 = v_2;
  eQwasmovedQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_2));
  add_0_Iyv2a7e1_comaa5xpt1((&(*c_50).d_00.globalSeeds_0), (GlobalSeed_0_chu5m1rja1){
    .slot_0 = slot_0, .name_0 = X60Qx_54, .cname_0 = X60Qx_55, .v_0 = X60Qtmp_7}
  );
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&v_2));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qx_0));
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_0));}
NI32 importcSlot_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_51, string_0_sysvq0asl cname_1){
  NI32 result_34;
  NI32 i_17 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_315 = len_3_Iuz7erf_comaa5xpt1((*c_51).d_00.globalSeeds_0);
      if (i_17 < X60Qx_315){
        NB8 X60Qx_316;
        GlobalSeed_0_chu5m1rja1* X60Qx_317 = getQ_7_Ijx02qt_comaa5xpt1((*c_51).d_00.globalSeeds_0, i_17);
        NI32 X60Qx_318 = len_4_sysvq0asl((*X60Qx_317).cname_0);
        if (0 < X60Qx_318){
          GlobalSeed_0_chu5m1rja1* X60Qx_319 = getQ_7_Ijx02qt_comaa5xpt1((*c_51).d_00.globalSeeds_0, i_17);
          NB8 X60Qx_320 = eqQ_20_sysvq0asl((*X60Qx_319).cname_0, cname_1);
          X60Qx_316 = X60Qx_320;}
        else {
          X60Qx_316 = NIM_FALSE;}
        if (X60Qx_316){
          GlobalSeed_0_chu5m1rja1* X60Qx_321 = getQ_7_Ijx02qt_comaa5xpt1((*c_51).d_00.globalSeeds_0, i_17);
          result_34 = (*X60Qx_321).slot_0;
          return result_34;}
        inc_1_I6wjjge_aow2h993l1((&i_17));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_34 = -1;
  return result_34;}
NI32 globalSlotFor_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_52, NU32 s_24){
  NI32 result_35;
  NI32 gs_0 = get_0_comaa5xpt1((*c_52).d_00.gmap_0, s_24);
  if (0 <= gs_0){
    return gs_0;}
  LoadResult_0_prorcx25w1 res_2 = tryLoadSymSafe_0_modzy18mg1(s_24);
  if (res_2.status_0 == 3){
    string_0_sysvq0asl dt_1 = nodeTag_0_comaa5xpt1(res_2.decl_0);
    NB8 X60Qx_322;
    NB8 X60Qx_323;
    NB8 X60Qx_324;
    NB8 X60Qx_325 = eqQ_20_sysvq0asl(dt_1, (string_0_sysvq0asl){
      .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
    );
    if (X60Qx_325){
      X60Qx_324 = NIM_TRUE;}
    else {
      NB8 X60Qx_326 = eqQ_20_sysvq0asl(dt_1, (string_0_sysvq0asl){
        .bytes_0 = 1701603326u, .more_0 = (&strlit_0_I5723805845286553140_comaa5xpt1)}
      );
      X60Qx_324 = X60Qx_326;}
    if (X60Qx_324){
      X60Qx_323 = NIM_TRUE;}
    else {
      NB8 X60Qx_327 = eqQ_20_sysvq0asl(dt_1, (string_0_sysvq0asl){
        .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_comaa5xpt1)}
      );
      X60Qx_323 = X60Qx_327;}
    if (X60Qx_323){
      X60Qx_322 = NIM_TRUE;}
    else {
      NB8 X60Qx_328 = eqQ_20_sysvq0asl(dt_1, (string_0_sysvq0asl){
        .bytes_0 = 1635153150u, .more_0 = (&strlit_0_I13046452236886743244_comaa5xpt1)}
      );
      X60Qx_322 = X60Qx_328;}
    if (X60Qx_322){
      Local_0_decqocs071 loc_1 = asLocal_0_decqocs071(res_2.decl_0, 1);
      NifKind_0_nif81dubp1 X60Qx_329 = kind_0_nifb6mq6y1(loc_1.val_0);
      if (X60Qx_329 == 2){
        string_0_sysvq0asl cn_0 = importcName_0_hlc70y78v(loc_1.pragmas_0);
        NI32 X60Qx_330 = len_4_sysvq0asl(cn_0);
        if (0 < X60Qx_330){
          NI32 sh_0 = importcSlot_0_comaa5xpt1(c_52, cn_0);
          if (0 <= sh_0){
            put_0_comaa5xpt1((&(*c_52).d_00.gmap_0), s_24, sh_0);
            nimStrDestroy(cn_0);
            eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_1));
            nimStrDestroy(dt_1);
            eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
            return sh_0;}}
        NI32 slot_2 = implicitGlobal_0_comaa5xpt1(c_52, s_24);
        string_0_sysvq0asl X60Qtmp_8 = baseName_0_comaa5xpt1(s_24);
        seedGlobal_0_comaa5xpt1(c_52, slot_2, X60Qtmp_8, cn_0, loc_1.typ_0);
        nimStrDestroy(X60Qtmp_8);
        nimStrDestroy(cn_0);
        eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_1));
        nimStrDestroy(dt_1);
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
        return slot_2;
        nimStrDestroy(X60Qtmp_8);
        nimStrDestroy(cn_0);}
      eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_1));}
    nimStrDestroy(dt_1);}
  NI32 X60Qx_331 = implicitGlobal_0_comaa5xpt1(c_52, s_24);
  result_35 = X60Qx_331;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
  return result_35;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_2);
  return result_35;}
X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 schedulerGlobalOf_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_53, NU32 setSchedSym_0){
  X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 result_36;
  result_36 = (X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1){
    .fld_0 = -1, .fld_1 = -1}
  ;
  Cursor_0_nifb6mq6y1 cur_3 = (Cursor_0_nifb6mq6y1){
    .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
  ;
  NI32 di_0 = symIndex_0_comaa5xpt1((*c_53).d_00.procDefSyms_0, setSchedSym_0);
  if (0 <= di_0){
    eQdestroy_0_nifb6mq6y1((&cur_3));
    Cursor_0_nifb6mq6y1* X60Qx_332 = getQ_7_Iyegbq3_comaa5xpt1((*c_53).d_00.procDefCursors_0, di_0);
    Cursor_0_nifb6mq6y1 X60Qx_333 = eQdup_0_nifb6mq6y1((*X60Qx_332));
    cur_3 = X60Qx_333;}
  else {
    LoadResult_0_prorcx25w1 res_3 = tryLoadSymSafe_0_modzy18mg1(setSchedSym_0);
    NB8 X60Qx_334;
    if ((!(res_3.status_0 == 3))){
      X60Qx_334 = NIM_TRUE;}
    else {
      NimonySym_0_nimry5ra91 X60Qx_335 = symKind_0_nim30udrv(res_3.decl_0);
      NB8 X60Qx_336 = isRoutine_0_decqocs071(X60Qx_335);
      X60Qx_334 = (!X60Qx_336);}
    if (X60Qx_334){
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_3);
      eQdestroy_0_nifb6mq6y1((&cur_3));
      return result_36;}
    eQdestroy_0_nifb6mq6y1((&cur_3));
    cur_3 = res_3.decl_0;
    eQwasMoved_0_nifb6mq6y1((&res_3.decl_0));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_3);}
  Routine_0_decqocs071 r_4 = asRoutine_0_decqocs071(cur_3, 1);
  NifKind_0_nif81dubp1 X60Qx_337 = kind_0_nifb6mq6y1(r_4.body_0);
  if ((!(X60Qx_337 == 11))){
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_4));
    eQdestroy_0_nifb6mq6y1((&cur_3));
    return result_36;}
  Cursor_0_nifb6mq6y1 b_2 = r_4.body_0;
  eQwasMoved_0_nifb6mq6y1((&r_4.body_0));
  NI32 guard_0 = 0;
  {
    while (guard_0 < 64){
      inc_1_I6wjjge_aow2h993l1((&guard_0));
      NifKind_0_nif81dubp1 X60Qx_338 = kind_0_nifb6mq6y1(b_2);
      if ((!(X60Qx_338 == 11))){
        eQdestroy_0_nifb6mq6y1((&b_2));
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_4));
        eQdestroy_0_nifb6mq6y1((&cur_3));
        return result_36;}
      string_0_sysvq0asl tg_0 = nodeTag_0_comaa5xpt1(b_2);
      NB8 X60Qx_339 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
        .bytes_0 = 1735614974u, .more_0 = (&strlit_0_I2681092370707159476_comaa5xpt1)}
      );
      if (X60Qx_339){
        inc_0_nifb6mq6y1((&b_2));
        NifKind_0_nif81dubp1 X60Qx_340 = kind_0_nifb6mq6y1(b_2);
        if ((!(X60Qx_340 == 4))){
          nimStrDestroy(tg_0);
          eQdestroy_0_nifb6mq6y1((&b_2));
          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_4));
          eQdestroy_0_nifb6mq6y1((&cur_3));
          return result_36;}
        NU32 X60Qx_341 = symId_0_nifb6mq6y1(b_2);
        X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 X60Qx_342 = importedGlobalAddr_0_comaa5xpt1(c_53, X60Qx_341);
        result_36 = X60Qx_342;
        nimStrDestroy(tg_0);
        eQdestroy_0_nifb6mq6y1((&b_2));
        eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_4));
        eQdestroy_0_nifb6mq6y1((&cur_3));
        return result_36;}
      else {
        NB8 X60Qx_343 = eqQ_20_sysvq0asl(tg_0, (string_0_sysvq0asl){
          .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_comaa5xpt1)}
        );
        if (X60Qx_343){
          inc_0_nifb6mq6y1((&b_2));}
        else {
          nimStrDestroy(tg_0);
          eQdestroy_0_nifb6mq6y1((&b_2));
          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_4));
          eQdestroy_0_nifb6mq6y1((&cur_3));
          return result_36;}}
      nimStrDestroy(tg_0);}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&b_2));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_4));
  eQdestroy_0_nifb6mq6y1((&cur_3));
  return result_36;
  eQdestroy_0_nifb6mq6y1((&b_2));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_4));
  eQdestroy_0_nifb6mq6y1((&cur_3));
  return result_36;}
void resolveSymbol_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_54, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_26, NU32 s_25){
  NI32 ls_0 = get_0_comaa5xpt1((*ctx_26).d_00.smap_0, s_25);
  if (0 <= ls_0){
    NI32 X60Qx_344 = emit_0_comaa5xpt1(ctx_26, 5, ls_0, 0);
    return;}
  NI32 gs_1 = get_0_comaa5xpt1((*c_54).d_00.gmap_0, s_25);
  if (0 <= gs_1){
    NI32 X60Qx_345 = emit_0_comaa5xpt1(ctx_26, 8, gs_1, 0);
    return;}
  NB8 X60Qx_346 = capturedSym_0_comaa5xpt1(c_54, ctx_26, s_25);
  if (X60Qx_346){
    NI32 X60Qx_347 = addEnvSym_0_comaa5xpt1(c_54, s_25);
    NI32 X60Qx_348 = emit_0_comaa5xpt1(ctx_26, 30, X60Qx_347, 0);
    return;}
  string_0_sysvq0asl b_3 = baseName_0_comaa5xpt1(s_25);
  NB8 X60Qx_349 = eqQ_20_sysvq0asl(b_3, (string_0_sysvq0asl){
    .bytes_0 = 1685353470u, .more_0 = (&strlit_0_I1990248930136438291_comaa5xpt1)}
  );
  if (X60Qx_349){
    Value_0_valzr1t4f X60Qtmp_9 = (Value_0_valzr1t4f){
      .kind_0 = 16, .toErr_0 = NIM_FALSE}
    ;
    NI32 X60Qx_350 = addConst_0_comaa5xpt1(c_54, (&X60Qtmp_9));
    NI32 X60Qx_351 = emit_0_comaa5xpt1(ctx_26, 0, X60Qx_350, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_9));
    nimStrDestroy(b_3);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_9));}
  NB8 X60Qx_352 = eqQ_20_sysvq0asl(b_3, (string_0_sysvq0asl){
    .bytes_0 = 1685353470u, .more_0 = (&strlit_0_I9873340078075426535_comaa5xpt1)}
  );
  if (X60Qx_352){
    Value_0_valzr1t4f X60Qtmp_10 = (Value_0_valzr1t4f){
      .kind_0 = 16, .toErr_0 = NIM_TRUE}
    ;
    NI32 X60Qx_353 = addConst_0_comaa5xpt1(c_54, (&X60Qtmp_10));
    NI32 X60Qx_354 = emit_0_comaa5xpt1(ctx_26, 0, X60Qx_353, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_10));
    nimStrDestroy(b_3);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_10));}
  NB8 X60Qx_355 = eqQ_20_sysvq0asl(b_3, (string_0_sysvq0asl){
    .bytes_0 = 1685353470u, .more_0 = (&strlit_0_I14266456148715147463_comaa5xpt1)}
  );
  if (X60Qx_355){
    Value_0_valzr1t4f X60Qtmp_11 = (Value_0_valzr1t4f){
      .kind_0 = 16, .toErr_0 = NIM_FALSE}
    ;
    NI32 X60Qx_356 = addConst_0_comaa5xpt1(c_54, (&X60Qtmp_11));
    NI32 X60Qx_357 = emit_0_comaa5xpt1(ctx_26, 0, X60Qx_356, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_11));
    nimStrDestroy(b_3);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_11));}
  NB8 lcFound_1 = NIM_FALSE;
  Value_0_valzr1t4f lc_1 = libcConstVal_0_runot4689(b_3, (&lcFound_1));
  if (lcFound_1){
    NI32 X60Qx_358 = addConst_0_comaa5xpt1(c_54, (&lc_1));
    NI32 X60Qx_359 = emit_0_comaa5xpt1(ctx_26, 0, X60Qx_358, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_1));
    nimStrDestroy(b_3);
    return;}
  NI32 ei_0 = symIndex_0_comaa5xpt1((*c_54).d_00.enumSyms_0, s_25);
  if (0 <= ei_0){
    NI32* X60Qx_360 = getQ_7_Ir8kccm_comaa5xpt1((*c_54).d_00.enumOrds_0, ei_0);
    string_0_sysvq0asl* X60Qx_361 = getQ_7_Ir6d0tw_ast8ri79k((*c_54).d_00.enumNames_0, ei_0);
    Value_0_valzr1t4f X60Qtmp_12 = vEnum_0_valzr1t4f((*X60Qx_360), s_25, (*X60Qx_361));
    NI32 X60Qx_362 = addConst_0_comaa5xpt1(c_54, (&X60Qtmp_12));
    NI32 X60Qx_363 = emit_0_comaa5xpt1(ctx_26, 0, X60Qx_362, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_12));
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_1));
    nimStrDestroy(b_3);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_12));}
  LoadResult_0_prorcx25w1 res_4 = tryLoadSymSafe_0_modzy18mg1(s_25);
  if (res_4.status_0 == 3){
    Cursor_0_nifb6mq6y1 d_1 = res_4.decl_0;
    eQwasMoved_0_nifb6mq6y1((&res_4.decl_0));
    string_0_sysvq0asl dt_2 = nodeTag_0_comaa5xpt1(d_1);
    NB8 X60Qx_364 = eqQ_20_sysvq0asl(dt_2, (string_0_sysvq0asl){
      .bytes_0 = 1818650110u, .more_0 = (&strlit_0_I2171368188661376471_comaa5xpt1)}
    );
    if (X60Qx_364){
      Cursor_0_nifb6mq6y1 cc_5 = d_1;
      eQwasMoved_0_nifb6mq6y1((&d_1));
      inc_0_nifb6mq6y1((&cc_5));
      skip_0_nifb6mq6y1((&cc_5));
      skip_0_nifb6mq6y1((&cc_5));
      skip_0_nifb6mq6y1((&cc_5));
      skip_0_nifb6mq6y1((&cc_5));
      NI32 ord_1 = 0;
      string_0_sysvq0asl ename_1 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      ;
      NifKind_0_nif81dubp1 X60Qx_365 = kind_0_nifb6mq6y1(cc_5);
      if (X60Qx_365 == 11){
        Cursor_0_nifb6mq6y1 t_8 = cc_5;
        eQwasMoved_0_nifb6mq6y1((&cc_5));
        inc_0_nifb6mq6y1((&t_8));
        NifKind_0_nif81dubp1 X60Qx_366 = kind_0_nifb6mq6y1(t_8);
        if (X60Qx_366 == 8){
          NU32 X60Qx_367 = intId_0_nifb6mq6y1(t_8);
          NI64* X60Qx_368 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_367);
          ord_1 = ((NI32)(*X60Qx_368));}
        skip_0_nifb6mq6y1((&t_8));
        NifKind_0_nif81dubp1 X60Qx_369 = kind_0_nifb6mq6y1(t_8);
        if (X60Qx_369 == 6){
          nimStrDestroy(ename_1);
          NU32 X60Qx_370 = litId_0_nifb6mq6y1(t_8);
          string_0_sysvq0asl* X60Qx_371 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_370);
          string_0_sysvq0asl X60Qx_372 = nimStrDup((*X60Qx_371));
          ename_1 = X60Qx_372;}
        eQdestroy_0_nifb6mq6y1((&t_8));}
      Value_0_valzr1t4f X60Qtmp_13 = vEnum_0_valzr1t4f(ord_1, s_25, ename_1);
      NI32 X60Qx_373 = addConst_0_comaa5xpt1(c_54, (&X60Qtmp_13));
      NI32 X60Qx_374 = emit_0_comaa5xpt1(ctx_26, 0, X60Qx_373, 0);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_13));
      nimStrDestroy(ename_1);
      eQdestroy_0_nifb6mq6y1((&cc_5));
      nimStrDestroy(dt_2);
      eQdestroy_0_nifb6mq6y1((&d_1));
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_1));
      nimStrDestroy(b_3);
      return;
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_13));
      nimStrDestroy(ename_1);
      eQdestroy_0_nifb6mq6y1((&cc_5));}
    else {
      NB8 X60Qx_375;
      NB8 X60Qx_376;
      NB8 X60Qx_377;
      NB8 X60Qx_378 = eqQ_20_sysvq0asl(dt_2, (string_0_sysvq0asl){
        .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
      );
      if (X60Qx_378){
        X60Qx_377 = NIM_TRUE;}
      else {
        NB8 X60Qx_379 = eqQ_20_sysvq0asl(dt_2, (string_0_sysvq0asl){
          .bytes_0 = 1701603326u, .more_0 = (&strlit_0_I5723805845286553140_comaa5xpt1)}
        );
        X60Qx_377 = X60Qx_379;}
      if (X60Qx_377){
        X60Qx_376 = NIM_TRUE;}
      else {
        NB8 X60Qx_380 = eqQ_20_sysvq0asl(dt_2, (string_0_sysvq0asl){
          .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_comaa5xpt1)}
        );
        X60Qx_376 = X60Qx_380;}
      if (X60Qx_376){
        X60Qx_375 = NIM_TRUE;}
      else {
        NB8 X60Qx_381 = eqQ_20_sysvq0asl(dt_2, (string_0_sysvq0asl){
          .bytes_0 = 1635153150u, .more_0 = (&strlit_0_I13046452236886743244_comaa5xpt1)}
        );
        X60Qx_375 = X60Qx_381;}
      if (X60Qx_375){
        Local_0_decqocs071 loc_2 = asLocal_0_decqocs071(d_1, 1);
        NifKind_0_nif81dubp1 X60Qx_382 = kind_0_nifb6mq6y1(loc_2.val_0);
        if ((!(X60Qx_382 == 2))){
          X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 g_0 = importedGlobal_1_comaa5xpt1(c_54, s_25, loc_2.val_0);
          NI32 X60Qx_383 = emit_0_comaa5xpt1(ctx_26, 11, g_0.fld_0, g_0.fld_1);
          eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_2));
          nimStrDestroy(dt_2);
          eQdestroy_0_nifb6mq6y1((&d_1));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_1));
          nimStrDestroy(b_3);
          return;}
        else {
          NI32 X60Qx_384 = globalSlotFor_0_comaa5xpt1(c_54, s_25);
          NI32 X60Qx_385 = emit_0_comaa5xpt1(ctx_26, 8, X60Qx_384, 0);
          eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_2));
          nimStrDestroy(dt_2);
          eQdestroy_0_nifb6mq6y1((&d_1));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
          eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_1));
          nimStrDestroy(b_3);
          return;}
        eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_2));}
      else {
        NB8 X60Qx_386 = eqQ_20_sysvq0asl(dt_2, (string_0_sysvq0asl){
          .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I12999086881046019782_comaa5xpt1)}
        );
        if (X60Qx_386){
          Local_0_decqocs071 loc_3 = asLocal_0_decqocs071(d_1, 1);
          NifKind_0_nif81dubp1 X60Qx_387 = kind_0_nifb6mq6y1(loc_3.val_0);
          if ((!(X60Qx_387 == 2))){
            Cursor_0_nifb6mq6y1 vc_1 = loc_3.val_0;
            eQwasMoved_0_nifb6mq6y1((&loc_3.val_0));
            compileExpr_1_comaa5xpt1(c_54, ctx_26, (&vc_1));
            eQdestroy_0_nifb6mq6y1((&vc_1));
            eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_3));
            nimStrDestroy(dt_2);
            eQdestroy_0_nifb6mq6y1((&d_1));
            eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_1));
            nimStrDestroy(b_3);
            return;
            eQdestroy_0_nifb6mq6y1((&vc_1));}
          eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_3));}}}
    nimStrDestroy(dt_2);
    eQdestroy_0_nifb6mq6y1((&d_1));}
  NB8 X60Qx_388 = routineExistsVM_1_comaa5xpt1(c_54, s_25);
  if (X60Qx_388){
    NI32 X60Qx_389 = getProcIdx_1_comaa5xpt1(c_54, s_25);
    Value_0_valzr1t4f X60Qtmp_14 = (Value_0_valzr1t4f){
      .kind_0 = 15, .fn_0 = s_25, .pidx_0 = X60Qx_389, .env_0 = ((X60Qt_0_IArefSX43losureX45nvX4fbj0valzr1t4f_comaa5xpt1*)NIM_NIL), .resume_0 = ((NI32)0)}
    ;
    NI32 X60Qx_390 = addConst_0_comaa5xpt1(c_54, (&X60Qtmp_14));
    NI32 X60Qx_391 = emit_0_comaa5xpt1(ctx_26, 0, X60Qx_390, 0);
    NI32 X60Qx_392 = get_0_comaa5xpt1((*c_54).d_00.nestedSyms_0, s_25);
    if (0 <= X60Qx_392){
      NI32 X60Qx_393 = emit_0_comaa5xpt1(ctx_26, 33, 0, 0);}
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_14));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_1));
    nimStrDestroy(b_3);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_14));}
  NI32 X60Qx_394 = implicitGlobal_0_comaa5xpt1(c_54, s_25);
  NI32 X60Qx_395 = emit_0_comaa5xpt1(ctx_26, 8, X60Qx_394, 0);
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_4);
  eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&lc_1));
  nimStrDestroy(b_3);}
void compileExpr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_55, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_27, Cursor_0_nifb6mq6y1* n_25){
  NifKind_0_nif81dubp1 X60Qx_396 = kind_0_nifb6mq6y1((*n_25));
  switch (X60Qx_396){
    case 8:
    {
      NU32 X60Qx_397 = intId_0_nifb6mq6y1((*n_25));
      NI64* X60Qx_398 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_397);
      xint_0_xinat3x34 X60Qx_399 = createXint_0_xinat3x34((*X60Qx_398));
      Value_0_valzr1t4f X60Qtmp_15 = vIntX_0_valzr1t4f(X60Qx_399, 64);
      NI32 X60Qx_400 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_15));
      NI32 X60Qx_401 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_400, 0);
      inc_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_15));}
    break;
    case 9:
    {
      NU32 X60Qx_402 = uintId_0_nifb6mq6y1((*n_25));
      NU64* X60Qx_403 = getQ_0_Iebom0i1_ast8ri79k(pool_0_nifh7u8pu1.uintegers_0, X60Qx_402);
      Value_0_valzr1t4f X60Qtmp_16 = vUIntX_0_valzr1t4f((xint_0_xinat3x34){
        .nan_0 = NIM_FALSE, .neg_0 = NIM_FALSE, .val_0 = ((NU64)(*X60Qx_403))}
      , 64);
      NI32 X60Qx_404 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_16));
      NI32 X60Qx_405 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_404, 0);
      inc_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_16));}
    break;
    case 10:
    {
      NU32 X60Qx_406 = floatId_0_nifb6mq6y1((*n_25));
      NF64 X60Qx_407 = getQ_1_I4qx0py_ast8ri79k(pool_0_nifh7u8pu1.floats_0, X60Qx_406);
      Value_0_valzr1t4f X60Qtmp_17 = vFloat_0_valzr1t4f(X60Qx_407, 64);
      NI32 X60Qx_408 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_17));
      NI32 X60Qx_409 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_408, 0);
      inc_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_17));}
    break;
    case 7:
    {
      NC8 X60Qx_410 = charLit_0_nifb6mq6y1((*n_25));
      Value_0_valzr1t4f X60Qtmp_18 = vChar_0_valzr1t4f(X60Qx_410);
      NI32 X60Qx_411 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_18));
      NI32 X60Qx_412 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_411, 0);
      inc_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_18));}
    break;
    case 6:
    {
      NU32 X60Qx_413 = litId_0_nifb6mq6y1((*n_25));
      string_0_sysvq0asl* X60Qx_414 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_413);
      Value_0_valzr1t4f X60Qtmp_19 = vStr_0_valzr1t4f((*X60Qx_414));
      NI32 X60Qx_415 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_19));
      NI32 X60Qx_416 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_415, 0);
      inc_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_19));}
    break;
    case 4:
    {
      NU32 X60Qx_417 = symId_0_nifb6mq6y1((*n_25));
      resolveSymbol_1_comaa5xpt1(c_55, ctx_27, X60Qx_417);
      inc_0_nifb6mq6y1(n_25);}
    break;
    case 2:
    {
      NI32 X60Qx_418 = emit_0_comaa5xpt1(ctx_27, 1, 0, 0);
      inc_0_nifb6mq6y1(n_25);}
    break;
    case 11:
    {
      NimonyExpr_0_nimry5ra91 ek_1 = exprKind_1_nim30udrv((*n_25));
      string_0_sysvq0asl tag_2 = nodeTag_0_comaa5xpt1((*n_25));
      NB8 X60Qtc_42 = nimStrAtLe_0_sysvq0asl(tag_2, 4, (NC8)'t');
      if (X60Qtc_42){
        NB8 X60Qtc_43 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'i');
        if (X60Qtc_43){
          NB8 X60Qtc_44 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'d');
          if (X60Qtc_44){
            NB8 X60Qtc_45 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'e');
            if (X60Qtc_45){
              NB8 X60Qtc_46 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'b');
              if (X60Qtc_46){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1935762174u, .more_0 = (&strlit_0_I4543393450896359795_comaa5xpt1)}
                )){
                  goto X60Qsc_16;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I17573272885368898989_comaa5xpt1)}
                )){
                  goto X60Qsc_33;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I9217337746930322866_comaa5xpt1)}
                )){
                  goto X60Qsc_11;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I8939511674443647382_comaa5xpt1)}
                )){
                  goto X60Qsc_26;}}}
            else {
              NB8 X60Qtc_47 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'l');
              if (X60Qtc_47){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1953063678u, .more_0 = (&strlit_0_I6041839086284145320_comaa5xpt1)}
                )){
                  goto X60Qsc_8;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1869374206u, .more_0 = (&strlit_0_I9830314142150548690_comaa5xpt1)}
                )){
                  goto X60Qsc_24;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1634886398u, .more_0 = (&strlit_0_I14055597598996035090_comaa5xpt1)}
                )){
                  goto X60Qsc_33;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I3001676635385606767_comaa5xpt1)}
                )){
                  goto X60Qsc_34;}}}}
          else {
            NB8 X60Qtc_48 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'f');
            if (X60Qtc_48){
              NB8 X60Qtc_49 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'e');
              if (X60Qtc_49){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1869440510u, .more_0 = (&strlit_0_I7330775407653057337_comaa5xpt1)}
                )){
                  goto X60Qsc_19;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1936811518u, .more_0 = (&strlit_0_I17580784255599249694_comaa5xpt1)}
                )){
                  goto X60Qsc_39;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1818322686u, .more_0 = (&strlit_0_I3372626016653902757_comaa5xpt1)}
                )){
                  goto X60Qsc_1;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1767991038u, .more_0 = (&strlit_0_I14845204679832807538_comaa5xpt1)}
                )){
                  goto X60Qsc_21;}}}
            else {
              NB8 X60Qtc_50 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'h');
              if (X60Qtc_50){
                NB8 X60Qtc_51 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'c');
                if (X60Qtc_51){
                  if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_comaa5xpt1)}
                  )){
                    goto X60Qsc_11;}
                  else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1684105470u, .more_0 = (&strlit_0_I17469384850928897790_comaa5xpt1)}
                  )){
                    goto X60Qsc_27;}}
                else {
                  if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1701079294u, .more_0 = (&strlit_0_I4196580491060784277_comaa5xpt1)}
                  )){
                    goto X60Qsc_26;}}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I4161172010043268705_comaa5xpt1)}
                )){
                  goto X60Qsc_31;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1936615934u, .more_0 = (&strlit_0_I17286088029172964552_comaa5xpt1)}
                )){
                  goto X60Qsc_36;}}}}}
        else {
          NB8 X60Qtc_52 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'o');
          if (X60Qtc_52){
            NB8 X60Qtc_53 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'m');
            if (X60Qtc_53){
              NB8 X60Qtc_54 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'l');
              if (X60Qtc_54){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1936026878u, .more_0 = (&strlit_0_I7755216903854853291_comaa5xpt1)}
                )){
                  goto X60Qsc_39;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1937009918u, .more_0 = (&strlit_0_I6438757400198936067_comaa5xpt1)}
                )){
                  goto X60Qsc_39;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1852403198u, .more_0 = (&strlit_0_I896709357113617264_comaa5xpt1)}
                )){
                  goto X60Qsc_38;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1819635198u, .more_0 = (&strlit_0_I6462229405280805082_comaa5xpt1)}
                )){
                  goto X60Qsc_38;}}}
            else {
              NB8 X60Qtc_55 = nimStrAtLe_0_sysvq0asl(tag_2, 2, (NC8)'o');
              if (X60Qtc_55){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1734700798u, .more_0 = (&strlit_0_I186799702831424311_comaa5xpt1)}
                )){
                  goto X60Qsc_5;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1868787710u, .more_0 = (&strlit_0_I7084116572891045059_comaa5xpt1)}
                )){
                  goto X60Qsc_29;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I12337342044224817361_comaa5xpt1)}
                )){
                  goto X60Qsc_29;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I9268166327583521131_comaa5xpt1)}
                )){
                  goto X60Qsc_30;}}}}
          else {
            NB8 X60Qtc_56 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'p');
            if (X60Qtc_56){
              NB8 X60Qtc_57 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'l');
              if (X60Qtc_57){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I6487260469238205337_comaa5xpt1)}
                )){
                  goto X60Qsc_18;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1970041086u, .more_0 = (&strlit_0_I12557166611382145809_comaa5xpt1)}
                )){
                  goto X60Qsc_38;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1701998846u, .more_0 = (&strlit_0_I8954722698363393223_comaa5xpt1)}
                )){
                  goto X60Qsc_11;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1869771006u, .more_0 = (&strlit_0_I3485566669610392440_comaa5xpt1)}
                )){
                  goto X60Qsc_12;}}}
            else {
              NB8 X60Qtc_58 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'s');
              if (X60Qtc_58){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I7358334719788826533_comaa5xpt1)}
                )){
                  goto X60Qsc_35;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 2053731326u, .more_0 = (&strlit_0_I14042222260391466396_comaa5xpt1)}
                )){
                  goto X60Qsc_41;}}
              else {
                NB8 X60Qtc_59 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'t');
                if (X60Qtc_59){
                  if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I17716058327968275251_comaa5xpt1)}
                  )){
                    goto X60Qsc_29;}
                  else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I5323221927989235116_comaa5xpt1)}
                  )){
                    goto X60Qsc_32;}}
                else {
                  if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1919908094u, .more_0 = (&strlit_0_I11168045910199617169_comaa5xpt1)}
                  )){
                    goto X60Qsc_38;}}}}}}}
      else {
        NB8 X60Qtc_60 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'h');
        if (X60Qtc_60){
          NB8 X60Qtc_61 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'d');
          if (X60Qtc_61){
            NB8 X60Qtc_62 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'a');
            if (X60Qtc_62){
              NB8 X60Qtc_63 = nimStrAtLe_0_sysvq0asl(tag_2, 2, (NC8)'r');
              if (X60Qtc_63){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_comaa5xpt1)}
                )){
                  goto X60Qsc_11;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1918985214u, .more_0 = (&strlit_0_I655215872312446365_comaa5xpt1)}
                )){
                  goto X60Qsc_37;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I13909093427330098489_comaa5xpt1)}
                )){
                  goto X60Qsc_15;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_comaa5xpt1)}
                )){
                  goto X60Qsc_22;}}}
            else {
              NB8 X60Qtc_64 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'c');
              if (X60Qtc_64){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1868785918u, .more_0 = (&strlit_0_I710932595938440230_comaa5xpt1)}
                )){
                  goto X60Qsc_15;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1868784894u, .more_0 = (&strlit_0_I9667346611828510523_comaa5xpt1)}
                )){
                  goto X60Qsc_15;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1684300286u, .more_0 = (&strlit_0_I9557201018976274010_comaa5xpt1)}
                )){
                  goto X60Qsc_27;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1868850430u, .more_0 = (&strlit_0_I14457488926480995039_comaa5xpt1)}
                )){
                  goto X60Qsc_28;}}}}
          else {
            NB8 X60Qtc_65 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'c');
            if (X60Qtc_65){
              NB8 X60Qtc_66 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'a');
              if (X60Qtc_66){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1684955395u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_9;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 7627010u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_34;}}
              else {
                NB8 X60Qtc_67 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'m');
                if (X60Qtc_67){
                  if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1684890371u, .more_0 = NIM_NIL}
                  )){
                    goto X60Qsc_11;}}
                else {
                  if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2501487269769466366_comaa5xpt1)}
                  )){
                    goto X60Qsc_15;}
                  else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I10209608037894561257_comaa5xpt1)}
                  )){
                    goto X60Qsc_40;}}}}
            else {
              NB8 X60Qtc_68 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'e');
              if (X60Qtc_68){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I14418907618963914168_comaa5xpt1)}
                )){
                  goto X60Qsc_13;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I358872489388858575_comaa5xpt1)}
                )){
                  goto X60Qsc_14;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I13798915436014509391_comaa5xpt1)}
                )){
                  goto X60Qsc_20;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1953457155u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_28;}}}}}
        else {
          NB8 X60Qtc_69 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'n');
          if (X60Qtc_69){
            NB8 X60Qtc_70 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'m');
            if (X60Qtc_70){
              NB8 X60Qtc_71 = nimStrAtLe_0_sysvq0asl(tag_2, 2, (NC8)'f');
              if (X60Qtc_71){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1718511875u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_4;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1718512126u, .more_0 = (&strlit_0_I8390060478375454995_comaa5xpt1)}
                )){
                  goto X60Qsc_11;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1987014142u, .more_0 = (&strlit_0_I17583757001664695776_comaa5xpt1)}
                )){
                  goto X60Qsc_19;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 6711554u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_23;}}}
            else {
              NB8 X60Qtc_72 = nimStrAtLe_0_sysvq0asl(tag_2, 1, (NC8)'e');
              if (X60Qtc_72){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1851878915u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_6;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1734700547u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_8;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1818848771u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_2;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1953459715u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_7;}}}}
          else {
            NB8 X60Qtc_73 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'s');
            if (X60Qtc_73){
              NB8 X60Qtc_74 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'o');
              if (X60Qtc_74){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1719037699u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_3;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 7499522u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_9;}}
              else {
                NB8 X60Qtc_75 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'p');
                if (X60Qtc_75){
                  if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1918988291u, .more_0 = NIM_NIL}
                  )){
                    goto X60Qsc_18;}
                  else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1952542723u, .more_0 = NIM_NIL}
                  )){
                    goto X60Qsc_34;}}
                else {
                  if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                    .bytes_0 = 1718973187u, .more_0 = NIM_NIL}
                  )){
                    goto X60Qsc_17;}}}}
            else {
              NB8 X60Qtc_76 = nimStrAtLe_0_sysvq0asl(tag_2, 2, (NC8)'r');
              if (X60Qtc_76){
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1919907843u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_10;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1886745603u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_29;}}
              else {
                if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 1970435326u, .more_0 = (&strlit_0_I8572766038233537570_comaa5xpt1)}
                )){
                  goto X60Qsc_0;}
                else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
                  .bytes_0 = 2037543939u, .more_0 = NIM_NIL}
                )){
                  goto X60Qsc_25;}}}}}}
      goto X60Qsc_78;
      X60Qsc_0: ;
      Value_0_valzr1t4f X60Qtmp_20 = vBool_0_valzr1t4f(NIM_TRUE);
      NI32 X60Qx_419 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_20));
      NI32 X60Qx_420 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_419, 0);
      skip_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_20));
      goto X60Qsc_77;
      X60Qsc_1: ;
      Value_0_valzr1t4f X60Qtmp_21 = vBool_0_valzr1t4f(NIM_FALSE);
      NI32 X60Qx_421 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_21));
      NI32 X60Qx_422 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_421, 0);
      skip_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_21));
      goto X60Qsc_77;
      X60Qsc_2: ;
      NI32 X60Qx_423 = emit_0_comaa5xpt1(ctx_27, 1, 0, 0);
      skip_0_nifb6mq6y1(n_25);
      goto X60Qsc_77;
      X60Qsc_3: ;
      skip_0_nifb6mq6y1(n_25);
      NI32 X60Qx_424 = emit_0_comaa5xpt1(ctx_27, 18, 0, 0);
      goto X60Qsc_77;
      X60Qsc_4: ;
      NU64 X60Qx_425 = ((NU64)9218868437227405312ull);
      NF64 X60Qx_426;
      copyMem_0_sysvq0asl((&X60Qx_426), (&X60Qx_425), sizeof(NF64));
      Value_0_valzr1t4f X60Qtmp_22 = vFloat_0_valzr1t4f(X60Qx_426, 64);
      NI32 X60Qx_427 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_22));
      NI32 X60Qx_428 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_427, 0);
      skip_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_22));
      goto X60Qsc_77;
      X60Qsc_5: ;
      NU64 X60Qx_429 = ((NU64)18442240474082181120ull);
      NF64 X60Qx_430;
      copyMem_0_sysvq0asl((&X60Qx_430), (&X60Qx_429), sizeof(NF64));
      Value_0_valzr1t4f X60Qtmp_23 = vFloat_0_valzr1t4f(X60Qx_430, 64);
      NI32 X60Qx_431 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_23));
      NI32 X60Qx_432 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_431, 0);
      skip_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_23));
      goto X60Qsc_77;
      X60Qsc_6: ;
      NU64 X60Qx_433 = ((NU64)9221120237041090560ull);
      NF64 X60Qx_434;
      copyMem_0_sysvq0asl((&X60Qx_434), (&X60Qx_433), sizeof(NF64));
      Value_0_valzr1t4f X60Qtmp_24 = vFloat_0_valzr1t4f(X60Qx_434, 64);
      NI32 X60Qx_435 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_24));
      NI32 X60Qx_436 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_435, 0);
      skip_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_24));
      goto X60Qsc_77;
      X60Qsc_7: ;
      inc_0_nifb6mq6y1(n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_437 = addMagic_0_comaa5xpt1(c_55, ek_1, 64, NIM_TRUE, NIM_FALSE);
      NI32 X60Qx_438 = emit_0_comaa5xpt1(ctx_27, 20, X60Qx_437, 0);
      goto X60Qsc_77;
      X60Qsc_8: ;
      inc_0_nifb6mq6y1(n_25);
      NI32 bits_4 = 64;
      NB8 signed_3 = NIM_TRUE;
      readOptType_0_comaa5xpt1(n_25, (&bits_4), (&signed_3));
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_439 = addMagic_0_comaa5xpt1(c_55, ek_1, bits_4, signed_3, NIM_FALSE);
      NI32 X60Qx_440 = emit_0_comaa5xpt1(ctx_27, 20, X60Qx_439, 0);
      goto X60Qsc_77;
      X60Qsc_9: ;
      inc_0_nifb6mq6y1(n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      if (ek_1 == 17){
        NI32 jf_0 = emit_0_comaa5xpt1(ctx_27, 25, 0, 0);
        compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
        NI32 jend_0 = emit_0_comaa5xpt1(ctx_27, 24, 0, 0);
        NI32 X60Qx_441 = len_3_Icgec691_comaa5xpt1((*ctx_27).d_00.code_0);
        patch_0_comaa5xpt1(ctx_27, jf_0, X60Qx_441);
        Value_0_valzr1t4f X60Qtmp_25 = vBool_0_valzr1t4f(NIM_FALSE);
        NI32 X60Qx_442 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_25));
        NI32 X60Qx_443 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_442, 0);
        NI32 X60Qx_444 = len_3_Icgec691_comaa5xpt1((*ctx_27).d_00.code_0);
        patch_0_comaa5xpt1(ctx_27, jend_0, X60Qx_444);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_25));}
      else {
        NI32 jf_1 = emit_0_comaa5xpt1(ctx_27, 25, 0, 0);
        Value_0_valzr1t4f X60Qtmp_26 = vBool_0_valzr1t4f(NIM_TRUE);
        NI32 X60Qx_445 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_26));
        NI32 X60Qx_446 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_445, 0);
        NI32 jend_1 = emit_0_comaa5xpt1(ctx_27, 24, 0, 0);
        NI32 X60Qx_447 = len_3_Icgec691_comaa5xpt1((*ctx_27).d_00.code_0);
        patch_0_comaa5xpt1(ctx_27, jf_1, X60Qx_447);
        compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
        NI32 X60Qx_448 = len_3_Icgec691_comaa5xpt1((*ctx_27).d_00.code_0);
        patch_0_comaa5xpt1(ctx_27, jend_1, X60Qx_448);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_26));}
      consumeParRi_0_nifb6mq6y1(n_25);
      goto X60Qsc_77;
      X60Qsc_10: ;
      inc_0_nifb6mq6y1(n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_449 = addMagic_0_comaa5xpt1(c_55, ek_1, 64, NIM_TRUE, NIM_FALSE);
      NI32 X60Qx_450 = emit_0_comaa5xpt1(ctx_27, 19, X60Qx_449, 0);
      goto X60Qsc_77;
      X60Qsc_11: ;
      compileCall_1_comaa5xpt1(c_55, ctx_27, n_25, NIM_FALSE);
      goto X60Qsc_77;
      X60Qsc_12: ;
      compileCall_1_comaa5xpt1(c_55, ctx_27, n_25, NIM_TRUE);
      goto X60Qsc_77;
      X60Qsc_13: ;
      inc_0_nifb6mq6y1(n_25);
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_451 = kind_0_nifb6mq6y1((*n_25));
          if ((!(X60Qx_451 == 12))){
            skip_0_nifb6mq6y1(n_25);}
          else {
            break;}}}
      whileStmtLabel_0: ;
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_452 = emit_0_comaa5xpt1(ctx_27, 76, 0, 0);
      goto X60Qsc_77;
      X60Qsc_14: ;
      inc_0_nifb6mq6y1(n_25);
      NU32 dsym_0 = ((NU32)0u);
      NifKind_0_nif81dubp1 X60Qx_453 = kind_0_nifb6mq6y1((*n_25));
      if (X60Qx_453 == 4){
        NU32 X60Qx_454 = symId_0_nifb6mq6y1((*n_25));
        dsym_0 = X60Qx_454;}
      skip_0_nifb6mq6y1(n_25);
      NI32 dargc_0 = 0;
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_455 = kind_0_nifb6mq6y1((*n_25));
          if ((!(X60Qx_455 == 12))){
            compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
            inc_1_I6wjjge_aow2h993l1((&dargc_0));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      consumeParRi_0_nifb6mq6y1(n_25);
      NB8 X60Qx_456;
      if ((!(((NU32)dsym_0) == ((NU32)0u)))){
        NB8 X60Qx_457 = routineExistsVM_1_comaa5xpt1(c_55, dsym_0);
        X60Qx_456 = X60Qx_457;}
      else {
        X60Qx_456 = NIM_FALSE;}
      if (X60Qx_456){
        NI32 X60Qx_458 = getProcIdx_1_comaa5xpt1(c_55, dsym_0);
        NI32 X60Qx_459 = emit_0_comaa5xpt1(ctx_27, 77, X60Qx_458, dargc_0);}
      else {
        NI32 k_0 = 0;
        {
          while (k_0 < dargc_0){
            NI32 X60Qx_460 = emit_0_comaa5xpt1(ctx_27, 4, 0, 0);
            inc_1_I6wjjge_aow2h993l1((&k_0));}}
        whileStmtLabel_2: ;
        NI32 X60Qx_461 = emit_0_comaa5xpt1(ctx_27, 1, 0, 0);}
      goto X60Qsc_77;
      X60Qsc_15: ;
      compileConv_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_16: ;
      inc_0_nifb6mq6y1(n_25);
      skip_0_nifb6mq6y1(n_25);
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_462 = kind_0_nifb6mq6y1((*n_25));
          if ((!(X60Qx_462 == 12))){
            NifKind_0_nif81dubp1 X60Qx_463 = kind_0_nifb6mq6y1((*n_25));
            if (X60Qx_463 == 8){
              inc_0_nifb6mq6y1(n_25);}
            else {
              compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);}}
          else {
            break;}}}
      whileStmtLabel_3: ;
      consumeParRi_0_nifb6mq6y1(n_25);
      goto X60Qsc_77;
      X60Qsc_17: ;
      compileSuf_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_18: ;
      inc_0_nifb6mq6y1(n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      goto X60Qsc_77;
      X60Qsc_19: ;
      inc_0_nifb6mq6y1(n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_464 = kind_0_nifb6mq6y1((*n_25));
          if ((!(X60Qx_464 == 12))){
            skip_0_nifb6mq6y1(n_25);}
          else {
            break;}}}
      whileStmtLabel_4: ;
      consumeParRi_0_nifb6mq6y1(n_25);
      goto X60Qsc_77;
      X60Qsc_20: ;
      inc_0_nifb6mq6y1(n_25);
      NI32 count_0 = 0;
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_465 = kind_0_nifb6mq6y1((*n_25));
          if ((!(X60Qx_465 == 12))){
            Cursor_0_nifb6mq6y1 lookahead_0 = eQdup_0_nifb6mq6y1((*n_25));
            skip_0_nifb6mq6y1((&lookahead_0));
            NifKind_0_nif81dubp1 X60Qx_466 = kind_0_nifb6mq6y1(lookahead_0);
            if (X60Qx_466 == 12){
              compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);}
            else {
              compileStmt_1_comaa5xpt1(c_55, ctx_27, n_25);}
            inc_1_I6wjjge_aow2h993l1((&count_0));
            eQdestroy_0_nifb6mq6y1((&lookahead_0));}
          else {
            break;}}}
      whileStmtLabel_5: ;
      if (count_0 == 0){
        NI32 X60Qx_467 = emit_0_comaa5xpt1(ctx_27, 1, 0, 0);}
      consumeParRi_0_nifb6mq6y1(n_25);
      goto X60Qsc_77;
      X60Qsc_21: ;
      Value_0_valzr1t4f X60Qtmp_27 = vBool_0_valzr1t4f(NIM_FALSE);
      NI32 X60Qx_468 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_27));
      NI32 X60Qx_469 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_468, 0);
      skip_0_nifb6mq6y1(n_25);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_27));
      goto X60Qsc_77;
      X60Qsc_22: ;
      compileCaseExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_23: ;
      compileIfExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_24: ;
      inc_0_nifb6mq6y1(n_25);
      NU32 lbl_0 = ((NU32)0u);
      NifKind_0_nif81dubp1 X60Qx_470 = kind_0_nifb6mq6y1((*n_25));
      if (X60Qx_470 == 5){
        NU32 X60Qx_471 = symId_0_nifb6mq6y1((*n_25));
        lbl_0 = X60Qx_471;}
      skip_0_nifb6mq6y1(n_25);
      void* X60Qx_472 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1));
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_28 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_472);
      seq_0_Ift2sne_chu5m1rja1 X60Qx_473 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
      seq_0_Ift2sne_chu5m1rja1 X60Qx_474 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
      (*X60Qtmp_28) = (X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1){
        .r_00 = 0, .d_00 = (Loop_Obj_0_comaa5xpt1){
          .contTarget_0 = -1, .breaks_0 = X60Qx_473, .continues_0 = X60Qx_474, .label_0 = lbl_0}}
      ;
      add_0_Iuw4xx01_comaa5xpt1((&(*ctx_27).d_00.loops_0), X60Qtmp_28);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_475 = getQ_7_I6yhgto_comaa5xpt1((*ctx_27).d_00.loops_0, ((NI32)((*ctx_27).d_00.loops_0.len_0 - ((NI32)((NI32)1)))));
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* lp_0 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_475));
      {
        openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_0 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_0).d_00.continues_0);
        NI32 X60Qlf_1 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_476 = len_6_I9632ti1_comaa5xpt1(X60Qlf_0);
            if (X60Qlf_1 < X60Qx_476){
              {
                NI32* X60Qii_8 = getQ_10_I053icq_comaa5xpt1(X60Qlf_0, X60Qlf_1);
                NI32 X60Qx_477 = len_3_Icgec691_comaa5xpt1((*ctx_27).d_00.code_0);
                patch_0_comaa5xpt1(ctx_27, (*X60Qii_8), X60Qx_477);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_1));}
            else {
              break;}}}
        whileStmtLabel_7: ;}
      forStmtLabel_6: ;
      {
        openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_2 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_0).d_00.breaks_0);
        NI32 X60Qlf_3 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_478 = len_6_I9632ti1_comaa5xpt1(X60Qlf_2);
            if (X60Qlf_3 < X60Qx_478){
              {
                NI32* X60Qii_11 = getQ_10_I053icq_comaa5xpt1(X60Qlf_2, X60Qlf_3);
                NI32 X60Qx_479 = len_3_Icgec691_comaa5xpt1((*ctx_27).d_00.code_0);
                patch_0_comaa5xpt1(ctx_27, (*X60Qii_11), X60Qx_479);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_3));}
            else {
              break;}}}
        whileStmtLabel_10: ;}
      forStmtLabel_9: ;
      NI32 X60Qx_480 = len_3_Ij0uoqp_comaa5xpt1((*ctx_27).d_00.loops_0);
      setLen_0_Ivhuv1v1_comaa5xpt1((&(*ctx_27).d_00.loops_0), ((NI32)(X60Qx_480 - 1)));
      consumeParRi_0_nifb6mq6y1(n_25);
      eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(lp_0);
      goto X60Qsc_77;
      X60Qsc_25: ;
      compileTryExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_26: ;
      inc_0_nifb6mq6y1(n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_481 = emit_0_comaa5xpt1(ctx_27, 13, 0, 0);
      goto X60Qsc_77;
      X60Qsc_27: ;
      inc_0_nifb6mq6y1(n_25);
      compileAddr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      goto X60Qsc_77;
      X60Qsc_28: ;
      inc_0_nifb6mq6y1(n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      NU32 fsym_0 = ((NU32)0u);
      NifKind_0_nif81dubp1 X60Qx_482 = kind_0_nifb6mq6y1((*n_25));
      if (X60Qx_482 == 4){
        NU32 X60Qx_483 = symId_0_nifb6mq6y1((*n_25));
        fsym_0 = X60Qx_483;}
      skip_0_nifb6mq6y1(n_25);
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_484 = kind_0_nifb6mq6y1((*n_25));
          if ((!(X60Qx_484 == 12))){
            skip_0_nifb6mq6y1(n_25);}
          else {
            break;}}}
      whileStmtLabel_12: ;
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_485 = addFieldSym_0_comaa5xpt1(c_55, fsym_0);
      NI32 X60Qx_486 = emit_0_comaa5xpt1(ctx_27, 41, X60Qx_485, 0);
      goto X60Qsc_77;
      X60Qsc_29: ;
      compileConstr_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_30: ;
      inc_0_nifb6mq6y1(n_25);
      NifKind_0_nif81dubp1 X60Qx_487 = kind_0_nifb6mq6y1((*n_25));
      if (X60Qx_487 == 11){
        skip_0_nifb6mq6y1(n_25);}
      else {
        NifKind_0_nif81dubp1 X60Qx_488 = kind_0_nifb6mq6y1((*n_25));
        if (X60Qx_488 == 4){
          inc_0_nifb6mq6y1(n_25);}}
      NifKind_0_nif81dubp1 X60Qx_489 = kind_0_nifb6mq6y1((*n_25));
      if ((!(X60Qx_489 == 12))){
        compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);}
      else {
        NI32 X60Qx_490 = emit_0_comaa5xpt1(ctx_27, 1, 0, 0);}
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_491 = kind_0_nifb6mq6y1((*n_25));
          if ((!(X60Qx_491 == 12))){
            skip_0_nifb6mq6y1(n_25);}
          else {
            break;}}}
      whileStmtLabel_13: ;
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_492 = emit_0_comaa5xpt1(ctx_27, 39, 0, 0);
      goto X60Qsc_77;
      X60Qsc_31: ;
      compileInstanceOf_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_32: ;
      emitTupIndex_1_comaa5xpt1(c_55, ctx_27, n_25, NIM_FALSE);
      goto X60Qsc_77;
      X60Qsc_33: ;
      compileArrayConstr_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_34: ;
      compileIndexGet_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_35: ;
      compileSetConstr_1_comaa5xpt1(c_55, ctx_27, n_25);
      goto X60Qsc_77;
      X60Qsc_36: ;
      inc_0_nifb6mq6y1(n_25);
      NifKind_0_nif81dubp1 X60Qx_493 = kind_0_nifb6mq6y1((*n_25));
      if (X60Qx_493 == 11){
        skip_0_nifb6mq6y1(n_25);}
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_494 = emit_0_comaa5xpt1(ctx_27, 57, 0, 0);
      goto X60Qsc_77;
      X60Qsc_37: ;
      inc_0_nifb6mq6y1(n_25);
      NifKind_0_nif81dubp1 X60Qx_495 = kind_0_nifb6mq6y1((*n_25));
      if (X60Qx_495 == 11){
        skip_0_nifb6mq6y1(n_25);}
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_496 = emit_0_comaa5xpt1(ctx_27, 58, 0, 0);
      goto X60Qsc_77;
      X60Qsc_38: ;
      inc_0_nifb6mq6y1(n_25);
      NifKind_0_nif81dubp1 X60Qx_497 = kind_0_nifb6mq6y1((*n_25));
      if (X60Qx_497 == 11){
        skip_0_nifb6mq6y1(n_25);}
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 mode_1 = 0;
      NB8 X60Qtc_82 = nimStrAtLe_0_sysvq0asl(tag_2, 0, (NC8)'m');
      if (X60Qtc_82){
        if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
          .bytes_0 = 1852403198u, .more_0 = (&strlit_0_I896709357113617264_comaa5xpt1)}
        )){
          goto X60Qsc_80;}
        else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
          .bytes_0 = 1819635198u, .more_0 = (&strlit_0_I6462229405280805082_comaa5xpt1)}
        )){
          goto X60Qsc_81;}}
      else {
        if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
          .bytes_0 = 1970041086u, .more_0 = (&strlit_0_I12557166611382145809_comaa5xpt1)}
        )){
          goto X60Qsc_79;}}
      goto X60Qsc_84;
      X60Qsc_79: ;
      mode_1 = 0;
      goto X60Qsc_83;
      X60Qsc_80: ;
      mode_1 = 1;
      goto X60Qsc_83;
      X60Qsc_81: ;
      mode_1 = 2;
      goto X60Qsc_83;
      X60Qsc_84: ;
      mode_1 = 3;
      X60Qsc_83: ;
      NI32 X60Qx_498 = emit_0_comaa5xpt1(ctx_27, 59, mode_1, 0);
      goto X60Qsc_77;
      X60Qsc_39: ;
      NI64 X60Qx_1;
      if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
        .bytes_0 = 1936026878u, .more_0 = (&strlit_0_I7755216903854853291_comaa5xpt1)}
      )){
        goto X60Qsc_85;}
      else if (equalStrings_0_sysvq0asl(tag_2, (string_0_sysvq0asl){
        .bytes_0 = 1937009918u, .more_0 = (&strlit_0_I6438757400198936067_comaa5xpt1)}
      )){
        goto X60Qsc_86;}
      goto X60Qsc_88;
      X60Qsc_85: ;
      X60Qx_1 = 1;
      goto X60Qsc_87;
      X60Qsc_86: ;
      X60Qx_1 = 2;
      goto X60Qsc_87;
      X60Qsc_88: ;
      X60Qx_1 = 0;
      X60Qsc_87: ;
      NI32 mode_2 = X60Qx_1;
      inc_0_nifb6mq6y1(n_25);
      NifKind_0_nif81dubp1 X60Qx_499 = kind_0_nifb6mq6y1((*n_25));
      if (X60Qx_499 == 11){
        skip_0_nifb6mq6y1(n_25);}
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
      consumeParRi_0_nifb6mq6y1(n_25);
      NI32 X60Qx_500 = emit_0_comaa5xpt1(ctx_27, 60, mode_2, 0);
      goto X60Qsc_77;
      X60Qsc_40: ;
      NI32 X60Qx_501 = emit_0_comaa5xpt1(ctx_27, 1, 0, 0);
      skip_0_nifb6mq6y1(n_25);
      goto X60Qsc_77;
      X60Qsc_41: ;
      inc_0_nifb6mq6y1(n_25);
      Cursor_0_nifb6mq6y1 typeCur_2 = eQdup_0_nifb6mq6y1((*n_25));
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_502 = kind_0_nifb6mq6y1((*n_25));
          if ((!(X60Qx_502 == 12))){
            skip_0_nifb6mq6y1(n_25);}
          else {
            break;}}}
      whileStmtLabel_14: ;
      consumeParRi_0_nifb6mq6y1(n_25);
      SizeAlign_0_siz2wt1it X60Qx_503 = sizeAlignOfType_0_siz2wt1it(typeCur_2, 0);
      NI32 sz_0 = X60Qx_503.size_0;
      if (0 <= sz_0){
        Value_0_valzr1t4f X60Qtmp_29 = vInt_0_valzr1t4f(((NI64)sz_0), 64);
        NI32 X60Qx_504 = addConst_0_comaa5xpt1(c_55, (&X60Qtmp_29));
        NI32 X60Qx_505 = emit_0_comaa5xpt1(ctx_27, 0, X60Qx_504, 0);
        eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_29));}
      else {
        NI32 X60Qx_506 = emit_0_comaa5xpt1(ctx_27, 1, 0, 0);}
      eQdestroy_0_nifb6mq6y1((&typeCur_2));
      goto X60Qsc_77;
      X60Qsc_78: ;
      NB8 X60Qx_507 = isBinMagicOp_0_comaa5xpt1(ek_1);
      if (X60Qx_507){
        inc_0_nifb6mq6y1(n_25);
        NI32 bits_5 = 64;
        NB8 signed_4 = NIM_TRUE;
        NU32 enumTy_0 = ((NU32)0u);
        NB8 X60Qx_508;
        NifKind_0_nif81dubp1 X60Qx_509 = kind_0_nifb6mq6y1((*n_25));
        if (X60Qx_509 == 4){
          NU32 X60Qx_510 = symId_0_nifb6mq6y1((*n_25));
          NB8 X60Qx_511 = isEnumType_0_runot4689(X60Qx_510);
          X60Qx_508 = X60Qx_511;}
        else {
          X60Qx_508 = NIM_FALSE;}
        if (X60Qx_508){
          switch (ek_1){
            case 33:
            case 34:
            case 35:
            case 36:
            case 37:
            case 40:
            case 41:
            case 42:
            case 39:
            case 38:
            case 245:
            {
              NU32 X60Qx_512 = symId_0_nifb6mq6y1((*n_25));
              enumTy_0 = X60Qx_512;}
            break;
            default:
            {
              }
            break;}}
        readOptType_0_comaa5xpt1(n_25, (&bits_5), (&signed_4));
        compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
        compileExpr_1_comaa5xpt1(c_55, ctx_27, n_25);
        consumeParRi_0_nifb6mq6y1(n_25);
        NI32 X60Qx_513 = addMagic_0_comaa5xpt1(c_55, ek_1, bits_5, signed_4, NIM_FALSE);
        NI32 X60Qx_514 = emit_0_comaa5xpt1(ctx_27, 19, X60Qx_513, 0);
        NB8 X60Qx_515 = eqQ_0_nifh7u8pu1(enumTy_0, ((NU32)0u));
        if ((!X60Qx_515)){
          NI32 X60Qx_516 = addEnumWrap_0_comaa5xpt1(c_55, enumTy_0);
          NI32 X60Qx_517 = emit_0_comaa5xpt1(ctx_27, 23, X60Qx_516, 0);}}
      else {
        NI32 X60Qx_518 = emit_0_comaa5xpt1(ctx_27, 1, 0, 0);
        skip_0_nifb6mq6y1(n_25);}
      X60Qsc_77: ;
      nimStrDestroy(tag_2);}
    break;
    default:
    {
      NI32 X60Qx_519 = emit_0_comaa5xpt1(ctx_27, 1, 0, 0);
      inc_0_nifb6mq6y1(n_25);}
    break;}}
void compileAddr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_56, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_28, Cursor_0_nifb6mq6y1* n_26){
  NifKind_0_nif81dubp1 X60Qx_520 = kind_0_nifb6mq6y1((*n_26));
  if (X60Qx_520 == 4){
    NU32 sym_1 = symId_0_nifb6mq6y1((*n_26));
    inc_0_nifb6mq6y1(n_26);
    NI32 ls_1 = get_0_comaa5xpt1((*ctx_28).d_00.smap_0, sym_1);
    if (0 <= ls_1){
      NI32 X60Qx_521 = emit_0_comaa5xpt1(ctx_28, 7, ls_1, 0);}
    else {
      NI32 gs_2 = get_0_comaa5xpt1((*c_56).d_00.gmap_0, sym_1);
      if (0 <= gs_2){
        NI32 X60Qx_522 = emit_0_comaa5xpt1(ctx_28, 10, gs_2, 0);}
      else {
        NB8 X60Qx_523 = capturedSym_0_comaa5xpt1(c_56, ctx_28, sym_1);
        if (X60Qx_523){
          NI32 X60Qx_524 = addEnvSym_0_comaa5xpt1(c_56, sym_1);
          NI32 X60Qx_525 = emit_0_comaa5xpt1(ctx_28, 32, X60Qx_524, 0);}
        else {
          X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 ig_0 = importedGlobalAddr_0_comaa5xpt1(c_56, sym_1);
          if (0 <= ig_0.fld_0){
            NI32 X60Qx_526 = emit_0_comaa5xpt1(ctx_28, 12, ig_0.fld_0, ig_0.fld_1);}
          else {
            NI32 X60Qx_527 = emit_0_comaa5xpt1(ctx_28, 1, 0, 0);}}}}}
  else {
    NB8 X60Qx_56;
    NifKind_0_nif81dubp1 X60Qx_528 = kind_0_nifb6mq6y1((*n_26));
    if (X60Qx_528 == 11){
      NB8 X60Qx_57;
      string_0_sysvq0asl X60Qtmp_30 = nodeTag_0_comaa5xpt1((*n_26));
      NB8 X60Qx_529 = eqQ_20_sysvq0asl(X60Qtmp_30, (string_0_sysvq0asl){
        .bytes_0 = 1701079294u, .more_0 = (&strlit_0_I4196580491060784277_comaa5xpt1)}
      );
      if (X60Qx_529){
        X60Qx_57 = NIM_TRUE;}
      else {
        string_0_sysvq0asl X60Qtmp_31 = nodeTag_0_comaa5xpt1((*n_26));
        NB8 X60Qx_530 = eqQ_20_sysvq0asl(X60Qtmp_31, (string_0_sysvq0asl){
          .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I8939511674443647382_comaa5xpt1)}
        );
        X60Qx_57 = X60Qx_530;
        nimStrDestroy(X60Qtmp_31);}
      X60Qx_56 = X60Qx_57;
      nimStrDestroy(X60Qtmp_30);}
    else {
      X60Qx_56 = NIM_FALSE;}
    if (X60Qx_56){
      inc_0_nifb6mq6y1(n_26);
      compileExpr_1_comaa5xpt1(c_56, ctx_28, n_26);
      consumeParRi_0_nifb6mq6y1(n_26);}
    else {
      NB8 X60Qx_58;
      NifKind_0_nif81dubp1 X60Qx_531 = kind_0_nifb6mq6y1((*n_26));
      if (X60Qx_531 == 11){
        NB8 X60Qx_59;
        string_0_sysvq0asl X60Qtmp_32 = nodeTag_0_comaa5xpt1((*n_26));
        NB8 X60Qx_532 = eqQ_20_sysvq0asl(X60Qtmp_32, (string_0_sysvq0asl){
          .bytes_0 = 1953457155u, .more_0 = NIM_NIL}
        );
        if (X60Qx_532){
          X60Qx_59 = NIM_TRUE;}
        else {
          string_0_sysvq0asl X60Qtmp_33 = nodeTag_0_comaa5xpt1((*n_26));
          NB8 X60Qx_533 = eqQ_20_sysvq0asl(X60Qtmp_33, (string_0_sysvq0asl){
            .bytes_0 = 1868850430u, .more_0 = (&strlit_0_I14457488926480995039_comaa5xpt1)}
          );
          X60Qx_59 = X60Qx_533;
          nimStrDestroy(X60Qtmp_33);}
        X60Qx_58 = X60Qx_59;
        nimStrDestroy(X60Qtmp_32);}
      else {
        X60Qx_58 = NIM_FALSE;}
      if (X60Qx_58){
        emitFieldAddr_1_comaa5xpt1(c_56, ctx_28, n_26);}
      else {
        NB8 X60Qx_60;
        NifKind_0_nif81dubp1 X60Qx_534 = kind_0_nifb6mq6y1((*n_26));
        if (X60Qx_534 == 11){
          string_0_sysvq0asl X60Qtmp_34 = nodeTag_0_comaa5xpt1((*n_26));
          NB8 X60Qx_535 = eqQ_20_sysvq0asl(X60Qtmp_34, (string_0_sysvq0asl){
            .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I5323221927989235116_comaa5xpt1)}
          );
          X60Qx_60 = X60Qx_535;
          nimStrDestroy(X60Qtmp_34);}
        else {
          X60Qx_60 = NIM_FALSE;}
        if (X60Qx_60){
          emitTupIndex_1_comaa5xpt1(c_56, ctx_28, n_26, NIM_TRUE);}
        else {
          NB8 X60Qx_2;
          string_0_sysvq0asl t_11;
          nimStrWasMoved((&t_11));
          NifKind_0_nif81dubp1 X60Qx_536 = kind_0_nifb6mq6y1((*n_26));
          if (X60Qx_536 == 11){
            nimStrDestroy(t_11);
            string_0_sysvq0asl X60Qx_537 = nodeTag_0_comaa5xpt1((*n_26));
            t_11 = X60Qx_537;
            NB8 X60Qx_538;
            NB8 X60Qx_539;
            NB8 X60Qx_540 = eqQ_20_sysvq0asl(t_11, (string_0_sysvq0asl){
              .bytes_0 = 7627010u, .more_0 = NIM_NIL}
            );
            if (X60Qx_540){
              X60Qx_539 = NIM_TRUE;}
            else {
              NB8 X60Qx_541 = eqQ_20_sysvq0asl(t_11, (string_0_sysvq0asl){
                .bytes_0 = 1952542723u, .more_0 = NIM_NIL}
              );
              X60Qx_539 = X60Qx_541;}
            if (X60Qx_539){
              X60Qx_538 = NIM_TRUE;}
            else {
              NB8 X60Qx_542 = eqQ_20_sysvq0asl(t_11, (string_0_sysvq0asl){
                .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I3001676635385606767_comaa5xpt1)}
              );
              X60Qx_538 = X60Qx_542;}
            X60Qx_2 = X60Qx_538;}
          else {
            X60Qx_2 = NIM_FALSE;}
          if (X60Qx_2){
            inc_0_nifb6mq6y1(n_26);
            compileExpr_1_comaa5xpt1(c_56, ctx_28, n_26);
            compileExpr_1_comaa5xpt1(c_56, ctx_28, n_26);
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_543 = kind_0_nifb6mq6y1((*n_26));
                if ((!(X60Qx_543 == 12))){
                  skip_0_nifb6mq6y1(n_26);}
                else {
                  break;}}}
            whileStmtLabel_0: ;
            consumeParRi_0_nifb6mq6y1(n_26);
            NI32 X60Qx_544 = emit_0_comaa5xpt1(ctx_28, 49, 0, 0);}
          else {
            compileExpr_1_comaa5xpt1(c_56, ctx_28, n_26);}
          nimStrDestroy(t_11);}}}}}
void emitFieldAddr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_57, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_29, Cursor_0_nifb6mq6y1* n_27){
  inc_0_nifb6mq6y1(n_27);
  NB8 X60Qx_3;
  string_0_sysvq0asl rt_0;
  nimStrWasMoved((&rt_0));
  NifKind_0_nif81dubp1 X60Qx_545 = kind_0_nifb6mq6y1((*n_27));
  if (X60Qx_545 == 11){
    nimStrDestroy(rt_0);
    string_0_sysvq0asl X60Qx_546 = nodeTag_0_comaa5xpt1((*n_27));
    rt_0 = X60Qx_546;
    NB8 X60Qx_547;
    NB8 X60Qx_548;
    NB8 X60Qx_549;
    NB8 X60Qx_550;
    NB8 X60Qx_551;
    NB8 X60Qx_552;
    NB8 X60Qx_553;
    NB8 X60Qx_554 = eqQ_20_sysvq0asl(rt_0, (string_0_sysvq0asl){
      .bytes_0 = 7627010u, .more_0 = NIM_NIL}
    );
    if (X60Qx_554){
      X60Qx_553 = NIM_TRUE;}
    else {
      NB8 X60Qx_555 = eqQ_20_sysvq0asl(rt_0, (string_0_sysvq0asl){
        .bytes_0 = 1952542723u, .more_0 = NIM_NIL}
      );
      X60Qx_553 = X60Qx_555;}
    if (X60Qx_553){
      X60Qx_552 = NIM_TRUE;}
    else {
      NB8 X60Qx_556 = eqQ_20_sysvq0asl(rt_0, (string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I3001676635385606767_comaa5xpt1)}
      );
      X60Qx_552 = X60Qx_556;}
    if (X60Qx_552){
      X60Qx_551 = NIM_TRUE;}
    else {
      NB8 X60Qx_557 = eqQ_20_sysvq0asl(rt_0, (string_0_sysvq0asl){
        .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I5323221927989235116_comaa5xpt1)}
      );
      X60Qx_551 = X60Qx_557;}
    if (X60Qx_551){
      X60Qx_550 = NIM_TRUE;}
    else {
      NB8 X60Qx_558 = eqQ_20_sysvq0asl(rt_0, (string_0_sysvq0asl){
        .bytes_0 = 1953457155u, .more_0 = NIM_NIL}
      );
      X60Qx_550 = X60Qx_558;}
    if (X60Qx_550){
      X60Qx_549 = NIM_TRUE;}
    else {
      NB8 X60Qx_559 = eqQ_20_sysvq0asl(rt_0, (string_0_sysvq0asl){
        .bytes_0 = 1868850430u, .more_0 = (&strlit_0_I14457488926480995039_comaa5xpt1)}
      );
      X60Qx_549 = X60Qx_559;}
    if (X60Qx_549){
      X60Qx_548 = NIM_TRUE;}
    else {
      NB8 X60Qx_560 = eqQ_20_sysvq0asl(rt_0, (string_0_sysvq0asl){
        .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I8939511674443647382_comaa5xpt1)}
      );
      X60Qx_548 = X60Qx_560;}
    if (X60Qx_548){
      X60Qx_547 = NIM_TRUE;}
    else {
      NB8 X60Qx_561 = eqQ_20_sysvq0asl(rt_0, (string_0_sysvq0asl){
        .bytes_0 = 1701079294u, .more_0 = (&strlit_0_I4196580491060784277_comaa5xpt1)}
      );
      X60Qx_547 = X60Qx_561;}
    X60Qx_3 = X60Qx_547;}
  else {
    X60Qx_3 = NIM_FALSE;}
  if (X60Qx_3){
    compileAddr_1_comaa5xpt1(c_57, ctx_29, n_27);}
  else {
    compileExpr_1_comaa5xpt1(c_57, ctx_29, n_27);}
  NU32 fsym_1 = ((NU32)0u);
  NifKind_0_nif81dubp1 X60Qx_562 = kind_0_nifb6mq6y1((*n_27));
  if (X60Qx_562 == 4){
    NU32 X60Qx_563 = symId_0_nifb6mq6y1((*n_27));
    fsym_1 = X60Qx_563;}
  skip_0_nifb6mq6y1(n_27);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_564 = kind_0_nifb6mq6y1((*n_27));
      if ((!(X60Qx_564 == 12))){
        skip_0_nifb6mq6y1(n_27);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_27);
  NI32 X60Qx_565 = addFieldSym_0_comaa5xpt1(c_57, fsym_1);
  NI32 X60Qx_566 = emit_0_comaa5xpt1(ctx_29, 42, X60Qx_565, 0);
  nimStrDestroy(rt_0);}
void emitTupIndex_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_58, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_30, Cursor_0_nifb6mq6y1* n_28, NB8 wantAddr_1){
  inc_0_nifb6mq6y1(n_28);
  compileExpr_1_comaa5xpt1(c_58, ctx_30, n_28);
  compileExpr_1_comaa5xpt1(c_58, ctx_30, n_28);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_567 = kind_0_nifb6mq6y1((*n_28));
      if ((!(X60Qx_567 == 12))){
        skip_0_nifb6mq6y1(n_28);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_28);
  if (wantAddr_1){
    NI32 X60Qx_568 = emit_0_comaa5xpt1(ctx_30, 44, 0, 0);}
  else {
    NI32 X60Qx_569 = emit_0_comaa5xpt1(ctx_30, 43, 0, 0);}}
void compileConstr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_59, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_31, Cursor_0_nifb6mq6y1* n_29){
  string_0_sysvq0asl tag_3 = nodeTag_0_comaa5xpt1((*n_29));
  inc_0_nifb6mq6y1(n_29);
  NU32 typeSym_5 = ((NU32)0u);
  NifKind_0_nif81dubp1 X60Qx_570 = kind_0_nifb6mq6y1((*n_29));
  if (X60Qx_570 == 4){
    NU32 X60Qx_571 = symId_0_nifb6mq6y1((*n_29));
    typeSym_5 = X60Qx_571;
    skip_0_nifb6mq6y1(n_29);}
  else {
    NifKind_0_nif81dubp1 X60Qx_572 = kind_0_nifb6mq6y1((*n_29));
    if (X60Qx_572 == 11){
      string_0_sysvq0asl X60Qtmp_35 = nodeTag_0_comaa5xpt1((*n_29));
      NB8 X60Qx_573 = eqQ_20_sysvq0asl(X60Qtmp_35, (string_0_sysvq0asl){
        .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
      );
      if (X60Qx_573){
        Cursor_0_nifb6mq6y1 cc_6 = eQdup_0_nifb6mq6y1((*n_29));
        inc_0_nifb6mq6y1((&cc_6));
        NifKind_0_nif81dubp1 X60Qx_574 = kind_0_nifb6mq6y1(cc_6);
        if (X60Qx_574 == 4){
          NU32 X60Qx_575 = symId_0_nifb6mq6y1(cc_6);
          typeSym_5 = X60Qx_575;}
        eQdestroy_0_nifb6mq6y1((&cc_6));}
      skip_0_nifb6mq6y1(n_29);
      nimStrDestroy(X60Qtmp_35);}}
  NB8 X60Qx_61;
  NB8 X60Qx_576;
  NB8 X60Qx_577 = eqQ_20_sysvq0asl(tag_3, (string_0_sysvq0asl){
    .bytes_0 = 1868787710u, .more_0 = (&strlit_0_I7084116572891045059_comaa5xpt1)}
  );
  if (X60Qx_577){
    NB8 X60Qx_578 = eqQ_0_nifh7u8pu1(typeSym_5, ((NU32)0u));
    X60Qx_576 = (!X60Qx_578);}
  else {
    X60Qx_576 = NIM_FALSE;}
  if (X60Qx_576){
    string_0_sysvq0asl X60Qtmp_36 = baseName_0_comaa5xpt1(typeSym_5);
    NB8 X60Qx_579 = eqQ_20_sysvq0asl(X60Qtmp_36, (string_0_sysvq0asl){
      .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
    );
    X60Qx_61 = X60Qx_579;
    nimStrDestroy(X60Qtmp_36);}
  else {
    X60Qx_61 = NIM_FALSE;}
  if (X60Qx_61){
    Cursor_0_nifb6mq6y1 dataCur_0 = (Cursor_0_nifb6mq6y1){
      .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
    ;
    NB8 haveData_0 = NIM_FALSE;
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_580 = kind_0_nifb6mq6y1((*n_29));
        if ((!(X60Qx_580 == 12))){
          NB8 X60Qx_62;
          NifKind_0_nif81dubp1 X60Qx_581 = kind_0_nifb6mq6y1((*n_29));
          if (X60Qx_581 == 11){
            string_0_sysvq0asl X60Qtmp_37 = nodeTag_0_comaa5xpt1((*n_29));
            NB8 X60Qx_582 = eqQ_20_sysvq0asl(X60Qtmp_37, (string_0_sysvq0asl){
              .bytes_0 = 7760642u, .more_0 = NIM_NIL}
            );
            X60Qx_62 = X60Qx_582;
            nimStrDestroy(X60Qtmp_37);}
          else {
            X60Qx_62 = NIM_FALSE;}
          if (X60Qx_62){
            Cursor_0_nifb6mq6y1 kv_0 = eQdup_0_nifb6mq6y1((*n_29));
            inc_0_nifb6mq6y1((&kv_0));
            NB8 X60Qx_63;
            NifKind_0_nif81dubp1 X60Qx_583 = kind_0_nifb6mq6y1(kv_0);
            if (X60Qx_583 == 4){
              NU32 X60Qx_584 = symId_0_nifb6mq6y1(kv_0);
              string_0_sysvq0asl X60Qtmp_38 = baseName_0_comaa5xpt1(X60Qx_584);
              NB8 X60Qx_585 = eqQ_20_sysvq0asl(X60Qtmp_38, (string_0_sysvq0asl){
                .bytes_0 = 1952539902u, .more_0 = (&strlit_0_I12477614342947401988_comaa5xpt1)}
              );
              X60Qx_63 = X60Qx_585;
              nimStrDestroy(X60Qtmp_38);}
            else {
              X60Qx_63 = NIM_FALSE;}
            if (X60Qx_63){
              skip_0_nifb6mq6y1((&kv_0));
              eQdestroy_0_nifb6mq6y1((&dataCur_0));
              dataCur_0 = kv_0;
              eQwasMoved_0_nifb6mq6y1((&kv_0));
              haveData_0 = NIM_TRUE;}
            eQdestroy_0_nifb6mq6y1((&kv_0));}
          skip_0_nifb6mq6y1(n_29);}
        else {
          break;}}}
    whileStmtLabel_0: ;
    consumeParRi_0_nifb6mq6y1(n_29);
    NI32 elemCount_0 = 0;
    if (haveData_0){
      Cursor_0_nifb6mq6y1 d_2 = dataCur_0;
      eQwasMoved_0_nifb6mq6y1((&dataCur_0));
      NB8 X60Qx_64;
      NifKind_0_nif81dubp1 X60Qx_586 = kind_0_nifb6mq6y1(d_2);
      if (X60Qx_586 == 11){
        string_0_sysvq0asl X60Qtmp_39 = nodeTag_0_comaa5xpt1(d_2);
        NB8 X60Qx_587 = eqQ_20_sysvq0asl(X60Qtmp_39, (string_0_sysvq0asl){
          .bytes_0 = 1684300286u, .more_0 = (&strlit_0_I9557201018976274010_comaa5xpt1)}
        );
        X60Qx_64 = X60Qx_587;
        nimStrDestroy(X60Qtmp_39);}
      else {
        X60Qx_64 = NIM_FALSE;}
      if (X60Qx_64){
        inc_0_nifb6mq6y1((&d_2));}
      NB8 X60Qx_65;
      NifKind_0_nif81dubp1 X60Qx_588 = kind_0_nifb6mq6y1(d_2);
      if (X60Qx_588 == 11){
        string_0_sysvq0asl X60Qtmp_40 = nodeTag_0_comaa5xpt1(d_2);
        NB8 X60Qx_589 = eqQ_20_sysvq0asl(X60Qtmp_40, (string_0_sysvq0asl){
          .bytes_0 = 1868784126u, .more_0 = (&strlit_0_I17573272885368898989_comaa5xpt1)}
        );
        X60Qx_65 = X60Qx_589;
        nimStrDestroy(X60Qtmp_40);}
      else {
        X60Qx_65 = NIM_FALSE;}
      if (X60Qx_65){
        inc_0_nifb6mq6y1((&d_2));
        skip_0_nifb6mq6y1((&d_2));
        {
          while (NIM_TRUE){
            NifKind_0_nif81dubp1 X60Qx_590 = kind_0_nifb6mq6y1(d_2);
            if ((!(X60Qx_590 == 12))){
              compileExpr_1_comaa5xpt1(c_59, ctx_31, (&d_2));
              inc_1_I6wjjge_aow2h993l1((&elemCount_0));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      eQdestroy_0_nifb6mq6y1((&d_2));}
    NI32 X60Qx_591 = emit_0_comaa5xpt1(ctx_31, 46, 0, elemCount_0);
    eQdestroy_0_nifb6mq6y1((&dataCur_0));
    nimStrDestroy(tag_3);
    return;
    eQdestroy_0_nifb6mq6y1((&dataCur_0));}
  seq_0_In6doa_ast8ri79k fieldSyms_1 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  NI32 count_1 = 0;
  NB8 X60Qx_592;
  NB8 X60Qx_593 = eqQ_20_sysvq0asl(tag_3, (string_0_sysvq0asl){
    .bytes_0 = 1868787710u, .more_0 = (&strlit_0_I7084116572891045059_comaa5xpt1)}
  );
  if (X60Qx_593){
    X60Qx_592 = NIM_TRUE;}
  else {
    NB8 X60Qx_594 = eqQ_20_sysvq0asl(tag_3, (string_0_sysvq0asl){
      .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I12337342044224817361_comaa5xpt1)}
    );
    X60Qx_592 = X60Qx_594;}
  if (X60Qx_592){
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_595 = kind_0_nifb6mq6y1((*n_29));
        if ((!(X60Qx_595 == 12))){
          NB8 X60Qx_66;
          NifKind_0_nif81dubp1 X60Qx_596 = kind_0_nifb6mq6y1((*n_29));
          if (X60Qx_596 == 11){
            string_0_sysvq0asl X60Qtmp_41 = nodeTag_0_comaa5xpt1((*n_29));
            NB8 X60Qx_597 = eqQ_20_sysvq0asl(X60Qtmp_41, (string_0_sysvq0asl){
              .bytes_0 = 7760642u, .more_0 = NIM_NIL}
            );
            X60Qx_66 = X60Qx_597;
            nimStrDestroy(X60Qtmp_41);}
          else {
            X60Qx_66 = NIM_FALSE;}
          if (X60Qx_66){
            inc_0_nifb6mq6y1(n_29);
            NU32 fsym_2 = ((NU32)0u);
            NifKind_0_nif81dubp1 X60Qx_598 = kind_0_nifb6mq6y1((*n_29));
            if (X60Qx_598 == 4){
              NU32 X60Qx_599 = symId_0_nifb6mq6y1((*n_29));
              fsym_2 = X60Qx_599;}
            skip_0_nifb6mq6y1(n_29);
            compileExpr_1_comaa5xpt1(c_59, ctx_31, n_29);
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_600 = kind_0_nifb6mq6y1((*n_29));
                if ((!(X60Qx_600 == 12))){
                  skip_0_nifb6mq6y1(n_29);}
                else {
                  break;}}}
            whileStmtLabel_3: ;
            consumeParRi_0_nifb6mq6y1(n_29);
            add_0_I34il1q_comaa5xpt1((&fieldSyms_1), fsym_2);
            inc_1_I6wjjge_aow2h993l1((&count_1));}
          else {
            skip_0_nifb6mq6y1(n_29);}}
        else {
          break;}}}
    whileStmtLabel_2: ;
    consumeParRi_0_nifb6mq6y1(n_29);
    NB8 X60Qx_601;
    if (count_1 == 0){
      NB8 X60Qx_602 = eqQ_0_nifh7u8pu1(typeSym_5, ((NU32)0u));
      X60Qx_601 = (!X60Qx_602);}
    else {
      X60Qx_601 = NIM_FALSE;}
    if (X60Qx_601){
      collectObjectFields_1_comaa5xpt1(typeSym_5, (&fieldSyms_1));
      NI32 i_20 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_603 = len_3_I6y2imo_buiyylk1h1(fieldSyms_1);
          if (i_20 < X60Qx_603){
            NI32 X60Qx_604 = emit_0_comaa5xpt1(ctx_31, 1, 0, 0);
            inc_1_I6wjjge_aow2h993l1((&i_20));}
          else {
            break;}}}
      whileStmtLabel_4: ;
      NI32 X60Qx_605 = len_3_I6y2imo_buiyylk1h1(fieldSyms_1);
      count_1 = X60Qx_605;}
    NI32 oi_0 = addObjInfo_0_comaa5xpt1(c_59, typeSym_5, fieldSyms_1);
    NB8 X60Qx_606 = eqQ_20_sysvq0asl(tag_3, (string_0_sysvq0asl){
      .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I12337342044224817361_comaa5xpt1)}
    );
    if (X60Qx_606){
      NI32 X60Qx_607 = emit_0_comaa5xpt1(ctx_31, 38, oi_0, count_1);}
    else {
      NI32 X60Qx_608 = emit_0_comaa5xpt1(ctx_31, 37, oi_0, count_1);}}
  else {
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_609 = kind_0_nifb6mq6y1((*n_29));
        if ((!(X60Qx_609 == 12))){
          NB8 X60Qx_67;
          NifKind_0_nif81dubp1 X60Qx_610 = kind_0_nifb6mq6y1((*n_29));
          if (X60Qx_610 == 11){
            string_0_sysvq0asl X60Qtmp_42 = nodeTag_0_comaa5xpt1((*n_29));
            NB8 X60Qx_611 = eqQ_20_sysvq0asl(X60Qtmp_42, (string_0_sysvq0asl){
              .bytes_0 = 7760642u, .more_0 = NIM_NIL}
            );
            X60Qx_67 = X60Qx_611;
            nimStrDestroy(X60Qtmp_42);}
          else {
            X60Qx_67 = NIM_FALSE;}
          if (X60Qx_67){
            inc_0_nifb6mq6y1(n_29);
            NU32 fsym_3 = ((NU32)0u);
            NifKind_0_nif81dubp1 X60Qx_612 = kind_0_nifb6mq6y1((*n_29));
            if (X60Qx_612 == 4){
              NU32 X60Qx_613 = symId_0_nifb6mq6y1((*n_29));
              fsym_3 = X60Qx_613;}
            skip_0_nifb6mq6y1(n_29);
            compileExpr_1_comaa5xpt1(c_59, ctx_31, n_29);
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_614 = kind_0_nifb6mq6y1((*n_29));
                if ((!(X60Qx_614 == 12))){
                  skip_0_nifb6mq6y1(n_29);}
                else {
                  break;}}}
            whileStmtLabel_6: ;
            consumeParRi_0_nifb6mq6y1(n_29);
            add_0_I34il1q_comaa5xpt1((&fieldSyms_1), fsym_3);
            inc_1_I6wjjge_aow2h993l1((&count_1));}
          else {
            add_0_I34il1q_comaa5xpt1((&fieldSyms_1), ((NU32)0u));
            compileExpr_1_comaa5xpt1(c_59, ctx_31, n_29);
            inc_1_I6wjjge_aow2h993l1((&count_1));}}
        else {
          break;}}}
    whileStmtLabel_5: ;
    consumeParRi_0_nifb6mq6y1(n_29);
    NI32 oi_1 = addObjInfo_0_comaa5xpt1(c_59, typeSym_5, fieldSyms_1);
    NI32 X60Qx_615 = emit_0_comaa5xpt1(ctx_31, 40, oi_1, count_1);}
  eQdestroy_1_Iscb4i31_ast8ri79k(fieldSyms_1);
  nimStrDestroy(tag_3);}
void compileCall_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_60, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_32, Cursor_0_nifb6mq6y1* n_30, NB8 forceStatic_1){
  NI32 X60Qx_616 = lineOf_0_comaa5xpt1((*n_30));
  (*ctx_32).d_00.curLine_0 = X60Qx_616;
  inc_0_nifb6mq6y1(n_30);
  NU32 calleeSym_0 = ((NU32)0u);
  NB8 haveCallee_0 = NIM_FALSE;
  Cursor_0_nifb6mq6y1 calleeCur_0 = eQdup_0_nifb6mq6y1((*n_30));
  NifKind_0_nif81dubp1 X60Qx_617 = kind_0_nifb6mq6y1((*n_30));
  if (X60Qx_617 == 4){
    NU32 X60Qx_618 = symId_0_nifb6mq6y1((*n_30));
    calleeSym_0 = X60Qx_618;
    haveCallee_0 = NIM_TRUE;
    inc_0_nifb6mq6y1(n_30);}
  else {
    skip_0_nifb6mq6y1(n_30);}
  NI32 argc_0 = 0;
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_619 = kind_0_nifb6mq6y1((*n_30));
      if ((!(X60Qx_619 == 12))){
        NB8 handledAsLoc_0 = NIM_FALSE;
        NifKind_0_nif81dubp1 X60Qx_620 = kind_0_nifb6mq6y1((*n_30));
        if (X60Qx_620 == 11){
          string_0_sysvq0asl atag_0 = nodeTag_0_comaa5xpt1((*n_30));
          NB8 X60Qx_621;
          NB8 X60Qx_622;
          NB8 X60Qx_623 = eqQ_20_sysvq0asl(atag_0, (string_0_sysvq0asl){
            .bytes_0 = 1818321918u, .more_0 = (&strlit_0_I1707222714195181991_comaa5xpt1)}
          );
          if (X60Qx_623){
            X60Qx_622 = NIM_TRUE;}
          else {
            NB8 X60Qx_624 = eqQ_20_sysvq0asl(atag_0, (string_0_sysvq0asl){
              .bytes_0 = 1684890371u, .more_0 = NIM_NIL}
            );
            X60Qx_622 = X60Qx_624;}
          if (X60Qx_622){
            X60Qx_621 = NIM_TRUE;}
          else {
            NB8 X60Qx_625 = eqQ_20_sysvq0asl(atag_0, (string_0_sysvq0asl){
              .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_comaa5xpt1)}
            );
            X60Qx_621 = X60Qx_625;}
          if (X60Qx_621){
            Cursor_0_nifb6mq6y1 probe_0 = eQdup_0_nifb6mq6y1((*n_30));
            inc_0_nifb6mq6y1((&probe_0));
            NB8 X60Qx_68;
            NB8 X60Qx_69;
            NB8 X60Qx_70;
            NifKind_0_nif81dubp1 X60Qx_626 = kind_0_nifb6mq6y1(probe_0);
            if (X60Qx_626 == 4){
              NU32 X60Qx_627 = symId_0_nifb6mq6y1(probe_0);
              string_0_sysvq0asl X60Qtmp_43 = baseName_0_comaa5xpt1(X60Qx_627);
              NB8 X60Qx_628 = eqQ_20_sysvq0asl(X60Qtmp_43, (string_0_sysvq0asl){
                .bytes_0 = 6118146u, .more_0 = NIM_NIL}
              );
              X60Qx_70 = X60Qx_628;
              nimStrDestroy(X60Qtmp_43);}
            else {
              X60Qx_70 = NIM_FALSE;}
            if (X60Qx_70){
              NU32 X60Qx_629 = symId_0_nifb6mq6y1(probe_0);
              NB8 X60Qx_630 = returnsMutLocation_1_comaa5xpt1(X60Qx_629);
              X60Qx_69 = X60Qx_630;}
            else {
              X60Qx_69 = NIM_FALSE;}
            if (X60Qx_69){
              NU32 X60Qx_631 = symId_0_nifb6mq6y1(probe_0);
              NB8 X60Qx_632 = firstParamContainer_1_comaa5xpt1(X60Qx_631);
              X60Qx_68 = X60Qx_632;}
            else {
              X60Qx_68 = NIM_FALSE;}
            if (X60Qx_68){
              Cursor_0_nifb6mq6y1 m_3 = eQdup_0_nifb6mq6y1((*n_30));
              inc_0_nifb6mq6y1((&m_3));
              skip_0_nifb6mq6y1((&m_3));
              compileExpr_1_comaa5xpt1(c_60, ctx_32, (&m_3));
              compileExpr_1_comaa5xpt1(c_60, ctx_32, (&m_3));
              {
                while (NIM_TRUE){
                  NifKind_0_nif81dubp1 X60Qx_633 = kind_0_nifb6mq6y1(m_3);
                  if ((!(X60Qx_633 == 12))){
                    skip_0_nifb6mq6y1((&m_3));}
                  else {
                    break;}}}
              whileStmtLabel_1: ;
              consumeParRi_0_nifb6mq6y1((&m_3));
              eQdestroy_0_nifb6mq6y1((&(*n_30)));
              (*n_30) = m_3;
              eQwasMoved_0_nifb6mq6y1((&m_3));
              NI32 X60Qx_634 = emit_0_comaa5xpt1(ctx_32, 49, 0, 0);
              handledAsLoc_0 = NIM_TRUE;
              eQdestroy_0_nifb6mq6y1((&m_3));}
            eQdestroy_0_nifb6mq6y1((&probe_0));}
          nimStrDestroy(atag_0);}
        NB8 X60Qx_4;
        NB8 X60Qx_5;
        string_0_sysvq0asl bn_1;
        nimStrWasMoved((&bn_1));
        NB8 X60Qx_635;
        NB8 X60Qx_636;
        NB8 X60Qx_637;
        if ((!handledAsLoc_0)){
          X60Qx_637 = (argc_0 == 0);}
        else {
          X60Qx_637 = NIM_FALSE;}
        if (X60Qx_637){
          NifKind_0_nif81dubp1 X60Qx_638 = kind_0_nifb6mq6y1((*n_30));
          X60Qx_636 = (X60Qx_638 == 4);}
        else {
          X60Qx_636 = NIM_FALSE;}
        if (X60Qx_636){
          X60Qx_635 = haveCallee_0;}
        else {
          X60Qx_635 = NIM_FALSE;}
        if (X60Qx_635){
          nimStrDestroy(bn_1);
          string_0_sysvq0asl X60Qx_639 = baseName_0_comaa5xpt1(calleeSym_0);
          bn_1 = X60Qx_639;
          NB8 X60Qx_640;
          NB8 X60Qx_641 = eqQ_20_sysvq0asl(bn_1, (string_0_sysvq0asl){
            .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I7514604024534592575_comaa5xpt1)}
          );
          if (X60Qx_641){
            X60Qx_640 = NIM_TRUE;}
          else {
            NB8 X60Qx_642 = eqQ_20_sysvq0asl(bn_1, (string_0_sysvq0asl){
              .bytes_0 = 1634038526u, .more_0 = (&strlit_0_I7466143617196742693_comaa5xpt1)}
            );
            X60Qx_640 = X60Qx_642;}
          X60Qx_5 = X60Qx_640;}
        else {
          X60Qx_5 = NIM_FALSE;}
        if (X60Qx_5){
          NB8 X60Qx_643;
          NU32 X60Qx_644 = symId_0_nifb6mq6y1((*n_30));
          NI32 X60Qx_645 = get_0_comaa5xpt1((*ctx_32).d_00.smap_0, X60Qx_644);
          if (0 <= X60Qx_645){
            X60Qx_643 = NIM_TRUE;}
          else {
            NU32 X60Qx_646 = symId_0_nifb6mq6y1((*n_30));
            NI32 X60Qx_647 = get_0_comaa5xpt1((*c_60).d_00.gmap_0, X60Qx_646);
            X60Qx_643 = (0 <= X60Qx_647);}
          X60Qx_4 = X60Qx_643;}
        else {
          X60Qx_4 = NIM_FALSE;}
        if (X60Qx_4){
          compileAddr_1_comaa5xpt1(c_60, ctx_32, n_30);
          handledAsLoc_0 = NIM_TRUE;}
        if ((!handledAsLoc_0)){
          compileExpr_1_comaa5xpt1(c_60, ctx_32, n_30);}
        inc_1_I6wjjge_aow2h993l1((&argc_0));
        nimStrDestroy(bn_1);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_30);
  if ((!haveCallee_0)){
    Cursor_0_nifb6mq6y1 cc_7 = calleeCur_0;
    eQwasMoved_0_nifb6mq6y1((&calleeCur_0));
    compileExpr_1_comaa5xpt1(c_60, ctx_32, (&cc_7));
    NI32 X60Qx_648 = emit_0_comaa5xpt1(ctx_32, 27, 0, argc_0);
    eQdestroy_0_nifb6mq6y1((&cc_7));
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;
    eQdestroy_0_nifb6mq6y1((&cc_7));}
  NB8 X60Qx_649;
  NI32 X60Qx_650 = get_0_comaa5xpt1((*ctx_32).d_00.smap_0, calleeSym_0);
  if (0 <= X60Qx_650){
    X60Qx_649 = NIM_TRUE;}
  else {
    NI32 X60Qx_651 = get_0_comaa5xpt1((*c_60).d_00.gmap_0, calleeSym_0);
    X60Qx_649 = (0 <= X60Qx_651);}
  if (X60Qx_649){
    resolveSymbol_1_comaa5xpt1(c_60, ctx_32, calleeSym_0);
    NI32 X60Qx_652 = emit_0_comaa5xpt1(ctx_32, 27, 0, argc_0);
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;}
  NB8 X60Qx_653 = routineExistsVM_1_comaa5xpt1(c_60, calleeSym_0);
  if ((!X60Qx_653)){
    X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 ga_0 = importedGlobalAddr_0_comaa5xpt1(c_60, calleeSym_0);
    if (0 <= ga_0.fld_0){
      NI32 X60Qx_654 = emit_0_comaa5xpt1(ctx_32, 11, ga_0.fld_0, ga_0.fld_1);
      NI32 X60Qx_655 = emit_0_comaa5xpt1(ctx_32, 27, 0, argc_0);
      eQdestroy_0_nifb6mq6y1((&calleeCur_0));
      return;}}
  string_0_sysvq0asl base_1 = baseName_0_comaa5xpt1(calleeSym_0);
  NB8 X60Qx_656;
  NB8 X60Qx_657 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
    .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I11023901819970991276_comaa5xpt1)}
  );
  if (X60Qx_657){
    X60Qx_656 = (1 <= argc_0);}
  else {
    X60Qx_656 = NIM_FALSE;}
  if (X60Qx_656){
    X60Qt_0_IAtupleAiS32ZAiS32_comaa5xpt1 sg_0 = schedulerGlobalOf_0_comaa5xpt1(c_60, calleeSym_0);
    if (0 <= sg_0.fld_0){
      NI32 X60Qx_658 = emit_0_comaa5xpt1(ctx_32, 75, sg_0.fld_0, sg_0.fld_1);}
    else {
      NI32 X60Qx_659 = addNative_0_comaa5xpt1(c_60, (string_0_sysvq0asl){
        .bytes_0 = 1952805886u, .more_0 = (&strlit_0_I11023901819970991276_comaa5xpt1)}
      );
      NI32 X60Qx_660 = emit_0_comaa5xpt1(ctx_32, 34, X60Qx_659, argc_0);}
    nimStrDestroy(base_1);
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;}
  NB8 X60Qx_661;
  NB8 X60Qx_662 = symIsPassive_1_comaa5xpt1(c_60, calleeSym_0);
  if (X60Qx_662){
    NB8 X60Qx_663 = routineExistsVM_1_comaa5xpt1(c_60, calleeSym_0);
    X60Qx_661 = X60Qx_663;}
  else {
    X60Qx_661 = NIM_FALSE;}
  if (X60Qx_661){
    NB8 X60Qx_664;
    NB8 X60Qx_665;
    if ((!forceStatic_1)){
      X60Qx_665 = (1 <= argc_0);}
    else {
      X60Qx_665 = NIM_FALSE;}
    if (X60Qx_665){
      NB8 X60Qx_666 = isMethodSym_1_comaa5xpt1(c_60, calleeSym_0);
      X60Qx_664 = X60Qx_666;}
    else {
      X60Qx_664 = NIM_FALSE;}
    if (X60Qx_664){
      NI32 idx_2 = getProcIdx_1_comaa5xpt1(c_60, calleeSym_0);
      NI32 site_0 = len_3_In1ttqs_comaa5xpt1((*c_60).d_00.methodSites_0);
      add_0_Inwn80m1_comaa5xpt1((&(*c_60).d_00.methodSites_0), (MethodSite_0_chu5m1rja1){
        .staticFn_0 = calleeSym_0, .fallbackIdx_0 = idx_2}
      );
      if ((*ctx_32).d_00.isPassive_0){
        NI32 X60Qx_667 = emit_0_comaa5xpt1(ctx_32, 81, site_0, argc_0);}
      else {
        NI32 X60Qx_668 = emit_0_comaa5xpt1(ctx_32, 82, site_0, argc_0);}}
    else {
      NI32 pidx_0 = getProcIdx_1_comaa5xpt1(c_60, calleeSym_0);
      if ((*ctx_32).d_00.isPassive_0){
        NI32 X60Qx_669 = emit_0_comaa5xpt1(ctx_32, 79, pidx_0, argc_0);}
      else {
        NI32 X60Qx_670 = emit_0_comaa5xpt1(ctx_32, 80, pidx_0, argc_0);}}
    nimStrDestroy(base_1);
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;}
  {
    X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1 fl_0 = foreignLeafOf_1_comaa5xpt1(c_60, calleeSym_0);
    if (fl_0.fld_0){
      NI32 X60Qx_671 = addNative_0_comaa5xpt1(c_60, fl_0.fld_1);
      NI32 X60Qx_672 = emit_0_comaa5xpt1(ctx_32, 34, X60Qx_671, argc_0);
      eQdestroyQ_AtupleAboolZSstring0sysvq0asl_0_comaa5xpt1(fl_0);
      nimStrDestroy(base_1);
      eQdestroy_0_nifb6mq6y1((&calleeCur_0));
      return;}
    eQdestroyQ_AtupleAboolZSstring0sysvq0asl_0_comaa5xpt1(fl_0);}
  X60Qlab_2: ;
  NB8 X60Qx_673;
  NB8 X60Qx_674;
  NB8 X60Qx_675;
  NB8 X60Qx_676;
  NB8 X60Qx_677;
  NB8 X60Qx_678;
  NB8 X60Qx_679 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
    .bytes_0 = 1701068286u, .more_0 = (&strlit_0_I10157464168546919252_comaa5xpt1)}
  );
  if (X60Qx_679){
    X60Qx_678 = NIM_TRUE;}
  else {
    NB8 X60Qx_680 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1969503742u, .more_0 = (&strlit_0_I11614359337083319489_comaa5xpt1)}
    );
    X60Qx_678 = X60Qx_680;}
  if (X60Qx_678){
    X60Qx_677 = NIM_TRUE;}
  else {
    NB8 X60Qx_681 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1868774910u, .more_0 = (&strlit_0_I14683201540015467042_comaa5xpt1)}
    );
    X60Qx_677 = X60Qx_681;}
  if (X60Qx_677){
    X60Qx_676 = NIM_TRUE;}
  else {
    NB8 X60Qx_682 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1769160190u, .more_0 = (&strlit_0_I17069683611453604721_comaa5xpt1)}
    );
    X60Qx_676 = X60Qx_682;}
  if (X60Qx_676){
    X60Qx_675 = NIM_TRUE;}
  else {
    NB8 X60Qx_683 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1635204606u, .more_0 = (&strlit_0_I9151517089334711309_comaa5xpt1)}
    );
    X60Qx_675 = X60Qx_683;}
  if (X60Qx_675){
    X60Qx_674 = NIM_TRUE;}
  else {
    NB8 X60Qx_684 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1920220670u, .more_0 = (&strlit_0_I7262382801534885590_comaa5xpt1)}
    );
    X60Qx_674 = X60Qx_684;}
  if (X60Qx_674){
    NB8 X60Qx_685 = calleeIsProvider_0_comaa5xpt1(c_60, calleeSym_0);
    X60Qx_673 = X60Qx_685;}
  else {
    X60Qx_673 = NIM_FALSE;}
  if (X60Qx_673){
    NI32 X60Qx_686 = addNative_0_comaa5xpt1(c_60, base_1);
    NI32 X60Qx_687 = emit_0_comaa5xpt1(ctx_32, 34, X60Qx_686, argc_0);
    nimStrDestroy(base_1);
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;}
  NB8 X60Qx_688;
  NB8 X60Qx_689 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
    .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I5348593791521339691_comaa5xpt1)}
  );
  if (X60Qx_689){
    X60Qx_688 = NIM_TRUE;}
  else {
    NB8 X60Qx_690 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1819042302u, .more_0 = (&strlit_0_I13537887754319196487_comaa5xpt1)}
    );
    X60Qx_688 = X60Qx_690;}
  if (X60Qx_688){
    NI32 X60Qx_691 = addNative_0_comaa5xpt1(c_60, base_1);
    NI32 X60Qx_692 = emit_0_comaa5xpt1(ctx_32, 34, X60Qx_691, argc_0);
    nimStrDestroy(base_1);
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;}
  NB8 X60Qx_693;
  NB8 X60Qx_694;
  NB8 X60Qx_695 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
    .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I930249616028346462_comaa5xpt1)}
  );
  if (X60Qx_695){
    X60Qx_694 = NIM_TRUE;}
  else {
    NB8 X60Qx_696 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I4547290982746310667_comaa5xpt1)}
    );
    X60Qx_694 = X60Qx_696;}
  if (X60Qx_694){
    X60Qx_693 = NIM_TRUE;}
  else {
    NB8 X60Qx_697 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1668440574u, .more_0 = (&strlit_0_I2856626897374252538_comaa5xpt1)}
    );
    X60Qx_693 = X60Qx_697;}
  if (X60Qx_693){
    NI32 X60Qx_698 = addNative_0_comaa5xpt1(c_60, base_1);
    NI32 X60Qx_699 = emit_0_comaa5xpt1(ctx_32, 34, X60Qx_698, argc_0);
    nimStrDestroy(base_1);
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;}
  NB8 X60Qx_700;
  NB8 X60Qx_701;
  NB8 X60Qx_702;
  NB8 X60Qx_703 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
    .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I3225684998187034911_comaa5xpt1)}
  );
  if (X60Qx_703){
    X60Qx_702 = NIM_TRUE;}
  else {
    NB8 X60Qx_704 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 2003136254u, .more_0 = (&strlit_0_I11042971208590088895_comaa5xpt1)}
    );
    X60Qx_702 = X60Qx_704;}
  if (X60Qx_702){
    NB8 X60Qx_705 = calleeIsProvider_0_comaa5xpt1(c_60, calleeSym_0);
    X60Qx_701 = X60Qx_705;}
  else {
    X60Qx_701 = NIM_FALSE;}
  if (X60Qx_701){
    X60Qx_700 = (argc_0 == 1);}
  else {
    X60Qx_700 = NIM_FALSE;}
  if (X60Qx_700){
    NI32 X60Qx_706 = addNative_0_comaa5xpt1(c_60, base_1);
    NI32 X60Qx_707 = emit_0_comaa5xpt1(ctx_32, 34, X60Qx_706, argc_0);
    NI32 dc_0 = newSeqElemDefaultConst_0_comaa5xpt1(c_60, calleeSym_0);
    if (0 <= dc_0){
      NI32 X60Qx_708 = emit_0_comaa5xpt1(ctx_32, 47, dc_0, 0);}
    nimStrDestroy(base_1);
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;}
  NB8 X60Qx_709;
  NB8 X60Qx_710;
  NB8 X60Qx_711;
  NB8 X60Qx_712;
  NB8 X60Qx_713;
  NB8 X60Qx_714;
  NB8 X60Qx_715;
  NB8 X60Qx_716;
  NB8 X60Qx_717 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
    .bytes_0 = 1768843774u, .more_0 = (&strlit_0_I15541155848264557133_comaa5xpt1)}
  );
  if (X60Qx_717){
    X60Qx_716 = NIM_TRUE;}
  else {
    NB8 X60Qx_718 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1936614910u, .more_0 = (&strlit_0_I3798637678053249641_comaa5xpt1)}
    );
    X60Qx_716 = X60Qx_718;}
  if (X60Qx_716){
    X60Qx_715 = NIM_TRUE;}
  else {
    NB8 X60Qx_719 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1651864574u, .more_0 = (&strlit_0_I16581638230773281198_comaa5xpt1)}
    );
    X60Qx_715 = X60Qx_719;}
  if (X60Qx_715){
    X60Qx_714 = NIM_TRUE;}
  else {
    NB8 X60Qx_720 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I1232877487365112244_comaa5xpt1)}
    );
    X60Qx_714 = X60Qx_720;}
  if (X60Qx_714){
    X60Qx_713 = NIM_TRUE;}
  else {
    NB8 X60Qx_721 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1969779710u, .more_0 = (&strlit_0_I8602794362013704992_comaa5xpt1)}
    );
    X60Qx_713 = X60Qx_721;}
  if (X60Qx_713){
    X60Qx_712 = NIM_TRUE;}
  else {
    NB8 X60Qx_722 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1869574398u, .more_0 = (&strlit_0_I11010039520288330211_comaa5xpt1)}
    );
    X60Qx_712 = X60Qx_722;}
  if (X60Qx_712){
    X60Qx_711 = NIM_TRUE;}
  else {
    NB8 X60Qx_723 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1869574398u, .more_0 = (&strlit_0_I10257712218960831919_comaa5xpt1)}
    );
    X60Qx_711 = X60Qx_723;}
  if (X60Qx_711){
    X60Qx_710 = NIM_TRUE;}
  else {
    NB8 X60Qx_724 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I12770529794932993973_comaa5xpt1)}
    );
    X60Qx_710 = X60Qx_724;}
  if (X60Qx_710){
    NB8 X60Qx_725 = calleeIsProvider_0_comaa5xpt1(c_60, calleeSym_0);
    X60Qx_709 = X60Qx_725;}
  else {
    X60Qx_709 = NIM_FALSE;}
  if (X60Qx_709){
    NI32 X60Qx_726 = addNative_0_comaa5xpt1(c_60, base_1);
    NI32 X60Qx_727 = emit_0_comaa5xpt1(ctx_32, 34, X60Qx_726, argc_0);
    nimStrDestroy(base_1);
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;}
  NB8 X60Qx_728;
  NB8 X60Qx_729 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
    .bytes_0 = 1836016638u, .more_0 = (&strlit_0_I13045133590002807130_comaa5xpt1)}
  );
  if (X60Qx_729){
    NB8 X60Qx_730 = calleeIsProvider_0_comaa5xpt1(c_60, calleeSym_0);
    X60Qx_728 = X60Qx_730;}
  else {
    X60Qx_728 = NIM_FALSE;}
  if (X60Qx_728){
    NB8 X60Qx_731 = routineExistsVM_1_comaa5xpt1(c_60, calleeSym_0);
    if (X60Qx_731){
      NI32 X60Qx_732 = addNative_0_comaa5xpt1(c_60, base_1);
      NI32 X60Qx_733 = getProcIdx_1_comaa5xpt1(c_60, calleeSym_0);
      NI32 g_1 = addGatedCall_0_comaa5xpt1(c_60, X60Qx_732, X60Qx_733, NIM_FALSE);
      NI32 X60Qx_734 = emit_0_comaa5xpt1(ctx_32, 35, g_1, argc_0);}
    else {
      NI32 X60Qx_735 = addNative_0_comaa5xpt1(c_60, base_1);
      NI32 X60Qx_736 = emit_0_comaa5xpt1(ctx_32, 34, X60Qx_735, argc_0);}
    nimStrDestroy(base_1);
    eQdestroy_0_nifb6mq6y1((&calleeCur_0));
    return;}
  NB8 X60Qx_737;
  NB8 X60Qx_738 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
    .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I9592449470941440445_comaa5xpt1)}
  );
  if (X60Qx_738){
    NB8 X60Qx_739 = routineExistsVM_1_comaa5xpt1(c_60, calleeSym_0);
    X60Qx_737 = X60Qx_739;}
  else {
    X60Qx_737 = NIM_FALSE;}
  NB8 preferOwnBody_0 = X60Qx_737;
  NB8 X60Qx_740;
  NB8 X60Qx_741;
  if ((!preferOwnBody_0)){
    NB8 X60Qx_742 = isNativeVM_0_comaa5xpt1(base_1);
    X60Qx_741 = X60Qx_742;}
  else {
    X60Qx_741 = NIM_FALSE;}
  if (X60Qx_741){
    NB8 X60Qx_743 = nativeProvidesVM_0_comaa5xpt1(c_60, calleeSym_0);
    X60Qx_740 = X60Qx_743;}
  else {
    X60Qx_740 = NIM_FALSE;}
  if (X60Qx_740){
    NB8 X60Qx_744;
    NB8 X60Qx_745;
    NB8 X60Qx_746 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
      .bytes_0 = 9217u, .more_0 = NIM_NIL}
    );
    if (X60Qx_746){
      X60Qx_745 = (1 <= argc_0);}
    else {
      X60Qx_745 = NIM_FALSE;}
    if (X60Qx_745){
      NB8 X60Qx_747 = routineExistsVM_1_comaa5xpt1(c_60, calleeSym_0);
      X60Qx_744 = X60Qx_747;}
    else {
      X60Qx_744 = NIM_FALSE;}
    if (X60Qx_744){
      string_0_sysvq0asl X60Qtmp_44 = trueModule_0_comaa5xpt1(calleeSym_0);
      NB8 X60Qx_748 = eqQ_20_sysvq0asl(X60Qtmp_44, (string_0_sysvq0asl){
        .bytes_0 = 1937339390u, .more_0 = (&strlit_0_I12313941242067973473_buiyylk1h1)}
      );
      NB8 dollarScalar_1 = (!X60Qx_748);
      NI32 X60Qx_749 = addNative_0_comaa5xpt1(c_60, base_1);
      NI32 X60Qx_750 = getProcIdx_1_comaa5xpt1(c_60, calleeSym_0);
      NI32 g_2 = addGatedCall_0_comaa5xpt1(c_60, X60Qx_749, X60Qx_750, dollarScalar_1);
      NI32 X60Qx_751 = emit_0_comaa5xpt1(ctx_32, 35, g_2, argc_0);
      nimStrDestroy(X60Qtmp_44);}
    else {
      NB8 X60Qx_752;
      NB8 X60Qx_753;
      NB8 X60Qx_754;
      NB8 X60Qx_755 = isGatedNative_0_runot4689(base_1);
      if (X60Qx_755){
        X60Qx_754 = (1 <= argc_0);}
      else {
        X60Qx_754 = NIM_FALSE;}
      if (X60Qx_754){
        NB8 X60Qx_756 = routineExistsVM_1_comaa5xpt1(c_60, calleeSym_0);
        X60Qx_753 = X60Qx_756;}
      else {
        X60Qx_753 = NIM_FALSE;}
      if (X60Qx_753){
        NB8 X60Qx_757;
        NB8 X60Qx_758 = eqQ_20_sysvq0asl(base_1, (string_0_sysvq0asl){
          .bytes_0 = 1935763710u, .more_0 = (&strlit_0_I17711552707752383867_comaa5xpt1)}
        );
        if (X60Qx_758){
          X60Qx_757 = NIM_TRUE;}
        else {
          NB8 X60Qx_759 = firstParamContainer_1_comaa5xpt1(calleeSym_0);
          X60Qx_757 = (!X60Qx_759);}
        X60Qx_752 = X60Qx_757;}
      else {
        X60Qx_752 = NIM_FALSE;}
      if (X60Qx_752){
        NI32 X60Qx_760 = addNative_0_comaa5xpt1(c_60, base_1);
        NI32 X60Qx_761 = getProcIdx_1_comaa5xpt1(c_60, calleeSym_0);
        NI32 g_3 = addGatedCall_0_comaa5xpt1(c_60, X60Qx_760, X60Qx_761, NIM_FALSE);
        NI32 X60Qx_762 = emit_0_comaa5xpt1(ctx_32, 35, g_3, argc_0);}
      else {
        NB8 X60Qx_763;
        NB8 X60Qx_764;
        NB8 X60Qx_765 = isStreamGatableIO_0_runot4689(base_1);
        if (X60Qx_765){
          X60Qx_764 = (1 <= argc_0);}
        else {
          X60Qx_764 = NIM_FALSE;}
        if (X60Qx_764){
          NB8 X60Qx_766 = routineExistsVM_1_comaa5xpt1(c_60, calleeSym_0);
          X60Qx_763 = X60Qx_766;}
        else {
          X60Qx_763 = NIM_FALSE;}
        if (X60Qx_763){
          NI32 X60Qx_767 = addNative_0_comaa5xpt1(c_60, base_1);
          NI32 X60Qx_768 = getProcIdx_1_comaa5xpt1(c_60, calleeSym_0);
          NI32 g_4 = addGatedCall_0_comaa5xpt1(c_60, X60Qx_767, X60Qx_768, NIM_FALSE);
          NI32 X60Qx_769 = emit_0_comaa5xpt1(ctx_32, 35, g_4, argc_0);}
        else {
          NI32 X60Qx_770 = addNative_0_comaa5xpt1(c_60, base_1);
          NI32 X60Qx_771 = emit_0_comaa5xpt1(ctx_32, 34, X60Qx_770, argc_0);}}}}
  else {
    NB8 X60Qx_772;
    NB8 X60Qx_773;
    if ((!forceStatic_1)){
      X60Qx_773 = (1 <= argc_0);}
    else {
      X60Qx_773 = NIM_FALSE;}
    if (X60Qx_773){
      NB8 X60Qx_774 = isMethodSym_1_comaa5xpt1(c_60, calleeSym_0);
      X60Qx_772 = X60Qx_774;}
    else {
      X60Qx_772 = NIM_FALSE;}
    if (X60Qx_772){
      NI32 idx_3 = getProcIdx_1_comaa5xpt1(c_60, calleeSym_0);
      NI32 site_1 = len_3_In1ttqs_comaa5xpt1((*c_60).d_00.methodSites_0);
      add_0_Inwn80m1_comaa5xpt1((&(*c_60).d_00.methodSites_0), (MethodSite_0_chu5m1rja1){
        .staticFn_0 = calleeSym_0, .fallbackIdx_0 = idx_3}
      );
      NI32 X60Qx_775 = emit_0_comaa5xpt1(ctx_32, 28, site_1, argc_0);}
    else {
      NI32 X60Qx_776 = get_0_comaa5xpt1((*c_60).d_00.nestedSyms_0, calleeSym_0);
      if (0 <= X60Qx_776){
        NI32 idx_4 = getProcIdx_1_comaa5xpt1(c_60, calleeSym_0);
        NI32 X60Qx_777 = emit_0_comaa5xpt1(ctx_32, 29, idx_4, argc_0);}
      else {
        NI32 idx_5 = getProcIdx_1_comaa5xpt1(c_60, calleeSym_0);
        NI32 X60Qx_778 = emit_0_comaa5xpt1(ctx_32, 26, idx_5, argc_0);}}}
  nimStrDestroy(base_1);
  eQdestroy_0_nifb6mq6y1((&calleeCur_0));}
X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1 scalarElemInfo_0_comaa5xpt1(Cursor_0_nifb6mq6y1 typeCur_0, NI32 depth_0){
  X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1 result_37;
  if (32 < depth_0){
    result_37 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1){
      .fld_0 = 0, .fld_1 = 0, .fld_2 = NIM_FALSE}
    ;
    return result_37;}
  Cursor_0_nifb6mq6y1 c_106 = eQdup_0_nifb6mq6y1(typeCur_0);
  NifKind_0_nif81dubp1 X60Qx_779 = kind_0_nifb6mq6y1(c_106);
  if (X60Qx_779 == 4){
    NU32 X60Qx_780 = symId_0_nifb6mq6y1(c_106);
    LoadResult_0_prorcx25w1 res_5 = tryLoadSymSafe_0_modzy18mg1(X60Qx_780);
    NB8 X60Qx_71;
    NB8 X60Qx_781;
    if ((!(res_5.status_0 == 3))){
      X60Qx_781 = NIM_TRUE;}
    else {
      NifKind_0_nif81dubp1 X60Qx_782 = kind_0_nifb6mq6y1(res_5.decl_0);
      X60Qx_781 = (!(X60Qx_782 == 11));}
    if (X60Qx_781){
      X60Qx_71 = NIM_TRUE;}
    else {
      string_0_sysvq0asl X60Qtmp_45 = nodeTag_0_comaa5xpt1(res_5.decl_0);
      NB8 X60Qx_783 = eqQ_20_sysvq0asl(X60Qtmp_45, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
      );
      X60Qx_71 = (!X60Qx_783);
      nimStrDestroy(X60Qtmp_45);}
    if (X60Qx_71){
      result_37 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1){
        .fld_0 = 0, .fld_1 = 0, .fld_2 = NIM_FALSE}
      ;
      eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_5);
      eQdestroy_0_nifb6mq6y1((&c_106));
      return result_37;}
    Cursor_0_nifb6mq6y1 d_3 = res_5.decl_0;
    eQwasMoved_0_nifb6mq6y1((&res_5.decl_0));
    inc_0_nifb6mq6y1((&d_3));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_784 = kind_0_nifb6mq6y1(d_3);
        if ((!(X60Qx_784 == 12))){
          NB8 X60Qx_72;
          NifKind_0_nif81dubp1 X60Qx_785 = kind_0_nifb6mq6y1(d_3);
          if (X60Qx_785 == 11){
            string_0_sysvq0asl X60Qtmp_46 = nodeTag_0_comaa5xpt1(d_3);
            NB8 X60Qx_786 = eqQ_20_sysvq0asl(X60Qtmp_46, (string_0_sysvq0asl){
              .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_comaa5xpt1)}
            );
            X60Qx_72 = (!X60Qx_786);
            nimStrDestroy(X60Qtmp_46);}
          else {
            X60Qx_72 = NIM_FALSE;}
          if (X60Qx_72){
            X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1 X60Qx_787 = scalarElemInfo_0_comaa5xpt1(d_3, ((NI32)(depth_0 + 1)));
            result_37 = X60Qx_787;
            eQdestroy_0_nifb6mq6y1((&d_3));
            eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_5);
            eQdestroy_0_nifb6mq6y1((&c_106));
            return result_37;}
          skip_0_nifb6mq6y1((&d_3));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    result_37 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1){
      .fld_0 = 0, .fld_1 = 0, .fld_2 = NIM_FALSE}
    ;
    eQdestroy_0_nifb6mq6y1((&d_3));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_5);
    eQdestroy_0_nifb6mq6y1((&c_106));
    return result_37;
    eQdestroy_0_nifb6mq6y1((&d_3));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_5);}
  NifKind_0_nif81dubp1 X60Qx_788 = kind_0_nifb6mq6y1(c_106);
  if ((!(X60Qx_788 == 11))){
    result_37 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1){
      .fld_0 = 0, .fld_1 = 0, .fld_2 = NIM_FALSE}
    ;
    eQdestroy_0_nifb6mq6y1((&c_106));
    return result_37;}
  string_0_sysvq0asl tg_1 = nodeTag_0_comaa5xpt1(c_106);
  NB8 X60Qtc_94 = nimStrAtLe_0_sysvq0asl(tg_1, 0, (NC8)'e');
  if (X60Qtc_94){
    NB8 X60Qtc_95 = nimStrAtLe_0_sysvq0asl(tg_1, 0, (NC8)'c');
    if (X60Qtc_95){
      if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
        .bytes_0 = 25345u, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_91;}
      else if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
        .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_buiyylk1h1)}
      )){
        goto X60Qsc_92;}}
    else {
      if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
        .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_comaa5xpt1)}
      )){
        goto X60Qsc_89;}
      else if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
        .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_comaa5xpt1)}
      )){
        goto X60Qsc_93;}}}
  else {
    NB8 X60Qtc_96 = nimStrAtLe_0_sysvq0asl(tg_1, 0, (NC8)'i');
    if (X60Qtc_96){
      if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
        .bytes_0 = 26881u, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_90;}
      else if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
        .bytes_0 = 26113u, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_90;}}
    else {
      if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
        .bytes_0 = 29953u, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_90;}
      else if (equalStrings_0_sysvq0asl(tg_1, (string_0_sysvq0asl){
        .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_comaa5xpt1)}
      )){
        goto X60Qsc_93;}}}
  goto X60Qsc_98;
  X60Qsc_89: ;
  inc_0_nifb6mq6y1((&c_106));
  X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1 X60Qx_789 = scalarElemInfo_0_comaa5xpt1(c_106, ((NI32)(depth_0 + 1)));
  result_37 = X60Qx_789;
  nimStrDestroy(tg_1);
  eQdestroy_0_nifb6mq6y1((&c_106));
  return result_37;
  goto X60Qsc_97;
  X60Qsc_90: ;
  TCode_0_valzr1t4f X60Qx_6;
  NB8 X60Qx_790 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
    .bytes_0 = 29953u, .more_0 = NIM_NIL}
  );
  if (X60Qx_790){
    X60Qx_6 = 0;}
  else {
    NB8 X60Qx_791 = eqQ_20_sysvq0asl(tg_1, (string_0_sysvq0asl){
      .bytes_0 = 26881u, .more_0 = NIM_NIL}
    );
    if (X60Qx_791){
      X60Qx_6 = 1;}
    else {
      X60Qx_6 = 2;}}
  TCode_0_valzr1t4f code_1 = X60Qx_6;
  inc_0_nifb6mq6y1((&c_106));
  NI32 bits_6 = 0;
  NifKind_0_nif81dubp1 X60Qx_792 = kind_0_nifb6mq6y1(c_106);
  if (X60Qx_792 == 8){
    NU32 X60Qx_793 = intId_0_nifb6mq6y1(c_106);
    NI64* X60Qx_794 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_793);
    bits_6 = ((NI32)(*X60Qx_794));}
  if (bits_6 < 0){
    bits_6 = ((NI32)(sizeof(NI32) * 8));}
  if (bits_6 <= 0){
    result_37 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1){
      .fld_0 = 0, .fld_1 = 0, .fld_2 = NIM_FALSE}
    ;
    nimStrDestroy(tg_1);
    eQdestroy_0_nifb6mq6y1((&c_106));
    return result_37;}
  result_37 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1){
    .fld_0 = bits_6, .fld_1 = code_1, .fld_2 = NIM_TRUE}
  ;
  nimStrDestroy(tg_1);
  eQdestroy_0_nifb6mq6y1((&c_106));
  return result_37;
  goto X60Qsc_97;
  X60Qsc_91: ;
  result_37 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1){
    .fld_0 = 8, .fld_1 = 5, .fld_2 = NIM_TRUE}
  ;
  nimStrDestroy(tg_1);
  eQdestroy_0_nifb6mq6y1((&c_106));
  return result_37;
  goto X60Qsc_97;
  X60Qsc_92: ;
  result_37 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1){
    .fld_0 = 8, .fld_1 = 4, .fld_2 = NIM_TRUE}
  ;
  nimStrDestroy(tg_1);
  eQdestroy_0_nifb6mq6y1((&c_106));
  return result_37;
  goto X60Qsc_97;
  X60Qsc_93: ;
  inc_0_nifb6mq6y1((&c_106));
  X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1 X60Qx_795 = scalarElemInfo_0_comaa5xpt1(c_106, ((NI32)(depth_0 + 1)));
  result_37 = X60Qx_795;
  nimStrDestroy(tg_1);
  eQdestroy_0_nifb6mq6y1((&c_106));
  return result_37;
  goto X60Qsc_97;
  X60Qsc_98: ;
  result_37 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1){
    .fld_0 = 0, .fld_1 = 0, .fld_2 = NIM_FALSE}
  ;
  nimStrDestroy(tg_1);
  eQdestroy_0_nifb6mq6y1((&c_106));
  return result_37;
  X60Qsc_97: ;
  nimStrDestroy(tg_1);
  eQdestroy_0_nifb6mq6y1((&c_106));
  return result_37;
  nimStrDestroy(tg_1);
  eQdestroy_0_nifb6mq6y1((&c_106));
  return result_37;}
X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAboolZSX53ymX49d0nifh7u8pu1_comaa5xpt1 parsePtrElem_0_comaa5xpt1(Cursor_0_nifb6mq6y1 typeCur_1){
  X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAboolZSX53ymX49d0nifh7u8pu1_comaa5xpt1 result_38;
  Cursor_0_nifb6mq6y1 c_107 = eQdup_0_nifb6mq6y1(typeCur_1);
  NB8 X60Qx_73;
  NifKind_0_nif81dubp1 X60Qx_796 = kind_0_nifb6mq6y1(c_107);
  if ((!(X60Qx_796 == 11))){
    X60Qx_73 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_47 = nodeTag_0_comaa5xpt1(c_107);
    NB8 X60Qx_797 = eqQ_20_sysvq0asl(X60Qtmp_47, (string_0_sysvq0asl){
      .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
    );
    X60Qx_73 = (!X60Qx_797);
    nimStrDestroy(X60Qtmp_47);}
  if (X60Qx_73){
    result_38 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAboolZSX53ymX49d0nifh7u8pu1_comaa5xpt1){
      .fld_0 = 0, .fld_1 = 0, .fld_2 = NIM_FALSE, .fld_3 = ((NU32)0u)}
    ;
    eQdestroy_0_nifb6mq6y1((&c_107));
    return result_38;}
  inc_0_nifb6mq6y1((&c_107));
  NB8 X60Qx_74;
  NifKind_0_nif81dubp1 X60Qx_798 = kind_0_nifb6mq6y1(c_107);
  if (X60Qx_798 == 11){
    string_0_sysvq0asl X60Qtmp_48 = nodeTag_0_comaa5xpt1(c_107);
    NB8 X60Qx_799 = eqQ_20_sysvq0asl(X60Qtmp_48, (string_0_sysvq0asl){
      .bytes_0 = 1918989822u, .more_0 = (&strlit_0_I2984705338531181753_buiyylk1h1)}
    );
    X60Qx_74 = X60Qx_799;
    nimStrDestroy(X60Qtmp_48);}
  else {
    X60Qx_74 = NIM_FALSE;}
  if (X60Qx_74){
    inc_0_nifb6mq6y1((&c_107));}
  X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAbool_comaa5xpt1 X60Qtmptup_0 = scalarElemInfo_0_comaa5xpt1(c_107, 0);
  NI32 bits_7 = X60Qtmptup_0.fld_0;
  TCode_0_valzr1t4f code_2 = X60Qtmptup_0.fld_1;
  NB8 ok_0 = X60Qtmptup_0.fld_2;
  if (ok_0){
    result_38 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAboolZSX53ymX49d0nifh7u8pu1_comaa5xpt1){
      .fld_0 = bits_7, .fld_1 = code_2, .fld_2 = NIM_TRUE, .fld_3 = ((NU32)0u)}
    ;
    eQdestroy_0_nifb6mq6y1((&c_107));
    return result_38;}
  NifKind_0_nif81dubp1 X60Qx_800 = kind_0_nifb6mq6y1(c_107);
  if (X60Qx_800 == 4){
    NU32 X60Qx_801 = symId_0_nifb6mq6y1(c_107);
    NI32 sz_1 = sizeOfSym_0_fiepkwzpc(X60Qx_801);
    NB8 X60Qx_802;
    if (0 < sz_1){
      NU32 X60Qx_803 = symId_0_nifb6mq6y1(c_107);
      NB8 X60Qx_804 = isFlatPodType_0_fiepkwzpc(X60Qx_803);
      X60Qx_802 = X60Qx_804;}
    else {
      X60Qx_802 = NIM_FALSE;}
    if (X60Qx_802){
      NU32 X60Qx_805 = symId_0_nifb6mq6y1(c_107);
      result_38 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAboolZSX53ymX49d0nifh7u8pu1_comaa5xpt1){
        .fld_0 = ((NI32)(sz_1 * 8)), .fld_1 = 7, .fld_2 = NIM_TRUE, .fld_3 = X60Qx_805}
      ;
      eQdestroy_0_nifb6mq6y1((&c_107));
      return result_38;}}
  result_38 = (X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAboolZSX53ymX49d0nifh7u8pu1_comaa5xpt1){
    .fld_0 = 0, .fld_1 = 0, .fld_2 = NIM_FALSE, .fld_3 = ((NU32)0u)}
  ;
  eQdestroy_0_nifb6mq6y1((&c_107));
  return result_38;
  eQdestroy_0_nifb6mq6y1((&c_107));
  return result_38;}
void compileConv_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_61, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_33, Cursor_0_nifb6mq6y1* n_31){
  string_0_sysvq0asl X60Qtmp_49 = nodeTag_0_comaa5xpt1((*n_31));
  NB8 isCast_0 = eqQ_20_sysvq0asl(X60Qtmp_49, (string_0_sysvq0asl){
    .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I13909093427330098489_comaa5xpt1)}
  );
  inc_0_nifb6mq6y1(n_31);
  string_0_sysvq0asl t_12 = (string_0_sysvq0asl){
    .bytes_0 = 0u, .more_0 = NIM_NIL}
  ;
  NifKind_0_nif81dubp1 X60Qx_806 = kind_0_nifb6mq6y1((*n_31));
  if (X60Qx_806 == 11){
    nimStrDestroy(t_12);
    string_0_sysvq0asl X60Qx_807 = nodeTag_0_comaa5xpt1((*n_31));
    t_12 = X60Qx_807;}
  NB8 X60Qx_808;
  NB8 X60Qx_809;
  NB8 X60Qx_810;
  NB8 X60Qx_811 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
    .bytes_0 = 26881u, .more_0 = NIM_NIL}
  );
  if (X60Qx_811){
    X60Qx_810 = NIM_TRUE;}
  else {
    NB8 X60Qx_812 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
      .bytes_0 = 29953u, .more_0 = NIM_NIL}
    );
    X60Qx_810 = X60Qx_812;}
  if (X60Qx_810){
    X60Qx_809 = NIM_TRUE;}
  else {
    NB8 X60Qx_813 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
      .bytes_0 = 26113u, .more_0 = NIM_NIL}
    );
    X60Qx_809 = X60Qx_813;}
  if (X60Qx_809){
    X60Qx_808 = NIM_TRUE;}
  else {
    NB8 X60Qx_814 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
      .bytes_0 = 25345u, .more_0 = NIM_NIL}
    );
    X60Qx_808 = X60Qx_814;}
  NB8 wasNum_0 = X60Qx_808;
  NI32 tbits_0 = 64;
  NB8 tsigned_0 = NIM_TRUE;
  NI32 ptrBits_0 = 0;
  TCode_0_valzr1t4f ptrCode_0 = 0;
  NU32 ptrEtype_0 = ((NU32)0u);
  NB8 isPtrCast_0 = NIM_FALSE;
  if (wasNum_0){
    readOptType_0_comaa5xpt1(n_31, (&tbits_0), (&tsigned_0));}
  else {
    NB8 X60Qx_815;
    if (isCast_0){
      NB8 X60Qx_816 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
        .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
      );
      X60Qx_815 = X60Qx_816;}
    else {
      X60Qx_815 = NIM_FALSE;}
    if (X60Qx_815){
      X60Qt_0_IAtupleAiS32ZSX54X43ode0valzr1t4fAboolZSX53ymX49d0nifh7u8pu1_comaa5xpt1 X60Qtmptup_1 = parsePtrElem_0_comaa5xpt1((*n_31));
      NI32 pb_0 = X60Qtmptup_1.fld_0;
      TCode_0_valzr1t4f pc_0 = X60Qtmptup_1.fld_1;
      NB8 ok_1 = X60Qtmptup_1.fld_2;
      NU32 pt_0 = X60Qtmptup_1.fld_3;
      if (ok_1){
        ptrBits_0 = pb_0;
        ptrCode_0 = pc_0;
        isPtrCast_0 = NIM_TRUE;
        ptrEtype_0 = pt_0;}}
    skip_0_nifb6mq6y1(n_31);}
  compileExpr_1_comaa5xpt1(c_61, ctx_33, n_31);
  consumeParRi_0_nifb6mq6y1(n_31);
  if (wasNum_0){
    NI32 mode_3 = 3;
    if (isCast_0){
      NB8 X60Qx_817 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
        .bytes_0 = 26113u, .more_0 = NIM_NIL}
      );
      if (X60Qx_817){
        mode_3 = 4;}
      else {
        NB8 X60Qx_818;
        NB8 X60Qx_819 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
          .bytes_0 = 26881u, .more_0 = NIM_NIL}
        );
        if (X60Qx_819){
          X60Qx_818 = NIM_TRUE;}
        else {
          NB8 X60Qx_820 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
            .bytes_0 = 29953u, .more_0 = NIM_NIL}
          );
          X60Qx_818 = X60Qx_820;}
        if (X60Qx_818){
          mode_3 = 5;}
        else {
          NB8 X60Qx_821 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
            .bytes_0 = 25345u, .more_0 = NIM_NIL}
          );
          if (X60Qx_821){
            mode_3 = 2;}}}}
    else {
      NB8 X60Qx_822 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
        .bytes_0 = 26113u, .more_0 = NIM_NIL}
      );
      if (X60Qx_822){
        mode_3 = 1;}
      else {
        NB8 X60Qx_823 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
          .bytes_0 = 25345u, .more_0 = NIM_NIL}
        );
        if (X60Qx_823){
          mode_3 = 2;}}}
    NI32 X60Qx_824 = addConv_0_comaa5xpt1(c_61, mode_3, tbits_0, tsigned_0);
    NI32 X60Qx_825 = emit_0_comaa5xpt1(ctx_33, 21, X60Qx_824, 0);}
  else {
    if (isPtrCast_0){
      NI32 X60Qx_826 = addPtrConv_0_comaa5xpt1(c_61, ptrBits_0, ptrCode_0, ptrEtype_0);
      NI32 X60Qx_827 = emit_0_comaa5xpt1(ctx_33, 21, X60Qx_826, 0);}
    else {
      NB8 X60Qx_828;
      if (isCast_0){
        NB8 X60Qx_829 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
          .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I6300154543333844069_comaa5xpt1)}
        );
        X60Qx_828 = X60Qx_829;}
      else {
        X60Qx_828 = NIM_FALSE;}
      if (X60Qx_828){
        NI32 X60Qx_830 = addPtrConv_0_comaa5xpt1(c_61, -2, 3, ((NU32)0u));
        NI32 X60Qx_831 = emit_0_comaa5xpt1(ctx_33, 21, X60Qx_830, 0);}
      else {
        NB8 X60Qx_832;
        if (isCast_0){
          NB8 X60Qx_833 = eqQ_20_sysvq0asl(t_12, (string_0_sysvq0asl){
            .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
          );
          X60Qx_832 = X60Qx_833;}
        else {
          X60Qx_832 = NIM_FALSE;}
        if (X60Qx_832){
          NI32 X60Qx_834 = addPtrConv_0_comaa5xpt1(c_61, -1, 0, ((NU32)0u));
          NI32 X60Qx_835 = emit_0_comaa5xpt1(ctx_33, 21, X60Qx_834, 0);}}}}
  nimStrDestroy(t_12);
  nimStrDestroy(X60Qtmp_49);}
void compileSuf_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_62, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_34, Cursor_0_nifb6mq6y1* n_32){
  inc_0_nifb6mq6y1(n_32);
  compileExpr_1_comaa5xpt1(c_62, ctx_34, n_32);
  NI32 w_0 = 0;
  NB8 isFloat_0 = NIM_FALSE;
  NB8 isUnsigned_0 = NIM_FALSE;
  NifKind_0_nif81dubp1 X60Qx_836 = kind_0_nifb6mq6y1((*n_32));
  if (X60Qx_836 == 6){
    NU32 X60Qx_837 = litId_0_nifb6mq6y1((*n_32));
    string_0_sysvq0asl* X60Qx_838 = getQ_0_Iplpzal1_ast8ri79k(pool_0_nifh7u8pu1.strings_0, X60Qx_837);
    string_0_sysvq0asl suf_0 = nimStrDup((*X60Qx_838));
    skip_0_nifb6mq6y1(n_32);
    NI32 i_21 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_839 = len_4_sysvq0asl(suf_0);
        if (i_21 < X60Qx_839){
          NC8 ch_0 = getQ_9_sysvq0asl(suf_0, i_21);
          if (ch_0 == (NC8)'f'){
            isFloat_0 = NIM_TRUE;}
          else {
            if (ch_0 == (NC8)'u'){
              isUnsigned_0 = NIM_TRUE;}
            else {
              NB8 X60Qx_840;
              if ((NC8)'0' <= ch_0){
                X60Qx_840 = (ch_0 <= (NC8)'9');}
              else {
                X60Qx_840 = NIM_FALSE;}
              if (X60Qx_840){
                w_0 = ((NI32)(((NI32)(w_0 * 10)) + ((NI32)(((NI32)ch_0) - ((NI32)(NC8)'0')))));}}}
          inc_1_I6wjjge_aow2h993l1((&i_21));}
        else {
          break;}}}
    whileStmtLabel_0: ;
    nimStrDestroy(suf_0);}
  else {
    NifKind_0_nif81dubp1 X60Qx_841 = kind_0_nifb6mq6y1((*n_32));
    if ((!(X60Qx_841 == 12))){
      skip_0_nifb6mq6y1(n_32);}}
  consumeParRi_0_nifb6mq6y1(n_32);
  NB8 X60Qx_842;
  NB8 X60Qx_843;
  NB8 X60Qx_844;
  if (w_0 == 8){
    X60Qx_844 = NIM_TRUE;}
  else {
    X60Qx_844 = (w_0 == 16);}
  if (X60Qx_844){
    X60Qx_843 = NIM_TRUE;}
  else {
    X60Qx_843 = (w_0 == 32);}
  if (X60Qx_843){
    X60Qx_842 = NIM_TRUE;}
  else {
    X60Qx_842 = (w_0 == 64);}
  if (X60Qx_842){
    NI32 X60Qx_845 = emit_0_comaa5xpt1(ctx_34, 22, w_0, 0);}}
void compileArrayConstr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_63, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_35, Cursor_0_nifb6mq6y1* n_33){
  inc_0_nifb6mq6y1(n_33);
  NI32 arrLo_0 = 0;
  NifKind_0_nif81dubp1 X60Qx_846 = kind_0_nifb6mq6y1((*n_33));
  if (X60Qx_846 == 4){
    skip_0_nifb6mq6y1(n_33);}
  else {
    NifKind_0_nif81dubp1 X60Qx_847 = kind_0_nifb6mq6y1((*n_33));
    if (X60Qx_847 == 11){
      string_0_sysvq0asl X60Qtmp_50 = nodeTag_0_comaa5xpt1((*n_33));
      NB8 X60Qx_848 = eqQ_20_sysvq0asl(X60Qtmp_50, (string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_comaa5xpt1)}
      );
      if (X60Qx_848){
        NI32 X60Qx_849 = arrayLowFromType_0_runot4689((*n_33));
        arrLo_0 = X60Qx_849;}
      skip_0_nifb6mq6y1(n_33);
      nimStrDestroy(X60Qtmp_50);}}
  NI32 count_2 = 0;
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_850 = kind_0_nifb6mq6y1((*n_33));
      if ((!(X60Qx_850 == 12))){
        compileExpr_1_comaa5xpt1(c_63, ctx_35, n_33);
        inc_1_I6wjjge_aow2h993l1((&count_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_33);
  NI32 X60Qx_851 = emit_0_comaa5xpt1(ctx_35, 45, arrLo_0, count_2);}
void compileIndexGet_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_64, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_36, Cursor_0_nifb6mq6y1* n_34){
  string_0_sysvq0asl idxTag_0 = nodeTag_0_comaa5xpt1((*n_34));
  NI64 X60Qx_7;
  NB8 X60Qx_852;
  NB8 X60Qx_853 = eqQ_20_sysvq0asl(idxTag_0, (string_0_sysvq0asl){
    .bytes_0 = 7627010u, .more_0 = NIM_NIL}
  );
  if (X60Qx_853){
    X60Qx_852 = NIM_TRUE;}
  else {
    NB8 X60Qx_854 = eqQ_20_sysvq0asl(idxTag_0, (string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I3001676635385606767_comaa5xpt1)}
    );
    X60Qx_852 = X60Qx_854;}
  if (X60Qx_852){
    X60Qx_7 = 1;}
  else {
    X60Qx_7 = 0;}
  NI32 checked_0 = X60Qx_7;
  inc_0_nifb6mq6y1(n_34);
  compileExpr_1_comaa5xpt1(c_64, ctx_36, n_34);
  compileExpr_1_comaa5xpt1(c_64, ctx_36, n_34);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_855 = kind_0_nifb6mq6y1((*n_34));
      if ((!(X60Qx_855 == 12))){
        skip_0_nifb6mq6y1(n_34);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_34);
  NI32 X60Qx_856 = emit_0_comaa5xpt1(ctx_36, 48, checked_0, 0);
  nimStrDestroy(idxTag_0);}
void compileSetConstr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_65, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_37, Cursor_0_nifb6mq6y1* n_35){
  inc_0_nifb6mq6y1(n_35);
  NifKind_0_nif81dubp1 X60Qx_857 = kind_0_nifb6mq6y1((*n_35));
  if (X60Qx_857 == 11){
    skip_0_nifb6mq6y1(n_35);}
  else {
    NifKind_0_nif81dubp1 X60Qx_858 = kind_0_nifb6mq6y1((*n_35));
    if ((!(X60Qx_858 == 12))){
      skip_0_nifb6mq6y1(n_35);}}
  NI32 X60Qx_859 = emit_0_comaa5xpt1(ctx_37, 52, 0, 0);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_860 = kind_0_nifb6mq6y1((*n_35));
      if ((!(X60Qx_860 == 12))){
        NB8 X60Qx_75;
        NifKind_0_nif81dubp1 X60Qx_861 = kind_0_nifb6mq6y1((*n_35));
        if (X60Qx_861 == 11){
          string_0_sysvq0asl X60Qtmp_51 = nodeTag_0_comaa5xpt1((*n_35));
          NB8 X60Qx_862 = eqQ_20_sysvq0asl(X60Qtmp_51, (string_0_sysvq0asl){
            .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16597999082088934835_comaa5xpt1)}
          );
          X60Qx_75 = X60Qx_862;
          nimStrDestroy(X60Qtmp_51);}
        else {
          X60Qx_75 = NIM_FALSE;}
        if (X60Qx_75){
          inc_0_nifb6mq6y1(n_35);
          compileExpr_1_comaa5xpt1(c_65, ctx_37, n_35);
          compileExpr_1_comaa5xpt1(c_65, ctx_37, n_35);
          consumeParRi_0_nifb6mq6y1(n_35);
          NI32 X60Qx_863 = emit_0_comaa5xpt1(ctx_37, 54, 0, 0);}
        else {
          compileExpr_1_comaa5xpt1(c_65, ctx_37, n_35);
          NI32 X60Qx_864 = emit_0_comaa5xpt1(ctx_37, 53, 0, 0);}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_35);}
void compileIncl_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_66, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_38, Cursor_0_nifb6mq6y1* n_36, NB8 isIncl_1){
  inc_0_nifb6mq6y1(n_36);
  NifKind_0_nif81dubp1 X60Qx_865 = kind_0_nifb6mq6y1((*n_36));
  if (X60Qx_865 == 11){
    skip_0_nifb6mq6y1(n_36);}
  compileAddr_1_comaa5xpt1(c_66, ctx_38, n_36);
  compileExpr_1_comaa5xpt1(c_66, ctx_38, n_36);
  consumeParRi_0_nifb6mq6y1(n_36);
  if (isIncl_1){
    NI32 X60Qx_866 = emit_0_comaa5xpt1(ctx_38, 55, 0, 0);}
  else {
    NI32 X60Qx_867 = emit_0_comaa5xpt1(ctx_38, 56, 0, 0);}}
void compileInstanceOf_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_68, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_40, Cursor_0_nifb6mq6y1* n_38){
  inc_0_nifb6mq6y1(n_38);
  compileExpr_1_comaa5xpt1(c_68, ctx_40, n_38);
  NU32 tsym_0 = ((NU32)0u);
  NifKind_0_nif81dubp1 X60Qx_873 = kind_0_nifb6mq6y1((*n_38));
  if (X60Qx_873 == 4){
    NU32 X60Qx_874 = symId_0_nifb6mq6y1((*n_38));
    tsym_0 = X60Qx_874;}
  else {
    NifKind_0_nif81dubp1 X60Qx_875 = kind_0_nifb6mq6y1((*n_38));
    if (X60Qx_875 == 11){
      string_0_sysvq0asl X60Qtmp_52 = nodeTag_0_comaa5xpt1((*n_38));
      NB8 X60Qx_876 = eqQ_20_sysvq0asl(X60Qtmp_52, (string_0_sysvq0asl){
        .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
      );
      if (X60Qx_876){
        Cursor_0_nifb6mq6y1 cc_8 = eQdup_0_nifb6mq6y1((*n_38));
        inc_0_nifb6mq6y1((&cc_8));
        NifKind_0_nif81dubp1 X60Qx_877 = kind_0_nifb6mq6y1(cc_8);
        if (X60Qx_877 == 4){
          NU32 X60Qx_878 = symId_0_nifb6mq6y1(cc_8);
          tsym_0 = X60Qx_878;}
        eQdestroy_0_nifb6mq6y1((&cc_8));}
      nimStrDestroy(X60Qtmp_52);}}
  skip_0_nifb6mq6y1(n_38);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_879 = kind_0_nifb6mq6y1((*n_38));
      if ((!(X60Qx_879 == 12))){
        skip_0_nifb6mq6y1(n_38);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_38);
  NI32 X60Qx_880 = addTypeSym_0_comaa5xpt1(c_68, tsym_0);
  NI32 X60Qx_881 = emit_0_comaa5xpt1(ctx_40, 63, X60Qx_880, 0);}
void emitOneMatch_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_69, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_41, Cursor_0_nifb6mq6y1* cc_0, NI32 selSlot_0){
  NB8 X60Qx_76;
  NifKind_0_nif81dubp1 X60Qx_882 = kind_0_nifb6mq6y1((*cc_0));
  if (X60Qx_882 == 11){
    string_0_sysvq0asl X60Qtmp_53 = nodeTag_0_comaa5xpt1((*cc_0));
    NB8 X60Qx_883 = eqQ_20_sysvq0asl(X60Qtmp_53, (string_0_sysvq0asl){
      .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16597999082088934835_comaa5xpt1)}
    );
    X60Qx_76 = X60Qx_883;
    nimStrDestroy(X60Qtmp_53);}
  else {
    X60Qx_76 = NIM_FALSE;}
  if (X60Qx_76){
    Cursor_0_nifb6mq6y1 rc_0 = eQdup_0_nifb6mq6y1((*cc_0));
    inc_0_nifb6mq6y1((&rc_0));
    compileExpr_1_comaa5xpt1(c_69, ctx_41, (&rc_0));
    NI32 X60Qx_884 = emit_0_comaa5xpt1(ctx_41, 5, selSlot_0, 0);
    NI32 X60Qx_885 = addMagic_0_comaa5xpt1(c_69, 46, 64, NIM_TRUE, NIM_FALSE);
    NI32 X60Qx_886 = emit_0_comaa5xpt1(ctx_41, 19, X60Qx_885, 0);
    NI32 X60Qx_887 = emit_0_comaa5xpt1(ctx_41, 5, selSlot_0, 0);
    compileExpr_1_comaa5xpt1(c_69, ctx_41, (&rc_0));
    NI32 X60Qx_888 = addMagic_0_comaa5xpt1(c_69, 46, 64, NIM_TRUE, NIM_FALSE);
    NI32 X60Qx_889 = emit_0_comaa5xpt1(ctx_41, 19, X60Qx_888, 0);
    NI32 X60Qx_890 = addMagic_0_comaa5xpt1(c_69, 17, 64, NIM_TRUE, NIM_FALSE);
    NI32 X60Qx_891 = emit_0_comaa5xpt1(ctx_41, 19, X60Qx_890, 0);
    skip_0_nifb6mq6y1(cc_0);
    eQdestroy_0_nifb6mq6y1((&rc_0));}
  else {
    NI32 X60Qx_892 = emit_0_comaa5xpt1(ctx_41, 5, selSlot_0, 0);
    compileExpr_1_comaa5xpt1(c_69, ctx_41, cc_0);
    NI32 X60Qx_893 = addMagic_0_comaa5xpt1(c_69, 44, 64, NIM_TRUE, NIM_TRUE);
    NI32 X60Qx_894 = emit_0_comaa5xpt1(ctx_41, 19, X60Qx_893, 0);}}
void compileCaseCond_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_70, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_42, Cursor_0_nifb6mq6y1 rangesCur_0, NI32 selSlot_1){
  Cursor_0_nifb6mq6y1 cc_9 = eQdup_0_nifb6mq6y1(rangesCur_0);
  NB8 first_0 = NIM_TRUE;
  NifKind_0_nif81dubp1 X60Qx_895 = kind_0_nifb6mq6y1(cc_9);
  if (X60Qx_895 == 11){
    inc_0_nifb6mq6y1((&cc_9));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_896 = kind_0_nifb6mq6y1(cc_9);
        if ((!(X60Qx_896 == 12))){
          emitOneMatch_0_comaa5xpt1(c_70, ctx_42, (&cc_9), selSlot_1);
          if ((!first_0)){
            NI32 X60Qx_897 = addMagic_0_comaa5xpt1(c_70, 18, 64, NIM_TRUE, NIM_FALSE);
            NI32 X60Qx_898 = emit_0_comaa5xpt1(ctx_42, 19, X60Qx_897, 0);}
          first_0 = NIM_FALSE;}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  if (first_0){
    Value_0_valzr1t4f X60Qtmp_54 = vBool_0_valzr1t4f(NIM_FALSE);
    NI32 X60Qx_899 = addConst_0_comaa5xpt1(c_70, (&X60Qtmp_54));
    NI32 X60Qx_900 = emit_0_comaa5xpt1(ctx_42, 0, X60Qx_899, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_54));}
  eQdestroy_0_nifb6mq6y1((&cc_9));}
void compileCaseExpr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_71, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_43, Cursor_0_nifb6mq6y1* n_39){
  inc_0_nifb6mq6y1(n_39);
  NI32 selSlot_2 = (*ctx_43).d_00.numLocals_0;
  inc_1_I6wjjge_aow2h993l1((&(*ctx_43).d_00.numLocals_0));
  compileExpr_1_comaa5xpt1(c_71, ctx_43, n_39);
  NI32 X60Qx_901 = emit_0_comaa5xpt1(ctx_43, 6, selSlot_2, 0);
  seq_0_Ift2sne_chu5m1rja1 endPatches_0 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  NB8 hasElse_0 = NIM_FALSE;
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_902 = kind_0_nifb6mq6y1((*n_39));
      if ((!(X60Qx_902 == 12))){
        string_0_sysvq0asl btag_0 = nodeTag_0_comaa5xpt1((*n_39));
        NB8 X60Qx_903 = eqQ_20_sysvq0asl(btag_0, (string_0_sysvq0asl){
          .bytes_0 = 6713090u, .more_0 = NIM_NIL}
        );
        if (X60Qx_903){
          inc_0_nifb6mq6y1(n_39);
          Cursor_0_nifb6mq6y1 rangesCur_1 = eQdup_0_nifb6mq6y1((*n_39));
          skip_0_nifb6mq6y1(n_39);
          compileCaseCond_0_comaa5xpt1(c_71, ctx_43, rangesCur_1, selSlot_2);
          NI32 jf_2 = emit_0_comaa5xpt1(ctx_43, 25, 0, 0);
          compileExpr_1_comaa5xpt1(c_71, ctx_43, n_39);
          NI32 X60Qx_904 = emit_0_comaa5xpt1(ctx_43, 24, 0, 0);
          add_0_I8kd4i4_comaa5xpt1((&endPatches_0), X60Qx_904);
          NI32 X60Qx_905 = len_3_Icgec691_comaa5xpt1((*ctx_43).d_00.code_0);
          patch_0_comaa5xpt1(ctx_43, jf_2, X60Qx_905);
          consumeParRi_0_nifb6mq6y1(n_39);
          eQdestroy_0_nifb6mq6y1((&rangesCur_1));}
        else {
          NB8 X60Qx_906 = eqQ_20_sysvq0asl(btag_0, (string_0_sysvq0asl){
            .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_comaa5xpt1)}
          );
          if (X60Qx_906){
            inc_0_nifb6mq6y1(n_39);
            compileExpr_1_comaa5xpt1(c_71, ctx_43, n_39);
            hasElse_0 = NIM_TRUE;
            consumeParRi_0_nifb6mq6y1(n_39);}
          else {
            skip_0_nifb6mq6y1(n_39);}}
        nimStrDestroy(btag_0);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_39);
  if ((!hasElse_0)){
    NI32 X60Qx_907 = emit_0_comaa5xpt1(ctx_43, 1, 0, 0);}
  {
    openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_4 = toOpenArray_1_Ibqb4ob_comaa5xpt1(endPatches_0);
    NI32 X60Qlf_5 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_908 = len_6_I9632ti1_comaa5xpt1(X60Qlf_4);
        if (X60Qlf_5 < X60Qx_908){
          {
            NI32* X60Qii_3 = getQ_10_I053icq_comaa5xpt1(X60Qlf_4, X60Qlf_5);
            NI32 X60Qx_909 = len_3_Icgec691_comaa5xpt1((*ctx_43).d_00.code_0);
            patch_0_comaa5xpt1(ctx_43, (*X60Qii_3), X60Qx_909);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_5));}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  forStmtLabel_1: ;
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(endPatches_0);}
void compileIfExpr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_72, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_44, Cursor_0_nifb6mq6y1* n_40){
  inc_0_nifb6mq6y1(n_40);
  seq_0_Ift2sne_chu5m1rja1 endPatches_1 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  NB8 hasElse_1 = NIM_FALSE;
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_910 = kind_0_nifb6mq6y1((*n_40));
      if ((!(X60Qx_910 == 12))){
        string_0_sysvq0asl btag_1 = nodeTag_0_comaa5xpt1((*n_40));
        NB8 X60Qx_911 = eqQ_20_sysvq0asl(btag_1, (string_0_sysvq0asl){
          .bytes_0 = 1768711678u, .more_0 = (&strlit_0_I13424873862977158440_comaa5xpt1)}
        );
        if (X60Qx_911){
          inc_0_nifb6mq6y1(n_40);
          compileExpr_1_comaa5xpt1(c_72, ctx_44, n_40);
          NI32 jf_3 = emit_0_comaa5xpt1(ctx_44, 25, 0, 0);
          compileExpr_1_comaa5xpt1(c_72, ctx_44, n_40);
          NI32 X60Qx_912 = emit_0_comaa5xpt1(ctx_44, 24, 0, 0);
          add_0_I8kd4i4_comaa5xpt1((&endPatches_1), X60Qx_912);
          NI32 X60Qx_913 = len_3_Icgec691_comaa5xpt1((*ctx_44).d_00.code_0);
          patch_0_comaa5xpt1(ctx_44, jf_3, X60Qx_913);
          consumeParRi_0_nifb6mq6y1(n_40);}
        else {
          NB8 X60Qx_914 = eqQ_20_sysvq0asl(btag_1, (string_0_sysvq0asl){
            .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_comaa5xpt1)}
          );
          if (X60Qx_914){
            inc_0_nifb6mq6y1(n_40);
            compileExpr_1_comaa5xpt1(c_72, ctx_44, n_40);
            hasElse_1 = NIM_TRUE;
            consumeParRi_0_nifb6mq6y1(n_40);}
          else {
            skip_0_nifb6mq6y1(n_40);}}
        nimStrDestroy(btag_1);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_40);
  if ((!hasElse_1)){
    NI32 X60Qx_915 = emit_0_comaa5xpt1(ctx_44, 1, 0, 0);}
  {
    openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_6 = toOpenArray_1_Ibqb4ob_comaa5xpt1(endPatches_1);
    NI32 X60Qlf_7 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_916 = len_6_I9632ti1_comaa5xpt1(X60Qlf_6);
        if (X60Qlf_7 < X60Qx_916){
          {
            NI32* X60Qii_3 = getQ_10_I053icq_comaa5xpt1(X60Qlf_6, X60Qlf_7);
            NI32 X60Qx_917 = len_3_Icgec691_comaa5xpt1((*ctx_44).d_00.code_0);
            patch_0_comaa5xpt1(ctx_44, (*X60Qii_3), X60Qx_917);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_7));}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  forStmtLabel_1: ;
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(endPatches_1);}
X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1 objectBodyOf_0_comaa5xpt1(NU32 typeSym_2){
  X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1 result_39;
  eQwasmovedQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1((&result_39));
  eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(result_39);
  result_39 = (X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1){
    .fld_0 = NIM_FALSE, .fld_1 = (Cursor_0_nifb6mq6y1){
      .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}}
  ;
  LoadResult_0_prorcx25w1 res_6 = tryLoadSymSafe_0_modzy18mg1(typeSym_2);
  NB8 X60Qx_77;
  NB8 X60Qx_918;
  if ((!(res_6.status_0 == 3))){
    X60Qx_918 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_919 = kind_0_nifb6mq6y1(res_6.decl_0);
    X60Qx_918 = (!(X60Qx_919 == 11));}
  if (X60Qx_918){
    X60Qx_77 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_55 = nodeTag_0_comaa5xpt1(res_6.decl_0);
    NB8 X60Qx_920 = eqQ_20_sysvq0asl(X60Qtmp_55, (string_0_sysvq0asl){
      .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
    );
    X60Qx_77 = (!X60Qx_920);
    nimStrDestroy(X60Qtmp_55);}
  if (X60Qx_77){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
    return result_39;}
  Cursor_0_nifb6mq6y1 t_13 = res_6.decl_0;
  eQwasMoved_0_nifb6mq6y1((&res_6.decl_0));
  inc_0_nifb6mq6y1((&t_13));
  skip_0_nifb6mq6y1((&t_13));
  skip_0_nifb6mq6y1((&t_13));
  skip_0_nifb6mq6y1((&t_13));
  skip_0_nifb6mq6y1((&t_13));
  NB8 X60Qx_78;
  NifKind_0_nif81dubp1 X60Qx_921 = kind_0_nifb6mq6y1(t_13);
  if (X60Qx_921 == 11){
    string_0_sysvq0asl X60Qtmp_56 = nodeTag_0_comaa5xpt1(t_13);
    NB8 X60Qx_922 = eqQ_20_sysvq0asl(X60Qtmp_56, (string_0_sysvq0asl){
      .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
    );
    X60Qx_78 = X60Qx_922;
    nimStrDestroy(X60Qtmp_56);}
  else {
    X60Qx_78 = NIM_FALSE;}
  if (X60Qx_78){
    eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(result_39);
    Cursor_0_nifb6mq6y1 X60Qtmp_57 = t_13;
    eQwasMoved_0_nifb6mq6y1((&t_13));
    result_39 = (X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1){
      .fld_0 = NIM_TRUE, .fld_1 = X60Qtmp_57}
    ;}
  eQdestroy_0_nifb6mq6y1((&t_13));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
  return result_39;
  eQdestroy_0_nifb6mq6y1((&t_13));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_6);
  return result_39;}
void collectObjectFields_1_comaa5xpt1(NU32 typeSym_3, seq_0_In6doa_ast8ri79k* fields_1){
  X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1 ob_0 = objectBodyOf_0_comaa5xpt1(typeSym_3);
  if ((!ob_0.fld_0)){
    eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(ob_0);
    return;}
  Cursor_0_nifb6mq6y1 o_0 = ob_0.fld_1;
  eQwasMoved_0_nifb6mq6y1((&ob_0.fld_1));
  inc_0_nifb6mq6y1((&o_0));
  NifKind_0_nif81dubp1 X60Qx_923 = kind_0_nifb6mq6y1(o_0);
  if (X60Qx_923 == 4){
    NU32 base_2 = symId_0_nifb6mq6y1(o_0);
    NB8 X60Qx_924 = eqQ_0_nifh7u8pu1(base_2, typeSym_3);
    if ((!X60Qx_924)){
      collectObjectFields_1_comaa5xpt1(base_2, fields_1);}}
  skip_0_nifb6mq6y1((&o_0));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_925 = kind_0_nifb6mq6y1(o_0);
      if ((!(X60Qx_925 == 12))){
        NB8 X60Qx_79;
        NifKind_0_nif81dubp1 X60Qx_926 = kind_0_nifb6mq6y1(o_0);
        if (X60Qx_926 == 11){
          string_0_sysvq0asl X60Qtmp_58 = nodeTag_0_comaa5xpt1(o_0);
          NB8 X60Qx_927 = eqQ_20_sysvq0asl(X60Qtmp_58, (string_0_sysvq0asl){
            .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
          );
          X60Qx_79 = X60Qx_927;
          nimStrDestroy(X60Qtmp_58);}
        else {
          X60Qx_79 = NIM_FALSE;}
        if (X60Qx_79){
          Cursor_0_nifb6mq6y1 f_0 = eQdup_0_nifb6mq6y1(o_0);
          inc_0_nifb6mq6y1((&f_0));
          NifKind_0_nif81dubp1 X60Qx_928 = kind_0_nifb6mq6y1(f_0);
          if (X60Qx_928 == 5){
            NU32 X60Qx_929 = symId_0_nifb6mq6y1(f_0);
            add_0_I34il1q_comaa5xpt1(fields_1, X60Qx_929);}
          eQdestroy_0_nifb6mq6y1((&f_0));}
        skip_0_nifb6mq6y1((&o_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&o_0));
  eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(ob_0);}
NB8 isDefaultInitObject_0_comaa5xpt1(Cursor_0_nifb6mq6y1 typ_1){
  NB8 result_40;
  NB8 X60Qx_80;
  NB8 X60Qx_930;
  NifKind_0_nif81dubp1 X60Qx_931 = kind_0_nifb6mq6y1(typ_1);
  if (X60Qx_931 == 4){
    NI32 X60Qx_932 = typeDefaultKind_0_runot4689(typ_1);
    X60Qx_930 = (X60Qx_932 == 0);}
  else {
    X60Qx_930 = NIM_FALSE;}
  if (X60Qx_930){
    NU32 X60Qx_933 = symId_0_nifb6mq6y1(typ_1);
    X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1 X60Qtmp_59 = objectBodyOf_0_comaa5xpt1(X60Qx_933);
    X60Qx_80 = X60Qtmp_59.fld_0;
    eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qtmp_59);}
  else {
    X60Qx_80 = NIM_FALSE;}
  result_40 = X60Qx_80;
  return result_40;}
NB8 isDefaultInitAggregate_0_comaa5xpt1(Cursor_0_nifb6mq6y1 typ_2){
  NB8 result_41;
  NifKind_0_nif81dubp1 X60Qx_934 = kind_0_nifb6mq6y1(typ_2);
  if (X60Qx_934 == 11){
    string_0_sysvq0asl tg_2 = nodeTag_0_comaa5xpt1(typ_2);
    NB8 X60Qx_935;
    NB8 X60Qx_936 = eqQ_20_sysvq0asl(tg_2, (string_0_sysvq0asl){
      .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_comaa5xpt1)}
    );
    if (X60Qx_936){
      X60Qx_935 = NIM_TRUE;}
    else {
      NB8 X60Qx_937 = eqQ_20_sysvq0asl(tg_2, (string_0_sysvq0asl){
        .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
      );
      X60Qx_935 = X60Qx_937;}
    result_41 = X60Qx_935;
    nimStrDestroy(tg_2);
    return result_41;
    nimStrDestroy(tg_2);}
  NB8 X60Qx_938;
  NifKind_0_nif81dubp1 X60Qx_939 = kind_0_nifb6mq6y1(typ_2);
  if (X60Qx_939 == 4){
    NI32 X60Qx_940 = typeDefaultKind_0_runot4689(typ_2);
    X60Qx_938 = (X60Qx_940 == 0);}
  else {
    X60Qx_938 = NIM_FALSE;}
  if (X60Qx_938){
    NU32 X60Qx_941 = symId_0_nifb6mq6y1(typ_2);
    LoadResult_0_prorcx25w1 res_7 = tryLoadSymSafe_0_modzy18mg1(X60Qx_941);
    NB8 X60Qx_81;
    NB8 X60Qx_942;
    if (res_7.status_0 == 3){
      NifKind_0_nif81dubp1 X60Qx_943 = kind_0_nifb6mq6y1(res_7.decl_0);
      X60Qx_942 = (X60Qx_943 == 11);}
    else {
      X60Qx_942 = NIM_FALSE;}
    if (X60Qx_942){
      string_0_sysvq0asl X60Qtmp_60 = nodeTag_0_comaa5xpt1(res_7.decl_0);
      NB8 X60Qx_944 = eqQ_20_sysvq0asl(X60Qtmp_60, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
      );
      X60Qx_81 = X60Qx_944;
      nimStrDestroy(X60Qtmp_60);}
    else {
      X60Qx_81 = NIM_FALSE;}
    if (X60Qx_81){
      Cursor_0_nifb6mq6y1 d_4 = res_7.decl_0;
      eQwasMoved_0_nifb6mq6y1((&res_7.decl_0));
      inc_0_nifb6mq6y1((&d_4));
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_945 = kind_0_nifb6mq6y1(d_4);
          if ((!(X60Qx_945 == 12))){
            NifKind_0_nif81dubp1 X60Qx_946 = kind_0_nifb6mq6y1(d_4);
            if (X60Qx_946 == 11){
              string_0_sysvq0asl tg_3 = nodeTag_0_comaa5xpt1(d_4);
              NB8 X60Qx_947;
              NB8 X60Qx_948 = eqQ_20_sysvq0asl(tg_3, (string_0_sysvq0asl){
                .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_comaa5xpt1)}
              );
              if (X60Qx_948){
                X60Qx_947 = NIM_TRUE;}
              else {
                NB8 X60Qx_949 = eqQ_20_sysvq0asl(tg_3, (string_0_sysvq0asl){
                  .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
                );
                X60Qx_947 = X60Qx_949;}
              if (X60Qx_947){
                nimStrDestroy(tg_3);
                eQdestroy_0_nifb6mq6y1((&d_4));
                eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
                return NIM_TRUE;}
              NB8 X60Qx_950;
              NB8 X60Qx_951;
              NB8 X60Qx_952;
              NB8 X60Qx_953 = eqQ_20_sysvq0asl(tg_3, (string_0_sysvq0asl){
                .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
              );
              if (X60Qx_953){
                X60Qx_952 = NIM_TRUE;}
              else {
                NB8 X60Qx_954 = eqQ_20_sysvq0asl(tg_3, (string_0_sysvq0asl){
                  .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_comaa5xpt1)}
                );
                X60Qx_952 = X60Qx_954;}
              if (X60Qx_952){
                X60Qx_951 = NIM_TRUE;}
              else {
                NB8 X60Qx_955 = eqQ_20_sysvq0asl(tg_3, (string_0_sysvq0asl){
                  .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_comaa5xpt1)}
                );
                X60Qx_951 = X60Qx_955;}
              if (X60Qx_951){
                X60Qx_950 = NIM_TRUE;}
              else {
                NB8 X60Qx_956 = eqQ_20_sysvq0asl(tg_3, (string_0_sysvq0asl){
                  .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_comaa5xpt1)}
                );
                X60Qx_950 = X60Qx_956;}
              if (X60Qx_950){
                nimStrDestroy(tg_3);
                eQdestroy_0_nifb6mq6y1((&d_4));
                eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);
                return NIM_FALSE;}
              nimStrDestroy(tg_3);}
            skip_0_nifb6mq6y1((&d_4));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      eQdestroy_0_nifb6mq6y1((&d_4));}
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_7);}
  return NIM_FALSE;
  return result_41;}
void collectObjectFieldsTyped_0_comaa5xpt1(NU32 typeSym_4, seq_0_In6doa_ast8ri79k* fields_2, seq_0_Isyzizu1_comaa5xpt1* ftypes_0){
  X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1 ob_1 = objectBodyOf_0_comaa5xpt1(typeSym_4);
  if ((!ob_1.fld_0)){
    eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(ob_1);
    return;}
  Cursor_0_nifb6mq6y1 o_1 = ob_1.fld_1;
  eQwasMoved_0_nifb6mq6y1((&ob_1.fld_1));
  inc_0_nifb6mq6y1((&o_1));
  NifKind_0_nif81dubp1 X60Qx_957 = kind_0_nifb6mq6y1(o_1);
  if (X60Qx_957 == 4){
    NU32 base_3 = symId_0_nifb6mq6y1(o_1);
    NB8 X60Qx_958 = eqQ_0_nifh7u8pu1(base_3, typeSym_4);
    if ((!X60Qx_958)){
      collectObjectFieldsTyped_0_comaa5xpt1(base_3, fields_2, ftypes_0);}}
  skip_0_nifb6mq6y1((&o_1));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_959 = kind_0_nifb6mq6y1(o_1);
      if ((!(X60Qx_959 == 12))){
        NB8 X60Qx_82;
        NifKind_0_nif81dubp1 X60Qx_960 = kind_0_nifb6mq6y1(o_1);
        if (X60Qx_960 == 11){
          string_0_sysvq0asl X60Qtmp_61 = nodeTag_0_comaa5xpt1(o_1);
          NB8 X60Qx_961 = eqQ_20_sysvq0asl(X60Qtmp_61, (string_0_sysvq0asl){
            .bytes_0 = 1684825603u, .more_0 = NIM_NIL}
          );
          X60Qx_82 = X60Qx_961;
          nimStrDestroy(X60Qtmp_61);}
        else {
          X60Qx_82 = NIM_FALSE;}
        if (X60Qx_82){
          Cursor_0_nifb6mq6y1 f_1 = eQdup_0_nifb6mq6y1(o_1);
          inc_0_nifb6mq6y1((&f_1));
          NifKind_0_nif81dubp1 X60Qx_962 = kind_0_nifb6mq6y1(f_1);
          if (X60Qx_962 == 5){
            NU32 fs_0 = symId_0_nifb6mq6y1(f_1);
            skip_0_nifb6mq6y1((&f_1));
            skip_0_nifb6mq6y1((&f_1));
            skip_0_nifb6mq6y1((&f_1));
            add_0_I34il1q_comaa5xpt1(fields_2, fs_0);
            Cursor_0_nifb6mq6y1 X60Qtmp_62 = f_1;
            eQwasMoved_0_nifb6mq6y1((&f_1));
            add_0_Insw6ce1_comaa5xpt1(ftypes_0, X60Qtmp_62);}
          eQdestroy_0_nifb6mq6y1((&f_1));}
        skip_0_nifb6mq6y1((&o_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&o_1));
  eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(ob_1);}
void emitDefaultInit_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_73, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_45, Cursor_0_nifb6mq6y1 typ_3){
  NI32 X60Qx_963 = typeDefaultKind_0_runot4689(typ_3);
  switch (X60Qx_963){
    case 1:
    {
      NI32 X60Qx_964 = emit_0_comaa5xpt1(ctx_45, 2, 0, 0);
      return;}
    break;
    case 2:
    {
      NI32 X60Qx_965 = emit_0_comaa5xpt1(ctx_45, 3, 0, 0);
      return;}
    break;
    default:
    {
      }
    break;}
  NifKind_0_nif81dubp1 X60Qx_966 = kind_0_nifb6mq6y1(typ_3);
  if (X60Qx_966 == 4){
    NU32 X60Qx_967 = symId_0_nifb6mq6y1(typ_3);
    X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1 X60Qtmp_63 = objectBodyOf_0_comaa5xpt1(X60Qx_967);
    if (X60Qtmp_63.fld_0){
      seq_0_In6doa_ast8ri79k fields_3 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
      seq_0_Isyzizu1_comaa5xpt1 ftypes_1 = newSeqUninit_0_Iikx2qh1_comaa5xpt1(0);
      NU32 X60Qx_968 = symId_0_nifb6mq6y1(typ_3);
      collectObjectFieldsTyped_0_comaa5xpt1(X60Qx_968, (&fields_3), (&ftypes_1));
      if (0 < fields_3.len_0){
        NI32 i_22 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_969 = len_3_I6y2imo_buiyylk1h1(fields_3);
            if (i_22 < X60Qx_969){
              Cursor_0_nifb6mq6y1* X60Qx_970 = getQ_7_Iyegbq3_comaa5xpt1(ftypes_1, i_22);
              emitDefaultInit_0_comaa5xpt1(c_73, ctx_45, (*X60Qx_970));
              inc_1_I6wjjge_aow2h993l1((&i_22));}
            else {
              break;}}}
        whileStmtLabel_0: ;
        NU32 X60Qx_971 = symId_0_nifb6mq6y1(typ_3);
        NI32 X60Qx_972 = addObjInfo_0_comaa5xpt1(c_73, X60Qx_971, fields_3);
        NI32 X60Qx_973 = len_3_I6y2imo_buiyylk1h1(fields_3);
        NI32 X60Qx_974 = emit_0_comaa5xpt1(ctx_45, 37, X60Qx_972, X60Qx_973);
        eQdestroy_1_Ir7cqbo_comaa5xpt1(ftypes_1);
        eQdestroy_1_Iscb4i31_ast8ri79k(fields_3);
        eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qtmp_63);
        return;}
      eQdestroy_1_Ir7cqbo_comaa5xpt1(ftypes_1);
      eQdestroy_1_Iscb4i31_ast8ri79k(fields_3);}
    NU32 X60Qx_975 = symId_0_nifb6mq6y1(typ_3);
    LoadResult_0_prorcx25w1 res_8 = tryLoadSymSafe_0_modzy18mg1(X60Qx_975);
    NB8 X60Qx_83;
    NB8 X60Qx_976;
    if (res_8.status_0 == 3){
      NifKind_0_nif81dubp1 X60Qx_977 = kind_0_nifb6mq6y1(res_8.decl_0);
      X60Qx_976 = (X60Qx_977 == 11);}
    else {
      X60Qx_976 = NIM_FALSE;}
    if (X60Qx_976){
      string_0_sysvq0asl X60Qtmp_64 = nodeTag_0_comaa5xpt1(res_8.decl_0);
      NB8 X60Qx_978 = eqQ_20_sysvq0asl(X60Qtmp_64, (string_0_sysvq0asl){
        .bytes_0 = 1887007998u, .more_0 = (&strlit_0_I13413619771642637377_comaa5xpt1)}
      );
      X60Qx_83 = X60Qx_978;
      nimStrDestroy(X60Qtmp_64);}
    else {
      X60Qx_83 = NIM_FALSE;}
    if (X60Qx_83){
      Cursor_0_nifb6mq6y1 d_5 = res_8.decl_0;
      eQwasMoved_0_nifb6mq6y1((&res_8.decl_0));
      inc_0_nifb6mq6y1((&d_5));
      {
        while (NIM_TRUE){
          NifKind_0_nif81dubp1 X60Qx_979 = kind_0_nifb6mq6y1(d_5);
          if ((!(X60Qx_979 == 12))){
            NifKind_0_nif81dubp1 X60Qx_980 = kind_0_nifb6mq6y1(d_5);
            if (X60Qx_980 == 11){
              string_0_sysvq0asl X60Qtmp_65 = nodeTag_0_comaa5xpt1(d_5);
              NB8 X60Qtc_103 = nimStrAtLe_0_sysvq0asl(X60Qtmp_65, 1, (NC8)'o');
              if (X60Qtc_103){
                NB8 X60Qtc_104 = nimStrAtLe_0_sysvq0asl(X60Qtmp_65, 0, (NC8)'o');
                if (X60Qtc_104){
                  NB8 X60Qtc_105 = nimStrAtLe_0_sysvq0asl(X60Qtmp_65, 0, (NC8)'e');
                  if (X60Qtc_105){
                    NB8 X60Qtc_106 = nimStrAtLe_0_sysvq0asl(X60Qtmp_65, 0, (NC8)'d');
                    if (X60Qtc_106){
                      if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                        .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I3021806080610957510_comaa5xpt1)}
                      )){
                        goto X60Qsc_100;}
                      else if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                        .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_buiyylk1h1)}
                      )){
                        goto X60Qsc_101;}}
                    else {
                      if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                        .bytes_0 = 1970169342u, .more_0 = (&strlit_0_I10462096440466995513_comaa5xpt1)}
                      )){
                        goto X60Qsc_99;}}}
                  else {
                    if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 1970171902u, .more_0 = (&strlit_0_I3225181402180923291_comaa5xpt1)}
                    )){
                      goto X60Qsc_99;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 1784836094u, .more_0 = (&strlit_0_I973692718279674627_comaa5xpt1)}
                    )){
                      goto X60Qsc_102;}}}
                else {
                  NB8 X60Qtc_107 = nimStrAtLe_0_sysvq0asl(X60Qtmp_65, 0, (NC8)'r');
                  if (X60Qtc_107){
                    if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 1717924355u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 1768911102u, .more_0 = (&strlit_0_I6300154543333844069_comaa5xpt1)}
                    )){
                      goto X60Qsc_101;}}
                  else {
                    if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 1952805635u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}}}}
              else {
                NB8 X60Qtc_108 = nimStrAtLe_0_sysvq0asl(X60Qtmp_65, 0, (NC8)'i');
                if (X60Qtc_108){
                  NB8 X60Qtc_109 = nimStrAtLe_0_sysvq0asl(X60Qtmp_65, 0, (NC8)'c');
                  if (X60Qtc_109){
                    NB8 X60Qtc_110 = nimStrAtLe_0_sysvq0asl(X60Qtmp_65, 0, (NC8)'a');
                    if (X60Qtc_110){
                      if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_comaa5xpt1)}
                      )){
                        goto X60Qsc_101;}}
                    else {
                      if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                        .bytes_0 = 25345u, .more_0 = NIM_NIL}
                      )){
                        goto X60Qsc_101;}
                      else if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                        .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
                      )){
                        goto X60Qsc_101;}}}
                  else {
                    if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 26881u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 26113u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}}}
                else {
                  NB8 X60Qtc_111 = nimStrAtLe_0_sysvq0asl(X60Qtmp_65, 0, (NC8)'s');
                  if (X60Qtc_111){
                    if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_comaa5xpt1)}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 1920233475u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}}
                  else {
                    if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 29953u, .more_0 = NIM_NIL}
                    )){
                      goto X60Qsc_101;}
                    else if (equalStrings_0_sysvq0asl(X60Qtmp_65, (string_0_sysvq0asl){
                      .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
                    )){
                      goto X60Qsc_101;}}}}
              goto X60Qsc_113;
              X60Qsc_99: ;
              NU32 X60Qx_981 = symId_0_nifb6mq6y1(typ_3);
              string_0_sysvq0asl X60Qtmp_67 = enumFieldName_0_runot4689(X60Qx_981, 0);
              NU32 X60Qx_982 = symId_0_nifb6mq6y1(typ_3);
              Value_0_valzr1t4f X60Qtmp_66 = vEnum_0_valzr1t4f(0, X60Qx_982, X60Qtmp_67);
              NI32 X60Qx_983 = addConst_0_comaa5xpt1(c_73, (&X60Qtmp_66));
              NI32 X60Qx_984 = emit_0_comaa5xpt1(ctx_45, 0, X60Qx_983, 0);
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_66));
              nimStrDestroy(X60Qtmp_67);
              nimStrDestroy(X60Qtmp_65);
              eQdestroy_0_nifb6mq6y1((&d_5));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
              eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qtmp_63);
              return;
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_66));
              nimStrDestroy(X60Qtmp_67);
              goto X60Qsc_112;
              X60Qsc_100: ;
              Cursor_0_nifb6mq6y1 b_4 = d_5;
              eQwasMoved_0_nifb6mq6y1((&d_5));
              inc_0_nifb6mq6y1((&b_4));
              emitDefaultInit_0_comaa5xpt1(c_73, ctx_45, b_4);
              eQdestroy_0_nifb6mq6y1((&b_4));
              nimStrDestroy(X60Qtmp_65);
              eQdestroy_0_nifb6mq6y1((&d_5));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
              eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qtmp_63);
              return;
              eQdestroy_0_nifb6mq6y1((&b_4));
              goto X60Qsc_112;
              X60Qsc_101: ;
              emitDefaultInit_0_comaa5xpt1(c_73, ctx_45, d_5);
              nimStrDestroy(X60Qtmp_65);
              eQdestroy_0_nifb6mq6y1((&d_5));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
              eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qtmp_63);
              return;
              goto X60Qsc_112;
              X60Qsc_102: ;
              NI32 X60Qx_985 = emit_0_comaa5xpt1(ctx_45, 1, 0, 0);
              nimStrDestroy(X60Qtmp_65);
              eQdestroy_0_nifb6mq6y1((&d_5));
              eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
              eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qtmp_63);
              return;
              goto X60Qsc_112;
              X60Qsc_113: ;
              X60Qsc_112: ;
              nimStrDestroy(X60Qtmp_65);}
            skip_0_nifb6mq6y1((&d_5));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      eQdestroy_0_nifb6mq6y1((&d_5));}
    NI32 X60Qx_986 = emit_0_comaa5xpt1(ctx_45, 1, 0, 0);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
    eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qtmp_63);
    return;
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_8);
    eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qtmp_63);}
  NifKind_0_nif81dubp1 X60Qx_987 = kind_0_nifb6mq6y1(typ_3);
  if (X60Qx_987 == 11){
    string_0_sysvq0asl X60Qtmp_68 = nodeTag_0_comaa5xpt1(typ_3);
    NB8 X60Qtc_121 = nimStrAtLe_0_sysvq0asl(X60Qtmp_68, 0, (NC8)'f');
    if (X60Qtc_121){
      NB8 X60Qtc_122 = nimStrAtLe_0_sysvq0asl(X60Qtmp_68, 0, (NC8)'b');
      if (X60Qtc_122){
        if (equalStrings_0_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
          .bytes_0 = 1869570814u, .more_0 = (&strlit_0_I11024699549390617459_buiyylk1h1)}
        )){
          goto X60Qsc_117;}
        else if (equalStrings_0_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
          .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_comaa5xpt1)}
        )){
          goto X60Qsc_119;}}
      else {
        if (equalStrings_0_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
          .bytes_0 = 26113u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_116;}
        else if (equalStrings_0_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
          .bytes_0 = 25345u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_118;}}}
    else {
      NB8 X60Qtc_123 = nimStrAtLe_0_sysvq0asl(X60Qtmp_68, 0, (NC8)'i');
      if (X60Qtc_123){
        if (equalStrings_0_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
          .bytes_0 = 26881u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_114;}}
      else {
        if (equalStrings_0_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
          .bytes_0 = 29953u, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_115;}
        else if (equalStrings_0_sysvq0asl(X60Qtmp_68, (string_0_sysvq0asl){
          .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I18086024188298164462_buiyylk1h1)}
        )){
          goto X60Qsc_120;}}}
    goto X60Qsc_125;
    X60Qsc_114: ;
    Value_0_valzr1t4f X60Qtmp_69 = vInt_0_valzr1t4f(((NI64)0), 64);
    NI32 X60Qx_988 = addConst_0_comaa5xpt1(c_73, (&X60Qtmp_69));
    NI32 X60Qx_989 = emit_0_comaa5xpt1(ctx_45, 0, X60Qx_988, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_69));
    nimStrDestroy(X60Qtmp_68);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_69));
    goto X60Qsc_124;
    X60Qsc_115: ;
    xint_0_xinat3x34 X60Qx_990 = createXint_0_xinat3x34(((NI64)0));
    Value_0_valzr1t4f X60Qtmp_70 = vUIntX_0_valzr1t4f(X60Qx_990, 64);
    NI32 X60Qx_991 = addConst_0_comaa5xpt1(c_73, (&X60Qtmp_70));
    NI32 X60Qx_992 = emit_0_comaa5xpt1(ctx_45, 0, X60Qx_991, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_70));
    nimStrDestroy(X60Qtmp_68);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_70));
    goto X60Qsc_124;
    X60Qsc_116: ;
    Value_0_valzr1t4f X60Qtmp_71 = vFloat_0_valzr1t4f(0.0, 64);
    NI32 X60Qx_993 = addConst_0_comaa5xpt1(c_73, (&X60Qtmp_71));
    NI32 X60Qx_994 = emit_0_comaa5xpt1(ctx_45, 0, X60Qx_993, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_71));
    nimStrDestroy(X60Qtmp_68);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_71));
    goto X60Qsc_124;
    X60Qsc_117: ;
    Value_0_valzr1t4f X60Qtmp_72 = vBool_0_valzr1t4f(NIM_FALSE);
    NI32 X60Qx_995 = addConst_0_comaa5xpt1(c_73, (&X60Qtmp_72));
    NI32 X60Qx_996 = emit_0_comaa5xpt1(ctx_45, 0, X60Qx_995, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_72));
    nimStrDestroy(X60Qtmp_68);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_72));
    goto X60Qsc_124;
    X60Qsc_118: ;
    Value_0_valzr1t4f X60Qtmp_73 = vChar_0_valzr1t4f((NC8)'\000');
    NI32 X60Qx_997 = addConst_0_comaa5xpt1(c_73, (&X60Qtmp_73));
    NI32 X60Qx_998 = emit_0_comaa5xpt1(ctx_45, 0, X60Qx_997, 0);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_73));
    nimStrDestroy(X60Qtmp_68);
    return;
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_73));
    goto X60Qsc_124;
    X60Qsc_119: ;
    Cursor_0_nifb6mq6y1 a_3 = eQdup_0_nifb6mq6y1(typ_3);
    inc_0_nifb6mq6y1((&a_3));
    Cursor_0_nifb6mq6y1 elemCur_1 = eQdup_0_nifb6mq6y1(a_3);
    skip_0_nifb6mq6y1((&a_3));
    NI32 lo_0 = 0;
    NI32 hi_0 = -1;
    NB8 X60Qx_84;
    NifKind_0_nif81dubp1 X60Qx_999 = kind_0_nifb6mq6y1(a_3);
    if (X60Qx_999 == 11){
      string_0_sysvq0asl X60Qtmp_74 = nodeTag_0_comaa5xpt1(a_3);
      NB8 X60Qx_1000 = eqQ_20_sysvq0asl(X60Qtmp_74, (string_0_sysvq0asl){
        .bytes_0 = 1851880190u, .more_0 = (&strlit_0_I16393544569146403439_comaa5xpt1)}
      );
      X60Qx_84 = X60Qx_1000;
      nimStrDestroy(X60Qtmp_74);}
    else {
      X60Qx_84 = NIM_FALSE;}
    if (X60Qx_84){
      Cursor_0_nifb6mq6y1 r_5 = a_3;
      eQwasMoved_0_nifb6mq6y1((&a_3));
      inc_0_nifb6mq6y1((&r_5));
      skip_0_nifb6mq6y1((&r_5));
      NifKind_0_nif81dubp1 X60Qx_1001 = kind_0_nifb6mq6y1(r_5);
      if (X60Qx_1001 == 8){
        NU32 X60Qx_1002 = intId_0_nifb6mq6y1(r_5);
        NI64* X60Qx_1003 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_1002);
        lo_0 = ((NI32)(*X60Qx_1003));}
      skip_0_nifb6mq6y1((&r_5));
      NifKind_0_nif81dubp1 X60Qx_1004 = kind_0_nifb6mq6y1(r_5);
      if (X60Qx_1004 == 8){
        NU32 X60Qx_1005 = intId_0_nifb6mq6y1(r_5);
        NI64* X60Qx_1006 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_1005);
        hi_0 = ((NI32)(*X60Qx_1006));}
      eQdestroy_0_nifb6mq6y1((&r_5));}
    NI32 i_23 = lo_0;
    {
      while (i_23 <= hi_0){
        emitDefaultInit_0_comaa5xpt1(c_73, ctx_45, elemCur_1);
        inc_1_I6wjjge_aow2h993l1((&i_23));}}
    whileStmtLabel_2: ;
    NI32 X60Qx_1007 = emit_0_comaa5xpt1(ctx_45, 45, lo_0, ((NI32)(((NI32)(hi_0 - lo_0)) + 1)));
    eQdestroy_0_nifb6mq6y1((&elemCur_1));
    eQdestroy_0_nifb6mq6y1((&a_3));
    nimStrDestroy(X60Qtmp_68);
    return;
    eQdestroy_0_nifb6mq6y1((&elemCur_1));
    eQdestroy_0_nifb6mq6y1((&a_3));
    goto X60Qsc_124;
    X60Qsc_120: ;
    Cursor_0_nifb6mq6y1 t_14 = eQdup_0_nifb6mq6y1(typ_3);
    inc_0_nifb6mq6y1((&t_14));
    seq_0_In6doa_ast8ri79k fieldSyms_2 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
    NI32 count_3 = 0;
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_1008 = kind_0_nifb6mq6y1(t_14);
        if ((!(X60Qx_1008 == 12))){
          NB8 X60Qx_85;
          NifKind_0_nif81dubp1 X60Qx_1009 = kind_0_nifb6mq6y1(t_14);
          if (X60Qx_1009 == 11){
            string_0_sysvq0asl X60Qtmp_75 = nodeTag_0_comaa5xpt1(t_14);
            NB8 X60Qx_1010 = eqQ_20_sysvq0asl(X60Qtmp_75, (string_0_sysvq0asl){
              .bytes_0 = 7760642u, .more_0 = NIM_NIL}
            );
            X60Qx_85 = X60Qx_1010;
            nimStrDestroy(X60Qtmp_75);}
          else {
            X60Qx_85 = NIM_FALSE;}
          if (X60Qx_85){
            Cursor_0_nifb6mq6y1 k_1 = eQdup_0_nifb6mq6y1(t_14);
            inc_0_nifb6mq6y1((&k_1));
            NU32 nameSym_0 = ((NU32)0u);
            NB8 X60Qx_1011;
            NifKind_0_nif81dubp1 X60Qx_1012 = kind_0_nifb6mq6y1(k_1);
            if (X60Qx_1012 == 4){
              X60Qx_1011 = NIM_TRUE;}
            else {
              NifKind_0_nif81dubp1 X60Qx_1013 = kind_0_nifb6mq6y1(k_1);
              X60Qx_1011 = (X60Qx_1013 == 5);}
            if (X60Qx_1011){
              NU32 X60Qx_1014 = symId_0_nifb6mq6y1(k_1);
              nameSym_0 = X60Qx_1014;}
            skip_0_nifb6mq6y1((&k_1));
            add_0_I34il1q_comaa5xpt1((&fieldSyms_2), nameSym_0);
            emitDefaultInit_0_comaa5xpt1(c_73, ctx_45, k_1);
            inc_1_I6wjjge_aow2h993l1((&count_3));
            eQdestroy_0_nifb6mq6y1((&k_1));}
          skip_0_nifb6mq6y1((&t_14));}
        else {
          break;}}}
    whileStmtLabel_3: ;
    NI32 X60Qx_1015 = addObjInfo_0_comaa5xpt1(c_73, ((NU32)0u), fieldSyms_2);
    NI32 X60Qx_1016 = emit_0_comaa5xpt1(ctx_45, 40, X60Qx_1015, count_3);
    eQdestroy_1_Iscb4i31_ast8ri79k(fieldSyms_2);
    eQdestroy_0_nifb6mq6y1((&t_14));
    nimStrDestroy(X60Qtmp_68);
    return;
    eQdestroy_1_Iscb4i31_ast8ri79k(fieldSyms_2);
    eQdestroy_0_nifb6mq6y1((&t_14));
    goto X60Qsc_124;
    X60Qsc_125: ;
    X60Qsc_124: ;
    nimStrDestroy(X60Qtmp_68);}
  NI32 X60Qx_1017 = emit_0_comaa5xpt1(ctx_45, 1, 0, 0);}
void compileLocal_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_74, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_46, Cursor_0_nifb6mq6y1* n_41, NB8 isResult_0){
  Local_0_decqocs071 loc_4 = asLocal_0_decqocs071((*n_41), 1);
  NB8 hasInit_0 = NIM_FALSE;
  NB8 X60Qx_1018;
  NifKind_0_nif81dubp1 X60Qx_1019 = kind_0_nifb6mq6y1(loc_4.val_0);
  if ((!(X60Qx_1019 == 2))){
    NifKind_0_nif81dubp1 X60Qx_1020 = kind_0_nifb6mq6y1(loc_4.val_0);
    X60Qx_1018 = (!(X60Qx_1020 == 12));}
  else {
    X60Qx_1018 = NIM_FALSE;}
  if (X60Qx_1018){
    hasInit_0 = NIM_TRUE;}
  NB8 X60Qx_1021;
  if ((!hasInit_0)){
    NB8 X60Qx_1022 = hasImportc_0_hlc70y78v(loc_4.pragmas_0);
    X60Qx_1021 = X60Qx_1022;}
  else {
    X60Qx_1021 = NIM_FALSE;}
  if (X60Qx_1021){
    skip_0_nifb6mq6y1(n_41);
    eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_4));
    return;}
  NifKind_0_nif81dubp1 X60Qx_1023 = kind_0_nifb6mq6y1(loc_4.name_0);
  if (X60Qx_1023 == 5){
    NU32 sym_2 = symId_0_nifb6mq6y1(loc_4.name_0);
    if ((*ctx_46).d_00.isTop_0){
      NI32 slot_3 = (*c_74).d_00.numGlobals_0;
      inc_1_I6wjjge_aow2h993l1((&(*c_74).d_00.numGlobals_0));
      put_0_comaa5xpt1((&(*c_74).d_00.gmap_0), sym_2, slot_3);
      if (hasInit_0){
        Cursor_0_nifb6mq6y1 vc_2 = loc_4.val_0;
        eQwasMoved_0_nifb6mq6y1((&loc_4.val_0));
        compileExpr_1_comaa5xpt1(c_74, ctx_46, (&vc_2));
        NI32 X60Qx_1024 = emit_0_comaa5xpt1(ctx_46, 51, 0, 0);
        eQdestroy_0_nifb6mq6y1((&vc_2));}
      else {
        emitDefaultInit_0_comaa5xpt1(c_74, ctx_46, loc_4.typ_0);}
      NI32 X60Qx_1025 = emit_0_comaa5xpt1(ctx_46, 9, slot_3, 0);}
    else {
      NI32 slot_4 = (*ctx_46).d_00.numLocals_0;
      inc_1_I6wjjge_aow2h993l1((&(*ctx_46).d_00.numLocals_0));
      put_0_comaa5xpt1((&(*ctx_46).d_00.smap_0), sym_2, slot_4);
      if (isResult_0){
        (*ctx_46).d_00.resultSlot_0 = slot_4;}
      if (hasInit_0){
        Cursor_0_nifb6mq6y1 vc_3 = loc_4.val_0;
        eQwasMoved_0_nifb6mq6y1((&loc_4.val_0));
        compileExpr_1_comaa5xpt1(c_74, ctx_46, (&vc_3));
        NI32 X60Qx_1026 = emit_0_comaa5xpt1(ctx_46, 51, 0, 0);
        NI32 X60Qx_1027 = emit_0_comaa5xpt1(ctx_46, 6, slot_4, 0);
        eQdestroy_0_nifb6mq6y1((&vc_3));}
      else {
        NB8 X60Qx_1028;
        NB8 X60Qx_1029;
        NI32 X60Qx_1030 = typeDefaultKind_0_runot4689(loc_4.typ_0);
        if ((!(X60Qx_1030 == 0))){
          X60Qx_1029 = NIM_TRUE;}
        else {
          NB8 X60Qx_1031 = isDefaultInitObject_0_comaa5xpt1(loc_4.typ_0);
          X60Qx_1029 = X60Qx_1031;}
        if (X60Qx_1029){
          X60Qx_1028 = NIM_TRUE;}
        else {
          NB8 X60Qx_1032 = isDefaultInitAggregate_0_comaa5xpt1(loc_4.typ_0);
          X60Qx_1028 = X60Qx_1032;}
        if (X60Qx_1028){
          emitDefaultInit_0_comaa5xpt1(c_74, ctx_46, loc_4.typ_0);
          NI32 X60Qx_1033 = emit_0_comaa5xpt1(ctx_46, 6, slot_4, 0);}}}}
  skip_0_nifb6mq6y1(n_41);
  eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_4));}
void compileAsgn_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_75, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_47, Cursor_0_nifb6mq6y1* n_42){
  inc_0_nifb6mq6y1(n_42);
  NifKind_0_nif81dubp1 X60Qx_1034 = kind_0_nifb6mq6y1((*n_42));
  if (X60Qx_1034 == 4){
    NU32 sym_3 = symId_0_nifb6mq6y1((*n_42));
    inc_0_nifb6mq6y1(n_42);
    compileExpr_1_comaa5xpt1(c_75, ctx_47, n_42);
    NI32 X60Qx_1035 = emit_0_comaa5xpt1(ctx_47, 51, 0, 0);
    consumeParRi_0_nifb6mq6y1(n_42);
    NI32 ls_2 = get_0_comaa5xpt1((*ctx_47).d_00.smap_0, sym_3);
    if (0 <= ls_2){
      NI32 X60Qx_1036 = emit_0_comaa5xpt1(ctx_47, 6, ls_2, 0);}
    else {
      NI32 gs_3 = get_0_comaa5xpt1((*c_75).d_00.gmap_0, sym_3);
      if (0 <= gs_3){
        NI32 X60Qx_1037 = emit_0_comaa5xpt1(ctx_47, 9, gs_3, 0);}
      else {
        NB8 X60Qx_1038 = capturedSym_0_comaa5xpt1(c_75, ctx_47, sym_3);
        if (X60Qx_1038){
          NI32 X60Qx_1039 = addEnvSym_0_comaa5xpt1(c_75, sym_3);
          NI32 X60Qx_1040 = emit_0_comaa5xpt1(ctx_47, 31, X60Qx_1039, 0);}
        else {
          NI32 X60Qx_1041 = globalSlotFor_0_comaa5xpt1(c_75, sym_3);
          NI32 X60Qx_1042 = emit_0_comaa5xpt1(ctx_47, 9, X60Qx_1041, 0);}}}}
  else {
    NB8 X60Qx_86;
    NifKind_0_nif81dubp1 X60Qx_1043 = kind_0_nifb6mq6y1((*n_42));
    if (X60Qx_1043 == 11){
      NB8 X60Qx_87;
      string_0_sysvq0asl X60Qtmp_76 = nodeTag_0_comaa5xpt1((*n_42));
      NB8 X60Qx_1044 = eqQ_20_sysvq0asl(X60Qtmp_76, (string_0_sysvq0asl){
        .bytes_0 = 1701079294u, .more_0 = (&strlit_0_I4196580491060784277_comaa5xpt1)}
      );
      if (X60Qx_1044){
        X60Qx_87 = NIM_TRUE;}
      else {
        string_0_sysvq0asl X60Qtmp_77 = nodeTag_0_comaa5xpt1((*n_42));
        NB8 X60Qx_1045 = eqQ_20_sysvq0asl(X60Qtmp_77, (string_0_sysvq0asl){
          .bytes_0 = 1919247614u, .more_0 = (&strlit_0_I8939511674443647382_comaa5xpt1)}
        );
        X60Qx_87 = X60Qx_1045;
        nimStrDestroy(X60Qtmp_77);}
      X60Qx_86 = X60Qx_87;
      nimStrDestroy(X60Qtmp_76);}
    else {
      X60Qx_86 = NIM_FALSE;}
    if (X60Qx_86){
      Cursor_0_nifb6mq6y1 lhs_0 = eQdup_0_nifb6mq6y1((*n_42));
      skip_0_nifb6mq6y1(n_42);
      compileExpr_1_comaa5xpt1(c_75, ctx_47, n_42);
      consumeParRi_0_nifb6mq6y1(n_42);
      Cursor_0_nifb6mq6y1 lc_2 = lhs_0;
      eQwasMoved_0_nifb6mq6y1((&lhs_0));
      inc_0_nifb6mq6y1((&lc_2));
      compileExpr_1_comaa5xpt1(c_75, ctx_47, (&lc_2));
      NI32 X60Qx_1046 = emit_0_comaa5xpt1(ctx_47, 14, 0, 0);
      eQdestroy_0_nifb6mq6y1((&lc_2));
      eQdestroy_0_nifb6mq6y1((&lhs_0));}
    else {
      NB8 X60Qx_88;
      NifKind_0_nif81dubp1 X60Qx_1047 = kind_0_nifb6mq6y1((*n_42));
      if (X60Qx_1047 == 11){
        NB8 X60Qx_89;
        string_0_sysvq0asl X60Qtmp_78 = nodeTag_0_comaa5xpt1((*n_42));
        NB8 X60Qx_1048 = eqQ_20_sysvq0asl(X60Qtmp_78, (string_0_sysvq0asl){
          .bytes_0 = 1953457155u, .more_0 = NIM_NIL}
        );
        if (X60Qx_1048){
          X60Qx_89 = NIM_TRUE;}
        else {
          string_0_sysvq0asl X60Qtmp_79 = nodeTag_0_comaa5xpt1((*n_42));
          NB8 X60Qx_1049 = eqQ_20_sysvq0asl(X60Qtmp_79, (string_0_sysvq0asl){
            .bytes_0 = 1868850430u, .more_0 = (&strlit_0_I14457488926480995039_comaa5xpt1)}
          );
          X60Qx_89 = X60Qx_1049;
          nimStrDestroy(X60Qtmp_79);}
        X60Qx_88 = X60Qx_89;
        nimStrDestroy(X60Qtmp_78);}
      else {
        X60Qx_88 = NIM_FALSE;}
      if (X60Qx_88){
        Cursor_0_nifb6mq6y1 lhs_1 = eQdup_0_nifb6mq6y1((*n_42));
        skip_0_nifb6mq6y1(n_42);
        compileExpr_1_comaa5xpt1(c_75, ctx_47, n_42);
        consumeParRi_0_nifb6mq6y1(n_42);
        Cursor_0_nifb6mq6y1 lc_3 = lhs_1;
        eQwasMoved_0_nifb6mq6y1((&lhs_1));
        emitFieldAddr_1_comaa5xpt1(c_75, ctx_47, (&lc_3));
        NI32 X60Qx_1050 = emit_0_comaa5xpt1(ctx_47, 14, 0, 0);
        eQdestroy_0_nifb6mq6y1((&lc_3));
        eQdestroy_0_nifb6mq6y1((&lhs_1));}
      else {
        NB8 X60Qx_90;
        NifKind_0_nif81dubp1 X60Qx_1051 = kind_0_nifb6mq6y1((*n_42));
        if (X60Qx_1051 == 11){
          string_0_sysvq0asl X60Qtmp_80 = nodeTag_0_comaa5xpt1((*n_42));
          NB8 X60Qx_1052 = eqQ_20_sysvq0asl(X60Qtmp_80, (string_0_sysvq0asl){
            .bytes_0 = 1886745854u, .more_0 = (&strlit_0_I5323221927989235116_comaa5xpt1)}
          );
          X60Qx_90 = X60Qx_1052;
          nimStrDestroy(X60Qtmp_80);}
        else {
          X60Qx_90 = NIM_FALSE;}
        if (X60Qx_90){
          Cursor_0_nifb6mq6y1 lhs_2 = eQdup_0_nifb6mq6y1((*n_42));
          skip_0_nifb6mq6y1(n_42);
          compileExpr_1_comaa5xpt1(c_75, ctx_47, n_42);
          consumeParRi_0_nifb6mq6y1(n_42);
          Cursor_0_nifb6mq6y1 lc_4 = lhs_2;
          eQwasMoved_0_nifb6mq6y1((&lhs_2));
          emitTupIndex_1_comaa5xpt1(c_75, ctx_47, (&lc_4), NIM_TRUE);
          NI32 X60Qx_1053 = emit_0_comaa5xpt1(ctx_47, 14, 0, 0);
          eQdestroy_0_nifb6mq6y1((&lc_4));
          eQdestroy_0_nifb6mq6y1((&lhs_2));}
        else {
          NB8 X60Qx_8;
          string_0_sysvq0asl t_15;
          nimStrWasMoved((&t_15));
          NifKind_0_nif81dubp1 X60Qx_1054 = kind_0_nifb6mq6y1((*n_42));
          if (X60Qx_1054 == 11){
            nimStrDestroy(t_15);
            string_0_sysvq0asl X60Qx_1055 = nodeTag_0_comaa5xpt1((*n_42));
            t_15 = X60Qx_1055;
            NB8 X60Qx_1056;
            NB8 X60Qx_1057;
            NB8 X60Qx_1058 = eqQ_20_sysvq0asl(t_15, (string_0_sysvq0asl){
              .bytes_0 = 7627010u, .more_0 = NIM_NIL}
            );
            if (X60Qx_1058){
              X60Qx_1057 = NIM_TRUE;}
            else {
              NB8 X60Qx_1059 = eqQ_20_sysvq0asl(t_15, (string_0_sysvq0asl){
                .bytes_0 = 1952542723u, .more_0 = NIM_NIL}
              );
              X60Qx_1057 = X60Qx_1059;}
            if (X60Qx_1057){
              X60Qx_1056 = NIM_TRUE;}
            else {
              NB8 X60Qx_1060 = eqQ_20_sysvq0asl(t_15, (string_0_sysvq0asl){
                .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I3001676635385606767_comaa5xpt1)}
              );
              X60Qx_1056 = X60Qx_1060;}
            X60Qx_8 = X60Qx_1056;}
          else {
            X60Qx_8 = NIM_FALSE;}
          if (X60Qx_8){
            inc_0_nifb6mq6y1(n_42);
            compileExpr_1_comaa5xpt1(c_75, ctx_47, n_42);
            compileExpr_1_comaa5xpt1(c_75, ctx_47, n_42);
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_1061 = kind_0_nifb6mq6y1((*n_42));
                if ((!(X60Qx_1061 == 12))){
                  skip_0_nifb6mq6y1(n_42);}
                else {
                  break;}}}
            whileStmtLabel_0: ;
            consumeParRi_0_nifb6mq6y1(n_42);
            compileExpr_1_comaa5xpt1(c_75, ctx_47, n_42);
            consumeParRi_0_nifb6mq6y1(n_42);
            NI32 X60Qx_1062 = emit_0_comaa5xpt1(ctx_47, 50, 0, 0);}
          else {
            skip_0_nifb6mq6y1(n_42);
            compileExpr_1_comaa5xpt1(c_75, ctx_47, n_42);
            consumeParRi_0_nifb6mq6y1(n_42);
            NI32 X60Qx_1063 = emit_0_comaa5xpt1(ctx_47, 4, 0, 0);}
          nimStrDestroy(t_15);}}}}}
void compileIf_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_76, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_48, Cursor_0_nifb6mq6y1* n_43){
  inc_0_nifb6mq6y1(n_43);
  seq_0_Ift2sne_chu5m1rja1 endPatches_2 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1064 = kind_0_nifb6mq6y1((*n_43));
      if ((!(X60Qx_1064 == 12))){
        string_0_sysvq0asl btag_2 = nodeTag_0_comaa5xpt1((*n_43));
        NB8 X60Qx_1065 = eqQ_20_sysvq0asl(btag_2, (string_0_sysvq0asl){
          .bytes_0 = 1768711678u, .more_0 = (&strlit_0_I13424873862977158440_comaa5xpt1)}
        );
        if (X60Qx_1065){
          inc_0_nifb6mq6y1(n_43);
          compileExpr_1_comaa5xpt1(c_76, ctx_48, n_43);
          NI32 jf_4 = emit_0_comaa5xpt1(ctx_48, 25, 0, 0);
          compileStmt_1_comaa5xpt1(c_76, ctx_48, n_43);
          NI32 X60Qx_1066 = emit_0_comaa5xpt1(ctx_48, 24, 0, 0);
          add_0_I8kd4i4_comaa5xpt1((&endPatches_2), X60Qx_1066);
          NI32 X60Qx_1067 = len_3_Icgec691_comaa5xpt1((*ctx_48).d_00.code_0);
          patch_0_comaa5xpt1(ctx_48, jf_4, X60Qx_1067);
          consumeParRi_0_nifb6mq6y1(n_43);}
        else {
          NB8 X60Qx_1068 = eqQ_20_sysvq0asl(btag_2, (string_0_sysvq0asl){
            .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_comaa5xpt1)}
          );
          if (X60Qx_1068){
            inc_0_nifb6mq6y1(n_43);
            compileStmt_1_comaa5xpt1(c_76, ctx_48, n_43);
            consumeParRi_0_nifb6mq6y1(n_43);}
          else {
            skip_0_nifb6mq6y1(n_43);}}
        nimStrDestroy(btag_2);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_43);
  {
    openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_8 = toOpenArray_1_Ibqb4ob_comaa5xpt1(endPatches_2);
    NI32 X60Qlf_9 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1069 = len_6_I9632ti1_comaa5xpt1(X60Qlf_8);
        if (X60Qlf_9 < X60Qx_1069){
          {
            NI32* X60Qii_3 = getQ_10_I053icq_comaa5xpt1(X60Qlf_8, X60Qlf_9);
            NI32 X60Qx_1070 = len_3_Icgec691_comaa5xpt1((*ctx_48).d_00.code_0);
            patch_0_comaa5xpt1(ctx_48, (*X60Qii_3), X60Qx_1070);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_9));}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  forStmtLabel_1: ;
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(endPatches_2);}
void compileWhile_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_77, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_49, Cursor_0_nifb6mq6y1* n_44){
  inc_0_nifb6mq6y1(n_44);
  NI32 condIp_0 = len_3_Icgec691_comaa5xpt1((*ctx_49).d_00.code_0);
  compileExpr_1_comaa5xpt1(c_77, ctx_49, n_44);
  NI32 jf_5 = emit_0_comaa5xpt1(ctx_49, 25, 0, 0);
  void* X60Qx_1071 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1));
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_81 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1071);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1072 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1073 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  (*X60Qtmp_81) = (X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1){
    .r_00 = 0, .d_00 = (Loop_Obj_0_comaa5xpt1){
      .contTarget_0 = condIp_0, .breaks_0 = X60Qx_1072, .continues_0 = X60Qx_1073, .label_0 = ((NU32)0u)}}
  ;
  add_0_Iuw4xx01_comaa5xpt1((&(*ctx_49).d_00.loops_0), X60Qtmp_81);
  compileStmt_1_comaa5xpt1(c_77, ctx_49, n_44);
  NI32 X60Qx_1074 = emit_0_comaa5xpt1(ctx_49, 24, condIp_0, 0);
  NI32 X60Qx_1075 = len_3_Icgec691_comaa5xpt1((*ctx_49).d_00.code_0);
  patch_0_comaa5xpt1(ctx_49, jf_5, X60Qx_1075);
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1076 = getQ_7_I6yhgto_comaa5xpt1((*ctx_49).d_00.loops_0, ((NI32)((*ctx_49).d_00.loops_0.len_0 - ((NI32)((NI32)1)))));
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* lp_1 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_1076));
  {
    openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_10 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_1).d_00.breaks_0);
    NI32 X60Qlf_11 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1077 = len_6_I9632ti1_comaa5xpt1(X60Qlf_10);
        if (X60Qlf_11 < X60Qx_1077){
          {
            NI32* X60Qii_2 = getQ_10_I053icq_comaa5xpt1(X60Qlf_10, X60Qlf_11);
            NI32 X60Qx_1078 = len_3_Icgec691_comaa5xpt1((*ctx_49).d_00.code_0);
            patch_0_comaa5xpt1(ctx_49, (*X60Qii_2), X60Qx_1078);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_11));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NI32 X60Qx_1079 = len_3_Ij0uoqp_comaa5xpt1((*ctx_49).d_00.loops_0);
  setLen_0_Ivhuv1v1_comaa5xpt1((&(*ctx_49).d_00.loops_0), ((NI32)(X60Qx_1079 - 1)));
  consumeParRi_0_nifb6mq6y1(n_44);
  eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(lp_1);}
void compileBlock_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_78, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_50, Cursor_0_nifb6mq6y1* n_45){
  inc_0_nifb6mq6y1(n_45);
  NU32 lbl_1 = ((NU32)0u);
  NifKind_0_nif81dubp1 X60Qx_1080 = kind_0_nifb6mq6y1((*n_45));
  if (X60Qx_1080 == 5){
    NU32 X60Qx_1081 = symId_0_nifb6mq6y1((*n_45));
    lbl_1 = X60Qx_1081;}
  skip_0_nifb6mq6y1(n_45);
  void* X60Qx_1082 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1));
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_82 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1082);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1083 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1084 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  (*X60Qtmp_82) = (X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1){
    .r_00 = 0, .d_00 = (Loop_Obj_0_comaa5xpt1){
      .contTarget_0 = -1, .breaks_0 = X60Qx_1083, .continues_0 = X60Qx_1084, .label_0 = lbl_1}}
  ;
  add_0_Iuw4xx01_comaa5xpt1((&(*ctx_50).d_00.loops_0), X60Qtmp_82);
  compileStmt_1_comaa5xpt1(c_78, ctx_50, n_45);
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1085 = getQ_7_I6yhgto_comaa5xpt1((*ctx_50).d_00.loops_0, ((NI32)((*ctx_50).d_00.loops_0.len_0 - ((NI32)((NI32)1)))));
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* lp_2 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_1085));
  {
    openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_12 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_2).d_00.continues_0);
    NI32 X60Qlf_13 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1086 = len_6_I9632ti1_comaa5xpt1(X60Qlf_12);
        if (X60Qlf_13 < X60Qx_1086){
          {
            NI32* X60Qii_2 = getQ_10_I053icq_comaa5xpt1(X60Qlf_12, X60Qlf_13);
            NI32 X60Qx_1087 = len_3_Icgec691_comaa5xpt1((*ctx_50).d_00.code_0);
            patch_0_comaa5xpt1(ctx_50, (*X60Qii_2), X60Qx_1087);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_13));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  {
    openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_14 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_2).d_00.breaks_0);
    NI32 X60Qlf_15 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1088 = len_6_I9632ti1_comaa5xpt1(X60Qlf_14);
        if (X60Qlf_15 < X60Qx_1088){
          {
            NI32* X60Qii_5 = getQ_10_I053icq_comaa5xpt1(X60Qlf_14, X60Qlf_15);
            NI32 X60Qx_1089 = len_3_Icgec691_comaa5xpt1((*ctx_50).d_00.code_0);
            patch_0_comaa5xpt1(ctx_50, (*X60Qii_5), X60Qx_1089);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_15));}
        else {
          break;}}}
    whileStmtLabel_4: ;}
  forStmtLabel_3: ;
  NI32 X60Qx_1090 = len_3_Ij0uoqp_comaa5xpt1((*ctx_50).d_00.loops_0);
  setLen_0_Ivhuv1v1_comaa5xpt1((&(*ctx_50).d_00.loops_0), ((NI32)(X60Qx_1090 - 1)));
  consumeParRi_0_nifb6mq6y1(n_45);
  eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(lp_2);}
seq_0_Ift2sne_chu5m1rja1 bindLoopVars_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_79, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_51, Cursor_0_nifb6mq6y1 binder_0, seq_0_Ik7wkpe_comaa5xpt1* plan_0){
  seq_0_Ift2sne_chu5m1rja1 result_42;
  eQwasMoved_1_Ix88qzs1_chu5m1rja1((&result_42));
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(result_42);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1091 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  result_42 = X60Qx_1091;
  eQdestroy_1_Ij4pznj1_comaa5xpt1((*plan_0));
  seq_0_Ik7wkpe_comaa5xpt1 X60Qx_1092 = newSeqUninit_0_Idxnvmq_comaa5xpt1(0);
  (*plan_0) = X60Qx_1092;
  Cursor_0_nifb6mq6y1 b_5 = eQdup_0_nifb6mq6y1(binder_0);
  NifKind_0_nif81dubp1 X60Qx_1093 = kind_0_nifb6mq6y1(b_5);
  if ((!(X60Qx_1093 == 11))){
    eQdestroy_0_nifb6mq6y1((&b_5));
    return result_42;}
  inc_0_nifb6mq6y1((&b_5));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1094 = kind_0_nifb6mq6y1(b_5);
      if ((!(X60Qx_1094 == 12))){
        NB8 X60Qx_91;
        NifKind_0_nif81dubp1 X60Qx_1095 = kind_0_nifb6mq6y1(b_5);
        if (X60Qx_1095 == 11){
          string_0_sysvq0asl X60Qtmp_83 = nodeTag_0_comaa5xpt1(b_5);
          NB8 X60Qx_1096 = eqQ_20_sysvq0asl(X60Qtmp_83, (string_0_sysvq0asl){
            .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
          );
          X60Qx_91 = X60Qx_1096;
          nimStrDestroy(X60Qtmp_83);}
        else {
          X60Qx_91 = NIM_FALSE;}
        if (X60Qx_91){
          Cursor_0_nifb6mq6y1 d_6 = eQdup_0_nifb6mq6y1(b_5);
          inc_0_nifb6mq6y1((&d_6));
          NifKind_0_nif81dubp1 X60Qx_1097 = kind_0_nifb6mq6y1(d_6);
          if (X60Qx_1097 == 5){
            NI32 slot_5 = (*ctx_51).d_00.numLocals_0;
            inc_1_I6wjjge_aow2h993l1((&(*ctx_51).d_00.numLocals_0));
            NU32 X60Qx_1098 = symId_0_nifb6mq6y1(d_6);
            put_0_comaa5xpt1((&(*ctx_51).d_00.smap_0), X60Qx_1098, slot_5);
            add_0_I8kd4i4_comaa5xpt1((&result_42), slot_5);
            seq_0_Ift2sne_chu5m1rja1 X60Qx_1099 = atQ_0_Iy7v4si1_comaa5xpt1((X60Qt_0_IAarrayAiS32ZS1_comaa5xpt1){
              .a = {
                slot_5}}
            );
            add_0_Iivdbhc_comaa5xpt1(plan_0, X60Qx_1099);}
          skip_0_nifb6mq6y1((&b_5));
          eQdestroy_0_nifb6mq6y1((&d_6));}
        else {
          NB8 X60Qx_92;
          NifKind_0_nif81dubp1 X60Qx_1100 = kind_0_nifb6mq6y1(b_5);
          if (X60Qx_1100 == 11){
            string_0_sysvq0asl X60Qtmp_84 = nodeTag_0_comaa5xpt1(b_5);
            NB8 X60Qx_1101 = eqQ_20_sysvq0asl(X60Qtmp_84, (string_0_sysvq0asl){
              .bytes_0 = 1886287358u, .more_0 = (&strlit_0_I1237672436915077942_comaa5xpt1)}
            );
            X60Qx_92 = X60Qx_1101;
            nimStrDestroy(X60Qtmp_84);}
          else {
            X60Qx_92 = NIM_FALSE;}
          if (X60Qx_92){
            seq_0_Ift2sne_chu5m1rja1 group_0 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
            Cursor_0_nifb6mq6y1 cc_10 = eQdup_0_nifb6mq6y1(b_5);
            inc_0_nifb6mq6y1((&cc_10));
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_1102 = kind_0_nifb6mq6y1(cc_10);
                if ((!(X60Qx_1102 == 12))){
                  NB8 X60Qx_93;
                  NifKind_0_nif81dubp1 X60Qx_1103 = kind_0_nifb6mq6y1(cc_10);
                  if (X60Qx_1103 == 11){
                    string_0_sysvq0asl X60Qtmp_85 = nodeTag_0_comaa5xpt1(cc_10);
                    NB8 X60Qx_1104 = eqQ_20_sysvq0asl(X60Qtmp_85, (string_0_sysvq0asl){
                      .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
                    );
                    X60Qx_93 = X60Qx_1104;
                    nimStrDestroy(X60Qtmp_85);}
                  else {
                    X60Qx_93 = NIM_FALSE;}
                  if (X60Qx_93){
                    Cursor_0_nifb6mq6y1 d_7 = eQdup_0_nifb6mq6y1(cc_10);
                    inc_0_nifb6mq6y1((&d_7));
                    NifKind_0_nif81dubp1 X60Qx_1105 = kind_0_nifb6mq6y1(d_7);
                    if (X60Qx_1105 == 5){
                      NI32 slot_6 = (*ctx_51).d_00.numLocals_0;
                      inc_1_I6wjjge_aow2h993l1((&(*ctx_51).d_00.numLocals_0));
                      NU32 X60Qx_1106 = symId_0_nifb6mq6y1(d_7);
                      put_0_comaa5xpt1((&(*ctx_51).d_00.smap_0), X60Qx_1106, slot_6);
                      add_0_I8kd4i4_comaa5xpt1((&result_42), slot_6);
                      add_0_I8kd4i4_comaa5xpt1((&group_0), slot_6);}
                    eQdestroy_0_nifb6mq6y1((&d_7));}
                  skip_0_nifb6mq6y1((&cc_10));}
                else {
                  break;}}}
            whileStmtLabel_1: ;
            seq_0_Ift2sne_chu5m1rja1 X60Qtmp_86 = group_0;
            eQwasMoved_1_Ix88qzs1_chu5m1rja1((&group_0));
            add_0_Iivdbhc_comaa5xpt1(plan_0, X60Qtmp_86);
            skip_0_nifb6mq6y1((&b_5));
            eQdestroy_0_nifb6mq6y1((&cc_10));
            eQdestroy_1_Iv9ij5i1_chu5m1rja1(group_0);}
          else {
            skip_0_nifb6mq6y1((&b_5));}}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  eQdestroy_0_nifb6mq6y1((&b_5));
  return result_42;
  eQdestroy_0_nifb6mq6y1((&b_5));
  return result_42;}
NB8 binderSingleScalar_0_comaa5xpt1(Cursor_0_nifb6mq6y1 binder_2){
  NB8 result_44;
  Cursor_0_nifb6mq6y1 b_6 = eQdup_0_nifb6mq6y1(binder_2);
  NifKind_0_nif81dubp1 X60Qx_1108 = kind_0_nifb6mq6y1(b_6);
  if ((!(X60Qx_1108 == 11))){
    eQdestroy_0_nifb6mq6y1((&b_6));
    return NIM_FALSE;}
  inc_0_nifb6mq6y1((&b_6));
  NI32 lets_0 = 0;
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1109 = kind_0_nifb6mq6y1(b_6);
      if ((!(X60Qx_1109 == 12))){
        NB8 X60Qx_94;
        NifKind_0_nif81dubp1 X60Qx_1110 = kind_0_nifb6mq6y1(b_6);
        if (X60Qx_1110 == 11){
          string_0_sysvq0asl X60Qtmp_87 = nodeTag_0_comaa5xpt1(b_6);
          NB8 X60Qx_1111 = eqQ_20_sysvq0asl(X60Qtmp_87, (string_0_sysvq0asl){
            .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
          );
          X60Qx_94 = X60Qx_1111;
          nimStrDestroy(X60Qtmp_87);}
        else {
          X60Qx_94 = NIM_FALSE;}
        if (X60Qx_94){
          inc_1_I6wjjge_aow2h993l1((&lets_0));}
        else {
          NB8 X60Qx_95;
          NifKind_0_nif81dubp1 X60Qx_1112 = kind_0_nifb6mq6y1(b_6);
          if (X60Qx_1112 == 11){
            string_0_sysvq0asl X60Qtmp_88 = nodeTag_0_comaa5xpt1(b_6);
            NB8 X60Qx_1113 = eqQ_20_sysvq0asl(X60Qtmp_88, (string_0_sysvq0asl){
              .bytes_0 = 1886287358u, .more_0 = (&strlit_0_I1237672436915077942_comaa5xpt1)}
            );
            X60Qx_95 = X60Qx_1113;
            nimStrDestroy(X60Qtmp_88);}
          else {
            X60Qx_95 = NIM_FALSE;}
          if (X60Qx_95){
            eQdestroy_0_nifb6mq6y1((&b_6));
            return NIM_FALSE;}}
        skip_0_nifb6mq6y1((&b_6));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_44 = (lets_0 == 1);
  eQdestroy_0_nifb6mq6y1((&b_6));
  return result_44;
  eQdestroy_0_nifb6mq6y1((&b_6));
  return result_44;}
void emitBindFromTos_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_81, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_53, seq_0_Ik7wkpe_comaa5xpt1 plan_1, NI32 tmpSlot_0, NI32 nestTmpSlot_0){
  NI32 X60Qx_1114 = len_3_Irjnvku_comaa5xpt1(plan_1);
  if (X60Qx_1114 == 0){
    NI32 X60Qx_1115 = emit_0_comaa5xpt1(ctx_53, 4, 0, 0);}
  else {
    NB8 X60Qx_1116;
    NI32 X60Qx_1117 = len_3_Irjnvku_comaa5xpt1(plan_1);
    if (X60Qx_1117 == 1){
      seq_0_Ift2sne_chu5m1rja1* X60Qx_1118 = getQ_7_Iurb46i_comaa5xpt1(plan_1, 0);
      NI32 X60Qx_1119 = len_3_I0v1j8d_comaa5xpt1((*X60Qx_1118));
      X60Qx_1116 = (X60Qx_1119 == 1);}
    else {
      X60Qx_1116 = NIM_FALSE;}
    if (X60Qx_1116){
      seq_0_Ift2sne_chu5m1rja1* X60Qx_1120 = getQ_7_Iurb46i_comaa5xpt1(plan_1, 0);
      NI32* X60Qx_1121 = getQ_7_Ir8kccm_comaa5xpt1((*X60Qx_1120), 0);
      NI32 X60Qx_1122 = emit_0_comaa5xpt1(ctx_53, 6, (*X60Qx_1121), 0);}
    else {
      NI32 X60Qx_1123 = emit_0_comaa5xpt1(ctx_53, 6, tmpSlot_0, 0);
      NI32 X60Qx_1124 = len_3_Irjnvku_comaa5xpt1(plan_1);
      if (X60Qx_1124 == 1){
        seq_0_Ift2sne_chu5m1rja1* X60Qx_1125 = getQ_7_Iurb46i_comaa5xpt1(plan_1, 0);
        seq_0_Ift2sne_chu5m1rja1 group_1 = eQdup_1_Iplow11_chu5m1rja1((*X60Qx_1125));
        NI32 k_2 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1126 = len_3_I0v1j8d_comaa5xpt1(group_1);
            if (k_2 < X60Qx_1126){
              NI32 X60Qx_1127 = emit_0_comaa5xpt1(ctx_53, 5, tmpSlot_0, 0);
              Value_0_valzr1t4f X60Qtmp_89 = vInt_0_valzr1t4f(((NI64)k_2), 64);
              NI32 X60Qx_1128 = addConst_0_comaa5xpt1(c_81, (&X60Qtmp_89));
              NI32 X60Qx_1129 = emit_0_comaa5xpt1(ctx_53, 0, X60Qx_1128, 0);
              NI32 X60Qx_1130 = emit_0_comaa5xpt1(ctx_53, 43, 0, 0);
              NI32* X60Qx_1131 = getQ_7_Ir8kccm_comaa5xpt1(group_1, k_2);
              NI32 X60Qx_1132 = emit_0_comaa5xpt1(ctx_53, 6, (*X60Qx_1131), 0);
              inc_1_I6wjjge_aow2h993l1((&k_2));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_89));}
            else {
              break;}}}
        whileStmtLabel_0: ;
        eQdestroy_1_Iv9ij5i1_chu5m1rja1(group_1);}
      else {
        NI32 j_0 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1133 = len_3_Irjnvku_comaa5xpt1(plan_1);
            if (j_0 < X60Qx_1133){
              seq_0_Ift2sne_chu5m1rja1* X60Qx_1134 = getQ_7_Iurb46i_comaa5xpt1(plan_1, j_0);
              seq_0_Ift2sne_chu5m1rja1 group_2 = eQdup_1_Iplow11_chu5m1rja1((*X60Qx_1134));
              NI32 X60Qx_1135 = len_3_I0v1j8d_comaa5xpt1(group_2);
              if (X60Qx_1135 == 1){
                NI32 X60Qx_1136 = emit_0_comaa5xpt1(ctx_53, 5, tmpSlot_0, 0);
                Value_0_valzr1t4f X60Qtmp_90 = vInt_0_valzr1t4f(((NI64)j_0), 64);
                NI32 X60Qx_1137 = addConst_0_comaa5xpt1(c_81, (&X60Qtmp_90));
                NI32 X60Qx_1138 = emit_0_comaa5xpt1(ctx_53, 0, X60Qx_1137, 0);
                NI32 X60Qx_1139 = emit_0_comaa5xpt1(ctx_53, 43, 0, 0);
                NI32* X60Qx_1140 = getQ_7_Ir8kccm_comaa5xpt1(group_2, 0);
                NI32 X60Qx_1141 = emit_0_comaa5xpt1(ctx_53, 6, (*X60Qx_1140), 0);
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_90));}
              else {
                NI32 X60Qx_1142 = emit_0_comaa5xpt1(ctx_53, 5, tmpSlot_0, 0);
                Value_0_valzr1t4f X60Qtmp_91 = vInt_0_valzr1t4f(((NI64)j_0), 64);
                NI32 X60Qx_1143 = addConst_0_comaa5xpt1(c_81, (&X60Qtmp_91));
                NI32 X60Qx_1144 = emit_0_comaa5xpt1(ctx_53, 0, X60Qx_1143, 0);
                NI32 X60Qx_1145 = emit_0_comaa5xpt1(ctx_53, 43, 0, 0);
                NI32 X60Qx_1146 = emit_0_comaa5xpt1(ctx_53, 6, nestTmpSlot_0, 0);
                NI32 k_3 = 0;
                {
                  while (NIM_TRUE){
                    NI32 X60Qx_1147 = len_3_I0v1j8d_comaa5xpt1(group_2);
                    if (k_3 < X60Qx_1147){
                      NI32 X60Qx_1148 = emit_0_comaa5xpt1(ctx_53, 5, nestTmpSlot_0, 0);
                      Value_0_valzr1t4f X60Qtmp_92 = vInt_0_valzr1t4f(((NI64)k_3), 64);
                      NI32 X60Qx_1149 = addConst_0_comaa5xpt1(c_81, (&X60Qtmp_92));
                      NI32 X60Qx_1150 = emit_0_comaa5xpt1(ctx_53, 0, X60Qx_1149, 0);
                      NI32 X60Qx_1151 = emit_0_comaa5xpt1(ctx_53, 43, 0, 0);
                      NI32* X60Qx_1152 = getQ_7_Ir8kccm_comaa5xpt1(group_2, k_3);
                      NI32 X60Qx_1153 = emit_0_comaa5xpt1(ctx_53, 6, (*X60Qx_1152), 0);
                      inc_1_I6wjjge_aow2h993l1((&k_3));
                      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_92));}
                    else {
                      break;}}}
                whileStmtLabel_2: ;
                eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_91));}
              inc_1_I6wjjge_aow2h993l1((&j_0));
              eQdestroy_1_Iv9ij5i1_chu5m1rja1(group_2);}
            else {
              break;}}}
        whileStmtLabel_1: ;}}}}
void compileCoroFor_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_82, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_54, NU32 iterSym_1, seq_0_Isyzizu1_comaa5xpt1 argCursors_1, seq_0_Ift2sne_chu5m1rja1 loopSlots_1, seq_0_Ik7wkpe_comaa5xpt1 loopPlan_1, Cursor_0_nifb6mq6y1 binderCur_1, Cursor_0_nifb6mq6y1 bodyCur_1){
  NI32 coroSlot_0 = (*ctx_54).d_00.numLocals_0;
  inc_1_I6wjjge_aow2h993l1((&(*ctx_54).d_00.numLocals_0));
  NI32 tmpSlot_1 = (*ctx_54).d_00.numLocals_0;
  inc_1_I6wjjge_aow2h993l1((&(*ctx_54).d_00.numLocals_0));
  NI32 nestTmpSlot_1 = (*ctx_54).d_00.numLocals_0;
  inc_1_I6wjjge_aow2h993l1((&(*ctx_54).d_00.numLocals_0));
  NI32 ls_3 = get_0_comaa5xpt1((*ctx_54).d_00.smap_0, iterSym_1);
  NI32 gs_4 = get_0_comaa5xpt1((*c_82).d_00.gmap_0, iterSym_1);
  NI32 byAddr_0 = 0;
  if (0 <= ls_3){
    NI32 X60Qx_1154 = emit_0_comaa5xpt1(ctx_54, 7, ls_3, 0);
    byAddr_0 = 1;}
  else {
    if (0 <= gs_4){
      NI32 X60Qx_1155 = emit_0_comaa5xpt1(ctx_54, 10, gs_4, 0);
      byAddr_0 = 1;}
    else {
      resolveSymbol_1_comaa5xpt1(c_82, ctx_54, iterSym_1);}}
  NI32 ai_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1156 = len_3_Ilsmz1h_comaa5xpt1(argCursors_1);
      if (ai_0 < X60Qx_1156){
        Cursor_0_nifb6mq6y1* X60Qx_1157 = getQ_7_Iyegbq3_comaa5xpt1(argCursors_1, ai_0);
        Cursor_0_nifb6mq6y1 ac_0 = eQdup_0_nifb6mq6y1((*X60Qx_1157));
        compileExpr_1_comaa5xpt1(c_82, ctx_54, (&ac_0));
        inc_1_I6wjjge_aow2h993l1((&ai_0));
        eQdestroy_0_nifb6mq6y1((&ac_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_1158 = len_3_Ilsmz1h_comaa5xpt1(argCursors_1);
  NI32 X60Qx_1159 = emit_0_comaa5xpt1(ctx_54, 73, byAddr_0, X60Qx_1158);
  NI32 X60Qx_1160 = emit_0_comaa5xpt1(ctx_54, 6, coroSlot_0, 0);
  NI32 startIp_0 = len_3_Icgec691_comaa5xpt1((*ctx_54).d_00.code_0);
  NI32 X60Qx_1161 = emit_0_comaa5xpt1(ctx_54, 74, coroSlot_0, 0);
  NI32 jf_6 = emit_0_comaa5xpt1(ctx_54, 25, 0, 0);
  void* X60Qx_1162 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1));
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_93 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1162);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1163 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1164 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  (*X60Qtmp_93) = (X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1){
    .r_00 = 0, .d_00 = (Loop_Obj_0_comaa5xpt1){
      .contTarget_0 = -1, .breaks_0 = X60Qx_1163, .continues_0 = X60Qx_1164, .label_0 = ((NU32)0u)}}
  ;
  add_0_Iuw4xx01_comaa5xpt1((&(*ctx_54).d_00.loops_0), X60Qtmp_93);
  emitBindFromTos_0_comaa5xpt1(c_82, ctx_54, loopPlan_1, tmpSlot_1, nestTmpSlot_1);
  Cursor_0_nifb6mq6y1 bc_0 = eQdup_0_nifb6mq6y1(bodyCur_1);
  compileStmt_1_comaa5xpt1(c_82, ctx_54, (&bc_0));
  NI32 X60Qx_1165 = emit_0_comaa5xpt1(ctx_54, 24, startIp_0, 0);
  NI32 X60Qx_1166 = len_3_Icgec691_comaa5xpt1((*ctx_54).d_00.code_0);
  patch_0_comaa5xpt1(ctx_54, jf_6, X60Qx_1166);
  NI32 X60Qx_1167 = emit_0_comaa5xpt1(ctx_54, 4, 0, 0);
  NI32 endIp_0 = len_3_Icgec691_comaa5xpt1((*ctx_54).d_00.code_0);
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1168 = getQ_7_I6yhgto_comaa5xpt1((*ctx_54).d_00.loops_0, ((NI32)((*ctx_54).d_00.loops_0.len_0 - ((NI32)((NI32)1)))));
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* lp_3 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_1168));
  {
    openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_16 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_3).d_00.continues_0);
    NI32 X60Qlf_17 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1169 = len_6_I9632ti1_comaa5xpt1(X60Qlf_16);
        if (X60Qlf_17 < X60Qx_1169){
          {
            NI32* X60Qii_3 = getQ_10_I053icq_comaa5xpt1(X60Qlf_16, X60Qlf_17);
            patch_0_comaa5xpt1(ctx_54, (*X60Qii_3), startIp_0);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_17));}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  forStmtLabel_1: ;
  {
    openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_18 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_3).d_00.breaks_0);
    NI32 X60Qlf_19 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1170 = len_6_I9632ti1_comaa5xpt1(X60Qlf_18);
        if (X60Qlf_19 < X60Qx_1170){
          {
            NI32* X60Qii_6 = getQ_10_I053icq_comaa5xpt1(X60Qlf_18, X60Qlf_19);
            patch_0_comaa5xpt1(ctx_54, (*X60Qii_6), endIp_0);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_19));}
        else {
          break;}}}
    whileStmtLabel_5: ;}
  forStmtLabel_4: ;
  NI32 X60Qx_1171 = len_3_Ij0uoqp_comaa5xpt1((*ctx_54).d_00.loops_0);
  setLen_0_Ivhuv1v1_comaa5xpt1((&(*ctx_54).d_00.loops_0), ((NI32)(X60Qx_1171 - 1)));
  eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(lp_3);
  eQdestroy_0_nifb6mq6y1((&bc_0));}
void compileFor_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_83, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_55, Cursor_0_nifb6mq6y1* n_46){
  inc_0_nifb6mq6y1(n_46);
  Cursor_0_nifb6mq6y1 iterCur_0 = eQdup_0_nifb6mq6y1((*n_46));
  skip_0_nifb6mq6y1(n_46);
  Cursor_0_nifb6mq6y1 binderCur_2 = eQdup_0_nifb6mq6y1((*n_46));
  skip_0_nifb6mq6y1(n_46);
  Cursor_0_nifb6mq6y1 bodyCur_2 = eQdup_0_nifb6mq6y1((*n_46));
  skip_0_nifb6mq6y1(n_46);
  consumeParRi_0_nifb6mq6y1(n_46);
  Cursor_0_nifb6mq6y1 it_0 = iterCur_0;
  eQwasMoved_0_nifb6mq6y1((&iterCur_0));
  NB8 stripping_0 = NIM_TRUE;
  {
    while (NIM_TRUE){
      NB8 X60Qx_1172;
      if (stripping_0){
        NifKind_0_nif81dubp1 X60Qx_1173 = kind_0_nifb6mq6y1(it_0);
        X60Qx_1172 = (X60Qx_1173 == 11);}
      else {
        X60Qx_1172 = NIM_FALSE;}
      if (X60Qx_1172){
        string_0_sysvq0asl itag_0 = nodeTag_0_comaa5xpt1(it_0);
        NB8 X60Qx_1174;
        NB8 X60Qx_1175 = eqQ_20_sysvq0asl(itag_0, (string_0_sysvq0asl){
          .bytes_0 = 1701079294u, .more_0 = (&strlit_0_I4196580491060784277_comaa5xpt1)}
        );
        if (X60Qx_1175){
          X60Qx_1174 = NIM_TRUE;}
        else {
          NB8 X60Qx_1176 = eqQ_20_sysvq0asl(itag_0, (string_0_sysvq0asl){
            .bytes_0 = 1633904894u, .more_0 = (&strlit_0_I12061648672903694946_comaa5xpt1)}
          );
          X60Qx_1174 = X60Qx_1176;}
        if (X60Qx_1174){
          inc_0_nifb6mq6y1((&it_0));}
        else {
          NB8 X60Qx_1177;
          NB8 X60Qx_1178 = eqQ_20_sysvq0asl(itag_0, (string_0_sysvq0asl){
            .bytes_0 = 1868785918u, .more_0 = (&strlit_0_I710932595938440230_comaa5xpt1)}
          );
          if (X60Qx_1178){
            X60Qx_1177 = NIM_TRUE;}
          else {
            NB8 X60Qx_1179 = eqQ_20_sysvq0asl(itag_0, (string_0_sysvq0asl){
              .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2501487269769466366_comaa5xpt1)}
            );
            X60Qx_1177 = X60Qx_1179;}
          if (X60Qx_1177){
            inc_0_nifb6mq6y1((&it_0));
            skip_0_nifb6mq6y1((&it_0));}
          else {
            stripping_0 = NIM_FALSE;}}
        nimStrDestroy(itag_0);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NU32 iterSym_2 = ((NU32)0u);
  seq_0_Isyzizu1_comaa5xpt1 argCursors_2 = newSeqUninit_0_Iikx2qh1_comaa5xpt1(0);
  NifKind_0_nif81dubp1 X60Qx_1180 = kind_0_nifb6mq6y1(it_0);
  if (X60Qx_1180 == 11){
    inc_0_nifb6mq6y1((&it_0));
    NifKind_0_nif81dubp1 X60Qx_1181 = kind_0_nifb6mq6y1(it_0);
    if (X60Qx_1181 == 4){
      NU32 X60Qx_1182 = symId_0_nifb6mq6y1(it_0);
      iterSym_2 = X60Qx_1182;}
    skip_0_nifb6mq6y1((&it_0));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_1183 = kind_0_nifb6mq6y1(it_0);
        if ((!(X60Qx_1183 == 12))){
          Cursor_0_nifb6mq6y1 X60Qx_1184 = eQdup_0_nifb6mq6y1(it_0);
          add_0_Insw6ce1_comaa5xpt1((&argCursors_2), X60Qx_1184);
          skip_0_nifb6mq6y1((&it_0));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  string_0_sysvq0asl base_4 = baseName_0_comaa5xpt1(iterSym_2);
  seq_0_Ik7wkpe_comaa5xpt1 loopPlan_2 = newSeqUninit_0_Idxnvmq_comaa5xpt1(0);
  seq_0_Ift2sne_chu5m1rja1 loopSlots_2 = bindLoopVars_0_comaa5xpt1(c_83, ctx_55, binderCur_2, (&loopPlan_2));
  NB8 X60Qx_1185;
  NB8 X60Qx_1186;
  NB8 X60Qx_1187;
  NB8 X60Qx_1188 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
    .bytes_0 = 3026434u, .more_0 = NIM_NIL}
  );
  if (X60Qx_1188){
    X60Qx_1187 = NIM_TRUE;}
  else {
    NB8 X60Qx_1189 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
      .bytes_0 = 1009659395u, .more_0 = NIM_NIL}
    );
    X60Qx_1187 = X60Qx_1189;}
  if (X60Qx_1187){
    X60Qx_1186 = (2 <= argCursors_2.len_0);}
  else {
    X60Qx_1186 = NIM_FALSE;}
  if (X60Qx_1186){
    X60Qx_1185 = (1 <= loopSlots_2.len_0);}
  else {
    X60Qx_1185 = NIM_FALSE;}
  if (X60Qx_1185){
    NU32 enumType_1 = ((NU32)0u);
    {
      Cursor_0_nifb6mq6y1* X60Qx_1190 = getQ_7_Iyegbq3_comaa5xpt1(argCursors_2, 0);
      Cursor_0_nifb6mq6y1 ac_1 = eQdup_0_nifb6mq6y1((*X60Qx_1190));
      {
        while (NIM_TRUE){
          NB8 X60Qx_96;
          NifKind_0_nif81dubp1 X60Qx_1191 = kind_0_nifb6mq6y1(ac_1);
          if (X60Qx_1191 == 11){
            NB8 X60Qx_97;
            string_0_sysvq0asl X60Qtmp_94 = nodeTag_0_comaa5xpt1(ac_1);
            NB8 X60Qx_1192 = eqQ_20_sysvq0asl(X60Qtmp_94, (string_0_sysvq0asl){
              .bytes_0 = 1868785918u, .more_0 = (&strlit_0_I710932595938440230_comaa5xpt1)}
            );
            if (X60Qx_1192){
              X60Qx_97 = NIM_TRUE;}
            else {
              string_0_sysvq0asl X60Qtmp_95 = nodeTag_0_comaa5xpt1(ac_1);
              NB8 X60Qx_1193 = eqQ_20_sysvq0asl(X60Qtmp_95, (string_0_sysvq0asl){
                .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2501487269769466366_comaa5xpt1)}
              );
              X60Qx_97 = X60Qx_1193;
              nimStrDestroy(X60Qtmp_95);}
            X60Qx_96 = X60Qx_97;
            nimStrDestroy(X60Qtmp_94);}
          else {
            X60Qx_96 = NIM_FALSE;}
          if (X60Qx_96){
            inc_0_nifb6mq6y1((&ac_1));
            skip_0_nifb6mq6y1((&ac_1));}
          else {
            break;}}}
      whileStmtLabel_3: ;
      NifKind_0_nif81dubp1 X60Qx_1194 = kind_0_nifb6mq6y1(ac_1);
      if (X60Qx_1194 == 4){
        NU32 X60Qx_1195 = symId_0_nifb6mq6y1(ac_1);
        NU32 X60Qx_1196 = enumTypeOfField_0_runot4689(X60Qx_1195);
        enumType_1 = X60Qx_1196;}
      eQdestroy_0_nifb6mq6y1((&ac_1));}
    X60Qlab_2: ;
    NB8 isEnum_0 = (!(((NU32)enumType_1) == ((NU32)0u)));
    NI32 X60Qx_9;
    if (isEnum_0){
      NI32 X60Qx_1197 = addEnumWrap_0_comaa5xpt1(c_83, enumType_1);
      X60Qx_9 = X60Qx_1197;}
    else {
      X60Qx_9 = -1;}
    NI32 wrapIdx_0 = X60Qx_9;
    NI32* X60Qx_1198 = getQ_7_Ir8kccm_comaa5xpt1(loopSlots_2, 0);
    NI32 iSlot_0 = (*X60Qx_1198);
    Cursor_0_nifb6mq6y1* X60Qx_1199 = getQ_7_Iyegbq3_comaa5xpt1(argCursors_2, 0);
    Cursor_0_nifb6mq6y1 loC_0 = eQdup_0_nifb6mq6y1((*X60Qx_1199));
    compileExpr_1_comaa5xpt1(c_83, ctx_55, (&loC_0));
    NI32 X60Qx_1200 = emit_0_comaa5xpt1(ctx_55, 6, iSlot_0, 0);
    NI32 topSlot_0 = (*ctx_55).d_00.numLocals_0;
    inc_1_I6wjjge_aow2h993l1((&(*ctx_55).d_00.numLocals_0));
    Cursor_0_nifb6mq6y1* X60Qx_1201 = getQ_7_Iyegbq3_comaa5xpt1(argCursors_2, 1);
    Cursor_0_nifb6mq6y1 hiC_0 = eQdup_0_nifb6mq6y1((*X60Qx_1201));
    compileExpr_1_comaa5xpt1(c_83, ctx_55, (&hiC_0));
    NI32 X60Qx_1202 = emit_0_comaa5xpt1(ctx_55, 6, topSlot_0, 0);
    NI32 startIp_1 = len_3_Icgec691_comaa5xpt1((*ctx_55).d_00.code_0);
    NI32 X60Qx_1203 = emit_0_comaa5xpt1(ctx_55, 5, iSlot_0, 0);
    NI32 X60Qx_1204 = emit_0_comaa5xpt1(ctx_55, 5, topSlot_0, 0);
    NimonyExpr_0_nimry5ra91 X60Qx_10;
    NB8 X60Qx_1205 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
      .bytes_0 = 1009659395u, .more_0 = NIM_NIL}
    );
    if (X60Qx_1205){
      X60Qx_10 = 47;}
    else {
      X60Qx_10 = 46;}
    NimonyExpr_0_nimry5ra91 cmpEk_0 = X60Qx_10;
    NI32 X60Qx_1206 = addMagic_0_comaa5xpt1(c_83, cmpEk_0, 64, NIM_TRUE, NIM_FALSE);
    NI32 X60Qx_1207 = emit_0_comaa5xpt1(ctx_55, 19, X60Qx_1206, 0);
    NI32 jf_7 = emit_0_comaa5xpt1(ctx_55, 25, 0, 0);
    void* X60Qx_1208 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1));
    X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_96 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1208);
    seq_0_Ift2sne_chu5m1rja1 X60Qx_1209 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
    seq_0_Ift2sne_chu5m1rja1 X60Qx_1210 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
    (*X60Qtmp_96) = (X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1){
      .r_00 = 0, .d_00 = (Loop_Obj_0_comaa5xpt1){
        .contTarget_0 = -1, .breaks_0 = X60Qx_1209, .continues_0 = X60Qx_1210, .label_0 = ((NU32)0u)}}
    ;
    add_0_Iuw4xx01_comaa5xpt1((&(*ctx_55).d_00.loops_0), X60Qtmp_96);
    Cursor_0_nifb6mq6y1 bc_1 = bodyCur_2;
    eQwasMoved_0_nifb6mq6y1((&bodyCur_2));
    compileStmt_1_comaa5xpt1(c_83, ctx_55, (&bc_1));
    NI32 incIp_0 = len_3_Icgec691_comaa5xpt1((*ctx_55).d_00.code_0);
    NI32 X60Qx_1211 = emit_0_comaa5xpt1(ctx_55, 5, iSlot_0, 0);
    Value_0_valzr1t4f X60Qtmp_97 = vInt_0_valzr1t4f(((NI64)1), 64);
    NI32 X60Qx_1212 = addConst_0_comaa5xpt1(c_83, (&X60Qtmp_97));
    NI32 X60Qx_1213 = emit_0_comaa5xpt1(ctx_55, 0, X60Qx_1212, 0);
    NI32 X60Qx_1214 = addMagic_0_comaa5xpt1(c_83, 33, 64, NIM_TRUE, NIM_FALSE);
    NI32 X60Qx_1215 = emit_0_comaa5xpt1(ctx_55, 19, X60Qx_1214, 0);
    if (isEnum_0){
      NI32 X60Qx_1216 = emit_0_comaa5xpt1(ctx_55, 23, wrapIdx_0, 0);}
    NI32 X60Qx_1217 = emit_0_comaa5xpt1(ctx_55, 6, iSlot_0, 0);
    NI32 X60Qx_1218 = emit_0_comaa5xpt1(ctx_55, 24, startIp_1, 0);
    NI32 X60Qx_1219 = len_3_Icgec691_comaa5xpt1((*ctx_55).d_00.code_0);
    patch_0_comaa5xpt1(ctx_55, jf_7, X60Qx_1219);
    X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1220 = getQ_7_I6yhgto_comaa5xpt1((*ctx_55).d_00.loops_0, ((NI32)((*ctx_55).d_00.loops_0.len_0 - ((NI32)((NI32)1)))));
    X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* lp_4 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_1220));
    {
      openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_20 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_4).d_00.continues_0);
      NI32 X60Qlf_21 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1221 = len_6_I9632ti1_comaa5xpt1(X60Qlf_20);
          if (X60Qlf_21 < X60Qx_1221){
            {
              NI32* X60Qii_6 = getQ_10_I053icq_comaa5xpt1(X60Qlf_20, X60Qlf_21);
              patch_0_comaa5xpt1(ctx_55, (*X60Qii_6), incIp_0);}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_21));}
          else {
            break;}}}
      whileStmtLabel_5: ;}
    forStmtLabel_4: ;
    {
      openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_22 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_4).d_00.breaks_0);
      NI32 X60Qlf_23 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1222 = len_6_I9632ti1_comaa5xpt1(X60Qlf_22);
          if (X60Qlf_23 < X60Qx_1222){
            {
              NI32* X60Qii_9 = getQ_10_I053icq_comaa5xpt1(X60Qlf_22, X60Qlf_23);
              NI32 X60Qx_1223 = len_3_Icgec691_comaa5xpt1((*ctx_55).d_00.code_0);
              patch_0_comaa5xpt1(ctx_55, (*X60Qii_9), X60Qx_1223);}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_23));}
          else {
            break;}}}
      whileStmtLabel_8: ;}
    forStmtLabel_7: ;
    NI32 X60Qx_1224 = len_3_Ij0uoqp_comaa5xpt1((*ctx_55).d_00.loops_0);
    setLen_0_Ivhuv1v1_comaa5xpt1((&(*ctx_55).d_00.loops_0), ((NI32)(X60Qx_1224 - 1)));
    eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(lp_4);
    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_97));
    eQdestroy_0_nifb6mq6y1((&bc_1));
    eQdestroy_0_nifb6mq6y1((&hiC_0));
    eQdestroy_0_nifb6mq6y1((&loC_0));}
  else {
    NB8 X60Qx_1225;
    NB8 X60Qx_1226;
    NB8 X60Qx_1227;
    NB8 X60Qx_1228;
    NB8 X60Qx_1229;
    NB8 X60Qx_1230;
    NB8 X60Qx_1231;
    NB8 X60Qx_1232 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
      .bytes_0 = 1702128126u, .more_0 = (&strlit_0_I1074026605013007683_comaa5xpt1)}
    );
    if (X60Qx_1232){
      X60Qx_1231 = NIM_TRUE;}
    else {
      NB8 X60Qx_1233 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
        .bytes_0 = 1953066494u, .more_0 = (&strlit_0_I749353374909415178_comaa5xpt1)}
      );
      X60Qx_1231 = X60Qx_1233;}
    if (X60Qx_1231){
      X60Qx_1230 = NIM_TRUE;}
    else {
      NB8 X60Qx_1234 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
        .bytes_0 = 1767993598u, .more_0 = (&strlit_0_I10146300619167329886_comaa5xpt1)}
      );
      X60Qx_1230 = X60Qx_1234;}
    if (X60Qx_1230){
      X60Qx_1229 = NIM_TRUE;}
    else {
      NB8 X60Qx_1235 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
        .bytes_0 = 1634758142u, .more_0 = (&strlit_0_I16434641538762240521_comaa5xpt1)}
      );
      X60Qx_1229 = X60Qx_1235;}
    if (X60Qx_1229){
      X60Qx_1228 = (1 <= argCursors_2.len_0);}
    else {
      X60Qx_1228 = NIM_FALSE;}
    if (X60Qx_1228){
      X60Qx_1227 = (1 <= loopSlots_2.len_0);}
    else {
      X60Qx_1227 = NIM_FALSE;}
    if (X60Qx_1227){
      NB8 X60Qx_1236 = firstParamContainer_1_comaa5xpt1(iterSym_2);
      X60Qx_1226 = X60Qx_1236;}
    else {
      X60Qx_1226 = NIM_FALSE;}
    if (X60Qx_1226){
      NB8 X60Qx_1237;
      NI32 X60Qx_1238 = symIndex_0_comaa5xpt1((*c_83).d_00.procDefSyms_0, iterSym_2);
      if (0 <= X60Qx_1238){
        NI32 X60Qx_1239 = symIndex_0_comaa5xpt1((*c_83).d_00.procDefSyms_0, iterSym_2);
        Cursor_0_nifb6mq6y1* X60Qx_1240 = getQ_7_Iyegbq3_comaa5xpt1((*c_83).d_00.procDefCursors_0, X60Qx_1239);
        NB8 X60Qx_1241 = routineHasClosureOrPassive_0_comaa5xpt1((*X60Qx_1240));
        X60Qx_1237 = X60Qx_1241;}
      else {
        X60Qx_1237 = NIM_FALSE;}
      X60Qx_1225 = (!X60Qx_1237);}
    else {
      X60Qx_1225 = NIM_FALSE;}
    if (X60Qx_1225){
      NB8 X60Qx_1242;
      NB8 X60Qx_1243 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
        .bytes_0 = 1767993598u, .more_0 = (&strlit_0_I10146300619167329886_comaa5xpt1)}
      );
      if (X60Qx_1243){
        X60Qx_1242 = NIM_TRUE;}
      else {
        NB8 X60Qx_1244 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
          .bytes_0 = 1634758142u, .more_0 = (&strlit_0_I16434641538762240521_comaa5xpt1)}
        );
        X60Qx_1242 = X60Qx_1244;}
      NB8 withIndex_0 = X60Qx_1242;
      NI32 X60Qx_11;
      if (withIndex_0){
        NI32* X60Qx_1245 = getQ_7_Ir8kccm_comaa5xpt1(loopSlots_2, 0);
        X60Qx_11 = (*X60Qx_1245);}
      else {
        X60Qx_11 = -1;}
      NI32 idxVarSlot_0 = X60Qx_11;
      NI32 X60Qx_12;
      if (withIndex_0){
        NI32 X60Qx_13;
        if (2 <= loopSlots_2.len_0){
          NI32* X60Qx_1246 = getQ_7_Ir8kccm_comaa5xpt1(loopSlots_2, 1);
          X60Qx_13 = (*X60Qx_1246);}
        else {
          NI32* X60Qx_1247 = getQ_7_Ir8kccm_comaa5xpt1(loopSlots_2, 0);
          X60Qx_13 = (*X60Qx_1247);}
        X60Qx_12 = X60Qx_13;}
      else {
        NI32* X60Qx_1248 = getQ_7_Ir8kccm_comaa5xpt1(loopSlots_2, 0);
        X60Qx_12 = (*X60Qx_1248);}
      NI32 elemSlot_0 = X60Qx_12;
      NI32 contSlot_0 = (*ctx_55).d_00.numLocals_0;
      inc_1_I6wjjge_aow2h993l1((&(*ctx_55).d_00.numLocals_0));
      Cursor_0_nifb6mq6y1* X60Qx_1249 = getQ_7_Iyegbq3_comaa5xpt1(argCursors_2, 0);
      Cursor_0_nifb6mq6y1 contC_0 = eQdup_0_nifb6mq6y1((*X60Qx_1249));
      compileExpr_1_comaa5xpt1(c_83, ctx_55, (&contC_0));
      NI32 X60Qx_1250 = emit_0_comaa5xpt1(ctx_55, 6, contSlot_0, 0);
      NI32 idxSlot_0 = (*ctx_55).d_00.numLocals_0;
      inc_1_I6wjjge_aow2h993l1((&(*ctx_55).d_00.numLocals_0));
      Value_0_valzr1t4f X60Qtmp_98 = vInt_0_valzr1t4f(((NI64)0), 64);
      NI32 X60Qx_1251 = addConst_0_comaa5xpt1(c_83, (&X60Qtmp_98));
      NI32 X60Qx_1252 = emit_0_comaa5xpt1(ctx_55, 0, X60Qx_1251, 0);
      NI32 X60Qx_1253 = emit_0_comaa5xpt1(ctx_55, 6, idxSlot_0, 0);
      NI32 startIp_2 = len_3_Icgec691_comaa5xpt1((*ctx_55).d_00.code_0);
      NI32 X60Qx_1254 = emit_0_comaa5xpt1(ctx_55, 5, idxSlot_0, 0);
      NI32 X60Qx_1255 = emit_0_comaa5xpt1(ctx_55, 5, contSlot_0, 0);
      NI32 X60Qx_1256 = addNative_0_comaa5xpt1(c_83, (string_0_sysvq0asl){
        .bytes_0 = 1852140547u, .more_0 = NIM_NIL}
      );
      NI32 X60Qx_1257 = emit_0_comaa5xpt1(ctx_55, 34, X60Qx_1256, 1);
      NI32 X60Qx_1258 = addMagic_0_comaa5xpt1(c_83, 47, 64, NIM_TRUE, NIM_FALSE);
      NI32 X60Qx_1259 = emit_0_comaa5xpt1(ctx_55, 19, X60Qx_1258, 0);
      NI32 jf_8 = emit_0_comaa5xpt1(ctx_55, 25, 0, 0);
      void* X60Qx_1260 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1));
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_99 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1260);
      seq_0_Ift2sne_chu5m1rja1 X60Qx_1261 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
      seq_0_Ift2sne_chu5m1rja1 X60Qx_1262 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
      (*X60Qtmp_99) = (X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1){
        .r_00 = 0, .d_00 = (Loop_Obj_0_comaa5xpt1){
          .contTarget_0 = -1, .breaks_0 = X60Qx_1261, .continues_0 = X60Qx_1262, .label_0 = ((NU32)0u)}}
      ;
      add_0_Iuw4xx01_comaa5xpt1((&(*ctx_55).d_00.loops_0), X60Qtmp_99);
      if (withIndex_0){
        NI32 X60Qx_1263 = emit_0_comaa5xpt1(ctx_55, 5, idxSlot_0, 0);
        NI32 X60Qx_1264 = emit_0_comaa5xpt1(ctx_55, 6, idxVarSlot_0, 0);}
      seq_0_Ift2sne_chu5m1rja1 X60Qx_14;
      eQwasMoved_1_Ix88qzs1_chu5m1rja1((&X60Qx_14));
      if (withIndex_0){
        seq_0_Ift2sne_chu5m1rja1 X60Qx_15;
        eQwasMoved_1_Ix88qzs1_chu5m1rja1((&X60Qx_15));
        if (2 <= loopSlots_2.len_0){
          eQdestroy_1_Iv9ij5i1_chu5m1rja1(X60Qx_15);
          HSlice_0_I8tnmvh1_comaa5xpt1 X60Qx_1265 = ___1_Ico26mb_comaa5xpt1(1, ((NI32)1));
          seq_0_Ift2sne_chu5m1rja1 X60Qx_1266 = getQ_17_I2og8ah1_comaa5xpt1(loopSlots_2, X60Qx_1265);
          X60Qx_15 = X60Qx_1266;}
        else {
          eQdestroy_1_Iv9ij5i1_chu5m1rja1(X60Qx_15);
          seq_0_Ift2sne_chu5m1rja1 X60Qx_1267 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
          X60Qx_15 = X60Qx_1267;}
        eQdestroy_1_Iv9ij5i1_chu5m1rja1(X60Qx_14);
        X60Qx_14 = X60Qx_15;
        eQwasMoved_1_Ix88qzs1_chu5m1rja1((&X60Qx_15));
        eQdestroy_1_Iv9ij5i1_chu5m1rja1(X60Qx_15);}
      else {
        eQdestroy_1_Iv9ij5i1_chu5m1rja1(X60Qx_14);
        X60Qx_14 = loopSlots_2;
        eQwasMoved_1_Ix88qzs1_chu5m1rja1((&loopSlots_2));}
      seq_0_Ift2sne_chu5m1rja1 elemSlots_0 = X60Qx_14;
      eQwasMoved_1_Ix88qzs1_chu5m1rja1((&X60Qx_14));
      NB8 X60Qx_1268;
      NB8 X60Qx_1269 = binderSingleScalar_0_comaa5xpt1(binderCur_2);
      if (X60Qx_1269){
        X60Qx_1268 = NIM_TRUE;}
      else {
        NI32 X60Qx_1270 = len_3_I0v1j8d_comaa5xpt1(elemSlots_0);
        X60Qx_1268 = (X60Qx_1270 <= 1);}
      if (X60Qx_1268){
        NI32 X60Qx_1271 = emit_0_comaa5xpt1(ctx_55, 5, contSlot_0, 0);
        NI32 X60Qx_1272 = emit_0_comaa5xpt1(ctx_55, 5, idxSlot_0, 0);
        NI32 X60Qx_1273 = emit_0_comaa5xpt1(ctx_55, 49, 0, 0);
        NI32 X60Qx_1274 = emit_0_comaa5xpt1(ctx_55, 6, elemSlot_0, 0);}
      else {
        NB8 X60Qx_1275;
        NB8 X60Qx_1276 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
          .bytes_0 = 1634758142u, .more_0 = (&strlit_0_I16434641538762240521_comaa5xpt1)}
        );
        if (X60Qx_1276){
          X60Qx_1275 = NIM_TRUE;}
        else {
          NB8 X60Qx_1277 = eqQ_20_sysvq0asl(base_4, (string_0_sysvq0asl){
            .bytes_0 = 1953066494u, .more_0 = (&strlit_0_I749353374909415178_comaa5xpt1)}
          );
          X60Qx_1275 = X60Qx_1277;}
        NB8 mutTuple_0 = X60Qx_1275;
        NI32 elemTmp_0 = (*ctx_55).d_00.numLocals_0;
        inc_1_I6wjjge_aow2h993l1((&(*ctx_55).d_00.numLocals_0));
        NI32 X60Qx_1278 = emit_0_comaa5xpt1(ctx_55, 5, contSlot_0, 0);
        NI32 X60Qx_1279 = emit_0_comaa5xpt1(ctx_55, 5, idxSlot_0, 0);
        if (mutTuple_0){
          NI32 X60Qx_1280 = emit_0_comaa5xpt1(ctx_55, 49, 0, 0);}
        else {
          NI32 X60Qx_1281 = emit_0_comaa5xpt1(ctx_55, 48, 0, 0);}
        NI32 X60Qx_1282 = emit_0_comaa5xpt1(ctx_55, 6, elemTmp_0, 0);
        NI32 k_4 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1283 = len_3_I0v1j8d_comaa5xpt1(elemSlots_0);
            if (k_4 < X60Qx_1283){
              NI32 X60Qx_1284 = emit_0_comaa5xpt1(ctx_55, 5, elemTmp_0, 0);
              Value_0_valzr1t4f X60Qtmp_100 = vInt_0_valzr1t4f(((NI64)k_4), 64);
              NI32 X60Qx_1285 = addConst_0_comaa5xpt1(c_83, (&X60Qtmp_100));
              NI32 X60Qx_1286 = emit_0_comaa5xpt1(ctx_55, 0, X60Qx_1285, 0);
              if (mutTuple_0){
                NI32 X60Qx_1287 = emit_0_comaa5xpt1(ctx_55, 44, 0, 0);}
              else {
                NI32 X60Qx_1288 = emit_0_comaa5xpt1(ctx_55, 43, 0, 0);}
              NI32* X60Qx_1289 = getQ_7_Ir8kccm_comaa5xpt1(elemSlots_0, k_4);
              NI32 X60Qx_1290 = emit_0_comaa5xpt1(ctx_55, 6, (*X60Qx_1289), 0);
              inc_1_I6wjjge_aow2h993l1((&k_4));
              eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_100));}
            else {
              break;}}}
        whileStmtLabel_10: ;}
      Cursor_0_nifb6mq6y1 bc_2 = bodyCur_2;
      eQwasMoved_0_nifb6mq6y1((&bodyCur_2));
      compileStmt_1_comaa5xpt1(c_83, ctx_55, (&bc_2));
      NI32 incIp_1 = len_3_Icgec691_comaa5xpt1((*ctx_55).d_00.code_0);
      NI32 X60Qx_1291 = emit_0_comaa5xpt1(ctx_55, 5, idxSlot_0, 0);
      Value_0_valzr1t4f X60Qtmp_101 = vInt_0_valzr1t4f(((NI64)1), 64);
      NI32 X60Qx_1292 = addConst_0_comaa5xpt1(c_83, (&X60Qtmp_101));
      NI32 X60Qx_1293 = emit_0_comaa5xpt1(ctx_55, 0, X60Qx_1292, 0);
      NI32 X60Qx_1294 = addMagic_0_comaa5xpt1(c_83, 33, 64, NIM_TRUE, NIM_FALSE);
      NI32 X60Qx_1295 = emit_0_comaa5xpt1(ctx_55, 19, X60Qx_1294, 0);
      NI32 X60Qx_1296 = emit_0_comaa5xpt1(ctx_55, 6, idxSlot_0, 0);
      NI32 X60Qx_1297 = emit_0_comaa5xpt1(ctx_55, 24, startIp_2, 0);
      NI32 X60Qx_1298 = len_3_Icgec691_comaa5xpt1((*ctx_55).d_00.code_0);
      patch_0_comaa5xpt1(ctx_55, jf_8, X60Qx_1298);
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1299 = getQ_7_I6yhgto_comaa5xpt1((*ctx_55).d_00.loops_0, ((NI32)((*ctx_55).d_00.loops_0.len_0 - ((NI32)((NI32)1)))));
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* lp_5 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_1299));
      {
        openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_24 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_5).d_00.continues_0);
        NI32 X60Qlf_25 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1300 = len_6_I9632ti1_comaa5xpt1(X60Qlf_24);
            if (X60Qlf_25 < X60Qx_1300){
              {
                NI32* X60Qii_13 = getQ_10_I053icq_comaa5xpt1(X60Qlf_24, X60Qlf_25);
                patch_0_comaa5xpt1(ctx_55, (*X60Qii_13), incIp_1);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_25));}
            else {
              break;}}}
        whileStmtLabel_12: ;}
      forStmtLabel_11: ;
      {
        openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_26 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*lp_5).d_00.breaks_0);
        NI32 X60Qlf_27 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1301 = len_6_I9632ti1_comaa5xpt1(X60Qlf_26);
            if (X60Qlf_27 < X60Qx_1301){
              {
                NI32* X60Qii_16 = getQ_10_I053icq_comaa5xpt1(X60Qlf_26, X60Qlf_27);
                NI32 X60Qx_1302 = len_3_Icgec691_comaa5xpt1((*ctx_55).d_00.code_0);
                patch_0_comaa5xpt1(ctx_55, (*X60Qii_16), X60Qx_1302);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_27));}
            else {
              break;}}}
        whileStmtLabel_15: ;}
      forStmtLabel_14: ;
      NI32 X60Qx_1303 = len_3_Ij0uoqp_comaa5xpt1((*ctx_55).d_00.loops_0);
      setLen_0_Ivhuv1v1_comaa5xpt1((&(*ctx_55).d_00.loops_0), ((NI32)(X60Qx_1303 - 1)));
      eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(lp_5);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_101));
      eQdestroy_0_nifb6mq6y1((&bc_2));
      eQdestroy_1_Iv9ij5i1_chu5m1rja1(elemSlots_0);
      eQdestroy_1_Iv9ij5i1_chu5m1rja1(X60Qx_14);
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_98));
      eQdestroy_0_nifb6mq6y1((&contC_0));}
    else {
      Cursor_0_nifb6mq6y1 iterCur_1 = (Cursor_0_nifb6mq6y1){
        .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
      ;
      NB8 haveIter_0 = NIM_FALSE;
      NI32 di_1 = symIndex_0_comaa5xpt1((*c_83).d_00.procDefSyms_0, iterSym_2);
      if (0 <= di_1){
        eQdestroy_0_nifb6mq6y1((&iterCur_1));
        Cursor_0_nifb6mq6y1* X60Qx_1304 = getQ_7_Iyegbq3_comaa5xpt1((*c_83).d_00.procDefCursors_0, di_1);
        Cursor_0_nifb6mq6y1 X60Qx_1305 = eQdup_0_nifb6mq6y1((*X60Qx_1304));
        iterCur_1 = X60Qx_1305;
        haveIter_0 = NIM_TRUE;}
      else {
        LoadResult_0_prorcx25w1 res_9 = tryLoadSymSafe_0_modzy18mg1(iterSym_2);
        NB8 X60Qx_1306;
        NB8 X60Qx_1307;
        if (res_9.status_0 == 3){
          NifKind_0_nif81dubp1 X60Qx_1308 = kind_0_nifb6mq6y1(res_9.decl_0);
          X60Qx_1307 = (X60Qx_1308 == 11);}
        else {
          X60Qx_1307 = NIM_FALSE;}
        if (X60Qx_1307){
          NimonySym_0_nimry5ra91 X60Qx_1309 = symKind_0_nim30udrv(res_9.decl_0);
          NB8 X60Qx_1310 = isRoutine_0_decqocs071(X60Qx_1309);
          X60Qx_1306 = X60Qx_1310;}
        else {
          X60Qx_1306 = NIM_FALSE;}
        if (X60Qx_1306){
          Routine_0_decqocs071 rr_0 = asRoutine_0_decqocs071(res_9.decl_0, 1);
          NifKind_0_nif81dubp1 X60Qx_1311 = kind_0_nifb6mq6y1(rr_0.body_0);
          if ((!(X60Qx_1311 == 2))){
            eQdestroy_0_nifb6mq6y1((&iterCur_1));
            iterCur_1 = res_9.decl_0;
            eQwasMoved_0_nifb6mq6y1((&res_9.decl_0));
            haveIter_0 = NIM_TRUE;}
          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&rr_0));}
        eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_9);}
      NB8 X60Qx_1312;
      NB8 X60Qx_1313;
      NB8 X60Qx_1314;
      if (haveIter_0){
        X60Qx_1314 = (1 <= loopSlots_2.len_0);}
      else {
        X60Qx_1314 = NIM_FALSE;}
      if (X60Qx_1314){
        X60Qx_1313 = (*c_83).d_00.usesScheduler_0;}
      else {
        X60Qx_1313 = NIM_FALSE;}
      if (X60Qx_1313){
        NB8 X60Qx_1315 = routineIsClosureIter_0_comaa5xpt1(iterCur_1);
        X60Qx_1312 = X60Qx_1315;}
      else {
        X60Qx_1312 = NIM_FALSE;}
      if (X60Qx_1312){
        compileCoroFor_1_comaa5xpt1(c_83, ctx_55, iterSym_2, argCursors_2, loopSlots_2, loopPlan_2, binderCur_2, bodyCur_2);}
      else {
        NB8 X60Qx_1316;
        if (haveIter_0){
          X60Qx_1316 = (1 <= loopSlots_2.len_0);}
        else {
          X60Qx_1316 = NIM_FALSE;}
        if (X60Qx_1316){
          Routine_0_decqocs071 r_6 = asRoutine_0_decqocs071(iterCur_1, 1);
          SymMap_0_comaa5xpt1 savedSmap_0 = eQdupQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1((*ctx_55).d_00.smap_0);
          Cursor_0_nifb6mq6y1 p_6 = r_6.params_0;
          eQwasMoved_0_nifb6mq6y1((&r_6.params_0));
          NI32 ai_1 = 0;
          NifKind_0_nif81dubp1 X60Qx_1317 = kind_0_nifb6mq6y1(p_6);
          if (X60Qx_1317 == 11){
            inc_0_nifb6mq6y1((&p_6));
            {
              while (NIM_TRUE){
                NifKind_0_nif81dubp1 X60Qx_1318 = kind_0_nifb6mq6y1(p_6);
                if ((!(X60Qx_1318 == 12))){
                  string_0_sysvq0asl X60Qtmp_102 = nodeTag_0_comaa5xpt1(p_6);
                  NB8 X60Qx_1319 = eqQ_20_sysvq0asl(X60Qtmp_102, (string_0_sysvq0asl){
                    .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I9792473688321036479_comaa5xpt1)}
                  );
                  if (X60Qx_1319){
                    Local_0_decqocs071 loc_5 = asLocal_0_decqocs071(p_6, 1);
                    NifKind_0_nif81dubp1 X60Qx_1320 = kind_0_nifb6mq6y1(loc_5.name_0);
                    if (X60Qx_1320 == 5){
                      NI32 slot_7 = (*ctx_55).d_00.numLocals_0;
                      inc_1_I6wjjge_aow2h993l1((&(*ctx_55).d_00.numLocals_0));
                      NI32 X60Qx_1321 = len_3_Ilsmz1h_comaa5xpt1(argCursors_2);
                      if (ai_1 < X60Qx_1321){
                        Cursor_0_nifb6mq6y1* X60Qx_1322 = getQ_7_Iyegbq3_comaa5xpt1(argCursors_2, ai_1);
                        Cursor_0_nifb6mq6y1 ac_2 = eQdup_0_nifb6mq6y1((*X60Qx_1322));
                        compileExpr_1_comaa5xpt1(c_83, ctx_55, (&ac_2));
                        eQdestroy_0_nifb6mq6y1((&ac_2));}
                      else {
                        NI32 X60Qx_1323 = emit_0_comaa5xpt1(ctx_55, 1, 0, 0);}
                      NI32 X60Qx_1324 = emit_0_comaa5xpt1(ctx_55, 6, slot_7, 0);
                      NU32 X60Qx_1325 = symId_0_nifb6mq6y1(loc_5.name_0);
                      put_0_comaa5xpt1((&(*ctx_55).d_00.smap_0), X60Qx_1325, slot_7);
                      inc_1_I6wjjge_aow2h993l1((&ai_1));}
                    eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_5));}
                  skip_0_nifb6mq6y1((&p_6));
                  nimStrDestroy(X60Qtmp_102);}
                else {
                  break;}}}
            whileStmtLabel_17: ;}
          NI32 tmpSlot_2 = (*ctx_55).d_00.numLocals_0;
          inc_1_I6wjjge_aow2h993l1((&(*ctx_55).d_00.numLocals_0));
          NI32 nestTmpSlot_2 = (*ctx_55).d_00.numLocals_0;
          inc_1_I6wjjge_aow2h993l1((&(*ctx_55).d_00.numLocals_0));
          NI32 consumerIdx_0 = len_3_Ij0uoqp_comaa5xpt1((*ctx_55).d_00.loops_0);
          void* X60Qx_1326 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1));
          X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_103 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1326);
          seq_0_Ift2sne_chu5m1rja1 X60Qx_1327 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
          seq_0_Ift2sne_chu5m1rja1 X60Qx_1328 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
          (*X60Qtmp_103) = (X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1){
            .r_00 = 0, .d_00 = (Loop_Obj_0_comaa5xpt1){
              .contTarget_0 = -1, .breaks_0 = X60Qx_1327, .continues_0 = X60Qx_1328, .label_0 = ((NU32)0u)}}
          ;
          add_0_Iuw4xx01_comaa5xpt1((&(*ctx_55).d_00.loops_0), X60Qtmp_103);
          void* X60Qx_1329 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1));
          X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_104 = ((X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1329);
          seq_0_Ift2sne_chu5m1rja1 X60Qtmp_105 = loopSlots_2;
          eQwasMoved_1_Ix88qzs1_chu5m1rja1((&loopSlots_2));
          seq_0_Ik7wkpe_comaa5xpt1 X60Qtmp_106 = loopPlan_2;
          eQwasMoved_1_I1l3xdo1_comaa5xpt1((&loopPlan_2));
          Cursor_0_nifb6mq6y1 X60Qtmp_107 = bodyCur_2;
          eQwasMoved_0_nifb6mq6y1((&bodyCur_2));
          (*X60Qtmp_104) = (X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1){
            .r_00 = 0, .d_00 = (YieldFrame_Obj_0_comaa5xpt1){
              .loopSlots_0 = X60Qtmp_105, .unpackPlan_0 = X60Qtmp_106, .tmpSlot_0 = tmpSlot_2, .nestTmpSlot_0 = nestTmpSlot_2, .bodyCur_0 = X60Qtmp_107, .consumerIdx_0 = consumerIdx_0}}
          ;
          add_0_Iype0e61_comaa5xpt1((&(*ctx_55).d_00.yields_0), X60Qtmp_104);
          Cursor_0_nifb6mq6y1 ibody_0 = r_6.body_0;
          eQwasMoved_0_nifb6mq6y1((&r_6.body_0));
          compileStmt_1_comaa5xpt1(c_83, ctx_55, (&ibody_0));
          NI32 X60Qx_1330 = len_3_I7uqqfu1_comaa5xpt1((*ctx_55).d_00.yields_0);
          setLen_0_I93919j1_comaa5xpt1((&(*ctx_55).d_00.yields_0), ((NI32)(X60Qx_1330 - 1)));
          X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1331 = getQ_7_I6yhgto_comaa5xpt1((*ctx_55).d_00.loops_0, consumerIdx_0);
          X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* consumer_0 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_1331));
          {
            openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_28 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*consumer_0).d_00.breaks_0);
            NI32 X60Qlf_29 = 0;
            {
              while (NIM_TRUE){
                NI32 X60Qx_1332 = len_6_I9632ti1_comaa5xpt1(X60Qlf_28);
                if (X60Qlf_29 < X60Qx_1332){
                  {
                    NI32* X60Qii_20 = getQ_10_I053icq_comaa5xpt1(X60Qlf_28, X60Qlf_29);
                    NI32 X60Qx_1333 = len_3_Icgec691_comaa5xpt1((*ctx_55).d_00.code_0);
                    patch_0_comaa5xpt1(ctx_55, (*X60Qii_20), X60Qx_1333);}
                  inc_1_I6wjjge_aow2h993l1((&X60Qlf_29));}
                else {
                  break;}}}
            whileStmtLabel_19: ;}
          forStmtLabel_18: ;
          setLen_0_Ivhuv1v1_comaa5xpt1((&(*ctx_55).d_00.loops_0), consumerIdx_0);
          SymMap_0_comaa5xpt1* X60Qlhs_108 = (&(*ctx_55).d_00.smap_0);
          SymMap_0_comaa5xpt1 X60Qlhs_109 = savedSmap_0;
          eQwasmovedQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1((&savedSmap_0));
          eQdestroyQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1((*X60Qlhs_108));
          (*X60Qlhs_108) = X60Qlhs_109;
          eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(consumer_0);
          eQdestroy_0_nifb6mq6y1((&ibody_0));
          eQdestroy_0_nifb6mq6y1((&p_6));
          eQdestroyQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1(savedSmap_0);
          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_6));}
        else {
          NB8 X60Qx_1334;
          if (1 <= loopSlots_2.len_0){
            NB8 X60Qx_1335;
            NI32 X60Qx_1336 = get_0_comaa5xpt1((*ctx_55).d_00.smap_0, iterSym_2);
            if (0 <= X60Qx_1336){
              X60Qx_1335 = NIM_TRUE;}
            else {
              NI32 X60Qx_1337 = get_0_comaa5xpt1((*c_83).d_00.gmap_0, iterSym_2);
              X60Qx_1335 = (0 <= X60Qx_1337);}
            X60Qx_1334 = X60Qx_1335;}
          else {
            X60Qx_1334 = NIM_FALSE;}
          if (X60Qx_1334){
            compileCoroFor_1_comaa5xpt1(c_83, ctx_55, iterSym_2, argCursors_2, loopSlots_2, loopPlan_2, binderCur_2, bodyCur_2);}}}
      eQdestroy_0_nifb6mq6y1((&iterCur_1));}}
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(loopSlots_2);
  eQdestroy_1_Ij4pznj1_comaa5xpt1(loopPlan_2);
  nimStrDestroy(base_4);
  eQdestroy_1_Ir7cqbo_comaa5xpt1(argCursors_2);
  eQdestroy_0_nifb6mq6y1((&it_0));
  eQdestroy_0_nifb6mq6y1((&bodyCur_2));
  eQdestroy_0_nifb6mq6y1((&binderCur_2));
  eQdestroy_0_nifb6mq6y1((&iterCur_0));}
void compileCase_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_84, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_56, Cursor_0_nifb6mq6y1* n_47){
  inc_0_nifb6mq6y1(n_47);
  NI32 selSlot_3 = (*ctx_56).d_00.numLocals_0;
  inc_1_I6wjjge_aow2h993l1((&(*ctx_56).d_00.numLocals_0));
  compileExpr_1_comaa5xpt1(c_84, ctx_56, n_47);
  NI32 X60Qx_1338 = emit_0_comaa5xpt1(ctx_56, 6, selSlot_3, 0);
  seq_0_Ift2sne_chu5m1rja1 endPatches_3 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1339 = kind_0_nifb6mq6y1((*n_47));
      if ((!(X60Qx_1339 == 12))){
        string_0_sysvq0asl btag_3 = nodeTag_0_comaa5xpt1((*n_47));
        NB8 X60Qx_1340 = eqQ_20_sysvq0asl(btag_3, (string_0_sysvq0asl){
          .bytes_0 = 6713090u, .more_0 = NIM_NIL}
        );
        if (X60Qx_1340){
          inc_0_nifb6mq6y1(n_47);
          Cursor_0_nifb6mq6y1 rangesCur_2 = eQdup_0_nifb6mq6y1((*n_47));
          skip_0_nifb6mq6y1(n_47);
          compileCaseCond_0_comaa5xpt1(c_84, ctx_56, rangesCur_2, selSlot_3);
          NI32 jf_9 = emit_0_comaa5xpt1(ctx_56, 25, 0, 0);
          compileStmt_1_comaa5xpt1(c_84, ctx_56, n_47);
          NI32 X60Qx_1341 = emit_0_comaa5xpt1(ctx_56, 24, 0, 0);
          add_0_I8kd4i4_comaa5xpt1((&endPatches_3), X60Qx_1341);
          NI32 X60Qx_1342 = len_3_Icgec691_comaa5xpt1((*ctx_56).d_00.code_0);
          patch_0_comaa5xpt1(ctx_56, jf_9, X60Qx_1342);
          consumeParRi_0_nifb6mq6y1(n_47);
          eQdestroy_0_nifb6mq6y1((&rangesCur_2));}
        else {
          NB8 X60Qx_1343 = eqQ_20_sysvq0asl(btag_3, (string_0_sysvq0asl){
            .bytes_0 = 1936483838u, .more_0 = (&strlit_0_I4167480082662538754_comaa5xpt1)}
          );
          if (X60Qx_1343){
            inc_0_nifb6mq6y1(n_47);
            compileStmt_1_comaa5xpt1(c_84, ctx_56, n_47);
            consumeParRi_0_nifb6mq6y1(n_47);}
          else {
            skip_0_nifb6mq6y1(n_47);}}
        nimStrDestroy(btag_3);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_47);
  {
    openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_30 = toOpenArray_1_Ibqb4ob_comaa5xpt1(endPatches_3);
    NI32 X60Qlf_31 = 0;
    {
      while (NIM_TRUE){
        NI32 X60Qx_1344 = len_6_I9632ti1_comaa5xpt1(X60Qlf_30);
        if (X60Qlf_31 < X60Qx_1344){
          {
            NI32* X60Qii_3 = getQ_10_I053icq_comaa5xpt1(X60Qlf_30, X60Qlf_31);
            NI32 X60Qx_1345 = len_3_Icgec691_comaa5xpt1((*ctx_56).d_00.code_0);
            patch_0_comaa5xpt1(ctx_56, (*X60Qii_3), X60Qx_1345);}
          inc_1_I6wjjge_aow2h993l1((&X60Qlf_31));}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  forStmtLabel_1: ;
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(endPatches_3);}
void compileRet_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_85, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_57, Cursor_0_nifb6mq6y1* n_48){
  inc_0_nifb6mq6y1(n_48);
  NifKind_0_nif81dubp1 X60Qx_1346 = kind_0_nifb6mq6y1((*n_48));
  if (X60Qx_1346 == 12){
    if (0 <= (*ctx_57).d_00.resultSlot_0){
      NI32 X60Qx_1347 = emit_0_comaa5xpt1(ctx_57, 5, (*ctx_57).d_00.resultSlot_0, 0);}
    else {
      NI32 X60Qx_1348 = emit_0_comaa5xpt1(ctx_57, 1, 0, 0);}}
  else {
    NifKind_0_nif81dubp1 X60Qx_1349 = kind_0_nifb6mq6y1((*n_48));
    if (X60Qx_1349 == 2){
      inc_0_nifb6mq6y1(n_48);
      if (0 <= (*ctx_57).d_00.resultSlot_0){
        NI32 X60Qx_1350 = emit_0_comaa5xpt1(ctx_57, 5, (*ctx_57).d_00.resultSlot_0, 0);}
      else {
        NI32 X60Qx_1351 = emit_0_comaa5xpt1(ctx_57, 1, 0, 0);}}
    else {
      compileExpr_1_comaa5xpt1(c_85, ctx_57, n_48);}}
  consumeParRi_0_nifb6mq6y1(n_48);
  NI32 X60Qx_1352 = emit_0_comaa5xpt1(ctx_57, 36, 0, 0);}
void emitFinallyBody_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_86, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_58, Cursor_0_nifb6mq6y1 finCur_0){
  Cursor_0_nifb6mq6y1 fc_0 = eQdup_0_nifb6mq6y1(finCur_0);
  inc_0_nifb6mq6y1((&fc_0));
  compileStmt_1_comaa5xpt1(c_86, ctx_58, (&fc_0));
  eQdestroy_0_nifb6mq6y1((&fc_0));}
void emitFinallyGuarded_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_87, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_59, Cursor_0_nifb6mq6y1 finCur_1){
  NI32 sk_0 = emit_0_comaa5xpt1(ctx_59, 71, 0, 0);
  emitFinallyBody_0_comaa5xpt1(c_87, ctx_59, finCur_1);
  NI32 X60Qx_1353 = len_3_Icgec691_comaa5xpt1((*ctx_59).d_00.code_0);
  patch_0_comaa5xpt1(ctx_59, sk_0, X60Qx_1353);}
void emitExceptDispatch_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_88, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_60, Cursor_0_nifb6mq6y1 exceptCur_0){
  Cursor_0_nifb6mq6y1 ec_0 = eQdup_0_nifb6mq6y1(exceptCur_0);
  inc_0_nifb6mq6y1((&ec_0));
  NifKind_0_nif81dubp1 X60Qx_1354 = kind_0_nifb6mq6y1(ec_0);
  if (X60Qx_1354 == 2){
    inc_0_nifb6mq6y1((&ec_0));}
  else {
    NB8 X60Qx_98;
    NifKind_0_nif81dubp1 X60Qx_1355 = kind_0_nifb6mq6y1(ec_0);
    if (X60Qx_1355 == 11){
      NB8 X60Qx_99;
      NB8 X60Qx_100;
      string_0_sysvq0asl X60Qtmp_110 = nodeTag_0_comaa5xpt1(ec_0);
      NB8 X60Qx_1356 = eqQ_20_sysvq0asl(X60Qtmp_110, (string_0_sysvq0asl){
        .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
      );
      if (X60Qx_1356){
        X60Qx_100 = NIM_TRUE;}
      else {
        string_0_sysvq0asl X60Qtmp_111 = nodeTag_0_comaa5xpt1(ec_0);
        NB8 X60Qx_1357 = eqQ_20_sysvq0asl(X60Qtmp_111, (string_0_sysvq0asl){
          .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I17735862253056247523_comaa5xpt1)}
        );
        X60Qx_100 = X60Qx_1357;
        nimStrDestroy(X60Qtmp_111);}
      if (X60Qx_100){
        X60Qx_99 = NIM_TRUE;}
      else {
        string_0_sysvq0asl X60Qtmp_112 = nodeTag_0_comaa5xpt1(ec_0);
        NB8 X60Qx_1358 = eqQ_20_sysvq0asl(X60Qtmp_112, (string_0_sysvq0asl){
          .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
        );
        X60Qx_99 = X60Qx_1358;
        nimStrDestroy(X60Qtmp_112);}
      X60Qx_98 = X60Qx_99;
      nimStrDestroy(X60Qtmp_110);}
    else {
      X60Qx_98 = NIM_FALSE;}
    if (X60Qx_98){
      Cursor_0_nifb6mq6y1 lc_5 = eQdup_0_nifb6mq6y1(ec_0);
      inc_0_nifb6mq6y1((&lc_5));
      NU32 esym_1 = ((NU32)0u);
      NifKind_0_nif81dubp1 X60Qx_1359 = kind_0_nifb6mq6y1(lc_5);
      if (X60Qx_1359 == 5){
        NU32 X60Qx_1360 = symId_0_nifb6mq6y1(lc_5);
        esym_1 = X60Qx_1360;}
      NI32 slot_8 = (*ctx_60).d_00.numLocals_0;
      inc_1_I6wjjge_aow2h993l1((&(*ctx_60).d_00.numLocals_0));
      put_0_comaa5xpt1((&(*ctx_60).d_00.smap_0), esym_1, slot_8);
      NI32 X60Qx_1361 = emit_0_comaa5xpt1(ctx_60, 69, 0, 0);
      NI32 X60Qx_1362 = emit_0_comaa5xpt1(ctx_60, 6, slot_8, 0);
      skip_0_nifb6mq6y1((&ec_0));
      eQdestroy_0_nifb6mq6y1((&lc_5));}
    else {
      skip_0_nifb6mq6y1((&ec_0));}}
  compileStmt_1_comaa5xpt1(c_88, ctx_60, (&ec_0));
  eQdestroy_0_nifb6mq6y1((&ec_0));}
void compileTry_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_89, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_61, Cursor_0_nifb6mq6y1* n_49){
  inc_0_nifb6mq6y1(n_49);
  Cursor_0_nifb6mq6y1 bodyCur_3 = eQdup_0_nifb6mq6y1((*n_49));
  skip_0_nifb6mq6y1(n_49);
  seq_0_Isyzizu1_comaa5xpt1 exceptCurs_0 = newSeqUninit_0_Iikx2qh1_comaa5xpt1(0);
  Cursor_0_nifb6mq6y1 finCur_2 = (Cursor_0_nifb6mq6y1){
    .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
  ;
  NB8 hasFin_0 = NIM_FALSE;
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1363 = kind_0_nifb6mq6y1((*n_49));
      if ((!(X60Qx_1363 == 12))){
        string_0_sysvq0asl t_16 = nodeTag_0_comaa5xpt1((*n_49));
        NB8 X60Qx_1364 = eqQ_20_sysvq0asl(t_16, (string_0_sysvq0asl){
          .bytes_0 = 1668834814u, .more_0 = (&strlit_0_I16264910594287870354_comaa5xpt1)}
        );
        if (X60Qx_1364){
          Cursor_0_nifb6mq6y1 X60Qx_1365 = eQdup_0_nifb6mq6y1((*n_49));
          add_0_Insw6ce1_comaa5xpt1((&exceptCurs_0), X60Qx_1365);
          skip_0_nifb6mq6y1(n_49);}
        else {
          NB8 X60Qx_1366 = eqQ_20_sysvq0asl(t_16, (string_0_sysvq0asl){
            .bytes_0 = 1852401155u, .more_0 = NIM_NIL}
          );
          if (X60Qx_1366){
            eQdestroy_0_nifb6mq6y1((&finCur_2));
            Cursor_0_nifb6mq6y1 X60Qx_1367 = eQdup_0_nifb6mq6y1((*n_49));
            finCur_2 = X60Qx_1367;
            hasFin_0 = NIM_TRUE;
            skip_0_nifb6mq6y1(n_49);}
          else {
            skip_0_nifb6mq6y1(n_49);}}
        nimStrDestroy(t_16);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_49);
  NB8 hasExc_0 = (0 < exceptCurs_0.len_0);
  NI32 finSetup_0 = -1;
  if (hasFin_0){
    NI32 X60Qx_1368 = emit_0_comaa5xpt1(ctx_61, 64, -1, 0);
    finSetup_0 = X60Qx_1368;}
  NI32 excSetup_0 = -1;
  if (hasExc_0){
    NI32 X60Qx_1369 = emit_0_comaa5xpt1(ctx_61, 64, 0, -1);
    excSetup_0 = X60Qx_1369;}
  if (hasFin_0){
    NI32 X60Qx_16 = len_3_Ij0uoqp_comaa5xpt1((*ctx_61).d_00.loops_0);
    NI64 X60Qx_17;
    if (hasExc_0){
      X60Qx_17 = 2;}
    else {
      X60Qx_17 = 1;}
    Cursor_0_nifb6mq6y1 X60Qx_1370 = eQdup_0_nifb6mq6y1(finCur_2);
    add_0_Ie3v897_comaa5xpt1((&(*ctx_61).d_00.finallys_0), (FinScope_0_comaa5xpt1){
      .finCur_0 = X60Qx_1370, .loopLen_0 = X60Qx_16, .handlerCount_0 = X60Qx_17}
    );}
  Cursor_0_nifb6mq6y1 bc_3 = bodyCur_3;
  eQwasMoved_0_nifb6mq6y1((&bodyCur_3));
  compileStmt_1_comaa5xpt1(c_89, ctx_61, (&bc_3));
  if (hasExc_0){
    NI32 X60Qx_1371 = emit_0_comaa5xpt1(ctx_61, 65, 0, 0);
    NI32 jdone_0 = emit_0_comaa5xpt1(ctx_61, 24, 0, 0);
    NI32 X60Qx_1372 = len_3_Icgec691_comaa5xpt1((*ctx_61).d_00.code_0);
    patch_0_comaa5xpt1(ctx_61, excSetup_0, X60Qx_1372);
    Cursor_0_nifb6mq6y1* X60Qx_1373 = getQ_7_Iyegbq3_comaa5xpt1(exceptCurs_0, 0);
    emitExceptDispatch_0_comaa5xpt1(c_89, ctx_61, (*X60Qx_1373));
    NB8 X60Qx_1374;
    if (hasFin_0){
      X60Qx_1374 = (*ctx_61).d_00.isPassive_0;}
    else {
      X60Qx_1374 = NIM_FALSE;}
    if (X60Qx_1374){
      emitFinallyGuarded_0_comaa5xpt1(c_89, ctx_61, finCur_2);}
    NI32 X60Qx_1375 = len_3_Icgec691_comaa5xpt1((*ctx_61).d_00.code_0);
    patch_0_comaa5xpt1(ctx_61, jdone_0, X60Qx_1375);}
  if (hasFin_0){
    NI32 X60Qx_1376 = len_3_I8hzf0s1_comaa5xpt1((*ctx_61).d_00.finallys_0);
    setLen_0_I53ui2z_comaa5xpt1((&(*ctx_61).d_00.finallys_0), ((NI32)(X60Qx_1376 - 1)));
    NI32 X60Qx_1377 = emit_0_comaa5xpt1(ctx_61, 65, 0, 0);
    emitFinallyGuarded_0_comaa5xpt1(c_89, ctx_61, finCur_2);
    NI32 jend_2 = emit_0_comaa5xpt1(ctx_61, 24, 0, 0);
    NI32 X60Qx_1378 = len_3_Icgec691_comaa5xpt1((*ctx_61).d_00.code_0);
    patchB_0_comaa5xpt1(ctx_61, finSetup_0, X60Qx_1378);
    emitFinallyGuarded_0_comaa5xpt1(c_89, ctx_61, finCur_2);
    NI32 X60Qx_1379 = emit_0_comaa5xpt1(ctx_61, 68, 0, 0);
    NI32 X60Qx_1380 = len_3_Icgec691_comaa5xpt1((*ctx_61).d_00.code_0);
    patch_0_comaa5xpt1(ctx_61, jend_2, X60Qx_1380);}
  eQdestroy_0_nifb6mq6y1((&bc_3));
  eQdestroy_0_nifb6mq6y1((&finCur_2));
  eQdestroy_1_Ir7cqbo_comaa5xpt1(exceptCurs_0);
  eQdestroy_0_nifb6mq6y1((&bodyCur_3));}
void emitExceptDispatchExpr_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_90, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_62, Cursor_0_nifb6mq6y1 exceptCur_1){
  Cursor_0_nifb6mq6y1 ec_1 = eQdup_0_nifb6mq6y1(exceptCur_1);
  inc_0_nifb6mq6y1((&ec_1));
  NifKind_0_nif81dubp1 X60Qx_1381 = kind_0_nifb6mq6y1(ec_1);
  if (X60Qx_1381 == 2){
    inc_0_nifb6mq6y1((&ec_1));}
  else {
    NB8 X60Qx_101;
    NifKind_0_nif81dubp1 X60Qx_1382 = kind_0_nifb6mq6y1(ec_1);
    if (X60Qx_1382 == 11){
      NB8 X60Qx_102;
      NB8 X60Qx_103;
      string_0_sysvq0asl X60Qtmp_113 = nodeTag_0_comaa5xpt1(ec_1);
      NB8 X60Qx_1383 = eqQ_20_sysvq0asl(X60Qtmp_113, (string_0_sysvq0asl){
        .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
      );
      if (X60Qx_1383){
        X60Qx_103 = NIM_TRUE;}
      else {
        string_0_sysvq0asl X60Qtmp_114 = nodeTag_0_comaa5xpt1(ec_1);
        NB8 X60Qx_1384 = eqQ_20_sysvq0asl(X60Qtmp_114, (string_0_sysvq0asl){
          .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I17735862253056247523_comaa5xpt1)}
        );
        X60Qx_103 = X60Qx_1384;
        nimStrDestroy(X60Qtmp_114);}
      if (X60Qx_103){
        X60Qx_102 = NIM_TRUE;}
      else {
        string_0_sysvq0asl X60Qtmp_115 = nodeTag_0_comaa5xpt1(ec_1);
        NB8 X60Qx_1385 = eqQ_20_sysvq0asl(X60Qtmp_115, (string_0_sysvq0asl){
          .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
        );
        X60Qx_102 = X60Qx_1385;
        nimStrDestroy(X60Qtmp_115);}
      X60Qx_101 = X60Qx_102;
      nimStrDestroy(X60Qtmp_113);}
    else {
      X60Qx_101 = NIM_FALSE;}
    if (X60Qx_101){
      Cursor_0_nifb6mq6y1 lc_6 = eQdup_0_nifb6mq6y1(ec_1);
      inc_0_nifb6mq6y1((&lc_6));
      NU32 esym_2 = ((NU32)0u);
      NifKind_0_nif81dubp1 X60Qx_1386 = kind_0_nifb6mq6y1(lc_6);
      if (X60Qx_1386 == 5){
        NU32 X60Qx_1387 = symId_0_nifb6mq6y1(lc_6);
        esym_2 = X60Qx_1387;}
      NI32 slot_9 = (*ctx_62).d_00.numLocals_0;
      inc_1_I6wjjge_aow2h993l1((&(*ctx_62).d_00.numLocals_0));
      put_0_comaa5xpt1((&(*ctx_62).d_00.smap_0), esym_2, slot_9);
      NI32 X60Qx_1388 = emit_0_comaa5xpt1(ctx_62, 69, 0, 0);
      NI32 X60Qx_1389 = emit_0_comaa5xpt1(ctx_62, 6, slot_9, 0);
      skip_0_nifb6mq6y1((&ec_1));
      eQdestroy_0_nifb6mq6y1((&lc_6));}
    else {
      skip_0_nifb6mq6y1((&ec_1));}}
  NB8 X60Qx_104;
  NifKind_0_nif81dubp1 X60Qx_1390 = kind_0_nifb6mq6y1(ec_1);
  if (X60Qx_1390 == 11){
    string_0_sysvq0asl X60Qtmp_116 = nodeTag_0_comaa5xpt1(ec_1);
    NB8 X60Qx_1391 = eqQ_20_sysvq0asl(X60Qtmp_116, (string_0_sysvq0asl){
      .bytes_0 = 1886938622u, .more_0 = (&strlit_0_I13798915436014509391_comaa5xpt1)}
    );
    X60Qx_104 = X60Qx_1391;
    nimStrDestroy(X60Qtmp_116);}
  else {
    X60Qx_104 = NIM_FALSE;}
  if (X60Qx_104){
    compileExpr_1_comaa5xpt1(c_90, ctx_62, (&ec_1));}
  else {
    compileStmt_1_comaa5xpt1(c_90, ctx_62, (&ec_1));
    NI32 X60Qx_1392 = emit_0_comaa5xpt1(ctx_62, 1, 0, 0);}
  eQdestroy_0_nifb6mq6y1((&ec_1));}
void compileTryExpr_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_91, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_63, Cursor_0_nifb6mq6y1* n_50){
  inc_0_nifb6mq6y1(n_50);
  Cursor_0_nifb6mq6y1 bodyCur_4 = eQdup_0_nifb6mq6y1((*n_50));
  skip_0_nifb6mq6y1(n_50);
  seq_0_Isyzizu1_comaa5xpt1 exceptCurs_1 = newSeqUninit_0_Iikx2qh1_comaa5xpt1(0);
  Cursor_0_nifb6mq6y1 finCur_3 = (Cursor_0_nifb6mq6y1){
    .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
  ;
  NB8 hasFin_1 = NIM_FALSE;
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1393 = kind_0_nifb6mq6y1((*n_50));
      if ((!(X60Qx_1393 == 12))){
        string_0_sysvq0asl t_17 = nodeTag_0_comaa5xpt1((*n_50));
        NB8 X60Qx_1394 = eqQ_20_sysvq0asl(t_17, (string_0_sysvq0asl){
          .bytes_0 = 1668834814u, .more_0 = (&strlit_0_I16264910594287870354_comaa5xpt1)}
        );
        if (X60Qx_1394){
          Cursor_0_nifb6mq6y1 X60Qx_1395 = eQdup_0_nifb6mq6y1((*n_50));
          add_0_Insw6ce1_comaa5xpt1((&exceptCurs_1), X60Qx_1395);
          skip_0_nifb6mq6y1(n_50);}
        else {
          NB8 X60Qx_1396 = eqQ_20_sysvq0asl(t_17, (string_0_sysvq0asl){
            .bytes_0 = 1852401155u, .more_0 = NIM_NIL}
          );
          if (X60Qx_1396){
            eQdestroy_0_nifb6mq6y1((&finCur_3));
            Cursor_0_nifb6mq6y1 X60Qx_1397 = eQdup_0_nifb6mq6y1((*n_50));
            finCur_3 = X60Qx_1397;
            hasFin_1 = NIM_TRUE;
            skip_0_nifb6mq6y1(n_50);}
          else {
            skip_0_nifb6mq6y1(n_50);}}
        nimStrDestroy(t_17);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_50);
  NB8 hasExc_1 = (0 < exceptCurs_1.len_0);
  NI32 finSetup_1 = -1;
  if (hasFin_1){
    NI32 X60Qx_1398 = emit_0_comaa5xpt1(ctx_63, 64, -1, 0);
    finSetup_1 = X60Qx_1398;}
  NI32 excSetup_1 = -1;
  if (hasExc_1){
    NI32 X60Qx_1399 = emit_0_comaa5xpt1(ctx_63, 64, 0, -1);
    excSetup_1 = X60Qx_1399;}
  Cursor_0_nifb6mq6y1 bc_4 = bodyCur_4;
  eQwasMoved_0_nifb6mq6y1((&bodyCur_4));
  compileExpr_1_comaa5xpt1(c_91, ctx_63, (&bc_4));
  if (hasExc_1){
    NI32 X60Qx_1400 = emit_0_comaa5xpt1(ctx_63, 65, 0, 0);
    NI32 jdone_1 = emit_0_comaa5xpt1(ctx_63, 24, 0, 0);
    NI32 X60Qx_1401 = len_3_Icgec691_comaa5xpt1((*ctx_63).d_00.code_0);
    patch_0_comaa5xpt1(ctx_63, excSetup_1, X60Qx_1401);
    Cursor_0_nifb6mq6y1* X60Qx_1402 = getQ_7_Iyegbq3_comaa5xpt1(exceptCurs_1, 0);
    emitExceptDispatchExpr_0_comaa5xpt1(c_91, ctx_63, (*X60Qx_1402));
    NI32 X60Qx_1403 = len_3_Icgec691_comaa5xpt1((*ctx_63).d_00.code_0);
    patch_0_comaa5xpt1(ctx_63, jdone_1, X60Qx_1403);}
  if (hasFin_1){
    NI32 X60Qx_1404 = emit_0_comaa5xpt1(ctx_63, 65, 0, 0);
    emitFinallyBody_0_comaa5xpt1(c_91, ctx_63, finCur_3);
    NI32 jend_3 = emit_0_comaa5xpt1(ctx_63, 24, 0, 0);
    NI32 X60Qx_1405 = len_3_Icgec691_comaa5xpt1((*ctx_63).d_00.code_0);
    patchB_0_comaa5xpt1(ctx_63, finSetup_1, X60Qx_1405);
    emitFinallyBody_0_comaa5xpt1(c_91, ctx_63, finCur_3);
    NI32 X60Qx_1406 = emit_0_comaa5xpt1(ctx_63, 68, 0, 0);
    NI32 X60Qx_1407 = len_3_Icgec691_comaa5xpt1((*ctx_63).d_00.code_0);
    patch_0_comaa5xpt1(ctx_63, jend_3, X60Qx_1407);}
  eQdestroy_0_nifb6mq6y1((&bc_4));
  eQdestroy_0_nifb6mq6y1((&finCur_3));
  eQdestroy_1_Ir7cqbo_comaa5xpt1(exceptCurs_1);
  eQdestroy_0_nifb6mq6y1((&bodyCur_4));}
void emitPendingFinallys_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_92, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_64, NI32 li_0){
  NI32 X60Qx_1408 = len_3_I8hzf0s1_comaa5xpt1((*ctx_64).d_00.finallys_0);
  NI32 i_25 = ((NI32)(X60Qx_1408 - 1));
  {
    while (0 <= i_25){
      FinScope_0_comaa5xpt1* X60Qx_1409 = getQ_7_Irfu7p7_comaa5xpt1((*ctx_64).d_00.finallys_0, i_25);
      if (li_0 < (*X60Qx_1409).loopLen_0){
        FinScope_0_comaa5xpt1* X60Qx_1410 = getQ_7_Irfu7p7_comaa5xpt1((*ctx_64).d_00.finallys_0, i_25);
        emitFinallyGuarded_0_comaa5xpt1(c_92, ctx_64, (*X60Qx_1410).finCur_0);
        NI32 k_5 = 0;
        {
          while (NIM_TRUE){
            FinScope_0_comaa5xpt1* X60Qx_1411 = getQ_7_Irfu7p7_comaa5xpt1((*ctx_64).d_00.finallys_0, i_25);
            if (k_5 < (*X60Qx_1411).handlerCount_0){
              NI32 X60Qx_1412 = emit_0_comaa5xpt1(ctx_64, 65, 0, 0);
              inc_1_I6wjjge_aow2h993l1((&k_5));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      dec_1_I0nzoz91_ast8ri79k((&i_25));}}
  whileStmtLabel_0: ;}
NU32 failedGuardSym_0_comaa5xpt1(Cursor_0_nifb6mq6y1 n_51){
  NU32 result_45;
  result_45 = ((NU32)0u);
  Cursor_0_nifb6mq6y1 c_108 = eQdup_0_nifb6mq6y1(n_51);
  NB8 X60Qx_105;
  NifKind_0_nif81dubp1 X60Qx_1413 = kind_0_nifb6mq6y1(c_108);
  if ((!(X60Qx_1413 == 11))){
    X60Qx_105 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_117 = nodeTag_0_comaa5xpt1(c_108);
    NB8 X60Qx_1414 = eqQ_20_sysvq0asl(X60Qtmp_117, (string_0_sysvq0asl){
      .bytes_0 = 6711554u, .more_0 = NIM_NIL}
    );
    X60Qx_105 = (!X60Qx_1414);
    nimStrDestroy(X60Qtmp_117);}
  if (X60Qx_105){
    eQdestroy_0_nifb6mq6y1((&c_108));
    return result_45;}
  inc_0_nifb6mq6y1((&c_108));
  NB8 X60Qx_106;
  NifKind_0_nif81dubp1 X60Qx_1415 = kind_0_nifb6mq6y1(c_108);
  if ((!(X60Qx_1415 == 11))){
    X60Qx_106 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_118 = nodeTag_0_comaa5xpt1(c_108);
    NB8 X60Qx_1416 = eqQ_20_sysvq0asl(X60Qtmp_118, (string_0_sysvq0asl){
      .bytes_0 = 1768711678u, .more_0 = (&strlit_0_I13424873862977158440_comaa5xpt1)}
    );
    X60Qx_106 = (!X60Qx_1416);
    nimStrDestroy(X60Qtmp_118);}
  if (X60Qx_106){
    eQdestroy_0_nifb6mq6y1((&c_108));
    return result_45;}
  inc_0_nifb6mq6y1((&c_108));
  NB8 X60Qx_107;
  NifKind_0_nif81dubp1 X60Qx_1417 = kind_0_nifb6mq6y1(c_108);
  if ((!(X60Qx_1417 == 11))){
    X60Qx_107 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_119 = nodeTag_0_comaa5xpt1(c_108);
    NB8 X60Qx_1418 = eqQ_20_sysvq0asl(X60Qtmp_119, (string_0_sysvq0asl){
      .bytes_0 = 1767991038u, .more_0 = (&strlit_0_I14845204679832807538_comaa5xpt1)}
    );
    X60Qx_107 = (!X60Qx_1418);
    nimStrDestroy(X60Qtmp_119);}
  if (X60Qx_107){
    eQdestroy_0_nifb6mq6y1((&c_108));
    return result_45;}
  inc_0_nifb6mq6y1((&c_108));
  NifKind_0_nif81dubp1 X60Qx_1419 = kind_0_nifb6mq6y1(c_108);
  if (X60Qx_1419 == 4){
    NU32 X60Qx_1420 = symId_0_nifb6mq6y1(c_108);
    result_45 = X60Qx_1420;}
  eQdestroy_0_nifb6mq6y1((&c_108));
  return result_45;
  eQdestroy_0_nifb6mq6y1((&c_108));
  return result_45;}
void compileFailedGuard_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_93, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_65, Cursor_0_nifb6mq6y1* n_52, NU32 gsym_0){
  NI32 setup_0 = emit_0_comaa5xpt1(ctx_65, 64, 0, -1);
  compileStmt_1_comaa5xpt1(c_93, ctx_65, n_52);
  NI32 X60Qx_1421 = emit_0_comaa5xpt1(ctx_65, 65, 0, 0);
  NI32 jdone_2 = emit_0_comaa5xpt1(ctx_65, 24, 0, 0);
  NI32 X60Qx_1422 = len_3_Icgec691_comaa5xpt1((*ctx_65).d_00.code_0);
  patch_0_comaa5xpt1(ctx_65, setup_0, X60Qx_1422);
  inc_0_nifb6mq6y1(n_52);
  inc_0_nifb6mq6y1(n_52);
  skip_0_nifb6mq6y1(n_52);
  NU32 saved_0 = (*ctx_65).d_00.guardSym_0;
  (*ctx_65).d_00.guardSym_0 = gsym_0;
  compileStmt_1_comaa5xpt1(c_93, ctx_65, n_52);
  (*ctx_65).d_00.guardSym_0 = saved_0;
  consumeParRi_0_nifb6mq6y1(n_52);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1423 = kind_0_nifb6mq6y1((*n_52));
      if ((!(X60Qx_1423 == 12))){
        skip_0_nifb6mq6y1(n_52);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_52);
  NI32 X60Qx_1424 = len_3_Icgec691_comaa5xpt1((*ctx_65).d_00.code_0);
  patch_0_comaa5xpt1(ctx_65, jdone_2, X60Qx_1424);}
void compileStmt_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_94, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_66, Cursor_0_nifb6mq6y1* n_53){
  NifKind_0_nif81dubp1 X60Qx_1425 = kind_0_nifb6mq6y1((*n_53));
  if ((!(X60Qx_1425 == 11))){
    inc_0_nifb6mq6y1(n_53);
    return;}
  string_0_sysvq0asl tag_4 = nodeTag_0_comaa5xpt1((*n_53));
  NI32 X60Qx_1426 = lineOf_0_comaa5xpt1((*n_53));
  (*ctx_66).d_00.curLine_0 = X60Qx_1426;
  NB8 X60Qtc_147 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'g');
  if (X60Qtc_147){
    NB8 X60Qtc_148 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'c');
    if (X60Qtc_148){
      NB8 X60Qtc_149 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'b');
      if (X60Qtc_149){
        NB8 X60Qtc_150 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'a');
        if (X60Qtc_150){
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1735614974u, .more_0 = (&strlit_0_I2681092370707159476_comaa5xpt1)}
          )){
            goto X60Qsc_129;}}
        else {
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1869374206u, .more_0 = (&strlit_0_I9830314142150548690_comaa5xpt1)}
          )){
            goto X60Qsc_133;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1701995262u, .more_0 = (&strlit_0_I8380221545607033154_comaa5xpt1)}
          )){
            goto X60Qsc_134;}}}
      else {
        NB8 X60Qtc_151 = nimStrAtLe_0_sysvq0asl(tag_4, 2, (NC8)'n');
        if (X60Qtc_151){
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I12999086881046019782_comaa5xpt1)}
          )){
            goto X60Qsc_127;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I2210116261907819816_comaa5xpt1)}
          )){
            goto X60Qsc_135;}}
        else {
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I17735862253056247523_comaa5xpt1)}
          )){
            goto X60Qsc_127;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I4956278306908871092_comaa5xpt1)}
          )){
            goto X60Qsc_132;}}}}
    else {
      NB8 X60Qtc_152 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'d');
      if (X60Qtc_152){
        NB8 X60Qtc_153 = nimStrAtLe_0_sysvq0asl(tag_4, 1, (NC8)'e');
        if (X60Qtc_153){
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I14418907618963914168_comaa5xpt1)}
          )){
            goto X60Qsc_144;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1818584318u, .more_0 = (&strlit_0_I358872489388858575_comaa5xpt1)}
          )){
            goto X60Qsc_144;}}
        else {
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1936286974u, .more_0 = (&strlit_0_I2956720964102846418_comaa5xpt1)}
          )){
            goto X60Qsc_139;}}}
      else {
        NB8 X60Qtc_154 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'f');
        if (X60Qtc_154){
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1919903235u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_140;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1668834814u, .more_0 = (&strlit_0_I2784804726569183623_comaa5xpt1)}
          )){
            goto X60Qsc_145;}}
        else {
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1635149822u, .more_0 = (&strlit_0_I1281801651151844468_comaa5xpt1)}
          )){
            goto X60Qsc_127;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1701603326u, .more_0 = (&strlit_0_I5723805845286553140_comaa5xpt1)}
          )){
            goto X60Qsc_127;}}}}}
  else {
    NB8 X60Qtc_155 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'r');
    if (X60Qtc_155){
      NB8 X60Qtc_156 = nimStrAtLe_0_sysvq0asl(tag_4, 2, (NC8)'s');
      if (X60Qtc_156){
        NB8 X60Qtc_157 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'p');
        if (X60Qtc_157){
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I17199005983847516849_comaa5xpt1)}
          )){
            goto X60Qsc_142;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I14732757010146030568_comaa5xpt1)}
          )){
            goto X60Qsc_145;}}
        else {
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1936028414u, .more_0 = (&strlit_0_I2416437014800228590_comaa5xpt1)}
          )){
            goto X60Qsc_128;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1767994110u, .more_0 = (&strlit_0_I6137881024046402116_comaa5xpt1)}
          )){
            goto X60Qsc_138;}}}
      else {
        NB8 X60Qtc_158 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'l');
        if (X60Qtc_158){
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1952803843u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_127;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 6711554u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_130;}}
        else {
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1952542974u, .more_0 = (&strlit_0_I3786558325628924612_comaa5xpt1)}
          )){
            goto X60Qsc_127;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1952805379u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_136;}}}}
    else {
      NB8 X60Qtc_159 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'v');
      if (X60Qtc_159){
        NB8 X60Qtc_160 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'s');
        if (X60Qtc_160){
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1836348414u, .more_0 = (&strlit_0_I13752166055203769914_comaa5xpt1)}
          )){
            goto X60Qsc_126;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1937077246u, .more_0 = (&strlit_0_I11512946405431690565_comaa5xpt1)}
          )){
            goto X60Qsc_143;}}
        else {
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_127;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 2037543939u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_137;}}}
      else {
        NB8 X60Qtc_161 = nimStrAtLe_0_sysvq0asl(tag_4, 0, (NC8)'w');
        if (X60Qtc_161){
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1768454142u, .more_0 = (&strlit_0_I13200118161122656888_comaa5xpt1)}
          )){
            goto X60Qsc_131;}
          else if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1935767550u, .more_0 = (&strlit_0_I10163392937326623266_comaa5xpt1)}
          )){
            goto X60Qsc_146;}}
        else {
          if (equalStrings_0_sysvq0asl(tag_4, (string_0_sysvq0asl){
            .bytes_0 = 1684830467u, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_141;}}}}}
  goto X60Qsc_163;
  X60Qsc_126: ;
  inc_0_nifb6mq6y1(n_53);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1427 = kind_0_nifb6mq6y1((*n_53));
      if ((!(X60Qx_1427 == 12))){
        Cursor_0_nifb6mq6y1 la_0 = eQdup_0_nifb6mq6y1((*n_53));
        skip_0_nifb6mq6y1((&la_0));
        NU32 X60Qx_18;
        NifKind_0_nif81dubp1 X60Qx_1428 = kind_0_nifb6mq6y1(la_0);
        if (X60Qx_1428 == 12){
          X60Qx_18 = ((NU32)0u);}
        else {
          NU32 X60Qx_1429 = failedGuardSym_0_comaa5xpt1(la_0);
          X60Qx_18 = X60Qx_1429;}
        NU32 gsym_1 = X60Qx_18;
        NB8 X60Qx_1430 = eqQ_0_nifh7u8pu1(gsym_1, ((NU32)0u));
        if ((!X60Qx_1430)){
          compileFailedGuard_0_comaa5xpt1(c_94, ctx_66, n_53, gsym_1);}
        else {
          compileStmt_1_comaa5xpt1(c_94, ctx_66, n_53);}
        eQdestroy_0_nifb6mq6y1((&la_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  consumeParRi_0_nifb6mq6y1(n_53);
  goto X60Qsc_162;
  X60Qsc_127: ;
  compileLocal_0_comaa5xpt1(c_94, ctx_66, n_53, NIM_FALSE);
  goto X60Qsc_162;
  X60Qsc_128: ;
  compileLocal_0_comaa5xpt1(c_94, ctx_66, n_53, NIM_TRUE);
  goto X60Qsc_162;
  X60Qsc_129: ;
  compileAsgn_0_comaa5xpt1(c_94, ctx_66, n_53);
  goto X60Qsc_162;
  X60Qsc_130: ;
  compileIf_0_comaa5xpt1(c_94, ctx_66, n_53);
  goto X60Qsc_162;
  X60Qsc_131: ;
  compileWhile_0_comaa5xpt1(c_94, ctx_66, n_53);
  goto X60Qsc_162;
  X60Qsc_132: ;
  compileCase_0_comaa5xpt1(c_94, ctx_66, n_53);
  goto X60Qsc_162;
  X60Qsc_133: ;
  compileBlock_0_comaa5xpt1(c_94, ctx_66, n_53);
  goto X60Qsc_162;
  X60Qsc_134: ;
  inc_0_nifb6mq6y1(n_53);
  NU32 lbl_2 = ((NU32)0u);
  NifKind_0_nif81dubp1 X60Qx_1431 = kind_0_nifb6mq6y1((*n_53));
  if (X60Qx_1431 == 4){
    NU32 X60Qx_1432 = symId_0_nifb6mq6y1((*n_53));
    lbl_2 = X60Qx_1432;}
  NifKind_0_nif81dubp1 X60Qx_1433 = kind_0_nifb6mq6y1((*n_53));
  if ((!(X60Qx_1433 == 12))){
    skip_0_nifb6mq6y1(n_53);}
  consumeParRi_0_nifb6mq6y1(n_53);
  NI32 X60Qx_1434 = len_3_Ij0uoqp_comaa5xpt1((*ctx_66).d_00.loops_0);
  NI32 li_1 = ((NI32)(X60Qx_1434 - 1));
  if ((!(((NU32)lbl_2) == ((NU32)0u)))){
    li_1 = -1;
    NI32 X60Qx_1435 = len_3_Ij0uoqp_comaa5xpt1((*ctx_66).d_00.loops_0);
    NI32 k_6 = ((NI32)(X60Qx_1435 - 1));
    {
      while (0 <= k_6){
        X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1436 = getQ_7_I6yhgto_comaa5xpt1((*ctx_66).d_00.loops_0, k_6);
        NB8 X60Qx_1437 = eqQ_0_nifh7u8pu1((*(*X60Qx_1436)).d_00.label_0, lbl_2);
        if (X60Qx_1437){
          li_1 = k_6;
          goto whileStmtLabel_1;}
        dec_1_I0nzoz91_ast8ri79k((&k_6));}}
    whileStmtLabel_1: ;
    if (li_1 < 0){
      NI32 X60Qx_1438 = len_3_Ij0uoqp_comaa5xpt1((*ctx_66).d_00.loops_0);
      li_1 = ((NI32)(X60Qx_1438 - 1));}}
  if (0 <= li_1){
    emitPendingFinallys_0_comaa5xpt1(c_94, ctx_66, li_1);
    NI32 bp_7 = emit_0_comaa5xpt1(ctx_66, 24, 0, 0);
    X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1439 = getQ_7_I6yhgto_comaa5xpt1((*ctx_66).d_00.loops_0, li_1);
    add_0_I8kd4i4_comaa5xpt1((&(*(*X60Qx_1439)).d_00.breaks_0), bp_7);}
  goto X60Qsc_162;
  X60Qsc_135: ;
  inc_0_nifb6mq6y1(n_53);
  NU32 lbl_3 = ((NU32)0u);
  NifKind_0_nif81dubp1 X60Qx_1440 = kind_0_nifb6mq6y1((*n_53));
  if (X60Qx_1440 == 4){
    NU32 X60Qx_1441 = symId_0_nifb6mq6y1((*n_53));
    lbl_3 = X60Qx_1441;}
  NifKind_0_nif81dubp1 X60Qx_1442 = kind_0_nifb6mq6y1((*n_53));
  if ((!(X60Qx_1442 == 12))){
    skip_0_nifb6mq6y1(n_53);}
  consumeParRi_0_nifb6mq6y1(n_53);
  NI32 X60Qx_1443 = len_3_Ij0uoqp_comaa5xpt1((*ctx_66).d_00.loops_0);
  NI32 li_2 = ((NI32)(X60Qx_1443 - 1));
  if ((!(((NU32)lbl_3) == ((NU32)0u)))){
    li_2 = -1;
    NI32 X60Qx_1444 = len_3_Ij0uoqp_comaa5xpt1((*ctx_66).d_00.loops_0);
    NI32 k_7 = ((NI32)(X60Qx_1444 - 1));
    {
      while (0 <= k_7){
        X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1445 = getQ_7_I6yhgto_comaa5xpt1((*ctx_66).d_00.loops_0, k_7);
        NB8 X60Qx_1446 = eqQ_0_nifh7u8pu1((*(*X60Qx_1445)).d_00.label_0, lbl_3);
        if (X60Qx_1446){
          li_2 = k_7;
          goto whileStmtLabel_2;}
        dec_1_I0nzoz91_ast8ri79k((&k_7));}}
    whileStmtLabel_2: ;
    if (li_2 < 0){
      NI32 X60Qx_1447 = len_3_Ij0uoqp_comaa5xpt1((*ctx_66).d_00.loops_0);
      li_2 = ((NI32)(X60Qx_1447 - 1));}}
  if (0 <= li_2){
    emitPendingFinallys_0_comaa5xpt1(c_94, ctx_66, li_2);
    X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1448 = getQ_7_I6yhgto_comaa5xpt1((*ctx_66).d_00.loops_0, li_2);
    if (0 <= (*(*X60Qx_1448)).d_00.contTarget_0){
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1449 = getQ_7_I6yhgto_comaa5xpt1((*ctx_66).d_00.loops_0, li_2);
      NI32 X60Qx_1450 = emit_0_comaa5xpt1(ctx_66, 24, (*(*X60Qx_1449)).d_00.contTarget_0, 0);}
    else {
      NI32 cp_5 = emit_0_comaa5xpt1(ctx_66, 24, 0, 0);
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1451 = getQ_7_I6yhgto_comaa5xpt1((*ctx_66).d_00.loops_0, li_2);
      add_0_I8kd4i4_comaa5xpt1((&(*(*X60Qx_1451)).d_00.continues_0), cp_5);}}
  goto X60Qsc_162;
  X60Qsc_136: ;
  compileRet_0_comaa5xpt1(c_94, ctx_66, n_53);
  goto X60Qsc_162;
  X60Qsc_137: ;
  compileTry_1_comaa5xpt1(c_94, ctx_66, n_53);
  goto X60Qsc_162;
  X60Qsc_138: ;
  inc_0_nifb6mq6y1(n_53);
  NB8 X60Qx_1452;
  NifKind_0_nif81dubp1 X60Qx_1453 = kind_0_nifb6mq6y1((*n_53));
  if (X60Qx_1453 == 2){
    X60Qx_1452 = NIM_TRUE;}
  else {
    NifKind_0_nif81dubp1 X60Qx_1454 = kind_0_nifb6mq6y1((*n_53));
    X60Qx_1452 = (X60Qx_1454 == 12);}
  if (X60Qx_1452){
    NifKind_0_nif81dubp1 X60Qx_1455 = kind_0_nifb6mq6y1((*n_53));
    if (X60Qx_1455 == 2){
      inc_0_nifb6mq6y1(n_53);}
    consumeParRi_0_nifb6mq6y1(n_53);
    NI32 X60Qx_1456 = emit_0_comaa5xpt1(ctx_66, 67, 0, 0);}
  else {
    NB8 X60Qx_1457;
    NB8 X60Qx_1458;
    NifKind_0_nif81dubp1 X60Qx_1459 = kind_0_nifb6mq6y1((*n_53));
    if (X60Qx_1459 == 4){
      NB8 X60Qx_1460 = eqQ_0_nifh7u8pu1((*ctx_66).d_00.guardSym_0, ((NU32)0u));
      X60Qx_1458 = (!X60Qx_1460);}
    else {
      X60Qx_1458 = NIM_FALSE;}
    if (X60Qx_1458){
      NU32 X60Qx_1461 = symId_0_nifb6mq6y1((*n_53));
      NB8 X60Qx_1462 = eqQ_0_nifh7u8pu1(X60Qx_1461, (*ctx_66).d_00.guardSym_0);
      X60Qx_1457 = X60Qx_1462;}
    else {
      X60Qx_1457 = NIM_FALSE;}
    if (X60Qx_1457){
      inc_0_nifb6mq6y1(n_53);
      consumeParRi_0_nifb6mq6y1(n_53);
      NI32 X60Qx_1463 = emit_0_comaa5xpt1(ctx_66, 67, 0, 0);}
    else {
      compileExpr_1_comaa5xpt1(c_94, ctx_66, n_53);
      consumeParRi_0_nifb6mq6y1(n_53);
      NI32 X60Qx_1464 = emit_0_comaa5xpt1(ctx_66, 66, 0, 0);}}
  goto X60Qsc_162;
  X60Qsc_139: ;
  inc_0_nifb6mq6y1(n_53);
  NB8 X60Qx_1465;
  NifKind_0_nif81dubp1 X60Qx_1466 = kind_0_nifb6mq6y1((*n_53));
  if (X60Qx_1466 == 8){
    NU32 X60Qx_1467 = intId_0_nifb6mq6y1((*n_53));
    NI64* X60Qx_1468 = getQ_0_Irwkiny1_ast8ri79k(pool_0_nifh7u8pu1.integers_0, X60Qx_1467);
    X60Qx_1465 = (((NI64)IL64(7020961649834065920)) <= (*X60Qx_1468));}
  else {
    X60Qx_1465 = NIM_FALSE;}
  if (X60Qx_1465){
    NI32 X60Qx_1469 = emit_0_comaa5xpt1(ctx_66, 70, 0, 0);
    inc_0_nifb6mq6y1(n_53);
    consumeParRi_0_nifb6mq6y1(n_53);
    nimStrDestroy(tag_4);
    return;}
  NB8 X60Qx_1470;
  NifKind_0_nif81dubp1 X60Qx_1471 = kind_0_nifb6mq6y1((*n_53));
  if ((!(X60Qx_1471 == 12))){
    NifKind_0_nif81dubp1 X60Qx_1472 = kind_0_nifb6mq6y1((*n_53));
    X60Qx_1470 = (!(X60Qx_1472 == 2));}
  else {
    X60Qx_1470 = NIM_FALSE;}
  if (X60Qx_1470){
    compileExpr_1_comaa5xpt1(c_94, ctx_66, n_53);
    NI32 X60Qx_1473 = emit_0_comaa5xpt1(ctx_66, 4, 0, 0);}
  else {
    NifKind_0_nif81dubp1 X60Qx_1474 = kind_0_nifb6mq6y1((*n_53));
    if (X60Qx_1474 == 2){
      inc_0_nifb6mq6y1(n_53);}}
  consumeParRi_0_nifb6mq6y1(n_53);
  goto X60Qsc_162;
  X60Qsc_140: ;
  compileFor_1_comaa5xpt1(c_94, ctx_66, n_53);
  goto X60Qsc_162;
  X60Qsc_141: ;
  if (0 < (*ctx_66).d_00.yields_0.len_0){
    X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1475 = getQ_7_Iklts1k_comaa5xpt1((*ctx_66).d_00.yields_0, ((NI32)((*ctx_66).d_00.yields_0.len_0 - ((NI32)((NI32)1)))));
    X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* yf_0 = eQdupQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_1475));
    inc_0_nifb6mq6y1(n_53);
    NifKind_0_nif81dubp1 X60Qx_1476 = kind_0_nifb6mq6y1((*n_53));
    if (X60Qx_1476 == 2){
      inc_0_nifb6mq6y1(n_53);}
    else {
      NifKind_0_nif81dubp1 X60Qx_1477 = kind_0_nifb6mq6y1((*n_53));
      if ((!(X60Qx_1477 == 12))){
        seq_0_Ik7wkpe_comaa5xpt1 plan_3 = eQdup_1_Iqlupf9_comaa5xpt1((*yf_0).d_00.unpackPlan_0);
        NI32 X60Qx_1478 = len_3_Irjnvku_comaa5xpt1(plan_3);
        if (X60Qx_1478 == 0){
          compileExpr_1_comaa5xpt1(c_94, ctx_66, n_53);
          NI32 X60Qx_1479 = emit_0_comaa5xpt1(ctx_66, 4, 0, 0);}
        else {
          NB8 X60Qx_1480;
          NI32 X60Qx_1481 = len_3_Irjnvku_comaa5xpt1(plan_3);
          if (X60Qx_1481 == 1){
            seq_0_Ift2sne_chu5m1rja1* X60Qx_1482 = getQ_7_Iurb46i_comaa5xpt1(plan_3, 0);
            NI32 X60Qx_1483 = len_3_I0v1j8d_comaa5xpt1((*X60Qx_1482));
            X60Qx_1480 = (X60Qx_1483 == 1);}
          else {
            X60Qx_1480 = NIM_FALSE;}
          if (X60Qx_1480){
            compileExpr_1_comaa5xpt1(c_94, ctx_66, n_53);
            seq_0_Ift2sne_chu5m1rja1* X60Qx_1484 = getQ_7_Iurb46i_comaa5xpt1(plan_3, 0);
            NI32* X60Qx_1485 = getQ_7_Ir8kccm_comaa5xpt1((*X60Qx_1484), 0);
            NI32 X60Qx_1486 = emit_0_comaa5xpt1(ctx_66, 6, (*X60Qx_1485), 0);}
          else {
            compileExpr_1_comaa5xpt1(c_94, ctx_66, n_53);
            NI32 X60Qx_1487 = emit_0_comaa5xpt1(ctx_66, 6, (*yf_0).d_00.tmpSlot_0, 0);
            NI32 X60Qx_1488 = len_3_Irjnvku_comaa5xpt1(plan_3);
            if (X60Qx_1488 == 1){
              seq_0_Ift2sne_chu5m1rja1* X60Qx_1489 = getQ_7_Iurb46i_comaa5xpt1(plan_3, 0);
              seq_0_Ift2sne_chu5m1rja1 group_3 = eQdup_1_Iplow11_chu5m1rja1((*X60Qx_1489));
              NI32 k_8 = 0;
              {
                while (NIM_TRUE){
                  NI32 X60Qx_1490 = len_3_I0v1j8d_comaa5xpt1(group_3);
                  if (k_8 < X60Qx_1490){
                    NI32 X60Qx_1491 = emit_0_comaa5xpt1(ctx_66, 5, (*yf_0).d_00.tmpSlot_0, 0);
                    Value_0_valzr1t4f X60Qtmp_120 = vInt_0_valzr1t4f(((NI64)k_8), 64);
                    NI32 X60Qx_1492 = addConst_0_comaa5xpt1(c_94, (&X60Qtmp_120));
                    NI32 X60Qx_1493 = emit_0_comaa5xpt1(ctx_66, 0, X60Qx_1492, 0);
                    NI32 X60Qx_1494 = emit_0_comaa5xpt1(ctx_66, 43, 0, 0);
                    NI32* X60Qx_1495 = getQ_7_Ir8kccm_comaa5xpt1(group_3, k_8);
                    NI32 X60Qx_1496 = emit_0_comaa5xpt1(ctx_66, 6, (*X60Qx_1495), 0);
                    inc_1_I6wjjge_aow2h993l1((&k_8));
                    eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_120));}
                  else {
                    break;}}}
              whileStmtLabel_3: ;
              eQdestroy_1_Iv9ij5i1_chu5m1rja1(group_3);}
            else {
              NI32 j_1 = 0;
              {
                while (NIM_TRUE){
                  NI32 X60Qx_1497 = len_3_Irjnvku_comaa5xpt1(plan_3);
                  if (j_1 < X60Qx_1497){
                    seq_0_Ift2sne_chu5m1rja1* X60Qx_1498 = getQ_7_Iurb46i_comaa5xpt1(plan_3, j_1);
                    seq_0_Ift2sne_chu5m1rja1 group_4 = eQdup_1_Iplow11_chu5m1rja1((*X60Qx_1498));
                    NI32 X60Qx_1499 = len_3_I0v1j8d_comaa5xpt1(group_4);
                    if (X60Qx_1499 == 1){
                      NI32 X60Qx_1500 = emit_0_comaa5xpt1(ctx_66, 5, (*yf_0).d_00.tmpSlot_0, 0);
                      Value_0_valzr1t4f X60Qtmp_121 = vInt_0_valzr1t4f(((NI64)j_1), 64);
                      NI32 X60Qx_1501 = addConst_0_comaa5xpt1(c_94, (&X60Qtmp_121));
                      NI32 X60Qx_1502 = emit_0_comaa5xpt1(ctx_66, 0, X60Qx_1501, 0);
                      NI32 X60Qx_1503 = emit_0_comaa5xpt1(ctx_66, 43, 0, 0);
                      NI32* X60Qx_1504 = getQ_7_Ir8kccm_comaa5xpt1(group_4, 0);
                      NI32 X60Qx_1505 = emit_0_comaa5xpt1(ctx_66, 6, (*X60Qx_1504), 0);
                      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_121));}
                    else {
                      NI32 X60Qx_1506 = emit_0_comaa5xpt1(ctx_66, 5, (*yf_0).d_00.tmpSlot_0, 0);
                      Value_0_valzr1t4f X60Qtmp_122 = vInt_0_valzr1t4f(((NI64)j_1), 64);
                      NI32 X60Qx_1507 = addConst_0_comaa5xpt1(c_94, (&X60Qtmp_122));
                      NI32 X60Qx_1508 = emit_0_comaa5xpt1(ctx_66, 0, X60Qx_1507, 0);
                      NI32 X60Qx_1509 = emit_0_comaa5xpt1(ctx_66, 43, 0, 0);
                      NI32 X60Qx_1510 = emit_0_comaa5xpt1(ctx_66, 6, (*yf_0).d_00.nestTmpSlot_0, 0);
                      NI32 k_9 = 0;
                      {
                        while (NIM_TRUE){
                          NI32 X60Qx_1511 = len_3_I0v1j8d_comaa5xpt1(group_4);
                          if (k_9 < X60Qx_1511){
                            NI32 X60Qx_1512 = emit_0_comaa5xpt1(ctx_66, 5, (*yf_0).d_00.nestTmpSlot_0, 0);
                            Value_0_valzr1t4f X60Qtmp_123 = vInt_0_valzr1t4f(((NI64)k_9), 64);
                            NI32 X60Qx_1513 = addConst_0_comaa5xpt1(c_94, (&X60Qtmp_123));
                            NI32 X60Qx_1514 = emit_0_comaa5xpt1(ctx_66, 0, X60Qx_1513, 0);
                            NI32 X60Qx_1515 = emit_0_comaa5xpt1(ctx_66, 43, 0, 0);
                            NI32* X60Qx_1516 = getQ_7_Ir8kccm_comaa5xpt1(group_4, k_9);
                            NI32 X60Qx_1517 = emit_0_comaa5xpt1(ctx_66, 6, (*X60Qx_1516), 0);
                            inc_1_I6wjjge_aow2h993l1((&k_9));
                            eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_123));}
                          else {
                            break;}}}
                      whileStmtLabel_5: ;
                      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&X60Qtmp_122));}
                    inc_1_I6wjjge_aow2h993l1((&j_1));
                    eQdestroy_1_Iv9ij5i1_chu5m1rja1(group_4);}
                  else {
                    break;}}}
              whileStmtLabel_4: ;}}}
        eQdestroy_1_Ij4pznj1_comaa5xpt1(plan_3);}}
    consumeParRi_0_nifb6mq6y1(n_53);
    HSlice_0_I8tnmvh1_comaa5xpt1 X60Qx_1518 = ___1_Ico26mb_comaa5xpt1(((NI32)((*yf_0).d_00.consumerIdx_0 + 1)), ((NI32)1));
    seq_0_Iscf6bn_comaa5xpt1 savedInner_0 = getQ_17_Iuwh3901_comaa5xpt1((*ctx_66).d_00.loops_0, X60Qx_1518);
    setLen_0_Ivhuv1v1_comaa5xpt1((&(*ctx_66).d_00.loops_0), ((NI32)((*yf_0).d_00.consumerIdx_0 + 1)));
    void* X60Qx_1519 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1));
    X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_124 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1519);
    seq_0_Ift2sne_chu5m1rja1 X60Qx_1520 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
    seq_0_Ift2sne_chu5m1rja1 X60Qx_1521 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
    (*X60Qtmp_124) = (X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1){
      .r_00 = 0, .d_00 = (Loop_Obj_0_comaa5xpt1){
        .contTarget_0 = -1, .breaks_0 = X60Qx_1520, .continues_0 = X60Qx_1521, .label_0 = ((NU32)0u)}}
    ;
    add_0_Iuw4xx01_comaa5xpt1((&(*ctx_66).d_00.loops_0), X60Qtmp_124);
    X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1522 = getQ_7_Iklts1k_comaa5xpt1((*ctx_66).d_00.yields_0, ((NI32)((*ctx_66).d_00.yields_0.len_0 - ((NI32)((NI32)1)))));
    X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* savedYf_0 = eQdupQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_1522));
    NI32 X60Qx_1523 = len_3_I7uqqfu1_comaa5xpt1((*ctx_66).d_00.yields_0);
    setLen_0_I93919j1_comaa5xpt1((&(*ctx_66).d_00.yields_0), ((NI32)(X60Qx_1523 - 1)));
    Cursor_0_nifb6mq6y1 bc_5 = eQdup_0_nifb6mq6y1((*yf_0).d_00.bodyCur_0);
    compileStmt_1_comaa5xpt1(c_94, ctx_66, (&bc_5));
    X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_125 = savedYf_0;
    eQwasmovedQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1((&savedYf_0));
    add_0_Iype0e61_comaa5xpt1((&(*ctx_66).d_00.yields_0), X60Qtmp_125);
    X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1524 = getQ_7_I6yhgto_comaa5xpt1((*ctx_66).d_00.loops_0, ((NI32)((*ctx_66).d_00.loops_0.len_0 - ((NI32)((NI32)1)))));
    X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* bodyScope_0 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qx_1524));
    {
      openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_32 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*bodyScope_0).d_00.continues_0);
      NI32 X60Qlf_33 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1525 = len_6_I9632ti1_comaa5xpt1(X60Qlf_32);
          if (X60Qlf_33 < X60Qx_1525){
            {
              NI32* X60Qii_8 = getQ_10_I053icq_comaa5xpt1(X60Qlf_32, X60Qlf_33);
              NI32 X60Qx_1526 = len_3_Icgec691_comaa5xpt1((*ctx_66).d_00.code_0);
              patch_0_comaa5xpt1(ctx_66, (*X60Qii_8), X60Qx_1526);}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_33));}
          else {
            break;}}}
      whileStmtLabel_7: ;}
    forStmtLabel_6: ;
    {
      openArray_0_Inqs7yx_comaa5xpt1 X60Qlf_34 = toOpenArray_1_Ibqb4ob_comaa5xpt1((*bodyScope_0).d_00.breaks_0);
      NI32 X60Qlf_35 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1527 = len_6_I9632ti1_comaa5xpt1(X60Qlf_34);
          if (X60Qlf_35 < X60Qx_1527){
            {
              NI32* X60Qii_11 = getQ_10_I053icq_comaa5xpt1(X60Qlf_34, X60Qlf_35);
              X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1528 = getQ_7_I6yhgto_comaa5xpt1((*ctx_66).d_00.loops_0, (*yf_0).d_00.consumerIdx_0);
              add_0_I8kd4i4_comaa5xpt1((&(*(*X60Qx_1528)).d_00.breaks_0), (*X60Qii_11));}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_35));}
          else {
            break;}}}
      whileStmtLabel_10: ;}
    forStmtLabel_9: ;
    setLen_0_Ivhuv1v1_comaa5xpt1((&(*ctx_66).d_00.loops_0), ((NI32)((*yf_0).d_00.consumerIdx_0 + 1)));
    {
      openArray_0_I6xd9vz_comaa5xpt1 X60Qlf_36 = toOpenArray_1_Ibb6pci1_comaa5xpt1(savedInner_0);
      NI32 X60Qlf_37 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1529 = len_6_Ie5pl0g_comaa5xpt1(X60Qlf_36);
          if (X60Qlf_37 < X60Qx_1529){
            {
              X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qii_14 = getQ_10_Itsygq7_comaa5xpt1(X60Qlf_36, X60Qlf_37);
              X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qx_1530 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*X60Qii_14));
              add_0_Iuw4xx01_comaa5xpt1((&(*ctx_66).d_00.loops_0), X60Qx_1530);}
            inc_1_I6wjjge_aow2h993l1((&X60Qlf_37));}
          else {
            break;}}}
      whileStmtLabel_13: ;}
    forStmtLabel_12: ;
    eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(bodyScope_0);
    eQdestroy_0_nifb6mq6y1((&bc_5));
    eQdestroyQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(savedYf_0);
    eQdestroy_1_Irljx3e1_comaa5xpt1(savedInner_0);
    eQdestroyQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(yf_0);}
  else {
    inc_0_nifb6mq6y1(n_53);
    NifKind_0_nif81dubp1 X60Qx_1531 = kind_0_nifb6mq6y1((*n_53));
    if (X60Qx_1531 == 2){
      inc_0_nifb6mq6y1(n_53);
      NI32 X60Qx_1532 = emit_0_comaa5xpt1(ctx_66, 1, 0, 0);}
    else {
      NifKind_0_nif81dubp1 X60Qx_1533 = kind_0_nifb6mq6y1((*n_53));
      if (X60Qx_1533 == 12){
        NI32 X60Qx_1534 = emit_0_comaa5xpt1(ctx_66, 1, 0, 0);}
      else {
        compileExpr_1_comaa5xpt1(c_94, ctx_66, n_53);}}
    consumeParRi_0_nifb6mq6y1(n_53);
    NI32 X60Qx_1535 = emit_0_comaa5xpt1(ctx_66, 72, 0, 0);}
  goto X60Qsc_162;
  X60Qsc_142: ;
  inc_0_nifb6mq6y1(n_53);
  NB8 isKeepOvf_0 = NIM_FALSE;
  NB8 isCast_1 = NIM_FALSE;
  NB8 X60Qx_108;
  NifKind_0_nif81dubp1 X60Qx_1536 = kind_0_nifb6mq6y1((*n_53));
  if (X60Qx_1536 == 11){
    string_0_sysvq0asl X60Qtmp_126 = nodeTag_0_comaa5xpt1((*n_53));
    NB8 X60Qx_1537 = eqQ_20_sysvq0asl(X60Qtmp_126, (string_0_sysvq0asl){
      .bytes_0 = 1634889982u, .more_0 = (&strlit_0_I7023501325319911082_comaa5xpt1)}
    );
    X60Qx_108 = X60Qx_1537;
    nimStrDestroy(X60Qtmp_126);}
  else {
    X60Qx_108 = NIM_FALSE;}
  if (X60Qx_108){
    Cursor_0_nifb6mq6y1 p2_0 = eQdup_0_nifb6mq6y1((*n_53));
    inc_0_nifb6mq6y1((&p2_0));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_1538 = kind_0_nifb6mq6y1(p2_0);
        if ((!(X60Qx_1538 == 12))){
          NifKind_0_nif81dubp1 X60Qx_1539 = kind_0_nifb6mq6y1(p2_0);
          if (X60Qx_1539 == 11){
            string_0_sysvq0asl ptag_0 = nodeTag_0_comaa5xpt1(p2_0);
            NB8 X60Qx_1540 = eqQ_20_sysvq0asl(ptag_0, (string_0_sysvq0asl){
              .bytes_0 = 1701145598u, .more_0 = (&strlit_0_I10356331269374273950_comaa5xpt1)}
            );
            if (X60Qx_1540){
              isKeepOvf_0 = NIM_TRUE;}
            else {
              NB8 X60Qx_1541 = eqQ_20_sysvq0asl(ptag_0, (string_0_sysvq0asl){
                .bytes_0 = 1935762430u, .more_0 = (&strlit_0_I13909093427330098489_comaa5xpt1)}
              );
              if (X60Qx_1541){
                isCast_1 = NIM_TRUE;}}
            nimStrDestroy(ptag_0);}
          skip_0_nifb6mq6y1((&p2_0));}
        else {
          break;}}}
    whileStmtLabel_15: ;
    eQdestroy_0_nifb6mq6y1((&p2_0));}
  skip_0_nifb6mq6y1(n_53);
  NB8 X60Qx_1542;
  if (isKeepOvf_0){
    X60Qx_1542 = NIM_TRUE;}
  else {
    X60Qx_1542 = isCast_1;}
  if (X60Qx_1542){
    if (isKeepOvf_0){
      NI32 X60Qx_1543 = emit_0_comaa5xpt1(ctx_66, 16, 0, 0);}
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_1544 = kind_0_nifb6mq6y1((*n_53));
        if ((!(X60Qx_1544 == 12))){
          compileStmt_1_comaa5xpt1(c_94, ctx_66, n_53);}
        else {
          break;}}}
    whileStmtLabel_16: ;
    if (isKeepOvf_0){
      NI32 X60Qx_1545 = emit_0_comaa5xpt1(ctx_66, 17, 0, 0);}}
  else {
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_1546 = kind_0_nifb6mq6y1((*n_53));
        if ((!(X60Qx_1546 == 12))){
          skip_0_nifb6mq6y1(n_53);}
        else {
          break;}}}
    whileStmtLabel_17: ;}
  consumeParRi_0_nifb6mq6y1(n_53);
  goto X60Qsc_162;
  X60Qsc_143: ;
  inc_0_nifb6mq6y1(n_53);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1547 = kind_0_nifb6mq6y1((*n_53));
      if ((!(X60Qx_1547 == 12))){
        skip_0_nifb6mq6y1(n_53);}
      else {
        break;}}}
  whileStmtLabel_18: ;
  consumeParRi_0_nifb6mq6y1(n_53);
  NI32 X60Qx_1548 = emit_0_comaa5xpt1(ctx_66, 78, 0, 0);
  goto X60Qsc_162;
  X60Qsc_144: ;
  compileExpr_1_comaa5xpt1(c_94, ctx_66, n_53);
  NI32 X60Qx_1549 = emit_0_comaa5xpt1(ctx_66, 4, 0, 0);
  goto X60Qsc_162;
  X60Qsc_145: ;
  NB8 X60Qx_1550 = eqQ_20_sysvq0asl(tag_4, (string_0_sysvq0asl){
    .bytes_0 = 1668180478u, .more_0 = (&strlit_0_I14732757010146030568_comaa5xpt1)}
  );
  compileIncl_1_comaa5xpt1(c_94, ctx_66, n_53, X60Qx_1550);
  goto X60Qsc_162;
  X60Qsc_146: ;
  inc_0_nifb6mq6y1(n_53);
  compileAddr_1_comaa5xpt1(c_94, ctx_66, n_53);
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1551 = kind_0_nifb6mq6y1((*n_53));
      if ((!(X60Qx_1551 == 12))){
        skip_0_nifb6mq6y1(n_53);}
      else {
        break;}}}
  whileStmtLabel_19: ;
  consumeParRi_0_nifb6mq6y1(n_53);
  NI32 X60Qx_1552 = emit_0_comaa5xpt1(ctx_66, 15, 0, 0);
  goto X60Qsc_162;
  X60Qsc_163: ;
  NB8 X60Qx_1553 = isDeclTag_0_comaa5xpt1(tag_4);
  if (X60Qx_1553){
    skip_0_nifb6mq6y1(n_53);}
  else {
    NimonyExpr_0_nimry5ra91 ek_2 = exprKind_1_nim30udrv((*n_53));
    if ((!(ek_2 == 0))){
      compileExpr_1_comaa5xpt1(c_94, ctx_66, n_53);
      NI32 X60Qx_1554 = emit_0_comaa5xpt1(ctx_66, 4, 0, 0);}
    else {
      skip_0_nifb6mq6y1(n_53);}}
  X60Qsc_162: ;
  nimStrDestroy(tag_4);}
seq_0_In6doa_ast8ri79k slotSymsOf_0_comaa5xpt1(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_67){
  seq_0_In6doa_ast8ri79k result_46;
  eQwasMoved_1_I2k4kel_ast8ri79k((&result_46));
  eQdestroy_1_Iscb4i31_ast8ri79k(result_46);
  seq_0_In6doa_ast8ri79k X60Qx_1555 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  result_46 = X60Qx_1555;
  NI32 i_28 = 0;
  {
    while (i_28 < (*ctx_67).d_00.numLocals_0){
      add_0_I34il1q_comaa5xpt1((&result_46), ((NU32)0u));
      inc_1_I6wjjge_aow2h993l1((&i_28));}}
  whileStmtLabel_0: ;
  i_28 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1556 = len_3_I6y2imo_buiyylk1h1((*ctx_67).d_00.smap_0.keys_0);
      if (i_28 < X60Qx_1556){
        NI32* X60Qx_1557 = getQ_7_Ir8kccm_comaa5xpt1((*ctx_67).d_00.smap_0.vals_0, i_28);
        NI32 sl_0 = (*X60Qx_1557);
        NB8 X60Qx_1558;
        if (0 <= sl_0){
          NI32 X60Qx_1559 = len_3_I6y2imo_buiyylk1h1(result_46);
          X60Qx_1558 = (sl_0 < X60Qx_1559);}
        else {
          X60Qx_1558 = NIM_FALSE;}
        if (X60Qx_1558){
          NU32* X60Qx_1560 = getQ_7_I2v00yv1_buiyylk1h1((*ctx_67).d_00.smap_0.keys_0, i_28);
          putQ_7_Ia9tk91_comaa5xpt1((&result_46), sl_0, (*X60Qx_1560));}
        inc_1_I6wjjge_aow2h993l1((&i_28));}
      else {
        break;}}}
  whileStmtLabel_1: ;
  return result_46;}
Proc_0_chu5m1rja1 compileProc_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_95, Cursor_0_nifb6mq6y1 procCur_1){
  Proc_0_chu5m1rja1 result_47;
  eQwasmovedQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&result_47));
  Routine_0_decqocs071 r_7 = asRoutine_0_decqocs071(procCur_1, 1);
  NB8 passive_0 = routineIsPassive_0_comaa5xpt1(procCur_1);
  NB8 nested_0 = NIM_FALSE;
  NifKind_0_nif81dubp1 X60Qx_1561 = kind_0_nifb6mq6y1(r_7.name_0);
  if (X60Qx_1561 == 5){
    NU32 X60Qx_1562 = symId_0_nifb6mq6y1(r_7.name_0);
    NI32 X60Qx_1563 = get_0_comaa5xpt1((*c_95).d_00.nestedSyms_0, X60Qx_1562);
    nested_0 = (0 <= X60Qx_1563);}
  void* X60Qx_1564 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1));
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_127 = ((X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1564);
  seq_0_Izok7jt1_chu5m1rja1 X60Qx_1565 = newSeqUninit_0_I82j90d_chu5m1rja1(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1566 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1567 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1568 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Iscf6bn_comaa5xpt1 X60Qx_1569 = newSeqUninit_0_Ib8z3ow_comaa5xpt1(0);
  seq_0_I806bg1_comaa5xpt1 X60Qx_1570 = newSeqUninit_0_Iqckanu_comaa5xpt1(0);
  seq_0_Igm8woo1_comaa5xpt1 X60Qx_1571 = newSeqUninit_0_I8nq5k8_comaa5xpt1(0);
  (*X60Qtmp_127) = (X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1){
    .r_00 = 0, .d_00 = (ProcCtx_Obj_0_comaa5xpt1){
      .code_0 = X60Qx_1565, .codeLines_0 = X60Qx_1566, .curLine_0 = ((NI32)0), .smap_0 = (SymMap_0_comaa5xpt1){
        .keys_0 = X60Qx_1567, .vals_0 = X60Qx_1568}
      , .numLocals_0 = 0, .numParams_0 = 0, .resultSlot_0 = -1, .isTop_0 = NIM_FALSE, .isNested_0 = nested_0, .isPassive_0 = passive_0, .loops_0 = X60Qx_1569, .finallys_0 = X60Qx_1570, .yields_0 = X60Qx_1571, .guardSym_0 = ((NU32)0u)}}
  ;
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_68 = X60Qtmp_127;
  Cursor_0_nifb6mq6y1 p_8 = r_7.params_0;
  eQwasMoved_0_nifb6mq6y1((&r_7.params_0));
  NifKind_0_nif81dubp1 X60Qx_1572 = kind_0_nifb6mq6y1(p_8);
  if (X60Qx_1572 == 11){
    inc_0_nifb6mq6y1((&p_8));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_1573 = kind_0_nifb6mq6y1(p_8);
        if ((!(X60Qx_1573 == 12))){
          string_0_sysvq0asl X60Qtmp_128 = nodeTag_0_comaa5xpt1(p_8);
          NB8 X60Qx_1574 = eqQ_20_sysvq0asl(X60Qtmp_128, (string_0_sysvq0asl){
            .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I9792473688321036479_comaa5xpt1)}
          );
          if (X60Qx_1574){
            Local_0_decqocs071 loc_6 = asLocal_0_decqocs071(p_8, 1);
            NifKind_0_nif81dubp1 X60Qx_1575 = kind_0_nifb6mq6y1(loc_6.name_0);
            if (X60Qx_1575 == 5){
              NU32 X60Qx_1576 = symId_0_nifb6mq6y1(loc_6.name_0);
              put_0_comaa5xpt1((&(*ctx_68).d_00.smap_0), X60Qx_1576, (*ctx_68).d_00.numLocals_0);
              inc_1_I6wjjge_aow2h993l1((&(*ctx_68).d_00.numLocals_0));
              inc_1_I6wjjge_aow2h993l1((&(*ctx_68).d_00.numParams_0));}
            eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_6));}
          skip_0_nifb6mq6y1((&p_8));
          nimStrDestroy(X60Qtmp_128);}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  Cursor_0_nifb6mq6y1 body_0 = r_7.body_0;
  eQwasMoved_0_nifb6mq6y1((&r_7.body_0));
  NB8 X60Qx_109;
  NB8 X60Qx_1577;
  NifKind_0_nif81dubp1 X60Qx_1578 = kind_0_nifb6mq6y1(r_7.name_0);
  if (X60Qx_1578 == 5){
    NB8 X60Qx_1579 = hasImportc_0_hlc70y78v(r_7.pragmas_0);
    X60Qx_1577 = X60Qx_1579;}
  else {
    X60Qx_1577 = NIM_FALSE;}
  if (X60Qx_1577){
    NB8 X60Qx_110;
    NifKind_0_nif81dubp1 X60Qx_1580 = kind_0_nifb6mq6y1(body_0);
    if (X60Qx_1580 == 2){
      X60Qx_110 = NIM_TRUE;}
    else {
      NU32 X60Qx_1581 = symId_0_nifb6mq6y1(r_7.name_0);
      string_0_sysvq0asl X60Qtmp_129 = baseName_0_comaa5xpt1(X60Qx_1581);
      NB8 X60Qx_1582 = isInterceptedForeign_0_runot4689(X60Qtmp_129);
      X60Qx_110 = X60Qx_1582;
      nimStrDestroy(X60Qtmp_129);}
    X60Qx_109 = X60Qx_110;}
  else {
    X60Qx_109 = NIM_FALSE;}
  if (X60Qx_109){
    NU32 X60Qx_1583 = symId_0_nifb6mq6y1(r_7.name_0);
    string_0_sysvq0asl bnm_0 = baseName_0_comaa5xpt1(X60Qx_1583);
    string_0_sysvq0asl cname_2 = nimStrDup(bnm_0);
    string_0_sysvq0asl cn_1 = importcName_0_hlc70y78v(r_7.pragmas_0);
    NB8 X60Qx_1584;
    NB8 X60Qx_1585;
    NI32 X60Qx_1586 = len_4_sysvq0asl(cn_1);
    if (0 < X60Qx_1586){
      NB8 X60Qx_1587 = eqQ_20_sysvq0asl(cn_1, bnm_0);
      X60Qx_1585 = (!X60Qx_1587);}
    else {
      X60Qx_1585 = NIM_FALSE;}
    if (X60Qx_1585){
      NB8 X60Qx_1588 = isInterceptedForeign_0_runot4689(bnm_0);
      X60Qx_1584 = (!X60Qx_1588);}
    else {
      X60Qx_1584 = NIM_FALSE;}
    if (X60Qx_1584){
      nimStrDestroy(cname_2);
      cname_2 = cn_1;
      nimStrWasMoved((&cn_1));}
    NI32 k_10 = 0;
    {
      while (k_10 < (*ctx_68).d_00.numParams_0){
        NI32 X60Qx_1589 = emit_0_comaa5xpt1(ctx_68, 5, k_10, 0);
        inc_1_I6wjjge_aow2h993l1((&k_10));}}
    whileStmtLabel_1: ;
    NI32 X60Qx_1590 = addNative_0_comaa5xpt1(c_95, cname_2);
    NI32 X60Qx_1591 = emit_0_comaa5xpt1(ctx_68, 34, X60Qx_1590, (*ctx_68).d_00.numParams_0);
    NI32 X60Qx_1592 = emit_0_comaa5xpt1(ctx_68, 36, 0, 0);
    eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&result_47));
    seq_0_Izok7jt1_chu5m1rja1 X60Qx_1593 = eQdup_1_Ir0cadv1_chu5m1rja1((*ctx_68).d_00.code_0);
    seq_0_Ift2sne_chu5m1rja1 X60Qx_1594 = eQdup_1_Iplow11_chu5m1rja1((*ctx_68).d_00.codeLines_0);
    seq_0_In6doa_ast8ri79k X60Qx_1595 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
    result_47 = (Proc_0_chu5m1rja1){
      .code_0 = X60Qx_1593, .lines_0 = X60Qx_1594, .numParams_0 = (*ctx_68).d_00.numParams_0, .numLocals_0 = (*ctx_68).d_00.numLocals_0, .resultSlot_0 = (*ctx_68).d_00.resultSlot_0, .name_0 = (string_0_sysvq0asl){
        .bytes_0 = 0u, .more_0 = NIM_NIL}
      , .isPassive_0 = passive_0, .slotSyms_0 = X60Qx_1595}
    ;
    nimStrDestroy(cn_1);
    nimStrDestroy(cname_2);
    nimStrDestroy(bnm_0);
    eQdestroy_0_nifb6mq6y1((&body_0));
    eQdestroy_0_nifb6mq6y1((&p_8));
    eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(ctx_68);
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_7));
    return result_47;
    nimStrDestroy(cn_1);
    nimStrDestroy(cname_2);
    nimStrDestroy(bnm_0);}
  Cursor_0_nifb6mq6y1 scan_0 = eQdup_0_nifb6mq6y1(body_0);
  registerNestedRoutines_0_comaa5xpt1(c_95, (&scan_0));
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* X60Qx_1596 = eQdupQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(ctx_68);
  add_0_If3vc0y1_comaa5xpt1((&(*c_95).d_00.ctxStack_0), X60Qx_1596);
  compileStmt_1_comaa5xpt1(c_95, ctx_68, (&body_0));
  NI32 X60Qx_1597 = len_3_Ibv77kg1_comaa5xpt1((*c_95).d_00.ctxStack_0);
  setLen_0_Izc6r611_comaa5xpt1((&(*c_95).d_00.ctxStack_0), ((NI32)(X60Qx_1597 - 1)));
  if (0 <= (*ctx_68).d_00.resultSlot_0){
    NI32 X60Qx_1598 = emit_0_comaa5xpt1(ctx_68, 5, (*ctx_68).d_00.resultSlot_0, 0);}
  else {
    NI32 X60Qx_1599 = emit_0_comaa5xpt1(ctx_68, 1, 0, 0);}
  NI32 X60Qx_1600 = emit_0_comaa5xpt1(ctx_68, 36, 0, 0);
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&result_47));
  seq_0_Izok7jt1_chu5m1rja1 X60Qx_1601 = eQdup_1_Ir0cadv1_chu5m1rja1((*ctx_68).d_00.code_0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1602 = eQdup_1_Iplow11_chu5m1rja1((*ctx_68).d_00.codeLines_0);
  seq_0_In6doa_ast8ri79k X60Qx_1603 = slotSymsOf_0_comaa5xpt1(ctx_68);
  result_47 = (Proc_0_chu5m1rja1){
    .code_0 = X60Qx_1601, .lines_0 = X60Qx_1602, .numParams_0 = (*ctx_68).d_00.numParams_0, .numLocals_0 = (*ctx_68).d_00.numLocals_0, .resultSlot_0 = (*ctx_68).d_00.resultSlot_0, .name_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .isPassive_0 = passive_0, .slotSyms_0 = X60Qx_1603}
  ;
  eQdestroy_0_nifb6mq6y1((&scan_0));
  eQdestroy_0_nifb6mq6y1((&body_0));
  eQdestroy_0_nifb6mq6y1((&p_8));
  eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(ctx_68);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_7));
  return result_47;
  eQdestroy_0_nifb6mq6y1((&scan_0));
  eQdestroy_0_nifb6mq6y1((&body_0));
  eQdestroy_0_nifb6mq6y1((&p_8));
  eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(ctx_68);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_7));
  return result_47;}
NB8 isMethodSym_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_96, NU32 s_26){
  NB8 result_48;
  NI32 di_2 = symIndex_0_comaa5xpt1((*c_96).d_00.procDefSyms_0, s_26);
  if (0 <= di_2){
    Cursor_0_nifb6mq6y1* X60Qx_1604 = getQ_7_Iyegbq3_comaa5xpt1((*c_96).d_00.procDefCursors_0, di_2);
    string_0_sysvq0asl X60Qtmp_130 = nodeTag_0_comaa5xpt1((*X60Qx_1604));
    NB8 X60Qx_1605 = eqQ_20_sysvq0asl(X60Qtmp_130, (string_0_sysvq0asl){
      .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_comaa5xpt1)}
    );
    result_48 = X60Qx_1605;
    nimStrDestroy(X60Qtmp_130);
    return result_48;
    nimStrDestroy(X60Qtmp_130);}
  LoadResult_0_prorcx25w1 res_10 = tryLoadSymSafe_0_modzy18mg1(s_26);
  NB8 X60Qx_1606;
  if (res_10.status_0 == 3){
    NifKind_0_nif81dubp1 X60Qx_1607 = kind_0_nifb6mq6y1(res_10.decl_0);
    X60Qx_1606 = (X60Qx_1607 == 11);}
  else {
    X60Qx_1606 = NIM_FALSE;}
  if (X60Qx_1606){
    string_0_sysvq0asl X60Qtmp_131 = nodeTag_0_comaa5xpt1(res_10.decl_0);
    NB8 X60Qx_1608 = eqQ_20_sysvq0asl(X60Qtmp_131, (string_0_sysvq0asl){
      .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_comaa5xpt1)}
    );
    result_48 = X60Qx_1608;
    nimStrDestroy(X60Qtmp_131);
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_10);
    return result_48;
    nimStrDestroy(X60Qtmp_131);}
  result_48 = NIM_FALSE;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_10);
  return result_48;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_10);
  return result_48;}
NB8 routineExistsVM_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_97, NU32 s_27){
  NB8 result_49;
  NI32 X60Qx_1609 = symIndex_0_comaa5xpt1((*c_97).d_00.procDefSyms_0, s_27);
  if (0 <= X60Qx_1609){
    return NIM_TRUE;}
  LoadResult_0_prorcx25w1 res_11 = tryLoadSymSafe_0_modzy18mg1(s_27);
  NB8 X60Qx_1610;
  if (res_11.status_0 == 3){
    NimonySym_0_nimry5ra91 X60Qx_1611 = symKind_0_nim30udrv(res_11.decl_0);
    NB8 X60Qx_1612 = isRoutine_0_decqocs071(X60Qx_1611);
    X60Qx_1610 = X60Qx_1612;}
  else {
    X60Qx_1610 = NIM_FALSE;}
  result_49 = X60Qx_1610;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_11);
  return result_49;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_11);
  return result_49;}
NB8 symIsPassive_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_98, NU32 s_28){
  NB8 result_50;
  NI32 di_3 = symIndex_0_comaa5xpt1((*c_98).d_00.procDefSyms_0, s_28);
  if (0 <= di_3){
    Cursor_0_nifb6mq6y1* X60Qx_1613 = getQ_7_Iyegbq3_comaa5xpt1((*c_98).d_00.procDefCursors_0, di_3);
    NB8 X60Qx_1614 = routineIsPassive_0_comaa5xpt1((*X60Qx_1613));
    result_50 = X60Qx_1614;
    return result_50;}
  LoadResult_0_prorcx25w1 res_12 = tryLoadSymSafe_0_modzy18mg1(s_28);
  NB8 X60Qx_1615;
  NB8 X60Qx_1616;
  if (res_12.status_0 == 3){
    NimonySym_0_nimry5ra91 X60Qx_1617 = symKind_0_nim30udrv(res_12.decl_0);
    NB8 X60Qx_1618 = isRoutine_0_decqocs071(X60Qx_1617);
    X60Qx_1616 = X60Qx_1618;}
  else {
    X60Qx_1616 = NIM_FALSE;}
  if (X60Qx_1616){
    NB8 X60Qx_1619 = routineIsPassive_0_comaa5xpt1(res_12.decl_0);
    X60Qx_1615 = X60Qx_1619;}
  else {
    X60Qx_1615 = NIM_FALSE;}
  result_50 = X60Qx_1615;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_12);
  return result_50;
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_12);
  return result_50;}
NB8 firstParamContainer_1_comaa5xpt1(NU32 s_29){
  NB8 result_51;
  LoadResult_0_prorcx25w1 res_13 = tryLoadSymSafe_0_modzy18mg1(s_29);
  NB8 X60Qx_1620;
  if ((!(res_13.status_0 == 3))){
    X60Qx_1620 = NIM_TRUE;}
  else {
    NimonySym_0_nimry5ra91 X60Qx_1621 = symKind_0_nim30udrv(res_13.decl_0);
    NB8 X60Qx_1622 = isRoutine_0_decqocs071(X60Qx_1621);
    X60Qx_1620 = (!X60Qx_1622);}
  if (X60Qx_1620){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_13);
    return NIM_FALSE;}
  Routine_0_decqocs071 r_8 = asRoutine_0_decqocs071(res_13.decl_0, 1);
  Cursor_0_nifb6mq6y1 p_9 = r_8.params_0;
  eQwasMoved_0_nifb6mq6y1((&r_8.params_0));
  NifKind_0_nif81dubp1 X60Qx_1623 = kind_0_nifb6mq6y1(p_9);
  if ((!(X60Qx_1623 == 11))){
    eQdestroy_0_nifb6mq6y1((&p_9));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_8));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_13);
    return NIM_FALSE;}
  inc_0_nifb6mq6y1((&p_9));
  NB8 X60Qx_111;
  NifKind_0_nif81dubp1 X60Qx_1624 = kind_0_nifb6mq6y1(p_9);
  if ((!(X60Qx_1624 == 11))){
    X60Qx_111 = NIM_TRUE;}
  else {
    string_0_sysvq0asl X60Qtmp_132 = nodeTag_0_comaa5xpt1(p_9);
    NB8 X60Qx_1625 = eqQ_20_sysvq0asl(X60Qtmp_132, (string_0_sysvq0asl){
      .bytes_0 = 1918988542u, .more_0 = (&strlit_0_I9792473688321036479_comaa5xpt1)}
    );
    X60Qx_111 = (!X60Qx_1625);
    nimStrDestroy(X60Qtmp_132);}
  if (X60Qx_111){
    eQdestroy_0_nifb6mq6y1((&p_9));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_8));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_13);
    return NIM_FALSE;}
  Local_0_decqocs071 loc_7 = asLocal_0_decqocs071(p_9, 1);
  Cursor_0_nifb6mq6y1 t_18 = loc_7.typ_0;
  eQwasMoved_0_nifb6mq6y1((&loc_7.typ_0));
  {
    while (NIM_TRUE){
      NifKind_0_nif81dubp1 X60Qx_1626 = kind_0_nifb6mq6y1(t_18);
      if (X60Qx_1626 == 11){
        string_0_sysvq0asl tg_4 = nodeTag_0_comaa5xpt1(t_18);
        NB8 X60Qx_1627;
        NB8 X60Qx_1628;
        NB8 X60Qx_1629;
        NB8 X60Qx_1630;
        NB8 X60Qx_1631 = eqQ_20_sysvq0asl(tg_4, (string_0_sysvq0asl){
          .bytes_0 = 1953852675u, .more_0 = NIM_NIL}
        );
        if (X60Qx_1631){
          X60Qx_1630 = NIM_TRUE;}
        else {
          NB8 X60Qx_1632 = eqQ_20_sysvq0asl(tg_4, (string_0_sysvq0asl){
            .bytes_0 = 1852404734u, .more_0 = (&strlit_0_I5595596763809202512_comaa5xpt1)}
          );
          X60Qx_1630 = X60Qx_1632;}
        if (X60Qx_1630){
          X60Qx_1629 = NIM_TRUE;}
        else {
          NB8 X60Qx_1633 = eqQ_20_sysvq0asl(tg_4, (string_0_sysvq0asl){
            .bytes_0 = 1953853187u, .more_0 = NIM_NIL}
          );
          X60Qx_1629 = X60Qx_1633;}
        if (X60Qx_1629){
          X60Qx_1628 = NIM_TRUE;}
        else {
          NB8 X60Qx_1634 = eqQ_20_sysvq0asl(tg_4, (string_0_sysvq0asl){
            .bytes_0 = 1852140798u, .more_0 = (&strlit_0_I6008424852838151324_comaa5xpt1)}
          );
          X60Qx_1628 = X60Qx_1634;}
        if (X60Qx_1628){
          X60Qx_1627 = NIM_TRUE;}
        else {
          NB8 X60Qx_1635 = eqQ_20_sysvq0asl(tg_4, (string_0_sysvq0asl){
            .bytes_0 = 1920295934u, .more_0 = (&strlit_0_I17735862253056247523_comaa5xpt1)}
          );
          X60Qx_1627 = X60Qx_1635;}
        if (X60Qx_1627){
          inc_0_nifb6mq6y1((&t_18));}
        else {
          NB8 X60Qx_1636;
          NB8 X60Qx_1637;
          NB8 X60Qx_1638;
          NB8 X60Qx_1639 = eqQ_20_sysvq0asl(tg_4, (string_0_sysvq0asl){
            .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
          );
          if (X60Qx_1639){
            X60Qx_1638 = NIM_TRUE;}
          else {
            NB8 X60Qx_1640 = eqQ_20_sysvq0asl(tg_4, (string_0_sysvq0asl){
              .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_comaa5xpt1)}
            );
            X60Qx_1638 = X60Qx_1640;}
          if (X60Qx_1638){
            X60Qx_1637 = NIM_TRUE;}
          else {
            NB8 X60Qx_1641 = eqQ_20_sysvq0asl(tg_4, (string_0_sysvq0asl){
              .bytes_0 = 1918989822u, .more_0 = (&strlit_0_I2984705338531181753_buiyylk1h1)}
            );
            X60Qx_1637 = X60Qx_1641;}
          if (X60Qx_1637){
            X60Qx_1636 = NIM_TRUE;}
          else {
            NB8 X60Qx_1642 = eqQ_20_sysvq0asl(tg_4, (string_0_sysvq0asl){
              .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I14469962976530872646_comaa5xpt1)}
            );
            X60Qx_1636 = X60Qx_1642;}
          result_51 = X60Qx_1636;
          nimStrDestroy(tg_4);
          eQdestroy_0_nifb6mq6y1((&t_18));
          eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_7));
          eQdestroy_0_nifb6mq6y1((&p_9));
          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_8));
          eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_13);
          return result_51;}
        nimStrDestroy(tg_4);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NifKind_0_nif81dubp1 X60Qx_1643 = kind_0_nifb6mq6y1(t_18);
  if (X60Qx_1643 == 4){
    NU32 X60Qx_1644 = symId_0_nifb6mq6y1(t_18);
    string_0_sysvq0asl b_8 = baseName_0_comaa5xpt1(X60Qx_1644);
    NB8 X60Qx_1645;
    NB8 X60Qx_1646;
    NB8 X60Qx_1647;
    NB8 X60Qx_1648;
    NB8 X60Qx_1649;
    NB8 X60Qx_1650 = eqQ_20_sysvq0asl(b_8, (string_0_sysvq0asl){
      .bytes_0 = 1920234494u, .more_0 = (&strlit_0_I4511345809429878981_comaa5xpt1)}
    );
    if (X60Qx_1650){
      X60Qx_1649 = NIM_TRUE;}
    else {
      NB8 X60Qx_1651 = eqQ_20_sysvq0asl(b_8, (string_0_sysvq0asl){
        .bytes_0 = 1902473987u, .more_0 = NIM_NIL}
      );
      X60Qx_1649 = X60Qx_1651;}
    if (X60Qx_1649){
      X60Qx_1648 = NIM_TRUE;}
    else {
      NB8 X60Qx_1652 = eqQ_20_sysvq0asl(b_8, (string_0_sysvq0asl){
        .bytes_0 = 1953719294u, .more_0 = (&strlit_0_I14727864736786204059_buiyylk1h1)}
      );
      X60Qx_1648 = X60Qx_1652;}
    if (X60Qx_1648){
      X60Qx_1647 = NIM_TRUE;}
    else {
      NB8 X60Qx_1653 = eqQ_20_sysvq0asl(b_8, (string_0_sysvq0asl){
        .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I4271430978068613410_comaa5xpt1)}
      );
      X60Qx_1647 = X60Qx_1653;}
    if (X60Qx_1647){
      X60Qx_1646 = NIM_TRUE;}
    else {
      NB8 X60Qx_1654 = eqQ_20_sysvq0asl(b_8, (string_0_sysvq0asl){
        .bytes_0 = 1701867518u, .more_0 = (&strlit_0_I14469962976530872646_comaa5xpt1)}
      );
      X60Qx_1646 = X60Qx_1654;}
    if (X60Qx_1646){
      X60Qx_1645 = NIM_TRUE;}
    else {
      NB8 X60Qx_1655 = eqQ_20_sysvq0asl(b_8, (string_0_sysvq0asl){
        .bytes_0 = 1920098814u, .more_0 = (&strlit_0_I1177603226064417776_comaa5xpt1)}
      );
      X60Qx_1645 = X60Qx_1655;}
    result_51 = X60Qx_1645;
    nimStrDestroy(b_8);
    eQdestroy_0_nifb6mq6y1((&t_18));
    eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_7));
    eQdestroy_0_nifb6mq6y1((&p_9));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_8));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_13);
    return result_51;
    nimStrDestroy(b_8);}
  result_51 = NIM_FALSE;
  eQdestroy_0_nifb6mq6y1((&t_18));
  eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_7));
  eQdestroy_0_nifb6mq6y1((&p_9));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_8));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_13);
  return result_51;
  eQdestroy_0_nifb6mq6y1((&t_18));
  eQdestroyQ_SX4cocal0decqocs071_0_decqocs071((&loc_7));
  eQdestroy_0_nifb6mq6y1((&p_9));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_8));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_13);
  return result_51;}
NB8 returnsMutLocation_1_comaa5xpt1(NU32 s_30){
  NB8 result_52;
  LoadResult_0_prorcx25w1 res_14 = tryLoadSymSafe_0_modzy18mg1(s_30);
  NB8 X60Qx_1656;
  if ((!(res_14.status_0 == 3))){
    X60Qx_1656 = NIM_TRUE;}
  else {
    NimonySym_0_nimry5ra91 X60Qx_1657 = symKind_0_nim30udrv(res_14.decl_0);
    NB8 X60Qx_1658 = isRoutine_0_decqocs071(X60Qx_1657);
    X60Qx_1656 = (!X60Qx_1658);}
  if (X60Qx_1656){
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_14);
    return NIM_FALSE;}
  Routine_0_decqocs071 r_9 = asRoutine_0_decqocs071(res_14.decl_0, 1);
  Cursor_0_nifb6mq6y1 t_19 = r_9.retType_0;
  eQwasMoved_0_nifb6mq6y1((&r_9.retType_0));
  NifKind_0_nif81dubp1 X60Qx_1659 = kind_0_nifb6mq6y1(t_19);
  if (X60Qx_1659 == 11){
    string_0_sysvq0asl tg_5 = nodeTag_0_comaa5xpt1(t_19);
    NB8 X60Qx_1660;
    NB8 X60Qx_1661;
    NB8 X60Qx_1662;
    NB8 X60Qx_1663 = eqQ_20_sysvq0asl(tg_5, (string_0_sysvq0asl){
      .bytes_0 = 1953852675u, .more_0 = NIM_NIL}
    );
    if (X60Qx_1663){
      X60Qx_1662 = NIM_TRUE;}
    else {
      NB8 X60Qx_1664 = eqQ_20_sysvq0asl(tg_5, (string_0_sysvq0asl){
        .bytes_0 = 1918989827u, .more_0 = NIM_NIL}
      );
      X60Qx_1662 = X60Qx_1664;}
    if (X60Qx_1662){
      X60Qx_1661 = NIM_TRUE;}
    else {
      NB8 X60Qx_1665 = eqQ_20_sysvq0asl(tg_5, (string_0_sysvq0asl){
        .bytes_0 = 1953853187u, .more_0 = NIM_NIL}
      );
      X60Qx_1661 = X60Qx_1665;}
    if (X60Qx_1661){
      X60Qx_1660 = NIM_TRUE;}
    else {
      NB8 X60Qx_1666 = eqQ_20_sysvq0asl(tg_5, (string_0_sysvq0asl){
        .bytes_0 = 1852140798u, .more_0 = (&strlit_0_I6008424852838151324_comaa5xpt1)}
      );
      X60Qx_1660 = X60Qx_1666;}
    result_52 = X60Qx_1660;
    nimStrDestroy(tg_5);
    eQdestroy_0_nifb6mq6y1((&t_19));
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_9));
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_14);
    return result_52;
    nimStrDestroy(tg_5);}
  result_52 = NIM_FALSE;
  eQdestroy_0_nifb6mq6y1((&t_19));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_9));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_14);
  return result_52;
  eQdestroy_0_nifb6mq6y1((&t_19));
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_9));
  eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_14);
  return result_52;}
NI32 procDefIdx_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_99, NU32 s_31){
  NI32 result_53;
  result_53 = -1;
  NI32 i_30 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1667 = len_3_I6y2imo_buiyylk1h1((*c_99).d_00.procDefSyms_0);
      if (i_30 < X60Qx_1667){
        NU32* X60Qx_1668 = getQ_7_I2v00yv1_buiyylk1h1((*c_99).d_00.procDefSyms_0, i_30);
        NB8 X60Qx_1669 = eqQ_0_nifh7u8pu1((*X60Qx_1668), s_31);
        if (X60Qx_1669){
          if (result_53 < 0){
            result_53 = i_30;}
          Cursor_0_nifb6mq6y1* X60Qx_1670 = getQ_7_Iyegbq3_comaa5xpt1((*c_99).d_00.procDefCursors_0, i_30);
          Routine_0_decqocs071 r_10 = asRoutine_0_decqocs071((*X60Qx_1670), 1);
          NifKind_0_nif81dubp1 X60Qx_1671 = kind_0_nifb6mq6y1(r_10.body_0);
          if ((!(X60Qx_1671 == 2))){
            eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_10));
            return i_30;}
          eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_10));}
        inc_1_I6wjjge_aow2h993l1((&i_30));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  return result_53;}
X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1 foreignLeafOf_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_100, NU32 s_32){
  X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1 result_54;
  eQwasmovedQ_AtupleAboolZSstring0sysvq0asl_0_comaa5xpt1((&result_54));
  eQdestroyQ_AtupleAboolZSstring0sysvq0asl_0_comaa5xpt1(result_54);
  result_54 = (X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1){
    .fld_0 = NIM_FALSE, .fld_1 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}}
  ;
  Cursor_0_nifb6mq6y1 cur_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
  ;
  NB8 have_0 = NIM_FALSE;
  NI32 di_4 = symIndex_0_comaa5xpt1((*c_100).d_00.procDefSyms_0, s_32);
  if (0 <= di_4){
    eQdestroy_0_nifb6mq6y1((&cur_4));
    Cursor_0_nifb6mq6y1* X60Qx_1672 = getQ_7_Iyegbq3_comaa5xpt1((*c_100).d_00.procDefCursors_0, di_4);
    Cursor_0_nifb6mq6y1 X60Qx_1673 = eQdup_0_nifb6mq6y1((*X60Qx_1672));
    cur_4 = X60Qx_1673;
    have_0 = NIM_TRUE;}
  else {
    LoadResult_0_prorcx25w1 res_15 = tryLoadSymSafe_0_modzy18mg1(s_32);
    NB8 X60Qx_1674;
    if (res_15.status_0 == 3){
      NimonySym_0_nimry5ra91 X60Qx_1675 = symKind_0_nim30udrv(res_15.decl_0);
      NB8 X60Qx_1676 = isRoutine_0_decqocs071(X60Qx_1675);
      X60Qx_1674 = X60Qx_1676;}
    else {
      X60Qx_1674 = NIM_FALSE;}
    if (X60Qx_1674){
      eQdestroy_0_nifb6mq6y1((&cur_4));
      cur_4 = res_15.decl_0;
      eQwasMoved_0_nifb6mq6y1((&res_15.decl_0));
      have_0 = NIM_TRUE;}
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_15);}
  if ((!have_0)){
    eQdestroy_0_nifb6mq6y1((&cur_4));
    return result_54;}
  Routine_0_decqocs071 r_11 = asRoutine_0_decqocs071(cur_4, 1);
  NB8 X60Qx_1677;
  NifKind_0_nif81dubp1 X60Qx_1678 = kind_0_nifb6mq6y1(r_11.name_0);
  if ((!(X60Qx_1678 == 5))){
    X60Qx_1677 = NIM_TRUE;}
  else {
    NB8 X60Qx_1679 = hasImportc_0_hlc70y78v(r_11.pragmas_0);
    X60Qx_1677 = (!X60Qx_1679);}
  if (X60Qx_1677){
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_11));
    eQdestroy_0_nifb6mq6y1((&cur_4));
    return result_54;}
  NU32 X60Qx_1680 = symId_0_nifb6mq6y1(r_11.name_0);
  string_0_sysvq0asl bnm_1 = baseName_0_comaa5xpt1(X60Qx_1680);
  NB8 X60Qx_1681;
  NifKind_0_nif81dubp1 X60Qx_1682 = kind_0_nifb6mq6y1(r_11.body_0);
  if ((!(X60Qx_1682 == 2))){
    NB8 X60Qx_1683 = isInterceptedForeign_0_runot4689(bnm_1);
    X60Qx_1681 = (!X60Qx_1683);}
  else {
    X60Qx_1681 = NIM_FALSE;}
  if (X60Qx_1681){
    nimStrDestroy(bnm_1);
    eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_11));
    eQdestroy_0_nifb6mq6y1((&cur_4));
    return result_54;}
  string_0_sysvq0asl cname_3 = nimStrDup(bnm_1);
  string_0_sysvq0asl cn_2 = importcName_0_hlc70y78v(r_11.pragmas_0);
  NB8 X60Qx_1684;
  NB8 X60Qx_1685;
  NI32 X60Qx_1686 = len_4_sysvq0asl(cn_2);
  if (0 < X60Qx_1686){
    NB8 X60Qx_1687 = eqQ_20_sysvq0asl(cn_2, bnm_1);
    X60Qx_1685 = (!X60Qx_1687);}
  else {
    X60Qx_1685 = NIM_FALSE;}
  if (X60Qx_1685){
    NB8 X60Qx_1688 = isInterceptedForeign_0_runot4689(bnm_1);
    X60Qx_1684 = (!X60Qx_1688);}
  else {
    X60Qx_1684 = NIM_FALSE;}
  if (X60Qx_1684){
    nimStrDestroy(cname_3);
    cname_3 = cn_2;
    nimStrWasMoved((&cn_2));}
  eQdestroyQ_AtupleAboolZSstring0sysvq0asl_0_comaa5xpt1(result_54);
  string_0_sysvq0asl X60Qtmp_133 = cname_3;
  nimStrWasMoved((&cname_3));
  result_54 = (X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1){
    .fld_0 = NIM_TRUE, .fld_1 = X60Qtmp_133}
  ;
  nimStrDestroy(cn_2);
  nimStrDestroy(cname_3);
  nimStrDestroy(bnm_1);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_11));
  eQdestroy_0_nifb6mq6y1((&cur_4));
  return result_54;
  nimStrDestroy(cn_2);
  nimStrDestroy(cname_3);
  nimStrDestroy(bnm_1);
  eQdestroyQ_SX52outine0decqocs071_0_decqocs071((&r_11));
  eQdestroy_0_nifb6mq6y1((&cur_4));
  return result_54;}
NI32 getProcIdx_1_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_101, NU32 s_33){
  NI32 result_55;
  NI32 existing_0 = get_0_comaa5xpt1((*c_101).d_00.pmap_0, s_33);
  if (0 <= existing_0){
    return existing_0;}
  NI32 idx_6 = len_3_I05nxx61_comaa5xpt1((*c_101).d_00.procs_0);
  put_0_comaa5xpt1((&(*c_101).d_00.pmap_0), s_33, idx_6);
  seq_0_Izok7jt1_chu5m1rja1 X60Qx_1689 = newSeqUninit_0_I82j90d_chu5m1rja1(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1690 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1691 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  add_0_Iss439i1_comaa5xpt1((&(*c_101).d_00.procs_0), (Proc_0_chu5m1rja1){
    .code_0 = X60Qx_1689, .lines_0 = X60Qx_1690, .numParams_0 = 0, .numLocals_0 = 0, .resultSlot_0 = -1, .name_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .isPassive_0 = NIM_FALSE, .slotSyms_0 = X60Qx_1691}
  );
  Cursor_0_nifb6mq6y1 cur_5 = (Cursor_0_nifb6mq6y1){
    .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
  ;
  NB8 found_1 = NIM_FALSE;
  NI32 di_5 = procDefIdx_0_comaa5xpt1(c_101, s_33);
  if (0 <= di_5){
    eQdestroy_0_nifb6mq6y1((&cur_5));
    Cursor_0_nifb6mq6y1* X60Qx_1692 = getQ_7_Iyegbq3_comaa5xpt1((*c_101).d_00.procDefCursors_0, di_5);
    Cursor_0_nifb6mq6y1 X60Qx_1693 = eQdup_0_nifb6mq6y1((*X60Qx_1692));
    cur_5 = X60Qx_1693;
    found_1 = NIM_TRUE;}
  else {
    LoadResult_0_prorcx25w1 res_16 = tryLoadSymSafe_0_modzy18mg1(s_33);
    NB8 X60Qx_1694;
    if (res_16.status_0 == 3){
      NimonySym_0_nimry5ra91 X60Qx_1695 = symKind_0_nim30udrv(res_16.decl_0);
      NB8 X60Qx_1696 = isRoutine_0_decqocs071(X60Qx_1695);
      X60Qx_1694 = X60Qx_1696;}
    else {
      X60Qx_1694 = NIM_FALSE;}
    if (X60Qx_1694){
      eQdestroy_0_nifb6mq6y1((&cur_5));
      cur_5 = res_16.decl_0;
      eQwasMoved_0_nifb6mq6y1((&res_16.decl_0));
      found_1 = NIM_TRUE;}
    eQdestroyQ_SX4coadX52esult0prorcx25w1_0_prorcx25w1(res_16);}
  if (found_1){
    Proc_0_chu5m1rja1 p_10 = compileProc_1_comaa5xpt1(c_101, cur_5);
    string_0_sysvq0asl* X60Qlhs_134 = (&p_10.name_0);
    nimStrDestroy((*X60Qlhs_134));
    string_0_sysvq0asl X60Qx_1697 = baseName_0_comaa5xpt1(s_33);
    (*X60Qlhs_134) = X60Qx_1697;
    Proc_0_chu5m1rja1 X60Qtmp_135 = p_10;
    eQwasmovedQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&p_10));
    putQ_7_I5scqr1_comaa5xpt1((&(*c_101).d_00.procs_0), idx_6, X60Qtmp_135);
    eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&p_10));}
  eQdestroy_0_nifb6mq6y1((&cur_5));
  return idx_6;
  eQdestroy_0_nifb6mq6y1((&cur_5));
  return result_55;
  eQdestroy_0_nifb6mq6y1((&cur_5));
  return result_55;}
NB8 methodTableHas_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_102, NU32 s_34){
  NB8 result_56;
  NI32 i_32 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1698 = len_3_I2qk2yu1_comaa5xpt1((*c_102).d_00.methodTable_0);
      if (i_32 < X60Qx_1698){
        MethodEntry_0_chu5m1rja1* X60Qx_1699 = getQ_7_I8226yy1_comaa5xpt1((*c_102).d_00.methodTable_0, i_32);
        NB8 X60Qx_1700 = eqQ_0_nifh7u8pu1((*X60Qx_1699).sym_0, s_34);
        if (X60Qx_1700){
          return NIM_TRUE;}
        inc_1_I6wjjge_aow2h993l1((&i_32));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  result_56 = NIM_FALSE;
  return result_56;}
void registerTypeVtable_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_103, NU32 t_0, SymMap_0_comaa5xpt1* seen_0){
  NU32 cur_6 = t_0;
  NI32 depth_2 = 0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_1701;
      if (depth_2 < 64){
        NB8 X60Qx_1702 = eqQ_0_nifh7u8pu1(cur_6, ((NU32)0u));
        X60Qx_1701 = (!X60Qx_1702);}
      else {
        X60Qx_1701 = NIM_FALSE;}
      if (X60Qx_1701){
        NI32 X60Qx_1703 = get_0_comaa5xpt1((*seen_0), cur_6);
        if (0 <= X60Qx_1703){
          return;}
        put_0_comaa5xpt1(seen_0, cur_6, 1);
        {
          seq_0_Idl3iy1_comaa5xpt1 X60Qtmp_136 = loadVTable_0_vtanlalcx(cur_6);
          openArray_0_In1h8lr1_comaa5xpt1 X60Qlf_38 = toOpenArray_1_Ivm9z5a_comaa5xpt1(X60Qtmp_136);
          NI32 X60Qlf_39 = 0;
          {
            while (NIM_TRUE){
              NI32 X60Qx_1704 = len_6_I8gnayb_comaa5xpt1(X60Qlf_38);
              if (X60Qlf_39 < X60Qx_1704){
                {
                  MethodIndexEntry_0_sempjk6bn1* X60Qii_3 = getQ_10_Izev5kw1_comaa5xpt1(X60Qlf_38, X60Qlf_39);
                  NB8 X60Qx_1705;
                  NB8 X60Qx_1706 = isGenericRoutine_0_runot4689((*X60Qii_3).fn_0);
                  if ((!X60Qx_1706)){
                    NB8 X60Qx_1707 = methodTableHas_0_comaa5xpt1(c_103, (*X60Qii_3).fn_0);
                    X60Qx_1705 = (!X60Qx_1707);}
                  else {
                    X60Qx_1705 = NIM_FALSE;}
                  if (X60Qx_1705){
                    NI32 X60Qii_4 = getProcIdx_1_comaa5xpt1(c_103, (*X60Qii_3).fn_0);
                    add_0_I3fda3s1_comaa5xpt1((&(*c_103).d_00.methodTable_0), (MethodEntry_0_chu5m1rja1){
                      .sym_0 = (*X60Qii_3).fn_0, .idx_0 = X60Qii_4}
                    );}}
                inc_1_I6wjjge_aow2h993l1((&X60Qlf_39));}
              else {
                break;}}}
          whileStmtLabel_2: ;
          eQdestroy_1_Iph9dp4_comaa5xpt1(X60Qtmp_136);}
        forStmtLabel_1: ;
        NU32 b_9 = objBaseSym_0_runot4689(cur_6);
        NB8 X60Qx_1708 = eqQ_0_nifh7u8pu1(b_9, cur_6);
        if (X60Qx_1708){
          goto whileStmtLabel_0;}
        cur_6 = b_9;
        inc_1_I6wjjge_aow2h993l1((&depth_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;}
void registerAllVtables_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_104){
  seq_0_In6doa_ast8ri79k X60Qx_1709 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1710 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  SymMap_0_comaa5xpt1 seen_1 = (SymMap_0_comaa5xpt1){
    .keys_0 = X60Qx_1709, .vals_0 = X60Qx_1710}
  ;
  NB8 changed_0 = NIM_TRUE;
  {
    while (changed_0){
      changed_0 = NIM_FALSE;
      seq_0_In6doa_ast8ri79k types_0 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
      {
        openArray_0_Iz8j0ra_comaa5xpt1 X60Qlf_40 = toOpenArray_1_Ipyn7lx1_comaa5xpt1((*c_104).d_00.objInfos_0);
        NI32 X60Qlf_41 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1711 = len_6_Io9vvx7_comaa5xpt1(X60Qlf_40);
            if (X60Qlf_41 < X60Qx_1711){
              {
                ObjInfo_0_chu5m1rja1* X60Qii_3 = getQ_10_Ij5s4n11_comaa5xpt1(X60Qlf_40, X60Qlf_41);
                add_0_I34il1q_comaa5xpt1((&types_0), (*X60Qii_3).typeSym_0);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_41));}
            else {
              break;}}}
        whileStmtLabel_2: ;}
      forStmtLabel_1: ;
      {
        openArray_0_I94odo91_comaa5xpt1 X60Qlf_42 = toOpenArray_1_Itwyxk01_comaa5xpt1((*c_104).d_00.objSpecs_0);
        NI32 X60Qlf_43 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1712 = len_6_I7v6wrd_comaa5xpt1(X60Qlf_42);
            if (X60Qlf_43 < X60Qx_1712){
              {
                ObjSpec_0_chu5m1rja1* X60Qii_6 = getQ_10_I3bn8xm1_comaa5xpt1(X60Qlf_42, X60Qlf_43);
                add_0_I34il1q_comaa5xpt1((&types_0), (*X60Qii_6).typeSym_0);}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_43));}
            else {
              break;}}}
        whileStmtLabel_5: ;}
      forStmtLabel_4: ;
      {
        openArray_0_Ir53qdx_comaa5xpt1 X60Qlf_44 = toOpenArray_1_I02c2wz_comaa5xpt1((*c_104).d_00.typeSyms_0);
        NI32 X60Qlf_45 = 0;
        {
          while (NIM_TRUE){
            NI32 X60Qx_1713 = len_6_Ijqv54i_comaa5xpt1(X60Qlf_44);
            if (X60Qlf_45 < X60Qx_1713){
              {
                NU32* X60Qii_9 = getQ_10_Ibernwj1_comaa5xpt1(X60Qlf_44, X60Qlf_45);
                add_0_I34il1q_comaa5xpt1((&types_0), (*X60Qii_9));}
              inc_1_I6wjjge_aow2h993l1((&X60Qlf_45));}
            else {
              break;}}}
        whileStmtLabel_8: ;}
      forStmtLabel_7: ;
      NI32 ti_0 = 0;
      {
        while (NIM_TRUE){
          NI32 X60Qx_1714 = len_3_I6y2imo_buiyylk1h1(types_0);
          if (ti_0 < X60Qx_1714){
            NU32* X60Qx_1715 = getQ_7_I2v00yv1_buiyylk1h1(types_0, ti_0);
            NU32 t_20 = (*X60Qx_1715);
            NB8 X60Qx_1716;
            NB8 X60Qx_1717 = eqQ_0_nifh7u8pu1(t_20, ((NU32)0u));
            if ((!X60Qx_1717)){
              NI32 X60Qx_1718 = get_0_comaa5xpt1(seen_1, t_20);
              X60Qx_1716 = (X60Qx_1718 < 0);}
            else {
              X60Qx_1716 = NIM_FALSE;}
            if (X60Qx_1716){
              registerTypeVtable_0_comaa5xpt1(c_104, t_20, (&seen_1));
              changed_0 = NIM_TRUE;}
            inc_1_I6wjjge_aow2h993l1((&ti_0));}
          else {
            break;}}}
      whileStmtLabel_10: ;
      eQdestroy_1_Iscb4i31_ast8ri79k(types_0);}}
  whileStmtLabel_0: ;
  eQdestroyQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1(seen_1);}
Proc_0_chu5m1rja1 compileTopStmts_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_105, Cursor_0_nifb6mq6y1 root_1){
  Proc_0_chu5m1rja1 result_57;
  eQwasmovedQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&result_57));
  void* X60Qx_1719 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1));
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_137 = ((X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1719);
  seq_0_Izok7jt1_chu5m1rja1 X60Qx_1720 = newSeqUninit_0_I82j90d_chu5m1rja1(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1721 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1722 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1723 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Iscf6bn_comaa5xpt1 X60Qx_1724 = newSeqUninit_0_Ib8z3ow_comaa5xpt1(0);
  seq_0_I806bg1_comaa5xpt1 X60Qx_1725 = newSeqUninit_0_Iqckanu_comaa5xpt1(0);
  seq_0_Igm8woo1_comaa5xpt1 X60Qx_1726 = newSeqUninit_0_I8nq5k8_comaa5xpt1(0);
  (*X60Qtmp_137) = (X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1){
    .r_00 = 0, .d_00 = (ProcCtx_Obj_0_comaa5xpt1){
      .code_0 = X60Qx_1720, .codeLines_0 = X60Qx_1721, .curLine_0 = ((NI32)0), .smap_0 = (SymMap_0_comaa5xpt1){
        .keys_0 = X60Qx_1722, .vals_0 = X60Qx_1723}
      , .numLocals_0 = 0, .numParams_0 = 0, .resultSlot_0 = -1, .isTop_0 = NIM_TRUE, .isNested_0 = NIM_FALSE, .isPassive_0 = NIM_FALSE, .loops_0 = X60Qx_1724, .finallys_0 = X60Qx_1725, .yields_0 = X60Qx_1726, .guardSym_0 = ((NU32)0u)}}
  ;
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* ctx_69 = X60Qtmp_137;
  Cursor_0_nifb6mq6y1 n_55 = eQdup_0_nifb6mq6y1(root_1);
  NifKind_0_nif81dubp1 X60Qx_1727 = kind_0_nifb6mq6y1(n_55);
  if (X60Qx_1727 == 11){
    inc_0_nifb6mq6y1((&n_55));
    {
      while (NIM_TRUE){
        NifKind_0_nif81dubp1 X60Qx_1728 = kind_0_nifb6mq6y1(n_55);
        if ((!(X60Qx_1728 == 12))){
          {
            NifKind_0_nif81dubp1 X60Qx_1729 = kind_0_nifb6mq6y1(n_55);
            if ((!(X60Qx_1729 == 11))){
              inc_0_nifb6mq6y1((&n_55));
              goto continueLabel_1;}
            string_0_sysvq0asl tag_5 = nodeTag_0_comaa5xpt1(n_55);
            NB8 X60Qx_1730;
            NB8 X60Qx_1731 = isDeclTag_0_comaa5xpt1(tag_5);
            if (X60Qx_1731){
              X60Qx_1730 = NIM_TRUE;}
            else {
              NimonySym_0_nimry5ra91 X60Qx_1732 = symKind_0_nim30udrv(n_55);
              NB8 X60Qx_1733 = isRoutine_0_decqocs071(X60Qx_1732);
              X60Qx_1730 = X60Qx_1733;}
            if (X60Qx_1730){
              skip_0_nifb6mq6y1((&n_55));}
            else {
              compileStmt_1_comaa5xpt1(c_105, ctx_69, (&n_55));}
            nimStrDestroy(tag_5);}
          continueLabel_1: ;}
        else {
          break;}}}
    whileStmtLabel_0: ;}
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&result_57));
  seq_0_Izok7jt1_chu5m1rja1 X60Qx_1734 = eQdup_1_Ir0cadv1_chu5m1rja1((*ctx_69).d_00.code_0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1735 = eQdup_1_Iplow11_chu5m1rja1((*ctx_69).d_00.codeLines_0);
  seq_0_In6doa_ast8ri79k X60Qx_1736 = slotSymsOf_0_comaa5xpt1(ctx_69);
  result_57 = (Proc_0_chu5m1rja1){
    .code_0 = X60Qx_1734, .lines_0 = X60Qx_1735, .numParams_0 = 0, .numLocals_0 = (*ctx_69).d_00.numLocals_0, .resultSlot_0 = -1, .name_0 = (string_0_sysvq0asl){
      .bytes_0 = 0u, .more_0 = NIM_NIL}
    , .isPassive_0 = NIM_FALSE, .slotSyms_0 = X60Qx_1736}
  ;
  eQdestroy_0_nifb6mq6y1((&n_55));
  eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(ctx_69);
  return result_57;
  eQdestroy_0_nifb6mq6y1((&n_55));
  eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(ctx_69);
  return result_57;}
VmProgram_0_chu5m1rja1 compileModule_0_comaa5xpt1(Cursor_0_nifb6mq6y1 root_2, openArray_0_Imqex5f1_comaa5xpt1 importRoots_0){
  VmProgram_0_chu5m1rja1 result_59;
  eQwasmovedQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1((&result_59));
  void* X60Qx_1753 = allocFixed_0_sysvq0asl(sizeof(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1));
  X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* X60Qtmp_141 = ((X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1*)X60Qx_1753);
  seq_0_Inaua171_chu5m1rja1 X60Qx_1754 = newSeqUninit_0_Isa1q0a_chu5m1rja1(0);
  seq_0_I50urnw_chu5m1rja1 X60Qx_1755 = newSeqUninit_0_I8oufjc_chu5m1rja1(0);
  seq_0_Ie9rikd_chu5m1rja1 X60Qx_1756 = newSeqUninit_0_Iqh1pff1_chu5m1rja1(0);
  seq_0_Iknt7a3_chu5m1rja1 X60Qx_1757 = newSeqUninit_0_I16oi801_chu5m1rja1(0);
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_1758 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  seq_0_In6doa_ast8ri79k X60Qx_1759 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Id5h4uf_chu5m1rja1 X60Qx_1760 = newSeqUninit_0_Ii76u2d1_chu5m1rja1(0);
  seq_0_I2neof81_chu5m1rja1 X60Qx_1761 = newSeqUninit_0_In1bf9z_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1762 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Isww99s_chu5m1rja1 X60Qx_1763 = newSeqUninit_0_Iuxy4sp1_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1764 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_In6doa_ast8ri79k X60Qx_1765 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1766 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Iioxqbu_chu5m1rja1 X60Qx_1767 = newSeqUninit_0_Iqy0tna1_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1768 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1769 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1770 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Isyzizu1_comaa5xpt1 X60Qx_1771 = newSeqUninit_0_Iikx2qh1_comaa5xpt1(0);
  seq_0_Ir067xu1_chu5m1rja1 X60Qx_1772 = newSeqUninit_0_Im7kjnr_chu5m1rja1(0);
  seq_0_I88k8j01_chu5m1rja1 X60Qx_1773 = newSeqUninit_0_I0s7mv21_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1774 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1775 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_1776 = newSeqUninit_0_Im3cqd9_ast8ri79k(0);
  seq_0_In6doa_ast8ri79k X60Qx_1777 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1778 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1779 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ik8dusv_comaa5xpt1 X60Qx_1780 = newSeqUninit_0_Ichtepn1_comaa5xpt1(0);
  seq_0_In6doa_ast8ri79k X60Qx_1781 = newSeqUninit_0_Ieodq4s1_ast8ri79k(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1782 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1783 = newSeqUninit_0_Iggfvwp_chu5m1rja1(0);
  (*X60Qtmp_141) = (X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1){
    .r_00 = 0, .d_00 = (Compiler_Obj_0_comaa5xpt1){
      .procs_0 = X60Qx_1754, .consts_0 = X60Qx_1755, .magics_0 = X60Qx_1756, .convs_0 = X60Qx_1757, .natives_0 = X60Qx_1758, .enumWraps_0 = X60Qx_1759, .gatedCalls_0 = X60Qx_1760, .objInfos_0 = X60Qx_1761, .fieldSyms_0 = X60Qx_1762, .objSpecs_0 = X60Qx_1763, .typeSyms_0 = X60Qx_1764, .gmap_0 = (SymMap_0_comaa5xpt1){
        .keys_0 = X60Qx_1765, .vals_0 = X60Qx_1766}
      , .numGlobals_0 = 0, .globalSeeds_0 = X60Qx_1767, .pmap_0 = (SymMap_0_comaa5xpt1){
        .keys_0 = X60Qx_1768, .vals_0 = X60Qx_1769}
      , .procDefSyms_0 = X60Qx_1770, .procDefCursors_0 = X60Qx_1771, .methodSites_0 = X60Qx_1772, .methodTable_0 = X60Qx_1773, .enumSyms_0 = X60Qx_1774, .enumOrds_0 = X60Qx_1775, .enumNames_0 = X60Qx_1776, .nestedSyms_0 = (SymMap_0_comaa5xpt1){
        .keys_0 = X60Qx_1777, .vals_0 = X60Qx_1778}
      , .envSyms_0 = X60Qx_1779, .usesScheduler_0 = NIM_FALSE, .ctxStack_0 = X60Qx_1780, .importGlobalSyms_0 = X60Qx_1781, .importGlobalSlots_0 = X60Qx_1782, .importGlobalInits_0 = X60Qx_1783}}
  ;
  X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* c_109 = X60Qtmp_141;
  Cursor_0_nifb6mq6y1 c1_0 = eQdup_0_nifb6mq6y1(root_2);
  collectDecls_0_comaa5xpt1(c_109, (&c1_0));
  NB8 X60Qx_1784 = mentionsSetScheduler_0_comaa5xpt1(root_2);
  (*c_109).d_00.usesScheduler_0 = X60Qx_1784;
  seq_0_Inaua171_chu5m1rja1 inits_0 = newSeqUninit_0_Isa1q0a_chu5m1rja1(0);
  NI32 ii_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1785 = len_6_Imwfq2l1_comaa5xpt1(importRoots_0);
      if (ii_0 < X60Qx_1785){
        Cursor_0_nifb6mq6y1* X60Qx_1786 = getQ_10_I3gtmqq1_comaa5xpt1(importRoots_0, ii_0);
        Proc_0_chu5m1rja1 X60Qx_1787 = compileTopStmts_0_comaa5xpt1(c_109, (*X60Qx_1786));
        add_0_Iss439i1_comaa5xpt1((&inits_0), X60Qx_1787);
        inc_1_I6wjjge_aow2h993l1((&ii_0));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  Proc_0_chu5m1rja1 topProc0_0 = compileTopStmts_0_comaa5xpt1(c_109, root_2);
  NI32 mi_0 = 0;
  {
    while (NIM_TRUE){
      NI32 X60Qx_1788 = len_3_I6y2imo_buiyylk1h1((*c_109).d_00.procDefSyms_0);
      if (mi_0 < X60Qx_1788){
        Cursor_0_nifb6mq6y1* X60Qx_1789 = getQ_7_Iyegbq3_comaa5xpt1((*c_109).d_00.procDefCursors_0, mi_0);
        string_0_sysvq0asl X60Qtmp_142 = nodeTag_0_comaa5xpt1((*X60Qx_1789));
        NB8 X60Qx_1790 = eqQ_20_sysvq0asl(X60Qtmp_142, (string_0_sysvq0asl){
          .bytes_0 = 1952804350u, .more_0 = (&strlit_0_I6517805684605582485_comaa5xpt1)}
        );
        if (X60Qx_1790){
          NU32* X60Qx_1791 = getQ_7_I2v00yv1_buiyylk1h1((*c_109).d_00.procDefSyms_0, mi_0);
          NU32 s_107 = (*X60Qx_1791);
          NI32 idx_9 = getProcIdx_1_comaa5xpt1(c_109, s_107);
          add_0_I3fda3s1_comaa5xpt1((&(*c_109).d_00.methodTable_0), (MethodEntry_0_chu5m1rja1){
            .sym_0 = s_107, .idx_0 = idx_9}
          );}
        inc_1_I6wjjge_aow2h993l1((&mi_0));
        nimStrDestroy(X60Qtmp_142);}
      else {
        break;}}}
  whileStmtLabel_1: ;
  registerAllVtables_0_comaa5xpt1(c_109);
  eQdestroyQ_SX56mX50rogram0chu5m1rja1_0_chu5m1rja1((&result_59));
  seq_0_Inaua171_chu5m1rja1 X60Qx_113 = eQdup_1_Iz0ujbh_chu5m1rja1((*c_109).d_00.procs_0);
  seq_0_I50urnw_chu5m1rja1 X60Qx_114 = eQdup_1_I28mx5s1_chu5m1rja1((*c_109).d_00.consts_0);
  seq_0_Ie9rikd_chu5m1rja1 X60Qx_115 = eQdup_1_Ivlbiyc_chu5m1rja1((*c_109).d_00.magics_0);
  seq_0_Iknt7a3_chu5m1rja1 X60Qx_116 = eQdup_1_Iivi5nx1_chu5m1rja1((*c_109).d_00.convs_0);
  seq_0_Ixdx2fh1_ast8ri79k X60Qx_117 = eQdup_1_Imq0s4c_ast8ri79k((*c_109).d_00.natives_0);
  seq_0_In6doa_ast8ri79k X60Qx_118 = eQdup_1_Idg8rf9_ast8ri79k((*c_109).d_00.enumWraps_0);
  seq_0_Id5h4uf_chu5m1rja1 X60Qx_119 = eQdup_1_I00ryxj_chu5m1rja1((*c_109).d_00.gatedCalls_0);
  seq_0_I2neof81_chu5m1rja1 X60Qx_120 = eQdup_1_I09s8x31_chu5m1rja1((*c_109).d_00.objInfos_0);
  seq_0_In6doa_ast8ri79k X60Qx_121 = eQdup_1_Idg8rf9_ast8ri79k((*c_109).d_00.fieldSyms_0);
  seq_0_Isww99s_chu5m1rja1 X60Qx_122 = eQdup_1_I41eryb1_chu5m1rja1((*c_109).d_00.objSpecs_0);
  seq_0_In6doa_ast8ri79k X60Qx_123 = eQdup_1_Idg8rf9_ast8ri79k((*c_109).d_00.typeSyms_0);
  seq_0_In6doa_ast8ri79k X60Qx_124 = eQdup_1_Idg8rf9_ast8ri79k((*c_109).d_00.envSyms_0);
  seq_0_Ir067xu1_chu5m1rja1 X60Qx_125 = eQdup_1_I85r9nd1_chu5m1rja1((*c_109).d_00.methodSites_0);
  seq_0_I88k8j01_chu5m1rja1 X60Qx_126 = eQdup_1_Ishf7nq1_chu5m1rja1((*c_109).d_00.methodTable_0);
  Proc_0_chu5m1rja1 X60Qtmp_143 = topProc0_0;
  eQwasmovedQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&topProc0_0));
  seq_0_Inaua171_chu5m1rja1 X60Qtmp_144 = inits_0;
  eQwasMoved_1_Iwfxwnm_chu5m1rja1((&inits_0));
  seq_0_Iioxqbu_chu5m1rja1 X60Qx_127 = eQdup_1_Iwrxt2p_chu5m1rja1((*c_109).d_00.globalSeeds_0);
  result_59 = (VmProgram_0_chu5m1rja1){
    .procs_0 = X60Qx_113, .consts_0 = X60Qx_114, .magics_0 = X60Qx_115, .convs_0 = X60Qx_116, .natives_0 = X60Qx_117, .enumWraps_0 = X60Qx_118, .gatedCalls_0 = X60Qx_119, .objInfos_0 = X60Qx_120, .fieldSyms_0 = X60Qx_121, .objSpecs_0 = X60Qx_122, .typeSyms_0 = X60Qx_123, .envSyms_0 = X60Qx_124, .methodSites_0 = X60Qx_125, .methodTable_0 = X60Qx_126, .top_0 = X60Qtmp_143, .inits_0 = X60Qtmp_144, .numGlobals_0 = (*c_109).d_00.numGlobals_0, .globalSeeds_0 = X60Qx_127}
  ;
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&topProc0_0));
  eQdestroy_1_Iwhufig1_chu5m1rja1(inits_0);
  eQdestroy_0_nifb6mq6y1((&c1_0));
  eQdestroyQ_ArefSX43ompilerX4fbj0comaa5xpt1_0_comaa5xpt1(c_109);
  return result_59;
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&topProc0_0));
  eQdestroy_1_Iwhufig1_chu5m1rja1(inits_0);
  eQdestroy_0_nifb6mq6y1((&c1_0));
  eQdestroyQ_ArefSX43ompilerX4fbj0comaa5xpt1_0_comaa5xpt1(c_109);
  return result_59;}
static inline NI32* getQ_7_Ir8kccm_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_110, NI32 i_36){
  NB8 X60Qx_1793;
  if (i_36 < s_110.len_0){
    X60Qx_1793 = (0 <= i_36);}
  else {
    X60Qx_1793 = NIM_FALSE;}
  if ((!X60Qx_1793)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NI32* result_62;
  result_62 = (&s_110.data_0[i_36]);
  return result_62;}
static inline void putQ_7_Ifvyck5_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_111, NI32 i_37, NI32 elem_25){
  NB8 X60Qx_1794;
  if (i_37 < (*s_111).len_0){
    X60Qx_1794 = (0 <= i_37);}
  else {
    X60Qx_1794 = NIM_FALSE;}
  if ((!X60Qx_1794)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  (*s_111).data_0[i_37] = elem_25;}
static inline void add_0_I34il1q_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_112, NU32 elem_26){
  NI32 L_1 = (*s_112).len_0;
  NI32 X60Qx_1795 = capInBytes_0_Iev6wua1_ast8ri79k((*s_112));
  if (X60Qx_1795 < ((NI32)(((NI32)(L_1 * sizeof(NU32))) + sizeof(NU32)))){
    NB8 X60Qx_1796 = resize_0_I6ho9ve_buiyylk1h1(s_112, 1);
    if ((!X60Qx_1796)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_112).len_0));
  (*s_112).data_0[L_1] = elem_26;}
static inline void add_0_I8kd4i4_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* s_114, NI32 elem_27){
  NI32 L_2 = (*s_114).len_0;
  NI32 X60Qx_1797 = capInBytes_0_Iet286n_chu5m1rja1((*s_114));
  if (X60Qx_1797 < ((NI32)(((NI32)(L_2 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_1798 = resize_0_I8l4tya_comaa5xpt1(s_114, 1);
    if ((!X60Qx_1798)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_114).len_0));
  (*s_114).data_0[L_2] = elem_27;}
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
static inline NI32 len_3_Icgec691_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1 s_116){
  NI32 result_65;
  result_65 = s_116.len_0;
  return result_65;}
static inline void add_0_Ibh17rk1_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1* s_117, Instr_0_chu5m1rja1 elem_28){
  NI32 L_3 = (*s_117).len_0;
  NI32 X60Qx_1801 = capInBytes_0_Io1cymi_chu5m1rja1((*s_117));
  if (X60Qx_1801 < ((NI32)(((NI32)(L_3 * sizeof(Instr_0_chu5m1rja1))) + sizeof(Instr_0_chu5m1rja1)))){
    NB8 X60Qx_1802 = resize_0_Izte9pz_comaa5xpt1(s_117, 1);
    if ((!X60Qx_1802)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_117).len_0));
  (*s_117).data_0[L_3] = elem_28;}
static inline Instr_0_chu5m1rja1* getQ_7_Iuezo3v1_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1 s_119, NI32 i_38){
  NB8 X60Qx_1803;
  if (i_38 < s_119.len_0){
    X60Qx_1803 = (0 <= i_38);}
  else {
    X60Qx_1803 = NIM_FALSE;}
  if ((!X60Qx_1803)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  Instr_0_chu5m1rja1* result_66;
  result_66 = (&s_119.data_0[i_38]);
  return result_66;}
static inline void putQ_7_Iko5vvk1_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1* s_120, NI32 i_39, Instr_0_chu5m1rja1 elem_29){
  NB8 X60Qx_1804;
  if (i_39 < (*s_120).len_0){
    X60Qx_1804 = (0 <= i_39);}
  else {
    X60Qx_1804 = NIM_FALSE;}
  if ((!X60Qx_1804)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  (*s_120).data_0[i_39] = elem_29;}
static inline NI32 len_3_I4n9kvq_comaa5xpt1(seq_0_I50urnw_chu5m1rja1 s_121){
  NI32 result_67;
  result_67 = s_121.len_0;
  return result_67;}
static inline void add_0_Itre92n_comaa5xpt1(seq_0_I50urnw_chu5m1rja1* s_122, Value_0_valzr1t4f elem_30){
  NI32 L_4 = (*s_122).len_0;
  NI32 X60Qx_1805 = capInBytes_0_Ihvsegh1_chu5m1rja1((*s_122));
  if (X60Qx_1805 < ((NI32)(((NI32)(L_4 * sizeof(Value_0_valzr1t4f))) + sizeof(Value_0_valzr1t4f)))){
    NB8 X60Qx_1806 = resize_0_Iz8tg361_comaa5xpt1(s_122, 1);
    if ((!X60Qx_1806)){
      eQdestroyQ_SX56alue0valzr1t4f_0_valzr1t4f((&elem_30));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_122).len_0));
  (*s_122).data_0[L_4] = elem_30;}
static inline NI32 len_3_Idcvg0j1_comaa5xpt1(seq_0_Ie9rikd_chu5m1rja1 s_124){
  NI32 result_68;
  result_68 = s_124.len_0;
  return result_68;}
static inline void add_0_Iv446pn1_comaa5xpt1(seq_0_Ie9rikd_chu5m1rja1* s_125, MagicSpec_0_chu5m1rja1 elem_31){
  NI32 L_5 = (*s_125).len_0;
  NI32 X60Qx_1807 = capInBytes_0_I02yj151_chu5m1rja1((*s_125));
  if (X60Qx_1807 < ((NI32)(((NI32)(L_5 * sizeof(MagicSpec_0_chu5m1rja1))) + sizeof(MagicSpec_0_chu5m1rja1)))){
    NB8 X60Qx_1808 = resize_0_Itdw5n21_comaa5xpt1(s_125, 1);
    if ((!X60Qx_1808)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_125).len_0));
  (*s_125).data_0[L_5] = elem_31;}
static inline NI32 len_3_Iiake9l_comaa5xpt1(seq_0_Iknt7a3_chu5m1rja1 s_127){
  NI32 result_69;
  result_69 = s_127.len_0;
  return result_69;}
static inline void add_0_Imr7j74_comaa5xpt1(seq_0_Iknt7a3_chu5m1rja1* s_128, ConvSpec_0_chu5m1rja1 elem_32){
  NI32 L_6 = (*s_128).len_0;
  NI32 X60Qx_1809 = capInBytes_0_Iccedzq_chu5m1rja1((*s_128));
  if (X60Qx_1809 < ((NI32)(((NI32)(L_6 * sizeof(ConvSpec_0_chu5m1rja1))) + sizeof(ConvSpec_0_chu5m1rja1)))){
    NB8 X60Qx_1810 = resize_0_Ikaiuf5_comaa5xpt1(s_128, 1);
    if ((!X60Qx_1810)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_128).len_0));
  (*s_128).data_0[L_6] = elem_32;}
static inline NI32 len_3_Ixq6taz_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_130){
  NI32 result_70;
  result_70 = s_130.len_0;
  return result_70;}
static inline NI32 len_3_I18vp0c1_comaa5xpt1(seq_0_Id5h4uf_chu5m1rja1 s_134){
  NI32 result_72;
  result_72 = s_134.len_0;
  return result_72;}
static inline void add_0_Iybug3z_comaa5xpt1(seq_0_Id5h4uf_chu5m1rja1* s_135, GatedCall_0_chu5m1rja1 elem_34){
  NI32 L_8 = (*s_135).len_0;
  NI32 X60Qx_1814 = capInBytes_0_Ihi6tep_chu5m1rja1((*s_135));
  if (X60Qx_1814 < ((NI32)(((NI32)(L_8 * sizeof(GatedCall_0_chu5m1rja1))) + sizeof(GatedCall_0_chu5m1rja1)))){
    NB8 X60Qx_1815 = resize_0_I9r5bp3_comaa5xpt1(s_135, 1);
    if ((!X60Qx_1815)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_135).len_0));
  (*s_135).data_0[L_8] = elem_34;}
static inline NI32 len_3_Ibeqm1v_comaa5xpt1(seq_0_I2neof81_chu5m1rja1 s_137){
  NI32 result_73;
  result_73 = s_137.len_0;
  return result_73;}
static inline void add_0_Iwx7sdj1_comaa5xpt1(seq_0_I2neof81_chu5m1rja1* s_138, ObjInfo_0_chu5m1rja1 elem_35){
  NI32 L_9 = (*s_138).len_0;
  NI32 X60Qx_1816 = capInBytes_0_I27hxyl_chu5m1rja1((*s_138));
  if (X60Qx_1816 < ((NI32)(((NI32)(L_9 * sizeof(ObjInfo_0_chu5m1rja1))) + sizeof(ObjInfo_0_chu5m1rja1)))){
    NB8 X60Qx_1817 = resize_0_Ib3lf9y1_comaa5xpt1(s_138, 1);
    if ((!X60Qx_1817)){
      eQdestroyQ_SX4fbjX49nfo0chu5m1rja1_0_chu5m1rja1(elem_35);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_138).len_0));
  (*s_138).data_0[L_9] = elem_35;}
static inline void add_0_Insw6ce1_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1* s_144, Cursor_0_nifb6mq6y1 elem_37){
  NI32 L_11 = (*s_144).len_0;
  NI32 X60Qx_1822 = capInBytes_0_I0ia6g61_comaa5xpt1((*s_144));
  if (X60Qx_1822 < ((NI32)(((NI32)(L_11 * sizeof(Cursor_0_nifb6mq6y1))) + sizeof(Cursor_0_nifb6mq6y1)))){
    NB8 X60Qx_1823 = resize_0_I6nu0dd_comaa5xpt1(s_144, 1);
    if ((!X60Qx_1823)){
      eQdestroy_0_nifb6mq6y1((&elem_37));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_144).len_0));
  (*s_144).data_0[L_11] = elem_37;}
static inline NI32 len_3_Ibv77kg1_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1 s_146){
  NI32 result_77;
  result_77 = s_146.len_0;
  return result_77;}
static inline X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1** getQ_7_Ivqabz61_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1 s_147, NI32 i_42){
  NB8 X60Qx_1824;
  if (i_42 < s_147.len_0){
    X60Qx_1824 = (0 <= i_42);}
  else {
    X60Qx_1824 = NIM_FALSE;}
  if ((!X60Qx_1824)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1** result_78;
  result_78 = (&s_147.data_0[i_42]);
  return result_78;}
static inline seq_0_Iscf6bn_comaa5xpt1 newSeqUninit_0_Ib8z3ow_comaa5xpt1(NI32 size_26){
  seq_0_Iscf6bn_comaa5xpt1 result_82;
  if (size_26 == 0){
    result_82 = (seq_0_Iscf6bn_comaa5xpt1){
      .len_0 = size_26, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_3 = memSizeInBytes_0_I11sygp_comaa5xpt1(size_26);
    void* X60Qx_1831 = alloc_1_sysvq0asl(memSize_3);
    result_82 = (seq_0_Iscf6bn_comaa5xpt1){
      .len_0 = size_26, .data_0 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1**)X60Qx_1831)}
    ;
    if ((!(result_82.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1832 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_82.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_82;}
static inline seq_0_Igm8woo1_comaa5xpt1 newSeqUninit_0_I8nq5k8_comaa5xpt1(NI32 size_28){
  seq_0_Igm8woo1_comaa5xpt1 result_83;
  if (size_28 == 0){
    result_83 = (seq_0_Igm8woo1_comaa5xpt1){
      .len_0 = size_28, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_4 = memSizeInBytes_0_Ichxqj91_comaa5xpt1(size_28);
    void* X60Qx_1833 = alloc_1_sysvq0asl(memSize_4);
    result_83 = (seq_0_Igm8woo1_comaa5xpt1){
      .len_0 = size_28, .data_0 = ((X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1**)X60Qx_1833)}
    ;
    if ((!(result_83.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1834 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_83.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_4);}}
  return result_83;}
static inline seq_0_I806bg1_comaa5xpt1 newSeqUninit_0_Iqckanu_comaa5xpt1(NI32 size_30){
  seq_0_I806bg1_comaa5xpt1 result_84;
  if (size_30 == 0){
    result_84 = (seq_0_I806bg1_comaa5xpt1){
      .len_0 = size_30, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_5 = memSizeInBytes_0_I86jswb1_comaa5xpt1(size_30);
    void* X60Qx_1835 = alloc_1_sysvq0asl(memSize_5);
    result_84 = (seq_0_I806bg1_comaa5xpt1){
      .len_0 = size_30, .data_0 = ((FinScope_0_comaa5xpt1*)X60Qx_1835)}
    ;
    if ((!(result_84.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1836 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_84.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_5);}}
  return result_84;}
static inline NI32 len_3_I05nxx61_comaa5xpt1(seq_0_Inaua171_chu5m1rja1 s_148){
  NI32 result_85;
  result_85 = s_148.len_0;
  return result_85;}
static inline void add_0_Iss439i1_comaa5xpt1(seq_0_Inaua171_chu5m1rja1* s_149, Proc_0_chu5m1rja1 elem_38){
  NI32 L_12 = (*s_149).len_0;
  NI32 X60Qx_1837 = capInBytes_0_Ifvg4nq1_chu5m1rja1((*s_149));
  if (X60Qx_1837 < ((NI32)(((NI32)(L_12 * sizeof(Proc_0_chu5m1rja1))) + sizeof(Proc_0_chu5m1rja1)))){
    NB8 X60Qx_1838 = resize_0_I91teg71_comaa5xpt1(s_149, 1);
    if ((!X60Qx_1838)){
      eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&elem_38));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_149).len_0));
  (*s_149).data_0[L_12] = elem_38;}
static inline NI32 len_3_Iuz7erf_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1 s_151){
  NI32 result_86;
  result_86 = s_151.len_0;
  return result_86;}
static inline GlobalSeed_0_chu5m1rja1* getQ_7_Ijx02qt_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1 s_152, NI32 i_43){
  NB8 X60Qx_1839;
  if (i_43 < s_152.len_0){
    X60Qx_1839 = (0 <= i_43);}
  else {
    X60Qx_1839 = NIM_FALSE;}
  if ((!X60Qx_1839)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  GlobalSeed_0_chu5m1rja1* result_87;
  result_87 = (&s_152.data_0[i_43]);
  return result_87;}
static inline void add_0_Iyv2a7e1_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1* s_153, GlobalSeed_0_chu5m1rja1 elem_39){
  NI32 L_13 = (*s_153).len_0;
  NI32 X60Qx_1840 = capInBytes_0_I38sirs1_chu5m1rja1((*s_153));
  if (X60Qx_1840 < ((NI32)(((NI32)(L_13 * sizeof(GlobalSeed_0_chu5m1rja1))) + sizeof(GlobalSeed_0_chu5m1rja1)))){
    NB8 X60Qx_1841 = resize_0_Ijlhibe1_comaa5xpt1(s_153, 1);
    if ((!X60Qx_1841)){
      eQdestroyQ_SX47lobalX53eed0chu5m1rja1_0_chu5m1rja1((&elem_39));
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_153).len_0));
  (*s_153).data_0[L_13] = elem_39;}
static inline Cursor_0_nifb6mq6y1* getQ_7_Iyegbq3_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_155, NI32 i_44){
  NB8 X60Qx_1842;
  if (i_44 < s_155.len_0){
    X60Qx_1842 = (0 <= i_44);}
  else {
    X60Qx_1842 = NIM_FALSE;}
  if ((!X60Qx_1842)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  Cursor_0_nifb6mq6y1* result_88;
  result_88 = (&s_155.data_0[i_44]);
  return result_88;}
static inline void add_0_Iuw4xx01_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_157, X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* elem_40){
  NI32 L_14 = (*s_157).len_0;
  NI32 X60Qx_1847 = capInBytes_0_Itl2tw2_comaa5xpt1((*s_157));
  if (X60Qx_1847 < ((NI32)(((NI32)(L_14 * sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*))) + sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)))){
    NB8 X60Qx_1848 = resize_0_I606t801_comaa5xpt1(s_157, 1);
    if ((!X60Qx_1848)){
      eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(elem_40);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_157).len_0));
  (*s_157).data_0[L_14] = elem_40;}
static inline X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** getQ_7_I6yhgto_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_159, NI32 i_46){
  NB8 X60Qx_1849;
  if (i_46 < s_159.len_0){
    X60Qx_1849 = (0 <= i_46);}
  else {
    X60Qx_1849 = NIM_FALSE;}
  if ((!X60Qx_1849)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** result_91;
  result_91 = (&s_159.data_0[i_46]);
  return result_91;}
static inline openArray_0_Inqs7yx_comaa5xpt1 toOpenArray_1_Ibqb4ob_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_160){
  openArray_0_Inqs7yx_comaa5xpt1 result_92;
  NI32* X60Qx_1850 = rawData_0_Ic25u3r_comaa5xpt1(s_160);
  result_92 = (openArray_0_Inqs7yx_comaa5xpt1){
    .a_0 = X60Qx_1850, .len_0 = s_160.len_0}
  ;
  return result_92;}
static inline NI32 len_3_Ij0uoqp_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_162){
  NI32 result_93;
  result_93 = s_162.len_0;
  return result_93;}
void setLen_0_Ivhuv1v1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_163, NI32 newLen_4){
  if (newLen_4 < (*s_163).len_0){
    shrink_0_Irsuiak1_comaa5xpt1(s_163, newLen_4);}
  else {
    NI32 i_48 = (*s_163).len_0;
    growUnsafe_0_Io18vke_comaa5xpt1(s_163, newLen_4);
    if ((*s_163).data_0 == NIM_NIL){
      return;}
    {
      while (i_48 < newLen_4){
        (*s_163).data_0[i_48] = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)NIM_NIL);
        inc_1_I6wjjge_aow2h993l1((&i_48));}}
    whileStmtLabel_0: ;}}
static inline NI32 len_3_In1ttqs_comaa5xpt1(seq_0_Ir067xu1_chu5m1rja1 s_166){
  NI32 result_94;
  result_94 = s_166.len_0;
  return result_94;}
static inline void add_0_Inwn80m1_comaa5xpt1(seq_0_Ir067xu1_chu5m1rja1* s_167, MethodSite_0_chu5m1rja1 elem_41){
  NI32 L_15 = (*s_167).len_0;
  NI32 X60Qx_1851 = capInBytes_0_Ivj8jl41_chu5m1rja1((*s_167));
  if (X60Qx_1851 < ((NI32)(((NI32)(L_15 * sizeof(MethodSite_0_chu5m1rja1))) + sizeof(MethodSite_0_chu5m1rja1)))){
    NB8 X60Qx_1852 = resize_0_Ig21eot_comaa5xpt1(s_167, 1);
    if ((!X60Qx_1852)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_167).len_0));
  (*s_167).data_0[L_15] = elem_41;}
static inline seq_0_Isyzizu1_comaa5xpt1 newSeqUninit_0_Iikx2qh1_comaa5xpt1(NI32 size_32){
  seq_0_Isyzizu1_comaa5xpt1 result_95;
  if (size_32 == 0){
    result_95 = (seq_0_Isyzizu1_comaa5xpt1){
      .len_0 = size_32, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_6 = memSizeInBytes_0_I3r8cpo1_comaa5xpt1(size_32);
    void* X60Qx_1853 = alloc_1_sysvq0asl(memSize_6);
    result_95 = (seq_0_Isyzizu1_comaa5xpt1){
      .len_0 = size_32, .data_0 = ((Cursor_0_nifb6mq6y1*)X60Qx_1853)}
    ;
    if ((!(result_95.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1854 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_95.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_6);}}
  return result_95;}
static inline seq_0_Ik7wkpe_comaa5xpt1 newSeqUninit_0_Idxnvmq_comaa5xpt1(NI32 size_34){
  seq_0_Ik7wkpe_comaa5xpt1 result_96;
  if (size_34 == 0){
    result_96 = (seq_0_Ik7wkpe_comaa5xpt1){
      .len_0 = size_34, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_7 = memSizeInBytes_0_I03jys01_comaa5xpt1(size_34);
    void* X60Qx_1855 = alloc_1_sysvq0asl(memSize_7);
    result_96 = (seq_0_Ik7wkpe_comaa5xpt1){
      .len_0 = size_34, .data_0 = ((seq_0_Ift2sne_chu5m1rja1*)X60Qx_1855)}
    ;
    if ((!(result_96.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1856 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_96.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_7);}}
  return result_96;}
seq_0_Ift2sne_chu5m1rja1 atQ_0_Iy7v4si1_comaa5xpt1(X60Qt_0_IAarrayAiS32ZS1_comaa5xpt1 a_16){
  seq_0_Ift2sne_chu5m1rja1 result_97;
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1857 = newSeqUninit_0_Iggfvwp_chu5m1rja1(((NI32)(((NI32)(((NI32)((NI32)0)) - ((NI32)((NI32)0)))) + 1)));
  result_97 = X60Qx_1857;
  if ((!(result_97.data_0 == NIM_NIL))){
    NI32 i_49 = 0;
    {
      while (i_49 < result_97.len_0){
        NI32 X60Qx_1858 = nimIcheckB(i_49, 0);
        result_97.data_0[i_49] = a_16.a[X60Qx_1858];
        inc_1_I6wjjge_aow2h993l1((&i_49));}}
    whileStmtLabel_0: ;}
  return result_97;}
static inline void add_0_Iivdbhc_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1* s_169, seq_0_Ift2sne_chu5m1rja1 elem_42){
  NI32 L_16 = (*s_169).len_0;
  NI32 X60Qx_1859 = capInBytes_0_Iri1hlt1_comaa5xpt1((*s_169));
  if (X60Qx_1859 < ((NI32)(((NI32)(L_16 * sizeof(seq_0_Ift2sne_chu5m1rja1))) + sizeof(seq_0_Ift2sne_chu5m1rja1)))){
    NB8 X60Qx_1860 = resize_0_I9lztdq1_comaa5xpt1(s_169, 1);
    if ((!X60Qx_1860)){
      eQdestroy_1_Iv9ij5i1_chu5m1rja1(elem_42);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_169).len_0));
  (*s_169).data_0[L_16] = elem_42;}
static inline NI32 len_3_Irjnvku_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 s_171){
  NI32 result_98;
  result_98 = s_171.len_0;
  return result_98;}
static inline seq_0_Ift2sne_chu5m1rja1* getQ_7_Iurb46i_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 s_172, NI32 i_50){
  NB8 X60Qx_1861;
  if (i_50 < s_172.len_0){
    X60Qx_1861 = (0 <= i_50);}
  else {
    X60Qx_1861 = NIM_FALSE;}
  if ((!X60Qx_1861)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  seq_0_Ift2sne_chu5m1rja1* result_99;
  result_99 = (&s_172.data_0[i_50]);
  return result_99;}
static inline NI32 len_3_I0v1j8d_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_173){
  NI32 result_100;
  result_100 = s_173.len_0;
  return result_100;}
static inline NI32 len_3_Ilsmz1h_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_174){
  NI32 result_101;
  result_101 = s_174.len_0;
  return result_101;}
static inline HSlice_0_I8tnmvh1_comaa5xpt1 ___1_Ico26mb_comaa5xpt1(NI32 a_17, NI32 b_12){
  HSlice_0_I8tnmvh1_comaa5xpt1 result_102;
  result_102 = (HSlice_0_I8tnmvh1_comaa5xpt1){
    .a_0 = a_17, .b_0 = b_12}
  ;
  return result_102;}
static inline seq_0_Ift2sne_chu5m1rja1 getQ_17_I2og8ah1_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_175, HSlice_0_I8tnmvh1_comaa5xpt1 x_9){
  seq_0_Ift2sne_chu5m1rja1 result_103;
  eQwasMoved_1_Ix88qzs1_chu5m1rja1((&result_103));
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(result_103);
  HSlice_0_Inzqy8d_comaa5xpt1 X60Qx_1862 = ___1_Iclcqmw1_comaa5xpt1(x_9.a_0, ((NI32)(s_175.len_0 - ((NI32)x_9.b_0))));
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1863 = getQ_16_Ijvcpzq1_comaa5xpt1(s_175, X60Qx_1862);
  result_103 = X60Qx_1863;
  return result_103;}
static inline void add_0_Iype0e61_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* s_177, X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* elem_43){
  NI32 L_17 = (*s_177).len_0;
  NI32 X60Qx_1864 = capInBytes_0_Idtacij1_comaa5xpt1((*s_177));
  if (X60Qx_1864 < ((NI32)(((NI32)(L_17 * sizeof(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1*))) + sizeof(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1*)))){
    NB8 X60Qx_1865 = resize_0_Iiusqmu1_comaa5xpt1(s_177, 1);
    if ((!X60Qx_1865)){
      eQdestroyQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(elem_43);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_177).len_0));
  (*s_177).data_0[L_17] = elem_43;}
static inline NI32 len_3_I7uqqfu1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1 s_179){
  NI32 result_104;
  result_104 = s_179.len_0;
  return result_104;}
void setLen_0_I93919j1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* s_180, NI32 newLen_7){
  if (newLen_7 < (*s_180).len_0){
    shrink_0_I6q9rej1_comaa5xpt1(s_180, newLen_7);}
  else {
    NI32 i_51 = (*s_180).len_0;
    growUnsafe_0_Itey597_comaa5xpt1(s_180, newLen_7);
    if ((*s_180).data_0 == NIM_NIL){
      return;}
    {
      while (i_51 < newLen_7){
        (*s_180).data_0[i_51] = ((X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1*)NIM_NIL);
        inc_1_I6wjjge_aow2h993l1((&i_51));}}
    whileStmtLabel_0: ;}}
static inline void add_0_Ie3v897_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* s_183, FinScope_0_comaa5xpt1 elem_44){
  NI32 L_18 = (*s_183).len_0;
  NI32 X60Qx_1866 = capInBytes_0_Ipkd9yl_comaa5xpt1((*s_183));
  if (X60Qx_1866 < ((NI32)(((NI32)(L_18 * sizeof(FinScope_0_comaa5xpt1))) + sizeof(FinScope_0_comaa5xpt1)))){
    NB8 X60Qx_1867 = resize_0_Ix9q1o91_comaa5xpt1(s_183, 1);
    if ((!X60Qx_1867)){
      eQdestroyQ_SX46inX53cope0comaa5xpt1_0_comaa5xpt1(elem_44);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_183).len_0));
  (*s_183).data_0[L_18] = elem_44;}
static inline NI32 len_3_I8hzf0s1_comaa5xpt1(seq_0_I806bg1_comaa5xpt1 s_185){
  NI32 result_105;
  result_105 = s_185.len_0;
  return result_105;}
void setLen_0_I53ui2z_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* s_186, NI32 newLen_10){
  if (newLen_10 < (*s_186).len_0){
    shrink_0_Ic6ijzf_comaa5xpt1(s_186, newLen_10);}
  else {
    NI32 i_52 = (*s_186).len_0;
    growUnsafe_0_I2ptrki_comaa5xpt1(s_186, newLen_10);
    if ((*s_186).data_0 == NIM_NIL){
      return;}
    {
      while (i_52 < newLen_10){
        (*s_186).data_0[i_52] = (FinScope_0_comaa5xpt1){
          .finCur_0 = (Cursor_0_nifb6mq6y1){
            .owner_0 = ((CursorOwnerObj_0_nifb6mq6y1*)NIM_NIL), .p_0 = ((PackedToken_0_nifh7u8pu1*)NIM_NIL), .rem_0 = ((NI32)0)}
          , .loopLen_0 = ((NI32)0), .handlerCount_0 = ((NI32)0)}
        ;
        inc_1_I6wjjge_aow2h993l1((&i_52));}}
    whileStmtLabel_0: ;}}
static inline FinScope_0_comaa5xpt1* getQ_7_Irfu7p7_comaa5xpt1(seq_0_I806bg1_comaa5xpt1 s_189, NI32 i_53){
  NB8 X60Qx_1868;
  if (i_53 < s_189.len_0){
    X60Qx_1868 = (0 <= i_53);}
  else {
    X60Qx_1868 = NIM_FALSE;}
  if ((!X60Qx_1868)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  FinScope_0_comaa5xpt1* result_106;
  result_106 = (&s_189.data_0[i_53]);
  return result_106;}
static inline X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1** getQ_7_Iklts1k_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1 s_190, NI32 i_54){
  NB8 X60Qx_1869;
  if (i_54 < s_190.len_0){
    X60Qx_1869 = (0 <= i_54);}
  else {
    X60Qx_1869 = NIM_FALSE;}
  if ((!X60Qx_1869)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1** result_107;
  result_107 = (&s_190.data_0[i_54]);
  return result_107;}
static inline seq_0_Iscf6bn_comaa5xpt1 getQ_17_Iuwh3901_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_191, HSlice_0_I8tnmvh1_comaa5xpt1 x_11){
  seq_0_Iscf6bn_comaa5xpt1 result_108;
  eQwasMoved_1_Iw33v4x_comaa5xpt1((&result_108));
  eQdestroy_1_Irljx3e1_comaa5xpt1(result_108);
  HSlice_0_Inzqy8d_comaa5xpt1 X60Qx_1870 = ___1_Iclcqmw1_comaa5xpt1(x_11.a_0, ((NI32)(s_191.len_0 - ((NI32)x_11.b_0))));
  seq_0_Iscf6bn_comaa5xpt1 X60Qx_1871 = getQ_16_Iansvof1_comaa5xpt1(s_191, X60Qx_1870);
  result_108 = X60Qx_1871;
  return result_108;}
static inline openArray_0_I6xd9vz_comaa5xpt1 toOpenArray_1_Ibb6pci1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_193){
  openArray_0_I6xd9vz_comaa5xpt1 result_109;
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1872 = rawData_0_Iabis8p_comaa5xpt1(s_193);
  result_109 = (openArray_0_I6xd9vz_comaa5xpt1){
    .a_0 = X60Qx_1872, .len_0 = s_193.len_0}
  ;
  return result_109;}
static inline void putQ_7_Ia9tk91_comaa5xpt1(seq_0_In6doa_ast8ri79k* s_195, NI32 i_56, NU32 elem_45){
  NB8 X60Qx_1873;
  if (i_56 < (*s_195).len_0){
    X60Qx_1873 = (0 <= i_56);}
  else {
    X60Qx_1873 = NIM_FALSE;}
  if ((!X60Qx_1873)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  (*s_195).data_0[i_56] = elem_45;}
static inline void add_0_If3vc0y1_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* s_196, X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* elem_46){
  NI32 L_19 = (*s_196).len_0;
  NI32 X60Qx_1874 = capInBytes_0_Iz2n5ul_comaa5xpt1((*s_196));
  if (X60Qx_1874 < ((NI32)(((NI32)(L_19 * sizeof(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1*))) + sizeof(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1*)))){
    NB8 X60Qx_1875 = resize_0_Iymm5xw_comaa5xpt1(s_196, 1);
    if ((!X60Qx_1875)){
      eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(elem_46);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_196).len_0));
  (*s_196).data_0[L_19] = elem_46;}
void setLen_0_Izc6r611_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* s_198, NI32 newLen_13){
  if (newLen_13 < (*s_198).len_0){
    shrink_0_I5z0zky1_comaa5xpt1(s_198, newLen_13);}
  else {
    NI32 i_57 = (*s_198).len_0;
    growUnsafe_0_I1b8vl2_comaa5xpt1(s_198, newLen_13);
    if ((*s_198).data_0 == NIM_NIL){
      return;}
    {
      while (i_57 < newLen_13){
        (*s_198).data_0[i_57] = ((X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1*)NIM_NIL);
        inc_1_I6wjjge_aow2h993l1((&i_57));}}
    whileStmtLabel_0: ;}}
static inline void putQ_7_I5scqr1_comaa5xpt1(seq_0_Inaua171_chu5m1rja1* s_201, NI32 i_58, Proc_0_chu5m1rja1 elem_47){
  NB8 X60Qx_1876;
  if (i_58 < (*s_201).len_0){
    X60Qx_1876 = (0 <= i_58);}
  else {
    X60Qx_1876 = NIM_FALSE;}
  if ((!X60Qx_1876)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I767816010166080526_comaa5xpt1)}
    );}
  Proc_0_chu5m1rja1* X60Qlhs_145 = (&(*s_201).data_0[i_58]);
  Proc_0_chu5m1rja1 X60Qlhs_146 = elem_47;
  eQwasmovedQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&elem_47));
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&(*X60Qlhs_145)));
  (*X60Qlhs_145) = X60Qlhs_146;
  eQdestroyQ_SX50roc0chu5m1rja1_0_chu5m1rja1((&elem_47));}
static inline NI32 len_3_I2qk2yu1_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1 s_202){
  NI32 result_110;
  result_110 = s_202.len_0;
  return result_110;}
static inline MethodEntry_0_chu5m1rja1* getQ_7_I8226yy1_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1 s_203, NI32 i_59){
  NB8 X60Qx_1877;
  if (i_59 < s_203.len_0){
    X60Qx_1877 = (0 <= i_59);}
  else {
    X60Qx_1877 = NIM_FALSE;}
  if ((!X60Qx_1877)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  MethodEntry_0_chu5m1rja1* result_111;
  result_111 = (&s_203.data_0[i_59]);
  return result_111;}
static inline openArray_0_In1h8lr1_comaa5xpt1 toOpenArray_1_Ivm9z5a_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_204){
  openArray_0_In1h8lr1_comaa5xpt1 result_112;
  MethodIndexEntry_0_sempjk6bn1* X60Qx_1878 = rawData_0_I0uy4q51_comaa5xpt1(s_204);
  result_112 = (openArray_0_In1h8lr1_comaa5xpt1){
    .a_0 = X60Qx_1878, .len_0 = s_204.len_0}
  ;
  return result_112;}
static inline void add_0_I3fda3s1_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1* s_206, MethodEntry_0_chu5m1rja1 elem_48){
  NI32 L_20 = (*s_206).len_0;
  NI32 X60Qx_1879 = capInBytes_0_I6qhu63_chu5m1rja1((*s_206));
  if (X60Qx_1879 < ((NI32)(((NI32)(L_20 * sizeof(MethodEntry_0_chu5m1rja1))) + sizeof(MethodEntry_0_chu5m1rja1)))){
    NB8 X60Qx_1880 = resize_0_I6yc4yx_comaa5xpt1(s_206, 1);
    if ((!X60Qx_1880)){
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_206).len_0));
  (*s_206).data_0[L_20] = elem_48;}
static inline openArray_0_Iz8j0ra_comaa5xpt1 toOpenArray_1_Ipyn7lx1_comaa5xpt1(seq_0_I2neof81_chu5m1rja1 s_208){
  openArray_0_Iz8j0ra_comaa5xpt1 result_113;
  ObjInfo_0_chu5m1rja1* X60Qx_1881 = rawData_0_Icrhavl1_comaa5xpt1(s_208);
  result_113 = (openArray_0_Iz8j0ra_comaa5xpt1){
    .a_0 = X60Qx_1881, .len_0 = s_208.len_0}
  ;
  return result_113;}
static inline openArray_0_I94odo91_comaa5xpt1 toOpenArray_1_Itwyxk01_comaa5xpt1(seq_0_Isww99s_chu5m1rja1 s_210){
  openArray_0_I94odo91_comaa5xpt1 result_114;
  ObjSpec_0_chu5m1rja1* X60Qx_1882 = rawData_0_I3cvan_comaa5xpt1(s_210);
  result_114 = (openArray_0_I94odo91_comaa5xpt1){
    .a_0 = X60Qx_1882, .len_0 = s_210.len_0}
  ;
  return result_114;}
static inline openArray_0_Ir53qdx_comaa5xpt1 toOpenArray_1_I02c2wz_comaa5xpt1(seq_0_In6doa_ast8ri79k s_212){
  openArray_0_Ir53qdx_comaa5xpt1 result_115;
  NU32* X60Qx_1883 = rawData_0_I9ky6gs1_comaa5xpt1(s_212);
  result_115 = (openArray_0_Ir53qdx_comaa5xpt1){
    .a_0 = X60Qx_1883, .len_0 = s_212.len_0}
  ;
  return result_115;}
static inline HSlice_0_Inzqy8d_comaa5xpt1 ___1_Iclcqmw1_comaa5xpt1(NI32 a_28, NI32 b_13){
  HSlice_0_Inzqy8d_comaa5xpt1 result_116;
  result_116 = (HSlice_0_Inzqy8d_comaa5xpt1){
    .a_0 = a_28, .b_0 = b_13}
  ;
  return result_116;}
static inline openArray_0_Ig73pnk_comaa5xpt1 toOpenArray_1_I6b60gk1_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_214){
  openArray_0_Ig73pnk_comaa5xpt1 result_117;
  string_0_sysvq0asl* X60Qx_1884 = rawData_0_I65w5sr_comaa5xpt1(s_214);
  result_117 = (openArray_0_Ig73pnk_comaa5xpt1){
    .a_0 = X60Qx_1884, .len_0 = s_214.len_0}
  ;
  return result_117;}
static inline openArray_0_Imqex5f1_comaa5xpt1 toOpenArray_0_Imravs1_comaa5xpt1(X60Qt_0_IAarraySX43ursor0nifb6mq6y1S0_comaa5xpt1* x_19){
  openArray_0_Imqex5f1_comaa5xpt1 result_120;
  openArray_0_Imqex5f1_comaa5xpt1 X60Qx_21;
  if (((NI32)(((NI32)(((NI32)((NI32)-1)) - ((NI32)((NI32)0)))) + 1)) == 0){
    X60Qx_21 = (openArray_0_Imqex5f1_comaa5xpt1){
      .a_0 = NIM_NIL, .len_0 = 0}
    ;}
  else {
    X60Qx_21 = (openArray_0_Imqex5f1_comaa5xpt1){
      .a_0 = ((Cursor_0_nifb6mq6y1*)(&(*x_19))), .len_0 = ((NI32)(((NI32)(((NI32)((NI32)-1)) - ((NI32)((NI32)0)))) + 1))}
    ;}
  result_120 = X60Qx_21;
  return result_120;}
static inline seq_0_Ik8dusv_comaa5xpt1 newSeqUninit_0_Ichtepn1_comaa5xpt1(NI32 size_54){
  seq_0_Ik8dusv_comaa5xpt1 result_130;
  if (size_54 == 0){
    result_130 = (seq_0_Ik8dusv_comaa5xpt1){
      .len_0 = size_54, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_17 = memSizeInBytes_0_I68vum51_comaa5xpt1(size_54);
    void* X60Qx_1906 = alloc_1_sysvq0asl(memSize_17);
    result_130 = (seq_0_Ik8dusv_comaa5xpt1){
      .len_0 = size_54, .data_0 = ((X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1**)X60Qx_1906)}
    ;
    if ((!(result_130.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_1907 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_130.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_17);}}
  return result_130;}
static inline NI32 len_6_Imwfq2l1_comaa5xpt1(openArray_0_Imqex5f1_comaa5xpt1 a_31){
  NI32 result_133;
  result_133 = a_31.len_0;
  return result_133;}
static inline Cursor_0_nifb6mq6y1* getQ_10_I3gtmqq1_comaa5xpt1(openArray_0_Imqex5f1_comaa5xpt1 x_20, NI32 idx_22){
  NB8 X60Qx_1912;
  if (0 <= idx_22){
    X60Qx_1912 = (idx_22 < x_20.len_0);}
  else {
    X60Qx_1912 = NIM_FALSE;}
  if ((!X60Qx_1912)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  Cursor_0_nifb6mq6y1* result_134;
  result_134 = (&x_20.a_0[idx_22]);
  return result_134;}
NB8 resize_0_I8l4tya_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1* dest_22, NI32 addedElements_22){
  NB8 result_138;
  NI32 X60Qx_1917 = capInBytes_0_Iet286n_chu5m1rja1((*dest_22));
  NI32 oldCap_1 = ((NI32)(X60Qx_1917 / sizeof(NI32)));
  NI32 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_22);
  NI32 memSize_21 = memSizeInBytes_0_Inv7kg3_chu5m1rja1(newCap_1);
  void* X60Qx_1918 = realloc_1_sysvq0asl(((void*)((void*)(*dest_22).data_0)), memSize_21);
  (*dest_22).data_0 = ((NI32*)X60Qx_1918);
  if ((*dest_22).data_0 == NIM_NIL){
    (*dest_22).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_21);
    result_138 = NIM_FALSE;}
  else {
    result_138 = NIM_TRUE;}
  return result_138;}
NB8 resize_0_Izte9pz_comaa5xpt1(seq_0_Izok7jt1_chu5m1rja1* dest_23, NI32 addedElements_23){
  NB8 result_140;
  NI32 X60Qx_1920 = capInBytes_0_Io1cymi_chu5m1rja1((*dest_23));
  NI32 oldCap_2 = ((NI32)(X60Qx_1920 / sizeof(Instr_0_chu5m1rja1)));
  NI32 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_23);
  NI32 memSize_22 = memSizeInBytes_0_I58le2f1_chu5m1rja1(newCap_2);
  void* X60Qx_1921 = realloc_1_sysvq0asl(((void*)((void*)(*dest_23).data_0)), memSize_22);
  (*dest_23).data_0 = ((Instr_0_chu5m1rja1*)X60Qx_1921);
  if ((*dest_23).data_0 == NIM_NIL){
    (*dest_23).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_22);
    result_140 = NIM_FALSE;}
  else {
    result_140 = NIM_TRUE;}
  return result_140;}
NB8 resize_0_Iz8tg361_comaa5xpt1(seq_0_I50urnw_chu5m1rja1* dest_24, NI32 addedElements_24){
  NB8 result_142;
  NI32 X60Qx_1923 = capInBytes_0_Ihvsegh1_chu5m1rja1((*dest_24));
  NI32 oldCap_3 = ((NI32)(X60Qx_1923 / sizeof(Value_0_valzr1t4f)));
  NI32 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_24);
  NI32 memSize_23 = memSizeInBytes_0_Itmy7ww1_chu5m1rja1(newCap_3);
  void* X60Qx_1924 = realloc_1_sysvq0asl(((void*)((void*)(*dest_24).data_0)), memSize_23);
  (*dest_24).data_0 = ((Value_0_valzr1t4f*)X60Qx_1924);
  if ((*dest_24).data_0 == NIM_NIL){
    (*dest_24).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_23);
    result_142 = NIM_FALSE;}
  else {
    result_142 = NIM_TRUE;}
  return result_142;}
NB8 resize_0_Itdw5n21_comaa5xpt1(seq_0_Ie9rikd_chu5m1rja1* dest_25, NI32 addedElements_25){
  NB8 result_144;
  NI32 X60Qx_1926 = capInBytes_0_I02yj151_chu5m1rja1((*dest_25));
  NI32 oldCap_4 = ((NI32)(X60Qx_1926 / sizeof(MagicSpec_0_chu5m1rja1)));
  NI32 newCap_4 = recalcCap_0_sysvq0asl(oldCap_4, addedElements_25);
  NI32 memSize_24 = memSizeInBytes_0_Ikrq3db1_chu5m1rja1(newCap_4);
  void* X60Qx_1927 = realloc_1_sysvq0asl(((void*)((void*)(*dest_25).data_0)), memSize_24);
  (*dest_25).data_0 = ((MagicSpec_0_chu5m1rja1*)X60Qx_1927);
  if ((*dest_25).data_0 == NIM_NIL){
    (*dest_25).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_24);
    result_144 = NIM_FALSE;}
  else {
    result_144 = NIM_TRUE;}
  return result_144;}
NB8 resize_0_Ikaiuf5_comaa5xpt1(seq_0_Iknt7a3_chu5m1rja1* dest_26, NI32 addedElements_26){
  NB8 result_146;
  NI32 X60Qx_1929 = capInBytes_0_Iccedzq_chu5m1rja1((*dest_26));
  NI32 oldCap_5 = ((NI32)(X60Qx_1929 / sizeof(ConvSpec_0_chu5m1rja1)));
  NI32 newCap_5 = recalcCap_0_sysvq0asl(oldCap_5, addedElements_26);
  NI32 memSize_25 = memSizeInBytes_0_I3p8ndy_chu5m1rja1(newCap_5);
  void* X60Qx_1930 = realloc_1_sysvq0asl(((void*)((void*)(*dest_26).data_0)), memSize_25);
  (*dest_26).data_0 = ((ConvSpec_0_chu5m1rja1*)X60Qx_1930);
  if ((*dest_26).data_0 == NIM_NIL){
    (*dest_26).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_25);
    result_146 = NIM_FALSE;}
  else {
    result_146 = NIM_TRUE;}
  return result_146;}
NB8 resize_0_I9r5bp3_comaa5xpt1(seq_0_Id5h4uf_chu5m1rja1* dest_28, NI32 addedElements_28){
  NB8 result_150;
  NI32 X60Qx_1935 = capInBytes_0_Ihi6tep_chu5m1rja1((*dest_28));
  NI32 oldCap_7 = ((NI32)(X60Qx_1935 / sizeof(GatedCall_0_chu5m1rja1)));
  NI32 newCap_7 = recalcCap_0_sysvq0asl(oldCap_7, addedElements_28);
  NI32 memSize_27 = memSizeInBytes_0_Ifccb5x1_chu5m1rja1(newCap_7);
  void* X60Qx_1936 = realloc_1_sysvq0asl(((void*)((void*)(*dest_28).data_0)), memSize_27);
  (*dest_28).data_0 = ((GatedCall_0_chu5m1rja1*)X60Qx_1936);
  if ((*dest_28).data_0 == NIM_NIL){
    (*dest_28).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_27);
    result_150 = NIM_FALSE;}
  else {
    result_150 = NIM_TRUE;}
  return result_150;}
NB8 resize_0_Ib3lf9y1_comaa5xpt1(seq_0_I2neof81_chu5m1rja1* dest_29, NI32 addedElements_29){
  NB8 result_152;
  NI32 X60Qx_1938 = capInBytes_0_I27hxyl_chu5m1rja1((*dest_29));
  NI32 oldCap_8 = ((NI32)(X60Qx_1938 / sizeof(ObjInfo_0_chu5m1rja1)));
  NI32 newCap_8 = recalcCap_0_sysvq0asl(oldCap_8, addedElements_29);
  NI32 memSize_28 = memSizeInBytes_0_I6hayax_chu5m1rja1(newCap_8);
  void* X60Qx_1939 = realloc_1_sysvq0asl(((void*)((void*)(*dest_29).data_0)), memSize_28);
  (*dest_29).data_0 = ((ObjInfo_0_chu5m1rja1*)X60Qx_1939);
  if ((*dest_29).data_0 == NIM_NIL){
    (*dest_29).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_28);
    result_152 = NIM_FALSE;}
  else {
    result_152 = NIM_TRUE;}
  return result_152;}
static inline NI32 capInBytes_0_I0ia6g61_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_231){
  NI32 result_156;
  NI32 X60Qx_32;
  if ((!(s_231.data_0 == NIM_NIL))){
    NI32 X60Qx_1944 = allocatedSize_0_sysvq0asl(((void*)((void*)s_231.data_0)));
    X60Qx_32 = X60Qx_1944;}
  else {
    X60Qx_32 = 0;}
  result_156 = X60Qx_32;
  return result_156;}
NB8 resize_0_I6nu0dd_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1* dest_31, NI32 addedElements_31){
  NB8 result_157;
  NI32 X60Qx_1945 = capInBytes_0_I0ia6g61_comaa5xpt1((*dest_31));
  NI32 oldCap_10 = ((NI32)(X60Qx_1945 / sizeof(Cursor_0_nifb6mq6y1)));
  NI32 newCap_10 = recalcCap_0_sysvq0asl(oldCap_10, addedElements_31);
  NI32 memSize_30 = memSizeInBytes_0_I3r8cpo1_comaa5xpt1(newCap_10);
  void* X60Qx_1946 = realloc_1_sysvq0asl(((void*)((void*)(*dest_31).data_0)), memSize_30);
  (*dest_31).data_0 = ((Cursor_0_nifb6mq6y1*)X60Qx_1946);
  if ((*dest_31).data_0 == NIM_NIL){
    (*dest_31).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_30);
    result_157 = NIM_FALSE;}
  else {
    result_157 = NIM_TRUE;}
  return result_157;}
static inline NI32 memSizeInBytes_0_I11sygp_comaa5xpt1(NI32 size_63){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_161;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_63, sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_161 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_161 = ((NI32)2147483647);}
  return result_161;}
static inline NI32 memSizeInBytes_0_Ichxqj91_comaa5xpt1(NI32 size_64){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_162;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_64, sizeof(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_162 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_162 = ((NI32)2147483647);}
  return result_162;}
static inline NI32 memSizeInBytes_0_I86jswb1_comaa5xpt1(NI32 size_65){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_163;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_65, sizeof(FinScope_0_comaa5xpt1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_163 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_163 = ((NI32)2147483647);}
  return result_163;}
NB8 resize_0_I91teg71_comaa5xpt1(seq_0_Inaua171_chu5m1rja1* dest_32, NI32 addedElements_32){
  NB8 result_165;
  NI32 X60Qx_1948 = capInBytes_0_Ifvg4nq1_chu5m1rja1((*dest_32));
  NI32 oldCap_11 = ((NI32)(X60Qx_1948 / sizeof(Proc_0_chu5m1rja1)));
  NI32 newCap_11 = recalcCap_0_sysvq0asl(oldCap_11, addedElements_32);
  NI32 memSize_31 = memSizeInBytes_0_Iq7wi6a_chu5m1rja1(newCap_11);
  void* X60Qx_1949 = realloc_1_sysvq0asl(((void*)((void*)(*dest_32).data_0)), memSize_31);
  (*dest_32).data_0 = ((Proc_0_chu5m1rja1*)X60Qx_1949);
  if ((*dest_32).data_0 == NIM_NIL){
    (*dest_32).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_31);
    result_165 = NIM_FALSE;}
  else {
    result_165 = NIM_TRUE;}
  return result_165;}
NB8 resize_0_Ijlhibe1_comaa5xpt1(seq_0_Iioxqbu_chu5m1rja1* dest_33, NI32 addedElements_33){
  NB8 result_167;
  NI32 X60Qx_1951 = capInBytes_0_I38sirs1_chu5m1rja1((*dest_33));
  NI32 oldCap_12 = ((NI32)(X60Qx_1951 / sizeof(GlobalSeed_0_chu5m1rja1)));
  NI32 newCap_12 = recalcCap_0_sysvq0asl(oldCap_12, addedElements_33);
  NI32 memSize_32 = memSizeInBytes_0_Iywqtuz_chu5m1rja1(newCap_12);
  void* X60Qx_1952 = realloc_1_sysvq0asl(((void*)((void*)(*dest_33).data_0)), memSize_32);
  (*dest_33).data_0 = ((GlobalSeed_0_chu5m1rja1*)X60Qx_1952);
  if ((*dest_33).data_0 == NIM_NIL){
    (*dest_33).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_32);
    result_167 = NIM_FALSE;}
  else {
    result_167 = NIM_TRUE;}
  return result_167;}
static inline NI32 capInBytes_0_Itl2tw2_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_235){
  NI32 result_170;
  NI32 X60Qx_35;
  if ((!(s_235.data_0 == NIM_NIL))){
    NI32 X60Qx_1955 = allocatedSize_0_sysvq0asl(((void*)((void*)s_235.data_0)));
    X60Qx_35 = X60Qx_1955;}
  else {
    X60Qx_35 = 0;}
  result_170 = X60Qx_35;
  return result_170;}
NB8 resize_0_I606t801_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* dest_34, NI32 addedElements_34){
  NB8 result_171;
  NI32 X60Qx_1956 = capInBytes_0_Itl2tw2_comaa5xpt1((*dest_34));
  NI32 oldCap_13 = ((NI32)(X60Qx_1956 / sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*)));
  NI32 newCap_13 = recalcCap_0_sysvq0asl(oldCap_13, addedElements_34);
  NI32 memSize_33 = memSizeInBytes_0_I11sygp_comaa5xpt1(newCap_13);
  void* X60Qx_1957 = realloc_1_sysvq0asl(((void*)((void*)(*dest_34).data_0)), memSize_33);
  (*dest_34).data_0 = ((X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1**)X60Qx_1957);
  if ((*dest_34).data_0 == NIM_NIL){
    (*dest_34).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_33);
    result_171 = NIM_FALSE;}
  else {
    result_171 = NIM_TRUE;}
  return result_171;}
static inline NI32* rawData_0_Ic25u3r_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_236){
  NI32* result_172;
  result_172 = s_236.data_0;
  return result_172;}
static inline NI32 len_6_I9632ti1_comaa5xpt1(openArray_0_Inqs7yx_comaa5xpt1 a_32){
  NI32 result_173;
  result_173 = a_32.len_0;
  return result_173;}
static inline NI32* getQ_10_I053icq_comaa5xpt1(openArray_0_Inqs7yx_comaa5xpt1 x_21, NI32 idx_24){
  NB8 X60Qx_1958;
  if (0 <= idx_24){
    X60Qx_1958 = (idx_24 < x_21.len_0);}
  else {
    X60Qx_1958 = NIM_FALSE;}
  if ((!X60Qx_1958)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  NI32* result_174;
  result_174 = (&x_21.a_0[idx_24]);
  return result_174;}
void shrink_0_Irsuiak1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_237, NI32 newLen_16){
  NI32 i_68 = ((NI32)((*s_237).len_0 - 1));
  {
    while (newLen_16 <= i_68){
      eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*s_237).data_0[i_68]);
      dec_1_I0nzoz91_ast8ri79k((&i_68));}}
  whileStmtLabel_0: ;
  (*s_237).len_0 = newLen_16;}
void growUnsafe_0_Io18vke_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_238, NI32 newLen_17){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_17, sizeof(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_0 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_1959 = capInBytes_0_Itl2tw2_comaa5xpt1((*s_238));
  if (X60Qx_1959 < newSize_0){
    NB8 X60Qx_1960 = resize_0_I606t801_comaa5xpt1(s_238, ((NI32)(newLen_17 - (*s_238).len_0)));
    if ((!X60Qx_1960)){
      return;}}
  (*s_238).len_0 = newLen_17;}
NB8 resize_0_Ig21eot_comaa5xpt1(seq_0_Ir067xu1_chu5m1rja1* dest_35, NI32 addedElements_35){
  NB8 result_176;
  NI32 X60Qx_1962 = capInBytes_0_Ivj8jl41_chu5m1rja1((*dest_35));
  NI32 oldCap_14 = ((NI32)(X60Qx_1962 / sizeof(MethodSite_0_chu5m1rja1)));
  NI32 newCap_14 = recalcCap_0_sysvq0asl(oldCap_14, addedElements_35);
  NI32 memSize_34 = memSizeInBytes_0_Iqssf4e1_chu5m1rja1(newCap_14);
  void* X60Qx_1963 = realloc_1_sysvq0asl(((void*)((void*)(*dest_35).data_0)), memSize_34);
  (*dest_35).data_0 = ((MethodSite_0_chu5m1rja1*)X60Qx_1963);
  if ((*dest_35).data_0 == NIM_NIL){
    (*dest_35).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_34);
    result_176 = NIM_FALSE;}
  else {
    result_176 = NIM_TRUE;}
  return result_176;}
static inline NI32 memSizeInBytes_0_I3r8cpo1_comaa5xpt1(NI32 size_66){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_177;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_66, sizeof(Cursor_0_nifb6mq6y1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_177 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_177 = ((NI32)2147483647);}
  return result_177;}
static inline NI32 memSizeInBytes_0_I03jys01_comaa5xpt1(NI32 size_67){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_178;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_67, sizeof(seq_0_Ift2sne_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_178 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_178 = ((NI32)2147483647);}
  return result_178;}
static inline NI32 capInBytes_0_Iri1hlt1_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 s_240){
  NI32 result_179;
  NI32 X60Qx_37;
  if ((!(s_240.data_0 == NIM_NIL))){
    NI32 X60Qx_1964 = allocatedSize_0_sysvq0asl(((void*)((void*)s_240.data_0)));
    X60Qx_37 = X60Qx_1964;}
  else {
    X60Qx_37 = 0;}
  result_179 = X60Qx_37;
  return result_179;}
NB8 resize_0_I9lztdq1_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1* dest_36, NI32 addedElements_36){
  NB8 result_180;
  NI32 X60Qx_1965 = capInBytes_0_Iri1hlt1_comaa5xpt1((*dest_36));
  NI32 oldCap_15 = ((NI32)(X60Qx_1965 / sizeof(seq_0_Ift2sne_chu5m1rja1)));
  NI32 newCap_15 = recalcCap_0_sysvq0asl(oldCap_15, addedElements_36);
  NI32 memSize_35 = memSizeInBytes_0_I03jys01_comaa5xpt1(newCap_15);
  void* X60Qx_1966 = realloc_1_sysvq0asl(((void*)((void*)(*dest_36).data_0)), memSize_35);
  (*dest_36).data_0 = ((seq_0_Ift2sne_chu5m1rja1*)X60Qx_1966);
  if ((*dest_36).data_0 == NIM_NIL){
    (*dest_36).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_35);
    result_180 = NIM_FALSE;}
  else {
    result_180 = NIM_TRUE;}
  return result_180;}
seq_0_Ift2sne_chu5m1rja1 getQ_16_Ijvcpzq1_comaa5xpt1(seq_0_Ift2sne_chu5m1rja1 s_241, HSlice_0_Inzqy8d_comaa5xpt1 x_22){
  seq_0_Ift2sne_chu5m1rja1 result_181;
  NI32 a_33 = max_2_sysvq0asl(x_22.a_0, 0);
  NI32 b_14 = min_2_sysvq0asl(x_22.b_0, ((NI32)(s_241.len_0 - 1)));
  NI32 X60Qx_38;
  if (a_33 <= b_14){
    X60Qx_38 = ((NI32)(((NI32)(b_14 - a_33)) + 1));}
  else {
    X60Qx_38 = 0;}
  NI32 n_56 = X60Qx_38;
  seq_0_Ift2sne_chu5m1rja1 X60Qx_1967 = newSeqUninit_0_Iggfvwp_chu5m1rja1(n_56);
  result_181 = X60Qx_1967;
  NI32 i_69 = 0;
  {
    while (i_69 < n_56){
      NI32* X60Qx_1968 = rawData_0_Ic25u3r_comaa5xpt1(result_181);
      NI32* X60Qx_1969 = rawData_0_Ic25u3r_comaa5xpt1(s_241);
      X60Qx_1968[i_69] = X60Qx_1969[((NI32)(a_33 + i_69))];
      inc_1_I6wjjge_aow2h993l1((&i_69));}}
  whileStmtLabel_0: ;
  return result_181;}
static inline NI32 capInBytes_0_Idtacij1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1 s_242){
  NI32 result_182;
  NI32 X60Qx_39;
  if ((!(s_242.data_0 == NIM_NIL))){
    NI32 X60Qx_1970 = allocatedSize_0_sysvq0asl(((void*)((void*)s_242.data_0)));
    X60Qx_39 = X60Qx_1970;}
  else {
    X60Qx_39 = 0;}
  result_182 = X60Qx_39;
  return result_182;}
NB8 resize_0_Iiusqmu1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* dest_37, NI32 addedElements_37){
  NB8 result_183;
  NI32 X60Qx_1971 = capInBytes_0_Idtacij1_comaa5xpt1((*dest_37));
  NI32 oldCap_16 = ((NI32)(X60Qx_1971 / sizeof(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1*)));
  NI32 newCap_16 = recalcCap_0_sysvq0asl(oldCap_16, addedElements_37);
  NI32 memSize_36 = memSizeInBytes_0_Ichxqj91_comaa5xpt1(newCap_16);
  void* X60Qx_1972 = realloc_1_sysvq0asl(((void*)((void*)(*dest_37).data_0)), memSize_36);
  (*dest_37).data_0 = ((X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1**)X60Qx_1972);
  if ((*dest_37).data_0 == NIM_NIL){
    (*dest_37).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_36);
    result_183 = NIM_FALSE;}
  else {
    result_183 = NIM_TRUE;}
  return result_183;}
void shrink_0_I6q9rej1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* s_243, NI32 newLen_18){
  NI32 i_70 = ((NI32)((*s_243).len_0 - 1));
  {
    while (newLen_18 <= i_70){
      eQdestroyQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1((*s_243).data_0[i_70]);
      dec_1_I0nzoz91_ast8ri79k((&i_70));}}
  whileStmtLabel_0: ;
  (*s_243).len_0 = newLen_18;}
void growUnsafe_0_Itey597_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1* s_244, NI32 newLen_19){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_19, sizeof(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_1 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_1973 = capInBytes_0_Idtacij1_comaa5xpt1((*s_244));
  if (X60Qx_1973 < newSize_1){
    NB8 X60Qx_1974 = resize_0_Iiusqmu1_comaa5xpt1(s_244, ((NI32)(newLen_19 - (*s_244).len_0)));
    if ((!X60Qx_1974)){
      return;}}
  (*s_244).len_0 = newLen_19;}
static inline NI32 capInBytes_0_Ipkd9yl_comaa5xpt1(seq_0_I806bg1_comaa5xpt1 s_245){
  NI32 result_184;
  NI32 X60Qx_40;
  if ((!(s_245.data_0 == NIM_NIL))){
    NI32 X60Qx_1975 = allocatedSize_0_sysvq0asl(((void*)((void*)s_245.data_0)));
    X60Qx_40 = X60Qx_1975;}
  else {
    X60Qx_40 = 0;}
  result_184 = X60Qx_40;
  return result_184;}
NB8 resize_0_Ix9q1o91_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* dest_38, NI32 addedElements_38){
  NB8 result_185;
  NI32 X60Qx_1976 = capInBytes_0_Ipkd9yl_comaa5xpt1((*dest_38));
  NI32 oldCap_17 = ((NI32)(X60Qx_1976 / sizeof(FinScope_0_comaa5xpt1)));
  NI32 newCap_17 = recalcCap_0_sysvq0asl(oldCap_17, addedElements_38);
  NI32 memSize_37 = memSizeInBytes_0_I86jswb1_comaa5xpt1(newCap_17);
  void* X60Qx_1977 = realloc_1_sysvq0asl(((void*)((void*)(*dest_38).data_0)), memSize_37);
  (*dest_38).data_0 = ((FinScope_0_comaa5xpt1*)X60Qx_1977);
  if ((*dest_38).data_0 == NIM_NIL){
    (*dest_38).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_37);
    result_185 = NIM_FALSE;}
  else {
    result_185 = NIM_TRUE;}
  return result_185;}
void shrink_0_Ic6ijzf_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* s_246, NI32 newLen_20){
  NI32 i_71 = ((NI32)((*s_246).len_0 - 1));
  {
    while (newLen_20 <= i_71){
      eQdestroyQ_SX46inX53cope0comaa5xpt1_0_comaa5xpt1((*s_246).data_0[i_71]);
      dec_1_I0nzoz91_ast8ri79k((&i_71));}}
  whileStmtLabel_0: ;
  (*s_246).len_0 = newLen_20;}
void growUnsafe_0_I2ptrki_comaa5xpt1(seq_0_I806bg1_comaa5xpt1* s_247, NI32 newLen_21){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_21, sizeof(FinScope_0_comaa5xpt1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_2 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_1978 = capInBytes_0_Ipkd9yl_comaa5xpt1((*s_247));
  if (X60Qx_1978 < newSize_2){
    NB8 X60Qx_1979 = resize_0_Ix9q1o91_comaa5xpt1(s_247, ((NI32)(newLen_21 - (*s_247).len_0)));
    if ((!X60Qx_1979)){
      return;}}
  (*s_247).len_0 = newLen_21;}
seq_0_Iscf6bn_comaa5xpt1 getQ_16_Iansvof1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_248, HSlice_0_Inzqy8d_comaa5xpt1 x_23){
  seq_0_Iscf6bn_comaa5xpt1 result_186;
  NI32 a_34 = max_2_sysvq0asl(x_23.a_0, 0);
  NI32 b_15 = min_2_sysvq0asl(x_23.b_0, ((NI32)(s_248.len_0 - 1)));
  NI32 X60Qx_41;
  if (a_34 <= b_15){
    X60Qx_41 = ((NI32)(((NI32)(b_15 - a_34)) + 1));}
  else {
    X60Qx_41 = 0;}
  NI32 n_57 = X60Qx_41;
  seq_0_Iscf6bn_comaa5xpt1 X60Qx_1980 = newSeqUninit_0_Ib8z3ow_comaa5xpt1(n_57);
  result_186 = X60Qx_1980;
  NI32 i_72 = 0;
  {
    while (i_72 < n_57){
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1981 = rawData_0_Iabis8p_comaa5xpt1(result_186);
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** X60Qx_1982 = rawData_0_Iabis8p_comaa5xpt1(s_248);
      X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* X60Qx_1983 = eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qx_1982[((NI32)(a_34 + i_72))]);
      X60Qx_1981[i_72] = X60Qx_1983;
      inc_1_I6wjjge_aow2h993l1((&i_72));}}
  whileStmtLabel_0: ;
  return result_186;}
static inline X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** rawData_0_Iabis8p_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_249){
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** result_187;
  result_187 = s_249.data_0;
  return result_187;}
static inline NI32 len_6_Ie5pl0g_comaa5xpt1(openArray_0_I6xd9vz_comaa5xpt1 a_35){
  NI32 result_188;
  result_188 = a_35.len_0;
  return result_188;}
static inline X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** getQ_10_Itsygq7_comaa5xpt1(openArray_0_I6xd9vz_comaa5xpt1 x_24, NI32 idx_25){
  NB8 X60Qx_1984;
  if (0 <= idx_25){
    X60Qx_1984 = (idx_25 < x_24.len_0);}
  else {
    X60Qx_1984 = NIM_FALSE;}
  if ((!X60Qx_1984)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1** result_189;
  result_189 = (&x_24.a_0[idx_25]);
  return result_189;}
static inline NI32 capInBytes_0_Iz2n5ul_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1 s_250){
  NI32 result_190;
  NI32 X60Qx_42;
  if ((!(s_250.data_0 == NIM_NIL))){
    NI32 X60Qx_1985 = allocatedSize_0_sysvq0asl(((void*)((void*)s_250.data_0)));
    X60Qx_42 = X60Qx_1985;}
  else {
    X60Qx_42 = 0;}
  result_190 = X60Qx_42;
  return result_190;}
NB8 resize_0_Iymm5xw_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* dest_39, NI32 addedElements_39){
  NB8 result_191;
  NI32 X60Qx_1986 = capInBytes_0_Iz2n5ul_comaa5xpt1((*dest_39));
  NI32 oldCap_18 = ((NI32)(X60Qx_1986 / sizeof(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1*)));
  NI32 newCap_18 = recalcCap_0_sysvq0asl(oldCap_18, addedElements_39);
  NI32 memSize_38 = memSizeInBytes_0_I68vum51_comaa5xpt1(newCap_18);
  void* X60Qx_1987 = realloc_1_sysvq0asl(((void*)((void*)(*dest_39).data_0)), memSize_38);
  (*dest_39).data_0 = ((X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1**)X60Qx_1987);
  if ((*dest_39).data_0 == NIM_NIL){
    (*dest_39).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_38);
    result_191 = NIM_FALSE;}
  else {
    result_191 = NIM_TRUE;}
  return result_191;}
void shrink_0_I5z0zky1_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* s_251, NI32 newLen_22){
  NI32 i_73 = ((NI32)((*s_251).len_0 - 1));
  {
    while (newLen_22 <= i_73){
      eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1((*s_251).data_0[i_73]);
      dec_1_I0nzoz91_ast8ri79k((&i_73));}}
  whileStmtLabel_0: ;
  (*s_251).len_0 = newLen_22;}
void growUnsafe_0_I1b8vl2_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1* s_252, NI32 newLen_23){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(newLen_23, sizeof(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI32 newSize_3 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    oomHandler_0_sysvq0asl(((NI32)2147483647));
    return;}
  NI32 X60Qx_1988 = capInBytes_0_Iz2n5ul_comaa5xpt1((*s_252));
  if (X60Qx_1988 < newSize_3){
    NB8 X60Qx_1989 = resize_0_Iymm5xw_comaa5xpt1(s_252, ((NI32)(newLen_23 - (*s_252).len_0)));
    if ((!X60Qx_1989)){
      return;}}
  (*s_252).len_0 = newLen_23;}
static inline MethodIndexEntry_0_sempjk6bn1* rawData_0_I0uy4q51_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_253){
  MethodIndexEntry_0_sempjk6bn1* result_192;
  result_192 = s_253.data_0;
  return result_192;}
static inline NI32 len_6_I8gnayb_comaa5xpt1(openArray_0_In1h8lr1_comaa5xpt1 a_36){
  NI32 result_193;
  result_193 = a_36.len_0;
  return result_193;}
static inline MethodIndexEntry_0_sempjk6bn1* getQ_10_Izev5kw1_comaa5xpt1(openArray_0_In1h8lr1_comaa5xpt1 x_25, NI32 idx_26){
  NB8 X60Qx_1990;
  if (0 <= idx_26){
    X60Qx_1990 = (idx_26 < x_25.len_0);}
  else {
    X60Qx_1990 = NIM_FALSE;}
  if ((!X60Qx_1990)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  MethodIndexEntry_0_sempjk6bn1* result_194;
  result_194 = (&x_25.a_0[idx_26]);
  return result_194;}
NB8 resize_0_I6yc4yx_comaa5xpt1(seq_0_I88k8j01_chu5m1rja1* dest_40, NI32 addedElements_40){
  NB8 result_196;
  NI32 X60Qx_1992 = capInBytes_0_I6qhu63_chu5m1rja1((*dest_40));
  NI32 oldCap_19 = ((NI32)(X60Qx_1992 / sizeof(MethodEntry_0_chu5m1rja1)));
  NI32 newCap_19 = recalcCap_0_sysvq0asl(oldCap_19, addedElements_40);
  NI32 memSize_39 = memSizeInBytes_0_Ij5c7dh1_chu5m1rja1(newCap_19);
  void* X60Qx_1993 = realloc_1_sysvq0asl(((void*)((void*)(*dest_40).data_0)), memSize_39);
  (*dest_40).data_0 = ((MethodEntry_0_chu5m1rja1*)X60Qx_1993);
  if ((*dest_40).data_0 == NIM_NIL){
    (*dest_40).len_0 = 0;
    oomHandler_0_sysvq0asl(memSize_39);
    result_196 = NIM_FALSE;}
  else {
    result_196 = NIM_TRUE;}
  return result_196;}
static inline ObjInfo_0_chu5m1rja1* rawData_0_Icrhavl1_comaa5xpt1(seq_0_I2neof81_chu5m1rja1 s_255){
  ObjInfo_0_chu5m1rja1* result_197;
  result_197 = s_255.data_0;
  return result_197;}
static inline NI32 len_6_Io9vvx7_comaa5xpt1(openArray_0_Iz8j0ra_comaa5xpt1 a_37){
  NI32 result_198;
  result_198 = a_37.len_0;
  return result_198;}
static inline ObjInfo_0_chu5m1rja1* getQ_10_Ij5s4n11_comaa5xpt1(openArray_0_Iz8j0ra_comaa5xpt1 x_26, NI32 idx_27){
  NB8 X60Qx_1994;
  if (0 <= idx_27){
    X60Qx_1994 = (idx_27 < x_26.len_0);}
  else {
    X60Qx_1994 = NIM_FALSE;}
  if ((!X60Qx_1994)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  ObjInfo_0_chu5m1rja1* result_199;
  result_199 = (&x_26.a_0[idx_27]);
  return result_199;}
static inline ObjSpec_0_chu5m1rja1* rawData_0_I3cvan_comaa5xpt1(seq_0_Isww99s_chu5m1rja1 s_256){
  ObjSpec_0_chu5m1rja1* result_200;
  result_200 = s_256.data_0;
  return result_200;}
static inline NI32 len_6_I7v6wrd_comaa5xpt1(openArray_0_I94odo91_comaa5xpt1 a_38){
  NI32 result_201;
  result_201 = a_38.len_0;
  return result_201;}
static inline ObjSpec_0_chu5m1rja1* getQ_10_I3bn8xm1_comaa5xpt1(openArray_0_I94odo91_comaa5xpt1 x_27, NI32 idx_28){
  NB8 X60Qx_1995;
  if (0 <= idx_28){
    X60Qx_1995 = (idx_28 < x_27.len_0);}
  else {
    X60Qx_1995 = NIM_FALSE;}
  if ((!X60Qx_1995)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  ObjSpec_0_chu5m1rja1* result_202;
  result_202 = (&x_27.a_0[idx_28]);
  return result_202;}
static inline NU32* rawData_0_I9ky6gs1_comaa5xpt1(seq_0_In6doa_ast8ri79k s_257){
  NU32* result_203;
  result_203 = s_257.data_0;
  return result_203;}
static inline NI32 len_6_Ijqv54i_comaa5xpt1(openArray_0_Ir53qdx_comaa5xpt1 a_39){
  NI32 result_204;
  result_204 = a_39.len_0;
  return result_204;}
static inline NU32* getQ_10_Ibernwj1_comaa5xpt1(openArray_0_Ir53qdx_comaa5xpt1 x_28, NI32 idx_29){
  NB8 X60Qx_1996;
  if (0 <= idx_29){
    X60Qx_1996 = (idx_29 < x_28.len_0);}
  else {
    X60Qx_1996 = NIM_FALSE;}
  if ((!X60Qx_1996)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  NU32* result_205;
  result_205 = (&x_28.a_0[idx_29]);
  return result_205;}
static inline string_0_sysvq0asl* rawData_0_I65w5sr_comaa5xpt1(seq_0_Ixdx2fh1_ast8ri79k s_258){
  string_0_sysvq0asl* result_206;
  result_206 = s_258.data_0;
  return result_206;}
static inline NI32 len_6_Igv2wyu1_comaa5xpt1(openArray_0_Ig73pnk_comaa5xpt1 a_40){
  NI32 result_207;
  result_207 = a_40.len_0;
  return result_207;}
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_comaa5xpt1(openArray_0_Ig73pnk_comaa5xpt1 x_29, NI32 idx_30){
  NB8 X60Qx_1997;
  if (0 <= idx_30){
    X60Qx_1997 = (idx_30 < x_29.len_0);}
  else {
    X60Qx_1997 = NIM_FALSE;}
  if ((!X60Qx_1997)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I3193426178656842898_comaa5xpt1)}
    );}
  string_0_sysvq0asl* result_208;
  result_208 = (&x_29.a_0[idx_30]);
  return result_208;}
static inline NI32 memSizeInBytes_0_I68vum51_comaa5xpt1(NI32 size_78){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_220;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_78, sizeof(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1*), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_220 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_220 = ((NI32)2147483647);}
  return result_220;}
void eQdestroy_1_Ij4pznj1_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 s_322){
  if ((!(s_322.data_0 == NIM_NIL))){
    NI32 i_82 = 0;
    {
      while (i_82 < s_322.len_0){
        eQdestroy_1_Iv9ij5i1_chu5m1rja1(s_322.data_0[i_82]);
        inc_1_I6wjjge_aow2h993l1((&i_82));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_322.data_0)));}}
static inline void eQwasMoved_1_I1l3xdo1_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1* s_323){
  (*s_323).len_0 = 0;
  (*s_323).data_0 = NIM_NIL;}
seq_0_Ik7wkpe_comaa5xpt1 eQdup_1_Iqlupf9_comaa5xpt1(seq_0_Ik7wkpe_comaa5xpt1 a_72){
  seq_0_Ik7wkpe_comaa5xpt1 result_226;
  seq_0_Ik7wkpe_comaa5xpt1 X60Qx_2009 = newSeqUninit_0_Idxnvmq_comaa5xpt1(a_72.len_0);
  result_226 = X60Qx_2009;
  NI32 i_83 = 0;
  {
    while (i_83 < a_72.len_0){
      seq_0_Ift2sne_chu5m1rja1 X60Qx_2010 = eQdup_1_Iplow11_chu5m1rja1(a_72.data_0[i_83]);
      result_226.data_0[i_83] = X60Qx_2010;
      inc_1_I6wjjge_aow2h993l1((&i_83));}}
  whileStmtLabel_0: ;
  return result_226;}
void eQdestroy_1_Irljx3e1_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1 s_326){
  if ((!(s_326.data_0 == NIM_NIL))){
    NI32 i_90 = 0;
    {
      while (i_90 < s_326.len_0){
        eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(s_326.data_0[i_90]);
        inc_1_I6wjjge_aow2h993l1((&i_90));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_326.data_0)));}}
static inline void eQwasMoved_1_Iw33v4x_comaa5xpt1(seq_0_Iscf6bn_comaa5xpt1* s_327){
  (*s_327).len_0 = 0;
  (*s_327).data_0 = NIM_NIL;}
void eQdestroy_1_Io42ulm1_comaa5xpt1(seq_0_I806bg1_comaa5xpt1 s_328){
  if ((!(s_328.data_0 == NIM_NIL))){
    NI32 i_94 = 0;
    {
      while (i_94 < s_328.len_0){
        eQdestroyQ_SX46inX53cope0comaa5xpt1_0_comaa5xpt1(s_328.data_0[i_94]);
        inc_1_I6wjjge_aow2h993l1((&i_94));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_328.data_0)));}}
void eQdestroy_1_Ioxdx8k1_comaa5xpt1(seq_0_Igm8woo1_comaa5xpt1 s_330){
  if ((!(s_330.data_0 == NIM_NIL))){
    NI32 i_98 = 0;
    {
      while (i_98 < s_330.len_0){
        eQdestroyQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(s_330.data_0[i_98]);
        inc_1_I6wjjge_aow2h993l1((&i_98));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_330.data_0)));}}
void eQdestroy_1_Ir7cqbo_comaa5xpt1(seq_0_Isyzizu1_comaa5xpt1 s_350){
  if ((!(s_350.data_0 == NIM_NIL))){
    NI32 i_138 = 0;
    {
      while (i_138 < s_350.len_0){
        eQdestroy_0_nifb6mq6y1((&s_350.data_0[i_138]));
        inc_1_I6wjjge_aow2h993l1((&i_138));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_350.data_0)));}}
void eQdestroy_1_Iziv4mp_comaa5xpt1(seq_0_Ik8dusv_comaa5xpt1 s_356){
  if ((!(s_356.data_0 == NIM_NIL))){
    NI32 i_150 = 0;
    {
      while (i_150 < s_356.len_0){
        eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(s_356.data_0[i_150]);
        inc_1_I6wjjge_aow2h993l1((&i_150));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_356.data_0)));}}
void eQdestroy_1_Iph9dp4_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_381){
  if ((!(s_381.data_0 == NIM_NIL))){
    NI32 i_186 = 0;
    {
      while (i_186 < s_381.len_0){
        inc_1_I6wjjge_aow2h993l1((&i_186));}}
    whileStmtLabel_0: ;
    dealloc_1_sysvq0asl(((void*)((void*)s_381.data_0)));}}
static inline void eQwasMoved_1_Ibnkc9q_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1* s_382){
  (*s_382).len_0 = 0;
  (*s_382).data_0 = NIM_NIL;}
static inline seq_0_Idl3iy1_comaa5xpt1 newSeqUninit_0_Itwybvv1_comaa5xpt1(NI32 size_114){
  seq_0_Idl3iy1_comaa5xpt1 result_275;
  if (size_114 == 0){
    result_275 = (seq_0_Idl3iy1_comaa5xpt1){
      .len_0 = size_114, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_78 = memSizeInBytes_0_Ikui0mk_comaa5xpt1(size_114);
    void* X60Qx_2166 = alloc_1_sysvq0asl(memSize_78);
    result_275 = (seq_0_Idl3iy1_comaa5xpt1){
      .len_0 = size_114, .data_0 = ((MethodIndexEntry_0_sempjk6bn1*)X60Qx_2166)}
    ;
    if ((!(result_275.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_2167 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_275.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_78);}}
  return result_275;}
static inline NI32 capInBytes_0_Irxk45k1_comaa5xpt1(seq_0_Idl3iy1_comaa5xpt1 s_391){
  NI32 result_276;
  NI32 X60Qx_52;
  if ((!(s_391.data_0 == NIM_NIL))){
    NI32 X60Qx_2168 = allocatedSize_0_sysvq0asl(((void*)((void*)s_391.data_0)));
    X60Qx_52 = X60Qx_2168;}
  else {
    X60Qx_52 = 0;}
  result_276 = X60Qx_52;
  return result_276;}
static inline NI32 memSizeInBytes_0_Ikui0mk_comaa5xpt1(NI32 size_115){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_277;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_115, sizeof(MethodIndexEntry_0_sempjk6bn1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_277 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_277 = ((NI32)2147483647);}
  return result_277;}
void eQdestroyQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1(SymMap_0_comaa5xpt1 dest_0){
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(dest_0.vals_0);
  eQdestroy_1_Iscb4i31_ast8ri79k(dest_0.keys_0);}
void eQwasmovedQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1(SymMap_0_comaa5xpt1* dest_0){
  eQwasMoved_1_I2k4kel_ast8ri79k((&(*dest_0).keys_0));
  eQwasMoved_1_Ix88qzs1_chu5m1rja1((&(*dest_0).vals_0));}
SymMap_0_comaa5xpt1 eQdupQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1(SymMap_0_comaa5xpt1 src_0){
  SymMap_0_comaa5xpt1 dest_0;
  seq_0_In6doa_ast8ri79k X60Qx_2169 = eQdup_1_Idg8rf9_ast8ri79k(src_0.keys_0);
  dest_0.keys_0 = X60Qx_2169;
  seq_0_Ift2sne_chu5m1rja1 X60Qx_2170 = eQdup_1_Iplow11_chu5m1rja1(src_0.vals_0);
  dest_0.vals_0 = X60Qx_2170;
  return dest_0;}
void eQdestroyQ_SX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(Loop_Obj_0_comaa5xpt1 dest_0){
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(dest_0.continues_0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1(dest_0.breaks_0);}
void eQdestroyQ_SX46inX53cope0comaa5xpt1_0_comaa5xpt1(FinScope_0_comaa5xpt1 dest_0){
  eQdestroy_0_nifb6mq6y1((&dest_0.finCur_0));}
void eQdestroyQ_SX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(YieldFrame_Obj_0_comaa5xpt1* dest_0){
  eQdestroy_0_nifb6mq6y1((&(*dest_0).bodyCur_0));
  eQdestroy_1_Ij4pznj1_comaa5xpt1((*dest_0).unpackPlan_0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1((*dest_0).loopSlots_0);}
void eQdestroyQ_SX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(ProcCtx_Obj_0_comaa5xpt1* dest_0){
  eQdestroy_1_Ioxdx8k1_comaa5xpt1((*dest_0).yields_0);
  eQdestroy_1_Io42ulm1_comaa5xpt1((*dest_0).finallys_0);
  eQdestroy_1_Irljx3e1_comaa5xpt1((*dest_0).loops_0);
  eQdestroyQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1((*dest_0).smap_0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1((*dest_0).codeLines_0);
  eQdestroy_1_Ipa2mag1_chu5m1rja1((*dest_0).code_0);}
void eQdestroyQ_SX43ompilerX4fbj0comaa5xpt1_0_comaa5xpt1(Compiler_Obj_0_comaa5xpt1* dest_0){
  eQdestroy_1_Iv9ij5i1_chu5m1rja1((*dest_0).importGlobalInits_0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1((*dest_0).importGlobalSlots_0);
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).importGlobalSyms_0);
  eQdestroy_1_Iziv4mp_comaa5xpt1((*dest_0).ctxStack_0);
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).envSyms_0);
  eQdestroyQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1((*dest_0).nestedSyms_0);
  eQdestroy_1_Ivioh0a_ast8ri79k((*dest_0).enumNames_0);
  eQdestroy_1_Iv9ij5i1_chu5m1rja1((*dest_0).enumOrds_0);
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).enumSyms_0);
  eQdestroy_1_Id0rxta_chu5m1rja1((*dest_0).methodTable_0);
  eQdestroy_1_Ivzn3k81_chu5m1rja1((*dest_0).methodSites_0);
  eQdestroy_1_Ir7cqbo_comaa5xpt1((*dest_0).procDefCursors_0);
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).procDefSyms_0);
  eQdestroyQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1((*dest_0).pmap_0);
  eQdestroy_1_I6lze041_chu5m1rja1((*dest_0).globalSeeds_0);
  eQdestroyQ_SX53ymX4dap0comaa5xpt1_0_comaa5xpt1((*dest_0).gmap_0);
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).typeSyms_0);
  eQdestroy_1_Iymp2mv1_chu5m1rja1((*dest_0).objSpecs_0);
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).fieldSyms_0);
  eQdestroy_1_Icae6hi1_chu5m1rja1((*dest_0).objInfos_0);
  eQdestroy_1_Iwyaew9_chu5m1rja1((*dest_0).gatedCalls_0);
  eQdestroy_1_Iscb4i31_ast8ri79k((*dest_0).enumWraps_0);
  eQdestroy_1_Ivioh0a_ast8ri79k((*dest_0).natives_0);
  eQdestroy_1_Ik9jljs1_chu5m1rja1((*dest_0).convs_0);
  eQdestroy_1_Is2um9k1_chu5m1rja1((*dest_0).magics_0);
  eQdestroy_1_Inxd7ue1_chu5m1rja1((*dest_0).consts_0);
  eQdestroy_1_Iwhufig1_chu5m1rja1((*dest_0).procs_0);}
void eQdestroyQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* dest_0){
  if (dest_0){
    NB8 X60Qx_2227 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2227){
      eQdestroyQ_SX4coopX4fbj0comaa5xpt1_0_comaa5xpt1((*dest_0).d_00);
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* dest_0){
  if (dest_0){
    NB8 X60Qx_2228 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2228){
      eQdestroyQ_SX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* dest_0){
  if (dest_0){
    NB8 X60Qx_2229 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2229){
      eQdestroyQ_SX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
void eQdestroyQ_ArefSX43ompilerX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX43ompilerX4fbj0comaa5xpt1_comaa5xpt1* dest_0){
  if (dest_0){
    NB8 X60Qx_2230 = arcDec_0_sysvq0asl((&(*dest_0).r_00));
    if (X60Qx_2230){
      eQdestroyQ_SX43ompilerX4fbj0comaa5xpt1_0_comaa5xpt1((&(*dest_0).d_00));
      deallocFixed_0_sysvq0asl(dest_0);}}}
X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* eQdupQ_ArefSX50rocX43txX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* src_0){
  X60Qt_0_IArefSX50rocX43txX4fbj0comaa5xpt1_comaa5xpt1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* eQdupQ_ArefSX4coopX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* src_0){
  X60Qt_0_IArefSX4coopX4fbj0comaa5xpt1_comaa5xpt1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQdestroyQ_AtupleAboolZSstring0sysvq0asl_0_comaa5xpt1(X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1 dest_0){
  nimStrDestroy(dest_0.fld_1);}
void eQwasmovedQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1* dest_0){
  eQwasMoved_0_nifb6mq6y1((&(*dest_0).fld_1));}
void eQdestroyQ_AtupleAboolZSX43ursor0nifb6mq6y1_0_comaa5xpt1(X60Qt_0_IAtupleAboolZSX43ursor0nifb6mq6y1_comaa5xpt1 dest_0){
  eQdestroy_0_nifb6mq6y1((&dest_0.fld_1));}
X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* eQdupQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* src_0){
  X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1* dest_0;
  if (src_0){
    arcInc_0_sysvq0asl((&(*src_0).r_00));}
  dest_0 = src_0;
  return dest_0;}
void eQwasmovedQ_ArefSX59ieldX46rameX4fbj0comaa5xpt1_0_comaa5xpt1(X60Qt_0_IArefSX59ieldX46rameX4fbj0comaa5xpt1_comaa5xpt1** dest_0){
  (*dest_0) = NIM_NIL;}
void eQwasmovedQ_AtupleAboolZSstring0sysvq0asl_0_comaa5xpt1(X60Qt_0_IAtupleAboolZSstring0sysvq0asl_comaa5xpt1* dest_0){
  nimStrWasMoved((&(*dest_0).fld_1));}
void X60Qini_0_comaa5xpt1(void){
  if (X60QiniGuard_0_comaa5xpt1){
    return;}
  X60QiniGuard_0_comaa5xpt1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_modzy18mg1();
  X60Qini_0_nifb6mq6y1();
  X60Qini_0_nifh7u8pu1();
  X60Qini_0_nif81dubp1();
  X60Qini_0_nim30udrv();
  X60Qini_0_nimry5ra91();
  X60Qini_0_cal1yym9t1();
  X60Qini_0_decqocs071();
  X60Qini_0_prorcx25w1();
  X60Qini_0_symkyk35i1();
  X60Qini_0_xinat3x34();
  X60Qini_0_buiyylk1h1();
  X60Qini_0_linxafkvx1();
  X60Qini_0_valzr1t4f();
  X60Qini_0_chu5m1rja1();
  X60Qini_0_runot4689();
  X60Qini_0_siz2wt1it();
  X60Qini_0_flaksyopx1();
  X60Qini_0_fiepkwzpc();
  X60Qini_0_vtanlalcx();
  X60Qini_0_hlc70y78v();
  X60Qini_0_hlld75j0s();}
static inline NI32 len_3_I6y2imo_buiyylk1h1(seq_0_In6doa_ast8ri79k s_56){
  NI32 result_20;
  result_20 = s_56.len_0;
  return result_20;}
static inline NU32* getQ_7_I2v00yv1_buiyylk1h1(seq_0_In6doa_ast8ri79k s_58, NI32 i_28){
  NB8 X60Qx_155;
  if (i_28 < s_58.len_0){
    X60Qx_155 = (0 <= i_28);}
  else {
    X60Qx_155 = NIM_FALSE;}
  if ((!X60Qx_155)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NU32* result_21;
  result_21 = (&s_58.data_0[i_28]);
  return result_21;}
static inline NB8 eqQ_0_nifh7u8pu1(NU32 a_0, NU32 b_0){
  NB8 result_5;
  result_5 = (a_0 == b_0);
  return result_5;}
static inline void inc_1_I6wjjge_aow2h993l1(NI32* x_7){
  (*x_7) = ((NI32)((*x_7) + ((NI32)1)));}
static inline void eQwasMoved_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_1){
  (*c_1).owner_0 = NIM_NIL;
  (*c_1).p_0 = NIM_NIL;
  (*c_1).rem_0 = 0;}
static inline NifKind_0_nif81dubp1 kind_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_4){
  NifKind_0_nif81dubp1 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_22 = load_0_nifb6mq6y1(c_4);
  result_8 = ((NifKind_0_nif81dubp1)((NU32)(X60Qx_22.x_0 & ((NU32)15u))));
  return result_8;}
static inline void eQdestroy_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_0){
  if ((!((*c_0).owner_0 == NIM_NIL))){
    dec_1_I0nzoz91_ast8ri79k((&(*(*c_0).owner_0).rc_0));
    if ((*(*c_0).owner_0).rc_0 == 0){
      if ((!((*(*c_0).owner_0).data_0 == NIM_NIL))){
        dealloc_1_sysvq0asl(((void*)((void*)(*(*c_0).owner_0).data_0)));}
      dealloc_1_sysvq0asl(((void*)((void*)(*c_0).owner_0)));}}}
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
static inline NU32 tagId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_13){
  NU32 result_16;
  PackedToken_0_nifh7u8pu1 X60Qx_36 = load_0_nifb6mq6y1(c_13);
  NU32 X60Qx_37 = tagId_0_nifh7u8pu1(X60Qx_36);
  result_16 = X60Qx_37;
  return result_16;}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_42){
  string_0_sysvq0asl result_104;
  NI32 X60Qx_224 = ssLenOf_0_sysvq0asl(s_42.bytes_0);
  if (X60Qx_224 == ((NI32)255)){
    arcInc_0_sysvq0asl((&(*s_42.more_0).rc_0));}
  result_104 = (string_0_sysvq0asl){
    .bytes_0 = s_42.bytes_0, .more_0 = s_42.more_0}
  ;
  return result_104;}
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_40){
  (*s_40).bytes_0 = ((NU32)0);}
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
static inline NU32 info_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_5){
  NU32 result_9;
  PackedToken_0_nifh7u8pu1 X60Qx_23 = load_0_nifb6mq6y1(c_5);
  result_9 = X60Qx_23.info_0;
  return result_9;}
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
static inline void add_0_Ig6072n_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k* s_20, string_0_sysvq0asl elem_3){
  NI32 L_0 = (*s_20).len_0;
  NI32 X60Qx_66 = capInBytes_0_Ih2sbn01_ast8ri79k((*s_20));
  if (X60Qx_66 < ((NI32)(((NI32)(L_0 * sizeof(string_0_sysvq0asl))) + sizeof(string_0_sysvq0asl)))){
    NB8 X60Qx_67 = resize_0_I4buliy_ast8ri79k(s_20, 1);
    if ((!X60Qx_67)){
      nimStrDestroy(elem_3);
      return;}}
  inc_1_I6wjjge_aow2h993l1((&(*s_20).len_0));
  (*s_20).data_0[L_0] = elem_3;}
static inline NI32 len_4_sysvq0asl(string_0_sysvq0asl s_34){
  NI32 result_98;
  result_98 = ((NI32)(*((NU8*)(&s_34.bytes_0))));
  if (((NI32)6) < result_98){
    result_98 = (*s_34.more_0).fullLen_0;}
  return result_98;}
static inline Cursor_0_nifb6mq6y1 eQdup_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 src_1){
  Cursor_0_nifb6mq6y1 result_4;
  result_4 = (Cursor_0_nifb6mq6y1){
    .owner_0 = src_1.owner_0, .p_0 = src_1.p_0, .rem_0 = src_1.rem_0}
  ;
  if ((!(result_4.owner_0 == NIM_NIL))){
    inc_1_I6wjjge_aow2h993l1((&(*result_4.owner_0).rc_0));}
  return result_4;}
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
static inline NU32 symId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_8){
  NU32 result_11;
  PackedToken_0_nifh7u8pu1 X60Qx_26 = load_0_nifb6mq6y1(c_8);
  NU32 X60Qx_27 = symId_0_nifh7u8pu1(X60Qx_26);
  result_11 = X60Qx_27;
  return result_11;}
static inline void dec_1_I0nzoz91_ast8ri79k(NI32* x_3){
  (*x_3) = ((NI32)((*x_3) - ((NI32)1)));}
static inline NU32 litId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_7){
  NU32 result_10;
  PackedToken_0_nifh7u8pu1 X60Qx_24 = load_0_nifb6mq6y1(c_7);
  NU32 X60Qx_25 = litId_0_nifh7u8pu1(X60Qx_24);
  result_10 = X60Qx_25;
  return result_10;}
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
static inline NimonySym_0_nimry5ra91 symKind_0_nim30udrv(Cursor_0_nifb6mq6y1 c_11){
  NimonySym_0_nimry5ra91 result_9;
  NifKind_0_nif81dubp1 X60Qx_48 = kind_0_nifb6mq6y1(c_11);
  if (X60Qx_48 == 11){
    NU32 X60Qx_49 = tag_0_nifb6mq6y1(c_11);
    NB8 X60Qx_50 = rawTagIsNimonySym_0_nimry5ra91(((TagEnum_0_tagygirdh1)X60Qx_49));
    if (X60Qx_50){
      NU32 X60Qx_51 = tag_0_nifb6mq6y1(c_11);
      result_9 = ((NimonySym_0_nimry5ra91)((TagEnum_0_tagygirdh1)X60Qx_51));}
    else {
      result_9 = 0;}}
  else {
    result_9 = 0;}
  return result_9;}
static inline NB8 isRoutine_0_decqocs071(NimonySym_0_nimry5ra91 t_0){
  NB8 result_0;
  X60Qt_0_IAarrayAuS8ZS11_decqocs071 X60Qdesugar_0 = (X60Qt_0_IAarrayAuS8ZS11_decqocs071){
    .a = {
      0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 192u, 31u, 0u}}
  ;
  NU64 X60Qdesugar_1 = ((NU)t_0);
  result_0 = (((NU8)(X60Qdesugar_0.a[((NU)(X60Qdesugar_1 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_1 & 7u)))))) != 0u);
  return result_0;}
static inline void consumeParRi_0_nifb6mq6y1(Cursor_0_nifb6mq6y1* c_19){
  NifKind_0_nif81dubp1 X60Qx_44 = kind_0_nifb6mq6y1((*c_19));
  if ((!(X60Qx_44 == 12))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1933663230u, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 1852793854u, .more_0 = (&strlit_0_I17128882682348225350_nifb6mq6y1)}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(1);}
  inc_0_nifb6mq6y1(c_19);}
static inline seq_0_Izok7jt1_chu5m1rja1 newSeqUninit_0_I82j90d_chu5m1rja1(NI32 size_30){
  seq_0_Izok7jt1_chu5m1rja1 result_18;
  if (size_30 == 0){
    result_18 = (seq_0_Izok7jt1_chu5m1rja1){
      .len_0 = size_30, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_15 = memSizeInBytes_0_I58le2f1_chu5m1rja1(size_30);
    void* X60Qx_85 = alloc_1_sysvq0asl(memSize_15);
    result_18 = (seq_0_Izok7jt1_chu5m1rja1){
      .len_0 = size_30, .data_0 = ((Instr_0_chu5m1rja1*)X60Qx_85)}
    ;
    if ((!(result_18.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_86 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_18.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_15);}}
  return result_18;}
static inline seq_0_Ift2sne_chu5m1rja1 newSeqUninit_0_Iggfvwp_chu5m1rja1(NI32 size_32){
  seq_0_Ift2sne_chu5m1rja1 result_21;
  if (size_32 == 0){
    result_21 = (seq_0_Ift2sne_chu5m1rja1){
      .len_0 = size_32, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_16 = memSizeInBytes_0_Inv7kg3_chu5m1rja1(size_32);
    void* X60Qx_88 = alloc_1_sysvq0asl(memSize_16);
    result_21 = (seq_0_Ift2sne_chu5m1rja1){
      .len_0 = size_32, .data_0 = ((NI32*)X60Qx_88)}
    ;
    if ((!(result_21.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_89 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_21.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_16);}}
  return result_21;}
static inline seq_0_In6doa_ast8ri79k newSeqUninit_0_Ieodq4s1_ast8ri79k(NI32 size_32){
  seq_0_In6doa_ast8ri79k result_50;
  if (size_32 == 0){
    result_50 = (seq_0_In6doa_ast8ri79k){
      .len_0 = size_32, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_18 = memSizeInBytes_0_Ivqzo5x1_ast8ri79k(size_32);
    void* X60Qx_132 = alloc_1_sysvq0asl(memSize_18);
    result_50 = (seq_0_In6doa_ast8ri79k){
      .len_0 = size_32, .data_0 = ((NU32*)X60Qx_132)}
    ;
    if ((!(result_50.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_133 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_50.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_18);}}
  return result_50;}
static inline NU32 uintId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_11){
  NU32 result_14;
  PackedToken_0_nifh7u8pu1 X60Qx_32 = load_0_nifb6mq6y1(c_11);
  NU32 X60Qx_33 = uintId_0_nifh7u8pu1(X60Qx_32);
  result_14 = X60Qx_33;
  return result_14;}
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
static inline NU32 floatId_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_12){
  NU32 result_15;
  PackedToken_0_nifh7u8pu1 X60Qx_34 = load_0_nifb6mq6y1(c_12);
  NU32 X60Qx_35 = floatId_0_nifh7u8pu1(X60Qx_34);
  result_15 = X60Qx_35;
  return result_15;}
static inline NF64 getQ_1_I4qx0py_ast8ri79k(BiTable_0_Iojfwmy1_ast8ri79k t_9, NU32 litId_8){
  NF64 result_6;
  NU64* X60Qx_34 = getQ_0_I3qz68f_ast8ri79k(t_9, litId_8);
  NU64 X60Qx_35 = (*X60Qx_34);
  NF64 X60Qx_36;
  copyMem_0_sysvq0asl((&X60Qx_36), (&X60Qx_35), sizeof(NF64));
  result_6 = X60Qx_36;
  return result_6;}
static inline NC8 charLit_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_9){
  NC8 result_12;
  PackedToken_0_nifh7u8pu1 X60Qx_28 = load_0_nifb6mq6y1(c_9);
  NC8 X60Qx_29 = charLit_0_nifh7u8pu1(X60Qx_28);
  result_12 = X60Qx_29;
  return result_12;}
static inline NimonyExpr_0_nimry5ra91 exprKind_1_nim30udrv(Cursor_0_nifb6mq6y1 c_10){
  NimonyExpr_0_nimry5ra91 result_8;
  PackedToken_0_nifh7u8pu1 X60Qx_46 = load_0_nifb6mq6y1(c_10);
  NimonyExpr_0_nimry5ra91 X60Qx_47 = exprKind_0_nim30udrv(X60Qx_46);
  result_8 = X60Qx_47;
  return result_8;}
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
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI32 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
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
static inline void eQwasMoved_1_Ix88qzs1_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1* s_35){
  (*s_35).len_0 = 0;
  (*s_35).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_I2k4kel_ast8ri79k(seq_0_In6doa_ast8ri79k* s_66){
  (*s_66).len_0 = 0;
  (*s_66).data_0 = NIM_NIL;}
static inline seq_0_Inaua171_chu5m1rja1 newSeqUninit_0_Isa1q0a_chu5m1rja1(NI32 size_34){
  seq_0_Inaua171_chu5m1rja1 result_24;
  if (size_34 == 0){
    result_24 = (seq_0_Inaua171_chu5m1rja1){
      .len_0 = size_34, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_17 = memSizeInBytes_0_Iq7wi6a_chu5m1rja1(size_34);
    void* X60Qx_91 = alloc_1_sysvq0asl(memSize_17);
    result_24 = (seq_0_Inaua171_chu5m1rja1){
      .len_0 = size_34, .data_0 = ((Proc_0_chu5m1rja1*)X60Qx_91)}
    ;
    if ((!(result_24.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_92 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_24.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_17);}}
  return result_24;}
static inline seq_0_I50urnw_chu5m1rja1 newSeqUninit_0_I8oufjc_chu5m1rja1(NI32 size_36){
  seq_0_I50urnw_chu5m1rja1 result_27;
  if (size_36 == 0){
    result_27 = (seq_0_I50urnw_chu5m1rja1){
      .len_0 = size_36, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_18 = memSizeInBytes_0_Itmy7ww1_chu5m1rja1(size_36);
    void* X60Qx_94 = alloc_1_sysvq0asl(memSize_18);
    result_27 = (seq_0_I50urnw_chu5m1rja1){
      .len_0 = size_36, .data_0 = ((Value_0_valzr1t4f*)X60Qx_94)}
    ;
    if ((!(result_27.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_95 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_27.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_18);}}
  return result_27;}
static inline seq_0_Ie9rikd_chu5m1rja1 newSeqUninit_0_Iqh1pff1_chu5m1rja1(NI32 size_38){
  seq_0_Ie9rikd_chu5m1rja1 result_30;
  if (size_38 == 0){
    result_30 = (seq_0_Ie9rikd_chu5m1rja1){
      .len_0 = size_38, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_19 = memSizeInBytes_0_Ikrq3db1_chu5m1rja1(size_38);
    void* X60Qx_97 = alloc_1_sysvq0asl(memSize_19);
    result_30 = (seq_0_Ie9rikd_chu5m1rja1){
      .len_0 = size_38, .data_0 = ((MagicSpec_0_chu5m1rja1*)X60Qx_97)}
    ;
    if ((!(result_30.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_98 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_30.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_19);}}
  return result_30;}
static inline seq_0_Iknt7a3_chu5m1rja1 newSeqUninit_0_I16oi801_chu5m1rja1(NI32 size_40){
  seq_0_Iknt7a3_chu5m1rja1 result_33;
  if (size_40 == 0){
    result_33 = (seq_0_Iknt7a3_chu5m1rja1){
      .len_0 = size_40, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_20 = memSizeInBytes_0_I3p8ndy_chu5m1rja1(size_40);
    void* X60Qx_100 = alloc_1_sysvq0asl(memSize_20);
    result_33 = (seq_0_Iknt7a3_chu5m1rja1){
      .len_0 = size_40, .data_0 = ((ConvSpec_0_chu5m1rja1*)X60Qx_100)}
    ;
    if ((!(result_33.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_101 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_33.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_20);}}
  return result_33;}
static inline seq_0_Ixdx2fh1_ast8ri79k newSeqUninit_0_Im3cqd9_ast8ri79k(NI32 size_20){
  seq_0_Ixdx2fh1_ast8ri79k result_33;
  if (size_20 == 0){
    result_33 = (seq_0_Ixdx2fh1_ast8ri79k){
      .len_0 = size_20, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_11 = memSizeInBytes_0_I7me00i_ast8ri79k(size_20);
    void* X60Qx_113 = alloc_1_sysvq0asl(memSize_11);
    result_33 = (seq_0_Ixdx2fh1_ast8ri79k){
      .len_0 = size_20, .data_0 = ((string_0_sysvq0asl*)X60Qx_113)}
    ;
    if ((!(result_33.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_114 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_33.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_11);}}
  return result_33;}
static inline seq_0_Id5h4uf_chu5m1rja1 newSeqUninit_0_Ii76u2d1_chu5m1rja1(NI32 size_44){
  seq_0_Id5h4uf_chu5m1rja1 result_39;
  if (size_44 == 0){
    result_39 = (seq_0_Id5h4uf_chu5m1rja1){
      .len_0 = size_44, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_22 = memSizeInBytes_0_Ifccb5x1_chu5m1rja1(size_44);
    void* X60Qx_106 = alloc_1_sysvq0asl(memSize_22);
    result_39 = (seq_0_Id5h4uf_chu5m1rja1){
      .len_0 = size_44, .data_0 = ((GatedCall_0_chu5m1rja1*)X60Qx_106)}
    ;
    if ((!(result_39.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_107 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_39.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_22);}}
  return result_39;}
static inline seq_0_I2neof81_chu5m1rja1 newSeqUninit_0_In1bf9z_chu5m1rja1(NI32 size_46){
  seq_0_I2neof81_chu5m1rja1 result_42;
  if (size_46 == 0){
    result_42 = (seq_0_I2neof81_chu5m1rja1){
      .len_0 = size_46, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_23 = memSizeInBytes_0_I6hayax_chu5m1rja1(size_46);
    void* X60Qx_109 = alloc_1_sysvq0asl(memSize_23);
    result_42 = (seq_0_I2neof81_chu5m1rja1){
      .len_0 = size_46, .data_0 = ((ObjInfo_0_chu5m1rja1*)X60Qx_109)}
    ;
    if ((!(result_42.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_110 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_42.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_23);}}
  return result_42;}
static inline seq_0_Isww99s_chu5m1rja1 newSeqUninit_0_Iuxy4sp1_chu5m1rja1(NI32 size_48){
  seq_0_Isww99s_chu5m1rja1 result_45;
  if (size_48 == 0){
    result_45 = (seq_0_Isww99s_chu5m1rja1){
      .len_0 = size_48, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_24 = memSizeInBytes_0_Ie1nwe7_chu5m1rja1(size_48);
    void* X60Qx_112 = alloc_1_sysvq0asl(memSize_24);
    result_45 = (seq_0_Isww99s_chu5m1rja1){
      .len_0 = size_48, .data_0 = ((ObjSpec_0_chu5m1rja1*)X60Qx_112)}
    ;
    if ((!(result_45.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_113 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_45.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_24);}}
  return result_45;}
static inline seq_0_Iioxqbu_chu5m1rja1 newSeqUninit_0_Iqy0tna1_chu5m1rja1(NI32 size_54){
  seq_0_Iioxqbu_chu5m1rja1 result_54;
  if (size_54 == 0){
    result_54 = (seq_0_Iioxqbu_chu5m1rja1){
      .len_0 = size_54, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_27 = memSizeInBytes_0_Iywqtuz_chu5m1rja1(size_54);
    void* X60Qx_121 = alloc_1_sysvq0asl(memSize_27);
    result_54 = (seq_0_Iioxqbu_chu5m1rja1){
      .len_0 = size_54, .data_0 = ((GlobalSeed_0_chu5m1rja1*)X60Qx_121)}
    ;
    if ((!(result_54.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_122 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_54.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_27);}}
  return result_54;}
static inline seq_0_Ir067xu1_chu5m1rja1 newSeqUninit_0_Im7kjnr_chu5m1rja1(NI32 size_50){
  seq_0_Ir067xu1_chu5m1rja1 result_48;
  if (size_50 == 0){
    result_48 = (seq_0_Ir067xu1_chu5m1rja1){
      .len_0 = size_50, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_25 = memSizeInBytes_0_Iqssf4e1_chu5m1rja1(size_50);
    void* X60Qx_115 = alloc_1_sysvq0asl(memSize_25);
    result_48 = (seq_0_Ir067xu1_chu5m1rja1){
      .len_0 = size_50, .data_0 = ((MethodSite_0_chu5m1rja1*)X60Qx_115)}
    ;
    if ((!(result_48.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_116 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_48.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_25);}}
  return result_48;}
static inline seq_0_I88k8j01_chu5m1rja1 newSeqUninit_0_I0s7mv21_chu5m1rja1(NI32 size_52){
  seq_0_I88k8j01_chu5m1rja1 result_51;
  if (size_52 == 0){
    result_51 = (seq_0_I88k8j01_chu5m1rja1){
      .len_0 = size_52, .data_0 = NIM_NIL}
    ;}
  else {
    NI32 memSize_26 = memSizeInBytes_0_Ij5c7dh1_chu5m1rja1(size_52);
    void* X60Qx_118 = alloc_1_sysvq0asl(memSize_26);
    result_51 = (seq_0_I88k8j01_chu5m1rja1){
      .len_0 = size_52, .data_0 = ((MethodEntry_0_chu5m1rja1*)X60Qx_118)}
    ;
    if ((!(result_51.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_119 = (string_0_sysvq0asl){
        .bytes_0 = 1634036990u, .more_0 = (&strlit_0_I15750996627617194403_ast8ri79k)}
      ;}
    else {
      result_51.len_0 = 0;
      oomHandler_0_sysvq0asl(memSize_26);}}
  return result_51;}
static inline void eQwasMoved_1_Iwfxwnm_chu5m1rja1(seq_0_Inaua171_chu5m1rja1* s_38){
  (*s_38).len_0 = 0;
  (*s_38).data_0 = NIM_NIL;}
static inline NI32 capInBytes_0_Iev6wua1_ast8ri79k(seq_0_In6doa_ast8ri79k s_73){
  NI32 result_51;
  NI32 X60Qx_7;
  if ((!(s_73.data_0 == NIM_NIL))){
    NI32 X60Qx_134 = allocatedSize_0_sysvq0asl(((void*)((void*)s_73.data_0)));
    X60Qx_7 = X60Qx_134;}
  else {
    X60Qx_7 = 0;}
  result_51 = X60Qx_7;
  return result_51;}
static inline NI32 capInBytes_0_Iet286n_chu5m1rja1(seq_0_Ift2sne_chu5m1rja1 s_72){
  NI32 result_22;
  NI32 X60Qx_2;
  if ((!(s_72.data_0 == NIM_NIL))){
    NI32 X60Qx_90 = allocatedSize_0_sysvq0asl(((void*)((void*)s_72.data_0)));
    X60Qx_2 = X60Qx_90;}
  else {
    X60Qx_2 = 0;}
  result_22 = X60Qx_2;
  return result_22;}
static inline NI32 capInBytes_0_Io1cymi_chu5m1rja1(seq_0_Izok7jt1_chu5m1rja1 s_71){
  NI32 result_19;
  NI32 X60Qx_1;
  if ((!(s_71.data_0 == NIM_NIL))){
    NI32 X60Qx_87 = allocatedSize_0_sysvq0asl(((void*)((void*)s_71.data_0)));
    X60Qx_1 = X60Qx_87;}
  else {
    X60Qx_1 = 0;}
  result_19 = X60Qx_1;
  return result_19;}
static inline NI32 capInBytes_0_Ihvsegh1_chu5m1rja1(seq_0_I50urnw_chu5m1rja1 s_74){
  NI32 result_28;
  NI32 X60Qx_4;
  if ((!(s_74.data_0 == NIM_NIL))){
    NI32 X60Qx_96 = allocatedSize_0_sysvq0asl(((void*)((void*)s_74.data_0)));
    X60Qx_4 = X60Qx_96;}
  else {
    X60Qx_4 = 0;}
  result_28 = X60Qx_4;
  return result_28;}
static inline NI32 capInBytes_0_I02yj151_chu5m1rja1(seq_0_Ie9rikd_chu5m1rja1 s_75){
  NI32 result_31;
  NI32 X60Qx_5;
  if ((!(s_75.data_0 == NIM_NIL))){
    NI32 X60Qx_99 = allocatedSize_0_sysvq0asl(((void*)((void*)s_75.data_0)));
    X60Qx_5 = X60Qx_99;}
  else {
    X60Qx_5 = 0;}
  result_31 = X60Qx_5;
  return result_31;}
static inline NI32 capInBytes_0_Iccedzq_chu5m1rja1(seq_0_Iknt7a3_chu5m1rja1 s_76){
  NI32 result_34;
  NI32 X60Qx_6;
  if ((!(s_76.data_0 == NIM_NIL))){
    NI32 X60Qx_102 = allocatedSize_0_sysvq0asl(((void*)((void*)s_76.data_0)));
    X60Qx_6 = X60Qx_102;}
  else {
    X60Qx_6 = 0;}
  result_34 = X60Qx_6;
  return result_34;}
static inline NI32 capInBytes_0_Ihi6tep_chu5m1rja1(seq_0_Id5h4uf_chu5m1rja1 s_78){
  NI32 result_40;
  NI32 X60Qx_8;
  if ((!(s_78.data_0 == NIM_NIL))){
    NI32 X60Qx_108 = allocatedSize_0_sysvq0asl(((void*)((void*)s_78.data_0)));
    X60Qx_8 = X60Qx_108;}
  else {
    X60Qx_8 = 0;}
  result_40 = X60Qx_8;
  return result_40;}
static inline NI32 capInBytes_0_I27hxyl_chu5m1rja1(seq_0_I2neof81_chu5m1rja1 s_79){
  NI32 result_43;
  NI32 X60Qx_9;
  if ((!(s_79.data_0 == NIM_NIL))){
    NI32 X60Qx_111 = allocatedSize_0_sysvq0asl(((void*)((void*)s_79.data_0)));
    X60Qx_9 = X60Qx_111;}
  else {
    X60Qx_9 = 0;}
  result_43 = X60Qx_9;
  return result_43;}
static inline NI32 capInBytes_0_Ifvg4nq1_chu5m1rja1(seq_0_Inaua171_chu5m1rja1 s_73){
  NI32 result_25;
  NI32 X60Qx_3;
  if ((!(s_73.data_0 == NIM_NIL))){
    NI32 X60Qx_93 = allocatedSize_0_sysvq0asl(((void*)((void*)s_73.data_0)));
    X60Qx_3 = X60Qx_93;}
  else {
    X60Qx_3 = 0;}
  result_25 = X60Qx_3;
  return result_25;}
static inline NI32 capInBytes_0_I38sirs1_chu5m1rja1(seq_0_Iioxqbu_chu5m1rja1 s_83){
  NI32 result_55;
  NI32 X60Qx_13;
  if ((!(s_83.data_0 == NIM_NIL))){
    NI32 X60Qx_123 = allocatedSize_0_sysvq0asl(((void*)((void*)s_83.data_0)));
    X60Qx_13 = X60Qx_123;}
  else {
    X60Qx_13 = 0;}
  result_55 = X60Qx_13;
  return result_55;}
static inline NI32 capInBytes_0_Ivj8jl41_chu5m1rja1(seq_0_Ir067xu1_chu5m1rja1 s_81){
  NI32 result_49;
  NI32 X60Qx_11;
  if ((!(s_81.data_0 == NIM_NIL))){
    NI32 X60Qx_117 = allocatedSize_0_sysvq0asl(((void*)((void*)s_81.data_0)));
    X60Qx_11 = X60Qx_117;}
  else {
    X60Qx_11 = 0;}
  result_49 = X60Qx_11;
  return result_49;}
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
static inline NI32 capInBytes_0_I6qhu63_chu5m1rja1(seq_0_I88k8j01_chu5m1rja1 s_82){
  NI32 result_52;
  NI32 X60Qx_12;
  if ((!(s_82.data_0 == NIM_NIL))){
    NI32 X60Qx_120 = allocatedSize_0_sysvq0asl(((void*)((void*)s_82.data_0)));
    X60Qx_12 = X60Qx_120;}
  else {
    X60Qx_12 = 0;}
  result_52 = X60Qx_12;
  return result_52;}
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
static inline NI32 memSizeInBytes_0_Inv7kg3_chu5m1rja1(NI32 size_33){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_23;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_33, sizeof(NI32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_23 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_23 = ((NI32)2147483647);}
  return result_23;}
static inline NI32 memSizeInBytes_0_I58le2f1_chu5m1rja1(NI32 size_31){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_20;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_31, sizeof(Instr_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_20 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_20 = ((NI32)2147483647);}
  return result_20;}
static inline NI32 memSizeInBytes_0_Itmy7ww1_chu5m1rja1(NI32 size_37){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_29;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_37, sizeof(Value_0_valzr1t4f), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_29 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_29 = ((NI32)2147483647);}
  return result_29;}
static inline NI32 memSizeInBytes_0_Ikrq3db1_chu5m1rja1(NI32 size_39){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_32;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_39, sizeof(MagicSpec_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_32 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_32 = ((NI32)2147483647);}
  return result_32;}
static inline NI32 memSizeInBytes_0_I3p8ndy_chu5m1rja1(NI32 size_41){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_35;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_41, sizeof(ConvSpec_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_35 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_35 = ((NI32)2147483647);}
  return result_35;}
static inline NI32 memSizeInBytes_0_Ifccb5x1_chu5m1rja1(NI32 size_45){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_41;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_45, sizeof(GatedCall_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_41 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_41 = ((NI32)2147483647);}
  return result_41;}
static inline NI32 memSizeInBytes_0_I6hayax_chu5m1rja1(NI32 size_47){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_44;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_47, sizeof(ObjInfo_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_44 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_44 = ((NI32)2147483647);}
  return result_44;}
static inline NI32 memSizeInBytes_0_Iq7wi6a_chu5m1rja1(NI32 size_35){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_26;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_35, sizeof(Proc_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_26 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_26 = ((NI32)2147483647);}
  return result_26;}
static inline NI32 memSizeInBytes_0_Iywqtuz_chu5m1rja1(NI32 size_55){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_56;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_55, sizeof(GlobalSeed_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_56 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_56 = ((NI32)2147483647);}
  return result_56;}
static inline NI32 memSizeInBytes_0_Iqssf4e1_chu5m1rja1(NI32 size_51){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_50;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_51, sizeof(MethodSite_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_50 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_50 = ((NI32)2147483647);}
  return result_50;}
static inline NI32 max_2_sysvq0asl(NI32 x_211, NI32 y_168){
  NI32 result_12;
  NI32 X60Qx_8;
  if (y_168 <= x_211){
    X60Qx_8 = x_211;}
  else {
    X60Qx_8 = y_168;}
  result_12 = X60Qx_8;
  return result_12;}
static inline NI32 min_2_sysvq0asl(NI32 x_204, NI32 y_161){
  NI32 result_5;
  NI32 X60Qx_2;
  if (x_204 <= y_161){
    X60Qx_2 = x_204;}
  else {
    X60Qx_2 = y_161;}
  result_5 = X60Qx_2;
  return result_5;}
static inline NI32 memSizeInBytes_0_Ij5c7dh1_chu5m1rja1(NI32 size_53){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_53;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_53, sizeof(MethodEntry_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_53 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_53 = ((NI32)2147483647);}
  return result_53;}
static inline NB8 arcDec_0_sysvq0asl(NI32* memLoc_1){
  NB8 result_156;
  NI32 X60Qx_319 = __atomic_sub_fetch((&(*memLoc_1)), 1, __ATOMIC_SEQ_CST);
  result_156 = (X60Qx_319 < 0);
  return result_156;}
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
static inline NI32 ssLenOf_0_sysvq0asl(NU32 bytes_2){
  NI32 result_95;
  result_95 = ((NI32)((NU32)(bytes_2 & 255u)));
  return result_95;}
static inline NI32 capInBytes_0_Ih2sbn01_ast8ri79k(seq_0_Ixdx2fh1_ast8ri79k s_28){
  NI32 result_18;
  NI32 X60Qx_0;
  if ((!(s_28.data_0 == NIM_NIL))){
    NI32 X60Qx_72 = allocatedSize_0_sysvq0asl(((void*)((void*)s_28.data_0)));
    X60Qx_0 = X60Qx_72;}
  else {
    X60Qx_0 = 0;}
  result_18 = X60Qx_0;
  return result_18;}
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
static inline NU32 tag_0_nifb6mq6y1(Cursor_0_nifb6mq6y1 c_14){
  NU32 result_17;
  PackedToken_0_nifh7u8pu1 X60Qx_38 = load_0_nifb6mq6y1(c_14);
  NU32 X60Qx_39 = tag_0_nifh7u8pu1(X60Qx_38);
  result_17 = X60Qx_39;
  return result_17;}
static inline NB8 rawTagIsNimonySym_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_5){
  NB8 result_11;
  NB8 X60Qx_0;
  if (54 <= raw_5){
    X60Qx_0 = (raw_5 <= 80);}
  else {
    X60Qx_0 = NIM_FALSE;}
  result_11 = X60Qx_0;
  return result_11;}
static inline NI32 memSizeInBytes_0_Ivqzo5x1_ast8ri79k(NI32 size_33){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_52;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_33, sizeof(NU32), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_52 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_52 = ((NI32)2147483647);}
  return result_52;}
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
static inline NU64* getQ_7_Ifaxado1_ast8ri79k(seq_0_Ijmiee61_ast8ri79k s_10, NI32 i_7){
  NB8 X60Qx_54;
  if (i_7 < s_10.len_0){
    X60Qx_54 = (0 <= i_7);}
  else {
    X60Qx_54 = NIM_FALSE;}
  if ((!X60Qx_54)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 791555838u, .more_0 = (&strlit_0_I5736347696189397304_ast8ri79k)}
    );}
  NU64* result_11;
  result_11 = (&s_10.data_0[i_7]);
  return result_11;}
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
static inline NimonyExpr_0_nimry5ra91 exprKind_0_nim30udrv(PackedToken_0_nifh7u8pu1 c_9){
  NimonyExpr_0_nimry5ra91 result_7;
  if (((NifKind_0_nif81dubp1)((NU32)(c_9.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_43 = tag_0_nifh7u8pu1(c_9);
    NB8 X60Qx_44 = rawTagIsNimonyExpr_0_nimry5ra91(((TagEnum_0_tagygirdh1)X60Qx_43));
    if (X60Qx_44){
      NU32 X60Qx_45 = tag_0_nifh7u8pu1(c_9);
      result_7 = ((NimonyExpr_0_nimry5ra91)((TagEnum_0_tagygirdh1)X60Qx_45));}
    else {
      result_7 = 0;}}
  else {
    result_7 = 0;}
  return result_7;}
static inline NI32 memSizeInBytes_0_I7me00i_ast8ri79k(NI32 size_4){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_23;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_4, sizeof(string_0_sysvq0asl), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_23 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_23 = ((NI32)2147483647);}
  return result_23;}
static inline NI32 memSizeInBytes_0_Ie1nwe7_chu5m1rja1(NI32 size_49){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI32 result_47;
  NI32 X60QconstRefTemp_0;
  if (__builtin_smul_overflow(size_49, sizeof(ObjSpec_0_chu5m1rja1), &X60QconstRefTemp_0)){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_47 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_47 = ((NI32)2147483647);}
  return result_47;}
static inline NU32 tag_0_nifh7u8pu1(PackedToken_0_nifh7u8pu1 n_16){
  NU32 result_43;
  if (((NifKind_0_nif81dubp1)((NU32)(n_16.x_0 & ((NU32)15u)))) == 11){
    NU32 X60Qx_88 = tagId_0_nifh7u8pu1(n_16);
    result_43 = X60Qx_88;}
  else {
    result_43 = ErrT_0_nifh7u8pu1;}
  return result_43;}
static inline NB8 rawTagIsNimonyExpr_0_nimry5ra91(TagEnum_0_tagygirdh1 raw_0){
  NB8 result_1;
  X60Qt_0_IAarrayAuS8ZS43_ast8ri79k X60Qdesugar_0 = (X60Qt_0_IAarrayAuS8ZS43_ast8ri79k){
    .a = {
      254u, 243u, 255u, 127u, 255u, 255u, 15u, 0u, 0u, 0u, 3u, 0u, 0u, 0u, 0u, 0u, 0u, 32u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 248u, 255u, 255u, 255u, 255u, 255u, 255u, 127u, 0u, 0u, 128u, 15u, 0u, 32u}}
  ;
  NU64 X60Qdesugar_1 = ((NU)raw_0);
  result_1 = (((NU8)(X60Qdesugar_0.a[((NU)(X60Qdesugar_1 >> 3u))] & ((NU8)(1u << ((NU)(X60Qdesugar_1 & 7u)))))) != 0u);
  return result_1;}
